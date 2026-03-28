#ifndef ETHREADMUTEX_H
#define ETHREADMUTEX_H

#include "types.h"

// EThreadMutex - struct layout extracted from assembly analysis
// Estimated minimum size: 0x40 (64 bytes)
// 3 known fields (1 named), 8 methods

class EThreadMutex {
public:
    // Constructors / Destructors
    EThreadMutex(void)  // 0x80759360
    ~EThreadMutex(void);  // 0x80759810

    // Methods
    void Acquire(unsigned int);  // 0x807593C8 (324B)
    void Release(void);  // 0x8075950C (224B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (EThreadMutex, ~EThreadMutex)
    u8 _pad_004[0x34];  // 0x004
    u32 m_field_038;  // 0x038 [R/W] (Acquire, EThreadMutex, Release)
    u32 m_field_03C;  // 0x03C [R/W] (Acquire, EThreadMutex, Release)
};

#endif // ETHREADMUTEX_H
