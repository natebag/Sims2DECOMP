// statemachine_decomp.cpp - Decompiled state machine system
// Covers: StateMachineState, StateMachine, StateMachineStatus, StateMachineManager,
//         TheSimsStateMachine, TheSimsStartScreenStateMachine, LoadingScreenStateMachine,
//         LiveModeInitState, and all related state classes
//
// These classes control the entire game flow:
//   Boot -> NGC License -> MemCard Check -> Maxis Logo -> Sims Intro -> EA Movie
//   -> Enter Main Menu -> Main Menu -> (PreGame States | Live Mode | CAS | Story)
//
// Original source files (from map):
//   statemachine.obj, thesims.obj, basestates.obj, inlevel.obj, livemode.obj,
//   pregamestate.obj, startscreen.obj, urbzmode.obj, loadingscreenstate.obj,
//   movieplayer.obj
//
// ============================================================================

#include "core/statemachine.h"
#include "core/gamestate.h"

// ============================================================================
// GAME STATE GRAPH
// ============================================================================
//
// TheSimsStateMachine is the master state machine that governs the entire game
// flow. It contains 20 states (IDs 0-19), each representing a major game
// phase. State transitions are driven by SetNextState(), CallState(), and
// ReturnFromState() within each state's Update() method.
//
// TheSimsStartScreenStateMachine (state 5) is itself a nested StateMachine
// that manages the title/start screen flow. LoadingScreenStateMachine is
// another sub-machine controlling fade-in/update/fade-out during loads.
// LiveModeChangeHouseStateMachine (state 19) manages house-change flow.
//
// ============================================================================
// STATE ID MAP (TheSimsStateMachine)
// ============================================================================
//
//  ID | Class                          | Size  | Description
// ----+--------------------------------+-------+-----------------------------------
//   0 | TheSimsNGCLicenseState         | 0x50  | NGC/Nintendo license screen
//   1 | TheSimsMemCardCheckState       | 0x1C  | Memory card detection & check
//   2 | TheSimsMaxisLogoState          | 0x20  | Maxis logo splash screen
//   3 | TheSimsSimsIntroMovieState     | 0x34  | "The Sims 2" intro cinematic
//   4 | TheSimsEAMovieState            | 0x28  | EA logo / movie
//   5 | TheSimsStartScreenStateMachine | 0x98  | Title screen ("Press Start")
//   6 | TheSimsEnterMainMenuState      | 0x20  | Transition into main menu
//   7 | TheSimsMainMenuState           | 0x28  | Main menu (New Game, Load, etc.)
//   8 | PreGameState                   | 0x30  | Pre-game setup / neighborhood
//   9 | PreGameFreeplayState           | 0x20  | Freeplay mode selection
//  10 | PreGameCasPlayer1State         | 0x30  | CAS for player 1 (pre-game)
//  11 | PreGameCasPlayer2State         | 0x30  | CAS for player 2 (pre-game)
//  12 | PreGameCreateAFamilyState      | 0x30  | Create-A-Family (pre-game)
//  13 | LiveModeInitState              | 0xB4  | Live mode initialization & loading
//  14 | InLevelCreateASimState         | 0x30  | In-level CAS editor
//  15 | MoviePlayerEndgameMovieState   | 0x48  | Endgame movie playback
//  16 | UrbzModeNewGameState           | 0x1C  | Urbz story mode new game
//  17 | UrbzCreditsState               | 0x1C  | Urbz credits roll
//  18 | InLevelBaseState               | 0x20  | Live mode gameplay (base)
//  19 | LiveModeChangeHouseStateMachine| 0x98  | House change flow (embedded SM)
//
// ============================================================================
// STATE TRANSITION GRAPH
// ============================================================================
//
//  [0: NGC License]
//       |
//       v  (auto-advance after display)
//  [1: MemCard Check]
//       |
//       v  (auto-advance after check)
//  [2: Maxis Logo]
//       |
//       v  (auto-advance / skip on button press)
//  [3: Sims Intro Movie]
//       |
//       v  (auto-advance / skip)
//  [4: EA Movie]
//       |
//       v  (auto-advance / skip)
//  [5: Start Screen]  <--+
//       |                 |
//       v  (Press Start)  |
//  [6: Enter Main Menu]   |
//       |                 |
//       v                 |
//  [7: Main Menu] --------+-- (back)
//       |
//       +---> [8:  PreGameState]     -- New Game flow
//       |         |
//       |         +---> [10: CAS Player 1]
//       |         +---> [11: CAS Player 2]
//       |         +---> [12: Create-A-Family]
//       |         +---> [9:  Freeplay Mode]
//       |
//       +---> [13: LiveModeInit]     -- Load existing game
//       |         |
//       |         v
//       |    [18: InLevelBase]       -- Main gameplay loop
//       |         |
//       |         +---> [14: In-Level CAS]
//       |         +---> [19: Change House SM]
//       |         +---> [7:  Main Menu] (exit)
//       |
//       +---> [16: Urbz New Game]    -- Story mode
//       |         |
//       |         v
//       |    [18: InLevelBase]
//       |
//       +---> [15: Endgame Movie]
//       +---> [17: Urbz Credits]
//
// ============================================================================
// LOADING SCREEN STATE MACHINE (sub-states)
// ============================================================================
//
//  ID | Class                            | Description
// ----+----------------------------------+-----------------------------
//   0 | LoadingScreenWaitingForLoadState  | Waiting for load request
//   1 | LoadingScreenFadeInState          | Fade-in transition
//   2 | LoadingScreenUpdateState          | Active loading / progress bar
//   3 | LoadingScreenFadeOutState         | Fade-out transition
//
//   Flow: [0: Waiting] -> [1: FadeIn] -> [2: Update/Load] -> [3: FadeOut] -> [0: Waiting]
//
// ============================================================================
// START SCREEN STATE MACHINE (sub-states within state 5)
// ============================================================================
//
//  ID | Class                  | Description
// ----+------------------------+-----------------------------
//   0 | StartScreenStartState  | "Press Start" prompt + attract mode
//
// ============================================================================

// Forward declarations
class ERC;
class CLoadingScreen;
class CameraDirector;
class ESimsCam;

// ============================================================================
// External references
// ============================================================================

extern "C" {
    // SDA globals
    extern StateMachineManager* g_pStateMachineManager;  // r13 - 0xAC04
    extern int g_bDrawTopmost;                            // bss
    extern void* g_pStartScreenVars;                      // r13 - 0x9FBC (r13-24508)

    // Memory
    void* operator_new_wrapper(unsigned int size);        // 0x802D11B0
    void operator_delete_wrapper(void* ptr);              // 0x802D1220
    void* small_alloc(unsigned int size);                 // 0x8039C304
    void small_free(void* ptr);                           // 0x8039BE60
    void* memcpy(void* dst, const void* src, unsigned int n); // 0x802434F8

    // Deque init
    void deque_init(void* deq, int param);                // 0x8039BF3C

    // Float constants
    extern const float kFloat_0_0f;   // 0x803E88D0
    extern const float kFloat_neg1f;  // 0x803E88B4
}

// ============================================================================
// StateMachineState - Base state class
// ============================================================================
// All states inherit from this. The key fields:
//   0x00: m_stateId     - unique integer ID within the owning machine
//   0x04: m_prevStateId - previous state ID (-1 if none)
//   0x08: m_pOwner      - pointer back to owning StateMachine
//   0x0C: m_stage       - current stage/phase within this state
//   0x10: m_unused10    - reserved
//   0x14: m_active      - 1 if state is active
//   0x18: m_pVtable     - pointer to derived class vtable
//
// Virtual functions (via vtable at offset 0x18):
//   vtable+0x08: destructor (with delete mode param)
//   vtable+0x14: SetFlag(unsigned int)
//   vtable+0x18: Startup(void)        -- called when entering state
//   vtable+0x1C: Shutdown(void)       -- called when leaving state
//   vtable+0x20: Startup(void)        -- alternate entry (used by Update loop)
//   vtable+0x24: Startup fn ptr       -- actual function pointer
//   vtable+0x28: Update this-adj      -- this adjustment for Update
//   vtable+0x2C: Update fn ptr        -- Update(float) function pointer
//   vtable+0x30: Draw this-adj        -- this adjustment for Draw
//   vtable+0x34: Draw fn ptr          -- Draw(ERC*) function pointer
//   vtable+0x38: DrawTopmost this-adj
//   vtable+0x3C: DrawTopmost fn ptr   -- DrawTopmost(ERC*) function pointer
//
// The SN Systems compiler uses a vtable entry format of:
//   [2-byte this-adjustment] [2-byte padding] [4-byte function pointer]

// StateMachineState::Startup(void)
// 0x803A024C - 4 bytes - empty virtual
void StateMachineState_Startup(void) {
    // No-op base implementation
}

// StateMachineState::Shutdown(void)
// 0x803A02BC - 4 bytes - empty virtual
void StateMachineState_Shutdown(void) {
    // No-op base implementation
}

// StateMachineState::Reset(void)
// 0x803A02C0 - 4 bytes - empty virtual
void StateMachineState_Reset(void) {
    // No-op base implementation
}

// StateMachineState::Update(float)
// 0x803A02C4 - 4 bytes - empty virtual
void StateMachineState_Update(float dt) {
    // No-op base implementation
}

// StateMachineState::Draw(ERC *)
// 0x803A02C8 - 4 bytes - empty virtual
void StateMachineState_Draw(void* pRC) {
    // No-op base implementation
}

// StateMachineState::DrawTopmost(ERC *)
// 0x803A0250 - 4 bytes - empty virtual
void StateMachineState_DrawTopmost(void* pRC) {
    // No-op base implementation
}

// StateMachineState::OwnerSetNextState(int, float)
// 0x80095AA4 - 36 bytes
// Delegates to the owning StateMachine's SetNextState
void StateMachineState::OwnerSetNextState(int stateId, float delay) {
    ((StateMachine*)m_unused08)->SetNextState(stateId, delay);
}

// StateMachineState::OwnerCallState(int)
// 0x80095AC8 - 36 bytes
// Delegates to the owning StateMachine's CallState
void StateMachineState::OwnerCallState(int stateId) {
    ((StateMachine*)m_unused08)->CallState(stateId);
}

// StateMachineState::OwnerReturnFromState(int)
// 0x80095AEC - 36 bytes
// Delegates to the owning StateMachine's ReturnFromState
void StateMachineState::OwnerReturnFromState(int returnVal) {
    ((StateMachine*)m_unused08)->ReturnFromState(returnVal);
}

// StateMachineState::OwnerGetReturnVal(void)
// 0x80095B10 - 12 bytes
int StateMachineState::OwnerGetReturnVal(void) {
    return ((StateMachine*)m_unused08)->m_returnVal;
}

// StateMachineState::OwnerResetReturnVal(void)
// 0x80095B1C - 16 bytes
void StateMachineState::OwnerResetReturnVal(void) {
    ((StateMachine*)m_unused08)->m_returnVal = 0;
}

// StateMachineState::ValidateHeap(bool)
// 0x80095B2C - 4 bytes - no-op
void StateMachineState::ValidateHeap(bool) {
}

// StateMachineState::SetFlag(unsigned int)
// 0x8039CFFC - 20 bytes
// Sets the active flag on the state
void StateMachineState_SetFlag(StateMachineState* self, unsigned int flag) {
    self->m_active = flag;
}

// ============================================================================
// StateMachineStatus - State tracking within a machine
// ============================================================================
// Embedded in StateMachine at offset 0x3C. Tracks:
//   m_pCurState              - currently active state
//   m_pLastState             - previously active state
//   m_pCallingState          - state that called into this one (for CallState)
//   m_stageFlags             - current stage flags
//   m_secondsBeforeNextState - timer for delayed transitions
//   m_secondsInCurState      - time spent in current state

// StateMachineStatus::StatusReset(void)
// 0x800963FC - 40 bytes
void StateMachineStatus::StatusReset(void) {
    m_stageFlags = 0;
    m_secondsInCurState = -1.0f;
    m_pCurState = 0;
    m_pLastState = 0;
    m_pCallingState = 0;
    m_secondsBeforeNextState = -1.0f;
}

// StateMachineStatus::AddToSecondsInCurState(float)
// 0x80096504 - 16 bytes
void StateMachineStatus::AddToSecondsInCurState(float dt) {
    m_secondsInCurState = m_secondsInCurState + dt;
}

// StateMachineStatus::AddToSecondsBeforeNextState(float)
// 0x800964D8 - 44 bytes
// Decrements timer, clamps to 0. Timer drives delayed state transitions.
void StateMachineStatus::AddToSecondsBeforeNextState(float dt) {
    float val = m_secondsBeforeNextState;
    if (val <= 0.0f) {
        return;
    }
    val = val + dt;  // dt is negative (subtracting time)
    m_secondsBeforeNextState = val;
    if (val < 0.0f) {
        m_secondsBeforeNextState = 0.0f;
    }
}

// StateMachineStatus::SetState(StateMachineState *)
// 0x80096424 - 180 bytes
// NON_MATCHING - complex vtable dispatch for Shutdown/Reset
// Shuts down current state, swaps in new state, calls Reset on it
void StateMachineStatus::SetState(StateMachineState* pNewState) {
    StateMachineState* pOldState = m_pCurState;

    // Shutdown old state via vtable
    if (pOldState != 0) {
        void** vtbl = (void**)pOldState->m_pVtable;
        short thisAdj = *(short*)((char*)vtbl + 0x0C);   // Shutdown this-adj
        void (*shutdownFn)(void*, int) = (void(*)(void*, int))*(void**)((char*)vtbl + 0x10);
        // The "stage 3" param indicates a state transition shutdown
        shutdownFn((char*)pOldState + thisAdj, 3);
    }

    m_pLastState = pOldState;
    m_pCurState = pNewState;
    m_stageFlags = 0;
    m_secondsInCurState = 0.0f;
    m_secondsBeforeNextState = -1.0f;

    // Reset new state via vtable
    if (pNewState != 0) {
        void** vtbl = (void**)pNewState->m_pVtable;
        short thisAdj = *(short*)((char*)vtbl + 0x18);
        void (*resetFn)(void*) = (void(*)(void*))*(void**)((char*)vtbl + 0x1C);
        resetFn((char*)pNewState + thisAdj);
    }
}

// StateMachineStatus::ShutdownCurState(void)
// 0x80096514 - 84 bytes
// Shuts down and clears the current state
void StateMachineStatus::ShutdownCurState(void) {
    StateMachineState* pState = m_pCurState;
    if (pState != 0) {
        // Call Shutdown via vtable
        void** vtbl = (void**)pState->m_pVtable;
        short thisAdj = *(short*)((char*)vtbl + 0x0C);
        void (*shutdownFn)(void*, int) = (void(*)(void*, int))*(void**)((char*)vtbl + 0x10);
        shutdownFn((char*)pState + thisAdj, 3);
    }
    m_pCurState = 0;
    m_secondsBeforeNextState = -1.0f;
}

// StateMachineStatus::UpdateCurState(float)
// 0x80096568 - 64 bytes
// Dispatches Update to current state via vtable
void StateMachineStatus::UpdateCurState(float dt) {
    StateMachineState* pState = m_pCurState;
    if (pState != 0) {
        void** vtbl = (void**)pState->m_pVtable;
        short thisAdj = *(short*)((char*)vtbl + 0x28);
        void (*updateFn)(void*, float) = (void(*)(void*, float))*(void**)((char*)vtbl + 0x2C);
        updateFn((char*)pState + thisAdj, dt);
    }
}

// StateMachineStatus::DrawCurState(ERC *)
// 0x800965A8 - 64 bytes
void StateMachineStatus::DrawCurState(ERC* pRC) {
    StateMachineState* pState = m_pCurState;
    if (pState != 0) {
        void** vtbl = (void**)pState->m_pVtable;
        short thisAdj = *(short*)((char*)vtbl + 0x30);
        void (*drawFn)(void*, ERC*) = (void(*)(void*, ERC*))*(void**)((char*)vtbl + 0x34);
        drawFn((char*)pState + thisAdj, pRC);
    }
}

// StateMachineStatus::DrawTopmostCurState(ERC *)
// 0x800965E8 - 64 bytes
void StateMachineStatus::DrawTopmostCurState(ERC* pRC) {
    StateMachineState* pState = m_pCurState;
    if (pState != 0) {
        void** vtbl = (void**)pState->m_pVtable;
        short thisAdj = *(short*)((char*)vtbl + 0x38);
        void (*drawTopmostFn)(void*, ERC*) = (void(*)(void*, ERC*))*(void**)((char*)vtbl + 0x3C);
        drawTopmostFn((char*)pState + thisAdj, pRC);
    }
}

// ============================================================================
// StateMachine - Core state machine engine
// ============================================================================
// Layout (0x98 bytes total):
//   0x00-0x17: inherited/vtable area (0x18 = derived vtable ptr)
//   0x00:      m_stateId (from StateMachineState base - reused as machine context)
//   0x04:      m_prevStateId
//   0x08:      m_pOwnerOrContext
//   0x0C:      m_stage
//   0x10:      m_unused10
//   0x14:      m_active
//   0x18:      m_pVtable (StateMachine vtable at 0x8045E100)
//   0x1C:      m_machineId
//   0x20:      m_pManager
//   0x24:      m_pauseUpdate
//   0x28:      m_frameDeltaTime (float)
//   0x2C-0x38: m_states (std::vector<StateMachineState*>) - begin/end/capacity
//   0x3C-0x53: m_status (StateMachineStatus) - current state tracking
//   0x54-0x6B: m_statusStack[0] (StateMachineStatus) - for PushStatus/PopStatus
//   0x6C-0x83: m_statusStack[1] (StateMachineStatus) - second level
//   0x84:      m_pCallState     - pending CallState target
//   0x88:      m_returnFlag     - 1 = ReturnFromState pending
//   0x8C:      m_returnStateId  - value to return with
//   0x90:      m_returnVal      - return value accessible by caller
//   0x94:      m_enabled        - 1 = machine is active

// StateMachine::StateMachine(int, int)
// 0x8009696C - 252 bytes
// Constructs a state machine with the given IDs and initializes all fields
// NON_MATCHING - complex field initialization, deque_init call
StateMachine::StateMachine(int machineId, int managerId) {
    // First 6 fields from StateMachineState base
    m_machineId = machineId;         // at 0x00 conceptually; actual layout uses 0x1C
    // m_pManager set by manager on AddMachine
    m_pauseUpdate = 0;
    m_frameDeltaTime = 0.0f;

    // Vector init (begin=end=0, capacity=0)
    m_pStatesBegin = 0;
    m_pStatesEnd = 0;
    // capacity ptr = 0

    // Status init
    m_status.StatusReset();

    // Status stack init (two levels for nested CallState)
    // m_statusStack[0] and m_statusStack[1] zeroed

    // Deque init for status stack
    deque_init(&_pad54, 0);  // initializes the deque at offset 0x54

    m_returnVal = 0;
    m_enabled = 1;
    m_pCallState = 0;
    m_returnFlag = 0;
    m_returnStateId = 0;
}

// StateMachine::~StateMachine(void)
// 0x80096A68 - 144 bytes
// Destroys the state machine, deleting all states and freeing the vector
// NON_MATCHING
StateMachine::~StateMachine(void) {
    // DeleteAllStates destroys each state via vtable dtor and frees vector
    DeleteAllStates();
    // Destructor also cleans up the deque
}

// StateMachine::Startup(void)
// 0x80096AF8 - 4 bytes
void StateMachine::Startup(void) {
    // Empty base implementation - derived classes override
}

// StateMachine::Shutdown(void)
// 0x80096AFC - 36 bytes
void StateMachine::Shutdown(void) {
    m_status.ShutdownCurState();
}

// StateMachine::Reset(void)
// 0x80096B20 - 4 bytes
void StateMachine::Reset(void) {
    // Empty base implementation
}

// StateMachine::Update(float)
// 0x80095B30 - 472 bytes
// The core update loop. Processes state transitions in this order:
//   1. If paused or disabled, skip
//   2. Accumulate time in current state
//   3. Process pending CallState (push current, enter called state)
//   4. Process pending ReturnFromState (pop to previous state)
//   5. Process pending SetNextState with delay timer
//   6. If transition occurred, call Startup on new state
//   7. Call UpdateCurState(dt) on current state
//
// NON_MATCHING - complex control flow with vtable dispatch
void StateMachine_Update_impl(StateMachine* self, float dt) {
    if (self->m_enabled == 0) return;
    if (self->m_pauseUpdate != 0) return;

    // Store frame delta time
    self->m_frameDeltaTime = dt;

    // Accumulate time
    self->m_status.AddToSecondsInCurState(dt);

    int didTransition = 0;

    // --- Process CallState ---
    // CallState stores the target in m_pCallState. Update processes it by:
    //   1. Pushing current status onto the status stack
    //   2. Setting calling state reference
    //   3. Setting the called state as current
    StateMachineState* callState = self->m_pCallState;
    if (callState != 0) {
        while (self->m_pCallState != 0) {
            didTransition = 1;
            StateMachineState* nextCall = self->m_pCallState;
            self->m_pCallState = 0;

            // Save current state reference
            StateMachineState* prevState = self->m_status.m_pCurState;

            // PushStatus - saves m_status onto the stack
            self->PushStatus();

            // StatusReset on new level
            self->m_status.StatusReset();

            // Set calling state so ReturnFromState knows where to go back
            self->m_status.m_pCallingState = prevState;

            // Set the called state as current
            self->m_status.SetState(nextCall);

            self->m_returnVal = 0;
        }
    }

    // --- Process ReturnFromState ---
    // ReturnFromState sets m_returnFlag=1 and m_returnStateId=value.
    // Update processes it by popping the status stack.
    if (self->m_returnFlag != 0) {
        StateMachineState* prevState = self->m_status.m_pCurState;

        // ShutdownCurState on the called state
        self->m_status.ShutdownCurState();

        // PopStatus - restores m_status from the stack
        self->PopStatus();

        int retStateId = self->m_returnStateId;
        self->m_returnFlag = 0;

        // Store previous state and return value for the calling state to read
        // (m_field_044 = prevState, m_returnVal = retStateId)
        self->m_returnVal = retStateId;
    }

    // --- Process SetNextState with delay ---
    // SetNextState stores target in m_status.m_pNextState and delay timer.
    // The timer is decremented each frame; when it reaches 0, the transition fires.
    StateMachineState* nextState = (StateMachineState*)
        *((void**)((char*)self + 0x40));  // next state pointer
    if (nextState != 0) {
        float timer = *((float*)((char*)self + 0x4C));  // delay timer
        if (timer == 0.0f) {
            didTransition = 1;
            // Process immediate transitions in a loop (chained SetNextState)
            while (nextState != 0) {
                *((void**)((char*)self + 0x40)) = 0;
                self->m_status.SetState(nextState);
                nextState = (StateMachineState*)*((void**)((char*)self + 0x40));
                if (nextState == 0) break;
                timer = *((float*)((char*)self + 0x4C));
                if (timer != 0.0f) break;
            }
        }
    }

    // --- Call Startup on new state after transition ---
    if (didTransition) {
        StateMachineState* curState = self->m_status.m_pCurState;
        if (curState != 0) {
            // Virtual call: Startup()
            void** vtbl = (void**)curState->m_pVtable;
            short thisAdj = *(short*)((char*)vtbl + 0x20);
            void (*startupFn)(void*) = (void(*)(void*))*(void**)((char*)vtbl + 0x24);
            startupFn((char*)curState + thisAdj);
        }
        // Check if the state's active flag indicates it should skip Update
        int pending = curState->m_active;
        if (pending == 0) return;
    }

    // --- Update current state ---
    self->m_status.UpdateCurState(dt);
}

// StateMachine::SetNextState(int, float)
// 0x80095D78 - 76 bytes
// Finds the state by ID, stores it and the delay timer for processing in Update
void StateMachine::SetNextState(int stateId, float delay) {
    StateMachineState* pState = FindStateById(stateId);
    if (pState != 0) {
        // Store next state pointer at status offset 0x04 (m_pNextState)
        // and delay at status offset 0x10 (m_secondsBeforeNextState)
        StateMachineStatus* pStatus = &m_status;
        pStatus->m_secondsBeforeNextState = delay;
        *((StateMachineState**)((char*)pStatus + 0x04)) = pState;
    }
}

// StateMachine::CallState(int)
// 0x80095DC4 - 56 bytes
// Requests a state call - the actual push happens in Update
void StateMachine::CallState(int stateId) {
    StateMachineState* pState = FindStateById(stateId);
    if (pState != 0) {
        m_pCallState = pState;
    }
}

// StateMachine::ReturnFromState(int)
// 0x80095DFC - 16 bytes
// Requests a return from the current called state
void StateMachine::ReturnFromState(int returnVal) {
    m_returnFlag = 1;
    m_returnStateId = returnVal;
}

// StateMachine::Draw(ERC *)
// 0x80095D08 - 48 bytes
void StateMachine::Draw(ERC* pRC) {
    if (m_enabled != 0) {
        m_status.DrawCurState(pRC);
    }
}

// StateMachine::DrawTopmost(ERC *)
// 0x80095D38 - 64 bytes
void StateMachine::DrawTopmost(ERC* pRC) {
    if (g_bDrawTopmost != 0) {
        if (m_enabled != 0) {
            m_status.DrawTopmostCurState(pRC);
        }
    }
}

// StateMachine::GetCurStateId(void) const
// 0x80095E0C - 28 bytes
int StateMachine::GetCurStateId(void) const {
    StateMachineState* pState = m_status.m_pCurState;
    if (pState == 0) return -1;
    return pState->m_stateId;
}

// StateMachine::GetCurStateStage(void) const
// 0x80095E28 - 12 bytes
int StateMachine::GetCurStateStage(void) const {
    return m_status.m_pCurState->m_stage;
}

// StateMachine::GetLastStateId(void) const
// 0x80095EA8 - 12 bytes
int StateMachine::GetLastStateId(void) const {
    return m_status.m_pLastState->m_stateId;
}

// StateMachine::GetCallingStateId(void) const
// 0x80095EB4 - 12 bytes
int StateMachine::GetCallingStateId(void) const {
    return m_status.m_pCallingState->m_stateId;
}

// StateMachine::GetTimeInState(void) const
// 0x800961B4 - 8 bytes
float StateMachine::GetTimeInState(void) const {
    return m_status.m_secondsInCurState;
}

// StateMachine::FindStateById(int)
// 0x800961BC - 56 bytes
StateMachineState* StateMachine::FindStateById(int stateId) {
    StateMachineState** iter = m_pStatesBegin;
    StateMachineState** end = m_pStatesEnd;
    while (iter != end) {
        StateMachineState* pState = *iter;
        if (pState->m_stateId == stateId) {
            return pState;
        }
        iter++;
    }
    return 0;
}

// StateMachine::FindState(StateMachineState *)
// 0x800961F4 - 48 bytes
StateMachineState* StateMachine::FindState(StateMachineState* pState) {
    StateMachineState** iter = m_pStatesBegin;
    StateMachineState** end = m_pStatesEnd;
    while (iter != end) {
        if (*iter == pState) {
            return *iter;
        }
        iter++;
    }
    return 0;
}

// StateMachine::SetState(StateMachineState *)
// 0x80096224 - 56 bytes
void StateMachine::SetState(StateMachineState* pState) {
    m_status.SetState(pState);
    m_returnVal = 0;
}

// StateMachine::AddState(StateMachineState *)
// 0x80095F10 - 368 bytes
// NON_MATCHING - vector push_back with small/large alloc paths
// Adds a state to the machine's state list. If already present, just sets owner.
void StateMachine::AddState(StateMachineState* pState) {
    // Check if state already in vector
    if (FindState(pState) != 0) {
        pState->m_unused08 = (int)this;  // set owner
        return;
    }

    // Vector push_back with grow logic
    StateMachineState** end = m_pStatesEnd;
    StateMachineState** capEnd = (StateMachineState**)_pad34;
    if (end != capEnd) {
        // Space available - just append
        *end = pState;
        m_pStatesEnd = end + 1;
    } else {
        // Need to grow - allocate new buffer, copy, free old
        int count = (int)(end - m_pStatesBegin);
        int newCount = count + 1;
        int newBytes = newCount * 4;
        StateMachineState** newBuf;
        if (newBytes == 0) {
            newBuf = 0;
        } else if ((unsigned int)newBytes > 128) {
            newBuf = (StateMachineState**)operator_new_wrapper(newBytes);
        } else {
            newBuf = (StateMachineState**)small_alloc(newBytes);
        }
        StateMachineState** newEnd;
        if (end != m_pStatesBegin) {
            int copySize = (int)((char*)end - (char*)m_pStatesBegin);
            memcpy(newBuf, m_pStatesBegin, copySize);
            newEnd = (StateMachineState**)((char*)newBuf + copySize);
        } else {
            newEnd = newBuf;
        }
        *newEnd = pState;
        newEnd++;
        if (m_pStatesBegin != 0) {
            int oldSize = (int)((char*)capEnd - (char*)m_pStatesBegin);
            if ((unsigned int)oldSize > 128)
                operator_delete_wrapper(m_pStatesBegin);
            else
                small_free(m_pStatesBegin);
        }
        m_pStatesBegin = newBuf;
        m_pStatesEnd = newEnd;
        // capEnd = newBuf + newCount
    }
    pState->m_unused08 = (int)this;  // set owner
}

// StateMachine::DeleteAllStates(void)
// 0x80096080 - 308 bytes
// NON_MATCHING - destroys each state via vtable dtor, frees vector
void StateMachine::DeleteAllStates(void) {
    m_status.ShutdownCurState();
    m_status.m_pCurState = 0;

    StateMachineState** iter = m_pStatesBegin;
    StateMachineState** end = m_pStatesEnd;
    while (iter != end) {
        StateMachineState* pState = *iter;
        if (pState != 0) {
            // Call destructor via vtable (mode=3 => delete)
            void** vtbl = (void**)pState->m_pVtable;
            short thisAdj = *(short*)((char*)vtbl + 0x08);
            void (*dtorFn)(void*, int) = (void(*)(void*, int))*(void**)((char*)vtbl + 0x0C);
            dtorFn((char*)pState + thisAdj, 3);
        }
        *iter = 0;
        iter++;
    }

    // Free vector memory
    StateMachineState** oldBegin = m_pStatesBegin;
    m_pStatesBegin = 0;
    m_pStatesEnd = 0;
    if (oldBegin != 0) {
        // free based on size
    }
}

// StateMachine::PushStatus(void)
// 0x8009625C - 176 bytes
// NON_MATCHING - pushes current m_status onto deque-based stack
void StateMachine::PushStatus(void) {
    // Copies m_status (0x18 bytes) into the status stack deque
    // The stack supports 2 levels of nesting for CallState
}

// StateMachine::PopStatus(void)
// 0x8009630C - 240 bytes
// NON_MATCHING - pops status from deque-based stack
void StateMachine::PopStatus(void) {
    // Restores m_status from the top of the status stack deque
}

// StateMachine accessors (trivial)
// 0x80096B24 - GetMachineId
int StateMachine::GetMachineId(void) const { return m_machineId; }
// 0x80096B2C - GetManager
StateMachineManager* StateMachine::GetManager(void) const { return m_pManager; }
// 0x80096B34 - GetFrameDeltaTime
float StateMachine::GetFrameDeltaTime(void) const { return m_frameDeltaTime; }
// 0x80096B3C - GetReturnVal
int StateMachine::GetReturnVal(void) const { return m_returnVal; }
// 0x80096B44 - ResetReturnVal
void StateMachine::ResetReturnVal(void) { m_returnVal = 0; }
// 0x80096B50 - Enable
void StateMachine::Enable(void) { m_enabled = 1; }
// 0x80096B5C - Disable
void StateMachine::Disable(void) { m_enabled = 0; }
// 0x80096B68 - PauseUpdate
void StateMachine::PauseUpdate(void) { m_pauseUpdate = 1; }
// 0x80096B74 - UnpauseUpdate
void StateMachine::UnpauseUpdate(void) { m_pauseUpdate = 0; }
// 0x80096B80 - IsEnabled
int StateMachine::IsEnabled(void) { return m_enabled; }
// 0x80096B88 - IsPausedUpdate
int StateMachine::IsPausedUpdate(void) { return m_pauseUpdate; }

// ============================================================================
// StateMachineManager - Singleton managing all state machines
// ============================================================================
// Accessed via SDA global g_pStateMachineManager (r13 - 0xAC04).
// Maintains a vector of StateMachine pointers.
//   0x00: m_pBegin (StateMachine**)
//   0x04: m_pEnd   (StateMachine**)
// Uses the same update/draw pattern as individual machines.

// StateMachineManager::Startup(void)
// 0x800966A4 - 60 bytes
// Allocates the singleton and stores in SDA global
void StateMachineManager_Startup(void) {
    void* mem = operator_new_wrapper(16);
    *(int*)((char*)mem + 0) = 0;
    *(int*)((char*)mem + 4) = 0;
    *(int*)((char*)mem + 12) = 0;
    g_pStateMachineManager = (StateMachineManager*)mem;
}

// StateMachineManager::FindMachineById(int)
// 0x80096628 - 64 bytes
StateMachine* StateMachineManager::FindMachineById(int machineId) {
    StateMachine** iter = m_pBegin;
    StateMachine** end = m_pEnd;
    while (iter != end) {
        StateMachine* pMachine = *iter;
        if (pMachine->m_machineId == machineId) {
            return pMachine;
        }
        iter++;
    }
    return 0;
}

// StateMachineManager::FindMachine(StateMachine *)
// 0x80096668 - 60 bytes
StateMachine* StateMachineManager::FindMachine(StateMachine* pMachine) {
    StateMachine** iter = m_pBegin;
    StateMachine** end = m_pEnd;
    while (iter != end) {
        if (*iter == pMachine) return *iter;
        iter++;
    }
    return 0;
}

// StateMachineManager::UpdateMachine(float)
// 0x800967A4 - 108 bytes
// Iterates all machines and calls Update on each enabled one
// NON_MATCHING
void StateMachineManager_UpdateMachine(StateMachineManager* mgr, float dt) {
    StateMachine** iter = mgr->m_pBegin;
    StateMachine** end = mgr->m_pEnd;
    while (iter != end) {
        StateMachine* pMachine = *iter;
        if (pMachine->m_enabled) {
            pMachine->Update(dt);
        }
        iter++;
    }
}

// StateMachineManager::UpdateMachines(float) (static)
// 0x80096810 - 44 bytes
void StateMachineManager_UpdateMachines(float dt) {
    StateMachineManager* mgr = g_pStateMachineManager;
    if (mgr != 0) {
        StateMachineManager_UpdateMachine(mgr, dt);
    }
}

// StateMachineManager::DrawMachines(ERC *) (static)
// 0x80096904 - 52 bytes
void StateMachineManager_DrawMachines(ERC* pRC) {
    StateMachineManager* mgr = g_pStateMachineManager;
    if (mgr != 0) {
        mgr->DrawMachine(pRC);
    }
}

// StateMachineManager::DrawTopmostMachines(ERC *) (static)
// 0x80096938 - 52 bytes
void StateMachineManager_DrawTopmostMachines(ERC* pRC) {
    StateMachineManager* mgr = g_pStateMachineManager;
    if (mgr != 0) {
        mgr->DrawTopmostMachine(pRC);
    }
}

// ============================================================================
// TheSimsStateMachine - Master game state machine
// ============================================================================
// Extends StateMachine. Size: 0x47C (1148 bytes).
// Contains additional fields beyond the base 0x98:
//   0x98: m_pFlashUI (void*) - pointer to APT/Flash UI system
//   0x9C: m_extraField
//   ...
//   0x478: m_additionalData
//
// This machine owns all 20 game states. On Startup, it allocates and
// registers each state via AddState, then sets the initial state to
// state 0 (TheSimsNGCLicenseState) with SetNextState(0, 0.0f).
//
// The game state graph is driven by each state's Update() calling
// OwnerSetNextState() to transition to the next game phase.

// TheSimsStateMachine::TheSimsStateMachine(int, int)
// 0x8009ACC4 - 264 bytes
// NON_MATCHING - calls StateMachine base ctor, sets vtable to 0x8045E460
// The constructor passes (machineId, managerId) to StateMachine base,
// then overrides the vtable pointer to TheSimsStateMachine's vtable.

// TheSimsStateMachine::Startup(void)
// 0x80098DB4 - 2236 bytes
// NON_MATCHING - massive function that allocates all 20 states
//
// This function is the "spine" of the game. It:
//   1. Initializes various game subsystems (14 bl calls at the start)
//   2. Allocates each of the 20 states via operator new
//   3. Initializes StateMachineState base fields (stateId, prevStateId=-1, etc.)
//   4. Sets derived vtable pointer at offset 0x18
//   5. Calls AddState to register each state with this machine
//   6. For complex states (5, 13, 19), also initializes embedded sub-machines
//   7. Calls SetNextState(0, 0.0f) to begin at NGC License state
//   8. Allocates the FlashUI helper at offset 0x98
//
// State allocation order and parameters:
//   State  0: new(0x50)  -> TheSimsNGCLicenseState      vtable=0x8045E418
//   State  1: new(0x1C)  -> TheSimsMemCardCheckState     vtable=0x8045E3D0
//   State  2: new(0x20)  -> TheSimsMaxisLogoState        vtable=0x8045E388
//   State  3: new(0x34)  -> TheSimsSimsIntroMovieState   vtable=0x8045E340
//   State  4: new(0x28)  -> TheSimsEAMovieState          vtable=0x8045E2F8
//   State  5: new(0x98)  -> TheSimsStartScreenStateMachine (embedded SM)
//             First initialized as StateMachine (vtable=0x8045E100)
//             Then vtable overridden to 0x8045E0B8 (TheSimsStartScreenStateMachine)
//   State  6: new(0x20)  -> TheSimsEnterMainMenuState    vtable=0x8045E2B0
//   State  7: new(0x28)  -> TheSimsMainMenuState         vtable=0x8045E268
//   State  8: new(0x30)  -> PreGameState                 vtable=0x8045E028
//   State  9: new(0x20)  -> PreGameFreeplayState         vtable=0x8045DEC0
//   State 10: new(0x30)  -> PreGameCasPlayer1State       vtable=0x8045DFE0
//   State 11: new(0x30)  -> PreGameCasPlayer2State       vtable=0x8045DF98
//   State 12: new(0x30)  -> PreGameCreateAFamilyState    vtable=0x8045DF50
//   State 13: new(0xB4)  -> LiveModeInitState            vtable=0x8045D8D8
//             Has embedded sub-objects initialized at offsets 0x54-0x9C
//             Overrides vtable to 0x8045E188? No - see below
//   State 14: new(0x30)  -> InLevelCreateASimState       vtable=0x8045DF08
//   State 15: new(0x48)  -> MoviePlayerEndgameMovieState vtable=0x8045C980
//   State 16: new(0x1C)  -> UrbzModeNewGameState         vtable=0x8045E4A8
//   State 17: new(0x1C)  -> UrbzCreditsState             vtable=0x8045E220
//   State 18: new(0x20)  -> InLevelBaseState             vtable=0x8045D8D8
//             Actually uses LiveModeInitState vtable initially, then
//             vtable overridden to InLevelBaseState's
//   State 19: new(0x98)  -> LiveModeChangeHouseStateMachine (embedded SM)
//             Similar to state 5 - full StateMachine base, vtable override
//
//   After all states added: SetNextState(0, 0.0f) -> start at NGC License
//   Allocates FlashUI helper: new(0x8C) -> stored at this+0x98

// TheSimsStateMachine::Shutdown(void)
// 0x80099670 - 152 bytes
// Shuts down the current state, then cleans up the FlashUI at offset 0x98
// and the global game data singleton
// NON_MATCHING
void TheSimsStateMachine_Shutdown(void* self) {
    char* _this = (char*)self;

    // Shutdown the FlashUI helper at offset 0x98
    void* pFlashUI = *(void**)(_this + 0x98);
    if (pFlashUI != 0) {
        // Virtual call: Shutdown(3) via vtable
        void** vtbl = *(void***)((char*)pFlashUI + 0x80);
        short adj = *(short*)((char*)vtbl + 0x0C);
        void (*fn)(void*, int) = (void(*)(void*, int))*(void**)((char*)vtbl + 0x10);
        fn((char*)pFlashUI + adj, 3);
        *(void**)(_this + 0x98) = 0;
    }

    // ShutdownCurState on the main status
    // this->m_status.ShutdownCurState()
    // (at offset 0x3C from self)

    // Clean up global game data
    // g_pGameData at 0x80475B84 + 0x68
    void* globalData = (void*)0x80475B84;
    void* entry = *((void**)((char*)globalData + 0x68));
    if (entry != 0) {
        void** vtbl2 = *(void***)((char*)entry + 0x80);
        short adj2 = *(short*)((char*)vtbl2 + 0x0C);
        void (*fn2)(void*, int) = (void(*)(void*, int))*(void**)((char*)vtbl2 + 0x10);
        fn2((char*)entry + adj2, 3);
        *((void**)((char*)globalData + 0x68)) = 0;
    }
}

// TheSimsStateMachine::Update(float)
// 0x80099708 - 92 bytes
// Wraps StateMachine::Update with a profiler scope
// Calls BGExec_Lock/Unlock around the base Update
void TheSimsStateMachine_Update(void* self, float dt) {
    // BGExec_TryLock (0x8003C798) on global singleton at 0x80475B84
    void* bgExec = (void*)0x80475B84;
    int locked = 0; // BGExec_TryLock(bgExec);
    if (locked != 0) {
        // StateMachine::Update(dt)
        // ((StateMachine*)self)->Update(dt);
    }
    // BGExec_Unlock (0x8003CE78) on bgExec
}

// TheSimsStateMachine::Draw(ERC *)
// 0x80099764 - 120 bytes
// Wraps StateMachine::Draw with FlashUI rendering
// Sets a "drawing" flag, calls base Draw, then renders Flash UI overlay
void TheSimsStateMachine_Draw(void* self, ERC* pRC) {
    void* bgExec = (void*)0x80475B84;
    // BGExec_IsRunning(bgExec) -> 0x8003CE34
    int isRunning = 0; // placeholder
    if (isRunning != 0) {
        // Set draw flag: g_pGameData->m_bDrawing = 1
        *((int*)((char*)bgExec + 0x88)) = 1;
        // StateMachine::Draw(pRC)
        ((StateMachine*)self)->Draw(pRC);
    } else {
        // Clear draw flag
        *((int*)((char*)bgExec + 0x88)) = 0;
    }
    // Draw FlashUI overlay: BGExec_DrawOverlay(bgExec, pRC) -> 0x8003CEC4
}

// TheSimsStateMachine::IsFlowStateRequestPending(void)
// 0x800997DC - 40 bytes
// Checks if the current state has a pending flow state request.
// Called by states that need to delegate flow decisions to TheSimsStateMachine.
int TheSimsStateMachine_IsFlowStateRequestPending(void* self) {
    // Reads the current state from m_status, then calls
    // IsFlowStateRequestPending on it via vtable dispatch
    // Returns 0 or 1
    return 0; // placeholder
}

// TheSimsStateMachine::GetFlowStateRequest(void)
// 0x80099804 - 24 bytes
int TheSimsStateMachine_GetFlowStateRequest(void* self) {
    // Delegates to current state's GetFlowStateRequest via vtable
    return 0; // placeholder
}

// TheSimsStateMachine::SetFlowStateCurrent(void)
// 0x8009981C - 24 bytes
void TheSimsStateMachine_SetFlowStateCurrent(void* self) {
    // Delegates to current state's SetFlowStateCurrent via vtable
}

// ============================================================================
// TheSimsStartScreenStateMachine - Title screen state machine
// ============================================================================
// State 5 in TheSimsStateMachine. This is itself a StateMachine (inherits
// from it) that manages the "Press Start" / attract mode screen.
//
// Size: 0x98 (same as StateMachine - no additional fields beyond base)
// vtable: 0x8045E0B8
//
// Contains 1 sub-state:
//   State 0: StartScreenStartState (vtable=0x8045E070)
//
// The title screen displays the game logo and "Press Start" text.
// On button press, it transitions the parent TheSimsStateMachine to
// state 6 (TheSimsEnterMainMenuState) via IsFlowStateRequestPending.

// TheSimsStartScreenStateMachine::TheSimsStartScreenStateMachine(int, int)
// 0x80095970 - 264 bytes
// Constructs as StateMachine base, overrides vtable to 0x8045E0B8

// TheSimsStartScreenStateMachine::Startup(void)
// 0x80095780 - 164 bytes
// Allocates StartScreenVars and the single StartScreenStartState
void TheSimsStartScreenStateMachine_Startup(void* self) {
    char* _this = (char*)self;

    // Allocate and initialize StartScreenVars (56 bytes)
    void* vars = operator_new_wrapper(0x38);
    // StartScreenVars::Startup()
    // Store in SDA global g_pStartScreenVars

    // Allocate StartScreenStartState (36 bytes)
    void* state = operator_new_wrapper(0x24);
    // Initialize StateMachineState base:
    //   stateId = 0, prevStateId = -1, owner = 0, stage = -1
    //   unused10 = 0, active = 1, vtable = 0x8045E070

    // AddState(state)
    // ((StateMachine*)self)->AddState(state);

    // Initialize dataset name reference
    // aptSetupOrSomething on global singleton

    // LoadingScreenStateMachine::LoadFinishing()
    // Signal that we're done loading into the start screen
}

// TheSimsStartScreenStateMachine::Shutdown(void)
// 0x80095824 - 80 bytes
void TheSimsStartScreenStateMachine_Shutdown(void* self) {
    // Shutdown StartScreenVars
    // ShutdownCurState on status
}

// TheSimsStartScreenStateMachine::Reset(void)
// 0x80095874 - 96 bytes
void TheSimsStartScreenStateMachine_Reset(void* self) {
    // Reset StartScreenVars
    // SetNextState(0, 0.0f) to re-enter StartScreenStartState
}

// TheSimsStartScreenStateMachine::Update(float)
// 0x800958D4 - 72 bytes
// Updates StartScreenVars then delegates to StateMachine::Update
void TheSimsStartScreenStateMachine_Update(void* self, float dt) {
    // StartScreenVars::Update(dt) on global vars
    // StateMachine::Update(dt) on self
}

// ============================================================================
// LoadingScreenStateMachine - Loading screen flow controller
// ============================================================================
// Manages the fade-in -> loading -> fade-out sequence during level loads.
// Size: 0xAC (172 bytes) - extends StateMachine with loading state fields.
// vtable: 0x8045DA40
//
// Has a static singleton pointer at LoadingScreenStateMachine::s_pSM (0x804FDB80).
//
// Additional fields beyond StateMachine (0x98):
//   0x98: m_pLoadingScreen (CLoadingScreen*)
//   0x9C: m_eLoadMode (CLoadingScreen::eLoadingScreenMode)
//   0xA0: m_bIsLoading (bool/int)
//   0xA4: m_loadStage
//   0xA8: m_fadeOpacity (float)
//
// Sub-states (registered in Startup):
//   State 0: LoadingScreenWaitingForLoadState  vtable=0x8045D9F8
//   State 1: LoadingScreenFadeInState          vtable=0x8045D9B0
//   State 2: LoadingScreenUpdateState          vtable=0x8045D968
//   State 3: LoadingScreenFadeOutState         vtable=0x8045D920
//
// Loading flow:
//   Normal state: WaitingForLoad (state 0)
//   StartLoad(mode) triggers: WaitingForLoad -> FadeIn (state 1)
//   FadeIn completes:         FadeIn -> Update (state 2)
//   Load finishes:            Update -> FadeOut (state 3)
//   FadeOut completes:        FadeOut -> WaitingForLoad (state 0)
//
// The fader system controls screen opacity during transitions:
//   FaderStart(duration, fadeIn) - begins a fade
//   FaderUpdate(dt) - advances the fade
//   FaderGetFadeOpacity() - returns current opacity (0.0-1.0)

// LoadingScreenStateMachine::LoadingScreenStateMachine(int, int)
// 0x800907CC - 308 bytes
// NON_MATCHING - complex StateMachine base init + extra fields

// LoadingScreenStateMachine::Startup(void)
// 0x800909A4 - 320 bytes
// Allocates 4 sub-states and registers them, then SetNextState(0, 0.0f)
void LoadingScreenStateMachine_Startup(void* self) {
    char* _this = (char*)self;

    // State 0: LoadingScreenWaitingForLoadState (28 bytes)
    void* s0 = operator_new_wrapper(0x1C);
    // stateId=0, vtable=0x8045D9F8

    // State 1: LoadingScreenFadeInState (28 bytes)
    void* s1 = operator_new_wrapper(0x1C);
    // stateId=1, vtable=0x8045D9B0

    // State 2: LoadingScreenUpdateState (28 bytes)
    void* s2 = operator_new_wrapper(0x1C);
    // stateId=2, vtable=0x8045D968

    // State 3: LoadingScreenFadeOutState (28 bytes)
    void* s3 = operator_new_wrapper(0x1C);
    // stateId=3, vtable=0x8045D920

    // AddState for each, then SetNextState(0, delay)
    // Initial state is WaitingForLoad
}

// LoadingScreenStateMachine::Update(float)
// 0x80090AE4 - 32 bytes
// Simple wrapper that calls StateMachine::Update(dt)
void LoadingScreenStateMachine_Update(void* self, float dt) {
    // StateMachine::Update(dt)
}

// LoadingScreenStateMachine::GetSingleton(void)
// 0x80090F74 - 8 bytes
// Returns the static singleton pointer
void* LoadingScreenStateMachine_GetSingleton(void) {
    // return s_pSM; (at 0x804FDB80)
    return 0; // placeholder
}

// LoadingScreenStateMachine::StartLoad(CLoadingScreen::eLoadingScreenMode)
// 0x80090C1C - 252 bytes
// NON_MATCHING - initiates a loading sequence
// Creates the loading screen if needed, sets loading mode,
// transitions to FadeIn state
void LoadingScreenStateMachine_StartLoad_impl(void* self, int mode) {
    char* _this = (char*)self;
    // If not already loading:
    //   CreateLoadingScreen()
    //   m_eLoadMode = mode
    //   m_bIsLoading = 1
    //   SetNextState(1, 0.0f) -> FadeIn
}

// LoadingScreenStateMachine::IsLoading(void)
// 0x80090BD0 - 76 bytes
int LoadingScreenStateMachine_IsLoading_impl(void* self) {
    char* _this = (char*)self;
    return *((int*)(_this + 0xA0));
}

// LoadingScreenStateMachine::IsReadyToLoad(void)
// 0x80090BB8 - 24 bytes
int LoadingScreenStateMachine_IsReadyToLoad_impl(void* self) {
    // Returns 1 if current state is WaitingForLoad and fade is complete
    return 0; // placeholder
}

// LoadingScreenStateMachine::LoadFinishedNow(void)
// 0x80090D18 - 64 bytes
// Signals that loading is complete, triggers FadeOut
void LoadingScreenStateMachine_LoadFinishedNow(void* self) {
    char* _this = (char*)self;
    // m_bIsLoading = 0
    *((int*)(_this + 0xA0)) = 0;
    // SetNextState to FadeOut
}

// LoadingScreenStateMachine fader functions:
// FaderStart(float duration, bool fadeIn) - 0x80090E20
// FaderStop() - 0x80090E88
// FaderUpdate(float dt) - 0x80090E94
// FaderGetFadeOpacity() - 0x80090F00
// IsFadingIn() - 0x80090F7C
// IsFadedIn() - 0x80090FA4
// IsFadingOut() - 0x80090FB4
// IsFadedOut() - 0x80090FC4

// ============================================================================
// LiveModeInitState - Live mode initialization (state 13)
// ============================================================================
// This state handles the heavy lifting of loading a lot/house for live mode.
// It's one of the most complex states with a 3216-byte Update function that
// manages a multi-phase loading pipeline:
//
//   Phase 0: Start level load, request loading screen
//   Phase 1: Wait for loading screen fade-in
//   Phase 2: Load datasets (async)
//   Phase 3: Initialize house, objects, sims
//   Phase 4: Initialize lighting, camera, UI
//   Phase 5: Signal loading complete, wait for fade-out
//   Phase 6: Transition to InLevelBaseState (state 18)
//
// Size: 0xB4 (180 bytes) with embedded dataset references
// vtable: 0x8045D8D8

// LiveModeInitState::LiveModeInitState(int)
// 0x8008FEDC - 60 bytes
// Simple constructor setting stateId

// LiveModeInitState::Reset(void)
// 0x8008BC28 - 260 bytes
// Resets all loading phases to initial state

// LiveModeInitState::Update(float)
// 0x8008BD2C - 3216 bytes
// NON_MATCHING - enormous loading state machine
// This function is the "loading coordinator" that orchestrates:
//   - LoadingScreenStateMachine::StartLoad()
//   - Dataset loading via EResourceManager
//   - House/lot initialization
//   - ELiveMode::Init()
//   - Camera setup
//   - UI initialization
//   - Transition to InLevelBaseState via OwnerSetNextState(18, 0.0f)

// LiveModeInitState::Shutdown(void)
// 0x8008BC24 - 4 bytes (no-op)

// LiveModeInitState::Draw(ERC *)
// 0x8008C9BC - 4 bytes (no-op - loading screen handles drawing)

// LiveModeInitState::DatasetPendingAddRefAsync(void)
// 0x8008FF18 - 24 bytes
// Returns whether an async dataset load is pending

// LiveModeInitState::DatasetFinishAddRefAsync(void)
// 0x8008CA18 - 64 bytes
// Completes an async dataset reference

// LiveModeInitState::DatasetGetRef(void)
// 0x8008C9C0 - 88 bytes
// Gets a dataset reference for the current loading phase

// ============================================================================
// InLevelBaseState - Main gameplay state (state 18)
// ============================================================================
// The "live mode" gameplay state where sims live their lives. This is the
// state the player spends most time in. It has one of the largest Update
// functions (5204 bytes) handling:
//
//   - Sim simulation updates
//   - Build mode / buy mode toggling
//   - Camera control
//   - UI updates (HUD, menus, dialogs)
//   - Save/load requests
//   - Exit to main menu flow
//   - House change transitions
//   - In-level CAS entry
//
// Size: 0xF0 (240 bytes)
// vtable: 0x8045D6D8
//
// Key transitions from InLevelBaseState:
//   -> State 14 (InLevelCreateASimState): when entering in-level CAS
//   -> State 19 (LiveModeChangeHouseStateMachine): when changing houses
//   -> State  7 (TheSimsMainMenuState): when exiting to main menu
//
// Flow state delegation:
//   IsFlowStateRequestPending, GetFlowStateRequest, SetFlowStateCurrent
//   delegate to TheSimsStateMachine to signal high-level transitions

// InLevelBaseState::InLevelBaseState(int)
// 0x8008B5B0 - 328 bytes

// InLevelBaseState::Reset(void)
// 0x80089E94 - 28 bytes

// InLevelBaseState::Shutdown(void)
// 0x80089EB0 - 124 bytes

// InLevelBaseState::Update(float)
// 0x80089F2C - 5204 bytes
// NON_MATCHING - massive gameplay update loop
// Handles all live mode gameplay logic per frame

// InLevelBaseState::Draw(ERC *)
// 0x8008B498 - 56 bytes
// Draws the live mode scene

// InLevelBaseState::HandleExitToMainMenu(void)
// 0x8008B380 - 280 bytes
// Initiates the exit-to-main-menu sequence

// InLevelBaseState::SavePlayerInteractorState(void)
// 0x8008B4D0 - 140 bytes
// Saves the player's current interaction state before transitions

// ============================================================================
// LiveModeChangeHouseStateMachine - House change flow (state 19)
// ============================================================================
// Another embedded StateMachine (size 0x98) that manages the flow when
// the player changes houses/lots during gameplay.
// vtable: 0x8045D890
//
// Contains sub-states for:
//   - Saving current house
//   - Unloading current house
//   - Loading new house
//   - Demolishing house (if requested)

// LiveModeChangeHouseStateMachine::Startup(void)
// 0x8008D91C - 412 bytes

// LiveModeChangeHouseStateMachine::Shutdown(void)
// 0x8008DAB8 - 164 bytes

// LiveModeChangeHouseStateMachine::Reset(void)
// 0x8008DB5C - 112 bytes

// LiveModeChangeHouseStateMachine::Update(float)
// 0x8008DBCC - 32 bytes
// Simple wrapper calling StateMachine::Update(dt)

// LiveModeChangeHouseStateMachine::Draw(ERC *)
// 0x8008DBEC - 32 bytes
// Simple wrapper calling StateMachine::Draw(pRC)

// ============================================================================
// Boot sequence states (states 0-4)
// ============================================================================
// These five states form the boot sequence. Each displays its content,
// waits for completion/timeout/button press, then advances to the next.

// TheSimsNGCLicenseState (state 0) - NGC license screen
//   Startup: loads license texture, sets display timer
//   Update:  waits for timer, then OwnerSetNextState(1, 0.0f)
//   Draw:    renders license text/image

// TheSimsMemCardCheckState (state 1) - memory card detection
//   Startup: initiates memory card probe
//   Update:  checks card status, OwnerSetNextState(2, 0.0f) when done
//   Draw:    renders memory card status UI

// TheSimsMaxisLogoState (state 2) - Maxis logo
//   Startup: loads logo texture, starts fade-in
//   Update:  runs fade animation, skippable, OwnerSetNextState(3, 0.0f)
//   Draw:    renders logo with fade effect

// TheSimsSimsIntroMovieState (state 3) - intro cinematic
//   Startup: starts movie playback
//   Update:  polls movie status, skippable, OwnerSetNextState(4, 0.0f)
//   Shutdown: stops and releases movie

// TheSimsEAMovieState (state 4) - EA logo movie
//   Startup: starts EA movie playback
//   Update:  polls movie status, skippable, OwnerSetNextState(5, 0.0f)
//   Shutdown: stops and releases movie

// ============================================================================
// Menu states (states 5-7)
// ============================================================================

// TheSimsStartScreenStateMachine (state 5) - "Press Start" screen
//   See detailed section above. Transitions to state 6 on button press.

// TheSimsEnterMainMenuState (state 6) - main menu entry transition
//   Startup: begins loading main menu UI datasets
//   Update:  multi-phase loading/transition
//     Phase 0: Request loading screen
//     Phase 1: Load UI datasets
//     Phase 2: Initialize menu Flash UI
//     Phase 3: Wait for fade-out
//     Phase 4: OwnerSetNextState(7, 0.0f) -> Main Menu
//   Draw/DrawTopmost: no-op (loading screen handles it)

// TheSimsMainMenuState (state 7) - main menu
//   Startup: activates menu UI, sets up button handlers
//   Update:  processes menu input, determines next state:
//     "New Game"    -> OwnerSetNextState(8, 0.0f)  (PreGameState)
//     "Continue"    -> OwnerSetNextState(13, 0.0f) (LiveModeInit)
//     "Load Game"   -> OwnerSetNextState(13, 0.0f) (LiveModeInit)
//     "Story Mode"  -> OwnerSetNextState(16, 0.0f) (UrbzModeNewGame)
//     "Back"        -> OwnerSetNextState(5, 0.0f)  (Start Screen)
//   LeavingMainMenuCleanup: tears down menu UI before transition
//   IsFlowStateRequestPending/GetFlowStateRequest/SetFlowStateCurrent:
//     Delegates to TheSimsStateMachine for coordinated transitions

// ============================================================================
// Pre-game states (states 8-12)
// ============================================================================

// PreGameState (state 8) - new game setup coordinator
//   Update: multi-phase setup:
//     Phase 0: Initialize neighborhood selection
//     Phase 1: Create/select family
//     Phase 2: Transition to CAS states or freeplay
//     Depending on player choice:
//       -> OwnerSetNextState(10, 0.0f) - CAS Player 1
//       -> OwnerSetNextState(11, 0.0f) - CAS Player 2
//       -> OwnerSetNextState(12, 0.0f) - Create-A-Family
//       -> OwnerSetNextState(9, 0.0f)  - Freeplay
//       -> OwnerSetNextState(13, 0.0f) - Start game (LiveModeInit)

// PreGameFreeplayState (state 9) - freeplay mode lot selection
//   Startup: loads neighborhood/lot selection UI
//   Update:  handles lot selection, then OwnerSetNextState(13, 0.0f)
//   IsFlowStateRequestPending: delegates to TheSimsStateMachine

// PreGameCasPlayer1State (state 10) - Create-A-Sim for player 1
//   Reset:  initializes CAS for player 1
//   Update: monitors CAS completion
//     On complete: OwnerSetNextState(8, 0.0f) back to PreGameState
//     Or chain to: OwnerSetNextState(11, 0.0f) for player 2

// PreGameCasPlayer2State (state 11) - Create-A-Sim for player 2
//   Similar to state 10 but for second player in 2-player mode

// PreGameCreateAFamilyState (state 12) - Create-A-Family
//   Reset:  initializes family creation UI
//   Update: monitors completion, then OwnerSetNextState(8, 0.0f)

// ============================================================================
// Gameplay states (states 13, 14, 18, 19)
// ============================================================================

// LiveModeInitState (state 13) - see detailed section above
//   Transitions to state 18 (InLevelBaseState) when loading completes

// InLevelCreateASimState (state 14) - in-level CAS
//   Reset:  enters CAS mode during gameplay
//   Update: monitors CAS completion
//     On complete/cancel: returns to live mode

// InLevelBaseState (state 18) - see detailed section above
//   The main gameplay loop state

// LiveModeChangeHouseStateMachine (state 19) - see detailed section above

// ============================================================================
// Story/special states (states 15-17)
// ============================================================================

// MoviePlayerEndgameMovieState (state 15) - endgame movie
//   Plays the endgame cinematic after completing story mode

// UrbzModeNewGameState (state 16) - Urbz story mode
//   Reset:  initializes Urbz-specific story data
//   Update: massive 1956-byte function managing story mode setup
//     Eventually transitions to state 13 (LiveModeInit) for gameplay

// UrbzCreditsState (state 17) - credits roll
//   Shows credits after completing the game

// ============================================================================
// MUStateMachine - Memory Unit (save/load) state machine
// ============================================================================
// Not part of the main TheSimsStateMachine graph but runs in parallel.
// Manages all save/load/format operations on the memory card.
// Registered with StateMachineManager as a separate machine.
//
// Size: 0x108 (264 bytes) - extends StateMachine
// Contains MUWrapper for low-level memory card operations.
//
// Sub-states (from MUStates*.h headers):
//   MUStatesLoadConfig
//   MUStatesLoadGame
//   MUStatesLoadHouse
//   MUStatesSaveExistingGame
//   MUStatesSaveNewGame
//   MUStatesSlotSelectSave
//   MUStatesAutoSaveExisting
//   MUStatesAutoSaveNew
//   MUStatesFormat
//   MUStatesProcessRequests
//   MUStatesTransitionAutoSaveExisting
//   MUStatesTransitionSaveExistingGame
//
// These handle the full save/load flow:
//   Save: SlotSelect -> SaveNew/SaveExisting -> AutoSave -> ProcessRequests
//   Load: SlotSelect -> LoadGame -> LoadHouse -> ProcessRequests

// ============================================================================
// Summary of the complete game flow
// ============================================================================
//
//  BOOT:
//    [NGC License] -> [MemCard Check] -> [Maxis Logo] -> [Sims Intro] -> [EA Movie]
//
//  TITLE:
//    [Start Screen ("Press Start")]
//         |
//         v
//    [Enter Main Menu (loading transition)]
//         |
//         v
//    [Main Menu]
//
//  NEW GAME PATH:
//    [Main Menu] -> [PreGame] -> [CAS P1] -> [CAS P2] -> [Create Family]
//         |              |                                      |
//         |              +-> [Freeplay] -> [LiveModeInit] -> [InLevel]
//         |              |                                      |
//         |              +----> [LiveModeInit] -> [InLevel (Live Mode)]
//         |
//  LOAD GAME PATH:
//    [Main Menu] -> [LiveModeInit] -> [InLevel (Live Mode)]
//
//  STORY MODE PATH:
//    [Main Menu] -> [UrbzNewGame] -> [LiveModeInit] -> [InLevel]
//
//  IN-GAME TRANSITIONS:
//    [InLevel] <-> [In-Level CAS]
//    [InLevel] <-> [Change House SM]
//    [InLevel] -> [Main Menu] (exit game)
//    [InLevel] -> [Endgame Movie] -> [Credits]
//
//  PARALLEL MACHINES:
//    [MUStateMachine] - runs save/load operations
//    [LoadingScreenStateMachine] - runs fade/load visuals
//
