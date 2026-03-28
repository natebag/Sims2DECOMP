#ifndef APTXMLATTRIBUTES_H
#define APTXMLATTRIBUTES_H

#include "types.h"

// AptXmlAttributes - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 3 known fields (0 named), 8 methods

class AptXmlAttributes {
public:
    // Constructors / Destructors
    AptXmlAttributes(AptVirtualFunctionTable_Indices, IAptXmlNode *)  // 0x8071F574
    ~AptXmlAttributes(void);  // 0x8071F504

    // Methods
    void PreDestroy(void);  // 0x8071F5D8 (40B)
    void objectMemberSet(AptValue *, EAStringC *, AptValue *);  // 0x8071F600 (240B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [W] (AptXmlAttributes, ~AptXmlAttributes)
    u8 _pad_00C[0x14];  // 0x00C
    u8 m_field_020;  // 0x020 [R/W] (AptXmlAttributes)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [W] (AptXmlAttributes, ~AptXmlAttributes)
};

#endif // APTXMLATTRIBUTES_H
