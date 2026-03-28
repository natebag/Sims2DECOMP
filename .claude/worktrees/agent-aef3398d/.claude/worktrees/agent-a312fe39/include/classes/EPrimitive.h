#ifndef EPRIMITIVE_H
#define EPRIMITIVE_H

#include "types.h"

// EPrimitive - struct layout extracted from assembly analysis
// Estimated minimum size: 0x74 (116 bytes)
// 12 known fields (0 named), 24 methods

class EPrimitive {
public:
    // Methods
    void WireBox(ERC *, EBound3 &, EVec4);  // 0x807C84E8 (1808B)
    void Rect(ERC *, float, float);  // 0x807C5DD4 (744B)
    void Vector(ERC *, EVec3, EVec3, EVec4);  // 0x807C6C94 (1656B)
    void Sphere(ERC *, EBoundSphere &, int, int, int, EVec4);  // 0x807C46CC (2512B)
    void Axis(ERC *, float);  // 0x807C6A0C (648B)
    void Torus(ERC *, float, float, int, int, int, int);  // 0x807C3D10 (2492B)
    void SpherePacked(ERC *, EBoundSphere &, int, int, int, EVec4);  // 0x807C509C (3384B)
    void Grid(ERC *, float, float, int, int, int, int);  // 0x807C60BC (1448B)
    void WireRect(ERC *, float, float, EVec4);  // 0x807C6664 (936B)
    void Cube(ERC *, float);  // 0x807C730C (4572B)
    void WireCircle(ERC *, float, int, EVec4, int, EVec3);  // 0x807C8BF8 (1064B)
    void WireSphere(ERC *, EBoundSphere &, EVec4, int, int);  // 0x807C9020 (572B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R] (Sphere, SpherePacked)
    f32 m_field_004;  // 0x004 [R/W] (Sphere, SpherePacked, Torus, ...)
    f32 m_field_008;  // 0x008 [R/W] (Sphere, SpherePacked, Torus, ...)
    f32 m_field_00C;  // 0x00C [R] (Sphere, SpherePacked, Vector)
    u8 _pad_010[0x10];  // 0x010
    f32 m_field_020;  // 0x020 [R] (SpherePacked)
    f32 m_field_024;  // 0x024 [R] (SpherePacked)
    u8 _pad_028[0xB];  // 0x028
    u8 m_field_033;  // 0x033 [R] (SpherePacked)
    u8 _pad_034[3];  // 0x034
    u8 m_field_037;  // 0x037 [R] (SpherePacked)
    u8 _pad_038[3];  // 0x038
    u8 m_field_03B;  // 0x03B [R] (SpherePacked)
    u8 _pad_03C[3];  // 0x03C
    u8 m_field_03F;  // 0x03F [R] (SpherePacked)
    u8 _pad_040[0x10];  // 0x040
    f32 m_field_050;  // 0x050 [R] (Sphere, SpherePacked)
    u8 _pad_054[0x1C];  // 0x054
    u32 m_field_070;  // 0x070 [R] (Axis, Cube, Grid, ...)
};

#endif // EPRIMITIVE_H
