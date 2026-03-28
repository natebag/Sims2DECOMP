#ifndef QUAD_H
#define QUAD_H

#include "types.h"

// Quad - struct layout extracted from assembly analysis
// Estimated minimum size: 0xF4 (244 bytes)
// 15 known fields (0 named), 10 methods

class Quad {
public:
    // Constructors / Destructors
    Quad(void)  // 0x8004C95C
    ~Quad(void);  // 0x8004C9D0

    // Methods
    void SetCorner(int, EVec3 &);  // 0x8004CA50 (80B)
    /* ? */ GetCorner(int);  // 0x8004CA1C (52B)
    bool IsInQuad(EVec3 *);  // 0x80827568 (328B)
    void PinToQuad(EVec3 *);  // 0x808276B0 (388B)
    void Draw(ERC *, unsigned int);  // 0x80827834 (1172B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (Draw)
    f32 m_field_004;  // 0x004 [R/W] (Draw)
    f32 m_field_008;  // 0x008 [R/W] (Draw)
    f32 m_field_00C;  // 0x00C [R/W] (Draw)
    f32 m_field_010;  // 0x010 [R] (Draw)
    f32 m_field_014;  // 0x014 [R] (Draw)
    f32 m_field_018;  // 0x018 [R] (Draw)
    f32 m_field_01C;  // 0x01C [R] (Draw)
    f32 m_field_020;  // 0x020 [R] (Draw)
    f32 m_field_024;  // 0x024 [R] (Draw)
    f32 m_field_028;  // 0x028 [R] (Draw)
    f32 m_field_02C;  // 0x02C [R] (Draw)
    u8 _pad_030[0x20];  // 0x030
    f32 m_field_050;  // 0x050 [W] (Draw)
    u8 _pad_054[0x4C];  // 0x054
    f32 m_field_0A0;  // 0x0A0 [W] (Draw)
    u8 _pad_0A4[0x4C];  // 0x0A4
    f32 m_field_0F0;  // 0x0F0 [W] (Draw)
};

#endif // QUAD_H
