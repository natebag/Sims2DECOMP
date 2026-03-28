// thesims_large.cpp - TheSimsStateMachine and related large functions (257-512 bytes)
// Object file: thesims.obj
// 14 functions total

#include "core/statemachine.h"

// External functions
extern "C" {
    void* operator_new_wrapper(unsigned int size);   // 0x802d11b0
    void operator_delete_wrapper(void* ptr);         // 0x802d1220

    // EAHeap init functions (called in startup sequences)
    void EAHeap_GetMainHeap(void);      // 0x802cfe64
    void EAHeap_SetActive(void);        // 0x802d0e28
    void EAHeap_GetMovieHeap(void);     // 0x802cff00
    void EAHeap_GetResourceHeap(void);  // 0x802cffa0
    void EAHeap_GetVMHeap(void);        // 0x802d021c
    void EAHeap_GetDebugHeap(void);     // 0x802d0040
    void EAHeap_Init1(void);            // 0x802d02cc
    void EAHeap_Init2(void);            // 0x802d037c
    void EAHeap_Init3(void);            // 0x802d042c
    void EAHeap_Init4(void);            // 0x802d04dc
    void EAHeap_Init5(void);            // 0x802d058c
    void EAHeap_Init6(void);            // 0x802d062c
    void EAHeap_Init7(void);            // 0x802d00e0
    void EAHeap_Init8(void);            // 0x802d017c
    void EAHeap_InitAll(void);          // 0x802d09ac

    // APT/UI functions
    void AptInit(void* aptData);                     // 0x8003d824
    void AptGetSomething(void* aptData);             // 0x8003e5b4
    void AptCleanup(void* aptData);                  // 0x8003d7c8
    void AptMovieFunc(void* p);                      // 0x8003d6a0
    void AptMovieFunc2(void* p);                     // 0x8003d788
    void AptReset(void* p);                          // 0x8003d7c8
    void AptSetup(void* p);                          // 0x8003b22c

    // Dataset functions
    void DatasetManager_AddRef(void* mgr, int hash); // 0x80326cf8
    void DatasetManager_RemoveRef(void* mgr, int hash); // 0x8032710c
    void DatasetManager_LookupByHash(void* p, int h); // 0x80326db4

    // EApp functions
    void EApp_PlayMovie(void* app, unsigned int id, int a, int b); // 0x802e26f0
    int EApp_IsMovieStarting(void* app);             // 0x802e2710
    int EApp_IsMoviePlaying(void* app);              // 0x802e2734
    int EApp_StopMovie(void* app);                   // 0x802e2710

    // Render functions
    void Renderer_SomeSetup(void* p);                // 0x80085ebc
    void Renderer_SetBG(void* p, int, int, void*);   // 0x8008507c
    void Renderer_SetAlpha(void* p, float, int, int); // 0x800850f8
    void Renderer_SetMode(void* p, int, int, int);   // 0x80085148
    void Renderer_SetCoords(void* p, int, int, void*); // 0x8008517c
    void Renderer_Draw(void* p, void*);              // 0x80086994
    void Renderer_DrawEnd(void* p, void*);           // 0x80086994

    // Movie/splash screen
    int SplashScreen_Init(void);                     // 0x8008698c
    void SplashScreen_FormatStr(void* out, void* fmtData, void* p); // 0x8003fd34

    // Loading screen
    void LoadingScreen_ChangeHouse(int mode);        // 0x80090d58

    // WorldMap
    void WorldMap_Init(void*);                       // 0x800998c8 (WorldMap::WorldMap)
    void WorldMap_Reset(void*);                      // 0x80099c44
    void WorldMap_Destroy(void*);                    // 0x80099aa8

    // StateMachine helpers
    void StateMachine_OwnerSetNextState(void*, float, int); // 0x80095aa4
    void StateMachine_GetTimeInState(void*);         // 0x800961b4

    // Misc
    void SomeRenderer_Setup(void*);                  // 0x80328e7c
    void DatasetSetSomething(void*, void*, int, int); // 0x80326cf8
    void AptSomeFunc(void*, int);                    // 0x803235cc
    void CameraSetup(void*);                         // 0x801c49c0
    void EAnimController_Init(void*);                // 0x802e77a4
    void EAnimController_Shutdown(void*, int);       // 0x802e7884
    void SomeNGHFunc(void*, int);                    // 0x802e6818
    void SomeOtherFunc(void*);                       // 0x800169e8
    void SomeFunc3(void*);                           // 0x80017070
    void SomeFunc4(void*);                           // 0x80017490
    void SomeInitFunc5(void*);                       // 0x80016a1c
    void SomeMovieFunc6(void*, int);                 // 0x800164d4
    void* GrabSomeSDAPtr(void);                      // 0x80011e1c
    void SomeResetFunc(void*);                       // 0x803082c4
    void CarInitFunc(void*);                         // 0x800d4258
    void DrawRoad2D(void* worldMap, void* rc);       // from disasm
    void SomeRenderCall(void*, void*, int);          // 0x8001b038
    void SomeRenderCall2(void*, int, int, int);      // 0x8001d368
    void CameraZoomThing(void*, void*, int);         // from vtable calls
    void SetupCamera2(void*, float);                 // 0x80237784
    void CameraFunc3(void*);                         // 0x80236f74
    void CameraFunc4(void*);                         // 0x80236f50
    void CameraFunc5(void*);                         // 0x802343a0
    void SomeFunc7(int);                             // 0x8022921c
    void SomeAptCall(void*, void*);                  // 0x8003fa24
    void SetLoadState(void*);                        // 0x80234c98
    void CameraInit(void*);                          // 0x80236ca8
    void SomeVtblFunc(void* obj, void* rc, int flag); // various vtable calls
    void SetDataPtr(void*, int, int);                // 0x80323724
    void SetSomeGlobal(void*, void*);                // 0x8032466c
    void StateMachine_BaseCtor(void*);               // 0x8039bf3c
}

// SDA globals
extern "C" {
    extern void* g_pEApp;           // 0x80475b84 (lis r3, -32697; addi r3, 0x5b84)
    extern void* g_pESimsApp;       // 0x80475dcc
    extern void* g_pAptData;        // r13 - 0x9864 (r13-26524)
    extern void* g_pInputMgr;       // r13 - 0x67A4
    extern void* g_pRenderer;       // r13 - 0x587C
    extern void* g_pEngine;         // r13 - 0x6790
    extern int g_moviePlaying;      // r13 - 0x6EF8
    extern int g_moviePending;      // r13 - 0x6EF4
    extern void* g_pCarManager;     // r13 - 0x7D38
    extern void* g_pWorldMap;       // r13 - 0x602C (r13-24620)
    extern void* g_pTheSimsMainMenuState; // r13 - 0x6030
}

// ============================================================================
// TheSimsNGCLicenseState::Startup(void)
// Address: 0x80096b90
// Size: 352 bytes (0x160)
// NON_MATCHING - heap init sequence, APT setup, string literal encoding
//
// Initializes all heaps, sets up APT UI system, creates license state strings.
// The string "License by Nintendo" is stored as shorts at member offsets.
// ============================================================================
void TheSimsNGCLicenseState_Startup(void* self) {
    // Initialize 14 heaps (pairs of get+activate)
    EAHeap_GetMainHeap(); EAHeap_SetActive();
    EAHeap_GetMovieHeap(); EAHeap_SetActive();
    EAHeap_GetResourceHeap(); EAHeap_SetActive();
    EAHeap_GetVMHeap(); EAHeap_SetActive();
    EAHeap_GetDebugHeap(); EAHeap_SetActive();
    EAHeap_Init1(); EAHeap_SetActive();
    EAHeap_Init2(); EAHeap_SetActive();
    EAHeap_Init3(); EAHeap_SetActive();
    EAHeap_Init4(); EAHeap_SetActive();
    EAHeap_Init5(); EAHeap_SetActive();
    EAHeap_Init6(); EAHeap_SetActive();
    EAHeap_Init7(); EAHeap_SetActive();
    EAHeap_Init8(); EAHeap_SetActive();
    EAHeap_InitAll();

    // Initialize APT UI system
    // AptInit(0x80475b84)
    // Get APT handle, register with dataset manager
    // Store dataset ref at this+0x1c

    // Store float constant at this+0x4c (timer value)
    // Store "License by Nintendo" as shorts at member offsets 0x20-0x48
    // Characters: L, i, c, e, n, s, e, space, b, y, space, N, i, n, t, e, n, d, o, NULL
}

// ============================================================================
// TheSimsEAMovieState::Startup(void)
// Address: 0x800971c8
// Size: 288 bytes (0x120)
// NON_MATCHING - heap init, vtable dispatch, SDA globals
//
// Initializes heaps, loads EA movie settings, starts EA logo movie.
// ============================================================================
void TheSimsEAMovieState_Startup(void* self) {
    // Same 14-heap init sequence
    EAHeap_GetMainHeap(); EAHeap_SetActive();
    EAHeap_GetMovieHeap(); EAHeap_SetActive();
    EAHeap_GetResourceHeap(); EAHeap_SetActive();
    EAHeap_GetVMHeap(); EAHeap_SetActive();
    EAHeap_GetDebugHeap(); EAHeap_SetActive();
    EAHeap_Init1(); EAHeap_SetActive();
    EAHeap_Init2(); EAHeap_SetActive();
    EAHeap_Init3(); EAHeap_SetActive();
    EAHeap_Init4(); EAHeap_SetActive();
    EAHeap_Init5(); EAHeap_SetActive();
    EAHeap_Init6(); EAHeap_SetActive();
    EAHeap_Init7(); EAHeap_SetActive();
    EAHeap_Init8(); EAHeap_SetActive();
    EAHeap_InitAll();

    // Virtual dispatch to set movie volume (vtable offset 0x60/0x64)
    // Check if g_moviePlaying (0x80476208) is set
    // If so, transition to next state (id=3) with delay
    // Otherwise, clear movie flags, set flag at this+0x1c=1
    // Play EA movie via EApp::PlayMovie
    // Reset APT data
}

// ============================================================================
// TheSimsMaxisLogoState::Reset(void)
// Address: 0x80097864
// Size: 292 bytes (0x124)
// NON_MATCHING - renderer setup calls, float constant loading
//
// Resets the Maxis logo splash screen state: loads splash image,
// sets up renderer with alpha/position/mode parameters.
// ============================================================================
void TheSimsMaxisLogoState_Reset(void* self) {
    // Load splash screen: SplashScreen_Init(this+0x1c)
    // Get renderer at this+0x20, set OR flag bit 0x01 on +0x04
    // Call renderer setup: Renderer_SomeSetup
    // Format string for texture path
    // Set background with Renderer_SetBG(renderer, 0, 0, texturePtr)
    // Set alpha with float constant: Renderer_SetAlpha(renderer, alpha, 0, 0)
    // Set mode: Renderer_SetMode(renderer, 0, 0, 5)
    // Set coordinates with two float pairs from rodata
    // Set timer struct at this+0x24: flags, duration, etc.
    // Store fade speed float at renderer+0x30
    void* renderer = *(void**)((char*)self + 0x20);
    (void)renderer;
}

// ============================================================================
// TheSimsMaxisLogoState::Update(float)
// Address: 0x80097988
// Size: 364 bytes (0x16C)
// NON_MATCHING - complex fade timer logic with float comparisons
//
// Updates Maxis logo fade animation. Handles fade-in, hold, fade-out phases.
// Transitions to next state when complete.
// ============================================================================
void TheSimsMaxisLogoState_Update(void* self, float dt) {
    // Timer struct at self+0x24
    // Check flags for active timer (bit 0x10)
    // If timer active: subtract dt from duration
    // When expired: transition phases (fade-in -> hold -> fade-out)
    // Phase 1 (bit 0x01): transition to phase 2 (bit 0x04)
    // Phase 2 (bit 0x02): transition to phase 3 (bit 0x08)
    // Update renderer alpha based on phase
    // Phase 0x01/0x02: alpha = (maxTime - curTime) * blendFactor
    // Phase 0x08: set alpha to 0, transition to next state (id=4)
    // After timer expires, check movie state and transition accordingly
    (void)self;
    (void)dt;
}

// ============================================================================
// TheSimsMaxisLogoState::Draw(ERC *)
// Address: 0x80097af4
// Size: 260 bytes (0x104)
// NON_MATCHING - renderer vtable dispatch, coordinate setup
//
// Draws the Maxis logo splash screen with proper camera setup.
// ============================================================================
void TheSimsMaxisLogoState_Draw(void* self, ERC* pRC) {
    // Get global Sims app (0x80475ec8)
    // Get camera at app+0x14, check for camera chain
    // Call renderer draw through vtable (offset 0xF0)
    // Set up camera coordinates from float constants in rodata
    // Call renderer draw end
    (void)self;
    (void)pRC;
}

// ============================================================================
// TheSimsSimsIntroMovieState::Startup(void)
// Address: 0x80097bf8
// Size: 332 bytes (0x14C)
// NON_MATCHING - heap init, vtable dispatch for movie playback
//
// Same heap init sequence, sets up Sims intro movie playback.
// ============================================================================
void TheSimsSimsIntroMovieState_Startup(void* self) {
    // Same 14-heap init + EAHeap_InitAll
    EAHeap_GetMainHeap(); EAHeap_SetActive();
    EAHeap_GetMovieHeap(); EAHeap_SetActive();
    EAHeap_GetResourceHeap(); EAHeap_SetActive();
    EAHeap_GetVMHeap(); EAHeap_SetActive();
    EAHeap_GetDebugHeap(); EAHeap_SetActive();
    EAHeap_Init1(); EAHeap_SetActive();
    EAHeap_Init2(); EAHeap_SetActive();
    EAHeap_Init3(); EAHeap_SetActive();
    EAHeap_Init4(); EAHeap_SetActive();
    EAHeap_Init5(); EAHeap_SetActive();
    EAHeap_Init6(); EAHeap_SetActive();
    EAHeap_Init7(); EAHeap_SetActive();
    EAHeap_Init8(); EAHeap_SetActive();
    EAHeap_InitAll();

    // Check ESimsApp movie/apt state
    // If movie or apt asset loaded, transition to next state (id=5)
    // Otherwise: clear movie flags, set this+0x24=1, play Sims intro movie
    // Set next state transition with delay
    // Clear this+0x20=0, call AptReset
}

// ============================================================================
// TheSimsSimsIntroMovieState::Update(float)
// Address: 0x80097d8c
// Size: 356 bytes (0x164)
// NON_MATCHING - movie playback state machine with float timer
//
// Updates intro movie state. Monitors movie playback, handles timer-based
// fade, transitions to main menu when complete.
// ============================================================================
void TheSimsSimsIntroMovieState_Update(void* self, float dt) {
    // Set up APT color rects from rodata float constants
    // Call SetDataPtr through g_pAptData (r13-26524)
    // Check this+0x20 flag
    // If set: monitor renderer state, compute fade alpha
    // Clamp alpha to [0.0, 1.0] range
    // Virtual dispatch to set alpha on renderer
    // Check if fade expired -> stop movie via EApp_StopMovie
    // Check if movie starting or playing
    // If neither: transition to next state (id=5) with delay 0.0
    (void)self;
    (void)dt;
}

// ============================================================================
// TheSimsEnterMainMenuState::Startup(void)
// Address: 0x80098058
// Size: 292 bytes (0x124)
// NON_MATCHING - double heap init, renderer vtable dispatch
//
// Initializes all heaps twice (28 heap calls), sets up renderer,
// loads main menu dataset.
// ============================================================================
void TheSimsEnterMainMenuState_Startup(void* self) {
    // First pass: 14 heap init pairs
    EAHeap_GetMainHeap(); EAHeap_SetActive();
    EAHeap_GetMovieHeap(); EAHeap_SetActive();
    EAHeap_GetResourceHeap(); EAHeap_SetActive();
    EAHeap_GetVMHeap(); EAHeap_SetActive();
    EAHeap_GetDebugHeap(); EAHeap_SetActive();
    EAHeap_Init1(); EAHeap_SetActive();
    EAHeap_Init2(); EAHeap_SetActive();
    EAHeap_Init3(); EAHeap_SetActive();
    EAHeap_Init4(); EAHeap_SetActive();
    EAHeap_Init5(); EAHeap_SetActive();
    EAHeap_Init6(); EAHeap_SetActive();
    EAHeap_Init7(); EAHeap_SetActive();
    EAHeap_Init8(); EAHeap_SetActive();
    EAHeap_InitAll();

    // Second pass: same 14 heap init pairs again
    EAHeap_GetMainHeap(); EAHeap_SetActive();
    EAHeap_GetMovieHeap(); EAHeap_SetActive();
    EAHeap_GetResourceHeap(); EAHeap_SetActive();
    EAHeap_GetVMHeap(); EAHeap_SetActive();
    EAHeap_GetDebugHeap(); EAHeap_SetActive();
    EAHeap_Init1(); EAHeap_SetActive();
    EAHeap_Init2(); EAHeap_SetActive();
    EAHeap_Init3(); EAHeap_SetActive();
    EAHeap_Init4(); EAHeap_SetActive();
    EAHeap_Init5(); EAHeap_SetActive();
    EAHeap_Init6(); EAHeap_SetActive();
    EAHeap_Init7(); EAHeap_SetActive();
    EAHeap_Init8(); EAHeap_SetActive();
    EAHeap_InitAll();

    // Renderer vtable call: set display mode (offset 0xE0/0xE4)
    // Load dataset: SetSomeGlobal(0x804b5fd8, rodata_string)
    (void)self;
}

// ============================================================================
// TheSimsMainMenuState::Reset(void)
// Address: 0x80098728
// Size: 272 bytes (0x110)
// NON_MATCHING - complex initialization with multiple SDA globals
//
// Resets main menu state: initializes APT UI, world map, car manager,
// sets up dataset references and loading screen.
// ============================================================================
void TheSimsMainMenuState_Reset(void* self) {
    // Setup APT state
    // Initialize world map if null (allocate 0xDC bytes, call WorldMap_Init)
    // Otherwise set reset flags on existing world map
    // Set movie flags (r13-28408, r13-28404)
    // Load car manager if needed (allocate 0x194 bytes)
    // Initialize world map pointer (r13-24620)
    (void)self;
}

// ============================================================================
// WorldMap::WorldMap(void)
// Address: 0x800998c8
// Size: 480 bytes (0x1E0)
// NON_MATCHING - complex constructor with dataset lookups, memory allocation
//
// Constructs the world map object. Initializes all fields, loads datasets
// for map tiles and decorations, allocates memory for map grid.
// ============================================================================
void WorldMap_Constructor(void* self) {
    // Zero all fields 0x00-0x14
    int* fields = (int*)self;
    for (int i = 0; i < 6; i++) fields[i] = 0;

    // Initialize animation controller at this+0x18
    EAnimController_Init((char*)self + 0x18);

    // Initialize various floats and ints from rodata constants
    // Set dataset refs to 0, set this+0xD4=0, this+0xD8=1
    // Load float constants for camera params (this+0xBC, 0xC0, 0xC4)
    // Set int at this+0xC8

    // Load 4 datasets by hash:
    // 1. Hash 0xBAFAC2DB at address 0x80487e4c -> this+0x08
    // 2. Hash 0x695154B9 at address 0x804c945c -> this+0x0C
    // 3. Hash 0x05E6001D at address 0x804b2b38 -> this+0x10
    // 4. Hash 0x695154B9 at address 0x804b5298 -> this+0x14

    // Load APT dataset for world map
    // Load world map data name from APT

    // Allocate map grid: 1392 bytes (0x570), 16-byte aligned
    // memset to 0
    // Initialize map controller (SomeMovieFunc6)
    // Set up map controller properties
    // If this+0x08 exists, call WorldMap_Reset
    // Call SomeFunc7(0)
}

// ============================================================================
// WorldMap::~WorldMap(void)
// Address: 0x80099aa8
// Size: 412 bytes (0x19C)
// NON_MATCHING - complex destructor with dataset release, vtable dispatch
//
// Destroys world map: unloads datasets, frees animation controller,
// releases map grid memory.
// ============================================================================
void WorldMap_Destructor(void* self, int flags) {
    // Check this+0x08 (dataset loaded)
    if (*(int*)((char*)self + 0x08) == 0) goto skip_unload;

    // Call two global cleanup functions
    // Clean up map overlay if this+0x90 set
    // Virtual dtor call on overlay with flag=3

    // Clear engine state
    // Unload map from engine module

    // Release 4 datasets:
    // DatasetManager_RemoveRef for each loaded dataset hash

skip_unload:
    // Clean up animation controller at this+0x18
    // If this+0x04 (grid memory) exists:
    //   Virtual dtor call on grid with flag=3

    // Release map tile dataset
    // Shutdown animation controller

    // If flags & 1: delete this
    (void)self;
    (void)flags;
}

// ============================================================================
// WorldMap::Reset(void)
// Address: 0x80099c44
// Size: 444 bytes (0x1BC)
// NON_MATCHING - complex camera/rendering setup with many float constants
//
// Resets world map to initial state: positions camera, loads map data,
// initializes tile grid and camera parameters.
// ============================================================================
void WorldMap_ResetFunc(void* self) {
    // Clear this+0x00 flag
    // Store this+0x08 dataset into engine module
    // Store SDA global into map engine address

    // Initialize camera with float constants from rodata
    // Set up 3D position vector, look-at vector
    // Set camera parameters (zoom, angle, distance)

    // Initialize map grid from dataset
    // Call CameraInit, SetupCamera2, CameraFunc3, CameraFunc4, CameraFunc5

    // Set up map overlay if loaded
    (void)self;
}

// ============================================================================
// WorldMap::Draw(ERC *)
// Address: 0x8009a1d0
// Size: 360 bytes (0x168)
// NON_MATCHING - complex rendering with vtable dispatch, coordinate math
//
// Draws the world map: sets up camera, renders map tiles, renders overlay.
// ============================================================================
void WorldMap_DrawFunc(void* self, ERC* pRC) {
    // Check this+0x08 (dataset) and this+0x04 (grid)
    if (*(int*)((char*)self + 0x08) == 0) return;
    if (*(int*)((char*)self + 0x04) == 0) return;

    // Call SomeFunc4 on grid
    // Set up grid renderer via vtable dispatch
    // Call SetLoadState on map dataset

    // Check this+0xD4 overlay flag
    if (*(int*)((char*)self + 0xD4) == 0) return;

    // Get overlay dataset, navigate pointer chain
    // Vtable dispatch to draw overlay with render context
    // Set up 2D overlay coordinates from SDA globals
    // Apply scale/offset transforms
    // Vtable dispatch for final rendering
    (void)self;
    (void)pRC;
}

// ============================================================================
// TheSimsStateMachine::TheSimsStateMachine(int, int)
// Address: 0x8009acc4
// Size: 264 bytes (0x108)
// NON_MATCHING - complex constructor with many field initializations
//
// Constructs the main TheSimsStateMachine. Initializes all state machine
// fields, sets up vtable, status structs, and timer data.
// ============================================================================
void TheSimsStateMachine_Constructor(void* self, int machineId, int param2) {
    // Store machineId and param2
    *(int*)((char*)self + 0x00) = machineId;

    // Set vtable pointer (0x8045e100)
    *(void**)((char*)self + 0x18) = (void*)0x8045e100; // approximate

    // Store param2 at +0x1C
    *(int*)((char*)self + 0x1C) = param2;

    // Initialize many fields to 0 or defaults
    *(int*)((char*)self + 0x0C) = -1;
    *(int*)((char*)self + 0x04) = -1;
    *(int*)((char*)self + 0x08) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 1;  // enabled
    *(int*)((char*)self + 0x20) = 0;
    *(int*)((char*)self + 0x24) = 0;

    // Float constant for timer
    float timerInit = 0.0f;  // from rodata
    *(float*)((char*)self + 0x28) = timerInit;

    // Initialize sub-structs
    *(int*)((char*)self + 0x2C) = 0;
    *(int*)((char*)self + 0x34) = 0;
    *(int*)((char*)self + 0x3C) = 0;

    // Initialize status areas (3 StateMachineStatus-like areas)
    // Each has fields for timer, state ptr, flags
    char* status1 = (char*)self + 0x3C;
    *(int*)(status1 + 0x04) = 0;
    *(int*)(status1 + 0x08) = 0;
    *(int*)(status1 + 0x0C) = 0;
    *(float*)(status1 + 0x10) = timerInit;
    *(float*)(status1 + 0x14) = timerInit;

    char* status2 = (char*)self + 0x54;
    *(int*)(status2 + 0x04) = 0;
    *(int*)(status2 + 0x08) = 0;
    *(int*)(status2 + 0x0C) = 0;

    char* status3 = (char*)self + 0x64;
    *(int*)(status3 + 0x0C) = 0;
    *(int*)(status3 + 0x04) = 0;
    *(int*)(status3 + 0x08) = 0;

    char* status4 = (char*)self + 0x74;
    *(int*)(status4 + 0x04) = 0;

    char* status5 = (char*)self + 0x7C;
    *(int*)(status5 + 0x04) = 0;

    // Call base ctor
    StateMachine_BaseCtor(self);

    // Set updated vtable
    *(void**)((char*)self + 0x18) = (void*)0x8045e460;
    *(int*)((char*)self + 0x90) = 0;
    *(int*)((char*)self + 0x94) = 1;

    // Clear final fields
    *(int*)((char*)self + 0x84) = 0;
    *(int*)((char*)self + 0x88) = 0;
    *(int*)((char*)self + 0x8C) = 0;
}
