/* Copyright 2014 The MathWorks, Inc. */
#ifndef _MW_ALSA_AUDIO_PLAYBACK_MACRO_H_
#define _MW_ALSA_AUDIO_PLAYBACK_MACRO_H_

#if defined(ARM_PROJECT)
 #include "MW_alsa_audio.h"
#else
 #define audioPlaybackInit(device, sampleRate, queueDuration, size) 
 #define audioPlayback(device, inData,  size) 
 #define audioPlaybackTerminate(device) 
#endif

#endif 
 
