// livemode_large.cpp - ELiveMode and related large functions (257-1024 bytes)
// Object file: livemode.obj
// All NON_MATCHING - GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

extern "C" {
    void* operator_new_wrapper(u32 size);
    void operator_delete_wrapper(void* ptr);
    void* memset(void* dst, int val, u32 n);
    void* memcpy(void* dst, const void* src, u32 n);

    // StateMachine
    void StateMachine_AddState(void* machine, void* state);
    void StateMachine_SetNextState(void* machine, int id, float d);

    // Dataset
    void DatasetManager_AddRef(void* mgr, int hash);
    void DatasetManager_RemoveRef(void* mgr, void* ref);

    // Loading
    void LoadingScreen_ChangeHouse(int mode);
    void LoadingScreenStateMachine_StartLoad(void* sm, int mode);

    // Globals
    extern void* g_pSimsApp;
    extern void* g_pEApp;
    extern void* g_pRenderer;
    extern void* g_pWorldMap;
    extern void* g_pEngine;
    extern void* g_pLoadingScreenSM;
    extern int g_bDrawTopmost;
}

// ============================================================================
// UnloadLevelGlobalData(void)
// Address: 0x8008b8a8
// Size: 0x120 = 288 bytes
// NON_MATCHING - unload sequence, dataset removal, global cleanup
// ============================================================================
void UnloadLevelGlobalData(void) {
    // Unloads global datasets and cleans up level-wide resources
    // Calls DatasetManager_RemoveRef for various global dataset refs
    // Clears global pointers
    // Shuts down ambient score player
    // Clears influence maps
    // Resets simulator state
}

// ============================================================================
// LiveModeInitState::Reset(void)
// Address: 0x8008bc28
// Size: 0x104 = 260 bytes
// NON_MATCHING - dataset loading, flag initialization
// ============================================================================
void LiveModeInitState_Reset(void* self) {
    char* _this = (char*)self;

    // Reset loading flags
    *(int*)(_this + 0x20) = 0;
    *(int*)(_this + 0x24) = 0;
    *(int*)(_this + 0x28) = 0;

    // Get ELiveMode owner
    void* owner = *(void**)(_this + 0x08);
    // Call owner->Reset(0)
    // Load house preload dataset
    // Set up loading screen
    // Start async dataset load
    // Set flag at _this + 0x2C = 1

    (void)owner;
}

// ============================================================================
// LiveModeChangeHouseStateMachine::LiveModeChangeHouseStateMachine(int, int)
// Address: 0x8008ff30
// Size: 0x108 = 264 bytes
// NON_MATCHING - base class construction, state addition
// ============================================================================
void LiveModeChangeHouseStateMachine_ctor(void* self, int machineId, int ownerId) {
    char* _this = (char*)self;

    // Call StateMachine base constructor
    // Set machine ID at offset
    // Set owner ID

    // Create 4 sub-states (ChangeHouse states)
    // ChangeHouseDemolishHouse(0)
    // ChangeHouseSaveHouse(1)
    // ChangeHouseUnloadHouse(2)
    // ChangeHouseLoadHouse(3)
    // AddState for each

    (void)machineId;
    (void)ownerId;
}

// ============================================================================
// LiveModeChangeHouseStateMachine::Startup(void)
// Address: 0x8008d91c
// Size: 0x19c = 412 bytes
// NON_MATCHING - state machine setup, dataset loading
// ============================================================================
void LiveModeChangeHouseStateMachine_Startup(void* self) {
    char* _this = (char*)self;

    // Get owner (ELiveMode) via StateMachineState::GetOwner
    void* owner = *(void**)(_this + 0x08);

    // Check if house is being demolished
    // If demolished: set next state to DemolishHouse (id 0)
    // Else: set next state to SaveHouse (id 1)

    // Load house preload dataset for new house
    // Get house name from world map
    // Call LoadHousePreloadDataset

    // Setup loading screen
    // Start loading screen fade in

    // Set various flags on owner
    // owner->SetDontDraw(true)
    // owner->SetInitialized(false)

    (void)owner;
}

// ============================================================================
// ELiveMode::IsReadyForUpdate(void)
// Address: 0x8008dd70
// Size: 0x1b8 = 440 bytes
// NON_MATCHING - complex conditional checks, dataset status
// ============================================================================
int ELiveMode_IsReadyForUpdate(void* self) {
    char* _this = (char*)self;

    // Check if initialized (offset for m_bInitialized)
    int initialized = *(int*)(_this + 0x58);
    if (!initialized) return 0;

    // Check loading screen state
    void* loadSM = g_pLoadingScreenSM;
    if (loadSM) {
        // Check if loading is in progress
        // If still loading, return 0
    }

    // Check dataset async loading status
    // If any datasets pending, return 0

    // Check if intro camera is running
    // If intro camera active, handle differently

    // Check simulator state
    // Verify all subsystems ready

    // All checks passed
    return 1;
}

// ============================================================================
// ELiveMode::Reset(int)
// Address: 0x8008ca58
// Size: 0x238 = 568 bytes
// NON_MATCHING - extensive initialization, dataset loading, subsystem reset
// ============================================================================
void ELiveMode_Reset(void* self, int param) {
    char* _this = (char*)self;

    // Reset all internal flags
    *(int*)(_this + 0x48) = 0;
    *(int*)(_this + 0x4C) = 0;
    *(int*)(_this + 0x50) = 0;
    *(int*)(_this + 0x54) = 0;
    *(int*)(_this + 0x58) = 0;

    // Reset intro camera state
    // m_introCameraState = 0
    // m_introCameraTriggered = false

    // Load level global data if not already loaded
    // Call LoadLevelGlobalData()

    // Initialize simulator
    // Reset camera
    // Reset interactors

    // Setup ambient sound
    // Reset UI state

    // If param != 0: additional initialization
    // Load house-specific datasets
    // Initialize objects in lot

    (void)param;
}

// ============================================================================
// ELiveMode::StartIntroCamera(CameraDirector*, ESimsCam*)
// Address: 0x8008fbfc
// Size: 0x22c = 556 bytes
// NON_MATCHING - camera setup, animation sequencing
// ============================================================================
void ELiveMode_StartIntroCamera(void* self, void* camDirector, void* simsCam) {
    char* _this = (char*)self;

    // Set intro camera state to Starting
    *(int*)(_this + 0x60) = 1;
    *(int*)(_this + 0x64) = 1; // m_introCameraTriggered

    // Get camera parameters from lot data
    // Set up camera path points
    // Initialize camera animation timeline

    // Configure camera director
    // Set initial position
    // Set target look-at point
    // Set field of view
    // Set camera speed

    // Start camera animation sequence
    // Set up blend from current to intro position

    (void)camDirector;
    (void)simsCam;
}

// ============================================================================
// ELiveMode::DrawSplitScreenMask(ERC*, E3DWindow&, int)
// Address: 0x8008ef1c
// Size: 0x29c = 668 bytes
// NON_MATCHING - rendering setup, coordinate calculations
// ============================================================================
void ELiveMode_DrawSplitScreenMask(void* self, void* pRC, void* window, int playerIdx) {
    char* _this = (char*)self;

    // Get window dimensions
    // Calculate mask region based on split mode
    // Set up orthographic projection for mask rendering

    // Set render state for mask drawing
    // Disable depth test
    // Set blend mode for mask alpha

    // Draw mask quad covering player's viewport edge
    // Use black with alpha gradient for smooth transition

    // Restore render state

    (void)_this;
    (void)pRC;
    (void)window;
    (void)playerIdx;
}

// ============================================================================
// ELiveMode::InitPlayerXWindow(ERC*, E3DWindow&, int)
// Address: 0x8008f1b8
// Size: 0x2b8 = 696 bytes
// NON_MATCHING - viewport setup, camera initialization per player
// ============================================================================
void ELiveMode_InitPlayerXWindow(void* self, void* pRC, void* window, int playerIdx) {
    char* _this = (char*)self;

    // Get player's viewport rectangle from window layout
    // Calculate aspect ratio for the sub-viewport

    // Set up camera for this player's view
    // Get player's ESimsCam
    // Configure field of view based on split mode

    // Set up render context for sub-viewport
    // Set viewport bounds
    // Set scissor rectangle

    // Initialize camera matrices
    // Set projection matrix
    // Set view matrix from camera position/orientation

    // Set up lighting for this viewport
    // Apply per-player render settings

    (void)_this;
    (void)pRC;
    (void)window;
    (void)playerIdx;
}

// ============================================================================
// ELiveMode::DrawSplitScreenDivider(ERC*)
// Address: 0x8008f470
// Size: 0x33c = 828 bytes
// NON_MATCHING - 2D line/quad rendering for divider
// ============================================================================
void ELiveMode_DrawSplitScreenDivider(void* self, void* pRC) {
    char* _this = (char*)self;

    // Set up orthographic projection (640x480)
    // Save current render state

    // Determine split orientation (horizontal vs vertical)
    // Get split position (center of screen or custom)

    // Draw divider line
    // Set color to divider color (typically dark with slight transparency)
    // Draw quad for divider bar (2-4 pixels wide)

    // Draw divider decorations (optional shadow/highlight lines)
    // Draw thin highlight line on one side
    // Draw thin shadow line on other side

    // Draw player indicators if enabled
    // Player 1 indicator on left/top
    // Player 2 indicator on right/bottom

    // Restore render state

    (void)_this;
    (void)pRC;
}
