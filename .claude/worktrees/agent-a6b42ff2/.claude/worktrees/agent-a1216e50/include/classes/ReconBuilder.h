#ifndef RECONBUILDER_H
#define RECONBUILDER_H

#include "types.h"

// ReconBuilder - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (1 named), 14 methods

class ReconBuilder {
public:
    // Methods
    void Reconstitute(ReconObject *, iResFile *, short, int *);  // 0x8039638C (272B)
    void Compact(ReconObject *, int, iResFile *, short);  // 0x803961B0 (476B)
    void Reconstitute(ReconObject *, Memory::HandleNode *, int *);  // 0x8039649C (508B)
    void Compact(ReconObject *, int);  // 0x80395F78 (568B)
    void SwapFourByteNumber(unsigned int *);  // 0x8039675C (148B)
    void Swizzle(void *, int);  // 0x80396698 (104B)
    void SwapTwoByteNumber(unsigned short *);  // 0x80396700 (92B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (Compact)
    u32 m_field_004;  // 0x004 [R/W] (Compact)
    u32 m_field_008;  // 0x008 [R/W] (Compact)
};

#endif // RECONBUILDER_H
