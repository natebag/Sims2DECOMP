#ifndef BITMATRIX64_H
#define BITMATRIX64_H

#include "types.h"

// BitMatrix64 - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 6 known fields (1 named), 32 methods

class BitMatrix64 {
public:
    // Constructors / Destructors
    BitMatrix64(void)  // 0x801EEC94
    BitMatrix64(BitMatrix64 &)  // 0x801EED08
    ~BitMatrix64(void);  // 0x801EED90

    // Methods
    void operator=(BitMatrix64 &);  // 0x801EEE30 (88B)
    void operator[](int);  // 0x801EEE88 (60B)
    bool IsSet(CTilePt &);  // 0x801EEF00 (112B)
    void Set(CTilePt &);  // 0x801EEF70 (100B)
    void Clear(CTilePt &);  // 0x801EEFD4 (100B)
    void Clear(void);  // 0x801EF038 (64B)
    void operator&=(BitMatrix64 &);  // 0x801EF078 (148B)
    void operator|=(BitMatrix64 &);  // 0x801EF10C (148B)
    void operator^=(BitMatrix64 &);  // 0x801EF1A0 (148B)
    void operator<<=(int);  // 0x801EF234 (128B)
    void operator>>=(int);  // 0x801EF2B4 (128B)
    void CountBits(void);  // 0x801EF334 (148B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (operator=)
    u32 m_field_004;  // 0x004 [W] (operator=)
    u32 m_field_008;  // 0x008 [W] (operator=)
    u32 m_field_00C;  // 0x00C [W] (operator=)
    u32 m_field_010;  // 0x010 [W] (operator=)
    u32 m_field_014;  // 0x014 [W] (operator=)
};

#endif // BITMATRIX64_H
