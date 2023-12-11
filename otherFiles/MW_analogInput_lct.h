/* Copyright 2014 The MathWorks, Inc. */
#ifndef _MW_ANALOG_INPUT_LCT_H_
#define _MW_ANALOG_INPUT_LCT_H_

#if defined(ARM_PROJECT)
 #include "MW_analogInput.h"
#else
 #define MW_analogInputInit() (0)
 #define MW_analogInputRead(adc) (0)
#endif 

#endif 
 
