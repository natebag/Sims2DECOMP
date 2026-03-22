// apt_script_colour_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptScriptColour.cpp.obj
// 6 functions, 2872 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// AptScriptColour::AptScriptColour(AptValue *) - 0x802B65F4 | 352 bytes
// ============================================================================
// NON_MATCHING
void AptScriptColour__AptScriptColour(void* self, void* p1) {
    // Stack: 24 bytes
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const

    // Initialize members
    // Object size >= 0x24
}

// ============================================================================
// AptScriptColour::CleanNativeFunctions(void) - 0x802B67BC | 284 bytes
// ============================================================================
// NON_MATCHING
void AptScriptColour__CleanNativeFunctions(void* self) {
    // Stack: 8 bytes
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptScriptColour::objectMemberLookup(AptValue *, EAStringC *) const - 0x802B68D8 | 908 bytes
// ============================================================================
// NON_MATCHING
void AptScriptColour__objectMemberLookup_const(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> strcasecmp
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // Accesses globals via r13 (SDA)

    // Search/lookup
}

// ============================================================================
// AptScriptColour::sMethod_setRGB(AptValue *, int) - 0x802B6C64 | 296 bytes
// ============================================================================
// NON_MATCHING
void AptScriptColour__sMethod_setRGB(void* self, void* p1, int p2) {
    // Stack: 56 bytes
    // -> AptValue::toInteger(void) const
    // -> AptCIH::setProceduralProperty(AptProceduralProperty, float, bool)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptScriptColour::sMethod_getRGB(AptValue *, int) - 0x802B6D8C | 280 bytes
// ============================================================================
// NON_MATCHING
void AptScriptColour__sMethod_getRGB(void* self, void* p1, int p2) {
    // Stack: 24 bytes
    // -> AptCIH::GetProceduralProperty(AptProceduralProperty)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptScriptColour::sMethod_setTransform(AptValue *, int) - 0x802B7500 | 752 bytes
// ============================================================================
// NON_MATCHING
void AptScriptColour__sMethod_setTransform(void* self, void* p1, int p2) {
    // Stack: 40 bytes
    // -> AptNativeHash::Lookup(EAStringC *) const
    // -> AptValue::toInteger(void) const
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Type conversion
}
