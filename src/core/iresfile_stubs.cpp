// iresfile_stubs.cpp - Stub implementations for Iresfile
// Auto-generated from symbols.json - 6 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x801F43EC | 80 bytes
iResFile::iResFile(void) { }

// 0x801F443C | 76 bytes
iResFile::~iResFile(void) { }

// 0x801F4498 | 128 bytes
void iResFile::Release(int *) { }

// 0x801F4518 | 232 bytes
void iResFile::Open(StringBuffer &, int) { }

// 0x801F463C | 120 bytes
void iResFile::AddWithLanguage(int *, int, short, StringBuffer &, char, bool) { }

// 0x801F46B4 | 88 bytes
void iResFile::GetByIDAndLanguage(int, short, char, void (*)(void *, int)) { }
