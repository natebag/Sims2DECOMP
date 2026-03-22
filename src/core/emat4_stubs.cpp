#if 0 // SKIP
// emat4_stubs.cpp - Stub implementations for Emat4
// Auto-generated from symbols.json - 34 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8046089C | 72 bytes
void EMat4::PreTranslate(EVec3 &) { }

// 0x80460AE8 | 160 bytes
void EMat4::Normalize(void) { }

// 0x80460B88 | 76 bytes
void EMat4::Transpose(EMat4 &) { }

// 0x80460C6C | 88 bytes
void EMat4::Id(void) { }

// 0x80460CC4 | 80 bytes
void EMat4::Translate(EVec3 &) { }

// 0x80460D14 | 76 bytes
void EMat4::Scale(EVec3 &) { }

// 0x80460DF0 | 108 bytes
void EMat4::RotateX(float) { }

// 0x80460E5C | 108 bytes
void EMat4::RotateY(float) { }

// 0x80460EC8 | 108 bytes
void EMat4::RotateZ(float) { }

// 0x80460F34 | 752 bytes
void EMat4::Invert(EMat4 &) { }

// 0x80461224 | 164 bytes
void EMat4::InvertSimple(EMat4 &) { }

// 0x804612C8 | 264 bytes
void EMat4::Rotate(EVec3 &, float) { }

// 0x804613D0 | 180 bytes
void EMat4::PreRotateX(float) { }

// 0x80461484 | 212 bytes
void EMat4::PostRotateX(float) { }

// 0x80461558 | 180 bytes
void EMat4::PreRotateY(float) { }

// 0x8046160C | 212 bytes
void EMat4::PostRotateY(float) { }

// 0x804616E0 | 180 bytes
void EMat4::PreRotateZ(float) { }

// 0x80461794 | 212 bytes
void EMat4::PostRotateZ(float) { }

// 0x804619A0 | 388 bytes
void EMat4::Conform(EVec3 &) { }

// 0x80461B24 | 76 bytes
void EMat4::OrientPosNormal(EVec3 &, EVec3 &, EVec3 &) { }

// 0x80461B70 | 100 bytes
void EMat4::Clamp(void) { }

// 0x80461C6C | 88 bytes
void EMat4::GetMaxScale(void) const { }

// 0x80461CC4 | 132 bytes
void EMat4::GetHPR(float &, float &, float &) { }

// 0x80461D88 | 228 bytes
void EMat4::GetLookAtPos(EVec3 &, EVec3 &, EVec3 &) { }

// 0x80461E6C | 508 bytes
void EMat4::LookAtPos(EVec3 &, EVec3 &, EVec3 &) { }

// 0x80462068 | 76 bytes
void EMat4::LookAt(EVec3 &, EVec3 &, EVec3 &) { }

// 0x804620B4 | 268 bytes
void EMat4::LookAtDirect(EVec3 &, EVec3 &, float) { }

// 0x804621C0 | 508 bytes
void EMat4::LookTo(EVec3 &, EVec3 &, EVec3 &) { }

// 0x804623BC | 212 bytes
void EMat4::Projection(float, float, float, float) { }

// 0x80462490 | 228 bytes
void EMat4::Ortho(float, float, float, float, float, float) { }

// 0x80462574 | 876 bytes
void EMat4::BlendEuler(float, EMat4 &, EMat4 &) { }

// 0x804628E0 | 372 bytes
void EMat4::BlendQuat(float, EMat4 &, EMat4 &) { }

// 0x80462A54 | 252 bytes
void EMat4::TexturePerspectiveProjection(EVec3 &, EVec3 &, EVec3 &, float, float, float, float) { }

// 0x80462B50 | 140 bytes
void EMat4::TexturePlanarProjection(EVec3 &, EVec3 &, EVec3 &, float, float, float, float) { }
#endif
