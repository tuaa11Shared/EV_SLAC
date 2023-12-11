#ifndef SOC_CPULOADGENERATOR_HEADER
#define SOC_CPULOADGENERATOR_HEADER

typedef struct {
    int isproxy;
    double durpercent[5];
    double durmean[5];
    double durmin[5];
    double durmax[5];
    double durstd[5];
} durationStructType;

typedef struct {
    double time;
    int semIdx;
} SOC_eventSourceDataType;

void mw_cpuloadgenerator(int taskIdx);

#endif