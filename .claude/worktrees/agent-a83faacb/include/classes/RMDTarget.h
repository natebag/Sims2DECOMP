#ifndef RMDTARGET_H
#define RMDTARGET_H

#include "types.h"

// RMDTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x54A8 (21672 bytes)
// 30 known fields (8 named), 20 methods

class RMDTarget {
public:
    // Constructors / Destructors
    RMDTarget(int, int)  // 0x8053ABDC
    ~RMDTarget(void);  // 0x8053B280

    // Methods
    void SetupWidgets(void);  // 0x8053BB00 (1380B)
    void StartShowTween(void);  // 0x8053C18C (240B)
    void SetVariable(char *, char *);  // 0x8053B3C8 (624B)
    void StartHideTween(void);  // 0x8053C27C (196B)
    void UnloadDialog(void);  // 0x8053C064 (296B)
    /* ? */ GetVariable(char *);  // 0x8053B638 (340B)
    /* ? */ GetLocalizable(char *);  // 0x8053B78C (720B)
    void Update(void);  // 0x8053BA5C (164B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (GetLocalizable, GetVariable, RMDTarget, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (GetVariable, RMDTarget, UnloadDialog, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (RMDTarget, UnloadDialog, ~RMDTarget)
    u32 m_upWidgets;  // 0x00C [R/W] (RMDTarget, SetupWidgets, UnloadDialog, ...)
    u32 m_field_010;  // 0x010 [R/W] (RMDTarget, UnloadDialog, ~RMDTarget)
    u32 m_field_014;  // 0x014 [R/W] (RMDTarget, UnloadDialog, ~RMDTarget)
    u32 m_field_018;  // 0x018 [R/W] (RMDTarget, UnloadDialog, ~RMDTarget)
    u32 m_field_01C;  // 0x01C [R/W] (RMDTarget, UnloadDialog, ~RMDTarget)
    u32 m_field_020;  // 0x020 [R/W] (RMDTarget, UnloadDialog, ~RMDTarget)
    u32 m_field_024;  // 0x024 [R/W] (RMDTarget, UnloadDialog, ~RMDTarget)
    u32 m_field_028;  // 0x028 [W] (RMDTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (RMDTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (RMDTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (RMDTarget, UnloadDialog, ~RMDTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (RMDTarget, UnloadDialog, ~RMDTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (RMDTarget)
    u32 m_field_07C;  // 0x07C [R/W] (RMDTarget, UnloadDialog, ~RMDTarget)
    u32 m_field_080;  // 0x080 [W] (RMDTarget, ~RMDTarget)
    u32 m_variable_084;  // 0x084 [R/W] (GetVariable, RMDTarget, UnloadDialog, ...)
    u32 m_variable_088;  // 0x088 [R/W] (RMDTarget, SetVariable, StartHideTween, ...)
    u32 m_field_08C;  // 0x08C [W] (RMDTarget)
    u32 m_field_090;  // 0x090 [W] (RMDTarget)
    u32 m_field_094;  // 0x094 [R/W] (RMDTarget, UnloadDialog, ~RMDTarget)
    u32 m_field_098;  // 0x098 [W] (RMDTarget)
    u32 m_field_09C;  // 0x09C [W] (RMDTarget)
    u8 _pad_0A0[8];  // 0x0A0
    f32 m_field_0A8;  // 0x0A8 [R/W] (RMDTarget, Update)
    u32 m_field_0AC;  // 0x0AC [R/W] (RMDTarget, Update)
    u8 _pad_0B0[0x53E0];  // 0x0B0
    f32 m_upWidgets_5490;  // 0x5490 [R] (SetupWidgets)
    u8 _pad_5494[0x10];  // 0x5494
    f32 m_upWidgets_54A4;  // 0x54A4 [R] (SetupWidgets)
};

#endif // RMDTARGET_H
