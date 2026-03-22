// erfont_stubs.cpp - Stub implementations for Erfont
// Auto-generated from symbols.json - 34 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x804DD864 | 128 bytes
ERFont::ERFont(void) { }

// 0x804DD8E4 | 104 bytes
ERFont::~ERFont(void) { }

// 0x804DD94C | 68 bytes
void ERFont::Deallocate(void) { }

// 0x804DD990 | 268 bytes
void ERFont::Load(EFile &) { }

// 0x804DDA9C | 368 bytes
void ERFont::SetSize(float, float, bool) { }

// 0x804DDC0C | 240 bytes
void ERFont::SelectPage(ERC *, int) { }

// 0x804DDE18 | 3740 bytes
void ERFont::DoDraw(void *, bool, bool, bool, EVec2 &, ERC *, EVec2 *, EWindow *, EMat4 *, EVec2 *, EFontMatrixType, fontFXcommand *) { }

// 0x804DECB4 | 3904 bytes
void ERFont::DoDrawNormalize(void *, bool, bool, bool, EVec2 &, ERC *, EVec2 *, EWindow *, EMat4 *, EVec2 *, EFontMatrixType, fontFXcommand *) { }

// 0x804DFBF4 | 212 bytes
void ERFont::DoGetStringSize(void *, bool, bool, EWindow *) { }

// 0x804DFCC8 | 184 bytes
void ERFont::SnapPosToPixel(EVec2 &, bool, bool, EWindow *) { }

// 0x804DFD80 | 380 bytes
void ERFont::SnapPosToPixelNormalize(EVec2 &, bool, bool, EWindow *) { }

// 0x804DFEFC | 676 bytes
void ERFont::DoDrawAlign(ERC *, void *, bool, EVec2, EFontAlignX, EFontAlignY, EVec2 *, EMat4 *, EFontMatrixType, fontFXcommand *, bool) { }

// 0x804E01A0 | 372 bytes
void ERFont::Draw(ERC *, char *, EVec2 &, EFontAlignX, EFontAlignY, EVec2 *, EMat4 *, EFontMatrixType, fontFXcommand *, bool) { }

// 0x804E0314 | 580 bytes
void ERFont::DrawDs(ERC *, char *, EVec2 &, EFontAlignX, EFontAlignY, EVec2 *, float, float, bool) { }

// 0x804E079C | 140 bytes
void ERFont::LoadFont(void) { }

// 0x804E0828 | 52 bytes
void ERFont::Select(ERC *) { }

// 0x804E085C | 324 bytes
void ERFont::GetLineSpacing(EWindow *, bool) { }

// 0x804E09A0 | 1760 bytes
void ERFont::ProcessFontFX(fontFXcommand *, EMat4 *, int) { }

// 0x804E146C | 40 bytes
void ERFont::New(void) { }

// 0x804E1494 | 44 bytes
void ERFont::Construct(ERFont *) { }

// 0x804E14C0 | 36 bytes
void ERFont::Destruct(ERFont *) { }

// 0x804E14E4 | 64 bytes
void ERFont::SafeDelete(void) { }

// 0x804E1530 | 12 bytes
void ERFont::GetTypeName(void) const { }

// 0x804E153C | 12 bytes
void ERFont::GetTypeKey(void) const { }

// 0x804E1548 | 12 bytes
void ERFont::GetTypeVersion(void) const { }

// 0x804E1560 | 12 bytes
void ERFont::GetReadVersion(void) { }

// 0x804E156C | 84 bytes
void ERFont::RegisterType(unsigned short) { }

// 0x804E15C0 | 32 bytes
void ERFont::CreateCopy(void) const { }

// 0x804E15E0 | 64 bytes
void* ERFont::operator new(unsigned int) { }

// 0x804E1628 | 52 bytes
void ERFont::operator delete(void *) { }

// 0x804E165C | 8 bytes
void ERFont::GetYSize(void) { }

// 0x804E1664 | 8 bytes
void ERFont::GetAspect(void) { }

// 0x804E166C | 56 bytes
void ERFont::GetStringSize(char *, EWindow *, bool) { }

// 0x804E16DC | 40 bytes
void ERFont::SetColor(EVec4 &) { }
