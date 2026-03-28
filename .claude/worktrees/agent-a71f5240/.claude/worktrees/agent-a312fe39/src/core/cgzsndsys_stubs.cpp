// cgzsndsys_stubs.cpp - Stub implementations for Cgzsndsys
// Auto-generated from symbols.json - 13 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x80143BA8 | 104 bytes
cGZSndSys::cGZSndSys(void) { }

// 0x80143C10 | 360 bytes
cGZSndSys::~cGZSndSys(void) { }

// 0x80143D78 | 36 bytes
void cGZSndSys::Initialize(void) { }

// 0x80143D9C | 88 bytes
void cGZSndSys::CreateSoundEffect(unsigned int, float) { }

// 0x80143DF4 | 160 bytes
void cGZSndSys::CreateAudioStream(unsigned int, bool, float) { }

// 0x80143E94 | 16 bytes
void cGZSndSys::addToList(cGZSnd *) { }

// 0x80143EA4 | 164 bytes
void cGZSndSys::removeFromList(cGZSnd *) { }

// 0x80144010 | 56 bytes
void cGZSndSys::FreeUnusedSounds(void) { }

// 0x80144048 | 548 bytes
void cGZSndSys::killDeadSounds(void) { }

// 0x8014426C | 1252 bytes
void cGZSndSys::ProcessCache(unsigned int) { }

// 0x80144750 | 2124 bytes
void cGZSndSys::Update(void) { }

// 0x80144F9C | 4 bytes
void cGZSndSys::preloadMusic(void) { }

// 0x80144FA0 | 4 bytes
void cGZSndSys::unloadMusic(void) { }
