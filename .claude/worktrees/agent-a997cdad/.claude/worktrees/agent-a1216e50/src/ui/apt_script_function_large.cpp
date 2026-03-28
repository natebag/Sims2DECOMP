// apt_script_function_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptScriptFunction.cpp.obj
// 7 functions, 3472 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// AptScriptFunctionBase::AptScriptFunctionBase(AptVirtualFunctionTable_Indices, AptScriptFunctionBase *, AptCIH *, bool) - 0x802B7A74 | 736 bytes
// ============================================================================
// NON_MATCHING
void AptScriptFunctionBase__AptScriptFunctionBase(void* self, void* p1, void* p2, void* p3, int p4) {
    // Stack: 32 bytes
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // -> AptCIH::getRootAnimation(void)
    // -> _AptGetAnimationAtLevel(int)
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // Accesses globals via r13 (SDA)

    // Initialize members
    // Object size >= 0x6988
}

// ============================================================================
// AptScriptFunctionBase::AptScriptFunctionBase(AptVirtualFunctionTable_Indices, AptScriptFunctionBase *, AptCIH *) - 0x802B7D54 | 596 bytes
// ============================================================================
// NON_MATCHING
void AptScriptFunctionBase__AptScriptFunctionBase(void* self, void* p1, void* p2, void* p3) {
    // Stack: 32 bytes
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // -> AptCIH::getRootAnimation(void)
    // -> _AptGetAnimationAtLevel(int)

    // Initialize members
    // Object size >= 0x5C
}

// ============================================================================
// AptScriptFunction2::SetupBeforeExecution(_AptScriptFunctionState *, AptValue *) - 0x802B84CC | 532 bytes
// ============================================================================
// NON_MATCHING
void AptScriptFunction2__SetupBeforeExecution(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptScriptFunctionBase::SetupBeforeExecution(_AptScriptFunctionState *, AptValue *)
    // -> AptValue::findChild(EAStringC *, AptValue *)
    // -> AptScriptFunctionBase::SetRegisterValue(int, AptValue *)
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// AptScriptFunctionBase::CreateFrameStack(void) - 0x802B8A18 | 344 bytes
// ============================================================================
// NON_MATCHING
void* AptScriptFunctionBase__CreateFrameStack(void* self) {
    // Stack: 24 bytes
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // Accesses globals via r13 (SDA)

    return 0;
}

// ============================================================================
// AptScriptFunctionBase::CreatingNestedFunction(void) - 0x802B8B70 | 356 bytes
// ============================================================================
// NON_MATCHING
void AptScriptFunctionBase__CreatingNestedFunction(void* self) {
    // Stack: 24 bytes
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptScriptFunction1::SetArgument(AptValue *, int) - 0x802B8D20 | 436 bytes
// ============================================================================
// NON_MATCHING
void AptScriptFunction1__SetArgument(void* self, void* p1, int p2) {
    // Stack: 40 bytes
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // -> EAStringC::EAStringC(char *)
    // -> AptNativeHash::Set(EAStringC *, AptValue *)
    // -> EAStringC::~EAStringC(void)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// AptScriptFunction2::SetArgument(AptValue *, int) - 0x802B8F64 | 472 bytes
// ============================================================================
// NON_MATCHING
void AptScriptFunction2__SetArgument(void* self, void* p1, int p2) {
    // Stack: 40 bytes
    // -> AptScriptFunctionBase::SetRegisterValue(int, AptValue *)
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // -> EAStringC::EAStringC(char *)
    // -> AptNativeHash::Set(EAStringC *, AptValue *)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}
