// ============================================================================
// InteractorModule System Decompilation
// The Sims 2 GameCube — Build Mode Wall/Floor/Object Placement & Manipulation
//
// Source files in original build:
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\interactor.obj
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\directinteractor.obj
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\siminteractor.obj
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\socialmodeinteractor.obj
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\interactormanager.obj
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\objectmanipulator.obj
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\wallmanipulator.obj
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\wallpainter.obj
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\floorpainter.obj
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\interactorvisualizer.obj
//
// 597 total symbols across the InteractorModule namespace.
// This file documents the complete interactor state machine, input handling,
// and build mode operations as decompiled from PowerPC assembly.
//
// Decompiled classes:
//   InteractorModule::Interactor          (base, 32 functions)
//   InteractorModule::DirectInteractor    (43 functions)
//   InteractorModule::SimInteractor       (40 functions)
//   InteractorModule::SocialModeInteractor(21 functions)
//   InteractorModule::InteractorManager   (19 functions)
//   InteractorModule::InteractorInputManager (14 functions)
//   InteractorModule::InteractorVisualizer(55 functions)
//   InteractorModule::ObjectManipulator   (18 functions)
//   InteractorModule::GrabManipulator     (16 functions)
//   InteractorModule::PlaceManipulator    (11 functions)
//   InteractorModule::PlacementObject     (23 functions)
//   InteractorModule::WallManipulator     (62 functions)
//   InteractorModule::WallPainter         (50 functions)
//   InteractorModule::FloorPainter        (47 functions)
//   InteractorModule::InteractorResourceSet(16 functions)
//   + free functions, callbacks, statics
// ============================================================================

#include "build_mode/interactor.h"
#include "build_mode/wallmanipulator.h"

// Forward declarations for external systems
class EHouse;
class ELevelDrawData;
class EOrderTableData;
class EMat4;
class ERShader;
class ERC;
class Room;
class FloorPattern;
class WallPattern;
class WallStyle;
class TileWalls;
class TileWallsSegment;
class TilePtDir;
class DiagonalSideSelector;
struct CTilePt;
struct FTilePt;
struct ObjSelector;
class cXObjectImpl;
class cXMTObjectImpl;
class InteractionList;

// External functions
extern "C" {
    void* operator_new(unsigned long);          // 0x802d11b0
    void operator_delete(void*);                // 0x802d1220
    void* alloca_small(unsigned long);          // 0x8039c304
}

// SDA-relative globals (r13 offsets)
namespace {
    // Game state singletons accessed via r13
    // r13-21472: EHouse* g_pHouse
    // r13-21488: world bounds pointer
    // r13-31536: sound effect handle (lazy-allocated)
    // r13-21224: tile data pointer
    // r13-21202: tile data 2
}

// ============================================================================
//
//     ARCHITECTURE OVERVIEW: The InteractorModule State Machine
//
// ============================================================================
//
// The InteractorModule system is EA's build/buy mode controller for
// The Sims 2 on GameCube. It manages all player input for:
//   - Direct sim control (walking around, selecting objects)
//   - Cursor-based sim selection (SimInteractor)
//   - Social interaction menus (SocialModeInteractor)
//   - Build mode wall placement/deletion (WallManipulator)
//   - Build mode wallpaper application (WallPainter)
//   - Build mode floor tile placement (FloorPainter)
//   - Buy mode object grab/place (GrabManipulator / PlaceManipulator)
//
// ---- Class Hierarchy ----
//
//   Interactor (base, 0x60 bytes)
//     +-- DirectInteractor    (live mode, direct sim control)
//     +-- SimInteractor       (live mode, cursor-based sim selection)
//     +-- SocialModeInteractor(live mode, social interaction menus)
//     +-- ObjectManipulator   (buy mode base)
//     |     +-- GrabManipulator   (pick up existing objects)
//     |     +-- PlaceManipulator  (place new objects from catalog)
//     +-- WallManipulator     (build mode, wall segments + rooms)
//     +-- WallPainter         (build mode, wallpaper application)
//     +-- FloorPainter        (build mode, floor tile painting)
//
// ---- Interactor Lifecycle ----
//
//   1. InteractorManager::Initialize() creates one set of interactors per player
//      (up to 2 players for split-screen).
//   2. Each player gets one instance of every interactor type stored in
//      InteractorManager's player arrays.
//   3. The active interactor is switched via InteractorManager, which calls
//      OnStop on the old interactor and OnStart on the new one.
//   4. Every frame, InteractorManager::UpdateActivePlayerInteractors() calls:
//        - InputManager::Update() to dispatch controller input
//        - active_interactor->Update(dt) for game logic
//   5. Drawing is handled separately through InteractorVisualizer, which
//      has type-specific PreDraw/Draw overloads for each interactor type.
//
// ---- Input Pipeline ----
//
//   Controller -> InteractorInputManager::InstanceData::Update()
//     -> Maps physical buttons/sticks to InteractorCommands
//     -> Dispatches to active Interactor via:
//        OnCommandPressed(cmd, value)   -- button down
//        OnCommandReleased(cmd)         -- button up
//        OnCommandUpdate(cmd, value)    -- analog stick per-frame
//
// ---- InteractorCommand Enum (partial) ----
//
//   0 = kCmdAction           (A button - confirm/place/build)
//   1 = kCmdCancel           (B button - cancel/undo)
//   2 = kCmdSwapTool         (X button - swap between place/remove)
//   4 = kCmdExit             (Y button or trigger - exit mode)
//   7 = kCmdLeftStickX       (left analog X)
//   8 = kCmdLeftStickY       (left analog Y)
//   11 = kCmdRightStickX     (right analog X / C-stick X)
//   12 = kCmdRightStickY     (right analog Y / C-stick Y)
//   18 = kCmdCameraX         (camera rotation X)
//   19 = kCmdCameraY         (camera rotation Y)
//
// ============================================================================


// ============================================================================
//
//     SECTION 1: Interactor Base Class
//     Address range: 0x80209280 - 0x802095E4
//     32 functions, sizes 4 - 196 bytes
//
// ============================================================================

namespace InteractorModule {

// ---------------------------------------------------------------------------
// Interactor::Interactor() — 0x802091BC, 196 bytes
// ---------------------------------------------------------------------------
// Initializes all base class fields to zero/defaults.
// Sets vtable pointer at offset 0x5C to the Interactor vtable (0x80468270).
// Layout:
//   0x00: m_playerId      (u32)
//   0x04: m_camera         (ESimsCam*)
//   0x08: m_pos            (EVec3 - 12 bytes)
//   0x14: m_prevPos        (EVec3 - 12 bytes)
//   0x20: m_snappedPos     (EVec3 - 12 bytes)
//   0x2C: m_snapped        (u32 - bool)
//   0x30: m_inputState     (u32)
//   0x34: m_leftStick      (EVec2 - 8 bytes)
//   0x3C: m_rightStick     (EVec2 - 8 bytes)
//   0x44: m_leftStickActive  (u32)
//   0x48: m_rightStickActive (u32)
//   0x4C: m_drawState      (u32)
//   0x50: m_extents        (EVec2 - 8 bytes)
//   0x58: m_idleTime       (f32)
//   0x5C: m_vtable         (void* - SN Systems vtable pointer)
Interactor::Interactor() {
    m_playerId = 0;
    m_camera = 0;
    m_pos.x = 0.0f;   m_pos.y = 0.0f;   m_pos.z = 0.0f;
    m_prevPos.x = 0.0f; m_prevPos.y = 0.0f; m_prevPos.z = 0.0f;
    m_snappedPos.x = 0.0f; m_snappedPos.y = 0.0f; m_snappedPos.z = 0.0f;
    m_snapped = 0;
    m_inputState = 0;
    m_leftStick.x = 0.0f;  m_leftStick.y = 0.0f;
    m_rightStick.x = 0.0f; m_rightStick.y = 0.0f;
    m_leftStickActive = 0;
    m_rightStickActive = 0;
    m_drawState = 0;
    m_extents.x = 0.0f; m_extents.y = 0.0f;
    m_idleTime = 0.0f;
    // vtable set to InteractorModule::Interactor virtual table (0x80468270)
}

// ---------------------------------------------------------------------------
// Interactor::Update(float) — 0x80209280, 36 bytes
// ---------------------------------------------------------------------------
// Copies current position into previous position.
// Called at start of every interactor's Update to track movement.
// The load/store order (x, z, y) is characteristic of SN Systems codegen.
void Interactor::Update(float dt) {
    (void)dt;
    // m_prevPos = m_pos (as u32 triple copy for bit-exact float transfer)
    u32* src = (u32*)&m_pos;
    u32* dst = (u32*)&m_prevPos;
    dst[0] = src[0];  // x
    dst[2] = src[2];  // z
    dst[1] = src[1];  // y
}

// ---------------------------------------------------------------------------
// Interactor::NotifyClient() — 0x80209480, 56 bytes
// ---------------------------------------------------------------------------
// The callback dispatch mechanism. Stores notification state into the
// CallbackData struct, then invokes the callback function pointer stored
// in InteractorParams (offset 0x08 = callback data offset, 0x0C = fn ptr).
//
// This is how build mode operations report results back to the UI:
//   - WallManipulator::CommittTransaction calls NotifyClient to tell INVTarget
//     about placed/deleted walls
//   - FloorPainter does the same for floor tiles
//   - GrabManipulator/PlaceManipulator for objects
void Interactor::NotifyClient(
    ClientNotificationState state,
    CallbackData& data,
    InteractorParams& params)
{
    // data.state = (u32)state  -- store at data+0x00 (via r3->r4)
    *(u32*)&data = (u32)state;
    // data.field_04 = params.field_08  -- copy callback offset
    *((u32*)&data + 1) = *((u32*)&params + 2);
    // Call function pointer: params.field_0C(data)
    typedef void (*CallbackFn)(CallbackData&);
    CallbackFn fn = (CallbackFn)*((u32*)&params + 3);
    fn(data);
}

// ---------------------------------------------------------------------------
// Interactor::OnCommandReleased() — 0x802092EC, 104 bytes
// ---------------------------------------------------------------------------
// Handles stick release for camera control axes (commands 18, 19, 11, 12).
// Zeroes out the corresponding stick value AND the active flag.
// This is the base class handler; subclasses override for button commands.
void Interactor::OnCommandReleased(InteractorInputManager::InteractorCommand cmd) {
    if (cmd == 18) {
        m_leftStick.x = 0.0f;
        m_leftStickActive = 0;
    } else if (cmd == 19) {
        m_leftStick.y = 0.0f;
        // Note: does NOT clear leftStickActive here (only X axis clears it)
    } else if (cmd == 11) {
        m_rightStick.x = 0.0f;
        m_rightStickActive = 0;
    } else if (cmd == 12) {
        m_rightStick.y = 0.0f;
    }
}

// ---------------------------------------------------------------------------
// Interactor::OnCommandUpdate() — 0x80209354, 88 bytes
// ---------------------------------------------------------------------------
// Per-frame analog stick update. Stores float value and sets active flag.
// Commands 7/8 are left stick X/Y, 11/12 are right stick X/Y.
void Interactor::OnCommandUpdate(
    InteractorInputManager::InteractorCommand cmd, float value)
{
    if (cmd == 7) {
        m_leftStick.x = value;
        m_leftStickActive = 1;
    } else if (cmd == 8) {
        m_leftStick.y = value;
    } else if (cmd == 11) {
        m_rightStick.x = value;
        m_rightStickActive = 1;
    } else if (cmd == 12) {
        m_rightStick.y = value;
    }
}

// ---------------------------------------------------------------------------
// Interactor::ResetInputState() — 0x802093AC, 68 bytes
// ---------------------------------------------------------------------------
// Zeroes all stick values and active flags. Called on interactor switch.
void Interactor::ResetInputState() {
    m_leftStick.x = 0.0f;
    m_leftStick.y = 0.0f;
    m_rightStick.x = 0.0f;
    m_rightStick.y = 0.0f;
    m_leftStickActive = 0;
    m_rightStickActive = 0;
}

// ---------------------------------------------------------------------------
// Interactor::GetSelectionRadius() — 0x802093F0, 100 bytes
// ---------------------------------------------------------------------------
// Loads selection radius from a global float table indexed by interactor type.
// Base implementation checks a global "selection cone" table.
f32 Interactor::GetSelectionRadius() {
    // Loads from InteractorModule::c_SelectionConeAngle or similar SDA data
    // Returns a float used for cursor-to-object proximity testing
    return 0.0f; // NON_MATCHING: actual value from SDA
}

// ---------------------------------------------------------------------------
// Interactor::Moved() — 0x80209584, 72 bytes
// ---------------------------------------------------------------------------
// Compares current pos against previous pos. Returns 1 if any component changed.
int Interactor::Moved() {
    u32* cur = (u32*)&m_pos;
    u32* prev = (u32*)&m_prevPos;
    if (cur[0] != prev[0]) return 1;
    if (cur[1] != prev[1]) return 1;
    if (cur[2] != prev[2]) return 1;
    return 0;
}

} // namespace InteractorModule


// ============================================================================
//
//     SECTION 2: InteractorManager — The Orchestrator
//     Address range: 0x8020AFA8 - 0x8020C094
//     19 functions
//
// ============================================================================
//
// InteractorManager is a singleton that owns all interactor instances.
// It manages the lifecycle, switching, and per-frame update of interactors.
//
// Key data:
//   0x00: m_initialized       (u32)
//   0x04: m_maxPlayers         (u32, 1 or 2)
//   0x08: m_interactorTypes    (array of InteractorType enum per player)
//   0x0C: m_interactorArrays   (pointer to array of Interactor* arrays)
//   0x1C: m_activeInteractors  (per-player active interactor index)
//   0x2C: m_pendingInteractors (per-player pending interactor to switch to)
//   0x3C: m_flags              (u8, bitmask of pending-switch flags per player)
//
// Static singletons (SDA-relative):
//   s_pInteractorManager: 0x804FE9BC
//   s_pInputManager:      0x804FE9C0
//   s_pVisualizer:        0x804FE9C4
//

namespace InteractorModule {

// ---------------------------------------------------------------------------
// InteractorManager::Initialize() — 0x8020B1B8, 664 bytes
// ---------------------------------------------------------------------------
// Called from InitializeInteractorModule. Sets up:
//   - Allocates InteractorInputManager (one global instance)
//   - Allocates InteractorVisualizer (one global instance)
//   - Stores player count from params
//   - Creates per-player interactor arrays
//   - Sets all initial interactors to "null" type (-1)
// NON_MATCHING
void InteractorManager_Initialize_doc() {
    // InteractorManager::InteractorParams& params = ...;
    // m_maxPlayers = params.maxPlayers;
    // s_pInputManager = new InteractorInputManager(m_maxPlayers);
    // s_pVisualizer = new InteractorVisualizer();
    // CreatePlayerInteractorSets();
}

// ---------------------------------------------------------------------------
// InteractorManager::CreatePlayerInteractorSets() — 0x8020B6A8, 936 bytes
// ---------------------------------------------------------------------------
// Allocates one instance of each interactor type per player:
//   - DirectInteractor   (live mode, direct control)
//   - SimInteractor      (live mode, cursor selection)
//   - SocialModeInteractor (live mode, social menu)
//   - GrabManipulator    (buy mode, grab objects)
//   - PlaceManipulator   (buy mode, place new objects)
//   - WallManipulator    (build mode, walls)
//   - WallPainter        (build mode, wallpaper)
//   - FloorPainter       (build mode, floor tiles)
//
// Each is created with operator new, constructor called, then OnCreate called.
// Stored in per-player interactor arrays indexed by InteractorType enum.
// NON_MATCHING
void InteractorManager_CreatePlayerInteractorSets_doc() {
    // for each player:
    //   interactors[kDirectInteractor]  = new DirectInteractor;
    //   interactors[kSimInteractor]     = new SimInteractor;
    //   interactors[kSocialMode]        = new SocialModeInteractor;
    //   interactors[kGrabManipulator]   = new GrabManipulator;
    //   interactors[kPlaceManipulator]  = new PlaceManipulator;
    //   interactors[kWallManipulator]   = new WallManipulator;
    //   interactors[kWallPainter]       = new WallPainter;
    //   interactors[kFloorPainter]      = new FloorPainter;
    //   for each: interactor->OnCreate();
}

// ---------------------------------------------------------------------------
// InteractorManager::UpdateActivePlayerInteractors() — 0x8020BDF4, 680 bytes
// ---------------------------------------------------------------------------
// The main per-frame dispatch loop. For each player:
//
//   1. Check if there's a pending interactor switch (m_flags bit set).
//   2. If switching:
//      a. Call old interactor's OnStop() via vtable
//      b. Clear old interactor reference
//      c. If new type != -1, look up new interactor from arrays
//      d. Call new interactor's OnStart(params) via vtable
//      e. Store new interactor as active
//   3. Call InputManager->Update(dt) for this player to dispatch input
//   4. Call active interactor->Update(dt) via vtable
//
// The vtable dispatch pattern (seen throughout):
//   lwz r11, 0x5C(interactor)    // load vtable ptr
//   lha r3, offset(r11)          // load 'this' adjustment
//   lwz r0, offset+4(r11)        // load function pointer
//   add r3, interactor, r3       // adjust 'this'
//   mtlr r0; blrl                // call virtual function
//
// This is the SN Systems C++ ABI vtable format:
//   Each vtable entry is 8 bytes: [s16 this_adjust, s16 pad, u32 fn_ptr]
// NON_MATCHING
void InteractorManager_UpdateActivePlayerInteractors_doc() {
    // for (int player = 0; player < m_maxPlayers; player++) {
    //     if (m_flags & (1 << player)) {
    //         // Switch interactor
    //         Interactor* old = m_activeInteractors[player].interactor;
    //         if (old) old->OnStop();  // vtable call
    //         m_activeInteractors[player].interactor = NULL;
    //
    //         int newType = m_pendingInteractors[player];
    //         if (newType != -1) {
    //             Interactor* newInt = m_interactorArrays[player][newType];
    //             newInt->OnStart(&params);  // vtable call
    //             m_activeInteractors[player].interactor = newInt;
    //         }
    //         m_flags &= ~(1 << player);
    //     }
    //
    //     inputManager->Update(dt, player);
    //
    //     Interactor* active = m_activeInteractors[player].interactor;
    //     if (active) active->Update(dt);  // vtable call
    // }
}

} // namespace InteractorModule


// ============================================================================
//
//     SECTION 3: InteractorInputManager — Controller Input Mapping
//     Address range: 0x802096F8 - 0x8020AF88
//     14 functions
//
// ============================================================================
//
// InteractorInputManager translates raw GC controller inputs into
// InteractorCommands. Each player has an InstanceData that holds:
//   - Active interactor pointer
//   - Button-to-command mappings (ButtonSemantic array)
//   - Stick-to-command mappings (StickSemantic array)
//   - Controller filter ID (for split-screen input separation)
//
// The AddCommandMapping functions (2260 bytes each!) contain massive
// switch statements mapping every possible ECTRL_CMD to InteractorCommands.
//
// InstanceData::Update() runs every frame:
//   1. Polls raw controller state via ENgcController
//   2. For each mapped button: detect press/release transitions
//   3. For each mapped stick axis: read analog value
//   4. Dispatches to active interactor's OnCommandPressed/Released/Update
//

namespace InteractorModule {

// ---------------------------------------------------------------------------
// InteractorInputManager::InstanceData::OpenSession()
// 0x8020A968, 260 bytes
// ---------------------------------------------------------------------------
// Opens an input session for a player. Links an interactor to receive input.
// Stores the button and stick semantic arrays, sets up controller filtering.
//
// Params:
//   playerId: which player (0 or 1)
//   interactor: the interactor to receive input events
//   controllerFilter: which GC controller port to listen on
//   buttons: array of ButtonSemantic mappings
//   numButtons: count of button mappings
//   sticks: array of StickSemantic mappings
//   sessionName: debug string (unused in release)
// NON_MATCHING
void InteractorInputManager_OpenSession_doc() {}

// ---------------------------------------------------------------------------
// InteractorInputManager::InstanceData::Update(float)
// 0x8020AAF0, 716 bytes
// ---------------------------------------------------------------------------
// Per-frame input processing. The core input pipeline:
//
//   for each button mapping:
//       rawState = Controller::GetButton(mapping.controllerButton)
//       if (rawState && !prevState):
//           interactor->OnCommandPressed(mapping.command, 1.0f)
//       elif (!rawState && prevState):
//           interactor->OnCommandReleased(mapping.command)
//       prevState = rawState
//
//   for each stick mapping:
//       value = Controller::GetAxis(mapping.axis)
//       if (|value| > deadzone):
//           interactor->OnCommandUpdate(mapping.command, value)
//       elif (prevActive):
//           interactor->OnCommandReleased(mapping.command)
//
// This runs through the SN Systems vtable dispatch for each call.
// NON_MATCHING
void InteractorInputManager_InstanceData_Update_doc() {}

} // namespace InteractorModule


// ============================================================================
//
//     SECTION 4: DirectInteractor — Live Mode Direct Sim Control
//     Address range: 0x80203D70 - 0x80206200
//     43 functions, total ~7.2KB code
//
// ============================================================================
//
// DirectInteractor handles the primary live mode where the player directly
// controls their Sim with the analog stick. It manages:
//   - Sim movement via analog stick input
//   - Object highlighting and selection
//   - Action menu display on objects
//   - Camera-relative movement translation
//   - Autonomous mode (sim acts on its own)
//   - Cancel timer for queued actions
//
// Layout (extends Interactor, +0x60):
//   0x60: m_field_60          (u32 - movement state)
//   0x64: m_controlStatus     (u32 - 0=idle, 1=walking, 2=running)
//   0x68: m_field_68          (u32 - animation state)
//   0x6C: m_exitDirectControl (u32 - flag to exit direct control)
//   0x70: m_targetObject      (cXObject* - currently highlighted object)
//   0x74: m_field_74          (u32)
//   0x78: m_interactorInfo    (void* - position data for UI overlay)
//   0x7C: m_field_7C          (u32)
//   0x80: m_isAutonomous      (u32 - sim acting on its own)
//   0x84: m_cancelTimerActive (u32 - is cancel timer running)
//   0x88: m_cancelTimerValue  (f32 - accumulated cancel time)
//
// Static data:
//   s_invalidPos: 0x80487DE0, 12 bytes — sentinel position {-999, -999, -999}
//   c_DirectInteractorDeadZone: analog stick dead zone threshold
//   c_DirectInteractorTurnCutoff: minimum stick magnitude to turn sim
//   c_DirectInteractorWalkCutoff: minimum stick magnitude to walk
//

namespace InteractorModule {

// ---------------------------------------------------------------------------
// DirectInteractor::OnStart() — 0x80203E6C, 616 bytes
// ---------------------------------------------------------------------------
// Sets up direct control mode. Copies input mapping semantics from
// static tables (ButtonSemantic and StickSemantic arrays at specific
// ROM addresses) then opens an input session on the InteractorInputManager.
//
// Flow:
//   1. Copy ButtonSemantic table (24-byte struct, likely 2+ entries)
//      from ROM address 0x8040CA60 to local stack buffer
//   2. Copy StickSemantic table from ROM address 0x8040CA88
//   3. Store player ID from params
//   4. Copy session params struct from InteractorParams
//   5. Initialize movement state, clear highlights
//   6. Call InteractorInputManager::OpenSession with button/stick mappings
//   7. Call InitPlayerPos() to set initial cursor position at sim
//   8. Call SetupCamera() to configure camera tracking
// NON_MATCHING
void DirectInteractor_OnStart_doc() {}

// ---------------------------------------------------------------------------
// DirectInteractor::OnStop() — 0x802040D4, 136 bytes
// ---------------------------------------------------------------------------
// Tears down direct control:
//   1. Closes the input session on InteractorInputManager
//   2. Resets object highlights
//   3. Clears camera filter
// NON_MATCHING
void DirectInteractor_OnStop_doc() {}

// ---------------------------------------------------------------------------
// DirectInteractor::Update(float) — 0x80204838, 948 bytes
// ---------------------------------------------------------------------------
// The main per-frame update for direct sim control. This is the largest
// single function in DirectInteractor:
//
//   1. Call base Interactor::Update(dt) — saves prev position
//   2. If autonomous mode, skip input processing
//   3. ParseControls() — interpret analog stick into desired direction
//   4. If exit requested (m_exitDirectControl), trigger mode switch
//   5. UpdateControlStatus() — determine idle/walk/run based on stick magnitude
//   6. If moving:
//      a. InterpretFreeMoveInput() — translate camera-relative stick to world direction
//      b. SetVelocityModifiers() — apply walk/run speed
//      c. Send movement input to sim via ESim interface
//   7. UpdatePlumbBob() — position plumb bob (mood indicator) above sim
//   8. ShouldHighlightObject() — raycast from sim to find nearby objects
//   9. UpdateObjectHighlights() — highlight/unhighlight objects
//  10. Check cancel timer for queued action cancellation
//  11. CheckCancelTimer() — if held long enough, cancel queued action
//
// The movement uses camera-relative controls:
//   - Gets camera forward/right vectors from ESimsCam
//   - Projects stick input onto world plane
//   - Applies dead zone filtering (c_DirectInteractorDeadZone)
//   - Below walk cutoff = turn in place
//   - Above walk cutoff = walk
//   - Above run threshold = run
// NON_MATCHING
void DirectInteractor_Update_doc() {}

// ---------------------------------------------------------------------------
// DirectInteractor::OnCommandPressed() — 0x8020506C, 1644 bytes
// ---------------------------------------------------------------------------
// Handles button presses during direct control. The largest command handler.
//
// Command dispatch (from disassembly at 0x80205084):
//   cmd 0 (kCmdAction):
//     - If near a highlighted object, open action menu (ExecuteObjectActionMenu)
//     - If no object, attempt generic interaction
//     - Checks if sim is in social mode, redirects if needed
//   cmd 1 (kCmdCancel):
//     - Start cancel timer (for cancelling queued sim actions)
//     - If in object menu, close it (StopInObjectMenu)
//   cmd 2 (kCmdSwapTool):
//     - Toggle between different control modes
//   cmd 5 (kCmdMenu):
//     - Open pie menu / radial menu on highlighted object
//
// The function uses the m_field_160 and m_field_238 data (from the
// InteractorModule class layout) as global pointers to check game state
// before allowing certain actions.
// NON_MATCHING
void DirectInteractor_OnCommandPressed_doc() {}

// ---------------------------------------------------------------------------
// DirectInteractor::ExecuteActionMenu() — 0x802057C8, 664 bytes
// ---------------------------------------------------------------------------
// Opens an interaction/action menu on the currently highlighted object.
// Queries the object for available interactions, builds a list, then
// displays a pie menu for the player to select from.
// NON_MATCHING
void DirectInteractor_ExecuteActionMenu_doc() {}

// ---------------------------------------------------------------------------
// DirectInteractor::ShouldHighlightObject() — 0x80204C5C, 640 bytes
// ---------------------------------------------------------------------------
// Determines whether an object should be highlighted based on:
//   - Distance from sim to object
//   - Angle between sim's facing and direction to object
//   - Object visibility (not occluded by walls)
//   - Object interaction availability
//
// Uses GetSelectionRadius() and the selection cone angle constant.
// Returns the best candidate object or NULL.
// NON_MATCHING
void DirectInteractor_ShouldHighlightObject_doc() {}

// ---------------------------------------------------------------------------
// DirectInteractor::UpdateObjectHighlights() — 0x80205C4C, 872 bytes
// ---------------------------------------------------------------------------
// Scans all objects in the world via EIObjectMan to find objects within
// the selection cone. Updates highlight state (glow shader) on the
// nearest valid interactable object.
// NON_MATCHING
void DirectInteractor_UpdateObjectHighlights_doc() {}

// ---------------------------------------------------------------------------
// DirectInteractor::InitPlayerPos() — 0x80204220, 536 bytes
// ---------------------------------------------------------------------------
// Sets the cursor/interactor position to the sim's current world position.
// Called when entering direct control mode.
// NON_MATCHING
void DirectInteractor_InitPlayerPos_doc() {}

// ---------------------------------------------------------------------------
// DirectInteractor::InterpretFreeMoveInput() — 0x802046FC, 316 bytes
// ---------------------------------------------------------------------------
// Translates analog stick input into world-space movement direction.
// Uses camera orientation to determine forward/right vectors, then
// projects stick (x,y) onto these vectors to get a world direction.
//
// Output is stored to m_field_0B0/0B4/608 (movement vector and speed).
// NON_MATCHING
void DirectInteractor_InterpretFreeMoveInput_doc() {}

// ---------------------------------------------------------------------------
// DirectInteractor::UpdateControlStatus() — 0x8020450C, 184 bytes
// ---------------------------------------------------------------------------
// Determines sim movement speed based on stick magnitude:
//   magnitude < deadZone:     controlStatus = 0 (idle)
//   magnitude < walkCutoff:   controlStatus = 1 (turning)
//   magnitude >= walkCutoff:  controlStatus = 2 (walking/running)
//
// Uses c_DirectInteractorWalkCutoff and c_DirectInteractorTurnCutoff
// from SDA (.sdata2 section).
// NON_MATCHING
void DirectInteractor_UpdateControlStatus_doc() {}

} // namespace InteractorModule


// ============================================================================
//
//     SECTION 5: SimInteractor — Cursor-Based Sim Selection
//     Address range: 0x8021D250 - 0x8021F0EC
//     40 functions, total ~5.5KB code
//
// ============================================================================
//
// SimInteractor provides a cursor that the player moves around the lot
// to select which Sim to control. Used when switching between Sims
// or in certain gameplay modes.
//
// Features:
//   - Floating cursor with movement along camera plane
//   - Gravity well: cursor snaps toward nearby Sims
//   - Beam visual: growing beam effect when near a Sim
//   - FadeSquare: visual indicator on the ground under cursor
//   - Plumb bob management: transfers plumb bob between Sims
//   - Cut-to-sim: camera cut when selecting a distant Sim
//
// Layout (extends Interactor, +0x60):
//   0x64-0x15F: FadeSquare array (4 entries, 28 bytes each = 112 bytes)
//               + additional cursor tracking data
//   0x160: m_globalInteractorPtr  (pointer to global state)
//   0x17C: m_cursorState          (u32 - cursor behavior state)
//   0x180: m_beamScale            (f32 - current beam visual scale)
//   0x184: m_beamTimer            (f32 - beam animation timer)
//   0x188: m_cutToSimPending      (u32 - flag: should cut to selected sim)
//   0x18C: m_cameraSnapState      (u32)
//   0x190: m_plumbBobShadowSave   (u32 - saved shadow state during transfer)
//   0x194: m_snapTarget           (u32 - target sim for gravity well)
//   0x198: m_snapStarted          (u32 - gravity well active flag)
//   0x19C: m_selectedSim          (cXPerson* - currently selected sim)
//   0x214: m_returnPlumbBob       (u32 - flag: return plumb bob to sim)
//
// Static tuning constants:
//   s_gravityWellVelocity:     0x80500698 — cursor snap speed
//   s_gravityWellTimeToAct:    0x805006A0 — delay before well activates
//   s_distanceToCutAfterSelect2: 0x805006A4 — distance threshold for camera cut
//   s_beamStartGrowTime:       0x805006AC — delay before beam starts growing
//   s_beamGrowDuration:        0x805006B0 — time for beam to reach full size
//   m_closeToSimThreshold:     0x8050069C — proximity threshold for "close to sim"
//   s_invalidPos:              0x80487E34 — sentinel position
//

namespace InteractorModule {

// ---------------------------------------------------------------------------
// SimInteractor::OnStart() — 0x8021D45C, 640 bytes
// ---------------------------------------------------------------------------
// Initializes cursor-based sim selection:
//   1. Copy input mapping tables from ROM
//   2. Store player ID
//   3. Open input session with stick+button mappings
//   4. Position cursor at current sim's location
//   5. Initialize all FadeSquares to inactive
//   6. Reset beam scale and timers
//   7. Set up camera for cursor tracking mode
// NON_MATCHING
void SimInteractor_OnStart_doc() {}

// ---------------------------------------------------------------------------
// SimInteractor::Update(float) — 0x8021D7D4, 1980 bytes
// ---------------------------------------------------------------------------
// Main update loop for cursor selection. The second-largest Update function:
//
//   1. Base::Update() — save prev position
//   2. ParseControls() — read analog stick
//   3. Move cursor along camera target vector (MoveCursorAlongCameraTargetVector)
//   4. Clamp cursor to world bounds (ClampPosToWorld)
//   5. Snap position to tile grid (SnapPositionToTile)
//   6. Gravity well processing:
//      a. Find nearest sim to cursor position
//      b. If within threshold, accelerate cursor toward sim
//      c. Update beam scale based on proximity
//   7. Update FadeSquares (visual indicators):
//      a. Fade in squares near sims
//      b. Fade out squares far from sims
//   8. Update plumb bob position
//   9. Check for sim selection (cursor overlaps sim)
//  10. Handle cut-to-sim camera transition
//
// The gravity well is a key UX feature: as the cursor approaches a Sim,
// it "pulls" the cursor toward the Sim, making selection easier with
// the analog stick.
// NON_MATCHING
void SimInteractor_Update_doc() {}

// ---------------------------------------------------------------------------
// SimInteractor::OnCommandPressed() — 0x8021E070, 1116 bytes
// ---------------------------------------------------------------------------
// Button handling for sim selection:
//   cmd 0 (kCmdAction):
//     - If cursor is near a sim, select that sim
//     - Trigger cut-to-sim camera if distance > threshold
//     - Transfer plumb bob to selected sim
//   cmd 1 (kCmdCancel):
//     - Return to previous sim / exit selection mode
//   cmd 4 (kCmdExit):
//     - Exit sim selection entirely
// NON_MATCHING
void SimInteractor_OnCommandPressed_doc() {}

// ---------------------------------------------------------------------------
// SimInteractor::GetBeamScale() — 0x8021DF90, 100 bytes
// ---------------------------------------------------------------------------
// Calculates the beam visual effect scale based on proximity and time.
// Uses s_beamStartGrowTime and s_beamGrowDuration for animation curve.
// NON_MATCHING
void SimInteractor_GetBeamScale_doc() {}

} // namespace InteractorModule


// ============================================================================
//
//     SECTION 6: WallManipulator — Build Mode Wall Placement
//     Address range: 0x8021F598 - 0x80224060
//     62 functions, total ~19KB code (largest subsystem)
//
// ============================================================================
//
// WallManipulator handles all wall-related build mode operations:
//   - Placing new wall segments (line drawing from anchor to cursor)
//   - Placing rooms (rectangular wall enclosures)
//   - Deleting wall segments
//   - Fence placement (decorative walls at half height)
//   - Previewing wall placement before confirming
//   - Cost calculation for wall lines
//   - Affected wall tracking (walls that need shader updates)
//
// ---- Wall Placement State Machine ----
//
// The state is stored as a bitfield at offset 0xC4 (m_flags):
//
//   Bit 0  (0x001): ANCHORED — first endpoint has been placed
//   Bit 1  (0x002): STICK_ACTIVE — analog stick is providing input
//   Bit 2  (0x004): BUY_MODE — wall placement (vs delete)
//   Bit 3  (0x008): SELL_MODE — wall deletion active
//   Bit 4  (0x010): ROOM_PREVIEW — showing room preview
//   Bit 5  (0x020): FINALIZE_REQUESTED — user pressed action to confirm
//   Bit 6  (0x040): EXIT_REQUESTED — user wants to exit wall mode
//   Bit 7  (0x080): VALID_SEGMENT — current wall segment is legal
//   Bit 8  (0x100): FENCE_MODE — placing fences instead of walls
//   Bit 9  (0x200): DESTRUCT_MODE — demolition mode active
//   Bit 10 (0x400): MOVED — cursor moved since last frame
//   Bit 11 (0x800): CURSOR_WAS_MOVING — cursor was moving previous frame
//   Bit 12 (0x1000): CONFIRM_ACTION — action button held for confirmation
//
// State transitions:
//   FREE state (no bits set):
//     Press Action -> Set ANCHORED + BUY_MODE, store anchor position
//     Press Swap   -> Toggle between BUY/SELL mode
//
//   ANCHORED state:
//     Move stick   -> Update wall preview line from anchor to cursor
//     Press Action -> Set FINALIZE_REQUESTED, start placement
//     Press Cancel -> Clear ANCHORED, return to FREE
//     Press Swap   -> Toggle ROOM_PREVIEW (line vs room mode)
//
//   FINALIZE flow:
//     HandleFinalizeRequest() checks:
//       ROOM_PREVIEW -> FinalizeRoom() - build all 4 walls of rectangle
//       BUY_MODE     -> FinalizePlacement() - build wall line
//       SELL_MODE    -> FinalizeWallDel() - delete wall line
//     Each calls CommittTransaction() on success
//
// Layout (extends Interactor, +0x60):
//   0x60: m_anchorPos      (EVec3 - first endpoint of wall line)
//   0x6C: m_anchorDrawPos  (EVec3 - visual position of anchor)
//   0x78: m_affectedWalls  (vector<pair<CTilePt,TileWallsSegment>> - walls to update)
//         +0x78: data ptr, +0x7C: end ptr, +0x80: capacity end ptr
//   0x84-0x8B: additional vector for wall operations
//   0x88-0x97: additional vector for affected wall segments
//   0x98-0xA7: additional vector for wall fade list
//   0xA8-0xB7: additional vector for transaction data
//   0xB8-0xBF: more tracking vectors
//   0xC0: m_field_C0       (u32)
//   0xC4: m_flags          (u32 - the state bitfield described above)
//   0xC8: m_wallShaderID   (u32 - current wall shader to apply, or -1)
//   0xCC: m_direction       (s16 - wall facing direction)
//   0xD0: m_stockRemaining (u32 - remaining wall units in inventory)
//   0xD4: m_wallTileCount  (u32 - number of wall tiles affected)
//   0xD8: m_fenceShaderRef (u32* - pointer to fence shader data)
//   0xDC: m_field_DC       (u32)
//   0xE0: m_callbackData   (CallbackData at +0xE0, ~32 bytes)
//         +0xE0: type enum (3=wall)
//         +0xF0: vtable for CallbackData
//         +0xF4-0x108: session params from OnStart
//
// Static data:
//   m_wallToolHeight:            0x805006B4 — standard wall height
//   m_affectedWallToolHeight:    0x805006B8 — height for affected walls
//   m_affectedWallToolFenceHeight: 0x805006BC — height for affected fences
//   UNLIMITED_STOCK:             0x805006C0 — sentinel for unlimited walls
//

namespace InteractorModule {

// ---------------------------------------------------------------------------
// WallManipulator::WallManipulator() — 0x8021F598, 176 bytes
// ---------------------------------------------------------------------------
// Constructor: calls Interactor base constructor, then:
//   - Sets vtable to WallManipulator vtable (0x80468790)
//   - Initializes all vectors to empty (data=0, size=0, capacity=0)
//   - Clears 8 vector triplets at offsets 0x78-0xB8
//   - Sets CallbackData vtable at +0xF0
//   - Sets m_flags to 3 (ANCHORED|STICK_ACTIVE initially - will be cleared in OnStart)
//   - Clears CallbackData fields at +0xF4, +0xF8, +0xFC
// Already decompiled in wallmanipulator.cpp

// ---------------------------------------------------------------------------
// WallManipulator::OnStart() — 0x8021F83C, 732 bytes
// ---------------------------------------------------------------------------
// Initializes wall placement mode:
//   1. Copies ButtonSemantic table (from 0x8040E0F8) to stack
//   2. Copies StickSemantic table (from 0x8040E118)
//   3. Clears m_flags to 0
//   4. Stores player ID from params
//   5. Copies session params (callback info) into CallbackData (+0xE0)
//   6. Opens input session
//   7. Reads initial wall shader and fence data from session params
//   8. Sets up stock count (UNLIMITED_STOCK or specific amount)
//   9. Initializes anchor position at current cursor location
//  10. Creates visualizer resources (wall preview models)
//
// The session params structure passed from INVTarget contains:
//   - Wall shader ID (which wall style to use)
//   - Stock count (how many walls available)
//   - Mode flags (buy/sell/fence/destruct)
//   - Callback function pointer for transaction completion
// NON_MATCHING
void WallManipulator_OnStart_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::Update(float) — 0x8022176C, 584 bytes
// ---------------------------------------------------------------------------
// Per-frame update for wall manipulation:
//
//   1. Base::Update() — save previous position
//   2. UpdateStickState() — update MOVED/CURSOR_WAS_MOVING flags
//   3. ClearWallFadeOffList() — reset per-frame wall fade tracking
//   4. If camera is available:
//      a. If stick active and in ANCHORED state:
//         - Move cursor along camera vector (MoveCursorOneTileAlongCameraTargetVector)
//         - Snap to tile grid (SnapPositionToTile with IMSnapType=2)
//         - Copy snapped pos to anchor draw pos
//         - If stick centered, use default step
//      b. Else: use camera-relative movement (MoveCursorAlongCameraTargetVector)
//      c. ClampPosToWorld — keep cursor in lot bounds
//      d. SnapPositionToTile
//   5. ValidateWallSegment() — check if current wall line is legal
//   6. HandleSwapRequest() — if swap button pressed, toggle mode
//   7. HandleExitRequest() — if exit pressed, cleanup and leave
//   8. HandleFinalizeRequest() — if action pressed, try to place/delete walls
//   9. If finalization succeeded, update wall fade list and trigger camera
// NON_MATCHING
void WallManipulator_Update_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::OnCommandPressed() — 0x802219B4, 208 bytes
// ---------------------------------------------------------------------------
// Button press handling for wall mode. Decoded from disassembly:
//
//   cmd 0 (kCmdAction):
//     if (m_flags & (ROOM_PREVIEW | ANCHORED)):
//       m_flags |= FINALIZE_REQUESTED  // already anchored, confirm placement
//     else:
//       m_flags |= (ANCHORED | STICK_ACTIVE)  // set anchor point
//       Allocate sound effect handle if needed
//       Play placement sound (GUID 0x374BDCEA)
//
//   cmd 1 (kCmdCancel):
//     if (m_flags & DESTRUCT_MODE):
//       Clear ANCHORED, set CONFIRM_ACTION
//     // Cancel current placement
//
//   cmd 2 (kCmdSwapTool):
//     if (!(m_flags & ANCHORED)):
//       m_flags |= ROOM_PREVIEW  // toggle to room mode
//     // Only works when not yet anchored
//
//   cmd 4 (kCmdExit):
//     m_flags |= EXIT_REQUESTED
void WallManipulator_OnCommandPressed(
    InteractorModule::WallManipulator* this_ptr,
    InteractorModule::InteractorInputManager::InteractorCommand cmd,
    float value)
{
    (void)value;
    u32 flags = *(u32*)((u8*)this_ptr + 0xC4);

    switch (cmd) {
    case 0: // kCmdAction
        if (flags & 0x11) { // ROOM_PREVIEW(0x10) or ANCHORED(0x01)
            flags |= 0x20;  // FINALIZE_REQUESTED
        } else {
            flags |= 0x03;  // ANCHORED | STICK_ACTIVE
            // Lazy-allocate sound handle, play wall-place sound 0x374BDCEA
        }
        break;

    case 1: // kCmdCancel
        if (flags & 0x200) { // DESTRUCT_MODE
            flags &= ~0x01; // clear ANCHORED
            flags |= 0x1000; // CONFIRM_ACTION
        }
        break;

    case 2: // kCmdSwapTool
        if (!((flags ^ 0x01) & 0x01)) { // if ANCHORED is set
            flags |= 0x10;  // ROOM_PREVIEW
        }
        break;

    case 4: // kCmdExit
        flags |= 0x40;  // EXIT_REQUESTED
        break;
    }

    *(u32*)((u8*)this_ptr + 0xC4) = flags;
}

// ---------------------------------------------------------------------------
// WallManipulator::UpdateStickState() — 0x802216B8, 84 bytes
// ---------------------------------------------------------------------------
// Updates the MOVED (bit 10) and CURSOR_WAS_MOVING (bit 11) flags
// based on whether the analog stick has input.
//
// If stick has input (either axis != 0.0):
//   If CURSOR_WAS_MOVING already set: clear both bits (debounce)
//   Else: set both MOVED and CURSOR_WAS_MOVING
// If stick centered:
//   Clear both bits
void WallManipulator_UpdateStickState(InteractorModule::WallManipulator* this_ptr) {
    f32 stickX = *(f32*)((u8*)this_ptr + 0x34);
    f32 stickY = *(f32*)((u8*)this_ptr + 0x38);
    u32 flags = *(u32*)((u8*)this_ptr + 0xC4);

    if (stickX != 0.0f || stickY != 0.0f) {
        if (flags & 0x400) { // MOVED already set
            flags &= ~0x0C00; // clear MOVED and CURSOR_WAS_MOVING
        } else {
            flags |= 0x0C00;  // set both
        }
    } else {
        flags &= ~0x0C00; // clear both
    }
    *(u32*)((u8*)this_ptr + 0xC4) = flags;
}

// ---------------------------------------------------------------------------
// WallManipulator::HandleFinalizeRequest() — 0x80221028, 692 bytes
// ---------------------------------------------------------------------------
// Called when the player presses Action on an anchored wall line.
// Decides which finalization path to take based on current flags:
//
//   1. Count occupied walls in the world (pre-placement count)
//   2. If VALID_SEGMENT (bit 7):
//      a. If ROOM_PREVIEW: call FinalizeRoom()
//      b. Else if BUY_MODE: call FinalizePlacement()
//      c. Else if SELL_MODE: call FinalizeWallDel()
//   3. Clear FINALIZE_REQUESTED flag
//   4. If placement succeeded:
//      a. Count walls again (post-placement)
//      b. If count changed, send build item count change event
//      c. Build and send CommittTransaction callback data
//      d. Update anchor position for next wall segment
//      e. Clear ANCHORED state to allow new placement
// NON_MATCHING
void WallManipulator_HandleFinalizeRequest_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::CommittTransaction() — 0x8021FBA4, 1820 bytes
// ---------------------------------------------------------------------------
// The largest function in WallManipulator. Commits a wall operation
// (place or delete) and notifies the UI callback.
//
// Flow:
//   1. Create CallbackData with transaction details
//   2. Calculate wall cost based on shader ID and stock
//   3. Iterate through affected wall segments:
//      a. For each segment in the affected walls vector
//      b. Check if it's a new wall or existing
//      c. Calculate individual segment cost
//   4. Update stock count (decrement for buy, increment for sell)
//   5. Populate CallbackData with:
//      - Total cost
//      - Number of segments affected
//      - Shader IDs used
//      - Pattern sell count data (for refunds on existing wallpaper)
//   6. Call NotifyClient(state, callbackData, params) to inform UI
//   7. The callback (from INVTarget or PCTTarget) then:
//      - Updates the player's simoleons
//      - Updates inventory stock
//      - Refreshes the UI display
// NON_MATCHING
void WallManipulator_CommittTransaction_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::FinalizePlacement() — 0x802202C0, 688 bytes
// ---------------------------------------------------------------------------
// Places walls along the line from anchor to cursor.
//
//   1. Convert anchor and cursor positions to tile coordinates
//      via ConvertVertsToTiles()
//   2. Call SubmitLine() to calculate all wall tiles along the line
//   3. For each tile in the line:
//      a. Call HandleAddLine() to add the wall segment
//      b. HandleAddLine checks CanChangeTileAdd() for legality
//      c. If legal, calls AddWallAtTile() to modify the tile data
//   4. Return success/failure
// NON_MATCHING
void WallManipulator_FinalizePlacement_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::FinalizeRoom() — 0x80220AFC, 1324 bytes
// ---------------------------------------------------------------------------
// Places a rectangular room (4 wall lines forming a box).
//
//   1. Get the 4 corners from anchor and cursor positions
//   2. For each of the 4 edges:
//      a. Call SubmitLine() to get wall tiles
//      b. HandleAddLine() for each tile
//   3. Count total walls placed
//   4. If all 4 sides succeeded, commit
//   5. Else, rollback (delete any partially placed walls)
// NON_MATCHING
void WallManipulator_FinalizeRoom_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::FinalizeWallDel() — 0x80220570, 976 bytes
// ---------------------------------------------------------------------------
// Deletes walls along the line from anchor to cursor.
//
//   1. Convert positions to tiles
//   2. SubmitLine() to get affected tiles
//   3. For each tile: HandleDeleteLine()
//      HandleDeleteLine checks CanChangeTileDelete() — ensures wall exists
//      and can be legally removed (not load-bearing for rooms)
//   4. On success, update world geometry
// NON_MATCHING
void WallManipulator_FinalizeWallDel_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::ValidateWallSegment() — 0x802213C0, 760 bytes
// ---------------------------------------------------------------------------
// Checks if the current anchor-to-cursor wall line is legal.
// Sets or clears the VALID_SEGMENT flag (bit 7).
//
// Validation rules:
//   - Wall must not overlap existing walls (DoesNotConflictWithExistingArchitecture)
//   - Wall tile must be a legal position (LegalWallTile)
//   - Must have sufficient stock
//   - Must not cross lot boundaries
//   - In fence mode, additional height restrictions apply
//
// Also calls CheckForAffectedWalls() to find walls that would need
// visual updates if this wall is placed.
// NON_MATCHING
void WallManipulator_ValidateWallSegment_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::CheckForAffectedWalls() — 0x802237A0, 1840 bytes
// ---------------------------------------------------------------------------
// Finds all existing wall segments that would be visually affected by
// placing a new wall. Used to update wall shaders for proper rendering
// of wall intersections and corners.
// NON_MATCHING
void WallManipulator_CheckForAffectedWalls_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::GetWallLineCost() — 0x80221BD4, 532 bytes
// ---------------------------------------------------------------------------
// Calculates the simoleon cost of a wall line from start to end.
// Takes into account:
//   - Number of wall segments
//   - Wall style price per segment
//   - Whether walls are being placed or deleted (refund amount)
//   - Fence vs full wall pricing
// NON_MATCHING
void WallManipulator_GetWallLineCost_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::SubmitLine() — 0x80221DE8, 400 bytes
// ---------------------------------------------------------------------------
// Converts two world positions into a list of tile positions that the
// wall line passes through. Uses Bresenham-style line rasterization
// on the tile grid.
//
// Output: populates the affected walls vector with tile positions.
// NON_MATCHING
void WallManipulator_SubmitLine_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::AddWallAtTile() — 0x80223354, 384 bytes
// ---------------------------------------------------------------------------
// Adds a wall segment to a specific tile. Modifies the tile's TileWalls
// data to include the new wall segment with the specified style.
// NON_MATCHING
void WallManipulator_AddWallAtTile_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::CanChangeTileAdd() — 0x8022237C, 332 bytes
// ---------------------------------------------------------------------------
// Checks if a wall can be added at a tile position:
//   - Tile must be within lot bounds
//   - Tile must not already have max walls
//   - Must not conflict with existing architecture
//   - Stock check (enough walls in inventory)
// NON_MATCHING
void WallManipulator_CanChangeTileAdd_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::CanChangeTileDelete() — 0x802224C8, 1308 bytes
// ---------------------------------------------------------------------------
// Checks if a wall can be deleted at a tile:
//   - Wall must actually exist at that tile
//   - Wall must not be the only wall supporting an upper floor
//   - In some modes, certain structural walls cannot be removed
// NON_MATCHING
void WallManipulator_CanChangeTileDelete_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::LegalWallTile() — 0x80223088, 716 bytes
// ---------------------------------------------------------------------------
// Comprehensive legality check for wall placement at a tile.
// Checks terrain constraints, existing structures, and lot boundaries.
// NON_MATCHING
void WallManipulator_LegalWallTile_doc() {}

// ---------------------------------------------------------------------------
// WallManipulator::DoesNotConflictWithExistingArchitecture()
// 0x80221F78, 1028 bytes
// ---------------------------------------------------------------------------
// Ensures new wall doesn't conflict with doors, windows, or stairwells.
// NON_MATCHING
void WallManipulator_DoesNotConflictWithExistingArchitecture_doc() {}

} // namespace InteractorModule


// ============================================================================
//
//     SECTION 7: WallPainter — Build Mode Wallpaper Application
//     Address range: 0x80224064 - 0x80226ACC
//     50 functions, total ~10KB code
//
// ============================================================================
//
// WallPainter applies wallpaper patterns to existing walls. Similar state
// machine to WallManipulator but operates on wall surfaces rather than
// wall geometry.
//
// ---- WallPainter State Machine ----
//
// State stored at offset 0x88 (m_flags):
//   Bit 0  (0x001): ANCHORED — anchor point placed
//   Bit 1  (0x002): STICK_ACTIVE
//   Bit 2  (0x004): BUY_MODE — applying wallpaper
//   Bit 3  (0x008): SELL_MODE — removing wallpaper
//   Bit 4  (0x010): ROOM_PREVIEW — painting entire room
//   Bit 5  (0x020): FINALIZE_REQUESTED
//   Bit 6  (0x040): EXIT_REQUESTED
//   Bit 7  (0x080): VALID_SEGMENT — legal wallpaper target
//   Bit 12 (0x1000): HOLD_POS_SAVED — hold position has been saved
//
// Layout (extends Interactor, +0x60):
//   0x60: m_anchorPos         (EVec3)
//   0x6C: m_anchorDrawPos     (EVec3)
//   0x78: m_holdPos           (EVec3 - saved cursor pos for room mode)
//   0x84: m_cursorRotAdj      (f32 - cursor rotation for wall alignment)
//   0x88: m_flags             (u32 - state bitfield)
//   0x90: m_shaderRef         (pointer to wallpaper shader data)
//   0x9C: m_wallSegmentData   (transaction tracking data)
//
// Static data:
//   m_paperToolHeight: 0x805006C4 — visual height of wallpaper tool
//   m_wallHeight:      0x805006C8 — standard wall height
//   UNLIMITED_STOCK:   0x805006CC — sentinel
//

namespace InteractorModule {

// ---------------------------------------------------------------------------
// WallPainter::OnStart() — 0x80224200, 652 bytes
// ---------------------------------------------------------------------------
// Initializes wallpaper mode. Similar to WallManipulator::OnStart:
//   1. Copy button/stick semantic tables from ROM
//   2. Store player ID and session params
//   3. Open input session
//   4. Read wallpaper shader from params
//   5. Initialize anchor and hold positions
//   6. Create visualizer resources (wallpaper preview)
// NON_MATCHING
void WallPainter_OnStart_doc() {}

// ---------------------------------------------------------------------------
// WallPainter::Update(float) — 0x80225098, 948 bytes
// ---------------------------------------------------------------------------
// Per-frame update, follows same pattern as WallManipulator::Update:
//   1. Base::Update()
//   2. UpdateStickState()
//   3. Move cursor, snap to tile
//   4. AdjustCursorPosition() — aligns cursor to nearest wall face
//   5. ValidateWallSegment() — check if target wall exists and is paintable
//   6. Handle swap/exit/finalize requests
//   7. If finalizing:
//      - FinalizePaperForLine() for line mode
//      - FinalizePaperForRoom() for room mode
//      - FinalizeSellPaperForLine() for removing wallpaper
// NON_MATCHING
void WallPainter_Update_doc() {}

// ---------------------------------------------------------------------------
// WallPainter::ValidateWallSegment() — 0x80224BB8, 1164 bytes
// ---------------------------------------------------------------------------
// Checks if the cursor is pointing at a valid wall surface for painting.
// Uses GetVisibleSideOfWall() to determine which side of the wall is
// facing the camera, so wallpaper is applied to the correct face.
// NON_MATCHING
void WallPainter_ValidateWallSegment_doc() {}

// ---------------------------------------------------------------------------
// WallPainter::CommittTransaction() — 0x802244EC, 844 bytes
// ---------------------------------------------------------------------------
// Commits a wallpaper application/removal:
//   1. Calculate cost based on number of wall surfaces painted
//   2. Track which walls were painted for undo/sell-back
//   3. Build callback data with pattern info and cost
//   4. Call NotifyClient to inform UI (INVTarget::WallPainterCallback)
// NON_MATCHING
void WallPainter_CommittTransaction_doc() {}

// ---------------------------------------------------------------------------
// WallPainter::CountWallsInRoomSelection() — 0x802256FC, 1652 bytes
// ---------------------------------------------------------------------------
// When painting an entire room, counts all wall surfaces in the room
// to calculate total cost. Iterates through the room's wall list and
// counts paintable surfaces on each wall segment.
// NON_MATCHING
void WallPainter_CountWallsInRoomSelection_doc() {}

// ---------------------------------------------------------------------------
// WallPainter::FinalizePaperForRoom() — 0x80225D70, 1352 bytes
// ---------------------------------------------------------------------------
// Applies wallpaper to all walls in a room:
//   1. Get room ID from cursor position
//   2. Iterate all wall segments in the room
//   3. For each wall: apply wallpaper shader to the visible side
//   4. Track total cost and changed walls
//   5. CommittTransaction
// NON_MATCHING
void WallPainter_FinalizePaperForRoom_doc() {}

// ---------------------------------------------------------------------------
// WallPainter::SubmitPaperLine() — 0x80226458, 984 bytes
// ---------------------------------------------------------------------------
// Applies wallpaper along a line of walls (similar to WallManipulator's
// SubmitLine but operates on wall surfaces).
// NON_MATCHING
void WallPainter_SubmitPaperLine_doc() {}

// ---------------------------------------------------------------------------
// WallPainter::AdjustCursorPosition() — 0x80224AAC, 268 bytes
// ---------------------------------------------------------------------------
// Snaps the cursor to the nearest wall face. Uses camera-relative
// wall visibility to determine which side of a wall the player can see,
// then positions the cursor on that face.
// NON_MATCHING
void WallPainter_AdjustCursorPosition_doc() {}

} // namespace InteractorModule


// ============================================================================
//
//     SECTION 8: FloorPainter — Build Mode Floor Tile Painting
//     Address range: 0x80206224 - 0x802091BC
//     47 functions, total ~11KB code
//
// ============================================================================
//
// FloorPainter handles floor tile placement and removal in build mode.
// Unlike WallManipulator which works on lines, FloorPainter works with
// rectangular regions (drag a rectangle to fill with floor tiles)
// or individual tiles.
//
// ---- FloorPainter State Machine ----
//
// State stored as a byte at offset 0x60 (m_state):
//   Bit 0 (0x01): ANCHOR_STATE — anchor corner has been placed
//   Bit 1 (0x02): FILL_STATE — in room-fill mode
//   Bit 2 (0x04): BUILD_STATE — actively building floor rectangle
//   Bit 3 (0x08): REMOVE_STATE — actively removing floor
//   Bit 4 (0x10): CONFIRMED_STATE — placement confirmed
//   Bit 5 (0x20): INVALID_STATE — current selection is invalid
//   Bit 6 (0x40): CURSOR_WAS_MOVING — cursor moved last frame
//   Bit 7 (0x80): STICK_ACTIVE — analog stick has input
//
// Layout (extends Interactor, +0x60):
//   0x60: m_state           (u8 - state byte, bit flags above)
//   0x64: m_anchorPos       (EVec3 - first corner of rectangle)
//   0x70: m_anchorTile      (CTilePt - anchor in tile coords)
//   0x78-0x93: m_rectData    (rectangle selection data)
//   0x94: m_selectedFloor   (pointer region - selected floor pattern data)
//   0x98: m_stockCount      (u32 - remaining tiles)
//   0x9C: m_floorShader     (u32 - current floor shader ID)
//   0xA0: m_sellCountVec    (vector - tracks sell counts per pattern)
//   0xA4: m_isPlaceMode     (u32 - 0=remove, nonzero=place)
//   0xA8: m_cursorObject    (cXObject* or related - cursor visual)
//   0xB0-0xB8: additional data vectors
//
// Static data:
//   UNLIMITED_STOCK: 0x80500694 — sentinel for unlimited tiles
//

namespace InteractorModule {

// ---------------------------------------------------------------------------
// FloorPainter::FloorPainter() — 0x80206224, 148 bytes
// ---------------------------------------------------------------------------
// Constructor:
//   1. Call Interactor base constructor
//   2. Set vtable to FloorPainter vtable (0x80468170)
//   3. Set CallbackData vtable at +0x90 offset
//   4. Initialize m_state (0x80) = 5 (ANCHOR_STATE | BUILD_STATE?)
//      Actually sets field at 0x80 to 5 (type enum = FloorPainter)
//   5. Clear cursor object pointer, vectors
//   6. Initialize stock from global floor data
// Already shown in wallmanipulator.cpp

// ---------------------------------------------------------------------------
// FloorPainter::OnStart() — 0x80206424, 608 bytes
// ---------------------------------------------------------------------------
// Initializes floor painting mode:
//   1. Copy input mapping tables from ROM
//   2. Store player ID, copy session params
//   3. If m_sellCountVec is null, allocate it at +0xA8
//   4. Open input session with button/stick mappings
//   5. Read floor shader from session params
//   6. Initialize anchor position at cursor
//   7. Set initial mode (place or remove from params)
//   8. Create visualizer resources (floor preview overlay)
//
// Two ROM-resident tables are copied:
//   0x8040CD0C: ButtonSemantic table for floor mode
//   0x8040CD2C: StickSemantic table for floor mode
// NON_MATCHING
void FloorPainter_OnStart_doc() {}

// ---------------------------------------------------------------------------
// FloorPainter::Update(float) — 0x80206734, 1576 bytes
// ---------------------------------------------------------------------------
// The largest FloorPainter function. Per-frame update:
//
//   1. Base::Update()
//   2. UpdateStickState() — update movement flags in m_state
//   3. If camera available:
//      a. Move cursor (tile-step if anchored, smooth if free)
//      b. ClampPosToWorld()
//      c. SnapPositionToTile()
//   4. Clear per-frame sell count tracking vector
//   5. If cursor has moved (Moved() returns true):
//      a. Get world tile data pointer
//      b. Get floor data for cursor position
//      c. In place mode: check IsValidFloorPlacement()
//      d. In remove mode: check if floor exists to remove
//   6. Build rectangle from anchor to cursor (GetSelectedRectPoints)
//   7. CurrentSelectionIsValid() — validate entire rectangle
//   8. If CONFIRMED_STATE:
//      a. PaintFloor() or RemoveFloor() based on mode
//      b. Or PaintRoom() / RemoveRoom() for fill mode
//      c. CommittTransaction equivalent via NotifyClient
//   9. Update visual preview
// NON_MATCHING
void FloorPainter_Update_doc() {}

// ---------------------------------------------------------------------------
// FloorPainter::OnCommandPressed() — 0x80207418, 1176 bytes
// ---------------------------------------------------------------------------
// Button handling for floor painting:
//
//   cmd 0 (kCmdAction):
//     In remove mode:
//       HandleActionCmdInRemoveMode() — immediately remove floor tile
//     In place mode:
//       HandleActionCmdInPlaceMode() — place anchor or confirm rectangle
//
//   cmd 1 (kCmdCancel):
//     In remove mode with no existing selection:
//       Exit (cannot cancel remove of something not selected)
//     In place mode:
//       If stock vector has data, try to add current tile to selection
//       Uses vector push_back pattern (with capacity management)
//
//   cmd 2 (kCmdSwapTool):
//     In place mode: SwapTools() — toggle between place/remove
//     Also handles room-fill mode toggle
//
//   cmd 4 (kCmdExit):
//     Request exit from floor mode
//
// The vector operations in cmd 1 show EA's std::vector implementation:
//   if (end < capacity): simple append
//   else: reallocate (>128 bytes: operator_new, <=128: alloca_small)
//   copy existing elements, add new element
// NON_MATCHING
void FloorPainter_OnCommandPressed_doc() {}

// ---------------------------------------------------------------------------
// FloorPainter::HandleActionCmdInPlaceMode() — 0x80207278, 416 bytes
// ---------------------------------------------------------------------------
// Handles the Action button in place mode:
//   - If in FREE state: set anchor, transition to ANCHOR_STATE
//   - If in ANCHOR state: start building, transition to BUILD_STATE
//   - If in BUILD state: confirm rectangle, call PaintFloor
// NON_MATCHING
void FloorPainter_HandleActionCmdInPlaceMode_doc() {}

// ---------------------------------------------------------------------------
// FloorPainter::HandleActionCmdInRemoveMode() — 0x80206E5C, 544 bytes
// ---------------------------------------------------------------------------
// Handles Action in remove mode:
//   - If in FREE state: set anchor for removal rectangle
//   - If anchored: confirm removal, call RemoveFloor
// NON_MATCHING
void FloorPainter_HandleActionCmdInRemoveMode_doc() {}

// ---------------------------------------------------------------------------
// FloorPainter::PaintFloor(int*) — 0x8020812C, 632 bytes
// ---------------------------------------------------------------------------
// Paints floor tiles in a rectangular region:
//   1. Get rectangle bounds from GetSelectedRectPoints
//   2. For each tile (x,y) in the rectangle:
//      a. Call SetFloorTile(tile, pattern, room, cost)
//      b. Accumulate cost
//   3. Send success event
//   4. Update stock count
// NON_MATCHING
void FloorPainter_PaintFloor_doc() {}

// ---------------------------------------------------------------------------
// FloorPainter::PaintRoom(int*) — 0x80208654, 768 bytes
// ---------------------------------------------------------------------------
// Fills an entire room with floor tiles:
//   1. Get room from cursor position (GetRoomIdFromPoint)
//   2. Iterate all floor positions in the room
//   3. For each position: SetFloorTile
//   4. Handle diagonal room edges (CheckDiagForRoomContainment)
// NON_MATCHING
void FloorPainter_PaintRoom_doc() {}

// ---------------------------------------------------------------------------
// FloorPainter::RemoveFloor(int*) — 0x802083A4, 688 bytes
// ---------------------------------------------------------------------------
// Removes floor tiles in a rectangular region:
//   1. Get rectangle bounds
//   2. For each tile: RemoveFloorTile
//   3. Track refund cost
// NON_MATCHING
void FloorPainter_RemoveFloor_doc() {}

// ---------------------------------------------------------------------------
// FloorPainter::RemoveRoom(int*) — 0x80208954, 800 bytes
// ---------------------------------------------------------------------------
// Removes all floor tiles in a room. Same room-iteration as PaintRoom.
// NON_MATCHING
void FloorPainter_RemoveRoom_doc() {}

// ---------------------------------------------------------------------------
// FloorPainter::SetFloorTile(CTilePt&, FloorPattern, Room*, int*)
// 0x80207C94, 488 bytes
// ---------------------------------------------------------------------------
// Sets a single floor tile:
//   1. Check if tile is valid (within room, not already this pattern)
//   2. Get the EIFloor interface for the tile
//   3. Set the floor pattern and shader
//   4. Update lighting grid (RecomputeLightingGrid)
//   5. Return cost delta
// NON_MATCHING
void FloorPainter_SetFloorTile_doc() {}

// ---------------------------------------------------------------------------
// FloorPainter::IsValidFloorPlacement() — 0x80207A10, 208 bytes
// ---------------------------------------------------------------------------
// Checks if a floor tile can be placed at a position:
//   - Position must be within lot bounds
//   - Tile must be a valid floor tile position
//   - Must not already have the same pattern (no double-painting)
// NON_MATCHING
void FloorPainter_IsValidFloorPlacement_doc() {}

// ---------------------------------------------------------------------------
// FloorPainter::CurrentSelectionIsValid() — 0x80208ECC, 624 bytes
// ---------------------------------------------------------------------------
// Validates the entire rectangle selection:
//   - All tiles in the rectangle must be legal floor positions
//   - Total cost must not exceed player's simoleons
//   - Stock must be sufficient for all tiles
// Sets or clears INVALID_STATE flag (bit 5).
// NON_MATCHING
void FloorPainter_CurrentSelectionIsValid_doc() {}

// ---------------------------------------------------------------------------
// FloorPainter::GetSelectedRectPoints() — 0x80208080, 172 bytes
// ---------------------------------------------------------------------------
// Calculates the rectangle defined by anchor and cursor positions.
// Returns min/max tile coordinates (x1, y1, x2, y2) sorted so x1<=x2, y1<=y2.
// NON_MATCHING
void FloorPainter_GetSelectedRectPoints_doc() {}

// ---------------------------------------------------------------------------
// FloorPainter::UpdateStockChanges(int*, int) — 0x8020707C, 508 bytes
// ---------------------------------------------------------------------------
// Updates stock tracking after floor operations. Handles the sell-back
// price calculation when removing previously placed floor tiles.
// Uses IncrementSellCountForPattern to track refund amounts.
// NON_MATCHING
void FloorPainter_UpdateStockChanges_doc() {}

// ---------------------------------------------------------------------------
// FloorPainter::SwapTools() — 0x80208E20, 172 bytes
// ---------------------------------------------------------------------------
// Toggles between place and remove mode:
//   1. Flip m_isPlaceMode
//   2. Reset state to FREE
//   3. Clear any active selection
//   4. Swap cursor visual (place cursor vs remove cursor)
// NON_MATCHING
void FloorPainter_SwapTools_doc() {}

} // namespace InteractorModule


// ============================================================================
//
//     SECTION 9: ObjectManipulator / GrabManipulator / PlaceManipulator
//     Address range: 0x80218F3C - 0x8021CE00
//     45 functions combined, total ~10KB code
//
// ============================================================================
//
// ObjectManipulator is the base for buy mode object manipulation.
// GrabManipulator picks up existing objects; PlaceManipulator puts down new ones.
//
// ---- Object Placement Flow ----
//
//   GrabManipulator:
//     1. Player enters buy mode
//     2. Cursor highlights nearby objects (UpdateObjectHighlights)
//     3. Player presses Action on an object -> TryGrabbingWorldObject()
//        a. Raycast to find object under cursor
//        b. If found, call PlacementObject::GrabExistingObjectInstanceFromId()
//        c. Object "picked up" — rendered at cursor position
//     4. Player moves cursor, object follows
//     5. Player presses Action -> PlacementObject::Drop()
//        a. Check IsLegalToPlaceAtLocation()
//        b. If legal, call FinalUserPlaceObject()
//        c. Object placed at new position
//     6. Player presses Cancel -> CancelCurrentGrab()
//        a. Return object to original position
//     7. Player presses Delete -> DestroyObjectInHand()
//        a. Sell object for simoleons
//
//   PlaceManipulator:
//     1. INVTarget selects an object from catalog
//     2. PlaceManipulator::StartPlacement() called with object GUID
//     3. PlacementObject::CreateNewPlacementObjectFromGuid() creates instance
//     4. Object follows cursor (same as grab mode)
//     5. Action to place, Cancel to abort
//
// ---- PlacementObject — The Object Being Placed ----
//
// PlacementObject (0x2C bytes) wraps a cXObject being manipulated:
//   0x00: m_object      (cXObject* - the game object)
//   0x04: m_originalPos  (EVec3 - where object was before grab, for cancel)
//   0x08: m_field_08     (u32)
//   0x0C: m_field_0C     (u32)
//   0x10: m_direction     (s16 - object rotation, 0-3)
//   0x12: m_field_12     (u8 - flags)
//   0x14: m_gridObject   (cXMTObjectImpl* - multi-tile footprint)
//   0x18: m_field_18     (u32)
//   0x1C: m_field_1C     (u32)
//   0x20: m_field_20     (u32)
//   0x24: m_field_24     (u32)
//   0x28: m_field_28     (u32)
//
// PlacementObject::Rotate() uses a 1628-byte function (0x8021C3C8) that:
//   1. Gets the object's cXObjectImpl
//   2. Reads tile footprint data
//   3. Rotates the footprint 90 degrees
//   4. Updates m_direction
//   5. Checks legality at current position with new rotation
//   6. Updates object shader (green=valid, red=invalid via ShadeModelToShowValidState)
//

namespace InteractorModule {

// ---------------------------------------------------------------------------
// ObjectManipulator::OnStart() — 0x80219074, 380 bytes
// ---------------------------------------------------------------------------
// Initializes object manipulation:
//   1. Copy input mapping tables
//   2. Open input session
//   3. Initialize PlacementObject at +0x64
//   4. Set cursor model enabled based on global flag
// NON_MATCHING
void ObjectManipulator_OnStart_doc() {}

// ---------------------------------------------------------------------------
// ObjectManipulator::Update(float) — 0x802194E0, 1940 bytes
// ---------------------------------------------------------------------------
// Per-frame object manipulation update:
//
//   1. Base::Update()
//   2. If camera available:
//      Move cursor via MoveCursorAlongCameraTargetVector
//      ClampPosToWorld, SnapPositionToTile
//   3. If PlacementObject has an object:
//      a. Get object's cXObjectImpl
//      b. Read object footprint dimensions
//      c. Calculate tile position from cursor
//      d. Check IsLegalToPlaceAtLocation()
//      e. Update object shader (green/red)
//      f. Update object position to match cursor
//      g. Handle object stacking (countertops, shelves)
//   4. If no object:
//      UpdateObjectHighlights to find nearby objects for highlighting
// NON_MATCHING
void ObjectManipulator_Update_doc() {}

// ---------------------------------------------------------------------------
// GrabManipulator::OnStart() — 0x8021A07C, 268 bytes
// ---------------------------------------------------------------------------
// Initializes grab mode:
//   1. Call ObjectManipulator::OnStart (base)
//   2. Save session params (for callback)
//   3. If m_stockRemaining > 0, try to start with an object
//      (for placing additional copies of a catalog item)
//   4. If object ID passed in params (from previous grab), re-grab it
// NON_MATCHING
void GrabManipulator_OnStart_doc() {}

// ---------------------------------------------------------------------------
// GrabManipulator::TryGrabbingWorldObject() — 0x8021A348, 240 bytes
// ---------------------------------------------------------------------------
// Attempts to grab the object under the cursor:
//
//   1. Initialize a vector<short> for intersecting object IDs
//   2. Call GetCursorIntersectionObjects() — raycasts from cursor position
//      into the world, collecting all objects within selection radius
//   3. If objects found:
//      a. Take the first (closest) object
//      b. Get its cXObject via GetObjectFromInt16()
//      c. Get its short ID via vtable call (offset 0x328 in vtable)
//      d. Call TryGrabbingWorldObjectFromId(objectId)
//   4. If no objects:
//      a. Try virtual function for "grab nothing" behavior
//      b. Check if grab sound should play
//   5. Clean up the intersection vector
// NON_MATCHING
void GrabManipulator_TryGrabbingWorldObject_doc() {}

// ---------------------------------------------------------------------------
// GrabManipulator::TryGrabbingWorldObjectFromId(short) — 0x8021A438, 212 bytes
// ---------------------------------------------------------------------------
// Grabs a specific object by ID:
//   1. Get PlacementObject (this+0x64)
//   2. Call PlacementObject::GrabExistingObjectInstanceFromId(id)
//   3. This calls PlacementObject::Pickup() which:
//      a. Saves object's current position (for cancel undo)
//      b. Removes object from world tile grid
//      c. Sets object to "held" state
//      d. Updates object shader to placement mode (transparent green)
// NON_MATCHING
void GrabManipulator_TryGrabbingWorldObjectFromId_doc() {}

// ---------------------------------------------------------------------------
// GrabManipulator::DropCurrentObject() — 0x8021A564, 188 bytes
// ---------------------------------------------------------------------------
// Places the held object at the cursor position:
//   1. Call PlacementObject::Drop()
//      a. Check IsLegalToPlaceAtLocation()
//      b. If legal: FinalUserPlaceObject()
//      c. Reset object shader to normal
//   2. If drop succeeded:
//      - Build callback data with placement info
//      - NotifyClient (INVTarget::GrabModeCallback)
//   3. If illegal:
//      - SetIsCursorModelEnabled(true) to show invalid state
// NON_MATCHING
void GrabManipulator_DropCurrentObject_doc() {}

// ---------------------------------------------------------------------------
// GrabManipulator::DestroyObjectInHand() — 0x8021A50C, 88 bytes
// ---------------------------------------------------------------------------
// Sells/destroys the held object:
//   1. Check CanObjectBeDestroyed()
//   2. If destroyable:
//      a. Call DestroyObject() to remove from world
//      b. Credit player with sell price
//   3. Reset PlacementObject state
// NON_MATCHING
void GrabManipulator_DestroyObjectInHand_doc() {}

// ---------------------------------------------------------------------------
// PlaceManipulator::StartPlacement() — 0x8021A1FC, 332 bytes
// ---------------------------------------------------------------------------
// Starts placement of a new catalog object:
//   1. Read object GUID from PlaceManipulatorParams
//   2. Call PlacementObject::CreateNewPlacementObjectFromGuid(guid, ...)
//   3. This calls CreateObjectFromGUID() to instantiate the game object
//   4. Set initial direction from params
//   5. Position at cursor location
// NON_MATCHING
void PlaceManipulator_StartPlacement_doc() {}

// ---------------------------------------------------------------------------
// PlaceManipulator::TryPlacingCurrentObject() — 0x8021A8D8, 276 bytes
// ---------------------------------------------------------------------------
// Attempts to place the catalog object at current position:
//
//   1. If object exists (PlacementObject+0x00 != NULL):
//      a. Check validity via vtable call (offset 0x260: CanPlace?)
//      b. If valid, save pre-placement state
//   2. Call PlacementObject::Drop()
//   3. If drop succeeded:
//      a. Get cXObject via vtable (offset 0x468)
//      b. Build callback with object data
//      c. Set stock remaining on callback
//      d. NotifyClient(state, callback, params)
//      e. Start new placement (call StartPlacement for next copy)
//   4. If drop failed:
//      a. SetIsCursorModelEnabled(true)
//
// Callback data structure (at sp+0x08):
//   +0x00: sell count (from Drop)
//   +0x04: stock remaining
//   +0x08: vtable for CallbackData
//   +0x0C: zero
void PlaceManipulator_TryPlacingCurrentObject_decomp(
    InteractorModule::PlaceManipulator* this_ptr)
{
    // r30 = this
    // r31 = PlacementObject* = this->m_placementObject (at +0x64, offset 100)
    void* placementObj_ptr = *(void**)((u8*)this_ptr + 100);

    // Check if object exists
    if (placementObj_ptr) {
        // vtable call: object->CanPlace(1) via vtable offset 0x260/0x264
        // r28 = result
    }

    // PlacementObject::Drop() at +0x64
    // r3 = this + 0x64
    // Result in r29 (1=success, 0=fail)

    if (/* r29 == 1 */(0)) {
        // Object placed successfully
        if (placementObj_ptr) {
            // vtable call: FinalizePlace(1) via vtable offset 0x468/0x46C
        }
        // Build callback: set sell count, stock remaining
        // NotifyClient(state, callbackData, sessionParams at +0xAC)

        // If callback says to continue (stock > 0):
        //   Call StartPlacement to create next copy
    } else {
        // SetIsCursorModelEnabled(true) — show invalid placement indicator
    }
}

// ---------------------------------------------------------------------------
// PlacementObject::Rotate() — 0x8021C3C8, 1628 bytes
// ---------------------------------------------------------------------------
// Rotates the held object by 90 degrees:
//   1. Get current rotation from m_direction
//   2. Calculate new direction (CW or CCW based on RotateDirection param)
//   3. Get object's cXObjectImpl
//   4. Read multi-tile footprint (if ISimsMultiTileObjectModel)
//   5. Rotate the footprint grid
//   6. Call SetDirection(newDir, object) to update world state
//   7. Check legality at current position with new rotation
//   8. Update shader (ShadeModelToShowValidState)
// NON_MATCHING
void PlacementObject_Rotate_doc() {}

// ---------------------------------------------------------------------------
// PlacementObject::ResetLocation() — 0x8021CA24, 668 bytes
// ---------------------------------------------------------------------------
// Returns a grabbed object to its original position (cancel/undo):
//   1. Restore saved position from m_originalPos
//   2. Restore saved rotation from saved direction
//   3. Place object back in tile grid
//   4. Update world state
// NON_MATCHING
void PlacementObject_ResetLocation_doc() {}

} // namespace InteractorModule


// ============================================================================
//
//     SECTION 10: InteractorVisualizer — Drawing Build Mode UI
//     Address range: 0x80213D8C - 0x80218E84
//     55 functions, total ~20KB code
//
// ============================================================================
//
// InteractorVisualizer handles all rendering for the interactor system.
// It has type-specific CreateResources/Draw/PreDraw for each interactor type.
//
// Key rendering operations:
//   - Wall preview: semi-transparent wall segments shown before placement
//   - Floor preview: colored rectangle overlay showing floor area
//   - Room preview: highlighted room boundaries
//   - Object preview: translucent object at cursor with green/red tint
//   - Cursor model: 3D cursor at interactor position
//   - Plumb bob: mood indicator above selected sim
//
// Uses InteractorResourceSet to manage models, shaders, and textures
// for each interactor type.
//

namespace InteractorModule {

// ---------------------------------------------------------------------------
// InteractorVisualizer::CreateResourceSet() — 0x80217D00, 3544 bytes
// ---------------------------------------------------------------------------
// Allocates and loads all graphical resources for an interactor:
//   - 3D cursor model (loaded by GUID)
//   - Selection highlight shaders
//   - Preview shaders (wall/floor/wallpaper)
//   - Textures for UI overlays
// Uses InteractorResourceSet::AddModel/AddShader/AddTexture
// NON_MATCHING
void InteractorVisualizer_CreateResourceSet_doc() {}

// ---------------------------------------------------------------------------
// InteractorVisualizer::Draw(WallManipulator&) — 0x80215C90, 632 bytes
// ---------------------------------------------------------------------------
// Draws wall placement preview:
//   1. If valid segment and anchored:
//      a. Draw wall preview (DrawPreviewOnAffectedWalls or DrawWallRectPreview)
//      b. Draw room preview if in room mode
//   2. Draw cursor at current position (DrawResource)
//   3. Draw anchor marker at anchor position
// NON_MATCHING
void InteractorVisualizer_Draw_WallManipulator_doc() {}

// ---------------------------------------------------------------------------
// InteractorVisualizer::DrawPreviewOnAffectedWalls()
// 0x802166D0, 1472 bytes
// ---------------------------------------------------------------------------
// Renders semi-transparent wall segments showing where new walls will go.
// For each wall in the affected walls list:
//   1. Get wall start/end positions from tile coordinates
//   2. Calculate wall height from m_wallToolHeight or m_affectedWallToolFenceHeight
//   3. Draw vertical rectangle with wall shader
// NON_MATCHING
void InteractorVisualizer_DrawPreviewOnAffectedWalls_doc() {}

// ---------------------------------------------------------------------------
// InteractorVisualizer::DrawFloorRectPreview()
// 0x802147E4, 800 bytes
// ---------------------------------------------------------------------------
// Renders the floor tile selection rectangle:
//   1. Get rectangle corners from FloorPainter
//   2. Calculate world positions for each corner
//   3. Draw textured quad on the ground plane
//   4. Color based on validity (green=valid, red=invalid)
// NON_MATCHING
void InteractorVisualizer_DrawFloorRectPreview_doc() {}

// ---------------------------------------------------------------------------
// InteractorVisualizer::Draw(PlacementObject&, EVec3&)
// 0x802175EC, 1348 bytes
// ---------------------------------------------------------------------------
// Draws the object being placed:
//   1. Get object model from PlacementObject
//   2. Position at cursor location
//   3. Apply green (valid) or red (invalid) tint shader
//   4. Draw using normal object rendering pipeline
// NON_MATCHING
void InteractorVisualizer_Draw_PlacementObject_doc() {}

// ---------------------------------------------------------------------------
// InteractorVisualizer::DrawVerticalRect()
// 0x80215FDC, 1196 bytes
// ---------------------------------------------------------------------------
// Low-level function to draw a vertical rectangle (wall face).
// Used by DrawPreviewOnAffectedWalls and DrawWallpaperRectPreview.
//
// Params:
//   shader: the wall/wallpaper shader
//   start: 2D start position (on ground plane)
//   end: 2D end position
//   height: wall height
//   texGenMode: 0=stretch, 1=tile, 2=directional
//   alpha: transparency
// NON_MATCHING
void InteractorVisualizer_DrawVerticalRect_doc() {}

} // namespace InteractorModule


// ============================================================================
//
//     SECTION 11: Free Functions — Module-Level Utilities
//     Address range: 0x80210260 - 0x80213C60
//     ~40 functions
//
// ============================================================================
//
// These are namespace-level functions in InteractorModule:: that provide
// shared utility services to all interactor types.
//

namespace InteractorModule {

// ---------------------------------------------------------------------------
// InitializeInteractorModule() — 0x80210260, 516 bytes
// ---------------------------------------------------------------------------
// Top-level module initialization called during game startup.
//
//   1. Check if split-screen is enabled (global flag at 0x80475C70)
//   2. Set up InteractorManager::InteractorParams:
//      - maxPlayers = splitScreen ? 2 : 1
//      - controllerMapping = 2 (default mapping)
//   3. Call InteractorManager::GetSingleton()
//   4. Call InteractorManager::Initialize(params)
//   5. For each player:
//      a. Validate player ID
//      b. If valid and not already initialized:
//         - Allocate player-specific data (20 bytes per player)
//         - Store in InteractorManager's player array
//         - Set up InitializeInteractorModule completion flag
// NON_MATCHING
void InitializeInteractorModule_decomp() {
    // Pseudocode from disassembly at 0x80210260:
    //
    // bool splitScreen = *(u8*)0x80475E84;
    // InteractorManager::InteractorParams params;
    // params.maxPlayers = splitScreen ? 2 : 1;
    // params.controllerMapping = 2;
    //
    // InteractorManager* mgr = InteractorManager::GetSingleton();
    // mgr->Initialize(params);
    //
    // for (int player = 0; player < params.maxPlayers; player++) {
    //     if (mgr->IsValidPlayerId(player)) {
    //         if (!(mgr->m_flags & (1 << player))) {
    //             mgr->m_flags |= (1 << player);
    //             void* data = operator_new(20);
    //             // ... initialize player data
    //         }
    //     }
    // }
}

// ---------------------------------------------------------------------------
// ShutdownInteractorModule() — 0x80210464, 68 bytes
// ---------------------------------------------------------------------------
// Tears down the module. Calls InteractorManager::Shutdown().
// NON_MATCHING
void ShutdownInteractorModule_doc() {}

// ---------------------------------------------------------------------------
// MoveCursorAlongCameraTargetVector() — 0x8021097C, 732 bytes
// ---------------------------------------------------------------------------
// Moves the cursor position based on analog stick input and camera orientation.
//
// Params:
//   pos (inout): current cursor position, updated with new position
//   stick: analog stick x/y input
//   camera: current camera for getting view direction
//   speed: movement speed multiplier
//
// Algorithm:
//   1. Get camera's target-to-position vector (forward direction)
//   2. Project onto XZ plane (remove Y component)
//   3. Normalize to get camera-relative forward and right vectors
//   4. pos += (stick.x * right + stick.y * forward) * speed * dt
//   5. Clamp result to world bounds
// NON_MATCHING
void MoveCursorAlongCameraTargetVector_doc() {}

// ---------------------------------------------------------------------------
// MoveCursorOneTileAlongCameraTargetVector() — 0x80210C58, 804 bytes
// ---------------------------------------------------------------------------
// Discrete tile-step version of cursor movement. Used when anchored in
// wall/floor modes — each stick input moves exactly one tile.
//
// Uses IMSnapType parameter:
//   0 = snap to tile center
//   1 = snap to tile edge (for walls)
//   2 = snap to tile corner (for walls at diagonals)
// NON_MATCHING
void MoveCursorOneTileAlongCameraTargetVector_doc() {}

// ---------------------------------------------------------------------------
// SnapPositionToTile() — 0x802106C4, 320 bytes
// ---------------------------------------------------------------------------
// Snaps a world position to the nearest tile grid point.
//
// IMSnapType determines snap behavior:
//   Type 0: Snap to tile center (floor painting)
//   Type 1: Snap to tile edge midpoint (wall placement)
//   Type 2: Snap to tile corner (wall corner placement)
// NON_MATCHING
void SnapPositionToTile_doc() {}

// ---------------------------------------------------------------------------
// ClampPosToWorld() — 0x80210F7C, 288 bytes
// ---------------------------------------------------------------------------
// Clamps a position to stay within the lot boundaries.
// Reads world min/max from global data and clamps each axis.
// NON_MATCHING
void ClampPosToWorld_doc() {}

// ---------------------------------------------------------------------------
// IsPosOutsideWorld() — 0x8021109C, 248 bytes
// ---------------------------------------------------------------------------
// Returns true if a position is outside the lot boundaries.
// Used for placement legality checks.
// NON_MATCHING
void IsPosOutsideWorld_doc() {}

// ---------------------------------------------------------------------------
// GetCameraRelativeStickAngle() — 0x80210804, 376 bytes
// ---------------------------------------------------------------------------
// Converts analog stick input to a world-space angle relative to the camera.
// Used by DirectInteractor for sim movement direction.
// NON_MATCHING
void GetCameraRelativeStickAngle_doc() {}

// ---------------------------------------------------------------------------
// ConvertVertsToTiles() — 0x80212D58, 656 bytes
// ---------------------------------------------------------------------------
// Converts two world-space vertex positions to tile coordinates.
// Used by WallManipulator to determine which tiles a wall line crosses.
// Handles diagonal walls and edge cases at lot boundaries.
// NON_MATCHING
void ConvertVertsToTiles_doc() {}

// ---------------------------------------------------------------------------
// GetVisibleSideOfWall() — 0x80212AD8, 640 bytes
// ---------------------------------------------------------------------------
// Determines which side of a wall is facing the camera.
// Used by WallPainter to apply wallpaper to the correct face.
//
// Algorithm:
//   1. Get camera position from ESimsCam
//   2. Calculate wall normal (perpendicular to wall direction)
//   3. Dot product of camera-to-wall vector with wall normal
//   4. Positive dot = front face, negative = back face
// NON_MATCHING
void GetVisibleSideOfWall_doc() {}

// ---------------------------------------------------------------------------
// GetRoomIdFromPoint() — 0x802131F4, 228 bytes
// ---------------------------------------------------------------------------
// Given a tile position, returns the room ID that contains that tile.
// Used by FloorPainter::PaintRoom and WallPainter::FinalizePaperForRoom.
// NON_MATCHING
void GetRoomIdFromPoint_doc() {}

// ---------------------------------------------------------------------------
// CoreIsLegalToPlace() — 0x80211BB4, 216 bytes
// ---------------------------------------------------------------------------
// Core legality check for object placement. Delegates to either
// IsLegalToPlaceSingleTileAtLocation or IsLegalToPlaceMultiTileAtLocation
// depending on the object's footprint.
// NON_MATCHING
void CoreIsLegalToPlace_doc() {}

// ---------------------------------------------------------------------------
// IsLegalToPlaceSingleTileAtLocation() — 0x80211CD8, 1104 bytes
// ---------------------------------------------------------------------------
// Comprehensive legality check for placing a single-tile object:
//   - Tile must be within lot bounds
//   - Floor must exist at tile position
//   - No existing object blocking the tile
//   - Object must be compatible with the surface type
//   - If wall object: wall must exist and have correct orientation
//   - If countertop object: compatible surface must exist
// NON_MATCHING
void IsLegalToPlaceSingleTileAtLocation_doc() {}

// ---------------------------------------------------------------------------
// FinalUserPlaceObject() — 0x802121C4, 460 bytes
// ---------------------------------------------------------------------------
// Final step of placing an object in the world:
//   1. Set object position to tile center
//   2. Add object to tile grid
//   3. Initialize object instances (ISimInstance list)
//   4. Recompute lighting grid around object
//   5. Call UpdateAllObjectsInWorldAfterFirstPickupOrFinalPlace
//   6. Notify game state of new object
// NON_MATCHING
void FinalUserPlaceObject_doc() {}

// ---------------------------------------------------------------------------
// ShadeModelToShowValidState() — 0x802127C8, 784 bytes
// ---------------------------------------------------------------------------
// Changes an object's shader to indicate placement validity:
//   valid=true:  green tinted, semi-transparent (can place here)
//   valid=false: red tinted, semi-transparent (cannot place here)
//
// Iterates through all sub-models and sub-shaders of the cXObjectImpl,
// replacing their shaders with the appropriate colored variant.
// NON_MATCHING
void ShadeModelToShowValidState_doc() {}

// ---------------------------------------------------------------------------
// CreateObjectFromGUID() — 0x802113D8, 148 bytes
// ---------------------------------------------------------------------------
// Creates a new cXObject instance from a catalog GUID.
// Calls the object creation factory with the GUID to instantiate
// the object and its associated model/shader data.
// NON_MATCHING
void CreateObjectFromGUID_doc() {}

// ---------------------------------------------------------------------------
// DestroyObject() — 0x8021146C, 184 bytes
// ---------------------------------------------------------------------------
// Removes an object from the world and deallocates it.
// Used for selling objects or cleaning up canceled placements.
// NON_MATCHING
void DestroyObject_doc() {}

// ---------------------------------------------------------------------------
// CanObjectBeDestroyed() — 0x80211524, 316 bytes
// ---------------------------------------------------------------------------
// Checks if an object can be sold/deleted:
//   - Object must not be in use by a sim
//   - Object must not be a structural element
//   - Object must be destroyable (not a special/locked object)
// NON_MATCHING
void CanObjectBeDestroyed_doc() {}

// ---------------------------------------------------------------------------
// GetCursorIntersectionObjects() — 0x80211660, 520 bytes
// ---------------------------------------------------------------------------
// Raycasts from the cursor position into the world, collecting all
// objects within the selection radius. Returns a vector of short object IDs.
// NON_MATCHING
void GetCursorIntersectionObjects_doc() {}

// ---------------------------------------------------------------------------
// RecomputeLightingGrid() — 0x80212458, 92 bytes
// ---------------------------------------------------------------------------
// Recomputes the lighting grid around an object after placement/removal.
// Objects can cast shadows and block light sources, so the grid must
// be updated whenever objects are added or removed.
// NON_MATCHING
void RecomputeLightingGrid_doc() {}

// ---------------------------------------------------------------------------
// SetDirection() — 0x802124B4, 412 bytes
// ---------------------------------------------------------------------------
// Sets an object's facing direction (0-3, representing 90-degree increments).
// Updates the object's transform matrix and tile footprint.
// NON_MATCHING
void SetDirection_doc() {}

// ---------------------------------------------------------------------------
// ForcePointDir() — 0x802132D8, 692 bytes
// ---------------------------------------------------------------------------
// Forces the wall direction for a wall segment between two tile points.
// Used to ensure consistent wall facing when building wall lines.
// NON_MATCHING
void ForcePointDir_doc() {}

} // namespace InteractorModule


// ============================================================================
//
//     SECTION 12: INVTarget / PCTTarget Callbacks
//     Address range: 0x801F0F94 - 0x801F7E3C (INVTarget)
//                    various (PCTTarget)
//
// ============================================================================
//
// The INVTarget and PCTTarget classes are the UI-side receivers of
// interactor callbacks. When a build/buy mode operation completes,
// the interactor's CommittTransaction calls NotifyClient, which
// invokes these callbacks.
//
// INVTarget callbacks (Buy/Build Mode UI):
//   WallManipulatorCallback     — wall placed/deleted
//   WallPainterCallback         — wallpaper applied/removed
//   FloorModeCallback           — floor tile placed/removed
//   GrabModeCallback            — object grabbed/dropped/sold
//   PlaceModeCallback           — catalog object placed
//
// PCTTarget callbacks (Pet Care/Other UI):
//   Same pattern but for different UI context
//
// Each callback receives a CallbackData struct containing:
//   - Operation result (success/failure)
//   - Cost/refund amount
//   - Stock changes
//   - Pattern/shader IDs for tracking
//
// The callback then:
//   1. Updates the player's simoleon balance
//   2. Adjusts inventory stock counts
//   3. Refreshes the UI display (price labels, stock indicators)
//   4. Plays appropriate sound effects
//

namespace InteractorModule {

// ---------------------------------------------------------------------------
// INVTarget callback flow example:
//
// WallManipulator::CommittTransaction()
//   -> NotifyClient(state, callbackData, sessionParams)
//     -> INVTarget::WallManipulatorCallbackImpl(callbackData)
//       -> CommittChangesToInventory(callbackData)  [0x801F1624, 592 bytes]
//          Updates inventory:
//            - Deduct wall cost from simoleons
//            - Decrement wall stock in inventory
//            - Update UI labels
//
// INVTarget::EnterWallBuildMode()  [0x801F76A8, 636 bytes]
//   Sets up the interactor for wall mode:
//     1. Get WallManipulator from InteractorManager
//     2. Configure wall shader and stock from inventory data
//     3. Set WallManipulatorParams:
//        - Wall shader ID
//        - Stock count
//        - Mode flags
//        - Callback function = WallManipulatorCallbackImpl
//     4. Switch active interactor to WallManipulator via InteractorManager
//
// INVTarget::EnterFloorTilingMode()  [0x801F7B9C, 688 bytes]
//   Same pattern for floor tiles.
//
// INVTarget::EnterWallPaperingMode()  [0x801F7924, 632 bytes]
//   Same pattern for wallpaper.
//
// ---------------------------------------------------------------------------

} // namespace InteractorModule


// ============================================================================
//
//     SECTION 13: Vtable Layouts
//
// ============================================================================
//
// SN Systems vtable format: each entry is 8 bytes [s16 this_adjust, s16 pad, u32 fn_ptr]
// The vtable pointer is at offset 0x5C in the Interactor base class.
//
// ---- Interactor vtable (0x80468270, 208 bytes = 26 entries) ----
//
// Entry  Offset  Function
//  0     0x00    ~Interactor (destructor)
//  1     0x08    OnCreate
//  2     0x10    OnDestroy
//  3     0x18    OnStart(InteractorParams*)
//  4     0x20    OnStop
//  5     0x28    Update(float)
//  6     0x30    GetInteractorInfo(InteractorInfo&)
//  7     0x38    OnCommandPressed(InteractorCommand, float)
//  8     0x40    OnCommandReleased(InteractorCommand)
//  9     0x48    OnCommandUpdate(InteractorCommand, float)
// 10     0x50    ResetInputState
// 11     0x58    GetSelectionRadius
// 12     0x60    PreDraw(InteractorVisualizer&)
// 13     0x68    Draw(InteractorVisualizer&)
// 14     0x70    Moved
// 15     0x78    AddIdleTime(float)
// 16     0x80    ResetIdleTime
// 17     0x88    UpdateOverlapIntersection(OverlapData*)
// 18     0x90    ExecuteObjectActionMenu(cXObject*)
// 19     0x98    StopInObjectMenu
// 20     0xA0    ChooseAction(Interaction*)
// 21     0xA8    GetPos
// 22     0xB0    GetSnappedPos
// 23     0xB8    SnapToPos(EVec3&)
// 24     0xC0    UpdateObjectHighlights(EIObjectMan*)
// 25     0xC8    SetExtents(EVec2&)
//
// Each subclass overrides relevant entries. For example:
//   DirectInteractor vtable (0x804680A0) overrides entries 0-14, 17-20
//   WallManipulator vtable (0x80468790) overrides entries 0-14
//   FloorPainter vtable (0x80468170) overrides entries 0-14
//   GrabManipulator vtable (0x80468428) overrides entries 0-7, 12-13
//
// ============================================================================


// ============================================================================
//
//     SECTION 14: Data Structures Summary
//
// ============================================================================
//
// ---- InteractorType enum (inferred from InteractorManager) ----
//
// enum InteractorType {
//     kDirectInteractor     = 0,  // Live mode - direct sim control
//     kSimInteractor        = 1,  // Live mode - cursor sim selection
//     kSocialModeInteractor = 2,  // Live mode - social interaction
//     kGrabManipulator      = 3,  // Buy mode - grab objects
//     kPlaceManipulator     = 4,  // Buy mode - place catalog objects
//     kWallManipulator      = 5,  // Build mode - walls
//     kWallPainter          = 6,  // Build mode - wallpaper
//     kFloorPainter         = 7,  // Build mode - floor tiles
//     kNumInteractorTypes   = 8
// };
//
// ---- IMSnapType enum (used by SnapPositionToTile) ----
//
// enum IMSnapType {
//     kSnapTileCenter = 0,   // Snap to center of tile (objects, floor)
//     kSnapTileEdge   = 1,   // Snap to edge midpoint (walls)
//     kSnapTileCorner = 2    // Snap to tile corner (wall intersections)
// };
//
// ---- WallData (used by INVTarget for wall catalog) ----
//
// struct WallData {
//     u32 shaderID;          // Wall shader/style identifier
//     u32 price;             // Cost per wall segment
//     u32 stock;             // Current inventory count
//     // ... additional catalog fields
// };
//
// ---- WallPaperData (used by INVTarget for wallpaper catalog) ----
//
// struct WallPaperData {
//     u32 shaderID;          // Wallpaper pattern shader
//     u32 price;             // Cost per wall face
//     u32 stock;             // Current inventory count
// };
//
// ---- FloorData (used by INVTarget for floor tile catalog) ----
//
// struct FloorData {
//     u32 shaderID;          // Floor pattern shader
//     u32 price;             // Cost per tile
//     u32 stock;             // Current inventory count
// };
//
// ---- ShoppingItem (used by INVTarget for buy mode catalog) ----
//
// struct ShoppingItem {
//     u32 objectGUID;        // Object type identifier
//     u32 price;             // Object price
//     u32 stock;             // Available stock
//     // ... additional catalog fields
// };
//
// ---- InvStock (tracks per-object-GUID sell counts) ----
//
// struct InvStock {
//     u32 objectGUID;
//     u32 sellCount;
// };
//
// ---- PatternSellCount (tracks per-pattern sell counts for refunds) ----
//
// struct PatternSellCount {
//     u32 patternID;
//     u32 sellCount;
// };
//
// ---- FenceSellCount (tracks fence sell counts) ----
//
// struct FenceSellCount {
//     u32 fenceStyleID;
//     u32 sellCount;
// };
//
// ---- CallbackData base (from Interactor::CallbackData) ----
//
// struct CallbackData {    // 0x10+ bytes, with vtable
//     u32 state;           // ClientNotificationState (success/fail/cancel)
//     u32 field_04;        // varies by subclass
//     u32 callbackOffset;  // offset into callback function table
//     u32 callbackFnPtr;   // function pointer for callback
//     // vtable at some offset (SN Systems places it differently per class)
// };
//
// ---- ButtonSemantic (input mapping) ----
//
// struct ButtonSemantic {
//     InteractorCommand command;  // Which interactor command this maps to
//     ECTRL_CMD controllerButton; // Which physical button
//     // ... additional mapping data
// };
//
// ---- StickSemantic (stick input mapping) ----
//
// struct StickSemantic {
//     InteractorCommand command;  // X or Y axis command
//     u32 axis;                   // Physical stick axis ID
//     f32 deadZone;               // Minimum magnitude to register
//     // ... additional mapping data
// };
//
// ============================================================================
