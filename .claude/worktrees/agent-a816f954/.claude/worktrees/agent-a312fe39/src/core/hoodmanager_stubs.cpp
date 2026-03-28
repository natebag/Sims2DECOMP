// hoodmanager_stubs.cpp - Stub implementations for Hoodmanager
// Auto-generated from symbols.json - 11 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8006DDF0 | 216 bytes
void HoodManager::TestMoveInFamily(int, Family *) { }

// 0x8006DEC8 | 192 bytes
void HoodManager::MoveInFamily(int, Family *, bool) { }

// 0x8006DF88 | 396 bytes
void HoodManager::UnmarkFamilyForDeletion(int, Family *) { }

// 0x8006E114 | 584 bytes
void HoodManager::EvictFamilyAndLiquidateAssets(int) { }

// 0x8006E35C | 600 bytes
void HoodManager::EvictFamily(int, bool) { }

// 0x8006E5B4 | 284 bytes
void HoodManager::RemoveAllObjects(int) { }

// 0x8006E6D0 | 1012 bytes
void HoodManager::DemolishCurrentHouse(int) { }

// 0x8006EAC4 | 3388 bytes
void HoodManager::ResetToPristine(void) { }

// 0x8006F800 | 952 bytes
void HoodManager::ResetNeighbors(void) { }

// 0x8006FBB8 | 144 bytes
void HoodManager::GetMatrix(Neighbor *, Neighbor *, RelMatrix **, int *) { }

// 0x8006FEE4 | 660 bytes
void HoodManager::GetRelatedPeople(int, cXPerson *, void *) { }
