/*====================================================================*
 *
 *   void memout (void const  * memory, size_t extent, char const * format, unsigned group, char c, char e, FILE * fp)
 *
 *   memory.h
 *
 *   print memory as a series of octets formatted by format string fmt,
 *   seperated by character c every mod prints;
 *
 *   for example, memout (memory, IPv4_LEN, "%d", 1, '.', stdout) would print:
 *
 *      192.168.1.1
 *
 *   another example, memout (memory, IPv6_LEN, "%02x", 2, ':', stdout) would print:
 *
 *     0032:0045:0000:0000:0000:0000:1123:4456
 *
 *   Motley Tools by Charles Maier;
 *   Copyright (c) 2001-2006 by Charles Maier Associates;
 *   Licensed under the Internet Software Consortium License;
 *
 *   Contributor(s):
 *  Nathaniel Houghton
 *
 *--------------------------------------------------------------------*/
#ifndef MEMOUT_SOURCE
#define MEMOUT_SOURCE
#include <stdio.h>
#include <stddef.h>
#include "../tools/memory.h"
void memout (void const * memory, size_t extent, char const * format, unsigned group, char c, char e, FILE * fp)
{
  byte_t * origin = (byte_t *) (memory);
  byte_t * offset = (byte_t *) (memory);
  while (extent--)
  {
    ptrdiff_t count = (offset - origin) + 1;
    fprintf (fp, format, * offset);
    if ((count % group) == 0 && extent)
    {
      putc (c, fp);
    }
    offset++;
  }
  if (e)
  {
    putc (c, fp);
  }
  return;
}
#endif
