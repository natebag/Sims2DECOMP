#ifndef DEPTHOFFIELDNGC_H
#define DEPTHOFFIELDNGC_H

#include "types.h"

// DepthOfFieldNGC - struct layout extracted from assembly analysis
// Estimated minimum size: 0x9DC (2524 bytes)
// 11 known fields (1 named), 5 methods

class DepthOfFieldNGC {
public:
    // Constructors / Destructors
    DepthOfFieldNGC(void)  // 0x808F4E6C
    ~DepthOfFieldNGC(void);  // 0x808F7F48

    // Methods
    void Draw(ERC *);  // 0x808F7508 (1520B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (Draw)
    u8 m_field_001;  // 0x001 [W] (Draw)
    u8 m_field_002;  // 0x002 [W] (Draw)
    u8 m_field_003;  // 0x003 [W] (Draw)
    f32 m_field_004;  // 0x004 [R] (Draw)
    f32 m_field_008;  // 0x008 [R] (Draw)
    u8 _pad_00C[0x1C];  // 0x00C
    u32 m_field_028;  // 0x028 [R] (Draw)
    f32 m_field_02C;  // 0x02C [R] (Draw)
    u8 _pad_030[8];  // 0x030
    f32 m_field_038;  // 0x038 [R] (Draw)
    u8 _pad_03C[0x690];  // 0x03C
    u32 m_field_6CC;  // 0x6CC [R/W] (Draw)
    u8 _pad_6D0[0x308];  // 0x6D0
    u32 m_field_9D8;  // 0x9D8 [W] (Draw)
};

#endif // DEPTHOFFIELDNGC_H
