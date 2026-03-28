#ifndef WXFTARGET_H
#define WXFTARGET_H

#include "types.h"

// WXFTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x19C (412 bytes)
// 30 known fields (11 named), 36 methods

class WXFTarget {
public:
    // Constructors / Destructors
    WXFTarget(int)  // 0x80542954
    ~WXFTarget(void);  // 0x805430FC

    // Methods
    void UpdateShaders(void);  // 0x80544158 (1424B)
    void SetVariable(char *, char *);  // 0x805431C8 (468B)
    void Shutdown(void);  // 0x80543C98 (132B)
    void OnCancelKeyPressed(char *, char *);  // 0x805440C4 (148B)
    void UpdateMenuState(char *, char *);  // 0x80543D3C (216B)
    void OnLeftKeyPressed(char *, char *);  // 0x80543F44 (192B)
    void OnRightKeyPressed(char *, char *);  // 0x80544004 (192B)
    void ShowHelp(void);  // 0x80544B10 (212B)
    /* ? */ GetLocalizable(char *);  // 0x8054339C (1760B)
    void UpdateWAFText(char *);  // 0x805447C8 (744B)
    /* ? */ GetAspirationIcon(void);  // 0x80544BE4 (164B)
    /* ? */ GetVariable(char *);  // 0x80543A7C (540B)
    void Update(void);  // 0x80543D1C (32B)
    void UpdateText(void);  // 0x80543E14 (304B)
    /* ? */ GetBackgroundShader(tWantType);  // 0x805446E8 (224B)
    void onHelpDialogSelection(int);  // 0x80544AB0 (96B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (GetLocalizable, GetVariable, UpdateShaders, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_aspirationIcon;  // 0x004 [R/W] (GetAspirationIcon, GetVariable, UpdateShaders, ...)
    u8 m_variable;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (WXFTarget, ~WXFTarget)
    u32 m_field_00C;  // 0x00C [R/W] (WXFTarget, ~WXFTarget)
    u32 m_field_010;  // 0x010 [R/W] (WXFTarget, ~WXFTarget)
    u32 m_field_014;  // 0x014 [R/W] (WXFTarget, ~WXFTarget)
    u32 m_field_018;  // 0x018 [R/W] (WXFTarget, ~WXFTarget)
    u32 m_shaders;  // 0x01C [R/W] (UpdateShaders, WXFTarget, ~WXFTarget)
    u32 m_field_020;  // 0x020 [R/W] (WXFTarget, ~WXFTarget)
    u32 m_field_024;  // 0x024 [R/W] (WXFTarget, ~WXFTarget)
    u32 m_field_028;  // 0x028 [W] (WXFTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (WXFTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (WXFTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (WXFTarget, ~WXFTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (WXFTarget, ~WXFTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (WXFTarget)
    u32 m_shaders_07C;  // 0x07C [R/W] (UpdateShaders, WXFTarget, ~WXFTarget)
    u32 m_field_080;  // 0x080 [R/W] (OnLeftKeyPressed, OnRightKeyPressed, WXFTarget, ...)
    u32 m_field_084;  // 0x084 [W] (WXFTarget, ~WXFTarget)
    u32 m_variable_088;  // 0x088 [W] (GetVariable, WXFTarget)
    u32 m_field_08C;  // 0x08C [R/W] (OnLeftKeyPressed, OnRightKeyPressed, UpdateMenuState, ...)
    u32 m_menuState;  // 0x090 [W] (UpdateMenuState, WXFTarget)
    u32 m_aspirationIcon_094;  // 0x094 [R/W] (GetAspirationIcon, ShowHelp, UpdateShaders, ...)
    u32 m_field_098;  // 0x098 [R/W] (WXFTarget, ~WXFTarget)
    u32 m_field_09C;  // 0x09C [R/W] (WXFTarget, ~WXFTarget)
    u8 _pad_0A0[0x18];  // 0x0A0
    s16 m_shaders_0B8;  // 0x0B8 [R] (UpdateShaders, UpdateWAFText)
    u8 _pad_0BA[0x6E];  // 0x0BA
    u32 m_variable_128;  // 0x128 [R] (GetVariable, SetVariable)
    u8 _pad_12C[4];  // 0x12C
    u32 m_field_130;  // 0x130 [R/W] (ShowHelp, WXFTarget)
    u8 _pad_134[0x64];  // 0x134
    u32 m_shaders_198;  // 0x198 [R] (UpdateShaders)
};

#endif // WXFTARGET_H
