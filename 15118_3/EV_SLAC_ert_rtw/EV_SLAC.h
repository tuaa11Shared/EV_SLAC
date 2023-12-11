#ifndef RTW_HEADER_EV_SLAC_h_
#define RTW_HEADER_EV_SLAC_h_
#ifndef EV_SLAC_COMMON_INCLUDES_
#define EV_SLAC_COMMON_INCLUDES_
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <semaphore.h>
#include <errno.h>
#include <stdio.h>
#include <limits.h>
#include "rtwtypes.h"
#include "ProtocolDecoderUtilities.h"
#endif

#include <stddef.h>
#include "EV_SLAC_types.h"
#include "iso1EXIDatatypes.h"
#include "EXITypes.h"
#include "appHandEXIDatatypes.h"
#include "slac.h"
#include "channel.h"
#include "linuxUDP_portV6.h"
#include "mme.h"
#include "types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"

#include "../tools/getoptv.h"
#include "../tools/putoptv.h"
#include "../tools/memory.h"
#include "../tools/number.h"
#include "../tools/types.h"
#include "../tools/flags.h"
#include "../tools/files.h"
#include "../tools/error.h"
#include "../tools/config.h"
#include "../tools/permissions.h"
#include "../tools/timer.h"
#include "../ether/channel.h"
#include "../slac/slac.h"
#include "/home/tuannt/Documents/MATLAB/15118_3/CustomCode/linuxUDP_portV6.h"
#include "/home/tuannt/Documents/MATLAB/15118_3/CustomCode/MW_TCPSendReceive_portedV6.h"
#include "/home/tuannt/Documents/MATLAB/15118_3/openV2G/EXITypes.h"
#include "EXITypes.h"
#include "appHandEXIDatatypes.h"
#include "appHandEXIDatatypesEncoder.h"
#include "appHandEXIDatatypesDecoder.h"
#include "iso1EXIDatatypes.h"
#include "iso1EXIDatatypesEncoder.h"
#include "iso1EXIDatatypesDecoder.h"
#include "v2gtp.h"

typedef struct {
  int32_T CCaller;
} B_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_EV_SL_T;

typedef struct {
  int32_T CCaller;
} B_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_EV_SL_T;

typedef struct {
  int32_T CCaller;
} B_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_EV_SLAC_T;

typedef struct {
  int32_T CCaller;
} B_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_EV_SLAC_T;

typedef struct {
  char_T rtb_ComposeString_oo_m[256];
  char_T cv[100];
  int8_T Cast1_bd[100];
} B_V2GLinkSetuperrorHandleTimeOutHandle_EV_SLAC_T;

typedef struct {
  uint8_T y[2];
} B_MATLABFunction_EV_SLAC_T;

typedef struct {
  int32_T CCaller1;
} B_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_r_T;

typedef struct {
  matlabshared_embedded_utilities_blocks_ProtocolEncoderBlock_EV_SLAC_T obj;
} DW_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp__T;

typedef struct {
  iso1EXIDocument BusAssignment_m;
  bitstream_t CCaller1_o2;
  bitstream_t BusAssignment4_h;
  char_T rtb_ComposeString_oj_m[256];
  char_T cv[100];
  int8_T Cast1_hc[100];
  int32_T CCaller1_o1;
} B_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_EV_SLAC_T;

typedef struct {
  iso1EXIDocument BusAssignment_k;
  bitstream_t CCaller1_o2;
  bitstream_t BusAssignment11;
  char_T rtb_ComposeString_d_m[256];
  char_T cv[100];
  int8_T Cast1_f[100];
  iso1DC_EVChargeParameterType BusAssignment1_e4;
  int32_T CCaller1_o1;
} B_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_EV_SLAC_T;

typedef struct {
  real32_T CastToSingle;
  real32_T Add;
} B_EnabledSubsystem_EV_SLAC_T;

typedef struct {
  iso1EXIDocument BusAssignment_j;
  bitstream_t CCaller1_o2;
  bitstream_t BusAssignment4_f;
  char_T rtb_ComposeString_m_m[256];
  char_T cv[100];
  int8_T Cast1_e[100];
  int32_T CCaller1_o1;
} B_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_EV_SLAC_T;

typedef struct {
  iso1EXIDocument BusAssignment_d;
  bitstream_t CCaller1_o2;
  bitstream_t BusAssignment4_g;
  char_T rtb_ComposeString_ly_m[256];
  char_T cv[100];
  int8_T Cast1_i[100];
  int32_T CCaller1_o1;
} B_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_EV_SLAC_T;

typedef struct {
  int8_T Cast_m[50];
} B_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy_EV_SLAC_T;

typedef struct {
  uint8_T ProtocolEncoder[8];
} B_ProtocolEncoder_EV_SLAC_T;

typedef struct {
  matlabshared_embedded_utilities_blocks_ProtocolEncoderBlock_EV_SLAC_T obj;
  boolean_T objisempty;
} DW_ProtocolEncoder_EV_SLAC_T;

typedef struct {
  uint32_T ProtocolDecoder_o1;
  boolean_T ProtocolDecoder_o2;
} B_ProtocolDecoder_EV_SLAC_T;

typedef struct {
  matlabshared_embedded_utilities_blocks_ProtocolDecoderBlock_EV_SLAC_T obj;
  boolean_T objisempty;
} DW_ProtocolDecoder_EV_SLAC_T;

typedef struct {
  iso1EXIDocument BusAssignment1_e;
  iso1EXIDocument CCaller2_o2_n;
  iso1EXIDocument CCaller2_o2_o;
  iso1EXIDocument CCaller2_o2_p;
  iso1EXIDocument CCaller2_o2_l;
  iso1EXIDocument CCaller2_o2_j;
  bitstream_t StreamIn;
  bitstream_t StreamIn_p;
  bitstream_t StreamIn_k;
  bitstream_t StreamIn_n;
  bitstream_t StreamIn_i;
  bitstream_t StreamIn_o;
  bitstream_t StreamIn_d;
  bitstream_t StreamIn_m;
  bitstream_t StreamIn_k4;
  bitstream_t BusAssignment_f;
  bitstream_t CCaller1_o2;
  bitstream_t CCaller1_o2_o;
  bitstream_t CCaller1_o2_k;
  bitstream_t CCaller2_o2;
  bitstream_t CCaller1_o2_f;
  bitstream_t BusAssignment;
  bitstream_t BusAssignment2_m;
  bitstream_t BusAssignment5_l;
  bitstream_t BusAssignment4_j;
  uint8_T VectorConcatenate_n[4104];
  uint8_T PDU_Read_o1[4096];
  uint32_T c_mt[625];
  uint32_T c_mt_m[625];
  appHandEXIDocument BusAssignment_f_c;
  appHandAppProtocolType BusAssignment1_g;
  char_T rtb_ComposeString_mb[256];
  char_T rtb_ComposeString_b_k[256];
  char_T rtb_ASCIItoString1_c[256];
  char_T rtb_ASCIItoString_if_b[256];
  char_T rtb_ASCIItoString_at_p[256];
  char_T rtb_ASCIItoString_ew_c[256];
  char_T rtb_ASCIItoString_cj_f[256];
  char_T rtb_ASCIItoString_de_g[256];
  char_T rtb_ComposeString_o_g[256];
  char_T rtb_ASCIItoString_ai_m[256];
  char_T rtb_ASCIItoString_lz_n[256];
  char_T rtb_StringConcatenate_a_p[256];
  char_T rtb_ASCIItoString_g4_l[256];
  char_T rtb_ASCIItoString_e4_j[256];
  char_T rtb_ASCIItoString_aj_d[256];
  char_T rtb_ASCIItoString_pr_g[256];
  char_T rtb_ASCIItoString_m5_l[256];
  char_T rtb_ASCIItoString_nn_d[256];
  char_T rtb_ASCIItoString_e1_d[256];
  char_T rtb_ASCIItoString_al_l[256];
  char_T rtb_ASCIItoString_pm_o[256];
  char_T rtb_ASCIItoString_p4_b[256];
  char_T rtb_ASCIItoString_fc_n[256];
  char_T rtb_ASCIItoString_ev_b[256];
  char_T rtb_ASCIItoString_cj3_l[256];
  char_T rtb_ASCIItoString_lat_h[256];
  char_T rtb_ASCIItoString_my_b[256];
  char_T rtb_ASCIItoString_lp_d[256];
  char_T rtb_StringConcatenate_dg_e[256];
  char_T rtb_ASCIItoString_gq_b[256];
  char_T rtb_ASCIItoString_ef_j[256];
  char_T rtb_ASCIItoString_je_f[256];
  char_T rtb_ASCIItoString_f_a[256];
  char_T rtb_ASCIItoString_h_j[256];
  char_T rtb_ASCIItoString_mq_j[256];
  char_T rtb_ASCIItoString_np_o[256];
  char_T rtb_ASCIItoString_nz_n[256];
  char_T rtb_StringConcatenate_f_i[256];
  char_T rtb_ASCIItoString_kc_o[256];
  char_T rtb_ASCIItoString_mu_n[256];
  char_T rtb_ASCIItoString_op_m[256];
  char_T rtb_ASCIItoString_bq_c[256];
  char_T rtb_ASCIItoString_j4_m[256];
  char_T rtb_ASCIItoString_p_m[256];
  char_T rtb_ASCIItoString_m4_j[256];
  char_T rtb_ASCIItoString_n4_h[256];
  char_T rtb_StringConcatenate_k_c[256];
  char_T rtb_ASCIItoString_j_c[256];
  char_T rtb_ASCIItoString_b_p[256];
  char_T rtb_ASCIItoString_jv_p[256];
  char_T rtb_ASCIItoString_eg_a[256];
  char_T rtb_ASCIItoString_bt_e[256];
  char_T rtb_ASCIItoString_l5_a[256];
  char_T rtb_ASCIItoString_k_a[256];
  char_T rtb_ASCIItoString_m0_i[256];
  char_T rtb_StringConcatenate_l_l[256];
  char_T rtb_ASCIItoString_lc_o[256];
  char_T rtb_ASCIItoString_c_o[256];
  char_T rtb_ASCIItoString_km_i[256];
  char_T rtb_ASCIItoString_a1_f[256];
  char_T rtb_ASCIItoString_oi_i[256];
  char_T rtb_ASCIItoString_g_f[256];
  char_T rtb_ASCIItoString_af_g[256];
  char_T rtb_ASCIItoString_d_c[256];
  char_T rtb_StringConcatenate_i_o[256];
  char_T rtb_ASCIItoString_lr_l[256];
  char_T rtb_ASCIItoString_i_m[256];
  char_T rtb_ASCIItoString_pq_m[256];
  char_T rtb_ASCIItoString_iy_c[256];
  char_T rtb_ASCIItoString_p3_f[256];
  char_T rtb_ASCIItoString_jp_p[256];
  char_T rtb_ASCIItoString_kr_e[256];
  char_T rtb_ASCIItoString_mj_o[256];
  char_T rtb_StringConcatenate_d_h[256];
  uint8_T CCaller_o2_f[256];
  session_t CCaller_o2;
  session_t CCaller_o2_l;
  session_t CCaller_o2_o;
  session_t CCaller_o2_g;
  real32_T Assignment1[39];
  real32_T Assignment2[39];
  real32_T Assignment3[39];
  real32_T Assignment4[39];
  char_T cv[120];
  char_T cv1[120];
  char_T cv2[120];
  char_T cv3[120];
  char_T cv4[120];
  char_T cv5[120];
  int8_T Cast2_ax[120];
  int8_T Cast2_k2[120];
  int8_T Cast2_d[120];
  int8_T Cast2_e[120];
  int8_T Cast2_k[120];
  int8_T Cast2_d0[120];
  char_T cv6[100];
  char_T cv7[100];
  char_T cv8[100];
  char_T cv9[100];
  int8_T Cast1_ma[100];
  int8_T Cast1_g[100];
  int8_T Cast1_n[100];
  int8_T Cast1_bt[100];
  channel_t BusAssignment_m;
  real32_T Assignment1_o[13];
  real32_T Assignment3_g[13];
  real32_T Assignment1_c[13];
  real32_T Assignment3_d[13];
  real32_T Assignment_o[13];
  real32_T Assignment2_n[13];
  real32_T Assignment_p[13];
  real32_T Assignment2_l[13];
  char_T cv10[50];
  int8_T Cast_f[50];
  int8_T Cast3[31];
  uint8_T CCaller2_o2_e[30];
  uint8_T payload[24];
  uint8_T CCaller2_o2_c[17];
  int8_T Cast1[17];
  char_T cv11[16];
  char_T cv12[16];
  int8_T Cast6_j2[16];
  int8_T Cast7_f[16];
  uint8_T b_varargout_2[16];
  real_T elapsedTime;
  real_T r;
  real_T r_h;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  uint8_T HeaderRead_o1[8];
  uint32_T b_u[2];
  uint32_T b_u_m[2];
  iso1SelectedServiceType BusAssignment_h;
  uint8_T header[4];
  real32_T Product;
  real32_T f;
  real32_T f1;
  int32_T Switch;
  int32_T Cast12;
  int32_T i;
  int32_T CCaller_d;
  int32_T Cast2;
  int32_T Cast6_l;
  int32_T CCaller1_o1_fj;
  int32_T i_m;
  int32_T c;
  int32_T CCaller2_o1_j;
  int32_T i_h;
  int32_T b_kk;
  int32_T i_c;
  int32_T Cast5_g;
  int32_T Cast3_g;
  int32_T i_k;
  int32_T CCaller2_o1_h;
  int32_T Cast3_p;
  int32_T i_p;
  int32_T Cast5_f;
  int32_T Cast3_i;
  int32_T i_px;
  int32_T Cast5_d0;
  int32_T Switch2;
  int32_T i_p4;
  int32_T Cast5_p;
  int32_T Cast3_f;
  int32_T i_a;
  int32_T b_kk_j;
  int32_T i_e;
  int32_T b_mti;
  uint32_T StreamMesg2Send_d_pos;
  uint32_T u;
  uint32_T temp;
  uint32_T u1;
  uint32_T r_o;
  uint32_T y;
  uint32_T u2;
  uint32_T u3;
  uint32_T u4;
  uint32_T u5;
  uint32_T u6;
  uint32_T mti;
  uint32_T y_b;
  uint32_T r_a;
  int8_T FindNonzeroElements[2];
  int16_T HeaderRead_o3;
  int16_T CCaller_o2_b;
  uint16_T Cast_e;
  uint16_T u7;
  uint16_T payloadLength;
  uint16_T inDataIdx;
  uint16_T Saturation_m;
  uint16_T s196_iter;
  uint16_T Saturation_i;
  int8_T PDU_Read_o2;
  int8_T HeaderRead_o2;
  uint8_T rtb_Cast1_m_g;
  uint8_T status;
  uint8_T terminator;
  uint8_T SumofElements_p;
  uint8_T SumofElements_c;
  uint8_T SumofElements_b;
  uint8_T SumofElements_j;
  uint8_T SumofElements_d;
  boolean_T StreamMesgOut_isValid;
  boolean_T ActiveTcpLoop_isValid;
  boolean_T Compare_j;
  boolean_T Compare_k;
  boolean_T Compare_b5;
  boolean_T Equal3;
  boolean_T AND_h;
  boolean_T OR_n;
  boolean_T isValid;
  boolean_T b_isvalid;
  boolean_T NAND_m;
  boolean_T AND_cs;
  boolean_T RelationalOperator6;
  boolean_T RelationalOperator5_l;
  boolean_T RelationalOperator3;
  boolean_T RelationalOperator5;
  boolean_T AND1_aw;
  boolean_T AND_e;
  boolean_T rtb_RelationalOperator2_l_e;
  boolean_T RelationalOperator5_g;
  boolean_T RelationalOperator1_p;
  boolean_T RelationalOperator6_e;
  boolean_T RelationalOperator5_g_f;
  boolean_T RelationalOperator5_n;
  boolean_T RelationalOperator4_m;
  boolean_T RelationalOperator6_j;
  boolean_T RelationalOperator10;
  boolean_T RelationalOperator5_n_h;
  boolean_T RelationalOperator3_a;
  boolean_T RelationalOperator4_p;
  boolean_T b_isvalid_e;
  B_ProtocolEncoder_EV_SLAC_T ProtocolEncoder_k;
  B_ProtocolDecoder_EV_SLAC_T ProtocolDecoder_kq;
  B_ProtocolDecoder_EV_SLAC_T ProtocolDecoder_k;
  B_ProtocolEncoder_EV_SLAC_T ProtocolEncoder;
  B_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy_EV_SLAC_T
    V2GTCP_IP_LOOPLOOP_ACTIVEFunctionOutStandy;
  B_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy_EV_SLAC_T
    V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_n5;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_bk;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_bj;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_af;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_bq;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_bi;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_kb;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_jo;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_ia;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_lo;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_bx;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_la;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_oc;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_eo;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_dn;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_i3;
  B_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_EV_SLAC_T
    V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_ne;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_iqd;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_e0;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_b0;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_mf;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_jy;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_n1;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_do;
  B_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_EV_SLAC_T
    V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_em;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_oh;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_i0;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_mk;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_b5k;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_ok;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_k;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_ad;
  B_EnabledSubsystem_EV_SLAC_T EnabledSubsystem_p;
  B_EnabledSubsystem_EV_SLAC_T EnabledSubsystem;
  B_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_EV_SLAC_T
    V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_jn;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_o0;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_gg;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_dd;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_b3;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_o5;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_ag;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_ld;
  B_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_EV_SLAC_T
    V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_cxo;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_pq;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_fv;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_ex;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_b5;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_jr;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_in;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_bc;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_f;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_l1;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_i2;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_ew;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_ln;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_m;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_lm;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_jd;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_gr;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_o;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_pu;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_a5;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_el;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_l;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_cx;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_no;
  B_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_r_T
    V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_p;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_ez;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_b;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_n;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_hf;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_g;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_iq;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_a;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_d4;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_i;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_j;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_d;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_e;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_h;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction_c;
  B_MATLABFunction_EV_SLAC_T sf_MATLABFunction;
  B_V2GLinkSetuperrorHandleTimeOutHandle_EV_SLAC_T
    V2GLinkSetuperrorHandleTimeOutHandle;
  B_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_EV_SLAC_T
    V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF;
  B_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_EV_SLAC_T
    V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ;
  B_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_EV_SL_T
    V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES;
  B_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_EV_SL_T
    V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ;
} B_EV_SLAC_T;

typedef struct {
  bitstream_t slMsgMgr_memArray_bitstream_t[6];
  bitstream_t StreamMesgOut;
  bitstream_t StreamMesgIn;
  bitstream_t StreamMesgOut_msgData;
  bitstream_t StreamMesgIn_msgData;
  bitstream_t StreamMesgOut_msgReservedData;
  bitstream_t StreamMesgIn_msgReservedData;
  matlabshared_embedded_utilities_blocks_ProtocolDecoderBlock_EV_SLAC_k_T obj;
  real_T temporalCounter_i1;
  real_T temporalCounter_i2;
  real_T previousTime;
  Msg_boolean_T Msg[3];
  Queue_boolean_T Queue[2];
  Msg_bitstream_t Msg_0[7];
  Queue_bitstream_t Queue_0[2];
  MemPool_bitstream_t slMsgMgr_MemPool_bitstream_t;
  bitstream_t* slMsgMgr_freeList_bitstream_t[6];
  void* StreamMesgOut_msgInterface;
  void* StreamMesgOut_msgHandle;
  void* StreamMesgOut_msgDataPtr;
  void* StreamMesgIn_msgInterface;
  void* StreamMesgIn_msgHandle;
  void* StreamMesgIn_msgDataPtr;
  void* ActiveTcpLoop_msgInterface;
  void* ActiveTcpLoop_msgHandle;
  void* ActiveTcpLoop_msgDataPtr;
  void* TCP_IP_LostConnect_msgInterface;
  void* TCP_IP_LostConnect_msgHandle;
  void* TCP_IP_LostConnect_msgDataPtr;
  int32_T ret;
  int32_T ret2;
  int32_T StreamMesgOut_qId;
  int32_T StreamMesgIn_qId;
  int32_T ActiveTcpLoop_qId;
  int32_T TCP_IP_LostConnect_qId;
  int32_T FindNonzeroElements_DIMS1;
  uint32_T TT_match_response;
  uint32_T TP_EV_batch_msg_interval;
  uint32_T TP_EV_match_session;
  uint32_T TT_EV_atten_results;
  uint32_T TP_match_sequence;
  uint32_T TT_match_join;
  uint32_T V2G_EVCC_CommunicationSetup_Timeout;
  uint32_T PowerDeliveryReq_Timeout;
  uint32_T ServiceDiscoveryReq_Timeout;
  uint32_T AuthorizationReq_Timeout;
  uint32_T ChargeParameterDiscoveryReq_Timeout;
  uint32_T PaymentServiceSelectionReq_Timeout;
  uint32_T CableCheckReq_Timeout;
  uint32_T PreChargeReq_Timeout;
  uint32_T V2G_EVCC_Ongoing_Timeout;
  uint32_T exitPortIndex;
  uint32_T exitPortIndex_d;
  uint32_T exitPortIndex_p;
  uint32_T exitPortIndex_a;
  uint32_T exitPortIndex_k;
  uint32_T exitPortIndex_f;
  uint32_T exitPortIndex_fu;
  uint32_T exitPortIndex_a1;
  uint32_T exitPortIndex_n;
  uint32_T exitPortIndex_h;
  uint32_T exitPortIndex_kz;
  uint32_T exitPortIndex_g;
  uint32_T exitPortIndex_hq;
  uint32_T exitPortIndex_gq;
  uint32_T exitPortIndex_ap;
  uint32_T exitPortIndex_o;
  uint32_T exitPortIndex_ht;
  uint32_T exitPortIndex_b;
  uint32_T exitPortIndex_kw;
  uint32_T exitPortIndex_ha;
  uint32_T exitPortIndex_fv;
  uint32_T exitPortIndex_h4;
  uint32_T state;
  uint32_T state_a[2];
  uint32_T state_c[625];
  uint32_T method;
  uint32_T method_h;
  uint32_T state_g[625];
  uint32_T state_f[2];
  uint32_T seed;
  uint8_T StartAttenCnt;
  uint8_T SdpResend;
  uint8_T is_active_c1_EV_SLAC;
  uint8_T is_LinkSetup;
  uint8_T is_BLOCK;
  uint8_T is_Hansharking;
  uint8_T is_SDP;
  uint8_T is_V2G2_016_IP_ADD_ASSIGMENT;
  uint8_T is_V2G2_019_V2G2_645_SECC_DISCOVERY;
  uint8_T is_SESSION_SETUP;
  uint8_T is_TCP_TLS_CONNECTION_EST;
  uint8_T is_SLAC;
  uint8_T is_MATCHED;
  uint8_T is_JOIN_NETWORK;
  uint8_T is_MATCHING;
  uint8_T is_CHECK_COMPATABLE;
  uint8_T is_DESISION;
  uint8_T is_SOUDING_SEQ;
  uint8_T is_VALIDATE;
  uint8_T is_Slac_param;
  uint8_T is_V2G_SEQ;
  uint8_T is_AUTHORIZATION;
  uint8_T is_BLOCK_p;
  uint8_T is_CABLE_CHECK;
  uint8_T is_BLOCK_j;
  uint8_T is_PARAMETER_DISCOVERY;
  uint8_T is_BLOCK_f;
  uint8_T is_PAYMENT_SELECTION;
  uint8_T is_BLOCK_g;
  uint8_T is_POWER_DELIVERY;
  uint8_T is_BLOCK_o;
  uint8_T is_PRE_CHARGE;
  uint8_T is_BLOCK_h;
  uint8_T is_SERVICE_DETAIL;
  uint8_T is_SERVICE_DISCOVERY;
  uint8_T is_REQ_BLOCK;
  uint8_T is_TCP_IP_LOOP;
  uint8_T is_LOOP_ACTIVE;
  boolean_T ActiveTcpLoop;
  boolean_T TCP_IP_LostConnect;
  boolean_T StreamMesgIn_isValid;
  boolean_T TCP_IP_LostConnect_isValid;
  boolean_T ActiveTcpLoop_msgData;
  boolean_T TCP_IP_LostConnect_msgData;
  boolean_T ActiveTcpLoop_msgReservedData;
  boolean_T TCP_IP_LostConnect_msgReservedData;
  boolean_T state_not_empty_n;
  boolean_T seed_not_empty;
  DW_ProtocolEncoder_EV_SLAC_T ProtocolEncoder_k;
  DW_ProtocolDecoder_EV_SLAC_T ProtocolDecoder_kq;
  DW_ProtocolDecoder_EV_SLAC_T ProtocolDecoder_k;
  DW_ProtocolEncoder_EV_SLAC_T ProtocolEncoder;
  DW_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp__T
    V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req;
} DW_EV_SLAC_T;

typedef struct {
  iso1EXIDocument ExiDoc_Buff;
  EVCC_CONFIG EVCC_CONFIG_SET;
  MESSAGE global_message;
  EVSE_PAIRING EVSE_PAIRING_SET;
  session_t global_session;
  channel_t global_channel;
  SdpMesgResT sdpMesg_res;
  int16_T errorNo;
  uint16_T connStream;
  int8_T TCP_recvStatus;
  uint8_T UDP_PORT[256];
  uint8_T Buffer_received[30];
} SharedDSM_EV_SLAC_T;

typedef struct {
  const real_T Width;
} ConstB_V2GLinkSetupSLACSlac_paraminscreseRunID_EV_SLAC_T;

typedef struct {
  const int32_T Width;
} ConstB_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERY_T;

typedef struct {
  const real_T Width;
  const uint32_T Width_m;
  const uint16_T Width1;
  ConstB_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERY_T
    V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req;
  ConstB_V2GLinkSetupSLACSlac_paraminscreseRunID_EV_SLAC_T
    V2GLinkSetupSLACSlac_paraminscreseRunID;
} ConstB_EV_SLAC_T;

struct P_V2GLinkSetupSLACSlac_paraminscreseRunID_EV_SLAC_T_ {
  int32_T ret_Y0;
};

struct
  P_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_EV_SL_T_
{
  int32_T ret_Y0;
};

struct
  P_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_EV_SL_T_
{
  int32_T ret_Y0;
};

struct
  P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_EV_SLAC_T_ {
  int32_T ret_Y0;
  real32_T TP_EV_vald_toggle_Value;
  uint8_T Gain_Gain;
};

struct
  P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_EV_SLAC_T_ {
  int32_T ret_Y0;
  uint8_T C_EV_vald_nb_toggles_Value;
};

struct P_V2GLinkSetuperrorHandleTimeOutHandle_EV_SLAC_T_ {
  int32_T Constant_Value;
  int32_T CCaller_status;
};

struct
  P_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_r_T_
{
  int32_T ret_Y0;
  uint32_T Constant2_Value;
  uint8_T Constant4_Value;
  uint8_T Constant5_Value;
};

struct P_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_EV_SLAC_T_ {
  bitstream_t Constant13_Value;
  iso1AuthorizationReqType Constant5_Value;
  int32_T ret_Y0;
  int32_T CCaller_status;
  uint16_T Constant11_Value;
  uint8_T Constant10_Value;
  uint8_T Constant2_Value;
  uint8_T Constant4_Value;
};

struct
  P_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_EV_SLAC_T_
{
  iso1DC_EVErrorCodeType EnumeratedConstant6_Value;
  iso1EnergyTransferModeType EnumeratedConstant_Value;
  iso1unitSymbolType EnumeratedConstant5_Value;
  iso1unitSymbolType EnumeratedConstant4_Value;
  iso1unitSymbolType EnumeratedConstant3_Value;
  iso1unitSymbolType EnumeratedConstant1_Value;
  iso1unitSymbolType EnumeratedConstant2_Value;
  bitstream_t Constant32_Value;
  iso1ChargeParameterDiscoveryReqType Constant5_Value;
  iso1DC_EVChargeParameterType Constant8_Value;
  iso1DC_EVStatusType Constant29_Value;
  iso1PhysicalValueType Constant26_Value;
  iso1PhysicalValueType Constant23_Value;
  iso1PhysicalValueType Constant20_Value;
  iso1PhysicalValueType Constant12_Value;
  iso1PhysicalValueType Constant16_Value;
  int32_T ret_Y0;
  int32_T CCaller_status;
  uint32_T Constant10_Value;
  uint32_T Constant31_Value;
  uint32_T Constant28_Value;
  uint32_T Constant27_Value;
  uint32_T Constant25_Value;
  uint32_T Constant24_Value;
  uint32_T Constant22_Value;
  uint32_T Constant21_Value;
  uint32_T Constant14_Value;
  uint32_T Constant13_Value;
  uint32_T Constant18_Value;
  uint32_T Constant17_Value;
  uint16_T Constant7_Value;
  boolean_T Constant30_Value;
  uint8_T Constant6_Value;
  uint8_T Constant4_Value;
  uint8_T Constant33_Value;
  uint8_T Constant_Value;
  uint8_T Constant2_Value;
  uint8_T Constant1_Value;
  uint8_T Constant9_Value;
  uint8_T Constant11_Value;
  uint8_T Constant15_Value;
  uint8_T Constant19_Value;
  uint8_T Constant3_Value;
};

struct P_EnabledSubsystem_EV_SLAC_T_ {
  real32_T Out1_Y0;
  real32_T TimePoint_Y0;
};

struct P_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_EV_SLAC_T_ {
  iso1DC_EVErrorCodeType EnumeratedConstant6_Value;
  bitstream_t Constant13_Value;
  iso1CableCheckReqType Constant5_Value;
  iso1DC_EVStatusType Constant29_Value;
  int32_T ret_Y0;
  int32_T CCaller_status;
  uint32_T Constant31_Value;
  uint16_T Constant11_Value;
  boolean_T Constant30_Value;
  uint8_T Constant10_Value;
  uint8_T Constant1_Value;
  uint8_T Constant4_Value;
};

struct P_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_EV_SLAC_T_ {
  iso1DC_EVErrorCodeType EnumeratedConstant6_Value;
  iso1unitSymbolType EnumeratedConstant3_Value;
  iso1unitSymbolType EnumeratedConstant5_Value;
  bitstream_t Constant13_Value;
  iso1PreChargeReqType Constant5_Value;
  iso1DC_EVStatusType Constant29_Value;
  iso1PhysicalValueType Constant20_Value;
  iso1PhysicalValueType Constant26_Value;
  int32_T ret_Y0;
  int32_T CCaller_status;
  uint32_T Constant31_Value;
  uint32_T Constant22_Value;
  uint32_T Constant21_Value;
  uint32_T Constant28_Value;
  uint32_T Constant27_Value;
  uint16_T Constant11_Value;
  boolean_T Constant30_Value;
  uint8_T Constant10_Value;
  uint8_T Constant1_Value;
  uint8_T Constant4_Value;
};

struct P_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy_EV_SLAC_T_ {
  char_T StringConstant1_String[256];
  int32_T CCaller_status;
};

struct P_EV_SLAC_T_ {
  NetInputOrOutput EnumeratedConstant_Value;
  appHandresponeType EnumeratedConstant1_Value;
  appHandresponeType EnumeratedConstant_Value_i;
  int32_T CompareToConstant_const;
  iso1DC_EVSEStatusCodeType EnumeratedConstant6_Value;
  iso1DC_EVSEStatusCodeType EnumeratedConstant9_Value;
  iso1DC_EVSEStatusCodeType EnumeratedConstant6_Value_m;
  iso1DC_EVSEStatusCodeType EnumeratedConstant6_Value_p;
  iso1EVSENotificationType EnumeratedConstant4_Value;
  iso1EVSENotificationType EnumeratedConstant4_Value_g;
  iso1EVSENotificationType EnumeratedConstant7_Value;
  iso1EVSENotificationType EnumeratedConstant4_Value_b;
  iso1EVSENotificationType EnumeratedConstant4_Value_h;
  iso1EVSEProcessingType EnumeratedConstant2_Value;
  iso1EVSEProcessingType EnumeratedConstant3_Value;
  iso1EVSEProcessingType EnumeratedConstant3_Value_h;
  iso1EVSEProcessingType EnumeratedConstant2_Value_i;
  iso1EVSEProcessingType EnumeratedConstant2_Value_c;
  iso1EVSEProcessingType EnumeratedConstant3_Value_j;
  iso1chargeProgressType EnumeratedConstant_Value_g;
  iso1isolationLevelType EnumeratedConstant5_Value;
  iso1isolationLevelType EnumeratedConstant8_Value;
  iso1isolationLevelType EnumeratedConstant5_Value_k;
  iso1isolationLevelType EnumeratedConstant5_Value_b;
  iso1paymentOptionType EnumeratedConstant_Value_d;
  iso1responseCodeType EnumeratedConstant1_Value_n;
  iso1responseCodeType EnumeratedConstant_Value_f;
  iso1responseCodeType EnumeratedConstant1_Value_n4;
  iso1responseCodeType EnumeratedConstant1_Value_nm;
  iso1responseCodeType EnumeratedConstant1_Value_m;
  iso1responseCodeType EnumeratedConstant1_Value_p;
  iso1responseCodeType EnumeratedConstant1_Value_i;
  iso1responseCodeType EnumeratedConstant1_Value_g;
  iso1responseCodeType EnumeratedConstant1_Value_f;
  iso1serviceCategoryType EnumeratedConstant_Value_o;
  int16_T CompareToConstant_const_j;
  int16_T CompareToConstant1_const;
  int16_T CompareToConstant_const_l;
  boolean_T CompareToConstant1_const_d;
  int8_T CompareToConstant_const_m;
  int8_T CompareToConstant2_const;
  int8_T CompareToConstant1_const_k;
  uint8_T CompareToConstant1_const_j;
  uint8_T CompareToConstant_const_o;
  uint8_T CompareToConstant1_const_c;
  uint8_T CompareToConstant_const_d;
  uint8_T CompareToConstant1_const_cx;
  uint8_T CompareToConstant_const_i;
  uint8_T CompareToConstant1_const_f;
  uint8_T CompareToConstant_const_a;
  uint8_T CompareToConstant1_const_cg;
  uint8_T CompareToConstant_const_ld;
  uint8_T CompareToConstant1_const_h;
  uint8_T CompareToConstant_const_lv;
  uint8_T CompareToConstant1_const_hl;
  uint8_T CompareToConstant_const_e;
  uint8_T CompareToConstant1_const_m;
  uint8_T CompareToConstant_const_a4;
  iso1EXIDocument DataStoreMemory8_InitialValue;
  EVCC_CONFIG DataStoreMemory10_InitialValue;
  bitstream_t Constant13_Value;
  bitstream_t Constant6_Value;
  bitstream_t Constant13_Value_g;
  bitstream_t Constant13_Value_l;
  bitstream_t Constant13_Value_c;
  bitstream_t msgRecv_Y0;
  bitstream_t Constant3_Value;
  bitstream_t StreamIn_Y0;
  bitstream_t Constant3_Value_e;
  appHandEXIDocument Constant8_Value;
  appHandEXIDocument Constant14_Value;
  MESSAGE DataStoreMemory4_InitialValue;
  iso1PowerDeliveryReqType Constant5_Value;
  EVSE_PAIRING DataStoreMemory11_InitialValue;
  appHandAppProtocolType Constant6_Value_k;
  appHandAppProtocolType Constant7_Value;
  iso1ServiceDiscoveryReqType Constant5_Value_j;
  session_t DataStoreMemory2_InitialValue;
  iso1PaymentServiceSelectionReqType Constant5_Value_l;
  channel_t Constant_Value;
  channel_t DataStoreMemory3_InitialValue;
  SdpMesgResT DataStoreMemory7_InitialValue;
  iso1SelectedServiceType Constant1_Value;
  iso1SessionSetupReqType Constant5_Value_c;
  char_T StringConstant_String[256];
  char_T StringConstant_String_e[256];
  char_T StringConstant1_String[256];
  char_T StringConstant_String_ec[256];
  char_T StringConstant2_String[256];
  char_T StringConstant_String_h[256];
  char_T StringConstant1_String_g[256];
  int32_T ret_Y0;
  int32_T Constant_Value_f;
  int32_T Constant_Value_f5;
  int32_T ret_Y0_l;
  int32_T ret_Y0_lz;
  int32_T ret_Y0_i;
  int32_T ret_Y0_l1;
  int32_T ret_Y0_i5;
  int32_T ret_Y0_h;
  int32_T Constant2_Value;
  int32_T ret_Y0_b;
  int32_T CCaller_status;
  int32_T ret_Y0_d;
  int32_T ret_Y0_n;
  int32_T ret_Y0_o;
  int32_T ret_Y0_k;
  int32_T ret_Y0_bq;
  int32_T Constant4_Value;
  int32_T ret_Y0_m;
  int32_T Constant6_Value_p;
  int32_T CCaller_status_i;
  int32_T ret_Y0_im;
  int32_T ret_Y0_j;
  int32_T CCaller_status_h;
  int32_T ret_Y0_jb;
  int32_T Constant_Value_h;
  int32_T CCaller_status_hs;
  int32_T ret_Y0_h5;
  int32_T CCaller_status_m;
  int32_T ret_Y0_f;
  int32_T Constant_Value_p;
  int32_T Constant_Value_g;
  int32_T CCaller1_status;
  int32_T ret_Y0_g;
  int32_T CCaller_status_f;
  int32_T ret_Y0_a;
  int32_T Constant_Value_j;
  int32_T Constant_Value_i;
  int32_T CCaller1_status_l;
  int32_T ret_Y0_ih;
  int32_T CCaller_status_hf;
  int32_T ret_Y0_nx;
  int32_T Constant_Value_l;
  int32_T Constant_Value_ll;
  int32_T CCaller1_status_g;
  int32_T Constant_Value_fp;
  int32_T ret_Y0_dp;
  int32_T Constant_Value_d;
  int32_T Constant_Value_in;
  int32_T CCaller1_status_n;
  int32_T Constant_Value_m;
  int32_T Constant1_Value_k;
  int32_T ret_Y0_mv;
  int32_T Constant_Value_fr;
  int32_T Constant_Value_my;
  int32_T CCaller1_status_c;
  int32_T Constant_Value_e;
  int32_T ret_Y0_di;
  int32_T Constant_Value_ep;
  int32_T Constant_Value_pq;
  int32_T CCaller1_status_n2;
  int32_T ret_Y0_c;
  int32_T Constant_Value_k;
  int32_T Constant_Value_a;
  int32_T CCaller1_status_d;
  int32_T ret_Y0_bf;
  int32_T CCaller_status_fu;
  int32_T ret_Y0_nf;
  int32_T Constant_Value_kb;
  int32_T Constant_Value_df;
  int32_T CCaller1_status_p;
  int32_T Constant1_Value_i;
  int32_T Constant_Value_dd;
  int32_T ret_Y0_hp;
  int32_T Constant1_Value_kg;
  int32_T Constant_Value_fv;
  int32_T recvStatus_Y0;
  int32_T Constant3_Value_o;
  int32_T Constant_Value_gi;
  int32_T ret_Y0_bt;
  int32_T ret_Y0_ihw;
  int32_T ret_Y0_ok;
  real32_T timeout_Value;
  real32_T TimeArray_Y0;
  real32_T PmaxArray_out_Y0;
  real32_T TimeArray_Y0_d;
  real32_T EpriceArray_out_Y0;
  real32_T PmaxSchedule_Y0;
  real32_T TimePointSchedule_Y0;
  real32_T EpriceScheduleList_Y0;
  real32_T TimePointSchedule_Eprice_Y0;
  uint32_T Constant_Value_js;
  uint32_T Constant2_Value_j;
  uint32_T Constant3_Value_p;
  uint32_T HeaderSize_Value;
  uint32_T Constant2_Value_m;
  uint32_T Constant2_Value_n;
  uint32_T Constant_Value_pt;
  int16_T errorNo_Y0;
  int16_T DataStoreMemory1_InitialValue;
  uint16_T Constant4_Value_f;
  uint16_T clientPort_Value;
  uint16_T clientPort_Value_h;
  uint16_T CCaller_server;
  uint16_T Constant11_Value;
  uint16_T Constant1_Value_m;
  uint16_T Constant_Value_eu;
  uint16_T Constant1_Value_a;
  uint16_T Constant11_Value_h;
  uint16_T Constant_Value_b;
  uint16_T Constant11_Value_l;
  uint16_T Saturation1_UpperSat;
  uint16_T Saturation1_LowerSat;
  uint16_T SAScheduleTupleID_Y0;
  uint16_T Saturation_UpperSat;
  uint16_T Saturation_LowerSat;
  uint16_T Saturation_UpperSat_c;
  uint16_T Saturation_LowerSat_d;
  uint16_T Constant11_Value_b;
  uint16_T Constant_Value_mu;
  uint16_T CCaller_isSer;
  uint16_T PDU_Read_isSer;
  uint16_T HeaderReceive_isSer;
  uint16_T HeaderRead_isSer;
  uint16_T PDU_Read_isSer_m;
  uint16_T CCaller_isSer_o;
  uint16_T DataStoreMemory_InitialValue;
  boolean_T Constant1_Value_f;
  boolean_T Constant2_Value_c;
  boolean_T Constant1_Value_b;
  boolean_T Constant1_Value_ba;
  int8_T recvStatus_Y0_i;
  int8_T DataStoreMemory9_InitialValue;
  uint8_T Constant1_Value_a4;
  uint8_T Constant2_Value_g;
  uint8_T Constant3_Value_k[6];
  uint8_T Constant5_Value_h;
  uint8_T Constant6_Value_n;
  uint8_T Constant5_Value_g[2];
  uint8_T Constant7_Value_o[17];
  uint8_T Constant_Value_inb;
  uint8_T Constant1_Value_kf;
  uint8_T Constant2_Value_l;
  uint8_T Constant3_Value_oe;
  uint8_T Constant4_Value_d;
  byte_t Saturation_UpperSat_f;
  byte_t Saturation_LowerSat_dw;
  uint8_T Constant5_Value_b[256];
  uint8_T Constant_Value_l5;
  uint8_T Constant1_Value_o;
  uint8_T Constant2_Value_b;
  uint8_T Constant3_Value_l;
  uint8_T Constant4_Value_i;
  uint8_T Constant5_Value_d;
  uint8_T Constant10_Value;
  uint8_T Constant3_Value_a;
  uint8_T Constant2_Value_a;
  uint8_T Constant7_Value_e[8];
  uint8_T Constant8_Value_j;
  uint8_T Constant10_Value_e;
  uint8_T Constant1_Value_n;
  uint8_T Constant4_Value_o;
  uint8_T Constant_Value_en;
  uint8_T Constant10_Value_en;
  uint8_T Constant3_Value_h;
  uint8_T Constant4_Value_dm;
  uint8_T Constant2_Value_c5;
  uint8_T Constant_Value_g2;
  uint8_T Constant_Value_dl;
  uint8_T Constant_Value_mf;
  uint8_T Constant_Value_jx;
  uint8_T Constant_Value_eh;
  uint8_T Constant_Value_o;
  uint8_T Constant10_Value_d;
  uint8_T Constant1_Value_fu;
  uint8_T Constant4_Value_or;
  uint8_T Constant_Value_hx;
  uint8_T Constant_Value_jj[4096];
  uint8_T Constant1_Value_ml[8];
  uint8_T Constant1_Value_bb[8];
  uint8_T Constant_Value_hr[4096];
  uint8_T DataStoreMemory5_InitialValue;
  uint8_T DataStoreMemory6_InitialValue;
  P_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy_EV_SLAC_T
    V2GTCP_IP_LOOPLOOP_ACTIVEFunctionOutStandy;
  P_V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy_EV_SLAC_T
    V2GTCP_IP_LOOPLOOP_ACTIVEFunctionInStandy;
  P_V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq_EV_SLAC_T
    V2GLinkSetupV2G_SEQPRE_CHARGEBLOCKPreChargeReq;
  P_V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq_EV_SLAC_T
    V2GLinkSetupV2G_SEQCABLE_CHECKBLOCKCableCheckReq;
  P_EnabledSubsystem_EV_SLAC_T EnabledSubsystem_p;
  P_EnabledSubsystem_EV_SLAC_T EnabledSubsystem;
  P_V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq_EV_SLAC_T
    V2GLinkSetupV2G_SEQPARAMETER_DISCOVERYBLOCKChargeParaDiscoveryReq;
  P_V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq_EV_SLAC_T
    V2GLinkSetupV2G_SEQAUTHORIZATIONBLOCKAuthorizationReq;
  P_V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_r_T
    V2GLinkSetupCOMMUNICATION_SETUPBLOCKSDPV2G2_019_V2G2_645_SECC_DISCOVERYSdp_req;
  P_V2GLinkSetuperrorHandleTimeOutHandle_EV_SLAC_T
    V2GLinkSetuperrorHandleTimeOutHandle;
  P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF_EV_SLAC_T
    V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateCNF;
  P_V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ_EV_SLAC_T
    V2GLinkSetupSLACMATCHINGVALIDATEpev_cm_validate_SecondStateREQ;
  P_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES_EV_SL_T
    V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_RES;
  P_V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ_EV_SL_T
    V2GLinkSetupSLACMATCHINGCHECK_COMPATABLEpev_cm_validate_FisrtState_REQ;
  P_V2GLinkSetupSLACSlac_paraminscreseRunID_EV_SLAC_T
    V2GLinkSetupSLACSlac_paraminscreseRunID;
};

typedef struct Slac_timing_constant_tag {
  uint32_T TP_EV_batch_msg_interval;
  uint32_T TP_EV_match_session;
  uint32_T TP_match_sequence;
  uint32_T TT_EV_atten_results;
  uint32_T TT_match_join;
  uint32_T TT_match_response;
  uint32_T V2G_EVCC_CommunicationSetup_Timeout;
} Slac_timing_constant_type;

typedef struct V2G_EVCC_Msg_Timeout_tag {
  uint32_T AuthorizationReq_Timeout;
  uint32_T CableCheckReq_Timeout;
  uint32_T ChargeParameterDiscoveryReq_Timeout;
  uint32_T PaymentServiceSelectionReq_Timeout;
  uint32_T PowerDeliveryReq_Timeout;
  uint32_T PreChargeReq_Timeout;
  uint32_T ServiceDiscoveryReq_Timeout;
} V2G_EVCC_Msg_Timeout_type;

typedef struct rt_Simulink_Struct_tag {
  uint32_T V2G_EVCC_Ongoing_Timeout;
} rt_Simulink_Struct_type;

struct tag_RTM_EV_SLAC_T {
  struct {
    uint32_T clockTick0;
    uint32_T clockTick1;
  } Timing;
};

extern P_EV_SLAC_T EV_SLAC_P;
extern B_EV_SLAC_T EV_SLAC_B;
extern DW_EV_SLAC_T EV_SLAC_DW;
extern SharedDSM_EV_SLAC_T EV_SLAC_SharedDSM;
extern const ConstB_EV_SLAC_T EV_SLAC_ConstB;
extern SdpMesgResT sdpMesg_res_bus;
extern void EV_SLAC_initialize(void);
extern void EV_SLAC_step(void);
extern void EV_SLAC_terminate(void);
extern Slac_timing_constant_type Slac_timing_constant;
extern V2G_EVCC_Msg_Timeout_type V2G_EVCC_Msg_Timeout;
extern rt_Simulink_Struct_type rt_Simulink_Struct;
extern RT_MODEL_EV_SLAC_T *const EV_SLAC_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#endif

