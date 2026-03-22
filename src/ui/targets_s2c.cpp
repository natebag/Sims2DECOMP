// targets_s2c.cpp - All small functions (<=64 bytes) from targets_s2c.obj
// 196 functions total - S2C UI target/event handler classes
//
// Original obj: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\targets_s2c.obj

#include "ui/targets_s2c.h"

// ============================================================================
// Extern globals (SDA / r13-relative)
// ============================================================================
extern "C" {
    extern int s_g2dInitComplete;       // r13 - 30368
    extern MMUTarget* s_mmuSingleton;   // r13 - 30180
    extern int s_k2yMode;              // r13 - 30256
    extern int s_ingRefrigeratorLevel; // r13 - 30260
    extern int s_staticInitVal;        // r13 - 23852
    extern E2ETarget* s_e2eSingleton;  // r13 - 30452
    extern int s_h2dPauseRefCount;     // r13 - 30384 (?)
    extern float s_e2eCurrentHue;      // r13 - 30444
    extern float s_e2eCurrentBrightness; // r13 - 30440
    extern float s_e2eCurrentSaturation; // r13 - 30436
    extern float s_e2eCurrentExposure;   // r13 - 30432
}

// External data addresses
extern unsigned short s_savedFirstName[];  // 0x8050C0E4
extern unsigned short s_savedLastName[];   // 0x8050C124
extern const char s_pazTLA[];              // 0x803F3F54
extern const char s_pz1TLA[];             // 0x803F3F5C

// External functions (called by small functions)
extern "C" {
    // EyeToy functions
    int EyeToyIsUnplugged();         // 0x80038FE0
    float GetHueValue();             // 0x80039378
    float GetBrightnessValue();      // 0x8003932C
    float GetSaturationValue();      // 0x80039434
    void SetHueValue(float val);     // 0x800393B0
    void SetSaturationValue(float val); // 0x8003944C
    void SetExposureValue(float val);   // 0x800392C4
    void SetBrightnessValue(float val); // 0x80039344
    void EyeToySaveSlot(int slot);   // 0x80038EEC
    void EyeToyResetDefaults();      // 0x800378E4
    float GetExposureValueRaw();     // 0x80039270

    // UI system functions
    void G2DTarget_SetButtonFilter(void* self, int filter); // called at 0x801B5A50
    void G2DTarget_SpawnDialogImpl(void* g2d, UIDialog* dialog); // 0x801B5B14
    void G2DTarget_ChangeContinueTypeImpl(void* g2d, int type); // 0x801B6C44
    void AptUnloadScreen(void* apt, int screenId); // 0x8017FAE4
    void AptSetMenuState(const char* state); // 0x80177D0C

    // Conversion functions
    int atoi_impl(const char* str); // 0x802DEC50

    // ACTTarget functions (large, called by small wrappers)
    void ACTTarget_RemoveAction(void* self, int player, Interaction* action); // 0x801A2828
    void ACTTarget_RemoveAllActions(void* self, int count); // 0x801A2AAC
    void ACTTarget_SetIconDisable(void* self, bool disable); // 0x801A7A88

    // Target-specific large functions
    void FAMTarget_SetMenuStateImpl(void* self, int state); // 0x801B2608
    void MDITarget_SpawnImpl(void* self, UIDialog* dialog); // 0x801C3CA8
    void MDITarget_CleanupImpl(void* self);                 // 0x801C3DF8
    void MODTarget_InWarning(void* self, int mode, bool flag); // 0x801CA1E8
    void MODTarget_SetMoodValue(void* self, int player, bool flag); // 0x801CA44C
    void MODTarget_DisplayPaused(void* self); // 0x801CA948
    void MODTarget_DisplayFastForward(void* self); // 0x801CA9B0
    void INTTarget_SetInteraction(void* self, unsigned int a, unsigned int b); // 0x801F8E94
    void INTTarget_TriggerAnim(void* self, unsigned int a, unsigned int b, unsigned int c); // 0x801F8FDC
    void INTTarget_MirrorUpArrow(void* self, bool state); // 0x801F9154
    void* INGTarget_getIngredientListImpl(void* self); // 0x801BBB60
    void INGTarget_exitImpl(void* self, int confirm); // 0x801BB7DC
    void G2DTarget_RenderCallback(void* self); // 0x80183410
    void ESimsApp_SetStartLot(void* app, int lot); // 0x80003FE4
    void MMUTarget_IncrementChoice(void* self); // 0x801C8228
    void MMUTarget_DecrementChoice(void* self); // 0x801C8420
    void MMUTarget_OnChoiceChange(void* self); // 0x801C7998
    void PAZBase_DestroyImpl(void* self);       // 0x801D0190
    void PCTTarget_GrabCallback(void* self, void* data); // 0x801D6824
    void PCTTarget_PlaceCallback(void* self, void* data); // 0x801D745C
    void PCTTarget_WallManipCallback(void* self, void* data); // 0x801D7A50
    void PCTTarget_WallPaintCallback(void* self, void* data); // 0x801D8088
    void PCTTarget_FloorCallback(void* self, void* data); // 0x801D84CC
    void* GetResDataFromSelectorImpl(void* selector); // 0x801D1A10
    int GetFireCodeLevel(int player);           // 0x800427A8
    void ShowHelpDialogImpl(void* dialog, int helpId, const char* helpStr, int a, int b, int c); // 0x80175EDC
    void AptSetVarImpl(const char* varStr); // 0x80179BB0
    void WXFTarget_UpdateHelpState(void* self); // 0x801E6E30
    void O2TTarget_QuitImpl(void* self); // 0x801CF780
    void FAMTarget_GetFamilyImpl(void* self); // 0x801B33CC delegate to large function
    void R2LTarget_SearchImpl(void* self); // see R2LTarget
    void _throwLengthError(const char* msg); // 0x802427C0
    void _throwLengthError2();               // 0x802427E8
    void operator_delete_impl(void* ptr);     // 0x802D1220
}

// External globals
extern void* g_aptSystem;     // lis r9,-32697; lwz ...,24336(r9) => 0x805F1210
extern void* g_g2dTarget;     // lis r9,-32697; lwz ...,24328(r9) => 0x805F1208
extern void* g_audioManager;  // lis r9,-32697; lwz ...,24340(r9) => 0x805F1214
extern int g_buildModeFlag;   // lis r9,-32697; lwz ...,24972(r9) => 0x805F148C

// Literal pool values
extern const float s_fp_zero;         // 0.0f
extern const float s_fp_default_exp;  // default exposure value
extern const float s_fp_100;          // 100.0f

// ============================================================================
// ACTTarget
// ============================================================================

// 0x801A21EC - 12 bytes
void ACTTarget::ShowActionQueue() {
    m_showQueue = 1;
}

// 0x801A21F8 - 12 bytes
void ACTTarget::HideActionQueue() {
    m_showQueue = 0;
}

// 0x801A23BC - 8 bytes
int ACTTarget::IsActionQueueActive() {
    return m_isActive;
}

// 0x801A2B34 - 8 bytes
int ACTTarget::IsActionQueueAvailable(int) const {
    return 1;
}

// 0x801A2C30 - 4 bytes
void ACTTarget::DebugListValidation() {
}

// ============================================================================
// BBHTarget
// ============================================================================

// 0x801A3E94 - 8 bytes
int BBHTarget::IsBuildBuyHUDActive() {
    return m_isActive;
}

// 0x801A3E9C - 12 bytes
void BBHTarget::ShowBuildBuyHUD() {
    m_showHUD = 1;
}

// 0x801A3EA8 - 12 bytes
void BBHTarget::HideBuildBuyHUD() {
    m_showHUD = 0;
}

// ============================================================================
// CRDTarget
// ============================================================================

// 0x801A4C6C - 4 bytes
void CRDTarget::Draw(ERC*) {
}

// 0x801A4F80 - 4 bytes
void CRDTarget::UpdateCredits() {
}

// ============================================================================
// CSMTarget
// ============================================================================

// 0x801A764C - 20 bytes
void CSMTarget::ShowCSIM() {
    m_showCSIM = 1;
    m_field98 = 0;
}

// 0x801A7660 - 20 bytes
void CSMTarget::HideCSIM() {
    if (m_field98 != 0) {
        return;
    }
    m_showCSIM = 0;
}

// 0x801A7674 - 8 bytes
int CSMTarget::IsCSIMActive() {
    return m_isActive;
}

// ============================================================================
// CSPTarget
// ============================================================================

// 0x801A9918 - 4 bytes
void CSPTarget::Update() {
}

// 0x801AA57C - 4 bytes
void CSPTarget::onHelpDialogSelection(int) {
}

// ============================================================================
// get_blank_shader_id (free function)
// ============================================================================

// 0x801A7B28 - 12 bytes
// lis r3,0x9F93; ori r3,r3,0xFF74
u32 get_blank_shader_id() {
    return 0x9F93FF74u;
}

// ============================================================================
// GetTheExposureHandler (free function)
// ============================================================================

// 0x801AA580 - 56 bytes
// NON_MATCHING: calls GetExposureValueRaw, compares with literal, returns alternate if equal
float GetTheExposureHandler() {
    float val = GetExposureValueRaw();
    if (val == s_fp_zero) {
        return s_fp_default_exp;
    }
    return val;
}

// ============================================================================
// E2ETarget
// ============================================================================

// 0x801ACC34 - 44 bytes
// NON_MATCHING: static function, loads singleton from r13
void E2ETarget::EyeToyUnplugCallback(int) {
    E2ETarget* self = s_e2eSingleton;
    self->m_eyeToyUnplugged = 1;
    self->OnEyeToyUnplugged();
}

// 0x801ACC60 - 32 bytes
// NON_MATCHING: just a tail-call wrapper to SpawnNoEyeToyDialogBox
void E2ETarget::OnEyeToyUnplugged() {
    // Calls SpawnNoEyeToyDialogBox at 0x801ACC80
    // but we represent it as a tail call
    void (*fn)(E2ETarget*) = (void (*)(E2ETarget*))0x801ACC80;
    fn(this);
}

// 0x801ACEE8 - 36 bytes
int E2ETarget::IsEyeToyPluggedIn() {
    return !EyeToyIsUnplugged();
}

// 0x801ACFC8 - 60 bytes
void E2ETarget::SaveCurrentSettings(char*, char*) {
    s_e2eCurrentHue = GetHueValue();
    s_e2eCurrentBrightness = GetBrightnessValue();
    s_e2eCurrentSaturation = GetSaturationValue();
    s_e2eCurrentExposure = GetTheExposureHandler();
}

// 0x801AD004 - 60 bytes
void E2ETarget::RestorePreviousSettings() {
    SetHueValue(s_e2eCurrentHue);
    SetSaturationValue(s_e2eCurrentSaturation);
    SetExposureValue(s_e2eCurrentExposure);
    SetBrightnessValue(s_e2eCurrentBrightness);
}

// 0x801AD544 - 36 bytes
void E2ETarget::SaveFrame(char*, char*) {
    int slot = *(int*)((char*)this + 192);  // offset 0xC0
    EyeToySaveSlot(slot);
}

// 0x801AD568 - 64 bytes
void E2ETarget::SetDefault(char*, char*) {
    EyeToyResetDefaults();
    s_e2eCurrentHue = GetHueValue();
    s_e2eCurrentBrightness = GetBrightnessValue();
    s_e2eCurrentSaturation = GetSaturationValue();
    s_e2eCurrentExposure = GetTheExposureHandler();
}

// 0x801AD820 - 64 bytes
// NON_MATCHING: integer modulo via divwu+mullw+subf
void E2ETarget::OnUpKeyPressed(char*, char*) {
    int idx = *(int*)((char*)this + 168);
    int count = *(int*)((char*)this + 172);
    idx = (idx + 1) % count;
    *(int*)((char*)this + 168) = idx;
    UpdateText();
}

// 0x801AD860 - 64 bytes
void E2ETarget::OnDownKeyPressed(char*, char*) {
    int idx = *(int*)((char*)this + 168);
    idx = idx - 1;
    *(int*)((char*)this + 168) = idx;
    if (idx < 0) {
        int count = *(int*)((char*)this + 172);
        *(int*)((char*)this + 168) = count - 1;
    }
    UpdateText();
}

// 0x801AE1E4 - 60 bytes
// NON_MATCHING: loads string literal address, calls ShowHelpDialogImpl
void E2ETarget::ShowHelp() {
    ShowHelpDialogImpl((char*)this + 500, 0, (const char*)0x803F9AAC, 0, 1, 0);
}

// 0x801AE220 - 36 bytes
void E2ETarget::OnEnterSettings() {
    float* savedHue = (float*)((char*)this + 200);
    float* savedBrightness = (float*)((char*)this + 204);
    float* savedSaturation = (float*)((char*)this + 208);
    float* savedExposure = (float*)((char*)this + 212);
    *savedHue = s_e2eCurrentHue;
    *savedExposure = s_e2eCurrentExposure;
    *savedBrightness = s_e2eCurrentBrightness;
    *savedSaturation = s_e2eCurrentSaturation;
}

// 0x801E7088 - 8 bytes
int E2ETarget::GetTopLevelState() {
    return m_topLevelState;
}

// ============================================================================
// FAMTarget
// ============================================================================

// 0x801AFCAC - 44 bytes
// NON_MATCHING: calls AptUnloadScreen with constant 68
void FAMTarget::UnloadScreen() {
    AptUnloadScreen(g_aptSystem, 68);
}

// 0x801B070C - 4 bytes
void FAMTarget::Shutdown() {
}

// 0x801B0710 - 4 bytes
void FAMTarget::Update() {
}

// 0x801B0714 - 60 bytes
// NON_MATCHING: calls atoi then FAMTarget_SetMenuStateImpl
void FAMTarget::UpdateMenuState(char*, char* value) {
    int state = atoi_impl(value);
    FAMTarget_SetMenuStateImpl(this, state);
}

// 0x801B0750 - 12 bytes
// NON_MATCHING: original has stwu r1,-32(r1); addi r1,r1,32; blr
void FAMTarget::UpdateText() {
}

// 0x801B075C - 4 bytes
void FAMTarget::OnLeftKeyPressed(char*, char*) {
}

// 0x801B0760 - 4 bytes
void FAMTarget::OnRightKeyPressed(char*, char*) {
}

// 0x801B0DAC - 8 bytes
int FAMTarget::ConvertSelectedFamilyIndexToActualGameIndex(int index) {
    return index + 20;
}

// 0x801B0D1C - 64 bytes
// NON_MATCHING: complex vtable dispatch pattern
int FAMTarget::GetFamilyInFamilyList(int index) {
    int gameIdx = ConvertSelectedFamilyIndexToActualGameIndex(index);
    // Vtable dispatch: loads vtable from r13-relative global, calls virtual method
    // This is a complex pattern involving indirect call through vtable
    void** vtable_ptr = *(void***)((char*)0 + *(int*)((char*)0 + *(int*)(0x80000000))); // placeholder
    // NON_MATCHING
    (void)gameIdx;
    return 0;
}

// 0x801B0E6C - 4 bytes
void FAMTarget::OnCancelDialog() {
}

// 0x801B1128 - 48 bytes
void FAMTarget::OnBackoutToMainMenuDialogClose(int sel) {
    if (sel == 1) {
        AptSetMenuState((const char*)0x803F96A4);
    }
}

// 0x801B2604 - 4 bytes
void FAMTarget::OnCircleKeyPressed(char*, char*) {
}

// 0x801B29F0 - 8 bytes
int FAMTarget::ConvertSelectedLotIndexToActualGameIndex(int index) {
    return index + 13;
}

// 0x801B3204 - 64 bytes
// NON_MATCHING: complex vtable dispatch via r13-relative global
int FAMTarget::GetFamilyInLot(int index) {
    int gameIdx = ConvertSelectedLotIndexToActualGameIndex(index);
    // Vtable dispatch: same pattern as GetFamilyInFamilyList
    (void)gameIdx;
    return 0;  // NON_MATCHING
}

// 0x801B33CC - 64 bytes
// NON_MATCHING: calls GetFamilyInFamilyList, checks result, calls secondary function
int FAMTarget::GetLotForFamily(int index) {
    int family = GetFamilyInFamilyList(index);
    if (family == 0) return 0;
    // calls 0x801B3388 with this
    return 0;  // NON_MATCHING
}

// 0x801B3244 - 64 bytes
// NON_MATCHING: calls ConvertSelectedLotIndexToActualGameIndex, ESimsApp_SetStartLot, AptSetMenuState
void FAMTarget::LaunchLot() {
    int lot = *(int*)((char*)this + 0x14C);
    int gameIdx = ConvertSelectedLotIndexToActualGameIndex(lot);
    ESimsApp_SetStartLot((void*)0x805F1208, gameIdx); // approximate
    AptSetMenuState((const char*)0x803F9794);
}

// ============================================================================
// FCMTarget
// ============================================================================

// 0x801B41B8 - 12 bytes
void FCMTarget::HideFireCodeMeter() {
    m_showMeter = 0;
}

// 0x801B441C - 60 bytes
// NON_MATCHING: float conversion pattern may differ
int FCMTarget::GetFireCodeMeterLevel() {
    float level = (float)GetFireCodeLevel(0);
    int result = (int)(level * s_fp_100);
    return result;
}

// 0x801B4458 - 8 bytes
int FCMTarget::IsFireCodeMeterActive() {
    return m_isActive;
}

// 0x801B4460 - 48 bytes
void FCMTarget::SetMeterHeight(int height) {
    if (height < 0) {
        m_meterHeight = 0;
        return;
    }
    if (height > 100) {
        m_meterHeight = 100;
        return;
    }
    m_meterHeight = height;
}

// ============================================================================
// G2DTarget
// ============================================================================

// 0x801B5A04 - 8 bytes
int G2DTarget::IsG2DActive() {
    return m_isActive;
}

// 0x801B5A0C - 8 bytes
int G2DTarget::IsG2DSpawned() {
    return m_isSpawned;
}

// 0x801B5A14 - 60 bytes
void G2DTarget::PushAptButtonFilters() {
    G2DTarget_SetButtonFilter(this, 0);
    G2DTarget_SetButtonFilter(this, 1);
}

// 0x801B7000 - 64 bytes
void G2DTarget::UnloadUI() {
    if (m_transitionState == 5) {
        m_transitionState = 6;
        AptUnloadScreen(g_aptSystem, 47);
    }
}

// 0x801E7050 - 8 bytes
int G2DTarget::IsInitComplete() {
    return s_g2dInitComplete;
}

// 0x801E7058 - 32 bytes
int G2DTarget::HasPendingTransition() {
    int state = m_transitionState;
    if (state == 0) return 0;
    if (state == 3) return 0;
    return 1;
}

// ============================================================================
// UIDialog
// ============================================================================

// 0x801E7044 - 4 bytes
void UIDialog::SelectionCallback(int) {
}

// 0x801E7048 - 4 bytes
void UIDialog::ZeroInputCallback() {
}

// 0x801E704C - 4 bytes
void UIDialog::DialogClosedCallback() {
}

// 0x801B71B4 - 44 bytes
void UIDialog::SpawnDialog() {
    G2DTarget_SpawnDialogImpl(g_g2dTarget, this);
}

// 0x801B71E0 - 40 bytes
// NON_MATCHING: loads g_g2dTarget, calls ChangeContinueTypeImpl
void UIDialog::ChangeContinueType(int type) {
    (void)type;
    G2DTarget_ChangeContinueTypeImpl(g_g2dTarget, type);
}

// ============================================================================
// H2DTarget
// ============================================================================

// 0x801B8480 - 4 bytes
void H2DTarget::Draw(ERC*) {
}

// 0x801B8A38 - 8 bytes
int H2DTarget::GetPausePlayer() {
    return m_pausePlayer;
}

// 0x801B8DB0 - 44 bytes
void H2DTarget::SpawnModelessDialog(UIDialog* dialog) {
    void* mdi = m_mdiTarget;
    if (mdi != 0) {
        MDITarget_SpawnImpl(mdi, dialog);
    }
}

// 0x801B8DDC - 44 bytes
void H2DTarget::CleanupModelessDialogs() {
    void* mdi = m_mdiTarget;
    if (mdi != 0) {
        MDITarget_CleanupImpl(mdi);
    }
}

// 0x801B8E08 - 52 bytes
int H2DTarget::CountModelessDialogs() {
    void* mdi = m_mdiTarget;
    if (mdi == 0) return 0;
    return ((MDITarget*)mdi)->CountModelessDialogs();
}

// 0x801B8EC8 - 60 bytes
void H2DTarget::RemoveAction(int player, Interaction* action) {
    if (player > 1u) return;
    void* target = *(void**)((char*)this + 180 + player * 4);
    if (target != 0) {
        ACTTarget_RemoveAction(target, player, action);
    }
}

// 0x801B8F04 - 60 bytes
void H2DTarget::RemoveAllActions(int player) {
    if ((unsigned)player > 1u) return;
    void* target = *(void**)((char*)this + 180 + player * 4);
    if (target != 0) {
        ACTTarget_RemoveAllActions(target, player);
    }
}

// 0x801B8FD8 - 60 bytes
void H2DTarget::SKLInWarning(int player, bool warning) {
    void* target = *(void**)((char*)this + 136 + player * 4);
    if (target != 0) {
        MODTarget_InWarning(target, 2, 1);
    }
}

// 0x801B9014 - 60 bytes
void H2DTarget::MOTInWarning(int player, bool warning) {
    void* target = *(void**)((char*)this + 136 + player * 4);
    if (target != 0) {
        MODTarget_InWarning(target, 3, 0);
    }
}

// 0x801B9050 - 56 bytes
void H2DTarget::WAFInWarning(int player, bool warning, bool extra) {
    void* target = *(void**)((char*)this + 136 + player * 4);
    if (target != 0) {
        MODTarget_InWarning(target, 4, extra);
    }
}

// 0x801B9088 - 56 bytes
void H2DTarget::SetMoodMeterValue(int player, float value, bool extra) {
    void* target = *(void**)((char*)this + 136 + player * 4);
    if (target != 0) {
        MODTarget_SetMoodValue(target, (int)extra, false);
    }
}

// 0x801B90C0 - 12 bytes
void H2DTarget::RewardMomentDialogClosed() {
    m_rewardClosed = 1;
}

// 0x801B91E4 - 60 bytes
void H2DTarget::SetInteractionDisplayValues(int player, unsigned int a, unsigned int b) {
    void* target = *(void**)((char*)this + 188 + player * 4);
    if (target != 0) {
        INTTarget_SetInteraction(target, a, b);
    }
}

// 0x801B9220 - 64 bytes
void H2DTarget::TriggerInteractionAnimation(int player, unsigned int a, unsigned int b, unsigned int c) {
    void* target = *(void**)((char*)this + 188 + player * 4);
    if (target != 0) {
        INTTarget_TriggerAnim(target, a, b, c);
    }
}

// 0x801B9260 - 44 bytes
void H2DTarget::DisplayPaused() {
    void* target = *(void**)((char*)this + 136);
    if (target != 0) {
        MODTarget_DisplayPaused(target);
    }
}

// 0x801B928C - 44 bytes
void H2DTarget::DisplayFastForward() {
    void* target = *(void**)((char*)this + 136);
    if (target != 0) {
        MODTarget_DisplayFastForward(target);
    }
}

// 0x801B92B8 - 48 bytes
void H2DTarget::CSIMSetIconDisable(int player, bool disable) {
    void* target = *(void**)((char*)this + 144 + player * 4);
    ACTTarget_SetIconDisable(target, disable);
}

// 0x801B92E8 - 48 bytes
void H2DTarget::INTMirrorUpArrow(int player, bool state) {
    void* target = *(void**)((char*)this + 188 + player * 4);
    INTTarget_MirrorUpArrow(target, state);
}

// ============================================================================
// INGTarget
// ============================================================================

// 0x801B941C - 24 bytes
INGTarget::TabInfo::TabInfo() {
    m_field08 = 0;
    m_field00 = 0;
    m_field04 = 0;
}

// 0x801B9434 - 20 bytes
INGTarget::IngInfo::IngInfo() {
    m_field04 = 0;
    m_field00 = 0;
}

// 0x801B9448 - 16 bytes
void INGTarget::IngInfo::erase() {
    m_field04 = 0;
    m_field00 = 0;
}

// 0x801B9458 - 16 bytes
int INGTarget::SetRefrigeratorLevel(int level) {
    int old = s_ingRefrigeratorLevel;
    s_ingRefrigeratorLevel = level;
    return old;
}

// 0x801BBBF0 - 52 bytes
// NON_MATCHING: calls get_ingredient_list_impl, checks null, returns field
int* INGTarget::get_current_ingredient() {
    IngInfo* info = (IngInfo*)INGTarget_getIngredientListImpl(this);
    if (info != 0) {
        return (IngInfo*)*(int*)info;
    }
    return 0;
}

// 0x801BBCCC - 44 bytes
int INGTarget::get_ingredient_type(int& info) const {
    int* p = (int*)info.m_field00;
    if (p == 0) return 0;
    int* q = (int*)info.m_field04;
    if (q == 0) return 0;
    return *(short*)q;
}

// 0x801BBE14 - 12 bytes
u32 INGTarget::get_blank_shader_id() const {
    return 0x9F93FF74u;
}

// 0x801BC114 - 64 bytes
// NON_MATCHING: loop with CTR, checks grid ingredients
int* INGTarget::get_grid_ingredient(short id) {
    void** grid = (void**)((char*)this + 432);
    for (int i = 0; i < 12; i++) {
        void* ing = grid[i];
        if (ing != 0) {
            void* data = *(void**)ing;
            if (data != 0) {
                short ingId = *(short*)data;
                if (ingId == id) return (IngInfo*)ing;
            }
        }
    }
    return 0;
}

// 0x801BC154 - 60 bytes
// NON_MATCHING: loop with CTR, checks mix ingredients
int* INGTarget::get_mix_ingredient(short id) const {
    void** mix = (void**)((char*)this + 480);
    for (int i = 0; i < 4; i++) {
        if (mix != 0) {
            void* data = *(void**)mix;
            if (data != 0) {
                short ingId = *(short*)data;
                if (ingId == id) return (IngInfo*)mix;
            }
        }
        mix = (void**)((char*)mix + 8);
    }
    return 0;
}

// 0x801BC984 - 20 bytes
// NON_MATCHING: original uses xori+subfic+adde
int INGTarget::is_group_meal() const {
    return (m_mealType == 2) ? 1 : 0;
}

// 0x801BC998 - 16 bytes
int INGTarget::RCPOnCancel() {
    m_rcpState = 2;
    return 1;
}

// 0x801BCA10 - 44 bytes
void INGTarget::exit_ingredients_dialog_selection_callback(int sel) {
    if (sel == 0) {
        INGTarget_exitImpl(this, 0);
    }
}

// ============================================================================
// ITBTarget
// ============================================================================

// 0x801BD870 - 12 bytes
void ITBTarget::ShowIntroThoughtBalloon() {
    m_showBalloon = 1;
}

// 0x801BD87C - 12 bytes
void ITBTarget::HideIntroThoughtBalloon() {
    m_showBalloon = 0;
}

// 0x801BD8F4 - 8 bytes
int ITBTarget::IsIntroThoughtBalloonActive() {
    return m_isActive;
}

// 0x801BDA50 - 8 bytes
float ITBTarget::GetUserReadTime() {
    return m_userReadTime;
}

// ============================================================================
// K2YTarget
// ============================================================================

// 0x801BE548 - 36 bytes
// NON_MATCHING: original uses cror/mfcr pattern for range check
int K2YTarget::IsModeValid() {
    int mode = s_k2yMode;
    if (mode > 8) return 0;
    if (mode >= 2) return 1;
    return 0;
}

// 0x801E7098 - 8 bytes
int K2YTarget::GetMode() {
    return s_k2yMode;
}

// 0x801E70A0 - 12 bytes
unsigned short* K2YTarget::GetSavedFirstName() {
    return s_savedFirstName;
}

// 0x801E70AC - 12 bytes
unsigned short* K2YTarget::GetSavedLastName() {
    return s_savedLastName;
}

// ============================================================================
// M2MTarget
// ============================================================================

// 0x801C0C9C - 4 bytes
void M2MTarget::ZeroInputCallback() {
}

// 0x801C1094 - 52 bytes
void M2MTarget::OnSlotSelectItemSelected(int slot, int& result) {
    if (result.m_field00 == 255) {
        result.m_field00 = slot;
        result.m_field04 = -1;
        return;
    }
    if (result.m_field04 == 255) return;
    result.m_field04 = ~slot;
}

// 0x801C10C8 - 64 bytes
int M2MTarget::OnGetNumItems(int& result) {
    if (result.m_field00 == 255) return 2;
    if (result.m_field04 == 255) return 8;
    if (result.m_field08 != 0) return 0;
    return 4;
}

// 0x801C1108 - 8 bytes
int M2MTarget::GetDevice() {
    return m_device;
}

// 0x801C1110 - 44 bytes
// NON_MATCHING: stores device, calls AptSetVarImpl
void M2MTarget::SetDevice(int device) {
    m_device = device;
    AptSetVarImpl((const char*)0x803F21BC);
}

// 0x801C113C - 8 bytes
int M2MTarget::GetSaveGameID() {
    return m_saveGameID;
}

// 0x801C1144 - 24 bytes
int M2MTarget::GetMemCardPort() {
    int dev = m_device;
    if (dev != -1) return dev;
    return m_saveGameID;
}

// 0x801C1D00 - 8 bytes
int M2MTarget::IsItemEnabledSaveGameSelect(int) {
    return 0;
}

// 0x801E7090 - 8 bytes
int M2MTarget::GetPlayerNum() {
    return m_playerNum;
}

// ============================================================================
// MDITarget
// ============================================================================

// 0x801C3C84 - 12 bytes
void MDITarget::ShowModelessDialog() {
    m_showDialog = 1;
}

// 0x801C3C90 - 12 bytes
void MDITarget::HideModelessDialog() {
    m_showDialog = 0;
}

// 0x801C3C9C - 4 bytes
void MDITarget::UpdateModelessDialogs() {
}

// 0x801C3CA0 - 8 bytes
int MDITarget::IsModelessDialogActive() {
    return m_isActive;
}

// 0x801C3DF0 - 8 bytes
int MDITarget::CountModelessDialogs() {
    return m_dialogCount;
}

// 0x801C3EC4 - 32 bytes
void MDITarget::CleanupModelessDialogs() {
    MDITarget_CleanupImpl(this);
}

// ============================================================================
// MMUTarget
// ============================================================================

// 0x801C59E0 - 8 bytes
MMUTarget* MMUTarget::GetSingleton() {
    return s_mmuSingleton;
}

// 0x801C59E8 - 12 bytes
void MMUTarget::OnCreditsClose() {
    m_creditsClose = 1;
}

// 0x801C6F84 - 32 bytes
void MMUTarget::OnLeftKeyPressed(char*, char*) {
    MMUTarget_DecrementChoice(this);
}

// 0x801C6FA4 - 32 bytes
void MMUTarget::OnRightKeyPressed(char*, char*) {
    MMUTarget_IncrementChoice(this);
}

// 0x801C7938 - 32 bytes
void MMUTarget::OnTopLevelChoiceChange() {
    MMUTarget_OnChoiceChange(this);
}

// 0x801C7958 - 32 bytes
void MMUTarget::OnGameplayLevelChoiceChange() {
    MMUTarget_OnChoiceChange(this);
}

// 0x801C7978 - 32 bytes
void MMUTarget::OnNumberOfPlayersChoiceChange() {
    MMUTarget_OnChoiceChange(this);
}

// 0x801C86B4 - 16 bytes
void MMUTarget::ChangeScreenMode(MMU_MODE mode) {
    int old = m_curMode;
    m_curMode = (int)mode;
    m_prevMode = old;
}

// 0x801C8788 - 4 bytes
void MMUTarget::OnCancelDialog() {
}

// 0x801C878C - 4 bytes
void MMUTarget::OnDialog2Close(int) {
}

// 0x801C8790 - 4 bytes
void MMUTarget::OnCancelDialog2() {
}

// 0x801E7078 - 8 bytes
int MMUTarget::GetCurrentMainScreenChoice() const {
    return m_mainScreenChoice;
}

// 0x801E7080 - 8 bytes
int MMUTarget::GetCurrentGameplayChoice() const {
    return m_gameplayChoice;
}

// ============================================================================
// MODTarget
// ============================================================================

// 0x801C9AE4 - 12 bytes
void MODTarget::ShowMood() {
    m_showMood = 1;
}

// 0x801C9AF0 - 12 bytes
void MODTarget::HideMood() {
    m_showMood = 0;
}

// 0x801C9C84 - 8 bytes
int MODTarget::IsMoodActive() {
    return m_isActive;
}

// 0x801CAAB4 - 8 bytes
void MODTarget::SetTextButtonPressed(bool pressed) {
    m_textButtonPressed = (int)pressed;
}

// ============================================================================
// MOTTarget
// ============================================================================

// 0x801CBB58 - 12 bytes
void MOTTarget::ShowMotives() {
    m_showMotives = 1;
}

// 0x801CBB64 - 16 bytes
void MOTTarget::HideMotives() {
    m_textButtonPressed = 0;
    m_showMotives = 0;
}

// 0x801CBB74 - 4 bytes
void MOTTarget::UpdateMotives() {
}

// 0x801CBFC0 - 8 bytes
int MOTTarget::IsMotivesActive() {
    return m_isActive;
}

// 0x801CC2A0 - 12 bytes
void MOTTarget::SelectedPersonChanged(cXPerson*) {
    m_personChanged = 1;
}

// 0x801CC2AC - 8 bytes
void MOTTarget::SetTextButtonPressed(bool pressed) {
    m_textButtonPressed = (int)pressed;
}

// ============================================================================
// O2TTarget
// ============================================================================

// 0x801CEA60 - 20 bytes
void O2TTarget::SaveGame(char*, char*) {
    m_dialogState = 0;
    m_showOptions = 1;
}

// 0x801CEF60 - 44 bytes
void O2TTarget::RememberAudioOptions() {
    char* audio = (char*)g_audioManager;
    // Offsets: SFX=41, Music=40, Ambient=28, Voice=29
    *(char*)((char*)&s_e2eCurrentHue + 0) = *(audio + 41);  // approximate
    // NON_MATCHING: stores bytes to r13-relative addresses
    // The exact r13 offsets are m_CurrentSFXVolume, m_CurrentMusicVolume, etc.
}

// 0x801CF028 - 44 bytes
// NON_MATCHING: loads from audio manager, stores to r13-relative
void O2TTarget::RememberGameOptions() {
    // Loads several fields from audio manager global and stores to static vars
}

// 0x801CF054 - 60 bytes
// NON_MATCHING: restores game options from static vars
void O2TTarget::RestoreGameOptions() {
    // Restores game options that were saved by RememberGameOptions
}

// 0x801CFA60 - 12 bytes
void O2TTarget::OnCancelDialog() {
    m_dialogState = 0;
}

// 0x801D00C0 - 40 bytes
void O2TTarget::QuitGame(char*, char*) {
    m_dialogState = 1;
    O2TTarget_QuitImpl(this);
}

// ============================================================================
// PAZBase
// ============================================================================

// 0x801D0B64 - 4 bytes
void PAZBase::Update() {
}

// 0x801D0B68 - 8 bytes
int PAZBase::GetPausePlayer() {
    return m_pausePlayer;
}

// 0x801D0B70 - 4 bytes
void PAZBase::UpdateButtonVisibility() {
}

// ============================================================================
// PAZTarget / PZ1Target
// ============================================================================

// 0x801D1510 - 52 bytes
// NON_MATCHING: stores vtable pointer, saves field, calls destroy impl
PAZTarget::~PAZTarget() {
    // Sets vtable to PAZTarget vtable
    // Saves m_field8C to r13-relative static
    // Calls PAZBase_DestroyImpl
    PAZBase_DestroyImpl(this);
}

// 0x801E70B8 - 12 bytes
const char* PAZTarget::GetTLA() const {
    return s_pazTLA;
}

// 0x801E70C4 - 12 bytes
const char* PZ1Target::GetTLA() const {
    return s_pz1TLA;
}

// ============================================================================
// PCTTarget
// ============================================================================

// 0x801D1E40 - 48 bytes
void PCTTarget::static_GrabManipulatorCallback(int* data) {
    void* userData = data->m_userData;
    if (userData != 0) {
        PCTTarget_GrabCallback(userData, data);
    }
}

// 0x801D1E70 - 48 bytes
void PCTTarget::static_PlaceModeCallback(int* data) {
    void* userData = data->m_userData;
    if (userData != 0) {
        PCTTarget_PlaceCallback(userData, data);
    }
}

// 0x801D1EA0 - 48 bytes
void PCTTarget::static_WallManipulatorCallback(int* data) {
    void* userData = data->m_userData;
    if (userData != 0) {
        PCTTarget_WallManipCallback(userData, data);
    }
}

// 0x801D1ED0 - 48 bytes
void PCTTarget::static_WallPainterCallback(int* data) {
    void* userData = data->m_userData;
    if (userData != 0) {
        PCTTarget_WallPaintCallback(userData, data);
    }
}

// 0x801D1F00 - 48 bytes
void PCTTarget::static_FloorPainterCallback(int* data) {
    void* userData = data->m_userData;
    if (userData != 0) {
        PCTTarget_FloorCallback(userData, data);
    }
}

// 0x801D1F30 - 36 bytes
PCTTarget::cCellInfo::cCellInfo() {
    m_field14 = 0;
    m_field00 = 0;
    m_field04 = 0;
    m_field08 = 0;
    m_field0C = 0;
    m_field10 = 0;
}

// 0x801D49A4 - 44 bytes
void PCTTarget::Draw(ERC*) {
    void* callback = m_drawCallback;
    if (callback != 0) {
        G2DTarget_RenderCallback(callback);
    }
}

// 0x801D49D0 - 16 bytes
unsigned int PCTTarget::get_cell_info_array_index(unsigned int col) const {
    return m_gridPage * 6 + col;
}

// 0x801D4F88 - 64 bytes
// NON_MATCHING: checks null, then g_buildModeFlag, then byte at offset 16
int filter_wallpaper(WallTile* tile) {
    if (tile == 0) return 0;
    if (g_buildModeFlag != 0) return 1;
    if (*(char*)((char*)tile + 16) != 0) return 1;
    return 0;
}

// 0x801D613C - 8 bytes
int PCTTarget::get_motive_rating_label(unsigned int, unsigned short*) const {
    return 1;
}

// 0x801D61AC - 8 bytes
int PCTTarget::refresh_text_field(char*, unsigned int) {
    return 1;
}

// 0x801D61B4 - 8 bytes
int PCTTarget::set_control_visible(char*, bool) {
    return 1;
}

// 0x801D6DE0 - 12 bytes
void PCTTarget::buy_fail_dialog_selection_callback(int) {
    m_dialogState = 0;
}

// 0x801D8750 - 12 bytes
void PCTTarget::ZeroInputCallback() {
    m_dialogState = 0;
}

// 0x801D875C - 12 bytes
void PCTTarget::DialogClosedCallback() {
    m_dialogState = 0;
}

// ============================================================================
// PRGTarget
// ============================================================================

// 0x801DA620 - 4 bytes
void PRGTarget::UpdateShaders() {
}

// ============================================================================
// R2LTarget
// ============================================================================

// 0x801DBB98 - 4 bytes
void R2LTarget::Update() {
}

// 0x801DCD68 - 32 bytes
int R2LTarget::RecordIndexToGridIndex(int index) {
    int pageStart = m_currentPage * 6;
    int gridIdx = index - pageStart;
    if ((unsigned)gridIdx > 6u) return -1;
    return gridIdx;
}

// 0x801DCD88 - 44 bytes
int R2LTarget::GridIndexToRecordIndex(int index) {
    int pageStart = m_currentPage * 6;
    int recordIdx = index + pageStart;
    if (recordIdx < 0) return -1;
    if (recordIdx >= m_totalRecords) return -1;
    return recordIdx;
}

// 0x801DCDB4 - 52 bytes
int R2LTarget::OldGridIndexToRecordIndex(int index) {
    int oldPage = m_oldPage;
    int pageStart = oldPage * 6;
    int recordIdx = index + pageStart;
    if (oldPage < 0) return -1;
    if (recordIdx < 0) return -1;
    if (recordIdx >= m_totalRecords) return -1;
    return recordIdx;
}

// 0x801DCDE8 - 24 bytes
int R2LTarget::ScrollLeftEnabled() {
    if (m_currentPage > 0) return 1;
    return 0;
}

// 0x801DCE00 - 40 bytes
int R2LTarget::ScrollRightEnabled() {
    int nextPageStart = (m_currentPage + 1) * 6;
    int remaining = m_totalRecords - nextPageStart;
    if (remaining > 0) return 1;
    return 0;
}

// 0x801DCE28 - 4 bytes
void R2LTarget::onHelpDialogSelection(int) {
}

// 0x801DCE78 - 12 bytes
void R2LTarget::onSummaryDialogZeroInputCallback() {
    m_summaryDialogState = 0;
}

// 0x801DCE84 - 12 bytes
void R2LTarget::onSummaryDialogDialogClosedCallback() {
    m_summaryDialogState = 0;
}

// ============================================================================
// RCPTarget
// ============================================================================

// 0x801DE534 - 4 bytes
void RCPTarget::Draw(ERC*) {
}

// ============================================================================
// SKLTarget
// ============================================================================

// 0x801E1628 - 12 bytes
void SKLTarget::ShowSkills() {
    m_showSkills = 1;
}

// 0x801E1634 - 16 bytes
void SKLTarget::HideSkills() {
    m_textButtonPressed = 0;
    m_showSkills = 0;
}

// 0x801E19BC - 8 bytes
int SKLTarget::IsSkillsActive() {
    return m_isActive;
}

// 0x801E19C4 - 8 bytes
void SKLTarget::SetTextButtonPressed(bool pressed) {
    m_textButtonPressed = (int)pressed;
}

// ============================================================================
// WAFTarget
// ============================================================================

// 0x801E3574 - 12 bytes
void WAFTarget::ShowWantsAndFears() {
    m_showWAF = 1;
}

// 0x801E3580 - 16 bytes
void WAFTarget::HideWantsAndFears() {
    m_textButtonPressed = 0;
    m_showWAF = 0;
}

// 0x801E38F8 - 8 bytes
int WAFTarget::IsWantsAndFearsActive() {
    return m_isActive;
}

// 0x801E4A00 - 12 bytes
void WAFTarget::OnGlowEffectComplete() {
    m_glowEffectActive = 0;
}

// 0x801E4F24 - 8 bytes
void WAFTarget::SetTextButtonPressed(bool pressed) {
    m_textButtonPressed = (int)pressed;
}

// ============================================================================
// WXFTarget
// ============================================================================

// 0x801E62E8 - 4 bytes
void WXFTarget::Update() {
}

// 0x801E6DF0 - 64 bytes
void WXFTarget::onHelpDialogSelection(int) {
    m_helpState++;
    if ((unsigned)m_helpState > 2u) {
        m_helpState = 0;
    } else {
        WXFTarget_UpdateHelpState(this);
    }
}

// ============================================================================
// Free functions
// ============================================================================

// 0x801D1A08 - 8 bytes
int DumpObjectFolder(char*) {
    return 0;
}

// 0x801D1A90 - 64 bytes
// NON_MATCHING: chain of null checks loading nested pointers
int GetResDataFromSelector(ObjSelector* selector) {
    void* p = (void*)GetResDataFromSelectorImpl(selector);
    if (p == 0) return 0;
    void* q = *(void**)((char*)p + 56);
    if (q == 0) return 0;
    return *(int*)((char*)q + 192);
}

// 0x801D1AD0 - 44 bytes
int IsSkillCatalogRating(int rating) {
    if (rating < 0) return 1;
    if (rating <= 6) return 0;
    if (rating <= 13) return 1;
    return 1;
}

// ============================================================================
// __static_initialization_and_destruction_0
// ============================================================================

// 0x801E6F08 - 36 bytes
// NON_MATCHING: compiler-generated static init guard
static void __static_initialization_and_destruction_0(int initialize, int priority) {
    if (priority != 0xFFFF) return;
    if (initialize == 0) return;
    s_staticInitVal = 17;
}

// 0x801E70D0 - 44 bytes
// Global constructor that calls __static_initialization_and_destruction_0
static void _GLOBAL__I_ACTTarget() {
    __static_initialization_and_destruction_0(1, 0xFFFF);
}

// ============================================================================
// _String_base<wchar_t>::_M_throw_length_error (from .data section)
// ============================================================================

// 0x803B50F8 - 28 bytes
// NON_MATCHING: calls two exception functions, never returns
// This is a wchar_t string length error thrower

// ============================================================================
// InteractorModule Params destructors (from .data section)
// These all follow the same pattern: set vtable, conditionally delete
// ============================================================================

// 0x803B95AC - 52 bytes
// NON_MATCHING: sets vtable pointer, conditionally calls operator delete
InteractorModule::GrabManipulator::GrabManipulatorParams::~GrabManipulatorParams() {
    // vtable = InteractorModule::Interactor::InteractorParams vtable
    if (0) { // conditional on r4 & 1 (second hidden param)
        operator_delete_impl(this);
    }
}

// 0x803B95E0 - 52 bytes
InteractorModule::PlaceManipulator::PlaceManipulatorParams::~PlaceManipulatorParams() {
    if (0) {
        operator_delete_impl(this);
    }
}

// 0x803B9614 - 52 bytes
InteractorModule::FloorPainter::FloorPainterParams::~FloorPainterParams() {
    if (0) {
        operator_delete_impl(this);
    }
}

// 0x803B9648 - 52 bytes
InteractorModule::WallManipulator::WallManipulatorParams::~WallManipulatorParams() {
    if (0) {
        operator_delete_impl(this);
    }
}

// 0x803B967C - 52 bytes
InteractorModule::WallPainter::WallPainterParams::~WallPainterParams() {
    if (0) {
        operator_delete_impl(this);
    }
}
