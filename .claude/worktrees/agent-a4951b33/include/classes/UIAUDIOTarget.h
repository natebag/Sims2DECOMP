#ifndef UIAUDIOTARGET_H
#define UIAUDIOTARGET_H

#include "types.h"

// UIAUDIOTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x84 (132 bytes)
// 18 known fields (2 named), 6 methods

class UIAUDIOTarget {
public:
    // Constructors / Destructors
    UIAUDIOTarget(void)  // 0x8049581C
    ~UIAUDIOTarget(void);  // 0x80495A44

    // Methods
    void SetVariable(char *, char *);  // 0x80495A98 (444B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (UIAUDIOTarget, ~UIAUDIOTarget)
    u32 m_field_004;  // 0x004 [R/W] (UIAUDIOTarget, ~UIAUDIOTarget)
    u32 m_field_008;  // 0x008 [R/W] (UIAUDIOTarget, ~UIAUDIOTarget)
    u32 m_field_00C;  // 0x00C [R/W] (UIAUDIOTarget, ~UIAUDIOTarget)
    u32 m_field_010;  // 0x010 [R/W] (UIAUDIOTarget, ~UIAUDIOTarget)
    u32 m_field_014;  // 0x014 [R/W] (UIAUDIOTarget, ~UIAUDIOTarget)
    u32 m_field_018;  // 0x018 [R/W] (UIAUDIOTarget, ~UIAUDIOTarget)
    u32 m_field_01C;  // 0x01C [R/W] (UIAUDIOTarget, ~UIAUDIOTarget)
    u32 m_field_020;  // 0x020 [R/W] (UIAUDIOTarget, ~UIAUDIOTarget)
    u32 m_variable;  // 0x024 [R/W] (SetVariable, UIAUDIOTarget, ~UIAUDIOTarget)
    u32 m_field_028;  // 0x028 [W] (UIAUDIOTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (UIAUDIOTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (UIAUDIOTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (UIAUDIOTarget, ~UIAUDIOTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (UIAUDIOTarget, ~UIAUDIOTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (UIAUDIOTarget)
    u32 m_field_07C;  // 0x07C [R/W] (UIAUDIOTarget, ~UIAUDIOTarget)
    u32 m_field_080;  // 0x080 [W] (UIAUDIOTarget, ~UIAUDIOTarget)
};

#endif // UIAUDIOTARGET_H
