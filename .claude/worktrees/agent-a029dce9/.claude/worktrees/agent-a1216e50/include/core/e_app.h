#ifndef E_APP_H
#define E_APP_H

#include "types.h"

// Forward declarations
class EAHeap;
class ERLevel;
class ERC;
struct HeapUseInfo;
struct EMat4;
struct EVec3;

typedef int OVERALL_GAME_STATE;
typedef int eTrackFlags;
struct EACTrack;

// EApp - Base application class from engine_ngc_release_dvd.lib(e_app.obj)
// Provides virtual interface for application lifecycle, movie playback, and state management.
// ESimsApp derives from this.
class EApp {
public:
    // Constructor sets up vtable, sda globals, zeroes members
    EApp();
    // 0x802e21e0 (52 bytes)
    virtual ~EApp();

    // --- Virtual methods (default implementations) ---
    virtual void SetupForMovie(void);           // 0x802e24b0 (4 bytes) - no-op
    virtual void CleanupAfterMovie(void);       // 0x802e24b4 (4 bytes) - no-op
    virtual void ShowInitialDisplay(void);      // 0x802e2974 (4 bytes) - no-op
    virtual void Init(void);                    // 0x802e2978 (4 bytes) - no-op
    virtual void Update(void);                  // 0x802e297c (4 bytes) - no-op
    virtual void UpdateAfterHotSync(void);      // 0x802e2980 (4 bytes) - no-op
    virtual void Shutdown(void);                // 0x802e2990 (4 bytes) - no-op
    virtual const char* GetRootDirectory(void); // 0x802e2910 (12 bytes)
    virtual const char* GetBuildVersion(void);  // 0x802e291c (12 bytes)
    virtual const char* GetAppName(void);       // 0x802e2928 (12 bytes)
    virtual int GetPrefetchBlockSize(void);     // 0x802e2934 (8 bytes)
    virtual int GetScratchBuffSize(void);       // 0x802e293c (8 bytes)
    virtual int GetEventTableSize(void);        // 0x802e2944 (8 bytes)
    virtual int GetAppStackSize(void);          // 0x802e2984 (12 bytes)
    virtual EAHeap* GetMovieHeap(void);         // 0x802e28f0 (32 bytes)

    // Non-virtual methods
    void SystemInit(void);                      // 0x802e247c (52 bytes)
    void PlayMovie(unsigned int id, int a, int b); // 0x802e26f0 (32 bytes)
    void StopMovie(void);                       // 0x802e2710 (12 bytes)
    int IsMovieStarting(void);                  // 0x802e271c (24 bytes)
    int IsMoviePlaying(void);                   // 0x802e2734 (24 bytes)
    void SetGameState(OVERALL_GAME_STATE s);    // 0x802e295c (8 bytes)
    void SetMenuOwner(OVERALL_GAME_STATE s);    // 0x802e296c (8 bytes)
    const char* GetFullArgString(void) const;   // 0x802e294c (8 bytes)
    OVERALL_GAME_STATE GetGameState(void) const;// 0x802e2954 (8 bytes)
    OVERALL_GAME_STATE GetMenuOwner(void) const;// 0x802e2964 (8 bytes)

    // Padding/members inferred from offsets
    // 0x000: vtable ptr (set in ctor)
    // 0x338: vtable2 ptr (set to EApp vtable2)
    // 0x340: movie-related ptr (initially 0)
    // 0x350: arg string buffer
    // 0x450: movie state (m_movieState)
    // 0x454: movie sub-state (m_movieSubState)
    // 0x458: movie resource ptr
    // 0x45C: movie id
    // 0x460: movie param a
    // 0x464: movie param b
    // 0x468: game state
    // 0x46C: menu owner state
    // 0x470: root dir ptr
    char _pad[0x478]; // full object size placeholder
};

// EEngine - Engine core from engine_ngc_release_dvd.lib(e_engine.obj)
class EEngine {
public:
    EEngine();

    // Small functions
    void ManagedShutdown(void);                     // 0x802e2b3c (12 bytes)
    void Line(void);                                // 0x802e2b48 (4 bytes)
    void PrintBanner(void);                         // 0x802e3238 (4 bytes)
    void PrintConfiguration(void);                  // 0x802e323c (4 bytes)
    int GetMinRetraces(void);                       // 0x802e2e38 (24 bytes)
    void EnterMovieMode(void);                      // 0x802e2e50 (60 bytes)
    void ExitMovieMode(void);                       // 0x802e2e8c (60 bytes)
    void FrameComplete(void);                       // 0x802e31fc (60 bytes)
    void InitFileSystem(void);                      // 0x802e340c (44 bytes)
    void ClearCurrentLevel(ERLevel* level);         // 0x802e37b8 (24 bytes)
    void Idle(void);                                // 0x802e37d0 (4 bytes)
    void GetDMARingMemoryUseInfo(HeapUseInfo* info);       // 0x802e37d4 (36 bytes)
    void GetTextureRingMemoryUseInfo(HeapUseInfo* info);   // 0x802e37f8 (36 bytes)
    void GetMatrixRingMemoryUseInfo(HeapUseInfo* info);    // 0x802e381c (36 bytes)
    void GetMemoryUseSystemInfo(HeapUseInfo* info);        // 0x802e3840 (40 bytes)
    void GetMemoryUseDmaInfo(HeapUseInfo* info);           // 0x802e3868 (40 bytes)
    int ManagedStartup(void);                       // 0x802e38e8 (8 bytes)
    void Reboot(void);                              // 0x802e38c0 (4 bytes)
    void SignalShutdown(void);                      // 0x802e38e4 (4 bytes)
    void EnableFrameRatePredictiveSmoothing(bool);  // 0x802e38b8 (8 bytes)
    void SetCurrentLevel(ERLevel* level);           // 0x802e38c4 (8 bytes)
    ERLevel* GetCurrentLevel(void);                 // 0x802e38cc (8 bytes)
    void SetResetAllowed(bool);                     // 0x802e38d4 (8 bytes)
    int CanReset(void);                             // 0x802e38dc (8 bytes)

    // Member layout inferred from assembly
    // 0x00: vtable ptr
    // 0x04: some_state
    // 0x08: smoothing_enabled
    // 0x0C: reset_allowed
    // 0x30: current_level
    // 0x34: app ptr offset
    char _pad[0x40]; // placeholder
};

// HeapUseInfo - memory usage info structure
struct HeapUseInfo {
    const char* name;  // 0x00
    int flags;         // 0x04
    int used;          // 0x08
    int free;          // 0x0C
    int total;         // 0x10
};

// EController - Controller/input from engine_ngc_release_dvd.lib(e_ctrl.obj)
class EController {
public:
    // Small functions from e_ctrl.obj
    void ClearAllData(void);                          // 0x803041e0 (44 bytes)
    void ClearAppData(bool b);                        // 0x8030420c (36 bytes)
    void OverrideStatus(int status);                  // 0x80304294 (8 bytes)
    void SwapAxes(int axis);                          // 0x8030429c (24 bytes)
    void InvertAxis(int axis, int sub);               // 0x803042b4 (32 bytes)
    unsigned int GetBtnResultAny(unsigned int mask, bool excl, unsigned int filter); // 0x8030503c (64 bytes)
    void Flush(void);                                 // 0x8030440c (40 bytes)
    int HasVibration(void) const;                     // 0x80304434 (8 bytes)
    int IsMotorOneActive(void) const;                 // 0x8030443c (28 bytes)
    int IsMotorTwoActive(void) const;                 // 0x80304458 (28 bytes)
    int StopMotorOne(float val);                      // 0x80304774 (12 bytes)
    int StopMotorTwo(float val);                      // 0x803047e4 (12 bytes)
    void ResetControllerData(bool clearAll);          // 0x803049c4 (36 bytes)
    int IsControlFake(void);                          // 0x80304d10 (8 bytes)
    void SetControlFake(bool fake);                   // 0x80304d18 (8 bytes)
    void SetFakeButtons(unsigned int btns);            // 0x80304d20 (8 bytes)
    void SetBtnExcl(void);                            // 0x80304fe8 (16 bytes)
    unsigned int GetBtnDownMask(unsigned int filter);  // 0x80305778 (56 bytes)
    unsigned int GetBtnUpMask(unsigned int filter);    // 0x803057b0 (56 bytes)
    unsigned int GetBtnPressedMask(unsigned int filter);  // 0x803057e8 (56 bytes)
    unsigned int GetBtnReleasedMask(unsigned int filter);  // 0x80305820 (56 bytes)
    unsigned int GetBtnRepeatMask(unsigned int filter);    // 0x80305858 (52 bytes)
    int GetStatus(void);                              // 0x80305894 (8 bytes)
    int IsStable(void);                               // 0x8030589c (12 bytes)
    int GetId(void);                                  // 0x8030588c (8 bytes)
    int AreAxesSwapped(int axis);                     // 0x80305d58 (16 bytes)
    int GetDirectionModifier(int axis, int sub);      // 0x80305d68 (24 bytes)

    // Member layout (from offsets used in assembly)
    // 0x000: controller_id
    // 0x004: status
    // 0x18C: axes_swap_table[8]   (4 ints, indexed by axis)
    // 0x194: direction_mods[2][8] (indexed by [axis*8+sub])
    // 0x1A4: btn_cmd_table_ptr
    // 0x1A8: btn_cmd_count
    // 0x1AC: is_fake
    // 0x1B0: fake_buttons
    // 0x1B4: repeat_mask
    // 0x1B8: repeat_timers[31] (byte array)
    // 0x1D8: vibration_timer_byte
    // 0x1D9: repeat_default_byte
    // 0x1DC: motor1_strength (float)
    // 0x1E0: motor2_strength (float)
    // 0x1E4: motor1_decay (float)
    // 0x1E8: motor2_decay (float)
    // 0x1EC: vibration_state (16 bytes)
    // 0x1FC: btn_data_prev_ptr
    // 0x200: btn_data_cur_ptr
    // 0x204: has_input_flag
    // 0x208: vtable for ctrl driver
    char _pad[0x210]; // placeholder
};

// EBtnToCmdAssoc - Button-to-command association
struct EBtnToCmdAssoc {
    static int CompareControllerCommands(void* a, void* b);    // 0x80304230 (32 bytes)
    static int CompareControllerCommandToKey(void* a, void* b); // 0x8030507c (32 bytes)
};

// CheatMenuParams from e_cheatmenu.obj
class EDebugMenuItem;

struct CheatMenuParams {
    CheatMenuParams(void);    // 0x80303ccc (24 bytes)
    ~CheatMenuParams(void);   // 0x80303ce4 (40 bytes)
    void Add(EDebugMenuItem& item); // 0x80303d0c (60 bytes)

    void* m_head;       // 0x00 - linked list head
    void* m_tail;       // 0x04 - linked list tail
    int m_count;        // 0x08 - item count

    static CheatMenuParams s_cheatMenuParams; // at 0x804b0d1c
};

// EDebugMenuItem from e_debugmenu.obj
enum EDebugMenuButton {};

class EDebugMenuItem {
public:
    EDebugMenuItem(void);                               // 0x80305d80 (32 bytes)
    virtual void GetDescription(char* buf, int len);    // 0x803c4160 (12 bytes)
    virtual void GetValue(char* buf);                   // 0x803c416c (12 bytes)
    virtual void ButtonPress(EDebugMenuButton btn);     // 0x803c4178 (4 bytes)
    virtual void ButtonPress(EDebugMenuButton btn, float val); // 0x803c417c (4 bytes)

    // 0x00: next ptr (linked list)
    // 0x04: prev ptr (linked list)
    // 0x08: vtable ptr
    void* m_next; // 0x00
    void* m_prev; // 0x04
    void* m_vt;   // 0x08 - set to EDebugMenuItem vtable
};

// EDebugMenu from e_debugmenu.obj
class EDebugMenu {
public:
    EDebugMenu(void);  // 0x80305da0 (40 bytes)

    // 0x00: visible (0=hidden, 1=shown)
    // 0x08: active (1=yes)
    // 0x0C: head ptr (linked list of items at offset 0x0C)
    // 0x10: tail ptr (at offset 0x10 = 0x0C + 4)
    // 0x14: selected index
    // 0x18: item count
    int m_visible;     // 0x00
    int m_unk04;       // 0x04
    int m_active;      // 0x08
    void* m_head;      // 0x0C
    void* m_tail;      // 0x10
    int m_selected;    // 0x14
    int m_count;       // 0x18
};

// EFrameAllocGroup from e_frag.obj
class EFrameAllocGroup {
public:
    EFrameAllocGroup();
    virtual ~EFrameAllocGroup();

    virtual void ManagedShutdown(void);   // 0x803066a8 (56 bytes)
    virtual void Update(void);            // 0x803066e0 (60 bytes)
    void* Alloc(unsigned int size, int align); // 0x8030683c (48 bytes)

    // Members at various offsets
    // 0x00: vtable
    // 0x04: sub-allocator 0 (24 bytes each)
    // 0x1C: sub-allocator 1
    // 0x34: current_index (alternates 0/1)
    char _pad[0x38];
};

// EAnimController from e_animcontroller.obj
class EAnimController {
public:
    void Shutdown(void);                                 // 0x802e7f40 (32 bytes)
    void SuspendTrack(EACTrack* track);                  // 0x802e80a0 (36 bytes)
    void GetAnimDistance(eTrackFlags flags, EVec3& out);  // 0x802e94a8 (48 bytes)
    void PrintTracks(void);                              // 0x802e9c0c (24 bytes)
    void PrepareForCollision(EMat4& mat);                // 0x802ea28c (64 bytes)
    void CallbackIntermediateComputeMatrices(EMat4& mat);// 0x802eb53c (52 bytes)
    void SetTrackBlendHermiteSafe(EACTrack* track, float a, float b, float c, float d); // 0x802ee4d8 (32 bytes)
    void SetTrackBlendFactors(EACTrack* track, float* factors); // 0x802ef214 (28 bytes)
};

// Particle system functions from psystem.obj (C-style)
struct pemitter;

extern "C" {
    void PSystemSetWorldGravityDir(void* dir);            // 0x80303a8c (48 bytes)
    int ParticleSysClose(void);                           // 0x80303a54 (56 bytes)
    void ParticleProcessType3(pemitter* e, float dt);     // 0x80302ce0 (32 bytes)
    void ParticleDestroy(void** handle);                  // 0x80303248 (60 bytes)
    void PEmitterSetState(void* emitter, unsigned int mask, int set); // 0x80303708 (40 bytes)
    int PEmitterGetNumActiveParticles(void* emitter);     // 0x80303730 (12 bytes)
    int PSystemGetNumActiveParticles(void);               // 0x80303abc (12 bytes)
}

// Global function declarations for e_main.obj
extern "C" int InitHeap(void);                            // 0x802e3a34 (8 bytes)
extern "C" void RegisterExitFunction(void* func);        // 0x802e3a3c (8 bytes)

// External function references used by button mask functions
extern unsigned int EController_GetBtnExclMask(unsigned int filter); // helper called internally

#endif // E_APP_H
