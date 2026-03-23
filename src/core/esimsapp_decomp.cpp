// esimsapp_decomp.cpp - Decompiled ESimsApp class
// The Sims 2 GameCube - Main application class
//
// ESimsApp inherits from EApp (the Maxis Engine application base class).
// It implements the game-specific Init, Update, Shutdown, and state management.
//
// Build: GameCube The Sims 2 Console Build F.09.12.0
// Compiler: SN Systems ProDG for GameCube
// Source: c:\BuildAgent\cm3-build25-NGC\CMBuild\
//
// ============================================================================
// MAIN GAME LOOP FLOW:
//
//   EApp::Main()
//     -> EApp::SystemInit()
//       -> ESimsApp::Init()              -- one-time initialization
//         -> ESimsApp::GetDefaultLanguage()
//         -> EResourceManager::FreeUnreferencedResources()
//         -> EResourceManager::AddRef() (multiple resource groups)
//         -> vtable call: base class Init
//         -> EResourceManager::DelRef()
//         -> heap setup (14 heaps: Root, Main, Resource, VM, Debug, CUI,
//            Audio, Shader, Texture, Animation, Model, Flashes, Apt, + checkpoints)
//         -> EResourceManager::AddRefAll() (2 resource managers)
//         -> ESimsApp::SetNghName("DEFAULT.NGH")
//         -> EControllerManager::MapControllerCommands()
//         -> NghResFile setup (constructor + RegisterSection)
//         -> SerializeUIGameData::AllocateLoadBuffers()
//         -> EyeToyClient::Init()
//         -> EGameStateMan setup (constructor + AddState for game states)
//         -> EWindow (renderer) creation & SetClip
//         -> ESimsApp::initContinue()    -- deferred initialization
//         -> CTGDump::operator<<()
//       -> ESimsApp::ShowInitialDisplay() -- initial display setup (heap ops)
//
//     -> EApp::SystemUpdate() (called each frame)
//       -> ESimsApp::Update()            -- per-frame update
//         -> Controller mapping check (player 1 & 2)
//         -> ProfileHook()
//         -> ESimsApp::UpdateCheats()
//         -> ESimsApp::UpdateApt()       -- APT UI system update
//         -> ESimsApp::UpdateGame()      -- game simulation tick
//         -> ESimsApp::UpdateAudio()     -- audio system update
//         -> ESimsApp::UpdateShaders(0.0) -- shader/material update
//         -> ESimsApp::UpdateDraw()      -- rendering
//         -> ESimsApp::UpdateReset()     -- controller reset detection
//
//     -> ESimsApp::Shutdown()            -- cleanup on exit
//       -> EGlobal::BeginSaveGame()
//       -> Globs::Shutdown()
//       -> EResourceManager::Free() (conditional)
//       -> StateMachineManager::Shutdown()
//       -> EGameStateMan::DeleteAllStates()
//       -> EGameStateMan::~EGameStateMan()
//       -> EGlobal::Reset()
//       -> EyeToyClient::Shutdown()
//       -> EWindow::~EWindow() (via vtable)
//       -> EResourceManager::Shutdown()
//       -> CTGDump::Shutdown()
// ============================================================================

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// Forward declarations for external functions/globals used by ESimsApp
// ============================================================================

// Heap management functions - each returns/initializes a specific heap
extern void RootHeap();
extern void MainHeap();
extern void ResourceHeap();
extern void VMHeap();
extern void DebugHeap();
extern void CUIHeap();
extern void AudioHeap();
extern void ShaderHeap();
extern void TextureHeap();
extern void AnimationHeap();
extern void ModelHeap();
extern void FlashesHeap();
extern void AptHeap();

// EAHeap operations
namespace EAHeap {
    extern void SetNextCheckPoint();
    extern void Compact();
    extern void* MallocAligned(u32 size, u32 align, u32 flags, int heap);
    extern void* Calloc(u32 count, u32 size, int flags);
}

extern void* operator_new(u32 size);  // __builtin_new at 0x802d11b0
extern void  operator_delete(void*);  // __builtin_delete at 0x802d1220

// Global subsystem managers
class EGlobal;
class GameData;
class EControllerManager;
class StateMachineManager;
class EResourceManager;
class EGameStateMan;
class AptViewer;
class EyeToyClient;
class NghResFile;
class EWindow;
class UIAUDIO;
class EShader;
class ERShader;
class ENgcMemoryCard;
class LoadingScreenStateMachine;
class PlayerCheats;
class BString2;
class CTGDump;

// C runtime
extern int   strcmp(const char*, const char*);
extern int   strcasecmp(const char*, const char*);
extern int   strncasecmp(const char*, const char*, int);
extern char* strcpy(char*, const char*);
extern char* strncpy(char*, const char*, int);
extern char* strstr(const char*, const char*);
extern int   strlen(const char*);
extern int   AtoI(const char*);
extern void  Sprintf(char*, const char*, ...);

// Printf-like debug output
extern void  OSReport(const char*, ...);

// ============================================================================
// Global/static variables (in .sdata/.sbss, accessed via r13 register)
// ============================================================================

// r13 + offset  -> meaning (from assembly analysis)
// -32760 (0x8008) -> reset timer (float)
// -32756 (0x800C) -> test mode flag
// -32752 (0x8010) -> s_startLot (int)
// -31536 (0x84D0) -> UIAUDIO* instance
// -31444 (0x852C) -> NghResFile registry handle
// -28404 (0x910C) -> APT system initialized flag
// -26800 (0x9750) -> deltaTime (float)
// -26748 (0x9784) -> pause game flag
// -26656 (0x97E0) -> resource manager 2 pointer
// -26652 (0x97E4) -> resource manager 2 flag
// -26532 (0x985C) -> ??? pointer
// -26524 (0x9864) -> EControllerManager* instance
// -26512 (0x9870) -> ??? pointer (for UpdateReset)
// -26392 (0x98E8) -> ??? pointer (renderer context)
// -24620 (0x9FD4) -> ??? pointer (shader data)
// -24588 (0x9FF4) -> CTGDump area
// -21500 (0xAC04) -> StateMachineManager* instance
// -21496 (0xAC08) -> ??? pointer (time scale / movie controller)
// -21492 (0xAC0C) -> cSoundPlayer* instance

// ============================================================================
// ESimsApp::m_nameOfNgh - static member (16 bytes in .bss)
// Address: 0x804FB1D0 (DOL) / 0x80789F28 (DVD ELF)
// ============================================================================

// This is a 16-byte static buffer holding the current neighborhood filename.
// static char ESimsApp::m_nameOfNgh[16];

// ============================================================================
// STRUCT LAYOUT (from header + assembly analysis)
//
// ESimsApp inherits from EApp. Key fields at known offsets from 'this':
//
//   +0x000  void** _vtable        - EApp/ESimsApp vtable pointer
//   ...     (EApp base class fields, ~0x338 bytes)
//   +0x338  void*  m_vtable2      - secondary vtable (set in ctor)
//   +0x348  int    m_argc         - command line argument count
//   +0x34C  char** m_argv         - command line argument array
//   +0x450  void*  m_audio        - audio system pointer
//   +0x468  OVERALL_GAME_STATE m_gameState
//   +0x478  void*  m_gameStateMan - EGameStateMan pointer
//   +0x47C  void*  m_draw         - current draw context (ERC*)
//   +0x480  void*  m_window       - EWindow pointer
//   +0x484  u8     m_flag_484     - unknown flag
//   +0x488  void*  m_field_488    - unknown
//   +0x48C  int    m_player1Flag  - player 1 controller remap pending
//   +0x490  int    m_player2Flag  - player 2 controller remap pending
//   +0x498  void*  m_field_498    - unknown
//   +0x49C  int    m_screenshotFlag  - screenshot in progress
//   +0x4A0  int    m_screenshotW  - screenshot width
//   +0x4A4  int    m_screenshotH  - screenshot height
//   +0xD20  void*  m_field_D20    - unknown (set during Init)
// ============================================================================


// ============================================================================
// ESimsApp::GetStartLot
// Address: 0x80003FDC | Size: 8 bytes
// Returns the starting lot number from a global/static variable.
// ============================================================================
// int ESimsApp::GetStartLot() {
//     return s_startLot;  // lwz r3, -32752(r13) -- loads from r13-relative static
// }


// ============================================================================
// ESimsApp::SetStartLot
// Address: 0x80003FE4 | Size: 8 bytes
// Sets the starting lot number in a global/static variable.
// ============================================================================
// void ESimsApp::SetStartLot(int lot) {
//     s_startLot = lot;  // stw r4, -32752(r13)
// }


// ============================================================================
// ESimsApp::SetNghName
// Address: 0x80003FEC | Size: 136 bytes
//
// Sets the neighborhood filename. Validates the name by checking for ".ngh"
// or ".NGH" extensions, ensures length > 4, and copies up to 15 chars
// into the static m_nameOfNgh buffer (null-terminated).
// ============================================================================
// void ESimsApp::SetNghName(char* name) {
//     // Check if name contains ".ngh" extension
//     if (strstr(name, ".ngh") == NULL) {
//         // If no lowercase, check uppercase
//         if (strstr(name, ".NGH") == NULL) {
//             return;  // No valid NGH extension found
//         }
//     }
//
//     // Validate minimum length (must be > 4 chars, i.e. more than just extension)
//     if (strlen(name) <= 4) {
//         return;
//     }
//
//     // Copy up to 15 characters to static buffer, null-terminate
//     strncpy(m_nameOfNgh, name, 16);
//     m_nameOfNgh[15] = '\0';
// }


// ============================================================================
// ESimsApp::parseCommandLine
// Address: 0x80004074 | Size: 716 bytes
//
// Parses command-line arguments. On GameCube this processes args passed
// from the debug host. Supports:
//   -lot <N>  : Set starting lot (1-16)
//   -ngh <X>  : Set neighborhood file
//   -test     : Enable test mode
//   -test_listen : Enable test listen mode
//   -test_NGC : Enable NGC test mode
//
// Arguments are space-delimited within each argv string. The function
// handles both separate argv entries and space-separated values within
// a single argv string.
// ============================================================================
// void ESimsApp::parseCommandLine() {
//     int argc = this->m_argc;     // offset 0x348
//     char** argv = this->m_argv;  // offset 0x34C
//
//     // Clear a global flag at r9 offset
//     // g_debugFlag = 0;
//
//     OSReport("------ Entering parseCommandLine()\n");
//     OSReport("Argc: %d, Argv: %08X\n", argc, argv);
//
//     // Print all arguments
//     for (int i = 0; i < argc; i++) {
//         OSReport("Argv[%d]: %s\n", i, argv[i]);
//     }
//
//     if (argv == NULL || argc <= 0 || argv[0] == NULL) {
//         return;
//     }
//
//     // Copy first arg (program name) to a global buffer
//     // strcpy(g_debugBuffer, argv[0]);  // at r13 - 6480
//
//     if (argc <= 1) {
//         return;
//     }
//
//     int argIdx = 0;
//     while (argIdx < argc) {
//         char* arg = argv[0];
//         argIdx++;
//         argv++;
//
//         // Split on spaces within the argument string
//         char* nextToken = NULL;
//         char* spacePos = strchr(arg, ' ');  // actually uses strchr with ' '
//         if (spacePos != NULL) {
//             *spacePos = '\0';   // null-terminate current token
//             nextToken = spacePos + 1;
//             // Find next space in remainder
//             char* space2 = strchr(nextToken, ' ');
//             if (space2 != NULL) {
//                 *space2 = '\0';
//             }
//         }
//
//         int consumed = 0;
//         bool hasNextArg = (argIdx < argc);  // cr3
//
//         if (arg[0] != '-') {
//             goto end_of_arg;  // Not a flag
//         }
//
//         arg++;  // skip the '-'
//
//         // Determine the value parameter (either from next arg or token after space)
//         char* value = NULL;
//         if (!hasNextArg) {
//             // No more args
//         } else {
//             value = argv[0];  // peek at next argv
//         }
//         if (spacePos != NULL) {
//             value = spacePos + 1;  // use space-separated value
//         }
//         if (value != NULL && value[0] == '\0') {
//             value = NULL;
//         }
//
//         // Parse the flag character
//         switch (arg[0]) {
//             case 'L':
//             case 'l':
//                 // -lot <N>: Set starting lot
//                 if (strncasecmp(arg, "lot", 3) == 0) {
//                     int lot = AtoI(value);
//                     if ((unsigned)(lot - 1) <= 15) {  // lot 1..16
//                         s_startLot = lot;
//                     }
//                     consumed = 1;
//                 }
//                 break;
//
//             case 'N':
//             case 'n':
//                 // -ngh <name>: Set neighborhood file
//                 if (strncasecmp(arg, "ngh", 3) == 0) {
//                     consumed = 1;
//                     this->SetNghName(value);
//                 }
//                 break;
//
//             case 'T':
//             case 't':
//                 // -test, -test_listen, -test_NGC
//                 if (strcasecmp(arg, "test_listen") == 0) {
//                     s_testMode = 1;
//                 } else if (strcasecmp(arg, "test_NGC") != 0) {
//                     // Not test_NGC either, check just "test"
//                     if (strcasecmp(arg, "test") == 0) {
//                         if (value != NULL) {
//                             s_testMode = 1;
//                         }
//                     }
//                 } else {
//                     s_testMode = 1;
//                 }
//                 break;
//
//             default:
//                 break;
//         }
//
//     end_of_arg:
//         // If we consumed a value argument, handle continuation from space-split
//         if (consumed != 0) {
//             if (spacePos != NULL) {
//                 // Already consumed via space-split, continue within same string
//                 spacePos = nextToken;
//             }
//             consumed = 0;
//         }
//         if (spacePos != NULL) {
//             arg = spacePos;
//             continue;  // re-parse the remainder
//         }
//
//         if (consumed != 0) {
//             argIdx += consumed;
//             argv += consumed;
//         }
//     }
// }


// ============================================================================
// ESimsApp::ESimsApp (Constructor)
// Address: 0x80004340 | Size: 88 bytes
//
// Initializes the ESimsApp object. Calls the parent EApp constructor,
// sets up the vtable pointer, and zeroes out key member fields.
// ============================================================================
// ESimsApp::ESimsApp() {
//     EApp::EApp();  // Call parent constructor (0x802e2180)
//
//     // Set vtable to ESimsApp's vtable
//     this->m_vtable2 = &ESimsApp_vtable;  // 0x8045AAF0 stored at offset 0x338
//
//     // Zero-initialize key fields
//     this->m_player2Flag = 0;     // offset 0x490
//     this->m_gameStateMan = NULL; // offset 0x478
//     this->m_window = NULL;       // offset 0x480
//     this->m_flag_484 = 0;        // offset 0x484
//     this->m_field_488 = 0;       // offset 0x488
//     this->m_player1Flag = 0;     // offset 0x48C
// }


// ============================================================================
// ESimsApp::~ESimsApp (Destructor)
// Address: 0x80004398 | Size: 48 bytes
//
// Resets vtable to ESimsApp's vtable (for correct virtual dispatch during
// destruction), then calls the parent EApp destructor.
// ============================================================================
// ESimsApp::~ESimsApp() {
//     this->m_vtable2 = &ESimsApp_vtable;  // Reset vtable at offset 0x338
//     EApp::~EApp();  // Call parent destructor (0x802e21e0)
// }


// ============================================================================
// ESimsApp::Shutdown
// Address: 0x800043C8 | Size: 236 bytes
//
// Full shutdown sequence. Tears down all game subsystems in reverse order
// of initialization.
// ============================================================================
// void ESimsApp::Shutdown() {
//     // 1. Begin save game (auto-save on exit)
//     EGlobal::BeginSaveGame(g_pEGlobal);  // 0x80041ac0
//
//     // 2. Shutdown global sim data
//     Globs::Shutdown(g_pGlobs);  // 0x800b82d4
//
//     // 3. Free resource manager 2 if it exists
//     if (g_resourceManager2_exists != 0) {  // r13-17472
//         void* resMgr2 = g_pResourceManager2;  // r13-26656
//         if (resMgr2 != NULL) {
//             EResourceManager::Free(g_resourceManager2_data, resMgr2);
//             g_pResourceManager2_flag = 0;  // r13-26652
//             g_pResourceManager2 = NULL;    // r13-26656
//         }
//     }
//
//     // 4. Shutdown state machine manager
//     StateMachineManager::Shutdown();  // 0x800966e0
//
//     // 5. Delete all game states and the state manager
//     EGameStateMan* gsm = this->m_gameStateMan;  // offset 0x478
//     EGameStateMan::DeleteAllStates(gsm);  // 0x80089c10
//     if (gsm != NULL) {
//         EGameStateMan::~EGameStateMan(gsm, 3);  // destructor + dealloc
//     }
//
//     // 6. Clear pointers and flags
//     this->m_field_488 = 0;        // offset 0x488
//     this->m_gameStateMan = NULL;  // offset 0x478
//     this->m_flag_484 = 0;         // offset 0x484
//
//     // 7. Reset global game state
//     EGlobal::Reset(g_pEGlobal);  // 0x8003f450
//
//     // 8. Shutdown EyeToy client
//     EyeToyClient::Shutdown();  // 0x80038634
//
//     // 9. Destroy the render window (via vtable call)
//     EWindow* win = this->m_window;  // offset 0x480
//     if (win != NULL) {
//         // Virtual destructor call through vtable
//         // win->vtable[offset 0x9C] gives the destructor entry
//         // Calls with mode=3 (destructor + deallocate)
//         win->~EWindow(3);  // vtable dispatch at offsets 0x08/0x0C
//     }
//
//     // 10. Shutdown resource manager
//     EResourceManager::Shutdown(g_pResourceManager);  // 0x80325728
//
//     // 11. Shutdown CTGDump
//     CTGDump::Shutdown(r13 - 24588);  // 0x800a5184
// }


// ============================================================================
// ESimsApp::GetBuildVersion
// Address: 0x800044B4 | Size: 12 bytes
// Returns a pointer to the build version string.
// ============================================================================
// const char* ESimsApp::GetBuildVersion() {
//     return "GameCube The Sims 2 Console Build F.09.12.0";
// }


// ============================================================================
// ESimsApp::GetDefaultLanguage
// Address: 0x800044C0 | Size: 8 bytes
// Returns the default language ID. Always 0 (English) on GameCube.
// ============================================================================
// int ESimsApp::GetDefaultLanguage() {
//     return 0;  // English
// }


// ============================================================================
// ESimsApp::Init
// Address: 0x800044C8 | Size: 1732 bytes
//
// Main initialization function. This is a massive function that sets up
// the entire game engine. Called once during EApp::SystemInit().
//
// Initialization sequence:
// 1.  Get default language
// 2.  Free unreferenced resources
// 3.  Add resource references for multiple resource groups
//     (14 heap regions: Root, Main, Resource, VM, Audio, Shader, Texture,
//      Animation, Model, Flashes, Apt, Debug, CUI + checkpoints)
// 4.  Load localized Sims 2 logo
// 5.  Call parent class Init via vtable
// 6.  Delete temporary resource reference
// 7.  Register EResource paths (e.g. "levels")
// 8.  Perform second round of heap setup (same 14 heaps again)
// 9.  Get game font ID and load intro requirements
// 10. Check for template_person data
// 11. Map controller commands
// 12. Create NghResFile and register sections (if not already created)
// 13. Allocate load buffers for save data
// 14. Third round of heap operations
// 15. Initialize EyeToy client
// 16. Fourth round of heap operations
// 17. Create EGameStateMan and add game states
// 18. Fifth round of heap operations
// 19. Set scratch pad init value
// 20. Allocate EWindow for rendering, set clip rect
// 21. Call initContinue() for deferred setup
// 22. Initialize CTGDump
// 23. Final resource cleanup
// ============================================================================
// void ESimsApp::Init() {
//     // Step 1: Get language setting
//     int language = this->GetDefaultLanguage();  // Always 0 on GC
//
//     // Step 2: Free unreferenced resources from any prior state
//     EResourceManager::FreeUnreferencedResources(g_pResourceManager1);
//
//     // Store language in resource manager's field at offset 0xD20
//     g_pResourceManager1->m_field_D20 = language;
//
//     // Step 3: Add resource references with magic IDs
//     // These register heap regions with the resource system using 32-bit hash keys
//     EResourceManager::AddRef(g_pResourceManager2, 0x7F5ABC2D, NULL, 0);
//
//     // Load localized logo
//     void* logo = GameData::GetLocalizedSims2Logo(g_pGameData);
//     EResourceManager::AddRef(g_pResourceManager2, (u32)logo, NULL, 0);
//
//     // Call parent class Init via vtable (offset 0x98/0x9C in vtable at offset 0x338)
//     // This calls EApp::Init() base class implementation
//     {
//         void** vtable = this->m_vtable2;  // offset 0x338
//         // vtable[0x98] = offset, vtable[0x9C] = function pointer
//         void (*initFn)(void*) = vtable[0x9C/4];
//         int offset = (s16)vtable[0x98/4];
//         initFn((char*)this + offset);
//     }
//
//     // Remove logo resource reference
//     EResourceManager::DelRef(g_pResourceManager2, (u32)logo, 1);
//
//     // Step 4: Init EResourceManager with path "levels" (if applicable)
//     EResourceManager::Init(g_pResourceManager_main, "levels");
//
//     // Step 5-6: Multiple rounds of heap initialization
//     // Each round calls all 14 heap functions followed by EAHeap::Compact():
//     //   RootHeap(); Compact(); MainHeap(); Compact(); ResourceHeap(); Compact();
//     //   AudioHeap(); Compact(); VMHeap(); Compact(); ShaderHeap(); Compact();
//     //   TextureHeap(); Compact(); AnimationHeap(); Compact(); ModelHeap(); Compact();
//     //   FlashesHeap(); Compact(); AptHeap(); Compact(); DebugHeap(); Compact();
//     //   CUIHeap(); Compact(); EAHeap::SetNextCheckPoint();
//     // This pattern repeats 5 times during Init with different operations in between.
//
//     // Step 7: Set default neighborhood name
//     this->SetNghName("DEFAULT.NGH");
//
//     // Step 8: Map controller commands
//     {
//         void* ctrlMgr = g_pEControllerManager;  // r13-26532
//         // Get command table and map buttons to game commands
//         EControllerManager::MapControllerCommands(ctrlMgr, g_btnToCmdAssoc, g_btnToCmdAssocSize);
//     }
//
//     // Step 9: Check if font resource exists and conditionally load
//     if (g_pEGlobal->m_field_0FC == 0) {  // g_pEGlobal at offset 0xFC
//         EResourceManager::AddRef(g_pResourceManager2, 0x1A18CA65, NULL, 0);
//         g_pEGlobal->m_field_0FC = result;
//     }
//
//     // Step 10: Parse command line
//     this->parseCommandLine();
//
//     // Step 11: Set up BString2 for resource path
//     BString2::operator=(g_pBString, L"...");  // wide string assignment
//
//     // (More heap Compact rounds...)
//
//     // Step 12: Get game font and load intro
//     u32 fontID = EGlobal::GetGameFontID(g_pEGlobal);
//     EResourceManager::AddRef(g_pResourceManager_main2, fontID, NULL, 0);
//     // (Heap rounds...)
//     EGlobal::LoadIntroRequirements(g_pEGlobal);
//
//     // Step 13: Check for template_person name match
//     // strcmp on a string at offset 0x1A4 in g_pEGlobal
//     // if (strcmp(g_pEGlobal + 0x1A4, "") != 0 && s_testMode == 0) {
//     //     s_testMode = 1;
//     // }
//
//     // Step 14: Create NghResFile (neighborhood resource file handler)
//     if (g_pNghResFile == NULL) {  // r13-32056
//         void* mem = operator_new(548);
//         g_pNghResFile = NghResFile::NghResFile(mem);
//         if (g_pNghResFile != NULL && g_nghRegistryHandle == NULL) {
//             // Register section handlers for save/load
//             g_nghRegistryHandle = NghResFile::RegisterSection(
//                 g_pNghResFile,
//                 0x55697878,  // registry ID "Uixx"
//                 saveHandler,   // 0x800105e8
//                 loadHandler,   // 0x80010464
//                 resetHandler   // 0x80010728
//             );
//         }
//         SerializeUIGameData::AllocateLoadBuffers();
//     }
//
//     // Step 15: (Heap rounds...)
//     // Step 16: Init EyeToy client
//     EyeToyClient::Init();
//
//     // Step 17: (More heap rounds...)
//
//     // Step 18: Create game state manager
//     void* gsmMem = operator_new(20);
//     EGameStateMan* gsm = EGameStateMan::EGameStateMan(gsmMem);
//     this->m_gameStateMan = gsm;  // offset 0x478
//
//     // Add game states
//     // State 1: allocated with EAHeap::Calloc(12, 1, 0)
//     void* state1Mem = EAHeap::Calloc(12, 1, 0);
//     void* state1 = SomeGameState1::SomeGameState1(state1Mem);
//     EGameStateMan::AddState(gsm, state1);
//
//     // State 2: allocated with EAHeap::Calloc(88, 1, 0)
//     void* state2Mem = EAHeap::Calloc(88, 1, 0);
//     void* state2 = SomeGameState2::SomeGameState2(state2Mem);
//     EGameStateMan::AddState(gsm, state2);
//
//     // Step 19: Set black graphics background
//     GameData::SetBlackGraphicsBackgroundColor(g_pGameData);
//     ESimScratchPadMan::InitHeap();
//
//     // Step 20: Initialize scratch pad
//     this->m_field_498 = 0;  // offset 0x498
//
//     // Step 21: Create render window
//     // Allocate with MallocAligned(160, 16, 0, 0) -> EWindow constructor
//     void* winMem = EAHeap::MallocAligned(160, 16, 0, 0);
//     EWindow* win = EWindow::EWindow(winMem);
//     this->m_window = win;  // offset 0x480
//
//     if (win != NULL) {
//         // Set clip rectangle (float values from rodata)
//         TRect<float> clipRect;
//         clipRect.left = 0.0f;
//         clipRect.top = 0.0f;
//         clipRect.right = 1.0f;
//         clipRect.bottom = 1.0f;
//         EWindow::SetClip(win, &clipRect);
//     }
//
//     // Step 22: Call initContinue for deferred initialization
//     this->initContinue();
//
//     // Step 23: Init CTGDump
//     CTGDump::operator<<(g_ctgDump, "Allocating CTGDump object memory\n");
//
//     // Step 24: Final resource cleanup
//     EResourceManager::DelRef(g_pResourceManager_main2, "introload", 1);
//
//     // Final heap operations
//     // (14 heaps + compact + checkpoint)
// }


// ============================================================================
// ESimsApp::ShowInitialDisplay
// Address: 0x80004B8C | Size: 244 bytes
//
// Sets up the initial display by performing heap operations. This is mostly
// heap management - two rounds of all 14 heaps with Compact() calls.
// Called after Init() completes but before the first Update().
// ============================================================================
// void ESimsApp::ShowInitialDisplay() {
//     // Round 1: Initialize all heaps with compact
//     RootHeap(); EAHeap::Compact();
//     MainHeap(); EAHeap::Compact();
//     ResourceHeap(); EAHeap::Compact();
//     AudioHeap(); EAHeap::Compact();
//     VMHeap(); EAHeap::Compact();
//     ShaderHeap(); EAHeap::Compact();
//     TextureHeap(); EAHeap::Compact();
//     AnimationHeap(); EAHeap::Compact();
//     ModelHeap(); EAHeap::Compact();
//     FlashesHeap(); EAHeap::Compact();
//     AptHeap(); EAHeap::Compact();
//     DebugHeap(); EAHeap::Compact();
//     CUIHeap(); EAHeap::Compact();
//     EAHeap::SetNextCheckPoint();
//
//     // Round 2: Same sequence again
//     RootHeap(); EAHeap::Compact();
//     MainHeap(); EAHeap::Compact();
//     ResourceHeap(); EAHeap::Compact();
//     AudioHeap(); EAHeap::Compact();
//     VMHeap(); EAHeap::Compact();
//     ShaderHeap(); EAHeap::Compact();
//     TextureHeap(); EAHeap::Compact();
//     AnimationHeap(); EAHeap::Compact();
//     ModelHeap(); EAHeap::Compact();
//     FlashesHeap(); EAHeap::Compact();
//     AptHeap(); EAHeap::Compact();
//     DebugHeap(); EAHeap::Compact();
//     CUIHeap(); EAHeap::Compact();
//     EAHeap::SetNextCheckPoint();
// }


// ============================================================================
// ESimsApp::SetGameState
// Address: 0x80005410 | Size: 8 bytes
// Sets the current game state enum at offset 0x468 in the ESimsApp object.
// ============================================================================
// void ESimsApp::SetGameState(OVERALL_GAME_STATE state) {
//     this->m_gameState = state;  // stw r4, 0x468(r3)
// }


// ============================================================================
// ESimsApp::LoadSimulatorGlobs
// Address: 0x80005418 | Size: 32 bytes
// Wrapper that calls InitPerformanceCounter to set up timing infrastructure.
// ============================================================================
// void ESimsApp::LoadSimulatorGlobs() {
//     InitPerformanceCounter();  // 0x8007d748
// }


// ============================================================================
// ESimsApp::UpdateCheats
// Address: 0x80005448 | Size: 116 bytes
//
// Checks if any controller has pressed a cheat button combination.
// If detected, passes the controller to PlayerCheats::Capture().
// ============================================================================
// void ESimsApp::UpdateCheats() {
//     EControllerManager* ctrlMgr = g_pEControllerManager;  // r13-26524
//     if (ctrlMgr == NULL) {
//         return;
//     }
//
//     // Get controller index for player 0
//     u32 ctrlIdx = EControllerManager::GetPlayerControllerIndex(ctrlMgr, 0);
//     // Get the actual controller object
//     EController* ctrl = EControllerManager::GetController(ctrlMgr, ctrlIdx);
//     if (ctrl == NULL) {
//         return;
//     }
//
//     // Check if any button was pressed (mask = -1 means all buttons)
//     u32 pressed = EController::GetBtnPressedMask(ctrl, -1);
//     if (pressed == 0) {
//         return;
//     }
//
//     // A cheat button was pressed - capture it
//     PlayerCheats::Capture(g_pPlayerCheats, ctrl);
// }


// ============================================================================
// ESimsApp::UpdateApt
// Address: 0x800054BC | Size: 88 bytes
//
// Updates the APT (ActionScript) UI system. Only runs if APT is initialized.
// Calls NewReadController to process input, then UpdateAll for rendering.
// ============================================================================
// void ESimsApp::UpdateApt() {
//     if (g_aptInitialized == 0) {  // r13-28404
//         return;
//     }
//
//     AptViewer* viewer = g_pEGlobal->m_aptViewer;  // offset 0xB4 in EGlobal
//
//     // Process controller input for APT UI
//     AptViewer::NewReadController(viewer, 0, false, 0, true);
//
//     // Update all APT elements
//     AptViewer::UpdateAll(viewer);
// }


// ============================================================================
// ESimsApp::UpdateGame
// Address: 0x80005514 | Size: 64 bytes
//
// Updates the game simulation. If not paused, ticks the state machine
// manager. Always updates the copyright/GameData with delta time.
// ============================================================================
// void ESimsApp::UpdateGame() {
//     // Check if game is paused
//     if (g_pauseGame == 0) {  // r13-26748
//         // Tick all state machines with delta time
//         StateMachineManager::UpdateMachines(g_deltaTime);  // r13-26800
//     }
//
//     // Update copyright/game data (always runs, even when paused)
//     GameData::CopyrightUpdate(g_pGameData, g_deltaTime);
// }


// ============================================================================
// ESimsApp::UpdateShaders
// Address: 0x80005554 | Size: 412 bytes
//
// Updates shader/material system. Handles time-scaling for shader animations,
// queries the current render state for shader parameters, and dispatches
// updates to EShader and ERShader systems.
//
// Parameters:
//   dt - delta time (0.0 means use the global delta time)
// ============================================================================
// void ESimsApp::UpdateShaders(float dt) {
//     float shaderDt = dt;
//     float renderDt = dt;
//
//     // If dt is 0.0, use global delta time
//     if (dt == 0.0f) {
//         shaderDt = g_deltaTime;
//     }
//     renderDt = dt;
//     if (dt == 0.0f) {
//         renderDt = g_deltaTime;
//     }
//
//     void* timeScaleObj = g_pTimeScaleObj;  // r13-21496
//     int shaderParam1 = 0;
//     int shaderParam3 = 0;
//     int shaderParam2 = 0;
//
//     // Query time scale object if it exists
//     if (timeScaleObj != NULL) {
//         // Check if "something is active" via vtable calls at offsets 0x80/0x84
//         int isActive = vtable_call_80(timeScaleObj);
//         if (isActive == 1) {
//             // Check "is paused" via vtable calls at offsets 0x70/0x74
//             int isPaused = vtable_call_70(timeScaleObj);
//             if (isPaused == 0) {
//                 // Check another state via offsets 0x68/0x6C
//                 int otherState = vtable_call_68(timeScaleObj);
//                 if (otherState == 0) {
//                     // Get time scale factor via offsets 0x10/0x14
//                     float scale = vtable_call_10(timeScaleObj);
//                     shaderDt *= scale;
//                 } else {
//                     shaderDt = 0.0f;
//                 }
//             } else {
//                 shaderDt = 0.0f;
//             }
//             renderDt = shaderDt;
//         }
//     } else {
//         // No time scale object - check alternate data source
//         void* altData = g_pAltShaderData;  // r13-24620
//         if (altData != NULL) {
//             shaderParam2 = *(int*)((char*)altData + 208);
//             renderDt = *(float*)((char*)altData + 196);
//             shaderParam1 = *(int*)((char*)altData + 200);
//             shaderParam3 = *(int*)((char*)altData + 204);
//         }
//     }
//
//     // Query shader parameters from the current render state if available
//     if (timeScaleObj != NULL) {
//         void* renderState = g_pEGlobal->m_renderState;  // offset 0xC8
//         if (renderState != NULL) {
//             // Get shader parameter indices via vtable calls at 0x30/0x34
//             shaderParam1 = vtable_call_30(timeScaleObj, 0);   // param index 0
//             shaderParam3 = vtable_call_30(timeScaleObj, 5);   // param index 5
//             shaderParam2 = *(u8*)((char*)renderState + 51);   // byte at offset 0x33
//         }
//     }
//
//     // Update all shaders
//     EShader::UpdateAll(shaderDt);
//
//     // Update all render shaders with full parameter set
//     ERShader::UpdateAll(renderDt, shaderParam1, shaderParam3, shaderParam2);
// }


// ============================================================================
// ESimsApp::UpdateAudio
// Address: 0x800056F0 | Size: 92 bytes
//
// Updates the audio system. If audio is not muted (m_audio field == 0),
// updates the sound player. Also lazily initializes and updates UIAUDIO.
// ============================================================================
// void ESimsApp::UpdateAudio() {
//     // Check if audio is muted (offset 0x450 in ESimsApp)
//     if (this->m_audio == 0) {
//         // Audio not muted - update sound player if it exists
//         cSoundPlayer* soundPlayer = g_pSoundPlayer;  // r13-21492
//         if (soundPlayer != NULL) {
//             cSoundPlayer::Update(soundPlayer);
//         }
//     }
//
//     // Lazy-initialize UIAUDIO singleton
//     if (g_pUIAudio == NULL) {  // r13-31536
//         void* mem = operator_new(120);  // sizeof(UIAUDIO) = 0x78
//         g_pUIAudio = UIAUDIO::UIAUDIO(mem);
//     }
//
//     // Update UI audio
//     UIAUDIO::Update(g_pUIAudio);
// }


// ============================================================================
// ESimsApp::UpdateDraw
// Address: 0x80005808 | Size: 708 bytes
//
// Main rendering function. Handles single-screen and split-screen rendering.
//
// Flow:
// 1. Begin render pass (get ERC from renderer)
// 2. Draw topmost state machines (overlays)
// 3. Draw game via DrawGame callback
// 4. Draw copyright overlay
// 5. End render pass
// 6. If screenshot mode is active, render each tile of the big screenshot
//    using EWindow::ScaleForScreenshot for tiled rendering
// 7. After screenshot, clean up
// ============================================================================
// void ESimsApp::UpdateDraw() {
//     // Get render context for player 0
//     void* renderer = g_pRenderer;  // r13-26392
//     ERC* rc = renderer->BeginRenderPass(0);  // vtable offset 0x80/0x84
//     this->m_draw = rc;  // offset 0x47C
//
//     // Draw topmost UI elements (loading screens, etc.)
//     DrawGame(rc);  // 0x8000574c
//
//     // Draw topmost state machine overlays
//     StateMachineManager::DrawTopmostMachines(rc);
//
//     // Draw copyright/legal text
//     GameData::CopyrightDraw(g_pGameData, rc);
//
//     // End render pass
//     renderer->EndRenderPass(rc);  // vtable offset 0x88/0x8C
//
//     this->m_draw = NULL;
//
//     // Check if big screenshot is pending
//     int screenshotFlag = this->m_screenshotFlag;  // offset 0x49C
//     if (screenshotFlag == 0) {
//         return;  // No screenshot - done
//     }
//
//     // -- Screenshot rendering (tiled approach) --
//     // Iterates over a grid of tiles to capture a high-res screenshot
//     // using EWindow::ScaleForScreenshot for each tile
//
//     // Begin fullscreen render
//     renderer->BeginFullScreenRender();  // vtable offset 0x38/0x3C
//
//     int numRows = this->m_screenshotH;  // offset 0x4A4
//     int numCols = this->m_screenshotW;  // offset 0x4A0
//
//     for (int row = 0; row < numRows; row++) {
//         for (int col = 0; col < numCols; col++) {
//             // Scale the viewport for this tile
//             EWindow::ScaleForScreenshot(1, col, numCols, row, numRows);
//
//             // Begin render pass for tile
//             renderer->BeginTileRender();  // vtable offset 0x30/0x34
//             rc = renderer->BeginRenderPass(0);
//             this->m_draw = rc;
//
//             // Create temp window and render into it
//             EWindow tempWin;
//             EWindow::Select(&tempWin, rc);
//             DrawGame(rc);
//
//             renderer->EndRenderPass(rc);
//
//             // End tile render
//             renderer->EndTileRender();
//
//             // Generate filename and save tile
//             char filename[160];
//             Sprintf(filename, "pic_%02d_%02d", col + 1, row + 1);
//             renderer->SaveScreenshot(filename);  // vtable offset 0x168/0x16C
//         }
//     }
//
//     // Final cleanup pass
//     EWindow::ScaleForScreenshot(1, 1, 1, 0, 0);
//     renderer->BeginTileRender();
//     rc = renderer->BeginRenderPass(0);
//     this->m_draw = rc;
//     EWindow tempWin2;
//     EWindow::Select(&tempWin2, rc);
//     StateMachineManager::DrawMachines(rc);
//     renderer->EndRenderPass(rc);
//     renderer->EndTileRender();
//
//     // Reset screenshot mode
//     EWindow::ScaleForScreenshot(0, 1, 1, 0, 0);
//     this->m_screenshotFlag = 0;  // offset 0x49C
//     EWindow::~EWindow(&tempWin2, 2);
// }


// ============================================================================
// ESimsApp::UpdateReset
// Address: 0x80005ACC | Size: 216 bytes
//
// Checks if the reset button combination is held. If the controller manager
// reports the reset command (command ID 0x1B = 27) is active, accumulates
// a timer. When the timer exceeds a threshold (~2 seconds), triggers a
// console soft reset via the renderer.
// ============================================================================
// void ESimsApp::UpdateReset() {
//     EControllerManager* ctrlMgr = g_pEControllerManager;  // r13-26524
//     if (ctrlMgr == NULL) {
//         return;
//     }
//
//     // Check for reset button combo across all controllers
//     // Command 0x1B = reset combo, uses custom comparison functions
//     u8 resetData[8] = { /* loaded from rodata at 0x803CB020 */ };
//     int resetHeld = EControllerManager::GetCmdResultAllCtrl(
//         ctrlMgr,
//         27,         // command ID for reset
//         &resetData, // comparison data (on stack)
//         &resetData, // threshold data
//         0, 0        // no player-specific filtering
//     );
//
//     if (resetHeld == 0) {
//         // Not holding reset - reset the timer
//         g_resetTimer = 0.0f;  // r13-32760
//         return;
//     }
//
//     // Accumulate reset hold timer
//     g_resetTimer += g_deltaTime;  // r13-26800
//
//     // Check if held long enough (threshold loaded from rodata, ~2.0 seconds)
//     if (g_resetTimer > 2.0f) {
//         // Trigger soft reset
//         void* resetTarget = g_pResetTarget;  // r13-26512
//         // Call vtable methods to perform the reset
//         resetTarget->DisableRendering(0);  // vtable offset 0x50/0x54
//         resetTarget->TriggerReset();        // vtable offset 0x58/0x5C
//     }
// }


// ============================================================================
// ESimsApp::Update (MAIN GAME LOOP)
// Address: 0x80005BA4 | Size: 264 bytes
//
// The per-frame update function. Called every frame from EApp::SystemUpdate().
// Orchestrates all game subsystem updates in the correct order.
//
// This is the heart of the game loop.
// ============================================================================
// void ESimsApp::Update() {
//     // --- Player 1 controller auto-mapping ---
//     // Check if player 1 needs controller remapping
//     if (this->m_player1Flag != 0) {  // offset 0x48C
//         EControllerManager* ctrlMgr = g_pEControllerManager;
//         // Check if player 0 is already mapped
//         int isMapped = EControllerManager::GetPlayerMapped(ctrlMgr, 0);
//         if (isMapped == 0) {
//             // Try to auto-map player 0
//             int result = EGlobal::TryAutoMapPlayer(g_pEGlobal, 0);
//             if (result != -1) {
//                 // Success - set the AptViewer's player index to -1 (reset)
//                 AptViewer* viewer = g_pEGlobal->m_aptViewer;  // offset 0xB4
//                 viewer->m_field_3AC = -1;
//             }
//         }
//     }
//
//     // --- Player 2 controller auto-mapping ---
//     if (this->m_player2Flag != 0) {  // offset 0x490
//         EControllerManager* ctrlMgr = g_pEControllerManager;
//         int isMapped = EControllerManager::GetPlayerMapped(ctrlMgr, 1);
//         if (isMapped == 0) {
//             int result = EGlobal::TryAutoMapPlayer(g_pEGlobal, 1);
//             if (result != -1) {
//                 AptViewer* viewer = g_pEGlobal->m_aptViewer;
//                 viewer->m_field_3AC = -1;
//                 viewer->m_field_3A8 = 1;  // Mark player 2 as needing attention
//             }
//         }
//     }
//
//     // --- Per-frame subsystem updates (in order) ---
//
//     // 1. Profile hook (performance measurement)
//     ProfileHook();
//
//     // 2. Process cheat codes
//     this->UpdateCheats();
//
//     // 3. Update APT UI system (ActionScript interpreter)
//     this->UpdateApt();
//
//     // 4. Update game simulation (state machines, AI, physics)
//     this->UpdateGame();
//
//     // 5. Update audio (sound player, UI audio)
//     this->UpdateAudio();
//
//     // 6. Update shaders (time = 0.0 means use global delta)
//     this->UpdateShaders(0.0f);
//
//     // 7. Render the frame
//     this->UpdateDraw();
//
//     // 8. Check for reset button combo
//     this->UpdateReset();
// }


// ============================================================================
// ESimsApp::SetupForMovie
// Address: 0x80005CAC | Size: 40 bytes (raw byte matched)
// Prepares the engine for FMV playback.
// ============================================================================
// void ESimsApp::SetupForMovie() {
//     // Implementation is a raw byte match - calls base class and sets up movie state
// }


// ============================================================================
// ESimsApp::CleanupAfterMovie
// Address: 0x80005CD4 | Size: 40 bytes (raw byte matched)
// Restores engine state after FMV playback completes.
// ============================================================================
// void ESimsApp::CleanupAfterMovie() {
//     // Implementation is a raw byte match
// }


// ============================================================================
// ESimsApp::GetMovieHeap
// Address: 0x80005CFC | Size: 48 bytes (raw byte matched)
// Returns the heap used for movie playback memory allocations.
// ============================================================================
// EAHeap* ESimsApp::GetMovieHeap() {
//     // Implementation is a raw byte match
// }


// ============================================================================
// ESimsApp::TakeBigScreenshot
// Address: 0x80005D2C | Size: 20 bytes
// Initiates a tiled high-resolution screenshot capture.
// Sets the screenshot flag and stores the grid dimensions.
// ============================================================================
// void ESimsApp::TakeBigScreenshot(int width, int height) {
//     this->m_screenshotFlag = 1;    // offset 0x49C
//     this->m_screenshotW = width;   // offset 0x4A0
//     this->m_screenshotH = height;  // offset 0x4A4
// }


// ============================================================================
// ESimsApp::GetAppName
// Address: 0x80006380 | Size: 12 bytes
// Returns the application name string.
// ============================================================================
// const char* ESimsApp::GetAppName() {
//     return "The Sims 2 Console";
// }


// ============================================================================
// ESimsApp::GetEventTableSize
// Address: 0x8000638C | Size: 8 bytes
// Returns the event table size. Always 0 on GameCube.
// ============================================================================
// int ESimsApp::GetEventTableSize() {
//     return 0;
// }


// ============================================================================
// ESimsApp::GetNghName
// Address: 0x80006394 | Size: 12 bytes
// Returns a pointer to the static neighborhood name buffer.
// ============================================================================
// const char* ESimsApp::GetNghName() {
//     return m_nameOfNgh;  // static buffer at 0x804FB1D0
// }


// ============================================================================
// ESimsApp::initContinue
// Address: 0x80004C80 | Size: 1936 bytes
//
// Deferred initialization called from Init(). Sets up:
// 1. Heap compaction (14 heaps)
// 2. LoadSimulatorGlobs (InitPerformanceCounter)
// 3. StateMachineManager::Startup
// 4. Creates two StateMachine instances with IDs "SIMS" and "MUST"
//    - These are the main Sims gameplay state machine and the
//      Memory Unit (save/load) state machine
// 5. Adds them to the StateMachineManager
// 6. Creates a LoadingScreenStateMachine ("LdSc")
// 7. Adds it to the StateMachineManager
// 8. Queries EGlobal for UI strings ("ngc_ipl_banner_1", "ngc_ipl_banner_2")
// 9. Sets ENgcMemoryCard comments with the banner strings
//
// The state machine IDs are 4-char codes stored as u32:
//   "SIMS" = 0x53494D53
//   "MUST" = 0x4D555354
//   "LdSc" = 0x4C645363
// ============================================================================
// void ESimsApp::initContinue() {
//     // Compact all heaps (same 14-heap pattern)
//     RootHeap(); EAHeap::Compact();
//     MainHeap(); EAHeap::Compact();
//     ResourceHeap(); EAHeap::Compact();
//     AudioHeap(); EAHeap::Compact();
//     VMHeap(); EAHeap::Compact();
//     ShaderHeap(); EAHeap::Compact();
//     TextureHeap(); EAHeap::Compact();
//     AnimationHeap(); EAHeap::Compact();
//     ModelHeap(); EAHeap::Compact();
//     FlashesHeap(); EAHeap::Compact();
//     AptHeap(); EAHeap::Compact();
//     DebugHeap(); EAHeap::Compact();
//     CUIHeap(); EAHeap::Compact();
//     EAHeap::SetNextCheckPoint();
//
//     // Initialize simulator timing
//     this->LoadSimulatorGlobs();
//
//     // Start up state machine system
//     StateMachineManager::Startup();  // 0x800966a4
//
//     // Save the current SM manager pointer
//     void* smMgr = g_pStateMachineManager;  // r13-21500
//
//     // --- Create "SIMS" state machine ---
//     // The main gameplay state machine
//     void* simsSM = operator_new(156);  // sizeof = 0x9C
//     // Initialize StateMachine with ID "SIMS" (0x53494D53)
//     // ... (complex initialization of StateMachine struct fields:
//     //      vtable, state pointers, deque for state stack, etc.)
//     //
//     // Key fields initialized:
//     //   +0x00: data pointer = 0
//     //   +0x04: end pointer = -1 (uninitialized)
//     //   +0x08: count = 0
//     //   +0x0C: capacity = -1
//     //   +0x10: ??? = 0
//     //   +0x14: active = 1
//     //   +0x18: vtable pointer (set to SIMS vtable)
//     //   +0x1C: ID = 0x53494D53 ("SIMS")
//     //   +0x20: owner = smMgr
//     //   +0x28: time = 0.0f
//
//     // Set flags on the state machine
//     StateMachineState::SetFlag(simsSM, 1);  // Flag 1
//     StateMachineState::SetFlag(simsSM, 2);  // Flag 2
//
//     // Add to state machine manager
//     if (simsSM != NULL && smMgr != NULL) {
//         StateMachineManager::FindMachine(smMgr, simsSM);
//         // If not found, add to the deque
//         // ... (deque push_back logic)
//         // Set owner reference
//         simsSM->m_owner = smMgr;  // offset 0x20
//         // Call vtable init method
//     }
//
//     // --- Create "MUST" state machine ---
//     // Memory Unit state machine (save/load system)
//     void* mustSM = operator_new(156);  // sizeof = 0x9C
//     // Initialize with ID "MUST" (0x4D555354)
//     // Same initialization pattern as SIMS...
//     StateMachineState::SetFlag(mustSM, 1);
//     StateMachineState::SetFlag(mustSM, 2);
//     // Add to manager...
//
//     // --- Create LoadingScreenStateMachine ---
//     void* lssmMem = operator_new(184);  // sizeof = 0xB8
//     LoadingScreenStateMachine* lssm =
//         LoadingScreenStateMachine::LoadingScreenStateMachine(lssmMem, 0, 0x4C645363);
//     // "LdSc" = 0x4C645363
//
//     // Add loading screen SM to manager...
//     if (lssm != NULL && smMgr != NULL) {
//         StateMachineManager::FindMachine(smMgr, lssm);
//         // deque push_back...
//         lssm->m_owner = smMgr;
//     }
//
//     // --- Set memory card banner strings ---
//     // Get localized banner strings from EGlobal
//     char banner1Buf[8];
//     char banner2Buf[8];
//     unsigned wchar_t* banner1 = NULL;
//     unsigned wchar_t* banner2 = NULL;
//
//     EGlobal::GetNewUIString(banner1Buf, g_pEGlobal, "ngc_ipl_banner_1");
//     if (banner1Buf[4] != NULL) {  // result check
//         banner1 = *(unsigned wchar_t**)&banner1Buf[4];
//     }
//
//     EGlobal::GetNewUIString(banner2Buf, g_pEGlobal, "ngc_ipl_banner_2");
//     if (banner2Buf[4] != NULL) {
//         banner2 = *(unsigned wchar_t**)&banner2Buf[4];
//     }
//
//     // Set the IPL banner comments on the memory card
//     ENgcMemoryCard::SetComments(banner1, banner2);
// }


// ============================================================================
// VTABLE LAYOUT (from .data at 0x8045AAF0, 224 bytes = 56 entries)
//
// The ESimsApp vtable overrides EApp virtual methods:
//
// [0x000] = ???
// ...
// [0x030] = ESimsApp::GetBuildVersion
// [0x034] = ESimsApp::GetAppName
// [0x038] = ESimsApp::GetEventTableSize
// ...
// [0x064] = ESimsApp::SetGameState
// [0x068] = ESimsApp::GetDefaultLanguage
// ...
// [0x088] = ESimsApp::ShowInitialDisplay
// [0x090] = ESimsApp::Init
// [0x094] = ESimsApp::Update
// [0x098] = ESimsApp::UpdateAfterHotSync
// [0x09C] = ESimsApp::Shutdown
// [0x0A0] = ESimsApp::SetupForMovie
// [0x0A4] = ESimsApp::CleanupAfterMovie
// [0x0A8] = ESimsApp::GetMovieHeap
//
// (Exact offsets may vary; the vtable has 56 entries for 224 bytes)
// ============================================================================
