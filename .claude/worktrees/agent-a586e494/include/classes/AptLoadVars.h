#ifndef APTLOADVARS_H
#define APTLOADVARS_H

#include "types.h"

// AptLoadVars - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 8 known fields (1 named), 20 methods

class AptLoadVars {
public:
    // Constructors / Destructors
    AptLoadVars(void)  // 0x806F5B60
    ~AptLoadVars(void);  // 0x806F40DC

    // Methods
    void CleanNativeFunctions(void);  // 0x806F4144 (604B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x806F3AF8 (1508B)
    void sMethod_load(AptValue *, int);  // 0x806F43A0 (528B)
    void sMethod_send(AptValue *, int);  // 0x806F45B0 (580B)
    void sMethod_sendAndLoad(AptValue *, int);  // 0x806F47F4 (956B)
    void sMethod_getBytesTotal(AptValue *, int);  // 0x806F4BB0 (240B)
    void sMethod_getBytesLoaded(AptValue *, int);  // 0x806F4CA0 (240B)
    void sMethod_toString(AptValue *, int);  // 0x806F4D90 (144B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (objectMemberLookup, sMethod_getBytesLoaded, sMethod_getBytesTotal, ...)
    u16 m_field_002;  // 0x002 [R] (objectMemberLookup, sMethod_load, sMethod_sendAndLoad)
    u32 m_field_004;  // 0x004 [R] (objectMemberLookup)
    u32 m_field_008;  // 0x008 [R/W] (AptLoadVars, objectMemberLookup, sMethod_getBytesLoaded, ...)
    f32 m_field_00C;  // 0x00C [R/W] (objectMemberLookup, sMethod_getBytesLoaded, sMethod_getBytesTotal, ...)
    u32 m_field_010;  // 0x010 [R] (objectMemberLookup)
    u8 _pad_014[0xC];  // 0x014
    u8 m_field_020;  // 0x020 [R/W] (AptLoadVars, objectMemberLookup)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [R/W] (AptLoadVars, objectMemberLookup, sMethod_load, ...)
};

#endif // APTLOADVARS_H
