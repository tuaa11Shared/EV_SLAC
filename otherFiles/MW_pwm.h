/* Copyright 2014-2015 The MathWorks, Inc. */
#ifndef _MW_PWM_H_
#define _MW_PWM_H_
#include "rtwtypes.h"
#ifdef __cplusplus
extern "C"
{
#endif
    
void MW_pwmInit(const uint8_T *pin, const real_T frequency, const uint32_T polarity);
void MW_pwmWrite(const uint8_T *pin, const real_T dutyCycle);
void MW_pwmTerminate(const uint8_T *pin);

#ifdef __cplusplus
}
#endif
#endif 

