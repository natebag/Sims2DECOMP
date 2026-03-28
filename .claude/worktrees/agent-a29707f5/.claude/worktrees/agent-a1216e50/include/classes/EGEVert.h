#ifndef EGEVERT_H
#define EGEVERT_H

#include "types.h"

// EGEVert - struct layout extracted from assembly analysis
// Estimated minimum size: 0x24 (36 bytes)
// 5 known fields (0 named), 6 methods

class EGEVert {
public:
    // Constructors / Destructors
    EGEVert(void)  // 0x80019100

    // Methods
    void operator=(EGEVert &);  // 0x8007DFE8 (348B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [W] (operator=)
    f32 m_field_004;  // 0x004 [W] (operator=)
    f32 m_field_008;  // 0x008 [W] (operator=)
    f32 m_field_00C;  // 0x00C [W] (operator=)
    u8 _pad_010[0x10];  // 0x010
    f32 m_field_020;  // 0x020 [W] (operator=)
};

#endif // EGEVERT_H
