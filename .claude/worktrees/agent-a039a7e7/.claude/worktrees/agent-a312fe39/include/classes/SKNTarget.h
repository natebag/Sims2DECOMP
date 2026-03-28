#ifndef SKNTARGET_H
#define SKNTARGET_H

#include "types.h"

// SKNTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x98 (152 bytes)
// 24 known fields (9 named), 14 methods

class SKNTarget {
public:
    // Constructors / Destructors
    SKNTarget(int)  // 0x8058C654
    ~SKNTarget(void);  // 0x8058CC00

    // Methods
    void SetupSkinUnlocks(void);  // 0x8058DA78 (204B)
    void SetupPageShaders(int);  // 0x8058D324 (1876B)
    /* ? */ GetVariable(char *);  // 0x8058CD80 (372B)
    void SetVariable(char *, char *);  // 0x8058CEF4 (852B)
    void FindActualSkinIndex(int);  // 0x8058D248 (220B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_variable;  // 0x000 [R/W] (FindActualSkinIndex, GetVariable, SKNTarget, ...)
    u8 _pad_001[3];  // 0x001
    u16 m_variable_004;  // 0x004 [R/W] (GetVariable, SKNTarget, ~SKNTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (SKNTarget, ~SKNTarget)
    u32 m_field_00C;  // 0x00C [R/W] (SKNTarget, ~SKNTarget)
    u32 m_field_010;  // 0x010 [R/W] (SKNTarget, ~SKNTarget)
    u32 m_field_014;  // 0x014 [R/W] (SKNTarget, ~SKNTarget)
    u32 m_field_018;  // 0x018 [R/W] (SKNTarget, ~SKNTarget)
    u32 m_upPageShaders;  // 0x01C [R/W] (SKNTarget, SetupPageShaders, ~SKNTarget)
    u32 m_field_020;  // 0x020 [R/W] (SKNTarget, ~SKNTarget)
    u32 m_field_024;  // 0x024 [R/W] (SKNTarget, ~SKNTarget)
    u32 m_field_028;  // 0x028 [W] (SKNTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (SKNTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (SKNTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (SKNTarget, ~SKNTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (SKNTarget, ~SKNTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (SKNTarget)
    u32 m_upPageShaders_07C;  // 0x07C [R/W] (SKNTarget, SetupPageShaders, ~SKNTarget)
    u32 m_field_080;  // 0x080 [W] (SKNTarget, ~SKNTarget)
    u32 m_variable_084;  // 0x084 [R/W] (SKNTarget, SetVariable)
    u32 m_variable_088;  // 0x088 [W] (SKNTarget, SetVariable)
    u32 m_variable_08C;  // 0x08C [R/W] (GetVariable, SKNTarget, SetupSkinUnlocks)
    u32 m_upSkinUnlocks;  // 0x090 [R/W] (FindActualSkinIndex, SKNTarget, SetVariable, ...)
    u32 m_field_094;  // 0x094 [R/W] (SKNTarget, ~SKNTarget)
};

#endif // SKNTARGET_H
