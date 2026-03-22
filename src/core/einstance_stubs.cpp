// einstance_stubs.cpp - Stub implementations for Einstance
// Auto-generated from symbols.json - 15 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8038AB60 | 224 bytes
EInstance::EInstance(void) { }

// 0x8038AC40 | 168 bytes
EInstance::~EInstance(void) { }

// 0x8038ACE8 | 160 bytes
void EInstance::Write(EStream &) { }

// 0x8038AF1C | 484 bytes
void EInstance::Load(EFile &) { }

// 0x8038B100 | 120 bytes
void EInstance::SetBounds(EBound3 &) { }

// 0x8038B25C | 412 bytes
void EInstance::ShadowDirAtPoint(EVec3 &, EVec3 &, int) { }

// 0x8038B3F8 | 380 bytes
void EInstance::CalcShadowLight(EVec3 &, short) { }

// 0x8038B574 | 344 bytes
void EInstance::CalcShadowLightWeighted(EVec3 &, short) { }

// 0x8038B6CC | 500 bytes
void EInstance::ShadowDirAtPointWeighted(EVec3 &, EVec3 &, int) { }

// 0x8038B918 | 448 bytes
void EInstance::CalcLights(EVec3 &, ELights &, bool) { }

// 0x8038BAD8 | 448 bytes
void EInstance::CalcLights4(EVec3 &, ELights &, bool) { }

// 0x8038D0D4 | 84 bytes
void EInstance::RegisterType(unsigned short) { }

// 0x8038D288 | 124 bytes
void EInstance::ResetLocation(void) { }

// 0x8038D304 | 76 bytes
void EInstance::GetLocationId(short &, short &) { }

// 0x8038D350 | 80 bytes
void EInstance::GetOtherSide(short &, short &) { }
