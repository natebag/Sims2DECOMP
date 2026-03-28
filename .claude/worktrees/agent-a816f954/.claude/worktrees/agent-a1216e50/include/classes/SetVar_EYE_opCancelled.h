#ifndef SETVAR_EYE_OPCANCELLED_H
#define SETVAR_EYE_OPCANCELLED_H

#include "types.h"

// SetVar_EYE_opCancelled - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 6 methods

class SetVar_EYE_opCancelled {
public:
    // Constructors / Destructors
    SetVar_EYE_opCancelled(char *)  // 0x80593CA0
    ~SetVar_EYE_opCancelled(void);  // 0x80591C74

    // Methods
    void Handler(char *);  // 0x80569DF0 (72B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (SetVar_EYE_opCancelled)
    u32 m_var_EYE_opCancelled_004;  // 0x004 [W] (SetVar_EYE_opCancelled)
    u32 m_var_EYE_opCancelled_008;  // 0x008 [W] (SetVar_EYE_opCancelled)
};

#endif // SETVAR_EYE_OPCANCELLED_H
