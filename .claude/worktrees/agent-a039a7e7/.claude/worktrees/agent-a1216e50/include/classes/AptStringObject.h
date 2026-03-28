#ifndef APTSTRINGOBJECT_H
#define APTSTRINGOBJECT_H

#include "types.h"

// AptStringObject - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 2 known fields (0 named), 7 methods

class AptStringObject {
public:
    // Constructors / Destructors
    AptStringObject(AptString *)  // 0x806BC920
    ~AptStringObject(void);  // 0x806BDEC0

    // Methods
    void setString(AptString *);  // 0x806BDF80 (120B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x806BDFF8 (172B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R/W] (objectMemberLookup, ~AptStringObject)
    u8 _pad_00C[0x18];  // 0x00C
    u32 m_field_024;  // 0x024 [R/W] (objectMemberLookup, setString, ~AptStringObject)
};

#endif // APTSTRINGOBJECT_H
