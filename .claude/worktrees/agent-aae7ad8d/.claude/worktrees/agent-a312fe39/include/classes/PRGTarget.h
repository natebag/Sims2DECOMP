#ifndef PRGTARGET_H
#define PRGTARGET_H

#include "types.h"

// PRGTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x94 (148 bytes)
// 23 known fields (5 named), 38 methods

class PRGTarget {
public:
    // Constructors / Destructors
    PRGTarget(int)  // 0x80531E98
    ~PRGTarget(void);  // 0x805323B8

    // Methods
    void SetVariable(char *, char *);  // 0x80532468 (380B)
    void Shutdown(void);  // 0x805345A4 (132B)
    void OnCancelKeyPressed(char *, char *);  // 0x805344F8 (140B)
    void FormatFraction(unsigned wchar_t *, int, int);  // 0x805325E4 (156B)
    void FormatPercentage(unsigned wchar_t *, int, int);  // 0x80532680 (168B)
    /* ? */ GetUnlockedFashions(void);  // 0x80532728 (228B)
    /* ? */ GetUnlockedRecipies(void);  // 0x8053280C (228B)
    /* ? */ GetUnlockedObjects(void);  // 0x805328F0 (228B)
    /* ? */ GetTotalPromotions(void);  // 0x805329D4 (412B)
    /* ? */ GetMaxedCareers(void);  // 0x80532B70 (280B)
    /* ? */ GetTotalSkillPoints(void);  // 0x80532C88 (788B)
    /* ? */ GetMaxedSkills(void);  // 0x80532F9C (676B)
    /* ? */ GetNPCsHelped(void);  // 0x80533240 (204B)
    /* ? */ GetUnlockedLots(void);  // 0x8053330C (228B)
    /* ? */ GetLocalizable(char *);  // 0x805333F0 (4020B)
    /* ? */ GetVariable(char *);  // 0x805343A4 (340B)
    void UpdateShaders(void);  // 0x80534584 (32B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_unlockedRecipies;  // 0x000 [R/W] (GetLocalizable, GetMaxedCareers, GetNPCsHelped, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (GetVariable, PRGTarget, ~PRGTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (PRGTarget, ~PRGTarget)
    u32 m_field_00C;  // 0x00C [R/W] (PRGTarget, ~PRGTarget)
    u32 m_field_010;  // 0x010 [R/W] (PRGTarget, ~PRGTarget)
    u32 m_field_014;  // 0x014 [R/W] (PRGTarget, ~PRGTarget)
    u32 m_totalSkillPoints;  // 0x018 [R/W] (GetMaxedSkills, GetTotalSkillPoints, PRGTarget, ...)
    u32 m_field_01C;  // 0x01C [R/W] (PRGTarget, ~PRGTarget)
    u32 m_field_020;  // 0x020 [R/W] (PRGTarget, ~PRGTarget)
    u32 m_field_024;  // 0x024 [R/W] (PRGTarget, ~PRGTarget)
    u32 m_field_028;  // 0x028 [W] (PRGTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (PRGTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (PRGTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (PRGTarget, ~PRGTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (PRGTarget, ~PRGTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (PRGTarget)
    u32 m_field_07C;  // 0x07C [R/W] (PRGTarget, ~PRGTarget)
    u32 m_field_080;  // 0x080 [W] (PRGTarget, ~PRGTarget)
    u32 m_variable_084;  // 0x084 [W] (GetVariable, PRGTarget)
    u32 m_field_088;  // 0x088 [R/W] (PRGTarget)
    u32 m_field_08C;  // 0x08C [R/W] (PRGTarget, ~PRGTarget)
    u32 m_field_090;  // 0x090 [R/W] (PRGTarget, ~PRGTarget)
};

#endif // PRGTARGET_H
