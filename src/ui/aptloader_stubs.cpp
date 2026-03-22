// aptloader_stubs.cpp - Stub implementations for Aptloader
// Auto-generated from symbols.json - 10 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8041CE30 | 168 bytes
void AptLoader::findFile(EAStringC &) { }

// 0x8041CED8 | 108 bytes
AptLoader::~AptLoader(void) { }

// 0x8041CF44 | 260 bytes
void AptLoader::Invalidate(AptFile *) { }

// 0x8041D048 | 104 bytes
void AptLoader::notify(AptSharedPtr<AptFile>) { }

// 0x8041D0B0 | 188 bytes
void AptLoader::IsLoaded(EAStringC &) { }

// 0x8041D16C | 324 bytes
void AptLoader::Load(EAStringC &) { }

// 0x8041D2B0 | 288 bytes
void AptLoader::AllImportsAvailable(AptSharedPtr<AptFile>) { }

// 0x8041D3D0 | 404 bytes
void AptLoader::Update(void) { }

// 0x8041D564 | 204 bytes
void AptLoader::CompleteLoad(AptSharedPtr<AptFile>, void *, void *, void *) { }

// 0x8041D630 | 788 bytes
void AptLoader::CancelPreloadedAnimation(EAStringC &) { }
