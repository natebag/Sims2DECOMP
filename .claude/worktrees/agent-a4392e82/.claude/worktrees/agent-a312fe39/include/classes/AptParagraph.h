#ifndef APTPARAGRAPH_H
#define APTPARAGRAPH_H

#include "types.h"

// AptParagraph - struct layout extracted from assembly analysis
// Estimated minimum size: 0x68 (104 bytes)
// 15 known fields (2 named), 18 methods

class AptParagraph {
public:
    // Constructors / Destructors
    AptParagraph(void)  // 0x80019530
    ~AptParagraph(void);  // 0x80019F28

    // Methods
    void Build(EVec2 &, EVec2 &, float, EVec4 &, AptStringAlignment, unsigned wchar_t *);  // 0x8001E654 (12428B)
    void Draw(ERC *, EMat4 *, EVec4 *, EVec4 *);  // 0x8001E544 (148B)
    void AddLine(AptLine *);  // 0x8001E5D8 (124B)
    /* ? */ GetWideHexValue(unsigned wchar_t *, int, int);  // 0x80021738 (828B)
    /* ? */ GetParagraphHeight(void);  // 0x800216E0 (44B)
    /* ? */ GetPrintWidth(void);  // 0x8002170C (44B)
    void SetFormattingEnable(int);  // 0x80021A74 (232B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_formattingEnable;  // 0x000 [R/W] (Build, Draw, SetFormattingEnable, ...)
    u8 _pad_002[2];  // 0x002
    u32 m_formattingEnable_004;  // 0x004 [R/W] (Build, SetFormattingEnable)
    u32 m_field_008;  // 0x008 [R/W] (Build)
    u32 m_field_00C;  // 0x00C [R/W] (Build, ~AptParagraph)
    u32 m_field_010;  // 0x010 [W] (Build)
    u32 m_field_014;  // 0x014 [R/W] (Build)
    u32 m_field_018;  // 0x018 [R/W] (Build)
    u32 m_field_01C;  // 0x01C [W] (Build)
    f32 m_field_020;  // 0x020 [R/W] (Build)
    f32 m_field_024;  // 0x024 [R/W] (Build)
    f32 m_field_028;  // 0x028 [R/W] (Build)
    f32 m_field_02C;  // 0x02C [R/W] (Build)
    f32 m_field_030;  // 0x030 [R/W] (Build)
    u32 m_field_034;  // 0x034 [W] (~AptParagraph)
    u8 _pad_038[0x2C];  // 0x038
    u32 m_field_064;  // 0x064 [R/W] (Build)
};

#endif // APTPARAGRAPH_H
