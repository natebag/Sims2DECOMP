// morphutilities.cpp - Morph/blend shape utility small functions
// From: morphutilities.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/morphutilities.h"

// ============================================================================
// External references
// ============================================================================

// __builtin_delete (0x802d1220)
extern "C" void __builtin_delete(void* ptr);

// ============================================================================
// MorphUtilities::MorphUtilities(EIStaticModel **)
// 0x80057C18 - 8 bytes
// Constructor: stores model array pointer
// ============================================================================
// stw r4,0(r3); blr
MorphUtilities::MorphUtilities(EIStaticModel** models) {
    m_models = models;
}

// ============================================================================
// MorphUtilities::~MorphUtilities(void)
// 0x80057C20 - 48 bytes
// Destructor: clears model pointer, conditionally deletes
// ============================================================================
// stwu r1,-8(r1); mflr r0; stw r0,12(r1)
// li r0,0; stw r0,0(r3)
// andi. r0,r4,1; beq- skip; bl __builtin_delete
// lwz r0,12(r1); mtlr r0; addi r1,r1,8; blr
// NON_MATCHING - GCC auto-generates the scalar deleting destructor
MorphUtilities::~MorphUtilities(void) {
    m_models = 0;
    // compiler auto-generates: if (__in_charge & 1) __builtin_delete(this);
}
