// elivemode_stubs.cpp - Stub implementations for Elivemode
// Auto-generated from symbols.json - 28 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x800F48D4 | 92 bytes
ELiveMode::ELiveMode(void) { }

// 0x800F4930 | 96 bytes
ELiveMode::~ELiveMode(void) { }

// 0x800F4990 | 452 bytes
void ELiveMode::Init(int) { }

// 0x800F7C28 | 52 bytes
void ELiveMode::ChangeHouse(void) { }

// 0x800F7C5C | 80 bytes
void ELiveMode::GotoStartMode(void) { }

// 0x800F7CAC | 404 bytes
void ELiveMode::QuitToMainMenu(void) { }

// 0x800F7E40 | 468 bytes
void ELiveMode::IsReadyForUpdate(void) { }

// 0x800F8014 | 1492 bytes
void ELiveMode::UpdateIntroCamera(void) { }

// 0x800F85E8 | 1728 bytes
void ELiveMode::Update(void) { }

// 0x800F8CA8 | 1552 bytes
void ELiveMode::Draw(ERC *) { }

// 0x800F92B8 | 4 bytes
void ELiveMode::PauseAllSounds(void) { }

// 0x800F92BC | 4 bytes
void ELiveMode::ResumeAllSounds(void) { }

// 0x800F92C0 | 940 bytes
void ELiveMode::DrawSplitScreenMask(ERC *, E3DWindow &, int) { }

// 0x800F966C | 900 bytes
void ELiveMode::InitPlayerXWindow(ERC *, E3DWindow &, int) { }

// 0x800F99F0 | 960 bytes
void ELiveMode::DrawSplitScreenDivider(ERC *) { }

// 0x800F9DB0 | 1316 bytes
void ELiveMode::DrawMain(ERC *) { }

// 0x800FA2D4 | 44 bytes
void ELiveMode::TriggerIntroCamera(CameraDirector *) { }

// 0x800FA300 | 680 bytes
void ELiveMode::StartIntroCamera(CameraDirector *, ESimsCam *) { }

// 0x800FA5A8 | 180 bytes
void ELiveMode::EndIntroCamera(CameraDirector *, ESimsCam *) { }

// 0x800FC7BC | 8 bytes
void ELiveMode::InTransportMode(void) { }

// 0x800FC7C4 | 20 bytes
void ELiveMode::IsIntroCameraTriggered(void) { }

// 0x800FC7D8 | 12 bytes
void ELiveMode::ResetIntroCamera(void) { }

// 0x800FC7E4 | 8 bytes
void ELiveMode::SetIntroCameraState(IntroCameraStartState) { }

// 0x800FC7EC | 8 bytes
void ELiveMode::GetIntroCameraState(void) { }

// 0x800FC7F4 | 24 bytes
void ELiveMode::IsRunningIntroCamera(void) { }

// 0x800FC80C | 8 bytes
void ELiveMode::SetGoingToNeighborhoodMode(bool) { }

// 0x800FC814 | 8 bytes
void ELiveMode::SetInitialized(bool) { }

// 0x800FC824 | 8 bytes
void ELiveMode::SetDontDraw(bool) { }
