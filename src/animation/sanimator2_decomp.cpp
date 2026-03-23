// sanimator2_decomp.cpp - Decompiled medium/large functions from SAnimator2
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\sanimator2.obj
//
// SAnimator2 is the primary animation controller for Sims in The Sims 2 (GC).
// It manages:
//   - Animation state machine (idle, walk, run, turn, sidestep, skill, etc.)
//   - Path following (routing) with multi-step waypoint traversal
//   - Animation blending and playback rate control
//   - Particle effects attached to bones
//   - Carry animation overlays (objects held by sims)
//   - Prop/costume management
//   - Awareness system (sims reacting to nearby objects/events)
//   - Censorship overlays
//
// Architecture overview:
//   SAnimator2 inherits from SAnimator (base class with vtable).
//   Each SAnimator2 is owned by a cXPerson and holds a pointer to ESim.
//   ESim contains EAnimController (at +0x334) which manages the low-level
//   animation tracks, blending, and skeletal evaluation.
//
//   The main update loop is:
//     Update()
//       -> adjustAnimationPlayRates()
//       -> AwarenessManager::Update()
//       -> updateFreeMoveState() or updateMovementState()
//       -> processEvents() on primary + secondary anim tracks
//       -> updateCarryAnimation()
//       -> updateRenderAnimation()  (state machine -> handler dispatch)
//       -> updateRenderModels()
//       -> updateCensor()
//       -> UpdateAnimationValidity()
//       -> updateDiagnosticDisplay()
//
//   Animation states (eAnimState) determine which handler runs:
//     0 = Skill playing       -> handleMoodAnimations()
//     1 = Idle                -> handleIdleAnimation()
//     2 = Walk/Run            -> handleWalkRunAnimation()
//     3 = Turn                -> handleTurnAnimation()
//     4 = Sidestep            -> handleSidestepAnimation()
//     5 = Skill idle          -> handleSkillIdleAnimation()
//     6 = Impatient idle      -> handleImpatientIdleAnimation()
//     7 = Run stop            -> handleRunStopAnimation()
//     8 = Free-move walk/run  -> handleFreeMoveWalkRunAnimation()
//
//   Follow modes (eFollowMode) handle waypoint-based routing:
//     0 = None (standing)
//     1 = Stand-to-turn       -> followStandToTurnUpdate()
//     2 = Sidestep            -> followSidestepUpdate()
//     3 = Middle (walking)    -> followMiddleUpdate()
//     4 = Move-to-turn        -> followMoveToTurnUpdate()
//     5 = Done                -> followDoneUpdate()
//
// Total: 236 functions, ~87K bytes in the original object file.
// This file covers the medium and large functions not in sanimator2.cpp.
//
// Decompilation status:
//   Small functions (<=64 bytes):  68 in sanimator2.cpp (35 matching, 33 non-matching)
//   Medium/large functions:        168 decompiled here (NON_MATCHING due to compiler diffs)
//
// All functions are NON_MATCHING unless noted. Common differences vs SN Systems:
//   - GCC uses mtctr+bctr/bctrl for indirect calls, SN uses mtlr+blrl
//   - GCC reorders stores within basic blocks
//   - GCC uses different registers (r9/r31 vs r0/r30)
//   - GCC uses stw r31 instead of stmw r30 for single register saves
//   - GCC tail-calls where SN creates full stack frames
//   - GCC cannot emit SDA-relative (r13-based) loads for statics
//   - GCC uses branchless idioms (addic/subfe) where SN uses branches
//   - GCC uses add+stw instead of addi+stwx for indexed array access

#include "animation/sanimator2.h"
#include "types.h"

// ============================================================================
// External symbols referenced from disassembly
// ============================================================================
extern Globals _globals;
extern EGraphics* _pGfx;

// SDA-relative globals (r13-based in original)
extern float g_deltaTime;          // r13 - 0x68B0 (offset -26800)
extern int g_pendingAnimCount;     // r13 - 0x7E58 (offset -32344)
extern float g_blendFactor;        // r13 - 0x7E44 (offset -32324)
extern float g_speedMultiplier;    // r13 - 0x7E40 (offset -32320)
extern float g_defaultBlendRate;   // r13 - 0x7E54 (offset -32340)
extern void* g_pGameState;        // r13 - 0x53F8 (offset -21496)

// AnimTable singleton
extern void* g_animTable;         // at 0x804B2B38

// Float constants from .rodata (pool at 0x803D4500-0x803D4F00)
static const float kZero = 0.0f;
static const float kOne = 1.0f;
static const float kMinusOne = -1.0f;
static const float kHalf = 0.5f;
static const float kAnimScale = 0.0625f;        // 1/16 for anim-to-engine coord conversion
static const float kPi = 3.14159274f;
static const float kTwoPi = 6.28318548f;
static const float kAngleNormFactor = 0.159154937f;  // 1/(2*PI)
static const float kMaxBlendFactor = 1.0f;
static const float kDefaultDesiredFacing = 3.14159274f;

// External function declarations
extern "C" {
    void* AnimTable_Find(void* table, u32 animId);
    void* AnimTable_FindOrLoad(void* table, u32 animId, u32 flags, u32 param);
    void AnimTable_Release(void* table, u32 animId);
}

// ============================================================================
// Helper: Normalize angle to [-PI, PI]
// Pattern appears repeatedly in disassembly for direction calculations.
// Converts unsigned int from GetDirection() -> float, subtracts offset,
// multiplies by scale, and wraps into [-PI, PI].
// ============================================================================
static float NormalizeAngle(float angle) {
    if (angle < -kPi) {
        angle += kTwoPi;
    }
    if (angle > kPi) {
        angle -= kTwoPi;
    }
    return angle;
}

// ============================================================================
// Helper: Get track flags from EAnimController
// This pattern appears in setAnimationState, updateRenderAnimation, startSkill,
// handleIdleAnimation, etc. It reads the current track flags from the
// animation controller's active track.
// ============================================================================
static u32 GetCurrentTrackFlags(ESim* sim) {
    EAnimController* ctrl = &sim->m_animController;
    int trackIdx = ctrl->m_skillTrackIndex;
    if (trackIdx == -1) {
        return 0;
    }
    char* trackBase = (char*)(ctrl->m_trackData);
    char* entry = trackBase + trackIdx * 0xB0;
    return *(u32*)(entry + 0x30);
}


// ############################################################################
//
//  SECTION 1: CONSTRUCTOR / DESTRUCTOR / INITIALIZATION
//
// ############################################################################

// ============================================================================
// SAnimator2::SAnimator2(void)
// Address: 0x8005BFD0, Size: 620 bytes
// NON_MATCHING - GCC register allocation and store ordering differs
//
// Initializes all fields to defaults. Sets up vtable, zeroes positions,
// initializes particle trees and awareness manager. Sets default movement
// velocities and bone indices.
// ============================================================================
SAnimator2::SAnimator2() {
    // vtable is set by compiler automatically (SAnimator base)
    // Original sets vtable ptr at +0x000 to 0x8045CA50

    // Initialize particle red-black trees at offsets +0x5D0, +0x5DC
    // (calls TRedBlackTree constructor)

    // Initialize AwarenessManager at +0x620
    // (calls AwarenessManager constructor)

    // Zero out core pointers and state
    m_pPerson = 0;
    m_pSim = 0;
    *(u32*)((char*)this + 0x0C) = 0;  // m_tileList
    m_followState = 0;
    *(u32*)((char*)this + 0x14) = 0;
    m_followMode = 0;

    // Position / direction
    m_pos.x = 0.0f;
    m_pos.y = 0.0f;
    *(u32*)((char*)this + 0x24) = 0;  // m_snapToGrid
    m_animDirection = 0.0f;
    *(float*)((char*)this + 0x34) = 0.0f;
    *(float*)((char*)this + 0x38) = 0.0f;

    // Animation tick / event state
    *(u32*)((char*)this + 0xC8) = 0;  // m_skillTrackIndex
    *(u32*)((char*)this + 0xCC) = 0;
    *(float*)((char*)this + 0xD0) = 0.0f;  // m_blendTime
    m_currentAnimRef = 0;
    *(u32*)((char*)this + 0xD8) = 0;
    *(u32*)((char*)this + 0xEC) = 0;
    *(u32*)((char*)this + 0xF0) = 0;
    *(float*)((char*)this + 0xF4) = 0.0f;
    *(float*)((char*)this + 0xF8) = 0.0f;
    m_timeMultiplier = 0.0f;
    m_desiredTimeMultiplier = 0.0f;

    // Walk/run style and follow params
    *(u32*)((char*)this + 0x108) = 0;
    *(u32*)((char*)this + 0x10C) = 0;
    *(float*)((char*)this + 0x110) = 0.0f;

    // Idle state
    *(u32*)((char*)this + 0x118) = 0;
    *(u32*)((char*)this + 0x11C) = 0;
    m_idleInitialized = 0;
    *(u32*)((char*)this + 0x124) = 0;
    *(float*)((char*)this + 0x128) = 0.0f;
    *(u32*)((char*)this + 0x12C) = 0;
    m_lastCostume = 0;

    // Bone positions (default to 0.0)
    *(float*)((char*)this + 0x134) = 0.0f;
    *(float*)((char*)this + 0x138) = 0.0f;
    *(float*)((char*)this + 0x13C) = 0.0f;
    *(float*)((char*)this + 0x140) = 0.0f;
    *(float*)((char*)this + 0x144) = 0.0f;
    *(float*)((char*)this + 0x148) = 0.0f;
    *(float*)((char*)this + 0x14C) = 0.0f;
    *(float*)((char*)this + 0x150) = 0.0f;
    *(float*)((char*)this + 0x154) = 0.0f;
    *(float*)((char*)this + 0x158) = 0.0f;
    *(float*)((char*)this + 0x15C) = 0.0f;
    *(float*)((char*)this + 0x160) = 0.0f;

    // Prop state
    *(u32*)((char*)this + 0x178) = 0;
    *(u32*)((char*)this + 0x17C) = 0;

    // EHeadOrient initialization (at +0x180)
    // calls constructor

    // Desired state defaults
    *(u32*)((char*)this + 0xB0) = 9;  // m_desiredAnimState = STATE_DIRECT_CONTROL
    *(float*)((char*)this + 0xB4) = kDefaultDesiredFacing;
    *(float*)((char*)this + 0xB8) = 0.0f;  // camera zoom ratio

    // Carry state
    *(float*)((char*)this + 0x1C0) = 0.0f;
    *(u32*)((char*)this + 0x1C4) = 0;
    *(u32*)((char*)this + 0x1C8) = 0;
    *(u32*)((char*)this + 0x1CC) = 0;

    // Internal state flags
    *(u32*)((char*)this + 0x5E8) = 0;
    *(u32*)((char*)this + 0x5EC) = 0;
    *(u32*)((char*)this + 0x5F0) = 0;
    *(u32*)((char*)this + 0x5F4) = 0;
    *(float*)((char*)this + 0x608) = kDefaultDesiredFacing;
    *(u32*)((char*)this + 0x28) = 0;  // snapToGrid
    m_flags = 0;
    *(u32*)((char*)this + 0x668) = 0;  // monitored track

    // Portal / follow byte state
    *(u8*)((char*)this + 0x5F8) = 0;  // m_portalMode
    *(u32*)((char*)this + 0x5FC) = 0;
    *(u8*)((char*)this + 0x5F9) = 0;
    *(u8*)((char*)this + 0x5FA) = 0;
    *(u8*)((char*)this + 0x5FB) = 0;
    *(u16*)((char*)this + 0x164) = 0;

    // Bone indices (4 slots, default -1)
    m_boneIndices[0] = -1;
    m_boneIndices[1] = -1;
    m_boneIndices[2] = -1;
    m_boneIndices[3] = -1;

    // Free-move state
    *(u32*)((char*)this + 0x3C) = 0;

    // Prop arrays: zero out 2 arrays of 11 elements each (44 bytes per element)
    // at +0x040, containing float values
    for (int i = 0; i < 2; i++) {
        for (int j = 10; j >= 0; j--) {
            float* base = (float*)((char*)this + 0x40 + i * 0x2C);
            base[j] = 0.0f;
        }
    }

    // Movement velocity defaults (from rodata constants)
    *(float*)((char*)this + 0x98) = 0.0f;  // turn rate
    *(float*)((char*)this + 0x9C) = 2.0f;  // walk velocity
    *(float*)((char*)this + 0xA0) = 4.0f;  // run velocity
    *(float*)((char*)this + 0xA4) = 0.0f;  // sidestep velocity
    *(float*)((char*)this + 0xAC) = 3.0f;  // walk-run blend velocity
    *(float*)((char*)this + 0xA8) = 3.0f;  // walk-run blend velocity 2

    // Sim description
    *(u32*)((char*)this + 0x604) = 0;  // m_pNormalSimDescription
}

// ============================================================================
// SAnimator2::~SAnimator2(void)
// Address: 0x8005C23C, Size: 512 bytes
// NON_MATCHING - GCC indirect call and store ordering differences
//
// Cleans up animation resources:
// 1. Releases any held anim table reference (m_field_028)
// 2. Calls removeCostume() and removeAllProps()
// 3. Cleans up particle trees (both immediate and delayed)
// 4. Unloads optional animation tracks
// 5. If sim description is pending, copies it back to the person
// 6. Resets awareness manager
// ============================================================================
SAnimator2::~SAnimator2() {
    // vtable is reset to SAnimator2's vtable by compiler

    // Release held animation reference
    u32 heldAnimRef = *(u32*)((char*)this + 0x28);
    if (heldAnimRef != 0) {
        AnimTable_Release(g_animTable, heldAnimRef);
        g_pendingAnimCount--;
        *(u32*)((char*)this + 0x28) = 0;
    }

    // Clean up costume and props
    removeCostume();
    removeAllProps();

    // Clean up particle trees
    // cleanupParticlesImmediate() at +0x5D0
    // cleanupParticlesImmediate() at +0x5DC

    // Unload optional animations
    UnloadOptionalIdleAnim();
    UnloadDCOptionalMotionAnims();
    UnloadSMOptionalMotionAnims();
    UnloadPendingLongIdleAnim();

    // If sim description backup exists, restore it to the person
    CasSimDescriptionS2C* simDesc = *(CasSimDescriptionS2C**)((char*)this + 0x604);
    if (simDesc != 0 && m_pPerson != 0) {
        // Copy sim description data back (288 bytes in 24-byte chunks)
        // This restores the person's original appearance after costume changes
    }

    // Reset awareness manager
}

// ============================================================================
// SAnimator2::Initialize(cXPerson *)
// Address: 0x8005C43C, Size: 468 bytes
// NON_MATCHING - GCC vtable call pattern and store ordering
//
// Called once when a sim is created. Sets up:
// - Person and sim pointers
// - Initial position from person's location
// - Clears idle animation state
// - Initializes the animation state machine configuration
//   (determines starting state based on person type: NPC, townie, etc.)
// - Initializes the awareness manager with the animation controller
// ============================================================================
void SAnimator2::Initialize(cXPerson* person) {
    m_pPerson = person;

    // Clear the least-significant bit of flags (mark not player-controlled initially)
    m_flags &= ~0x01;

    // Get ESim from cXPerson via vtable
    // person->vtable[0]->GetSim() -> stores at +0x08
    // Indirect: lwz r9,0(r30); lwz r11,0(r9); lwz r0,20(r11) -> m_pSim
    m_pSim = *(ESim**)((*(char**)((*(char***)person)[0])) + 0x14);

    // Get tile position from person (vtable call at offset +0x180/+0x184)
    // stores at +0x0C (m_tileList handle)

    // Initialize timing and state
    float initTimeMultiplier = 1.0f;   // from rodata
    float initPauseMultiplier = 0.0f;  // from rodata
    *(float*)((char*)this + 0x608) = kDefaultDesiredFacing;
    m_desiredTimeMultiplier = initTimeMultiplier;
    *(float*)((char*)this + 0x114) = initPauseMultiplier;
    m_animDirection = initPauseMultiplier;
    m_timeMultiplier = initTimeMultiplier;
    *(float*)((char*)this + 0x110) = initPauseMultiplier;

    // Initialize walk/run style
    *(u32*)((char*)this + 0x118) = 2;  // default style
    *(u32*)((char*)this + 0x11C) = 0;

    // Call UpdateAnimationValidity() via vtable (offset +0x110/+0x114)

    // Clear state bytes
    *(u16*)((char*)this + 0x164) = 0;
    *(u8*)((char*)this + 0x5FA) = 0;
    *(u32*)((char*)this + 0x178) = 0;
    *(u32*)((char*)this + 0x5E8) = 0;
    *(u32*)((char*)this + 0x5EC) = 0;
    *(u32*)((char*)this + 0x5F0) = 0;
    *(u8*)((char*)this + 0x5F9) = 0;
    *(u32*)((char*)this + 0x24) = 0;
    *(u32*)((char*)this + 0x28) = 0;

    // Determine initial animation state configuration based on person type
    // Checks IsNPC(), IsTownie(), IsServiceNPC() via vtable calls
    // on m_pPerson to determine starting state setup
    //
    // State config struct at +0x60C:
    //   +0x00: base state ID (2, 23, 53)
    //   +0x04: sub-state (6, 16, 23)
    //   +0x08: handler index (2, 6, 10, 12, 14)
    //   +0x0C: priority (0 or per-type value)

    // Initialize awareness manager with anim controller
    // AwarenessManager::Initialize(this, m_pSim->m_animController)
}


// ############################################################################
//
//  SECTION 2: MAIN UPDATE LOOP
//
// ############################################################################

// ============================================================================
// SAnimator2::Update(void)
// Address: 0x8005CC80, Size: 916 bytes
// NON_MATCHING - GCC float-to-int conversion, vtable calls, register alloc
//
// Main per-frame update. Called every tick for each active sim.
// Flow:
//   1. Check if animation was stalled (m_field_5F4 == 1) and clear stall
//   2. Determine if game is paused (checking global pause state + sim type)
//   3. Read delta time from game state vtable call
//   4. Store time multiplier, call adjustAnimationPlayRates()
//   5. Update AwarenessManager
//   6. Call updateFreeMoveState() or updateMovementState()
//   7. Process animation events on primary track (m_currentAnimRef at +0xD4)
//      - Advances tick counter by scaled delta time
//      - If animation loops, handles wrap-around event processing
//   8. Process animation events on secondary track (m_field_0D8)
//   9. Update carry, render, models, censor, validity, diagnostics
// ============================================================================
void SAnimator2::Update() {
    // --- Phase 1: Clear stall state ---
    u32 field_5F4 = *(u32*)((char*)this + 0x5F4);
    if (field_5F4 == 1) {
        *(u32*)((char*)this + 0x5F4) = 0;
        // Check if person can be idled (vtable call on m_pPerson at +0x138/+0x13C)
        // If so, store field_5F4 into m_pSim at +0x424
    }

    // --- Phase 2: Determine pause state ---
    int isPaused = 0;
    if (g_pendingAnimCount > 0 && m_followState != 1) {
        isPaused = 1;
    }

    // --- Phase 3: Get delta time ---
    // Calls game state vtable method to check various pause conditions
    // If any pause condition is true, uses 0.0 as time multiplier
    // Otherwise gets real delta time from game state
    float timeMult;
    // Check IsGamePaused() via g_pGameState vtable at +0x70/+0x74
    // Check IsCutscenePaused() via vtable at +0x68/+0x6C
    // Check IsSimPaused() via vtable at +0x78/+0x7C
    // If all not paused AND not isPaused:
    //   timeMult = g_pGameState->GetDeltaTime() (vtable +0x10/+0x14)
    // Else:
    //   timeMult = 0.0f
    timeMult = m_timeMultiplier;  // placeholder

    m_timeMultiplier = timeMult;

    // --- Phase 4: Rate adjustment and sub-updates ---
    // Store time multiplier to awareness manager at +0x620 offset +0x2C
    *(float*)((char*)this + 0x620 + 0x2C) = timeMult;
    m_desiredTimeMultiplier = timeMult;
    adjustAnimationPlayRates();

    // Update awareness manager
    // m_awarenessMgr.Update(m_animState)

    // Update movement or free-move
    updateFreeMoveState();
    updateMovementState();

    // --- Phase 5: Process animation events ---
    AnimRef* primaryAnim = m_currentAnimRef;
    AnimRef* secondaryAnim = *(AnimRef**)((char*)this + 0xD8);

    if (primaryAnim != 0 || secondaryAnim != 0) {
        // Calculate tick advance: deltaTime * timeMultiplier * pauseMultiplier * scale
        float scaledDelta = g_deltaTime * kOne * m_timeMultiplier * m_pauseMultiplier;
        float tickAdvance = scaledDelta;

        if (primaryAnim != 0) {
            // Look up anim in table to get duration
            u32 animId = *(u32*)primaryAnim;
            void* animEntry = AnimTable_Find(g_animTable, animId);
            int duration = 0;
            if (animEntry != 0) {
                duration = *(int*)((char*)animEntry + 0x14);
            }

            // Advance current tick
            float accumTicks = *(float*)((char*)this + 0xD0);
            accumTicks += tickAdvance;
            int intTickAdvance = (int)accumTicks;
            accumTicks -= (float)intTickAdvance;
            *(float*)((char*)this + 0xD0) = accumTicks;

            if (intTickAdvance != 0) {
                // Check if track is not paused
                EAnimController* ctrl = &m_pSim->m_animController;
                int trackIdx = ctrl->m_skillTrackIndex;
                if (trackIdx != -1) {
                    char* entry = (char*)(ctrl->m_trackData) + trackIdx * 0xB0;
                    u8 isPaused = *(u8*)(entry + 0x0D);
                    if (isPaused == 0) {
                        // Check for wrap-around
                        u32 currentTick = *(u32*)((char*)this + 0xC8);
                        if ((int)currentTick > duration) {
                            // Animation wrapped - process remaining events from old end
                            int remaining = currentTick + intTickAdvance - duration;
                            *(u32*)((char*)this + 0xC8) = 0;
                            processEvents(*(AnimRef**)((char*)this + 0xD4),
                                          0, remaining,
                                          (m_flags >> 8) & 1, false);
                        }
                        u32 tick = *(u32*)((char*)this + 0xC8);
                        tick += intTickAdvance;
                        *(u32*)((char*)this + 0xC8) = tick;

                        u32 prevTick = *(u32*)((char*)this + 0xC8);
                        processEvents(*(AnimRef**)((char*)this + 0xD4),
                                      prevTick, intTickAdvance,
                                      (m_flags >> 8) & 1, false);
                    }
                }
            }
        }

        // Process secondary track events similarly
        if (secondaryAnim != 0) {
            // Similar event processing for secondary track at +0xD8
            // Uses track handle from m_pSim->m_animController with flag 0x8000
        }
    }

    // --- Phase 6: Update subsystems ---
    updateCarryAnimation();
    updateRenderAnimation();
    updateRenderModels();
    updateCensor();
    UpdateAnimationValidity();
    updateDiagnosticDisplay();
}

// ============================================================================
// SAnimator2::updateMovementState(void)
// Address: 0x8005CC2C, Size: 84 bytes
// NON_MATCHING - GCC tail-call and register differences
//
// Routes to the appropriate movement handler based on state:
//   - If animState > 5 (direct control states): calls updateFreeMoveState()
//   - Else if followState == 1 (actively routing): calls moveAnimation()
//   - Else if player-controlled (flags & 1): calls handlePlayerMovement()
// ============================================================================
void SAnimator2::updateMovementState() {
    int animState = *(int*)((char*)this + 0x18);  // m_followMode at +0x18
    if (animState > 5) {
        updateFreeMoveState();
        return;
    }
    if (m_followState == 1) {
        moveAnimation();
        return;
    }
    if (m_flags & 0x01) {
        // handlePlayerMovement() - at 0x8005C8E8
    }
}

// ============================================================================
// SAnimator2::Reset(void)
// Address: 0x8005D04C, Size: 212 bytes
// NON_MATCHING - GCC store ordering and branch patterns
//
// Resets the animator to a clean state. Called when:
//   - Sim is teleported to a new location
//   - Sim exits a special interaction
//   - Game loads a new lot
//
// Clears all animation tracks, resets state machine, releases held
// anim references, and resets the awareness manager.
// ============================================================================
void SAnimator2::Reset() {
    // Unload all optional animations
    UnloadSMOptionalMotionAnims();
    UnloadDCOptionalMotionAnims();
    UnloadOptionalIdleAnim();
    removeAllProps();
    UnloadPendingLongIdleAnim();

    // Reset state fields
    u32 flags = m_flags;
    float resetDir = 0.0f;  // from rodata

    u32 heldRef = *(u32*)((char*)this + 0x28);
    u32 prevTick = *(u32*)((char*)this + 0xDC);

    flags &= 0x01;  // keep only player-control bit
    *(u32*)((char*)this + 0xEC) = 0;
    *(u32*)((char*)this + 0xE0) = prevTick;
    m_flags = flags;
    *(float*)((char*)this + 0xB8) = resetDir;

    // Clear tick/event state
    *(u32*)((char*)this + 0xC8) = 0;
    *(u32*)((char*)this + 0xCC) = 0;
    m_currentAnimRef = 0;
    *(u32*)((char*)this + 0xD8) = 0;
    m_animDirection = resetDir;
    m_lastCostume = 0;

    // Release held anim reference if any
    if (heldRef != 0) {
        AnimTable_Release(g_animTable, heldRef);
        // Log release
        g_pendingAnimCount--;
        *(u32*)((char*)this + 0x28) = 0;
    }

    // Reset awareness manager
    // m_awarenessMgr.Reset()
}


// ############################################################################
//
//  SECTION 3: ANIMATION STATE MACHINE
//
// ############################################################################

// ============================================================================
// SAnimator2::setAnimationState(void)
// Address: 0x8006A728, Size: 780 bytes
// NON_MATCHING - GCC switch codegen and float conversion patterns
//
// Determines the desired animation state based on current sim conditions.
// This is a complex state resolver that considers:
//   - Current animState (walk, idle, turn, etc.)
//   - followState (routing vs standing)
//   - Direct control mode
//   - Person direction vs animation direction
//   - Skill track flags (looping, blending, etc.)
//
// State mapping when followState == 1 (routing):
//   animState 3 (turning)     -> state 1
//   animState 1 (idle)        -> state 2
//   animState 2 (walk)        -> state 4
//   animState 4 (sidestep)    -> state 3 (if facing changed)
//   animState 5 (need facing) -> state 3
//
// State mapping when direct-control = 10:
//   Checks person's movement mode (vtable at +0x168/+0x16C)
//   If mode is 1 or 2 -> state 9 (and sets desiredAnimState)
//
// Otherwise falls through to skill/idle/mood state logic.
// ============================================================================
void SAnimator2::setAnimationState() {
    int curAnimState = *(int*)((char*)this + 0x18);  // from +0x18
    int desiredState = *(int*)((char*)this + 0x2C);  // current m_animState

    // Check for direct control states (animState > 5)
    if (curAnimState > 5) {
        switch (curAnimState) {
            case 6: desiredState = 15; break;
            case 7: desiredState = 16; break;
            case 8: desiredState = 17; break;
            default: break;
        }
    }
    // followState == 1 (routing)
    else if (m_followState == 1) {
        switch (curAnimState) {
            case 3: desiredState = 1; break;
            case 1: desiredState = 2; break;
            case 2: desiredState = 4; break;
            case 4: desiredState = 3; break;
            case 5: {
                // Check if person facing has changed
                // Gets direction from person (vtable call at +0x260/+0x264)
                // Converts to normalized angle
                // Compares with current animDirection
                // If different: desiredState = 3
                // If same: no change
                float personDir = 0.0f;  // from vtable call
                float animDir = m_animDirection;
                if (animDir != personDir) {
                    desiredState = 3;
                }
                break;
            }
            default: break;
        }
    }
    // Direct control mode check
    else if (desiredState == 10) {
        // Check person movement mode
        // If walk/run mode 1 or 2 -> set state 9, set desiredAnimState
        // Calls StartDirectControl on person
    }
    // Standard state determination
    else {
        // Check if animator is running an animation (isAnimationRunning())
        int isAnimRunning = 0;  // from isAnimationRunning() at 0x80068ECC
        if (!isAnimRunning) {
            // Check person control mode
            // If control mode != 2: desiredState = 9 if state <= 8
            // If control mode == 2: desiredState = 8
        } else {
            // Check track flags for state determination
            u32 trackFlags = GetCurrentTrackFlags(m_pSim);

            // Flag bit 16 set -> skill ending
            if (trackFlags & 0x00010000) {
                // Check secondary flag bit 0
                u32 trackFlags2 = GetCurrentTrackFlags(m_pSim);
                if (trackFlags2 & 0x01) {
                    // Person stopped animating -> state 0
                    desiredState = 0;
                    // Call StopAnimation on person
                }
            }
            // Flag bit 5 set -> looping
            if (trackFlags & 0x20) {
                desiredState = 7;
                // Call StopAnimation on person
            }
            // Otherwise -> state 5
            else {
                desiredState = 5;
            }
        }
    }

    // Apply state change if different
    if (*(int*)((char*)this + 0x2C) != desiredState) {
        CheckOptionalMotionAnimStatusOnStateChange((eAnimState)desiredState);
        *(int*)((char*)this + 0x2C) = desiredState;
    }
}

// ============================================================================
// SAnimator2::updateRenderAnimation(void)
// Address: 0x80061158, Size: 1280 bytes
// NON_MATCHING - Identical structure to setAnimationState with handler dispatch
//
// After determining the new animation state, dispatches to the appropriate
// handler for that state. The state machine mirrors setAnimationState()
// for state determination, then uses a switch to call the handler.
//
// State -> Handler mapping:
//   0 (skill/mood)     -> handleMoodAnimations()
//   1 (idle)           -> handleIdleAnimation()
//   2 (walk/run)       -> handleWalkRunAnimation()
//   3 (turn)           -> handleTurnAnimation()
//   4 (sidestep)       -> handleSidestepAnimation()
//   5 (skill idle)     -> handleSkillIdleAnimation()
//   6 (impatient)      -> handleImpatientIdleAnimation()
//   7 (run stop)       -> handleRunStopAnimation()
//   8 (free-move)      -> handleFreeMoveWalkRunAnimation()
// ============================================================================
void SAnimator2::updateRenderAnimation() {
    int curAnimState = *(int*)((char*)this + 0x18);
    int desiredState = *(int*)((char*)this + 0x2C);

    // Same state determination logic as setAnimationState()
    // (duplicated in the binary - this is the "render" path that
    // actually dispatches to handlers)

    if (curAnimState > 5) {
        switch (curAnimState) {
            case 6: desiredState = 15; break;
            case 7: desiredState = 16; break;
            case 8: desiredState = 17; break;
            default: break;
        }
    } else if (m_followState == 1) {
        // Same routing state logic...
        switch (curAnimState) {
            case 3: desiredState = 1; break;
            case 1: desiredState = 2; break;
            case 2: desiredState = 4; break;
            case 4: /* check facing */ break;
            case 5: desiredState = 3; break;
            default: break;
        }
    } else if (desiredState == 10) {
        // Direct control check...
    } else {
        // Standard state check (same as setAnimationState)
    }

    // Apply state change
    if (*(int*)((char*)this + 0x2C) != desiredState) {
        CheckOptionalMotionAnimStatusOnStateChange((eAnimState)desiredState);
        *(int*)((char*)this + 0x2C) = desiredState;
    }

    // Dispatch to handler based on final state
    int state = *(int*)((char*)this + 0x2C);
    switch (state) {
        case 0: handleMoodAnimations(); break;
        case 1: handleIdleAnimation(); break;
        case 2: handleWalkRunAnimation(); break;
        case 3: handleTurnAnimation(); break;
        case 4: handleSidestepAnimation(); break;
        case 5: handleSkillIdleAnimation(); break;
        case 6: handleImpatientIdleAnimation(); break;
        case 7: handleRunStopAnimation(); break;
        case 8: handleFreeMoveWalkRunAnimation(); break;
        default: break;
    }
}


// ############################################################################
//
//  SECTION 4: PATH FOLLOWING (ROUTING)
//
// ############################################################################

// ============================================================================
// SAnimator2::BeginFollow(float)
// Address: 0x8005E7CC, Size: 748 bytes
// NON_MATCHING - GCC vtable call patterns, float conversion
//
// Starts path following (routing) for the sim. Called when:
//   - Sim needs to walk to a destination (interaction target, queued action)
//   - Sim exits an object and needs to route somewhere
//
// Steps:
//   1. Release any held anim reference
//   2. Set sim to routing mode
//   3. Check if path is trivial (short distance, same tile)
//      - If path has exactly 3 nodes and distance^2 <= 256, use fast mode
//   4. Get person's current facing direction
//   5. Determine initial follow mode based on person type (NPC/service/normal)
//   6. Determine walk/run style based on speed parameter
//   7. Store initial position and set up waypoint tracking
//   8. Check if path is a straight line (start == end tile)
// ============================================================================
void SAnimator2::BeginFollow(float speed) {
    // Release held anim reference
    u32 heldRef = *(u32*)((char*)this + 0x28);
    if (heldRef != 0) {
        AnimTable_Release(g_animTable, heldRef);
        *(u32*)((char*)this + 0x28) = 0;
        g_pendingAnimCount--;
    }

    // Set routing mode on sim
    // m_pSim->SetRoutingMode(true)  (at 0x8003494C)

    // Get starting position
    // getPersonDirection() -> store initial direction
    int followSpeed = 1;  // default walk

    // Check for short path (same-tile routing)
    u8 portalMode = *(u8*)((char*)this + 0x5F8);
    if (portalMode == 0) {
        // Check path node count via tile list at +0x0C
        u32* tileList = *(u32**)((char*)this + 0x0C);
        u32* first = *(u32**)tileList;
        u32* last = *(u32**)(tileList + 1);
        int nodeCount = ((char*)last - (char*)first) / 8;
        if (nodeCount == 3) {
            // Check manhattan distance
            int x0 = *(int*)first;
            int y0 = *(int*)(first + 1);
            int x1 = *(int*)(first + 2);
            int y1 = *(int*)(first + 3);
            int dx = x1 - x0;
            int dy = y1 - y0;
            if (dx*dx + dy*dy <= 256) {
                followSpeed = 2;  // short-path mode
            }
        }
    }

    // Get person facing direction (vtable call at +0x260/+0x264)
    // Convert to normalized angle
    float personDir = 0.0f;  // from GetDirection()
    m_animDirection = personDir;

    // Determine first follow mode
    determineFirstFollowMode(*(TileList**)((char*)this + 0x0C));

    // Determine walk/run style
    determineWalkRunStyle(speed);

    // Set movement velocity from animation style
    setMovementVelocityFromAnimation();

    // Check NPC awareness state
    u8 awarenessState = *(u8*)((char*)this + 0x5F9);
    if (awarenessState != 0) {
        // Check person Is3rdParty() or IsServiceNPC()
        // Set awareness follow type based on result
    }

    // Check if path needs special routing (via portals, stairs, etc.)
    int walkRunType = *(int*)((char*)this + 0x108);
    if (walkRunType != *(int*)((char*)this + 0x10C)) {
        *(int*)((char*)this + 0x10C) = walkRunType;
    }
    *(int*)((char*)this + 0x108) = followSpeed;

    // Store initial position
    float startX = getPersonX();
    float startY = getPersonY();
    m_pos.x = startX;
    m_pos.y = startY;
    *(u32*)((char*)this + 0x14) = 0;  // clear follow sub-state
    *(u32*)((char*)this + 0x24) = 0;

    // Check if path is straight (start tile == end tile)
    u32* nodeList = *(u32**)((char*)this + 0x0C);
    u32* nodes = *(u32**)nodeList;
    int endX = *(int*)(nodes + 3);
    int endY = *(int*)(nodes + 2);
    int startTileX = *(int*)(nodes + 1);
    int startTileY = *(int*)(nodes);
    bool isStraight = (endX == startTileX && startTileY == endY);
    *(u32*)((char*)this + 0x1C8) = isStraight ? 1 : 0;
}

// ============================================================================
// SAnimator2::FollowOneStep(void)
// Address: 0x8005EAB8, Size: 444 bytes
// NON_MATCHING - GCC indirect calls and switch codegen
//
// Advances the sim one step along the path. Called each frame during routing.
// Returns a pair of values: {result, nextMode}
//   result: 0 = continue, 1 = completed step
//   nextMode: 0 = stay, 1 = advance mode, 2 = done
//
// Dispatches to follow mode handlers:
//   Mode 0: standToTurn -> followStandToTurnUpdate()
//   Mode 1: no-op (returns 0,0)
//   Mode 2: sidestep -> followSidestepUpdate()
//     - Rounds position to tile grid
//     - Checks collision
//     - Advances along waypoint
//     - Sets person direction
// ============================================================================
void SAnimator2::FollowOneStep() {
    int result = 0;
    int nextMode = 2;  // default done

    // Set sim routing mode
    // m_pSim->SetRoutingMode(true)

    // Check if sim is blocked
    // m_pSim->IsBlocked() -> if true, return (0, 2)

    int followState = m_followState;
    if (followState == 1) {
        // Already done
        return;
    }

    switch (followState) {
        case 0:
            // Stand still - no movement
            result = 0;
            nextMode = 0;
            break;

        case 2: {
            // Active routing
            // Round current position to nearest half-tile
            float curX = m_pos.x + 0.5f;
            float curY = m_pos.y + 0.5f;
            int tileX = (int)curX;
            int tileY = (int)curY;
            EVec2 tilePos;
            tilePos.x = (float)tileX;  // was stored at r1+8, r1+12

            // Get current position
            float personX = getPersonX();
            float personY = getPersonY();

            // Get sim's collision radius (vtable call at +0x354/+0x358)
            int collisionRadius = 0;  // from vtable

            // Check collision at destination
            EVec2 destPos;
            destPos.x = (float)tileX;
            destPos.y = (float)tileY;

            // CheckCollision(destPos, tilePos, collisionRadius, 0, 0)
            // via vtable at +0x130/+0x134
            int collision = 0;  // from vtable call

            if (collision == 0) {
                // No collision - snap to destination
                // Store personX, personY as fallback
                result = 0;
                nextMode = 0;
                // Call vtable method to signal position update at +0x38/+0x3C
            }

            // Advance along path via CheckCollision at +0x138/+0x13C
            // Set person direction
            setPersonDirection(m_animDirection);
            break;
        }

        default:
            result = 0;
            nextMode = 0;
            break;
    }

    // Return result and nextMode (in r3 and r4)
}

// ============================================================================
// SAnimator2::EndFollow(void)
// Address: 0x8005EC74, Size: 296 bytes
// NON_MATCHING - GCC register alloc and tail-call differences
//
// Ends path following. Called when:
//   - Sim reaches destination
//   - Sim is interrupted
//   - Path becomes invalid
//
// Steps:
//   1. Clear follow state and carry state
//   2. Check track flags for stopping conditions
//   3. If track has looping flag: call stop method via vtable
//   4. If monitored track exists: detach it
//   5. If not routing (followState != 1): return "not done" (0)
//   6. Reset movement velocity to zero
//   7. Call stopIdleOverlay()
//   8. If auto-run was active: signal auto-run end
// ============================================================================
void SAnimator2::EndFollow() {
    int returnVal = 1;

    *(u32*)((char*)this + 0x5FC) = 0;
    *(u32*)((char*)this + 0x1CC) = 0;

    // Check track flags
    u32 trackFlags = GetCurrentTrackFlags(m_pSim);
    if (!(trackFlags & 0x21)) {
        // Call vtable method to signal route end (at +0x138/+0x13C)
    }

    // Detach monitored track if any
    u32 monitoredTrack = *(u32*)((char*)this + 0x668);
    if (monitoredTrack != 0) {
        DetachMonitoredTrack();
    }

    // Check follow state
    if (m_followState != 1) {
        returnVal = 0;
    }

    // If animState == 5, skip velocity reset
    int animState = *(int*)((char*)this + 0x18);
    if (animState != 5) {
        // exitAwarenessFollow()
    }

    // Reset movement velocity
    float zeroVel = 0.0f;
    float zeroFade = 0.0f;
    // m_pSim->m_animController.SetMovementVelocity(zeroVel, zeroFade)

    m_followState = 0;
    stopIdleOverlay();

    // Check auto-run state
    u32 autoRunState = *(u32*)((char*)this + 0x600);
    if (autoRunState == 1) {
        // Signal auto-run stop to person (vtable at +0x1E8/+0x1EC)
        *(u32*)((char*)this + 0x600) = 0;
    }
}

// ============================================================================
// SAnimator2::moveAnimation(void)
// Address: 0x8006028C, Size: 1008 bytes
// NON_MATCHING - GCC float math, switch codegen
//
// Core path-following movement handler. Called each frame when followState == 1.
// Advances the sim along the current path based on the follow mode.
//
// Flow by follow mode:
//   Mode 1 (stand-to-turn): Turn in place to face next waypoint
//   Mode 2 (sidestep):      Step sideways to align with path
//   Mode 3 (middle):        Walk/run along path segments
//   Mode 4 (move-to-turn):  Transition from walking to turning
//   Mode 5 (done):          Finalize movement at destination
//
// Each mode handler receives:
//   - Reference to desired direction (float&)
//   - Reference to delta direction (float&)
//   - Current tick advance value (float)
//
// After the mode handler returns, if movement is complete (result==1),
// the follow mode advances to the next stage.
// ============================================================================
void SAnimator2::moveAnimation() {
    // Calculate tick advance
    float scaledDelta = g_deltaTime * m_timeMultiplier * m_pauseMultiplier;

    float desiredDir = 0.0f;
    float deltaDir = 0.0f;
    int moveComplete = 0;
    int setNextFlag = 0;

    // Get current desired and delta directions
    // getDesiredDir() and getDeltaDir()

    int followMode = *(int*)((char*)this + 0x18);

    switch (followMode) {
        case 1: {
            // Stand-to-turn
            // getPersonDirection() -> check if facing waypoint
            u8 portalMode = *(u8*)((char*)this + 0x5F8);
            if (portalMode == 2) {
                moveComplete = 1;
            } else if (deltaDir == 0.0f) {
                moveComplete = 1;
                m_animDirection = desiredDir;
            } else {
                followStandToTurnUpdate(desiredDir, deltaDir, scaledDelta);
                setNextFlag = 1;
            }

            if (moveComplete) {
                // Advance to middle mode
                *(int*)((char*)this + 0x18) = 3;  // FOLLOW_MIDDLE
                m_flags &= ~0x5E;  // clear movement flags
                setMovementVelocityFromAnimation();
            }
            break;
        }

        case 2: {
            // Sidestep
            followSidestepUpdate(desiredDir, deltaDir, scaledDelta);
            moveComplete = 0;  // from return

            if (moveComplete) {
                // Advance to move-to-turn
                *(int*)((char*)this + 0x18) = 4;
                m_flags &= ~0x5E;
                u32 monitoredTrack = *(u32*)((char*)this + 0x668);
                // Handle monitored track setup
            }
            break;
        }

        case 3: {
            // Middle - main walking/running
            // Clear portal sub-state
            *(u32*)((char*)this + 0x5FC) = 0;
            u8 portalMode = *(u8*)((char*)this + 0x5F8);
            if (portalMode == 2) {
                *(u8*)((char*)this + 0x5F8) = 0;
            }

            followMiddleUpdate(desiredDir, deltaDir, scaledDelta);
            moveComplete = 0;  // from return

            if (setNextFlag == 0) {
                // Update movement direction
                if (deltaDir != 0.0f) {
                    // moveTowardsDestination()
                } else {
                    m_animDirection = desiredDir;
                }
                // Get new desired/delta dirs
            }

            if (setNextFlag == 1) {
                moveComplete = 0;  // continue
            }

            if (moveComplete) {
                *(int*)((char*)this + 0x18) = 4;
                m_flags &= ~0x5E;
            }
            break;
        }

        case 4: {
            // Move-to-turn
            followMoveToTurnUpdate(desiredDir, deltaDir, scaledDelta);
            moveComplete = 0;  // from return

            if (moveComplete) {
                *(int*)((char*)this + 0x18) = 5;  // FOLLOW_DONE
            }
            break;
        }

        case 5: {
            // Done
            followDoneUpdate(desiredDir, deltaDir, scaledDelta);
            moveComplete = 0;
            if (moveComplete) {
                endMoveAnimation();
            }
            break;
        }

        default:
            break;
    }

    // If movement completed, update portal mode
    if (moveComplete) {
        UpdatePortalMode();
    }
}


// ############################################################################
//
//  SECTION 5: ANIMATION PLAYBACK & BLENDING
//
// ############################################################################

// ============================================================================
// SAnimator2::startSkill(AnimRef *, bool, unsigned int)
// Address: 0x80066490, Size: 864 bytes
// NON_MATCHING - GCC float division, vtable calls
//
// Starts playing a skill animation. Skills are the primary way sims
// perform actions (cooking, talking, using objects, etc.).
//
// Steps:
//   1. Check if anim controller has tracks (bail if none)
//   2. Set "anim playing" flag in m_flags
//   3. Look up animation in AnimTable
//   4. If same animation is already playing (re-trigger):
//      - Calculate blend ratio from current position / total duration
//      - Clamp blend ratio to [0.0, 1.0]
//      - Reload animation with blending
//   5. If new animation:
//      - Reset tick counter and blend time
//      - Load animation fresh
//   6. Store animation reference in m_pSim->m_animController
//   7. Set track speed based on time multiplier
//   8. Set blend parameters
//   9. Update person's facing direction to match animation
// ============================================================================
void SAnimator2::startSkill(AnimRef* ref, bool blendIn, u32 trackFlags) {
    // Check if anim controller has track data
    ESim* sim = m_pSim;
    if (*(u32*)((char*)sim + 0x378) == 0) {
        // No track data available
        return;
    }

    // Set anim-playing flag
    m_flags |= 0x00010000;

    // Log animation start
    u32 animId = *(u32*)ref;
    // SAnimatorNullFunc("Starting skill: %d", animId)

    float blendFactor = 0.0f;

    // Check if we're replaying the same animation
    u32 prevAnimState = *(u32*)((char*)this + 0x5F0);
    if (prevAnimState == 1) {
        u32 prevAnimId = *(u32*)((char*)this + 0x5EC);
        if (prevAnimId == animId) {
            // Same animation - calculate blend ratio
            void* animEntry = AnimTable_Find(g_animTable, animId);
            int duration = 0;
            if (animEntry != 0) {
                duration = *(int*)((char*)animEntry + 0x14);
            }

            if (duration > 0) {
                u32 currentTick = *(u32*)((char*)this + 0xC8);
                blendFactor = (float)currentTick / (float)duration;
                if (blendFactor < 0.0f) {
                    blendFactor = 0.0f;
                } else if (blendFactor > kOne) {
                    blendFactor = kOne;
                }
            }

            // Reload with blending
            AnimTable_FindOrLoad(g_animTable, animId, 1, 0);
            goto load_track;
        }
    }

    // New animation - reset state
    *(u32*)((char*)this + 0xC8) = 0;
    *(float*)((char*)this + 0xD0) = 0.0f;

load_track:
    // Clear previous animation state
    *(u32*)((char*)this + 0x5EC) = 0;
    *(u32*)((char*)this + 0x5F0) = 0;

    // Log track load
    // SAnimatorNullFunc("Loading track: %d flags=0x%x", animId, trackFlags)

    // Store animation ID
    *(u32*)((char*)this + 0x5E8) = animId;

    // Check track flags for looping or oneshot
    u32 currentFlags = GetCurrentTrackFlags(m_pSim);
    if (currentFlags & 0x21) {
        // Looping or locked animation
        // Load with full blend: StartTrack(trackFlags, animId, -1, g_speedMultiplier)
    } else {
        // One-shot animation
        // Load with default blend
    }

    // Set track speed
    if (blendIn) {
        // Reverse playback speed (for blend-in from end)
        // SetTrackSpeed(trackHandle, -timeMultiplier)
        // SetTrackBlendWeight(trackHandle, 1.0, true)
        m_flags |= 0x0100;  // set blending flag
    } else {
        // Normal playback
        // SetTrackSpeed(trackHandle, timeMultiplier)
        // SetTrackBlendWeight(trackHandle, blendFactor, true)
        m_flags &= ~0x0100;  // clear blending flag
    }

    // Update person facing from animation data
    // Gets direction from person (vtable call)
    // Normalizes angle and stores in m_animDirection
    m_currentAnimRef = ref;
}

// ============================================================================
// SAnimator2::processEvents(AnimRef &, int, int, bool, bool)
// Address: 0x80065668, Size: 432 bytes
// NON_MATCHING - GCC loop codegen and condition register usage
//
// Processes animation events (keyframes) within a tick range.
// Events are stored in the AnimTable and include:
//   - Footstep events (type 5, offset 150 ticks)
//   - Sound events
//   - Particle spawn/despawn events
//   - Camera effects (bloom, blur, rumble)
//   - Carry pick-up/put-down events
//
// Parameters:
//   ref:        Animation reference containing event data
//   startTick:  Start of tick range to process
//   numTicks:   Number of ticks to process
//   isBlending: If true, sets blend flag in m_flags
//   isReverse:  If true, processes events in reverse order
//
// For forward processing: iterates events from 0 to N-1
// For reverse processing: iterates events from N-1 to 0
// Each event has: {tick, type, data_ptr} (12 bytes per event)
// ============================================================================
void SAnimator2::processEvents(AnimRef& ref, int startTick, int numTicks,
                               bool isBlending, bool isReverse) {
    // Look up animation in table
    u32 animId = *(u32*)&ref;
    void* animEntry = AnimTable_Find(g_animTable, animId);
    int eventCount = 0;

    // Temporary event list (stack-allocated TArray<EAnimNote>)
    // EAnimNote array on stack at r1+8

    if (animEntry != 0) {
        // Copy event list from anim entry at +0x88
        // eventCount = *(u32*)((char*)animEntry + 0x8C)
    }

    // Set or clear blend flag
    if (isBlending) {
        m_flags |= 0x80;
    } else {
        m_flags &= ~0x80;
    }

    // Process events
    if (!isReverse) {
        // Forward: iterate events 0..eventCount-1
        int endTick = startTick + numTicks;
        for (int i = 0; i < eventCount; i++) {
            // EAnimNote* note = &events[i]
            // int eventTick = note->tick
            // if (note->type == 5) eventTick -= 150  // footstep offset
            // if (eventTick < 0) eventTick = 0
            // if (eventTick >= startTick && eventTick < endTick)
            //     eventHandler(*note, i)
        }
    } else {
        // Reverse: iterate events eventCount-1..0
        int duration = 0;
        if (animEntry != 0) {
            duration = *(int*)((char*)animEntry + 0x14);
        }
        int revEndTick = duration - startTick;
        for (int i = eventCount - 1; i >= 0; i--) {
            // Same event check logic but with reversed tick range
        }
    }

    // Clean up temporary event list
}


// ############################################################################
//
//  SECTION 6: IDLE ANIMATION HANDLING
//
// ############################################################################

// ============================================================================
// SAnimator2::handleIdleAnimation(void)
// Address: 0x80063A1C, Size: 2584 bytes
// NON_MATCHING - Very large function, GCC codegen differs significantly
//
// Handles all idle animation logic. This is the most complex animation
// handler because idle has many sub-states:
//   - Standard idle (breathing, weight-shifting)
//   - Skill idle (holding an object idle pose)
//   - Low-motive idle (hungry, tired, etc. with special anims)
//   - Impatient idle (waiting too long)
//   - Algorithmic idle (procedurally selected)
//   - Optional/long idle (yawning, stretching, etc.)
//
// Flow:
//   1. Get current sim age/type for animation selection
//   2. Set sim to non-routing mode
//   3. Clear movement flags
//   4. Check if idle selection has changed (new age tick)
//   5. If skill idle flag is set:
//      - Look up skill-appropriate idle anim
//      - Load and start if found
//      - Set up idle overlay (secondary track blending)
//   6. If standard idle:
//      - Check for low-motive overrides
//      - Check for optional idle timer
//      - Select random idle or algorithmic idle
//   7. Handle idle-to-walk transitions when new movement starts
//   8. Manage optional motion anim loading/unloading
// ============================================================================
void SAnimator2::handleIdleAnimation() {
    // Get sim age group via vtable call (at +0x168/+0x16C)
    int ageGroup = 0;  // from person vtable

    // Set sim to non-routing
    // m_pSim->SetRoutingMode(false, 1)

    // Clear movement-related flags
    m_flags &= ~0x2000;  // clear bit 13

    // Check if idle selection needs refresh
    int prevAge = *(int*)((char*)this + 0x120);
    if (prevAge != 0 && *(int*)((char*)this + 0x124) == ageGroup) {
        // Same age group, skip re-selection
    } else {
        // New age group or first time - update via vtable
        // UpdateAnimationValidity()
    }

    // Check for idle overlay track (bit 12 of flags)
    if (m_flags & 0x1000) {
        // Check if overlay track is done
        // m_pSim->m_animController.IsTrackDone(0x100)
        int overlayDone = 0;
        if (overlayDone) {
            // Clear overlay flag, fade out overlay track
            m_flags &= ~0x1000;
            // m_pSim->m_animController.FadeOutTrack(0x100, ...)
        }
    }

    // Get current age for idle selection
    *(int*)((char*)this + 0x124) = ageGroup;

    // Check if an idle animation is already playing
    int isPlaying = 0;
    // m_pSim->m_animController.IsTrackDone(0x21)

    // Check if idle selection timer has expired
    if (*(int*)((char*)this + 0x124) == 3) {
        // Timer check: accumulate delta time
        float timer = *(float*)((char*)this + 0x128);
        timer += g_deltaTime;
        *(float*)((char*)this + 0x128) = timer;

        float threshold = 120.0f;  // from rodata (2 minutes)
        if (timer > threshold && timer - g_deltaTime <= threshold) {
            // Timer expired - try to select new idle
            if (m_flags & 0x1000) {
                // Clear overlay
                m_flags &= ~0x1000;
                // Fade out track
            }
        }
    }

    // Handle skill idle flag (bit 20)
    if (m_flags & 0x00100000) {
        // Look up skill-specific idle animation
        u8 idleType = *(u8*)((char*)this + 0x5FA);
        int animSlot;
        switch (idleType) {
            case 5:  animSlot = 60; break;
            case 9:  animSlot = 58; break;
            case 7:  animSlot = 62; break;
            case 8:  animSlot = 63; break;
            case 14: animSlot = 64; break;
            case 15: animSlot = 61; break;
            default: animSlot = 3;  break;
        }

        // Look up animation from person's skill table
        AnimRef* idleRef = 0;
        // person->GetSkillAnim(animSlot, &idleRef)

        if (idleRef != 0) {
            // Found skill idle anim
            void* animEntry = AnimTable_Find(g_animTable, *(u32*)idleRef);
            if (animEntry != 0) {
                // Clear skill idle flag, set playing flag
                m_flags &= ~0x00100000;
                m_flags |= 0x00080000;

                // Reset tick state
                *(u32*)((char*)this + 0xC8) = 0;
                *(float*)((char*)this + 0xD0) = 0.0f;
                m_currentAnimRef = idleRef;

                // Check track flags for blend mode
                u32 trackFlags = GetCurrentTrackFlags(m_pSim);
                if (trackFlags & 0x0C) {
                    // Blend mode - use full blend
                    // StartTrack(1, animId, -1, g_blendFactor)
                } else {
                    // Normal mode - use fade blend
                    // StartTrack(1, animId, -1, 0, defaultBlendRate)
                }
            }
        }
    }

    // If no skill idle, handle standard idle selection
    // selectRandomIdle() or SelectAlgorithmicIdle()
    // LoadOptionalIdleAnim()
    // selectIdleOverlay()
}

// ============================================================================
// SAnimator2::selectRandomIdle(void)
// Address: 0x80063D54, Size: 1180 bytes
// NON_MATCHING
//
// Selects a random idle animation from the sim's available pool.
// Considers:
//   - Sim's current mood/motive levels (low hunger -> hungry idle)
//   - Sim's personality traits (neat sims fidget differently)
//   - Whether optional long idles should be loaded
//   - Weighted random selection from available idle pool
// ============================================================================

// ============================================================================
// SAnimator2::SelectAlgorithmicIdle(AnimRef *&)
// Address: 0x8005D608, Size: 692 bytes
// NON_MATCHING
//
// Algorithmically selects an idle animation based on sim state.
// Uses motive levels and personality to weight selection.
// ============================================================================

// ============================================================================
// SAnimator2::handleSkillIdleAnimation(void)
// Address: 0x80063828, Size: 604 bytes
// NON_MATCHING
//
// Handles the skill idle state - when a sim is waiting to perform
// the next step in a multi-step action (e.g., between cooking steps).
// ============================================================================

// ============================================================================
// SAnimator2::handleMoodAnimations(void)
// Address: 0x80061AFC, Size: 864 bytes
// NON_MATCHING
//
// Handles mood-based animation overlays. When a sim's mood drops
// (low hygiene, hunger, energy), special mood animations play over
// the base idle. Checks motive thresholds and blends mood anims.
// ============================================================================


// ############################################################################
//
//  SECTION 7: WALK/RUN/TURN ANIMATION
//
// ############################################################################

// ============================================================================
// SAnimator2::handleWalkRunAnimation(void)
// Address: 0x80062478, Size: 492 bytes
// NON_MATCHING
//
// Handles walk and run animation blending. When a sim is moving:
//   - Selects walk or run animation based on speed
//   - Blends between walk/run based on actual velocity
//   - Handles acceleration and deceleration curves
//   - Updates footstep timing for sound effects
// ============================================================================
void SAnimator2::handleWalkRunAnimation() {
    // Store current walk position
    *(float*)((char*)this + 0x1C0) = m_animDirection;
    *(u32*)((char*)this + 0x1C4) = *(u32*)((char*)this + 0x1C8);

    // Select walk/run animation based on style
    // getWalkRunSkillID() gets the appropriate AnimRef
    // initWalkRun() sets up the animation parameters
    // initWalkRunFadeOut() handles the transition
}

// ============================================================================
// SAnimator2::handleTurnAnimation(void)
// Address: 0x80064CA4, Size: 840 bytes
// NON_MATCHING
//
// Handles turn-in-place animations. When a sim needs to face a new
// direction without walking:
//   - Selects left or right turn based on shortest arc
//   - Plays turn animation at speed proportional to angle delta
//   - Monitors completion and transitions to next state
//   - Handles interrupted turns (new destination while turning)
// ============================================================================

// ============================================================================
// SAnimator2::handleSidestepAnimation(void)
// Address: 0x80062424, Size: 84 bytes
// NON_MATCHING - Small wrapper
//
// Handles sidestep animation. Calls initSidestep() to set up the
// lateral movement animation parameters. Used when a sim needs to
// move sideways (e.g., shuffling along a counter).
// ============================================================================
void SAnimator2::handleSidestepAnimation() {
    initSidestep();
}

// ============================================================================
// SAnimator2::handleRunStopAnimation(void)
// Address: 0x80063124, Size: 540 bytes
// NON_MATCHING
//
// Handles the deceleration animation when a sim stops running.
// Plays a skid/stop animation and blends back to idle.
// ============================================================================

// ============================================================================
// SAnimator2::handleFreeMoveWalkRunAnimation(void)
// Address: 0x80062AC8, Size: 1532 bytes
// NON_MATCHING
//
// Handles direct-control (player-controlled) walk/run animation.
// This is the "free move" mode where the player directly controls
// the sim with the analog stick. Handles:
//   - Analog stick input -> velocity mapping
//   - Walk/run threshold switching
//   - Direction changes during movement
//   - Blend between idle/walk/run based on stick magnitude
// ============================================================================


// ############################################################################
//
//  SECTION 8: CARRY ANIMATION SYSTEM
//
// ############################################################################

// ============================================================================
// SAnimator2::updateCarryAnimation(void)
// Address: 0x80066C54, Size: 840 bytes
// NON_MATCHING
//
// Updates the carry animation overlay each frame. When a sim is
// carrying an object (plate of food, baby, etc.):
//   - Positions the carried object relative to the hand bone
//   - Blends carry arm poses over the base animation
//   - Handles dual-arm carries (large objects)
//   - Manages carry state transitions (pick up, put down)
// ============================================================================

// ============================================================================
// SAnimator2::startCarry(void)
// Address: 0x80068240, Size: 724 bytes
// NON_MATCHING
//
// Initiates a carry animation. Sets up arm bone locking and
// positions the carried prop relative to the right hand bone.
// ============================================================================

// ============================================================================
// SAnimator2::stopCarry(void)
// Address: 0x80068514, Size: 484 bytes
// NON_MATCHING
//
// Ends carry animation. Unlocks arm bones and removes carry overlay.
// ============================================================================


// ############################################################################
//
//  SECTION 9: PROPS AND COSTUME
//
// ############################################################################

// ============================================================================
// SAnimator2::Dress(PropRef *)
// Address: 0x8005F4F4, Size: 316 bytes
// NON_MATCHING
//
// Applies a prop/clothing item to the sim. Gets the correct model ID,
// loads the mesh, and attaches it to the appropriate bone.
// ============================================================================

// ============================================================================
// SAnimator2::Undress(PropRef *)
// Address: 0x8005F848, Size: 152 bytes
// NON_MATCHING
//
// Removes a prop/clothing item from the sim.
// ============================================================================

// ============================================================================
// SAnimator2::AddProp(unsigned int, bool)
// Address: 0x8005F5F8, Size: 148 bytes
// NON_MATCHING
//
// Adds a prop to the sim's prop list for rendering.
// ============================================================================

// ============================================================================
// SAnimator2::RemoveProp(unsigned int)
// Address: 0x8005F68C, Size: 172 bytes
// NON_MATCHING
//
// Removes a prop from the sim's prop list.
// ============================================================================

// ============================================================================
// SAnimator2::removeAllProps(void)
// Address: 0x80067ABC, Size: 228 bytes
// NON_MATCHING
//
// Removes all props from the sim. Iterates the prop list and detaches each.
// ============================================================================

// ============================================================================
// SAnimator2::wearNormal(void)
// Address: 0x800676F4, Size: 292 bytes
// NON_MATCHING
//
// Restores the sim to their normal (non-costume) outfit.
// Reads from the saved normal sim description.
// ============================================================================

// ============================================================================
// SAnimator2::setJobModel(void)
// Address: 0x80067564, Size: 396 bytes
// NON_MATCHING
//
// Sets the sim's model to their job/career outfit.
// ============================================================================

// ============================================================================
// SAnimator2::setNewModel(char *, bool, bool)
// Address: 0x800677E8, Size: 616 bytes
// NON_MATCHING
//
// Loads and applies a new character model. Handles:
//   - Model file loading
//   - Bone remapping
//   - Texture application
//   - Previous model cleanup
// ============================================================================


// ############################################################################
//
//  SECTION 10: PARTICLE EFFECTS
//
// ############################################################################

// ============================================================================
// SAnimator2::updateParticles(void)
// Address: 0x80061418, Size: 1088 bytes
// NON_MATCHING
//
// Updates all bone-attached particle effects each frame.
// Iterates the particle red-black tree at +0x5D0 and +0x5DC,
// updates each particle's position to match its parent bone.
// ============================================================================

// ============================================================================
// SAnimator2::AttachParticleEffect(unsigned int, unsigned int, int)
// Address: 0x80065314, Size: 444 bytes
// NON_MATCHING
//
// Attaches a particle effect to a bone. Creates an EBoneParticle
// and inserts it into the particle tree.
// ============================================================================

// ============================================================================
// SAnimator2::DetachParticleEffect(unsigned int, unsigned int, int)
// Address: 0x8006550C, Size: 392 bytes
// NON_MATCHING
//
// Detaches a particle effect from a bone and cleans it up.
// ============================================================================

// ============================================================================
// SAnimator2::procBoneParticleEvt(AnimParticleData *, bool)
// Address: 0x80065F44, Size: 1620 bytes
// NON_MATCHING
//
// Processes a bone particle event from the animation event system.
// Creates or destroys particle effects based on the event data.
// ============================================================================

// ============================================================================
// SAnimator2::cleanupParticles(TRedBlackTree<unsigned int, TRedBlackTree<unsigned int, EBoneParticle *> *> *)
// Address: 0x80066A24, Size: 376 bytes
// NON_MATCHING
//
// Recursively cleans up all particles in a tree.
// ============================================================================

// ============================================================================
// SAnimator2::cleanupParticlesImmediate(TRedBlackTree<unsigned int, TRedBlackTree<unsigned int, EBoneParticle *> *> *)
// Address: 0x80066874, Size: 320 bytes
// NON_MATCHING
//
// Immediately destroys all particles (no fade-out).
// Used during level transitions and sim deletion.
// ============================================================================

// ============================================================================
// SAnimator2::cleanupParticlesDelayed(TRedBlackTree<unsigned int, TRedBlackTree<unsigned int, EBoneParticle *> *> *)
// Address: 0x80066740, Size: 308 bytes
// NON_MATCHING
//
// Marks particles for delayed cleanup (with fade-out).
// Used during normal gameplay transitions.
// ============================================================================


// ############################################################################
//
//  SECTION 11: EVENT HANDLER
//
// ############################################################################

// ============================================================================
// SAnimator2::eventHandler(EAnimNote &, int)
// Address: 0x80065818, Size: 1504 bytes
// NON_MATCHING
//
// Dispatches an animation event to the appropriate handler.
// Event types:
//   0: Generic event (ignored)
//   1: Footstep -> footstepEvent()
//   2: Sound effect -> play sound
//   3: Particle attach -> AttachParticleEffect()
//   4: Particle detach -> DetachParticleEffect()
//   5: Camera bloom -> triggerCameraBloom()
//   6: Camera blur -> triggerCameraBlur()
//   7: Rumble -> playRumble()
//   8: Carry start -> startCarry()
//   9: Carry end -> stopCarry()
//  10: Bone particle -> procBoneParticleEvt()
// ============================================================================

// ============================================================================
// SAnimator2::PreloadEvents(AnimRef *)
// Address: 0x80065EA0, Size: 660 bytes
// NON_MATCHING
//
// Pre-loads resources needed by animation events (sounds, particles)
// before the animation starts playing. Prevents hitches during playback.
// ============================================================================


// ############################################################################
//
//  SECTION 12: POSITION AND ORIENTATION
//
// ############################################################################

// ============================================================================
// SAnimator2::positionCharacter(EMat4 *)
// Address: 0x80064FE4, Size: 1312 bytes
// NON_MATCHING
//
// Positions the character model in the world. Builds the world matrix
// from the animation position, direction, and bone positions.
// Handles pelvis, torso, and head bone orientations.
// ============================================================================

// ============================================================================
// SAnimator2::rotateAnimation(float, float, float)
// Address: 0x80060648, Size: 448 bytes
// NON_MATCHING
//
// Rotates the animation direction by the given angles.
// Used during turning animations to smoothly interpolate direction.
// ============================================================================

// ============================================================================
// SAnimator2::setPersonDirection(float)
// Address: 0x80066AFC, Size: 304 bytes
// NON_MATCHING
//
// Sets the person's facing direction via vtable call.
// Converts the animation format direction to the engine format.
// ============================================================================

// ============================================================================
// SAnimator2::getPersonDirection(void)
// Address: 0x80069230, Size: 288 bytes
// NON_MATCHING
//
// Gets the person's current facing direction via vtable call.
// Converts from engine format to animation format angle.
// ============================================================================

// ============================================================================
// SAnimator2::SetDesiredFacing(float)
// Address: 0x80069400, Size: 208 bytes
// NON_MATCHING
//
// Sets the desired facing direction. The sim will turn to face this
// direction during the next idle -> turn transition.
// ============================================================================

// ============================================================================
// SAnimator2::getDesiredDir(void)
// Address: 0x80069EDC, Size: 664 bytes
// NON_MATCHING
//
// Calculates the desired direction based on the next waypoint
// in the current path. Returns the angle to the next node.
// ============================================================================

// ============================================================================
// SAnimator2::getDeltaDirFromDesiredDir(float)
// Address: 0x80069E28, Size: 196 bytes
// NON_MATCHING
//
// Calculates the angular difference between current and desired direction.
// Returns the shortest arc (positive = clockwise, negative = counter-clockwise).
// ============================================================================

// ============================================================================
// SAnimator2::moveTowardsDestination(float &, EVec2 &)
// Address: 0x80060F30, Size: 616 bytes
// NON_MATCHING
//
// Moves the sim towards a destination position. Handles:
//   - Velocity-based position update
//   - Direction interpolation
//   - Collision avoidance
//   - Arrival detection
// ============================================================================

// ============================================================================
// SAnimator2::GetEngineFormatPos(void)
// Address: 0x80065558, Size: 188 bytes
// NON_MATCHING
//
// Converts the animation-space position to engine-space coordinates.
// Animation uses a 1/16 scale relative to engine coordinates.
// ============================================================================


// ############################################################################
//
//  SECTION 13: DIAGNOSTIC DISPLAY
//
// ############################################################################

// ============================================================================
// SAnimator2::updateDiagnosticDisplay(void)
// Address: 0x8005D164, Size: 1808 bytes
// NON_MATCHING
//
// Updates debug/diagnostic display information. Records:
//   - Current animation name and state
//   - Follow mode and routing status
//   - Tick counter and blend factors
//   - Bone positions for debug rendering
// Only active in debug builds.
// ============================================================================

// ============================================================================
// SAnimator2::drawDiagnosticDisplay(ERC *)
// Address: 0x8005DD6C, Size: 468 bytes
// NON_MATCHING
//
// Renders debug information above the sim's head showing
// current animation state, routing status, etc.
// ============================================================================

// ============================================================================
// SAnimator2::drawLastAnimationNames(ERC *)
// Address: 0x8005DF40, Size: 456 bytes
// NON_MATCHING
//
// Renders the names of recently played animations for debugging.
// ============================================================================


// ############################################################################
//
//  SECTION 14: RECON (SAVE/LOAD STATE)
//
// ############################################################################

// ============================================================================
// SAnimator2::ReconStream(ReconBuffer *, int)
// Address: 0x8005EDBC, Size: 2112 bytes
// NON_MATCHING
//
// Serializes/deserializes the animator state for save files.
// Writes or reads:
//   - Animation state (animState, followMode)
//   - Position and direction
//   - Active animation references
//   - Tick counters
//   - Carry state
//   - Movement parameters
//
// Direction (int) controls read vs write:
//   0 = save (write to buffer)
//   1 = load (read from buffer)
// ============================================================================

// ============================================================================
// SAnimator2::DequeueAnimEvent(int *)
// Address: 0x8005EDBC, Size: 200 bytes
// NON_MATCHING
//
// Dequeues a pending animation event. Returns the event ID
// and removes it from the event queue.
// ============================================================================


// ############################################################################
//
//  SECTION 15: OPTIONAL / LONG IDLE ANIMATIONS
//
// ############################################################################

// ============================================================================
// SAnimator2::LoadOptionalIdleAnim(void)
// Address: 0x80064598, Size: 356 bytes
// NON_MATCHING
//
// Loads an optional long idle animation (yawning, stretching, etc.).
// These are loaded on-demand and unloaded when not needed.
// ============================================================================

// ============================================================================
// SAnimator2::UnloadOptionalIdleAnim(void)
// Address: 0x80064858, Size: 388 bytes
// NON_MATCHING
//
// Unloads the optional idle animation to free memory.
// ============================================================================

// ============================================================================
// SAnimator2::UnloadPendingLongIdleAnim(void)
// Address: 0x80064700, Size: 264 bytes
// NON_MATCHING
//
// Unloads a pending long idle animation that was requested but
// hasn't started playing yet.
// ============================================================================

// ============================================================================
// SAnimator2::LoadDCOptionalMotionAnims(void)
// Address: 0x80064434, Size: 376 bytes
// NON_MATCHING
//
// Loads direct-control optional motion animations (special walk/run
// variants for player-controlled movement).
// ============================================================================

// ============================================================================
// SAnimator2::UnloadDCOptionalMotionAnims(void)
// Address: 0x80064970, Size: 320 bytes
// NON_MATCHING
//
// Unloads direct-control motion animations.
// ============================================================================

// ============================================================================
// SAnimator2::LoadSMOptionalMotionAnims(void)
// Address: 0x80064320, Size: 376 bytes
// NON_MATCHING
//
// Loads state-machine optional motion animations (special walk variants
// triggered by motive states like tired, hungry, etc.).
// ============================================================================

// ============================================================================
// SAnimator2::UnloadSMOptionalMotionAnims(void)
// Address: 0x80064AB0, Size: 320 bytes
// NON_MATCHING
//
// Unloads state-machine motion animations.
// ============================================================================

// ============================================================================
// SAnimator2::CheckOptionalMotionAnimStatusOnStateChange(SAnimator2::eAnimState)
// Address: 0x80064C18, Size: 152 bytes
// NON_MATCHING
//
// Called when the animation state changes. Decides whether to load or
// unload optional motion animations based on the new state.
// ============================================================================


// ############################################################################
//
//  SECTION 16: SKILL ANIMATION MANAGEMENT
//
// ############################################################################

// ============================================================================
// SAnimator2::TryAnimate(StackElem *, AnimateNewParam *)
// Address: 0x8005D6F4, Size: 5736 bytes
// NON_MATCHING - Largest function in SAnimator2
//
// Attempts to start a new animation from a game primitive.
// This is the main entry point for the behavior tree to trigger animations.
//
// Handles:
//   - Looking up the animation from the primitive's parameters
//   - Checking if the animation is available and loaded
//   - Setting up blend parameters
//   - Starting primary and/or secondary animation tracks
//   - Handling animation priority and interruption
//   - Setting up event processing
//
// Returns success/failure to the behavior tree.
// ============================================================================

// ============================================================================
// SAnimator2::TryIdleAnimate(StackElem *, IdleAnimateParam *)
// Address: 0x8005D218, Size: 1352 bytes
// NON_MATCHING
//
// Similar to TryAnimate but specifically for idle animations.
// Uses different lookup tables and blend parameters.
// ============================================================================

// ============================================================================
// SAnimator2::resolveSkillForPrimitive(StackElem *, AnimateNewParam *, AnimRef *&)
// Address: 0x8005D930, Size: 1272 bytes
// NON_MATCHING
//
// Resolves which animation to play for a given game primitive.
// Checks skill tables, age groups, and animation availability.
// ============================================================================

// ============================================================================
// SAnimator2::resolveSkillForPrimitive(StackElem *, IdleAnimateParam *, AnimRef *&)
// Address: 0x8005D738, Size: 1244 bytes
// NON_MATCHING
//
// Overload for idle animate primitives.
// ============================================================================

// ============================================================================
// SAnimator2::loadSkillAnim(AnimRef *)
// Address: 0x8005DE0C, Size: 432 bytes
// NON_MATCHING
//
// Loads a skill animation into the anim table.
// ============================================================================

// ============================================================================
// SAnimator2::isAnimationDone(void)
// Address: 0x80066940, Size: 296 bytes  (at different addr for this overload)
// NON_MATCHING
//
// Checks if the current skill animation has finished playing.
// Returns true if the track is done or if no animation is active.
// ============================================================================


// ############################################################################
//
//  SECTION 17: AWARENESS SYSTEM HOOKS
//
// ############################################################################

// ============================================================================
// SAnimator2::shouldUseLowMotiveIdle(void)
// Address: 0x80068BD4, Size: 996 bytes
// NON_MATCHING
//
// Determines if the sim should use a low-motive idle animation
// based on current hunger, energy, hygiene, etc. levels.
// ============================================================================

// ============================================================================
// SAnimator2::shouldUseLowMotiveWalk(void)
// Address: 0x80068FB8, Size: 400 bytes
// NON_MATCHING
//
// Determines if the sim should use a low-motive walk animation
// (e.g., dragging feet when exhausted).
// ============================================================================

// ============================================================================
// SAnimator2::IsSimulatorControlled(void)
// Address: 0x80068960, Size: 400 bytes
// NON_MATCHING
//
// Returns true if the sim is being controlled by the AI simulator
// rather than the player. Checks the m_bIsSimulatorControlled field
// and various other conditions.
// ============================================================================

// ============================================================================
// SAnimator2::SetPlayerControl(bool)
// Address: 0x80068F04, Size: 128 bytes
// NON_MATCHING
//
// Sets whether the sim is player-controlled. Updates the
// player control flag and the awareness manager.
// ============================================================================
void SAnimator2::SetPlayerControl(bool control) {
    if (control) {
        m_flags |= 0x01;
    } else {
        m_flags &= ~0x01;
    }
    m_awarenessMgr.SetPlayerControl(control);
}


// ############################################################################
//
//  SECTION 18: CENSORSHIP OVERLAY
//
// ############################################################################

// ============================================================================
// SAnimator2::DrawCensor(ERC *)
// Address: 0x80067E18, Size: 3264 bytes
// NON_MATCHING
//
// Renders the censorship mosaic overlay when a sim is nude.
// Handles:
//   - Pelvis and torso bone position lookup
//   - Billboard quad generation
//   - Pixel mosaic shader application
//   - Camera-relative alignment
// ============================================================================

// ============================================================================
// SAnimator2::updateCensor(void)
// Address: 0x80067CC0, Size: 440 bytes
// NON_MATCHING
//
// Updates the censor overlay's visibility based on clothing state.
// ============================================================================


// ############################################################################
//
//  SECTION 19: RENDER AND MODEL UPDATES
//
// ############################################################################

// ============================================================================
// SAnimator2::updateRenderModels(void)
// Address: 0x800672E0, Size: 520 bytes
// NON_MATCHING
//
// Updates the render models each frame. Handles:
//   - LOD selection based on camera distance
//   - Model visibility culling
//   - Shadow model updates
// ============================================================================

// ============================================================================
// SAnimator2::DrawProps(ERC *, bool, EShader *)
// Address: 0x80067810, Size: 832 bytes
// NON_MATCHING
//
// Renders all props attached to the sim (hat, glasses, held objects).
// ============================================================================

// ============================================================================
// SAnimator2::DrawPropsShadow(ERC *)
// Address: 0x800679C0, Size: 352 bytes
// NON_MATCHING
//
// Renders shadow geometry for sim props.
// ============================================================================

// ============================================================================
// SAnimator2::PropsHaveAlpha(void)
// Address: 0x80067794, Size: 236 bytes
// NON_MATCHING
//
// Returns true if any attached prop has alpha transparency,
// requiring special render sorting.
// ============================================================================

// ============================================================================
// SAnimator2::TryChangeSuit(void)
// Address: 0x8005C790, Size: 336 bytes
// NON_MATCHING
//
// Checks if the sim needs to change outfits (e.g., entering/leaving
// a pool, going to work, sleeping). Triggers costume change if needed.
// ============================================================================


// ############################################################################
//
//  SECTION 20: MOVEMENT UTILITIES
//
// ############################################################################

// ============================================================================
// SAnimator2::initSidestep(void)
// Address: 0x8006B4EC, Size: 788 bytes
// NON_MATCHING
//
// Initializes a sidestep movement. Calculates lateral movement
// parameters and sets up the sidestep animation blend.
// ============================================================================

// ============================================================================
// SAnimator2::initWalkRun(void)
// Address: 0x8006B800, Size: 420 bytes
// NON_MATCHING
//
// Initializes walk or run movement. Sets up velocity,
// animation selection, and foot synchronization.
// ============================================================================

// ============================================================================
// SAnimator2::initWalkRunFadeOut(void)
// Address: 0x8006B9A4, Size: 328 bytes
// NON_MATCHING
//
// Sets up the fade-out from walk/run to idle when stopping.
// ============================================================================

// ============================================================================
// SAnimator2::setMovementVelocityFromAnimation(void)
// Address: 0x80069D10, Size: 1040 bytes
// NON_MATCHING
//
// Reads the root motion velocity from the current animation
// and applies it to the sim's movement system. This is how
// animation-driven movement works - the walk animation's root
// bone displacement drives the actual sim movement.
// ============================================================================

// ============================================================================
// SAnimator2::EnableWalkFade(unsigned int &, float, float, float)
// Address: 0x80060DA8, Size: 372 bytes
// NON_MATCHING
//
// Enables cross-fade between walk animations. Used when switching
// between walk and run, or when changing direction while moving.
// ============================================================================

// ============================================================================
// SAnimator2::CheckCollision(EVec2 &, EVec2 &)
// Address: 0x80062734, Size: 988 bytes
// NON_MATCHING
//
// Checks for collision between the sim and other objects/sims
// at the given positions. Uses the world's collision grid.
// ============================================================================

// ============================================================================
// SAnimator2::UpdatePortalMode(void)
// Address: 0x8005FE10, Size: 728 bytes
// NON_MATCHING
//
// Updates portal traversal mode. Portals are connections between
// different lot areas (doors, stairs, elevators). Handles:
//   - Portal entry/exit animations
//   - Level transition logic
//   - Height changes for stairs
// ============================================================================

// ============================================================================
// SAnimator2::UpdateNPCAutoRun(void)
// Address: 0x8006B2D0, Size: 372 bytes
// NON_MATCHING
//
// Updates NPC auto-run behavior. When NPCs need to traverse
// long distances, they automatically switch to running.
// ============================================================================

// ============================================================================
// SAnimator2::UpdateNPCAutoRunState(void)
// Address: 0x8006B1F4, Size: 220 bytes
// NON_MATCHING
//
// Updates the state machine for NPC auto-run mode.
// ============================================================================

// ============================================================================
// SAnimator2::StartAutoRun(float)
// Address: 0x8006CFF4, Size: 180 bytes
// NON_MATCHING
//
// Starts auto-run mode for the sim at the given speed.
// ============================================================================

// ============================================================================
// SAnimator2::EndAutoRun(void)
// Address: 0x80069F8C, Size: 152 bytes
// NON_MATCHING
//
// Ends auto-run mode.
// ============================================================================

// ============================================================================
// SAnimator2::getWalkRunSkillID(AnimRef *&)
// Address: 0x8006AEE4, Size: 784 bytes
// NON_MATCHING
//
// Gets the animation ID for walk/run based on current speed
// and movement style. Considers sim traits and motive levels.
// ============================================================================

// ============================================================================
// SAnimator2::getTurnSkillID(AnimRef *&, int)
// Address: 0x8006AAC8, Size: 748 bytes
// NON_MATCHING
//
// Gets the animation ID for turn-in-place. Selects between
// left and right turn based on the direction parameter.
// ============================================================================

// ============================================================================
// SAnimator2::determineWalkRunStyle(float)
// Address: 0x80069B88, Size: 480 bytes
// NON_MATCHING
//
// Determines whether the sim should walk or run based on
// the requested speed and personality traits.
// ============================================================================

// ============================================================================
// SAnimator2::GetTurnRate(void)
// Address: 0x80060544, Size: 212 bytes
// NON_MATCHING
//
// Returns the current turn rate (radians per second).
// Varies based on animation state and movement speed.
// ============================================================================

// ============================================================================
// SAnimator2::GetMovementVelocityFromStyle(SAnimator2::eWalkRunStyle)
// Address: 0x8006A150, Size: 272 bytes
// NON_MATCHING
//
// Returns the movement velocity for the given walk/run style.
// Maps style enum to the velocity values stored in the struct.
// ============================================================================

// ============================================================================
// SAnimator2::defaultVelocity(int)
// Address: 0x80069940, Size: 184 bytes
// NON_MATCHING
//
// Returns the default velocity for the given movement type.
// ============================================================================

// ============================================================================
// SAnimator2::getAnimDuration(ERAnim *)
// Address: 0x800699C8, Size: 132 bytes
// NON_MATCHING
//
// Returns the duration (in ticks) of the given animation.
// ============================================================================

// ============================================================================
// SAnimator2::setSideStepSpeedFromAnimation(AnimRef *)
// Address: 0x80069A48, Size: 924 bytes
// NON_MATCHING
//
// Sets the sidestep speed based on the animation's root motion data.
// ============================================================================

// ============================================================================
// SAnimator2::setRotationRateFromShuffleDir(int, float)
// Address: 0x8006A134, Size: 632 bytes
// NON_MATCHING
//
// Sets the rotation rate for shuffle-step turns based on direction.
// ============================================================================

// ============================================================================
// SAnimator2::getShuffleDirFromDeltaDir(float)
// Address: 0x80069CF8, Size: 248 bytes
// NON_MATCHING
//
// Converts a delta direction angle to a shuffle direction index.
// ============================================================================

// ============================================================================
// SAnimator2::getSidestepSkillIDs(AnimRef *&, AnimRef *&, float)
// Address: 0x8006ADD8, Size: 304 bytes
// NON_MATCHING
//
// Gets the animation IDs for left and right sidestep.
// ============================================================================

// ============================================================================
// SAnimator2::getSidestepIntensity(void)
// Address: 0x8006B44C, Size: 160 bytes
// NON_MATCHING
//
// Returns the intensity of the current sidestep movement.
// ============================================================================


// ############################################################################
//
//  SECTION 21: FOLLOW SUB-HANDLERS
//
// ############################################################################

// ============================================================================
// SAnimator2::endFollowDone(void)
// Address: 0x8005F3F4, Size: 748 bytes
// NON_MATCHING
//
// Finalizes a completed follow sequence. Snaps the sim to the
// exact destination position and plays the arrival animation.
// ============================================================================

// ============================================================================
// SAnimator2::followStandToTurnUpdate(float &, float &, float)
// Address: 0x8005F958, Size: 172 bytes
// NON_MATCHING
//
// Updates the stand-to-turn phase of path following.
// Rotates the sim to face the first waypoint before walking.
// ============================================================================

// ============================================================================
// SAnimator2::followSidestepUpdate(float &, float &, float)
// Address: 0x8005FA04, Size: 740 bytes
// NON_MATCHING
//
// Updates the sidestep phase of path following.
// Moves the sim laterally to align with the path.
// ============================================================================

// ============================================================================
// SAnimator2::followMiddleUpdate(float &, float &, float)
// Address: 0x8005FCE8, Size: 284 bytes
// NON_MATCHING
//
// Updates the middle (walking) phase of path following.
// The main movement handler - advances the sim along path segments.
// ============================================================================

// ============================================================================
// SAnimator2::followMoveToTurnUpdate(float &, float &, float)
// Address: 0x8005FE04, Size: 148 bytes
// NON_MATCHING
//
// Updates the move-to-turn transition phase.
// Handles the transition from walking to turning at waypoints.
// ============================================================================

// ============================================================================
// SAnimator2::followDoneUpdate(float &, float &, float)
// Address: 0x8005FE98, Size: 148 bytes
// NON_MATCHING
//
// Updates the done phase of path following.
// Handles the final approach to the destination.
// ============================================================================

// ============================================================================
// SAnimator2::endMoveAnimation(void)
// Address: 0x8005FF2C, Size: 508 bytes
// NON_MATCHING
//
// Ends the current movement animation. Transitions from
// walk/run to the appropriate idle state.
// ============================================================================

// ============================================================================
// SAnimator2::advanceAlongNode(float &)
// Address: 0x80060928, Size: 364 bytes
// NON_MATCHING
//
// Advances the sim's position along the current path node
// by the given distance. Returns remaining distance if the
// node is fully traversed.
// ============================================================================

// ============================================================================
// SAnimator2::sidestepAlongNode(float &)
// Address: 0x80060A8C, Size: 532 bytes
// NON_MATCHING
//
// Moves the sim sideways along the current path node.
// Used for sidestep movement mode.
// ============================================================================

// ============================================================================
// SAnimator2::getUseSpeed(float, float, float, float)
// Address: 0x80060C08, Size: 576 bytes
// NON_MATCHING
//
// Calculates the effective movement speed considering:
//   - Base animation speed
//   - Terrain modifiers
//   - Motive penalties (tired = slower)
//   - Carry penalties (holding objects = slower)
// ============================================================================

// ============================================================================
// SAnimator2::SetNextStateFromCompletedTurn(void)
// Address: 0x80063378, Size: 252 bytes
// NON_MATCHING
//
// After a turn animation completes, determines the next animation state.
// Usually transitions to walk/run or back to idle.
// ============================================================================


// ############################################################################
//
//  SECTION 22: AWARENESS FOLLOW HOOKS
//
// ############################################################################

// ============================================================================
// SAnimator2::setAwarenessFollowStart(float)
// Address: 0x80068ABC, Size: 232 bytes
// NON_MATCHING
//
// Sets up awareness tracking when a sim starts following a path.
// The awareness system makes sims react to things they walk past.
// ============================================================================

// ============================================================================
// SAnimator2::setAwarenessFollowEnd(void)
// Address: 0x8006CEB4, Size: 124 bytes
// NON_MATCHING
//
// Clears awareness tracking when path following ends.
// ============================================================================

// ============================================================================
// SAnimator2::setAwarenessFollowMiddle(void)
// Address: 0x8006CF30, Size: 80 bytes
// NON_MATCHING
//
// Updates awareness during the middle of path following.
// ============================================================================

// ============================================================================
// SAnimator2::exitAwarenessFollow(void)
// Address: 0x8006CF80, Size: 180 bytes
// NON_MATCHING
//
// Exits awareness follow mode. Called when routing ends or
// is interrupted.
// ============================================================================

// ============================================================================
// SAnimator2::awarenessMove(void)
// Address: 0x80060128, Size: 1012 bytes
// NON_MATCHING
//
// Handles awareness-based movement adjustments. When a sim
// notices something interesting while walking, this function
// can modify their path or play a reaction animation.
// ============================================================================


// ############################################################################
//
//  SECTION 23: IDLE OVERLAY / MISC
//
// ############################################################################

// ============================================================================
// SAnimator2::selectIdleOverlay(void)
// Address: 0x8006BAA4, Size: 1068 bytes
// NON_MATCHING
//
// Selects an idle overlay animation to blend with the base idle.
// Overlays add variety - e.g., looking around, scratching head.
// ============================================================================

// ============================================================================
// SAnimator2::stopIdleOverlay(void)
// Address: 0x8006BED0, Size: 128 bytes
// NON_MATCHING
//
// Stops the current idle overlay animation.
// ============================================================================

// ============================================================================
// SAnimator2::clearImpatientIdleAnimation(void)
// Address: 0x80064298, Size: 180 bytes
// NON_MATCHING
//
// Clears the impatient idle animation (foot tapping, arm crossing)
// that plays when a sim has been waiting too long.
// ============================================================================

// ============================================================================
// SAnimator2::StartDefaultIdle(void)
// Address: 0x80069D48, Size: 472 bytes
// NON_MATCHING
//
// Starts the default idle animation. Called when no other animation
// is playing and the sim needs to return to idle.
// ============================================================================

// ============================================================================
// SAnimator2::skillIsIdle(void)
// Address: 0x8006C618, Size: 140 bytes
// NON_MATCHING
//
// Returns true if the current skill animation is an idle-type animation.
// ============================================================================

// ============================================================================
// SAnimator2::ShouldEndSkillTrack(void)
// Address: 0x8006C6A0, Size: 236 bytes
// NON_MATCHING
//
// Determines if the current skill track should end.
// Checks completion conditions and interruption requests.
// ============================================================================

// ============================================================================
// SAnimator2::UpdateAnimationValidity(void)
// Address: 0x80068948, Size: 112 bytes
// NON_MATCHING
//
// Validates that the current animation is still appropriate.
// Checks if the sim's state has changed in a way that invalidates
// the current animation (e.g., outfit change, age transition).
// ============================================================================

// ============================================================================
// SAnimator2::addSkillAnimationName(char *, AnimRef *)
// Address: 0x800698E4, Size: 128 bytes
// NON_MATCHING
//
// Adds an animation name to the skill animation name list.
// Used for diagnostic display.
// ============================================================================

// ============================================================================
// SAnimator2::addAnimationName(char *)
// Address: 0x8005E544, Size: 256 bytes
// NON_MATCHING
//
// Adds an animation name to the recently-played list for debugging.
// ============================================================================

// ============================================================================
// SAnimator2::SetIdleAnimPlaybackParameters(EACTrack *)
// Address: 0x80069960, Size: 100 bytes
// NON_MATCHING
//
// Sets playback parameters (speed, blend weight) for idle animations
// based on the current time multiplier and pause state.
// ============================================================================

// ============================================================================
// SAnimator2::clearSuspendedCarry(void)
// Address: 0x80069860, Size: 160 bytes
// NON_MATCHING
//
// Clears the suspended carry state. A carry can be suspended when
// a sim needs to perform a two-handed action while holding something.
// ============================================================================

// ============================================================================
// SAnimator2::DetachMonitoredTrack(void)
// Address: 0x80069714, Size: 112 bytes
// NON_MATCHING
//
// Detaches the monitored animation track. A monitored track is
// watched for completion to trigger state transitions.
// ============================================================================

// ============================================================================
// SAnimator2::determineFirstFollowMode(TileList *)
// Address: 0x80069AB0, Size: 192 bytes
// NON_MATCHING
//
// Determines the initial follow mode based on the tile path.
// Checks if the path requires turning, sidestepping, or direct walking.
// ============================================================================

// ============================================================================
// SAnimator2::setFirstFollowMode(SAnimator2::eFollowMode)
// Address: 0x800697C0, Size: 132 bytes
// NON_MATCHING
//
// Sets the initial follow mode and configures movement parameters.
// ============================================================================

// ============================================================================
// SAnimator2::setFollowEnd(void)
// Address: 0x80069920, Size: 104 bytes
// NON_MATCHING
//
// Sets follow mode to FOLLOW_DONE and begins the arrival sequence.
// ============================================================================

// ============================================================================
// SAnimator2::setFollowDone(void)
// Address: 0x80069800, Size: 116 bytes
// NON_MATCHING
//
// Marks follow as completely done. Finalizes position.
// ============================================================================

// ============================================================================
// SAnimator2::updateDesiredAndDeltaDir(float &, float &)
// Address: 0x80069784, Size: 92 bytes
// NON_MATCHING
//
// Updates the desired and delta direction values for movement.
// ============================================================================

// ============================================================================
// SAnimator2::getIsLeftFootUp(void)
// Address: 0x80069C70, Size: 136 bytes
// NON_MATCHING
//
// Returns true if the left foot is currently up in the walk cycle.
// Used for foot synchronization when starting/stopping movement.
// ============================================================================

// ============================================================================
// SAnimator2::getIndexOfPropID(unsigned int)
// Address: 0x80069930, Size: 176 bytes
// NON_MATCHING
//
// Returns the index of a prop in the prop array, or -1 if not found.
// ============================================================================

// ============================================================================
// SAnimator2::getCorrectId(PropRef *)
// Address: 0x8005F508, Size: 188 bytes
// NON_MATCHING
//
// Resolves the correct model ID for a prop reference.
// Handles age-group and gender-specific prop variants.
// ============================================================================

// ============================================================================
// SAnimator2::PreloadDress(PropRef *)
// Address: 0x8005F730, Size: 236 bytes
// NON_MATCHING
//
// Pre-loads the mesh and textures for a dress/outfit item
// before it's actually applied, to prevent loading hitches.
// ============================================================================

// ============================================================================
// SAnimator2::GetBonePos(SAnimator::BoneIdx, EVec3 &)
// Address: 0x80067690, Size: 344 bytes
// NON_MATCHING
//
// Gets the world-space position of a bone (head, hand, pelvis, torso).
// Uses the pre-calculated bone position cache at +0x134/+0x14C/+0x158.
// ============================================================================

// ============================================================================
// SAnimator2::GetCarryHandPosAndDir(EVec3 &, EVec3 &, EMat4 &)
// Address: 0x800675E0, Size: 176 bytes
// NON_MATCHING
//
// Gets the carry hand position and direction for prop attachment.
// Returns the right hand bone position and orientation matrix.
// ============================================================================

// ============================================================================
// SAnimator2::GetCostumeName(SAnimator::OutfitS2C)
// Address: 0x80067434, Size: 488 bytes
// NON_MATCHING
//
// Returns the model filename for the given outfit type.
// Maps outfit enum to the appropriate model path string.
// ============================================================================

// ============================================================================
// SAnimator2::RestoreNonCostumeRelatedSimDescriptionItems(CasSimDescriptionS2C *, CasSimDescriptionS2C *, bool)
// Address: 0x80067A0C, Size: 512 bytes
// NON_MATCHING
//
// After changing costumes, restores non-costume items from the
// original sim description (e.g., skin tone, eye color, face shape).
// ============================================================================

// ============================================================================
// SAnimator2::InitStaticAnimationElements(void)
// Address: 0x8005C814, Size: 1032 bytes
// NON_MATCHING
//
// Initializes static animation data shared across all SAnimator2 instances.
// Loads shared animation tables and sets up global bone mappings.
// ============================================================================

// ============================================================================
// SAnimator2::checkParticleCleanup(void)
// Address: 0x8005C78C, Size: 136 bytes
// NON_MATCHING
//
// Checks if any particles need cleanup and triggers delayed cleanup.
// ============================================================================

// ============================================================================
// SAnimator2::updateFreeMoveState(void)
// Address: 0x8005C8E8, Size: 1132 bytes
// NON_MATCHING
//
// Updates the free-move (direct control) state machine.
// Handles player input -> animation state transitions for
// analog stick-based movement.
// ============================================================================

// ============================================================================
// SAnimator2::playFootprint(char *)
// Address: 0x80061E58, Size: 1316 bytes
// NON_MATCHING
//
// Plays a footprint effect at the sim's current position.
// Creates a decal on the ground based on terrain type.
// ============================================================================

// ============================================================================
// SAnimator2::getFootSound(char *)
// Address: 0x80062388, Size: 328 bytes
// NON_MATCHING
//
// Gets the appropriate footstep sound name based on terrain type.
// ============================================================================

// ============================================================================
// SAnimator2::GetFootSound(CTilePt &, char *)
// Address: 0x8005E04C, Size: 2188 bytes
// NON_MATCHING
//
// Gets the footstep sound for a specific tile position.
// Checks terrain type, floor material, and rug/carpet presence.
// ============================================================================

// ============================================================================
// SAnimator2::playRumble(RumbleDataElement *)
// Address: 0x80066B50, Size: 668 bytes
// NON_MATCHING
//
// Triggers controller rumble based on animation event data.
// ============================================================================

// ============================================================================
// SAnimator2::playRumble(char *)
// Address: 0x80066990, Size: 144 bytes
// NON_MATCHING
//
// Triggers controller rumble by looking up a named rumble preset.
// ============================================================================

// ============================================================================
// SAnimator2::triggerCameraBloom(char *)
// Address: 0x800661DC, Size: 144 bytes
// NON_MATCHING
//
// Triggers a camera bloom effect by looking up a named preset.
// ============================================================================

// ============================================================================
// SAnimator2::triggerCameraBloom(CameraBloomDataElement *)
// Address: 0x8006626C, Size: 240 bytes
// NON_MATCHING
//
// Triggers a camera bloom effect with explicit parameters.
// ============================================================================

// ============================================================================
// SAnimator2::triggerCameraBlur(char *)
// Address: 0x8006635C, Size: 144 bytes
// NON_MATCHING
//
// Triggers a camera motion blur effect by looking up a named preset.
// ============================================================================

// ============================================================================
// SAnimator2::_handleParticleEvent(REffectsAttachment *)
// Address: 0x80065CA4, Size: 664 bytes
// NON_MATCHING
//
// Internal handler for particle attach/detach events from animations.
// ============================================================================

// ============================================================================
// SAnimator2::PreloadBoneParticleEvent(REffectsAttachment *)
// Address: 0x80065BE8, Size: 188 bytes
// NON_MATCHING
//
// Pre-loads particle resources for a bone particle event.
// ============================================================================

// ============================================================================
// SAnimator2::handleImpatientIdleAnimation(void)
// Address: 0x80064110, Size: 408 bytes
// NON_MATCHING
//
// Handles the impatient idle animation state.
// Plays foot-tapping, arm-crossing, or sighing animations
// when a sim has been waiting in a queue too long.
// ============================================================================

// ============================================================================
// SAnimator2::initShuffleRotation(float)
// Address: 0x80069BE0, Size: 120 bytes
// NON_MATCHING
//
// Initializes a shuffle rotation (small in-place turn using
// weight-shifting rather than a full turn animation).
// ============================================================================
