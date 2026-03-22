// uidrawtable_stubs.cpp - Stub implementations for Uidrawtable
// Auto-generated from symbols.json - 11 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x802737E4 | 168 bytes
UIDrawTable::UIDrawTable(void) { }

// 0x8027388C | 176 bytes
UIDrawTable::~UIDrawTable(void) { }

// 0x8027393C | 204 bytes
void UIDrawTable::AddRecord(int, CBFunctor1<ERC *> &, char *) { }

// 0x80273A08 | 156 bytes
void UIDrawTable::RemoveRecord(int *) { }

// 0x80273AA4 | 256 bytes
void UIDrawTable::InstallEntry(int, CBFunctor1<ERC *> &, char *) { }

// 0x80273BA4 | 84 bytes
void UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &) { }

// 0x80273BF8 | 112 bytes
void UIDrawTable::UnInstallAllName(char *) { }

// 0x80273C9C | 100 bytes
void UIDrawTable::ExecuteDrawsPreFlash(ERC *) { }

// 0x80273D00 | 100 bytes
void UIDrawTable::ExecuteDrawsPostFlash(ERC *) { }

// 0x80273D64 | 52 bytes
UIDrawTable::DrawTableRecord::~DrawTableRecord(void) { }

// 0x80273DD4 | 76 bytes
void UIDrawTable::Shutdown(void) { }
