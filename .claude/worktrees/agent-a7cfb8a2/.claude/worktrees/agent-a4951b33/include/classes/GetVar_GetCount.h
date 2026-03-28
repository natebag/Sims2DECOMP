#ifndef GETVAR_GETCOUNT_H
#define GETVAR_GETCOUNT_H

#include "types.h"

// GetVar_GetCount - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 6 methods

class GetVar_GetCount {
public:
    // Constructors / Destructors
    GetVar_GetCount(char *, int)  // 0x805692D8
    ~GetVar_GetCount(void);  // 0x80591D34

    // Methods
    void Handler(char *);  // 0x80569570 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (GetVar_GetCount)
    u32 m_var_GetCount_004;  // 0x004 [W] (GetVar_GetCount)
    u32 m_var_GetCount_008;  // 0x008 [W] (GetVar_GetCount)
};

#endif // GETVAR_GETCOUNT_H
