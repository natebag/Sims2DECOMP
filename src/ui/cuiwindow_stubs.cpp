// cuiwindow_stubs.cpp - Stub implementations for Cuiwindow
// Auto-generated from symbols.json - 41 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x804B3360 | 84 bytes
void CUIWindow::CreateChildWindow(int) { }

// 0x804B33B4 | 1316 bytes
void CUIWindow::SetRect(TRect<float>) { }

// 0x804B38D8 | 40 bytes
void CUIWindow::GetRect(void) { }

// 0x804B3900 | 136 bytes
void CUIWindow::GetDrawRect(void) { }

// 0x804B3988 | 80 bytes
void CUIWindow::SetEraseColor(EVec3, float) { }

// 0x804B39D8 | 1580 bytes
void CUIWindow::Init(CUIWindow *, CUIPane *, int) { }

// 0x804B4004 | 632 bytes
void CUIWindow::Destroy(void) { }

// 0x804B427C | 64 bytes
void CUIWindow::BringToTop(void) { }

// 0x804B42BC | 60 bytes
void CUIWindow::WindowToScreen(EVec2) { }

// 0x804B42F8 | 60 bytes
void CUIWindow::ScreenToWindow(EVec2) { }

// 0x804B4334 | 36 bytes
void CUIWindow::SetCaption(char *) { }

// 0x804B4358 | 36 bytes
void CUIWindow::GetCaption(void) { }

// 0x804B437C | 52 bytes
void CUIWindow::GetOrigin(void) { }

// 0x804B43B0 | 64 bytes
void CUIWindow::SetOrigin(EVec2) { }

// 0x804B43F0 | 44 bytes
void CUIWindow::FindWidget(int) { }

// 0x804B441C | 128 bytes
void CUIWindow::AddWidget(int, int) { }

// 0x804B449C | 164 bytes
void CUIWindow::RemoveWidget(int) { }

// 0x804B4540 | 48 bytes
void CUIWindow::WidgetExists(int) { }

// 0x804B4570 | 36 bytes
void CUIWindow::GetWidgetType(int) { }

// 0x804B4594 | 112 bytes
void CUIWindow::SetWidgetRect(int, TRect<float>) { }

// 0x804B4604 | 68 bytes
void CUIWindow::GetWidgetRect(int) { }

// 0x804B4648 | 56 bytes
void CUIWindow::SetWidgetText(int, char *) { }

// 0x804B4680 | 40 bytes
void CUIWindow::GetWidgetText(int) { }

// 0x804B46A8 | 48 bytes
void CUIWindow::EnableWidget(int, bool) { }

// 0x804B46D8 | 68 bytes
void CUIWindow::SetWidgetCallback(int, bool (*)(unsigned int, CUIWindow *, int), unsigned int, bool (*)(unsigned int, CUIWindow *, int)) { }

// 0x804B471C | 12 bytes
void CUIWindow::SetEventCallback(void (*)(unsigned int, CUIEvent *), unsigned int) { }

// 0x804B4728 | 164 bytes
void CUIWindow::DispatchNotify(int, unsigned int) { }

// 0x804B47CC | 52 bytes
void CUIWindow::DispatchEvent(CUIEvent *) { }

// 0x804B4800 | 52 bytes
void CUIWindow::SetCheckbox(int, bool) { }

// 0x804B4834 | 40 bytes
void CUIWindow::GetCheckbox(int) { }

// 0x804B485C | 84 bytes
void CUIWindow::SetSlider(int, CUISliderState *) { }

// 0x804B48B0 | 84 bytes
void CUIWindow::GetSlider(int, CUISliderState *) { }

// 0x804B4904 | 100 bytes
void CUIWindow::SetScroll(int, CUIScrollState *) { }

// 0x804B4968 | 100 bytes
void CUIWindow::GetScroll(int, CUIScrollState *) { }

// 0x804B49CC | 108 bytes
void CUIWindow::SetSpin(int, CUISpinState *) { }

// 0x804B4A38 | 108 bytes
void CUIWindow::GetSpin(int, CUISpinState *) { }

// 0x804B4AA4 | 84 bytes
void CUIWindow::SetTextColor(int, EVec3 &) { }

// 0x804B4AF8 | 8 bytes
void CUIWindow::GetEventCallback(void) { }

// 0x804B4B00 | 8 bytes
void CUIWindow::GetUserData(void) { }

// 0x804B4B08 | 120 bytes
void CUIWindow::DrawRect(ERC *, TRect<float>, EVec3) { }

// 0x804B4B80 | 92 bytes
void CUIWindow::DrawText(ERC *, EVec2, float, EVec3, char *, EFontAlignX, EFontAlignY) { }
