#ifndef APTCHARACTERBUTTONINST_H
#define APTCHARACTERBUTTONINST_H

#include "types.h"

// AptCharacterButtonInst - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 5 known fields (1 named), 6 methods

class AptCharacterButtonInst {
public:
    // Constructors / Destructors
    AptCharacterButtonInst(void)  // 0x8071F084
    ~AptCharacterButtonInst(void);  // 0x8071EF50

    // Methods
    void PreDestroy(void);  // 0x8071EF14 (60B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (AptCharacterButtonInst)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [W] (AptCharacterButtonInst)
    u32 m_field_00C;  // 0x00C [R/W] (AptCharacterButtonInst, ~AptCharacterButtonInst)
    u32 m_field_010;  // 0x010 [W] (AptCharacterButtonInst)
    u32 m_field_014;  // 0x014 [W] (AptCharacterButtonInst, ~AptCharacterButtonInst)
};

#endif // APTCHARACTERBUTTONINST_H
