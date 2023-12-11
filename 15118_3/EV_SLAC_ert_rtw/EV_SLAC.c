#include "EV_SLAC.h"
#include "slac.h"
#include "channel.h"
#include "mme.h"
#include "rtwtypes.h"
#include "EV_SLAC_types.h"
#include "iso1EXIDatatypes.h"
#include "EXITypes.h"
#include "EV_SLAC_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "types.h"
#include <stdio.h>
#include <string.h>
#include "EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_start_atten_char.h"
#include "EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_mnbc_sound.h"
#include "EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_atten_char_IND.h"
#include "EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONpev_cm_atten_char_RSP.h"
#include "EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONcheckAAG.h"
#include "EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_slac_match.h"
#include "EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_set_key_REQ.h"
#include "EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_set_key_CNF.h"
#include "linuxUDP_portV6.h"
#include <stddef.h>

#define EV_SLAC_IN_AUTHORIZATION       ((uint8_T)1U)
#define EV_SLAC_IN_Atten               ((uint8_T)1U)
#define EV_SLAC_IN_BINDING             ((uint8_T)1U)
#define EV_SLAC_IN_BLOCK               ((uint8_T)1U)
#define EV_SLAC_IN_CABLE_CHECK         ((uint8_T)2U)
#define EV_SLAC_IN_CHECK_COMPATABLE    ((uint8_T)1U)
#define EV_SLAC_IN_COMMUNICATION_SETUP ((uint8_T)1U)
#define EV_SLAC_IN_DESISION            ((uint8_T)2U)
#define EV_SLAC_IN_FirstStateReq       ((uint8_T)1U)
#define EV_SLAC_IN_FirstStateRes       ((uint8_T)2U)
#define EV_SLAC_IN_Hansharking         ((uint8_T)1U)
#define EV_SLAC_IN_Initialization      ((uint8_T)1U)
#define EV_SLAC_IN_JOIN_NETWORK        ((uint8_T)1U)
#define EV_SLAC_IN_JOIN_NETWORK_CNF    ((uint8_T)1U)
#define EV_SLAC_IN_JOIN_NETWORK_REQ    ((uint8_T)2U)
#define EV_SLAC_IN_LOOP_ACTIVE         ((uint8_T)1U)
#define EV_SLAC_IN_LOOP_INACTIVE       ((uint8_T)2U)
#define EV_SLAC_IN_LastStateCNF        ((uint8_T)1U)
#define EV_SLAC_IN_MATCHED             ((uint8_T)2U)
#define EV_SLAC_IN_MATCHING            ((uint8_T)3U)
#define EV_SLAC_IN_NOP                 ((uint8_T)1U)
#define EV_SLAC_IN_NO_ACTIVE_CHILD     ((uint8_T)0U)
#define EV_SLAC_IN_OPEN_CHANNEL        ((uint8_T)2U)
#define EV_SLAC_IN_OPEN_TCPCHANNEL     ((uint8_T)1U)
#define EV_SLAC_IN_PARAMETER_DISCOVERY ((uint8_T)3U)
#define EV_SLAC_IN_PAYMENT_SELECTION   ((uint8_T)4U)
#define EV_SLAC_IN_POWER_DELIVERY      ((uint8_T)5U)
#define EV_SLAC_IN_PRE_CHARGE          ((uint8_T)6U)
#define EV_SLAC_IN_RECEIVING_ATTEN_CHAR ((uint8_T)1U)
#define EV_SLAC_IN_REQUEST             ((uint8_T)1U)
#define EV_SLAC_IN_REQ_BLOCK           ((uint8_T)1U)
#define EV_SLAC_IN_RESPONSE            ((uint8_T)2U)
#define EV_SLAC_IN_RSP_ATTEN_CHAR      ((uint8_T)2U)
#define EV_SLAC_IN_Request             ((uint8_T)1U)
#define EV_SLAC_IN_SDP                 ((uint8_T)2U)
#define EV_SLAC_IN_SDP_REQ             ((uint8_T)1U)
#define EV_SLAC_IN_SDP_RES             ((uint8_T)2U)
#define EV_SLAC_IN_SERVICE_DETAIL      ((uint8_T)7U)
#define EV_SLAC_IN_SERVICE_DISCOVERY   ((uint8_T)8U)
#define EV_SLAC_IN_SESSION_SETUP       ((uint8_T)3U)
#define EV_SLAC_IN_SLAC                ((uint8_T)2U)
#define EV_SLAC_IN_SOUDING_SEQ         ((uint8_T)3U)
#define EV_SLAC_IN_SOUNDING            ((uint8_T)2U)
#define EV_SLAC_IN_STANDBY             ((uint8_T)1U)
#define EV_SLAC_IN_START_ATTEN         ((uint8_T)3U)
#define EV_SLAC_IN_SecondStateReq      ((uint8_T)2U)
#define EV_SLAC_IN_Slac_param          ((uint8_T)4U)
#define EV_SLAC_IN_Start_Match         ((uint8_T)2U)
#define EV_SLAC_IN_TCP_TLS_CONNECTION_EST ((uint8_T)4U)
#define EV_SLAC_IN_TRY_RECEIVE         ((uint8_T)2U)
#define EV_SLAC_IN_TRY_RECEIVE1        ((uint8_T)3U)
#define EV_SLAC_IN_TRY_SEND            ((uint8_T)4U)
#define EV_SLAC_IN_TRY_SEND1           ((uint8_T)5U)
#define EV_SLAC_IN_Toggling_State      ((uint8_T)3U)
#define EV_SLAC_IN_V2G2_016_IP_ADD_ASSIGMENT ((uint8_T)1U)
#define EV_SLAC_IN_V2G2_019_V2G2_645_SECC_DISCOVERY ((uint8_T)2U)
#define EV_SLAC_IN_V2G_SEQ             ((uint8_T)3U)
#define EV_SLAC_IN_VALIDATE            ((uint8_T)4U)
#define EV_SLAC_IN_errorHandle         ((uint8_T)4U)
#define EV_SLAC_IN_errorHandle_o       ((uint8_T)9U)
#define EV_SLAC_IN_response            ((uint8_T)2U)
#define EV_SLAC_IN_waitingRes          ((uint8_T)3U)
#define EV_SLAC_IN_waitingRes_j        ((uint8_T)2U)

SdpMesgResT sdpMesg_res_bus;
Slac_timing_constant_type Slac_timing_constant = {

  50U,

  500U,

  100U,

  1200U,

  12U,

  200U,

  20U
};

V2G_EVCC_Msg_Timeout_type V2G_EVCC_Msg_Timeout = {

  2000U,

  2000U,

  2000U,

  2000U,

  5000U,

  2000U,

  2000U
};

rt_Simulink_Struct_type rt_Simulink_Struct = {

  60000U
};

B_EV_SLAC_T EV_SLAC_B;
DW_EV_SLAC_T EV_SLAC_DW;
SharedDSM_EV_SLAC_T EV_SLAC_SharedDSM;
static RT_MODEL_EV_SLAC_T EV_SLAC_M_;
RT_MODEL_EV_SLAC_T *const EV_SLAC_M = &EV_SLAC_M_;
static void EV_SLAC_initialize_msg_local_queues_for_chart(void);
static void EV_SLAC_eml_rand_mt19937ar(uint32_T state[625]);
static void EV_SLAC_rng(real_T varargin_1, uint32_T *state_d);
static void EV_SLAC_SystemCore_setup
  (matlabshared_embedded_utilities_blocks_ProtocolDecoderBlock_EV_SLAC_k_T *obj);
static void EV_SLAC_sf_msg_send_ActiveTcpLoop(void);
static boolean_T EV_SLAC_sf_msg_pop_StreamMesgIn(void);
static void EV_SLAC_sf_msg_send_StreamMesgOut(void);
static uint16_T EV_SLAC_ProtocolDecoderBase_bytePacker(const uint8_T inData[24]);
static real_T EV_SLAC_rand_d(void);
static void EV_SLAC_SDP(void);
static void EV_SLAC_COMMUNICATION_SETUP(void);
static void EV_SLAC_Slac_param(void);
static void EV_SLAC_enter_internal_Slac_param(void);
static void EV_SLAC_MATCHING(void);
static real_T EV_SLAC_rand(void);
static boolean_T EV_SLAC_sf_msg_pop_TCP_IP_LostConnect(void);
static void EV_SLAC_AUTHORIZATION(void);
static void EV_SLAC_CABLE_CHECK(void);
static real32_T EV_SLAC_rt_powf_snf(real32_T u0, real32_T u1);
static void EV_SLAC_PARAMETER_DISCOVERY(void);
static void EV_SLAC_PRE_CHARGE(void);
static void EV_SLAC_exit_internal_V2G_SEQ(void);
static void EV_SLAC_V2G_SEQ(void);
static boolean_T EV_SLAC_sf_msg_pop_ActiveTcpLoop(boolean_T
  *ActiveTcpLoop_isValid);
static boolean_T EV_SLAC_sf_msg_pop_StreamMesgOut(boolean_T
  *StreamMesgOut_isValid);
static void EV_SLAC_sf_msg_send_StreamMesgIn(void);
static void EV_SLAC_sf_msg_send_TCP_IP_LostConnect(void);
static void EV_SLAC_V2G(boolean_T *StreamMesgOut_isValid, boolean_T
  *ActiveTcpLoop_isValid);
static void EV_SLAC_sf_msg_discard_StreamMesgOut(boolean_T
  *StreamMesgOut_isValid);
static void EV_SLAC_sf_msg_discard_StreamMesgIn(void);
static void EV_SLAC_sf_msg_discard_ActiveTcpLoop(boolean_T
  *ActiveTcpLoop_isValid);
static void EV_SLAC_sf_msg_discard_TCP_IP_LostConnect(void);
int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;
  } else {
    uint32_T absDenominator;
    uint32_T absNumerator;
    uint32_T tempAbsQuotient;
    boolean_T quotientNeedsNegation;
    absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
      denominator;
    quotientNeedsNegation = (boolean_T)((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

void Task0_fcn(void)
{
  while (1) {
    {
      EV_SLAC_M->Timing.clockTick1 = EV_SLAC_M->Timing.clockTick0;
      EV_SLAC_B.elapsedTime = ((EV_SLAC_M->Timing.clockTick1) * 0.01) -
        EV_SLAC_DW.previousTime;
      EV_SLAC_DW.previousTime = ((EV_SLAC_M->Timing.clockTick1) * 0.01);
      EV_SLAC_DW.temporalCounter_i1 += EV_SLAC_B.elapsedTime;
      EV_SLAC_DW.temporalCounter_i2 += EV_SLAC_B.elapsedTime;
      EV_SLAC_B.StreamMesgOut_isValid = false;
      EV_SLAC_DW.StreamMesgIn_isValid = false;
      EV_SLAC_B.ActiveTcpLoop_isValid = false;
      EV_SLAC_DW.TCP_IP_LostConnect_isValid = false;
      if ((uint32_T)(int32_T)EV_SLAC_DW.is_active_c1_EV_SLAC == 0U) {
        EV_SLAC_DW.is_active_c1_EV_SLAC = (uint8_T)1U;
        EV_SLAC_DW.is_LinkSetup = EV_SLAC_IN_SLAC;
        EV_SLAC_DW.is_SLAC = EV_SLAC_IN_Initialization;
        EV_SLAC_SharedDSM.global_channel = EV_SLAC_P.Constant_Value;
        EV_SLAC_SharedDSM.global_channel.fd = (int32_T)
          EV_SLAC_P.Constant1_Value_a4;
        EV_SLAC_SharedDSM.global_channel.ifindex = (int32_T)
          EV_SLAC_P.Constant2_Value_g;
        strncpy(&EV_SLAC_B.cv11[0], &EV_SLAC_P.StringConstant_String[0], 16U);
        for (EV_SLAC_B.i = 0; EV_SLAC_B.i < 16; EV_SLAC_B.i++) {
          EV_SLAC_SharedDSM.global_channel.ifname[EV_SLAC_B.i] = (int8_T)
            (uint8_T)EV_SLAC_B.cv11[EV_SLAC_B.i];
        }

        for (EV_SLAC_B.i = 0; EV_SLAC_B.i < 6; EV_SLAC_B.i++) {
          EV_SLAC_SharedDSM.global_channel.peer[EV_SLAC_B.i] =
            EV_SLAC_P.Constant3_Value_k[EV_SLAC_B.i];
        }

        EV_SLAC_SharedDSM.global_channel.type = EV_SLAC_P.Constant4_Value_f;
        EV_SLAC_SharedDSM.global_channel.capture = (int32_T)
          EV_SLAC_P.Constant5_Value_h;
        EV_SLAC_SharedDSM.global_channel.timeout = (int32_T)
          EV_SLAC_P.Constant6_Value_n;
        EV_SLAC_V2GLinkSetupSLACInitializationopenChannel();
        EV_SLAC_DW.ret = EV_SLAC_B.Cast12;
        EV_SLAC_DW.is_TCP_IP_LOOP = EV_SLAC_IN_LOOP_INACTIVE;
      } else {
        EV_SLAC_V2G(&EV_SLAC_B.StreamMesgOut_isValid,
                    &EV_SLAC_B.ActiveTcpLoop_isValid);
      }

      EV_SLAC_sf_msg_discard_StreamMesgOut(&EV_SLAC_B.StreamMesgOut_isValid);
      EV_SLAC_sf_msg_discard_StreamMesgIn();
      EV_SLAC_sf_msg_discard_ActiveTcpLoop(&EV_SLAC_B.ActiveTcpLoop_isValid);
      EV_SLAC_sf_msg_discard_TCP_IP_LostConnect();
    }
  }
}

void EV_SLAC_V2GLinkSetupSLACInitializationopenChannel_Init(void)
{
  EV_SLAC_B.Cast12 = EV_SLAC_P.ret_Y0;
}

void EV_SLAC_V2GLinkSetupSLACInitializationopenChannel(void)
{
  int32_T i;
  int32_T rtb_CCaller1_o1;
  int32_T rtb_CCaller_o1;
  char_T tmp[17];
  char_T tmp_0[16];
  uint8_T rtb_Reshape[8];
  EV_SLAC_B.BusAssignment_m = EV_SLAC_SharedDSM.global_channel;
  rtb_CCaller_o1 = initchannel(&EV_SLAC_B.BusAssignment_m);
  strncpy(&tmp_0[0], &EV_SLAC_P.StringConstant_String_e[0], 16U);
  for (i = 0; i < 16; i++) {
    EV_SLAC_B.BusAssignment_m.ifname[i] = (int8_T)(uint8_T)tmp_0[i];
  }

  EV_SLAC_SharedDSM.global_channel = EV_SLAC_B.BusAssignment_m;
  rtb_CCaller1_o1 = openchannel(&EV_SLAC_SharedDSM.global_channel);
  for (i = 0; i < 6; i++) {
    rtb_Reshape[i] = EV_SLAC_SharedDSM.global_channel.host[i];
  }

  rtb_Reshape[6] = EV_SLAC_P.Constant5_Value_g[0];
  rtb_Reshape[7] = EV_SLAC_P.Constant5_Value_g[1];
  strncpy(&tmp[0], &EV_SLAC_P.StringConstant1_String[0], 17U);
  for (i = 0; i < 17; i++) {
    EV_SLAC_B.CCaller2_o2_c[i] = (uint8_T)tmp[i];
    EV_SLAC_B.Cast1[i] = (int8_T)EV_SLAC_B.CCaller2_o2_c[i];
    EV_SLAC_B.CCaller2_o2_c[i] = EV_SLAC_P.Constant7_Value_o[i];
  }

  hexencode(&EV_SLAC_B.CCaller2_o2_c[0], EV_SLAC_ConstB.Width_m,
            &EV_SLAC_B.Cast1[0]);
  EV_SLAC_SharedDSM.global_session.limit = (uint32_T)
    EV_SLAC_P.Constant_Value_inb;
  EV_SLAC_SharedDSM.global_session.pause = (uint32_T)
    EV_SLAC_P.Constant1_Value_kf;
  EV_SLAC_SharedDSM.global_session.settletime = (uint32_T)
    EV_SLAC_P.Constant2_Value_l;
  EV_SLAC_SharedDSM.global_session.chargetime = (uint32_T)
    EV_SLAC_P.Constant3_Value_oe;
  EV_SLAC_SharedDSM.global_session.state = (uint32_T)EV_SLAC_P.Constant4_Value_d;
  for (i = 0; i < 8; i++) {
    EV_SLAC_SharedDSM.global_session.RunID[i] = rtb_Reshape[i];
  }

  for (i = 0; i < 6; i++) {
    EV_SLAC_SharedDSM.global_session.PEV_MAC[i] =
      EV_SLAC_SharedDSM.global_channel.host[i];
  }

  memcpy(&EV_SLAC_SharedDSM.global_session.PEV_ID[0], &EV_SLAC_B.CCaller2_o2_c[0],
         17U * sizeof(byte_t));
  EV_SLAC_B.Cast12 = ((rtb_CCaller_o1 != EV_SLAC_P.Constant_Value_f5) ||
                      (rtb_CCaller1_o1 != EV_SLAC_P.Constant_Value_f));
  desuid();
}

void EV_SLAC_V2GLinkSetupSLACSlac_paraminscreseRunID(session_t
  *rtd_global_session, const
  ConstB_V2GLinkSetupSLACSlac_paraminscreseRunID_EV_SLAC_T *localC)
{
  real_T tmp;
  int32_T i;
  byte_t rtb_DataStoreRead_lj[8];
  byte_t rtd_global_session_0;
  for (i = 0; i < 8; i++) {
    rtd_global_session_0 = rtd_global_session->RunID[i];
    rtb_DataStoreRead_lj[i] = rtd_global_session_0;
  }

  tmp = floor(localC->Width);
  if (((int32_T)rtIsNaN(tmp)) || ((int32_T)rtIsInf(tmp))) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  memincr(&rtb_DataStoreRead_lj[0], tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
          -tmp : (uint32_T)tmp);
  for (i = 0; i < 8; i++) {
    rtd_global_session_0 = rtb_DataStoreRead_lj[i];
    rtd_global_session->RunID[i] = rtd_global_session_0;
  }
}

void EV_SLAC_V2GLinkSetupSLACSlac_parampev_cm_slac_param_request_Init(int32_T
  *rty_ret)
{
  *rty_ret = EV_SLAC_P.ret_Y0_l;
}

void EV_SLAC_V2GLinkSetupSLACSlac_parampev_cm_slac_param_request(int32_T
  *rty_ret)
{
  *rty_ret = pev_cm_slac_param_request(&EV_SLAC_SharedDSM.global_session,
    &EV_SLAC_SharedDSM.global_channel, &EV_SLAC_SharedDSM.global_message);
}

void EV_SLAC_V2GLinkSetupSLACSlac_parampev_cm_slac_param_response_Init(int32_T
  *rty_ret)
{
  *rty_ret = EV_SLAC_P.ret_Y0_lz;
}

void EV_SLAC_V2GLinkSetupSLACSlac_parampev_cm_slac_param_response(int32_T
  *rty_ret)
{
  EV_SLAC_B.CCaller_o2 = EV_SLAC_SharedDSM.global_session;
  *rty_ret = pev_cm_slac_param_response(&EV_SLAC_B.CCaller_o2,
    &EV_SLAC_SharedDSM.global_channel, &EV_SLAC_SharedDSM.global_message);
  EV_SLAC_SharedDSM.global_session = EV_SLAC_B.CCaller_o2;
}

void
  EV_S_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_Init
  (B_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_EV_SL_T
   *localB,
   P_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_EV_SL_T
   *localP)
{
  localB->CCaller = localP->ret_Y0;
}

void
  EV_SLAC_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ
  (channel_t *rtd_global_channel, MESSAGE *rtd_global_message, session_t
   *rtd_global_session,
   B_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_EV_SL_T
   *localB)
{
  localB->CCaller = pev_cm_validate_FisrtState_REQ(rtd_global_session,
    rtd_global_channel, rtd_global_message);
}

void
  EV_S_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_Init
  (B_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_EV_SL_T
   *localB,
   P_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_EV_SL_T
   *localP)
{
  localB->CCaller = localP->ret_Y0;
}

void
  EV_SLAC_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES
  (channel_t *rtd_global_channel, MESSAGE *rtd_global_message, session_t
   *rtd_global_session,
   B_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_EV_SL_T
   *localB)
{
  localB->CCaller = pev_cm_validate_FisrtState_IND(rtd_global_session,
    rtd_global_channel, rtd_global_message);
}

void EV_SLAC_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_Init
  (B_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_EV_SLAC_T
   *localB,
   P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_EV_SLAC_T
   *localP)
{
  localB->CCaller = localP->ret_Y0;
}

void EV_SLAC_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ
  (channel_t *rtd_global_channel, MESSAGE *rtd_global_message, session_t
   *rtd_global_session,
   B_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_EV_SLAC_T
   *localB,
   P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_EV_SLAC_T
   *localP)
{
  real32_T tmp;
  tmp = floorf((real32_T)localP->Gain_Gain * localP->TP_EV_vald_toggle_Value);
  if (((int32_T)rtIsNaNF(tmp)) || ((int32_T)rtIsInfF(tmp))) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 256.0F);
  }

  localB->CCaller = pev_cm_validate_SecondStateREQ(rtd_global_session,
    rtd_global_channel, rtd_global_message, (uint8_T)(tmp < 0.0F ? (int32_T)
    (uint8_T)-(int32_T)(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp));
}

void EV_SLAC_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_Init
  (B_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_EV_SLAC_T
   *localB,
   P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_EV_SLAC_T
   *localP)
{
  localB->CCaller = localP->ret_Y0;
}

void EV_SLAC_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF
  (channel_t *rtd_global_channel, MESSAGE *rtd_global_message, session_t
   *rtd_global_session,
   B_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_EV_SLAC_T
   *localB,
   P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_EV_SLAC_T
   *localP)
{
  localB->CCaller = pev_cm_validate_SecondStateCNF(rtd_global_session,
    rtd_global_channel, rtd_global_message, localP->C_EV_vald_nb_toggles_Value);
}

void EV_SLAC_V2GLinkSetuperrorHandleTimeOutHandle
  (B_V2GLinkSetuperrorHandleTimeOutHandle_EV_SLAC_T *localB,
   P_V2GLinkSetuperrorHandleTimeOutHandle_EV_SLAC_T *localP)
{
  int32_T i;
  snprintf(&localB->rtb_ComposeString_oo_m[0], 256U,
           "SLAC TIME OUT ====> EXITED %d", localP->Constant_Value);
  strncpy(&localB->cv[0], &localB->rtb_ComposeString_oo_m[0], 100U);
  for (i = 0; i < 100; i++) {
    localB->Cast1_bd[i] = (int8_T)(uint8_T)localB->cv[i];
  }

  slac_debug_ported(localP->CCaller_status, &localB->Cast1_bd[0]);
}

void EV_SLAC_MATLABFunction(uint8_T rtu_u, B_MATLABFunction_EV_SLAC_T *localB)
{
  int32_T b_k;
  int32_T idx;
  int32_T k;
  int32_T npad;
  char_T b[8];
  char_T sfull[8];
  uint8_T v;
  boolean_T exitg1;
  for (idx = 0; idx < 8; idx++) {
    sfull[idx] = '0';
    if ((1 << (7 - idx) & (int32_T)rtu_u) != 0) {
      sfull[idx] = '1';
    }
  }

  idx = 0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if ((int32_T)sfull[k] == 49) {
      idx = k + 1;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (idx == 0) {
    idx = 8;
  }

  k = 8 - idx;
  if (9 - idx < 8) {
    npad = idx - 1;
    for (b_k = 0; b_k < npad; b_k++) {
      b[b_k] = '0';
    }
  } else {
    npad = 0;
  }

  for (b_k = 0; b_k <= k; b_k++) {
    b[npad + b_k] = sfull[(idx + b_k) - 1];
  }

  v = (uint8_T)((int32_T)b[3] == 49);
  if ((int32_T)b[2] == 49) {
    v = (uint8_T)((int32_T)v + 2);
  }

  if ((int32_T)b[1] == 49) {
    v = (uint8_T)((int32_T)v + 4);
  }

  if ((int32_T)b[0] == 49) {
    v = (uint8_T)((int32_T)v + 8);
  }

  if ((int32_T)v > 9) {
    localB->y[0] = (uint8_T)(char_T)((int32_T)v + 55);
  } else {
    localB->y[0] = (uint8_T)(char_T)((int32_T)v + 48);
  }

  v = (uint8_T)((int32_T)b[7] == 49);
  if ((int32_T)b[6] == 49) {
    v = (uint8_T)((int32_T)v + 2);
  }

  if ((int32_T)b[5] == 49) {
    v = (uint8_T)((int32_T)v + 4);
  }

  if ((int32_T)b[4] == 49) {
    v = (uint8_T)((int32_T)v + 8);
  }

  if ((int32_T)v > 9) {
    localB->y[1] = (uint8_T)(char_T)((int32_T)v + 55);
  } else {
    localB->y[1] = (uint8_T)(char_T)((int32_T)v + 48);
  }
}

void
  V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp__Init
  (B_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_r_T
   *localB,
   DW_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp__T
   *localDW,
   P_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_r_T
   *localP)
{
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;
  localB->CCaller1 = localP->ret_Y0;
}

void
  E_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req
  (uint8_T rtd_UDP_PORT[256],
   B_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_r_T
   *localB, const
   ConstB_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERY_T
   *localC,
   DW_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp__T
   *localDW,
   P_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_r_T
   *localP)
{
  int32_T i;
  uint8_T rtb_ProtocolEncoder[10];
  uint8_T out[4];
  uint8_T temp[4];
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  for (i = 0; i < 10; i++) {
    rtb_ProtocolEncoder[i] = (uint8_T)0U;
  }

  rtb_ProtocolEncoder[0] = (uint8_T)1U;
  rtb_ProtocolEncoder[1] = (uint8_T)254U;
  rtb_ProtocolEncoder[2] = (uint8_T)144U;
  rtb_ProtocolEncoder[3] = (uint8_T)0U;
  temp[3] = (uint8_T)(localP->Constant2_Value & 255U);
  temp[2] = (uint8_T)(localP->Constant2_Value >> 8 & 255U);
  temp[1] = (uint8_T)(localP->Constant2_Value >> 16 & 255U);
  temp[0] = (uint8_T)(localP->Constant2_Value >> 24);
  for (i = 0; i < 4; i++) {
    out[i] = temp[i];
  }

  rtb_ProtocolEncoder[4] = out[0];
  rtb_ProtocolEncoder[5] = out[1];
  rtb_ProtocolEncoder[6] = out[2];
  rtb_ProtocolEncoder[7] = out[3];
  rtb_ProtocolEncoder[8] = localP->Constant4_Value;
  rtb_ProtocolEncoder[9] = localP->Constant5_Value;
  localB->CCaller1 = UDP_libUpdate(&rtd_UDP_PORT[0], &rtb_ProtocolEncoder[0],
    localC->Width);
}

void
  V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp__Term
  (DW_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp__T
   *localDW)
{
  if (!(int32_T)localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }
}

void EV_SLAC_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_Init
  (B_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_EV_SLAC_T *localB,
   P_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_EV_SLAC_T *localP)
{
  localB->CCaller1_o1 = localP->ret_Y0;
}

void EV_SLAC_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq(const
  EVSE_PAIRING *rtd_EVSE_PAIRING_SET, const iso1EXIDocument *rtd_ExiDoc_Buff,
  B_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_EV_SLAC_T *localB,
  P_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_EV_SLAC_T *localP)
{
  int32_T i;
  localB->BusAssignment_m = *rtd_ExiDoc_Buff;
  localB->BusAssignment4_h = localP->Constant13_Value;
  localB->BusAssignment4_h.size = (uint32_T)localP->Constant11_Value;
  localB->BusAssignment4_h.pos = (uint32_T)localP->Constant10_Value;
  repaireExiDocBuff(&localB->BusAssignment_m);
  localB->BusAssignment_m.V2G_Message.Header.SessionID =
    rtd_EVSE_PAIRING_SET->SessionID;
  localB->BusAssignment_m.V2G_Message.Body.AuthorizationReq_isUsed =
    localP->Constant4_Value;
  localB->BusAssignment_m.V2G_Message.Body.AuthorizationReq =
    localP->Constant5_Value;
  localB->BusAssignment_m.V2G_Message_isUsed = localP->Constant2_Value;
  localB->CCaller1_o2 = localB->BusAssignment4_h;
  localB->CCaller1_o1 = encode_iso1ExiDocument(&localB->CCaller1_o2,
    &localB->BusAssignment_m);
  snprintf(&localB->rtb_ComposeString_oj_m[0], 256U,
           "AuthorizationReq: status: %d", localB->CCaller1_o1);
  strncpy(&localB->cv[0], &localB->rtb_ComposeString_oj_m[0], 100U);
  for (i = 0; i < 100; i++) {
    localB->Cast1_hc[i] = (int8_T)(uint8_T)localB->cv[i];
  }

  slac_debug_ported(localP->CCaller_status, &localB->Cast1_hc[0]);
}

void
  EV_SLAC_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_Init
  (B_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_EV_SLAC_T
   *localB,
   P_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_EV_SLAC_T
   *localP)
{
  localB->CCaller1_o1 = localP->ret_Y0;
}

void EV_SLAC_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq(
  const EVSE_PAIRING *rtd_EVSE_PAIRING_SET, const iso1EXIDocument
  *rtd_ExiDoc_Buff,
  B_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_EV_SLAC_T *
  localB,
  P_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_EV_SLAC_T *
  localP)
{
  int32_T i;
  localB->BusAssignment11 = localP->Constant32_Value;
  localB->BusAssignment11.size = (uint32_T)localP->Constant7_Value;
  localB->BusAssignment11.pos = (uint32_T)localP->Constant6_Value;
  localB->BusAssignment_k = *rtd_ExiDoc_Buff;
  repaireExiDocBuff(&localB->BusAssignment_k);
  localB->BusAssignment_k.V2G_Message.Header.SessionID =
    rtd_EVSE_PAIRING_SET->SessionID;
  localB->BusAssignment1_e4 = localP->Constant8_Value;
  localB->BusAssignment1_e4.DepartureTime = localP->Constant10_Value;
  localB->BusAssignment1_e4.DepartureTime_isUsed = localP->Constant9_Value;
  localB->BusAssignment1_e4.DC_EVStatus.EVReady = (int32_T)
    localP->Constant30_Value;
  localB->BusAssignment1_e4.DC_EVStatus.EVErrorCode =
    localP->EnumeratedConstant6_Value;
  localB->BusAssignment1_e4.DC_EVStatus.EVRESSSOC = (int8_T)
    localP->Constant31_Value;
  localB->BusAssignment1_e4.EVMaximumCurrentLimit.Multiplier = (int8_T)
    localP->Constant28_Value;
  localB->BusAssignment1_e4.EVMaximumCurrentLimit.Unit =
    localP->EnumeratedConstant5_Value;
  localB->BusAssignment1_e4.EVMaximumCurrentLimit.Value = (int16_T)
    localP->Constant27_Value;
  localB->BusAssignment1_e4.EVMaximumPowerLimit.Multiplier = (int8_T)
    localP->Constant25_Value;
  localB->BusAssignment1_e4.EVMaximumPowerLimit.Unit =
    localP->EnumeratedConstant4_Value;
  localB->BusAssignment1_e4.EVMaximumPowerLimit.Value = (int16_T)
    localP->Constant24_Value;
  localB->BusAssignment1_e4.EVMaximumPowerLimit_isUsed =
    localP->Constant11_Value;
  localB->BusAssignment1_e4.EVMaximumVoltageLimit.Multiplier = (int8_T)
    localP->Constant22_Value;
  localB->BusAssignment1_e4.EVMaximumVoltageLimit.Unit =
    localP->EnumeratedConstant3_Value;
  localB->BusAssignment1_e4.EVMaximumVoltageLimit.Value = (int16_T)
    localP->Constant21_Value;
  localB->BusAssignment1_e4.EVEnergyCapacity.Multiplier = (int8_T)
    localP->Constant14_Value;
  localB->BusAssignment1_e4.EVEnergyCapacity.Unit =
    localP->EnumeratedConstant1_Value;
  localB->BusAssignment1_e4.EVEnergyCapacity.Value = (int16_T)
    localP->Constant13_Value;
  localB->BusAssignment1_e4.EVEnergyCapacity_isUsed = localP->Constant15_Value;
  localB->BusAssignment1_e4.EVEnergyRequest.Multiplier = (int8_T)
    localP->Constant18_Value;
  localB->BusAssignment1_e4.EVEnergyRequest.Unit =
    localP->EnumeratedConstant2_Value;
  localB->BusAssignment1_e4.EVEnergyRequest.Value = (int16_T)
    localP->Constant17_Value;
  localB->BusAssignment1_e4.EVEnergyRequest_isUsed = localP->Constant19_Value;
  localB->BusAssignment_k.V2G_Message.Body.ChargeParameterDiscoveryReq =
    localP->Constant5_Value;
  localB->BusAssignment_k.V2G_Message.Body.ChargeParameterDiscoveryReq.MaxEntriesSAScheduleTuple
    = (uint16_T)localP->Constant_Value;
  localB->BusAssignment_k.V2G_Message.Body.ChargeParameterDiscoveryReq.MaxEntriesSAScheduleTuple_isUsed
    = localP->Constant2_Value;
  localB->BusAssignment_k.V2G_Message.Body.ChargeParameterDiscoveryReq.RequestedEnergyTransferMode
    = localP->EnumeratedConstant_Value;
  localB->BusAssignment_k.V2G_Message.Body.ChargeParameterDiscoveryReq.EVChargeParameter_isUsed
    = localP->Constant1_Value;
  localB->BusAssignment_k.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter
    = localB->BusAssignment1_e4;
  localB->BusAssignment_k.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter_isUsed
    = localP->Constant3_Value;
  localB->BusAssignment_k.V2G_Message.Body.ChargeParameterDiscoveryReq_isUsed =
    localP->Constant33_Value;
  localB->BusAssignment_k.V2G_Message_isUsed = localP->Constant4_Value;
  localB->CCaller1_o2 = localB->BusAssignment11;
  localB->CCaller1_o1 = encode_iso1ExiDocument(&localB->CCaller1_o2,
    &localB->BusAssignment_k);
  snprintf(&localB->rtb_ComposeString_d_m[0], 256U,
           "Charge parameter Discovery: status: %d", localB->CCaller1_o1);
  strncpy(&localB->cv[0], &localB->rtb_ComposeString_d_m[0], 100U);
  for (i = 0; i < 100; i++) {
    localB->Cast1_f[i] = (int8_T)(uint8_T)localB->cv[i];
  }

  slac_debug_ported(localP->CCaller_status, &localB->Cast1_f[0]);
}

void EV_SLAC_EnabledSubsystem_Init(B_EnabledSubsystem_EV_SLAC_T *localB,
  P_EnabledSubsystem_EV_SLAC_T *localP)
{
  localB->Add = localP->Out1_Y0;
  localB->CastToSingle = localP->TimePoint_Y0;
}

void EV_SLAC_EnabledSubsystem(uint8_T rtu_Enable, const
  iso1RelativeTimeIntervalType *rtu_In1, B_EnabledSubsystem_EV_SLAC_T *localB)
{
  if ((int32_T)rtu_Enable > 0) {
    localB->CastToSingle = (real32_T)rtu_In1->start;
    if ((int32_T)rtu_In1->duration_isUsed > 0) {
      localB->Add = (real32_T)(rtu_In1->start + rtu_In1->duration);
    }
  }
}

void EV_SLAC_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_Init
  (B_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_EV_SLAC_T *localB,
   P_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_EV_SLAC_T *localP)
{
  localB->CCaller1_o1 = localP->ret_Y0;
}

void EV_SLAC_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq(const EVSE_PAIRING
  *rtd_EVSE_PAIRING_SET, const iso1EXIDocument *rtd_ExiDoc_Buff,
  B_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_EV_SLAC_T *localB,
  P_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_EV_SLAC_T *localP)
{
  int32_T i;
  localB->BusAssignment_j = *rtd_ExiDoc_Buff;
  localB->BusAssignment4_f = localP->Constant13_Value;
  localB->BusAssignment4_f.size = (uint32_T)localP->Constant11_Value;
  localB->BusAssignment4_f.pos = (uint32_T)localP->Constant10_Value;
  repaireExiDocBuff(&localB->BusAssignment_j);
  localB->BusAssignment_j.V2G_Message.Header.SessionID =
    rtd_EVSE_PAIRING_SET->SessionID;
  localB->BusAssignment_j.V2G_Message.Body.CableCheckReq_isUsed =
    localP->Constant4_Value;
  localB->BusAssignment_j.V2G_Message.Body.CableCheckReq.DC_EVStatus.EVReady =
    (int32_T)localP->Constant30_Value;
  localB->BusAssignment_j.V2G_Message.Body.CableCheckReq.DC_EVStatus.EVErrorCode
    = localP->EnumeratedConstant6_Value;
  localB->BusAssignment_j.V2G_Message.Body.CableCheckReq.DC_EVStatus.EVRESSSOC =
    (int8_T)localP->Constant31_Value;
  localB->BusAssignment_j.V2G_Message_isUsed = localP->Constant1_Value;
  localB->CCaller1_o2 = localB->BusAssignment4_f;
  localB->CCaller1_o1 = encode_iso1ExiDocument(&localB->CCaller1_o2,
    &localB->BusAssignment_j);
  snprintf(&localB->rtb_ComposeString_m_m[0], 256U, "CableCheckReq: status: %d",
           localB->CCaller1_o1);
  strncpy(&localB->cv[0], &localB->rtb_ComposeString_m_m[0], 100U);
  for (i = 0; i < 100; i++) {
    localB->Cast1_e[i] = (int8_T)(uint8_T)localB->cv[i];
  }

  slac_debug_ported(localP->CCaller_status, &localB->Cast1_e[0]);
}

void EV_SLAC_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_Init
  (B_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_EV_SLAC_T *localB,
   P_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_EV_SLAC_T *localP)
{
  localB->CCaller1_o1 = localP->ret_Y0;
}

void EV_SLAC_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq(const EVSE_PAIRING
  *rtd_EVSE_PAIRING_SET, const iso1EXIDocument *rtd_ExiDoc_Buff,
  B_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_EV_SLAC_T *localB,
  P_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_EV_SLAC_T *localP)
{
  int32_T i;
  localB->BusAssignment_d = *rtd_ExiDoc_Buff;
  localB->BusAssignment4_g = localP->Constant13_Value;
  localB->BusAssignment4_g.size = (uint32_T)localP->Constant11_Value;
  localB->BusAssignment4_g.pos = (uint32_T)localP->Constant10_Value;
  repaireExiDocBuff(&localB->BusAssignment_d);
  localB->BusAssignment_d.V2G_Message.Header.SessionID =
    rtd_EVSE_PAIRING_SET->SessionID;
  localB->BusAssignment_d.V2G_Message.Body.PreChargeReq_isUsed =
    localP->Constant4_Value;
  localB->BusAssignment_d.V2G_Message.Body.PreChargeReq.DC_EVStatus.EVReady =
    (int32_T)localP->Constant30_Value;
  localB->BusAssignment_d.V2G_Message.Body.PreChargeReq.DC_EVStatus.EVErrorCode =
    localP->EnumeratedConstant6_Value;
  localB->BusAssignment_d.V2G_Message.Body.PreChargeReq.DC_EVStatus.EVRESSSOC =
    (int8_T)localP->Constant31_Value;
  localB->BusAssignment_d.V2G_Message.Body.PreChargeReq.EVTargetVoltage.Multiplier
    = (int8_T)localP->Constant22_Value;
  localB->BusAssignment_d.V2G_Message.Body.PreChargeReq.EVTargetVoltage.Unit =
    localP->EnumeratedConstant3_Value;
  localB->BusAssignment_d.V2G_Message.Body.PreChargeReq.EVTargetVoltage.Value =
    (int16_T)localP->Constant21_Value;
  localB->BusAssignment_d.V2G_Message.Body.PreChargeReq.EVTargetCurrent.Multiplier
    = (int8_T)localP->Constant28_Value;
  localB->BusAssignment_d.V2G_Message.Body.PreChargeReq.EVTargetCurrent.Unit =
    localP->EnumeratedConstant5_Value;
  localB->BusAssignment_d.V2G_Message.Body.PreChargeReq.EVTargetCurrent.Value =
    (int16_T)localP->Constant27_Value;
  localB->BusAssignment_d.V2G_Message_isUsed = localP->Constant1_Value;
  localB->CCaller1_o2 = localB->BusAssignment4_g;
  localB->CCaller1_o1 = encode_iso1ExiDocument(&localB->CCaller1_o2,
    &localB->BusAssignment_d);
  snprintf(&localB->rtb_ComposeString_ly_m[0], 256U,
           "PreCharge request: status: %d", localB->CCaller1_o1);
  strncpy(&localB->cv[0], &localB->rtb_ComposeString_ly_m[0], 100U);
  for (i = 0; i < 100; i++) {
    localB->Cast1_i[i] = (int8_T)(uint8_T)localB->cv[i];
  }

  slac_debug_ported(localP->CCaller_status, &localB->Cast1_i[0]);
}

void EV_SLAC_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy
  (B_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy_EV_SLAC_T *localB,
   P_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy_EV_SLAC_T *localP)
{
  int32_T i;
  char_T tmp[50];
  strncpy(&tmp[0], &localP->StringConstant1_String[0], 50U);
  for (i = 0; i < 50; i++) {
    localB->Cast_m[i] = (int8_T)(uint8_T)tmp[i];
  }

  slac_debug_ported(localP->CCaller_status, &localB->Cast_m[0]);
}

void EV_SLAC_ProtocolEncoder_Init(DW_ProtocolEncoder_EV_SLAC_T *localDW)
{
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;
}

void EV_SLAC_ProtocolEncoder(uint32_T rtu_0, B_ProtocolEncoder_EV_SLAC_T *localB,
  DW_ProtocolEncoder_EV_SLAC_T *localDW)
{
  int32_T i;
  uint8_T tmp[8];
  uint8_T out[4];
  uint8_T temp[4];
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  tmp[0] = (uint8_T)1U;
  tmp[1] = (uint8_T)254U;
  tmp[2] = (uint8_T)128U;
  tmp[3] = (uint8_T)1U;
  temp[3] = (uint8_T)(rtu_0 & 255U);
  temp[2] = (uint8_T)(rtu_0 >> 8 & 255U);
  temp[1] = (uint8_T)(rtu_0 >> 16 & 255U);
  temp[0] = (uint8_T)(rtu_0 >> 24);
  for (i = 0; i < 4; i++) {
    out[i] = temp[i];
  }

  tmp[4] = out[0];
  tmp[5] = out[1];
  tmp[6] = out[2];
  tmp[7] = out[3];
  for (i = 0; i < 8; i++) {
    localB->ProtocolEncoder[i] = tmp[i];
  }
}

void EV_SLAC_ProtocolEncoder_Term(DW_ProtocolEncoder_EV_SLAC_T *localDW)
{
  if (!(int32_T)localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }
}

void EV_SLAC_ProtocolDecoder_Init(DW_ProtocolDecoder_EV_SLAC_T *localDW)
{
  int32_T i;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  for (i = 0; i < 8; i++) {
    localDW->obj.DataBuffer[i] = (uint8_T)0U;
  }

  localDW->obj.PrevOutCellArray.f1 = 0U;
  localDW->obj.PrevOutCellArray.f2 = false;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;
}

void EV_SLAC_ProtocolDecoder(const uint8_T rtu_0[8], B_ProtocolDecoder_EV_SLAC_T
  *localB, DW_ProtocolDecoder_EV_SLAC_T *localDW)
{
  int32_T i;
  uint16_T payloadLength;
  uint8_T inData[8];
  uint8_T header[4];
  uint8_T payload[4];
  uint8_T status;
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  for (i = 0; i < 8; i++) {
    inData[i] = rtu_0[i];
  }

  uint8_T terminator;
  header[0] = (uint8_T)1U;
  header[1] = (uint8_T)254U;
  header[2] = (uint8_T)128U;
  header[3] = (uint8_T)1U;
  terminator = (uint8_T)0U;
  status = readPacket(&inData[0], 8, &header[0], 4, &terminator, 0, false, 4, 4,
                      &localDW->obj.DataBuffer[0], &payload[0], &payloadLength);
  if ((int32_T)status != 0) {
    int32_T d;
    uint32_T temp;
    temp = (uint32_T)(int32_T)payloadLength + 1U;
    if ((uint32_T)(int32_T)payloadLength + 1U > 65535U) {
      temp = 65535U;
    }

    if ((int32_T)(uint16_T)temp > 4) {
      d = 0;
      i = 0;
    } else {
      d = (int32_T)(uint16_T)temp - 1;
      i = 4;
    }

    i -= d;
    if (i - 1 >= 0) {
      memset(&payload[d], 0, (uint32_T)((i + d) - d) * sizeof(uint8_T));
    }

    temp = (uint32_T)payload[0] << 24 | (uint32_T)payload[1] << 16 | (uint32_T)
      payload[2] << 8 | (uint32_T)(int32_T)payload[3];
    localB->ProtocolDecoder_o1 = temp;
    localB->ProtocolDecoder_o2 = true;
    localDW->obj.PrevOutCellArray.f1 = temp;
    localDW->obj.PrevOutCellArray.f2 = false;
  } else {
    localB->ProtocolDecoder_o1 = localDW->obj.PrevOutCellArray.f1;
    localB->ProtocolDecoder_o2 = localDW->obj.PrevOutCellArray.f2;
  }
}

void EV_SLAC_ProtocolDecoder_Term(DW_ProtocolDecoder_EV_SLAC_T *localDW)
{
  if (!(int32_T)localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }
}

static void EV_SLAC_initialize_msg_local_queues_for_chart(void)
{
  EV_SLAC_initQueue_i(&EV_SLAC_DW.Queue_0[0], MSG_FIFO_QUEUE, 3,
                      &EV_SLAC_DW.Msg_0[1]);
  EV_SLAC_initQueue_i(&EV_SLAC_DW.Queue_0[1], MSG_FIFO_QUEUE, 3,
                      &EV_SLAC_DW.Msg_0[4]);
  EV_SLAC_initQueue(&EV_SLAC_DW.Queue[0], MSG_FIFO_QUEUE, 1, &EV_SLAC_DW.Msg[1]);
  EV_SLAC_initQueue(&EV_SLAC_DW.Queue[1], MSG_FIFO_QUEUE, 1, &EV_SLAC_DW.Msg[2]);
}

static void EV_SLAC_eml_rand_mt19937ar(uint32_T state[625])
{
  EV_SLAC_B.r_a = 5489U;
  state[0] = 5489U;
  for (EV_SLAC_B.b_mti = 0; EV_SLAC_B.b_mti < 623; EV_SLAC_B.b_mti++) {
    EV_SLAC_B.r_a = ((EV_SLAC_B.r_a >> 30U ^ EV_SLAC_B.r_a) * 1812433253U +
                     (uint32_T)EV_SLAC_B.b_mti) + 1U;
    state[EV_SLAC_B.b_mti + 1] = EV_SLAC_B.r_a;
  }

  state[624] = 624U;
}

static void EV_SLAC_rng(real_T varargin_1, uint32_T *state_d)
{
  int32_T t;
  uint32_T r;
  if (varargin_1 < 4.294967296E+9) {
    if (varargin_1 >= 0.0) {
      *state_d = (uint32_T)varargin_1;
    } else {
      *state_d = 0U;
    }
  } else {
    *state_d = MAX_uint32_T;
  }

  if (EV_SLAC_DW.method_h == 7U) {
    if (*state_d == 0U) {
      *state_d = 5489U;
    }

    if (!(int32_T)EV_SLAC_DW.seed_not_empty) {
      EV_SLAC_eml_rand_mt19937ar(EV_SLAC_DW.state_g);
      EV_SLAC_DW.seed_not_empty = true;
    }

    r = *state_d;
    EV_SLAC_DW.state_g[0] = *state_d;
    for (t = 0; t < 623; t++) {
      r = ((r >> 30U ^ r) * 1812433253U + (uint32_T)t) + 1U;
      EV_SLAC_DW.state_g[t + 1] = r;
    }

    EV_SLAC_DW.state_g[624] = 624U;
  } else if (EV_SLAC_DW.method_h == 5U) {
    EV_SLAC_DW.state_f[0] = 362436069U;
    EV_SLAC_DW.state_f[1] = *state_d;
    if (EV_SLAC_DW.state_f[1] == 0U) {
      EV_SLAC_DW.state_f[1] = 521288629U;
    }
  } else {
    r = *state_d >> 16U;
    t = (int32_T)(*state_d & 32768U);
    r += (((*state_d - (r << 16U)) - (uint32_T)t) << 16U) + (uint32_T)t;
    if (r < 1U) {
      r = 1144108930U;
    } else if (r > 2147483646U) {
      r = 2147483646U;
    }

    EV_SLAC_DW.seed = r;
  }
}

static void EV_SLAC_SystemCore_setup
  (matlabshared_embedded_utilities_blocks_ProtocolDecoderBlock_EV_SLAC_k_T *obj)
{
  obj->isInitialized = 1;
  memset(&obj->DataBuffer[0], 0, 28U * sizeof(uint8_T));
  obj->PrevOutCellArray.f1 = 0U;
  memset(&obj->PrevOutCellArray.f2[0], 0, sizeof(uint8_T) << 4U);
  obj->PrevOutCellArray.f3 = (uint16_T)0U;
  obj->PrevOutCellArray.f4 = (uint8_T)0U;
  obj->PrevOutCellArray.f5 = (uint8_T)0U;
  obj->PrevOutCellArray.f6 = false;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

static void EV_SLAC_sf_msg_send_ActiveTcpLoop(void)
{
  EV_SLAC_emplace(&EV_SLAC_DW.Queue[0],
                  &EV_SLAC_DW.ActiveTcpLoop_msgReservedData);
}

static boolean_T EV_SLAC_sf_msg_pop_StreamMesgIn(void)
{
  boolean_T isPresent;
  if (EV_SLAC_DW.StreamMesgIn_isValid) {
    isPresent = true;
  } else {
    if (EV_SLAC_pop_k(&EV_SLAC_DW.Queue_0[1], &EV_SLAC_DW.Msg_0[0])) {
      EV_SLAC_DW.StreamMesgIn_msgHandle = &EV_SLAC_DW.Msg_0[0];
    } else {
      EV_SLAC_DW.StreamMesgIn_msgHandle = NULL;
    }

    if (EV_SLAC_DW.StreamMesgIn_msgHandle != NULL) {
      EV_SLAC_DW.StreamMesgIn_msgDataPtr = ((Msg_bitstream_t *)
        EV_SLAC_DW.StreamMesgIn_msgHandle)->fData;
      isPresent = true;
      EV_SLAC_DW.StreamMesgIn_msgReservedData = *(bitstream_t *)
        EV_SLAC_DW.StreamMesgIn_msgDataPtr;
      EV_SLAC_DW.StreamMesgIn_isValid = true;
    } else {
      isPresent = false;
    }
  }

  return isPresent;
}

static void EV_SLAC_sf_msg_send_StreamMesgOut(void)
{
  EV_SLAC_emplace_n(&EV_SLAC_DW.Queue_0[0],
                    &EV_SLAC_DW.StreamMesgOut_msgReservedData);
}

static uint16_T EV_SLAC_ProtocolDecoderBase_bytePacker(const uint8_T inData[24])
{
  return (uint16_T)((int32_T)inData[20] << 8 | (int32_T)inData[21]);
}

static real_T EV_SLAC_rand_d(void)
{
  real_T r;
  if (EV_SLAC_DW.method == 4U) {
    EV_SLAC_B.y = EV_SLAC_DW.state / 127773U;
    EV_SLAC_B.r_o = (EV_SLAC_DW.state - EV_SLAC_B.y * 127773U) * 16807U;
    EV_SLAC_B.y *= 2836U;
    if (EV_SLAC_B.r_o < EV_SLAC_B.y) {
      EV_SLAC_B.r_o = ~(EV_SLAC_B.y - EV_SLAC_B.r_o) & 2147483647U;
    } else {
      EV_SLAC_B.r_o -= EV_SLAC_B.y;
    }

    r = (real_T)EV_SLAC_B.r_o * 4.6566128752457969E-10;
    EV_SLAC_DW.state = EV_SLAC_B.r_o;
  } else if (EV_SLAC_DW.method == 5U) {
    EV_SLAC_B.r_o = 69069U * EV_SLAC_DW.state_a[0] + 1234567U;
    EV_SLAC_B.y = EV_SLAC_DW.state_a[1] << 13 ^ EV_SLAC_DW.state_a[1];
    EV_SLAC_B.y ^= EV_SLAC_B.y >> 17;
    EV_SLAC_B.y ^= EV_SLAC_B.y << 5;
    EV_SLAC_DW.state_a[0] = EV_SLAC_B.r_o;
    EV_SLAC_DW.state_a[1] = EV_SLAC_B.y;
    r = (real_T)(EV_SLAC_B.r_o + EV_SLAC_B.y) * 2.328306436538696E-10;
  } else {
    if (!(int32_T)EV_SLAC_DW.state_not_empty_n) {
      memset(&EV_SLAC_DW.state_c[0], 0, 625U * sizeof(uint32_T));
      EV_SLAC_B.r_o = 5489U;
      EV_SLAC_DW.state_c[0] = 5489U;
      for (EV_SLAC_B.i_c = 0; EV_SLAC_B.i_c < 623; EV_SLAC_B.i_c++) {
        EV_SLAC_B.r_o = ((EV_SLAC_B.r_o >> 30U ^ EV_SLAC_B.r_o) * 1812433253U +
                         (uint32_T)EV_SLAC_B.i_c) + 1U;
        EV_SLAC_DW.state_c[EV_SLAC_B.i_c + 1] = EV_SLAC_B.r_o;
      }

      EV_SLAC_DW.state_c[624] = 624U;
      EV_SLAC_DW.state_not_empty_n = true;
    }

    memcpy(&EV_SLAC_B.c_mt[0], &EV_SLAC_DW.state_c[0], 625U * sizeof(uint32_T));

    /* ========================= COPYRIGHT NOTICE ============================ */
    /*  This is a uniform (0,1) pseudorandom number generator based on:        */
    /*                                                                         */
    /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
    /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
    /*                                                                         */
    /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
    /*  All rights reserved.                                                   */
    /*                                                                         */
    /*  Redistribution and use in source and binary forms, with or without     */
    /*  modification, are permitted provided that the following conditions     */
    /*  are met:                                                               */
    /*                                                                         */
    /*    1. Redistributions of source code must retain the above copyright    */
    /*       notice, this list of conditions and the following disclaimer.     */
    /*                                                                         */
    /*    2. Redistributions in binary form must reproduce the above copyright */
    /*       notice, this list of conditions and the following disclaimer      */
    /*       in the documentation and/or other materials provided with the     */
    /*       distribution.                                                     */
    /*                                                                         */
    /*    3. The names of its contributors may not be used to endorse or       */
    /*       promote products derived from this software without specific      */
    /*       prior written permission.                                         */
    /*                                                                         */
    /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
    /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
    /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
    /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
    /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
    /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
    /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
    /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
    /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
    /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
    /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
    /*                                                                         */
    /* =============================   END   ================================= */
    int32_T exitg1;
    do {
      exitg1 = 0;
      for (EV_SLAC_B.i_c = 0; EV_SLAC_B.i_c < 2; EV_SLAC_B.i_c++) {
        EV_SLAC_B.r_o = EV_SLAC_B.c_mt[624] + 1U;
        if (EV_SLAC_B.c_mt[624] + 1U >= 625U) {
          for (EV_SLAC_B.b_kk = 0; EV_SLAC_B.b_kk < 227; EV_SLAC_B.b_kk++) {
            EV_SLAC_B.y = (EV_SLAC_B.c_mt[EV_SLAC_B.b_kk + 1] & 2147483647U) |
              (EV_SLAC_B.c_mt[EV_SLAC_B.b_kk] & 2147483648U);
            if ((EV_SLAC_B.y & 1U) == 0U) {
              EV_SLAC_B.r_o = EV_SLAC_B.y >> 1U;
            } else {
              EV_SLAC_B.r_o = EV_SLAC_B.y >> 1U ^ 2567483615U;
            }

            EV_SLAC_B.c_mt[EV_SLAC_B.b_kk] = EV_SLAC_B.c_mt[EV_SLAC_B.b_kk + 397]
              ^ EV_SLAC_B.r_o;
          }

          for (EV_SLAC_B.b_kk = 0; EV_SLAC_B.b_kk < 396; EV_SLAC_B.b_kk++) {
            EV_SLAC_B.y = (EV_SLAC_B.c_mt[EV_SLAC_B.b_kk + 227] & 2147483648U) |
              (EV_SLAC_B.c_mt[EV_SLAC_B.b_kk + 228] & 2147483647U);
            if ((EV_SLAC_B.y & 1U) == 0U) {
              EV_SLAC_B.r_o = EV_SLAC_B.y >> 1U;
            } else {
              EV_SLAC_B.r_o = EV_SLAC_B.y >> 1U ^ 2567483615U;
            }

            EV_SLAC_B.c_mt[EV_SLAC_B.b_kk + 227] = EV_SLAC_B.c_mt[EV_SLAC_B.b_kk]
              ^ EV_SLAC_B.r_o;
          }

          EV_SLAC_B.y = (EV_SLAC_B.c_mt[623] & 2147483648U) | (EV_SLAC_B.c_mt[0]
            & 2147483647U);
          if ((EV_SLAC_B.y & 1U) == 0U) {
            EV_SLAC_B.r_o = EV_SLAC_B.y >> 1U;
          } else {
            EV_SLAC_B.r_o = EV_SLAC_B.y >> 1U ^ 2567483615U;
          }

          EV_SLAC_B.c_mt[623] = EV_SLAC_B.c_mt[396] ^ EV_SLAC_B.r_o;
          EV_SLAC_B.r_o = 1U;
        }

        EV_SLAC_B.y = EV_SLAC_B.c_mt[(int32_T)EV_SLAC_B.r_o - 1];
        EV_SLAC_B.c_mt[624] = EV_SLAC_B.r_o;
        EV_SLAC_B.y ^= EV_SLAC_B.y >> 11U;
        EV_SLAC_B.y ^= EV_SLAC_B.y << 7U & 2636928640U;
        EV_SLAC_B.y ^= EV_SLAC_B.y << 15U & 4022730752U;
        EV_SLAC_B.b_u[EV_SLAC_B.i_c] = EV_SLAC_B.y >> 18U ^ EV_SLAC_B.y;
      }

      r = ((real_T)(EV_SLAC_B.b_u[0] >> 5U) * 6.7108864E+7 + (real_T)
           (EV_SLAC_B.b_u[1] >> 6U)) * 1.1102230246251565E-16;
      if (r == 0.0) {
        if ((EV_SLAC_B.c_mt[624] >= 1U) && (EV_SLAC_B.c_mt[624] < 625U)) {
          boolean_T exitg2;
          EV_SLAC_B.b_isvalid = false;
          EV_SLAC_B.i_c = 0;
          exitg2 = false;
          while ((!exitg2) && (EV_SLAC_B.i_c + 1 < 625)) {
            if (EV_SLAC_B.c_mt[EV_SLAC_B.i_c] == 0U) {
              EV_SLAC_B.i_c++;
            } else {
              EV_SLAC_B.b_isvalid = true;
              exitg2 = true;
            }
          }
        } else {
          EV_SLAC_B.b_isvalid = false;
        }

        if (!(int32_T)EV_SLAC_B.b_isvalid) {
          EV_SLAC_B.r_o = 5489U;
          EV_SLAC_B.c_mt[0] = 5489U;
          for (EV_SLAC_B.i_c = 0; EV_SLAC_B.i_c < 623; EV_SLAC_B.i_c++) {
            EV_SLAC_B.r_o = ((EV_SLAC_B.r_o >> 30U ^ EV_SLAC_B.r_o) *
                             1812433253U + (uint32_T)EV_SLAC_B.i_c) + 1U;
            EV_SLAC_B.c_mt[EV_SLAC_B.i_c + 1] = EV_SLAC_B.r_o;
          }

          EV_SLAC_B.c_mt[624] = 624U;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    memcpy(&EV_SLAC_DW.state_c[0], &EV_SLAC_B.c_mt[0], 625U * sizeof(uint32_T));
  }

  return r;
}

static void EV_SLAC_SDP(void)
{
  boolean_T guard1;
  if ((int32_T)EV_SLAC_DW.is_SDP == (int32_T)
      EV_SLAC_IN_V2G2_016_IP_ADD_ASSIGMENT) {
    if ((int32_T)EV_SLAC_DW.is_V2G2_016_IP_ADD_ASSIGMENT == (int32_T)
        EV_SLAC_IN_BINDING) {
      switch (EV_SLAC_DW.ret) {
       case 0:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_V2G2_016_IP_ADD_ASSIGMENT = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_k = 3U;
        break;

       case 1:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_V2G2_016_IP_ADD_ASSIGMENT = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_k = 2U;
        break;
      }
    } else {
      switch (EV_SLAC_DW.ret) {
       case 0:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_V2G2_016_IP_ADD_ASSIGMENT = EV_SLAC_IN_BINDING;
        EV_SLAC_DW.ret = UDP_libStart(&EV_SLAC_SharedDSM.UDP_PORT[0]);
        break;

       case 1:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_V2G2_016_IP_ADD_ASSIGMENT = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_k = 2U;
        break;
      }
    }

    switch (EV_SLAC_DW.exitPortIndex_k) {
     case 2:
      EV_SLAC_DW.exitPortIndex_k = 0U;
      EV_SLAC_DW.is_SDP = EV_SLAC_IN_NO_ACTIVE_CHILD;
      EV_SLAC_DW.exitPortIndex_a = 2U;
      break;

     case 3:
      EV_SLAC_DW.exitPortIndex_k = 0U;
      EV_SLAC_DW.is_SDP = EV_SLAC_IN_V2G2_019_V2G2_645_SECC_DISCOVERY;
      EV_SLAC_DW.is_V2G2_019_V2G2_645_SECC_DISCOVERY = EV_SLAC_IN_SDP_REQ;
      E_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req
        (EV_SLAC_SharedDSM.UDP_PORT,
         &EV_SLAC_B.V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req,
         &EV_SLAC_ConstB.V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req,
         &EV_SLAC_DW.V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req,
         &EV_SLAC_P.V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req);
      EV_SLAC_DW.ret =
        EV_SLAC_B.V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req.CCaller1;
      break;
    }
  } else {
    if ((int32_T)EV_SLAC_DW.is_V2G2_019_V2G2_645_SECC_DISCOVERY == (int32_T)
        EV_SLAC_IN_SDP_REQ) {
      switch (EV_SLAC_DW.ret) {
       case 0:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.temporalCounter_i1 = 0.0;
        EV_SLAC_DW.is_V2G2_019_V2G2_645_SECC_DISCOVERY = EV_SLAC_IN_SDP_RES;
        memcpy(&EV_SLAC_B.CCaller2_o2_e[0], &EV_SLAC_SharedDSM.Buffer_received[0],
               30U * sizeof(uint8_T));
        EV_SLAC_B.CCaller2_o1_j = UDP_libOutputs(&EV_SLAC_SharedDSM.UDP_PORT[0],
          &EV_SLAC_B.CCaller2_o2_e[0], &EV_SLAC_P.Constant6_Value_p);
        if (EV_SLAC_DW.obj.TunablePropsChanged) {
          EV_SLAC_DW.obj.TunablePropsChanged = false;
        }

        EV_SLAC_B.header[0] = (uint8_T)1U;
        EV_SLAC_B.header[1] = (uint8_T)254U;
        EV_SLAC_B.header[2] = (uint8_T)144U;
        EV_SLAC_B.header[3] = (uint8_T)1U;
        EV_SLAC_B.terminator = (uint8_T)0U;
        EV_SLAC_B.status = readPacket(&EV_SLAC_B.CCaller2_o2_e[0], 30,
          &EV_SLAC_B.header[0], 4, &EV_SLAC_B.terminator, 0, false, 24, 24,
          &EV_SLAC_DW.obj.DataBuffer[0], &EV_SLAC_B.payload[0],
          &EV_SLAC_B.payloadLength);
        if ((int32_T)EV_SLAC_B.status != 0) {
          EV_SLAC_B.u1 = (uint32_T)(int32_T)EV_SLAC_B.payloadLength + 1U;
          if (EV_SLAC_B.u1 > 65535U) {
            EV_SLAC_B.u1 = 65535U;
          }

          EV_SLAC_B.payloadLength = (uint16_T)EV_SLAC_B.u1;
          if ((int32_T)EV_SLAC_B.payloadLength > 24) {
            EV_SLAC_B.i_h = 0;
            EV_SLAC_B.c = 0;
          } else {
            EV_SLAC_B.i_h = (int32_T)EV_SLAC_B.payloadLength - 1;
            EV_SLAC_B.c = 24;
          }

          EV_SLAC_B.c -= EV_SLAC_B.i_h;
          if (EV_SLAC_B.c - 1 >= 0) {
            memset(&EV_SLAC_B.payload[EV_SLAC_B.i_h], 0, (uint32_T)((EV_SLAC_B.c
                     + EV_SLAC_B.i_h) - EV_SLAC_B.i_h) * sizeof(uint8_T));
          }

          EV_SLAC_B.isValid = true;
          EV_SLAC_B.temp = (uint32_T)EV_SLAC_B.payload[0] << 24 | (uint32_T)
            EV_SLAC_B.payload[1] << 16 | (uint32_T)EV_SLAC_B.payload[2] << 8 |
            (uint32_T)(int32_T)EV_SLAC_B.payload[3];
          EV_SLAC_B.payloadLength = (uint16_T)1U;
          memset(&EV_SLAC_B.b_varargout_2[0], 0, sizeof(uint8_T) << 4U);
          for (EV_SLAC_B.inDataIdx = 5; EV_SLAC_B.inDataIdx < 21;
               EV_SLAC_B.inDataIdx++) {
            EV_SLAC_B.i_h = (int32_T)EV_SLAC_B.inDataIdx;
            if ((uint32_T)(int32_T)EV_SLAC_B.inDataIdx > (uint32_T)(int32_T)
                EV_SLAC_B.inDataIdx + 1U) {
              EV_SLAC_B.i_h = 0;
            }

            if ((int32_T)EV_SLAC_B.inDataIdx > EV_SLAC_B.i_h) {
              EV_SLAC_B.c = 1;
            } else {
              EV_SLAC_B.c = (int32_T)EV_SLAC_B.inDataIdx;
            }

            EV_SLAC_B.b_varargout_2[(int32_T)EV_SLAC_B.payloadLength - 1] =
              EV_SLAC_B.payload[EV_SLAC_B.c - 1];
            EV_SLAC_B.u1 = (uint32_T)(int32_T)EV_SLAC_B.payloadLength + 1U;
            if (EV_SLAC_B.u1 > 65535U) {
              EV_SLAC_B.u1 = 65535U;
            }

            EV_SLAC_B.payloadLength = (uint16_T)EV_SLAC_B.u1;
          }

          EV_SLAC_B.payloadLength = EV_SLAC_ProtocolDecoderBase_bytePacker
            (EV_SLAC_B.payload);
          EV_SLAC_B.terminator = EV_SLAC_B.payload[22];
          EV_SLAC_B.status = EV_SLAC_B.payload[23];
          EV_SLAC_DW.obj.PrevOutCellArray.f1 = EV_SLAC_B.temp;
          memcpy(&EV_SLAC_DW.obj.PrevOutCellArray.f2[0],
                 &EV_SLAC_B.b_varargout_2[0], sizeof(uint8_T) << 4U);
          EV_SLAC_DW.obj.PrevOutCellArray.f3 = EV_SLAC_B.payloadLength;
          EV_SLAC_DW.obj.PrevOutCellArray.f4 = EV_SLAC_B.payload[22];
          EV_SLAC_DW.obj.PrevOutCellArray.f5 = EV_SLAC_B.payload[23];
          EV_SLAC_DW.obj.PrevOutCellArray.f6 = false;
        } else {
          EV_SLAC_B.temp = EV_SLAC_DW.obj.PrevOutCellArray.f1;
          memcpy(&EV_SLAC_B.b_varargout_2[0],
                 &EV_SLAC_DW.obj.PrevOutCellArray.f2[0], sizeof(uint8_T) << 4U);
          EV_SLAC_B.payloadLength = EV_SLAC_DW.obj.PrevOutCellArray.f3;
          EV_SLAC_B.terminator = EV_SLAC_DW.obj.PrevOutCellArray.f4;
          EV_SLAC_B.status = EV_SLAC_DW.obj.PrevOutCellArray.f5;
          EV_SLAC_B.isValid = EV_SLAC_DW.obj.PrevOutCellArray.f6;
        }

        sdpMesg_res_bus = EV_SLAC_SharedDSM.sdpMesg_res;
        sdpMesg_res_bus.mHeader.payloadLen = EV_SLAC_B.temp;
        memcpy(&sdpMesg_res_bus.mPayload.u6_addr8[0], &EV_SLAC_B.b_varargout_2[0],
               sizeof(uint8_T) << 4U);
        sdpMesg_res_bus.mPayload.port = EV_SLAC_B.payloadLength;
        sdpMesg_res_bus.mPayload.Sec = EV_SLAC_B.terminator;
        sdpMesg_res_bus.mPayload.transportProtocol = EV_SLAC_B.status;
        EV_SLAC_SharedDSM.sdpMesg_res = sdpMesg_res_bus;
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[0],
          &EV_SLAC_B.sf_MATLABFunction);
        EV_SLAC_B.rtb_ASCIItoString_g4_l[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction.y[0];
        EV_SLAC_B.rtb_ASCIItoString_g4_l[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_g4_l[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[1],
          &EV_SLAC_B.sf_MATLABFunction_c);
        EV_SLAC_B.rtb_ASCIItoString_e4_j[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_c.y[0];
        EV_SLAC_B.rtb_ASCIItoString_e4_j[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_c.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_e4_j[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[2],
          &EV_SLAC_B.sf_MATLABFunction_a);
        EV_SLAC_B.rtb_ASCIItoString_aj_d[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_a.y[0];
        EV_SLAC_B.rtb_ASCIItoString_aj_d[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_a.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_aj_d[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[3],
          &EV_SLAC_B.sf_MATLABFunction_iq);
        EV_SLAC_B.rtb_ASCIItoString_pr_g[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_iq.y[0];
        EV_SLAC_B.rtb_ASCIItoString_pr_g[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_iq.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_pr_g[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[4],
          &EV_SLAC_B.sf_MATLABFunction_g);
        EV_SLAC_B.rtb_ASCIItoString_m5_l[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_g.y[0];
        EV_SLAC_B.rtb_ASCIItoString_m5_l[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_g.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_m5_l[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[5],
          &EV_SLAC_B.sf_MATLABFunction_hf);
        EV_SLAC_B.rtb_ASCIItoString_nn_d[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_hf.y[0];
        EV_SLAC_B.rtb_ASCIItoString_nn_d[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_hf.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_nn_d[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[6],
          &EV_SLAC_B.sf_MATLABFunction_n);
        EV_SLAC_B.rtb_ASCIItoString_e1_d[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_n.y[0];
        EV_SLAC_B.rtb_ASCIItoString_e1_d[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_n.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_e1_d[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[7],
          &EV_SLAC_B.sf_MATLABFunction_b);
        EV_SLAC_B.rtb_ASCIItoString_al_l[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_b.y[0];
        EV_SLAC_B.rtb_ASCIItoString_al_l[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_b.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_al_l[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[8],
          &EV_SLAC_B.sf_MATLABFunction_ez);
        EV_SLAC_B.rtb_ASCIItoString_pm_o[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_ez.y[0];
        EV_SLAC_B.rtb_ASCIItoString_pm_o[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_ez.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_pm_o[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[9],
          &EV_SLAC_B.sf_MATLABFunction_p);
        EV_SLAC_B.rtb_ASCIItoString_p4_b[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_p.y[0];
        EV_SLAC_B.rtb_ASCIItoString_p4_b[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_p.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_p4_b[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[10],
          &EV_SLAC_B.sf_MATLABFunction_h);
        EV_SLAC_B.rtb_ASCIItoString_fc_n[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_h.y[0];
        EV_SLAC_B.rtb_ASCIItoString_fc_n[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_h.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_fc_n[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[11],
          &EV_SLAC_B.sf_MATLABFunction_e);
        EV_SLAC_B.rtb_ASCIItoString_ev_b[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_e.y[0];
        EV_SLAC_B.rtb_ASCIItoString_ev_b[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_e.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_ev_b[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[12],
          &EV_SLAC_B.sf_MATLABFunction_d);
        EV_SLAC_B.rtb_ASCIItoString_cj3_l[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_d.y[0];
        EV_SLAC_B.rtb_ASCIItoString_cj3_l[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_d.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_cj3_l[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[13],
          &EV_SLAC_B.sf_MATLABFunction_j);
        EV_SLAC_B.rtb_ASCIItoString_lat_h[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_j.y[0];
        EV_SLAC_B.rtb_ASCIItoString_lat_h[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_j.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_lat_h[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[14],
          &EV_SLAC_B.sf_MATLABFunction_i);
        EV_SLAC_B.rtb_ASCIItoString_my_b[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_i.y[0];
        EV_SLAC_B.rtb_ASCIItoString_my_b[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_i.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_my_b[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction(sdpMesg_res_bus.mPayload.u6_addr8[15],
          &EV_SLAC_B.sf_MATLABFunction_d4);
        EV_SLAC_B.rtb_ASCIItoString_lp_d[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_d4.y[0];
        EV_SLAC_B.rtb_ASCIItoString_lp_d[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_d4.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_lp_d[2], 0, 254U * sizeof(char_T));
        EV_SLAC_B.rtb_StringConcatenate_dg_e[0] = '\x00';
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[0U],
                &EV_SLAC_B.rtb_ASCIItoString_g4_l[0], 255U);
        EV_SLAC_B.temp = strlen(&EV_SLAC_B.rtb_StringConcatenate_dg_e[0U]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_e4_j[0], 255U - EV_SLAC_B.temp);
        EV_SLAC_B.temp += strlen
          (&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_aj_d[0], 255U - EV_SLAC_B.temp);
        EV_SLAC_B.temp += strlen
          (&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_pr_g[0], 255U - EV_SLAC_B.temp);
        EV_SLAC_B.temp += strlen
          (&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_m5_l[0], 255U - EV_SLAC_B.temp);
        EV_SLAC_B.temp += strlen
          (&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_nn_d[0], 255U - EV_SLAC_B.temp);
        EV_SLAC_B.temp += strlen
          (&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_e1_d[0], 255U - EV_SLAC_B.temp);
        EV_SLAC_B.temp += strlen
          (&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_al_l[0], 255U - EV_SLAC_B.temp);
        EV_SLAC_B.temp += strlen
          (&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_pm_o[0], 255U - EV_SLAC_B.temp);
        EV_SLAC_B.temp += strlen
          (&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_p4_b[0], 255U - EV_SLAC_B.temp);
        EV_SLAC_B.temp += strlen
          (&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_fc_n[0], 255U - EV_SLAC_B.temp);
        EV_SLAC_B.temp += strlen
          (&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_ev_b[0], 255U - EV_SLAC_B.temp);
        EV_SLAC_B.temp += strlen
          (&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_cj3_l[0], 255U - EV_SLAC_B.temp);
        EV_SLAC_B.temp += strlen
          (&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_lat_h[0], 255U - EV_SLAC_B.temp);
        EV_SLAC_B.temp += strlen
          (&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_my_b[0], 255U - EV_SLAC_B.temp);
        EV_SLAC_B.temp += strlen
          (&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_dg_e[EV_SLAC_B.temp],
                &EV_SLAC_B.rtb_ASCIItoString_lp_d[0], 255U - EV_SLAC_B.temp);
        snprintf(&EV_SLAC_B.rtb_ASCIItoString_g4_l[0], 256U,
                 "SDP get SECC IP: %s, port: %d",
                 &EV_SLAC_B.rtb_StringConcatenate_dg_e[0], (int32_T)
                 sdpMesg_res_bus.mPayload.port);
        strncpy(&EV_SLAC_B.cv7[0], &EV_SLAC_B.rtb_ASCIItoString_g4_l[0], 100U);
        for (EV_SLAC_B.i_h = 0; EV_SLAC_B.i_h < 100; EV_SLAC_B.i_h++) {
          EV_SLAC_B.Cast1_g[EV_SLAC_B.i_h] = (int8_T)(uint8_T)
            EV_SLAC_B.cv7[EV_SLAC_B.i_h];
        }

        slac_debug_ported(EV_SLAC_P.CCaller_status_i, &EV_SLAC_B.Cast1_g[0]);
        EV_SLAC_DW.ret = (((int32_T)EV_SLAC_B.isValid != (int32_T)
                           EV_SLAC_P.CompareToConstant1_const_d) ||
                          (EV_SLAC_B.CCaller2_o1_j !=
                           EV_SLAC_P.CompareToConstant_const));
        EV_SLAC_B.c = (int32_T)((uint32_T)(int32_T)EV_SLAC_DW.SdpResend + 1U);
        if ((uint32_T)(int32_T)EV_SLAC_DW.SdpResend + 1U > 255U) {
          EV_SLAC_B.c = 255;
        }

        EV_SLAC_DW.SdpResend = (uint8_T)EV_SLAC_B.c;
        break;

       case 1:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_V2G2_019_V2G2_645_SECC_DISCOVERY =
          EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_f = 2U;
        break;
      }
    } else {
      guard1 = false;
      if (EV_SLAC_DW.ret == 1) {
        guard1 = true;
      } else if (EV_SLAC_DW.ret == 0) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.SdpResend = (uint8_T)0U;
        EV_SLAC_DW.is_V2G2_019_V2G2_645_SECC_DISCOVERY =
          EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_f = 3U;
      } else if ((int32_T)EV_SLAC_DW.SdpResend >= 50) {
        guard1 = true;
      } else if ((((((EV_SLAC_M->Timing.clockTick1) * 0.01) -
                    EV_SLAC_DW.previousTime) + EV_SLAC_DW.temporalCounter_i1) *
                  1000.0 >= 250.0) && ((int32_T)EV_SLAC_DW.SdpResend < 50)) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.SdpResend = (uint8_T)0U;
        EV_SLAC_DW.is_V2G2_019_V2G2_645_SECC_DISCOVERY = EV_SLAC_IN_SDP_REQ;
        E_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req
          (EV_SLAC_SharedDSM.UDP_PORT,
           &EV_SLAC_B.V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req,
           &EV_SLAC_ConstB.V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req,
           &EV_SLAC_DW.V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req,
           &EV_SLAC_P.V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req);
        EV_SLAC_DW.ret =
          EV_SLAC_B.V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req.CCaller1;
      }

      if (guard1) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.SdpResend = (uint8_T)0U;
        EV_SLAC_DW.is_V2G2_019_V2G2_645_SECC_DISCOVERY =
          EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_f = 2U;
      }
    }

    switch (EV_SLAC_DW.exitPortIndex_f) {
     case 2:
      EV_SLAC_DW.exitPortIndex_f = 0U;
      EV_SLAC_DW.is_SDP = EV_SLAC_IN_NO_ACTIVE_CHILD;
      EV_SLAC_DW.exitPortIndex_a = 2U;
      break;

     case 3:
      EV_SLAC_DW.exitPortIndex_f = 0U;
      EV_SLAC_DW.is_SDP = EV_SLAC_IN_NO_ACTIVE_CHILD;
      EV_SLAC_DW.exitPortIndex_a = 3U;
      break;
    }
  }

  switch (EV_SLAC_DW.exitPortIndex_a) {
   case 2:
    EV_SLAC_DW.exitPortIndex_a = 0U;
    EV_SLAC_DW.is_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
    EV_SLAC_DW.exitPortIndex_d = 2U;
    break;

   case 3:
    EV_SLAC_DW.exitPortIndex_a = 0U;
    EV_SLAC_DW.is_BLOCK = EV_SLAC_IN_TCP_TLS_CONNECTION_EST;
    EV_SLAC_DW.is_TCP_TLS_CONNECTION_EST = EV_SLAC_IN_OPEN_TCPCHANNEL;
    EV_SLAC_B.r_h = EV_SLAC_rand_d();
    EV_SLAC_B.payloadLength = EV_SLAC_SharedDSM.connStream;
    EV_SLAC_B.CCaller_o2_b = EV_SLAC_SharedDSM.errorNo;
    EV_SLAC_B.r_h = floor(EV_SLAC_B.r_h * 16383.0);
    if (EV_SLAC_B.r_h < 65536.0) {
      if (EV_SLAC_B.r_h >= 0.0) {
        EV_SLAC_B.inDataIdx = (uint16_T)EV_SLAC_B.r_h;
      } else {
        EV_SLAC_B.inDataIdx = (uint16_T)0U;
      }
    } else {
      EV_SLAC_B.inDataIdx = MAX_uint16_T;
    }

    EV_SLAC_B.u1 = (uint32_T)EV_SLAC_B.inDataIdx + (uint32_T)(int32_T)
      EV_SLAC_P.clientPort_Value_h;
    if (EV_SLAC_B.u1 > 65535U) {
      EV_SLAC_B.u1 = 65535U;
    }

    TCPStreamSetup6(EV_SLAC_SharedDSM.sdpMesg_res.mPayload.port, (uint16_T)
                    EV_SLAC_B.u1, &EV_SLAC_B.payloadLength,
                    EV_SLAC_P.CCaller_server, EV_SLAC_P.timeout_Value,
                    &EV_SLAC_B.CCaller_o2_b,
                    &EV_SLAC_SharedDSM.sdpMesg_res.mPayload.u6_addr8[0]);
    EV_SLAC_SharedDSM.connStream = EV_SLAC_B.payloadLength;
    EV_SLAC_DW.ret = (int32_T)EV_SLAC_B.CCaller_o2_b;
    break;
  }
}

static void EV_SLAC_COMMUNICATION_SETUP(void)
{
  if ((((EV_SLAC_M->Timing.clockTick1) * 0.01) - EV_SLAC_DW.previousTime) +
      EV_SLAC_DW.temporalCounter_i2 >= (real_T)
      EV_SLAC_DW.V2G_EVCC_CommunicationSetup_Timeout) {
    switch (EV_SLAC_DW.is_BLOCK) {
     case EV_SLAC_IN_Hansharking:
      switch (EV_SLAC_DW.is_Hansharking) {
       case EV_SLAC_IN_REQUEST:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_Hansharking = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;

       case EV_SLAC_IN_RESPONSE:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_Hansharking = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;

       default:
        EV_SLAC_DW.is_Hansharking = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;
      }

      EV_SLAC_DW.is_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;

     case EV_SLAC_IN_SDP:
      switch (EV_SLAC_DW.is_SDP) {
       case EV_SLAC_IN_V2G2_016_IP_ADD_ASSIGMENT:
        switch (EV_SLAC_DW.is_V2G2_016_IP_ADD_ASSIGMENT) {
         case EV_SLAC_IN_BINDING:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_V2G2_016_IP_ADD_ASSIGMENT = EV_SLAC_IN_NO_ACTIVE_CHILD;
          break;

         case EV_SLAC_IN_OPEN_CHANNEL:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_V2G2_016_IP_ADD_ASSIGMENT = EV_SLAC_IN_NO_ACTIVE_CHILD;
          break;
        }

        EV_SLAC_DW.is_SDP = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;

       case EV_SLAC_IN_V2G2_019_V2G2_645_SECC_DISCOVERY:
        switch (EV_SLAC_DW.is_V2G2_019_V2G2_645_SECC_DISCOVERY) {
         case EV_SLAC_IN_SDP_REQ:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_V2G2_019_V2G2_645_SECC_DISCOVERY =
            EV_SLAC_IN_NO_ACTIVE_CHILD;
          break;

         case EV_SLAC_IN_SDP_RES:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.SdpResend = (uint8_T)0U;
          EV_SLAC_DW.is_V2G2_019_V2G2_645_SECC_DISCOVERY =
            EV_SLAC_IN_NO_ACTIVE_CHILD;
          break;
        }

        EV_SLAC_DW.is_SDP = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;
      }

      EV_SLAC_DW.is_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;

     case EV_SLAC_IN_SESSION_SETUP:
      switch (EV_SLAC_DW.is_SESSION_SETUP) {
       case EV_SLAC_IN_REQUEST:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_SESSION_SETUP = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;

       case EV_SLAC_IN_RESPONSE:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_SESSION_SETUP = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;

       default:
        EV_SLAC_DW.is_SESSION_SETUP = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;
      }

      EV_SLAC_DW.is_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;

     case EV_SLAC_IN_TCP_TLS_CONNECTION_EST:
      if ((int32_T)EV_SLAC_DW.is_TCP_TLS_CONNECTION_EST == (int32_T)
          EV_SLAC_IN_OPEN_TCPCHANNEL) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_TCP_TLS_CONNECTION_EST = EV_SLAC_IN_NO_ACTIVE_CHILD;
      }

      EV_SLAC_DW.is_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;
    }

    EV_SLAC_DW.exitPortIndex = 4U;
  } else {
    switch (EV_SLAC_DW.is_BLOCK) {
     case EV_SLAC_IN_Hansharking:
      switch (EV_SLAC_DW.is_Hansharking) {
       case EV_SLAC_IN_REQUEST:
        if (EV_SLAC_DW.ret == 0) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_Hansharking = EV_SLAC_IN_waitingRes;
          EV_SLAC_sf_msg_send_StreamMesgOut();
        } else if (EV_SLAC_DW.ret != 0) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_Hansharking = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_p = 2U;
        }
        break;

       case EV_SLAC_IN_RESPONSE:
        if (EV_SLAC_DW.ret == 0) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_Hansharking = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_p = 3U;
        } else if (EV_SLAC_DW.ret != 0) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_Hansharking = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_p = 2U;
        }
        break;

       default:
        if (EV_SLAC_sf_msg_pop_StreamMesgIn()) {
          EV_SLAC_DW.is_Hansharking = EV_SLAC_IN_RESPONSE;
          EV_SLAC_B.StreamIn = EV_SLAC_DW.StreamMesgIn_msgReservedData;
          EV_SLAC_B.BusAssignment_f_c = EV_SLAC_P.Constant14_Value;
          EV_SLAC_B.CCaller1_o1_fj = decode_appHandExiDocument
            (&EV_SLAC_B.StreamIn, &EV_SLAC_B.BusAssignment_f_c);
          EV_SLAC_B.Cast2 = (int32_T)
            EV_SLAC_B.BusAssignment_f_c.supportedAppProtocolRes.ResponseCode;
          EV_SLAC_B.i_m = (int32_T)
            EV_SLAC_B.BusAssignment_f_c.supportedAppProtocolRes.SchemaID;
          EV_SLAC_B.Equal3 = (boolean_T)(EV_SLAC_P.EnumeratedConstant1_Value ==
            EV_SLAC_B.BusAssignment_f_c.supportedAppProtocolRes.ResponseCode);
          EV_SLAC_B.AND_h = (boolean_T)
            (EV_SLAC_B.BusAssignment_f_c.supportedAppProtocolRes.ResponseCode ==
             EV_SLAC_P.EnumeratedConstant_Value_i);
          EV_SLAC_B.OR_n = (boolean_T)(((int32_T)EV_SLAC_B.Equal3) || ((int32_T)
            EV_SLAC_B.AND_h));
          EV_SLAC_B.AND_h = (boolean_T)((int32_T)
            EV_SLAC_B.BusAssignment_f_c.supportedAppProtocolRes.SchemaID ==
            (int32_T)EV_SLAC_P.Constant1_Value_m);
          EV_SLAC_B.Equal3 = (boolean_T)
            (EV_SLAC_B.BusAssignment_f_c.supportedAppProtocolRes_isUsed ==
             (uint32_T)(int32_T)EV_SLAC_P.Constant_Value_eu);
          EV_SLAC_B.AND_h = (boolean_T)((EV_SLAC_B.CCaller1_o1_fj !=
            EV_SLAC_P.Constant_Value_h) || (!(int32_T)EV_SLAC_B.OR_n) ||
            (!(int32_T)EV_SLAC_B.AND_h) || (!(int32_T)EV_SLAC_B.Equal3));
          snprintf(&EV_SLAC_B.rtb_ComposeString_b_k[0], 256U,
                   "Handshark Response: resCode: %d  schemaID: %d status: %d",
                   EV_SLAC_B.Cast2, EV_SLAC_B.i_m, (int32_T)EV_SLAC_B.AND_h);
          strncpy(&EV_SLAC_B.cv6[0], &EV_SLAC_B.rtb_ComposeString_b_k[0], 100U);
          for (EV_SLAC_B.i_m = 0; EV_SLAC_B.i_m < 100; EV_SLAC_B.i_m++) {
            EV_SLAC_B.Cast1_ma[EV_SLAC_B.i_m] = (int8_T)(uint8_T)
              EV_SLAC_B.cv6[EV_SLAC_B.i_m];
          }

          slac_debug_ported(EV_SLAC_P.CCaller_status_hs, &EV_SLAC_B.Cast1_ma[0]);
          EV_SLAC_DW.ret = (int32_T)EV_SLAC_B.AND_h;
        }
        break;
      }

      switch (EV_SLAC_DW.exitPortIndex_p) {
       case 2:
        EV_SLAC_DW.exitPortIndex_p = 0U;
        EV_SLAC_DW.is_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_d = 2U;
        break;

       case 3:
        EV_SLAC_DW.exitPortIndex_p = 0U;
        EV_SLAC_DW.is_BLOCK = EV_SLAC_IN_SESSION_SETUP;
        EV_SLAC_DW.is_SESSION_SETUP = EV_SLAC_IN_REQUEST;
        EV_SLAC_B.BusAssignment2_m = EV_SLAC_P.Constant6_Value;
        EV_SLAC_B.BusAssignment2_m.size = (uint32_T)EV_SLAC_P.Constant1_Value_a;
        EV_SLAC_B.BusAssignment2_m.pos = (uint32_T)EV_SLAC_P.Constant3_Value_a;
        EV_SLAC_B.BusAssignment1_e = EV_SLAC_SharedDSM.ExiDoc_Buff;
        repaireExiDocBuff(&EV_SLAC_B.BusAssignment1_e);
        for (EV_SLAC_B.i_m = 0; EV_SLAC_B.i_m < 8; EV_SLAC_B.i_m++) {
          EV_SLAC_B.BusAssignment1_e.V2G_Message.Header.SessionID.bytes[EV_SLAC_B.i_m]
            = EV_SLAC_P.Constant7_Value_e[EV_SLAC_B.i_m];
        }

        EV_SLAC_B.BusAssignment1_e.V2G_Message.Header.SessionID.bytesLen =
          EV_SLAC_ConstB.Width1;
        EV_SLAC_B.BusAssignment1_e.V2G_Message.Body.SessionSetupReq_isUsed =
          EV_SLAC_P.Constant8_Value_j;
        EV_SLAC_B.BusAssignment1_e.V2G_Message.Body.SessionSetupReq.EVCCID =
          EV_SLAC_SharedDSM.EVCC_CONFIG_SET.EVCCID;
        EV_SLAC_B.BusAssignment1_e.V2G_Message_isUsed =
          EV_SLAC_P.Constant2_Value_a;
        EV_SLAC_B.CCaller2_o2 = EV_SLAC_B.BusAssignment2_m;
        EV_SLAC_B.Cast2 = encode_iso1ExiDocument(&EV_SLAC_B.CCaller2_o2,
          &EV_SLAC_B.BusAssignment1_e);
        snprintf(&EV_SLAC_B.rtb_ComposeString_o_g[0], 256U,
                 "SessionSetup Request: status: %d with EVCCID: ",
                 EV_SLAC_B.Cast2);
        for (EV_SLAC_B.i_m = 0; EV_SLAC_B.i_m < 6; EV_SLAC_B.i_m++) {
          EV_SLAC_B.rtb_ASCIItoString_lz_n[EV_SLAC_B.i_m] = (char_T)(int8_T)
            EV_SLAC_SharedDSM.EVCC_CONFIG_SET.EVCCID.bytes[EV_SLAC_B.i_m];
        }

        memset(&EV_SLAC_B.rtb_ASCIItoString_lz_n[6], 0, 250U * sizeof(char_T));
        EV_SLAC_B.rtb_StringConcatenate_a_p[0] = '\x00';
        strncat(&EV_SLAC_B.rtb_StringConcatenate_a_p[0U],
                &EV_SLAC_B.rtb_ComposeString_o_g[0], 255U);
        EV_SLAC_B.u = strlen(&EV_SLAC_B.rtb_StringConcatenate_a_p[0U]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_a_p[EV_SLAC_B.u],
                &EV_SLAC_B.rtb_ASCIItoString_lz_n[0], 255U - EV_SLAC_B.u);
        strncpy(&EV_SLAC_B.cv6[0], &EV_SLAC_B.rtb_StringConcatenate_a_p[0], 100U);
        for (EV_SLAC_B.i_m = 0; EV_SLAC_B.i_m < 100; EV_SLAC_B.i_m++) {
          EV_SLAC_B.Cast1_ma[EV_SLAC_B.i_m] = (int8_T)(uint8_T)
            EV_SLAC_B.cv6[EV_SLAC_B.i_m];
        }

        slac_debug_ported(EV_SLAC_P.CCaller_status_m, &EV_SLAC_B.Cast1_ma[0]);
        EV_SLAC_DW.ret = EV_SLAC_B.Cast2;
        EV_SLAC_DW.StreamMesgOut_msgReservedData = EV_SLAC_B.CCaller2_o2;
        break;
      }
      break;

     case EV_SLAC_IN_SDP:
      EV_SLAC_SDP();
      break;

     case EV_SLAC_IN_SESSION_SETUP:
      switch (EV_SLAC_DW.is_SESSION_SETUP) {
       case EV_SLAC_IN_REQUEST:
        if (EV_SLAC_DW.ret == 0) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_SESSION_SETUP = EV_SLAC_IN_waitingRes;
          EV_SLAC_sf_msg_send_StreamMesgOut();
        } else if (EV_SLAC_DW.ret != 0) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_SESSION_SETUP = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_fu = 2U;
        }
        break;

       case EV_SLAC_IN_RESPONSE:
        if (EV_SLAC_DW.ret == 0) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_SESSION_SETUP = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_fu = 3U;
        } else if (EV_SLAC_DW.ret != 0) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_SESSION_SETUP = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_fu = 2U;
        }
        break;

       default:
        if (EV_SLAC_sf_msg_pop_StreamMesgIn()) {
          EV_SLAC_DW.is_SESSION_SETUP = EV_SLAC_IN_RESPONSE;
          EV_SLAC_B.StreamIn_p = EV_SLAC_DW.StreamMesgIn_msgReservedData;
          EV_SLAC_B.BusAssignment1_e = EV_SLAC_SharedDSM.ExiDoc_Buff;
          EV_SLAC_B.CCaller1_o1_fj = decode_iso1ExiDocument
            (&EV_SLAC_B.StreamIn_p, &EV_SLAC_B.BusAssignment1_e);
          EV_SLAC_SharedDSM.EVSE_PAIRING_SET.SessionID =
            EV_SLAC_B.BusAssignment1_e.V2G_Message.Header.SessionID;
          EV_SLAC_SharedDSM.EVSE_PAIRING_SET.EVSEID =
            EV_SLAC_B.BusAssignment1_e.V2G_Message.Body.SessionSetupRes.EVSEID;
          for (EV_SLAC_B.i_m = 0; EV_SLAC_B.i_m < 37; EV_SLAC_B.i_m++) {
            EV_SLAC_B.rtb_Cast1_m_g = (uint8_T)
              EV_SLAC_B.BusAssignment1_e.V2G_Message.Body.SessionSetupRes.EVSEID.characters
              [EV_SLAC_B.i_m];
            EV_SLAC_B.rtb_ASCIItoString1_c[EV_SLAC_B.i_m] = (char_T)(int8_T)
              EV_SLAC_B.rtb_Cast1_m_g;
          }

          memset(&EV_SLAC_B.rtb_ASCIItoString1_c[37], 0, 219U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.BusAssignment1_e.V2G_Message.Header.SessionID.bytes[0],
             &EV_SLAC_B.sf_MATLABFunction_no);
          EV_SLAC_B.rtb_StringConcatenate_a_p[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_no.y[0];
          EV_SLAC_B.rtb_StringConcatenate_a_p[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_no.y[1];
          memset(&EV_SLAC_B.rtb_StringConcatenate_a_p[2], 0, 254U * sizeof
                 (char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.BusAssignment1_e.V2G_Message.Header.SessionID.bytes[1],
             &EV_SLAC_B.sf_MATLABFunction_cx);
          EV_SLAC_B.rtb_ComposeString_b_k[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_cx.y[0];
          EV_SLAC_B.rtb_ComposeString_b_k[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_cx.y[1];
          memset(&EV_SLAC_B.rtb_ComposeString_b_k[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.BusAssignment1_e.V2G_Message.Header.SessionID.bytes[2],
             &EV_SLAC_B.sf_MATLABFunction_l);
          EV_SLAC_B.rtb_ASCIItoString_if_b[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_l.y[0];
          EV_SLAC_B.rtb_ASCIItoString_if_b[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_l.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_if_b[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.BusAssignment1_e.V2G_Message.Header.SessionID.bytes[3],
             &EV_SLAC_B.sf_MATLABFunction_el);
          EV_SLAC_B.rtb_ASCIItoString_at_p[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_el.y[0];
          EV_SLAC_B.rtb_ASCIItoString_at_p[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_el.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_at_p[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.BusAssignment1_e.V2G_Message.Header.SessionID.bytes[4],
             &EV_SLAC_B.sf_MATLABFunction_a5);
          EV_SLAC_B.rtb_ASCIItoString_ew_c[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_a5.y[0];
          EV_SLAC_B.rtb_ASCIItoString_ew_c[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_a5.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_ew_c[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.BusAssignment1_e.V2G_Message.Header.SessionID.bytes[5],
             &EV_SLAC_B.sf_MATLABFunction_pu);
          EV_SLAC_B.rtb_ASCIItoString_cj_f[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_pu.y[0];
          EV_SLAC_B.rtb_ASCIItoString_cj_f[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_pu.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_cj_f[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.BusAssignment1_e.V2G_Message.Header.SessionID.bytes[6],
             &EV_SLAC_B.sf_MATLABFunction_o);
          EV_SLAC_B.rtb_ASCIItoString_de_g[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_o.y[0];
          EV_SLAC_B.rtb_ASCIItoString_de_g[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_o.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_de_g[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.BusAssignment1_e.V2G_Message.Header.SessionID.bytes[7],
             &EV_SLAC_B.sf_MATLABFunction_gr);
          EV_SLAC_B.rtb_ASCIItoString_ai_m[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_gr.y[0];
          EV_SLAC_B.rtb_ASCIItoString_ai_m[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_gr.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_ai_m[2], 0, 254U * sizeof(char_T));
          EV_SLAC_B.rtb_ASCIItoString_lz_n[0] = '\x00';
          strncat(&EV_SLAC_B.rtb_ASCIItoString_lz_n[0U],
                  &EV_SLAC_B.rtb_StringConcatenate_a_p[0], 255U);
          EV_SLAC_B.u = strlen(&EV_SLAC_B.rtb_ASCIItoString_lz_n[0U]);
          strncat(&EV_SLAC_B.rtb_ASCIItoString_lz_n[EV_SLAC_B.u],
                  &EV_SLAC_B.rtb_ComposeString_b_k[0], 255U - EV_SLAC_B.u);
          EV_SLAC_B.u += strlen(&EV_SLAC_B.rtb_ASCIItoString_lz_n[EV_SLAC_B.u]);
          strncat(&EV_SLAC_B.rtb_ASCIItoString_lz_n[EV_SLAC_B.u],
                  &EV_SLAC_B.rtb_ASCIItoString_if_b[0], 255U - EV_SLAC_B.u);
          EV_SLAC_B.u += strlen(&EV_SLAC_B.rtb_ASCIItoString_lz_n[EV_SLAC_B.u]);
          strncat(&EV_SLAC_B.rtb_ASCIItoString_lz_n[EV_SLAC_B.u],
                  &EV_SLAC_B.rtb_ASCIItoString_at_p[0], 255U - EV_SLAC_B.u);
          EV_SLAC_B.u += strlen(&EV_SLAC_B.rtb_ASCIItoString_lz_n[EV_SLAC_B.u]);
          strncat(&EV_SLAC_B.rtb_ASCIItoString_lz_n[EV_SLAC_B.u],
                  &EV_SLAC_B.rtb_ASCIItoString_ew_c[0], 255U - EV_SLAC_B.u);
          EV_SLAC_B.u += strlen(&EV_SLAC_B.rtb_ASCIItoString_lz_n[EV_SLAC_B.u]);
          strncat(&EV_SLAC_B.rtb_ASCIItoString_lz_n[EV_SLAC_B.u],
                  &EV_SLAC_B.rtb_ASCIItoString_cj_f[0], 255U - EV_SLAC_B.u);
          EV_SLAC_B.u += strlen(&EV_SLAC_B.rtb_ASCIItoString_lz_n[EV_SLAC_B.u]);
          strncat(&EV_SLAC_B.rtb_ASCIItoString_lz_n[EV_SLAC_B.u],
                  &EV_SLAC_B.rtb_ASCIItoString_de_g[0], 255U - EV_SLAC_B.u);
          EV_SLAC_B.u += strlen(&EV_SLAC_B.rtb_ASCIItoString_lz_n[EV_SLAC_B.u]);
          strncat(&EV_SLAC_B.rtb_ASCIItoString_lz_n[EV_SLAC_B.u],
                  &EV_SLAC_B.rtb_ASCIItoString_ai_m[0], 255U - EV_SLAC_B.u);
          EV_SLAC_B.Cast2 = (int32_T)
            EV_SLAC_B.BusAssignment1_e.V2G_Message.Header.Notification_isUsed;
          EV_SLAC_B.i_m = (int32_T)
            EV_SLAC_B.BusAssignment1_e.V2G_Message.Body.SessionSetupRes.EVSETimeStamp_isUsed;
          EV_SLAC_B.Cast6_l = (int32_T)
            EV_SLAC_B.BusAssignment1_e.V2G_Message.Header.Signature_isUsed;
          EV_SLAC_B.Equal3 = (boolean_T)((int32_T)
            EV_SLAC_B.BusAssignment1_e.V2G_Message_isUsed == (int32_T)
            EV_SLAC_P.CompareToConstant1_const_j);
          EV_SLAC_B.AND_h = (boolean_T)((int32_T)
            EV_SLAC_B.BusAssignment1_e.V2G_Message.Body.SessionSetupRes_isUsed ==
            (int32_T)EV_SLAC_P.CompareToConstant_const_o);
          EV_SLAC_B.CCaller1_o1_fj = ((EV_SLAC_B.CCaller1_o1_fj !=
            EV_SLAC_P.Constant_Value_g) || (!(int32_T)EV_SLAC_B.Equal3) ||
            (!(int32_T)EV_SLAC_B.AND_h));
          EV_SLAC_B.AND_h = (boolean_T)(EV_SLAC_P.EnumeratedConstant1_Value_n ==
            EV_SLAC_B.BusAssignment1_e.V2G_Message.Body.SessionSetupRes.ResponseCode);
          EV_SLAC_B.Equal3 = (boolean_T)(EV_SLAC_P.EnumeratedConstant_Value_f ==
            EV_SLAC_B.BusAssignment1_e.V2G_Message.Body.SessionSetupRes.ResponseCode);
          EV_SLAC_B.AND_h = (boolean_T)((EV_SLAC_B.CCaller1_o1_fj !=
            EV_SLAC_P.Constant_Value_p) || ((!(int32_T)EV_SLAC_B.AND_h) &&
            (!(int32_T)EV_SLAC_B.Equal3)));
          snprintf(&EV_SLAC_B.rtb_StringConcatenate_a_p[0], 256U,
                   "EvseID: %s new sessionsetup SessionID= %s , Notify = %d, useTime = %d, signUsed = %d, retCode : %d",
                   &EV_SLAC_B.rtb_ASCIItoString1_c[0],
                   &EV_SLAC_B.rtb_ASCIItoString_lz_n[0], EV_SLAC_B.Cast2,
                   EV_SLAC_B.i_m, EV_SLAC_B.Cast6_l, (int32_T)EV_SLAC_B.AND_h);
          strncpy(&EV_SLAC_B.cv[0], &EV_SLAC_B.rtb_StringConcatenate_a_p[0],
                  120U);
          for (EV_SLAC_B.i_m = 0; EV_SLAC_B.i_m < 120; EV_SLAC_B.i_m++) {
            EV_SLAC_B.Cast2_ax[EV_SLAC_B.i_m] = (int8_T)(uint8_T)
              EV_SLAC_B.cv[EV_SLAC_B.i_m];
          }

          slac_debug_ported(EV_SLAC_P.CCaller1_status, &EV_SLAC_B.Cast2_ax[0]);
          EV_SLAC_DW.ret = (int32_T)EV_SLAC_B.AND_h;
        }
        break;
      }

      switch (EV_SLAC_DW.exitPortIndex_fu) {
       case 2:
        EV_SLAC_DW.exitPortIndex_fu = 0U;
        EV_SLAC_DW.is_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_d = 2U;
        break;

       case 3:
        EV_SLAC_DW.exitPortIndex_fu = 0U;
        EV_SLAC_DW.is_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_d = 3U;
        break;
      }
      break;

     default:
      if (EV_SLAC_DW.ret == 0) {
        EV_SLAC_DW.ActiveTcpLoop_msgReservedData = true;
        EV_SLAC_sf_msg_send_ActiveTcpLoop();
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_TCP_TLS_CONNECTION_EST = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_a1 = 3U;
      } else if (EV_SLAC_DW.ret != 0) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_TCP_TLS_CONNECTION_EST = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_a1 = 2U;
      }

      switch (EV_SLAC_DW.exitPortIndex_a1) {
       case 2:
        EV_SLAC_DW.exitPortIndex_a1 = 0U;
        EV_SLAC_DW.is_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_d = 2U;
        break;

       case 3:
        EV_SLAC_DW.exitPortIndex_a1 = 0U;
        EV_SLAC_DW.is_BLOCK = EV_SLAC_IN_Hansharking;
        EV_SLAC_DW.is_Hansharking = EV_SLAC_IN_REQUEST;
        strncpy(&EV_SLAC_B.cv6[0], &EV_SLAC_P.StringConstant_String_h[0], 100U);
        for (EV_SLAC_B.i_m = 0; EV_SLAC_B.i_m < 100; EV_SLAC_B.i_m++) {
          EV_SLAC_B.BusAssignment1_g.ProtocolNamespace.characters[EV_SLAC_B.i_m]
            = (exi_string_character_t)(uint8_T)EV_SLAC_B.cv6[EV_SLAC_B.i_m];
        }

        EV_SLAC_B.BusAssignment1_g.ProtocolNamespace.charactersLen = (uint16_T)
          (uint8_T)strlen(&EV_SLAC_P.StringConstant_String_h[0]);
        EV_SLAC_B.BusAssignment1_g.VersionNumberMajor = (uint32_T)
          EV_SLAC_P.Constant1_Value_o;
        EV_SLAC_B.BusAssignment1_g.VersionNumberMinor = (uint32_T)
          EV_SLAC_P.Constant2_Value_b;
        EV_SLAC_B.BusAssignment1_g.SchemaID = EV_SLAC_P.Constant3_Value_l;
        EV_SLAC_B.BusAssignment1_g.Priority = EV_SLAC_P.Constant4_Value_i;
        EV_SLAC_B.BusAssignment_f_c = EV_SLAC_P.Constant8_Value;
        EV_SLAC_B.BusAssignment_f_c.supportedAppProtocolReq_isUsed = (uint32_T)
          EV_SLAC_P.Constant_Value_l5;
        EV_SLAC_B.BusAssignment_f_c.supportedAppProtocolReq.AppProtocol.data_Array
          [0] = EV_SLAC_B.BusAssignment1_g;
        EV_SLAC_B.BusAssignment_f_c.supportedAppProtocolReq.AppProtocol.data_Array
          [1] = EV_SLAC_P.Constant7_Value;
        EV_SLAC_B.BusAssignment_f_c.supportedAppProtocolReq.AppProtocol.data_Array
          [2] = EV_SLAC_P.Constant7_Value;
        EV_SLAC_B.BusAssignment_f_c.supportedAppProtocolReq.AppProtocol.data_Array
          [3] = EV_SLAC_P.Constant7_Value;
        EV_SLAC_B.BusAssignment_f_c.supportedAppProtocolReq.AppProtocol.data_Array
          [4] = EV_SLAC_P.Constant7_Value;
        EV_SLAC_B.BusAssignment_f_c.supportedAppProtocolReq.AppProtocol.arrayLen
          = (uint16_T)EV_SLAC_P.Constant5_Value_d;
        EV_SLAC_B.BusAssignment2_m = EV_SLAC_P.Constant13_Value;
        EV_SLAC_B.BusAssignment2_m.size = (uint32_T)EV_SLAC_P.Constant11_Value;
        EV_SLAC_B.BusAssignment2_m.pos = (uint32_T)EV_SLAC_P.Constant10_Value;
        EV_SLAC_B.CCaller1_o2_f = EV_SLAC_B.BusAssignment2_m;
        EV_SLAC_B.CCaller1_o1_fj = encode_appHandExiDocument
          (&EV_SLAC_B.CCaller1_o2_f, &EV_SLAC_B.BusAssignment_f_c);
        strncpy(&EV_SLAC_B.cv10[0], &EV_SLAC_P.StringConstant1_String_g[0], 50U);
        for (EV_SLAC_B.i_m = 0; EV_SLAC_B.i_m < 50; EV_SLAC_B.i_m++) {
          EV_SLAC_B.Cast_f[EV_SLAC_B.i_m] = (int8_T)(uint8_T)
            EV_SLAC_B.cv10[EV_SLAC_B.i_m];
        }

        slac_debug_ported(EV_SLAC_P.CCaller_status_h, &EV_SLAC_B.Cast_f[0]);
        EV_SLAC_DW.ret = EV_SLAC_B.CCaller1_o1_fj;
        EV_SLAC_DW.StreamMesgOut_msgReservedData = EV_SLAC_B.CCaller1_o2_f;
        break;
      }
      break;
    }

    switch (EV_SLAC_DW.exitPortIndex_d) {
     case 2:
      EV_SLAC_DW.exitPortIndex_d = 0U;
      EV_SLAC_DW.exitPortIndex = 2U;
      break;

     case 3:
      EV_SLAC_DW.exitPortIndex_d = 0U;
      EV_SLAC_DW.exitPortIndex = 3U;
      break;
    }
  }

  switch (EV_SLAC_DW.exitPortIndex) {
   case 2:
    EV_SLAC_DW.exitPortIndex = 0U;
    EV_SLAC_DW.is_LinkSetup = EV_SLAC_IN_errorHandle;
    EV_SLAC_V2GLinkSetuperrorHandleTimeOutHandle
      (&EV_SLAC_B.V2GLinkSetuperrorHandleTimeOutHandle,
       &EV_SLAC_P.V2GLinkSetuperrorHandleTimeOutHandle);
    break;

   case 3:
    EV_SLAC_DW.exitPortIndex = 0U;
    EV_SLAC_DW.is_LinkSetup = EV_SLAC_IN_V2G_SEQ;
    EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_SERVICE_DISCOVERY;
    EV_SLAC_DW.temporalCounter_i1 = 0.0;
    EV_SLAC_DW.is_SERVICE_DISCOVERY = EV_SLAC_IN_REQ_BLOCK;
    EV_SLAC_DW.is_REQ_BLOCK = EV_SLAC_IN_REQUEST;
    EV_SLAC_B.BusAssignment2_m = EV_SLAC_P.Constant13_Value_g;
    EV_SLAC_B.BusAssignment2_m.size = (uint32_T)EV_SLAC_P.Constant11_Value_h;
    EV_SLAC_B.BusAssignment2_m.pos = (uint32_T)EV_SLAC_P.Constant10_Value_e;
    EV_SLAC_B.BusAssignment1_e = EV_SLAC_SharedDSM.ExiDoc_Buff;
    repaireExiDocBuff(&EV_SLAC_B.BusAssignment1_e);
    EV_SLAC_B.BusAssignment1_e.V2G_Message.Header.SessionID =
      EV_SLAC_SharedDSM.EVSE_PAIRING_SET.SessionID;
    EV_SLAC_B.BusAssignment1_e.V2G_Message.Body.ServiceDiscoveryReq =
      EV_SLAC_P.Constant5_Value_j;
    EV_SLAC_B.BusAssignment1_e.V2G_Message.Body.ServiceDiscoveryReq.ServiceCategory
      = EV_SLAC_P.EnumeratedConstant_Value_o;
    EV_SLAC_B.BusAssignment1_e.V2G_Message.Body.ServiceDiscoveryReq.ServiceCategory_isUsed
      = (uint8_T)EV_SLAC_P.Constant_Value_b;
    EV_SLAC_B.BusAssignment1_e.V2G_Message.Body.ServiceDiscoveryReq_isUsed =
      EV_SLAC_P.Constant4_Value_o;
    EV_SLAC_B.BusAssignment1_e.V2G_Message_isUsed = EV_SLAC_P.Constant1_Value_n;
    EV_SLAC_B.CCaller1_o2_k = EV_SLAC_B.BusAssignment2_m;
    EV_SLAC_B.Cast2 = encode_iso1ExiDocument(&EV_SLAC_B.CCaller1_o2_k,
      &EV_SLAC_B.BusAssignment1_e);
    snprintf(&EV_SLAC_B.rtb_ComposeString_o_g[0], 256U,
             "Discovery Request: serviceCategory: %d status: %d",
             EV_SLAC_B.Cast2, (int32_T)EV_SLAC_P.EnumeratedConstant_Value_o);
    strncpy(&EV_SLAC_B.cv6[0], &EV_SLAC_B.rtb_ComposeString_o_g[0], 100U);
    for (EV_SLAC_B.i_m = 0; EV_SLAC_B.i_m < 100; EV_SLAC_B.i_m++) {
      EV_SLAC_B.Cast1_ma[EV_SLAC_B.i_m] = (int8_T)(uint8_T)
        EV_SLAC_B.cv6[EV_SLAC_B.i_m];
    }

    slac_debug_ported(EV_SLAC_P.CCaller_status_f, &EV_SLAC_B.Cast1_ma[0]);
    EV_SLAC_DW.ret = EV_SLAC_B.Cast2;
    EV_SLAC_DW.StreamMesgOut_msgReservedData = EV_SLAC_B.CCaller1_o2_k;
    break;

   case 4:
    EV_SLAC_DW.exitPortIndex = 0U;
    EV_SLAC_DW.is_LinkSetup = EV_SLAC_IN_errorHandle;
    EV_SLAC_V2GLinkSetuperrorHandleTimeOutHandle
      (&EV_SLAC_B.V2GLinkSetuperrorHandleTimeOutHandle,
       &EV_SLAC_P.V2GLinkSetuperrorHandleTimeOutHandle);
    break;
  }
}

static void EV_SLAC_Slac_param(void)
{
  int32_T CCaller_o1_h;
  if ((int32_T)EV_SLAC_DW.is_Slac_param == (int32_T)EV_SLAC_IN_Request) {
    if (EV_SLAC_DW.ret == 0) {
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.temporalCounter_i1 = 0.0;
      EV_SLAC_DW.is_Slac_param = EV_SLAC_IN_response;
      EV_SLAC_V2GLinkSetupSLACSlac_parampev_cm_slac_param_response(&CCaller_o1_h);
      EV_SLAC_DW.ret = CCaller_o1_h;
    } else if ((((EV_SLAC_M->Timing.clockTick1) * 0.01) -
                EV_SLAC_DW.previousTime) + EV_SLAC_DW.temporalCounter_i1 >= 1.0)
    {
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.temporalCounter_i1 = 0.0;
      EV_SLAC_DW.is_Slac_param = EV_SLAC_IN_Request;
      EV_SLAC_V2GLinkSetupSLACSlac_paraminscreseRunID
        (&EV_SLAC_SharedDSM.global_session,
         &EV_SLAC_ConstB.V2GLinkSetupSLACSlac_paraminscreseRunID);
      EV_SLAC_V2GLinkSetupSLACSlac_parampev_cm_slac_param_request(&CCaller_o1_h);
      EV_SLAC_DW.ret = CCaller_o1_h;
    }
  } else if (((((EV_SLAC_M->Timing.clockTick1) * 0.01) - EV_SLAC_DW.previousTime)
              + EV_SLAC_DW.temporalCounter_i1) * 1000.0 >= (real_T)
             EV_SLAC_DW.TT_match_response) {
    EV_SLAC_DW.ret = -1;
    EV_SLAC_DW.is_Slac_param = EV_SLAC_IN_NO_ACTIVE_CHILD;
    EV_SLAC_DW.exitPortIndex_hq = 2U;
  } else if (EV_SLAC_DW.ret == 0) {
    EV_SLAC_DW.ret = -1;
    EV_SLAC_DW.is_Slac_param = EV_SLAC_IN_NO_ACTIVE_CHILD;
    EV_SLAC_DW.exitPortIndex_hq = 3U;
  } else {
    EV_SLAC_V2GLinkSetupSLACSlac_parampev_cm_slac_param_response(&CCaller_o1_h);
    EV_SLAC_DW.ret = CCaller_o1_h;
  }

  switch (EV_SLAC_DW.exitPortIndex_hq) {
   case 2:
    EV_SLAC_DW.exitPortIndex_hq = 0U;
    EV_SLAC_DW.is_SLAC = EV_SLAC_IN_NO_ACTIVE_CHILD;
    EV_SLAC_DW.exitPortIndex_n = 3U;
    break;

   case 3:
    EV_SLAC_DW.exitPortIndex_hq = 0U;
    EV_SLAC_DW.is_SLAC = EV_SLAC_IN_MATCHING;
    EV_SLAC_DW.temporalCounter_i2 = 0.0;
    EV_SLAC_DW.is_MATCHING = EV_SLAC_IN_SOUDING_SEQ;
    EV_SLAC_DW.temporalCounter_i1 = 0.0;
    EV_SLAC_DW.is_SOUDING_SEQ = EV_SLAC_IN_START_ATTEN;
    EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_start_atten_char
      (&CCaller_o1_h);
    EV_SLAC_DW.ret = CCaller_o1_h;
    CCaller_o1_h = (int32_T)((uint32_T)(int32_T)EV_SLAC_DW.StartAttenCnt + 1U);
    if ((uint32_T)(int32_T)EV_SLAC_DW.StartAttenCnt + 1U > 255U) {
      CCaller_o1_h = 255;
    }

    EV_SLAC_DW.StartAttenCnt = (uint8_T)CCaller_o1_h;
    break;
  }
}

static void EV_SLAC_enter_internal_Slac_param(void)
{
  int32_T CCaller_e;
  EV_SLAC_DW.temporalCounter_i1 = 0.0;
  EV_SLAC_DW.is_Slac_param = EV_SLAC_IN_Request;
  EV_SLAC_V2GLinkSetupSLACSlac_paraminscreseRunID
    (&EV_SLAC_SharedDSM.global_session,
     &EV_SLAC_ConstB.V2GLinkSetupSLACSlac_paraminscreseRunID);
  EV_SLAC_V2GLinkSetupSLACSlac_parampev_cm_slac_param_request(&CCaller_e);
  EV_SLAC_DW.ret = CCaller_e;
}

static void EV_SLAC_MATCHING(void)
{
  real_T tmp;
  int32_T CCaller_o1_g;
  switch (EV_SLAC_DW.is_MATCHING) {
   case EV_SLAC_IN_CHECK_COMPATABLE:
    if ((int32_T)EV_SLAC_DW.is_CHECK_COMPATABLE == (int32_T)
        EV_SLAC_IN_FirstStateReq) {
      if (EV_SLAC_DW.ret == 0) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.temporalCounter_i1 = 0.0;
        EV_SLAC_DW.is_CHECK_COMPATABLE = EV_SLAC_IN_FirstStateRes;
        EV_SLAC_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES
          (&EV_SLAC_SharedDSM.global_channel, &EV_SLAC_SharedDSM.global_message,
           &EV_SLAC_SharedDSM.global_session,
           &EV_SLAC_B.V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES);
        EV_SLAC_DW.ret =
          EV_SLAC_B.V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES.CCaller;
      } else {
        EV_SLAC_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ
          (&EV_SLAC_SharedDSM.global_channel, &EV_SLAC_SharedDSM.global_message,
           &EV_SLAC_SharedDSM.global_session,
           &EV_SLAC_B.V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ);
        EV_SLAC_DW.ret =
          EV_SLAC_B.V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ.CCaller;
      }
    } else {
      switch (EV_SLAC_DW.ret) {
       case 1:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_CHECK_COMPATABLE = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.is_MATCHING = EV_SLAC_IN_VALIDATE;
        EV_SLAC_DW.is_VALIDATE = EV_SLAC_IN_SecondStateReq;
        EV_SLAC_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ
          (&EV_SLAC_SharedDSM.global_channel, &EV_SLAC_SharedDSM.global_message,
           &EV_SLAC_SharedDSM.global_session,
           &EV_SLAC_B.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ,
           &EV_SLAC_P.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ);
        EV_SLAC_DW.ret =
          EV_SLAC_B.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ.CCaller;
        break;

       case 4:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_CHECK_COMPATABLE = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.is_MATCHING = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_g = 2U;
        break;

       default:
        if ((EV_SLAC_DW.ret == 0) || (EV_SLAC_DW.ret == 2) || (EV_SLAC_DW.ret ==
             3)) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_CHECK_COMPATABLE = EV_SLAC_IN_FirstStateReq;
          EV_SLAC_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ
            (&EV_SLAC_SharedDSM.global_channel,
             &EV_SLAC_SharedDSM.global_message,
             &EV_SLAC_SharedDSM.global_session,
             &EV_SLAC_B.V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ);
          EV_SLAC_DW.ret =
            EV_SLAC_B.V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ.CCaller;
        } else if (((((EV_SLAC_M->Timing.clockTick1) * 0.01) -
                     EV_SLAC_DW.previousTime) + EV_SLAC_DW.temporalCounter_i1) *
                   1000.0 >= (real_T)EV_SLAC_DW.TT_match_response) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_CHECK_COMPATABLE = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.is_MATCHING = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_g = 3U;
        } else {
          EV_SLAC_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES
            (&EV_SLAC_SharedDSM.global_channel,
             &EV_SLAC_SharedDSM.global_message,
             &EV_SLAC_SharedDSM.global_session,
             &EV_SLAC_B.V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES);
          EV_SLAC_DW.ret =
            EV_SLAC_B.V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES.CCaller;
        }
        break;
      }
    }
    break;

   case EV_SLAC_IN_DESISION:
    tmp = ((EV_SLAC_M->Timing.clockTick1) * 0.01) - EV_SLAC_DW.previousTime;
    if ((tmp + EV_SLAC_DW.temporalCounter_i2) * 1000.0 >= (real_T)
        EV_SLAC_DW.TP_EV_match_session) {
      switch (EV_SLAC_DW.is_DESISION) {
       case EV_SLAC_IN_Atten:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_DESISION = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;

       case EV_SLAC_IN_RSP_ATTEN_CHAR:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_DESISION = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;
      }

      EV_SLAC_DW.is_MATCHING = EV_SLAC_IN_NO_ACTIVE_CHILD;
      EV_SLAC_DW.exitPortIndex_g = 3U;
    } else if ((int32_T)EV_SLAC_DW.is_DESISION == (int32_T)EV_SLAC_IN_Atten) {
      if (EV_SLAC_DW.ret > 1) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_DESISION = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.is_MATCHING = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_g = 3U;
      } else {
        switch (EV_SLAC_DW.ret) {
         case 1:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_DESISION = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.is_MATCHING = EV_SLAC_IN_CHECK_COMPATABLE;
          EV_SLAC_DW.is_CHECK_COMPATABLE = EV_SLAC_IN_FirstStateReq;
          EV_SLAC_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ
            (&EV_SLAC_SharedDSM.global_channel,
             &EV_SLAC_SharedDSM.global_message,
             &EV_SLAC_SharedDSM.global_session,
             &EV_SLAC_B.V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ);
          EV_SLAC_DW.ret =
            EV_SLAC_B.V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ.CCaller;
          break;

         case 0:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_DESISION = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.is_MATCHING = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_g = 2U;
          break;

         default:
          EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONcheckAAG(40, 80, &CCaller_o1_g);
          EV_SLAC_DW.ret = CCaller_o1_g;
          break;
        }
      }
    } else if ((tmp + EV_SLAC_DW.temporalCounter_i1) * 1000.0 >= (real_T)
               EV_SLAC_DW.TP_match_sequence) {
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_DESISION = EV_SLAC_IN_NO_ACTIVE_CHILD;
      EV_SLAC_DW.is_MATCHING = EV_SLAC_IN_NO_ACTIVE_CHILD;
      EV_SLAC_DW.exitPortIndex_g = 3U;
    } else if (EV_SLAC_DW.ret == 0) {
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_DESISION = EV_SLAC_IN_Atten;
      EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONcheckAAG(40, 80, &CCaller_o1_g);
      EV_SLAC_DW.ret = CCaller_o1_g;
    } else {
      EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONpev_cm_atten_char_RSP
        (&CCaller_o1_g);
      EV_SLAC_DW.ret = CCaller_o1_g;
    }
    break;

   case EV_SLAC_IN_SOUDING_SEQ:
    tmp = ((EV_SLAC_M->Timing.clockTick1) * 0.01) - EV_SLAC_DW.previousTime;
    if ((tmp + EV_SLAC_DW.temporalCounter_i2) * 1000.0 >= (real_T)
        EV_SLAC_DW.TT_EV_atten_results) {
      switch (EV_SLAC_DW.is_SOUDING_SEQ) {
       case EV_SLAC_IN_RECEIVING_ATTEN_CHAR:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_SOUDING_SEQ = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;

       case EV_SLAC_IN_SOUNDING:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_SOUDING_SEQ = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;

       case EV_SLAC_IN_START_ATTEN:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_SOUDING_SEQ = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;
      }

      EV_SLAC_DW.is_MATCHING = EV_SLAC_IN_NO_ACTIVE_CHILD;
      EV_SLAC_DW.exitPortIndex_g = 3U;
    } else {
      switch (EV_SLAC_DW.is_SOUDING_SEQ) {
       case EV_SLAC_IN_RECEIVING_ATTEN_CHAR:
        if (EV_SLAC_DW.ret == 0) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_SOUDING_SEQ = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.temporalCounter_i2 = 0.0;
          EV_SLAC_DW.is_MATCHING = EV_SLAC_IN_DESISION;
          EV_SLAC_DW.temporalCounter_i1 = 0.0;
          EV_SLAC_DW.is_DESISION = EV_SLAC_IN_RSP_ATTEN_CHAR;
          EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONpev_cm_atten_char_RSP
            (&CCaller_o1_g);
          EV_SLAC_DW.ret = CCaller_o1_g;
        } else {
          EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_atten_char_IND
            (&CCaller_o1_g);
          EV_SLAC_DW.ret = CCaller_o1_g;
        }
        break;

       case EV_SLAC_IN_SOUNDING:
        if (EV_SLAC_DW.ret == 0) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_SOUDING_SEQ = EV_SLAC_IN_RECEIVING_ATTEN_CHAR;
          EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_atten_char_IND
            (&CCaller_o1_g);
          EV_SLAC_DW.ret = CCaller_o1_g;
        }
        break;

       default:
        if ((EV_SLAC_DW.ret == 0) && ((tmp + EV_SLAC_DW.temporalCounter_i1) *
             1000.0 >= (real_T)EV_SLAC_DW.TP_EV_batch_msg_interval)) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.temporalCounter_i1 = 0.0;
          EV_SLAC_DW.is_SOUDING_SEQ = EV_SLAC_IN_START_ATTEN;
          EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_start_atten_char
            (&CCaller_o1_g);
          EV_SLAC_DW.ret = CCaller_o1_g;
          CCaller_o1_g = (int32_T)((uint32_T)(int32_T)EV_SLAC_DW.StartAttenCnt +
            1U);
          if ((uint32_T)(int32_T)EV_SLAC_DW.StartAttenCnt + 1U > 255U) {
            CCaller_o1_g = 255;
          }

          EV_SLAC_DW.StartAttenCnt = (uint8_T)CCaller_o1_g;
        } else {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_SOUDING_SEQ = EV_SLAC_IN_SOUNDING;
          EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_mnbc_sound
            (&CCaller_o1_g);
          EV_SLAC_DW.ret = CCaller_o1_g;
        }
        break;
      }
    }
    break;

   default:
    switch (EV_SLAC_DW.is_VALIDATE) {
     case EV_SLAC_IN_LastStateCNF:
      if (EV_SLAC_DW.ret == 2) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_VALIDATE = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.is_MATCHING = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_g = 2U;
      } else if (((((EV_SLAC_M->Timing.clockTick1) * 0.01) -
                   EV_SLAC_DW.previousTime) + EV_SLAC_DW.temporalCounter_i1) *
                 1000.0 >= (real_T)EV_SLAC_DW.TT_match_response) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_VALIDATE = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.is_MATCHING = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_g = 3U;
      } else {
        EV_SLAC_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF
          (&EV_SLAC_SharedDSM.global_channel, &EV_SLAC_SharedDSM.global_message,
           &EV_SLAC_SharedDSM.global_session,
           &EV_SLAC_B.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF,
           &EV_SLAC_P.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF);
        EV_SLAC_DW.ret =
          EV_SLAC_B.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF.CCaller;
      }
      break;

     case EV_SLAC_IN_SecondStateReq:
      if (EV_SLAC_DW.ret == 0) {
        EV_SLAC_DW.is_VALIDATE = EV_SLAC_IN_Toggling_State;
        EV_SLAC_DW.ret = 0;
      } else {
        EV_SLAC_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ
          (&EV_SLAC_SharedDSM.global_channel, &EV_SLAC_SharedDSM.global_message,
           &EV_SLAC_SharedDSM.global_session,
           &EV_SLAC_B.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ,
           &EV_SLAC_P.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ);
        EV_SLAC_DW.ret =
          EV_SLAC_B.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ.CCaller;
      }
      break;

     default:
      if (EV_SLAC_DW.ret == 0) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.temporalCounter_i1 = 0.0;
        EV_SLAC_DW.is_VALIDATE = EV_SLAC_IN_LastStateCNF;
        EV_SLAC_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF
          (&EV_SLAC_SharedDSM.global_channel, &EV_SLAC_SharedDSM.global_message,
           &EV_SLAC_SharedDSM.global_session,
           &EV_SLAC_B.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF,
           &EV_SLAC_P.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF);
        EV_SLAC_DW.ret =
          EV_SLAC_B.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF.CCaller;
      }
      break;
    }
    break;
  }

  switch (EV_SLAC_DW.exitPortIndex_g) {
   case 2:
    EV_SLAC_DW.exitPortIndex_g = 0U;
    EV_SLAC_DW.is_SLAC = EV_SLAC_IN_MATCHED;
    EV_SLAC_DW.temporalCounter_i1 = 0.0;
    EV_SLAC_DW.is_MATCHED = EV_SLAC_IN_Start_Match;
    EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_slac_match(&CCaller_o1_g);
    EV_SLAC_DW.ret = CCaller_o1_g;
    break;

   case 3:
    EV_SLAC_DW.exitPortIndex_g = 0U;
    EV_SLAC_DW.is_SLAC = EV_SLAC_IN_NO_ACTIVE_CHILD;
    EV_SLAC_DW.exitPortIndex_n = 3U;
    break;
  }
}

static real_T EV_SLAC_rand(void)
{
  real_T r;
  int32_T exitg1;
  boolean_T exitg2;
  if (EV_SLAC_DW.method_h == 4U) {
    EV_SLAC_B.y_b = EV_SLAC_DW.seed / 127773U;
    EV_SLAC_B.mti = (EV_SLAC_DW.seed - EV_SLAC_B.y_b * 127773U) * 16807U;
    EV_SLAC_B.y_b *= 2836U;
    if (EV_SLAC_B.mti < EV_SLAC_B.y_b) {
      EV_SLAC_B.mti = ~(EV_SLAC_B.y_b - EV_SLAC_B.mti) & 2147483647U;
    } else {
      EV_SLAC_B.mti -= EV_SLAC_B.y_b;
    }

    r = (real_T)EV_SLAC_B.mti * 4.6566128752457969E-10;
    EV_SLAC_DW.seed = EV_SLAC_B.mti;
  } else if (EV_SLAC_DW.method_h == 5U) {
    EV_SLAC_B.mti = 69069U * EV_SLAC_DW.state_f[0] + 1234567U;
    EV_SLAC_B.y_b = EV_SLAC_DW.state_f[1] << 13 ^ EV_SLAC_DW.state_f[1];
    EV_SLAC_B.y_b ^= EV_SLAC_B.y_b >> 17;
    EV_SLAC_B.y_b ^= EV_SLAC_B.y_b << 5;
    EV_SLAC_DW.state_f[0] = EV_SLAC_B.mti;
    EV_SLAC_DW.state_f[1] = EV_SLAC_B.y_b;
    r = (real_T)(EV_SLAC_B.mti + EV_SLAC_B.y_b) * 2.328306436538696E-10;
  } else {
    if (!(int32_T)EV_SLAC_DW.seed_not_empty) {
      EV_SLAC_eml_rand_mt19937ar(EV_SLAC_DW.state_g);
      EV_SLAC_DW.seed_not_empty = true;
    }

    memcpy(&EV_SLAC_B.c_mt_m[0], &EV_SLAC_DW.state_g[0], 625U * sizeof(uint32_T));

    /* ========================= COPYRIGHT NOTICE ============================ */
    /*  This is a uniform (0,1) pseudorandom number generator based on:        */
    /*                                                                         */
    /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
    /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
    /*                                                                         */
    /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
    /*  All rights reserved.                                                   */
    /*                                                                         */
    /*  Redistribution and use in source and binary forms, with or without     */
    /*  modification, are permitted provided that the following conditions     */
    /*  are met:                                                               */
    /*                                                                         */
    /*    1. Redistributions of source code must retain the above copyright    */
    /*       notice, this list of conditions and the following disclaimer.     */
    /*                                                                         */
    /*    2. Redistributions in binary form must reproduce the above copyright */
    /*       notice, this list of conditions and the following disclaimer      */
    /*       in the documentation and/or other materials provided with the     */
    /*       distribution.                                                     */
    /*                                                                         */
    /*    3. The names of its contributors may not be used to endorse or       */
    /*       promote products derived from this software without specific      */
    /*       prior written permission.                                         */
    /*                                                                         */
    /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
    /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
    /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
    /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
    /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
    /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
    /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
    /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
    /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
    /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
    /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
    /*                                                                         */
    /* =============================   END   ================================= */
    do {
      exitg1 = 0;
      for (EV_SLAC_B.i_e = 0; EV_SLAC_B.i_e < 2; EV_SLAC_B.i_e++) {
        EV_SLAC_B.mti = EV_SLAC_B.c_mt_m[624] + 1U;
        if (EV_SLAC_B.c_mt_m[624] + 1U >= 625U) {
          for (EV_SLAC_B.b_kk_j = 0; EV_SLAC_B.b_kk_j < 227; EV_SLAC_B.b_kk_j++)
          {
            EV_SLAC_B.y_b = (EV_SLAC_B.c_mt_m[EV_SLAC_B.b_kk_j + 1] &
                             2147483647U) | (EV_SLAC_B.c_mt_m[EV_SLAC_B.b_kk_j]
              & 2147483648U);
            if ((EV_SLAC_B.y_b & 1U) == 0U) {
              EV_SLAC_B.mti = EV_SLAC_B.y_b >> 1U;
            } else {
              EV_SLAC_B.mti = EV_SLAC_B.y_b >> 1U ^ 2567483615U;
            }

            EV_SLAC_B.c_mt_m[EV_SLAC_B.b_kk_j] =
              EV_SLAC_B.c_mt_m[EV_SLAC_B.b_kk_j + 397] ^ EV_SLAC_B.mti;
          }

          for (EV_SLAC_B.b_kk_j = 0; EV_SLAC_B.b_kk_j < 396; EV_SLAC_B.b_kk_j++)
          {
            EV_SLAC_B.y_b = (EV_SLAC_B.c_mt_m[EV_SLAC_B.b_kk_j + 227] &
                             2147483648U) | (EV_SLAC_B.c_mt_m[EV_SLAC_B.b_kk_j +
              228] & 2147483647U);
            if ((EV_SLAC_B.y_b & 1U) == 0U) {
              EV_SLAC_B.mti = EV_SLAC_B.y_b >> 1U;
            } else {
              EV_SLAC_B.mti = EV_SLAC_B.y_b >> 1U ^ 2567483615U;
            }

            EV_SLAC_B.c_mt_m[EV_SLAC_B.b_kk_j + 227] =
              EV_SLAC_B.c_mt_m[EV_SLAC_B.b_kk_j] ^ EV_SLAC_B.mti;
          }

          EV_SLAC_B.y_b = (EV_SLAC_B.c_mt_m[623] & 2147483648U) |
            (EV_SLAC_B.c_mt_m[0] & 2147483647U);
          if ((EV_SLAC_B.y_b & 1U) == 0U) {
            EV_SLAC_B.mti = EV_SLAC_B.y_b >> 1U;
          } else {
            EV_SLAC_B.mti = EV_SLAC_B.y_b >> 1U ^ 2567483615U;
          }

          EV_SLAC_B.c_mt_m[623] = EV_SLAC_B.c_mt_m[396] ^ EV_SLAC_B.mti;
          EV_SLAC_B.mti = 1U;
        }

        EV_SLAC_B.y_b = EV_SLAC_B.c_mt_m[(int32_T)EV_SLAC_B.mti - 1];
        EV_SLAC_B.c_mt_m[624] = EV_SLAC_B.mti;
        EV_SLAC_B.y_b ^= EV_SLAC_B.y_b >> 11U;
        EV_SLAC_B.y_b ^= EV_SLAC_B.y_b << 7U & 2636928640U;
        EV_SLAC_B.y_b ^= EV_SLAC_B.y_b << 15U & 4022730752U;
        EV_SLAC_B.b_u_m[EV_SLAC_B.i_e] = EV_SLAC_B.y_b >> 18U ^ EV_SLAC_B.y_b;
      }

      r = ((real_T)(EV_SLAC_B.b_u_m[0] >> 5U) * 6.7108864E+7 + (real_T)
           (EV_SLAC_B.b_u_m[1] >> 6U)) * 1.1102230246251565E-16;
      if (r == 0.0) {
        if ((EV_SLAC_B.c_mt_m[624] >= 1U) && (EV_SLAC_B.c_mt_m[624] < 625U)) {
          EV_SLAC_B.b_isvalid_e = false;
          EV_SLAC_B.i_e = 0;
          exitg2 = false;
          while ((!exitg2) && (EV_SLAC_B.i_e + 1 < 625)) {
            if (EV_SLAC_B.c_mt_m[EV_SLAC_B.i_e] == 0U) {
              EV_SLAC_B.i_e++;
            } else {
              EV_SLAC_B.b_isvalid_e = true;
              exitg2 = true;
            }
          }
        } else {
          EV_SLAC_B.b_isvalid_e = false;
        }

        if (!(int32_T)EV_SLAC_B.b_isvalid_e) {
          EV_SLAC_B.mti = 5489U;
          EV_SLAC_B.c_mt_m[0] = 5489U;
          for (EV_SLAC_B.i_e = 0; EV_SLAC_B.i_e < 623; EV_SLAC_B.i_e++) {
            EV_SLAC_B.mti = ((EV_SLAC_B.mti >> 30U ^ EV_SLAC_B.mti) *
                             1812433253U + (uint32_T)EV_SLAC_B.i_e) + 1U;
            EV_SLAC_B.c_mt_m[EV_SLAC_B.i_e + 1] = EV_SLAC_B.mti;
          }

          EV_SLAC_B.c_mt_m[624] = 624U;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    memcpy(&EV_SLAC_DW.state_g[0], &EV_SLAC_B.c_mt_m[0], 625U * sizeof(uint32_T));
  }

  return r;
}

static boolean_T EV_SLAC_sf_msg_pop_TCP_IP_LostConnect(void)
{
  boolean_T isPresent;
  if (EV_SLAC_DW.TCP_IP_LostConnect_isValid) {
    isPresent = true;
  } else {
    if (EV_SLAC_pop(&EV_SLAC_DW.Queue[1], &EV_SLAC_DW.Msg[0])) {
      EV_SLAC_DW.TCP_IP_LostConnect_msgHandle = &EV_SLAC_DW.Msg[0];
    } else {
      EV_SLAC_DW.TCP_IP_LostConnect_msgHandle = NULL;
    }

    if (EV_SLAC_DW.TCP_IP_LostConnect_msgHandle != NULL) {
      EV_SLAC_DW.TCP_IP_LostConnect_msgDataPtr = &((Msg_boolean_T *)
        EV_SLAC_DW.TCP_IP_LostConnect_msgHandle)->fData;
      isPresent = true;
      EV_SLAC_DW.TCP_IP_LostConnect_msgReservedData = *(boolean_T *)
        EV_SLAC_DW.TCP_IP_LostConnect_msgDataPtr;
      EV_SLAC_DW.TCP_IP_LostConnect_isValid = true;
    } else {
      isPresent = false;
    }
  }

  return isPresent;
}

static void EV_SLAC_AUTHORIZATION(void)
{
  EV_SLAC_B.d3 = ((EV_SLAC_M->Timing.clockTick1) * 0.01) -
    EV_SLAC_DW.previousTime;
  if ((EV_SLAC_B.d3 + EV_SLAC_DW.temporalCounter_i2) * 1000.0 >= (real_T)
      EV_SLAC_DW.V2G_EVCC_Ongoing_Timeout) {
    switch (EV_SLAC_DW.is_AUTHORIZATION) {
     case EV_SLAC_IN_BLOCK:
      if ((int32_T)EV_SLAC_DW.is_BLOCK_p == (int32_T)EV_SLAC_IN_REQUEST) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_BLOCK_p = EV_SLAC_IN_NO_ACTIVE_CHILD;
      } else {
        EV_SLAC_DW.is_BLOCK_p = EV_SLAC_IN_NO_ACTIVE_CHILD;
      }

      EV_SLAC_DW.is_AUTHORIZATION = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;

     case EV_SLAC_IN_RESPONSE:
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_AUTHORIZATION = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;
    }

    EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
  } else {
    if ((int32_T)EV_SLAC_DW.is_AUTHORIZATION == (int32_T)EV_SLAC_IN_BLOCK) {
      if ((EV_SLAC_B.d3 + EV_SLAC_DW.temporalCounter_i1) * 1000.0 >= (real_T)
          EV_SLAC_DW.AuthorizationReq_Timeout) {
        if ((int32_T)EV_SLAC_DW.is_BLOCK_p == (int32_T)EV_SLAC_IN_REQUEST) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_BLOCK_p = EV_SLAC_IN_NO_ACTIVE_CHILD;
        } else {
          EV_SLAC_DW.is_BLOCK_p = EV_SLAC_IN_NO_ACTIVE_CHILD;
        }

        EV_SLAC_DW.is_AUTHORIZATION = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_ap = 4U;
      } else if ((int32_T)EV_SLAC_DW.is_BLOCK_p == (int32_T)EV_SLAC_IN_REQUEST)
      {
        if (EV_SLAC_DW.ret == 0) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_BLOCK_p = EV_SLAC_IN_waitingRes_j;
          EV_SLAC_sf_msg_send_StreamMesgOut();
        } else if (EV_SLAC_DW.ret != 0) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_BLOCK_p = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.is_AUTHORIZATION = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_ap = 2U;
        }
      } else if (EV_SLAC_sf_msg_pop_StreamMesgIn()) {
        EV_SLAC_DW.is_BLOCK_p = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.temporalCounter_i1 = 0.0;
        EV_SLAC_DW.is_AUTHORIZATION = EV_SLAC_IN_RESPONSE;
        EV_SLAC_B.StreamIn_i = EV_SLAC_DW.StreamMesgIn_msgReservedData;
        EV_SLAC_B.CCaller2_o2_o = EV_SLAC_SharedDSM.ExiDoc_Buff;
        EV_SLAC_B.Cast5_p = decode_iso1ExiDocument(&EV_SLAC_B.StreamIn_i,
          &EV_SLAC_B.CCaller2_o2_o);
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_o.V2G_Message.Header.SessionID.bytes[0],
           &EV_SLAC_B.sf_MATLABFunction_ld);
        EV_SLAC_B.rtb_ASCIItoString_lr_l[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_ld.y[0];
        EV_SLAC_B.rtb_ASCIItoString_lr_l[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_ld.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_lr_l[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_o.V2G_Message.Header.SessionID.bytes[1],
           &EV_SLAC_B.sf_MATLABFunction_ag);
        EV_SLAC_B.rtb_ASCIItoString_i_m[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_ag.y[0];
        EV_SLAC_B.rtb_ASCIItoString_i_m[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_ag.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_i_m[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_o.V2G_Message.Header.SessionID.bytes[2],
           &EV_SLAC_B.sf_MATLABFunction_o5);
        EV_SLAC_B.rtb_ASCIItoString_pq_m[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_o5.y[0];
        EV_SLAC_B.rtb_ASCIItoString_pq_m[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_o5.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_pq_m[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_o.V2G_Message.Header.SessionID.bytes[3],
           &EV_SLAC_B.sf_MATLABFunction_b3);
        EV_SLAC_B.rtb_ASCIItoString_iy_c[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_b3.y[0];
        EV_SLAC_B.rtb_ASCIItoString_iy_c[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_b3.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_iy_c[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_o.V2G_Message.Header.SessionID.bytes[4],
           &EV_SLAC_B.sf_MATLABFunction_dd);
        EV_SLAC_B.rtb_ASCIItoString_p3_f[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_dd.y[0];
        EV_SLAC_B.rtb_ASCIItoString_p3_f[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_dd.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_p3_f[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_o.V2G_Message.Header.SessionID.bytes[5],
           &EV_SLAC_B.sf_MATLABFunction_gg);
        EV_SLAC_B.rtb_ASCIItoString_jp_p[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_gg.y[0];
        EV_SLAC_B.rtb_ASCIItoString_jp_p[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_gg.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_jp_p[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_o.V2G_Message.Header.SessionID.bytes[6],
           &EV_SLAC_B.sf_MATLABFunction_o0);
        EV_SLAC_B.rtb_ASCIItoString_kr_e[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_o0.y[0];
        EV_SLAC_B.rtb_ASCIItoString_kr_e[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_o0.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_kr_e[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_o.V2G_Message.Header.SessionID.bytes[7],
           &EV_SLAC_B.sf_MATLABFunction_jn);
        EV_SLAC_B.rtb_ASCIItoString_mj_o[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_jn.y[0];
        EV_SLAC_B.rtb_ASCIItoString_mj_o[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_jn.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_mj_o[2], 0, 254U * sizeof(char_T));
        EV_SLAC_B.rtb_StringConcatenate_d_h[0] = '\x00';
        strncat(&EV_SLAC_B.rtb_StringConcatenate_d_h[0U],
                &EV_SLAC_B.rtb_ASCIItoString_lr_l[0], 255U);
        EV_SLAC_B.u6 = strlen(&EV_SLAC_B.rtb_StringConcatenate_d_h[0U]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_d_h[EV_SLAC_B.u6],
                &EV_SLAC_B.rtb_ASCIItoString_i_m[0], 255U - EV_SLAC_B.u6);
        EV_SLAC_B.u6 += strlen(&EV_SLAC_B.rtb_StringConcatenate_d_h[EV_SLAC_B.u6]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_d_h[EV_SLAC_B.u6],
                &EV_SLAC_B.rtb_ASCIItoString_pq_m[0], 255U - EV_SLAC_B.u6);
        EV_SLAC_B.u6 += strlen(&EV_SLAC_B.rtb_StringConcatenate_d_h[EV_SLAC_B.u6]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_d_h[EV_SLAC_B.u6],
                &EV_SLAC_B.rtb_ASCIItoString_iy_c[0], 255U - EV_SLAC_B.u6);
        EV_SLAC_B.u6 += strlen(&EV_SLAC_B.rtb_StringConcatenate_d_h[EV_SLAC_B.u6]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_d_h[EV_SLAC_B.u6],
                &EV_SLAC_B.rtb_ASCIItoString_p3_f[0], 255U - EV_SLAC_B.u6);
        EV_SLAC_B.u6 += strlen(&EV_SLAC_B.rtb_StringConcatenate_d_h[EV_SLAC_B.u6]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_d_h[EV_SLAC_B.u6],
                &EV_SLAC_B.rtb_ASCIItoString_jp_p[0], 255U - EV_SLAC_B.u6);
        EV_SLAC_B.u6 += strlen(&EV_SLAC_B.rtb_StringConcatenate_d_h[EV_SLAC_B.u6]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_d_h[EV_SLAC_B.u6],
                &EV_SLAC_B.rtb_ASCIItoString_kr_e[0], 255U - EV_SLAC_B.u6);
        EV_SLAC_B.u6 += strlen(&EV_SLAC_B.rtb_StringConcatenate_d_h[EV_SLAC_B.u6]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_d_h[EV_SLAC_B.u6],
                &EV_SLAC_B.rtb_ASCIItoString_mj_o[0], 255U - EV_SLAC_B.u6);
        EV_SLAC_B.Cast3_f = (int32_T)
          EV_SLAC_B.CCaller2_o2_o.V2G_Message.Header.Notification_isUsed;
        EV_SLAC_B.SumofElements_d = (uint8_T)0U;
        for (EV_SLAC_B.i_a = 0; EV_SLAC_B.i_a < 8; EV_SLAC_B.i_a++) {
          EV_SLAC_B.RelationalOperator3_a = (boolean_T)((int32_T)
            EV_SLAC_SharedDSM.EVSE_PAIRING_SET.SessionID.bytes[EV_SLAC_B.i_a] !=
            (int32_T)
            EV_SLAC_B.CCaller2_o2_o.V2G_Message.Header.SessionID.bytes[EV_SLAC_B.i_a]);
          EV_SLAC_B.SumofElements_d = (uint8_T)((uint32_T)
            EV_SLAC_B.SumofElements_d + (uint32_T)(int32_T)
            EV_SLAC_B.RelationalOperator3_a);
        }

        EV_SLAC_B.RelationalOperator3_a = (boolean_T)((int32_T)
          EV_SLAC_B.CCaller2_o2_o.V2G_Message_isUsed == (int32_T)
          EV_SLAC_P.CompareToConstant1_const_f);
        EV_SLAC_B.RelationalOperator4_p = (boolean_T)((int32_T)
          EV_SLAC_B.CCaller2_o2_o.V2G_Message.Body.AuthorizationRes_isUsed ==
          (int32_T)EV_SLAC_P.CompareToConstant_const_a);
        EV_SLAC_B.Cast5_p = ((EV_SLAC_B.Cast5_p != EV_SLAC_P.Constant_Value_in) ||
                             (!(int32_T)EV_SLAC_B.RelationalOperator3_a) ||
                             (!(int32_T)EV_SLAC_B.RelationalOperator4_p));
        EV_SLAC_B.RelationalOperator4_p = (boolean_T)
          (EV_SLAC_P.EnumeratedConstant1_Value_m ==
           EV_SLAC_B.CCaller2_o2_o.V2G_Message.Body.AuthorizationRes.ResponseCode);
        EV_SLAC_B.RelationalOperator3_a = (boolean_T)
          (EV_SLAC_P.EnumeratedConstant2_Value ==
           EV_SLAC_B.CCaller2_o2_o.V2G_Message.Body.AuthorizationRes.EVSEProcessing);
        EV_SLAC_B.RelationalOperator3_a = (boolean_T)(((int32_T)
          EV_SLAC_B.SumofElements_d != (int32_T)EV_SLAC_P.Constant_Value_mf) ||
          (EV_SLAC_B.Cast5_p != EV_SLAC_P.Constant_Value_d) || ((!(int32_T)
          EV_SLAC_B.RelationalOperator4_p) || (!(int32_T)
          EV_SLAC_B.RelationalOperator3_a)));
        snprintf(&EV_SLAC_B.rtb_ASCIItoString_lr_l[0], 256U,
                 "Authorization: SessionID= %s , Notify = %d, retCode : %d",
                 &EV_SLAC_B.rtb_StringConcatenate_d_h[0], EV_SLAC_B.Cast3_f,
                 (int32_T)EV_SLAC_B.RelationalOperator3_a);
        strncpy(&EV_SLAC_B.cv5[0], &EV_SLAC_B.rtb_ASCIItoString_lr_l[0], 120U);
        for (EV_SLAC_B.i_a = 0; EV_SLAC_B.i_a < 120; EV_SLAC_B.i_a++) {
          EV_SLAC_B.Cast2_d0[EV_SLAC_B.i_a] = (int8_T)(uint8_T)
            EV_SLAC_B.cv5[EV_SLAC_B.i_a];
        }

        slac_debug_ported(EV_SLAC_P.CCaller1_status_n, &EV_SLAC_B.Cast2_d0[0]);
        EV_SLAC_B.RelationalOperator4_p = (boolean_T)
          (EV_SLAC_B.CCaller2_o2_o.V2G_Message.Body.AuthorizationRes.EVSEProcessing
           == EV_SLAC_P.EnumeratedConstant3_Value);
        if (EV_SLAC_B.RelationalOperator4_p) {
          EV_SLAC_DW.ret = EV_SLAC_P.Constant_Value_fp;
        } else {
          EV_SLAC_DW.ret = (int32_T)EV_SLAC_B.RelationalOperator3_a;
        }
      }
    } else if (EV_SLAC_DW.ret == 0) {
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_AUTHORIZATION = EV_SLAC_IN_NO_ACTIVE_CHILD;
      EV_SLAC_DW.exitPortIndex_ap = 3U;
    } else if ((EV_SLAC_DW.ret == 2) && (((((EV_SLAC_M->Timing.clockTick1) *
        0.01) - EV_SLAC_DW.previousTime) + EV_SLAC_DW.temporalCounter_i1) *
                1000.0 >= 250.0)) {
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.temporalCounter_i1 = 0.0;
      EV_SLAC_DW.is_AUTHORIZATION = EV_SLAC_IN_BLOCK;
      EV_SLAC_DW.is_BLOCK_p = EV_SLAC_IN_REQUEST;
      EV_SLAC_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq
        (&EV_SLAC_SharedDSM.EVSE_PAIRING_SET, &EV_SLAC_SharedDSM.ExiDoc_Buff,
         &EV_SLAC_B.V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq,
         &EV_SLAC_P.V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq);
      EV_SLAC_DW.ret =
        EV_SLAC_B.V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq.CCaller1_o1;
      EV_SLAC_DW.StreamMesgOut_msgReservedData =
        EV_SLAC_B.V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq.CCaller1_o2;
    } else if (EV_SLAC_DW.ret == 1) {
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_AUTHORIZATION = EV_SLAC_IN_NO_ACTIVE_CHILD;
      EV_SLAC_DW.exitPortIndex_ap = 2U;
    }

    switch (EV_SLAC_DW.exitPortIndex_ap) {
     case 2:
      EV_SLAC_DW.exitPortIndex_ap = 0U;
      EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
      break;

     case 3:
      EV_SLAC_DW.exitPortIndex_ap = 0U;
      EV_SLAC_DW.temporalCounter_i2 = 0.0;
      EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_PARAMETER_DISCOVERY;
      EV_SLAC_DW.temporalCounter_i1 = 0.0;
      EV_SLAC_DW.is_PARAMETER_DISCOVERY = EV_SLAC_IN_BLOCK;
      EV_SLAC_DW.is_BLOCK_f = EV_SLAC_IN_REQUEST;
      EV_SLAC_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq(
        &EV_SLAC_SharedDSM.EVSE_PAIRING_SET, &EV_SLAC_SharedDSM.ExiDoc_Buff,
        &EV_SLAC_B.V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq,
        &EV_SLAC_P.V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq);
      EV_SLAC_DW.ret =
        EV_SLAC_B.V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq.CCaller1_o1;
      EV_SLAC_DW.StreamMesgOut_msgReservedData =
        EV_SLAC_B.V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq.CCaller1_o2;
      break;

     case 4:
      EV_SLAC_DW.exitPortIndex_ap = 0U;
      EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
      break;
    }
  }
}

static void EV_SLAC_CABLE_CHECK(void)
{
  EV_SLAC_B.d2 = ((EV_SLAC_M->Timing.clockTick1) * 0.01) -
    EV_SLAC_DW.previousTime;
  if ((EV_SLAC_B.d2 + EV_SLAC_DW.temporalCounter_i2) * 1000.0 >= (real_T)
      EV_SLAC_DW.V2G_EVCC_Ongoing_Timeout) {
    switch (EV_SLAC_DW.is_CABLE_CHECK) {
     case EV_SLAC_IN_BLOCK:
      if ((int32_T)EV_SLAC_DW.is_BLOCK_j == (int32_T)EV_SLAC_IN_REQUEST) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_BLOCK_j = EV_SLAC_IN_NO_ACTIVE_CHILD;
      } else {
        EV_SLAC_DW.is_BLOCK_j = EV_SLAC_IN_NO_ACTIVE_CHILD;
      }

      EV_SLAC_DW.is_CABLE_CHECK = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;

     case EV_SLAC_IN_RESPONSE:
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_CABLE_CHECK = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;
    }

    EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
  } else {
    if ((int32_T)EV_SLAC_DW.is_CABLE_CHECK == (int32_T)EV_SLAC_IN_BLOCK) {
      if ((EV_SLAC_B.d2 + EV_SLAC_DW.temporalCounter_i1) * 1000.0 >= (real_T)
          EV_SLAC_DW.CableCheckReq_Timeout) {
        if ((int32_T)EV_SLAC_DW.is_BLOCK_j == (int32_T)EV_SLAC_IN_REQUEST) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_BLOCK_j = EV_SLAC_IN_NO_ACTIVE_CHILD;
        } else {
          EV_SLAC_DW.is_BLOCK_j = EV_SLAC_IN_NO_ACTIVE_CHILD;
        }

        EV_SLAC_DW.is_CABLE_CHECK = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_o = 4U;
      } else if ((int32_T)EV_SLAC_DW.is_BLOCK_j == (int32_T)EV_SLAC_IN_REQUEST)
      {
        switch (EV_SLAC_DW.ret) {
         case 0:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_BLOCK_j = EV_SLAC_IN_waitingRes_j;
          EV_SLAC_sf_msg_send_StreamMesgOut();
          break;

         case 1:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_BLOCK_j = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.is_CABLE_CHECK = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_o = 2U;
          break;
        }
      } else if (EV_SLAC_sf_msg_pop_StreamMesgIn()) {
        EV_SLAC_DW.is_BLOCK_j = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.temporalCounter_i1 = 0.0;
        EV_SLAC_DW.is_CABLE_CHECK = EV_SLAC_IN_RESPONSE;
        EV_SLAC_B.StreamIn_d = EV_SLAC_DW.StreamMesgIn_msgReservedData;
        EV_SLAC_B.CCaller2_o2_p = EV_SLAC_SharedDSM.ExiDoc_Buff;
        EV_SLAC_B.Cast5_d0 = decode_iso1ExiDocument(&EV_SLAC_B.StreamIn_d,
          &EV_SLAC_B.CCaller2_o2_p);
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_p.V2G_Message.Header.SessionID.bytes[0],
           &EV_SLAC_B.sf_MATLABFunction_do);
        EV_SLAC_B.rtb_ASCIItoString_lc_o[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_do.y[0];
        EV_SLAC_B.rtb_ASCIItoString_lc_o[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_do.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_lc_o[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_p.V2G_Message.Header.SessionID.bytes[1],
           &EV_SLAC_B.sf_MATLABFunction_n1);
        EV_SLAC_B.rtb_ASCIItoString_c_o[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_n1.y[0];
        EV_SLAC_B.rtb_ASCIItoString_c_o[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_n1.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_c_o[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_p.V2G_Message.Header.SessionID.bytes[2],
           &EV_SLAC_B.sf_MATLABFunction_jy);
        EV_SLAC_B.rtb_ASCIItoString_km_i[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_jy.y[0];
        EV_SLAC_B.rtb_ASCIItoString_km_i[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_jy.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_km_i[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_p.V2G_Message.Header.SessionID.bytes[3],
           &EV_SLAC_B.sf_MATLABFunction_mf);
        EV_SLAC_B.rtb_ASCIItoString_a1_f[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_mf.y[0];
        EV_SLAC_B.rtb_ASCIItoString_a1_f[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_mf.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_a1_f[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_p.V2G_Message.Header.SessionID.bytes[4],
           &EV_SLAC_B.sf_MATLABFunction_b0);
        EV_SLAC_B.rtb_ASCIItoString_oi_i[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_b0.y[0];
        EV_SLAC_B.rtb_ASCIItoString_oi_i[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_b0.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_oi_i[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_p.V2G_Message.Header.SessionID.bytes[5],
           &EV_SLAC_B.sf_MATLABFunction_e0);
        EV_SLAC_B.rtb_ASCIItoString_g_f[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_e0.y[0];
        EV_SLAC_B.rtb_ASCIItoString_g_f[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_e0.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_g_f[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_p.V2G_Message.Header.SessionID.bytes[6],
           &EV_SLAC_B.sf_MATLABFunction_iqd);
        EV_SLAC_B.rtb_ASCIItoString_af_g[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_iqd.y[0];
        EV_SLAC_B.rtb_ASCIItoString_af_g[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_iqd.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_af_g[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_p.V2G_Message.Header.SessionID.bytes[7],
           &EV_SLAC_B.sf_MATLABFunction_ne);
        EV_SLAC_B.rtb_ASCIItoString_d_c[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_ne.y[0];
        EV_SLAC_B.rtb_ASCIItoString_d_c[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_ne.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_d_c[2], 0, 254U * sizeof(char_T));
        EV_SLAC_B.rtb_StringConcatenate_i_o[0] = '\x00';
        strncat(&EV_SLAC_B.rtb_StringConcatenate_i_o[0U],
                &EV_SLAC_B.rtb_ASCIItoString_lc_o[0], 255U);
        EV_SLAC_B.u5 = strlen(&EV_SLAC_B.rtb_StringConcatenate_i_o[0U]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_i_o[EV_SLAC_B.u5],
                &EV_SLAC_B.rtb_ASCIItoString_c_o[0], 255U - EV_SLAC_B.u5);
        EV_SLAC_B.u5 += strlen(&EV_SLAC_B.rtb_StringConcatenate_i_o[EV_SLAC_B.u5]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_i_o[EV_SLAC_B.u5],
                &EV_SLAC_B.rtb_ASCIItoString_km_i[0], 255U - EV_SLAC_B.u5);
        EV_SLAC_B.u5 += strlen(&EV_SLAC_B.rtb_StringConcatenate_i_o[EV_SLAC_B.u5]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_i_o[EV_SLAC_B.u5],
                &EV_SLAC_B.rtb_ASCIItoString_a1_f[0], 255U - EV_SLAC_B.u5);
        EV_SLAC_B.u5 += strlen(&EV_SLAC_B.rtb_StringConcatenate_i_o[EV_SLAC_B.u5]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_i_o[EV_SLAC_B.u5],
                &EV_SLAC_B.rtb_ASCIItoString_oi_i[0], 255U - EV_SLAC_B.u5);
        EV_SLAC_B.u5 += strlen(&EV_SLAC_B.rtb_StringConcatenate_i_o[EV_SLAC_B.u5]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_i_o[EV_SLAC_B.u5],
                &EV_SLAC_B.rtb_ASCIItoString_g_f[0], 255U - EV_SLAC_B.u5);
        EV_SLAC_B.u5 += strlen(&EV_SLAC_B.rtb_StringConcatenate_i_o[EV_SLAC_B.u5]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_i_o[EV_SLAC_B.u5],
                &EV_SLAC_B.rtb_ASCIItoString_af_g[0], 255U - EV_SLAC_B.u5);
        EV_SLAC_B.u5 += strlen(&EV_SLAC_B.rtb_StringConcatenate_i_o[EV_SLAC_B.u5]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_i_o[EV_SLAC_B.u5],
                &EV_SLAC_B.rtb_ASCIItoString_d_c[0], 255U - EV_SLAC_B.u5);
        EV_SLAC_B.Switch2 = (int32_T)
          EV_SLAC_B.CCaller2_o2_p.V2G_Message.Header.Notification_isUsed;
        EV_SLAC_B.SumofElements_j = (uint8_T)0U;
        for (EV_SLAC_B.i_p4 = 0; EV_SLAC_B.i_p4 < 8; EV_SLAC_B.i_p4++) {
          EV_SLAC_B.RelationalOperator5_n = (boolean_T)((int32_T)
            EV_SLAC_SharedDSM.EVSE_PAIRING_SET.SessionID.bytes[EV_SLAC_B.i_p4]
            != (int32_T)
            EV_SLAC_B.CCaller2_o2_p.V2G_Message.Header.SessionID.bytes[EV_SLAC_B.i_p4]);
          EV_SLAC_B.SumofElements_j = (uint8_T)((uint32_T)
            EV_SLAC_B.SumofElements_j + (uint32_T)(int32_T)
            EV_SLAC_B.RelationalOperator5_n);
        }

        EV_SLAC_B.RelationalOperator5_n = (boolean_T)((int32_T)
          EV_SLAC_B.CCaller2_o2_p.V2G_Message_isUsed == (int32_T)
          EV_SLAC_P.CompareToConstant1_const_h);
        EV_SLAC_B.RelationalOperator4_m = (boolean_T)((int32_T)
          EV_SLAC_B.CCaller2_o2_p.V2G_Message.Body.CableCheckRes_isUsed ==
          (int32_T)EV_SLAC_P.CompareToConstant_const_lv);
        EV_SLAC_B.RelationalOperator5_n_h = (boolean_T)((EV_SLAC_B.Cast5_d0 !=
          EV_SLAC_P.Constant_Value_pq) || (!(int32_T)
          EV_SLAC_B.RelationalOperator5_n) || (!(int32_T)
          EV_SLAC_B.RelationalOperator4_m));
        EV_SLAC_B.RelationalOperator4_m = (boolean_T)
          (EV_SLAC_P.EnumeratedConstant1_Value_i ==
           EV_SLAC_B.CCaller2_o2_p.V2G_Message.Body.CableCheckRes.ResponseCode);
        EV_SLAC_B.RelationalOperator5_n = (boolean_T)
          (EV_SLAC_P.EnumeratedConstant4_Value_g ==
           EV_SLAC_B.CCaller2_o2_p.V2G_Message.Body.CableCheckRes.DC_EVSEStatus.EVSENotification);
        if ((int32_T)
            EV_SLAC_B.CCaller2_o2_p.V2G_Message.Body.CableCheckRes.DC_EVSEStatus.EVSEIsolationStatus_isUsed
            != 0) {
          EV_SLAC_B.RelationalOperator6_j = (boolean_T)
            (EV_SLAC_P.EnumeratedConstant5_Value ==
             EV_SLAC_B.CCaller2_o2_p.V2G_Message.Body.CableCheckRes.DC_EVSEStatus.EVSEIsolationStatus);
          EV_SLAC_B.Cast5_d0 = (int32_T)EV_SLAC_B.RelationalOperator6_j;
        } else {
          EV_SLAC_B.Cast5_d0 = (int32_T)EV_SLAC_P.Constant1_Value_f;
        }

        EV_SLAC_B.RelationalOperator10 = (boolean_T)
          (EV_SLAC_B.CCaller2_o2_p.V2G_Message.Body.CableCheckRes.DC_EVSEStatus.EVSEStatusCode
           == EV_SLAC_P.EnumeratedConstant6_Value);
        EV_SLAC_B.RelationalOperator6_j = (boolean_T)
          (EV_SLAC_P.EnumeratedConstant2_Value_c ==
           EV_SLAC_B.CCaller2_o2_p.V2G_Message.Body.CableCheckRes.EVSEProcessing);
        EV_SLAC_B.RelationalOperator5_n = (boolean_T)(((int32_T)
          EV_SLAC_B.SumofElements_j != (int32_T)EV_SLAC_P.Constant_Value_eh) ||
          ((int32_T)EV_SLAC_B.RelationalOperator5_n_h !=
           EV_SLAC_P.Constant_Value_ep) || ((!(int32_T)
          EV_SLAC_B.RelationalOperator4_m) || ((!(int32_T)
          EV_SLAC_B.RelationalOperator5_n) || (EV_SLAC_B.Cast5_d0 == 0) ||
          (!(int32_T)EV_SLAC_B.RelationalOperator10) || (!(int32_T)
          EV_SLAC_B.RelationalOperator6_j))));
        snprintf(&EV_SLAC_B.rtb_ASCIItoString_lc_o[0], 256U,
                 "CableCheck: SessionID= %s , Notify = %d, retCode : %d",
                 &EV_SLAC_B.rtb_StringConcatenate_i_o[0], EV_SLAC_B.Switch2,
                 (int32_T)EV_SLAC_B.RelationalOperator5_n);
        strncpy(&EV_SLAC_B.cv4[0], &EV_SLAC_B.rtb_ASCIItoString_lc_o[0], 120U);
        for (EV_SLAC_B.i_p4 = 0; EV_SLAC_B.i_p4 < 120; EV_SLAC_B.i_p4++) {
          EV_SLAC_B.Cast2_k[EV_SLAC_B.i_p4] = (int8_T)(uint8_T)
            EV_SLAC_B.cv4[EV_SLAC_B.i_p4];
        }

        slac_debug_ported(EV_SLAC_P.CCaller1_status_n2, &EV_SLAC_B.Cast2_k[0]);
        EV_SLAC_B.RelationalOperator6_j = (boolean_T)
          (EV_SLAC_P.EnumeratedConstant7_Value ==
           EV_SLAC_B.CCaller2_o2_p.V2G_Message.Body.CableCheckRes.DC_EVSEStatus.EVSENotification);
        if ((int32_T)
            EV_SLAC_B.CCaller2_o2_p.V2G_Message.Body.CableCheckRes.DC_EVSEStatus.EVSEIsolationStatus_isUsed
            != 0) {
          EV_SLAC_B.RelationalOperator4_m = (boolean_T)
            (EV_SLAC_P.EnumeratedConstant8_Value ==
             EV_SLAC_B.CCaller2_o2_p.V2G_Message.Body.CableCheckRes.DC_EVSEStatus.EVSEIsolationStatus);
          EV_SLAC_B.Switch2 = (int32_T)EV_SLAC_B.RelationalOperator4_m;
        } else {
          EV_SLAC_B.Switch2 = (int32_T)EV_SLAC_P.Constant2_Value_c;
        }

        EV_SLAC_B.RelationalOperator10 = (boolean_T)
          (EV_SLAC_B.CCaller2_o2_p.V2G_Message.Body.CableCheckRes.DC_EVSEStatus.EVSEStatusCode
           == EV_SLAC_P.EnumeratedConstant9_Value);
        EV_SLAC_B.RelationalOperator4_m = (boolean_T)
          (EV_SLAC_B.CCaller2_o2_p.V2G_Message.Body.CableCheckRes.EVSEProcessing
           == EV_SLAC_P.EnumeratedConstant3_Value_j);
        if (((int32_T)EV_SLAC_B.RelationalOperator6_j) && (EV_SLAC_B.Switch2 !=
             0) && ((int32_T)EV_SLAC_B.RelationalOperator10) && ((int32_T)
             EV_SLAC_B.RelationalOperator4_m)) {
          EV_SLAC_DW.ret = EV_SLAC_P.Constant_Value_e;
        } else {
          EV_SLAC_DW.ret = (int32_T)EV_SLAC_B.RelationalOperator5_n;
        }
      }
    } else if ((EV_SLAC_DW.ret == 2) && (((((EV_SLAC_M->Timing.clockTick1) *
        0.01) - EV_SLAC_DW.previousTime) + EV_SLAC_DW.temporalCounter_i1) *
                1000.0 >= 500.0)) {
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.temporalCounter_i1 = 0.0;
      EV_SLAC_DW.is_CABLE_CHECK = EV_SLAC_IN_BLOCK;
      EV_SLAC_DW.is_BLOCK_j = EV_SLAC_IN_REQUEST;
      EV_SLAC_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq
        (&EV_SLAC_SharedDSM.EVSE_PAIRING_SET, &EV_SLAC_SharedDSM.ExiDoc_Buff,
         &EV_SLAC_B.V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq,
         &EV_SLAC_P.V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq);
      EV_SLAC_DW.ret =
        EV_SLAC_B.V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq.CCaller1_o1;
      EV_SLAC_DW.StreamMesgOut_msgReservedData =
        EV_SLAC_B.V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq.CCaller1_o2;
    } else {
      switch (EV_SLAC_DW.ret) {
       case 0:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_CABLE_CHECK = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_o = 3U;
        break;

       case 1:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_CABLE_CHECK = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_o = 2U;
        break;
      }
    }

    switch (EV_SLAC_DW.exitPortIndex_o) {
     case 2:
      EV_SLAC_DW.exitPortIndex_o = 0U;
      EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
      break;

     case 3:
      EV_SLAC_DW.exitPortIndex_o = 0U;
      EV_SLAC_DW.temporalCounter_i2 = 0.0;
      EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_PRE_CHARGE;
      EV_SLAC_DW.temporalCounter_i1 = 0.0;
      EV_SLAC_DW.is_PRE_CHARGE = EV_SLAC_IN_BLOCK;
      EV_SLAC_DW.is_BLOCK_h = EV_SLAC_IN_REQUEST;
      EV_SLAC_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq
        (&EV_SLAC_SharedDSM.EVSE_PAIRING_SET, &EV_SLAC_SharedDSM.ExiDoc_Buff,
         &EV_SLAC_B.V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq,
         &EV_SLAC_P.V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq);
      EV_SLAC_DW.ret =
        EV_SLAC_B.V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq.CCaller1_o1;
      EV_SLAC_DW.StreamMesgOut_msgReservedData =
        EV_SLAC_B.V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq.CCaller1_o2;
      break;

     case 4:
      EV_SLAC_DW.exitPortIndex_o = 0U;
      EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
      break;
    }
  }
}

static real32_T EV_SLAC_rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (((int32_T)rtIsNaNF(u0)) || ((int32_T)rtIsNaNF(u1))) {
    y = (rtNaNF);
  } else {
    EV_SLAC_B.f = fabsf(u0);
    EV_SLAC_B.f1 = fabsf(u1);
    if (rtIsInfF(u1)) {
      if (EV_SLAC_B.f == 1.0F) {
        y = 1.0F;
      } else if (EV_SLAC_B.f > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (EV_SLAC_B.f1 == 0.0F) {
      y = 1.0F;
    } else if (EV_SLAC_B.f1 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = sqrtf(u0);
    } else if ((u0 < 0.0F) && (u1 > floorf(u1))) {
      y = (rtNaNF);
    } else {
      y = powf(u0, u1);
    }
  }

  return y;
}

static void EV_SLAC_PARAMETER_DISCOVERY(void)
{
  iso1SAScheduleTupleType *expl_temp;
  EV_SLAC_B.d = ((EV_SLAC_M->Timing.clockTick1) * 0.01) -
    EV_SLAC_DW.previousTime;
  if ((EV_SLAC_B.d + EV_SLAC_DW.temporalCounter_i2) * 1000.0 >= (real_T)
      EV_SLAC_DW.V2G_EVCC_Ongoing_Timeout) {
    switch (EV_SLAC_DW.is_PARAMETER_DISCOVERY) {
     case EV_SLAC_IN_BLOCK:
      if ((int32_T)EV_SLAC_DW.is_BLOCK_f == (int32_T)EV_SLAC_IN_REQUEST) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_BLOCK_f = EV_SLAC_IN_NO_ACTIVE_CHILD;
      } else {
        EV_SLAC_DW.is_BLOCK_f = EV_SLAC_IN_NO_ACTIVE_CHILD;
      }

      EV_SLAC_DW.is_PARAMETER_DISCOVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;

     case EV_SLAC_IN_RESPONSE:
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_PARAMETER_DISCOVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;
    }

    EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
  } else {
    if ((int32_T)EV_SLAC_DW.is_PARAMETER_DISCOVERY == (int32_T)EV_SLAC_IN_BLOCK)
    {
      if ((EV_SLAC_B.d + EV_SLAC_DW.temporalCounter_i1) * 1000.0 >= (real_T)
          EV_SLAC_DW.ChargeParameterDiscoveryReq_Timeout) {
        if ((int32_T)EV_SLAC_DW.is_BLOCK_f == (int32_T)EV_SLAC_IN_REQUEST) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_BLOCK_f = EV_SLAC_IN_NO_ACTIVE_CHILD;
        } else {
          EV_SLAC_DW.is_BLOCK_f = EV_SLAC_IN_NO_ACTIVE_CHILD;
        }

        EV_SLAC_DW.is_PARAMETER_DISCOVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_ht = 4U;
      } else if ((int32_T)EV_SLAC_DW.is_BLOCK_f == (int32_T)EV_SLAC_IN_REQUEST)
      {
        switch (EV_SLAC_DW.ret) {
         case 0:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_BLOCK_f = EV_SLAC_IN_waitingRes_j;
          EV_SLAC_sf_msg_send_StreamMesgOut();
          break;

         case 1:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_BLOCK_f = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.is_PARAMETER_DISCOVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_ht = 2U;
          break;
        }
      } else if (EV_SLAC_sf_msg_pop_StreamMesgIn()) {
        EV_SLAC_DW.is_BLOCK_f = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.temporalCounter_i1 = 0.0;
        EV_SLAC_DW.is_PARAMETER_DISCOVERY = EV_SLAC_IN_RESPONSE;
        EV_SLAC_B.StreamIn_o = EV_SLAC_DW.StreamMesgIn_msgReservedData;
        EV_SLAC_B.CCaller2_o2_l = EV_SLAC_SharedDSM.ExiDoc_Buff;
        EV_SLAC_B.CCaller2_o1_h = decode_iso1ExiDocument(&EV_SLAC_B.StreamIn_o,
          &EV_SLAC_B.CCaller2_o2_l);
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_l.V2G_Message.Header.SessionID.bytes[0],
           &EV_SLAC_B.sf_MATLABFunction_ad);
        EV_SLAC_B.rtb_ASCIItoString_kc_o[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_ad.y[0];
        EV_SLAC_B.rtb_ASCIItoString_kc_o[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_ad.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_kc_o[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_l.V2G_Message.Header.SessionID.bytes[1],
           &EV_SLAC_B.sf_MATLABFunction_k);
        EV_SLAC_B.rtb_ASCIItoString_mu_n[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_k.y[0];
        EV_SLAC_B.rtb_ASCIItoString_mu_n[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_k.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_mu_n[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_l.V2G_Message.Header.SessionID.bytes[2],
           &EV_SLAC_B.sf_MATLABFunction_ok);
        EV_SLAC_B.rtb_ASCIItoString_op_m[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_ok.y[0];
        EV_SLAC_B.rtb_ASCIItoString_op_m[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_ok.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_op_m[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_l.V2G_Message.Header.SessionID.bytes[3],
           &EV_SLAC_B.sf_MATLABFunction_b5k);
        EV_SLAC_B.rtb_ASCIItoString_bq_c[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_b5k.y[0];
        EV_SLAC_B.rtb_ASCIItoString_bq_c[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_b5k.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_bq_c[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_l.V2G_Message.Header.SessionID.bytes[4],
           &EV_SLAC_B.sf_MATLABFunction_mk);
        EV_SLAC_B.rtb_ASCIItoString_j4_m[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_mk.y[0];
        EV_SLAC_B.rtb_ASCIItoString_j4_m[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_mk.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_j4_m[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_l.V2G_Message.Header.SessionID.bytes[5],
           &EV_SLAC_B.sf_MATLABFunction_i0);
        EV_SLAC_B.rtb_ASCIItoString_p_m[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_i0.y[0];
        EV_SLAC_B.rtb_ASCIItoString_p_m[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_i0.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_p_m[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_l.V2G_Message.Header.SessionID.bytes[6],
           &EV_SLAC_B.sf_MATLABFunction_oh);
        EV_SLAC_B.rtb_ASCIItoString_m4_j[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_oh.y[0];
        EV_SLAC_B.rtb_ASCIItoString_m4_j[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_oh.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_m4_j[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_l.V2G_Message.Header.SessionID.bytes[7],
           &EV_SLAC_B.sf_MATLABFunction_em);
        EV_SLAC_B.rtb_ASCIItoString_n4_h[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_em.y[0];
        EV_SLAC_B.rtb_ASCIItoString_n4_h[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_em.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_n4_h[2], 0, 254U * sizeof(char_T));
        EV_SLAC_B.rtb_StringConcatenate_k_c[0] = '\x00';
        strncat(&EV_SLAC_B.rtb_StringConcatenate_k_c[0U],
                &EV_SLAC_B.rtb_ASCIItoString_kc_o[0], 255U);
        EV_SLAC_B.u3 = strlen(&EV_SLAC_B.rtb_StringConcatenate_k_c[0U]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_k_c[EV_SLAC_B.u3],
                &EV_SLAC_B.rtb_ASCIItoString_mu_n[0], 255U - EV_SLAC_B.u3);
        EV_SLAC_B.u3 += strlen(&EV_SLAC_B.rtb_StringConcatenate_k_c[EV_SLAC_B.u3]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_k_c[EV_SLAC_B.u3],
                &EV_SLAC_B.rtb_ASCIItoString_op_m[0], 255U - EV_SLAC_B.u3);
        EV_SLAC_B.u3 += strlen(&EV_SLAC_B.rtb_StringConcatenate_k_c[EV_SLAC_B.u3]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_k_c[EV_SLAC_B.u3],
                &EV_SLAC_B.rtb_ASCIItoString_bq_c[0], 255U - EV_SLAC_B.u3);
        EV_SLAC_B.u3 += strlen(&EV_SLAC_B.rtb_StringConcatenate_k_c[EV_SLAC_B.u3]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_k_c[EV_SLAC_B.u3],
                &EV_SLAC_B.rtb_ASCIItoString_j4_m[0], 255U - EV_SLAC_B.u3);
        EV_SLAC_B.u3 += strlen(&EV_SLAC_B.rtb_StringConcatenate_k_c[EV_SLAC_B.u3]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_k_c[EV_SLAC_B.u3],
                &EV_SLAC_B.rtb_ASCIItoString_p_m[0], 255U - EV_SLAC_B.u3);
        EV_SLAC_B.u3 += strlen(&EV_SLAC_B.rtb_StringConcatenate_k_c[EV_SLAC_B.u3]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_k_c[EV_SLAC_B.u3],
                &EV_SLAC_B.rtb_ASCIItoString_m4_j[0], 255U - EV_SLAC_B.u3);
        EV_SLAC_B.u3 += strlen(&EV_SLAC_B.rtb_StringConcatenate_k_c[EV_SLAC_B.u3]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_k_c[EV_SLAC_B.u3],
                &EV_SLAC_B.rtb_ASCIItoString_n4_h[0], 255U - EV_SLAC_B.u3);
        EV_SLAC_B.Cast3_p = (int32_T)
          EV_SLAC_B.CCaller2_o2_l.V2G_Message.Header.Notification_isUsed;
        EV_SLAC_B.RelationalOperator3 = (boolean_T)
          (EV_SLAC_P.EnumeratedConstant2_Value_i ==
           EV_SLAC_B.CCaller2_o2_l.V2G_Message.Body.ChargeParameterDiscoveryRes.EVSEProcessing);
        EV_SLAC_B.RelationalOperator5 = (boolean_T)
          (EV_SLAC_B.CCaller2_o2_l.V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.DC_EVSEStatus.EVSENotification
           == EV_SLAC_P.EnumeratedConstant4_Value);
        if (EV_SLAC_B.RelationalOperator5) {
          EV_SLAC_B.RelationalOperator5 = (boolean_T)
            (EV_SLAC_B.CCaller2_o2_l.V2G_Message.Body.ChargeParameterDiscoveryRes.EVSEProcessing
             == EV_SLAC_P.EnumeratedConstant3_Value_h);
          if (EV_SLAC_B.RelationalOperator5) {
            EV_SLAC_B.CCaller2_o1_h = EV_SLAC_P.Constant_Value_m;
          } else {
            EV_SLAC_B.RelationalOperator5 = (boolean_T)
              (EV_SLAC_P.EnumeratedConstant1_Value_p ==
               EV_SLAC_B.CCaller2_o2_l.V2G_Message.Body.ChargeParameterDiscoveryRes.ResponseCode);
            EV_SLAC_B.AND1_aw = (boolean_T)(((int32_T)
              EV_SLAC_B.RelationalOperator5) && ((int32_T)
              EV_SLAC_B.RelationalOperator3));
            EV_SLAC_B.RelationalOperator5 = (boolean_T)((int32_T)
              EV_SLAC_B.CCaller2_o2_l.V2G_Message.Body.ChargeParameterDiscoveryRes_isUsed
              == (int32_T)EV_SLAC_P.CompareToConstant_const_ld);
            EV_SLAC_B.AND_e = (boolean_T)((int32_T)
              EV_SLAC_B.CCaller2_o2_l.V2G_Message_isUsed == (int32_T)
              EV_SLAC_P.CompareToConstant1_const_cg);
            EV_SLAC_B.SumofElements_c = (uint8_T)0U;
            for (EV_SLAC_B.i_p = 0; EV_SLAC_B.i_p < 8; EV_SLAC_B.i_p++) {
              EV_SLAC_B.rtb_RelationalOperator2_l_e = (boolean_T)((int32_T)
                EV_SLAC_SharedDSM.EVSE_PAIRING_SET.SessionID.bytes[EV_SLAC_B.i_p]
                != (int32_T)
                EV_SLAC_B.CCaller2_o2_l.V2G_Message.Header.SessionID.bytes[EV_SLAC_B.i_p]);
              EV_SLAC_B.SumofElements_c = (uint8_T)((uint32_T)
                EV_SLAC_B.SumofElements_c + (uint32_T)(int32_T)
                EV_SLAC_B.rtb_RelationalOperator2_l_e);
            }

            EV_SLAC_B.CCaller2_o1_h = (((int32_T)EV_SLAC_B.SumofElements_c !=
              (int32_T)EV_SLAC_P.Constant_Value_jx) ||
              (((EV_SLAC_B.CCaller2_o1_h != EV_SLAC_P.Constant_Value_my) ||
                (!(int32_T)EV_SLAC_B.AND_e) || (!(int32_T)
              EV_SLAC_B.RelationalOperator5)) != EV_SLAC_P.Constant_Value_fr) ||
              (!(int32_T)EV_SLAC_B.AND1_aw));
          }
        } else {
          EV_SLAC_B.CCaller2_o1_h = EV_SLAC_P.Constant1_Value_k;
        }

        snprintf(&EV_SLAC_B.rtb_ASCIItoString_kc_o[0], 256U,
                 "ChargeParameterDiscovery: SessionID= %s , Notify = %d, retCode : %d",
                 &EV_SLAC_B.rtb_StringConcatenate_k_c[0], EV_SLAC_B.Cast3_p,
                 EV_SLAC_B.CCaller2_o1_h);
        strncpy(&EV_SLAC_B.cv2[0], &EV_SLAC_B.rtb_ASCIItoString_kc_o[0], 120U);
        for (EV_SLAC_B.i_p = 0; EV_SLAC_B.i_p < 120; EV_SLAC_B.i_p++) {
          EV_SLAC_B.Cast2_d[EV_SLAC_B.i_p] = (int8_T)(uint8_T)
            EV_SLAC_B.cv2[EV_SLAC_B.i_p];
        }

        slac_debug_ported(EV_SLAC_P.CCaller1_status_c, &EV_SLAC_B.Cast2_d[0]);
        if (((int32_T)EV_SLAC_B.RelationalOperator3) && ((int32_T)
             EV_SLAC_B.CCaller2_o2_l.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList_isUsed
             > 0)) {
          EV_SLAC_SharedDSM.EVCC_CONFIG_SET.vc_SASchedule_List =
            EV_SLAC_B.CCaller2_o2_l.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList;
          EV_SLAC_B.Saturation_m =
            EV_SLAC_B.CCaller2_o2_l.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.arrayLen;
          if ((int32_T)EV_SLAC_B.Saturation_m > (int32_T)
              EV_SLAC_P.Saturation_UpperSat_c) {
            EV_SLAC_B.Saturation_m = EV_SLAC_P.Saturation_UpperSat_c;
          } else if ((int32_T)EV_SLAC_B.Saturation_m < (int32_T)
                     EV_SLAC_P.Saturation_LowerSat_d) {
            EV_SLAC_B.Saturation_m = EV_SLAC_P.Saturation_LowerSat_d;
          }

          EV_SLAC_B.s196_iter = (uint16_T)0U;
          while ((int32_T)EV_SLAC_B.s196_iter < (int32_T)EV_SLAC_B.Saturation_m)
          {
            expl_temp =
              &EV_SLAC_B.CCaller2_o2_l.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.data_Array
              [EV_SLAC_B.s196_iter];
            if ((int32_T)expl_temp->PMaxSchedule.PMaxScheduleEntry.arrayLen >
                (int32_T)EV_SLAC_P.Saturation_UpperSat) {
              EV_SLAC_B.Saturation_i = EV_SLAC_P.Saturation_UpperSat;
            } else if ((int32_T)
                       expl_temp->PMaxSchedule.PMaxScheduleEntry.arrayLen <
                       (int32_T)EV_SLAC_P.Saturation_LowerSat) {
              EV_SLAC_B.Saturation_i = EV_SLAC_P.Saturation_LowerSat;
            } else {
              EV_SLAC_B.Saturation_i =
                expl_temp->PMaxSchedule.PMaxScheduleEntry.arrayLen;
            }

            EV_SLAC_B.Cast3_p = 0;
            while (EV_SLAC_B.Cast3_p < (int32_T)EV_SLAC_B.Saturation_i) {
              EV_SLAC_B.Product = EV_SLAC_rt_powf_snf(10.0F, (real32_T)
                expl_temp->
                PMaxSchedule.PMaxScheduleEntry.data_Array[EV_SLAC_B.Cast3_p].
                PMax.Multiplier) * (real32_T)
                expl_temp->
                PMaxSchedule.PMaxScheduleEntry.data_Array[EV_SLAC_B.Cast3_p].
                PMax.Value;
              if (EV_SLAC_B.Cast3_p == 0) {
                memcpy(&EV_SLAC_B.Assignment_o[0],
                       &EV_SLAC_SharedDSM.EVSE_PAIRING_SET.PmaxScheduleList
                       [(int32_T)EV_SLAC_B.s196_iter * 13], 13U * sizeof
                       (real32_T));
              }

              EV_SLAC_B.Assignment_o[EV_SLAC_B.Cast3_p] = EV_SLAC_B.Product;
              if (EV_SLAC_B.Cast3_p == 0) {
                memcpy(&EV_SLAC_B.Assignment1_c[0], &EV_SLAC_B.Assignment_o[0],
                       13U * sizeof(real32_T));
              }

              EV_SLAC_B.Assignment1_c[EV_SLAC_B.Saturation_i] =
                EV_SLAC_B.Product;
              EV_SLAC_EnabledSubsystem
                (expl_temp->
                 PMaxSchedule.PMaxScheduleEntry.data_Array[EV_SLAC_B.Cast3_p].
                 RelativeTimeInterval_isUsed,
                 &expl_temp->
                 PMaxSchedule.PMaxScheduleEntry.data_Array[EV_SLAC_B.Cast3_p].
                 RelativeTimeInterval, &EV_SLAC_B.EnabledSubsystem);
              if (EV_SLAC_B.Cast3_p == 0) {
                memcpy(&EV_SLAC_B.Assignment2_n[0],
                       &EV_SLAC_SharedDSM.EVSE_PAIRING_SET.TimePointPmaxScheduleList
                       [(int32_T)EV_SLAC_B.s196_iter * 13], 13U * sizeof
                       (real32_T));
              }

              EV_SLAC_B.Assignment2_n[EV_SLAC_B.Cast3_p] =
                EV_SLAC_B.EnabledSubsystem.CastToSingle;
              if (EV_SLAC_B.Cast3_p == 0) {
                memcpy(&EV_SLAC_B.Assignment3_d[0], &EV_SLAC_B.Assignment2_n[0],
                       13U * sizeof(real32_T));
              }

              EV_SLAC_B.Assignment3_d[EV_SLAC_B.Saturation_i] =
                EV_SLAC_B.EnabledSubsystem.Add;
              EV_SLAC_B.Cast3_p++;
            }

            if ((int32_T)EV_SLAC_B.s196_iter == 0) {
              memcpy(&EV_SLAC_B.Assignment1[0],
                     &EV_SLAC_SharedDSM.EVSE_PAIRING_SET.PmaxScheduleList[0],
                     39U * sizeof(real32_T));
            }

            memcpy(&EV_SLAC_B.Assignment1[(int32_T)EV_SLAC_B.s196_iter * 13],
                   &EV_SLAC_B.Assignment1_c[0], 13U * sizeof(real32_T));
            if ((int32_T)EV_SLAC_B.s196_iter == 0) {
              memcpy(&EV_SLAC_B.Assignment2[0],
                     &EV_SLAC_SharedDSM.EVSE_PAIRING_SET.TimePointPmaxScheduleList
                     [0], 39U * sizeof(real32_T));
            }

            memcpy(&EV_SLAC_B.Assignment2[(int32_T)EV_SLAC_B.s196_iter * 13],
                   &EV_SLAC_B.Assignment3_d[0], 13U * sizeof(real32_T));
            if ((int32_T)expl_temp->SalesTariff_isUsed > 0) {
              if ((int32_T)expl_temp->SalesTariff.SalesTariffEntry.arrayLen >
                  (int32_T)EV_SLAC_P.Saturation1_UpperSat) {
                EV_SLAC_B.Saturation_i = EV_SLAC_P.Saturation1_UpperSat;
              } else if ((int32_T)
                         expl_temp->SalesTariff.SalesTariffEntry.arrayLen <
                         (int32_T)EV_SLAC_P.Saturation1_LowerSat) {
                EV_SLAC_B.Saturation_i = EV_SLAC_P.Saturation1_LowerSat;
              } else {
                EV_SLAC_B.Saturation_i =
                  expl_temp->SalesTariff.SalesTariffEntry.arrayLen;
              }

              EV_SLAC_B.Cast3_p = 0;
              while (EV_SLAC_B.Cast3_p < (int32_T)EV_SLAC_B.Saturation_i) {
                if (EV_SLAC_B.Cast3_p == 0) {
                  memcpy(&EV_SLAC_B.Assignment_p[0],
                         &EV_SLAC_SharedDSM.EVSE_PAIRING_SET.EpriceScheduleList
                         [(int32_T)EV_SLAC_B.s196_iter * 13], 13U * sizeof
                         (real32_T));
                }

                EV_SLAC_B.Product = (real32_T)
                  expl_temp->
                  SalesTariff.SalesTariffEntry.data_Array[EV_SLAC_B.Cast3_p].
                  EPriceLevel;
                EV_SLAC_B.Assignment_p[EV_SLAC_B.Cast3_p] = EV_SLAC_B.Product;
                if (EV_SLAC_B.Cast3_p == 0) {
                  memcpy(&EV_SLAC_B.Assignment1_o[0], &EV_SLAC_B.Assignment_p[0],
                         13U * sizeof(real32_T));
                }

                EV_SLAC_B.Assignment1_o[EV_SLAC_B.Saturation_i] =
                  EV_SLAC_B.Product;
                EV_SLAC_EnabledSubsystem
                  (expl_temp->
                   SalesTariff.SalesTariffEntry.data_Array[EV_SLAC_B.Cast3_p].
                   RelativeTimeInterval_isUsed,
                   &expl_temp->
                   SalesTariff.SalesTariffEntry.data_Array[EV_SLAC_B.Cast3_p].
                   RelativeTimeInterval, &EV_SLAC_B.EnabledSubsystem_p);
                if (EV_SLAC_B.Cast3_p == 0) {
                  memcpy(&EV_SLAC_B.Assignment2_l[0],
                         &EV_SLAC_SharedDSM.EVSE_PAIRING_SET.TimePointPriceScheduleList
                         [(int32_T)EV_SLAC_B.s196_iter * 13], 13U * sizeof
                         (real32_T));
                }

                EV_SLAC_B.Assignment2_l[EV_SLAC_B.Cast3_p] =
                  EV_SLAC_B.EnabledSubsystem_p.CastToSingle;
                if (EV_SLAC_B.Cast3_p == 0) {
                  memcpy(&EV_SLAC_B.Assignment3_g[0], &EV_SLAC_B.Assignment2_l[0],
                         13U * sizeof(real32_T));
                }

                EV_SLAC_B.Assignment3_g[EV_SLAC_B.Saturation_i] =
                  EV_SLAC_B.EnabledSubsystem_p.Add;
                EV_SLAC_B.Cast3_p++;
              }
            }

            if ((int32_T)EV_SLAC_B.s196_iter == 0) {
              memcpy(&EV_SLAC_B.Assignment3[0],
                     &EV_SLAC_SharedDSM.EVSE_PAIRING_SET.PmaxScheduleList[0],
                     39U * sizeof(real32_T));
            }

            memcpy(&EV_SLAC_B.Assignment3[(int32_T)EV_SLAC_B.s196_iter * 13],
                   &EV_SLAC_B.Assignment1_o[0], 13U * sizeof(real32_T));
            if ((int32_T)EV_SLAC_B.s196_iter == 0) {
              memcpy(&EV_SLAC_B.Assignment4[0],
                     &EV_SLAC_SharedDSM.EVSE_PAIRING_SET.TimePointPmaxScheduleList
                     [0], 39U * sizeof(real32_T));
            }

            memcpy(&EV_SLAC_B.Assignment4[(int32_T)EV_SLAC_B.s196_iter * 13],
                   &EV_SLAC_B.Assignment3_g[0], 13U * sizeof(real32_T));
            EV_SLAC_B.Cast_e = (uint16_T)expl_temp->SAScheduleTupleID;
            EV_SLAC_B.s196_iter = (uint16_T)((uint32_T)(int32_T)
              EV_SLAC_B.s196_iter + 1U);
          }

          EV_SLAC_SharedDSM.EVSE_PAIRING_SET.ScheduleTupleIDList =
            EV_SLAC_B.Cast_e;
          EV_SLAC_SharedDSM.EVSE_PAIRING_SET.ScheduleTupleLen =
            EV_SLAC_B.Saturation_m;
          memcpy(&EV_SLAC_SharedDSM.EVSE_PAIRING_SET.PmaxScheduleList[0],
                 &EV_SLAC_B.Assignment1[0], 39U * sizeof(real32_T));
          memcpy(&EV_SLAC_SharedDSM.EVSE_PAIRING_SET.TimePointPmaxScheduleList[0],
                 &EV_SLAC_B.Assignment2[0], 39U * sizeof(real32_T));
          memcpy(&EV_SLAC_SharedDSM.EVSE_PAIRING_SET.EpriceScheduleList[0],
                 &EV_SLAC_B.Assignment3[0], 39U * sizeof(real32_T));
          memcpy(&EV_SLAC_SharedDSM.EVSE_PAIRING_SET.TimePointPriceScheduleList
                 [0], &EV_SLAC_B.Assignment4[0], 39U * sizeof(real32_T));
        }

        EV_SLAC_DW.ret = EV_SLAC_B.CCaller2_o1_h;
      }
    } else if ((EV_SLAC_DW.ret == 2) && (((((EV_SLAC_M->Timing.clockTick1) *
        0.01) - EV_SLAC_DW.previousTime) + EV_SLAC_DW.temporalCounter_i1) *
                1000.0 >= 250.0)) {
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.temporalCounter_i1 = 0.0;
      EV_SLAC_DW.is_PARAMETER_DISCOVERY = EV_SLAC_IN_BLOCK;
      EV_SLAC_DW.is_BLOCK_f = EV_SLAC_IN_REQUEST;
      EV_SLAC_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq(
        &EV_SLAC_SharedDSM.EVSE_PAIRING_SET, &EV_SLAC_SharedDSM.ExiDoc_Buff,
        &EV_SLAC_B.V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq,
        &EV_SLAC_P.V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq);
      EV_SLAC_DW.ret =
        EV_SLAC_B.V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq.CCaller1_o1;
      EV_SLAC_DW.StreamMesgOut_msgReservedData =
        EV_SLAC_B.V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq.CCaller1_o2;
    } else {
      switch (EV_SLAC_DW.ret) {
       case 0:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_PARAMETER_DISCOVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_ht = 3U;
        break;

       case 1:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_PARAMETER_DISCOVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_ht = 2U;
        break;
      }
    }

    switch (EV_SLAC_DW.exitPortIndex_ht) {
     case 2:
      EV_SLAC_DW.exitPortIndex_ht = 0U;
      EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
      break;

     case 3:
      EV_SLAC_DW.exitPortIndex_ht = 0U;
      EV_SLAC_DW.temporalCounter_i2 = 0.0;
      EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_CABLE_CHECK;
      EV_SLAC_DW.temporalCounter_i1 = 0.0;
      EV_SLAC_DW.is_CABLE_CHECK = EV_SLAC_IN_BLOCK;
      EV_SLAC_DW.is_BLOCK_j = EV_SLAC_IN_REQUEST;
      EV_SLAC_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq
        (&EV_SLAC_SharedDSM.EVSE_PAIRING_SET, &EV_SLAC_SharedDSM.ExiDoc_Buff,
         &EV_SLAC_B.V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq,
         &EV_SLAC_P.V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq);
      EV_SLAC_DW.ret =
        EV_SLAC_B.V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq.CCaller1_o1;
      EV_SLAC_DW.StreamMesgOut_msgReservedData =
        EV_SLAC_B.V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq.CCaller1_o2;
      break;

     case 4:
      EV_SLAC_DW.exitPortIndex_ht = 0U;
      EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
      break;
    }
  }
}

static void EV_SLAC_PRE_CHARGE(void)
{
  EV_SLAC_B.d1 = ((EV_SLAC_M->Timing.clockTick1) * 0.01) -
    EV_SLAC_DW.previousTime;
  if ((EV_SLAC_B.d1 + EV_SLAC_DW.temporalCounter_i2) * 1000.0 >= (real_T)
      EV_SLAC_DW.V2G_EVCC_Ongoing_Timeout) {
    switch (EV_SLAC_DW.is_PRE_CHARGE) {
     case EV_SLAC_IN_BLOCK:
      if ((int32_T)EV_SLAC_DW.is_BLOCK_h == (int32_T)EV_SLAC_IN_REQUEST) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_BLOCK_h = EV_SLAC_IN_NO_ACTIVE_CHILD;
      } else {
        EV_SLAC_DW.is_BLOCK_h = EV_SLAC_IN_NO_ACTIVE_CHILD;
      }

      EV_SLAC_DW.is_PRE_CHARGE = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;

     case EV_SLAC_IN_RESPONSE:
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_PRE_CHARGE = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;
    }

    EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
  } else {
    if ((int32_T)EV_SLAC_DW.is_PRE_CHARGE == (int32_T)EV_SLAC_IN_BLOCK) {
      if ((EV_SLAC_B.d1 + EV_SLAC_DW.temporalCounter_i1) * 1000.0 >= (real_T)
          EV_SLAC_DW.PreChargeReq_Timeout) {
        if ((int32_T)EV_SLAC_DW.is_BLOCK_h == (int32_T)EV_SLAC_IN_REQUEST) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_BLOCK_h = EV_SLAC_IN_NO_ACTIVE_CHILD;
        } else {
          EV_SLAC_DW.is_BLOCK_h = EV_SLAC_IN_NO_ACTIVE_CHILD;
        }

        EV_SLAC_DW.is_PRE_CHARGE = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_ha = 4U;
      } else if ((int32_T)EV_SLAC_DW.is_BLOCK_h == (int32_T)EV_SLAC_IN_REQUEST)
      {
        switch (EV_SLAC_DW.ret) {
         case 0:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_BLOCK_h = EV_SLAC_IN_waitingRes_j;
          EV_SLAC_sf_msg_send_StreamMesgOut();
          break;

         case 1:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_BLOCK_h = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.is_PRE_CHARGE = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_ha = 2U;
          break;
        }
      } else if (EV_SLAC_sf_msg_pop_StreamMesgIn()) {
        EV_SLAC_DW.is_BLOCK_h = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.is_PRE_CHARGE = EV_SLAC_IN_RESPONSE;
        EV_SLAC_B.StreamIn_m = EV_SLAC_DW.StreamMesgIn_msgReservedData;
        EV_SLAC_B.CCaller2_o2_j = EV_SLAC_SharedDSM.ExiDoc_Buff;
        EV_SLAC_B.Cast5_f = decode_iso1ExiDocument(&EV_SLAC_B.StreamIn_m,
          &EV_SLAC_B.CCaller2_o2_j);
        EV_SLAC_SharedDSM.EVCC_CONFIG_SET.vc_EVSEPresentVoltage =
          EV_SLAC_B.CCaller2_o2_j.V2G_Message.Body.PreChargeRes.EVSEPresentVoltage;
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_j.V2G_Message.Header.SessionID.bytes[0],
           &EV_SLAC_B.sf_MATLABFunction_i3);
        EV_SLAC_B.rtb_ASCIItoString_j_c[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_i3.y[0];
        EV_SLAC_B.rtb_ASCIItoString_j_c[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_i3.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_j_c[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_j.V2G_Message.Header.SessionID.bytes[1],
           &EV_SLAC_B.sf_MATLABFunction_dn);
        EV_SLAC_B.rtb_ASCIItoString_b_p[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_dn.y[0];
        EV_SLAC_B.rtb_ASCIItoString_b_p[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_dn.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_b_p[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_j.V2G_Message.Header.SessionID.bytes[2],
           &EV_SLAC_B.sf_MATLABFunction_eo);
        EV_SLAC_B.rtb_ASCIItoString_jv_p[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_eo.y[0];
        EV_SLAC_B.rtb_ASCIItoString_jv_p[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_eo.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_jv_p[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_j.V2G_Message.Header.SessionID.bytes[3],
           &EV_SLAC_B.sf_MATLABFunction_oc);
        EV_SLAC_B.rtb_ASCIItoString_eg_a[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_oc.y[0];
        EV_SLAC_B.rtb_ASCIItoString_eg_a[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_oc.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_eg_a[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_j.V2G_Message.Header.SessionID.bytes[4],
           &EV_SLAC_B.sf_MATLABFunction_la);
        EV_SLAC_B.rtb_ASCIItoString_bt_e[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_la.y[0];
        EV_SLAC_B.rtb_ASCIItoString_bt_e[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_la.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_bt_e[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_j.V2G_Message.Header.SessionID.bytes[5],
           &EV_SLAC_B.sf_MATLABFunction_bx);
        EV_SLAC_B.rtb_ASCIItoString_l5_a[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_bx.y[0];
        EV_SLAC_B.rtb_ASCIItoString_l5_a[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_bx.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_l5_a[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_j.V2G_Message.Header.SessionID.bytes[6],
           &EV_SLAC_B.sf_MATLABFunction_lo);
        EV_SLAC_B.rtb_ASCIItoString_k_a[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_lo.y[0];
        EV_SLAC_B.rtb_ASCIItoString_k_a[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_lo.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_k_a[2], 0, 254U * sizeof(char_T));
        EV_SLAC_MATLABFunction
          (EV_SLAC_B.CCaller2_o2_j.V2G_Message.Header.SessionID.bytes[7],
           &EV_SLAC_B.sf_MATLABFunction_ia);
        EV_SLAC_B.rtb_ASCIItoString_m0_i[0] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_ia.y[0];
        EV_SLAC_B.rtb_ASCIItoString_m0_i[1] = (char_T)(int8_T)
          EV_SLAC_B.sf_MATLABFunction_ia.y[1];
        memset(&EV_SLAC_B.rtb_ASCIItoString_m0_i[2], 0, 254U * sizeof(char_T));
        EV_SLAC_B.rtb_StringConcatenate_l_l[0] = '\x00';
        strncat(&EV_SLAC_B.rtb_StringConcatenate_l_l[0U],
                &EV_SLAC_B.rtb_ASCIItoString_j_c[0], 255U);
        EV_SLAC_B.u4 = strlen(&EV_SLAC_B.rtb_StringConcatenate_l_l[0U]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_l_l[EV_SLAC_B.u4],
                &EV_SLAC_B.rtb_ASCIItoString_b_p[0], 255U - EV_SLAC_B.u4);
        EV_SLAC_B.u4 += strlen(&EV_SLAC_B.rtb_StringConcatenate_l_l[EV_SLAC_B.u4]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_l_l[EV_SLAC_B.u4],
                &EV_SLAC_B.rtb_ASCIItoString_jv_p[0], 255U - EV_SLAC_B.u4);
        EV_SLAC_B.u4 += strlen(&EV_SLAC_B.rtb_StringConcatenate_l_l[EV_SLAC_B.u4]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_l_l[EV_SLAC_B.u4],
                &EV_SLAC_B.rtb_ASCIItoString_eg_a[0], 255U - EV_SLAC_B.u4);
        EV_SLAC_B.u4 += strlen(&EV_SLAC_B.rtb_StringConcatenate_l_l[EV_SLAC_B.u4]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_l_l[EV_SLAC_B.u4],
                &EV_SLAC_B.rtb_ASCIItoString_bt_e[0], 255U - EV_SLAC_B.u4);
        EV_SLAC_B.u4 += strlen(&EV_SLAC_B.rtb_StringConcatenate_l_l[EV_SLAC_B.u4]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_l_l[EV_SLAC_B.u4],
                &EV_SLAC_B.rtb_ASCIItoString_l5_a[0], 255U - EV_SLAC_B.u4);
        EV_SLAC_B.u4 += strlen(&EV_SLAC_B.rtb_StringConcatenate_l_l[EV_SLAC_B.u4]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_l_l[EV_SLAC_B.u4],
                &EV_SLAC_B.rtb_ASCIItoString_k_a[0], 255U - EV_SLAC_B.u4);
        EV_SLAC_B.u4 += strlen(&EV_SLAC_B.rtb_StringConcatenate_l_l[EV_SLAC_B.u4]);
        strncat(&EV_SLAC_B.rtb_StringConcatenate_l_l[EV_SLAC_B.u4],
                &EV_SLAC_B.rtb_ASCIItoString_m0_i[0], 255U - EV_SLAC_B.u4);
        EV_SLAC_B.Cast3_i = (int32_T)
          EV_SLAC_B.CCaller2_o2_j.V2G_Message.Header.Notification_isUsed;
        EV_SLAC_B.SumofElements_b = (uint8_T)0U;
        for (EV_SLAC_B.i_px = 0; EV_SLAC_B.i_px < 8; EV_SLAC_B.i_px++) {
          EV_SLAC_B.RelationalOperator5_g = (boolean_T)((int32_T)
            EV_SLAC_SharedDSM.EVSE_PAIRING_SET.SessionID.bytes[EV_SLAC_B.i_px]
            != (int32_T)
            EV_SLAC_B.CCaller2_o2_j.V2G_Message.Header.SessionID.bytes[EV_SLAC_B.i_px]);
          EV_SLAC_B.SumofElements_b = (uint8_T)((uint32_T)
            EV_SLAC_B.SumofElements_b + (uint32_T)(int32_T)
            EV_SLAC_B.RelationalOperator5_g);
        }

        EV_SLAC_B.RelationalOperator5_g = (boolean_T)((int32_T)
          EV_SLAC_B.CCaller2_o2_j.V2G_Message_isUsed == (int32_T)
          EV_SLAC_P.CompareToConstant1_const_hl);
        EV_SLAC_B.RelationalOperator1_p = (boolean_T)((int32_T)
          EV_SLAC_B.CCaller2_o2_j.V2G_Message.Body.PreChargeRes_isUsed ==
          (int32_T)EV_SLAC_P.CompareToConstant_const_e);
        EV_SLAC_B.RelationalOperator5_g_f = (boolean_T)((EV_SLAC_B.Cast5_f !=
          EV_SLAC_P.Constant_Value_a) || (!(int32_T)
          EV_SLAC_B.RelationalOperator5_g) || (!(int32_T)
          EV_SLAC_B.RelationalOperator1_p));
        EV_SLAC_B.RelationalOperator1_p = (boolean_T)
          (EV_SLAC_P.EnumeratedConstant1_Value_g ==
           EV_SLAC_B.CCaller2_o2_j.V2G_Message.Body.PreChargeRes.ResponseCode);
        EV_SLAC_B.RelationalOperator5_g = (boolean_T)
          (EV_SLAC_P.EnumeratedConstant4_Value_b ==
           EV_SLAC_B.CCaller2_o2_j.V2G_Message.Body.PreChargeRes.DC_EVSEStatus.EVSENotification);
        if ((int32_T)
            EV_SLAC_B.CCaller2_o2_j.V2G_Message.Body.PreChargeRes.DC_EVSEStatus.EVSEIsolationStatus_isUsed
            != 0) {
          EV_SLAC_B.RelationalOperator6_e = (boolean_T)
            (EV_SLAC_P.EnumeratedConstant5_Value_k ==
             EV_SLAC_B.CCaller2_o2_j.V2G_Message.Body.PreChargeRes.DC_EVSEStatus.EVSEIsolationStatus);
          EV_SLAC_B.Cast5_f = (int32_T)EV_SLAC_B.RelationalOperator6_e;
        } else {
          EV_SLAC_B.Cast5_f = (int32_T)EV_SLAC_P.Constant1_Value_b;
        }

        EV_SLAC_B.RelationalOperator6_e = (boolean_T)
          (EV_SLAC_B.CCaller2_o2_j.V2G_Message.Body.PreChargeRes.DC_EVSEStatus.EVSEStatusCode
           == EV_SLAC_P.EnumeratedConstant6_Value_m);
        EV_SLAC_B.RelationalOperator6_e = (boolean_T)(((int32_T)
          EV_SLAC_B.SumofElements_b != (int32_T)EV_SLAC_P.Constant_Value_o) ||
          ((int32_T)EV_SLAC_B.RelationalOperator5_g_f !=
           EV_SLAC_P.Constant_Value_k) || ((!(int32_T)
          EV_SLAC_B.RelationalOperator1_p) || ((!(int32_T)
          EV_SLAC_B.RelationalOperator5_g) || (EV_SLAC_B.Cast5_f == 0) ||
          (!(int32_T)EV_SLAC_B.RelationalOperator6_e))));
        snprintf(&EV_SLAC_B.rtb_ASCIItoString_j_c[0], 256U,
                 "PreCharge: SessionID= %s , Notify = %d, retCode : %d",
                 &EV_SLAC_B.rtb_StringConcatenate_l_l[0], EV_SLAC_B.Cast3_i,
                 (int32_T)EV_SLAC_B.RelationalOperator6_e);
        strncpy(&EV_SLAC_B.cv3[0], &EV_SLAC_B.rtb_ASCIItoString_j_c[0], 120U);
        for (EV_SLAC_B.i_px = 0; EV_SLAC_B.i_px < 120; EV_SLAC_B.i_px++) {
          EV_SLAC_B.Cast2_e[EV_SLAC_B.i_px] = (int8_T)(uint8_T)
            EV_SLAC_B.cv3[EV_SLAC_B.i_px];
        }

        slac_debug_ported(EV_SLAC_P.CCaller1_status_d, &EV_SLAC_B.Cast2_e[0]);
        EV_SLAC_DW.ret = (int32_T)EV_SLAC_B.RelationalOperator6_e;
      }
    } else if (EV_SLAC_DW.ret != 0) {
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.temporalCounter_i1 = 0.0;
      EV_SLAC_DW.is_PRE_CHARGE = EV_SLAC_IN_BLOCK;
      EV_SLAC_DW.is_BLOCK_h = EV_SLAC_IN_REQUEST;
      EV_SLAC_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq
        (&EV_SLAC_SharedDSM.EVSE_PAIRING_SET, &EV_SLAC_SharedDSM.ExiDoc_Buff,
         &EV_SLAC_B.V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq,
         &EV_SLAC_P.V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq);
      EV_SLAC_DW.ret =
        EV_SLAC_B.V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq.CCaller1_o1;
      EV_SLAC_DW.StreamMesgOut_msgReservedData =
        EV_SLAC_B.V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq.CCaller1_o2;
    } else {
      switch (EV_SLAC_DW.ret) {
       case 0:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_PRE_CHARGE = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_ha = 3U;
        break;

       case 1:
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_PRE_CHARGE = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_ha = 2U;
        break;
      }
    }

    switch (EV_SLAC_DW.exitPortIndex_ha) {
     case 2:
      EV_SLAC_DW.exitPortIndex_ha = 0U;
      EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
      break;

     case 3:
      EV_SLAC_DW.exitPortIndex_ha = 0U;
      EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_POWER_DELIVERY;
      EV_SLAC_DW.temporalCounter_i1 = 0.0;
      EV_SLAC_DW.is_POWER_DELIVERY = EV_SLAC_IN_BLOCK;
      EV_SLAC_DW.is_BLOCK_o = EV_SLAC_IN_REQUEST;
      EV_SLAC_B.BusAssignment4_j = EV_SLAC_P.Constant13_Value_c;
      EV_SLAC_B.BusAssignment4_j.size = (uint32_T)EV_SLAC_P.Constant11_Value_b;
      EV_SLAC_B.BusAssignment4_j.pos = (uint32_T)EV_SLAC_P.Constant10_Value_d;
      EV_SLAC_B.CCaller2_o2_j = EV_SLAC_SharedDSM.ExiDoc_Buff;
      repaireExiDocBuff(&EV_SLAC_B.CCaller2_o2_j);
      EV_SLAC_B.CCaller2_o2_j.V2G_Message.Header.SessionID =
        EV_SLAC_SharedDSM.EVSE_PAIRING_SET.SessionID;
      EV_SLAC_B.CCaller2_o2_j.V2G_Message.Body.PowerDeliveryReq =
        EV_SLAC_P.Constant5_Value;
      EV_SLAC_B.CCaller2_o2_j.V2G_Message.Body.PowerDeliveryReq.ChargeProgress =
        EV_SLAC_P.EnumeratedConstant_Value_g;
      EV_SLAC_B.CCaller2_o2_j.V2G_Message.Body.PowerDeliveryReq.SAScheduleTupleID
        = (uint8_T)EV_SLAC_P.Constant_Value_mu;
      EV_SLAC_B.CCaller2_o2_j.V2G_Message.Body.PowerDeliveryReq_isUsed =
        EV_SLAC_P.Constant4_Value_or;
      EV_SLAC_B.CCaller2_o2_j.V2G_Message_isUsed = EV_SLAC_P.Constant1_Value_fu;
      EV_SLAC_B.CCaller1_o2 = EV_SLAC_B.BusAssignment4_j;
      EV_SLAC_B.Cast5_f = encode_iso1ExiDocument(&EV_SLAC_B.CCaller1_o2,
        &EV_SLAC_B.CCaller2_o2_j);
      snprintf(&EV_SLAC_B.rtb_StringConcatenate_l_l[0], 256U,
               "PowerDelivery request: status: %d", EV_SLAC_B.Cast5_f);
      strncpy(&EV_SLAC_B.cv9[0], &EV_SLAC_B.rtb_StringConcatenate_l_l[0], 100U);
      for (EV_SLAC_B.i_px = 0; EV_SLAC_B.i_px < 100; EV_SLAC_B.i_px++) {
        EV_SLAC_B.Cast1_bt[EV_SLAC_B.i_px] = (int8_T)(uint8_T)
          EV_SLAC_B.cv9[EV_SLAC_B.i_px];
      }

      slac_debug_ported(EV_SLAC_P.CCaller_status_fu, &EV_SLAC_B.Cast1_bt[0]);
      EV_SLAC_DW.ret = EV_SLAC_B.Cast5_f;
      EV_SLAC_DW.StreamMesgOut_msgReservedData = EV_SLAC_B.CCaller1_o2;
      break;

     case 4:
      EV_SLAC_DW.exitPortIndex_ha = 0U;
      EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
      break;
    }
  }
}

static void EV_SLAC_exit_internal_V2G_SEQ(void)
{
  switch (EV_SLAC_DW.is_V2G_SEQ) {
   case EV_SLAC_IN_AUTHORIZATION:
    switch (EV_SLAC_DW.is_AUTHORIZATION) {
     case EV_SLAC_IN_BLOCK:
      if ((int32_T)EV_SLAC_DW.is_BLOCK_p == (int32_T)EV_SLAC_IN_REQUEST) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_BLOCK_p = EV_SLAC_IN_NO_ACTIVE_CHILD;
      } else {
        EV_SLAC_DW.is_BLOCK_p = EV_SLAC_IN_NO_ACTIVE_CHILD;
      }

      EV_SLAC_DW.is_AUTHORIZATION = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;

     case EV_SLAC_IN_RESPONSE:
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_AUTHORIZATION = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;
    }

    EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_NO_ACTIVE_CHILD;
    break;

   case EV_SLAC_IN_CABLE_CHECK:
    switch (EV_SLAC_DW.is_CABLE_CHECK) {
     case EV_SLAC_IN_BLOCK:
      if ((int32_T)EV_SLAC_DW.is_BLOCK_j == (int32_T)EV_SLAC_IN_REQUEST) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_BLOCK_j = EV_SLAC_IN_NO_ACTIVE_CHILD;
      } else {
        EV_SLAC_DW.is_BLOCK_j = EV_SLAC_IN_NO_ACTIVE_CHILD;
      }

      EV_SLAC_DW.is_CABLE_CHECK = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;

     case EV_SLAC_IN_RESPONSE:
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_CABLE_CHECK = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;
    }

    EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_NO_ACTIVE_CHILD;
    break;

   case EV_SLAC_IN_PARAMETER_DISCOVERY:
    switch (EV_SLAC_DW.is_PARAMETER_DISCOVERY) {
     case EV_SLAC_IN_BLOCK:
      if ((int32_T)EV_SLAC_DW.is_BLOCK_f == (int32_T)EV_SLAC_IN_REQUEST) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_BLOCK_f = EV_SLAC_IN_NO_ACTIVE_CHILD;
      } else {
        EV_SLAC_DW.is_BLOCK_f = EV_SLAC_IN_NO_ACTIVE_CHILD;
      }

      EV_SLAC_DW.is_PARAMETER_DISCOVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;

     case EV_SLAC_IN_RESPONSE:
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_PARAMETER_DISCOVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;
    }

    EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_NO_ACTIVE_CHILD;
    break;

   case EV_SLAC_IN_PAYMENT_SELECTION:
    switch (EV_SLAC_DW.is_PAYMENT_SELECTION) {
     case EV_SLAC_IN_BLOCK:
      if ((int32_T)EV_SLAC_DW.is_BLOCK_g == (int32_T)EV_SLAC_IN_REQUEST) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_BLOCK_g = EV_SLAC_IN_NO_ACTIVE_CHILD;
      } else {
        EV_SLAC_DW.is_BLOCK_g = EV_SLAC_IN_NO_ACTIVE_CHILD;
      }

      EV_SLAC_DW.is_PAYMENT_SELECTION = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;

     case EV_SLAC_IN_RESPONSE:
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_PAYMENT_SELECTION = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;
    }

    EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_NO_ACTIVE_CHILD;
    break;

   case EV_SLAC_IN_POWER_DELIVERY:
    switch (EV_SLAC_DW.is_POWER_DELIVERY) {
     case EV_SLAC_IN_BLOCK:
      if ((int32_T)EV_SLAC_DW.is_BLOCK_o == (int32_T)EV_SLAC_IN_REQUEST) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_BLOCK_o = EV_SLAC_IN_NO_ACTIVE_CHILD;
      } else {
        EV_SLAC_DW.is_BLOCK_o = EV_SLAC_IN_NO_ACTIVE_CHILD;
      }

      EV_SLAC_DW.is_POWER_DELIVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;

     case EV_SLAC_IN_RESPONSE:
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_POWER_DELIVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;
    }

    EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_NO_ACTIVE_CHILD;
    break;

   case EV_SLAC_IN_PRE_CHARGE:
    switch (EV_SLAC_DW.is_PRE_CHARGE) {
     case EV_SLAC_IN_BLOCK:
      if ((int32_T)EV_SLAC_DW.is_BLOCK_h == (int32_T)EV_SLAC_IN_REQUEST) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_BLOCK_h = EV_SLAC_IN_NO_ACTIVE_CHILD;
      } else {
        EV_SLAC_DW.is_BLOCK_h = EV_SLAC_IN_NO_ACTIVE_CHILD;
      }

      EV_SLAC_DW.is_PRE_CHARGE = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;

     case EV_SLAC_IN_RESPONSE:
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_PRE_CHARGE = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;
    }

    EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_NO_ACTIVE_CHILD;
    break;

   case EV_SLAC_IN_SERVICE_DETAIL:
    if ((int32_T)EV_SLAC_DW.is_SERVICE_DETAIL == (int32_T)EV_SLAC_IN_NOP) {
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_SERVICE_DETAIL = EV_SLAC_IN_NO_ACTIVE_CHILD;
    }

    EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_NO_ACTIVE_CHILD;
    break;

   case EV_SLAC_IN_SERVICE_DISCOVERY:
    switch (EV_SLAC_DW.is_SERVICE_DISCOVERY) {
     case EV_SLAC_IN_REQ_BLOCK:
      if ((int32_T)EV_SLAC_DW.is_REQ_BLOCK == (int32_T)EV_SLAC_IN_REQUEST) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_REQ_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
      } else {
        EV_SLAC_DW.is_REQ_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
      }

      EV_SLAC_DW.is_SERVICE_DISCOVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;

     case EV_SLAC_IN_RESPONSE:
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_SERVICE_DISCOVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
      break;
    }

    EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_NO_ACTIVE_CHILD;
    break;

   default:
    EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_NO_ACTIVE_CHILD;
    break;
  }
}

static void EV_SLAC_V2G_SEQ(void)
{
  if (EV_SLAC_sf_msg_pop_TCP_IP_LostConnect()) {
    EV_SLAC_exit_internal_V2G_SEQ();
    EV_SLAC_DW.is_LinkSetup = EV_SLAC_IN_errorHandle;
    EV_SLAC_V2GLinkSetuperrorHandleTimeOutHandle
      (&EV_SLAC_B.V2GLinkSetuperrorHandleTimeOutHandle,
       &EV_SLAC_P.V2GLinkSetuperrorHandleTimeOutHandle);
  } else {
    switch (EV_SLAC_DW.is_V2G_SEQ) {
     case EV_SLAC_IN_AUTHORIZATION:
      EV_SLAC_AUTHORIZATION();
      break;

     case EV_SLAC_IN_CABLE_CHECK:
      EV_SLAC_CABLE_CHECK();
      break;

     case EV_SLAC_IN_PARAMETER_DISCOVERY:
      EV_SLAC_PARAMETER_DISCOVERY();
      break;

     case EV_SLAC_IN_PAYMENT_SELECTION:
      if ((int32_T)EV_SLAC_DW.is_PAYMENT_SELECTION == (int32_T)EV_SLAC_IN_BLOCK)
      {
        if (((((EV_SLAC_M->Timing.clockTick1) * 0.01) - EV_SLAC_DW.previousTime)
             + EV_SLAC_DW.temporalCounter_i1) * 1000.0 >= (real_T)
            EV_SLAC_DW.PaymentServiceSelectionReq_Timeout) {
          if ((int32_T)EV_SLAC_DW.is_BLOCK_g == (int32_T)EV_SLAC_IN_REQUEST) {
            EV_SLAC_DW.ret = -1;
            EV_SLAC_DW.is_BLOCK_g = EV_SLAC_IN_NO_ACTIVE_CHILD;
          } else {
            EV_SLAC_DW.is_BLOCK_g = EV_SLAC_IN_NO_ACTIVE_CHILD;
          }

          EV_SLAC_DW.is_PAYMENT_SELECTION = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_b = 4U;
        } else if ((int32_T)EV_SLAC_DW.is_BLOCK_g == (int32_T)EV_SLAC_IN_REQUEST)
        {
          switch (EV_SLAC_DW.ret) {
           case 0:
            EV_SLAC_DW.ret = -1;
            EV_SLAC_DW.is_BLOCK_g = EV_SLAC_IN_waitingRes_j;
            EV_SLAC_sf_msg_send_StreamMesgOut();
            break;

           case 1:
            EV_SLAC_DW.ret = -1;
            EV_SLAC_DW.is_BLOCK_g = EV_SLAC_IN_NO_ACTIVE_CHILD;
            EV_SLAC_DW.is_PAYMENT_SELECTION = EV_SLAC_IN_NO_ACTIVE_CHILD;
            EV_SLAC_DW.exitPortIndex_b = 2U;
            break;
          }
        } else if (EV_SLAC_sf_msg_pop_StreamMesgIn()) {
          EV_SLAC_DW.is_BLOCK_g = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.is_PAYMENT_SELECTION = EV_SLAC_IN_RESPONSE;
          EV_SLAC_B.StreamIn_n = EV_SLAC_DW.StreamMesgIn_msgReservedData;
          EV_SLAC_B.CCaller2_o2_n = EV_SLAC_SharedDSM.ExiDoc_Buff;
          EV_SLAC_B.Cast5_g = decode_iso1ExiDocument(&EV_SLAC_B.StreamIn_n,
            &EV_SLAC_B.CCaller2_o2_n);
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[0],
             &EV_SLAC_B.sf_MATLABFunction_bc);
          EV_SLAC_B.rtb_ASCIItoString_gq_b[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_bc.y[0];
          EV_SLAC_B.rtb_ASCIItoString_gq_b[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_bc.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_gq_b[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[1],
             &EV_SLAC_B.sf_MATLABFunction_in);
          EV_SLAC_B.rtb_ASCIItoString_ef_j[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_in.y[0];
          EV_SLAC_B.rtb_ASCIItoString_ef_j[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_in.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_ef_j[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[2],
             &EV_SLAC_B.sf_MATLABFunction_jr);
          EV_SLAC_B.rtb_ASCIItoString_je_f[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_jr.y[0];
          EV_SLAC_B.rtb_ASCIItoString_je_f[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_jr.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_je_f[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[3],
             &EV_SLAC_B.sf_MATLABFunction_b5);
          EV_SLAC_B.rtb_ASCIItoString_f_a[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_b5.y[0];
          EV_SLAC_B.rtb_ASCIItoString_f_a[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_b5.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_f_a[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[4],
             &EV_SLAC_B.sf_MATLABFunction_ex);
          EV_SLAC_B.rtb_ASCIItoString_h_j[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_ex.y[0];
          EV_SLAC_B.rtb_ASCIItoString_h_j[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_ex.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_h_j[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[5],
             &EV_SLAC_B.sf_MATLABFunction_fv);
          EV_SLAC_B.rtb_ASCIItoString_mq_j[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_fv.y[0];
          EV_SLAC_B.rtb_ASCIItoString_mq_j[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_fv.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_mq_j[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[6],
             &EV_SLAC_B.sf_MATLABFunction_pq);
          EV_SLAC_B.rtb_ASCIItoString_np_o[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_pq.y[0];
          EV_SLAC_B.rtb_ASCIItoString_np_o[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_pq.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_np_o[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[7],
             &EV_SLAC_B.sf_MATLABFunction_cxo);
          EV_SLAC_B.rtb_ASCIItoString_nz_n[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_cxo.y[0];
          EV_SLAC_B.rtb_ASCIItoString_nz_n[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_cxo.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_nz_n[2], 0, 254U * sizeof(char_T));
          EV_SLAC_B.rtb_StringConcatenate_f_i[0] = '\x00';
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[0U],
                  &EV_SLAC_B.rtb_ASCIItoString_gq_b[0], 255U);
          EV_SLAC_B.u2 = strlen(&EV_SLAC_B.rtb_StringConcatenate_f_i[0U]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_ef_j[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_je_f[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_f_a[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_h_j[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_mq_j[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_np_o[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_nz_n[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.Cast3_g = (int32_T)
            EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.Notification_isUsed;
          EV_SLAC_B.SumofElements_p = (uint8_T)0U;
          for (EV_SLAC_B.i_k = 0; EV_SLAC_B.i_k < 8; EV_SLAC_B.i_k++) {
            EV_SLAC_B.NAND_m = (boolean_T)((int32_T)
              EV_SLAC_SharedDSM.EVSE_PAIRING_SET.SessionID.bytes[EV_SLAC_B.i_k]
              != (int32_T)
              EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[EV_SLAC_B.i_k]);
            EV_SLAC_B.SumofElements_p = (uint8_T)((uint32_T)
              EV_SLAC_B.SumofElements_p + (uint32_T)(int32_T)EV_SLAC_B.NAND_m);
          }

          EV_SLAC_B.NAND_m = (boolean_T)((int32_T)
            EV_SLAC_B.CCaller2_o2_n.V2G_Message_isUsed == (int32_T)
            EV_SLAC_P.CompareToConstant1_const_cx);
          EV_SLAC_B.AND_cs = (boolean_T)((int32_T)
            EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.PaymentServiceSelectionRes_isUsed
            == (int32_T)EV_SLAC_P.CompareToConstant_const_i);
          EV_SLAC_B.Cast5_g = ((EV_SLAC_B.Cast5_g != EV_SLAC_P.Constant_Value_ll)
                               || (!(int32_T)EV_SLAC_B.NAND_m) || (!(int32_T)
            EV_SLAC_B.AND_cs));
          EV_SLAC_B.AND_cs = (boolean_T)(EV_SLAC_P.EnumeratedConstant1_Value_nm ==
            EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.PaymentServiceSelectionRes.ResponseCode);
          EV_SLAC_B.AND_cs = (boolean_T)(((int32_T)EV_SLAC_B.SumofElements_p !=
            (int32_T)EV_SLAC_P.Constant_Value_dl) || (EV_SLAC_B.Cast5_g !=
            EV_SLAC_P.Constant_Value_l) || (!(int32_T)EV_SLAC_B.AND_cs));
          snprintf(&EV_SLAC_B.rtb_ASCIItoString_gq_b[0], 256U,
                   "PaymentServiceSelection: SessionID= %s , Notify = %d, retCode : %d",
                   &EV_SLAC_B.rtb_StringConcatenate_f_i[0], EV_SLAC_B.Cast3_g,
                   (int32_T)EV_SLAC_B.AND_cs);
          strncpy(&EV_SLAC_B.cv1[0], &EV_SLAC_B.rtb_ASCIItoString_gq_b[0], 120U);
          for (EV_SLAC_B.i_k = 0; EV_SLAC_B.i_k < 120; EV_SLAC_B.i_k++) {
            EV_SLAC_B.Cast2_k2[EV_SLAC_B.i_k] = (int8_T)(uint8_T)
              EV_SLAC_B.cv1[EV_SLAC_B.i_k];
          }

          slac_debug_ported(EV_SLAC_P.CCaller1_status_g, &EV_SLAC_B.Cast2_k2[0]);
          EV_SLAC_DW.ret = (int32_T)EV_SLAC_B.AND_cs;
        }
      } else {
        switch (EV_SLAC_DW.ret) {
         case 0:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_PAYMENT_SELECTION = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_b = 3U;
          break;

         case 1:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_PAYMENT_SELECTION = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_b = 2U;
          break;
        }
      }

      switch (EV_SLAC_DW.exitPortIndex_b) {
       case 2:
        EV_SLAC_DW.exitPortIndex_b = 0U;
        EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
        break;

       case 3:
        EV_SLAC_DW.exitPortIndex_b = 0U;
        EV_SLAC_DW.temporalCounter_i2 = 0.0;
        EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_AUTHORIZATION;
        EV_SLAC_DW.temporalCounter_i1 = 0.0;
        EV_SLAC_DW.is_AUTHORIZATION = EV_SLAC_IN_BLOCK;
        EV_SLAC_DW.is_BLOCK_p = EV_SLAC_IN_REQUEST;
        EV_SLAC_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq
          (&EV_SLAC_SharedDSM.EVSE_PAIRING_SET, &EV_SLAC_SharedDSM.ExiDoc_Buff,
           &EV_SLAC_B.V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq,
           &EV_SLAC_P.V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq);
        EV_SLAC_DW.ret =
          EV_SLAC_B.V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq.CCaller1_o1;
        EV_SLAC_DW.StreamMesgOut_msgReservedData =
          EV_SLAC_B.V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq.CCaller1_o2;
        break;

       case 4:
        EV_SLAC_DW.exitPortIndex_b = 0U;
        EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
        break;
      }
      break;

     case EV_SLAC_IN_POWER_DELIVERY:
      if ((int32_T)EV_SLAC_DW.is_POWER_DELIVERY == (int32_T)EV_SLAC_IN_BLOCK) {
        if (((((EV_SLAC_M->Timing.clockTick1) * 0.01) - EV_SLAC_DW.previousTime)
             + EV_SLAC_DW.temporalCounter_i1) * 1000.0 >= (real_T)
            EV_SLAC_DW.PowerDeliveryReq_Timeout) {
          if ((int32_T)EV_SLAC_DW.is_BLOCK_o == (int32_T)EV_SLAC_IN_REQUEST) {
            EV_SLAC_DW.ret = -1;
            EV_SLAC_DW.is_BLOCK_o = EV_SLAC_IN_NO_ACTIVE_CHILD;
          } else {
            EV_SLAC_DW.is_BLOCK_o = EV_SLAC_IN_NO_ACTIVE_CHILD;
          }

          EV_SLAC_DW.is_POWER_DELIVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_kw = 4U;
        } else if ((int32_T)EV_SLAC_DW.is_BLOCK_o == (int32_T)EV_SLAC_IN_REQUEST)
        {
          switch (EV_SLAC_DW.ret) {
           case 0:
            EV_SLAC_DW.ret = -1;
            EV_SLAC_DW.is_BLOCK_o = EV_SLAC_IN_waitingRes_j;
            EV_SLAC_sf_msg_send_StreamMesgOut();
            break;

           case 1:
            EV_SLAC_DW.ret = -1;
            EV_SLAC_DW.is_BLOCK_o = EV_SLAC_IN_NO_ACTIVE_CHILD;
            EV_SLAC_DW.is_POWER_DELIVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
            EV_SLAC_DW.exitPortIndex_kw = 2U;
            break;
          }
        } else if (EV_SLAC_sf_msg_pop_StreamMesgIn()) {
          EV_SLAC_DW.is_BLOCK_o = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.is_POWER_DELIVERY = EV_SLAC_IN_RESPONSE;
          EV_SLAC_B.StreamIn_k4 = EV_SLAC_DW.StreamMesgIn_msgReservedData;
          EV_SLAC_B.CCaller2_o2_n = EV_SLAC_SharedDSM.ExiDoc_Buff;
          EV_SLAC_B.Cast5_g = decode_iso1ExiDocument(&EV_SLAC_B.StreamIn_k4,
            &EV_SLAC_B.CCaller2_o2_n);
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[0],
             &EV_SLAC_B.sf_MATLABFunction_jo);
          EV_SLAC_B.rtb_ASCIItoString_gq_b[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_jo.y[0];
          EV_SLAC_B.rtb_ASCIItoString_gq_b[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_jo.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_gq_b[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[1],
             &EV_SLAC_B.sf_MATLABFunction_kb);
          EV_SLAC_B.rtb_ASCIItoString_ef_j[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_kb.y[0];
          EV_SLAC_B.rtb_ASCIItoString_ef_j[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_kb.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_ef_j[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[2],
             &EV_SLAC_B.sf_MATLABFunction_bi);
          EV_SLAC_B.rtb_ASCIItoString_je_f[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_bi.y[0];
          EV_SLAC_B.rtb_ASCIItoString_je_f[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_bi.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_je_f[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[3],
             &EV_SLAC_B.sf_MATLABFunction_bq);
          EV_SLAC_B.rtb_ASCIItoString_f_a[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_bq.y[0];
          EV_SLAC_B.rtb_ASCIItoString_f_a[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_bq.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_f_a[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[4],
             &EV_SLAC_B.sf_MATLABFunction_af);
          EV_SLAC_B.rtb_ASCIItoString_h_j[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_af.y[0];
          EV_SLAC_B.rtb_ASCIItoString_h_j[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_af.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_h_j[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[5],
             &EV_SLAC_B.sf_MATLABFunction_bj);
          EV_SLAC_B.rtb_ASCIItoString_mq_j[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_bj.y[0];
          EV_SLAC_B.rtb_ASCIItoString_mq_j[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_bj.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_mq_j[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[6],
             &EV_SLAC_B.sf_MATLABFunction_bk);
          EV_SLAC_B.rtb_ASCIItoString_np_o[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_bk.y[0];
          EV_SLAC_B.rtb_ASCIItoString_np_o[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_bk.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_np_o[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[7],
             &EV_SLAC_B.sf_MATLABFunction_n5);
          EV_SLAC_B.rtb_ASCIItoString_nz_n[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_n5.y[0];
          EV_SLAC_B.rtb_ASCIItoString_nz_n[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_n5.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_nz_n[2], 0, 254U * sizeof(char_T));
          EV_SLAC_B.rtb_StringConcatenate_f_i[0] = '\x00';
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[0U],
                  &EV_SLAC_B.rtb_ASCIItoString_gq_b[0], 255U);
          EV_SLAC_B.u2 = strlen(&EV_SLAC_B.rtb_StringConcatenate_f_i[0U]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_ef_j[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_je_f[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_f_a[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_h_j[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_mq_j[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_np_o[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_nz_n[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.Cast3_g = (int32_T)
            EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.Notification_isUsed;
          EV_SLAC_B.SumofElements_p = (uint8_T)0U;
          for (EV_SLAC_B.i_k = 0; EV_SLAC_B.i_k < 8; EV_SLAC_B.i_k++) {
            EV_SLAC_B.NAND_m = (boolean_T)((int32_T)
              EV_SLAC_SharedDSM.EVSE_PAIRING_SET.SessionID.bytes[EV_SLAC_B.i_k]
              != (int32_T)
              EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[EV_SLAC_B.i_k]);
            EV_SLAC_B.SumofElements_p = (uint8_T)((uint32_T)
              EV_SLAC_B.SumofElements_p + (uint32_T)(int32_T)EV_SLAC_B.NAND_m);
          }

          EV_SLAC_B.NAND_m = (boolean_T)((int32_T)
            EV_SLAC_B.CCaller2_o2_n.V2G_Message_isUsed == (int32_T)
            EV_SLAC_P.CompareToConstant1_const_m);
          EV_SLAC_B.AND_cs = (boolean_T)((int32_T)
            EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.PowerDeliveryRes_isUsed ==
            (int32_T)EV_SLAC_P.CompareToConstant_const_a4);
          EV_SLAC_B.RelationalOperator5_l = (boolean_T)((EV_SLAC_B.Cast5_g !=
            EV_SLAC_P.Constant_Value_df) || (!(int32_T)EV_SLAC_B.NAND_m) ||
            (!(int32_T)EV_SLAC_B.AND_cs));
          EV_SLAC_B.AND_cs = (boolean_T)(EV_SLAC_P.EnumeratedConstant1_Value_f ==
            EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.PowerDeliveryRes.ResponseCode);
          EV_SLAC_B.NAND_m = (boolean_T)(EV_SLAC_P.EnumeratedConstant4_Value_h ==
            EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.PowerDeliveryRes.DC_EVSEStatus.EVSENotification);
          if ((int32_T)
              EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.PowerDeliveryRes.DC_EVSEStatus.EVSEIsolationStatus_isUsed
              != 0) {
            EV_SLAC_B.RelationalOperator6 = (boolean_T)
              (EV_SLAC_P.EnumeratedConstant5_Value_b ==
               EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.PowerDeliveryRes.DC_EVSEStatus.EVSEIsolationStatus);
            EV_SLAC_B.Cast5_g = (int32_T)EV_SLAC_B.RelationalOperator6;
          } else {
            EV_SLAC_B.Cast5_g = (int32_T)EV_SLAC_P.Constant1_Value_ba;
          }

          EV_SLAC_B.RelationalOperator6 = (boolean_T)
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.PowerDeliveryRes.DC_EVSEStatus.EVSEStatusCode
             == EV_SLAC_P.EnumeratedConstant6_Value_p);
          EV_SLAC_B.RelationalOperator6 = (boolean_T)(((int32_T)
            EV_SLAC_B.SumofElements_p != (int32_T)EV_SLAC_P.Constant_Value_hx) ||
            ((int32_T)EV_SLAC_B.RelationalOperator5_l !=
             EV_SLAC_P.Constant_Value_kb) || ((!(int32_T)EV_SLAC_B.AND_cs) || ((
            !(int32_T)EV_SLAC_B.NAND_m) || (EV_SLAC_B.Cast5_g == 0) ||
            (!(int32_T)EV_SLAC_B.RelationalOperator6))));
          snprintf(&EV_SLAC_B.rtb_ASCIItoString_gq_b[0], 256U,
                   "PowerDelivery: SessionID= %s , Notify = %d, retCode : %d",
                   &EV_SLAC_B.rtb_StringConcatenate_f_i[0], EV_SLAC_B.Cast3_g,
                   (int32_T)EV_SLAC_B.RelationalOperator6);
          strncpy(&EV_SLAC_B.cv1[0], &EV_SLAC_B.rtb_ASCIItoString_gq_b[0], 120U);
          for (EV_SLAC_B.i_k = 0; EV_SLAC_B.i_k < 120; EV_SLAC_B.i_k++) {
            EV_SLAC_B.Cast2_k2[EV_SLAC_B.i_k] = (int8_T)(uint8_T)
              EV_SLAC_B.cv1[EV_SLAC_B.i_k];
          }

          slac_debug_ported(EV_SLAC_P.CCaller1_status_p, &EV_SLAC_B.Cast2_k2[0]);
          EV_SLAC_DW.ret = (int32_T)EV_SLAC_B.RelationalOperator6;
        }
      } else {
        switch (EV_SLAC_DW.ret) {
         case 0:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_POWER_DELIVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_kw = 3U;
          break;

         case 1:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_POWER_DELIVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_kw = 2U;
          break;
        }
      }

      switch (EV_SLAC_DW.exitPortIndex_kw) {
       case 2:
        EV_SLAC_DW.exitPortIndex_kw = 0U;
        EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
        break;

       case 3:
        EV_SLAC_DW.exitPortIndex_kw = 0U;
        EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
        break;

       case 4:
        EV_SLAC_DW.exitPortIndex_kw = 0U;
        EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
        break;
      }
      break;

     case EV_SLAC_IN_PRE_CHARGE:
      EV_SLAC_PRE_CHARGE();
      break;

     case EV_SLAC_IN_SERVICE_DETAIL:
      EV_SLAC_DW.ret = -1;
      EV_SLAC_DW.is_SERVICE_DETAIL = EV_SLAC_IN_NO_ACTIVE_CHILD;
      EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_PAYMENT_SELECTION;
      EV_SLAC_DW.temporalCounter_i1 = 0.0;
      EV_SLAC_DW.is_PAYMENT_SELECTION = EV_SLAC_IN_BLOCK;
      EV_SLAC_DW.is_BLOCK_g = EV_SLAC_IN_REQUEST;
      EV_SLAC_B.Cast5_g = (int32_T)
        EV_SLAC_SharedDSM.EVCC_CONFIG_SET.vc_SelectedPaymentOption;
      EV_SLAC_B.BusAssignment5_l = EV_SLAC_P.Constant13_Value_l;
      EV_SLAC_B.BusAssignment5_l.size = (uint32_T)EV_SLAC_P.Constant11_Value_l;
      EV_SLAC_B.BusAssignment5_l.pos = (uint32_T)EV_SLAC_P.Constant10_Value_en;
      EV_SLAC_B.CCaller2_o2_n = EV_SLAC_SharedDSM.ExiDoc_Buff;
      repaireExiDocBuff(&EV_SLAC_B.CCaller2_o2_n);
      EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID =
        EV_SLAC_SharedDSM.EVSE_PAIRING_SET.SessionID;
      EV_SLAC_B.BusAssignment_h = EV_SLAC_P.Constant1_Value;
      EV_SLAC_B.BusAssignment_h.ServiceID = (uint16_T)
        EV_SLAC_P.Constant2_Value_c5;
      memcpy
        (&EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.data_Array
         [0],
         &EV_SLAC_P.Constant5_Value_l.SelectedServiceList.SelectedService.data_Array
         [0], sizeof(iso1SelectedServiceType) << 4U);
      EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.data_Array
        [0] = EV_SLAC_B.BusAssignment_h;
      EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.PaymentServiceSelectionReq_isUsed
        = EV_SLAC_P.Constant4_Value_dm;
      EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.PaymentServiceSelectionReq.SelectedPaymentOption
        = EV_SLAC_SharedDSM.EVCC_CONFIG_SET.vc_SelectedPaymentOption;
      EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.arrayLen
        = (uint16_T)EV_SLAC_P.Constant_Value_g2;
      EV_SLAC_B.CCaller2_o2_n.V2G_Message_isUsed = EV_SLAC_P.Constant3_Value_h;
      EV_SLAC_B.CCaller1_o2_o = EV_SLAC_B.BusAssignment5_l;
      EV_SLAC_B.Cast3_g = encode_iso1ExiDocument(&EV_SLAC_B.CCaller1_o2_o,
        &EV_SLAC_B.CCaller2_o2_n);
      snprintf(&EV_SLAC_B.rtb_StringConcatenate_f_i[0], 256U,
               "PaymentSeviceSeletion: PaymentChoice: %d status: %d",
               EV_SLAC_B.Cast5_g, EV_SLAC_B.Cast3_g);
      strncpy(&EV_SLAC_B.cv8[0], &EV_SLAC_B.rtb_StringConcatenate_f_i[0], 100U);
      for (EV_SLAC_B.i_k = 0; EV_SLAC_B.i_k < 100; EV_SLAC_B.i_k++) {
        EV_SLAC_B.Cast1_n[EV_SLAC_B.i_k] = (int8_T)(uint8_T)
          EV_SLAC_B.cv8[EV_SLAC_B.i_k];
      }

      slac_debug_ported(EV_SLAC_P.CCaller_status_hf, &EV_SLAC_B.Cast1_n[0]);
      EV_SLAC_DW.ret = EV_SLAC_B.Cast3_g;
      EV_SLAC_DW.StreamMesgOut_msgReservedData = EV_SLAC_B.CCaller1_o2_o;
      break;

     case EV_SLAC_IN_SERVICE_DISCOVERY:
      if ((int32_T)EV_SLAC_DW.is_SERVICE_DISCOVERY == (int32_T)
          EV_SLAC_IN_REQ_BLOCK) {
        if (((((EV_SLAC_M->Timing.clockTick1) * 0.01) - EV_SLAC_DW.previousTime)
             + EV_SLAC_DW.temporalCounter_i1) * 1000.0 >= (real_T)
            EV_SLAC_DW.ServiceDiscoveryReq_Timeout) {
          if ((int32_T)EV_SLAC_DW.is_REQ_BLOCK == (int32_T)EV_SLAC_IN_REQUEST) {
            EV_SLAC_DW.ret = -1;
            EV_SLAC_DW.is_REQ_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
          } else {
            EV_SLAC_DW.is_REQ_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
          }

          EV_SLAC_DW.is_SERVICE_DISCOVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_fv = 4U;
        } else if ((int32_T)EV_SLAC_DW.is_REQ_BLOCK == (int32_T)
                   EV_SLAC_IN_REQUEST) {
          switch (EV_SLAC_DW.ret) {
           case 0:
            EV_SLAC_DW.ret = -1;
            EV_SLAC_DW.is_REQ_BLOCK = EV_SLAC_IN_waitingRes_j;
            EV_SLAC_sf_msg_send_StreamMesgOut();
            break;

           case 1:
            EV_SLAC_DW.ret = -1;
            EV_SLAC_DW.is_REQ_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
            EV_SLAC_DW.is_SERVICE_DISCOVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
            EV_SLAC_DW.exitPortIndex_fv = 2U;
            break;
          }
        } else if (EV_SLAC_sf_msg_pop_StreamMesgIn()) {
          EV_SLAC_DW.is_REQ_BLOCK = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.is_SERVICE_DISCOVERY = EV_SLAC_IN_RESPONSE;
          EV_SLAC_B.StreamIn_k = EV_SLAC_DW.StreamMesgIn_msgReservedData;
          EV_SLAC_B.CCaller2_o2_n = EV_SLAC_SharedDSM.ExiDoc_Buff;
          EV_SLAC_B.Cast5_g = decode_iso1ExiDocument(&EV_SLAC_B.StreamIn_k,
            &EV_SLAC_B.CCaller2_o2_n);
          EV_SLAC_SharedDSM.EVCC_CONFIG_SET.vc_paymentOptionList =
            EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.ServiceDiscoveryRes.PaymentOptionList;
          EV_SLAC_SharedDSM.EVCC_CONFIG_SET.vc_chargeService =
            EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.ServiceDiscoveryRes.ChargeService;
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[0],
             &EV_SLAC_B.sf_MATLABFunction_jd);
          EV_SLAC_B.rtb_ASCIItoString_gq_b[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_jd.y[0];
          EV_SLAC_B.rtb_ASCIItoString_gq_b[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_jd.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_gq_b[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[1],
             &EV_SLAC_B.sf_MATLABFunction_lm);
          EV_SLAC_B.rtb_ASCIItoString_ef_j[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_lm.y[0];
          EV_SLAC_B.rtb_ASCIItoString_ef_j[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_lm.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_ef_j[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[2],
             &EV_SLAC_B.sf_MATLABFunction_m);
          EV_SLAC_B.rtb_ASCIItoString_je_f[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_m.y[0];
          EV_SLAC_B.rtb_ASCIItoString_je_f[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_m.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_je_f[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[3],
             &EV_SLAC_B.sf_MATLABFunction_ln);
          EV_SLAC_B.rtb_ASCIItoString_f_a[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_ln.y[0];
          EV_SLAC_B.rtb_ASCIItoString_f_a[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_ln.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_f_a[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[4],
             &EV_SLAC_B.sf_MATLABFunction_ew);
          EV_SLAC_B.rtb_ASCIItoString_h_j[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_ew.y[0];
          EV_SLAC_B.rtb_ASCIItoString_h_j[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_ew.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_h_j[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[5],
             &EV_SLAC_B.sf_MATLABFunction_i2);
          EV_SLAC_B.rtb_ASCIItoString_mq_j[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_i2.y[0];
          EV_SLAC_B.rtb_ASCIItoString_mq_j[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_i2.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_mq_j[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[6],
             &EV_SLAC_B.sf_MATLABFunction_l1);
          EV_SLAC_B.rtb_ASCIItoString_np_o[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_l1.y[0];
          EV_SLAC_B.rtb_ASCIItoString_np_o[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_l1.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_np_o[2], 0, 254U * sizeof(char_T));
          EV_SLAC_MATLABFunction
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[7],
             &EV_SLAC_B.sf_MATLABFunction_f);
          EV_SLAC_B.rtb_ASCIItoString_nz_n[0] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_f.y[0];
          EV_SLAC_B.rtb_ASCIItoString_nz_n[1] = (char_T)(int8_T)
            EV_SLAC_B.sf_MATLABFunction_f.y[1];
          memset(&EV_SLAC_B.rtb_ASCIItoString_nz_n[2], 0, 254U * sizeof(char_T));
          EV_SLAC_B.rtb_StringConcatenate_f_i[0] = '\x00';
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[0U],
                  &EV_SLAC_B.rtb_ASCIItoString_gq_b[0], 255U);
          EV_SLAC_B.u2 = strlen(&EV_SLAC_B.rtb_StringConcatenate_f_i[0U]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_ef_j[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_je_f[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_f_a[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_h_j[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_mq_j[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_np_o[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.u2 += strlen
            (&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2]);
          strncat(&EV_SLAC_B.rtb_StringConcatenate_f_i[EV_SLAC_B.u2],
                  &EV_SLAC_B.rtb_ASCIItoString_nz_n[0], 255U - EV_SLAC_B.u2);
          EV_SLAC_B.Cast3_g = (int32_T)
            EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.Notification_isUsed;
          EV_SLAC_B.SumofElements_p = (uint8_T)0U;
          for (EV_SLAC_B.i_k = 0; EV_SLAC_B.i_k < 8; EV_SLAC_B.i_k++) {
            EV_SLAC_B.NAND_m = (boolean_T)((int32_T)
              EV_SLAC_SharedDSM.EVSE_PAIRING_SET.SessionID.bytes[EV_SLAC_B.i_k]
              != (int32_T)
              EV_SLAC_B.CCaller2_o2_n.V2G_Message.Header.SessionID.bytes[EV_SLAC_B.i_k]);
            EV_SLAC_B.SumofElements_p = (uint8_T)((uint32_T)
              EV_SLAC_B.SumofElements_p + (uint32_T)(int32_T)EV_SLAC_B.NAND_m);
          }

          EV_SLAC_B.AND_cs = (boolean_T)((int32_T)
            EV_SLAC_B.CCaller2_o2_n.V2G_Message_isUsed == (int32_T)
            EV_SLAC_P.CompareToConstant1_const_c);
          EV_SLAC_B.NAND_m = (boolean_T)((int32_T)
            EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.ServiceDiscoveryRes_isUsed ==
            (int32_T)EV_SLAC_P.CompareToConstant_const_d);
          EV_SLAC_B.Cast5_g = ((EV_SLAC_B.Cast5_g != EV_SLAC_P.Constant_Value_i)
                               || (!(int32_T)EV_SLAC_B.AND_cs) || (!(int32_T)
            EV_SLAC_B.NAND_m));
          EV_SLAC_B.NAND_m = (boolean_T)(EV_SLAC_P.EnumeratedConstant1_Value_n4 ==
            EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.ServiceDiscoveryRes.ResponseCode);
          EV_SLAC_B.AND_cs = (boolean_T)
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.ServiceDiscoveryRes.PaymentOptionList.PaymentOption.data_Array
             [0] == EV_SLAC_P.EnumeratedConstant_Value_d);
          EV_SLAC_B.RelationalOperator5_l = (boolean_T)
            (EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.ServiceDiscoveryRes.PaymentOptionList.PaymentOption.data_Array
             [1] == EV_SLAC_P.EnumeratedConstant_Value_d);
          EV_SLAC_B.i_k = 0;
          if (EV_SLAC_B.AND_cs) {
            EV_SLAC_B.FindNonzeroElements[0] = (int8_T)0;
            EV_SLAC_B.i_k = 1;
          }

          if (EV_SLAC_B.RelationalOperator5_l) {
            EV_SLAC_B.FindNonzeroElements[EV_SLAC_B.i_k] = (int8_T)1;
            EV_SLAC_B.i_k++;
          }

          EV_SLAC_DW.FindNonzeroElements_DIMS1 = EV_SLAC_B.i_k;
          EV_SLAC_B.AND_cs = (boolean_T)((uint32_T)(int32_T)
            EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.ServiceDiscoveryRes.PaymentOptionList.PaymentOption.arrayLen
            >= (uint32_T)EV_SLAC_B.FindNonzeroElements[0]);
          EV_SLAC_B.NAND_m = (boolean_T)(((int32_T)EV_SLAC_B.SumofElements_p !=
            (int32_T)EV_SLAC_P.Constant_Value_en) || (EV_SLAC_B.Cast5_g !=
            EV_SLAC_P.Constant_Value_j) || ((!(int32_T)EV_SLAC_B.NAND_m) ||
            (!(int32_T)EV_SLAC_B.AND_cs)));
          snprintf(&EV_SLAC_B.rtb_ASCIItoString_gq_b[0], 256U,
                   "Service Discovery: SessionID= %s , Notify = %d, retCode : %d",
                   &EV_SLAC_B.rtb_StringConcatenate_f_i[0], EV_SLAC_B.Cast3_g,
                   (int32_T)EV_SLAC_B.NAND_m);
          strncpy(&EV_SLAC_B.cv1[0], &EV_SLAC_B.rtb_ASCIItoString_gq_b[0], 120U);
          for (EV_SLAC_B.i_k = 0; EV_SLAC_B.i_k < 120; EV_SLAC_B.i_k++) {
            EV_SLAC_B.Cast2_k2[EV_SLAC_B.i_k] = (int8_T)(uint8_T)
              EV_SLAC_B.cv1[EV_SLAC_B.i_k];
          }

          slac_debug_ported(EV_SLAC_P.CCaller1_status_l, &EV_SLAC_B.Cast2_k2[0]);
          if ((int32_T)
              EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.ServiceDiscoveryRes.ServiceList_isUsed
              > 0) {
            EV_SLAC_SharedDSM.EVCC_CONFIG_SET.vc_serviceList =
              EV_SLAC_B.CCaller2_o2_n.V2G_Message.Body.ServiceDiscoveryRes.ServiceList;
          }

          if (EV_SLAC_B.AND_cs) {
            EV_SLAC_SharedDSM.EVCC_CONFIG_SET.vc_SelectedPaymentOption =
              EV_SLAC_P.EnumeratedConstant_Value_d;
          }

          EV_SLAC_DW.ret = (int32_T)EV_SLAC_B.NAND_m;
        }
      } else {
        switch (EV_SLAC_DW.ret) {
         case 0:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_SERVICE_DISCOVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_fv = 3U;
          break;

         case 1:
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_SERVICE_DISCOVERY = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_fv = 2U;
          break;
        }
      }

      switch (EV_SLAC_DW.exitPortIndex_fv) {
       case 2:
        EV_SLAC_DW.exitPortIndex_fv = 0U;
        EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
        break;

       case 3:
        EV_SLAC_DW.exitPortIndex_fv = 0U;
        EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_SERVICE_DETAIL;
        EV_SLAC_DW.is_SERVICE_DETAIL = EV_SLAC_IN_NOP;
        EV_SLAC_DW.ret = 0;
        break;

       case 4:
        EV_SLAC_DW.exitPortIndex_fv = 0U;
        EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_errorHandle_o;
        break;
      }
      break;

     default:
      EV_SLAC_DW.is_V2G_SEQ = EV_SLAC_IN_NO_ACTIVE_CHILD;
      EV_SLAC_DW.exitPortIndex_gq = 2U;
      break;
    }

    if (EV_SLAC_DW.exitPortIndex_gq == 2U) {
      EV_SLAC_DW.exitPortIndex_gq = 0U;
      EV_SLAC_DW.is_LinkSetup = EV_SLAC_IN_errorHandle;
      EV_SLAC_V2GLinkSetuperrorHandleTimeOutHandle
        (&EV_SLAC_B.V2GLinkSetuperrorHandleTimeOutHandle,
         &EV_SLAC_P.V2GLinkSetuperrorHandleTimeOutHandle);
    }
  }
}

static boolean_T EV_SLAC_sf_msg_pop_ActiveTcpLoop(boolean_T
  *ActiveTcpLoop_isValid)
{
  boolean_T isPresent;
  if (*ActiveTcpLoop_isValid) {
    isPresent = true;
  } else {
    if (EV_SLAC_pop(&EV_SLAC_DW.Queue[0], &EV_SLAC_DW.Msg[0])) {
      EV_SLAC_DW.ActiveTcpLoop_msgHandle = &EV_SLAC_DW.Msg[0];
    } else {
      EV_SLAC_DW.ActiveTcpLoop_msgHandle = NULL;
    }

    if (EV_SLAC_DW.ActiveTcpLoop_msgHandle != NULL) {
      EV_SLAC_DW.ActiveTcpLoop_msgDataPtr = &((Msg_boolean_T *)
        EV_SLAC_DW.ActiveTcpLoop_msgHandle)->fData;
      isPresent = true;
      EV_SLAC_DW.ActiveTcpLoop_msgReservedData = *(boolean_T *)
        EV_SLAC_DW.ActiveTcpLoop_msgDataPtr;
      *ActiveTcpLoop_isValid = true;
    } else {
      isPresent = false;
      *ActiveTcpLoop_isValid = false;
    }
  }

  return isPresent;
}

static boolean_T EV_SLAC_sf_msg_pop_StreamMesgOut(boolean_T
  *StreamMesgOut_isValid)
{
  boolean_T isPresent;
  if (*StreamMesgOut_isValid) {
    isPresent = true;
  } else {
    if (EV_SLAC_pop_k(&EV_SLAC_DW.Queue_0[0], &EV_SLAC_DW.Msg_0[0])) {
      EV_SLAC_DW.StreamMesgOut_msgHandle = &EV_SLAC_DW.Msg_0[0];
    } else {
      EV_SLAC_DW.StreamMesgOut_msgHandle = NULL;
    }

    if (EV_SLAC_DW.StreamMesgOut_msgHandle != NULL) {
      EV_SLAC_DW.StreamMesgOut_msgDataPtr = ((Msg_bitstream_t *)
        EV_SLAC_DW.StreamMesgOut_msgHandle)->fData;
      isPresent = true;
      EV_SLAC_DW.StreamMesgOut_msgReservedData = *(bitstream_t *)
        EV_SLAC_DW.StreamMesgOut_msgDataPtr;
      *StreamMesgOut_isValid = true;
    } else {
      isPresent = false;
      *StreamMesgOut_isValid = false;
    }
  }

  return isPresent;
}

static void EV_SLAC_sf_msg_send_StreamMesgIn(void)
{
  EV_SLAC_emplace_n(&EV_SLAC_DW.Queue_0[1],
                    &EV_SLAC_DW.StreamMesgIn_msgReservedData);
}

static void EV_SLAC_sf_msg_send_TCP_IP_LostConnect(void)
{
  EV_SLAC_emplace(&EV_SLAC_DW.Queue[1],
                  &EV_SLAC_DW.TCP_IP_LostConnect_msgReservedData);
}

static void EV_SLAC_V2G(boolean_T *StreamMesgOut_isValid, boolean_T
  *ActiveTcpLoop_isValid)
{
  switch (EV_SLAC_DW.is_LinkSetup) {
   case EV_SLAC_IN_COMMUNICATION_SETUP:
    EV_SLAC_COMMUNICATION_SETUP();
    break;

   case EV_SLAC_IN_SLAC:
    switch (EV_SLAC_DW.is_SLAC) {
     case EV_SLAC_IN_Initialization:
      if (EV_SLAC_DW.ret == 0) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.exitPortIndex_h = 2U;
      } else {
        EV_SLAC_V2GLinkSetupSLACInitializationopenChannel();
        EV_SLAC_DW.ret = EV_SLAC_B.Cast12;
      }

      if (EV_SLAC_DW.exitPortIndex_h == 2U) {
        EV_SLAC_DW.exitPortIndex_h = 0U;
        EV_SLAC_DW.is_SLAC = EV_SLAC_IN_Slac_param;
        EV_SLAC_enter_internal_Slac_param();
      }
      break;

     case EV_SLAC_IN_MATCHED:
      if ((int32_T)EV_SLAC_DW.is_MATCHED == (int32_T)EV_SLAC_IN_JOIN_NETWORK) {
        if (((((EV_SLAC_M->Timing.clockTick1) * 0.01) - EV_SLAC_DW.previousTime)
             + EV_SLAC_DW.temporalCounter_i1) * 1000.0 >= (real_T)
            EV_SLAC_DW.TT_match_join) {
          switch (EV_SLAC_DW.is_JOIN_NETWORK) {
           case EV_SLAC_IN_JOIN_NETWORK_CNF:
            EV_SLAC_DW.ret = -1;
            EV_SLAC_DW.is_JOIN_NETWORK = EV_SLAC_IN_NO_ACTIVE_CHILD;
            break;

           case EV_SLAC_IN_JOIN_NETWORK_REQ:
            EV_SLAC_DW.ret = -1;
            EV_SLAC_DW.is_JOIN_NETWORK = EV_SLAC_IN_NO_ACTIVE_CHILD;
            break;
          }

          EV_SLAC_DW.is_MATCHED = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_kz = 2U;
        } else if ((int32_T)EV_SLAC_DW.is_JOIN_NETWORK == (int32_T)
                   EV_SLAC_IN_JOIN_NETWORK_CNF) {
          if (EV_SLAC_DW.ret == 0) {
            EV_SLAC_DW.ret = -1;
            EV_SLAC_DW.is_JOIN_NETWORK = EV_SLAC_IN_NO_ACTIVE_CHILD;
            EV_SLAC_DW.is_MATCHED = EV_SLAC_IN_NO_ACTIVE_CHILD;
            EV_SLAC_DW.exitPortIndex_kz = 3U;
          } else {
            EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_set_key_CNF
              (&EV_SLAC_B.CCaller_d);
            EV_SLAC_DW.ret = EV_SLAC_B.CCaller_d;
          }
        } else if (EV_SLAC_DW.ret == 0) {
          EV_SLAC_DW.ret = -1;
          EV_SLAC_DW.is_JOIN_NETWORK = EV_SLAC_IN_JOIN_NETWORK_CNF;
          EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_set_key_CNF(&EV_SLAC_B.CCaller_d);
          EV_SLAC_DW.ret = EV_SLAC_B.CCaller_d;
        } else {
          EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_set_key_REQ(&EV_SLAC_B.CCaller_d);
          EV_SLAC_DW.ret = EV_SLAC_B.CCaller_d;
        }
      } else if (EV_SLAC_DW.ret == 0) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.temporalCounter_i1 = 0.0;
        EV_SLAC_DW.is_MATCHED = EV_SLAC_IN_JOIN_NETWORK;
        EV_SLAC_DW.is_JOIN_NETWORK = EV_SLAC_IN_JOIN_NETWORK_REQ;
        EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_set_key_REQ(&EV_SLAC_B.CCaller_d);
        EV_SLAC_DW.ret = EV_SLAC_B.CCaller_d;
      } else if (((((EV_SLAC_M->Timing.clockTick1) * 0.01) -
                   EV_SLAC_DW.previousTime) + EV_SLAC_DW.temporalCounter_i1) *
                 1000.0 >= (real_T)EV_SLAC_DW.TT_match_response) {
        EV_SLAC_DW.ret = -1;
        EV_SLAC_DW.is_MATCHED = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_kz = 2U;
      }

      switch (EV_SLAC_DW.exitPortIndex_kz) {
       case 2:
        EV_SLAC_DW.exitPortIndex_kz = 0U;
        EV_SLAC_DW.is_SLAC = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_n = 3U;
        break;

       case 3:
        EV_SLAC_DW.exitPortIndex_kz = 0U;
        EV_SLAC_DW.is_SLAC = EV_SLAC_IN_NO_ACTIVE_CHILD;
        EV_SLAC_DW.exitPortIndex_n = 2U;
        break;
      }
      break;

     case EV_SLAC_IN_MATCHING:
      EV_SLAC_MATCHING();
      break;

     default:
      EV_SLAC_Slac_param();
      break;
    }

    switch (EV_SLAC_DW.exitPortIndex_n) {
     case 2:
      EV_SLAC_DW.exitPortIndex_n = 0U;
      EV_SLAC_DW.is_LinkSetup = EV_SLAC_IN_COMMUNICATION_SETUP;
      EV_SLAC_DW.temporalCounter_i2 = 0.0;
      EV_SLAC_DW.is_BLOCK = EV_SLAC_IN_SDP;
      EV_SLAC_DW.is_SDP = EV_SLAC_IN_V2G2_016_IP_ADD_ASSIGMENT;
      memcpy(&EV_SLAC_SharedDSM.UDP_PORT[0], &EV_SLAC_P.Constant5_Value_b[0],
             sizeof(uint8_T) << 8U);
      EV_SLAC_DW.is_V2G2_016_IP_ADD_ASSIGMENT = EV_SLAC_IN_OPEN_CHANNEL;
      EV_SLAC_B.r = EV_SLAC_rand();
      strncpy(&EV_SLAC_B.cv12[0], &EV_SLAC_P.StringConstant_String_ec[0], 16U);
      for (EV_SLAC_B.CCaller_d = 0; EV_SLAC_B.CCaller_d < 16;
           EV_SLAC_B.CCaller_d++) {
        EV_SLAC_B.Cast6_j2[EV_SLAC_B.CCaller_d] = (int8_T)(uint8_T)
          EV_SLAC_B.cv12[EV_SLAC_B.CCaller_d];
      }

      strncpy(&EV_SLAC_B.cv12[0], &EV_SLAC_P.StringConstant2_String[0], 16U);
      for (EV_SLAC_B.CCaller_d = 0; EV_SLAC_B.CCaller_d < 16;
           EV_SLAC_B.CCaller_d++) {
        EV_SLAC_B.Cast7_f[EV_SLAC_B.CCaller_d] = (int8_T)(uint8_T)
          EV_SLAC_B.cv12[EV_SLAC_B.CCaller_d];
      }

      memcpy(&EV_SLAC_B.CCaller_o2_f[0], &EV_SLAC_SharedDSM.UDP_PORT[0], sizeof
             (uint8_T) << 8U);
      EV_SLAC_B.r = floor(EV_SLAC_B.r * 16383.0);
      if (EV_SLAC_B.r < 65536.0) {
        if (EV_SLAC_B.r >= 0.0) {
          EV_SLAC_B.u7 = (uint16_T)EV_SLAC_B.r;
        } else {
          EV_SLAC_B.u7 = (uint16_T)0U;
        }
      } else {
        EV_SLAC_B.u7 = MAX_uint16_T;
      }

      EV_SLAC_B.StreamMesg2Send_d_pos = (uint32_T)EV_SLAC_B.u7 + (uint32_T)
        (int32_T)EV_SLAC_P.clientPort_Value;
      if (EV_SLAC_B.StreamMesg2Send_d_pos > 65535U) {
        EV_SLAC_B.StreamMesg2Send_d_pos = 65535U;
      }

      EV_SLAC_DW.ret = UDP_libCreate(&EV_SLAC_B.CCaller_o2_f[0],
        EV_SLAC_P.EnumeratedConstant_Value, (int32_T)
        EV_SLAC_B.StreamMesg2Send_d_pos, &EV_SLAC_B.Cast6_j2[0], (int32_T)
        EV_SLAC_P.Constant_Value_js, &EV_SLAC_B.Cast7_f[0], (int32_T)
        EV_SLAC_P.Constant2_Value_j, (int32_T)EV_SLAC_P.Constant3_Value_p,
        EV_SLAC_P.Constant4_Value);
      memcpy(&EV_SLAC_SharedDSM.UDP_PORT[0], &EV_SLAC_B.CCaller_o2_f[0], sizeof
             (uint8_T) << 8U);
      break;

     case 3:
      EV_SLAC_DW.exitPortIndex_n = 0U;
      EV_SLAC_DW.is_LinkSetup = EV_SLAC_IN_errorHandle;
      EV_SLAC_V2GLinkSetuperrorHandleTimeOutHandle
        (&EV_SLAC_B.V2GLinkSetuperrorHandleTimeOutHandle,
         &EV_SLAC_P.V2GLinkSetuperrorHandleTimeOutHandle);
      break;
    }
    break;

   case EV_SLAC_IN_V2G_SEQ:
    EV_SLAC_V2G_SEQ();
    break;

   default:
    break;
  }

  if ((int32_T)EV_SLAC_DW.is_TCP_IP_LOOP == (int32_T)EV_SLAC_IN_LOOP_ACTIVE) {
    if (EV_SLAC_sf_msg_pop_ActiveTcpLoop(ActiveTcpLoop_isValid)) {
      EV_SLAC_B.Compare_b5 = (boolean_T)!(int32_T)
        EV_SLAC_DW.ActiveTcpLoop_msgReservedData;
    } else {
      EV_SLAC_B.Compare_b5 = false;
    }

    if (EV_SLAC_B.Compare_b5) {
      switch (EV_SLAC_DW.is_LOOP_ACTIVE) {
       case EV_SLAC_IN_STANDBY:
        EV_SLAC_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy
          (&EV_SLAC_B.V2GTCP_IP_LOOPLOOP_ACTIVEFunctionOutStandy,
           &EV_SLAC_P.V2GTCP_IP_LOOPLOOP_ACTIVEFunctionOutStandy);
        EV_SLAC_DW.is_LOOP_ACTIVE = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;

       case EV_SLAC_IN_TRY_RECEIVE:
        EV_SLAC_DW.ret2 = -1;
        EV_SLAC_DW.is_LOOP_ACTIVE = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;

       case EV_SLAC_IN_TRY_RECEIVE1:
        EV_SLAC_DW.ret2 = -1;
        EV_SLAC_DW.is_LOOP_ACTIVE = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;

       case EV_SLAC_IN_TRY_SEND:
        EV_SLAC_DW.ret2 = -1;
        EV_SLAC_DW.is_LOOP_ACTIVE = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;

       case EV_SLAC_IN_TRY_SEND1:
        EV_SLAC_DW.ret2 = -1;
        EV_SLAC_DW.is_LOOP_ACTIVE = EV_SLAC_IN_NO_ACTIVE_CHILD;
        break;
      }

      EV_SLAC_DW.is_TCP_IP_LOOP = EV_SLAC_IN_LOOP_INACTIVE;
    } else {
      switch (EV_SLAC_DW.is_LOOP_ACTIVE) {
       case EV_SLAC_IN_STANDBY:
        if (EV_SLAC_sf_msg_pop_StreamMesgOut(StreamMesgOut_isValid)) {
          EV_SLAC_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy
            (&EV_SLAC_B.V2GTCP_IP_LOOPLOOP_ACTIVEFunctionOutStandy,
             &EV_SLAC_P.V2GTCP_IP_LOOPLOOP_ACTIVEFunctionOutStandy);
          EV_SLAC_DW.is_LOOP_ACTIVE = EV_SLAC_IN_TRY_SEND;
          memcpy(&EV_SLAC_B.PDU_Read_o1[0],
                 &EV_SLAC_DW.StreamMesgOut_msgReservedData.data[0], sizeof
                 (uint8_T) << 12U);
          EV_SLAC_B.StreamMesg2Send_d_pos =
            EV_SLAC_DW.StreamMesgOut_msgReservedData.pos;
          EV_SLAC_ProtocolEncoder(EV_SLAC_B.StreamMesg2Send_d_pos,
            &EV_SLAC_B.ProtocolEncoder, &EV_SLAC_DW.ProtocolEncoder);
          for (EV_SLAC_B.CCaller_d = 0; EV_SLAC_B.CCaller_d < 8;
               EV_SLAC_B.CCaller_d++) {
            EV_SLAC_B.VectorConcatenate_n[EV_SLAC_B.CCaller_d] =
              EV_SLAC_B.ProtocolEncoder.ProtocolEncoder[EV_SLAC_B.CCaller_d];
          }

          memcpy(&EV_SLAC_B.VectorConcatenate_n[8], &EV_SLAC_B.PDU_Read_o1[0],
                 sizeof(uint8_T) << 12U);
          EV_SLAC_B.HeaderRead_o3 = EV_SLAC_SharedDSM.errorNo;
          TCPStreamStepSend6(&EV_SLAC_B.VectorConcatenate_n[0],
                             EV_SLAC_B.StreamMesg2Send_d_pos +
                             EV_SLAC_P.HeaderSize_Value,
                             EV_SLAC_SharedDSM.connStream,
                             EV_SLAC_P.CCaller_isSer, &EV_SLAC_B.HeaderRead_o3);
          EV_SLAC_B.Compare_b5 = (boolean_T)((int32_T)EV_SLAC_B.HeaderRead_o3 ==
            (int32_T)EV_SLAC_P.CompareToConstant_const_j);
          if (EV_SLAC_B.Compare_b5) {
            EV_SLAC_DW.ret2 = EV_SLAC_P.Constant1_Value_i;
          } else {
            EV_SLAC_DW.ret2 = EV_SLAC_P.Constant_Value_dd;
          }
        } else if (EV_SLAC_sf_msg_pop_StreamMesgOut(StreamMesgOut_isValid)) {
          EV_SLAC_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy
            (&EV_SLAC_B.V2GTCP_IP_LOOPLOOP_ACTIVEFunctionOutStandy,
             &EV_SLAC_P.V2GTCP_IP_LOOPLOOP_ACTIVEFunctionOutStandy);
          EV_SLAC_DW.is_LOOP_ACTIVE = EV_SLAC_IN_TRY_SEND1;
          memcpy(&EV_SLAC_B.PDU_Read_o1[0],
                 &EV_SLAC_DW.StreamMesgOut_msgReservedData.data[0], sizeof
                 (uint8_T) << 12U);
          EV_SLAC_B.StreamMesg2Send_d_pos =
            EV_SLAC_DW.StreamMesgOut_msgReservedData.pos;
          EV_SLAC_ProtocolEncoder(EV_SLAC_B.StreamMesg2Send_d_pos,
            &EV_SLAC_B.ProtocolEncoder_k, &EV_SLAC_DW.ProtocolEncoder_k);
          for (EV_SLAC_B.CCaller_d = 0; EV_SLAC_B.CCaller_d < 8;
               EV_SLAC_B.CCaller_d++) {
            EV_SLAC_B.VectorConcatenate_n[EV_SLAC_B.CCaller_d] =
              EV_SLAC_B.ProtocolEncoder_k.ProtocolEncoder[EV_SLAC_B.CCaller_d];
          }

          memcpy(&EV_SLAC_B.VectorConcatenate_n[8], &EV_SLAC_B.PDU_Read_o1[0],
                 sizeof(uint8_T) << 12U);
          EV_SLAC_B.HeaderRead_o3 = EV_SLAC_SharedDSM.errorNo;
          TCPStreamStepSend6(&EV_SLAC_B.VectorConcatenate_n[0],
                             EV_SLAC_B.StreamMesg2Send_d_pos +
                             EV_SLAC_P.Constant_Value_pt,
                             EV_SLAC_SharedDSM.connStream,
                             EV_SLAC_P.CCaller_isSer_o, &EV_SLAC_B.HeaderRead_o3);
          EV_SLAC_B.Compare_b5 = (boolean_T)((int32_T)EV_SLAC_B.HeaderRead_o3 !=
            (int32_T)EV_SLAC_P.CompareToConstant_const_l);
          EV_SLAC_DW.ret2 = (int32_T)EV_SLAC_B.Compare_b5;
        }
        break;

       case EV_SLAC_IN_TRY_RECEIVE:
        if (EV_SLAC_DW.ret2 == 0) {
          EV_SLAC_sf_msg_send_StreamMesgIn();
          EV_SLAC_DW.ret2 = -1;
          EV_SLAC_DW.is_LOOP_ACTIVE = EV_SLAC_IN_STANDBY;
          EV_SLAC_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy
            (&EV_SLAC_B.V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy,
             &EV_SLAC_P.V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy);
        } else if (EV_SLAC_DW.ret2 != 0) {
          EV_SLAC_DW.ret2 = -1;
          EV_SLAC_DW.is_LOOP_ACTIVE = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_h4 = 2U;
        }
        break;

       case EV_SLAC_IN_TRY_RECEIVE1:
        if (EV_SLAC_DW.ret2 == 0) {
          EV_SLAC_sf_msg_send_StreamMesgIn();
          EV_SLAC_DW.ret2 = -1;
          EV_SLAC_DW.is_LOOP_ACTIVE = EV_SLAC_IN_STANDBY;
          EV_SLAC_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy
            (&EV_SLAC_B.V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy,
             &EV_SLAC_P.V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy);
        }
        break;

       case EV_SLAC_IN_TRY_SEND:
        if (EV_SLAC_DW.ret2 == 0) {
          EV_SLAC_DW.ret2 = -1;
          EV_SLAC_DW.is_LOOP_ACTIVE = EV_SLAC_IN_TRY_RECEIVE;
          for (EV_SLAC_B.CCaller_d = 0; EV_SLAC_B.CCaller_d < 8;
               EV_SLAC_B.CCaller_d++) {
            EV_SLAC_B.HeaderRead_o1[EV_SLAC_B.CCaller_d] =
              EV_SLAC_P.Constant1_Value_ml[EV_SLAC_B.CCaller_d];
          }

          EV_SLAC_B.HeaderRead_o2 = EV_SLAC_SharedDSM.TCP_recvStatus;
          EV_SLAC_B.HeaderRead_o3 = EV_SLAC_SharedDSM.errorNo;
          TCPStreamStepRecv6(&EV_SLAC_B.HeaderRead_o1[0],
                             &EV_SLAC_B.HeaderRead_o2,
                             EV_SLAC_P.Constant2_Value_m,
                             EV_SLAC_SharedDSM.connStream,
                             &EV_SLAC_B.HeaderRead_o3,
                             EV_SLAC_P.HeaderReceive_isSer);
          EV_SLAC_B.Compare_b5 = (boolean_T)((int32_T)EV_SLAC_B.HeaderRead_o3 ==
            (int32_T)EV_SLAC_P.CompareToConstant1_const);
          EV_SLAC_B.Compare_j = (boolean_T)((int32_T)EV_SLAC_B.HeaderRead_o2 ==
            (int32_T)EV_SLAC_P.CompareToConstant2_const);
          if (EV_SLAC_B.Compare_j) {
            EV_SLAC_ProtocolDecoder(EV_SLAC_B.HeaderRead_o1,
              &EV_SLAC_B.ProtocolDecoder_k, &EV_SLAC_DW.ProtocolDecoder_k);
            if (EV_SLAC_B.ProtocolDecoder_k.ProtocolDecoder_o2) {
              memcpy(&EV_SLAC_B.PDU_Read_o1[0], &EV_SLAC_P.Constant_Value_jj[0],
                     sizeof(uint8_T) << 12U);
              EV_SLAC_B.PDU_Read_o2 = EV_SLAC_SharedDSM.TCP_recvStatus;
              EV_SLAC_B.HeaderRead_o3 = EV_SLAC_SharedDSM.errorNo;
              TCPStreamStepRecv6(&EV_SLAC_B.PDU_Read_o1[0],
                                 &EV_SLAC_B.PDU_Read_o2,
                                 EV_SLAC_B.ProtocolDecoder_k.ProtocolDecoder_o1,
                                 EV_SLAC_SharedDSM.connStream,
                                 &EV_SLAC_B.HeaderRead_o3,
                                 EV_SLAC_P.PDU_Read_isSer);
              EV_SLAC_B.BusAssignment_f = EV_SLAC_P.Constant3_Value;
              EV_SLAC_B.BusAssignment_f.size =
                EV_SLAC_B.ProtocolDecoder_k.ProtocolDecoder_o1;
              memcpy(&EV_SLAC_B.BusAssignment_f.data[0], &EV_SLAC_B.PDU_Read_o1
                     [0], sizeof(uint8_T) << 12U);
            }

            EV_SLAC_B.Compare_k = (boolean_T)((int32_T)EV_SLAC_B.PDU_Read_o2 ==
              (int32_T)EV_SLAC_P.CompareToConstant_const_m);
            if (((int32_T)EV_SLAC_B.Compare_k) && ((int32_T)
                 EV_SLAC_B.ProtocolDecoder_k.ProtocolDecoder_o2)) {
              EV_SLAC_B.Switch = EV_SLAC_P.Constant1_Value_kg;
            } else {
              EV_SLAC_B.Switch = EV_SLAC_P.Constant_Value_fv;
            }
          }

          if (EV_SLAC_B.Compare_b5) {
            EV_SLAC_DW.ret2 = EV_SLAC_P.Constant3_Value_o;
          } else if (EV_SLAC_B.Compare_j) {
            EV_SLAC_DW.ret2 = EV_SLAC_B.Switch;
          } else {
            EV_SLAC_DW.ret2 = EV_SLAC_P.Constant_Value_gi;
          }

          EV_SLAC_DW.StreamMesgIn_msgReservedData = EV_SLAC_B.BusAssignment_f;
        } else if (EV_SLAC_DW.ret2 != 0) {
          EV_SLAC_DW.ret2 = -1;
          EV_SLAC_DW.is_LOOP_ACTIVE = EV_SLAC_IN_NO_ACTIVE_CHILD;
          EV_SLAC_DW.exitPortIndex_h4 = 2U;
        }
        break;

       default:
        if (EV_SLAC_DW.ret2 == 0) {
          EV_SLAC_DW.ret2 = -1;
          EV_SLAC_DW.is_LOOP_ACTIVE = EV_SLAC_IN_TRY_RECEIVE1;
          for (EV_SLAC_B.CCaller_d = 0; EV_SLAC_B.CCaller_d < 8;
               EV_SLAC_B.CCaller_d++) {
            EV_SLAC_B.HeaderRead_o1[EV_SLAC_B.CCaller_d] =
              EV_SLAC_P.Constant1_Value_bb[EV_SLAC_B.CCaller_d];
          }

          EV_SLAC_B.HeaderRead_o2 = EV_SLAC_SharedDSM.TCP_recvStatus;
          EV_SLAC_B.HeaderRead_o3 = EV_SLAC_SharedDSM.errorNo;
          TCPStreamStepRecv6(&EV_SLAC_B.HeaderRead_o1[0],
                             &EV_SLAC_B.HeaderRead_o2,
                             EV_SLAC_P.Constant2_Value_n,
                             EV_SLAC_SharedDSM.connStream,
                             &EV_SLAC_B.HeaderRead_o3,
                             EV_SLAC_P.HeaderRead_isSer);
          EV_SLAC_ProtocolDecoder(EV_SLAC_B.HeaderRead_o1,
            &EV_SLAC_B.ProtocolDecoder_kq, &EV_SLAC_DW.ProtocolDecoder_kq);
          memcpy(&EV_SLAC_B.PDU_Read_o1[0], &EV_SLAC_P.Constant_Value_hr[0],
                 sizeof(uint8_T) << 12U);
          EV_SLAC_B.HeaderRead_o2 = EV_SLAC_SharedDSM.TCP_recvStatus;
          EV_SLAC_B.HeaderRead_o3 = EV_SLAC_SharedDSM.errorNo;
          TCPStreamStepRecv6(&EV_SLAC_B.PDU_Read_o1[0], &EV_SLAC_B.HeaderRead_o2,
                             EV_SLAC_B.ProtocolDecoder_kq.ProtocolDecoder_o1,
                             EV_SLAC_SharedDSM.connStream,
                             &EV_SLAC_B.HeaderRead_o3,
                             EV_SLAC_P.PDU_Read_isSer_m);
          EV_SLAC_B.BusAssignment = EV_SLAC_P.Constant3_Value_e;
          EV_SLAC_B.BusAssignment.size =
            EV_SLAC_B.ProtocolDecoder_kq.ProtocolDecoder_o1;
          memcpy(&EV_SLAC_B.BusAssignment.data[0], &EV_SLAC_B.PDU_Read_o1[0],
                 sizeof(uint8_T) << 12U);
          EV_SLAC_B.Compare_b5 = (boolean_T)((int32_T)EV_SLAC_B.HeaderRead_o2 !=
            (int32_T)EV_SLAC_P.CompareToConstant1_const_k);
          EV_SLAC_DW.ret2 = (int32_T)EV_SLAC_B.Compare_b5;
          EV_SLAC_DW.StreamMesgIn_msgReservedData = EV_SLAC_B.BusAssignment;
        }
        break;
      }

      if (EV_SLAC_DW.exitPortIndex_h4 == 2U) {
        EV_SLAC_DW.exitPortIndex_h4 = 0U;
        EV_SLAC_sf_msg_send_TCP_IP_LostConnect();
        EV_SLAC_DW.is_TCP_IP_LOOP = EV_SLAC_IN_LOOP_INACTIVE;
      }
    }
  } else {
    if (EV_SLAC_sf_msg_pop_ActiveTcpLoop(ActiveTcpLoop_isValid)) {
      EV_SLAC_B.Compare_b5 = EV_SLAC_DW.ActiveTcpLoop_msgReservedData;
    } else {
      EV_SLAC_B.Compare_b5 = false;
    }

    if (EV_SLAC_B.Compare_b5) {
      EV_SLAC_DW.is_TCP_IP_LOOP = EV_SLAC_IN_LOOP_ACTIVE;
      EV_SLAC_DW.is_LOOP_ACTIVE = EV_SLAC_IN_STANDBY;
      EV_SLAC_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy
        (&EV_SLAC_B.V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy,
         &EV_SLAC_P.V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy);
    }
  }
}

static void EV_SLAC_sf_msg_discard_StreamMesgOut(boolean_T
  *StreamMesgOut_isValid)
{
  if (*StreamMesgOut_isValid) {
    EV_SLAC_destroyMsg_f((Msg_bitstream_t *)EV_SLAC_DW.StreamMesgOut_msgHandle);
    *StreamMesgOut_isValid = false;
  }
}

static void EV_SLAC_sf_msg_discard_StreamMesgIn(void)
{
  if (EV_SLAC_DW.StreamMesgIn_isValid) {
    EV_SLAC_destroyMsg_f((Msg_bitstream_t *)EV_SLAC_DW.StreamMesgIn_msgHandle);
    EV_SLAC_DW.StreamMesgIn_isValid = false;
  }
}

static void EV_SLAC_sf_msg_discard_ActiveTcpLoop(boolean_T
  *ActiveTcpLoop_isValid)
{
  *ActiveTcpLoop_isValid = false;
}

static void EV_SLAC_sf_msg_discard_TCP_IP_LostConnect(void)
{
  EV_SLAC_DW.TCP_IP_LostConnect_isValid = false;
}

void EV_SLAC_initMemPool(MemPool_bitstream_t *memPool, bitstream_t *memArray,
  bitstream_t **freeList, int32_T size)
{
  memPool->fMemArray = memArray;
  memPool->fNumUsed = 0;
  memPool->fFreeList = freeList;
  memPool->fNumFree = 0;
  memPool->fSize = size;
}

void EV_SLAC_freeMemPool(MemPool_bitstream_t *memPool, bitstream_t *dataPtr)
{
  memPool->fFreeList[memPool->fNumFree] = dataPtr;
  memPool->fNumFree++;
}

void EV_SLAC_destroyMsg_f(Msg_bitstream_t *msg)
{
  EV_SLAC_freeMemPool(&EV_SLAC_DW.slMsgMgr_MemPool_bitstream_t, msg->fData);
}

bitstream_t *EV_SLAC_allocMemPool(MemPool_bitstream_t *memPool, int32_T width)
{
  bitstream_t *dataPtr;
  if (memPool->fNumFree > 0) {
    memPool->fNumFree--;
    dataPtr = memPool->fFreeList[memPool->fNumFree];
  } else if (memPool->fNumUsed < memPool->fSize) {
    dataPtr = &memPool->fMemArray[memPool->fNumUsed];
    memPool->fNumUsed += width;
  } else {
    dataPtr = NULL;
  }

  return dataPtr;
}

boolean_T EV_SLAC_emplace_n(Queue_bitstream_t *q, const bitstream_t *dataIn)
{
  Msg_bitstream_t *msg;
  int32_T newTail;
  boolean_T isEmplaced = false;
  newTail = (q->fTail + 1) % q->fCapacity;
  if (q->fHead != newTail) {
    q->fTail = newTail;
    msg = &q->fArray[newTail];
    msg->fData = EV_SLAC_allocMemPool(&EV_SLAC_DW.slMsgMgr_MemPool_bitstream_t,
      1);
    if (msg->fData != NULL) {
      *msg->fData = *dataIn;
      if (q->fHead == -1) {
        q->fHead = q->fTail;
      }

      isEmplaced = true;
    }
  }

  return isEmplaced;
}

boolean_T EV_SLAC_emplace(Queue_boolean_T *q, const boolean_T *dataIn)
{
  Msg_boolean_T *msg;
  int32_T newTail;
  boolean_T isEmplaced = false;
  newTail = (q->fTail + 1) % q->fCapacity;
  if (q->fHead != newTail) {
    q->fTail = newTail;
    msg = &q->fArray[newTail];
    msg->fData = *dataIn;
    if (q->fHead == -1) {
      q->fHead = q->fTail;
    }

    isEmplaced = true;
  }

  return isEmplaced;
}

boolean_T EV_SLAC_pop_k(Queue_bitstream_t *q, Msg_bitstream_t *elementOut)
{
  boolean_T isPop;
  if (q->fHead == -1) {
    isPop = false;
  } else {
    *elementOut = q->fArray[q->fHead];
    isPop = true;
    if (q->fHead == q->fTail) {
      q->fHead = -1;
      q->fTail = -1;
    } else {
      q->fHead = (q->fHead + 1) % q->fCapacity;
    }
  }

  return isPop;
}

boolean_T EV_SLAC_pop(Queue_boolean_T *q, Msg_boolean_T *elementOut)
{
  boolean_T isPop;
  if (q->fHead == -1) {
    isPop = false;
  } else {
    *elementOut = q->fArray[q->fHead];
    isPop = true;
    if (q->fHead == q->fTail) {
      q->fHead = -1;
      q->fTail = -1;
    } else {
      q->fHead = (q->fHead + 1) % q->fCapacity;
    }
  }

  return isPop;
}

void EV_SLAC_initQueue_i(Queue_bitstream_t *q, QueuePolicy_T policy, int32_T
  capacity, Msg_bitstream_t *qPool)
{
  q->fPolicy = policy;
  q->fCapacity = capacity;
  q->fHead = -1;
  q->fTail = -1;
  q->fArray = qPool;
}

void EV_SLAC_initQueue(Queue_boolean_T *q, QueuePolicy_T policy, int32_T
  capacity, Msg_boolean_T *qPool)
{
  q->fPolicy = policy;
  q->fCapacity = capacity;
  q->fHead = -1;
  q->fTail = -1;
  q->fArray = qPool;
}

void EV_SLAC_step(void)
{
  EV_SLAC_M->Timing.clockTick0++;
}

void EV_SLAC_initialize(void)
{
  rt_InitInfAndNaN(sizeof(real_T));
  EV_SLAC_initMemPool(&EV_SLAC_DW.slMsgMgr_MemPool_bitstream_t,
                      &EV_SLAC_DW.slMsgMgr_memArray_bitstream_t[0],
                      &EV_SLAC_DW.slMsgMgr_freeList_bitstream_t[0], 6);

  {
    int32_T i;
    uint32_T state_d;
    EV_SLAC_M->Timing.clockTick1 = EV_SLAC_M->Timing.clockTick0;
    EV_SLAC_SharedDSM.connStream = EV_SLAC_P.DataStoreMemory_InitialValue;
    EV_SLAC_SharedDSM.errorNo = EV_SLAC_P.DataStoreMemory1_InitialValue;
    EV_SLAC_SharedDSM.EVCC_CONFIG_SET = EV_SLAC_P.DataStoreMemory10_InitialValue;
    EV_SLAC_SharedDSM.EVSE_PAIRING_SET =
      EV_SLAC_P.DataStoreMemory11_InitialValue;
    EV_SLAC_SharedDSM.global_session = EV_SLAC_P.DataStoreMemory2_InitialValue;
    EV_SLAC_SharedDSM.global_channel = EV_SLAC_P.DataStoreMemory3_InitialValue;
    EV_SLAC_SharedDSM.global_message = EV_SLAC_P.DataStoreMemory4_InitialValue;
    for (i = 0; i < 256; i++) {
      EV_SLAC_SharedDSM.UDP_PORT[i] = EV_SLAC_P.DataStoreMemory5_InitialValue;
    }

    for (i = 0; i < 30; i++) {
      EV_SLAC_SharedDSM.Buffer_received[i] =
        EV_SLAC_P.DataStoreMemory6_InitialValue;
    }

    EV_SLAC_SharedDSM.sdpMesg_res = EV_SLAC_P.DataStoreMemory7_InitialValue;
    EV_SLAC_SharedDSM.ExiDoc_Buff = EV_SLAC_P.DataStoreMemory8_InitialValue;
    EV_SLAC_SharedDSM.TCP_recvStatus = EV_SLAC_P.DataStoreMemory9_InitialValue;
    EV_SLAC_initialize_msg_local_queues_for_chart();
    EV_SLAC_DW.ret = -1;
    EV_SLAC_DW.TT_match_response = Slac_timing_constant.TT_match_response;
    EV_SLAC_DW.TP_EV_batch_msg_interval =
      Slac_timing_constant.TP_EV_batch_msg_interval;
    EV_SLAC_DW.TP_EV_match_session = Slac_timing_constant.TP_EV_match_session;
    EV_SLAC_DW.TT_EV_atten_results = Slac_timing_constant.TT_EV_atten_results;
    EV_SLAC_DW.TP_match_sequence = Slac_timing_constant.TP_match_sequence;
    EV_SLAC_DW.TT_match_join = Slac_timing_constant.TT_match_join;
    EV_SLAC_DW.V2G_EVCC_CommunicationSetup_Timeout =
      Slac_timing_constant.V2G_EVCC_CommunicationSetup_Timeout;
    EV_SLAC_DW.PowerDeliveryReq_Timeout =
      V2G_EVCC_Msg_Timeout.PowerDeliveryReq_Timeout;
    EV_SLAC_DW.ret2 = -1;
    EV_SLAC_DW.ServiceDiscoveryReq_Timeout =
      V2G_EVCC_Msg_Timeout.ServiceDiscoveryReq_Timeout;
    EV_SLAC_DW.AuthorizationReq_Timeout =
      V2G_EVCC_Msg_Timeout.AuthorizationReq_Timeout;
    EV_SLAC_DW.ChargeParameterDiscoveryReq_Timeout =
      V2G_EVCC_Msg_Timeout.ChargeParameterDiscoveryReq_Timeout;
    EV_SLAC_DW.PaymentServiceSelectionReq_Timeout =
      V2G_EVCC_Msg_Timeout.PaymentServiceSelectionReq_Timeout;
    EV_SLAC_DW.CableCheckReq_Timeout =
      V2G_EVCC_Msg_Timeout.CableCheckReq_Timeout;
    EV_SLAC_DW.PreChargeReq_Timeout = V2G_EVCC_Msg_Timeout.PreChargeReq_Timeout;
    EV_SLAC_DW.V2G_EVCC_Ongoing_Timeout =
      rt_Simulink_Struct.V2G_EVCC_Ongoing_Timeout;
    EV_SLAC_V2GLinkSetupSLACInitializationopenChannel_Init();
    EV_SLAC_V2GLinkSetupSLACSlac_parampev_cm_slac_param_request_Init(&i);
    EV_SLAC_V2GLinkSetupSLACSlac_parampev_cm_slac_param_response_Init(&i);
    EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_start_atten_char_Init(&i);
    EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_mnbc_sound_Init(&i);
    EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_atten_char_IND_Init(&i);
    EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONpev_cm_atten_char_RSP_Init(&i);
    EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONcheckAAG_Init(&i);
    EV_S_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_Init
      (&EV_SLAC_B.V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ,
       &EV_SLAC_P.V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ);
    EV_S_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_Init
      (&EV_SLAC_B.V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES,
       &EV_SLAC_P.V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES);
    EV_SLAC_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_Init(
      &EV_SLAC_B.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ,
      &EV_SLAC_P.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ);
    EV_SLAC_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_Init(
      &EV_SLAC_B.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF,
      &EV_SLAC_P.V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF);
    EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_slac_match_Init(&i);
    EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_set_key_REQ_Init(&i);
    EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_set_key_CNF_Init(&i);
    state_d = 0U;
    EV_SLAC_DW.method_h = 7U;
    EV_SLAC_DW.state_f[0] = 362436069U;
    EV_SLAC_DW.state_f[1] = 521288629U;
    EV_SLAC_DW.seed = 1144108930U;
    EV_SLAC_rng(15118.0, &state_d);
    EV_SLAC_rng(15118.0, &state_d);
    EV_SLAC_SystemCore_setup(&EV_SLAC_DW.obj);
    V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp__Init
      (&EV_SLAC_B.V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req,
       &EV_SLAC_DW.V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req,
       &EV_SLAC_P.V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req);
    EV_SLAC_DW.method = 7U;
    EV_SLAC_DW.state = 1144108930U;
    EV_SLAC_DW.state_a[0] = 362436069U;
    EV_SLAC_DW.state_a[1] = 521288629U;
    EV_SLAC_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_Init
      (&EV_SLAC_B.V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq,
       &EV_SLAC_P.V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq);
    EV_SLAC_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_Init
      (&EV_SLAC_B.V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq,
       &EV_SLAC_P.V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq);
    EV_SLAC_EnabledSubsystem_Init(&EV_SLAC_B.EnabledSubsystem,
      &EV_SLAC_P.EnabledSubsystem);
    for (i = 0; i < 13; i++) {
      EV_SLAC_B.Assignment3_d[i] = EV_SLAC_P.TimeArray_Y0;
      EV_SLAC_B.Assignment1_c[i] = EV_SLAC_P.PmaxArray_out_Y0;
    }

    EV_SLAC_EnabledSubsystem_Init(&EV_SLAC_B.EnabledSubsystem_p,
      &EV_SLAC_P.EnabledSubsystem_p);
    for (i = 0; i < 13; i++) {
      EV_SLAC_B.Assignment3_g[i] = EV_SLAC_P.TimeArray_Y0_d;
      EV_SLAC_B.Assignment1_o[i] = EV_SLAC_P.EpriceArray_out_Y0;
    }

    EV_SLAC_B.Cast_e = EV_SLAC_P.SAScheduleTupleID_Y0;
    for (i = 0; i < 39; i++) {
      EV_SLAC_B.Assignment1[i] = EV_SLAC_P.PmaxSchedule_Y0;
      EV_SLAC_B.Assignment2[i] = EV_SLAC_P.TimePointSchedule_Y0;
      EV_SLAC_B.Assignment3[i] = EV_SLAC_P.EpriceScheduleList_Y0;
      EV_SLAC_B.Assignment4[i] = EV_SLAC_P.TimePointSchedule_Eprice_Y0;
    }

    EV_SLAC_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_Init
      (&EV_SLAC_B.V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq,
       &EV_SLAC_P.V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq);
    EV_SLAC_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_Init
      (&EV_SLAC_B.V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq,
       &EV_SLAC_P.V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq);
    EV_SLAC_ProtocolEncoder_Init(&EV_SLAC_DW.ProtocolEncoder);
    EV_SLAC_B.BusAssignment_f = EV_SLAC_P.msgRecv_Y0;
    EV_SLAC_B.PDU_Read_o2 = EV_SLAC_P.recvStatus_Y0_i;
    EV_SLAC_ProtocolDecoder_Init(&EV_SLAC_DW.ProtocolDecoder_k);
    EV_SLAC_B.Switch = EV_SLAC_P.recvStatus_Y0;
    EV_SLAC_ProtocolDecoder_Init(&EV_SLAC_DW.ProtocolDecoder_kq);
    EV_SLAC_ProtocolEncoder_Init(&EV_SLAC_DW.ProtocolEncoder_k);
  }

  {
    pthread_attr_t attr;
    pthread_t thread;
    struct sched_param param;
    int policy;
    int inherit;
    int ret;
    size_t stackSize;
    pthread_attr_init(&attr);
    inherit = PTHREAD_EXPLICIT_SCHED;
    ret = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    CHECK_STATUS(ret, "pthread_attr_setinheritsched");
    ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    CHECK_STATUS(ret, "pthread_attr_setdetachstate");
    stackSize = (512 > PTHREAD_STACK_MIN) ? 512:PTHREAD_STACK_MIN;
    ret = pthread_attr_setstacksize(&attr, stackSize);
    CHECK_STATUS(ret, "pthread_attr_setstacksize");
    policy = SCHED_OTHER;
    ret = pthread_attr_setschedpolicy(&attr, policy);
    CHECK_STATUS(ret, "pthread_attr_setschedpolicy");
    ret = pthread_create(&thread, &attr, (void *) Task0_fcn, NULL);
    CHECK_STATUS(ret, "pthread_create");
    pthread_attr_destroy(&attr);
  }

  EV_SLAC_M->Timing.clockTick1 = EV_SLAC_M->Timing.clockTick0;
  EV_SLAC_DW.previousTime = ((EV_SLAC_M->Timing.clockTick1) * 0.01);
}

void EV_SLAC_terminate(void)
{
  if (!(int32_T)EV_SLAC_DW.obj.matlabCodegenIsDeleted) {
    EV_SLAC_DW.obj.matlabCodegenIsDeleted = true;
  }

  V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp__Term
    (&EV_SLAC_DW.V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req);
  EV_SLAC_ProtocolEncoder_Term(&EV_SLAC_DW.ProtocolEncoder);
  EV_SLAC_ProtocolDecoder_Term(&EV_SLAC_DW.ProtocolDecoder_k);
  EV_SLAC_ProtocolDecoder_Term(&EV_SLAC_DW.ProtocolDecoder_kq);
  EV_SLAC_ProtocolEncoder_Term(&EV_SLAC_DW.ProtocolEncoder_k);
}
