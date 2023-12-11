/* Copyright 2014-2015 The MathWorks, Inc. */
#ifndef _MW_ANALOG_INPUT_H_
#define _MW_ANALOG_INPUT_H_
#include "rtwtypes.h"
#ifdef __cplusplus
extern "C"
{
#endif
 
void MW_analogInputInit(void);
real_T MW_analogInputRead(const uint32_T *adc);

#ifdef __cplusplus
}
#endif
#endif

