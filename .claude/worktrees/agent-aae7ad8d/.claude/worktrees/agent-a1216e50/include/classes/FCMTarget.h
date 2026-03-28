#ifndef FCMTARGET_H
#define FCMTARGET_H

#include "types.h"

// FCMTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0xA8 (168 bytes)
// 28 known fields (11 named), 24 methods

class FCMTarget {
public:
    // Constructors / Destructors
    FCMTarget(void)  // 0x804FF138
    ~FCMTarget(void);  // 0x804FF520

    // Methods
    void ShowFireCodeMeter(void);  // 0x804FFC8C (596B)
    void HideFireCodeMeter(void);  // 0x804FFEE0 (40B)
    void UpdateFireCodeMeter(void);  // 0x804FFF08 (796B)
    void SetVariable(char *, char *);  // 0x804FF5A0 (516B)
    /* ? */ GetVariable(char *);  // 0x804FF7A4 (340B)
    /* ? */ GetLocalizable(char *);  // 0x804FF8F8 (600B)
    void Update(void);  // 0x804FFB50 (316B)
    /* ? */ GetFireCodeMeterLevel(void);  // 0x80500224 (96B)
    void SetMeterHeight(int);  // 0x805002B0 (92B)
    bool IsFireCodeMeterActive(void);  // 0x80500284 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_variable;  // 0x000 [R/W] (FCMTarget, GetLocalizable, GetVariable, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable_004;  // 0x004 [R/W] (FCMTarget, GetVariable, ~FCMTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (FCMTarget, ~FCMTarget)
    u32 m_field_00C;  // 0x00C [R/W] (FCMTarget, ~FCMTarget)
    u32 m_field_010;  // 0x010 [R/W] (FCMTarget, ~FCMTarget)
    u32 m_field_014;  // 0x014 [R/W] (FCMTarget, ~FCMTarget)
    u32 m_field_018;  // 0x018 [R/W] (FCMTarget, ~FCMTarget)
    u32 m_field_01C;  // 0x01C [R/W] (FCMTarget, ~FCMTarget)
    u32 m_field_020;  // 0x020 [R/W] (FCMTarget, ~FCMTarget)
    u32 m_field_024;  // 0x024 [R/W] (FCMTarget, ~FCMTarget)
    u32 m_field_028;  // 0x028 [W] (FCMTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (FCMTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (FCMTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (FCMTarget, ~FCMTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (FCMTarget, ~FCMTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (FCMTarget)
    u32 m_field_07C;  // 0x07C [R/W] (FCMTarget, ~FCMTarget)
    u32 m_field_080;  // 0x080 [W] (FCMTarget, ~FCMTarget)
    u32 m_variable_084;  // 0x084 [R/W] (FCMTarget, GetVariable, Update)
    u32 m_variable_088;  // 0x088 [R/W] (FCMTarget, SetVariable, Update, ...)
    u32 m_variable_08C;  // 0x08C [R/W] (FCMTarget, SetVariable, Update)
    u32 m_field_090;  // 0x090 [R/W] (FCMTarget, ShowFireCodeMeter, Update, ...)
    u32 m_variable_094;  // 0x094 [R/W] (FCMTarget, SetVariable, UpdateFireCodeMeter)
    u32 m_variable_098;  // 0x098 [R/W] (FCMTarget, SetVariable, ShowFireCodeMeter, ...)
    u32 m_variable_09C;  // 0x09C [R/W] (FCMTarget, SetVariable, UpdateFireCodeMeter)
    u32 m_fireCodeMeter;  // 0x0A0 [R/W] (FCMTarget, UpdateFireCodeMeter)
    u32 m_fireCodeMeter_0A4;  // 0x0A4 [R/W] (FCMTarget, ShowFireCodeMeter, UpdateFireCodeMeter)
};

#endif // FCMTARGET_H
