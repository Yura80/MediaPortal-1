/*
	MediaPortal TS-SourceFilter by Agree
	Some parts taken from OpenSource TSSourceFilter.ax by nate,bear and bisswanger
	
*/


#include <streams.h>
#include "MPTSFilter.h"
//#include "Mmsystem.h"
class CFilterOutPin;
extern void LogDebug(const char *fmt, ...) ;

CFilterOutPin::CFilterOutPin(LPUNKNOWN pUnk, CMPTSFilter *pFilter, FileReader *pFileReader, Sections *pSections, HRESULT *phr) :
	CSourceStream(NAME("PinObject"), phr, pFilter, L"Out"),
	CTimeShiftSeeking(NAME("MediaSeekingObject"), pUnk, phr, &m_cSharedState),
	m_pMPTSFilter(pFilter),
	m_pFileReader(pFileReader),
	m_pSections(pSections),m_bDiscontinuity(FALSE), m_bFlushing(FALSE)
{
	CAutoLock cAutoLock(&m_cSharedState);
	m_dwSeekingCaps =	
						AM_SEEKING_CanSeekForwards  | AM_SEEKING_CanSeekBackwards |
						AM_SEEKING_CanGetStopPos    | AM_SEEKING_CanGetDuration   |
						AM_SEEKING_CanSeekAbsolute;

	__int64 size;
	m_pFileReader->GetFileSize(&size);
	m_rtDuration = m_rtStop = m_pSections->pids.Duration;
	m_lTSPacketDeliverySize = 188*100;
	m_pBuffers = new CBuffers(m_pFileReader, &m_pSections->pids,m_lTSPacketDeliverySize);
	m_dTimeInc=0;
	m_lastPTS=0;	
	m_dRateSeeking = 1.0;
	
}

CFilterOutPin::~CFilterOutPin()
{
	CAutoLock cAutoLock(&m_cSharedState);
	m_pBuffers->Clear();
	delete m_pBuffers;
}
STDMETHODIMP CFilterOutPin::NonDelegatingQueryInterface( REFIID riid, void ** ppv )
{
    if (riid == IID_IMediaSeeking)
    {
        return CTimeShiftSeeking::NonDelegatingQueryInterface( riid, ppv );
    }
    return CSourceStream::NonDelegatingQueryInterface(riid, ppv);
}

HRESULT CFilterOutPin::GetMediaType(CMediaType *pmt)
{
	CAutoLock cAutoLock(m_pFilter->pStateLock());

    CheckPointer(pmt, E_POINTER);

	pmt->InitMediaType();
	pmt->SetType      (& MEDIATYPE_Stream);
	pmt->SetSubtype   (& MEDIASUBTYPE_MPEG2_TRANSPORT);

    return S_OK;
}

HRESULT CFilterOutPin::DecideBufferSize(IMemAllocator *pAlloc, ALLOCATOR_PROPERTIES *pRequest)
{
    HRESULT hr;

	CAutoLock cAutoLock(m_pFilter->pStateLock());

    CheckPointer(pAlloc, E_POINTER);
    CheckPointer(pRequest, E_POINTER);

    if (pRequest->cBuffers == 0)
    {
        pRequest->cBuffers = 2;
    }

	pRequest->cbBuffer = m_lTSPacketDeliverySize;
	

    ALLOCATOR_PROPERTIES Actual;
    hr = pAlloc->SetProperties(pRequest, &Actual);
    if (FAILED(hr))
    {
        return hr;
    }

    if (Actual.cbBuffer < pRequest->cbBuffer)
    {
        return E_FAIL;
    }

    return S_OK;
}

HRESULT CFilterOutPin::CompleteConnect(IPin *pReceivePin)
{
	HRESULT hr = CBaseOutputPin::CompleteConnect(pReceivePin);
	if (SUCCEEDED(hr))
	{
		m_pMPTSFilter->OnConnect();
		ULONGLONG startPts=0, endPts=0;
		UpdatePositions(startPts,endPts);
	}
	return S_OK;
}
STDMETHODIMP CFilterOutPin::SetPositions(LONGLONG *pCurrent,DWORD CurrentFlags,LONGLONG *pStop,DWORD StopFlags)
{
	LogDebug("pin:SetPositions: current:%x stop:%x", *pCurrent, *pStop);
	return CTimeShiftSeeking::SetPositions(pCurrent,CurrentFlags,pStop,StopFlags);
}
HRESULT CFilterOutPin::FillBuffer(IMediaSample *pSample)
{
	
	if (m_lastPTS==0) 
		m_lastPTS=m_pSections->pids.StartPTS;
	CheckPointer(pSample, E_POINTER);
	//CAutoLock cAutoLockShared(&m_cSharedState);
	{

		PBYTE pData;
		LONG lDataLength;
		HRESULT hr = pSample->GetPointer(&pData);
		if (FAILED(hr))
		{
			LogDebug("GetPointer() failed:%x",hr);
			m_pMPTSFilter->Log((char*)"pin: FillBuffer() error on getting pointer for sample",true);
		
			return hr;
		}
		lDataLength = pSample->GetActualDataLength();


		

		do
		{
			m_pMPTSFilter->UpdatePids();
			bool endOfFile=false;
			hr = m_pBuffers->Require(lDataLength,endOfFile);
			if (endOfFile)
			{
				if (m_pMPTSFilter->m_pFileReader->m_hInfoFile!=INVALID_HANDLE_VALUE)
				{
					LogDebug("output pin:EOF");
					__int64 fileSize;
					m_pMPTSFilter->m_pFileReader->GetFileSize(&fileSize);
					int count=0;
					while (true)
					{
						m_pMPTSFilter->UpdatePids();
						LogDebug("output pin pos:%x size:%x", m_pSections->pids.fileStartPosition,fileSize);
						if (m_pSections->pids.fileStartPosition >= fileSize-(1024*1024) ||
							m_pSections->pids.fileStartPosition < lDataLength) 
						{
							count++;
							if (count >20) break;
							Sleep(50);
						}
						else break;
					}
					LogDebug("outputpin:end of file, writepos:%x slept:%i", m_pSections->pids.fileStartPosition,count);
				}
			}

		} while (hr==S_OK && m_pBuffers->Count() < lDataLength);
		

		if (FAILED(hr))
		{
			if (m_pMPTSFilter->m_pFileReader->m_hInfoFile==INVALID_HANDLE_VALUE)
			{
				LogDebug("outpin:end of file detected");
				return S_FALSE;//end of stream
			}
				
			LogDebug("outpin: Require(%d) failed:0x%x",lDataLength,hr);
			//m_pMPTSFilter->Refresh();
			//return S_FALSE; // cant read = end of stream
		}

		m_pBuffers->DequeFromBuffer(pData, lDataLength);

		ULONGLONG pts=0;
		ULONGLONG ptsStart=0;
		ULONGLONG ptsEnd=0;
		
		BOOL bSyncPoint=FALSE;
		int pid;
		for(int i=0;i<lDataLength;i+=188)
		{
			if(m_pSections->CurrentPTS(&pData[i],&pts,&pid)==S_OK)
			{
				if (pid==m_pSections->pids.VideoPid) 
					bSyncPoint=TRUE;
				if (pts>0)
				{
					if (ptsStart==0) 
					{ 
						ptsStart=pts; 
						ptsEnd=pts;
					}
					else 
					{
						ptsEnd=pts;
					}
					/*
					// correct our clock
					ULONGLONG millis = pts / 90; // Systemclock (27MHz) / 300
					m_dwStartTime = (DWORD)(timeGetTime() - millis);
					break; // first pts*/
				}
		
			}
		}
		UpdatePositions(ptsStart,ptsEnd);

		REFERENCE_TIME rtStart = static_cast<REFERENCE_TIME>(ptsStart / m_dRateSeeking);
		REFERENCE_TIME rtStop  = static_cast<REFERENCE_TIME>(ptsEnd / m_dRateSeeking);

		pSample->SetTime(&rtStart, &rtStop); 
		pSample->SetSyncPoint(bSyncPoint);

		
		if(m_bDiscontinuity) 
		{
			LogDebug("pin: FillBuffer() SetDiscontinuity");
			pSample->SetDiscontinuity(TRUE);
			m_bDiscontinuity = FALSE;
		}
	}
		
	
		
	return NOERROR;
}

HRESULT CFilterOutPin::OnThreadCreate( )
{
    CAutoLock cAutoLockShared(&m_cSharedState);
	if(m_pFileReader->IsFileInvalid()==TRUE)
	{
		m_pFileReader->OpenFile();
	}
    return S_OK;
}

HRESULT CFilterOutPin::OnThreadStartPlay( )
{
   m_bDiscontinuity = TRUE;
   return DeliverNewSegment(m_rtStart, m_rtStop, m_dRateSeeking);
}

HRESULT CFilterOutPin::Run(REFERENCE_TIME tStart)
{
	return CBaseOutputPin::Run(tStart);
}


HRESULT CFilterOutPin::ChangeStart()
{
	m_pMPTSFilter->SetFilePosition(m_rtStart);
    UpdateFromSeek();
    return S_OK;
}

HRESULT CFilterOutPin::ChangeStop()
{
    UpdateFromSeek();
    return S_OK;
}

HRESULT CFilterOutPin::ChangeRate()
{
    {   // Scope for critical section lock.
        CAutoLock cAutoLockSeeking(CTimeShiftSeeking::m_pLock);
        if( m_dRateSeeking <= 0 ) {
            m_dRateSeeking = 1.0;  // Reset to a reasonable value.
            return E_FAIL;
        }
    }
    UpdateFromSeek();
	return S_OK;
}

void CFilterOutPin::UpdateFromSeek(void)
{
	if (ThreadExists())
	{
		LogDebug("pin:UpdateFromSeek()");
		DeliverBeginFlush();
		Stop();
		DeliverEndFlush();
		Pause();
	}
}

HRESULT CFilterOutPin::SetDuration(REFERENCE_TIME duration)
{
	
	CAutoLock lock(CTimeShiftSeeking::m_pLock);
	m_rtDuration = duration;
	m_rtStop = m_rtDuration;
    return S_OK;
}

HRESULT CFilterOutPin::GetReferenceClock(IReferenceClock **pClock)
{
	HRESULT hr;
	FILTER_INFO		filterInfo;
	hr = m_pFilter->QueryFilterInfo(&filterInfo);

	if (filterInfo.pGraph)
	{
		// Get IMediaFilter interface
		IMediaFilter* pMediaFilter = NULL;
		hr = filterInfo.pGraph->QueryInterface(IID_IMediaFilter, (void**)&pMediaFilter);
		filterInfo.pGraph->Release();

		if (pMediaFilter)
		{
			// Get IReferenceClock interface
			hr = pMediaFilter->GetSyncSource(pClock);
			pMediaFilter->Release();
			return S_OK;
		}
	}
	return E_FAIL;
}
void CFilterOutPin::ResetBuffers()
{
	if (m_pBuffers==NULL) return;
	m_pBuffers->Clear();
	m_bDiscontinuity=true;
}

void CFilterOutPin::UpdatePositions(ULONGLONG& ptsStart, ULONGLONG& ptsEnd)
{
	CRefTime rtStart,rtStop,rtDuration;

	Sections::PTSTime time;
	rtStart=m_pSections->pids.StartPTS;
	rtStop=m_pSections->pids.EndPTS;
	rtDuration=m_pSections->pids.EndPTS-m_pSections->pids.StartPTS;
	
	
	if (ptsStart==0) ptsStart=m_lastPTS;
	if (ptsEnd==0) ptsEnd=m_lastPTS;

	m_lastPTS=ptsEnd;

	ptsStart -=rtStart;
	ptsEnd   -=rtStart;

	m_pSections->PTSToPTSTime(ptsStart,&time);
	ptsStart=((ULONGLONG)36000000000*time.h)+((ULONGLONG)600000000*time.m)+((ULONGLONG)10000000*time.s)+((ULONGLONG)1000*time.u);

	m_pSections->PTSToPTSTime(ptsEnd,&time);
	ptsEnd=((ULONGLONG)36000000000*time.h)+((ULONGLONG)600000000*time.m)+((ULONGLONG)10000000*time.s)+((ULONGLONG)1000*time.u);

	m_pSections->PTSToPTSTime(rtStart,&time);
	rtStart=((ULONGLONG)36000000000*time.h)+((ULONGLONG)600000000*time.m)+((ULONGLONG)10000000*time.s)+((ULONGLONG)1000*time.u);


	m_pSections->PTSToPTSTime(rtStop,&time);
	rtStop=((ULONGLONG)36000000000*time.h)+((ULONGLONG)600000000*time.m)+((ULONGLONG)10000000*time.s)+((ULONGLONG)1000*time.u);

	//m_pSections->PTSToPTSTime(rtDuration,&time);
	//m_rtDuration=((ULONGLONG)36000000000*time.h)+((ULONGLONG)600000000*time.m)+((ULONGLONG)10000000*time.s)+((ULONGLONG)1000*time.u);

	m_rtStart=rtStart;
	m_rtStop=rtStop;
	m_rtDuration=rtStop-rtStart;
}