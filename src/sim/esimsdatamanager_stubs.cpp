// esimsdatamanager_stubs.cpp - Stub implementations for Esimsdatamanager
// Auto-generated from symbols.json - 14 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x800346D0 | 120 bytes
void ESimsDataManager::compareID(unsigned int &, unsigned int &) { }

// 0x800349D8 | 108 bytes
ESimsDataManager::ESimsDataManager(void) { }

// 0x80034A44 | 140 bytes
ESimsDataManager::~ESimsDataManager(void) { }

// 0x80034AD0 | 132 bytes
void ESimsDataManager::GetLoadProgress(void) { }

// 0x80034B54 | 508 bytes
void ESimsDataManager::AllocateAndLoadResource(EFile *, unsigned int, unsigned int) { }

// 0x80034D50 | 116 bytes
void ESimsDataManager::preloadResources(EEvent &) { }

// 0x80034DC4 | 112 bytes
void ESimsDataManager::incWorkQueued(void) { }

// 0x80034E34 | 192 bytes
void ESimsDataManager::decWorkQueued(void) { }

// 0x80034EF4 | 288 bytes
void ESimsDataManager::LoadSelectorData(ObjSelector *, bool) { }

// 0x80035014 | 300 bytes
void ESimsDataManager::UnloadSelectorData(ObjSelector *, bool) { }

// 0x80035140 | 148 bytes
void ESimsDataManager::undoPreload(ObjSelector *) { }

// 0x800351D4 | 156 bytes
void ESimsDataManager::preload(ObjSelector *) { }

// 0x80035270 | 328 bytes
void ESimsDataManager::QueueCommand(ESim *, unsigned int) { }

// 0x800353B8 | 184 bytes
void ESimsDataManager::FlushCommands(void) { }
