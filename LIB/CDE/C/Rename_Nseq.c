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

#include "Rename_Nseq.h"

#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>

extern FILE *dump_file;

#define convert_arr_htonl(a,i,n) \
  j = i; \
  k = 0; \
  while ( k < n ) { \
    a [ j ] = htonl ( a [ j ] ); \
    j++; \
    k++; \
  }

#define convert_arr_ntohl(a,i,n) \
  j = i; \
  k = 0; \
  while ( k < n ) { \
    a [ j ] = ntohl ( a [ j ] ); \
    j++; \
    k++; \
  }

#define  write_fm(a,b)    fwrite(&a,sizeof(int),b,dump_file)

void
Rename_SAV_NSEQ()
{
	write_fm(Rename_Nsize,1);
	write_fm(Rename_Nseq[1],Rename_Nsize);
}

void
Rename_SAVN_NSEQ()
{
        int j, k;
	Rename_Nsize = htonl ( Rename_Nsize );
	write_fm(Rename_Nsize,1);
	Rename_Nsize = ntohl ( Rename_Nsize );

	convert_arr_htonl(Rename_Nseq,1,Rename_Nsize);
	write_fm(Rename_Nseq[1],Rename_Nsize);
	convert_arr_ntohl(Rename_Nseq,1,Rename_Nsize);
}


#define  read_fm(a,b)    fread(&a,sizeof(int),b,dump_file)

void
Rename_RST_NSEQ()
{
	read_fm(Rename_Nsize,1);
	read_fm(Rename_Nseq[1],Rename_Nsize);
}

void
Rename_RSTN_NSEQ()
{
        int j, k;
	read_fm(Rename_Nsize,1);
	Rename_Nsize = ntohl ( Rename_Nsize );

	read_fm(Rename_Nseq[1],Rename_Nsize);
	convert_arr_ntohl(Rename_Nseq,1,Rename_Nsize);
}


void
Rename_TAL_NSEQ()
{
	int i;
	i = 2;
	while( i<=Rename_Nsize ){
		Rename_Nseq[i-1] = Rename_Nseq[i];
		i = i+1
		    ;
	};
	Rename_Nsize = Rename_Nsize-1;
}


void
#ifdef _BT_ANSIC
Rename_CUT_NSEQ( int ii )
#else
Rename_CUT_NSEQ( ii )
int ii;
#endif
{
	int i;
	i = ii+1;
	while( i<=Rename_Nsize ){
		Rename_Nseq[i-ii] = Rename_Nseq[i];
		i = i+1
		    ;
	};
	Rename_Nsize = Rename_Nsize-ii;
}


void
#ifdef _BT_ANSIC
Rename_SWP_NSEQ( int ii, int jj )
#else
Rename_SWP_NSEQ( ii, jj )
int ii, jj;
#endif
{
	int i;
	i=Rename_Nseq[ii];
	Rename_Nseq[ii]=Rename_Nseq[jj];
	Rename_Nseq[jj]=i;
}


void
#ifdef _BT_ANSIC
Rename_MAX_IDX_NSEQ( int *vv, int ii, int jj )
#else
Rename_MAX_IDX_NSEQ( vv, ii, jj )
int* vv;
int ii, jj;
#endif
{
	int x,t,k;
	x=ii;
	t=0;
	k=ii;
	while( x<=jj ){
		if( Rename_Nseq[x]>=t ){
			t=Rename_Nseq[x];
			k=x;
		};
		x=x+1;
	};
	*(vv)=k;
}


void
#ifdef _BT_ANSIC
Rename_MIN_IDX_NSEQ( int *vv, int ii, int jj )
#else
Rename_MIN_IDX_NSEQ( vv, ii, jj )
int* vv;
int ii, jj;
#endif
{
	int x,t,k;
	x=ii;
	k=ii;
	t=Rename_NseqP1;
	while( x<=jj ){
		if( Rename_Nseq[x]<=t ){
			t=Rename_Nseq[x];
			k=x;
		};
		x=x+1;
	};
	*(vv)=k;
}


void
#ifdef _BT_ANSIC
Rename_SCH_LO_EQL_NSEQ( int *bb, int *ii, int jj, int kk, int vv )
#else
Rename_SCH_LO_EQL_NSEQ( bb, ii, jj, kk, vv )
int *bb;
int *ii;
int jj, kk, vv;
#endif
{
	int r,y;
	r=jj;
	y=kk+1;
	while( y!=r ){
		if( Rename_Nseq[r] == vv ){
			y=r;
		} else{
			r=r+1;
		};
	}
	*(bb)=((r!=kk+1)!=0);
	*(ii)=r;
}


void
#ifdef _BT_ANSIC
Rename_SCH_LO_NEQ_NSEQ( int *bb, int *ii, int jj, int kk, int vv )
#else
Rename_SCH_LO_NEQ_NSEQ( bb, ii, jj, kk, vv )
int *bb;
int *ii;
int jj, kk, vv;
#endif
{
	int r,y;
	r=jj;
	y=kk+1;
	while( y!=r ){
		if( Rename_Nseq[r] != vv ){
			y=r;
		} else{
			r=r+1;
		};
	}
	*(bb)=((r!=kk+1)!=0);
	*(ii)=r;
}


void
#ifdef _BT_ANSIC
Rename_SCH_LO_GEQ_NSEQ( int *bb, int *ii, int jj, int kk, int vv )
#else
Rename_SCH_LO_GEQ_NSEQ( bb, ii, jj, kk, vv )
int *bb;
int *ii;
int jj, kk, vv;
#endif
{
	int r,y;
	r=jj;
	y=kk+1;
	while( y!=r ){
		if( Rename_Nseq[r] >= vv ){
			y=r;
		} else{
			r=r+1;
		};
	}
	*(bb)=((r!=kk+1)!=0);
	*(ii)=r;
}


void
#ifdef _BT_ANSIC
Rename_SCH_LO_GTR_NSEQ( int *bb, int *ii, int jj, int kk, int vv )
#else
Rename_SCH_LO_GTR_NSEQ( bb, ii, jj, kk, vv )
int *bb;
int *ii;
int jj, kk, vv;
#endif
{
	int r,y;
	r=jj;
	y=kk+1;
	while( y!=r ){
		if( Rename_Nseq[r] > vv ){
			y=r;
		} else{
			r=r+1;
		};
	}
	*(bb)=((r!=kk+1)!=0);
	*(ii)=r;
}


void
#ifdef _BT_ANSIC
Rename_SCH_LO_LEQ_NSEQ( int *bb, int *ii, int jj, int kk, int vv )
#else
Rename_SCH_LO_LEQ_NSEQ( bb, ii, jj, kk, vv )
int *bb;
int *ii;
int jj, kk, vv;
#endif
{
	int r,y;
	r=jj;
	y=kk+1;
	while( y!=r ){
		if( Rename_Nseq[r] <= vv ){
			y=r;
		} else{
			r=r+1;
		};
	}
	*(bb)=((r!=kk+1)!=0);
	*(ii)=r;
}


void
#ifdef _BT_ANSIC
Rename_SCH_LO_SMR_NSEQ( int *bb, int *ii, int jj, int kk, int vv )
#else
Rename_SCH_LO_SMR_NSEQ( bb, ii, jj, kk, vv )
int *bb;
int *ii;
int jj, kk, vv;
#endif
{
	int r,y;
	r=jj;
	y=kk+1;
	while( y!=r ){
		if( Rename_Nseq[r] < vv ){
			y=r;
		} else{
			r=r+1;
		};
	}
	*(bb)=((r!=kk+1)!=0);
	*(ii)=r;
}


void
#ifdef _BT_ANSIC
Rename_SCH_HI_EQL_NSEQ( int *bb, int *ii, int jj, int kk, int vv )
#else
Rename_SCH_HI_EQL_NSEQ( bb, ii, jj, kk, vv )
int *bb;
int *ii;
int jj, kk, vv;
#endif
{
	int r,y;
	r=kk;
	y=jj-1;
	while( y!=r ){
		if( Rename_Nseq[r] == vv ){
			y=r;
		} else{
			r=r-1;
		};
	}
	*(bb)=((r!=jj-1)!=0);
	*(ii)=r;
}


void
#ifdef _BT_ANSIC
Rename_SCH_HI_NEQ_NSEQ( int *bb, int *ii, int jj, int kk, int vv )
#else
Rename_SCH_HI_NEQ_NSEQ( bb, ii, jj, kk, vv )
int *bb;
int *ii;
int jj, kk, vv;
#endif
{
	int r,y;
	r=kk;
	y=jj-1;
	while( y!=r ){
		if( Rename_Nseq[r] != vv ){
			y=r;
		} else{
			r=r-1;
		};
	}
	*(bb)=((r!=jj-1)!=0);
	*(ii)=r;
}


void
#ifdef _BT_ANSIC
Rename_SCH_HI_GEQ_NSEQ( int *bb, int *ii, int jj, int kk, int vv )
#else
Rename_SCH_HI_GEQ_NSEQ( bb, ii, jj, kk, vv )
int *bb;
int *ii;
int jj, kk, vv;
#endif
{
	int r,y;
	r=kk;
	y=jj-1;
	while( y!=r ){
		if( Rename_Nseq[r] >= vv ){
			y=r;
		} else{
			r=r-1;
		};
	}
	*(bb)=((r!=jj-1)!=0);
	*(ii)=r;
}


void
#ifdef _BT_ANSIC
Rename_SCH_HI_GTR_NSEQ( int *bb, int *ii, int jj, int kk, int vv )
#else
Rename_SCH_HI_GTR_NSEQ( bb, ii, jj, kk, vv )
int *bb;
int *ii;
int jj, kk, vv;
#endif
{
	int r,y;
	r=kk;
	y=jj-1;
	while( y!=r ){
		if( Rename_Nseq[r] > vv ){
			y=r;
		} else{
			r=r-1;
		};
	}
	*(bb)=((r!=jj-1)!=0);
	*(ii)=r;
}


void
#ifdef _BT_ANSIC
Rename_SCH_HI_LEQ_NSEQ( int *bb, int *ii, int jj, int kk, int vv )
#else
Rename_SCH_HI_LEQ_NSEQ( bb, ii, jj, kk, vv )
int *bb;
int *ii;
int jj, kk, vv;
#endif
{
	int r,y;
	r=kk;
	y=jj-1;
	while( y!=r ){
		if( Rename_Nseq[r] <= vv ){
			y=r;
		} else{
			r=r-1;
		};
	}
	*(bb)=((r!=jj-1)!=0);
	*(ii)=r;
}


void
#ifdef _BT_ANSIC
Rename_SCH_HI_SMR_NSEQ( int *bb, int *ii, int jj, int kk, int vv )
#else
Rename_SCH_HI_SMR_NSEQ( bb, ii, jj, kk, vv )
int *bb;
int *ii;
int jj, kk, vv;
#endif
{
	int r,y;
	r=kk;
	y=jj-1;
	while( y!=r ){
		if( Rename_Nseq[r] < vv ){
			y=r;
		} else{
			r=r-1;
		};
	}
	*(bb)=((r!=jj-1)!=0);
	*(ii)=r;
}


void
#ifdef _BT_ANSIC
Rename_SRT_ASC_NSEQ( int ii, int jj )
#else
Rename_SRT_ASC_NSEQ( ii, jj )
int ii, jj;
#endif
{
	int i,j;
	i=ii;
	while( i<jj ){
		Rename_MIN_IDX_NSEQ(&j,i,jj);
		Rename_SWP_NSEQ(i,j);
		i=i+1;
	};
}


void
#ifdef _BT_ANSIC
Rename_SRT_DSC_NSEQ( int ii, int jj )
#else
Rename_SRT_DSC_NSEQ( ii, jj )
int ii, jj;
#endif
{
	int i,j;
	i=ii;
	while( i<jj ){
		Rename_MAX_IDX_NSEQ(&j,i,jj);
		Rename_SWP_NSEQ(i,j);
		i=i+1;
	};
}


void
#ifdef _BT_ANSIC
Rename_REV_NSEQ( int ii, int jj )
#else
Rename_REV_NSEQ( ii, jj )
int ii, jj;
#endif
{
	int i,j;
	i=ii;
	j=jj;
	while( i<j ){
		Rename_SWP_NSEQ(i,j);
		i=i+1;
		j=j-1;
	};
}


void
#ifdef _BT_ANSIC
Rename_RHT_NSEQ( int ii, int jj, int nn )
#else
Rename_RHT_NSEQ( ii, jj, nn )
int ii, jj, nn;
#endif
{
	int k,n;
	n=jj-ii+1;
	k=0;
	while( k<n ){
		if( jj+nn-k<=Rename_NseqP2 ){
			Rename_Nseq[jj+nn-k]=Rename_Nseq[jj-k];
		}
		k=k+1;
	};
}


void
#ifdef _BT_ANSIC
Rename_LFT_NSEQ( int ii, int jj, int nn )
#else
Rename_LFT_NSEQ( ii, jj, nn )
int ii, jj, nn;
#endif
{
	int k,n;
	n=jj-ii+1;
	k=0;
	while( k<n ){
		if( ii-nn+k>=1 ){
			Rename_Nseq[ii-nn+k]=Rename_Nseq[ii+k];
		}
		k=k+1;
	};
}
