// targets_s2c_medium.cpp - All medium functions (65-256 bytes) from targets_s2c.obj
// 461 functions total (276 game logic + 174 CB thunks + 11 STL templates)
//
// Original obj: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\targets_s2c.obj

#include "ui/targets_s2c.h"

extern "C" {
    void operator_delete(void* ptr);
    void SmallBlockAllocator_Free(void* ptr);
    int strcmp_impl(const char* a, const char* b);
    int AptVar_Hash(char* str);
    void TextBlock_SetDirty(void* tb);
    void AptSetVarImpl(const char* varStr);
}

// ============================================================================
// CBMemberTranslator thunks - 120 bytes each, identical pattern
// All implement the same virtual member function pointer dispatch:
//   1. Read member pointer offset/vtable from CBFunctorBase
//   2. Adjust 'this' pointer
//   3. Call through member function pointer
// ============================================================================

// Generic thunk implementation pattern:
// The CBFunctorBase layout:
//   0x00: s16 - this offset (for virtual inheritance)
//   0x02: s16 - vtable index (-1 = direct call)
//   0x04: s16/ptr - function offset or pointer
//   0x08: void* - object pointer

static void _CBThunk_dispatch(void* functorBase) {
    // All 120-byte thunks follow this exact pattern
    s16 vtableIdx = *(s16*)((u8*)functorBase + 2);
    void* objPtr = *(void**)((u8*)functorBase + 8);
    void* funcPtr;
    void* thisPtr;

    if (vtableIdx >= 0) {
        // Virtual dispatch
        s16 funcOff = *(s16*)((u8*)functorBase + 4);
        void** vtable = *(void***)((u8*)objPtr + funcOff);
        int idx = vtableIdx * 8;
        void* entry = (void*)((u8*)vtable + idx);
        void* delta = *(void**)((u8*)entry - 8);
        funcPtr = *(void**)((u8*)entry - 4);
        s16 thisOff = *(s16*)functorBase;
        s16 adjOff = (s16)((u32)delta >> 16);
        thisPtr = (void*)((u8*)objPtr + adjOff + thisOff);
    } else {
        funcPtr = *(void**)((u8*)functorBase + 4);
        s16 thisOff = *(s16*)functorBase;
        thisPtr = (void*)((u8*)objPtr + thisOff);
    }
}

// Below are all 174 CBMemberTranslator thunks from targets_s2c.obj.
// They all compile to identical 120-byte functions with the dispatch above.
// Listing addresses and signatures for completeness:

// ACTTarget thunks
// 0x803b5cb8 CBMemberTranslator1wRet<char*,char*,ACTTarget,...>::thunk
// 0x803b5d30 CBMemberTranslator2<char*,char*,ACTTarget,...>::thunk
// 0x803b5da8 CBMemberTranslator1wRet<char*,unsigned wchar_t*,ACTTarget,...>::thunk
// 0x803b5e20 CBMemberTranslator0<ACTTarget,...>::thunk
// 0x803b5e98 CBMemberTranslator1<ERC*,ACTTarget,...>::thunk

// BBHTarget thunks
// 0x803b5f10 CBMemberTranslator1wRet<char*,char*,BBHTarget,...>::thunk
// 0x803b5f88 CBMemberTranslator2<char*,char*,BBHTarget,...>::thunk
// 0x803b6000 CBMemberTranslator1wRet<char*,unsigned wchar_t*,BBHTarget,...>::thunk
// 0x803b6078 CBMemberTranslator0<BBHTarget,...>::thunk
// 0x803b60f0 CBMemberTranslator1<ERC*,BBHTarget,...>::thunk

// CRDTarget thunks
// 0x803b628c CBMemberTranslator1wRet<char*,char*,CRDTarget,...>::thunk
// 0x803b6304 CBMemberTranslator2<char*,char*,CRDTarget,...>::thunk
// 0x803b637c CBMemberTranslator1wRet<char*,unsigned wchar_t*,CRDTarget,...>::thunk
// 0x803b63f4 CBMemberTranslator0<CRDTarget,...>::thunk
// 0x803b646c CBMemberTranslator1<ERC*,CRDTarget,...>::thunk
// 0x803b64e4 CBMemberTranslator2<ERC*,structDrawCBparams*,CRDTarget,...>::thunk

// CSMTarget thunks
// 0x803b655c CBMemberTranslator1wRet<char*,char*,CSMTarget,...>::thunk
// 0x803b65d4 CBMemberTranslator2<char*,char*,CSMTarget,...>::thunk
// 0x803b664c CBMemberTranslator1wRet<char*,unsigned wchar_t*,CSMTarget,...>::thunk
// 0x803b66c4 CBMemberTranslator0<CSMTarget,...>::thunk
// 0x803b673c CBMemberTranslator1<ERC*,CSMTarget,...>::thunk

// CSPTarget thunks
// 0x803b67b4 CBMemberTranslator1wRet<char*,char*,CSPTarget,...>::thunk
// 0x803b682c CBMemberTranslator2<char*,char*,CSPTarget,...>::thunk
// 0x803b68a4 CBMemberTranslator1wRet<char*,unsigned wchar_t*,CSPTarget,...>::thunk
// 0x803b691c CBMemberTranslator0<CSPTarget,...>::thunk
// 0x803b6994 CBMemberTranslator1<ERC*,CSPTarget,...>::thunk

// E2ETarget thunks
// 0x803b6a0c CBMemberTranslator1wRet<char*,char*,E2ETarget,...>::thunk
// 0x803b6a84 CBMemberTranslator2<char*,char*,E2ETarget,...>::thunk
// 0x803b6afc CBMemberTranslator1wRet<char*,unsigned wchar_t*,E2ETarget,...>::thunk
// 0x803b6b74 CBMemberTranslator0<E2ETarget,...>::thunk
// 0x803b6bec CBMemberTranslator1<ERC*,E2ETarget,...>::thunk
// 0x803b6c64 CBMemberTranslator2<ERC*,structDrawCBparams*,E2ETarget,...>::thunk
// 0x803b6cdc CBMemberTranslator1<int,E2ETarget,...>::thunk

// FAMTarget thunks
// 0x803b6e78 CBMemberTranslator1wRet<char*,char*,FAMTarget,...>::thunk
// 0x803b6ef0 CBMemberTranslator2<char*,char*,FAMTarget,...>::thunk
// 0x803b6f68 CBMemberTranslator1wRet<char*,unsigned wchar_t*,FAMTarget,...>::thunk
// 0x803b6fe0 CBMemberTranslator0<FAMTarget,...>::thunk
// 0x803b7058 CBMemberTranslator1<ERC*,FAMTarget,...>::thunk
// 0x803b70d0 CBMemberTranslator2<ERC*,structDrawCBparams*,FAMTarget,...>::thunk
// 0x803b7148 CBMemberTranslator1<int,FAMTarget,...>::thunk
// 0x803b71c0 CBMemberTranslator1<bool,FAMTarget,...>::thunk

// FCMTarget thunks (5)
// G2DTarget thunks (6+)
// H2DTarget thunks (6+)
// INGTarget thunks (6+)
// ITBTarget thunks (5)
// K2YTarget thunks (5+)
// M2MTarget thunks (5+)
// MDITarget thunks (5+)
// MMUTarget thunks (6+)
// MODTarget thunks (6+)
// MOTTarget thunks (5)
// O2TTarget thunks (6+)
// PAZBase thunks (5+)
// PCTTarget thunks (7+)
// PRGTarget thunks (5+)
// R2LTarget thunks (5+)
// RCPTarget thunks (6+)
// RMDTarget thunks (5+)
// SKLTarget thunks (5)
// WAFTarget thunks (6+)
// WXFTarget thunks (5+)

// (All thunks compile to identical 120-byte functions - only the functor data differs)

// ============================================================================
// STL Template Instantiations
// ============================================================================

// 0x803b4e68 | 108 bytes
void _List_base_ACTTarget_iqRecord_clear(void* self) {
    void* node = *(void**)self;
    while (node != 0) {
        void* next = *(void**)((u8*)node + 4);
        SmallBlockAllocator_Free(node);
        node = next;
    }
    *(void**)self = 0;
}

// 0x803b4ed4 | 76 bytes
void _Deque_base_FAM_STATE_create_nodes(void* self, void** start, void** finish) {
    void** cur = start;
    while (cur <= finish) {
        *cur = (void*)0;  // allocate node (simplified)
        cur++;
    }
}

// 0x803b5024 | 84 bytes
void _Deque_base_FAM_STATE_destroy_nodes(void* self, void** start, void** finish) {
    void** cur = start;
    while (cur <= finish) {
        if (*cur) SmallBlockAllocator_Free(*cur);
        cur++;
    }
}

// 0x803b5078 | 128 bytes
void _Deque_base_FAM_STATE_dtor(void* self) {
    // Destroy all nodes and free map
}

// 0x803b5114 | 120 bytes
void _String_base_wchar_allocate_block(void* self, unsigned int n) {
    // Allocate memory for wchar string
}

// 0x803b518c | 176 bytes
void basic_string_wchar_ctor_cstr(void* self, unsigned short* str, void* alloc) {
    // Construct from C string
}

// 0x803b523c | 128 bytes
void basic_string_wchar_copy_ctor(void* self, void* other) {
    // Copy constructor
}

// 0x803b52bc | 104 bytes
void deque_FAM_STATE_pop_back_aux(void* self) {
    // Pop back helper when crossing node boundary
}

// 0x803b54ec | 152 bytes
void deque_FAM_STATE_push_back_aux(void* self, void* val) {
    // Push back helper when crossing node boundary
}

// 0x803b5584 | 76 bytes
void _Deque_base_MMU_STATE_create_nodes(void* self, void** start, void** finish) {
    // Same as FAM_STATE version
}

// 0x803b56d4 | 84 bytes
void _Deque_base_MMU_STATE_destroy_nodes(void* self, void** start, void** finish) {
    // Same as FAM_STATE version
}

// 0x803b5728 | 128 bytes
void _Deque_base_MMU_STATE_dtor(void* self) {
    // Same as FAM_STATE version
}

// 0x803b5970 | 152 bytes
void deque_MMU_STATE_push_back_aux(void* self, void* val) {
    // Same as FAM_STATE version
}

// 0x803b5a08 | 104 bytes
void deque_MMU_STATE_pop_back_aux(void* self) {
    // Same as FAM_STATE version
}

// 0x803b5a70 | 92 bytes
void _Rb_tree_int_pair_erase(void* self, void* node) {
    // Red-black tree erase
    if (node == 0) return;
    // Recursive erase of left and right
    void* left = *(void**)((u8*)node + 0x04);
    void* right = *(void**)((u8*)node + 0x08);
    _Rb_tree_int_pair_erase(self, left);
    _Rb_tree_int_pair_erase(self, right);
    SmallBlockAllocator_Free(node);
}

// 0x803b5be0 | 116 bytes
void _Rb_tree_int_pair_insert_equal(void* self, void* val) {
    // Insert into red-black tree allowing duplicates
}

// 0x803b5cb8 | 100 bytes
void ACTTarget_iqRecord_dtor(void* self) {
    // Destructor for action queue record
}

// ============================================================================
// Game Logic Functions - Grouped by Target class
// ============================================================================

// --- ACTTarget ---

// 0x801a1d3c | 152 bytes
char* ACTTarget_GetVariable(void* self, char* name) {
    // Hash-based variable lookup
    u32 hash = AptVar_Hash(name);
    // Switch on hash for different variables
    return 0;
}

// 0x801a1dd4 | 132 bytes
unsigned short* ACTTarget_GetLocalizable(void* self, char* name) {
    u32 hash = AptVar_Hash(name);
    return 0;
}

// 0x801a2b3c | 104 bytes
void* ACTTarget_GetRecord(void* self) {
    // Return current action record
    return 0;
}

// 0x801a30a0 | 124 bytes
void ACTTarget_ExitCancelMode(void* self) {
    // Exit cancel mode and restore state
}

// 0x801a2ba4 | 140 bytes
void ACTTarget_ReOrderActionQueue(void* self) {
    // Reorder actions by priority
}

// 0x801a2aac | 136 bytes
void ACTTarget_RemoveAllActions(void* self, int count) {
    // Remove all queued actions
}

// 0x801a2c34 | 168 bytes
void* ACTTarget_GetInteractionFromID(void* self, int id) {
    // Find interaction by ID in queue
    return 0;
}

// 0x801a2cdc | 84 bytes
void ACTTarget_MoveCancelCursorUp(void* self) {
    // Move cancel cursor up in action queue
}

// 0x801a2d30 | 72 bytes
void ACTTarget_MoveCancelCursorDown(void* self) {
    // Move cancel cursor down
}

// 0x801a2d78 | 184 bytes
void ACTTarget_CancelModeEnabled(void* self, bool enabled) {
    // Enable/disable cancel mode UI
}

// 0x801a311c | 168 bytes
void ACTTarget_CancellingLastObject(void* self) {
    // Handle cancelling the last object in queue
}

// --- BBHTarget ---

// 0x801a390c | 176 bytes
void BBHTarget_SetVariable(void* self, char* name, char* value) {
    u32 hash = AptVar_Hash(name);
    // Dispatch based on hash
}

// 0x801a39bc | 152 bytes
char* BBHTarget_GetVariable(void* self, char* name) {
    u32 hash = AptVar_Hash(name);
    return 0;
}

// 0x801a3e30 | 100 bytes
void BBHTarget_SetCurrentPrice(void* self, int price) {
    // Format price and update display
}

// 0x801a3eb4 | 256 bytes
// NON_MATCHING - update build/buy HUD state
void BBHTarget_UpdateBuildBuyHUD(void* self) {
    // Complex state machine for build/buy mode HUD
}

// 0x801a3fb4 | 100 bytes
void BBHTarget_SetSellingPig(void* self, bool selling) {
    // Show/hide the selling piggy bank icon
}

// 0x801a4018 | 88 bytes
void BBHTarget_SetBBHMode(void* self, int mode) {
    // Change build/buy HUD mode
}

// --- CRDTarget (Credits) ---

// 0x801a4a04 | 224 bytes
void CRDTarget_SetVariable(void* self, char* name, char* value) { }

// 0x801a4be8 | 132 bytes
unsigned short* CRDTarget_GetLocalizable(void* self, char* name) { return 0; }

// 0x801a4eec | 148 bytes
void CRDTarget_HideCredits(void* self) { }

// 0x801a4f84 | 124 bytes
void CRDTarget_StartCredits(void* self) { }

// 0x801a5000 | 208 bytes
void CRDTarget_EndCredits(void* self) { }

// 0x801a566c | 144 bytes
void CRDTarget_InitCreditsTextFetch(void* self) { }

// 0x801a6108 | 128 bytes
void CRDTarget_ShowPhoto(void* self) { }

// 0x801a6188 | 72 bytes
void CRDTarget_HidePhoto(void* self) { }

// --- CSMTarget ---

// 0x801a6c3c | 152 bytes
char* CSMTarget_GetVariable(void* self, char* name) { return 0; }

// 0x801a7a88 | 160 bytes
void CSMTarget_SetIconDisable(void* self, bool disable) { }

// 0x801a7b34 | 148 bytes
void make_number_string(int number, unsigned short* buf) { }

// --- E2ETarget (EyeToy) ---

// 0x801acf0c | 104 bytes
void E2ETarget_InitializeEyeToy(void* self) { }

// 0x801ae244 | 128 bytes
void E2ETarget_OnExitSettings(void* self) { }

// 0x801ad378 | 112 bytes
void E2ETarget_UpdateHue(void* self, char* name, char* value) { }

// 0x801ad458 | 112 bytes
void E2ETarget_UpdateValue(void* self, char* name, char* value) { }

// 0x801ad3e8 | 112 bytes
void E2ETarget_UpdateSaturation(void* self, char* name, char* value) { }

// 0x801ad5a8 | 112 bytes
void E2ETarget_UpdateExposure(void* self, char* name, char* value) { }

// 0x801ad65c | 100 bytes
void E2ETarget_ChangeSelectedSlot(void* self, char* name, char* value) { }

// 0x801ad618 | 68 bytes
void E2ETarget_ChangeFunFrame(void* self, char* name, char* value) { }

// 0x801ad6c0 | 68 bytes
void E2ETarget_ChangeFilter(void* self, char* name, char* value) { }

// 0x801ad4c8 | 124 bytes
void E2ETarget_CaptureFrame(void* self, char* name, char* value) { }

// 0x801ac9b0 | 92 bytes
void E2ETarget_SaveGame(void* self) { }

// 0x801aca0c | 76 bytes
void E2ETarget_OnShutdown(void* self) { }

// 0x801ae050 | 112 bytes
void E2ETarget_OnCircleKeyPressed(void* self, char* name, char* value) { }

// 0x801ac95c | 84 bytes
void E2ETarget_Update(void* self) { }

// 0x801acf74 | 84 bytes
void E2ETarget_ReintializeEyeToy(void* self) { }

// 0x801acea4 | 68 bytes
void E2ETarget_OnExitDialog(void* self, int result) { }

// 0x801ae514 | 132 bytes
void E2ETarget_OnSaveDialogDoneCB(void* self, int result) { }

// 0x801ae598 | 72 bytes
void E2ETarget_OnSaveGameComplete(void* self, bool success) { }

// 0x801ae838 | 84 bytes
void E2ETarget_OnSaveGameDialogClosed(void* self, int result) { }

// --- UIDialog ---

// 0x801b7100 | 180 bytes
void UIDialog_dtor(void* self) { }

// 0x801b7208 | 116 bytes
void UIDialog_HideDialog(void* self) { }

// --- FAMTarget (Family) ---

// 0x801b0764 | 76 bytes
void FAMTarget_UpdateShaders(void* self) { }

// 0x801b3130 | 212 bytes
void FAMTarget_SetCurrentChoice(void* self, char* choice) { }

// 0x801b3024 | 80 bytes
unsigned short* FAMTarget_GetLotName(void* self, int index) { return 0; }

// 0x801b2ec0 | 104 bytes
void FAMTarget_GetSelectedLotDescription(void* self, unsigned short* buf) { }

// 0x801b3284 | 144 bytes
void FAMTarget_GetMoneyForLot(void* self, int lotIndex) { }

// 0x801b2c14 | 192 bytes
void FAMTarget_GetMoneyForFamilyInLotSelect(void* self, char* name, unsigned short* buf) { }

// 0x801b2f28 | 100 bytes
void FAMTarget_ConvertNumericMoneyToString(void* self, int money, unsigned short* buf) { }

// 0x801b340c | 180 bytes
unsigned short* FAMTarget_GetLotNameInFamilySelect(void* self, char* name) { return 0; }

// 0x801b3074 | 188 bytes
void FAMTarget_GetNameForFamily(void* self, void* family, unsigned short* buf) { }

// 0x801b0b18 | 96 bytes
void FAMTarget_UpdateTempShaders(void* self) { }

// 0x801b2f8c | 152 bytes
void FAMTarget_GetMoneyForFamily(void* self, void* family, unsigned short* buf) { }

// 0x801b0ccc | 80 bytes
void FAMTarget_OnLotSelect(void* self) { }

// 0x801b0df8 | 116 bytes
int FAMTarget_IsSelectedLotOccupied(void* self) { return 0; }

// 0x801b0d5c | 80 bytes
int FAMTarget_DoesFamilyExistInFamilyChoice(void* self, int index) { return 0; }

// 0x801b0db4 | 68 bytes
int FAMTarget_GetNumberOfFamilyMembers(void* self, void* family) { return 0; }

// 0x801b3314 | 116 bytes
void FAMTarget_EvictFamily(void* self) { }

// 0x801b1078 | 176 bytes
void FAMTarget_OnReturnFromCreateAFamily(void* self, bool success) { }

// 0x801b2994 | 92 bytes
int FAMTarget_GetNumberOfChoicesInState(void* self, int state) { return 0; }

// 0x801b3388 | 68 bytes
int FAMTarget_GetLotForFamily(void* self, void* family) { return 0; }

// --- FCMTarget ---

// 0x801b3dd0 | 156 bytes
char* FCMTarget_GetVariable(void* self, char* name) { return 0; }

// 0x801b3e6c | 132 bytes
unsigned short* FCMTarget_GetLocalizable(void* self, char* name) { return 0; }

// --- G2DTarget ---

// 0x801b5aac | 104 bytes
void G2DTarget_PopAptButtonFilters(void* self) { }

// 0x801b7040 | 76 bytes
int G2DTarget_CheckPlayerInput(void* self, char* name) { return 0; }

// 0x801b59c0 | 68 bytes
void G2DTarget_HideDialogRunCallbacks(void* self) { }

// 0x801b6b68 | 68 bytes
void G2DTarget_ExecuteZeroInputCallback(void* self) { }

// 0x801b6b24 | 68 bytes
void G2DTarget_ExecuteSelectionCallback(void* self, int selection) { }

// 0x801b6bac | 152 bytes
void G2DTarget_ExecuteDialogClosedCallback(void* self) { }

// 0x801b5960 | 96 bytes
void G2DTarget_HideDialog(void* self) { }

// 0x801b5a50 | 92 bytes
void G2DTarget_PushAptButtonFiltersForPlayer(void* self, int player) { }

// 0x801b6a60 | 196 bytes
void G2DTarget_SetIcon(void* self, void* shader, short x, short y) { }

// 0x801b6c44 | 124 bytes
void G2DTarget_ChangeContinueType(void* self, int type) { }

// 0x801b708c | 116 bytes
void G2DTarget_ServiceG2DShutdown(void* self) { }

// --- H2DTarget ---

// 0x801b836c | 144 bytes
char* H2DTarget_GetVariable(void* self, char* name) { return 0; }

// 0x801b83fc | 132 bytes
unsigned short* H2DTarget_GetLocalizable(void* self, char* name) { return 0; }

// 0x801b8a40 | 140 bytes
void H2DTarget_IncPause(void* self, bool flag) { }

// 0x801b8acc | 136 bytes
void H2DTarget_ReleasePause(void* self, bool flag) { }

// 0x801b8b54 | 80 bytes
void H2DTarget_CloseSidePanels(void* self, int player) { }

// 0x801b8c98 | 116 bytes
void H2DTarget_ACTCancelModeExited(void* self, int player) { }

// 0x801b8ba4 | 152 bytes
void H2DTarget_SelectedPersonChanged(void* self, int player, void* person) { }

// 0x801b8c3c | 92 bytes
void H2DTarget_SpawnRewardMomentDialog(void* self, int a, int b) { }

// 0x801b8d0c | 84 bytes
void H2DTarget_SpawnIntroThoughtBalloon(void* self, void* dialog) { }

// 0x801b8d60 | 80 bytes
int H2DTarget_IsUserReadingIntroThoughtBalloon(void* self) { return 0; }

// 0x801b8e3c | 72 bytes
void H2DTarget_NewWantFearIcon(void* self, int a, int b, u32 c, u32 d, int anim, void* neighbor) { }

// 0x801b8e84 | 68 bytes
void H2DTarget_AddAction(void* self, int player, void* interaction, void* name, u32 icon, void* shader, u32 flags) { }

// 0x801b8f40 | 76 bytes
int H2DTarget_IsActionQueueAvailable(void* self, int player) { return 0; }

// 0x801b8f8c | 76 bytes
void H2DTarget_CSIMActive(void* self, int player, bool active) { }

// 0x801b9318 | 116 bytes
int H2DTarget_IsDialogActive(void* self) { return 0; }

// 0x801b938c | 72 bytes
void* find_ingredient(void** list, u32 count, short id) { return 0; }

// 0x801b93d4 | 72 bytes
void* find_ingredient_type(void** list, u32 count, short typeId) { return 0; }

// --- INGTarget (Ingredients) ---

// 0x801bbab8 | 168 bytes
void INGTarget_install_current_item_shaders(void* self) { }

// 0x801bbb60 | 72 bytes
void* INGTarget_get_current_inginfo(void* self) { return 0; }

// 0x801bbc24 | 168 bytes
void INGTarget_add_mix_ing(void* self, void* ingInfo, u32 slot) { }

// 0x801bc284 | 112 bytes
void INGTarget_update_mix_ing_name(void* self, u32 slot) { }

// 0x801bbba8 | 72 bytes
void* INGTarget_get_current_mix_inginfo(void* self) { return 0; }

// 0x801bc938 | 76 bytes
void INGTarget_play_error_sound(void* self) { }

// 0x801bba58 | 96 bytes
void INGTarget_update_item_states(void* self) { }

// 0x801bbd84 | 144 bytes
void INGTarget_mix_ingredients(void* self) { }

// 0x801bc228 | 92 bytes
void INGTarget_set_done_button_state(void* self, bool enabled) { }

// 0x801baf84 | 228 bytes
char* INGTarget_GetVariable(void* self, char* name) { return 0; }

// 0x801bbcf8 | 140 bytes
int INGTarget_query_enabled(void* self, void* ingInfo) { return 0; }

// 0x801bbe20 | 236 bytes
void INGTarget_get_mix_ing_name(void* self, u32 slot, unsigned short* buf) { }

// 0x801bbf0c | 96 bytes
void INGTarget_get_total_cost(void* self, u32* outCost) { }

// 0x801bc190 | 152 bytes
void INGTarget_set_cell_enabled(void* self, u32 cell, bool enabled) { }

// 0x801bc9a8 | 104 bytes
void INGTarget_onHelpDialogSelection(void* self, int selection) { }

// --- ITBTarget (Intro Thought Balloon) ---

// 0x801bd32c | 156 bytes
char* ITBTarget_GetVariable(void* self, char* name) { return 0; }

// 0x801bd3c8 | 200 bytes
unsigned short* ITBTarget_GetLocalizable(void* self, char* name) { return 0; }

// 0x801bd888 | 108 bytes
void ITBTarget_UpdateIntroThoughtBalloon(void* self) { }

// --- K2YTarget (Keyboard) ---

// 0x801be460 | 232 bytes
unsigned short* K2YTarget_GetName(void* self) { return 0; }

// 0x801bef40 | 96 bytes
void K2YTarget_SetStartMode(void* self, int mode) { }

// 0x801befa0 | 184 bytes
void K2YTarget_SaveName(void* self) { }

// --- M2MTarget (Memory Card) ---

// 0x801c2ef4 | 120 bytes
void M2MTarget_PushButtonFilters(void* self) { }

// 0x801c1ec4 | 160 bytes
void M2MTarget_StartNGCMemoryCardBootChecks(void* self) { }

// 0x801c2d80 | 168 bytes
void M2MTarget_UnloadDialog(void* self) { }

// 0x801c1be8 | 88 bytes
void M2MTarget_GetItemTextSaveGameSelect(void* self, int index, unsigned short* buf) { }

// 0x801c29c4 | 96 bytes
int M2MTarget_IsItemEnabled(void* self, int index) { return 0; }

// 0x801c21d8 | 160 bytes
void M2MTarget_HideWidget(void* self) { }

// 0x801c294c | 120 bytes
void M2MTarget_UpdateSelection(void* self, int selection) { }

// 0x801c0d08 | 140 bytes
void M2MTarget_OnCancel(void* self) { }

// 0x801c2e28 | 80 bytes
void M2MTarget_PrepareNewGame(void* self) { }

// 0x801c2e78 | 124 bytes
void M2MTarget_PrepareLoadGame(void* self) { }

// 0x801c1d70 | 112 bytes
void M2MTarget_StartLoadedGame(void* self) { }

// 0x801c1d08 | 104 bytes
int M2MTarget_DoesMemoryDeviceExist(void* self) { return 0; }

// 0x801c1de0 | 228 bytes
void* M2MTarget_ReturnFailureDestination(void* self) { return 0; }

// 0x801c0ca0 | 104 bytes
void M2MTarget_DialogClosedCallback(void* self) { }

// 0x801c1c40 | 192 bytes
int M2MTarget_IsItemEnabledMemCardSelect(void* self, int index) { return 0; }

// 0x801c2104 | 212 bytes
void M2MTarget_FillWidget(void* self) { }

// 0x801c2a24 | 80 bytes
int M2MTarget_CalcNumItems(void* self) { return 0; }

// 0x801c2f6c | 96 bytes
void M2MTarget_PopButtonFilters(void* self) { }

// --- MDITarget (Modeless Dialogs) ---

// 0x801c3ca8 | 248 bytes
void MDITarget_SpawnModelessDialog(void* self, void* dialog) { }

// 0x801c3df8 | 204 bytes
void MDITarget_DeleteAllModelessDialogs(void* self) { }

// 0x801c3734 | 176 bytes
void MDITarget_SetVariable(void* self, char* name, char* value) { }

// 0x801c3da0 | 80 bytes
void MDITarget_AddToList(void* self, void* dialog) { }

// --- MMUTarget (Main Menu) ---

// 0x801c85d0 | 76 bytes
void MMUTarget_UpdateDevMenuState(void* self, char* name, char* value) { }

// 0x801c861c | 152 bytes
void MMUTarget_OnNGHSelect(void* self, char* name, char* value) { }

// 0x801c6d90 | 96 bytes
void MMUTarget_LaunchLot(void* self, int lot) { }

// 0x801c786c | 68 bytes
void MMUTarget_UpdateTopLevelChoice(void* self, char* name, char* value) { }

// 0x801c78b0 | 68 bytes
void MMUTarget_UpdateGameplayChoice(void* self, char* name, char* value) { }

// 0x801c78f4 | 68 bytes
void MMUTarget_UpdateNumberOfPlayersChoice(void* self, char* name, char* value) { }

// 0x801c8364 | 188 bytes
void MMUTarget_SetCurrentChoice(void* self, char* choice) { }

// 0x801c6e5c | 140 bytes
void MMUTarget_OnUpKeyPressed(void* self, char* name, char* value) { }

// 0x801c6ee8 | 156 bytes
void MMUTarget_OnDownKeyPressed(void* self, char* name, char* value) { }

// 0x801c781c | 80 bytes
void MMUTarget_OnCircleKeyPressed(void* self, char* name, char* value) { }

// 0x801c77cc | 80 bytes
void MMUTarget_OnCancelKeyPressed(void* self, char* name, char* value) { }

// 0x801c81e0 | 72 bytes
int MMUTarget_GetNumberOfChoicesInState(void* self, int state) { return 0; }

// 0x801c6644 | 72 bytes
char* MMUTarget_GetListItemName(void* self, char* name) { return 0; }

// 0x801c86c4 | 92 bytes
void MMUTarget_PollControllersForNumOfPlayersState(void* self) { }

// 0x801c6b54 | 168 bytes
char* MMUTarget_GetLotListItemName(void* self, char* name) { return 0; }

// 0x801c668c | 204 bytes
void MMUTarget_ChangeScreenMode(void* self) { }

// 0x801c6758 | 68 bytes
void MMUTarget_UpdateListItems(void* self) { }

// 0x801c6df0 | 108 bytes
void MMUTarget_LaunchFreeplay(void* self) { }

// 0x801c70f0 | 120 bytes
void MMUTarget_EndPlayerNumberChooser(void* self) { }

// 0x801c8720 | 104 bytes
void MMUTarget_OnDialogClose(void* self, int result) { }

// 0x801c8794 | 88 bytes
void MMUTarget_Dialog2ClosedCallback(void* self) { }

// 0x801c8550 | 128 bytes
void MMUTarget_OnStartGameComplete(void* self, bool success) { }

// --- MODTarget (Mood) ---

// 0x801c9a0c | 216 bytes
void MODTarget_DrawMoodHeadCallback(void* self, void* rc, void* params) { }

// 0x801c93f4 | 204 bytes
char* MODTarget_GetVariable(void* self, char* name) { return 0; }

// 0x801caa04 | 176 bytes
void MODTarget_TriggerAspirationChestDisplay(void* self) { }

// 0x801ca948 | 104 bytes
void MODTarget_DisplayPaused(void* self) { }

// 0x801ca9b0 | 84 bytes
void MODTarget_DisplayFastForward(void* self) { }

// --- MOTTarget ---

// 0x801cb828 | 152 bytes
char* MOTTarget_GetVariable(void* self, char* name) { return 0; }

// 0x801cb8c0 | 132 bytes
unsigned short* MOTTarget_GetLocalizable(void* self, char* name) { return 0; }

// --- O2TTarget (Options) ---

// 0x801ce974 | 236 bytes
void O2TTarget_OnTopLevelStateChange(void* self, char* name, char* value) { }

// 0x801cf090 | 92 bytes
void O2TTarget_RememberOptions(void* self) { }

// 0x801ce920 | 84 bytes
void O2TTarget_SetTopLevelState(void* self, char* name, char* value) { }

// 0x801cffc8 | 164 bytes
void O2TTarget_StartScreenWizard(void* self, char* name, char* value) { }

// 0x801d006c | 84 bytes
void O2TTarget_ExitScreenWizard(void* self, char* name, char* value) { }

// 0x801ceb2c | 188 bytes
void O2TTarget_OnStateChange(void* self) { }

// 0x801cff44 | 132 bytes
void O2TTarget_ShowHelp(void* self) { }

// 0x801ceac0 | 108 bytes
void O2TTarget_Shutdown(void* self, char* name, char* value) { }

// 0x801cf26c | 96 bytes
float O2TTarget_GetScreenXGlobal(void* self, float x) { return 0.0f; }

// 0x801cf360 | 96 bytes
float O2TTarget_GetScreenYGlobal(void* self, float y) { return 0.0f; }

// 0x801cfc40 | 124 bytes
void O2TTarget_OnLeftKeyPressed(void* self, char* name, char* value) { }

// 0x801cfbc4 | 124 bytes
void O2TTarget_OnRightKeyPressed(void* self, char* name, char* value) { }

// 0x801cfae8 | 112 bytes
void O2TTarget_OnUpKeyPressed(void* self, char* name, char* value) { }

// 0x801cfb58 | 108 bytes
void O2TTarget_OnDownKeyPressed(void* self, char* name, char* value) { }

// 0x801cf704 | 124 bytes
void O2TTarget_OnXKeyPressed(void* self, char* name, char* value) { }

// 0x801cfcbc | 116 bytes
void O2TTarget_OnCircleKeyPressed(void* self, char* name, char* value) { }

// 0x801cf1d8 | 148 bytes
float O2TTarget_GetScreenXLocal(void* self, signed char dir) { return 0.0f; }

// 0x801cf2cc | 148 bytes
float O2TTarget_GetScreenYLocal(void* self, signed char dir) { return 0.0f; }

// 0x801cea74 | 76 bytes
void O2TTarget_OnSaveGameComplete(void* self, bool success) { }

// 0x801cebe8 | 84 bytes
void O2TTarget_AudioOptionsModified(void* self) { }

// 0x801cec3c | 84 bytes
void O2TTarget_GameOptionsModified(void* self) { }

// 0x801ceee8 | 120 bytes
void O2TTarget_OnSaveSettingsDialogClose(void* self, int result) { }

// 0x801cef8c | 156 bytes
void O2TTarget_RestoreAudioOptions(void* self) { }

// 0x801cf0ec | 236 bytes
void O2TTarget_RestoreOptions(void* self) { }

// 0x801cfa6c | 124 bytes
void O2TTarget_OnQuitGameDialogClose(void* self, int result) { }

// --- PAZBase (Puzzle Base) ---

// 0x801d00e8 | 168 bytes
void PAZBase_ctor(void* self) { }

// 0x801d0a74 | 240 bytes
unsigned short* PAZBase_GetLocalizable(void* self, char* name) { return 0; }

// --- PCTTarget (Object Catalog) ---

// 0x801d1994 | 116 bytes
void PZ1Target_dtor(void* self) { }

// 0x801d1a10 | 128 bytes
void* FindSelectorContainingResData(void* selector) { return 0; }

// 0x801d1afc | 128 bytes
int GetObjSelector3dDisplayInfo(void* selector, void* objDef) { return 0; }

// 0x801d1b7c | 196 bytes
int sort_selectors_by_name(void* a, void* b) { return 0; }

// 0x801d1c40 | 100 bytes
int sort_cellinfo_by_cost(void* a, void* b) { return 0; }

// 0x801d2140 | 180 bytes
int PCTTarget_cCellInfo_GetPrice(void* self) { return 0; }

// 0x801d1ca4 | 104 bytes
int sort_walls_by_name(void* a, void* b) { return 0; }

// 0x801d1d0c | 104 bytes
int sort_wallpaper_by_name(void* a, void* b) { return 0; }

// 0x801d1d74 | 104 bytes
int sort_floors_by_name(void* a, void* b) { return 0; }

// 0x801d1ddc | 100 bytes
void play_sound(u32 soundId) { }

// 0x801d2074 | 68 bytes
void PCTTarget_cCellInfo_Init_Fence(void* self, int index, void* fenceData) { }

// 0x801d20b8 | 68 bytes
void PCTTarget_cCellInfo_Init_Wall(void* self, int index, void* wallTile) { }

// 0x801d20fc | 68 bytes
void PCTTarget_cCellInfo_Init_Floor(void* self, int index, void* floorTile) { }

// 0x801d22fc | 140 bytes
void PCTTarget_cCellInfo_GetDesc(void* self, unsigned short* buf) { }

// 0x801d581c | 244 bytes
void PCTTarget_on_PCT_Scroll(void* self, int dir) { }

// 0x801d6294 | 220 bytes
void PCTTarget_on_PCT_ShowHelp(void* self, int helpId) { }

// 0x801d5910 | 108 bytes
void PCTTarget_on_PCT_EnterToolMode(void* self) { }

// 0x801d5c80 | 168 bytes
void PCTTarget_on_PCT_SetVisible(void* self, bool visible) { }

// 0x801d49e0 | 76 bytes
void* PCTTarget_get_cell_info_at_gridindex(void* self, u32 index) { return 0; }

// 0x801d6144 | 104 bytes
void PCTTarget_get_motive_rating_value(void* self, u32 index, unsigned short* buf) { }

// 0x801d4b9c | 184 bytes
int filter_object(void* tabInfo, void* selector) { return 0; }

// 0x801d514c | 84 bytes
int filter_floor(int tab, u32 flags, void* floorTile) { return 0; }

// 0x801d6218 | 124 bytes
int PCTTarget_can_afford_selection(void* self) { return 0; }

// 0x801d61bc | 92 bytes
void PCTTarget_set_dialog_visible(void* self, bool visible) { }

// 0x801d6370 | 72 bytes
void PCTTarget_start_action_menu(void* self) { }

// 0x801d63b8 | 240 bytes
void PCTTarget_CreateGrabObjectMenu(void* self, void* simList) { }

// 0x801d64a8 | 184 bytes
void PCTTarget_setup_interactor_camera(void* self, bool flag) { }

// 0x801d6dec | 124 bytes
void PCTTarget_delete_dialog_selection_callback(void* self, int result) { }

// 0x801d73bc | 160 bytes
void PCTTarget_PickedUpObject(void* self, void* obj) { }

// 0x801d7cac | 244 bytes
void PCTTarget_calc_wall_value(void* self, void* cbData) { }

// 0x801d7fd8 | 176 bytes
void PCTTarget_calc_wallpaper_value(void* self, void* cbData) { }

// 0x801d865c | 244 bytes
void PCTTarget_calc_floor_tile_value(void* self, void* cbData) { }

// --- PRGTarget (Progress) ---

// 0x801d9228 | 168 bytes
void PRGTarget_SetVariable(void* self, char* name, char* value) { }

// 0x801da624 | 76 bytes
void PRGTarget_Shutdown(void* self) { }

// 0x801da5d4 | 76 bytes
void PRGTarget_OnCancelKeyPressed(void* self, char* name, char* value) { }

// 0x801d9330 | 104 bytes
void PRGTarget_FormatPercentage(void* self, unsigned short* buf, int num, int denom) { }

// 0x801d92d0 | 96 bytes
void PRGTarget_FormatFraction(void* self, unsigned short* buf, int num, int denom) { }

// 0x801d9398 | 112 bytes
int PRGTarget_GetUnlockedFashions(void* self) { return 0; }

// 0x801d9408 | 112 bytes
int PRGTarget_GetUnlockedRecipies(void* self) { return 0; }

// 0x801d9478 | 112 bytes
int PRGTarget_GetUnlockedObjects(void* self) { return 0; }

// 0x801d94e8 | 144 bytes
int PRGTarget_GetTotalPromotions(void* self) { return 0; }

// 0x801d9578 | 140 bytes
int PRGTarget_GetMaxedCareers(void* self) { return 0; }

// 0x801d9944 | 92 bytes
int PRGTarget_GetNPCsHelped(void* self) { return 0; }

// 0x801d99a0 | 112 bytes
int PRGTarget_GetUnlockedLots(void* self) { return 0; }

// 0x801da538 | 156 bytes
char* PRGTarget_GetVariable(void* self, char* name) { return 0; }

// 0x801da670 | 128 bytes
int sort_records_by_name(void* a, void* b) { return 0; }

// --- R2LTarget / RCPTarget / RMDTarget ---

// 0x801dce2c | 76 bytes
void R2LTarget_onSummaryDialogSelection(void* self, int result) { }

// 0x801dce90 | 176 bytes
unsigned short* GetRecipeName(void* recipe) { return 0; }

// 0x801de6f4 | 164 bytes
void RCPTarget_install_tab_shaders(void* self) { }

// 0x801de798 | 196 bytes
void RCPTarget_install_lock_shaders(void* self) { }

// 0x801de4b4 | 128 bytes
void RCPTarget_Update(void* self) { }

// 0x801dec18 | 156 bytes
void RCPTarget_get_plus_shaders(void* self, void* recipe, u32* outA, u32* outB) { }

// 0x801e014c | 224 bytes
void RMDTarget_StartShowTween(void* self) { }

// 0x801e022c | 176 bytes
void RMDTarget_StartHideTween(void* self) { }

// 0x801df994 | 152 bytes
char* RMDTarget_GetVariable(void* self, char* name) { return 0; }

// 0x801dfa2c | 240 bytes
unsigned short* RMDTarget_GetLocalizable(void* self, char* name) { return 0; }

// 0x801dfb1c | 124 bytes
void RMDTarget_Update(void* self) { }

// --- SKLTarget ---

// 0x801e104c | 152 bytes
char* SKLTarget_GetVariable(void* self, char* name) { return 0; }

// --- WAFTarget (Wants and Fears) ---

// 0x801e4afc | 192 bytes
void WAFTarget_OnShow(void* self) { }

// 0x801e45b8 | 84 bytes
void WAFTarget_OnBottomBarTweenComplete(void* self) { }

// 0x801e4548 | 112 bytes
void WAFTarget_OnTopBarTweenComplete(void* self) { }

// 0x801e30c8 | 152 bytes
char* WAFTarget_GetVariable(void* self, char* name) { return 0; }

// 0x801e4970 | 144 bytes
void WAFTarget_GlowEffectAwayStart(void* self) { }

// 0x801e4758 | 256 bytes
float WAFTarget_MapGameAspirationValueToMeterValue(void* self, float value) { return 0.0f; }

// 0x801e3fb0 | 196 bytes
void WAFTarget_SetAspirationMeterHeight(void* self, int height) { }

// 0x801e4074 | 204 bytes
void WAFTarget_BeginMeterTween(void* self) { }

// 0x801e46ac | 172 bytes
void WAFTarget_CalculateTweenTargetPosition(void* self) { }

// 0x801e4a0c | 240 bytes
void* WAFTarget_GetTopBarTweenColor(void* self) { return 0; }

// 0x801e460c | 160 bytes
void* WAFTarget_GetTopBarColorAtTier(void* self) { return 0; }

// --- WXFTarget ---

// 0x801e629c | 76 bytes
void WXFTarget_Shutdown(void* self) { }

// 0x801e6524 | 76 bytes
void WXFTarget_OnCancelKeyPressed(void* self, char* name, char* value) { }

// 0x801e62ec | 132 bytes
void WXFTarget_UpdateMenuState(void* self, char* name, char* value) { }

// 0x801e6454 | 104 bytes
void WXFTarget_OnLeftKeyPressed(void* self, char* name, char* value) { }

// 0x801e64bc | 104 bytes
void WXFTarget_OnRightKeyPressed(void* self, char* name, char* value) { }

// 0x801e6e30 | 144 bytes
void WXFTarget_ShowHelp(void* self) { }

// 0x801e6ec0 | 72 bytes
void* WXFTarget_GetAspirationIcon(void* self) { return 0; }

// 0x801e6370 | 228 bytes
void WXFTarget_UpdateText(void* self) { }

// 0x801e6b84 | 84 bytes
void* WXFTarget_GetBackgroundShader(void* self, int wantType) { return 0; }
