// ertquantize_stubs.cpp - Stub implementations for Ertquantize
// Auto-generated from symbols.json - 30 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8046617C | 56 bytes
ERTQuantize::ERTQuantize(void) { }

// 0x804661B4 | 80 bytes
ERTQuantize::~ERTQuantize(void) { }

// 0x80466204 | 80 bytes
void ERTQuantize::Deallocate(void) { }

// 0x80466254 | 592 bytes
void ERTQuantize::Init(unsigned int, unsigned int, void *(*)(unsigned int), void (*)(void *), bool) { }

// 0x80466510 | 56 bytes
void ERTQuantize::TextureAlloc(unsigned int) { }

// 0x80466548 | 52 bytes
void ERTQuantize::TextureFree(void *) { }

// 0x8046657C | 236 bytes
void ERTQuantize::InitializeCube(void) { }

// 0x80466668 | 272 bytes
void ERTQuantize::InitializeNode(unsigned char, unsigned int, ERTQNode *, EVec3 &) { }

// 0x80466778 | 184 bytes
void ERTQuantize::AddPixel(unsigned char *) { }

// 0x80466830 | 104 bytes
void ERTQuantize::FlushAdd(ERTQCacheNode &) { }

// 0x80466898 | 464 bytes
void ERTQuantize::TransformToYuv(unsigned char *, EVec3 &) { }

// 0x80466A68 | 504 bytes
void ERTQuantize::TransformFromYUV(EVec3 &, unsigned char *) { }

// 0x80466C60 | 736 bytes
void ERTQuantize::Classify(EVec3 &, int) { }

// 0x80466F40 | 164 bytes
void ERTQuantize::PruneLevel(ERTQNode *) { }

// 0x80466FE4 | 232 bytes
void ERTQuantize::PruneChild(ERTQNode *) { }

// 0x804670CC | 152 bytes
void ERTQuantize::Compute(void) { }

// 0x80467164 | 144 bytes
void ERTQuantize::Reduction(void) { }

// 0x804671F4 | 220 bytes
void ERTQuantize::Reduce(ERTQNode *) { }

// 0x804672D0 | 292 bytes
void ERTQuantize::MColormap(ERTQNode *) { }

// 0x804673F4 | 8 bytes
void ERTQuantize::GetPaletteSize(void) { }

// 0x804673FC | 8 bytes
void ERTQuantize::GetFullPaletteSize(void) { }

// 0x80467404 | 76 bytes
void ERTQuantize::GetPaletteEntry(int, unsigned char *) { }

// 0x80467450 | 636 bytes
void ERTQuantize::GetClosestColor(unsigned char *) { }

// 0x804676CC | 248 bytes
void ERTQuantize::ClosestColor(ERTQNode *) { }

// 0x804677C4 | 64 bytes
void* ERTQuantize::operator new(unsigned int) { }

// 0x80467804 | 52 bytes
void ERTQuantize::operator delete(void *) { }

// 0x80467838 | 44 bytes
void ERTQuantize::AllocNode(void) { }

// 0x80467864 | 32 bytes
void ERTQuantize::FreeNode(unsigned short) { }

// 0x80467884 | 32 bytes
void ERTQuantize::IndexToNode(unsigned short) { }

// 0x804678A4 | 44 bytes
void ERTQuantize::NodeToIndex(ERTQNode *) { }
