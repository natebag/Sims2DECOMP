#ifndef CSMTARGET_H
#define CSMTARGET_H

#include "types.h"

// CSMTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0xF0 (240 bytes)
// 37 known fields (11 named), 22 methods

class CSMTarget {
public:
    // Constructors / Destructors
    CSMTarget(int)  // 0x804EDC9C
    ~CSMTarget(void);  // 0x804EE2DC

    // Methods
    bool IsCSIMActive(void);  // 0x804EF83C (44B)
    void HideCSIM(void);  // 0x804EF808 (52B)
    void ShowCSIM(void);  // 0x804EF7D8 (48B)
    void TempInterface(BString2 *, BString2 *, BString2 *, BString2 *, bool, bool);  // 0x804EF868 (1308B)
    void SetVariable(char *, char *);  // 0x804EE408 (552B)
    /* ? */ GetVariable(char *);  // 0x804EE630 (340B)
    /* ? */ GetLocalizable(char *);  // 0x804EE784 (872B)
    void Update(void);  // 0x804EEAEC (3308B)
    void SetIconDisable(bool);  // 0x804EFD84 (220B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (CSMTarget, GetLocalizable, GetVariable, ...)
    u8 _pad_002[2];  // 0x002
    s16 m_variable;  // 0x004 [R/W] (CSMTarget, GetVariable, Update, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (CSMTarget, ~CSMTarget)
    u32 m_field_00C;  // 0x00C [R/W] (CSMTarget, ~CSMTarget)
    u32 m_field_010;  // 0x010 [R/W] (CSMTarget, Update, ~CSMTarget)
    u32 m_field_014;  // 0x014 [R/W] (CSMTarget, ~CSMTarget)
    u32 m_field_018;  // 0x018 [R/W] (CSMTarget, ~CSMTarget)
    u32 m_field_01C;  // 0x01C [R/W] (CSMTarget, Update, ~CSMTarget)
    u32 m_field_020;  // 0x020 [R/W] (CSMTarget, ~CSMTarget)
    u32 m_field_024;  // 0x024 [R/W] (CSMTarget, ~CSMTarget)
    u32 m_field_028;  // 0x028 [W] (CSMTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (CSMTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (CSMTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (CSMTarget, ~CSMTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (CSMTarget, ~CSMTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (CSMTarget)
    u32 m_field_07C;  // 0x07C [R/W] (CSMTarget, Update, ~CSMTarget)
    u32 m_field_080;  // 0x080 [W] (CSMTarget, ~CSMTarget)
    u32 m_variable_084;  // 0x084 [R/W] (CSMTarget, GetVariable, Update)
    u32 m_variable_088;  // 0x088 [R/W] (CSMTarget, SetIconDisable, SetVariable, ...)
    u32 m_iconDisable;  // 0x08C [R/W] (CSMTarget, SetIconDisable, SetVariable, ...)
    u32 m_field_090;  // 0x090 [R/W] (CSMTarget, Update)
    u32 m_variable_094;  // 0x094 [R/W] (CSMTarget, SetVariable, Update)
    u32 m_field_098;  // 0x098 [R/W] (CSMTarget, Update)
    u32 m_field_09C;  // 0x09C [R/W] (CSMTarget, Update)
    u32 m_variable_0A0;  // 0x0A0 [R/W] (CSMTarget, SetVariable, Update)
    u32 m_variable_0A4;  // 0x0A4 [R/W] (CSMTarget, SetVariable, Update)
    u8 _pad_0A8[8];  // 0x0A8
    u32 m_localizable_0B0;  // 0x0B0 [R/W] (CSMTarget, GetLocalizable, TempInterface, ...)
    u32 m_field_0B4;  // 0x0B4 [R] (TempInterface)
    u32 m_field_0B8;  // 0x0B8 [R] (TempInterface)
    u32 m_field_0BC;  // 0x0BC [R] (TempInterface)
    u32 m_field_0C0;  // 0x0C0 [R] (Update)
    u8 _pad_0C4[8];  // 0x0C4
    u32 m_field_0CC;  // 0x0CC [R/W] (CSMTarget, TempInterface)
    u32 m_field_0D0;  // 0x0D0 [R/W] (CSMTarget, TempInterface)
    u32 m_iconDisable_0D4;  // 0x0D4 [R/W] (CSMTarget, SetIconDisable, Update)
    u8 _pad_0D8[0x14];  // 0x0D8
    u32 m_field_0EC;  // 0x0EC [R] (Update)
};

#endif // CSMTARGET_H
