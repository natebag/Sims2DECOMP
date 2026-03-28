#ifndef RELATIONSCMP_H
#define RELATIONSCMP_H

#include "types.h"

// RelationsCmp - struct layout extracted from assembly analysis
// Estimated minimum size: 0xEA (234 bytes)
// 4 known fields (0 named), 4 methods

class RelationsCmp {
public:
    // Constructors / Destructors
    RelationsCmp(int)  // 0x800CD750
    ~RelationsCmp(void);  // 0x800CD780

    // Methods
    void operator()(Neighbor *, Neighbor *);  // 0x800C7788 (1216B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (operator)
    u32 m_field_004;  // 0x004 [R] (operator)
    u8 _pad_008[0x14];  // 0x008
    u32 m_field_01C;  // 0x01C [R] (operator)
    u8 _pad_020[0xC8];  // 0x020
    s16 m_field_0E8;  // 0x0E8 [R] (operator)
};

#endif // RELATIONSCMP_H
