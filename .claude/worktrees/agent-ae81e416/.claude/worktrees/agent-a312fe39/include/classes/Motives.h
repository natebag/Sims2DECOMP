#ifndef MOTIVES_H
#define MOTIVES_H

#include "types.h"

// Motives - struct layout extracted from assembly analysis
// Estimated minimum size: 0x84 (132 bytes)
// 12 known fields (0 named), 7 methods

class Motives {
public:
    // Constructors / Destructors
    Motives(void)  // 0x80278494

    // Methods
    void Init(void);  // 0x8025E784 (268B)
    void Sim(void);  // 0x8025E890 (1432B)
    void Cleanup(void);  // 0x8025EE28 (344B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (Init, Sim)
    u32 m_field_004;  // 0x004 [R] (Cleanup, Sim)
    u8 _pad_008[0xC];  // 0x008
    f32 m_field_014;  // 0x014 [R/W] (Sim)
    f32 m_field_018;  // 0x018 [R/W] (Sim)
    f32 m_field_01C;  // 0x01C [R/W] (Sim)
    f32 m_field_020;  // 0x020 [R/W] (Sim)
    f32 m_field_024;  // 0x024 [R/W] (Sim)
    u8 _pad_028[4];  // 0x028
    f32 m_field_02C;  // 0x02C [R] (Sim)
    u8 _pad_030[8];  // 0x030
    f32 m_field_038;  // 0x038 [R/W] (Sim)
    f32 m_field_03C;  // 0x03C [R/W] (Sim)
    u8 _pad_040[0x1C];  // 0x040
    f32 m_field_05C;  // 0x05C [R] (Sim)
    u8 _pad_060[0x20];  // 0x060
    u32 m_field_080;  // 0x080 [R/W] (Cleanup, Init, Sim)
};

#endif // MOTIVES_H
