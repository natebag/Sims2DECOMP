// cuilog_stubs.cpp - Stub implementations for Cuilog
// Auto-generated from symbols.json - 16 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x804B8EA0 | 352 bytes
CUILog::CUILog(char *) { }

// 0x804B9000 | 144 bytes
CUILog::~CUILog(void) { }

// 0x804B9090 | 44 bytes
void CUILog::ClearLines(void) { }

// 0x804B90BC | 8 bytes
void CUILog::GetWindowName(void) { }

// 0x804B90C4 | 40 bytes
void CUILog::SetWindowRect(TRect<float> &) { }

// 0x804B90EC | 636 bytes
void CUILog::SetupWindow(CUIWindow *) { }

// 0x804B9368 | 124 bytes
void CUILog::ResizedWindow(CUIWindow *) { }

// 0x804B93E4 | 1012 bytes
void CUILog::DrawWindow(CUIWindow *, ERC *) { }

// 0x804B97D8 | 288 bytes
void CUILog::OutputLine(char *) { }

// 0x804B98F8 | 124 bytes
void CUILog::WindowNotify(CUIWindow *, int) { }

// 0x804B9974 | 172 bytes
void CUILog::WriteLineToFile(int) { }

// 0x804B9A20 | 76 bytes
void CUILog::WriteLineToDebug(int) { }

// 0x804B9A6C | 276 bytes
void CUILog::StartCapture(void) { }

// 0x804B9B80 | 80 bytes
void CUILog::EndCapture(void) { }

// 0x804B9BD0 | 136 bytes
void CUILog::StartTrace(void) { }

// 0x804B9C58 | 12 bytes
void CUILog::EndTrace(void) { }
