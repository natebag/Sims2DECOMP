#ifndef ESIMSAPP_H
#define ESIMSAPP_H

#include "types.h"

// Forward declarations
class EApp;
class EGameStateMan;
class EWindow;

typedef int OVERALL_GAME_STATE;

// ============================================================================
// ESimsApp - Main application class for The Sims 2 GameCube
// Inherits from EApp (Maxis Engine base application class)
//
// Estimated minimum size: 0xD24 (3364 bytes)
// 31 known methods, ~38 known fields
//
// DVD ELF addresses (release map):
//   Constructor: 0x80004CE0 | Destructor: 0x80004D40
//   Vtable: 0x80579870 (224 bytes, 56 entries)
//   m_nameOfNgh: 0x80789F28 (16 bytes, .bss)
//
// DOL addresses (disc):
//   Constructor: 0x80004340 | Destructor: 0x80004398
//   Vtable: 0x8045AAF0 (224 bytes)
//   m_nameOfNgh: 0x804FB1D0 (16 bytes)
// ============================================================================

class ESimsApp /* : public EApp */ {
public:
    // --- Constructors / Destructors ---
    ESimsApp(void);   // DOL: 0x80004340 (88B) | DVD: 0x80004CE0 (96B)
    ~ESimsApp(void);  // DOL: 0x80004398 (48B) | DVD: 0x80004D40 (80B)

    // --- Lifecycle (virtual overrides from EApp) ---
    void Init(void);                           // DOL: 0x800044C8 (1732B)
    void initContinue(void);                   // DOL: 0x80004C80 (1936B)
    void ShowInitialDisplay(void);             // DOL: 0x80004B8C (244B)
    void Update(void);                         // DOL: 0x80005BA4 (264B)
    void Shutdown(void);                       // DOL: 0x800043C8 (236B)
    void UpdateAfterHotSync(void);             // DVD: 0x80007ECC (560B)

    // --- Update sub-functions (called from Update) ---
    void UpdateCheats(void);                   // DOL: 0x80005448 (116B)
    void UpdateApt(void);                      // DOL: 0x800054BC (88B)
    void UpdateGame(void);                     // DOL: 0x80005514 (64B)
    void UpdateShaders(float dt);              // DOL: 0x80005554 (412B)
    void UpdateAudio(void);                    // DOL: 0x800056F0 (92B)
    void UpdateDraw(void);                     // DOL: 0x80005808 (708B)
    void UpdateReset(void);                    // DOL: 0x80005ACC (216B)

    // --- Game state management ---
    void SetGameState(OVERALL_GAME_STATE);     // DOL: 0x80005410 (8B)
    void LoadSimulatorGlobs(void);             // DOL: 0x80005418 (32B)

    // --- Command line & configuration ---
    void parseCommandLine(void);               // DOL: 0x80004074 (716B)
    static int GetStartLot(void);              // DOL: 0x80003FDC (8B) - static, uses r13
    static void SetStartLot(int lot);          // DOL: 0x80003FE4 (8B) - static, uses r13
    void SetNghName(char* name);               // DOL: 0x80003FEC (136B)

    // --- Accessors (virtual overrides) ---
    const char* GetBuildVersion(void);         // DOL: 0x800044B4 (12B) -> "GameCube The Sims 2 Console Build F.09.12.0"
    int GetDefaultLanguage(void);              // DOL: 0x800044C0 (8B) -> 0 (English)
    const char* GetAppName(void);              // DOL: 0x80006380 (12B) -> "The Sims 2 Console"
    int GetEventTableSize(void);               // DOL: 0x8000638C (8B) -> 0
    const char* GetNghName(void);              // DOL: 0x80006394 (12B) -> m_nameOfNgh

    // --- Movie support ---
    void SetupForMovie(void);                  // DOL: 0x80005CAC (40B)
    void CleanupAfterMovie(void);              // DOL: 0x80005CD4 (40B)
    void* GetMovieHeap(void);                  // DOL: 0x80005CFC (48B)

    // --- Screenshot ---
    void TakeBigScreenshot(int w, int h);      // DOL: 0x80005D2C (20B)

    // --- Misc ---
    void ClearRecentlyBuiltFilesList(void);    // DVD: 0x800080FC (116B)

    // --- Static data ---
    static char m_nameOfNgh[16];               // DOL: 0x804FB1D0 | DVD: 0x80789F28

    // ======================================================================
    // FIELD LAYOUT (from assembly analysis of DOL)
    //
    // ESimsApp inherits EApp base class (~0x338 bytes).
    // Fields below offset 0x338 are from the EApp base.
    // Fields at 0x338+ are ESimsApp-specific.
    // ======================================================================

    // --- EApp base class data (offsets 0x000 - 0x337) ---
    // void** _vtable;                      // 0x000 - EApp vtable (set by EApp::EApp)
    // u8     _eapp_data[0x0FC];            // 0x004 - EApp internals
    // u32    m_fontResource;               // 0x0FC - font resource handle (Init checks if 0)
    // u8     _eapp_data2[0x238];           // 0x100 - more EApp internals

    // --- ESimsApp vtable pointer ---
    // void** m_simsVtable;                 // 0x338 - ESimsApp vtable (overrides EApp vtable at this offset)
    //                                      //         Set to &ESimsApp_vtable in ctor/dtor
    //                                      //         Used for virtual dispatch of ESimsApp methods

    // u8     _pad_33C[0x0C];              // 0x33C

    // --- Command line data (set by EApp::SetArgs) ---
    // int    m_argc;                       // 0x348 - argument count
    // char** m_argv;                       // 0x34C - argument array

    // u8     _pad_350[0x100];             // 0x350

    // --- Audio ---
    // u32    m_audioMuted;                 // 0x450 - audio mute flag (0=unmuted, checked in UpdateAudio)

    // u8     _pad_454[0x14];              // 0x454

    // --- Game state ---
    // OVERALL_GAME_STATE m_gameState;      // 0x468 - current game state enum (SetGameState writes here)

    // u8     _pad_46C[0x0C];              // 0x46C

    // --- Core subsystem pointers ---
    // EGameStateMan* m_gameStateMan;       // 0x478 - game state manager (Init creates, Shutdown destroys)
    // void*  m_currentRC;                  // 0x47C - current render context (ERC*), set during UpdateDraw
    // EWindow* m_window;                   // 0x480 - render window (Init creates, Shutdown destroys)
    // u8     m_flag_484;                   // 0x484 - unknown flag (zeroed in ctor/shutdown)
    // u8     _pad_485[3];                 // 0x485
    // u32    m_field_488;                  // 0x488 - unknown (zeroed in ctor/shutdown)

    // --- Controller auto-mapping flags ---
    // int    m_player1RemapPending;        // 0x48C - player 1 controller needs remapping (Update checks)
    // int    m_player2RemapPending;        // 0x490 - player 2 controller needs remapping (Update checks)

    // u8     _pad_494[4];                 // 0x494

    // --- Init state ---
    // u32    m_scratchPadInit;             // 0x498 - scratch pad initialization state (Init sets to 0)

    // --- Screenshot state ---
    // int    m_screenshotActive;           // 0x49C - screenshot in progress flag (TakeBigScreenshot sets to 1)
    // int    m_screenshotCols;             // 0x4A0 - screenshot grid width (TakeBigScreenshot)
    // int    m_screenshotRows;             // 0x4A4 - screenshot grid height (TakeBigScreenshot)

    // u8     _pad_4A8[0x878];             // 0x4A8

    // --- Resource data ---
    // u32    m_languageId;                 // 0xD20 - language ID (Init sets from GetDefaultLanguage)

    // Total estimated size: 0xD24 (3364 bytes)
    char _stub_data[0xD24];
};

#endif // ESIMSAPP_H
