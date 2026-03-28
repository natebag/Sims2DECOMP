// targets.cpp - UI Target small functions (<=64 bytes)
// From: targets_cas.obj (~35 small functions) + targets_s2c.obj (~190 small functions)
// Combined into one translation unit for the decomp

#include "ui/targets.h"

// ============================================================================
// Extern globals (SDA / r13-relative)
// ============================================================================
extern "C" {
    extern int s_g2dInitComplete;      // r13 - 30368 (0x8960)
    extern int s_mmuSingleton;         // r13 - 30180 (0x8A1C) (actually a pointer)
    extern int s_k2yMode;              // r13 - 30256 (0x89D0)
    extern int s_casLotData;           // r13 - 32056 (0x82C8) (pointer)
    extern int s_ingRefrigeratorLevel; // r13 - 30260 (0x89CC)
    extern int s_isGenerating;         // r13 - 31440 (0x8530)
    extern int s_staticInitVal;        // r13 - 23852 (0xA2D4)
}

// External data addresses
extern unsigned short s_savedFirstName[];  // at 0x8050C0E4
extern unsigned short s_savedLastName[];   // at 0x8050C124
extern const char s_pazTLA[];              // at 0x803F3F54
extern const char s_pz1TLA[];             // at 0x803F3F5C

// External functions
extern void MDITarget_CleanupImpl(void* self);  // at 0x801C3DF8
extern void CASTarget_GotoBaseImpl(void* self, int param); // at 0x80194DA4
extern void CASSelectionTarget_ClearTexturesRange(void* self, int start, int end); // at 0x8019A4B0

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
    // Empty function
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
    // Empty function
}

// 0x801A4F80 - 4 bytes
void CRDTarget::UpdateCredits() {
    // Empty function
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
    // Empty function
}

// 0x801AA57C - 4 bytes
void CSPTarget::onHelpDialogSelection(int) {
    // Empty function
}

// ============================================================================
// E2ETarget
// ============================================================================

// 0x801E7088 - 8 bytes
int E2ETarget::GetTopLevelState() {
    return m_topLevelState;
}

// ============================================================================
// FAMTarget
// ============================================================================

// 0x801B070C - 4 bytes
void FAMTarget::Shutdown() {
    // Empty function
}

// 0x801B0710 - 4 bytes
void FAMTarget::Update() {
    // Empty function
}

// 0x801B0750 - 12 bytes
// NON_MATCHING: original has stwu r1,-32(r1); addi r1,r1,32; blr (dummy stack frame)
// Compiler optimizes out the no-op stack frame, producing just blr
void FAMTarget::UpdateText() {
    // Empty function - original allocates and frees 32-byte stack frame
}

// 0x801B075C - 4 bytes
void FAMTarget::OnLeftKeyPressed(char*, char*) {
    // Empty function
}

// 0x801B0760 - 4 bytes
void FAMTarget::OnRightKeyPressed(char*, char*) {
    // Empty function
}

// 0x801B0DAC - 8 bytes
int FAMTarget::ConvertSelectedFamilyIndexToActualGameIndex(int index) {
    return index + 20;
}

// 0x801B0E6C - 4 bytes
void FAMTarget::OnCancelDialog() {
    // Empty function
}

// 0x801B2604 - 4 bytes
void FAMTarget::OnCircleKeyPressed(char*, char*) {
    // Empty function
}

// 0x801B29F0 - 8 bytes
int FAMTarget::ConvertSelectedLotIndexToActualGameIndex(int index) {
    return index + 13;
}

// ============================================================================
// FCMTarget
// ============================================================================

// 0x801B41B8 - 12 bytes
void FCMTarget::HideFireCodeMeter() {
    m_showMeter = 0;
}

// 0x801B4458 - 8 bytes
int FCMTarget::IsFireCodeMeterActive() {
    return m_isActive;
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

// 0x801E7050 - 8 bytes
int G2DTarget::IsInitComplete() {
    return s_g2dInitComplete;
}

// 0x801E7058 - 32 bytes
// NON_MATCHING: original uses beqlr (conditional return), compiler generates branchless arithmetic
int G2DTarget::HasPendingTransition() {
    int state = m_transitionState;
    if (state == 0) return 0;
    if (state == 3) return 0;
    return 1;
}

// ============================================================================
// H2DTarget
// ============================================================================

// 0x801B8480 - 4 bytes
void H2DTarget::Draw(ERC*) {
    // Empty function
}

// 0x801B8A38 - 8 bytes
int H2DTarget::GetPausePlayer() {
    return m_pausePlayer;
}

// 0x801B90C0 - 12 bytes
void H2DTarget::RewardMomentDialogClosed() {
    m_rewardClosed = 1;
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

// 0x801BBE14 - 12 bytes
u32 INGTarget::get_blank_shader_id() const {
    return 0x9F93FF74u;
}

// 0x801BC984 - 20 bytes
// NON_MATCHING: original uses xori+subfic+adde, compiler generates cntlzw+srwi
int INGTarget::is_group_meal() const {
    return (m_mealType == 2) ? 1 : 0;
}

// 0x801BC998 - 16 bytes
int INGTarget::RCPOnCancel() {
    m_rcpState = 2;
    return 1;
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
    // Empty function
}

// 0x801C1108 - 8 bytes
int M2MTarget::GetDevice() {
    return m_device;
}

// 0x801C113C - 8 bytes
int M2MTarget::GetSaveGameID() {
    return m_saveGameID;
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
    // Empty function
}

// 0x801C3CA0 - 8 bytes
int MDITarget::IsModelessDialogActive() {
    return m_isActive;
}

// 0x801C3DF0 - 8 bytes
int MDITarget::CountModelessDialogs() {
    return m_dialogCount;
}

// ============================================================================
// MMUTarget
// ============================================================================

// 0x801C59E0 - 8 bytes
MMUTarget* MMUTarget::GetSingleton() {
    return (MMUTarget*)s_mmuSingleton;
}

// 0x801C59E8 - 12 bytes
void MMUTarget::OnCreditsClose() {
    m_creditsClose = 1;
}

// 0x801C86B4 - 16 bytes
void MMUTarget::ChangeScreenMode(MMU_MODE mode) {
    int old = m_curMode;
    m_curMode = (int)mode;
    m_prevMode = old;
}

// 0x801C8788 - 4 bytes
void MMUTarget::OnCancelDialog() {
    // Empty function
}

// 0x801C878C - 4 bytes
void MMUTarget::OnDialog2Close(int) {
    // Empty function
}

// 0x801C8790 - 4 bytes
void MMUTarget::OnCancelDialog2() {
    // Empty function
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
    // Empty function
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
// PAZBase
// ============================================================================

// 0x801D0B64 - 4 bytes
void PAZBase::Update() {
    // Empty function
}

// 0x801D0B68 - 8 bytes
int PAZBase::GetPausePlayer() {
    return m_pausePlayer;
}

// 0x801D0B70 - 4 bytes
void PAZBase::UpdateButtonVisibility() {
    // Empty function
}

// ============================================================================
// PAZTarget / PZ1Target - GetTLA
// ============================================================================

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

// 0x801D49D0 - 16 bytes
unsigned int PCTTarget::get_cell_info_array_index(unsigned int col) const {
    return m_gridPage * 6 + col;
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
    // Empty function
}

// ============================================================================
// R2LTarget
// ============================================================================

// 0x801DBB98 - 4 bytes
void R2LTarget::Update() {
    // Empty function
}

// 0x801DCE28 - 4 bytes
void R2LTarget::onHelpDialogSelection(int) {
    // Empty function
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
    // Empty function
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
    // Empty function
}

// ============================================================================
// UIDialog
// ============================================================================

// 0x801E7044 - 4 bytes
void UIDialog::SelectionCallback(int) {
    // Empty function
}

// 0x801E7048 - 4 bytes
void UIDialog::ZeroInputCallback() {
    // Empty function
}

// 0x801E704C - 4 bytes
void UIDialog::DialogClosedCallback() {
    // Empty function
}

// ============================================================================
// Free functions
// ============================================================================

// 0x801A7B28 - 12 bytes (in targets_s2c)
u32 get_blank_shader_id() {
    return 0x9F93FF74u;
}

// 0x801C1D00 - 8 bytes
// Always returns 0 (all items disabled by default?)
int M2MTarget::IsItemEnabledSaveGameSelect(int) {
    return 0;
}

// 0x801CFA60 - 12 bytes
void O2TTarget::OnCancelDialog() {
    *(int*)((char*)this + 0x250) = 0;
}

// 0x801CEA60 - 20 bytes
void O2TTarget::SaveGame(char*, char*) {
    *(int*)((char*)this + 0x250) = 0;
    *(int*)((char*)this + 0x90) = 1;
}

// 0x801C1144 - 24 bytes
// NON_MATCHING: original uses bnelr conditional return
int M2MTarget::GetMemCardPort() {
    int device = m_device;
    if (device != -1) return device;
    return m_saveGameID;
}

// 0x801C86B4 - 16 bytes (already defined above, removing duplicate declaration)

// ============================================================================
// R2LTarget extended functions
// ============================================================================

// 0x801DCDE8 - 24 bytes
// NON_MATCHING: original uses bgtlr conditional return
int R2LTarget::ScrollLeftEnabled() {
    int page = *(int*)((char*)this + 0xA4);
    if (page > 0) return 1;
    return 0;
}

// ============================================================================
// PCTTarget::cCellInfo
// ============================================================================

// 0x801D1F30 - 36 bytes
// NON_MATCHING: store order may differ (original stores offset 0x14 first)
PCTTarget::cCellInfo::cCellInfo() {
    int* p = (int*)this;
    p[5] = 0;  // 0x14
    p[0] = 0;  // 0x00
    p[1] = 0;  // 0x04
    p[2] = 0;  // 0x08
    p[3] = 0;  // 0x0C
    p[4] = 0;  // 0x10
}

// ============================================================================
// INGTarget::TabInfo - store order fix
// ============================================================================
// Note: TabInfo::TabInfo is already defined above but original has store order: 0x08, 0x00, sth 0x04

// 0x801D1A08 - 8 bytes
int DumpObjectFolder(char*) {
    return 0;
}

// ============================================================================
// targets_cas functions
// ============================================================================

// 0x801960F4 - 4 bytes
void CASTarget::DialogNoSelectionCallback() {
    // Empty function
}

// 0x80196A50 - 4 bytes
void CASBodyTarget::SetVariable(char*, char*) {
    // Empty function
}

// 0x8019B3F4 - 4 bytes
void CASFashionTarget::RandomizeFashion() {
    // Empty function
}

// 0x8019B3F8 - 12 bytes
void CASFashionTarget::HandleEventChangeFocus(CasEventChangeFocus& event) {
    m_focusValue = *(int*)((char*)&event + 0x14);
}

// 0x8019C1B0 - 4 bytes
void CASMiscTarget::SetVariable(char*, char*) {
    // Empty function
}

// 0x8019D50C - 12 bytes
void CASMorphTarget::ExitMorphScreenDone() {
    m_exitMorphDone = 0;
}

// 0x8019F1DC - 16 bytes
signed char CASPersonalTarget::GetSavedPersVal(signed char index) {
    return *((signed char*)this + 0x8C + (unsigned char)index);
}

// 0x801A07F8 - 8 bytes
int CASTarget::IsShuttingdown() {
    return m_isShuttingDown;
}

// 0x801A0800 - 8 bytes
int CASTarget::GetPrevUIFocus() {
    return m_prevUIFocus;
}

// 0x801A0808 - 8 bytes
int CASTarget::GetCurPartUIFocus() {
    return m_curPartUIFocus;
}

// 0x801A0810 - 8 bytes
int CASTarget::GetCurrentSimNumber() {
    return m_currentSimNumber;
}

// 0x80194EBC - 8 bytes
void CASTarget::SetHandleInput(bool handle) {
    m_handleInput = (int)handle;
}

// 0x801A08A8 - 8 bytes
void* CASTarget::GetGeneticsTarget() {
    return (void*)m_geneticsTarget;
}

// 0x801A08B0 - 8 bytes
void* CASTarget::GetNPCEditor() {
    return (void*)m_npcEditor;
}

// 0x801A0818 - 40 bytes
// NON_MATCHING: original uses signed division pattern (bge/addi for negative), compiler may differ
int CASTarget::HasSimInSlot(int slot) const {
    return (m_simSlotBits >> (slot & 3)) & 1;
}

// 0x801A0890 - 24 bytes
// NON_MATCHING: compiler may generate different multiply sequence
// Original: slwi r9,r4,3; add r9,r9,r4; slwi r9,r9,6; addi r9,r9,0xA48; add r3,r3,r9
// This computes offset = simIndex * 576 + 0xA48 (simIndex * 8 + simIndex = 9*simIndex, then *64 = 576)
void* CASTarget::GetSimRenderer(int simIndex) {
    return (void*)((char*)this + simIndex * 576 + 0xA48);
}

// 0x801A08B8 - 8 bytes
void* CASGeneticsTarget::GetCasGenetics() {
    return m_casGenetics;
}

// 0x801A0934 - 8 bytes
int CASRoommateTarget::GetSelectedSlot() const {
    return m_selectedSlot;
}

// 0x801A08C0 - 40 bytes
void CASGeneticsTarget::SetWarnOnGenerate(bool warn) {
    if (warn) {
        m_flags |= 0x20;
    } else {
        m_flags &= ~0x20;
    }
}

// 0x801A08E8 - 12 bytes
int CASGeneticsTarget::GetWarnOnGenerate() {
    return (m_flags >> 5) & 1;
}

// 0x801A08F4 - 40 bytes
void CASGeneticsTarget::SetGenerateDefaultSim(bool generate) {
    if (generate) {
        m_flags |= 0x10;
    } else {
        m_flags &= ~0x10;
    }
}

// 0x801A091C - 24 bytes
// NON_MATCHING: original uses beqlr/bnelr conditional returns, compiler generates branchless
int CASGeneticsTarget::IsGenerating() {
    if (s_isGenerating != 0) {
        return 1;
    }
    return 0;
}

// 0x80199E5C - 20 bytes
// NON_MATCHING: compiler rearranges arithmetic (addi -2 then slwi vs original slwi then addi -8)
unsigned int CASSelectionTarget::ConvertGridIdxToOptionIdx(unsigned int gridIdx) {
    return gridIdx + (m_gridColumns * 4 - 8);
}

// 0x80196364 - 20 bytes
// NON_MATCHING: original uses xori+subfic+adde, compiler generates cntlzw+srwi
int CASTarget::IsViewingCAR() {
    return (m_cfcMode == 3) ? 1 : 0;
}

// 0x80195C1C - 36 bytes
// NON_MATCHING: original uses beqlr for inner comparison, compiler generates xori+cntlzw+srwi
int CASTarget::CFCShouldGotoBodyScreenNext() {
    if (m_cfcMode == 0) {
        if (m_curPartUIFocus == 19) {
            return 1;
        }
    }
    return 0;
}

// 0x8019314C - 40 bytes
// NON_MATCHING - static function, accesses r13-relative global
int CASTarget::GetLotNumberFromMode(int mode) {
    if (mode >= 1 && mode <= 5) {
        int* lotData = (int*)s_casLotData;
        return lotData[9] + 1;  // offset 0x24 = 36/4 = index 9
    }
    return 9;
}
