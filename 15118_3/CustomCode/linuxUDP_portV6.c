#include "linuxUDP_portV6.h"
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <limits.h>
#include <assert.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/time.h>
#include <fcntl.h>
#include <net/if.h>
#include <unistd.h>


 /* Wrap everything in extern C */
#ifdef __cplusplus
extern "C" {
#endif 
    int32_t UDP_libCreate(uint8_t* device_, NetInputOrOutput io,
            int localPort, const char* remoteURL, int remotePort,
            const char* interface, int bufferSize, int dataTypeSize, int blockingTime) {
        int flags;
        struct timeval tv;
        int ret;
        UDPSockStructT* device;
        /* verification of the local port*/
        /* case it lower than zero, assign to zero so it can dynamically assigned */
        if (localPort < 0) {
            localPort = 0;
        }
        device = (UDPSockStructT*)device_;

        bzero(&device->remotesockaddr, sizeof(device->remotesockaddr));
        device->remotesockaddr.sin6_family = AF_INET6;
        device->remotesockaddr.sin6_port = htons(remotePort);

        if (inet_pton(AF_INET6, remoteURL, &(device->remotesockaddr.sin6_addr)) <= 0) {
            perror("inet_pton");
            return EXIT_FAILURE;
        }

        bzero(&device->localsockaddr, sizeof(device->localsockaddr));
        device->localsockaddr.sin6_family = AF_INET6;
        device->localsockaddr.sin6_port = htons(localPort);

        device->sockfd = socket(AF_INET6, SOCK_DGRAM, 0);
        if (device->sockfd < 0) {
            printf("error creating socket\n");
        }

        // const char* interface_name = "eth1";
        if (setsockopt(device->sockfd, SOL_SOCKET, 25, interface, strlen(interface)) == -1) {
            perror("can't bind interface");
            close(device->sockfd);
            return EXIT_FAILURE;
        }

        int enable = 1;
        if (setsockopt(device->sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) == -1) {
            perror("setsockopt");
            close(device->sockfd);
            return EXIT_FAILURE;
        }

        {
            struct ifaddrs* ifaddr, * ifa;
            // Lấy thông tin về tất cả các interface trên máy tính
            if (getifaddrs(&ifaddr) == -1) {
                perror("getifaddrs");
                return EXIT_FAILURE;
            }

            // Duyệt qua danh sách các interface để lấy địa chỉ IP
            for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
                if (ifa->ifa_addr == NULL) {
                    continue;
                }

                // Chỉ quan tâm đến interface với địa chỉ AF_INET6
                if (ifa->ifa_addr->sa_family == AF_INET6) {
                    char ipstr[INET6_ADDRSTRLEN];
                    if (strcmp(ifa->ifa_name, interface) == 0) {
                        if (IN6_IS_ADDR_LINKLOCAL(&((struct sockaddr_in6*)ifa->ifa_addr)->sin6_addr)) {
                            memcpy(&(device->localsockaddr.sin6_addr), &((struct sockaddr_in6*)ifa->ifa_addr)->sin6_addr, 16);
                            inet_ntop(AF_INET6, &(device->localsockaddr.sin6_addr), ipstr, sizeof(ipstr));
                            printf("Interface: %s, IPv6: %s\n", ifa->ifa_name, ipstr);
                        }
                    }
                }
            }
            freeifaddrs(ifaddr);
        }

        if (io == NET_INPUT) {
            ret = setsockopt(((UDPSockStructT*)device)->sockfd, SOL_SOCKET, SO_RCVBUF, &bufferSize, sizeof(bufferSize));
        }
        else if (io == NET_OUTPUT) {
            ret = setsockopt(((UDPSockStructT*)device)->sockfd, SOL_SOCKET, SO_SNDBUF, &bufferSize, sizeof(bufferSize));
        }
        else {
            ret = -1;
            perror("INVALID NetworkIOValue");
            return EXIT_FAILURE;
        }

        if (ret < 0) {
            perror("ERROR in setsockopt");
            return EXIT_FAILURE;
        }
        else {
            int realSize = 0;
            int len = sizeof(realSize);

            if (io == NET_INPUT) {
                getsockopt(((UDPSockStructT*)device)->sockfd, SOL_SOCKET, SO_RCVBUF, &realSize, &len);
            }
            else {
                getsockopt(((UDPSockStructT*)device)->sockfd, SOL_SOCKET, SO_SNDBUF, &realSize, &len);
            }
            if (realSize < bufferSize) {
                fprintf(stderr, "Buffer requested size: %d Bytes. Socket buffer limit: %d Bytes\n", bufferSize, realSize);
            }
        }

        if (blockingTime == 0) {
            /* set non-blocking socket option */
            flags = fcntl(((UDPSockStructT*)device)->sockfd, F_GETFL, 0);
            fcntl(((UDPSockStructT*)device)->sockfd, F_SETFL, flags | O_NONBLOCK);
        }
        else if (blockingTime != INT_MAX) {
            /* if not set to inf in the block mask */
            tv.tv_sec = (long)(blockingTime / 1000);
            tv.tv_usec = (long)(blockingTime % 1000);
            setsockopt(((UDPSockStructT*)device)->sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
        }
        device->dataTypeSize = dataTypeSize;
        // *device_ = device;
        return EXIT_SUCCESS;
    }


    int32_t UDP_libStart(uint8_t* device) {
        if (device) {
            bind(((UDPSockStructT*)device)->sockfd,
                    (struct sockaddr*)&((UDPSockStructT*)device)->localsockaddr,
                    sizeof(((UDPSockStructT*)device)->localsockaddr));
            return EXIT_SUCCESS;
        }
        else
            return EXIT_FAILURE;
    }


    int32_t UDP_libUpdate(uint8_t* device, const uint8_t* src, int nSamples) {
        int n;
        if (device) {
            n = sendto(((UDPSockStructT*)device)->sockfd, src,
                    ((UDPSockStructT*)device)->dataTypeSize * nSamples, 0,
                    (struct sockaddr*)&((UDPSockStructT*)device)->remotesockaddr,
                    sizeof(((UDPSockStructT*)device)->remotesockaddr));
            if (n < 0) {
                printf("error writing to socket\n");
                return EXIT_FAILURE;
            }
            return EXIT_SUCCESS;
        }
        else
            return EXIT_FAILURE;
    }


    int32_t UDP_libOutputs(uint8_t* device, uint8_t* src, int* nSamples) {
        int numBytesReceived = 0;
        int dTypeSize;
        size_t nBytesToRead;
        if (device) {
            dTypeSize = ((UDPSockStructT*)device)->dataTypeSize;
            nBytesToRead = dTypeSize * (*nSamples);
            numBytesReceived = recvfrom(((UDPSockStructT*)device)->sockfd, src, nBytesToRead, 0, NULL, NULL);
            *nSamples = (int)(numBytesReceived / dTypeSize); /* Return number of bytes received */
            return EXIT_SUCCESS;
        }
        else
            return EXIT_FAILURE;
    }

    int32_t UDP_libTerminate(uint8_t* device) {
        close(((UDPSockStructT*)device)->sockfd);
        return EXIT_SUCCESS;
    }