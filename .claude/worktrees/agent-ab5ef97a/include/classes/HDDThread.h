#ifndef HDDTHREAD_H
#define HDDTHREAD_H

#include "types.h"

// HDDThread - struct layout extracted from assembly analysis
// Estimated minimum size: 0x5D0 (1488 bytes)
// 5 known fields (4 named), 44 methods

class HDDThread {
public:
    // Constructors / Destructors
    HDDThread(void)  // 0x80878EC8
    ~HDDThread(void);  // 0x8087A648

    // Methods
    void SetPriorityHigh(void);  // 0x808795A0 (108B)
    void SetPriorityLow(void);  // 0x8087960C (108B)
    void InitAndRun(void);  // 0x80878FC8 (32B)
    bool IsDoingCommand(void);  // 0x80878FE8 (132B)
    void DoDelete(void);  // 0x8087906C (64B)
    void TerminateCopy(void);  // 0x808790D4 (60B)
    void DoCopy(void);  // 0x808790AC (40B)
    void DoFormat(void);  // 0x80879110 (72B)
    void DoSpeedTest(void);  // 0x80879158 (64B)
    void SpeedTest(void);  // 0x80879198 (32B)
    void Main(void);  // 0x808791B8 (32B)
    /* ? */ GetArcIndex(char *);  // 0x808791D8 (152B)
    void ArcIsCurrent(char *);  // 0x80879270 (92B)
    void ArcIsCurrent(int);  // 0x808792CC (120B)
    void ArcIsUsingHDD(int);  // 0x80879344 (120B)
    void ArcIsOpen(int);  // 0x808793BC (120B)
    /* ? */ GetArcName(int);  // 0x80879434 (124B)
    /* ? */ GetArcSourceLen(int);  // 0x808794B0 (120B)
    /* ? */ GetArcCopiedSize(int);  // 0x80879528 (120B)
    void StopAll(void);  // 0x80879678 (84B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x338];  // 0x000
    u32 m_field_338;  // 0x338 [W] (HDDThread)
    u8 _pad_33C[0x284];  // 0x33C
    u32 m_bIsDoingCommand;  // 0x5C0 [R/W] (HDDThread, IsDoingCommand)
    u32 m_bIsDoingCommand_5C4;  // 0x5C4 [R/W] (HDDThread, IsDoingCommand)
    u32 m_bIsDoingCommand_5C8;  // 0x5C8 [R/W] (HDDThread, IsDoingCommand)
    u32 m_bIsDoingCommand_5CC;  // 0x5CC [R/W] (HDDThread, IsDoingCommand)
};

#endif // HDDTHREAD_H
