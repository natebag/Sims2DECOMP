#ifndef FONTARGET_H
#define FONTARGET_H

#include "types.h"

// FONTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x5BC8 (23496 bytes)
// 28 known fields (7 named), 10 methods

class FONTarget {
public:
    // Constructors / Destructors
    FONTarget(int)  // 0x8056A0A4
    ~FONTarget(void);  // 0x8056A7C4

    // Methods
    void SetupNames(IHRecord *, int);  // 0x8056A97C (488B)
    /* ? */ GetVariable(char *);  // 0x8056AB64 (624B)
    void SetVariable(char *, char *);  // 0x8056ADD4 (768B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_variable;  // 0x000 [R/W] (FONTarget, GetVariable, ~FONTarget)
    u8 _pad_001[3];  // 0x001
    u16 m_variable_004;  // 0x004 [R/W] (FONTarget, GetVariable, SetVariable, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (FONTarget, ~FONTarget)
    u32 m_field_00C;  // 0x00C [R/W] (FONTarget, ~FONTarget)
    u32 m_field_010;  // 0x010 [R/W] (FONTarget, ~FONTarget)
    u32 m_field_014;  // 0x014 [R/W] (FONTarget, ~FONTarget)
    u32 m_field_018;  // 0x018 [R/W] (FONTarget, ~FONTarget)
    u32 m_field_01C;  // 0x01C [R/W] (FONTarget, ~FONTarget)
    u32 m_field_020;  // 0x020 [R/W] (FONTarget, ~FONTarget)
    u32 m_field_024;  // 0x024 [R/W] (FONTarget, ~FONTarget)
    u32 m_field_028;  // 0x028 [W] (FONTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (FONTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (FONTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (FONTarget, ~FONTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (FONTarget, ~FONTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (FONTarget)
    u32 m_field_07C;  // 0x07C [R/W] (FONTarget, ~FONTarget)
    u32 m_field_080;  // 0x080 [W] (FONTarget, ~FONTarget)
    u32 m_field_084;  // 0x084 [W] (FONTarget)
    u32 m_variable_088;  // 0x088 [R/W] (FONTarget, GetVariable, SetVariable)
    u32 m_variable_08C;  // 0x08C [R/W] (FONTarget, GetVariable, SetVariable, ...)
    u8 _pad_090[8];  // 0x090
    u32 m_variable_098;  // 0x098 [R/W] (FONTarget, GetVariable, SetVariable)
    u32 m_upNames;  // 0x09C [R/W] (FONTarget, SetupNames, ~FONTarget)
    u32 m_field_0A0;  // 0x0A0 [R/W] (FONTarget, ~FONTarget)
    u8 _pad_0A4[0x3C];  // 0x0A4
    s16 m_field_0E0;  // 0x0E0 [R] (FONTarget)
    u8 _pad_0E2[2];  // 0x0E2
    u32 m_field_0E4;  // 0x0E4 [R] (FONTarget)
    u8 _pad_0E8[0x5ADC];  // 0x0E8
    u32 m_field_5BC4;  // 0x5BC4 [R] (FONTarget)
};

#endif // FONTARGET_H
