#ifndef THESIMSMAINMENUSTATE_H
#define THESIMSMAINMENUSTATE_H

#include "types.h"

// TheSimsMainMenuState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x94 (148 bytes)
// 3 known fields (0 named), 22 methods

class TheSimsMainMenuState {
public:
    // Constructors / Destructors
    TheSimsMainMenuState(int)  // 0x801E90E0
    ~TheSimsMainMenuState(void);  // 0x801E9154

    // Methods
    void Startup(void);  // 0x801E1838 (396B)
    void Shutdown(void);  // 0x801E19C4 (296B)
    void Reset(void);  // 0x801E1AEC (544B)
    void Update(float);  // 0x801E1D0C (2264B)
    bool IsFlowStateRequestPending(void);  // 0x801E91AC (80B)
    /* ? */ GetFlowStateRequest(void);  // 0x801E91FC (80B)
    void SetFlowStateCurrent(void);  // 0x801E924C (72B)
    void LeavingMainMenuCleanup(void);  // 0x801E25E4 (336B)
    void Draw(ERC *);  // 0x801E2734 (104B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Update)
    u8 _pad_00C[0xC];  // 0x00C
    u32 m_field_018;  // 0x018 [R/W] (Update, ~TheSimsMainMenuState)
    u8 _pad_01C[0x74];  // 0x01C
    u32 m_field_090;  // 0x090 [R/W] (Update)
};

#endif // THESIMSMAINMENUSTATE_H
