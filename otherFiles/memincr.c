/*====================================================================*
 *
 *   signed memincr (void * memory, size_t  extent);
 *
 *   memory.h
 *
 *   increment a multi-byte_t memory region; start at 0x00 and reset
 *   at 0xFF; return -1 if all bytes are 0xFF;
 *
 *   for example,
 *
 *      0x00 0x00 0x00 --> 0x00 0x00 0x01
 *      0xFF 0x00 0xFF --> 0xFF 0x01 0x00
 *
 *   Motley Tools by Charles Maier;
 *   Copyright (c) 2001-2006 by Charles Maier Associates;
 *   Licensed under the Internet Software Consortium License;
 *
 *--------------------------------------------------------------------*/
#ifndef MEMINCR_SOURCE
#define MEMINCR_SOURCE
#include "../tools/memory.h"
signed memincr (uint8_t * memory, uint32_t extent) {
  register byte_t * offset = (byte_t *)(memory);
  while (--extent)
  {
    offset[extent]++;
    if (offset[extent] != 0x00)
    {
      return (0);
    }
  }
  return (-1);
}
#endif
