#ifndef NEIGHBORLIST_H
#define NEIGHBORLIST_H

#include "types.h"

// NeighborList - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (1 named), 4 methods

class NeighborList {
public:
    // Constructors / Destructors
    NeighborList(void)  // 0x800CD07C
    ~NeighborList(void);  // 0x800CD12C

    // Methods
    void DeleteAll(void);  // 0x80279CF8 (240B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (DeleteAll)
    u32 m_field_004;  // 0x004 [R/W] (DeleteAll)
    u32 m_field_008;  // 0x008 [R/W] (DeleteAll)
};

#endif // NEIGHBORLIST_H
