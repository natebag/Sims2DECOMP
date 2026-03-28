#ifndef APTXML_H
#define APTXML_H

#include "types.h"

// AptXml - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 8 known fields (1 named), 20 methods

class AptXml {
public:
    // Constructors / Destructors
    AptXml(AptValue *)  // 0x80710698
    AptXml(IAptXmlNode *)  // 0x80710640
    ~AptXml(void);  // 0x8071043C

    // Methods
    void CleanNativeFunctions(void);  // 0x807104A4 (412B)
    void PreDestroy(void);  // 0x8071081C (128B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x8071089C (1604B)
    void sMethod_getBytesTotal(AptValue *, int);  // 0x80710EE0 (204B)
    void sMethod_getBytesLoaded(AptValue *, int);  // 0x80710FAC (204B)
    void sMethod_load(AptValue *, int);  // 0x80711078 (308B)
    void sMethod_parseXml(AptValue *, int);  // 0x807111AC (312B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AptXml, objectMemberLookup, sMethod_getBytesLoaded, ...)
    u16 m_field_002;  // 0x002 [R] (objectMemberLookup)
    u32 m_field_004;  // 0x004 [R] (objectMemberLookup)
    u32 m_field_008;  // 0x008 [W] (AptXml, objectMemberLookup, sMethod_getBytesLoaded, ...)
    u32 m_field_00C;  // 0x00C [R/W] (objectMemberLookup, sMethod_getBytesLoaded, sMethod_getBytesTotal)
    u32 m_field_010;  // 0x010 [R] (objectMemberLookup)
    u8 _pad_014[0xC];  // 0x014
    u8 m_field_020;  // 0x020 [R/W] (objectMemberLookup)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [R/W] (AptXml, PreDestroy, objectMemberLookup, ...)
};

#endif // APTXML_H
