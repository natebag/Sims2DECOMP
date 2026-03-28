#ifndef APTMEMORYALLOCATIONST_H
#define APTMEMORYALLOCATIONST_H

#include "types.h"

// AptMemoryAllocationsT - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 8 known fields (1 named), 7 methods

class AptMemoryAllocationsT {
public:
    // Constructors / Destructors
    AptMemoryAllocationsT(void)  // 0x806A6564

    // Methods
    void operator+(AptMemoryAllocationsT &);  // 0x806A131C (332B)
    void operator+=(AptMemoryAllocationsT &);  // 0x806A1468 (204B)
    void Reset(void);  // 0x806A1534 (96B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (operator+=)
    u32 m_field_004;  // 0x004 [R/W] (operator+=)
    u32 m_field_008;  // 0x008 [R/W] (operator+=)
    u32 m_field_00C;  // 0x00C [R/W] (operator+=)
    u32 m_field_010;  // 0x010 [R/W] (operator+=)
    u32 m_field_014;  // 0x014 [R/W] (operator+=)
    u32 m_field_018;  // 0x018 [R/W] (operator+=)
    u32 m_field_01C;  // 0x01C [R/W] (operator+=)
};

#endif // APTMEMORYALLOCATIONST_H
