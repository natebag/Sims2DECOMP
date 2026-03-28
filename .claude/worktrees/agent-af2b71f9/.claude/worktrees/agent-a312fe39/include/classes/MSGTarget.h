#ifndef MSGTARGET_H
#define MSGTARGET_H

#include "types.h"

// MSGTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0xA0 (160 bytes)
// 23 known fields (8 named), 14 methods

class MSGTarget {
public:
    // Constructors / Destructors
    MSGTarget(int)  // 0x80581778
    ~MSGTarget(void);  // 0x80581F88

    // Methods
    void DeliverXamMessage(int, unsigned short);  // 0x80581548 (560B)
    void SetupTitles(int);  // 0x80582138 (484B)
    /* ? */ GetVariable(char *);  // 0x8058231C (656B)
    void SetVariable(char *, char *);  // 0x805825AC (1412B)
    /* ? */ GetLocalizable(char *);  // 0x80582B30 (764B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (GetLocalizable, GetVariable, MSGTarget, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (GetVariable, MSGTarget, ~MSGTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (MSGTarget, ~MSGTarget)
    u32 m_field_00C;  // 0x00C [R/W] (MSGTarget, ~MSGTarget)
    u32 m_field_010;  // 0x010 [R/W] (MSGTarget, ~MSGTarget)
    u32 m_field_014;  // 0x014 [R/W] (MSGTarget, ~MSGTarget)
    u32 m_field_018;  // 0x018 [R/W] (MSGTarget, ~MSGTarget)
    u32 m_variable_01C;  // 0x01C [R/W] (MSGTarget, SetVariable, ~MSGTarget)
    u32 m_field_020;  // 0x020 [R/W] (MSGTarget, ~MSGTarget)
    u32 m_field_024;  // 0x024 [R/W] (MSGTarget, ~MSGTarget)
    u32 m_field_028;  // 0x028 [W] (MSGTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (MSGTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (MSGTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (MSGTarget, ~MSGTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (MSGTarget, ~MSGTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (MSGTarget)
    u32 m_variable_07C;  // 0x07C [R/W] (MSGTarget, SetVariable, ~MSGTarget)
    u32 m_field_080;  // 0x080 [W] (MSGTarget, ~MSGTarget)
    u32 m_variable_084;  // 0x084 [R/W] (GetVariable, MSGTarget)
    u32 m_variable_088;  // 0x088 [R/W] (GetVariable, MSGTarget, SetVariable)
    u8 _pad_08C[0xC];  // 0x08C
    u32 m_variable_098;  // 0x098 [R/W] (GetVariable, MSGTarget, SetVariable, ...)
    u32 m_field_09C;  // 0x09C [R/W] (MSGTarget, ~MSGTarget)
};

#endif // MSGTARGET_H
