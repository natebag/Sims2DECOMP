// eresource_stubs.cpp - Stub implementations for Eresource
// Auto-generated from symbols.json - 36 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x804DB13C | 152 bytes
EResource::EResource(void) { }

// 0x804DB1D4 | 212 bytes
EResource::~EResource(void) { }

// 0x804DB2A8 | 84 bytes
void EResource::Write(EStream &) { }

// 0x804DB368 | 108 bytes
void EResource::Load(EFile &) { }

// 0x804DB3D4 | 104 bytes
void EResource::DelRef(void) { }

// 0x804DB43C | 40 bytes
void EResource::Detach(void) { }

// 0x804DB464 | 64 bytes
void EResource::AddRef(void) { }

// 0x804DB4A4 | 48 bytes
void EResource::Refresh(void) { }

// 0x804DB8F4 | 40 bytes
void EResource::New(void) { }

// 0x804DB91C | 44 bytes
void EResource::Construct(EResource *) { }

// 0x804DB948 | 36 bytes
void EResource::Destruct(EResource *) { }

// 0x804DB96C | 64 bytes
void EResource::SafeDelete(void) { }

// 0x804DB9B8 | 12 bytes
void EResource::GetTypeName(void) const { }

// 0x804DB9C4 | 12 bytes
void EResource::GetTypeKey(void) const { }

// 0x804DB9D0 | 12 bytes
void EResource::GetTypeVersion(void) const { }

// 0x804DB9E8 | 12 bytes
void EResource::GetReadVersion(void) { }

// 0x804DB9F4 | 84 bytes
void EResource::RegisterType(unsigned short) { }

// 0x804DBA48 | 32 bytes
void EResource::CreateCopy(void) const { }

// 0x804DBA68 | 24 bytes
void EResource::IsManaged(void) const { }

// 0x804DBA80 | 8 bytes
void EResource::IsSafeToDelete(void) { }

// 0x804DBA88 | 8 bytes
void EResource::GetResId(void) const { }

// 0x804DBA90 | 8 bytes
void EResource::SetResId(unsigned int) { }

// 0x804DBA98 | 8 bytes
void EResource::GetNumRefs(void) { }

// 0x804DBAA0 | 16 bytes
void EResource::SetResSize(unsigned int) { }

// 0x804DBAB0 | 12 bytes
void EResource::GetResSize(void) { }

// 0x804DBABC | 36 bytes
void EResource::SetResName(char *) { }

// 0x804DBAE0 | 8 bytes
void EResource::GetResName(void) { }

// 0x804DBAE8 | 8 bytes
void EResource::SetCheckPoint(unsigned int) { }

// 0x804DBAF0 | 8 bytes
void EResource::GetCheckPoint(void) { }

// 0x804DBAF8 | 56 bytes
void* EResource::operator new(unsigned int) { }

// 0x804DBB38 | 52 bytes
void EResource::operator delete(void *) { }

// 0x804DBB6C | 4 bytes
void EResource::Init(void) { }

// 0x804DBB74 | 4 bytes
void EResource::DelRefSubResources(void) { }

// 0x804DBB78 | 4 bytes
void EResource::AddRefSubResources(void) { }

// 0x804DBB7C | 8 bytes
void EResource::TryIncrementSubResources(void) { }

// 0x804DBB84 | 4 bytes
void EResource::DetachClone(void) { }
