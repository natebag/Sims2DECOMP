#ifndef GETVAR_LOCKEDSTATUS_H
#define GETVAR_LOCKEDSTATUS_H

#include "types.h"

// GetVar_LockedStatus - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (4 named), 6 methods

class GetVar_LockedStatus {
public:
    // Constructors / Destructors
    GetVar_LockedStatus(char *, unsigned int)  // 0x805693AC
    ~GetVar_LockedStatus(void);  // 0x80591CB4

    // Methods
    void Handler(char *);  // 0x805694D0 (96B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (GetVar_LockedStatus)
    u32 m_var_LockedStatus_004;  // 0x004 [W] (GetVar_LockedStatus)
    u32 m_var_LockedStatus_008;  // 0x008 [W] (GetVar_LockedStatus)
    u32 m_var_LockedStatus_00C;  // 0x00C [R/W] (GetVar_LockedStatus, Handler)
};

#endif // GETVAR_LOCKEDSTATUS_H
