#ifndef SETVAR_EYE_FILTERCURRSEL_H
#define SETVAR_EYE_FILTERCURRSEL_H

#include "types.h"

// SetVar_EYE_filterCurrSel - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 6 methods

class SetVar_EYE_filterCurrSel {
public:
    // Constructors / Destructors
    SetVar_EYE_filterCurrSel(char *)  // 0x80593B48
    ~SetVar_EYE_filterCurrSel(void);  // 0x80591B74

    // Methods
    void Handler(char *);  // 0x80569CD0 (108B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (SetVar_EYE_filterCurrSel)
    u32 m_var_EYE_filterCurrSel_004;  // 0x004 [W] (SetVar_EYE_filterCurrSel)
    u32 m_var_EYE_filterCurrSel_008;  // 0x008 [W] (SetVar_EYE_filterCurrSel)
};

#endif // SETVAR_EYE_FILTERCURRSEL_H
