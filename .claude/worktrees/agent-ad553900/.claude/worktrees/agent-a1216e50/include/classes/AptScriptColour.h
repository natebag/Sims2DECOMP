#ifndef APTSCRIPTCOLOUR_H
#define APTSCRIPTCOLOUR_H

#include "types.h"

// AptScriptColour - struct layout extracted from assembly analysis
// Estimated minimum size: 0x5DCC (24012 bytes)
// 6 known fields (1 named), 20 methods

class AptScriptColour {
public:
    // Constructors / Destructors
    AptScriptColour(AptValue *)  // 0x8070C5E0
    ~AptScriptColour(void);  // 0x8070C738

    // Methods
    void CleanNativeFunctions(void);  // 0x8070C7A0 (412B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x8070C93C (780B)
    void sMethod_setRGB(AptValue *, int);  // 0x8070CC48 (408B)
    void sMethod_getRGB(AptValue *, int);  // 0x8070CDE0 (264B)
    void sMethod_getTransform(AptValue *, int);  // 0x8070CEE8 (964B)
    void sMethod_setTransform(AptValue *, int);  // 0x8070D2AC (1348B)
    void RegisterReferences(void);  // 0x8070D7F0 (116B)
    void DestroyGCPointers(void);  // 0x8070D864 (148B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (objectMemberLookup, sMethod_getRGB, sMethod_setTransform)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [R/W] (AptScriptColour, objectMemberLookup, sMethod_getRGB, ...)
    u32 m_field_00C;  // 0x00C [R/W] (sMethod_getRGB, sMethod_getTransform)
    u8 _pad_010[0x10];  // 0x010
    u8 m_field_020;  // 0x020 [R/W] (AptScriptColour, objectMemberLookup, sMethod_getTransform)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [R/W] (AptScriptColour, DestroyGCPointers, RegisterReferences, ...)
    u8 _pad_028[0x5DA0];  // 0x028
    f32 m_field_5DC8;  // 0x5DC8 [R] (sMethod_setRGB)
};

#endif // APTSCRIPTCOLOUR_H
