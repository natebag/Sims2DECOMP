#ifndef SKLTARGET_H
#define SKLTARGET_H

#include "types.h"

// SKLTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC4 (196 bytes)
// 35 known fields (18 named), 22 methods

class SKLTarget {
public:
    // Constructors / Destructors
    SKLTarget(int)  // 0x8053C340
    ~SKLTarget(void);  // 0x8053CD30

    // Methods
    void ShowSkills(void);  // 0x8053D9F8 (40B)
    void SetTextButtonPressed(bool);  // 0x8053E000 (44B)
    void UpdateSkillsBar(void);  // 0x8053DA50 (1412B)
    void HideSkills(void);  // 0x8053DA20 (48B)
    void SetVariable(char *, char *);  // 0x8053CDBC (560B)
    /* ? */ GetVariable(char *);  // 0x8053CFEC (340B)
    /* ? */ GetLocalizable(char *);  // 0x8053D140 (1652B)
    void Update(void);  // 0x8053D7B4 (580B)
    bool IsSkillsActive(void);  // 0x8053DFD4 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_variable;  // 0x000 [R/W] (GetLocalizable, GetVariable, SKLTarget, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable_004;  // 0x004 [R/W] (GetLocalizable, GetVariable, SKLTarget, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (SKLTarget, ~SKLTarget)
    u32 m_field_00C;  // 0x00C [R/W] (SKLTarget, ~SKLTarget)
    u32 m_field_010;  // 0x010 [R/W] (SKLTarget, ~SKLTarget)
    u32 m_field_014;  // 0x014 [R/W] (SKLTarget, ~SKLTarget)
    u32 m_field_018;  // 0x018 [R/W] (SKLTarget, ~SKLTarget)
    u32 m_field_01C;  // 0x01C [R/W] (SKLTarget, ~SKLTarget)
    u32 m_field_020;  // 0x020 [R/W] (SKLTarget, ~SKLTarget)
    u32 m_field_024;  // 0x024 [R/W] (SKLTarget, ~SKLTarget)
    u32 m_field_028;  // 0x028 [W] (SKLTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (SKLTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (SKLTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (SKLTarget, ~SKLTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (SKLTarget, ~SKLTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (SKLTarget)
    u32 m_field_07C;  // 0x07C [R/W] (SKLTarget, ~SKLTarget)
    u32 m_field_080;  // 0x080 [W] (SKLTarget, ~SKLTarget)
    u32 m_variable_084;  // 0x084 [R/W] (GetVariable, SKLTarget, Update, ...)
    u32 m_variable_088;  // 0x088 [R/W] (SKLTarget, SetVariable, Update)
    u32 m_variable_08C;  // 0x08C [R/W] (SKLTarget, SetVariable, Update)
    u32 m_skillsBar;  // 0x090 [R/W] (SKLTarget, Update, UpdateSkillsBar)
    u32 m_variable_094;  // 0x094 [R/W] (SKLTarget, SetVariable, Update, ...)
    u32 m_variable_098;  // 0x098 [R/W] (SKLTarget, SetVariable, Update)
    u32 m_field_09C;  // 0x09C [R/W] (SKLTarget, Update)
    u32 m_variable_0A0;  // 0x0A0 [R/W] (SKLTarget, SetVariable, Update)
    u32 m_localizable;  // 0x0A4 [R/W] (GetLocalizable, SKLTarget, UpdateSkillsBar)
    u32 m_localizable_0A8;  // 0x0A8 [W] (GetLocalizable)
    u32 m_localizable_0AC;  // 0x0AC [W] (GetLocalizable)
    u32 m_localizable_0B0;  // 0x0B0 [W] (GetLocalizable)
    u32 m_localizable_0B4;  // 0x0B4 [W] (GetLocalizable)
    u32 m_localizable_0B8;  // 0x0B8 [W] (GetLocalizable)
    u32 m_localizable_0BC;  // 0x0BC [W] (GetLocalizable)
    u32 m_localizable_0C0;  // 0x0C0 [W] (GetLocalizable)
};

#endif // SKLTARGET_H
