/*Copyright (c) 1985-2012, B-Core (UK) Ltd

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "Rename_BiArrO.h"

#include "Rename_C_UiArr.h"
#include "Rename_M_Byt.h"
#include "Rename_O_BiArr.h"

#include "Bool_TYPE.h"
#include "PASP_TYPE.h"

INI_Rename_BArrO()
{
  INI_Rename_C_UiArr();
  INI_Rename_M_Byt();
  INI_Rename_O_BiArr();
}

Rename_BiAO_OBJ_FUL(bb)
int *bb;
{
  int obj;
  Rename_M_VAL(&obj);
  if( obj == Rename_BiArrOP1 ){
    *bb = TRUE;
  } else {
    *bb = FALSE;
  }
}

Rename_BiAO_XST(bb,pp)
int *bb,pp;
{
  int tok,xx,yy;
  Rename_M_VAL(&tok);
  BNE(&xx,0,tok);
  BLE(&yy,pp,tok);
  if( xx == TRUE && yy == TRUE ){
    *bb = TRUE;
  } else {
    *bb = FALSE;
  }
}

Rename_BiAO_INI()
{
  Rename_M_STO(0);
}

Rename_BiAO_CRE(bb,pp)
int *bb,*pp;
{
  int tt,tok;
  Rename_M_VAL(&tt);
  if( tt!=Rename_BiArrOP1 ){
    BINC(&tok,tt);
    Rename_M_STO(tok);
    Rename_O_STO(tok,Rename_lb);
    *pp = tok;
    *bb = TRUE;
  } else {
    *bb = FALSE;
    *pp = 0;
  }
}

Rename_BiAO_VAL(vv,pp,ii)
int *vv,pp,ii;
{
  int seg,idx;
  BDEC(&seg,pp);
  UMUL(&idx,seg,Rename_BiArrOP2);
  UADD(&idx,idx,ii);
  Rename_C_VAL(vv,idx);
}

Rename_BiAO_NXT(nn,pp)
int *nn,pp;
{
  Rename_O_VAL(nn,pp);
}

Rename_BiAO_EQL(bb,ss,tt)
int *bb,ss,tt;
{
  int idx,offset,seg,top,xidx,xoffset,xseg,v1,v2,pp,qq;
  BDEC(&seg,ss);
  UMUL(&offset,Rename_BiArrOP2,seg);
  UINC(&idx,offset);
  UADD(&top,offset,Rename_BiArrOP2);
  BDEC(&xseg,tt);
  UMUL(&xoffset,Rename_BiArrOP2,xseg);
  UINC(&xidx,xoffset);
  pp = TRUE;
  while( pp == TRUE ){
    Rename_C_VAL(&v1,idx);
    Rename_C_VAL(&v2,xidx);
    UINC(&idx,idx);
    UINC(&xidx,xidx);
    ULE(&pp,idx,top);
    BEQ(&qq,v1,v2);
    if( pp == TRUE && qq == TRUE ){
      pp = TRUE;
    } else {
      pp = FALSE;
    }
  };
  Rename_O_STO(ss,Rename_lb);
  Rename_O_STO(tt,Rename_lb);
  *bb = qq;
}

Rename_BiAO_STO(pp,ii,vv)
int pp,ii,vv;
{
  int nx,offset,seg,index;
  BDEC(&seg,pp);
  UMUL(&offset,Rename_BiArrOP2,seg);
  UADD(&index,offset,ii);
  Rename_C_STO(index,vv);
  UINC(&nx,ii);
  if( nx<Rename_BiArrOP2 ){
    Rename_O_STO(pp,nx);
  }else{
    Rename_O_STO(pp,Rename_lb);
  }
}

Rename_BiAO_STO_NXT(pp,vv)
int pp,vv;
{
  int nx,offset,seg,index,ii;
  BDEC(&seg,pp);
  UMUL(&offset,Rename_BiArrOP2,seg);
  Rename_O_VAL(&ii,pp);
  UADD(&index,offset,ii);
  Rename_C_STO(index,vv);
  UINC(&nx,ii);
  if( nx<Rename_BiArrOP2 ){
    Rename_O_STO(pp,nx);
  }else{
    Rename_O_STO(pp,Rename_lb);
  }
}

Rename_BiAO_CPY(pp,qq)
int pp,qq;
{
  int idx,offset,seg,top,xidx,xoffset,xseg,vv;
  BDEC(&seg,pp);
  UMUL(&offset,Rename_BiArrOP2,seg);
  UINC(&idx,offset);
  UADD(&top,offset,Rename_BiArrOP2);
  BDEC(&xseg,qq);
  UMUL(&xoffset,Rename_BiArrOP2,xseg);
  UINC(&xidx,xoffset);
  while( idx<=top ){
    Rename_C_VAL(&vv,idx);
    Rename_C_STO(xidx,vv);
    UINC(&idx,idx);
    UINC(&xidx,xidx);
  };
  Rename_O_STO(pp,Rename_lb);
  Rename_O_STO(qq,Rename_lb);
}

Rename_BiAO_FILL(pp,vv)
int pp,vv;
{
  int idx,offset,seg,top;
  BDEC(&seg,pp);
  UMUL(&offset,Rename_BiArrOP2,seg);
  UINC(&idx,offset);
  UADD(&top,offset,Rename_BiArrOP2);
  while( idx<=top ){
    Rename_C_STO(idx,vv);
    UINC(&idx,idx);
  };
  Rename_O_STO(pp,Rename_lb);
}

