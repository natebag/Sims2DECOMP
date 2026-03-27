// game_bootstrap.cpp — Minimal game initialization for PC port
// Instead of calling the full ESimsApp::Init() (which depends on 20+ unimplemented
// subsystems), this bootstraps just enough for basic rendering and asset loading.

#include "types.h"
#include "platform/arc_reader.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>

// ============================================================================
// Global singletons that the game code expects to exist
// ============================================================================

// EAHeap — memory allocator (maps to malloc on PC)
struct PCEAHeap {
    void* Malloc(unsigned int size, int flags) { return malloc(size); }
    void* MallocAligned(unsigned int size, unsigned int align, int flags) { return malloc(size); }
    void  Free(void* ptr) { free(ptr); }
};

static PCEAHeap g_mainHeap;
static PCEAHeap g_rootHeap;

// Heap accessor functions the decomp code calls
extern "C" {
    void* MainHeap_PC(void) { return &g_mainHeap; }
    void* RootHeap_PC(void) { return &g_rootHeap; }
}

// EGlobal — massive global state struct (~4KB)
static u8 g_eGlobal[8192] = {};
static void* g_pEGlobal = g_eGlobal;

// ESimsApp singleton
static u8 g_eSimsApp[4096] = {};

// ENgcEngine singleton
static u8 g_eNgcEngine[2048] = {};

// EControllerManager singleton
static u8 g_eControllerManager[512] = {};

// StateMachineManager
static u8 g_stateMachineManager[256] = {};

// ============================================================================
// Game Bootstrap — called from main_pc.cpp before the render loop
// ============================================================================

static FILE* g_logFile = nullptr;

static void log_boot(const char* fmt, ...) {
    if (!g_logFile) g_logFile = fopen("sims2pc.log", "a");
    if (g_logFile) {
        va_list args;
        va_start(args, fmt);
        vfprintf(g_logFile, fmt, args);
        va_end(args);
        fflush(g_logFile);
    }
}

int game_bootstrap(const char* data_path) {
    log_boot("[BOOT] Starting game bootstrap...\n");

    // Step 1: Initialize memory (already done — using malloc)
    log_boot("[BOOT] Memory: using system malloc\n");

    // Step 2: Initialize global state
    memset(g_eGlobal, 0, sizeof(g_eGlobal));
    memset(g_eSimsApp, 0, sizeof(g_eSimsApp));
    log_boot("[BOOT] Global state initialized\n");

    // Step 3: Load game archives
    int arc_loaded = arc_open_all(data_path);
    log_boot("[BOOT] Archives loaded: %d\n", arc_loaded);

    if (arc_loaded == 0) {
        log_boot("[BOOT] ERROR: No archives found at %s\n", data_path);
        return 0;
    }

    // Step 4: Verify key resources exist
    int has_textures = 0, has_models = 0, has_fonts = 0;
    for (int i = 0; i < arc_count(); i++) {
        ArcArchive* arc = arc_get(i);
        if (!arc) continue;
        // Check for key entries
        if (arc_find(arc, "systemfont")) has_fonts = 1;
        if (arc_find(arc, "map")) has_models = 1;
        if (arc_find(arc, "title bg c")) has_textures = 1;
    }

    log_boot("[BOOT] Resources: fonts=%d models=%d textures=%d\n",
             has_fonts, has_models, has_textures);

    // Step 5: Set up renderer state
    // (OpenGL already initialized by gl_init in main_pc.cpp)
    log_boot("[BOOT] Renderer: OpenGL (initialized by main)\n");

    // Step 6: Report ready
    log_boot("[BOOT] Game bootstrap complete — ready for render loop\n");
    log_boot("[BOOT] NOTE: Full game init (ESimsApp::Init) not yet wired.\n");
    log_boot("[BOOT]       Currently showing test scene. Next step: implement\n");
    log_boot("[BOOT]       subsystem inits one at a time until game boots.\n");

    return 1;
}

// Called each frame from the render loop
void game_update(float dt) {
    // TODO: When ready, call:
    // ESimsApp::UpdateCheats();
    // ESimsApp::UpdateApt();
    // ESimsApp::UpdateGame();
    // ESimsApp::UpdateAudio();
    // ESimsApp::UpdateShaders(dt);
    // ESimsApp::UpdateDraw();
    (void)dt;
}

void game_shutdown(void) {
    log_boot("[BOOT] Game shutdown\n");
    if (g_logFile) fclose(g_logFile);
    g_logFile = nullptr;
}
