// engccontroller_stubs.cpp - Stub implementations for Engccontroller
// Auto-generated from symbols.json - 11 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x80506A68 | 32 bytes
ENgcController::~ENgcController(void) { }

// 0x80506A88 | 8 bytes
void ENgcController::HasVibration(void) const { }

// 0x80506A90 | 68 bytes
void ENgcController::VibrateMotorOne(float) { }

// 0x80506AD4 | 68 bytes
void ENgcController::VibrateMotorTwo(float) { }

// 0x80506B18 | 68 bytes
void ENgcController::StopMotorOne(void) { }

// 0x80506B5C | 68 bytes
void ENgcController::StopMotorTwo(void) { }

// 0x80506BA0 | 32 bytes
void ENgcController::IsMotorOneActive(void) const { }

// 0x80506BC0 | 32 bytes
void ENgcController::IsMotorTwoActive(void) const { }

// 0x80506BE0 | 508 bytes
void ENgcController::GetButtons(PADStatus &) { }

// 0x80506DDC | 240 bytes
void ENgcController::GetStick(PADStatus &, int, int) { }

// 0x80506ECC | 184 bytes
void ENgcController::UpdateMotors(void) { }
