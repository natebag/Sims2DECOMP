// erquickdata_stubs.cpp - Stub implementations for Erquickdata
// Auto-generated from symbols.json - 20 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x804E7E6C | 72 bytes
ERQuickdata::ERQuickdata(void) { }

// 0x804E7EB4 | 96 bytes
ERQuickdata::~ERQuickdata(void) { }

// 0x804E7F14 | 84 bytes
void ERQuickdata::reset(void) { }

// 0x804E7F68 | 4 bytes
void ERQuickdata::UnlockImage(void) { }

// 0x804E7F6C | 4 bytes
void ERQuickdata::LockImage(void) { }

// 0x804E7F70 | 80 bytes
void ERQuickdata::Reload(EFile *) { }

// 0x804E7FC0 | 120 bytes
void ERQuickdata::Load(EFile *, int) { }

// 0x804E8038 | 192 bytes
void ERQuickdata::getTableIndex(int, int, char *) { }

// 0x804E80F8 | 104 bytes
void ERQuickdata::getTable(char *) { }

// 0x804E8160 | 184 bytes
void ERQuickdata::getRowIndex(int, int, char *, char **) { }

// 0x804E8218 | 124 bytes
void ERQuickdata::getRow(void *, char *) { }

// 0x804E8294 | 120 bytes
void ERQuickdata::getStartAddr(int) { }

// 0x804E830C | 260 bytes
void ERQuickdata::findTableIndex(int, int, void *) { }

// 0x804E8410 | 156 bytes
void ERQuickdata::findRow(void *, unsigned int *) { }

// 0x804E84AC | 116 bytes
void ERQuickdata::FindTableName(void *, char **) { }

// 0x804E8520 | 24 bytes
void ERQuickdata::GetRevisionNumber(void) { }

// 0x804E8C54 | 48 bytes
void* ERQuickdata::operator new(unsigned int) { }

// 0x804E8C84 | 44 bytes
void ERQuickdata::operator delete(void *) { }

// 0x804E8CB0 | 8 bytes
void ERQuickdata::GetImage(void) const { }

// 0x804E8CB8 | 8 bytes
void ERQuickdata::GetImageSize(void) const { }
