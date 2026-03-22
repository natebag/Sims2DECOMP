// gamedata_stubs.cpp - Stub implementations for Gamedata
// Auto-generated from symbols.json - 44 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x800602B8 | 300 bytes
GameData::GameData(void) { }

// 0x800603E4 | 232 bytes
GameData::~GameData(void) { }

// 0x800604CC | 72 bytes
void GameData::GamePlayShutdown(void) { }

// 0x80060514 | 128 bytes
void GameData::GamePlayReset(void) { }

// 0x80060598 | 912 bytes
void GameData::LoadDefaultNeighborhood(void) { }

// 0x80060928 | 152 bytes
void GameData::LoadSavedNeighborhood(void) { }

// 0x800609C0 | 428 bytes
void GameData::PrepareSimData(int, int) { }

// 0x80060B6C | 464 bytes
void GameData::ReplaceSimData(int, bool, int, int) { }

// 0x80060D3C | 40 bytes
void GameData::LoadCreateASim(int, int) { }

// 0x80060D64 | 88 bytes
void GameData::SaveCreateASim(void) { }

// 0x80060DBC | 860 bytes
void GameData::PlayerEnterHouse(void) { }

// 0x80061118 | 1392 bytes
void GameData::PrepCreateAFamilyData(int) { }

// 0x80061688 | 236 bytes
void GameData::CreateAFamilyAddFamilyMember(Family *) { }

// 0x80061774 | 1720 bytes
void GameData::StoreCreateAFamilyData(void) { }

// 0x80061E2C | 112 bytes
void GameData::SaveCreateAFamily(void) { }

// 0x80061E9C | 700 bytes
void GameData::SystemPreUpdate(void) { }

// 0x80062728 | 136 bytes
void GameData::SystemPreDraw(ERC *) { }

// 0x800627B0 | 4 bytes
void GameData::SystemPostUpdate(void) { }

// 0x800627B4 | 24 bytes
void GameData::IsDrawCtrlMessageDisabled(void) { }

// 0x800627CC | 24 bytes
void GameData::SetCtrlDrawMessageDisable(int) { }

// 0x800627E4 | 24 bytes
void GameData::ClearCtrlDrawMessageDisable(int) { }

// 0x800627FC | 756 bytes
void GameData::SystemPostDraw(ERC *) { }

// 0x80062AF0 | 100 bytes
void GameData::SetTwoPlayerMode(bool) { }

// 0x80062B54 | 108 bytes
void GameData::IsPlayerConnected(unsigned char) { }

// 0x80062BC0 | 76 bytes
void GameData::GotoLiveMode(void) { }

// 0x80062C0C | 252 bytes
void GameData::CopyrightUpdate(float) { }

// 0x80062D08 | 280 bytes
void GameData::CopyrightDraw(ERC *) { }

// 0x80062E20 | 468 bytes
void GameData::VersionInfoDraw(ERC *) { }

// 0x80062FF4 | 140 bytes
void GameData::GetLocalizedSims2Logo(void) { }

// 0x80063080 | 252 bytes
void GameData::GetLocalizedEAMovie(void) { }

// 0x8006317C | 64 bytes
void GameData::GetLocalizedSimsIntroMovie(void) { }

// 0x800631BC | 64 bytes
void GameData::GetLocalizedSimsEndingMovie(void) { }

// 0x800631FC | 92 bytes
void GameData::SetBlackGraphicsBackgroundColor(void) { }

// 0x80063258 | 100 bytes
void GameData::SetUglyGraphicsBackgroundColor(void) { }

// 0x800632BC | 40 bytes
void GameData::UseConfigOptions(void) { }

// 0x800632E4 | 516 bytes
void GameData::StageInitTiming(float *, int) { }

// 0x800634E8 | 68 bytes
void GameData::StageStartFrame(void) { }

// 0x8006352C | 604 bytes
void GameData::StageEndFrame(char *, int, int) { }

// 0x80063788 | 168 bytes
void GameData::StageEnd(char *, char *, bool) { }

// 0x80063830 | 4 bytes
void GameData::StageOutputActualTimes(char *) { }

// 0x80063834 | 480 bytes
void GameData::GotoXamMode(int, int, int, int) { }

// 0x80063A14 | 8 bytes
void GameData::GetBuildBuyPlayer(void) const { }

// 0x80063A1C | 148 bytes
void GameData::SetBuildBuyPlayer(int) { }

// 0x80063AB0 | 60 bytes
void GameData::GetSelectedPlayerFamily(void) { }
