#if 0 // SKIP
// targets_tsc3.cpp - All small functions (<=64 bytes) from targets_tsc3.obj
// 101 functions total - TSC3 UI target/event handler classes
//
// Original obj: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\targets_tsc3.obj

#include "ui/targets_tsc3.h"

// ============================================================================
// Extern globals (SDA / r13-relative)
// ============================================================================
extern "C" {
    extern EYETarget* s_eyeTarget;     // r13 - 28712
    extern int s_pdaFirstOpen[4];      // r13 - 28524 (4 ints)
    extern int s_invTabIndices[2];     // r13 - 28708 (2 ints)
    extern int s_invCellIndices[2];    // r13 - 28700 (2 ints)
}

// External functions
extern "C" {
    float GetExposureValueRaw();       // 0x80039270
    int atoi_impl(const char* str);    // 0x802DEC50
    float atof_impl(const char* str);  // 0x802DEC2C
    int sprintf_impl(char* buf, const char* fmt, ...); // 0x802DE888
    void AptSetVarImpl(const char* str); // 0x80179C68 (variant)
    void AptSetVarImpl2(const char* str, char* buf); // 0x80179C68
    void operator_delete_impl(void* ptr); // 0x802D1220
    void EyeToySetFunFrame(int frame); // 0x80038E50
    void EyeToySetFilter(int filter);  // 0x80038E34
    void EyeToySetTimerScale(float scale); // 0x80038710
    void EyeToySetTimerMode();         // 0x800387C0
    void INVTarget_ChangeTab(void* self, int tab); // 0x801F0050
    void INVTarget_ExitMode(void* self, int mode); // 0x801F04FC
    void INVTarget_RenderCallback(void* target); // 0x80183410
    void INVTarget_UpdateCallback(void* target); // 0x80183C24
    void INVTarget_StartActionImpl(void* self, void* data, int idx); // 0x801837E4
    void INVTarget_PlaceImpl(void* self, void* data); // 0x801F14EC
    void INVTarget_WallManipImpl(void* self, void* data); // 0x801F1874
    void INVTarget_WallPaintImpl(void* self, void* data); // 0x801F1A6C
    void INVTarget_FloorImpl(void* self, void* data); // 0x801F1BBC
    void INVTarget_GrabImpl(void* self, void* data); // 0x801F1C4C
    void INVTarget_SetVarImpl(void* self, const char* str, void* data); // 0x80177FDC
    void INVTarget_BackExitImpl(void* self); // 0x801F0904
    void INVTarget_ConvertCategory(void* self); // 0x801ECCC0
    void UIDialog_SpawnDialog(void* dialog); // 0x801B71B4
    void EYETarget_RestorePreviousSetting(void* self); // 0x801E724C
    void AptResultSetInt(char* result, int value); // 0x802438E0
}

// External data
extern const float s_fp_zero;       // 0.0f
extern const float s_fp_default_exp; // default exposure
extern int g_buildModeFlag;          // 0x805F148C
extern const char s_aptVarExists[];  // 7-byte APT var struct at offset in data section
extern int s_skillUpgradeGUIDs[];    // 6-element array at 0x803FC710

// ============================================================================
// EYETarget
// ============================================================================

// 0x801E70FC - 24 bytes
void EYETarget::EyeToyUnplugCallback(int) {
    EYETarget* self = s_eyeTarget;
    if (self == 0) return;
    self->m_eyeToyUnplugged = 1;
}

// 0x801E7114 - 56 bytes
// Same pattern as GetTheExposureHandler but in tsc3
float GetExposureHandler() {
    float val = GetExposureValueRaw();
    if (val == s_fp_zero) {
        return s_fp_default_exp;
    }
    return val;
}

// 0x801E724C - 64 bytes
// NON_MATCHING: calls restore function pointer if non-null, decrements settings count
void EYETarget::RestorePreviousSetting() {
    void* restoreFunc = m_restoreFunc;
    if (restoreFunc != 0) {
        float savedVal = m_savedSetting;
        int count = m_settingsCount - 1;
        m_settingsCount = count;
        // Call through function pointer: restoreFunc(savedVal)
        ((void(*)(float))restoreFunc)(savedVal);
    }
}

// 0x801E8F60 - 52 bytes
// NON_MATCHING: loads float literal, sets field, calls two EyeToy functions
void EYETarget::Update() {
    *(int*)((char*)this + 192) = 1;  // m_field at offset 192
    // Loads float from literal pool, calls EyeToySetTimerScale then EyeToySetTimerMode
    EyeToySetTimerScale(1.0f); // approximate literal
    EyeToySetTimerMode();
}

// 0x8020377C - 8 bytes
void EYETarget::SetState(int state) {
    *(int*)((char*)this + 172) = (int)state;
}

// ============================================================================
// GetVar / SetVar handlers
// ============================================================================

// 0x801E9248 - 36 bytes
// NON_MATCHING: copies 7-byte APT var struct (4+2+1 bytes)
void GetVar_EYE_exists::Handler(char* result) {
    // Copies the s_aptVarExists struct to result
    // This is a 7-byte copy: int + short + byte
    *(int*)result = *(int*)&s_aptVarExists[0];
    *(short*)(result + 4) = *(short*)&s_aptVarExists[4];
    *(char*)(result + 6) = s_aptVarExists[6];
}

// 0x801E92B0 - 44 bytes
void GetVar_SliderStep::Handler(char* result) {
    int val = m_field0C;
    AptResultSetInt(result, val);
}

// 0x801E92DC - 44 bytes
void GetVar_GetCount::Handler(char* result) {
    int* countPtr = (int*)((char*)this + 12);
    AptResultSetInt(result, (int)countPtr);
}

// 0x801E9480 - 4 bytes
void GetVar_Legacy::Handler(char*) {
}

// 0x801E9484 - 4 bytes
void GetVar_EYE_targetState::Handler(char*) {
}

// 0x801E9488 - 4 bytes
void GetVar_SaveStatus::Handler(char*) {
}

// 0x801E9648 - 56 bytes
void SetVar_EYE_funframeCurrSel::Handler(char* value) {
    int sel = atoi_impl(value);
    EYETarget* eye = s_eyeTarget;
    eye->m_funframeSelection = sel;
    EyeToySetFunFrame(sel - 1);
}

// 0x801E9680 - 56 bytes
void SetVar_EYE_filterCurrSel::Handler(char* value) {
    int sel = atoi_impl(value);
    EYETarget* eye = s_eyeTarget;
    eye->m_filterSelection = sel;
    EyeToySetFilter(sel - 1);
}

// 0x801E96B8 - 44 bytes
void SetVar_EYE_slotCurrSel::Handler(char* value) {
    int sel = atoi_impl(value);
    EYETarget* eye = s_eyeTarget;
    eye->m_slotSelection = sel;
}

// 0x801E96E4 - 60 bytes
// NON_MATCHING: calls atof, loads function pointer from field, calls it
void SetVar_EYE_settingSliderVal::Handler(char* value) {
    float fval = atof_impl(value);
    void* func = *(void**)((char*)this + 12);
    // Call function pointer with float arg
    ((void(*)(float))func)(fval);
}

// 0x801E9720 - 36 bytes
void SetVar_EYE_opCancelled::Handler(char*) {
    EYETarget* eye = s_eyeTarget;
    eye->RestorePreviousSetting();
}

// ============================================================================
// AptVar
// ============================================================================

// 0x801E97D0 - 56 bytes
// NON_MATCHING: manual loop summing signed bytes
int AptVar::Hash(char* str) {
    int hash = 0;
    int i = 0;
    while (str[i] != 0) {
        hash += (signed char)str[i];
        i++;
        if (str[i] == 0) break;
    }
    return hash;
}

// ============================================================================
// GOLTarget
// ============================================================================

// 0x801EC094 - 4 bytes
void GOLTarget::Update() {
}

// 0x801EC098 - 4 bytes
void GOLTarget::Draw(ERC*) {
}

// ============================================================================
// Free functions
// ============================================================================

// 0x801EC09C - 52 bytes
// NON_MATCHING: loop with CTR over 6-element GUID array
int StaticIsSkillUpgradeObject(int guid) {
    for (int i = 0; i < 6; i++) {
        if (s_skillUpgradeGUIDs[i] == guid) return 1;
    }
    return 0;
}

// 0x801ECC58 - 32 bytes
u32 StaticGetShaderId(int* data) {
    if (data == 0) return 0xD59C7BB5u;
    void* inner = *(void**)data;
    return *(u32*)((char*)inner + 8);
}

// 0x801ECC78 - 32 bytes
u32 StaticGetShaderId(int* data) {
    if (data == 0) return 0xD59C7BB5u;
    void* inner = *(void**)data;
    return *(u32*)inner;
}

// 0x801ECC98 - 32 bytes
u32 StaticGetShaderId(int* data) {
    if (data == 0) return 0xD59C7BB5u;
    void* inner = *(void**)data;
    return *(u32*)((char*)inner + 12);
}

// 0x801ECCB8 - 8 bytes
int IsObjectLockedByGUID(int, int) {
    return 0;
}

// 0x801ECDC4 - 44 bytes
int ConvertShoppingCategoryToInventoryCategory(int category) {
    if (category < 0) return 0;
    if (category <= 8) return 1;
    if (category <= 13) return 2;
    return 0;
}

// ============================================================================
// INVTarget
// ============================================================================

// 0x801EF4B8 - 36 bytes
void INVTarget::Update() {
    INVTarget_UpdateCallback((char*)this + 12700);
}

// 0x801EF4DC - 36 bytes
void INVTarget::Draw(ERC*) {
    INVTarget_RenderCallback((char*)this + 12700);
}

// 0x801EFA00 - 28 bytes
// NON_MATCHING: compiler division by 6 using magic number multiply
int INVTarget::CalcLastPageIdx(int totalItems) {
    return totalItems / 6;
}

// 0x801F04B8 - 36 bytes
void INVTarget::SetIsShaderLoadedByIndex(int index, bool loaded) {
    if ((unsigned)index > 11u) return;
    m_shaderLoaded[index] = (int)loaded;
}

// 0x801F04DC - 32 bytes
int INVTarget::GetIsShaderLoadedByIndex(int index) const {
    if ((unsigned)index > 11u) return 0;
    return m_shaderLoaded[index];
}

// 0x801F0EC8 - 52 bytes
// NON_MATCHING: calls sprintf with "%d" format and price value
void INVTarget::SetPriceCheatString(char* buf, int price, unsigned short currency) {
    sprintf_impl(buf, (const char*)0x803F9A68, price);
}

// 0x801F11F4 - 52 bytes
// NON_MATCHING: calls sprintf with format string and budget
void INVTarget::SetBudgetCheatString(int budget) {
    sprintf_impl((char*)this + 10635, (const char*)0x803F9A74, budget);
}

// 0x801F1228 - 44 bytes
int INVTarget::GetMaxWCharBufSize(unsigned short* str) {
    int len = 0;
    if (str[0] == 0) {
        return (len + 2) * 4;
    }
    do {
        str++;
        len++;
    } while (*str != 0);
    return (len + 2) * 4;
}

// 0x801F146C - 4 bytes
void INVTarget::FireCodeDialogZeroInputCallback() {
}

// 0x801F14BC - 4 bytes
void INVTarget::CannotGrabToInventoryDialogZeroInputCallback() {
}

// 0x801F14C0 - 44 bytes
void INVTarget::StartActionMenu() {
    int idx = m_playerIndex;
    INVTarget_StartActionImpl((char*)this + 12700, this, idx);
}

// 0x801F15FC - 40 bytes
void INVTarget::PlaceModeCallback(int* data) {
    void* userData = *(void**)((char*)data + 4);
    INVTarget_PlaceImpl(userData, data);
}

// 0x801F1974 - 40 bytes
void INVTarget::WallManipulatorCallback(int* data) {
    void* userData = *(void**)((char*)data + 4);
    INVTarget_WallManipImpl(userData, data);
}

// 0x801F1B6C - 40 bytes
void INVTarget::WallPainterCallback(int* data) {
    void* userData = *(void**)((char*)data + 4);
    INVTarget_WallPaintImpl(userData, data);
}

// 0x801F1B94 - 40 bytes
void INVTarget::FloorModeCallback(int* data) {
    void* userData = *(void**)((char*)data + 4);
    INVTarget_FloorImpl(userData, data);
}

// 0x801F1DDC - 40 bytes
void INVTarget::GrabModeCallback(int* data) {
    void* userData = *(void**)((char*)data + 4);
    INVTarget_GrabImpl(userData, data);
}

// 0x801F2370 - 64 bytes
// NON_MATCHING: checks first field of struct, calls AptSetVarImpl
void INVTarget::InstallBldVariables() {
    int* vars = (int*)this;
    if (vars[0] != 0) {
        INVTarget_SetVarImpl((void*)vars[1], (const char*)0x803F97A8, (char*)this + 40);
    }
}

// 0x801F451C - 52 bytes
void INVTarget::SetOnMsgInvNextTab(char*) {
    int idx = m_playerIndex;
    int tab = s_invTabIndices[idx];
    INVTarget_ChangeTab(this, tab + 1);
}

// 0x801F4550 - 52 bytes
void INVTarget::SetOnMsgInvPrevTab(char*) {
    int idx = m_playerIndex;
    int tab = s_invTabIndices[idx];
    INVTarget_ChangeTab(this, tab - 1);
}

// 0x801F4784 - 16 bytes
void INVTarget::SetOnMsgInvRemoveObjectInfo(char*) {
    m_showObjectInfo = 0;
}

// 0x801F4794 - 4 bytes
void INVTarget::SetOnMsgInvClose(char*) {
}

// 0x801F4FCC - 64 bytes
// NON_MATCHING: calls atoi, xori+subfic+adde pattern for == 1 test
void INVTarget::SetOnMsgInvCurrentPanel(char* msg) {
    int val = atoi_impl(msg);
    m_isShoppingPanel = (val == 1) ? 1 : 0;
}

// 0x801F500C - 4 bytes
void INVTarget::SetOnMsgInvShpQueryTab(char*) {
}

// 0x801F5B94 - 12 bytes
void INVTarget::SetOnMsgInvShpRemoveObjectInfo(char*) {
    m_showObjectInfo = 0;
}

// 0x801F6094 - 64 bytes
void INVTarget::InstallShoppingPanelShaders() {
    InstallShoppingCategoryShaders();
    int idx = GetSelectedShoppingCategoryListIdx();
    // Calls secondary shader install function at 0x801F60D8
    void (*fn)(INVTarget*, int) = (void(*)(INVTarget*, int))0x801F60D8;
    fn(this, idx);
}

// 0x801F60D4 - 4 bytes
void INVTarget::InstallShoppingCategoryShaders() {
}

// 0x801F6570 - 52 bytes
void INVTarget::SetOnMsgInvShpCurrentCell(char* msg) {
    int val = atoi_impl(msg);
    m_shoppingCellIdx = (u8)val;
}

// 0x801F65A4 - 36 bytes
// NON_MATCHING: same APT var struct copy as GetVar_EYE_exists::Handler
void INVTarget::GetOnMsgInvExists(char* result) {
    *(int*)result = *(int*)&s_aptVarExists[0];
    *(short*)(result + 4) = *(short*)&s_aptVarExists[4];
    *(char*)(result + 6) = s_aptVarExists[6];
}

// 0x801F66B8 - 64 bytes
// NON_MATCHING: checks g_buildModeFlag, calls different handler or copies short
void INVTarget::GetOnMsgInvBackExitReset(char* result) {
    if (g_buildModeFlag != 0) {
        INVTarget_BackExitImpl(this);
    } else {
        // Copies a short from literal pool to result
        *(short*)result = 0; // approximate
    }
}

// 0x801F673C - 64 bytes
// NON_MATCHING: loads tab index, calls sprintf with "%d" format
void INVTarget::GetOnMsgInvCurrentTab(char* result) {
    int idx = m_playerIndex;
    int tab = s_invTabIndices[idx];
    sprintf_impl(result, (const char*)0x803F8774, tab);
}

// 0x801F677C - 64 bytes
// NON_MATCHING: loads cell index, calls sprintf with "%d" format
void INVTarget::GetOnMsgInvCurrentCell(char* result) {
    int idx = m_playerIndex;
    int cell = s_invCellIndices[idx];
    sprintf_impl(result, (const char*)0x803F8774, cell);
}

// 0x801F67BC - 52 bytes
void INVTarget::GetOnMsgInvTabCount(char* result) {
    sprintf_impl(result, (const char*)0x803F8774, m_tabCount);
}

// 0x801F67F0 - 52 bytes
void INVTarget::GetOnMsgInvInventoryCount(char* result) {
    sprintf_impl(result, (const char*)0x803F8774, m_inventoryCount);
}

// 0x801F6824 - 52 bytes
void INVTarget::GetOnMsgInvInventoryReady(char* result) {
    sprintf_impl(result, (const char*)0x803F8774, 1);
}

// 0x801F6950 - 4 bytes
void INVTarget::GetOnMsgInvShpCurrentCell(char*) {
}

// 0x801F6954 - 52 bytes
void INVTarget::GetOnMsgInvShpResourcesReady(char* result) {
    sprintf_impl(result, (const char*)0x803F8774, 1);
}

// 0x801F714C - 4 bytes
void INVTarget::GetOnMsgInvShpIsTabEnabled(char*) {
}

// 0x801F7470 - 52 bytes
void INVTarget::GetOnMsgInvShpDefaultColor(char* result) {
    sprintf_impl(result, (const char*)0x803F8774, 0);
}

// 0x801F7660 - 36 bytes
void INVTarget::ExitWallPaperingMode() {
    INVTarget_ExitMode(this, 1);
}

// 0x801F7684 - 36 bytes
void INVTarget::ExitWallBuildingMode() {
    INVTarget_ExitMode(this, 1);
}

// 0x801F7FA8 - 56 bytes
// NON_MATCHING: calls INVTarget_ConvertCategory, then AptSetVarImpl2
void INVTarget::SetInvBldItemCount() {
    // Loads from offset 13032, calls ConvertCategory, then sets APT var
    void* data = (void*)*(int*)((char*)this + 13032);
    char buf[64];
    INVTarget_ConvertCategory(data /*, buf */);
    AptSetVarImpl2((const char*)0x803FA468, buf);
}

// 0x80203D30 - 56 bytes
int INVTarget::GetSelectedShoppingCategory() {
    int idx = GetSelectedShoppingCategoryListIdx();
    void* categories = *(void**)((char*)this + 376);
    return *(int*)((char*)categories + idx * 8);
}

// 0x80203D68 - 8 bytes
int INVTarget::GetSelectedShoppingCategoryListIdx() {
    return (int)m_shoppingCatIdx;
}

// ============================================================================
// INTTarget
// ============================================================================

// 0x801F8D98 - 12 bytes
void INTTarget::ShowInterestMeter() {
    m_showInterest = 1;
}

// 0x801F8DA4 - 12 bytes
void INTTarget::HideInterestMeter() {
    m_showInterest = 0;
}

// 0x801F8E8C - 8 bytes
int INTTarget::IsInterestMeterActive() {
    return m_isActive;
}

// ============================================================================
// KEYTarget
// ============================================================================

// 0x801F99FC - 32 bytes
int KEYTarget::IsModeValid() {
    int mode = m_mode;
    if (mode > 4) return 0;
    if (mode < 1) return 0;
    return 1;
}

// ============================================================================
// OPTTarget
// ============================================================================

// 0x801FC2AC - 4 bytes
void OPTTarget::Update() {
}

// ============================================================================
// PDATarget
// ============================================================================

// 0x801FEAA0 - 60 bytes
// NON_MATCHING: complex logic with subfic/subfe/neg pattern for != 13 check
void PDATarget::SetupFirstOpenMessage(int player, int mode) {
    if ((int)mode == 13) return;
    if (player == 2) {
        s_pdaFirstOpen[0] = (int)mode;
        s_pdaFirstOpen[1] = (int)mode;
        return;
    }
    s_pdaFirstOpen[player] = (int)mode;
}

// 0x801FEE44 - 60 bytes
void PDATarget::Update() {
    int flag = m_fireOnExitFlag;
    if (flag != 0) {
        m_fireOnExitFlag = 0;
        UIDialog_SpawnDialog((char*)this + 132);
    }
}

// 0x801FEFA0 - 16 bytes
int PDATarget::SetStartFireOnExit(bool fire) {
    int old = m_startFireOnExit;
    m_startFireOnExit = (int)fire;
    return old;
}

// 0x8020375C - 16 bytes
INVTarget* PDATarget::GetINVTarget(int player) const {
    return m_invTargets[player];
}

// 0x8020376C - 16 bytes
int PDATarget::GetPdaMode(int player) {
    return m_pdaModes[player];
}

// ============================================================================
// RELTarget
// ============================================================================

// 0x802012DC - 8 bytes
int RELTarget::GetFace(int) {
    return 6;
}

// 0x802012E4 - 8 bytes
int RELTarget::GetCrew(int) {
    return 0;
}

// 0x80201338 - 36 bytes
// NON_MATCHING: loop using CTR, follows linked list
void* RELTarget::GetRecord(int index) {
    void* node = m_headList;
    if (index <= 0) return node;
    for (int i = 0; i < index; i++) {
        if (node == 0) return 0;
        node = *(void**)((char*)node + 4);
    }
    return node;
}

// ============================================================================
// AptVar destructors - all follow identical pattern:
// Set vtable to AptVar base vtable, conditionally call operator delete
// ============================================================================

// 0x803BAA60 - 52 bytes
AptVar::~AptVar() {
    // vtable = AptVar vtable
    // if (flags & 1) operator_delete_impl(this);
}

// 0x803BAA94 - 52 bytes
SetVar_EYE_state::~SetVar_EYE_state() {
}

// 0x803BAAC8 - 52 bytes
SetVar_EYE_topLevelCurrSel::~SetVar_EYE_topLevelCurrSel() {
}

// 0x803BAAFC - 52 bytes
SetVar_EYE_funframeCurrSel::~SetVar_EYE_funframeCurrSel() {
}

// 0x803BAB30 - 52 bytes
SetVar_EYE_filterCurrSel::~SetVar_EYE_filterCurrSel() {
}

// 0x803BAB64 - 52 bytes
SetVar_EYE_slotCurrSel::~SetVar_EYE_slotCurrSel() {
}

// 0x803BAB98 - 52 bytes
SetVar_EYE_saveToSlotStatus::~SetVar_EYE_saveToSlotStatus() {
}

// 0x803BABCC - 52 bytes
SetVar_EYE_settingSliderVal::~SetVar_EYE_settingSliderVal() {
}

// 0x803BAC00 - 52 bytes
SetVar_EYE_opCancelled::~SetVar_EYE_opCancelled() {
}

// 0x803BAC34 - 52 bytes
GetVar_LockedStatus::~GetVar_LockedStatus() {
}

// 0x803BAC68 - 52 bytes
GetVar_SliderStep::~GetVar_SliderStep() {
}

// 0x803BAC9C - 52 bytes
GetVar_GetCount::~GetVar_GetCount() {
}

// 0x803BACD0 - 52 bytes
GetVar_EYE_exists::~GetVar_EYE_exists() {
}

// 0x803BAD04 - 52 bytes
GetVar_EYE_targetState::~GetVar_EYE_targetState() {
}

// 0x803BAD38 - 52 bytes
GetVar_EYE_settingSliderVal::~GetVar_EYE_settingSliderVal() {
}

// 0x803BAD6C - 52 bytes
GetVar_SaveRequired::~GetVar_SaveRequired() {
}

// 0x803BADA0 - 52 bytes
GetVar_SaveStatus::~GetVar_SaveStatus() {
}

// 0x803BADD4 - 52 bytes
GetVar_ImageSlotsAvail::~GetVar_ImageSlotsAvail() {
}

// 0x803BAE08 - 52 bytes
GetVar_EYE_connectionStatus::~GetVar_EYE_connectionStatus() {
}

// 0x803BAE3C - 52 bytes
GetVar_Legacy::~GetVar_Legacy() {
}
#endif
