#ifndef APTCHARACTER_H
#define APTCHARACTER_H

#include "types.h"

// AptCharacter - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 2 known fields (0 named), 4 methods

class AptCharacter {
public:
    // Methods
    void render(AptRenderingContext *, AptMaskRenderOperation, AptMatrix *);  // 0x806C9C00 (324B)
    void _getBoundingRect(AptRenderingContext *, AptRect *, AptMatrix *);  // 0x806C9D44 (276B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (_getBoundingRect, render)
    u8 _pad_004[0x14];  // 0x004
    u32 m_field_018;  // 0x018 [R] (render)
};

#endif // APTCHARACTER_H
