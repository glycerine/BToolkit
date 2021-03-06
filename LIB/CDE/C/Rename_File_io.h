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

#include <stdio.h>

extern FILE *Rename_File_io_ptr;


#define INI_Rename_File_io()  { ; }

#define Rename_OPEN_READ(rep,filename) \
  { *rep = ( ( Rename_File_io_ptr = fopen ( ( char * ) filename, "r" ) ) != NULL ); }

#define Rename_OPEN_WRITE(rep,filename) \
  { *rep = ( ( Rename_File_io_ptr = fopen ( ( char * )filename, "w" ) ) != NULL ); }

#define Rename_OPEN_APPEND(rep,filename) \
  { *rep = ( ( Rename_File_io_ptr = fopen ( ( char * )filename, "a" ) ) != NULL ); }

#define Rename_CLOSE(rep) \
  { *rep = ( ( fclose ( Rename_File_io_ptr ) ) == 0 ); }

#define Rename_PUT_STR(rep,ss) \
  { *rep = ( ( fprintf ( Rename_File_io_ptr, "%s", ( char * ) ss ) ) == strlen ( ( char * ) ss ) ); }

#define Rename_PUT_CHAR(rep,cc) \
  { *rep = ( ( fprintf ( Rename_File_io_ptr, "%c", ( char ) cc ) ) != 0 ); }

#define Rename_PUT_NAT(rep,nn) \
  { *rep = ( ( fprintf ( Rename_File_io_ptr, "%d", ( int ) nn ) ) != 0 ); }

#define Rename_PUT_TOK(rep,tt) Rename_PUT_NAT(rep,tt)

#define Rename_GET_STR(rep,ss) \
  { *rep = ( ( fgets ( (char *) ss, 250, Rename_File_io_ptr ) != NULL ) ); }

#define Rename_GET_CHAR(rep,cc) \
  { *rep = ( ( *cc = getc ( Rename_File_io_ptr ) ) != EOF ); }

#define Rename_GET_NAT(rep,nn) \
  { *rep = ( ( *nn = getw ( Rename_File_io_ptr ) ) != EOF ); }

#define Rename_GET_TOK(rep,tt)  Rename_GET_NAT(rep,nn)

#define Rename_PUT_NWL(rep,nn) \
  { int i = nn; *rep = 1; while ( *rep && i ) \
   { Rename_PUT_CHAR ( rep, '\n' ); i--; } }

#define Rename_PUT_BLK(rep,nn) \
  { int i = nn; *rep = 1; while ( *rep && i ) \
   { Rename_PUT_CHAR (rep, ' ' ); i--; } }

#define Rename_FLUSH(rep) \
  { *rep = ( ( fflush ( Rename_File_io_ptr ) ) == 0 ); }
