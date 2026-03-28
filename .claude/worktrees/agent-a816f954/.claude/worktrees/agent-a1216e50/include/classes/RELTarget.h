#ifndef RELTARGET_H
#define RELTARGET_H

#include "types.h"

// RELTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0xA4 (164 bytes)
// 26 known fields (14 named), 22 methods

class RELTarget {
public:
    // Constructors / Destructors
    RELTarget(int)  // 0x80589594
    ~RELTarget(void);  // 0x80589E8C

    // Methods
    void SetupRelationshipInformation(void);  // 0x8058AD88 (836B)
    void SetupPageShaders(int);  // 0x8058B248 (1248B)
    /* ? */ GetVariable(char *);  // 0x8058A090 (796B)
    /* ? */ GetFace(int);  // 0x8058B0CC (44B)
    /* ? */ GetColor(int);  // 0x8058B124 (168B)
    /* ? */ GetCrew(int);  // 0x8058B0F8 (44B)
    /* ? */ GetLocalizable(char *);  // 0x8058A3AC (872B)
    /* ? */ GetRecord(int);  // 0x8058B1CC (124B)
    void SetVariable(char *, char *);  // 0x8058A714 (1652B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (GetLocalizable, GetVariable, RELTarget, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (GetVariable, RELTarget, SetupPageShaders, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_upRelationshipInformation;  // 0x008 [R/W] (RELTarget, SetupPageShaders, SetupRelationshipInformation, ...)
    u16 m_upRelationshipInformation_00C;  // 0x00C [R/W] (RELTarget, SetupPageShaders, SetupRelationshipInformation, ...)
    u8 _pad_00E[2];  // 0x00E
    u32 m_upRelationshipInformation_010;  // 0x010 [R/W] (RELTarget, SetupPageShaders, SetupRelationshipInformation, ...)
    u32 m_field_014;  // 0x014 [R/W] (RELTarget, ~RELTarget)
    u32 m_field_018;  // 0x018 [R/W] (RELTarget, ~RELTarget)
    u32 m_color;  // 0x01C [R/W] (GetColor, RELTarget, SetVariable, ...)
    u32 m_field_020;  // 0x020 [R/W] (RELTarget, ~RELTarget)
    u32 m_field_024;  // 0x024 [R/W] (RELTarget, ~RELTarget)
    u32 m_field_028;  // 0x028 [W] (RELTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (RELTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (RELTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (RELTarget, ~RELTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (RELTarget, ~RELTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (RELTarget)
    u32 m_variable_07C;  // 0x07C [R/W] (RELTarget, SetVariable, SetupPageShaders, ...)
    u32 m_field_080;  // 0x080 [W] (RELTarget, ~RELTarget)
    u32 m_upRelationshipInformation_084;  // 0x084 [R/W] (RELTarget, SetupRelationshipInformation, ~RELTarget)
    u32 m_variable_088;  // 0x088 [R/W] (GetVariable, RELTarget, SetVariable, ...)
    u32 m_variable_08C;  // 0x08C [R/W] (GetLocalizable, GetVariable, RELTarget, ...)
    u32 m_localizable_090;  // 0x090 [R/W] (GetLocalizable, RELTarget, SetVariable)
    u8 _pad_094[4];  // 0x094
    u32 m_variable_098;  // 0x098 [R/W] (RELTarget, SetVariable, ~RELTarget)
    u32 m_upPageShaders;  // 0x09C [R/W] (RELTarget, SetVariable, SetupPageShaders, ...)
    u32 m_field_0A0;  // 0x0A0 [R/W] (RELTarget, ~RELTarget)
};

#endif // RELTARGET_H
