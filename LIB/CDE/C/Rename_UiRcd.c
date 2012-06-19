/* Copyright (c) 1985-2012, B-Core (UK) Ltd
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in
   the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT 
NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
extern int Rename_UiRcdP1;
extern int Rename_UiRcdP2;
extern int Rename_UiRcdP3;

extern int Rename_UiRcd_ARR_UiArrP1;
extern int Rename_UiRcd_ARR_UiArrP2;
extern int Rename_UiRcd_ARR_UiArrP3;

extern int Rename_UiRcd_ARR[];

extern int Rename_UiRcd_HEAP_ARR_UiArrP1;
extern int Rename_UiRcd_HEAP_ARR_UiArrP2;
extern int Rename_UiRcd_HEAP_ARR_UiArrP3;

extern int Rename_UiRcd_HEAP_ARR[];

extern int Rename_UiRcd_TOT;

INI_Rename_UiRcd()
{
  {} ;
  {} ;
  Rename_UiRcd_TOT = 0 ;
  {
    int ii;
    ii = 0;
    while( ii<Rename_UiRcdP3 ){
      Rename_UiRcd_HEAP_ARR[ ii ] =  ii  ;
      *( &ii ) = ( ii )+1 ;
    };
    Rename_UiRcd_TOT =  0  ;
  }
}

Rename_UiRcd_RST()
{
  int ii;
  ii = 0;
  while( ii<Rename_UiRcdP3 ){
    Rename_UiRcd_HEAP_ARR[ ii ] =  ii  ;
    *( &ii ) = ( ii )+1 ;
  };
  Rename_UiRcd_TOT =  0  ;
}

/* ANSIC header */
Rename_UiRcd_IDX(int *bb, int idx)
/* end ANSIC header */

/* non-ANSIC header */
Rename_UiRcd_IDX(bb,idx)
int *bb,idx;
/* end non-ANSIC header */
{
  if( idx<=Rename_UiRcdP2 ){
    *bb = 1 ;
  } else {
    *bb = 0 ;
  }
}

/* ANSIC header */
Rename_UiRcd_FULL(int *bb)
/* end ANSIC header */

/* non-ANSIC header */
Rename_UiRcd_FULL(bb)
int *bb;
/* end non-ANSIC header */
{
  int vv;
  *( &vv ) = Rename_UiRcd_TOT ;
  if( vv == Rename_UiRcdP3 ){
    *bb = 1 ;
  } else {
    *bb = 0 ;
  }
}

/* ANSIC header */
Rename_UiRcd_CRE(int *rr)
/* end ANSIC header */

/* non-ANSIC header */
Rename_UiRcd_CRE(rr)
int *rr;
/* end non-ANSIC header */
{
  int ii,ss;
  *( &ii ) = Rename_UiRcd_TOT ;
  *( &ss ) = Rename_UiRcd_HEAP_ARR[ ii ] ;
  *( rr ) = ( ss )+1 ;
  Rename_UiRcd_TOT = Rename_UiRcd_TOT+1 ;
}

/* ANSIC header */
Rename_UiRcd_KILL(int rr)
/* end ANSIC header */

/* non-ANSIC header */
Rename_UiRcd_KILL(rr)
int rr;
/* end non-ANSIC header */
{
  int ii,ss;
  Rename_UiRcd_TOT = Rename_UiRcd_TOT-1 ;
  *( &ss ) = ( rr )-1 ;
  *( &ii ) = Rename_UiRcd_TOT ;
  Rename_UiRcd_HEAP_ARR[ ii ] =  ss  ;
}

/* ANSIC header */
Rename_UiRcd_VLD(int *bb, int rr)
/* end ANSIC header */

/* non-ANSIC header */
Rename_UiRcd_VLD(bb,rr)
int *bb,rr;
/* end non-ANSIC header */
{
  int tt,ii,aa,ss;
  *( &tt ) = Rename_UiRcd_TOT ;
  aa = 1 ;
  ii = Rename_UiRcdP3;
  while( aa == 1  && ii>tt ){
    *( &ii ) = ( ii )-1 ;
    *( &ss ) = Rename_UiRcd_HEAP_ARR[ ii ] ;
    *( &ss ) = ( ss )+1 ;
    if( rr == ss ){
      aa = 0 ;
    }
  };
  *bb = aa;
}

/* ANSIC header */
Rename_UiRcd_STO(int rr, int idx, int vv)
/* end ANSIC header */

/* non-ANSIC header */
Rename_UiRcd_STO(rr,idx,vv)
int rr,idx,vv;
/* end non-ANSIC header */
{
  int jj,kk;
  *( &jj ) = ( rr )-1 ;
  *( &kk ) = ( idx )-1 ;
  *( &jj ) = ( jj )*( Rename_UiRcdP2 ) ;
  *( &jj ) = ( jj )+( kk ) ;
  Rename_UiRcd_ARR[ jj ] =  vv  ;
}

/* ANSIC header */
Rename_UiRcd_VAL(int *vv, int rr, int idx)
/* end ANSIC header */

/* non-ANSIC header */
Rename_UiRcd_VAL(vv,rr,idx)
int *vv,rr,idx;
/* end non-ANSIC header */
{
  int jj,kk;
  *( &jj ) = ( rr )-1 ;
  *( &kk ) = ( idx )-1 ;
  *( &jj ) = ( jj )*( Rename_UiRcdP2 ) ;
  *( &jj ) = ( jj )+( kk ) ;
  *( vv ) = Rename_UiRcd_ARR[ jj ] ;
}
