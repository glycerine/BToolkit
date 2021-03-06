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

#include <sys/types.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/signal.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/utsname.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <limits.h>
#include <fcntl.h>
#include <netdb.h>
#include <syslog.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#ifndef LOCK_EX
#define LOCK_EX 2
#endif /* LOCK_EX - exclusive lock */

#ifndef LOCK_NB
#define LOCK_NB 4
#endif /* LOCK_NB - Don't block when locking */



extern char * Rename_SharedSocketServerP1[];
extern int Rename_SharedSocketServerP2;
extern int Rename_SharedSocketServerP3;

extern char * _out_buf;
extern long int _out_buf_size;
extern long int _out_buf_ptr;

extern char * _in_buf;
extern long int _in_buf_size;
extern long int _in_buf_ptr;
extern long int _in_buf_len;

extern int _num_sav;
extern char _sav_buf [];
extern long int _sav_buf_ptr;

extern char * malloc_buf;
extern long int malloc_buf_len;
extern long int malloc_buf_ptr;
extern long int malloc_done;

#define INI_Rename_SharedSocketServer()   { _out_buf_ptr = 4; _in_buf_ptr = 4; }

void Rename_INIT ( int * _rep, void * _lockfile, int _port , void * _bufsavefile );
void Rename_ACCEPT ( int * _rep );
void Rename_READ ( int * _rep, int * _pp );
void Rename_WRITE ( int * _rep );
void Rename_CLOSE ( int * _rep );
void Rename_GET_TOK ( int * _tok, int _toksize );
void Rename_GET_STR ( int * _ss );
void Rename_PUT_TOK ( int _tok, int _toksize );
void Rename_PUT_STR ( int * _ss );
void Rename_SET_IN_PTR ( int _ptr );
void Rename_GET_IN_PTR ( int * _ptr );
void Rename_SET_OUT_PTR ( int _ptr );
void Rename_GET_OUT_PTR ( int * _ptr );
void Rename_GET_OUT_SIZE ( int * _sz );
void Rename_PUT_FILE ( int * _rep, void * _filename );
void Rename_SAV_BUF ( int * _rep, int * _num_saves );
void Rename_SAV_RMV ( void );
void Rename_RST_BUF ( int * _rep );
void Rename_NXT_BUF ( int * _rep );
