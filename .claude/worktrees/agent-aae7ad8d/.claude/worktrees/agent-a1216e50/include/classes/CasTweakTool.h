#ifndef CASTWEAKTOOL_H
#define CASTWEAKTOOL_H

#include "types.h"

// CasTweakTool - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 6 known fields (6 named), 20 methods

class CasTweakTool {
public:
    // Constructors / Destructors
    CasTweakTool(void)  // 0x80476610
    ~CasTweakTool(void);  // 0x80476680

    // Methods
    /* ? */ GetLights(ELights &);  // 0x80476AB8 (136B)
    void SetCamera(EVec3 &, EVec3 &);  // 0x80476C50 (136B)
    /* ? */ GetCamera(EVec3 &, EVec3 &);  // 0x80476BE0 (112B)
    void SetLights(ELights &);  // 0x80476B40 (160B)
    /* ? */ GetMixinSize(void);  // 0x804766E4 (40B)
    /* ? */ GetMixinInfo(char *);  // 0x8047670C (48B)
    void SetupWindow(CUIWindow *);  // 0x8047673C (892B)
    /* ? */ GetWindowName(void);  // 0x80476EC4 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetLights, SetLights)
    u32 m_lights_004;  // 0x004 [R/W] (GetLights, SetLights)
    u32 m_lights_008;  // 0x008 [R/W] (GetLights, SetLights)
    u32 m_lights_00C;  // 0x00C [R/W] (GetLights, SetLights)
    u32 m_lights_010;  // 0x010 [R/W] (GetLights, SetLights)
    u32 m_lights_014;  // 0x014 [R/W] (GetLights, SetLights)
};

#endif // CASTWEAKTOOL_H
