#include "EV_SLAC.h"
#include "rtwtypes.h"
#include "EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_slac_match.h"
#include "EV_SLAC_private.h"

void EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_slac_match_Init(int32_T *rty_ret)
{
  *rty_ret = EV_SLAC_P.ret_Y0_d;
}

void EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_slac_match(int32_T *rty_ret)
{
  EV_SLAC_B.CCaller_o2_g = EV_SLAC_SharedDSM.global_session;
  *rty_ret = pev_cm_slac_match_ported(&EV_SLAC_B.CCaller_o2_g,
    &EV_SLAC_SharedDSM.global_channel, &EV_SLAC_SharedDSM.global_message);
  EV_SLAC_SharedDSM.global_session = EV_SLAC_B.CCaller_o2_g;
}
