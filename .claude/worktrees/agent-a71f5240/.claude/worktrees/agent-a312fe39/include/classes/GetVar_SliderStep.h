#ifndef GETVAR_SLIDERSTEP_H
#define GETVAR_SLIDERSTEP_H

#include "types.h"

// GetVar_SliderStep - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (4 named), 6 methods

class GetVar_SliderStep {
public:
    // Constructors / Destructors
    GetVar_SliderStep(char *, char *)  // 0x80593D88
    ~GetVar_SliderStep(void);  // 0x80591CF4

    // Methods
    void Handler(char *);  // 0x80569530 (64B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (GetVar_SliderStep)
    u32 m_var_SliderStep_004;  // 0x004 [W] (GetVar_SliderStep)
    u32 m_var_SliderStep_008;  // 0x008 [W] (GetVar_SliderStep)
    u32 m_var_SliderStep_00C;  // 0x00C [W] (GetVar_SliderStep)
};

#endif // GETVAR_SLIDERSTEP_H
