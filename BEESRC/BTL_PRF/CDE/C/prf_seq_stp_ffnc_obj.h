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
extern int prf_seq_stp_ffnc_objP2;
extern int prf_seq_stp_ffnc_objP3;
extern int prf_seq_stp_fnc_obj[];
extern int prf_seq_stp_ssize_fnc_obj;
extern int prf_seq_stp_old_fnc_obj[];
extern int prf_seq_stp_sold_fnc_obj;

char prf_seq_stp_buf_ffnc_obj[1000];

#define prf_seq_stp_CHARperWORD 4

#define INI_prf_seq_stp_ffnc_obj() \
{prf_seq_stp_ssize_fnc_obj = 0; prf_seq_stp_sold_fnc_obj=0;}

#define prf_seq_stp_INI_FNC_OBJ() \
{prf_seq_stp_ssize_fnc_obj = 0; prf_seq_stp_sold_fnc_obj=0;}

#define prf_seq_stp_ANY_FNC_OBJ(vv) \
{*(vv) = 1;}

#define prf_seq_stp_TST_FLD_FNC_OBJ(bb,pp) \
{ *(bb) = ( ( (pp>0) && (pp<=prf_seq_stp_ffnc_objP2) )!=0) ;}



#define prf_seq_stp_FUL_FNC_OBJ(bb) \
{*(bb) = (((prf_seq_stp_ssize_fnc_obj - prf_seq_stp_sold_fnc_obj) == prf_seq_stp_ffnc_objP3)!=0);}

#define prf_seq_stp_DEF_FNC_OBJ(bb,ff,ii) \
{*(bb) = (prf_seq_stp_fnc_obj[(ff-1)*prf_seq_stp_ffnc_objP2+ii] != 2147483647)!=0;}

#define prf_seq_stp_VAL_FNC_OBJ(vv,ff,ii) \
{*(vv) = prf_seq_stp_fnc_obj[(ff-1)*prf_seq_stp_ffnc_objP2+ii];}

#define prf_seq_stp_STO_FNC_OBJ(ff,ii,vv) \
{prf_seq_stp_fnc_obj[(ff-1)*prf_seq_stp_ffnc_objP2+(ii)] = (vv);}

#define prf_seq_stp_RMV_FNC_OBJ(ff,ii) \
{prf_seq_stp_fnc_obj[(ff-1)*prf_seq_stp_ffnc_objP2+ii] = 2147483647;}

#define prf_seq_stp_KIL_FNC_OBJ(ff) \
{prf_seq_stp_sold_fnc_obj=prf_seq_stp_sold_fnc_obj+1; \
prf_seq_stp_old_fnc_obj[prf_seq_stp_sold_fnc_obj]=ff;}





