#ifndef APTXMLNODE_H
#define APTXMLNODE_H

#include "types.h"

// AptXmlNode - struct layout extracted from assembly analysis
// Estimated minimum size: 0x2C (44 bytes)
// 9 known fields (0 named), 24 methods

class AptXmlNode {
public:
    // Constructors / Destructors
    AptXmlNode(AptVirtualFunctionTable_Indices, IAptXmlNode *)  // 0x80711468
    ~AptXmlNode(void);  // 0x807114FC

    // Methods
    void CleanNativeFunctions(void);  // 0x80711574 (596B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x807119AC (3348B)
    void objectMemberSet(AptValue *, EAStringC *, AptValue *);  // 0x807117C8 (484B)
    void PreDestroy(void);  // 0x807114D4 (40B)
    void sMethod_appendChild(AptValue *, int);  // 0x807126C0 (56B)
    void sMethod_cloneNode(AptValue *, int);  // 0x807126F8 (56B)
    void sMethod_hasChildNodes(AptValue *, int);  // 0x80712730 (272B)
    void sMethod_insertBefore(AptValue *, int);  // 0x80712840 (56B)
    void sMethod_removeNode(AptValue *, int);  // 0x80712878 (56B)
    void sMethod_toString(AptValue *, int);  // 0x807128B0 (284B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_field_000;  // 0x000 [R/W] (objectMemberLookup, sMethod_hasChildNodes, sMethod_toString)
    u16 m_field_002;  // 0x002 [R] (objectMemberLookup)
    u16 m_field_004;  // 0x004 [R] (objectMemberLookup)
    u8 _pad_006[2];  // 0x006
    u32 m_field_008;  // 0x008 [W] (AptXmlNode, objectMemberLookup, sMethod_hasChildNodes, ...)
    u32 m_field_00C;  // 0x00C [R/W] (objectMemberLookup, sMethod_hasChildNodes)
    u32 m_field_010;  // 0x010 [R] (objectMemberLookup, sMethod_toString)
    u8 _pad_014[0xC];  // 0x014
    u8 m_field_020;  // 0x020 [R/W] (AptXmlNode, objectMemberLookup)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [R/W] (AptXmlNode, objectMemberLookup, sMethod_hasChildNodes, ...)
    u32 m_field_028;  // 0x028 [W] (AptXmlNode, ~AptXmlNode)
};

#endif // APTXMLNODE_H
