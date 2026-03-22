// aptextobject_stubs.cpp - Stub implementations for Aptextobject
// Auto-generated from symbols.json - 21 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8043AC40 | 116 bytes
void AptExtObject::SetFunction(char *, AptNativeFunction *) { }

// 0x8043ACB4 | 100 bytes
AptExtObject::AptExtObject(int) { }

// 0x8043AD18 | 112 bytes
AptExtObject::~AptExtObject(void) { }

// 0x8043AD88 | 40 bytes
void AptExtObject::objectMemberLookup(AptValue *, EAStringC *) const { }

// 0x8043ADB0 | 48 bytes
void AptExtObject::objectMemberSet(AptValue *, EAStringC *, AptValue *) { }

// 0x8043ADE0 | 8 bytes
void AptExtObject::GetNativeHashVirtual(void) { }

// 0x8043ADE8 | 8 bytes
void AptExtObject::ContainsNativeHashVirtual(void) const { }

// 0x8043ADF0 | 40 bytes
void AptExtObject::RegisterReferences(void) const { }

// 0x8043AE18 | 36 bytes
void AptExtObject::DestroyGCPointers(void) { }

// 0x8043AE3C | 36 bytes
void AptExtObject::Lookup(EAStringC *) const { }

// 0x8043AE60 | 36 bytes
void AptExtObject::Set(EAStringC *, AptValue *) { }

// 0x8043AE84 | 48 bytes
void* AptExtObject::operator new(unsigned int) { }

// 0x8043AEB4 | 48 bytes
void AptExtObject::operator delete(void *, unsigned int) { }

// 0x8043AF3C | 8 bytes
void AptExtObject::IsGarbageCollected(void) const { }

// 0x8043AF44 | 8 bytes
void AptExtObject::GetSize(void) const { }

// 0x8043AF4C | 60 bytes
void AptExtObject::GetParam(int) { }

// 0x8043AF88 | 8 bytes
void AptExtObject::GetUndefinedValue(void) { }

// 0x8043AF90 | 120 bytes
void AptExtObject::CreateNewAptObject(void) { }

// 0x8043B084 | 128 bytes
void AptExtObject::CreateNewAptFunction(void *) { }

// 0x8043B104 | 88 bytes
void AptExtObject::GetVariable(AptValue *, EAStringC *) { }

// 0x8043B15C | 72 bytes
void AptExtObject::SetVariable(AptValue *, EAStringC *, AptValue *) { }
