#include "EV_SLAC.h"
#include "rtwtypes.h"
#include "EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_set_key_CNF.h"
#include "EV_SLAC_private.h"

void EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_set_key_CNF_Init(int32_T *rty_ret)
{
  *rty_ret = EV_SLAC_P.ret_Y0_o;
}

void EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_set_key_CNF(int32_T *rty_ret)
{
  *rty_ret = pev_cm_set_key_CNF(&EV_SLAC_SharedDSM.global_session,
    &EV_SLAC_SharedDSM.global_channel, &EV_SLAC_SharedDSM.global_message);
}
