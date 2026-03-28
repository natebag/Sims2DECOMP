#ifndef ETHREAD_H
#define ETHREAD_H

#include "types.h"

// EThread - struct layout extracted from assembly analysis
// Estimated minimum size: 0x33C (828 bytes)
// 9 known fields (5 named), 60 methods

class EThread {
public:
    // Constructors / Destructors
    EThread(void)  // 0x8077DF5C
    EThread(int, int, void *)  // 0x8077E004
    ~EThread(void);  // 0x8077E0E4

    // Methods
    void ValidateAllStacks(void);  // 0x80778480 (132B)
    void AttachToCallingThread(void);  // 0x807780C0 (68B)
    void SetupStack(int, void *);  // 0x80778104 (512B)
    void ValidateStack(void);  // 0x80778304 (380B)
    /* ? */ GetStackUsage(void);  // 0x80778504 (216B)
    void PrintAllThreads(void);  // 0x807785DC (240B)
    bool IsCallingThread(void);  // 0x8077E9D8 (80B)
    bool IsValidMemoryBlock(void *, int);  // 0x8077EDBC (284B)
    /* ? */ GetCurrentThreadId(void);  // 0x8077F244 (60B)
    void Attach(int);  // 0x8077E4E8 (376B)
    void DeallocateStack(void);  // 0x8077E1D0 (112B)
    /* ? */ GetPriority(void);  // 0x8077E930 (168B)
    void Create(int, int, void *);  // 0x8077E240 (528B)
    void Destroy(void);  // 0x8077E660 (224B)
    void ThreadEntryPoint(void *);  // 0x8077E450 (152B)
    /* ? */ GetStack(void);  // 0x8077EB70 (156B)
    /* ? */ GetStackSize(void);  // 0x8077EC0C (156B)
    void Start(void);  // 0x8077E740 (152B)
    void Stop(void);  // 0x8077E7D8 (68B)
    void SetPriority(int);  // 0x8077E81C (276B)
    /* ? */ GetThreadObject(int);  // 0x8077EA28 (256B)
    /* ? */ GetCallingThreadObject(void);  // 0x8077EB28 (72B)
    bool IsStackPtr(void *);  // 0x8077ECA8 (84B)
    /* ? */ GetThreadFromStackPtr(void *);  // 0x8077ECFC (192B)
    void Main(void);  // 0x8077EF98 (32B)
    void SetThreadName(char *);  // 0x8077EED8 (148B)
    /* ? */ GetThreadName(void);  // 0x8077EF6C (44B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x318];  // 0x000
    u32 m_field_318;  // 0x318 [R/W] (Attach, Create, Destroy, ...)
    u32 m_threadFromStackPtr;  // 0x31C [R/W] (Attach, Create, DeallocateStack, ...)
    u32 m_threadFromStackPtr_320;  // 0x320 [R/W] (Attach, Create, DeallocateStack, ...)
    u32 m_upStack;  // 0x324 [R/W] (Attach, DeallocateStack, EThread, ...)
    u32 m_upStack_328;  // 0x328 [W] (Attach, DeallocateStack, EThread, ...)
    u32 m_field_32C;  // 0x32C [W] (EThread)
    u32 m_field_330;  // 0x330 [R/W] (Attach, Create, Destroy, ...)
    u32 m_threadFromStackPtr_334;  // 0x334 [R/W] (Attach, Create, Destroy, ...)
    u32 m_field_338;  // 0x338 [W] (EThread, ~EThread)
};

#endif // ETHREAD_H
