// statemachine.cpp - StateMachine, StateMachineState, StateMachineStatus,
//                    StateMachineManager small functions
// From: statemachine.obj, basestates.obj, inlevel.obj, livemode.obj,
//       pregamestate.obj, startscreen.obj, thesims.obj, urbzmode.obj,
//       loadingscreenstate.obj
// Small functions (<=64 bytes) decompiled from these objects

#include "core/statemachine.h"
#include "core/gamestate.h"

// ============================================================================
// External references
// ============================================================================

// SDA (r13-relative) globals
extern "C" {
    extern StateMachineManager* g_pStateMachineManager; // r13 - 0xAC04 (r13-21500)
    extern int g_bDrawTopmost;                          // 0x80475C0C
    extern EGameStateMan* g_pGameStateMan;              // 0x80475C14
    extern void* g_pELiveMode;                          // 0x80475C10
    extern int g_bDrawInLevel;                          // 0x8047E680 (r13 offset)
}

// Memory functions
extern "C" {
    void* operator_new_wrapper(unsigned int size);       // 0x802d11b0
    void operator_delete_wrapper(void* ptr);            // 0x802d1220
}

// External functions called by various states
extern "C" {
    void StateMachine_Update(StateMachine* machine, float dt); // 0x80095b30
    void StateMachine_SetNextState(StateMachine* machine, int stateId, float delay); // 0x80095d78
    void StateMachine_Draw_impl(StateMachine* machine, ERC* pRC); // 0x80095d08
    void StateMachineStatus_DrawCurState(StateMachineStatus* status, ERC* pRC); // 0x800965a8
    void StateMachineStatus_DrawTopmostCurState(StateMachineStatus* status, ERC* pRC); // 0x800965e8
    void StateMachineStatus_ShutdownCurState(StateMachineStatus* status); // 0x80096514
    void StateMachineStatus_SetState(StateMachineStatus* status, StateMachineState* pState); // 0x80096424
    void StateMachineManager_UpdateMachine(StateMachineManager* mgr, float dt); // 0x800967a4
    void StateMachineManager_DrawMachine(StateMachineManager* mgr, ERC* pRC); // 0x8009683c
    void StateMachineManager_DrawTopmostMachine(StateMachineManager* mgr, ERC* pRC); // 0x800968a0

    // TheSimsStateMachine flow state functions
    int TheSimsStateMachine_IsFlowStateRequestPending(void* pMachine); // 0x800997dc
    int TheSimsStateMachine_GetFlowStateRequest(void* pMachine);       // 0x80099804
    void TheSimsStateMachine_SetFlowStateCurrent(void* pMachine);      // 0x8009981c

    // State find helpers
    StateMachineState* StateMachine_FindStateById(StateMachine* machine, int stateId); // 0x800961bc

    // LoadingScreenStateMachine functions
    void LoadingScreenStateMachine_StartLoad(void* sm, int mode);        // 0x80090c1c
    void LoadingScreenStateMachine_DeleteLoadingScreen(void* sm);        // 0x80090b5c
    int  LoadingScreenStateMachine_IsLoading(void* sm);                  // 0x80090bd0
    void LoadingScreenStateMachine_LoadFinishedNow_impl(void* sm);       // 0x80090d18

    // Dataset ref functions
    void DatasetManager_RemoveRef(void* mgr, void* ref);                 // 0x8032710c

    // EGameStateMan Draw
    void EGameStateMan_Draw(EGameStateMan* man, ERC* pRC);               // 0x80089d3c

    // Other externals
    void SaveAndQuitGame(int param);                                     // 0x800937e8
    void ChangeHouseStateMachine_StartingLoad(int mode);                 // 0x80090d58
    void StateMachineManager_FindMachineById_impl(StateMachineManager* mgr, int id); // 0x80096628
    void StateMachine_CallState_impl(StateMachine* machine, int stateId); // 0x80095dc4

    // PreGameState externals
    void CreateASimBaseState_Reset(void* state);                         // 0x800891b8
    void aptCleanupOrSomething(void* p1, void* p2);                     // 0x8003bbcc
    void EString_something(void* str);                                   // 0x80179ac8
    void aptSetupOrSomething(void* p1, void* p2, int p3);               // 0x8003b878
    void LoadingScreenStateMachine_LoadFinishing(void);                  // 0x80090d8c
    void AptResetSomething(void* p);                                     // 0x8003d7c8

    // UrbzModeNewGameState
    void UrbzResetSomething(void* p);                                    // 0x8005892c

    // StartScreenVars
    void StartScreenVars_init_func(void);                                // 0x8009591c static init

    // BGExec
    void BGExec_ResetCallbacks(void* p);                                 // 0x8003ecf4

    // UrbzCreditsState
    void SomeAptFunction(void* p, int val);                              // 0x803235cc

    // TheSimsNGCLicenseState::Shutdown helper
    void SomeShutdownFunc(void* p);                                      // 0x80311f70

    // WorldMap
    void WorldMap_Draw(void* worldMap, ERC* pRC);                        // 0x8009a1d0
}

// Float constants (from .rodata)
extern "C" {
    extern const float _flt_neg_one;      // 0x803e88b4 - value: -1.0f (for StatusReset)
    extern const float _flt_zero;         // 0x803e88d0 - value: 0.0f (for AddToSecondsBeforeNextState)
    extern const float _flt_one;          // 0x803e80bc - value: 1.0f (for LoadFinishedNow)
    extern const float _flt_zero2;        // 0x803d7db0 - value: 0.0f (for ChangeHouseUnloadHouse)
}

// Global data
extern "C" {
    extern int g_bHouseDemolished;        // 0x80475C44
    extern void* g_pDatasetManager;       // 0x804b5fd8 (lis r3, -32693; addi r3, r3, 24536)
    extern int g_bBGExecEnabled;          // r13 - 0xAC18 (r13-21480)
    extern void* g_pWorldMap;             // r13 - 0x9FD4 (r13-24620) - WorldMap ptr
    extern void* g_pTheSimsMainMenuState; // r13 - 0x9FD0 (r13-24624)
    extern void* g_pSomeAptThing;         // r13 - 0x9864 (r13-26524)
}

// Static local data (from various obj files)
extern "C" {
    extern char s_casDatasetName[];       // 0x803d75d4 - 11-byte dataset name string
    extern int g_goingToCasStage;         // 0x804fdb60
    extern int g_unloadStage;            // 0x804fdb64
}

// Vtable pointers
extern "C" {
    extern void* StateMachineState_base_vtable[]; // 0x8045c9c8 - base vtable for all StateMachineState subclasses
}

// ============================================================================
// statemachine.obj functions
// ============================================================================

// StateMachineState::OwnerSetNextState(int, float)
// 0x80095aa4 - 36 bytes
// Delegates to StateMachine::SetNextState via m_pOwner
void StateMachineState::OwnerSetNextState(int stateId, float delay) {
    ((StateMachine*)m_unused08)->SetNextState(stateId, delay);
}

// StateMachineState::OwnerCallState(int)
// 0x80095ac8 - 36 bytes
// Delegates to StateMachine::CallState via m_pOwner
void StateMachineState::OwnerCallState(int stateId) {
    ((StateMachine*)m_unused08)->CallState(stateId);
}

// StateMachineState::OwnerReturnFromState(int)
// 0x80095aec - 36 bytes
// Delegates to StateMachine::ReturnFromState via m_pOwner
void StateMachineState::OwnerReturnFromState(int returnVal) {
    ((StateMachine*)m_unused08)->ReturnFromState(returnVal);
}

// StateMachineState::OwnerGetReturnVal(void)
// 0x80095b10 - 12 bytes
// Returns the return value from the owner state machine
int StateMachineState::OwnerGetReturnVal(void) {
    return ((StateMachine*)m_unused08)->m_returnVal;
}

// StateMachineState::OwnerResetReturnVal(void)
// 0x80095b1c - 16 bytes
// Clears the return value on the owner state machine
void StateMachineState::OwnerResetReturnVal(void) {
    ((StateMachine*)m_unused08)->m_returnVal = 0;
}

// StateMachineState::ValidateHeap(bool)
// 0x80095b2c - 4 bytes
// Empty function - no-op
void StateMachineState::ValidateHeap(bool) {
}

// StateMachine::Draw(ERC *)
// 0x80095d08 - 48 bytes
// Draws the current state if machine is enabled
void StateMachine::Draw(ERC* pRC) {
    if (m_enabled != 0) {
        m_status.DrawCurState(pRC);
    }
}

// StateMachine::DrawTopmost(ERC *)
// 0x80095d38 - 64 bytes
// Draws topmost for current state if g_bDrawTopmost and machine is enabled
void StateMachine::DrawTopmost(ERC* pRC) {
    if (g_bDrawTopmost != 0) {
        if (m_enabled != 0) {
            m_status.DrawTopmostCurState(pRC);
        }
    }
}

// StateMachine::CallState(int)
// 0x80095dc4 - 56 bytes
// Finds state by id and stores it as the call state
void StateMachine::CallState(int stateId) {
    StateMachineState* pState = FindStateById(stateId);
    if (pState != 0) {
        m_pCallState = pState;
    }
}

// StateMachine::ReturnFromState(int)
// 0x80095dfc - 16 bytes
// Sets return flag and stores return state id
void StateMachine::ReturnFromState(int returnVal) {
    m_returnFlag = 1;
    m_returnStateId = returnVal;
}

// StateMachine::GetCurStateId(void) const
// 0x80095e0c - 28 bytes
// Returns the state id of the current state, or -1 if none
int StateMachine::GetCurStateId(void) const {
    StateMachineState* pState = m_status.m_pCurState;
    if (pState == 0) {
        return -1;
    }
    return pState->m_stateId;
}

// StateMachine::GetCurStateStage(void) const
// 0x80095e28 - 12 bytes
// Returns the stage of the current state
int StateMachine::GetCurStateStage(void) const {
    return m_status.m_pCurState->m_stage;
}

// StateMachine::GetLastStateId(void) const
// 0x80095ea8 - 12 bytes
// Returns the state id of the last state
int StateMachine::GetLastStateId(void) const {
    return m_status.m_pLastState->m_stateId;
}

// StateMachine::GetCallingStateId(void) const
// 0x80095eb4 - 12 bytes
// Returns the state id of the calling state
int StateMachine::GetCallingStateId(void) const {
    return m_status.m_pCallingState->m_stateId;
}

// StateMachine::GetTimeInState(void) const
// 0x800961b4 - 8 bytes
// Returns seconds in current state (float at offset 0x50)
float StateMachine::GetTimeInState(void) const {
    return m_status.m_secondsInCurState;
}

// StateMachine::FindStateById(int)
// 0x800961bc - 56 bytes
// Linear search through states vector for matching state id
StateMachineState* StateMachine::FindStateById(int stateId) {
    StateMachineState** iter = m_pStatesBegin;
    StateMachineState** end = m_pStatesEnd;
    while (iter != end) {
        StateMachineState* pState = *iter;
        if (pState->m_stateId == stateId) {
            return pState;
        }
        iter++;
    }
    return 0;
}

// StateMachine::FindState(StateMachineState *)
// 0x800961f4 - 48 bytes
// Linear search through states vector for matching pointer
StateMachineState* StateMachine::FindState(StateMachineState* pState) {
    StateMachineState** iter = m_pStatesBegin;
    StateMachineState** end = m_pStatesEnd;
    while (iter != end) {
        StateMachineState* pCur = *iter;
        if (pCur == pState) {
            return pCur;
        }
        iter++;
    }
    return 0;
}

// StateMachine::SetState(StateMachineState *)
// 0x80096224 - 56 bytes
// Sets current state via status and clears return val
// NON_MATCHING - uses stmw/lmw r30 but GCC may choose differently
void StateMachine::SetState(StateMachineState* pState) {
    m_status.SetState(pState);
    m_returnVal = 0;
}

// StateMachineStatus::StatusReset(void)
// 0x800963fc - 40 bytes
// Resets all status fields to defaults
void StateMachineStatus::StatusReset(void) {
    m_stageFlags = 0;
    m_secondsInCurState = -1.0f;
    m_pCurState = 0;
    m_pLastState = 0;
    m_pCallingState = 0;
    m_secondsBeforeNextState = -1.0f;
}

// StateMachineStatus::AddToSecondsBeforeNextState(float)
// 0x800964d8 - 44 bytes
// Adds delta to seconds before next state, clamps to >= 0
void StateMachineStatus::AddToSecondsBeforeNextState(float dt) {
    float val = m_secondsBeforeNextState;
    if (val <= 0.0f) {
        return;
    }
    val = val + dt;
    m_secondsBeforeNextState = val;
    if (val < 0.0f) {
        m_secondsBeforeNextState = 0.0f;
    }
}

// StateMachineStatus::AddToSecondsInCurState(float)
// 0x80096504 - 16 bytes
// Adds delta time to seconds in current state
void StateMachineStatus::AddToSecondsInCurState(float dt) {
    m_secondsInCurState = m_secondsInCurState + dt;
}

// StateMachineStatus::UpdateCurState(float)
// 0x80096568 - 64 bytes
// Calls the Update virtual function on the current state via vtable dispatch
// NON_MATCHING - vtable-based virtual call; compiler may use different register allocation
void StateMachineStatus::UpdateCurState(float dt) {
    StateMachineState* pState = m_pCurState;
    if (pState != 0) {
        // Virtual call through vtable at offset 0x18 in state
        // vtable entry: offset 0x28 = this adjustment (short), offset 0x2C = function ptr
        typedef void (*UpdateFn)(void*, float);
        void** vtable = (void**)pState->m_pVtable;
        short thisAdj = *(short*)((char*)vtable + 0x28);
        UpdateFn fn = (UpdateFn)*((void**)((char*)vtable + 0x2C));
        fn((char*)pState + thisAdj, dt);
    }
}

// StateMachineStatus::DrawCurState(ERC *)
// 0x800965a8 - 64 bytes
// Calls the Draw virtual function on the current state via vtable dispatch
// NON_MATCHING - vtable-based virtual call
void StateMachineStatus::DrawCurState(ERC* pRC) {
    StateMachineState* pState = m_pCurState;
    if (pState != 0) {
        typedef void (*DrawFn)(void*, ERC*);
        void** vtable = (void**)pState->m_pVtable;
        short thisAdj = *(short*)((char*)vtable + 0x30);
        DrawFn fn = (DrawFn)*((void**)((char*)vtable + 0x34));
        fn((char*)pState + thisAdj, pRC);
    }
}

// StateMachineStatus::DrawTopmostCurState(ERC *)
// 0x800965e8 - 64 bytes
// Calls the DrawTopmost virtual function on the current state via vtable dispatch
// NON_MATCHING - vtable-based virtual call
void StateMachineStatus::DrawTopmostCurState(ERC* pRC) {
    StateMachineState* pState = m_pCurState;
    if (pState != 0) {
        typedef void (*DrawTopmostFn)(void*, ERC*);
        void** vtable = (void**)pState->m_pVtable;
        short thisAdj = *(short*)((char*)vtable + 0x38);
        DrawTopmostFn fn = (DrawTopmostFn)*((void**)((char*)vtable + 0x3C));
        fn((char*)pState + thisAdj, pRC);
    }
}

// StateMachineManager::FindMachineById(int)
// 0x80096628 - 64 bytes
// Linear search through machines vector for matching machine id
StateMachine* StateMachineManager::FindMachineById(int machineId) {
    StateMachine** iter = m_pBegin;
    StateMachine** end = m_pEnd;
    while (iter != end) {
        StateMachine* pMachine = *iter;
        if (pMachine->m_machineId == machineId) {
            return pMachine;
        }
        iter++;
    }
    return 0;
}

// StateMachineManager::FindMachine(StateMachine *)
// 0x80096668 - 60 bytes
// Linear search through machines vector for matching pointer
StateMachine* StateMachineManager::FindMachine(StateMachine* pMachine) {
    StateMachine** iter = m_pBegin;
    StateMachine** end = m_pEnd;
    while (iter != end) {
        StateMachine* pCur = *iter;
        if (pCur == pMachine) {
            return pCur;
        }
        iter++;
    }
    return 0;
}

// StateMachineManager::Startup(void)
// 0x800966a4 - 60 bytes
// Allocates manager struct and stores in SDA global
// NON_MATCHING - Memory layout and initialization order may differ
void StateMachineManager::Startup(void) {
    void* mem = operator_new_wrapper(16);
    char* p = (char*)mem;
    *(int*)(p + 0) = 0;
    *(int*)(p + 4) = 0;
    *(int*)(p + 12) = 0;  // p+8+4
    g_pStateMachineManager = (StateMachineManager*)mem;
}

// StateMachineManager::UpdateMachines(float)
// 0x80096810 - 44 bytes
// Updates all machines if manager exists
void StateMachineManager::UpdateMachines(float dt) {
    StateMachineManager* mgr = g_pStateMachineManager;
    if (mgr != 0) {
        mgr->UpdateMachine(dt);
    }
}

// StateMachineManager::DrawMachines(ERC *)
// 0x80096904 - 52 bytes
// Draws all machines if manager exists
void StateMachineManager::DrawMachines(ERC* pRC) {
    StateMachineManager* mgr = g_pStateMachineManager;
    if (mgr != 0) {
        mgr->DrawMachine(pRC);
    }
}

// StateMachineManager::DrawTopmostMachines(ERC *)
// 0x80096938 - 52 bytes
// Draws topmost for all machines if manager exists
void StateMachineManager::DrawTopmostMachines(ERC* pRC) {
    StateMachineManager* mgr = g_pStateMachineManager;
    if (mgr != 0) {
        mgr->DrawTopmostMachine(pRC);
    }
}

// StateMachine::Startup(void)
// 0x80096af8 - 4 bytes
// Empty virtual - no-op
void StateMachine::Startup(void) {
}

// StateMachine::Shutdown(void)
// 0x80096afc - 36 bytes
// Shuts down the current state via status
void StateMachine::Shutdown(void) {
    m_status.ShutdownCurState();
}

// StateMachine::Reset(void)
// 0x80096b20 - 4 bytes
// Empty virtual - no-op
void StateMachine::Reset(void) {
}

// StateMachine::GetMachineId(void) const
// 0x80096b24 - 8 bytes
int StateMachine::GetMachineId(void) const {
    return m_machineId;
}

// StateMachine::GetManager(void) const
// 0x80096b2c - 8 bytes
StateMachineManager* StateMachine::GetManager(void) const {
    return m_pManager;
}

// StateMachine::GetFrameDeltaTime(void) const
// 0x80096b34 - 8 bytes
float StateMachine::GetFrameDeltaTime(void) const {
    return m_frameDeltaTime;
}

// StateMachine::GetReturnVal(void) const
// 0x80096b3c - 8 bytes
int StateMachine::GetReturnVal(void) const {
    return m_returnVal;
}

// StateMachine::ResetReturnVal(void)
// 0x80096b44 - 12 bytes
void StateMachine::ResetReturnVal(void) {
    m_returnVal = 0;
}

// StateMachine::Enable(void)
// 0x80096b50 - 12 bytes
void StateMachine::Enable(void) {
    m_enabled = 1;
}

// StateMachine::Disable(void)
// 0x80096b5c - 12 bytes
void StateMachine::Disable(void) {
    m_enabled = 0;
}

// StateMachine::PauseUpdate(void)
// 0x80096b68 - 12 bytes
void StateMachine::PauseUpdate(void) {
    m_pauseUpdate = 1;
}

// StateMachine::UnpauseUpdate(void)
// 0x80096b74 - 12 bytes
void StateMachine::UnpauseUpdate(void) {
    m_pauseUpdate = 0;
}

// StateMachine::IsEnabled(void)
// 0x80096b80 - 8 bytes
int StateMachine::IsEnabled(void) {
    return m_enabled;
}

// StateMachine::IsPausedUpdate(void)
// 0x80096b88 - 8 bytes
int StateMachine::IsPausedUpdate(void) {
    return m_pauseUpdate;
}
