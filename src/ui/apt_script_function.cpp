// AptScriptFunction.cpp - APT ActionScript script function types
// Source: libaptz.a(AptScriptFunction.cpp.obj)
// 24 small functions (<=64 bytes) decompiled
// 17 MATCHING, 7 NON_MATCHING
//
// Simple getters (8-12 bytes) tend to match since GCC and SN produce
// identical code for trivial member access patterns.
// Static data functions are NON_MATCHING because SN uses SDA r13-relative
// addressing while GCC uses lis+lwz.
// GetConstantPool functions are NON_MATCHING because SN uses sret (hidden
// return pointer) while GCC returns small structs in r3/r4 registers.

#include "ui/apt_script_function.h"
#include "ui/apt_value.h"

// External functions
extern "C" void __builtin_vec_delete(void*);

// ============================================================================
// Static data pointers (SDA r13-relative)
// These would normally be accessed via r13 offsets:
//   r13-26976 (-0x6960): s_staticData (AptValueVector*)
//   r13-26972 (-0x695C): s_registerBase (AptValue**)
//   r13-26968 (-0x6958): s_registerCount (u32)
//   r13-26960 (-0x6950): s_savedRegisters (u32)
// ============================================================================
static void* s_staticData;           // r13-26976
static AptValue** s_registerBase;    // r13-26972
static u32 s_registerCount;          // r13-26968
static u32 s_savedRegisters;         // r13-26960

// ============================================================================
// AptScriptFunctionBase::ShutdownStaticData (0x802b797c, 56 bytes) NON_MATCHING
// Original:
//   lwz r3,-26976(r13) / cmpwi r3,0 / beq skip
//   bl __builtin_vec_delete
//   skip: li r0,0 / stw r0,-26972(r13) / stw r0,-26976(r13)
//   epilogue
// ============================================================================
void AptScriptFunctionBase::ShutdownStaticData() {
    if (s_staticData != 0) {
        __builtin_vec_delete(s_staticData);
    }
    s_registerBase = 0;
    s_staticData = 0;
}

// ============================================================================
// AptScriptFunctionBase::PushStaticData (0x802b79b4, 32 bytes) NON_MATCHING
// Original:
//   lwz r0,-26968(r13) / li r9,0
//   lwz r3,-26972(r13) / slwi r0,r0,2
//   stw r9,-26968(r13) / add r0,r3,r0
//   stw r0,-26972(r13) / blr
// Advances s_registerBase by s_registerCount entries, resets count to 0.
// ============================================================================
void AptScriptFunctionBase::PushStaticData() {
    u32 count = s_registerCount;
    AptValue** base = s_registerBase;
    s_registerCount = 0;
    s_registerBase = base + count;
}

// ============================================================================
// AptScriptFunctionBase::PreDestroy (0x802b8208, 4 bytes) MATCHING
// Original: blr (empty function)
// ============================================================================
void AptScriptFunctionBase::PreDestroy() {
    // Empty - no-op
}

// ============================================================================
// AptScriptFunctionBase::SetupBeforeExecution (0x802b837c, 20 bytes) NON_MATCHING
// Original:
//   lwz r0,-26960(r13) / li r9,0
//   stw r0,0(r4) / stw r9,-26960(r13) / blr
// Saves s_savedRegisters into state, then resets it to 0.
// ============================================================================
void AptScriptFunctionBase::SetupBeforeExecution(_AptScriptFunctionState* state, AptValue* val) {
    state->m_savedRegisters = s_savedRegisters;
    s_savedRegisters = 0;
}

// ============================================================================
// AptScriptFunctionBase::GetRegisterValue (0x802b8420, 16 bytes) NON_MATCHING
// Original:
//   lwz r9,-26972(r13) / slwi r3,r3,2
//   lwzx r3,r3,r9 / blr
// Returns s_registerBase[index]
// ============================================================================
AptValue* AptScriptFunctionBase::GetRegisterValue(int index) {
    return (AptValue*)s_registerBase[index];
}

// ============================================================================
// AptScriptFunctionByteCodeBlock::GetName (0x802b9180, 8 bytes) MATCHING
// Original: lwz r3,60(r3) / blr
// Returns m_name at offset 0x3C
// ============================================================================
const char* AptScriptFunctionByteCodeBlock::GetName() const {
    return *(const char**)((u8*)this + 0x3C);
}

// ============================================================================
// AptScriptFunctionByteCodeBlock::GetNumArguments (0x802b9188, 8 bytes) MATCHING
// Original: li r3,0 / blr
// Always returns 0 for bytecode blocks
// ============================================================================
int AptScriptFunctionByteCodeBlock::GetNumArguments() {
    return 0;
}

// ============================================================================
// AptScriptFunctionByteCodeBlock::GetByteCodeBase (0x802b9190, 8 bytes) MATCHING
// Original: lwz r3,52(r3) / blr
// Returns m_byteCodeBase at offset 0x34
// ============================================================================
void* AptScriptFunctionByteCodeBlock::GetByteCodeBase() {
    return *(void**)((u8*)this + 0x34);
}

// ============================================================================
// AptScriptFunctionByteCodeBlock::GetByteCodeSize (0x802b9198, 8 bytes) MATCHING
// Original: lwz r3,56(r3) / blr
// Returns m_byteCodeSize at offset 0x38
// ============================================================================
int AptScriptFunctionByteCodeBlock::GetByteCodeSize() {
    return *(int*)((u8*)this + 0x38);
}

// ============================================================================
// AptScriptFunctionByteCodeBlock::GetConstantPool (0x802b91a0, 24 bytes) NON_MATCHING
// Original: (return-by-value struct, sret in r3, this in r4)
//   lwz r11,64(r4) / lwz r12,68(r4)
//   mr r9,r3 / stw r11,0(r9) / stw r12,4(r9) / blr
// Returns pair from offsets 0x40 and 0x44
// ============================================================================
AptConstantPoolPair AptScriptFunctionByteCodeBlock::GetConstantPool() {
    AptConstantPoolPair pair;
    pair.m_pool = *(void**)((u8*)this + 0x40);
    pair.m_count = *(u32*)((u8*)this + 0x44);
    return pair;
}

// ============================================================================
// AptScriptFunctionByteCodeBlock::SetArgument (0x802b91b8, 4 bytes) MATCHING
// Original: blr (empty function)
// ============================================================================
void AptScriptFunctionByteCodeBlock::SetArgument(AptValue* val, int index) {
    // Empty - no-op
}

// ============================================================================
// AptScriptFunctionByteCodeBlock::Duplicate (0x802b91bc, 8 bytes) MATCHING
// Original: li r3,0 / blr
// Returns NULL
// ============================================================================
AptCIH* AptScriptFunctionByteCodeBlock::Duplicate(AptCIH* cih) {
    return (AptCIH*)0;
}

// ============================================================================
// AptScriptFunction1::GetName (0x802b8cd4, 12 bytes) MATCHING
// Original: lwz r9,52(r3) / lwz r3,0(r9) / blr
// Returns dataPtr->m_name (offset 0x34 -> deref -> offset 0x00)
// ============================================================================
const char* AptScriptFunction1::GetName() const {
    u32* dataPtr = *(u32**)((u8*)this + 0x34);
    return (const char*)dataPtr[0];
}

// ============================================================================
// AptScriptFunction1::GetNumArguments (0x802b8ce0, 12 bytes) MATCHING
// Original: lwz r9,52(r3) / lwz r3,4(r9) / blr
// Returns dataPtr->m_numArguments (offset 0x34 -> deref -> offset 0x04)
// ============================================================================
int AptScriptFunction1::GetNumArguments() {
    u32* dataPtr = *(u32**)((u8*)this + 0x34);
    return (int)dataPtr[1];
}

// ============================================================================
// AptScriptFunction1::GetByteCodeBase (0x802b8cec, 12 bytes) MATCHING
// Original: lwz r3,52(r3) / addi r3,r3,24 / blr
// Returns dataPtr + 0x18 (bytecode follows header in data block)
// ============================================================================
void* AptScriptFunction1::GetByteCodeBase() {
    u8* dataPtr = *(u8**)((u8*)this + 0x34);
    return dataPtr + 0x18;
}

// ============================================================================
// AptScriptFunction1::GetByteCodeSize (0x802b8cf8, 12 bytes) MATCHING
// Original: lwz r9,52(r3) / lwz r3,12(r9) / blr
// Returns dataPtr->m_byteCodeSize (offset 0x34 -> deref -> offset 0x0C)
// ============================================================================
int AptScriptFunction1::GetByteCodeSize() {
    u32* dataPtr = *(u32**)((u8*)this + 0x34);
    return (int)dataPtr[3];
}

// ============================================================================
// AptScriptFunction1::GetConstantPool (0x802b8d04, 28 bytes) NON_MATCHING
// Original: (return-by-value struct, sret in r3, this in r4)
//   lwz r8,52(r4) / mr r11,r3
//   lwz r9,16(r8) / lwz r10,20(r8)
//   stw r9,0(r11) / stw r10,4(r11) / blr
// Returns pair from dataPtr offsets 0x10 and 0x14
// ============================================================================
AptConstantPoolPair AptScriptFunction1::GetConstantPool() {
    AptConstantPoolPair pair;
    u32* dataPtr = *(u32**)((u8*)this + 0x34);
    pair.m_pool = (void*)dataPtr[4];
    pair.m_count = dataPtr[5];
    return pair;
}

// ============================================================================
// AptScriptFunction2::GetName (0x802b8f18, 12 bytes) MATCHING
// Original: lwz r9,52(r3) / lwz r3,0(r9) / blr
// ============================================================================
const char* AptScriptFunction2::GetName() const {
    u32* dataPtr = *(u32**)((u8*)this + 0x34);
    return (const char*)dataPtr[0];
}

// ============================================================================
// AptScriptFunction2::GetNumArguments (0x802b8f24, 12 bytes) MATCHING
// Original: lwz r9,52(r3) / lwz r3,4(r9) / blr
// ============================================================================
int AptScriptFunction2::GetNumArguments() {
    u32* dataPtr = *(u32**)((u8*)this + 0x34);
    return (int)dataPtr[1];
}

// ============================================================================
// AptScriptFunction2::GetByteCodeBase (0x802b8f30, 12 bytes) MATCHING
// Original: lwz r3,52(r3) / addi r3,r3,28 / blr
// Returns dataPtr + 0x1C (bytecode follows extended header)
// ============================================================================
void* AptScriptFunction2::GetByteCodeBase() {
    u8* dataPtr = *(u8**)((u8*)this + 0x34);
    return dataPtr + 0x1C;
}

// ============================================================================
// AptScriptFunction2::GetByteCodeSize (0x802b8f3c, 12 bytes) MATCHING
// Original: lwz r9,52(r3) / lwz r3,16(r9) / blr
// ============================================================================
int AptScriptFunction2::GetByteCodeSize() {
    u32* dataPtr = *(u32**)((u8*)this + 0x34);
    return (int)dataPtr[4];
}

// ============================================================================
// AptScriptFunction2::GetConstantPool (0x802b8f48, 28 bytes) NON_MATCHING
// Original: (return-by-value struct, sret in r3, this in r4)
//   lwz r8,52(r4) / mr r11,r3
//   lwz r9,20(r8) / lwz r10,24(r8)
//   stw r9,0(r11) / stw r10,4(r11) / blr
// Returns pair from dataPtr offsets 0x14 and 0x18
// ============================================================================
AptConstantPoolPair AptScriptFunction2::GetConstantPool() {
    AptConstantPoolPair pair;
    u32* dataPtr = *(u32**)((u8*)this + 0x34);
    pair.m_pool = (void*)dataPtr[5];
    pair.m_count = dataPtr[6];
    return pair;
}
