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

#include "Rename_Bit_String.h"


void
#ifdef _BT_ANSIC
Rename_VMS_BTS( int *s, int b, int m, int n )
#else
Rename_VMS_BTS( s, b, m, n )
int *s, b, m, n;
#endif
{
	int i,v;
	i = n-m+1;
	v = 0;
	while( i>0 ){
		v = 2*v+1;
		i = i-1;
	};
	*(s) = ((b&(v<<(32-n)))>>(32-n));
}


void
#ifdef _BT_ANSIC
Rename_MMS_BTS( int *s, int b, int m, int n, int w )
#else
Rename_MMS_BTS( s, b, m, n, w )
int *s, b, m, n, w;
#endif
{
	int i,v;
	i = n-m+1;
	v = 0;
	while( i>0 ){
		v = 2*v+1;
		i = i-1;
	};
	*(s) = (~(v<<(32-n))&b)|((w&v)<<(32-n));
}



void
#ifdef _BT_ANSIC
Rename_VAL_BTS( int *s, int b, int n)
#else
Rename_VAL_BTS( s, b, n)
int *s, b, n;
#endif
{
	Rename_VMS_BTS(s,b,n,n);
}

void
#ifdef _BT_ANSIC
Rename_STO_BTS( int *s, int b, int n, int w )
#else
Rename_STO_BTS( s, b, n, w )
int *s, b, n;
#endif
{
	Rename_MMS_BTS(s,b,n,n,w);
}

