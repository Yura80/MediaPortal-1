/ *  
   * 	 C o p y r i g h t   ( C )   2 0 0 5 - 2 0 0 6   T e a m   M e d i a P o r t a l  
   *     A u t h o r :   t o u r e t t e s  
   * 	 h t t p : / / w w w . t e a m - m e d i a p o r t a l . c o m  
   *  
   *     T h i s   P r o g r a m   i s   f r e e   s o f t w a r e ;   y o u   c a n   r e d i s t r i b u t e   i t   a n d / o r   m o d i f y  
   *     i t   u n d e r   t h e   t e r m s   o f   t h e   G N U   G e n e r a l   P u b l i c   L i c e n s e   a s   p u b l i s h e d   b y  
   *     t h e   F r e e   S o f t w a r e   F o u n d a t i o n ;   e i t h e r   v e r s i o n   2 ,   o r   ( a t   y o u r   o p t i o n )  
   *     a n y   l a t e r   v e r s i o n .  
   *  
   *     T h i s   P r o g r a m   i s   d i s t r i b u t e d   i n   t h e   h o p e   t h a t   i t   w i l l   b e   u s e f u l ,  
   *     b u t   W I T H O U T   A N Y   W A R R A N T Y ;   w i t h o u t   e v e n   t h e   i m p l i e d   w a r r a n t y   o f  
   *     M E R C H A N T A B I L I T Y   o r   F I T N E S S   F O R   A   P A R T I C U L A R   P U R P O S E .   S e e   t h e  
   *     G N U   G e n e r a l   P u b l i c   L i c e n s e   f o r   m o r e   d e t a i l s .  
   *  
   *     Y o u   s h o u l d   h a v e   r e c e i v e d   a   c o p y   o f   t h e   G N U   G e n e r a l   P u b l i c   L i c e n s e  
   *     a l o n g   w i t h   G N U   M a k e ;   s e e   t h e   f i l e   C O P Y I N G .     I f   n o t ,   w r i t e   t o  
   *     t h e   F r e e   S o f t w a r e   F o u n d a t i o n ,   6 7 5   M a s s   A v e ,   C a m b r i d g e ,   M A   0 2 1 3 9 ,   U S A .  
   *     h t t p : / / w w w . g n u . o r g / c o p y l e f t / g p l . h t m l  
   *  
   * /  
  
 # p r a g m a   w a r n i n g (   d i s a b l e :   4 9 9 5   4 9 9 6   )  
  
 # i n c l u d e   " S u b T r a n s f o r m . h "  
 # i n c l u d e   " S u b t i t l e I n p u t P i n . h "  
 # i n c l u d e   " P c r I n p u t P i n . h "  
 # i n c l u d e   " P M T I n p u t P i n . h "  
 # i n c l u d e   < b d a i f a c e . h >  
  
 c o n s t   D W O R D   f c c U Y V Y   =   M A K E F O U R C C ( ' U ' , ' Y ' , ' V ' , ' Y ' ) ;  
 c o n s t   D W O R D   f c c Y U Y 2   =   M A K E F O U R C C ( ' Y ' , ' U ' , ' Y ' , ' 2 ' ) ;  
  
 c o n s t   i n t   s u b t i t l e S i z e I n B y t e s   =   7 2 0   *   5 7 6   *   3 ;  
  
 c o n s t   L O N G   s u b D e l a y   =   5 2 0 0 0 0 ;  
  
 e x t e r n   v o i d   L o g ( c o n s t   c h a r   * f m t ,   . . . ) ;  
  
 / /   S e t u p   d a t a  
 c o n s t   A M O V I E S E T U P _ M E D I A T Y P E   s u d P i n T y p e s S u b t i t l e   =  
 {  
 	 & M E D I A T Y P E _ M P E G 2 _ S E C T I O N S ,   & M E D I A S U B T Y P E _ D V B _ S I  
 } ;  
  
 c o n s t   A M O V I E S E T U P _ M E D I A T Y P E   s u d P i n T y p e s O u t p u t   =  
 {  
 	 & M E D I A T Y P E _ N U L L ,   & M E D I A S U B T Y P E _ N U L L  
 } ;  
  
 c o n s t   A M O V I E S E T U P _ P I N   s u d P i n s [ 5 ]   =  
 {  
 	 {  
 	 	 L " S u b t i t l e " , 	 	 	 	     / /   P i n   s t r i n g   n a m e  
 	 	 F A L S E , 	 	 	 	 	 	         / /   I s   i t   r e n d e r e d  
 	 	 F A L S E , 	 	 	 	 	 	         / /   I s   i t   a n   o u t p u t  
 	 	 F A L S E , 	 	 	 	 	 	         / /   A l l o w e d   n o n e  
 	 	 F A L S E , 	 	 	 	 	 	         / /   L i k e w i s e   m a n y  
 	 	 & C L S I D _ N U L L , 	 	 	 	     / /   C o n n e c t s   t o   f i l t e r  
 	 	 L " S u b t i t l e " , 	 	 	 	     / /   C o n n e c t s   t o   p i n  
 	 	 1 , 	 	 	 	 	 	 	             / /   N u m b e r   o f   t y p e s  
 	 	 & s u d P i n T y p e s S u b t i t l e     / /   P i n   i n f o r m a t i o n  
 	 } ,  
 	 {  
 	 	 L " V i d e o " , 	 	 	 	 	     / /   P i n   s t r i n g   n a m e  
 	 	 F A L S E , 	 	 	 	 	 	     / /   I s   i t   r e n d e r e d  
 	 	 F A L S E , 	 	 	 	 	 	     / /   I s   i t   a n   o u t p u t  
 	 	 F A L S E , 	 	 	 	 	 	     / /   A l l o w e d   n o n e  
 	 	 F A L S E , 	 	 	 	 	 	     / /   L i k e w i s e   m a n y  
 	 	 & C L S I D _ N U L L , 	 	 	 	 / /   C o n n e c t s   t o   f i l t e r  
 	 	 L " V i d e o " , 	 	 	 	 	     / /   C o n n e c t s   t o   p i n  
 	 	 1 , 	 	 	 	 	 	 	         / /   N u m b e r   o f   t y p e s  
 	 	 & s u d P i n T y p e s O u t p u t     / /   P i n   i n f o r m a t i o n  
 	 } ,  
 	 {  
 	 	 L " A u d i o " , 	 	 	 	 	     / /   P i n   s t r i n g   n a m e  
 	 	 F A L S E , 	 	 	 	 	 	     / /   I s   i t   r e n d e r e d  
 	 	 F A L S E , 	 	 	 	 	 	     / /   I s   i t   a n   o u t p u t  
 	 	 F A L S E , 	 	 	 	 	 	     / /   A l l o w e d   n o n e  
 	 	 F A L S E , 	 	 	 	 	 	     / /   L i k e w i s e   m a n y  
 	 	 & C L S I D _ N U L L , 	 	 	     / /   C o n n e c t s   t o   f i l t e r  
 	 	 L " A u d i o " , 	 	 	 	 	     / /   C o n n e c t s   t o   p i n  
 	 	 1 , 	 	 	 	 	 	 	         / /   N u m b e r   o f   t y p e s  
 	 	 & s u d P i n T y p e s O u t p u t 	 / /   P i n   i n f o r m a t i o n  
 	 } ,  
 	 {  
 	 	 L " P M T " , 	 	 	 	 	         / /   P i n   s t r i n g   n a m e  
 	 	 F A L S E , 	 	 	 	 	 	     / /   I s   i t   r e n d e r e d  
 	 	 F A L S E , 	 	 	 	 	 	     / /   I s   i t   a n   o u t p u t  
 	 	 F A L S E , 	 	 	 	 	 	     / /   A l l o w e d   n o n e  
 	 	 F A L S E , 	 	 	 	 	 	     / /   L i k e w i s e   m a n y  
 	 	 & C L S I D _ N U L L , 	 	 	     / /   C o n n e c t s   t o   f i l t e r  
 	 	 L " P M T " , 	 	 	 	 	         / /   C o n n e c t s   t o   p i n  
 	 	 1 , 	 	 	 	 	 	 	         / /   N u m b e r   o f   t y p e s  
 	 	 & s u d P i n T y p e s O u t p u t 	 / /   P i n   i n f o r m a t i o n  
 	 } ,  
  
 	 {  
 	 	 L " O u t p u t " , 	 	 	 	     / /   P i n ' s   s t r i n g   n a m e  
 	 	 F A L S E , 	 	 	 	 	 	     / /   I s   i t   r e n d e r e d  
 	 	 T R U E , 	 	 	 	 	 	         / /   I s   i t   a n   o u t p u t  
 	 	 F A L S E , 	 	 	 	 	 	     / /   A l l o w e d   n o n e  
 	 	 F A L S E , 	 	 	 	 	 	     / /   A l l o w e d   m a n y  
 	 	 & C L S I D _ N U L L , 	 	 	     / /   C o n n e c t s   t o   f i l t e r  
 	 	 L " O u t p u t " , 	 	 	 	     / /   C o n n e c t s   t o   p i n  
 	 	 1 , 	 	 	 	 	 	 	         / /   N u m b e r   o f   t y p e s  
 	 	 & s u d P i n T y p e s O u t p u t     / /   P i n   t y p e   i n f o r m a t i o n  
 	 }  
 } ;  
 / /  
 / /   C o n s t r u c t o r  
 / /  
 C S u b T r a n s f o r m : : C S u b T r a n s f o r m (   L P U N K N O W N   p U n k ,   H R E S U L T   * p h r   )   :  
 	 C T r a n s f o r m F i l t e r (   N A M E ( " M e d i a P o r t a l   S u b   T r a n s f o r m   F i l t e r " ) ,   p U n k ,   C L S I D _ S u b T r a n s f o r m   ) ,  
 	 m _ p S u b t i t l e P i n (   N U L L   ) ,  
 	 m _ p P c r P i n (   N U L L   ) ,  
     m _ p P M T P i n (   N U L L   ) ,  
 	 m _ p S u b D e c o d e r (   N U L L   ) ,  
 	 m _ p S u b t i t l e (   N U L L   ) ,  
 	 m _ b R e n d e r C u r r e n t S u b t i t l e (   f a l s e   ) ,  
 	 m _ c u r S u b t i t l e P T S (   0   ) ,  
 	 m _ N e x t S u b t i t l e P T S (   0   ) ,  
 	 m _ c u r P T S (   0   ) ,  
 	 m _ P T S d i f f (   0   ) ,  
 	 m _ f i r s t P T S (   0   ) ,  
 	 m _ f i r s t P T S D o n e (   f a l s e   ) ,  
 	 m _ b S u b t i t l e D i s c a r d e d (   t r u e   ) ,  
 	 m _ S h o w D u r a t i o n (   3 8 8 0 0 0   ) ,  
 	 m _ p D i b B i t s (   N U L L   ) ,  
     m _ D i b s S u b (   N U L L   ) ,  
     m _ D C (   N U L L   ) ,  
     m _ O l d O b j e c t (   N U L L   ) ,  
 	 m _ c u r S u b t i t l e D a t a (   N U L L   )  
 {  
 	 / /   C r e a t e   s u b t i t l e   d e c o d e r  
 	 m _ p S u b D e c o d e r   =   n e w   C D V B S u b D e c o d e r ( ) ;  
  
 	 i f (   m _ p S u b D e c o d e r   = =   N U L L   )  
 	 {  
         i f (   p h r   )  
 	 	 {  
             * p h r   =   E _ O U T O F M E M O R Y ;  
 	 	 }  
         r e t u r n ;  
     }  
  
 	 / /   C r e a t e   s u b t i t l e   i n p u t   p i n  
 	 m _ p S u b t i t l e P i n   =   n e w   C S u b t i t l e I n p u t P i n (   t h i s ,  
 	 	 	 	 	 	 	 	 G e t O w n e r ( ) ,  
 	 	 	 	 	 	 	 	 t h i s ,  
 	 	 	 	 	 	 	 	 & m _ L o c k ,  
 	 	 	 	 	 	 	 	 & m _ R e c e i v e L o c k ,  
 	 	 	 	 	 	 	 	 m _ p S u b D e c o d e r ,  
 	 	 	 	 	 	 	 	 p h r   ) ;  
  
 	 i f   (   m _ p S u b t i t l e P i n   = =   N U L L   )  
 	 {  
         i f (   p h r   )  
 	 	 {  
             * p h r   =   E _ O U T O F M E M O R Y ;  
 	 	 }  
             r e t u r n ;  
         }  
  
 	 / /   C r e a t e   o u t p u t   p i n  
 	 m _ p O u t p u t   =   n e w   C T r a n s f o r m O u t p u t P i n (  
 	 	 N A M E ( " C T r a n s f o r m O u t p u t P i n " ) ,   t h i s ,   p h r ,   L " O u t "   ) ;  
  
 	 i f (   m _ p O u t p u t   = =   N U L L   )  
 	 {  
         i f (   p h r   )  
 	 	 {  
             * p h r   =   E _ O U T O F M E M O R Y ;  
 	 	 }  
             r e t u r n ;  
         }  
  
 	 / /   C r e a t e   v i d e o   i n p u t   p i n  
 	 m _ p I n p u t   =   n e w   C T r a n s f o r m I n p u t P i n (  
 	 	 N A M E ( " C T r a n s f o r m I n p u t P i n " ) ,   t h i s ,   p h r ,   L " V i d e o   I n " ) ;  
  
 	 i f   (   m _ p O u t p u t   = =   N U L L   )  
 	 {  
         i f (   p h r   )  
 	 	 {  
             * p h r   =   E _ O U T O F M E M O R Y ;  
 	 	 }  
             r e t u r n ;  
         }  
  
 	 / /   C r e a t e   p c r   i n p u t   p i n  
 	 m _ p P c r P i n   =   n e w   C P c r I n p u t P i n (   t h i s ,  
 	 	 	 	 	 	 	 	 G e t O w n e r ( ) ,  
 	 	 	 	 	 	 	 	 t h i s ,  
 	 	 	 	 	 	 	 	 & m _ L o c k ,  
 	 	 	 	 	 	 	 	 & m _ R e c e i v e L o c k ,  
 	 	 	 	 	 	 	 	 p h r   ) ;  
  
 	 i f   (   m _ p P c r P i n   = =   N U L L   )  
 	 {  
         i f (   p h r   )  
 	 	 {  
             * p h r   =   E _ O U T O F M E M O R Y ;  
 	 	 }  
             r e t u r n ;  
         }  
  
 	 / /   C r e a t e   P M T   i n p u t   p i n  
 	 m _ p P M T P i n   =   n e w   C P M T I n p u t P i n (   t h i s ,  
 	 	 	 	 	 	 	 	 G e t O w n e r ( ) ,  
 	 	 	 	 	 	 	 	 t h i s ,  
 	 	 	 	 	 	 	 	 & m _ L o c k ,  
 	 	 	 	 	 	 	 	 & m _ R e c e i v e L o c k ,  
 	 	 	 	 	 	 	 	 p h r ,  
                                 t h i s   ) ;   / /   M P i d O b s e r v e r  
  
 	 i f   (   m _ p P M T P i n   = =   N U L L   )  
 	 {  
         i f (   p h r   )  
 	 	 {  
             * p h r   =   E _ O U T O F M E M O R Y ;  
 	 	 }  
             r e t u r n ;  
         }  
  
 	 m _ c u r S u b t i t l e D a t a   =   N U L L ;  
 	 m _ p S u b D e c o d e r - > S e t O b s e r v e r (   t h i s   ) ;  
 }  
  
 C S u b T r a n s f o r m : : ~ C S u b T r a n s f o r m ( )  
 {  
 	 m _ p S u b D e c o d e r - > S e t O b s e r v e r (   N U L L   ) ;  
 	 d e l e t e   m _ p S u b D e c o d e r ;  
 	 d e l e t e   m _ p S u b t i t l e P i n ;  
 	 d e l e t e   m _ p P c r P i n ;  
     d e l e t e   m _ p P M T P i n ;  
 	 D e l e t e O b j e c t (   m _ D i b s S u b   ) ;  
 	 D e l e t e O b j e c t (   m _ O l d O b j e c t   ) ;  
 }  
  
 / /  
 / /   G e t P i n  
 / /  
 C B a s e P i n   *   C S u b T r a n s f o r m : : G e t P i n (   i n t   n   )  
 {  
     i f   (   n   = =   0   )  
 	 {  
         / /   C B a s e P i n   o u t p u t   p i n  
 	 	 r e t u r n   m _ p O u t p u t ;  
 	 }  
 	 i f (   n   = =   1   )  
 	 {  
 	 	 / /   C B a s e P i n   i n p u t   p i n  
 	 	 r e t u r n   m _ p I n p u t ;  
 	 }  
 	 i f (   n   = =   2   )  
 	 {  
 	 	 r e t u r n   m _ p S u b t i t l e P i n ;  
 	 }  
 	 i f (   n   = =   3   )  
 	 {  
 	 	 r e t u r n   m _ p P c r P i n ;  
 	 }  
 	 i f (   n   = =   4   )  
 	 {  
 	 	 r e t u r n   m _ p P M T P i n ;  
 	 }  
 	 e l s e  
 	 {  
         r e t u r n   N U L L ;  
     }  
 }  
  
 i n t   C S u b T r a n s f o r m : : G e t P i n C o u n t ( )  
 {  
 	 r e t u r n   5 ;   / /   i n p u t ,   o u t p u t ,   s u b t i t l e ,   p c r   &   P M T  
 }  
  
 H R E S U L T   C S u b T r a n s f o r m : : C h e c k I n p u t T y p e (   c o n s t   C M e d i a T y p e   * p m t   )  
 {  
     i f (   I s V a l i d U Y V Y (   p m t   )   )  
     {  
         r e t u r n   S _ O K ;  
     }  
     i f (   I s V a l i d Y U Y 2 (   p m t   )   )  
 	 {  
         r e t u r n   S _ O K ;  
     }  
 	 r e t u r n   V F W _ E _ T Y P E _ N O T _ A C C E P T E D ;  
 }  
  
 H R E S U L T   C S u b T r a n s f o r m : : C h e c k C o n n e c t (   P I N _ D I R E C T I O N   d i r ,   I P i n   * p P i n   )  
 {  
     H R E S U L T   h r   =   C T r a n s f o r m F i l t e r : : C h e c k C o n n e c t (   d i r ,   p P i n   ) ;  
  
     A M _ M E D I A _ T Y P E   m e d i a T y p e ;  
     i n t   v i d e o P i d   =   0 ;  
  
     p P i n - > C o n n e c t i o n M e d i a T y p e (   & m e d i a T y p e   ) ;  
  
     / /   S e a r c h   f o r   d e m u x e r ' s   v i d e o   p i n  
     i f (     m e d i a T y p e . m a j o r t y p e   = =   M E D I A T Y P E _ V i d e o   & &   d i r   = =   P I N D I R _ I N P U T   )  
     {  
 	     I M P E G 2 P I D M a p *   p M u x M a p P i d ;  
 	     i f (   S U C C E E D E D (   p P i n - > Q u e r y I n t e r f a c e (   & p M u x M a p P i d   )   )   )  
         {  
 	 	     I E n u m P I D M a p   * p I E n u m P I D M a p ;  
 	 	     i f (   S U C C E E D E D (   p M u x M a p P i d - > E n u m P I D M a p (   & p I E n u m P I D M a p   )   )   )  
             {  
 	 	 	     U L O N G   c o u n t   =   0 ;  
 	 	 	     P I D _ M A P   p i d M a p ;  
 	 	 	     w h i l e (   p I E n u m P I D M a p - > N e x t (   1 ,   & p i d M a p ,   & c o u n t   )   = =   S _ O K   )  
                 {  
                     m _ V i d e o P i d   =   p i d M a p . u l P I D ;  
                     m _ p P M T P i n - > S e t V i d e o P i d (   m _ V i d e o P i d   ) ;  
                     L o g (   " C h e c k C o n n e c t   -   f o u n d   v i d e o   P I D   % d " ,     m _ V i d e o P i d   ) ;  
 	 	 	     }  
 	 	     }  
 	 	     p M u x M a p P i d - > R e l e a s e ( ) ;  
         }  
     }  
     r e t u r n   S _ O K ;  
 }  
  
  
 H R E S U L T   C S u b T r a n s f o r m : : C h e c k T r a n s f o r m (   c o n s t   C M e d i a T y p e   * m t I n ,   c o n s t   C M e d i a T y p e   * m t O u t   )  
 {  
     / /   M a k e   s u r e   t h e   s u b t y p e s   m a t c h  
     i f (   m t I n - > s u b t y p e   ! =   m t O u t - > s u b t y p e   )  
     {  
         r e t u r n   V F W _ E _ T Y P E _ N O T _ A C C E P T E D ;  
     }  
  
     / /   C u r r e n t l y   s u p p o r t e d   m o d e s   a r e   U Y V Y   &   Y U Y 2  
     i f (   ! I s V a l i d U Y V Y (   m t O u t   )   )  
     {  
         i f (   ! I s V a l i d Y U Y 2 (   m t O u t   )   )  
         {  
             r e t u r n   V F W _ E _ T Y P E _ N O T _ A C C E P T E D ;  
         }  
     }  
  
     B I T M A P I N F O H E A D E R   * p B m i   =   H E A D E R (   m t I n   ) ;  
     B I T M A P I N F O H E A D E R   * p B m i 2   =   H E A D E R (   m t O u t   ) ;  
  
     i f (   (   p B m i - > b i W i d t h   < =   p B m i 2 - > b i W i d t h   )   & &  
             (   p B m i - > b i H e i g h t   = =   a b s (   p B m i 2 - > b i H e i g h t   )   )   )  
     {  
         r e t u r n   S _ O K ;  
     }  
     r e t u r n   V F W _ E _ T Y P E _ N O T _ A C C E P T E D ;  
 }  
  
 H R E S U L T   C S u b T r a n s f o r m : : G e t M e d i a T y p e (   i n t   i P o s i t i o n ,   C M e d i a T y p e   * p M e d i a T y p e   )  
 {  
     A S S E R T (   m _ p I n p u t - > I s C o n n e c t e d ( )   ) ;  
  
     i f (   i P o s i t i o n   <   0   )  
     {  
         r e t u r n   E _ I N V A L I D A R G ;  
     }  
     e l s e   i f (   i P o s i t i o n   = =   0   )  
     {  
         r e t u r n   m _ p I n p u t - > C o n n e c t i o n M e d i a T y p e (   p M e d i a T y p e   ) ;  
     }  
  
 	 r e t u r n   V F W _ S _ N O _ M O R E _ I T E M S ;  
 }  
  
 H R E S U L T   C S u b T r a n s f o r m : : S e t M e d i a T y p e (   P I N _ D I R E C T I O N   d i r e c t i o n ,   c o n s t   C M e d i a T y p e   * p m t   )  
 {  
     i f (   d i r e c t i o n   = =   P I N D I R _ I N P U T   )  
     {  
         A S S E R T (   p m t - > f o r m a t t y p e   = =   F O R M A T _ V i d e o I n f o   ) ;  
         V I D E O I N F O H E A D E R   * p V i h   =   ( V I D E O I N F O H E A D E R * ) p m t - > p b F o r m a t ;  
         C o p y M e m o r y (   & m _ V i h I n ,   p V i h ,   s i z e o f (   V I D E O I N F O H E A D E R   )   ) ;  
     }  
     e l s e       / /   O u t p u t   p i n  
     {  
         A S S E R T (   d i r e c t i o n   = =   P I N D I R _ O U T P U T   ) ;  
         A S S E R T (   p m t - > f o r m a t t y p e   = =   F O R M A T _ V i d e o I n f o   ) ;  
         V I D E O I N F O H E A D E R   * p V i h   =   ( V I D E O I N F O H E A D E R * ) p m t - > p b F o r m a t ;  
         C o p y M e m o r y (   & m _ V i h O u t ,   p V i h ,   s i z e o f (   V I D E O I N F O H E A D E R   )   ) ;  
     }  
     r e t u r n   S _ O K ;  
 }  
  
 H R E S U L T   i n l i n e   C S u b T r a n s f o r m : : P r o c e s s F r a m e U Y V Y (   B Y T E   * p b I n p u t ,   B Y T E   * p b O u t p u t ,   l o n g   * p c b B y t e   )  
 {  
     D W O R D   d w W i d t h ,   d w H e i g h t ;  
     D W O R D   d w W i d t h O u t ,   d w H e i g h t O u t ;  
     L O N G     l S t r i d e I n ,   l S t r i d e O u t ;  
     B Y T E     * p b S o u r c e ,   * p b T a r g e t ;  
  
 	 * p c b B y t e   =   m _ V i h O u t . b m i H e a d e r . b i S i z e I m a g e ;  
  
     G e t V i d e o I n f o P a r a m e t e r s (   & m _ V i h I n ,   p b I n p u t ,   & d w W i d t h ,   & d w H e i g h t ,   & l S t r i d e I n ,   & p b S o u r c e ,   t r u e   ) ;  
     G e t V i d e o I n f o P a r a m e t e r s (   & m _ V i h O u t ,   p b O u t p u t ,   & d w W i d t h O u t ,   & d w H e i g h t O u t ,   & l S t r i d e O u t ,   & p b T a r g e t ,   t r u e   ) ;  
  
 	 i n t   m o v e Y   =   ( 5 7 6   -   4 8 0 ) / 2   *   7 2 0 ;  
 	 / / l o n g   p l a c e   =   m o v e Y * 3 ;  
 	 l o n g   p l a c e   =   0 ;  
 	 b o o l   f i r s t W o r d (   t r u e   ) ;  
 	 W O R D   p i x e l ;   i n t   Y = 0 ,   U = 0 ,   V = 0 ;  
  
 	 f o r (   D W O R D   y   =   0   ;   y   <   d w H e i g h t   ;   y + +   )  
     {  
         W O R D   * p w T a r g e t   =   ( W O R D * ) p b T a r g e t ;  
         W O R D   * p w S o u r c e   =   ( W O R D * ) p b S o u r c e ;  
  
         f o r (   D W O R D   x   =   0   ;   x   <   d w W i d t h   ;   x + +   )  
         {  
 	 	     Y   =   m _ c u r S u b t i t l e D a t a [ p l a c e ] ;  
 	 	     U   =   m _ c u r S u b t i t l e D a t a [ p l a c e   +   1 ] ;  
 	 	     V   =   m _ c u r S u b t i t l e D a t a [ p l a c e   +   2 ] ;  
  
 	 	     p l a c e + = 3 ;  
  
 	 	     i f (   m _ b R e n d e r C u r r e n t S u b t i t l e   = =   f a l s e   | |   (   V   = =   0   & &   U   = =   0   )   )  
 	 	     {  
 	 	 	     p i x e l   =   p w S o u r c e [ x ] ;  
 	 	     }  
 	 	     e l s e  
 	 	     {  
 	 	 	     p i x e l   =   Y   *   0 x 1 0 0 ;  
  
 	 	 	     i f (   f i r s t W o r d   )  
 	 	 	     {  
 	 	 	 	     p i x e l   + =   U ;  
 	 	 	 	     f i r s t W o r d   =   f a l s e ;  
 	 	 	     }  
 	 	 	     e l s e  
 	 	 	     {  
 	 	 	 	     p i x e l   + =   V ;  
 	 	 	 	     f i r s t W o r d   =   t r u e ;  
 	 	 	     }  
 	 	 }  
 	 	 p w T a r g e t [ x ]   =   p i x e l ;  
     }  
  
     / /   A d v a n c e   t h e   s t r i d e   o n   b o t h   b u f f e r s .  
     p b T a r g e t   + =   l S t r i d e O u t ;  
     p b S o u r c e   + =   l S t r i d e I n ;  
     }  
  
 	 r e t u r n   S _ O K ;  
 }  
  
 H R E S U L T   C S u b T r a n s f o r m : : P r o c e s s F r a m e Y U Y 2 (     B Y T E   * p b I n p u t ,  
                                                                                     B Y T E   * p b O u t p u t ,  
 	 	 	 	 	 	 	 	 	 	                                             l o n g   * p c b B y t e   )  
 {  
     D W O R D   d w W i d t h ,   d w H e i g h t ;  
     D W O R D   d w W i d t h O u t ,   d w H e i g h t O u t ;  
     L O N G     l S t r i d e I n ,   l S t r i d e O u t ;  
     B Y T E     * p b S o u r c e ,   * p b T a r g e t ;  
  
 	 * p c b B y t e   =   m _ V i h O u t . b m i H e a d e r . b i S i z e I m a g e ;  
  
     G e t V i d e o I n f o P a r a m e t e r s (   & m _ V i h I n ,   p b I n p u t ,   & d w W i d t h ,   & d w H e i g h t ,   & l S t r i d e I n ,   & p b S o u r c e ,   t r u e   ) ;  
     G e t V i d e o I n f o P a r a m e t e r s (   & m _ V i h O u t ,   p b O u t p u t ,   & d w W i d t h O u t ,   & d w H e i g h t O u t ,   & l S t r i d e O u t ,   & p b T a r g e t ,   t r u e   ) ;  
  
 	 i n t   m o v e Y   =   ( 5 7 6   -   4 8 0 ) / 2   *   7 2 0 ;  
 	 / / l o n g   p l a c e   =   m o v e Y * 3 ;  
 	 l o n g   p l a c e   =   0 ;  
 	 b o o l   f i r s t W o r d (   t r u e   ) ;  
 	 W O R D   p i x e l ;   i n t   Y = 0 ,   U = 0 ,   V = 0 ;  
  
 	 f o r (   D W O R D   y   =   0   ;   y   <   d w H e i g h t   ;   y + +   )  
     {  
 	 	 W O R D   * p w T a r g e t   =   ( W O R D * ) p b T a r g e t ;  
         W O R D   * p w S o u r c e   =   ( W O R D * ) p b S o u r c e ;  
  
           f o r (   D W O R D   x   =   0   ;   x   <   d w W i d t h   ;   x + +   )  
           {  
                 Y   =   m _ c u r S u b t i t l e D a t a [ p l a c e ] ;  
                 U   =   m _ c u r S u b t i t l e D a t a [ p l a c e   +   1 ] ;  
                 V   =   m _ c u r S u b t i t l e D a t a [ p l a c e   +   2 ] ;  
  
     	 	 	 p l a c e + = 3 ;  
  
 	     	 	 i f (   m _ b R e n d e r C u r r e n t S u b t i t l e   = =   f a l s e   | |   (   V   = =   0   & &   U   = =   0   )   )  
 	 	     	 {  
 	 	 	     	 p i x e l   =   p w S o u r c e [ x ] ;  
 	 	 	     }  
 	 	 	     e l s e  
 	 	 	     {  
 	 	 	 	     p i x e l   =   Y ;  
  
 	 	 	 	     i f (   f i r s t W o r d   )  
 	 	 	 	     {  
 	 	 	 	 	     p i x e l   + =   U   *   0 x 1 0 0 ;  
 	 	 	 	 	     f i r s t W o r d   =   f a l s e ;  
 	 	 	 	     }  
 	 	 	 	     e l s e  
 	 	 	 	     {  
 	 	 	 	 	     p i x e l   + =   V   *   0 x 1 0 0 ;  
 	 	 	 	 	     f i r s t W o r d   =   t r u e ;  
 	 	 	 	     }  
 	 	 	     }  
 	 	 	     p w T a r g e t [ x ]   =   p i x e l ;  
             }  
  
             / /   A d v a n c e   t h e   s t r i d e   o n   b o t h   b u f f e r s .  
             p b T a r g e t   + =   l S t r i d e O u t ;  
             p b S o u r c e   + =   l S t r i d e I n ;  
         }  
  
     r e t u r n   S _ O K ;  
 }  
  
 H R E S U L T   C S u b T r a n s f o r m : : D e c i d e B u f f e r S i z e (   I M e m A l l o c a t o r   * p A l l o c ,   A L L O C A T O R _ P R O P E R T I E S   * p P r o p   )  
 {  
         i f (   ! m _ p I n p u t - > I s C o n n e c t e d ( )   )  
         {  
                 r e t u r n   E _ U N E X P E C T E D ;  
         }  
  
         A L L O C A T O R _ P R O P E R T I E S   I n p u t P r o p s ;  
  
         I M e m A l l o c a t o r   * p A l l o c I n p u t   =   0 ;  
         H R E S U L T   h r   =   m _ p I n p u t - > G e t A l l o c a t o r (   & p A l l o c I n p u t   ) ;  
  
         i f (   F A I L E D (   h r   )   )  
         {  
                 r e t u r n   h r ;  
         }  
  
         h r   =   p A l l o c I n p u t - > G e t P r o p e r t i e s (   & I n p u t P r o p s   ) ;  
         p A l l o c I n p u t - > R e l e a s e ( ) ;  
  
         i f (   F A I L E D (   h r   )   )  
         {  
                 r e t u r n   h r ;  
         }  
  
         i f (   p P r o p - > c b B u f f e r   = =   0   )  
         {  
                 p P r o p - > c B u f f e r s   =   1 ;  
         }  
  
 	 i f (   p P r o p - > c b A l i g n   = =   0   )  
         {  
                 p P r o p - > c b A l i g n   =   1 ;  
         }  
  
 	 p P r o p - > c b B u f f e r   =   m a x (   I n p u t P r o p s . c b B u f f e r ,   p P r o p - > c b B u f f e r   ) ;  
  
         A L L O C A T O R _ P R O P E R T I E S   A c t u a l ;  
         h r   =   p A l l o c - > S e t P r o p e r t i e s (   p P r o p ,   & A c t u a l   ) ;  
         i f (   F A I L E D (   h r   )   )  
         {  
                 r e t u r n   h r ;  
         }  
  
         i f (   I n p u t P r o p s . c b B u f f e r   >   A c t u a l . c b B u f f e r   )  
         {  
                 r e t u r n   E _ F A I L ;  
         }  
  
         r e t u r n   S _ O K ;  
 }  
 S T D M E T H O D I M P   C S u b T r a n s f o r m : : R u n (   R E F E R E N C E _ T I M E   t S t a r t   )  
 {  
     C A u t o L o c k   c O b j e c t L o c k (   m _ p L o c k   ) ;  
 	 R e s e t ( ) ;  
 	 r e t u r n   C B a s e F i l t e r : : R u n (   t S t a r t   ) ;  
 }  
  
 S T D M E T H O D I M P   C S u b T r a n s f o r m : : P a u s e ( )  
 {  
     C A u t o L o c k   c O b j e c t L o c k (   m _ p L o c k   ) ;  
 	 / / R e s e t ( ) ;  
 	 r e t u r n   C B a s e F i l t e r : : P a u s e ( ) ;  
 }  
  
 S T D M E T H O D I M P   C S u b T r a n s f o r m : : S t o p ( )  
 {  
         C A u t o L o c k   c O b j e c t L o c k (   m _ p L o c k   ) ;  
  
 	 R e s e t ( ) ;  
  
 	 r e t u r n   C B a s e F i l t e r : : S t o p ( ) ;  
 }  
  
 H R E S U L T   C S u b T r a n s f o r m : : T r a n s f o r m (   I M e d i a S a m p l e   * p S o u r c e ,   I M e d i a S a m p l e   * p D e s t   )  
 {  
 	 C A u t o L o c k   c O b j e c t L o c k (   m _ p L o c k   ) ;  
 	 H R E S U L T   h r (   0   ) ;  
  
     i f (   m _ p P c r P i n   )  
 	     m _ c u r P T S   =   m _ p P c r P i n - > G e t C u r r e n t P T S ( ) ;  
  
 	 / /   L o o k   f o r   f o r m a t   c h a n g e s   f r o m   t h e   v i d e o   r e n d e r e r .  
     C M e d i a T y p e   * p m t   =   0 ;  
     i f (   S _ O K   = =   p D e s t - > G e t M e d i a T y p e (   ( A M _ M E D I A _ T Y P E * * ) & p m t )   & &   p m t   )  
     {  
         / /   N o t i f y   o u r   o w n   o u t p u t   p i n   a b o u t   t h e   n e w   t y p e .  
         m _ p O u t p u t - > S e t M e d i a T y p e (   p m t   ) ;  
         D e l e t e M e d i a T y p e (   p m t   ) ;  
     }  
  
     i f (   m _ c u r S u b t i t l e D a t a   = =   N U L L   )  
 	 {  
 	 	 m _ c u r S u b t i t l e D a t a   =   n e w   B Y T E [ m _ V i h O u t . b m i H e a d e r . b i W i d t h   *   a b s ( m _ V i h O u t . b m i H e a d e r . b i H e i g h t ) *   3 ] ;  
 	 }  
  
     B Y T E   * p B u f f e r I n ,   * p B u f f e r O u t ;  
     p S o u r c e - > G e t P o i n t e r (   & p B u f f e r I n   ) ;  
     p D e s t - > G e t P o i n t e r (   & p B u f f e r O u t   ) ;  
  
     l o n g   c b B y t e   =   0 ;  
  
 	 i f (   m _ p S u b t i t l e   = =   N U L L   )  
 	 {  
 	 	 m _ N e x t S u b t i t l e P T S   =   0 ;  
  
 	 	 m _ p S u b t i t l e 	 =   m _ p S u b D e c o d e r - > G e t S u b t i t l e (   0   ) ;  
 	 	 i f (   m _ p S u b t i t l e   )  
 	 	 {  
 	 	 	 m _ c u r S u b t i t l e P T S   =   m _ p S u b t i t l e - > P T S ( ) ;  
 	 	 	 i f (   m _ P T S d i f f   = =   0   )  
 	 	 	 {  
 	 	 	 	 L o g ( " f i r s t   s u b t i t l e   f r o m   d e c o d e r   (   m _ c u r S u b t i t l e P T S :   % l l d   -   m _ f i r s t P T S :   % l l d   )   -   % l l d " ,   m _ c u r S u b t i t l e P T S ,   m _ f i r s t P T S ,   m _ c u r S u b t i t l e P T S   -   m _ f i r s t P T S   ) ;  
 	 	 	 	 / / m _ P T S d i f f   =   m _ c u r S u b t i t l e P T S   -   m _ f i r s t P T S ;  
 	 	 	 }  
 	 	 }  
  
 	 	 C S u b t i t l e *   p N e x t S u b t i t l e   =   m _ p S u b D e c o d e r - > G e t S u b t i t l e (   1   ) ;  
 	 	 i f (   p N e x t S u b t i t l e   )  
 	 	 {  
 	 	 	 m _ N e x t S u b t i t l e P T S   =   p N e x t S u b t i t l e - > P T S ( ) ;  
 	 	 }  
 	 	 P T S T i m e   c u r ;  
 	 	 P T S T o P T S T i m e ( m _ c u r S u b t i t l e P T S , & c u r ) ;  
 	 	 L o g ( " C u r r e n t   P T S :   % l l d   % d : % 0 2 d : % 0 2 d : % 0 3 d " ,   m _ c u r S u b t i t l e P T S , c u r . h , c u r . m , c u r . s , c u r . u ) ;  
 	 	 i f (   m _ c u r S u b t i t l e P T S   >   0   )  
 	 	 {  
 	 	 	 m _ c u r S u b t i t l e P T S   + =   s u b D e l a y ;       / / 2 8 8 0 0 0 ;  
 	 	 }  
 	 	 / / P T S T o P T S T i m e ( m _ c u r S u b t i t l e P T S , & c u r ) ;  
 	 	 / / L o g ( " C u r r e n t   P T S   f i x e d :   % l l d   % d : % 0 2 d : % 0 2 d : % 0 3 d " ,   m _ c u r S u b t i t l e P T S , c u r . h , c u r . m , c u r . s , c u r . u ) ;  
  
 	 	 i f (   m _ N e x t S u b t i t l e P T S   >   0   )  
 	 	 {  
 	 	 	 m _ N e x t S u b t i t l e P T S   + =   s u b D e l a y ;     / / 2 8 8 0 0 0 ;  
 	 	 }  
 	 }  
  
 	 / /   C h e c k   s u b t i t l e   s t a t u s  
 	 i f (   m _ p S u b t i t l e   )  
 	 {  
 	 	 / /   U p d a t e   S u b t i t l e   b i t m a p   d a t a  
 	 	 i f (   m _ b S u b t i t l e D i s c a r d e d   )  
 	 	 {  
 	 	 	 m _ b S u b t i t l e D i s c a r d e d   =   f a l s e ;  
 	 	 	 S t r e t c h S u b t i t l e ( ) ;  
 	 	 }  
  
 	 	 L o g ( " c u r P T S   &   s u b P T S   -   % l l d   % l l d " ,   m _ c u r P T S ,   m _ c u r S u b t i t l e P T S   ) ;  
  
 	 	 / / i f (   (   m _ c u r S u b t i t l e P T S   > =   m _ c u r P T S   )   & &   (   m _ c u r S u b t i t l e P T S   +   m _ S h o w D u r a t i o n   )   < =   m _ c u r P T S   )  
 	 	 i f (   m _ c u r P T S   > =   m _ c u r S u b t i t l e P T S   )  
 	 	 {  
 	 	 	 L o g ( " D i s p l a y   s u b t i t l e ! " ) ;  
 	 	 	 m _ b R e n d e r C u r r e n t S u b t i t l e   =   t r u e ;  
 	 	 }  
 	 	 e l s e  
 	 	 {  
 	 	 	 m _ b R e n d e r C u r r e n t S u b t i t l e   =   f a l s e ;  
 	 	 }  
  
 	 	 b o o l   b D i s c a r d S u b t i t l e   =   f a l s e ;  
  
 	 	 i f (   (   m _ c u r S u b t i t l e P T S   +   m _ S h o w D u r a t i o n   )   <   m _ c u r P T S   )  
 	 	 {  
 	 	 	 L o g ( " S u b t i t l e   h a s   b e e n   s h o w n   e n o u g h ! " ) ;  
 	 	 	 b D i s c a r d S u b t i t l e   =   t r u e ;  
 	 	 }  
  
 	 	 i f (   (   m _ N e x t S u b t i t l e P T S   >   0   )   & &   (   m _ N e x t S u b t i t l e P T S   <   m _ c u r P T S   )   )  
 	 	 {  
 	 	 	 L o g ( " N e x t   s u b t i t l e   i n c o m i n g ! " ) ;  
 	 	 	 b D i s c a r d S u b t i t l e   =   t r u e ;  
 	 	 }  
  
 	 	 / /   S u b t i t l e   c a n   b e   d i s c a r d e d  
 	 	 i f (   b D i s c a r d S u b t i t l e   & &  
 	 	 	 ! m _ b S u b t i t l e D i s c a r d e d   & &  
 	 	 	 (   m _ p S u b t i t l e   ! =   N U L L   )   )  
 	 	 {  
 	 	 	 L o g ( " T i m e   t o   d i s c a r d   t h e   c u r r e n t   s u b t i t l e   ! " ) ;  
 	 	 	 m _ b S u b t i t l e D i s c a r d e d   =   t r u e ;  
 	 	 	 m _ b R e n d e r C u r r e n t S u b t i t l e   =   f a l s e ;  
 	 	 	 m _ p S u b D e c o d e r - > R e l e a s e O l d e s t S u b t i t l e ( ) ;  
 	 	 	 m _ p S u b t i t l e 	 =   N U L L ;  
 	 	 }  
 	 }  
  
 	 / /   R e n d e r   s u b t i t l e s   &   v i d e o  
 	 i f   (   m _ V i h O u t . b m i H e a d e r . b i C o m p r e s s i o n   = =   f c c U Y V Y   )  
         {  
                 h r   =   P r o c e s s F r a m e U Y V Y (   p B u f f e r I n ,   p B u f f e r O u t ,   & c b B y t e   ) ;  
         }  
         e l s e   i f   ( m _ V i h O u t . b m i H e a d e r . b i C o m p r e s s i o n   = =   f c c Y U Y 2   )  
         {  
                 h r   =   P r o c e s s F r a m e Y U Y 2 (   p B u f f e r I n ,   p B u f f e r O u t ,   & c b B y t e   ) ;  
         }  
         e l s e  
         {  
                 r e t u r n   E _ U N E X P E C T E D ;  
         }  
  
         / /   S e t   t h e   s i z e   o f   t h e   d e s t i n a t i o n   i m a g e .  
         A S S E R T (   p D e s t - > G e t S i z e ( )   > =   c b B y t e   ) ;  
  
         p D e s t - > S e t A c t u a l D a t a L e n g t h (   c b B y t e   ) ;  
  
         r e t u r n   h r ;  
 }  
  
 v o i d   C S u b T r a n s f o r m : : G e t V i d e o I n f o P a r a m e t e r s (  
         c o n s t   V I D E O I N F O H E A D E R   * p v i h ,  
         B Y T E     *   c o n s t   p b D a t a ,  
         D W O R D   * p d w W i d t h ,  
         D W O R D   * p d w H e i g h t ,  
         L O N G     * p l S t r i d e I n B y t e s ,  
         B Y T E   * * p p b T o p ,  
         b o o l   b Y u v  
         )  
 {  
     L O N G   l S t r i d e ;  
  
     / /     F o r   ' n o r m a l '   f o r m a t s ,   b i W i d t h   i s   i n   p i x e l s .  
     / /     E x p a n d   t o   b y t e s   a n d   r o u n d   u p   t o   a   m u l t i p l e   o f   4 .  
     i f   ( p v i h - > b m i H e a d e r . b i B i t C o u n t   ! =   0   & &  
             0   = =   ( 7   &   p v i h - > b m i H e a d e r . b i B i t C o u n t ) )  
     {  
         l S t r i d e   =   ( p v i h - > b m i H e a d e r . b i W i d t h   *   (   p v i h - > b m i H e a d e r . b i B i t C o u n t   /   8 )   +   3   )   &   ~ 3 ;  
     }  
     e l s e       / /   O t h e r w i s e ,   b i W i d t h   i s   i n   b y t e s .  
     {  
         l S t r i d e   =   p v i h - > b m i H e a d e r . b i W i d t h ;  
     }  
  
     / /     I f   r c T a r g e t   i s   e m p t y ,   u s e   t h e   w h o l e   i m a g e .  
     i f   ( I s R e c t E m p t y ( & p v i h - > r c T a r g e t ) )  
     {  
         * p d w W i d t h   =   ( D W O R D ) p v i h - > b m i H e a d e r . b i W i d t h ;  
         * p d w H e i g h t   =   ( D W O R D ) ( a b s ( p v i h - > b m i H e a d e r . b i H e i g h t ) ) ;  
  
         i f   ( p v i h - > b m i H e a d e r . b i H e i g h t   <   0   | |   b Y u v )       / /   T o p - d o w n   b i t m a p  
         {  
             * p l S t r i d e I n B y t e s   =   l S t r i d e ;   / /   S t r i d e   g o e s   " d o w n "  
             * p p b T o p                       =   p b D a t a ;   / /   T o p   r o w   i s   f i r s t  
         }  
         e l s e     / /   B o t t o m - u p   b i t m a p  
         {  
             * p l S t r i d e I n B y t e s   =   - l S t r i d e ;                                         / /   S t r i d e   g o e s   " u p "  
             * p p b T o p   =   p b D a t a   +   l S t r i d e   *   (   * p d w H e i g h t   -   1   ) ; / /   B o t t o m   r o w   i s   f i r s t  
         }  
     }  
     e l s e       / /   r c T a r g e t   i s   N O T   e m p t y .   U s e   a   s u b - r e c t a n g l e   i n   t h e   i m a g e .  
     {  
         * p d w W i d t h   =   ( D W O R D ) (   p v i h - > r c T a r g e t . r i g h t   -   p v i h - > r c T a r g e t . l e f t )   ;  
         * p d w H e i g h t   =   ( D W O R D ) (   p v i h - > r c T a r g e t . b o t t o m   -   p v i h - > r c T a r g e t . t o p   ) ;  
  
         i f   ( p v i h - > b m i H e a d e r . b i H e i g h t   <   0   | |   b Y u v )       / /   T o p - d o w n   b i t m a p  
         {  
             / /   S a m e   s t r i d e   a s   a b o v e ,   b u t   f i r s t   p i x e l   i s   m o d i f i e d   d o w n  
             / /   a n d   o v e r   b y   t h e   t a r g e t   r e c t a n g l e .  
             * p l S t r i d e I n B y t e s   =   l S t r i d e ;  
             * p p b T o p   =   p b D a t a   +   l S t r i d e   *   p v i h - > r c T a r g e t . t o p   +  
                 ( p v i h - > b m i H e a d e r . b i B i t C o u n t   *   p v i h - > r c T a r g e t . l e f t )   /   8 ;  
         }  
         e l s e     / /   B o t t o m - u p   b i t m a p  
         {  
             * p l S t r i d e I n B y t e s   =   - l S t r i d e ;  
             * p p b T o p   =   p b D a t a   +   l S t r i d e   *   (   p v i h - > b m i H e a d e r . b i H e i g h t   -  
                 p v i h - > r c T a r g e t . t o p   -   1   )   +   (   p v i h - > b m i H e a d e r . b i B i t C o u n t   *   p v i h - > r c T a r g e t . l e f t   )   /   8 ;  
         }  
     }  
 }  
  
 b o o l   C S u b T r a n s f o r m : : I s V a l i d U Y V Y (   c o n s t   C M e d i a T y p e   * p m t   )  
 {  
 	 i f (   p m t - > f o r m a t t y p e   ! =   F O R M A T _ V i d e o I n f o   )  
 	 	 r e t u r n   f a l s e ;  
  
 	 i f ( 	 p m t - > m a j o r t y p e   ! =   M E D I A T Y P E _ V i d e o   )  
 	 	 r e t u r n   f a l s e ;  
  
 	 i f (   p m t - > s u b t y p e   ! =   M E D I A S U B T Y P E _ U Y V Y   )  
 	 	 r e t u r n   f a l s e ;  
  
 	 r e t u r n   t r u e ;  
 }  
  
 b o o l   C S u b T r a n s f o r m : : I s V a l i d Y U Y 2 (   c o n s t   C M e d i a T y p e   * p m t   )  
 {  
 	 i f (   p m t - > f o r m a t t y p e   ! =   F O R M A T _ V i d e o I n f o   )  
 	 	 r e t u r n   f a l s e ;  
  
 	 i f ( 	 p m t - > m a j o r t y p e   ! =   M E D I A T Y P E _ V i d e o   )  
 	 	 r e t u r n   f a l s e ;  
  
 	 i f (   p m t - > s u b t y p e   ! =   M E D I A S U B T Y P E _ Y U Y 2   )  
 	 	 r e t u r n   f a l s e ;  
  
 	 r e t u r n   t r u e ;  
 }  
  
  
 v o i d   C S u b T r a n s f o r m : : S e t P c r P i d (   L O N G   p i d   )  
 {  
     m _ p P c r P i n - > S e t P c r P i d (   p i d   ) ;  
 }  
  
  
 v o i d   C S u b T r a n s f o r m : : S e t S u b t i t l e P i d (   L O N G   p i d   )  
 {  
     m _ p S u b t i t l e P i n - > S e t S u b t i t l e P i d (   p i d   ) ;  
 }  
  
 v o i d   C S u b T r a n s f o r m : : R e s e t ( )  
 {  
 	 C A u t o L o c k   c O b j e c t L o c k (   m _ p L o c k   ) ;  
  
 	 m _ p S u b D e c o d e r - > R e s e t ( ) ;  
 	 m _ p S u b t i t l e   =   N U L L ; 	 / /   N U L L   t h e   l o c a l   p o i n t e r ,   a s   c a c h e   i s   d e l e t e d  
  
 	 m _ p S u b t i t l e P i n - > R e s e t ( ) ;  
     m _ p P c r P i n - > R e s e t ( ) ;  
  
 	 m _ N e x t S u b t i t l e P T S =   0 ;  
 	 m _ c u r S u b t i t l e P T S   =   0 ;  
 	 m _ c u r P T S   =   0 ;  
 	 m _ f i r s t P T S   =   0 ;  
 	 m _ P T S d i f f   =   0 ;  
 	 m _ f i r s t P T S D o n e   =   f a l s e ;  
 	 m _ b R e n d e r C u r r e n t S u b t i t l e   =   f a l s e ;  
 	 m _ b S u b t i t l e D i s c a r d e d   =   t r u e ;  
 }  
  
 H R E S U L T   C S u b T r a n s f o r m : : B e g i n F l u s h (   v o i d   )  
 {  
 / / 	 R e s e t ( ) ;  
 	 r e t u r n   C T r a n s f o r m F i l t e r : : B e g i n F l u s h ( ) ;  
 }  
 H R E S U L T   C S u b T r a n s f o r m : : E n d F l u s h (   v o i d   )  
 {  
 	 R e s e t ( ) ;  
 	 r e t u r n   C T r a n s f o r m F i l t e r : : E n d F l u s h ( ) ;  
 }  
  
 v o i d   C S u b T r a n s f o r m : : N o t i f y ( )  
 {  
 / / 	 C r e a t e   a   f a k e   P T S  
 / / 	 C S u b t i t l e *   s u b t i t l e   =   m _ p S u b D e c o d e r - > G e t L a t e s t S u b t i t l e ( ) ;  
 / / 	 s u b t i t l e - > S e t P T S (   m _ p r e v i o u s F r a m e T S   +   9 0 0 0 0 0   ) ;   / /   +   9 0 0 0 0 0 * 2 5 * 5   ) ;  
 / / 	 L o g (   " f a k e   P T S   -   % l l d   " ,   s u b t i t l e - > P T S ( )   ) ;  
 }  
  
 / /  
 / /   I n t e r f a c e   m e t h o d s  
 / /  
 S T D M E T H O D I M P   C S u b T r a n s f o r m : : S e t S u b t i t l e P i d (   U L O N G   p P i d   )  
 {  
 	 i f (   m _ p S u b t i t l e P i n   )  
 	 {  
 	 	 m _ p S u b t i t l e P i n - > S e t S u b t i t l e P i d (   p P i d   ) ;  
 	 }  
  
 	 r e t u r n   S _ O K ;  
 }  
  
 S T D M E T H O D I M P   C S u b T r a n s f o r m : : S e t P c r P i d (   U L O N G   p P i d   )  
 {  
 	 i f (   m _ p P c r P i n   )  
 	 {  
 	 	 m _ p P c r P i n - > S e t P c r P i d (   p P i d   ) ;  
 	 }  
  
 	 r e t u r n   S _ O K ;  
 }  
  
 / /  
 / /   C r e a t e I n s t a n c e  
 / /  
 C U n k n o w n   *   W I N A P I   C S u b T r a n s f o r m : : C r e a t e I n s t a n c e (   L P U N K N O W N   p u n k ,   H R E S U L T   * p h r   )  
 {  
     A S S E R T (   p h r   ) ;  
  
     C S u b T r a n s f o r m   * p F i l t e r   =   n e w   C S u b T r a n s f o r m (   p u n k ,   p h r   ) ;  
     i f (   p F i l t e r   = =   N U L L   )  
     {  
         i f   ( p h r )  
         {  
             * p h r   =   E _ O U T O F M E M O R Y ;  
         }  
     }  
     r e t u r n   p F i l t e r ;  
 }  
  
 v o i d   C S u b T r a n s f o r m : : S t r e t c h S u b t i t l e ( )  
 {  
 	 i n t   i R e t ;  
 	 i n t   i W i d t h , i H e i g h t ;  
 	 L O G F O N T   L o g F o n t ;  
 	 H F O N T   f o n z i ;  
 	 P T S T i m e   p c r , n e x t , c u r ;  
  
 	 i f   ( m _ D i b s S u b   = =   N U L L )  
 	 {  
 	 	 B I T M A P I N F O   b m i ;  
 	 	 Z e r o M e m o r y ( & b m i , s i z e o f ( B I T M A P I N F O ) ) ;  
 	 	 b m i . b m i H e a d e r . b i B i t C o u n t   =   2 4 ;  
 	 	 b m i . b m i H e a d e r . b i H e i g h t   =   m _ V i h I n . b m i H e a d e r . b i H e i g h t ;  
 	 	 b m i . b m i H e a d e r . b i W i d t h   =   m _ V i h I n . b m i H e a d e r . b i W i d t h ;  
 	 	 b m i . b m i H e a d e r . b i S i z e I m a g e   =   m _ V i h I n . b m i H e a d e r . b i W i d t h   *   a b s ( m _ V i h I n . b m i H e a d e r . b i H e i g h t )   *   3 ;  
 	 	 b m i . b m i H e a d e r . b i P l a n e s     =   1 ;  
 	 	 b m i . b m i H e a d e r . b i C o m p r e s s i o n 	 =   B I _ R G B ;  
 	 	 b m i . b m i H e a d e r . b i S i z e   =   s i z e o f ( b m i ) ;  
         i f   ( b m i . b m i H e a d e r . b i H e i g h t > 0 )  
 	 	 {  
 	 	 	 b m i . b m i H e a d e r . b i H e i g h t   =   - 1 * b m i . b m i H e a d e r . b i H e i g h t ;  
 	 	 }  
 	 	 m _ D i b s S u b   =   C r e a t e D I B S e c t i o n (  
 	 	 	 	 	 	 	 	 	 N U L L ,  
 	 	 	 	 	 	 	 	 	 ( B I T M A P I N F O * )   & b m i ,  
 	 	 	 	 	 	 	 	 	 D I B _ R G B _ C O L O R S ,  
 	 	 	 	 	 	 	 	 	 & m _ p D i b B i t s ,  
 	 	 	 	 	 	 	 	 	 N U L L ,  
 	 	 	 	 	 	 	 	 	 0  
 	 	 	 	 	 	 	 	 	 ) ;  
  
 	 	 H D C   h d c   =   G e t D C (   N U L L   ) ;  
 	 	 A S S E R T ( h d c   ! =   0 ) ;  
 	 	 m _ D C   =   C r e a t e C o m p a t i b l e D C (   h d c   ) ;  
 	 	 R e l e a s e D C (   N U L L ,   h d c   ) ;  
 	 	 m _ O l d O b j e c t   =   S e l e c t O b j e c t (   m _ D C ,   m _ D i b s S u b   ) ;  
 	 }  
  
 	 B I T M A P I N F O   b m i S r c ;  
 	 m e m s e t ( & b m i S r c ,   0 ,   s i z e o f ( b m i S r c ) ) ;  
 	 b m i S r c . b m i H e a d e r . b i S i z e 	 	 	 	         =   s i z e o f ( B I T M A P I N F O H E A D E R ) ;  
     b m i S r c . b m i H e a d e r . b i W i d t h 	 	 	         =   7 2 0 ;  
     b m i S r c . b m i H e a d e r . b i H e i g h t 	 	 	         =   - 5 7 6 ;  
     b m i S r c . b m i H e a d e r . b i P l a n e s 	 	 	         =   1 ;  
 	 b m i S r c . b m i H e a d e r . b i B i t C o u n t 	 	 	     =   2 4 ;  
     b m i S r c . b m i H e a d e r . b i C o m p r e s s i o n 	 	 =   B I _ R G B ;  
 	 b m i S r c . b m i H e a d e r . b i S i z e I m a g e 	 	     =   ( ( m _ p S u b t i t l e - > m _ B i t m a p . b m W i d t h   *   m _ p S u b t i t l e - > m _ B i t m a p . b m B i t s P i x e l   +   3 1 )   &   ( ~ 3 1 ) )   /   8   *   m _ p S u b t i t l e - > m _ B i t m a p . b m H e i g h t ;  
 	 b m i S r c . b m i H e a d e r . b i X P e l s P e r M e t e r 	 =   0 ;  
 	 b m i S r c . b m i H e a d e r . b i Y P e l s P e r M e t e r 	 =   0 ;  
 	 b m i S r c . b m i H e a d e r . b i C l r I m p o r t a n t 	 	 =   0 ;  
 	 b m i S r c . b m i H e a d e r . b i C l r U s e d 	 	 	     =   0 ;  
  
 	 i W i d t h     =   m _ V i h I n . b m i H e a d e r . b i W i d t h ;  
     i H e i g h t   =   a b s ( m _ V i h I n . b m i H e a d e r . b i H e i g h t ) ;  
  
 	 B Y T E   * l p B i t s   =   n e w   B Y T E [   7 2 0 * 5 7 6 * 3   ] ;  
  
 	 m e m c p y ( l p B i t s , m _ p S u b t i t l e - > G e t D a t a ( ) , 7 2 0 * 5 7 6 * 3 ) ;  
  
 	 i R e t   =   S t r e t c h D I B i t s ( m _ D C ,  
                                                 / /   d e s t i n a t i o n   r e c t a n g l e  
 	 	 	 	 	 	                         0 ,   0 ,   i W i d t h ,   i H e i g h t ,  
                                                 / /   s o u r c e   r e c t a n g l e  
                                                 0 ,   0 ,   7 2 0 ,   5 7 6 ,  
                                                 ( v o i d   * )   l p B i t s ,  
                                                 & b m i S r c ,  
                                                 D I B _ R G B _ C O L O R S ,  
 	 	 	 	 	 	                         S R C C O P Y ) ;  
  
  
 	 S e t T e x t C o l o r ( m _ D C ,   R G B ( 1 2 8 , 1 2 8 , 1 9 2 ) ) ;  
 	 S e t B k C o l o r ( m _ D C ,   R G B ( 1 2 8 , 1 2 8 , 0 ) ) ;  
  
 	 C H A R   s z F o n t N a m e [ 3 2 ]   =   " M S   S a n s   s e r i f " ;  
  
 	 L o g F o n t . l f S t r i k e O u t   =   0 ;  
     L o g F o n t . l f U n d e r l i n e   =   0 ;  
 	 L o g F o n t . l f W e i g h t   =   F W _ B O L D ;  
     L o g F o n t . l f H e i g h t   =   2 2 ;  
     L o g F o n t . l f E s c a p e m e n t   =   0 ;  
     L o g F o n t . l f I t a l i c   =   F A L S E ;  
 	 ( v o i d )   S t r i n g C c h C o p y ( ( c h a r   * ) L o g F o n t . l f F a c e N a m e , 3 2 , ( c h a r   * ) s z F o n t N a m e ) ;  
 	 f o n z i   =   C r e a t e F o n t I n d i r e c t ( & L o g F o n t ) ;  
 	 S e l e c t O b j e c t ( m _ D C , f o n z i ) ;  
  
 	 T C H A R   s z T e x t [ 2 5 6 ] ;  
  
 	 P T S T o P T S T i m e ( m _ c u r P T S , & p c r ) ;  
 	 P T S T o P T S T i m e ( m _ c u r S u b t i t l e P T S , & c u r ) ;  
 	 P T S T o P T S T i m e ( m _ N e x t S u b t i t l e P T S , & n e x t ) ;  
 	 ( v o i d ) S t r i n g C c h P r i n t f (   s z T e x t ,   N U M E L M S ( s z T e x t ) ,   T E X T ( " P c r :   % d : % 0 2 d : % 0 2 d : % 0 3 d   C u r :   % d : % 0 2 d : % 0 2 d : % 0 3 d   N e x t :   % d : % 0 2 d : % 0 2 d : % 0 3 d " ) ,   p c r . h , p c r . m , p c r . s , p c r . u , c u r . h , c u r . m , c u r . s , c u r . u , n e x t . h , n e x t . m , n e x t . s , n e x t . u ) ;  
     B O O L   b W o r k e d   =   T e x t O u t (   m _ D C ,   1 0 ,   1 0 ,   s z T e x t ,   _ t c s l e n (   s z T e x t   )   ) ;  
  
     i f   ( i R e t   = =   G D I _ E R R O R )   L o g ( " S t r e c t c h D I B i t s   f a i l e d " ) ;  
 	 e l s e   {  
 	 	 G e t B i t m a p B i t s (   m _ D i b s S u b ,   i W i d t h   *   a b s ( i H e i g h t ) * 3 ,   m _ p D i b B i t s   ) ;  
 	 	 m e m c p y (   m _ c u r S u b t i t l e D a t a ,   m _ p D i b B i t s ,   i W i d t h   *   i H e i g h t   *   3   ) ;  
 	 	 Z e r o M e m o r y (   m _ p D i b B i t s ,   i W i d t h   *   i H e i g h t   *   3   ) ;  
 	 }  
 }  
  
 v o i d   C S u b T r a n s f o r m : : P T S T o P T S T i m e (   U L O N G L O N G   p t s ,   P T S T i m e *   p t s T i m e   )  
 {  
 	 P T S T i m e   t i m e ;  
 	 U L O N G     _ 9 0 k h z   =   p t s / 9 0 ;  
 	 t i m e . h = ( _ 9 0 k h z / ( 1 0 0 0 * 6 0 * 6 0 ) ) ;  
 	 t i m e . m = ( _ 9 0 k h z / ( 1 0 0 0 * 6 0 ) ) - ( t i m e . h * 6 0 ) ;  
 	 t i m e . s = ( _ 9 0 k h z / 1 0 0 0 ) - ( t i m e . h * 3 6 0 0 ) - ( t i m e . m * 6 0 ) ;  
 	 t i m e . u = _ 9 0 k h z - ( t i m e . h * 1 0 0 0 * 6 0 * 6 0 ) - ( t i m e . m * 1 0 0 0 * 6 0 ) - ( t i m e . s * 1 0 0 0 ) ;  
 	 * p t s T i m e = t i m e ;  
 }  
 