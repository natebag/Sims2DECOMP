#ifndef E2ETARGET_H
#define E2ETARGET_H

#include "types.h"

// E2ETarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x288 (648 bytes)
// 56 known fields (15 named), 96 methods

class E2ETarget {
public:
    // Constructors / Destructors
    E2ETarget(int)  // 0x804F3910
    ~E2ETarget(void);  // 0x804F4974

    // Methods
    void OnSaveGameComplete(bool);  // 0x804F846C (96B)
    void E2ERenderCallback(ERC *, structDrawCBparams *);  // 0x804F5DE4 (924B)
    void InitializeEyeToy(void);  // 0x804F64E8 (184B)
    void OnTopLevelStateChange(char *, char *);  // 0x804F67B8 (468B)
    void UpdateText(void);  // 0x804F796C (572B)
    void SpawnNoEyeToyDialogBox(void);  // 0x804F6204 (548B)
    void UpdateShaders(char *, char *);  // 0x804F7EE0 (280B)
    void SetVariable(char *, char *);  // 0x804F4BA8 (1536B)
    void OnExitSettings(void);  // 0x804F80A4 (172B)
    void SpawnSaveGameDialog(void);  // 0x804F84CC (596B)
    void OnEnterSettings(void);  // 0x804F8054 (80B)
    void ShowHelp(void);  // 0x804F7FF8 (92B)
    void UpdateHue(char *, char *);  // 0x804F698C (200B)
    void UpdateValue(char *, char *);  // 0x804F6B1C (200B)
    void UpdateSaturation(char *, char *);  // 0x804F6A54 (200B)
    void UpdateExposure(char *, char *);  // 0x804F6D6C (200B)
    void SetDefault(char *, char *);  // 0x804F6CF0 (124B)
    void SaveCurrentSettings(char *, char *);  // 0x804F6600 (120B)
    void SetTopLevelState(char *, char *);  // 0x804F66D8 (224B)
    void ChangeSelectedSlot(char *, char *);  // 0x804F6EB4 (156B)
    void ChangeFunFrame(char *, char *);  // 0x804F6E34 (128B)
    void ChangeFilter(char *, char *);  // 0x804F6F50 (128B)
    void CaptureFrame(char *, char *);  // 0x804F6BE4 (188B)
    void SaveFrame(char *, char *);  // 0x804F6CA0 (80B)
    void OnShutdown(void);  // 0x804F5D60 (132B)
    void SaveGame(void);  // 0x804F5CF0 (112B)
    void OnLeftKeyPressed(char *, char *);  // 0x804F76A0 (716B)
    void OnRightKeyPressed(char *, char *);  // 0x804F72BC (996B)
    void OnUpKeyPressed(char *, char *);  // 0x804F71F0 (104B)
    void OnDownKeyPressed(char *, char *);  // 0x804F7258 (100B)
    void OnXKeyPressed(char *, char *);  // 0x804F6FD0 (544B)
    void OnCircleKeyPressed(char *, char *);  // 0x804F7E24 (188B)
    /* ? */ GetVariable(char *);  // 0x804F51A8 (1152B)
    /* ? */ GetTopLevelState(void);  // 0x805507D0 (52B)
    /* ? */ GetLocalizable(char *);  // 0x804F5628 (1612B)
    /* ? */ GetText(char *);  // 0x804F7BA8 (636B)
    void Update(void);  // 0x804F5C74 (124B)
    bool IsEyeToyPluggedIn(void);  // 0x804F648C (92B)
    void ReintializeEyeToy(void);  // 0x804F65A0 (96B)
    void EyeToyUnplugCallback(int);  // 0x804F6180 (76B)
    void OnEyeToyUnplugged(void);  // 0x804F61CC (56B)
    void OnExitDialog(int);  // 0x804F6428 (100B)
    void RestorePreviousSettings(void);  // 0x804F6678 (96B)
    void LaunchSaveSettingsDialog(void);  // 0x804F8150 (592B)
    void OnSaveDialogDoneCB(int);  // 0x804F83A0 (204B)
    void OnSaveGameDialogClosed(int);  // 0x804F8720 (112B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (E2ETarget, GetLocalizable, GetVariable, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (E2ETarget, GetVariable, ~E2ETarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (E2ETarget, ~E2ETarget)
    u32 m_field_00C;  // 0x00C [R/W] (E2ETarget, ~E2ETarget)
    u16 m_field_010;  // 0x010 [R/W] (E2ETarget, ~E2ETarget)
    u16 m_field_012;  // 0x012 [R] (E2ETarget)
    u32 m_field_014;  // 0x014 [R/W] (E2ETarget, ~E2ETarget)
    u32 m_field_018;  // 0x018 [R/W] (E2ETarget, ~E2ETarget)
    u32 m_shaders;  // 0x01C [R/W] (E2ETarget, UpdateShaders, ~E2ETarget)
    u32 m_field_020;  // 0x020 [R/W] (E2ETarget, ~E2ETarget)
    u32 m_field_024;  // 0x024 [R/W] (E2ETarget, ~E2ETarget)
    u32 m_field_028;  // 0x028 [W] (E2ETarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (E2ETarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (E2ETarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (E2ETarget, ~E2ETarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (E2ETarget, ~E2ETarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [R/W] (E2ETarget)
    u32 m_shaders_07C;  // 0x07C [R/W] (E2ETarget, UpdateShaders, ~E2ETarget)
    u32 m_field_080;  // 0x080 [R/W] (CaptureFrame, E2ETarget, OnCircleKeyPressed, ...)
    u32 m_variable_084;  // 0x084 [W] (E2ETarget, GetVariable)
    u32 m_field_088;  // 0x088 [R/W] (E2ERenderCallback, E2ETarget, Update)
    u32 m_field_08C;  // 0x08C [R/W] (E2ETarget, InitializeEyeToy, ReintializeEyeToy)
    u32 m_field_090;  // 0x090 [R/W] (E2ETarget, ~E2ETarget)
    u32 m_field_094;  // 0x094 [W] (E2ETarget)
    u32 m_field_098;  // 0x098 [R/W] (E2ETarget)
    u32 m_field_09C;  // 0x09C [R/W] (E2ETarget, ~E2ETarget)
    u32 m_field_0A0;  // 0x0A0 [R/W] (E2ETarget, ~E2ETarget)
    u8 _pad_0A4[4];  // 0x0A4
    u32 m_field_0A8;  // 0x0A8 [R/W] (E2ETarget, OnLeftKeyPressed, OnRightKeyPressed, ...)
    u32 m_field_0AC;  // 0x0AC [W] (E2ETarget)
    u32 m_variable_0B0;  // 0x0B0 [R/W] (E2ETarget, GetVariable)
    u32 m_variable_0B4;  // 0x0B4 [R/W] (ChangeSelectedSlot, E2ETarget, GetVariable)
    u32 m_variable_0B8;  // 0x0B8 [R/W] (E2ETarget, GetVariable)
    u32 m_variable_0BC;  // 0x0BC [R/W] (CaptureFrame, ChangeFunFrame, E2ETarget, ...)
    u32 m_field_0C0;  // 0x0C0 [R/W] (ChangeSelectedSlot, E2ETarget, OnLeftKeyPressed, ...)
    u32 m_variable_0C4;  // 0x0C4 [R/W] (ChangeFilter, E2ETarget, OnLeftKeyPressed, ...)
    f32 m_field_0C8;  // 0x0C8 [R/W] (E2ETarget, OnExitSettings, OnSaveDialogDoneCB)
    f32 m_field_0CC;  // 0x0CC [R/W] (E2ETarget, OnExitSettings, OnSaveDialogDoneCB)
    f32 m_field_0D0;  // 0x0D0 [R/W] (E2ETarget, OnExitSettings, OnSaveDialogDoneCB)
    f32 m_field_0D4;  // 0x0D4 [R/W] (E2ETarget, OnExitSettings, OnSaveDialogDoneCB)
    u32 m_localizable_0D8;  // 0x0D8 [R/W] (CaptureFrame, E2ETarget, GetLocalizable, ...)
    u32 m_topLevelState;  // 0x0DC [W] (E2ETarget, SetTopLevelState)
    u32 m_variable_0E0;  // 0x0E0 [R/W] (E2ETarget, GetVariable, OnSaveGameComplete, ...)
    u32 m_field_0E4;  // 0x0E4 [W] (E2ETarget, LaunchSaveSettingsDialog, SpawnNoEyeToyDialogBox)
    u8 _pad_0E8[8];  // 0x0E8
    u32 m_field_0F0;  // 0x0F0 [W] (LaunchSaveSettingsDialog, SpawnNoEyeToyDialogBox)
    u8 _pad_0F4[4];  // 0x0F4
    u32 m_field_0F8;  // 0x0F8 [W] (LaunchSaveSettingsDialog, SpawnNoEyeToyDialogBox)
    u8 _pad_0FC[8];  // 0x0FC
    u32 m_field_104;  // 0x104 [W] (LaunchSaveSettingsDialog, SpawnNoEyeToyDialogBox)
    u8 _pad_108[0x2C];  // 0x108
    u32 m_field_134;  // 0x134 [W] (E2ETarget, LaunchSaveSettingsDialog, SpawnNoEyeToyDialogBox)
    u8 _pad_138[0xC];  // 0x138
    u32 m_field_144;  // 0x144 [W] (E2ETarget, LaunchSaveSettingsDialog, SpawnNoEyeToyDialogBox)
    u8 _pad_148[0xC];  // 0x148
    u32 m_field_154;  // 0x154 [W] (E2ETarget, LaunchSaveSettingsDialog, SpawnNoEyeToyDialogBox)
    u8 _pad_158[0x14];  // 0x158
    u32 m_field_16C;  // 0x16C [W] (E2ETarget, SpawnSaveGameDialog)
    u8 _pad_170[0x10];  // 0x170
    u32 m_field_180;  // 0x180 [W] (SpawnSaveGameDialog)
    u8 _pad_184[0x38];  // 0x184
    u32 m_field_1BC;  // 0x1BC [W] (E2ETarget, SpawnSaveGameDialog)
    u8 _pad_1C0[0xC];  // 0x1C0
    u32 m_field_1CC;  // 0x1CC [W] (E2ETarget, SpawnSaveGameDialog)
    u8 _pad_1D0[0xC];  // 0x1D0
    u32 m_field_1DC;  // 0x1DC [W] (E2ETarget, SpawnSaveGameDialog)
    u8 _pad_1E0[0xA4];  // 0x1E0
    u32 m_variable_284;  // 0x284 [R/W] (CaptureFrame, E2ETarget, OnSaveGameComplete, ...)
};

#endif // E2ETARGET_H
