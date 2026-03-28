#ifndef RELMATRIX_H
#define RELMATRIX_H

#include "types.h"

// RelMatrix - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (1 named), 7 methods

class RelMatrix {
public:
    // Constructors / Destructors
    RelMatrix(void)  // 0x8039A4C8
    ~RelMatrix(void);  // 0x80399A94

    // Methods
    void CreateInstance(void);  // 0x803970E0 (80B)
    void DestroyInstance(RelMatrix *);  // 0x80397130 (120B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (CreateInstance)
    u32 m_field_004;  // 0x004 [W] (CreateInstance)
    u32 m_field_008;  // 0x008 [W] (CreateInstance)
};

#endif // RELMATRIX_H
