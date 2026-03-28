// e_levelman.cpp - Level manager, ERLevel, ENodeList
//
// Source obj files: e_levelman.obj, e_rlevel.obj, e_nodelist.obj

#include "render/e_levelman.h"
#include "types.h"

// External functions
extern EStream& operator<<(EStream& stream, EStorable* obj);
extern EStream& operator>>(EStream& stream, EStorable*& obj);
extern EFile& operator>>(EFile& file, EStorable*& obj);
extern void* EStorable_New(unsigned int size);
extern void EStorable_CreateCopy(EStorable* obj);
extern void EInstance_Destruct(EInstance* inst, int mode);
extern void ERLevel_ctor(ERLevel* level);
extern void ERLevel_Destruct(ERLevel* level, int mode);
extern void ELightGrid_Update(void* grid, void* a, int b, void* c, int d, void* e);
extern void ERLevel_UpdatePerRoomDataImpl(ERLevel* level);
extern void ERLevel_DrawObjectsWithDOF(ERLevel* level, void* rc);
extern void ELightGrid_Init(void* grid);
extern void ERLevel_OutsideLightsInitImpl(void* sun, float val, LevelLightingEntry& entry);
extern void ERLevel_AddInstance(ERLevel* level, EInstance* inst);
extern void ERLevel_RemoveInstanceFromLevel(ERLevel* level, EInstance* inst);
extern void ERLevel_AssignRoom(ERLevel* level, EInstance* inst);
extern void ERLevel_ReassignRoom(ERLevel* level, EInstance* inst);
extern void EResource_LoadLevel(void* res);
extern void EResource_FreeLevel(void* res);
extern void* ERLevel_AllocFromHeap(unsigned int size, int align);
extern void ERLevel_FreeToHeap(void* ptr);
extern void* EHashTable_Find(void* table, unsigned int key, void* out);
extern void* EHashTable_FindNext(void* table, void* iter, void* out);
extern void EHashTable_Insert(void* table, unsigned int key, void* val, int flag);
extern void EHashTable_Remove(void* table, unsigned int key);
extern void EHashTable_SetSize(void* table, int size);
extern unsigned int EChecksum_Compute(char* str);
extern void ERLevel_UpdateRoomsImpl(ERLevel* level, int count);
extern void ERLevel_LoadResource(void* res, void* file, unsigned int a, unsigned int b);

// =============================================================================
// ERLevel - operator<<(EStream&, ERLevel*)
// Address: 0x802312A8, Size: 32
// =============================================================================
EStream& operator<<(EStream& stream, ERLevel* level) {
    return operator<<(stream, (EStorable*)level);
}

// =============================================================================
// ERLevel - operator>>(EStream&, ERLevel*&)
// Address: 0x802312C8, Size: 64
// =============================================================================
EStream& operator>>(EStream& stream, ERLevel*& level) {
    EStorable* tmp;
    operator>>(stream, tmp);
    level = (ERLevel*)tmp;
    return stream;
}

// =============================================================================
// ERLevel - operator>>(EFile&, ERLevel*&)
// Address: 0x80231308, Size: 64
// =============================================================================
EFile& operator>>(EFile& file, ERLevel*& level) {
    EStorable* tmp;
    operator>>(file, tmp);
    level = (ERLevel*)tmp;
    return file;
}

// =============================================================================
// ERLevel::ValidateInstanceInLevel (stub)
// Address: 0x80233364, Size: 4
// =============================================================================
void ERLevel::ValidateInstanceInLevel(EInstance* inst) {
    // blr - empty stub
}

// =============================================================================
// ERLevel::GroupWallInstances (stub)
// Address: 0x802337D0, Size: 4
// =============================================================================
void ERLevel::GroupWallInstances() {
    // blr - empty stub
}

// =============================================================================
// ERLevel::IsInstanceListKindaFull
// Address: 0x802331F8, Size: 24
// Compares instance count against 1663
// NON_MATCHING - mfcr/rlwinm pattern for bool return
// =============================================================================
int ERLevel::IsInstanceListKindaFull() {
    // Uses addis r3,r3,3 pattern => offset 0x3C2B8 from this
    // lwz r0, -15688(r3) => offset 0x3C2B8
    // cmpwi cr7, r0, 0x67F (1663)
    // mfcr/rlwinm to return bool (cr7 less-than bit)
    // NON_MATCHING
    return 0;
}

// =============================================================================
// ERLevel::InsertHouseObject
// Address: 0x802379A0, Size: 20
// =============================================================================
void ERLevel::InsertHouseObject(EOrderTableData* data) {
    // Linked list insert at head
    // data->next = this->m_houseObjectList  (offset 0x3E2D0)
    // this->m_houseObjectList = data
}

// =============================================================================
// ERLevel::GetTypeInfo
// Address: 0x802380F4, Size: 12
// =============================================================================
const ETypeInfo* ERLevel::GetTypeInfo() const {
    return &m_typeInfo;
}

// =============================================================================
// ERLevel::GetTypeName
// Address: 0x80238100, Size: 12
// =============================================================================
const char* ERLevel::GetTypeName() const {
    return m_typeInfo.m_name;
}

// =============================================================================
// ERLevel::GetTypeKey
// Address: 0x8023810C, Size: 12
// =============================================================================
u32 ERLevel::GetTypeKey() const {
    return m_typeInfo.m_key;
}

// =============================================================================
// ERLevel::GetTypeVersion
// Address: 0x80238118, Size: 12
// =============================================================================
u16 ERLevel::GetTypeVersion() const {
    return m_typeInfo.m_version;
}

// =============================================================================
// ERLevel::GetTypeInfoStatic
// Address: 0x80238124, Size: 12
// =============================================================================
const ETypeInfo* ERLevel::GetTypeInfoStatic() {
    return &m_typeInfo;
}

// =============================================================================
// ERLevel::GetReadVersion
// Address: 0x80238130, Size: 12
// =============================================================================
u16 ERLevel::GetReadVersion() {
    return m_typeInfo.m_readVersion;
}

// =============================================================================
// ERLevel::CreateCopy
// Address: 0x80238190, Size: 32
// =============================================================================
EStorable* ERLevel::CreateCopy() const {
    EStorable_CreateCopy((EStorable*)this);
    return (EStorable*)this;
}

// =============================================================================
// ERLevel::operator new(unsigned int, void*)
// Address: 0x802381E0, Size: 8
// =============================================================================
void* ERLevel::operator new(unsigned int size, void* ptr) {
    return ptr;
}

// =============================================================================
// ERLevel::GetSun
// Address: 0x80238214, Size: 12
// Returns pointer at offset 0x3E2F0 from this
// =============================================================================
EILight* ERLevel::GetSun() {
    // addis r3,r3,3; addi r3,r3,-7440 => offset 0x3E2F0 ???
    // Actually: addis r3,r3,3 = r3+0x30000, then addi r3,r3,0xE2F0 = nope
    // 0x3E2F0 = that's the offset for the sun pointer
    return NULL; // NON_MATCHING - need correct struct offset
}

// =============================================================================
// ERLevel::GetSunAmbient
// Address: 0x80238220, Size: 12
// Returns pointer at offset 0x3E3A8 from this
// =============================================================================
EILight* ERLevel::GetSunAmbient() {
    return NULL; // NON_MATCHING
}

// =============================================================================
// ERLevel::SetDayNightLightTable
// Address: 0x8023822C, Size: 12
// Stores pointer at offset 0x3E454 from this
// =============================================================================
void ERLevel::SetDayNightLightTable(LevelLighting* table) {
    // NON_MATCHING - large struct offset
}

// =============================================================================
// ERLevel::SetRainInfoTable
// Address: 0x80238238, Size: 12
// Stores pointer at offset 0x3E458 from this
// =============================================================================
void ERLevel::SetRainInfoTable(levelraininfo* table) {
    // NON_MATCHING - large struct offset
}

// =============================================================================
// ERLevel::SetSunYawOffset
// Address: 0x80238244, Size: 12
// Stores float at offset 0x3E45C from this
// =============================================================================
void ERLevel::SetSunYawOffset(float offset) {
    // NON_MATCHING - large struct offset
}

// =============================================================================
// ERLevel::SetWallFadeState
// Address: 0x80238250, Size: 12
// Stores int at offset 0x3E2D4 from this
// =============================================================================
void ERLevel::SetWallFadeState(EWallUpDownStateType state) {
    // NON_MATCHING - large struct offset
}

// =============================================================================
// ERLevel::WallFadeState
// Address: 0x8023825C, Size: 12
// Loads int from offset 0x3E2D4 from this
// =============================================================================
EWallUpDownStateType ERLevel::WallFadeState() {
    return WALL_STATE_DEFAULT; // NON_MATCHING
}

// =============================================================================
// ERLevel::IsDrawingOrderTable
// Address: 0x80238290, Size: 8
// Static - loads from SDA r13
// =============================================================================
int ERLevel::IsDrawingOrderTable() {
    return 0; // NON_MATCHING - reads from r13 SDA
}

// =============================================================================
// ERLevel::IsInUse
// Address: 0x80238298, Size: 12
// Loads field at offset 0x3A2B0 from this
// =============================================================================
int ERLevel::IsInUse() {
    return 0; // NON_MATCHING - large struct offset
}

// =============================================================================
// ERLevel::GetRoomCount
// Address: 0x802382A4, Size: 12
// Loads field at offset 0x3A2B4 from this
// =============================================================================
int ERLevel::GetRoomCount() {
    return 0; // NON_MATCHING - large struct offset
}

// =============================================================================
// ERLevel::SetRainBlend
// Address: 0x802382E0, Size: 12
// Stores float at offset 0x3E2E8 from this
// =============================================================================
void ERLevel::SetRainBlend(float blend) {
    // NON_MATCHING - large struct offset
}

// =============================================================================
// ERLevel::GetStorableVersion
// Address: 0x802382EC, Size: 12
// Loads field at offset 0x3A198 from this
// =============================================================================
u32 ERLevel::GetStorableVersion() const {
    return 0; // NON_MATCHING - large struct offset
}

// =============================================================================
// ERLevel::ClearWallIndexSaves
// Address: 0x80238334, Size: 20
// Sets two fields to -1
// =============================================================================
void ERLevel::ClearWallIndexSaves() {
    // NON_MATCHING - large struct offset
    // offset 0x3C2C0 = -1
    // offset 0x3C2BC = -1
}

// =============================================================================
// ERLevel::GetNumInstances
// Address: 0x80238348, Size: 12
// =============================================================================
int ERLevel::GetNumInstances() {
    return 0; // NON_MATCHING - large struct offset 0x3C2B8
}

// =============================================================================
// ERLevel::GetInstance
// Address: 0x80238354, Size: 20
// =============================================================================
EInstance* ERLevel::GetInstance(int index) {
    return NULL; // NON_MATCHING - array access at offset 0x3A2B8
}

// =============================================================================
// ERLevel::GetNumVisibleInstances
// Address: 0x80238368, Size: 12
// =============================================================================
int ERLevel::GetNumVisibleInstances() {
    return 0; // NON_MATCHING - large struct offset 0x3E2CC
}

// =============================================================================
// ERLevel::GetVisInstance
// Address: 0x80238374, Size: 20
// =============================================================================
EInstance* ERLevel::GetVisInstance(int index) {
    return NULL; // NON_MATCHING - array access at offset 0x3C2CC
}

// =============================================================================
// ERLevel::SetDrawWallShadowsFunc
// Address: 0x80238388, Size: 12
// =============================================================================
void ERLevel::SetDrawWallShadowsFunc(void (*fn)(TNodeList<EInstance*>&, EVec3&, ELevelDrawData&)) {
    // NON_MATCHING - stores at offset 0x3E2D8
}

// =============================================================================
// ERLevel::Destruct
// Address: 0x80238090, Size: 36
// =============================================================================
void ERLevel::Destruct(ERLevel* level) {
    ERLevel_Destruct(level, 2);
}

// =============================================================================
// Emitter::SetSortPos
// Address: 0x80238954, Size: 32
// =============================================================================

// =============================================================================
// ELevelManager::AllocateAndLoadResource
// Address: 0x8022F944, Size: 36
// Just forwards to ERLevel::LoadResource
// =============================================================================

// =============================================================================
// ELevelManager::AddRef(unsigned int, EFile*, int)
// Address: 0x8022F9D4, Size: 32
// Forwards to resource manager
// =============================================================================

// =============================================================================
// ELevelManager::AddRef(char*, EFile*, int)
// Address: 0x8022F9F4, Size: 32
// Forwards to resource manager
// =============================================================================

// =============================================================================
// ENodeList::GetSize
// Address: 0x802CC900, Size: 52
// Iterates forward list counting nodes
// =============================================================================
int ENodeList::GetSize() const {
    int count = 0;
    ENodeListEntry* node = m_head;
    while (node != NULL) {
        node = node->m_next;
        count++;
    }
    return count;
}

// =============================================================================
// ENodeList::GetSizeRev
// Address: 0x802CC934, Size: 48
// Iterates backward list counting nodes
// =============================================================================
int ENodeList::GetSizeRev() const {
    int count = 0;
    ENodeListEntry* node = m_tail;
    while (node != NULL) {
        node = node->m_prev;
        count++;
    }
    return count;
}

// =============================================================================
// ENodeList::Search
// Address: 0x802CCA7C, Size: 56
// Searches forward list for node with matching key (data field)
// =============================================================================
ENodeListEntry* ENodeList::Search(unsigned int key) const {
    ENodeListEntry* node = m_head;
    while (node != NULL) {
        if ((unsigned int)node->m_data == key) {
            return node;
        }
        node = node->m_next;
    }
    return NULL;
}
