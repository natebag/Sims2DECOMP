#ifndef BLOOMNGC_H
#define BLOOMNGC_H

#include "types.h"

// BloomNGC - struct layout extracted from assembly analysis
// Estimated minimum size: 0x2C78 (11384 bytes)
// 10 known fields (1 named), 5 methods

class BloomNGC {
public:
    // Constructors / Destructors
    BloomNGC(void)  // 0x808F4E20
    ~BloomNGC(void);  // 0x808F7EFC

    // Methods
    void Draw(ERC *);  // 0x808F701C (1260B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (Draw)
    f32 m_field_004;  // 0x004 [W] (Draw)
    u8 _pad_008[0x38];  // 0x008
    f32 m_field_040;  // 0x040 [R] (Draw)
    f32 m_field_044;  // 0x044 [R] (Draw)
    f32 m_field_048;  // 0x048 [R] (Draw)
    u8 _pad_04C[8];  // 0x04C
    f32 m_field_054;  // 0x054 [R] (Draw)
    f32 m_field_058;  // 0x058 [R] (Draw)
    u8 _pad_05C[0x670];  // 0x05C
    u32 m_field_6CC;  // 0x6CC [R/W] (Draw)
    u8 _pad_6D0[0x308];  // 0x6D0
    u32 m_field_9D8;  // 0x9D8 [W] (Draw)
    u8 _pad_9DC[0x2298];  // 0x9DC
    f32 m_field_2C74;  // 0x2C74 [R] (Draw)
};

#endif // BLOOMNGC_H
