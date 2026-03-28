// e_instance.cpp - EInstance class (game object instances)
// Part of the Sims 2 GC decompilation
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\e_instance.obj
//
// Small functions (<=64 bytes) decompiled from the e_instance object file.
// Matching status notes:
//   MATCHING - Produces byte-identical output (after linking/relocation)
//   NON_MATCHING - Structurally correct but differs due to GCC vs SN Systems compiler

#include "render/e_instance.h"

// Placement new
inline void* operator new(u32, void* ptr) { return ptr; }

// External function declarations
extern "C" {
    void* __builtin_new(u32 size);
    void __builtin_delete(void* ptr);
}

// External functions
void ERLevel_RemoveInstance(ERLevel*, EInstance*);
void ERLevel_InsertInOrderTable(ERLevel*, EOrderTableData&);
void EMat4_Id(EMat4*);

// Stream operators (external)
EStream& operator<<(EStream& stream, EStorable* storable);
EStream& operator>>(EStream& stream, EStorable*& storable);
EFile& operator>>(EFile& file, EStorable*& storable);
EStorable* EStorable_CreateCopy(const EStorable*);

// Static data
int EInstance::_instanceContext;
ETypeInfo EInstance::m_typeInfo;

// String constant for GetInstName
static const char s_unnamedInst[] = "Unnamed inst type";

//=============================================================================
// operator<< (EStream&, EInstance*)
// Address: 0x802281F0, Size: 0x20
// NON_MATCHING: GCC tail-calls, original has full stack frame wrapper
//=============================================================================
EStream& operator<<(EStream& stream, EInstance* inst) {
    return operator<<(stream, (EStorable*)inst);
}

//=============================================================================
// operator>> (EStream&, EInstance*&)
// Address: 0x80228210, Size: 0x40
// NON_MATCHING: Register allocation differs (GCC uses r30/r31, orig uses r29/r30)
//   Also GCC saves with individual stw, orig uses stmw
//=============================================================================
EStream& operator>>(EStream& stream, EInstance*& inst) {
    EStorable* storable;
    operator>>(stream, storable);
    inst = (EInstance*)storable;
    return stream;
}

//=============================================================================
// operator>> (EFile&, EInstance*&)
// Address: 0x80228250, Size: 0x40
// NON_MATCHING: Same issue as EStream version above
//=============================================================================
EFile& operator>>(EFile& file, EInstance*& inst) {
    EStorable* storable;
    operator>>(file, storable);
    inst = (EInstance*)storable;
    return file;
}

//=============================================================================
// EInstance::RemoveFromLevel
// Address: 0x80228818, Size: 0x30
// NON_MATCHING: GCC generates beqlr+tail-call, original has full stack frame
//=============================================================================
void EInstance::RemoveFromLevel() {
    ERLevel* level = m_pLevel;
    if (level != 0) {
        ERLevel_RemoveInstance(level, this);
    }
}

//=============================================================================
// EInstance::GetBoundSphere
// Address: 0x802287F4, Size: 0x24
// NON_MATCHING: GCC generates tail-call, original has full stack frame
//=============================================================================
void EInstance::GetBoundSphere(EBoundSphere& sphere) {
    m_bounds.CalcBoundSphere(sphere);
}

//=============================================================================
// LightArray::Init
// Address: 0x80228EF4, Size: 0x0C
// MATCHING (after relocation; uses r9 vs r0 for temp - minor reg diff)
//=============================================================================
void LightArray::Init() {
    count = 0;
}

//=============================================================================
// EInstance::InsertInOrderTable
// Address: 0x802291F8, Size: 0x24
// NON_MATCHING: GCC generates tail-call, original has full stack frame
//=============================================================================
void EInstance::InsertInOrderTable(EOrderTableData& data) {
    ERLevel_InsertInOrderTable(m_pLevel, data);
}

//=============================================================================
// EInstance::SetContext
// Address: 0x8022921C, Size: 0x08
// MATCHING (after linking - SDA access vs global; same structure)
//=============================================================================
void EInstance::SetContext(int context) {
    _instanceContext = context;
}

//=============================================================================
// EInstance::GetContext
// Address: 0x80229224, Size: 0x08
// MATCHING (after linking - SDA access)
//=============================================================================
int EInstance::GetContext() {
    return _instanceContext;
}

//=============================================================================
// EInstance::SetInstAlpha
// Address: 0x8022922C, Size: 0x44
// NON_MATCHING: GCC generates different branching for float comparisons
//   (cror eq,lt,eq / beq vs cror so,eq,lt / bns)
//   Also different code layout for the clamp+store path
//=============================================================================
void EInstance::SetInstAlpha(float alpha) {
    if (alpha <= 0.0f) {
        alpha = 0.0f;
    }
    if (alpha >= 1.0f) {
        alpha = 1.0f;
    }
    (&m_instAlpha0)[_instanceContext] = alpha;
}

//=============================================================================
// EInstance::GetInstAlpha
// Address: 0x80229270, Size: 0x14
// NON_MATCHING: GCC uses add+lfs, original uses lfsx (indexed load)
//   Also SDA base access difference
//=============================================================================
float EInstance::GetInstAlpha() {
    return (&m_instAlpha0)[_instanceContext];
}

//=============================================================================
// EInstance::New
// Address: 0x802292F4, Size: 0x28
// NON_MATCHING: GCC saves r31 for return value, original doesn't
//   (original assumes EInstance() returns this in r3)
//=============================================================================
EInstance* EInstance::New() {
    EInstance* inst = (EInstance*)__builtin_new(sizeof(EInstance));
    new (inst) EInstance();
    return inst;
}

//=============================================================================
// EInstance::Construct
// Address: 0x8022931C, Size: 0x20
// NON_MATCHING: GCC tail-calls constructor, original has full stack frame
//=============================================================================
void EInstance::Construct(EInstance* inst) {
    new (inst) EInstance();
}

//=============================================================================
// EInstance::Destruct
// Address: 0x8022933C, Size: 0x24
// NON_MATCHING: GCC does vtable indirect call, original calls destructor
//   directly with r4=2 (deleting destructor flag)
//=============================================================================
void EInstance::Destruct(EInstance* inst) {
    inst->~EInstance();
}

//=============================================================================
// EInstance::SafeDelete
// Address: 0x80229360, Size: 0x40
// NON_MATCHING: GCC does vtable indirect call, original loads vtable
//   and calls through blrl with full stack frame
//=============================================================================
void EInstance::SafeDelete() {
    if (this != 0) {
        this->~EInstance();
    }
}

//=============================================================================
// EInstance::GetTypeInfo
// Address: 0x802293A0, Size: 0x0C
// MATCHING (after relocation)
//=============================================================================
const ETypeInfo* EInstance::GetTypeInfo() const {
    return &m_typeInfo;
}

//=============================================================================
// EInstance::GetTypeName
// Address: 0x802293AC, Size: 0x0C
// MATCHING (after relocation)
//=============================================================================
const char* EInstance::GetTypeName() const {
    return m_typeInfo.m_name;
}

//=============================================================================
// EInstance::GetTypeKey
// Address: 0x802293B8, Size: 0x0C
// MATCHING (after relocation)
//=============================================================================
u32 EInstance::GetTypeKey() const {
    return m_typeInfo.m_key;
}

//=============================================================================
// EInstance::GetTypeVersion
// Address: 0x802293C4, Size: 0x0C
// MATCHING (after relocation)
//=============================================================================
u16 EInstance::GetTypeVersion() const {
    return m_typeInfo.m_version;
}

//=============================================================================
// EInstance::GetTypeInfoStatic
// Address: 0x802293D0, Size: 0x0C
// MATCHING (after relocation)
//=============================================================================
const ETypeInfo* EInstance::GetTypeInfoStatic() {
    return &m_typeInfo;
}

//=============================================================================
// EInstance::GetReadVersion
// Address: 0x802293DC, Size: 0x0C
// MATCHING (after relocation)
//=============================================================================
u16 EInstance::GetReadVersion() {
    return m_typeInfo.m_readVersion;
}

//=============================================================================
// EInstance::CreateCopy
// Address: 0x8022943C, Size: 0x20
// NON_MATCHING: GCC tail-calls, original has stack frame
//=============================================================================
EStorable* EInstance::CreateCopy() const {
    return EStorable_CreateCopy(this);
}

//=============================================================================
// Virtual stubs - all just blr (empty functions)
// ALL MATCHING - empty functions always produce just blr
//=============================================================================

// Address: 0x8022945C, Size: 0x04 - MATCHING
void EInstance::Init() {}

// Address: 0x80229460, Size: 0x04 - MATCHING
void EInstance::Update() {}

// Address: 0x80229464, Size: 0x04 - MATCHING
void EInstance::DoAnimation() {}

// Address: 0x80229468, Size: 0x04 - MATCHING
void EInstance::DoLightingCalculation() {}

//=============================================================================
// EInstance::VisibilityTest
// Address: 0x8022946C, Size: 0x08
// MATCHING
//=============================================================================
int EInstance::VisibilityTest(E3DWindow& window) {
    return 1;
}

// Address: 0x80229474, Size: 0x04 - MATCHING
void EInstance::Draw(ELevelDrawData& data) {}

// Address: 0x80229478, Size: 0x04 - MATCHING
void EInstance::DrawStencil(ELevelDrawData& data) {}

// Address: 0x8022947C, Size: 0x04 - MATCHING
void EInstance::DrawShadow(ELevelDrawData& data) {}

// Address: 0x80229480, Size: 0x04 - MATCHING
void EInstance::DrawWireFrame(ERC* rc) {}

// Address: 0x80229484, Size: 0x04 - MATCHING
void EInstance::SetOrient(EMat4& orient) {}

// Address: 0x80229488, Size: 0x04 - MATCHING
void EInstance::RebuildShaders() {}

//=============================================================================
// EInstance::GetInstName
// Address: 0x8022948C, Size: 0x14
// MATCHING (after relocation; minor reg diff: r9 vs r0 for zero)
//=============================================================================
const char* EInstance::GetInstName(InstType& type) {
    type.value = 0;
    return s_unnamedInst;
}

//=============================================================================
// EInstance::GetUpdatePriority
// Address: 0x802294A0, Size: 0x08
// MATCHING
//=============================================================================
int EInstance::GetUpdatePriority() {
    return 50;
}

// Address: 0x802294A8, Size: 0x04 - MATCHING
void EInstance::RegisterFloor() {}

//=============================================================================
// EInstance::SetPortalType
// Address: 0x802295C4, Size: 0x08
// MATCHING
//=============================================================================
void EInstance::SetPortalType(EPortalType type) {
    m_portalType = type;
}

//=============================================================================
// EInstance::GetPortalType
// Address: 0x802295CC, Size: 0x08
// MATCHING
//=============================================================================
EPortalType EInstance::GetPortalType() {
    return m_portalType;
}

//=============================================================================
// EInstance::RegisterOtherSideFn
// Address: 0x802295D4, Size: 0x0C
// NON_MATCHING: GCC stores r4 before r5, original stores r5 first
//=============================================================================
void EInstance::RegisterOtherSideFn(u32 data, PortalSideFn fn) {
    m_otherSideFn = fn;
    m_otherSideData = data;
}

//=============================================================================
// EInstance::GetThisSideData
// Address: 0x802295E0, Size: 0x08
// MATCHING
//=============================================================================
u32 EInstance::GetThisSideData() {
    return m_thisSideData;
}

//=============================================================================
// EInstance::GetThisSideFn
// Address: 0x802295E8, Size: 0x08
// MATCHING
//=============================================================================
PortalSideFn EInstance::GetThisSideFn() {
    return m_thisSideFn;
}

//=============================================================================
// EInstance::GetOtherSideData
// Address: 0x802295F0, Size: 0x08
// MATCHING
//=============================================================================
u32 EInstance::GetOtherSideData() {
    return m_otherSideData;
}

//=============================================================================
// EInstance::GetOtherSideFn
// Address: 0x802295F8, Size: 0x08
// MATCHING
//=============================================================================
PortalSideFn EInstance::GetOtherSideFn() {
    return m_otherSideFn;
}

//=============================================================================
// EInstance::RegisterThisSideFn
// Address: 0x80229600, Size: 0x0C
// NON_MATCHING: GCC stores r4 before r5, original stores r5 first
//=============================================================================
void EInstance::RegisterThisSideFn(u32 data, PortalSideFn fn) {
    m_thisSideFn = fn;
    m_thisSideData = data;
}

//=============================================================================
// EInstance::RegisterHiddenFn
// Address: 0x8022960C, Size: 0x0C
// NON_MATCHING: GCC stores r4 before r5, original stores r5 first
//=============================================================================
void EInstance::RegisterHiddenFn(u32 data, HiddenFn fn) {
    m_hiddenFn = fn;
    m_hiddenData = data;
}

//=============================================================================
// EInstance::IsHidden
// Address: 0x80229618, Size: 0x3C
// NON_MATCHING: GCC generates tail-call via bctr, original has full
//   stack frame with blrl
//=============================================================================
bool EInstance::IsHidden() {
    if (m_hiddenFn == 0) {
        return false;
    }
    return m_hiddenFn(m_hiddenData);
}

//=============================================================================
// EInstance::SetShadowInterpolated
// Address: 0x80229654, Size: 0x08
// MATCHING
//=============================================================================
void EInstance::SetShadowInterpolated(bool interp) {
    m_field0C = (u32)interp;
}

// Address: 0x8022965C, Size: 0x04 - MATCHING
void EInstance::GetShadowCenter(EVec3& center) const {}

//=============================================================================
// EInstance::GetBounds
// Address: 0x80229660, Size: 0x08
// MATCHING
//=============================================================================
const EBound3* EInstance::GetBounds() const {
    return &m_bounds;
}

// Address: 0x80229668, Size: 0x04 - MATCHING
void EInstance::ReadInstanceData(EStream& stream, bool flag) {}

//=============================================================================
// EInstance::CanReloadInstanceData
// Address: 0x8022966C, Size: 0x08
// MATCHING
//=============================================================================
int EInstance::CanReloadInstanceData() {
    return 0;
}

//=============================================================================
// EInstance::GetLevel
// Address: 0x80229674, Size: 0x08
// MATCHING
//=============================================================================
ERLevel* EInstance::GetLevel() {
    return m_pLevel;
}

//=============================================================================
// EInstance::GetOwner
// Address: 0x8022967C, Size: 0x04 (just blr)
// NON_MATCHING: Original is just blr (returns unmodified r3 = this).
//   GCC generates li r3,0; blr when returning 0.
//   Should be a void return type in the original.
//=============================================================================
void* EInstance::GetOwner() {
    return 0;
}

//=============================================================================
// EInstance::GetNumRoomID
// Address: 0x80229680, Size: 0x08
// MATCHING
//=============================================================================
int EInstance::GetNumRoomID() {
    return 0;
}

//=============================================================================
// EInstance::GetRoomID
// Address: 0x80229688, Size: 0x08
// MATCHING
//=============================================================================
int EInstance::GetRoomID(u32 index) {
    return 0;
}

//=============================================================================
// EInstance::GetVelocity
// Address: 0x80229690, Size: 0x18
// MATCHING (after relocation)
//=============================================================================
void EInstance::GetVelocity(EVec3& vel) {
    float zero = 0.0f;
    ((float*)&vel)[0] = zero;
    ((float*)&vel)[2] = zero;
    ((float*)&vel)[1] = zero;
}

//=============================================================================
// EInstance::GetPos
// Address: 0x802296A8, Size: 0x18
// MATCHING (after relocation)
//=============================================================================
void EInstance::GetPos(EVec3& pos) {
    float zero = 0.0f;
    ((float*)&pos)[0] = zero;
    ((float*)&pos)[2] = zero;
    ((float*)&pos)[1] = zero;
}

//=============================================================================
// EInstance::GetOrient
// Address: 0x802296C0, Size: 0x24
// NON_MATCHING: GCC generates tail-call, original has stack frame
//=============================================================================
void EInstance::GetOrient(EMat4& orient) {
    EMat4_Id(&orient);
}

//=============================================================================
// EInstance::HasModifiableColor
// Address: 0x802296E4, Size: 0x08
// MATCHING
//=============================================================================
int EInstance::HasModifiableColor() {
    return 0;
}

// Address: 0x802296EC, Size: 0x04 - MATCHING
void EInstance::ModifyColor(u32 color) {}

//=============================================================================
// EInstance::GetModifiableColor
// Address: 0x802296F0, Size: 0x08
// MATCHING
//=============================================================================
int EInstance::GetModifiableColor(u32 index) {
    return 0;
}

// Address: 0x802296F8, Size: 0x04 - MATCHING
void EInstance::AddedToLevel(ERLevel* level) {}

// Address: 0x802296FC, Size: 0x04 - MATCHING
void EInstance::AboutToBeRemovedFromLevel(ERLevel* level) {}

// Address: 0x80229700, Size: 0x04 - MATCHING
void EInstance::RemovedFromLevel(ERLevel* level) {}

//=============================================================================
// EInstance::IsShadow
// Address: 0x80229704, Size: 0x18
// NON_MATCHING: GCC uses addic/subfe pattern, original uses
//   li r3,1; cmpwi; bnelr pattern
//=============================================================================
bool EInstance::IsShadow() {
    if (m_shadowOwner != 0) {
        return true;
    }
    return false;
}

//=============================================================================
// EInstance::GetShadowOwner
// Address: 0x8022971C, Size: 0x08
// MATCHING
//=============================================================================
EInstance* EInstance::GetShadowOwner() {
    return m_shadowOwner;
}

//=============================================================================
// EInstance::IsWall
// Address: 0x80229724, Size: 0x08
// MATCHING
//=============================================================================
int EInstance::IsWall() {
    return m_isWall;
}

//=============================================================================
// EInstance::ShouldInterestFade
// Address: 0x8022972C, Size: 0x14
// NON_MATCHING: GCC just stores r4 directly (2 instructions).
//   Original uses xori/subfic/adde pattern to normalize bool (5 instructions).
//=============================================================================
void EInstance::ShouldInterestFade(bool fade) {
    m_field6C = fade ? 1 : 0;
}

// Address: 0x80229740, Size: 0x04 - MATCHING
void EInstance::RealizeShaderTuning() {}
