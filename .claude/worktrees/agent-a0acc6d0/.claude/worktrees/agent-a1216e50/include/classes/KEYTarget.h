#ifndef KEYTARGET_H
#define KEYTARGET_H

#include "types.h"

// KEYTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x90 (144 bytes)
// 23 known fields (5 named), 12 methods

class KEYTarget {
public:
    // Constructors / Destructors
    KEYTarget(void)  // 0x805808B4
    ~KEYTarget(void);  // 0x80580C58

    // Methods
    /* ? */ GetName(void);  // 0x80580CC8 (468B)
    bool IsModeValid(void);  // 0x80580E9C (124B)
    void SetVariable(char *, char *);  // 0x80580F18 (996B)
    /* ? */ GetVariable(char *);  // 0x805812FC (588B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_variable;  // 0x000 [R/W] (GetVariable, KEYTarget, ~KEYTarget)
    u8 _pad_001[3];  // 0x001
    u16 m_variable_004;  // 0x004 [R/W] (GetVariable, KEYTarget, ~KEYTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (KEYTarget, ~KEYTarget)
    u32 m_field_00C;  // 0x00C [R/W] (KEYTarget, ~KEYTarget)
    u32 m_field_010;  // 0x010 [R/W] (KEYTarget, ~KEYTarget)
    u32 m_field_014;  // 0x014 [R/W] (KEYTarget, ~KEYTarget)
    u32 m_field_018;  // 0x018 [R/W] (KEYTarget, ~KEYTarget)
    u32 m_field_01C;  // 0x01C [R/W] (KEYTarget, ~KEYTarget)
    u8 m_variable_01F;  // 0x01F [W] (GetVariable)
    u32 m_field_020;  // 0x020 [R/W] (KEYTarget, ~KEYTarget)
    u32 m_field_024;  // 0x024 [R/W] (KEYTarget, ~KEYTarget)
    u32 m_field_028;  // 0x028 [W] (KEYTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (KEYTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (KEYTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (KEYTarget, ~KEYTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (KEYTarget, ~KEYTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (KEYTarget)
    u32 m_field_07C;  // 0x07C [R/W] (KEYTarget, ~KEYTarget)
    u32 m_field_080;  // 0x080 [W] (KEYTarget, ~KEYTarget)
    u32 m_field_084;  // 0x084 [W] (KEYTarget)
    u32 m_field_088;  // 0x088 [W] (KEYTarget, ~KEYTarget)
    u32 m_name;  // 0x08C [R/W] (GetName, KEYTarget, SetVariable)
};

#endif // KEYTARGET_H
