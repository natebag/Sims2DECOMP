#ifndef UIQDTARGET_H
#define UIQDTARGET_H

#include "types.h"

// UIQDTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x84 (132 bytes)
// 18 known fields (1 named), 12 methods

class UIQDTarget {
public:
    // Constructors / Destructors
    UIQDTarget(void)  // 0x8048B9B8
    ~UIQDTarget(void);  // 0x8048BBE0

    // Methods
    /* ? */ GetQuickdataText(char *);  // 0x8048C2E8 (1572B)
    void UIQDSubstitutionStrings(unsigned wchar_t *);  // 0x8048C90C (4704B)
    /* ? */ GetVariable(char *);  // 0x8048BC44 (1700B)
    void UIQDRemoveEmbeddedControl(unsigned wchar_t *);  // 0x8048DB6C (984B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_variable;  // 0x000 [R/W] (GetVariable, UIQDSubstitutionStrings, UIQDTarget, ...)
    u8 _pad_002[2];  // 0x002
    u32 m_field_004;  // 0x004 [R/W] (UIQDTarget, ~UIQDTarget)
    u32 m_field_008;  // 0x008 [R/W] (UIQDTarget, ~UIQDTarget)
    u32 m_field_00C;  // 0x00C [R/W] (UIQDTarget, ~UIQDTarget)
    u32 m_field_010;  // 0x010 [R/W] (UIQDTarget, ~UIQDTarget)
    u32 m_field_014;  // 0x014 [R/W] (UIQDTarget, ~UIQDTarget)
    u32 m_field_018;  // 0x018 [R/W] (UIQDTarget, ~UIQDTarget)
    u32 m_field_01C;  // 0x01C [R/W] (UIQDTarget, ~UIQDTarget)
    u32 m_field_020;  // 0x020 [R/W] (UIQDTarget, ~UIQDTarget)
    u32 m_field_024;  // 0x024 [R/W] (UIQDTarget, ~UIQDTarget)
    u32 m_field_028;  // 0x028 [W] (UIQDTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (UIQDTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (UIQDTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (UIQDTarget, ~UIQDTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (UIQDTarget, ~UIQDTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (UIQDTarget)
    u32 m_field_07C;  // 0x07C [R/W] (UIQDTarget, ~UIQDTarget)
    u32 m_field_080;  // 0x080 [W] (UIQDTarget, ~UIQDTarget)
};

#endif // UIQDTARGET_H
