#ifndef CASFASHIONTARGET_H
#define CASFASHIONTARGET_H

#include "types.h"

// CASFashionTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x90 (144 bytes)
// 21 known fields (3 named), 22 methods

class CASFashionTarget {
public:
    // Constructors / Destructors
    CASFashionTarget(void)  // 0x804D3410
    ~CASFashionTarget(void);  // 0x804D3678

    // Methods
    /* ? */ GetLocalizableSubnav(UIScreenID, int, unsigned wchar_t *);  // 0x804D4134 (1360B)
    void SetVariableSubnav(UIScreenID, int, int);  // 0x804D3834 (132B)
    void ConvertPartUIFocusOptionToChangeEvent(int, int, int &);  // 0x804D38B8 (1064B)
    void SetVariable(char *, char *);  // 0x804D36E8 (232B)
    void RandomizeFashion(void);  // 0x804D37D0 (32B)
    void HandleEventChangeFocus(CasEventChangeFocus &);  // 0x804D37F0 (68B)
    void HandleCFCSubnav(int, int);  // 0x804D3CE0 (232B)
    /* ? */ GetVariable(char *);  // 0x804D3DC8 (296B)
    /* ? */ GetLocalizable(char *);  // 0x804D3EF0 (580B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_variable;  // 0x000 [R/W] (CASFashionTarget, GetVariable, ~CASFashionTarget)
    u8 _pad_001[3];  // 0x001
    u32 m_field_004;  // 0x004 [R/W] (CASFashionTarget, ~CASFashionTarget)
    u32 m_field_008;  // 0x008 [R/W] (CASFashionTarget, ~CASFashionTarget)
    u32 m_field_00C;  // 0x00C [R/W] (CASFashionTarget, ~CASFashionTarget)
    u32 m_field_010;  // 0x010 [R/W] (CASFashionTarget, ~CASFashionTarget)
    u32 m_field_014;  // 0x014 [R/W] (CASFashionTarget, ~CASFashionTarget)
    u32 m_field_018;  // 0x018 [R/W] (CASFashionTarget, ~CASFashionTarget)
    u32 m_field_01C;  // 0x01C [R/W] (CASFashionTarget, ~CASFashionTarget)
    u32 m_field_020;  // 0x020 [R/W] (CASFashionTarget, ~CASFashionTarget)
    u32 m_field_024;  // 0x024 [R/W] (CASFashionTarget, ~CASFashionTarget)
    u32 m_field_028;  // 0x028 [W] (CASFashionTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (CASFashionTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (CASFashionTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (CASFashionTarget, ~CASFashionTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (CASFashionTarget, ~CASFashionTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (CASFashionTarget)
    u32 m_field_07C;  // 0x07C [R/W] (CASFashionTarget, ~CASFashionTarget)
    u32 m_field_080;  // 0x080 [W] (CASFashionTarget, ~CASFashionTarget)
    u32 m_localizableSubnav;  // 0x084 [R/W] (CASFashionTarget, GetLocalizableSubnav, HandleCFCSubnav)
    u32 m_field_088;  // 0x088 [W] (CASFashionTarget, ~CASFashionTarget)
    u32 m_variableSubnav;  // 0x08C [R/W] (CASFashionTarget, SetVariableSubnav)
};

#endif // CASFASHIONTARGET_H
