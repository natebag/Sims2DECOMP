// engctexture_stubs.cpp - Stub implementations for Engctexture
// Auto-generated from symbols.json - 22 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x805295D4 | 68 bytes
ENgcTexture::ENgcTexture(void) { }

// 0x80529618 | 140 bytes
ENgcTexture::~ENgcTexture(void) { }

// 0x805296A4 | 416 bytes
void ENgcTexture::CloneSwizzled(void) { }

// 0x80529844 | 56 bytes
void ENgcTexture::Lock(void) { }

// 0x8052987C | 56 bytes
void ENgcTexture::Unlock(void) { }

// 0x805298B4 | 56 bytes
void ENgcTexture::Invalidate(void) { }

// 0x805298EC | 56 bytes
void ENgcTexture::UpdateBegin(ETextureUpdateType) { }

// 0x80529924 | 56 bytes
void ENgcTexture::UpdateMipLevel(int, int &, int &) { }

// 0x8052995C | 56 bytes
void ENgcTexture::UpdatePalette(void) { }

// 0x80529994 | 56 bytes
void ENgcTexture::UpdatePaletteDeswizzled(void) { }

// 0x805299CC | 56 bytes
void ENgcTexture::UpdateEnd(void) { }

// 0x80529A04 | 460 bytes
void ENgcTexture::Create(ETextureDef &) { }

// 0x80529BD0 | 56 bytes
void ENgcTexture::Select(int, int) { }

// 0x80529C08 | 12 bytes
void ENgcTexture::GetGXTexFmt(void) { }

// 0x80529C14 | 36 bytes
void ENgcTexture::FlushImageMemoryRange(bool) { }

// 0x80529C38 | 56 bytes
void ENgcTexture::GetTEVStageCount(void) { }

// 0x80529C70 | 56 bytes
void ENgcTexture::GetTEXCount(void) { }

// 0x80529CA8 | 68 bytes
void ENgcTexture::ClearTileFlags(void) { }

// 0x80529CEC | 68 bytes
void ENgcTexture::ClearSwizzleFlag(void) { }

// 0x80529D30 | 68 bytes
void ENgcTexture::SetSwizzleFlag(void) { }

// 0x80529D74 | 48 bytes
void* ENgcTexture::operator new(unsigned int) { }

// 0x80529DAC | 44 bytes
void ENgcTexture::operator delete(void *) { }
