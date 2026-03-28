#ifndef EBOUNDSPHERE_H
#define EBOUNDSPHERE_H

#include "types.h"

// EBoundSphere - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (0 named), 9 methods

class EBoundSphere {
public:
    // Constructors / Destructors
    EBoundSphere(void)  // 0x80068C50
    EBoundSphere(EBoundSphere &)  // 0x80141D6C
    EBoundSphere(float)  // 0x80862C08

    // Methods
    void operator=(float);  // 0x8063212C (124B)
    void operator=(EBoundSphere &);  // 0x806320D8 (84B)
    void Combine(EBoundSphere &, EBoundSphere &);  // 0x808F99A0 (756B)
    void ComputeFast(EVec3 *, int);  // 0x808F9C94 (112B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (Combine)
    f32 m_field_004;  // 0x004 [R/W] (Combine)
    f32 m_field_008;  // 0x008 [R/W] (Combine)
    f32 m_field_00C;  // 0x00C [W] (Combine)
};

#endif // EBOUNDSPHERE_H
