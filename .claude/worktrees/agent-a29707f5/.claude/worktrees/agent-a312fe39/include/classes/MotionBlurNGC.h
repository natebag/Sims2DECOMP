#ifndef MOTIONBLURNGC_H
#define MOTIONBLURNGC_H

#include "types.h"

// MotionBlurNGC - struct layout extracted from assembly analysis
// Estimated minimum size: 0x9DC (2524 bytes)
// 6 known fields (1 named), 5 methods

class MotionBlurNGC {
public:
    // Constructors / Destructors
    MotionBlurNGC(void)  // 0x808F4DD4
    ~MotionBlurNGC(void);  // 0x808F7EB0

    // Methods
    void Draw(ERC *);  // 0x808F6978 (1700B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (Draw)
    u16 m_field_002;  // 0x002 [R] (Draw)
    u8 _pad_004[0x20];  // 0x004
    f32 m_field_024;  // 0x024 [R] (Draw)
    u32 m_field_028;  // 0x028 [R] (Draw)
    u8 _pad_02C[0x6A0];  // 0x02C
    u32 m_field_6CC;  // 0x6CC [R/W] (Draw)
    u8 _pad_6D0[0x308];  // 0x6D0
    u32 m_field_9D8;  // 0x9D8 [W] (Draw)
};

#endif // MOTIONBLURNGC_H
