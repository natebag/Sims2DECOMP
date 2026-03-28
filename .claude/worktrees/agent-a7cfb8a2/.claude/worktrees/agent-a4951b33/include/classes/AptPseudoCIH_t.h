#ifndef APTPSEUDOCIH_T_H
#define APTPSEUDOCIH_T_H

#include "types.h"

// AptPseudoCIH_t - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 5 known fields (1 named), 3 methods

class AptPseudoCIH_t {
public:
    // Constructors / Destructors
    AptPseudoCIH_t(AptControl *, int, int, AptCharacter *)  // 0x806DF1A4
    ~AptPseudoCIH_t(void);  // 0x806D9AEC

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (AptPseudoCIH_t)
    u32 m_field_004;  // 0x004 [W] (AptPseudoCIH_t)
    u32 m_field_008;  // 0x008 [W] (AptPseudoCIH_t)
    u32 m_field_00C;  // 0x00C [W] (AptPseudoCIH_t)
    u32 m_field_010;  // 0x010 [W] (AptPseudoCIH_t)
};

#endif // APTPSEUDOCIH_T_H
