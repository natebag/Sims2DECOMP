// invtarget_stubs.cpp - Stub implementations for Invtarget
// Auto-generated from symbols.json - 98 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x803266D8 | 5652 bytes
INVTarget::INVTarget(int) { }

// 0x80327CEC | 1812 bytes
INVTarget::~INVTarget(void) { }

// 0x80328400 | 92 bytes
void INVTarget::GetPlayerFunds(void) const { }

// 0x8032845C | 100 bytes
void INVTarget::SetPlayerFunds(int) { }

// 0x803284C0 | 176 bytes
void INVTarget::FormatMoneyString(int, bool, wchar_t *) { }

// 0x80328570 | 984 bytes
void INVTarget::SetVariable(char *, char *) { }

// 0x80328948 | 2368 bytes
void INVTarget::GetVariable(char *) { }

// 0x80329288 | 652 bytes
void INVTarget::GetLocalizable(char *) { }

// 0x80329514 | 656 bytes
void INVTarget::GetOnLocMsgInvObjectName(wchar_t *) { }

// 0x803297A4 | 476 bytes
void INVTarget::GetOnLocMsgInvObjectDescription(wchar_t *) { }

// 0x80329EC0 | 868 bytes
void INVTarget::Cheat_OnSetCurrentTabMode(int) { }

// 0x8032A224 | 836 bytes
void INVTarget::OnItemSelectedCheatMode(void) { }

// 0x8032A584 | 2084 bytes
void INVTarget::Cheat_InstallSelectedCategoryObjectShaders(int) { }

// 0x8032ADA8 | 164 bytes
void INVTarget::OnSetCurrentTab(int) { }

// 0x8032AE4C | 1348 bytes
void INVTarget::InstallInventoryPanelShaders(int) { }

// 0x8032B390 | 268 bytes
void INVTarget::UninstallInventoryPanelInfo(void) { }

// 0x8032B5B4 | 356 bytes
void INVTarget::SetupInteractorCamera(bool) { }

// 0x8032B718 | 88 bytes
void INVTarget::UpdateInputState(void) { }

// 0x8032B770 | 340 bytes
void INVTarget::CreateObjectMenuForBuyBuild(TNodeList<ISimInstance *> &) { }

// 0x8032B8C4 | 208 bytes
void INVTarget::PushPlaceFilter(void) { }

// 0x8032B994 | 292 bytes
void INVTarget::PushGrabFilter(void) { }

// 0x8032BAB8 | 212 bytes
void INVTarget::PopCurrentFilter(void) { }

// 0x8032BB8C | 184 bytes
void INVTarget::Cheat_HandleProgressDownHierarchy(char *) { }

// 0x8032BC44 | 220 bytes
void INVTarget::Cheat_HandleReturnUpHierarchy(char *) { }

// 0x8032BD20 | 960 bytes
void INVTarget::Cheat_HandleCellChange(void) { }

// 0x8032C0E0 | 72 bytes
void INVTarget::ClearAllCheatStrings(void) { }

// 0x8032C128 | 204 bytes
void INVTarget::SetCategoryCheatString(char *, int, char *) { }

// 0x8032C1F4 | 68 bytes
void INVTarget::SetPageIdxCheatString(char *, int) { }

// 0x8032C238 | 196 bytes
void INVTarget::SetFileNameCheatString(char *, int, char *) { }

// 0x8032C2FC | 200 bytes
void INVTarget::SetCatalogNameCheatString(char *, int, wchar_t *) { }

// 0x8032C3F8 | 276 bytes
void INVTarget::SetAllObjectRelatedCheatStrings(ObjSelector *) { }

// 0x8032C7BC | 88 bytes
void INVTarget::ClearAllObjRelatedCheatStrings(void) { }

// 0x8032C874 | 608 bytes
void INVTarget::FireCodeDialogSelectionCallback(int) { }

// 0x8032CAD8 | 76 bytes
void INVTarget::CannotGrabToInventoryDialogSelectionCallback(int) { }

// 0x8032CB54 | 272 bytes
void INVTarget::PlaceModeCallbackImpl(int *) { }

// 0x8032CCD8 | 592 bytes
void INVTarget::CommittChangesToInventory(int *) { }

// 0x8032CF28 | 256 bytes
void INVTarget::WallManipulatorCallbackImpl(int *) { }

// 0x8032D16C | 256 bytes
void INVTarget::WallPainterCallbackImpl(int *) { }

// 0x8032D354 | 144 bytes
void INVTarget::FloorModeCallbackImpl(int *) { }

// 0x8032D3E4 | 472 bytes
void INVTarget::GrabModeCallbackImpl(int *) { }

// 0x8032D630 | 504 bytes
void INVTarget::EnterPlaceAnyObjectModeUsingNewInteractorApi(ObjSelector *) { }

// 0x8032D828 | 440 bytes
void INVTarget::EnterGrabModeNewInteractorApi(void) { }

// 0x8032D9E0 | 564 bytes
void INVTarget::EnterPlaceModeUsingNewInteractorApi(ObjSelector *, unsigned char) { }

// 0x8032DCA8 | 5980 bytes
void INVTarget::InstallInvVariables(void) { }

// 0x8032F404 | 7124 bytes
void INVTarget::InstallShpVariables(void) { }

// 0x80330FD8 | 704 bytes
void INVTarget::AddObjSelectorToShopItemsDB(ObjSelector *) { }

// 0x80331298 | 520 bytes
void INVTarget::AddFloorTileToShopItemsDB(FloorTile *, int) { }

// 0x803314A0 | 520 bytes
void INVTarget::AddWallPaperToShopItemsDB(WallTile *, int) { }

// 0x803316A8 | 520 bytes
void INVTarget::AddWallToShopItemsDB(FenceData *, int) { }

// 0x803318B0 | 840 bytes
void INVTarget::Cheat_BuildCatalogDB(void) { }

// 0x80331BF8 | 1612 bytes
void INVTarget::BuildLotShopDB(void) { }

// 0x80332244 | 116 bytes
void INVTarget::SetOnMsgInvCurrentTab(char *) { }

// 0x803322B8 | 112 bytes
void INVTarget::SetOnMsgInvCurrentCell(char *) { }

// 0x80332390 | 656 bytes
void INVTarget::SetOnMsgInvPrepareObjectInfo(char *) { }

// 0x80332634 | 444 bytes
void INVTarget::SetOnMsgInvItemSelected(char *) { }

// 0x803327F0 | 168 bytes
void INVTarget::SetOnMsgInvGrabMode(char *) { }

// 0x803329B0 | 748 bytes
void INVTarget::SetOnMsgInvSellAllItems(char *) { }

// 0x80332C9C | 744 bytes
void INVTarget::SetOnMsgInvSellOneItem(char *) { }

// 0x80332FC8 | 308 bytes
void INVTarget::SetOnMsgInvShpPrepareObjectInfo(char *) { }

// 0x803330FC | 796 bytes
void INVTarget::PrepareObjectInfo(ObjSelector *, int, bool, unsigned char) { }

// 0x80333708 | 344 bytes
void INVTarget::ClearAllObjectInfoData(void) { }

// 0x80333860 | 212 bytes
void INVTarget::GetObjectRating(ObjSelector *, int &, int &) { }

// 0x80333934 | 404 bytes
void INVTarget::GetMotiveText(ObjSelector *, wchar_t *) { }

// 0x80333E8C | 136 bytes
void INVTarget::GetNumberOfBuildItemsToBuy(int, int) { }

// 0x80333F14 | 640 bytes
void INVTarget::SetOnMsgInvShpItemSelected(char *) { }

// 0x80334194 | 104 bytes
void INVTarget::SetOnMsgInvShpNextTab(char *) { }

// 0x803341FC | 108 bytes
void INVTarget::SetOnMsgInvShpPrevTab(char *) { }

// 0x80334268 | 148 bytes
void INVTarget::SetOnMsgInvShpCurrentCategory(char *) { }

// 0x803342FC | 376 bytes
void INVTarget::SetOnMsgInvShpSelectColor(char *) { }

// 0x803344B8 | 364 bytes
void INVTarget::InstallShoppingObjectShaders(int) { }

// 0x80334624 | 320 bytes
void INVTarget::InstallWallPaperShaders(vector<int, allocator<int> > *, int) { }

// 0x80334764 | 496 bytes
void INVTarget::InstallWallShaders(vector<int, allocator<int> > *, int) { }

// 0x80334954 | 320 bytes
void INVTarget::InstallFloorTileShaders(vector<int, allocator<int> > *, int) { }

// 0x80334A94 | 320 bytes
void INVTarget::InstallObjListShaders(vector<ObjSelector *, allocator<ObjSelector *> > *, int) { }

// 0x80334C2C | 264 bytes
void INVTarget::GetOnMsgInvSelectExitReset(char *) { }

// 0x80334D74 | 68 bytes
void INVTarget::GetOnMsgInvObjectInfoReady(char *) { }

// 0x80334ED4 | 248 bytes
void INVTarget::GetOnMsgInvShpItemCount(char *) { }

// 0x80335004 | 336 bytes
void INVTarget::GetOnLocMsgInvShpObjectName(wchar_t *) { }

// 0x80335154 | 208 bytes
void INVTarget::GetOnLocMsgInvShpObjectDescription(wchar_t *) { }

// 0x80335224 | 152 bytes
void INVTarget::GetOnLocMsgInvShpBudget(wchar_t *) { }

// 0x803352BC | 84 bytes
void INVTarget::GetOnLocMsgInvMotiveText(wchar_t *) { }

// 0x80335310 | 104 bytes
void INVTarget::GetOnLocMsgInvShpMotiveText(wchar_t *) { }

// 0x80335378 | 68 bytes
void INVTarget::GetOnMsgInvShpObjectInfoReady(char *) { }

// 0x803353BC | 988 bytes
void INVTarget::GetSelectedShoppingItem(int, int &, int &) { }

// 0x80335798 | 992 bytes
void INVTarget::GetOnMsgInvShpCanPurchase(char *) { }

// 0x80335B7C | 184 bytes
void INVTarget::GetOnMsgInvShpShpTabToInvTab(char *) { }

// 0x80335C34 | 784 bytes
void INVTarget::GetOnMsgInvShpCanColor(char *) { }

// 0x80335F44 | 256 bytes
void INVTarget::GetOnMsgInvShpColorN(char *, int) { }

// 0x80336078 | 68 bytes
void INVTarget::GetOnMsgInvShpCategoryCount(char *) { }

// 0x803360BC | 104 bytes
void INVTarget::GetOnMsgInvShpCategoryN(char *, int) { }

// 0x80336124 | 272 bytes
void INVTarget::ExitFloorTilingMode(bool) { }

// 0x8033627C | 728 bytes
void INVTarget::EnterWallBuildMode(int *, int) { }

// 0x80336554 | 724 bytes
void INVTarget::EnterWallPaperingMode(int *, int) { }

// 0x80336828 | 780 bytes
void INVTarget::EnterFloorTilingMode(int *, int) { }

// 0x80336B34 | 100 bytes
void INVTarget::IsPackagedItem(int *) { }

// 0x80336B98 | 108 bytes
void INVTarget::GetOnMsgInvShpIsPack(char *) { }

// 0x80336C04 | 140 bytes
void INVTarget::GetOnMsgInvHelpMode(char *) { }

// 0x80336CC8 | 68 bytes
void INVTarget::GetOnMsgInvBldDisplayInfo(char *) { }
