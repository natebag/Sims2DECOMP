#ifndef APTTEXTFORMAT_H
#define APTTEXTFORMAT_H

#include "types.h"

// AptTextFormat - struct layout extracted from assembly analysis
// Estimated minimum size: 0x44 (68 bytes)
// 15 known fields (1 named), 10 methods

class AptTextFormat {
public:
    // Constructors / Destructors
    AptTextFormat(AptValue *, float, unsigned int, int, int, int, int, int, AptValue *, int, int, int, int)  // 0x8070072C
    AptTextFormat(TextFormat *)  // 0x807007FC
    ~AptTextFormat(void);  // 0x807009A4

    // Methods
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x806FFB44 (1348B)
    void objectMemberSet(AptValue *, EAStringC *, AptValue *);  // 0x80700088 (1660B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (objectMemberLookup)
    u16 m_field_002;  // 0x002 [R] (objectMemberLookup, objectMemberSet)
    u32 m_field_004;  // 0x004 [R] (objectMemberLookup, objectMemberSet)
    u32 m_field_008;  // 0x008 [W] (AptTextFormat, objectMemberLookup, ~AptTextFormat)
    f32 m_field_00C;  // 0x00C [R/W] (objectMemberLookup)
    u32 m_field_010;  // 0x010 [R] (objectMemberLookup)
    u8 _pad_014[0xC];  // 0x014
    u8 m_field_020;  // 0x020 [R/W] (AptTextFormat)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [R] (objectMemberLookup)
    f32 m_field_028;  // 0x028 [R/W] (objectMemberLookup, objectMemberSet)
    u32 m_field_02C;  // 0x02C [R/W] (objectMemberLookup, objectMemberSet)
    u32 m_field_030;  // 0x030 [R/W] (objectMemberLookup, objectMemberSet)
    u32 m_field_034;  // 0x034 [R/W] (objectMemberLookup, objectMemberSet)
    u32 m_field_038;  // 0x038 [R/W] (objectMemberLookup, objectMemberSet)
    u32 m_field_03C;  // 0x03C [R/W] (objectMemberLookup, objectMemberSet)
    u32 m_field_040;  // 0x040 [R/W] (objectMemberLookup, objectMemberSet)
};

#endif // APTTEXTFORMAT_H
