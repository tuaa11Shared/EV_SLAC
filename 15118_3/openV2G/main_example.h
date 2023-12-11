#ifndef MAIN_EXAMPLE_HEADER
#define MAIN_EXAMPLE_HEADER

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include <string.h>

#include "EXITypes.h"

#include "appHandEXIDatatypes.h"
#include "appHandEXIDatatypesEncoder.h"
#include "appHandEXIDatatypesDecoder.h"
#include "EXIHeaderDecoder.h"
#include "DecoderChannel.h"



/* Activate support for DIN */
// #include "dinEXIDatatypes.h"
// #if DEPLOY_DIN_CODEC == SUPPORT_YES
// #include "dinEXIDatatypesEncoder.h"
// #include "dinEXIDatatypesDecoder.h"
// #endif /* DEPLOY_DIN_CODEC == SUPPORT_YES */

/* Activate support for XMLDSIG */
// #include "xmldsigEXIDatatypes.h"
// #if DEPLOY_XMLDSIG_CODEC == SUPPORT_YES
// #include "xmldsigEXIDatatypesEncoder.h"
// #include "xmldsigEXIDatatypesDecoder.h"
// #endif /* DEPLOY_XMLDSIG_CODEC == SUPPORT_YES */

/* Activate support for ISO1 */
#include "iso1EXIDatatypes.h"

// #if DEPLOY_ISO1_CODEC == SUPPORT_YES
#include "iso1EXIDatatypesEncoder.h"
#include "iso1EXIDatatypesDecoder.h"
// #endif /* DEPLOY_ISO1_CODEC == SUPPORT_YES */

// /* Activate support for ISO2 */
// #include "iso2EXIDatatypes.h"
// #if DEPLOY_ISO2_CODEC == SUPPORT_YES
// #include "iso2EXIDatatypesEncoder.h"
// #include "iso2EXIDatatypesDecoder.h"
// #endif /* DEPLOY_ISO2_CODEC == SUPPORT_YES */

#include "v2gtp.h"



// uint32_t deserialize1Stream2EXI_M(char* buff, struct iso1EXIDocument *exiDoc);
int decode_iso1ExiDocument(bitstream_t* stream, struct iso1EXIDocument* exiDoc);
int decode_iso1MessageHeaderType(bitstream_t* stream, struct iso1MessageHeaderType* iso1MessageHeaderType);

int appHandshakeHandler(bitstream_t* iStream, bitstream_t* oStream);
struct appHandEXIDocument appHandshake(void);
struct iso1EXIDocument deserialize1Stream2EXI_M(uint8_t* buff, uint8_t len);
uint16_t deserialize1Stream2EXI_MT(void);
int authorization1(struct iso1EXIDocument* exiIn, struct iso1EXIDocument* exiOut);
int writeStringToEXIString(char* string, exi_string_character_t* exiString);
void printASCIIString(exi_string_character_t* string, uint16_t len);
void printBinaryArray(uint8_t* byte, uint16_t len);
void copyBytes(uint8_t* from, uint16_t len, uint8_t* to);
void printEVSEStatus1(struct iso1DC_EVSEStatusType* status);


#endif /* MAIN_EXAMPLE_HEADER */
