// AptXmlNode.cpp - APT ActionScript XMLNode type
// Source: libaptz.a(AptXmlNode.cpp.obj)
// 12 small functions (<=64 bytes) decompiled
//
// All NON_MATCHING due to SN Systems vs GCC codegen differences.

#include "ui/apt_xml.h"
#include "ui/apt_value.h"
#include "ui/apt_types.h"

// External globals
extern AptValue* gpUndefinedValue;
extern AptValueGC_PoolManager* gpGCPoolManager;

// ============================================================================
// AptXmlNode::PreDestroy (0x802ba42c, 12 bytes) NON_MATCHING
// Original:
//   li r0,0 / stw r0,36(r3) / blr
// Nulls out m_nativeNode at offset 0x24 (36 decimal)
// ============================================================================
void AptXmlNode::PreDestroy() {
    *(void**)((u8*)this + 0x24) = 0;
}

// ============================================================================
// AptXmlNode::sMethod_appendChild (0x802bb338, 8 bytes) NON_MATCHING
// Original: lwz r3,-22936(r13) / blr
// Returns gpUndefinedValue (stub - not implemented)
// ============================================================================
AptValue* AptXmlNode::sMethod_appendChild(AptValue* thisObj, int argc) {
    return gpUndefinedValue;
}

// ============================================================================
// AptXmlNode::sMethod_cloneNode (0x802bb340, 8 bytes) NON_MATCHING
// Original: lwz r3,-22936(r13) / blr
// Returns gpUndefinedValue (stub - not implemented)
// ============================================================================
AptValue* AptXmlNode::sMethod_cloneNode(AptValue* thisObj, int argc) {
    return gpUndefinedValue;
}

// ============================================================================
// AptXmlNode::sMethod_insertBefore (0x802bb4d4, 8 bytes) NON_MATCHING
// Original: lwz r3,-22936(r13) / blr
// Returns gpUndefinedValue (stub - not implemented)
// ============================================================================
AptValue* AptXmlNode::sMethod_insertBefore(AptValue* thisObj, int argc) {
    return gpUndefinedValue;
}

// ============================================================================
// AptXmlNode::sMethod_removeNode (0x802bb4dc, 8 bytes) NON_MATCHING
// Original: lwz r3,-22936(r13) / blr
// Returns gpUndefinedValue (stub - not implemented)
// ============================================================================
AptValue* AptXmlNode::sMethod_removeNode(AptValue* thisObj, int argc) {
    return gpUndefinedValue;
}

// ============================================================================
// AptValueGC::IsGarbageCollected (0x802bb634, 8 bytes) NON_MATCHING
// Duplicate instance for AptXmlNode TU.
// ============================================================================
// Already defined in apt_value.cpp

// ============================================================================
// AptXmlNode::operator new (0x802bb63c, 40 bytes) NON_MATCHING
// Original:
//   mr r4,r3 / lwz r3,-23016(r13) (gpGCPoolManager)
//   bl AptValueGC_PoolManager::AllocateAptValueGC
// ============================================================================
void* AptXmlNode::operator new(unsigned int size) {
    return gpGCPoolManager->AllocateAptValueGC(size);
}

// ============================================================================
// AptXmlNode::operator delete (0x802bb664, 48 bytes) NON_MATCHING
// Original:
//   mr r0,r3 / mr r5,r4
//   lwz r3,-23016(r13) (gpGCPoolManager) / mr r4,r0
//   bl AptValueGC_PoolManager::DeallocateAptValueGC
// ============================================================================
void AptXmlNode::operator delete(void* ptr, unsigned int size) {
    gpGCPoolManager->DeallocateAptValueGC((AptValueGC*)ptr, size);
}

// ============================================================================
// AptXmlNode::operator new[] (0x802bb694, 8 bytes) MATCHING
// Original: li r3,0 / blr
// Returns NULL (array allocation not supported)
// ============================================================================
void* AptXmlNode::operator new[](unsigned int size) {
    return (void*)0;
}

// ============================================================================
// AptXmlNode::operator delete[] (0x802bb69c, 4 bytes) MATCHING
// Original: blr (no-op)
// ============================================================================
void AptXmlNode::operator delete[](void* ptr) {
    // Empty - no-op
}
