#ifndef GETVAR_EYE_TARGETSTATE_H
#define GETVAR_EYE_TARGETSTATE_H

#include "types.h"

// GetVar_EYE_targetState - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 6 methods

class GetVar_EYE_targetState {
public:
    // Constructors / Destructors
    GetVar_EYE_targetState(char *)  // 0x80593E38
    ~GetVar_EYE_targetState(void);  // 0x80591DB4

    // Methods
    void Handler(char *);  // 0x80569848 (136B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (GetVar_EYE_targetState)
    u32 m_var_EYE_targetState_004;  // 0x004 [W] (GetVar_EYE_targetState)
    u32 m_var_EYE_targetState_008;  // 0x008 [W] (GetVar_EYE_targetState)
};

#endif // GETVAR_EYE_TARGETSTATE_H
