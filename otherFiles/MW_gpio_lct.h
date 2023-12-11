/* Copyright 2014 The MathWorks, Inc. */
#ifndef _MW_GPIO_LCT_H_
#define _MW_GPIO_LCT_H_

#if defined(ARM_PROJECT)
 #include "MW_gpio.h"
#else
 #define MW_gpioInit(gpio,direction) (0)
 #define MW_gpioWrite(gpio, inData) (0)
 #define MW_gpioRead(gpio) (0)
 #define MW_gpioTerminate(gpio) (0)
#endif

#endif 
 
