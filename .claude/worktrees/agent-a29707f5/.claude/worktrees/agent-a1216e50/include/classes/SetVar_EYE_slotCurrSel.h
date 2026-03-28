#ifndef SETVAR_EYE_SLOTCURRSEL_H
#define SETVAR_EYE_SLOTCURRSEL_H

#include "types.h"

// SetVar_EYE_slotCurrSel - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 6 methods

class SetVar_EYE_slotCurrSel {
public:
    // Constructors / Destructors
    SetVar_EYE_slotCurrSel(char *)  // 0x80593B9C
    ~SetVar_EYE_slotCurrSel(void);  // 0x80591BB4

    // Methods
    void Handler(char *);  // 0x80569D3C (84B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (SetVar_EYE_slotCurrSel)
    u32 m_var_EYE_slotCurrSel_004;  // 0x004 [W] (SetVar_EYE_slotCurrSel)
    u32 m_var_EYE_slotCurrSel_008;  // 0x008 [W] (SetVar_EYE_slotCurrSel)
};

#endif // SETVAR_EYE_SLOTCURRSEL_H
