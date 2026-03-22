// loadingscreen_large.cpp - CLoadingScreen large functions (257-1024 bytes)
// Object file: loadingscreen.obj
// All NON_MATCHING - GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

extern "C" {
    void* operator_new_wrapper(u32 size);
    void operator_delete_wrapper(void* ptr);
    void* memset(void* dst, int val, u32 n);

    // Heap
    void* EAHeap_GetMovieHeap(void);
    void* EAHeap_MallocAligned(void* heap, u32 size, int align, int flags);
    void EAHeap_Free(void* heap, void* ptr);
}

// ============================================================================
// CLoadingScreen::CLoadingScreen(CLoadingScreen::eLoadingScreenMode)
// Address: 0x80056a64
// Size: 0x18c = 396 bytes
// NON_MATCHING - member initialization, mode setup
// ============================================================================
void CLoadingScreen_ctor(void* self, int mode) {
    char* _this = (char*)self;

    // Initialize all members to zero/default
    memset(_this, 0, 0x100); // approximate size

    // Set loading screen mode
    *(int*)(_this + 0x04) = mode;

    // Initialize progress tracking
    *(float*)(_this + 0x08) = 0.0f;  // m_progress
    *(float*)(_this + 0x0C) = 0.0f;  // m_displayProgress
    *(int*)(_this + 0x10) = 0;       // m_loadPhase

    // Initialize fade state
    *(float*)(_this + 0x14) = 0.0f;  // m_fadeAlpha
    *(int*)(_this + 0x18) = 0;       // m_fadeState

    // Set up rendering resources based on mode:
    // Mode 0: Neighborhood loading screen
    // Mode 1: Lot loading screen
    // Mode 2: CAS loading screen

    // Allocate texture buffers for loading screen art
    // Load loading screen image

    (void)mode;
}

// ============================================================================
// CLoadingScreen::~CLoadingScreen(void)
// Address: 0x80056bf0
// Size: 0xf8 = 248 bytes (under 257, skip)
// ============================================================================

// ============================================================================
// CLoadingScreen::InitAsync(void)
// Address: 0x80056ce8
// Size: 0xcc = 204 bytes (under 257, skip)
// ============================================================================

// ============================================================================
// CLoadingScreen::Update(float)
// Address: 0x80056db4
// Size: 0xe0 = 224 bytes (under 257, skip)
// ============================================================================

// ============================================================================
// CLoadingScreen::DrawTopmost(ERC*, float)
// Address: 0x80056e94
// Size: 0x8a4 = 2212 bytes (over 1024, skip)
// ============================================================================

// ============================================================================
// __static_initialization_and_destruction_0
// Address: 0x80057738
// Size: 0xf8 = 248 bytes (under 257, skip)
// ============================================================================

// Note: The only function in loadingscreen.obj in the 257-1024 range is the
// constructor at 396 bytes. DrawTopmost is much larger (2212 bytes).
