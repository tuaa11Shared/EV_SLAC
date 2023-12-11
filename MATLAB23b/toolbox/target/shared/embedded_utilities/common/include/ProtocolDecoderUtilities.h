/**
 * @file ProtocolDecoderUtilities.h
 *
 * Header file for ProtocolDecoderUtilities.c
 *
 * @Copyright 2021-2022 The MathWorks, Inc.
 *
 */
#ifndef __PROTOCOLDECODER__
#define __PROTOCOLDECODER__

#ifdef __cplusplus
extern "C" {
#endif

enum DecodingStatesTag
{
    WaitForHeader,
    WaitForMinimumData,
    WaitForVariableLengthDataAndTerminator
};

uint8_T readPacket(uint8_T *inData,uint16_T inDataLen,
        uint8_T *header,
        uint8_T headerLen,
        uint8_T *terminator,
        uint8_T terminatorLen,
        uint8_T isVariableSize,
        uint16_T minPacketLen,
        uint16_T maxPacketLen,
        uint8_T *dataBuffer,
        uint8_T *payload,
        uint16_T *payloadLength);

uint8_T parseCSV(uint8_T *payload, 
              uint16_T payloadLen,
              uint8_T startIdx,
              uint16_T expectedLen,
              uint8_T *commaSeperateVariable, 
              uint16_T *actualLen,
              uint16_T *commaIdx);

#ifdef __cplusplus
}
#endif

#endif



