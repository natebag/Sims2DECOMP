#ifndef APTERROR_H
#define APTERROR_H

#include "types.h"

// AptError - struct layout extracted from assembly analysis
// Estimated minimum size: 0x2C (44 bytes)
// 6 known fields (1 named), 14 methods

class AptError {
public:
    // Constructors / Destructors
    AptError(EAStringC)  // 0x806F5C38
    AptError(void)  // 0x806F5BBC
    ~AptError(void);  // 0x806F5224

    // Methods
    void CleanNativeFunctions(void);  // 0x806F533C (144B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x806F4E20 (592B)
    void sMethod_toString(AptValue *, int);  // 0x806F52AC (144B)
    void objectMemberSet(AptValue *, EAStringC *, AptValue *);  // 0x806F5070 (436B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (objectMemberLookup)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [W] (AptError, objectMemberLookup, ~AptError)
    u8 _pad_00C[4];  // 0x00C
    u32 m_field_010;  // 0x010 [R] (objectMemberLookup)
    u8 _pad_014[0xC];  // 0x014
    u8 m_field_020;  // 0x020 [R/W] (AptError, objectMemberLookup)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [R/W] (objectMemberLookup, ~AptError)
    u32 m_field_028;  // 0x028 [R] (objectMemberLookup, ~AptError)
};

#endif // APTERROR_H
