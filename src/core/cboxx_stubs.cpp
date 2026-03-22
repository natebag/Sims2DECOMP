// cboxx_stubs.cpp - Stub implementations for Cboxx
// Auto-generated from symbols.json - 25 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x80131FE4 | 180 bytes
cBoxX::cBoxX(void) { }

// 0x80132098 | 180 bytes
cBoxX::~cBoxX(void) { }

// 0x8013214C | 404 bytes
void cBoxX::Init(void) { }

// 0x801322E4 | 180 bytes
void cBoxX::Shutdown(void) { }

// 0x80132398 | 684 bytes
void cBoxX::Update(unsigned int) { }

// 0x80132674 | 856 bytes
void cBoxX::GetSurroundVol(AmbientScorePlayer *, EVec3 &, float, float, int &, int &, int &, int &) { }

// 0x80132D4C | 816 bytes
void cBoxX::CalculateSurroundVol(EVec3 &, EVec3 &, EVec3 &, float, float, int &, int &, int &, int &) { }

// 0x8013307C | 508 bytes
void cBoxX::GetInstanceSurroundVol(int, cTrack *, int &, int &, int &, int &) { }

// 0x80133278 | 864 bytes
void cBoxX::GetInstanceVolNoPan(int, cTrack *, int &) { }

// 0x801335D8 | 684 bytes
void cBoxX::ConvertSurroundToVolPan(int, int, int, int, int &, int &) { }

// 0x80133914 | 4036 bytes
void cBoxX::Event(int, int, int, ERSoundEvent *, float) { }

// 0x801348D8 | 264 bytes
void cBoxX::SetAmbientScore(int) { }

// 0x80134A40 | 272 bytes
void cBoxX::FindSndobInstancePair(ERSoundEvent *, int) { }

// 0x80134B50 | 176 bytes
void cBoxX::AddToInstanceMap(ERSoundEvent *, int) { }

// 0x80134C00 | 392 bytes
void cBoxX::UpdateAllSndobVolPan(void) { }

// 0x80134D88 | 288 bytes
void cBoxX::CheckForTooManySounds(void) { }

// 0x80134EA8 | 264 bytes
void cBoxX::KillSource(int) { }

// 0x80134FB0 | 216 bytes
void cBoxX::UpdateSndobVolPan(ERSoundEvent *) { }

// 0x80135264 | 616 bytes
void cBoxX::GetSndobSurroundVols(ERSoundEvent *, int &, int &, int &, int &) { }

// 0x80135544 | 96 bytes
void cBoxX::PauseSFX(void) { }

// 0x801355A4 | 104 bytes
void cBoxX::UnpauseSFX(void) { }

// 0x8013564C | 76 bytes
void cBoxX::UnpauseAmbient(void) { }

// 0x80135698 | 76 bytes
void cBoxX::PauseMusic(void) { }

// 0x801356E4 | 92 bytes
void cBoxX::UnpauseMusic(void) { }

// 0x80135740 | 452 bytes
void cBoxX::GetListenerPosAndDir(ESimsCam *, EVec3 &, EVec3 &) { }
