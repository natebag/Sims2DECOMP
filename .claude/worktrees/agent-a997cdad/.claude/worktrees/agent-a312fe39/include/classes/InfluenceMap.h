#ifndef INFLUENCEMAP_H
#define INFLUENCEMAP_H

#include "types.h"

// InfluenceMap - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 6 known fields (3 named), 22 methods

class InfluenceMap {
public:
    // Constructors / Destructors
    InfluenceMap(int, int)  // 0x800D9FE4
    ~InfluenceMap(void);  // 0x800DA0AC

    // Methods
    void RemoveAll(void);  // 0x800DA16C (180B)
    void CalculateAffectedArea(cXObject *, ITreeTableEntry *, FTileRect &);  // 0x800DA220 (1112B)
    void AddObjectToMap(cXObject *);  // 0x800DA678 (828B)
    void ValidateMissing(cXObject *);  // 0x800DB5DC (296B)
    void AddObjectEntry(cXObject *, ITreeTableEntry *);  // 0x800DA9B4 (1104B)
    void RemoveObjectFromMap(cXObject *);  // 0x800DAE04 (700B)
    void RemoveObjectEntry(cXObject *, ITreeTableEntry *);  // 0x800DB0C0 (720B)
    /* ? */ GetObjectList(int, int);  // 0x800DB390 (588B)
    void Validate(void);  // 0x800DB704 (408B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddObjectEntry, AddObjectToMap, CalculateAffectedArea, ...)
    u32 m_objectList_004;  // 0x004 [R/W] (AddObjectEntry, AddObjectToMap, CalculateAffectedArea, ...)
    u32 m_objectList_008;  // 0x008 [R/W] (AddObjectEntry, GetObjectList, InfluenceMap, ...)
    u8 _pad_00C[0xA];  // 0x00C
    s16 m_field_016;  // 0x016 [R] (CalculateAffectedArea)
    u8 m_field_017;  // 0x017 [R] (CalculateAffectedArea)
    u32 m_field_018;  // 0x018 [R] (AddObjectToMap, RemoveObjectFromMap)
};

#endif // INFLUENCEMAP_H
