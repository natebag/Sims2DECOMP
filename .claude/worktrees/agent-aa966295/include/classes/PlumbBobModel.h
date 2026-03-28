#ifndef PLUMBBOBMODEL_H
#define PLUMBBOBMODEL_H

#include "types.h"

// PlumbBobModel - struct layout extracted from assembly analysis
// Estimated minimum size: 0x3C (60 bytes)
// 14 known fields (8 named), 15 methods

class PlumbBobModel {
public:
    // Constructors / Destructors
    PlumbBobModel(void)  // 0x8012376C
    ~PlumbBobModel(void);  // 0x8012383C

    // Methods
    /* ? */ GetModel(void);  // 0x80122A64 (44B)
    void SetModel(unsigned int);  // 0x801238D8 (196B)
    void Draw(ERC *);  // 0x80123B40 (956B)
    void SetShadow(unsigned int);  // 0x8012399C (196B)
    void DrawShadow(ERC *);  // 0x80123A60 (224B)
    /* ? */ GetExtents(EVec2 &);  // 0x80123EFC (392B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_extents;  // 0x000 [R] (Draw, GetExtents)
    f32 m_extents_004;  // 0x004 [R] (Draw, GetExtents)
    f32 m_shadow;  // 0x008 [R] (Draw, SetModel, SetShadow)
    f32 m_shadow_00C;  // 0x00C [R] (Draw, DrawShadow)
    u8 _pad_010[4];  // 0x010
    f32 m_extents_014;  // 0x014 [R] (GetExtents)
    f32 m_extents_018;  // 0x018 [R] (Draw, GetExtents)
    f32 m_field_01C;  // 0x01C [R/W] (Draw)
    u32 m_field_020;  // 0x020 [R] (Draw)
    u32 m_field_024;  // 0x024 [R] (Draw)
    u32 m_extents_028;  // 0x028 [R/W] (Draw, GetExtents, SetModel, ...)
    u32 m_shadow_02C;  // 0x02C [R/W] (DrawShadow, SetShadow, ~PlumbBobModel)
    f32 m_field_030;  // 0x030 [R/W] (Draw)
    f32 m_field_034;  // 0x034 [R/W] (Draw)
    u32 m_field_038;  // 0x038 [R/W] (Draw)
};

#endif // PLUMBBOBMODEL_H
