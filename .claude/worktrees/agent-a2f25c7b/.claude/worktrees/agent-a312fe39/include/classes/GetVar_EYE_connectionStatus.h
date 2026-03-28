#ifndef GETVAR_EYE_CONNECTIONSTATUS_H
#define GETVAR_EYE_CONNECTIONSTATUS_H

#include "types.h"

// GetVar_EYE_connectionStatus - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 6 methods

class GetVar_EYE_connectionStatus {
public:
    // Constructors / Destructors
    GetVar_EYE_connectionStatus(char *)  // 0x80593FE4
    ~GetVar_EYE_connectionStatus(void);  // 0x80591EF4

    // Methods
    void Handler(char *);  // 0x80569728 (152B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (GetVar_EYE_connectionStatus)
    u32 m_var_EYE_connectionStatus_004;  // 0x004 [W] (GetVar_EYE_connectionStatus)
    u32 m_var_EYE_connectionStatus_008;  // 0x008 [W] (GetVar_EYE_connectionStatus)
};

#endif // GETVAR_EYE_CONNECTIONSTATUS_H
