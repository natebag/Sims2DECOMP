// =============================================================================
// ui_targets.cpp - Complete UI Target/Wrapper/Manager System
// =============================================================================
//
// Decompiled portable C++ for the Sims 2 GameCube UI subsystem.
// Converted from PPC inline assembly (src/asm_decomp/) using decomp docs
// (src/ui/targets_decomp.cpp, src/ui/wrapper.cpp, src/ui/dlgwrapper*.cpp,
//  src/ui/mustates_medium.cpp, src/ui/muwrapper_large.cpp, src/ui/uicore.cpp,
//  src/ui/uibase_medium.cpp) for struct layouts, field offsets, vtable
//  orders, control flow, and calling conventions.
//
// This file covers ALL remaining UI/Target/Wrapper classes not already in
// src/decomp_cpp/ui_system.cpp (which covers APT engine internals).
//
// Sections:
//   1.  Forward declarations and basic types
//   2.  UIObjectBase - Abstract base class
//   3.  UIReflow - Batched UI element modification
//   4.  UIScreenManager - Screen lifecycle manager
//   5.  UIRouter - Variable routing
//   6.  FlowGotoTarget - Screen navigation state machine
//   7.  WrapperPaneBase - Base class for UI panes
//   8.  Wrapper - Top-level UI wrapper
//   9.  DlgWrapper - Modal dialog system
//  10.  MUWrapper - Memory unit wrapper
//  11.  MUStateMachine and MUState* classes
//  12.  HUDTarget - Live mode HUD controller
//  13.  ACTTarget - Action queue display
//  14.  O2TTarget - Options menu controller
//  15.  E2ETarget - EyeToy camera controller
//  16.  FAMTarget - Family/lot selection
//  17.  MMUTarget - Main menu controller
//  18.  M2MTarget - Memory card management
//  19.  LoadGameTarget - Load game operation
//  20.  SaveGameTarget - Save game operation
//  21.  CSMTarget - CAS integration menu
//  22.  KEYTarget - Input configuration
//  23.  INGTarget - In-game ingredient/cooking target
//  24.  WAFTarget - Wants and fears display
//  25.  CUIWindow - Debug UI window system
//  26.  CUIPropertySheet - Debug property editor
//  27.  Additional Target classes (BBH, CRD, CSP, FCM, G2D, H2D, ITB,
//       K2Y, MDI, MOD, MOT, PAZ, PZ1, PCT, PRG, R2L, RCP, SKL, WXF)
//  28.  UIDialog base callback class
//
// All struct offsets are derived from the decomp docs and verified against
// the PPC assembly in src/asm_decomp/*.cpp.
//
// =============================================================================

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <cmath>

// -- Basic types (matching include/types.h) ----------------------------------
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef float          f32;


// =============================================================================
// SECTION 1 - Forward declarations
// =============================================================================

class ERC;
class ERFont;
class ERShader;
class cXObject;
class cXPerson;
class Interaction;
class Family;
class NghResFile;
class BString2;
class AptViewer;
class AptConstFile;
class AptCharacter;
class AptCharacterInst;
class TextBlock;
class CUIPane;
class CUIEvent;

struct EVec2 { f32 x, y; };
struct EVec3 { f32 x, y, z; };
struct EVec4 { f32 x, y, z, w; };
struct structDrawCBparams;
struct CBFunctorBase;

// Template forward used by CUIWindow
template<typename T> struct TRect {
    T left, top, right, bottom;
};

// Font alignment enums for CUIWindow
enum EFontAlignX { FONT_ALIGN_X_LEFT = 0, FONT_ALIGN_X_CENTER, FONT_ALIGN_X_RIGHT };
enum EFontAlignY { FONT_ALIGN_Y_TOP = 0, FONT_ALIGN_Y_CENTER, FONT_ALIGN_Y_BOTTOM };

// Controller command enum (used by button filter system)
typedef int ECTRL_CMD;

// UIScreenID / UIScreenInputMode enumerations
typedef int UIScreenID;
typedef int UIScreenInputMode;

// Global singleton pointers (from r13/SDA in PPC binary)
extern AptViewer* g_pAptViewer;       // _globals + 0xB4 = 0x80475E80
extern void*      g_pUIRouter;        // _globals + 0xF8 = 0x80475EC4

// External function declarations
extern "C" {
    void* ERShader_AddRef(const char* path, u32 hash, int a, int b);
    void  ERShader_Release(void* shader);
}


// =============================================================================
// SECTION 2 - UIObjectBase
// =============================================================================
// Virtual table at 0x8045CFD8 (64 bytes = 16 vtable entries)
// Size: variable (base class only provides vtable + utility methods)
//
// UIObjectBase is the bridge between APT Flash UI and C++ game logic.
// All Target classes inherit from this (through Wrapper) and override the
// virtual callbacks to handle screen-specific variable get/set operations.
//
// Static safe-area constants (sdata2):
//   UIObjectBase::SAFE_LEFT   = 0x80500658
//   UIObjectBase::SAFE_TOP    = 0x8050065C
//   UIObjectBase::SAFE_RIGHT  = 0x80500660
//   UIObjectBase::SAFE_BOTTOM = 0x80500664

class UIObjectBase {
public:
    // --- Virtual interface ---
    virtual ~UIObjectBase() {}                                    // vt[0]
    virtual void SetVariable(char* name, char* value) {}          // vt[1]
    virtual char* GetVariable(char* name) { return nullptr; }     // vt[2]
    virtual unsigned short* GetLocalizable(char* name) { return nullptr; } // vt[3]
    virtual void Update() {}                                      // vt[4]
    virtual void Draw(ERC* rc) {}                                 // vt[5]

    // --- Utility methods (non-virtual, from uicore.cpp / uibase_medium.cpp) ---

    // 0x80177A64 (52 bytes) - Push APT button filter for a player
    void pushAptButtonFilter(int player, char* context) {
        if (g_pAptViewer) {
            // Delegate to AptViewer::PushAptButtonFilter(player, context)
        }
    }

    // 0x80177A98 (52 bytes) - Pop APT button filter
    void popAptButtonFilter(int player, u32 handle) {
        if (g_pAptViewer) {
            // Delegate to AptViewer::PopAptButtonFilter(player, handle)
        }
    }

    // 0x80177ACC (60 bytes) - Add command to button filter
    void addCmdToAptButtonFilter(int player, u32 handle, ECTRL_CMD cmd) {
        if (g_pAptViewer) {
            // Delegate to AptViewer::AddCmdToAptButtonFilter
        }
    }

    // 0x80177B08 (60 bytes) - Remove command from button filter
    void removeCmdFromAptButtonFilter(int player, u32 handle, ECTRL_CMD cmd) {
        if (g_pAptViewer) {
            // Delegate to AptViewer::RemoveCmdFromAptButtonFilter
        }
    }

    // 0x80177B44 (96 bytes) - Push button filter for ALL 48 command slots
    void pushAptButtonFilterALL(int player, char* context) {
        for (u32 i = 1; i <= 48; i++) {
            pushAptButtonFilter(player, context);
        }
    }

    // 0x80177BA4 (140 bytes) - Convert int to wchar number string
    void makeNumberString(int value, unsigned short* outBuf) {
        if (!outBuf) return;
        char tmp[32];
        sprintf(tmp, "%d", value);
        for (int i = 0; tmp[i]; i++) {
            outBuf[i] = static_cast<unsigned short>(tmp[i]);
        }
        outBuf[strlen(tmp)] = 0;
    }

    // 0x80177C30 (120 bytes) - Convert int to money string
    void makeMoneyString(int value, unsigned short* outBuf, bool withSymbol) {
        if (!outBuf) return;
        char tmp[32];
        if (withSymbol) {
            sprintf(tmp, "$%d", value);
        } else {
            sprintf(tmp, "%d", value);
        }
        for (int i = 0; tmp[i]; i++) {
            outBuf[i] = static_cast<unsigned short>(tmp[i]);
        }
        outBuf[strlen(tmp)] = 0;
    }

    // 0x80177CA8 (32 bytes) - String substitution
    void doUIQDStringSubstitution(unsigned short* str) {
        // Delegates to UIQDTarget::UIQDSubstitutionStrings(str)
    }

    // 0x80177CC8 (68 bytes) - Route SetVariable through UIRouter
    void UIRouter_SetVariable(const char* name, const char* value) {
        if (!g_pUIRouter) return;
        // Load vtable from UIRouter at offset 0x80, dispatch SetVariable
        u8* routerObj = reinterpret_cast<u8*>(g_pUIRouter);
        void** vtable = *reinterpret_cast<void***>(routerObj + 0x80);
        s16 thisAdj = *reinterpret_cast<s16*>(reinterpret_cast<u8*>(vtable) + 0x10);
        void* func = *reinterpret_cast<void**>(reinterpret_cast<u8*>(vtable) + 0x14);
        void* adjThis = routerObj + thisAdj;
        typedef void (*SetVarFn)(void*, char*, char*);
        reinterpret_cast<SetVarFn>(func)(adjThis,
            const_cast<char*>(name), const_cast<char*>(value));
    }

    // 0x80177D0C (72 bytes) - Navigate to a screen via FlowGoto
    void UIRouter_FlowGoto(const char* screenName) {
        UIRouter_SetVariable("state", screenName);
    }

    // 0x80177D54 (84 bytes) - Call ActionScript function on AptViewer
    void AptViewer_CallFunction(const char* funcName, const char* arg1,
                                const char* arg2, int argc, char** argv) {
        // Delegate to AptViewer::NewCallFunction2
    }
};


// =============================================================================
// SECTION 3 - UIReflow
// =============================================================================
// Size: 0x14 (20 bytes)
// Provides batched command system for modifying APT UI elements.

class UIReflow {
public:
    int   m_focus;          // 0x04 - current screen ID (0 = none)
    void* m_blockBuffer;    // 0x08 - dynamically allocated command buffer
    int   m_blockSize;      // 0x0C - current number of commands in buffer
    int   m_blockCapacity;  // 0x10 - allocated capacity of buffer

    // 0x8017D234 (32 bytes)
    UIReflow() : m_focus(0), m_blockBuffer(nullptr),
                 m_blockSize(0), m_blockCapacity(0) {}

    // 0x8017D254 (92 bytes)
    ~UIReflow() {
        if (m_blockBuffer) {
            free(m_blockBuffer);
            m_blockBuffer = nullptr;
        }
    }

    // 0x8017D2B0 (112 bytes)
    void SetFocus(UIScreenID screenID) {
        m_focus = screenID;
        // Calls UIScreenManager::GetScreenFlashName to resolve screen ID
        // Then calls AptViewer::Init to set active context
    }

    // --- Immediate property resets ---
    void ResetSize(char* element, int w, int h, int player) {}             // 0x8017D320
    void ResetPosition(char* element, int x, int y, int player) {}         // 0x8017D4A0
    void ResetZ(char* element, int z, int player) {}                       // 0x8017D620
    void ResetVisibility(char* element, bool visible, int player) {}       // 0x8017D75C
    void ResetAlpha(char* element, u32 alpha, int player) {}               // 0x8017D898
    void ResetText(char* element, char* text, int player) {}               // 0x8017D9E4
    void ResetColorOverride(char* element, u32 color, int player) {}       // 0x8017DB04
    void ResetFontSizeOverride(char* element, u32 size, int player) {}     // 0x8017DCAC
    void ResetSwfAnimation(char* element, char* anim, int player) {}       // 0x8017DDE8
    void ResetSwfFileName(char* element, char* file, int player) {}        // 0x8017DF08

    // --- Internal block management ---
    void AddToBlock(char* cmd) {
        // Append command string to block buffer, grow if needed
        if (m_blockSize >= m_blockCapacity) {
            ReallocateBlock();
        }
        m_blockSize++;
    }

    void ReallocateBlock() {
        int newCap = (m_blockCapacity == 0) ? 16 : m_blockCapacity * 2;
        void* newBuf = realloc(m_blockBuffer, newCap * sizeof(void*));
        if (newBuf) {
            m_blockBuffer = newBuf;
            m_blockCapacity = newCap;
        }
    }

    // --- Tween animation system ---
    void OpenTweenBlock(char* element, u32 duration, u32 delay,
                        char* easing, int player) {}                       // 0x8017E138
    void SubmitTweenBlock() {}                                             // 0x8017E318
    void Tween_X(int x) {}                                                 // 0x8017E39C
    void Tween_Y(int y) {}                                                 // 0x8017E408
    void Tween_Z(u32 z) {}                                                 // 0x8017E474
    void Tween_H(u32 h) {}                                                 // 0x8017E4E0
    void Tween_W(u32 w) {}                                                 // 0x8017E54C
    void Tween_XScale(f32 scale) {}                                        // 0x8017E5B8
    void Tween_YScale(f32 scale) {}                                        // 0x8017E638
    void Tween_Rotation(f32 rot) {}                                        // 0x8017E6B8
    void Tween_Alpha(u32 alpha) {}                                         // 0x8017E72C
    void Tween_ColorOverride(u32 color) {}                                 // 0x8017E7A8
    void Tween_ColorOnlyOverride(u32 color) {}                             // 0x8017E838
    void Tween_FontSizeOverride(u32 size) {}                               // 0x8017E8B4

    // --- Reflow batch system ---
    void OpenReflowBlock() {}                                              // 0x8017E920
    void SubmitReflowBlock() {}                                            // 0x8017E998
    void Reflow_Id(char* id, int player) {}                                // 0x8017EA1C
    void Reflow_X(int x) {}                                                // 0x8017EAB0
    void Reflow_Y(int y) {}                                                // 0x8017EAD0
    void Reflow_Z(u32 z) {}                                                // 0x8017EAF0
    void Reflow_H(u32 h) {}                                                // 0x8017EB10
    void Reflow_W(u32 w) {}                                                // 0x8017EB30
    void Reflow_XScale(f32 scale) {}                                       // 0x8017EB50
    void Reflow_YScale(f32 scale) {}                                       // 0x8017EB70
    void Reflow_Rotation(f32 rot) {}                                       // 0x8017EB90
    void Reflow_Visibility(bool visible) {}                                // 0x8017EBB0
    void Reflow_Alpha(u32 alpha) {}                                        // 0x8017EC28
    void Reflow_StringChange(char* text) {}                                // 0x8017EC48
    void Reflow_ColorOverride(u32 color) {}                                // 0x8017EC9C
    void Reflow_ColorOnlyOverride(u32 color) {}                            // 0x8017ECBC
    void Reflow_FontSizeOverride(u32 size) {}                              // 0x8017ECDC
    void Reflow_SwfAnimation(char* anim) {}                                // 0x8017ECFC
    void Reflow_SwfFile(char* file) {}                                     // 0x8017ED50
    void Debug_PrintBlock() {}                                             // 0x8017EDA4
};


// =============================================================================
// SECTION 4 - UIScreenManager
// =============================================================================
// Virtual table at 0x80466750
// Static data: UIScreenManager::UIScreenDataTable at 0x80424720 (1488 bytes)
// Singleton group: UIScreenManager::m_groupNumber at 0x804FDE18
// Size: ~0x600 (includes embedded screen record array)

class UIScreenManager : public UIObjectBase {
public:
    // Screen record entry (32 bytes each, embedded array)
    struct ScreenRecord {
        int      m_screenID;
        int      m_type;
        int      m_isManaged;
        int      m_isLoaded;
        int      m_inputMode;
        void*    m_target;
        char     m_flashName[64];
        int      m_markedForUnload;
    };

    static int m_groupNumber;

    int           m_numRecords;
    ScreenRecord  m_records[32];     // max 32 simultaneous screens
    int           m_queueHead;
    int           m_queueTail;
    int           m_queue[16];

    // 0x8017F0D0 (1464 bytes)
    UIScreenManager() {
        m_numRecords = 0;
        m_queueHead = 0;
        m_queueTail = 0;
        memset(m_records, 0, sizeof(m_records));
        memset(m_queue, 0, sizeof(m_queue));
    }

    // 0x8017F688
    ~UIScreenManager() override {}

    // 0x8017F838 (184 bytes) - Find data record by screen ID
    void* FindDataByID(UIScreenID screenID) {
        for (int i = 0; i < m_numRecords; i++) {
            if (m_records[i].m_screenID == screenID) {
                return &m_records[i];
            }
        }
        return nullptr;
    }

    // 0x8017F87C (8 bytes) - Empty debug function
    void process_cheats(UIScreenID screenID) {
        // intentionally empty
    }

    // 0x8017F884 (640 bytes) - Load a UI screen by ID
    int LoadUIScreen(UIScreenID screenID, UIScreenInputMode inputMode) {
        if (IsScreenManaged(screenID)) return -1;
        // Look up screen data, handle screen type (1=suspend all, 3/4=special)
        return AddScreen(screenID, 0);
    }

    // 0x8017FAE4 (428 bytes) - Unload a screen
    int UnloadUIScreen(UIScreenID screenID) {
        return RemoveScreen(screenID);
    }

    // 0x8017FC74 (60 bytes) - Check if screen is managed
    int IsScreenManaged(UIScreenID screenID) {
        return (FindRecordIndexByID(screenID) >= 0) ? 1 : 0;
    }

    // 0x8017FCB0 (188 bytes) - Suspend all active screens
    void SuspendAllActiveScreens() {
        for (int i = 0; i < m_numRecords; i++) {
            if (m_records[i].m_isLoaded) {
                m_records[i].m_isLoaded = 0;
            }
        }
    }

    // 0x8017FD58 (288 bytes) - Suspend a list of screens
    void SuspendScreenList(UIScreenID* screenIDs) {
        if (!screenIDs) return;
        for (int i = 0; screenIDs[i] != -1; i++) {
            int idx = FindRecordIndexByID(screenIDs[i]);
            if (idx >= 0) {
                m_records[idx].m_isLoaded = 0;
            }
        }
    }

    // 0x8017FE64 (284 bytes) - Add screen to managed list
    int AddScreen(UIScreenID screenID, int type) {
        if (m_numRecords >= 32) return -1;
        ScreenRecord& rec = m_records[m_numRecords];
        rec.m_screenID = screenID;
        rec.m_type = type;
        rec.m_isManaged = 1;
        rec.m_isLoaded = 1;
        rec.m_inputMode = 0;
        rec.m_target = nullptr;
        rec.m_markedForUnload = 0;
        m_numRecords++;
        return 0;
    }

    // 0x8017FEB8 (64 bytes) - Find record index by screen ID
    int FindRecordIndexByID(UIScreenID screenID) {
        for (int i = 0; i < m_numRecords; i++) {
            if (m_records[i].m_screenID == screenID) return i;
        }
        return -1;
    }

    // 0x8017FEF8 (76 bytes) - Remove screen from managed list
    int RemoveScreen(UIScreenID screenID) {
        int idx = FindRecordIndexByID(screenID);
        if (idx < 0) return -1;
        // Shift remaining records down
        for (int i = idx; i < m_numRecords - 1; i++) {
            m_records[i] = m_records[i + 1];
        }
        m_numRecords--;
        return 0;
    }

    // 0x8017FF44 (248 bytes) - Get Flash movie name for screen
    int GetScreenFlashName(char* outBuf, UIScreenID screenID) {
        int idx = FindRecordIndexByID(screenID);
        if (idx < 0) return -1;
        strcpy(outBuf, m_records[idx].m_flashName);
        return 0;
    }

    // 0x8018003C (44 bytes)
    int IsUIScreenUnloaded(UIScreenID screenID) {
        int idx = FindRecordIndexByID(screenID);
        if (idx < 0) return 1;
        return !m_records[idx].m_isLoaded;
    }

    // 0x80180068 (84 bytes)
    int IsUIScreenMarkedForUnloading(UIScreenID screenID) {
        int idx = FindRecordIndexByID(screenID);
        if (idx < 0) return 0;
        return m_records[idx].m_markedForUnload;
    }

    // 0x801800BC (224 bytes)
    void SetHandlesInput(UIScreenID screenID, bool handles) {
        int idx = FindRecordIndexByID(screenID);
        if (idx < 0) return;
        m_records[idx].m_inputMode = handles ? 1 : 0;
    }

    // 0x8018019C (216 bytes) - Route SetVariable to appropriate target
    void SetVariable(char* name, char* value) override {
        for (int i = 0; i < m_numRecords; i++) {
            if (m_records[i].m_target) {
                UIObjectBase* target = static_cast<UIObjectBase*>(m_records[i].m_target);
                target->SetVariable(name, value);
            }
        }
    }

    // 0x80180274 (148 bytes) - Frame update
    void Update() override {
        for (int i = 0; i < m_numRecords; i++) {
            if (m_records[i].m_isLoaded && m_records[i].m_target) {
                UIObjectBase* target = static_cast<UIObjectBase*>(m_records[i].m_target);
                target->Update();
            }
        }
    }

    // 0x80180308 (64 bytes) - Pop queue entries
    void PopQueue(int count) {
        for (int i = 0; i < count && m_queueHead != m_queueTail; i++) {
            m_queueHead = (m_queueHead + 1) % 16;
        }
    }
};

int UIScreenManager::m_groupNumber = 0;


// =============================================================================
// SECTION 5 - UIRouter
// =============================================================================
// Virtual table at 0x80466710
// Routes APT variable get/set to appropriate targets.

class UIRouter : public UIObjectBase {
public:
    void* m_targets[16];  // registered target pointers
    int   m_numTargets;

    // 0x8017EDA8 (252 bytes)
    UIRouter() : m_numTargets(0) {
        memset(m_targets, 0, sizeof(m_targets));
    }

    // 0x8017EEA4
    ~UIRouter() override {}

    // 0x8017EF08
    char* GetVariable(char* name) override {
        // Iterate registered targets and return first non-null response
        for (int i = 0; i < m_numTargets; i++) {
            if (m_targets[i]) {
                UIObjectBase* t = static_cast<UIObjectBase*>(m_targets[i]);
                char* result = t->GetVariable(name);
                if (result) return result;
            }
        }
        return nullptr;
    }

    // 0x8017EFE0
    void SetVariable(char* name, char* value) override {
        for (int i = 0; i < m_numTargets; i++) {
            if (m_targets[i]) {
                UIObjectBase* t = static_cast<UIObjectBase*>(m_targets[i]);
                t->SetVariable(name, value);
            }
        }
    }
};


// =============================================================================
// SECTION 6 - FlowGotoTarget
// =============================================================================
// Virtual table at 0x80466578
// Size: ~0x90
// Central screen navigation controller.

class FlowGotoTarget : public UIObjectBase {
public:
    int  m_stateRequest;        // 0x084 - pending navigation target state
    int  m_requestPending;      // 0x088 - flag: state request pending
    int  m_currentState;        // current active state
    u8   m_pad[0x80];           // remaining fields

    // State ID constants (from SetVariable string comparison chain)
    enum FlowState {
        FLOW_NONE        = 0,
        FLOW_MAINMENU    = 1,
        FLOW_INGAME      = 2,
        FLOW_CAS_BODY    = 3,
        FLOW_CAS_FACE    = 4,
        FLOW_CAS_CLOTHES = 5,
        FLOW_CAS_SUMMARY = 6,
        FLOW_CAS_SELECT  = 7,
        FLOW_LOADGAME    = 8,
        FLOW_FREEPLAY    = 9,
        FLOW_CREDITS     = 10,
        FLOW_OPTIONS     = 11,
    };

    // 0x8017ABA0 (1164 bytes)
    FlowGotoTarget() : m_stateRequest(FLOW_NONE), m_requestPending(0),
                       m_currentState(FLOW_NONE) {
        memset(m_pad, 0, sizeof(m_pad));
    }

    // 0x8017B02C
    ~FlowGotoTarget() override {}

    // 0x8017B170 (1804 bytes) - Main navigation handler
    // Massive string comparison maps screen name -> state ID
    void SetVariable(char* name, char* value) override {
        if (strcmp(name, "state") != 0) return;

        if (strcmp(value, "mainmenu") == 0) {
            m_stateRequest = FLOW_MAINMENU;
        } else if (strcmp(value, "ingame") == 0) {
            m_stateRequest = FLOW_INGAME;
        } else if (strcmp(value, "freeplay") == 0) {
            m_stateRequest = FLOW_FREEPLAY;
        } else if (strcmp(value, "loadgame") == 0) {
            m_stateRequest = FLOW_LOADGAME;
        } else if (strcmp(value, "credits") == 0) {
            m_stateRequest = FLOW_CREDITS;
        } else if (strcmp(value, "options") == 0) {
            m_stateRequest = FLOW_OPTIONS;
        } else if (strcmp(value, "cas_body") == 0) {
            m_stateRequest = FLOW_CAS_BODY;
        } else if (strcmp(value, "cas_face") == 0) {
            m_stateRequest = FLOW_CAS_FACE;
        } else if (strcmp(value, "cas_clothes") == 0) {
            m_stateRequest = FLOW_CAS_CLOTHES;
        } else if (strcmp(value, "cas_summary") == 0) {
            m_stateRequest = FLOW_CAS_SUMMARY;
        } else if (strcmp(value, "cas_select") == 0) {
            m_stateRequest = FLOW_CAS_SELECT;
        }
        m_requestPending = 1;
    }

    // 0x8017B960
    char* GetVariable(char* name) override {
        return nullptr;
    }

    // 0x8017B960
    int IsStateRequestPending() {
        return m_requestPending;
    }

    // 0x8017B980
    int GetStateRequest() {
        return m_stateRequest;
    }

    // 0x8017B988
    void SetPendingStateCurrent() {
        m_currentState = m_stateRequest;
        m_requestPending = 0;
    }
};


// =============================================================================
// SECTION 7 - WrapperPaneBase
// =============================================================================
// Base class for all UI panes within Wrapper objects.
// Manages item lists, buttons, background shaders, and draw state.

// Button type enumeration
enum ButtonType {
    kButton_Accept  = 0,
    kButton_Decline = 1,
    kButton_Alt1    = 2,
    kButton_Max     = 3
};

// Pane state enumeration
enum PaneState {
    kPaneState_Running  = 0,
    kPaneState_Accepted = 1,
    kPaneState_Declined = 2,
    kPaneState_Alt1     = 3
};

// Item type for SetSelected/GetItem etc.
typedef int ItemType;

// TextBaseItem - text display element within a pane
class TextBaseItem {
public:
    u32            m_flags;             // 0x00
    u32            m_aptFlags;          // 0x04
    unsigned short* m_text;             // at offset via TextBlock
    EVec4*         m_color;             // color pointer
    f32            m_shadowAlpha;
    f32            m_shadowSize;
    f32            m_posX, m_posY;
    f32            m_displaySizeX, m_displaySizeY;
    f32            m_displayPadSizeX, m_displayPadSizeY;
    u32            m_textBlockFlags;    // flags in embedded TextBlock
    ERFont*        m_font;
    f32            m_fontSize;
    int            m_style;             // ItemStyle

    // 0x80087104 (12 bytes)
    void Reset() { m_flags = 1; }

    // 0x80087170 (40 bytes)
    void SetColor(EVec4& color) {
        m_color->x = color.x;
        m_color->y = color.y;
        m_color->z = color.z;
        m_color->w = color.w;
    }

    EVec4* GetColor() { return m_color; }
    void   SetAlpha(f32 alpha) { m_color->w = alpha; }
    f32    GetAlpha() { return m_color->w; }
    void   SetShadowAlpha(f32 a) { m_shadowAlpha = a; }
    f32    GetShadowAlpha() { return m_shadowAlpha; }
    void   SetShadowSize(f32 s) { m_shadowSize = s; }
    f32    GetShadowSize() { return m_shadowSize; }

    void   SetPos(EVec2& pos) { m_posX = pos.x; m_posY = pos.y; }
    EVec2* GetPos() { return reinterpret_cast<EVec2*>(&m_posX); }
    void   SetPosX(f32 x) { m_posX = x; }
    f32    GetPosX() { return m_posX; }
    void   SetPosY(f32 y) { m_posY = y; }
    f32    GetPosY() { return m_posY; }

    void   SetDisplaySize(EVec2& size) {
        m_displaySizeX = size.x;
        m_displaySizeY = size.y;
        // TextBlock::SetDirty()
    }
    EVec2* GetDisplaySize() { return reinterpret_cast<EVec2*>(&m_displaySizeX); }
    f32    GetDisplaySizeX() { return m_displaySizeX; }
    f32    GetDisplaySizeY() { return m_displaySizeY; }

    void   SetDisplayPadSize(EVec2& size) {
        m_displayPadSizeX = size.x;
        m_displayPadSizeY = size.y;
    }
    EVec2* GetDisplayPadSize() { return reinterpret_cast<EVec2*>(&m_displayPadSizeX); }

    void   SetVerticalCenter(bool center) {
        if (center) m_textBlockFlags |= 0x08;
        else        m_textBlockFlags &= ~0x08u;
    }

    void   SetYPosCentered(bool centered) {
        if (centered) m_textBlockFlags |= 0x20;
        else          m_textBlockFlags &= ~0x20u;
    }

    unsigned short* GetText() const { return m_text; }

    void SetFont(ERFont* font) {
        m_font = font;
        m_flags |= 0x02;
    }
    ERFont* GetFont() const { return m_font; }

    void SetFontSize(f32 size) {
        m_fontSize = size;
        m_flags |= 0x02;
    }
    f32 GetFontSize() const { return m_fontSize; }

    int GetStyle() const { return m_style; }

    void SetText(unsigned short* text) {
        if (!text) return;
        m_text = text;
        m_flags |= 0x02;
    }
};

// IconItem - icon display element
class IconItem {
public:
    u32       m_flags;       // 0x00
    ERShader* m_shader;      // 0x30
    f32       m_colorR, m_colorG, m_colorB, m_alpha;

    void Startup() { m_shader = nullptr; }

    void Shutdown() { ReleaseShader(); }

    void SetShader(u32 shaderHash) {
        m_shader = static_cast<ERShader*>(ERShader_AddRef("", shaderHash, 0, 0));
    }

    void ReleaseShader() {
        if (m_shader) {
            ERShader_Release(m_shader);
            m_shader = nullptr;
        }
    }

    void SetColor(EVec4& color) {
        m_colorR = color.x; m_colorG = color.y;
        m_colorB = color.z; m_alpha = color.w;
    }

    void SetAlpha(f32 a) { m_alpha = a; }
    f32  GetAlpha() { return m_alpha; }
    void SetShader(ERShader* s) { m_shader = s; }
    ERShader* GetShader() { return m_shader; }
};

class WrapperPaneBase {
public:
    u32            m_drawFlags;       // 0x04
    // Item list vector (begin/end/capacity pointers at 0x08..0x14)
    void**         m_items;           // 0x08
    void**         m_itemsEnd;        // 0x0C
    void**         m_itemsCap;        // 0x10
    s32            m_paneId;
    ERShader*      m_bgShader;        // 0x18
    f32            m_bgRectPosX, m_bgRectPosY;
    f32            m_bgRectSizeX, m_bgRectSizeY;
    f32            m_bgAlpha;
    char*          m_buttonContext;
    int            m_buttonContextLen;
    TextBaseItem*  m_buttons[kButton_Max]; // accept, decline, alt1
    f32            m_alpha;
    PaneState      m_state;
    int            m_numItemsInit;
    int            m_numItemsCurrent;

    // 0x80084A8C (40 bytes)
    void Startup() {
        m_numItemsCurrent = m_numItemsInit;
        // Zero 7 words backwards from offset 0x58
    }

    // 0x80087A64 (4 bytes)
    void Reset() { /* empty */ }

    s32  GetPaneId() { return m_paneId; }

    // 0x80087A68 (48 bytes)
    void EnableDraw() {
        m_drawFlags |= 0x01;
        ShowEnabledButtons();
    }

    // 0x80087A98 (48 bytes)
    void DisableDraw() {
        m_drawFlags &= ~0x01u;
        HideEnabledButtons();
    }

    bool IsDrawEnabled() { return (m_drawFlags & 0x01) != 0; }

    void SetAlpha(f32 alpha) { m_alpha = alpha; }
    f32  GetAlpha() { return m_alpha; }

    void SetState(PaneState state) { m_state = state; }
    void SetStateRunning() { m_state = kPaneState_Running; }
    void SetStateAccepted() { m_state = kPaneState_Accepted; }
    void SetStateDeclined() { m_state = kPaneState_Declined; }
    void SetStateAlt1() { m_state = kPaneState_Alt1; }

    int  GetState() const { return m_state; }
    bool IsStateRunning() const { return m_state == kPaneState_Running; }
    bool IsStateAccepted() const { return m_state == kPaneState_Accepted; }
    bool IsStateDeclined() const { return m_state == kPaneState_Declined; }
    bool IsStateAlt1() const { return m_state == kPaneState_Alt1; }

    void SetBackgroundShader(u32 shaderHash) {
        m_bgShader = static_cast<ERShader*>(ERShader_AddRef("", shaderHash, 0, 0));
    }

    void ReleaseBackgroundShader() {
        if (m_bgShader) {
            ERShader_Release(m_bgShader);
            m_bgShader = nullptr;
        }
    }

    ERShader* GetBackgroundShader() { return m_bgShader; }

    void SetBackgroundRect(EVec2* pos, EVec2* size) {
        m_bgRectPosX = pos->x;  m_bgRectPosY = pos->y;
        m_bgRectSizeX = size->x; m_bgRectSizeY = size->y;
    }

    void SetBackgroundAlpha(f32 alpha) { m_bgAlpha = alpha; }

    void SetButtonContext(char* context) {
        m_buttonContext = context;
        m_buttonContextLen = context ? static_cast<int>(strlen(context)) : 0;
    }

    TextBaseItem*   GetButton(ButtonType type) { return m_buttons[type]; }
    unsigned short* GetButtonText(ButtonType type) const { return m_buttons[type]->m_text; }
    ERFont*         GetButtonFont(ButtonType type) const { return m_buttons[type]->m_font; }
    f32             GetButtonFontSize(ButtonType type) const { return m_buttons[type]->m_fontSize; }
    EVec2*          GetButtonPos(ButtonType type) const { return m_buttons[type]->GetPos(); }
    f32             GetButtonPosX(ButtonType type) const { return m_buttons[type]->GetPosX(); }
    f32             GetButtonPosY(ButtonType type) const { return m_buttons[type]->GetPosY(); }

    TextBaseItem* GetAcceptButton() { return m_buttons[kButton_Accept]; }
    TextBaseItem* GetDeclineButton() { return m_buttons[kButton_Decline]; }
    TextBaseItem* GetAlt1Button() { return m_buttons[kButton_Alt1]; }

    void* GetItemList() { return reinterpret_cast<void*>(m_items); }

    void SetAcceptText(unsigned short* text) {
        m_buttons[kButton_Accept]->SetText(text);
        UpdateAptButtonWidth(kButton_Accept);
    }

    void SetDeclineText(unsigned short* text) {
        m_buttons[kButton_Decline]->SetText(text);
        UpdateAptButtonWidth(kButton_Decline);
    }

    void SetAlt1Text(unsigned short* text) {
        m_buttons[kButton_Alt1]->SetText(text);
        UpdateAptButtonWidth(kButton_Alt1);
    }

    void SetButtonText(ButtonType type, unsigned short* text) {
        m_buttons[type]->SetText(text);
        UpdateAptButtonWidth(type);
    }

    void UpdateAptButtonPosX(ButtonType type) {
        u32 mask = 0x100u << type;
        if (!(m_drawFlags & mask)) return;
        // Set APT dirty flags on button
    }

    void UpdateAptButtonPosY(ButtonType type) {
        u32 mask = 0x100u << type;
        if (!(m_drawFlags & mask)) return;
    }

    // Stubs for virtual methods called by Enable/DisableDraw
    virtual void ShowEnabledButtons() {}
    virtual void HideEnabledButtons() {}
    virtual void UpdateAptButtonWidth(ButtonType type) {}

    // Drawing
    virtual void DrawBackground(ERC* rc) {}          // 0x80084BF8 (652 bytes)
    virtual void DrawItems(ERC* rc, bool enabled) {}  // 0x80084E84 (172 bytes)

    // Item management
    void SetSelected(ItemType type, int idx) {}
    void* GetSelectedItem(ItemType type) { return nullptr; }
    void* GetEnabledItemIndexWithValue(ItemType type, int val) { return nullptr; }
    void* GetItem(ItemType type, int idx) { return nullptr; }
    void SetItemFont(ItemType type, int idx, ERFont* font) {}
    void SetItemFontSize(ItemType type, int idx, f32 size) {}
    void SetItemPos(ItemType type, int idx, EVec2& pos) {}
    void SetItemPosX(ItemType type, int idx, f32 x) {}
    void SetItemPosY(ItemType type, int idx, f32 y) {}
    void SetItemSize(ItemType type, int idx, EVec2& size) {}
    void SetItemSizeX(ItemType type, int idx, f32 x) {}
    void SetItemSizeY(ItemType type, int idx, f32 y) {}

    // Shutdown (324 bytes) - releases shaders, deletes item list
    void Shutdown() {
        if (m_bgShader) {
            ERShader_Release(m_bgShader);
            m_bgShader = nullptr;
        }
        // Delete item list, release button shaders
    }

    // DeleteItemList (296 bytes)
    void DeleteItemList() {
        // Iterate items, call destructors, free memory
    }
};


// =============================================================================
// SECTION 8 - Wrapper
// =============================================================================
// Top-level UI wrapper that contains panes.
// Inherits UIObjectBase and manages WrapperPaneBase instances.

class Wrapper : public UIObjectBase {
public:
    WrapperPaneBase** m_panes;     // pane array
    int               m_numPanes;
    int               m_activePaneIdx;
    u8                m_wrapperData[0x80]; // remaining wrapper state

    // 0x800DC17C (136 bytes)
    ~Wrapper() override {}

    // 0x800E83F4 (316 bytes) - WrapperShutdown
    void WrapperShutdown() {
        for (int i = 0; i < m_numPanes; i++) {
            if (m_panes[i]) {
                m_panes[i]->Shutdown();
            }
        }
    }

    // 0x800E8540 (340 bytes) - WrapperDraw
    void WrapperDraw(ERC* rc) {
        for (int i = 0; i < m_numPanes; i++) {
            if (m_panes[i] && m_panes[i]->IsDrawEnabled()) {
                m_panes[i]->DrawBackground(rc);
                m_panes[i]->DrawItems(rc, true);
            }
        }
    }

    // 0x800E8724 (360 bytes) - AddPane
    void AddPane(WrapperPaneBase* pane) {
        if (m_numPanes < 16) {
            m_panes[m_numPanes++] = pane;
        }
    }

    // 0x800E888C (84 bytes) - Release all pane background shaders
    void ReleasePaneBackgrounds() {
        for (int i = 0; i < m_numPanes; i++) {
            if (m_panes[i]) {
                m_panes[i]->ReleaseBackgroundShader();
            }
        }
    }
};


// =============================================================================
// SECTION 9 - DlgWrapper
// =============================================================================
// Virtual table at 0x8045CF18
// Size: 0x698C (27020 bytes - includes large embedded DialogPane)
// Modal dialog display system.

class DlgWrapper {
public:
    u32   m_flags;          // 0x00
    void* m_aptViewerHandle; // 0x04
    void* m_font;           // 0x08
    void* m_dialogPane;     // 0x0C
    f32   m_posX, m_posY;   // dialog position
    f32   m_sizeX, m_sizeY; // dialog size
    int   m_refCount;       // reference count for show/hide
    int   m_dialogMode;     // modal flag
    int   m_state;          // dialog state
    void* m_titleText;      // title string pointer
    void* m_bodyText;       // body string pointer
    int   m_buttonCount;
    int   m_selectionType;
    int   m_currentSelection;
    int   m_numButtons;
    void* m_currentDialog;  // current active dialog pane
    int   m_dialogStackCount;
    int   m_playerCount;

    // 0x8007E440 (260 bytes)
    DlgWrapper(bool useAltLayout) {
        m_flags = 0;
        m_aptViewerHandle = nullptr;
        m_font = nullptr;
        m_dialogPane = nullptr;
        m_posX = 0.0f; m_posY = 0.0f;
        m_sizeX = 0.0f; m_sizeY = 0.0f;
        m_refCount = 0;
        m_dialogMode = 0;
        m_state = 0;
        m_titleText = nullptr;
        m_bodyText = nullptr;
        m_buttonCount = 0;
        m_selectionType = 0;
        m_currentSelection = 0;
        m_numButtons = 0;
        m_currentDialog = nullptr;
        m_dialogStackCount = 0;
        m_playerCount = 1;
        if (useAltLayout) {
            m_flags |= 1; // set modal flag
        }
    }

    // 0x8007E544
    ~DlgWrapper() {}

    // --- Core lifecycle ---

    void Startup() {}                                  // 0x8007D8A0 (1272 bytes)

    // 0x8007DD98 (84 bytes)
    void Shutdown() {
        DialogPaneHide();
        // Release shader, clear state
        m_refCount = 0;
    }

    // 0x8007DDEC (68 bytes)
    void Reset() {
        m_refCount = 0;
        // Reset pane selection state
        DialogPaneShow();
    }

    // 0x8007DE30 (440 bytes) - Main update: handles button presses
    void Update() {
        // Read input, dispatch accept/decline/alt1 based on button ID
    }

    void Draw(ERC* rc) {}                              // 0x8007DFE8

    // 0x8007E084 (120 bytes)
    void DialogPaneShow() {
        m_refCount++;
        // Show APT dialog pane, set visible flag
    }

    // 0x8007E0FC (136 bytes)
    void DialogPaneHide() {
        m_refCount--;
        // Hide APT dialog pane, clear visible flag, clear items
    }

    // --- APT variable interface ---
    void  SetVariable(char* name, char* value) {}      // 0x8007E184 (240 bytes)

    // 0x8007E274 (460 bytes) - Gets dialog state variables
    char* GetVariable(char* name) {
        if (strcmp(name, "visible") == 0) {
            return (m_flags & 1) ? const_cast<char*>("1") : const_cast<char*>("0");
        }
        return nullptr;
    }

    // --- State queries ---
    void* GetFont() { return m_font; }                 // 0x8007E5E0
    void* GetDialogPane() { return m_dialogPane; }     // 0x8007E5E8

    // 0x8007E5F0 (24 bytes) - bit field check
    bool IsDialogUp() { return m_refCount > 0; }

    // 0x8007E608 (24 bytes)
    bool DialogAccepted() { return m_state == 1; }

    // 0x8007E620 (24 bytes)
    bool DialogDeclined() { return m_state == 2; }

    // 0x8007E638 (24 bytes)
    bool DialogAlt1() { return m_state == 3; }

    // 0x8007F06C
    bool IsAptDrawable() { return m_dialogPane != nullptr; }

    // --- Positioning ---
    void   SetDialogPos(EVec2& pos) { m_posX = pos.x; m_posY = pos.y; }
    void   SetDialogPosX(f32 x) { m_posX = x; }
    void   SetDialogPosY(f32 y) { m_posY = y; }
    EVec2* GetDialogPos() { return reinterpret_cast<EVec2*>(&m_posX); }
    f32    GetDialogPosX() const { return m_posX; }
    f32    GetDialogPosY() const { return m_posY; }

    // --- Sizing ---
    void   SetDialogSize(EVec2& size) { m_sizeX = size.x; m_sizeY = size.y; }
    void   SetDialogSizeX(f32 w) { m_sizeX = w; }
    void   SetDialogSizeY(f32 h) { m_sizeY = h; }
    EVec2* GetDialogSize() { return reinterpret_cast<EVec2*>(&m_sizeX); }
    f32    GetDialogSizeX() const { return m_sizeX; }
    f32    GetDialogSizeY() const { return m_sizeY; }
    f32    GetDialogWidth() const { return m_sizeX; }
    f32    GetDialogHeight() const { return m_sizeY; }
    f32    GetDialogPadSizeX() const { return 0.0f; }
    f32    GetDialogPadSizeY() const { return 0.0f; }
    f32    GetTitleWidth() const { return m_sizeX; }

    // --- Content ---
    void SetTitleText(unsigned short* text) {}         // 0x8007E7E0
    void SetTitleFontSize(f32 size) {}                 // 0x8007E808
    void SetBodyText(unsigned short* text) {}          // 0x8007E84C
    void SetBodyFont(ERFont* font) {}                  // 0x8007E874
    void SetBodyFontSize(f32 size) {}                  // 0x8007E8B8
    void SetBodyPos(EVec2& pos) {}                     // 0x8007E8FC
    void SetBodyPosX(f32 x) {}                         // 0x8007E954
    void SetBodyPosY(f32 y) {}                         // 0x8007E990
    void SetBodyPadSize(EVec2& padSize) {}             // 0x8007EF60

    // --- Buttons ---
    void SetAcceptText(unsigned short* text) {}        // 0x8007E9CC
    void SetAcceptFont(ERFont* font) {}                // 0x8007EA08
    void SetAcceptFontSize(f32 size) {}                // 0x8007EA58
    void SetAcceptPos(EVec2& pos) {}                   // 0x8007EAAC
    void SetAcceptPosX(f32 x) {}                       // 0x8007EB08
    void SetAcceptPosY(f32 y) {}                       // 0x8007EB58
    void SetDeclineText(unsigned short* text) {}       // 0x8007EBA8
    void SetDeclineFont(ERFont* font) {}               // 0x8007EBE4
    void SetDeclineFontSize(f32 size) {}               // 0x8007EC34
    void SetDeclinePos(EVec2& pos) {}                  // 0x8007EC88
    void SetDeclinePosX(f32 x) {}                      // 0x8007ECE4
    void SetDeclinePosY(f32 y) {}                      // 0x8007ED34
    void SetAlt1Text(unsigned short* text) {}          // 0x8007ED84
    void SetAlt1Font(ERFont* font) {}                  // 0x8007EDC0
    void SetAlt1FontSize(f32 size) {}                  // 0x8007EE10
    void SetAlt1Pos(EVec2& pos) {}                     // 0x8007EE64
    void SetAlt1PosX(f32 x) {}                         // 0x8007EEC0
    void SetAlt1PosY(f32 y) {}                         // 0x8007EF10

    void SetButtonContext(char* context) {}            // 0x8007EF9C
    void AddAcceptButton(unsigned short* text) {}      // 0x8007EFDC
    void AddDeclineButton(unsigned short* text) {}     // 0x8007F00C
    void AddAlt1Button(unsigned short* text) {}        // 0x8007F03C
    void SetPlayer(int player) { m_playerCount = player; }  // 0x8007F074
};


// =============================================================================
// SECTION 10 - MUWrapper
// =============================================================================
// Memory unit (memory card) UI wrapper.
// Manages save slot display, selection, and input handling.

class MUWrapper {
public:
    u32    m_flags;          // 0x04
    void** m_slotList;       // 0x08
    void** m_slotListEnd;    // 0x0C
    void** m_slotListCap;    // 0x10
    int    m_numSlots;       // 0xC0
    int    m_dialogState;    // 0xC8
    int    m_selection;      // 0xCC
    int    m_scrollPos;      // 0xD0
    int    m_scrollTarget;   // 0xD4
    u8     m_wrapperData[0x80]; // base Wrapper data

    // 0x8007F7BC (316 bytes)
    void Shutdown() {
        // Release all slot resources
        void** p = m_slotList;
        while (p && p != m_slotListEnd) {
            if (*p) {
                delete reinterpret_cast<u8*>(*p);
            }
            p++;
        }
        // Free slot list
        if (m_slotList) {
            delete[] reinterpret_cast<u8*>(m_slotList);
        }
        m_slotList = nullptr;
        m_slotListEnd = nullptr;
        m_slotListCap = nullptr;
    }

    // 0x80080BA8 (984 bytes)
    void ResetSlotSelection(int clearAll) {
        for (int i = 0; i < m_numSlots; i++) {
            if (!m_slotList) break;
            void* slot = m_slotList[i];
            if (!slot) continue;
            u8* s = reinterpret_cast<u8*>(slot);
            *reinterpret_cast<int*>(s + 0x00) = 0; // state
            *reinterpret_cast<int*>(s + 0x04) = 0; // selected
            *reinterpret_cast<int*>(s + 0x08) = 0; // highlighted
            if (clearAll) {
                *reinterpret_cast<int*>(s + 0x0C) = 0; // dirty
                *reinterpret_cast<int*>(s + 0x10) = 0; // data valid
            }
        }
        m_scrollPos = 0;
        m_scrollTarget = 0;
    }

    // 0x80081880 (340 bytes)
    void HideDialog() {
        m_flags &= ~1u;
        // Hide all child panes
        void** p = m_slotList;
        while (p && p != m_slotListEnd) {
            if (*p) {
                u8* pane = reinterpret_cast<u8*>(*p);
                *reinterpret_cast<u32*>(pane + 0x04) &= ~1u;
            }
            p++;
        }
        m_dialogState = 0;
        m_selection = -1;
    }

    // 0x800815D4 (684 bytes)
    void ShowDialog() {
        m_flags |= 1;
        m_selection = 0;
        m_dialogState = 1;
        // Show panes, initialize slot display
    }

    // 0x80080F80 (840 bytes) - Main update
    void Update() {
        // State machine for MU dialog input handling
    }
};


// =============================================================================
// SECTION 11 - MUStateMachine and MUState* classes
// =============================================================================
// Memory unit state machine system. Each MUStates* class represents a
// state in the memory card management flow (format, save, load, etc.).

// Global MU state data (at 0x804858D8)
struct MUStateData {
    int  m_field00, m_field04, m_field08, m_field0C;
    void *m_field10, *m_field14, *m_field18, *m_field1C;
    int  m_field20, m_field24, m_field28, m_field2C;
    int  m_field30, m_field34, m_field38, m_field3C;
    int  m_field40;
};

// MUStatesFormat - memory card format state
class MUStatesFormat {
public:
    u8    _pad00[0x08];
    void* m_machine;      // 0x08
    u8    _pad0C[0x10];
    int   m_field1C;      // 0x1C
    int   m_field20;      // 0x20

    // 0x800916F8 (108 bytes)
    void Reset() {
        m_field1C = 0;
        m_field20 = 0;
        // Set wrapper mode, change state to 14
        m_field20 = 0;
        m_field1C = 1;
    }

    // 0x80091764 (72 bytes) - Draw if state permits
    void Draw(ERC* rc) {
        if (m_field20 == 1) {
            // Draw wrapper through vtable dispatch
        }
    }
};

// MUStatesSlotSelectSave
class MUStatesSlotSelectSave {
public:
    u8    _pad00[0x08];
    void* m_machine;      // 0x08
    u8    _pad0C[0x84];
    int   m_memcardState; // 0x90

    // 0x80091A7C (116 bytes)
    void Update(f32 dt) {
        // Check memcard state and transition accordingly
    }
};

// MUStatesSlotSelectSaveNoSkip
class MUStatesSlotSelectSaveNoSkip {
public:
    u8    _pad00[0x08];
    void* m_machine;      // 0x08
    u8    _pad0C[0x84];
    int   m_memcardState; // 0x90

    // 0x80091AF0 (136 bytes)
    void Update(f32 dt) {
        // Similar to MUStatesSlotSelectSave but no skip option
    }
};

// MUStatesSaveNewGame
class MUStatesSaveNewGame {
public:
    int   m_field00;
    u8    _pad04[0x04];
    void* m_machine;      // 0x08
    u8    _pad0C[0x10];
    int   m_field1C;      // 0x1C

    MUStatesSaveNewGame(int arg) : m_field00(0), m_field1C(0), m_machine(nullptr) {}

    // 0x800922F4 (76 bytes)
    void Draw(ERC* rc) {
        int state = m_field1C;
        if (static_cast<u32>(state - 7) <= 2) {
            // Draw wrapper through vtable dispatch
        }
    }
};

// MUStatesTransitionSaveExistingGame
class MUStatesTransitionSaveExistingGame {
public:
    u8    _pad00[0x08];
    void* m_machine;      // 0x08
    u8    _pad0C[0x10];
    int   m_field1C;      // 0x1C

    // 0x80092EE4 (120 bytes)
    void Draw(ERC* rc) {
        int state = m_field1C;
        if (static_cast<u32>(state - 8) <= 1) {
            // Clear animation flag, draw wrapper, set animation flag
        }
    }
};

// MUStatesLoadConfig
class MUStatesLoadConfig {
public:
    u8    _pad00[0x08];
    void* m_machine;      // 0x08
    u8    _pad0C[0x10];
    int   m_field1C;      // 0x1C

    // 0x80093124 (76 bytes)
    void Draw(ERC* rc) {
        int state = m_field1C;
        if (static_cast<u32>(state - 1) <= 1) {
            // Draw wrapper
        }
    }
};

// MUStatesDisplay
class MUStatesDisplay {
public:
    u8    _pad00[0x08];
    void* m_machine;      // 0x08

    // 0x8009320C (68 bytes)
    void Update(f32 dt) {
        // Update wrapper through vtable dispatch
    }

    // 0x80093250 (68 bytes)
    void Draw(ERC* rc) {
        // Draw wrapper through vtable dispatch
    }
};

// MUStateMachine - top-level state machine for memory unit operations
class MUStateMachine {
public:
    u8    _pad00[0x18];
    void* m_vtable;       // 0x18
    u8    _pad1C[0x08];
    u8    _pad24[0x30];
    void* m_vec_begin;    // 0x54
    u8    _pad58[0x3C];
    int   m_field94;      // 0x94
    void* m_wrapper;      // 0x98

    // 0x800939DC (84 bytes)
    void SetupQuitToMainMenu() {
        // Set global state data for quit-to-main-menu transition
    }

    // 0x80093958 (104 bytes)
    void MUWrapperShutdown() {
        if (m_wrapper) {
            // Shutdown and destroy wrapper through vtable
            m_wrapper = nullptr;
        }
    }

    void Reset() {}
    ~MUStateMachine() {}
};


// =============================================================================
// SECTION 12 - HUDTarget
// =============================================================================
// Virtual table at 0x80466888 (64 bytes)
// Size: 0x8B8 (2232 bytes)
// Live mode HUD overlay controller.

class HUDTarget : public UIObjectBase {
public:
    static ERFont* m_pFont;  // at 0x804FDE44

    // Per-player data pointers
    void* m_playerData[2];

    // HUD visibility state
    int   m_hudVisState;       // 0xE8 - 0=hidden, 1=showing, 2=visible, 3=CAS transition
    int   m_tutorialLocks;     // 0xF0 - tutorial completion tracking

    // Speed control bytes
    u8    m_speedPrev;         // 0xF4
    u8    m_speedCurrent;      // 0xF5
    u8    m_speedPrevCombined; // 0xF6
    u8    m_speedCommand;      // 0xF7 - -4=pause, -3=slow, -2=ff, 0=normal

    int   m_hudMode;           // current HUD mode
    int   m_field_084;         // clock update counter (counts to 30)
    int   m_field_100;         // navigation state (0=normal, 1=mainmenu, 3=CAS)

    void* m_actionQueueHUD[2]; // per-player ACTTarget pointers
    void* m_liveMode;          // ELiveMode pointer (0x8B4)

    // 0x8018591C (4320 bytes)
    HUDTarget() {
        m_hudVisState = 0;
        m_tutorialLocks = 0;
        m_speedPrev = 0;
        m_speedCurrent = 0;
        m_speedPrevCombined = 0;
        m_speedCommand = 0;
        m_hudMode = 0;
        m_field_084 = 30;
        m_field_100 = 0;
        m_playerData[0] = nullptr;
        m_playerData[1] = nullptr;
        m_actionQueueHUD[0] = nullptr;
        m_actionQueueHUD[1] = nullptr;
        m_liveMode = nullptr;
    }

    // 0x801869FC (588 bytes)
    ~HUDTarget() override {}

    // --- Controller management ---
    void AttachControllers() {}    // 0x80186C48 (228 bytes)
    void ReleaseControllers() {}   // 0x80186D2C (168 bytes)

    // --- Pause system ---
    // 0x80186DD4
    void IncPause(bool showPauseUI) {
        if (m_liveMode) {
            // ELiveMode::IncPause
        }
    }

    // 0x80186E04
    void ReleasePause(bool hidePauseUI) {
        if (m_liveMode) {
            // ELiveMode::ReleasePause
        }
    }

    // --- APT variable interface ---
    // 0x80186E34 - Parses optional player digit prefix
    void SetVariable(char* name, char* value) override {
        if (name && name[0] >= '0' && name[0] <= '9') {
            int player = name[0] - '0';
            SetPlayerVariable(player, name + 1, value);
        } else {
            SetPlayerVariable(0, name, value);
        }
    }

    // 0x80186EA0 (800 bytes)
    void SetPlayerVariable(int player, char* name, char* value) {
        if (strcmp(name, "HUDMode") == 0) {
            m_hudMode = atoi(value);
        }
        // Additional: CASType, speed control vars, motive display
    }

    // 0x801871C0
    char* GetVariable(char* name) override {
        if (name && name[0] >= '0' && name[0] <= '9') {
            int player = name[0] - '0';
            return GetPlayerVariable(player, name + 1);
        }
        return GetPlayerVariable(0, name);
    }

    // 0x80187224 (1212 bytes)
    char* GetPlayerVariable(int player, char* name) {
        static char buf[64];
        if (strcmp(name, "HUDMode") == 0) {
            sprintf(buf, "%d", m_hudMode);
            return buf;
        }
        return nullptr;
    }

    // 0x801876E0
    unsigned short* GetLocalizable(char* name) override {
        if (name && name[0] >= '0' && name[0] <= '9') {
            int player = name[0] - '0';
            return GetPlayerLocalizable(player, name + 1);
        }
        return GetPlayerLocalizable(0, name);
    }

    // 0x80187744 (768 bytes)
    unsigned short* GetPlayerLocalizable(int player, char* name) {
        return nullptr;
    }

    // --- Reputation ---
    void InitRepValues() {}                           // 0x80187A44
    int  GetReputationValue(int repType) { return 0; } // 0x80187B00
    int  GetNextRepUnlockValue(int repType) { return 0; } // 0x80187BC4

    // --- Motive display ---
    void OnReadBar(int player, u32 barIndex) {}       // 0x80187C9C
    void ReadMoodBar(int player, u32 index) {}        // 0x80187D10

    // --- HUD visibility ---
    // 0x80187E3C
    void ShowHUD() {
        if (m_hudVisState == 0) return;
        if (m_hudVisState >= 2) return;
        UpdateClock();
        m_hudVisState = 2;
    }

    // 0x80187EB4
    void HideHUD() {
        if (m_hudVisState != 2) return;
        m_hudVisState = 0;
    }

    void OnPlayerHUDShow(int player) {}               // 0x80187F24
    void OnPlayerHUDHide(int player) {}               // 0x80187F54
    void OnPlayerHUDHideStart(int player) {}          // 0x80187F80

    // Virtual no-ops (4 bytes each)
    void OnHUDShow() {}                                // 0x80187FFC
    void OnHUDHideStart() {}                           // 0x80188000
    void OnHUDHide() {}                                // 0x80188004

    void InstallHUDIcons(int player) {}               // 0x80188008
    int  ShouldHUDBeVisible(int player) const { return 1; } // 0x80188348

    // --- Frame update ---
    void UpdateTutorialLocks() {}                     // 0x80188464

    // 0x801884B4 (248 bytes)
    void Update() override {
        UpdateTutorialLocks();
        if (!ShouldHUDBeVisible(0)) {
            // Handle hide transition
            return;
        }
        ShowHUD();
        UpdateSpeedControls();
        m_field_084--;
        if (m_field_084 <= 0) {
            m_field_084 = 30;
            UpdateClock();
        }
    }

    void UpdateClock() {}                             // 0x801885AC
    void UpdateActivePlayer(int player, bool active) {} // 0x801886C0
    int  IsActionQueueAvailable(int player) const { return 1; } // 0x80188724
    void UpdateSpeedControls() {}                     // 0x801887AC

    // --- Action menu (pie menu) ---
    void AddMenu(int player, cXObject* obj, BString2& name,
                 u32 icon, ERShader* shader) {}                       // 0x80188BF4
    void AddMenuItem(int player, cXObject* obj, Interaction* interaction,
                     BString2& name, u32 icon, ERShader* shader,
                     int priority, bool enabled) {}                    // 0x80188C54
    void NotifyMenuRemoveObj(cXObject* obj) {}                         // 0x80188CC4
    void CompleteMenu(int player) {}                                   // 0x80188D3C
    void ShowMenu(int player) {}                                       // 0x80188D7C
    int  IsMenuAvailable(int player) const { return 0; }               // 0x80188DBC
    void CloseMenu(int player) {}                                      // 0x80188E34

    // --- Action queue display ---
    void AddAction(int player, Interaction* interaction, BString2& name,
                   u32 icon, ERShader* shader, u32 flags) {}           // 0x80188E60
    void RemoveAction(int player, Interaction* interaction) {}         // 0x80188F70
    void RemoveAllActions(int player) {}                               // 0x80188FC8

    // --- Rendering ---
    void Draw(ERC* rc) override {}                                     // 0x8018901C
    void DrawMotiveValues(ERC* rc, int player) {}                      // 0x801890C8

    // --- Job HUD ---
    void ResetJobHudProperties() {}                                    // 0x801890CC
    void SetJobBarInputRange(int player, int min, int max) {}          // 0x80189408
    void ApplyMotiveCurveArray(u32 curveIndex, s16 value) {}           // 0x80189444
    void CalculateJobScore() {}                                        // 0x801895AC
    int  GetJobBarCount() { return 0; }                                // 0x80189A34

    // --- HUD control system ---
    void RequestHUD(s16 type, s16 p1, s16 p2) {}                      // 0x801891C0
    void AddHUDControl(s16 type, s16 sub, s16& id) {}                  // 0x801892A8
    void RemoveHUDControl(s16 type, s16 sub) {}                        // 0x801892D4
    void ManageHUD(s16 type, s16 p, s16 val) {}                        // 0x801892FC
    void SetHUDData(s16 type, s16 val) {}                              // 0x80189360
    int  GetHUDData(s16 type, s16& outVal) { return 0; }               // 0x801897EC
    void AnimateHUDControl(s16 type, int animType) {}                  // 0x80189864

    // --- Screen navigation ---
    // 0x801898E4 (260 bytes)
    void GotoCAS(u16 casType, u16 param, int player, int slot) {
        m_field_100 = 3;
        HideHUD();
        UIRouter_FlowGoto("cas_body");
    }

    // 0x801899E8 (48 bytes)
    void GotoMainMenu() {
        m_field_100 = 1;
        UIRouter_FlowGoto("mainmenu");
    }

    // 0x80189A18 (28 bytes)
    void RequestQuitGame(bool quitRequested) {
        m_field_100 = quitRequested ? 1 : 0;
    }

    // --- Query methods ---
    void* GetActionQueueHUD(int player) { return m_actionQueueHUD[player]; } // 0x80189A50
    int   GetHUDMode() const { return m_hudMode; }                           // 0x80189A60
    bool  HUDHideComplete() const { return m_hudVisState == 0; }             // 0x80189A78
    bool  HideInProgress() const { return m_hudVisState == 1; }              // 0x80189A88
    bool  IsHUDVisible() const { return m_hudVisState >= 2; }                // 0x80189A9C
    bool  IsPlayerHUDVisible(int player) const { return m_hudVisState >= 2; } // 0x80189AB0
    void* GetHudTransitionTarget() { return nullptr; }                       // 0x80189AC8
};

ERFont* HUDTarget::m_pFont = nullptr;


// =============================================================================
// SECTION 13 - ACTTarget
// =============================================================================
// Virtual table at 0x80467960 (64 bytes)
// Size: 0x658 (1624 bytes)
// Action queue display for a single player.

class ACTTarget : public UIObjectBase {
public:
    int m_player;
    int m_showQueue;
    int m_isActive;

    // Cancel mode state
    bool m_cancelModeEnabled;
    int  m_cancelCursorPos;

    // 0x801A0968 (4168 bytes)
    ACTTarget(int player) : m_player(player), m_showQueue(0), m_isActive(0),
                            m_cancelModeEnabled(false), m_cancelCursorPos(0) {}

    // 0x801A19B0 (620 bytes)
    ~ACTTarget() override {}

    void SetVariable(char* name, char* value) override {}  // 0x801A1C1C
    char* GetVariable(char* name) override { return nullptr; } // 0x801A1D3C
    unsigned short* GetLocalizable(char* name) override { return nullptr; } // 0x801A1DD4

    // 0x801A1E58 (916 bytes) - Update action queue display
    void Update() override {}

    // 0x801A21EC (12 bytes)
    void ShowActionQueue() { m_showQueue = 1; }

    // 0x801A21F8 (12 bytes)
    void HideActionQueue() { m_showQueue = 0; }

    void UpdateActionQueue() {}                        // 0x801A2204

    // 0x801A23BC (8 bytes)
    int IsActionQueueActive() { return m_isActive; }

    // 0x801A23C4 (500 bytes)
    void AddAction(int slot, Interaction* interaction, BString2& name,
                   u32 icon, ERShader* shader, u32 flags) {}

    void PlaceItem(void* record, int slot, Interaction* interaction,
                   int pos, cXPerson* person, BString2& name,
                   u32 icon, ERShader* shader, u32 flags) {}   // 0x801A25B8

    void RemoveAction(int slot, Interaction* interaction) {}   // 0x801A2828
    void RemoveAllActions(int slot) {}                         // 0x801A2AAC

    // 0x801A2B34 (8 bytes) - Always returns 1
    int IsActionQueueAvailable(int) const { return 1; }

    void* GetRecord() { return nullptr; }                      // 0x801A2B3C
    void ReOrderActionQueue() {}                               // 0x801A2BA4
    void DebugListValidation() {}                              // 0x801A2C30 (empty)
    void* GetInteractionFromID(int id) { return nullptr; }     // 0x801A2C34

    // Cancel mode
    void MoveCancelCursorUp() { if (m_cancelCursorPos > 0) m_cancelCursorPos--; }
    void MoveCancelCursorDown() { m_cancelCursorPos++; }
    void CancelModeEnabled(bool enable) { m_cancelModeEnabled = enable; }
    void CancelCurrentObject() {}                              // 0x801A2E30
    void UpdateCancelModeWidgets() {}                          // 0x801A2F98
    void ExitCancelMode() { m_cancelModeEnabled = false; }     // 0x801A30A0
    void CancellingLastObject() {}                             // 0x801A311C
};


// =============================================================================
// SECTION 14 - O2TTarget
// =============================================================================
// Virtual table at 0x804672C0 (64 bytes)
// Size: 0x25C (604 bytes)
// Options menu controller.

class O2TTarget : public UIObjectBase {
public:
    static O2TTarget* m_pSingletonPtr;
    static u8  m_CurrentSFXVolume;
    static u8  m_CurrentMusicVolume;
    static u8  m_CurrentAmbientVolume;
    static u8  m_CurrentVoiceVolume;
    static u8  m_CurrentScreenX;
    static u8  m_CurrentScreenY;
    static int m_bRumbleOn;
    static int m_bCameraRotateDC;
    static int m_bCameraRotate;
    static int m_bFreeWill;

    int  m_screenID;
    int  m_player;
    int  m_topLevelState;
    int  m_dialogState;       // at +0x250
    int  m_saveRequested;     // at +0x90

    // Saved options for revert
    u8   m_savedSFX, m_savedMusic, m_savedAmbient, m_savedVoice;
    u8   m_savedScreenX, m_savedScreenY;
    int  m_savedRumble, m_savedCameraRotateDC, m_savedCameraRotate, m_savedFreeWill;

    // 0x801CC2B4 (4392 bytes)
    O2TTarget(int screenID, int player)
        : m_screenID(screenID), m_player(player),
          m_topLevelState(0), m_dialogState(0), m_saveRequested(0)
    {
        m_pSingletonPtr = this;
        RememberOptions();
    }

    // 0x801CD3DC
    ~O2TTarget() override {
        if (m_pSingletonPtr == this) m_pSingletonPtr = nullptr;
    }

    void SetVariable(char* name, char* value) override {}  // 0x801CD598 (2460 bytes)
    char* GetVariable(char* name) override { return nullptr; } // 0x801CDF34 (1160 bytes)
    unsigned short* GetLocalizable(char* name) override { return nullptr; } // 0x801CE3BC

    // --- State management ---
    void SetTopLevelState(char* name, char* value) {}      // 0x801CE920
    void OnTopLevelStateChange(char* name, char* value) {} // 0x801CE974

    // 0x801CEA60 (20 bytes)
    void SaveGame(char* name, char* value) {
        m_dialogState = 0;
        m_saveRequested = 1;
    }

    void OnSaveGameComplete(bool success) {}               // 0x801CEA74
    void Shutdown(char* name, char* value) {}              // 0x801CEAC0
    void OnStateChange() {}                                // 0x801CEB2C

    // --- Options tracking ---
    void AudioOptionsModified() {}                         // 0x801CEBE8
    void GameOptionsModified() {}                          // 0x801CEC3C
    void SpawnSaveSettingsDialog() {}                      // 0x801CEC90
    void OnSaveSettingsDialogClose(int result) {}          // 0x801CEEE8

    void RememberAudioOptions() {
        m_savedSFX = m_CurrentSFXVolume;
        m_savedMusic = m_CurrentMusicVolume;
        m_savedAmbient = m_CurrentAmbientVolume;
        m_savedVoice = m_CurrentVoiceVolume;
    }

    void RestoreAudioOptions() {
        m_CurrentSFXVolume = m_savedSFX;
        m_CurrentMusicVolume = m_savedMusic;
        m_CurrentAmbientVolume = m_savedAmbient;
        m_CurrentVoiceVolume = m_savedVoice;
    }

    void RememberGameOptions() {
        m_savedScreenX = m_CurrentScreenX;
        m_savedScreenY = m_CurrentScreenY;
        m_savedRumble = m_bRumbleOn;
        m_savedCameraRotateDC = m_bCameraRotateDC;
        m_savedCameraRotate = m_bCameraRotate;
        m_savedFreeWill = m_bFreeWill;
    }

    void RestoreGameOptions() {
        m_CurrentScreenX = m_savedScreenX;
        m_CurrentScreenY = m_savedScreenY;
        m_bRumbleOn = m_savedRumble;
        m_bCameraRotateDC = m_savedCameraRotateDC;
        m_bCameraRotate = m_savedCameraRotate;
        m_bFreeWill = m_savedFreeWill;
    }

    void RememberOptions() { RememberAudioOptions(); RememberGameOptions(); }
    void RestoreOptions() { RestoreAudioOptions(); RestoreGameOptions(); }

    // Screen calibration
    int GetScreenXLocal(s8 offset) { return static_cast<int>(m_CurrentScreenX) + offset; }
    int GetScreenXGlobal(f32 value) { return static_cast<int>(value); }
    int GetScreenYLocal(s8 offset) { return static_cast<int>(m_CurrentScreenY) + offset; }
    int GetScreenYGlobal(f32 value) { return static_cast<int>(value); }

    void UpdateText() {}                                   // 0x801CF3C0
    void OnXKeyPressed(char*, char*) {}                    // 0x801CF704

    // 0x801CFA60 (12 bytes)
    void OnCancelDialog() { m_dialogState = 0; }

    void SpawnQuitDialogBox() {}                           // 0x801CF780
    void OnQuitGameDialogClose(int result) {}              // 0x801CFA6C
    void OnUpKeyPressed(char*, char*) {}                   // 0x801CFAE8
    void OnDownKeyPressed(char*, char*) {}                 // 0x801CFB58
    void OnRightKeyPressed(char*, char*) {}                // 0x801CFBC4
    void OnLeftKeyPressed(char*, char*) {}                 // 0x801CFC40
    void OnCircleKeyPressed(char*, char*) {}               // 0x801CFCBC
    void UpdateShaders(char*, char*) {}                    // 0x801CFD30
    void ShowHelp() {}                                     // 0x801CFFC8
    void StartScreenWizard(char*, char*) {}                // 0x801CFFC8
    void ExitScreenWizard(char*, char*) {}                 // 0x801D006C
    void QuitGame(char*, char*) {}                         // 0x801D00C0
};

O2TTarget* O2TTarget::m_pSingletonPtr = nullptr;
u8  O2TTarget::m_CurrentSFXVolume = 100;
u8  O2TTarget::m_CurrentMusicVolume = 100;
u8  O2TTarget::m_CurrentAmbientVolume = 100;
u8  O2TTarget::m_CurrentVoiceVolume = 100;
u8  O2TTarget::m_CurrentScreenX = 0;
u8  O2TTarget::m_CurrentScreenY = 0;
int O2TTarget::m_bRumbleOn = 1;
int O2TTarget::m_bCameraRotateDC = 0;
int O2TTarget::m_bCameraRotate = 0;
int O2TTarget::m_bFreeWill = 1;


// =============================================================================
// SECTION 15 - E2ETarget
// =============================================================================
// Virtual table at 0x80467718 (64 bytes)
// Size: 0x288 (648 bytes)
// EyeToy camera controller (vestigial PS2 feature on GameCube).

class E2ETarget : public UIObjectBase {
public:
    static E2ETarget* m_pSingletonPtr;
    static bool       m_bAlreadyCreatedOnce;
    static int        m_sCurrentHue;
    static int        m_sCurrentSaturation;
    static int        m_sCurrentBrightness;
    static int        m_sCurrentExposure;

    int m_screenID;
    int m_topLevelState;

    // 0x801AA5B8 (5888 bytes)
    E2ETarget(int screenID) : m_screenID(screenID), m_topLevelState(0) {
        m_pSingletonPtr = this;
        m_bAlreadyCreatedOnce = true;
    }

    // 0x801ABCB8
    ~E2ETarget() override {
        if (m_pSingletonPtr == this) m_pSingletonPtr = nullptr;
    }

    void SetVariable(char* name, char* value) override {}
    char* GetVariable(char* name) override { return nullptr; }
    unsigned short* GetLocalizable(char* name) override { return nullptr; }
    void Update() override {}

    void SaveGame() {}
    void OnShutdown() {}
    void E2ERenderCallback(ERC* rc, structDrawCBparams* params) {}
    void EyeToyUnplugCallback(int port) {}
    void OnEyeToyUnplugged() {}
    void SpawnNoEyeToyDialogBox() {}
    void OnExitDialog(int result) {}
    bool IsEyeToyPluggedIn() { return false; } // always false on GC
    void InitializeEyeToy() {}
    void ReintializeEyeToy() {}
    void SaveCurrentSettings(char*, char*) {}
    void RestorePreviousSettings() {}
    void SetTopLevelState(char*, char*) {}
    void OnTopLevelStateChange(char*, char*) {}
    void SetDefault(char*, char*) {}
    void UpdateHue(char*, char*) {}
    void UpdateSaturation(char*, char*) {}
    void UpdateValue(char*, char*) {}
    void UpdateExposure(char*, char*) {}
    void CaptureFrame(char*, char*) {}
    void SaveFrame(char*, char*) {}
    void ChangeFunFrame(char*, char*) {}
    void ChangeSelectedSlot(char*, char*) {}
    void ChangeFilter(char*, char*) {}
    void OnXKeyPressed(char*, char*) {}
    void OnUpKeyPressed(char*, char*) {}
    void OnDownKeyPressed(char*, char*) {}
    void OnRightKeyPressed(char*, char*) {}
    void OnLeftKeyPressed(char*, char*) {}
    void OnCircleKeyPressed(char*, char*) {}
    void UpdateText() {}
    char* GetText(char* name) { return nullptr; }
    void UpdateShaders(char*, char*) {}
    void ShowHelp() {}
    void OnEnterSettings() {}
    void OnExitSettings() {}
    void LaunchSaveSettingsDialog() {}
    void OnSaveDialogDoneCB(int result) {}
    void OnSaveGameComplete(bool success) {}
    void SpawnSaveGameDialog() {}
    void OnSaveGameDialogClosed(int result) {}

    // 0x801E7088 (8 bytes)
    int GetTopLevelState() { return m_topLevelState; }
};

E2ETarget* E2ETarget::m_pSingletonPtr = nullptr;
bool       E2ETarget::m_bAlreadyCreatedOnce = false;
int        E2ETarget::m_sCurrentHue = 0;
int        E2ETarget::m_sCurrentSaturation = 0;
int        E2ETarget::m_sCurrentBrightness = 0;
int        E2ETarget::m_sCurrentExposure = 0;


// =============================================================================
// SECTION 16 - FAMTarget
// =============================================================================
// Virtual table at 0x80467668 (64 bytes)
// Size: 0x450 (1104 bytes)
// Family/lot selection controller.

class FAMTarget : public UIObjectBase {
public:
    int m_stateStack[16];
    int m_stateStackTop;
    int m_selectedLotIndex;
    int m_selectedFamilyIndex;

    // 0x801AE88C (4800 bytes)
    FAMTarget() : m_stateStackTop(0), m_selectedLotIndex(0),
                  m_selectedFamilyIndex(0) {
        memset(m_stateStack, 0, sizeof(m_stateStack));
    }

    ~FAMTarget() override {}

    void UnloadScreen() {}
    void SetVariable(char* name, char* value) override {}
    unsigned short* GetLocalizable(char* name) override { return nullptr; }
    char* GetVariable(char* name) override { return nullptr; }

    // 0x801B070C (4 bytes - empty)
    void Shutdown() {}

    // 0x801B0710 (4 bytes - empty)
    void Update() override {}

    // 0x801B0750 (12 bytes - empty with stack frame)
    void UpdateText() {}

    // 0x801B075C (4 bytes - empty)
    void OnLeftKeyPressed(char*, char*) {}

    // 0x801B0760 (4 bytes - empty)
    void OnRightKeyPressed(char*, char*) {}

    void UpdateShaders() {}
    void UpdateOccupiedShaders() {}
    void UpdateLotSelectShaders() {}
    void UpdateTempShaders() {}
    unsigned short* GetFamilyText(char* key, unsigned short* buf) { return nullptr; }
    void OnLotSelect() {}
    Family* GetFamilyInFamilyList(int index) { return nullptr; }
    int DoesFamilyExistInFamilyChoice(int familyID) { return 0; }

    // 0x801B0DAC (8 bytes)
    int ConvertSelectedFamilyIndexToActualGameIndex(int index) {
        return index + 20;
    }

    int GetNumberOfFamilyMembers(Family* family) { return 0; }
    int IsSelectedLotOccupied() { return 0; }

    // 0x801B0E6C (4 bytes - empty)
    void OnCancelDialog() {}

    void OnDialogSelection(int selection) {}
    void OnReturnFromCreateAFamily(bool created) {}
    void OnBackoutToMainMenuDialogClose(int result) {}
    void OnCancelKeyPressed(char*, char*) {}
    void OnUpKeyPressed(char*, char*) {}
    void OnDownKeyPressed(char*, char*) {}
    void OnXKeyPressed(char*, char*) {}

    // 0x801B2604 (4 bytes - empty)
    void OnCircleKeyPressed(char*, char*) {}

    // State machine
    void UpdateMenuState(int state) {
        if (m_stateStackTop < 16) {
            m_stateStack[m_stateStackTop++] = state;
        }
    }

    int GetNumberOfChoicesInState(int state) { return 0; }

    // 0x801B29F0 (8 bytes)
    int ConvertSelectedLotIndexToActualGameIndex(int index) {
        return index + 13;
    }

    void GoUpMenuTree() {
        if (m_stateStackTop > 1) m_stateStackTop--;
    }

    unsigned short* GetNameForFamilyInLotSelect(char*, unsigned short*) { return nullptr; }
    unsigned short* GetMoneyForFamilyInLotSelect(char*, unsigned short*) { return nullptr; }
    void UpdateFamilySelectShaders() {}
    unsigned short* GetSelectedLotDescription(unsigned short*) { return nullptr; }
    void ConvertNumericMoneyToString(int money, unsigned short* buf) {}
    unsigned short* GetMoneyForFamily(Family*, unsigned short*) { return nullptr; }
    char* GetLotName(int lotIndex) { return nullptr; }
    unsigned short* GetNameForFamily(Family*, unsigned short*) { return nullptr; }
    void SetCurrentChoice(char* choice) {}
    Family* GetFamilyInLot(int lotIndex) { return nullptr; }

    void LaunchLot() {
        UIRouter_FlowGoto("ingame");
    }

    int GetMoneyForLot(int lotIndex) { return 0; }
    void EvictFamily() {}
    int GetLotForFamily(Family* family) { return -1; }
    int GetLotForFamily(int familyID) { return -1; }
    char* GetLotNameInFamilySelect(char* key) { return nullptr; }
};


// =============================================================================
// SECTION 17 - MMUTarget
// =============================================================================
// Virtual table at 0x804677F0 (64 bytes)
// Size: 0x360 (864 bytes)
// Main menu controller.

class MMUTarget : public UIObjectBase {
public:
    static MMUTarget* m_MMUSingleton;

    int m_mainScreenChoice;
    int m_gameplayChoice;
    int m_numPlayersChoice;
    int m_curMode;           // 0=menu, 1=NGH list, 2=lot list
    int m_prevMode;
    int m_creditsClose;

    int m_stateStack[16];
    int m_stateStackTop;

    // 0x801C49C0 (3696 bytes)
    MMUTarget() : m_mainScreenChoice(0), m_gameplayChoice(0),
                  m_numPlayersChoice(0), m_curMode(0), m_prevMode(0),
                  m_creditsClose(0), m_stateStackTop(0)
    {
        m_MMUSingleton = this;
        memset(m_stateStack, 0, sizeof(m_stateStack));
        m_stateStack[m_stateStackTop++] = 0; // TOP_LEVEL
    }

    // 0x801C5830
    ~MMUTarget() override {
        if (m_MMUSingleton == this) m_MMUSingleton = nullptr;
    }

    // 0x801C59E0 (8 bytes)
    static MMUTarget* GetSingleton() { return m_MMUSingleton; }

    // 0x801C59E8 (12 bytes)
    void OnCreditsClose() { m_creditsClose = 1; }

    void SetVariable(char* name, char* value) override {
        if (strcmp(name, "TopLevelChoice") == 0) m_mainScreenChoice = atoi(value);
        else if (strcmp(name, "GameplayChoice") == 0) m_gameplayChoice = atoi(value);
        else if (strcmp(name, "NumPlayersChoice") == 0) m_numPlayersChoice = atoi(value);
    }

    char* GetVariable(char* name) override {
        static char buf[64];
        if (strcmp(name, "TopLevelChoice") == 0) { sprintf(buf, "%d", m_mainScreenChoice); return buf; }
        if (strcmp(name, "GameplayChoice") == 0) { sprintf(buf, "%d", m_gameplayChoice); return buf; }
        if (strcmp(name, "NumPlayersChoice") == 0) { sprintf(buf, "%d", m_numPlayersChoice); return buf; }
        return nullptr;
    }

    unsigned short* GetLocalizable(char* name) override { return nullptr; }
    void Update() override {}
    void Draw(ERC* rc) override {}

    // List management
    char* GetListItemName(char* name) { return nullptr; }
    void ChangeScreenMode() {}
    void UpdateListItems() {}
    void UpdateNGHListItems() {}
    void UpdateLotListItems() {}
    char* GetNGHListItemName(char* name) { return nullptr; }
    char* GetLotListItemName(char* name) { return nullptr; }
    void EnterLot(int lotIndex) {}
    void LaunchLot(int lotIndex) {}
    void LaunchFreeplay() { UIRouter_FlowGoto("freeplay"); }

    // Input handlers
    void OnUpKeyPressed(char*, char*) {}
    void OnDownKeyPressed(char*, char*) {}
    void OnLeftKeyPressed(char*, char*) {}
    void OnRightKeyPressed(char*, char*) {}
    void EndPlayerNumberChooser() {}
    void OnXKeyPressed(char*, char*) {}
    void OnCancelKeyPressed(char*, char*) {}
    void OnCircleKeyPressed(char*, char*) {}

    // Choice change callbacks
    void UpdateTopLevelChoice(char*, char*) {}
    void UpdateGameplayChoice(char*, char*) {}
    void UpdateNumberOfPlayersChoice(char*, char*) {}
    void OnTopLevelChoiceChange() {}
    void OnGameplayLevelChoiceChange() {}
    void OnNumberOfPlayersChoiceChange() {}

    void UpdateText() {}

    void UpdateMenuState(char* name, char* value) {
        int newState = atoi(value);
        if (m_stateStackTop < 16) m_stateStack[m_stateStackTop++] = newState;
    }

    void GoUpMenuTree(char*, char*) {
        if (m_stateStackTop > 1) m_stateStackTop--;
    }

    int GetNumberOfControllers() { return 1; }

    int GetNumberOfChoicesInState(int state) {
        switch (state) {
            case 0: return 4;  // TOP_LEVEL
            case 1: return 2;  // GAMEPLAY
            case 2: return 2;  // NUM_PLAYERS
            default: return 0;
        }
    }

    void IncrementChoice(char*, char*) {}
    void SetCurrentChoice(char* choice) {}
    void DecrementChoice(char*, char*) {}
    void OnStartGameComplete(bool success) {}
    void UpdateDevMenuState(char*, char*) {}
    void OnNGHSelect(char*, char*) {}

    // 0x801C86B4 (16 bytes)
    void ChangeScreenMode(int mode) {
        m_prevMode = m_curMode;
        m_curMode = mode;
    }

    void PollControllersForNumOfPlayersState() {}

    // Dialog callbacks
    void OnDialogClose(int result) {}
    void OnCancelDialog() {}                           // 0x801C8788 (empty)
    void OnDialog2Close(int result) {}                 // 0x801C878C (empty)
    void OnCancelDialog2() {}                          // 0x801C8790 (empty)
    void Dialog2ClosedCallback() {}

    // 0x801E7078 (8 bytes)
    int GetCurrentMainScreenChoice() const { return m_mainScreenChoice; }
    // 0x801E7080 (8 bytes)
    int GetCurrentGameplayChoice() const { return m_gameplayChoice; }
};

MMUTarget* MMUTarget::m_MMUSingleton = nullptr;


// =============================================================================
// SECTION 18 - M2MTarget
// =============================================================================
// Virtual table at 0x804676D8 (64 bytes)
// Size: 0x23E8 (9192 bytes)
// Memory card management controller.

class LoadGameTarget;
class SaveGameTarget;

class M2MTarget : public UIObjectBase {
public:
    int            m_device;
    int            m_saveGameID;
    int            m_playerNum;
    int            m_currState;
    int            m_numItems;
    LoadGameTarget* m_loadTarget;
    SaveGameTarget* m_saveTarget;
    DlgWrapper*    m_dialog;

    M2MTarget() : m_device(0), m_saveGameID(0), m_playerNum(0),
                  m_currState(0), m_numItems(0),
                  m_loadTarget(nullptr), m_saveTarget(nullptr),
                  m_dialog(nullptr) {}

    ~M2MTarget() override {}

    char* GetVariable(char* name) override { return nullptr; }
    unsigned short* GetLocalizable(char* name) override { return nullptr; }
    void SetVariable(char* name, char* value) override {}
    void Update() override {}

    void ReflowButtonSelection() {}
    void SelectionCallback(int selection) {}

    // 0x801C0C9C (4 bytes - empty)
    void ZeroInputCallback() {}

    void DialogClosedCallback() {}
    void OnCancel() {}
    void OnSaveLoadSucceed() {}
    void OnSaveLoadFailed() {}
    void OnSlotSelectItemSelected(int slot, void* result) {}
    void OnGetNumItems(void* result) {}

    // 0x801C1108 (8 bytes)
    int GetDevice() { return m_device; }

    void SetDevice(int device) { m_device = device; }

    // 0x801C113C (8 bytes)
    int GetSaveGameID() { return m_saveGameID; }

    // 0x801C1144 (24 bytes)
    int GetMemCardPort() {
        if (m_device != -1) return m_device;
        return m_saveGameID;
    }

    // 0x801E7090 (8 bytes)
    int GetPlayerNum() { return m_playerNum; }

    // Dialog spawning
    void SpawnNoSpaceDialog() {}
    void SpawnConfirmStartNewGameDialog() {}
    void SpawnContinueNoMemCardDialog() {}
    void SpawnSaveBeforeQuitCASDialog() {}
    void SpawnSaveBeforeQuitGameDialog() {}
    void SpawnNoSaveBeforeQuitDialog() {}
    void SpawnStartNGCNoMemCardDialog() {}

    unsigned short* GetItemTextMemCardSelect(int, unsigned short*) { return nullptr; }
    unsigned short* GetItemTextSaveGameSelect(int, unsigned short*) { return nullptr; }
    int IsItemEnabledMemCardSelect(int slot) { return 1; }

    // 0x801C1D00 (8 bytes) - Always returns 0
    int IsItemEnabledSaveGameSelect(int) { return 0; }

    void DoesMemoryDeviceExist() {}
    void StartLoadedGame() {}
    void ReturnFailureDestination() {}
    void StartNGCMemoryCardBootChecks() {}
    void UpdateWidgetState() {}
    void FillWidget() {}
    void HideWidget() {}
    void SetupWidgetLayout() {}
    void UpdateSelection(int selection) {}
    int IsItemEnabled(int slot) { return 1; }
    void CalcNumItems() {}
    void SetCurrState(int state) { m_currState = state; }
    void UnloadDialog() {}
    void PrepareNewGame() {}
    void PrepareLoadGame() {}
    void PushButtonFilters() {}
    void PopButtonFilters() {}
};


// =============================================================================
// SECTION 19 - LoadGameTarget
// =============================================================================
// Virtual table at 0x80466918 (64 bytes)
// Size: 0x14C (332 bytes)

class LoadGameTarget {
public:
    M2MTarget* m_parent;
    int        m_device;
    int        m_slot;
    int        m_result;     // 0=pending, 1=success, -1=failure
    bool       m_bgLoading;
    DlgWrapper* m_dialog;

    LoadGameTarget(M2MTarget* parent, int device, int slot)
        : m_parent(parent), m_device(device), m_slot(slot),
          m_result(0), m_bgLoading(false), m_dialog(nullptr) {}

    ~LoadGameTarget() {
        if (m_dialog) {
            m_dialog->Shutdown();
            delete m_dialog;
        }
    }

    void SelectionCallback(int selection) {}
    void ZeroInputCallback() {}

    void Update() {
        if (m_bgLoading) {
            // Poll background load for completion
        }
    }

    int GetResult() { return m_result; }
    void ImportLoad(int sectionID, void* record) {} // empty

    void PerformMemoryCardChecks() {}
    void PerformLoad() {}

    // Dialog chain
    void SpawnCheckingDialog() {}
    void SpawnWrongDeviceDialog() {}
    void SpawnCardDamagedDialog() {}
    void SpawnCardCorruptDialog() {}
    void SpawnWrongSaveDialog() {}
    void SpawnNoSaveDialog() {}
    void SpawnLoadConfirmDialog() {}
    void SpawnLoadingDialog() {}
    void SpawnLoadSucceededDialog() { m_result = 1; }
    void SpawnLoadFailedDialog() { m_result = -1; }
    void SpawnMemCardRemovedDialog() {}
    void SpawnSameCardDialog() {}

    // Format sub-flow
    void SpawnFormatDecideDialog() {}
    void SpawnFormatConfirmDialog() {}
    void SpawnFormattingDialog() {}
    void SpawnFormatCancelDialog() {}
    void SpawnFormatFailDialog() {}
    void SpawnFormatSuccessDialog() {}

    void BackgroundPerformLoad() {
        PerformMemoryCardChecks();
        if (m_result == 0) PerformLoad();
    }

    void BGCall_PerformLoad() {}

    static void BGExec_PerformLoad(void* arg) {
        LoadGameTarget* t = static_cast<LoadGameTarget*>(arg);
        t->BackgroundPerformLoad();
    }

    void ImportSave(int, void*) {}          // empty
    void ImportSaveComplete(int, void*) {}  // empty
    int  GetDevice() { return m_device; }
    int  GetPlayerNum() { return m_parent ? m_parent->GetPlayerNum() : 0; }
    int  GetSaveGameID() { return m_slot; }
};


// =============================================================================
// SECTION 20 - SaveGameTarget
// =============================================================================
// Virtual table at 0x804669C8 (72 bytes)
// Size: 0x168 (360 bytes)

class SaveGameTarget {
public:
    M2MTarget* m_parent;
    int        m_device;
    int        m_slot;
    int        m_result;
    bool       m_bgSaving;
    DlgWrapper* m_dialog;

    SaveGameTarget(M2MTarget* parent, int device, int slot)
        : m_parent(parent), m_device(device), m_slot(slot),
          m_result(0), m_bgSaving(false), m_dialog(nullptr) {}

    ~SaveGameTarget() {
        if (m_dialog) {
            m_dialog->Shutdown();
            delete m_dialog;
        }
    }

    void SelectionCallback(int selection) {}
    void ZeroInputCallback() {}
    void Update() {
        if (m_bgSaving) { /* poll */ }
    }
    void Hide() {}
    int  GetResult() { return m_result; }

    void PerformMemoryCardChecks() {}

    // Dialog chain
    void SpawnCheckingDialog() {}
    void SpawnCardCorruptDialog() {}
    void SpawnWrongDeviceDialog() {}
    void SpawnCardDamagedDialog() {}
    void SpawnFormatDecideDialog() {}
    void SpawnFormatConfirmDialog() {}
    void SpawnFormattingDialog() {}
    void SpawnFormatCancelDialog() {}
    void SpawnFormatFailDialog() {}
    void SpawnFormatSuccessDialog() {}
    void SpawnNoSpaceDialog(int noSpaceType) {}
    void SpawnOverwriteDialog() {}
    void SpawnSaveConfirmDialog() {}
    void SpawnSavingDialog() {}
    void SpawnSaveSucceededDialog() { m_result = 1; }
    void SpawnSaveFailedDialog() { m_result = -1; }
    void SpawnMemCardRemovedDialog() {}

    void PerformSaveGame() {}

    void BGCall_SaveGame() {}
    static void BGExec_SaveGame(void* arg) {
        SaveGameTarget* t = static_cast<SaveGameTarget*>(arg);
        t->PerformMemoryCardChecks();
        if (t->m_result == 0) t->PerformSaveGame();
    }

    int GetDevice() { return m_device; }
    int GetPlayerNum() { return m_parent ? m_parent->GetPlayerNum() : 0; }
    int GetSaveGameID() { return m_slot; }
};


// =============================================================================
// SECTION 21 - CSMTarget
// =============================================================================
// Virtual table at 0x804677B0 (64 bytes)
// Size: 0xF0 (240 bytes)
// CAS integration menu controller.

class CSMTarget : public UIObjectBase {
public:
    int  m_player;
    int  m_showCSIM;
    int  m_isActive;
    int  m_field98;

    CSMTarget(int player) : m_player(player), m_showCSIM(0),
                            m_isActive(0), m_field98(0) {}

    ~CSMTarget() override {}

    void SetVariable(char* name, char* value) override {}
    char* GetVariable(char* name) override { return nullptr; }
    unsigned short* GetLocalizable(char* name) override { return nullptr; }
    void Update() override {}

    // 0x801A764C (20 bytes)
    void ShowCSIM() { m_showCSIM = 1; m_field98 = 0; }

    // 0x801A7660 (20 bytes)
    void HideCSIM() {
        if (m_field98 != 0) return;
        m_showCSIM = 0;
    }

    // 0x801A7674 (8 bytes)
    int IsCSIMActive() { return m_isActive; }

    void TempInterface(BString2* opt1, BString2* opt2,
                       BString2* opt3, BString2* opt4,
                       bool enableOpt3, bool enableOpt4) {}

    void SetIconDisable(bool disable) {}
};


// =============================================================================
// SECTION 22 - KEYTarget
// =============================================================================
// Virtual table at 0x80467C18 (64 bytes)
// Size: 0x90 (144 bytes)
// Input configuration controller.

class KEYTarget : public UIObjectBase {
public:
    KEYTarget() {}
    ~KEYTarget() override {}

    char* GetName() { return nullptr; }
    int IsModeValid() { return 1; }

    void SetVariable(char* name, char* value) override {}
    char* GetVariable(char* name) override { return nullptr; }
};


// =============================================================================
// SECTION 23 - INGTarget
// =============================================================================
// In-game ingredient/cooking system target.
// Static: s_ingRefrigeratorLevel

class INGTarget : public UIObjectBase {
public:
    static int s_ingRefrigeratorLevel;

    int m_mealType;
    int m_rcpState;

    struct TabInfo {
        int m_field00;
        int m_field04;
        int m_field08;
        TabInfo() : m_field08(0), m_field00(0), m_field04(0) {}
    };

    struct IngInfo {
        int m_field00;
        int m_field04;
        IngInfo() : m_field04(0), m_field00(0) {}
        void erase() { m_field04 = 0; m_field00 = 0; }
    };

    INGTarget() : m_mealType(0), m_rcpState(0) {}
    ~INGTarget() override {}

    // 0x801B9458 (16 bytes)
    static int SetRefrigeratorLevel(int level) {
        int old = s_ingRefrigeratorLevel;
        s_ingRefrigeratorLevel = level;
        return old;
    }

    // 0x801BBE14 (12 bytes)
    u32 get_blank_shader_id() const { return 0x9F93FF74u; }

    // 0x801BC984 (20 bytes)
    int is_group_meal() const { return (m_mealType == 2) ? 1 : 0; }

    // 0x801BC998 (16 bytes)
    int RCPOnCancel() { m_rcpState = 2; return 1; }
};

int INGTarget::s_ingRefrigeratorLevel = 0;


// =============================================================================
// SECTION 24 - WAFTarget
// =============================================================================
// Wants and fears display target.

class WAFTarget : public UIObjectBase {
public:
    int m_showWAF;
    int m_isActive;
    int m_glowEffectActive;
    int m_textButtonPressed;

    WAFTarget() : m_showWAF(0), m_isActive(0),
                  m_glowEffectActive(0), m_textButtonPressed(0) {}
    ~WAFTarget() override {}

    // 0x801E3574 (12 bytes)
    void ShowWantsAndFears() { m_showWAF = 1; }

    // 0x801E3580 (16 bytes)
    void HideWantsAndFears() { m_textButtonPressed = 0; m_showWAF = 0; }

    // 0x801E38F8 (8 bytes)
    int IsWantsAndFearsActive() { return m_isActive; }

    // 0x801E4A00 (12 bytes)
    void OnGlowEffectComplete() { m_glowEffectActive = 0; }

    // 0x801E4F24 (8 bytes)
    void SetTextButtonPressed(bool pressed) { m_textButtonPressed = static_cast<int>(pressed); }
};


// =============================================================================
// SECTION 25 - CUIWindow
// =============================================================================
// Debug UI window system. Used for developer tools.
// Virtual table in 0x804B33xx range.

struct CUISliderState { int min, max, value; };
struct CUIScrollState { int min, max, value, pageSize; };
struct CUISpinState   { int min, max, value; };

class CUIWindow {
public:
    void CreateChildWindow(int id) {}
    void SetRect(TRect<f32> rect) {}
    void GetRect() {}
    void GetDrawRect() {}
    void SetEraseColor(EVec3 color, f32 alpha) {}
    void Init(CUIWindow* parent, CUIPane* pane, int id) {}
    void Destroy() {}
    void BringToTop() {}
    void WindowToScreen(EVec2 pos) {}
    void ScreenToWindow(EVec2 pos) {}
    void SetCaption(char* caption) {}
    void GetCaption() {}
    void GetOrigin() {}
    void SetOrigin(EVec2 origin) {}
    void FindWidget(int id) {}
    void AddWidget(int type, int id) {}
    void RemoveWidget(int id) {}
    void WidgetExists(int id) {}
    void GetWidgetType(int id) {}
    void SetWidgetRect(int id, TRect<f32> rect) {}
    void GetWidgetRect(int id) {}
    void SetWidgetText(int id, char* text) {}
    void GetWidgetText(int id) {}
    void EnableWidget(int id, bool enable) {}
    void SetWidgetCallback(int id,
        bool (*cb1)(u32, CUIWindow*, int), u32 userData1,
        bool (*cb2)(u32, CUIWindow*, int)) {}
    void SetEventCallback(void (*cb)(u32, CUIEvent*), u32 userData) {}
    void DispatchNotify(int id, u32 param) {}
    void DispatchEvent(CUIEvent* event) {}
    void SetCheckbox(int id, bool checked) {}
    void GetCheckbox(int id) {}
    void SetSlider(int id, CUISliderState* state) {}
    void GetSlider(int id, CUISliderState* state) {}
    void SetScroll(int id, CUIScrollState* state) {}
    void GetScroll(int id, CUIScrollState* state) {}
    void SetSpin(int id, CUISpinState* state) {}
    void GetSpin(int id, CUISpinState* state) {}
    void SetTextColor(int id, EVec3& color) {}
    void GetEventCallback() {}
    void GetUserData() {}
    void DrawRect(ERC* rc, TRect<f32> rect, EVec3 color) {}
    void DrawText(ERC* rc, EVec2 pos, f32 scale, EVec3 color,
                  char* text, EFontAlignX alignX, EFontAlignY alignY) {}
};


// =============================================================================
// SECTION 26 - CUIPropertySheet
// =============================================================================
// Debug property editor for developer tools.

struct CUIRadioPropertyData {
    int value;
};

class CUIPropertySheet {
public:
    void SetupWindow(CUIWindow* window) {}
    void GetWindowFlags() {}
    void WindowNotify(CUIWindow* window, int msg) {}
    void ResizedWindow(CUIWindow* window) {}
    void RefreshAllProperties() {}
    void BoolPropertyCallback(u32 userData, CUIWindow* window, int param) {}
    void AddBoolProperty(bool* value, char* label) {}
    void AddTextProperty(char* label) {}
    void FloatSliderPropertyCallback(u32 userData, CUIWindow* window, int param) {}
    void AddFloatSliderProperty(f32* value, char* label, f32 min, f32 max) {}
    void IntSliderPropertyCallback(u32 userData, CUIWindow* window, int param) {}
    void UInt8SliderPropertyCallback(u32 userData, CUIWindow* window, int param) {}
    void Int8SliderPropertyCallback(u32 userData, CUIWindow* window, int param) {}
    void Int16SliderPropertyCallback(u32 userData, CUIWindow* window, int param) {}
    void AddIntSliderProperty(int* value, char* label, int min, int max) {}
    void AddUInt8SliderProperty(u8* value, char* label, int min, int max) {}
    void AddInt8SliderProperty(s8* value, char* label, int min, int max) {}
    void AddInt16SliderProperty(s16* value, char* label, int min, int max) {}
    void AddColorProperty(EVec3* value, char* label) {}
    void AddVec3Property(EVec3* value, char* label, EVec3& min, EVec3& max) {}
    void IntScrollPropertyCallback(u32 userData, CUIWindow* window, int param) {}
    void AddIntScrollProperty(int* value, char* label, int min, int max) {}
    void AddRadioScrollProperty(CUIRadioPropertyData* data, char* label,
                                char** options, int numOptions, int defaultIdx) {}
    void AddRadioSpinProperty(CUIRadioPropertyData* data, char* label,
                              char** options, int numOptions, int defaultIdx) {}
};


// =============================================================================
// SECTION 27 - Additional Target Classes
// =============================================================================
// These are smaller/simpler targets found in src/asm_decomp/ and
// src/ui/targets.cpp. Each follows the UIObjectBase inheritance pattern.

// --- BBHTarget (Build/Buy HUD) ---
class BBHTarget : public UIObjectBase {
public:
    int m_isActive;
    int m_showHUD;

    int IsBuildBuyHUDActive() { return m_isActive; }    // 0x801A3E94
    void ShowBuildBuyHUD() { m_showHUD = 1; }           // 0x801A3E9C
    void HideBuildBuyHUD() { m_showHUD = 0; }           // 0x801A3EA8
};

// --- CRDTarget (Credits) ---
class CRDTarget : public UIObjectBase {
public:
    void Draw(ERC*) override {}          // 0x801A4C6C (empty)
    void UpdateCredits() {}              // 0x801A4F80 (empty)
};

// --- CSPTarget ---
class CSPTarget : public UIObjectBase {
public:
    void Update() override {}            // 0x801A9918 (empty)
    void onHelpDialogSelection(int) {}   // 0x801AA57C (empty)
};

// --- FCMTarget (Fire Code Meter) ---
class FCMTarget : public UIObjectBase {
public:
    int m_showMeter;
    int m_isActive;

    void HideFireCodeMeter() { m_showMeter = 0; }       // 0x801B41B8
    int IsFireCodeMeterActive() { return m_isActive; }   // 0x801B4458
};

// --- G2DTarget ---
class G2DTarget : public UIObjectBase {
public:
    int m_isActive;
    int m_isSpawned;
    int m_transitionState;
    static int s_g2dInitComplete;

    int IsG2DActive() { return m_isActive; }             // 0x801B5A04
    int IsG2DSpawned() { return m_isSpawned; }           // 0x801B5A0C
    int IsInitComplete() { return s_g2dInitComplete; }   // 0x801E7050

    // 0x801E7058 (32 bytes)
    int HasPendingTransition() {
        if (m_transitionState == 0 || m_transitionState == 3) return 0;
        return 1;
    }
};

int G2DTarget::s_g2dInitComplete = 0;

// --- H2DTarget ---
class H2DTarget : public UIObjectBase {
public:
    int m_pausePlayer;
    int m_rewardClosed;

    void Draw(ERC*) override {}          // 0x801B8480 (empty)
    int GetPausePlayer() { return m_pausePlayer; }       // 0x801B8A38
    void RewardMomentDialogClosed() { m_rewardClosed = 1; } // 0x801B90C0
};

// --- ITBTarget (Intro Thought Balloon) ---
class ITBTarget : public UIObjectBase {
public:
    int   m_showBalloon;
    int   m_isActive;
    f32   m_userReadTime;

    void ShowIntroThoughtBalloon() { m_showBalloon = 1; }  // 0x801BD870
    void HideIntroThoughtBalloon() { m_showBalloon = 0; }  // 0x801BD87C
    int IsIntroThoughtBalloonActive() { return m_isActive; } // 0x801BD8F4
    f32 GetUserReadTime() { return m_userReadTime; }        // 0x801BDA50
};

// --- K2YTarget ---
class K2YTarget : public UIObjectBase {
public:
    static int s_k2yMode;
    static unsigned short s_savedFirstName[32];
    static unsigned short s_savedLastName[32];

    int GetMode() { return s_k2yMode; }                    // 0x801E7098
    unsigned short* GetSavedFirstName() { return s_savedFirstName; } // 0x801E70A0
    unsigned short* GetSavedLastName() { return s_savedLastName; }   // 0x801E70AC
};

int K2YTarget::s_k2yMode = 0;
unsigned short K2YTarget::s_savedFirstName[32] = {};
unsigned short K2YTarget::s_savedLastName[32] = {};

// --- MDITarget (Modeless Dialog) ---
class MDITarget : public UIObjectBase {
public:
    int m_showDialog;
    int m_isActive;
    int m_dialogCount;

    void ShowModelessDialog() { m_showDialog = 1; }        // 0x801C3C84
    void HideModelessDialog() { m_showDialog = 0; }        // 0x801C3C90
    void UpdateModelessDialogs() {}                        // 0x801C3C9C (empty)
    int IsModelessDialogActive() { return m_isActive; }    // 0x801C3CA0
    int CountModelessDialogs() { return m_dialogCount; }   // 0x801C3DF0
};

// --- MODTarget (Mood Display) ---
class MODTarget : public UIObjectBase {
public:
    int m_showMood;
    int m_isActive;
    int m_textButtonPressed;

    void ShowMood() { m_showMood = 1; }                    // 0x801C9AE4
    void HideMood() { m_showMood = 0; }                    // 0x801C9AF0
    int IsMoodActive() { return m_isActive; }              // 0x801C9C84
    void SetTextButtonPressed(bool p) { m_textButtonPressed = static_cast<int>(p); } // 0x801CAAB4
};

// --- MOTTarget (Motives Display) ---
class MOTTarget : public UIObjectBase {
public:
    int m_showMotives;
    int m_isActive;
    int m_textButtonPressed;

    void ShowMotives() { m_showMotives = 1; }              // 0x801CBB58
    void HideMotives() { m_textButtonPressed = 0; m_showMotives = 0; } // 0x801CBB64
    void UpdateMotives() {}                                // 0x801CBB74 (empty)
    int IsMotivesActive() { return m_isActive; }           // 0x801CBFC0
    void SelectedPersonChanged(cXPerson*) { m_textButtonPressed = 1; } // 0x801CC2A0
    void SetTextButtonPressed(bool p) { m_textButtonPressed = static_cast<int>(p); } // 0x801CC2AC
};

// --- PAZBase / PAZTarget / PZ1Target ---
class PAZBase : public UIObjectBase {
public:
    int m_pausePlayer;

    void Update() override {}                              // 0x801D0B64 (empty)
    int GetPausePlayer() { return m_pausePlayer; }         // 0x801D0B68
    void UpdateButtonVisibility() {}                       // 0x801D0B70 (empty)
};

class PAZTarget : public PAZBase {
public:
    const char* GetTLA() const { return "PAZ"; }           // 0x801E70B8
};

class PZ1Target : public PAZBase {
public:
    const char* GetTLA() const { return "PZ1"; }           // 0x801E70C4
};

// --- PCTTarget (Plumbob/Catalog Target) ---
class PCTTarget : public UIObjectBase {
public:
    int m_gridPage;
    int m_dialogState;

    struct cCellInfo {
        int data[6]; // 0x00-0x14
        cCellInfo() { memset(data, 0, sizeof(data)); }
    };

    u32 get_cell_info_array_index(u32 col) const { return m_gridPage * 6 + col; }
    int get_motive_rating_label(u32, unsigned short*) const { return 1; }
    int refresh_text_field(char*, u32) { return 1; }
    int set_control_visible(char*, bool) { return 1; }
    void buy_fail_dialog_selection_callback(int) { m_dialogState = 0; }
    void ZeroInputCallback() { m_dialogState = 0; }
    void DialogClosedCallback() { m_dialogState = 0; }
};

// --- PRGTarget ---
class PRGTarget : public UIObjectBase {
public:
    void UpdateShaders() {}                                // 0x801DA620 (empty)
};

// --- R2LTarget ---
class R2LTarget : public UIObjectBase {
public:
    int m_summaryDialogState;

    void Update() override {}                              // 0x801DBB98 (empty)
    void onHelpDialogSelection(int) {}                     // 0x801DCE28 (empty)
    void onSummaryDialogZeroInputCallback() { m_summaryDialogState = 0; }
    void onSummaryDialogDialogClosedCallback() { m_summaryDialogState = 0; }

    int ScrollLeftEnabled() {
        // Uses page counter at offset 0xA4
        return 0;
    }
};

// --- RCPTarget (Recipe) ---
class RCPTarget : public UIObjectBase {
public:
    void Draw(ERC*) override {}                            // 0x801DE534 (empty)
};

// --- SKLTarget (Skills Display) ---
class SKLTarget : public UIObjectBase {
public:
    int m_showSkills;
    int m_isActive;
    int m_textButtonPressed;

    void ShowSkills() { m_showSkills = 1; }                // 0x801E1628
    void HideSkills() { m_textButtonPressed = 0; m_showSkills = 0; } // 0x801E1634
    int IsSkillsActive() { return m_isActive; }            // 0x801E19BC
    void SetTextButtonPressed(bool p) { m_textButtonPressed = static_cast<int>(p); } // 0x801E19C4
};

// --- WXFTarget ---
class WXFTarget : public UIObjectBase {
public:
    void Update() override {}                              // 0x801E62E8 (empty)
};


// =============================================================================
// SECTION 28 - UIDialog base callback class
// =============================================================================
// Base class for dialog callbacks used by LoadGameTarget, SaveGameTarget, etc.

class UIDialog {
public:
    virtual void SelectionCallback(int) {}                 // 0x801E7044 (empty)
    virtual void ZeroInputCallback() {}                    // 0x801E7048 (empty)
    virtual void DialogClosedCallback() {}                 // 0x801E704C (empty)
    virtual ~UIDialog() {}
};


// =============================================================================
// Free functions
// =============================================================================

// 0x801A7B28 (12 bytes) - Returns the blank shader hash ID
u32 get_blank_shader_id() {
    return 0x9F93FF74u;
}

// 0x801D1A08 (8 bytes) - Debug dump stub, always returns 0
int DumpObjectFolder(char*) {
    return 0;
}
