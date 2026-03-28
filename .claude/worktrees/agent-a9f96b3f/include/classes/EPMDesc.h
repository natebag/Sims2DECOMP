#ifndef EPMDESC_H
#define EPMDESC_H

#include "types.h"

// EPMDesc - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 5 known fields (1 named), 4 methods

class EPMDesc {
public:
    // Constructors / Destructors
    EPMDesc(char *, bool)  // 0x808A21E0
    EPMDesc(unsigned int, bool)  // 0x808A2188

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (EPMDesc)
    u32 m_field_004;  // 0x004 [W] (EPMDesc)
    u32 m_field_008;  // 0x008 [W] (EPMDesc)
    u32 m_field_00C;  // 0x00C [W] (EPMDesc)
    u32 m_field_010;  // 0x010 [W] (EPMDesc)
};

#endif // EPMDESC_H
