// eresourcemanager_stubs.cpp - Stub implementations for Eresourcemanager
// Auto-generated from symbols.json - 51 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x804FA584 | 108 bytes
EResourceManager::EResourceManager(void) { }

// 0x804FA5F0 | 160 bytes
EResourceManager::~EResourceManager(void) { }

// 0x804FA690 | 144 bytes
void EResourceManager::Shutdown(void) { }

// 0x804FA720 | 920 bytes
void EResourceManager::Init(char *) { }

// 0x804FAAB8 | 232 bytes
void EResourceManager::CalcPath(void) { }

// 0x804FABA0 | 372 bytes
void EResourceManager::GetArchiveFile(void) { }

// 0x804FAD14 | 164 bytes
void EResourceManager::ArchiveFileIsUsingHDD(void) { }

// 0x804FADB8 | 124 bytes
void EResourceManager::ArchiveFileIsOpen(void) { }

// 0x804FAE34 | 100 bytes
void EResourceManager::CloseArchiveFile(void) { }

// 0x804FAE98 | 100 bytes
void EResourceManager::BinarySearch(unsigned int, unsigned int *, int) { }

// 0x804FAEFC | 144 bytes
void EResourceManager::LookupId(unsigned int, unsigned int &, unsigned int &) { }

// 0x804FAF8C | 808 bytes
void EResourceManager::AddRefAll(void) { }

// 0x804FB2B4 | 828 bytes
void EResourceManager::AddDelRefAll(void) { }

// 0x804FB5F0 | 116 bytes
void EResourceManager::DelRefAll(void) { }

// 0x804FB664 | 112 bytes
void EResourceManager::PrintLoadedResources(void) { }

// 0x804FB6D4 | 112 bytes
void EResourceManager::PrintResourceSizes(void) { }

// 0x804FB744 | 216 bytes
void EResourceManager::PrintUnmanagedResources(void) { }

// 0x804FB81C | 260 bytes
void EResourceManager::GetRef(unsigned int) { }

// 0x804FB95C | 88 bytes
void EResourceManager::ReadData(void *, unsigned int, unsigned int) { }

// 0x804FB9B4 | 180 bytes
void EResourceManager::PreloadResource(unsigned int) { }

// 0x804FBAA4 | 568 bytes
void EResourceManager::addRef(unsigned int, EFile *, unsigned int, bool) { }

// 0x804FBCDC | 388 bytes
void EResourceManager::TryIncrementResource(unsigned int, EResource **) { }

// 0x804FBE60 | 96 bytes
void EResourceManager::IsResourceIncludedInLog(char *) { }

// 0x804FBEC0 | 36 bytes
void EResourceManager::AddResource(EResource *, unsigned int) { }

// 0x804FBEE4 | 128 bytes
void EResourceManager::LogResourceLoad(EResource *) { }

// 0x804FC0C0 | 36 bytes
void EResourceManager::AddRef(unsigned int, EFile *, int) { }

// 0x804FC134 | 72 bytes
void EResourceManager::AddRefAsync(char *) { }

// 0x804FC1A8 | 28 bytes
void EResourceManager::GetIds(unsigned int *&, int &) { }

// 0x804FC1C4 | 36 bytes
void EResourceManager::RefreshResources(void) { }

// 0x804FC1E8 | 112 bytes
void EResourceManager::Refresh(EResource *) { }

// 0x804FC398 | 188 bytes
void EResourceManager::DelRef(unsigned int, int) { }

// 0x804FC498 | 60 bytes
void EResourceManager::DelRefAsync(char *) { }

// 0x804FC77C | 116 bytes
void EResourceManager::Detach(EResource *) { }

// 0x804FC7F0 | 56 bytes
void EResourceManager::GetPos(unsigned int) { }

// 0x804FC828 | 132 bytes
void EResourceManager::GetSize(unsigned int) { }

// 0x804FC8AC | 48 bytes
void EResourceManager::IsValid(unsigned int) { }

// 0x804FC8DC | 128 bytes
void EResourceManager::IsLoaded(unsigned int) { }

// 0x804FC998 | 4 bytes
void EResourceManager::ResourceDestructing(EResource *) { }

// 0x804FC99C | 88 bytes
void EResourceManager::CalcId(char *) { }

// 0x804FC9F4 | 248 bytes
void EResourceManager::PushLoggingOutput(char *) { }

// 0x804FCAEC | 280 bytes
void EResourceManager::PopLoggingOutput(void) { }

// 0x804FCC04 | 488 bytes
void EResourceManager::SetLoggingOutput(char *, bool) { }

// 0x804FCDEC | 32 bytes
void EResourceManager::GetHeap(void) { }

// 0x804FCE0C | 72 bytes
void EResourceManager::MakeSpace(void) { }

// 0x804FCE54 | 60 bytes
void EResourceManager::FreeUnreferencedResources(void) { }

// 0x804FCE90 | 36 bytes
void EResourceManager::GetUnreferencedResourceCount(void) { }

// 0x804FCEB4 | 164 bytes
void EResourceManager::Alloc(unsigned long, unsigned int) { }

// 0x804FCF58 | 80 bytes
void EResourceManager::Free(void *) { }

// 0x804FCFA8 | 164 bytes
void EResourceManager::GetOverriddenFile(unsigned int, unsigned int &) { }

// 0x80500574 | 8 bytes
void EResourceManager::CanCache(void) { }

// 0x805005D0 | 24 bytes
void EResourceManager::ResourceIndexRecord::CheckPos(int &, int &) { }
