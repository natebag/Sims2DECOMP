#ifndef CASMORPHTARGET_H
#define CASMORPHTARGET_H

#include "types.h"

// CASMorphTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C4 (452 bytes)
// 34 known fields (15 named), 18 methods

class CASMorphTarget {
public:
    // Constructors / Destructors
    CASMorphTarget(void)  // 0x804D53EC
    ~CASMorphTarget(void);  // 0x804D56A4

    // Methods
    /* ? */ GetLocalizableSubnav(UIScreenID, int, unsigned wchar_t *);  // 0x804D5C24 (936B)
    void SetVariableSubnav(UIScreenID, int, int);  // 0x804D5A80 (420B)
    void EnterMorphScreen(void);  // 0x804D6360 (276B)
    void ExitMorphScreenPrev(void);  // 0x804D6474 (228B)
    void ExitMorphScreenDone(void);  // 0x804D6558 (40B)
    void SetVariable(char *, char *);  // 0x804D5724 (860B)
    /* ? */ GetVariable(char *);  // 0x804D5FCC (916B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_variable;  // 0x000 [R/W] (CASMorphTarget, EnterMorphScreen, GetVariable, ...)
    u8 _pad_001[3];  // 0x001
    u32 m_field_004;  // 0x004 [R/W] (CASMorphTarget, EnterMorphScreen, ~CASMorphTarget)
    u32 m_field_008;  // 0x008 [R/W] (CASMorphTarget, EnterMorphScreen, ~CASMorphTarget)
    u32 m_field_00C;  // 0x00C [R/W] (CASMorphTarget, EnterMorphScreen, ~CASMorphTarget)
    u32 m_field_010;  // 0x010 [R/W] (CASMorphTarget, EnterMorphScreen, ~CASMorphTarget)
    u32 m_field_014;  // 0x014 [R/W] (CASMorphTarget, EnterMorphScreen, ~CASMorphTarget)
    u32 m_field_018;  // 0x018 [R/W] (CASMorphTarget, ~CASMorphTarget)
    u32 m_field_01C;  // 0x01C [R/W] (CASMorphTarget, ~CASMorphTarget)
    u8 m_variable_01F;  // 0x01F [W] (GetVariable)
    u32 m_field_020;  // 0x020 [R/W] (CASMorphTarget, ~CASMorphTarget)
    u32 m_field_024;  // 0x024 [R/W] (CASMorphTarget, ~CASMorphTarget)
    u32 m_field_028;  // 0x028 [W] (CASMorphTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (CASMorphTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (CASMorphTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (CASMorphTarget, ~CASMorphTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (CASMorphTarget, ~CASMorphTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (CASMorphTarget)
    u32 m_field_07C;  // 0x07C [R/W] (CASMorphTarget, ~CASMorphTarget)
    u32 m_field_080;  // 0x080 [W] (CASMorphTarget, ~CASMorphTarget)
    u32 m_variable_084;  // 0x084 [R/W] (CASMorphTarget, EnterMorphScreen, ExitMorphScreenPrev, ...)
    u32 m_field_088;  // 0x088 [W] (CASMorphTarget, ~CASMorphTarget)
    u8 m_variable_08C;  // 0x08C [R/W] (CASMorphTarget, GetVariable, SetVariable, ...)
    u8 _pad_08D[3];  // 0x08D
    u32 m_variable_090;  // 0x090 [R/W] (CASMorphTarget, SetVariable)
    f32 m_variable_094;  // 0x094 [R/W] (CASMorphTarget, SetVariable)
    u32 m_variableSubnav;  // 0x098 [W] (CASMorphTarget, SetVariableSubnav)
    u8 _pad_09C[0x5C];  // 0x09C
    f32 m_variable_0F8;  // 0x0F8 [R] (GetVariable)
    f32 m_variable_0FC;  // 0x0FC [R] (GetVariable)
    f32 m_variable_100;  // 0x100 [R] (GetVariable)
    f32 m_variable_104;  // 0x104 [R] (GetVariable)
    f32 m_variable_108;  // 0x108 [R] (GetVariable)
    f32 m_variable_10C;  // 0x10C [R] (GetVariable)
    f32 m_variable_110;  // 0x110 [R] (GetVariable)
    f32 m_variable_114;  // 0x114 [R] (GetVariable)
    u8 _pad_118[0xA8];  // 0x118
    u32 m_field_1C0;  // 0x1C0 [R/W] (CASMorphTarget, EnterMorphScreen, ExitMorphScreenPrev)
};

#endif // CASMORPHTARGET_H
