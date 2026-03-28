#ifndef EGAMESTATEMAN_H
#define EGAMESTATEMAN_H

#include "types.h"

// EGameStateMan - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 18 methods

class EGameStateMan {
public:
    // Constructors / Destructors
    EGameStateMan(void)  // 0x801A7620
    ~EGameStateMan(void);  // 0x801A767C

    // Methods
    void DeleteAllStates(void);  // 0x801A7B8C (156B)
    void AddState(EGameState *);  // 0x801A795C (316B)
    void SetState(EGameStateId);  // 0x801A76EC (624B)
    void KillState(void);  // 0x801A7A98 (88B)
    void SoftReset(void);  // 0x801A7AF0 (156B)
    void Update(void);  // 0x801A7C28 (152B)
    void Draw(ERC *);  // 0x801A7CC0 (212B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (DeleteAllStates, SetState, SoftReset, ...)
    u32 m_state_004;  // 0x004 [R] (SetState)
    u32 m_state_008;  // 0x008 [R] (DeleteAllStates, SetState, SoftReset)
};

#endif // EGAMESTATEMAN_H
