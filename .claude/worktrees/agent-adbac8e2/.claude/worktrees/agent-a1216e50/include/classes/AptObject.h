#ifndef APTOBJECT_H
#define APTOBJECT_H

#include "types.h"

// AptObject - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 4 known fields (1 named), 30 methods

class AptObject {
public:
    // Constructors / Destructors
    AptObject(AptVirtualFunctionTable_Indices, int)  // 0x8070C108
    ~AptObject(void);  // 0x8070C388

    // Methods
    void setInMainInst(int);  // 0x8070C1F4 (64B)
    /* ? */ GetImplementedObjects(int *);  // 0x8070BB04 (176B)
    void SetImplementedObjects(AptArray *, int);  // 0x8070BA80 (132B)
    void Set(EAStringC *, AptValue *);  // 0x8070C264 (76B)
    void DoesImplementObject(AptValue *);  // 0x8070BBB4 (532B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x8070B998 (104B)
    void getHasClass(void);  // 0x8070C1C4 (48B)
    void setHasClass(int);  // 0x8070C184 (64B)
    void DestroyGCPointers(void);  // 0x8070BA44 (60B)
    void RegisterReferences(void);  // 0x8070BA00 (68B)
    void Lookup(EAStringC *);  // 0x8070C2B0 (80B)
    void getInMainInst(void);  // 0x8070C234 (48B)
    void SetPrototype(AptValue *);  // 0x8070C344 (68B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R/W] (AptObject, DoesImplementObject, ~AptObject)
    u8 _pad_00C[8];  // 0x00C
    u32 m_field_014;  // 0x014 [R] (DoesImplementObject)
    u8 _pad_018[8];  // 0x018
    u8 m_implementedObjects;  // 0x020 [R/W] (AptObject, DoesImplementObject, GetImplementedObjects, ...)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [R] (DoesImplementObject)
};

#endif // APTOBJECT_H
