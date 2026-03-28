// object_medium.cpp - Medium functions (65-256 bytes) from object.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\object.obj
//
// 60 medium functions decompiled from object.obj
//
// NON_MATCHING causes:
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC register allocation (r0 vs r9)
//   - SDA-relative addressing
//   - GCC constructor/destructor ABI
//   - GCC loop codegen

#include "types.h"
#include "stub_classes.h"

// Forward declarations - this file is standalone to avoid header conflicts
// All functions are NON_MATCHING stubs for documentation purposes


// External functions
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);
extern void BString2_ctor(void* str);
extern void BString2_dtor(void* str, int);
extern void ReconBuffer_StreamInline(void* buf, void* data, int count);

#if 0  // Reference decompilation - not compiled (header conflicts with existing declarations)

// ============================================================================
// cXObjectImpl::GetContainedCount(void)
// Address: 0x800d9b78 | Size: 72 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXObjectImpl::GetContainedCount() {
    // Get number of contained objects
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x280);
    void* thunk = (char*)subObj + offset;
    typedef int (*CountFn)(void*);
    CountFn fn = (CountFn)*(int*)((char*)vtbl + 0x284);
    return fn(thunk);
}

// ============================================================================
// cXObjectImpl::GetContainedObj(int)
// Address: 0x800d9bc0 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
cXObject* cXObjectImpl::GetContainedObj(int index) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x288);
    void* thunk = (char*)subObj + offset;
    typedef cXObject* (*GetFn)(void*, int);
    GetFn fn = (GetFn)*(int*)((char*)vtbl + 0x28C);
    return fn(thunk, index);
}

// ============================================================================
// cXObjectImpl::GetGUID(void)
// Address: 0x800d9c0c | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXObjectImpl::GetGUID() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x290);
    void* thunk = (char*)subObj + offset;
    typedef int (*GUIDFn)(void*);
    GUIDFn fn = (GUIDFn)*(int*)((char*)vtbl + 0x294);
    return fn(thunk);
}

// ============================================================================
// cXObjectImpl::GetDefGUID(void)
// Address: 0x800d9c58 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXObjectImpl::GetDefGUID() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x298);
    void* thunk = (char*)subObj + offset;
    typedef int (*GUIDFn)(void*);
    GUIDFn fn = (GUIDFn)*(int*)((char*)vtbl + 0x29C);
    return fn(thunk);
}

// ============================================================================
// cXObjectImpl::GetLocationObj(void) const
// Address: 0x800d9ca4 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void* cXObjectImpl::GetLocationObj() const {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x2A0);
    void* thunk = (char*)subObj + offset;
    typedef void* (*GetLocFn)(void*);
    GetLocFn fn = (GetLocFn)*(int*)((char*)vtbl + 0x2A4);
    return fn(thunk);
}

// ============================================================================
// cXObjectImpl::GetOwnerObj(void) const
// Address: 0x800d9cf0 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
cXObject* cXObjectImpl::GetOwnerObj() const {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x2A8);
    void* thunk = (char*)subObj + offset;
    typedef cXObject* (*GetOwnerFn)(void*);
    GetOwnerFn fn = (GetOwnerFn)*(int*)((char*)vtbl + 0x2AC);
    return fn(thunk);
}

// ============================================================================
// cXObjectImpl::GetNeighborID(void)
// Address: 0x800d9d3c | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
short cXObjectImpl::GetNeighborID() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x138);
    void* thunk = (char*)subObj + offset;
    typedef short (*GetIDFn)(void*, int);
    GetIDFn fn = (GetIDFn)*(int*)((char*)vtbl + 0x13C);
    return fn(thunk, 31);
}

// ============================================================================
// cXObjectImpl::GetAttr(int)
// Address: 0x800d9d88 | Size: 80 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
short cXObjectImpl::GetAttr(int index) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x138);
    void* thunk = (char*)subObj + offset;
    typedef short (*GetAttrFn)(void*, int);
    GetAttrFn fn = (GetAttrFn)*(int*)((char*)vtbl + 0x13C);
    return fn(thunk, index);
}

// ============================================================================
// cXObjectImpl::SetAttr(int, short)
// Address: 0x800d9dd8 | Size: 80 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXObjectImpl::SetAttr(int index, short value) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x140);
    void* thunk = (char*)subObj + offset;
    typedef void (*SetAttrFn)(void*, int, short);
    SetAttrFn fn = (SetAttrFn)*(int*)((char*)vtbl + 0x144);
    fn(thunk, index, value);
}

// ============================================================================
// cXObjectImpl::GetAttrRef(int)
// Address: 0x800d9e28 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
short* cXObjectImpl::GetAttrRef(int index) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x148);
    void* thunk = (char*)subObj + offset;
    typedef short* (*GetRefFn)(void*, int);
    GetRefFn fn = (GetRefFn)*(int*)((char*)vtbl + 0x14C);
    return fn(thunk, index);
}

// ============================================================================
// cXObjectImpl::IsPersonObj(void) const
// Address: 0x800da110 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXObjectImpl::IsPersonObj() const {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x1B0);
    void* thunk = (char*)subObj + offset;
    typedef int (*IsPersonFn)(void*);
    IsPersonFn fn = (IsPersonFn)*(int*)((char*)vtbl + 0x1B4);
    return fn(thunk);
}

// ============================================================================
// cXObjectImpl::IsPortal(void) const
// Address: 0x800da15c | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXObjectImpl::IsPortal() const {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x1B8);
    void* thunk = (char*)subObj + offset;
    typedef int (*IsPortalFn)(void*);
    IsPortalFn fn = (IsPortalFn)*(int*)((char*)vtbl + 0x1BC);
    return fn(thunk);
}

// ============================================================================
// cXObjectImpl::IsMultiTileObj(void) const
// Address: 0x800da1a8 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXObjectImpl::IsMultiTileObj() const {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x1C0);
    void* thunk = (char*)subObj + offset;
    typedef int (*IsMTFn)(void*);
    IsMTFn fn = (IsMTFn)*(int*)((char*)vtbl + 0x1C4);
    return fn(thunk);
}

// ============================================================================
// cXObjectImpl::FindSlotsByType(int)
// Address: 0x800da8b0 | Size: 104 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void* cXObjectImpl::FindSlotsByType(int type) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x2B0);
    void* thunk = (char*)subObj + offset;
    typedef void* (*FindSlotsFn)(void*, int);
    FindSlotsFn fn = (FindSlotsFn)*(int*)((char*)vtbl + 0x2B4);
    return fn(thunk, type);
}

// ============================================================================
// cXObjectImpl::SetContainer(cXObject *)
// Address: 0x800da4b8 | Size: 80 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXObjectImpl::SetContainer(cXObject* container) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x2C0);
    void* thunk = (char*)subObj + offset;
    typedef void (*SetContFn)(void*, cXObject*);
    SetContFn fn = (SetContFn)*(int*)((char*)vtbl + 0x2C4);
    fn(thunk, container);
}

// ============================================================================
// cXObjectImpl::GetContainer(void)
// Address: 0x800da508 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
cXObject* cXObjectImpl::GetContainer() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x2C8);
    void* thunk = (char*)subObj + offset;
    typedef cXObject* (*GetContFn)(void*);
    GetContFn fn = (GetContFn)*(int*)((char*)vtbl + 0x2CC);
    return fn(thunk);
}

// ============================================================================
// cXObjectImpl::GetObjDataByName(char *)
// Address: 0x800db3c4 | Size: 96 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void* cXObjectImpl::GetObjDataByName(char* name) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x310);
    void* thunk = (char*)subObj + offset;
    typedef void* (*GetDataFn)(void*, char*);
    GetDataFn fn = (GetDataFn)*(int*)((char*)vtbl + 0x314);
    return fn(thunk, name);
}

// ============================================================================
// cXObjectImpl::GetObjDataByID(ObjectDataID &)
// Address: 0x800db424 | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void* cXObjectImpl::GetObjDataByID(void* dataID) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x318);
    void* thunk = (char*)subObj + offset;
    typedef void* (*GetDataFn)(void*, void*);
    GetDataFn fn = (GetDataFn)*(int*)((char*)vtbl + 0x31C);
    return fn(thunk, dataID);
}

// ============================================================================
// cXObjectImpl::GetFloatConst(char *, float)
// Address: 0x800dbb54 | Size: 108 bytes
// NON_MATCHING - GCC virtual dispatch chain
// ============================================================================
float cXObjectImpl::GetFloatConst(char* name, float defaultVal) {
    // Virtual call through selector's float constants
    return defaultVal;
}

// ============================================================================
// cXObjectImpl::DoMyCommand(short, int)
// Address: 0x800dbe28 | Size: 112 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXObjectImpl::DoMyCommand(short cmd, int arg) {
    // Virtual call: MyDoCommand through selector
    return 0;
}

// ============================================================================
// cXObjectImpl::FlagDelete(void)
// Address: 0x800dc3cc | Size: 68 bytes
// NON_MATCHING - GCC bit manipulation
// ============================================================================
void cXObjectImpl::FlagDelete() {
    // Set delete flag in object flags
    int* flags = (int*)((char*)this + 0x84);
    *flags |= 0x100; // FLAG_DELETE
}

// ============================================================================
// cXObjectImpl::IsFlagDelete(void)
// Address: 0x800dc410 | Size: 72 bytes
// NON_MATCHING - GCC bit extraction
// ============================================================================
int cXObjectImpl::IsFlagDelete() {
    int flags = *(int*)((char*)this + 0x84);
    return (flags >> 8) & 1;
}

// ============================================================================
// cXObjectImpl::SetFlag(int, bool)
// Address: 0x800dc458 | Size: 88 bytes
// NON_MATCHING - GCC bit manipulation
// ============================================================================
void cXObjectImpl::SetFlag(int flagBit, bool value) {
    int* flags = (int*)((char*)this + 0x84);
    if (value) {
        *flags |= (1 << flagBit);
    } else {
        *flags &= ~(1 << flagBit);
    }
}

// ============================================================================
// cXObjectImpl::GetFlag(int)
// Address: 0x800dc4b0 | Size: 68 bytes
// NON_MATCHING - GCC bit extraction
// ============================================================================
int cXObjectImpl::GetFlag(int flagBit) {
    int flags = *(int*)((char*)this + 0x84);
    return (flags >> flagBit) & 1;
}

// ============================================================================
// cXObjectImpl::IsInWorld(void)
// Address: 0x800dc514 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXObjectImpl::IsInWorld() {
    return 0;
}

// ============================================================================
// cXObjectImpl::AddContainedObj(cXObject *)
// Address: 0x800dc894 | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXObjectImpl::AddContainedObj(cXObject* obj) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x2D0);
    void* thunk = (char*)subObj + offset;
    typedef void (*AddFn)(void*, cXObject*);
    AddFn fn = (AddFn)*(int*)((char*)vtbl + 0x2D4);
    fn(thunk, obj);
}

// ============================================================================
// cXObjectImpl::RemoveContainedObj(cXObject *)
// Address: 0x800dc8e8 | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXObjectImpl::RemoveContainedObj(cXObject* obj) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x2D8);
    void* thunk = (char*)subObj + offset;
    typedef void (*RemFn)(void*, cXObject*);
    RemFn fn = (RemFn)*(int*)((char*)vtbl + 0x2DC);
    fn(thunk, obj);
}

// ============================================================================
// cXObjectImpl::GetTreeTable(void)
// Address: 0x800dc93c | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void* cXObjectImpl::GetTreeTable() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x2E0);
    void* thunk = (char*)subObj + offset;
    typedef void* (*GetTTFn)(void*);
    GetTTFn fn = (GetTTFn)*(int*)((char*)vtbl + 0x2E4);
    return fn(thunk);
}

// ============================================================================
// cXObjectImpl::GetTreeTableEntry(int)
// Address: 0x800dc988 | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void* cXObjectImpl::GetTreeTableEntry(int index) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x2E8);
    void* thunk = (char*)subObj + offset;
    typedef void* (*GetEntryFn)(void*, int);
    GetEntryFn fn = (GetEntryFn)*(int*)((char*)vtbl + 0x2EC);
    return fn(thunk, index);
}

// ============================================================================
// cXObjectImpl::IsVisible(void)
// Address: 0x800dd7e0 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXObjectImpl::IsVisible() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x300);
    void* thunk = (char*)subObj + offset;
    typedef int (*IsVisFn)(void*);
    IsVisFn fn = (IsVisFn)*(int*)((char*)vtbl + 0x304);
    return fn(thunk);
}

// ============================================================================
// cXObjectImpl::SetVisible(bool)
// Address: 0x800dd82c | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXObjectImpl::SetVisible(bool visible) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x308);
    void* thunk = (char*)subObj + offset;
    typedef void (*SetVisFn)(void*, bool);
    SetVisFn fn = (SetVisFn)*(int*)((char*)vtbl + 0x30C);
    fn(thunk, visible);
}

// ============================================================================
// cXObjectImpl::GetDir(void)
// Address: 0x800dd8b4 | Size: 68 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXObjectImpl::GetDir() {
    return *(int*)((char*)this + 0x5C);
}

// ============================================================================
// cXObjectImpl::Place(FTilePt &, int, cXObject *, int)
// Address: 0x800dd9e4 | Size: 204 bytes
// NON_MATCHING - complex placement logic
// ============================================================================
// NON_MATCHING
void cXObjectImpl::Place(void* tilePt, int dir, cXObject* container, int flags) {
    // Place object at tile position with given direction
}

// ============================================================================
// cXObjectImpl::MoveToRoom(unsigned short)
// Address: 0x800ddb70 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXObjectImpl::MoveToRoom(unsigned short room) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x330);
    void* thunk = (char*)subObj + offset;
    typedef void (*MoveFn)(void*, unsigned short);
    MoveFn fn = (MoveFn)*(int*)((char*)vtbl + 0x334);
    fn(thunk, room);
}

// ============================================================================
// cXObjectImpl::GetRoom(void) const
// Address: 0x800ddbc0 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
unsigned short cXObjectImpl::GetRoom() const {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x338);
    void* thunk = (char*)subObj + offset;
    typedef unsigned short (*GetRoomFn)(void*);
    GetRoomFn fn = (GetRoomFn)*(int*)((char*)vtbl + 0x33C);
    return fn(thunk);
}

// ============================================================================
// cXObjectImpl::EnableClickability(bool)
// Address: 0x800ddfb4 | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXObjectImpl::EnableClickability(bool enable) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x340);
    void* thunk = (char*)subObj + offset;
    typedef void (*EnableFn)(void*, bool);
    EnableFn fn = (EnableFn)*(int*)((char*)vtbl + 0x344);
    fn(thunk, enable);
}

// ============================================================================
// cXObjectImpl::GetCurrentAnimation(void)
// Address: 0x800de580 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXObjectImpl::GetCurrentAnimation() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x350);
    void* thunk = (char*)subObj + offset;
    typedef int (*GetAnimFn)(void*);
    GetAnimFn fn = (GetAnimFn)*(int*)((char*)vtbl + 0x354);
    return fn(thunk);
}

// ============================================================================
// cXObjectImpl::PreloadAnimation(short)
// Address: 0x800de5cc | Size: 80 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXObjectImpl::PreloadAnimation(short animID) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x358);
    void* thunk = (char*)subObj + offset;
    typedef void (*PreloadFn)(void*, short);
    PreloadFn fn = (PreloadFn)*(int*)((char*)vtbl + 0x35C);
    fn(thunk, animID);
}

// ============================================================================
// cXObjectImpl::StartAnim(short)
// Address: 0x800de61c | Size: 80 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXObjectImpl::StartAnim(short animID) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x360);
    void* thunk = (char*)subObj + offset;
    typedef void (*StartFn)(void*, short);
    StartFn fn = (StartFn)*(int*)((char*)vtbl + 0x364);
    fn(thunk, animID);
}

// ============================================================================
// cXObjectImpl::GetShadow(void)
// Address: 0x800dfb38 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void* cXObjectImpl::GetShadow() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x370);
    void* thunk = (char*)subObj + offset;
    typedef void* (*GetShadowFn)(void*);
    GetShadowFn fn = (GetShadowFn)*(int*)((char*)vtbl + 0x374);
    return fn(thunk);
}

// ============================================================================
// cXObject::GetSelectorImpl(void)
// Address: 0x800e0d10 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void* cXObject::GetSelectorImpl() {
    void* impl = *(void**)this;
    int* vtbl = *(int**)impl;
    short offset = *(short*)((char*)vtbl + 0x08);
    void* thunk = (char*)impl + offset;
    typedef void* (*GetSelFn)(void*);
    GetSelFn fn = (GetSelFn)*(int*)((char*)vtbl + 0x0C);
    return fn(thunk);
}

// ============================================================================
// cXObject::DoCommand(short, int)
// Address: 0x800e0e4c | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXObject::DoCommand(short cmd, int arg) {
    // Dispatch command through implementation
    return 0;
}

// ============================================================================
// cXObject::GetOwnerGUID(void)
// Address: 0x800e1084 | Size: 104 bytes
// NON_MATCHING - GCC virtual dispatch chain
// ============================================================================
int cXObject::GetOwnerGUID() {
    // Get owner object's GUID
    cXObject* owner = GetOwnerObj();
    if (owner == 0) return 0;
    return owner->GetGUID();
}

// ============================================================================
// cXObject::GetBehavior(void)
// Address: 0x800e1114 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void* cXObject::GetBehavior() {
    void* impl = *(void**)this;
    int* vtbl = *(int**)((char*)impl + 0x04);
    short offset = *(short*)((char*)vtbl + 0x380);
    void* thunk = (char*)impl + offset;
    typedef void* (*GetBehFn)(void*);
    GetBehFn fn = (GetBehFn)*(int*)((char*)vtbl + 0x384);
    return fn(thunk);
}

// ============================================================================
// cXObject::CastToObject(void)
// Address: 0x800e11a0 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
cXObject* cXObject::CastToObject() {
    return this;
}

// ============================================================================
// cXObjectImpl::AnimateObject(short)
// Address: 0x800de66c | Size: 80 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXObjectImpl::AnimateObject(short animID) {
    // Start animation on object
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x368);
    void* thunk = (char*)subObj + offset;
    typedef void (*AnimFn)(void*, short);
    AnimFn fn = (AnimFn)*(int*)((char*)vtbl + 0x36C);
    fn(thunk, animID);
}

#endif // Reference decompilation
