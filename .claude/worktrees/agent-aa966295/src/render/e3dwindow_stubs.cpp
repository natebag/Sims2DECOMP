// e3dwindow_stubs.cpp - Stub implementations for E3Dwindow
// Auto-generated from symbols.json - 41 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x80482328 | 228 bytes
E3DWindow::E3DWindow(void) { }

// 0x8048240C | 280 bytes
void E3DWindow::SetProjection(float, float, float, float) { }

// 0x80482524 | 212 bytes
void E3DWindow::CopyProjection(E3DWindow *) { }

// 0x804825F8 | 1236 bytes
void E3DWindow::SetOrthoProjectionForUIHD(float, float, float, float, float, float, float, float, float, float, float) { }

// 0x80482ACC | 580 bytes
void E3DWindow::SetOrthoProjection(float, float, float, float, float, float) { }

// 0x80482D10 | 192 bytes
void E3DWindow::SetLookAt(EMat4 &) { }

// 0x80482DD0 | 192 bytes
void E3DWindow::SetLookAtPos(EMat4 &) { }

// 0x80482ED8 | 92 bytes
void E3DWindow::SetViewport(TRect<float> &) { }

// 0x80482F34 | 100 bytes
void E3DWindow::CalcViewport(void) { }

// 0x80482F98 | 116 bytes
void E3DWindow::CalcViewportInv(void) { }

// 0x80483068 | 3488 bytes
void E3DWindow::CalcViewportStructures(void) { }

// 0x80483E08 | 264 bytes
void E3DWindow::Test(EBoundSphere &) { }

// 0x804841D0 | 388 bytes
void E3DWindow::TestAsRect(EBound3 &) { }

// 0x804845D8 | 224 bytes
void E3DWindow::ProjectionMatrixChanged(void) { }

// 0x804846B8 | 252 bytes
void E3DWindow::LookAtMatrixChanged(void) { }

// 0x804847B4 | 64 bytes
void E3DWindow::CalcLookAtDotProjection(void) { }

// 0x804847F4 | 228 bytes
void E3DWindow::Select(ERC *) { }

// 0x804848D8 | 32 bytes
void E3DWindow::InputCoordinatesChanged(void) { }

// 0x804848F8 | 32 bytes
void E3DWindow::OutputCoordinatesChanged(void) { }

// 0x80484918 | 284 bytes
void E3DWindow::CalcTextureProjection(EMat4 &) { }

// 0x80484A34 | 196 bytes
void E3DWindow::TransformToScreen(EVec3 &, EVec2 &) { }

// 0x80484BDC | 212 bytes
void E3DWindow::CameraTransformToScreen(EVec3 &, EVec3 &) { }

// 0x80484CB0 | 352 bytes
void E3DWindow::BackCullTest(EVec3 *) { }

// 0x80484E10 | 488 bytes
void E3DWindow::TransformToWorld(EVec2 &, EVec3 &) { }

// 0x80484FF8 | 52 bytes
void E3DWindow::GetNearFar(float *, float *) { }

// 0x8048502C | 36 bytes
void E3DWindow::GetFOVLengths(float *, float *) { }

// 0x80485050 | 48 bytes
void E3DWindow::SetFrustumType(int) { }

// 0x80485080 | 1112 bytes
void E3DWindow::PinToFrustrum(EVec3 *) { }

// 0x804854D8 | 240 bytes
void E3DWindow::CornerToWorld(EVec3 *, int) { }

// 0x804855C8 | 468 bytes
void E3DWindow::ProjectToZPlane(EVec3 *, float, EVec3 &) { }

// 0x8048579C | 276 bytes
void E3DWindow::MakeLineOnPlane(EVec3 *, float, EVec3 &) { }

// 0x804858B0 | 408 bytes
void E3DWindow::GetFrustrumQuadAtZ(float, Quad *) { }

// 0x80485A48 | 1088 bytes
void E3DWindow::Get3DQuadFromScreenTrapAtZ(float, float *, Quad *) { }

// 0x80485E88 | 72 bytes
E3DWindow::~E3DWindow(void) { }

// 0x80485ED0 | 44 bytes
void E3DWindow::GetViewport(void) const { }

// 0x80485EFC | 8 bytes
void E3DWindow::GetLookPos(void) { }

// 0x80485F04 | 8 bytes
void E3DWindow::GetLookDir(void) { }

// 0x80485F0C | 8 bytes
void E3DWindow::GetLookAt(void) { }

// 0x80485F14 | 8 bytes
void E3DWindow::GetProjection(void) const { }

// 0x80485F1C | 8 bytes
void E3DWindow::GetNormalizedProjection(void) const { }

// 0x80485F24 | 4 bytes
void E3DWindow::Cast3DWindow(void) { }
