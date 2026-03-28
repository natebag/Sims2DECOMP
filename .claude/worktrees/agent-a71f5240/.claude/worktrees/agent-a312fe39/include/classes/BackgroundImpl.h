#ifndef BACKGROUNDIMPL_H
#define BACKGROUNDIMPL_H

#include "types.h"

// BackgroundImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x34C (844 bytes)
// 7 known fields (1 named), 24 methods

class BackgroundImpl {
public:
    // Constructors / Destructors
    BackgroundImpl(void)  // 0x80799228
    ~BackgroundImpl(void);  // 0x807992B4

    // Methods
    void Shutdown(void);  // 0x8079939C (180B)
    void TerminateThread(void);  // 0x80799450 (240B)
    void SendCommand(BackgroundCmd *);  // 0x80799804 (296B)
    void Init(void);  // 0x80799540 (428B)
    void Update(void);  // 0x807996EC (32B)
    void ExecuteRoutine(void (*);  // 0x8079970C (116B)
    void ExecuteArgRoutine(void (*);  // 0x80799780 (132B)
    void Flush(void);  // 0x8079992C (312B)
    void Main(void);  // 0x80799A64 (544B)
    bool IsCallingThread(void);  // 0x80799F38 (72B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (BackgroundImpl, ExecuteArgRoutine, ExecuteRoutine, ...)
    u32 m_field_004;  // 0x004 [W] (ExecuteArgRoutine, ExecuteRoutine, Flush)
    u8 _pad_008[4];  // 0x008
    u32 m_field_00C;  // 0x00C [W] (ExecuteArgRoutine, ExecuteRoutine, Flush, ...)
    u8 _pad_010[0x18];  // 0x010
    s16 m_field_028;  // 0x028 [R] (Flush)
    u8 _pad_02A[2];  // 0x02A
    u32 m_field_02C;  // 0x02C [R] (Flush)
    u8 _pad_030[0x310];  // 0x030
    u32 m_field_340;  // 0x340 [W] (BackgroundImpl, ~BackgroundImpl)
    u8 _pad_344[4];  // 0x344
    u32 m_field_348;  // 0x348 [W] (BackgroundImpl, Init, Shutdown)
};

#endif // BACKGROUNDIMPL_H
