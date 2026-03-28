#ifndef GETVAR_LEGACY_H
#define GETVAR_LEGACY_H

#include "types.h"

// GetVar_Legacy - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 6 methods

class GetVar_Legacy {
public:
    // Constructors / Destructors
    GetVar_Legacy(char *)  // 0x80594038
    ~GetVar_Legacy(void);  // 0x80591F34

    // Methods
    void Handler(char *);  // 0x805697C0 (136B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (GetVar_Legacy)
    u32 m_var_Legacy_004;  // 0x004 [W] (GetVar_Legacy)
    u32 m_var_Legacy_008;  // 0x008 [W] (GetVar_Legacy)
};

#endif // GETVAR_LEGACY_H
