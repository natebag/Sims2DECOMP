#ifndef ICONITEM_H
#define ICONITEM_H

#include "types.h"

// IconItem - struct layout extracted from assembly analysis
// Estimated minimum size: 0x34 (52 bytes)
// 11 known fields (4 named), 26 methods

class IconItem {
public:
    // Constructors / Destructors
    IconItem(void)  // 0x8019D838
    ~IconItem(void);  // 0x8019D8D0

    // Methods
    void Startup(void);  // 0x801967FC (64B)
    void Shutdown(void);  // 0x8019683C (56B)
    void ReleaseShader(void);  // 0x80196A88 (84B)
    void Draw(ERC *, float);  // 0x80196874 (256B)
    void SetShader(unsigned int);  // 0x80196974 (276B)
    void SetColor(EVec4 &);  // 0x8019D91C (104B)
    /* ? */ GetColor(void);  // 0x8019D984 (104B)
    void SetAlpha(float);  // 0x8019D9EC (40B)
    /* ? */ GetAlpha(void);  // 0x8019DA14 (44B)
    void SetShader(ERShader *);  // 0x8019DA40 (40B)
    /* ? */ GetShader(void);  // 0x8019DA68 (44B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_color;  // 0x000 [W] (GetColor, IconItem)
    f32 m_color_004;  // 0x004 [R/W] (Draw, GetColor, IconItem)
    f32 m_color_008;  // 0x008 [W] (GetColor, IconItem)
    f32 m_color_00C;  // 0x00C [W] (GetColor, IconItem)
    f32 m_field_010;  // 0x010 [W] (IconItem)
    f32 m_field_014;  // 0x014 [W] (IconItem)
    f32 m_field_018;  // 0x018 [W] (IconItem)
    u32 m_field_01C;  // 0x01C [R/W] (Draw, IconItem, ~IconItem)
    f32 m_field_020;  // 0x020 [R/W] (Draw, IconItem)
    u8 _pad_024[8];  // 0x024
    f32 m_field_02C;  // 0x02C [R/W] (Draw, IconItem)
    u32 m_field_030;  // 0x030 [R/W] (Draw, IconItem)
};

#endif // ICONITEM_H
