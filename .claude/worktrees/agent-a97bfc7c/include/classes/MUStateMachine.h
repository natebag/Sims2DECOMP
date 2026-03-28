#ifndef MUSTATEMACHINE_H
#define MUSTATEMACHINE_H

#include "types.h"

// MUStateMachine - struct layout extracted from assembly analysis
// Estimated minimum size: 0x108 (264 bytes)
// 40 known fields (1 named), 34 methods

class MUStateMachine {
public:
    // Constructors / Destructors
    MUStateMachine(int, int)  // 0x801CDD58
    ~MUStateMachine(void);  // 0x801CDDBC

    // Methods
    void MURequest(MUStateMachine::eMURequest);  // 0x801CAC40 (252B)
    void MUPollForResult(MUStateMachine::eMURequest);  // 0x801CAD3C (84B)
    void SetupQuitToMainMenu(void);  // 0x801CAFE4 (304B)
    void Startup(void);  // 0x801CA6BC (740B)
    void Shutdown(void);  // 0x801CA9A0 (72B)
    void MUWrapperShutdown(void);  // 0x801CAE50 (148B)
    void Reset(void);  // 0x801CA9E8 (452B)
    void Update(float);  // 0x801CABAC (64B)
    void Draw(ERC *);  // 0x801CABEC (84B)
    void MUWrapperStartup(void);  // 0x801CAD90 (192B)
    /* ? */ GetCurRequest(void);  // 0x801CAEE4 (44B)
    void ClearResult(void);  // 0x801CAF10 (40B)
    void SetHouseNumber(int);  // 0x801CAF38 (172B)
    /* ? */ GetHouseNumber(void);  // 0x801CDE30 (44B)
    /* ? */ GetMUWrapper(void);  // 0x801CDE5C (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (MUStateMachine, MUWrapperStartup, Startup)
    u32 m_field_004;  // 0x004 [W] (MUStateMachine, MUWrapperStartup, Startup)
    u32 m_field_008;  // 0x008 [W] (MUStateMachine, MUWrapperStartup, Startup)
    u32 m_field_00C;  // 0x00C [W] (MUStateMachine, MUWrapperStartup, Startup)
    u32 m_field_010;  // 0x010 [W] (MUStateMachine, MUWrapperStartup, Startup)
    u32 m_field_014;  // 0x014 [W] (MUStateMachine, MUWrapperStartup, Startup)
    u32 m_field_018;  // 0x018 [R/W] (MUStateMachine, MUWrapperStartup, Startup, ...)
    u32 m_field_01C;  // 0x01C [W] (MUStateMachine)
    s16 m_field_020;  // 0x020 [R/W] (MUStateMachine, Startup)
    u8 _pad_022[2];  // 0x022
    u32 m_field_024;  // 0x024 [R/W] (MUStateMachine, Startup)
    f32 m_field_028;  // 0x028 [W] (MUStateMachine, MUWrapperStartup)
    u32 m_field_02C;  // 0x02C [R/W] (MUStateMachine, ~MUStateMachine)
    f32 m_field_030;  // 0x030 [W] (Startup)
    f32 m_field_034;  // 0x034 [W] (Startup)
    u32 m_field_038;  // 0x038 [W] (MUWrapperStartup)
    u32 m_field_03C;  // 0x03C [W] (MUStateMachine)
    u8 _pad_040[8];  // 0x040
    u32 m_field_048;  // 0x048 [W] (MUWrapperStartup)
    u8 _pad_04C[8];  // 0x04C
    u32 m_field_054;  // 0x054 [W] (MUStateMachine)
    u32 m_field_058;  // 0x058 [W] (MUWrapperStartup)
    u8 _pad_05C[8];  // 0x05C
    u32 m_field_064;  // 0x064 [W] (MUStateMachine)
    u32 m_field_068;  // 0x068 [W] (MUWrapperStartup)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (MUWrapperStartup)
    u8 _pad_07C[4];  // 0x07C
    u32 m_field_080;  // 0x080 [W] (MUWrapperStartup)
    u32 m_field_084;  // 0x084 [W] (MUStateMachine, MUWrapperStartup)
    u32 m_field_088;  // 0x088 [W] (MUStateMachine, MUWrapperStartup)
    u32 m_field_08C;  // 0x08C [W] (MUStateMachine, MUWrapperStartup)
    u32 m_field_090;  // 0x090 [W] (MUStateMachine)
    u32 m_field_094;  // 0x094 [W] (MUStateMachine)
    u32 m_field_098;  // 0x098 [R/W] (MUStateMachine, MUWrapperShutdown, MUWrapperStartup)
    u32 m_field_09C;  // 0x09C [W] (MUWrapperStartup)
    u32 m_field_0A0;  // 0x0A0 [W] (MUWrapperStartup)
    u32 m_field_0A4;  // 0x0A4 [W] (MUWrapperStartup)
    u32 m_field_0A8;  // 0x0A8 [W] (MUWrapperStartup)
    u8 _pad_0AC[0x14];  // 0x0AC
    u32 m_field_0C0;  // 0x0C0 [W] (MUWrapperStartup)
    u32 m_field_0C4;  // 0x0C4 [W] (MUWrapperStartup)
    u8 _pad_0C8[0x2C];  // 0x0C8
    u32 m_field_0F4;  // 0x0F4 [W] (MUWrapperStartup)
    u32 m_field_0F8;  // 0x0F8 [W] (MUWrapperStartup)
    u32 m_field_0FC;  // 0x0FC [W] (MUWrapperStartup)
    u32 m_field_100;  // 0x100 [W] (MUWrapperStartup)
    u32 m_field_104;  // 0x104 [W] (MUWrapperStartup)
};

#endif // MUSTATEMACHINE_H
