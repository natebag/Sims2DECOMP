// e_app_large.cpp - EApp/EEngine large functions (257-512 bytes)
// Object files: e_app.obj, e_engine.obj
// Functions: EApp::Main, EEngine::EEngine, EEngine::Init,
//            EEngine::InitSubsystems, EEngine::ShutdownResourceManagers

#include "core/e_app.h"

// External functions
extern "C" {
    void EStorable_BaseCtor(void* obj, int numSlots);    // base ctor
    void EStorable_ManagedShutdownBase(void* obj);       // base shutdown
    void EAHeap_SystemInit(void);
}

// SDA globals
extern "C" {
    extern EApp* _pApp;       // r13 - 0x68C8
    extern void* _pEngine;    // r13 - 0x6790
    extern void* _pRenderer;  // r13 - 0x587C
    extern void* _pInputMgr;  // r13 - 0x67A4
    extern void* _pRC;        // r13 - 0x6718
    extern int _frameIndex;   // r13 - 0x68BC
}

// ============================================================================
// EApp::Main(void)
// Address: 0x802e2290
// Size: 388 bytes (0x184)
// NON_MATCHING - vtable dispatch chain, SDA addressing
//
// Main application loop entry. Calls SystemInit, Init, ShowInitialDisplay,
// then enters the main loop calling SystemUpdate until shutdown.
// ============================================================================
// Using free function to avoid header declaration mismatch
static void EApp_Main(void* self) {
    char* _this = (char*)self;
    void** vtbl = *(void***)(_this + 0x338);

    // SystemInit dispatch
    {
        short adj = *(short*)((char*)vtbl + 0xA0);
        void (*fn)(void*) = (void (*)(void*))*(void**)((char*)vtbl + 0xA4);
        fn(_this + adj);
    }

    // Init dispatch
    {
        short adj = *(short*)((char*)vtbl + 0x88);
        void (*fn)(void*) = (void (*)(void*))*(void**)((char*)vtbl + 0x8C);
        fn(_this + adj);
    }

    // ShowInitialDisplay dispatch
    {
        short adj = *(short*)((char*)vtbl + 0x80);
        void (*fn)(void*) = (void (*)(void*))*(void**)((char*)vtbl + 0x84);
        fn(_this + adj);
    }

    // Main loop: SystemUpdate dispatched via vtable
    for (;;) {
        short adj = *(short*)((char*)vtbl + 0x90);
        void (*fn)(void*) = (void (*)(void*))*(void**)((char*)vtbl + 0x94);
        fn(_this + adj);
    }
}

// ============================================================================
// EEngine::EEngine(void)
// Address: 0x802e2994
// Size: 292 bytes (0x124)
// NON_MATCHING - multiple vtable setup, field initialization
//
// Constructor for EEngine. Sets up dual vtable, initializes all fields.
// ============================================================================
void EEngine_Constructor(void* self) {
    // Call EStorable base constructor with 3 slots
    EStorable_BaseCtor(self, 3);

    // Set primary vtable at this+0x00
    // Set secondary vtable at offset (computed from this)

    // Initialize all fields to 0/defaults:
    // this+0x04 = 0 (retrace count)
    // this+0x08 = 0 (smoothing disabled)
    // this+0x0C = 0 (reset not allowed)
    // this+0x10 = 0
    // ... through this+0x34

    // Store _pEngine SDA global = this
    _pEngine = self;
}

// ============================================================================
// EEngine::Init(void)
// Address: 0x802e2b4c
// Size: 352 bytes (0x160)
// NON_MATCHING - complex initialization with multiple subsystem calls
//
// Full engine initialization. Initializes heap, file system, renderer,
// input manager, and resource managers.
// ============================================================================
void EEngine_Init(void* self) {
    // NON_MATCHING - many external function calls and vtable dispatches
    // 1. Call InitHeap (0x802e3a34) - returns 1
    // 2. Call InitFileSystem via vtable
    // 3. Create renderer via vtable dispatch
    // 4. Store _pRenderer SDA global
    // 5. Create input manager via vtable dispatch
    // 6. Store _pInputMgr SDA global
    // 7. Create rendering context
    // 8. Store _pRC SDA global
    // 9. Call InitResourceManagers via vtable
    // 10. Call InitSubsystems via vtable
    // 11. Call ManagedStartup via vtable
    (void)self;
}

// ============================================================================
// EEngine::InitSubsystems(void)
// Address: 0x802e3240
// Size: 460 bytes (0x1CC)
// NON_MATCHING - multiple subsystem initialization calls
//
// Initializes engine subsystems: animation system, particle system,
// debug menu, frame allocator.
// ============================================================================
void EEngine_InitSubsystems(void* self) {
    // NON_MATCHING - extensive initialization sequence
    // Initialize animation system
    // Initialize particle system
    // Initialize debug menu
    // Initialize frame allocator groups
    // Set up DMA rings
    // Initialize texture ring
    // Initialize matrix ring
    (void)self;
}

// ============================================================================
// EEngine::ShutdownResourceManagers(void)
// Address: 0x802e3658
// Size: 352 bytes (0x160)
// NON_MATCHING - reverse order shutdown of resource managers
//
// Shuts down all resource managers in reverse order of initialization.
// ============================================================================
void EEngine_ShutdownResourceManagers(void* self) {
    // NON_MATCHING - extensive shutdown sequence
    // Shutdown in reverse order:
    // 1. Shutdown frame allocator
    // 2. Shutdown debug menu
    // 3. Shutdown particle system
    // 4. Shutdown animation system
    // 5. Shutdown rendering context
    // 6. Shutdown input manager
    // 7. Shutdown renderer
    // 8. Shutdown file system
    // 9. Shutdown heap
    (void)self;
}
