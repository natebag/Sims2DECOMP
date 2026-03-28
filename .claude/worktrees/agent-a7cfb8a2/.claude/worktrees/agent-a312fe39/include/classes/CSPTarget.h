#ifndef CSPTARGET_H
#define CSPTARGET_H

#include "types.h"

// CSPTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1A4 (420 bytes)
// 44 known fields (29 named), 24 methods

class CSPTarget {
public:
    // Constructors / Destructors
    CSPTarget(CSPTarget::eTabs, int)  // 0x804F000C
    ~CSPTarget(void);  // 0x804F089C

    // Methods
    void SetupSkills(cXPerson *);  // 0x804F3218 (788B)
    void SetupCareer(cXPerson *);  // 0x804F25DC (2524B)
    void SetupPersonality(cXPerson *);  // 0x804F352C (852B)
    void ChangeSelectedTab(CSPTarget::eTabs);  // 0x804F2458 (388B)
    void SetVariable(char *, char *);  // 0x804F09D8 (828B)
    /* ? */ GetVariable(char *);  // 0x804F0D14 (1592B)
    /* ? */ GetLocalizable(char *);  // 0x804F134C (4332B)
    void Update(void);  // 0x804F2438 (32B)
    void InstallPromotionShaders(void);  // 0x804F2FB8 (608B)
    void onHelpDialogSelection(int);  // 0x804F3880 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (CSPTarget, ChangeSelectedTab, GetLocalizable, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (CSPTarget, GetVariable, SetupCareer, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_upCareer;  // 0x008 [R/W] (CSPTarget, SetupCareer, ~CSPTarget)
    u32 m_field_00C;  // 0x00C [R/W] (CSPTarget, ~CSPTarget)
    u32 m_field_010;  // 0x010 [R/W] (CSPTarget, ~CSPTarget)
    u32 m_field_014;  // 0x014 [R/W] (CSPTarget, ~CSPTarget)
    u32 m_field_018;  // 0x018 [R/W] (CSPTarget, ~CSPTarget)
    u32 m_upCareer_01C;  // 0x01C [R/W] (CSPTarget, ChangeSelectedTab, InstallPromotionShaders, ...)
    s16 m_upCareer_020;  // 0x020 [R/W] (CSPTarget, SetupCareer, ~CSPTarget)
    u8 _pad_022[2];  // 0x022
    u32 m_field_024;  // 0x024 [R/W] (CSPTarget, ~CSPTarget)
    u32 m_field_028;  // 0x028 [W] (CSPTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (CSPTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (CSPTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (CSPTarget, ~CSPTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (CSPTarget, ~CSPTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (CSPTarget)
    u32 m_upCareer_07C;  // 0x07C [R/W] (CSPTarget, ChangeSelectedTab, InstallPromotionShaders, ...)
    u32 m_field_080;  // 0x080 [W] (CSPTarget, ~CSPTarget)
    u32 m_field_084;  // 0x084 [W] (CSPTarget, ~CSPTarget)
    u32 m_variable_088;  // 0x088 [W] (CSPTarget, GetVariable)
    u32 m_localizable_08C;  // 0x08C [R/W] (CSPTarget, GetLocalizable, SetVariable)
    u32 m_localizable_090;  // 0x090 [R/W] (CSPTarget, ChangeSelectedTab, GetLocalizable, ...)
    u32 m_field_094;  // 0x094 [R/W] (CSPTarget, ~CSPTarget)
    u32 m_field_098;  // 0x098 [R/W] (CSPTarget, ~CSPTarget)
    u8 _pad_09C[0x14];  // 0x09C
    u32 m_localizable_0B0;  // 0x0B0 [R/W] (GetLocalizable, SetupCareer)
    u8 _pad_0B4[4];  // 0x0B4
    s16 m_upCareer_0B8;  // 0x0B8 [R] (SetupCareer)
    u8 _pad_0BA[0x1E];  // 0x0BA
    u32 m_localizable_0D8;  // 0x0D8 [R/W] (GetLocalizable, SetupCareer)
    u32 m_localizable_0DC;  // 0x0DC [R/W] (GetLocalizable, SetupCareer)
    u32 m_upSkills;  // 0x0E0 [R/W] (InstallPromotionShaders, SetupSkills)
    u32 m_upSkills_0E4;  // 0x0E4 [R/W] (InstallPromotionShaders, SetupSkills)
    u32 m_upSkills_0E8;  // 0x0E8 [R/W] (InstallPromotionShaders, SetupSkills)
    u32 m_upSkills_0EC;  // 0x0EC [R/W] (InstallPromotionShaders, SetupSkills)
    u32 m_upSkills_0F0;  // 0x0F0 [R/W] (InstallPromotionShaders, SetupSkills)
    u32 m_upSkills_0F4;  // 0x0F4 [R/W] (InstallPromotionShaders, SetupSkills)
    u32 m_upSkills_0F8;  // 0x0F8 [R/W] (InstallPromotionShaders, SetupSkills)
    u32 m_upPersonality;  // 0x0FC [W] (SetupPersonality)
    u32 m_upPersonality_100;  // 0x100 [W] (SetupPersonality)
    u32 m_upPersonality_104;  // 0x104 [W] (SetupPersonality)
    u32 m_upPersonality_108;  // 0x108 [W] (SetupPersonality)
    u32 m_upPersonality_10C;  // 0x10C [W] (SetupPersonality)
    u32 m_upPersonality_110;  // 0x110 [R/W] (SetupPersonality)
    s16 m_upPersonality_112;  // 0x112 [R] (SetupPersonality)
    u8 _pad_114[0x8C];  // 0x114
    u32 m_variable_1A0;  // 0x1A0 [R] (GetVariable, SetVariable)
};

#endif // CSPTARGET_H
