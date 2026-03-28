#ifndef PASSIVEINFLUENCESYSTEM_H
#define PASSIVEINFLUENCESYSTEM_H

#include "types.h"

// PassiveInfluenceSystem - struct layout extracted from assembly analysis
// Estimated minimum size: 0x30 (48 bytes)
// 13 known fields (3 named), 24 methods

class PassiveInfluenceSystem {
public:
    // Constructors / Destructors
    PassiveInfluenceSystem(void)  // 0x80336984
    ~PassiveInfluenceSystem(void);  // 0x80336A60

    // Methods
    void RemoveObjectFromMap(cXObject *);  // 0x80336EBC (796B)
    void MoveObjectInWorld(cXObject *);  // 0x803371D8 (1456B)
    void FlushSystem(void);  // 0x80336B14 (92B)
    void AddObjectToMap(cXObject *, signed char, signed char, signed char, signed char);  // 0x80336BD0 (748B)
    void ClearInfluenceMotiveDeltas(cXObject *);  // 0x803388D8 (272B)
    void SetInfluenceMotiveDelta(cXObject *, unsigned char, float, short);  // 0x80338758 (384B)
    void SetSkillNameID(cXObject *, AnimRef *);  // 0x803389E8 (284B)
    void NotifySimulator(cXPerson *, int, int);  // 0x80337788 (2856B)
    void DoStream(ReconBuffer *, int);  // 0x80336B70 (96B)
    void CheckObjects(int);  // 0x803382B0 (1192B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddObjectToMap, CheckObjects, MoveObjectInWorld, ...)
    u32 m_skillNameID;  // 0x004 [R/W] (AddObjectToMap, CheckObjects, ClearInfluenceMotiveDeltas, ...)
    u32 m_influenceMotiveDelta_008;  // 0x008 [R/W] (AddObjectToMap, CheckObjects, MoveObjectInWorld, ...)
    s16 m_field_00A;  // 0x00A [R] (MoveObjectInWorld)
    u32 m_field_00C;  // 0x00C [R] (CheckObjects)
    u8 _pad_010[8];  // 0x010
    u8 m_field_018;  // 0x018 [R/W] (AddObjectToMap, MoveObjectInWorld, NotifySimulator)
    u8 m_field_019;  // 0x019 [W] (AddObjectToMap)
    u8 m_field_01A;  // 0x01A [W] (AddObjectToMap)
    u8 m_field_01B;  // 0x01B [W] (AddObjectToMap)
    u32 m_field_01C;  // 0x01C [W] (AddObjectToMap)
    u32 m_field_020;  // 0x020 [W] (AddObjectToMap)
    u32 m_field_024;  // 0x024 [W] (AddObjectToMap)
    u8 _pad_028[4];  // 0x028
    u32 m_field_02C;  // 0x02C [W] (AddObjectToMap)
};

#endif // PASSIVEINFLUENCESYSTEM_H
