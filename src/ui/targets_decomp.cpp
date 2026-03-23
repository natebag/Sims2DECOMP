// targets_decomp.cpp - UI Target System Decompilation
// Part of the Sims 2 GameCube matching decompilation
//
// This file documents the UI target system: the game's dialog/menu controllers.
// Each "Target" is a C++ class that bridges Flash/APT UI screens with game logic.
//
// =============================================================================
// ARCHITECTURE OVERVIEW
// =============================================================================
//
// The Sims 2 GC UI is built on EA's APT (ActionScript Player Technology) engine.
// APT renders Flash-based .swf UI screens and communicates with C++ game logic
// through a callback system based on UIObjectBase.
//
// The flow works like this:
//
//   APT Flash UI  <-->  UIObjectBase callbacks  <-->  Target classes  <-->  Game systems
//
// UIObjectBase is the abstract base class for all C++ objects that talk to APT.
// It provides virtual methods:
//   - SetVariable(char* name, char* value)  -- APT calls this to push data to C++
//   - GetVariable(char* name) -> char*      -- APT calls this to pull data from C++
//   - GetLocalizable(char* name) -> wchar*  -- APT calls this for localized strings
//   - Update()                              -- Called every frame
//   - Draw(ERC*)                            -- Called every render frame
//
// Each Target class inherits UIObjectBase (through Wrapper) and implements these
// callbacks for a specific UI screen. The APT Flash movie sends string-based
// variable names, and the Target parses them to read/write game state.
//
// =============================================================================
// COMMUNICATION FLOW: APT <-> C++
// =============================================================================
//
// 1. APT Flash movie calls SetVariable("varName", "value")
//    -> UIObjectBase dispatches to the Target's SetVariable override
//    -> Target parses the variable name string and updates game state
//
// 2. APT Flash movie calls GetVariable("varName")
//    -> Target's GetVariable compares the name against known strings
//    -> Returns a formatted char* or wchar_t* response
//
// 3. C++ pushes updates via UIReflow:
//    -> UIReflow::SetFocus(screenID) selects which APT screen to modify
//    -> UIReflow::ResetPosition/Size/Visibility/Alpha/Text modify elements
//    -> UIReflow::OpenTweenBlock/SubmitTweenBlock animate elements
//    -> UIReflow::OpenReflowBlock/SubmitReflowBlock batch element changes
//
// 4. Screen navigation via FlowGotoTarget:
//    -> UIObjectBase::UIRouter_FlowGoto("screenName") triggers screen transitions
//    -> FlowGotoTarget::SetVariable handles state machine transitions
//    -> UIScreenManager::LoadUIScreen/UnloadUIScreen manages screen lifecycles
//
// 5. CBFunctor callback system:
//    -> Target constructors register member functions as callbacks via CBMemberTranslator
//    -> Templates: CBMemberTranslator0 (no args), CBMemberTranslator1 (1 arg),
//       CBMemberTranslator2 (2 args), CBMemberTranslator1wRet (1 arg + return)
//    -> These create thunk functions that extract 'this' from CBFunctorBase
//
// =============================================================================
// VARIABLE NAME CONVENTION
// =============================================================================
//
// Target SetVariable/GetVariable use a player-index prefix scheme:
//   "0varName" -> player 0's variable
//   "1varName" -> player 1's variable
//   "varName"  -> global (no player prefix)
//
// The SetVariable/GetVariable pattern is:
//   1. Check if first char is a digit (isdigit via bl 0x80242690)
//   2. If so, extract player index: playerIdx = firstChar - '0'
//   3. Advance string pointer past the digit
//   4. Call SetPlayerVariable(playerIdx, name, value) or GetPlayerVariable(playerIdx, name)
//
// This is visible in HUDTarget::SetVariable (0x80186E34) and GetVariable (0x801871C0).

#include "types.h"

// Forward declarations
class ERC;
class cXObject;
class cXPerson;
class Interaction;
class BString2;
class ERShader;
class ERFont;
class Family;
class NghResFile;
struct EVec2;
struct EVec3;
struct structDrawCBparams;
struct CBFunctorBase;

// =============================================================================
// UIObjectBase - Abstract base class for APT-connected objects
// =============================================================================
// Virtual table at 0x8045CFD8 (64 bytes = 16 vtable entries)
//
// UIObjectBase is the bridge between APT Flash UI and C++ game logic.
// All Target classes inherit from this (through Wrapper) and override the
// virtual callbacks to handle screen-specific variable get/set operations.
//
// Static constants (sdata2):
//   UIObjectBase::SAFE_LEFT   = 0x80500658  (safe area left margin)
//   UIObjectBase::SAFE_TOP    = 0x8050065C
//   UIObjectBase::SAFE_RIGHT  = 0x80500660
//   UIObjectBase::SAFE_BOTTOM = 0x80500664

class UIObjectBase {
public:
    virtual ~UIObjectBase();                                      // vt[0]
    virtual void SetVariable(char* name, char* value);            // vt[1] - default: empty
    virtual char* GetVariable(char* name);                        // vt[2] - default: returns NULL
    virtual unsigned short* GetLocalizable(char* name);           // vt[3] - default: returns NULL
    virtual void Update();                                        // vt[4] - default: empty
    virtual void Draw(ERC*);                                      // vt[5] - default: empty

    // Utility methods (non-virtual)
    void pushAptButtonFilter(int player, char* context);          // 0x80177A64
    void popAptButtonFilter(int player, unsigned int handle);     // 0x80177A98
    void addCmdToAptButtonFilter(int player, unsigned int handle, int cmd); // 0x80177ACC
    void removeCmdFromAptButtonFilter(int player, unsigned int handle, int cmd); // 0x80177B08
    void pushAptButtonFilterALL(int player, char* context);       // 0x80177B44
    void makeNumberString(int value, unsigned short* outBuf);     // 0x80177BA4
    void makeMoneyString(int value, unsigned short* outBuf, bool withSymbol); // 0x80177C30
    void doUIQDStringSubstitution(unsigned short* str);           // 0x80177CA8

    // APT Router helpers - communicate with the UI Router singleton
    // 0x80177CC8 - Calls through UIRouter's vtable at offset 0x80 to SetVariable
    void UIRouter_SetVariable(char* name, char* value);

    // 0x80177D0C - Calls UIRouter_SetVariable with key "FlowGoto" to navigate screens
    // Uses the string "FlowGoto" (at 0x803E2490) as the variable name
    void UIRouter_FlowGoto(char* screenName);

    // 0x80177D54 - Calls AptViewer to execute ActionScript functions
    void AptViewer_CallFunction(char* funcName, char* arg1, char* arg2, int argc, char** argv);
};


// =============================================================================
// UIReflow - Batched UI element modification system
// =============================================================================
// Size: 0x14 (20 bytes)
//
// UIReflow provides a batched command system for modifying APT UI elements.
// It buffers changes to position, size, visibility, alpha, text, color, and
// animation properties, then submits them to APT in a single batch.
//
// Usage pattern in Targets:
//   UIReflow reflow;
//   reflow.SetFocus(screenID);
//   reflow.ResetVisibility("elementName", true, 0);
//   reflow.ResetPosition("elementName", x, y, 0);
//   reflow.OpenTweenBlock("element", duration, delay, easing, 0);
//   reflow.Tween_Alpha(255);
//   reflow.SubmitTweenBlock();

class UIReflow {
public:
    // 0x8017D234 - Constructor, zeroes all fields
    UIReflow();

    // 0x8017D254 - Destructor, frees block buffer if allocated
    ~UIReflow();

    // 0x8017D2B0 - Set which APT screen to target
    // Calls UIScreenManager::GetScreenFlashName to resolve the screen ID
    // Then calls AptViewer::Init (0x80010394) to set the active context
    void SetFocus(int screenID);

    // Immediate property resets (applied next frame)
    void ResetSize(char* element, int w, int h, int player);                // 0x8017D320
    void ResetPosition(char* element, int x, int y, int player);            // 0x8017D4A0
    void ResetZ(char* element, int z, int player);                          // 0x8017D620
    void ResetVisibility(char* element, bool visible, int player);          // 0x8017D75C
    void ResetAlpha(char* element, unsigned int alpha, int player);         // 0x8017D898
    void ResetText(char* element, char* text, int player);                  // 0x8017D9E4
    void ResetColorOverride(char* element, unsigned int color, int player); // 0x8017DB04
    void ResetFontSizeOverride(char* element, unsigned int size, int player); // 0x8017DCAC
    void ResetSwfAnimation(char* element, char* anim, int player);          // 0x8017DDE8
    void ResetSwfFileName(char* element, char* file, int player);           // 0x8017DF08

    // Tween animation system
    void OpenTweenBlock(char* element, unsigned int duration, unsigned int delay, char* easing, int player); // 0x8017E138
    void SubmitTweenBlock();               // 0x8017E318
    void Tween_X(int x);                   // 0x8017E39C
    void Tween_Y(int y);                   // 0x8017E408
    void Tween_Z(unsigned int z);          // 0x8017E474
    void Tween_H(unsigned int h);          // 0x8017E4E0
    void Tween_W(unsigned int w);          // 0x8017E54C
    void Tween_XScale(float scale);        // 0x8017E5B8
    void Tween_YScale(float scale);        // 0x8017E638
    void Tween_Rotation(float rot);        // 0x8017E6B8
    void Tween_Alpha(unsigned int alpha);  // 0x8017E72C
    void Tween_ColorOverride(unsigned int color);       // 0x8017E7A8
    void Tween_ColorOnlyOverride(unsigned int color);   // 0x8017E838
    void Tween_FontSizeOverride(unsigned int size);     // 0x8017E8B4

    // Reflow batch system (multiple element changes at once)
    void OpenReflowBlock();                // 0x8017E920
    void SubmitReflowBlock();              // 0x8017E998
    void Reflow_Id(char* id, int player);  // 0x8017EA1C
    void Reflow_X(int x);                  // 0x8017EAB0
    void Reflow_Y(int y);                  // 0x8017EAD0
    void Reflow_Z(unsigned int z);         // 0x8017EAF0
    void Reflow_H(unsigned int h);         // 0x8017EB10
    void Reflow_W(unsigned int w);         // 0x8017EB30
    void Reflow_XScale(float scale);       // 0x8017EB50
    void Reflow_YScale(float scale);       // 0x8017EB70
    void Reflow_Rotation(float rot);       // 0x8017EB90
    void Reflow_Visibility(bool visible);  // 0x8017EBB0
    void Reflow_Alpha(unsigned int alpha); // 0x8017EC28
    void Reflow_StringChange(char* text);  // 0x8017EC48
    void Reflow_ColorOverride(unsigned int color);      // 0x8017EC9C
    void Reflow_ColorOnlyOverride(unsigned int color);  // 0x8017ECBC
    void Reflow_FontSizeOverride(unsigned int size);    // 0x8017ECDC
    void Reflow_SwfAnimation(char* anim);  // 0x8017ECFC
    void Reflow_SwfFile(char* file);       // 0x8017ED50
    void Debug_PrintBlock();               // 0x8017EDA4

    // Fields
    void** m_vtable;       // 0x00 - vtable pointer
    int    m_focus;        // 0x04 - current screen ID (0 = none)
    void*  m_blockBuffer;  // 0x08 - dynamically allocated command buffer
    int    m_blockSize;    // 0x0C - current number of commands in buffer
    int    m_blockCapacity; // 0x10 - allocated capacity of buffer
};


// =============================================================================
// UIScreenManager - Manages loading/unloading of APT UI screens
// =============================================================================
// Virtual table at 0x80466750
// Static data table: UIScreenManager::UIScreenDataTable at 0x80424720 (1488 bytes)
// Singleton group number: UIScreenManager::m_groupNumber at 0x804FDE18
//
// UIScreenManager owns the lifecycle of all UI screens. Each screen is
// identified by a UIScreenID enum. The manager loads Flash .swf files,
// creates Target objects, and routes APT callbacks to them.

class UIScreenManager : public UIObjectBase {
public:
    UIScreenManager();                      // 0x8017F0D0 (1464 bytes - large ctor)
    ~UIScreenManager();                     // 0x8017F688

    void* FindDataByID(int screenID);       // 0x8017F838
    void  process_cheats(int screenID);     // 0x8017F87C (empty)

    // 0x8017F884 - Load a UI screen by ID with input mode
    // Checks if screen already managed, looks up data record,
    // handles different screen types (type 1=suspend all, type 3/4=special layout)
    int LoadUIScreen(int screenID, int inputMode);

    // 0x8017FAE4 - Unload a screen, release resources
    int UnloadUIScreen(int screenID);

    int  IsScreenManaged(int screenID);     // 0x8017FC74
    void SuspendAllActiveScreens();         // 0x8017FCB0
    void SuspendScreenList(int* screenIDs); // 0x8017FD58
    int  AddScreen(int screenID, int type); // 0x8017FE64
    int  FindRecordIndexByID(int screenID); // 0x8017FEB8
    int  RemoveScreen(int screenID);        // 0x8017FEF8
    int  GetScreenFlashName(char* outBuf, int screenID); // 0x8017FF44
    int  IsUIScreenUnloaded(int screenID);  // 0x8018003C
    int  IsUIScreenMarkedForUnloading(int screenID); // 0x80180068
    void SetHandlesInput(int screenID, bool handles); // 0x801800BC
    void SetVariable(char* name, char* value);        // 0x8018019C
    void Update();                          // 0x80180274
    void PopQueue(int count);               // 0x80180308
};


// =============================================================================
// FlowGotoTarget - Screen navigation state machine
// =============================================================================
// Virtual table at 0x80466578
// Size: ~0x90
//
// FlowGotoTarget is the central screen navigation controller. When
// UIObjectBase::UIRouter_FlowGoto("screenName") is called, it routes through
// FlowGotoTarget::SetVariable which contains a massive string comparison chain
// that maps screen names to numeric state IDs:
//
//   "mainmenu"        -> state 1  (main menu)
//   "ingame"          -> state 2  (in-game / live mode)
//   "freeplay"        -> state 9  (freeplay mode)
//   "loadgame"        -> state 8  (load game)
//   "credits"         -> state 10 (credits)
//   "cas_xxxx"        -> state 3-7 (Create-A-Sim sub-screens)
//   "options"         -> state 11 (options menu)
//   etc.
//
// The state machine triggers UIScreenManager to load/unload screens and
// coordinates transitions between major game modes.

class FlowGotoTarget : public UIObjectBase {
public:
    FlowGotoTarget();                           // 0x8017ABA0 (1164 bytes)
    ~FlowGotoTarget();                          // 0x8017B02C

    // 0x8017B170 - Main navigation handler (1804 bytes)
    // Massive string comparison: compares incoming screen name against known
    // destinations and sets m_stateRequest to the corresponding state ID
    void SetVariable(char* name, char* value);

    char* GetVariable(char* name);              // 0x8017B960
    int   IsStateRequestPending();              // 0x8017B960
    int   GetStateRequest();                    // 0x8017B980
    void  SetPendingStateCurrent();             // 0x8017B988

    // Fields
    // 0x084: m_stateRequest - pending navigation target
    // 0x088: state request pending flag
};


// =============================================================================
// UIRouter - Routes APT variable get/set to appropriate targets
// =============================================================================
// Virtual table at 0x80466710
//
// UIRouter is a thin routing layer. When APT needs to set or get a variable,
// it goes through UIRouter which forwards to the appropriate Target based on
// the variable prefix or context.

class UIRouter : public UIObjectBase {
public:
    UIRouter();                                 // 0x8017EDA8 (252 bytes)
    ~UIRouter();                                // 0x8017EEA4
    char* GetVariable(char* name);              // 0x8017EF08
    void  SetVariable(char* name, char* value); // 0x8017EFE0
};


// =============================================================================
// DlgWrapper - Modal dialog display system
// =============================================================================
// Virtual table at 0x8045CF18
// Size: 0x698C (27020 bytes - includes large embedded DialogPane)
//
// DlgWrapper manages modal popup dialogs (confirmations, errors, info).
// It wraps the APT DialogPane system and provides C++ control over:
//   - Dialog text (title, body, buttons)
//   - Dialog positioning and sizing
//   - Button configuration (accept/decline/alt1)
//   - Show/hide animation
//
// Used extensively by LoadGameTarget, SaveGameTarget, M2MTarget, O2TTarget,
// E2ETarget, FAMTarget, and MMUTarget for confirmation dialogs.
//
// Dialog lifecycle:
//   1. DlgWrapper::Startup()       - Initialize APT dialog resources
//   2. Set title/body/button text
//   3. DlgWrapper::DialogPaneShow() - Show the dialog
//   4. DlgWrapper::Update()        - Poll for user input
//   5. Check DialogAccepted()/DialogDeclined()/DialogAlt1()
//   6. DlgWrapper::DialogPaneHide() - Hide dialog
//   7. DlgWrapper::Shutdown()      - Release resources

class DlgWrapper {
public:
    // 0x8007E440 - Constructor
    DlgWrapper(bool useAltLayout);

    // 0x8007E544 - Destructor
    ~DlgWrapper();

    // Core lifecycle
    void Startup();                             // 0x8007D8A0 (1272 bytes - large init)
    void Shutdown();                            // 0x8007DD98
    void Reset();                               // 0x8007DDEC
    void Update();                              // 0x8007DE30 (440 bytes)
    void Draw(ERC* rc);                         // 0x8007DFE8
    void DialogPaneShow();                      // 0x8007E084
    void DialogPaneHide();                      // 0x8007E0FC

    // APT variable interface
    void  SetVariable(char* name, char* value); // 0x8007E184
    char* GetVariable(char* name);              // 0x8007E274

    // State queries
    void* GetFont();                            // 0x8007E5E0
    void* GetDialogPane();                      // 0x8007E5E8
    bool  IsDialogUp();                         // 0x8007E5F0
    bool  DialogAccepted();                     // 0x8007E608
    bool  DialogDeclined();                     // 0x8007E620
    bool  DialogAlt1();                         // 0x8007E638
    bool  IsAptDrawable();                      // 0x8007F06C

    // Positioning
    void   SetDialogPos(EVec2& pos);            // 0x8007E650
    void   SetDialogPosX(float x);              // 0x8007E664
    void   SetDialogPosY(float y);              // 0x8007E66C
    EVec2* GetDialogPos();                      // 0x8007E674
    float  GetDialogPosX() const;               // 0x8007E67C
    float  GetDialogPosY() const;               // 0x8007E684

    // Sizing
    void   SetDialogSize(EVec2& size);          // 0x8007E68C
    void   SetDialogSizeX(float w);             // 0x8007E6D8
    void   SetDialogSizeY(float h);             // 0x8007E718
    EVec2* GetDialogSize();                     // 0x8007E758
    float  GetDialogSizeX() const;              // 0x8007E760
    float  GetDialogSizeY() const;              // 0x8007E768
    float  GetDialogWidth() const;              // 0x8007E770
    float  GetDialogHeight() const;             // 0x8007E778
    float  GetDialogPadSizeX() const;           // 0x8007E780
    float  GetDialogPadSizeY() const;           // 0x8007E790
    float  GetTitleWidth() const;               // 0x8007E7A0

    // Content
    void SetTitleText(unsigned short* text);     // 0x8007E7E0
    void SetTitleFontSize(float size);           // 0x8007E808
    void SetBodyText(unsigned short* text);      // 0x8007E84C
    void SetBodyFont(ERFont* font);              // 0x8007E874
    void SetBodyFontSize(float size);            // 0x8007E8B8
    void SetBodyPos(EVec2& pos);                 // 0x8007E8FC
    void SetBodyPosX(float x);                   // 0x8007E954
    void SetBodyPosY(float y);                   // 0x8007E990
    void SetBodyPadSize(EVec2& padSize);         // 0x8007EF60

    // Buttons
    void SetAcceptText(unsigned short* text);    // 0x8007E9CC
    void SetAcceptFont(ERFont* font);            // 0x8007EA08
    void SetAcceptFontSize(float size);          // 0x8007EA58
    void SetAcceptPos(EVec2& pos);               // 0x8007EAAC
    void SetAcceptPosX(float x);                 // 0x8007EB08
    void SetAcceptPosY(float y);                 // 0x8007EB58
    void SetDeclineText(unsigned short* text);   // 0x8007EBA8
    void SetDeclineFont(ERFont* font);           // 0x8007EBE4
    void SetDeclineFontSize(float size);         // 0x8007EC34
    void SetDeclinePos(EVec2& pos);              // 0x8007EC88
    void SetDeclinePosX(float x);                // 0x8007ECE4
    void SetDeclinePosY(float y);                // 0x8007ED34
    void SetAlt1Text(unsigned short* text);      // 0x8007ED84
    void SetAlt1Font(ERFont* font);              // 0x8007EDC0
    void SetAlt1FontSize(float size);            // 0x8007EE10
    void SetAlt1Pos(EVec2& pos);                 // 0x8007EE64
    void SetAlt1PosX(float x);                   // 0x8007EEC0
    void SetAlt1PosY(float y);                   // 0x8007EF10

    void SetButtonContext(char* context);         // 0x8007EF9C
    void AddAcceptButton(unsigned short* text);   // 0x8007EFDC
    void AddDeclineButton(unsigned short* text);  // 0x8007F00C
    void AddAlt1Button(unsigned short* text);     // 0x8007F03C
    void SetPlayer(int player);                   // 0x8007F074

    // Fields (key offsets from DlgWrapper.h)
    float  m_variable;       // 0x000 - dialog state flags
    u32    m_field_004;      // 0x004 - APT viewer handle
    u32    m_field_008;      // 0x008
    float  m_posX;           // 0x00C
    float  m_posY;           // 0x010
    float  m_sizeX;          // 0x014
    float  m_sizeY;          // 0x018
    // ... (27020 bytes total, includes embedded DialogPane at +0x0D0)
};


// =============================================================================
// HUDTarget - Live Mode HUD Overlay Controller
// =============================================================================
// Virtual table at 0x80466888 (64 bytes)
// Size: 0x8B8 (2232 bytes)
// Static: HUDTarget::m_pFont at 0x804FDE44
//
// HUDTarget is the primary in-game HUD controller. It manages:
//   - Motive bars (hunger, energy, fun, etc.) per player
//   - Speed controls (pause/play/fast-forward)
//   - Action queue display per player
//   - Action menu (pie menu) per player
//   - Clock display (time of day)
//   - Job performance bars
//   - Reputation values
//   - Tutorial lock state
//   - HUD show/hide transitions
//   - Navigation to CAS and Main Menu
//
// The HUD supports split-screen multiplayer (up to 2 players), so many methods
// take a player index parameter. Player-specific data is accessed through
// a pointer array at the global ESimsApp singleton.
//
// === HUD Visibility State Machine ===
// m_field_0E8 (byte at offset 0xE8) tracks visibility state:
//   0 = hidden
//   1 = showing / visible
//   2 = visible and active
//   3 = transitioning to CAS
//
// === Speed Control System ===
// m_speedControls (bytes at 0xF4-0xF7) encode game speed state:
//   m_speedControls[0] (0xF4): previous frame's combined speed flags
//   m_speedControls[1] (0xF5): current frame's speed change flags
//     bit 0: player 0 pressed speed up (button 0x22)
//     bit 1: player 0 pressed speed down (button 0x23)
//     bit 2: player 1 pressed speed up
//     bit 3: player 1 pressed speed down
//     bit 4: pause toggle
//   m_speedControls[2] (0xF6): previous combined state
//   m_speedControls[3] (0xF7): computed speed command
//     -4 = pause
//     -3 = slow (unpause but slow)
//     -2 = fast forward
//      0 = normal
//
// Speed commands are sent to ELiveMode via the APT callback vtable.
// The sound system plays speed-change SFX via hashes: 0x5D6996BB (pause),
// 0xB367F797 (slow/normal), 0xE13275888 (resume from pause), 0xACFAD483 (fast).
//
// === Clock Display ===
// HUDTarget::UpdateClock queries the game time through the APT vtable:
//   - Hour (vtable offset 0x30, param 5) -> "HUDHr" variable
//   - Minute (vtable offset 0x30, param 6) -> "HUDMin" variable
//   - AM/PM (vtable offset 0x30, param 0) -> "HUDMeridian" variable
//     12-hour conversion applied (hour > 12 -> subtract 12, 0 -> 12)
//   - Displayed as "HUDHr12" for 12-hour format
//
// === Tutorial Lock System ===
// m_tutorialLocks (offset 0xF0) tracks whether the tutorial has been completed.
// When the tutorial completion global changes from last frame, and equals 1,
// ShowHUD() is called to reveal the full HUD.

class HUDTarget : public UIObjectBase /* through Wrapper */ {
public:
    // 0x8018591C - Constructor (4320 bytes - very large)
    // Initializes all per-player data, registers CBFunctor callbacks for
    // SetVariable, GetVariable, GetLocalizable, Update, Draw
    HUDTarget();

    // 0x801869FC - Destructor (588 bytes)
    ~HUDTarget();

    // === Controller Management ===
    void AttachControllers();       // 0x80186C48 (228 bytes)
    void ReleaseControllers();      // 0x80186D2C (168 bytes)

    // === Pause System ===
    // 0x80186DD4 - Increment pause reference count
    // Loads m_field_8B4 (offset 0x8B4), if non-null calls ELiveMode::IncPause
    void IncPause(bool showPauseUI);

    // 0x80186E04 - Decrement pause reference count
    // Same pattern: loads m_field_8B4, if non-null calls ELiveMode::ReleasePause
    void ReleasePause(bool hidePauseUI);

    // === APT Variable Interface ===
    // 0x80186E34 - SetVariable dispatcher
    // Parses optional player digit prefix, then calls SetPlayerVariable
    void SetVariable(char* name, char* value);

    // 0x80186EA0 - Per-player variable setter (800 bytes)
    // Handles: "HUDMode", "CASType", speed control vars, motive display vars
    void SetPlayerVariable(int player, char* name, char* value);

    // 0x801871C0 - GetVariable dispatcher
    // Parses optional player digit prefix, then calls GetPlayerVariable
    char* GetVariable(char* name);

    // 0x80187224 - Per-player variable getter (1212 bytes)
    // Returns: player count, HUD mode, motive values, job data, reputation
    char* GetPlayerVariable(int player, char* name);

    // 0x801876E0 - GetLocalizable dispatcher
    unsigned short* GetLocalizable(char* name);

    // 0x80187744 - Per-player localized string getter (768 bytes)
    // Returns: sim name, lot name, job title, motive descriptions
    unsigned short* GetPlayerLocalizable(int player, char* name);

    // === Reputation System ===
    void InitRepValues();                    // 0x80187A44 (188 bytes)
    int  GetReputationValue(int repType);    // 0x80187B00 (196 bytes)
    int  GetNextRepUnlockValue(int repType); // 0x80187BC4 (216 bytes)

    // === Motive Display ===
    void OnReadBar(int player, unsigned int barIndex); // 0x80187C9C
    void ReadMoodBar(int player, unsigned int index);  // 0x80187D10 (300 bytes)

    // === HUD Visibility ===
    // 0x80187E3C - Show the HUD overlay
    // Checks tutorial lock state and current visibility flags.
    // If visible and not already showing, calls UpdateClock and transitions
    // APT to "showHUD" state via AptViewer::Init (0x80010394)
    void ShowHUD();

    // 0x80187EB4 - Hide the HUD overlay
    // Checks tutorial lock state. If currently visible (state==2),
    // triggers "hideHUD" APT transition
    void HideHUD();

    // Per-player show/hide callbacks
    void OnPlayerHUDShow(int player);       // 0x80187F24
    void OnPlayerHUDHide(int player);       // 0x80187F54
    void OnPlayerHUDHideStart(int player);  // 0x80187F80

    // Virtual callbacks (overridden from base - typically no-ops)
    void OnHUDShow();                       // 0x80187FFC (4 bytes - blr)
    void OnHUDHideStart();                  // 0x80188000 (4 bytes - blr)
    void OnHUDHide();                       // 0x80188004 (4 bytes - blr)

    // === HUD Icon Management ===
    // 0x80188008 - Install icons for a player (832 bytes)
    // Sets up motive bar icons, button prompts, HUD frame elements
    void InstallHUDIcons(int player);

    // 0x80188348 - Check if HUD should be visible for a player (284 bytes)
    int ShouldHUDBeVisible(int player) const;

    // === Frame Update ===
    // 0x80188464 - Update tutorial lock state
    void UpdateTutorialLocks();

    // 0x801884B4 - Main frame update (248 bytes)
    // 1. UpdateTutorialLocks
    // 2. ShouldHUDBeVisible(0) -> if not visible, handle hide transition
    //    If speed command is -4 (pause), call ReleasePause
    //    Shift speed state bytes and clear pending
    // 3. If visible: call ShowHUD, UpdateSpeedControls
    //    Decrement m_field_084 counter; at 0, reset to 30 and UpdateClock
    void Update();

    void UpdateClock();                         // 0x801885AC (276 bytes)
    void UpdateActivePlayer(int player, bool active); // 0x801886C0
    int  IsActionQueueAvailable(int player) const;    // 0x80188724

    // 0x801887AC - Speed control update (1096 bytes)
    // Reads controller input for speed up/down buttons per player
    // Computes combined speed state, handles pause toggle, plays SFX
    void UpdateSpeedControls();

    // === Action Menu (Pie Menu) ===
    void AddMenu(int player, cXObject* obj, BString2& name, unsigned int icon, ERShader* shader); // 0x80188BF4
    void AddMenuItem(int player, cXObject* obj, Interaction* interaction,
                     BString2& name, unsigned int icon, ERShader* shader, int priority, bool enabled); // 0x80188C54
    void NotifyMenuRemoveObj(cXObject* obj);    // 0x80188CC4
    void CompleteMenu(int player);              // 0x80188D3C
    void ShowMenu(int player);                  // 0x80188D7C
    int  IsMenuAvailable(int player) const;     // 0x80188DBC
    void CloseMenu(int player);                 // 0x80188E34

    // === Action Queue Display ===
    void AddAction(int player, Interaction* interaction, BString2& name,
                   unsigned int icon, ERShader* shader, unsigned int flags); // 0x80188E60
    void RemoveAction(int player, Interaction* interaction);                 // 0x80188F70
    void RemoveAllActions(int player);                                       // 0x80188FC8

    // === Rendering ===
    void Draw(ERC* rc);                         // 0x8018901C (172 bytes)
    void DrawMotiveValues(ERC* rc, int player); // 0x801890C8 (4 bytes - blr / empty)

    // === Job HUD ===
    void ResetJobHudProperties();               // 0x801890CC (244 bytes)
    void SetJobBarInputRange(int player, int min, int max); // 0x80189408
    void ApplyMotiveCurveArray(unsigned int curveIndex, short value); // 0x80189444
    void CalculateJobScore();                   // 0x801895AC (576 bytes)
    int  GetJobBarCount();                      // 0x80189A34

    // === HUD Control System ===
    void RequestHUD(short type, short param1, short param2);    // 0x801891C0
    void AddHUDControl(short type, short subtype, short& id);   // 0x801892A8
    void RemoveHUDControl(short type, short subtype);           // 0x801892D4
    void ManageHUD(short type, short param, short value);       // 0x801892FC
    void SetHUDData(short type, short value);                   // 0x80189360
    int  GetHUDData(short type, short& outValue);               // 0x801897EC
    void AnimateHUDControl(short type, int animType);           // 0x80189864

    // === Screen Navigation ===
    // 0x801898E4 - Transition to Create-A-Sim (260 bytes)
    // Sets m_field_100 = 3, hides HUD for both players if visible,
    // sets CAS parameters via UIReflow, then calls UIRouter_FlowGoto
    void GotoCAS(unsigned short casType, unsigned short param, int player, int slot);

    // 0x801899E8 - Return to main menu (48 bytes)
    // Sets m_field_100 = 1, calls UIRouter_FlowGoto("mainmenu")
    void GotoMainMenu();

    // 0x80189A18 - Request quit game (28 bytes)
    // If quitRequested is true, sets m_field_100 = 1; else sets to 0
    void RequestQuitGame(bool quitRequested);

    // === Query Methods ===
    void* GetActionQueueHUD(int player);        // 0x80189A50
    int   GetHUDMode() const;                   // 0x80189A60
    bool  HUDHideComplete() const;              // 0x80189A78
    bool  HideInProgress() const;               // 0x80189A88
    bool  IsHUDVisible() const;                 // 0x80189A9C
    bool  IsPlayerHUDVisible(int player) const; // 0x80189AB0
    void* GetHudTransitionTarget();             // 0x80189AC8
};


// =============================================================================
// ACTTarget - Action Queue HUD Controller
// =============================================================================
// Virtual table at 0x80467960 (64 bytes)
// Inner class vtable: ACTTarget::iqRecord at 0x804679A0 (24 bytes)
// Size: 0x658 (1624 bytes)
//
// ACTTarget manages the action queue display for a single player. It shows
// the list of queued interactions (actions) and provides a cancel mode where
// the player can select and remove individual actions.
//
// The action queue is stored as a linked list of iqRecord entries, each
// containing an Interaction pointer, display name, icon, and shader.
//
// === Cancel Mode ===
// When cancel mode is active (m_bCancelModeEnabled), the player can move
// a cursor up/down through the action queue and press X to cancel the
// highlighted action. The cursor position is tracked by
// m_bCancelModeEnabled_644/648/64C.

class ACTTarget : public UIObjectBase {
public:
    // 0x801A0968 - Constructor (4168 bytes - very large)
    ACTTarget(int player);

    // 0x801A19B0 - Destructor (620 bytes)
    ~ACTTarget();

    void SetVariable(char* name, char* value);  // 0x801A1C1C
    char* GetVariable(char* name);              // 0x801A1D3C
    unsigned short* GetLocalizable(char* name); // 0x801A1DD4

    // 0x801A1E58 - Frame update (916 bytes)
    // Updates action queue display, animates entries, handles cancel mode
    void Update();

    void ShowActionQueue();     // 0x801A21EC (12 bytes: m_showQueue = 1)
    void HideActionQueue();     // 0x801A21F8 (12 bytes: m_showQueue = 0)

    // 0x801A2204 - Refresh action queue display (440 bytes)
    void UpdateActionQueue();

    int IsActionQueueActive();  // 0x801A23BC (8 bytes: return m_isActive)

    // 0x801A23C4 - Add action to queue (500 bytes)
    void AddAction(int slot, Interaction* interaction, BString2& name,
                   unsigned int icon, ERShader* shader, unsigned int flags);

    // 0x801A25B8 - Place item in queue list (624 bytes)
    void PlaceItem(void* record, int slot, Interaction* interaction,
                   int position, cXPerson* person, BString2& name,
                   unsigned int icon, ERShader* shader, unsigned int flags);

    // 0x801A2828 - Remove specific action (644 bytes)
    void RemoveAction(int slot, Interaction* interaction);

    void RemoveAllActions(int slot);            // 0x801A2AAC
    int  IsActionQueueAvailable(int) const;     // 0x801A2B34 (returns 1 always)
    void* GetRecord();                          // 0x801A2B3C
    void ReOrderActionQueue();                  // 0x801A2BA4
    void DebugListValidation();                 // 0x801A2C30 (empty)
    void* GetInteractionFromID(int id);         // 0x801A2C34

    // Cancel mode
    void MoveCancelCursorUp();                  // 0x801A2CDC
    void MoveCancelCursorDown();                // 0x801A2D30
    void CancelModeEnabled(bool enable);        // 0x801A2D78
    void CancelCurrentObject();                 // 0x801A2E30
    void UpdateCancelModeWidgets();             // 0x801A2F98
    void ExitCancelMode();                      // 0x801A30A0
    void CancellingLastObject();                // 0x801A311C
};


// =============================================================================
// O2TTarget - Options Menu Controller
// =============================================================================
// Virtual table at 0x804672C0 (64 bytes)
// Singleton: O2TTarget::m_pSingletonPtr at 0x804FE4F0
// Size: 0x25C (604 bytes)
//
// O2TTarget manages the in-game options menu. It controls:
//   - Audio settings (SFX, Music, Ambient, Voice volume)
//   - Game settings (rumble, camera rotation, free will)
//   - Screen position calibration (X/Y offset)
//   - Save settings confirmation dialog
//   - Quit game confirmation dialog
//   - Help screen display
//
// Static audio/game option values (sdata):
//   m_CurrentSFXVolume     at 0x804FE4F4 (1 byte)
//   m_CurrentMusicVolume   at 0x804FE4F5 (1 byte)
//   m_CurrentAmbientVolume at 0x804FE4F6 (1 byte)
//   m_CurrentVoiceVolume   at 0x804FE4F7 (1 byte)
//   m_CurrentScreenX       at 0x804FE4F8 (1 byte)
//   m_CurrentScreenY       at 0x804FE4F9 (1 byte)
//   m_bRumbleOn            at 0x804FE4FC (4 bytes)
//   m_bCameraRotateDC      at 0x804FE500 (4 bytes)
//   m_bCameraRotate        at 0x804FE504 (4 bytes)
//   m_bFreeWill            at 0x804FE508 (4 bytes)
//
// The options system remembers previous values so changes can be reverted:
//   RememberAudioOptions() / RestoreAudioOptions()
//   RememberGameOptions()  / RestoreGameOptions()
//   RememberOptions()      / RestoreOptions()

class O2TTarget : public UIObjectBase {
public:
    O2TTarget(int screenID, int player);        // 0x801CC2B4 (4392 bytes)
    ~O2TTarget();                               // 0x801CD3DC

    void SetVariable(char* name, char* value);  // 0x801CD598 (2460 bytes)
    char* GetVariable(char* name);              // 0x801CDF34 (1160 bytes)
    unsigned short* GetLocalizable(char* name); // 0x801CE3BC (1380 bytes)

    // Top-level state management
    void SetTopLevelState(char* name, char* value);         // 0x801CE920
    void OnTopLevelStateChange(char* name, char* value);    // 0x801CE974

    // Save/quit flow
    void SaveGame(char* name, char* value);     // 0x801CEA60
    void OnSaveGameComplete(bool success);      // 0x801CEA74
    void Shutdown(char* name, char* value);     // 0x801CEAC0
    void OnStateChange();                       // 0x801CEB2C

    // Options modification tracking
    void AudioOptionsModified();                // 0x801CEBE8
    void GameOptionsModified();                 // 0x801CEC3C
    void SpawnSaveSettingsDialog();             // 0x801CEC90 (600 bytes)
    void OnSaveSettingsDialogClose(int result); // 0x801CEEE8
    void RememberAudioOptions();                // 0x801CEF60
    void RestoreAudioOptions();                 // 0x801CEF8C
    void RememberGameOptions();                 // 0x801CF028
    void RestoreGameOptions();                  // 0x801CF054
    void RememberOptions();                     // 0x801CF090
    void RestoreOptions();                      // 0x801CF0EC

    // Screen calibration
    int GetScreenXLocal(signed char offset);    // 0x801CF1D8
    int GetScreenXGlobal(float value);          // 0x801CF26C
    int GetScreenYLocal(signed char offset);    // 0x801CF2CC
    int GetScreenYGlobal(float value);          // 0x801CF360

    void UpdateText();                          // 0x801CF3C0 (836 bytes)

    // Input handlers (registered as APT callbacks)
    void OnXKeyPressed(char* name, char* value);      // 0x801CF704
    void SpawnQuitDialogBox();                         // 0x801CF780 (736 bytes)
    void OnCancelDialog();                             // 0x801CFA60
    void OnQuitGameDialogClose(int result);            // 0x801CFA6C
    void OnUpKeyPressed(char* name, char* value);      // 0x801CFAE8
    void OnDownKeyPressed(char* name, char* value);    // 0x801CFB58
    void OnRightKeyPressed(char* name, char* value);   // 0x801CFBC4
    void OnLeftKeyPressed(char* name, char* value);    // 0x801CFC40
    void OnCircleKeyPressed(char* name, char* value);  // 0x801CFCBC

    void UpdateShaders(char* name, char* value);       // 0x801CFD30
    void ShowHelp();                                   // 0x801CFFC8
    void StartScreenWizard(char* name, char* value);   // 0x801CFFC8
    void ExitScreenWizard(char* name, char* value);    // 0x801D006C
    void QuitGame(char* name, char* value);            // 0x801D00C0
};


// =============================================================================
// E2ETarget - EyeToy Camera Controller
// =============================================================================
// Virtual table at 0x80467718 (64 bytes)
// Singleton: E2ETarget::m_pSingletonPtr at 0x804FE22C
// Size: 0x288 (648 bytes)
//
// E2ETarget manages the EyeToy camera interface (PS2-heritage feature).
// On GameCube this is largely vestigial but the code remains. It handles:
//   - Camera settings (hue, saturation, brightness, exposure)
//   - Fun frames and filters
//   - Image capture and save to memory card
//   - EyeToy plug/unplug detection
//   - Settings save/restore

class E2ETarget : public UIObjectBase {
public:
    E2ETarget(int screenID);                    // 0x801AA5B8 (5888 bytes)
    ~E2ETarget();                               // 0x801ABCB8

    void SetVariable(char* name, char* value);  // 0x801ABF08 (1156 bytes)
    char* GetVariable(char* name);              // 0x801AC38C
    unsigned short* GetLocalizable(char* name); // 0x801AC5F8
    void Update();                              // 0x801AC95C
    void SaveGame();                            // 0x801AC9B0
    void OnShutdown();                          // 0x801ACA08

    // Rendering callback for EyeToy preview
    void E2ERenderCallback(ERC* rc, structDrawCBparams* params); // 0x801ACA58

    // EyeToy hardware management
    void EyeToyUnplugCallback(int port);        // 0x801ACC34
    void OnEyeToyUnplugged();                   // 0x801ACC60
    void SpawnNoEyeToyDialogBox();              // 0x801ACC80 (548 bytes)
    void OnExitDialog(int result);              // 0x801ACEA4
    bool IsEyeToyPluggedIn();                   // 0x801ACEE8
    void InitializeEyeToy();                    // 0x801ACF0C
    void ReintializeEyeToy();                   // 0x801ACF74

    // Settings
    void SaveCurrentSettings(char* name, char* value);  // 0x801ACFC8
    void RestorePreviousSettings();                     // 0x801AD004
    void SetTopLevelState(char* name, char* value);     // 0x801AD040
    void OnTopLevelStateChange(char* name, char* value); // 0x801AD200
    void SetDefault(char* name, char* value);            // 0x801AD568

    // Camera adjustments
    void UpdateHue(char* name, char* value);        // 0x801AD378
    void UpdateSaturation(char* name, char* value); // 0x801AD3E8
    void UpdateValue(char* name, char* value);      // 0x801AD458
    void UpdateExposure(char* name, char* value);   // 0x801AD5A8

    // Content
    void CaptureFrame(char* name, char* value);     // 0x801AD4C8
    void SaveFrame(char* name, char* value);        // 0x801AD544
    void ChangeFunFrame(char* name, char* value);   // 0x801AD618
    void ChangeSelectedSlot(char* name, char* value); // 0x801AD65C
    void ChangeFilter(char* name, char* value);     // 0x801AD6C0

    // Input
    void OnXKeyPressed(char* name, char* value);      // 0x801AD704
    void OnUpKeyPressed(char* name, char* value);     // 0x801AD820
    void OnDownKeyPressed(char* name, char* value);   // 0x801AD860
    void OnRightKeyPressed(char* name, char* value);  // 0x801AD8A0
    void OnLeftKeyPressed(char* name, char* value);   // 0x801ADA7C
    void OnCircleKeyPressed(char* name, char* value); // 0x801AE050

    void UpdateText();                               // 0x801ADC50
    char* GetText(char* name);                       // 0x801ADE54
    void UpdateShaders(char* name, char* value);     // 0x801AE0C0
    void ShowHelp();                                 // 0x801AE1E4
    void OnEnterSettings();                          // 0x801AE220
    void OnExitSettings();                           // 0x801AE244

    // Save flow
    void LaunchSaveSettingsDialog();                 // 0x801AE2C4 (592 bytes)
    void OnSaveDialogDoneCB(int result);             // 0x801AE514
    void OnSaveGameComplete(bool success);           // 0x801AE598
    void SpawnSaveGameDialog();                      // 0x801AE5E0 (600 bytes)
    void OnSaveGameDialogClosed(int result);         // 0x801AE838

    int GetTopLevelState();                          // 0x801E7088

    // Static data
    // E2ETarget::m_bAlreadyCreatedOnce at 0x804FE230
    // E2ETarget::m_sCurrentHue         at 0x804FE234
    // E2ETarget::m_sCurrentSaturation  at 0x804FE238
    // E2ETarget::m_sCurrentBrightness  at 0x804FE23C
    // E2ETarget::m_sCurrentExposure    at 0x804FE240
};


// =============================================================================
// FAMTarget - Family/Lot Selection Controller
// =============================================================================
// Virtual table at 0x80467668 (64 bytes)
// Widget data: Widget_FAMTarget at 0x80428B14 (8792 bytes)
// Size: 0x450 (1104 bytes)
//
// FAMTarget controls the family and lot selection screen. This is the screen
// shown after the main menu where the player selects a neighborhood lot and
// family to play.
//
// === Menu State Machine ===
// FAMTarget uses a stack-based state machine (std::stack<FAM_STATE>) to
// track menu navigation. States include lot selection, family selection,
// occupied lot handling, and family creation.
//
// Navigation: push states when going deeper, pop on cancel/back.
//   GoUpMenuTree() - pop state and return to parent menu
//   UpdateMenuState(FAM_STATE) - push new state
//   OnCancelKeyPressed - triggers GoUpMenuTree or back-to-main-menu dialog

class FAMTarget : public UIObjectBase {
public:
    FAMTarget();                                // 0x801AE88C (4800 bytes)
    ~FAMTarget();                               // 0x801AFB4C
    void UnloadScreen();                        // 0x801AFCAC
    void SetVariable(char* name, char* value);  // 0x801AFCD8
    unsigned short* GetLocalizable(char* name); // 0x801AFEB8 (1832 bytes)
    char* GetVariable(char* name);              // 0x801B05E0
    void Shutdown();                            // 0x801B070C (empty)
    void Update();                              // 0x801B0710 (empty)
    void UpdateMenuState(char* name, char* value); // 0x801B0714
    void UpdateText();                          // 0x801B0750 (empty stub)
    void OnLeftKeyPressed(char* name, char* value);  // 0x801B075C (empty)
    void OnRightKeyPressed(char* name, char* value); // 0x801B0760 (empty)
    void UpdateShaders();                       // 0x801B0764
    void UpdateOccupiedShaders();               // 0x801B07B0
    void UpdateLotSelectShaders();              // 0x801B0950
    void UpdateTempShaders();                   // 0x801B0B18

    // Family/Lot data access
    unsigned short* GetFamilyText(char* key, unsigned short* buf);    // 0x801B0B78
    void OnLotSelect();                                               // 0x801B0CCC
    Family* GetFamilyInFamilyList(int index);                         // 0x801B0D1C
    int  DoesFamilyExistInFamilyChoice(int familyID);                 // 0x801B0D5C
    int  ConvertSelectedFamilyIndexToActualGameIndex(int index);      // 0x801B0DAC (returns index + 20)
    int  GetNumberOfFamilyMembers(Family* family);                    // 0x801B0DB4
    int  IsSelectedLotOccupied();                                     // 0x801B0DF8

    // Dialog callbacks
    void OnCancelDialog();                      // 0x801B0E6C (empty)
    void OnDialogSelection(int selection);      // 0x801B0E70
    void OnReturnFromCreateAFamily(bool created); // 0x801B1078
    void OnBackoutToMainMenuDialogClose(int result); // 0x801B1128

    // Input handlers
    void OnCancelKeyPressed(char* name, char* value); // 0x801B1158 (644 bytes)
    void OnUpKeyPressed(char* name, char* value);     // 0x801B13DC
    void OnDownKeyPressed(char* name, char* value);   // 0x801B1500
    void OnXKeyPressed(char* name, char* value);      // 0x801B1640 (4036 bytes - massive)
    void OnCircleKeyPressed(char* name, char* value); // 0x801B2604 (empty)

    // State machine
    void UpdateMenuState(int state);            // 0x801B2608 (908 bytes)
    int  GetNumberOfChoicesInState(int state);  // 0x801B2994
    int  ConvertSelectedLotIndexToActualGameIndex(int index); // 0x801B29F8 (returns index)
    void GoUpMenuTree();                        // 0x801B29F8

    // Lot/Family display helpers
    unsigned short* GetNameForFamilyInLotSelect(char* key, unsigned short* buf); // 0x801B2B00
    unsigned short* GetMoneyForFamilyInLotSelect(char* key, unsigned short* buf); // 0x801B2C14
    void UpdateFamilySelectShaders();           // 0x801B2CD4
    unsigned short* GetSelectedLotDescription(unsigned short* buf); // 0x801B2EC0
    void ConvertNumericMoneyToString(int money, unsigned short* buf); // 0x801B2F28
    unsigned short* GetMoneyForFamily(Family* family, unsigned short* buf); // 0x801B2F8C
    char* GetLotName(int lotIndex);             // 0x801B3024
    unsigned short* GetNameForFamily(Family* family, unsigned short* buf); // 0x801B3074
    void SetCurrentChoice(char* choice);        // 0x801B3130
    Family* GetFamilyInLot(int lotIndex);       // 0x801B3204
    void LaunchLot();                           // 0x801B3244
    int  GetMoneyForLot(int lotIndex);          // 0x801B3284
    void EvictFamily();                         // 0x801B3314
    int  GetLotForFamily(Family* family);       // 0x801B3388
    int  GetLotForFamily(int familyID);         // 0x801B33CC
    char* GetLotNameInFamilySelect(char* key);  // 0x801B340C
};


// =============================================================================
// MMUTarget - Main Menu Controller
// =============================================================================
// Virtual table at 0x804677F0 (64 bytes)
// Singleton: MMUTarget::m_MMUSingleton at 0x804FE33C
// Widget data: Widget_MMUTarget at 0x8042D110 (3424 bytes)
// Size: 0x360 (864 bytes)
//
// MMUTarget manages the main menu screen. It handles:
//   - Top-level menu choices (New Game, Continue, Options, Credits)
//   - Gameplay mode selection (Story, Freeplay)
//   - Number of players selection (1P, 2P)
//   - Neighborhood list browsing
//   - Lot list browsing
//   - Controller detection for multiplayer
//
// === Menu State Machine ===
// Uses std::stack<MMU_MENU_STATE> for hierarchical navigation:
//   TOP_LEVEL -> GAMEPLAY -> NUM_PLAYERS -> NGH_SELECT -> LOT_SELECT
// Navigation: OnXKeyPressed goes deeper, GoUpMenuTree pops back.
//
// === Screen Modes ===
// m_listItemName (offset 0x8C) tracks which list mode is active:
//   0 = normal menu
//   1 = neighborhood list
//   2 = lot list

class MMUTarget : public UIObjectBase {
public:
    MMUTarget();                                // 0x801C49C0 (3696 bytes)
    ~MMUTarget();                               // 0x801C5830

    static MMUTarget* GetSingleton();           // 0x801C59E0
    void OnCreditsClose();                      // 0x801C59E8

    void SetVariable(char* name, char* value);  // 0x801C59F4 (988 bytes)
    char* GetVariable(char* name);              // 0x801C5DD0
    unsigned short* GetLocalizable(char* name); // 0x801C5F80 (1092 bytes)

    void Update();                              // 0x801C63C4 (268 bytes)
    void Draw(ERC* rc);                         // 0x801C64D0 (372 bytes)

    // List management
    char* GetListItemName(char* name);          // 0x801C6644
    void ChangeScreenMode();                    // 0x801C668C
    void UpdateListItems();                     // 0x801C6758
    void UpdateNGHListItems();                  // 0x801C679C (332 bytes)
    void UpdateLotListItems();                  // 0x801C68E8 (292 bytes)
    char* GetNGHListItemName(char* name);       // 0x801C6A0C
    char* GetLotListItemName(char* name);       // 0x801C6B54
    void EnterLot(int lotIndex);                // 0x801C6BFC (404 bytes)
    void LaunchLot(int lotIndex);               // 0x801C6D90
    void LaunchFreeplay();                      // 0x801C6DF0

    // Input handlers
    void OnUpKeyPressed(char* name, char* value);     // 0x801C6E5C
    void OnDownKeyPressed(char* name, char* value);   // 0x801C6EE8
    void OnLeftKeyPressed(char* name, char* value);   // 0x801C6F84
    void OnRightKeyPressed(char* name, char* value);  // 0x801C6FA4
    void EndPlayerNumberChooser();                    // 0x801C70F0
    void OnXKeyPressed(char* name, char* value);      // 0x801C7168 (1636 bytes - massive)
    void OnCancelKeyPressed(char* name, char* value); // 0x801C77CC
    void OnCircleKeyPressed(char* name, char* value); // 0x801C781C

    // Choice change callbacks
    void UpdateTopLevelChoice(char* name, char* value);        // 0x801C786C
    void UpdateGameplayChoice(char* name, char* value);        // 0x801C78B0
    void UpdateNumberOfPlayersChoice(char* name, char* value); // 0x801C78F4
    void OnTopLevelChoiceChange();              // 0x801C7938
    void OnGameplayLevelChoiceChange();         // 0x801C7958
    void OnNumberOfPlayersChoiceChange();       // 0x801C7978

    void UpdateText();                          // 0x801C7998 (1000 bytes)
    void UpdateMenuState(char* name, char* value); // 0x801C7D80
    void GoUpMenuTree(char* name, char* value); // 0x801C7F24 (416 bytes)
    int  GetNumberOfControllers();              // 0x801C80C4 (284 bytes)
    int  GetNumberOfChoicesInState(int state);  // 0x801C81E0
    void IncrementChoice(char* name, char* value); // 0x801C8228
    void SetCurrentChoice(char* choice);        // 0x801C8364
    void DecrementChoice(char* name, char* value); // 0x801C8420
    void OnStartGameComplete(bool success);     // 0x801C8550

    void UpdateDevMenuState(char* name, char* value); // 0x801C85D0
    void OnNGHSelect(char* name, char* value);  // 0x801C861C
    void ChangeScreenMode(int mode);            // 0x801C86B4
    void PollControllersForNumOfPlayersState(); // 0x801C86C4

    // Dialog callbacks
    void OnDialogClose(int result);             // 0x801C8720
    void OnCancelDialog();                      // 0x801C8788 (empty)
    void OnDialog2Close(int result);            // 0x801C878C (empty)
    void OnCancelDialog2();                     // 0x801C8790 (empty)
    void Dialog2ClosedCallback();               // 0x801C8794

    int GetCurrentMainScreenChoice() const;     // 0x801E7078
    int GetCurrentGameplayChoice() const;       // 0x801E7080
};


// =============================================================================
// M2MTarget - Memory Card / Save-Load Management Controller
// =============================================================================
// Virtual table at 0x804676D8 (64 bytes)
// Inner vtables: M2MTarget::UIDialog at 0x804676A8 (48 bytes)
// Size: 0x23E8 (9192 bytes - large due to embedded widget data)
//
// M2MTarget is the memory card management screen. It coordinates:
//   - Memory card slot selection
//   - Save game slot selection
//   - New game start with memory card checks
//   - Save/Load operations through LoadGameTarget/SaveGameTarget
//   - Memory card format prompts
//   - Error dialogs (no card, damaged card, corrupt data, no space)
//
// This Target acts as a parent controller that spawns LoadGameTarget and
// SaveGameTarget as child controllers for actual I/O operations.
//
// === Widget State Machine ===
// M2MTarget::WidgetState controls the displayed widget:
//   Various states for mem card select, save slot select, confirmation, etc.
// SetCurrState() handles transitions between states.

class M2MTarget : public UIObjectBase {
public:
    M2MTarget();                                // 0x801BF058 (3204 bytes)
    ~M2MTarget();                               // 0x801BFCDC

    char* GetVariable(char* name);              // 0x801BFEE8
    unsigned short* GetLocalizable(char* name); // 0x801C00A0
    void SetVariable(char* name, char* value);  // 0x801C02EC

    void ReflowButtonSelection();               // 0x801C0464 (1020 bytes)
    void Update();                              // 0x801C05A4 (1020 bytes)
    void SelectionCallback(int selection);      // 0x801C09A0 (764 bytes)
    void ZeroInputCallback();                   // 0x801C0C9C (empty)
    void DialogClosedCallback();                // 0x801C0CA0
    void OnCancel();                            // 0x801C0D08
    void OnSaveLoadSucceed();                   // 0x801C0D94
    void OnSaveLoadFailed();                    // 0x801C0EC8 (460 bytes)

    void OnSlotSelectItemSelected(int slot, void* result); // 0x801C1094
    void OnGetNumItems(void* result);           // 0x801C10C8
    int  GetDevice();                           // 0x801C1108
    void SetDevice(int device);                 // 0x801C1110
    int  GetSaveGameID();                       // 0x801C113C
    int  GetMemCardPort();                      // 0x801C1144

    // Error/confirmation dialogs
    void SpawnNoSpaceDialog();                  // 0x801C115C
    void SpawnConfirmStartNewGameDialog();      // 0x801C12A8
    void SpawnContinueNoMemCardDialog();        // 0x801C13EC
    void SpawnSaveBeforeQuitCASDialog();        // 0x801C1540
    void SpawnSaveBeforeQuitGameDialog();       // 0x801C16AC
    void SpawnNoSaveBeforeQuitDialog();         // 0x801C1818
    void SpawnStartNGCNoMemCardDialog();        // 0x801C195C

    // Item text/enable for slot selection
    unsigned short* GetItemTextMemCardSelect(int slot, unsigned short* buf); // 0x801C1AA0
    unsigned short* GetItemTextSaveGameSelect(int slot, unsigned short* buf); // 0x801C1BE8
    int  IsItemEnabledMemCardSelect(int slot);  // 0x801C1C40
    int  IsItemEnabledSaveGameSelect(int slot); // 0x801C1D00 (returns 1 always)
    void DoesMemoryDeviceExist();               // 0x801C1D08
    void StartLoadedGame();                     // 0x801C1D70
    void ReturnFailureDestination();            // 0x801C1DE0
    void StartNGCMemoryCardBootChecks();        // 0x801C1EC4

    // Widget display management
    void UpdateWidgetState();                   // 0x801C1F64
    void FillWidget();                          // 0x801C2104
    void HideWidget();                          // 0x801C21D8
    void SetupWidgetLayout();                   // 0x801C2278 (1748 bytes)
    void UpdateSelection(int selection);        // 0x801C294C
    int  IsItemEnabled(int slot);               // 0x801C29C4
    void CalcNumItems();                        // 0x801C2A24
    void SetCurrState(int state);               // 0x801C2A74 (780 bytes)
    void UnloadDialog();                        // 0x801C2D80
    void PrepareNewGame();                      // 0x801C2E28
    void PrepareLoadGame();                     // 0x801C2E78
    void PushButtonFilters();                   // 0x801C2EF4
    void PopButtonFilters();                    // 0x801C2F6C

    int GetPlayerNum();                         // 0x801E7090
};


// =============================================================================
// LoadGameTarget - Load Game Operation Controller
// =============================================================================
// Virtual tables:
//   LoadGameTarget at 0x80466918 (64 bytes)
//   LoadGameTarget::UIDialog at 0x804668E8 (48 bytes)
//   LoadGameTarget::MemCardSaveLoad at 0x804668C8 (32 bytes)
// Size: 0x14C (332 bytes)
//
// LoadGameTarget handles the actual load game operation. It is created by
// M2MTarget and manages:
//   - Memory card validation (correct device, undamaged, correct save)
//   - Save file integrity checks
//   - Background load execution (via BGExec_PerformLoad thread)
//   - Memory card format flow (if card needs formatting)
//   - Extensive error dialog chain for every possible failure mode
//
// The load process runs on a background thread:
//   1. PerformMemoryCardChecks() - validate hardware
//   2. PerformLoad() / BackgroundPerformLoad() - read data from card
//   3. BGExec_PerformLoad() - thread entry point
//   4. BGCall_PerformLoad() - called from main thread to start BG load
//   5. Update() polls for completion, shows success/failure dialog

class LoadGameTarget {
public:
    LoadGameTarget(M2MTarget* parent, int device, int slot); // 0x80189AD0 (1840 bytes)
    ~LoadGameTarget();                          // 0x8018A200

    void SelectionCallback(int selection);      // 0x8018A374 (840 bytes)
    void ZeroInputCallback();                   // 0x8018A6BC
    void Update();                              // 0x8018A708 (992 bytes)
    int  GetResult();                           // 0x8018AAE8
    void ImportLoad(int sectionID, void* record); // 0x8018AAF0 (empty)

    void PerformMemoryCardChecks();             // 0x8018AAF4 (580 bytes)
    void PerformLoad();                         // 0x8018AD38 (348 bytes)

    // Extensive dialog chain for error handling
    void SpawnCheckingDialog();                 // 0x8018AE94
    void SpawnWrongDeviceDialog();              // 0x8018AFC4 (552 bytes)
    void SpawnCardDamagedDialog();              // 0x8018B1EC (616 bytes)
    void SpawnCardCorruptDialog();              // 0x8018B454 (568 bytes)
    void SpawnWrongSaveDialog();                // 0x8018B68C (568 bytes)
    void SpawnNoSaveDialog();                   // 0x8018B8C4 (376 bytes)
    void SpawnLoadConfirmDialog();              // 0x8018BA3C (420 bytes)
    void SpawnLoadingDialog();                  // 0x8018BBE0 (296 bytes)
    void SpawnLoadSucceededDialog();            // 0x8018BD08 (284 bytes)
    void SpawnLoadFailedDialog();               // 0x8018BE24 (568 bytes)
    void SpawnMemCardRemovedDialog();           // 0x8018C05C (356 bytes)
    void SpawnSameCardDialog();                 // 0x8018C1C0 (284 bytes)

    // Memory card format sub-flow
    void SpawnFormatDecideDialog();             // 0x8018C2DC (324 bytes)
    void SpawnFormatConfirmDialog();            // 0x8018C420 (324 bytes)
    void SpawnFormattingDialog();               // 0x8018C564 (208 bytes)
    void SpawnFormatCancelDialog();             // 0x8018C634 (324 bytes)
    void SpawnFormatFailDialog();               // 0x8018C778 (516 bytes)
    void SpawnFormatSuccessDialog();            // 0x8018C97C (276 bytes)

    // Background thread operations
    void BackgroundPerformLoad();               // 0x8018CA90 (432 bytes)
    void BGCall_PerformLoad();                  // 0x8018CC40
    static void BGExec_PerformLoad(void* arg);  // 0x8018CC8C

    void ImportSave(int sectionID, void* record);         // 0x8018CCBC (empty)
    void ImportSaveComplete(int sectionID, void* record); // 0x8018CCC0 (empty)
    int  GetDevice();                           // 0x8018CCC4
    int  GetPlayerNum();                        // 0x8018CCE8
    int  GetSaveGameID();                       // 0x8018CCF4
};


// =============================================================================
// SaveGameTarget - Save Game Operation Controller
// =============================================================================
// Virtual tables:
//   SaveGameTarget at 0x804669C8 (72 bytes)
//   SaveGameTarget::UIDialog at 0x80466998 (48 bytes)
//   SaveGameTarget::MemCardSaveLoad at 0x80466978 (32 bytes)
// Size: 0x168 (360 bytes)
//
// SaveGameTarget handles save game operations. Like LoadGameTarget, it is
// created by M2MTarget. It manages:
//   - Memory card validation
//   - Space availability checks
//   - Overwrite confirmation
//   - Background save execution (BGExec_SaveGame thread)
//   - Error/success dialog chain
//
// Additional complexity vs LoadGameTarget:
//   - NoSpaceType enum for different "no space" scenarios
//   - Overwrite confirmation dialog
//   - Hide() method to dismiss the save UI

class SaveGameTarget {
public:
    SaveGameTarget(M2MTarget* parent, int device, int slot); // 0x8018CD18 (1888 bytes)
    ~SaveGameTarget();                          // 0x8018D478

    void SelectionCallback(int selection);      // 0x8018D5EC (756 bytes)
    void ZeroInputCallback();                   // 0x8018D8E0 (220 bytes)
    void Update();                              // 0x8018D9BC (1064 bytes)
    void Hide();                                // 0x8018DE08
    int  GetResult();                           // 0x8018DE08

    void PerformMemoryCardChecks();             // 0x8018DE10 (664 bytes)

    // Dialog chain
    void SpawnCheckingDialog();                 // 0x8018E0A8
    void SpawnCardCorruptDialog();              // 0x8018E1D8 (460 bytes)
    void SpawnWrongDeviceDialog();              // 0x8018E3A4
    void SpawnCardDamagedDialog();              // 0x8018E508 (468 bytes)
    void SpawnFormatDecideDialog();             // 0x8018E6DC
    void SpawnFormatConfirmDialog();            // 0x8018E840
    void SpawnFormattingDialog();               // 0x8018E99C
    void SpawnFormatCancelDialog();             // 0x8018EA84
    void SpawnFormatFailDialog();               // 0x8018EBE0
    void SpawnFormatSuccessDialog();            // 0x8018ED3C
    void SpawnNoSpaceDialog(int noSpaceType);   // 0x8018EE6C (612 bytes)
    void SpawnOverwriteDialog();                // 0x8018F0D0 (420 bytes)
    void SpawnSaveConfirmDialog();              // 0x8018F274 (424 bytes)
    void SpawnSavingDialog();                   // 0x8018F41C
    void SpawnSaveSucceededDialog();            // 0x8018F544
    void SpawnSaveFailedDialog();               // 0x8018F660 (376 bytes)
    void SpawnMemCardRemovedDialog();           // 0x8018F7D8

    void PerformSaveGame();                     // 0x8018F944 (1452 bytes - very large)

    // Background thread operations
    void BGCall_SaveGame();                     // 0x8018FEF0
    static void BGExec_SaveGame(void* arg);     // 0x8018FF3C

    int GetDevice();                            // 0x8018FF8C
    int GetPlayerNum();                         // 0x8018FFB0
    int GetSaveGameID();                        // 0x8018FFBC
};


// =============================================================================
// KEYTarget - Keyboard/Input Configuration Controller
// =============================================================================
// Virtual table at 0x80467C18 (64 bytes)
// Inner vtable: KEYTarget::CasListener at 0x80467BB8 (96 bytes)
// Size: 0x90 (144 bytes)
//
// KEYTarget manages the input/keyboard configuration screen. It handles
// button remapping for game controls and validates that the current
// control mode is supported.
//
// Notable: Has a CasListener inner class (96-byte vtable) suggesting it
// listens for CAS (Create-A-Sim) state changes to adjust controls.

class KEYTarget : public UIObjectBase {
public:
    KEYTarget();                                // 0x801F91A0 (1636 bytes)
    ~KEYTarget();                               // 0x801F9804

    // 0x801F9960 - Get control scheme name (156 bytes)
    char* GetName();

    // 0x801F99FC - Check if current control mode is supported (32 bytes)
    int IsModeValid();

    // 0x801F9A1C - Set key binding (428 bytes)
    void SetVariable(char* name, char* value);

    // 0x801F9BC8 - Get key binding info (384 bytes)
    char* GetVariable(char* name);
};


// =============================================================================
// CSMTarget - CSIM (Create-A-Sim Integration Menu) Controller
// =============================================================================
// Virtual table at 0x804677B0 (64 bytes)
// Size: 0xF0 (240 bytes)
//
// CSMTarget manages the Create-A-Sim integration menu - the UI overlay
// shown during CAS mode for navigation between CAS sub-screens.
// It provides show/hide control and a temporary interface for CAS options.

class CSMTarget : public UIObjectBase {
public:
    CSMTarget(int player);                      // 0x801A61D0 (1968 bytes)
    ~CSMTarget();                               // 0x801A6980

    void SetVariable(char* name, char* value);  // 0x801A6B34
    char* GetVariable(char* name);              // 0x801A6C3C
    unsigned short* GetLocalizable(char* name); // 0x801A6CD4

    // 0x801A6E00 - Frame update (2124 bytes - large state machine)
    void Update();

    // Show/hide the CSIM overlay
    void ShowCSIM();                            // 0x801A764C (20 bytes: m_showCSIM=1, m_field98=0)
    void HideCSIM();                            // 0x801A7660 (20 bytes: if m_field98==0, m_showCSIM=0)
    int  IsCSIMActive();                        // 0x801A7674 (8 bytes: return m_isActive)

    // 0x801A767C - Create temporary CAS interface (1036 bytes)
    // Takes 4 BString2 parameters for option labels, plus enable flags
    void TempInterface(BString2* opt1, BString2* opt2, BString2* opt3, BString2* opt4,
                       bool enableOpt3, bool enableOpt4);

    void SetIconDisable(bool disable);          // 0x801A7A88 (160 bytes)
};


// =============================================================================
// UI FLOW DIAGRAM
// =============================================================================
//
// Boot -> TheSimsStartScreenStateMachine
//      -> TheSimsMaxisLogoState (logo movies)
//      -> TheSimsNGCLicenseState (license screen)
//      -> TheSimsMemCardCheckState (memory card boot check)
//           -> M2MTarget (if mem card issues)
//      -> TheSimsMainMenuState
//           -> MMUTarget (main menu)
//                |
//                +-> "New Game" -> M2MTarget (mem card) -> FAMTarget (lot select) -> Live Mode
//                +-> "Continue" -> M2MTarget (load game) -> LoadGameTarget -> Live Mode
//                +-> "Options"  -> O2TTarget (options menu)
//                +-> "Credits"  -> Credits screen
//
// Live Mode (HUDTarget active):
//      HUDTarget manages:
//        - ACTTarget (action queue per player)
//        - CSMTarget (CAS integration overlay)
//        - Speed controls, motive bars, clock
//        - Action menus (pie menus)
//
//      From Live Mode:
//        +-> "Pause" -> O2TTarget (in-game options)
//        +-> "CAS"   -> HUDTarget::GotoCAS -> CAS screens (KEYTarget active)
//        +-> "Save"  -> M2MTarget -> SaveGameTarget
//        +-> "Quit"  -> M2MTarget -> back to MMUTarget
//
// EyeToy (E2ETarget):
//      Accessible from options or dedicated EyeToy menu entry.
//      Manages camera hardware, capture, and save operations.
//
// Dialog System (DlgWrapper):
//      Used by O2TTarget, E2ETarget, FAMTarget, MMUTarget, M2MTarget,
//      LoadGameTarget, and SaveGameTarget for modal confirmation/error dialogs.
//      Each Target typically embeds or references DlgWrapper instances
//      for their various dialog needs.
//
// =============================================================================
// CALLBACK REGISTRATION PATTERN
// =============================================================================
//
// Each Target constructor follows this pattern to register with APT:
//
//   1. Call Wrapper::WrapperStartup(this) to initialize the APT connection
//   2. Create CBFunctor callbacks using CBMemberTranslator templates:
//      - CBMemberTranslator2<char*, char*, TargetClass, void (TargetClass::*)(TargetClass*, char*, char*)>
//        -> For SetVariable callbacks (APT sends variable name + value)
//      - CBMemberTranslator1wRet<char*, char*, TargetClass, char* (TargetClass::*)(TargetClass*, char*)>
//        -> For GetVariable callbacks (APT requests variable value)
//      - CBMemberTranslator1wRet<char*, wchar_t*, TargetClass, wchar_t* (TargetClass::*)(TargetClass*, char*)>
//        -> For GetLocalizable callbacks (APT requests localized string)
//      - CBMemberTranslator0<TargetClass, void (TargetClass::*)(TargetClass*)>
//        -> For Update callbacks (per-frame tick)
//      - CBMemberTranslator1<ERC*, TargetClass, void (TargetClass::*)(TargetClass*, ERC*)>
//        -> For Draw callbacks (per-frame render)
//   3. Register input handler callbacks for controller buttons:
//      OnXKeyPressed, OnCircleKeyPressed, OnUpKeyPressed, etc.
//      These are registered as CBFunctor2 with (char*, char*) parameters
//   4. Additional callbacks for dialog close events:
//      CBMemberTranslator1<int, TargetClass, void (...)> for dialog result callbacks
//
// The thunk functions (at 0x803Bxxxx) extract the 'this' pointer from
// CBFunctorBase and call the actual member function.
