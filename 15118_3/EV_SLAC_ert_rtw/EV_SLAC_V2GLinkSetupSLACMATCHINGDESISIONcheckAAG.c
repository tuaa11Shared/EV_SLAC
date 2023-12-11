#include "EV_SLAC.h"
#include "rtwtypes.h"
#include "EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONcheckAAG.h"
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "EV_SLAC_private.h"

void EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONcheckAAG_Init(int32_T *rty_ret)
{
  *rty_ret = EV_SLAC_P.ret_Y0_b;
}

void EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONcheckAAG(uint16_T rtu_Threshold1,
  uint16_T rtu_Threshold2, int32_T *rty_ret)
{
  int32_T i;
  int32_T rtb_Switch;
  byte_t tmp_0;
  char_T tmp[31];
  i = 0;
  for (rtb_Switch = 0; rtb_Switch < 58; rtb_Switch++) {
    i = (int32_T)((uint32_T)i + (uint32_T)(int32_T)
                  EV_SLAC_SharedDSM.global_session.AAG[rtb_Switch]);
  }

  if ((int32_T)EV_SLAC_SharedDSM.global_session.NumGroups > (int32_T)
      EV_SLAC_P.Saturation_UpperSat_f) {
    tmp_0 = EV_SLAC_P.Saturation_UpperSat_f;
  } else if ((int32_T)EV_SLAC_SharedDSM.global_session.NumGroups < (int32_T)
             EV_SLAC_P.Saturation_LowerSat_dw) {
    tmp_0 = EV_SLAC_P.Saturation_LowerSat_dw;
  } else {
    tmp_0 = EV_SLAC_SharedDSM.global_session.NumGroups;
  }

  i = div_s32_floor(i, (int32_T)tmp_0);
  if (EV_SLAC_ConstB.Width >= (real_T)(int32_T)
      EV_SLAC_SharedDSM.global_session.NumGroups) {
    rtb_Switch = (i >= (int32_T)rtu_Threshold1) + (i >= (int32_T)rtu_Threshold2);
  } else {
    rtb_Switch = EV_SLAC_P.Constant2_Value;
  }

  snprintf(&EV_SLAC_B.rtb_ComposeString_mb[0], 256U, "AAG: %d ret: %d", i,
           rtb_Switch);
  strncpy(&tmp[0], &EV_SLAC_B.rtb_ComposeString_mb[0], 31U);
  for (i = 0; i < 31; i++) {
    EV_SLAC_B.Cast3[i] = (int8_T)(uint8_T)tmp[i];
  }

  slac_debug_ported(EV_SLAC_P.CCaller_status, &EV_SLAC_B.Cast3[0]);
  *rty_ret = rtb_Switch;
}
