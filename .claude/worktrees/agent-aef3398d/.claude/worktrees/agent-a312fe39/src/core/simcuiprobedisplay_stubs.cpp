// simcuiprobedisplay_stubs.cpp - Stub implementations for Simcuiprobedisplay
// Auto-generated from symbols.json - 15 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x801A1850 | 60 bytes
SimCUIProbeDisplay::SimCUIProbeDisplay(void) { }

// 0x801A188C | 84 bytes
SimCUIProbeDisplay::~SimCUIProbeDisplay(void) { }

// 0x801A18E0 | 12 bytes
void SimCUIProbeDisplay::GetWindowName(void) { }

// 0x801A18EC | 796 bytes
void SimCUIProbeDisplay::SetupWindow(CUIWindow *) { }

// 0x801A1C08 | 304 bytes
void SimCUIProbeDisplay::ResizedWindow(CUIWindow *) { }

// 0x801A1D38 | 2840 bytes
void SimCUIProbeDisplay::DrawWindow(CUIWindow *, ERC *) { }

// 0x801A2850 | 804 bytes
void SimCUIProbeDisplay::MouseDown(CUIWindow *, EVec2) { }

// 0x801A2B74 | 292 bytes
void SimCUIProbeDisplay::WindowNotify(CUIWindow *, int) { }

// 0x801A2C98 | 212 bytes
void SimCUIProbeDisplay::WindowCallback(unsigned int, CUIEvent *) { }

// 0x801A2D6C | 296 bytes
void SimCUIProbeDisplay::CreateObjectProbes(void) { }

// 0x801A2E94 | 228 bytes
void SimCUIProbeDisplay::DeleteObjectProbes(void) { }

// 0x801A2F78 | 248 bytes
void SimCUIProbeDisplay::PauseObjectProbes(bool) { }

// 0x801A3070 | 100 bytes
void SimCUIProbeDisplay::GetObjectProbe(short) { }

// 0x801A30D4 | 316 bytes
void SimCUIProbeDisplay::GetObjectName(short, char *) { }

// 0x801A3210 | 1008 bytes
void SimCUIProbeDisplay::GetPrimSampleText(SimTickSample *, int, char *) { }
