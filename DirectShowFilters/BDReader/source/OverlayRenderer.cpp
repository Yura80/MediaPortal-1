/*
 *  Copyright (C) 2005-2011 Team MediaPortal
 *  http://www.team-mediaportal.com
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GNU Make; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "OverlayRenderer.h"
#include <streams.h>
#include <D3d9.h>
#include "LibBlurayWrapper.h"

#define TRACE_PERF //LogDebug

// For more details for memory leak detection see the alloctracing.h header
#include "..\..\alloctracing.h"

extern void LogDebug(const char *fmt, ...);

COverlayRenderer::COverlayRenderer(CLibBlurayWrapper* pLib) :
  m_pLib(pLib),
  m_bIsMenuOpen(false),
  m_pD3DDevice(NULL)
{
}

COverlayRenderer::~COverlayRenderer()
{
}

void COverlayRenderer::SetD3DDevice(IDirect3DDevice9* device)
{
  m_pD3DDevice = device;
}

void COverlayRenderer::OverlayProc(const BD_OVERLAY* const ov)
{
  bool bIsMenuOpen = false;

  if (!ov)
  {
    CloseOverlay();
    return;
  }
  else
    TRACE_PERF("OverlayProc - %d %d %d %d plane:%d pts:%d", ov->x, ov->y, ov->w, ov->h, ov->plane, ov->pts);

  if (ov->plane > 1) 
    return;

  TRACE_PERF("OverlayProc - mark 1");

  switch (ov->cmd) 
  {
    case BD_OVERLAY_INIT:    /* init overlay plane. Size of full plane in x,y,w,h */
      //open_overlay(this, ov);
      return;
    case BD_OVERLAY_CLOSE:   /* close overlay */
      //close_overlay(this, ov->plane);
      CloseOverlay();
      return;
  }

  //xine_osd_t *osd = get_overlay(this, ov->plane);

  switch (ov->cmd) 
  {
    case BD_OVERLAY_DRAW:    /* draw bitmap (x,y,w,h,img,palette) */
      DrawBitmap(ov);
      return;

    case BD_OVERLAY_WIPE:    /* clear area (x,y,w,h) */
      ClearArea(ov);
      return;

    case BD_OVERLAY_CLEAR:   /* clear plane */
      ClearOverlay(ov);
      return;

    case BD_OVERLAY_FLUSH:   /* all changes have been done, flush overlay to display at given pts */
      //xine_osd_show(osd, 0);

      m_pLib->HandleMenuStateChange(true);

      if (ov->plane == 1) 
      {
        //this->menu_open = 1;
        //send_num_buttons(this, 1);
      }
      return;

    default:
      //LOGMSG("unknown overlay command %d", ov->cmd);
      return;
  }


  /*
  if (bIsMenuOpen != m_bIsMenuOpen)
  {
    m_pLib->HandleMenuStateChange(bIsMenuOpen);
    m_bIsMenuOpen = bIsMenuOpen;
  }*/
  
  
  /*
  if (osdTexture.texture)
    osdTexture.texture->Release();
  */
}


void COverlayRenderer::ClearOverlay(const BD_OVERLAY* const ov)
{      
  //xine_osd_draw_rect(osd, 0, 0, osd->osd.width - 1, osd->osd.height - 1, 0xff, 1);
      
  //xine_osd_clear(osd);
  //xine_osd_hide(osd, 0);

  OSDTexture osdTexture;
  osdTexture.height = 1080;
  osdTexture.width = 1980;
  osdTexture.x = 0;
  osdTexture.y = 0;
  osdTexture.texture = NULL;

  if (m_pD3DDevice)
  {
    D3DLOCKED_RECT lockedRect;
    
    HRESULT hr = m_pD3DDevice->CreateTexture(1920, 1080, 1, D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, 
                                D3DPOOL_DEFAULT, &osdTexture.texture, NULL);
    
    if (SUCCEEDED(hr))
    {
      hr = osdTexture.texture->LockRect(0, &lockedRect, NULL, 0);
      if (SUCCEEDED(hr))
      {
        UINT32* dst = (UINT32*)lockedRect.pBits;
        const BD_PG_RLE_ELEM* rlep = ov->img;
        unsigned pixels = 1920 * 1080;

        // Clear part of the overlay
        for (int i = 0; i < 1080; i++)
        {
          memset(dst, 0x00, ov->w * 4); // D3DFMT_A8R8G8B8
          dst += lockedRect.Pitch / 4;
        }

        osdTexture.texture->UnlockRect(0);
        //bIsMenuOpen = true;
      }
      else
      {
        LogDebug("   LockRect 0x%08x", hr);
      }
    }
    else
    {
      LogDebug("   CreateTexture 0x%08x", hr);
    }
  }

  m_pLib->HandleOSDUpdate(osdTexture);
  m_pLib->HandleMenuStateChange(false);
}

void COverlayRenderer::ClearArea(const BD_OVERLAY* const ov)
{
  ///xine_osd_draw_rect(osd, ov->x, ov->y, ov->x + ov->w - 1, ov->y + ov->h - 1, 0xff, 1);
  OSDTexture osdTexture;
  osdTexture.height = ov->h;
  osdTexture.width = ov->w;
  osdTexture.x = ov->x;
  osdTexture.y = ov->y;
  osdTexture.texture = NULL;

  if (m_pD3DDevice)
  {
    D3DLOCKED_RECT lockedRect;
    
    HRESULT hr = m_pD3DDevice->CreateTexture(ov->w, ov->h, 1, D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, 
                                D3DPOOL_DEFAULT, &osdTexture.texture, NULL);
    
    if (SUCCEEDED(hr))
    {
      hr = osdTexture.texture->LockRect(0, &lockedRect, NULL, 0);
      if (SUCCEEDED(hr))
      {
        UINT32* dst = (UINT32*)lockedRect.pBits;
        const BD_PG_RLE_ELEM* rlep = ov->img;
        unsigned pixels = ov->w * ov->h;

        // Clear part of the overlay
        for (int i = 0; i < ov->h; i++)
        {
          memset(dst, 0x00, ov->w * 4); // D3DFMT_A8R8G8B8
          dst += lockedRect.Pitch / 4;
        }

        osdTexture.texture->UnlockRect(0);
        //bIsMenuOpen = true;
      }
      else
      {
        LogDebug("   LockRect 0x%08x", hr);
      }
    }
    else
    {
      LogDebug("   CreateTexture 0x%08x", hr);
    }
  }

  m_pLib->HandleOSDUpdate(osdTexture);
}

void COverlayRenderer::DrawBitmap(const BD_OVERLAY* const ov)
{
  if (ov->palette)
  {
    DecodePalette(ov);
  }

  if (!ov->img)
  {
    // Clear the whole overlay area and close overlay
    if (ov->x == 0 && ov->y == 0 && ov->w == 1920 && ov->h == 1080) 
    {
      // Nothing to display
      CloseOverlay();
      return;
    }
  }

  TRACE_PERF("OverlayProc - mark 2");

  OSDTexture osdTexture;
  osdTexture.height = ov->h;
  osdTexture.width = ov->w;
  osdTexture.x = ov->x;
  osdTexture.y = ov->y;
  osdTexture.texture = NULL;

  if (m_pD3DDevice)
  {
    D3DLOCKED_RECT lockedRect;
    
    HRESULT hr = m_pD3DDevice->CreateTexture(ov->w, ov->h, 1, D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, 
                                D3DPOOL_DEFAULT, &osdTexture.texture, NULL);
    
    if (SUCCEEDED(hr))
    {
      hr = osdTexture.texture->LockRect(0, &lockedRect, NULL, 0);
      if (SUCCEEDED(hr))
      {
        UINT32* dst = (UINT32*)lockedRect.pBits;
        const BD_PG_RLE_ELEM* rlep = ov->img;
        unsigned pixels = ov->w * ov->h;

        // Copy image data to the texture
        if (ov->img)
        {
          for (unsigned int i = 0; i < pixels; rlep++)
          {
            for (unsigned int j = rlep->len; j > 0; j--)
            {
              if (i > 0 && i % ov->w == 0)
                dst += lockedRect.Pitch / 4 - ov->w;

              *dst = m_palette[rlep->color];
              dst++;
              i++;
            }
          }
        }
        else 
        {
          // Clear part of the overlay
          for (int i = 0; i < ov->h; i++)
          {
            memset(dst, 0x00, ov->w * 4); // D3DFMT_A8R8G8B8
            dst += lockedRect.Pitch / 4;
          }
        }

        osdTexture.texture->UnlockRect(0);
        //bIsMenuOpen = true;
      }
      else
      {
        LogDebug("   LockRect 0x%08x", hr);
      }
    }
    else
    {
      LogDebug("   CreateTexture 0x%08x", hr);
    }
  }

  m_pLib->HandleOSDUpdate(osdTexture);
}


void COverlayRenderer::CloseOverlay()
{  
  OSDTexture nullTexture = {0};

  TRACE_PERF("ClearOverlay - clear overlay");
  m_pLib->HandleOSDUpdate(nullTexture);
    
  if (m_bIsMenuOpen)
  {    
    m_pLib->HandleMenuStateChange(false);
    m_bIsMenuOpen = false;
  }
}

void COverlayRenderer::DecodePalette(const BD_OVERLAY* const ov)
{
  for (unsigned int i = 0; i < PALETTE_SIZE; i++) 
  {
    // Convert the palette to use RGB colors instead of YUV as converting palette is
    // much faster than converting the whole bitmap.
    int T = ov->palette[i].T;
    int B = (int)(1.164 * (ov->palette[i].Y - 16) + 2.018 * (ov->palette[i].Cb - 128));
    int G = (int)(1.164 * (ov->palette[i].Y - 16) - 0.813 * (ov->palette[i].Cr - 128) - 0.391 * (ov->palette[i].Cb - 128));
    int R = (int)(1.164 * (ov->palette[i].Y - 16) + 1.596 * (ov->palette[i].Cr - 128));
    if (B < 0) B = 0; if (B > 255) B = 255;
    if (G < 0) G = 0; if (G > 255) G = 255;
    if (R < 0) R = 0; if (R > 255) R = 255; 
  
    R = (R * T) / 255;
    G = (G * T) / 255;
    B = (B * T) / 255;
    m_palette[i] = R << 16 | G << 8 | B | T << 24;
  }
}

bool COverlayRenderer::IsMenuOpen()
{
  return m_bIsMenuOpen;
}