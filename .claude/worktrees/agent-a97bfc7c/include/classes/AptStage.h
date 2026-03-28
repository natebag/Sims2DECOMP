#ifndef APTSTAGE_H
#define APTSTAGE_H

#include "types.h"

// AptStage - struct layout extracted from assembly analysis
// Estimated minimum size: 0x21 (33 bytes)
// 6 known fields (1 named), 12 methods

class AptStage {
public:
    // Constructors / Destructors
    AptStage(void)  // 0x806F5CC8
    ~AptStage(void);  // 0x806F5D28

    // Methods
    void CleanNativeFunctions(void);  // 0x806F53CC (236B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x806F54B8 (912B)
    void sMethod_addListener(AptValue *, int);  // 0x806F5848 (56B)
    void sMethod_removeListener(AptValue *, int);  // 0x806F5880 (56B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (objectMemberLookup)
    u16 m_field_002;  // 0x002 [R] (objectMemberLookup)
    u32 m_field_004;  // 0x004 [R] (objectMemberLookup)
    u32 m_field_008;  // 0x008 [W] (AptStage, objectMemberLookup, ~AptStage)
    f32 m_field_00C;  // 0x00C [R/W] (objectMemberLookup)
    u8 _pad_010[0x10];  // 0x010
    u8 m_field_020;  // 0x020 [R/W] (AptStage)
};

#endif // APTSTAGE_H
