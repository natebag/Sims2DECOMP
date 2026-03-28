#ifndef APTPROTOTYPE_H
#define APTPROTOTYPE_H

#include "types.h"

// AptPrototype - struct layout extracted from assembly analysis
// Estimated minimum size: 0x24 (36 bytes)
// 3 known fields (2 named), 16 methods

class AptPrototype {
public:
    // Constructors / Destructors
    AptPrototype(void)  // 0x8070BE1C
    ~AptPrototype(void);  // 0x8070C0A4

    // Methods
    void SetSuperConstructor(AptValue *);  // 0x8070BFC8 (220B)
    /* ? */ GetSuperConstructor(void);  // 0x8070BF9C (44B)
    void DestroyGCPointers(void);  // 0x8070B890 (148B)
    void RegisterReferences(void);  // 0x8070B924 (116B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x8070BE84 (136B)
    void objectMemberSet(AptValue *, EAStringC *, AptValue *);  // 0x8070BF0C (144B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AptPrototype)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [W] (AptPrototype, ~AptPrototype)
    u8 _pad_00C[0x14];  // 0x00C
    u32 m_superConstructor;  // 0x020 [R/W] (AptPrototype, DestroyGCPointers, RegisterReferences, ...)
};

#endif // APTPROTOTYPE_H
