// iobject.cpp - ISimsObjectModel and derived classes
// Object file: iobject.obj
// 98 small functions (<=64 bytes) decompiled from Sims 2 GC
//
// Matching status: 43 matching, 55 NON_MATCHING (GCC vs SN Systems compiler differences)
// NON_MATCHING reasons:
//   - Register allocation differs (GCC uses r31/r30, SN uses r29/r30)
//   - GCC uses stw/lwz individually, SN uses stmw/lmw
//   - GCC tail-call optimizes more aggressively
//   - GCC uses branchless arithmetic where SN uses branches
//   - GCC inlines small functions that SN did not
//   - GCC unrolls loops that SN kept as simple loops
//   - Virtual destructor codegen differs fundamentally

#include "objects/iobject.h"

// ============================================================================
// External function declarations (defined in other translation units)
// ============================================================================
extern EStream& operator<<(EStream& stream, EStorable* obj);
extern EStream& operator>>(EStream& stream, EStorable*& obj);
extern EFile& operator>>(EFile& file, EStorable*& obj);

// External type info structs (defined in data sections)
extern ETypeInfo sTypeInfo_ISimsObjectModel;
extern ETypeInfo sTypeInfo_ISimsWallObjectModel;
extern ETypeInfo sTypeInfo_ISimsMultiTileObjectModel;
extern ETypeInfo sTypeInfo_ISimsCounterTopObject;
extern ETypeInfo sTypeInfo_IShrubObject;

// External global variables
extern float _isom_minburpscale;

// ============================================================================
// EParticleObj
// ============================================================================

// NON_MATCHING: register allocation + store order differs
// EParticleObj::EParticleObj(void) @ 0x8004c130, 32 bytes
EParticleObj::EParticleObj() {
    m_effectPtrs[0] = 0;
    m_effectPtrs[1] = 0;
    m_count = 1;
    m_effectPtrs[2] = 0;
}

// ============================================================================
// Streaming operators for ISimsObjectModel
// ============================================================================

// NON_MATCHING: GCC tail-calls (b), original uses stack frame (stwu/bl/blr)
// operator<<(EStream &, ISimsObjectModel *) @ 0x8004c460, 32 bytes
EStream& operator<<(EStream& stream, ISimsObjectModel* obj) {
    return operator<<(stream, (EStorable*)obj);
}

// NON_MATCHING: GCC uses stw r31/r30, original uses stmw r29; register numbers differ
// operator>>(EStream &, ISimsObjectModel *&) @ 0x8004c480, 64 bytes
EStream& operator>>(EStream& stream, ISimsObjectModel*& obj) {
    EStorable* tmp;
    operator>>(stream, tmp);
    obj = (ISimsObjectModel*)tmp;
    return stream;
}

// NON_MATCHING: same as above - stw vs stmw, register allocation
// operator>>(EFile &, ISimsObjectModel *&) @ 0x8004c4c0, 64 bytes
EFile& operator>>(EFile& file, ISimsObjectModel*& obj) {
    EStorable* tmp;
    operator>>(file, tmp);
    obj = (ISimsObjectModel*)tmp;
    return file;
}

// ============================================================================
// ISimsObjectModel member functions
// ============================================================================

// NON_MATCHING: instruction reordering (stw before xori in compiled)
// ISimsObjectModel::UpdateBulb(ObjAnimDef *) @ 0x8004dce4, 56 bytes
void ISimsObjectModel::UpdateBulb(ObjAnimDef* animDef) {
    if (animDef == NULL) return;
    u32* pBulb = (u32*)((char*)this + 0x420);
    u32 newModel = *(u32*)((char*)animDef + 0x14);
    if (*pBulb == newModel) return;
    *pBulb = newModel;
    u32 val = newModel ^ 1;
    u32 result = (val == 0) ? 0 : 1;
    u32* pILight = *(u32**)((char*)this + 0x460);
    *(u32*)((char*)pILight + 0x88) = result;
}

// NON_MATCHING: GCC tail-calls (b), original uses stack frame
// ISimsObjectModel::UpdateAnim(ObjAnimDef *) @ 0x8004e538, 36 bytes
void ISimsObjectModel::UpdateAnim(ObjAnimDef* animDef) {
    UpdateAnimTrack(animDef, false);
}

// ISimsObjectModel::SetPosStatic(EVec3 &, float) @ 0x8004eb6c, 4 bytes
void ISimsObjectModel::SetPosStatic(EVec3& pos, float rot) {
}

// ISimsObjectModel::SetOutOfWorld(void) @ 0x8004ed20, 4 bytes
void ISimsObjectModel::SetOutOfWorld() {
}

// NON_MATCHING: GCC uses add+stfs, original uses addi+stfsx
// ISimsObjectModel::StartBurp(int) @ 0x8004ed24, 24 bytes
void ISimsObjectModel::StartBurp(int index) {
    float* burpScale = (float*)((char*)this + 0x3F8);
    burpScale[index] = _isom_minburpscale;
}

// ============================================================================
// Streaming operators for ISimsWallObjectModel
// ============================================================================

// NON_MATCHING: GCC tail-calls, original uses stack frame
// operator<<(EStream &, ISimsWallObjectModel *) @ 0x800510d0, 32 bytes
EStream& operator<<(EStream& stream, ISimsWallObjectModel* obj) {
    return operator<<(stream, (EStorable*)obj);
}

// NON_MATCHING: stw vs stmw, register allocation
// operator>>(EStream &, ISimsWallObjectModel *&) @ 0x800510f0, 64 bytes
EStream& operator>>(EStream& stream, ISimsWallObjectModel*& obj) {
    EStorable* tmp;
    operator>>(stream, tmp);
    obj = (ISimsWallObjectModel*)tmp;
    return stream;
}

// NON_MATCHING: stw vs stmw, register allocation
// operator>>(EFile &, ISimsWallObjectModel *&) @ 0x80051130, 64 bytes
EFile& operator>>(EFile& file, ISimsWallObjectModel*& obj) {
    EStorable* tmp;
    operator>>(file, tmp);
    obj = (ISimsWallObjectModel*)tmp;
    return file;
}

// ISimsWallObjectModel::CreateShadow(void) @ 0x80051218, 4 bytes
void ISimsWallObjectModel::CreateShadow() {
}

// ============================================================================
// Streaming operators for ISimsMultiTileObjectModel
// ============================================================================

// NON_MATCHING: GCC tail-calls, original uses stack frame
// operator<<(EStream &, ISimsMultiTileObjectModel *) @ 0x800519ec, 32 bytes
EStream& operator<<(EStream& stream, ISimsMultiTileObjectModel* obj) {
    return operator<<(stream, (EStorable*)obj);
}

// NON_MATCHING: stw vs stmw, register allocation
// operator>>(EStream &, ISimsMultiTileObjectModel *&) @ 0x80051a0c, 64 bytes
EStream& operator>>(EStream& stream, ISimsMultiTileObjectModel*& obj) {
    EStorable* tmp;
    operator>>(stream, tmp);
    obj = (ISimsMultiTileObjectModel*)tmp;
    return stream;
}

// NON_MATCHING: stw vs stmw, register allocation
// operator>>(EFile &, ISimsMultiTileObjectModel *&) @ 0x80051a4c, 64 bytes
EFile& operator>>(EFile& file, ISimsMultiTileObjectModel*& obj) {
    EStorable* tmp;
    operator>>(file, tmp);
    obj = (ISimsMultiTileObjectModel*)tmp;
    return file;
}

// ============================================================================
// Streaming operators for ISimsCounterTopObject
// ============================================================================

// NON_MATCHING: GCC tail-calls, original uses stack frame
// operator<<(EStream &, ISimsCounterTopObject *) @ 0x8005200c, 32 bytes
EStream& operator<<(EStream& stream, ISimsCounterTopObject* obj) {
    return operator<<(stream, (EStorable*)obj);
}

// NON_MATCHING: stw vs stmw, register allocation
// operator>>(EStream &, ISimsCounterTopObject *&) @ 0x8005202c, 64 bytes
EStream& operator>>(EStream& stream, ISimsCounterTopObject*& obj) {
    EStorable* tmp;
    operator>>(stream, tmp);
    obj = (ISimsCounterTopObject*)tmp;
    return stream;
}

// NON_MATCHING: stw vs stmw, register allocation
// operator>>(EFile &, ISimsCounterTopObject *&) @ 0x8005206c, 64 bytes
EFile& operator>>(EFile& file, ISimsCounterTopObject*& obj) {
    EStorable* tmp;
    operator>>(file, tmp);
    obj = (ISimsCounterTopObject*)tmp;
    return file;
}

// NON_MATCHING: GCC generates virtual call via vtable, original calls directly
// ISimsCounterTopObject::Create(cXObject *, EHouse *) @ 0x80052154, 60 bytes
void ISimsCounterTopObject::Create(cXObject* obj, EHouse* house) {
    *(cXObject**)((char*)this + 0x328) = obj;
    *(EHouse**)((char*)this + 0x3C8) = house;
    SetObjOrient();
    SetInitalObjectState();
}

// ============================================================================
// Streaming operators for IShrubObject
// ============================================================================

// NON_MATCHING: GCC tail-calls, original uses stack frame
// operator<<(EStream &, IShrubObject *) @ 0x80052544, 32 bytes
EStream& operator<<(EStream& stream, IShrubObject* obj) {
    return operator<<(stream, (EStorable*)obj);
}

// NON_MATCHING: stw vs stmw, register allocation
// operator>>(EStream &, IShrubObject *&) @ 0x80052564, 64 bytes
EStream& operator>>(EStream& stream, IShrubObject*& obj) {
    EStorable* tmp;
    operator>>(stream, tmp);
    obj = (IShrubObject*)tmp;
    return stream;
}

// NON_MATCHING: stw vs stmw, register allocation
// operator>>(EFile &, IShrubObject *&) @ 0x800525a4, 64 bytes
EFile& operator>>(EFile& file, IShrubObject*& obj) {
    EStorable* tmp;
    operator>>(file, tmp);
    obj = (IShrubObject*)tmp;
    return file;
}

// ============================================================================
// ISimsObjectModel - Factory / Type System
// ============================================================================

// NON_MATCHING: GCC tail-calls to constructor, original uses stack frame with bl
// ISimsObjectModel::Construct(ISimsObjectModel *) @ 0x80053c5c, 32 bytes
void ISimsObjectModel::Construct(ISimsObjectModel* obj) {
    new ((void*)obj) ISimsObjectModel();
}

// NON_MATCHING: GCC generates virtual dispatch via vtable, original bl's destructor directly
// ISimsObjectModel::Destruct(ISimsObjectModel *) @ 0x80053c7c, 36 bytes
void ISimsObjectModel::Destruct(ISimsObjectModel* obj) {
    obj->~ISimsObjectModel();
}

// NON_MATCHING: GCC generates different vtable dispatch pattern
// ISimsObjectModel::SafeDelete(void) @ 0x80053ca0, 64 bytes
void ISimsObjectModel::SafeDelete() {
    if (this != NULL) {
        this->~ISimsObjectModel();
    }
}

// ISimsObjectModel::GetTypeInfo(void) const @ 0x80053ce0, 12 bytes
const ETypeInfo* ISimsObjectModel::GetTypeInfo() const {
    return &sTypeInfo_ISimsObjectModel;
}

// ISimsObjectModel::GetTypeName(void) const @ 0x80053cec, 12 bytes
const char* ISimsObjectModel::GetTypeName() const {
    return *(const char**)((char*)&sTypeInfo_ISimsObjectModel + 0x0C);
}

// ISimsObjectModel::GetTypeKey(void) const @ 0x80053cf8, 12 bytes
u32 ISimsObjectModel::GetTypeKey() const {
    return *(u32*)((char*)&sTypeInfo_ISimsObjectModel + 0x10);
}

// ISimsObjectModel::GetTypeVersion(void) const @ 0x80053d04, 12 bytes
u16 ISimsObjectModel::GetTypeVersion() const {
    return *(u16*)((char*)&sTypeInfo_ISimsObjectModel + 0x14);
}

// ISimsObjectModel::GetTypeInfoStatic(void) @ 0x80053d10, 12 bytes
const ETypeInfo* ISimsObjectModel::GetTypeInfoStatic() {
    return &sTypeInfo_ISimsObjectModel;
}

// ISimsObjectModel::GetReadVersion(void) @ 0x80053d1c, 12 bytes
u16 ISimsObjectModel::GetReadVersion() {
    return *(u16*)((char*)&sTypeInfo_ISimsObjectModel + 0x16);
}

// NON_MATCHING: GCC tail-calls (b), original uses stack frame
// ISimsObjectModel::CreateCopy(void) const @ 0x80053d7c, 32 bytes
ISimsObjectModel* ISimsObjectModel::CreateCopy() const {
    return (ISimsObjectModel*)EStorable::CreateCopy();
}

// ISimsObjectModel::GetShadow(void) @ 0x80053d9c, 8 bytes
void* ISimsObjectModel::GetShadow() {
    return *(void**)((char*)this + 0x44C);
}

// ISimsObjectModel::GetDynamic(void) @ 0x80053da4, 12 bytes
bool ISimsObjectModel::GetDynamic() {
    u32 flags = *(u32*)((char*)this + 0x32C);
    return (flags >> 6) & 1;
}

// NON_MATCHING: GCC pre-computes both branches, original has two separate paths
// ISimsObjectModel::SetDynamic(bool) @ 0x80053db0, 40 bytes
void ISimsObjectModel::SetDynamic(bool dynamic) {
    if (dynamic) {
        *(u32*)((char*)this + 0x32C) |= 0x40;
    } else {
        *(u32*)((char*)this + 0x32C) &= ~0x40;
    }
}

// ISimsObjectModel::GetPos(void) @ 0x80053dd8, 8 bytes
EVec3* ISimsObjectModel::GetPos() {
    return (EVec3*)((char*)this + 0x404);
}

// NON_MATCHING: GCC interleaves load-store, original loads all then stores
// ISimsObjectModel::SetPos(EVec3 &) @ 0x80053de0, 32 bytes
void ISimsObjectModel::SetPos(EVec3& pos) {
    u32* dst = (u32*)((char*)this + 0x404);
    u32* src = (u32*)&pos;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ISimsObjectModel::GetDir(void) @ 0x80053e00, 8 bytes
EVec3* ISimsObjectModel::GetDir() {
    return (EVec3*)((char*)this + 0x410);
}

// NON_MATCHING: GCC interleaves load-store, original loads all then stores
// ISimsObjectModel::SetDir(EVec3 &) @ 0x80053e08, 32 bytes
void ISimsObjectModel::SetDir(EVec3& dir) {
    u32* dst = (u32*)((char*)this + 0x410);
    u32* src = (u32*)&dir;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ISimsObjectModel::GetRot(void) @ 0x80053e28, 8 bytes
float ISimsObjectModel::GetRot() {
    return *(float*)((char*)this + 0x3F0);
}

// ISimsObjectModel::SetRot(float) @ 0x80053e30, 8 bytes
void ISimsObjectModel::SetRot(float rot) {
    *(float*)((char*)this + 0x3F0) = rot;
}

// ISimsObjectModel::GetILight(void) @ 0x80053e38, 8 bytes
void* ISimsObjectModel::GetILight() {
    return *(void**)((char*)this + 0x460);
}

// NON_MATCHING: GCC uses branchless arithmetic (and), original uses branches (beqlr)
// ISimsObjectModel::ShouldAnimStartBlendIn(unsigned int) @ 0x80053e40, 32 bytes
bool ISimsObjectModel::ShouldAnimStartBlendIn(u32 animId) {
    u32 trackCount = *(u32*)((char*)this + 0x428);
    if (trackCount == 0) return false;
    if (animId == 0) return false;
    return true;
}

// NON_MATCHING: GCC uses addic+subfe, original uses cmpwi+bnelr branch pattern
// ISimsObjectModel::ShouldAnimStartImmediate(unsigned int) @ 0x80053e60, 20 bytes
bool ISimsObjectModel::ShouldAnimStartImmediate(u32 animId) {
    if (animId != 0) return true;
    return false;
}

// NON_MATCHING: GCC uses addic+subfe, original uses subfic+adde
// ISimsObjectModel::ShouldKillAllAnimTracks(unsigned int) @ 0x80053e74, 12 bytes
bool ISimsObjectModel::ShouldKillAllAnimTracks(u32 animId) {
    return animId != 0;
}

// ============================================================================
// ISimsWallObjectModel - Factory / Type System
// ============================================================================

// NON_MATCHING: GCC tail-calls, original uses stack frame
// ISimsWallObjectModel::Construct @ 0x80053ed4, 32 bytes
void ISimsWallObjectModel::Construct(ISimsWallObjectModel* obj) {
    new ((void*)obj) ISimsWallObjectModel();
}

// NON_MATCHING: GCC generates virtual dispatch, original bl's destructor
// ISimsWallObjectModel::Destruct @ 0x80053ef4, 36 bytes
void ISimsWallObjectModel::Destruct(ISimsWallObjectModel* obj) {
    obj->~ISimsWallObjectModel();
}

// NON_MATCHING: GCC generates different vtable dispatch pattern
// ISimsWallObjectModel::SafeDelete @ 0x80053f18, 64 bytes
void ISimsWallObjectModel::SafeDelete() {
    if (this != NULL) {
        this->~ISimsWallObjectModel();
    }
}

// ISimsWallObjectModel::GetTypeInfo(void) const @ 0x80053f58, 12 bytes
const ETypeInfo* ISimsWallObjectModel::GetTypeInfo() const {
    return &sTypeInfo_ISimsWallObjectModel;
}

// ISimsWallObjectModel::GetTypeName(void) const @ 0x80053f64, 12 bytes
const char* ISimsWallObjectModel::GetTypeName() const {
    return *(const char**)((char*)&sTypeInfo_ISimsWallObjectModel + 0x0C);
}

// ISimsWallObjectModel::GetTypeKey(void) const @ 0x80053f70, 12 bytes
u32 ISimsWallObjectModel::GetTypeKey() const {
    return *(u32*)((char*)&sTypeInfo_ISimsWallObjectModel + 0x10);
}

// ISimsWallObjectModel::GetTypeVersion(void) const @ 0x80053f7c, 12 bytes
u16 ISimsWallObjectModel::GetTypeVersion() const {
    return *(u16*)((char*)&sTypeInfo_ISimsWallObjectModel + 0x14);
}

// ISimsWallObjectModel::GetTypeInfoStatic(void) @ 0x80053f88, 12 bytes
const ETypeInfo* ISimsWallObjectModel::GetTypeInfoStatic() {
    return &sTypeInfo_ISimsWallObjectModel;
}

// ISimsWallObjectModel::GetReadVersion(void) @ 0x80053f94, 12 bytes
u16 ISimsWallObjectModel::GetReadVersion() {
    return *(u16*)((char*)&sTypeInfo_ISimsWallObjectModel + 0x16);
}

// NON_MATCHING: GCC tail-calls, original uses stack frame
// ISimsWallObjectModel::CreateCopy(void) const @ 0x80053ff4, 32 bytes
ISimsWallObjectModel* ISimsWallObjectModel::CreateCopy() const {
    return (ISimsWallObjectModel*)EStorable::CreateCopy();
}

// ============================================================================
// ISimsMultiTileObjectModel - Factory / Type System
// ============================================================================

// NON_MATCHING: GCC tail-calls, original uses stack frame
// ISimsMultiTileObjectModel::Construct @ 0x80054068, 32 bytes
void ISimsMultiTileObjectModel::Construct(ISimsMultiTileObjectModel* obj) {
    new ((void*)obj) ISimsMultiTileObjectModel();
}

// NON_MATCHING: GCC generates virtual dispatch, original bl's destructor
// ISimsMultiTileObjectModel::Destruct @ 0x80054088, 36 bytes
void ISimsMultiTileObjectModel::Destruct(ISimsMultiTileObjectModel* obj) {
    obj->~ISimsMultiTileObjectModel();
}

// NON_MATCHING: GCC generates different vtable dispatch pattern
// ISimsMultiTileObjectModel::SafeDelete @ 0x800540ac, 64 bytes
void ISimsMultiTileObjectModel::SafeDelete() {
    if (this != NULL) {
        this->~ISimsMultiTileObjectModel();
    }
}

// ISimsMultiTileObjectModel::GetTypeInfo(void) const @ 0x800540ec, 12 bytes
const ETypeInfo* ISimsMultiTileObjectModel::GetTypeInfo() const {
    return &sTypeInfo_ISimsMultiTileObjectModel;
}

// ISimsMultiTileObjectModel::GetTypeName(void) const @ 0x800540f8, 12 bytes
const char* ISimsMultiTileObjectModel::GetTypeName() const {
    return *(const char**)((char*)&sTypeInfo_ISimsMultiTileObjectModel + 0x0C);
}

// ISimsMultiTileObjectModel::GetTypeKey(void) const @ 0x80054104, 12 bytes
u32 ISimsMultiTileObjectModel::GetTypeKey() const {
    return *(u32*)((char*)&sTypeInfo_ISimsMultiTileObjectModel + 0x10);
}

// ISimsMultiTileObjectModel::GetTypeVersion(void) const @ 0x80054110, 12 bytes
u16 ISimsMultiTileObjectModel::GetTypeVersion() const {
    return *(u16*)((char*)&sTypeInfo_ISimsMultiTileObjectModel + 0x14);
}

// ISimsMultiTileObjectModel::GetTypeInfoStatic(void) @ 0x8005411c, 12 bytes
const ETypeInfo* ISimsMultiTileObjectModel::GetTypeInfoStatic() {
    return &sTypeInfo_ISimsMultiTileObjectModel;
}

// ISimsMultiTileObjectModel::GetReadVersion(void) @ 0x80054128, 12 bytes
u16 ISimsMultiTileObjectModel::GetReadVersion() {
    return *(u16*)((char*)&sTypeInfo_ISimsMultiTileObjectModel + 0x16);
}

// NON_MATCHING: GCC tail-calls, original uses stack frame
// ISimsMultiTileObjectModel::CreateCopy(void) const @ 0x80054188, 32 bytes
ISimsMultiTileObjectModel* ISimsMultiTileObjectModel::CreateCopy() const {
    return (ISimsMultiTileObjectModel*)EStorable::CreateCopy();
}

// ============================================================================
// ISimsCounterTopObject - Factory / Type System
// ============================================================================

// NON_MATCHING: GCC tail-calls, original uses stack frame
// ISimsCounterTopObject::Construct @ 0x800541fc, 32 bytes
void ISimsCounterTopObject::Construct(ISimsCounterTopObject* obj) {
    new ((void*)obj) ISimsCounterTopObject();
}

// NON_MATCHING: GCC generates virtual dispatch, original bl's destructor
// ISimsCounterTopObject::Destruct @ 0x8005421c, 36 bytes
void ISimsCounterTopObject::Destruct(ISimsCounterTopObject* obj) {
    obj->~ISimsCounterTopObject();
}

// NON_MATCHING: GCC generates different vtable dispatch pattern
// ISimsCounterTopObject::SafeDelete @ 0x80054240, 64 bytes
void ISimsCounterTopObject::SafeDelete() {
    if (this != NULL) {
        this->~ISimsCounterTopObject();
    }
}

// ISimsCounterTopObject::GetTypeInfo(void) const @ 0x80054280, 12 bytes
const ETypeInfo* ISimsCounterTopObject::GetTypeInfo() const {
    return &sTypeInfo_ISimsCounterTopObject;
}

// ISimsCounterTopObject::GetTypeName(void) const @ 0x8005428c, 12 bytes
const char* ISimsCounterTopObject::GetTypeName() const {
    return *(const char**)((char*)&sTypeInfo_ISimsCounterTopObject + 0x0C);
}

// ISimsCounterTopObject::GetTypeKey(void) const @ 0x80054298, 12 bytes
u32 ISimsCounterTopObject::GetTypeKey() const {
    return *(u32*)((char*)&sTypeInfo_ISimsCounterTopObject + 0x10);
}

// ISimsCounterTopObject::GetTypeVersion(void) const @ 0x800542a4, 12 bytes
u16 ISimsCounterTopObject::GetTypeVersion() const {
    return *(u16*)((char*)&sTypeInfo_ISimsCounterTopObject + 0x14);
}

// ISimsCounterTopObject::GetTypeInfoStatic(void) @ 0x800542b0, 12 bytes
const ETypeInfo* ISimsCounterTopObject::GetTypeInfoStatic() {
    return &sTypeInfo_ISimsCounterTopObject;
}

// ISimsCounterTopObject::GetReadVersion(void) @ 0x800542bc, 12 bytes
u16 ISimsCounterTopObject::GetReadVersion() {
    return *(u16*)((char*)&sTypeInfo_ISimsCounterTopObject + 0x16);
}

// NON_MATCHING: GCC tail-calls, original uses stack frame
// ISimsCounterTopObject::CreateCopy(void) const @ 0x8005431c, 32 bytes
ISimsCounterTopObject* ISimsCounterTopObject::CreateCopy() const {
    return (ISimsCounterTopObject*)EStorable::CreateCopy();
}

// ============================================================================
// IShrubObject - Factory / Type System
// ============================================================================

// NON_MATCHING: GCC tail-calls, original uses stack frame
// IShrubObject::Construct @ 0x80054390, 32 bytes
void IShrubObject::Construct(IShrubObject* obj) {
    new ((void*)obj) IShrubObject();
}

// NON_MATCHING: GCC generates virtual dispatch, original bl's destructor
// IShrubObject::Destruct @ 0x800543b0, 36 bytes
void IShrubObject::Destruct(IShrubObject* obj) {
    obj->~IShrubObject();
}

// NON_MATCHING: GCC generates different vtable dispatch pattern
// IShrubObject::SafeDelete @ 0x800543d4, 64 bytes
void IShrubObject::SafeDelete() {
    if (this != NULL) {
        this->~IShrubObject();
    }
}

// IShrubObject::GetTypeInfo(void) const @ 0x80054414, 12 bytes
const ETypeInfo* IShrubObject::GetTypeInfo() const {
    return &sTypeInfo_IShrubObject;
}

// IShrubObject::GetTypeName(void) const @ 0x80054420, 12 bytes
const char* IShrubObject::GetTypeName() const {
    return *(const char**)((char*)&sTypeInfo_IShrubObject + 0x0C);
}

// IShrubObject::GetTypeKey(void) const @ 0x8005442c, 12 bytes
u32 IShrubObject::GetTypeKey() const {
    return *(u32*)((char*)&sTypeInfo_IShrubObject + 0x10);
}

// IShrubObject::GetTypeVersion(void) const @ 0x80054438, 12 bytes
u16 IShrubObject::GetTypeVersion() const {
    return *(u16*)((char*)&sTypeInfo_IShrubObject + 0x14);
}

// IShrubObject::GetTypeInfoStatic(void) @ 0x80054444, 12 bytes
const ETypeInfo* IShrubObject::GetTypeInfoStatic() {
    return &sTypeInfo_IShrubObject;
}

// IShrubObject::GetReadVersion(void) @ 0x80054450, 12 bytes
u16 IShrubObject::GetReadVersion() {
    return *(u16*)((char*)&sTypeInfo_IShrubObject + 0x16);
}

// NON_MATCHING: GCC tail-calls, original uses stack frame
// IShrubObject::CreateCopy(void) const @ 0x800544b0, 32 bytes
IShrubObject* IShrubObject::CreateCopy() const {
    return (IShrubObject*)EStorable::CreateCopy();
}

// ============================================================================
// ISimsObjectModel::UpdateModel @ 0x800544d0, 60 bytes
// NON_MATCHING: GCC optimizes to tail-call + beqlr, original uses stack frame
// ============================================================================
void ISimsObjectModel::UpdateModel(ObjAnimDef* animDef) {
    u32 newModel = *(u32*)((char*)animDef + 0x00);
    u32 curModel = *(u32*)((char*)this + 0x420);
    if (curModel != newModel) {
        *(u32*)((char*)this + 0x420) = newModel;
        if (newModel != 0) {
            SetSOMModel(newModel);
        }
    }
}

// ============================================================================
// TArray<EILight*, TArrayDefaultAllocator> template instantiations
// ============================================================================

// NON_MATCHING: register r0 vs r9
// TArray::Init(void) @ 0x8039f614, 20 bytes
template<>
void TArray<EILight*, TArrayDefaultAllocator>::Init() {
    m_size = 0;
    m_pData = NULL;
    m_capacity = 0;
}

// NON_MATCHING: GCC inlines Init, original calls it
// TArray::TArray(void) @ 0x8039f628, 48 bytes
template<>
TArray<EILight*, TArrayDefaultAllocator>::TArray() {
    Init();
}

// NON_MATCHING: GCC optimizes away empty loop, original keeps it
// TArray::Destruct(EILight **, int) @ 0x8039f658, 28 bytes
template<>
void TArray<EILight*, TArrayDefaultAllocator>::Destruct(EILight** ptr, int count) {
    for (int i = count - 1; i >= 0; i--) {
    }
}

// NON_MATCHING: GCC generates different code for dtor + conditional delete
// TArray::~TArray(void) @ 0x8039f6c0, 64 bytes
template<>
TArray<EILight*, TArrayDefaultAllocator>::~TArray() {
    Deallocate();
}

// NON_MATCHING: GCC optimizes away empty loop
// TArray::Construct(EILight **, int) @ 0x8039f774, 28 bytes
template<>
void TArray<EILight*, TArrayDefaultAllocator>::Construct(EILight** ptr, int count) {
    for (int i = count - 1; i >= 0; i--) {
    }
}

// NON_MATCHING: GCC unrolls loop by 2, original is simple loop
// TArray::Copy(EILight **, EILight **, int) @ 0x8039f790, 44 bytes
template<>
void TArray<EILight*, TArrayDefaultAllocator>::Copy(EILight** dst, EILight** src, int count) {
    for (int i = count; i > 0; i--) {
        *dst = *src;
        dst++;
        src++;
    }
}

// NON_MATCHING: GCC unrolls loop by 2, original is simple reverse loop
// TArray::CopyReverse(EILight **, EILight **, int) @ 0x8039f8e0, 60 bytes
template<>
void TArray<EILight*, TArrayDefaultAllocator>::CopyReverse(EILight** dst, EILight** src, int count) {
    dst = dst + count - 1;
    src = src + count - 1;
    for (int i = count; i > 0; i--) {
        *dst = *src;
        dst--;
        src--;
    }
}

// NON_MATCHING: GCC tail-calls + different param passing
// TArray::Add(EILight *&) @ 0x8039f9f4, 40 bytes
template<>
void TArray<EILight*, TArrayDefaultAllocator>::Add(EILight*& item) {
    Insert((EILight**)m_size, 0, 1);
}

// ============================================================================
// EmitterGeom3d / EmitterGeom3dTab destructors
// NON_MATCHING: GCC generates vtable init code, original just calls base dtor
// ============================================================================

// EmitterGeom3d::~EmitterGeom3d(void) @ 0x8039fa1c, 32 bytes
EmitterGeom3d::~EmitterGeom3d() {
}

// EmitterGeom3dTab::~EmitterGeom3dTab(void) @ 0x8039fa3c, 32 bytes
EmitterGeom3dTab::~EmitterGeom3dTab() {
}

// NOTE: "global constructors keyed to _newlightint" @ 0x80054984, 44 bytes
// This is auto-generated by the compiler for static initialization.
// It calls __static_initialization_and_destruction_0(1, 0xFFFF).
// Cannot be directly decompiled as it is compiler-generated infrastructure.
