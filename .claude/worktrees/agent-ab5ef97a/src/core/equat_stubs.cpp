// equat_stubs.cpp - Stub implementations for Equat
// Auto-generated from symbols.json - 10 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8046453C | 196 bytes
void EQuat::ToMat4(EMat4 &) const { }

// 0x80464600 | 444 bytes
void EQuat::FromMat4(EMat4 &) { }

// 0x804647BC | 184 bytes
void EQuat::ToAxisAngle(EVec3 &, float &) const { }

// 0x80464874 | 72 bytes
void EQuat::ExtractAxisRotation(EVec3 &) const { }

// 0x804648BC | 464 bytes
void EQuat::Set(float, float, float) { }

// 0x80464A8C | 100 bytes
void EQuat::RemoveAxisFlip(EQuat &) { }

// 0x80464AF0 | 808 bytes
void EQuat::Slerp(float, EQuat &, EQuat) { }

// 0x80464E18 | 732 bytes
void EQuat::SlerpNoInvert(float, EQuat &, EQuat &) { }

// 0x804650F4 | 248 bytes
void EQuat::Scale(float, EQuat &) { }

// 0x804653F0 | 40 bytes
void EQuat::Id(void) { }
