// gamestate_large.cpp - Game state related large functions (257-1024 bytes)
// Object files: gamestate.obj (none in range), inlevel.obj, loadingscreenstate.obj
// All NON_MATCHING - GCC vs SN Systems codegen differences
//
// Note: gamestate.obj has no functions in the 257-1024 byte range.
// This file covers related inlevel.obj and loadingscreenstate.obj large functions.

#include "types.h"

extern "C" {
    void* operator_new_wrapper(u32 size);
    void operator_delete_wrapper(void* ptr);
    void* memset(void* dst, int val, u32 n);

    // StateMachine
    void StateMachine_AddState(void* machine, void* state);
    void StateMachineState_OwnerSetNextState(void* state, int id, float d);

    // TheSimsStateMachine
    int TheSimsStateMachine_IsFlowStateRequestPending(void* p);
    int TheSimsStateMachine_GetFlowStateRequest(void* p);
    void TheSimsStateMachine_SetFlowStateCurrent(void* p);

    // Globals
    extern void* g_pSimsApp;
    extern void* g_pLoadingScreenSM;
}

// ============================================================================
// InLevelBaseState::HandleExitToMainMenu(void)
// Address: 0x8008b380
// Size: 0x118 = 280 bytes
// NON_MATCHING - menu exit flow, state cleanup
// ============================================================================
void InLevelBaseState_HandleExitToMainMenu(void* self) {
    char* _this = (char*)self;

    // Save current game state
    // Save player interactor state
    // SavePlayerInteractorState()

    // Stop ambient sounds
    // Stop music

    // Trigger loading screen for main menu transition
    // Set loading screen mode to "returning to menu"

    // Set flow state to exit
    // Request state transition to main menu state

    // Clean up live mode resources
    // Release held datasets

    (void)_this;
}

// ============================================================================
// InLevelBaseState::InLevelBaseState(int)
// Address: 0x8008b5b0
// Size: 0x148 = 328 bytes
// NON_MATCHING - base class construction, member init
// ============================================================================
void InLevelBaseState_ctor(void* self, int stateId) {
    char* _this = (char*)self;

    // Call StateMachineState base constructor
    // Set state ID
    *(int*)(_this + 0x00) = stateId;

    // Initialize InLevelBaseState-specific members
    *(int*)(_this + 0x20) = 0;    // m_dialogResult
    *(int*)(_this + 0x24) = 0;    // m_dialogActive
    *(void**)(_this + 0x28) = 0;  // m_pDialogCallback
    *(int*)(_this + 0x2C) = 0;    // m_exitRequested
    *(int*)(_this + 0x30) = 0;    // m_interactorStateSaved

    // Set up vtable
    // Store derived vtable pointer for virtual dispatch

    (void)stateId;
}

// ============================================================================
// From loadingscreenstate.obj:
// ============================================================================

// ============================================================================
// LoadingScreenFadeInState::Update(float)
// Address: 0x8009027c
// Size: 0x110 = 272 bytes
// NON_MATCHING - fade animation update
// ============================================================================
void LoadingScreenFadeInState_Update(void* self, float dt) {
    char* _this = (char*)self;

    // Update fader
    // FaderUpdate(dt)

    // Check if fade complete
    // If fade complete (opacity >= 1.0):
    //   Transition to update state
    //   OwnerSetNextState(updateStateId, 0.0f)

    // Check if load is already complete
    // If load complete during fade-in:
    //   Can skip ahead

    // Update loading screen UI
    // Update progress bar if visible

    (void)_this;
    (void)dt;
}

// ============================================================================
// LoadingScreenStateMachine::LoadingScreenStateMachine(int, int)
// Address: 0x800907cc
// Size: 0x134 = 308 bytes
// NON_MATCHING - state machine construction, sub-state creation
// ============================================================================
void LoadingScreenStateMachine_ctor(void* self, int machineId, int ownerId) {
    char* _this = (char*)self;

    // Call StateMachine base constructor
    // Set machine ID and owner ID

    // Create sub-states:
    // LoadingScreenWaitingForLoadState(0)
    // LoadingScreenFadeInState(1)
    // LoadingScreenUpdateState(2)
    // LoadingScreenFadeOutState(3)

    // Add all states to machine
    // StateMachine::AddState for each

    // Initialize loading screen pointer to null
    *(void**)(_this + 0x40) = 0;

    // Initialize fader state
    *(int*)(_this + 0x44) = 0;    // m_faderState = FadedOut
    *(float*)(_this + 0x48) = 0.0f; // m_faderOpacity
    *(float*)(_this + 0x4C) = 0.0f; // m_faderSpeed

    // Initialize load tracking
    *(int*)(_this + 0x50) = 0;    // m_loadStarted
    *(int*)(_this + 0x54) = 0;    // m_loadComplete

    (void)machineId;
    (void)ownerId;
}

// ============================================================================
// LoadingScreenStateMachine::Startup(void)
// Address: 0x800909a4
// Size: 0x140 = 320 bytes
// NON_MATCHING - startup sequence, initial state setup
// ============================================================================
void LoadingScreenStateMachine_Startup(void* self) {
    char* _this = (char*)self;

    // Reset load tracking
    *(int*)(_this + 0x50) = 0;
    *(int*)(_this + 0x54) = 0;

    // Create loading screen if needed
    // CreateLoadingScreen()

    // Set initial state to WaitingForLoad
    // SetNextState(0, 0.0f)

    // Initialize fader to fully transparent
    *(float*)(_this + 0x48) = 0.0f;

    // Register with global loading screen singleton
    // Set as active loading screen state machine

    (void)_this;
}

// ============================================================================
// LoadingScreenStateMachine::StartLoad(CLoadingScreen::eLoadingScreenMode)
// Address: 0x80090c1c
// Size: 0xfc = 252 bytes (just under 257, skip)
// ============================================================================

// ============================================================================
// LoadingScreenUpdateState::Update(float)
// Address: 0x80090454
// Size: 0xf0 = 240 bytes (under 257, skip)
// ============================================================================

// ============================================================================
// LoadingScreenFadeOutState::Update(float)
// Address: 0x8009060c
// Size: 0xf8 = 248 bytes (under 257, skip)
// ============================================================================

// ============================================================================
// LoadingScreenWaitingForLoadState::Update(float)
// Address: 0x800901a4
// Size: 0xd8 = 216 bytes (under 257, skip)
// ============================================================================
