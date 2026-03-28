// influencemap.cpp - Influence map small functions
// From: influencemap.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/influencemap.h"

// ============================================================================
// ObjectList::ObjectList(void)
// 0x80048570 - 32 bytes
// Default constructor: zeroes out all 3 fields
// ============================================================================
// stwu r1,-16(r1); li r0,0; addi r9,r3,8
// stw r0,0(r3); stw r0,4(r3); stw r0,4(r9)
// addi r1,r1,16; blr
// NON_MATCHING - GCC omits stack frame for leaf function; original allocates 16-byte frame
ObjectList::ObjectList(void) {
    m_count = 0;
    m_capacity = 0;
    m_data = 0;
}

// ============================================================================
// InfluenceMap::ValidateMissing(cXObject *)
// 0x800492E0 - 8 bytes
// Always returns true (1) - validation stub
// ============================================================================
// li r3,1; blr
BOOL InfluenceMap::ValidateMissing(cXObject* obj) {
    return TRUE;
}
