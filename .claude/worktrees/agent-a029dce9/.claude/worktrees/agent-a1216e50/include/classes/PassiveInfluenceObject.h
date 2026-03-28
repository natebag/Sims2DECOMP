#ifndef PASSIVEINFLUENCEOBJECT_H
#define PASSIVEINFLUENCEOBJECT_H

#include "types.h"

// PassiveInfluenceObject - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 3 known fields (1 named), 9 methods

class PassiveInfluenceObject {
public:
    // Constructors / Destructors
    PassiveInfluenceObject(void)  // 0x8033B0D8
    ~PassiveInfluenceObject(void);  // 0x8033CE78

    // Methods
    /* ? */ GetObject(void);  // 0x8033CF28 (44B)
    /* ? */ GetType(void);  // 0x8033CF54 (40B)
    /* ? */ GetTileVector(void);  // 0x8033CF7C (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (~PassiveInfluenceObject)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [R/W] (~PassiveInfluenceObject)
    u32 m_field_00C;  // 0x00C [R/W] (~PassiveInfluenceObject)
};

#endif // PASSIVEINFLUENCEOBJECT_H
