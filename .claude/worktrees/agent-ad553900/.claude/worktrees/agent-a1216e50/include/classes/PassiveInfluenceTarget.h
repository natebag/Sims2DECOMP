#ifndef PASSIVEINFLUENCETARGET_H
#define PASSIVEINFLUENCETARGET_H

#include "types.h"

// PassiveInfluenceTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (1 named), 10 methods

class PassiveInfluenceTarget {
public:
    // Constructors / Destructors
    PassiveInfluenceTarget(void)  // 0x8033B14C
    ~PassiveInfluenceTarget(void);  // 0x8033CFA8

    // Methods
    /* ? */ GetObject(void);  // 0x8033D074 (44B)
    /* ? */ GetType(void);  // 0x8033D0A0 (40B)
    /* ? */ GetTileVector(void);  // 0x8033D0C8 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (PassiveInfluenceTarget, ~PassiveInfluenceTarget)
    u32 m_field_004;  // 0x004 [W] (PassiveInfluenceTarget)
    u32 m_field_008;  // 0x008 [R/W] (PassiveInfluenceTarget, ~PassiveInfluenceTarget)
    u32 m_field_00C;  // 0x00C [R/W] (~PassiveInfluenceTarget)
};

#endif // PASSIVEINFLUENCETARGET_H
