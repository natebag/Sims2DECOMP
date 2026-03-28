#ifndef THESIMSNGCLICENSESTATE_H
#define THESIMSNGCLICENSESTATE_H

#include "types.h"

// TheSimsNGCLicenseState - struct layout extracted from assembly analysis
// Estimated minimum size: 0xF4 (244 bytes)
// 27 known fields (0 named), 12 methods

class TheSimsNGCLicenseState {
public:
    // Constructors / Destructors
    TheSimsNGCLicenseState(int)  // 0x801E8C30
    ~TheSimsNGCLicenseState(void);  // 0x801E8CB8

    // Methods
    void Startup(void);  // 0x801DF334 (572B)
    void Shutdown(void);  // 0x801DF570 (92B)
    void Update(float);  // 0x801DF5CC (328B)
    void Draw(ERC *);  // 0x801DF714 (800B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    f32 m_field_004;  // 0x004 [W] (Draw)
    f32 m_field_008;  // 0x008 [R/W] (Draw, Update)
    f32 m_field_00C;  // 0x00C [W] (Draw)
    u8 _pad_010[0xC];  // 0x010
    u32 m_field_01C;  // 0x01C [R/W] (Draw, Startup)
    u16 m_field_020;  // 0x020 [W] (Startup)
    u16 m_field_022;  // 0x022 [W] (Startup)
    u16 m_field_024;  // 0x024 [W] (Startup)
    u16 m_field_026;  // 0x026 [W] (Startup)
    u16 m_field_028;  // 0x028 [W] (Startup)
    u16 m_field_02A;  // 0x02A [W] (Startup)
    u16 m_field_02C;  // 0x02C [W] (Startup)
    u16 m_field_02E;  // 0x02E [W] (Startup)
    u16 m_field_030;  // 0x030 [W] (Startup)
    u16 m_field_032;  // 0x032 [W] (Startup)
    u16 m_field_034;  // 0x034 [W] (Startup)
    u16 m_field_036;  // 0x036 [W] (Startup)
    u16 m_field_038;  // 0x038 [W] (Startup)
    u16 m_field_03A;  // 0x03A [W] (Startup)
    u16 m_field_03C;  // 0x03C [W] (Startup)
    u16 m_field_03E;  // 0x03E [W] (Startup)
    u16 m_field_040;  // 0x040 [W] (Startup)
    u16 m_field_042;  // 0x042 [W] (Startup)
    u16 m_field_044;  // 0x044 [W] (Startup)
    u16 m_field_046;  // 0x046 [W] (Startup)
    u16 m_field_048;  // 0x048 [W] (Startup)
    u8 _pad_04A[2];  // 0x04A
    f32 m_field_04C;  // 0x04C [R/W] (Draw, Startup, Update)
    u8 _pad_050[0xA0];  // 0x050
    u32 m_field_0F0;  // 0x0F0 [R] (Draw)
};

#endif // THESIMSNGCLICENSESTATE_H
