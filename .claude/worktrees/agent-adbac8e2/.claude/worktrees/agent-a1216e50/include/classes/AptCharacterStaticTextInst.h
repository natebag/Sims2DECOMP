#ifndef APTCHARACTERSTATICTEXTINST_H
#define APTCHARACTERSTATICTEXTINST_H

#include "types.h"

// AptCharacterStaticTextInst - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 2 known fields (0 named), 3 methods

class AptCharacterStaticTextInst {
public:
    // Constructors / Destructors
    AptCharacterStaticTextInst(void)  // 0x806E40B4
    ~AptCharacterStaticTextInst(void);  // 0x806E492C

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0xC];  // 0x000
    u32 m_field_00C;  // 0x00C [R] (~AptCharacterStaticTextInst)
    u8 _pad_010[4];  // 0x010
    u32 m_field_014;  // 0x014 [W] (~AptCharacterStaticTextInst)
};

#endif // APTCHARACTERSTATICTEXTINST_H
