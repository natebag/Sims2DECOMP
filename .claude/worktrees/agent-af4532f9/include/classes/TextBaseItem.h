#ifndef TEXTBASEITEM_H
#define TEXTBASEITEM_H

#include "types.h"

// TextBaseItem - struct layout extracted from assembly analysis
// Estimated minimum size: 0x6324 (25380 bytes)
// 14 known fields (9 named), 76 methods

class TextBaseItem {
public:
    // Constructors / Destructors
    TextBaseItem(ItemType)  // 0x8019CBEC
    ~TextBaseItem(void);  // 0x8019CC64

    // Methods
    void SetVerticalCenter(bool);  // 0x8019D3A4 (68B)
    void SetYPosCentered(bool);  // 0x8019D3E8 (68B)
    /* ? */ GetText(void);  // 0x8019D42C (72B)
    void SetDisplaySize(EVec2 &);  // 0x8019D16C (68B)
    void SetStyle(ItemStyle);  // 0x80196574 (360B)
    void Startup(void);  // 0x8019631C (160B)
    void Draw(ERC *, float);  // 0x801963BC (248B)
    /* ? */ GetStyle(void);  // 0x8019D608 (44B)
    /* ? */ GetFontSize(void);  // 0x8019D5C0 (72B)
    void SetFontSize(float);  // 0x8019D568 (88B)
    void SetText(unsigned wchar_t *);  // 0x801964B4 (192B)
    void SetFont(ERFont *);  // 0x8019D474 (172B)
    /* ? */ GetFont(void);  // 0x8019D520 (72B)
    void Reset(void);  // 0x8019CCC0 (56B)
    void CalculateSize(void);  // 0x8019CCF8 (112B)
    void SetPos(EVec2 &);  // 0x8019CFB0 (68B)
    /* ? */ GetPos(void);  // 0x8019CFF4 (72B)
    void SetPosX(float);  // 0x8019D03C (76B)
    void SetPosY(float);  // 0x8019D0D4 (76B)
    void SetColor(EVec4 &);  // 0x8019CD68 (68B)
    /* ? */ GetColor(void);  // 0x8019CDAC (72B)
    void SetAlpha(float);  // 0x8019CDF4 (76B)
    /* ? */ GetAlpha(void);  // 0x8019CE40 (72B)
    void SetShadowAlpha(float);  // 0x8019CE88 (76B)
    /* ? */ GetShadowAlpha(void);  // 0x8019CED4 (72B)
    void SetShadowSize(float);  // 0x8019CF1C (76B)
    /* ? */ GetShadowSize(void);  // 0x8019CF68 (72B)
    /* ? */ GetPosX(void);  // 0x8019D088 (76B)
    /* ? */ GetPosY(void);  // 0x8019D120 (76B)
    /* ? */ GetDisplaySize(void);  // 0x8019D1B0 (72B)
    /* ? */ GetDisplaySizeX(void);  // 0x8019D1F8 (72B)
    /* ? */ GetDisplaySizeY(void);  // 0x8019D240 (72B)
    void SetDisplayPadSize(EVec2 &);  // 0x8019D288 (68B)
    /* ? */ GetDisplayPadSize(void);  // 0x8019D2CC (72B)
    /* ? */ GetDisplayPadSizeX(void);  // 0x8019D314 (72B)
    /* ? */ GetDisplayPadSizeY(void);  // 0x8019D35C (72B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (TextBaseItem)
    f32 m_style;  // 0x004 [R/W] (Draw, SetStyle, SetText, ...)
    f32 m_style_008;  // 0x008 [R/W] (SetStyle, TextBaseItem)
    f32 m_style_00C;  // 0x00C [R/W] (SetStyle, TextBaseItem)
    f32 m_field_010;  // 0x010 [W] (TextBaseItem)
    f32 m_field_014;  // 0x014 [W] (TextBaseItem)
    f32 m_field_018;  // 0x018 [W] (TextBaseItem)
    u32 m_field_01C;  // 0x01C [R/W] (CalculateSize, TextBaseItem, ~TextBaseItem)
    u32 m_text;  // 0x020 [W] (SetText)
    u32 m_style_024;  // 0x024 [R] (SetStyle)
    u8 _pad_028[0x10];  // 0x028
    u32 m_style_038;  // 0x038 [R/W] (CalculateSize, SetStyle)
    u8 _pad_03C[8];  // 0x03C
    u32 m_field_044;  // 0x044 [R] (~TextBaseItem)
    u8 _pad_048[0x24];  // 0x048
    u32 m_style_06C;  // 0x06C [R/W] (Draw, SetStyle, TextBaseItem)
    u8 _pad_070[0x62B0];  // 0x070
    f32 m_style_6320;  // 0x6320 [R] (SetStyle)
};

#endif // TEXTBASEITEM_H
