/* Copyright 2012-2015 The MathWorks, Inc. */
#ifndef _MW_ALSA_AUDIO_H_
#define _MW_ALSA_AUDIO_H_
#include "rtwtypes.h"
#ifdef __cplusplus
extern "C"
{
#endif

#if defined(ARM_PROJECT)
extern void audioPlaybackInit(
        const uint8_T *device,
        const uint32_T sampleRate,
        const real_T queueDuration,
        const uint32_T frameSize);
extern void audioCaptureInit(
        const uint8_T *device,
        const uint32_T sampleRate,
        const real_T queueDuration,
        const uint32_T frameSize);
extern void audioCapture(const uint8_T *device, int16_T *outData, const uint32_T frameSize);
extern void audioPlayback(const uint8_T *device, int16_T *inData, const uint32_T frameSize);
extern void audioCaptureTerminate(const uint8_T *device);
extern void audioPlaybackTerminate(const uint8_T *device);
#else /* !defined(ARM_PROJECT) */
 #define audioPlaybackInit(device, sampleRate, queueDuration, frameSize)
 #define audioCaptureInit(device, sampleRate, queueDuration, frameSize)
 #define audioCapture(device, outData, frameSize)
 #define audioPlayback(device, inData, frameSize)
 #define audioCaptureTerminate(device)
 #define audioPlaybackTerminate(device)
#endif

#ifdef __cplusplus
}
#endif
#endif


