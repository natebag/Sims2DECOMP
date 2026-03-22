// influencemap_large.cpp - InfluenceMap large functions (257-1024 bytes)
// Object file: influencemap.obj
// All NON_MATCHING - GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

extern "C" {
    void* operator_new_wrapper(u32 size);
    void operator_delete_wrapper(void* ptr);
    void* memcpy(void* dst, const void* src, u32 n);
    void* memset(void* dst, int val, u32 n);
}

// ============================================================================
// ObjectList::AddObject(cXObject*)
// Address: 0x80048590
// Size: 0x184 = 388 bytes
// NON_MATCHING - linked list insertion, duplicate check
// ============================================================================
void ObjectList_AddObject(void* self, void* object) {
    char* _this = (char*)self;

    // Check if object already in list
    void* current = *(void**)(_this + 0x04); // m_pHead
    while (current) {
        void* obj = *(void**)((char*)current + 0x00);
        if (obj == object) return; // Already added

        current = *(void**)((char*)current + 0x04); // next
    }

    // Allocate new list node
    void* node = operator_new_wrapper(0x08);
    *(void**)((char*)node + 0x00) = object; // m_pObject
    *(void**)((char*)node + 0x04) = 0;      // m_pNext

    // Add to front of list
    void* oldHead = *(void**)(_this + 0x04);
    *(void**)((char*)node + 0x04) = oldHead;
    *(void**)(_this + 0x04) = node;

    // Increment count
    int count = *(int*)(_this + 0x00);
    *(int*)(_this + 0x00) = count + 1;
}

// ============================================================================
// InfluenceMap::CalculateAffectedArea(cXObject*, ITreeTableEntry*, FTileRect&)
// Address: 0x800489ec
// Size: 0x358 = 856 bytes
// NON_MATCHING - area calculation, tree table interaction radius
// ============================================================================
void InfluenceMap_CalculateAffectedArea(void* self, void* object, void* entry, void* outRect) {
    char* _this = (char*)self;

    // Get object position in world
    // Get object footprint

    // Get interaction radius from tree table entry
    // Factor in attenuation

    // Calculate tile rectangle that covers the influence area
    // Clamp to map bounds

    // Set output rectangle
    // min_x, min_y, max_x, max_y in tile coordinates

    (void)_this;
    (void)object;
    (void)entry;
    (void)outRect;
}

// ============================================================================
// InfluenceMap::AddObjectToMap(cXObject*)
// Address: 0x80048d44
// Size: 0x164 = 356 bytes
// NON_MATCHING - object registration, tile iteration
// ============================================================================
void InfluenceMap_AddObjectToMap(void* self, void* object) {
    char* _this = (char*)self;

    // Get object's tree table
    // For each entry in tree table:
    //   Calculate affected area
    //   AddObjectEntry(object, entry)

    // Mark object as tracked in influence map

    (void)_this;
    (void)object;
}

// ============================================================================
// InfluenceMap::AddObjectEntry(cXObject*, ITreeTableEntry*)
// Address: 0x80048ea8
// Size: 0x1cc = 460 bytes
// NON_MATCHING - tile-by-tile object list update
// ============================================================================
void InfluenceMap_AddObjectEntry(void* self, void* object, void* entry) {
    char* _this = (char*)self;

    // Calculate affected tile area for this entry
    // CalculateAffectedArea(object, entry, rect)

    // Get map dimensions
    int mapWidth = *(int*)(_this + 0x04);
    int mapHeight = *(int*)(_this + 0x08);

    // For each tile in affected area:
    //   Get object list for tile (x, y)
    //   Add object to tile's object list
    //   ObjectList::AddObject

    // Track entry for later removal

    (void)mapWidth;
    (void)mapHeight;
    (void)object;
    (void)entry;
}

// ============================================================================
// InfluenceMap::RemoveObjectFromMap(cXObject*)
// Address: 0x80049074
// Size: 0x158 = 344 bytes
// NON_MATCHING - object removal from all tiles
// ============================================================================
void InfluenceMap_RemoveObjectFromMap(void* self, void* object) {
    char* _this = (char*)self;

    // Get object's tree table
    // For each entry in tree table:
    //   RemoveObjectEntry(object, entry)

    // Remove object from tracking list
    // Clear any cached influence data for this object

    (void)_this;
    (void)object;
}
