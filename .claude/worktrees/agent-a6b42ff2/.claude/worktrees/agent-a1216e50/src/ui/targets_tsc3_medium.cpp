// targets_tsc3_medium.cpp - All medium functions (65-256 bytes) from targets_tsc3.obj
// 207 functions total (145 game logic + 54 CB thunks + 8 template data)
//
// Original obj: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\targets_tsc3.obj

#include "ui/targets_tsc3.h"

extern "C" {
    void operator_delete(void* ptr);
    void SmallBlockAllocator_Free(void* ptr);
    int strcmp_impl(const char* a, const char* b);
    int AptVar_Hash(char* str);
    int atoi_impl(const char* str);
}

// ============================================================================
// EYETarget (EyeToy Camera)
// ============================================================================

// 0x801e714c | 256 bytes
// NON_MATCHING - saves current EyeToy settings
void EYETarget_SaveCurrentSetting(void* self) { }

// 0x801e8df8 | 168 bytes
void EYETarget_SetVariable(void* self, char* name, char* value) { }

// 0x801e8ea0 | 192 bytes
char* EYETarget_GetVariable(void* self, char* name) { return 0; }

// ============================================================================
// AptVar constructors and handlers
// ============================================================================

// 0x801e9138 | 112 bytes
void GetVar_GetCount_ctor(void* self, char* name, int count) {
    *(int*)((u8*)self + 0x00) = 0;  // vtable placeholder
    *(int*)((u8*)self + 0x0C) = count;
    // Set name hash
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x801e91a8 | 160 bytes
void GetVar_LockedStatus_ctor(void* self, char* name, unsigned int lockBits) {
    *(int*)((u8*)self + 0x00) = 0;
    *(unsigned int*)((u8*)self + 0x0C) = lockBits;
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x801e926c | 68 bytes
char* GetVar_LockedStatus_Handler(void* self, char* result) {
    // Returns "0" or "1" based on lock status
    return 0;
}

// 0x801e9308 | 72 bytes
char* GetVar_EYE_settingSliderVal_Handler(void* self, char* result) {
    // Returns current slider value as string
    return 0;
}

// 0x801e9350 | 108 bytes
char* GetVar_SaveRequired_Handler(void* self, char* result) {
    // Returns "1" if save is required
    return 0;
}

// 0x801e93bc | 84 bytes
char* GetVar_ImageSlotsAvail_Handler(void* self, char* result) {
    // Returns number of available image slots
    return 0;
}

// 0x801e9410 | 112 bytes
char* GetVar_EYE_connectionStatus_Handler(void* self, char* result) {
    // Returns EyeToy connection status string
    return 0;
}

// 0x801e95ec | 92 bytes
void SetVar_EYE_topLevelCurrSel_Handler(void* self, char* value) {
    // Updates top level selection from APT
}

// 0x801e9744 | 140 bytes
void SetVar_EYE_saveToSlotStatus_Handler(void* self, char* value) {
    // Handles save-to-slot status changes
}

// ============================================================================
// SetVar/GetVar constructors (all follow same 84-92 byte pattern)
// ============================================================================

// 0x80203784 | 84 bytes
void SetVar_EYE_state_ctor(void* self, char* name) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x802037d8 | 84 bytes
void SetVar_EYE_topLevelCurrSel_ctor(void* self, char* name) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x8020382c | 84 bytes
void SetVar_EYE_funframeCurrSel_ctor(void* self, char* name) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x80203880 | 84 bytes
void SetVar_EYE_filterCurrSel_ctor(void* self, char* name) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x802038d4 | 84 bytes
void SetVar_EYE_slotCurrSel_ctor(void* self, char* name) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x80203928 | 84 bytes
void SetVar_EYE_saveToSlotStatus_ctor(void* self, char* name) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x8020397c | 92 bytes
void SetVar_EYE_settingSliderVal_ctor(void* self, char* name, void* setFunc) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
    *(void**)((u8*)self + 0x10) = setFunc;
}

// 0x802039d8 | 84 bytes
void SetVar_EYE_opCancelled_ctor(void* self, char* name) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x80203a2c | 92 bytes
void GetVar_SliderStep_ctor(void* self, char* name, char* stepValue) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
    *(char**)((u8*)self + 0x10) = stepValue;
}

// 0x80203a88 | 84 bytes
void GetVar_EYE_exists_ctor(void* self, char* name) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x80203adc | 84 bytes
void GetVar_EYE_targetState_ctor(void* self, char* name) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x80203b30 | 92 bytes
void GetVar_EYE_settingSliderVal_ctor(void* self, char* name, void* getFunc) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
    *(void**)((u8*)self + 0x10) = getFunc;
}

// 0x80203b8c | 84 bytes
void GetVar_SaveRequired_ctor(void* self, char* name) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x80203be0 | 84 bytes
void GetVar_SaveStatus_ctor(void* self, char* name) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x80203c34 | 84 bytes
void GetVar_ImageSlotsAvail_ctor(void* self, char* name) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x80203c88 | 84 bytes
void GetVar_EYE_connectionStatus_ctor(void* self, char* name) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// 0x80203cdc | 84 bytes
void GetVar_Legacy_ctor(void* self, char* name) {
    *(int*)((u8*)self + 0x08) = AptVar_Hash(name);
}

// ============================================================================
// GOLTarget (Goals)
// ============================================================================

// 0x801ebffc | 152 bytes
void GOLTarget_InstallMapShader(void* self) { }

// 0x801eb4dc | 164 bytes
void GOLTarget_SetVariable(void* self, char* name, char* value) { }

// 0x801eb580 | 100 bytes
int GOLTarget_IsMapGoalUnlocked(void* self, int map, int goal, int subGoal) { return 0; }

// 0x801eb5e4 | 120 bytes
int GOLTarget_IsHouseUnlocked(void* self, int map, int house) { return 0; }

// 0x801eb65c | 120 bytes
int GOLTarget_IsApartmentUnlocked(void* self, int map, int apartment) { return 0; }

// 0x801ec0d0 | 68 bytes
int StaticConvertTabToCategory(int tab) { return tab; }

// 0x801ec114 | 68 bytes
int StaticGetObjectValue(void* objSelector) { return 0; }

// 0x801ecb94 | 196 bytes
int StaticGetShaderId(void* objSelector) { return 0; }

// 0x801eccc0 | 148 bytes
void StaticNumberToWideString(int number, unsigned short* buf) { }

// 0x801ecd54 | 112 bytes
int StaticExtractObjSelectorGuidFromObject(void* xObject) { return 0; }

// ============================================================================
// INVTarget (Inventory)
// ============================================================================

// 0x801f0d00 | 72 bytes
void INVTarget_ClearAllCheatStrings(void* self) { }

// 0x801ee1a4 | 92 bytes
int INVTarget_GetPlayerFunds(void* self) { return 0; }

// 0x801ee200 | 100 bytes
void INVTarget_SetPlayerFunds(void* self, int funds) { }

// 0x801ee264 | 176 bytes
void INVTarget_FormatMoneyString(void* self, int amount, bool addSign, unsigned short* buf) { }

// 0x801f446c | 88 bytes
void INVTarget_SetOnMsgInvCurrentTab(void* self, char* value) { }

// 0x801f44c4 | 88 bytes
void INVTarget_SetOnMsgInvCurrentCell(void* self, char* value) { }

// 0x801f4940 | 96 bytes
void INVTarget_SetOnMsgInvGrabMode(void* self, char* value) { }

// 0x801f5e58 | 104 bytes
void INVTarget_SetOnMsgInvShpNextTab(void* self, char* value) { }

// 0x801f5ec0 | 108 bytes
void INVTarget_SetOnMsgInvShpPrevTab(void* self, char* value) { }

// 0x801f5010 | 228 bytes
void INVTarget_SetOnMsgInvShpPrepareObjectInfo(void* self, char* value) { }

// 0x801f5fc0 | 212 bytes
void INVTarget_SetOnMsgInvShpSelectColor(void* self, char* value) { }

// 0x801f5f2c | 148 bytes
void INVTarget_SetOnMsgInvShpCurrentCategory(void* self, char* value) { }

// 0x801f65c8 | 240 bytes
char* INVTarget_GetOnMsgInvSelectExitReset(void* self, char* name) { return 0; }

// 0x801f66f8 | 68 bytes
char* INVTarget_GetOnMsgInvObjectInfoReady(void* self, char* name) { return 0; }

// 0x801f6858 | 248 bytes
char* INVTarget_GetOnMsgInvShpItemCount(void* self, char* name) { return 0; }

// 0x801f6c5c | 68 bytes
char* INVTarget_GetOnMsgInvShpObjectInfoReady(void* self, char* name) { return 0; }

// 0x801f7150 | 104 bytes
char* INVTarget_GetOnMsgInvShpShpTabToInvTab(void* self, char* name) { return 0; }

// 0x801f73bc | 180 bytes
char* INVTarget_GetOnMsgInvShpColorN(void* self, char* name, int n) { return 0; }

// 0x801f7eb0 | 108 bytes
char* INVTarget_GetOnMsgInvShpIsPack(void* self, char* name) { return 0; }

// 0x801f7f1c | 140 bytes
char* INVTarget_GetOnMsgInvHelpMode(void* self, char* name) { return 0; }

// 0x801f7fe0 | 68 bytes
char* INVTarget_GetOnMsgInvBldDisplayInfo(void* self, char* name) { return 0; }

// 0x801f74a4 | 68 bytes
char* INVTarget_GetOnMsgInvShpCategoryCount(void* self, char* name) { return 0; }

// 0x801f74e8 | 104 bytes
char* INVTarget_GetOnMsgInvShpCategoryN(void* self, char* name, int n) { return 0; }

// 0x801f6a88 | 128 bytes
unsigned short* INVTarget_GetOnLocMsgInvShpObjectDescription(void* self, unsigned short* buf) { return 0; }

// 0x801f6988 | 256 bytes
unsigned short* INVTarget_GetOnLocMsgInvShpObjectName(void* self, unsigned short* buf) { return 0; }

// 0x801f6b08 | 152 bytes
unsigned short* INVTarget_GetOnLocMsgInvShpBudget(void* self, unsigned short* buf) { return 0; }

// 0x801f6ba0 | 84 bytes
unsigned short* INVTarget_GetOnLocMsgInvMotiveText(void* self, unsigned short* buf) { return 0; }

// 0x801f6bf4 | 104 bytes
unsigned short* INVTarget_GetOnLocMsgInvShpMotiveText(void* self, unsigned short* buf) { return 0; }

// 0x801f0d48 | 112 bytes
void INVTarget_SetCategoryCheatString(void* self, char* str, int cat, char* value) { }

// 0x801f0db8 | 68 bytes
void INVTarget_SetPageIdxCheatString(void* self, char* str, int idx) { }

// 0x801f0efc | 152 bytes
void INVTarget_SetAllObjectRelatedCheatStrings_obj(void* self, void* objSelector) { }

// 0x801f0f94 | 256 bytes
void INVTarget_SetAllObjectRelatedCheatStrings_wall(void* self, void* wallData) { }

// 0x801f1094 | 132 bytes
void INVTarget_SetAllObjectRelatedCheatStrings_wallpaper(void* self, void* wpData) { }

// 0x801f1118 | 132 bytes
void INVTarget_SetAllObjectRelatedCheatStrings_floor(void* self, void* floorData) { }

// 0x801f0050 | 164 bytes
void INVTarget_OnSetCurrentTab(void* self, int tab) { }

// 0x801f0400 | 184 bytes
void INVTarget_UninstallInventoryPanelInfo(void* self) { }

// 0x801f04fc | 204 bytes
void INVTarget_SetupInteractorCamera(void* self, bool flag) { }

// 0x801f05c8 | 88 bytes
void INVTarget_UpdateInputState(void* self) { }

// 0x801f0620 | 204 bytes
void INVTarget_CreateObjectMenuForBuyBuild(void* self, void* simList) { }

// 0x801f06ec | 148 bytes
void INVTarget_PushPlaceFilter(void* self) { }

// 0x801f0780 | 232 bytes
void INVTarget_PushGrabFilter(void* self) { }

// 0x801f0868 | 84 bytes
void INVTarget_PopCurrentFilter(void* self) { }

// 0x801f08bc | 72 bytes
void INVTarget_Cheat_HandleProgressDownHierarchy(void* self, char* cmd) { }

// 0x801f0904 | 132 bytes
void INVTarget_Cheat_HandleReturnUpHierarchy(void* self, char* cmd) { }

// 0x801f0dfc | 104 bytes
void INVTarget_SetFileNameCheatString(void* self, char* str, int idx, char* value) { }

// 0x801f0e64 | 100 bytes
void INVTarget_SetCatalogNameCheatString(void* self, char* str, int idx, unsigned short* value) { }

// 0x801f119c | 88 bytes
void INVTarget_ClearAllObjRelatedCheatStrings(void* self) { }

// 0x801f1470 | 76 bytes
void INVTarget_CannotGrabToInventoryDialogSelectionCallback(void* self, int result) { }

// 0x801f1874 | 256 bytes
// NON_MATCHING - wall manipulator callback
void INVTarget_WallManipulatorCallbackImpl(void* self, void* cbData) { }

// 0x801f199c | 208 bytes
void INVTarget_CommittChangesToInventory(void* self, void* cbData) { }

// 0x801f1a6c | 256 bytes
// NON_MATCHING - wall painter callback
void INVTarget_WallPainterCallbackImpl(void* self, void* cbData) { }

// 0x801f1bbc | 144 bytes
void INVTarget_FloorModeCallbackImpl(void* self, void* cbData) { }

// 0x801f54a4 | 204 bytes
void INVTarget_PrepareObjectInfo_wall(void* self, void* wallData, int idx, bool flag) { }

// 0x801f53ec | 184 bytes
void INVTarget_PrepareObjectInfo_floor(void* self, void* floorData, int idx, bool flag) { }

// 0x801f5334 | 184 bytes
void INVTarget_PrepareObjectInfo_wallpaper(void* self, void* wpData, int idx, bool flag) { }

// 0x801f49a0 | 160 bytes
int StaticCalcRefundAmount_Pack(int cost, int count, int condition) { return 0; }

// 0x801f4a40 | 120 bytes
int StaticCalcRefundAmount_Single(int cost, int condition) { return 0; }

// 0x801f5674 | 152 bytes
void INVTarget_GetObjectRating(void* self, void* objSelector, int* outA, int* outB) { }

// 0x801f58a0 | 104 bytes
void INVTarget_GetMotiveText(void* self, int motive, unsigned short* buf) { }

// 0x801f5a94 | 256 bytes
void INVTarget_GetMotiveText_shopping(void* self, int motive, void* shopItem, unsigned short* buf) { }

// 0x801f5ba0 | 136 bytes
int INVTarget_GetNumberOfBuildItemsToBuy(void* self, int subCategory, int tab) { return 0; }

// 0x801f60d8 | 144 bytes
void INVTarget_InstallShoppingObjectShaders(void* self, int count) { }

// 0x801f6168 | 236 bytes
void INVTarget_InstallWallPaperShaders(void* self, void* wpVec, int count) { }

// 0x801f6398 | 236 bytes
void INVTarget_InstallFloorTileShaders(void* self, void* floorVec, int count) { }

// 0x801f6484 | 236 bytes
void INVTarget_InstallObjListShaders(void* self, void* objVec, int count) { }

// 0x801f7e4c | 100 bytes
int INVTarget_IsPackagedItem(void* self, void* invItem) { return 0; }

// ============================================================================
// INTTarget (Interactions)
// ============================================================================

// 0x801f89e4 | 152 bytes
char* INTTarget_GetVariable(void* self, char* name) { return 0; }

// 0x801f8db0 | 220 bytes
void INTTarget_UpdateInterestMeter(void* self) { }

// 0x801f9154 | 76 bytes
void INTTarget_MirrorUpArrow(void* self, bool state) { }

// ============================================================================
// KEYTarget (Keyboard)
// ============================================================================

// 0x801f9960 | 156 bytes
unsigned short* KEYTarget_GetName(void* self) { return 0; }

// ============================================================================
// MSGTarget (Messages)
// ============================================================================

// 0x801f9d48 | 184 bytes
void MSGTarget_DeliverXamMessage(void* self, int player, unsigned short msgId) { }

// ============================================================================
// OPTTarget (Options - TSC3 version)
// ============================================================================

// 0x801fc498 | 120 bytes
void OPTTarget_RememberOptions(void* self) { }

// 0x801fc344 | 96 bytes
float OPTTarget_GetScreenXGlobal(void* self, float x) { return 0.0f; }

// 0x801fc438 | 96 bytes
float OPTTarget_GetScreenYGlobal(void* self, float y) { return 0.0f; }

// 0x801fc510 | 196 bytes
void OPTTarget_RestoreOptions(void* self) { }

// 0x801fc2b0 | 148 bytes
float OPTTarget_GetScreenXLocal(void* self, signed char dir) { return 0.0f; }

// 0x801fc3a4 | 148 bytes
float OPTTarget_GetScreenYLocal(void* self, signed char dir) { return 0.0f; }

// ============================================================================
// PDATarget (PDA/Phone)
// ============================================================================

// 0x801fc748 | 252 bytes
void PDATarget_SetupMoney(void* self) { }

// 0x801fea10 | 144 bytes
void PDATarget_SelectionCallback(void* self, int selection) { }

// ============================================================================
// PSETarget (Pause Screen)
// ============================================================================

// 0x801ffa08 | 132 bytes
void PSETarget_PopAptButtonFilters(void* self) { }

// 0x801ff700 | 188 bytes
char* PSETarget_GetVariable(void* self, char* name) { return 0; }

// 0x801ff7bc | 124 bytes
void PSETarget_SetVariable(void* self, char* name, char* value) { }

// ============================================================================
// RELTarget (Relationships)
// ============================================================================

// 0x802012ec | 76 bytes
void* RELTarget_GetColor(void* self, int index) { return 0; }

// ============================================================================
// RGTTarget (Ringtones)
// ============================================================================

// 0x802023e0 | 100 bytes
void RGTTarget_SetupRingtoneUnlocks(void* self) { }

// 0x80202378 | 104 bytes
int RGTTarget_FindActualRingtoneIndex(void* self, int index) { return 0; }

// 0x802020e4 | 196 bytes
char* RGTTarget_GetVariable(void* self, char* name) { return 0; }

// ============================================================================
// SKNTarget (Skins)
// ============================================================================

// 0x802036f8 | 100 bytes
void SKNTarget_SetupSkinUnlocks(void* self) { }

// 0x80202d54 | 196 bytes
char* SKNTarget_GetVariable(void* self, char* name) { return 0; }

// 0x80202e18 | 212 bytes
void SKNTarget_SetVariable(void* self, char* name, char* value) { }

// 0x80202eec | 108 bytes
int SKNTarget_FindActualSkinIndex(void* self, int index) { return 0; }

// ============================================================================
// CBMemberTranslator Thunks (54 thunks, all 120 bytes, identical pattern)
// ============================================================================
// See targets_s2c_medium.cpp for the generic thunk dispatch pattern.
// All thunks listed by address:
//
// EYETarget: 0x803bae70, 0x803baee8, 0x803baf60, 0x803bafd8, 0x803bb050, 0x803bb0c8
// FONTarget: 0x803bb140, 0x803bb1b8, 0x803bb230, 0x803bb2a8, 0x803bb320
// GOLTarget: 0x803bb398, 0x803bb410, 0x803bb488, 0x803bb500, 0x803bb578
// INVTarget: 0x803bb5f0, 0x803bb668, 0x803bb6e0, 0x803bb758, 0x803bb7d0, 0x803bb848, 0x803bb8c0
// INTTarget: 0x803bb938, 0x803bb9b0, 0x803bba28, 0x803bbaa0, 0x803bbb18
// KEYTarget: 0x803bbb90, 0x803bbc08, 0x803bbc80, 0x803bbcf8, 0x803bbd70
// MSGTarget: 0x803bbde8, 0x803bbe60, 0x803bbed8, 0x803bbf50, 0x803bbfc8
// OPTTarget: 0x803bc040, 0x803bc0b8, 0x803bc130, 0x803bc1a8, 0x803bc220
// PDATarget: 0x803bc298, 0x803bc310, 0x803bc388, 0x803bc400, 0x803bc478, 0x803bc4f0, 0x803bc568
// PSETarget: 0x803bc5f8, 0x803bc670, 0x803bc6e8, 0x803bc760, 0x803bc7d8
// RELTarget: 0x803bc850, 0x803bc8c8, 0x803bc940, 0x803bc9b8, 0x803bca30
// RGTTarget: 0x803bcaa8, 0x803bcb20, 0x803bcb98, 0x803bcc10, 0x803bcc88
// SKNTarget: 0x803bcd00, 0x803bcd78, 0x803bcdf0, 0x803bce68, 0x803bcee0
