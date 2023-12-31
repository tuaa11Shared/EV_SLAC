/*====================================================================*
 *
 *   Copyright (c) 2013 Qualcomm Atheros, Inc.
 *
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted (subject to the limitations
 *   in the disclaimer below) provided that the following conditions
 *   are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials
 *     provided with the distribution.
 *
 *   * Neither the name of Qualcomm Atheros nor the names of
 *     its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written
 *     permission.
 *
 *   NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
 *   GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE
 *   COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 *   IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *   PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 *   OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *   NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 *   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *--------------------------------------------------------------------*/
/*====================================================================*
 *
 *   signed EthernetHeader (void * memory, const uint8_t peer [], const uint8_t host [], uint16_t protocol);
 *
 *   mme.h
 *
 *   encode a memory region with a standard Ethernet frame header in
 *   network byte_t order;
 *
 *
 *   Contributor(s):
 *  Charles Maier
 *
 *--------------------------------------------------------------------*/
#ifndef ETHERNETHEADER_SOURCE
#define ETHERNETHEADER_SOURCE
#include <stdint.h>
#include <memory.h>
#include <string.h>
#include "../mme/mme.h"
signed EthernetHeader (void * memory, const uint8_t peer [], const uint8_t host [], uint16_t protocol)
{
  // fill ethernet frame header part
  struct ether_header * header = (struct ether_header *)(memory);
  // destination
  memcpy (header->ether_dhost, peer, sizeof (header->ether_dhost));
  // source
  memcpy (header->ether_shost, host, sizeof (header->ether_shost));
  // type of upper layer data 0x0800(IPV4), 0x0806(ARP), ...
  header->ether_type = htons (protocol);
  return (sizeof (* header));
}
#endif
