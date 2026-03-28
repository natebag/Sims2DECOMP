#ifndef SETVAR_EYE_FUNFRAMECURRSEL_H
#define SETVAR_EYE_FUNFRAMECURRSEL_H

#include "types.h"

// SetVar_EYE_funframeCurrSel - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 6 methods

class SetVar_EYE_funframeCurrSel {
public:
    // Constructors / Destructors
    SetVar_EYE_funframeCurrSel(char *)  // 0x80593AF4
    ~SetVar_EYE_funframeCurrSel(void);  // 0x80591B34

    // Methods
    void Handler(char *);  // 0x80569C64 (108B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (SetVar_EYE_funframeCurrSel)
    u32 m_var_EYE_funframeCurrSel_004;  // 0x004 [W] (SetVar_EYE_funframeCurrSel)
    u32 m_var_EYE_funframeCurrSel_008;  // 0x008 [W] (SetVar_EYE_funframeCurrSel)
};

#endif // SETVAR_EYE_FUNFRAMECURRSEL_H
