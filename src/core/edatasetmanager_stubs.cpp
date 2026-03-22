// edatasetmanager_stubs.cpp - Stub implementations for Edatasetmanager
// Auto-generated from symbols.json - 16 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x804F8634 | 308 bytes
void EDatasetManager::ManageDasFile(char *) { }

// 0x804F8768 | 84 bytes
void EDatasetManager::AddRef(char *, EFile *, int) { }

// 0x804F87EC | 76 bytes
void EDatasetManager::AddRefAsync(char *) { }

// 0x804F8838 | 128 bytes
void EDatasetManager::AddRefAsyncIfNotLoaded(char *) { }

// 0x804F88B8 | 48 bytes
void EDatasetManager::DelRef(EResource *, EResourceManager::DelRefMode) { }

// 0x804F88E8 | 8 bytes
void EDatasetManager::GetLoadProgress(void) const { }

// 0x804F88F0 | 92 bytes
void EDatasetManager::AllocateAndLoadResource(EFile *, unsigned int, unsigned int) { }

// 0x804F894C | 8 bytes
void EDatasetManager::SetLoadProgress(float) { }

// 0x804F8954 | 76 bytes
void EDatasetManager::PreloadResource(char *) { }

// 0x804F89A0 | 60 bytes
void EDatasetManager::GetRef(char *) { }

// 0x804F8A14 | 8 bytes
void EDatasetManager::SetLoadingEnabled(bool) { }

// 0x804F8A1C | 8 bytes
void EDatasetManager::GetLoadingEnabled(void) { }

// 0x804F8A24 | 72 bytes
void EDatasetManager::OutputDatasets(bool) { }

// 0x804F8AE4 | 32 bytes
EDatasetManager::~EDatasetManager(void) { }

// 0x804F8B04 | 72 bytes
EDatasetManager::EDatasetManager(void) { }

// 0x804F8B4C | 8 bytes
void EDatasetManager::CanCache(EResource *) { }
