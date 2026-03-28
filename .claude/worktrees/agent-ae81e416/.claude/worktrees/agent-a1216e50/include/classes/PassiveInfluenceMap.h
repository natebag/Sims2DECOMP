#ifndef PASSIVEINFLUENCEMAP_H
#define PASSIVEINFLUENCEMAP_H

#include "types.h"

// PassiveInfluenceMap - struct layout extracted from assembly analysis
// Estimated minimum size: 0x330 (816 bytes)
// 10 known fields (3 named), 32 methods

class PassiveInfluenceMap {
public:
    // Constructors / Destructors
    PassiveInfluenceMap(int, int)  // 0x803353EC
    ~PassiveInfluenceMap(void);  // 0x8033555C

    // Methods
    void NotifySimulator(cXPerson *, int, int);  // 0x80335FC0 (524B)
    void EmptyMap(void);  // 0x80335EB4 (268B)
    void AddItemToMap(PassiveInfluenceItem *);  // 0x80335628 (768B)
    void RemoveItemFromMap(PassiveInfluenceItem *);  // 0x80335928 (844B)
    void CalculateAffectedArea(PassiveInfluenceItem *);  // 0x803399EC (1896B)
    /* ? */ GetListForTile(int, int);  // 0x80335C74 (576B)
    void CheckObjectInfluence(PassiveInfluenceTarget *);  // 0x803361CC (1156B)
    void ApplyInfluence(PassiveInfluenceObject *, PassiveInfluenceTarget *);  // 0x80336650 (536B)
    void ValidateMissing(PassiveInfluenceItem *);  // 0x80336868 (284B)
    void CalculateTargetArea(PassiveInfluenceItem *);  // 0x80338B04 (444B)
    void FilledArc_Line(int, int, int, PassiveInfluenceItem *);  // 0x80338CC0 (644B)
    void FilledArc_Polygon(int, int, int, int, int, int *, vert2 *);  // 0x80338F44 (1168B)
    void FilledArc(int, int, int, int, int, PassiveInfluenceItem *);  // 0x803393D4 (1560B)
    void Validate(void);  // 0x8033A154 (404B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddItemToMap, ApplyInfluence, CalculateAffectedArea, ...)
    u32 m_listForTile_004;  // 0x004 [R/W] (AddItemToMap, ApplyInfluence, CalculateAffectedArea, ...)
    s16 m_listForTile_008;  // 0x008 [R/W] (AddItemToMap, ApplyInfluence, CheckObjectInfluence, ...)
    u8 _pad_00A[2];  // 0x00A
    u32 m_field_00C;  // 0x00C [R/W] (ApplyInfluence, CalculateAffectedArea, CalculateTargetArea, ...)
    u8 _pad_010[0xF0];  // 0x010
    s16 m_field_100;  // 0x100 [R] (ApplyInfluence)
    u8 _pad_102[2];  // 0x102
    u32 m_field_104;  // 0x104 [R] (ApplyInfluence)
    u8 _pad_108[0x168];  // 0x108
    s16 m_field_270;  // 0x270 [R] (ApplyInfluence)
    u8 _pad_272[2];  // 0x272
    u32 m_field_274;  // 0x274 [R] (ApplyInfluence)
    u8 _pad_278[0xB0];  // 0x278
    s16 m_field_328;  // 0x328 [R] (ApplyInfluence)
    u8 _pad_32A[2];  // 0x32A
    u32 m_field_32C;  // 0x32C [R] (ApplyInfluence)
};

#endif // PASSIVEINFLUENCEMAP_H
