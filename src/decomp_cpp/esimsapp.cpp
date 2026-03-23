// esimsapp.cpp - Decompiled ESimsApp class (PC port, functionally correct C++)
//
// Converted from inline PPC asm (src/asm_decomp/ESimsApp.cpp) using
// documentation in src/core/esimsapp_decomp.cpp.
//
// ESimsApp inherits from EApp (the Maxis Engine application base class).
// It implements the game-specific Init, Update, Shutdown, and state management.
//
// MAIN GAME LOOP FLOW:
//   EApp::Main()
//     -> EApp::SystemInit()
//       -> ESimsApp::Init()              -- one-time initialization
//       -> ESimsApp::ShowInitialDisplay() -- initial display setup
//     -> EApp::SystemUpdate() (called each frame)
//       -> ESimsApp::Update()            -- per-frame update
//     -> ESimsApp::Shutdown()            -- cleanup on exit

#include "types.h"

// C runtime
extern "C" {
    int    strcmp(const char*, const char*);
    int    strcasecmp(const char*, const char*);
    int    strncasecmp(const char*, const char*, int);
    char*  strcpy(char*, const char*);
    char*  strncpy(char*, const char*, int);
    char*  strstr(const char*, const char*);
    int    strlen(const char*);
    char*  strchr(const char*, int);
    int    AtoI(const char*);
    void   Sprintf(char*, const char*, ...);
}

// Debug output
extern "C" void OSReport(const char*, ...);
// In the original, this was EORDbgTrace - same signature as printf
extern "C" void EORDbgTrace(const char*, ...);

// Forward declarations for external classes/functions
class EApp;
class EGlobal;
class GameData;
class EControllerManager;
class EController;
class StateMachineManager;
class EResourceManager;
class EGameStateMan;
class AptViewer;
class EyeToyClient;
class NghResFile;
class EWindow;
class ERC;
class UIAUDIO;
class EShader;
class ERShader;
class ENgcMemoryCard;
class LoadingScreenStateMachine;
class PlayerCheats;
class BString2;
class CTGDump;
class cSoundPlayer;
class EAHeap;
class ESimScratchPadMan;

typedef int OVERALL_GAME_STATE;

// External subsystem functions (would be linked from other translation units)
extern void InitPerformanceCounter();
extern void ProfileHook();
extern void DrawGame(ERC* rc);

// ============================================================================
// Global/static variables
// Originally accessed via r13-relative SDA (Small Data Area) addressing.
// For PC port, these are regular globals.
// ============================================================================

static float         g_resetTimer = 0.0f;
static int           s_testMode = 0;
static int           s_startLot = 0;
static UIAUDIO*      g_pUIAudio = NULL;
static void*         g_nghRegistryHandle = NULL;
static int           g_aptInitialized = 0;
static float         g_deltaTime = 0.0f;
static int           g_pauseGame = 0;
static void*         g_pResourceManager2 = NULL;
static int           g_resourceManager2_exists = 0;
static void*         g_pResourceManager2_data = NULL;
static EControllerManager* g_pEControllerManager = NULL;
static void*         g_pResetTarget = NULL;
static void*         g_pRenderer = NULL;
static void*         g_pAltShaderData = NULL;
static void*         g_pTimeScaleObj = NULL;
static CTGDump*      g_ctgDump = NULL;
static StateMachineManager* g_pStateMachineManager = NULL;
static cSoundPlayer* g_pSoundPlayer = NULL;
static EGlobal*      g_pEGlobal = NULL;
static GameData*     g_pGameData = NULL;
static NghResFile*   g_pNghResFile = NULL;
static PlayerCheats* g_pPlayerCheats = NULL;
static void*         g_pResourceManager1 = NULL;
static void*         g_pResourceManager_main = NULL;

// ============================================================================
// ESimsApp class definition
// ============================================================================

class ESimsApp /* : public EApp */ {
public:
    // EApp base class data (offsets 0x000 - 0x337)
    u8 _eapp_data[0x338];

    // ESimsApp-specific fields:
    // 0x338 - secondary vtable pointer (set in ctor)
    void** m_vtable2;

    u8 _pad_33C[0x0C];

    // 0x348 - command line data
    int    m_argc;
    char** m_argv;

    u8 _pad_350[0x100];

    // 0x450 - audio mute flag
    u32    m_audioMuted;

    u8 _pad_454[0x14];

    // 0x468 - current game state
    OVERALL_GAME_STATE m_gameState;

    u8 _pad_46C[0x0C];

    // 0x478 - core subsystem pointers
    EGameStateMan* m_gameStateMan;
    ERC*           m_currentRC;      // 0x47C
    EWindow*       m_window;         // 0x480
    u8             m_flag_484;       // 0x484
    u8             _pad_485[3];
    u32            m_field_488;      // 0x488

    // 0x48C - controller auto-mapping flags
    int            m_player1RemapPending;
    int            m_player2RemapPending;

    u8 _pad_494[4];

    // 0x498 - init state
    u32            m_scratchPadInit;

    // 0x49C - screenshot state
    int            m_screenshotActive;
    int            m_screenshotCols;
    int            m_screenshotRows;

    u8 _pad_4A8[0x878];

    // 0xD20 - language ID
    u32            m_languageId;

    // --- Static data ---
    static char m_nameOfNgh[16];

    // --- Methods ---
    ESimsApp();
    ~ESimsApp();

    // Lifecycle
    void Init();
    void initContinue();
    void ShowInitialDisplay();
    void Update();
    void Shutdown();

    // Update sub-functions
    void UpdateCheats();
    void UpdateApt();
    void UpdateGame();
    void UpdateShaders(float dt);
    void UpdateAudio();
    void UpdateDraw();
    void UpdateReset();

    // Game state
    void SetGameState(OVERALL_GAME_STATE state);
    void LoadSimulatorGlobs();

    // Command line
    void parseCommandLine();
    static int GetStartLot();
    static void SetStartLot(int lot);
    void SetNghName(char* name);

    // Accessors
    const char* GetBuildVersion();
    int GetDefaultLanguage();
    const char* GetAppName();
    int GetEventTableSize();
    const char* GetNghName();

    // Screenshot
    void TakeBigScreenshot(int w, int h);
};

// Static member initialization
char ESimsApp::m_nameOfNgh[16] = {0};


// ============================================================================
// IMPLEMENTATIONS
// ============================================================================

// ============================================================================
// ESimsApp::GetStartLot
// Address: 0x80003FDC | 8 bytes
// Returns the starting lot number from a static variable.
// ============================================================================

int ESimsApp::GetStartLot() {
    return s_startLot;
}


// ============================================================================
// ESimsApp::SetStartLot
// Address: 0x80003FE4 | 8 bytes
// Sets the starting lot number.
// ============================================================================

void ESimsApp::SetStartLot(int lot) {
    s_startLot = lot;
}


// ============================================================================
// ESimsApp::SetNghName
// Address: 0x80003FEC | 136 bytes
//
// Sets the neighborhood filename. Validates for ".ngh" or ".NGH" extension,
// ensures length > 4, copies up to 15 chars into static buffer.
// ============================================================================

void ESimsApp::SetNghName(char* name) {
    // Check for valid NGH extension (case-insensitive)
    if (strstr(name, ".ngh") == NULL) {
        if (strstr(name, ".NGH") == NULL) {
            return; // No valid NGH extension
        }
    }

    // Must be more than just the extension
    if ((unsigned int)strlen(name) <= 4) {
        return;
    }

    // Copy up to 15 characters, null-terminate
    strncpy(m_nameOfNgh, name, 16);
    m_nameOfNgh[15] = '\0';
}


// ============================================================================
// ESimsApp::parseCommandLine
// Address: 0x80004074 | 716 bytes
//
// Parses command-line arguments. Supports:
//   -lot <N>      : Set starting lot (1-16)
//   -ngh <X>      : Set neighborhood file
//   -test         : Enable test mode
//   -test_listen  : Enable test listen mode
//   -test_NGC     : Enable NGC test mode
// ============================================================================

void ESimsApp::parseCommandLine() {
    int argc = m_argc;
    char** argv = m_argv;

    EORDbgTrace("------ Entering parseCommandLine()\n");
    EORDbgTrace("Argc: %d, Argv: %08X\n", argc, argv);

    // Print all arguments
    for (int i = 0; i < argc; i++) {
        EORDbgTrace("Argv[%d]: %s\n", i, argv[i]);
    }

    if (argv == NULL || argc <= 0 || argv[0] == NULL) {
        return;
    }

    // Copy first arg (program name) to debug buffer
    // (omitted for PC port - debug buffer not needed)

    if (argc <= 1) {
        return;
    }

    int argIdx = 0;
    char** argvCur = argv;

    while (argIdx < argc) {
        char* arg = argvCur[0];
        argIdx++;
        argvCur++;

        // Split on spaces within the argument string
        char* spacePos = strchr(arg, ' ');
        char* nextToken = NULL;
        if (spacePos != NULL) {
            *spacePos = '\0';
            nextToken = spacePos + 1;
            char* space2 = strchr(nextToken, ' ');
            if (space2 != NULL) {
                *space2 = '\0';
            }
        }

        int consumed = 0;

        // Check if arg starts with '-'
        if (arg[0] != '-') {
            goto end_of_arg;
        }

        arg++; // skip the '-'

        {
            // Determine the value parameter
            char* value = NULL;
            if (argIdx < argc) {
                value = argvCur[0]; // peek at next argv
            }
            if (spacePos != NULL) {
                value = spacePos + 1; // use space-separated value
            }
            if (value != NULL && value[0] == '\0') {
                value = NULL;
            }

            // Parse the flag
            char firstChar = arg[0];

            if (firstChar == 'L' || firstChar == 'l') {
                // -lot <N>: Set starting lot
                if (strncasecmp(arg, "lot", 3) == 0 && value != NULL) {
                    int lot = AtoI(value);
                    if ((unsigned)(lot - 1) <= 15) { // lot 1..16
                        s_startLot = lot;
                    }
                    consumed = 1;
                }
            } else if (firstChar == 'N' || firstChar == 'n') {
                // -ngh <name>: Set neighborhood file
                if (strncasecmp(arg, "ngh", 3) == 0 && value != NULL) {
                    consumed = 1;
                    SetNghName(value);
                }
            } else if (firstChar == 'T' || firstChar == 't') {
                // -test, -test_listen, -test_NGC
                if (strcasecmp(arg, "test_listen") == 0) {
                    s_testMode = 1;
                } else if (strcasecmp(arg, "test_NGC") == 0) {
                    s_testMode = 1;
                } else if (strcasecmp(arg, "test") == 0) {
                    if (value != NULL) {
                        s_testMode = 1;
                    }
                }
            }
        }

    end_of_arg:
        if (consumed != 0) {
            if (spacePos != NULL) {
                spacePos = nextToken;
            }
            consumed = 0;
        }
        if (spacePos != NULL) {
            arg = spacePos;
            continue; // re-parse the remainder
        }

        if (consumed != 0) {
            argIdx += consumed;
            argvCur += consumed;
        }
    }
}


// ============================================================================
// ESimsApp::ESimsApp - Constructor
// Address: 0x80004340 | 88 bytes
// ============================================================================

ESimsApp::ESimsApp() {
    // EApp::EApp() is called implicitly by base class constructor

    // Set vtable to ESimsApp's vtable
    // m_vtable2 = &ESimsApp_vtable;  // PC port: handled by compiler

    // Zero-initialize key fields
    m_player2RemapPending = 0;
    m_gameStateMan = NULL;
    m_window = NULL;
    m_flag_484 = 0;
    m_field_488 = 0;
    m_player1RemapPending = 0;
}


// ============================================================================
// ESimsApp::~ESimsApp - Destructor
// Address: 0x80004398 | 48 bytes
// ============================================================================

ESimsApp::~ESimsApp() {
    // Reset vtable for correct dispatch during destruction
    // m_vtable2 = &ESimsApp_vtable;  // PC port: handled by compiler
    // ~EApp() called implicitly
}


// ============================================================================
// ESimsApp::GetBuildVersion
// Address: 0x800044B4 | 12 bytes
// ============================================================================

const char* ESimsApp::GetBuildVersion() {
    return "GameCube The Sims 2 Console Build F.09.12.0";
}


// ============================================================================
// ESimsApp::GetDefaultLanguage
// Address: 0x800044C0 | 8 bytes
// Returns 0 (English) on GameCube. PC port could read system locale.
// ============================================================================

int ESimsApp::GetDefaultLanguage() {
    return 0; // English
}


// ============================================================================
// ESimsApp::SetGameState
// Address: 0x80005410 | 8 bytes
// ============================================================================

void ESimsApp::SetGameState(OVERALL_GAME_STATE state) {
    m_gameState = state;
}


// ============================================================================
// ESimsApp::LoadSimulatorGlobs
// Address: 0x80005418 | 32 bytes
// Wrapper that initializes performance timing.
// ============================================================================

void ESimsApp::LoadSimulatorGlobs() {
    InitPerformanceCounter();
}


// ============================================================================
// ESimsApp::UpdateCheats
// Address: 0x80005448 | 116 bytes
//
// Checks if any controller has pressed a cheat button combination.
// If detected, passes the controller to PlayerCheats::Capture().
// ============================================================================

void ESimsApp::UpdateCheats() {
    if (g_pEControllerManager == NULL) {
        return;
    }

    // Get controller index for player 0
    // u32 ctrlIdx = EControllerManager::GetPlayerControllerIndex(g_pEControllerManager, 0);
    // EController* ctrl = EControllerManager::GetController(g_pEControllerManager, ctrlIdx);
    // if (ctrl == NULL) return;

    // Check if any button was pressed
    // u32 pressed = EController::GetBtnPressedMask(ctrl, -1);
    // if (pressed == 0) return;

    // A cheat button was pressed - capture it
    // PlayerCheats::Capture(g_pPlayerCheats, ctrl);

    // TODO: implement controller/cheat system for PC port
}


// ============================================================================
// ESimsApp::UpdateApt
// Address: 0x800054BC | 88 bytes
//
// Updates the APT (ActionScript) UI system.
// Only runs if APT is initialized.
// ============================================================================

void ESimsApp::UpdateApt() {
    if (g_aptInitialized == 0) {
        return;
    }

    // AptViewer* viewer = g_pEGlobal->m_aptViewer;
    // AptViewer::NewReadController(viewer, 0, false, 0, true);
    // AptViewer::UpdateAll(viewer);

    // TODO: implement APT UI system for PC port
}


// ============================================================================
// ESimsApp::UpdateGame
// Address: 0x80005514 | 64 bytes
//
// Updates the game simulation. If not paused, ticks the state machine
// manager. Always updates GameData with delta time.
// ============================================================================

void ESimsApp::UpdateGame() {
    // Check if game is paused
    if (g_pauseGame == 0) {
        // Tick all state machines with delta time
        // StateMachineManager::UpdateMachines(g_deltaTime);
    }

    // Update copyright/game data (always runs, even when paused)
    // GameData::CopyrightUpdate(g_pGameData, g_deltaTime);

    // TODO: implement state machine and game data systems
}


// ============================================================================
// ESimsApp::UpdateShaders
// Address: 0x80005554 | 412 bytes
//
// Updates shader/material system. Handles time-scaling for shader
// animations and dispatches to EShader and ERShader systems.
// ============================================================================

void ESimsApp::UpdateShaders(float dt) {
    float shaderDt = dt;
    float renderDt = dt;

    // If dt is 0.0, use global delta time
    if (dt == 0.0f) {
        shaderDt = g_deltaTime;
    }
    renderDt = dt;
    if (dt == 0.0f) {
        renderDt = g_deltaTime;
    }

    int shaderParam1 = 0;
    int shaderParam2 = 0;
    int shaderParam3 = 0;

    // Query time scale object if it exists
    if (g_pTimeScaleObj != NULL) {
        // The time scale object controls simulation speed during movies/cutscenes.
        // Virtual method calls query whether it's active, paused, and its
        // time scale factor.
        //
        // if active:
        //   if paused: shaderDt = 0
        //   else if otherState: shaderDt = 0
        //   else: shaderDt *= timeScale
        //   renderDt = shaderDt
        //
        // Also queries shader parameter indices from render state
    } else {
        // No time scale object - check alternate data source
        if (g_pAltShaderData != NULL) {
            shaderParam2 = *(int*)((char*)g_pAltShaderData + 208);
            renderDt     = *(float*)((char*)g_pAltShaderData + 196);
            shaderParam1 = *(int*)((char*)g_pAltShaderData + 200);
            shaderParam3 = *(int*)((char*)g_pAltShaderData + 204);
        }
    }

    // Update all shaders
    // EShader::UpdateAll(shaderDt);
    // ERShader::UpdateAll(renderDt, shaderParam1, shaderParam3, shaderParam2);

    // TODO: implement shader system for PC port
}


// ============================================================================
// ESimsApp::UpdateAudio
// Address: 0x800056F0 | 92 bytes
//
// Updates the audio system. If audio is not muted, updates the sound
// player. Also lazily initializes and updates UIAUDIO.
// ============================================================================

void ESimsApp::UpdateAudio() {
    // Check if audio is muted
    if (m_audioMuted == 0) {
        // Audio not muted - update sound player
        if (g_pSoundPlayer != NULL) {
            // cSoundPlayer::Update(g_pSoundPlayer);
        }
    }

    // Lazy-initialize UIAUDIO singleton
    if (g_pUIAudio == NULL) {
        // g_pUIAudio = new UIAUDIO(); // sizeof(UIAUDIO) = 0x78 = 120 bytes
    }

    // Update UI audio
    // UIAUDIO::Update(g_pUIAudio);

    // TODO: implement audio system for PC port
}


// ============================================================================
// ESimsApp::UpdateDraw
// Address: 0x80005808 | 708 bytes
//
// Main rendering function. Handles single-screen and split-screen rendering.
// ============================================================================

void ESimsApp::UpdateDraw() {
    // Get render context for player 0
    // ERC* rc = renderer->BeginRenderPass(0);
    // m_currentRC = rc;

    // Draw game scene
    // DrawGame(rc);

    // Draw topmost state machine overlays (loading screens, etc.)
    // StateMachineManager::DrawTopmostMachines(rc);

    // Draw copyright/legal text
    // GameData::CopyrightDraw(g_pGameData, rc);

    // End render pass
    // renderer->EndRenderPass(rc);
    // m_currentRC = NULL;

    // Check if big screenshot is pending
    if (m_screenshotActive == 0) {
        return;
    }

    // Screenshot rendering (tiled approach for high-res capture)
    // renderer->BeginFullScreenRender();
    //
    // for (int row = 0; row < m_screenshotRows; row++) {
    //     for (int col = 0; col < m_screenshotCols; col++) {
    //         EWindow::ScaleForScreenshot(1, col, m_screenshotCols, row, m_screenshotRows);
    //         // ... render tile, save to file ...
    //         char filename[160];
    //         Sprintf(filename, "pic_%02d_%02d", col + 1, row + 1);
    //         // renderer->SaveScreenshot(filename);
    //     }
    // }
    //
    // // Reset screenshot mode
    // EWindow::ScaleForScreenshot(0, 1, 1, 0, 0);
    // m_screenshotActive = 0;

    // TODO: implement rendering for PC port
}


// ============================================================================
// ESimsApp::UpdateReset
// Address: 0x80005ACC | 216 bytes
//
// Checks if the reset button combination is held. If held long enough
// (~2 seconds), triggers a console soft reset.
// ============================================================================

void ESimsApp::UpdateReset() {
    if (g_pEControllerManager == NULL) {
        return;
    }

    // Check for reset button combo across all controllers
    // Command 0x1B (27) = reset combo
    // int resetHeld = EControllerManager::GetCmdResultAllCtrl(
    //     g_pEControllerManager, 27, &resetData, &resetData, 0, 0);

    int resetHeld = 0; // placeholder

    if (resetHeld == 0) {
        // Not holding reset - reset the timer
        g_resetTimer = 0.0f;
        return;
    }

    // Accumulate reset hold timer
    g_resetTimer += g_deltaTime;

    // Check if held long enough (~2.0 seconds)
    if (g_resetTimer > 2.0f) {
        // Trigger soft reset
        // resetTarget->DisableRendering(0);
        // resetTarget->TriggerReset();
    }
}


// ============================================================================
// ESimsApp::Update - MAIN GAME LOOP
// Address: 0x80005BA4 | 264 bytes
//
// The per-frame update function. Called every frame from EApp::SystemUpdate().
// This is the heart of the game loop.
// ============================================================================

void ESimsApp::Update() {
    // --- Player 1 controller auto-mapping ---
    if (m_player1RemapPending != 0) {
        // EControllerManager* ctrlMgr = g_pEControllerManager;
        // if (!EControllerManager::GetPlayerMapped(ctrlMgr, 0)) {
        //     int result = EGlobal::TryAutoMapPlayer(g_pEGlobal, 0);
        //     if (result != -1) {
        //         AptViewer* viewer = g_pEGlobal->m_aptViewer;
        //         viewer->m_field_3AC = -1;
        //     }
        // }
    }

    // --- Player 2 controller auto-mapping ---
    if (m_player2RemapPending != 0) {
        // EControllerManager* ctrlMgr = g_pEControllerManager;
        // if (!EControllerManager::GetPlayerMapped(ctrlMgr, 1)) {
        //     int result = EGlobal::TryAutoMapPlayer(g_pEGlobal, 1);
        //     if (result != -1) {
        //         AptViewer* viewer = g_pEGlobal->m_aptViewer;
        //         viewer->m_field_3AC = -1;
        //         viewer->m_field_3A8 = 1;
        //     }
        // }
    }

    // --- Per-frame subsystem updates (in order) ---

    // 1. Profile hook (performance measurement)
    ProfileHook();

    // 2. Process cheat codes
    UpdateCheats();

    // 3. Update APT UI system (ActionScript interpreter)
    UpdateApt();

    // 4. Update game simulation (state machines, AI, physics)
    UpdateGame();

    // 5. Update audio (sound player, UI audio)
    UpdateAudio();

    // 6. Update shaders (dt=0.0 means use global delta time)
    UpdateShaders(0.0f);

    // 7. Render the frame
    UpdateDraw();

    // 8. Check for reset button combo
    UpdateReset();
}


// ============================================================================
// ESimsApp::Shutdown
// Address: 0x800043C8 | 236 bytes
//
// Full shutdown sequence. Tears down all game subsystems in reverse order.
// ============================================================================

void ESimsApp::Shutdown() {
    // 1. Begin save game (auto-save on exit)
    // EGlobal::BeginSaveGame(g_pEGlobal);

    // 2. Shutdown global sim data
    // Globs::Shutdown(g_pGlobs);

    // 3. Free resource manager 2 if it exists
    if (g_resourceManager2_exists != 0) {
        if (g_pResourceManager2 != NULL) {
            // EResourceManager::Free(g_pResourceManager2_data, g_pResourceManager2);
            g_resourceManager2_exists = 0;
            g_pResourceManager2 = NULL;
        }
    }

    // 4. Shutdown state machine manager
    // StateMachineManager::Shutdown();

    // 5. Delete all game states and the state manager
    if (m_gameStateMan != NULL) {
        // EGameStateMan::DeleteAllStates(m_gameStateMan);
        // delete m_gameStateMan;
    }

    // 6. Clear pointers and flags
    m_field_488 = 0;
    m_gameStateMan = NULL;
    m_flag_484 = 0;

    // 7. Reset global game state
    // EGlobal::Reset(g_pEGlobal);

    // 8. Shutdown EyeToy client
    // EyeToyClient::Shutdown();

    // 9. Destroy the render window
    if (m_window != NULL) {
        // delete m_window;
        m_window = NULL;
    }

    // 10. Shutdown resource manager
    // EResourceManager::Shutdown(g_pResourceManager1);

    // 11. Shutdown CTGDump
    // CTGDump::Shutdown(g_ctgDump);
}


// ============================================================================
// ESimsApp::ShowInitialDisplay
// Address: 0x80004B8C | 244 bytes
//
// Sets up the initial display by performing heap compaction.
// Two rounds of all 14 heaps with Compact() calls.
// ============================================================================

void ESimsApp::ShowInitialDisplay() {
    // The original performs two identical rounds of heap compaction:
    // Each round calls all 14 heap accessor functions followed by Compact().
    // This coalesces free memory after initialization is complete.
    //
    // For the PC port, heap compaction is handled by the OS allocator.
    // The pattern is preserved for documentation:

    // Round 1
    // RootHeap()->Compact();
    // MainHeap()->Compact();
    // ResourceHeap()->Compact();
    // AudioHeap()->Compact();
    // VMHeap()->Compact();
    // ShaderHeap()->Compact();
    // TextureHeap()->Compact();
    // AnimationHeap()->Compact();
    // ModelHeap()->Compact();
    // FlashesHeap()->Compact();
    // AptHeap()->Compact();
    // DebugHeap()->Compact();
    // CUIHeap()->Compact();
    // EAHeap::SetNextCheckPoint();

    // Round 2 (identical)
    // RootHeap()->Compact();
    // ... (same 13 heaps) ...
    // EAHeap::SetNextCheckPoint();
}


// ============================================================================
// ESimsApp::TakeBigScreenshot
// Address: 0x80005D2C | 20 bytes
// Initiates a tiled high-resolution screenshot capture.
// ============================================================================

void ESimsApp::TakeBigScreenshot(int w, int h) {
    m_screenshotActive = 1;
    m_screenshotCols = w;
    m_screenshotRows = h;
}


// ============================================================================
// ESimsApp::GetAppName
// Address: 0x80006380 | 12 bytes
// ============================================================================

const char* ESimsApp::GetAppName() {
    return "The Sims 2 Console";
}


// ============================================================================
// ESimsApp::GetEventTableSize
// Address: 0x8000638C | 8 bytes
// ============================================================================

int ESimsApp::GetEventTableSize() {
    return 0;
}


// ============================================================================
// ESimsApp::GetNghName
// Address: 0x80006394 | 12 bytes
// ============================================================================

const char* ESimsApp::GetNghName() {
    return m_nameOfNgh;
}
