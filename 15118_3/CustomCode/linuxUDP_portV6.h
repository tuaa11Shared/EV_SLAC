#ifndef LINUXUDP_PORTV6_HEADER
#define LINUXUDP_PORTV6_HEADER

#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct UDPsockstruct {
    int sockfd;
    struct sockaddr_in6 localsockaddr;
    struct sockaddr_in6 remotesockaddr;
    int dataTypeSize;
} UDPSockStructT;

typedef enum {
    NET_INPUT = 0,
    NET_OUTPUT = 1
} NetInputOrOutput;


typedef struct SdpMesgRes {
    struct mHeader {
        uint8_t protocolVersion;
        uint8_t protocolVersionInv;
        uint16_t payloadType;
        uint32_t payloadLen;
    } mHeader;
    struct mPayload {
        uint8_t	u6_addr8[16];
        uint16_t port;
        uint8_t Sec;
        uint8_t transportProtocol;
    } mPayload;
}SdpMesgResT;

int32_t UDP_libCreate(uint8_t* device_, NetInputOrOutput io,
            int localPort, const char* remoteURL,
            int remotePort, const char* interface, int bufferSize, int dataTypeSize, int blockingTime);
int32_t UDP_libUpdate(uint8_t* device, const uint8_t* src, int nSamples);
int32_t UDP_libStart(uint8_t* device);
int32_t UDP_libOutputs(uint8_t* device, uint8_t* src, int *nSamples);
int32_t UDP_libTerminate(uint8_t* device);

#endif /* LINUXUDP_PORTV6_HEADER */
