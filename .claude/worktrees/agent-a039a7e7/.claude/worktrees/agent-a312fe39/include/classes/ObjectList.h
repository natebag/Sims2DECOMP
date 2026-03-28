#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include "types.h"

// ObjectList - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (1 named), 10 methods

class ObjectList {
public:
    // Constructors / Destructors
    ObjectList(void)  // 0x800D9DD0
    ~ObjectList(void);  // 0x800DBF2C

    // Methods
    void AddObject(cXObject *);  // 0x800D9E2C (156B)
    void RemoveObject(cXObject *);  // 0x800D9EC8 (156B)
    void RemoveAll(void);  // 0x800D9F64 (128B)
    /* ? */ GetItems(void);  // 0x800DBF84 (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddObject, RemoveAll, RemoveObject)
    u32 m_field_004;  // 0x004 [R/W] (AddObject, RemoveAll, RemoveObject)
    u32 m_field_008;  // 0x008 [R/W] (RemoveAll)
    u32 m_field_00C;  // 0x00C [R/W] (AddObject)
};

#endif // OBJECTLIST_H
