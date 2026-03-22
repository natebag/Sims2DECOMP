// econtrollermanager_stubs.cpp - Stub implementations for Econtrollermanager
// Auto-generated from symbols.json - 50 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x804F667C | 44 bytes
EControllerManager::EControllerManager(void) { }

// 0x804F66A8 | 44 bytes
void EControllerManager::Init(void) { }

// 0x804F66D4 | 88 bytes
void EControllerManager::Update(void) { }

// 0x804F672C | 4 bytes
void EControllerManager::Shutdown(void) { }

// 0x804F6730 | 24 bytes
void EControllerManager::MapPlayerToController(unsigned int, unsigned int) { }

// 0x804F6748 | 356 bytes
void EControllerManager::SwapPlayerControls(unsigned int, unsigned int) { }

// 0x804F68AC | 20 bytes
void EControllerManager::UnmapPlayer(unsigned int) { }

// 0x804F68C0 | 16 bytes
void EControllerManager::GetPlayerMapped(unsigned int) { }

// 0x804F68D0 | 32 bytes
void EControllerManager::GetController(unsigned int) { }

// 0x804F68F0 | 28 bytes
void EControllerManager::GetPlayerControllerIndex(unsigned int) { }

// 0x804F690C | 64 bytes
void EControllerManager::GetPlayerController(unsigned int) { }

// 0x804F694C | 96 bytes
void EControllerManager::FindActiveController(void) { }

// 0x804F69AC | 88 bytes
void EControllerManager::Flush(void) { }

// 0x804F6A04 | 352 bytes
void EControllerManager::GetCmdResultAllCtrl(unsigned int, unsigned int (EController::*)(EController *, unsigned int), unsigned int (EController::*)(EController *, unsigned int), bool, unsigned int *, unsigned int) { }

// 0x804F6B64 | 356 bytes
void EControllerManager::GetBtnResultAllCtrl(unsigned int (EController::*)(EController *, unsigned int), bool, bool, unsigned int, unsigned int *, unsigned int) { }

// 0x804F6CC8 | 100 bytes
void EControllerManager::MapControllerCommands(EBtnToCmdAssoc *, int) { }

// 0x804F7B10 | 52 bytes
EControllerManager::~EControllerManager(void) { }

// 0x804F7B44 | 8 bytes
void EControllerManager::GetControllerCount(void) { }

// 0x804F7B4C | 84 bytes
void EControllerManager::GetCmdDownAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7BA0 | 108 bytes
void EControllerManager::GetCmdPressedAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7C0C | 108 bytes
void EControllerManager::GetCmdReleasedAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7C78 | 84 bytes
void EControllerManager::GetCmdUpAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7CCC | 108 bytes
void EControllerManager::GetCmdRepeatAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7D38 | 80 bytes
void EControllerManager::GetBtnDownAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7D88 | 80 bytes
void EControllerManager::GetBtnPressedAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7DD8 | 80 bytes
void EControllerManager::GetBtnReleasedAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7E28 | 80 bytes
void EControllerManager::GetBtnUpAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7E78 | 80 bytes
void EControllerManager::GetBtnRepeatAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7EC8 | 80 bytes
void EControllerManager::GetBtnDownAnyAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7F18 | 80 bytes
void EControllerManager::GetBtnPressedAnyAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7F68 | 80 bytes
void EControllerManager::GetBtnReleasedAnyAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7FB8 | 80 bytes
void EControllerManager::GetBtnUpAnyAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8008 | 80 bytes
void EControllerManager::GetBtnRepeatAnyAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8058 | 84 bytes
void EControllerManager::GetCmdDownExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F80AC | 108 bytes
void EControllerManager::GetCmdPressedExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8118 | 108 bytes
void EControllerManager::GetCmdReleasedExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8184 | 84 bytes
void EControllerManager::GetCmdUpExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F81D8 | 108 bytes
void EControllerManager::GetCmdRepeatExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8244 | 80 bytes
void EControllerManager::GetBtnDownExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8294 | 80 bytes
void EControllerManager::GetBtnPressedExlAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F82E4 | 80 bytes
void EControllerManager::GetBtnReleasedExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8334 | 80 bytes
void EControllerManager::GetBtnUpExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8384 | 80 bytes
void EControllerManager::GetBtnRepeatExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F83D4 | 80 bytes
void EControllerManager::GetBtnDownAnyExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8424 | 80 bytes
void EControllerManager::GetBtnPressedAnyExlAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8474 | 80 bytes
void EControllerManager::GetBtnReleasedAnyExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F84C4 | 80 bytes
void EControllerManager::GetBtnUpAnyExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8514 | 80 bytes
void EControllerManager::GetBtnRepeatAnyExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8564 | 36 bytes
void EControllerManager::BitToIndex(unsigned int) { }

// 0x804F8588 | 12 bytes
void EControllerManager::IndexToBit(int) { }
