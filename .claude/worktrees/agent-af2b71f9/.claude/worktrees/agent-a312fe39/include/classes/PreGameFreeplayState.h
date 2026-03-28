#ifndef PREGAMEFREEPLAYSTATE_H
#define PREGAMEFREEPLAYSTATE_H

#include "types.h"

// PreGameFreeplayState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 2 known fields (0 named), 18 methods

class PreGameFreeplayState {
public:
    // Constructors / Destructors
    PreGameFreeplayState(int)  // 0x801D473C
    ~PreGameFreeplayState(void);  // 0x801D3A18

    // Methods
    void Startup(void);  // 0x801D0B34 (348B)
    void Shutdown(void);  // 0x801D0C90 (140B)
    void Reset(void);  // 0x801D0D1C (72B)
    void Update(float);  // 0x801D0D64 (820B)
    bool IsFlowStateRequestPending(void);  // 0x801D47B0 (80B)
    /* ? */ GetFlowStateRequest(void);  // 0x801D4800 (80B)
    void SetFlowStateCurrent(void);  // 0x801D4850 (72B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Update)
    u8 _pad_00C[0x10];  // 0x00C
    u32 m_field_01C;  // 0x01C [R/W] (Shutdown, Startup, Update)
};

#endif // PREGAMEFREEPLAYSTATE_H
