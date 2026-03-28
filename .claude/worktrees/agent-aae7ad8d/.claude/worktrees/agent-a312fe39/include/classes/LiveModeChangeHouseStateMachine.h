#ifndef LIVEMODECHANGEHOUSESTATEMACHINE_H
#define LIVEMODECHANGEHOUSESTATEMACHINE_H

#include "types.h"

// LiveModeChangeHouseStateMachine - struct layout extracted from assembly analysis
// Estimated minimum size: 0x98 (152 bytes)
// 20 known fields (1 named), 14 methods

class LiveModeChangeHouseStateMachine {
public:
    // Constructors / Destructors
    LiveModeChangeHouseStateMachine(int, int)  // 0x801BFDD8
    ~LiveModeChangeHouseStateMachine(void);  // 0x801BE524

    // Methods
    void Startup(void);  // 0x801B6C50 (544B)
    void Shutdown(void);  // 0x801B6E70 (376B)
    void Reset(void);  // 0x801B6FE8 (208B)
    void Update(float);  // 0x801B70B8 (72B)
    void Draw(ERC *);  // 0x801B7100 (72B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (LiveModeChangeHouseStateMachine, Startup)
    u32 m_field_004;  // 0x004 [W] (LiveModeChangeHouseStateMachine, Startup)
    u32 m_field_008;  // 0x008 [W] (LiveModeChangeHouseStateMachine, Startup)
    u32 m_field_00C;  // 0x00C [W] (LiveModeChangeHouseStateMachine, Startup)
    u32 m_field_010;  // 0x010 [W] (LiveModeChangeHouseStateMachine, Startup)
    u32 m_field_014;  // 0x014 [W] (LiveModeChangeHouseStateMachine, Startup)
    u32 m_field_018;  // 0x018 [W] (LiveModeChangeHouseStateMachine, Startup, ~LiveModeChangeHouseStateMachine)
    u32 m_field_01C;  // 0x01C [W] (LiveModeChangeHouseStateMachine, Startup)
    u32 m_field_020;  // 0x020 [W] (LiveModeChangeHouseStateMachine)
    u32 m_field_024;  // 0x024 [W] (LiveModeChangeHouseStateMachine)
    f32 m_field_028;  // 0x028 [W] (LiveModeChangeHouseStateMachine)
    u32 m_field_02C;  // 0x02C [R/W] (LiveModeChangeHouseStateMachine, ~LiveModeChangeHouseStateMachine)
    u8 _pad_030[0xC];  // 0x030
    u32 m_field_03C;  // 0x03C [W] (LiveModeChangeHouseStateMachine)
    u8 _pad_040[0x14];  // 0x040
    u32 m_field_054;  // 0x054 [W] (LiveModeChangeHouseStateMachine)
    u8 _pad_058[0xC];  // 0x058
    u32 m_field_064;  // 0x064 [W] (LiveModeChangeHouseStateMachine)
    u8 _pad_068[0x1C];  // 0x068
    u32 m_field_084;  // 0x084 [W] (LiveModeChangeHouseStateMachine)
    u32 m_field_088;  // 0x088 [W] (LiveModeChangeHouseStateMachine)
    u32 m_field_08C;  // 0x08C [W] (LiveModeChangeHouseStateMachine)
    u32 m_field_090;  // 0x090 [W] (LiveModeChangeHouseStateMachine)
    u32 m_field_094;  // 0x094 [W] (LiveModeChangeHouseStateMachine)
};

#endif // LIVEMODECHANGEHOUSESTATEMACHINE_H
