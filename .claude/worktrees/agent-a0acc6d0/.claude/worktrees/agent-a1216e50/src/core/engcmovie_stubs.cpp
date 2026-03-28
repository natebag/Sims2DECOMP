// engcmovie_stubs.cpp - Stub implementations for Engcmovie
// Auto-generated from symbols.json - 24 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8050F26C | 208 bytes
ENgcMovie::ENgcMovie(void) { }

// 0x8050F33C | 108 bytes
ENgcMovie::~ENgcMovie(void) { }

// 0x8050F3A8 | 356 bytes
void ENgcMovie::Load(EFile *, unsigned int, unsigned int, unsigned int) { }

// 0x8050F50C | 184 bytes
void ENgcMovie::Start(int, int) { }

// 0x8050F5C4 | 60 bytes
void ENgcMovie::Stop(void) { }

// 0x8050F604 | 92 bytes
void ENgcMovie::IsFinished(void) { }

// 0x8050F660 | 272 bytes
void ENgcMovie::GetNextFrame(void) { }

// 0x8050F770 | 312 bytes
void ENgcMovie::PlayerInit(int) { }

// 0x8050F8A8 | 96 bytes
void ENgcMovie::PlayerQuit(void) { }

// 0x8050F908 | 792 bytes
void ENgcMovie::PlayerOpen(unsigned int, bool) { }

// 0x8050FC20 | 80 bytes
void ENgcMovie::PlayerClose(void) { }

// 0x8050FC70 | 472 bytes
void ENgcMovie::PlayerCreateBuffers(EAllocGroup &) { }

// 0x8050FE48 | 556 bytes
void ENgcMovie::PlayerPrepare(int, int, int) { }

// 0x80510074 | 92 bytes
void ENgcMovie::PlayerPlay(void) { }

// 0x805100D0 | 172 bytes
void ENgcMovie::PlayerStop(void) { }

// 0x8051017C | 60 bytes
void ENgcMovie::PlayerPause(void) { }

// 0x805101B8 | 424 bytes
void ENgcMovie::PlayerSkip(void) { }

// 0x80510360 | 188 bytes
void ENgcMovie::PlayerDrawCurrentFrame(_GXRenderModeObj *, unsigned int, unsigned int, unsigned int, unsigned int) { }

// 0x8051041C | 64 bytes
void ENgcMovie::PlayerGetVideoInfo(THPVideoInfo *) { }

// 0x8051045C | 72 bytes
void ENgcMovie::PlayerGetAudioInfo(THPAudioInfo *) { }

// 0x805104A4 | 40 bytes
void ENgcMovie::PlayerGetFrameRate(void) { }

// 0x805104CC | 32 bytes
void ENgcMovie::PlayerGetTotalFrame(void) { }

// 0x805104EC | 12 bytes
void ENgcMovie::PlayerGetState(void) { }

// 0x805104F8 | 76 bytes
void ENgcMovie::PlayerDrawDone(void) { }
