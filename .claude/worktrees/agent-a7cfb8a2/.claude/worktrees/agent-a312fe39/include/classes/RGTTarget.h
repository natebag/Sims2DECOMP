#ifndef RGTTARGET_H
#define RGTTARGET_H

#include "types.h"

// RGTTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x94 (148 bytes)
// 23 known fields (6 named), 14 methods

class RGTTarget {
public:
    // Constructors / Destructors
    RGTTarget(int)  // 0x8058B728
    ~RGTTarget(void);  // 0x8058BCEC

    // Methods
    void SetupRingtoneUnlocks(void);  // 0x8058C588 (204B)
    void SetupNames(int);  // 0x8058BE6C (420B)
    void FindActualRingtoneIndex(int);  // 0x8058C4B8 (208B)
    /* ? */ GetVariable(char *);  // 0x8058C010 (372B)
    void SetVariable(char *, char *);  // 0x8058C184 (820B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_variable;  // 0x000 [R/W] (GetVariable, RGTTarget, SetVariable, ...)
    u8 _pad_001[3];  // 0x001
    u16 m_variable_004;  // 0x004 [R/W] (GetVariable, RGTTarget, ~RGTTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (RGTTarget, ~RGTTarget)
    u32 m_field_00C;  // 0x00C [R/W] (RGTTarget, ~RGTTarget)
    u32 m_field_010;  // 0x010 [R/W] (RGTTarget, ~RGTTarget)
    u32 m_field_014;  // 0x014 [R/W] (RGTTarget, ~RGTTarget)
    u32 m_field_018;  // 0x018 [R/W] (RGTTarget, ~RGTTarget)
    u32 m_field_01C;  // 0x01C [R/W] (RGTTarget, ~RGTTarget)
    u32 m_field_020;  // 0x020 [R/W] (RGTTarget, ~RGTTarget)
    u32 m_field_024;  // 0x024 [R/W] (RGTTarget, ~RGTTarget)
    u32 m_field_028;  // 0x028 [W] (RGTTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (RGTTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (RGTTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (RGTTarget, ~RGTTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (RGTTarget, ~RGTTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (RGTTarget)
    u32 m_field_07C;  // 0x07C [R/W] (RGTTarget, ~RGTTarget)
    u32 m_field_080;  // 0x080 [W] (RGTTarget, ~RGTTarget)
    u32 m_variable_084;  // 0x084 [R/W] (GetVariable, RGTTarget, SetupRingtoneUnlocks)
    u32 m_variable_088;  // 0x088 [R/W] (RGTTarget, SetVariable)
    u32 m_variable_08C;  // 0x08C [R/W] (FindActualRingtoneIndex, RGTTarget, SetVariable, ...)
    u32 m_field_090;  // 0x090 [R/W] (RGTTarget, ~RGTTarget)
};

#endif // RGTTARGET_H
