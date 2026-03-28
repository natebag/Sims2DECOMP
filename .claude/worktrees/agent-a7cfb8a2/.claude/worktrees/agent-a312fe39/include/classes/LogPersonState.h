#ifndef LOGPERSONSTATE_H
#define LOGPERSONSTATE_H

#include "types.h"

// LogPersonState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x40 (64 bytes)
// 13 known fields (10 named), 4 methods

class LogPersonState {
public:
    // Constructors / Destructors
    LogPersonState(cXPerson *)  // 0x803B1A40

    // Methods
    void SetDeltas(cXPerson *);  // 0x803B1BF8 (212B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (LogPersonState)
    f32 m_deltas;  // 0x004 [R/W] (LogPersonState, SetDeltas)
    f32 m_deltas_008;  // 0x008 [R/W] (LogPersonState, SetDeltas)
    f32 m_deltas_00C;  // 0x00C [R/W] (LogPersonState, SetDeltas)
    f32 m_deltas_010;  // 0x010 [R/W] (LogPersonState, SetDeltas)
    f32 m_deltas_014;  // 0x014 [R/W] (LogPersonState, SetDeltas)
    f32 m_deltas_018;  // 0x018 [R/W] (LogPersonState, SetDeltas)
    f32 m_deltas_01C;  // 0x01C [R/W] (LogPersonState, SetDeltas)
    f32 m_deltas_020;  // 0x020 [R/W] (LogPersonState, SetDeltas)
    f32 m_deltas_024;  // 0x024 [R/W] (LogPersonState, SetDeltas)
    u8 _pad_028[0xC];  // 0x028
    f32 m_field_034;  // 0x034 [R] (LogPersonState)
    f32 m_field_038;  // 0x038 [R] (LogPersonState)
    f32 m_field_03C;  // 0x03C [R] (LogPersonState)
};

#endif // LOGPERSONSTATE_H
