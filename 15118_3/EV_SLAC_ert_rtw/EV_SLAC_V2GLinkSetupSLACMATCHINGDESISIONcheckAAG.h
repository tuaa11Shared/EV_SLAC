#ifndef RTW_HEADER_EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONcheckAAG_h_
#define RTW_HEADER_EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONcheckAAG_h_
#ifndef EV_SLAC_COMMON_INCLUDES_
#define EV_SLAC_COMMON_INCLUDES_
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <semaphore.h>
#include <errno.h>
#include <stdio.h>
#include <limits.h>
#include "rtwtypes.h"
#include "ProtocolDecoderUtilities.h"
#endif

extern void EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONcheckAAG_Init(int32_T
  *rty_ret);
extern void EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONcheckAAG(uint16_T
  rtu_Threshold1, uint16_T rtu_Threshold2, int32_T *rty_ret);

#endif

