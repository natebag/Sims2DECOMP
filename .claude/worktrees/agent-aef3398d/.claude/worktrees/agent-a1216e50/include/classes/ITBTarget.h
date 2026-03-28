#ifndef ITBTARGET_H
#define ITBTARGET_H

#include "types.h"

// ITBTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0xA0 (160 bytes)
// 26 known fields (9 named), 24 methods

class ITBTarget {
public:
    // Constructors / Destructors
    ITBTarget(void)  // 0x8050CB34
    ~ITBTarget(void);  // 0x8050CEBC

    // Methods
    void UpdateIntroThoughtBalloon(void);  // 0x8050DA1C (140B)
    /* ? */ GetUserReadTime(void);  // 0x8050DC84 (44B)
    void SpawnIntroThoughtBalloon(UIDialog *);  // 0x8050DAD4 (432B)
    void SetVariable(char *, char *);  // 0x8050CF5C (568B)
    /* ? */ GetVariable(char *);  // 0x8050D194 (340B)
    /* ? */ GetLocalizable(char *);  // 0x8050D2E8 (656B)
    void Update(void);  // 0x8050D578 (1108B)
    void ShowIntroThoughtBalloon(void);  // 0x8050D9CC (40B)
    void HideIntroThoughtBalloon(void);  // 0x8050D9F4 (40B)
    bool IsIntroThoughtBalloonActive(void);  // 0x8050DAA8 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_variable;  // 0x000 [R/W] (GetLocalizable, GetVariable, ITBTarget, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable_004;  // 0x004 [R/W] (GetVariable, ITBTarget, ~ITBTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (ITBTarget, ~ITBTarget)
    u32 m_field_00C;  // 0x00C [R/W] (ITBTarget, ~ITBTarget)
    u32 m_field_010;  // 0x010 [R/W] (ITBTarget, ~ITBTarget)
    u32 m_field_014;  // 0x014 [R/W] (ITBTarget, ~ITBTarget)
    u32 m_field_018;  // 0x018 [R/W] (ITBTarget, ~ITBTarget)
    u32 m_field_01C;  // 0x01C [R/W] (ITBTarget, ~ITBTarget)
    u32 m_field_020;  // 0x020 [R/W] (ITBTarget, ~ITBTarget)
    u32 m_field_024;  // 0x024 [R/W] (ITBTarget, ~ITBTarget)
    u32 m_field_028;  // 0x028 [W] (ITBTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (ITBTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (ITBTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (ITBTarget, ~ITBTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (ITBTarget, ~ITBTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (ITBTarget)
    u32 m_field_07C;  // 0x07C [R/W] (ITBTarget, ~ITBTarget)
    u32 m_field_080;  // 0x080 [W] (ITBTarget, ~ITBTarget)
    u32 m_variable_084;  // 0x084 [R/W] (GetVariable, ITBTarget, Update)
    u32 m_variable_088;  // 0x088 [R/W] (ITBTarget, SetVariable, Update, ...)
    u32 m_localizable;  // 0x08C [R/W] (GetLocalizable, ITBTarget, SpawnIntroThoughtBalloon, ...)
    u32 m_variable_090;  // 0x090 [R/W] (ITBTarget, SetVariable, Update)
    u32 m_variable_094;  // 0x094 [R/W] (ITBTarget, SetVariable, Update, ...)
    u32 m_field_098;  // 0x098 [R/W] (ITBTarget, Update)
    f32 m_introThoughtBalloon;  // 0x09C [R/W] (ITBTarget, SpawnIntroThoughtBalloon, UpdateIntroThoughtBalloon)
};

#endif // ITBTARGET_H
