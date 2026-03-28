// particles_lighting_decomp.cpp - Particle Effects & Scene Lighting Decompilation
// The Sims 2 GameCube - Visual Effects Pipeline and Light Grid System
//
// Object files:
//   c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\reffectsemitter.obj
//   c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\reffectssequencer.obj
//   c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\reffectsattachment.obj
//   c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\rparticle.obj
//   c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\eilight.obj
//   c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\eiamblight.obj
//   c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\eipointlight.obj
//   c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\eispotlight.obj
//   c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\elightgrid.obj
//   c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\effectsmanager.obj
//
// ============================================================================
// PARTICLE EFFECTS & LIGHTING SYSTEM ARCHITECTURE
// ============================================================================
//
// This file documents two major visual systems in The Sims 2 GameCube:
//
// I.  PARTICLE EFFECTS SYSTEM (REffects*, RParticle, Effects::*)
// II. SCENE LIGHTING SYSTEM (EILight hierarchy, ELightGrid)
//
// ============================================================================
// I. PARTICLE EFFECTS SYSTEM
// ============================================================================
//
// The particle system follows a three-tier resource architecture:
//
//   REffectsSequencer (top-level effect definition)
//       |
//       +-- Contains a list of REffectsEmitter references
//       |   (sequencer orchestrates timing/order of emitters)
//       |
//       +-- REffectsEmitter (individual emitter resource)
//               |
//               +-- m_emitterInitData (ptr at offset 0x14) -> emitter config data
//               +-- m_particleBirthData (ptr at offset 0x18) -> per-particle spawn params
//               +-- m_texture (ptr at offset 0x1C)          -> particle texture resource
//               |
//               +-- RParticle (particle definition resource)
//                       |
//                       +-- m_emitterInitData (ptr at offset 0x14)
//                       +-- m_particleBirthData (ptr at offset 0x18)
//                       +-- m_data (array at offsets 0x1C+)
//                       +-- PrepareData() converts raw particle data
//                           into runtime-ready format (1596 bytes of code)
//
// Resource Loading Flow:
//
//   1. REffectsSequencer::Load(EFile*) loads sequencer from .arc file
//      - Opens an EChunkedFile with tag 'ESEQ' (0x45534551)
//      - Reads version byte into m_field_010
//      - Dispatches to vtable-based sub-resource loader
//
//   2. REffectsEmitter::Load(EFile*) loads emitter definition
//      - Opens EChunkedFile with tag 'EEMT' (0x45454D54)
//      - Reads version byte into m_field_010
//      - Allocates particle birth data block (64-byte aligned)
//      - Stores emitterInitData at this+0x14 (points to base+0x90)
//      - Stores particleBirthData at this+0x18 (raw alloc pointer)
//      - Dispatches sub-resource loading via vtable
//
//   3. RParticle::Load(EFile*, uint) loads particle definitions
//      - Largest loader (612 bytes) - handles multiple data versions
//      - Loads raw particle parameter arrays
//      - Calls PrepareData() to convert units and pre-compute values
//
// Attachment System (REffectsAttachment):
//
//   REffectsAttachment connects particle effects to bone animations.
//   When a SAnimator2 encounters a particle event in an animation timeline:
//
//     SAnimator2::_handleParticleEvent(REffectsAttachment*)
//       -> iterates attachment entries (8-byte stride at offset 0x14)
//       -> each entry has: [u8 boneIndex, u8 pad, u16 flags, u32 effectPtr]
//       -> checks if bone is valid via vtable call (offset 0x118 in vtable)
//       -> spawns effect at bone position with optional mirror flag
//
//   REffectsAttachment::Load(EFile*) loads attachment data:
//     - Opens EChunkedFile with tag 'EATC' (0x45415443) version 2
//     - Falls back to OldLoad() for version 1 (652 bytes - legacy format)
//     - Reads attachment count from version byte, divides by 8
//     - Resizes internal vector at this+0x14 to hold entries
//     - Dispatches sub-resource loading
//
// Runtime Effect Creation:
//
//   Effects::EffectsManager::CreateEffect(REffectsEmitter&, ClientParams*)
//     1. Checks if EffectsManager is initialized (this->field_000 != 0)
//     2. Allocates a FastParticleEmitter (424 bytes, 16-byte aligned)
//     3. If ClientParams provided: constructs with params, else default ctor
//     4. Calls FastParticleEmitter::Init(REffectsEmitter&)
//        - Stores emitter resource ref at this+0x1A0
//        - Increments resource refcount
//        - Calls SharedInitPart1() for basic setup
//        - Copies emitterInitData ptr to this+0x18C
//        - Reads particle type byte from initData offset 0xA8
//        - If particleBirthData exists: calls SharedInitPart2() for full init
//     5. On Init failure: destroys effect via vtable call (offset 0x08)
//     6. On success: calls AddEffect() to register with manager
//
//   Effects::EffectsManager::CreateEffect(REffectsSequencer&, ClientParams*)
//     - 8-byte stub that delegates to sequencer-based creation
//     - Sequencer iterates its emitter list and creates each sub-effect
//
// ============================================================================
// II. SCENE LIGHTING SYSTEM
// ============================================================================
//
// The lighting system uses a class hierarchy rooted at EILight (EInstance-based
// light), with specialized subclasses for different light types:
//
//   EILight (base class - 172 bytes, vtable at 0x80468DE0)
//       |
//       +-- EIAmbLight     (ambient light - 148 bytes, vtable 0x80468960)
//       +-- EIDirLight      (directional light - 176 bytes)
//       +-- EIPointLight    (point light - 208 bytes, vtable 0x804692B0)
//       +-- EIPointAmbLight (point ambient - 196 bytes)
//       +-- EISpotLight     (spot light - 224 bytes, vtable 0x804695D8)
//       +-- EIPortalPointLight (portal light - 216 bytes)
//
// Light Type Enum (from GetLightType() returns):
//   0 = EILight (base/unknown)
//   1 = EIAmbLight (ambient)
//   2 = EIDirLight (directional)
//   3 = EIPointLight (point)
//   4 = EIPortalPointLight (portal)
//   5 = EISpotLight (spot)
//
// ============================================================================
// EILight BASE CLASS
// ============================================================================
//
// EILight (0xAC = 172 bytes) is the base for all scene lights.
//
// Key fields (from EILight constructor + Read/Write analysis):
//
//   0x000: f32[3] m_scaledIntensity    -- cached scaled RGB intensity
//   0x05C: u32    m_flags              -- light flags (bit 3 = 0x00080000 set in ctor)
//   0x07C: u32    m_enabled            -- 1=enabled (default true)
//   0x080: u32    m_useScaleIntensity  -- 0=disabled (default false)
//   0x084: u32    m_field_084          -- unknown (zeroed in ctor)
//   0x088: u32    m_field_088          -- serialized (Read/Write)
//   0x08C: f32    m_intensity          -- base intensity (default 1.0)
//   0x090: f32[3] m_color              -- light color RGB (default {1,1,1})
//   0x09C: f32[3] m_intensityScale     -- per-component scale (default {0,0,0})
//   0x0A8: u32    m_useIntensityScale  -- whether to use scale (default 1)
//

#include "types.h"

// Forward declarations matching symbol names
class EFile;
class EStream;
class EInstance;
class EVec3;
class EMat4;
class ERC;
class FastAllocPool;
class EChunkedFile;
struct EDirLight;
struct AttachmentNode;
struct EAnimController;
struct ObjAnimDef;
struct EFloorVertexSpan;

// ============================================================================
// EILight - Base Light Class
// ============================================================================
// Address: 0x80227984 (ctor) | Size: 0xAC (172 bytes)
// Vtable: 0x80468DE0 (400 bytes = 100 entries)

// 0x80227984 - 168 bytes (42 instructions)
// EILight::EILight(void)
//
// Constructs the base light with default values:
//   - Calls EInstance base ctor at 0x80228290
//   - Sets vtable to 0x8046_8DE0 (EILight vtable)
//   - m_intensity (0x8C) = 1.0f  (from rodata -6544(r9))
//   - m_color (0x90) = {1.0, 1.0, 1.0}  (copies same float)
//   - m_enabled (0x7C) = 1
//   - m_useScaleIntensity (0x80) = 0
//   - m_field_084 = 0
//   - Flags at 0x5C: OR'd with 0x0008_0000 (oris r0,r0,8)
//   - m_intensityScale (0x9C) = {0.0, 0.0, 0.0}  (uses same 1.0 stored as init?)
//     Actually: stfs f0,0x9C / stfs f0,0xA0 / stfs f0,0xA4 = {1.0,1.0,1.0}
//     Wait - re-examining: the float loaded is 1.0 for intensity AND color.
//     But 0x9C-0xA4 are stored with f0 which is 1.0 -> scale = {1.0,1.0,1.0}
//   - m_useIntensityScale (0xA8) = 1
//
// Note: The 1.0f constant is loaded once from rodata at -6544(lis r9,-32704)
//       and reused for intensity, color channels, and scale channels.
#if 0
void EILight::EILight() {
    EInstance::EInstance();         // bl 0x80228290
    _vtable = &EILight_vtable;     // 0x8046_8DE0

    f32 one = 1.0f;               // rodata constant

    // Color: {1.0, 1.0, 1.0}
    m_color[0] = one;             // stfs f0, 0x90(r30)
    m_color[1] = one;             // via EVec3 copy pattern
    m_color[2] = one;

    m_enabled = 1;                 // stw r9, 0x7C(r30)  (r9 = 1)
    m_useScaleIntensity = 0;       // stw r6, 0x80(r30)  (r6 = 0)
    m_intensity = one;             // stfs f0, 0x8C(r30)
    m_field_084 = 0;               // stw r6, 0x84(r30)

    // Set flag bit in m_flags
    u32 flags = m_flags;           // lwz r0, 0x5C(r30)
    flags |= 0x0008_0000;         // oris r0, r0, 8
    m_flags = flags;               // stw r0, 0x5C(r30)

    m_useIntensityScale = 1;       // stw r9, 0xA8(r30)

    // Intensity scale: {1.0, 1.0, 1.0}
    m_intensityScale[0] = one;     // stfs f0, 0x9C(r30)
    m_intensityScale[1] = one;     // stfs f0, 0xA0(r30)
    m_intensityScale[2] = one;     // stfs f0, 0xA4(r30)
}
#endif

// 0x80227D64 - 124 bytes (31 instructions)
// EILight::GetScaledIntensity(void)
//
// Computes the final RGB intensity, applying per-component intensity scale
// if m_useIntensityScale is set and the scale is non-zero.
//
// Parameters: r3 = output EVec3*, r4 = this (hidden retval ABI)
//
// If m_useIntensityScale (0xA8) == 0, or all scale components are 0.0:
//   result = { m_intensity, m_intensity, m_intensity }  (uniform)
//
// Otherwise:
//   result.x = m_intensity * m_intensityScale.x
//   result.y = m_intensity * m_intensityScale.y
//   result.z = m_intensity * m_intensityScale.z
//
// This allows lights to have per-channel intensity variation (e.g., warm tint).
#if 0
void EILight::GetScaledIntensity(EVec3& out) {
    if (m_useIntensityScale == 0) {
        // No scale - uniform intensity
        out.x = m_intensity;
        out.y = m_intensity;
        out.z = m_intensity;
        return;
    }

    f32 sx = m_intensityScale[0];  // 0x9C
    f32 sy = m_intensityScale[1];  // 0xA0 (loaded as 4(r9))
    f32 sz = m_intensityScale[2];  // 0xA4 (loaded as 8(r9))

    // Check if all scale components are 0.0
    if (sx == 0.0f && sy == 0.0f && sz == 0.0f) {
        // Zero scale -> fall back to uniform
        out.x = m_intensity;
        out.y = m_intensity;
        out.z = m_intensity;
        return;
    }

    // Apply per-component scale
    out.x = m_intensity * sx;    // fmuls f12, f0, f12
    out.y = m_intensity * sy;    // fmuls f0, f0, f11
    out.z = m_intensity * sz;    // fmuls f13, f0, f13
}
#endif

// 0x80227C90 - 212 bytes (53 instructions)
// EILight::GetScaledIntColor(float, unsigned int *)
//
// Converts the light's color and intensity into integer RGB values (0-255).
// Used to produce hardware-friendly color values for the GX renderer.
//
// Parameters:
//   f1 = additional scale factor (e.g., distance attenuation)
//   r4 = pointer to u32[3] output (R, G, B as separate u32s)
//
// Algorithm:
//   scaledIntensity = f1 * 255.0f * m_intensity;
//   for each channel (R, G, B):
//     float val = m_color[channel] * scaledIntensity;
//     if (val > 255.0f) val = 255;
//     else val = (int)val;  // fctiwz - truncate to int
//     output[channel] = val;
//
// The 255.0f constant is loaded from rodata at -6536(r9).
// Clamping to 255 is done per-channel with fcmpu + branch.
#if 0
void EILight::GetScaledIntColor(float scale, u32* outRGB) {
    f32 intensity = m_intensity;      // lfs f11, 0x8C(r3)
    f32 kScale = 255.0f;              // lfs f0, rodata   (-6540)
    f32 kMax = 255.0f;                // lfs f11, rodata  (-6536)

    f32 combinedScale = scale * kScale * intensity;  // fmuls chain

    // Red channel
    f32 red = m_color[0] * combinedScale;   // 0x90
    if (red > kMax)
        outRGB[0] = 255;
    else
        outRGB[0] = (u32)red;              // fctiwz

    // Green channel
    f32 green = m_color[1] * combinedScale; // 0x94 (via addi r11,r3,0x90; 4(r11))
    if (green > kMax)
        outRGB[1] = 255;
    else
        outRGB[1] = (u32)green;

    // Blue channel
    f32 blue = m_color[2] * combinedScale;  // 0x98 (8(r11))
    if (blue > kMax)
        outRGB[2] = 255;
    else
        outRGB[2] = (u32)blue;
}
#endif

// 0x80227B40 - 284 bytes (71 instructions)
// EILight::Read(EStream &)
//
// Deserializes light parameters from a stream. Reads:
//   1. bool -> m_enabled (0x88)      (as byte, converted to 0/1)
//   2. bool -> m_field_07C (0x7C)    (enabled flag)
//   3. bool -> m_field_080 (0x80)    (useScaleIntensity)
//   4. float -> m_intensity (0x8C)   (4 bytes)
//   5. EVec3 -> m_color (0x90)       (12 bytes via ReadVec3)
//   6. ??? -> m_field_084 (0x84)     (via helper at 0x80228210)
//
// Each bool is read as a single byte via the stream's read vtable
// (offset 0x30/0x34 in stream vtable), then converted to int 0 or 1.
// The version check at 0x80227B60 gates whether any data is read at all.
#if 0
void EILight::Read(EStream& stream) {
    // Check read version
    u16 version = EILight::s_readVersion;  // lhz r0, sdata
    if (version == 0) return;

    // Read enabled state
    u8 byte;
    stream.ReadBytes(&byte, 1);       // blrl via vtable 0x30/0x34
    m_field_088 = byte ? 1 : 0;       // stw r9, 0x88(r30)

    // Read light on/off
    stream.ReadBytes(&byte, 1);
    m_enabled = byte ? 1 : 0;         // stw r9, 0x7C(r30)

    // Read use-scale-intensity flag
    stream.ReadBytes(&byte, 1);
    m_useScaleIntensity = byte ? 1 : 0;  // stw r9, 0x80(r30)

    // Read intensity (4 bytes float)
    stream.ReadBytes(&m_intensity, 4);    // addi r4, r30, 0x8C

    // Read color vector
    stream.ReadVec3(m_color);              // bl 0x802d266c with r4=r30+0x90

    // Read additional field
    ReadBoolField(stream, &m_field_084);   // bl 0x80228210 with r4=r30+0x84
}
#endif

// ============================================================================
// EIAmbLight - Ambient Light
// ============================================================================
// Address: 0x80226B98 | Size: 0x94 (148 bytes)
// Vtable: 0x80468960 (408 bytes)
//
// Ambient lights provide uniform non-directional illumination to rooms.
// They have no position or falloff - just color and intensity applied
// equally everywhere within their associated room.
//
// Key fields (inherited from EILight + own):
//   0x08C: f32 m_intensity  (from EILight)
//   0x090: f32[3] m_color   (from EILight)

// 0x80226B98 - 192 bytes (48 instructions)
// EIAmbLight::CalcLightOnPoint(EVec3 &, EVec3 &)
//
// Calculates ambient light contribution at a point. For ambient lights,
// the contribution is the same everywhere (no position dependence).
//
// Parameters:
//   r4 = point position (EVec3&) -- unused for ambient
//   r5 = output color (EVec3&)
//
// Algorithm:
//   1. Initialize output to {0, 0, 0}
//   2. Call IsEnabled() via vtable (offset 0x178/0x17C)
//   3. If enabled:
//      scaledColor = { m_color[0] * m_intensity,
//                      m_color[1] * m_intensity,
//                      m_color[2] * m_intensity }
//      output = scaledColor
#if 0
void EIAmbLight::CalcLightOnPoint(EVec3& point, EVec3& outColor) {
    // Init output to zero
    outColor.x = 0.0f;
    outColor.y = 0.0f;
    outColor.z = 0.0f;

    // Check if enabled via vtable call at offset 0x178
    bool enabled = this->IsEnabled();  // blrl via vtable
    if (!enabled) return;

    // Scale color by intensity
    f32 intensity = m_intensity;      // lfs f13, 0x8C(r31)
    outColor.x = m_color[0] * intensity;  // 0x90 * 0x8C
    outColor.y = m_color[1] * intensity;  // 0x94 * 0x8C (via +4 offset)
    outColor.z = m_color[2] * intensity;  // 0x98 * 0x8C (via +8 offset)
}
#endif

// 0x80226C58 - 176 bytes (44 instructions)
// EIAmbLight::LightingParameters(EVec3 &, float &, EVec3 &, EVec3 &)
//
// Returns ambient light's contribution parameters for the light grid.
// For ambient lights there is no direction, so direction output is zeroed.
//
// Parameters:
//   r4 = out direction (EVec3&) -- zeroed for ambient
//   r5 = out falloff (float&)  -- set to 0.0
//   r6 = out position (EVec3&) -- zeroed for ambient
//   r7 = out color (EVec3&)    -- scaled color
//
// Fills in:
//   direction = {0, 0, 0}
//   falloff = 0.0
//   position = {0, 0, 0}
//   color = { m_color[0]*intensity, m_color[1]*intensity, m_color[2]*intensity }
#if 0
void EIAmbLight::LightingParameters(EVec3& dir, float& falloff,
                                     EVec3& pos, EVec3& color) {
    f32 zero = 0.0f;

    dir.x = zero; dir.y = zero; dir.z = zero;
    falloff = zero;
    pos.x = zero; pos.y = zero; pos.z = zero;

    // Compute scaled color
    f32 intensity = m_intensity;  // 0x8C
    color.x = m_color[0] * intensity;
    color.y = m_color[1] * intensity;
    color.z = m_color[2] * intensity;
}
#endif

// 0x80226D08 - 196 bytes (49 instructions)
// EIAmbLight::Setup(void)
//
// Initializes the ambient light's derived state. Sets up:
//   - position = {0, 0, 0}
//   - direction = {0, 1, 0} (up vector for ambient reference)
//   - "up" vector = {1, 0, 0}
// Then calls the base EILight setup at 0x8022877C.
//
// The constants loaded are:
//   0.0f from rodata (-7084)
//   1.0f from rodata (-7080)
//   -1.0f or another constant from rodata (-7076)
#if 0
void EIAmbLight::Setup() {
    EVec3 position = {0.0f, 0.0f, 0.0f};
    EVec3 direction = {0.0f, 1.0f, 0.0f};
    EVec3 up = {-1.0f, 0.0f, 0.0f};

    // Copy position, direction, up into internal state
    // ... (complex EVec3 copy chains through stack locals)

    EILight::SetupInternal(position, direction, up);  // bl 0x8022877C
}
#endif

// ============================================================================
// EIPointLight - Point Light
// ============================================================================
// Address: 0x80229DCC (ctor) | Size: 0xD0 (208 bytes)
// Vtable: 0x804692B0 (400 bytes)
//
// Point lights emit light in all directions from a position, with distance
// falloff. They are the most common light type for lamps and fixtures.
//
// Key fields (from constructor + CalcFullIntensityLightOnPoint analysis):
//   0x0AC: f32 m_posX          -- world position X
//   0x0B0: f32 m_posY          -- world position Y (height)
//   0x0B8: f32[3] m_worldPos   -- world position (full, set by SetPosition)
//   0x0C0: f32[3] m_worldPos2  -- redundant copy
//   0x0C4: f32 m_falloffStart  -- inner radius (no attenuation)
//   0x0C8: f32 m_falloffEnd    -- outer radius (full attenuation)
//   0x0CC: u32 m_roomId        -- room this light belongs to (-1 = unassigned)
//
// The ctor also calls Setup() at the end to initialize derived matrices.

// 0x80229DCC - 172 bytes (43 instructions)
// EIPointLight::EIPointLight(void)
//
// Constructs a point light with default parameters:
//   - Calls EILight base ctor
//   - Sets vtable to 0x8046_92B0
//   - Position = {0, 0, 0}  (at 0xAC, 0xB8-0xC0)
//   - m_falloffStart = some default (rodata -5468)
//   - m_falloffEnd = some default (rodata -5464)
//   - m_roomId = -1 (0xFFFFFFFF -- unassigned)
//   - m_field_0BC = 0
//   - m_field_0CC = 1
//   - Calls Setup() at end
#if 0
void EIPointLight::EIPointLight() {
    EILight::EILight();                // bl 0x80227984
    _vtable = &EIPointLight_vtable;    // 0x8046_92B0

    f32 zero = 0.0f;                   // rodata -5472
    m_position = {zero, zero, zero};   // 0xAC + vec copy

    m_field_0BC = 0;
    m_roomId = -1;                     // li r6, -1; stw 0xC0
    m_falloffStart = DEFAULT_START;    // rodata -5468
    m_falloffEnd = DEFAULT_END;        // rodata -5464
    m_field_0CC = 1;

    Setup();                           // bl 0x8022A354
}
#endif

// 0x8022A008 - 216 bytes (54 instructions)
// EIPointLight::CalcFullIntensityLightOnPoint(EVec3 &, float &)
//
// Calculates the attenuation factor for a point at a given position.
// This is the core light evaluation function used by the light grid.
//
// Parameters:
//   r4 = point position (EVec3&)
//   r5 = output intensity (float&)
//
// Algorithm:
//   1. Compute 2D distance (XZ plane only - Y is ignored):
//      dx = point.x - m_posX    (0xAC)
//      dy = point.y - m_posY    (0xB0)
//      dist2D = sqrt(dx*dx + dy*dy)  via Vec2Length at 0x8025AC6C
//
//   2. Store base intensity: *outIntensity = m_intensity (0x8C)
//      If intensity is 0.0: set to fallback value (rodata -5456 = 1.0?)
//
//   3. If distance is 0.0: skip attenuation (light is at the point)
//
//   4. Apply falloff attenuation:
//      If m_field_0CC (use quadratic falloff):
//        attenuation = (falloffEnd / (dist * 2.0))^2
//      Else:
//        attenuation = 1.0 (linear, handled elsewhere)
//
//   5. result = attenuation * baseIntensity
//      Clamp: if result > 1.0 -> result = 1.0
//
// Note: The 2D distance calculation (ignoring height) is intentional --
// Sims 2 uses a top-down grid, so XZ distance determines light coverage
// on the floor plane.
#if 0
void EIPointLight::CalcFullIntensityLightOnPoint(EVec3& point, float& outIntensity) {
    f32 zero = 0.0f;                  // rodata -5460(r9)

    // 2D distance: XZ plane
    f32 dx = point.x - m_posX;        // 0x00(r4) - 0xAC(r31)
    f32 dy = point.y - m_posY;        // 0x04(r4) - 0xB0(r31)
    EVec3 delta = {dx, dy, 0.0f};
    f32 distance = Vec2Length(delta);  // bl 0x8025AC6C

    // Base intensity
    f32 baseIntensity = m_intensity;   // 0x8C
    outIntensity = baseIntensity;
    if (baseIntensity == zero) {
        outIntensity = 1.0f;           // rodata -5456
    }

    if (distance == zero) return;      // at the light position

    f32 attenuation = 1.0f;           // rodata -5452(r11)

    if (m_field_0CC != 0) {            // quadratic falloff enabled
        f32 falloffEnd = m_falloffEnd; // 0xC8
        f32 scaledDist = distance * 2.0f;  // rodata -5448(r9)
        f32 ratio = falloffEnd / scaledDist;
        attenuation = ratio * ratio;   // fmuls f1, f1, f1  (squared)
    }

    f32 result = attenuation * outIntensity;
    if (result > 1.0f) result = 1.0f;  // clamp
    outIntensity = result;
}
#endif

// 0x8022A0E0 - 408 bytes (102 instructions)
// EIPointLight::LightingParameters(EVec3 &, float &, EVec3 &, EVec3 &)
//
// Returns the full lighting parameters for the light grid system.
// This is called during ELightGrid::EvaluatePointLights to get each
// light's contribution at a grid vertex.
//
// Parameters:
//   r4 = out direction (EVec3&)  -- normalized direction from light to vertex
//   r5 = out falloff (float&)    -- falloff radius
//   r6 = out position (EVec3&)   -- not used for point lights (zeroed)
//   r7 = out scaledColor (EVec3&) -- intensity * color per-channel
//
// Algorithm:
//   1. falloff = m_falloffEnd * SOME_SCALE  (0xC8 * rodata -5444)
//   2. Call GetPosition via vtable (offset 0x174) to get world position
//   3. Compute scaledColor:
//      r = m_intensity * m_color.r
//      g = m_intensity * m_color.g
//      b = m_intensity * m_color.b
//   4. Apply intensity scale if non-zero:
//      If any component of m_intensityScale is != 0:
//        scaledColor.r *= m_intensityScale.r
//        scaledColor.g *= m_intensityScale.g
//        scaledColor.b *= m_intensityScale.b
//   5. Zero out the direction output
#if 0
void EIPointLight::LightingParameters(EVec3& dir, float& falloff,
                                       EVec3& pos, EVec3& color) {
    // Falloff radius
    falloff = m_falloffEnd * kFalloffScale;  // 0xC8 * rodata

    // Get position via vtable call
    EVec3 lightPos;
    this->GetPosition(lightPos);  // vtable offset 0x174

    // Compute base scaled color
    f32 intensity = m_intensity;          // 0x8C
    color.x = m_color[0] * intensity;     // 0x90 (via addi r9, r30, 0x90)
    color.y = m_color[1] * intensity;
    color.z = m_color[2] * intensity;

    // Apply intensity scale if non-trivial
    f32 sx = m_intensityScale[0];          // 0x9C
    f32 sy = m_intensityScale[1];
    f32 sz = m_intensityScale[2];

    if (sx != 0.0f || sy != 0.0f || sz != 0.0f) {
        // Further check: if all scale == 1.0, skip (already applied)
        if (sx != 1.0f || sy != 1.0f || sz != 1.0f) {
            color.x *= sx;
            color.y *= sy;
            color.z *= sz;
        }
    }

    // Zero direction (point lights are omnidirectional)
    dir.x = 0.0f;
    dir.y = 0.0f;
    dir.z = 0.0f;

    // Copy to output pos
    pos = dir;  // also zeroed
}
#endif

// ============================================================================
// EISpotLight - Spot Light
// ============================================================================
// Address: 0x8022B1E0 (ctor) | Size: 0xE0 (224 bytes)
// Vtable: 0x804695D8 (400 bytes)
//
// Spot lights emit a cone of light from a position in a direction.
// They add cone angle and direction on top of EIPointLight's fields.
//
// Key fields (from constructor analysis):
//   0x0AC: f32[3] m_position    -- world position
//   0x0B8: f32    m_coneAngle   -- spotlight cone half-angle
//   0x0C4: f32    m_falloffStart
//   0x0C8: f32    m_upX         -- direction/up vector X
//   0x0CC: f32    m_upY         -- direction/up vector Y
//   0x0D0: f32    m_upZ         -- direction/up vector Z
//   0x0D4: u32    m_field_0D4   -- flags/mode
//   0x0D8: f32    m_cosConeAngle -- precomputed cos(coneAngle)
//   0x0DC: f32    m_sinConeAngle -- precomputed sin(coneAngle)

// 0x8022B4E8 - 532 bytes (133 instructions)
// EISpotLight::Setup(void)
//
// Computes derived spotlight parameters from the cone angle and direction.
// This is the largest Setup function (532 bytes) due to the trigonometry
// and matrix construction for the spot cone.
//
// High-level algorithm:
//   1. If m_field_0D4 != 0:
//        Compute view direction from cone angle + position offset
//        via SinCosLookup at 0x802C5930
//      Else:
//        Set default direction {0, 0, 0} and up {0, 1, 0}
//
//   2. Precompute cone parameters:
//        m_cosConeAngle = cos(m_coneAngle * DEG_TO_RAD)
//        m_sinConeAngle = sin(m_coneAngle * DEG_TO_RAD)
//        (using fmuls chains with pi/180 constant from rodata)
//
//   3. Build spotlight orientation matrix for rendering
//
//   4. Call base EILight::SetupInternal() with computed vectors

// ============================================================================
// ELightGrid - Room-Based Light Evaluation Grid
// ============================================================================
// Address: 0x8022FA6C (ctor) | Size: 0x6058 (24664 bytes)
//
// The ELightGrid is the central structure for The Sims 2's room-based lighting
// system. It divides the lot into rooms, each with its own set of contributing
// lights, and evaluates light contributions at grid vertices for smooth
// interpolated lighting across floor tiles.
//
// STRUCTURE LAYOUT:
//
//   0x000: f32    m_gridScale         -- grid cell size (world units)
//   0x004: f32    m_ambientR          -- global ambient red
//   0x008: f32    m_ambientG          -- global ambient green
//   0x00C: f32    m_ambientB          -- global ambient blue
//   0x010: u32    m_portalLightStart  -- start index for portal lights
//   0x014: u32    m_portalLightEnd    -- end index for portal lights
//   0x018: u32    m_pointLightStart   -- start index for point lights
//   0x01C: u32    m_pointLightEnd     -- end index for point lights
//   0x020-0x03B: [padding/unknown]
//   0x03C: u32    m_ambLightPtr       -- ambient light reference
//   0x044: u32    m_vertexLightStart  -- vertex light array start
//   0x048: u32    m_vertexLightEnd    -- vertex light array end
//   0x04C: u32    m_portalStart       -- portal data start
//   0x050: u32    m_portalEnd         -- portal data end
//
//   -- Room grid data (0x054 to 0x6020): 60*60 grid of room assignments --
//   Each cell maps to a room ID, allowing O(1) room lookup by position.
//   Layout is approximately:
//     0x054: RoomTile grid[3968] -- (variable count per Flush)
//     Each RoomTile contains vertex indices and room assignments.
//
//   0x6020: u32   m_numRooms          -- number of active rooms
//   0x6024-0x6057: per-room summary data (outer lot lights, etc.)
//     0x6034: u32 m_outerLotLightR
//     0x6044: u32 m_outerLotLightG
//     0x6054: u32 m_outerLotLightB
//
// INNER STRUCTURES:
//
//   ELightGrid::RoomData (84 bytes per room, up to 40 rooms):
//     Starts at this + 0x6024, stride 0x54
//     0x00: EVec3 m_ambientColor     -- room ambient light color
//     0x0C: f32   m_ambientIntensity -- room ambient intensity
//     0x10: EVec3 m_pointLightColor  -- accumulated point light color
//     0x1C: EILight* m_ambientLight  -- pointer to room's ambient light
//     0x20: EVec3 m_directionalDir   -- directional light direction
//     0x2C: f32   m_directionalIntensity
//     0x30: EVec3 m_directionalColor
//     0x3C: EILight* m_directionalLight
//     0x44: u32   m_localLightStart  -- index range for local point lights
//     0x48: u32   m_localLightEnd
//     0x4C: u32   m_portalLightStart -- index range for portal lights
//     0x50: u32   m_portalLightEnd
//
//   ELightGrid::LightData (32 bytes per light slot):
//     0x00: f32   m_gridScale        -- light's grid position scale
//     0x04: f32   m_unknown
//     0x08: f32   m_unknown2
//     0x0C: f32   m_unknown3
//     0x10: f32   m_red              -- light's red contribution
//     0x14: f32   m_green            -- light's green contribution
//     0x18: f32   m_blue             -- light's blue contribution
//     0x1C: EILight* m_lightPtr      -- pointer to the light source
//
//   ELightGrid::LightWeight (8 bytes per weight entry):
//     0x00: f32   m_weight           -- blend weight for this light
//     0x04: s16   m_lightIndex       -- index into LightData array (-1 = empty)
//     0x06: s16   m_padding
//
//   ELightGrid::VertexData:
//     Contains per-vertex light weight assignments (up to 4 lights per vertex)
//     Used by AddLightsToVertices to build the final per-vertex lighting.

// 0x8022FA6C - 136 bytes (34 instructions)
// ELightGrid::ELightGrid(void)
//
// Constructor initializes the grid with empty state.
// Uses bdnz (branch-decrement-not-zero) loops for bulk initialization:
//   - Loop 1: 512 iterations (initializing room grid - 2048 bytes?)
//   - Loop 2: 40 iterations (RoomData array - 40 rooms max)
//   - Loop 3: 4 iterations (vertex data)
//   - Loop 4: 4 iterations (per-room indices, set to -1)
//
// After loops: sets m_field_008 = 0, calls Flush() to initialize grid state.
#if 0
void ELightGrid::ELightGrid() {
    // Bulk-init room grid (512 * something)
    for (int i = 0; i < 512; i++) { /* bdnz spin */ }

    // Init room data array (40 rooms)
    for (int i = 0; i < 40; i++) { /* bdnz spin */ }

    // Init vertex/portal data
    for (int i = 0; i < 4; i++) { /* bdnz spin */ }

    // Init room indices to -1
    for (int i = 0; i < 4; i++) {
        // sth r0(=-1), 0(r9); addi r9, r9, -2
        roomIndices[3-i] = -1;
    }

    m_field_008 = 0;
    Flush();  // bl 0x8022FAF4
}
#endif

// 0x8022FAF4 - 208 bytes (52 instructions)
// ELightGrid::Flush(void)
//
// Resets the entire light grid to its default empty state.
// Called during initialization and when the lot changes.
//
// Algorithm:
//   1. Initialize tile grid (3968 entries):
//      For each tile index 0..3967:
//        - Set room assignment to -1 (0xFF byte)
//        - Set 4 light weight indices to -1 (0xFFFF half-words)
//      Uses nested loops with bdnz
//
//   2. Flush all 40 RoomData entries:
//      for (i = 0; i < 40; i++)
//        RoomData::Flush()  at this + 0x6024 + i*0x54
//
//   3. Reset grid parameters:
//      m_field_00C = 0  (loop counter)
//      m_pointLightStart = 256
//      m_gridScale = 1.0  (m_field_000 = 1)
//      m_numRooms = 0
//      m_portalLightStart = 0
//      m_portalLightEnd = 0 (m_field_010)
//      m_pointLightEnd = 256
//      m_field_004 = 0
#if 0
void ELightGrid::Flush() {
    // Reset all grid tiles
    int tileCount = 3968;
    u8* tileBase = (u8*)(this + 0x6D44);  // addi r10, r29, 0x6D44
    for (int i = 0; i <= tileCount; i++) {
        tileBase[i] = 0xFF;  // room = unassigned
        // Reset 4 light weights to -1
        s16* weights = (s16*)(tileBase + 4 + i*8 + 6);
        for (int j = 0; j < 4; j++) {
            *weights-- = -1;
        }
    }

    // Flush all room data
    u8* roomBase = (u8*)this + 0x6024;
    for (int i = 0; i < 40; i++) {
        RoomData_Flush(roomBase);  // bl 0x8022FBC4
        roomBase += 0x54;
    }

    // Reset counters
    m_field_00C = 0;
    m_pointLightStart = 256;    // stw r9, 0x18
    m_gridScale = 1;            // stw r0(=1), 0x00
    m_numRooms = 0;             // stw r30(=0), 0x6020
    m_portalLightStart = 0;     // stw r30, 0x14
    m_portalLightEnd = 0;       // stw r30, 0x10
    m_pointLightEnd = 256;      // stw r9, 0x1C
    m_field_004 = 0;            // stw r30, 0x04
}
#endif

// 0x80230608 - 84 bytes (21 instructions)
// ELightGrid::EvaluateLights(void)
//
// Master light evaluation function. Called each frame to update all
// lighting in the grid. Orchestrates the evaluation pipeline:
//
//   1. EvaluatePointLights(m_pointLightStart, m_pointLightEnd)
//      - Evaluates all point lights in their range
//   2. EvaluateAmbientAndDirectionalLights()
//      - Per-room ambient and directional light evaluation
//   3. EvaluatePortalLights(m_portalLightStart, m_portalLightEnd)
//      - Evaluates portal lights (light bleeding between rooms)
//   4. EvaluateOuterLotLights()
//      - Evaluates outdoor/exterior lighting
#if 0
void ELightGrid::EvaluateLights() {
    EvaluatePointLights(m_pointLightStart, m_pointLightEnd);  // 0x18, 0x1C
    EvaluateAmbientAndDirectionalLights();
    EvaluatePortalLights(m_portalLightStart, m_portalLightEnd);  // 0x10, 0x14
    EvaluateOuterLotLights();
}
#endif

// 0x802302B4 - 288 bytes (72 instructions)
// ELightGrid::EvaluatePointLights(int startIdx, int endIdx)
//
// Evaluates all point lights in the given index range. For each light slot:
//
// Algorithm:
//   for (int i = startIdx; i < endIdx; i++) {
//     LightData* ld = &lightData[i];  // stride 32 bytes, base offset 0x20
//     EILight* light = ld->m_lightPtr; // offset 0x1C in LightData
//
//     // Call RoomData::FindClosestLights via vtable to get
//     // the light's parameters at this grid vertex
//     light->vtable[0x150/4](light, &outParams, &r29, &r31, &r28);
//
//     // Clamp RGB to [0.0, 1.0]
//     f32 r = ld->m_red;   // offset 0x10
//     f32 g = ld->m_green; // offset 0x14
//     f32 b = ld->m_blue;  // offset 0x18
//
//     r = clamp(r, 0.0, 1.0);
//     g = clamp(g, 0.0, 1.0);
//     b = clamp(b, 0.0, 1.0);
//
//     ld->m_red = r;
//     ld->m_green = g;
//     ld->m_blue = b;
//   }
//
// The clamping uses 0.0 (rodata -3512) and 1.0 (rodata -3508) constants.
// Stride is 32 bytes per LightData (addi r28/r29/r31, +32 per iteration).
#if 0
void ELightGrid::EvaluatePointLights(int start, int end) {
    if (start >= end) return;

    f32 kMin = 0.0f;  // rodata -3512
    f32 kMax = 1.0f;  // rodata -3508

    for (int i = start; i < end; i++) {
        LightData* ld = GetLightSlot(i);  // base + i*32 + 32
        EILight* light = ld->m_lightPtr;

        // Evaluate light contribution at vertex via vtable
        EVec3 outParams;
        light->CalcLightContribution(&outParams, ...);

        // Clamp R channel
        f32 r = ld->m_red;
        if (r < kMin) r = kMin;
        else if (r > kMax) r = kMax;
        ld->m_red = r;

        // Clamp G channel
        f32 g = ld->m_green;
        if (g < kMin) g = kMin;
        else if (g > kMax) g = kMax;
        ld->m_green = g;

        // Clamp B channel
        f32 b = ld->m_blue;
        if (b < kMin) b = kMin;
        else if (b > kMax) b = kMax;
        ld->m_blue = b;
    }
}
#endif

// 0x802306E4 - 88 bytes (22 instructions)
// ELightGrid::EvaluateAmbientAndDirectionalLights(void)
//
// Iterates all active rooms and evaluates their ambient + directional lights.
//
// Algorithm:
//   for (int i = 0; i < m_numRooms; i++) {
//     RoomData* room = &rooms[i];  // this + 0x6024 + i*0x54
//     room->EvaluateAmbientAndDirectionalLights();
//   }
#if 0
void ELightGrid::EvaluateAmbientAndDirectionalLights() {
    int numRooms = m_numRooms;  // lwz r0, 0x6020(r29)

    for (int i = 0; i < numRooms; i++) {
        RoomData* room = (RoomData*)((u8*)this + 0x6024 + i * 0x54);
        room->EvaluateAmbientAndDirectionalLights();  // bl 0x8023073C
    }
}
#endif

// 0x8023073C - 144 bytes (36 instructions)
// ELightGrid::RoomData::EvaluateAmbientAndDirectionalLights(void)
//
// Evaluates ambient and directional lights for a single room.
//
// Algorithm:
//   1. If m_ambientLight (offset 0x1C) is non-null:
//      Call ambientLight->LightingParameters(this, this+0x0C, this, this+0x10)
//      This fills in the room's ambient color and intensity.
//      (vtable offset 0x150/0x154 = LightingParameters)
//
//   2. If m_directionalLight (offset 0x3C) is non-null:
//      Call dirLight->LightingParameters(this+0x20, this+0x2C, stackLocal, this+0x30)
//      This fills in the directional light direction and color.
//
// The LightingParameters call uses vtable dispatch (blrl) with offsets
// computed from the light's vtable at 0x150 (offset) and 0x154 (handler).
#if 0
void ELightGrid::RoomData::EvaluateAmbientAndDirectionalLights() {
    // Ambient light
    EILight* ambLight = m_ambientLight;  // lwz r11, 0x1C(r31)
    if (ambLight != NULL) {
        ambLight->LightingParameters(
            *(EVec3*)this,              // out direction (unused for ambient)
            *(float*)((u8*)this + 0x0C), // out falloff
            *(EVec3*)this,              // out position (unused)
            *(EVec3*)((u8*)this + 0x10)  // out color
        );
    }

    // Directional light
    EILight* dirLight = m_directionalLight;  // lwz r11, 0x3C(r31)
    if (dirLight != NULL) {
        EVec3 stackLocal;
        dirLight->LightingParameters(
            *(EVec3*)((u8*)this + 0x20),  // out direction
            *(float*)((u8*)this + 0x2C),  // out falloff/intensity
            stackLocal,                    // temporary
            *(EVec3*)((u8*)this + 0x30)    // out color
        );
    }
}
#endif

// 0x80230FFC - 68 bytes (17 instructions)
// ELightGrid::EvaluateLamps(void)
//
// Evaluates lamp-type lights (furniture lamps that can be toggled).
// Calls the same point/portal light evaluators but uses different ranges.
//
// Algorithm:
//   EvaluatePointLights(m_pointLightStart, m_pointLightEnd);
//   EvaluatePortalLights(m_portalLightStart, m_portalLightEnd);
#if 0
void ELightGrid::EvaluateLamps() {
    EvaluatePointLights(m_pointLightStart, m_pointLightEnd);  // 0x18, 0x1C
    EvaluatePortalLights(m_portalLightStart, m_portalLightEnd);  // 0x10, 0x14
}
#endif

// 0x80231040 - 224 bytes (56 instructions)
// ELightGrid::EvaluateLampsOn(void)
//
// Called when a lamp is turned on. Re-evaluates the affected lights
// and their contributions, reading from the light's color data.
//
// For each point light in range [m_pointLightStart, m_pointLightEnd):
//   Read the light's color from its EILight (offset 0x90 = m_color)
//   Clamp each channel to [0.0, 1.0]
//   Store back into the grid's LightData slots
//
// Then calls EvaluatePortalLights for portal light updates.
//
// Constants:
//   0.0f from rodata -3436
//   1.0f from rodata -3432
#if 0
void ELightGrid::EvaluateLampsOn() {
    f32 kMin = 0.0f;
    f32 kMax = 1.0f;

    int start = m_pointLightStart;  // 0x18
    int end = m_pointLightEnd;      // 0x1C

    for (int i = start; i < end; i++) {
        LightData* ld = GetLightSlot(i);  // stride 32, offset 0x20
        EILight* light = ld->m_lightPtr;  // offset 0x1C

        // Read color from light's color array at offset 0x90
        f32* color = (f32*)((u8*)light + 0x90);

        // Channel 0 (red)
        f32 r = color[0];
        ld->m_red = clamp(r, kMin, kMax);

        // Channel 1 (green)
        f32 g = color[1];
        ld->m_green = clamp(g, kMin, kMax);

        // Channel 2 (blue)
        f32 b = color[2];
        ld->m_blue = clamp(b, kMin, kMax);
    }

    // Also update portal lights
    EvaluatePortalLights(m_portalLightStart, m_portalLightEnd);
}
#endif

// 0x802303D4 - 564 bytes (141 instructions)
// ELightGrid::AddLightsToVertices(void)
//
// The most complex grid function (564 bytes). Builds per-vertex light
// assignments from the evaluated room/light data.
//
// Architecture:
//   The lot is divided into a grid (approximately 60x60 tiles).
//   For each grid vertex, this function:
//     1. Determines which room the vertex belongs to
//     2. Queries the room's closest lights (up to 4 per vertex)
//     3. Assigns light weights for smooth blending
//     4. Selects the top contributing lights from the candidate set
//
// The outer loops iterate over grid coordinates (triple-nested):
//   - Outer: tiles in X (r8, starts at 2, up to 0x3D = 61)
//   - Middle: tiles in Z (r10, starts at 2, up to 0x3D)
//   - Inner: room entries per tile (r10 inner, up to 3)
//
// Each tile stores up to 4 room assignments (checked for -1 = empty).
// For each valid room:
//   1. Clear 4 LightWeight slots to {-1, 0.0}
//   2. Call RoomData::FindClosestLights() with local + portal light ranges
//   3. Count valid weights (index != -1)
//   4. Call FindClosestLights again with remaining slots
//   5. Select best lights by highest weight using max-search
//   6. Store final light assignments to vertex data
//
// The int-to-float conversion at 0x80230424 uses the standard PowerPC
// trick: xoris r0, r8, 0x8000; stw; lfd; fsub with magic constant.

// 0x800461E0 - 280 bytes (70 instructions)
// EvaluateFloorLights(ELightGrid &, int roomId, EVec3 &outAmbient, EVec3 &outDir)
//
// Free function that extracts a room's lighting for floor rendering.
// Used by the floor tile renderer to get ambient + directional light colors.
//
// Parameters:
//   r3 = ELightGrid reference
//   r4 = room ID
//   r5 = output ambient color (EVec3&)
//   r6 = output directional color (EVec3&)
//
// Algorithm:
//   1. Compute RoomData pointer: grid + roomId * 84 + 24612
//      (mulli r4, r4, 0x54; addi r4, 0x6024; add r3, r3, r4)
//
//   2. If room has point lights (offset 0x1C in RoomData != 0):
//      Copy ambient color from RoomData offset 0x10 (EVec3)
//   Else:
//      Set ambient to {0, 0, 0}
//
//   3. If room has directional light (offset 0x3C != 0):
//      Negate the direction Y component (fneg)
//      Clamp to >= 0.0 (directional light points downward)
//      Scale directional color by the clamped direction
//      Copy to output
//   Else:
//      Set directional to {0, 0, 0}
#if 0
void EvaluateFloorLights(ELightGrid& grid, int roomId,
                          EVec3& outAmbient, EVec3& outDirectional) {
    // Access room data
    RoomData* room = (RoomData*)((u8*)&grid + roomId * 0x54 + 0x6024);

    // Ambient light
    if (room->m_ambientLight != NULL) {  // offset 0x1C
        outAmbient = room->m_pointLightColor;  // offset 0x10
    } else {
        outAmbient = {0.0f, 0.0f, 0.0f};
    }

    // Directional light
    if (room->m_directionalLight != NULL) {  // offset 0x3C
        f32 dirY = -room->m_directionalDir.y;  // offset 0x28, negated
        f32 clamped = (dirY < 0.0f) ? 0.0f : dirY;

        outDirectional.x = clamped * room->m_directionalColor.x;  // 0x30
        outDirectional.y = clamped * room->m_directionalColor.y;  // 0x34 (via +4)
        outDirectional.z = clamped * room->m_directionalColor.z;  // 0x38 (via +8)
    } else {
        outDirectional = {0.0f, 0.0f, 0.0f};
    }
}
#endif

// ============================================================================
// REffectsEmitter - Emitter Resource
// ============================================================================
// Address: 0x8036A7B4 (ctor) | Size: 0x24 (36 bytes)
// Vtable: 0x8046E028 (144 bytes = 36 entries)
//
// Inherits from a base resource class (ctor calls 0x80311DC8).
// The emitter resource holds the data needed to create particle effects.

// 0x8036A7B4 - 80 bytes (20 instructions)
// REffectsEmitter::REffectsEmitter(void)
//
// Constructs an emitter resource with empty state:
//   - Calls base resource ctor at 0x80311DC8
//   - Sets vtable to 0x8046_E028
//   - m_field_014 = 0 (emitter init data ptr)
//   - m_field_018 = 0 (particle birth data ptr)
//   - m_field_01C = 0 (texture ptr)
//   - m_field_020 = 0 (refresh flag)
#if 0
void REffectsEmitter::REffectsEmitter() {
    RResource::RResource();          // bl 0x80311DC8
    _vtable = &REffectsEmitter_vtable;  // 0x8046_E028 (lis r9,-32697; addi r9,-8152)

    m_field_014 = 0;   // stw r0(=0), 0x14
    m_field_018 = 0;   // stw r0, 0x18
    m_field_01C = 0;   // stw r0, 0x1C
    m_field_020 = 0;   // stw r0, 0x20
}
#endif

// 0x8036AD78 - 8 bytes
// REffectsEmitter::GetEmitterInitData(void)
// Returns the emitter initialization data pointer (offset 0x14).
#if 0
void* REffectsEmitter::GetEmitterInitData() {
    return m_field_014;  // lwz r3, 0x14(r3); blr
}
#endif

// 0x8036AD80 - 8 bytes
// REffectsEmitter::GetParticleBirthData(void)
// Returns the particle birth data pointer (offset 0x18).
#if 0
void* REffectsEmitter::GetParticleBirthData() {
    return m_field_018;  // lwz r3, 0x18(r3); blr
}
#endif

// 0x8036AD88 - 8 bytes
// REffectsEmitter::GetTexture(void)
// Returns the texture resource pointer (offset 0x1C).
#if 0
void* REffectsEmitter::GetTexture() {
    return m_field_01C;  // lwz r3, 0x1C(r3); blr
}
#endif

// 0x8036A860 - 100 bytes (25 instructions)
// REffectsEmitter::Deallocate(void)
//
// Frees the emitter's allocated particle birth data.
// Called during destruction or when the resource is refreshed.
//
// Algorithm:
//   1. Call vtable function at offset 0x68/0x6C to deallocate sub-resources
//      (this is the base resource's Deallocate dispatcher)
//   2. If m_field_018 (birth data) is non-null:
//      - Get current heap via EAHeap::GetCurrentHeap() at 0x802CFF00
//      - Free the birth data via EAHeap::Free() at 0x802D0D78
//      - Set m_field_018 = 0
//      - Set m_field_014 = 0
#if 0
void REffectsEmitter::Deallocate() {
    // Call base deallocation via vtable
    s16 offset = *(s16*)(_vtable + 0x68);    // lha r3, 0x68(r9)
    void* handler = *(void**)(_vtable + 0x6C); // lwz r0, 0x6C(r9)
    ((void(*)(void*))handler)((u8*)this + offset);  // blrl

    if (m_field_018 != NULL) {
        void* heap = EAHeap::GetCurrentHeap();   // bl 0x802CFF00
        EAHeap::Free(heap, m_field_018);          // bl 0x802D0D78
        m_field_018 = NULL;
        m_field_014 = NULL;
    }
}
#endif

// 0x8036A904 - 96 bytes (24 instructions)
// REffectsEmitter::AddRefSubResources(void)
//
// Increments reference counts on sub-resources (texture).
// Called when the emitter resource is referenced by a new effect instance.
//
// Algorithm:
//   1. Set m_field_01C = 0 (clear texture ref)
//   2. If m_field_014 (init data) != NULL:
//      If initData->offset_0xC0 (texture key) != NULL:
//        Load texture via resource manager lookup:
//          ResourceManager::FindResource(textureTypeName, textureKey, 0, 0)
//          at 0x80326CF8
//        Store result in m_field_01C
#if 0
void REffectsEmitter::AddRefSubResources() {
    m_field_01C = NULL;

    void* initData = m_field_014;  // lwz r4, 0x14(r31)
    if (initData != NULL) {
        void* textureKey = *(void**)((u8*)initData + 0xC0);  // lwz r4, 0xC0(r4)
        if (textureKey != NULL) {
            // Look up texture resource
            void* typeName = (void*)0x804CE33C;  // lis r3,-32692; addi r3,-7364
            m_field_01C = ResourceManager::FindResource(typeName, textureKey, 0, 0);
        }
    }
}
#endif

// 0x8036A9D0 - 244 bytes (61 instructions)
// REffectsEmitter::Load(EFile *)
//
// Loads emitter resource data from an .arc file.
//
// Algorithm:
//   1. Call Deallocate() to free any existing data
//   2. If file is NULL, return
//   3. Open EChunkedFile on stack (addi r3, r1, 8; bl 0x8035AE70)
//   4. Begin chunk with tag 'EEMT' (0x45454D54):
//      lis r5, 0x4545; ori r5, r5, 0x4D54
//      Version range: min=1, max=1
//   5. If chunk not found: close file, return
//   6. Read chunk header data (bl 0x8035B320)
//   7. Extract version from header byte into m_field_010:
//      rlwimi r0, r9, 8, 0, 23  (insert version byte)
//   8. Allocate particle birth data:
//      EAHeap::GetCurrentHeap()
//      EAHeap::AllocAligned(64, 0, 0)  -- 64-byte aligned allocation
//   9. Store allocated pointers:
//      m_field_018 = allocPtr           (raw birth data)
//      m_field_014 = allocPtr + 0x90    (emitter init data starts 144 bytes in)
//  10. Load sub-resource data from file via vtable dispatch
//  11. Dispatch additional sub-resource loader via vtable[0x70/0x74]
//  12. Close chunk file

// ============================================================================
// REffectsSequencer - Sequencer Resource
// ============================================================================
// Address: 0x8036AE70 (ctor) | Size: ~0x14 (20 bytes)
// Vtable: 0x8046E0B8 (144 bytes)
//
// Sequences multiple emitters to create complex multi-part effects.
// Lighter than REffectsEmitter -- mainly holds a list of emitter references.

// 0x8036AE70 - 60 bytes (15 instructions)
// REffectsSequencer::REffectsSequencer(void)
//
// Minimal constructor:
//   - Calls base resource ctor at 0x80311DC8
//   - Sets vtable to 0x8046_E0B8
// No additional field initialization (sequencer data loaded from file).
#if 0
void REffectsSequencer::REffectsSequencer() {
    RResource::RResource();              // bl 0x80311DC8
    _vtable = &REffectsSequencer_vtable; // 0x8046_E0B8
}
#endif

// 0x8036AF4C - 176 bytes (44 instructions)
// REffectsSequencer::Load(EFile *)
//
// Loads sequencer data from file. Similar pattern to REffectsEmitter::Load:
//   1. Deallocate() existing data
//   2. Open EChunkedFile with tag 'ESEQ' (0x45534551)
//      lis r5, 0x4553; ori r5, r5, 0x4551
//   3. Read version into m_field_010
//   4. Dispatch sub-resource loading via vtable[0x70/0x74]
//   5. Close chunk file
//
// Note: No allocation step (unlike emitter) -- sequencer just references
// emitter resources, which are loaded separately.

// ============================================================================
// RParticle - Particle Definition Resource
// ============================================================================
// Address: 0x8036B2E8 (ctor) | Size: ~0x3C (60 bytes)
// Vtable: 0x8046E148 (144 bytes)
//
// Defines particle visual properties, animation curves, and physics.

// 0x8036B2E8 - 100 bytes (25 instructions)
// RParticle::RParticle(void)
//
// Constructs a particle resource:
//   - Calls base resource ctor
//   - Sets vtable to 0x8046_E148
//   - Zeros out 8 dwords at offsets 0x18-0x38 (bdnz loop, 8 iterations)
//     This clears the particle data array pointers
//   - m_field_018 = 0
//   - m_field_014 = 0
#if 0
void RParticle::RParticle() {
    RResource::RResource();
    _vtable = &RParticle_vtable;

    m_field_018 = 0;
    m_field_014 = 0;

    // Zero out data array (8 entries, 4 bytes each, stored backwards)
    u32* p = (u32*)((u8*)this + 0x38);
    for (int i = 0; i < 8; i++) {
        *p = 0;
        p--;  // addi r9, r9, -4
    }
}
#endif

// 0x8036B6BC - 1596 bytes (399 instructions)
// RParticle::PrepareData(void)
//
// The largest function in the particle system. Converts raw loaded particle
// data into runtime-ready format by applying unit conversions and
// pre-computing animation curves.
//
// High-level operations (from first ~100 instructions analyzed):
//
//   1. Get raw data pointer from m_field_014:
//      r31 = this->m_field_014   (offset 0x14)
//
//   2. Validate/fix zero lifetime:
//      If data[0x110] == 0.0:
//        Set data[0x110] = default_lifetime (rodata 13540)
//        Also set data[0xD4], data[0xE8], data[0xFC] to same value
//
//   3. Convert angle units (degrees to radians scaled):
//      Multiple fields multiplied by conversion constants from rodata:
//        - data[0xC8] (dispersion angle) *= DEG_TO_RAD (rodata 13548)
//        - data[0x7C], [0x80], [0x84] (rotation) *= SCALE (rodata 13544)
//        - data[0x50], [0x54], [0x5C], [0x60], [0x64] *= SCALE
//        - data[0x104], [0x108], [0x10C] *= SCALE
//        - data[0xBC], [0xC0], [0xC4] (angular velocity) *= ANGLE_SCALE (13552)
//        - data[0x120+] (sub-emitter angles) *= SCALE
//
//   4. Build animation curves:
//      For each animated property (size, color, alpha, rotation):
//        - Read keyframe count and data from the raw buffer
//        - Interpolate control points
//        - Store pre-computed curve data
//
//   5. The function uses 1704 bytes of stack space (stwu r1, -1704(r1))
//      indicating substantial local computation buffers.

// ============================================================================
// REffectsAttachment - Bone Attachment Resource
// ============================================================================
// Address: 0x80322400 (ctor) | Size: 0x20 (32 bytes)
// Vtable: 0x8046B7C0 (144 bytes)
//
// Connects particle effects to skeleton bones for character animations.

// 0x80322780 - 300 bytes (75 instructions)
// REffectsAttachment::Load(EFile *)
//
// Loads attachment data from file.
//
// Algorithm:
//   1. If file is NULL, return
//   2. Open EChunkedFile with tag 'EATC' (0x45415443):
//      lis r5, 0x4541; ori r5, r5, 0x5443
//      Version range: min=2, max=2
//   3. If version < 2: fall back to OldLoad() (legacy v1 format)
//      OldLoad handles the 652-byte legacy attachment format.
//   4. Read chunk header, extract version
//   5. Compute entry count: version_byte >> 3 (srwi r5, r5, 3)
//      (Each attachment entry is 8 bytes)
//   6. Resize vector at this+0x14 to hold entries:
//      - Check current capacity vs needed
//      - If insufficient: call vector::resize at 0x803C5F34
//   7. Read attachment entries from file via vtable dispatch:
//      Stream read with stride from file's vtable[0x18/0x1C]
//      Reads into vector data at this+0x14

// 0x80065CE4 - 260 bytes (65 instructions)
// SAnimator2::_handleParticleEvent(REffectsAttachment *)
//
// Called when an animation reaches a particle event keyframe.
// Iterates the attachment's bone entries and spawns effects.
//
// Algorithm:
//   1. Get entry count from attachment vector (offset 0x14 to 0x18, stride 8)
//   2. Load mirror flag from r13-relative global (-18451)
//   3. For each entry (8-byte stride):
//      a. If entry->effectPtr (offset +4) is NULL: skip
//      b. If entry->boneIndex (offset +1, sign-extended) <= 0: skip
//      c. Store bone count and effect ptr to stack locals
//      d. Read bone index (offset +0, sign-extended as s8)
//      e. Store as s16 at stack+0x10
//      f. Check if bone is valid via model vtable call (offset 0x118):
//         model->HasBone(boneIndex)
//      g. If bone not found: try alternate lookup via vtable 0x330
//      h. If found: OR bone index with mirror flag (r26)
//         Else: use raw bone index
//      i. Call internal spawn function at 0x80065DE8 with:
//         (this, stackParams, 0)

// ============================================================================
// Effects::EffectsManager - Runtime Effect Manager
// ============================================================================

// 0x80352634 - 220 bytes (55 instructions)
// Effects::EffectsManager::CreateEffect(REffectsEmitter &, Effect::ClientParams *)
//
// Creates a runtime particle effect from an emitter resource definition.
//
// Algorithm:
//   1. If manager not initialized (this->field_000 == 0): return NULL
//   2. Allocate FastParticleEmitter:
//      - EAHeap::GetCurrentHeap()
//      - EAHeap::AllocAligned(0x1A8, 16, 0, 0)  (424 bytes, 16-byte aligned)
//   3. If ClientParams provided:
//        Construct with params: FastParticleEmitter::FastParticleEmitter(params)
//      Else:
//        Default construct: FastParticleEmitter::FastParticleEmitter()
//   4. Init with emitter resource:
//      FastParticleEmitter::Init(emitterResource)   at 0x80353C84
//   5. If Init returns 0 (failure):
//      - Destroy the effect via vtable call at offset 0x08 (Destroy)
//        with param=3 (cleanup mode)
//      - Return NULL
//   6. If Init succeeds:
//      - Call AddEffect(this, effect) at 0x803527D0
//      - Return the new effect
#if 0
Effects::Effect* Effects::EffectsManager::CreateEffect(
    REffectsEmitter& emitter, Effect::ClientParams* params)
{
    if (m_initialized == 0) return NULL;  // lwz r0, 0(r30); cmpwi; beq

    FastParticleEmitter* effect;

    // Allocate 424 bytes, 16-byte aligned
    void* heap = EAHeap::GetCurrentHeap();
    void* mem = EAHeap::AllocAligned(heap, 0x1A8, 16, 0, 0);

    if (params != NULL) {
        effect = new(mem) FastParticleEmitter(params);  // bl 0x8035312C
    } else {
        effect = new(mem) FastParticleEmitter();          // bl 0x803530C4
    }

    // Initialize with emitter resource
    int result = effect->Init(emitter);  // bl 0x80353C84
    if (result == 0) {
        // Init failed -- destroy
        effect->Destroy(3);  // vtable call offset 0x08
        return NULL;
    }

    // Success -- register with manager
    AddEffect(effect);  // bl 0x803527D0
    return effect;
}
#endif

// 0x80353C84 - 132 bytes (33 instructions)
// Effects::FastParticleEmitter::Init(REffectsEmitter &)
//
// Initializes a fast particle emitter from its resource definition.
//
// Algorithm:
//   1. Store emitter resource ref at this+0x1A0 (offset 416)
//   2. Increment emitter refcount: RResource::AddRef(emitter) at 0x80312000
//   3. Call SharedInitPart1() at 0x80353344 for basic setup
//   4. Copy emitter's init data ptr to this+0x18C (offset 396):
//      this->m_initData = emitter.m_field_014
//   5. If init data is NULL: return 0 (failure)
//   6. Read particle type byte from initData[0xA8]:
//      lbz r0, 0xA8(r9) -> stb this+0x166
//   7. Copy texture ptr: this+0x194 = emitter.m_field_01C (offset 28)
//   8. Copy birth data: this+0x190 = emitter.m_field_018 (offset 24)
//   9. If birth data is non-NULL:
//      Call SharedInitPart2() at 0x80353398 for full initialization
//      Return result
//   10. If birth data is NULL: return 0 (failure)
#if 0
int Effects::FastParticleEmitter::Init(REffectsEmitter& emitter) {
    m_emitterResource = &emitter;     // stw r30, 0x1A0(r31)
    RResource::AddRef(&emitter);       // bl 0x80312000

    SharedInitPart1();                 // bl 0x80353344

    void* initData = emitter.GetEmitterInitData();  // lwz r9, 0x14(r30)
    m_initData = initData;             // stw r9, 0x18C(r31)

    if (initData == NULL) return 0;

    m_particleType = *(u8*)((u8*)initData + 0xA8);  // lbz; stb 0x166
    m_texture = emitter.GetTexture();     // lwz 0x1C(r30); stw 0x194(r31)
    m_birthData = emitter.GetParticleBirthData();  // lwz 0x18(r30); stw 0x190(r31)

    if (m_birthData != NULL) {
        return SharedInitPart2();        // bl 0x80353398
    }
    return 0;
}
#endif

// ============================================================================
// SYSTEM INTEGRATION SUMMARY
// ============================================================================
//
// The particle and lighting systems interact at several points:
//
// 1. PARTICLE EFFECTS do NOT participate in the light grid.
//    They are rendered additively on top of the lit scene.
//    Particles get their visual appearance from:
//      - RParticle texture and color curves
//      - REffectsEmitter birth/init parameters
//      - FastParticleEmitter runtime state (position, rotation, scale)
//
// 2. SCENE LIGHTING flows through the ELightGrid:
//    a. ELightGrid::Update() is called with the light list and room data
//    b. Lights are sorted into rooms based on room ID / spatial queries
//    c. EvaluateLights() runs the full pipeline:
//       - Point lights evaluated per-vertex
//       - Ambient/directional evaluated per-room
//       - Portal lights propagated between connected rooms
//       - Outer lot lights for exterior areas
//    d. AddLightsToVertices() builds final per-vertex light assignments
//    e. Floor/object renderers query GetLightWeightsAtLocation()
//       to get interpolated lighting at any world position
//
// 3. LAMP TOGGLE HANDLING:
//    When a sim turns a lamp on/off:
//      - EHouse::SetLightIntensityScaleFromRoom(EILight*) updates the light
//      - ELightGrid::EvaluateLampsOn() re-evaluates affected grid vertices
//      - The static flag EILight::m_haveLightsChanged is set to trigger
//        re-evaluation on the next frame
//
// 4. PORTAL LIGHT BLEEDING:
//    EIPortalPointLight instances represent light leaking through doorways.
//    ELightGrid::ConnectPortalLights() establishes which rooms can see
//    each other's lights, and EvaluatePortalLight() computes the
//    attenuated contribution through each portal opening.
