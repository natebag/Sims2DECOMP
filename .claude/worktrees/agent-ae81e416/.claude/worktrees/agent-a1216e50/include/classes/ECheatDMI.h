#ifndef ECHEATDMI_H
#define ECHEATDMI_H

#include "types.h"

// ECheatDMI - struct layout extracted from assembly analysis
// Estimated minimum size: 0x54 (84 bytes)
// 6 known fields (3 named), 14 methods

class ECheatDMI {
public:
    // Constructors / Destructors
    ECheatDMI(ECheatLookup *)  // 0x800569D0

    // Methods
    /* ? */ GetDescription(char *, int);  // 0x80056008 (236B)
    /* ? */ GetValue(char *);  // 0x800560F4 (400B)
    void ButtonPress(EDebugMenuButton);  // 0x80056284 (940B)
    void ButtonPress(EDebugMenuButton, float);  // 0x80056630 (624B)
    /* ? */ GetType(void);  // 0x80056F3C (76B)
    /* ? */ GetVariable(void);  // 0x80056F88 (76B)

    // ---- Field Layout (from assembly analysis) ----
    s16 m_value;  // 0x000 [R/W] (ButtonPress, GetValue)
    u8 _pad_002[2];  // 0x002
    u16 m_value_004;  // 0x004 [W] (GetValue)
    u8 _pad_006[2];  // 0x006
    u32 m_field_008;  // 0x008 [W] (ECheatDMI)
    u32 m_description;  // 0x00C [R/W] (ButtonPress, ECheatDMI, GetDescription, ...)
    u8 _pad_010[0x3C];  // 0x010
    u32 m_field_04C;  // 0x04C [R] (ButtonPress)
    u32 m_field_050;  // 0x050 [R] (ButtonPress)
};

#endif // ECHEATDMI_H
