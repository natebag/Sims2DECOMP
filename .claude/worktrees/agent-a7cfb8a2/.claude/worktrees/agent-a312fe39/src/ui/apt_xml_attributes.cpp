// AptXmlAttributes.cpp - APT ActionScript XML attributes collection
// Source: libaptz.a(AptXmlAttributes.cpp.obj)
// 6 small functions (<=64 bytes) decompiled
//
// All NON_MATCHING due to SN Systems vs GCC codegen differences.

#include "ui/apt_xml.h"
#include "ui/apt_value.h"
#include "ui/apt_types.h"

// External globals
extern AptValueGC_PoolManager* gpGCPoolManager;

// ============================================================================
// AptXmlAttributes::PreDestroy (0x802c4ecc, 12 bytes) NON_MATCHING
// Original:
//   li r0,0 / stw r0,36(r3) / blr
// Nulls out m_ownerNode at offset 0x24 (36 decimal)
// Same pattern as AptXmlNode::PreDestroy
// ============================================================================
void AptXmlAttributes::PreDestroy() {
    *(void**)((u8*)this + 0x24) = 0;
}

// ============================================================================
// AptValueGC::IsGarbageCollected (0x802c4f7c, 8 bytes) NON_MATCHING
// Duplicate instance for AptXmlAttributes TU.
// ============================================================================
// Already defined in apt_value.cpp

// ============================================================================
// AptXmlAttributes::operator new (0x802c4f84, 40 bytes) NON_MATCHING
// Original:
//   mr r4,r3 / lwz r3,-23016(r13) (gpGCPoolManager)
//   bl AptValueGC_PoolManager::AllocateAptValueGC
// ============================================================================
void* AptXmlAttributes::operator new(unsigned int size) {
    return gpGCPoolManager->AllocateAptValueGC(size);
}

// ============================================================================
// AptXmlAttributes::operator delete (0x802c4fac, 48 bytes) NON_MATCHING
// Original:
//   mr r0,r3 / mr r5,r4
//   lwz r3,-23016(r13) (gpGCPoolManager) / mr r4,r0
//   bl AptValueGC_PoolManager::DeallocateAptValueGC
// ============================================================================
void AptXmlAttributes::operator delete(void* ptr, unsigned int size) {
    gpGCPoolManager->DeallocateAptValueGC((AptValueGC*)ptr, size);
}

// ============================================================================
// AptXmlAttributes::operator new[] (0x802c4fdc, 8 bytes) MATCHING
// Original: li r3,0 / blr
// Returns NULL (array allocation not supported)
// ============================================================================
void* AptXmlAttributes::operator new[](unsigned int size) {
    return (void*)0;
}

// ============================================================================
// AptXmlAttributes::operator delete[] (0x802c4fe4, 4 bytes) MATCHING
// Original: blr (no-op)
// ============================================================================
void AptXmlAttributes::operator delete[](void* ptr) {
    // Empty - no-op
}
