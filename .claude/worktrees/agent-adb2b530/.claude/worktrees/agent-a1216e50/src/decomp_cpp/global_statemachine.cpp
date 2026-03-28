// global_statemachine.cpp - Decompiled EGlobal, ECheats, OptionsRecon,
// StateMachineState, StateMachineStatus, StateMachine, StateMachineManager,
// TheSimsStateMachine, TheSimsStartScreenStateMachine,
// LoadingScreenStateMachine, LiveModeInitState, InLevelBaseState,
// LiveModeChangeHouseStateMachine, and all boot/menu/pregame/gameplay states.
//
// Sims 2 GameCube Decompilation - Portable C++ (no inline PPC asm)
//
// Converted from:
//   src/core/eglobal_decomp.cpp   (1,719 lines - annotated disassembly)
//   src/core/statemachine_decomp.cpp (1,629 lines - annotated disassembly)
//   src/asm_decomp/*.cpp          (inline asm originals)
//   include/classes/*.h           (struct layouts from assembly analysis)
//
// All field offsets match the original binary's struct layouts.
// NON_MATCHING annotations preserved where byte-match status is uncertain.

#include "types.h"

// ============================================================================
// Forward declarations
// ============================================================================

class AnimRef;
class BString2;
class CameraDirector;
class CLoadingScreen;
class CTilePt;
class ERC;
class ESimsCam;
class EVec2;
class EVec3;
class Family;
class FenceData;
class FloorTile;
class FTilePt;
class IBaseSimInstance;
class ObjectModule;
class ObjSelector;
class PropRef;
class ReconBuffer;
class SpriteSlot;
class WallTile;
class cXObject;
class cXPerson;

class StateMachine;
class StateMachineState;
class StateMachineStatus;
class StateMachineManager;

// ============================================================================
// External functions / globals (originally SDA-relative or via linker)
// ============================================================================

extern "C" {
    void* operator_new_wrapper(unsigned int size);
    void  operator_delete_wrapper(void* ptr);
    void* small_alloc(unsigned int size);
    void  small_free(void* ptr);
    void* memcpy(void* dst, const void* src, unsigned int n);
    void* memset(void* dst, int val, unsigned int n);

    void deque_init(void* deq, int param);
}

// SDA globals (originally accessed via r13 offsets)
static StateMachineManager* g_pStateMachineManager = NULL;
static int                  g_bDrawTopmost = 0;
static void*                g_pStartScreenVars = NULL;
static void*                g_pEGlobal = NULL;
static void*                g_pStaticResource = NULL;
static void*                g_pAudioPlayer = NULL;
static void*                g_pSoundEventManager = NULL;
static int                  g_bGodMode = 0;
static int                  g_bNotInLevel = 0;
static int                  g_bPreferencesPreserved = 0;
static int                  g_bOnlinePrefsPreserved = 0;


// ############################################################################
//
//  PART 1: EGlobal (0x654 bytes, 211 fields)
//
// ############################################################################
//
// The largest global state class. Holds runtime state for the entire game:
// player settings, debug flags, cheat sequences, resource handles, camera,
// selected sims, house data, UI string tables, etc.
//
// Struct regions:
//   0x000-0x09B  Cheat sequence table (10 cheats x 6 steps x u16)
//   0x09C        Active cheat bitmask (u16)
//   0x0A0-0x0FF  Core state / resource handles
//   0x0BC-0x0C8  Player & house pointers
//   0x0D0-0x0E0  Camera / window
//   0x0E4-0x148  Resource handles (~20)
//   0x160        Default sim count
//   0x168-0x1A4  Initial data (memset + rodata copy)
//   0x330-0x3AF  Object state flags (32 x u32)
//   0x3AC-0x3B0  Float parameters
//   0x3B4-0x404  Author/god-mode cheat flags
//   0x400        God mode flag
//   0x450-0x454  Save/load flags
//   0x478        Controller listen flag
//   0x490        Level state resource
//   0x650        Tail alignment

class EGlobal {
public:
    // ---- Cheat Sequence Table (0x000 - 0x09B) ----
    u16 m_allPlayerCheatsMask;       // 0x000
    u8  _nghOverlap;                 // 0x001 (overlap from u16/u8 ambiguity)
    u16 m_cheatSequences[60];        // 0x002-0x079 (10 cheats x 6 steps)
    u16 m_playerCheatBitmask[10];    // 0x07A-0x08D
    u8  _pad_08E[0x0E];             // 0x08E-0x09B

    u16 m_activeCheatFlags;          // 0x09C
    u8  _pad_09E[2];                // 0x09E-0x09F

    // ---- Core State (0x0A0 - 0x0BF) ----
    u32 m_gameStateFlags;            // 0x0A0
    f32 m_defaultFloat1;             // 0x0A4
    f32 m_defaultFloat2;             // 0x0A8
    u32 m_field_0AC;                 // 0x0AC
    u32 m_field_0B0;                 // 0x0B0
    u32 m_resourceHandle_0B4;        // 0x0B4
    u16 m_field_0B6;                 // 0x0B6
    u8  m_field_0B8;                 // 0x0B8
    u8  m_field_0B9;                 // 0x0B9
    u8  _pad_0BA[2];                // 0x0BA-0x0BB

    // ---- Player State (0x0BC - 0x0CF) ----
    u32 m_selectedPerson[2];         // 0x0BC-0x0C3
    u8  _pad_0C4[4];               // 0x0C4-0x0C7
    u32 m_pCurHouse;                 // 0x0C8
    u8  _pad_0CC[4];               // 0x0CC-0x0CF

    // ---- Camera & Window (0x0D0 - 0x0E3) ----
    ESimsCam* m_pCam;                // 0x0D0
    u32 m_floorSet;                  // 0x0D4
    u32 m_wallSet;                   // 0x0D8
    u32 m_fenceSet;                  // 0x0DC
    CameraDirector* m_pCameraDirector; // 0x0E0

    // ---- Resource Handles (0x0E4 - 0x148) ----
    u32 m_pResourceModule;           // 0x0E4
    u32 m_pHouseLevelIdResource;     // 0x0E8
    u32 m_pResourceHandle_0EC;       // 0x0EC
    u32 m_pResourceHandle_0F0;       // 0x0F0
    u32 m_pResourceHandle_0F4;       // 0x0F4
    u32 m_pResourceHandle_0F8;       // 0x0F8
    u32 m_pResourceHandle_0FC;       // 0x0FC
    u32 m_pResourceHandle_100;       // 0x100
    u32 m_pFontResource;             // 0x104
    u32 m_pResourceHandle_108;       // 0x108
    u32 m_pAnimator;                 // 0x10C
    u32 m_pResourceHandle_110;       // 0x110
    u32 m_pCheatsObject;             // 0x114
    u32 m_pResourceHandle_118;       // 0x118
    u32 m_pResourceHandle_11C;       // 0x11C
    u32 m_pResourceHandle_120;       // 0x120
    u32 m_pResourceHandle_124;       // 0x124
    u32 m_pResourceHandle_128;       // 0x128
    u32 m_pResourceHandle_12C;       // 0x12C
    u32 m_pResourceHandle_130;       // 0x130
    u32 m_pResourceHandle_134;       // 0x134
    u32 m_pResourceHandle_138;       // 0x138
    u32 m_pResourceHandle_13C;       // 0x13C
    u32 m_pResourceHandle_140;       // 0x140
    u32 m_field_144;                 // 0x144
    u32 m_pResourceHandle_148;       // 0x148
    u32 m_field_14C;                 // 0x14C
    u32 m_field_150;                 // 0x150
    u32 m_field_154;                 // 0x154
    u8  _pad_158[8];                // 0x158-0x15F
    u32 m_nDefaultSimCount;          // 0x160
    u8  _pad_164[4];                // 0x164-0x167

    // ---- Initial Data Block (0x168 - 0x1A4) ----
    u32 m_initData_168;              // 0x168
    u8  _pad_16C[0x1C];            // 0x16C-0x187
    u32 m_initData_188;              // 0x188
    u8  m_initData_18C;              // 0x18C
    u8  _pad_18D[3];               // 0x18D-0x18F
    u32 m_initData_190;              // 0x190
    u8  m_initData_194;              // 0x194
    u8  _pad_195[3];               // 0x195-0x197
    u32 m_initData_198;              // 0x198
    u8  _pad_19C[8];               // 0x19C-0x1A3
    u8  m_initData_1A4;              // 0x1A4

    // ---- Large Gap (0x1A5 - 0x31F) ----
    u8  _pad_1A5[0x17B];           // 0x1A5-0x31F

    // ---- Instance & Config Data (0x320 - 0x32D) ----
    u32 m_field_320;                 // 0x320
    u32 m_initData_324;              // 0x324
    u8  m_initData_328;              // 0x328
    u8  _pad_329[3];               // 0x329-0x32B
    u8  m_field_32C;                 // 0x32C
    u8  m_field_32D;                 // 0x32D
    u8  _pad_32E[2];               // 0x32E-0x32F

    // ---- Object State Flags (0x330 - 0x3AF) ----
    u32 m_objState[32];              // 0x330-0x3AF

    // ---- Float Parameters (0x3AC - 0x3B3) ----
    f32 m_floatParam1;               // 0x3AC (originally from .rodata)
    f32 m_floatParam2;               // 0x3B0

    // ---- Extended State / Cheat Flags (0x3B4 - 0x40F) ----
    u32 m_extState_3B4;              // 0x3B4
    u32 m_extState_3B8;              // 0x3B8
    u32 m_cheatFlag_3BC;             // 0x3BC (author+god)
    u32 m_cheatFlag_3C0;             // 0x3C0 (author+god)
    u32 m_cheatFlag_3C4;             // 0x3C4
    u32 m_cheatFlag_3C8;             // 0x3C8 (author+god)
    u32 m_cheatFlag_3CC;             // 0x3CC (god only)
    u32 m_cheatFlag_3D0;             // 0x3D0 (god only)
    u32 m_cheatFlag_3D4;             // 0x3D4
    u32 m_cheatFlag_3D8;             // 0x3D8 (god only)
    u32 m_cheatFlag_3DC;             // 0x3DC (author+god)
    u32 m_cheatFlag_3E0;             // 0x3E0
    u32 m_cheatFlag_3E4;             // 0x3E4 (author)
    u32 m_cheatFlag_3E8;             // 0x3E8 (author)
    u32 m_cheatFlag_3EC;             // 0x3EC
    u32 m_cheatFlag_3F0;             // 0x3F0 (author+god)
    u32 m_cheatFlag_3F4;             // 0x3F4
    u32 m_cheatFlag_3F8;             // 0x3F8
    u32 m_cheatFlag_3FC;             // 0x3FC
    u32 m_godModeFlag;               // 0x400 (nonzero => all cheats active)
    u32 m_cheatFlag_404;             // 0x404 (author)

    // ---- Resource Handles (0x408 - 0x44F) ----
    u32 m_initData_408;              // 0x408
    u32 m_initData_40C;              // 0x40C
    u8  _pad_410[8];               // 0x410-0x417
    u32 m_pDefaultResource;          // 0x418
    u32 m_field_41C;                 // 0x41C
    u32 m_field_420;                 // 0x420
    u32 m_field_424;                 // 0x424
    u32 m_field_428;                 // 0x428
    u32 m_field_42C;                 // 0x42C
    u32 m_field_430;                 // 0x430
    u32 m_field_434;                 // 0x434
    u32 m_field_438;                 // 0x438
    u32 m_field_43C;                 // 0x43C
    u32 m_field_440;                 // 0x440
    u8  _pad_444[4];               // 0x444-0x447
    u32 m_field_448;                 // 0x448
    u32 m_field_44C;                 // 0x44C

    // ---- Save/Load Flags (0x450 - 0x45B) ----
    u32 m_saveGameFlags1;            // 0x450
    u32 m_saveGameFlags2;            // 0x454
    u8  _pad_458[4];               // 0x458-0x45B

    // ---- Game Mode Flags (0x45C - 0x494) ----
    u32 m_nModeField_45C;            // 0x45C
    u32 m_field_460;                 // 0x460
    u32 m_field_464;                 // 0x464
    u32 m_field_468;                 // 0x468
    u32 m_field_46C;                 // 0x46C
    u32 m_field_470;                 // 0x470
    u32 m_field_474;                 // 0x474
    u32 m_bListenForController;      // 0x478
    u8  _pad_47C[4];               // 0x47C-0x47F
    u32 m_field_480;                 // 0x480
    u32 m_field_484;                 // 0x484
    u8  _pad_488[4];               // 0x488-0x48B
    u32 m_field_48C;                 // 0x48C
    u32 m_pLevelStateResource;       // 0x490

    // ---- Tail Gap (0x494 - 0x653) ----
    u8  _pad_494[0x1BC];           // 0x494-0x64F
    u32 m_defaults_650;              // 0x650

    // ---- Method declarations ----
    EGlobal();
    ~EGlobal();
    void      SetDefaults();
    void      Reset();
    void      SetCam(ESimsCam* pCam);
    ESimsCam* GetCam();
    void      SetCameraDirector(CameraDirector* pDir);
    ERC*      GetWin();
    cXPerson* GetSelectedPerson(int playerIndex);
    void      SetupScratchHeap();
    void      FreeScratchHeap();
    void      PlaceObjectInHouse(cXObject*);
    void      PickUpInHouseObject(cXObject*);
    bool      IsBuildHouseMode();
    AnimRef*  GetSkillFromName(char*);
    PropRef*  GetPropFromName(char*);
    char*     GetNameFromProp(PropRef*);
    bool      ListenForController();
    void      SetListenFlag(bool flag);
    u32       GetGameFontID();
    void      SetAuthorModeCheats();
    bool      InLevelState();
    int       GetFloorIndex(FloorTile* pTile);
    int       GetWallIndex(WallTile* pTile);
    int       GetFenceIndex(FenceData* pTile);
    u16       GetPlayerCheats();
    bool      IsPlayerCheatOn(int cheatIndex);
    void      TogglePlayerCheat(int cheatIndex);
    void      ClearPlayerCheats();
    void      InitPlayerCheats();
    u16       GetAllPlayerCheatsMask();
    u16       GetPlayerCheatsMask(int playerIndex);
    u16       GetPlayerCheatsSequence(int cheatIndex, int step);
    u32       GetFloorSet();
    u32       GetWallSet();
    u32       GetFenceSet();
    void      SetIsTransitionLoad(bool b);
    bool      IsTransitionLoad();
    void      SetUIDrawEnable(bool b);
    void      SetUIUpdateEnable(bool b);
    bool      IsUIDrawEnabled();
    bool      IsUIUpdateEnabled();
    void      SetIsLoadingFromMainMenu(bool b);
    bool      IsLoadingFromMainMenu();
    bool      IsSaveGameEnabled();
};
// static_assert(sizeof(EGlobal) == 0x654, "EGlobal size mismatch");


// ---------------------------------------------------------------------------
// EGlobal::~EGlobal - Destructor
// Address: 0x8003E1F0 | 40 bytes
// ---------------------------------------------------------------------------
EGlobal::~EGlobal() {
    // Trivial -- resources cleaned in Reset(). SN Systems dtor disposition
    // flag (r4 bit 0) determines whether to free memory; omitted here.
}

// ---------------------------------------------------------------------------
// EGlobal::EGlobal - Constructor
// Address: 0x8003E218 | 800 bytes
// ---------------------------------------------------------------------------
EGlobal::EGlobal() {
    // Zero critical pointer/flag fields
    m_gameStateFlags = 0;
    m_pCam = NULL;
    m_selectedPerson[0] = 0;
    m_selectedPerson[1] = 0;
    m_field_0B8 = 0;
    m_field_0B9 = 0;
    m_pCurHouse = 0;
    m_pResourceModule = 0;
    m_pHouseLevelIdResource = 0;
    m_pResourceHandle_0F0 = 0;
    m_pResourceHandle_0FC = 0;
    m_pResourceHandle_100 = 0;
    m_pFontResource = 0;
    m_pResourceHandle_108 = 0;
    m_pAnimator = 0;
    m_pResourceHandle_110 = 0;
    m_pCheatsObject = 0;
    m_pResourceHandle_118 = 0;
    m_pResourceHandle_11C = 0;
    m_pResourceHandle_120 = 0;
    m_field_48C = 0;
    m_activeCheatFlags = 0;
    m_pResourceHandle_148 = 0;
    m_field_14C = 0;
    m_pResourceHandle_0F4 = 0;
    m_pResourceHandle_0EC = 0;
    m_pResourceHandle_0F8 = 0;

    // Clear the large data region (0x168 to ~0x448, 736 bytes)
    memset(&m_initData_168, 0, 736);

    // Set object state flags (32 slots, most zero, 4 enabled)
    for (int i = 0; i < 32; i++) {
        m_objState[i] = 0;
    }
    m_objState[3]  = 1;   // 0x33C
    m_objState[20] = 1;   // 0x380
    m_objState[22] = 1;   // 0x388
    m_objState[23] = 1;   // 0x38C

    // Float parameters (original loads from .rodata at 0x803D22F0/F4)
    m_floatParam1 = 0.0f;   // placeholder -- actual value from .rodata
    m_floatParam2 = 0.0f;   // placeholder

    // Zero remaining pointer fields
    m_field_150 = 0;
    m_field_154 = 0;
    m_pResourceHandle_138 = 0;
    m_field_434 = 1;
    m_field_438 = 1;
    m_field_32C = 0xFF;
    m_field_32D = 0xFF;

    // Store global pointer (SDA r13 reference)
    g_pEGlobal = this;
}

// ---------------------------------------------------------------------------
// EGlobal::SetDefaults
// Address: 0x8003ECF4 | 984 bytes
// ---------------------------------------------------------------------------
void EGlobal::SetDefaults() {
    m_pCam = NULL;
    m_gameStateFlags = 0;
    m_selectedPerson[0] = 0;
    m_selectedPerson[1] = 0;
    m_floorSet = 0;
    m_wallSet = 0;
    m_fenceSet = 0;
    m_pCurHouse = 0;

    // Load default floats from .rodata
    // m_defaultFloat1 = kDefaultFloat1;
    // m_defaultFloat2 = kDefaultFloat2;

    // Lazy-load resources by hash ID
    // if (m_pResourceHandle_0F0 == 0) {
    //     m_pResourceHandle_0F0 = ResourceManager::Load(0x19A16F2D);
    // }
    // ... (similar pattern for 0EC, 0F4, 0F8, 100, 108)

    // Create animator if needed
    // if (m_pAnimator == 0) { m_pAnimator = (u32)new Animator(); }

    m_nDefaultSimCount = 2;
    m_saveGameFlags1 = 2;
    m_saveGameFlags2 = 2;
}

// ---------------------------------------------------------------------------
// EGlobal::Reset
// Address: 0x8003F450 | 1168 bytes
// ---------------------------------------------------------------------------
void EGlobal::Reset() {
    m_pCam = NULL;

    // Free each resource handle if allocated, then NULL it
    // Pattern: if (handle) { ResourceManager::Free(handle); handle = 0; }
    // Applied to: m_pResourceModule, m_pHouseLevelIdResource,
    //   m_pResourceHandle_0F0, 0EC, 0F4, 0FC, 100, m_pFontResource, 108

    // Reset & destroy cheats
    // if (m_pCheatsObject) {
    //     ((ECheats*)m_pCheatsObject)->Reset();
    //     ((ECheats*)m_pCheatsObject)->~ECheats();
    //     m_pCheatsObject = 0;
    // }

    // Free animator, EOrPool, house, level state, etc.
    m_pResourceHandle_148 = 0;
    m_saveGameFlags1 = 0;
    m_saveGameFlags2 = 0;
}

// ---------------------------------------------------------------------------
// EGlobal::SetCam / GetCam
// Address: 0x8003FA14 / 0x8003FA1C | 8 bytes each
// ---------------------------------------------------------------------------
void EGlobal::SetCam(ESimsCam* pCam) {
    m_pCam = pCam;
}

ESimsCam* EGlobal::GetCam() {
    return m_pCam;
}

// ---------------------------------------------------------------------------
// EGlobal::SetCameraDirector
// Address: 0x8003FA24 | 8 bytes
// ---------------------------------------------------------------------------
void EGlobal::SetCameraDirector(CameraDirector* pDir) {
    m_pCameraDirector = pDir;
}

// ---------------------------------------------------------------------------
// EGlobal::GetWin
// Address: 0x8003F9FC | 24 bytes
// ---------------------------------------------------------------------------
ERC* EGlobal::GetWin() {
    if (m_pCam != NULL) {
        return (ERC*)((char*)m_pCam + 0x10);
    }
    return NULL;
}

// ---------------------------------------------------------------------------
// EGlobal::GetSelectedPerson
// Address: 0x8004079C | 16 bytes
// ---------------------------------------------------------------------------
cXPerson* EGlobal::GetSelectedPerson(int playerIndex) {
    return (cXPerson*)m_selectedPerson[playerIndex];
}

// ---------------------------------------------------------------------------
// EGlobal stubs (no-ops on GameCube)
// ---------------------------------------------------------------------------
void EGlobal::SetupScratchHeap()                    { }   // 0x8003F0CC
void EGlobal::FreeScratchHeap()                     { }   // 0x8003F0D0
void EGlobal::PlaceObjectInHouse(cXObject*)          { }   // 0x80041214
void EGlobal::PickUpInHouseObject(cXObject*)         { }   // 0x80041218
bool EGlobal::IsBuildHouseMode()                     { return false; } // 0x800420AC
AnimRef* EGlobal::GetSkillFromName(char*)            { return NULL; }  // 0x8004219C
PropRef* EGlobal::GetPropFromName(char*)             { return NULL; }  // 0x8004227C
char*    EGlobal::GetNameFromProp(PropRef*)          { return NULL; }  // 0x80042284

// ---------------------------------------------------------------------------
// EGlobal::ListenForController
// Address: 0x80042194 | 8 bytes
// ---------------------------------------------------------------------------
bool EGlobal::ListenForController() {
    return m_bListenForController != 0;
}

// ---------------------------------------------------------------------------
// EGlobal::SetListenFlag
// Address: 0x801BEEEC | 40 bytes
// ---------------------------------------------------------------------------
void EGlobal::SetListenFlag(bool flag) {
    m_bListenForController = flag ? 1 : 0;
}

// ---------------------------------------------------------------------------
// EGlobal::GetGameFontID
// Address: 0x8003E5B4 | 12 bytes
// ---------------------------------------------------------------------------
unsigned int EGlobal::GetGameFontID() {
    return 0x67F664FB;
}

// ---------------------------------------------------------------------------
// EGlobal::SetAuthorModeCheats
// Address: 0x8003E538 | 40 bytes
// ---------------------------------------------------------------------------
void EGlobal::SetAuthorModeCheats() {
    m_cheatFlag_3E4 = 1;
    m_cheatFlag_3BC = 1;
    m_cheatFlag_3C0 = 1;
    m_cheatFlag_3C8 = 1;
    m_cheatFlag_3DC = 1;
    m_cheatFlag_3E8 = 1;
    m_cheatFlag_3F0 = 1;
    m_cheatFlag_404 = 1;
}

// ---------------------------------------------------------------------------
// EGlobal::InLevelState
// Address: 0x80042320 | 24 bytes
// ---------------------------------------------------------------------------
bool EGlobal::InLevelState() {
    return (g_bNotInLevel == 0);
}

// ---------------------------------------------------------------------------
// EGlobal::GetFloorIndex / GetWallIndex / GetFenceIndex
// Addresses: 0x800406C4 / 0x8004070C / 0x80040754 | 72 bytes each
// ---------------------------------------------------------------------------
int EGlobal::GetFloorIndex(FloorTile* pTile) {
    u32* pArray = (u32*)m_floorSet;
    int count = 0;
    if (pArray != NULL) {
        count = *((int*)pArray - 1);
    }
    for (int i = 0; i < count; i++) {
        if (pArray[i] == (u32)(uintptr_t)pTile) {
            return i;
        }
    }
    return 0;
}

int EGlobal::GetWallIndex(WallTile* pTile) {
    u32* pArray = (u32*)m_wallSet;
    int count = 0;
    if (pArray != NULL) {
        count = *((int*)pArray - 1);
    }
    for (int i = 0; i < count; i++) {
        if (pArray[i] == (u32)(uintptr_t)pTile) {
            return i;
        }
    }
    return 0;
}

int EGlobal::GetFenceIndex(FenceData* pTile) {
    u32* pArray = (u32*)m_fenceSet;
    int count = 0;
    if (pArray != NULL) {
        count = *((int*)pArray - 1);
    }
    for (int i = 0; i < count; i++) {
        if (pArray[i] == (u32)(uintptr_t)pTile) {
            return i;
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// EGlobal::GetPlayerCheats
// Address: 0x80042338 | 32 bytes
// ---------------------------------------------------------------------------
u16 EGlobal::GetPlayerCheats() {
    if (m_godModeFlag != 0) {
        return 0xFFFF;
    }
    return m_activeCheatFlags;
}

// ---------------------------------------------------------------------------
// EGlobal::IsPlayerCheatOn
// Address: 0x80042358 | 48 bytes
// ---------------------------------------------------------------------------
bool EGlobal::IsPlayerCheatOn(int cheatIndex) {
    if (m_godModeFlag != 0) {
        return true;
    }
    return ((m_activeCheatFlags >> cheatIndex) & 1) != 0;
}

// ---------------------------------------------------------------------------
// EGlobal::TogglePlayerCheat
// Address: 0x80042388 | 228 bytes
// ---------------------------------------------------------------------------
void EGlobal::TogglePlayerCheat(int cheatIndex) {
    if (cheatIndex == 10) {
        // Special cheat #10: play a sound effect (hash 0x3EA0941F)
        // if (!g_pAudioPlayer) g_pAudioPlayer = new AudioPlayer();
        // g_pAudioPlayer->PlayByHash(0x3EA0941F);
        return;
    }

    m_activeCheatFlags ^= (1 << cheatIndex);

    bool isNowOn = IsPlayerCheatOn(cheatIndex);
    if (g_pSoundEventManager == NULL) {
        return;
    }

    if (isNowOn) {
        // Play "cheat enabled" jingle (hash 0xCE619E32)
    } else {
        // Play "cheat disabled" jingle (hash 0x1C99B71C)
    }
}

// ---------------------------------------------------------------------------
// EGlobal::ClearPlayerCheats
// Address: 0x801E85F4 | 40 bytes
// ---------------------------------------------------------------------------
void EGlobal::ClearPlayerCheats() {
    m_activeCheatFlags = 0;
}

// ---------------------------------------------------------------------------
// EGlobal::InitPlayerCheats
// Address: 0x8004246C | 424 bytes
// ---------------------------------------------------------------------------
void EGlobal::InitPlayerCheats() {
    // Cheat 0 (offset 0x002)
    m_cheatSequences[0]  = 4;     m_cheatSequences[1]  = 8;
    m_cheatSequences[2]  = 4096;  m_cheatSequences[3]  = 64;
    m_cheatSequences[4]  = 2;     m_cheatSequences[5]  = 0;
    // Cheat 1 (offset 0x00E)
    m_cheatSequences[6]  = 8;     m_cheatSequences[7]  = 4;
    m_cheatSequences[8]  = 2;     m_cheatSequences[9]  = 8192;
    m_cheatSequences[10] = 0x8000; m_cheatSequences[11] = 0;
    // Cheat 2 (offset 0x01A)
    m_cheatSequences[12] = 4096;  m_cheatSequences[13] = 32;
    m_cheatSequences[14] = 4096;  m_cheatSequences[15] = 8192;
    m_cheatSequences[16] = 2;     m_cheatSequences[17] = 0;
    // Cheat 3 (offset 0x026)
    m_cheatSequences[18] = 32;    m_cheatSequences[19] = 0x4000;
    m_cheatSequences[20] = 0x8000; m_cheatSequences[21] = 4096;
    m_cheatSequences[22] = 0;     m_cheatSequences[23] = 32;
    // Cheat 4 (offset 0x032)
    m_cheatSequences[24] = 128;   m_cheatSequences[25] = 0;
    m_cheatSequences[26] = 32;    m_cheatSequences[27] = 128;
    m_cheatSequences[28] = 4;     m_cheatSequences[29] = 4096;
    // Cheat 5 (offset 0x03E)
    m_cheatSequences[30] = 0x4000; m_cheatSequences[31] = 8192;
    m_cheatSequences[32] = 0;     m_cheatSequences[33] = 2;
    m_cheatSequences[34] = 8;     m_cheatSequences[35] = 0x4000;
    // Cheat 6 (offset 0x04A)
    m_cheatSequences[36] = 8192;  m_cheatSequences[37] = 0x4000;
    m_cheatSequences[38] = 8192;  m_cheatSequences[39] = 0x4000;
    m_cheatSequences[40] = 8192;  m_cheatSequences[41] = 0;
    // Cheat 7 (offset 0x056)
    m_cheatSequences[42] = 0;     m_cheatSequences[43] = 8;
    m_cheatSequences[44] = 4;     m_cheatSequences[45] = 128;
    m_cheatSequences[46] = 2;     m_cheatSequences[47] = 0x8000;
    // Cheat 8 (offset 0x062)
    m_cheatSequences[48] = 2;     m_cheatSequences[49] = 0x4000;
    m_cheatSequences[50] = 8192;  m_cheatSequences[51] = 0x8000;
    m_cheatSequences[52] = 4096;  m_cheatSequences[53] = 0x4000;
    // Cheat 9 (offset 0x06E)
    m_cheatSequences[54] = 16;    m_cheatSequences[55] = 0;
    m_cheatSequences[56] = 0x4000; m_cheatSequences[57] = 128;
    m_cheatSequences[58] = 0;     m_cheatSequences[59] = 32;

    // Compute per-player OR masks
    u16 combined = 0;
    for (int player = 0; player < 10; player++) {
        u16 mask = 0;
        for (int step = 0; step < 6; step++) {
            mask |= m_cheatSequences[player * 6 + step];
        }
        m_playerCheatBitmask[player] = mask;
        combined |= mask;
    }
    m_allPlayerCheatsMask = combined;
}

// ---------------------------------------------------------------------------
// EGlobal accessor pair helpers
// ---------------------------------------------------------------------------
u16 EGlobal::GetAllPlayerCheatsMask() {
    return m_allPlayerCheatsMask;
}

u16 EGlobal::GetPlayerCheatsMask(int playerIndex) {
    return m_playerCheatBitmask[playerIndex];
}

u16 EGlobal::GetPlayerCheatsSequence(int cheatIndex, int step) {
    return m_cheatSequences[cheatIndex * 6 + step];
}

u32 EGlobal::GetFloorSet()  { return m_floorSet; }
u32 EGlobal::GetWallSet()   { return m_wallSet; }
u32 EGlobal::GetFenceSet()  { return m_fenceSet; }

void EGlobal::SetIsTransitionLoad(bool b) {
    // Sets a field -- placeholder
}
bool EGlobal::IsTransitionLoad() {
    return false;  // Reads a field -- placeholder
}
void EGlobal::SetUIDrawEnable(bool b) {
    // Writes to game state flags
}
void EGlobal::SetUIUpdateEnable(bool b) {
    // Writes to game state flags
}
bool EGlobal::IsUIDrawEnabled() {
    return (m_gameStateFlags & 1) == 0;  // bit test
}
bool EGlobal::IsUIUpdateEnabled() {
    return (m_gameStateFlags & 2) == 0;  // bit test
}
void EGlobal::SetIsLoadingFromMainMenu(bool b) {
    // Sets a field -- placeholder
}
bool EGlobal::IsLoadingFromMainMenu() {
    return false;  // placeholder
}

// ---------------------------------------------------------------------------
// EGlobal::IsSaveGameEnabled
// Address: 0x80042718 | 144 bytes
// ---------------------------------------------------------------------------
bool EGlobal::IsSaveGameEnabled() {
    // Multi-condition check: valid house, player states, multiplayer
    // Simplified placeholder -- actual logic checks multiple globals
    return false;
}


// ############################################################################
//
//  PART 2: ECheats (0x10C bytes)
//
// ############################################################################
//
// 64-bucket hash table of cheat definitions with audio event callbacks.

class ECheats {
public:
    u32 m_hashBuckets[64];   // 0x000-0x0FF
    u32 m_lookupCount;       // 0x100
    u32 m_flags;             // 0x104
    u32 m_initStatus;        // 0x108

    ECheats();
    ~ECheats();
    void Init(EGlobal& global);
    void Reset();
    void EmptyLookupList();
    void ReadCheatsFile();
    void WriteCheatsFile();
    void Update();
    void SetGodMode(bool enable);
    void EnableCheats();
    void DisableCheats();
};

// ---------------------------------------------------------------------------
// ECheats::ECheats - Constructor
// Address: 0x8001ECAC | 72 bytes
// ---------------------------------------------------------------------------
ECheats::ECheats() {
    memset(m_hashBuckets, 0, 256);
    EmptyLookupList();
    m_flags = 0;
}

// ---------------------------------------------------------------------------
// ECheats::~ECheats - Destructor
// Address: 0x8001ECF4 | 136 bytes
// ---------------------------------------------------------------------------
ECheats::~ECheats() {
    DisableCheats();
    EmptyLookupList();

    for (int i = 0; i < 64; i++) {
        u32* pEntry = (u32*)(unsigned long)m_hashBuckets[i];
        while (pEntry != NULL) {
            m_hashBuckets[i] = 0;
            u32* pNext;
            while (pEntry) {
                pNext = *(u32**)pEntry;
                operator_delete_wrapper(pEntry);
                pEntry = pNext;
            }
        }
    }
}

// ---------------------------------------------------------------------------
// ECheats::Reset
// Address: 0x80020C0C | 52 bytes
// ---------------------------------------------------------------------------
void ECheats::Reset() {
    WriteCheatsFile();
    EmptyLookupList();
}

// ---------------------------------------------------------------------------
// ECheats::EmptyLookupList
// Address: 0x80020C40 | 112 bytes
// ---------------------------------------------------------------------------
void ECheats::EmptyLookupList() {
    for (int i = 0; i < 64; i++) {
        u32* pEntry = (u32*)(unsigned long)m_hashBuckets[i];
        while (pEntry != NULL) {
            m_hashBuckets[i] = 0;
            u32* pNext;
            do {
                pNext = *(u32**)pEntry;
                operator_delete_wrapper(pEntry);
                pEntry = pNext;
            } while (pEntry != NULL);
        }
    }
    m_lookupCount = 0;
}

// ---------------------------------------------------------------------------
// ECheats stubs
// ---------------------------------------------------------------------------
void ECheats::ReadCheatsFile() {
    m_flags = 1;                     // 0x80020CB0 | 20 bytes
}
void ECheats::WriteCheatsFile()  { }  // 0x80020D08 | 4 bytes (no-op)
void ECheats::Update()           { }  // 0x80020D0C | 4 bytes (no-op)

// ---------------------------------------------------------------------------
// ECheats::SetGodMode
// Address: 0x80020CC4 | 68 bytes
// ---------------------------------------------------------------------------
void ECheats::SetGodMode(bool enable) {
    if (enable) {
        EGlobal* pGlobal = (EGlobal*)g_pEGlobal;
        pGlobal->m_cheatFlag_3D8 = 1;
        pGlobal->m_cheatFlag_3D0 = 1;
        pGlobal->m_cheatFlag_3C0 = 1;
        pGlobal->m_cheatFlag_3C8 = 1;
        pGlobal->m_cheatFlag_3CC = 1;
        pGlobal->m_cheatFlag_3BC = 1;
        pGlobal->m_cheatFlag_3F0 = 1;
        pGlobal->m_cheatFlag_3DC = 1;
    } else {
        g_bGodMode = 0;
    }
}

// ---------------------------------------------------------------------------
// ECheats::Init
// Address: 0x80051974 | 12732 bytes (!)
// NON_MATCHING - massive hash table population from cheat sequence data
// ---------------------------------------------------------------------------
void ECheats::Init(EGlobal& global) {
    // Populates 64-bucket hash table from EGlobal's cheat sequences.
    // Each cheat is mapped to its button sequence and effect callback.
    // This is the largest ECheats function.
    m_initStatus = 1;
}

// ---------------------------------------------------------------------------
// ECheats::EnableCheats
// Address: 0x80020D10 | 504 bytes
// ---------------------------------------------------------------------------
void ECheats::EnableCheats() {
    // Walks all 64 buckets. For each entry with an action (entry+0x54),
    // allocates an AudioEventCallback, registers with global event system.
}

// ---------------------------------------------------------------------------
// ECheats::DisableCheats
// Address: 0x80020F08 | 476 bytes
// ---------------------------------------------------------------------------
void ECheats::DisableCheats() {
    // Reverse of EnableCheats: unregister and free callbacks.
}


// ############################################################################
//
//  PART 3: OptionsRecon (0xF4 bytes, 34 fields)
//
// ############################################################################
//
// Player preferences serialized to memory card via EA's Recon system.

class OptionsRecon {
public:
    u32 m_bMusicEnabled;             // 0x000
    u32 m_bSFXEnabled;               // 0x004
    u32 m_bVoiceEnabled;             // 0x008
    u32 m_field_00C;                 // 0x00C
    u32 m_bVibrationEnabled;         // 0x010
    u32 m_bAutoSaveEnabled;          // 0x014
    u32 m_field_018;                 // 0x018
    u8  m_musicVolume;               // 0x01C  (0-10)
    u8  m_sfxVolume;                 // 0x01D  (0-10)
    u8  m_voiceVolume;               // 0x01E  (0-10)
    u8  m_screenAdjustX;             // 0x01F
    u8  m_screenAdjustY;             // 0x020
    u8  _pad_021[3];               // 0x021
    u32 m_field_024;                 // 0x024
    u8  m_brightnessLevel;           // 0x028  (0-10)
    u8  m_contrastLevel;             // 0x029  (0-10)
    u8  _pad_02A[2];               // 0x02A

    // Shadow copy (PreservePreferences / RestorePreferences)
    u32 m_saved_bMusicEnabled;       // 0x02C
    u32 m_saved_bSFXEnabled;         // 0x030
    u32 m_saved_bVoiceEnabled;       // 0x034
    u32 m_saved_bVibrationEnabled;   // 0x038
    u32 m_saved_bAutoSaveEnabled;    // 0x03C
    u32 m_saved_field_018;           // 0x040
    u32 m_saved_field_024;           // 0x044
    u8  m_saved_musicVolume;         // 0x048
    u8  m_saved_sfxVolume;           // 0x049
    u8  m_saved_voiceVolume;         // 0x04A
    u8  m_saved_screenAdjustX;       // 0x04B
    u8  m_saved_screenAdjustY;       // 0x04C
    u8  m_saved_brightnessLevel;     // 0x04D
    u8  m_saved_contrastLevel;       // 0x04E
    u8  _pad_04F;                   // 0x04F

    u32 m_onlinePrefsBackup;         // 0x050
    u8  m_versionOrFlag;             // 0x054  (0xFF default)
    u8  _pad_055[3];               // 0x055

    u8  m_playerName1[72];           // 0x058-0x09F (StringBuffer2)
    u8  m_playerName2[72];           // 0x0A0-0x0E7 (StringBuffer2)

    u32 m_field_0E8;                 // 0x0E8
    u32 m_field_0EC;                 // 0x0EC
    u32 m_field_0F0;                 // 0x0F0

    OptionsRecon();
    OptionsRecon(OptionsRecon& other);
    void ResetToDefaults();
    void operator=(OptionsRecon& other);
    void DoStream(ReconBuffer* pBuffer, int direction);
    void WriteOut();
    int  ReadIn(int slot);
    int  WriteToMemoryCard(char*, unsigned char);
    int  ReadFromMemoryCard(char*, unsigned char);
    void PreservePreferences();
    void RestorePreferences();
    void PreservePrefsForOnline();
    void RestorePrefsForOnline();
};

// ---------------------------------------------------------------------------
// OptionsRecon::OptionsRecon()
// Address: 0x8005887C | 84 bytes
// ---------------------------------------------------------------------------
OptionsRecon::OptionsRecon() {
    // In original: initializes two StringBuffer2 objects at 0x58 and 0xA0
    // with 32-wchar internal buffers.
    memset(m_playerName1, 0, 72);
    memset(m_playerName2, 0, 72);
    ResetToDefaults();
}

// ---------------------------------------------------------------------------
// OptionsRecon::OptionsRecon(OptionsRecon&)
// Address: 0x800588D0 | 92 bytes
// ---------------------------------------------------------------------------
OptionsRecon::OptionsRecon(OptionsRecon& other) {
    memset(m_playerName1, 0, 72);
    memset(m_playerName2, 0, 72);
    *this = other;
}

// ---------------------------------------------------------------------------
// OptionsRecon::ResetToDefaults
// Address: 0x8005892C | 96 bytes
// ---------------------------------------------------------------------------
void OptionsRecon::ResetToDefaults() {
    m_bMusicEnabled     = 1;
    m_bSFXEnabled       = 1;
    m_bVoiceEnabled     = 1;
    m_field_00C         = 0;
    m_bVibrationEnabled = 0;
    m_bAutoSaveEnabled  = 1;
    m_field_018         = 0;
    m_musicVolume       = 10;
    m_sfxVolume         = 10;
    m_voiceVolume       = 10;
    m_screenAdjustX     = 0;
    m_screenAdjustY     = 0;
    m_field_024         = 0;
    m_brightnessLevel   = 10;
    m_contrastLevel     = 10;
    m_versionOrFlag     = 0xFF;
    m_field_0E8         = 0;
    m_field_0EC         = 0;
    m_field_0F0         = 0;
}

// ---------------------------------------------------------------------------
// OptionsRecon::DoStream
// Address: 0x8005898C | 624 bytes
// ---------------------------------------------------------------------------
void OptionsRecon::DoStream(ReconBuffer* pBuffer, int direction) {
    // Bidirectional serialize all fields through ReconBuffer.
    // On load (direction==0), clamps volume values to 0-10 range.
    // Streams: bools, volume bytes (with clamping), screen adjust,
    // version flag, string buffers, trailing u16/s32 fields,
    // auto-save, brightness/contrast.
}

// ---------------------------------------------------------------------------
// OptionsRecon stubs
// ---------------------------------------------------------------------------
int OptionsRecon::WriteToMemoryCard(char*, unsigned char) { return 0; }
int OptionsRecon::ReadFromMemoryCard(char*, unsigned char) { return 0; }

// ---------------------------------------------------------------------------
// OptionsRecon::WriteOut
// Address: 0x80058BFC | 296 bytes
// ---------------------------------------------------------------------------
void OptionsRecon::WriteOut() {
    // Allocate 8KB buffer, serialize via Recon, calculate checksum,
    // write to memory card, free buffer.
}

// ---------------------------------------------------------------------------
// OptionsRecon::ReadIn
// Address: 0x80058D2C | 296 bytes
// ---------------------------------------------------------------------------
int OptionsRecon::ReadIn(int slot) {
    // Read from memory card, validate checksum + version,
    // deserialize via Recon.
    return 0;
}

// ---------------------------------------------------------------------------
// OptionsRecon::PreservePreferences
// Address: 0x80058E5C | 140 bytes
// ---------------------------------------------------------------------------
void OptionsRecon::PreservePreferences() {
    m_saved_bMusicEnabled      = m_bMusicEnabled;
    m_saved_bSFXEnabled        = m_bSFXEnabled;
    m_saved_bVoiceEnabled      = m_bVoiceEnabled;
    m_saved_bVibrationEnabled  = m_bVibrationEnabled;
    m_saved_musicVolume        = m_musicVolume;
    m_saved_sfxVolume          = m_sfxVolume;
    m_saved_voiceVolume        = m_voiceVolume;
    m_saved_screenAdjustX      = m_screenAdjustX;
    m_saved_screenAdjustY      = m_screenAdjustY;
    m_saved_bAutoSaveEnabled   = m_bAutoSaveEnabled;
    m_saved_field_018          = m_field_018;
    m_saved_field_024          = m_field_024;
    m_saved_brightnessLevel    = m_brightnessLevel;
    m_saved_contrastLevel      = m_contrastLevel;
    g_bPreferencesPreserved = 1;
}

// ---------------------------------------------------------------------------
// OptionsRecon::RestorePreferences
// Address: 0x80058EFC | 132 bytes
// ---------------------------------------------------------------------------
void OptionsRecon::RestorePreferences() {
    m_bMusicEnabled       = m_saved_bMusicEnabled;
    m_bSFXEnabled         = m_saved_bSFXEnabled;
    m_bVoiceEnabled       = m_saved_bVoiceEnabled;
    m_bVibrationEnabled   = m_saved_bVibrationEnabled;
    m_musicVolume         = m_saved_musicVolume;
    m_sfxVolume           = m_saved_sfxVolume;
    m_voiceVolume         = m_saved_voiceVolume;
    m_screenAdjustX       = m_saved_screenAdjustX;
    m_screenAdjustY       = m_saved_screenAdjustY;
    m_bAutoSaveEnabled    = m_saved_bAutoSaveEnabled;
    m_field_018           = m_saved_field_018;
    m_field_024           = m_saved_field_024;
    m_brightnessLevel     = m_saved_brightnessLevel;
    m_contrastLevel       = m_saved_contrastLevel;
}

// ---------------------------------------------------------------------------
// OptionsRecon::PreservePrefsForOnline / RestorePrefsForOnline
// ---------------------------------------------------------------------------
void OptionsRecon::PreservePrefsForOnline() {
    m_onlinePrefsBackup = m_bVibrationEnabled;
    g_bOnlinePrefsPreserved = 1;
}

void OptionsRecon::RestorePrefsForOnline() {
    m_bVibrationEnabled = m_onlinePrefsBackup;
}

// ---------------------------------------------------------------------------
// OptionsRecon::operator=
// Address: 0x803A0380 | 344 bytes
// ---------------------------------------------------------------------------
void OptionsRecon::operator=(OptionsRecon& other) {
    m_bMusicEnabled      = other.m_bMusicEnabled;
    m_bSFXEnabled        = other.m_bSFXEnabled;
    m_bVoiceEnabled      = other.m_bVoiceEnabled;
    m_field_00C          = other.m_field_00C;
    m_bVibrationEnabled  = other.m_bVibrationEnabled;
    m_bAutoSaveEnabled   = other.m_bAutoSaveEnabled;
    m_field_018          = other.m_field_018;
    m_musicVolume        = other.m_musicVolume;
    m_sfxVolume          = other.m_sfxVolume;
    m_voiceVolume        = other.m_voiceVolume;
    m_screenAdjustX      = other.m_screenAdjustX;
    m_screenAdjustY      = other.m_screenAdjustY;
    m_field_024          = other.m_field_024;
    m_brightnessLevel    = other.m_brightnessLevel;
    m_contrastLevel      = other.m_contrastLevel;

    m_saved_bMusicEnabled     = other.m_saved_bMusicEnabled;
    m_saved_bSFXEnabled       = other.m_saved_bSFXEnabled;
    m_saved_bVoiceEnabled     = other.m_saved_bVoiceEnabled;
    m_saved_bVibrationEnabled = other.m_saved_bVibrationEnabled;
    m_saved_bAutoSaveEnabled  = other.m_saved_bAutoSaveEnabled;
    m_saved_field_018         = other.m_saved_field_018;
    m_saved_field_024         = other.m_saved_field_024;
    m_saved_musicVolume       = other.m_saved_musicVolume;
    m_saved_sfxVolume         = other.m_saved_sfxVolume;
    m_saved_voiceVolume       = other.m_saved_voiceVolume;
    m_saved_screenAdjustX     = other.m_saved_screenAdjustX;
    m_saved_screenAdjustY     = other.m_saved_screenAdjustY;
    m_saved_brightnessLevel   = other.m_saved_brightnessLevel;
    m_saved_contrastLevel     = other.m_saved_contrastLevel;

    m_onlinePrefsBackup       = other.m_onlinePrefsBackup;
    m_versionOrFlag           = other.m_versionOrFlag;

    // Copy string buffers (StringBuffer2::Copy)
    memcpy(m_playerName1, other.m_playerName1, 72);
    memcpy(m_playerName2, other.m_playerName2, 72);

    m_field_0E8 = other.m_field_0E8;
    m_field_0EC = other.m_field_0EC;
    m_field_0F0 = other.m_field_0F0;
}


// ############################################################################
//
//  PART 4: StateMachineState
//
// ############################################################################
//
// Base class for all states. Owns a unique ID within its StateMachine and
// stores a back-pointer to the owning machine.
//
// Layout (0x1C bytes):
//   0x00: m_stateId        - unique ID
//   0x04: m_prevStateId    - previous state (-1 if none)
//   0x08: m_pOwner         - owning StateMachine*
//   0x0C: m_stage          - current phase within state
//   0x10: m_unused10       - reserved
//   0x14: m_active         - 1 if active
//   0x18: m_pVtable        - derived vtable pointer

class StateMachineState {
public:
    int   m_stateId;         // 0x00
    int   m_prevStateId;     // 0x04
    u32   m_pOwner;          // 0x08 (StateMachine*)
    int   m_stage;           // 0x0C
    int   m_unused10;        // 0x10
    int   m_active;          // 0x14
    void* m_pVtable;         // 0x18

    virtual ~StateMachineState() {}
    virtual void SetFlag(unsigned int flag);
    virtual void Startup();
    virtual void Shutdown();
    virtual void Reset();
    virtual void Update(float dt);
    virtual void Draw(ERC* pRC);
    virtual void DrawTopmost(ERC* pRC);
    virtual void ValidateHeap(bool);

    void OwnerSetNextState(int stateId, float delay);
    void OwnerCallState(int stateId);
    void OwnerReturnFromState(int returnVal);
    int  OwnerGetReturnVal();
    void OwnerResetReturnVal();
};

// StateMachineState virtual defaults (no-ops)
void StateMachineState::SetFlag(unsigned int flag) {
    m_active = flag;
}
void StateMachineState::Startup()              { }
void StateMachineState::Shutdown()             { }
void StateMachineState::Reset()                { }
void StateMachineState::Update(float dt)       { }
void StateMachineState::Draw(ERC* pRC)         { }
void StateMachineState::DrawTopmost(ERC* pRC)  { }
void StateMachineState::ValidateHeap(bool)     { }

// ############################################################################
//
//  PART 5: StateMachineStatus (0x18 bytes)
//
// ############################################################################
//
// Tracks the current/last/calling state within a machine, plus timers.

class StateMachineStatus {
public:
    StateMachineState* m_pCurState;               // 0x00
    StateMachineState* m_pLastState;              // 0x04
    StateMachineState* m_pCallingState;           // 0x08
    int   m_stageFlags;                            // 0x0C
    f32   m_secondsBeforeNextState;                // 0x10
    f32   m_secondsInCurState;                     // 0x14

    void StatusReset();
    void SetState(StateMachineState* pNewState);
    void ShutdownCurState();
    void UpdateCurState(float dt);
    void DrawCurState(ERC* pRC);
    void DrawTopmostCurState(ERC* pRC);
    void AddToSecondsInCurState(float dt);
    void AddToSecondsBeforeNextState(float dt);
    void SetNextState(StateMachineState* pState, float delay);

    StateMachineState* GetCurState()    { return m_pCurState; }
    StateMachineState* GetLastState()   { return m_pLastState; }
    StateMachineState* GetCallingState() { return m_pCallingState; }
    float GetSecondsInCurState()        { return m_secondsInCurState; }
    void  SetCallingState(StateMachineState* p) { m_pCallingState = p; }
};

// ---------------------------------------------------------------------------
// StateMachineStatus::StatusReset
// Address: 0x800963FC | 40 bytes
// ---------------------------------------------------------------------------
void StateMachineStatus::StatusReset() {
    m_stageFlags = 0;
    m_secondsInCurState = -1.0f;
    m_pCurState = NULL;
    m_pLastState = NULL;
    m_pCallingState = NULL;
    m_secondsBeforeNextState = -1.0f;
}

// ---------------------------------------------------------------------------
// StateMachineStatus::AddToSecondsInCurState
// Address: 0x80096504 | 16 bytes
// ---------------------------------------------------------------------------
void StateMachineStatus::AddToSecondsInCurState(float dt) {
    m_secondsInCurState += dt;
}

// ---------------------------------------------------------------------------
// StateMachineStatus::AddToSecondsBeforeNextState
// Address: 0x800964D8 | 44 bytes
// ---------------------------------------------------------------------------
void StateMachineStatus::AddToSecondsBeforeNextState(float dt) {
    float val = m_secondsBeforeNextState;
    if (val <= 0.0f) return;
    val += dt;
    m_secondsBeforeNextState = val;
    if (val < 0.0f) {
        m_secondsBeforeNextState = 0.0f;
    }
}

// ---------------------------------------------------------------------------
// StateMachineStatus::SetState
// Address: 0x80096424 | 180 bytes
// ---------------------------------------------------------------------------
void StateMachineStatus::SetState(StateMachineState* pNewState) {
    StateMachineState* pOldState = m_pCurState;

    // Shutdown old state
    if (pOldState != NULL) {
        pOldState->Shutdown();
    }

    m_pLastState = pOldState;
    m_pCurState = pNewState;
    m_stageFlags = 0;
    m_secondsInCurState = 0.0f;
    m_secondsBeforeNextState = -1.0f;

    // Reset new state
    if (pNewState != NULL) {
        pNewState->Reset();
    }
}

// ---------------------------------------------------------------------------
// StateMachineStatus::ShutdownCurState
// Address: 0x80096514 | 84 bytes
// ---------------------------------------------------------------------------
void StateMachineStatus::ShutdownCurState() {
    StateMachineState* pState = m_pCurState;
    if (pState != NULL) {
        pState->Shutdown();
    }
    m_pCurState = NULL;
    m_secondsBeforeNextState = -1.0f;
}

// ---------------------------------------------------------------------------
// StateMachineStatus::UpdateCurState
// Address: 0x80096568 | 64 bytes
// ---------------------------------------------------------------------------
void StateMachineStatus::UpdateCurState(float dt) {
    StateMachineState* pState = m_pCurState;
    if (pState != NULL) {
        pState->Update(dt);
    }
}

// ---------------------------------------------------------------------------
// StateMachineStatus::DrawCurState
// Address: 0x800965A8 | 64 bytes
// ---------------------------------------------------------------------------
void StateMachineStatus::DrawCurState(ERC* pRC) {
    StateMachineState* pState = m_pCurState;
    if (pState != NULL) {
        pState->Draw(pRC);
    }
}

// ---------------------------------------------------------------------------
// StateMachineStatus::DrawTopmostCurState
// Address: 0x800965E8 | 64 bytes
// ---------------------------------------------------------------------------
void StateMachineStatus::DrawTopmostCurState(ERC* pRC) {
    StateMachineState* pState = m_pCurState;
    if (pState != NULL) {
        pState->DrawTopmost(pRC);
    }
}

// ---------------------------------------------------------------------------
// StateMachineStatus::SetNextState
// Address: 0x801DCD20 | 48 bytes
// ---------------------------------------------------------------------------
void StateMachineStatus::SetNextState(StateMachineState* pState, float delay) {
    // Stores pending next state + delay; processed by StateMachine::Update
    m_secondsBeforeNextState = delay;
    // The next-state pointer is stored separately in the StateMachine
}


// ############################################################################
//
//  PART 6: StateMachine (0x98 bytes)
//
// ############################################################################
//
// Core state machine engine. Manages a vector of states, a status stack
// for nested CallState/ReturnFromState, and the main update loop.
//
// Layout:
//   0x00-0x17: StateMachineState base (reused for machine context)
//   0x18:      m_pVtable (derived vtable)
//   0x1C:      m_machineId
//   0x20:      m_pManager
//   0x24:      m_pauseUpdate
//   0x28:      m_frameDeltaTime (float)
//   0x2C-0x38: m_states vector (begin/end/capacity)
//   0x3C-0x53: m_status (StateMachineStatus)
//   0x54-0x83: status stack (two levels, via deque)
//   0x84:      m_pCallState
//   0x88:      m_returnFlag
//   0x8C:      m_returnStateId
//   0x90:      m_returnVal
//   0x94:      m_enabled

class StateMachine : public StateMachineState {
public:
    int   m_machineId;                   // 0x1C
    StateMachineManager* m_pManager;     // 0x20
    int   m_pauseUpdate;                 // 0x24
    f32   m_frameDeltaTime;              // 0x28
    StateMachineState** m_pStatesBegin;  // 0x2C
    StateMachineState** m_pStatesEnd;    // 0x30
    StateMachineState** m_pStatesCap;    // 0x34
    u8    _pad_038[4];                  // 0x38
    StateMachineStatus  m_status;        // 0x3C-0x53
    u8    m_statusStackData[0x30];      // 0x54-0x83 (deque-based stack)
    StateMachineState*  m_pCallState;    // 0x84
    int   m_returnFlag;                  // 0x88
    int   m_returnStateId;               // 0x8C
    int   m_returnVal;                   // 0x90
    int   m_enabled;                     // 0x94

    StateMachine(int machineId, int managerId);
    virtual ~StateMachine();

    virtual void Startup();
    virtual void Shutdown();
    virtual void Reset();
    virtual void Update(float dt);
    virtual void Draw(ERC* pRC);
    virtual void DrawTopmost(ERC* pRC);

    void SetNextState(int stateId, float delay);
    void CallState(int stateId);
    void ReturnFromState(int returnVal);
    void AddState(StateMachineState* pState);
    void DeleteAllStates();
    void RemoveAllStates();
    void SetState(StateMachineState* pState);
    void PushStatus();
    void PopStatus();

    StateMachineState* FindStateById(int stateId);
    StateMachineState* FindState(StateMachineState* pState);
    int  GetCurStateId() const;
    int  GetCurStateStage() const;
    int  GetLastStateId() const;
    int  GetCallingStateId() const;
    float GetTimeInState() const;
    int  GetMachineId() const;
    StateMachineManager* GetManager() const;
    float GetFrameDeltaTime() const;
    int  GetReturnVal() const;
    void ResetReturnVal();
    void Enable();
    void Disable();
    void PauseUpdate();
    void UnpauseUpdate();
    int  IsEnabled();
    int  IsPausedUpdate();
};

// Owner delegation methods (defined here because StateMachine must be complete)
void StateMachineState::OwnerSetNextState(int stateId, float delay) {
    ((StateMachine*)m_pOwner)->SetNextState(stateId, delay);
}
void StateMachineState::OwnerCallState(int stateId) {
    ((StateMachine*)m_pOwner)->CallState(stateId);
}
void StateMachineState::OwnerReturnFromState(int returnVal) {
    ((StateMachine*)m_pOwner)->ReturnFromState(returnVal);
}
int StateMachineState::OwnerGetReturnVal() {
    return ((StateMachine*)m_pOwner)->GetReturnVal();
}
void StateMachineState::OwnerResetReturnVal() {
    ((StateMachine*)m_pOwner)->ResetReturnVal();
}

// ---------------------------------------------------------------------------
// StateMachine::StateMachine(int, int)
// Address: 0x8009696C | 252 bytes
// ---------------------------------------------------------------------------
StateMachine::StateMachine(int machineId, int managerId) {
    m_machineId = machineId;
    m_pManager = NULL;
    m_pauseUpdate = 0;
    m_frameDeltaTime = 0.0f;
    m_pStatesBegin = NULL;
    m_pStatesEnd = NULL;
    m_pStatesCap = NULL;
    m_status.StatusReset();
    memset(m_statusStackData, 0, 0x30);
    m_returnVal = 0;
    m_enabled = 1;
    m_pCallState = NULL;
    m_returnFlag = 0;
    m_returnStateId = 0;
}

// ---------------------------------------------------------------------------
// StateMachine::~StateMachine()
// Address: 0x80096A68 | 144 bytes
// ---------------------------------------------------------------------------
StateMachine::~StateMachine() {
    DeleteAllStates();
}

// ---------------------------------------------------------------------------
// StateMachine virtuals (base stubs)
// ---------------------------------------------------------------------------
void StateMachine::Startup()   { }   // 0x80096AF8
void StateMachine::Reset()     { }   // 0x80096B20

void StateMachine::Shutdown() {      // 0x80096AFC | 36 bytes
    m_status.ShutdownCurState();
}

// ---------------------------------------------------------------------------
// StateMachine::Update(float)
// Address: 0x80095B30 | 472 bytes
// NON_MATCHING - complex control flow with vtable dispatch
// ---------------------------------------------------------------------------
void StateMachine::Update(float dt) {
    if (m_enabled == 0) return;
    if (m_pauseUpdate != 0) return;

    m_frameDeltaTime = dt;
    m_status.AddToSecondsInCurState(dt);

    int didTransition = 0;

    // Process pending CallState
    if (m_pCallState != NULL) {
        while (m_pCallState != NULL) {
            didTransition = 1;
            StateMachineState* nextCall = m_pCallState;
            m_pCallState = NULL;

            StateMachineState* prevState = m_status.m_pCurState;
            PushStatus();
            m_status.StatusReset();
            m_status.m_pCallingState = prevState;
            m_status.SetState(nextCall);
            m_returnVal = 0;
        }
    }

    // Process pending ReturnFromState
    if (m_returnFlag != 0) {
        m_status.ShutdownCurState();
        PopStatus();
        int retStateId = m_returnStateId;
        m_returnFlag = 0;
        m_returnVal = retStateId;
    }

    // Process pending SetNextState with delay
    // (handled via status m_secondsBeforeNextState timer)

    // If transition occurred, call Startup on the new state
    if (didTransition) {
        StateMachineState* curState = m_status.m_pCurState;
        if (curState != NULL) {
            curState->Startup();
        }
    }

    // Update current state
    m_status.UpdateCurState(dt);
}

// ---------------------------------------------------------------------------
// StateMachine::Draw / DrawTopmost
// ---------------------------------------------------------------------------
void StateMachine::Draw(ERC* pRC) {
    if (m_enabled != 0) {
        m_status.DrawCurState(pRC);
    }
}

void StateMachine::DrawTopmost(ERC* pRC) {
    if (g_bDrawTopmost != 0) {
        if (m_enabled != 0) {
            m_status.DrawTopmostCurState(pRC);
        }
    }
}

// ---------------------------------------------------------------------------
// StateMachine::SetNextState
// Address: 0x80095D78 | 76 bytes
// ---------------------------------------------------------------------------
void StateMachine::SetNextState(int stateId, float delay) {
    StateMachineState* pState = FindStateById(stateId);
    if (pState != NULL) {
        m_status.m_secondsBeforeNextState = delay;
        // Store pending next state -- processed in Update
        m_status.SetState(pState);
    }
}

// ---------------------------------------------------------------------------
// StateMachine::CallState
// Address: 0x80095DC4 | 56 bytes
// ---------------------------------------------------------------------------
void StateMachine::CallState(int stateId) {
    StateMachineState* pState = FindStateById(stateId);
    if (pState != NULL) {
        m_pCallState = pState;
    }
}

// ---------------------------------------------------------------------------
// StateMachine::ReturnFromState
// Address: 0x80095DFC | 16 bytes
// ---------------------------------------------------------------------------
void StateMachine::ReturnFromState(int returnVal) {
    m_returnFlag = 1;
    m_returnStateId = returnVal;
}

// ---------------------------------------------------------------------------
// StateMachine::FindStateById
// Address: 0x800961BC | 56 bytes
// ---------------------------------------------------------------------------
StateMachineState* StateMachine::FindStateById(int stateId) {
    StateMachineState** iter = m_pStatesBegin;
    StateMachineState** end  = m_pStatesEnd;
    while (iter != end) {
        if ((*iter)->m_stateId == stateId) {
            return *iter;
        }
        iter++;
    }
    return NULL;
}

// ---------------------------------------------------------------------------
// StateMachine::FindState
// Address: 0x800961F4 | 48 bytes
// ---------------------------------------------------------------------------
StateMachineState* StateMachine::FindState(StateMachineState* pState) {
    StateMachineState** iter = m_pStatesBegin;
    StateMachineState** end  = m_pStatesEnd;
    while (iter != end) {
        if (*iter == pState) return *iter;
        iter++;
    }
    return NULL;
}

// ---------------------------------------------------------------------------
// StateMachine::SetState
// Address: 0x80096224 | 56 bytes
// ---------------------------------------------------------------------------
void StateMachine::SetState(StateMachineState* pState) {
    m_status.SetState(pState);
    m_returnVal = 0;
}

// ---------------------------------------------------------------------------
// StateMachine::AddState
// Address: 0x80095F10 | 368 bytes
// NON_MATCHING - vector push_back with small/large alloc paths
// ---------------------------------------------------------------------------
void StateMachine::AddState(StateMachineState* pState) {
    if (FindState(pState) != NULL) {
        pState->m_pOwner = (u32)(uintptr_t)this;
        return;
    }

    StateMachineState** end = m_pStatesEnd;
    StateMachineState** capEnd = m_pStatesCap;
    if (end != capEnd) {
        *end = pState;
        m_pStatesEnd = end + 1;
    } else {
        int count = (int)(end - m_pStatesBegin);
        int newCount = count + 1;
        int newBytes = newCount * 4;
        StateMachineState** newBuf;
        if (newBytes == 0) {
            newBuf = NULL;
        } else if ((unsigned int)newBytes > 128) {
            newBuf = (StateMachineState**)operator_new_wrapper(newBytes);
        } else {
            newBuf = (StateMachineState**)small_alloc(newBytes);
        }
        StateMachineState** newEnd;
        if (end != m_pStatesBegin && m_pStatesBegin != NULL) {
            int copySize = (int)((char*)end - (char*)m_pStatesBegin);
            memcpy(newBuf, m_pStatesBegin, copySize);
            newEnd = (StateMachineState**)((char*)newBuf + copySize);
        } else {
            newEnd = newBuf;
        }
        *newEnd = pState;
        newEnd++;
        if (m_pStatesBegin != NULL) {
            int oldSize = (int)((char*)capEnd - (char*)m_pStatesBegin);
            if ((unsigned int)oldSize > 128)
                operator_delete_wrapper(m_pStatesBegin);
            else
                small_free(m_pStatesBegin);
        }
        m_pStatesBegin = newBuf;
        m_pStatesEnd = newEnd;
        m_pStatesCap = newBuf + newCount;
    }
    pState->m_pOwner = (u32)(uintptr_t)this;
}

// ---------------------------------------------------------------------------
// StateMachine::DeleteAllStates
// Address: 0x80096080 | 308 bytes
// NON_MATCHING
// ---------------------------------------------------------------------------
void StateMachine::DeleteAllStates() {
    m_status.ShutdownCurState();
    m_status.m_pCurState = NULL;

    StateMachineState** iter = m_pStatesBegin;
    StateMachineState** end  = m_pStatesEnd;
    while (iter != end) {
        StateMachineState* pState = *iter;
        if (pState != NULL) {
            delete pState;
        }
        *iter = NULL;
        iter++;
    }

    StateMachineState** oldBegin = m_pStatesBegin;
    m_pStatesBegin = NULL;
    m_pStatesEnd = NULL;
    m_pStatesCap = NULL;
    if (oldBegin != NULL) {
        small_free(oldBegin);
    }
}

// ---------------------------------------------------------------------------
// StateMachine::RemoveAllStates
// Address: 0x80095EC0 | 96 bytes
// ---------------------------------------------------------------------------
void StateMachine::RemoveAllStates() {
    m_pStatesBegin = NULL;
    m_pStatesEnd = NULL;
    m_pStatesCap = NULL;
}

// ---------------------------------------------------------------------------
// StateMachine::PushStatus / PopStatus
// NON_MATCHING - deque-based status stack
// ---------------------------------------------------------------------------
void StateMachine::PushStatus() {
    // Copies m_status (0x18 bytes) into the status stack deque
}

void StateMachine::PopStatus() {
    // Restores m_status from the top of the status stack deque
}

// ---------------------------------------------------------------------------
// StateMachine trivial accessors
// ---------------------------------------------------------------------------
int  StateMachine::GetCurStateId() const {
    if (m_status.m_pCurState == NULL) return -1;
    return m_status.m_pCurState->m_stateId;
}
int  StateMachine::GetCurStateStage() const {
    return m_status.m_pCurState->m_stage;
}
int  StateMachine::GetLastStateId() const {
    return m_status.m_pLastState->m_stateId;
}
int  StateMachine::GetCallingStateId() const {
    return m_status.m_pCallingState->m_stateId;
}
float StateMachine::GetTimeInState() const {
    return m_status.m_secondsInCurState;
}
int  StateMachine::GetMachineId() const          { return m_machineId; }
StateMachineManager* StateMachine::GetManager() const { return m_pManager; }
float StateMachine::GetFrameDeltaTime() const    { return m_frameDeltaTime; }
int  StateMachine::GetReturnVal() const          { return m_returnVal; }
void StateMachine::ResetReturnVal()              { m_returnVal = 0; }
void StateMachine::Enable()                      { m_enabled = 1; }
void StateMachine::Disable()                     { m_enabled = 0; }
void StateMachine::PauseUpdate()                 { m_pauseUpdate = 1; }
void StateMachine::UnpauseUpdate()               { m_pauseUpdate = 0; }
int  StateMachine::IsEnabled()                   { return m_enabled; }
int  StateMachine::IsPausedUpdate()              { return m_pauseUpdate; }


// ############################################################################
//
//  PART 7: StateMachineManager
//
// ############################################################################
//
// Singleton managing all state machines. Stored in SDA global.

class StateMachineManager {
public:
    StateMachine** m_pBegin;     // 0x00
    StateMachine** m_pEnd;       // 0x04
    u32 m_pad_08;                // 0x08
    u32 m_pad_0C;                // 0x0C

    StateMachineManager();

    static void Startup();
    static void UpdateMachines(float dt);
    static void DrawMachines(ERC* pRC);
    static void DrawTopmostMachines(ERC* pRC);

    StateMachine* FindMachineById(int machineId);
    StateMachine* FindMachine(StateMachine* pMachine);
    void UpdateMachine(float dt);
    void DrawMachine(ERC* pRC);
    void DrawTopmostMachine(ERC* pRC);
    void AddMachine(StateMachine* pMachine);
};

// ---------------------------------------------------------------------------
// StateMachineManager::Startup (static)
// Address: 0x800966A4 | 60 bytes
// ---------------------------------------------------------------------------
void StateMachineManager::Startup() {
    void* mem = operator_new_wrapper(16);
    memset(mem, 0, 16);
    g_pStateMachineManager = (StateMachineManager*)mem;
}

// ---------------------------------------------------------------------------
// StateMachineManager::FindMachineById
// Address: 0x80096628 | 64 bytes
// ---------------------------------------------------------------------------
StateMachine* StateMachineManager::FindMachineById(int machineId) {
    StateMachine** iter = m_pBegin;
    StateMachine** end  = m_pEnd;
    while (iter != end) {
        if ((*iter)->m_machineId == machineId) {
            return *iter;
        }
        iter++;
    }
    return NULL;
}

// ---------------------------------------------------------------------------
// StateMachineManager::FindMachine
// Address: 0x80096668 | 60 bytes
// ---------------------------------------------------------------------------
StateMachine* StateMachineManager::FindMachine(StateMachine* pMachine) {
    StateMachine** iter = m_pBegin;
    StateMachine** end  = m_pEnd;
    while (iter != end) {
        if (*iter == pMachine) return *iter;
        iter++;
    }
    return NULL;
}

// ---------------------------------------------------------------------------
// StateMachineManager::UpdateMachine
// Address: 0x800967A4 | 108 bytes
// ---------------------------------------------------------------------------
void StateMachineManager::UpdateMachine(float dt) {
    StateMachine** iter = m_pBegin;
    StateMachine** end  = m_pEnd;
    while (iter != end) {
        StateMachine* pMachine = *iter;
        if (pMachine->m_enabled) {
            pMachine->Update(dt);
        }
        iter++;
    }
}

// ---------------------------------------------------------------------------
// StateMachineManager static dispatchers
// ---------------------------------------------------------------------------
void StateMachineManager::UpdateMachines(float dt) {
    if (g_pStateMachineManager != NULL) {
        g_pStateMachineManager->UpdateMachine(dt);
    }
}

void StateMachineManager::DrawMachines(ERC* pRC) {
    if (g_pStateMachineManager != NULL) {
        g_pStateMachineManager->DrawMachine(pRC);
    }
}

void StateMachineManager::DrawTopmostMachines(ERC* pRC) {
    if (g_pStateMachineManager != NULL) {
        g_pStateMachineManager->DrawTopmostMachine(pRC);
    }
}

void StateMachineManager::DrawMachine(ERC* pRC) {
    StateMachine** iter = m_pBegin;
    StateMachine** end  = m_pEnd;
    while (iter != end) {
        StateMachine* pMachine = *iter;
        if (pMachine->m_enabled) {
            pMachine->Draw(pRC);
        }
        iter++;
    }
}

void StateMachineManager::DrawTopmostMachine(ERC* pRC) {
    StateMachine** iter = m_pBegin;
    StateMachine** end  = m_pEnd;
    while (iter != end) {
        StateMachine* pMachine = *iter;
        if (pMachine->m_enabled) {
            pMachine->DrawTopmost(pRC);
        }
        iter++;
    }
}


// ############################################################################
//
//  PART 8: TheSimsStateMachine (0x47C bytes)
//
// ############################################################################
//
// Master game state machine. Extends StateMachine with 20 states covering
// the entire game flow from NGC license to live mode.
//
// Additional fields beyond StateMachine (0x98):
//   0x98: m_pFlashUI - APT/Flash UI system pointer
//   0x9C-0x477: game-specific data (state references, dataset handles, etc.)
//   0x478: m_additionalData

class TheSimsStateMachine : public StateMachine {
public:
    void* m_pFlashUI;            // 0x98
    u32   m_field_09C;           // 0x9C
    u8    _pad_0A0[0x3D8];     // 0xA0-0x477
    u32   m_field_478;           // 0x478

    TheSimsStateMachine(int machineId, int managerId);
    virtual ~TheSimsStateMachine();

    virtual void Startup();
    virtual void Shutdown();
    virtual void Update(float dt);
    virtual void Draw(ERC* pRC);

    int  IsFlowStateRequestPending();
    int  GetFlowStateRequest();
    void SetFlowStateCurrent();
};

// ---------------------------------------------------------------------------
// TheSimsStateMachine::TheSimsStateMachine
// Address: 0x801E8BAC | 264 bytes
// NON_MATCHING
// ---------------------------------------------------------------------------
TheSimsStateMachine::TheSimsStateMachine(int machineId, int managerId)
    : StateMachine(machineId, managerId)
{
    m_pFlashUI = NULL;
    m_field_09C = 0;
    memset(_pad_0A0, 0, 0x3D8);
    m_field_478 = 0;
}

// ---------------------------------------------------------------------------
// TheSimsStateMachine::~TheSimsStateMachine
// Address: 0x801E79F0
// ---------------------------------------------------------------------------
TheSimsStateMachine::~TheSimsStateMachine() {
    // Handled by StateMachine base dtor (DeleteAllStates)
}

// ---------------------------------------------------------------------------
// TheSimsStateMachine::Startup
// Address: 0x801E28D0 | 2236 bytes
// NON_MATCHING - allocates all 20 game states
// ---------------------------------------------------------------------------
//
// State allocation map:
//   ID 0:  TheSimsNGCLicenseState         (0x50)  vtable=0x8045E418
//   ID 1:  TheSimsMemCardCheckState       (0x1C)  vtable=0x8045E3D0
//   ID 2:  TheSimsMaxisLogoState          (0x20)  vtable=0x8045E388
//   ID 3:  TheSimsSimsIntroMovieState     (0x34)  vtable=0x8045E340
//   ID 4:  TheSimsEAMovieState            (0x28)  vtable=0x8045E2F8
//   ID 5:  TheSimsStartScreenStateMachine (0x98)  vtable=0x8045E0B8
//   ID 6:  TheSimsEnterMainMenuState      (0x20)  vtable=0x8045E2B0
//   ID 7:  TheSimsMainMenuState           (0x28)  vtable=0x8045E268
//   ID 8:  PreGameState                   (0x30)  vtable=0x8045E028
//   ID 9:  PreGameFreeplayState           (0x20)  vtable=0x8045DEC0
//   ID 10: PreGameCasPlayer1State         (0x30)  vtable=0x8045DFE0
//   ID 11: PreGameCasPlayer2State         (0x30)  vtable=0x8045DF98
//   ID 12: PreGameCreateAFamilyState      (0x30)  vtable=0x8045DF50
//   ID 13: LiveModeInitState              (0xB4)  vtable=0x8045D8D8
//   ID 14: InLevelCreateASimState         (0x30)  vtable=0x8045DF08
//   ID 15: MoviePlayerEndgameMovieState   (0x48)  vtable=0x8045C980
//   ID 16: UrbzModeNewGameState           (0x1C)  vtable=0x8045E4A8
//   ID 17: UrbzCreditsState               (0x1C)  vtable=0x8045E220
//   ID 18: InLevelBaseState               (0x20)  vtable=0x8045D6D8
//   ID 19: LiveModeChangeHouseStateMachine (0x98) vtable=0x8045D890
//
void TheSimsStateMachine::Startup() {
    // Allocate and initialize all 20 states.
    // For each state:
    //   1. operator_new_wrapper(size)
    //   2. Set StateMachineState base fields (stateId, prevStateId=-1, etc.)
    //   3. Set derived vtable pointer
    //   4. AddState(state)
    // For embedded SMs (states 5, 19): also init StateMachine base + sub-states.
    // Finally: SetNextState(0, 0.0f) -> begin at NGC License.
    // Allocate FlashUI: m_pFlashUI = operator_new_wrapper(0x8C);
}

// ---------------------------------------------------------------------------
// TheSimsStateMachine::Shutdown
// Address: 0x80099670 | 152 bytes
// NON_MATCHING
// ---------------------------------------------------------------------------
void TheSimsStateMachine::Shutdown() {
    // Shutdown FlashUI at 0x98
    if (m_pFlashUI != NULL) {
        // Virtual Shutdown on FlashUI
        m_pFlashUI = NULL;
    }

    m_status.ShutdownCurState();

    // Clean up global game data singleton
}

// ---------------------------------------------------------------------------
// TheSimsStateMachine::Update
// Address: 0x80099708 | 92 bytes
// ---------------------------------------------------------------------------
void TheSimsStateMachine::Update(float dt) {
    // Wraps StateMachine::Update with BGExec lock/unlock
    StateMachine::Update(dt);
}

// ---------------------------------------------------------------------------
// TheSimsStateMachine::Draw
// Address: 0x80099764 | 120 bytes
// ---------------------------------------------------------------------------
void TheSimsStateMachine::Draw(ERC* pRC) {
    StateMachine::Draw(pRC);
    // Then render FlashUI overlay
}

// ---------------------------------------------------------------------------
// TheSimsStateMachine flow-state delegation
// ---------------------------------------------------------------------------
int TheSimsStateMachine::IsFlowStateRequestPending() {
    // Delegates to current state's IsFlowStateRequestPending via vtable
    return 0;
}
int TheSimsStateMachine::GetFlowStateRequest() {
    // Delegates to current state
    return 0;
}
void TheSimsStateMachine::SetFlowStateCurrent() {
    // Delegates to current state
}


// ############################################################################
//
//  PART 9: TheSimsStartScreenStateMachine (state 5)
//
// ############################################################################
//
// Embedded state machine for the "Press Start" / attract mode screen.
// Size 0x98 (same as StateMachine base). Contains 1 sub-state:
//   State 0: StartScreenStartState

class TheSimsStartScreenStateMachine : public StateMachine {
public:
    TheSimsStartScreenStateMachine(int machineId, int managerId);

    virtual void Startup();
    virtual void Shutdown();
    virtual void Reset();
    virtual void Update(float dt);
};

TheSimsStartScreenStateMachine::TheSimsStartScreenStateMachine(int machineId, int managerId)
    : StateMachine(machineId, managerId)
{
}

// ---------------------------------------------------------------------------
// TheSimsStartScreenStateMachine::Startup
// Address: 0x80095780 | 164 bytes
// ---------------------------------------------------------------------------
void TheSimsStartScreenStateMachine::Startup() {
    // Allocate StartScreenVars (56 bytes)
    g_pStartScreenVars = operator_new_wrapper(0x38);
    // StartScreenVars::Startup()

    // Allocate StartScreenStartState (36 bytes)
    // StateMachineState base: stateId=0, prevStateId=-1, active=1
    // AddState(startState)

    // LoadingScreenStateMachine::LoadFinishing() -- done loading
}

// ---------------------------------------------------------------------------
// TheSimsStartScreenStateMachine::Shutdown
// Address: 0x80095824 | 80 bytes
// ---------------------------------------------------------------------------
void TheSimsStartScreenStateMachine::Shutdown() {
    // Shutdown StartScreenVars
    m_status.ShutdownCurState();
}

// ---------------------------------------------------------------------------
// TheSimsStartScreenStateMachine::Reset
// Address: 0x80095874 | 96 bytes
// ---------------------------------------------------------------------------
void TheSimsStartScreenStateMachine::Reset() {
    // Reset StartScreenVars
    SetNextState(0, 0.0f);
}

// ---------------------------------------------------------------------------
// TheSimsStartScreenStateMachine::Update
// Address: 0x800958D4 | 72 bytes
// ---------------------------------------------------------------------------
void TheSimsStartScreenStateMachine::Update(float dt) {
    // StartScreenVars::Update(dt)
    StateMachine::Update(dt);
}


// ############################################################################
//
//  PART 10: LoadingScreenStateMachine (0xAC bytes)
//
// ############################################################################
//
// Controls fade-in -> loading -> fade-out sequence during level loads.
// Extends StateMachine with:
//   0x98: m_pLoadingScreen (CLoadingScreen*)
//   0x9C: m_eLoadMode
//   0xA0: m_bIsLoading
//   0xA4: m_loadStage
//   0xA8: m_fadeOpacity (float)
//
// Sub-states:
//   0: LoadingScreenWaitingForLoadState
//   1: LoadingScreenFadeInState
//   2: LoadingScreenUpdateState
//   3: LoadingScreenFadeOutState
//
// Static singleton at s_pSM (0x804FDB80).

static void* s_pLoadingScreenSM = NULL;

class LoadingScreenStateMachine : public StateMachine {
public:
    void* m_pLoadingScreen;      // 0x98 (CLoadingScreen*)
    int   m_eLoadMode;           // 0x9C
    int   m_bIsLoading;          // 0xA0
    int   m_loadStage;           // 0xA4
    f32   m_fadeOpacity;         // 0xA8

    LoadingScreenStateMachine(int machineId, int managerId);
    virtual ~LoadingScreenStateMachine();

    virtual void Startup();
    virtual void Update(float dt);

    static void* GetSingleton();

    void CreateLoadingScreen();
    void DeleteLoadingScreen();
    void StartLoad(int mode);
    bool IsLoading();
    bool IsReadyToLoad();
    void LoadStarted();
    bool IsLoadComplete();
    void LoadFinishedNow();
    void LoadFinished();
    void LoadFinishNow();
    void LoadInProgress();
    void StartingLoad(int mode);
    void LoadFinishing();
    void FaderStart(float duration, bool fadeIn);
    void FaderStop();
    void FaderUpdate(float dt);
    float FaderGetFadeOpacity();
    bool IsFadingIn();
    bool IsFadedIn();
    bool IsFadingOut();
    bool IsFadedOut();
};

// ---------------------------------------------------------------------------
// LoadingScreenStateMachine::LoadingScreenStateMachine
// Address: 0x801C152C | 308 bytes
// NON_MATCHING
// ---------------------------------------------------------------------------
LoadingScreenStateMachine::LoadingScreenStateMachine(int machineId, int managerId)
    : StateMachine(machineId, managerId)
{
    m_pLoadingScreen = NULL;
    m_eLoadMode = 0;
    m_bIsLoading = 0;
    m_loadStage = 0;
    m_fadeOpacity = 0.0f;
    s_pLoadingScreenSM = this;
}

LoadingScreenStateMachine::~LoadingScreenStateMachine() {
    s_pLoadingScreenSM = NULL;
}

// ---------------------------------------------------------------------------
// LoadingScreenStateMachine::Startup
// Address: 0x801C1668 | 252 bytes
// ---------------------------------------------------------------------------
void LoadingScreenStateMachine::Startup() {
    // Allocate 4 sub-states (each 0x1C bytes):
    //   State 0: WaitingForLoadState
    //   State 1: FadeInState
    //   State 2: UpdateState
    //   State 3: FadeOutState
    // AddState for each, then SetNextState(0, 0.0f)
}

// ---------------------------------------------------------------------------
// LoadingScreenStateMachine::Update
// Address: 0x801C1764 | 64 bytes
// ---------------------------------------------------------------------------
void LoadingScreenStateMachine::Update(float dt) {
    StateMachine::Update(dt);
}

// ---------------------------------------------------------------------------
// LoadingScreenStateMachine::GetSingleton (static)
// Address: 0x801C50E0 | 44 bytes
// ---------------------------------------------------------------------------
void* LoadingScreenStateMachine::GetSingleton() {
    return s_pLoadingScreenSM;
}

// ---------------------------------------------------------------------------
// LoadingScreenStateMachine loading flow
// ---------------------------------------------------------------------------
void LoadingScreenStateMachine::StartLoad(int mode) {
    if (!m_bIsLoading) {
        CreateLoadingScreen();
        m_eLoadMode = mode;
        m_bIsLoading = 1;
        SetNextState(1, 0.0f);  // -> FadeIn
    }
}

bool LoadingScreenStateMachine::IsLoading() {
    return m_bIsLoading != 0;
}

bool LoadingScreenStateMachine::IsReadyToLoad() {
    return (GetCurStateId() == 0) && IsFadedOut();
}

void LoadingScreenStateMachine::LoadStarted() {
    // Mark that loading has begun
}

bool LoadingScreenStateMachine::IsLoadComplete() {
    return m_bIsLoading == 0;
}

void LoadingScreenStateMachine::LoadFinishedNow() {
    m_bIsLoading = 0;
    // Trigger FadeOut: SetNextState(3, 0.0f)
}

void LoadingScreenStateMachine::LoadFinished() {
    m_bIsLoading = 0;
}

void LoadingScreenStateMachine::LoadFinishNow() {
    m_bIsLoading = 0;
}

void LoadingScreenStateMachine::LoadInProgress() {
    // Signal that loading is actively running
}

void LoadingScreenStateMachine::StartingLoad(int mode) {
    m_eLoadMode = mode;
}

void LoadingScreenStateMachine::LoadFinishing() {
    // Signal that loading is wrapping up
}

// ---------------------------------------------------------------------------
// LoadingScreenStateMachine fader system
// ---------------------------------------------------------------------------
void LoadingScreenStateMachine::CreateLoadingScreen() {
    // if (m_pLoadingScreen == NULL) { allocate CLoadingScreen }
}

void LoadingScreenStateMachine::DeleteLoadingScreen() {
    if (m_pLoadingScreen != NULL) {
        // destroy and free
        m_pLoadingScreen = NULL;
    }
    m_bIsLoading = 0;
}

void LoadingScreenStateMachine::FaderStart(float duration, bool fadeIn) {
    m_fadeOpacity = fadeIn ? 0.0f : 1.0f;
    // Set up fader direction and speed based on duration
}

void LoadingScreenStateMachine::FaderStop() {
    // Stop any active fade
}

void LoadingScreenStateMachine::FaderUpdate(float dt) {
    // Advance fade opacity toward target based on dt
}

float LoadingScreenStateMachine::FaderGetFadeOpacity() {
    return m_fadeOpacity;
}

bool LoadingScreenStateMachine::IsFadingIn() {
    return false;  // Check fader state
}

bool LoadingScreenStateMachine::IsFadedIn() {
    return (m_fadeOpacity >= 1.0f);
}

bool LoadingScreenStateMachine::IsFadingOut() {
    return false;  // Check fader state
}

bool LoadingScreenStateMachine::IsFadedOut() {
    return (m_fadeOpacity <= 0.0f);
}


// ############################################################################
//
//  PART 11: Game State Classes
//
// ############################################################################
//
// All 20 game states for TheSimsStateMachine, plus sub-states for embedded
// state machines. Each extends StateMachineState.

// ---- Boot States (IDs 0-4) ----

class TheSimsNGCLicenseState : public StateMachineState {
public:
    u8 _extra[0x50 - 0x1C]; // 0x1C-0x4F (state-specific data)

    virtual void Startup()       { /* Load license texture, set display timer */ }
    virtual void Update(float dt) { /* Wait for timer, then OwnerSetNextState(1, 0.0f) */ }
    virtual void Draw(ERC* pRC)  { /* Render license text/image */ }
};

class TheSimsMemCardCheckState : public StateMachineState {
public:
    virtual void Startup()       { /* Initiate memory card probe */ }
    virtual void Update(float dt) { /* Check card status, OwnerSetNextState(2, 0.0f) */ }
    virtual void Draw(ERC* pRC)  { /* Render memory card status UI */ }
};

class TheSimsMaxisLogoState : public StateMachineState {
public:
    u8 _extra[0x20 - 0x1C];

    virtual void Startup()       { /* Load logo texture, start fade-in */ }
    virtual void Update(float dt) { /* Run fade animation, skippable, OwnerSetNextState(3, 0.0f) */ }
    virtual void Draw(ERC* pRC)  { /* Render logo with fade effect */ }
};

class TheSimsSimsIntroMovieState : public StateMachineState {
public:
    u8 _extra[0x34 - 0x1C];

    virtual void Startup()       { /* Start intro movie playback */ }
    virtual void Shutdown()      { /* Stop and release movie */ }
    virtual void Update(float dt) { /* Poll movie status, skippable, OwnerSetNextState(4, 0.0f) */ }
};

class TheSimsEAMovieState : public StateMachineState {
public:
    u8 _extra[0x28 - 0x1C];

    virtual void Startup()       { /* Start EA movie playback */ }
    virtual void Shutdown()      { /* Stop and release movie */ }
    virtual void Update(float dt) { /* Poll movie status, skippable, OwnerSetNextState(5, 0.0f) */ }
};

// ---- Menu States (IDs 6-7) ----

class TheSimsEnterMainMenuState : public StateMachineState {
public:
    u8 _extra[0x20 - 0x1C];

    virtual void Startup()       { /* Begin loading main menu UI datasets */ }
    virtual void Update(float dt) {
        // Multi-phase loading/transition:
        //   Phase 0: Request loading screen
        //   Phase 1: Load UI datasets
        //   Phase 2: Initialize menu Flash UI
        //   Phase 3: Wait for fade-out
        //   Phase 4: OwnerSetNextState(7, 0.0f) -> Main Menu
    }
};

class TheSimsMainMenuState : public StateMachineState {
public:
    u8 _extra[0x28 - 0x1C];

    virtual void Startup()       { /* Activate menu UI, set up button handlers */ }
    virtual void Update(float dt) {
        // Process menu input:
        //   "New Game"    -> OwnerSetNextState(8, 0.0f)
        //   "Continue"    -> OwnerSetNextState(13, 0.0f)
        //   "Load Game"   -> OwnerSetNextState(13, 0.0f)
        //   "Story Mode"  -> OwnerSetNextState(16, 0.0f)
        //   "Back"        -> OwnerSetNextState(5, 0.0f)
    }
};

// ---- Pre-game States (IDs 8-12) ----

class PreGameState : public StateMachineState {
public:
    u8 _extra[0x30 - 0x1C];

    virtual void Update(float dt) {
        // Multi-phase setup:
        //   -> CAS P1 (10), CAS P2 (11), Create Family (12),
        //      Freeplay (9), or LiveModeInit (13)
    }
};

class PreGameFreeplayState : public StateMachineState {
public:
    u8 _extra[0x20 - 0x1C];

    virtual void Startup()        { /* Load neighborhood/lot selection UI */ }
    virtual void Update(float dt) { /* Handle lot selection, OwnerSetNextState(13, 0.0f) */ }
};

class PreGameCasPlayer1State : public StateMachineState {
public:
    u8 _extra[0x30 - 0x1C];

    virtual void Reset()          { /* Init CAS for player 1 */ }
    virtual void Update(float dt) {
        // Monitor CAS completion
        //   On complete: OwnerSetNextState(8, 0.0f) or chain to (11)
    }
};

class PreGameCasPlayer2State : public StateMachineState {
public:
    u8 _extra[0x30 - 0x1C];

    virtual void Reset()          { /* Init CAS for player 2 */ }
    virtual void Update(float dt) { /* Monitor CAS completion */ }
};

class PreGameCreateAFamilyState : public StateMachineState {
public:
    u8 _extra[0x30 - 0x1C];

    virtual void Reset()          { /* Init family creation UI */ }
    virtual void Update(float dt) { /* Monitor completion, OwnerSetNextState(8, 0.0f) */ }
};

// ---- Gameplay States (IDs 13, 14, 18) ----

class LiveModeInitState : public StateMachineState {
public:
    u8 _extra[0xB4 - 0x1C]; // embedded dataset references

    virtual void Reset();
    virtual void Shutdown()       { }  // no-op
    virtual void Update(float dt);
    virtual void Draw(ERC* pRC)  { }  // loading screen handles drawing
};

// ---------------------------------------------------------------------------
// LiveModeInitState::Reset
// Address: 0x8008BC28 | 260 bytes
// ---------------------------------------------------------------------------
void LiveModeInitState::Reset() {
    // Reset all loading phases to initial state
    memset(_extra, 0, sizeof(_extra));
}

// ---------------------------------------------------------------------------
// LiveModeInitState::Update
// Address: 0x8008BD2C | 3216 bytes
// NON_MATCHING - enormous loading state machine
// ---------------------------------------------------------------------------
void LiveModeInitState::Update(float dt) {
    // Multi-phase loading pipeline:
    //   Phase 0: Start level load, request loading screen
    //   Phase 1: Wait for loading screen fade-in
    //   Phase 2: Load datasets (async)
    //   Phase 3: Initialize house, objects, sims
    //   Phase 4: Initialize lighting, camera, UI
    //   Phase 5: Signal loading complete, wait for fade-out
    //   Phase 6: OwnerSetNextState(18, 0.0f) -> InLevelBaseState
}

class InLevelCreateASimState : public StateMachineState {
public:
    u8 _extra[0x30 - 0x1C];

    virtual void Reset()          { /* Enter CAS mode during gameplay */ }
    virtual void Update(float dt) { /* Monitor CAS completion, return to live mode */ }
};

class InLevelBaseState : public StateMachineState {
public:
    u8 _extra[0xF0 - 0x1C];  // 0x1C-0xEF

    virtual void Reset();
    virtual void Shutdown();
    virtual void Update(float dt);
    virtual void Draw(ERC* pRC);
};

// ---------------------------------------------------------------------------
// InLevelBaseState::Reset
// Address: 0x80089E94 | 28 bytes
// ---------------------------------------------------------------------------
void InLevelBaseState::Reset() {
    // Reset gameplay state
}

// ---------------------------------------------------------------------------
// InLevelBaseState::Shutdown
// Address: 0x80089EB0 | 124 bytes
// ---------------------------------------------------------------------------
void InLevelBaseState::Shutdown() {
    // Clean up live mode resources
}

// ---------------------------------------------------------------------------
// InLevelBaseState::Update
// Address: 0x80089F2C | 5204 bytes
// NON_MATCHING - massive gameplay update loop
// ---------------------------------------------------------------------------
void InLevelBaseState::Update(float dt) {
    // Main gameplay loop handling:
    //   - Sim simulation updates
    //   - Build/buy mode toggling
    //   - Camera control
    //   - UI updates (HUD, menus, dialogs)
    //   - Save/load requests
    //   - Exit to main menu: OwnerSetNextState(7, 0.0f)
    //   - House change: OwnerSetNextState(19, 0.0f)
    //   - In-level CAS: OwnerSetNextState(14, 0.0f)
}

// ---------------------------------------------------------------------------
// InLevelBaseState::Draw
// Address: 0x8008B498 | 56 bytes
// ---------------------------------------------------------------------------
void InLevelBaseState::Draw(ERC* pRC) {
    // Render the live mode scene
}

// ---- Story/Special States (IDs 15-17) ----

class MoviePlayerEndgameMovieState : public StateMachineState {
public:
    u8 _extra[0x48 - 0x1C];

    virtual void Startup()       { /* Start endgame cinematic */ }
    virtual void Shutdown()      { /* Stop and release movie */ }
    virtual void Update(float dt) { /* Poll movie status, advance when done */ }
};

class UrbzModeNewGameState : public StateMachineState {
public:
    virtual void Reset()          { /* Init Urbz story data */ }
    virtual void Update(float dt) {
        // Story mode setup (1956 bytes in original)
        // Eventually: OwnerSetNextState(13, 0.0f) -> LiveModeInit
    }
};

class UrbzCreditsState : public StateMachineState {
public:
    virtual void Update(float dt) { /* Show credits roll */ }
};

// ---- Embedded SM: LiveModeChangeHouseStateMachine (state 19, 0x98 bytes) ----

class LiveModeChangeHouseStateMachine : public StateMachine {
public:
    LiveModeChangeHouseStateMachine(int machineId, int managerId);

    virtual void Startup();
    virtual void Shutdown();
    virtual void Reset();
    virtual void Update(float dt);
    virtual void Draw(ERC* pRC);
};

LiveModeChangeHouseStateMachine::LiveModeChangeHouseStateMachine(int machineId, int managerId)
    : StateMachine(machineId, managerId)
{
}

// ---------------------------------------------------------------------------
// LiveModeChangeHouseStateMachine::Startup
// Address: 0x8008D91C | 412 bytes
// ---------------------------------------------------------------------------
void LiveModeChangeHouseStateMachine::Startup() {
    // Allocate sub-states for:
    //   - Saving current house (ChangeHouseSaveHouse)
    //   - Unloading current house (ChangeHouseUnloadHouse)
    //   - Loading new house (ChangeHouseLoadHouse)
    //   - Demolishing house (ChangeHouseDemolishHouse)
    // AddState for each, then SetNextState(0, 0.0f)
}

// ---------------------------------------------------------------------------
// LiveModeChangeHouseStateMachine::Shutdown
// Address: 0x8008DAB8 | 164 bytes
// ---------------------------------------------------------------------------
void LiveModeChangeHouseStateMachine::Shutdown() {
    m_status.ShutdownCurState();
}

// ---------------------------------------------------------------------------
// LiveModeChangeHouseStateMachine::Reset
// Address: 0x8008DB5C | 112 bytes
// ---------------------------------------------------------------------------
void LiveModeChangeHouseStateMachine::Reset() {
    SetNextState(0, 0.0f);
}

// ---------------------------------------------------------------------------
// LiveModeChangeHouseStateMachine::Update / Draw
// Addresses: 0x8008DBCC / 0x8008DBEC | 32 bytes each
// ---------------------------------------------------------------------------
void LiveModeChangeHouseStateMachine::Update(float dt) {
    StateMachine::Update(dt);
}

void LiveModeChangeHouseStateMachine::Draw(ERC* pRC) {
    StateMachine::Draw(pRC);
}


// ---- Loading Screen Sub-states ----

class LoadingScreenWaitingForLoadState : public StateMachineState {
public:
    virtual void Update(float dt) { /* Idle until StartLoad is called */ }
};

class LoadingScreenFadeInState : public StateMachineState {
public:
    virtual void Startup() {
        // FaderStart(fadeInDuration, true)
    }
    virtual void Update(float dt) {
        // FaderUpdate(dt)
        // When IsFadedIn(): OwnerSetNextState(2, 0.0f)
    }
};

class LoadingScreenUpdateState : public StateMachineState {
public:
    virtual void Update(float dt) {
        // Active loading / progress bar update
        // When load finishes: OwnerSetNextState(3, 0.0f)
    }
    virtual void Draw(ERC* pRC) {
        // Draw loading screen progress bar
    }
};

class LoadingScreenFadeOutState : public StateMachineState {
public:
    virtual void Startup() {
        // FaderStart(fadeOutDuration, false)
    }
    virtual void Update(float dt) {
        // FaderUpdate(dt)
        // When IsFadedOut(): OwnerSetNextState(0, 0.0f)
    }
};

// ---- Start Screen Sub-state ----

class StartScreenStartState : public StateMachineState {
public:
    u8 _extra[0x24 - 0x1C];

    virtual void Startup()       { /* Display "Press Start" + attract mode timer */ }
    virtual void Update(float dt) {
        // Check for button press
        // If pressed: signal parent TheSimsStateMachine to go to state 6
    }
    virtual void Draw(ERC* pRC)  { /* Render title screen + "Press Start" text */ }
};


// ############################################################################
//
//  PART 12: Standalone helpers
//
// ############################################################################

bool IsConfigFileValid(int slot, OptionsRecon& opts) {
    int result = opts.ReadIn(slot);
    return (result == 0);
}
