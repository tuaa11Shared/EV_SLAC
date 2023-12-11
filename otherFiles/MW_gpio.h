// Copyright 2012-2017 The MathWorks, Inc.
#ifndef _MW_GPIO_H_
#define _MW_GPIO_H_
#include "rtwtypes.h"

typedef struct {
    int gpio;                   // Pin number
    int fd;                     // File descriptor for the GPIO pin  
    boolean_T direction;        // Input or output
} GPIO_info;

#ifdef __cplusplus
extern "C"
{
#endif
    
// Common definitions
#define GPIO_MAX_BUF               (128)
#define GPIO_DIRECTION_INPUT       (1)  // MATLAB numbering
#define GPIO_DIRECTION_OUTPUT      (2)

extern void MW_gpioInit(int32_T gpio, boolean_T direction);
extern void MW_gpioTerminate(int32_T gpio);
extern boolean_T MW_gpioRead(int32_T gpio);
extern void MW_gpioWrite(int32_T gpio, boolean_T value);

/* With handles */
extern GPIO_info * MW_gpioInitH(int32_T gpio, boolean_T direction);
extern void MW_gpioTerminateH(GPIO_info * gpioInfoPtr);
extern boolean_T MW_gpioReadH(GPIO_info * gpioInfoPtr);
extern void MW_gpioWriteH(GPIO_info * gpioInfoPtr, boolean_T value);

#ifdef __cplusplus
}
#endif
#endif
