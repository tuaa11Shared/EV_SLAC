/* Copyright 2016 The MathWorks, Inc. */
#ifndef __MW_SDL_VIDEO_DISPLAY_H__
#define __MW_SDL_VIDEO_DISPLAY_H__
#include "rtwtypes.h"
#ifdef __cplusplus
extern "C" {
#endif

#if (defined(MATLAB_MEX_FILE) || defined(EXT_MODE) || defined(RSIM_PARAMETER_LOADING) ||  defined(RSIM_WITH_SL_SOLVER))
 /* Rapid Accelerator Mode */
 #define MW_SDL_videoDisplayInit(pixelFormat,pixelOrder,rowMajor,width,height)
 #define MW_SDL_videoDisplayOutput(pln0,pln1,pln2)
 #define MW_SDL_videoDisplayTerminate(width,height)   
#else
/* Code generation */ 
#if defined(__linux__) 
 #include "SDL/SDL.h"
#else
 #include "SDL.h"
#endif
void MW_SDL_videoDisplayInit(
    int32_T pixelFormat, 
    int32_T pixelOrder, 
    int32_T rowMajor,
    int32_T width, 
    int32_T height);
void MW_SDL_videoDisplayOutput(const uint8_T *pln0, const uint8_T *pln1, const uint8_T *pln2);
void MW_SDL_videoDisplayTerminate(int32_T width, int32_T height);
#endif

#ifdef __cplusplus
}
#endif
#endif