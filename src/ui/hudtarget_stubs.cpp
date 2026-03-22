// hudtarget_stubs.cpp - Stub implementations for Hudtarget
// Auto-generated from symbols.json - 67 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8028544C | 10652 bytes
HUDTarget::HUDTarget(void) { }

// 0x80287DE8 | 588 bytes
HUDTarget::~HUDTarget(void) { }

// 0x80288034 | 364 bytes
void HUDTarget::AttachControllers(void) { }

// 0x802881A0 | 168 bytes
void HUDTarget::ReleaseControllers(void) { }

// 0x80288248 | 48 bytes
void HUDTarget::IncPause(bool) { }

// 0x80288278 | 48 bytes
void HUDTarget::ReleasePause(bool) { }

// 0x802882A8 | 108 bytes
void HUDTarget::SetVariable(char *, char *) { }

// 0x80288314 | 1076 bytes
void HUDTarget::SetPlayerVariable(int, char *, char *) { }

// 0x80288748 | 100 bytes
void HUDTarget::GetVariable(char *) { }

// 0x802887AC | 1256 bytes
void HUDTarget::GetPlayerVariable(int, char *) { }

// 0x80288C94 | 100 bytes
void HUDTarget::GetLocalizable(char *) { }

// 0x80288CF8 | 1036 bytes
void HUDTarget::GetPlayerLocalizable(int, char *) { }

// 0x80289104 | 188 bytes
void HUDTarget::InitRepValues(void) { }

// 0x802891C0 | 196 bytes
void HUDTarget::GetReputationValue(int) { }

// 0x80289284 | 216 bytes
void HUDTarget::GetNextRepUnlockValue(int) { }

// 0x8028935C | 192 bytes
void HUDTarget::OnReadBar(int, unsigned int) { }

// 0x8028941C | 300 bytes
void HUDTarget::ReadMoodBar(int, unsigned int) { }

// 0x80289548 | 184 bytes
void HUDTarget::ShowHUD(void) { }

// 0x80289600 | 112 bytes
void HUDTarget::HideHUD(void) { }

// 0x80289670 | 48 bytes
void HUDTarget::OnPlayerHUDShow(int) { }

// 0x802896A0 | 44 bytes
void HUDTarget::OnPlayerHUDHide(int) { }

// 0x802896CC | 124 bytes
void HUDTarget::OnPlayerHUDHideStart(int) { }

// 0x80289748 | 44 bytes
void HUDTarget::OnHUDShow(void) { }

// 0x80289774 | 4 bytes
void HUDTarget::OnHUDHideStart(void) { }

// 0x80289778 | 44 bytes
void HUDTarget::OnHUDHide(void) { }

// 0x802897A4 | 1624 bytes
void HUDTarget::InstallHUDIcons(int) { }

// 0x80289DFC | 284 bytes
void HUDTarget::ShouldHUDBeVisible(int) const { }

// 0x80289F18 | 80 bytes
void HUDTarget::UpdateTutorialLocks(void) { }

// 0x80289F68 | 248 bytes
void HUDTarget::Update(void) { }

// 0x8028A060 | 276 bytes
void HUDTarget::UpdateClock(void) { }

// 0x8028A174 | 100 bytes
void HUDTarget::UpdateActivePlayer(int, bool) { }

// 0x8028A1D8 | 136 bytes
void HUDTarget::IsActionQueueAvailable(int) const { }

// 0x8028A260 | 1224 bytes
void HUDTarget::UpdateSpeedControls(void) { }

// 0x8028A728 | 168 bytes
void HUDTarget::AddMenu(int, cXObject *, BString2 &, unsigned int, ERShader *) { }

// 0x8028A7D0 | 180 bytes
void HUDTarget::AddMenuItem(int, cXObject *, Interaction *, BString2 &, unsigned int, ERShader *, int, bool) { }

// 0x8028A884 | 120 bytes
void HUDTarget::NotifyMenuRemoveObj(cXObject *) { }

// 0x8028A8FC | 136 bytes
void HUDTarget::CompleteMenu(int) { }

// 0x8028A984 | 136 bytes
void HUDTarget::ShowMenu(int) { }

// 0x8028AA0C | 120 bytes
void HUDTarget::IsMenuAvailable(int) const { }

// 0x8028AA84 | 44 bytes
void HUDTarget::CloseMenu(int) { }

// 0x8028AAB0 | 272 bytes
void HUDTarget::AddAction(int, Interaction *, BString2 &, unsigned int, ERShader *, unsigned int) { }

// 0x8028ABC0 | 88 bytes
void HUDTarget::RemoveAction(int, Interaction *) { }

// 0x8028AC18 | 84 bytes
void HUDTarget::RemoveAllActions(int) { }

// 0x8028AC6C | 172 bytes
void HUDTarget::Draw(ERC *) { }

// 0x8028AD18 | 4 bytes
void HUDTarget::DrawMotiveValues(ERC *, int) { }

// 0x8028AD1C | 244 bytes
void HUDTarget::ResetJobHudProperties(void) { }

// 0x8028AE10 | 252 bytes
void HUDTarget::RequestHUD(short, short, short) { }

// 0x8028AF0C | 80 bytes
void HUDTarget::AddHUDControl(short, short, short &) { }

// 0x8028AF5C | 104 bytes
void HUDTarget::RemoveHUDControl(short, short) { }

// 0x8028AFC4 | 200 bytes
void HUDTarget::ManageHUD(short, short, short) { }

// 0x8028B08C | 264 bytes
void HUDTarget::SetHUDData(short, short) { }

// 0x8028B194 | 148 bytes
void HUDTarget::SetJobBarInputRange(int, int, int) { }

// 0x8028B228 | 600 bytes
void HUDTarget::ApplyMotiveCurveArray(unsigned int, short) { }

// 0x8028B480 | 1200 bytes
void HUDTarget::CalculateJobScore(void) { }

// 0x8028B930 | 120 bytes
void HUDTarget::GetHUDData(short, short &) { }

// 0x8028B9A8 | 128 bytes
void HUDTarget::AnimateHUDControl(short, HUDTarget::EControlAnimType) { }

// 0x8028BA28 | 332 bytes
void HUDTarget::GotoCAS(unsigned short, unsigned short, int, int) { }

// 0x8028BB74 | 128 bytes
void HUDTarget::GotoMainMenu(void) { }

// 0x8028BBF4 | 136 bytes
void HUDTarget::RequestQuitGame(bool) { }

// 0x8028BC7C | 28 bytes
void HUDTarget::GetJobBarCount(void) { }

// 0x8028BC98 | 120 bytes
void HUDTarget::GetActionQueueHUD(int) { }

// 0x8028D3B0 | 24 bytes
void HUDTarget::GetHUDMode(void) const { }

// 0x8028D3C8 | 16 bytes
void HUDTarget::HUDHideComplete(void) const { }

// 0x8028D3D8 | 20 bytes
void HUDTarget::HideInProgress(void) const { }

// 0x8028D3EC | 20 bytes
void HUDTarget::IsHUDVisible(void) const { }

// 0x8028D400 | 24 bytes
void HUDTarget::IsPlayerHUDVisible(int) const { }

// 0x8028D418 | 8 bytes
void HUDTarget::GetHudTransitionTarget(void) { }
