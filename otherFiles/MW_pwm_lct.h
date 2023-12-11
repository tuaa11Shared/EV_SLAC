/* Copyright 2014 The MathWorks, Inc. */
#ifndef _MW_PWM_LCT_H_
#define _MW_PWM_LCT_H_

#if defined(ARM_PROJECT)
 #include "MW_pwm.h"
#else
 #define MW_pwmInit(pin,frequency,polarity) (0)
 #define MW_pwmWrite(pin,dutyCycle) (0)
 #define MW_pwmTerminate(pin) (0)
#endif

#endif
 
