#ifndef CXPERSON_H
#define CXPERSON_H

#include "types.h"

// cXPerson - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 3 known fields (1 named), 10 methods

class cXPerson {
public:
    // Constructors / Destructors
    cXPerson(int)  // 0x803782E0
    ~cXPerson(void);  // 0x803558C8

    // Methods
    void CAST_IMPL(void);  // 0x80378498 (120B)
    void setPersonImpl(cXPersonImpl *);  // 0x80378430 (64B)
    void CastToPerson(void);  // 0x80378470 (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (cXPerson, ~cXPerson)
    u32 m_field_004;  // 0x004 [W] (cXPerson, ~cXPerson)
    u8 _pad_008[0x1C];  // 0x008
    u32 m_field_024;  // 0x024 [W] (cXPerson)
};

#endif // CXPERSON_H
