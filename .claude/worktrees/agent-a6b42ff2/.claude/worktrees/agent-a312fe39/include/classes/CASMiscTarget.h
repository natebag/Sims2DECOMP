#ifndef CASMISCTARGET_H
#define CASMISCTARGET_H

#include "types.h"

// CASMiscTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8C (140 bytes)
// 20 known fields (2 named), 10 methods

class CASMiscTarget {
public:
    // Constructors / Destructors
    CASMiscTarget(void)  // 0x804D4684
    ~CASMiscTarget(void);  // 0x804D48B4

    // Methods
    /* ? */ GetLocalizableSubnav(UIScreenID, int, unsigned wchar_t *);  // 0x804D4AB8 (2356B)
    void SetVariable(char *, char *);  // 0x804D4924 (192B)
    /* ? */ GetVariable(char *);  // 0x804D49E4 (212B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CASMiscTarget, ~CASMiscTarget)
    u32 m_field_004;  // 0x004 [R/W] (CASMiscTarget, ~CASMiscTarget)
    u32 m_field_008;  // 0x008 [R/W] (CASMiscTarget, ~CASMiscTarget)
    u32 m_field_00C;  // 0x00C [R/W] (CASMiscTarget, ~CASMiscTarget)
    u32 m_field_010;  // 0x010 [R/W] (CASMiscTarget, ~CASMiscTarget)
    u32 m_field_014;  // 0x014 [R/W] (CASMiscTarget, ~CASMiscTarget)
    u32 m_field_018;  // 0x018 [R/W] (CASMiscTarget, ~CASMiscTarget)
    u32 m_field_01C;  // 0x01C [R/W] (CASMiscTarget, ~CASMiscTarget)
    u32 m_field_020;  // 0x020 [R/W] (CASMiscTarget, ~CASMiscTarget)
    u32 m_field_024;  // 0x024 [R/W] (CASMiscTarget, ~CASMiscTarget)
    u32 m_field_028;  // 0x028 [W] (CASMiscTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (CASMiscTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (CASMiscTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (CASMiscTarget, ~CASMiscTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (CASMiscTarget, ~CASMiscTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (CASMiscTarget)
    u32 m_field_07C;  // 0x07C [R/W] (CASMiscTarget, ~CASMiscTarget)
    u32 m_field_080;  // 0x080 [W] (CASMiscTarget, ~CASMiscTarget)
    u32 m_localizableSubnav;  // 0x084 [R/W] (CASMiscTarget, GetLocalizableSubnav)
    u32 m_field_088;  // 0x088 [W] (CASMiscTarget, ~CASMiscTarget)
};

#endif // CASMISCTARGET_H
