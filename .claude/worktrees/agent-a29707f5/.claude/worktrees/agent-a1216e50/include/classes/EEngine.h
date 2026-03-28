#ifndef EENGINE_H
#define EENGINE_H

#include "types.h"

// EEngine - struct layout extracted from assembly analysis
// Estimated minimum size: 0x34 (52 bytes)
// 6 known fields (1 named), 68 methods

class EEngine {
public:
    // Constructors / Destructors
    EEngine(void)  // 0x8079B7BC
    ~EEngine(void);  // 0x8079B968

    // Methods
    void SetCurrentLevel(ERLevel *);  // 0x8079E4B8 (40B)
    /* ? */ GetCurrentLevel(void);  // 0x8079E4E0 (44B)
    void SetResetAllowed(bool);  // 0x8079E50C (40B)
    void ClearCurrentLevel(ERLevel *);  // 0x8079DBDC (60B)
    void ManagedShutdown(void);  // 0x8079B9CC (160B)
    void Line(void);  // 0x8079BA6C (64B)
    void Init(void);  // 0x8079BAAC (688B)
    void PrintBanner(void);  // 0x8079C84C (96B)
    void PrintConfiguration(void);  // 0x8079C8AC (220B)
    void ShutdownThreads(bool);  // 0x8079BD5C (320B)
    void RetraceUpdate(float);  // 0x8079BE9C (416B)
    /* ? */ GetMinRetraces(void);  // 0x8079C03C (72B)
    void EnterMovieMode(void);  // 0x8079C084 (112B)
    void ExitMovieMode(void);  // 0x8079C0F4 (112B)
    void PreFrameUpdate(void);  // 0x8079C164 (1316B)
    void PostFrameUpdate(void);  // 0x8079C688 (336B)
    void FrameComplete(void);  // 0x8079C7D8 (116B)
    void InitSubsystems(void);  // 0x8079CBE0 (2760B)
    void InitFileSystem(void);  // 0x8079D6A8 (76B)
    void InitResourceManagers(void);  // 0x8079D6F4 (688B)
    void ShutdownResourceManagers(void);  // 0x8079D9A4 (568B)
    void Idle(void);  // 0x8079DC18 (44B)
    /* ? */ GetDMARingMemoryUseInfo(HeapUseInfo *);  // 0x8079DC44 (100B)
    /* ? */ GetTextureRingMemoryUseInfo(HeapUseInfo *);  // 0x8079DCA8 (100B)
    /* ? */ GetMatrixRingMemoryUseInfo(HeapUseInfo *);  // 0x8079DD0C (100B)
    /* ? */ GetMemoryUseSystemInfo(HeapUseInfo *);  // 0x8079DD70 (100B)
    /* ? */ GetMemoryUseDmaInfo(HeapUseInfo *);  // 0x8079DDD4 (100B)
    void ManagedStartup(void);  // 0x8079E580 (40B)
    void Reboot(void);  // 0x8079E498 (32B)
    void SignalShutdown(void);  // 0x8079E560 (32B)
    void EnableFrameRatePredictiveSmoothing(bool);  // 0x8079E470 (40B)
    bool CanReset(void);  // 0x8079E534 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (EEngine, Init, InitSubsystems, ...)
    u32 m_field_004;  // 0x004 [W] (EEngine, Init)
    u32 m_field_008;  // 0x008 [R/W] (EEngine, PreFrameUpdate, RetraceUpdate)
    u32 m_field_00C;  // 0x00C [W] (EEngine)
    u8 _pad_010[0x10];  // 0x010
    u32 m_field_020;  // 0x020 [R] (InitSubsystems)
    u8 _pad_024[0xC];  // 0x024
    u32 m_field_030;  // 0x030 [W] (EEngine)
};

#endif // EENGINE_H
