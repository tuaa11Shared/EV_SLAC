/* Copyright 2014-2016 The MathWorks, Inc. */

#include <vxWorks.h>
#include <types/vxWind.h> /*Support OLD VxWorks Types */
#include <taskLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <pthread.h>
#include <sched.h>
#include <semaphore.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <cpuset.h>

typedef struct {
    int sigNo;
    sigset_t sigMask;
    double period;
} baseRateInfo_t;

void myWaitForThisEvent(int sigNo);
void myAddBlockForThisEvent(int sigNo);
void myAddHandlerForThisEvent(int sigNo, int sigToBlock[], int numSigToBlock, void (*sigHandler)(int));
void myRestoreDefaultHandlerForThisEvent(int sigNo);
void myRTOSInit(double baseRatePeriod, int numSubrates);

/* Define the semaphore used by VXWORKS rtiostream API */
SEM_ID startStopSem; 

#define CHECK_STATUS(status, expStatus, fcn) if (status != expStatus) {fprintf(stderr, "Call to %s returned error status (%d).\n", fcn, status); perror(fcn); fflush(stderr); exit(EXIT_FAILURE);}
#define CHECK_STATUS_NOT(status, errStatus, fcn) if (status == errStatus) {fprintf(stderr, "Call to %s returned error status (%d).\n", fcn, status); perror(fcn); fflush(stderr); exit(EXIT_FAILURE);}
#define UNUSED(x) x = x
