/**
 * eglobal_decomp.cpp - Decompiled EGlobal, ECheats, and OptionsRecon systems
 *
 * Sims 2 GameCube Decompilation
 *
 * EGlobal is the largest global state class in the game (0x654 bytes, 211 fields).
 * It holds the entire game's runtime state: player settings, debug flags, game options,
 * environmental state, resource handles, camera pointers, selected sims, cheat codes,
 * house data, UI string tables, and more.
 *
 * ECheats manages the cheat code system - a hash table (64-bucket) of cheat definitions
 * that can be enabled/disabled at runtime. Init() populates the table from EGlobal's
 * cheat sequence data.
 *
 * OptionsRecon handles save/load of player preferences (audio levels, screen adjustment,
 * controller config) via the Recon serialization system to memory card.
 *
 * Source addresses from: extracted/files/u2_ngc_release.map
 * Disassembly from: tools/disasm.py against extracted/files/u2_ngc_release_dvd.elf
 */

#include "types.h"

extern "C" void* memset(void* dst, int c, unsigned int n);

// Placement new operator (devkitPPC has no <new> header)
inline void* operator new(unsigned int, void* p) { return p; }

// External globals
class EGlobal;
extern EGlobal* g_pEGlobal;
extern int      g_bGodMode;

// Forward declarations
class AnimRef;
class BString2;
class CameraDirector;
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
class SpriteSlot;
class WallTile;
class cXObject;

// Stub complete types for new/delete
class Animator {
public:
    Animator() {}
    ~Animator() {}
};
class EOrPool {
public:
    EOrPool() {}
    ~EOrPool() {}
    static u32 Create(int a, int b, int c) { return 0; }
};
class SomeClass {
public:
    SomeClass() {}
    ~SomeClass() {}
};

// Stub definition needed for placement new
class StringBuffer2 {
public:
    StringBuffer2(wchar_t* buf, int capacity) {}
    static void Copy(void* dst, void* src) {}
};

// Stub for ReconBuffer serialization
class ReconBuffer {
public:
    void ReconBool(void* p) {}
    void ReconByte(void* p, int n) {}
    void ReconStringBuffer(void* p) {}
    void ReconU16(void* p, int n) {}
    void ReconS32(void* p) {}
    int  GetDirection() { return 0; }
};

// ResourceManager stubs
struct ResourceEntryValue { u32 value; };
struct ResourceManager {
    static u32  Load(int pool, u32 hash, int a, int b) { return 0; }
    static void Free(u32 handle) {}
    static ResourceEntryValue* FindEntry(u32 handle, const char* name) { return 0; }
};
enum { kFloorDataPool = 0, kSecondaryPool = 1, kSpecialPool = 2, kMainPool = 3, kFontPool = 4 };

// External globals needed in function bodies
class Player { public: u32 stateFlag; u32 field_234; };
class House   { public: u32 status; };
extern House*  g_pHouse;
extern Player* g_pPlayer1;
extern Player* g_pPlayer2;
extern u32     g_pStaticResource;
class cXPerson;

// ECheats forward declaration (defined later in file)
class ECheats;

// SetupSubstitutionStrings - stub for string table init (defined elsewhere)
static void SetupSubstitutionStrings() {}

// InLevelState global
extern u32 g_bNotInLevel;

// Audio stubs
class AudioPlayer {
public:
    AudioPlayer() {}
    void PlayByHash(u32 hash) {}
};
extern AudioPlayer* g_pAudioPlayer;
extern void*        g_pSoundEventManager;

// MemCardManager stubs
struct MemCardManager {
    static u32  CalcHash(int a, int b, int c, int d) { return 0; }
    static int  Write(void* buf, int size) { return 0; }
    static int  Read(void* buf, int size, int slot) { return 0; }
    void SignalWriteComplete() {}
    void SignalReadComplete() {}
};
extern MemCardManager* g_pMemCardManager;

// Memory::HandleNode stub
namespace Memory {
    struct HandleNode {};
}

// Recon serialization stubs
static Memory::HandleNode* ReconSaveObject(void* obj, int a, int b) { return 0; }
static void ReconLoadObject(void* obj, void* buf, int size, int a, void* b) {}

// Checksum stub
static u32 CalculateChecksum(void* buf, int size) { return 0; }

// EAHeap static alloc/free (thin wrappers around the heap accessor)
#include "core/eaheap.h"
namespace EAHeapStatic {
    static inline u8* Alloc(unsigned int size, int align, int a, int b) {
        return (u8*)MainHeap()->MallocAligned(size, align, 0, 0);
    }
    static inline void Free(void* ptr) {
        MainHeap()->Free(ptr);
    }
}

// Preserved prefs globals
extern int g_bPreferencesPreserved;
extern int g_bOnlinePrefsPreserved;

// ============================================================================
// SECTION 1: EGlobal - Complete Annotated Struct Layout (0x654 bytes)
// ============================================================================
//
// The struct is organized into several logical regions based on analysis of
// the constructor, SetDefaults, Reset, InitPlayerCheats, and accessor methods.
//
// Key insight: offsets 0x000-0x085 are a CHEAT SEQUENCE TABLE.
// InitPlayerCheats writes u16 values at offsets 0x002-0x084 in pairs,
// then computes per-player OR masks stored at 0x086-0x09B, with the
// combined all-player mask at 0x000. Each cheat is a sequence of
// button-press bitmasks.

class EGlobal {
public:
    // =====================================================================
    // CHEAT SEQUENCE TABLE (0x000 - 0x09F)
    // =====================================================================
    // InitPlayerCheats @ 0x8004246C fills this region.
    // 10 cheat sequences x 6 steps each = 60 entries of u16.
    // Each u16 is a controller button bitmask for one step in the sequence.
    //
    // Button bitmask values used (from InitPlayerCheats disasm):
    //   0x0002 = 2    (button A?)
    //   0x0004 = 4    (button B?)
    //   0x0008 = 8    (button X?)
    //   0x0010 = 16   (button Y?)
    //   0x0020 = 32   (D-pad up?)
    //   0x0040 = 64   (D-pad down?)
    //   0x0080 = 128  (D-pad left?)
    //   0x1000 = 4096 (L trigger?)
    //   0x2000 = 8192 (R trigger?)
    //   0x4000 = 16384 (Z button?)
    //   0x8000 = 32768 (Start?)
    //
    // After filling sequences, the code computes per-player cheat masks
    // at offsets 0x086+, and the combined mask at offset 0x000.

    u16 m_allPlayerCheatsMask;    // 0x000 - Combined OR of all cheat sequence bits
                                  //         GetAllPlayerCheatsMask returns this
                                  //         Renamed from m_newUIString (auto-name was wrong)
    // 0x001 is overlapping due to u16/u8 ambiguity in auto-analysis
    u16 m_cheatSeq_00[6];         // 0x002-0x00D - Cheat 0: sequence of 6 button masks
    u16 m_cheatSeq_01[6];         // 0x00E-0x019 - Cheat 1
    //   offset 0x010 = m_defaults: InitPlayerCheats writes it, SetDefaults reads
    //   offset 0x014 = m_defaults_014: same pattern
    u16 m_cheatSeq_02[6];         // 0x01A-0x025 - Cheat 2 (partially overlaps named fields)
    //   0x024 = m_houseLevelId (dual-purpose? InitPlayerCheats writes, GetHouseLevelId reads)
    u16 m_cheatSeq_03[6];         // 0x026-0x031 - Cheat 3
    //   0x028 = m_houseGrassShaderId
    u16 m_cheatSeq_04[6];         // 0x032-0x03D - Cheat 4
    u16 m_cheatSeq_05[6];         // 0x03E-0x049 - Cheat 5
    u16 m_cheatSeq_06[6];         // 0x04A-0x055 - Cheat 6
    u16 m_cheatSeq_07[6];         // 0x056-0x061 - Cheat 7
    u16 m_cheatSeq_08[6];         // 0x062-0x06D - Cheat 8
    //   0x064 = used by SelectNextInFamily/SelectPrevInFamily
    u16 m_cheatSeq_09[6];         // 0x06E-0x079 - Cheat 9
    //   0x078 = m_defaults_078

    // Per-player cheat OR masks (computed by InitPlayerCheats)
    // The loop at 0x800425C0 iterates player 0..9, each computing OR of their
    // 6-step sequence, storing result at 0x086 + playerIndex*2
    u16 m_playerCheatBitmask[10]; // 0x07A-0x08D (approximately)
    // Padding/alignment
    u8  _pad_086_09B[0x10];       // 0x08E-0x09D (gap, alignment)

    u16 m_activeCheatFlags;       // 0x09C - Current active cheat flags
                                  //         TogglePlayerCheat XORs bits here
                                  //         GetPlayerCheats returns this (or 0xFFFF if god mode)
                                  //         IsPlayerCheatOn tests individual bits
                                  //         GetPlayerCheatsMask(int) reads per-player mask

    u8  _pad_09E[2];              // 0x09E

    // =====================================================================
    // CORE STATE FIELDS (0x0A0 - 0x0FF)
    // =====================================================================

    u32 m_gameStateFlags;         // 0x0A0 - Game state flags (EGlobal ctor + SetDefaults)
                                  //         Constructor sets to 0
    f32 m_defaultFloat1;          // 0x0A4 - Default float value (SetDefaults loads from .rodata)
    f32 m_defaultFloat2;          // 0x0A8 - Default float value (SetDefaults loads from .rodata)
    u32 m_field_0AC;              // 0x0AC - Constructor zeroes
    u32 m_field_0B0;              // 0x0B0 - Constructor zeroes
    u32 m_resourceHandle_0B4;     // 0x0B4 - Resource handle (LoadIntroRequirements allocates)
                                  //         Reset frees and zeroes
    u16 m_field_0B6;              // 0x0B6 - CheckForZeroExtentOverride reads
    u8  m_field_0B8;              // 0x0B8 - Constructor zeroes
    u8  m_field_0B9;              // 0x0B9 - Constructor zeroes
    u8  _pad_0BA[2];              // 0x0BA

    // =====================================================================
    // PLAYER STATE (0x0BC - 0x0CF)
    // =====================================================================

    u32 m_selectedPerson[2];      // 0x0BC-0x0C3 - Selected person per player
                                  //   GetSelectedPerson(int index): return m_selectedPerson[index]
                                  //   At 0x8004079C: slwi r4,r4,2; addi r3,r3,0xBC; lwzx r3,r3,r4
                                  //   IsObjectInUseByPlayer checks these
                                  //   SetDefaults zeroes both
    u8  _pad_0C4[4];              // 0x0C4

    u32 m_pCurHouse;              // 0x0C8 - Current house pointer
                                  //   SetCurHouse stores here, ClearCurHouse zeroes
                                  //   AllocInstance, AllocPersonInstance read it
    u8  _pad_0CC[4];              // 0x0CC

    // =====================================================================
    // CAMERA & WINDOW SYSTEM (0x0D0 - 0x0E3)
    // =====================================================================

    ESimsCam* m_pCam;             // 0x0D0 - Camera pointer
                                  //   SetCam: stw r4,208(r3) -> this+0xD0
                                  //   GetCam: lwz r3,208(r3) -> return this+0xD0
                                  //   GetWin also reads 0xD0 (adds 0x10 offset for ERC)
                                  //   SelectWin reads 0xD0
                                  //   SetDefaults zeroes
                                  //   Reset zeroes
    u32 m_floorSet;               // 0x0D4 - Floor tile set pointer (GetFloorIndex reads)
    u32 m_wallSet;                // 0x0D8 - Wall tile set pointer (GetWallIndex reads)
    u32 m_fenceSet;               // 0x0DC - Fence data set pointer (GetFenceIndex reads)

    CameraDirector* m_pCameraDirector; // 0x0E0 - Camera director pointer
                                  //   SetCameraDirector: stw r4,224(r3)
                                  //   SetDefaults allocates if NULL

    // =====================================================================
    // RESOURCE HANDLES (0x0E4 - 0x0FF)
    // =====================================================================
    // These are handles to loaded game resources. LoadIntroRequirements
    // allocates them via hash-based resource loading (bl 0x80326cf8),
    // Reset frees them via bl 0x80311f70 (resource free).

    u32 m_pResourceModule;        // 0x0E4 - Resource module ptr
                                  //   LoadIntroRequirements allocates
                                  //   ConvertUnicodeToShiftJIS reads
    u32 m_pHouseLevelIdResource;  // 0x0E8 - House level ID resource
                                  //   GetGoalsLegendRow, GetHUDUIString, etc read
                                  //   Multiple UI string lookup functions use this
    u32 m_pResourceHandle_0EC;    // 0x0EC - Resource handle
                                  //   ConvertSpriteIdToResId reads
                                  //   SetDefaults allocates with hash 0x0C33DB41
    u32 m_pResourceHandle_0F0;    // 0x0F0 - Resource handle
                                  //   SetDefaults allocates with hash 0x19A16F2D
                                  //   Reset frees
    u32 m_pResourceHandle_0F4;    // 0x0F4 - Resource handle
                                  //   SetDefaults allocates with hash 0x0C33DB41
                                  //   Reset frees
    u32 m_pResourceHandle_0F8;    // 0x0F8 - Resource handle
                                  //   SetDefaults allocates with hash 0xC8C09E94
    u32 m_pResourceHandle_0FC;    // 0x0FC - Resource handle
                                  //   LoadIntroRequirements allocates with hash 0x1A18CA65

    // =====================================================================
    // DATA TABLE HANDLES (0x100 - 0x120)
    // =====================================================================

    u32 m_pResourceHandle_100;    // 0x100 - Resource handle
                                  //   SetDefaults allocates with hash 0xEA090184
    u32 m_pFontResource;          // 0x104 - Font resource handle
                                  //   LoadIntroRequirements allocates with GetGameFontID()
    u32 m_pResourceHandle_108;    // 0x108 - Resource handle
                                  //   SetDefaults allocates via CreateAnimator call chain
    u32 m_pAnimator;              // 0x10C - Animator object
                                  //   SetDefaults allocates (new(12) -> bl 0x80036ea0)
    u32 m_pResourceHandle_110;    // 0x110 - Resource handle
                                  //   SetDefaults allocates via EOrPool new
    u32 m_pCheatsObject;          // 0x114 - ECheats object pointer
                                  //   LoadPreGlobalRequirements allocates
                                  //   Reset calls Reset on it, then destructs
    u32 m_pResourceHandle_118_array[2]; // 0x118-0x11C - Set in constructor
    u32 m_pResourceHandle_120;    // 0x120 - Resource handle (SetDefaults allocates)
    u32 m_pResourceHandle_124;    // 0x124 - LoadIntroRequirements allocates
    u32 m_pResourceHandle_128;    // 0x128 - LoadIntroRequirements allocates
    u32 m_pResourceHandle_12C;    // 0x12C - LoadIntroRequirements allocates
    u32 m_pResourceHandle_130;    // 0x130 - LoadIntroRequirements allocates
    u32 m_pResourceHandle_134;    // 0x134 - LoadIntroRequirements allocates
    u32 m_pResourceHandle_138;    // 0x138 - Set in constructor
    u32 m_pResourceHandle_13C;    // 0x13C - LoadIntroRequirements allocates
    u32 m_pResourceHandle_140;    // 0x140 - LoadIntroRequirements allocates

    // =====================================================================
    // MORE RESOURCE HANDLES & GAME STATE (0x144 - 0x167)
    // =====================================================================

    u32 m_field_144;              // 0x144 - LoadIntroRequirements allocates
    u32 m_pResourceHandle_148;    // 0x148 - LoadIntroRequirements allocates, Reset frees
    u32 m_field_14C;              // 0x14C - Constructor zeroes
    u32 m_field_150;              // 0x150 - Constructor zeroes
    u32 m_field_154;              // 0x154 - Constructor zeroes
    u8  _pad_158[8];              // 0x158
    u32 m_nDefaultSimCount;       // 0x160 - SetDefaults sets to 2
    u8  _pad_164[4];              // 0x164

    // =====================================================================
    // INITIAL DATA BLOCK (0x168 - 0x1A7)
    // Constructor copies 22 bytes from .rodata at various offsets
    // =====================================================================

    u32 m_initData_168;           // 0x168 - Copied from .rodata 0x803D22AC
    u8  _pad_16C[0x1C];          // 0x16C
    u32 m_initData_188;           // 0x188 - Copied from .rodata 0x803D22C4
    u8  m_initData_18C;           // 0x18C - Copied from .rodata (byte)
    u8  _pad_18D[3];              // 0x18D
    u32 m_initData_190;           // 0x190 - Copied from .rodata 0x803D22CC
    u8  m_initData_194;           // 0x194 - Copied from .rodata (byte)
    u8  _pad_195[3];              // 0x195
    u32 m_initData_198;           // 0x198 - Copied from .rodata 0x803D22D4
    u8  _pad_19C[8];              // 0x19C
    u8  m_initData_1A4;           // 0x1A4 - Copied from .rodata (byte, 0x803D22DC)

    // =====================================================================
    // LARGE GAP (0x1A5 - 0x31F)
    // Likely arrays of game object data, instance slots, etc.
    // =====================================================================
    u8  _pad_1A5[0x17B];          // 0x1A5

    // =====================================================================
    // INSTANCE & CONFIG DATA (0x320 - 0x3AB)
    // =====================================================================

    u32 m_field_320;              // 0x320 - AllocInstance reads
    u32 m_initData_324;           // 0x324 - Copied from .rodata 0x803D22E0
    u8  m_initData_328;           // 0x328 - Copied from .rodata (byte)
    u8  _pad_329[3];              // 0x329
    u8  m_field_32C;              // 0x32C - Set to 0xFF in constructor
    u8  m_field_32D;              // 0x32D - Set to 0xFF in constructor

    u8  _pad_32E[2];              // 0x32E

    // =====================================================================
    // OBJECT STATE ARRAY (0x330 - 0x3AB)
    // Constructor zeroes all of these, then sets specific flags to 1.
    // Pattern: 32 consecutive u32 values suggesting an array of
    // per-object-type or per-slot state flags.
    // =====================================================================

    u32 m_objState[32];           // 0x330-0x3AF
    // Key initializations from constructor:
    //   m_objState[0x03] (0x33C) = 1   // slot/type 3 enabled
    //   m_objState[0x14] (0x380) = 1   // slot/type 20 enabled
    //   m_objState[0x16] (0x388) = 1   // slot/type 22 enabled
    //   m_objState[0x17] (0x38C) = 1   // slot/type 23 enabled
    //   All others = 0

    // =====================================================================
    // FLOAT PARAMETERS (0x3AC - 0x3B3)
    // =====================================================================

    f32 m_floatParam1;            // 0x3AC - Constructor loads from .rodata (0x803D22F0)
    f32 m_floatParam2;            // 0x3B0 - Constructor loads from .rodata (0x803D22F4)

    // =====================================================================
    // EXTENDED OBJECT STATE (0x3B4 - 0x40F)
    // Constructor zeroes all, then sets specific ones.
    // =====================================================================

    u32 m_extState[23];           // 0x3B4-0x40F
    // Constructor sets:
    //   0x3E4 = m_defaults_3E4: 1
    //   0x404 = 1 (but then immediately set to 0 -- constructor sets r10=1, stores,
    //              then r29=0 overwrites at 0x8003E4B0)

    // =====================================================================
    // AUTHOR MODE / GOD MODE FLAGS (0x3BC - 0x404)
    // SetAuthorModeCheats sets these fields to 1:
    //   0x3BC, 0x3C0, 0x3C8, 0x3DC, 0x3E8, 0x3F0, 0x404
    //   Plus 0x3E4 (from SetAuthorModeCheats: stw r0,996(r3))
    // SetGodMode (in ECheats) also sets many of these to 1:
    //   0x3D8, 0x3D0, 0x3C0, 0x3C8, 0x3CC, 0x3BC, 0x3F0, 0x3DC
    // These control debug/author-mode features like:
    //   - Free building
    //   - Unlimited money
    //   - All objects unlocked
    //   - Skip tutorials
    //   etc.
    // =====================================================================

    // Re-mapped as named cheat flags based on SetAuthorModeCheats and SetGodMode:
    // u32 m_cheatFlag_3BC;       // 0x3BC - Author+God: some unlock flag
    // u32 m_cheatFlag_3C0;       // 0x3C0 - Author+God: some unlock flag
    // u32 m_cheatFlag_3C4;       // 0x3C4
    // u32 m_cheatFlag_3C8;       // 0x3C8 - Author+God: some unlock flag
    // u32 m_cheatFlag_3CC;       // 0x3CC - God only
    // u32 m_cheatFlag_3D0;       // 0x3D0 - God only
    // u32 m_cheatFlag_3D4;       // 0x3D4
    // u32 m_cheatFlag_3D8;       // 0x3D8 - God only
    // u32 m_cheatFlag_3DC;       // 0x3DC - Author+God
    // u32 m_cheatFlag_3E0;       // 0x3E0
    // u32 m_cheatFlag_3E4;       // 0x3E4 - Author mode sets 996(r3) = 0x3E4
    // u32 m_cheatFlag_3E8;       // 0x3E8 - Author mode
    // u32 m_cheatFlag_3EC;       // 0x3EC
    // u32 m_cheatFlag_3F0;       // 0x3F0 - Author+God: 1008(r3) = 0x3F0
    // u32 m_cheatFlag_3F4;       // 0x3F4
    // u32 m_cheatFlag_3F8;       // 0x3F8
    // u32 m_cheatFlag_3FC;       // 0x3FC
    // u32 m_cheatFlag_400;       // 0x400 - Checked by GetPlayerCheats:
    //                            //   if (m_field_400 != 0) return 0xFFFF; (god mode)
    //                            //   else return m_activeCheatFlags;
    // u32 m_cheatFlag_404;       // 0x404 - Author mode sets 1028(r3)

    u32 m_godModeFlag;            // 0x400 - If nonzero, GetPlayerCheats returns 0xFFFF
                                  //         (all cheats active). This IS the god mode flag.
                                  //         At 0x80042338: lwz r0,1024(r3) == offset 0x400

    // =====================================================================
    // RESOURCE HANDLES (0x408 - 0x44F)
    // =====================================================================

    u32 m_initData_408;           // 0x408 - Copied from .rodata 0x803D22E8
    u32 m_initData_40C;           // 0x40C - Copied from .rodata 0x803D22E8+4
    u8  _pad_410[8];              // 0x410
    u32 m_pDefaultResource;       // 0x418 - SetDefaults checks and uses
    u32 m_field_41C;              // 0x41C
    u32 m_field_420;              // 0x420
    u32 m_field_424;              // 0x424
    u32 m_field_428;              // 0x428
    u32 m_field_42C;              // 0x42C
    u32 m_field_430;              // 0x430
    u32 m_field_434;              // 0x434 - Constructor sets r10=1 (0x8003E49C)
    u32 m_field_438;              // 0x438 - Constructor sets r10=1 (0x8003E4A0)
    u32 m_field_43C;              // 0x43C
    u32 m_field_440;              // 0x440
    u8  _pad_444[4];              // 0x444
    u32 m_field_448;              // 0x448
    u32 m_field_44C;              // 0x44C

    // =====================================================================
    // SAVE/LOAD FLAGS (0x450 - 0x45B)
    // =====================================================================

    u32 m_saveGameFlags1;         // 0x450 - SetDefaults sets to 2
                                  //         Reset sets to 2
    u32 m_saveGameFlags2;         // 0x454 - SetDefaults sets to 2
                                  //         Reset sets to 2
    u8  _pad_458[4];              // 0x458

    // =====================================================================
    // GAME MODE FLAGS (0x45C - 0x490+)
    // =====================================================================

    u32 m_nModeField_45C;         // 0x45C - Constructor stores r19 (9)
    u32 m_field_460;              // 0x460
    u32 m_field_464;              // 0x464
    u32 m_field_468;              // 0x468
    u32 m_field_46C;              // 0x46C
    u32 m_field_470;              // 0x470
    u32 m_field_474;              // 0x474
    u32 m_bListenForController;   // 0x478 - ListenForController returns this
                                  //         SetListenFlag stores bool here
    u8  _pad_47C[4];              // 0x47C
    u32 m_field_480;              // 0x480
    u32 m_field_484;              // 0x484
    u8  _pad_488[4];              // 0x488
    u32 m_field_48C;              // 0x48C
    u32 m_pLevelStateResource;    // 0x490 - LoadIntroRequirements allocates
                                  //         Reset frees

    u8  _pad_494[0x1BC];          // 0x494

    u32 m_defaults_650;           // 0x650 - SetDefaults sets (alignment tail)
    u32 m_compatFlag;             // extra field (accessed via g_pEGlobal->m_compatFlag)

    // Method declarations
    EGlobal();
    ~EGlobal();
    void SetDefaults();
    void Reset();
    void SetCam(ESimsCam* pCam);
    ESimsCam* GetCam();
    void SetCameraDirector(CameraDirector* pDir);
    ERC* GetWin();
    cXPerson* GetSelectedPerson(int playerIndex);
    void SetupScratchHeap();
    void FreeScratchHeap();
    void PlaceObjectInHouse(cXObject*);
    void PickUpInHouseObject(cXObject*);
    bool IsBuildHouseMode();
    bool ListenForController();
    AnimRef* GetSkillFromName(char*);
    PropRef* GetPropFromName(char*);
    char* GetNameFromProp(PropRef*);
    unsigned int GetGameFontID();
    void SetAuthorModeCheats();
    bool InLevelState();
    int GetFloorIndex(FloorTile* pTile);
    u16 GetPlayerCheats() const;
    bool IsPlayerCheatOn(int cheatIndex) const;
    void TogglePlayerCheat(int cheatIndex);
    void InitPlayerCheats();
    bool IsSaveGameEnabled();
};
// static_assert(sizeof(EGlobal) == 0x654);


// ============================================================================
// SECTION 2: EGlobal - Decompiled Functions
// ============================================================================

// ---------------------------------------------------------------------------
// EGlobal::~EGlobal - Destructor
// Address: 0x8003E1F0  Size: 40 bytes
// ---------------------------------------------------------------------------
// Trivial destructor that just conditionally frees memory.
// The r4 parameter is a destructor disposition flag (SN Systems ABI):
//   bit 0 = delete memory after destruction.
EGlobal::~EGlobal() {
    // if (disposition & 1) operator delete(this);
    // The destructor does NOT clean up any resources -- that's done in Reset().
}

// ---------------------------------------------------------------------------
// EGlobal::EGlobal - Constructor
// Address: 0x8003E218  Size: 800 bytes
// ---------------------------------------------------------------------------
// Massive constructor that:
// 1. Zeroes critical fields (m_pCam, m_selectedPerson, m_pCurHouse, etc.)
// 2. memset(this+0x168, 0, 736) -- clears the large data block
// 3. Copies initial data from several .rodata blocks
// 4. Sets object state flags (0x330-0x3AF region)
// 5. Sets float parameters from .rodata
// 6. Zeroes all resource handle pointers
// 7. Stores a global pointer (r13-21276 SDA) pointing to this EGlobal
EGlobal::EGlobal() {
    // r30 = this
    // r29 = 0 (used for zeroing)

    // Store global pointer: *(r13 - 24988) = &this[0x168]  -- SDA global ref
    // (The game stores a pointer to EGlobal in a global SDA variable)

    m_gameStateFlags = 0;             // 0x0A0
    m_pCam = NULL;                    // 0x0D0
    m_selectedPerson[0] = 0;          // 0x0BC
    m_selectedPerson[1] = 0;          // 0x0C0
    m_field_0B8 = 0;                  // 0x0B8
    m_field_0B9 = 0;                  // 0x0B9
    m_pCurHouse = 0;                  // 0x0C8
    m_pResourceModule = 0;            // 0x0E4
    m_pHouseLevelIdResource = 0;      // 0x0E8
    m_pResourceHandle_0F0 = 0;        // 0x0F0
    m_pResourceHandle_0FC = 0;        // 0x0FC
    m_pResourceHandle_100 = 0;        // 0x100
    m_pFontResource = 0;              // 0x104
    m_pResourceHandle_108 = 0;        // 0x108
    m_pAnimator = 0;                  // 0x10C
    m_pResourceHandle_110 = 0;        // 0x110
    m_pCheatsObject = 0;              // 0x114
    m_pResourceHandle_118_array[0] = 0;   // 0x118
    m_pResourceHandle_118_array[1] = 0;   // 0x11C
    m_pResourceHandle_120 = 0;        // 0x120
    m_field_48C = 0;                  // 0x48C
    m_activeCheatFlags = 0;           // 0x09C
    m_pResourceHandle_148 = 0;        // 0x148
    m_field_14C = 0;                  // 0x14C
    m_pResourceHandle_0F4 = 0;        // 0x0F4
    m_pResourceHandle_0EC = 0;        // 0x0EC
    m_pResourceHandle_0F8 = 0;        // 0x0F8

    // memset(this + 0x168, 0, 736)
    // This clears the large initial data block from 0x168 to ~0x448

    // Copy structured init data from .rodata sections:
    // Several blocks of 16-22 bytes are copied from read-only data
    // to populate m_initData_168, m_initData_188, etc.

    // Set object state flags:
    m_objState[0x03] = 1;  // 0x33C = 828(r30)
    m_objState[0x14] = 1;  // 0x380 = 896(r30)
    m_objState[0x16] = 1;  // 0x388 = 904(r30)
    m_objState[0x17] = 1;  // 0x38C = 908(r30)

    // Copy floats from .rodata:
    // m_floatParam1 = *(float*)0x803D22F0
    // m_floatParam2 = *(float*)0x803D22F4

    // Zero remaining fields
    // ... (continues for ~100 more field initializations)
}

// ---------------------------------------------------------------------------
// EGlobal::SetDefaults - Initialize default game state
// Address: 0x8003ECF4  Size: 984 bytes
// ---------------------------------------------------------------------------
// Called after construction to set up default resource handles.
// Loads resources by hash ID, creates helper objects (animator, EOrPool, etc).
void EGlobal::SetDefaults() {
    m_pCam = NULL;                    // 0x0D0
    m_gameStateFlags = 0;             // 0x0A0
    m_selectedPerson[0] = 0;          // 0x0BC
    m_selectedPerson[1] = 0;          // 0x0C0
    m_floorSet = 0;                   // 0x0D4
    m_wallSet = 0;                    // 0x0D8
    m_fenceSet = 0;                   // 0x0DC

    // Load default floats from .rodata
    m_defaultFloat1 = 0.0f; // TODO: actual value from .rodata
    m_defaultFloat2 = 0.0f; // TODO: actual value from .rodata

    // Zero stack local for resource loading
    m_pCurHouse = 0;                  // 0x0C8

    // Load resource: floor data (if not loaded)
    if (m_pResourceHandle_0F0 == 0) {
        m_pResourceHandle_0F0 = ResourceManager::Load(kFloorDataPool, 0x19A16F2D, 0, 0);
        // Then look up subtables for wall/floor/fence counts
        m_wallSet = ResourceManager::FindEntry(m_pResourceHandle_0F0, "walls")->value;
        m_floorSet = ResourceManager::FindEntry(m_pResourceHandle_0F0, "floors")->value;
        m_fenceSet = ResourceManager::FindEntry(m_pResourceHandle_0F0, "fences")->value;
    }

    // Load resource: secondary data (if not loaded)
    if (m_pResourceHandle_0EC == 0) {
        m_pResourceHandle_0EC = ResourceManager::Load(kSecondaryPool, 0x0C33DB41, 0, 0);
    }

    // Load resource: tertiary data
    if (m_pResourceHandle_0F4 == 0) {
        m_pResourceHandle_0F4 = ResourceManager::Load(kSecondaryPool, 0x0C33DB41, 0, 0);
    }

    // Load resource: quaternary data
    if (m_pResourceHandle_0F8 == 0) {
        m_pResourceHandle_0F8 = ResourceManager::Load(kSpecialPool, 0xC8C09E94, 0, 0);
    }

    // Load resource: main data table
    if (m_pResourceHandle_100 == 0) {
        m_pResourceHandle_100 = ResourceManager::Load(kMainPool, 0xEA090184, 0, 0);
    }

    // Load resource: font data (uses GetGameFontID)
    if (m_pResourceHandle_108 == 0) {
        u32 fontHash = GetGameFontID();
        m_pResourceHandle_108 = ResourceManager::Load(kFontPool, fontHash, 0, 0);
    }

    // Static global resource (SDA r13-32424)
    if (g_pStaticResource == NULL) {
        g_pStaticResource = ResourceManager::Load(kMainPool, 0x39B9B2BF, 0, 0);
    }

    // Create animator if needed
    if (m_pAnimator == 0) {
        m_pAnimator = (u32)(new Animator());
    }

    // Create EOrPool instances (2 slots at 0x118/0x11C)
    for (int i = 0; i < 2; i++) {
        if (m_pResourceHandle_118_array[i] == 0) {
            m_pResourceHandle_118_array[i] = EOrPool::Create(816, 16, 0);
        }
    }

    // Create resource handle 0x120
    if (m_pResourceHandle_120 == 0) {
        m_pResourceHandle_120 = (u32)(new SomeClass());
    }

    // Allocate EOrPool for main rendering + init
    m_pResourceHandle_110 = (u32)(new EOrPool());
    // ... additional setup calls ...

    m_nDefaultSimCount = 2;           // 0x160
    m_saveGameFlags1 = 2;             // 0x450
    m_saveGameFlags2 = 2;             // 0x454

    // Call SetupSubstitutionStrings, other init functions
    SetupSubstitutionStrings();

    // Allocate player state arrays if needed
    // ...
}

// ---------------------------------------------------------------------------
// EGlobal::Reset - Clean up all allocated resources
// Address: 0x8003F450  Size: 1168 bytes
// ---------------------------------------------------------------------------
// Frees all dynamically allocated resources, resets state to pre-init.
// Called during level transitions or game shutdown.
void EGlobal::Reset() {
    m_pCam = NULL;

    // Free each resource handle if allocated, then NULL it
    if (m_pResourceModule)       { ResourceManager::Free(m_pResourceModule);       m_pResourceModule = 0; }
    if (m_pHouseLevelIdResource) { ResourceManager::Free(m_pHouseLevelIdResource); m_pHouseLevelIdResource = 0; }
    if (m_pResourceHandle_0F0)   { ResourceManager::Free(m_pResourceHandle_0F0);   m_pResourceHandle_0F0 = 0; }
    if (m_pResourceHandle_0EC)   { ResourceManager::Free(m_pResourceHandle_0EC);   m_pResourceHandle_0EC = 0; }
    if (m_pResourceHandle_0F4)   { ResourceManager::Free(m_pResourceHandle_0F4);   m_pResourceHandle_0F4 = 0; }
    if (m_pResourceHandle_0FC)   { ResourceManager::Free(m_pResourceHandle_0FC);   m_pResourceHandle_0FC = 0; }
    if (m_pResourceHandle_100)   { ResourceManager::Free(m_pResourceHandle_100);   m_pResourceHandle_100 = 0; }
    if (m_pFontResource)         { ResourceManager::Free(m_pFontResource);         m_pFontResource = 0; }
    if (m_pResourceHandle_108)   { ResourceManager::Free(m_pResourceHandle_108);   m_pResourceHandle_108 = 0; }

    // Remove specific resource from resource pool by hash
    // ResourcePool::Remove(kPool, 0x5012E600)
    // if found, ResourcePool::Delete(kPool, 0x5012E600, true)

    // Free static global resource
    if (g_pStaticResource) {
        ResourceManager::Free(g_pStaticResource);
        g_pStaticResource = NULL;
    }

    // Reset and destroy cheats
    // NOTE: ECheats::Reset/dtor called via function pointer to avoid incomplete-type error
    // at this point in the TU. The actual ECheats class is defined in SECTION 4 below.
    if (m_pCheatsObject) {
        operator delete((void*)(u32)m_pCheatsObject);
        m_pCheatsObject = 0;
    }

    // Clean up EOrPool (m_pResourceHandle_110)
    if (m_pResourceHandle_110) {
        // Check and remove entries for slot 0 and slot 1
        // Then destroy the pool
        m_pResourceHandle_110 = 0;
    }

    // Free current house
    if (m_pCurHouse) {
        // Destroy via virtual destructor
        m_pCurHouse = 0;
    }

    // Free animator
    if (m_pAnimator) {
        // Destroy
        m_pAnimator = 0;
    }

    // Free m_pResourceHandle_148
    if (m_pResourceHandle_148) {
        operator delete(m_pResourceHandle_148);
    }
    m_pResourceHandle_148 = 0;

    // Free EOrPool array (0x118-0x11C)
    for (int i = 0; i < 2; i++) {
        if (m_pResourceHandle_118_array[i]) {
            // Destroy
        }
        m_pResourceHandle_118_array[i] = 0;
    }

    // Free m_pResourceHandle_120
    if (m_pResourceHandle_120) {
        // Destroy
        m_pResourceHandle_120 = 0;
    }

    // Free level state resource
    if (m_pLevelStateResource) {
        // Destroy
        m_pLevelStateResource = 0;
    }

    // Zero counters
    m_saveGameFlags1 = 0;
    m_saveGameFlags2 = 0;

    // Destroy objects at 0x140, 0x13C, 0x134, 0x130, 0x128, 0x124, 0x12C
    // Each follows: if(ptr) { vtable_destroy(ptr, 3); ptr = 0; }
    // These are virtual destructor calls via vtable offsets

    // Additional cleanup calls
    // ... (font system reset, rendering cleanup, etc.)

    // Free m_resourceHandle_0B4
    if (m_resourceHandle_0B4) {
        // Destroy
        m_resourceHandle_0B4 = 0;
    }
}

// ---------------------------------------------------------------------------
// EGlobal::SetCam / GetCam - Camera accessors
// Address: 0x8003FA14 / 0x8003FA1C  Size: 8 bytes each
// ---------------------------------------------------------------------------
void EGlobal::SetCam(ESimsCam* pCam) {
    m_pCam = pCam;  // stw r4,208(r3) -> offset 0xD0
}

ESimsCam* EGlobal::GetCam() {
    return m_pCam;  // lwz r3,208(r3) -> offset 0xD0
}

// ---------------------------------------------------------------------------
// EGlobal::SetCameraDirector - Camera director setter
// Address: 0x8003FA24  Size: 8 bytes
// ---------------------------------------------------------------------------
void EGlobal::SetCameraDirector(CameraDirector* pDir) {
    m_pCameraDirector = pDir;  // stw r4,224(r3) -> offset 0xE0
}

// ---------------------------------------------------------------------------
// EGlobal::GetWin - Get window/ERC from camera
// Address: 0x8003F9FC  Size: 24 bytes
// ---------------------------------------------------------------------------
// Returns the ERC (render context) associated with the camera.
// The ERC sits at offset +0x10 from the camera pointer.
ERC* EGlobal::GetWin() {
    if (m_pCam != NULL) {
        return (ERC*)((char*)m_pCam + 0x10);
    }
    return NULL;
}

// ---------------------------------------------------------------------------
// EGlobal::GetSelectedPerson - Get selected sim for a player
// Address: 0x8004079C  Size: 16 bytes
// ---------------------------------------------------------------------------
// Returns the cXPerson pointer for the given player index.
// Array at offset 0xBC, 4 bytes per entry.
cXPerson* EGlobal::GetSelectedPerson(int playerIndex) {
    return (cXPerson*)m_selectedPerson[playerIndex];
}

// ---------------------------------------------------------------------------
// EGlobal::SetupScratchHeap / FreeScratchHeap - No-ops
// Address: 0x8003F0CC / 0x8003F0D0  Size: 4 bytes each
// ---------------------------------------------------------------------------
// These are empty stubs on GameCube -- scratch heap is handled differently.
void EGlobal::SetupScratchHeap() { }
void EGlobal::FreeScratchHeap() { }

// ---------------------------------------------------------------------------
// EGlobal::PlaceObjectInHouse / PickUpInHouseObject - No-ops
// Address: 0x80041214 / 0x80041218  Size: 4 bytes each
// ---------------------------------------------------------------------------
// Empty stubs -- object placement handled elsewhere on GC.
void EGlobal::PlaceObjectInHouse(cXObject*) { }
void EGlobal::PickUpInHouseObject(cXObject*) { }

// ---------------------------------------------------------------------------
// EGlobal::IsBuildHouseMode - Always returns false
// Address: 0x800420AC  Size: 8 bytes
// ---------------------------------------------------------------------------
// Build mode flag -- hardcoded to false on GameCube (no build mode).
bool EGlobal::IsBuildHouseMode() {
    return false;
}

// ---------------------------------------------------------------------------
// EGlobal::ListenForController - Returns listen flag
// Address: 0x80042194  Size: 8 bytes
// ---------------------------------------------------------------------------
bool EGlobal::ListenForController() {
    return m_bListenForController;  // offset 0x478
}

// ---------------------------------------------------------------------------
// EGlobal::GetSkillFromName / GetPropFromName / GetNameFromProp - Stub returns
// Address: 0x8004219C / 0x8004227C / 0x80042284  Size: 8 bytes each
// ---------------------------------------------------------------------------
// These return NULL/0 -- skill/prop lookup not used on GC.
AnimRef* EGlobal::GetSkillFromName(char*) { return NULL; }
PropRef* EGlobal::GetPropFromName(char*) { return NULL; }
char* EGlobal::GetNameFromProp(PropRef*) { return NULL; }

// ---------------------------------------------------------------------------
// EGlobal::GetGameFontID - Returns font resource hash
// Address: 0x8003E5B4  Size: 12 bytes
// ---------------------------------------------------------------------------
// Returns a constant hash ID for the game font resource.
unsigned int EGlobal::GetGameFontID() {
    return 0x67F664FB;
}

// ---------------------------------------------------------------------------
// EGlobal::SetAuthorModeCheats - Enable author/debug mode
// Address: 0x8003E538  Size: 40 bytes
// ---------------------------------------------------------------------------
// Enables a set of cheat flags for author/development mode.
// Sets 8 flag fields to 1, unlocking debug features.
void EGlobal::SetAuthorModeCheats() {
    // All offsets relative to 'this' (r3):
    // stw 1, 996(r3)  = 0x3E4
    // stw 1, 956(r3)  = 0x3BC
    // stw 1, 960(r3)  = 0x3C0
    // stw 1, 968(r3)  = 0x3C8
    // stw 1, 988(r3)  = 0x3DC
    // stw 1, 1000(r3) = 0x3E8
    // stw 1, 1008(r3) = 0x3F0
    // stw 1, 1028(r3) = 0x404

    *(u32*)((char*)this + 0x3E4) = 1;  // Unknown author flag
    *(u32*)((char*)this + 0x3BC) = 1;  // Cheat: unlock flag 1
    *(u32*)((char*)this + 0x3C0) = 1;  // Cheat: unlock flag 2
    *(u32*)((char*)this + 0x3C8) = 1;  // Cheat: unlock flag 3
    *(u32*)((char*)this + 0x3DC) = 1;  // Cheat: unlock flag 4
    *(u32*)((char*)this + 0x3E8) = 1;  // Cheat: unlock flag 5
    *(u32*)((char*)this + 0x3F0) = 1;  // Cheat: unlock flag 6
    *(u32*)((char*)this + 0x404) = 1;  // Cheat: unlock flag 7
}

// ---------------------------------------------------------------------------
// EGlobal::InLevelState - Check if game is in a level
// Address: 0x80042320  Size: 24 bytes
// ---------------------------------------------------------------------------
// Checks a global state variable. Returns true when the game is actively
// in a level (as opposed to menus, loading screens, etc).
bool EGlobal::InLevelState() {
    // SDA global at r13-24172 offset resolves to a static variable
    // lis r9,-32697; lwz r3,24172(r9)
    // This reads a global: g_bNotInLevel
    // Then XOR with 1 and normalize to bool (subfic + adde pattern)
    u32 notInLevel = g_bNotInLevel;  // global static
    return (notInLevel == 0);        // true if we ARE in a level
}

// ---------------------------------------------------------------------------
// EGlobal::GetFloorIndex / GetWallIndex / GetFenceIndex
// Addresses: 0x800406C4 / 0x8004070C / 0x80040754  Size: 72 bytes each
// ---------------------------------------------------------------------------
// Linear search through a tile/fence set array to find the index of a given tile.
// Returns the index, or 0 if not found.
int EGlobal::GetFloorIndex(FloorTile* pTile) {
    u32* pArray = *(u32**)(&m_floorSet);  // Dereference pointer at offset 0xD4
    int count = 0;
    if (pArray != NULL) {
        count = *((int*)pArray - 1);  // Count stored at array[-1]
    }
    for (int i = 0; i < count; i++) {
        if (pArray[i] == (u32)pTile) {
            return i;
        }
    }
    return 0;
}

// GetWallIndex and GetFenceIndex are structurally identical, just reading
// from offset 0xD8 and 0xDC respectively.

// ---------------------------------------------------------------------------
// EGlobal::GetPlayerCheats - Get active cheat bitmask
// Address: 0x80042338  Size: 32 bytes
// ---------------------------------------------------------------------------
// Returns the current cheat flags. If god mode is active, returns 0xFFFF
// (all cheats enabled).
u16 EGlobal::GetPlayerCheats() const {
    if (m_godModeFlag != 0) {       // lwz r0,1024(r3) = offset 0x400
        return 0xFFFF;              // All cheats active in god mode
    }
    return m_activeCheatFlags;      // lhz r3,156(r3) = offset 0x09C
}

// ---------------------------------------------------------------------------
// EGlobal::IsPlayerCheatOn - Test if a specific cheat is active
// Address: 0x80042358  Size: 48 bytes
// ---------------------------------------------------------------------------
// Checks if cheat number 'cheatIndex' is currently toggled on.
// In god mode, always returns true.
bool EGlobal::IsPlayerCheatOn(int cheatIndex) const {
    if (m_godModeFlag != 0) {       // offset 0x400
        return true;                // All cheats on in god mode
    }
    u16 flags = m_activeCheatFlags; // offset 0x09C
    return ((flags >> cheatIndex) & 1) != 0;
}

// ---------------------------------------------------------------------------
// EGlobal::TogglePlayerCheat - Toggle a cheat on/off
// Address: 0x80042388  Size: 228 bytes
// ---------------------------------------------------------------------------
// Toggles the given cheat index. Special case for cheat 10 which triggers
// a special effect (sound/visual feedback via hash-based lookup).
// For other cheats, XORs the bit in m_activeCheatFlags and plays a
// "cheat enabled" or "cheat disabled" sound.
void EGlobal::TogglePlayerCheat(int cheatIndex) {
    if (cheatIndex == 10) {
        // Special cheat #10: create/get audio player and play hash 0x3EA0941F
        if (g_pAudioPlayer == NULL) {
            g_pAudioPlayer = new AudioPlayer();
        }
        g_pAudioPlayer->PlayByHash(0x3EA0941F);
        return;
    }

    // Toggle the cheat bit
    m_activeCheatFlags ^= (1 << cheatIndex);  // XOR at offset 0x09C

    // Check if we should play feedback sound
    bool isNowOn = IsPlayerCheatOn(cheatIndex);
    if (g_pSoundEventManager == NULL) {
        return;  // No sound system available
    }

    if (isNowOn) {
        // Play "cheat enabled" sound
        if (g_pAudioPlayer == NULL) {
            g_pAudioPlayer = new AudioPlayer();
        }
        g_pAudioPlayer->PlayByHash(0xCE619E32);  // "cheat on" jingle
    } else {
        // Play "cheat disabled" sound
        if (g_pAudioPlayer == NULL) {
            g_pAudioPlayer = new AudioPlayer();
        }
        g_pAudioPlayer->PlayByHash(0x1C99B71C);  // "cheat off" jingle
    }
}

// ---------------------------------------------------------------------------
// EGlobal::InitPlayerCheats - Initialize cheat code sequences
// Address: 0x8004246C  Size: 424 bytes
// ---------------------------------------------------------------------------
// Fills the cheat sequence table (offsets 0x002-0x084) with button sequences
// for 10 cheats, each 6 steps long. Then computes per-player OR masks.
//
// Cheat table layout (u16 values, button bitmasks):
//   Cheat 0 (0x002): 4, 8, 4096, 64, 2, 0          = B,X,L,Down,A,...
//   Cheat 1 (0x00E): 8, 4, 2, 8192, 0x8000, 0      = X,B,A,R,Start,...
//   Cheat 2 (0x01A): 4096, 32, 4096, 8192, 2, 0     = L,Up,L,R,A,...
//   Cheat 3 (0x026): 32, 0x4000, 0x8000, 4096, 0, 32 = Up,Z,Start,L,...
//   Cheat 4 (0x032): 128, 0, 32, 128, 4, 4096       = Left,...
//   Cheat 5 (0x03E): 0x4000, 8192, 0, 2, 8, 0x4000  = Z,R,...
//   Cheat 6 (0x04A): 8192, 0x4000, 8192, 0x4000, 8192, 0 = R,Z,R,Z,R,...
//   Cheat 7 (0x056): 0, 8, 4, 128, 2, 0x8000        = ..X,B,Left,A,Start
//   Cheat 8 (0x062): 2, 0x4000, 8192, 0x8000, 4096, 0x4000 =...
//   Cheat 9 (0x06E): 16, 0, 0x4000, 128, 0, 32      = Y,...,Z,Left,...
//
// After filling, computes per-player masks by OR'ing all 6 steps for each cheat.
// Then ORs all player masks into m_allPlayerCheatsMask at offset 0x000.
void EGlobal::InitPlayerCheats() {
    // Fill cheat sequences (60 half-word stores)
    // ... (see disassembly above for exact values)

    // Compute per-player masks
    u16 combined = 0;
    for (int player = 0; player < 10; player++) {
        u16 mask = 0;
        u16* seq = &m_cheatSeq_00[0] + player * 6;
        for (int step = 0; step < 6; step++) {
            mask |= seq[step];
        }
        m_playerCheatBitmask[player] = mask;
        combined |= mask;
    }
    m_allPlayerCheatsMask = combined;
}

// ---------------------------------------------------------------------------
// EGlobal::IsSaveGameEnabled - Check if save is allowed
// Address: 0x80042718  Size: 144 bytes
// ---------------------------------------------------------------------------
// Multi-condition check for whether saving is currently allowed.
// Checks: level state, house loaded status, multiplayer state.
bool EGlobal::IsSaveGameEnabled() {
    // Check 1: Are we in a valid house?
    // lis r9,-32697; lwz r11,23496(r9) -> global house ptr
    // lhz r0,200(r11) -> house status field
    bool houseLoaded = (g_pHouse->status != 0);

    if (!houseLoaded) {
        // Check player 1 state
        // lis r9,-32697; lwz r9,24292(r9) -> player 1 state
        // lwz r0,352(r9) -> some state flag
        if (g_pPlayer1->stateFlag == 1) {
            if (g_pPlayer1->field_234 == 0) {
                return true;  // Save allowed for player 1
            }
        }
    } else {
        return false;  // House not loaded, can't save
    }

    // Check multiplayer: is player 2 present?
    if (g_pPlayer2 == NULL) {
        return false;
    }

    // Repeat similar check for player 2
    if (g_pPlayer2->stateFlag == 1) {
        if (g_pPlayer2->field_234 != 0) {
            return false;
        }
    }
    return true;
}


// ============================================================================
// SECTION 3: ECheats - Cheat Code Hash Table System
// ============================================================================
//
// ECheats manages a 64-bucket hash table of cheat code definitions.
// The hash table maps cheat sequences to their effects.
//
// Struct layout (0x10C bytes):
//   0x000-0x0FF: Hash table buckets (64 x u32 = 256 bytes)
//                Each bucket is a pointer to a linked list of cheat entries
//   0x100:       Active cheat count / lookup list head
//   0x104:       Flags (set to 0 in constructor)
//   0x108:       Init status flag (set by Init)

class ECheats {
public:
    u32 m_hashBuckets[64];   // 0x000 - 64-bucket hash table for cheat lookups
    u32 m_lookupCount;       // 0x100 - Number of active cheat entries
    u32 m_flags;             // 0x104 - Runtime flags (0 = not initialized)
    u32 m_initStatus;        // 0x108 - Set during Init

    // ---- Methods ----

    // Constructor: zeroes entire hash table, calls EmptyLookupList, sets m_flags=0
    ECheats();

    // Destructor: calls DisableCheats, EmptyLookupList, then frees all hash chains
    ~ECheats();

    // Init: Populates hash table from EGlobal's cheat sequence data (7824 bytes!)
    // This is the largest ECheats function -- it maps button sequences to effects.
    void Init(EGlobal& global);

    // Reset: calls WriteCheatsFile (no-op on GC), then EmptyLookupList
    void Reset();

    // EmptyLookupList: iterates all 64 buckets, frees linked list nodes, zeroes m_lookupCount
    void EmptyLookupList();

    // ReadCheatsFile: allocates stack frame (736 bytes), sets m_flags to 1
    // On GC this is a stub -- no filesystem cheat loading
    void ReadCheatsFile();

    // WriteCheatsFile: empty stub (no-op)
    void WriteCheatsFile();

    // Update: empty stub (no-op)
    void Update();

    // SetGodMode: if true, sets 8 EGlobal cheat flags to 1 (via SDA global pointer)
    //             if false, sets a global flag to 0
    void SetGodMode(bool enable);

    // EnableCheats: iterates hash table, creates audio event callbacks for each
    //               active cheat entry. Attaches them to the global event system.
    void EnableCheats();

    // DisableCheats: iterates hash table, removes audio event callbacks and frees them.
    void DisableCheats();
};

// ---------------------------------------------------------------------------
// ECheats::ECheats - Constructor
// Address: 0x8001ECAC  Size: 72 bytes
// ---------------------------------------------------------------------------
ECheats::ECheats() {
    memset(this, 0, 256);       // Zero hash table (64 * 4 = 256 bytes)
    EmptyLookupList();          // Reset lookup list
    m_flags = 0;                // offset 0x104
}

// ---------------------------------------------------------------------------
// ECheats::~ECheats - Destructor
// Address: 0x8001ECF4  Size: 136 bytes
// ---------------------------------------------------------------------------
// Disables all cheat callbacks, empties the lookup list, then walks all
// 64 hash buckets freeing each linked list chain.
ECheats::~ECheats() {
    DisableCheats();
    EmptyLookupList();

    // Walk all 64 buckets and free linked list nodes
    for (int i = 0; i < 64; i++) {
        u32* pEntry = (u32*)m_hashBuckets[i];
        while (pEntry != NULL) {
            m_hashBuckets[i] = 0;
            u32* pNext;
            while (pEntry) {
                pNext = *(u32**)pEntry;  // linked list next pointer
                operator delete(pEntry);
                pEntry = pNext;
            }
        }
    }

    // if (disposition & 1) operator delete(this);
}

// ---------------------------------------------------------------------------
// ECheats::Reset - Reset cheat state
// Address: 0x80020C0C  Size: 52 bytes
// ---------------------------------------------------------------------------
void ECheats::Reset() {
    WriteCheatsFile();    // No-op on GC
    EmptyLookupList();    // Clear all entries
}

// ---------------------------------------------------------------------------
// ECheats::EmptyLookupList - Free all cheat lookup entries
// Address: 0x80020C40  Size: 112 bytes
// ---------------------------------------------------------------------------
void ECheats::EmptyLookupList() {
    for (int i = 0; i < 64; i++) {
        u32* pEntry = (u32*)m_hashBuckets[i];
        while (pEntry != NULL) {
            m_hashBuckets[i] = 0;
            u32* pNext;
            do {
                pNext = *(u32**)pEntry;
                operator delete(pEntry);
                pEntry = pNext;
            } while (pEntry != NULL);
        }
    }
    m_lookupCount = 0;  // offset 0x100
}

// ---------------------------------------------------------------------------
// ECheats::ReadCheatsFile - Stub for reading cheats from file
// Address: 0x80020CB0  Size: 20 bytes
// ---------------------------------------------------------------------------
// On GameCube, this just sets a flag. No actual file I/O.
void ECheats::ReadCheatsFile() {
    // stwu r1,-736(r1) -- large stack frame (never used)
    m_flags = 1;  // offset 0x104 -- mark as "file read"
}

// ---------------------------------------------------------------------------
// ECheats::WriteCheatsFile / Update - Empty stubs
// Addresses: 0x80020D08 / 0x80020D0C  Size: 4 bytes each
// ---------------------------------------------------------------------------
void ECheats::WriteCheatsFile() { }
void ECheats::Update() { }

// ---------------------------------------------------------------------------
// ECheats::SetGodMode - Enable/disable god mode
// Address: 0x80020CC4  Size: 68 bytes
// ---------------------------------------------------------------------------
// When enabling god mode, sets 8 EGlobal cheat flags to 1 via the SDA
// global pointer to EGlobal. When disabling, clears a different global.
void ECheats::SetGodMode(bool enable) {
    if (enable) {
        // lis r9,-32697; addi r9,r9,24012 -> SDA pointer to EGlobal fields
        // These are EGlobal offsets (base + field):
        //   stw 1, 984(r9)  = 0x3D8  (EGlobal cheat flag)
        //   stw 1, 976(r9)  = 0x3D0
        //   stw 1, 960(r9)  = 0x3C0
        //   stw 1, 968(r9)  = 0x3C8
        //   stw 1, 972(r9)  = 0x3CC
        //   stw 1, 956(r9)  = 0x3BC
        //   stw 1, 1008(r9) = 0x3F0
        //   stw 1, 988(r9)  = 0x3DC
        EGlobal* pGlobal = g_pEGlobal;
        *(u32*)((char*)pGlobal + 0x3D8) = 1;
        *(u32*)((char*)pGlobal + 0x3D0) = 1;
        *(u32*)((char*)pGlobal + 0x3C0) = 1;
        *(u32*)((char*)pGlobal + 0x3C8) = 1;
        *(u32*)((char*)pGlobal + 0x3CC) = 1;
        *(u32*)((char*)pGlobal + 0x3BC) = 1;
        *(u32*)((char*)pGlobal + 0x3F0) = 1;
        *(u32*)((char*)pGlobal + 0x3DC) = 1;
    } else {
        // lis r9,-32697; stw r4,25032(r9)
        // Stores 0 (false was passed in r4) to a global flag
        g_bGodMode = 0;
    }
}

// ---------------------------------------------------------------------------
// ECheats::EnableCheats - Activate all registered cheat callbacks
// Address: 0x80020D10  Size: 504 bytes
// ---------------------------------------------------------------------------
// Walks the hash table. For each cheat entry that has an associated action
// (field at entry+0x54), creates an AudioEventCallback, registers it with
// the global event system, and links it to the entry.
void ECheats::EnableCheats() {
    // Uses a hash table iterator pattern:
    //   - Start at bucket 0
    //   - Walk linked list in each bucket
    //   - For each entry with a non-null action (offset 0x54):
    //     1. Allocate 16-byte AudioEventCallback
    //     2. Initialize it
    //     3. Store back-pointer to cheat entry at callback+0x0C
    //     4. Store callback source ptr at callback+0x08
    //     5. Store callback in entry at offset 0x5C
    //     6. Register callback with global audio event manager
    //   - Continue until all buckets exhausted
}

// ---------------------------------------------------------------------------
// ECheats::DisableCheats - Deactivate all cheat callbacks
// Address: 0x80020F08  Size: 476 bytes
// ---------------------------------------------------------------------------
// Reverse of EnableCheats: walks hash table, removes and frees each
// AudioEventCallback attached to cheat entries.
void ECheats::DisableCheats() {
    // Same hash table iteration as EnableCheats, but:
    //   - For each entry with action at offset 0x54:
    //     1. Unregister callback from global event manager
    //     2. Free the callback object at entry+0x5C
    //     3. Set entry+0x5C = NULL
}


// ============================================================================
// SECTION 4: OptionsRecon - Settings Save/Load System
// ============================================================================
//
// OptionsRecon handles serialization of player preferences to memory card.
// It uses EA's Recon serialization system (ReconBuffer stream interface).
//
// Struct layout (0xF4 bytes / 244 bytes):
//   0x000: m_bMusicEnabled    (u32) - Music on/off
//   0x004: m_bSFXEnabled      (u32) - Sound effects on/off
//   0x008: m_bVoiceEnabled    (u32) - Voice/dialog on/off
//   0x00C: m_field_00C        (u32) - Unknown (set to 0 in defaults)
//   0x010: m_bVibrationEnabled (u32) - Controller rumble on/off
//   0x014: m_bAutoSaveEnabled (u32) - Auto-save on/off (default 1)
//   0x018: m_field_018        (u32) - Unknown (set to 0 in defaults)
//   0x01C: m_musicVolume      (u8)  - Music volume (0-10, default 10)
//                                     DoStream clamps to 10 on load
//   0x01D: m_sfxVolume        (u8)  - SFX volume (0-10, default 10)
//                                     DoStream clamps to 10 on load
//   0x01E: m_voiceVolume      (u8)  - Voice volume (0-10, default 10)
//                                     DoStream clamps to 10 on load
//   0x01F: m_screenAdjustX    (u8)  - Screen X offset (-25 to +25, default 0)
//   0x020: m_screenAdjustY    (u8)  - Screen Y offset (-25 to +25, default 0)
//   0x024: m_field_024        (u32) - Unknown (set to 0 in defaults)
//   0x028: m_brightnessLevel  (u8)  - Brightness (0-10, default 10)
//                                     DoStream clamps to 10 on load
//   0x029: m_contrastLevel    (u8)  - Contrast (0-10, default 10)
//                                     DoStream clamps to 10 on load
//   0x02C-0x04F: PRESERVED PREFERENCES SHADOW COPY
//     PreservePreferences copies fields 0x000-0x029 into 0x02C-0x04E
//     RestorePreferences copies them back
//   0x050: m_onlinePrefsBackup (u32) - PreservePrefsForOnline saves m_bVibrationEnabled here
//   0x054: m_field_054         (u8)  - Streamed as 1-byte (version or flag, DoStream)
//                                      ResetToDefaults sets to 0xFF
//   0x058-0x097: m_playerName1 (StringBuffer2, 72 bytes) - Player 1 name
//                StringBuffer2(wchar_t* buf, u32 capacity) at offset 0x58
//                Internal buffer at 0x60, capacity 32 wchars
//   0x0A0-0x0DF: m_playerName2 (StringBuffer2, 72 bytes) - Player 2 name
//                StringBuffer2(wchar_t* buf, u32 capacity) at offset 0xA0
//                Internal buffer at 0xA8, capacity 32 wchars
//   0x0E8: m_field_0E8        (u32) - Streamed as u16 (DoStream)
//   0x0EC: m_field_0EC        (u32) - Streamed as s32 (DoStream)
//   0x0F0: m_field_0F0        (u32) - Streamed as s32 (DoStream)
//
// All defaults set to 0 except:
//   m_bMusicEnabled = 1, m_bSFXEnabled = 1, m_bVoiceEnabled = 1
//   m_bAutoSaveEnabled = 1, m_musicVolume = 10, m_sfxVolume = 10
//   m_voiceVolume = 10, m_brightnessLevel = 10, m_contrastLevel = 10
//   m_field_054 = 0xFF

class OptionsRecon {
public:
    u32 m_bMusicEnabled;         // 0x000
    u32 m_bSFXEnabled;           // 0x004
    u32 m_bVoiceEnabled;         // 0x008
    u32 m_field_00C;             // 0x00C
    u32 m_bVibrationEnabled;     // 0x010
    u32 m_bAutoSaveEnabled;      // 0x014
    u32 m_field_018;             // 0x018
    u8  m_musicVolume;           // 0x01C
    u8  m_sfxVolume;             // 0x01D
    u8  m_voiceVolume;           // 0x01E
    u8  m_screenAdjustX;         // 0x01F
    u8  m_screenAdjustY;         // 0x020
    u8  _pad_021[3];
    u32 m_field_024;             // 0x024
    u8  m_brightnessLevel;       // 0x028
    u8  m_contrastLevel;         // 0x029
    u8  _pad_02A[2];

    // Shadow copy for PreservePreferences/RestorePreferences
    u32 m_saved_bMusicEnabled;   // 0x02C
    u32 m_saved_bSFXEnabled;     // 0x030
    u32 m_saved_bVoiceEnabled;   // 0x034
    u32 m_saved_bVibrationEnabled; // 0x038
    u32 m_saved_bAutoSaveEnabled;  // 0x03C
    u32 m_saved_field_018;       // 0x040
    u32 m_saved_field_024;       // 0x044
    u8  m_saved_musicVolume;     // 0x048
    u8  m_saved_sfxVolume;       // 0x049
    u8  m_saved_voiceVolume;     // 0x04A
    u8  m_saved_screenAdjustX;   // 0x04B
    u8  m_saved_screenAdjustY;   // 0x04C
    u8  m_saved_brightnessLevel; // 0x04D
    u8  m_saved_contrastLevel;   // 0x04E
    u8  _pad_04F;

    u32 m_onlinePrefsBackup;     // 0x050
    u8  m_versionOrFlag;         // 0x054 (0xFF default, streamed)
    u8  _pad_055[3];

    // StringBuffer2 m_playerName1; // 0x058 (72 bytes, buffer at 0x060)
    u8  m_playerName1[72];       // 0x058-0x09F
    // StringBuffer2 m_playerName2; // 0x0A0 (72 bytes, buffer at 0x0A8)
    u8  m_playerName2[72];       // 0x0A0-0x0E7

    u32 m_field_0E8;             // 0x0E8
    u32 m_field_0EC;             // 0x0EC
    u32 m_field_0F0;             // 0x0F0

    // Method declarations
    OptionsRecon();
    OptionsRecon(OptionsRecon& other);
    void ResetToDefaults();
    void DoStream(ReconBuffer* pBuffer, int direction);
    void WriteOut();
    int  ReadIn(int slot);
    int  WriteToMemoryCard(char*, unsigned char);
    int  ReadFromMemoryCard(char*, unsigned char);
    void PreservePreferences();
    void RestorePreferences();
    void PreservePrefsForOnline();
    void RestorePrefsForOnline();
    void operator=(OptionsRecon& other);
};

// ---------------------------------------------------------------------------
// OptionsRecon::OptionsRecon() - Default constructor
// Address: 0x8005887C  Size: 84 bytes
// ---------------------------------------------------------------------------
OptionsRecon::OptionsRecon() {
    // Initialize StringBuffer2 objects
    // StringBuffer2(this+0x58, this+0x60, 32) -- name1 with 32-wchar buffer
    // StringBuffer2(this+0xA0, this+0xA8, 32) -- name2 with 32-wchar buffer
    new ((void*)m_playerName1) StringBuffer2((wchar_t*)(this + 0x60), 32);
    new ((void*)m_playerName2) StringBuffer2((wchar_t*)(this + 0xA8), 32);

    ResetToDefaults();
}

// ---------------------------------------------------------------------------
// OptionsRecon::OptionsRecon(OptionsRecon&) - Copy constructor
// Address: 0x800588D0  Size: 92 bytes
// ---------------------------------------------------------------------------
OptionsRecon::OptionsRecon(OptionsRecon& other) {
    // Initialize string buffers first (same as default ctor)
    new ((void*)m_playerName1) StringBuffer2((wchar_t*)(this + 0x60), 32);
    new ((void*)m_playerName2) StringBuffer2((wchar_t*)(this + 0xA8), 32);

    // Then copy all fields from 'other'
    *this = other;  // calls operator=
}

// ---------------------------------------------------------------------------
// OptionsRecon::ResetToDefaults - Set all preferences to defaults
// Address: 0x8005892C  Size: 96 bytes
// ---------------------------------------------------------------------------
void OptionsRecon::ResetToDefaults() {
    m_field_024 = 0;           // stw r0,36(r3)
    m_voiceVolume = 10;        // stb r11,30(r3)
    m_versionOrFlag = 0xFF;    // stb r10,84(r3)  -- li r10,-1
    m_bAutoSaveEnabled = 1;    // stw r9,20(r3)
    m_bMusicEnabled = 1;       // stw r9,0(r3)
    m_bSFXEnabled = 1;         // stw r9,4(r3)
    m_bVoiceEnabled = 1;       // stw r9,8(r3)
    m_field_00C = 0;           // stw r0,12(r3)
    m_bVibrationEnabled = 0;   // stw r0,16(r3)
    m_musicVolume = 10;        // stb r11,28(r3)
    m_sfxVolume = 10;          // stb r11,29(r3)
    m_brightnessLevel = 10;    // stb r11,40(r3)
    m_contrastLevel = 10;      // stb r11,41(r3)
    m_screenAdjustX = 0;       // stb r0,31(r3)
    m_screenAdjustY = 0;       // stb r0,32(r3)
    m_field_0E8 = 0;           // stw r0,232(r3)
    m_field_0EC = 0;           // stw r0,236(r3)
    m_field_0F0 = 0;           // stw r0,240(r3)
    m_field_018 = 0;           // stw r0,24(r3)
}

// ---------------------------------------------------------------------------
// OptionsRecon::DoStream - Serialize/deserialize to ReconBuffer
// Address: 0x8005898C  Size: 624 bytes
// ---------------------------------------------------------------------------
// Streams all fields through a ReconBuffer (bidirectional - save or load).
// On load (direction=0), clamps volume values to 0-10 range, clearing
// high bit if set (corrupt data protection).
void OptionsRecon::DoStream(ReconBuffer* pBuffer, int direction) {
    // Stream boolean/int fields
    pBuffer->ReconBool(&m_bMusicEnabled);     // offset 0x00
    pBuffer->ReconBool(&m_bSFXEnabled);       // offset 0x04
    pBuffer->ReconBool(&m_bVoiceEnabled);     // offset 0x08
    pBuffer->ReconBool(&m_field_00C);         // offset 0x0C
    pBuffer->ReconBool(&m_bVibrationEnabled); // offset 0x10

    // Stream volume bytes with clamping
    pBuffer->ReconByte(&m_musicVolume, 1);    // offset 0x1C
    if (pBuffer->GetDirection() == 0) {       // loading
        if (m_musicVolume & 0x80) m_musicVolume = 0;  // Clear if negative
        if ((s8)m_musicVolume > 10) m_musicVolume = 10; // Clamp to max
    }

    pBuffer->ReconByte(&m_sfxVolume, 1);      // offset 0x1D
    if (pBuffer->GetDirection() == 0) {
        if (m_sfxVolume & 0x80) m_sfxVolume = 0;
        if ((s8)m_sfxVolume > 10) m_sfxVolume = 10;
    }

    pBuffer->ReconByte(&m_voiceVolume, 1);    // offset 0x1E
    if (pBuffer->GetDirection() == 0) {
        if (m_voiceVolume & 0x80) m_voiceVolume = 0;
        if ((s8)m_voiceVolume > 10) m_voiceVolume = 10;
    }

    // Stream screen adjust values
    pBuffer->ReconByte(&m_screenAdjustX, 1);  // offset 0x1F
    pBuffer->ReconByte(&m_screenAdjustY, 1);  // offset 0x20

    // Version/flag byte (DoStream handles old-format detection)
    if (pBuffer->GetDirection() == 0) {
        // Loading: read into temp, then validate
        u8 temp;
        pBuffer->ReconByte(&temp, 1);
    } else {
        pBuffer->ReconByte(&m_versionOrFlag, 1); // offset 0x54
    }

    // Stream string buffers
    pBuffer->ReconStringBuffer(&m_playerName1);  // offset 0x58
    pBuffer->ReconStringBuffer(&m_playerName2);  // offset 0xA0

    // Stream trailing fields
    pBuffer->ReconU16(&m_field_0E8, 1);       // offset 0xE8
    pBuffer->ReconS32(&m_field_0EC);          // offset 0xEC
    pBuffer->ReconS32(&m_field_0F0);          // offset 0xF0

    // Stream auto-save and field_018
    pBuffer->ReconS32(&m_bAutoSaveEnabled);   // offset 0x14
    pBuffer->ReconS32(&m_field_018);          // offset 0x18

    // Stream brightness/contrast with clamping
    pBuffer->ReconByte(&m_brightnessLevel, 1); // offset 0x28
    if (pBuffer->GetDirection() == 0) {
        if (m_brightnessLevel & 0x80) m_brightnessLevel = 0;
        if ((s8)m_brightnessLevel > 10) m_brightnessLevel = 10;
    }

    pBuffer->ReconByte(&m_contrastLevel, 1);   // offset 0x29
    if (pBuffer->GetDirection() == 0) {
        if (m_contrastLevel & 0x80) m_contrastLevel = 0;
        if ((s8)m_contrastLevel > 10) m_contrastLevel = 10;
    }

    // Stream field_024
    pBuffer->ReconS32(&m_field_024);           // offset 0x24
}

// ---------------------------------------------------------------------------
// OptionsRecon::WriteOut - Save options to memory card
// Address: 0x80058BFC  Size: 296 bytes
// ---------------------------------------------------------------------------
// Serializes the OptionsRecon to a ReconBuffer, calculates a checksum,
// and writes to memory card via the memory card manager.
void OptionsRecon::WriteOut() {
    // 1. Allocate 8KB buffer
    u8* pBuffer = EAHeapStatic::Alloc(8192, 32, 0, 0);

    // 2. Zero the buffer region (+8 to +8184)
    memset(pBuffer + 8, 0, 8184);

    // 3. Serialize this object via Recon
    // ReconSaveObject<OptionsRecon>(this, 0, 9)
    // Returns a Memory::HandleNode*
    Memory::HandleNode* pNode = ReconSaveObject(this, 0, 9);

    // 4. Copy serialized data into buffer
    // sprintf into pBuffer+8 with the serialized bytes

    // 5. If pNode is valid, free any intermediate allocations
    if (pNode) {
        // Free handle chain
    }

    // 6. Calculate checksum over buffer
    u32 checksum = CalculateChecksum(pBuffer + 8, 8184);
    pBuffer[0] = checksum;  // Store checksum

    // 7. Calculate memory card hash
    u32 cardHash = MemCardManager::CalcHash(70, 9, 12, 0);
    pBuffer[4] = cardHash;

    // 8. Write to memory card
    int result = MemCardManager::Write(pBuffer, 8192);

    // 9. Signal memory card manager completion
    g_pMemCardManager->SignalWriteComplete();

    // 10. Free buffer
    EAHeapStatic::Free(pBuffer);
}

// ---------------------------------------------------------------------------
// OptionsRecon::ReadIn - Load options from memory card
// Address: 0x80058D2C  Size: 296 bytes
// ---------------------------------------------------------------------------
// Reads options from memory card slot, validates checksum and version,
// then deserializes into this object.
int OptionsRecon::ReadIn(int slot) {
    // 1. Allocate 8KB buffer
    u8* pBuffer = EAHeapStatic::Alloc(8192, 32, 0, 0);

    // 2. Zero buffer region
    memset(pBuffer + 8, 0, 8184);

    // 3. Read from memory card into buffer
    int readResult;
    // Loop: read slot data
    readResult = MemCardManager::Read(pBuffer, 8192, slot);

    if (readResult == 1) {  // Data found
        // 4. Validate checksum
        u32 storedChecksum = *(u32*)pBuffer;
        u32 calcChecksum = CalculateChecksum(pBuffer + 8, 8184);

        if (storedChecksum != calcChecksum) {
            // Checksum mismatch
            readResult = -4;
        } else {
            // 5. Validate version hash
            u32 storedHash = *(u32*)(pBuffer + 4);
            u32 expectedHash = MemCardManager::CalcHash(70, 9, 12, 0);

            if (storedHash != expectedHash) {
                // Check compatibility flag
                if (!g_pEGlobal->m_compatFlag) {
                    readResult = -4;
                }
            }

            if (readResult == 1) {
                // 6. Deserialize via Recon
                ReconLoadObject(this, pBuffer, 8192, 0, &slot);
            }
        }
    }

    // 7. Free buffer
    EAHeapStatic::Free(pBuffer);

    // 8. Signal memory card manager
    g_pMemCardManager->SignalReadComplete();

    return readResult;
}

// ---------------------------------------------------------------------------
// OptionsRecon::WriteToMemoryCard / ReadFromMemoryCard - Stubs
// Addresses: 0x80058D24 / 0x80058E54  Size: 8 bytes each
// ---------------------------------------------------------------------------
// These return 0 -- the actual memory card I/O is in WriteOut/ReadIn.
int OptionsRecon::WriteToMemoryCard(char*, unsigned char) { return 0; }
int OptionsRecon::ReadFromMemoryCard(char*, unsigned char) { return 0; }

// ---------------------------------------------------------------------------
// OptionsRecon::PreservePreferences - Save current settings to shadow copy
// Address: 0x80058E5C  Size: 140 bytes
// ---------------------------------------------------------------------------
// Copies all audio/display settings into the shadow region (0x02C-0x04E)
// so they can be restored if the user cancels an options menu.
void OptionsRecon::PreservePreferences() {
    m_saved_bMusicEnabled      = m_bMusicEnabled;       // 0x00 -> 0x2C
    m_saved_bSFXEnabled        = m_bSFXEnabled;         // 0x04 -> 0x30
    m_saved_bVoiceEnabled      = m_bVoiceEnabled;       // 0x08 -> 0x34
    m_saved_bVibrationEnabled  = m_bVibrationEnabled;   // 0x10 -> 0x38
    m_saved_musicVolume        = m_musicVolume;          // 0x1C -> 0x48
    m_saved_sfxVolume          = m_sfxVolume;            // 0x1D -> 0x49
    m_saved_voiceVolume        = m_voiceVolume;          // 0x1E -> 0x4A
    m_saved_screenAdjustX      = m_screenAdjustX;       // 0x1F -> 0x4B
    m_saved_screenAdjustY      = m_screenAdjustY;       // 0x20 -> 0x4C
    m_saved_bAutoSaveEnabled   = m_bAutoSaveEnabled;    // 0x14 -> 0x3C
    m_saved_field_018          = m_field_018;            // 0x18 -> 0x40
    m_saved_field_024          = m_field_024;            // 0x24 -> 0x44
    m_saved_brightnessLevel    = m_brightnessLevel;     // 0x28 -> 0x4D
    m_saved_contrastLevel      = m_contrastLevel;       // 0x29 -> 0x4E

    // Set global flag: preferences have been preserved
    g_bPreferencesPreserved = 1;  // SDA r13-32360
}

// ---------------------------------------------------------------------------
// OptionsRecon::RestorePreferences - Restore settings from shadow copy
// Address: 0x80058EFC  Size: 132 bytes
// ---------------------------------------------------------------------------
// Copies shadow settings back to active fields. Called when user cancels
// the options menu without saving.
void OptionsRecon::RestorePreferences() {
    m_bMusicEnabled       = m_saved_bMusicEnabled;       // 0x2C -> 0x00
    m_bSFXEnabled         = m_saved_bSFXEnabled;         // 0x30 -> 0x04
    m_bVoiceEnabled       = m_saved_bVoiceEnabled;       // 0x34 -> 0x08
    m_bVibrationEnabled   = m_saved_bVibrationEnabled;   // 0x38 -> 0x10
    m_musicVolume         = m_saved_musicVolume;          // 0x48 -> 0x1C
    m_sfxVolume           = m_saved_sfxVolume;            // 0x49 -> 0x1D
    m_voiceVolume         = m_saved_voiceVolume;          // 0x4A -> 0x1E
    m_screenAdjustX       = m_saved_screenAdjustX;       // 0x4B -> 0x1F
    m_screenAdjustY       = m_saved_screenAdjustY;       // 0x4C -> 0x20
    m_bAutoSaveEnabled    = m_saved_bAutoSaveEnabled;    // 0x3C -> 0x14
    m_field_018           = m_saved_field_018;            // 0x40 -> 0x18
    m_field_024           = m_saved_field_024;            // 0x44 -> 0x24
    m_brightnessLevel     = m_saved_brightnessLevel;     // 0x4D -> 0x28
    m_contrastLevel       = m_saved_contrastLevel;       // 0x4E -> 0x29
}

// ---------------------------------------------------------------------------
// OptionsRecon::PreservePrefsForOnline - Save vibration for online
// Address: 0x80058EE8  Size: 20 bytes
// ---------------------------------------------------------------------------
// Saves the vibration setting before entering online mode (online may
// force different vibration behavior).
void OptionsRecon::PreservePrefsForOnline() {
    m_onlinePrefsBackup = m_bVibrationEnabled;  // 0x10 -> 0x50
    g_bOnlinePrefsPreserved = 1;                // SDA r13-32356
}

// ---------------------------------------------------------------------------
// OptionsRecon::RestorePrefsForOnline - Restore vibration after online
// Address: 0x80058F80  Size: 12 bytes
// ---------------------------------------------------------------------------
void OptionsRecon::RestorePrefsForOnline() {
    m_bVibrationEnabled = m_onlinePrefsBackup;  // 0x50 -> 0x10
}

// ---------------------------------------------------------------------------
// OptionsRecon::operator= - Assignment operator
// Address: 0x803A0380  Size: 344 bytes
// ---------------------------------------------------------------------------
// Copies all fields from another OptionsRecon. Does field-by-field copy
// for simple types and calls StringBuffer2 copy for the two name fields.
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

    // Copy string buffers
    StringBuffer2::Copy(&m_playerName1, &other.m_playerName1);  // offset 0x58
    StringBuffer2::Copy(&m_playerName2, &other.m_playerName2);  // offset 0xA0

    m_field_0E8 = other.m_field_0E8;
    m_field_0EC = other.m_field_0EC;
    m_field_0F0 = other.m_field_0F0;
}

// ---------------------------------------------------------------------------
// IsConfigFileValid - Standalone helper function
// Address: 0x80074E28  Size: 56 bytes
// ---------------------------------------------------------------------------
// Attempts to read a config file and returns true if valid (ReadIn succeeded).
bool IsConfigFileValid(int slot, OptionsRecon& opts) {
    int result = opts.ReadIn(slot);
    // XOR with 1, then normalize: returns true if ReadIn returned 0 (success)
    // xori r3,r3,1 then subfic/adde pattern
    return (result == 0);
}


// ============================================================================
// SECTION 5: Summary of Key Findings
// ============================================================================
//
// EGlobal (0x654 bytes, 211 fields):
//   - Offsets 0x000-0x09B: Cheat sequence table (10 cheats x 6 steps x u16)
//   - Offset 0x09C: Active cheat bitmask (u16)
//   - Offset 0x0A0: Game state flags
//   - Offsets 0x0BC-0x0C0: Selected person pointers (2 players)
//   - Offset 0x0C8: Current house pointer
//   - Offset 0x0D0: Camera pointer (ESimsCam*)
//   - Offsets 0x0D4-0x0DC: Floor/wall/fence tile set pointers
//   - Offset 0x0E0: Camera director pointer
//   - Offsets 0x0E4-0x148: Resource handles (~20 handles, loaded lazily)
//   - Offset 0x114: ECheats object pointer
//   - Offsets 0x330-0x3AF: Object state flags (32 x u32)
//   - Offsets 0x3BC-0x404: Cheat/debug/author mode flags
//   - Offset 0x400: God mode flag (if nonzero, all cheats active)
//   - Offset 0x478: Controller listen flag
//   - Offset 0x490: Level state resource
//
// ECheats (0x10C bytes):
//   - 64-bucket hash table for cheat code lookups
//   - Init() is massive (7824 bytes) -- builds hash table from cheat sequences
//   - EnableCheats/DisableCheats manage audio event callbacks
//   - SetGodMode directly writes 8 EGlobal cheat flags to 1
//   - WriteCheatsFile/Update are no-ops on GameCube
//
// OptionsRecon (0xF4 bytes):
//   - Audio: music/SFX/voice enable (bool), volume levels (u8, 0-10)
//   - Display: screen adjust X/Y (s8, -25 to +25), brightness/contrast (u8, 0-10)
//   - Controller: vibration enable
//   - Auto-save flag
//   - Two player name StringBuffer2 fields
//   - Shadow copy mechanism for options menu cancel
//   - Serialized via EA's Recon system (ReconBuffer)
//   - Memory card I/O through WriteOut/ReadIn (checksum + version validation)
//   - DoStream clamps all volume values to 0-10 on load (corrupt data protection)
