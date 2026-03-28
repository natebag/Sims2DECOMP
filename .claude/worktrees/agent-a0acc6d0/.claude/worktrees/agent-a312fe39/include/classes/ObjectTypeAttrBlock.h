#ifndef OBJECTTYPEATTRBLOCK_H
#define OBJECTTYPEATTRBLOCK_H

#include "types.h"

// ObjectTypeAttrBlock - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (1 named), 11 methods

class ObjectTypeAttrBlock {
public:
    // Constructors / Destructors
    ObjectTypeAttrBlock(int, int)  // 0x8032D228
    ~ObjectTypeAttrBlock(void);  // 0x8032D2C8

    // Methods
    /* ? */ GetGUID(void);  // 0x802D0060 (44B)
    /* ? */ GetNumAttr(void);  // 0x802CFFB8 (44B)
    /* ? */ GetAttr(void);  // 0x802D0034 (44B)
    void SetNumAttr(int);  // 0x802CFFE4 (40B)
    void SetAttributeBuffer(short *);  // 0x802D000C (40B)
    void Clear(void);  // 0x8032D330 (104B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ObjectTypeAttrBlock)
    u32 m_field_004;  // 0x004 [W] (ObjectTypeAttrBlock)
    u32 m_field_008;  // 0x008 [R/W] (ObjectTypeAttrBlock, ~ObjectTypeAttrBlock)
};

#endif // OBJECTTYPEATTRBLOCK_H
