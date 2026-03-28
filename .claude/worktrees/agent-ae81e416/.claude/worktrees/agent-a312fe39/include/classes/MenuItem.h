#ifndef MENUITEM_H
#define MENUITEM_H

#include "types.h"

// MenuItem - struct layout extracted from assembly analysis
// Estimated minimum size: 0x70 (112 bytes)
// 10 known fields (1 named), 6 methods

class MenuItem {
public:
    // Constructors / Destructors
    MenuItem(void)  // 0x8019D6E0
    ~MenuItem(void);  // 0x8019D740

    // Methods
    void Startup(void);  // 0x8019673C (96B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (MenuItem)
    u32 m_field_004;  // 0x004 [R/W] (MenuItem, Startup)
    u32 m_field_008;  // 0x008 [W] (MenuItem)
    f32 m_field_00C;  // 0x00C [W] (MenuItem)
    f32 m_field_010;  // 0x010 [W] (MenuItem)
    f32 m_field_014;  // 0x014 [W] (MenuItem)
    f32 m_field_018;  // 0x018 [W] (MenuItem)
    u32 m_field_01C;  // 0x01C [W] (MenuItem, ~MenuItem)
    u8 _pad_020[0x24];  // 0x020
    u32 m_field_044;  // 0x044 [R] (~MenuItem)
    u8 _pad_048[0x24];  // 0x048
    u32 m_field_06C;  // 0x06C [W] (MenuItem)
};

#endif // MENUITEM_H
