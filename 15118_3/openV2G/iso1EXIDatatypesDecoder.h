/*
 * Copyright (C) 2007-2018 Siemens AG
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

 /*******************************************************************
  *
  * @author Daniel.Peintner.EXT@siemens.com
  * @version 0.9.4
  * @contact Richard.Kuntschke@siemens.com
  *
  * <p>Code generated by EXIdizer</p>
  * <p>Schema: V2G_CI_MsgDef.xsd</p>
  *
  *
  ********************************************************************/



  /**
   * \file 	EXIDatatypesDecoder.h
   * \brief 	Decoder for datatype definitions
   *
   */

#ifndef EXI_iso1_DATATYPES_DECODER_H
#define EXI_iso1_DATATYPES_DECODER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "iso1EXIDatatypes.h"

#if DEPLOY_ISO1_CODEC == SUPPORT_YES

#include <stdint.h>

#include "EXITypes.h"

    int decode_iso1ExiDocument(bitstream_t* stream, struct iso1EXIDocument* exiDoc);
    int decode_iso1MessageHeaderType(bitstream_t* stream, struct iso1MessageHeaderType* iso1MessageHeaderType);
    int decode_iso1SignatureType(bitstream_t* stream, struct iso1SignatureType* iso1SignatureType);
    int decode_iso1PowerDeliveryReqType(bitstream_t* stream, struct iso1PowerDeliveryReqType* iso1PowerDeliveryReqType);
    int decode_iso1ParameterType(bitstream_t* stream, struct iso1ParameterType* iso1ParameterType);
    int decode_iso1CertificateInstallationReqType(bitstream_t* stream, struct iso1CertificateInstallationReqType* iso1CertificateInstallationReqType);
    int decode_iso1SessionSetupResType(bitstream_t* stream, struct iso1SessionSetupResType* iso1SessionSetupResType);
    int decode_iso1EVChargeParameterType(bitstream_t* stream, struct iso1EVChargeParameterType* iso1EVChargeParameterType);
    int decode_iso1DiffieHellmanPublickeyType(bitstream_t* stream, struct iso1DiffieHellmanPublickeyType* iso1DiffieHellmanPublickeyType);
    int decode_iso1ServiceDiscoveryResType(bitstream_t* stream, struct iso1ServiceDiscoveryResType* iso1ServiceDiscoveryResType);
    int decode_iso1ServiceParameterListType(bitstream_t* stream, struct iso1ServiceParameterListType* iso1ServiceParameterListType);
    int decode_iso1CertificateChainType(bitstream_t* stream, struct iso1CertificateChainType* iso1CertificateChainType);
    int decode_iso1SASchedulesType(bitstream_t* stream, struct iso1SASchedulesType* iso1SASchedulesType);
    int decode_iso1DC_EVSEStatusType(bitstream_t* stream, struct iso1DC_EVSEStatusType* iso1DC_EVSEStatusType);
    int decode_iso1PreChargeResType(bitstream_t* stream, struct iso1PreChargeResType* iso1PreChargeResType);
    int decode_iso1ParameterSetType(bitstream_t* stream, struct iso1ParameterSetType* iso1ParameterSetType);
    int decode_iso1ServiceDetailReqType(bitstream_t* stream, struct iso1ServiceDetailReqType* iso1ServiceDetailReqType);
    int decode_iso1RelativeTimeIntervalType(bitstream_t* stream, struct iso1RelativeTimeIntervalType* iso1RelativeTimeIntervalType);
    int decode_iso1SignedInfoType(bitstream_t* stream, struct iso1SignedInfoType* iso1SignedInfoType);
    int decode_iso1EMAIDType(bitstream_t* stream, struct iso1EMAIDType* iso1EMAIDType);
    int decode_iso1EVStatusType(bitstream_t* stream, struct iso1EVStatusType* iso1EVStatusType);
    int decode_iso1ServiceListType(bitstream_t* stream, struct iso1ServiceListType* iso1ServiceListType);
    int decode_iso1EVSEChargeParameterType(bitstream_t* stream, struct iso1EVSEChargeParameterType* iso1EVSEChargeParameterType);
    int decode_iso1EVPowerDeliveryParameterType(bitstream_t* stream, struct iso1EVPowerDeliveryParameterType* iso1EVPowerDeliveryParameterType);
    int decode_iso1ProfileEntryType(bitstream_t* stream, struct iso1ProfileEntryType* iso1ProfileEntryType);
    int decode_iso1AuthorizationReqType(bitstream_t* stream, struct iso1AuthorizationReqType* iso1AuthorizationReqType);
    int decode_iso1MeterInfoType(bitstream_t* stream, struct iso1MeterInfoType* iso1MeterInfoType);
    int decode_iso1ManifestType(bitstream_t* stream, struct iso1ManifestType* iso1ManifestType);
    int decode_iso1ChargeParameterDiscoveryResType(bitstream_t* stream, struct iso1ChargeParameterDiscoveryResType* iso1ChargeParameterDiscoveryResType);
    int decode_iso1PowerDeliveryResType(bitstream_t* stream, struct iso1PowerDeliveryResType* iso1PowerDeliveryResType);
    int decode_iso1DC_EVChargeParameterType(bitstream_t* stream, struct iso1DC_EVChargeParameterType* iso1DC_EVChargeParameterType);
    int decode_iso1ConsumptionCostType(bitstream_t* stream, struct iso1ConsumptionCostType* iso1ConsumptionCostType);
    int decode_iso1PMaxScheduleType(bitstream_t* stream, struct iso1PMaxScheduleType* iso1PMaxScheduleType);
    int decode_iso1PaymentOptionListType(bitstream_t* stream, struct iso1PaymentOptionListType* iso1PaymentOptionListType);
    int decode_iso1ObjectType(bitstream_t* stream, struct iso1ObjectType* iso1ObjectType);
    int decode_iso1PhysicalValueType(bitstream_t* stream, struct iso1PhysicalValueType* iso1PhysicalValueType);
    int decode_iso1RSAKeyValueType(bitstream_t* stream, struct iso1RSAKeyValueType* iso1RSAKeyValueType);
    int decode_iso1SessionStopResType(bitstream_t* stream, struct iso1SessionStopResType* iso1SessionStopResType);
    int decode_iso1CertificateUpdateReqType(bitstream_t* stream, struct iso1CertificateUpdateReqType* iso1CertificateUpdateReqType);
    int decode_iso1SignatureValueType(bitstream_t* stream, struct iso1SignatureValueType* iso1SignatureValueType);
    int decode_iso1PaymentDetailsReqType(bitstream_t* stream, struct iso1PaymentDetailsReqType* iso1PaymentDetailsReqType);
    int decode_iso1AuthorizationResType(bitstream_t* stream, struct iso1AuthorizationResType* iso1AuthorizationResType);
    int decode_iso1DC_EVSEChargeParameterType(bitstream_t* stream, struct iso1DC_EVSEChargeParameterType* iso1DC_EVSEChargeParameterType);
    int decode_iso1SubCertificatesType(bitstream_t* stream, struct iso1SubCertificatesType* iso1SubCertificatesType);
    int decode_iso1ChargingStatusResType(bitstream_t* stream, struct iso1ChargingStatusResType* iso1ChargingStatusResType);
    int decode_iso1DSAKeyValueType(bitstream_t* stream, struct iso1DSAKeyValueType* iso1DSAKeyValueType);
    int decode_iso1ListOfRootCertificateIDsType(bitstream_t* stream, struct iso1ListOfRootCertificateIDsType* iso1ListOfRootCertificateIDsType);
    int decode_iso1ChargeServiceType(bitstream_t* stream, struct iso1ChargeServiceType* iso1ChargeServiceType);
    int decode_iso1IntervalType(bitstream_t* stream, struct iso1IntervalType* iso1IntervalType);
    int decode_iso1MeteringReceiptReqType(bitstream_t* stream, struct iso1MeteringReceiptReqType* iso1MeteringReceiptReqType);
    int decode_iso1ServiceDetailResType(bitstream_t* stream, struct iso1ServiceDetailResType* iso1ServiceDetailResType);
    int decode_iso1KeyValueType(bitstream_t* stream, struct iso1KeyValueType* iso1KeyValueType);
    int decode_iso1SelectedServiceListType(bitstream_t* stream, struct iso1SelectedServiceListType* iso1SelectedServiceListType);
    int decode_iso1CableCheckResType(bitstream_t* stream, struct iso1CableCheckResType* iso1CableCheckResType);
    int decode_iso1X509IssuerSerialType(bitstream_t* stream, struct iso1X509IssuerSerialType* iso1X509IssuerSerialType);
    int decode_iso1KeyInfoType(bitstream_t* stream, struct iso1KeyInfoType* iso1KeyInfoType);
    int decode_iso1TransformsType(bitstream_t* stream, struct iso1TransformsType* iso1TransformsType);
    int decode_iso1ChargeParameterDiscoveryReqType(bitstream_t* stream, struct iso1ChargeParameterDiscoveryReqType* iso1ChargeParameterDiscoveryReqType);
    int decode_iso1PreChargeReqType(bitstream_t* stream, struct iso1PreChargeReqType* iso1PreChargeReqType);
    int decode_iso1EVSEStatusType(bitstream_t* stream, struct iso1EVSEStatusType* iso1EVSEStatusType);
    int decode_iso1SignatureMethodType(bitstream_t* stream, struct iso1SignatureMethodType* iso1SignatureMethodType);
    int decode_iso1X509DataType(bitstream_t* stream, struct iso1X509DataType* iso1X509DataType);
    int decode_iso1NotificationType(bitstream_t* stream, struct iso1NotificationType* iso1NotificationType);
    int decode_iso1SAScheduleListType(bitstream_t* stream, struct iso1SAScheduleListType* iso1SAScheduleListType);
    int decode_iso1BodyType(bitstream_t* stream, struct iso1BodyType* iso1BodyType);
    int decode_iso1ChargingProfileType(bitstream_t* stream, struct iso1ChargingProfileType* iso1ChargingProfileType);
    int decode_iso1TransformType(bitstream_t* stream, struct iso1TransformType* iso1TransformType);
    int decode_iso1SAScheduleTupleType(bitstream_t* stream, struct iso1SAScheduleTupleType* iso1SAScheduleTupleType);
    int decode_iso1AC_EVChargeParameterType(bitstream_t* stream, struct iso1AC_EVChargeParameterType* iso1AC_EVChargeParameterType);
    int decode_iso1AnonType_V2G_Message(bitstream_t* stream, struct iso1AnonType_V2G_Message* iso1AnonType_V2G_Message);
    int decode_iso1PaymentDetailsResType(bitstream_t* stream, struct iso1PaymentDetailsResType* iso1PaymentDetailsResType);
    int decode_iso1ContractSignatureEncryptedPrivateKeyType(bitstream_t* stream, struct iso1ContractSignatureEncryptedPrivateKeyType* iso1ContractSignatureEncryptedPrivateKeyType);
    int decode_iso1PMaxScheduleEntryType(bitstream_t* stream, struct iso1PMaxScheduleEntryType* iso1PMaxScheduleEntryType);
    int decode_iso1SPKIDataType(bitstream_t* stream, struct iso1SPKIDataType* iso1SPKIDataType);
    int decode_iso1MeteringReceiptResType(bitstream_t* stream, struct iso1MeteringReceiptResType* iso1MeteringReceiptResType);
    int decode_iso1SessionStopReqType(bitstream_t* stream, struct iso1SessionStopReqType* iso1SessionStopReqType);
    int decode_iso1WeldingDetectionResType(bitstream_t* stream, struct iso1WeldingDetectionResType* iso1WeldingDetectionResType);
    int decode_iso1ReferenceType(bitstream_t* stream, struct iso1ReferenceType* iso1ReferenceType);
    int decode_iso1CurrentDemandReqType(bitstream_t* stream, struct iso1CurrentDemandReqType* iso1CurrentDemandReqType);
    int decode_iso1SalesTariffEntryType(bitstream_t* stream, struct iso1SalesTariffEntryType* iso1SalesTariffEntryType);
    int decode_iso1EntryType(bitstream_t* stream, struct iso1EntryType* iso1EntryType);
    int decode_iso1SessionSetupReqType(bitstream_t* stream, struct iso1SessionSetupReqType* iso1SessionSetupReqType);
    int decode_iso1CostType(bitstream_t* stream, struct iso1CostType* iso1CostType);
    int decode_iso1DC_EVPowerDeliveryParameterType(bitstream_t* stream, struct iso1DC_EVPowerDeliveryParameterType* iso1DC_EVPowerDeliveryParameterType);
    int decode_iso1RetrievalMethodType(bitstream_t* stream, struct iso1RetrievalMethodType* iso1RetrievalMethodType);
    int decode_iso1CertificateUpdateResType(bitstream_t* stream, struct iso1CertificateUpdateResType* iso1CertificateUpdateResType);
    int decode_iso1CertificateInstallationResType(bitstream_t* stream, struct iso1CertificateInstallationResType* iso1CertificateInstallationResType);
    int decode_iso1CanonicalizationMethodType(bitstream_t* stream, struct iso1CanonicalizationMethodType* iso1CanonicalizationMethodType);
    int decode_iso1WeldingDetectionReqType(bitstream_t* stream, struct iso1WeldingDetectionReqType* iso1WeldingDetectionReqType);
    int decode_iso1DC_EVStatusType(bitstream_t* stream, struct iso1DC_EVStatusType* iso1DC_EVStatusType);
    int decode_iso1CurrentDemandResType(bitstream_t* stream, struct iso1CurrentDemandResType* iso1CurrentDemandResType);
    int decode_iso1ServiceType(bitstream_t* stream, struct iso1ServiceType* iso1ServiceType);
    int decode_iso1ServiceDiscoveryReqType(bitstream_t* stream, struct iso1ServiceDiscoveryReqType* iso1ServiceDiscoveryReqType);
    int decode_iso1AC_EVSEChargeParameterType(bitstream_t* stream, struct iso1AC_EVSEChargeParameterType* iso1AC_EVSEChargeParameterType);
    int decode_iso1CableCheckReqType(bitstream_t* stream, struct iso1CableCheckReqType* iso1CableCheckReqType);
    int decode_iso1SelectedServiceType(bitstream_t* stream, struct iso1SelectedServiceType* iso1SelectedServiceType);
    int decode_iso1AC_EVSEStatusType(bitstream_t* stream, struct iso1AC_EVSEStatusType* iso1AC_EVSEStatusType);
    int decode_iso1SalesTariffType(bitstream_t* stream, struct iso1SalesTariffType* iso1SalesTariffType);
    int decode_iso1PaymentServiceSelectionReqType(bitstream_t* stream, struct iso1PaymentServiceSelectionReqType* iso1PaymentServiceSelectionReqType);
    int decode_iso1SignaturePropertiesType(bitstream_t* stream, struct iso1SignaturePropertiesType* iso1SignaturePropertiesType);
    int decode_iso1BodyBaseType(bitstream_t* stream, struct iso1BodyBaseType* iso1BodyBaseType);
    int decode_iso1SupportedEnergyTransferModeType(bitstream_t* stream, struct iso1SupportedEnergyTransferModeType* iso1SupportedEnergyTransferModeType);
    int decode_iso1ChargingStatusReqType(bitstream_t* stream, struct iso1ChargingStatusReqType* iso1ChargingStatusReqType);
    int decode_iso1PaymentServiceSelectionResType(bitstream_t* stream, struct iso1PaymentServiceSelectionResType* iso1PaymentServiceSelectionResType);
    int decode_iso1DigestMethodType(bitstream_t* stream, struct iso1DigestMethodType* iso1DigestMethodType);
    int decode_iso1SignaturePropertyType(bitstream_t* stream, struct iso1SignaturePropertyType* iso1SignaturePropertyType);
    int decode_iso1PGPDataType(bitstream_t* stream, struct iso1PGPDataType* iso1PGPDataType);

#if DEPLOY_ISO1_CODEC_FRAGMENT == SUPPORT_YES
    int decode_iso1ExiFragment(bitstream_t* stream, struct iso1EXIFragment* exiFrag);
#endif /* DEPLOY_ISO1_CODEC_FRAGMENT */

#endif /* DEPLOY_ISO1_CODEC */

#ifdef __cplusplus
}
#endif

#endif