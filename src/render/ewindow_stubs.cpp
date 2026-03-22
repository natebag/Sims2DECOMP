// ewindow_stubs.cpp - Stub implementations for Ewindow
// Auto-generated from symbols.json - 24 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x804A7B50 | 232 bytes
EWindow::EWindow(void) { }

// 0x804A7C38 | 112 bytes
EWindow::~EWindow(void) { }

// 0x804A7CA8 | 168 bytes
void EWindow::SetRenderSurface(ERenderSurface *, int) { }

// 0x804A7EC8 | 132 bytes
void EWindow::ScaleOutputRectForScreenshot(TRect<float> *) { }

// 0x804A7F4C | 172 bytes
void EWindow::ScaleScissorRectForScreenshot(TRect<float> *, TRect<float> *) { }

// 0x804A82E8 | 44 bytes
void EWindow::TransformToPixel(EVec2 &, EVec2 &) { }

// 0x804A8564 | 84 bytes
void EWindow::CalcClipInv(void) { }

// 0x804A85B8 | 72 bytes
void EWindow::SetClip(TRect<float> &) { }

// 0x804A8600 | 200 bytes
void EWindow::SetInputCoordinates(TRect<float> &) { }

// 0x804A86C8 | 200 bytes
void EWindow::SetOutputCoordinates(TRect<float> &) { }

// 0x804A87E4 | 64 bytes
void* EWindow::operator new(unsigned int) { }

// 0x804A8824 | 52 bytes
void EWindow::operator delete(void *) { }

// 0x804A8858 | 60 bytes
void EWindow::SetInputCoordinatesAndClip(TRect<float> &) { }

// 0x804A8894 | 72 bytes
void EWindow::SetRect(TRect<float> &) { }

// 0x804A88DC | 44 bytes
void EWindow::Transform(EVec2 &, EVec2 &) { }

// 0x804A892C | 52 bytes
void EWindow::TransformInv(EVec2 &, EVec2 &) { }

// 0x804A898C | 28 bytes
void EWindow::TransformScale(float, float, float &, float &) { }

// 0x804A89CC | 40 bytes
void EWindow::ClipTest(EVec2 &) { }

// 0x804A8AA0 | 8 bytes
void EWindow::GetCurrentWindow(void) { }

// 0x804A8AA8 | 8 bytes
void EWindow::GetCurrent3DWindow(void) { }

// 0x804A8AB0 | 4 bytes
void EWindow::WindowMatrixChanged(void) { }

// 0x804A8AB4 | 4 bytes
void EWindow::InputCoordinatesChanged(void) { }

// 0x804A8AB8 | 4 bytes
void EWindow::OutputCoordinatesChanged(void) { }

// 0x804A8ABC | 8 bytes
void EWindow::Cast3DWindow(void) { }
