#ifndef WAFTARGET_H
#define WAFTARGET_H

#include "types.h"

// WAFTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x288 (648 bytes)
// 59 known fields (14 named), 58 methods

class WAFTarget {
public:
    // Constructors / Destructors
    WAFTarget(int)  // 0x8053E02C
    ~WAFTarget(void);  // 0x8053F52C

    // Methods
    void ShowWantsAndFears(void);  // 0x80540284 (40B)
    void SetTextButtonPressed(bool);  // 0x80542928 (44B)
    void UpdateWantsAndFears(void);  // 0x805402DC (1268B)
    void HideWantsAndFears(void);  // 0x805402AC (48B)
    void NewWantsAndFearsIcon(int, unsigned int, unsigned int, WAFTarget::eWAFIconAnim, Neighbor *);  // 0x805407FC (1348B)
    void SetVariable(char *, char *);  // 0x8053F62C (856B)
    void OnShow(void);  // 0x80542328 (240B)
    void OnBottomBarTweenComplete(void);  // 0x80541A60 (104B)
    void OnTopBarTweenComplete(void);  // 0x805419E4 (124B)
    void OnGlowEffectComplete(void);  // 0x80542104 (40B)
    /* ? */ GetVariable(char *);  // 0x8053F984 (340B)
    /* ? */ GetLocalizable(char *);  // 0x8053FAD8 (980B)
    void Update(void);  // 0x8053FEAC (984B)
    void GlowEffectAwayStart(void);  // 0x8054205C (168B)
    void StartAnimation(int);  // 0x80540D40 (584B)
    void UpdateAspirationMeter(void);  // 0x80542418 (1296B)
    void MapGameAspirationValueToMeterValue(float);  // 0x80541D4C (452B)
    void SetAspirationMeterHeight(int);  // 0x805411A4 (260B)
    void BeginMeterTween(void);  // 0x805412A8 (308B)
    void FinishSettingIcon(int);  // 0x80540F88 (540B)
    bool IsWantsAndFearsActive(void);  // 0x805407D0 (44B)
    void BeginBottomBarTween(void);  // 0x805413DC (744B)
    void BeginTopBarTween(void);  // 0x805416C4 (800B)
    void CalculateTweenTargetPosition(void);  // 0x80541BA8 (420B)
    void GlowEffectStart(void);  // 0x80541F10 (332B)
    /* ? */ GetTopBarTweenColor(void);  // 0x8054212C (508B)
    /* ? */ GetTopBarColorAtTier(void);  // 0x80541AC8 (224B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (GetLocalizable, GetVariable, NewWantsAndFearsIcon, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (GetVariable, WAFTarget, ~WAFTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (WAFTarget, ~WAFTarget)
    u32 m_field_00C;  // 0x00C [R/W] (WAFTarget, ~WAFTarget)
    u32 m_field_010;  // 0x010 [R/W] (WAFTarget, ~WAFTarget)
    u32 m_field_014;  // 0x014 [R/W] (WAFTarget, ~WAFTarget)
    u32 m_field_018;  // 0x018 [R/W] (WAFTarget, ~WAFTarget)
    u32 m_field_01C;  // 0x01C [R/W] (NewWantsAndFearsIcon, StartAnimation, UpdateWantsAndFears, ...)
    u32 m_field_020;  // 0x020 [R/W] (WAFTarget, ~WAFTarget)
    u32 m_field_024;  // 0x024 [R/W] (WAFTarget, ~WAFTarget)
    u32 m_field_028;  // 0x028 [W] (WAFTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (WAFTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (WAFTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (WAFTarget, ~WAFTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (WAFTarget, ~WAFTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (WAFTarget)
    u32 m_field_07C;  // 0x07C [R/W] (NewWantsAndFearsIcon, StartAnimation, UpdateWantsAndFears, ...)
    u32 m_field_080;  // 0x080 [W] (WAFTarget, ~WAFTarget)
    u32 m_variable_084;  // 0x084 [R/W] (GetVariable, Update, UpdateWantsAndFears, ...)
    u32 m_variable_088;  // 0x088 [R/W] (SetVariable, Update, UpdateWantsAndFears, ...)
    u32 m_variable_08C;  // 0x08C [R/W] (SetVariable, Update, WAFTarget)
    u32 m_field_090;  // 0x090 [R/W] (NewWantsAndFearsIcon, Update, WAFTarget)
    u32 m_topBarColorAtTier;  // 0x094 [R/W] (BeginBottomBarTween, BeginTopBarTween, FinishSettingIcon, ...)
    u32 m_variable_098;  // 0x098 [R/W] (SetVariable, Update, WAFTarget)
    u32 m_field_09C;  // 0x09C [R/W] (Update, WAFTarget)
    u32 m_variable_0A0;  // 0x0A0 [R/W] (SetVariable, Update, WAFTarget)
    u8 _pad_0A4[0x20];  // 0x0A4
    u32 m_field_0C4;  // 0x0C4 [W] (WAFTarget)
    u32 m_field_0C8;  // 0x0C8 [W] (WAFTarget)
    u32 m_field_0CC;  // 0x0CC [W] (WAFTarget)
    u8 _pad_0D0[0x30];  // 0x0D0
    u32 m_field_100;  // 0x100 [W] (WAFTarget)
    u32 m_field_104;  // 0x104 [W] (WAFTarget)
    u32 m_field_108;  // 0x108 [W] (WAFTarget)
    u8 _pad_10C[0x30];  // 0x10C
    u32 m_field_13C;  // 0x13C [W] (WAFTarget)
    u32 m_field_140;  // 0x140 [W] (WAFTarget)
    u32 m_field_144;  // 0x144 [W] (WAFTarget)
    u8 _pad_148[0x30];  // 0x148
    u32 m_field_178;  // 0x178 [W] (WAFTarget)
    u32 m_field_17C;  // 0x17C [W] (WAFTarget)
    u32 m_field_180;  // 0x180 [W] (WAFTarget)
    u8 _pad_184[0x30];  // 0x184
    u32 m_field_1B4;  // 0x1B4 [W] (WAFTarget)
    u32 m_field_1B8;  // 0x1B8 [W] (WAFTarget)
    u32 m_field_1BC;  // 0x1BC [W] (WAFTarget)
    u8 _pad_1C0[0x30];  // 0x1C0
    u32 m_field_1F0;  // 0x1F0 [W] (WAFTarget)
    u32 m_field_1F4;  // 0x1F4 [W] (WAFTarget)
    u32 m_field_1F8;  // 0x1F8 [W] (WAFTarget)
    u8 _pad_1FC[0x30];  // 0x1FC
    u32 m_field_22C;  // 0x22C [W] (WAFTarget)
    u32 m_field_230;  // 0x230 [W] (WAFTarget)
    u32 m_field_234;  // 0x234 [W] (WAFTarget)
    u8 _pad_238[0x10];  // 0x238
    f32 m_field_248;  // 0x248 [R/W] (Update, WAFTarget)
    u32 m_field_24C;  // 0x24C [R/W] (NewWantsAndFearsIcon, Update, WAFTarget)
    u8 _pad_250[0x14];  // 0x250
    u32 m_field_264;  // 0x264 [R/W] (BeginBottomBarTween, BeginTopBarTween, OnBottomBarTweenComplete, ...)
    u32 m_field_268;  // 0x268 [R/W] (BeginBottomBarTween, BeginMeterTween, BeginTopBarTween, ...)
    u32 m_aspirationMeterHeight;  // 0x26C [R/W] (GlowEffectAwayStart, GlowEffectStart, OnTopBarTweenComplete, ...)
    u32 m_field_270;  // 0x270 [R/W] (GlowEffectAwayStart, GlowEffectStart, UpdateWantsAndFears, ...)
    f32 m_topBarTweenColor;  // 0x274 [R/W] (BeginBottomBarTween, BeginMeterTween, CalculateTweenTargetPosition, ...)
    f32 m_topBarColorAtTier_278;  // 0x278 [R/W] (BeginBottomBarTween, BeginMeterTween, BeginTopBarTween, ...)
    f32 m_field_27C;  // 0x27C [R/W] (BeginBottomBarTween, BeginTopBarTween, OnBottomBarTweenComplete, ...)
    u32 m_variable_280;  // 0x280 [R/W] (SetVariable, Update, WAFTarget)
    u32 m_wantsAndFears;  // 0x284 [R/W] (UpdateWantsAndFears, WAFTarget)
};

#endif // WAFTARGET_H
