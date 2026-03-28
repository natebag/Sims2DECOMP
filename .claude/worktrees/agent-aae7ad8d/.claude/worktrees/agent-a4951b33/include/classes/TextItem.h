#ifndef TEXTITEM_H
#define TEXTITEM_H

#include "types.h"

// TextItem - struct layout extracted from assembly analysis
// Estimated minimum size: 0x70 (112 bytes)
// 10 known fields (1 named), 6 methods

class TextItem {
public:
    // Constructors / Destructors
    TextItem(void)  // 0x8019D634
    ~TextItem(void);  // 0x8019D694

    // Methods
    void Startup(void);  // 0x801966DC (96B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (TextItem)
    u32 m_field_004;  // 0x004 [R/W] (Startup, TextItem)
    u32 m_field_008;  // 0x008 [W] (TextItem)
    f32 m_field_00C;  // 0x00C [W] (TextItem)
    f32 m_field_010;  // 0x010 [W] (TextItem)
    f32 m_field_014;  // 0x014 [W] (TextItem)
    f32 m_field_018;  // 0x018 [W] (TextItem)
    u32 m_field_01C;  // 0x01C [W] (TextItem, ~TextItem)
    u8 _pad_020[0x24];  // 0x020
    u32 m_field_044;  // 0x044 [R] (~TextItem)
    u8 _pad_048[0x24];  // 0x048
    u32 m_field_06C;  // 0x06C [W] (TextItem)
};

#endif // TEXTITEM_H
