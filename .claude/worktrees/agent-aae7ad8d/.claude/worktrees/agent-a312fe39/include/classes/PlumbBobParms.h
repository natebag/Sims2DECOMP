#ifndef PLUMBBOBPARMS_H
#define PLUMBBOBPARMS_H

#include "types.h"

// PlumbBobParms - struct layout extracted from assembly analysis
// Estimated minimum size: 0x4264 (16996 bytes)
// 23 known fields (1 named), 12 methods

class PlumbBobParms {
public:
    // Constructors / Destructors
    PlumbBobParms(void)  // 0x8011EC98
    ~PlumbBobParms(void);  // 0x80122A90

    // Methods
    void Calculate(void);  // 0x8011EEB8 (52B)
    void Validate(void);  // 0x8011EE80 (56B)
    /* ? */ GetWindowName(void);  // 0x8011EEEC (44B)
    void SetupWindow(CUIWindow *);  // 0x8011EF18 (704B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (PlumbBobParms)
    u32 m_field_004;  // 0x004 [W] (PlumbBobParms)
    u32 m_field_008;  // 0x008 [W] (PlumbBobParms)
    u32 m_field_00C;  // 0x00C [W] (PlumbBobParms)
    u8 _pad_010[8];  // 0x010
    f32 m_field_018;  // 0x018 [W] (PlumbBobParms)
    f32 m_field_01C;  // 0x01C [W] (PlumbBobParms)
    f32 m_field_020;  // 0x020 [W] (PlumbBobParms)
    f32 m_field_024;  // 0x024 [W] (PlumbBobParms)
    f32 m_field_028;  // 0x028 [W] (PlumbBobParms)
    f32 m_field_02C;  // 0x02C [W] (PlumbBobParms)
    f32 m_field_030;  // 0x030 [W] (PlumbBobParms)
    f32 m_field_034;  // 0x034 [W] (PlumbBobParms)
    f32 m_field_038;  // 0x038 [W] (PlumbBobParms)
    f32 m_field_03C;  // 0x03C [W] (PlumbBobParms)
    f32 m_field_040;  // 0x040 [W] (PlumbBobParms)
    f32 m_field_044;  // 0x044 [W] (PlumbBobParms)
    f32 m_field_048;  // 0x048 [W] (PlumbBobParms)
    f32 m_field_04C;  // 0x04C [W] (PlumbBobParms)
    f32 m_field_050;  // 0x050 [W] (PlumbBobParms)
    f32 m_field_054;  // 0x054 [W] (PlumbBobParms)
    u32 m_field_058;  // 0x058 [W] (PlumbBobParms)
    u8 _pad_05C[4];  // 0x05C
    u32 m_field_060;  // 0x060 [W] (PlumbBobParms)
    u8 _pad_064[0x41FC];  // 0x064
    f32 m_field_4260;  // 0x4260 [R] (PlumbBobParms)
};

#endif // PLUMBBOBPARMS_H
