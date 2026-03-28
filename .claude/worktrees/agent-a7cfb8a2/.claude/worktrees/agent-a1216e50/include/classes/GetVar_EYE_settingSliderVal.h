#ifndef GETVAR_EYE_SETTINGSLIDERVAL_H
#define GETVAR_EYE_SETTINGSLIDERVAL_H

#include "types.h"

// GetVar_EYE_settingSliderVal - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (4 named), 6 methods

class GetVar_EYE_settingSliderVal {
public:
    // Constructors / Destructors
    GetVar_EYE_settingSliderVal(char *, float (*)  // 0x80593E8C
    ~GetVar_EYE_settingSliderVal(void);  // 0x80591DF4

    // Methods
    void Handler(char *);  // 0x805695B4 (96B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (GetVar_EYE_settingSliderVal)
    u32 m_var_EYE_settingSliderVal_004;  // 0x004 [W] (GetVar_EYE_settingSliderVal)
    u32 m_var_EYE_settingSliderVal_008;  // 0x008 [W] (GetVar_EYE_settingSliderVal)
    u32 m_var_EYE_settingSliderVal_00C;  // 0x00C [R/W] (GetVar_EYE_settingSliderVal, Handler)
};

#endif // GETVAR_EYE_SETTINGSLIDERVAL_H
