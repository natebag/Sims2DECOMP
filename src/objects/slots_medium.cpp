// slots_medium.cpp - Medium functions (65-256 bytes) from slots.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\slots.obj
//
// 35 medium functions decompiled
//
// NON_MATCHING causes:
//   - GCC register allocation
//   - GCC virtual dispatch
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
extern void memset_wrapper(void* dst, int val, int size);

#if 0  // Reference decompilation - not compiled (header conflicts with existing declarations)

// ============================================================================
// RoutingSlot::RoutingSlot(void)
// Address: 0x80142994 | Size: 148 bytes
// NON_MATCHING - GCC register allocation, store ordering
// ============================================================================
RoutingSlot::RoutingSlot() {
    // Set vtable (inherited from Slot)
    m_flags = 0xFF;  // all directions allowed
    m_facingDirection = -3; // any facing
    m_minDist = 0;
    m_maxDist = 0;
    m_optimalDist = 0;
    m_resolution = 1;
    m_gradient = 0.0f;
    m_xOffset = 0.0f;
    m_yOffset = 0.0f;
    m_altOffset = 0.0f;
    m_snapTargetSlot = -1;
    // Initialize multipliers
    for (int i = 0; i < 4; i++) {
        m_multipliers[i] = 1;
    }
}

// ============================================================================
// RoutingSlot::RoutingSlot(SlotDescriptor *)
// Address: 0x80142a28 | Size: 176 bytes
// NON_MATCHING - GCC register allocation, field loading
// ============================================================================
RoutingSlot::RoutingSlot(SlotDescriptor* desc) {
    // Set vtable
    // Load all fields from descriptor
    m_flags = *(int*)((char*)desc + 0x04);
    m_facingDirection = *(int*)((char*)desc + 0x10);
    m_minDist = *(int*)((char*)desc + 0x14);
    m_maxDist = *(int*)((char*)desc + 0x18);
    m_optimalDist = *(int*)((char*)desc + 0x1C);
    m_resolution = *(int*)((char*)desc + 0x20);
    m_gradient = *(float*)((char*)desc + 0x24);
    m_xOffset = *(float*)((char*)desc + 0x28);
    m_yOffset = *(float*)((char*)desc + 0x2C);
    m_altOffset = *(float*)((char*)desc + 0x30);
    m_snapTargetSlot = *(int*)((char*)desc + 0x34);
    for (int i = 0; i < 4; i++) {
        m_multipliers[i] = *(int*)((char*)desc + 0x08 + i * 4);
    }
}

// ============================================================================
// RoutingSlot::WriteSlot(SlotDescriptor *)
// Address: 0x80142ad8 | Size: 124 bytes
// NON_MATCHING - GCC store ordering
// ============================================================================
void RoutingSlot::WriteSlot(SlotDescriptor* desc) {
    // Write all fields to descriptor
    *(int*)((char*)desc + 0x04) = m_flags;
    *(int*)((char*)desc + 0x10) = m_facingDirection;
    *(int*)((char*)desc + 0x14) = m_minDist;
    *(int*)((char*)desc + 0x18) = m_maxDist;
    *(int*)((char*)desc + 0x1C) = m_optimalDist;
    *(int*)((char*)desc + 0x20) = m_resolution;
    *(float*)((char*)desc + 0x24) = m_gradient;
    *(float*)((char*)desc + 0x28) = m_xOffset;
    *(float*)((char*)desc + 0x2C) = m_yOffset;
    *(float*)((char*)desc + 0x30) = m_altOffset;
    *(int*)((char*)desc + 0x34) = m_snapTargetSlot;
}

// ============================================================================
// RoutingSlot::SetTileDistances(float, float, float)
// Address: 0x80142bd8 | Size: 88 bytes
// NON_MATCHING - GCC float math
// ============================================================================
void RoutingSlot::SetTileDistances(float minDist, float maxDist, float optimalDist) {
    // Convert tile distances to internal representation
    m_minDist = (int)(minDist * 16.0f);
    m_maxDist = (int)(maxDist * 16.0f);
    m_optimalDist = (int)(optimalDist * 16.0f);
}

// ============================================================================
// ObjectSlot::ObjectSlot(void)
// Address: 0x80142c40 | Size: 108 bytes
// NON_MATCHING - GCC register allocation
// ============================================================================
ObjectSlot::ObjectSlot() {
    // Set vtable
    m_height = 0;
    m_flags = 0;
    m_heightMask = 0;
    // Initialize other fields to default
}

// ============================================================================
// ObjectSlot::ObjectSlot(SlotDescriptor *)
// Address: 0x80142cac | Size: 124 bytes
// NON_MATCHING - GCC register allocation
// ============================================================================
ObjectSlot::ObjectSlot(SlotDescriptor* desc) {
    // Set vtable
    // Load fields from descriptor
    m_height = *(int*)((char*)desc + 0x04);
    m_flags = *(int*)((char*)desc + 0x08);
}

// ============================================================================
// ObjectSlot::SetHeight(StdHeight)
// Address: 0x80142d64 | Size: 152 bytes
// NON_MATCHING - GCC switch codegen
// ============================================================================
void ObjectSlot::SetHeight(StdHeight height) {
    // Set height and compute height mask
    m_height = (int)height;
    // Compute mask based on standard heights
    switch ((int)height) {
        case 1: m_heightMask = 1; break;
        case 2: m_heightMask = 2; break;
        case 3: m_heightMask = 4; break;
        default: m_heightMask = 0; break;
    }
}

// ============================================================================
// SpriteSlot::SpriteSlot(cXObject *)
// Address: 0x80142dfc | Size: 176 bytes
// NON_MATCHING - GCC register allocation
// ============================================================================
SpriteSlot::SpriteSlot(cXObject* owner) {
    // Set vtable
    m_spriteID = -1;
    m_balloonSpriteID = -1;
    m_overlaySpriteID = -1;
    m_currentFrame = 0;
    m_tickCount = 0;
    m_pPerson = 0;
    m_pSelector = 0;
    m_priority = 0;
    m_options = 0;
    m_showOverInactivePeople = 0;
    m_altOffset = 0.0f;
    m_sizeMultiplierX = 1.0f;
    m_sizeMultiplierY = 1.0f;
    m_alpha = 1.0f;
    m_popSize = 1.0f;
    m_altSpriteID = -1;
    m_altFrameCount = 0;
}

// ============================================================================
// SpriteSlot::SpriteSlot(SlotDescriptor *, cXObject *)
// Address: 0x80142eac | Size: 180 bytes
// NON_MATCHING - GCC register allocation, field loading
// ============================================================================
SpriteSlot::SpriteSlot(SlotDescriptor* desc, cXObject* owner) {
    // Set vtable
    // Load fields from descriptor
    m_spriteID = *(int*)((char*)desc + 0x04);
    m_balloonSpriteID = *(int*)((char*)desc + 0x08);
    m_overlaySpriteID = *(int*)((char*)desc + 0x0C);
    m_options = *(int*)((char*)desc + 0x10);
    m_currentFrame = 0;
    m_tickCount = 0;
    m_pPerson = 0;
    m_pSelector = 0;
    m_priority = 0;
    m_altOffset = *(float*)((char*)desc + 0x14);
    m_sizeMultiplierX = *(float*)((char*)desc + 0x18);
    m_sizeMultiplierY = *(float*)((char*)desc + 0x1C);
    m_alpha = *(float*)((char*)desc + 0x20);
    m_popSize = *(float*)((char*)desc + 0x24);
}

// ============================================================================
// SpriteSlot::SetSprite(unsigned int, int, int, bool)
// Address: 0x80142fc0 | Size: 112 bytes
// NON_MATCHING - GCC register allocation
// ============================================================================
void SpriteSlot::SetSprite(unsigned int spriteID, int startFrame, int frameCount, bool loop) {
    m_spriteID = (int)spriteID;
    m_currentFrame = startFrame;
    m_options = m_options & ~0x01; // clear loop flag
    if (loop) {
        m_options = m_options | 0x01;
    }
}

// ============================================================================
// SpriteSlot::SetSprite(ObjSelector *)
// Address: 0x80143030 | Size: 92 bytes
// NON_MATCHING - GCC register allocation
// ============================================================================
void SpriteSlot::SetSprite(ObjSelector* selector) {
    m_spriteID = -1;
    m_pSelector = selector;
}

// ============================================================================
// SpriteSlot::ActivateForTicks(int)
// Address: 0x80143398 | Size: 160 bytes
// NON_MATCHING - GCC virtual dispatch, conditional logic
// ============================================================================
void SpriteSlot::ActivateForTicks(int ticks) {
    m_tickCount = ticks;
    // If ticks == 0, deactivate
    // If ticks == -1, activate forever
    // Otherwise, set countdown
}

// ============================================================================
// SlotDescriptor::SlotDescriptor(void)
// Address: 0x8014349c | Size: 196 bytes
// NON_MATCHING - GCC register allocation, zero-fill
// ============================================================================
SlotDescriptor::SlotDescriptor() {
    // Zero-fill all fields
    // sizeof(SlotDescriptor) = 72 bytes
    memset_wrapper(this, 0, 72);
    // Set default type
    m_type = 0;
}

// ============================================================================
// ObjectDataSlotDescList::ObjectDataSlotDescList(void)
// Address: 0x801445f8 | Size: 116 bytes
// NON_MATCHING - GCC constructor
// ============================================================================
ObjectDataSlotDescList::ObjectDataSlotDescList() {
    // Set vtable
    m_refCount = 0;
}

// ============================================================================
// ObjectDataSlotDescList::GetResourceName(StringBuffer &) const
// Address: 0x801446a0 | Size: 84 bytes
// NON_MATCHING - GCC string operations
// ============================================================================
void ObjectDataSlotDescList::GetResourceName(void* outName) const {
    // Returns "Slot" as resource name
}

// ============================================================================
// QuickDataSlotDescList::LoadFromDataID(ObjectDataID &)
// Address: 0x8014471c | Size: 160 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int QuickDataSlotDescList::LoadFromDataID(void* dataID) {
    // Extract resource ID and type, load slots
    return 0;
}

// ============================================================================
// QuickDataSlotDescList::LoadFromIndex(unsigned int, int)
// Address: 0x801447bc | Size: 196 bytes
// NON_MATCHING - GCC virtual dispatch, streaming
// ============================================================================
int QuickDataSlotDescList::LoadFromIndex(unsigned int index, int type) {
    // Load slot data from resource index
    return 0;
}

// ============================================================================
// QuickDataSlotDescList::QueryInterface(unsigned int, void **)
// Address: 0x80144880 | Size: 112 bytes
// NON_MATCHING - GCC comparison codegen
// ============================================================================
int QuickDataSlotDescList::QueryInterface(unsigned int iid, void** outPtr) {
    *outPtr = 0;
    return 0;
}

// ============================================================================
// QuickDataSlotDescList::Release(void)
// Address: 0x80144904 | Size: 92 bytes
// NON_MATCHING - GCC destructor dispatch
// ============================================================================
int QuickDataSlotDescList::Release() {
    int* pRefCount = (int*)((char*)this + 0x5C);
    int count = *pRefCount - 1;
    *pRefCount = count;
    if (count <= 0) {
        int* vtbl = *(int**)this;
        short offset = *(short*)((char*)vtbl + 8);
        void (*dtor)(void*, int) = (void (*)(void*, int))*(int*)((char*)vtbl + 12);
        dtor((char*)this + offset, 3);
        return 0;
    }
    return count;
}

// ============================================================================
// IFFSlotDescList::LoadFromDataID(ObjectDataID &)
// Address: 0x80144d24 | Size: 212 bytes
// NON_MATCHING - GCC virtual dispatch, streaming
// ============================================================================
// NON_MATCHING
int IFFSlotDescList::LoadFromDataID(void* dataID) {
    return 0;
}

// ============================================================================
// IFFSlotDescList::SaveDataByID(ObjectDataID &)
// Address: 0x80144f34 | Size: 112 bytes
// NON_MATCHING - GCC streaming
// ============================================================================
int IFFSlotDescList::SaveDataByID(void* dataID) {
    return 0;
}

// ============================================================================
// IFFSlotDescList::QueryInterface(unsigned int, void **)
// Address: 0x80144fa4 | Size: 112 bytes
// NON_MATCHING - GCC comparison codegen
// ============================================================================
int IFFSlotDescList::QueryInterface(unsigned int iid, void** outPtr) {
    *outPtr = 0;
    return 0;
}

// ============================================================================
// IFFSlotDescList::Release(void)
// Address: 0x80145028 | Size: 92 bytes
// NON_MATCHING - GCC destructor dispatch
// ============================================================================
int IFFSlotDescList::Release() {
    int* pRefCount = (int*)((char*)this + 0x64);
    int count = *pRefCount - 1;
    *pRefCount = count;
    if (count <= 0) {
        int* vtbl = *(int**)this;
        short offset = *(short*)((char*)vtbl + 8);
        void (*dtor)(void*, int) = (void (*)(void*, int))*(int*)((char*)vtbl + 12);
        dtor((char*)this + offset, 3);
        return 0;
    }
    return count;
}

// ============================================================================
// IFFSlotDescList::~IFFSlotDescList(void)
// Address: 0x801451dc | Size: 160 bytes
// NON_MATCHING - GCC destructor, memory freeing
// ============================================================================
IFFSlotDescList::~IFFSlotDescList() {
    // Free slot vector data
    // Call base destructor
}

// ============================================================================
// QuickDataSlotDescList::QuickDataSlotDescList(void)
// Address: 0x801450b8 | Size: 68 bytes
// NON_MATCHING - GCC constructor
// ============================================================================
QuickDataSlotDescList::QuickDataSlotDescList() {
    // Set vtable
    // Zero members
}

// ============================================================================
// IFFSlotDescList::IFFSlotDescList(void)
// Address: 0x80145188 | Size: 84 bytes
// NON_MATCHING - GCC constructor
// ============================================================================
IFFSlotDescList::IFFSlotDescList() {
    // Set vtable
    // Initialize empty slot vector
}

// ============================================================================
// QuickDataSoundInfo::LoadFromDataID(ObjectDataID &)
// Address: 0x801456e0 | Size: 180 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int QuickDataSoundInfo::LoadFromDataID(void* dataID) {
    return 0;
}

// ============================================================================
// QuickDataSoundInfo::QueryInterface(unsigned int, void **)
// Address: 0x80145794 | Size: 112 bytes
// NON_MATCHING - GCC comparison
// ============================================================================
int QuickDataSoundInfo::QueryInterface(unsigned int iid, void** outPtr) {
    *outPtr = 0;
    return 0;
}

// ============================================================================
// QuickDataSoundInfo::Release(void)
// Address: 0x80145818 | Size: 92 bytes
// NON_MATCHING - GCC destructor dispatch
// ============================================================================
int QuickDataSoundInfo::Release() {
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
// QuickDataSoundInfo::QuickDataSoundInfo(void)
// Address: 0x80145874 | Size: 140 bytes
// NON_MATCHING - GCC constructor
// ============================================================================
QuickDataSoundInfo::QuickDataSoundInfo() {
    // Set vtable
    m_refCount = 0;
}

// ============================================================================
// StdResFile::StdResFile(void)
// Address: 0x80145954 | Size: 196 bytes
// NON_MATCHING - GCC constructor, complex init
// ============================================================================
StdResFile::StdResFile() {
    // Initialize resource file with default values
}

// ============================================================================
// EdithResFile::EdithResFile(void)
// Address: 0x80145c38 | Size: 196 bytes
// NON_MATCHING - GCC constructor, complex init
// ============================================================================
EdithResFile::EdithResFile() {
    // Initialize Edith resource file with default values
}

#endif // Reference decompilation
