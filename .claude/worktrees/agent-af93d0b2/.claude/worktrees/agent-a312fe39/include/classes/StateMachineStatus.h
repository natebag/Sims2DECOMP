#ifndef STATEMACHINESTATUS_H
#define STATEMACHINESTATUS_H

#include "types.h"

// StateMachineStatus - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 3 known fields (3 named), 24 methods

class StateMachineStatus {
public:
    // Constructors / Destructors
    StateMachineStatus(void)  // 0x801DCB9C
    ~StateMachineStatus(void);  // 0x801DCBFC

    // Methods
    void AddToSecondsInCurState(float);  // 0x801DAD38 (52B)
    void StatusReset(void);  // 0x801DAADC (88B)
    void SetCallingState(StateMachineState *);  // 0x801DCCCC (40B)
    void ShutdownCurState(void);  // 0x801DAD6C (160B)
    void AddToSecondsBeforeNextState(float);  // 0x801DACD0 (104B)
    void SetState(StateMachineState *);  // 0x801DAB34 (412B)
    void UpdateCurState(float);  // 0x801DAE0C (160B)
    void DrawCurState(ERC *);  // 0x801DAEAC (160B)
    void DrawTopmostCurState(ERC *);  // 0x801DAF4C (160B)
    void SetNextState(StateMachineState *, float);  // 0x801DCD20 (48B)
    /* ? */ GetCurState(void);  // 0x801DCC48 (44B)
    /* ? */ GetLastState(void);  // 0x801DCC74 (44B)
    /* ? */ GetCallingState(void);  // 0x801DCCA0 (44B)
    /* ? */ GetSecondsInCurState(void);  // 0x801DCCF4 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (SetState, ShutdownCurState)
    u8 _pad_004[4];  // 0x004
    u32 m_state_008;  // 0x008 [W] (SetState)
    u8 _pad_00C[8];  // 0x00C
    f32 m_state_014;  // 0x014 [W] (SetState)
};

#endif // STATEMACHINESTATUS_H
