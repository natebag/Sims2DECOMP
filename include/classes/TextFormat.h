#ifndef TEXTFORMAT_H
#define TEXTFORMAT_H

#include "types.h"

// TextFormat - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 7 known fields (0 named), 6 methods

class TextFormat {
public:
    // Constructors / Destructors
    TextFormat(TextFormat *)  // 0x806D1F78
    TextFormat(AptValue *, float, unsigned int, int, int, int, int, int, AptValue *, int, int, int, int)  // 0x806D1D5C
    ~TextFormat(void);  // 0x806D1D04

    // Methods
    void copyTextFormatObj(TextFormat *);  // 0x806D200C (256B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    f32 m_field_004;  // 0x004 [W] (copyTextFormatObj)
    u32 m_field_008;  // 0x008 [W] (copyTextFormatObj)
    u32 m_field_00C;  // 0x00C [W] (copyTextFormatObj)
    u32 m_field_010;  // 0x010 [W] (copyTextFormatObj)
    u32 m_field_014;  // 0x014 [W] (copyTextFormatObj)
    u32 m_field_018;  // 0x018 [W] (copyTextFormatObj)
    u32 m_field_01C;  // 0x01C [W] (copyTextFormatObj)
};

#endif // TEXTFORMAT_H
