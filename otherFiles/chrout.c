/*====================================================================*
 *
 *   void chrout (void const * memory, size_t extent, char c, char e, FILE * fp)
 *
 *   memory.h
 *
 *   print memory as an ASCII character string; replace non-printable
 *   characters with (c) on output; terminate output with (e);
 *
 *   Motley Tools by Charles Maier;
 *   Copyright (c) 2001-2006 by Charles Maier Associates;
 *   Licensed under the Internet Software Consortium License;
 *
 *--------------------------------------------------------------------*/
#ifndef CHROUT_SOURCE
#define CHROUT_SOURCE
#include <stdio.h>
#include <ctype.h>
#include "../tools/memory.h"
void chrout (void const * memory, size_t extent, char c, char e, FILE * fp)
{
  byte_t * offset = (byte_t *)(memory);
  while (extent--)
  {
    putc (isprint (* offset)? * offset: c, fp);
    offset++;
  }
  if (e)
  {
    putc (e, fp);
  }
  return;
}
#endif
