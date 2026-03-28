#ifndef CASPERSONALTARGET_H
#define CASPERSONALTARGET_H

#include "types.h"

// CASPersonalTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x122 (290 bytes)
// 32 known fields (16 named), 28 methods

class CASPersonalTarget {
public:
    // Constructors / Destructors
    CASPersonalTarget(void)  // 0x804D6580
    ~CASPersonalTarget(void);  // 0x804D6B44

    // Methods
    /* ? */ GetLocalizableSubnav(UIScreenID, int, unsigned wchar_t *);  // 0x804D8208 (492B)
    void SetVariableSubnav(UIScreenID, int, int);  // 0x804D80A0 (360B)
    /* ? */ GetSavedPersVal(signed char);  // 0x804D86E4 (216B)
    void CalcHighScoreAspShaderIds(void);  // 0x804D83F4 (752B)
    void SetVariable(char *, char *);  // 0x804D6BB4 (668B)
    void HandlePersonalityAnimation(char *);  // 0x804D6E50 (124B)
    void ConvertFromPersonalityTextToEnum(char *);  // 0x804D6ECC (456B)
    /* ? */ GetVariable(char *);  // 0x804D7094 (832B)
    /* ? */ GetLocalizable(char *);  // 0x804D73D4 (824B)
    void ParseSignText(short, unsigned wchar_t *);  // 0x804D770C (1000B)
    void ParsePersonalityText(char *, unsigned wchar_t *);  // 0x804D7CCC (980B)
    void ParseDescriptionText(short, unsigned wchar_t *);  // 0x804D7AF4 (472B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_localizable;  // 0x000 [R/W] (CASPersonalTarget, GetLocalizable, GetVariable, ...)
    u8 _pad_001[3];  // 0x001
    u32 m_field_004;  // 0x004 [R/W] (CASPersonalTarget, ~CASPersonalTarget)
    u32 m_field_008;  // 0x008 [R/W] (CASPersonalTarget, ~CASPersonalTarget)
    u32 m_field_00C;  // 0x00C [R/W] (CASPersonalTarget, ~CASPersonalTarget)
    u32 m_field_010;  // 0x010 [R/W] (CASPersonalTarget, ~CASPersonalTarget)
    u32 m_field_014;  // 0x014 [R/W] (CASPersonalTarget, ~CASPersonalTarget)
    u32 m_field_018;  // 0x018 [R/W] (CASPersonalTarget, ~CASPersonalTarget)
    u32 m_variableSubnav;  // 0x01C [R/W] (CASPersonalTarget, SetVariableSubnav, ~CASPersonalTarget)
    u8 m_variable;  // 0x01F [W] (GetVariable)
    u32 m_field_020;  // 0x020 [R/W] (CASPersonalTarget, ~CASPersonalTarget)
    u32 m_field_024;  // 0x024 [R/W] (CASPersonalTarget, ~CASPersonalTarget)
    u32 m_field_028;  // 0x028 [W] (CASPersonalTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (CASPersonalTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (CASPersonalTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (CASPersonalTarget, ~CASPersonalTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (CASPersonalTarget, ~CASPersonalTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (CASPersonalTarget)
    u32 m_variableSubnav_07C;  // 0x07C [R/W] (CASPersonalTarget, SetVariableSubnav, ~CASPersonalTarget)
    u32 m_field_080;  // 0x080 [W] (CASPersonalTarget, ~CASPersonalTarget)
    u32 m_variable_084;  // 0x084 [R/W] (CASPersonalTarget, GetVariable, HandlePersonalityAnimation, ...)
    u32 m_field_088;  // 0x088 [W] (CASPersonalTarget, ~CASPersonalTarget)
    u8 m_variable_08C;  // 0x08C [W] (SetVariable)
    u8 m_variable_08D;  // 0x08D [W] (SetVariable)
    u8 m_variable_08E;  // 0x08E [W] (SetVariable)
    u8 m_variable_08F;  // 0x08F [W] (SetVariable)
    u8 m_variable_090;  // 0x090 [W] (SetVariable)
    u8 _pad_091[0x8B];  // 0x091
    u8 m_variable_11C;  // 0x11C [R] (GetVariable)
    u8 m_variable_11D;  // 0x11D [R] (GetVariable)
    u8 m_variable_11E;  // 0x11E [R] (GetVariable)
    u8 m_variable_11F;  // 0x11F [R] (GetVariable)
    u8 m_variable_120;  // 0x120 [R] (GetVariable)
    u8 m_variable_121;  // 0x121 [R/W] (GetVariable, SetVariable)
};

#endif // CASPERSONALTARGET_H
