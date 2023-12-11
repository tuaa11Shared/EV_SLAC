/* Copyright 2010-2012 The MathWorks, Inc. */
#ifndef __ARMCORTEXA_V4L2_CAPTURE_H_
#define __ARMCORTEXA_V4L2_CAPTURE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#ifdef MATLAB_MEX_FILE
 #include "tmwtypes.h"
#else
 #include "rtwtypes.h"
#endif

enum MW_PIXEL_FORMAT {
    MW_YCBCR422 = 1,      /* Index starts at zero to match MATLAB conventions */
    MW_RGB,
    NOT_SUPPORTED, /* Not supported from down here */
};

typedef enum {
    PIXEL_ORDER_INTERLEAVED = 1, /* Index starts at zero to match MATLAB conventions */
    PIXEL_ORDER_PLANAR,
} MW_PIXEL_ORDER;

#if defined(MATLAB_MEX_FILE)
   /* Simulation */
   #define MW_ERROR_EXIT(msg)                    videoCaptureCleanup(); mexErrMsgTxt(msg)
   #define MW_ERROR_EXIT1(msg, arg1)             sprintf(errMsg, msg, arg1); \
                                                 videoCaptureCleanup(); mexErrMsgTxt(errMsg)
   #define MW_ERROR_EXIT2(msg, arg1, arg2)       sprintf(errMsg, msg, arg1, arg2); \
                                                 videoCaptureCleanup(); mexErrMsgTxt(errMsg)
   #define MW_ERROR_EXIT3(msg, arg1, arg2, arg3) sprintf(errMsg, msg, arg1, arg2, arg3); \
                                                 videoCaptureCleanup(); mexErrMsgTxt(errMsg)
   #define MW_ERROR_EXIT4(msg, arg1, arg2, arg3, arg4) sprintf(errMsg, msg, arg1, arg2, arg3, arg4); \
                                                 videoCaptureCleanup(); mexErrMsgTxt(errMsg)
   #define MW_WARNING3(msg, arg1, arg2, arg3)    sprintf(errMsg, msg, arg1, arg2, arg3); mexWarnMsgTxt(errMsg)
#else
   /* Code generation */
   #define MW_ERROR_EXIT(msg)                    printf(msg); \
                                                 videoCaptureCleanup(); exit(EXIT_FAILURE)
   #define MW_ERROR_EXIT1(msg, arg1)             printf(msg, arg1); \
                                                 videoCaptureCleanup(); exit(EXIT_FAILURE)
   #define MW_ERROR_EXIT2(msg, arg1, arg2)       printf(msg, arg1, arg2); \
                                                 videoCaptureCleanup(); exit(EXIT_FAILURE)
   #define MW_ERROR_EXIT3(msg, arg1, arg2, arg3) printf(msg, arg1, arg2, arg3); \
                                                 videoCaptureCleanup(); exit(EXIT_FAILURE)
   #define MW_ERROR_EXIT4(msg, arg1, arg2, arg3, arg4) printf(msg, arg1, arg2, arg3, arg4); \
                                                 videoCaptureCleanup(); exit(EXIT_FAILURE)
   #define MW_WARNING3(msg, arg1, arg2, arg3)    printf(msg, arg1, arg2, arg3)
#endif
#define MW_NUM_V4L2_BUFFERS      (4)
#define MW_NUM_MAX_VIDEO_DEVICES (8)
#define MW_NUM_COLOR_PLANES      (3)
#define ERR_MSG_BUF_SIZE         (512)

typedef enum {
        IO_METHOD_READ,
        IO_METHOD_MMAP,
        IO_METHOD_USERPTR,
} MW_IO_METHOD;

typedef enum {
    SIM_OUTPUT_COLORBARS = 1,    /* Index starts at zero to match MATLAB conventions */
    SIM_OUTPUT_BLACK,
    SIM_OUTPUT_WHITE,
    SIM_OUTPUT_LIVE_VIDEO,
} MW_SIM_OUTPUT;

typedef struct {
	int32_T top;
	int32_T left;
	int32_T width;
	int32_T height;
} MW_rect_t;

typedef struct {
	uint32_T width;
	uint32_T height;
    uint32_T pln12Width;
	uint32_T pixelFormat;
} MW_imFormat_t;

typedef struct {
    void *start;
    size_t length;
} MW_frmInfo_t;

/* Structure holding device information */
typedef struct {
    int fd;                         /* handle to device */
    uint8_T *devName;                  /* i.e. "/dev/video0" */
    MW_rect_t roi;                  /* Stores cropping rectangle (ROI from block mask) */
    MW_imFormat_t imFormat;         /* Stores image size and pixel format */
    int pixelOrder;                 /* Interleave / planar selection */
    real_T frameRate;               /* 1/sampletime */
    int simOutput;                  /* Generated output in simulation */
    unsigned int frmCount;
    unsigned int v4l2BufCount;
    unsigned int v4l2CaptureStarted;
    MW_frmInfo_t frm[MW_NUM_V4L2_BUFFERS];
    uint8_T *hRgbRefLine;           /* RGB reference line for sim devices */
    MW_IO_METHOD ioMethod;          /* I/O method used */
} MW_videoInfo_t;


extern void MW_videoCaptureInit
(
        const uint8_T *devName, /* p1 */
        int32_T roiTop,         /* p2 */
        int32_T roiLeft,        /* p3 */
        int32_T roiWidth,       /* p4 */
        int32_T roiHeight,      /* p5 */
        uint32_T imWidth,       /* p6 */
        uint32_T imHeight,      /* p7 */
        uint32_T pixelFormat,   /* p8 */
        uint32_T pixelOrder,    /* p9 */
        uint32_T simOutput,     /* p10 */
        real_T sampleTime       /* p11 */
);
extern void MW_videoCaptureOutput(const uint8_T *devName, uint8_T *pln0, uint8_T *pln1, uint8_T *pln2);
extern void MW_videoCaptureTerminate(const uint8_T *devName);
extern uint32_T getBytesPerLine(uint32_T pixelFormat, uint32_T width);
extern void videoCaptureCleanup(void);


#endif /*__ARMCORTEXA_V4L2_CAPTURE_H_*/