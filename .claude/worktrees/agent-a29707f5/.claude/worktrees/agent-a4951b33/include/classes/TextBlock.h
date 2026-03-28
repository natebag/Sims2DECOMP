#ifndef TEXTBLOCK_H
#define TEXTBLOCK_H

#include "types.h"

// TextBlock - struct layout extracted from assembly analysis
// Estimated minimum size: 0x4C (76 bytes)
// 19 known fields (11 named), 53 methods

class TextBlock {
public:
    // Constructors / Destructors
    TextBlock(unsigned wchar_t *, EVec2 &, EVec4 *, ERFont *, float, bool, bool, bool)  // 0x80194DC4
    TextBlock(unsigned wchar_t *, EVec2 &, EVec2 &, EVec4 *, ERFont *, float, bool, bool, bool)  // 0x80194E98
    TextBlock(void)  // 0x801A1334
    ~TextBlock(void);  // 0x801A13AC

    // Methods
    void Set(unsigned wchar_t *, EVec2 &, EVec2 &, EVec4 *, ERFont *, float, bool, bool, bool);  // 0x80194F50 (344B)
    void SetDropShadow(bool);  // 0x8019601C (72B)
    void SetVerticalCenter(bool);  // 0x80195FD4 (72B)
    void SetCenterJustify(void);  // 0x80195FA8 (44B)
    void SetDirty(void);  // 0x80196064 (44B)
    void Clear(void);  // 0x801950A8 (396B)
    void DrawWrappedText(ERC *, EVec2 &, float, float);  // 0x80195234 (2492B)
    void DrawText(ERC *, float);  // 0x80195BF0 (380B)
    void CalcSizes(void);  // 0x80195D6C (68B)
    void SetFont(ERFont *);  // 0x8019C194 (156B)
    void SetXPosCentered(bool);  // 0x8019C2A4 (72B)
    void SetYPosCentered(bool);  // 0x8019C2EC (72B)
    void SetLineGap(float);  // 0x8019C37C (40B)
    void SetText(unsigned wchar_t *);  // 0x8019C0B8 (156B)
    void SetColor(EVec4 &);  // 0x8019C154 (64B)
    /* ? */ GetActualSize(void);  // 0x801A16A0 (84B)
    /* ? */ GetColor(void);  // 0x801A16F4 (44B)
    void SetAlpha(float);  // 0x801A1720 (44B)
    /* ? */ GetAlpha(void);  // 0x801A174C (48B)
    void SetShadowAlpha(float);  // 0x801A177C (40B)
    /* ? */ GetShadowAlpha(void);  // 0x801A17A4 (44B)
    void SetShadowSize(float);  // 0x801A17D0 (40B)
    /* ? */ GetShadowSize(void);  // 0x801A17F8 (44B)
    void SetPos(EVec2 &);  // 0x801A1438 (60B)
    /* ? */ GetPos(void);  // 0x801A14C4 (44B)
    void SetPosX(float);  // 0x801A1474 (40B)
    void SetPosY(float);  // 0x801A149C (40B)
    void SetDisplaySize(EVec2 &);  // 0x801A14F0 (84B)
    /* ? */ GetDisplaySize(void);  // 0x801A1544 (44B)
    /* ? */ GetDisplaySizeX(void);  // 0x801A1570 (44B)
    /* ? */ GetDisplaySizeY(void);  // 0x801A159C (44B)
    void SetDisplayPadSize(EVec2 &);  // 0x801A15C8 (84B)
    /* ? */ GetDisplayPadSize(void);  // 0x801A161C (44B)
    /* ? */ GetDisplayPadSizeX(void);  // 0x801A1648 (44B)
    /* ? */ GetDisplayPadSizeY(void);  // 0x801A1674 (44B)
    /* ? */ GetText(void);  // 0x801A140C (44B)
    /* ? */ GetFont(void);  // 0x801A1824 (44B)
    void SetFontSize(float);  // 0x801A1850 (72B)
    /* ? */ GetFontSize(void);  // 0x801A1898 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Clear, DrawWrappedText, Set)
    u32 m_field_004;  // 0x004 [W] (Clear, Set)
    u32 m_field_008;  // 0x008 [W] (Clear, Set)
    f32 m_field_00C;  // 0x00C [R/W] (Clear, DrawText, DrawWrappedText, ...)
    f32 m_field_010;  // 0x010 [R/W] (Clear, DrawText, Set)
    f32 m_wrappedText;  // 0x014 [R/W] (Clear, DrawWrappedText)
    f32 m_text;  // 0x018 [R/W] (Clear, DrawText)
    f32 m_wrappedText_01C;  // 0x01C [R/W] (Clear, DrawWrappedText)
    f32 m_wrappedText_020;  // 0x020 [R/W] (Clear, DrawWrappedText)
    u32 m_field_024;  // 0x024 [R/W] (Clear, DrawWrappedText, Set)
    f32 m_wrappedText_028;  // 0x028 [R/W] (Clear, DrawWrappedText)
    f32 m_wrappedText_02C;  // 0x02C [R/W] (Clear, DrawWrappedText)
    u32 m_field_030;  // 0x030 [R/W] (Clear, DrawWrappedText, Set)
    f32 m_field_034;  // 0x034 [R/W] (Clear, DrawWrappedText, Set)
    u32 m_field_038;  // 0x038 [R/W] (Clear, DrawText, DrawWrappedText, ...)
    u32 m_wrappedText_03C;  // 0x03C [R/W] (Clear, DrawWrappedText)
    u32 m_wrappedText_040;  // 0x040 [R/W] (Clear, DrawWrappedText)
    u32 m_wrappedText_044;  // 0x044 [W] (Clear, DrawWrappedText)
    f32 m_wrappedText_048;  // 0x048 [R/W] (Clear, DrawWrappedText)
};

#endif // TEXTBLOCK_H
