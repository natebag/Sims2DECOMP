#ifndef EBITARRAYPROXY_H
#define EBITARRAYPROXY_H

#include "types.h"

// EBitArrayProxy - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (0 named), 9 methods

class EBitArrayProxy {
public:
    // Constructors / Destructors
    EBitArrayProxy(EBitArray *, int)  // 0x80795D18

    // Methods
    void operator=(bool);  // 0x80792EC0 (68B)
    void operator|=(bool);  // 0x80792F04 (124B)
    void operator&=(bool);  // 0x80792F80 (124B)
    void operator^=(bool);  // 0x80792FFC (156B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (operator&=, operator^=, operator|=)
    u32 m_field_004;  // 0x004 [R] (operator&=, operator^=, operator|=)
};

#endif // EBITARRAYPROXY_H
