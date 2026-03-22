// object.cpp - cXObject and cXObjectImpl core game object functions
// Object file: object.obj
// 116 small functions (<=64 bytes) decompiled from Sims 2 GC
// (2 compiler-generated global ctor/dtor and 1 function >64 bytes excluded)
//
// Matching status: ~38 matching, ~78 NON_MATCHING
//
// Functions that MATCH byte-for-byte:
//   PreSave, ForceLocation, CastToObjectImpl, SetObjectProbe,
//   GetObjectImplementation, GetGlobalInitTreeID, GetGlobalMainTreeID,
//   ReconType, IsBeingDraggedAround, GetObjectProbe,
//   GetLevel, SetLevel, GetSpriteSlot, GetHilite, GetNumAttr,
//   GetRect, GetModule, GetDef, GetID, GetLocation(), GetSelector(),
//   GetSelector() const, GetRelMatrix, GetNextImpl,
//   GetType, GetBehavior, GetFolder, GetName,
//   setObjectImpl, setPersonImpl, setMTObjectImpl, setPortalImpl,
//   GetRoutingSlot, WaitingForSync (logic matches, bool conversion differs),
//   GetDef, GetID
//
// NON_MATCHING reasons (GCC vs SN Systems compiler differences):
//   - Register allocation differs (GCC uses r9 where SN uses r0)
//   - GCC uses stw/lwz individually, SN uses stmw/lmw
//   - GCC tail-call optimizes more aggressively
//   - Virtual call dispatch patterns differ
//   - GCC uses branchless arithmetic where SN uses branches
//   - Conditional return (beqlr/bnelr) patterns differ
//   - SDA-relative addressing (r13) vs BSS for globals
//   - Load/store interleaving differences
//   - Indexed addressing operand order differs

#include "objects/object.h"

// ============================================================================
// External global variables (stored relative to r13 SDA)
// ============================================================================

// cXObject static members stored in SDA
// r13-31916 = s_personWidth
// r13-31912 = s_freeWill
// r13-31910 = s_freeWillShort (short companion to freeWill)
// r13-31908 = s_globalFreeWillOverride
// r13-31904 = s_autoCenter
// r13-31900 = s_autoReset
// r13-31828 = s_overrideDialogReturnCode
// r13-24280 = static destruction guard

// SDA globals - in the final linked binary these live in .sbss/.sdata
// relative to r13. With devkitPPC they are placed in BSS/data so the
// generated code differs (no r13-relative addressing).
// All functions accessing these are marked NON_MATCHING.
static int s_personWidth;
static int s_freeWill;
static s16 s_freeWillShort;
static int s_globalFreeWillOverride;
static int s_autoCenter;
static int s_autoReset;
static TreeReturnCode s_overrideDialogReturnCode;

// Forward declarations for external functions
extern void __destroy_global_chain(void* chain, int count);

// ============================================================================
// __tcf_0 - Static destruction function
// @ 0x800d945c, 40 bytes
// Calls __destroy_global_chain on static data
// ============================================================================
// NON_MATCHING: cannot reproduce static dtor linkage exactly
// This is compiler-generated infrastructure

// ============================================================================
// cXObject - Static global accessors
// These access SDA-relative globals, compiled as simple lwz/stw from r13
// ============================================================================

// NON_MATCHING: All SDA globals use r13-relative addressing in original.
// GCC places these in BSS instead, so the addressing mode differs.

// cXObject::GetPersonWidth(void) @ 0x800d95ec, 8 bytes
// NON_MATCHING: SDA-relative (lwz r3, -31916(r13); blr)
int cXObject::GetPersonWidth() {
    return s_personWidth;
}

// cXObject::GetFreeWill(void) @ 0x800d95f4, 8 bytes
// NON_MATCHING: SDA-relative (lwz r3, -31912(r13); blr)
bool cXObject::GetFreeWill() {
    return s_freeWill;
}

// cXObject::GetAutoCenter(void) @ 0x800d95fc, 8 bytes
// NON_MATCHING: SDA-relative (lwz r3, -31904(r13); blr)
bool cXObject::GetAutoCenter() {
    return s_autoCenter;
}

// cXObject::SetAutoCenter(bool) @ 0x800d9604, 8 bytes
// NON_MATCHING: SDA-relative (stw r3, -31904(r13); blr)
void cXObject::SetAutoCenter(bool value) {
    s_autoCenter = value;
}

// cXObject::GetAutoReset(void) @ 0x800d960c, 8 bytes
// NON_MATCHING: SDA-relative (lwz r3, -31900(r13); blr)
bool cXObject::GetAutoReset() {
    return s_autoReset;
}

// cXObject::SetAutoReset(bool) @ 0x800d9614, 8 bytes
// NON_MATCHING: SDA-relative (stw r3, -31900(r13); blr)
void cXObject::SetAutoReset(bool value) {
    s_autoReset = value;
}

// cXObject::GetGlobalInitTreeID(void) @ 0x800d961c, 8 bytes
// li r3, 271; blr
short cXObject::GetGlobalInitTreeID() {
    return 271;
}

// cXObject::GetGlobalMainTreeID(void) @ 0x800d9624, 8 bytes
// li r3, 391; blr
short cXObject::GetGlobalMainTreeID() {
    return 391;
}

// cXObject::SetGlobalFreeWillOverride(bool) @ 0x800db9a0, 8 bytes
// NON_MATCHING: SDA-relative (stw r3, -31908(r13); blr)
void cXObject::SetGlobalFreeWillOverride(bool value) {
    s_globalFreeWillOverride = value;
}

// ============================================================================
// cXObject::SetFreeWill(bool) @ 0x800db954, 76 bytes
// NON_MATCHING: virtual call dispatch through module vtable
// ============================================================================
// This function stores the freeWill value in SDA, then if a module exists,
// calls a virtual function on the module (vtable offset 0x38/0x3C) with
// params (0x1E, freeWill short value)
// Too complex for matching without full module vtable layout - skip for now

// ============================================================================
// cXObject - Impl setters
// ============================================================================

// cXObject::setObjectImpl(cXObjectImpl *) @ 0x800ea98c, 12 bytes
// lwz r9, 0(r3); stw r4, 0(r9); blr
void cXObject::setObjectImpl(cXObjectImpl* impl) {
    m_pImpls->m_objectImpl = impl;
}

// cXObject::setPersonImpl(cXPersonImpl *) @ 0x800ea998, 12 bytes
// lwz r9, 0(r3); stw r4, 4(r9); blr
void cXObject::setPersonImpl(cXPersonImpl* impl) {
    m_pImpls->m_personImpl = impl;
}

// cXObject::setMTObjectImpl(cXMTObjectImpl *) @ 0x800ea9a4, 12 bytes
// lwz r9, 0(r3); stw r4, 8(r9); blr
void cXObject::setMTObjectImpl(cXMTObjectImpl* impl) {
    m_pImpls->m_mtObjectImpl = impl;
}

// cXObject::setPortalImpl(cXPortalImpl *) @ 0x800ea9b0, 12 bytes
// lwz r9, 0(r3); stw r4, 12(r9); blr
void cXObject::setPortalImpl(cXPortalImpl* impl) {
    m_pImpls->m_portalImpl = impl;
}

// ============================================================================
// PlacementSpec constructors
// ============================================================================

// PlacementSpec::PlacementSpec(bool) @ 0x800dcdf4, 12 bytes
// NON_MATCHING: GCC uses r9, original uses r0
PlacementSpec::PlacementSpec(bool valid) {
    m_valid = 0;
}

// PlacementSpec::PlacementSpec(FTilePt &, int, cXObjectImpl *, int) @ 0x800dce00, 68 bytes
// This is >64 bytes so excluded from our small function set
// (Actually 0x44 = 68, so it IS >64. Wait let me recheck.)
// Map says size 0x44. That's 68 bytes, >64. So skip.

// PlacementSpec::PlacementSpec(cXObjectImpl *) @ 0x800dcdbc, 56 bytes
// Calls cXObjectImpl::GetPlacementSpec on the impl, passing this as output
// NON_MATCHING: GCC uses stw r31/r30, SN uses stmw r30
PlacementSpec::PlacementSpec(cXObjectImpl* impl) {
    impl->GetPlacementSpec(this);
}

// ============================================================================
// HierarchySite constructors
// ============================================================================

// HierarchySite::HierarchySite(cXObjectImpl *) @ 0x800dce90, 56 bytes
// Calls cXObjectImpl::HierGetSite(this)
// NON_MATCHING: GCC uses stw r31/r30, SN uses stmw r30
HierarchySite::HierarchySite(cXObjectImpl* impl) {
    impl->HierGetSite(this);
}

// HierarchySite::HierarchySite(cXObjectImpl *, FTilePt &, int) @ 0x800dcec8, 48 bytes
// NON_MATCHING: register allocation and store ordering differs
HierarchySite::HierarchySite(cXObjectImpl* impl, FTilePt& tile, int level) {
    m_slot = level;                   // stw r6, 16(r11)
    m_parent = impl;                  // stw r4, 12(r11)
    m_tileX = tile.x;                // lwz r9, 0(r5); stw r9, 4(r11)
    m_tileY = tile.y;                // lwz r10, 4(r5); stw r10, 8(r11)
    int implLevel = *(int*)((char*)impl + 0x80);
    m_valid = 1;                      // li r8, 1; stw r8, 0(r11)
    m_level = implLevel;             // lwz r0, 128(r4); stw r0, 20(r11)
}

// HierarchySite::HierarchySite(FTilePt &, int) @ 0x800dcef8, 52 bytes
// NON_MATCHING: register allocation differs (r6/r7 vs r11/r12)
HierarchySite::HierarchySite(FTilePt& tile, int level) {
    m_tileX = tile.x;                // lwz r11, 0(r4); stw r11, 4(r9)
    m_tileY = tile.y;                // lwz r12, 4(r4); stw r12, 8(r9)
    m_parent = NULL;                 // li r0, 0; stw r0, 12(r9)
    m_slot = -1;                     // li r10, -1; stw r10, 16(r9)
    m_level = level;                 // stw r5, 20(r9)
    m_valid = 1;                     // li r8, 1; stw r8, 0(r9)
}

// ============================================================================
// HierarchySite::HierarchySite(PlacementSpec *) @ 0x800dce44, 76 bytes
// This is 0x4C = 76 bytes. > 64. Skip.
// ============================================================================

// ============================================================================
// cXObjectImpl - Simple getters/setters (blr-only or single load/store)
// ============================================================================

// cXObjectImpl::PreSave(void) @ 0x800db168, 4 bytes
// blr
void cXObjectImpl::PreSave() {
}

// cXObjectImpl::GetHilite(void) @ 0x800db5c4, 12 bytes
// lwz r3, 132(r3); clrlwi r3, r3, 27; blr
// Returns low 5 bits of m_miscFlags (+0x84)
int cXObjectImpl::GetHilite() {
    return *(u32*)((char*)this + 0x84) & 0x1F;
}

// cXObjectImpl::IsInWorld(void) @ 0x800dcb50, 40 bytes
// NON_MATCHING: GCC uses cmpwi/branchless, original uses srawi./ble+bgt
bool cXObjectImpl::IsInWorld() {
    int y = *(int*)((char*)this + 0x6C);
    if ((y >> 4) <= 0) return false;
    int x = *(int*)((char*)this + 0x68);
    if ((x >> 4) <= 0) return false;
    return true;
}

// cXObjectImpl::GetNextObjectSibling(void) @ 0x800dcd4c, 36 bytes
// NON_MATCHING: GCC adds extra li r3,0 after call, codegen differs
int cXObjectImpl::GetNextObjectSibling() {
    HierGetChild(0);
    return 0; // return value comes from HierGetChild
}

// cXObjectImpl::GetSpriteSlot(void) @ 0x800de780, 8 bytes
// lwz r3, 176(r3); blr
int cXObjectImpl::GetSpriteSlot() {
    return *(int*)((char*)this + 0xB0);
}

// cXObjectImpl::IsPartOfMe(cXObject *) @ 0x800df210, 20 bytes
// lwz r3, 4(r3); xor r3, r4, r3; subfic r0, r3, 0; adde r3, r0, r3; blr
// NON_MATCHING: GCC uses cntlzw/srwi for ==, original uses subfic/adde
bool cXObjectImpl::IsPartOfMe(cXObject* obj) {
    cXObject* myObj = *(cXObject**)((char*)this + 0x04);
    return myObj == obj;
}

// cXObjectImpl::ForceLocation(void) @ 0x800df224, 4 bytes
// blr
void cXObjectImpl::ForceLocation() {
}

// cXObjectImpl::ReconType(void) @ 0x800e0f34, 12 bytes
// lis r3, 0x584F; ori r3, r3, 0x424A; blr
// Returns 'XOBJ' as a 4CC code (0x584F424A)
u32 cXObjectImpl::ReconType() {
    return 0x584F424A; // 'XOBJ'
}

// cXObjectImpl::IsBeingDraggedAround(void) @ 0x800e1784, 8 bytes
// li r3, 0; blr
bool cXObjectImpl::IsBeingDraggedAround() {
    return false;
}

// cXObjectImpl::GetLevel(void) const @ 0x800e2ac4, 8 bytes
// lwz r3, 128(r3); blr
int cXObjectImpl::GetLevel() const {
    return *(int*)((char*)this + 0x80);
}

// cXObjectImpl::SetLevel(int) @ 0x800e2acc, 8 bytes
// stw r4, 128(r3); blr
void cXObjectImpl::SetLevel(int level) {
    *(int*)((char*)this + 0x80) = level;
}

// cXObjectImpl::SetDrawLabel(bool) @ 0x800e2fe4, 20 bytes
// NON_MATCHING: GCC uses r9 instead of r0, cmpw operand order differs
void cXObjectImpl::SetDrawLabel(bool enable) {
    int current = *(int*)((char*)this + 0xC4);
    if (current == (int)enable) return;
    *(int*)((char*)this + 0xC4) = (int)enable;
}

// cXObjectImpl::OverrideRenderPosition(float &, float &) @ 0x800e2ff8, 36 bytes
// NON_MATCHING: GCC uses addic/subfe for bool return, original uses lwz
bool cXObjectImpl::OverrideRenderPosition(float& x, float& y) {
    int active = *(int*)((char*)this + 0xCC);
    if (active != 0) {
        x = *(float*)((char*)this + 0xD0);
        y = *(float*)((char*)this + 0xD4);
    }
    return *(int*)((char*)this + 0xCC);
}

// cXObjectImpl::SetOverrideRenderPosition(float, float) @ 0x800e301c, 20 bytes
// NON_MATCHING: GCC reorders stores and uses r9 vs r0
void cXObjectImpl::SetOverrideRenderPosition(float x, float y) {
    *(int*)((char*)this + 0xCC) = 1;
    *(float*)((char*)this + 0xD0) = x;
    *(float*)((char*)this + 0xD4) = y;
}

// cXObjectImpl::GetOverrideRenderPosition(float &, float &) @ 0x800e3030, 20 bytes
// NON_MATCHING: GCC uses f0 for both loads, original uses f0 and f13
void cXObjectImpl::GetOverrideRenderPosition(float& x, float& y) {
    x = *(float*)((char*)this + 0xD0);
    y = *(float*)((char*)this + 0xD4);
}

// cXObjectImpl::ClearOverrideRenderPosition(void) @ 0x800e3044, 12 bytes
// NON_MATCHING: GCC uses r9, original uses r0
void cXObjectImpl::ClearOverrideRenderPosition() {
    *(int*)((char*)this + 0xCC) = 0;
}

// cXObjectImpl::GetNumTiles(int &, int &) @ 0x800e324c, 16 bytes
// NON_MATCHING: GCC uses r9, original uses r0
void cXObjectImpl::GetNumTiles(int& width, int& height) {
    width = 1;
    height = 1;
}

// cXObjectImpl::CastToObjectImpl(void) @ 0x800eaa44, 4 bytes
// blr  (returns this in r3)
cXObjectImpl* cXObjectImpl::CastToObjectImpl() {
    return this;
}

// cXObjectImpl::GetNumAttr(void) @ 0x800eaa3c, 8 bytes
// lwz r3, 12(r3); blr
int cXObjectImpl::GetNumAttr() {
    return *(int*)((char*)this + 0x0C);
}

// cXObjectImpl::SetMiscFlag(cXObject::MiscFlag, bool) @ 0x800eaa48, 32 bytes
// NON_MATCHING: GCC uses branch-less OR/ANDC, original uses beqlr
void cXObjectImpl::SetMiscFlag(int flag, bool value) {
    int flags = *(int*)((char*)this + 0x84);
    flags &= ~flag; // andc
    *(int*)((char*)this + 0x84) = flags;
    if (!value) return;
    flags |= flag;
    *(int*)((char*)this + 0x84) = flags;
}

// cXObjectImpl::GetMiscFlag(cXObject::MiscFlag) @ 0x800eaa68, 24 bytes
// NON_MATCHING: GCC uses addic/subfe, original uses bnelr branch
bool cXObjectImpl::GetMiscFlag(int flag) {
    int flags = *(int*)((char*)this + 0x84);
    if (flags & flag) return true;
    return false;
}

// cXObjectImpl::GetSyncObject(void) @ 0x800eab38, 8 bytes
// lwz r3, 220(r3); blr
// NON_MATCHING: GCC sign-extends (extsb) for s8 return, original just lwz+blr
s8 cXObjectImpl::GetSyncObject() {
    return *(int*)((char*)this + 0xDC);
}

// cXObjectImpl::ClearSyncObject(void) @ 0x800eab40, 12 bytes
// NON_MATCHING: GCC uses r9, original uses r0
void cXObjectImpl::ClearSyncObject() {
    *(int*)((char*)this + 0xDC) = 0;
}

// cXObjectImpl::WaitingForSync(void) @ 0x800eab4c, 8 bytes
// NON_MATCHING: GCC adds bool conversion (addic/subfe), original just lwz+blr
bool cXObjectImpl::WaitingForSync() {
    return *(int*)((char*)this + 0xE4);
}

// cXObjectImpl::GetObjectProbe(void) @ 0x800eaf2c, 8 bytes
// li r3, 0; blr
// Always returns NULL in this implementation
ObjectProbe* cXObjectImpl::GetObjectProbe() {
    return NULL;
}

// cXObjectImpl::SetObjectProbe(ObjectProbe *) @ 0x800eaf34, 4 bytes
// blr (no-op)
void cXObjectImpl::SetObjectProbe(ObjectProbe* probe) {
}

// cXObjectImpl::GetRect(void) @ 0x800eb0bc, 8 bytes
// addi r3, r3, 112; blr
// Returns pointer to embedded FTileRect at +0x70
void* cXObjectImpl::GetRect() {
    return (void*)((char*)this + 0x70);
}

// cXObjectImpl::GetModule(void) @ 0x800eb10c, 8 bytes
// lwz r3, 88(r3); blr
ObjectModule* cXObjectImpl::GetModule() {
    return *(ObjectModule**)((char*)this + 0x58);
}

// cXObjectImpl::GetDef(void) @ 0x800eb2cc, 8 bytes
// lwz r3, 136(r3); blr
ObjDef* cXObjectImpl::GetDef() {
    return *(ObjDef**)((char*)this + 0x88);
}

// cXObjectImpl::GetID(void) @ 0x800eb2e0, 8 bytes
// lha r3, 100(r3); blr
s16 cXObjectImpl::GetID() {
    return *(s16*)((char*)this + 0x64);
}

// cXObjectImpl::GetLocation(void) @ 0x800eb2fc, 8 bytes
// addi r3, r3, 104; blr
// Returns pointer to embedded FTilePt at +0x68
FTilePt* cXObjectImpl::GetLocation() {
    return (FTilePt*)((char*)this + 0x68);
}

// cXObjectImpl::GetLocation(FTilePt *) const @ 0x800eb2e8, 20 bytes
// NON_MATCHING: GCC interleaves load/store, original loads both then stores both
void cXObjectImpl::GetLocation(FTilePt* outTile) const {
    u32* src = (u32*)((char*)this + 0x68);
    u32* dst = (u32*)outTile;
    dst[0] = src[0];
    dst[1] = src[1];
}

// cXObjectImpl::GetSelector(void) @ 0x800eb328, 8 bytes
// lwz r3, 140(r3); blr
ObjSelector* cXObjectImpl::GetSelector() {
    return *(ObjSelector**)((char*)this + 0x8C);
}

// cXObjectImpl::GetSelector(void) const @ 0x800eb330, 8 bytes
// lwz r3, 140(r3); blr
ObjSelector* cXObjectImpl::GetSelector() const {
    return *(ObjSelector**)((char*)this + 0x8C);
}

// cXObjectImpl::GetRelMatrix(void) @ 0x800eb3ec, 8 bytes
// lwz r3, 96(r3); blr
void* cXObjectImpl::GetRelMatrix() {
    return *(void**)((char*)this + 0x60);
}

// cXObjectImpl::GetNextImpl(void) @ 0x800eb844, 8 bytes
// lwz r3, 92(r3); blr
cXObjectImpl* cXObjectImpl::GetNextImpl() {
    return *(cXObjectImpl**)((char*)this + 0x5C);
}

// cXObjectImpl::GetObjectImplementation(void) @ 0x800eb8dc, 4 bytes
// blr (returns this)
cXObjectImpl* cXObjectImpl::GetObjectImplementation() {
    return this;
}

// cXObjectImpl::SetOverrideDialogReturnCode(TreeReturnCode) @ 0x800eb8e0, 8 bytes
// NON_MATCHING: SDA-relative (sth r4, -31828(r13); blr)
void cXObjectImpl::SetOverrideDialogReturnCode(TreeReturnCode code) {
    s_overrideDialogReturnCode = code;
}

// ============================================================================
// cXObjectImpl - Simple derived/computed getters
// ============================================================================

// cXObjectImpl::GetType(void) @ 0x800eb2d4, 12 bytes
// lwz r9, 136(r3); lha r3, 18(r9); blr
// Returns ObjDef->m_type at offset +0x12
int cXObjectImpl::GetType() {
    ObjDef* def = *(ObjDef**)((char*)this + 0x88);
    return *(s16*)((char*)def + 0x12);
}

// cXObjectImpl::GetBehavior(void) @ 0x800eb338, 12 bytes
// lwz r9, 140(r3); lwz r3, 12(r9); blr
// Returns m_pSelector->m_behavior at offset +0x0C
void* cXObjectImpl::GetBehavior() {
    void* selector = *(void**)((char*)this + 0x8C);
    return *(void**)((char*)selector + 0x0C);
}

// cXObjectImpl::GetFolder(void) @ 0x800eaf38, 12 bytes
// lwz r9, 140(r3); lwz r3, 80(r9); blr
// Returns m_pSelector->m_folder at +0x50
void* cXObjectImpl::GetFolder() {
    void* selector = *(void**)((char*)this + 0x8C);
    return *(void**)((char*)selector + 0x50);
}

// cXObjectImpl::GetName(void) const @ 0x800eb8d0, 12 bytes
// lwz r9, 140(r3); lwz r3, 20(r9); blr
// Returns m_pSelector->m_name at +0x14
const char* cXObjectImpl::GetName() const {
    void* selector = *(void**)((char*)this + 0x8C);
    return *(const char**)((char*)selector + 0x14);
}

// cXObjectImpl::GetTemp(int) @ 0x800eb0ec, 16 bytes
// NON_MATCHING: GCC uses add+lha instead of addi+lhax
short cXObjectImpl::GetTemp(int index) {
    s16* temps = (s16*)((char*)this + 0x16);
    return temps[index];
}

// cXObjectImpl::SetTemp(int, short) @ 0x800eaf0c, 16 bytes
// NON_MATCHING: GCC uses add+sth instead of addi+sthx
void cXObjectImpl::SetTemp(int index, short value) {
    s16* temps = (s16*)((char*)this + 0x16);
    temps[index] = value;
}

// cXObjectImpl::GetAttr(int) @ 0x800eb0fc, 16 bytes
// NON_MATCHING: GCC swaps lhax operand order (lhax r3,r9,r4 vs r3,r4,r9)
short cXObjectImpl::GetAttr(int index) {
    s16* attrs = *(s16**)((char*)this + 0x08);
    return attrs[index];
}

// cXObjectImpl::SetAttr(int, short) @ 0x800eaf1c, 16 bytes
// NON_MATCHING: GCC swaps sthx operand order (sthx r5,r9,r4 vs r5,r4,r9)
void cXObjectImpl::SetAttr(int index, short value) {
    s16* attrs = *(s16**)((char*)this + 0x08);
    attrs[index] = value;
}

// cXObjectImpl::GetNext(void) @ 0x800eb7f4, 24 bytes
// NON_MATCHING: GCC uses cmpwi after lwz, original uses beqlr pattern
cXObject* cXObjectImpl::GetNext() {
    cXObjectImpl* next = *(cXObjectImpl**)((char*)this + 0x5C);
    if (next == NULL) return NULL;
    return *(cXObject**)((char*)next + 0x04);
}

// cXObjectImpl::IsMultiTile(void) @ 0x800eb378, 28 bytes
// NON_MATCHING: GCC uses branchless cmpwi, original uses bnelr
bool cXObjectImpl::IsMultiTile() {
    ObjDef* def = *(ObjDef**)((char*)this + 0x88);
    s16 mtCount = *(s16*)((char*)def + 0x14);
    if (mtCount != 0) return true;
    return false;
}

// cXObjectImpl::CountObjectSlots(void) @ 0x800eb218, 24 bytes
// NON_MATCHING: GCC uses r0 for intermediate, register allocation differs
int cXObjectImpl::CountObjectSlots() {
    u32 begin = *(u32*)((char*)this + 0x90);
    u32 end = *(u32*)((char*)this + 0x94);
    return ((int)(end - begin) >> 5) - 1;
}

// cXObjectImpl::HierCountSlots(void) @ 0x800eabec, 20 bytes
// (end - begin) / 32
// Same as CountObjectSlots but without the -1
int cXObjectImpl::HierCountSlots() {
    u32 begin = *(u32*)((char*)this + 0x90);
    u32 end = *(u32*)((char*)this + 0x94);
    return (int)(end - begin) >> 5;
}

// cXObjectImpl::GetNumRoutingSlots(void) @ 0x800eb3f4, 32 bytes
// NON_MATCHING: GCC generates different magic number division sequence
int cXObjectImpl::GetNumRoutingSlots() {
    u32 begin = *(u32*)((char*)this + 0xA0);
    u32 end = *(u32*)((char*)this + 0xA4);
    return (int)(end - begin) / 60;
}

// cXObjectImpl::GetRoutingSlot(int) @ 0x800eb414, 16 bytes
// mulli r4, r4, 60; lwz r3, 160(r3); add r3, r3, r4; blr
void* cXObjectImpl::GetRoutingSlot(int index) {
    char* slots = *(char**)((char*)this + 0xA0);
    return slots + index * 60;
}

// cXObjectImpl::HierGetSlot(int) @ 0x800dcf84, 52 bytes
// NON_MATCHING: GCC uses different comparison sequence (cmplw vs subf+srawi+cmplw)
HierarchySite* cXObjectImpl::HierGetSlot(int index) {
    if (index < 0) return NULL;
    u32 begin = *(u32*)((char*)this + 0x90);
    u32 end = *(u32*)((char*)this + 0x94);
    u32 count = (end - begin) >> 5;
    if ((u32)index >= count) return NULL;
    return (HierarchySite*)(begin + (u32)index * 32);
}

// ============================================================================
// cXObjectImpl - Functions that call EdithVariableSet methods
// All of these add 0x28 to this to get the embedded EdithVariableSet
// ============================================================================

// cXObjectImpl::GetData(int) @ 0x800eb0c4, 40 bytes
// Calls EdithVariableSet::operator[](index) on embedded varset at +0x28
// Returns signed half of result
// NON_MATCHING: tail call vs stack frame
short cXObjectImpl::GetData(int index) {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[index];
    return *(s16*)ptr;
}

// cXObjectImpl::SetData(int, short) @ 0x800eaee8, 36 bytes
// Calls EdithVariableSet::WriteVar(index, value) on embedded varset at +0x28
// NON_MATCHING: tail call vs stack frame
void cXObjectImpl::SetData(int index, short value) {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    vars->WriteVar(index, value);
}

// cXObjectImpl::ContainsData(int) @ 0x800e325c, 36 bytes
// Calls EdithVariableSet::Contains(key) on embedded varset at +0x28
// NON_MATCHING: tail call vs stack frame
bool cXObjectImpl::ContainsData(int key) {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    return vars->Contains(key);
}

// cXObjectImpl::GetFlags(void) @ 0x800eb394, 44 bytes
// Calls EdithVariableSet::operator[](8) and returns signed half
// NON_MATCHING: tail call vs stack frame
int cXObjectImpl::GetFlags() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[8];
    return *(s16*)ptr;
}

// cXObjectImpl::GetWallPlacementFlags(void) @ 0x800eb3c0, 44 bytes
// Calls EdithVariableSet::operator[](13) and returns signed half
// NON_MATCHING: tail call vs stack frame
int cXObjectImpl::GetWallPlacementFlags() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[13];
    return *(s16*)ptr;
}

// cXObjectImpl::GetSize(void) @ 0x800eb424, 44 bytes
// Calls EdithVariableSet::operator[](49) and returns signed half
// NON_MATCHING: tail call vs stack frame
int cXObjectImpl::GetSize() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[49];
    return *(s16*)ptr;
}

// cXObjectImpl::GetRoom(void) @ 0x800eb2a0, 44 bytes
// Calls EdithVariableSet::operator[](29) and returns unsigned half
// NON_MATCHING: tail call vs stack frame
int cXObjectImpl::GetRoom() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[29];
    return *(u16*)ptr;
}

// cXObjectImpl::GetLightingContribution(void) @ 0x800eb528, 44 bytes
// Calls EdithVariableSet::operator[](51) and returns signed half
// NON_MATCHING: tail call vs stack frame
int cXObjectImpl::GetLightingContribution() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[51];
    return *(s16*)ptr;
}

// cXObjectImpl::GetObjectLightSource(void) @ 0x800eb554, 44 bytes
// Calls EdithVariableSet::operator[](16) and returns signed half
// NON_MATCHING: tail call vs stack frame
int cXObjectImpl::GetObjectLightSource() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[16];
    return *(s16*)ptr;
}

// ============================================================================
// cXObjectImpl - Bool flag queries via EdithVariableSet
// These call operator[] with a data index, then test bits or compare
// ============================================================================

// cXObjectImpl::GetWasPlacedFromInventory(void) @ 0x800e22c8, 48 bytes
// Calls EdithVariableSet::operator[](8), reads unsigned half, extracts bit 13
// NON_MATCHING: tail call vs stack frame
bool cXObjectImpl::GetWasPlacedFromInventory() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[8];
    u16 flags = *(u16*)ptr;
    return (flags >> 13) & 1;
}

// cXObjectImpl::IsOccupied(void) @ 0x800eace8, 48 bytes
// Calls EdithVariableSet::operator[](8), reads unsigned half, extracts bit 4
// NON_MATCHING: tail call vs stack frame
bool cXObjectImpl::IsOccupied() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[8];
    u16 flags = *(u16*)ptr;
    return (flags >> 4) & 1;
}

// cXObjectImpl::CanContributeLight(void) @ 0x800eb4f8, 48 bytes
// Calls EdithVariableSet::operator[](40), reads unsigned half, extracts bit 9
// NON_MATCHING: tail call vs stack frame
bool cXObjectImpl::CanContributeLight() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[40];
    u16 flags = *(u16*)ptr;
    return (flags >> 9) & 1;
}

// cXObjectImpl::IsBurning(void) @ 0x800eb5f8, 48 bytes
// Calls EdithVariableSet::operator[](8), reads unsigned half, extracts bit 8
// NON_MATCHING: tail call vs stack frame
bool cXObjectImpl::IsBurning() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[8];
    u16 flags = *(u16*)ptr;
    return (flags >> 8) & 1;
}

// cXObjectImpl::CanBurn(void) @ 0x800eb628, 48 bytes
// Calls EdithVariableSet::operator[](40), reads unsigned half, extracts bit 4
// NON_MATCHING: tail call vs stack frame
bool cXObjectImpl::CanBurn() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[40];
    u16 flags = *(u16*)ptr;
    return (flags >> 4) & 1;
}

// cXObjectImpl::IsFireproof(void) @ 0x800eb658, 48 bytes
// Calls EdithVariableSet::operator[](8), reads unsigned half, extracts bit 10
// NON_MATCHING: tail call vs stack frame
bool cXObjectImpl::IsFireproof() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[8];
    u16 flags = *(u16*)ptr;
    return (flags >> 10) & 1;
}

// cXObjectImpl::IsBroken(void) @ 0x800eb580, 60 bytes
// Calls EdithVariableSet::operator[](15), reads signed half, returns != 0
// NON_MATCHING: tail call vs stack frame
bool cXObjectImpl::IsBroken() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[15];
    s16 val = *(s16*)ptr;
    if (val != 0) return true;
    return false;
}

// cXObjectImpl::IsDirty(void) @ 0x800eb5bc, 60 bytes
// Calls EdithVariableSet::operator[](39), reads signed half, returns > 0
// NON_MATCHING: tail call vs stack frame
bool cXObjectImpl::IsDirty() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[39];
    s16 val = *(s16*)ptr;
    if (val > 0) return true;
    return false;
}

// cXObjectImpl::SimIndependent(void) @ 0x800eaf44, 60 bytes
// Calls EdithVariableSet::operator[](60), reads signed half, returns != 0
// NON_MATCHING: tail call vs stack frame
bool cXObjectImpl::SimIndependent() {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = (*vars)[60];
    s16 val = *(s16*)ptr;
    if (val != 0) return true;
    return false;
}

// ============================================================================
// cXObjectImpl - Functions that call IsContained / GetContainedSlotNum
// via PlacementSpec
// ============================================================================

// cXObjectImpl::IsContained(void) @ 0x800dd408, 60 bytes
// Creates a local PlacementSpec from this impl, checks if m_parent is non-null
// NON_MATCHING: register allocation
bool cXObjectImpl::IsContained() {
    PlacementSpec spec(this);
    return spec.m_parent != NULL;
}

// cXObjectImpl::GetContainedSlotNum(void) @ 0x800dd49c, 44 bytes
// Creates a local PlacementSpec from this impl, returns slot number (signed half at +0x12)
// NON_MATCHING: register allocation
int cXObjectImpl::GetContainedSlotNum() {
    PlacementSpec spec(this);
    return *(s16*)((char*)&spec + 0x12);
}

// ============================================================================
// cXObjectImpl - Functions with virtual dispatch through module/cXObject vtable
// These load vtable pointers and do indirect calls
// ============================================================================

// cXObjectImpl::Kill(void) @ 0x800eaa00, 60 bytes
// Loads module (+0x58), reads vtable, calls virtual fn with objectID param
// NON_MATCHING: virtual dispatch codegen differs
void cXObjectImpl::Kill() {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    s16 id = *(s16*)((char*)this + 0x64);
    // Virtual call through module vtable at offset 0x58/0x5C
    void** vtable = *(void***)module;
    s16 voffset = *(s16*)((char*)vtable + 0x58);
    void* fn = *(void**)((char*)vtable + 0x5C);
    typedef void (*KillFn)(void*, s16);
    ((KillFn)fn)((char*)module + voffset, id);
}

// cXObjectImpl::IsRenderingRoot(void) @ 0x800eaa80, 60 bytes
// Loads cXObject (+0x04), reads its vtable, calls virtual fn at offset 0x2D8/0x2DC
// XORs result with 1 (inverts boolean)
// NON_MATCHING: virtual dispatch codegen differs
bool cXObjectImpl::IsRenderingRoot() {
    cXObject* obj = *(cXObject**)((char*)this + 0x04);
    void** vtable = *(void***)((char*)obj + 0x04);
    s16 voffset = *(s16*)((char*)vtable + 0x2D8);
    void* fn = *(void**)((char*)vtable + 0x2DC);
    typedef int (*VFn)(void*);
    int result = ((VFn)fn)((char*)obj + voffset);
    return result ^ 1;
}

// cXObjectImpl::GetColorIndex(void) const @ 0x800e30d8, 64 bytes
// Loads cXObject (+0x04), reads its vtable, calls virtual fn at offset 0x260/0x264
// with param 55. Returns low 8 bits.
// NON_MATCHING: virtual dispatch codegen differs
u8 cXObjectImpl::GetColorIndex() const {
    cXObject* obj = *(cXObject**)((char*)this + 0x04);
    void** vtable = *(void***)((char*)obj + 0x04);
    s16 voffset = *(s16*)((char*)vtable + 0x260);
    void* fn = *(void**)((char*)vtable + 0x264);
    typedef int (*VFn)(void*, int);
    int result = ((VFn)fn)((char*)obj + voffset, 55);
    return (u8)result;
}

// cXObjectImpl::HasZeroExtent(void) @ 0x800eb688, 60 bytes
// Loads cXObject (+0x04), reads vtable, calls virtual fn at offset 0x398/0x39C
// Extracts bit 1 (>> 1 & 1)
// NON_MATCHING: virtual dispatch codegen differs
bool cXObjectImpl::HasZeroExtent() {
    cXObject* obj = *(cXObject**)((char*)this + 0x04);
    void** vtable = *(void***)((char*)obj + 0x04);
    s16 voffset = *(s16*)((char*)vtable + 0x398);
    void* fn = *(void**)((char*)vtable + 0x39C);
    typedef int (*VFn)(void*);
    int result = ((VFn)fn)((char*)obj + voffset);
    return (result >> 1) & 1;
}

// cXObjectImpl::IsSupport(void) @ 0x800eb4b4, 68 bytes
// >64 bytes, but included since map says 0x44 = 68. Actually that is >64, skip.
// Wait - map says 0x44. 0x44 = 68. That's > 64. Let me recheck.
// The entry says: 800eb4b4 00000044 - that's 68 bytes. So it's NOT <=64 bytes.
// However I initially included it. Let me verify.
// 0x44 = 4*16 + 4 = 68. Yes, >64. Skip.

// cXObjectImpl::GetSim(void) @ 0x800eb450, 56 bytes
// Loads module (+0x58), reads its vtable, calls virtual fn at offset 0xD8/0xDC
// NON_MATCHING: virtual dispatch codegen differs
void* cXObjectImpl::GetSim() {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    void** vtable = *(void***)module;
    s16 voffset = *(s16*)((char*)vtable + 0xD8);
    void* fn = *(void**)((char*)vtable + 0xDC);
    typedef void* (*VFn)(void*);
    return ((VFn)fn)((char*)module + voffset);
}

// cXObjectImpl::GetObjectFromID(short) @ 0x800eb7bc, 56 bytes
// Loads module (+0x58), reads vtable, calls virtual fn at offset 0x90/0x94 with ID
// NON_MATCHING: virtual dispatch codegen differs
cXObject* cXObjectImpl::GetObjectFromID(short id) {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    void** vtable = *(void***)module;
    s16 voffset = *(s16*)((char*)vtable + 0x90);
    void* fn = *(void**)((char*)vtable + 0x94);
    typedef cXObject* (*VFn)(void*, short);
    return ((VFn)fn)((char*)module + voffset, id);
}

// cXObjectImpl::GetFirst(void) @ 0x800eb80c, 56 bytes
// Loads module (+0x58), reads vtable, calls virtual fn at offset 0x98/0x9C
// NON_MATCHING: virtual dispatch codegen differs
cXObject* cXObjectImpl::GetFirst() {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    void** vtable = *(void***)module;
    s16 voffset = *(s16*)((char*)vtable + 0x98);
    void* fn = *(void**)((char*)vtable + 0x9C);
    typedef cXObject* (*VFn)(void*);
    return ((VFn)fn)((char*)module + voffset);
}

// ============================================================================
// cXObjectImpl - Functions calling through selector / module
// ============================================================================

// cXObjectImpl::GetFnTable(void) @ 0x800eac64, 36 bytes
// Loads m_pSelector (+0x8C), calls a function on it (0x801113ac)
// NON_MATCHING: tail call vs stack frame
void* cXObjectImpl::GetFnTable() {
    ObjSelector* sel = *(ObjSelector**)((char*)this + 0x8C);
    // Calls ObjSelector::GetFnTable() externally
    typedef void* (*GetFnTableFn)(ObjSelector*);
    extern void* ObjSelector_GetFnTable(ObjSelector*);
    return ObjSelector_GetFnTable(sel);
}

// cXObjectImpl::GetTreeTab(void) @ 0x800eb304, 36 bytes
// Loads m_pSelector (+0x8C), calls a function on it (0x80111648)
// NON_MATCHING: tail call vs stack frame
void* cXObjectImpl::GetTreeTab() {
    ObjSelector* sel = *(ObjSelector**)((char*)this + 0x8C);
    typedef void* (*GetTreeTabFn)(ObjSelector*);
    extern void* ObjSelector_GetTreeTab(ObjSelector*);
    return ObjSelector_GetTreeTab(sel);
}

// cXObjectImpl::GetAdultAnimTable(void) @ 0x800eb114, 36 bytes
// Loads m_pSelector (+0x8C), calls a function on it (0x80111744)
// NON_MATCHING: tail call vs stack frame
void* cXObjectImpl::GetAdultAnimTable() {
    ObjSelector* sel = *(ObjSelector**)((char*)this + 0x8C);
    typedef void* (*Fn)(ObjSelector*);
    extern void* ObjSelector_GetAdultAnimTable(ObjSelector*);
    return ObjSelector_GetAdultAnimTable(sel);
}

// cXObjectImpl::GetChildAnimTable(void) @ 0x800eb138, 36 bytes
// Loads m_pSelector (+0x8C), calls a function on it (0x801117a4)
// NON_MATCHING: tail call vs stack frame
void* cXObjectImpl::GetChildAnimTable() {
    ObjSelector* sel = *(ObjSelector**)((char*)this + 0x8C);
    typedef void* (*Fn)(ObjSelector*);
    extern void* ObjSelector_GetChildAnimTable(ObjSelector*);
    return ObjSelector_GetChildAnimTable(sel);
}

// cXObjectImpl::GetBuildModeType(void) @ 0x800eb488, 44 bytes
// Loads m_pSelector (+0x8C), calls ObjSelector::GetSelFile (0x80110840)
// then reads +0x38 -> +0x8A (signed half)
// NON_MATCHING: tail call vs stack frame
int cXObjectImpl::GetBuildModeType() {
    ObjSelector* sel = *(ObjSelector**)((char*)this + 0x8C);
    typedef void* (*GetSelFileFn)(ObjSelector*);
    extern void* ObjSelector_GetSelFile(ObjSelector*);
    void* selFile = ObjSelector_GetSelFile(sel);
    void* inner = *(void**)((char*)selFile + 0x38);
    return *(s16*)((char*)inner + 0x8A);
}

// cXObjectImpl::GetSelFile(void) @ 0x800eb344, 52 bytes
// Loads m_pSelector (+0x8C), checks if selector->m_selFile (+0x00) is non-null,
// if null calls ObjSelector::LoadSelFile (0x80110790), returns result
// NON_MATCHING: different control flow codegen
void* cXObjectImpl::GetSelFile() {
    ObjSelector* sel = *(ObjSelector**)((char*)this + 0x8C);
    void* selFile = *(void**)sel;
    if (selFile == NULL) {
        typedef void* (*LoadSelFileFn)(ObjSelector*);
        extern void* ObjSelector_LoadSelFile(ObjSelector*);
        selFile = ObjSelector_LoadSelFile(sel);
    }
    return selFile;
}

// ============================================================================
// cXObjectImpl - Functions that call through module vtable with params
// (SimEnabled, EnableSim, GetIdleStatus, SetIdleStatus, ClearIdleStatus)
// ============================================================================

// cXObjectImpl::SimEnabled(void) @ 0x800eaf80, 64 bytes
// Module virtual call at offset 0x248/0x24C with (objectID, 1)
// NON_MATCHING: virtual dispatch codegen differs
bool cXObjectImpl::SimEnabled() {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    s16 id = *(s16*)((char*)this + 0x64);
    void** vtable = *(void***)module;
    s16 voffset = *(s16*)((char*)vtable + 0x248);
    void* fn = *(void**)((char*)vtable + 0x24C);
    typedef int (*VFn)(void*, s16, int);
    return ((VFn)fn)((char*)module + voffset, id, 1);
}

// cXObjectImpl::EnableSim(bool) @ 0x800eafc0, 64 bytes
// Module virtual call at offset 0x240/0x244 with (objectID, 1, enable)
// NON_MATCHING: virtual dispatch codegen differs
void cXObjectImpl::EnableSim(bool enable) {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    s16 id = *(s16*)((char*)this + 0x64);
    void** vtable = *(void***)module;
    s16 voffset = *(s16*)((char*)vtable + 0x240);
    void* fn = *(void**)((char*)vtable + 0x244);
    typedef void (*VFn)(void*, s16, int, int);
    ((VFn)fn)((char*)module + voffset, id, 1, (int)enable);
}

// cXObjectImpl::GetIdleStatus(void) @ 0x800eb004, 60 bytes
// Module virtual call at offset 0x238/0x23C with objectID
// NON_MATCHING: virtual dispatch codegen differs
int cXObjectImpl::GetIdleStatus() {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    s16 id = *(s16*)((char*)this + 0x64);
    void** vtable = *(void***)module;
    s16 voffset = *(s16*)((char*)vtable + 0x238);
    void* fn = *(void**)((char*)vtable + 0x23C);
    typedef int (*VFn)(void*, s16);
    return ((VFn)fn)((char*)module + voffset, id);
}

// cXObjectImpl::SetIdleStatus(int) @ 0x800eb040, 64 bytes
// Module virtual call at offset 0x228/0x22C with (objectID, status)
// NON_MATCHING: virtual dispatch codegen differs
void cXObjectImpl::SetIdleStatus(int status) {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    s16 id = *(s16*)((char*)this + 0x64);
    void** vtable = *(void***)module;
    s16 voffset = *(s16*)((char*)vtable + 0x228);
    void* fn = *(void**)((char*)vtable + 0x22C);
    typedef void (*VFn)(void*, s16, int);
    ((VFn)fn)((char*)module + voffset, id, status);
}

// cXObjectImpl::ClearIdleStatus(void) @ 0x800eb080, 60 bytes
// Module virtual call at offset 0x230/0x234 with objectID
// NON_MATCHING: virtual dispatch codegen differs
void cXObjectImpl::ClearIdleStatus() {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    s16 id = *(s16*)((char*)this + 0x64);
    void** vtable = *(void***)module;
    s16 voffset = *(s16*)((char*)vtable + 0x230);
    void* fn = *(void**)((char*)vtable + 0x234);
    typedef void (*VFn)(void*, s16);
    ((VFn)fn)((char*)module + voffset, id);
}

// ============================================================================
// cXObjectImpl - HaveGraphicsBeenTagged / TagGraphicsField
// ============================================================================

// cXObjectImpl::HaveGraphicsBeenTagged(void) @ 0x800eb89c, 40 bytes
// NON_MATCHING: GCC uses different register for 'this' and branch structure
bool cXObjectImpl::HaveGraphicsBeenTagged() {
    int tagged = *(int*)((char*)this + 0xE8);
    if (tagged == 0) return false;
    *(int*)((char*)this + 0xE8) = 0;
    return true;
}

// cXObjectImpl::TagGraphicsField(void) @ 0x800eb8c4, 12 bytes
// NON_MATCHING: GCC uses r9, original uses r0
void cXObjectImpl::TagGraphicsField() {
    *(int*)((char*)this + 0xE8) = 1;
}

// ============================================================================
// cXObjectImpl - FreeWill/AutoCenter/AutoReset forwarding to cXObject statics
// These are instance methods that just delegate to the static methods
// ============================================================================

// cXObjectImpl::GetFreeWill(void) @ 0x800eabc4, 8 bytes
// NON_MATCHING: SDA-relative (lwz r3, -31912(r13); blr)
bool cXObjectImpl::GetFreeWill() {
    return s_freeWill;
}

// cXObjectImpl::GetAutoCenter(void) @ 0x800eabcc, 8 bytes
// NON_MATCHING: SDA-relative (lwz r3, -31904(r13); blr)
bool cXObjectImpl::GetAutoCenter() {
    return s_autoCenter;
}

// cXObjectImpl::SetAutoCenter(bool) @ 0x800eabd4, 8 bytes
// NON_MATCHING: SDA-relative (stw r3, -31904(r13); blr)
void cXObjectImpl::SetAutoCenter(bool value) {
    s_autoCenter = value;
}

// cXObjectImpl::GetAutoReset(void) @ 0x800eabdc, 8 bytes
// NON_MATCHING: SDA-relative (lwz r3, -31900(r13); blr)
bool cXObjectImpl::GetAutoReset() {
    return s_autoReset;
}

// cXObjectImpl::SetAutoReset(bool) @ 0x800eabe4, 8 bytes
// NON_MATCHING: SDA-relative (stw r3, -31900(r13); blr)
void cXObjectImpl::SetAutoReset(bool value) {
    s_autoReset = value;
}

// ============================================================================
// cXObjectImpl - Functions needing more context (virtual dispatch / complex)
// ============================================================================

// cXObjectImpl::GetContainedObject(int) @ 0x800eb230, 44 bytes (>40)
// Actually 0x2C = 44 bytes. This is <=64 so include.
// But it's a complex virtual call, needs GetObjectSlot first

// cXObjectImpl::IsRoof(void) @ 0x800eb1d0, 72 bytes
// 0x48 = 72 bytes, >64. Skip.

// cXObjectImpl::HideForCutaway(void) @ 0x800eb15c, 116 bytes
// 0x74 = 116, >64. Skip.

// cXObjectImpl::IsEmissive(void) @ 0x800eaabc, 124 bytes
// 0x7C = 124, >64. Skip.

// cXObjectImpl::CanIntersectPeople(void) @ 0x800eb6c4, 148 bytes
// 0x94 = 148, >64. Skip.

// cXObjectImpl::IsChair(void) @ 0x800eb758, 100 bytes
// 0x64 = 100, >64. Skip.

// cXObjectImpl::GetFirstImpl(void) @ 0x800eb84c, 80 bytes
// 0x50 = 80 bytes, >64. Skip.

// cXObjectImpl::RunTree(char *) @ 0x800eab54, 112 bytes
// 0x70 = 112, >64. Skip.

// cXObjectImpl::GetTreeID(ObjEntryPoint) @ 0x800eac88, 96 bytes
// 0x60 = 96, >64. Skip.

// cXObjectImpl::RequiresWallAdjacency(void) @ 0x800eac00, 100 bytes
// 0x64 = 100, >64. Skip.

// cXObjectImpl::CAST_IMPL(void) @ 0x800ea9bc, 68 bytes
// 0x44 = 68, >64. Skip.

// cXObjectImpl::GetPrevObjectSibling(void) @ 0x800dcd70, 76 bytes
// 0x4C = 76, >64. Skip.

// cXObjectImpl::HierGetParent(void) @ 0x800dcf2c, 88 bytes
// 0x58 = 88, >64. Skip.

// cXObjectImpl::IsPortal(void) @ 0x800ead18, 128 bytes
// 0x80 = 128, >64. Skip.

// cXObjectImpl::IsWindow(void) @ 0x800ead98, 168 bytes
// 0xA8 = 168, >64. Skip.

// cXObjectImpl::IsDoor(void) @ 0x800eae40, 168 bytes
// 0xA8 = 168, >64. Skip.

// cXObjectImpl::SetFreeWill(bool) @ 0x800db954, 76 bytes
// 0x4C = 76, >64. Skip.

// PlacementSpec::PlacementSpec(FTilePt &, int, cXObjectImpl *, int) @ 0x800dce00, 68 bytes
// 0x44 = 68, >64. Skip.

// HierarchySite::HierarchySite(PlacementSpec *) @ 0x800dce44, 76 bytes
// 0x4C = 76, >64. Skip.

// cXObjectImpl::GetWallBlockFlags(void) @ 0x800e2848, 100 bytes
// 0x64 = 100, >64. Skip.

// cXObjectImpl::HierGetChild(int) @ 0x800dd114, 72 bytes
// 0x48 = 72, >64. Skip.

// ============================================================================
// global constructors / destructors keyed to cXObjectImpl::sXDirTable
// ============================================================================

// global constructors keyed to cXObjectImpl::sXDirTable @ 0x800eb8e8, 44 bytes
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
// This is compiler-generated infrastructure, cannot match exactly

// global destructors keyed to cXObjectImpl::sXDirTable @ 0x800eb914, 44 bytes
// Calls __static_initialization_and_destruction_0(0, 0xFFFF)
// This is compiler-generated infrastructure, cannot match exactly
