// apt_xml_node_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptXmlNode.cpp.obj
// 4 functions, 1616 bytes

#include "types.h"

// ============================================================================
// AptXmlNode::CleanNativeFunctions(void) - 0x802BA4AC | 412 bytes
// ============================================================================
// NON_MATCHING
void AptXmlNode__CleanNativeFunctions(void* self) {
    // Stack: 8 bytes
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptXmlNode::objectMemberSet(AptValue *, EAStringC *, AptValue *) - 0x802BA648 | 472 bytes
// ============================================================================
// NON_MATCHING
void AptXmlNode__objectMemberSet(void* self, void* p1, void* p2, void* p3) {
    // Stack: 32 bytes
    // -> strcasecmp
    // -> AptValue::toString(EAStringC &) const
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// AptXmlNode::sMethod_hasChildNodes(AptValue *, int) - 0x802BB348 | 396 bytes
// ============================================================================
// NON_MATCHING
void AptXmlNode__sMethod_hasChildNodes(void* self, void* p1, int p2) {
    // Stack: 16 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptXmlNode::sMethod_toString(AptValue *, int) - 0x802BB4E4 | 336 bytes
// ============================================================================
// NON_MATCHING
void AptXmlNode__sMethod_toString(void* self, void* p1, int p2) {
    // Stack: 32 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> EAStringC::EAStringC(char *)
    // -> EAStringC::operator=(EAStringC &)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

}
