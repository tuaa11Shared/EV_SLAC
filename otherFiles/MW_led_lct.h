/* Copyright 2014 The MathWorks, Inc. */
#ifndef _MW_LED_LCT_H_
#define _MW_LED_LCT_H_

#if defined(ARM_PROJECT)
 #include "MW_led.h"
#else
 #define MW_ledInit(deviceFile) (0)
 #define MW_ledWrite(deviceFile,inData) (0)
 #define MW_ledTerminate(deviceFile) (0)
#endif 

#endif 
 
