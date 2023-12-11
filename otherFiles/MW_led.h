// Copyright 2012-2015 The MathWorks, Inc.
#ifndef _MW_LED_H_
#define _MW_LED_H_
#include "rtwtypes.h"
#ifdef __cplusplus
extern "C"
{
#endif

void MW_ledInit(const uint8_T *deviceFile);
void MW_ledTerminate(const uint8_T *deviceFile);
void MW_ledWrite(const uint8_T *deviceFile, boolean_T value);

#ifdef __cplusplus
}
#endif
#endif

