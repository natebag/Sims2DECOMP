// reconbuffer_stubs.cpp - Stub implementations for Reconbuffer
// Auto-generated from symbols.json - 16 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x801F0594 | 172 bytes
ReconBuffer::ReconBuffer(void *, int, int, bool) { }

// 0x801F0680 | 124 bytes
ReconBuffer::~ReconBuffer(void) { }

// 0x801F06FC | 252 bytes
void ReconBuffer::UseStringTable(unsigned int, unsigned int, short) { }

// 0x801F07F8 | 12 bytes
void ReconBuffer::EnableCompression(void) { }

// 0x801F0804 | 512 bytes
void ReconBuffer::ReconCmprInt(int *, Scheme *) { }

// 0x801F0A04 | 524 bytes
void ReconBuffer::ReconBits(int, int *) { }

// 0x801F0C10 | 12 bytes
void ReconBuffer::PadBits(void) { }

// 0x801F0C1C | 516 bytes
void ReconBuffer::Recon8(signed char *, int) { }

// 0x801F0E20 | 84 bytes
void ReconBuffer::ReconBool(bool *) { }

// 0x801F0E74 | 568 bytes
void ReconBuffer::Recon16(short *, int) { }

// 0x801F10AC | 32 bytes
void ReconBuffer::ReconInt(int *, int) { }

// 0x801F10CC | 596 bytes
void ReconBuffer::Recon32(int *, int) { }

// 0x801F1320 | 596 bytes
void ReconBuffer::ReconFloat(float *, int) { }

// 0x801F1574 | 268 bytes
void ReconBuffer::ReconMark(void) { }

// 0x801F1680 | 312 bytes
void ReconBuffer::ReadToNextMark(void) { }

// 0x801F17B8 | 424 bytes
void ReconBuffer::ReconString(BString &) { }
