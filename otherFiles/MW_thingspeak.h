/* Copyright 2014-2015 The MathWorks, Inc. */
#ifndef _MW_THINGSPEAK_H_
#define _MW_THINGSPEAK_H_
#include "rtwtypes.h"
#ifdef __cplusplus
extern "C"
{
#endif
    
#define _CURL_AVAILABLE_

typedef struct {
    char *header;
    char *dataStr;
    char *url;
    uint32_T headerSize;
    boolean_T printDiagnosticMessages;
} TSData_t;

void MW_initThingSpeak(
        const char *url,
        const char *writeAPIKey,
        const uint32_T updateInterval,
        const boolean_T printDiagnosticMessages);
uint32_T MW_getCurrentTimeInMillis(void);
TSData_t *MW_startThingSpeak(
        const char *url,
        const char *writeAPIKey,
        const boolean_T printDiagnosticMessages);
void MW_addField(TSData_t *ptr, const real_T data, const uint8_T fieldNo);
void MW_addLocation(TSData_t *ptr, const real_T *location);
void MW_addStatus(TSData_t *ptr, const char *statusMessage);
void MW_postThingSpeak(
        TSData_t *ptr,
        const char *url,
        const char *writeAPIKey,
        const boolean_T printDiagnosticMessages);

#ifdef __cplusplus
}
#endif
#endif

