// uiupdatetable_stubs.cpp - Stub implementations for Uiupdatetable
// Auto-generated from symbols.json - 13 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8027DABC | 168 bytes
UIUpdateTable::UIUpdateTable(void) { }

// 0x8027DB64 | 176 bytes
UIUpdateTable::~UIUpdateTable(void) { }

// 0x8027DC14 | 204 bytes
void UIUpdateTable::AddRecord(UIUpdateTable::UpdateTablePriority, CBFunctor0 &, char *) { }

// 0x8027DCE0 | 156 bytes
void UIUpdateTable::RemoveRecord(UIUpdateTable::UpdateTableRecord *) { }

// 0x8027DD7C | 256 bytes
void UIUpdateTable::InstallEntry(UIUpdateTable::UpdateTablePriority, CBFunctor0 &, char *) { }

// 0x8027DE7C | 84 bytes
void UIUpdateTable::UnInstallEntry(CBFunctor0 &) { }

// 0x8027DED0 | 112 bytes
void UIUpdateTable::UnInstallAllName(char *) { }

// 0x8027DF40 | 52 bytes
void UIUpdateTable::ContainsEntry(CBFunctor0 &) { }

// 0x8027DF74 | 100 bytes
void UIUpdateTable::ExecuteUpdatesPreFlash(void) { }

// 0x8027DFD8 | 92 bytes
void UIUpdateTable::ExecuteUpdatesPostFlash(void) { }

// 0x8027E034 | 52 bytes
UIUpdateTable::UpdateTableRecord::~UpdateTableRecord(void) { }

// 0x8027E068 | 60 bytes
void UIUpdateTable::Instance(void) { }

// 0x8027E0A4 | 76 bytes
void UIUpdateTable::Shutdown(void) { }
