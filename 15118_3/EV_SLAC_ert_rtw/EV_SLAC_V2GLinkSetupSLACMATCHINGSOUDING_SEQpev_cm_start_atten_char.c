#include "EV_SLAC.h"
#include "rtwtypes.h"
#include "EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_start_atten_char.h"
#include "EV_SLAC_private.h"

void EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_start_atten_char_Init
  (int32_T *rty_ret)
{
  *rty_ret = EV_SLAC_P.ret_Y0_i;
}

void EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_start_atten_char(int32_T *
  rty_ret)
{
  *rty_ret = pev_cm_start_atten_char(&EV_SLAC_SharedDSM.global_session,
    &EV_SLAC_SharedDSM.global_channel, &EV_SLAC_SharedDSM.global_message);
}
