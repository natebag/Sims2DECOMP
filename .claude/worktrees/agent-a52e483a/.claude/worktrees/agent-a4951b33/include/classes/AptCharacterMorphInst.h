#ifndef APTCHARACTERMORPHINST_H
#define APTCHARACTERMORPHINST_H

#include "types.h"

// AptCharacterMorphInst - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 2 known fields (0 named), 3 methods

class AptCharacterMorphInst {
public:
    // Constructors / Destructors
    AptCharacterMorphInst(void)  // 0x806E4150
    ~AptCharacterMorphInst(void);  // 0x806E4984

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0xC];  // 0x000
    u32 m_field_00C;  // 0x00C [R] (~AptCharacterMorphInst)
    u8 _pad_010[4];  // 0x010
    u32 m_field_014;  // 0x014 [W] (~AptCharacterMorphInst)
};

#endif // APTCHARACTERMORPHINST_H
