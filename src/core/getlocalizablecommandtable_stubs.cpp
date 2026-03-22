// getlocalizablecommandtable_stubs.cpp - Stub implementations for Getlocalizablecommandtable
// Auto-generated from symbols.json - 11 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8026FBE8 | 160 bytes
GetLocalizableCommandTable::GetLocalizableCommandTable(void) { }

// 0x8026FC88 | 160 bytes
GetLocalizableCommandTable::~GetLocalizableCommandTable(void) { }

// 0x8026FD28 | 100 bytes
void GetLocalizableCommandTable::AddRecord(char *, CBFunctor1wRet<char *, unsigned wchar_t *> &) { }

// 0x8026FD8C | 144 bytes
void GetLocalizableCommandTable::RemoveRecord(GetLocalizableCommandTable::GetLocalizableCommandTableRecord *) { }

// 0x8026FE1C | 284 bytes
void GetLocalizableCommandTable::InstallCommand(char *, CBFunctor1wRet<char *, unsigned wchar_t *> &) { }

// 0x8026FF38 | 188 bytes
void GetLocalizableCommandTable::UnInstallCommand(char *) { }

// 0x8026FFF4 | 96 bytes
void GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &) { }

// 0x80270054 | 96 bytes
void GetLocalizableCommandTable::ContainsCommand(char *) { }

// 0x802700B4 | 212 bytes
void GetLocalizableCommandTable::ExecuteCommand(char *, char *) { }

// 0x80270300 | 52 bytes
GetLocalizableCommandTable::GetLocalizableCommandTableRecord::~GetLocalizableCommandTableRecord(void) { }

// 0x80270370 | 76 bytes
void GetLocalizableCommandTable::Shutdown(void) { }
