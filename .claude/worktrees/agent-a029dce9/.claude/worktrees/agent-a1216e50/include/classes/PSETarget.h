#ifndef PSETARGET_H
#define PSETARGET_H

#include "types.h"

// PSETarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x94 (148 bytes)
// 23 known fields (4 named), 12 methods

class PSETarget {
public:
    // Constructors / Destructors
    PSETarget(void)  // 0x805889DC
    ~PSETarget(void);  // 0x80588D7C

    // Methods
    void PushAptButtonFilters(void);  // 0x80589100 (936B)
    void PopAptButtonFilters(void);  // 0x805894A8 (236B)
    /* ? */ GetVariable(char *);  // 0x80588E40 (360B)
    void SetVariable(char *, char *);  // 0x80588FA8 (344B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_variable;  // 0x000 [R/W] (GetVariable, PSETarget, ~PSETarget)
    u8 m_variable_001;  // 0x001 [W] (GetVariable)
    u8 _pad_002[2];  // 0x002
    u16 m_variable_004;  // 0x004 [R/W] (GetVariable, PSETarget, ~PSETarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (PSETarget, ~PSETarget)
    u32 m_field_00C;  // 0x00C [R/W] (PSETarget, ~PSETarget)
    u32 m_field_010;  // 0x010 [R/W] (PSETarget, ~PSETarget)
    u32 m_field_014;  // 0x014 [R/W] (PSETarget, ~PSETarget)
    u32 m_field_018;  // 0x018 [R/W] (PSETarget, ~PSETarget)
    u32 m_field_01C;  // 0x01C [R/W] (PSETarget, ~PSETarget)
    u32 m_field_020;  // 0x020 [R/W] (PSETarget, ~PSETarget)
    u32 m_field_024;  // 0x024 [R/W] (PSETarget, ~PSETarget)
    u32 m_field_028;  // 0x028 [W] (PSETarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (PSETarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (PSETarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (PSETarget, ~PSETarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (PSETarget, ~PSETarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (PSETarget)
    u32 m_field_07C;  // 0x07C [R/W] (PSETarget, PushAptButtonFilters, ~PSETarget)
    u32 m_field_080;  // 0x080 [W] (PSETarget, ~PSETarget)
    u32 m_field_084;  // 0x084 [R/W] (PSETarget, ~PSETarget)
    u8 _pad_088[4];  // 0x088
    u32 m_field_08C;  // 0x08C [W] (PSETarget)
    u32 m_field_090;  // 0x090 [W] (PSETarget)
};

#endif // PSETARGET_H
