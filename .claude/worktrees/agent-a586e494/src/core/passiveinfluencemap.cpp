// passiveinfluencemap.cpp - Passive influence map small functions
// From: passiveinfluencemap.obj (linked into influencemap.obj .text section)
// Small functions (<=64 bytes) decompiled from this object

#include "core/passiveinfluencemap.h"

// ============================================================================
// External references
// ============================================================================

// __builtin_delete - SN Systems runtime delete operator (0x802d1220)
extern "C" void __builtin_delete(void* ptr);

// PassiveInfluenceSystem::NotifySimulator (static, 0x80114704)
// PassiveInfluenceMap::EmptyMap (0x80113944)

// SDA globals (r13-relative)
// r13-0x7C24 (-31780) = PassiveInfluenceSystem instance pointer
// r13-0x7C28 (-31784) = PassiveInfluenceMap pointer

// ============================================================================
// PassiveInfluenceMap::NotifySimulator(cXPerson *, int, int)
// 0x80113A58 - 52 bytes
// Checks if system exists, then delegates to PassiveInfluenceSystem::NotifySimulator
// ============================================================================
// lwz r0,-31780(r13); li r3,0; cmpwi r0,0; beq- skip
// mr r3,r0; bl PassiveInfluenceSystem::NotifySimulator
void PassiveInfluenceMap::NotifySimulator(cXPerson* person, int x, int y) {
    // NOTE: The original ignores the 'this' pointer and 'person'/'x'/'y' params,
    // loading the global system pointer from SDA instead and calling through it.
    // This is a static-like dispatch pattern.
    // The actual args are passed through r3 from the SDA load.
    // NON_MATCHING - requires SDA-relative global access pattern
}

// ============================================================================
// PassiveInfluenceMap::ValidateMissing(PassiveInfluenceItem *)
// 0x80113DA8 - 8 bytes
// Always returns true (1) - validation stub
// ============================================================================
// li r3,1; blr
BOOL PassiveInfluenceMap::ValidateMissing(PassiveInfluenceItem* item) {
    return TRUE;
}

// ============================================================================
// PassiveInfluenceSystem::FlushSystem(void)
// 0x80113F04 - 56 bytes
// Checks if this system matches the global, then empties the map
// ============================================================================
// lwz r0,-31780(r13); cmpw r0,r3; bne- skip
// lwz r3,-31784(r13); cmpwi r3,0; beq- skip
// bl PassiveInfluenceMap::EmptyMap
// NON_MATCHING - requires SDA-relative global access
void PassiveInfluenceSystem::FlushSystem(void) {
    // Original checks if 'this' == global system pointer (SDA r13-0x7C24)
    // If so, loads the map pointer (SDA r13-0x7C28) and calls EmptyMap on it
}

// ============================================================================
// PassiveInfluenceSystem::DoStream(ReconBuffer *, int)
// 0x80113F3C - 4 bytes
// Empty no-op (just blr)
// ============================================================================
// blr
void PassiveInfluenceSystem::DoStream(ReconBuffer* buffer, int mode) {
    // empty - passive influence state is not serialized
}

// ============================================================================
// PassiveInfluencePerson::GetObject(void)
// 0x803A8B48 - 8 bytes
// Returns m_object field at offset +0x04
// ============================================================================
// lwz r3,4(r3); blr
cXObject* PassiveInfluencePerson::GetObject(void) {
    return m_object;
}

// ============================================================================
// PassiveInfluencePerson::GetType(void)
// 0x803A8B50 - 8 bytes
// Returns 0 (person type)
// ============================================================================
// li r3,0; blr
int PassiveInfluencePerson::GetType(void) {
    return 0;
}

// ============================================================================
// PassiveInfluencePerson::GetTileVector(void)
// 0x803A8B58 - 8 bytes
// Returns pointer to tile vector at offset +0x08
// ============================================================================
// addi r3,r3,8; blr
EVec3* PassiveInfluencePerson::GetTileVector(void) {
    return (EVec3*)((u8*)this + 0x08);
}

// ============================================================================
// PassiveInfluenceObject::GetObject(void)
// 0x803A8CB0 - 8 bytes
// Returns m_object field at offset +0x04
// ============================================================================
// lwz r3,4(r3); blr
cXObject* PassiveInfluenceObject::GetObject(void) {
    return m_object;
}

// ============================================================================
// PassiveInfluenceObject::GetType(void)
// 0x803A8CB8 - 8 bytes
// Returns 1 (object type)
// ============================================================================
// li r3,1; blr
int PassiveInfluenceObject::GetType(void) {
    return 1;
}

// ============================================================================
// PassiveInfluenceObject::GetTileVector(void)
// 0x803A8CC0 - 8 bytes
// Returns pointer to tile vector at offset +0x08
// ============================================================================
// addi r3,r3,8; blr
EVec3* PassiveInfluenceObject::GetTileVector(void) {
    return (EVec3*)((u8*)this + 0x08);
}

// ============================================================================
// PassiveInfluenceItem::~PassiveInfluenceItem(void)
// 0x803A8D38 - 52 bytes
// Virtual destructor: sets vtable, conditionally deletes
// ============================================================================
// lis r9,0x8046; andi. r0,r4,1; addi r9,r9,0x2318
// stw r9,0(r3); beq- skip; bl __builtin_delete
// NON_MATCHING - vtable address is a link-time constant
PassiveInfluenceItem::~PassiveInfluenceItem(void) {
    // compiler generates: vtable = &PassiveInfluenceItem_vtable;
    // if (__in_charge & 1) __builtin_delete(this);
}

// ============================================================================
// PassiveInfluenceTarget::GetObject(void)
// 0x803A8EE4 - 8 bytes
// Returns m_object field at offset +0x04
// ============================================================================
// lwz r3,4(r3); blr
cXObject* PassiveInfluenceTarget::GetObject(void) {
    return m_object;
}

// ============================================================================
// PassiveInfluenceTarget::GetType(void)
// 0x803A8EEC - 8 bytes
// Returns 2 (target type)
// ============================================================================
// li r3,2; blr
int PassiveInfluenceTarget::GetType(void) {
    return 2;
}

// ============================================================================
// PassiveInfluenceTarget::GetTileVector(void)
// 0x803A8EF4 - 8 bytes
// Returns pointer to tile vector at offset +0x08
// ============================================================================
// addi r3,r3,8; blr
EVec3* PassiveInfluenceTarget::GetTileVector(void) {
    return (EVec3*)((u8*)this + 0x08);
}
