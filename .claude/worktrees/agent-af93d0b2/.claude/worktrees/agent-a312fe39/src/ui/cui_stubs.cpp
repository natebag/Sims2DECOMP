// cui_stubs.cpp - Stub implementations for Cui
// Auto-generated from symbols.json - 15 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x804B4BDC | 584 bytes
void CUI::Init(void) { }

// 0x804B4E24 | 340 bytes
void CUI::SetCursor(char *) { }

// 0x804B4F78 | 64 bytes
void CUI::SetFont(int) { }

// 0x804B4FB8 | 2096 bytes
void CUI::Update(void) { }

// 0x804B57E8 | 104 bytes
void CUI::GetCursorLocation(CUIWindow *) { }

// 0x804B5850 | 84 bytes
void CUI::CreateWindow(int) { }

// 0x804B58A4 | 8 bytes
void CUI::CaptureInput(CUIPane *) { }

// 0x804B58AC | 12 bytes
void CUI::ReleaseInput(CUIPane *) { }

// 0x804B58E0 | 220 bytes
void CUI::SelectFont(ERC *, float, EVec3) { }

// 0x804B59BC | 68 bytes
void CUI::GetTopmostWindow(CUIWindow *) { }

// 0x804B5A00 | 28 bytes
void CUI::GetKeyboardFocus(void) { }

// 0x804B5A1C | 12 bytes
void CUI::SetKeyboardFocus(CUIWindow *) { }

// 0x804B5A28 | 12 bytes
void CUI::SetDesktopEventCallback(void (*)(unsigned int, CUIEvent *), unsigned int) { }

// 0x804B5A34 | 52 bytes
void CUI::DispatchDesktopEvent(CUIEvent *) { }

// 0x804B5A68 | 8 bytes
void CUI::SetVisible(bool) { }
