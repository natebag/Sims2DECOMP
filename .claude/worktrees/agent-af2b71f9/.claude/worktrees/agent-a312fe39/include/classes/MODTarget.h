#ifndef MODTARGET_H
#define MODTARGET_H

#include "types.h"

// MODTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x100 (256 bytes)
// 45 known fields (21 named), 40 methods

class MODTarget {
public:
    // Constructors / Destructors
    MODTarget(int)  // 0x8051BE5C
    ~MODTarget(void);  // 0x8051C754

    // Methods
    void SetDpadIcons(MODTarget::eSidePanelIcon);  // 0x8051E4EC (948B)
    void SetTextButtonPressed(bool);  // 0x8051EA4C (52B)
    void UpdateMood(void);  // 0x8051D578 (580B)
    bool IsMoodActive(void);  // 0x8051D7BC (44B)
    void ShowMood(void);  // 0x8051D528 (40B)
    void HideMood(void);  // 0x8051D550 (40B)
    void SetWarning(MODTarget::eSidePanelId, bool, bool);  // 0x8051DE60 (908B)
    void SetMeterValue(float, bool);  // 0x8051E1EC (768B)
    void DisplayPaused(void);  // 0x8051E8A0 (120B)
    void DisplayFastForward(void);  // 0x8051E918 (104B)
    void DrawMoodHeadCallback(ERC *, structDrawCBparams *);  // 0x8051D3A8 (384B)
    void SetVariable(char *, char *);  // 0x8051C7F0 (532B)
    /* ? */ GetVariable(char *);  // 0x8051CA04 (404B)
    /* ? */ GetLocalizable(char *);  // 0x8051CB98 (816B)
    void Update(void);  // 0x8051CEC8 (1248B)
    void SelectDpadArrow(MODTarget::eSidePanelId);  // 0x8051D7E8 (548B)
    void SelectDpadButton(MODTarget::eSidePanelId);  // 0x8051DA0C (1108B)
    void TriggerAspirationChestDisplay(void);  // 0x8051E980 (204B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_variable;  // 0x000 [R/W] (GetLocalizable, GetVariable, MODTarget, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable_004;  // 0x004 [R/W] (GetVariable, MODTarget, ~MODTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (MODTarget, ~MODTarget)
    u32 m_field_00C;  // 0x00C [R/W] (MODTarget, ~MODTarget)
    u32 m_field_010;  // 0x010 [R/W] (MODTarget, ~MODTarget)
    u32 m_field_014;  // 0x014 [R/W] (MODTarget, ~MODTarget)
    u32 m_field_018;  // 0x018 [R/W] (MODTarget, ~MODTarget)
    u32 m_field_01C;  // 0x01C [R/W] (MODTarget, ~MODTarget)
    u32 m_field_020;  // 0x020 [R/W] (MODTarget, ~MODTarget)
    u32 m_field_024;  // 0x024 [R/W] (MODTarget, ~MODTarget)
    u32 m_field_028;  // 0x028 [W] (MODTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (MODTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (MODTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (MODTarget, ~MODTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (MODTarget, ~MODTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [R/W] (MODTarget)
    u32 m_field_07C;  // 0x07C [R/W] (MODTarget, ~MODTarget)
    u32 m_field_080;  // 0x080 [W] (MODTarget, ~MODTarget)
    u32 m_variable_084;  // 0x084 [R/W] (GetVariable, MODTarget, SetDpadIcons, ...)
    u32 m_variable_088;  // 0x088 [R/W] (MODTarget, SetVariable, TriggerAspirationChestDisplay, ...)
    u32 m_variable_08C;  // 0x08C [R/W] (MODTarget, SetVariable, Update)
    u32 m_field_090;  // 0x090 [R/W] (MODTarget, Update)
    u32 m_variable_094;  // 0x094 [R/W] (DisplayFastForward, DisplayPaused, GetVariable, ...)
    u32 m_field_098;  // 0x098 [W] (MODTarget)
    u32 m_warning;  // 0x09C [R/W] (SetWarning, UpdateMood)
    u32 m_mood;  // 0x0A0 [R/W] (MODTarget, UpdateMood)
    u32 m_meterValue;  // 0x0A4 [R/W] (MODTarget, SetMeterValue, UpdateMood)
    u32 m_dpadIcons;  // 0x0A8 [R/W] (MODTarget, SelectDpadArrow, SelectDpadButton, ...)
    u32 m_field_0AC;  // 0x0AC [W] (SelectDpadArrow)
    u32 m_field_0B0;  // 0x0B0 [W] (SelectDpadArrow)
    u32 m_warning_0B4;  // 0x0B4 [R/W] (SelectDpadButton, SetWarning)
    u32 m_dpadIcons_0B8;  // 0x0B8 [R/W] (SelectDpadButton, SetDpadIcons, SetWarning)
    u32 m_dpadIcons_0BC;  // 0x0BC [R/W] (SelectDpadButton, SetDpadIcons, SetWarning, ...)
    u32 m_dpadIcons_0C0;  // 0x0C0 [R/W] (MODTarget, SelectDpadButton, SetDpadIcons)
    u32 m_dpadIcons_0C4;  // 0x0C4 [R/W] (MODTarget, SelectDpadButton, SetDpadIcons)
    u8 _pad_0C8[0x14];  // 0x0C8
    u32 m_meterValue_0DC;  // 0x0DC [R/W] (MODTarget, SetMeterValue)
    u32 m_field_0E0;  // 0x0E0 [R/W] (DisplayPaused, MODTarget, Update)
    u32 m_field_0E4;  // 0x0E4 [R/W] (DisplayFastForward, MODTarget, Update)
    u32 m_field_0E8;  // 0x0E8 [R/W] (MODTarget, TriggerAspirationChestDisplay, Update)
    u32 m_localizable;  // 0x0EC [R/W] (GetLocalizable, TriggerAspirationChestDisplay, Update)
    u32 m_localizable_0F0;  // 0x0F0 [R/W] (GetLocalizable, TriggerAspirationChestDisplay, Update)
    u32 m_variable_0F4;  // 0x0F4 [R/W] (MODTarget, SetVariable, Update)
    u32 m_field_0F8;  // 0x0F8 [R/W] (MODTarget, Update)
    u32 m_variable_0FC;  // 0x0FC [R/W] (MODTarget, SetVariable, Update)
};

#endif // MODTARGET_H
