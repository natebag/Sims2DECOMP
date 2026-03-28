// effects_decomp.cpp - Frame Effects system decompilation
// The Sims 2 GameCube - Frame Effects (FrameEffectsManager, Bloom, MotionBlur, DepthOfField)
//
// Object files:
//   c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\frameeffects.obj
//   c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\frameeffects_ngc.obj
//
// ============================================================================
// FRAME EFFECTS PIPELINE OVERVIEW
// ============================================================================
//
// The frame effects system applies full-screen post-processing effects to the
// rendered frame on the GameCube. Three effects are supported:
//
//   1. Bloom    - Glow/HDR-like effect for bright areas
//   2. MotionBlur - Temporal blur for camera movement
//   3. DepthOfField - Focus/defocus based on distance from camera
//
// Architecture:
//
//   FrameEffectsManager (owns all three effect objects)
//       |
//       +-- MotionBlur* m_pMotionBlur     (offset 0x00)
//       +-- Bloom*      m_pBloom          (offset 0x04)
//       +-- DepthOfField* m_pDepthOfField (offset 0x08)
//
// Each effect derives from FrameEffect (base class with enable/disable state
// machine and fade timing) and has a platform-specific NGC renderer class
// that handles the actual GPU operations.
//
// Inheritance hierarchy:
//
//   FrameEffect (base - state machine, fade timing)
//       |
//       +-- MotionBlur (target settings, interpolation)
//       |       +-- MotionBlurNGC (GC-specific GX draw commands)
//       |
//       +-- Bloom (target settings, interpolation, mip chain)
//       |       +-- BloomNGC (GC-specific GX draw commands, mip surfaces)
//       |
//       +-- DepthOfField (focal parameters, circle of confusion)
//               +-- DepthOfFieldNGC (GC-specific GX draw commands)
//
// RENDERING PIPELINE:
//
//   1. Main scene is rendered to the framebuffer normally
//   2. ENgcRenderer::DrawFrameWithBloomAndMotionBlur() is called
//   3. For each active effect:
//      a. FrameEffect::Update() advances the effect state machine
//      b. The NGC subclass's Draw(ERC*) performs GX texture operations:
//         - Copies framebuffer to texture (EFB to texture copy)
//         - Applies shader/filter passes
//         - Blends result back onto framebuffer
//   4. ENgcGraphics::ProcessFrameEffects() finalizes the compositing
//
// EFFECT STATE MACHINE (FrameEffect::EffectState at offset 0x0C):
//   1 = DISABLED      - Effect is off (idle state)
//   2 = FADING_IN     - Effect is ramping up (increasing intensity)
//   4 = ACTIVE        - Effect is fully on at target parameters
//   8 = FADING_OUT    - Effect is ramping down (decreasing intensity)
//
//   State transitions:
//     DISABLED(1) --Enable(true)--> FADING_IN(2)
//     FADING_IN(2) --fade complete--> ACTIVE(4) [calls EffectStateChanged]
//     ACTIVE(4) --Enable(false)--> FADING_OUT(8)
//     FADING_OUT(8) --fade complete--> DISABLED(1) [calls EffectStateChanged]
//
// EFFECT TIMING:
//   Offset 0x08: float m_timer        - Accumulated time since state change
//   Offset 0x0C: u32   m_state        - Current EffectState enum
//   Offset 0x10: void* m_pVtable      - Points to concrete effect's vtable
//
//   The vtable contains function pointers for:
//     +0x08: EffectStateChanged(EffectState) - called on state transitions
//     +0x10: UpdateTargetParameters(float)   - interpolate parameters
//     +0x14: UpdateTuningUI()                - debug UI update
//     +0x18: Draw(ERC*)                      - platform-specific rendering
//     +0x20: EffectIsFinishedFadingIn(float) - check if fade-in complete
//     +0x24: EffectIsFinishedFadingOut(float)- check if fade-out complete
//
// ============================================================================

#include "types.h"

// Forward declarations
class ERC;
class ETexture;

// External functions
extern "C" void* EAHeap_Alloc(int size);
extern "C" void  EAHeap_FreePtr(void* ptr);

// ============================================================================
// FrameEffect base class vtable layout (from 0x8046D748)
// ============================================================================
//
//   +0x00: destructor
//   +0x04: destructor (variant)
//   +0x08: EffectStateChanged(EffectState)
//   +0x0C: SetEffectState(EffectState)  -- not virtual, but pointer stored
//   +0x10: UpdateTargetParameters(float)
//   +0x14: UpdateTuningUI()
//   +0x18: Draw(ERC*)
//   +0x1C: (reserved)
//   +0x20: EffectIsFinishedFadingIn(float) const
//   +0x24: EffectIsFinishedFadingOut(float) const
//   +0x28: SetFadeInTime(float)
//   +0x2C: SetFadeOutTime(float)
//   +0x30: EffectStateChanged(EffectState) -- vtable entry
//
// Each derived class (Bloom, MotionBlur, DepthOfField) replaces the
// virtual entries with its own implementations. The NGC subclasses
// (BloomNGC, etc.) override the Draw entry.
//


// ============================================================================
// FrameEffect - Base effect state machine
// ============================================================================
//
// Size: 20 bytes (0x14) for base, extended by derived classes
// Layout:
//   0x00: float m_fadeInTime    - Duration of fade-in transition (seconds)
//   0x04: float m_fadeOutTime   - Duration of fade-out transition (seconds)
//   0x08: float m_timer         - Accumulated time in current state
//   0x0C: u32   m_state         - Current EffectState
//   0x10: void* m_pVtable       - Pointer to vtable (with virtual dispatch thunks)
//

struct FrameEffect {
    float m_fadeInTime;       // 0x00
    float m_fadeOutTime;      // 0x04
    float m_timer;            // 0x08
    u32   m_state;            // 0x0C - EffectState enum
    void* m_pConcreteClass;   // 0x10 - pointer to concrete derived class

    enum EffectState {
        STATE_DISABLED   = 1,
        STATE_FADING_IN  = 2,
        STATE_ACTIVE     = 4,
        STATE_FADING_OUT = 8
    };

    void Enable(bool enable);
    void Update(float dt, ERC* rc);
    bool IsEffectRamping() const;
    bool IsEffectRunning() const;
    void UpdateEffectState();
};


// 0x80356FB0 - 112 bytes
// Enable/disable effect with state transition
// NON_MATCHING: SN Systems conditional branch codegen
void FrameEffect::Enable(bool enable) {
    if (!enable) {
        // If already disabled, do nothing
        if (m_state == STATE_DISABLED) {
            return;
        }
    }

    // Set new state based on enable flag
    EffectState newState;
    if (!enable) {
        newState = STATE_FADING_OUT;
    } else {
        newState = STATE_FADING_IN;
    }

    m_state = newState;

    // Call EffectStateChanged on the concrete class via vtable
    // vtable at m_pConcreteClass offset 0x20/0x24
    // Simplified: the actual code does indirect vtable dispatch
    // ((ConcreteClass*)m_pConcreteClass)->EffectStateChanged(newState);

    // Reset timer to 0
    m_timer = 0.0f;
}


// 0x80357020 - 148 bytes
// Per-frame update: advances timer, calls UpdateTargetParameters if ramping,
// calls Draw if running, then processes state transitions
// NON_MATCHING: vtable dispatch codegen
void FrameEffect::Update(float dt, ERC* rc) {
    // Advance timer
    m_timer += dt;

    // If effect is ramping (fading in or out), update target parameters
    if (IsEffectRamping()) {
        // Call UpdateTargetParameters(m_timer) via vtable on concrete class
        // The concrete class interpolates between start/end parameter sets
        // based on the current timer value
    }

    // If effect is running (fading in, active, or fading out), call Draw
    if (IsEffectRunning()) {
        // Call Draw(rc) via vtable on concrete class
        // This performs the actual GX rendering operations
    }

    // Process state transitions (check if fade complete)
    UpdateEffectState();
}


// 0x803570B4 - 32 bytes
// Returns true if effect is in FADING_IN or FADING_OUT state
bool FrameEffect::IsEffectRamping() const {
    return (m_state == STATE_FADING_IN || m_state == STATE_FADING_OUT);
}


// 0x803570D4 - 24 bytes
// Returns true if effect is in any active state (not DISABLED)
bool FrameEffect::IsEffectRunning() const {
    return (m_state != STATE_DISABLED);
}


// 0x803570EC - 212 bytes
// Check if fade transitions have completed and advance state
// NON_MATCHING: vtable dispatch codegen
void FrameEffect::UpdateEffectState() {
    if (m_state == STATE_FADING_IN) {
        // Check if fade-in is complete via vtable call
        // EffectIsFinishedFadingIn(m_timer) returns true when
        // m_timer >= m_fadeInTime
        bool finished = false; // vtable dispatch simplified
        if (finished) {
            m_state = STATE_ACTIVE;
            // Notify concrete class: EffectStateChanged(STATE_ACTIVE)
        }
    }
    else if (m_state == STATE_FADING_OUT) {
        // Check if fade-out is complete via vtable call
        bool finished = false; // vtable dispatch simplified
        if (finished) {
            m_state = STATE_DISABLED;
            // Notify concrete class: EffectStateChanged(STATE_DISABLED)
        }
    }
}


// ============================================================================
// BLOOM EFFECT
// ============================================================================
//
// The bloom effect adds a glow to bright areas of the scene. On GameCube,
// it works by:
//   1. Copying the framebuffer to a texture (EFB-to-texture)
//   2. Downsampling through a mip chain (controlled by _ngcBloomNumIterations
//      at 0x804FF264, default 3-4 passes)
//   3. Applying a brightness threshold filter
//   4. Blurring each mip level
//   5. Compositing the blurred mips back onto the framebuffer additively
//
// Bloom class layout (inherits from FrameEffect):
//   FrameEffect base: 0x00-0x13 (20 bytes)
//   --- Bloom-specific data starts at offset 0x14 relative to Bloom ---
//   0x14: BloomSettings m_targetSettings (variable, copied from external)
//   0x40: BloomSettings m_activeSettings (variable, interpolated)
//   0x6C: BloomSettings m_savedSettings  (for state change snapshots)
//   0x70: float m_interpProgress         (interpolation progress [0,1])
//
// BloomSettings structure (inferred from SetTargetSettings copy loop):
//   Total size: ~56 bytes (two passes of 24-byte copy + 20 extra bytes)
//   Contains: threshold, intensity, scale, color tint RGBA, blur kernel size
//
// Bloom vtable at 0x8046D6C8:
//   Overrides: EffectStateChanged, UpdateTargetParameters,
//              EffectIsFinishedFadingIn, EffectIsFinishedFadingOut,
//              SetTargetSettings
//

struct BloomSettings {
    float threshold;          // 0x00 - brightness threshold for bloom
    float intensity;          // 0x04 - bloom intensity multiplier
    float scale;              // 0x08 - bloom scale factor
    float colorR;             // 0x0C - tint red
    float colorG;             // 0x10 - tint green
    float colorB;             // 0x14 - tint blue
    // Additional params follow in 24-byte blocks...
};


// 0x803576E0 - 116 bytes
// Copies BloomSettings from external source into m_targetSettings
// The copy is done as a loop: 2 iterations of 24-byte chunks + 20 trailing bytes
// Total copied: 2*24 + 20 = 68 bytes (approximate BloomSettings total size)
// NON_MATCHING: loop codegen
/*
void Bloom::SetTargetSettings(BloomSettings& settings) {
    // this+0x14 = m_targetSettings destination
    u8* dst = (u8*)this + 0x14;
    u8* src = (u8*)&settings;

    // Copy in 24-byte chunks (2 iterations)
    for (int i = 0; i < 2; i++) {
        // Copy 6 words (24 bytes) per iteration
        ((u32*)dst)[0] = ((u32*)src)[0];
        ((u32*)dst)[1] = ((u32*)src)[1];
        ((u32*)dst)[2] = ((u32*)src)[2];
        ((u32*)dst)[3] = ((u32*)src)[3];
        ((u32*)dst)[4] = ((u32*)src)[4];
        ((u32*)dst)[5] = ((u32*)src)[5];
        dst += 24;
        src += 24;
    }

    // Copy remaining 20 bytes (5 words)
    ((u32*)dst)[0] = ((u32*)src)[0];
    ((u32*)dst)[1] = ((u32*)src)[1];
    ((u32*)dst)[2] = ((u32*)src)[2];
    ((u32*)dst)[3] = ((u32*)src)[3];
    ((u32*)dst)[4] = ((u32*)src)[4];
}
*/


// 0x803572F0 - 204 bytes
// Interpolates bloom parameters based on current effect state
// NON_MATCHING: FP register allocation
//
// During FADING_IN (state 2):
//   - Stores current active settings snapshot at offset 0x40
//   - Calls InterpolateLerp() to blend from saved settings to target
//   - Parameters: threshold, intensity, color are independently interpolated
//   - Also copies target's additional params (offset 0x20+) to active (0x4C+)
//
// During FADING_OUT (state 8):
//   - Interpolates from current active settings toward zero/disabled values
//   - Uses same InterpolateLerp helper
//
// InterpolateLerp (at 0x803C774C) signature:
//   float InterpolateLerp(float current, float blendValue, float speed, float dt, float target)
//   Returns the interpolated value.
//
/*
void Bloom::UpdateTargetParameters(float dt) {
    u8* self = (u8*)this;

    if (m_state == STATE_FADING_IN) {
        // Save snapshot of current intensity at offset 0x40
        float curIntensity = *(float*)(self + 0x14);
        *(float*)(self + 0x40) = curIntensity;

        // Interpolate intensity toward target
        float target = *(float*)(self + 0x70);  // interp progress
        float blendVal = *(float*)(self + 0x18); // blend speed
        float speed = 1.0f;  // from constant pool
        float result = InterpolateLerp(target, blendVal, speed, dt, *(float*)(self + 0x00));
        *(float*)(self + 0x44) = result;

        // Copy additional bloom params from source (0x1C) directly
        *(float*)(self + 0x48) = *(float*)(self + 0x1C);

        // Copy 3 param blocks (threshold/scale/color) from offset 0x20
        // to offset 0x4C in 8-byte pairs
        for (int i = 0; i < 3; i++) {
            *(float*)(self + 0x4C + i*8) = *(float*)(self + 0x20 + i*8);
            *(float*)(self + 0x4C + i*8 + 4) = *(float*)(self + 0x20 + i*8 + 4);
        }
    }
    else if (m_state == STATE_FADING_OUT) {
        // Interpolate toward zero
        float target = *(float*)(self + 0x70);
        float zeroTarget = 0.0f;  // from constant pool
        float speed = 1.0f;
        float result = InterpolateLerp(target, zeroTarget, speed, dt, *(float*)(self + 0x04));
        *(float*)(self + 0x44) = result;
    }
}
*/


// 0x803573BC - 136 bytes
// Called when effect state changes (DISABLED->FADING_IN or ACTIVE->FADING_OUT)
// Copies current active params to saved params for interpolation start point
// NON_MATCHING: loop unrolling
/*
void Bloom::EffectStateChanged(FrameEffect::EffectState newState) {
    if (newState != STATE_FADING_IN && newState != STATE_FADING_OUT) {
        return;
    }

    // Copy active settings (at this+0x40, 56 bytes) to saved settings (at this+0x6C)
    // Done as: 1 loop of 24 bytes + remaining 32 bytes
    u32* src = (u32*)((u8*)this + 0x40);
    u32* dst = (u32*)((u8*)this + 0x6C);

    // Copy 24 bytes
    for (int i = 0; i < 6; i++) {
        dst[i] = src[i];
    }
    src += 6;
    dst += 6;

    // Copy remaining 20 bytes
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
}
*/


// ============================================================================
// MOTION BLUR EFFECT
// ============================================================================
//
// Motion blur creates a temporal blending effect where the current frame is
// blended with previous frames. On GameCube:
//   1. The previous frame's texture is stored
//   2. Current frame is blended with previous using a weighted average
//   3. The blend factor controls the "trail" length
//
// MotionBlur class layout:
//   FrameEffect base: 0x00-0x13 (20 bytes)
//   0x14: MotionBlurSettings m_targetSettings (12 bytes)
//   0x20: float m_activeIntensity   - current interpolated intensity
//   0x24: float m_activeBlendFactor - current interpolated blend
//   0x28: u32   m_activeFlags       - current active flags
//   0x2C: float m_savedIntensity    - snapshot for interpolation
//   0x30: float m_savedBlendFactor  - snapshot for interpolation
//
// MotionBlurSettings structure (from SetTargetSettings - 12 bytes):
//   0x00: float intensity    - blur strength (0=none, 1=full)
//   0x04: float blendFactor  - temporal blend weight
//   0x08: u32   flags        - enable flags / mode bits
//
// MotionBlur vtable at 0x8046D708
//

struct MotionBlurSettings {
    float intensity;     // 0x00 - motion blur strength
    float blendFactor;   // 0x04 - temporal blend weight
    u32   flags;         // 0x08 - mode flags
};


// 0x8035768C - 32 bytes
// Simple 12-byte copy (3 words) from settings to this+0x14
void MotionBlur_SetTargetSettings(void* thisPtr, MotionBlurSettings* settings) {
    u32* dst = (u32*)((u8*)thisPtr + 0x14);
    u32* src = (u32*)settings;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}


// 0x803571C0 - 204 bytes
// Interpolates motion blur parameters between current and target
// NON_MATCHING: FP register scheduling
//
// During FADING_IN (state 2):
//   - Interpolates intensity: lerp(savedIntensity -> targetIntensity)
//   - Interpolates blendFactor: lerp(savedBlend -> targetBlend)
//   - Copies flags from target to active
//
// During FADING_OUT (state 8):
//   - Interpolates intensity toward 0 (target = this+0x04)
//   - Interpolates blendFactor toward 0
//   - Sets flags to 0
//
// Both paths use InterpolateLerp (0x803C774C) with a speed constant
// loaded from the constant pool at offset 10972 (approx 1.0).
//
/*
void MotionBlur::UpdateTargetParameters(float dt) {
    u8* self = (u8*)this;

    if (m_state == STATE_FADING_IN) {
        float savedIntensity = *(float*)(self + 0x14);  // target intensity
        float speed = 1.0f;  // constant
        float blendVal = *(float*)(self + 0x2C);  // saved intensity
        float curIntensity = *(float*)(self + 0x00);  // base intensity
        *(float*)(self + 0x20) = InterpolateLerp(curIntensity, blendVal, speed, dt, savedIntensity);

        float savedBlend = *(float*)(self + 0x18);  // target blend
        float curBlend = *(float*)(self + 0x00);  // base blend
        float blendVal2 = *(float*)(self + 0x30);  // saved blend
        float result = InterpolateLerp(curBlend, blendVal2, speed, dt, savedBlend);
        *(float*)(self + 0x24) = result;

        // Copy flags from target
        *(u32*)(self + 0x28) = *(u32*)(self + 0x1C);
    }
    else if (m_state == STATE_FADING_OUT) {
        float fadeTarget = *(float*)(self + 0x04);  // fade target (0.0)
        float speed = 1.0f;
        float blendVal = *(float*)(self + 0x2C);
        float result1 = InterpolateLerp(blendVal, speed, speed, dt, fadeTarget);
        *(float*)(self + 0x20) = result1;

        float result2 = InterpolateLerp(blendVal, speed, speed, dt, fadeTarget);
        *(float*)(self + 0x24) = result2;

        *(u32*)(self + 0x28) = 0;
    }
}
*/


// 0x8035728C - 52 bytes
// Called on state change for motion blur - saves current active values
/*
void MotionBlur::EffectStateChanged(FrameEffect::EffectState newState) {
    if (newState != STATE_FADING_IN && newState != STATE_FADING_OUT) {
        return;
    }
    // Save active intensity and blend factor for interpolation
    // (actual implementation saves from active to saved slots)
}
*/


// ============================================================================
// DEPTH OF FIELD EFFECT
// ============================================================================
//
// Depth of field simulates camera focus by blurring objects that are
// too close or too far from a focal point. On GameCube:
//   1. The scene depth is sampled (via Z-buffer or approximation)
//   2. A blur kernel is applied based on distance from focal plane
//   3. Near-field and far-field blur are applied independently
//
// DepthOfField class layout:
//   FrameEffect base: 0x00-0x13 (20 bytes)
//   0x14: DepthOfFieldSettings m_targetSettings (20 bytes)
//   0x28: u32   m_activeFlags
//   0x2C: float m_activeFocalDist  - current focal distance
//   0x30: float m_activeFocalRange - current focal range
//   0x34: float m_activeNearBlur   - near field blur amount
//   0x38: float m_activeFarBlur    - far field blur amount
//   0x3C: u32   m_savedFlags       - snapshot for interpolation
//   0x40: EVec3 m_focusParams      - focal distance/range/etc
//   0x4C: float m_interpProgress   - interpolation progress
//
// DepthOfFieldSettings (from SetTargetSettings - 20 bytes):
//   0x00: float focalDistance   - distance to focal plane
//   0x04: float focalRange     - range of sharp focus
//   0x08: float nearBlurAmount  - near blur intensity
//   0x0C: float farBlurAmount   - far blur intensity
//   0x10: u32   flags           - DOF mode flags
//
// DepthOfField vtable at 0x8046D688
//

struct DepthOfFieldSettings {
    float focalDistance;   // 0x00
    float focalRange;     // 0x04
    float nearBlurAmount; // 0x08
    float farBlurAmount;  // 0x0C
    u32   flags;          // 0x10
};


// 0x80357788 - 48 bytes
// Copy 20 bytes (5 words) from settings to this+0x14
void DepthOfField_SetTargetSettings(void* thisPtr, DepthOfFieldSettings* settings) {
    u32* dst = (u32*)((u8*)thisPtr + 0x14);
    u32* src = (u32*)settings;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
}


// 0x80357474 - 368 bytes
// Interpolates DOF parameters. More complex than motion blur because DOF
// interpolates focal distance/range as a 3-component vector using
// InterpolateLerp3 (at 0x803C77A4), which handles 3D interpolation.
// NON_MATCHING: heavy FP register usage
//
// During FADING_IN:
//   - Copies target focal params to a temp EVec3
//   - Calls InterpolateLerp3 to blend from saved focal params toward target
//   - Stores result in active focal params
//   - Separately interpolates far blur with InterpolateLerp
//
// During FADING_OUT:
//   - Same structure but targets are zeroed out (all blur to 0)
//   - Focal params interpolate toward (0, 0, 0)
//
/*
void DepthOfField::UpdateTargetParameters(float dt) {
    u8* self = (u8*)this;

    if (m_state == STATE_FADING_IN) {
        // Copy target flags to active
        *(u32*)(self + 0x28) = *(u32*)(self + 0x14 + 0x10);

        // Build temp vectors for 3D interpolation
        EVec3 targetFocal = {
            *(float*)(self + 0x40),   // focal distance
            *(float*)(self + 0x44),   // focal range
            *(float*)(self + 0x48)    // near blur
        };

        EVec3 savedFocal = {
            *(float*)(self + 0x18 + 0x00),
            *(float*)(self + 0x18 + 0x04),
            *(float*)(self + 0x18 + 0x08)
        };

        // InterpolateLerp3(result, target, saved, speed, dt, baseValue)
        EVec3 result;
        // result = lerp between savedFocal and targetFocal based on dt
        // Store result at offset 0x2C
        *(float*)(self + 0x2C) = result.x;
        *(float*)(self + 0x30) = result.y;
        *(float*)(self + 0x34) = result.z;

        // Interpolate far blur separately
        float farBlurTarget = *(float*)(self + 0x4C);
        float farBlurSaved = *(float*)(self + 0x24);
        float speed = 1.0f;
        // *(float*)(self + 0x38) = InterpolateLerp(...);
    }
    else if (m_state == STATE_FADING_OUT) {
        // Same but targeting zero for all parameters
        // Focal params -> (0, 0, 0)
        // Far blur -> 0
    }
}
*/


// ============================================================================
// FrameEffectsManager - Creates, owns, and destroys the three effect objects
// ============================================================================
//
// The FrameEffectsManager is created by the CameraDirector and stored at
// CameraDirector offset 0x2D0. It allocates three effect objects on the
// heap during Init() and frees them during Shutdown().
//
// Layout (only first 12 bytes are the effect pointers):
//   0x00: FrameEffect* m_pMotionBlur   (actually MotionBlur*)
//   0x04: FrameEffect* m_pBloom        (actually Bloom*)
//   0x08: FrameEffect* m_pDepthOfField (actually DepthOfField*)
//
// The remaining ~11KB is scratch memory used by the NGC renderers
// for texture buffers during post-processing.
//

// 0x803577B8 - 248 bytes
// Allocates and initializes all three effect objects
// NON_MATCHING: heap allocation + vtable setup
void FrameEffectsManager_Init(void* thisPtr) {
    u32* self = (u32*)thisPtr;

    // Step 1: Allocate MotionBlur-based FrameEffect wrapper (56 bytes)
    // This is a compound object containing the FrameEffect base with
    // 3 sub-effects (MotionBlur + its fade timers)
    void* fxWrapper = EAHeap_Alloc(0x38);

    // Initialize the wrapper with default fade times and disabled state
    // The wrapper contains 3 sub-effects at offsets 0x00, 0x14, 0x20, 0x2C
    // Each sub-effect has: fadeInTime, fadeOutTime, timer, state
    // Default fadeInTime and fadeOutTime loaded from constant pool
    // Default state = STATE_DISABLED (1)

    // Store wrapper vtable (FrameEffect vtable at 0x8046D708 initially,
    // then overwritten to BloomNGC vtable at 0x8046D808)
    self[0] = (u32)fxWrapper;

    // Step 2: Allocate Bloom (152 bytes = 0x98)
    void* bloom = EAHeap_Alloc(0x98);
    // Bloom::Bloom() constructor at 0x803C78E0
    // Sets up target/active/saved BloomSettings to defaults
    // Installs Bloom vtable at 0x8046D6C8 -> overwritten to 0x8046D7C8 (BloomNGC)
    self[1] = (u32)bloom;

    // Step 3: Allocate DepthOfField (80 bytes = 0x50)
    void* dof = EAHeap_Alloc(0x50);
    // DepthOfField::DepthOfField() constructor at 0x803C7A14
    // Installs DOF vtable at 0x8046D688 -> overwritten to 0x8046D788 (DepthOfFieldNGC)
    self[2] = (u32)dof;
}


// 0x803578B0 - 184 bytes
// Destroys all three effect objects by calling their destructors
// NON_MATCHING: vtable dispatch codegen
void FrameEffectsManager_Shutdown(void* thisPtr) {
    u32* self = (u32*)thisPtr;

    // Destroy MotionBlur wrapper
    void* motionBlur = (void*)self[0];
    if (motionBlur != 0) {
        // Call destructor via vtable: vtable[0x08](this, 3)
        // The '3' flag means "delete after destruct"
        // vtable dispatch: lwz r9, 0x10(motionBlur) -> a8 r3, 0x08(r9)...
        self[0] = 0;
    }

    // Destroy Bloom
    void* bloom = (void*)self[1];
    if (bloom != 0) {
        // Same vtable destructor call pattern
        self[1] = 0;
    }

    // Destroy DepthOfField
    void* dof = (void*)self[2];
    if (dof != 0) {
        // Same vtable destructor call pattern
        self[2] = 0;
    }
}


// 0x80357968 - 8 bytes
// addi r3, r3, 0x00 (returns this + 0 = pointer to m_pMotionBlur)
void* FrameEffectsManager_MotionBlurObject(void* thisPtr) {
    return thisPtr;
}

// 0x80357970 - 8 bytes
// addi r3, r3, 0x04 (returns this + 4 = pointer to m_pBloom)
void* FrameEffectsManager_BloomObject(void* thisPtr) {
    return (void*)((u8*)thisPtr + 4);
}

// 0x80357978 - 8 bytes
// addi r3, r3, 0x08 (returns this + 8 = pointer to m_pDepthOfField)
void* FrameEffectsManager_DepthOfFieldObject(void* thisPtr) {
    return (void*)((u8*)thisPtr + 8);
}


// ============================================================================
// NGC PLATFORM-SPECIFIC RENDERING
// ============================================================================
//
// The NGC (Nintendo GameCube) renderer subclasses handle the actual
// GX hardware operations for each effect. They share a common pattern:
//
// All three NGC renderers share a memory region at offset 0x6CC in their
// respective structs. This is a display list buffer / texture cache
// that stores the intermediate rendering state.
//
// Common NGC rendering pattern (in Draw methods):
//   1. Save current GX state (render state cache at 0x6CC)
//   2. Set up GX texture environment (TEV) stages
//   3. Copy EFB (Embedded Frame Buffer) to texture
//   4. Apply filter/blend passes
//   5. Draw full-screen quad with effect applied
//   6. Restore GX state
//

// ============================================================================
// BloomNGC::Draw (0x803595E4, 876 bytes)
// ============================================================================
//
// The bloom rendering pipeline on GameCube:
//
// 1. Read bloom parameters from the Bloom parent class:
//    - threshold (offset 0x40)
//    - intensity (offset 0x44)
//    - scale (offset 0x48)
//    - color tint (offset 0x54, 0x58)
//
// 2. Create mip surface chain via ConstructBloomMipSurface():
//    - _ngcBloomNumIterations (sdata 0x804FF264) controls mip count
//    - _ngcBloomInitialSize (sdata 0x804FF268) controls starting resolution
//    - Each level is half the previous (128 -> 64 -> 32 -> 16)
//
// 3. For each mip level:
//    a. Copy EFB to texture (GXCopyTex with downscale)
//    b. Apply threshold filter (pixels below threshold -> black)
//    c. Gaussian blur (horizontal + vertical passes)
//    d. Store result in mip texture
//
// 4. Composite all mip levels back onto framebuffer:
//    a. Set blend mode to additive (GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE)
//    b. Draw full-screen quad for each mip with intensity scaling
//    c. Color tint is applied as a TEV color multiplier
//
// The display list at offset 0x6CC stores pre-built GX commands for
// the common setup/teardown, avoiding redundant CPU-side GX calls.
//

// ============================================================================
// MotionBlurNGC::Draw (0x8035917C, 1128 bytes)
// ============================================================================
//
// Motion blur on GameCube:
//
// 1. Read active blur parameters from MotionBlur parent:
//    - intensity (offset 0x24)
//    - blend flags (offset 0x28)
//
// 2. Check if motion blur is actually enabled (field at offset 0x02)
//    - If disabled or intensity is 0, skip rendering
//
// 3. Set up GX alpha blending:
//    - Source factor = GX_BL_SRCALPHA
//    - Dest factor = GX_BL_INVSRCALPHA
//    - Alpha = intensity value
//
// 4. Draw previous frame's texture as a full-screen quad
//    - This creates the "ghosting" effect
//    - The alpha controls how much of the previous frame shows through
//
// 5. Copy current framebuffer to texture for next frame's blur source
//    - GXCopyTex to the motion blur texture at offset 0x6CC
//
// The motion blur texture is stored persistently between frames, which is
// why the NGC struct is so large (~2524 bytes) - it contains the full
// texture buffer for the previous frame.
//

// ============================================================================
// DepthOfFieldNGC::Draw (0x80359950, 1056 bytes)
// ============================================================================
//
// Depth of field on GameCube uses a simplified approach:
//
// 1. Read DOF parameters from DepthOfField parent:
//    - focalDistance (offset 0x04)
//    - focalRange (offset 0x08)
//    - blurAmount (offset 0x28, 0x2C)
//    - farBlur (offset 0x38)
//
// 2. Color encode depth info:
//    - Fields at offset 0x01, 0x02, 0x03 store RGB components that
//      encode the focal plane distance for the TEV comparison
//
// 3. Set up multi-pass rendering:
//    a. Pass 1: Copy EFB to texture
//    b. Pass 2: Apply blur (downscale + box filter)
//    c. Pass 3: Blend based on depth:
//       - Use TEV to compare pixel depth against focal plane
//       - Blend between sharp (original) and blurred textures
//       - Near field: blur increases as distance < focalDist - focalRange
//       - Far field: blur increases as distance > focalDist + focalRange
//
// 4. Composite result to framebuffer
//
// The DOF effect is the most complex of the three because it requires
// per-pixel depth comparison, which on GC hardware is done through
// creative use of the TEV (Texture Environment) stages and Z-buffer
// readback.
//

// ============================================================================
// ENgcRenderer::DrawFrameWithBloomAndMotionBlur (0x80349B94, 356 bytes)
// ============================================================================
//
// This is the top-level function that orchestrates frame effects rendering.
// Called by the main render loop after scene geometry is drawn.
//
// Parameters: float param1, float param2 (viewport dimensions or scaling)
//
// Flow:
//   1. Check _ngcSkipFrameEffects (sdata 0x804FF260) - if set, skip all
//   2. Check EGraphics::IsEnableFrameEffects() - if disabled, skip
//   3. For each active effect (checked via IsEffectRunning()):
//      a. Call the effect's NGC Draw(ERC*) method
//   4. The effects render in order: MotionBlur -> Bloom -> DepthOfField
//      This order matters because motion blur should be applied before
//      bloom (bloom on blurred content looks correct, not vice versa)
//
// The _ngcSkipFrameEffects global can be toggled via cheat menu to
// disable effects for performance debugging.
//


// ============================================================================
// ANIMATION EVENT INTEGRATION
// ============================================================================
//
// Frame effects are triggered from camera animation note tracks. When
// the CameraDirector processes animation events (ProcessAnimEvents),
// it dispatches to these handler functions:
//
// HandleBloomEvent (0x80003998, 680 bytes):
//   Parses bloom parameters from an EAnimNote and calls
//   Bloom::SetTargetSettings + FrameEffect::Enable on the bloom object.
//   Supports override tokens for tuning (OverrideBloomSettingsFromTokens).
//
// HandleMotionBlurEvent (0x80003C40, 416 bytes):
//   Same pattern for motion blur. Sets MotionBlurSettings from anim data.
//
// HandleDepthOfFieldEvent (0x80003DE0, 508 bytes):
//   Same pattern for DOF. Sets DepthOfFieldSettings from anim data.
//
// Override functions allow animation-embedded text tokens to fine-tune
// effect parameters without reauthoring the animation:
//   OverrideBloomSettingsFromTokens (0x800035D8, 600 bytes)
//   OverrideMotionBlurSettingsFromTokens (0x800034C0, 280 bytes)
//   OverrideDOFSettingsFromTokens (0x80003830, 360 bytes)
//
// Social mode interaction helpers:
//   TurnOnMotionBlur (0x800158C4, 148 bytes):
//     Enables motion blur when entering social mode camera
//   TurnOffMotionBlur (0x80015958, 72 bytes):
//     Disables motion blur when leaving social mode
//   TurnOffSocialModeEffects (0x80015880, 68 bytes):
//     Disables all effects when exiting social mode
//
