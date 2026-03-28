#if 0 // SKIP
// mustates.cpp - MU (Memory Unit) state machine states
// From: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\mustates.obj
// 70 small functions (<=64 bytes) decompiled

#include "core/mustates.h"

// ============================================================================
// Extern declarations for functions/globals referenced
// ============================================================================

// r13-relative globals (SDA)
extern "C" {
    extern int s_threadPollComplete;    // r13 - 24652 (0x9FB4)
    extern int s_threadExecResult;      // r13 - 24648 (0x9FB8)
    extern int s_autoSaveFlag;          // r13 - 24656 (0x9FB0)
    extern int s_curRequest;            // r13 - 21368 (0xAC88)
    extern int s_curResult;             // r13 - 21364 (0xAC8C)
    extern int s_requestResult;         // r13 - 21372 (0xAC84)
    extern int s_houseNumber;           // r13 - 21360 (0xAC90)
    extern int s_drawEnabled;           // at 0x80475C0C (lis r9,-32697; lwz r0,23564(r9))
}

// External function prototypes
extern "C" {
    int MUWrapper_SaveNewGame(void* wrapper);  // at 0x800756DC
    void MUWrapper_LoadConfig(void* wrapper);  // at 0x80075548
}

// Forward declarations for external calls
void StateMachine_SetState(void* sm, int state);        // at 0x80095DFC
void StateMachine_UpdateCurrentState(void* sm);         // at 0x80095B30
void StateMachine_DrawCurrentState(void* sm);           // at 0x80095D08
void MUStateMachine_MUWrapperShutdown_impl(MUStateMachine*); // at 0x80093958
void StateMachine_ShutdownStates(void* sm);             // at 0x80096514
void StateMachine_Shutdown_impl(void* sm);              // at 0x80096080
void AptDisplay_UnloadActiveMovie(void* aptDisplay);    // at 0x80086988
void AptDisplay_Show(void* aptDisplay);                 // at 0x8007F8F8

// External data
extern void* s_pMUWrapperData; // at 0x804858D8

// ============================================================================
// Thread polling functions
// ============================================================================

// 0x80091654 - 8 bytes
int THREADPOLL_MU_IsComplete(void) {
    return s_threadPollComplete;
}

// 0x8009165C - 12 bytes
void THREADPOLL_MU_Start(void) {
    s_threadPollComplete = 0;
}

// 0x80091668 - 12 bytes
void THREADPOLL_MU_End(void) {
    s_threadPollComplete = 1;
}

// ============================================================================
// MUStatesLoadGame
// ============================================================================

// 0x80091B78 - 12 bytes
void MUStatesLoadGame::Reset() {
    ((MUStateBase*)this)->m_field1C = 0;
}

// 0x80091B84 - 4 bytes
void MUStatesLoadGame::Draw(ERC*) {
    // Empty function - just blr
}

// ============================================================================
// MUStatesLoadHouse
// ============================================================================

// 0x8009200C - 12 bytes
void MUStatesLoadHouse::Reset() {
    ((MUStateBase*)this)->m_field1C = 0;
}

// 0x80092018 - 4 bytes
void MUStatesLoadHouse::Draw(ERC*) {
    // Empty function - just blr
}

// ============================================================================
// MUStatesSaveNewGame
// ============================================================================

// 0x800922DC - 24 bytes
void MUStatesSaveNewGame::Reset() {
    MUStateBase* base = (MUStateBase*)this;
    base->m_field2C = 0;
    base->m_field1C = 0;
    base->m_field20 = 0;
    base->m_field28 = 0;
}

// ============================================================================
// MUStatesAutoSaveExisting
// ============================================================================

// 0x80092988 - 16 bytes
void MUStatesAutoSaveExisting::Reset() {
    s_autoSaveFlag = 0;
    ((MUStateBase*)this)->m_field20 = 0;
}

// ============================================================================
// MUStatesSaveExistingGame
// ============================================================================

// 0x80092B08 - 12 bytes
void MUStatesSaveExistingGame::Reset() {
    ((MUStateBase*)this)->m_field1C = 0;
}

// 0x80092B14 - 4 bytes
void MUStatesSaveExistingGame::Draw(ERC*) {
    // Empty function - just blr
}

// ============================================================================
// MUStatesTransitionAutoSaveExisting
// ============================================================================

// 0x80092D44 - 16 bytes
void MUStatesTransitionAutoSaveExisting::Reset() {
    s_autoSaveFlag = 0;
    ((MUStateBase*)this)->m_field20 = 0;
}

// ============================================================================
// MUStatesTransitionSaveExistingGame
// ============================================================================

// 0x80092ED8 - 12 bytes
void MUStatesTransitionSaveExistingGame::Reset() {
    ((MUStateBase*)this)->m_field1C = 0;
}

// ============================================================================
// MUStatesLoadConfig
// ============================================================================

// 0x80093118 - 12 bytes
void MUStatesLoadConfig::Reset() {
    ((MUStateBase*)this)->m_field1C = 0;
}

// ============================================================================
// MUStatesDisplay
// ============================================================================

// 0x800931B0 - 4 bytes
void MUStatesDisplay::Startup() {
    // Empty function - just blr
}

// ============================================================================
// MUStateMachine - static accessor functions
// ============================================================================

// 0x800939C0 - 8 bytes
int MUStateMachine::GetCurRequest() {
    return (eMURequest)s_curRequest;
}

// 0x800939C8 - 12 bytes
void MUStateMachine::ClearResult() {
    s_requestResult = 0;
}

// 0x800939D4 - 8 bytes
void MUStateMachine::SetHouseNumber(int num) {
    s_houseNumber = num;
}

// 0x80093BCC - 8 bytes
int MUStateMachine::GetHouseNumber() {
    return s_houseNumber;
}

// 0x80093BD4 - 8 bytes
MUWrapper* MUStateMachine::GetMUWrapper() {
    return m_pMUWrapper;
}

// ============================================================================
// GetWrapper - identical pattern for all MUStates* classes
// Load sm ptr from offset 0x08, then return wrapper ptr at offset 0x98
// ============================================================================

// 0x80093C48 - 12 bytes
MUWrapper* MUStatesProcessRequests::GetWrapper() {
    UIObjectBase* sm = *(UIObjectBase**)((char*)this + 0x08);
    return (MUWrapper*)sm->m_pStateMachine->m_pMUWrapper;
}

// 0x80093CC0 - 12 bytes
MUWrapper* MUStatesFormat::GetWrapper() {
    UIObjectBase* sm = *(UIObjectBase**)((char*)this + 0x08);
    return (MUWrapper*)sm->m_pStateMachine->m_pMUWrapper;
}

// 0x80093D38 - 12 bytes
MUWrapper* MUStatesSlotSelectSave::GetWrapper() {
    UIObjectBase* sm = *(UIObjectBase**)((char*)this + 0x08);
    return (MUWrapper*)sm->m_pStateMachine->m_pMUWrapper;
}

// 0x80093DB0 - 12 bytes
MUWrapper* MUStatesSlotSelectSaveNoSkip::GetWrapper() {
    UIObjectBase* sm = *(UIObjectBase**)((char*)this + 0x08);
    return (MUWrapper*)sm->m_pStateMachine->m_pMUWrapper;
}

// 0x80093E28 - 12 bytes
MUWrapper* MUStatesLoadGame::GetWrapper() {
    UIObjectBase* sm = *(UIObjectBase**)((char*)this + 0x08);
    return (MUWrapper*)sm->m_pStateMachine->m_pMUWrapper;
}

// 0x80093EA0 - 12 bytes
MUWrapper* MUStatesLoadHouse::GetWrapper() {
    UIObjectBase* sm = *(UIObjectBase**)((char*)this + 0x08);
    return (MUWrapper*)sm->m_pStateMachine->m_pMUWrapper;
}

// 0x80093F18 - 12 bytes
MUWrapper* MUStatesAutoSaveNew::GetWrapper() {
    UIObjectBase* sm = *(UIObjectBase**)((char*)this + 0x08);
    return (MUWrapper*)sm->m_pStateMachine->m_pMUWrapper;
}

// 0x80093FA0 - 12 bytes
MUWrapper* MUStatesSaveNewGame::GetWrapper() {
    UIObjectBase* sm = *(UIObjectBase**)((char*)this + 0x08);
    return (MUWrapper*)sm->m_pStateMachine->m_pMUWrapper;
}

// 0x80094018 - 12 bytes
MUWrapper* MUStatesAutoSaveExisting::GetWrapper() {
    UIObjectBase* sm = *(UIObjectBase**)((char*)this + 0x08);
    return (MUWrapper*)sm->m_pStateMachine->m_pMUWrapper;
}

// 0x80094090 - 12 bytes
MUWrapper* MUStatesSaveExistingGame::GetWrapper() {
    UIObjectBase* sm = *(UIObjectBase**)((char*)this + 0x08);
    return (MUWrapper*)sm->m_pStateMachine->m_pMUWrapper;
}

// 0x80094108 - 12 bytes
MUWrapper* MUStatesTransitionAutoSaveExisting::GetWrapper() {
    UIObjectBase* sm = *(UIObjectBase**)((char*)this + 0x08);
    return (MUWrapper*)sm->m_pStateMachine->m_pMUWrapper;
}

// 0x80094180 - 12 bytes
MUWrapper* MUStatesTransitionSaveExistingGame::GetWrapper() {
    UIObjectBase* sm = *(UIObjectBase**)((char*)this + 0x08);
    return (MUWrapper*)sm->m_pStateMachine->m_pMUWrapper;
}

// 0x800941F8 - 12 bytes
MUWrapper* MUStatesLoadConfig::GetWrapper() {
    UIObjectBase* sm = *(UIObjectBase**)((char*)this + 0x08);
    return (MUWrapper*)sm->m_pStateMachine->m_pMUWrapper;
}

// 0x80094270 - 12 bytes
MUWrapper* MUStatesDisplay::GetWrapper() {
    UIObjectBase* sm = *(UIObjectBase**)((char*)this + 0x08);
    return (MUWrapper*)sm->m_pStateMachine->m_pMUWrapper;
}

// ============================================================================
// MUStateMachine::MURequest - 52 bytes
// Static function that manages request queuing
// ============================================================================

// 0x800937E8 - 52 bytes
// NON_MATCHING - uses static globals via r13, takes request as r3 (not this ptr)
int MUStateMachine::MURequest(int request) {
    int req = (int)request;
    int result = 0;
    if (s_curRequest == 0) {
        if ((unsigned int)(req - 1) <= 7) {
            s_curResult = 0;
            s_requestResult = 0;
            s_curRequest = req;
            result = req;
        }
    }
    return (eMURequest)result;
}

// ============================================================================
// MUStateMachine::MUPollForResult - 28 bytes
// ============================================================================

// 0x8009381C - 28 bytes
// NON_MATCHING - static function, takes request as r3
int MUStateMachine::MUPollForResult(int request) {
    int result = 0;
    if (s_curResult == (int)request) {
        result = s_requestResult;
    }
    return (eMURequest)result;
}
#endif
