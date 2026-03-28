#ifndef PASSIVEINFLUENCEPERSON_H
#define PASSIVEINFLUENCEPERSON_H

#include "types.h"

// PassiveInfluencePerson - struct layout extracted from assembly analysis
// Estimated minimum size: 0x2C (44 bytes)
// 6 known fields (1 named), 14 methods

class PassiveInfluencePerson {
public:
    // Constructors / Destructors
    PassiveInfluencePerson(void)  // 0x8033AE50
    ~PassiveInfluencePerson(void);  // 0x8033CCE0

    // Methods
    /* ? */ GetAnimation(void);  // 0x80031664 (48B)
    /* ? */ GetSkillName(void);  // 0x80031694 (44B)
    void NoEffectWhenHeld(void);  // 0x8033B09C (60B)
    void NoEffectToHolder(void);  // 0x8033B068 (52B)
    /* ? */ GetObject(void);  // 0x8033CDF8 (44B)
    /* ? */ GetType(void);  // 0x8033CE24 (40B)
    /* ? */ GetTileVector(void);  // 0x8033CE4C (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (~PassiveInfluencePerson)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [R/W] (~PassiveInfluencePerson)
    u32 m_field_00C;  // 0x00C [R/W] (~PassiveInfluencePerson)
    u8 _pad_010[0x10];  // 0x010
    u32 m_field_020;  // 0x020 [R/W] (~PassiveInfluencePerson)
    u32 m_field_024;  // 0x024 [R/W] (~PassiveInfluencePerson)
    u32 m_field_028;  // 0x028 [R/W] (~PassiveInfluencePerson)
};

#endif // PASSIVEINFLUENCEPERSON_H
