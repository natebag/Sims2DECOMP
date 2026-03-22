// castarget_stubs.cpp - Stub implementations for Castarget
// Auto-generated from symbols.json - 44 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x802987BC | 5348 bytes
CASTarget::CASTarget(bool) { }

// 0x80299CA0 | 712 bytes
CASTarget::~CASTarget(void) { }

// 0x80299F68 | 1760 bytes
void CASTarget::Init(bool) { }

// 0x8029A648 | 200 bytes
void CASTarget::Shutdown(void) { }

// 0x8029A710 | 820 bytes
void CASTarget::SaveSimToFamilySlot(int) { }

// 0x8029AA44 | 524 bytes
void CASTarget::SaveCASDataToNeighborhood(void) { }

// 0x8029AC50 | 688 bytes
void CASTarget::IsShutdown(void) { }

// 0x8029AF00 | 448 bytes
void CASTarget::StartupMediator(void) { }

// 0x8029B0C0 | 420 bytes
void CASTarget::ShutdownMediator(void) { }

// 0x8029B264 | 864 bytes
void CASTarget::ChangeMediator(int) { }

// 0x8029B5C4 | 176 bytes
void CASTarget::CreateScene(int) { }

// 0x8029B6C4 | 472 bytes
void CASTarget::SetVariable(char *, char *) { }

// 0x8029B89C | 1696 bytes
void CASTarget::GetLocalizable(char *) { }

// 0x8029BF3C | 676 bytes
void CASTarget::GetVariable(char *) { }

// 0x8029C1E0 | 504 bytes
void CASTarget::Update(void) { }

// 0x8029C3D8 | 444 bytes
void CASTarget::Draw(ERC *) { }

// 0x8029C594 | 132 bytes
void CASTarget::UnloadLastScreen(void) { }

// 0x8029C618 | 832 bytes
void CASTarget::SetVariableNav(char *) { }

// 0x8029C958 | 368 bytes
void CASTarget::SetVariableSubnav(char *) { }

// 0x8029CAC8 | 1556 bytes
void CASTarget::GetCurrentUIFocus(void) { }

// 0x8029D0DC | 140 bytes
void CASTarget::BroadcastNewFocus(void) { }

// 0x8029D168 | 600 bytes
void CASTarget::ConvertUIFocusToEventFocus(int) { }

// 0x8029D3C0 | 212 bytes
void CASTarget::HandleNav(int) { }

// 0x8029D494 | 168 bytes
void CASTarget::GotoScreen(UIScreenID) { }

// 0x8029D53C | 672 bytes
void CASTarget::GotoInitialScreen(void) { }

// 0x8029D7E4 | 68 bytes
void CASTarget::GotoGame(void) { }

// 0x8029D828 | 204 bytes
void CASTarget::GotoMainMenu(void) { }

// 0x8029D8F4 | 36 bytes
void CASTarget::GotoBase(void) { }

// 0x8029D918 | 152 bytes
void CASTarget::ReturnForwardToKeyboard(void) { }

// 0x8029D9B0 | 268 bytes
void CASTarget::SaveNameEnterCBA(void) { }

// 0x8029DABC | 208 bytes
void CASTarget::DontSaveNameEnterCBA(void) { }

// 0x8029DB8C | 3192 bytes
void CASTarget::HandleConditionalNav(int) { }

// 0x8029E828 | 64 bytes
void CASTarget::ShowAllCFAOptions(void) { }

// 0x8029E868 | 200 bytes
void CASTarget::ConvertPartUIFocusToModList(char *) { }

// 0x8029E930 | 124 bytes
void CASTarget::CreateModStrFromValues(char *, BitFlags<unsigned int>) { }

// 0x8029E9AC | 636 bytes
void CASTarget::SpawnYesNoDialog(unsigned int, unsigned wchar_t *, unsigned wchar_t *, int) { }

// 0x8029EC28 | 180 bytes
void CASTarget::DialogYesNoSelectionCallback(int) { }

// 0x8029ECE0 | 564 bytes
void CASTarget::SpawnOKDialog(unsigned wchar_t *, unsigned wchar_t *) { }

// 0x8029EF14 | 56 bytes
void CASTarget::DialogOKSelectionCallback(int) { }

// 0x8029EF60 | 84 bytes
void CASTarget::IsViewingMirror(void) { }

// 0x8029EFB4 | 84 bytes
void CASTarget::IsViewingGenetics(void) { }

// 0x8029F008 | 84 bytes
void CASTarget::ResetSimRotations(void) { }

// 0x8029F05C | 152 bytes
void CASTarget::DeallocateMorphResources(int) { }

// 0x802AE380 | 80 bytes
void CASTarget::SetHasSimInSlot(int, bool) { }
