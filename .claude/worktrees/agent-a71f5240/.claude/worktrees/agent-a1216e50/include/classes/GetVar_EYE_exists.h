#ifndef GETVAR_EYE_EXISTS_H
#define GETVAR_EYE_EXISTS_H

#include "types.h"

// GetVar_EYE_exists - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 6 methods

class GetVar_EYE_exists {
public:
    // Constructors / Destructors
    GetVar_EYE_exists(char *)  // 0x80593DE4
    ~GetVar_EYE_exists(void);  // 0x80591D74

    // Methods
    void Handler(char *);  // 0x8056948C (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (GetVar_EYE_exists)
    u32 m_var_EYE_exists_004;  // 0x004 [W] (GetVar_EYE_exists)
    u32 m_var_EYE_exists_008;  // 0x008 [W] (GetVar_EYE_exists)
};

#endif // GETVAR_EYE_EXISTS_H
