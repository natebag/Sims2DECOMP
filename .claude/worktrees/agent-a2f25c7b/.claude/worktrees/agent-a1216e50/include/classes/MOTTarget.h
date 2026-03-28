#ifndef MOTTARGET_H
#define MOTTARGET_H

#include "types.h"

// MOTTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x16C (364 bytes)
// 30 known fields (11 named), 32 methods

class MOTTarget {
public:
    // Constructors / Destructors
    MOTTarget(int)  // 0x8051EA80
    ~MOTTarget(void);  // 0x8051F56C

    // Methods
    void ShowMotives(void);  // 0x80520134 (40B)
    void SetTextButtonPressed(bool);  // 0x80520F00 (52B)
    void UpdateMotives(void);  // 0x8052018C (32B)
    void UpdateMotiveBars(void);  // 0x805201AC (2080B)
    void HideMotives(void);  // 0x8052015C (48B)
    void SelectedPersonChanged(cXPerson *);  // 0x80520ECC (52B)
    void ReadMotiveBar(int);  // 0x805209F8 (784B)
    void SetVariable(char *, char *);  // 0x8051F5F8 (560B)
    /* ? */ GetVariable(char *);  // 0x8051F828 (340B)
    /* ? */ GetLocalizable(char *);  // 0x8051F97C (600B)
    void Draw(ERC *);  // 0x8051FBD4 (796B)
    void Update(void);  // 0x8051FEF0 (580B)
    void ResetRealMotiveValues(void);  // 0x80520D08 (452B)
    bool IsMotivesActive(void);  // 0x805209CC (44B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (GetLocalizable, GetVariable, MOTTarget, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (GetVariable, MOTTarget, ~MOTTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (MOTTarget, ~MOTTarget)
    u32 m_field_00C;  // 0x00C [R/W] (MOTTarget, ~MOTTarget)
    u32 m_field_010;  // 0x010 [R/W] (MOTTarget, ~MOTTarget)
    u32 m_field_014;  // 0x014 [R/W] (MOTTarget, ~MOTTarget)
    u32 m_field_018;  // 0x018 [R/W] (MOTTarget, ~MOTTarget)
    u32 m_field_01C;  // 0x01C [R/W] (MOTTarget, ~MOTTarget)
    u32 m_field_020;  // 0x020 [R/W] (MOTTarget, ~MOTTarget)
    u32 m_field_024;  // 0x024 [R/W] (MOTTarget, ~MOTTarget)
    u32 m_field_028;  // 0x028 [W] (MOTTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (MOTTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (MOTTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (MOTTarget, ~MOTTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (MOTTarget, ~MOTTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (MOTTarget)
    u32 m_field_07C;  // 0x07C [R/W] (MOTTarget, ~MOTTarget)
    u32 m_field_080;  // 0x080 [W] (MOTTarget, ~MOTTarget)
    u32 m_variable_084;  // 0x084 [R/W] (GetVariable, MOTTarget, Update, ...)
    u32 m_variable_088;  // 0x088 [R/W] (MOTTarget, SetVariable, Update, ...)
    u32 m_variable_08C;  // 0x08C [R/W] (MOTTarget, SetVariable, Update, ...)
    u32 m_variable_090;  // 0x090 [R/W] (MOTTarget, SetVariable, Update)
    u32 m_field_094;  // 0x094 [R/W] (MOTTarget, Update)
    u32 m_variable_098;  // 0x098 [R/W] (MOTTarget, SetVariable, Update)
    u32 m_motiveBars;  // 0x09C [R] (UpdateMotiveBars)
    u8 _pad_0A0[0xBC];  // 0x0A0
    u32 m_variable_15C;  // 0x15C [R/W] (MOTTarget, SetVariable, Update)
    u32 m_field_160;  // 0x160 [R/W] (MOTTarget, Update)
    u32 m_field_164;  // 0x164 [R/W] (MOTTarget, ReadMotiveBar, ResetRealMotiveValues, ...)
    u32 m_motiveBars_168;  // 0x168 [R/W] (MOTTarget, UpdateMotiveBars)
};

#endif // MOTTARGET_H
