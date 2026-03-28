// camera_decomp.cpp - Camera system decompilation
// The Sims 2 GameCube - Camera System (ESimsCam, CameraDirector, CameraManager, CameraMotionSystem)
//
// Object file: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\camera.obj
//
// ============================================================================
// CAMERA SYSTEM ARCHITECTURE OVERVIEW
// ============================================================================
//
// The camera system is a layered architecture with four primary classes:
//
//   CameraManager (singleton)
//       |
//       +-- ESimsCam[0]  (player 1 camera)
//       +-- ESimsCam[1]  (player 2 camera, splitscreen)
//       |
//       +-- CameraDirector (cutscene/animation camera control)
//              |
//              +-- FrameEffectsManager (bloom, blur, DOF)
//
// CAMERA MODES (ESimsCam::CameraMode stored at offset 0x3CC):
//   0 = FOLLOW_PLAYER     - Default mode, follows the active sim via interactor
//   1 = FOLLOW_SIM_STIFF  - Locked follow of a specific sim (social mode, etc.)
//   2 = RESTORE_PREVIOUS  - Restores mode from m_field3D0 (previous mode backup)
//
// CAMERA STATES (CameraDirector::m_state at offset 0x160):
//   0 = IDLE              - No director control, game camera is active
//   1 = ANIM_PLAYING      - Playing a camera animation (cutscene)
//   2 = HOLD              - Holding current position for m_holdTime seconds
//   3 = INTERP_TO_CUT     - Interpolating from game camera to a cut camera
//   4 = INTERP_HOLD       - Interp complete, waiting or looping
//   5 = INTERP_TO_GAME    - Interpolating back to the game camera
//   6 = ANIM_UPDATE       - Animation is updating pos/FOV each frame
//   7 = CANCEL_CHECK      - Checking/processing a cancel request
//   8 = FADE_OUT          - Camera fading out after animation
//
// CAMERA MOTION TYPES (CameraMotionType):
//   0 = SNAP              - Instantly snap to target position
//   1 = RUBBERBAND        - Smooth rubber-band interpolation toward target
//
// NOISE SETTINGS (CameraNoiseSetting, offset 0x4A8):
//   -1 = NONE             - No camera noise
//    4 = BUILD_MODE        - Subtle noise for build mode
//    5 = ACTIVE            - Active gameplay noise (idle sway)
//    6 = INACTIVE          - Reduced noise when cursor not active
//
// ============================================================================
// DATA FLOW PER FRAME
// ============================================================================
//
// 1. CameraManager::Update() is called each frame
//    - Iterates over registered ESimsCam instances (up to 2 for splitscreen)
//    - Calls each camera's Update() method
//    - Stores the final rotation angle for the active camera
//
// 2. ESimsCam::Update() main loop:
//    a. Validate SimsCameraParameters (min/max bounds)
//    b. Check CursorNotActive state -> set appropriate noise setting
//    c. Query CameraDirector state to determine if director has control
//    d. Based on m_mode:
//       - Mode 0: FollowPlayerInteractor() - tracks the active sim
//       - Mode 1: FollowSimStiff() - rigid follow of a sim
//       - Mode 2: Restore previous mode from m_field3D0
//    e. If not in social/intro interpolation mode:
//       - HandleRotation() - read controller stick input for rotation
//       - HandleZoom() - read controller trigger input for zoom
//       - m_bMoved = (rotationChanged || zoomChanged)
//    f. UpdateWin() - update the 3D window with final eye/target/up
//
// 3. CameraDirector::Update() (runs when director is in control):
//    a. Check current state (m_state at 0x160)
//    b. State machine:
//       - State 1: Check if anim controller reports finished
//       - State 2: Decrement hold timer, release when expired
//       - State 3: Call Interp() to interpolate camera position
//       - State 5: Call Interp() + CalcCancelCam() if cancel requested
//       - State 6: UpdateCameraPosAndFOV() + UpdateAnimNoteTrack()
//       - State 7: CalcCancelCam() + ReleaseCurrentCamera()
//    c. If state != 0: UpdateAnimNoteTrack() for anim events
//    d. BloomInterp() + BlurInterp() if effects interpolation active
//
// ============================================================================

#include "camera/esimscam.h"

// External function declarations
extern "C" void* EAHeap_Alloc(int size);
extern "C" void  EAHeap_FreePtr(void* ptr);
extern "C" void  Vec3_Normalize(EVec3* out, EVec3* in);
extern "C" float Vec3_Length(EVec3* v);
extern "C" float Vec3_Length2(EVec3* v);
extern "C" void  EMat4_Identity(void* mat);
extern "C" void  EMat4_Multiply(void* dst, void* a, void* b);
extern "C" void  ERAnimController_Init(void* ctrl);
extern "C" void  ERAnimController_Release(void* ctrl);
extern "C" void  ERAnim_Stop(void* anim);
extern "C" void  ERAnim_SetAnim(void* anim, int id);
extern "C" void  ERAnim_Play(void* anim, int mode, int blendMode, float blendTime, int startFrame, int flags);
extern "C" void  EGraphics_SetCameraBloom(float r, float g, float b, float a);
extern "C" void  EGraphics_SetMotionBlur(float intensity, float r, float g, float b);

extern void* g_pControllerManager;


// ============================================================================
// CameraMotionSystem - Smooth camera movement via rubber-band interpolation
// ============================================================================
//
// The CameraMotionSystem provides two movement strategies for camera rigs:
//
// 1. SNAP mode: Directly copies rig vectors (eye, target, up) to output
//    positions, then computes a normalized forward direction from
//    (target - eye). Useful for instant camera cuts.
//
// 2. RUBBERBAND mode: Uses spring-like interpolation where the camera
//    smoothly approaches its target position. The stiffness is controlled
//    by SimsCameraParameters fields at offsets 0x4C/0x50/0x54.
//
// Layout (88 bytes total):
//   0x00: CameraMotionType m_motionType
//   0x04: SimsCameraParameters* m_pParams
//   0x08: EVec3 m_rigEye       (12 bytes) - target eye position from SetRig
//   0x14: EVec3 m_rigTarget    (12 bytes) - target look-at from SetRig
//   0x20: EVec3 m_rigUp        (12 bytes) - target up vector from SetRig
//   0x2C: EVec3 m_currentEye   (12 bytes) - actual interpolated eye
//   0x38: EVec3 m_currentTarget(12 bytes) - actual interpolated target
//   0x44: EVec3 m_currentUp    (12 bytes) - actual interpolated up
//   0x50: EVec3 m_forward      (12 bytes) - normalized forward direction
//

// 0x800160B8 - 88 bytes
// NON_MATCHING: register allocation differs
void CameraMotionSystem::SetRig(EVec3& eye, EVec3& target, EVec3& up) {
    // Copy eye vector (3 words via integer copy for exact bit pattern)
    u32* src = (u32*)&eye;
    u32* dstEye = (u32*)((u8*)this + 0x08);
    dstEye[0] = src[0];
    dstEye[1] = src[1];
    dstEye[2] = src[2];

    // Copy target vector
    src = (u32*)&target;
    u32* dstTarget = (u32*)((u8*)this + 0x14);
    dstTarget[0] = src[0];
    dstTarget[1] = src[1];
    dstTarget[2] = src[2];

    // Copy up vector
    src = (u32*)&up;
    u32* dstUp = (u32*)((u8*)this + 0x20);
    dstUp[0] = src[0];
    dstUp[1] = src[1];
    dstUp[2] = src[2];
}

// 0x80016110 - 268 bytes
// Snap: copies rig directly to current, computes forward = normalize(target - eye)
// NON_MATCHING: SN Systems register scheduling
void CameraMotionSystem::SnapCamera() {
    u8* self = (u8*)this;

    // Copy rig eye -> current eye (offset 0x08 -> 0x2C)
    EVec3* rigEye = (EVec3*)(self + 0x08);
    EVec3* curEye = (EVec3*)(self + 0x2C);
    curEye->x = rigEye->x;
    curEye->y = rigEye->y;
    curEye->z = rigEye->z;

    // Copy rig target -> current target (offset 0x14 -> 0x38)
    EVec3* rigTarget = (EVec3*)(self + 0x14);
    EVec3* curTarget = (EVec3*)(self + 0x38);
    curTarget->x = rigTarget->x;
    curTarget->y = rigTarget->y;
    curTarget->z = rigTarget->z;

    // Copy rig up -> current up (offset 0x20 -> 0x44)
    EVec3* rigUp = (EVec3*)(self + 0x20);
    EVec3* curUp = (EVec3*)(self + 0x44);
    curUp->x = rigUp->x;
    curUp->y = rigUp->y;
    curUp->z = rigUp->z;

    // Compute forward direction = curTarget - curEye
    EVec3 forward;
    forward.x = curTarget->x - curEye->x;
    forward.y = curTarget->y - curEye->y;
    forward.z = curTarget->z - curEye->z;

    // Only normalize if not zero vector
    if (forward.x != 0.0f || forward.y != 0.0f || forward.z != 0.0f) {
        Vec3_Normalize(&forward, &forward);
    }

    // Store forward at offset 0x50
    EVec3* fwd = (EVec3*)(self + 0x50);
    fwd->x = forward.x;
    fwd->y = forward.y;
    fwd->z = forward.z;
}

// 0x80016258 - 324 bytes
// Spring interpolation: moves *result toward target using velocity and damping
// NON_MATCHING: FP register allocation differs
void CameraMotionSystem::RubberBandInterpolate(EVec3* result, EVec3 target, float dt) {
    // Compute displacement from result to target
    EVec3 disp;
    disp.x = target.x - result->x;
    disp.y = target.y - result->y;
    disp.z = target.z - result->z;

    // Get length of displacement
    float len = Vec3_Length2(&disp);

    // If very close (within threshold), snap directly
    if (len <= 0.0f) {  // threshold from float constant at r9-7440
        result->x = target.x;
        result->y = target.y;
        result->z = target.z;
        return;
    }

    // Get stiffness parameters from SimsCameraParameters
    SimsCameraParameters* params = m_pParams;
    float stiffness;
    if (len > *(float*)((u8*)params + 0x4C)) {
        stiffness = *(float*)((u8*)params + 0x50);  // high stiffness for far distances
    } else {
        stiffness = *(float*)((u8*)params + 0x54);  // low stiffness for close distances
    }

    // velocity = stiffness * len * dt
    float speed = stiffness * len;
    float velocity = speed * dt;

    // Clamp velocity to not overshoot
    if (velocity > len) {
        velocity = len;
    }

    // Normalize displacement and scale by velocity
    float invLen = 1.0f / len;
    disp.x *= invLen;
    disp.y *= invLen;
    disp.z *= invLen;

    // Apply velocity along normalized direction
    result->x += disp.x * velocity;
    result->y += disp.y * velocity;
    result->z += disp.z * velocity;
}

// 0x8001639C - 312 bytes
// RubberBandMove: interpolates eye, target, up toward rig using RubberBandInterpolate,
// then recomputes forward direction
// NON_MATCHING: SN Systems codegen
void CameraMotionSystem::RubberBandMove(float dt) {
    u8* self = (u8*)this;

    // Interpolate current eye toward rig eye
    EVec3 tempEye;
    EVec3* rigEye = (EVec3*)(self + 0x08);
    EVec3* curEye = (EVec3*)(self + 0x2C);
    tempEye = *curEye;
    RubberBandInterpolate(&tempEye, *rigEye, dt);

    // Interpolate current target toward rig target
    EVec3 tempTarget;
    EVec3* rigTarget = (EVec3*)(self + 0x14);
    EVec3* curTarget = (EVec3*)(self + 0x38);
    tempTarget = *curTarget;
    RubberBandInterpolate(&tempTarget, *rigTarget, dt);

    // Copy rig up directly to current up (no interpolation on up vector)
    EVec3* rigUp = (EVec3*)(self + 0x20);
    EVec3* curUp = (EVec3*)(self + 0x44);
    curUp->x = rigUp->x;
    curUp->y = rigUp->y;
    curUp->z = rigUp->z;

    // Compute forward = curTarget - curEye
    EVec3 forward;
    forward.x = curTarget->x - curEye->x;
    forward.y = curTarget->y - curEye->y;
    forward.z = curTarget->z - curEye->z;

    if (forward.x != 0.0f || forward.y != 0.0f || forward.z != 0.0f) {
        Vec3_Normalize(&forward, &forward);
    }

    // Store forward at offset 0x50
    EVec3* fwd = (EVec3*)(self + 0x50);
    fwd->x = forward.x;
    fwd->y = forward.y;
    fwd->z = forward.z;
}


// ============================================================================
// ESimsCam::Update - Main camera update loop (512 bytes)
// ============================================================================
//
// This is the central per-frame update for ESimsCam. It orchestrates:
// 1. Parameter validation
// 2. Noise setting based on cursor activity
// 3. CameraDirector integration (checking if director controls the camera)
// 4. Camera mode dispatch (follow player, follow sim stiff, or restore)
// 5. Controller input for rotation and zoom
// 6. 3D window update with final camera matrices
//

// 0x80016DB8 - 512 bytes
// NON_MATCHING: GCC vs SN Systems codegen differences
void ESimsCam::Update() {
    // Step 1: Validate camera parameters (clamp zoom bounds etc.)
    m_pParams->Validate();

    // Step 2: Check cursor activity for noise settings
    // CursorNotActive() returns whether cursor hasn't moved recently
    int cursorInactive = CursorNotActive();
    if (cursorInactive) {
        // Cursor is not active - use subtle noise (setting 5 = ACTIVE)
        SetActiveNoiseSetting(5);
    } else {
        // Cursor is active - use reduced noise (setting 6 = INACTIVE)
        SetActiveNoiseSetting(6);
    }

    // Step 3: Check if CameraDirector has control
    // Looks up the CameraDirector instance via global table at 0x80475dcc
    // The director is indexed by player ID
    // If the director is in a non-idle/non-fade state, it controls the camera
    u32* globalTable = (u32*)0x80475dcc; // approximate - resolved at link time
    int playerId = m_playerId;
    u32 directorPtr = globalTable[0xBC / 4 + playerId]; // director array
    if (directorPtr != 0) {
        // Get the director's current state
        u32 dirState = *(u32*)(directorPtr + 0x160);
        bool directorInControl = (dirState != 0 && dirState != 8);

        if (directorInControl) {
            // Check if we're in a social mode interaction
            // Look up interactor for this player, check type == 17 (social)
            bool inSocialMode = false; // simplified - actual code does vtable call
            if (inSocialMode && cursorInactive) {
                // Interacting sim in social mode + cursor active = build mode noise
                SetActiveNoiseSetting(4);
            }

            // If noise is currently set to build mode but we're leaving
            if (m_activeNoiseSetting == 4) {
                SetActiveNoiseSetting(-1);  // clear noise
            }
        }
    }

    // Step 4: Camera mode dispatch
    // Check if director is in a non-controlling state
    u32 directorPtr2 = globalTable[0x118 / 4 + playerId]; // another director ref
    if (directorPtr2 != 0) {
        u32 dirState2 = *(u32*)(directorPtr2 + 0x160);
        if (dirState2 != 8) {
            // Director not in fade-out state
            switch (m_mode) {
                case 0: // FOLLOW_PLAYER
                    FollowPlayerInteractor(playerId);
                    break;
                case 1: // FOLLOW_SIM_STIFF
                    FollowSimStiff();
                    break;
                case 2: // RESTORE_PREVIOUS
                    // Not handled in this path
                    break;
            }
        }
    }

    // Step 5: Handle controller input for rotation and zoom
    // Only process input if not interpolating to/from social mode camera
    //   and not interpolating from lot intro camera
    if (m_interpSocialMode == 0 && m_interpLotIntro == 0) {
        int rotChanged = HandleRotation();
        int zoomChanged = HandleZoom();
        // Set moved flag if either changed
        m_bMoved = (rotChanged != 0 || zoomChanged != 0) ? 1 : 0;
    } else {
        m_bMoved = 0;
    }

    // Step 6: Update the 3D viewport window
    UpdateWin();
}


// ============================================================================
// ESimsCam::SetMode - Switch camera modes with previous mode backup
// ============================================================================
//
// The mode system uses a simple "current + previous" pattern:
//   m_mode (0x3CC) = active camera mode
//   m_field3D0 (0x3D0) = previous mode (for restore)
//
// When mode 2 (RESTORE) is requested, it loads m_field3D0 as the new mode.
// This allows the camera to temporarily switch modes (e.g., for social
// interactions) and then restore to the previous behavior.
//

// 0x80016BD4 - 96 bytes
// NON_MATCHING: conditional return codegen
void ESimsCam::SetMode(ESimsCam::CameraMode newMode) {
    // Check if the CameraDirector is in control
    u32* globalTable = (u32*)0x80475dcc; // link-time resolved
    u32 dirPtr = globalTable[0x118 / 4 + m_playerId];
    if (dirPtr != 0) {
        u32 dirState = *(u32*)(dirPtr + 0x160);
        bool directorInControl = (dirState != 0 && dirState != 8);
        if (directorInControl) {
            return; // Director has camera control, ignore mode changes
        }
    }

    // If mode == 2 (RESTORE), load previous mode instead
    if ((int)newMode == 2) {
        newMode = (ESimsCam::CameraMode)m_field3D0;
    }

    // Swap current and previous modes
    u32 oldMode = m_mode;
    m_mode = (u32)newMode;
    m_field3D0 = oldMode;
}


// ============================================================================
// CameraDirector::Update - Director state machine (1360 bytes)
// ============================================================================
//
// The CameraDirector manages scripted camera sequences (cutscenes, social
// interactions, lot introductions). It operates as a state machine:
//
// State transitions:
//   IDLE(0) -> INTERP_TO_CUT(3) : When SetCameraCut/SetCameraInterp called
//   INTERP_TO_CUT(3) -> INTERP_HOLD(4) : When interpolation completes
//   INTERP_HOLD(4) -> INTERP_TO_GAME(5) : When releasing back to game
//   INTERP_TO_GAME(5) -> IDLE(0) : When interpolation back completes
//   Any -> CANCEL_CHECK(7) : When player requests cancel (B button)
//   CANCEL_CHECK(7) -> IDLE(0) : After cancel processing
//   IDLE(0) -> ANIM_PLAYING(1) : When StartAnim() called
//   ANIM_PLAYING(1) -> ANIM_UPDATE(6) : Anim begins updating
//   ANIM_UPDATE(6) -> IDLE(0) : Anim finishes and cleans up
//
// The director also manages BloomInterp() and BlurInterp() for
// effects interpolation during camera transitions.
//

// 0x8001D644 - 1360 bytes
// NON_MATCHING: GCC vs SN Systems codegen, register scheduling
void CameraDirector::Update() {
    u8* self = (u8*)this;
    u32 state = m_state;

    // Check if director is in control (state != 0 and state != 8)
    bool inControl = (state != 0 && state != 8);

    if (inControl) {
        // Check for cancel request
        int cancelled = CheckCancelled();
        if (cancelled) {
            if (state != 7) { // not already in cancel state
                // Transition to cancel: interp back to game camera over ~0.5s
                *(u32*)(self + 0x238) = 2; // set cancel mode
                InterpToCancelCamera(0.5f, 0, false);
            }
        }
    }

    // State machine dispatch
    switch (state) {
        case 4: // INTERP_HOLD - check if hold anim completed
        case 5: // INTERP_TO_GAME
            if (*(u32*)(self + 0x198) != 0) {
                // Anim/interp still running
                Interp();
                *(u32*)(self + 0x198) = 0; // original stores return to m_state
            } else {
                ReleaseCurrentCamera();
            }
            break;

        case 3: // INTERP_TO_CUT
            if (*(u32*)(self + 0x198) != 0) {
                // Still interpolating
                // Identity the offset matrix, apply dummy attachment if present
                EMat4_Identity(self + 0x80);
                // Apply attached dummy transforms if m_attachedDummy (0x118) set
                if (*(u32*)(self + 0x118) != 0) {
                    // Multiply dummy matrix into offset
                }
                if (*(u32*)(self + 0x11C) != 0) {
                    // Multiply second dummy
                }

                // Set camera from current interp state
                float fov = *(float*)(self + 0x1A0);
                SetFOV(fov);

                // Transition to state 1 (ANIM_PLAYING)
                *(u32*)(self + 0x160) = 1; // m_state = ANIM_PLAYING

                // If attached camera dummy exists, reset animation
                if (*(u32*)(self + 0x230) != 0) {
                    EMat4_Identity(self + 0x80);
                    // Apply dummy offset...
                }
            }
            break;

        case 7: // CANCEL_CHECK
            // Set noise to nothing on the attached camera
            if (*(u32*)(self + 0x170) != 0) { // m_pCurrentCamera
                ((ESimsCam*)*(u32*)(self + 0x170))->SetActiveNoiseSetting(0);
            }
            // Check cancel timer
            if (*(u32*)(self + 0x23C) != 0) {
                CalcCancelCam();
            } else {
                ReleaseCurrentCamera();
            }
            break;

        case 6: // ANIM_UPDATE
            UpdateCameraPosAndFOV();
            {
                // Check if anim controller has reached end
                void* animCtrl = (void*)(self + 0x1A8);
                // ERAnim::IsFinished check via vtable at offset +0x08
                bool animFinished = false; // simplified
                if (animFinished) {
                    *(u32*)(self + 0x160) = 1; // back to ANIM_PLAYING
                    // If note track has end marker, stop anim
                    ERAnim_Stop(animCtrl);
                    *(u32*)(self + 0x220) = 0;
                    *(float*)(self + 0x22C) = 0.0f;
                }
            }
            break;

        case 1: // ANIM_PLAYING
            {
                // Check if animation controller is still active
                void* animCtrl = (void*)(self + 0x1A8);
                // Release if finished
                bool released = false; // ERAnimController::IsReleased
                if (!released) {
                    UpdateCameraPosAndFOV();
                }
                // Check for pending state transition
                u32 pendingState = *(u32*)(self + 0x164);
                if (pendingState != 0) {
                    *(u32*)(self + 0x160) = pendingState;
                    *(u32*)(self + 0x164) = 0;
                }
            }
            break;

        case 2: // HOLD
            {
                float holdTime = *(float*)(self + 0x168);
                if (holdTime > 0.0f) {
                    // Check if the game is paused
                    // Decrement hold timer by frame delta time
                    float dt = 0.0f; // read from global timer at r13-22732
                    holdTime -= dt;
                    *(float*)(self + 0x168) = holdTime;
                    if (holdTime < 0.0f) {
                        // Hold expired - release camera
                        ReleaseCurrentCamera();
                        *(u32*)(self + 0x160) = 0; // IDLE
                    }
                }
            }
            break;
    }

    // If director is in a non-idle state, update animation note track
    if (*(u32*)(self + 0x160) != 0) {
        UpdateAnimNoteTrack();
    }
}


// ============================================================================
// CameraDirector::BloomInterp - Interpolate bloom parameters each frame
// ============================================================================
//
// During camera animations, bloom effect parameters are interpolated between
// start and end values. The interpolation uses a normalized time value t
// computed from the bloom timer at offset 0x2D4.
//
// The bloom parameters being interpolated are:
//   - Intensity (RGBA components at offsets 0x2EC-0x2F8)
//   - These are interpolated to final values at 0x2DC-0x2E8
//
// The formula is: result = startVal * t + endVal * (1 - t)
//   where t = bloomTimer * bloomSpeed (clamped to [0, 1])
//
// When t >= 1.0, the interpolation is complete and the bloom interp flag
// at offset 0x31C is cleared (bit 0 masked off).
//

// 0x8001E540 - 176 bytes
// NON_MATCHING: FP register allocation
void CameraDirector::BloomInterp() {
    u8* self = (u8*)this;

    // Compute normalized time t
    float bloomTimer = *(float*)(self + 0x2D4);
    float bloomSpeed = 1.0f; // loaded from constant pool at r9-6684
    float t = bloomTimer * bloomSpeed;

    float maxT = 1.0f; // loaded from constant pool at r11-6680
    if (t >= maxT) {
        t = maxT;
        // Clear bloom interp bit in flags at 0x31C
        u32 flags = *(u32*)(self + 0x31C);
        flags &= ~1; // clear bit 0
        *(u32*)(self + 0x31C) = flags;
    }

    // Interpolate: result = endVal * (1-t) + startVal * t
    float oneMinusT = maxT - t;

    // End bloom values (at offsets 0x2EC..0x2F8)
    float endR = *(float*)(self + 0x2EC);
    float endG = *(float*)(self + 0x2F0);
    float endB = *(float*)(self + 0x2F4);
    float endA = *(float*)(self + 0x2F8);

    // Start bloom values (at offsets 0x2DC..0x2E8)
    float startR = *(float*)(self + 0x2DC);
    float startG = *(float*)(self + 0x2E0);
    float startB = *(float*)(self + 0x2E4);
    float startA = *(float*)(self + 0x2E8);

    // Compute interpolated RGBA
    float r = t * endR + oneMinusT * startR;
    float g = t * endG + oneMinusT * startG;
    float b = t * endB + oneMinusT * startB;
    float a = t * endA + oneMinusT * startA;

    // Apply bloom via EGraphics (calls through global singleton at r13-26392)
    EGraphics_SetCameraBloom(r, g, b, a);
}


// ============================================================================
// CameraDirector::BlurInterp - Interpolate motion blur parameters each frame
// ============================================================================
//
// Same pattern as BloomInterp but for motion blur. Uses a separate timer
// at offset 0x2D8 and separate parameter ranges (0x2FC-0x318).
//
// Motion blur parameters:
//   Start: intensity(0x30C), r(0x310), g(0x314), b(0x318)
//   End:   intensity(0x2FC), r(0x300), g(0x304), b(0x308)
//

// 0x8001E5F0 - 156 bytes
// NON_MATCHING: FP register allocation
void CameraDirector::BlurInterp() {
    u8* self = (u8*)this;

    // Compute normalized time
    float blurTimer = *(float*)(self + 0x2D8);
    float blurSpeed = 1.0f; // from constant pool
    float t = blurTimer * blurSpeed;

    float maxT = 1.0f;
    if (t >= maxT) {
        t = maxT;
        // Clear blur interp bit in flags at 0x31C
        u32 flags = *(u32*)(self + 0x31C);
        flags &= ~2; // clear bit 1
        *(u32*)(self + 0x31C) = flags;
    }

    float oneMinusT = maxT - t;

    // End blur values
    float endIntensity = *(float*)(self + 0x2FC);
    float endR         = *(float*)(self + 0x300);
    float endG         = *(float*)(self + 0x304);
    float endB         = *(float*)(self + 0x308);

    // Start blur values
    float startIntensity = *(float*)(self + 0x30C);
    float startR         = *(float*)(self + 0x310);
    float startG         = *(float*)(self + 0x314);
    float startB         = *(float*)(self + 0x318);

    float intensity = t * endIntensity + oneMinusT * startIntensity;
    float r         = t * endR         + oneMinusT * startR;
    float g         = t * endG         + oneMinusT * startG;
    float b         = t * endB         + oneMinusT * startB;

    // Apply motion blur directly via EGraphics
    EGraphics_SetMotionBlur(intensity, r, g, b);
}


// ============================================================================
// CameraManager::Update - Per-frame update of all registered cameras
// ============================================================================
//
// The CameraManager is a singleton (static pointer at CameraManager::s_pCameraManager
// in .sdata at 0x804FD980). It holds up to 2 camera instances for splitscreen.
//
// Layout:
//   0x000: ESimsCam* m_cameras[0]  - Player 1 camera (or NULL)
//   0x004: ESimsCam* m_cameras[1]  - Player 2 camera (or NULL)
//   ...
//   0x11C: u32  - unknown field checked in Update
//   0x56C: u32  - unknown field checked in Update
//
// Update flow:
//   1. If camera[0] exists:
//      a. Call the global "CalcCameraTarget" helper with director params
//      b. Call camera[0]->Update() via vtable at offset 0x56C
//      c. Read camera[0]->rotAng (offset 0x44C) and store to global
//   2. If camera[1] exists (splitscreen):
//      a. Same as above for player 2
//   3. Call global "CalcCameraTarget" for the combined/main director
//

// 0x8001EB80 - 208 bytes
// NON_MATCHING: global address resolution
void CameraManager::Update() {
    u8* self = (u8*)this;

    // Global director table
    u32* dirTable = (u32*)0x80475dcc; // link-time resolved

    // Save current director cam (dirTable[0xE0/4])
    u32 savedDirectorCam = dirTable[0xE0 / 4];

    // Update camera[0] if registered
    ESimsCam* cam0 = m_cameras[0];
    if (cam0 != 0) {
        // CalcCameraTarget for player 0's director
        // cam0->Update() via vtable dispatch at offset 0x56C
        // Read cam0->m_targetParams.data[4] (rotAng at 0x44C) -> store to director

        // Actual call: vtable at (cam0 + 0x56C)->vfunc[4] which is cam->Update()
        cam0->Update();
    }

    // Update camera[1] if registered (splitscreen)
    ESimsCam* cam1 = m_cameras[1];
    if (cam1 != 0) {
        cam1->Update();
    }

    // Final CalcCameraTarget call with savedDirectorCam
}

// 0x8001EC50 - 68 bytes
// CameraManager* CameraManager::GetSingleton()
// Returns the static singleton. Creates one via EAHeap_Alloc if NULL.
// NON_MATCHING: SN Systems codegen
/*
CameraManager* CameraManager::GetSingleton() {
    static CameraManager* s_pCameraManager = 0; // at 0x804FD980
    if (s_pCameraManager == 0) {
        s_pCameraManager = (CameraManager*)EAHeap_Alloc(sizeof(CameraManager));
        // zero-init
    }
    return s_pCameraManager;
}
*/

// 0x8001ECA0 - 12 bytes
// slwi r4, r4, 2; lwzx r3, r3, r4
ESimsCam* CameraManager::GetCamera(int index) {
    return m_cameras[index];
}


// ============================================================================
// CameraDirector::BeginCameraBloomInterp
// ============================================================================
//
// Initiates a bloom effect interpolation during a camera cut/transition.
// Stores the start and end bloom RGBA values and resets the timer.
//
// CameraBloomDataElement layout (inferred from disassembly):
//   0x00: float startR, startG, startB, startA  (16 bytes)
//   0x10: float endR, endG, endB, endA          (16 bytes)
//   0x20: float interpSpeed                      (4 bytes)
//

// 0x8001E4C0 - 128 bytes
// NON_MATCHING: register scheduling
void CameraDirector::BeginCameraBloomInterp(CameraBloomDataElement* bloomData) {
    u8* self = (u8*)this;

    // Copy start bloom values from bloomData to director offsets 0x2DC-0x2E8
    u32* src = (u32*)bloomData;
    *(u32*)(self + 0x2DC) = src[0];
    *(u32*)(self + 0x2E0) = src[1];
    *(u32*)(self + 0x2E4) = src[2];
    *(u32*)(self + 0x2E8) = src[3];

    // Copy end bloom values to offsets 0x2EC-0x2F8
    *(u32*)(self + 0x2EC) = src[4];
    *(u32*)(self + 0x2F0) = src[5];
    *(u32*)(self + 0x2F4) = src[6];
    *(u32*)(self + 0x2F8) = src[7];

    // Reset bloom timer
    *(float*)(self + 0x2D4) = 0.0f;

    // Set bloom interp flag (bit 0 of flags at 0x31C)
    u32 flags = *(u32*)(self + 0x31C);
    flags |= 1;
    *(u32*)(self + 0x31C) = flags;
}


// ============================================================================
// CAMERA PARAMETER INTERPOLATION
// ============================================================================
//
// ESimsCam uses a dual-parameter system for smooth camera movement:
//
//   m_targetParams (offset 0x43C, 24 bytes):
//     The "desired" camera state. Updated by mode logic, controller input.
//     data[0-2] = target position XYZ
//     data[3]   = zoom level
//     data[4]   = rotation angle (radians)
//     data[5]   = tilt angle (radians)
//
//   m_actualParams (offset 0x454, 24 bytes):
//     The "current" camera state. Interpolated toward target each frame.
//     Same layout as target params.
//
// InterpolateActualCameraParamsToTarget() uses per-axis stiffness values
// from SimsCameraParameters to smoothly move actual toward target.
// The stiffness varies with zoom level (closer zoom = stiffer response).
//
// CalcTranslationStiffness(), CalcRotationStiffness(), CalcZoomStiffness()
// all use InterpolateLinear<float> to map the current zoom level to a
// stiffness value between min and max.
//

// ============================================================================
// CONTROLLER INPUT HANDLING
// ============================================================================
//
// ReadControllerRotation (0x8001AE0C, 84 bytes):
//   Reads the right analog stick X-axis from the GameCube controller.
//   Uses m_controllerFilterId to select the correct input source.
//   Returns the raw stick value which HandleRotation() applies as
//   a rotation delta to m_targetParams.data[4] (rotAng).
//
// ReadControllerZoom (0x8001ADB8, 84 bytes):
//   Reads the L/R trigger values from the controller.
//   Zoom in (L trigger) decreases zoom, zoom out (R trigger) increases.
//   The delta is applied to m_targetParams.data[3] (zoom).
//
// HandleRotation (0x8001709C, 588 bytes):
//   Calls ReadControllerRotation(), applies dead zone filtering,
//   scales by rotation speed (from SimsCameraParameters), and
//   adds the rotation delta to m_targetParams.data[4].
//   Returns 1 if rotation changed, 0 otherwise.
//
// HandleZoom (0x800172E8, 424 bytes):
//   Calls ReadControllerZoom(), applies dead zone filtering,
//   scales by zoom speed (from SimsCameraParameters), and
//   applies the zoom delta via ApplyZoom().
//   Also recalculates tilt from the new zoom level via CalcTiltFromZoom().
//   Returns 1 if zoom changed, 0 otherwise.
//


// ============================================================================
// CAMERA NOISE SYSTEM
// ============================================================================
//
// The camera noise system adds subtle procedural motion to the camera to
// make it feel "alive" rather than rigidly following a position.
//
// SetActiveNoiseSetting() selects a noise profile:
//   - Each profile has amplitude and frequency parameters
//   - Noise is applied in ApplyNoise() which adds sinusoidal perturbation
//     to the eye and target positions
//   - The noise fields are stored at offsets 0x4A8-0x4C4
//
// ApplyNoise (0x8001A424, 1616 bytes):
//   The largest function in the camera system. It computes Perlin-like
//   noise by combining multiple sine waves at different frequencies.
//   The noise is applied separately to the eye, target, and up vectors.
//   The amplitude scales with zoom level (less noise when zoomed in).
//
