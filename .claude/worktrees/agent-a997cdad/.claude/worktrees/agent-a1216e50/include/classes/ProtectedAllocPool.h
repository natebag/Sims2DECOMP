#ifndef PROTECTEDALLOCPOOL_H
#define PROTECTEDALLOCPOOL_H

#include "types.h"

// ProtectedAllocPool - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 2 known fields (0 named), 10 methods

class ProtectedAllocPool {
public:
    // Constructors / Destructors
    ProtectedAllocPool(char *, void *, int, int)  // 0x8077BA28
    ~ProtectedAllocPool(void);  // 0x8077BB2C

    // Methods
    void Free(void *);  // 0x8077BE60 (92B)
    void Alloc(void);  // 0x8077BE00 (96B)
    void Valid(void);  // 0x8077BEBC (84B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x14];  // 0x000
    u32 m_field_014;  // 0x014 [W] (ProtectedAllocPool, ~ProtectedAllocPool)
    u32 m_field_018;  // 0x018 [R] (Alloc, Free)
};

#endif // PROTECTEDALLOCPOOL_H
