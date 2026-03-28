#ifndef BUTTONITEM_H
#define BUTTONITEM_H

#include "types.h"

// ButtonItem - struct layout extracted from assembly analysis
// Estimated minimum size: 0x70 (112 bytes)
// 10 known fields (1 named), 6 methods

class ButtonItem {
public:
    // Constructors / Destructors
    ButtonItem(void)  // 0x8019D78C
    ~ButtonItem(void);  // 0x8019D7EC

    // Methods
    void Startup(void);  // 0x8019679C (96B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ButtonItem)
    u32 m_field_004;  // 0x004 [R/W] (ButtonItem, Startup)
    u32 m_field_008;  // 0x008 [W] (ButtonItem)
    f32 m_field_00C;  // 0x00C [W] (ButtonItem)
    f32 m_field_010;  // 0x010 [W] (ButtonItem)
    f32 m_field_014;  // 0x014 [W] (ButtonItem)
    f32 m_field_018;  // 0x018 [W] (ButtonItem)
    u32 m_field_01C;  // 0x01C [W] (ButtonItem, ~ButtonItem)
    u8 _pad_020[0x24];  // 0x020
    u32 m_field_044;  // 0x044 [R] (~ButtonItem)
    u8 _pad_048[0x24];  // 0x048
    u32 m_field_06C;  // 0x06C [W] (ButtonItem)
};

#endif // BUTTONITEM_H
