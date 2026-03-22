// emitter_stubs.cpp - Stub implementations for Emitter
// Auto-generated from symbols.json - 12 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x803ABC0C | 148 bytes
void Emitter::Create(char *, float *, pemitterinfo *, void (*)(particle *, PVector4 *, float, float, PVector4 *, void *), void (*)(void *), void (*)(pemitter *, PVector4 *, PVector4 *), void *) { }

// 0x803ABCD0 | 92 bytes
void Emitter::Reg(psystem *, bool) { }

// 0x803ABD2C | 100 bytes
void Emitter::UnReg(psystem *, bool) { }

// 0x803ABD90 | 152 bytes
void Emitter::SetMatrix(float *) { }

// 0x803ABE28 | 116 bytes
void Emitter::SetState(int, int) { }

// 0x803ABEC4 | 136 bytes
Emitter::Emitter(void) { }

// 0x803ABF4C | 96 bytes
Emitter::~Emitter(void) { }

// 0x803ABFAC | 192 bytes
void Emitter::SetCallbacks(void (*)(particle *, PVector4 *, float, float, PVector4 *, void *), void (*)(void *), void (*)(void *), void (*)(pemitter *, PVector4 *, PVector4 *), void *, void (*)(void *), void *, void (*)(void *), void *) { }

// 0x803AC06C | 104 bytes
void Emitter::EmitterSetPostDestroyCallback(void (*)(void *), void *) { }

// 0x803AC0D4 | 116 bytes
void Emitter::EmitterSetIntervalCallback(void (*)(void *), void *) { }

// 0x803AC1A0 | 84 bytes
void Emitter::PEmitterSubmitParticlesCB(ELevelDrawData &, EOrderTableData *) { }

// 0x803AC1FC | 300 bytes
void Emitter::Draw(ELevelDrawData &) { }
