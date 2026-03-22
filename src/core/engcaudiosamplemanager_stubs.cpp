// engcaudiosamplemanager_stubs.cpp - Stub implementations for Engcaudiosamplemanager
// Auto-generated from symbols.json - 15 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8050573C | 68 bytes
ENgcAudioSampleManager::ENgcAudioSampleManager(void) { }

// 0x80505780 | 48 bytes
ENgcAudioSampleManager::~ENgcAudioSampleManager(void) { }

// 0x805057B0 | 60 bytes
void ENgcAudioSampleManager::Init(char *) { }

// 0x805057EC | 32 bytes
void ENgcAudioSampleManager::Shutdown(void) { }

// 0x8050580C | 36 bytes
void ENgcAudioSampleManager::CanCache(EResource *) { }

// 0x80505830 | 504 bytes
void ENgcAudioSampleManager::AllocateAndLoadResource(EFile *, unsigned int, unsigned int) { }

// 0x80505A28 | 68 bytes
void ENgcAudioSampleManager::OnDelRef(ERSampledata *) { }

// 0x80505B04 | 476 bytes
void ENgcAudioSampleManager::heapInit(void) { }

// 0x80505CE0 | 408 bytes
void ENgcAudioSampleManager::heapAlloc(unsigned int) { }

// 0x80505E78 | 200 bytes
void ENgcAudioSampleManager::heapResortSmaller(ARAMBlock *) { }

// 0x80505F40 | 216 bytes
void ENgcAudioSampleManager::heapResortLarger(ARAMBlock *) { }

// 0x80506018 | 52 bytes
void ENgcAudioSampleManager::heapFindBlock(unsigned int) const { }

// 0x8050604C | 52 bytes
void ENgcAudioSampleManager::heapIsFreeBlock(ARAMBlock *) const { }

// 0x80506080 | 336 bytes
void ENgcAudioSampleManager::heapFree(unsigned int) { }

// 0x805061D0 | 292 bytes
void ENgcAudioSampleManager::heapWalk(bool) const { }
