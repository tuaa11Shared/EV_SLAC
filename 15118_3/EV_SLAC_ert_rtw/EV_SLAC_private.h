#ifndef RTW_HEADER_EV_SLAC_private_h_
#define RTW_HEADER_EV_SLAC_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "slac.h"
#include "EV_SLAC.h"
#include "channel.h"
#include "mme.h"
#include "EV_SLAC_types.h"
#include "iso1EXIDatatypes.h"
#include "EXITypes.h"

#define NUM_TSK_BLOCKS                 (1)
#define CHECK_STATUS(status, fcn)      if (status != 0) {printf("Call to %s returned error status (%d): %s.\n", fcn, status,strerror(errno)); fflush(stdout); exit(EXIT_FAILURE);}

extern void EV_SLAC_initMemPool(MemPool_bitstream_t *memPool, bitstream_t
  *memArray, bitstream_t **freeList, int32_T size);
extern void EV_SLAC_freeMemPool(MemPool_bitstream_t *memPool, bitstream_t
  *dataPtr);
extern void EV_SLAC_destroyMsg_f(Msg_bitstream_t *msg);
extern bitstream_t *EV_SLAC_allocMemPool(MemPool_bitstream_t *memPool, int32_T
  width);
extern boolean_T EV_SLAC_emplace_n(Queue_bitstream_t *q, const bitstream_t
  *dataIn);
extern boolean_T EV_SLAC_emplace(Queue_boolean_T *q, const boolean_T *dataIn);
extern boolean_T EV_SLAC_pop_k(Queue_bitstream_t *q, Msg_bitstream_t *elementOut);
extern boolean_T EV_SLAC_pop(Queue_boolean_T *q, Msg_boolean_T *elementOut);
extern void EV_SLAC_initQueue_i(Queue_bitstream_t *q, QueuePolicy_T policy,
  int32_T capacity, Msg_bitstream_t *qPool);
extern void EV_SLAC_initQueue(Queue_boolean_T *q, QueuePolicy_T policy, int32_T
  capacity, Msg_boolean_T *qPool);
extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);
extern void EV_SLAC_V2GLinkSetupSLACSlac_paraminscreseRunID(session_t
  *rtd_global_session, const
  ConstB_V2GLinkSetupSLACSlac_paraminscreseRunID_EV_SLAC_T *localC);
extern void
  EV_S_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_Init
  (B_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_EV_SL_T
   *localB,
   P_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_EV_SL_T
   *localP);
extern void
  EV_SLAC_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ
  (channel_t *rtd_global_channel, MESSAGE *rtd_global_message, session_t
   *rtd_global_session,
   B_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_EV_SL_T
   *localB);
extern void
  EV_S_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_Init
  (B_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_EV_SL_T
   *localB,
   P_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_EV_SL_T
   *localP);
extern void
  EV_SLAC_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES
  (channel_t *rtd_global_channel, MESSAGE *rtd_global_message, session_t
   *rtd_global_session,
   B_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_EV_SL_T
   *localB);
extern void
  EV_SLAC_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_Init
  (B_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_EV_SLAC_T
   *localB,
   P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_EV_SLAC_T
   *localP);
extern void
  EV_SLAC_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ
  (channel_t *rtd_global_channel, MESSAGE *rtd_global_message, session_t
   *rtd_global_session,
   B_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_EV_SLAC_T
   *localB,
   P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_EV_SLAC_T
   *localP);
extern void
  EV_SLAC_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_Init
  (B_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_EV_SLAC_T
   *localB,
   P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_EV_SLAC_T
   *localP);
extern void
  EV_SLAC_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF
  (channel_t *rtd_global_channel, MESSAGE *rtd_global_message, session_t
   *rtd_global_session,
   B_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_EV_SLAC_T
   *localB,
   P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_EV_SLAC_T
   *localP);
extern void EV_SLAC_V2GLinkSetuperrorHandleTimeOutHandle
  (B_V2GLinkSetuperrorHandleTimeOutHandle_EV_SLAC_T *localB,
   P_V2GLinkSetuperrorHandleTimeOutHandle_EV_SLAC_T *localP);
extern void EV_SLAC_MATLABFunction(uint8_T rtu_u, B_MATLABFunction_EV_SLAC_T
  *localB);
extern void
  V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp__Init
  (B_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_r_T
   *localB,
   DW_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp__T
   *localDW,
   P_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_r_T
   *localP);
extern void
  E_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req
  (uint8_T rtd_UDP_PORT[256],
   B_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_r_T
   *localB, const
   ConstB_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERY_T
   *localC,
   DW_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp__T
   *localDW,
   P_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_r_T
   *localP);
extern void EV_SLAC_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_Init
  (B_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_EV_SLAC_T *localB,
   P_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_EV_SLAC_T *localP);
extern void EV_SLAC_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq(const
  EVSE_PAIRING *rtd_EVSE_PAIRING_SET, const iso1EXIDocument *rtd_ExiDoc_Buff,
  B_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_EV_SLAC_T *localB,
  P_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_EV_SLAC_T *localP);
extern void
  EV_SLAC_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_Init
  (B_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_EV_SLAC_T
   *localB,
   P_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_EV_SLAC_T
   *localP);
extern void
  EV_SLAC_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq(
  const EVSE_PAIRING *rtd_EVSE_PAIRING_SET, const iso1EXIDocument
  *rtd_ExiDoc_Buff,
  B_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_EV_SLAC_T *
  localB,
  P_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_EV_SLAC_T *
  localP);
extern void EV_SLAC_EnabledSubsystem_Init(B_EnabledSubsystem_EV_SLAC_T *localB,
  P_EnabledSubsystem_EV_SLAC_T *localP);
extern void EV_SLAC_EnabledSubsystem(uint8_T rtu_Enable, const
  iso1RelativeTimeIntervalType *rtu_In1, B_EnabledSubsystem_EV_SLAC_T *localB);
extern void EV_SLAC_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_Init
  (B_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_EV_SLAC_T *localB,
   P_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_EV_SLAC_T *localP);
extern void EV_SLAC_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq(const
  EVSE_PAIRING *rtd_EVSE_PAIRING_SET, const iso1EXIDocument *rtd_ExiDoc_Buff,
  B_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_EV_SLAC_T *localB,
  P_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_EV_SLAC_T *localP);
extern void EV_SLAC_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_Init
  (B_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_EV_SLAC_T *localB,
   P_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_EV_SLAC_T *localP);
extern void EV_SLAC_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq(const
  EVSE_PAIRING *rtd_EVSE_PAIRING_SET, const iso1EXIDocument *rtd_ExiDoc_Buff,
  B_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_EV_SLAC_T *localB,
  P_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_EV_SLAC_T *localP);
extern void EV_SLAC_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy
  (B_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy_EV_SLAC_T *localB,
   P_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy_EV_SLAC_T *localP);
extern void EV_SLAC_ProtocolEncoder_Init(DW_ProtocolEncoder_EV_SLAC_T *localDW);
extern void EV_SLAC_ProtocolEncoder(uint32_T rtu_0, B_ProtocolEncoder_EV_SLAC_T *
  localB, DW_ProtocolEncoder_EV_SLAC_T *localDW);
extern void EV_SLAC_ProtocolDecoder_Init(DW_ProtocolDecoder_EV_SLAC_T *localDW);
extern void EV_SLAC_ProtocolDecoder(const uint8_T rtu_0[8],
  B_ProtocolDecoder_EV_SLAC_T *localB, DW_ProtocolDecoder_EV_SLAC_T *localDW);
extern void EV_SLAC_V2GLinkSetupSLACInitializationopenChannel_Init(void);
extern void EV_SLAC_V2GLinkSetupSLACInitializationopenChannel(void);
extern void EV_SLAC_V2GLinkSetupSLACSlac_parampev_cm_slac_param_request_Init
  (int32_T *rty_ret);
extern void EV_SLAC_V2GLinkSetupSLACSlac_parampev_cm_slac_param_request(int32_T *
  rty_ret);
extern void EV_SLAC_V2GLinkSetupSLACSlac_parampev_cm_slac_param_response_Init
  (int32_T *rty_ret);
extern void EV_SLAC_V2GLinkSetupSLACSlac_parampev_cm_slac_param_response(int32_T
  *rty_ret);
extern void
  V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp__Term
  (DW_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp__T
   *localDW);
extern void EV_SLAC_ProtocolEncoder_Term(DW_ProtocolEncoder_EV_SLAC_T *localDW);
extern void EV_SLAC_ProtocolDecoder_Term(DW_ProtocolDecoder_EV_SLAC_T *localDW);

#endif

