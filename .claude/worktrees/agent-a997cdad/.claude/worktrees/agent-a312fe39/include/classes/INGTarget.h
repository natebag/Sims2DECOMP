#ifndef INGTARGET_H
#define INGTARGET_H

#include "types.h"

// INGTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x468 (1128 bytes)
// 53 known fields (29 named), 66 methods

class INGTarget {
public:
    // Constructors / Destructors
    INGTarget(void)  // 0x80508158
    ~INGTarget(void);  // 0x80508E1C

    // Methods
    void SetRefrigeratorLevel(int);  // 0x80508114 (68B)
    void create_edit_buffer(void);  // 0x8050B8CC (1072B)
    void get_blank_shader_id(void);  // 0x8050B618 (72B)
    void exit_ingredients_dialog_selection_callback(int);  // 0x8050CAE4 (80B)
    void SetVariable(char *, char *);  // 0x80508EE4 (3372B)
    void update_current_items(unsigned int);  // 0x8050ACFC (544B)
    void install_current_item_shaders(void);  // 0x8050AFC0 (260B)
    void get_current_inginfo(void);  // 0x8050B0C4 (132B)
    void play_error_sound(void);  // 0x8050C98C (92B)
    void get_mix_ingredient(short);  // 0x8050BDEC (204B)
    void add_mix_ing(INGTarget::IngInfo *, unsigned int);  // 0x8050B230 (316B)
    void update_mix_ing_name(unsigned int);  // 0x8050C008 (160B)
    void update_item_states(void);  // 0x8050AF1C (164B)
    void mix_ingredients(void);  // 0x8050B504 (276B)
    void set_done_button_state(bool);  // 0x8050BF84 (132B)
    void get_current_mix_inginfo(void);  // 0x8050B148 (132B)
    void end_dialog(bool);  // 0x8050AA8C (624B)
    /* ? */ GetVariable(char *);  // 0x80509C10 (280B)
    /* ? */ GetLocalizable(char *);  // 0x80509D28 (2796B)
    void get_current_ingredient(void);  // 0x8050B1CC (100B)
    void query_enabled(INGTarget::IngInfo *);  // 0x8050B3E0 (292B)
    void get_mix_ing_name(unsigned int, unsigned wchar_t *);  // 0x8050B660 (344B)
    void get_total_cost(unsigned int *);  // 0x8050B7B8 (276B)
    void Update(void);  // 0x8050A814 (632B)
    void configure_object(short, Ingredient *, Ingredient *, Ingredient *, Ingredient *);  // 0x8050C0A8 (2276B)
    void get_ingredient_type(INGTarget::IngInfo &);  // 0x8050B36C (116B)
    void set_cell_enabled(unsigned int, bool);  // 0x8050BEB8 (204B)
    void is_group_meal(void);  // 0x8050C9E8 (56B)
    void get_grid_ingredient(short);  // 0x8050BCFC (240B)
    void RCPOnCancel(void);  // 0x8050CA20 (48B)
    void onHelpDialogSelection(int);  // 0x8050CA50 (148B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_localizable;  // 0x000 [R/W] (GetLocalizable, GetVariable, INGTarget, ...)
    u8 _pad_001[1];  // 0x001
    s16 m_localizable_002;  // 0x002 [R] (GetLocalizable)
    u16 m_localizable_004;  // 0x004 [R/W] (GetLocalizable, GetVariable, INGTarget, ...)
    u8 m_variable;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_variable_008;  // 0x008 [R/W] (INGTarget, SetVariable, install_current_item_shaders, ...)
    u32 m_variable_00C;  // 0x00C [R/W] (INGTarget, SetVariable, ~INGTarget)
    u32 m_localizable_010;  // 0x010 [R/W] (GetLocalizable, INGTarget, ~INGTarget)
    u32 m_localizable_014;  // 0x014 [R/W] (GetLocalizable, INGTarget, ~INGTarget)
    u32 m_localizable_018;  // 0x018 [R/W] (GetLocalizable, INGTarget, ~INGTarget)
    u32 m_localizable_01C;  // 0x01C [R/W] (GetLocalizable, INGTarget, SetVariable, ...)
    u32 m_field_020;  // 0x020 [R/W] (INGTarget, ~INGTarget)
    u32 m_localizable_024;  // 0x024 [R/W] (GetLocalizable, INGTarget, ~INGTarget)
    u32 m_field_028;  // 0x028 [W] (INGTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (INGTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (INGTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (INGTarget, ~INGTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (INGTarget, ~INGTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (INGTarget)
    u32 m_variable_07C;  // 0x07C [R/W] (INGTarget, SetVariable, install_current_item_shaders, ...)
    u32 m_field_080;  // 0x080 [R/W] (INGTarget, onHelpDialogSelection, ~INGTarget)
    u32 m_field_084;  // 0x084 [W] (INGTarget, ~INGTarget)
    u32 m_field_088;  // 0x088 [W] (INGTarget, ~INGTarget)
    u32 m_field_08C;  // 0x08C [W] (INGTarget)
    u32 m_field_090;  // 0x090 [W] (INGTarget)
    u32 m_variable_094;  // 0x094 [R/W] (INGTarget, SetVariable, Update)
    u32 m_field_098;  // 0x098 [W] (INGTarget)
    s16 m_field_09A;  // 0x09A [R] (end_dialog)
    u32 m_field_09C;  // 0x09C [R/W] (INGTarget, ~INGTarget)
    u32 m_field_0A0;  // 0x0A0 [R/W] (INGTarget, ~INGTarget)
    u32 m_variable_0A4;  // 0x0A4 [W] (SetVariable)
    u32 m_variable_0A8;  // 0x0A8 [W] (SetVariable)
    u8 _pad_0AC[0xC];  // 0x0AC
    u32 m_variable_0B8;  // 0x0B8 [W] (SetVariable)
    u8 _pad_0BC[0xC];  // 0x0BC
    u32 m_variable_0C8;  // 0x0C8 [W] (SetVariable)
    u8 _pad_0CC[0x28];  // 0x0CC
    u32 m_variable_0F4;  // 0x0F4 [W] (SetVariable)
    u8 _pad_0F8[0xC];  // 0x0F8
    u32 m_variable_104;  // 0x104 [W] (SetVariable)
    u8 _pad_108[0xC];  // 0x108
    u32 m_variable_114;  // 0x114 [W] (SetVariable)
    u8 _pad_118[0x18];  // 0x118
    u32 m_variable_130;  // 0x130 [W] (SetVariable)
    u32 m_variable_134;  // 0x134 [R/W] (INGTarget, SetVariable, onHelpDialogSelection)
    u8 _pad_138[0xA8];  // 0x138
    u32 m_field_1E0;  // 0x1E0 [R] (end_dialog)
    u8 _pad_1E4[4];  // 0x1E4
    u32 m_field_1E8;  // 0x1E8 [R] (end_dialog)
    u8 _pad_1EC[4];  // 0x1EC
    u32 m_field_1F0;  // 0x1F0 [R] (end_dialog)
    u8 _pad_1F4[4];  // 0x1F4
    u32 m_field_1F8;  // 0x1F8 [R] (end_dialog)
    u8 _pad_1FC[4];  // 0x1FC
    u32 m_field_200;  // 0x200 [R/W] (INGTarget, create_edit_buffer, end_dialog)
    u32 m_field_204;  // 0x204 [R] (end_dialog)
    u8 _pad_208[0x23C];  // 0x208
    u32 m_localizable_444;  // 0x444 [R/W] (GetLocalizable, INGTarget, SetVariable, ...)
    u32 m_localizable_448;  // 0x448 [R/W] (GetLocalizable, INGTarget, SetVariable)
    u32 m_variable_44C;  // 0x44C [R/W] (INGTarget, SetVariable, get_current_inginfo)
    u32 m_variable_450;  // 0x450 [R/W] (INGTarget, SetVariable, get_current_mix_inginfo)
    u32 m_localizable_454;  // 0x454 [R/W] (GetLocalizable, INGTarget, SetVariable, ...)
    u32 m_variable_458;  // 0x458 [R/W] (INGTarget, SetVariable, Update)
    u32 m_field_45C;  // 0x45C [R/W] (INGTarget, Update)
    f32 m_variable_460;  // 0x460 [R/W] (INGTarget, SetVariable, Update)
    u32 m_field_464;  // 0x464 [R/W] (INGTarget, Update)
};

#endif // INGTARGET_H
