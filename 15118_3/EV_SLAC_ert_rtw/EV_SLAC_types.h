#ifndef RTW_HEADER_EV_SLAC_types_h_
#define RTW_HEADER_EV_SLAC_types_h_
#include "rtwtypes.h"
#include "appHandEXIDatatypes.h"
#include "linuxUDP_portV6.h"
#include "iso1EXIDatatypes.h"
#include "EXITypes.h"
#include "types.h"
#include "slac.h"
#include "channel.h"
#include "mme.h"
#ifndef DEFINED_TYPEDEF_FOR_EVCC_CONFIG_
#define DEFINED_TYPEDEF_FOR_EVCC_CONFIG_

typedef struct {
  EVCCID_iso1SessionSetupReqType EVCCID;
  iso1EnergyTransferModeType vc_requestedEnergyTransferModeAC;
  iso1EnergyTransferModeType vc_requestedEnergyTransferModeDC;
  uint32_T vc_DepartureTime;
  iso1PhysicalValueType vc_EAmount;
  iso1PhysicalValueType vc_EVMaxVoltage;
  iso1PhysicalValueType vc_EVMaxCurrent;
  iso1PhysicalValueType vc_EVMinCurrent;
  iso1chargeProgressType vc_ChargeProgress;
  iso1EVSENotificationType vc_EVSENotification;
  iso1CertificateChainType vc_contractSignatureCertChain;
  iso1SAScheduleListType vc_SASchedule_List;
  iso1SAScheduleListType vc_SASchedules;
  iso1PMaxScheduleType vc_PMaxSchedule;
  uint8_T vc_SAScheduleTupleId;
  iso1PhysicalValueType vc_EVSENominalVoltage;
  iso1PhysicalValueType vc_EVSEMaxCurrent;
  iso1PhysicalValueType vc_EVSEMaximumCurrentLimit;
  iso1PhysicalValueType vc_EVSEMinimumCurrentLimit;
  iso1PhysicalValueType vc_EVSEMaximumVoltageLimit;
  iso1PhysicalValueType vc_EVSEMinimumVoltageLimit;
  iso1PhysicalValueType vc_EVSEMaximumPowerLimit;
  iso1PhysicalValueType vc_EVSEPeakCurrentRipple;
  iso1PhysicalValueType vc_EVTargetVoltage;
  iso1PhysicalValueType vc_EVTargetCurrent;
  iso1PhysicalValueType vc_EVPreChargeTargetCurrent;
  iso1PhysicalValueType vc_EVSEPresentVoltage;
  iso1PhysicalValueType vc_EVSEPresentCurrent;
  iso1MeterInfoType vc_MeterInfo;
  iso1DC_EVStatusType vc_DC_EVStatus;
  iso1PhysicalValueType vc_EVMaximumVoltageLimit;
  iso1PhysicalValueType vc_EVMaximumCurrentLimit;
  iso1PhysicalValueType vc_EVMaximumPowerLimit;
  iso1PhysicalValueType vc_DC_remainingTimeToBulkSoC;
  iso1PhysicalValueType vc_DC_remainingTimeToFullSoC;
  char_T vc_contractPrivateKey[256];
  iso1ServiceListType vc_serviceList;
  iso1ChargeServiceType vc_chargeService;
  iso1PaymentOptionListType vc_paymentOptionList;
  iso1SupportedEnergyTransferModeType vc_supportedEnergyTransferMode;
  iso1paymentOptionType vc_SelectedPaymentOption;
} EVCC_CONFIG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EVSE_PAIRING_
#define DEFINED_TYPEDEF_FOR_EVSE_PAIRING_

typedef struct {
  SessionID_iso1MessageHeaderType SessionID;
  EVSEID_iso1SessionSetupResType EVSEID;
  real32_T PmaxScheduleList[39];
  real32_T TimePointPmaxScheduleList[39];
  real32_T EpriceScheduleList[39];
  real32_T TimePointPriceScheduleList[39];
  uint16_T ScheduleTupleIDList;
  uint16_T ScheduleTupleLen;
} EVSE_PAIRING;

#endif

#ifndef DEFINED_TYPEDEF_FOR_QueuePolicy_T_
#define DEFINED_TYPEDEF_FOR_QueuePolicy_T_

typedef enum {
  MSG_QUEUE_UNUSED = -1,
  MSG_FIFO_QUEUE,
  MSG_LIFO_QUEUE,
  MSG_PRIORITY_QUEUE
} QueuePolicy_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Msg_boolean_T_
#define DEFINED_TYPEDEF_FOR_Msg_boolean_T_

typedef struct {
  boolean_T fData;
} Msg_boolean_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Queue_boolean_T_
#define DEFINED_TYPEDEF_FOR_Queue_boolean_T_

typedef struct {
  QueuePolicy_T fPolicy;
  int32_T fHead;
  int32_T fTail;
  int32_T fCapacity;
  Msg_boolean_T *fArray;
} Queue_boolean_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Msg_bitstream_t_
#define DEFINED_TYPEDEF_FOR_Msg_bitstream_t_

typedef struct {
  bitstream_t *fData;
} Msg_bitstream_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Queue_bitstream_t_
#define DEFINED_TYPEDEF_FOR_Queue_bitstream_t_

typedef struct {
  QueuePolicy_T fPolicy;
  int32_T fHead;
  int32_T fTail;
  int32_T fCapacity;
  Msg_bitstream_t *fArray;
} Queue_bitstream_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MemPool_bitstream_t_
#define DEFINED_TYPEDEF_FOR_MemPool_bitstream_t_

typedef struct {
  bitstream_t *fMemArray;
  int32_T fNumUsed;
  bitstream_t **fFreeList;
  int32_T fNumFree;
  int32_T fSize;
} MemPool_bitstream_t;

#endif

#ifndef struct_tag_EZX87pxGevkvjdbi99XOED
#define struct_tag_EZX87pxGevkvjdbi99XOED

struct tag_EZX87pxGevkvjdbi99XOED
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
};

#endif

#ifndef typedef_matlabshared_embedded_utilities_blocks_ProtocolEncoderBlock_EV_SLAC_T
#define typedef_matlabshared_embedded_utilities_blocks_ProtocolEncoderBlock_EV_SLAC_T

typedef struct tag_EZX87pxGevkvjdbi99XOED
  matlabshared_embedded_utilities_blocks_ProtocolEncoderBlock_EV_SLAC_T;

#endif

#ifndef struct_tag_wJk5RqrZOIACUbqs5cF3PB
#define struct_tag_wJk5RqrZOIACUbqs5cF3PB

struct tag_wJk5RqrZOIACUbqs5cF3PB
{
  uint32_T f1;
  boolean_T f2;
};

#endif

#ifndef typedef_cell_EV_SLAC_T
#define typedef_cell_EV_SLAC_T

typedef struct tag_wJk5RqrZOIACUbqs5cF3PB cell_EV_SLAC_T;

#endif

#ifndef struct_tag_3BUuSiaLsxaYKAERtImzYC
#define struct_tag_3BUuSiaLsxaYKAERtImzYC

struct tag_3BUuSiaLsxaYKAERtImzYC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  uint8_T DataBuffer[8];
  cell_EV_SLAC_T PrevOutCellArray;
};

#endif

#ifndef typedef_matlabshared_embedded_utilities_blocks_ProtocolDecoderBlock_EV_SLAC_T
#define typedef_matlabshared_embedded_utilities_blocks_ProtocolDecoderBlock_EV_SLAC_T

typedef struct tag_3BUuSiaLsxaYKAERtImzYC
  matlabshared_embedded_utilities_blocks_ProtocolDecoderBlock_EV_SLAC_T;

#endif

#ifndef struct_tag_hWgtZAPqSjs1EyhETh9jYH
#define struct_tag_hWgtZAPqSjs1EyhETh9jYH

struct tag_hWgtZAPqSjs1EyhETh9jYH
{
  int32_T isInitialized;
};

#endif

#ifndef typedef_comm_internal_RandomIntegerGenerator_EV_SLAC_T
#define typedef_comm_internal_RandomIntegerGenerator_EV_SLAC_T

typedef struct tag_hWgtZAPqSjs1EyhETh9jYH
  comm_internal_RandomIntegerGenerator_EV_SLAC_T;

#endif

#ifndef struct_tag_GEwMBqGX9Ti2ok51rNTAfC
#define struct_tag_GEwMBqGX9Ti2ok51rNTAfC

struct tag_GEwMBqGX9Ti2ok51rNTAfC
{
  uint32_T f1;
  uint8_T f2[16];
  uint16_T f3;
  uint8_T f4;
  uint8_T f5;
  boolean_T f6;
};

#endif

#ifndef typedef_cell_EV_SLAC_m_T
#define typedef_cell_EV_SLAC_m_T

typedef struct tag_GEwMBqGX9Ti2ok51rNTAfC cell_EV_SLAC_m_T;

#endif

#ifndef struct_tag_mFYxvYq2z1krgW8lVREqJG
#define struct_tag_mFYxvYq2z1krgW8lVREqJG

struct tag_mFYxvYq2z1krgW8lVREqJG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  uint8_T DataBuffer[28];
  cell_EV_SLAC_m_T PrevOutCellArray;
};

#endif

#ifndef typedef_matlabshared_embedded_utilities_blocks_ProtocolDecoderBlock_EV_SLAC_k_T
#define typedef_matlabshared_embedded_utilities_blocks_ProtocolDecoderBlock_EV_SLAC_k_T

typedef struct tag_mFYxvYq2z1krgW8lVREqJG
  matlabshared_embedded_utilities_blocks_ProtocolDecoderBlock_EV_SLAC_k_T;

#endif

#ifndef SS_UINT64
#define SS_UINT64                      296
#endif

#ifndef SS_INT64
#define SS_INT64                       297
#endif

typedef struct P_V2GLinkSetupSLACSlac_paraminscreseRunID_EV_SLAC_T_
  P_V2GLinkSetupSLACSlac_paraminscreseRunID_EV_SLAC_T;
typedef struct
  P_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_EV_SL_T_
  P_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_EV_SL_T;
typedef struct
  P_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_EV_SL_T_
  P_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_EV_SL_T;
typedef struct
  P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_EV_SLAC_T_
  P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_EV_SLAC_T;
typedef struct
  P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_EV_SLAC_T_
  P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_EV_SLAC_T;
typedef struct P_V2GLinkSetuperrorHandleTimeOutHandle_EV_SLAC_T_
  P_V2GLinkSetuperrorHandleTimeOutHandle_EV_SLAC_T;
typedef struct
  P_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_r_T_
  P_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_r_T;
typedef struct
  P_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_EV_SLAC_T_
  P_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_EV_SLAC_T;
typedef struct
  P_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_EV_SLAC_T_
  P_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_EV_SLAC_T;
typedef struct P_EnabledSubsystem_EV_SLAC_T_ P_EnabledSubsystem_EV_SLAC_T;
typedef struct P_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_EV_SLAC_T_
  P_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_EV_SLAC_T;
typedef struct P_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_EV_SLAC_T_
  P_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_EV_SLAC_T;
typedef struct P_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy_EV_SLAC_T_
  P_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy_EV_SLAC_T;
typedef struct P_EV_SLAC_T_ P_EV_SLAC_T;
typedef struct tag_RTM_EV_SLAC_T RT_MODEL_EV_SLAC_T;

#endif

