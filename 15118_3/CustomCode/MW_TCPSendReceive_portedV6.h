#ifndef _MW_SHARED_LINUX_TCP_V6_H_
#define _MW_SHARED_LINUX_TCP_V6_H_

#ifndef DEBUG_PRINTF
#define DEBUG_PRINTF
#endif

#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

#ifdef __cplusplus
#include <cmath>
#include <cstdlib>
#else
#include <stdlib.h>
#include <math.h>
#endif

#include <pthread.h>
#include <syslog.h>
#include <sys/ioctl.h>
#include <string.h>
#include <poll.h>

#define NO_BLOCKING (0)
#define BLOCKING_RECV (1)
#define INF_BLOCKING (-1)

#define TCPSTREAM_NO_ERROR (0)
#define TCPSTREAM_ERROR (-1)

/* timeout of 0 means to return immediately */
#define BLOCKING_RECV_TIMEOUT_NOWAIT (0)
/* timeout of -1 means to wait indefinitely */
#define BLOCKING_RECV_TIMEOUT_NEVER (-1)
/* rogue value for blocking receive timeout */
#define DEFAULT_BLOCKING_RECV_TIMEOUT (-2)
/* timeout on a default value TO DO: decide upon the value */
#define BLOCKING_RECV_TIMEOUT_xMS (-3)

/* default isVerbose value */
#define DEFAULT_IS_VERBOSE 0

#define INVALID_SOCKET (-1)
#define SOCK_ERR (-1)
#define RECEIVE_SUCCESS (1)

#define CONNECT_SUCCESS (1)
#define CONNECT_FAILED (-1)

#define TCP_ERR_NOCLIENT (1)
#define TCP_ERR_NOSERVER (2)
#define TCP_ERR_CONNSUCCESS (3)
#define TCP_ERR_SOCBIND (4)
#define TCP_ERR_NOHOST (5)
#define TCP_ERR_NOCONN_SERVER (6)
#define TCP_ERR_NOCONN_CLIENT (7)

#ifdef DEBUG_SYSLOG
#define LOG(LOG_LEVEL,message,args...) syslog(LOG_LEVEL,"%s(): "message,__func__,##args)
#else
#ifdef DEBUG_PRINTF
#define LOG(LOG_LEVEL,message,args...) printf(message,##args)
#else
#define LOG(LOG_LEVEL,message,args...)
#endif
#endif

#define MAX_NUM_CONNECTIONS (20)

#ifndef h_addr
#define h_addr h_addr_list[0] /*For backward compatibility with _POSIX_C_SOURCE>=199309L*/
#endif

typedef int SOCKET;

/* enum of connection modes */
typedef enum { CLIENT_MODE, SERVER_MODE } ConnectionModeT;

/* enum of valid connection */
typedef enum { VALID_TCP_STREAM, INVALID_TCP_STREAM } ConnectionStatusT;

/*
 * The following typedefs suppress compiler warnings.
 */
typedef const void* send_buffer_t;

/* Server specific data structure */
typedef struct ServerData_tag {
    uint16_t port; /* port number associated with the server socket */
    SOCKET listenSock; /* listening socket to accept incoming connections */
} ServerDataT;

#define PADDING_REV 8
/* Data encapsulating a single client / server connection  */
typedef struct ConnectionInfo_tag {
    int isInUse; 			/* is this ConnectionInfoT instance currently in use? */
    float blockingTimeout; /*TO DO
     * Get blocking params from mask
     */
    int isVerbose; 			/* flag indicating whether to display verbose output */
    SOCKET sock; 			/* socket to send/receive packets */
    SOCKET clientSock;		/* saved socket for connection retry */
    ServerDataT* serverData; /* Server specific data - NULL for clients */
    char remoteHost[INET6_ADDRSTRLEN + PADDING_REV]; 	/* Remote address if connection is in client mode */
    uint16_t remotePort; 	/* Remote server port */
    uint16_t localClientPort;
    uint16_t streamID;
    int32_t SendBufferSize;
    int32_t ReceiveBufferSize;
    ConnectionModeT operMode; /* Server or Client */
    pthread_mutex_t connect_mutex;
    pthread_cond_t connect_cv;
} ConnectionInfoT;

#ifdef __cplusplus
extern "C" {
#endif
    ConnectionInfoT* getConnectionInfo6(int connectionID);
    void TCPStreamSetup6(uint16_t portNumber, uint16_t localClientPort, uint16_t* connStream, uint16_t server, float blockingTimeout, int16_t* errorNo, uint8_t* addr6);
    void TCPStreamStepSend6(const uint8_t* dataIn, uint32_t dataInSize, uint16_t connStream, uint16_t isSer, int16_t* errorNo);
    void TCPStreamStepRecv6(uint8_t* msgRec, int8_t* recvStatus, uint32_t dataSizeToRead, uint16_t connStream, int16_t* errorNo, uint16_t isSer);
#ifdef __cplusplus
}
#endif
#endif
