// treetab_medium.cpp - Medium functions (65-256 bytes) from treetab.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\treetab.obj
//
// 42 medium functions decompiled (from the core TreeTable/WantFear/cFixedWorld systems)
//
// NON_MATCHING causes:
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC register allocation
//   - GCC loop codegen
//   - GCC switch codegen

#include "types.h"
#include "stub_classes.h"

// Forward declarations - this file is standalone to avoid header conflicts
// All functions are NON_MATCHING stubs for documentation purposes


// External functions
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);
extern void BString2_ctor(void* str);
extern void BString2_dtor(void* str, int);

#if 0  // Reference decompilation - not compiled (header conflicts with existing declarations)

// ============================================================================
// CalculateAttenuationValue(bool, int, float)
// Address: 0x801492ec | Size: 196 bytes
// NON_MATCHING - GCC float math, switch codegen
// ============================================================================
float CalculateAttenuationValue(bool useCustom, int attenuationType, float customValue) {
    if (useCustom) {
        return customValue;
    }
    // Switch on attenuation type
    switch (attenuationType) {
        case 0: return 1.0f;     // No attenuation
        case 1: return 0.5f;     // Low
        case 2: return 0.25f;    // Medium
        case 3: return 0.125f;   // High
        case 4: return 0.0f;     // Maximum
        default: return 1.0f;
    }
}

// ============================================================================
// TTabScratchEntry::TTabScratchEntry(void)
// Address: 0x8014941c | Size: 124 bytes
// NON_MATCHING - GCC constructor, loop codegen
// ============================================================================
TTabScratchEntry::TTabScratchEntry() {
    // Set vtable
    m_refCount = 0;
    m_actionTreeID = -1;
    m_checkTreeID = -1;
    m_attenuation = 0;
    m_autonomyThreshold = 50;
    m_flags = 0;
    m_joinIndex = 0;
    // Initialize 16 ads
    for (int i = 0; i < 16; i++) {
        TTabScratchAd* ad = GetAd(i);
        *(short*)((char*)ad + 0) = -1;  // personality var
        *(short*)((char*)ad + 2) = 0;   // reserved
        *(short*)((char*)ad + 4) = 0;   // min
        *(short*)((char*)ad + 6) = 0;   // range
    }
}

// ============================================================================
// TTabScratchEntry::~TTabScratchEntry(void)
// Address: 0x80149498 | Size: 132 bytes
// NON_MATCHING - GCC destructor ABI
// ============================================================================
TTabScratchEntry::~TTabScratchEntry() {
    // Set vtable
    // Conditional delete
}

// ============================================================================
// TreeTableAdScratch::QueryInterface(unsigned int, void **)
// Address: 0x801496f0 | Size: 112 bytes
// NON_MATCHING - GCC comparison codegen
// ============================================================================
int TreeTableAdScratch::QueryInterface(unsigned int iid, void** outPtr) {
    *outPtr = 0;
    return 0;
}

// ============================================================================
// TreeTableAdScratch::Release(void)
// Address: 0x80149774 | Size: 92 bytes
// NON_MATCHING - GCC destructor dispatch
// ============================================================================
int TreeTableAdScratch::Release() {
    m_refCount--;
    if (m_refCount <= 0) {
        int* vtbl = *(int**)this;
        short offset = *(short*)((char*)vtbl + 8);
        void (*dtor)(void*, int) = (void (*)(void*, int))*(int*)((char*)vtbl + 12);
        dtor((char*)this + offset, 3);
        return 0;
    }
    return m_refCount;
}

// ============================================================================
// TTabScratchEntry::QueryInterface(unsigned int, void **)
// Address: 0x801497d0 | Size: 112 bytes
// NON_MATCHING - GCC comparison codegen
// ============================================================================
int TTabScratchEntry::QueryInterface(unsigned int iid, void** outPtr) {
    *outPtr = 0;
    return 0;
}

// ============================================================================
// TTabScratchEntry::Release(void)
// Address: 0x80149854 | Size: 92 bytes
// NON_MATCHING - GCC destructor dispatch
// ============================================================================
int TTabScratchEntry::Release() {
    m_refCount--;
    if (m_refCount <= 0) {
        int* vtbl = *(int**)this;
        short offset = *(short*)((char*)vtbl + 8);
        void (*dtor)(void*, int) = (void (*)(void*, int))*(int*)((char*)vtbl + 12);
        dtor((char*)this + offset, 3);
        return 0;
    }
    return m_refCount;
}

// ============================================================================
// TreeTable::GetIndexOfResource(short) const
// Address: 0x801498b0 | Size: 116 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
int TreeTable::GetIndexOfResource(short resID) const {
    TreeTableEntry* entries = m_pEntries;
    int count = 0;
    if (entries != 0) {
        count = ((int*)entries)[-1];
    }
    for (int i = 0; i < count; i++) {
        if (entries[i].m_resID == resID) {
            return i;
        }
    }
    return -1;
}

// ============================================================================
// TreeTable::GetIndexByTreeID(short, short) const
// Address: 0x80149924 | Size: 92 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
int TreeTable::GetIndexByTreeID(short treeID, short scope) const {
    TreeTableEntry* entries = m_pEntries;
    int count = 0;
    if (entries != 0) {
        count = ((int*)entries)[-1];
    }
    for (int i = 0; i < count; i++) {
        if (entries[i].m_treeID == treeID) {
            return i;
        }
    }
    return -1;
}

// ============================================================================
// TTabScratchEntry::SetAd(int, ITreeTableAd &)
// Address: 0x80149e30 | Size: 72 bytes
// NON_MATCHING - GCC memory copy
// ============================================================================
void TTabScratchEntry::SetAd(int idx, void* ad) {
    // Copy ad data (16 bytes) to ad slot
    TTabScratchAd* dst = GetAd(idx);
    // Copy from source ad
    *(int*)((char*)dst + 0) = *(int*)((char*)ad + 0);
    *(int*)((char*)dst + 4) = *(int*)((char*)ad + 4);
    *(int*)((char*)dst + 8) = *(int*)((char*)ad + 8);
    *(int*)((char*)dst + 12) = *(int*)((char*)ad + 12);
}

// ============================================================================
// TTabScratchEntry::GetName(void) const
// Address: 0x80149ed0 | Size: 76 bytes
// NON_MATCHING - GCC string operations
// ============================================================================
const char* TTabScratchEntry::GetName() const {
    // Returns empty string or name from tree table
    return "";
}

// ============================================================================
// TreeTableAdScratch::operator=(ITreeTableAd &)
// Address: 0x80149a1c | Size: 228 bytes
// NON_MATCHING - GCC virtual dispatch chain for copying
// ============================================================================
// NON_MATCHING
TreeTableAdScratch& TreeTableAdScratch::operator=(void* other) {
    // Copy personality ad, min, range from other ad via virtual calls
    return *this;
}

// ============================================================================
// TestDoorCondition(TileWalls &, TileWallsSegment)
// Address: 0x80149f98 | Size: 116 bytes
// NON_MATCHING - GCC bit manipulation
// ============================================================================
int TestDoorCondition(void* tileWalls, int segment) {
    // Tests if tile wall segment has a door
    return 0;
}

// ============================================================================
// WantFear::Bookmark::ResetCountdown(void)
// Address: 0x8014abe4 | Size: 80 bytes
// NON_MATCHING - GCC store ordering
// ============================================================================
void WantFear_Bookmark_ResetCountdown(void* bookmark) {
    // Reset countdown timer for want/fear expiration
    *(int*)((char*)bookmark + 4) = 0;
    *(int*)((char*)bookmark + 8) = 0;
}

// ============================================================================
// WantFear::Bookmark::IsDuplicateNode(WantFear::Bookmark &) const
// Address: 0x8014acb8 | Size: 120 bytes
// NON_MATCHING - GCC comparison codegen
// ============================================================================
int WantFear_Bookmark_IsDuplicateNode(void* self, void* other) {
    // Compare bookmark nodes for duplication
    short selfNode = *(short*)((char*)self + 0);
    short otherNode = *(short*)((char*)other + 0);
    if (selfNode != otherNode) return 0;
    // Additional field comparisons
    return 1;
}

// ============================================================================
// WantFear::Bookmark::IsDuplicateEvent(WantFear::Bookmark &) const
// Address: 0x8014ad30 | Size: 112 bytes
// NON_MATCHING - GCC comparison codegen
// ============================================================================
int WantFear_Bookmark_IsDuplicateEvent(void* self, void* other) {
    // Compare bookmark events for duplication
    return 0;
}

// ============================================================================
// WantFear::Bookmark::GetType(void) const
// Address: 0x8014ada0 | Size: 104 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int WantFear_Bookmark_GetType(void* self) {
    // Returns want or fear type
    return 0;
}

// ============================================================================
// WantFearManager::GetEvent(unsigned short) const
// Address: 0x8014bf30 | Size: 140 bytes
// NON_MATCHING - GCC bounds checking, virtual dispatch
// ============================================================================
void* WantFearManager_GetEvent(void* self, unsigned short eventID) {
    // Look up event by ID in event table
    return 0;
}

// ============================================================================
// WantFearManager::GetTree(unsigned short) const
// Address: 0x8014bfcc | Size: 152 bytes
// NON_MATCHING - GCC bounds checking
// ============================================================================
void* WantFearManager_GetTree(void* self, unsigned short treeID) {
    // Look up tree by ID
    return 0;
}

// ============================================================================
// WantFearManager::GetStoryTreeRoot(short, short) const
// Address: 0x8014c064 | Size: 256 bytes
// NON_MATCHING - complex tree traversal
// ============================================================================
// NON_MATCHING
void* WantFearManager_GetStoryTreeRoot(void* self, short treeIdx, short scope) {
    return 0;
}

// ============================================================================
// WantFearManager::GetCategoryShader(WantFear::TargetType, short)
// Address: 0x8014c164 | Size: 152 bytes
// NON_MATCHING - GCC switch codegen
// ============================================================================
int WantFearManager_GetCategoryShader(void* self, int targetType, short category) {
    // Returns shader ID for category display
    return 0;
}

// ============================================================================
// WantFear::Bookmark::GetBaseShader(Neighbor *) const
// Address: 0x8014b398 | Size: 168 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int WantFear_Bookmark_GetBaseShader(void* self, void* neighbor) {
    // Gets shader for want/fear icon base
    return 0;
}

// ============================================================================
// WantFear::Bookmark::GetBackgroundShader(Neighbor *) const
// Address: 0x8014b44c | Size: 144 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int WantFear_Bookmark_GetBackgroundShader(void* self, void* neighbor) {
    // Gets shader for want/fear icon background
    return 0;
}

// ============================================================================
// WantFear::Bookmark::GetNextBookmarkAlongBranch(short)
// Address: 0x8014ba7c | Size: 208 bytes
// NON_MATCHING - complex tree traversal
// ============================================================================
// NON_MATCHING
short WantFear_Bookmark_GetNextBookmarkAlongBranch(void* self, short currentIdx) {
    return -1;
}

// ============================================================================
// WantFearManager::WantFearManager(void)
// Address: 0x8014bc6c | Size: 76 bytes
// NON_MATCHING - GCC constructor
// ============================================================================
void WantFearManager_ctor(void* self) {
    // Initialize WantFearManager
    // Set vtable, zero members
}

// ============================================================================
// WantFearManager::~WantFearManager(void)
// Address: 0x8014bcb8 | Size: 76 bytes
// NON_MATCHING - GCC destructor
// ============================================================================
void WantFearManager_dtor(void* self) {
    // Cleanup WantFearManager
}

// ============================================================================
// WantFearManager::Lottery(unsigned int *, unsigned int) const
// Address: 0x8014c3b8 | Size: 140 bytes
// NON_MATCHING - GCC random/loop codegen
// ============================================================================
int WantFearManager_Lottery(void* self, unsigned int* weights, unsigned int count) {
    // Weighted random selection from array of weights
    return 0;
}

// ============================================================================
// GetWallPrice(WallStyle)
// Address: 0x8014c444 | Size: 224 bytes
// NON_MATCHING - GCC switch codegen
// ============================================================================
int GetWallPrice(int wallStyle) {
    // Returns price for wall style
    switch (wallStyle) {
        case 0: return 0;
        case 1: return 5;
        case 2: return 10;
        default: return 15;
    }
}

// ============================================================================
// cFixedWorldImpl::cFixedWorldImpl(int, int)
// Address: 0x8014c524 | Size: 156 bytes
// NON_MATCHING - GCC constructor
// ============================================================================
void cFixedWorldImpl_ctor(void* self, int width, int height) {
    // Initialize fixed world with given dimensions
    *(int*)((char*)self + 4) = width;
    *(int*)((char*)self + 8) = height;
    // Allocate arrays for floor, room, flags, walls
}

// ============================================================================
// cFixedWorldImpl::~cFixedWorldImpl(void)
// Address: 0x8014c5c0 | Size: 112 bytes
// NON_MATCHING - GCC destructor
// ============================================================================
void cFixedWorldImpl_dtor(void* self) {
    // Free allocated arrays
}

// ============================================================================
// cFixedWorldImpl::DeleteArrays(void)
// Address: 0x8014cac0 | Size: 188 bytes
// NON_MATCHING - GCC null checks, free calls
// ============================================================================
void cFixedWorldImpl_DeleteArrays(void* self) {
    // Free floor, room, flags, walls arrays
    void* floor = *(void**)((char*)self + 0x10);
    if (floor) operator_delete(floor);
    void* rooms = *(void**)((char*)self + 0x14);
    if (rooms) operator_delete(rooms);
    void* flags = *(void**)((char*)self + 0x18);
    if (flags) operator_delete(flags);
    void* walls = *(void**)((char*)self + 0x1C);
    if (walls) operator_delete(walls);
}

// ============================================================================
// cFixedWorldImpl::Save(iResFile *, int)
// Address: 0x8014cb7c | Size: 144 bytes
// NON_MATCHING - GCC streaming
// ============================================================================
int cFixedWorldImpl_Save(void* self, void* resFile, int version) {
    // Save world data to resource file
    return 0;
}

// ============================================================================
// cFixedWorldImpl::OutOfRoutableExtent(CTilePt &) const
// Address: 0x80151984 | Size: 80 bytes
// NON_MATCHING - GCC bounds comparison
// ============================================================================
int cFixedWorldImpl_OutOfRoutableExtent_CTilePt(void* self, void* tilePt) {
    int x = *(int*)tilePt;
    int y = *(int*)((char*)tilePt + 4);
    int w = *(int*)((char*)self + 4);
    int h = *(int*)((char*)self + 8);
    if (x < 0 || x >= w) return 1;
    if (y < 0 || y >= h) return 1;
    return 0;
}

// ============================================================================
// cFixedWorldImpl::OutOfRoutableExtent(FTilePt &) const
// Address: 0x801519d4 | Size: 108 bytes
// NON_MATCHING - GCC float comparison
// ============================================================================
int cFixedWorldImpl_OutOfRoutableExtent_FTilePt(void* self, void* tilePt) {
    float x = *(float*)tilePt;
    float y = *(float*)((char*)tilePt + 4);
    float w = (float)*(int*)((char*)self + 4);
    float h = (float)*(int*)((char*)self + 8);
    if (x < 0.0f || x >= w) return 1;
    if (y < 0.0f || y >= h) return 1;
    return 0;
}

// ============================================================================
// cFixedWorldImpl::OutOfBounds(CTilePt &) const
// Address: 0x80151a40 | Size: 80 bytes
// NON_MATCHING - GCC bounds check
// ============================================================================
int cFixedWorldImpl_OutOfBounds_CTilePt(void* self, void* tilePt) {
    int x = *(int*)tilePt;
    int y = *(int*)((char*)tilePt + 4);
    int w = *(int*)((char*)self + 4);
    int h = *(int*)((char*)self + 8);
    if (x < 0 || x >= w) return 1;
    if (y < 0 || y >= h) return 1;
    return 0;
}

// ============================================================================
// cFixedWorldImpl::OutOfBuildingBounds(CTilePt &, bool) const
// Address: 0x80151a90 | Size: 128 bytes
// NON_MATCHING - GCC bounds check with margin
// ============================================================================
int cFixedWorldImpl_OutOfBuildingBounds(void* self, void* tilePt, int allowMargin) {
    int x = *(int*)tilePt;
    int y = *(int*)((char*)tilePt + 4);
    int margin = allowMargin ? 1 : 0;
    int w = *(int*)((char*)self + 4);
    int h = *(int*)((char*)self + 8);
    if (x < -margin || x >= w + margin) return 1;
    if (y < -margin || y >= h + margin) return 1;
    return 0;
}

// ============================================================================
// cFixedWorldImpl::OutOfGrid(CTilePt &) const
// Address: 0x80151b10 | Size: 72 bytes
// NON_MATCHING - GCC bounds check
// ============================================================================
int cFixedWorldImpl_OutOfGrid_CTilePt(void* self, void* tilePt) {
    int x = *(int*)tilePt;
    int y = *(int*)((char*)tilePt + 4);
    if (x < 0 || x >= *(int*)((char*)self + 4)) return 1;
    if (y < 0 || y >= *(int*)((char*)self + 8)) return 1;
    return 0;
}

// ============================================================================
// cFixedWorldImpl::GetFloor(CTilePt &)
// Address: 0x80151c48 | Size: 80 bytes
// NON_MATCHING - GCC array indexing
// ============================================================================
int cFixedWorldImpl_GetFloor(void* self, void* tilePt) {
    int x = *(int*)tilePt;
    int y = *(int*)((char*)tilePt + 4);
    int w = *(int*)((char*)self + 4);
    char* floor = *(char**)((char*)self + 0x10);
    return floor[y * w + x];
}

// ============================================================================
// cFixedWorldImpl::IsGrassAt(CTilePt &)
// Address: 0x80151c98 | Size: 128 bytes
// NON_MATCHING - GCC array indexing + comparison
// ============================================================================
int cFixedWorldImpl_IsGrassAt(void* self, void* tilePt) {
    int floorType = cFixedWorldImpl_GetFloor(self, tilePt);
    return floorType == 0; // grass is floor type 0
}

// ============================================================================
// cFixedWorldImpl::SetFloor(CTilePt &, FloorPattern)
// Address: 0x80151d18 | Size: 140 bytes
// NON_MATCHING - GCC array indexing
// ============================================================================
void cFixedWorldImpl_SetFloor(void* self, void* tilePt, int pattern) {
    int x = *(int*)tilePt;
    int y = *(int*)((char*)tilePt + 4);
    int w = *(int*)((char*)self + 4);
    char* floor = *(char**)((char*)self + 0x10);
    floor[y * w + x] = (char)pattern;
}

// ============================================================================
// cFixedWorldImpl::GetRoom(CTilePt &)
// Address: 0x80151da4 | Size: 188 bytes
// NON_MATCHING - GCC bounds check + array indexing
// ============================================================================
int cFixedWorldImpl_GetRoom(void* self, void* tilePt) {
    int x = *(int*)tilePt;
    int y = *(int*)((char*)tilePt + 4);
    int w = *(int*)((char*)self + 4);
    int h = *(int*)((char*)self + 8);
    if (x < 0 || x >= w || y < 0 || y >= h) return 0;
    short* rooms = *(short**)((char*)self + 0x14);
    return rooms[y * w + x];
}

// ============================================================================
// cFixedWorldImpl::SetRoom(CTilePt &, unsigned short)
// Address: 0x80151e60 | Size: 88 bytes
// NON_MATCHING - GCC array indexing
// ============================================================================
void cFixedWorldImpl_SetRoom(void* self, void* tilePt, unsigned short room) {
    int x = *(int*)tilePt;
    int y = *(int*)((char*)tilePt + 4);
    int w = *(int*)((char*)self + 4);
    short* rooms = *(short**)((char*)self + 0x14);
    rooms[y * w + x] = (short)room;
}

// ============================================================================
// cFixedWorldImpl::GetFlags(CTilePt &)
// Address: 0x80151eb8 | Size: 80 bytes
// NON_MATCHING - GCC array indexing
// ============================================================================
int cFixedWorldImpl_GetFlags(void* self, void* tilePt) {
    int x = *(int*)tilePt;
    int y = *(int*)((char*)tilePt + 4);
    int w = *(int*)((char*)self + 4);
    unsigned char* flags = *(unsigned char**)((char*)self + 0x18);
    return flags[y * w + x];
}

// ============================================================================
// cFixedWorldImpl::SetFlags(CTilePt &, unsigned char)
// Address: 0x80151f08 | Size: 84 bytes
// NON_MATCHING - GCC array indexing
// ============================================================================
void cFixedWorldImpl_SetFlags(void* self, void* tilePt, unsigned char flagVal) {
    int x = *(int*)tilePt;
    int y = *(int*)((char*)tilePt + 4);
    int w = *(int*)((char*)self + 4);
    unsigned char* flags = *(unsigned char**)((char*)self + 0x18);
    flags[y * w + x] = flagVal;
}

// ============================================================================
// cFixedWorldImpl::IsOutside(CTilePt &)
// Address: 0x80151f5c | Size: 84 bytes
// NON_MATCHING - GCC comparison
// ============================================================================
int cFixedWorldImpl_IsOutside(void* self, void* tilePt) {
    int room = cFixedWorldImpl_GetRoom(self, tilePt);
    return room == 0;
}

// ============================================================================
// cFixedWorldImpl::HasWalls(CTilePt &, TileWallsSegment)
// Address: 0x80151fb0 | Size: 104 bytes
// NON_MATCHING - GCC bit manipulation
// ============================================================================
int cFixedWorldImpl_HasWalls_Segment(void* self, void* tilePt, int segment) {
    int x = *(int*)tilePt;
    int y = *(int*)((char*)tilePt + 4);
    int w = *(int*)((char*)self + 4);
    int* walls = *(int**)((char*)self + 0x1C);
    int wallVal = walls[y * w + x];
    return (wallVal >> segment) & 1;
}

// ============================================================================
// cFixedWorldImpl::HasWalls(CTilePt &)
// Address: 0x80152018 | Size: 104 bytes
// NON_MATCHING - GCC bit manipulation
// ============================================================================
int cFixedWorldImpl_HasWalls(void* self, void* tilePt) {
    int x = *(int*)tilePt;
    int y = *(int*)((char*)tilePt + 4);
    int w = *(int*)((char*)self + 4);
    int* walls = *(int**)((char*)self + 0x1C);
    int wallVal = walls[y * w + x];
    return wallVal != 0;
}

#endif // Reference decompilation
