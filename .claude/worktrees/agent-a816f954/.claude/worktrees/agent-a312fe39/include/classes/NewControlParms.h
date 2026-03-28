#ifndef NEWCONTROLPARMS_H
#define NEWCONTROLPARMS_H

#include "types.h"

// NewControlParms - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC4 (196 bytes)
// 49 known fields (1 named), 10 methods

class NewControlParms {
public:
    // Constructors / Destructors
    NewControlParms(void)  // 0x80046BDC
    ~NewControlParms(void);  // 0x8004CAA0

    // Methods
    void Validate(void);  // 0x80046E34 (32B)
    /* ? */ GetWindowName(void);  // 0x80046E54 (44B)
    void SetupWindow(CUIWindow *);  // 0x80046E80 (1836B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (NewControlParms)
    f32 m_field_004;  // 0x004 [W] (NewControlParms)
    f32 m_field_008;  // 0x008 [W] (NewControlParms)
    f32 m_field_00C;  // 0x00C [W] (NewControlParms)
    f32 m_field_010;  // 0x010 [W] (NewControlParms)
    f32 m_field_014;  // 0x014 [W] (NewControlParms)
    f32 m_field_018;  // 0x018 [W] (NewControlParms)
    f32 m_field_01C;  // 0x01C [W] (NewControlParms)
    f32 m_field_020;  // 0x020 [W] (NewControlParms)
    f32 m_field_024;  // 0x024 [W] (NewControlParms)
    u32 m_field_028;  // 0x028 [W] (NewControlParms)
    u32 m_field_02C;  // 0x02C [W] (NewControlParms)
    u32 m_field_030;  // 0x030 [W] (NewControlParms)
    f32 m_field_034;  // 0x034 [W] (NewControlParms)
    f32 m_field_038;  // 0x038 [W] (NewControlParms)
    f32 m_field_03C;  // 0x03C [W] (NewControlParms)
    u32 m_field_040;  // 0x040 [W] (NewControlParms)
    f32 m_field_044;  // 0x044 [W] (NewControlParms)
    f32 m_field_048;  // 0x048 [W] (NewControlParms)
    f32 m_field_04C;  // 0x04C [W] (NewControlParms)
    u32 m_field_050;  // 0x050 [W] (NewControlParms)
    f32 m_field_054;  // 0x054 [W] (NewControlParms)
    u32 m_field_058;  // 0x058 [W] (NewControlParms)
    u32 m_field_05C;  // 0x05C [W] (NewControlParms)
    f32 m_field_060;  // 0x060 [W] (NewControlParms)
    f32 m_field_064;  // 0x064 [W] (NewControlParms)
    u32 m_field_068;  // 0x068 [W] (NewControlParms)
    f32 m_field_06C;  // 0x06C [W] (NewControlParms)
    f32 m_field_070;  // 0x070 [W] (NewControlParms)
    f32 m_field_074;  // 0x074 [W] (NewControlParms)
    u32 m_field_078;  // 0x078 [W] (NewControlParms)
    f32 m_field_07C;  // 0x07C [W] (NewControlParms)
    f32 m_field_080;  // 0x080 [W] (NewControlParms)
    f32 m_field_084;  // 0x084 [W] (NewControlParms)
    f32 m_field_088;  // 0x088 [W] (NewControlParms)
    f32 m_field_08C;  // 0x08C [W] (NewControlParms)
    f32 m_field_090;  // 0x090 [W] (NewControlParms)
    f32 m_field_094;  // 0x094 [W] (NewControlParms)
    f32 m_field_098;  // 0x098 [W] (NewControlParms)
    f32 m_field_09C;  // 0x09C [W] (NewControlParms)
    u32 m_field_0A0;  // 0x0A0 [W] (NewControlParms)
    u32 m_field_0A4;  // 0x0A4 [W] (NewControlParms)
    f32 m_field_0A8;  // 0x0A8 [W] (NewControlParms)
    f32 m_field_0AC;  // 0x0AC [W] (NewControlParms)
    f32 m_field_0B0;  // 0x0B0 [W] (NewControlParms)
    f32 m_field_0B4;  // 0x0B4 [W] (NewControlParms)
    f32 m_field_0B8;  // 0x0B8 [W] (NewControlParms)
    f32 m_field_0BC;  // 0x0BC [W] (NewControlParms)
    u32 m_field_0C0;  // 0x0C0 [W] (NewControlParms)
};

#endif // NEWCONTROLPARMS_H
