// EControllerManager — stub implementations from symbol map
// Auto-generated. 52 functions.

// 0x804F667C [44b]
EControllerManager::EControllerManager(void) { }

// 0x804F66A8 [44b]
void EControllerManager::Init(void) { }

// 0x804F66D4 [88b]
void EControllerManager::Update(void) { }

// 0x804F672C [4b]
void EControllerManager::Shutdown(void) { }

// 0x804F6730 [24b]
void EControllerManager::MapPlayerToController(unsigned int, unsigned int) { }

// 0x804F6748 [356b]
void EControllerManager::SwapPlayerControls(unsigned int, unsigned int) { }

// 0x804F68AC [20b]
void EControllerManager::UnmapPlayer(unsigned int) { }

// 0x804F68C0 [16b]
int EControllerManager::GetPlayerMapped(unsigned int) { }

// 0x804F68D0 [32b]
int EControllerManager::GetController(unsigned int) { }

// 0x804F68F0 [28b]
int EControllerManager::GetPlayerControllerIndex(unsigned int) { }

// 0x804F690C [64b]
int EControllerManager::GetPlayerController(unsigned int) { }

// 0x804F694C [96b]
void EControllerManager::FindActiveController(void) { }

// 0x804F69AC [88b]
void EControllerManager::Flush(void) { }

// 0x804F6A04 [352b]
int EControllerManager::GetCmdResultAllCtrl(unsigned int, unsigned int (EController::*)(EController *, unsigned int), unsigned int (EController::*)(EController *, unsigned int), bool, unsigned int *, unsigned int) { }

// 0x804F6B64 [356b]
int EControllerManager::GetBtnResultAllCtrl(unsigned int (EController::*)(EController *, unsigned int), bool, bool, unsigned int, unsigned int *, unsigned int) { }

// 0x804F6CC8 [100b]
void EControllerManager::MapControllerCommands(EBtnToCmdAssoc *, int) { }

// 0x804F7B10 [52b]
EControllerManager::~EControllerManager(void) { }

// 0x804F7B44 [8b]
int EControllerManager::GetControllerCount(void) { }

// 0x804F7B4C [84b]
int EControllerManager::GetCmdDownAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7BA0 [108b]
int EControllerManager::GetCmdPressedAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7C0C [108b]
int EControllerManager::GetCmdReleasedAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7C78 [84b]
int EControllerManager::GetCmdUpAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7CCC [108b]
int EControllerManager::GetCmdRepeatAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7D38 [80b]
int EControllerManager::GetBtnDownAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7D88 [80b]
int EControllerManager::GetBtnPressedAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7DD8 [80b]
int EControllerManager::GetBtnReleasedAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7E28 [80b]
int EControllerManager::GetBtnUpAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7E78 [80b]
int EControllerManager::GetBtnRepeatAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7EC8 [80b]
int EControllerManager::GetBtnDownAnyAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7F18 [80b]
int EControllerManager::GetBtnPressedAnyAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7F68 [80b]
int EControllerManager::GetBtnReleasedAnyAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F7FB8 [80b]
int EControllerManager::GetBtnUpAnyAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8008 [80b]
int EControllerManager::GetBtnRepeatAnyAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8058 [84b]
int EControllerManager::GetCmdDownExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F80AC [108b]
int EControllerManager::GetCmdPressedExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8118 [108b]
int EControllerManager::GetCmdReleasedExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8184 [84b]
int EControllerManager::GetCmdUpExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F81D8 [108b]
int EControllerManager::GetCmdRepeatExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8244 [80b]
int EControllerManager::GetBtnDownExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8294 [80b]
int EControllerManager::GetBtnPressedExlAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F82E4 [80b]
int EControllerManager::GetBtnReleasedExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8334 [80b]
int EControllerManager::GetBtnUpExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8384 [80b]
int EControllerManager::GetBtnRepeatExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F83D4 [80b]
int EControllerManager::GetBtnDownAnyExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8424 [80b]
int EControllerManager::GetBtnPressedAnyExlAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8474 [80b]
int EControllerManager::GetBtnReleasedAnyExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F84C4 [80b]
int EControllerManager::GetBtnUpAnyExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8514 [80b]
int EControllerManager::GetBtnRepeatAnyExclAllCtrl(unsigned int, unsigned int *, unsigned int) { }

// 0x804F8564 [36b]
void EControllerManager::BitToIndex(unsigned int) { }

// 0x804F8588 [12b]
void EControllerManager::IndexToBit(int) { }

// 0x80744AE0 [32b]
void EControllerManager::_ctrlLastActivetime() { }

// 0x8078AEF8 [16b]
void EControllerManager::_ctrlPads() { }

