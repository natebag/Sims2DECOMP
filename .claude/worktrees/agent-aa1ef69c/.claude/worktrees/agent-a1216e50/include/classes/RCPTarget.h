#ifndef RCPTARGET_H
#define RCPTARGET_H

#include "types.h"

// RCPTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14C (332 bytes)
// 40 known fields (19 named), 28 methods

class RCPTarget {
public:
    // Constructors / Destructors
    RCPTarget(cRCPEventHandler *, int)  // 0x805382EC
    ~RCPTarget(void);  // 0x805389C4

    // Methods
    void init_recipes(void);  // 0x80539B6C (1052B)
    void make_recipe_text(RCPTarget::Recipe *, BString2 &);  // 0x80538D14 (636B)
    void SetVariable(char *, char *);  // 0x80538F90 (1368B)
    void install_tab_shaders(void);  // 0x80539F88 (212B)
    void install_lock_shaders(void);  // 0x8053A05C (288B)
    void install_ing_shaders(void);  // 0x8053A17C (1152B)
    /* ? */ GetVariable(char *);  // 0x805394E8 (560B)
    /* ? */ GetLocalizable(char *);  // 0x80539718 (876B)
    void Update(void);  // 0x80539A84 (196B)
    void Draw(ERC *);  // 0x80539B48 (36B)
    void get_plus_shaders(RCPTarget::Recipe &, unsigned int &, unsigned int &);  // 0x8053A5FC (684B)
    void get_proc_shaders(RCPTarget::Recipe &, unsigned int &, unsigned int &);  // 0x8053A8A8 (820B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_field_000;  // 0x000 [R/W] (RCPTarget, init_recipes, install_ing_shaders, ...)
    u8 _pad_002[2];  // 0x002
    u32 m_field_004;  // 0x004 [R/W] (RCPTarget, init_recipes, ~RCPTarget)
    u32 m_field_008;  // 0x008 [R/W] (RCPTarget, install_ing_shaders, ~RCPTarget)
    u32 m_field_00C;  // 0x00C [R/W] (RCPTarget, ~RCPTarget)
    u32 m_field_010;  // 0x010 [R/W] (RCPTarget, ~RCPTarget)
    u32 m_field_014;  // 0x014 [R/W] (RCPTarget, ~RCPTarget)
    u32 m_field_018;  // 0x018 [R/W] (RCPTarget, ~RCPTarget)
    u32 m_field_01C;  // 0x01C [R/W] (RCPTarget, install_ing_shaders, install_lock_shaders, ...)
    u32 m_field_020;  // 0x020 [R/W] (RCPTarget, ~RCPTarget)
    u32 m_field_024;  // 0x024 [R/W] (RCPTarget, ~RCPTarget)
    u32 m_field_028;  // 0x028 [W] (RCPTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (RCPTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (RCPTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (RCPTarget, ~RCPTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (RCPTarget, ~RCPTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (RCPTarget)
    u32 m_field_07C;  // 0x07C [R/W] (RCPTarget, install_ing_shaders, install_lock_shaders, ...)
    u32 m_field_080;  // 0x080 [W] (RCPTarget, ~RCPTarget)
    u32 m_variable;  // 0x084 [R/W] (RCPTarget, SetVariable)
    u32 m_field_088;  // 0x088 [R/W] (RCPTarget, ~RCPTarget)
    u32 m_field_08C;  // 0x08C [R/W] (RCPTarget, ~RCPTarget)
    u32 m_variable_090;  // 0x090 [W] (SetVariable)
    u32 m_variable_094;  // 0x094 [W] (SetVariable)
    u8 _pad_098[0xC];  // 0x098
    u32 m_variable_0A4;  // 0x0A4 [W] (SetVariable)
    u8 _pad_0A8[0xC];  // 0x0A8
    u32 m_variable_0B4;  // 0x0B4 [W] (SetVariable)
    u8 _pad_0B8[0x28];  // 0x0B8
    u32 m_variable_0E0;  // 0x0E0 [W] (SetVariable)
    u8 _pad_0E4[0xC];  // 0x0E4
    u32 m_variable_0F0;  // 0x0F0 [W] (SetVariable)
    u8 _pad_0F4[0xC];  // 0x0F4
    u32 m_variable_100;  // 0x100 [W] (SetVariable)
    u8 _pad_104[0x14];  // 0x104
    u32 m_variable_118;  // 0x118 [R] (GetVariable, SetVariable)
    u8 _pad_11C[4];  // 0x11C
    u32 m_variable_120;  // 0x120 [R/W] (RCPTarget, SetVariable, Update)
    u32 m_localizable;  // 0x124 [R/W] (GetLocalizable, RCPTarget, SetVariable, ...)
    u32 m_localizable_128;  // 0x128 [R/W] (GetLocalizable, GetVariable, RCPTarget, ...)
    u32 m_variable_12C;  // 0x12C [R/W] (GetVariable, RCPTarget, SetVariable, ...)
    u32 m_variable_130;  // 0x130 [R/W] (RCPTarget, SetVariable, install_tab_shaders)
    u32 m_localizable_134;  // 0x134 [R/W] (GetLocalizable, RCPTarget, SetVariable, ...)
    u32 m_variable_138;  // 0x138 [R/W] (RCPTarget, SetVariable)
    u32 m_variable_13C;  // 0x13C [R/W] (SetVariable, init_recipes)
    f32 m_variable_140;  // 0x140 [R/W] (RCPTarget, SetVariable, Update)
    u32 m_field_144;  // 0x144 [R/W] (RCPTarget, Update)
    u32 m_variable_148;  // 0x148 [R/W] (RCPTarget, SetVariable)
};

#endif // RCPTARGET_H
