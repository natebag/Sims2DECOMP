#ifndef BITARRAY64_H
#define BITARRAY64_H

#include "types.h"

// BitArray64 - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (2 named), 32 methods

class BitArray64 {
public:
    // Constructors / Destructors
    BitArray64(void)  // 0x801EE714
    BitArray64(BitArray64 &)  // 0x801EE74C
    BitArray64(long long &)  // 0x801EE81C
    ~BitArray64(void);  // 0x801EE78C

    // Methods
    void operator=(BitArray64 &);  // 0x801EE7DC (64B)
    void Clear(void);  // 0x801EE85C (48B)
    bool IsSet(int);  // 0x801EE88C (124B)
    void operator[](int);  // 0x801EE908 (124B)
    void Set(int);  // 0x801EE984 (104B)
    void Clear(int);  // 0x801EE9EC (112B)
    void operator|=(BitArray64 &);  // 0x801EEA5C (80B)
    void operator&=(BitArray64 &);  // 0x801EEAAC (80B)
    void operator^=(BitArray64 &);  // 0x801EEAFC (80B)
    void operator<<=(int);  // 0x801EEB4C (96B)
    void operator>>=(int);  // 0x801EEBAC (96B)
    void CountBits(void);  // 0x801EEC0C (136B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Clear, IsSet, Set, ...)
    u32 m_bIsSet_004;  // 0x004 [R/W] (Clear, IsSet, Set, ...)
};

#endif // BITARRAY64_H
