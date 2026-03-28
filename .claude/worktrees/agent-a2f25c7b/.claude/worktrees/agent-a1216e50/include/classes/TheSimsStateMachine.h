#ifndef THESIMSSTATEMACHINE_H
#define THESIMSSTATEMACHINE_H

#include "types.h"

// TheSimsStateMachine - struct layout extracted from assembly analysis
// Estimated minimum size: 0x47C (1148 bytes)
// 30 known fields (1 named), 18 methods

class TheSimsStateMachine {
public:
    // Constructors / Destructors
    TheSimsStateMachine(int, int)  // 0x801E8BAC
    ~TheSimsStateMachine(void);  // 0x801E79F0

    // Methods
    bool IsFlowStateRequestPending(void);  // 0x801E3054 (96B)
    void SetFlowStateCurrent(void);  // 0x801E3114 (76B)
    /* ? */ GetFlowStateRequest(void);  // 0x801E30B4 (96B)
    void Startup(void);  // 0x801E28D0 (1304B)
    void Shutdown(void);  // 0x801E2DE8 (288B)
    void Update(float);  // 0x801E2F08 (180B)
    void Draw(ERC *);  // 0x801E2FBC (152B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (Startup, TheSimsStateMachine)
    u32 m_field_004;  // 0x004 [W] (Startup, TheSimsStateMachine)
    u32 m_field_008;  // 0x008 [W] (Startup, TheSimsStateMachine)
    u32 m_field_00C;  // 0x00C [W] (Startup, TheSimsStateMachine)
    f32 m_field_010;  // 0x010 [W] (Startup, TheSimsStateMachine)
    f32 m_field_014;  // 0x014 [W] (Startup, TheSimsStateMachine)
    u32 m_field_018;  // 0x018 [W] (Startup, TheSimsStateMachine, ~TheSimsStateMachine)
    u32 m_field_01C;  // 0x01C [W] (Startup, TheSimsStateMachine)
    u16 m_field_020;  // 0x020 [W] (Startup, TheSimsStateMachine)
    u8 _pad_022[2];  // 0x022
    f32 m_field_024;  // 0x024 [W] (Startup, TheSimsStateMachine)
    f32 m_field_028;  // 0x028 [W] (Startup, TheSimsStateMachine)
    u32 m_field_02C;  // 0x02C [R/W] (Startup, TheSimsStateMachine, ~TheSimsStateMachine)
    u8 _pad_030[0xC];  // 0x030
    u32 m_field_03C;  // 0x03C [W] (Startup, TheSimsStateMachine)
    u32 m_field_040;  // 0x040 [W] (Startup)
    u32 m_field_044;  // 0x044 [W] (Startup)
    u16 m_field_048;  // 0x048 [W] (Startup)
    u16 m_field_04A;  // 0x04A [W] (Startup)
    f32 m_field_04C;  // 0x04C [W] (Startup)
    u8 _pad_050[4];  // 0x050
    u32 m_field_054;  // 0x054 [W] (Startup, TheSimsStateMachine)
    u8 _pad_058[0xC];  // 0x058
    u32 m_field_064;  // 0x064 [W] (Startup, TheSimsStateMachine)
    u32 m_field_068;  // 0x068 [R/W] (Shutdown)
    u8 _pad_06C[0x10];  // 0x06C
    u32 m_field_07C;  // 0x07C [W] (Startup)
    u8 _pad_080[4];  // 0x080
    u32 m_field_084;  // 0x084 [W] (Startup, TheSimsStateMachine)
    u32 m_field_088;  // 0x088 [W] (Startup, TheSimsStateMachine)
    u32 m_field_08C;  // 0x08C [W] (Startup, TheSimsStateMachine)
    u32 m_field_090;  // 0x090 [W] (Startup, TheSimsStateMachine)
    u32 m_field_094;  // 0x094 [W] (Startup, TheSimsStateMachine)
    u32 m_field_098;  // 0x098 [R/W] (Shutdown, Startup)
    u32 m_field_09C;  // 0x09C [W] (Startup)
    u8 _pad_0A0[0x3D8];  // 0x0A0
    u32 m_field_478;  // 0x478 [W] (Startup)
};

#endif // THESIMSSTATEMACHINE_H
