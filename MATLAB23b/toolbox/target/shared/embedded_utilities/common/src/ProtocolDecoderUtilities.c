#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "ProtocolDecoderUtilities.h"

static enum DecodingStatesTag decodingState = WaitForHeader;

uint8_T readPacket(uint8_T *inData, uint16_T inDataLen,
                   uint8_T *header,
                   uint8_T headerLen,
                   uint8_T *terminator,
                   uint8_T terminatorLen,
                   uint8_T isVariableSize,
                   uint16_T minPacketLen,
                   uint16_T maxPacketLen,
                   uint8_T *dataBuffer,
                   uint8_T *payload,
                   uint16_T *payloadLength)
{
    // Read the latest packet based on size, header and terminator.
    // Size can be fixed or variable. Terminator is optional for fixed size packet
    // payload will contains the decoded packet whose size can be determined by payloadLength
    // Function return 0 if no packet is available;
    static uint16_T dataBufferIndex = 0;
    static uint8_T numTerminatorBytesReceived = 0;
    static uint8_T numHeaderBytesReceived = 0;
    uint8_T presentChar = 0;
    uint8_T status = 0;
    uint16_T inputDataIndex = 0;
    // exit if storage queue is empty
    while (inputDataIndex < inDataLen)
    {
        presentChar = inData[inputDataIndex];
        inputDataIndex++;
        switch (decodingState)
        {
         // Look for header. Header can be multibytes.
        case WaitForHeader:
            //If complete header found
            if (header[numHeaderBytesReceived] == presentChar)
            {
                numHeaderBytesReceived++;
                if (numHeaderBytesReceived == headerLen)
                {
                    numHeaderBytesReceived = 0;
                    numTerminatorBytesReceived = 0;
                    dataBufferIndex = 0;
                    if (minPacketLen == 0 )
                    {
                       // For packet with no fixed size fields are available, directly look for terminator
                       decodingState = WaitForVariableLengthDataAndTerminator;
                    }
                    else
                    {
                       // For packet with atleast one fixed size field is available, wait for the fixed size data size
                       decodingState = WaitForMinimumData;
                    }    
                }
            }
            // Check whether the present char is the first char of the pattern. For the case like
            // header = 12, incoming byte stream = 112
            else if (header[0] == presentChar)
            {
                numHeaderBytesReceived = 1;
            }
            else
            {
                numHeaderBytesReceived = 0;
            }
            break;
            
            // Wait for minimum amount of data.Variable size packet can have fixed size entries as well.
            // For variable size packet, length of fixed size fields will be the minimum data length required
            // For Fixed size packet, MinPayloadSize = MaxPayloadSize   
        case WaitForMinimumData:
            // store bytes into buffer, till the required data size is found
            if (dataBufferIndex < minPacketLen)
            {
                dataBuffer[dataBufferIndex] = presentChar;
                dataBufferIndex++;
            }
            if (dataBufferIndex == minPacketLen)
            {
                // If no terminator is required , copy the required bytes, reset the states and continue
                if (terminatorLen == 0)
                {
                    *payloadLength = dataBufferIndex;
                    memcpy(payload, dataBuffer, (*payloadLength) * sizeof(uint8_T));
                    numTerminatorBytesReceived = 0;
                    numHeaderBytesReceived = 0;
                    dataBufferIndex = 0;
                    decodingState = WaitForHeader;
                    status = 1;
                }
                else
                {
                    decodingState = WaitForVariableLengthDataAndTerminator;
                }
            }
            break;

        case WaitForVariableLengthDataAndTerminator:
            // For fixed size packet, terminator bytes are expected right after the expected data
            if (isVariableSize == 0)
            {
                // Check if a terminator byte received
                if (terminator[numTerminatorBytesReceived] == presentChar)
                {
                    numTerminatorBytesReceived++;
                    if (numTerminatorBytesReceived == terminatorLen)
                    {
                        *payloadLength = dataBufferIndex;
                        memcpy(payload, dataBuffer, (*payloadLength) * sizeof(uint8_T));
                        numTerminatorBytesReceived = 0;
                        numHeaderBytesReceived = 0;
                        decodingState = WaitForHeader;
                        dataBufferIndex = 0;
                        status = 1;
                    }
                }
                else
                {
                    // Invalid packet, reset the states and start again
                    numTerminatorBytesReceived = 0;
                    numHeaderBytesReceived = 0;
                    decodingState = WaitForHeader;
                    dataBufferIndex = 0;
                    // Keep the same input same for next iteration since this might be start
                    // of header of next packet
                    inputDataIndex--;
                }
            }
            else
            // For variable size packets
            {
                // Partial terminator bytes can be part of packet as well.
                // Store the terminator bytes as well in the buffer
                dataBuffer[dataBufferIndex] = presentChar;
                dataBufferIndex++;
                // Check if a terminator byte recieved
                if (terminator[numTerminatorBytesReceived] == presentChar)
                {
                     numTerminatorBytesReceived++;
                    // Check if all terminator bytes are recieved
                    if (numTerminatorBytesReceived == terminatorLen)
                    {
                        *payloadLength = dataBufferIndex - terminatorLen;
                        memcpy(payload, dataBuffer, (*payloadLength) * sizeof(uint8_T));
                        numTerminatorBytesReceived = 0;
                        numHeaderBytesReceived = 0;
                        decodingState = WaitForHeader;
                        dataBufferIndex = 0;
                        status = 1;
                    }
                }
                // Check whether the present char is the first char of the pattern. For the case like
                // terminator = 12, incoming byte stream = 112
                else if (terminator[0] == presentChar)
                {
                    numTerminatorBytesReceived = 1;
                }
                else
                {
                    numTerminatorBytesReceived = 0;
                }
                // If no terminator is found within the limit,reset the states
                // For example, maxPacketSize = 2, termintor is *%
                // Input stream is abc or ab*#
                if ((dataBufferIndex > maxPacketLen) && (numTerminatorBytesReceived != dataBufferIndex - maxPacketLen))
                {
                    // Invalid packet, reset the states and start again
                    numTerminatorBytesReceived = 0;
                    numHeaderBytesReceived = 0;
                    decodingState = WaitForHeader;
                    dataBufferIndex = 0;
                    // Keep the same input same for next iteration since this might be start
                    // of header of next packet
                    inputDataIndex--;
                }
            }
            break;
        }
    }
    return status;
}

uint8_T parseCSV(uint8_T *payload, uint16_T payloadLen,
                 uint8_T startIdx, uint16_T expectedLen,
                 uint8_T *commaSeperateVariable, uint16_T *actualLen, uint16_T *commaIdx)
{
    uint8_T comma = 44; //ASCII for comma
    uint16_T idx = startIdx;
    *actualLen = 0;
    // Look for data between startIdx and commas in the payload and
    // store the length between startIdx and comma in len
    while (idx < payloadLen)
    {
        if (payload[idx] == comma)
        {
            // For the cases with consecutive comma and no data in
            // between (e.g GPS with no fix)
            if (idx == startIdx)
            {
                *actualLen = 0;
            }
            else if ((idx - startIdx) < expectedLen)
            {
                *actualLen = idx - startIdx;
                memcpy(commaSeperateVariable, &payload[startIdx], *actualLen);
            }
            else
            {
                // If the datasize exceeds the maximum output
                // length, truncuate the data and give it out
                *actualLen = idx - startIdx;
                memcpy(commaSeperateVariable, &payload[startIdx], expectedLen);
            }
            *commaIdx = idx;
            return 1;
        }
        else
        {
            idx++;
        }
    }
    // if there is comma found, take the end of packet as the delimter
    //If there is no data after startIdx
    if ((payloadLen - startIdx) < expectedLen)
    {
        *actualLen = payloadLen - startIdx;
        memcpy(commaSeperateVariable, &payload[startIdx], *actualLen);
    }
    else
    {
        *actualLen = payloadLen - startIdx;
        memcpy(commaSeperateVariable, &payload[startIdx], expectedLen);
    }
    *commaIdx = payloadLen;
    return 1;
}
