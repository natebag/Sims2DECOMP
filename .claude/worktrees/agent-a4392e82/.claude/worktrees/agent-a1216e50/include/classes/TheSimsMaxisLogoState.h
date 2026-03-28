#ifndef THESIMSMAXISLOGOSTATE_H
#define THESIMSMAXISLOGOSTATE_H

#include "types.h"

// TheSimsMaxisLogoState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x6178 (24952 bytes)
// 31 known fields (1 named), 14 methods

class TheSimsMaxisLogoState {
public:
    // Constructors / Destructors
    TheSimsMaxisLogoState(int)  // 0x801E8E7C
    ~TheSimsMaxisLogoState(void);  // 0x801E8F04

    // Methods
    void Startup(void);  // 0x801DFFE8 (604B)
    void Shutdown(void);  // 0x801E0244 (152B)
    void Reset(void);  // 0x801E02DC (264B)
    void Update(float);  // 0x801E03E4 (276B)
    void Draw(ERC *);  // 0x801E04F8 (360B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (Startup)
    f32 m_field_004;  // 0x004 [W] (Draw, Startup)
    u32 m_field_008;  // 0x008 [R/W] (Startup, Update)
    f32 m_field_00C;  // 0x00C [W] (Startup)
    f32 m_field_010;  // 0x010 [W] (Startup)
    f32 m_field_014;  // 0x014 [W] (Startup)
    f32 m_field_018;  // 0x018 [W] (Startup)
    f32 m_field_01C;  // 0x01C [R/W] (Draw, Reset, Shutdown, ...)
    f32 m_field_020;  // 0x020 [R/W] (Reset, Shutdown, Startup, ...)
    f32 m_field_024;  // 0x024 [R/W] (Reset, Startup, Update)
    f32 m_field_028;  // 0x028 [W] (Startup)
    f32 m_field_02C;  // 0x02C [W] (Startup)
    f32 m_field_030;  // 0x030 [W] (Startup)
    u32 m_field_034;  // 0x034 [W] (Startup)
    u32 m_field_038;  // 0x038 [W] (Startup)
    u32 m_field_03C;  // 0x03C [W] (Startup)
    u8 _pad_040[8];  // 0x040
    u32 m_field_048;  // 0x048 [W] (Startup)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [W] (Startup)
    u32 m_field_05C;  // 0x05C [W] (Startup)
    u8 _pad_060[8];  // 0x060
    u32 m_field_068;  // 0x068 [W] (Startup)
    u32 m_field_06C;  // 0x06C [W] (Startup)
    u8 _pad_070[8];  // 0x070
    u32 m_field_078;  // 0x078 [W] (Startup)
    u8 _pad_07C[4];  // 0x07C
    u32 m_field_080;  // 0x080 [W] (Startup)
    u32 m_field_084;  // 0x084 [W] (Startup)
    u32 m_field_088;  // 0x088 [W] (Startup)
    u32 m_field_08C;  // 0x08C [W] (Startup)
    u8 _pad_090[0xC];  // 0x090
    u32 m_field_09C;  // 0x09C [W] (Startup)
    u32 m_field_0A0;  // 0x0A0 [W] (Startup)
    u8 _pad_0A4[0x4C];  // 0x0A4
    u32 m_field_0F0;  // 0x0F0 [R] (Draw)
    u8 _pad_0F4[0x10];  // 0x0F4
    u32 m_field_104;  // 0x104 [R] (Startup)
    u8 _pad_108[0x606C];  // 0x108
    u32 m_field_6174;  // 0x6174 [R] (Startup)
};

#endif // THESIMSMAXISLOGOSTATE_H
