#ifndef GETVAR_SAVESTATUS_H
#define GETVAR_SAVESTATUS_H

#include "types.h"

// GetVar_SaveStatus - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 6 methods

class GetVar_SaveStatus {
public:
    // Constructors / Destructors
    GetVar_SaveStatus(char *)  // 0x80593F3C
    ~GetVar_SaveStatus(void);  // 0x80591E74

    // Methods
    void Handler(char *);  // 0x805698D0 (136B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (GetVar_SaveStatus)
    u32 m_var_SaveStatus_004;  // 0x004 [W] (GetVar_SaveStatus)
    u32 m_var_SaveStatus_008;  // 0x008 [W] (GetVar_SaveStatus)
};

#endif // GETVAR_SAVESTATUS_H
