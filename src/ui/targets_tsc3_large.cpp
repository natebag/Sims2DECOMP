// targets_tsc3_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: targets_tsc3.obj
// 89 functions, 46268 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// EYETarget::AddSetVar(SetVar *) - 0x801E8844 | 336 bytes
// ============================================================================
// NON_MATCHING
void EYETarget__AddSetVar(void* self, void* p1) {
    // Stack: 48 bytes
    // -> __builtin_new
    // -> sub_8039C304
    // -> memmove
    // -> __builtin_delete
    // -> sub_8039BE60
    // Contains loop(s)

    // Setter
}

// ============================================================================
// EYETarget::AddGetVar(GetVar *) - 0x801E8994 | 336 bytes
// ============================================================================
// NON_MATCHING
void EYETarget__AddGetVar(void* self, void* p1) {
    // Stack: 48 bytes
    // -> __builtin_new
    // -> sub_8039C304
    // -> memmove
    // -> __builtin_delete
    // -> sub_8039BE60
    // Contains loop(s)

    // Getter
}

// ============================================================================
// EYETarget::~EYETarget(void) - 0x801E8AE4 | 788 bytes
// ============================================================================
// NON_MATCHING
void EYETarget__dtor_EYETarget(void* self) {
    // Stack: 32 bytes
    // -> AptViewer::PopAptButtonFilter(int, unsigned int)
    // -> EyeToyClient::SetUnplugCallback(void (*)(int))
    // -> EyeToyClient::CloseSession(void)
    // -> MainHeap(void)
    // -> EAHeap::Free(void *)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // ... and 24 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Release resources
    // EAHeap::Free(void *) called for cleanup
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// EYETarget::RenderCallback(ERC *, structDrawCBparams *) - 0x801E8F94 | 420 bytes
// ============================================================================
// NON_MATCHING
void EYETarget__RenderCallback(void* self, void* p1, void* p2) {
    // Stack: 64 bytes
    // -> EyeToyClient::GetSessionTexture(void)
    // Uses floating point

    // Render pass
    // Computes positions/transforms
}

// ============================================================================
// SetVar_EYE_state::Handler(char *) - 0x801E948C | 352 bytes
// ============================================================================
// NON_MATCHING
void SetVar_EYE_state__Handler(void* self, char* p1) {
    // Stack: 32 bytes
    // -> AtoI(char *)
    // -> EyeToyClient::ApplyFunFrame(int)
    // -> EyeToyClient::ApplyPresetFilter(int)
    // -> EyeToyClient::StartStream(void)
    // -> EYETarget::SaveCurrentSetting(void)
    // -> EyeToyClient::StopStream(void)
    // ... and 3 more calls
    // Accesses globals via r13 (SDA)

    // Process/handle event
}

// ============================================================================
// FONTarget::~FONTarget(void) - 0x801EA07C | 484 bytes
// ============================================================================
// NON_MATCHING
void FONTarget__dtor_FONTarget(void* self) {
    // Stack: 16 bytes
    // -> InteractionHelper::~InteractionHelper(void)
    // -> AptViewer::PopAptButtonFilter(int, unsigned int)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 22 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// FONTarget::SetupNames(IHRecord *, int) - 0x801EA260 | 308 bytes
// ============================================================================
// NON_MATCHING
void FONTarget__SetupNames(void* self, void* p1, int p2) {
    // Stack: 128 bytes
    // -> Sprintf(char *, char *,...)
    // -> strcat
    // -> BString2::c_str(void) const
    // -> UIDB::UIDBSetString(char *, unsigned wchar_t *)
    // Contains loop(s)

    // Setter
}

// ============================================================================
// FONTarget::GetVariable(char *) - 0x801EA394 | 376 bytes
// ============================================================================
// NON_MATCHING
void* FONTarget__GetVariable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> InteractionHelper::GetCount(IHRecord *)
    // -> FONTarget::SetupNames(IHRecord *, int)
    // -> Sprintf(char *, char *,...)

    // Getter
    return 0;
}

// ============================================================================
// FONTarget::SetVariable(char *, char *) - 0x801EA50C | 436 bytes
// ============================================================================
// NON_MATCHING
void FONTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 24 bytes
    // -> strcmp
    // -> AtoI(char *)
    // -> InteractionHelper::FindRecord(int)
    // -> Interaction::GetPerson(void) const
    // -> InteractionHelper::GetCount(IHRecord *)
    // -> FONTarget::SetupNames(IHRecord *, int)

    // Setter
}

// ============================================================================
// GOLTarget::~GOLTarget(void) - 0x801EB32C | 432 bytes
// ============================================================================
// NON_MATCHING
void GOLTarget__dtor_GOLTarget(void* self) {
    // Stack: 16 bytes
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // -> UIUserDrawCBTable::UnInstallAllName(char *)
    // ... and 19 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// GOLTarget::GetVariable(char *) - 0x801EB6D4 | 844 bytes
// ============================================================================
// NON_MATCHING
void* GOLTarget__GetVariable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> strncmp
    // -> AtoI(char *)
    // -> GOLTarget::IsMapGoalUnlocked(int, int, int)
    // -> GOLTarget::IsApartmentUnlocked(int, int)
    // ... and 3 more calls

    // Getter
    return 0;
}

// ============================================================================
// StaticGetShaderDimensions(ERShader *, unsigned int &, unsigned int &) - 0x801EC158 | 260 bytes
// ============================================================================
// NON_MATCHING
void StaticGetShaderDimensions(void* p1, int p2, int p3) {
    // Stack: 24 bytes
    // -> EShader::GetTexture(int) const

    // Getter
}

// ============================================================================
// StaticSetupFireCodeDialog(INVTarget *, UIDialog &, int) - 0x801EC25C | 768 bytes
// ============================================================================
// NON_MATCHING
void StaticSetupFireCodeDialog(void* p1, void* p2, int p3) {
    // Stack: 152 bytes
    // -> EGlobal::GetNewUIString(char *)
    // -> BString2::assign(unsigned wchar_t *)
    // -> Sprintf(char *, char *,...)
    // -> BString2::BString2(void)
    // -> BString2::operator=(BString2 &)
    // -> BString2::~BString2(void)
    // ... and 3 more calls

    // Setter
}

// ============================================================================
// StaticSetupInventoryFullDialog(INVTarget *, UIDialog &, eInvFullDialogType) - 0x801EC55C | 824 bytes
// ============================================================================
// NON_MATCHING
void StaticSetupInventoryFullDialog(void* p1, void* p2, void* p3) {
    // Stack: 104 bytes
    // -> EGlobal::GetNewUIString(char *)
    // -> BString2::assign(unsigned wchar_t *)
    // -> BString2::BString2(void)
    // -> BString2::operator=(BString2 &)
    // -> BString2::~BString2(void)
    // -> EResourceManager::AddRef(unsigned int, EFile *, int)
    // ... and 2 more calls
    // Contains loop(s)

    // Setter
}

// ============================================================================
// StaticSetupCannotGrabToInventoryDialog(INVTarget *, UIDialog &) - 0x801EC894 | 768 bytes
// ============================================================================
// NON_MATCHING
void StaticSetupCannotGrabToInventoryDialog(void* p1, void* p2) {
    // Stack: 104 bytes
    // -> EGlobal::GetPDAString(char *)
    // -> BString2::assign(unsigned wchar_t *)
    // -> EGlobal::GetNewUIString(char *)
    // -> BString2::BString2(void)
    // -> BString2::operator=(BString2 &)
    // -> BString2::~BString2(void)
    // ... and 3 more calls

    // Setter
}

// ============================================================================
// INVTarget::SetVariable(char *, char *) - 0x801EE314 | 888 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 24 bytes
    // -> strcmp
    // -> INVTarget::SetOnMsgInvCurrentTab(char *)
    // -> INVTarget::SetOnMsgInvCurrentCell(char *)
    // -> INVTarget::SetOnMsgInvNextTab(char *)
    // -> INVTarget::SetOnMsgInvPrevTab(char *)
    // -> INVTarget::SetOnMsgInvPrepareObjectInfo(char *)
    // ... and 15 more calls

    // Setter
}

// ============================================================================
// INVTarget::GetLocalizable(char *) - 0x801EEFB4 | 408 bytes
// ============================================================================
// NON_MATCHING
void* INVTarget__GetLocalizable(void* self, char* p1) {
    // Stack: 8208 bytes
    // -> strcmp
    // -> INVTarget::GetOnLocMsgInvObjectName(unsigned wchar_t *)
    // -> INVTarget::GetOnLocMsgInvObjectDescription(unsigned wchar_t *)
    // -> INVTarget::GetOnLocMsgInvShpObjectDescription(unsigned wchar_t *)
    // -> INVTarget::GetOnLocMsgInvShpObjectName(unsigned wchar_t *)
    // -> INVTarget::GetOnLocMsgInvShpBudget(unsigned wchar_t *)
    // ... and 6 more calls

    // Getter
    return 0;
}

// ============================================================================
// INVTarget::GetOnLocMsgInvObjectName(unsigned wchar_t *) - 0x801EF14C | 536 bytes
// ============================================================================
// NON_MATCHING
void* INVTarget__GetOnLocMsgInvObjectName(void* self, void* p1) {
    // Stack: 40 bytes
    // -> BBI::InventoryItem::GetItemCategory(void) const
    // -> BBI::InventoryItem::GetItemGuid(void) const
    // -> BBI::InventoryItem::GetItemSubcategory(void) const
    // -> EGlobal::GetNewUIString(char *)
    // -> ObjSelector::GetMasterSelector(void)
    // -> ObjSelector::GetCatalogName(void)
    // ... and 1 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// INVTarget::GetOnLocMsgInvObjectDescription(unsigned wchar_t *) - 0x801EF364 | 340 bytes
// ============================================================================
// NON_MATCHING
void* INVTarget__GetOnLocMsgInvObjectDescription(void* self, void* p1) {
    // Stack: 32 bytes
    // -> BBI::InventoryItem::GetItemCategory(void) const
    // -> BBI::InventoryItem::GetItemGuid(void) const
    // -> BBI::InventoryItem::GetItemSubcategory(void) const
    // -> ObjSelector::GetMasterSelector(void)
    // -> ObjSelector::GetCatalogDescription(void)
    // -> wcscpy
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// INVTarget::Cheat_OnSetCurrentTabMode(int) - 0x801EF500 | 624 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__Cheat_OnSetCurrentTabMode(void* self, int p1) {
    // Stack: 40 bytes
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // -> INVTarget::SetCategoryCheatString(char *, int, char *)
    // -> INVTarget::Cheat_InstallSelectedCategoryObjectShaders(int)
    // -> INVTarget::SetPageIdxCheatString(char *, int)
    // Contains loop(s)

    // Setter
}

// ============================================================================
// INVTarget::OnItemSelectedCheatMode(void) - 0x801EF770 | 656 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__OnItemSelectedCheatMode(void* self) {
    // Stack: 24 bytes
    // -> INVTarget::ClearAllCheatStrings(void)
    // -> puts
    // -> abort
    // -> INVTarget::EnterPlaceAnyObjectModeUsingNewInteractorApi(ObjSelector *)
    // -> INVTarget::EnterWallBuildMode(InteractorModule::WallData *, INVTarget::eInteractorMode)
    // -> INVTarget::EnterWallPaperingMode(InteractorModule::WallPaperData *, INVTarget::eInteractorMode)
    // ... and 1 more calls

}

// ============================================================================
// INVTarget::InstallInventoryPanelShaders(int) - 0x801F00F4 | 780 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__InstallInventoryPanelShaders(void* self, int p1) {
    // Stack: 128 bytes
    // -> BBI::InventoryItems::CountItemsByCategory(BBI::InventoryItem::eItemCategory) const
    // -> memset
    // -> BBI::InventoryItems::GetItemsByCategory(BBI::InventoryItem::eItemCategory, BBI::InventoryItem **, unsigned int) const
    // -> BBI::InventoryItem::GetItemSubcategory(void) const
    // -> BBI::InventoryItem::GetItemGuid(void) const
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // ... and 5 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// INVTarget::Cheat_HandleCellChange(void) - 0x801F0988 | 888 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__Cheat_HandleCellChange(void* self) {
    // Stack: 16 bytes
    // -> puts
    // -> abort
    // -> INVTarget::SetAllObjectRelatedCheatStrings(ObjSelector *)
    // -> INVTarget::SetAllObjectRelatedCheatStrings(InteractorModule::WallData *)
    // -> INVTarget::ClearAllCheatStrings(void)
    // -> INVTarget::SetAllObjectRelatedCheatStrings(InteractorModule::WallPaperData *)
    // ... and 3 more calls

    // Process/handle event
}

// ============================================================================
// INVTarget::FireCodeDialogSelectionCallback(int) - 0x801F1254 | 536 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__FireCodeDialogSelectionCallback(void* self, int p1) {
    // Stack: 48 bytes
    // -> BBI::InventoryItem::GetItemCategory(void) const
    // -> BBI::InventoryItem::GetItemSubcategory(void) const
    // -> BBI::InventoryItem::GetItemGuid(void) const
    // -> INVTarget::EnterWallBuildMode(InteractorModule::WallData *, INVTarget::eInteractorMode)
    // -> BBI::InventoryItem::GetItemColorIndex(void) const
    // -> INVTarget::EnterPlaceModeUsingNewInteractorApi(ObjSelector *, unsigned char)
    // ... and 2 more calls
    // Accesses globals via r13 (SDA)

    // Callback handler
}

// ============================================================================
// INVTarget::PlaceModeCallbackImpl(InteractorModule::PlaceManipulator::CallbackData *) - 0x801F14EC | 272 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__PlaceModeCallbackImpl(void* self, void* p1) {
    // Stack: 24 bytes
    // -> INVTarget::UninstallInventoryPanelInfo(void)
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::ChangeActiveInteractorToNull(int)
    // -> INVTarget::SetupInteractorCamera(bool)
    // -> BBI::InventoryItems::RemoveItemsByGuid(int, int, unsigned char)
    // -> BBI::InventoryItems::GetItemByGuid(int, unsigned char) const
    // ... and 3 more calls
    // Uses floating point

    // Callback handler
}

// ============================================================================
// INVTarget::CommittChangesToInventory(InteractorModule::WallManipulator::CallbackData *) - 0x801F1624 | 592 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__CommittChangesToInventory(void* self, void* p1) {
    // Stack: 40 bytes
    // -> BBI::InventoryItems::AddBuilderItem(BBI::InventoryItem::eItemSubcategory, int, int)
    // -> BBI::InventoryItems::RemoveBuilderItem(BBI::InventoryItem::eItemSubcategory, int, int)
    // Contains loop(s)

    // Callback handler
}

// ============================================================================
// INVTarget::GrabModeCallbackImpl(InteractorModule::GrabManipulator::CallbackData *) - 0x801F1C4C | 400 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__GrabModeCallbackImpl(void* self, void* p1) {
    // Stack: 32 bytes
    // -> INVTarget::UninstallInventoryPanelInfo(void)
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::ChangeActiveInteractorToNull(int)
    // -> INVTarget::SetupInteractorCamera(bool)
    // -> StaticExtractObjSelectorGuidFromObject(cXObject *)
    // -> BBI::InventoryItems::CanAddItemsByGuid(int, int, unsigned char) const
    // ... and 5 more calls
    // Accesses globals via r13 (SDA)

    // Callback handler
}

// ============================================================================
// INVTarget::EnterPlaceAnyObjectModeUsingNewInteractorApi(ObjSelector *) - 0x801F1E04 | 444 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__EnterPlaceAnyObjectModeUsingNewInteractorApi(void* self, void* p1) {
    // Stack: 112 bytes
    // -> INVTarget::StartActionMenu(void)
    // -> ObjSelector::GetGUID(void) const
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::IsValidPlayerId(int) const
    // -> __builtin_new
    // -> INVTarget::SetupInteractorCamera(bool)
    // ... and 1 more calls
    // Contains loop(s)

}

// ============================================================================
// INVTarget::EnterGrabModeNewInteractorApi(void) - 0x801F1FC0 | 440 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__EnterGrabModeNewInteractorApi(void* self) {
    // Stack: 112 bytes
    // -> INVTarget::StartActionMenu(void)
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::IsValidPlayerId(int) const
    // -> __builtin_new
    // -> INVTarget::SetupInteractorCamera(bool)
    // -> INVTarget::ClearAllCheatStrings(void)
    // Contains loop(s)
    // Uses floating point

}

// ============================================================================
// INVTarget::EnterPlaceModeUsingNewInteractorApi(ObjSelector *, unsigned char) - 0x801F2178 | 504 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__EnterPlaceModeUsingNewInteractorApi(void* self, void* p1, u8* p2) {
    // Stack: 104 bytes
    // -> EMemoryMeterWin::PollMemoryLevels(void)
    // -> INVTarget::EnterGrabModeNewInteractorApi(void)
    // -> INVTarget::StartActionMenu(void)
    // -> ObjSelector::GetGUID(void) const
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::IsValidPlayerId(int) const
    // ... and 3 more calls
    // Contains loop(s)
    // Uses floating point

}

// ============================================================================
// INVTarget::AddObjSelectorToShopItemsDB(ObjSelector *) - 0x801F3380 | 592 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__AddObjSelectorToShopItemsDB(void* self, void* p1) {
    // Stack: 48 bytes
    // -> ObjSelector::GetMasterSelector(void)
    // -> __builtin_new
    // -> sub_8039C304
    // -> memmove
    // -> __builtin_delete
    // -> sub_8039BE60
    // Contains loop(s)

    // Add element
}

// ============================================================================
// INVTarget::AddFloorTileToShopItemsDB(FloorTile *, int) - 0x801F35D0 | 440 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__AddFloorTileToShopItemsDB(void* self, void* p1, int p2) {
    // Stack: 48 bytes
    // -> __builtin_new
    // -> sub_8039C304
    // -> __builtin_delete
    // -> sub_8039BE60
    // Contains loop(s)

    // Add element
}

// ============================================================================
// INVTarget::AddWallPaperToShopItemsDB(WallTile *, int) - 0x801F3788 | 440 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__AddWallPaperToShopItemsDB(void* self, void* p1, int p2) {
    // Stack: 48 bytes
    // -> __builtin_new
    // -> sub_8039C304
    // -> __builtin_delete
    // -> sub_8039BE60
    // Contains loop(s)

    // Add element
}

// ============================================================================
// INVTarget::AddWallToShopItemsDB(FenceData *, int) - 0x801F3940 | 440 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__AddWallToShopItemsDB(void* self, void* p1, int p2) {
    // Stack: 48 bytes
    // -> __builtin_new
    // -> sub_8039C304
    // -> __builtin_delete
    // -> sub_8039BE60
    // Contains loop(s)

    // Add element
}

// ============================================================================
// INVTarget::Cheat_BuildCatalogDB(void) - 0x801F3AF8 | 840 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__Cheat_BuildCatalogDB(void* self) {
    // Stack: 40 bytes
    // -> __builtin_new
    // -> INVTarget::AddObjSelectorToShopItemsDB(ObjSelector *)
    // -> INVTarget::AddFloorTileToShopItemsDB(FloorTile *, int)
    // -> INVTarget::AddWallPaperToShopItemsDB(WallTile *, int)
    // -> INVTarget::AddWallToShopItemsDB(FenceData *, int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// INVTarget::SetOnMsgInvPrepareObjectInfo(char *) - 0x801F4584 | 512 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__SetOnMsgInvPrepareObjectInfo(void* self, char* p1) {
    // Stack: 56 bytes
    // -> BBI::InventoryItem::GetItemCategory(void) const
    // -> BBI::InventoryItem::GetItemGuid(void) const
    // -> BBI::InventoryItem::GetItemCount(void) const
    // -> BBI::InventoryItem::GetItemSubcategory(void) const
    // -> INVTarget::PrepareObjectInfo(InteractorModule::WallData *, int, bool)
    // -> INVTarget::PrepareObjectInfo(InteractorModule::FloorData *, int, bool)
    // ... and 3 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// INVTarget::SetOnMsgInvItemSelected(char *) - 0x801F4798 | 424 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__SetOnMsgInvItemSelected(void* self, char* p1) {
    // Stack: 24 bytes
    // -> AtoI(char *)
    // -> INVTarget::OnItemSelectedCheatMode(void)
    // -> BBI::InventoryItems::GetItemAtIndex(int) const
    // -> EMemoryMeterWin::PollMemoryLevels(void)
    // -> StaticSetupFireCodeDialog(INVTarget *, UIDialog &, int)
    // -> UIDialog::SpawnDialog(void)
    // ... and 1 more calls
    // Uses floating point

    // Setter
}

// ============================================================================
// INVTarget::SetOnMsgInvSellAllItems(char *) - 0x801F4AB8 | 652 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__SetOnMsgInvSellAllItems(void* self, char* p1) {
    // Stack: 40 bytes
    // -> AtoI(char *)
    // -> BBI::InventoryItem::GetItemGuid(void) const
    // -> BBI::InventoryItem::GetItemCategory(void) const
    // -> BBI::InventoryItem::GetItemCount(void) const
    // -> BBI::InventoryItem::GetItemSubcategory(void) const
    // -> StaticCalcRefundAmount_Pack(int, int, int)
    // ... and 6 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// INVTarget::SetOnMsgInvSellOneItem(char *) - 0x801F4D44 | 648 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__SetOnMsgInvSellOneItem(void* self, char* p1) {
    // Stack: 40 bytes
    // -> AtoI(char *)
    // -> BBI::InventoryItem::GetItemGuid(void) const
    // -> BBI::InventoryItem::GetItemCategory(void) const
    // -> BBI::InventoryItem::GetItemSubcategory(void) const
    // -> StaticCalcRefundAmount_Pack(int, int, int)
    // -> BBI::InventoryItems::RemoveBuilderItem(BBI::InventoryItem::eItemSubcategory, int, int)
    // ... and 5 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// INVTarget::PrepareObjectInfo(ObjSelector *, int, bool, unsigned char) - 0x801F50F4 | 576 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__PrepareObjectInfo(void* self, void* p1, int p2, int p3, u8* p4) {
    // Stack: 576 bytes
    // -> INVTarget::ClearAllObjectInfoData(void)
    // -> memset
    // -> StaticGetObjectValue(ObjSelector *)
    // -> StaticCalcRefundAmount_Single(int, int)
    // -> INVTarget::FormatMoneyString(int, bool, unsigned wchar_t *)
    // -> UIDB::UIDBSetString(char *, unsigned wchar_t *)
    // ... and 6 more calls

}

// ============================================================================
// INVTarget::ClearAllObjectInfoData(void) - 0x801F5570 | 260 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__ClearAllObjectInfoData(void* self) {
    // Stack: 88 bytes
    // -> memset
    // -> UIDB::UIDBSetString(char *, unsigned wchar_t *)
    // -> UI3D::UnInstallEntry(char *)

}

// ============================================================================
// INVTarget::GetMotiveText(ObjSelector *, unsigned wchar_t *) - 0x801F570C | 404 bytes
// ============================================================================
// NON_MATCHING
void* INVTarget__GetMotiveText(void* self, void* p1, void* p2) {
    // Stack: 112 bytes
    // -> ObjSelector::GetMasterSelector(void)
    // -> INVTarget::GetObjectRating(ObjSelector *, int &, int &)
    // -> memset
    // -> EGlobal::GetNewUIString(char *)
    // -> StaticNumberToWideString(int, unsigned wchar_t *)
    // -> wcscpy
    // ... and 1 more calls

    // Getter
    return 0;
}

// ============================================================================
// INVTarget::GetMotiveText(BBI::InventoryItem *, unsigned wchar_t *) - 0x801F5908 | 396 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__GetMotiveText_InvItem(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> BBI::InventoryItem::GetItemCategory(void) const
    // -> BBI::InventoryItem::GetItemSubcategory(void) const
    // -> EGlobal::GetPDAString(char *)
    // -> BBI::InventoryItem::GetItemGuid(void) const
    // -> INVTarget::GetMotiveText(int, unsigned wchar_t *)
    // -> wcscpy

}

// ============================================================================
// INVTarget::SetOnMsgInvShpItemSelected(char *) - 0x801F5C28 | 560 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__SetOnMsgInvShpItemSelected(void* self, char* p1) {
    // Stack: 40 bytes
    // -> INVTarget::GetSelectedShoppingItem(int, InteractorModule::ShoppingItem &, int &)
    // -> BBI::InventoryItems::AddBuilderItem(BBI::InventoryItem::eItemSubcategory, int, int)
    // -> ObjSelector::GetGUID(void) const
    // -> StaticGetObjectValue(ObjSelector *)
    // -> INVTarget::GetSelectedShoppingCategory(void)
    // -> ConvertShoppingCategoryToInventoryCategory(int)
    // ... and 2 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// INVTarget::InstallWallShaders(vector<InteractorModule::WallData, allocator<InteractorModule::WallData> > *, int) - 0x801F6254 | 324 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__InstallWallShaders(void* self, void* p1, void* p2, int p3) {
    // Stack: 48 bytes
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // -> puts
    // -> abort
    // -> StaticGetShaderId(InteractorModule::WallData *)
    // Contains loop(s)

}

// ============================================================================
// INVTarget::GetSelectedShoppingItem(int, InteractorModule::ShoppingItem &, int &) - 0x801F6CA0 | 488 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__GetSelectedShoppingItem(void* self, int p1, void* p2, int p3) {
    // Stack: 32 bytes
    // -> INVTarget::GetSelectedShoppingCategoryListIdx(void)
    // -> puts
    // -> abort

}

// ============================================================================
// INVTarget::GetOnMsgInvShpCanPurchase(char *) - 0x801F6E88 | 708 bytes
// ============================================================================
// NON_MATCHING
void* INVTarget__GetOnMsgInvShpCanPurchase(void* self, char* p1) {
    // Stack: 48 bytes
    // -> INVTarget::GetSelectedShoppingItem(int, InteractorModule::ShoppingItem &, int &)
    // -> BBI::InventoryItems::CanAddBuilderItem(BBI::InventoryItem::eItemSubcategory, int, int) const
    // -> ObjSelector::GetGUID(void) const
    // -> BBI::InventoryItems::CanAddItemsByGuid(int, int, unsigned char) const
    // -> StaticSetupInventoryFullDialog(INVTarget *, UIDialog &, eInvFullDialogType)
    // -> UIDialog::SpawnDialog(void)
    // ... and 4 more calls

    // Getter
    return 0;
}

// ============================================================================
// INVTarget::GetOnMsgInvShpCanColor(char *) - 0x801F71B8 | 516 bytes
// ============================================================================
// NON_MATCHING
void* INVTarget__GetOnMsgInvShpCanColor(void* self, char* p1) {
    // Stack: 56 bytes
    // -> INVTarget::GetSelectedShoppingItem(int, InteractorModule::ShoppingItem &, int &)
    // -> StaticGetShaderId(InteractorModule::WallData *)
    // -> StaticGetShaderId(InteractorModule::WallPaperData *)
    // -> StaticGetShaderId(InteractorModule::FloorData *)
    // -> EResourceManager::AddRef(unsigned int, EFile *, int)
    // -> EResourceManager::DelRef(unsigned int, EResourceManager::DelRefMode)
    // ... and 6 more calls

    // Getter
    return 0;
}

// ============================================================================
// INVTarget::ExitFloorTilingMode(bool) - 0x801F7550 | 272 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__ExitFloorTilingMode(void* self, int p1) {
    // Stack: 24 bytes
    // -> INVTarget::SetInvBldItemCount(void)
    // -> INVTarget::UninstallInventoryPanelInfo(void)
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::ChangeActiveInteractorToNull(int)
    // -> INVTarget::SetupInteractorCamera(bool)
    // -> BBI::InventoryItems::AddBuilderItem(BBI::InventoryItem::eItemSubcategory, int, int)
    // ... and 1 more calls
    // Contains loop(s)

}

// ============================================================================
// INVTarget::EnterWallBuildMode(InteractorModule::WallData *, INVTarget::eInteractorMode) - 0x801F76A8 | 636 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__EnterWallBuildMode(void* self, void* p1, void* p2) {
    // Stack: 88 bytes
    // -> INVTarget::ClearAllCheatStrings(void)
    // -> BBI::InventoryItems::GetBuilderItem(BBI::InventoryItem::eItemSubcategory, int) const
    // -> BBI::InventoryItem::GetItemCount(void) const
    // -> INVTarget::SetupInteractorCamera(bool)
    // -> INVTarget::SetInvBldItemCount(void)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // ... and 3 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// INVTarget::EnterWallPaperingMode(InteractorModule::WallPaperData *, INVTarget::eInteractorMode) - 0x801F7924 | 632 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__EnterWallPaperingMode(void* self, void* p1, void* p2) {
    // Stack: 96 bytes
    // -> INVTarget::ClearAllCheatStrings(void)
    // -> BBI::InventoryItems::GetBuilderItem(BBI::InventoryItem::eItemSubcategory, int) const
    // -> BBI::InventoryItem::GetItemCount(void) const
    // -> INVTarget::SetupInteractorCamera(bool)
    // -> INVTarget::SetInvBldItemCount(void)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // ... and 3 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// INVTarget::EnterFloorTilingMode(InteractorModule::FloorData *, INVTarget::eInteractorMode) - 0x801F7B9C | 688 bytes
// ============================================================================
// NON_MATCHING
void INVTarget__EnterFloorTilingMode(void* self, void* p1, void* p2) {
    // Stack: 88 bytes
    // -> INVTarget::ClearAllCheatStrings(void)
    // -> BBI::InventoryItems::GetBuilderItem(BBI::InventoryItem::eItemSubcategory, int) const
    // -> BBI::InventoryItem::GetItemCount(void) const
    // -> INVTarget::SetupInteractorCamera(bool)
    // -> INVTarget::SetInvBldItemCount(void)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // ... and 3 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// INTTarget::~INTTarget(void) - 0x801F8720 | 436 bytes
// ============================================================================
// NON_MATCHING
void INTTarget__dtor_INTTarget(void* self) {
    // Stack: 16 bytes
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // ... and 7 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// INTTarget::SetVariable(char *, char *) - 0x801F88D4 | 272 bytes
// ============================================================================
// NON_MATCHING
void INTTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 56 bytes
    // -> isdigit
    // -> strcmp
    // -> UIReflow::ResetSwfAnimation(char *, char *, int)
    // -> UIReflow::ResetVisibility(char *, bool, int)
    // -> Sprintf(char *, char *,...)
    // -> BString2::assignDebug(char *)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// INTTarget::GetLocalizable(char *) - 0x801F8A7C | 324 bytes
// ============================================================================
// NON_MATCHING
void* INTTarget__GetLocalizable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> BString2::c_str(void) const
    // -> wcscat
    // -> wcslen
    // ... and 3 more calls
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// INTTarget::Update(void) - 0x801F8BC0 | 472 bytes
// ============================================================================
// NON_MATCHING
void INTTarget__Update(void* self) {
    // Stack: 24 bytes
    // -> UIReflow::OpenTweenBlock(char *, unsigned int, unsigned int, char *, int)
    // -> UIReflow::Tween_Alpha(unsigned int)
    // -> UIReflow::SubmitTweenBlock(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_X(int)
    // ... and 4 more calls
    // Accesses globals via r13 (SDA)

    // Per-frame update
}

// ============================================================================
// INTTarget::SetInteractionDisplayValues(unsigned int, unsigned int) - 0x801F8E94 | 328 bytes
// ============================================================================
// NON_MATCHING
void INTTarget__SetInteractionDisplayValues(void* self, int p1, int p2) {
    // Stack: 88 bytes
    // -> Sprintf(char *, char *,...)
    // -> BString2::BString2(void)
    // -> BString2::assignDebug(char *)
    // -> BString2::assign(unsigned wchar_t *)
    // -> operator+(BString2 &, BString2 &)
    // -> BString2::operator=(BString2 &)
    // ... and 2 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// INTTarget::TriggerInteractionAnimation(unsigned int, unsigned int, unsigned int) - 0x801F8FDC | 376 bytes
// ============================================================================
// NON_MATCHING
void INTTarget__TriggerInteractionAnimation(void* self, int p1, int p2, int p3) {
    // Stack: 96 bytes
    // -> Sprintf(char *, char *,...)
    // -> BString2::BString2(void)
    // -> BString2::assignDebug(char *)
    // -> BString2::assign(unsigned wchar_t *)
    // -> operator+(BString2 &, BString2 &)
    // -> BString2::operator=(BString2 &)
    // ... and 2 more calls
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// KEYTarget::~KEYTarget(void) - 0x801F9804 | 348 bytes
// ============================================================================
// NON_MATCHING
void KEYTarget__dtor_KEYTarget(void* self) {
    // Stack: 16 bytes
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // -> UIUserDrawCBTable::UnInstallAllName(char *)
    // ... and 4 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// KEYTarget::SetVariable(char *, char *) - 0x801F9A1C | 428 bytes
// ============================================================================
// NON_MATCHING
void KEYTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 32 bytes
    // -> strcmp
    // -> AtoI(char *)
    // -> KEYTarget::IsModeValid(void)
    // -> KEYTarget::GetName(void)
    // -> wcslen
    // -> EGlobal::GetNewUIString(char *)
    // ... and 4 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// KEYTarget::GetVariable(char *) - 0x801F9BC8 | 384 bytes
// ============================================================================
// NON_MATCHING
void* KEYTarget__GetVariable(void* self, char* p1) {
    // Stack: 40 bytes
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> Snprintf(char *, unsigned int, char *,...)
    // -> KEYTarget::IsModeValid(void)
    // -> KEYTarget::GetName(void)
    // -> wcslen
    // ... and 2 more calls
    // Uses floating point

    // Getter
    return 0;
}

// ============================================================================
// MSGTarget::~MSGTarget(void) - 0x801FA99C | 488 bytes
// ============================================================================
// NON_MATCHING
void MSGTarget__dtor_MSGTarget(void* self) {
    // Stack: 16 bytes
    // -> AptViewer::PopAptButtonFilter(int, unsigned int)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // ... and 21 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// MSGTarget::SetupTitles(int) - 0x801FAB84 | 320 bytes
// ============================================================================
// NON_MATCHING
void MSGTarget__SetupTitles(void* self, int p1) {
    // Stack: 112 bytes
    // -> Sprintf(char *, char *,...)
    // -> strcat
    // -> EGlobal::GetMessagesTableRow(unsigned int)
    // -> UIDB::UIDBSetString(char *, unsigned wchar_t *)
    // Contains loop(s)

    // Setter
}

// ============================================================================
// MSGTarget::GetVariable(char *) - 0x801FACC4 | 368 bytes
// ============================================================================
// NON_MATCHING
void* MSGTarget__GetVariable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> Sprintf(char *, char *,...)
    // -> strncmp
    // -> AtoI(char *)
    // Contains loop(s)

    // Getter
    return 0;
}

// ============================================================================
// MSGTarget::SetVariable(char *, char *) - 0x801FAE34 | 744 bytes
// ============================================================================
// NON_MATCHING
void MSGTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 48 bytes
    // -> strcmp
    // -> AtoI(char *)
    // -> EGlobal::GetMessagesTableRow(unsigned int)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> ObjSelector::GetUserName(void)
    // -> BString2::operator=(BString2 &)
    // ... and 3 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// MSGTarget::GetLocalizable(char *) - 0x801FB11C | 276 bytes
// ============================================================================
// NON_MATCHING
void* MSGTarget__GetLocalizable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> BString2::c_str(void) const
    // -> wcscpy
    // -> wcslen
    // -> UIQDTarget::UIQDSubstitutionStrings(unsigned wchar_t *)
    // ... and 1 more calls

    // Getter
    return 0;
}

// ============================================================================
// OPTTarget::~OPTTarget(void) - 0x801FBA98 | 324 bytes
// ============================================================================
// NON_MATCHING
void OPTTarget__dtor_OPTTarget(void* self) {
    // Stack: 16 bytes
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // -> UIUserDrawCBTable::UnInstallAllName(char *)
    // ... and 4 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// OPTTarget::SetVariable(char *, char *) - 0x801FBBDC | 832 bytes
// ============================================================================
// NON_MATCHING
void OPTTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 32 bytes
    // -> strcmp
    // -> AtoF(char *)
    // -> cSoundPlayer::SetOldFXVolume(int)
    // -> cSoundPlayer::SetMusicVolume(int)
    // -> OPTTarget::GetScreenXGlobal(float)
    // -> OPTTarget::GetScreenYGlobal(float)
    // ... and 6 more calls
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// OPTTarget::GetVariable(char *) - 0x801FBF1C | 912 bytes
// ============================================================================
// NON_MATCHING
void* OPTTarget__GetVariable(void* self, char* p1) {
    // Stack: 40 bytes
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> Sprintf(char *, char *,...)
    // -> OPTTarget::GetScreenXLocal(signed char)
    // -> OPTTarget::GetScreenYLocal(signed char)
    // Uses floating point

    // Getter
    return 0;
}

// ============================================================================
// StartFire(void) - 0x801FC5D4 | 372 bytes
// ============================================================================
// NON_MATCHING
void StartFire(void) {
    // Stack: 40 bytes
    // -> StartFireAtObjectLoc(cXObject *, ObjSelector *)
    // -> rand
    // -> CTilePt::CTilePt(int, int, int)
    // -> CTilePt::~CTilePt(void)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// PDATarget::SetVariable(char *, char *) - 0x801FDC64 | 512 bytes
// ============================================================================
// NON_MATCHING
void PDATarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 24 bytes
    // -> strcmp
    // -> AtoI(char *)
    // -> UIDB::UIDBSetInt(char *, int)
    // -> PDATarget::HandleFirstOpenMessage(int)
    // -> UIDB::UIDBGetInt(char *)
    // -> PDATarget::HandleButtonHelpMessage(int, int)
    // ... and 1 more calls

    // Setter
}

// ============================================================================
// PDATarget::GetVariable(char *) - 0x801FDE64 | 320 bytes
// ============================================================================
// NON_MATCHING
void* PDATarget__GetVariable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> EyeToyClient::IsEyeToyHardwarePresent(void)
    // -> Sprintf(char *, char *,...)

    // Getter
    return 0;
}

// ============================================================================
// PDATarget::HandleSubTargetStateChange(FlowGotoTarget::eFlashState) - 0x801FDFA4 | 864 bytes
// ============================================================================
// NON_MATCHING
void PDATarget__HandleSubTargetStateChange(void* self, void* p1) {
    // Stack: 56 bytes
    // -> __builtin_new
    // -> INVTarget::INVTarget(int)
    // -> RELTarget::RELTarget(int)
    // -> EyeToyClient::IsEyeToyHardwarePresent(void)
    // -> EYETarget::EYETarget(int)
    // -> SKNTarget::SKNTarget(int)
    // ... and 5 more calls

}

// ============================================================================
// PDATarget::HandleSubTargetStateChange(int, PDATarget::ePDAMode) - 0x801FE304 | 948 bytes
// ============================================================================
// NON_MATCHING
void PDATarget__HandleSubTargetStateChange(void* self, int p1, void* p2) {
    // Stack: 56 bytes
    // -> PDATarget::SetupFirstOpenMessage(int, PDATarget::ePDAMode)
    // -> __builtin_new
    // -> FONTarget::FONTarget(int)
    // -> INVTarget::INVTarget(int)
    // -> RELTarget::RELTarget(int)
    // -> MSGTarget::MSGTarget(int)
    // ... and 5 more calls

}

// ============================================================================
// PDATarget::SetupSkinShaders(int, int) - 0x801FE6B8 | 856 bytes
// ============================================================================
// NON_MATCHING
void PDATarget__SetupSkinShaders(void* self, int p1, int p2) {
    // Stack: 24 bytes
    // -> UIDB::UIDBSetInt(char *, int)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)

    // Setter
}

// ============================================================================
// PDATarget::HandleFirstOpenMessage(int) - 0x801FEADC | 872 bytes
// ============================================================================
// NON_MATCHING
void PDATarget__HandleFirstOpenMessage(void* self, int p1) {
    // Stack: 80 bytes
    // -> EGlobal::GetNewUIString(char *)
    // -> BString2::operator=(unsigned wchar_t *)

    // Process/handle event
}

// ============================================================================
// PDATarget::HandleButtonHelpMessage(int, int) - 0x801FEE80 | 288 bytes
// ============================================================================
// NON_MATCHING
void PDATarget__HandleButtonHelpMessage(void* self, int p1, int p2) {
    // Stack: 32 bytes
    // -> EGlobal::GetUrbzButtonsRow(unsigned int)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> EGlobal::GetNewUIString(char *)

    // Process/handle event
}

// ============================================================================
// PSETarget::~PSETarget(void) - 0x801FF574 | 396 bytes
// ============================================================================
// NON_MATCHING
void PSETarget__dtor_PSETarget(void* self) {
    // Stack: 16 bytes
    // -> cBoxX::UnpauseAmbient(void)
    // -> PSETarget::PopAptButtonFilters(void)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 6 more calls
    // Accesses globals via r13 (SDA)

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// PSETarget::PushAptButtonFilters(void) - 0x801FF838 | 464 bytes
// ============================================================================
// NON_MATCHING
void PSETarget__PushAptButtonFilters(void* self) {
    // Stack: 32 bytes
    // -> AptViewer::PushAptButtonFilter(int, char *)
    // -> AptViewer::AddCmdToAptButtonFilter(int, unsigned int, ECTRL_CMD)
    // Contains loop(s)

}

// ============================================================================
// RELTarget::~RELTarget(void) - 0x802007EC | 572 bytes
// ============================================================================
// NON_MATCHING
void RELTarget__dtor_RELTarget(void* self) {
    // Stack: 24 bytes
    // -> EResource::DelRef(void)
    // -> BString2::~BString2(void)
    // -> __builtin_delete
    // -> AptViewer::PopAptButtonFilter(int, unsigned int)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // ... and 22 more calls
    // Contains loop(s)

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// RELTarget::GetVariable(char *) - 0x80200A28 | 436 bytes
// ============================================================================
// NON_MATCHING
void* RELTarget__GetVariable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> strncmp
    // -> AtoI(char *)
    // -> RELTarget::GetFace(int)
    // -> RELTarget::GetColor(int)
    // ... and 2 more calls

    // Getter
    return 0;
}

// ============================================================================
// RELTarget::GetLocalizable(char *) - 0x80200BDC | 340 bytes
// ============================================================================
// NON_MATCHING
void* RELTarget__GetLocalizable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> RELTarget::GetRecord(int)
    // -> BString2::c_str(void) const
    // -> wcscpy
    // -> wcslen
    // ... and 2 more calls

    // Getter
    return 0;
}

// ============================================================================
// RELTarget::SetVariable(char *, char *) - 0x80200D30 | 876 bytes
// ============================================================================
// NON_MATCHING
void RELTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 64 bytes
    // -> strcmp
    // -> AtoI(char *)
    // -> RELTarget::SetupPageShaders(int)
    // -> RELTarget::GetRecord(int)
    // -> BString2::BString2(void)
    // -> Sprintf(char *, char *,...)
    // ... and 10 more calls

    // Setter
}

// ============================================================================
// RELTarget::SetupRelationshipInformation(void) - 0x8020109C | 576 bytes
// ============================================================================
// NON_MATCHING
void RELTarget__SetupRelationshipInformation(void* self) {
    // Stack: 72 bytes
    // -> HoodManager::GetRelatedPeople(int, cXPerson *, void *)
    // -> Neighbor::GetGUID(void)
    // -> __builtin_new
    // -> BString2::BString2(void)
    // -> Neighbor::GetRelationship(Neighbor *, int *)
    // -> ObjSelector::GetUserName(void)
    // ... and 4 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// RELTarget::SetupPageShaders(int) - 0x8020135C | 760 bytes
// ============================================================================
// NON_MATCHING
void RELTarget__SetupPageShaders(void* self, int p1) {
    // Stack: 64 bytes
    // -> BString2::BString2(void)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // -> RELTarget::GetRecord(int)
    // -> EResource::DelRef(void)
    // -> EGlobal::GetRelationshipTableRow(unsigned int)
    // -> ObjSelector::GetThumbnail(ERShader **)
    // ... and 6 more calls
    // Contains loop(s)

    // Setter
}

// ============================================================================
// RGTTarget::~RGTTarget(void) - 0x80201DD8 | 452 bytes
// ============================================================================
// NON_MATCHING
void RGTTarget__dtor_RGTTarget(void* self) {
    // Stack: 16 bytes
    // -> AptViewer::PopAptButtonFilter(int, unsigned int)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // ... and 20 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// RGTTarget::SetupNames(int) - 0x80201F9C | 328 bytes
// ============================================================================
// NON_MATCHING
void RGTTarget__SetupNames(void* self, int p1) {
    // Stack: 120 bytes
    // -> Sprintf(char *, char *,...)
    // -> strcat
    // -> RGTTarget::FindActualRingtoneIndex(int)
    // -> EGlobal::GetPDAString(char *)
    // -> UIDB::UIDBSetString(char *, unsigned wchar_t *)
    // Contains loop(s)

    // Setter
}

// ============================================================================
// RGTTarget::SetVariable(char *, char *) - 0x802021A8 | 464 bytes
// ============================================================================
// NON_MATCHING
void RGTTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 24 bytes
    // -> strcmp
    // -> AtoI(char *)
    // -> RGTTarget::FindActualRingtoneIndex(int)
    // -> __builtin_new
    // -> UIAUDIO::UIAUDIO(void)
    // -> UIAUDIO::PlaySound(unsigned int)
    // ... and 2 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// SKNTarget::~SKNTarget(void) - 0x80202B90 | 452 bytes
// ============================================================================
// NON_MATCHING
void SKNTarget__dtor_SKNTarget(void* self) {
    // Stack: 16 bytes
    // -> AptViewer::PopAptButtonFilter(int, unsigned int)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // ... and 20 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}
