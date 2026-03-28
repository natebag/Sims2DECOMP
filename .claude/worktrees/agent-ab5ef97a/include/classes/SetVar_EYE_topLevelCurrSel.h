#ifndef SETVAR_EYE_TOPLEVELCURRSEL_H
#define SETVAR_EYE_TOPLEVELCURRSEL_H

#include "types.h"

// SetVar_EYE_topLevelCurrSel - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 6 methods

class SetVar_EYE_topLevelCurrSel {
public:
    // Constructors / Destructors
    SetVar_EYE_topLevelCurrSel(char *)  // 0x80593AA0
    ~SetVar_EYE_topLevelCurrSel(void);  // 0x80591AF4

    // Methods
    void Handler(char *);  // 0x80569B6C (248B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (SetVar_EYE_topLevelCurrSel)
    u32 m_var_EYE_topLevelCurrSel_004;  // 0x004 [W] (SetVar_EYE_topLevelCurrSel)
    u32 m_var_EYE_topLevelCurrSel_008;  // 0x008 [W] (SetVar_EYE_topLevelCurrSel)
};

#endif // SETVAR_EYE_TOPLEVELCURRSEL_H
