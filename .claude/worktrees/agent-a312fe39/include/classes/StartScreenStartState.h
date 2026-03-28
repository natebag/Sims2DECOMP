#ifndef STARTSCREENSTARTSTATE_H
#define STARTSCREENSTARTSTATE_H

#include "types.h"

// StartScreenStartState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x190 (400 bytes)
// 11 known fields (0 named), 17 methods

class StartScreenStartState {
public:
    // Constructors / Destructors
    StartScreenStartState(int)  // 0x801D85F0
    ~StartScreenStartState(void);  // 0x801D866C

    // Methods
    void Startup(void);  // 0x801D8944 (284B)
    void Shutdown(void);  // 0x801D8A60 (136B)
    void Update(float);  // 0x801D8AE8 (832B)
    void Draw(ERC *);  // 0x801D8E28 (708B)
    bool IsFlowStateRequestPending(void);  // 0x801D93AC (92B)
    /* ? */ GetFlowStateRequest(void);  // 0x801D9408 (92B)
    void SetFlowStateCurrent(void);  // 0x801D9464 (84B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    u32 m_field_004;  // 0x004 [R] (Update)
    u32 m_field_008;  // 0x008 [R] (Update)
    u8 _pad_00C[8];  // 0x00C
    u32 m_field_014;  // 0x014 [R] (Draw)
    u32 m_field_018;  // 0x018 [R] (Draw)
    u32 m_field_01C;  // 0x01C [R/W] (Draw, Shutdown, Startup, ...)
    u32 m_field_020;  // 0x020 [R/W] (Draw, Shutdown, Startup, ...)
    u8 _pad_024[0x10];  // 0x024
    f32 m_field_034;  // 0x034 [R/W] (Draw)
    u8 _pad_038[8];  // 0x038
    s16 m_field_040;  // 0x040 [R] (Update)
    u8 _pad_042[0xAE];  // 0x042
    u32 m_field_0F0;  // 0x0F0 [R] (Draw)
    u8 _pad_0F4[0x94];  // 0x0F4
    s16 m_field_188;  // 0x188 [R] (Draw)
    u8 _pad_18A[2];  // 0x18A
    u32 m_field_18C;  // 0x18C [R] (Draw)
};

#endif // STARTSCREENSTARTSTATE_H
