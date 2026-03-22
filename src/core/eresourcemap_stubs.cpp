// eresourcemap_stubs.cpp - Stub implementations for Eresourcemap
// Auto-generated from symbols.json - 21 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x804FD458 | 32 bytes
EResourceMap::EResourceMap(void) { }

// 0x804FD478 | 64 bytes
EResourceMap::~EResourceMap(void) { }

// 0x804FD4B8 | 76 bytes
void EResourceMap::Search(unsigned int) { }

// 0x804FD504 | 116 bytes
void EResourceMap::Find(unsigned int, EResource **) { }

// 0x804FD578 | 124 bytes
void EResourceMap::SetCapacity(int, char *) { }

// 0x804FD5F4 | 452 bytes
void EResourceMap::Insert(EResourceManager *, unsigned int, EResource *, char *) { }

// 0x804FD7B8 | 212 bytes
void EResourceMap::Remove(unsigned int) { }

// 0x804FD88C | 8 bytes
void EResourceMap::GetSize(void) { }

// 0x804FD894 | 16 bytes
void EResourceMap::IsEmpty(void) { }

// 0x804FD8A4 | 88 bytes
void EResourceMap::RemoveAll(void) { }

// 0x804FD8FC | 396 bytes
void EResourceMap::PrintLoadedResources(char *) { }

// 0x804FDA88 | 236 bytes
void EResourceMap::PrintResourceSizes(char *) { }

// 0x804FDB74 | 220 bytes
void EResourceMap::RefreshResources(void) { }

// 0x804FDC50 | 304 bytes
void EResourceMap::BuildResourceList(vector<int, allocator<int> > &) { }

// 0x804FDD80 | 284 bytes
void EResourceMap::GetPrevResourceID(int) { }

// 0x804FDE9C | 288 bytes
void EResourceMap::GetNextResourceID(int) { }

// 0x804FDFBC | 16 bytes
void EResourceMap::GetResourceID(int) { }

// 0x804FDFCC | 8 bytes
void EResourceMap::GetNumEntries(void) { }

// 0x804FDFD4 | 8 bytes
void EResourceMap::GetMaxEntries(void) { }

// 0x804FDFDC | 8 bytes
void EResourceMap::GetMaxLoaded(void) { }

// 0x804FDFE4 | 8 bytes
void EResourceMap::GetMaxUsed(void) { }
