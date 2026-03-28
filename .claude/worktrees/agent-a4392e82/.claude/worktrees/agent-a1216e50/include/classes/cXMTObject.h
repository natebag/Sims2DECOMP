#ifndef CXMTOBJECT_H
#define CXMTOBJECT_H

#include "types.h"

// cXMTObject - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 7 known fields (1 named), 10 methods

class cXMTObject {
public:
    // Constructors / Destructors
    cXMTObject(int)  // 0x80268CD8
    ~cXMTObject(void);  // 0x802603A8

    // Methods
    void setMTObjectImpl(cXMTObjectImpl *);  // 0x80268F14 (64B)
    void CAST_IMPL(void);  // 0x80268F94 (120B)
    void setPortalImpl(cXPortalImpl *);  // 0x80268F54 (64B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (cXMTObject, ~cXMTObject)
    u32 m_field_004;  // 0x004 [R/W] (cXMTObject, ~cXMTObject)
    u32 m_field_008;  // 0x008 [R/W] (cXMTObject)
    u32 m_field_00C;  // 0x00C [R/W] (cXMTObject)
    u32 m_field_010;  // 0x010 [R/W] (cXMTObject)
    u32 m_field_014;  // 0x014 [R/W] (cXMTObject)
    u8 _pad_018[0xC];  // 0x018
    u32 m_field_024;  // 0x024 [W] (cXMTObject)
};

#endif // CXMTOBJECT_H
