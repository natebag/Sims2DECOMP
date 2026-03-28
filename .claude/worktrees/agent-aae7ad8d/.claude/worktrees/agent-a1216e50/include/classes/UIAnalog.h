#ifndef UIANALOG_H
#define UIANALOG_H

#include "types.h"

// UIAnalog - struct layout extracted from assembly analysis
// Estimated minimum size: 0x84 (132 bytes)
// 19 known fields (3 named), 6 methods

class UIAnalog {
public:
    // Constructors / Destructors
    UIAnalog(void)  // 0x80495C54
    ~UIAnalog(void);  // 0x80495EFC

    // Methods
    /* ? */ GetVariable(char *);  // 0x80495F50 (812B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_variable;  // 0x000 [R/W] (GetVariable, UIAnalog, ~UIAnalog)
    u8 _pad_001[3];  // 0x001
    u16 m_variable_004;  // 0x004 [R/W] (GetVariable, UIAnalog, ~UIAnalog)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (UIAnalog, ~UIAnalog)
    u32 m_field_00C;  // 0x00C [R/W] (UIAnalog, ~UIAnalog)
    u32 m_field_010;  // 0x010 [R/W] (UIAnalog, ~UIAnalog)
    u32 m_field_014;  // 0x014 [R/W] (UIAnalog, ~UIAnalog)
    u32 m_field_018;  // 0x018 [R/W] (UIAnalog, ~UIAnalog)
    u32 m_field_01C;  // 0x01C [R/W] (UIAnalog, ~UIAnalog)
    u32 m_field_020;  // 0x020 [R/W] (UIAnalog, ~UIAnalog)
    u32 m_field_024;  // 0x024 [R/W] (UIAnalog, ~UIAnalog)
    u32 m_field_028;  // 0x028 [W] (UIAnalog)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (UIAnalog)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (UIAnalog)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (UIAnalog, ~UIAnalog)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (UIAnalog, ~UIAnalog)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (UIAnalog)
    u32 m_field_07C;  // 0x07C [R/W] (UIAnalog, ~UIAnalog)
    u32 m_field_080;  // 0x080 [W] (UIAnalog, ~UIAnalog)
};

#endif // UIANALOG_H
