#include "EV_SLAC.h"
#include "rtwtypes.h"
#include "EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_mnbc_sound.h"
#include "EV_SLAC_private.h"

void EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_mnbc_sound_Init(int32_T
  *rty_ret)
{
  *rty_ret = EV_SLAC_P.ret_Y0_l1;
}

void EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_mnbc_sound(int32_T
  *rty_ret)
{
  *rty_ret = pev_cm_mnbc_sound(&EV_SLAC_SharedDSM.global_session,
    &EV_SLAC_SharedDSM.global_channel, &EV_SLAC_SharedDSM.global_message);
}
