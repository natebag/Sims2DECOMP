#ifndef BBHTARGET_H
#define BBHTARGET_H

#include "types.h"

// BBHTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0xA8 (168 bytes)
// 28 known fields (10 named), 26 methods

class BBHTarget {
public:
    // Constructors / Destructors
    BBHTarget(int)  // 0x804EA398
    ~BBHTarget(void);  // 0x804EA700

    // Methods
    void SetVariable(char *, char *);  // 0x804EA7C0 (416B)
    /* ? */ GetVariable(char *);  // 0x804EA960 (340B)
    /* ? */ GetLocalizable(char *);  // 0x804EAAB4 (1388B)
    void Update(void);  // 0x804EB020 (396B)
    void SetCurrentPrice(int);  // 0x804EB1AC (144B)
    bool IsBuildBuyHUDActive(void);  // 0x804EB23C (44B)
    void ShowBuildBuyHUD(void);  // 0x804EB268 (40B)
    void HideBuildBuyHUD(void);  // 0x804EB290 (40B)
    void UpdateBuildBuyHUD(void);  // 0x804EB2B8 (356B)
    void SetSellingPig(bool);  // 0x804EB41C (132B)
    void SetBBHMode(BBHTarget::eBBHMode);  // 0x804EB4A0 (132B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_variable;  // 0x000 [R/W] (BBHTarget, GetLocalizable, GetVariable, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable_004;  // 0x004 [R/W] (BBHTarget, GetVariable, ~BBHTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (BBHTarget, ~BBHTarget)
    u32 m_field_00C;  // 0x00C [R/W] (BBHTarget, ~BBHTarget)
    u32 m_field_010;  // 0x010 [R/W] (BBHTarget, ~BBHTarget)
    u32 m_field_014;  // 0x014 [R/W] (BBHTarget, ~BBHTarget)
    u32 m_field_018;  // 0x018 [R/W] (BBHTarget, ~BBHTarget)
    u32 m_field_01C;  // 0x01C [R/W] (BBHTarget, ~BBHTarget)
    u32 m_field_020;  // 0x020 [R/W] (BBHTarget, ~BBHTarget)
    u32 m_field_024;  // 0x024 [R/W] (BBHTarget, ~BBHTarget)
    u32 m_field_028;  // 0x028 [W] (BBHTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (BBHTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (BBHTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (BBHTarget, ~BBHTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (BBHTarget, ~BBHTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (BBHTarget)
    u32 m_field_07C;  // 0x07C [R/W] (BBHTarget, ~BBHTarget)
    u32 m_field_080;  // 0x080 [W] (BBHTarget, ~BBHTarget)
    u32 m_variable_084;  // 0x084 [R/W] (BBHTarget, GetVariable, SetCurrentPrice, ...)
    u32 m_variable_088;  // 0x088 [R/W] (BBHTarget, SetVariable, Update)
    u32 m_variable_08C;  // 0x08C [R/W] (BBHTarget, SetVariable, Update)
    u32 m_buildBuyHUD;  // 0x090 [R/W] (BBHTarget, Update, UpdateBuildBuyHUD)
    u32 m_field_094;  // 0x094 [W] (BBHTarget)
    u32 m_localizable;  // 0x098 [R/W] (BBHTarget, GetLocalizable, SetCurrentPrice)
    u32 m_sellingPig;  // 0x09C [R/W] (BBHTarget, SetSellingPig, Update)
    u32 m_localizable_0A0;  // 0x0A0 [R/W] (BBHTarget, GetLocalizable, SetBBHMode)
    u32 m_field_0A4;  // 0x0A4 [R/W] (BBHTarget, Update, UpdateBuildBuyHUD, ...)
};

#endif // BBHTARGET_H
