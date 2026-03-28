#ifndef APTGLOBAL_H
#define APTGLOBAL_H

#include "types.h"

// AptGlobal - struct layout extracted from assembly analysis
// Estimated minimum size: 0x21 (33 bytes)
// 3 known fields (0 named), 12 methods

class AptGlobal {
public:
    // Constructors / Destructors
    AptGlobal(void)  // 0x8070B780
    ~AptGlobal(void);  // 0x8070B7E0

    // Methods
    void Lookup(EAStringC *);  // 0x8070B56C (80B)
    void Set(EAStringC *, AptValue *);  // 0x8070B520 (76B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x8070B5BC (224B)
    void objectMemberSet(AptValue *, EAStringC *, AptValue *);  // 0x8070B69C (188B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (objectMemberLookup)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [W] (AptGlobal, ~AptGlobal)
    u8 _pad_00C[0x14];  // 0x00C
    u8 m_field_020;  // 0x020 [R/W] (AptGlobal)
};

#endif // APTGLOBAL_H
