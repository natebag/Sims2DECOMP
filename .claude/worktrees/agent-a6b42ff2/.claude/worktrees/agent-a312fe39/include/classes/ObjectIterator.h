#ifndef OBJECTITERATOR_H
#define OBJECTITERATOR_H

#include "types.h"

// ObjectIterator - struct layout extracted from assembly analysis
// Estimated minimum size: 0x98 (152 bytes)
// 5 known fields (1 named), 11 methods

class ObjectIterator {
public:
    // Constructors / Destructors
    ObjectIterator(CTilePt &, ObjectIterator::IterateType)  // 0x8007E60C
    ObjectIterator(cXObject *, ObjectIterator::IterateType)  // 0x802D82E0

    // Methods
    void finished(void);  // 0x8007E688 (56B)
    void operator*(void);  // 0x8007E65C (44B)
    void operator++(void);  // 0x802D8398 (444B)
    void init(CTilePt &, ObjectIterator::IterateType);  // 0x802D8204 (220B)
    void operator==(ObjectIterator &);  // 0x802D8324 (116B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (init, operator++)
    u32 m_field_004;  // 0x004 [R/W] (init, operator++)
    u32 m_field_008;  // 0x008 [W] (init)
    u8 _pad_00C[0x84];  // 0x00C
    u32 m_field_090;  // 0x090 [R] (operator++)
    u32 m_field_094;  // 0x094 [R] (operator++)
};

#endif // OBJECTITERATOR_H
