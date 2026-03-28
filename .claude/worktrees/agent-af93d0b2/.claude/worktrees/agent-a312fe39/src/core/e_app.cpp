// e_app.cpp - EApp, EAnimController, psystem, e_main, e_cheatmenu, e_frag, e_debugmenu small functions
// From: engine_ngc_release_dvd.lib
// Small functions (<=64 bytes) decompiled from these objects

#include "core/e_app.h"

// ============================================================================
// External references (SDA globals, called functions)
// ============================================================================

// SDA (r13-relative) globals
extern "C" {
    extern EApp* _pApp;                   // r13 - 0x68C8 = r13-26824
    extern int g_movieInError;            // r13 - 0x68C4 = r13-26820
    extern void* _pEngine;               // r13 - 0x6790 = r13-26512
    extern int _frameIndex;              // r13 - 0x68BC = r13-26812
    extern void* _pExitFunc;             // r13 - 0x6870 = r13-26736
    extern void* g_pParticleSystem;       // r13 - 0x589C = r13-22684
    extern void* g_pParticleWeatherSystem;// r13 - 0x58A0 = r13-22688
    extern void* g_pParticleModelSystem;  // r13 - 0x58A4 = r13-22692
    extern int _minRetraces;             // r13 - 0x68B4 = r13-26804
    extern void* _pRenderer;             // r13 - 0x587C = r13-22652
    extern void* _pInputMgr;             // r13 - 0x67A4 = r13-26532
    extern void* _pRC;                   // r13 - 0x6718 = r13-26392
}

// Called functions (external linkage)
extern "C" {
    void EApp_baseDestructor(EApp* app);                    // ~EStorableOrBase
    void EApp_baseCtor(void* obj);
    void EAHeap_GetMovieHeap(void);                         // at 0x802cff00
    void _ParticlePoolFree(void* pool, void* ptr);         // at 0x8036594c
    void _ParticlePoolClose(void* pool);                    // at 0x803658b4
    void _RingReset(void* ring);                            // at 0x80359f38
    void _RingInit(void* ring, unsigned int size);          // at 0x80359e0c
    void* _RingAlloc(void* ring, unsigned int size);        // at 0x80359e68
    void EController_BtnDataClear(void* data, int flags);   // at 0x80365a7c
    void EController_BtnDataUpdate(void* dst, void* src);   // at 0x80365b60
    void EController_BtnDataCopy(void* dst, void* src);     // at 0x80365c60
    unsigned int EController_ComputeExclMask(void* ctrl);   // at 0x80305700
    void _ParticleProcessType3Impl(pemitter* e, float dt);  // at 0x8030186c
}

// Vtable pointers (resolved at link time)
extern "C" void* EApp_vtable[];          // 0x8046a628
extern "C" void* EEngine_vtable_a120[];  // 0x8046a120
extern "C" void* EEngine_vtable_a708[];  // 0x8046a708
extern "C" void* EDebugMenuItem_vtable[];// 0x8046aeb8
extern "C" void* EFrameAllocGroup_vtable_a120[]; // re-use
extern "C" void* EFrameAllocGroup_vtable_aee8[]; // 0x8046aee8

// String constants
extern "C" const char* _buildVersionStr;   // "F.09.12.0" at rodata
extern "C" const char* _appNameStr;        // app name string at rodata
extern "C" const char _heapUseInfoName_DMA[];     // at rodata
extern "C" const char _heapUseInfoName_Texture[]; // at rodata
extern "C" const char _heapUseInfoName_Matrix[];  // at rodata
extern "C" const char _heapUseInfoName_System[];  // at rodata
extern "C" const char _heapUseInfoName_Dma2[];    // at rodata

// ============================================================================
// e_app.obj - EApp small functions (28 functions, ~26 code)
// ============================================================================

// EApp::~EApp - 0x802e21e0 (52 bytes)
// Resets vtable to base, clears _pApp SDA global, calls base dtor
EApp::~EApp() {
    *(void**)((char*)this + 0x338) = EApp_vtable;
    _pApp = 0;
    // calls base class destructor
}

// EApp::SetupForMovie - 0x802e24b0 (4 bytes)
// No-op virtual stub
void EApp::SetupForMovie(void) {
}

// EApp::CleanupAfterMovie - 0x802e24b4 (4 bytes)
// No-op virtual stub
void EApp::CleanupAfterMovie(void) {
}

// EApp::PlayMovie - 0x802e26f0 (32 bytes)
// Starts movie playback if id != 0
void EApp::PlayMovie(unsigned int id, int a, int b) {
    if (id == 0) return;
    *(int*)((char*)this + 0x464) = b;
    *(unsigned int*)((char*)this + 0x45C) = id;
    *(int*)((char*)this + 0x454) = 1;
    *(int*)((char*)this + 0x460) = a;
}

// EApp::StopMovie - 0x802e2710 (12 bytes)
// Clears movie sub-state to 0
void EApp::StopMovie(void) {
    *(int*)((char*)this + 0x454) = 0;
}

// EApp::IsMovieStarting - 0x802e271c (24 bytes)
// Returns 1 if movie sub-state == 1
int EApp::IsMovieStarting(void) {
    int state = *(int*)((char*)this + 0x454);
    // subfic r3,r3,1; li r3,0; adde r3,r3,r3
    // This is the PPC idiom for (state == 1)
    return (state == 1) ? 1 : 0;
}

// EApp::IsMoviePlaying - 0x802e2734 (24 bytes)
// Returns 1 if movie state == 2 (currently playing)
// NON_MATCHING - PPC uses subfic/adde idiom for == compare
int EApp::IsMoviePlaying(void) {
    int state = *(int*)((char*)this + 0x450);
    return (state == 2) ? 1 : 0;
}

// EApp::GetMovieHeap - 0x802e28f0 (32 bytes)
// Calls global function to get movie heap
EAHeap* EApp::GetMovieHeap(void) {
    EAHeap_GetMovieHeap();
    return 0; // return value comes from called function via r3
}

// EApp::GetRootDirectory - 0x802e2910 (12 bytes)
// Returns string from root dir ptr member
const char* EApp::GetRootDirectory(void) {
    void* ptr = *(void**)((char*)this + 0x470);
    return *(const char**)ptr;
}

// EApp::GetBuildVersion - 0x802e291c (12 bytes)
// Returns constant build version string pointer
const char* EApp::GetBuildVersion(void) {
    return _buildVersionStr;
}

// EApp::GetAppName - 0x802e2928 (12 bytes)
// Returns constant app name string pointer
const char* EApp::GetAppName(void) {
    return _appNameStr;
}

// EApp::GetPrefetchBlockSize - 0x802e2934 (8 bytes)
// Returns 0 (no prefetch)
int EApp::GetPrefetchBlockSize(void) {
    return 0;
}

// EApp::GetScratchBuffSize - 0x802e293c (8 bytes)
// Returns 0 (no scratch buffer)
int EApp::GetScratchBuffSize(void) {
    return 0;
}

// EApp::GetEventTableSize - 0x802e2944 (8 bytes)
// Returns 8
int EApp::GetEventTableSize(void) {
    return 8;
}

// EApp::GetFullArgString - 0x802e294c (8 bytes)
// Returns pointer to arg string at offset 0x350
const char* EApp::GetFullArgString(void) const {
    return (const char*)((char*)this + 0x350);
}

// EApp::GetGameState - 0x802e2954 (8 bytes)
OVERALL_GAME_STATE EApp::GetGameState(void) const {
    return *(OVERALL_GAME_STATE*)((char*)this + 0x468);
}

// EApp::SetGameState - 0x802e295c (8 bytes)
void EApp::SetGameState(OVERALL_GAME_STATE s) {
    *(OVERALL_GAME_STATE*)((char*)this + 0x468) = s;
}

// EApp::GetMenuOwner - 0x802e2964 (8 bytes)
OVERALL_GAME_STATE EApp::GetMenuOwner(void) const {
    return *(OVERALL_GAME_STATE*)((char*)this + 0x46C);
}

// EApp::SetMenuOwner - 0x802e296c (8 bytes)
void EApp::SetMenuOwner(OVERALL_GAME_STATE s) {
    *(OVERALL_GAME_STATE*)((char*)this + 0x46C) = s;
}

// EApp::ShowInitialDisplay - 0x802e2974 (4 bytes)
void EApp::ShowInitialDisplay(void) {
}

// EApp::Init - 0x802e2978 (4 bytes)
void EApp::Init(void) {
}

// EApp::Update - 0x802e297c (4 bytes)
void EApp::Update(void) {
}

// EApp::UpdateAfterHotSync - 0x802e2980 (4 bytes)
void EApp::UpdateAfterHotSync(void) {
}

// EApp::GetAppStackSize - 0x802e2984 (12 bytes)
// Returns 0x18000 (96KB)
int EApp::GetAppStackSize(void) {
    return 0x18000;
}

// EApp::Shutdown - 0x802e2990 (4 bytes)
void EApp::Shutdown(void) {
}

// ============================================================================
// e_engine.obj - EEngine small functions (24+ functions)
// ============================================================================

// EEngine::ManagedShutdown - 0x802e2b3c (12 bytes)
// Clears the engine pointer SDA global
void EEngine::ManagedShutdown(void) {
    _pEngine = 0;
}

// EEngine::Line - 0x802e2b48 (4 bytes)
// No-op
void EEngine::Line(void) {
}

// EEngine::PrintBanner - 0x802e3238 (4 bytes)
// No-op
void EEngine::PrintBanner(void) {
}

// EEngine::PrintConfiguration - 0x802e323c (4 bytes)
// No-op
void EEngine::PrintConfiguration(void) {
}

// EEngine::GetMinRetraces - 0x802e2e38 (24 bytes)
// Returns 1 if smoothing is disabled (field at +8 == 0), else returns _minRetraces
int EEngine::GetMinRetraces(void) {
    if (*(int*)((char*)this + 0x08) == 0) {
        return 1;
    }
    return _minRetraces;
}

// EEngine::ClearCurrentLevel - 0x802e37b8 (24 bytes)
// Clears current level if it matches the given pointer
void EEngine::ClearCurrentLevel(ERLevel* level) {
    if (*(ERLevel**)((char*)this + 0x30) != level) return;
    *(ERLevel**)((char*)this + 0x30) = 0;
}

// EEngine::Idle - 0x802e37d0 (4 bytes)
// Infinite loop (intentional hang for idle state)
// NON_MATCHING - can't produce b . in C++
void EEngine::Idle(void) {
    for (;;) {}
}

// EEngine::GetDMARingMemoryUseInfo - 0x802e37d4 (36 bytes)
// Fills HeapUseInfo with DMA ring info
void EEngine::GetDMARingMemoryUseInfo(HeapUseInfo* info) {
    info->total = 0;
    info->name = _heapUseInfoName_DMA;
    info->flags = 0;
    info->used = 0;
    info->free = 0;
}

// EEngine::GetTextureRingMemoryUseInfo - 0x802e37f8 (36 bytes)
void EEngine::GetTextureRingMemoryUseInfo(HeapUseInfo* info) {
    info->total = 0;
    info->name = _heapUseInfoName_Texture;
    info->flags = 0;
    info->used = 0;
    info->free = 0;
}

// EEngine::GetMatrixRingMemoryUseInfo - 0x802e381c (36 bytes)
void EEngine::GetMatrixRingMemoryUseInfo(HeapUseInfo* info) {
    info->total = 0;
    info->name = _heapUseInfoName_Matrix;
    info->flags = 0;
    info->used = 0;
    info->free = 0;
}

// EEngine::GetMemoryUseSystemInfo - 0x802e3840 (40 bytes)
// Same pattern but flags=1
void EEngine::GetMemoryUseSystemInfo(HeapUseInfo* info) {
    info->total = 0;
    info->name = _heapUseInfoName_System;
    info->flags = 1;
    info->used = 0;
    info->free = 0;
}

// EEngine::GetMemoryUseDmaInfo - 0x802e3868 (40 bytes)
// Same pattern but flags=1
void EEngine::GetMemoryUseDmaInfo(HeapUseInfo* info) {
    info->total = 0;
    info->name = _heapUseInfoName_Dma2;
    info->flags = 1;
    info->used = 0;
    info->free = 0;
}

// EEngine::EnableFrameRatePredictiveSmoothing - 0x802e38b8 (8 bytes)
void EEngine::EnableFrameRatePredictiveSmoothing(bool val) {
    *(int*)((char*)this + 0x08) = (int)val;
}

// EEngine::Reboot - 0x802e38c0 (4 bytes)
void EEngine::Reboot(void) {
}

// EEngine::SetCurrentLevel - 0x802e38c4 (8 bytes)
void EEngine::SetCurrentLevel(ERLevel* level) {
    *(ERLevel**)((char*)this + 0x30) = level;
}

// EEngine::GetCurrentLevel - 0x802e38cc (8 bytes)
ERLevel* EEngine::GetCurrentLevel(void) {
    return *(ERLevel**)((char*)this + 0x30);
}

// EEngine::SetResetAllowed - 0x802e38d4 (8 bytes)
void EEngine::SetResetAllowed(bool val) {
    *(int*)((char*)this + 0x0C) = (int)val;
}

// EEngine::CanReset - 0x802e38dc (8 bytes)
int EEngine::CanReset(void) {
    return *(int*)((char*)this + 0x0C);
}

// EEngine::SignalShutdown - 0x802e38e4 (4 bytes)
void EEngine::SignalShutdown(void) {
}

// EEngine::ManagedStartup - 0x802e38e8 (8 bytes)
// Returns 1 (success)
int EEngine::ManagedStartup(void) {
    return 1;
}

// ============================================================================
// e_main.obj - Small functions (5 functions, 2 code + 3 ctor/dtor stubs)
// ============================================================================

// InitHeap - 0x802e3a34 (8 bytes)
// Returns 1 (success)
int InitHeap(void) {
    return 1;
}

// RegisterExitFunction - 0x802e3a3c (8 bytes)
// Stores function pointer in SDA global
void RegisterExitFunction(void* func) {
    _pExitFunc = func;
}

// ============================================================================
// e_cheatmenu.obj - CheatMenuParams small functions (6 functions)
// ============================================================================

// CheatMenuParams::CheatMenuParams - 0x80303ccc (24 bytes)
// Initializes all members to zero
CheatMenuParams::CheatMenuParams(void) {
    m_count = 0;
    m_tail = 0;
    m_head = 0;
}

// CheatMenuParams::~CheatMenuParams - 0x80303ce4 (40 bytes)
// NON_MATCHING - destructor with deleting flag check
// If flag & 1, calls operator delete
CheatMenuParams::~CheatMenuParams(void) {
    // Compiler generates: if (flag & 1) delete this;
}

// CheatMenuParams::Add - 0x80303d0c (60 bytes)
// Adds item to linked list (tail insert)
void CheatMenuParams::Add(EDebugMenuItem& item) {
    // item.m_next = m_tail
    *(void**)&item = m_tail;
    // if (m_tail != NULL) m_tail->m_prev = &item
    if (m_tail != 0) {
        *(void**)((char*)m_tail + 4) = &item;
    } else {
        // m_head = &item
        m_head = &item;
    }
    // item.m_prev = NULL
    *((void**)&item + 1) = 0;
    // m_tail = &item
    m_tail = &item;
    // m_count++
    m_count++;
}

// ============================================================================
// e_debugmenu.obj - EDebugMenuItem/EDebugMenu small functions (11 functions)
// ============================================================================

// EDebugMenuItem::EDebugMenuItem - 0x80305d80 (32 bytes)
// Sets vtable, zeroes next/prev
EDebugMenuItem::EDebugMenuItem(void) {
    m_vt = EDebugMenuItem_vtable;
    m_next = 0;
    m_prev = 0;
}

// EDebugMenu::EDebugMenu - 0x80305da0 (40 bytes)
// Initializes all members
EDebugMenu::EDebugMenu(void) {
    m_selected = 0;
    m_active = 1;
    m_count = 0;
    m_head = 0;
    m_visible = 1;
    m_unk04 = 0;
    m_tail = 0;
}

// EDebugMenuItem::GetDescription - 0x803c4160 (12 bytes)
// Default: writes empty string
void EDebugMenuItem::GetDescription(char* buf, int len) {
    buf[0] = '\0';
}

// EDebugMenuItem::GetValue - 0x803c416c (12 bytes)
// Default: writes empty string
void EDebugMenuItem::GetValue(char* buf) {
    buf[0] = '\0';
}

// EDebugMenuItem::ButtonPress(EDebugMenuButton) - 0x803c4178 (4 bytes)
// No-op
void EDebugMenuItem::ButtonPress(EDebugMenuButton btn) {
}

// EDebugMenuItem::ButtonPress(EDebugMenuButton, float) - 0x803c417c (4 bytes)
// No-op
void EDebugMenuItem::ButtonPress(EDebugMenuButton btn, float val) {
}

// ============================================================================
// e_animcontroller.obj - EAnimController small functions (8+1 functions)
// ============================================================================

// EAnimController::Shutdown - 0x802e7f40 (32 bytes)
// Calls internal cleanup function at 0x802e78e4
// NON_MATCHING - just a wrapper call
void EAnimController::Shutdown(void) {
    // Calls EAnimController::CleanupTracks(this)
    // bl 0x802e78e4
}

// EAnimController::SuspendTrack - 0x802e80a0 (36 bytes)
// Suspends a track by setting SUSPENDED flag bit
void EAnimController::SuspendTrack(EACTrack* track) {
    if (track == 0) return;
    // Check track state at +0xa8 == 1
    if (*(int*)((char*)track + 0xa8) != 1) return;
    // Set bit 0x08000000 in flags at +0x30
    unsigned int flags = *(unsigned int*)((char*)track + 0x30);
    flags |= 0x08000000;
    *(unsigned int*)((char*)track + 0x30) = flags;
}

// EAnimController::PrintTracks - 0x802e9c0c (24 bytes)
// Busy-waits for m_trackCount iterations (debug stall)
void EAnimController::PrintTracks(void) {
    int count = *(int*)((char*)this + 0x40);
    if (count <= 0) return;
    // bdnz loop - just burns cycles
    volatile int i = count;
    while (--i > 0) {}
}

// EAnimController::SetTrackBlendFactors - 0x802ef214 (28 bytes)
// Sets blend factor pointer on track if track is active
void EAnimController::SetTrackBlendFactors(EACTrack* track, float* factors) {
    if (track == 0) return;
    if (*(int*)((char*)track + 0xa8) != 1) return;
    *(float**)((char*)track + 0x9c) = factors;
}

// ============================================================================
// psystem.obj - Particle system small functions (7 code functions)
// ============================================================================

// ParticleProcessType3 - 0x80302ce0 (32 bytes)
// Wrapper that calls the real implementation
void ParticleProcessType3(pemitter* e, float dt) {
    _ParticleProcessType3Impl(e, dt);
}

// ParticleDestroy - 0x80303248 (60 bytes)
// Frees a particle and NULLs the handle
void ParticleDestroy(void** handle) {
    void* ptr = *handle;
    _ParticlePoolFree(g_pParticleSystem, ptr);
    *handle = 0;
}

// PEmitterSetState - 0x80303708 (40 bytes)
// Sets or clears state bits on an emitter
void PEmitterSetState(void* emitter, unsigned int mask, int set) {
    if (set) {
        unsigned int flags = *(unsigned int*)((char*)emitter + 0x50);
        flags |= mask;
        *(unsigned int*)((char*)emitter + 0x50) = flags;
    } else {
        unsigned int flags = *(unsigned int*)((char*)emitter + 0x50);
        flags &= ~mask;
        *(unsigned int*)((char*)emitter + 0x50) = flags;
    }
}

// PEmitterGetNumActiveParticles - 0x80303730 (12 bytes)
// Returns active particle count from emitter's internal data
int PEmitterGetNumActiveParticles(void* emitter) {
    void* data = *(void**)((char*)emitter + 0x54);
    return *(int*)((char*)data + 0x84);
}

// ParticleSysClose - 0x80303a54 (56 bytes)
// Closes all three particle pools
int ParticleSysClose(void) {
    _ParticlePoolClose(&g_pParticleModelSystem);
    _ParticlePoolClose(&g_pParticleWeatherSystem);
    _ParticlePoolClose(&g_pParticleSystem);
    return 0;
}

// PSystemSetWorldGravityDir - 0x80303a8c (48 bytes)
// Sets the world gravity direction vector (with magnitude stored at +0x0C)
extern "C" float g_PSystemGravity[]; // at 0x804b090c (16 bytes: x,y,z,mag)
extern "C" float _gravityMagnitude;  // constant from rodata

void PSystemSetWorldGravityDir(void* dir) {
    float* src = (float*)dir;
    g_PSystemGravity[0] = src[0];
    g_PSystemGravity[3] = _gravityMagnitude;
    g_PSystemGravity[1] = src[1];
    g_PSystemGravity[2] = src[2];
}

// PSystemGetNumActiveParticles - 0x80303abc (12 bytes)
// Returns total active particles from the main system pool
int PSystemGetNumActiveParticles(void) {
    void* pool = g_pParticleSystem;
    return *(int*)((char*)pool + 0x08);
}

// ============================================================================
// ADDITIONAL FUNCTIONS - SystemInit, EnterMovieMode, etc.
// ============================================================================

// EApp::SystemInit - 0x802e247c (52 bytes)
// Calls vtable function to get system init function, then calls it
// NON_MATCHING - vtable dispatch through offset table
void EApp::SystemInit(void) {
    // Loads vtable at this+0x338, gets offset/fn at +0xA0/+0xA4
    // Computes this+offset, calls fn
    void** vtbl = *(void***)((char*)this + 0x338);
    short offset = *(short*)((char*)vtbl + 0xA0);
    void (*fn)(void*) = (void (*)(void*))*(void**)((char*)vtbl + 0xA4);
    fn((char*)this + offset);
}

// EEngine::EnterMovieMode - 0x802e2e50 (60 bytes)
// Enters movie mode by calling renderer's enter movie function
// NON_MATCHING - vtable dispatch pattern
void EEngine::EnterMovieMode(void) {
    // Calls function at 0x80328e7c (some renderer pause)
    // Then dispatches through _pRenderer vtable offset 0x108/0x10C
}

// EEngine::ExitMovieMode - 0x802e2e8c (60 bytes)
// Exits movie mode by calling renderer's exit movie function
// NON_MATCHING - vtable dispatch pattern
void EEngine::ExitMovieMode(void) {
    // Dispatches through _pRenderer vtable offset 0x110/0x114
    // Then calls function at 0x80328e90 (some renderer resume)
}

// EEngine::FrameComplete - 0x802e31fc (60 bytes)
// Signals frame completion to the engine's app
// NON_MATCHING - vtable dispatch through SDA global
void EEngine::FrameComplete(void) {
    // Loads _pEngine (r13-0x6538), gets its app at +0x338
    // Dispatches through app vtable offset 0x38/0x3C
}

// EEngine::InitFileSystem - 0x802e340c (44 bytes)
// Initializes the file system
// NON_MATCHING - calls specific file system init function
void EEngine::InitFileSystem(void) {
    // Calls file system init at 0x802d7450 with specific path string
}

// EAnimController::GetAnimDistance - 0x802e94a8 (48 bytes)
// Gets animation distance for given track flags
// NON_MATCHING - calls internal function then normalizes
void EAnimController::GetAnimDistance(eTrackFlags flags, EVec3& out) {
    // Calls internal function at 0x802e96a8 with stack-local vec3
    // Then copies result to out via normalize at 0x8025ac6c
}

// EAnimController::PrepareForCollision - 0x802ea28c (64 bytes)
// Prepares animation state for collision detection
// NON_MATCHING - reads _frameIndex SDA global, calls internal at 0x802ea1dc
void EAnimController::PrepareForCollision(EMat4& mat) {
    int frame = _frameIndex;
    int f1 = *(int*)((char*)this + 0x28);
    if (f1 == frame) goto call;
    {
        int f2 = *(int*)((char*)this + 0x30);
        if (f2 == frame) goto call;
        frame--;
    }
call:
    // calls internal function at 0x802ea1dc
    (void)mat;
}

// EAnimController::CallbackIntermediateComputeMatrices - 0x802eb53c (52 bytes)
// Callback that computes intermediate matrices, stores frame index
// NON_MATCHING - calls internal at 0x802eb570 then stores _frameIndex
void EAnimController::CallbackIntermediateComputeMatrices(EMat4& mat) {
    // calls internal function at 0x802eb570
    *(int*)((char*)this + 0x30) = _frameIndex;
}

// EAnimController::SetTrackBlendHermiteSafe - 0x802ee4d8 (32 bytes)
// Wrapper that calls full SetTrackBlendHermite at 0x802ee640
// NON_MATCHING - just a wrapper call
void EAnimController::SetTrackBlendHermiteSafe(EACTrack* track, float a, float b, float c, float d) {
    // calls SetTrackBlendHermite at 0x802ee640
}

// ============================================================================
// Global constructor/destructor stubs
// These are compiler-generated and call __static_initialization_and_destruction_0
// ============================================================================

// __static_initialization_and_destruction_0 (e_engine.obj) - 0x802e3890 (40 bytes)
// Standard GCC static init guard pattern
// NON_MATCHING - compiler-generated, uses bdnz loop as delay
// Checks args: if (r4 != 0xFFFF) return; if (r3 == 0) return;
// Then does 3-iteration delay loop

// global constructors keyed to _evenodd (e_engine.obj) - 0x802e38f0 (44 bytes)
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
// NON_MATCHING - compiler-generated wrapper

// global constructors keyed to MainInit (e_main.obj) - 0x802e3a98 (44 bytes)
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
// NON_MATCHING - compiler-generated wrapper

// global destructors keyed to MainInit (e_main.obj) - 0x802e3ac4 (44 bytes)
// Calls __static_initialization_and_destruction_0(0, 0xFFFF)
// NON_MATCHING - compiler-generated wrapper

// global constructors keyed to kEACDefaultBlendTime (e_animcontroller.obj) - 0x802f0d70 (44 bytes)
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
// NON_MATCHING - compiler-generated wrapper

// global constructors keyed to CheatMenuParams (e_cheatmenu.obj) - 0x80303e00 (44 bytes)
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
// NON_MATCHING - compiler-generated wrapper

// global destructors keyed to CheatMenuParams (e_cheatmenu.obj) - 0x80303e2c (44 bytes)
// Calls __static_initialization_and_destruction_0(0, 0xFFFF)
// NON_MATCHING - compiler-generated wrapper

// global constructors keyed to EDebugMenuItem (e_debugmenu.obj) - 0x803065dc (44 bytes)
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
// NON_MATCHING - compiler-generated wrapper

// global constructors keyed to EFrameAllocGroup (e_frag.obj) - 0x8030686c (44 bytes)
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
// NON_MATCHING - compiler-generated wrapper

// global destructors keyed to EFrameAllocGroup (e_frag.obj) - 0x80306898 (44 bytes)
// Calls __static_initialization_and_destruction_0(0, 0xFFFF)
// NON_MATCHING - compiler-generated wrapper
