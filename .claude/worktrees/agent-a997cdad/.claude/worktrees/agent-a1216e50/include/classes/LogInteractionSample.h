#ifndef LOGINTERACTIONSAMPLE_H
#define LOGINTERACTIONSAMPLE_H

#include "types.h"

// LogInteractionSample - struct layout extracted from assembly analysis
// Estimated minimum size: 0x3C (60 bytes)
// 15 known fields (0 named), 6 methods

class LogInteractionSample {
public:
    // Constructors / Destructors
    LogInteractionSample(void)  // 0x803B1CCC

    // Methods
    void Print(void);  // 0x803B1D30 (860B)
    void PrintHeader(void);  // 0x803B208C (664B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (Print)
    f32 m_field_004;  // 0x004 [R] (Print)
    f32 m_field_008;  // 0x008 [R] (Print)
    f32 m_field_00C;  // 0x00C [R] (Print)
    f32 m_field_010;  // 0x010 [R] (Print)
    f32 m_field_014;  // 0x014 [R] (Print)
    f32 m_field_018;  // 0x018 [R] (Print)
    f32 m_field_01C;  // 0x01C [R] (Print)
    f32 m_field_020;  // 0x020 [R] (Print)
    f32 m_field_024;  // 0x024 [R] (Print)
    u32 m_field_028;  // 0x028 [R/W] (LogInteractionSample, Print)
    u32 m_field_02C;  // 0x02C [R/W] (LogInteractionSample, Print)
    u32 m_field_030;  // 0x030 [R/W] (LogInteractionSample, Print)
    u32 m_field_034;  // 0x034 [R/W] (LogInteractionSample, Print)
    u32 m_field_038;  // 0x038 [R] (Print)
};

#endif // LOGINTERACTIONSAMPLE_H
