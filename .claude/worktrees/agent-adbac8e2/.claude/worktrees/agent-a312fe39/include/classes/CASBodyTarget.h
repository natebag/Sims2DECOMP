#ifndef CASBODYTARGET_H
#define CASBODYTARGET_H

#include "types.h"

// CASBodyTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8C (140 bytes)
// 20 known fields (1 named), 18 methods

class CASBodyTarget {
public:
    // Constructors / Destructors
    CASBodyTarget(void)  // 0x804CD47C
    ~CASBodyTarget(void);  // 0x804CD6AC

    // Methods
    /* ? */ GetLocalizableSubnav(int, unsigned wchar_t *);  // 0x804CD888 (780B)
    void SetVariableSubnav(int, int);  // 0x804CD7DC (172B)
    void SetVariable(char *, char *);  // 0x804CD71C (192B)
    void HandleHairSubnav(int);  // 0x804CDB94 (236B)
    void HandleBodyTypeSubnav(int);  // 0x804CDC80 (252B)
    void HandleSkinColorSubnav(int);  // 0x804CDD7C (252B)
    /* ? */ GetVariable(char *);  // 0x804CDE78 (212B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CASBodyTarget, ~CASBodyTarget)
    u32 m_field_004;  // 0x004 [R/W] (CASBodyTarget, ~CASBodyTarget)
    u32 m_field_008;  // 0x008 [R/W] (CASBodyTarget, ~CASBodyTarget)
    u32 m_field_00C;  // 0x00C [R/W] (CASBodyTarget, ~CASBodyTarget)
    u32 m_field_010;  // 0x010 [R/W] (CASBodyTarget, ~CASBodyTarget)
    u32 m_field_014;  // 0x014 [R/W] (CASBodyTarget, ~CASBodyTarget)
    u32 m_field_018;  // 0x018 [R/W] (CASBodyTarget, ~CASBodyTarget)
    u32 m_field_01C;  // 0x01C [R/W] (CASBodyTarget, ~CASBodyTarget)
    u32 m_field_020;  // 0x020 [R/W] (CASBodyTarget, ~CASBodyTarget)
    u32 m_field_024;  // 0x024 [R/W] (CASBodyTarget, ~CASBodyTarget)
    u32 m_field_028;  // 0x028 [W] (CASBodyTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (CASBodyTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (CASBodyTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (CASBodyTarget, ~CASBodyTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (CASBodyTarget, ~CASBodyTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (CASBodyTarget)
    u32 m_field_07C;  // 0x07C [R/W] (CASBodyTarget, ~CASBodyTarget)
    u32 m_field_080;  // 0x080 [W] (CASBodyTarget, ~CASBodyTarget)
    u32 m_field_084;  // 0x084 [R/W] (CASBodyTarget, HandleBodyTypeSubnav, HandleHairSubnav, ...)
    u32 m_field_088;  // 0x088 [W] (CASBodyTarget, ~CASBodyTarget)
};

#endif // CASBODYTARGET_H
