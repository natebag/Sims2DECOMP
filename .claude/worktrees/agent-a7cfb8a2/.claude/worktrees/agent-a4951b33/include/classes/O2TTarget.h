#ifndef O2TTARGET_H
#define O2TTARGET_H

#include "types.h"

// O2TTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x25C (604 bytes)
// 56 known fields (19 named), 80 methods

class O2TTarget {
public:
    // Constructors / Destructors
    O2TTarget(int, int)  // 0x80520F34
    ~O2TTarget(void);  // 0x805218AC

    // Methods
    void OnSaveGameComplete(bool);  // 0x80523F38 (88B)
    void OnTopLevelStateChange(char *, char *);  // 0x80523DD0 (304B)
    void RememberOptions(void);  // 0x80524848 (272B)
    void UpdateText(void);  // 0x80524E64 (884B)
    void SetVariable(char *, char *);  // 0x80521998 (4636B)
    void SetTopLevelState(char *, char *);  // 0x80523D2C (164B)
    void StartScreenWizard(char *, char *);  // 0x80525CF0 (168B)
    void ExitScreenWizard(char *, char *);  // 0x80525D98 (96B)
    void UpdateShaders(char *, char *);  // 0x80525A58 (464B)
    void RememberAudioOptions(void);  // 0x805245B8 (128B)
    void RememberGameOptions(void);  // 0x80524748 (128B)
    void OnStateChange(void);  // 0x80524044 (268B)
    void ShowHelp(void);  // 0x80525C28 (200B)
    void Shutdown(char *, char *);  // 0x80523F90 (180B)
    /* ? */ GetScreenXGlobal(float);  // 0x80524BEC (200B)
    /* ? */ GetScreenYGlobal(float);  // 0x80524D9C (200B)
    void OnLeftKeyPressed(char *, char *);  // 0x805258C8 (212B)
    void OnRightKeyPressed(char *, char *);  // 0x805257F4 (212B)
    void OnUpKeyPressed(char *, char *);  // 0x805256BC (156B)
    void OnDownKeyPressed(char *, char *);  // 0x80525758 (156B)
    void OnXKeyPressed(char *, char *);  // 0x805251D8 (256B)
    void OnCircleKeyPressed(char *, char *);  // 0x8052599C (188B)
    /* ? */ GetVariable(char *);  // 0x80522BB4 (2052B)
    /* ? */ GetScreenXLocal(signed char);  // 0x80524B04 (232B)
    /* ? */ GetScreenYLocal(signed char);  // 0x80524CB4 (232B)
    /* ? */ GetLocalizable(char *);  // 0x805233B8 (2420B)
    void SaveGame(char *, char *);  // 0x80523F00 (56B)
    void AudioOptionsModified(void);  // 0x80524150 (208B)
    void SpawnSaveSettingsDialog(void);  // 0x805242D0 (600B)
    void GameOptionsModified(void);  // 0x80524220 (176B)
    void OnSaveSettingsDialogClose(int);  // 0x80524528 (144B)
    void RestoreAudioOptions(void);  // 0x80524638 (272B)
    void RestoreGameOptions(void);  // 0x805247C8 (128B)
    void RestoreOptions(void);  // 0x80524958 (428B)
    void OnQuitGameDialogClose(int);  // 0x8052562C (144B)
    void OnCancelDialog(void);  // 0x805255E4 (72B)
    void SpawnQuitDialogBox(void);  // 0x805252D8 (780B)
    void QuitGame(char *, char *);  // 0x80525DF8 (72B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (ExitScreenWizard, GetLocalizable, GetVariable, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (GetVariable, O2TTarget, ~O2TTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (O2TTarget, ~O2TTarget)
    u32 m_field_00C;  // 0x00C [R/W] (O2TTarget, ~O2TTarget)
    u32 m_field_010;  // 0x010 [R/W] (O2TTarget, ~O2TTarget)
    u32 m_field_014;  // 0x014 [R/W] (O2TTarget, ~O2TTarget)
    u32 m_field_018;  // 0x018 [R/W] (O2TTarget, ~O2TTarget)
    u32 m_field_01C;  // 0x01C [R/W] (ExitScreenWizard, O2TTarget, StartScreenWizard, ...)
    u32 m_field_020;  // 0x020 [R/W] (O2TTarget, ~O2TTarget)
    u32 m_field_024;  // 0x024 [R/W] (O2TTarget, ~O2TTarget)
    u32 m_field_028;  // 0x028 [W] (O2TTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (O2TTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (O2TTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (O2TTarget, ~O2TTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (O2TTarget, ~O2TTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (O2TTarget)
    u32 m_field_07C;  // 0x07C [R/W] (ExitScreenWizard, O2TTarget, StartScreenWizard, ...)
    u32 m_field_080;  // 0x080 [R/W] (O2TTarget, OnCircleKeyPressed, ~O2TTarget)
    u32 m_variable_084;  // 0x084 [W] (GetVariable, O2TTarget)
    u32 m_localizable_088;  // 0x088 [R/W] (GetLocalizable, O2TTarget, OnCircleKeyPressed, ...)
    u32 m_variable_08C;  // 0x08C [W] (O2TTarget, SetTopLevelState, SetVariable)
    u32 m_variable_090;  // 0x090 [R/W] (GetVariable, O2TTarget, OnSaveGameComplete, ...)
    u32 m_field_094;  // 0x094 [W] (O2TTarget)
    u32 m_field_098;  // 0x098 [W] (O2TTarget)
    u32 m_field_09C;  // 0x09C [R/W] (O2TTarget, OnDownKeyPressed, OnUpKeyPressed, ...)
    u32 m_field_0A0;  // 0x0A0 [R/W] (O2TTarget, OnDownKeyPressed, OnLeftKeyPressed, ...)
    u32 m_field_0A4;  // 0x0A4 [W] (O2TTarget, SpawnQuitDialogBox)
    u8 _pad_0A8[8];  // 0x0A8
    u32 m_field_0B0;  // 0x0B0 [W] (SpawnQuitDialogBox)
    u8 _pad_0B4[4];  // 0x0B4
    u32 m_field_0B8;  // 0x0B8 [W] (SpawnQuitDialogBox)
    u8 _pad_0BC[8];  // 0x0BC
    u32 m_field_0C4;  // 0x0C4 [W] (SpawnQuitDialogBox)
    u8 _pad_0C8[0x2C];  // 0x0C8
    u32 m_field_0F4;  // 0x0F4 [W] (O2TTarget, SpawnQuitDialogBox)
    u8 _pad_0F8[0xC];  // 0x0F8
    u32 m_field_104;  // 0x104 [W] (O2TTarget, SpawnQuitDialogBox)
    u8 _pad_108[0xC];  // 0x108
    u32 m_field_114;  // 0x114 [W] (O2TTarget, SpawnQuitDialogBox)
    u8 _pad_118[0x14];  // 0x118
    u32 m_field_12C;  // 0x12C [W] (O2TTarget, SpawnSaveSettingsDialog)
    u8 _pad_130[8];  // 0x130
    u32 m_field_138;  // 0x138 [W] (SpawnSaveSettingsDialog)
    u8 _pad_13C[4];  // 0x13C
    u32 m_field_140;  // 0x140 [W] (SpawnSaveSettingsDialog)
    u8 _pad_144[8];  // 0x144
    u32 m_field_14C;  // 0x14C [W] (SpawnSaveSettingsDialog)
    u8 _pad_150[0x2C];  // 0x150
    u32 m_field_17C;  // 0x17C [W] (O2TTarget, SpawnSaveSettingsDialog)
    u8 _pad_180[0xC];  // 0x180
    u32 m_field_18C;  // 0x18C [W] (O2TTarget, SpawnSaveSettingsDialog)
    u8 _pad_190[0xC];  // 0x190
    u32 m_field_19C;  // 0x19C [W] (O2TTarget, SpawnSaveSettingsDialog)
    u8 _pad_1A0[0x14];  // 0x1A0
    u32 m_variable_1B4;  // 0x1B4 [R/W] (O2TTarget, SetVariable, ShowHelp)
    u32 m_field_1B8;  // 0x1B8 [R/W] (O2TTarget, ~O2TTarget)
    u32 m_field_1BC;  // 0x1BC [R/W] (O2TTarget, ~O2TTarget)
    u32 m_variable_1C0;  // 0x1C0 [W] (SetVariable)
    u8 _pad_1C4[8];  // 0x1C4
    u32 m_variable_1CC;  // 0x1CC [W] (SetVariable)
    u8 _pad_1D0[4];  // 0x1D0
    u32 m_variable_1D4;  // 0x1D4 [W] (SetVariable)
    u8 _pad_1D8[8];  // 0x1D8
    u32 m_variable_1E0;  // 0x1E0 [W] (SetVariable)
    u32 m_variable_1E4;  // 0x1E4 [W] (SetVariable)
    u8 _pad_1E8[0x28];  // 0x1E8
    u32 m_variable_210;  // 0x210 [W] (SetVariable)
    u8 _pad_214[0xC];  // 0x214
    u32 m_variable_220;  // 0x220 [W] (SetVariable)
    u8 _pad_224[0xC];  // 0x224
    u32 m_variable_230;  // 0x230 [W] (SetVariable)
    u8 _pad_234[0x14];  // 0x234
    u32 m_variable_248;  // 0x248 [R] (GetVariable, SetVariable, ShowHelp, ...)
    u8 _pad_24C[4];  // 0x24C
    u32 m_field_250;  // 0x250 [W] (O2TTarget, OnQuitGameDialogClose)
    u32 m_variable_254;  // 0x254 [R/W] (O2TTarget, SetVariable, ShowHelp, ...)
    u32 m_variable_258;  // 0x258 [R/W] (O2TTarget, OnSaveSettingsDialogClose, OnStateChange, ...)
};

#endif // O2TTARGET_H
