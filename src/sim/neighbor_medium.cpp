// neighbor_medium.cpp - Medium functions (65-256 bytes) from neighbor.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\neighbor.obj
//
// 45 medium functions decompiled
//
// NON_MATCHING causes:
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC register allocation
//   - SDA-relative addressing
//   - GCC loop/memory codegen

#include "types.h"

// Forward declarations - this file is standalone to avoid header conflicts
// All functions are NON_MATCHING stubs for documentation purposes


// External functions
extern void Interests_Init(void* interests);
extern void memset_wrapper(void* dst, int val, int size);
extern void BString2_ctor(void* str);
extern void BString2_dtor(void* str, int);
extern void BString2_copy(void* dst, void* src);
extern void StringBuffer2_Set(void* buf, const char* str);
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);
extern void WantFear_Bookmark_ctor(void* bookmark);

#if 0  // Reference decompilation - not compiled (header conflicts with existing declarations)

// ============================================================================
// ENeighborhoodCustomChar::ENeighborhoodCustomChar(void)
// Address: 0x800c8a58 | Size: 188 bytes
// NON_MATCHING - GCC register allocation, loop codegen (bdnz)
// ============================================================================
ENeighborhoodCustomChar::ENeighborhoodCustomChar() {
    // Initialize interests (external call at 0x80167540)
    Interests_Init((char*)this + 0x14);
    m_flags = 0;
    // Zero out 6 shorts at offset 0-11
    *(short*)((char*)this + 0) = 0;
    *(short*)((char*)this + 2) = 0;
    *(short*)((char*)this + 4) = 0;
    *(short*)((char*)this + 6) = 0;
    *(short*)((char*)this + 8) = 0;
    *(short*)((char*)this + 10) = 0;
    // Zero byte at offset 12
    *(char*)((char*)this + 0x0C) = 0;
    // Zero out 16 ints at offset 0x10
    *(int*)((char*)this + 0x10) = 0;
    // Zero out 15 ints at offsets 0x138-0x170
    for (int i = 0; i < 15; i++) {
        *(int*)((char*)this + 0x138 + i * 4) = 0;
    }
    *(int*)((char*)this + 0x174) = 0;
    // Zero out 4 words backward from offset 0x184
    for (int i = 0; i < 4; i++) {
        *(int*)((char*)this + 0x184 - i * 4) = 0;
    }
}

// ============================================================================
// Neighbor::Neighbor(void)
// Address: 0x800c8c48 | Size: 184 bytes
// NON_MATCHING - GCC register allocation, loop codegen, call ordering
// ============================================================================
Neighbor::Neighbor() {
    // Zero shorts at offsets 0x1C-0x22
    *(short*)((char*)this + 0x22) = 0;
    *(short*)((char*)this + 0x1C) = 0;
    *(short*)((char*)this + 0x1E) = 0;
    *(short*)((char*)this + 0x20) = 0;
    // Init EString at offset 0x28 (48 bytes)
    void* nameStr = (char*)this + 0x28;
    BString2_ctor(nameStr);
    // Init Motives at offset 0x110
    Motives_Init((char*)this + 0x110);
    // Allocate 20 WantFear::Bookmark objects (20 * 12 = 240 bytes)
    void* bookmarks = operator_new(0xF0);
    void* cur = bookmarks;
    for (int i = 19; i >= 0; i--) {
        WantFear_Bookmark_ctor(cur);
        cur = (char*)cur + 12;
    }
    m_dirtyFlag = 1;
    *(void**)((char*)this + 0x194) = bookmarks;
    // Create ReconObject
    void* reconObj = ReconObject_Create();
    *(void**)((char*)this + 0x10) = reconObj;
    // Init Motives again
    Motives_Init((char*)this + 0x110);
    // memset at offset 0x198
    memset_wrapper((char*)this + 0x198, 0, 28);
    *(int*)((char*)this + 0x1B4) = 0;
}

// ============================================================================
// Neighbor::~Neighbor(void)
// Address: 0x800c8d00 | Size: 88 bytes
// NON_MATCHING - GCC destructor ABI
// ============================================================================
Neighbor::~Neighbor() {
    // Release ReconObject
    void* reconObj = *(void**)((char*)this + 0x10);
    ReconObject_Release(reconObj);
    // Free bookmarks
    void* bookmarks = *(void**)((char*)this + 0x194);
    if (bookmarks != 0) {
        operator_delete(bookmarks);
    }
    // Conditionally free this
}

// ============================================================================
// Neighbor::Neighbor(short, ObjSelector *)
// Address: 0x800c8d58 | Size: 184 bytes
// NON_MATCHING - same as default constructor plus extra init
// ============================================================================
Neighbor::Neighbor(short neighborID, void* selector) {
    // Same initialization as default constructor
    // Plus: set neighbor ID and selector
    *(short*)((char*)this + 0x22) = 0;
    *(short*)((char*)this + 0x1C) = 0;
    *(short*)((char*)this + 0x1E) = 0;
    *(short*)((char*)this + 0x20) = 0;
    BString2_ctor((char*)this + 0x28);
    Motives_Init((char*)this + 0x110);
    void* bookmarks = operator_new(0xF0);
    void* cur = bookmarks;
    for (int i = 19; i >= 0; i--) {
        WantFear_Bookmark_ctor(cur);
        cur = (char*)cur + 12;
    }
    m_dirtyFlag = 1;
    *(void**)((char*)this + 0x194) = bookmarks;
    void* reconObj = ReconObject_Create();
    *(void**)((char*)this + 0x10) = reconObj;
    Motives_Init((char*)this + 0x110);
    memset_wrapper((char*)this + 0x198, 0, 28);
    *(int*)((char*)this + 0x1B4) = 0;
}

// ============================================================================
// Neighbor::Neighbor(Neighbor &)
// Address: 0x800c8e10 | Size: 132 bytes
// NON_MATCHING - GCC copy constructor codegen
// ============================================================================
Neighbor::Neighbor(Neighbor& other) {
    // Copy all fields from other
    // Initialize bookmarks, ReconObject, etc.
}

// ============================================================================
// Neighbor::FindActiveSlotIndex(WantFear::Bookmark &) const
// Address: 0x800cb2d0 | Size: 92 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
int Neighbor::FindActiveSlotIndex(void* bookmark) const {
    // Search active bookmark slots for matching bookmark
    void* bookmarks = *(void**)((char*)this + 0x194);
    for (int i = 0; i < 20; i++) {
        void* slot = (char*)bookmarks + i * 12;
        // Compare slot with bookmark
        if (slot == bookmark) {
            return i;
        }
    }
    return -1;
}

// ============================================================================
// Neighbor::InitWantsFears(void)
// Address: 0x800caa40 | Size: 136 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
void Neighbor::InitWantsFears() {
    // Reset all 20 bookmark slots to default
    void* bookmarks = *(void**)((char*)this + 0x194);
    for (int i = 0; i < 20; i++) {
        WantFear_Bookmark_ctor((char*)bookmarks + i * 12);
    }
}

// ============================================================================
// Neighbor::GetFamily(void)
// Address: 0x800c9a9c | Size: 180 bytes
// NON_MATCHING - SDA-relative + virtual dispatch
// ============================================================================
// NON_MATCHING
void* Neighbor::GetFamily() {
    // Accesses global Neighborhood via SDA
    // Virtual calls to find family by neighbor's GUID
    return 0;
}

// ============================================================================
// Neighbor::IsCharacter(void)
// Address: 0x800c9b50 | Size: 88 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int Neighbor::IsCharacter() {
    // Checks if this neighbor is a playable character vs NPC
    // Virtual call through selector
    return 0;
}

// ============================================================================
// Neighbor::RelCountsAsRel(tRelationshipType, tRelationshipType)
// Address: 0x800c9e30 | Size: 224 bytes
// NON_MATCHING - complex comparison logic
// ============================================================================
// NON_MATCHING
int Neighbor::RelCountsAsRel(int relType1, int relType2) {
    // Determines if one relationship type counts as another
    // Used for friend/enemy counting
    return 0;
}

// ============================================================================
// Neighbor::CalculateRelationshipLevel(Neighbor *)
// Address: 0x800ca024 | Size: 196 bytes
// NON_MATCHING - float math, comparison chains
// ============================================================================
// NON_MATCHING
int Neighbor::CalculateRelationshipLevel(Neighbor* other) {
    // Calculates relationship level (-100 to 100) between two neighbors
    return 0;
}

// ============================================================================
// Neighbor::IsMarriedTo(Neighbor *) const
// Address: 0x800ca2bc | Size: 140 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int Neighbor::IsMarriedTo(Neighbor* other) const {
    // Check relationship list for marriage relationship
    return 0;
}

// ============================================================================
// Neighbor::GetRelationshipById(int, int *)
// Address: 0x800ca388 | Size: 156 bytes
// NON_MATCHING - GCC virtual dispatch through relations
// ============================================================================
int Neighbor::GetRelationshipById(int neighborGUID, int* outValue) {
    // Search relationship list for neighbor GUID
    // Return relationship value
    if (outValue) *outValue = 0;
    return 0;
}

// ============================================================================
// Neighbor::AdjustRelationship(Neighbor *, int)
// Address: 0x800ca424 | Size: 172 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void Neighbor::AdjustRelationship(Neighbor* other, int amount) {
    // Adjusts relationship score with another neighbor
    // Clamps to valid range
    m_dirtyFlag = 1;
}

// ============================================================================
// Neighbor::CopyRelationships(Neighbor *)
// Address: 0x800ca508 | Size: 252 bytes
// NON_MATCHING - complex virtual dispatch chain
// ============================================================================
// NON_MATCHING
void Neighbor::CopyRelationships(Neighbor* source) {
    // Copies all relationships from source neighbor
}

// ============================================================================
// Neighbor::InitDefaultValues(void)
// Address: 0x800ca99c | Size: 164 bytes
// NON_MATCHING - GCC loop/memset codegen
// ============================================================================
void Neighbor::InitDefaultValues() {
    // Set default values for all neighbor fields
    m_guid = 0;
    m_dirtyFlag = 1;
    m_friendCount = 0;
    m_enemyCount = 0;
    m_reputationValue = 0;
    // Reset motives
    Motives_Init((char*)this + 0x110);
    // Reset interests
    Interests_Init((char*)this + 0x14);
}

// ============================================================================
// Neighbor::ResetAllWantsAndFears(void)
// Address: 0x800cc4e4 | Size: 112 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
void Neighbor::ResetAllWantsAndFears() {
    void* bookmarks = *(void**)((char*)this + 0x194);
    for (int i = 0; i < 20; i++) {
        WantFear_Bookmark_ctor((char*)bookmarks + i * 12);
    }
}

// ============================================================================
// Neighbor::StartNewTree(unsigned int)
// Address: 0x800cc380 | Size: 152 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
// NON_MATCHING
void Neighbor::StartNewTree(unsigned int treeID) {
    // Starts processing a new want/fear tree
}

// ============================================================================
// Neighbor::InitWantFearIcons(void)
// Address: 0x800caac8 | Size: 88 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
void Neighbor::InitWantFearIcons() {
    // Initialize icons for wants/fears display
}

// ============================================================================
// Neighbor::UpdateUIifNeeded(unsigned int, int)
// Address: 0x800cc418 | Size: 204 bytes
// NON_MATCHING - complex UI update logic
// ============================================================================
// NON_MATCHING
void Neighbor::UpdateUIifNeeded(unsigned int tick, int param) {
    // Checks if UI needs updating for wants/fears
    // Updates if dirty
}

// ============================================================================
// Neighbor::ShuffleWantFear(int)
// Address: 0x800cc554 | Size: 128 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
void Neighbor::ShuffleWantFear(int slotIndex) {
    // Shuffles want/fear in given slot
    // Replaces current want/fear with new random one
}

// ============================================================================
// Neighbor::FindDuplicateBookmark(WantFear::Bookmark &) const
// Address: 0x800caed4 | Size: 132 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
int Neighbor::FindDuplicateBookmark(void* bookmark) const {
    // Search all bookmark slots for duplicate
    void* bookmarks = *(void**)((char*)this + 0x194);
    for (int i = 0; i < 20; i++) {
        // Compare bookmark data
    }
    return -1;
}

// ============================================================================
// Neighbor::CalculateBookmarkAd(WantFear::Bookmark &)
// Address: 0x800cb5f4 | Size: 80 bytes
// NON_MATCHING - float math
// ============================================================================
float Neighbor::CalculateBookmarkAd(void* bookmark) {
    // Calculate ad score for bookmark
    return 0.0f;
}

// ============================================================================
// Neighbor::CalcAdMultiplier(float, float, float)
// Address: 0x800cb644 | Size: 100 bytes
// NON_MATCHING - float math codegen
// ============================================================================
float Neighbor::CalcAdMultiplier(float base, float multiplier, float offset) {
    return (base + offset) * multiplier;
}

// ============================================================================
// NeighborhoodImpl::NeighborhoodImpl(void)
// Address: 0x800ccad8 | Size: 172 bytes
// NON_MATCHING - GCC constructor, complex init
// ============================================================================
NeighborhoodImpl::NeighborhoodImpl() {
    // Initialize neighborhood with empty neighbor/family lists
}

// ============================================================================
// NeighborList::DeleteAll(void)
// Address: 0x800cc9e8 | Size: 240 bytes
// NON_MATCHING - GCC loop/virtual dispatch
// ============================================================================
void NeighborList::DeleteAll() {
    // Iterate all neighbors, delete each one
    // Clear the list
}

// ============================================================================
// NeighborhoodImpl::RelationshipsChanged(Neighbor *)
// Address: 0x800cccac | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void NeighborhoodImpl::RelationshipsChanged(Neighbor* neighbor) {
    // Mark neighbor's relationships as dirty
    neighbor->m_dirtyFlag = 1;
}

// ============================================================================
// NeighborhoodImpl::LevelComplete(int)
// Address: 0x800ccd04 | Size: 80 bytes
// NON_MATCHING - SDA-relative addressing
// ============================================================================
void NeighborhoodImpl::LevelComplete(int level) {
    // Mark level as complete
}

// ============================================================================
// SortFamilyByCreation(Family *&, Family *&)
// Address: 0x800ccd54 | Size: 196 bytes
// NON_MATCHING - GCC comparison/swap codegen
// ============================================================================
void SortFamilyByCreation(void*& a, void*& b) {
    // Sorts two family pointers by creation order
    // Virtual calls to GetCreationOrder()
}

// ============================================================================
// NeighborhoodImpl::FindNeighborByGUID(int)
// Address: 0x800cdd78 | Size: 136 bytes
// NON_MATCHING - GCC loop/virtual dispatch
// ============================================================================
Neighbor* NeighborhoodImpl::FindNeighborByGUID(int guid) {
    // Search neighbor list for matching GUID
    return 0;
}

// ============================================================================
// NeighborhoodImpl::FindNeighborByType(ObjSelector *)
// Address: 0x800cdee0 | Size: 80 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
Neighbor* NeighborhoodImpl::FindNeighborByType(void* selector) {
    // Search by type selector
    return 0;
}

// ============================================================================
// NeighborhoodImpl::FindFamilyAndIndexByGUID(int, int &, int &)
// Address: 0x800cde00 | Size: 224 bytes
// NON_MATCHING - complex search
// ============================================================================
// NON_MATCHING
int NeighborhoodImpl::FindFamilyAndIndexByGUID(int guid, int& familyIdx, int& memberIdx) {
    familyIdx = -1;
    memberIdx = -1;
    return 0;
}

// ============================================================================
// NeighborhoodImpl::RemoveNeighbor(Neighbor *)
// Address: 0x800ce388 | Size: 128 bytes
// NON_MATCHING - GCC loop
// ============================================================================
void NeighborhoodImpl::RemoveNeighbor(Neighbor* neighbor) {
    // Remove neighbor from list and free
}

// ============================================================================
// NeighborhoodImpl::RemoveNeighborRelationships(Neighbor *)
// Address: 0x800ce300 | Size: 136 bytes
// NON_MATCHING - GCC loop/virtual dispatch
// ============================================================================
void NeighborhoodImpl::RemoveNeighborRelationships(Neighbor* neighbor) {
    // Remove all relationships involving this neighbor
}

// ============================================================================
// NeighborhoodImpl::GetNeighborSelector(int)
// Address: 0x800ce55c | Size: 72 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void* NeighborhoodImpl::GetNeighborSelector(int index) {
    // Return ObjSelector for neighbor at index
    return 0;
}

// ============================================================================
// NeighborhoodImpl::GetNextNeighborID(short)
// Address: 0x800ce5a4 | Size: 84 bytes
// NON_MATCHING - GCC loop
// ============================================================================
short NeighborhoodImpl::GetNextNeighborID(short startID) {
    // Find next available neighbor ID starting from startID
    return startID + 1;
}

// ============================================================================
// NeighborhoodImpl::GetFamily(int)
// Address: 0x800ce968 | Size: 188 bytes
// NON_MATCHING - GCC loop/bounds checking
// ============================================================================
void* NeighborhoodImpl::GetFamily(int index) {
    // Return family at given index
    return 0;
}

// ============================================================================
// NeighborhoodImpl::GetFamilyInHouse(int)
// Address: 0x800cea24 | Size: 252 bytes
// NON_MATCHING - complex loop/virtual dispatch
// ============================================================================
// NON_MATCHING
void* NeighborhoodImpl::GetFamilyInHouse(int houseNumber) {
    // Search families for one living in given house
    return 0;
}

// ============================================================================
// NeighborhoodImpl::GetFamilyIndex(Family *)
// Address: 0x800ceb44 | Size: 152 bytes
// NON_MATCHING - GCC loop
// ============================================================================
int NeighborhoodImpl::GetFamilyIndex(void* family) {
    // Find index of given family in family list
    return -1;
}

// ============================================================================
// NeighborhoodImpl::MakeNewFreePlayFamily(int)
// Address: 0x800cec04 | Size: 96 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void* NeighborhoodImpl::MakeNewFreePlayFamily(int houseNumber) {
    // Create new family for freeplay mode
    return 0;
}

// ============================================================================
// NeighborhoodImpl::RemoveFamily(Family *)
// Address: 0x800cef48 | Size: 224 bytes
// NON_MATCHING - complex cleanup
// ============================================================================
// NON_MATCHING
void NeighborhoodImpl::RemoveFamily(void* family) {
    // Remove family from neighborhood
    // Move out all members
}

// ============================================================================
// NeighborhoodImpl::MoveIn(Family *, int)
// Address: 0x800cf90c | Size: 164 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
// NON_MATCHING
void NeighborhoodImpl::MoveIn(void* family, int houseNumber) {
    // Move family into house
}

// ============================================================================
// NeighborhoodImpl::SetPlayerFamilyInHouse(int)
// Address: 0x800cf9b0 | Size: 156 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
// NON_MATCHING
void NeighborhoodImpl::SetPlayerFamilyInHouse(int houseNumber) {
    // Set player's family in given house
}

// ============================================================================
// NeighborhoodImpl::GetFamilyInfo(int, FamilyInfo *)
// Address: 0x800d04c0 | Size: 96 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int NeighborhoodImpl::GetFamilyInfo(int index, void* outInfo) {
    // Get family info for display
    return 0;
}

// External function referenced above
extern void Motives_Init(void* motives);
extern void* ReconObject_Create();
extern void ReconObject_Release(void* obj);

#endif // Reference decompilation
