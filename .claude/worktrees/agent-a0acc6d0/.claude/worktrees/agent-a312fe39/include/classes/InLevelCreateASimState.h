#ifndef INLEVELCREATEASIMSTATE_H
#define INLEVELCREATEASIMSTATE_H

#include "types.h"

// InLevelCreateASimState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x30 (48 bytes)
// 3 known fields (0 named), 8 methods

class InLevelCreateASimState {
public:
    // Constructors / Destructors
    InLevelCreateASimState(int)  // 0x801D46D4
    ~InLevelCreateASimState(void);  // 0x801D39D8

    // Methods
    void Reset(void);  // 0x801D09D4 (96B)
    void Update(float);  // 0x801D0A34 (256B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x20];  // 0x000
    u32 m_field_020;  // 0x020 [R] (Update)
    u8 _pad_024[4];  // 0x024
    u32 m_field_028;  // 0x028 [R] (Update)
    u32 m_field_02C;  // 0x02C [R] (Update)
};

#endif // INLEVELCREATEASIMSTATE_H
