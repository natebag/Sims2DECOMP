// cuimixin_stubs.cpp - Stub implementations for Cuimixin
// Auto-generated from symbols.json - 21 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x804B7920 | 32 bytes
CUIMixin::CUIMixin(void) { }

// 0x804B7940 | 120 bytes
CUIMixin::~CUIMixin(void) { }

// 0x804B79B8 | 48 bytes
void CUIMixin::AddMixin(int) { }

// 0x804B79E8 | 48 bytes
void CUIMixin::RemoveMixin(void) { }

// 0x804B7A18 | 616 bytes
void CUIMixin::WindowCallback(unsigned int, CUIEvent *) { }

// 0x804B7C80 | 8 bytes
void CUIMixin::GetWindowFlags(void) { }

// 0x804B7C88 | 208 bytes
void CUIMixin::CreateWindow(void) { }

// 0x804B7D58 | 64 bytes
void CUIMixin::DestroyWindow(void) { }

// 0x804B7D98 | 4 bytes
void CUIMixin::SetupWindow(CUIWindow *) { }

// 0x804B7D9C | 4 bytes
void CUIMixin::ResizedWindow(CUIWindow *) { }

// 0x804B7DA0 | 4 bytes
void CUIMixin::DrawWindow(CUIWindow *, ERC *) { }

// 0x804B7DA4 | 4 bytes
void CUIMixin::WindowNotify(CUIWindow *, int) { }

// 0x804B7DA8 | 4 bytes
void CUIMixin::MouseDown(CUIWindow *, EVec2) { }

// 0x804B7DAC | 4 bytes
void CUIMixin::MouseUp(CUIWindow *, EVec2) { }

// 0x804B7DB0 | 4 bytes
void CUIMixin::MouseDoubleClick(CUIWindow *, EVec2) { }

// 0x804B7DB4 | 48 bytes
void CUIMixin::SetCursor(CUIWindow *, EVec2) { }

// 0x804B7DE4 | 4 bytes
void CUIMixin::KeyPressed(CUIWindow *, int, unsigned short, bool) { }

// 0x804B7DE8 | 4 bytes
void CUIMixin::KeyReleased(CUIWindow *, int, unsigned short) { }

// 0x804BCC80 | 56 bytes
void* CUIMixin::operator new(unsigned int) { }

// 0x804BCCC0 | 52 bytes
void CUIMixin::operator delete(void *) { }

// 0x804BCCF4 | 24 bytes
void CUIMixin::DoesWindowExist(void) { }
