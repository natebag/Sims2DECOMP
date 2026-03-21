#ifndef INFLUENCEMAP_H
#define INFLUENCEMAP_H

#include "types.h"

// Forward declarations
class cXObject;
class cXPerson;
class ReconBuffer;
class ITreeTableEntry;
struct FTileRect;
struct EVec3;

// ============================================================================
// ObjectList - List of objects for influence map tiles
// From: influencemap.obj
// Layout: { u32 m_count(0x00); u32 m_unknown(0x04); u32 m_data(0x08); u32 m_pad(0x0C) }
// ============================================================================
class ObjectList {
public:
    ObjectList(void);

    void AddObject(cXObject* obj);
    void RemoveObject(cXObject* obj);
    void RemoveAll(void);

private:
    u32 m_count;    // 0x00
    u32 m_capacity; // 0x04
    u32 m_pad08;    // 0x08 - not zeroed by constructor
    u32 m_data;     // 0x0C - pointer to linked list node
};

// ============================================================================
// InfluenceMap - Grid-based influence/heat map for objects
// From: influencemap.obj
// ============================================================================
class InfluenceMap {
public:
    InfluenceMap(int width, int height);
    ~InfluenceMap();

    void RemoveAll(void);
    void CalculateAffectedArea(cXObject* obj, ITreeTableEntry* entry, FTileRect& rect);
    void AddObjectToMap(cXObject* obj);
    BOOL ValidateMissing(cXObject* obj);
    void AddObjectEntry(cXObject* obj, ITreeTableEntry* entry);
    void RemoveObjectFromMap(cXObject* obj);
    void RemoveObjectEntry(cXObject* obj, ITreeTableEntry* entry);
    ObjectList* GetObjectList(int x, int y);
    void Validate(void);
};

#endif // INFLUENCEMAP_H
