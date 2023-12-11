#include "EV_SLAC.h"
#include "rtwtypes.h"
#include "EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_atten_char_IND.h"
#include "EV_SLAC_private.h"

void EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_atten_char_IND_Init
  (int32_T *rty_ret)
{
  *rty_ret = EV_SLAC_P.ret_Y0_i5;
}

void EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_atten_char_IND(int32_T
  *rty_ret)
{
  EV_SLAC_B.CCaller_o2_l = EV_SLAC_SharedDSM.global_session;
  *rty_ret = pev_cm_atten_char_IND(&EV_SLAC_B.CCaller_o2_l,
    &EV_SLAC_SharedDSM.global_channel, &EV_SLAC_SharedDSM.global_message);
  EV_SLAC_SharedDSM.global_session = EV_SLAC_B.CCaller_o2_l;
}
