/*
 * Copyright (C) 2007-2018 Siemens AG
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

 /*******************************************************************
  *
  * @author Daniel.Peintner.EXT@siemens.com
  * @version 2017-03-02
  * @contact Richard.Kuntschke@siemens.com
  *
  * <p>Code generated by EXIdizer</p>
  * <p>Schema: V2G_CI_MsgDef.xsd</p>
  *
  *
  ********************************************************************/



#include "BitInputStream.h"
#include "EXIConfig.h"
#include "EXITypes.h"
#include "ErrorCodes.h"

#ifndef BIT_INPUT_STREAM_C
#define BIT_INPUT_STREAM_C

  /* internal method to (re)fill buffer */
static int readBuffer(bitstream_t* stream) {
	int errn = 0;
	if (stream->capacity == 0) {
#if EXI_STREAM == BYTE_ARRAY
		if ((stream->pos) < stream->size) {
			stream->buffer = stream->data[(stream->pos)++];
			stream->capacity = BITS_IN_BYTE;
		}
		else {
			errn = EXI_ERROR_INPUT_STREAM_EOF;
		}
#endif
#if EXI_STREAM == FILE_STREAM
		stream->buffer = (uint8_t)(getc(stream->file));
		/* EOF cannot be used, 0xFF valid value */
		if (feof(stream->file) || ferror(stream->file)) {
			errn = EXI_ERROR_INPUT_STREAM_EOF;
		}
		else {
			stream->capacity = BITS_IN_BYTE;
		}
#endif
	}
	return errn;
}

int readBits(bitstream_t* stream, size_t num_bits, uint32_t* b) {
	int errn = readBuffer(stream);
	if (errn == 0) {
		/* read the bits in one step */
		if (num_bits <= stream->capacity) {
			stream->capacity = (uint8_t)(stream->capacity - num_bits);
			*b = (uint32_t)((stream->buffer >> stream->capacity) & (0xff >> (BITS_IN_BYTE - num_bits)));
		}
		else {
			/* read bits as much as possible */
			*b = (uint32_t)(stream->buffer & (0xff >> (BITS_IN_BYTE - stream->capacity)));
			num_bits = (num_bits - stream->capacity);
			stream->capacity = 0;

			/* read whole bytes */
			while (errn == 0 && num_bits >= 8) {
				errn = readBuffer(stream);
				*b = ((*b) << BITS_IN_BYTE) | stream->buffer;
				num_bits = (num_bits - BITS_IN_BYTE);
				stream->capacity = 0;
			}

			/* read the spare bits in the buffer */
			if (errn == 0 && num_bits > 0) {
				errn = readBuffer(stream);
				if (errn == 0) {
					*b = ((*b) << num_bits) | (uint8_t)(stream->buffer >> (BITS_IN_BYTE - num_bits));
					stream->capacity = (uint8_t)(BITS_IN_BYTE - num_bits);
				}
			}
		}
	}

	return errn;
}

#endif
