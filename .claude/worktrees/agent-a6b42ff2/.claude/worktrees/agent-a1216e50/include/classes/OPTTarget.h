#ifndef OPTTARGET_H
#define OPTTARGET_H

#include "types.h"

// OPTTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x9C (156 bytes)
// 28 known fields (3 named), 22 methods

class OPTTarget {
public:
    // Constructors / Destructors
    OPTTarget(void)  // 0x80582E2C
    ~OPTTarget(void);  // 0x8058328C

    // Methods
    void RememberOptions(void);  // 0x805845B4 (212B)
    void SetVariable(char *, char *);  // 0x805832E0 (2388B)
    /* ? */ GetScreenXGlobal(float);  // 0x8058433C (200B)
    /* ? */ GetScreenYGlobal(float);  // 0x805844EC (200B)
    void RestoreOptions(void);  // 0x80584688 (296B)
    /* ? */ GetVariable(char *);  // 0x80583C34 (1536B)
    /* ? */ GetScreenXLocal(signed char);  // 0x80584254 (232B)
    /* ? */ GetScreenYLocal(signed char);  // 0x80584404 (232B)
    void Update(void);  // 0x80584234 (32B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_variable;  // 0x000 [R/W] (GetVariable, OPTTarget, ~OPTTarget)
    u8 _pad_001[3];  // 0x001
    u16 m_variable_004;  // 0x004 [R/W] (GetVariable, OPTTarget, ~OPTTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (OPTTarget, ~OPTTarget)
    u32 m_field_00C;  // 0x00C [R/W] (OPTTarget, ~OPTTarget)
    u32 m_field_010;  // 0x010 [R/W] (OPTTarget, ~OPTTarget)
    u32 m_field_014;  // 0x014 [R/W] (OPTTarget, ~OPTTarget)
    u32 m_field_018;  // 0x018 [R/W] (OPTTarget, ~OPTTarget)
    u32 m_field_01C;  // 0x01C [R/W] (OPTTarget, ~OPTTarget)
    u32 m_field_020;  // 0x020 [R/W] (OPTTarget, ~OPTTarget)
    u32 m_field_024;  // 0x024 [R/W] (OPTTarget, ~OPTTarget)
    u32 m_field_028;  // 0x028 [W] (OPTTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (OPTTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (OPTTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (OPTTarget, ~OPTTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (OPTTarget, ~OPTTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (OPTTarget)
    u32 m_field_07C;  // 0x07C [R/W] (OPTTarget, ~OPTTarget)
    u32 m_field_080;  // 0x080 [W] (OPTTarget, ~OPTTarget)
    u8 m_field_084;  // 0x084 [R/W] (RememberOptions, RestoreOptions)
    u8 m_field_085;  // 0x085 [R/W] (RememberOptions, RestoreOptions)
    u8 m_field_086;  // 0x086 [R/W] (RememberOptions, RestoreOptions)
    u8 m_field_087;  // 0x087 [R/W] (RememberOptions, RestoreOptions)
    u32 m_field_088;  // 0x088 [R/W] (RememberOptions, RestoreOptions)
    u32 m_field_08C;  // 0x08C [R/W] (RememberOptions, RestoreOptions)
    u32 m_field_090;  // 0x090 [R/W] (RememberOptions, RestoreOptions)
    u32 m_field_094;  // 0x094 [R/W] (RememberOptions, RestoreOptions)
    u32 m_field_098;  // 0x098 [R/W] (RememberOptions, RestoreOptions)
};

#endif // OPTTARGET_H
