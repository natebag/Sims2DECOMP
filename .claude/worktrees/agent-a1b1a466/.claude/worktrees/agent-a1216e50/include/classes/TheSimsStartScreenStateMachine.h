#ifndef THESIMSSTARTSCREENSTATEMACHINE_H
#define THESIMSSTARTSCREENSTATEMACHINE_H

#include "types.h"

// TheSimsStartScreenStateMachine - struct layout extracted from assembly analysis
// Estimated minimum size: 0x98 (152 bytes)
// 20 known fields (1 named), 12 methods

class TheSimsStartScreenStateMachine {
public:
    // Constructors / Destructors
    TheSimsStartScreenStateMachine(int, int)  // 0x801D8520
    ~TheSimsStartScreenStateMachine(void);  // 0x801D7CE4

    // Methods
    void Startup(void);  // 0x801D5170 (356B)
    void Shutdown(void);  // 0x801D52D4 (116B)
    void Reset(void);  // 0x801D5348 (132B)
    void Update(float);  // 0x801D53CC (80B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (Startup, TheSimsStartScreenStateMachine)
    u32 m_field_004;  // 0x004 [W] (Startup, TheSimsStartScreenStateMachine)
    u32 m_field_008;  // 0x008 [W] (Startup, TheSimsStartScreenStateMachine)
    u32 m_field_00C;  // 0x00C [W] (Startup, TheSimsStartScreenStateMachine)
    u32 m_field_010;  // 0x010 [W] (Startup, TheSimsStartScreenStateMachine)
    u32 m_field_014;  // 0x014 [W] (Startup, TheSimsStartScreenStateMachine)
    u32 m_field_018;  // 0x018 [W] (Startup, TheSimsStartScreenStateMachine, ~TheSimsStartScreenStateMachine)
    u32 m_field_01C;  // 0x01C [W] (Startup, TheSimsStartScreenStateMachine)
    u32 m_field_020;  // 0x020 [W] (Startup, TheSimsStartScreenStateMachine)
    u32 m_field_024;  // 0x024 [W] (TheSimsStartScreenStateMachine)
    f32 m_field_028;  // 0x028 [W] (TheSimsStartScreenStateMachine)
    u32 m_field_02C;  // 0x02C [R/W] (TheSimsStartScreenStateMachine, ~TheSimsStartScreenStateMachine)
    u8 _pad_030[0xC];  // 0x030
    u32 m_field_03C;  // 0x03C [W] (TheSimsStartScreenStateMachine)
    u8 _pad_040[0x14];  // 0x040
    u32 m_field_054;  // 0x054 [W] (TheSimsStartScreenStateMachine)
    u8 _pad_058[0xC];  // 0x058
    u32 m_field_064;  // 0x064 [W] (TheSimsStartScreenStateMachine)
    u8 _pad_068[0x1C];  // 0x068
    u32 m_field_084;  // 0x084 [W] (TheSimsStartScreenStateMachine)
    u32 m_field_088;  // 0x088 [W] (TheSimsStartScreenStateMachine)
    u32 m_field_08C;  // 0x08C [W] (TheSimsStartScreenStateMachine)
    u32 m_field_090;  // 0x090 [W] (TheSimsStartScreenStateMachine)
    u32 m_field_094;  // 0x094 [W] (TheSimsStartScreenStateMachine)
};

#endif // THESIMSSTARTSCREENSTATEMACHINE_H
