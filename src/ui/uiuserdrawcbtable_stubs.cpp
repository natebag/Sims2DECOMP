// uiuserdrawcbtable_stubs.cpp - Stub implementations for Uiuserdrawcbtable
// Auto-generated from symbols.json - 12 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8027E0F0 | 164 bytes
UIUserDrawCBTable::UIUserDrawCBTable(void) { }

// 0x8027E194 | 176 bytes
UIUserDrawCBTable::~UIUserDrawCBTable(void) { }

// 0x8027E244 | 104 bytes
void UIUserDrawCBTable::AddRecord(char *, CBFunctor2<ERC *, structDrawCBparams *> *, char *) { }

// 0x8027E2AC | 204 bytes
void UIUserDrawCBTable::RemoveRecord(UIUserDrawCBTable::UserDrawCBTableRecord *) { }

// 0x8027E378 | 280 bytes
void UIUserDrawCBTable::InstallEntry(char *, CBFunctor2<ERC *, structDrawCBparams *> *, char *) { }

// 0x8027E490 | 68 bytes
void UIUserDrawCBTable::UnInstallEntry(char *) { }

// 0x8027E4D4 | 112 bytes
void UIUserDrawCBTable::UnInstallAllName(char *) { }

// 0x8027E544 | 92 bytes
void UIUserDrawCBTable::FindEntry(char *) { }

// 0x8027E5A0 | 180 bytes
void UIUserDrawCBTable::ExecuteCallback(ERC *, char *) { }

// 0x8027E654 | 52 bytes
UIUserDrawCBTable::UserDrawCBTableRecord::~UserDrawCBTableRecord(void) { }

// 0x8027E688 | 60 bytes
void UIUserDrawCBTable::Instance(void) { }

// 0x8027E6C4 | 76 bytes
void UIUserDrawCBTable::Shutdown(void) { }
