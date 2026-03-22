// cuipane_stubs.cpp - Stub implementations for Cuipane
// Auto-generated from symbols.json - 24 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x804AE97C | 104 bytes
CUIPane::CUIPane(void) { }

// 0x804AE9E4 | 88 bytes
void CUIPane::Thread(CUIWindow *, CUIPane *, bool) { }

// 0x804AEA3C | 92 bytes
void CUIPane::Unthread(void) { }

// 0x804AEA98 | 84 bytes
void CUIPane::BringToTop(void) { }

// 0x804AEAEC | 40 bytes
void CUIPane::SetRect(TRect<float>) { }

// 0x804AEB14 | 44 bytes
void CUIPane::GetRect(void) { }

// 0x804AEB40 | 20 bytes
void CUIPane::SetOrigin(EVec2) { }

// 0x804AEB54 | 24 bytes
void CUIPane::GetOrigin(void) { }

// 0x804AEB6C | 504 bytes
void CUIPane::CalcHierarchy(TRect<float>, TRect<float>) { }

// 0x804AED64 | 188 bytes
void CUIPane::HitTest(EVec2, CUIPane **) { }

// 0x804AEE20 | 4 bytes
void CUIPane::Draw(ERC *) { }

// 0x804AEE24 | 4 bytes
void CUIPane::MouseDown(EVec2, int, float) { }

// 0x804AEE28 | 48 bytes
void CUIPane::SetCursor(EVec2, float) { }

// 0x804AEE58 | 4 bytes
void CUIPane::MouseUp(EVec2, int, float) { }

// 0x804AEE5C | 760 bytes
void CUIPane::DrawRect(ERC *, TRect<float>, EVec3, float) { }

// 0x804AF294 | 704 bytes
void CUIPane::DrawText(ERC *, EVec2, float, EVec3, char *, EFontAlignX, EFontAlignY) { }

// 0x804AF554 | 104 bytes
void CUIPane::DrawHierarchy(ERC *) { }

// 0x804AF5BC | 4 bytes
void CUIPane::KeyPressed(int, unsigned short) { }

// 0x804AF5C0 | 4 bytes
void CUIPane::KeyHeld(int, unsigned short) { }

// 0x804AF5C4 | 4 bytes
void CUIPane::KeyReleased(int, unsigned short) { }

// 0x804AF5C8 | 112 bytes
void CUIPane::SetKeyFocus(void) { }

// 0x804B5D90 | 56 bytes
void* CUIPane::operator new(unsigned int) { }

// 0x804B5DD0 | 52 bytes
void CUIPane::operator delete(void *) { }

// 0x804B5E04 | 72 bytes
CUIPane::~CUIPane(void) { }
