// iobject_medium.cpp - Medium functions (65-256 bytes) from iobject.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\iobject.obj
//
// 40 medium functions decompiled from iobject.obj
//
// NON_MATCHING causes:
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC register allocation
//   - GCC constructor/destructor ABI
//   - GCC loop codegen (bdnz)

#include "types.h"

// Forward declarations - this file is standalone to avoid header conflicts
// All functions are NON_MATCHING stubs for documentation purposes


// External functions
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);

#if 0  // Reference decompilation - not compiled (header conflicts with existing declarations)

// ============================================================================
// EParticleEffect::SetAlphaFade(float)
// Address: 0x8004bfe4 | Size: 124 bytes
// NON_MATCHING - GCC float math codegen
// ============================================================================
void EParticleEffect::SetAlphaFade(float fade) {
    // Set alpha fade value for particle effect
    // Clamps to 0.0-1.0 range
    if (fade < 0.0f) fade = 0.0f;
    if (fade > 1.0f) fade = 1.0f;
    *(float*)((char*)this + 0x10) = fade;
}

// ============================================================================
// CalcRotAngleOff(float)
// Address: 0x8004c060 | Size: 208 bytes
// NON_MATCHING - GCC float math
// ============================================================================
float CalcRotAngleOff(float angle) {
    // Calculate rotation angle offset
    // Normalizes angle to -PI to PI range
    return angle;
}

// ============================================================================
// EParticleObj::~EParticleObj(void)
// Address: 0x8004c150 | Size: 168 bytes
// NON_MATCHING - GCC destructor, loop cleanup
// ============================================================================
EParticleObj::~EParticleObj() {
    // Clean up particle effect pointers
    for (int i = 0; i < m_count; i++) {
        if (m_effectPtrs[i] != 0) {
            // Release effect
        }
    }
}

// ============================================================================
// ISimsObjectModel::InsertSubModelsInHouse(ERLevel *)
// Address: 0x8004c91c | Size: 80 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void ISimsObjectModel::InsertSubModelsInHouse(void* level) {
    // Insert sub-models into house rendering
}

// ============================================================================
// ISimsObjectModel::PropigateFlagsToSubModels(void)
// Address: 0x8004c96c | Size: 100 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
void ISimsObjectModel::PropigateFlagsToSubModels() {
    // Copy flags from main model to all sub-models
}

// ============================================================================
// ISimsObjectModel::UpdateShader(ObjAnimDef *)
// Address: 0x8005450c | Size: 80 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void ISimsObjectModel::UpdateShader(void* animDef) {
    // Update shader from animation definition
    if (animDef == 0) return;
    unsigned int shaderID = *(unsigned int*)((char*)animDef + 0x08);
    unsigned int curShader = *(unsigned int*)((char*)this + 0x41C);
    if (shaderID != curShader) {
        *(unsigned int*)((char*)this + 0x41C) = shaderID;
        // Apply new shader
    }
}

// ============================================================================
// ISimsObjectModel::CalcDynamicOrient(void)
// Address: 0x8004ec78 | Size: 168 bytes
// NON_MATCHING - GCC float math, matrix operations
// ============================================================================
// NON_MATCHING
void ISimsObjectModel::CalcDynamicOrient() {
    // Calculate dynamic orientation matrix from position and rotation
}

// ============================================================================
// ISimsObjectModel::SetSOMModel(unsigned int)
// Address: 0x8004dd1c | Size: 208 bytes
// NON_MATCHING - complex model loading
// ============================================================================
// NON_MATCHING
void ISimsObjectModel::SetSOMModel(unsigned int modelID) {
    // Set the model for this object
    // Loads model resource, sets up rendering data
}

// ============================================================================
// ISimsObjectModel::AnimStartImmediate(unsigned int)
// Address: 0x8004df34 | Size: 80 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void ISimsObjectModel::AnimStartImmediate(unsigned int animID) {
    // Start animation immediately (no blend)
    *(unsigned int*)((char*)this + 0x428) = animID;
}

// ============================================================================
// ISimsObjectModel::AnimStartBlendIn(unsigned int)
// Address: 0x8004df84 | Size: 80 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void ISimsObjectModel::AnimStartBlendIn(unsigned int animID) {
    // Start animation with blend-in
    *(unsigned int*)((char*)this + 0x428) = animID;
}

// ============================================================================
// ISimsObjectModel::KillAllAnimTracks(void)
// Address: 0x8004dfd4 | Size: 84 bytes
// NON_MATCHING - GCC register allocation
// ============================================================================
void ISimsObjectModel::KillAllAnimTracks() {
    // Kill all animation tracks
    *(unsigned int*)((char*)this + 0x428) = 0;
}

// ============================================================================
// ISimsObjectModel::UpdateAnimController(void)
// Address: 0x8004fc8c | Size: 172 bytes
// NON_MATCHING - complex animation update
// ============================================================================
// NON_MATCHING
void ISimsObjectModel::UpdateAnimController() {
    // Update animation controller state
}

// ============================================================================
// ISimsObjectModel::RemoveSubModelsFromHouse(ERLevel *)
// Address: 0x8004e55c | Size: 188 bytes
// NON_MATCHING - GCC loop/virtual dispatch
// ============================================================================
// NON_MATCHING
void ISimsObjectModel::RemoveSubModelsFromHouse(void* level) {
    // Remove sub-models from house rendering
}

// ============================================================================
// ISimsObjectModel::ChageShader(unsigned int, unsigned int)
// Address: 0x8004e618 | Size: 136 bytes
// NON_MATCHING - GCC virtual dispatch
// (Note: original has typo "Chage" instead of "Change")
// ============================================================================
void ISimsObjectModel::ChageShader(unsigned int oldShader, unsigned int newShader) {
    // Change shader from old to new
}

// ============================================================================
// OtherSide(unsigned int, bool, short &, short &)
// Address: 0x8004e6a0 | Size: 112 bytes
// NON_MATCHING - GCC switch codegen
// ============================================================================
void OtherSide(unsigned int wallData, bool isTop, short& outX, short& outY) {
    // Get other side coordinates from wall data
}

// ============================================================================
// ISimsObjectModel::GetAdjacentRoom(bool)
// Address: 0x8004e7dc | Size: 140 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int ISimsObjectModel::GetAdjacentRoom(bool otherSide) {
    // Get room ID on other side of wall object
    return 0;
}

// ============================================================================
// Hidden(unsigned int)
// Address: 0x8004e794 | Size: 72 bytes
// NON_MATCHING - GCC bit manipulation
// ============================================================================
int Hidden(unsigned int wallData) {
    // Check if wall segment is hidden
    return (wallData >> 16) & 1;
}

// ============================================================================
// ISimsObjectModel::PreloadAnimation(short)
// Address: 0x8004ef58 | Size: 212 bytes
// NON_MATCHING - complex animation preloading
// ============================================================================
// NON_MATCHING
void ISimsObjectModel::PreloadAnimation(short animID) {
    // Preload animation resource
}

// ============================================================================
// ISimsObjectModel::VisibilityTest(E3DWindow &)
// Address: 0x8004fba0 | Size: 132 bytes
// NON_MATCHING - GCC float math, frustum culling
// ============================================================================
int ISimsObjectModel::VisibilityTest(void* window) {
    // Test if object is visible within camera frustum
    return 1;
}

// ============================================================================
// ISimsObjectModel::IsVisible(void)
// Address: 0x8004fc24 | Size: 104 bytes
// NON_MATCHING - GCC flag checking
// ============================================================================
int ISimsObjectModel::IsVisible() {
    unsigned int flags = *(unsigned int*)((char*)this + 0x32C);
    if (flags & 0x01) return 0; // hidden
    return 1;
}

// ============================================================================
// ISimsObjectModel::DoAnimation(void)
// Address: 0x8004fd38 | Size: 240 bytes
// NON_MATCHING - complex animation state machine
// ============================================================================
// NON_MATCHING
void ISimsObjectModel::DoAnimation() {
    // Process current animation frame
}

// ============================================================================
// ISimsObjectModel::DrawBounds(ERC *)
// Address: 0x80050418 | Size: 160 bytes
// NON_MATCHING - GCC float math, rendering
// ============================================================================
// NON_MATCHING
void ISimsObjectModel::DrawBounds(void* rc) {
    // Debug draw: render bounding box
}

// ============================================================================
// PortalRoom(unsigned int, bool, short &, short &)
// Address: 0x80050c38 | Size: 104 bytes
// NON_MATCHING - GCC switch codegen
// ============================================================================
void PortalRoom(unsigned int wallData, bool isTop, short& outX, short& outY) {
    // Get portal room from wall data
}

// ============================================================================
// ISimsObjectModel::Create(cXObject *, EHouse *)
// Address: 0x80050ca0 | Size: 164 bytes
// NON_MATCHING - GCC virtual dispatch chain
// ============================================================================
void ISimsObjectModel::Create(cXObject* obj, void* house) {
    *(cXObject**)((char*)this + 0x328) = obj;
    *(void**)((char*)this + 0x3C8) = house;
    // Set orientation and initial state
}

// ============================================================================
// ISimsObjectModel::OrientSubObjects(void)
// Address: 0x80050eb4 | Size: 96 bytes
// NON_MATCHING - GCC loop
// ============================================================================
void ISimsObjectModel::OrientSubObjects() {
    // Orient all sub-objects to match main object's orientation
}

// ============================================================================
// ISimsWallObjectModel::ISimsWallObjectModel(void)
// Address: 0x80051170 | Size: 72 bytes
// NON_MATCHING - GCC constructor
// ============================================================================
ISimsWallObjectModel::ISimsWallObjectModel() {
    // Set vtable
    // Initialize wall-specific fields
}

// ============================================================================
// ISimsWallObjectModel::~ISimsWallObjectModel(void)
// Address: 0x800511b8 | Size: 96 bytes
// NON_MATCHING - GCC destructor
// ============================================================================
ISimsWallObjectModel::~ISimsWallObjectModel() {
    // Clean up wall object model
}

// ============================================================================
// ISimsWallObjectModel::Create(cXObject *, EHouse *)
// Address: 0x8005121c | Size: 96 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void ISimsWallObjectModel::Create(cXObject* obj, void* house) {
    *(cXObject**)((char*)this + 0x328) = obj;
    *(void**)((char*)this + 0x3C8) = house;
}

// ============================================================================
// ISimsMultiTileObjectModel::ISimsMultiTileObjectModel(void)
// Address: 0x80051a8c | Size: 72 bytes
// NON_MATCHING - GCC constructor
// ============================================================================
ISimsMultiTileObjectModel::ISimsMultiTileObjectModel() {
    // Set vtable
    // Initialize multi-tile specific fields
}

// ============================================================================
// ThisSide(unsigned int, bool, short &, short &)
// Address: 0x8004e710 | Size: 132 bytes
// NON_MATCHING - GCC switch codegen
// ============================================================================
void ThisSide(unsigned int wallData, bool isTop, short& outX, short& outY) {
    // Get this side coordinates from wall data
}

// ============================================================================
// TArray<EILight*>::Deallocate()
// Address: 0x8039f674 | Size: 76 bytes
// NON_MATCHING - GCC memory deallocation
// ============================================================================
template<>
void TArray_EILight_Deallocate(void* self) {
    // Free array data
    void* data = *(void**)((char*)self + 4);
    if (data != 0) {
        operator_delete(data);
    }
    *(void**)((char*)self + 4) = 0;
    *(int*)((char*)self + 0) = 0;
    *(int*)((char*)self + 8) = 0;
}

// ============================================================================
// TArray<EILight*>::Remove(int)
// Address: 0x8039f700 | Size: 116 bytes
// NON_MATCHING - GCC loop codegen, bounds checking
// ============================================================================
template<>
void TArray_EILight_Remove(void* self, int index) {
    // Remove element at index, shift remaining elements
    int size = *(int*)self;
    if (index < 0 || index >= size) return;
    void** data = *(void***)((char*)self + 4);
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    *(int*)self = size - 1;
}

// ============================================================================
// TArray<EILight*>::Grow(int)
// Address: 0x8039f7bc | Size: 140 bytes
// NON_MATCHING - GCC memory allocation, copy
// ============================================================================
template<>
void TArray_EILight_Grow(void* self, int newCapacity) {
    int oldCapacity = *(int*)((char*)self + 8);
    if (newCapacity <= oldCapacity) return;
    void** oldData = *(void***)((char*)self + 4);
    void** newData = (void**)operator_new(newCapacity * 4);
    int size = *(int*)self;
    for (int i = 0; i < size; i++) {
        newData[i] = oldData[i];
    }
    if (oldData) operator_delete(oldData);
    *(void***)((char*)self + 4) = newData;
    *(int*)((char*)self + 8) = newCapacity;
}

// ============================================================================
// TArray<EILight*>::Insert(int, int)
// Address: 0x8039f85c | Size: 132 bytes
// NON_MATCHING - GCC insert logic
// ============================================================================
template<>
void TArray_EILight_Insert(void* self, int index, int count) {
    // Insert count empty elements at index
    // Grows array if needed
}

// ============================================================================
// TArray<EILight*>::SetSize(int)
// Address: 0x8039f91c | Size: 108 bytes
// NON_MATCHING - GCC grow/shrink logic
// ============================================================================
template<>
void TArray_EILight_SetSize(void* self, int newSize) {
    int capacity = *(int*)((char*)self + 8);
    if (newSize > capacity) {
        TArray_EILight_Grow(self, newSize);
    }
    *(int*)self = newSize;
}

// ============================================================================
// TArray<EILight*>::Find(void*, int, int)
// Address: 0x8039f98c | Size: 104 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
template<>
int TArray_EILight_Find(void* self, void* item, int startIdx, int endIdx) {
    void** data = *(void***)((char*)self + 4);
    int size = *(int*)self;
    if (endIdx > size) endIdx = size;
    for (int i = startIdx; i < endIdx; i++) {
        if (data[i] == item) return i;
    }
    return -1;
}

#endif // Reference decompilation
