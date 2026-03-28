// gamestate.cpp - EGameState, EGameStateMan, and all game state classes
// From: gamestate.obj, basestates.obj, inlevel.obj, livemode.obj,
//       pregamestate.obj, startscreen.obj, thesims.obj, urbzmode.obj,
//       loadingscreenstate.obj
// Small functions (<=64 bytes) decompiled from these objects

#include "core/gamestate.h"
#include "core/statemachine.h"

// ============================================================================
// External references
// ============================================================================

extern "C" {
    // Memory
    void* EAHeap_GetMovieHeap(void);                    // 0x802cff00
    void* EAHeap_MallocAligned(void* heap, unsigned int size, int align, int flags); // 0x802d0c84
    void EAHeap_Free(void* heap, void* ptr);            // 0x802d0d78
    void operator_delete_wrapper(void* ptr);            // 0x802d1220

    // SDA globals
    extern StateMachineManager* g_pStateMachineManager; // r13 - 0xAC04
    extern int g_bBGExecEnabled;                        // r13 - 0xAC18
    extern void* g_pWorldMap;                           // r13 - 0x9FD4
    extern void* g_pTheSimsMainMenuState;               // r13 - 0x9FD0
    extern void* g_pSomeAptThing;                       // r13 - 0x9864
    extern void* g_pLoadingScreenSM;                    // r13 - 0x8260 (r13-32160)

    // Absolute globals
    extern int g_bDrawTopmost;                          // 0x80475C0C
    extern int g_bDrawInLevel;                          // 0x80475C10
    extern EGameStateMan* g_pGameStateMan;              // 0x80475C14
    extern int g_bHouseDemolished;                      // 0x80475C44
    extern void* g_pSimsApp;                            // 0x80475E80
    extern void* g_pSimsAppData;                        // 0x80476214
    extern int g_goingToCasStage;                       // 0x804fdb60
    extern int g_unloadStage;                           // 0x804fdb64
    extern void* g_pDatasetManager;                     // 0x804b5fd8
    extern void* g_pSomePtr;                            // 0x80475F14
    extern void* g_pStaticInitGuard;                    // static init guard

    // Vtable pointers for different classes
    extern void* EGameState_vtable[];                   // 0x8045d670 (lis r9, -32698; addi r9, r9, -10640)
    extern void* StateMachineState_base_vtable[];       // 0x8045c9c8

    // Specific class vtables - offsets from 0x8045xxxx
    extern void* LiveModeInitState_vtable[];            // 0x8045d8d8
    extern void* ChangeHouseDemolishHouse_vtable[];     // 0x8045d7f8
    extern void* ChangeHouseSaveHouse_vtable[];         // 0x8045d7b0
    extern void* ChangeHouseUnloadHouse_vtable[];       // 0x8045d768
    extern void* ChangeHouseLoadHouse_vtable[];         // 0x8045d720
    extern void* LoadingScreenWaitingForLoadState_vtable[]; // 0x8045d9f8
    extern void* LoadingScreenFadeInState_vtable[];     // 0x8045d9b0
    extern void* LoadingScreenUpdateState_vtable[];     // 0x8045d968
    extern void* LoadingScreenFadeOutState_vtable[];    // 0x8045d920
    extern void* TheSimsMemCardCheckState_vtable[];     // 0x8045e3d0
    extern void* TheSimsEAMovieState_vtable[];          // 0x8045e388
    extern void* TheSimsSimsIntroMovieState_vtable[];   // 0x8045e2f8
    extern void* TheSimsEnterMainMenuState_vtable[];    // 0x8045e2b0
    extern void* TheSimsMainMenuState_vtable[];         // 0x8045e268
    extern void* UrbzCreditsState_vtable[];             // 0x8045e220
    extern void* TheSimsNGCLicenseState_vtable[];       // 0x8045c9c8 (same as base)
    extern void* DummyMode_vtable[];                    // 0x8045e1d0
    extern void* PreGameFreeplayState_vtable[];         // 0x8045dec0
    extern void* UrbzModeNewGameState_vtable[];         // 0x8045e4a8
    extern void* TheSimsMaxisLogoState_vtable[];        // 0x8045e340 (has extra member, 0x5c offset)
}

// External functions
extern "C" {
    // EGameStateMan
    void EGameStateMan_SetState(EGameStateMan* man, EGameStateId stateId); // 0x80089a80
    void EGameStateMan_Draw(EGameStateMan* man, ERC* pRC);                 // 0x80089d3c

    // StateMachine
    void StateMachine_Update(StateMachine* machine, float dt);              // 0x80095b30
    void StateMachine_Draw_impl(StateMachine* machine, ERC* pRC);           // 0x80095d08
    void StateMachine_SetNextState(StateMachine* machine, int id, float d); // 0x80095d78
    void StateMachine_CallState_impl(StateMachine* machine, int id);        // 0x80095dc4

    // TheSimsStateMachine flow
    int  TheSimsStateMachine_IsFlowStateRequestPending(void* p);            // 0x800997dc
    int  TheSimsStateMachine_GetFlowStateRequest(void* p);                  // 0x80099804
    void TheSimsStateMachine_SetFlowStateCurrent(void* p);                  // 0x8009981c

    // StateMachineManager
    StateMachine* StateMachineManager_FindMachineById(StateMachineManager* m, int id); // 0x80096628

    // Dataset
    void DatasetManager_RemoveRef(void* mgr, void* ref);                    // 0x8032710c

    // Loading screen
    void LoadingScreenStateMachine_StartLoad(void* sm, int mode);           // 0x80090c1c
    void LoadingScreenStateMachine_DeleteLoadingScreen(void* sm);           // 0x80090b5c
    int  LoadingScreenStateMachine_IsLoading(void* sm);                     // 0x80090bd0
    void LoadingScreenStateMachine_LoadFinishedNow_impl(void* sm);          // 0x80090d18
    void LoadingScreenStateMachine_StartingLoad_call(int mode);             // 0x80090d58
    void LoadingScreenStateMachine_LoadFinishing_impl(void);                // 0x80090d8c

    // Misc
    void SaveAndQuitGame(int param);                                        // 0x800937e8
    void CreateASimBaseState_Reset_impl(void* state);                       // 0x800891b8
    void AptSomething1(void* p1, void* p2);                                // 0x8003bbcc
    void* EString_GetString(void* str);                                     // 0x80179ac8
    void AptSomething2(void* p1, void* p2, int p3);                        // 0x8003b878
    void AptResetSomething(void* p);                                        // 0x8003d7c8
    void UrbzResetSomething(void* p);                                       // 0x8005892c
    void BGExec_ResetCallbacks(void* p);                                    // 0x8003ecf4
    void SomeAptFunction(void* p, int val);                                 // 0x803235cc
    void SomeShutdownFunc(void* p);                                         // 0x80311f70
    void WorldMap_Draw(void* worldMap, ERC* pRC);                           // 0x8009a1d0

    // Vector push_back
    void Vector_push_back(void* vec, void* element);                        // 0x802cc608

    // OwnerSetNextState (StateMachineState function)
    void StateMachineState_OwnerSetNextState(void* state, int id, float d); // 0x80095aa4
}

// Float constants
static const float kFloatNegOne = -1.0f;
static const float kFloatZero = 0.0f;

// ============================================================================
// gamestate.obj functions
// ============================================================================

// EGameState::EGameState(void)
// 0x80089d78 - 40 bytes
// NON_MATCHING - stack frame layout and vtable address materialization may differ
EGameState::EGameState(void) {
    m_pVtable = EGameState_vtable;
    m_stateId = 0;
}

// EGameState::~EGameState(void)
// 0x800899cc - 72 bytes (>64, NOT included - only small functions)

// EGameState::operator new(unsigned int)
// 0x80089da0 - 60 bytes
// NON_MATCHING - register allocation (stmw r30 vs r31)
void* EGameState::operator new(unsigned int size) {
    void* heap = EAHeap_GetMovieHeap();
    return EAHeap_MallocAligned(heap, size, 1, 0);
}

// EGameState::operator delete(void *)
// 0x80089ddc - 52 bytes
// NON_MATCHING - register allocation (stmw r30 vs r31)
void EGameState::operator delete(void* ptr) {
    void* heap = EAHeap_GetMovieHeap();
    EAHeap_Free(heap, ptr);
}

// EGameState::GetState(void)
// 0x80089e10 - 16 bytes
// Copies state id from src to dest (return by value via hidden param)
void EGameState::GetState(EGameStateId* pOutState) {
    *pOutState = m_stateId;
}

// EGameState::InTransportMode(void)
// 0x80089e20 - 8 bytes
// Always returns 0 (base implementation)
int EGameState::InTransportMode(void) {
    return 0;
}

// EGameState::PauseAllSounds(void)
// 0x80089e28 - 4 bytes
// Empty virtual - no-op
void EGameState::PauseAllSounds(void) {
}

// EGameState::ResumeAllSounds(void)
// 0x80089e2c - 4 bytes
// Empty virtual - no-op
void EGameState::ResumeAllSounds(void) {
}

// EGameStateMan::EGameStateMan(void)
// 0x80089a14 - 40 bytes
EGameStateMan::EGameStateMan(void) {
    *(int*)((char*)this + 0x08) = 0;
    *(int*)((char*)this + 0x04) = 0;
    *(int*)((char*)this + 0x0C) = 1;
    m_pCurrentState = 0;
    m_nextStateId = 0;
}

// EGameStateMan::AddState(EGameState *)
// 0x80089b30 - 56 bytes
// NON_MATCHING - stmw/lmw register count may differ
void EGameStateMan::AddState(EGameState* pState) {
    Vector_push_back((char*)this + 0x04, &pState);
    pState->m_pManager = this;
}

// EGameStateMan::KillState(void)
// 0x80089b68 - 56 bytes
// Triggers state transition to kill state (id = 2)
void EGameStateMan::KillState(void) {
    if (m_pCurrentState != 0) {
        EGameStateId killId = (EGameStateId)2;
        EGameStateMan_SetState(this, killId);
    }
}

// EGameStateMan::Draw(ERC *)
// 0x80089d3c - 60 bytes
// Virtual call to Draw on current state's game state
// NON_MATCHING - vtable dispatch
void EGameStateMan::Draw(ERC* pRC) {
    // Loads current state, gets vtable, calls Draw virtually
    // This is a vtable dispatch through the EGameState vtable
    void* pCurState = m_pCurrentState;
    void** stateVtable = *(void***)pCurState;
    void** vtableInfo = (void**)stateVtable[2]; // offset 0x08
    short thisAdj = *(short*)((char*)vtableInfo + 0x20);
    typedef void (*DrawFn)(void*, ERC*);
    DrawFn fn = (DrawFn)*((void**)((char*)vtableInfo + 0x24));
    fn((char*)stateVtable + thisAdj, pRC);
}

// ============================================================================
// basestates.obj functions (CreateASimBaseState)
// ============================================================================

// CreateASimBaseState - inherits StateMachineState
// Offset 0x08: m_pOwner (TheSimsStateMachine*)
// Offset 0x20: m_isPending (int) - pending flag
// Offset 0x28: m_casAccepted (int) - accepted flag
// Offset 0x2C: m_casCanceled (int) - canceled flag

// CreateASimBaseState::Draw(ERC *)
// 0x800898c0 - 4 bytes
// Empty - no-op
static void CreateASimBaseState_Draw(void* pRC) {
    (void)pRC;
}

// CreateASimBaseState::CASAccepted(void)
// 0x80089910 - 40 bytes
// Returns 1 if not pending AND accepted flag is set
static int CreateASimBaseState_CASAccepted(void* self) {
    int* p = (int*)self;
    int pending = p[0x20 / 4];
    if (pending != 0) return 0;
    int accepted = p[0x28 / 4];
    if (accepted == 0) return 0;
    return 1;
}

// CreateASimBaseState::CASCanceled(void)
// 0x80089938 - 40 bytes
// Returns 1 if not pending AND canceled flag is set
static int CreateASimBaseState_CASCanceled(void* self) {
    int* p = (int*)self;
    int pending = p[0x20 / 4];
    if (pending != 0) return 0;
    int canceled = p[0x2C / 4];
    if (canceled == 0) return 0;
    return 1;
}

// CreateASimBaseState::GetDatasetName(char *)
// 0x80089214 - 44 bytes
// Copies 11-byte dataset name from global to output buffer
// NON_MATCHING - byte/halfword copy sequence
static void CreateASimBaseState_GetDatasetName(void* self, char* out) {
    // Copies from a global 11-byte string at 0x803d75d4
    // Uses lwz+lwz+lhz+lbz pattern (4+4+2+1 = 11 bytes)
    extern char s_casDatasetName[];  // 0x803d75d4
    *(int*)(out + 0) = *(int*)(s_casDatasetName + 0);
    *(int*)(out + 4) = *(int*)(s_casDatasetName + 4);
    *(short*)(out + 8) = *(short*)(s_casDatasetName + 8);
    *(char*)(out + 10) = *(char*)(s_casDatasetName + 10);
}

// CreateASimBaseState::IsFlowStateRequestPending(void)
// 0x80089960 - 36 bytes
// Delegates to TheSimsStateMachine via owner at offset 0x08
static int CreateASimBaseState_IsFlowStateRequestPending(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    return TheSimsStateMachine_IsFlowStateRequestPending(owner);
}

// CreateASimBaseState::GetFlowStateRequest(void)
// 0x80089984 - 36 bytes
static int CreateASimBaseState_GetFlowStateRequest(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    return TheSimsStateMachine_GetFlowStateRequest(owner);
}

// CreateASimBaseState::SetFlowStateCurrent(void)
// 0x800899a8 - 36 bytes
static void CreateASimBaseState_SetFlowStateCurrent(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    TheSimsStateMachine_SetFlowStateCurrent(owner);
}

// ============================================================================
// inlevel.obj functions (InLevelBaseState)
// ============================================================================

// InLevelBaseState - inherits StateMachineState
// Offset 0x08: m_pOwner (TheSimsStateMachine*)
// Offset 0x1C: m_field1C (int)
// Offset 0x20: m_field20 (int)

// InLevelBaseState::Reset(void)
// 0x80089e94 - 28 bytes
static void InLevelBaseState_Reset(void* self) {
    int* p = (int*)self;
    p[0x1C / 4] = 0;
    p[0x20 / 4] = 0;
    *(int*)((char*)&g_bDrawInLevel) = 1;
}

// InLevelBaseState::Draw(ERC *)
// 0x8008b498 - 56 bytes
// Draws if g_bDrawInLevel is set, delegates to EGameStateMan::Draw
static void InLevelBaseState_Draw(void* self, ERC* pRC) {
    (void)self;
    if (g_bDrawInLevel != 0) {
        EGameStateMan_Draw(g_pGameStateMan, pRC);
    }
}

// InLevelBaseState::dialog_zero_input_callback(void)
// 0x8008b5ac - 4 bytes
// Empty callback - no-op
static void InLevelBaseState_dialog_zero_input_callback(void) {
}

// InLevelBaseState::IsFlowStateRequestPending(void)
// 0x8008b758 - 36 bytes
static int InLevelBaseState_IsFlowStateRequestPending(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    return TheSimsStateMachine_IsFlowStateRequestPending(owner);
}

// InLevelBaseState::GetFlowStateRequest(void)
// 0x8008b77c - 36 bytes
static int InLevelBaseState_GetFlowStateRequest(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    return TheSimsStateMachine_GetFlowStateRequest(owner);
}

// InLevelBaseState::SetFlowStateCurrent(void)
// 0x8008b7a0 - 36 bytes
static void InLevelBaseState_SetFlowStateCurrent(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    TheSimsStateMachine_SetFlowStateCurrent(owner);
}

// ============================================================================
// livemode.obj functions
// ============================================================================

// ELiveMode - game mode class
// Offset 0x0C: m_introCameraState (int)
// Offset 0x24: m_goingToNeighborhoodMode (int)
// Offset 0x28: m_inTransportMode (int)
// Offset 0x30: m_initialized (int)
// Offset 0x34: m_dontDraw (int)

// LiveModeInitState::Shutdown(void)
// 0x8008bc24 - 4 bytes
static void LiveModeInitState_Shutdown(void) {
}

// LiveModeInitState::Draw(ERC *)
// 0x8008c9bc - 4 bytes
static void LiveModeInitState_Draw(ERC* pRC) {
    (void)pRC;
}

// LiveModeInitState::DatasetFinishAddRefAsync(void)
// 0x8008ca18 - 64 bytes
// NON_MATCHING - stmw/lmw register pair selection
static void LiveModeInitState_DatasetFinishAddRefAsync(void* self) {
    void* ref = ((void**)self)[0x1C / 4];
    DatasetManager_RemoveRef((void*)((char*)g_pDatasetManager), ref);
    ((void**)self)[0x1C / 4] = 0;
}

// LiveModeInitState::DatasetPendingAddRefAsync(void)
// 0x8008ff18 - 24 bytes
// Returns 1 if m_datasetRef (offset 0x1C) is non-null, 0 otherwise
static int LiveModeInitState_DatasetPendingAddRefAsync(void* self) {
    void* ref = ((void**)self)[0x1C / 4];
    if (ref != 0) return 1;
    return 0;
}

// LiveModeInitState::LiveModeInitState(int)
// 0x8008fedc - 60 bytes
// Constructor: initializes state fields
// NON_MATCHING - field init order may differ
static void LiveModeInitState_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)LiveModeInitState_vtable;
    p[0x1C / 4] = 0;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
    p[0x10 / 4] = 0;
}

// ChangeHouseDemolishHouse::Reset(void)
// 0x8008cc90 - 48 bytes
static void ChangeHouseDemolishHouse_Reset(void* self) {
    g_bHouseDemolished = 0;
    LoadingScreenStateMachine_StartingLoad_call(4);
}

// ChangeHouseSaveHouse::Reset(void)
// 0x8008cd78 - 36 bytes
static void ChangeHouseSaveHouse_Reset(void* self) {
    SaveAndQuitGame(7);
}

// ChangeHouseUnloadHouse::Update(float)
// 0x8008cf10 - 44 bytes
// Calls OwnerSetNextState(3, 0.0f)
static void ChangeHouseUnloadHouse_Update(void* self, float dt) {
    StateMachineState_OwnerSetNextState(self, 3, 0.0f);
}

// ChangeHouseLoadHouse::DatasetFinishAddRefAsync(void)
// 0x8008cf94 - 64 bytes
// Same pattern as LiveModeInitState::DatasetFinishAddRefAsync
// NON_MATCHING - stmw/lmw register pair selection
static void ChangeHouseLoadHouse_DatasetFinishAddRefAsync(void* self) {
    void* ref = ((void**)self)[0x1C / 4];
    DatasetManager_RemoveRef((void*)((char*)g_pDatasetManager), ref);
    ((void**)self)[0x1C / 4] = 0;
}

// ChangeHouseLoadHouse::DatasetPendingAddRefAsync(void)
// 0x8009018c - 24 bytes
static int ChangeHouseLoadHouse_DatasetPendingAddRefAsync(void* self) {
    void* ref = ((void**)self)[0x1C / 4];
    if (ref != 0) return 1;
    return 0;
}

// LiveModeChangeHouseStateMachine::Update(float)
// 0x8008dbcc - 32 bytes
// Delegates to StateMachine::Update
static void LiveModeChangeHouseStateMachine_Update(void* self, float dt) {
    StateMachine_Update((StateMachine*)self, dt);
}

// LiveModeChangeHouseStateMachine::Draw(ERC *)
// 0x8008dbec - 32 bytes
// Delegates to StateMachine::Draw
static void LiveModeChangeHouseStateMachine_Draw(void* self, ERC* pRC) {
    StateMachine_Draw_impl((StateMachine*)self, pRC);
}

// ELiveMode::ChangeHouse(void)
// 0x8008dc0c - 52 bytes
// Finds the SIMS machine and calls state 0x13 (19)
static void ELiveMode_ChangeHouse(void* self) {
    StateMachine* pMachine = StateMachineManager_FindMachineById(
        g_pStateMachineManager, 0x53494D53); // 'SIMS'
    StateMachine_CallState_impl(pMachine, 19);
}

// ELiveMode::PauseAllSounds(void)
// 0x8008ef14 - 4 bytes
static void ELiveMode_PauseAllSounds(void) {
}

// ELiveMode::ResumeAllSounds(void)
// 0x8008ef18 - 4 bytes
static void ELiveMode_ResumeAllSounds(void) {
}

// ELiveMode::TriggerIntroCamera(CameraDirector *)
// 0x8008fbd0 - 44 bytes
// Sets intro camera triggered flag and modifies CameraDirector
static void ELiveMode_TriggerIntroCamera(void* self, void* pCamDir) {
    int* pSelf = (int*)self;
    pSelf[0x0C / 4] = 1;
    if (pCamDir == 0) return;
    int* pCam = (int*)pCamDir;
    pCam[0x160 / 4] = 1;
    int flags = pCam[0x240 / 4];
    flags |= 1;
    pCam[0x240 / 4] = flags;
    pSelf[0x34 / 4] = 1;
    pCam[0x320 / 4] = 1;
}

// ELiveMode::InTransportMode(void)
// 0x80090038 - 8 bytes
static int ELiveMode_InTransportMode(void* self) {
    return ((int*)self)[0x28 / 4];
}

// ELiveMode::IsIntroCameraTriggered(void)
// 0x80090040 - 20 bytes
// Returns (m_introCameraState != 0) as bool
static int ELiveMode_IsIntroCameraTriggered(void* self) {
    int state = ((int*)self)[0x0C / 4];
    // xori r3, r3, 1; subfic r0, r3, 0; adde r3, r0, r3
    // This is: (state ^ 1) == 0 ? 1 : 0, i.e., state != 0
    state ^= 1;
    return (state == 0) ? 1 : 0;
}

// ELiveMode::ResetIntroCamera(void)
// 0x80090054 - 12 bytes
static void ELiveMode_ResetIntroCamera(void* self) {
    ((int*)self)[0x0C / 4] = 0;
}

// ELiveMode::SetIntroCameraState(IntroCameraStartState)
// 0x80090060 - 8 bytes
static void ELiveMode_SetIntroCameraState(void* self, int state) {
    ((int*)self)[0x0C / 4] = state;
}

// ELiveMode::GetIntroCameraState(void)
// 0x80090068 - 8 bytes
static int ELiveMode_GetIntroCameraState(void* self) {
    return ((int*)self)[0x0C / 4];
}

// ELiveMode::IsRunningIntroCamera(void)
// 0x80090070 - 24 bytes
// Returns 1 if m_introCameraState != 0
static int ELiveMode_IsRunningIntroCamera(void* self) {
    int state = ((int*)self)[0x0C / 4];
    if (state != 0) return 1;
    return 0;
}

// ELiveMode::SetGoingToNeighborhoodMode(bool)
// 0x80090088 - 8 bytes
static void ELiveMode_SetGoingToNeighborhoodMode(void* self, int val) {
    ((int*)self)[0x24 / 4] = val;
}

// ELiveMode::SetInitialized(bool)
// 0x80090090 - 8 bytes
static void ELiveMode_SetInitialized(void* self, int val) {
    ((int*)self)[0x30 / 4] = val;
}

// ELiveMode::IsInitialized(void)
// 0x80090098 - 8 bytes
static int ELiveMode_IsInitialized(void* self) {
    return ((int*)self)[0x30 / 4];
}

// ELiveMode::SetDontDraw(bool)
// 0x800900a0 - 8 bytes
static void ELiveMode_SetDontDraw(void* self, int val) {
    ((int*)self)[0x34 / 4] = val;
}

// ChangeHouseDemolishHouse::ChangeHouseDemolishHouse(int)
// 0x800900a8 - 56 bytes
static void ChangeHouseDemolishHouse_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x10 / 4] = 0;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)ChangeHouseDemolishHouse_vtable;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
}

// ChangeHouseSaveHouse::ChangeHouseSaveHouse(int)
// 0x800900e0 - 56 bytes
static void ChangeHouseSaveHouse_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x10 / 4] = 0;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)ChangeHouseSaveHouse_vtable;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
}

// ChangeHouseUnloadHouse::ChangeHouseUnloadHouse(int)
// 0x80090118 - 56 bytes
static void ChangeHouseUnloadHouse_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x10 / 4] = 0;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)ChangeHouseUnloadHouse_vtable;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
}

// ChangeHouseLoadHouse::ChangeHouseLoadHouse(int)
// 0x80090150 - 60 bytes
static void ChangeHouseLoadHouse_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)ChangeHouseLoadHouse_vtable;
    p[0x1C / 4] = 0;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
    p[0x10 / 4] = 0;
}

// ============================================================================
// loadingscreenstate.obj functions
// ============================================================================

// LoadingScreenStateMachine embedded fader struct at offset 0xA8 (from machine base)
// Fader:
//   0x00: m_currentValue (float)
//   0x04: m_speed (float)
//   0x08: m_targetValue (float)
//   0x0C: m_flags (int) - bit 0: fading in, bit 1: faded in, bit 2: fading out, bit 3: faded out

// LoadingScreenStateMachine::Update(float)
// 0x80090ae4 - 32 bytes
// Delegates to StateMachine::Update
static void LoadingScreenStateMachine_Update(void* self, float dt) {
    StateMachine_Update((StateMachine*)self, dt);
}

// LoadingScreenStateMachine::IsReadyToLoad(void)
// 0x80090bb8 - 24 bytes
// Returns (m_readyToLoad at offset 0xA0) != 0
static int LoadingScreenStateMachine_IsReadyToLoad(void* self) {
    int val = ((int*)self)[0xA0 / 4];
    if (val != 0) return 1;
    return 0;
}

// LoadingScreenStateMachine::LoadFinishedNow(void)
// 0x80090d18 - 64 bytes
// Deletes loading screen and sets next state to 0 with delay 1.0f
// NON_MATCHING - stmw/lmw and float constant materialization
static void LoadingScreenStateMachine_LoadFinishedNow(void* self) {
    LoadingScreenStateMachine_DeleteLoadingScreen(self);
    StateMachine_SetNextState((StateMachine*)self, 0, 1.0f);
}

// LoadingScreenStateMachine::StartingLoad(CLoadingScreen::eLoadingScreenMode)
// 0x80090d58 - 52 bytes
// Static - delegates to singleton if it exists
static void LoadingScreenStateMachine_StartingLoad(int mode) {
    void* sm = g_pLoadingScreenSM;
    if (sm != 0) {
        LoadingScreenStateMachine_StartLoad(sm, mode);
    }
}

// LoadingScreenStateMachine::LoadFinishing(void)
// 0x80090d8c - 24 bytes
// Static - sets load complete flag on singleton if it exists
static void LoadingScreenStateMachine_LoadFinishing(void) {
    void* sm = g_pLoadingScreenSM;
    if (sm == 0) return;
    ((int*)sm)[0xA4 / 4] = 1;
}

// LoadingScreenStateMachine::LoadFinishNow(void)
// 0x80090da4 - 44 bytes
// Static - calls LoadFinishedNow on singleton if it exists
static void LoadingScreenStateMachine_LoadFinishNow(void) {
    void* sm = g_pLoadingScreenSM;
    if (sm != 0) {
        LoadingScreenStateMachine_LoadFinishedNow_impl(sm);
    }
}

// LoadingScreenStateMachine::LoadInProgress(void)
// 0x80090dd0 - 52 bytes
// Static - returns whether loading is in progress via singleton
static int LoadingScreenStateMachine_LoadInProgress(void) {
    void* sm = g_pLoadingScreenSM;
    if (sm == 0) return 0;
    return LoadingScreenStateMachine_IsLoading(sm);
}

// LoadingScreenStateMachine::GetLoadingScreen(void)
// 0x80090e04 - 8 bytes
static void* LoadingScreenStateMachine_GetLoadingScreen(void* self) {
    return ((void**)self)[0x98 / 4];
}

// LoadingScreenStateMachine::LoadStarted(void)
// 0x80090e0c - 12 bytes
static void LoadingScreenStateMachine_LoadStarted(void* self) {
    ((int*)self)[0xA0 / 4] = 0;
}

// LoadingScreenStateMachine::IsLoadComplete(void)
// 0x80090e18 - 8 bytes
static int LoadingScreenStateMachine_IsLoadComplete(void* self) {
    return ((int*)self)[0xA4 / 4];
}

// LoadingScreenStateMachine::FaderStop(void)
// 0x80090e88 - 12 bytes
static void LoadingScreenStateMachine_FaderStop(void* self) {
    ((int*)self)[0xB4 / 4] = 0;
}

// LoadingScreenStateMachine::GetSingleton(void)
// 0x80090f74 - 8 bytes
static void* LoadingScreenStateMachine_GetSingleton(void) {
    return g_pLoadingScreenSM;
}

// LoadingScreenStateMachine::IsFadingIn(void)
// 0x80090f7c - 40 bytes
// Returns 1 if fading in (bit 0) OR loading not ready (m_readyToLoad != 0)
static int LoadingScreenStateMachine_IsFadingIn(void) {
    void* sm = g_pLoadingScreenSM;
    int flags = ((int*)sm)[0xB4 / 4];
    if (flags & 1) return 1;
    int ready = ((int*)sm)[0xA0 / 4];
    if (ready == 0) return 0;
    return 1;
}

// LoadingScreenStateMachine::IsFadedIn(void)
// 0x80090fa4 - 16 bytes
// Returns bit 1 of fader flags (rlwinm r3,r3,30,31,31)
static int LoadingScreenStateMachine_IsFadedIn(void) {
    void* sm = g_pLoadingScreenSM;
    int flags = ((int*)sm)[0xB4 / 4];
    return (flags >> 2) & 1;
}

// LoadingScreenStateMachine::IsFadingOut(void)
// 0x80090fb4 - 16 bytes
// Returns bit 2 of fader flags (rlwinm r3,r3,31,31,31)
static int LoadingScreenStateMachine_IsFadingOut(void) {
    void* sm = g_pLoadingScreenSM;
    int flags = ((int*)sm)[0xB4 / 4];
    return (flags >> 1) & 1;
}

// LoadingScreenStateMachine::IsFadedOut(void)
// 0x80090fc4 - 16 bytes
// Returns bit 3 of fader flags (rlwinm r3,r3,29,31,31)
static int LoadingScreenStateMachine_IsFadedOut(void) {
    void* sm = g_pLoadingScreenSM;
    int flags = ((int*)sm)[0xB4 / 4];
    return (flags >> 3) & 1;
}

// LoadingScreenStateMachine::LoadFinished(void)
// 0x80090fd4 - 12 bytes
static void LoadingScreenStateMachine_LoadFinished(void* self) {
    ((int*)self)[0xA4 / 4] = 1;
}

// LoadingScreenWaitingForLoadState::LoadingScreenWaitingForLoadState(int)
// 0x80090fe0 - 56 bytes
static void LoadingScreenWaitingForLoadState_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x10 / 4] = 0;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)LoadingScreenWaitingForLoadState_vtable;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
}

// LoadingScreenWaitingForLoadState::FaderStart(float)
// 0x80091018 - 60 bytes
// Sets up fader on the owning state machine
// NON_MATCHING - complex floating point operations and bit manipulation
static void LoadingScreenWaitingForLoadState_FaderStart(void* self, float duration) {
    void* owner = ((void**)self)[0x08 / 4];
    int* pFader = (int*)((char*)owner + 0xA8);
    pFader[0x0C / 4] = 16;
    *(float*)((char*)pFader + 0x08) = duration;
    *(float*)((char*)owner + 0xA8) = duration;
    float speed = 1.0f / duration;
    int flags = pFader[0x0C / 4];
    flags &= ~0x07;
    flags |= 1;
    pFader[0x0C / 4] = flags;
    *(float*)((char*)pFader + 0x04) = speed;
}

// LoadingScreenFadeInState::LoadingScreenFadeInState(int)
// 0x80091098 - 56 bytes
static void LoadingScreenFadeInState_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x10 / 4] = 0;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)LoadingScreenFadeInState_vtable;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
}

// LoadingScreenFadeInState::IsLoadComplete(void)
// 0x800911b8 - 52 bytes
// Reads m_loadComplete (int at owner+0xA4), converts to float
// NON_MATCHING - int-to-float conversion uses magic number technique
static float LoadingScreenFadeInState_IsLoadComplete(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    int val = ((int*)owner)[0xA4 / 4];
    return (float)val;
}

// LoadingScreenUpdateState::LoadingScreenUpdateState(int)
// 0x800911ec - 56 bytes
static void LoadingScreenUpdateState_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x10 / 4] = 0;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)LoadingScreenUpdateState_vtable;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
}

// LoadingScreenUpdateState::FaderStart(float)
// 0x80091224 - 64 bytes
// Sets up fader with fade-in flag for update state
// NON_MATCHING - complex floating point operations and bit manipulation
static void LoadingScreenUpdateState_FaderStart(void* self, float duration) {
    void* owner = ((void**)self)[0x08 / 4];
    int* pFader = (int*)((char*)owner + 0xA8);
    pFader[0x0C / 4] = 16;
    *(float*)((char*)pFader + 0x08) = duration;
    *(float*)((char*)owner + 0xA8) = duration;
    float speed = -1.0f / duration;
    int flags = pFader[0x0C / 4];
    flags &= ~0x0E;   // -14 = 0xFFFFFFF2 -> AND mask
    flags |= 2;
    pFader[0x0C / 4] = flags;
    *(float*)((char*)pFader + 0x04) = speed;
}

// LoadingScreenUpdateState::IsLoadComplete(void)
// 0x800912dc - 52 bytes
// Same pattern as FadeInState::IsLoadComplete
// NON_MATCHING - int-to-float conversion
static float LoadingScreenUpdateState_IsLoadComplete(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    int val = ((int*)owner)[0xA4 / 4];
    return (float)val;
}

// LoadingScreenFadeOutState::LoadingScreenFadeOutState(int)
// 0x80091310 - 56 bytes
static void LoadingScreenFadeOutState_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x10 / 4] = 0;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)LoadingScreenFadeOutState_vtable;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
}

// LoadingScreenFadeOutState::IsLoadComplete(void)
// 0x80091430 - 52 bytes
// Same pattern as FadeInState::IsLoadComplete
// NON_MATCHING - int-to-float conversion
static float LoadingScreenFadeOutState_IsLoadComplete(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    int val = ((int*)owner)[0xA4 / 4];
    return (float)val;
}

// ============================================================================
// pregamestate.obj functions
// ============================================================================

// PreGameCasPlayer1State::Startup(void)
// 0x800949e4 - 4 bytes
static void PreGameCasPlayer1State_Startup(void) {
}

// PreGameCasPlayer1State::Shutdown(void)
// 0x800949e8 - 4 bytes
static void PreGameCasPlayer1State_Shutdown(void) {
}

// PreGameCasPlayer2State::Shutdown(void)
// 0x80094b54 - 20 bytes
// Sets player 2 roommate index to -1
static void PreGameCasPlayer2State_Shutdown(void* self) {
    int* pApp = (int*)g_pSimsApp;
    int* pData = (int*)(((char*)pApp) + 0x03AC);
    // Actually: lwz r11, 0x5E80(r9); stw r0, 0x03AC(r11)
    // g_pSimsApp is at 0x80475E80, offset 0x03AC = 940
    *pData = -1;
}

// PreGameCreateAFamilyState::Reset(void)
// 0x80094c6c - 52 bytes
// Calls base Reset then does APT setup
static void PreGameCreateAFamilyState_Reset(void* self) {
    CreateASimBaseState_Reset_impl(self);
    // Then calls AptSomething1(aptPtr, data)
    // aptPtr = 0x80475B84, data = *(0x80476214)
    AptSomething1((void*)0x80475B84, (void*)*(int*)((char*)&g_pSimsAppData));
}

// InLevelCreateASimState::Reset(void)
// 0x80094db0 - 64 bytes
// Calls base Reset then does string lookup and APT setup
// NON_MATCHING - string materialization and function call order
static void InLevelCreateASimState_Reset(void* self) {
    CreateASimBaseState_Reset_impl(self);
    void* str = (void*)EString_GetString((void*)0x803e8570);
    AptSomething2((void*)0x80475B84, str, 0);
}

// PreGameFreeplayState::Reset(void)
// 0x80095060 - 44 bytes
static void PreGameFreeplayState_Reset(void* self) {
    LoadingScreenStateMachine_LoadFinishing_impl();
    AptResetSomething((void*)0x80475B84);
}

// PreGameState::SetFlowStateCurrent(void)
// 0x800952b4 - 36 bytes
static void PreGameState_SetFlowStateCurrent(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    TheSimsStateMachine_SetFlowStateCurrent(owner);
}

// PreGameFreeplayState::PreGameFreeplayState(int)
// 0x80095408 - 60 bytes
static void PreGameFreeplayState_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)PreGameFreeplayState_vtable;
    p[0x1C / 4] = 0;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
    p[0x10 / 4] = 0;
}

// PreGameFreeplayState::IsFlowStateRequestPending(void)
// 0x80095444 - 36 bytes
static int PreGameFreeplayState_IsFlowStateRequestPending(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    return TheSimsStateMachine_IsFlowStateRequestPending(owner);
}

// PreGameFreeplayState::GetFlowStateRequest(void)
// 0x80095468 - 36 bytes
static int PreGameFreeplayState_GetFlowStateRequest(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    return TheSimsStateMachine_GetFlowStateRequest(owner);
}

// PreGameFreeplayState::SetFlowStateCurrent(void)
// 0x8009548c - 36 bytes
static void PreGameFreeplayState_SetFlowStateCurrent(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    TheSimsStateMachine_SetFlowStateCurrent(owner);
}

// ============================================================================
// thesims.obj functions
// ============================================================================

// TheSimsNGCLicenseState::Shutdown(void)
// 0x80096cf0 - 64 bytes
// Frees texture at offset 0x1C if present
// NON_MATCHING - register allocation
static void TheSimsNGCLicenseState_Shutdown(void* self) {
    void* tex = ((void**)self)[0x1C / 4];
    if (tex != 0) {
        SomeShutdownFunc(tex);
        ((void**)self)[0x1C / 4] = 0;
    }
}

// TheSimsMemCardCheckState::Shutdown(void)
// 0x800970e8 - 4 bytes
static void TheSimsMemCardCheckState_Shutdown(void) {
}

// TheSimsMemCardCheckState::Update(float)
// 0x800970ec - 4 bytes
static void TheSimsMemCardCheckState_Update(float dt) {
    (void)dt;
}

// TheSimsEnterMainMenuState::Shutdown(void)
// 0x80097fdc - 4 bytes
static void TheSimsEnterMainMenuState_Shutdown(void) {
}

// BGExec_SetDefaults(void)
// 0x80097fe0 - 48 bytes
// Resets background exec callbacks and sets enabled flag
static void BGExec_SetDefaults(void) {
    BGExec_ResetCallbacks((void*)0x80475DCC);
    g_bBGExecEnabled = 1;
}

// TheSimsEnterMainMenuState::Draw(ERC *)
// 0x800985f8 - 4 bytes
static void TheSimsEnterMainMenuState_Draw(ERC* pRC) {
    (void)pRC;
}

// TheSimsEnterMainMenuState::DrawTopmost(ERC *)
// 0x800985fc - 4 bytes
static void TheSimsEnterMainMenuState_DrawTopmost(ERC* pRC) {
    (void)pRC;
}

// TheSimsMainMenuState::Draw(ERC *)
// 0x80098d00 - 44 bytes
// Draws world map if it exists
static void TheSimsMainMenuState_Draw(void* self, ERC* pRC) {
    (void)self;
    if (g_pWorldMap != 0) {
        WorldMap_Draw(g_pWorldMap, pRC);
    }
}

// UrbzCreditsState::Reset(void)
// 0x80098d2c - 4 bytes
static void UrbzCreditsState_Reset(void) {
}

// UrbzCreditsState::Shutdown(void)
// 0x80098d30 - 40 bytes
// Calls SomeAptFunction with 0
static void UrbzCreditsState_Shutdown(void* self) {
    (void)self;
    SomeAptFunction(g_pSomeAptThing, 0);
}

// TheSimsStateMachine::IsFlowStateRequestPending(void)
// 0x800997dc - 40 bytes
// Returns 1 if there's a pending flow state request
static int TheSimsStateMachine_IsFlowStateRequestPending_impl(void* self) {
    void* pExtra = ((void**)self)[0x98 / 4];
    if (pExtra == 0) {
        return 0;
    }
    int nextState = ((int*)pExtra)[0x84 / 4];
    int curState = ((int*)pExtra)[0x88 / 4];
    if (nextState != curState) return 1;
    return 0;
}

// TheSimsStateMachine::GetFlowStateRequest(void)
// 0x80099804 - 24 bytes
// Returns the pending flow state request id
static int TheSimsStateMachine_GetFlowStateRequest_impl(void* self) {
    void* pExtra = ((void**)self)[0x98 / 4];
    if (pExtra == 0) return 0;
    return ((int*)pExtra)[0x84 / 4];
}

// TheSimsStateMachine::SetFlowStateCurrent(void)
// 0x8009981c - 24 bytes
// Sets current flow state to match the requested state
static void TheSimsStateMachine_SetFlowStateCurrent_impl(void* self) {
    void* pExtra = ((void**)self)[0x98 / 4];
    if (pExtra == 0) return;
    int nextState = ((int*)pExtra)[0x84 / 4];
    ((int*)pExtra)[0x88 / 4] = nextState;
}

// DummyMode::DummyMode(void)
// 0x80099834 - 48 bytes
// Constructor for dummy/placeholder game mode
// NON_MATCHING - stack frame and vtable materialization
static void DummyMode_ctor(void* self) {
    int* p = (int*)self;
    p[0x08 / 4] = (int)DummyMode_vtable;
    p[0x00 / 4] = 2;
}

// DummyMode::Init(int)
// 0x800998b8 - 4 bytes
static void DummyMode_Init(void* self, int param) {
    (void)self; (void)param;
}

// DummyMode::Reset(int)
// 0x800998bc - 4 bytes
static void DummyMode_Reset(void* self, int param) {
    (void)self; (void)param;
}

// DummyMode::Update(void)
// 0x800998c0 - 4 bytes
static void DummyMode_Update(void) {
}

// DummyMode::Draw(ERC *)
// 0x800998c4 - 4 bytes
static void DummyMode_Draw(ERC* pRC) {
    (void)pRC;
}

// TheSimsMemCardCheckState::TheSimsMemCardCheckState(int)
// 0x8009ae4c - 56 bytes
static void TheSimsMemCardCheckState_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x10 / 4] = 0;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)TheSimsMemCardCheckState_vtable;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
}

// TheSimsEAMovieState::TheSimsEAMovieState(int)
// 0x8009aeb8 - 60 bytes
static void TheSimsEAMovieState_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)TheSimsEAMovieState_vtable;
    p[0x1C / 4] = 0;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
    p[0x10 / 4] = 0;
}

// TheSimsSimsIntroMovieState::TheSimsSimsIntroMovieState(int)
// 0x8009afb8 - 60 bytes
static void TheSimsSimsIntroMovieState_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)TheSimsSimsIntroMovieState_vtable;
    p[0x24 / 4] = 0; // note: offset 0x24 not 0x1C
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
    p[0x10 / 4] = 0;
}

// TheSimsEnterMainMenuState::TheSimsEnterMainMenuState(int)
// 0x8009b028 - 60 bytes
static void TheSimsEnterMainMenuState_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)TheSimsEnterMainMenuState_vtable;
    p[0x1C / 4] = 0;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
    p[0x10 / 4] = 0;
}

// TheSimsMainMenuState::TheSimsMainMenuState(int)
// 0x8009b098 - 60 bytes
// Also stores self to g_pTheSimsMainMenuState
static void TheSimsMainMenuState_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x10 / 4] = 0;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)TheSimsMainMenuState_vtable;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
    g_pTheSimsMainMenuState = self;
}

// TheSimsMainMenuState::IsFlowStateRequestPending(void)
// 0x8009b11c - 36 bytes
static int TheSimsMainMenuState_IsFlowStateRequestPending(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    return TheSimsStateMachine_IsFlowStateRequestPending(owner);
}

// TheSimsMainMenuState::GetFlowStateRequest(void)
// 0x8009b140 - 36 bytes
static int TheSimsMainMenuState_GetFlowStateRequest(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    return TheSimsStateMachine_GetFlowStateRequest(owner);
}

// TheSimsMainMenuState::SetFlowStateCurrent(void)
// 0x8009b164 - 36 bytes
static void TheSimsMainMenuState_SetFlowStateCurrent(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    TheSimsStateMachine_SetFlowStateCurrent(owner);
}

// UrbzCreditsState::UrbzCreditsState(int)
// 0x8009b188 - 56 bytes
static void UrbzCreditsState_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x10 / 4] = 0;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)UrbzCreditsState_vtable;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
}

// UrbzCreditsState::IsFlowStateRequestPending(void)
// 0x8009b1c0 - 36 bytes
static int UrbzCreditsState_IsFlowStateRequestPending(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    return TheSimsStateMachine_IsFlowStateRequestPending(owner);
}

// UrbzCreditsState::GetFlowStateRequest(void)
// 0x8009b1e4 - 36 bytes
static int UrbzCreditsState_GetFlowStateRequest(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    return TheSimsStateMachine_GetFlowStateRequest(owner);
}

// UrbzCreditsState::SetFlowStateCurrent(void)
// 0x8009b208 - 36 bytes
static void UrbzCreditsState_SetFlowStateCurrent(void* self) {
    void* owner = ((void**)self)[0x08 / 4];
    TheSimsStateMachine_SetFlowStateCurrent(owner);
}

// ============================================================================
// urbzmode.obj functions
// ============================================================================

// UrbzModeNewGameState::Reset(void)
// 0x8009b258 - 48 bytes
// Resets stage counter and calls UrbzResetSomething
static void UrbzModeNewGameState_Reset(void* self) {
    ((int*)self)[0x0C / 4] = 0;
    UrbzResetSomething(g_pSomePtr);
}

// UrbzModeNewGameState::UrbzModeNewGameState(int)
// 0x8009b6dc - 56 bytes
static void UrbzModeNewGameState_ctor(void* self, int stateId) {
    int* p = (int*)self;
    p[0x00 / 4] = stateId;
    p[0x0C / 4] = -1;
    p[0x10 / 4] = 0;
    p[0x14 / 4] = 1;
    p[0x18 / 4] = (int)UrbzModeNewGameState_vtable;
    p[0x04 / 4] = -1;
    p[0x08 / 4] = 0;
}

// ============================================================================
// startscreen.obj functions (StartScreenStartState)
// These are in .text2 section (0x803a1xxx range)
// ============================================================================

// StartScreenStartState::IsFlowStateRequestPending(void)
// 0x803a1524 - 40 bytes
// Double indirection: self->offset8->offset8 = TheSimsStateMachine
static int StartScreenStartState_IsFlowStateRequestPending(void* self) {
    void* pOuter = ((void**)self)[0x08 / 4];
    void* pOwner = ((void**)pOuter)[0x08 / 4];
    return TheSimsStateMachine_IsFlowStateRequestPending(pOwner);
}

// StartScreenStartState::GetFlowStateRequest(void)
// 0x803a154c - 40 bytes
static int StartScreenStartState_GetFlowStateRequest(void* self) {
    void* pOuter = ((void**)self)[0x08 / 4];
    void* pOwner = ((void**)pOuter)[0x08 / 4];
    return TheSimsStateMachine_GetFlowStateRequest(pOwner);
}

// StartScreenStartState::SetFlowStateCurrent(void)
// 0x803a1574 - 40 bytes
static void StartScreenStartState_SetFlowStateCurrent(void* self) {
    void* pOuter = ((void**)self)[0x08 / 4];
    void* pOwner = ((void**)pOuter)[0x08 / 4];
    TheSimsStateMachine_SetFlowStateCurrent(pOwner);
}

// ============================================================================
// Destructors (all follow same pattern: set base vtable, conditionally free)
// These are all in .text2 section
// ============================================================================

// Generic destructor pattern:
// 1. Set vtable to StateMachineState base vtable at offset 0x18
// 2. If r4 & 1 (destructor flag), call operator delete
// All destructors below follow this exact pattern.

// CreateASimBaseState::~CreateASimBaseState(void)
// 0x803a0978 - 52 bytes
static void CreateASimBaseState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// InteractorModule::Interactor::InteractorParams::~InteractorParams(void)
// 0x803a09ac - 52 bytes
// Note: vtable stored at offset 0x10, not 0x18
static void InteractorParams_dtor(void* self, int flags) {
    // Uses different vtable address: 0x8045d6c0
    extern void* InteractorParams_vtable[]; // 0x8045d6c0
    ((void**)self)[0x10 / 4] = (void*)InteractorParams_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// LiveModeInitState::~LiveModeInitState(void)
// 0x803a09e0 - 52 bytes
static void LiveModeInitState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// ChangeHouseDemolishHouse::~ChangeHouseDemolishHouse(void)
// 0x803a0aa4 - 52 bytes
static void ChangeHouseDemolishHouse_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// ChangeHouseSaveHouse::~ChangeHouseSaveHouse(void)
// 0x803a0ad8 - 52 bytes
static void ChangeHouseSaveHouse_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// ChangeHouseUnloadHouse::~ChangeHouseUnloadHouse(void)
// 0x803a0b0c - 52 bytes
static void ChangeHouseUnloadHouse_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// ChangeHouseLoadHouse::~ChangeHouseLoadHouse(void)
// 0x803a0b40 - 52 bytes
static void ChangeHouseLoadHouse_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// LoadingScreenWaitingForLoadState::~LoadingScreenWaitingForLoadState(void)
// 0x803a0c3c - 52 bytes
static void LoadingScreenWaitingForLoadState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// LoadingScreenFadeInState::~LoadingScreenFadeInState(void)
// 0x803a0c70 - 52 bytes
static void LoadingScreenFadeInState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// LoadingScreenUpdateState::~LoadingScreenUpdateState(void)
// 0x803a0ca4 - 52 bytes
static void LoadingScreenUpdateState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// LoadingScreenFadeOutState::~LoadingScreenFadeOutState(void)
// 0x803a0cd8 - 52 bytes
static void LoadingScreenFadeOutState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// PreGameState::~PreGameState(void)
// 0x803a0d58 - 52 bytes
static void PreGameState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// PreGameCasPlayer1State::~PreGameCasPlayer1State(void)
// 0x803a0d8c - 52 bytes
static void PreGameCasPlayer1State_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// PreGameCasPlayer2State::~PreGameCasPlayer2State(void)
// 0x803a0dc0 - 52 bytes
static void PreGameCasPlayer2State_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// PreGameCreateAFamilyState::~PreGameCreateAFamilyState(void)
// 0x803a0df4 - 52 bytes
static void PreGameCreateAFamilyState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// InLevelCreateASimState::~InLevelCreateASimState(void)
// 0x803a0e28 - 52 bytes
static void InLevelCreateASimState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// PreGameFreeplayState::~PreGameFreeplayState(void)
// 0x803a0e5c - 52 bytes
static void PreGameFreeplayState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// StartScreenStartState::~StartScreenStartState(void)
// 0x803a0f20 - 52 bytes
static void StartScreenStartState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// TheSimsNGCLicenseState::~TheSimsNGCLicenseState(void)
// 0x8009ae18 - 52 bytes
static void TheSimsNGCLicenseState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// TheSimsMemCardCheckState::~TheSimsMemCardCheckState(void)
// 0x8009ae84 - 52 bytes
static void TheSimsMemCardCheckState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// TheSimsEAMovieState::~TheSimsEAMovieState(void)
// 0x8009aef4 - 52 bytes
static void TheSimsEAMovieState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// TheSimsMaxisLogoState::~TheSimsMaxisLogoState(void)
// 0x8009af84 - 52 bytes
static void TheSimsMaxisLogoState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// TheSimsSimsIntroMovieState::~TheSimsSimsIntroMovieState(void)
// 0x8009aff4 - 52 bytes
static void TheSimsSimsIntroMovieState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// TheSimsEnterMainMenuState::~TheSimsEnterMainMenuState(void)
// 0x8009b064 - 52 bytes
static void TheSimsEnterMainMenuState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// UrbzCreditsState::~UrbzCreditsState(void)
// 0x803a18f4 - 52 bytes
static void UrbzCreditsState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}

// UrbzModeNewGameState::~UrbzModeNewGameState(void)
// 0x803a1a04 - 52 bytes
static void UrbzModeNewGameState_dtor(void* self, int flags) {
    ((void**)self)[0x18 / 4] = (void*)StateMachineState_base_vtable;
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}
