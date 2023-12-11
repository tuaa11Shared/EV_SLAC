#include "EV_SLAC.h"
#include "rtwtypes.h"
#include "EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONpev_cm_atten_char_RSP.h"
#include "EV_SLAC_private.h"

void EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONpev_cm_atten_char_RSP_Init(int32_T *
  rty_ret)
{
  *rty_ret = EV_SLAC_P.ret_Y0_h;
}

void EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONpev_cm_atten_char_RSP(int32_T
  *rty_ret)
{
  EV_SLAC_B.CCaller_o2_o = EV_SLAC_SharedDSM.global_session;
  *rty_ret = pev_cm_atten_char_RSP(&EV_SLAC_B.CCaller_o2_o,
    &EV_SLAC_SharedDSM.global_channel, &EV_SLAC_SharedDSM.global_message);
  EV_SLAC_SharedDSM.global_session = EV_SLAC_B.CCaller_o2_o;
}
