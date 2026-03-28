#ifndef GETVAR_SAVEREQUIRED_H
#define GETVAR_SAVEREQUIRED_H

#include "types.h"

// GetVar_SaveRequired - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 6 methods

class GetVar_SaveRequired {
public:
    // Constructors / Destructors
    GetVar_SaveRequired(char *)  // 0x80593EE8
    ~GetVar_SaveRequired(void);  // 0x80591E34

    // Methods
    void Handler(char *);  // 0x80569614 (160B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (GetVar_SaveRequired)
    u32 m_var_SaveRequired_004;  // 0x004 [W] (GetVar_SaveRequired)
    u32 m_var_SaveRequired_008;  // 0x008 [W] (GetVar_SaveRequired)
};

#endif // GETVAR_SAVEREQUIRED_H
