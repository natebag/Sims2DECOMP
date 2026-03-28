#ifndef GLOBALSKILLTABLES_H
#define GLOBALSKILLTABLES_H

#include "types.h"

// GlobalSkillTables - struct layout extracted from assembly analysis
// Estimated minimum size: 0x40 (64 bytes)
// 5 known fields (0 named), 3 methods

class GlobalSkillTables {
public:
    // Constructors / Destructors
    GlobalSkillTables(void)  // 0x803BD934
    ~GlobalSkillTables(void);  // 0x803BD734

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x18];  // 0x000
    u32 m_field_018;  // 0x018 [R/W] (~GlobalSkillTables)
    u32 m_field_01C;  // 0x01C [R/W] (~GlobalSkillTables)
    u8 _pad_020[0x14];  // 0x020
    u32 m_field_034;  // 0x034 [R/W] (~GlobalSkillTables)
    u32 m_field_038;  // 0x038 [R/W] (~GlobalSkillTables)
    u32 m_field_03C;  // 0x03C [R/W] (~GlobalSkillTables)
};

#endif // GLOBALSKILLTABLES_H
