// engcaram_stubs.cpp - Stub implementations for Engcaram
// Auto-generated from symbols.json - 8 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x805423A0 | 176 bytes
void ENgcAram::Open(void) { }

// 0x80542450 | 24 bytes
void ENgcAram::Close(void) { }

// 0x80542468 | 68 bytes
void ENgcAram::Allocate(unsigned int) { }

// 0x805424AC | 20 bytes
void ENgcAram::AvailableMemory(void) { }

// 0x805424C0 | 148 bytes
void ENgcAram::SequentialLoadToARAM(void *, unsigned int, unsigned int) { }

// 0x80542560 | 248 bytes
void ENgcAram::AsyncLoadToARAM(void *, unsigned int, unsigned int, void (*)(unsigned int), unsigned int) { }

// 0x805426F4 | 148 bytes
void ENgcAram::SequentialLoadFromARAM(void *, unsigned int, unsigned int) { }

// 0x80542794 | 248 bytes
void ENgcAram::AsyncLoadFromARAM(void *, unsigned int, unsigned int, void (*)(unsigned int), unsigned int) { }
