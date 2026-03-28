#ifndef SETVAR_EYE_SETTINGSLIDERVAL_H
#define SETVAR_EYE_SETTINGSLIDERVAL_H

#include "types.h"

// SetVar_EYE_settingSliderVal - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (4 named), 6 methods

class SetVar_EYE_settingSliderVal {
public:
    // Constructors / Destructors
    SetVar_EYE_settingSliderVal(char *, void (*)  // 0x80593C44
    ~SetVar_EYE_settingSliderVal(void);  // 0x80591C34

    // Methods
    void Handler(char *);  // 0x80569D90 (96B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (SetVar_EYE_settingSliderVal)
    u32 m_var_EYE_settingSliderVal_004;  // 0x004 [W] (SetVar_EYE_settingSliderVal)
    u32 m_var_EYE_settingSliderVal_008;  // 0x008 [W] (SetVar_EYE_settingSliderVal)
    u32 m_var_EYE_settingSliderVal_00C;  // 0x00C [W] (SetVar_EYE_settingSliderVal)
};

#endif // SETVAR_EYE_SETTINGSLIDERVAL_H
