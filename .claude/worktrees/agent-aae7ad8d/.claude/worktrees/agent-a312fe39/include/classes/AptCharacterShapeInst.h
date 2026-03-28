#ifndef APTCHARACTERSHAPEINST_H
#define APTCHARACTERSHAPEINST_H

#include "types.h"

// AptCharacterShapeInst - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 2 known fields (0 named), 3 methods

class AptCharacterShapeInst {
public:
    // Constructors / Destructors
    AptCharacterShapeInst(void)  // 0x806E4018
    ~AptCharacterShapeInst(void);  // 0x806E48D4

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0xC];  // 0x000
    u32 m_field_00C;  // 0x00C [R] (~AptCharacterShapeInst)
    u8 _pad_010[4];  // 0x010
    u32 m_field_014;  // 0x014 [W] (~AptCharacterShapeInst)
};

#endif // APTCHARACTERSHAPEINST_H
