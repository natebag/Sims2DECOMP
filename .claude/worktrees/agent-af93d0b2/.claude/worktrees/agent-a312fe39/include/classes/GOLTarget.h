#ifndef GOLTARGET_H
#define GOLTARGET_H

#include "types.h"

// GOLTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x5C60 (23648 bytes)
// 31 known fields (12 named), 22 methods

class GOLTarget {
public:
    // Constructors / Destructors
    GOLTarget(int)  // 0x8056B0D4
    ~GOLTarget(void);  // 0x8056BAB4

    // Methods
    void InstallMapShader(void);  // 0x8056D6F0 (152B)
    void SetVariable(char *, char *);  // 0x8056BC1C (640B)
    bool IsMapGoalUnlocked(int, int, int);  // 0x8056BE9C (240B)
    bool IsHouseUnlocked(int, int);  // 0x8056BF8C (240B)
    bool IsApartmentUnlocked(int, int);  // 0x8056C07C (240B)
    /* ? */ GetVariable(char *);  // 0x8056C16C (2224B)
    /* ? */ GetLocalizable(char *);  // 0x8056CA1C (3284B)
    void Update(void);  // 0x8056D788 (32B)
    void Draw(ERC *);  // 0x8056D7A8 (36B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (GOLTarget, GetLocalizable, GetVariable, ...)
    u8 m_variable;  // 0x001 [W] (GetVariable)
    u8 _pad_002[2];  // 0x002
    u16 m_variable_004;  // 0x004 [R/W] (GOLTarget, GetVariable, ~GOLTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (GOLTarget, ~GOLTarget)
    u32 m_field_00C;  // 0x00C [R/W] (GOLTarget, ~GOLTarget)
    u32 m_field_010;  // 0x010 [R/W] (GOLTarget, ~GOLTarget)
    u32 m_field_014;  // 0x014 [R/W] (GOLTarget, ~GOLTarget)
    u32 m_field_018;  // 0x018 [R/W] (GOLTarget, ~GOLTarget)
    u32 m_field_01C;  // 0x01C [R/W] (GOLTarget, InstallMapShader, ~GOLTarget)
    u32 m_field_020;  // 0x020 [R/W] (GOLTarget, ~GOLTarget)
    u32 m_field_024;  // 0x024 [R/W] (GOLTarget, ~GOLTarget)
    u32 m_field_028;  // 0x028 [W] (GOLTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (GOLTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (GOLTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (GOLTarget, ~GOLTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (GOLTarget, ~GOLTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (GOLTarget)
    u32 m_field_07C;  // 0x07C [R/W] (GOLTarget, InstallMapShader, ~GOLTarget)
    u32 m_field_080;  // 0x080 [W] (GOLTarget, ~GOLTarget)
    u32 m_field_084;  // 0x084 [W] (GOLTarget)
    u32 m_field_088;  // 0x088 [W] (GOLTarget)
    u32 m_variable_08C;  // 0x08C [R/W] (GOLTarget, GetLocalizable, GetVariable, ...)
    u32 m_field_090;  // 0x090 [W] (GOLTarget)
    u32 m_variable_094;  // 0x094 [R/W] (GOLTarget, InstallMapShader, SetVariable)
    u32 m_variable_098;  // 0x098 [R/W] (GOLTarget, GetLocalizable, GetVariable, ...)
    u8 _pad_09C[0x9C];  // 0x09C
    s16 m_localizable_138;  // 0x138 [R] (GetLocalizable)
    u8 _pad_13A[2];  // 0x13A
    u32 m_localizable_13C;  // 0x13C [R] (GetLocalizable)
    u8 _pad_140[0x10];  // 0x140
    s16 m_localizable_150;  // 0x150 [R] (GetLocalizable)
    u8 _pad_152[2];  // 0x152
    u32 m_localizable_154;  // 0x154 [R] (GetLocalizable)
    u8 _pad_158[0x5B04];  // 0x158
    u32 m_localizable_5C5C;  // 0x5C5C [R] (GetLocalizable)
};

#endif // GOLTARGET_H
