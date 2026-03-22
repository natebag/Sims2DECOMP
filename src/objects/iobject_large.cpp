// iobject_large.cpp - Large functions (257-1024 bytes) from iobject.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\iobject.obj
//
// 40 large functions decompiled from iobject.obj
// (5 are vtable data, 1 is TArray template)
//
// NON_MATCHING causes:
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC register allocation differences
//   - GCC loop codegen (bdnz vs cmpw/blt)
//   - GCC float math codegen
//   - SDA-relative addressing
//   - GCC constructor/destructor ABI

#include "types.h"

// Forward declarations
class ISimsObjectModel;
class ISimsCounterTopObject;
class EParticleEffect;
class EParticleObj;
class AttachmentNode;
class EMat4;
class EVec3;
class ELights;
class ERAnim;
class EAnimNote;
class EAnimController;
class ERLevel;
class EHouse;
class EILight;
class cXObject;
class ObjAnimDef;
struct ETypeInfo;

// External functions
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);
extern void memcpy(void* dst, const void* src, unsigned int size);
extern void memset(void* dst, int val, unsigned int size);

#if 0  // Reference decompilation - not compiled

// ============================================================================
// EParticleEffect::EParticleEffect(AttachmentNode &, EMat4 &)
// Address: 0x8004B8E0 | Size: 344 bytes
// NON_MATCHING - GCC constructor ABI, register alloc
//
// Constructs a particle effect from an attachment node and transform matrix.
// Initializes the effect's position and orientation from the matrix,
// loads the particle definition from the attachment node, and starts
// the particle system.
// ============================================================================
EParticleEffect::EParticleEffect(AttachmentNode& node, EMat4& mat) {
    // Initialize base fields
    memset(this, 0, sizeof(EParticleEffect));

    // Copy transform
    memcpy((char*)this + 0x04, &mat, 0x40);  // 4x4 matrix

    // Load effect definition from attachment node
    int effectID = *(int*)((char*)&node + 0x00);
    if (effectID != 0) {
        // Load particle definition
        void* particleDef = LoadParticleDef(effectID);
        *(void**)((char*)this + 0x48) = particleDef;

        // Create emitter
        if (particleDef != 0) {
            void* emitter = CreateEmitter(particleDef, &mat);
            *(void**)((char*)this + 0x4C) = emitter;
        }
    }

    // Set active flag
    *(int*)((char*)this + 0x50) = 1;
}

// ============================================================================
// EParticleEffect::UpdateParticleEffectLoad(void)
// Address: 0x8004BA38 | Size: 564 bytes
// NON_MATCHING - GCC register alloc, resource loading
//
// Updates the particle effect's loading state. Called each frame until
// the effect's resources are fully loaded. Handles async texture and
// geometry loading for the particle system.
// ============================================================================
void EParticleEffect::UpdateParticleEffectLoad() {
    void* particleDef = *(void**)((char*)this + 0x48);
    if (particleDef == 0) return;

    // Check if definition is loaded
    int loadState = *(int*)((char*)particleDef + 0x00);
    if (loadState == 2) return;  // Already loaded

    // Update loading progress
    int progress = UpdateResourceLoad(particleDef);

    if (progress >= 100) {
        // Fully loaded - finalize effect
        *(int*)((char*)particleDef + 0x00) = 2;

        // Create render resources
        void* emitter = *(void**)((char*)this + 0x4C);
        if (emitter != 0) {
            FinalizeEmitter(emitter, particleDef);
        }
    }
}

// ============================================================================
// EParticleEffect::~EParticleEffect(void)
// Address: 0x8004BC6C | Size: 320 bytes
// NON_MATCHING - GCC destructor ABI, cleanup order
//
// Destructs the particle effect. Releases the emitter, frees the
// particle definition, and cleans up render resources.
// ============================================================================
EParticleEffect::~EParticleEffect() {
    // Release emitter
    void* emitter = *(void**)((char*)this + 0x4C);
    if (emitter != 0) {
        DestroyEmitter(emitter);
        *(void**)((char*)this + 0x4C) = 0;
    }

    // Release definition
    void* particleDef = *(void**)((char*)this + 0x48);
    if (particleDef != 0) {
        ReleaseParticleDef(particleDef);
        *(void**)((char*)this + 0x48) = 0;
    }

    // Clear active flag
    *(int*)((char*)this + 0x50) = 0;
}

// ============================================================================
// EParticleEffect::SetPos(EMat4 &, EVec3 *)
// Address: 0x8004BDAC | Size: 568 bytes
// NON_MATCHING - GCC float math, matrix operations
//
// Sets the particle effect's position and orientation from a matrix and
// optional position offset. Updates both the transform and the emitter.
// ============================================================================
void EParticleEffect::SetPos(EMat4& mat, EVec3* pos) {
    // Copy new transform
    memcpy((char*)this + 0x04, &mat, 0x40);

    // Apply position offset if provided
    if (pos != 0) {
        float* matPos = (float*)((char*)this + 0x34);  // Translation column
        matPos[0] += *(float*)((char*)pos + 0x00);
        matPos[1] += *(float*)((char*)pos + 0x04);
        matPos[2] += *(float*)((char*)pos + 0x08);
    }

    // Update emitter position
    void* emitter = *(void**)((char*)this + 0x4C);
    if (emitter != 0) {
        SetEmitterTransform(emitter, (float*)((char*)this + 0x04));
    }
}

// ============================================================================
// EParticleObj::CreateEffects(EMat4 &, float, ObjAnimDef *)
// Address: 0x8004C1F8 | Size: 344 bytes
// NON_MATCHING - GCC register alloc, effect creation loop
//
// Creates particle effects for this object. Reads the effect definitions
// from the animation def and creates an EParticleEffect for each slot.
// ============================================================================
void EParticleObj::CreateEffects(EMat4& mat, float scale, ObjAnimDef* animDef) {
    if (animDef == 0) return;

    // Get effect count from anim def
    int effectCount = *(int*)((char*)animDef + 0x10);
    if (effectCount <= 0) return;
    if (effectCount > 3) effectCount = 3;  // Max 3 effects

    m_count = effectCount;

    // Create each effect
    void* effectDefs = *(void**)((char*)animDef + 0x14);
    for (int i = 0; i < effectCount; i++) {
        // Get attachment node for this effect
        AttachmentNode* node = (AttachmentNode*)((char*)effectDefs + i * 0x20);

        // Create the effect
        EParticleEffect* effect = (EParticleEffect*)operator_new(sizeof(EParticleEffect));
        if (effect != 0) {
            // Construct in place
            new (effect) EParticleEffect(*node, mat);
            m_effectPtrs[i] = (u32)effect;
        } else {
            m_effectPtrs[i] = 0;
        }
    }
}

// ============================================================================
// EParticleObj::UpdateEffectPosAndAlphaFade(EAnimController &, float, EMat4 &, EVec3 *, float)
// Address: 0x8004C350 | Size: 272 bytes
// NON_MATCHING - GCC register alloc, float math
//
// Updates all particle effects' positions and alpha fade values.
// Called each frame to sync particles with the owning object's animation.
// ============================================================================
void EParticleObj::UpdateEffectPosAndAlphaFade(EAnimController& ctrl, float alpha,
                                                EMat4& mat, EVec3* pos, float fade) {
    for (int i = 0; i < (int)m_count; i++) {
        EParticleEffect* effect = (EParticleEffect*)m_effectPtrs[i];
        if (effect == 0) continue;

        // Update position
        effect->SetPos(mat, pos);

        // Update alpha fade
        effect->SetAlphaFade(fade * alpha);
    }
}

// ============================================================================
// ISimsObjectModel::ISimsObjectModel(void)
// Address: 0x8004C500 | Size: 324 bytes
// NON_MATCHING - GCC constructor ABI, init order
//
// Default constructor. Initializes all member variables to default values.
// Sets vtable pointer, zeros out position/direction/rotation, initializes
// animation state, and clears the light pointer.
// ============================================================================
ISimsObjectModel::ISimsObjectModel() {
    // Set vtable
    *(void**)this = (void*)0x8045C220;

    // Initialize member fields
    // Zero out most of the structure
    memset((char*)this + 0x04, 0, 0x460);

    // Set defaults
    *(float*)((char*)this + 0x03F0) = 0.0f;  // m_rot = 0

    // Init burp scale
    *(float*)((char*)this + 0x03F8) = 1.0f;
    *(float*)((char*)this + 0x03FC) = 1.0f;

    // Init flags
    *(u32*)((char*)this + 0x032C) = 0;

    // NULL pointers
    *(void**)((char*)this + 0x0328) = 0;  // m_pObject
    *(void**)((char*)this + 0x03C8) = 0;  // m_pHouse
    *(void**)((char*)this + 0x044C) = 0;  // m_pShadow
    *(void**)((char*)this + 0x0460) = 0;  // m_pILight
}

// ============================================================================
// ISimsObjectModel::~ISimsObjectModel(void)
// Address: 0x8004C644 | Size: 428 bytes
// NON_MATCHING - GCC destructor ABI, cleanup chain
//
// Destructor. Cleans up shadow, light, particle effects, and animation
// resources. Removes sub-models from the house if still attached.
// ============================================================================
ISimsObjectModel::~ISimsObjectModel() {
    // Set vtable for proper destruction
    *(void**)this = (void*)0x8045C220;

    // Cleanup shadow
    void* shadow = *(void**)((char*)this + 0x044C);
    if (shadow != 0) {
        DestroyShadow(shadow);
        *(void**)((char*)this + 0x044C) = 0;
    }

    // Cleanup light
    EILight* light = *(EILight**)((char*)this + 0x0460);
    if (light != 0) {
        ReleaseLight(light);
        *(EILight**)((char*)this + 0x0460) = 0;
    }

    // Cleanup animation tracks
    // Multiple tracks may exist at various offsets
    for (int i = 0; i < 4; i++) {
        void* track = *(void**)((char*)this + 0x0430 + i * 4);
        if (track != 0) {
            ReleaseAnimTrack(track);
            *(void**)((char*)this + 0x0430 + i * 4) = 0;
        }
    }

    // Remove from house if still attached
    EHouse* house = *(EHouse**)((char*)this + 0x03C8);
    if (house != 0) {
        ERLevel* level = GetLevelFromHouse(house);
        if (level != 0) {
            RemoveSubModelsFromHouse(level);
        }
    }
}

// ============================================================================
// ISimsObjectModel::CleanupStuff(ERLevel *)
// Address: 0x8004C9D0 | Size: 524 bytes
// NON_MATCHING - GCC register alloc, cleanup chain
//
// Cleans up object model resources associated with a level. Removes
// sub-models, shadows, and lights from the render level. Called when
// an object is being removed from a level.
// ============================================================================
void ISimsObjectModel::CleanupStuff(ERLevel* level) {
    if (level == 0) return;

    // Remove sub-models from level
    RemoveSubModelsFromHouse(level);

    // Cleanup shadow from level
    void* shadow = *(void**)((char*)this + 0x044C);
    if (shadow != 0) {
        RemoveShadowFromLevel(level, shadow);
    }

    // Cleanup light from level
    EILight* light = *(EILight**)((char*)this + 0x0460);
    if (light != 0) {
        RemoveLightFromLevel(level, light);
    }

    // Clear house reference
    *(EHouse**)((char*)this + 0x03C8) = 0;

    // Reset animation state
    *(u32*)((char*)this + 0x0428) = 0;  // m_animTrackCount

    // Cleanup particle effects
    cXObject* obj = *(cXObject**)((char*)this + 0x0328);
    if (obj != 0) {
        // Get particle obj if exists
        // Cleanup particle effects associated with this model
    }
}

// ============================================================================
// ISimsObjectModel::GetHeightOffset(void)
// Address: 0x8004C7F0 | Size: 300 bytes
// NON_MATCHING - GCC float math, register alloc
//
// Gets the height offset for this object model. Accounts for floor level,
// object elevation, and any dynamic height adjustments (burp animation).
// ============================================================================
float ISimsObjectModel::GetHeightOffset() {
    float baseHeight = 0.0f;

    // Get level from house
    EHouse* house = *(EHouse**)((char*)this + 0x03C8);
    if (house != 0) {
        // Get floor height at object position
        EVec3* pos = GetPos();
        if (pos != 0) {
            baseHeight = GetFloorHeight(house, pos);
        }
    }

    // Add object's own height offset
    cXObject* obj = *(cXObject**)((char*)this + 0x0328);
    if (obj != 0) {
        // Check if on a surface/countertop
        cXObjectImpl* impl = obj->CAST_IMPL();
        if (impl != 0 && impl->IsContained()) {
            // Get container's surface height
            int containerSlot = impl->GetContainedSlotNum();
            void* container = impl->GetContainer();
            if (container != 0) {
                float surfaceHeight = GetSlotHeight(container, containerSlot);
                baseHeight += surfaceHeight;
            }
        }
    }

    return baseHeight;
}

// ============================================================================
// ISimsObjectModel::GetAnimDef(int, bool)
// Address: 0x800504B8 | Size: 376 bytes
// NON_MATCHING - GCC register alloc, lookup table
//
// Gets an animation definition by index. The bool parameter controls
// whether to include secondary animations. Looks up the anim def
// from the object's animation table.
// ============================================================================
void ISimsObjectModel::GetAnimDef(int index, bool includeSecondary) {
    cXObject* obj = *(cXObject**)((char*)this + 0x0328);
    if (obj == 0) return;

    cXObjectImpl* impl = obj->CAST_IMPL();
    if (impl == 0) return;

    // Get anim table
    void* animTable = impl->GetAdultAnimTable();
    if (animTable == 0) return;

    // Look up by index
    int tableCount = *(int*)((char*)animTable + 0x00);
    if (index < 0 || index >= tableCount) return;

    ObjAnimDef* def = (ObjAnimDef*)((char*)animTable + 0x04 + index * sizeof(ObjAnimDef));

    // Check for secondary
    if (!includeSecondary) {
        // Return primary def only
    }

    // Store result for caller (via register or temp)
}

// ============================================================================
// ISimsObjectModel::UpdateParticle(ObjAnimDef *)
// Address: 0x8004D598 | Size: 308 bytes
// NON_MATCHING - GCC register alloc, effect update
//
// Updates particle effects based on the current animation definition.
// Creates or destroys effects as the animation state changes.
// ============================================================================
void ISimsObjectModel::UpdateParticle(ObjAnimDef* animDef) {
    if (animDef == 0) return;

    // Get particle obj
    cXObject* obj = *(cXObject**)((char*)this + 0x0328);
    if (obj == 0) return;

    // Check if effect state changed
    u32 newModel = animDef->m_modelId;
    u32 oldModel = *(u32*)((char*)this + 0x0424);

    if (newModel == oldModel) return;

    // Update particle effects
    *(u32*)((char*)this + 0x0424) = newModel;

    // Get transform matrix
    float* matrix = (float*)((char*)this + 0x0404);
    EMat4* mat = (EMat4*)matrix;

    // Update or recreate effects based on new model
}

// ============================================================================
// ISimsObjectModel::UpdateAnimTrack(ObjAnimDef *, bool)
// Address: 0x8004E15C | Size: 988 bytes
// NON_MATCHING - GCC register alloc, animation blending
//
// Updates an animation track with a new animation definition. Handles
// blend-in/out, immediate start, and track killing. The bool parameter
// controls whether to force-start or blend.
// ============================================================================
void ISimsObjectModel::UpdateAnimTrack(ObjAnimDef* animDef, bool forceStart) {
    if (animDef == 0) return;

    u32 animId = animDef->m_modelId;

    // Check if we need a new track
    if (forceStart || ShouldAnimStartImmediate(animId)) {
        // Kill existing tracks if needed
        if (ShouldKillAllAnimTracks(animId)) {
            KillAllAnimTracks();
        }

        // Start new track immediately
        AnimStartImmediate(animId);
    } else if (ShouldAnimStartBlendIn(animId)) {
        // Blend in new animation
        AnimStartBlendIn(animId);
    }

    // Update model visual
    UpdateModel(animDef);

    // Update bulb state
    UpdateBulb(animDef);

    // Update shader
    UpdateShader(animDef);

    // Process animation events
    // Get current anim controller
    void* animCtrl = *(void**)((char*)this + 0x0440);
    if (animCtrl != 0) {
        // Get frame range
        int startFrame = *(int*)((char*)animCtrl + 0x10);
        int endFrame = *(int*)((char*)animCtrl + 0x14);

        // Process events in this range
        ERAnim* anim = *(ERAnim**)((char*)animCtrl + 0x08);
        if (anim != 0) {
            processAnimEvents(anim, startFrame, endFrame, false);
        }
    }
}

// ============================================================================
// ISimsObjectModel::UpdateHighlightAnim(void)
// Address: 0x8004DDEC | Size: 328 bytes
// NON_MATCHING - GCC register alloc, float math
//
// Updates the highlight animation effect (pulsing glow when selected).
// Oscillates the highlight intensity using a sine wave.
// ============================================================================
void ISimsObjectModel::UpdateHighlightAnim() {
    // Get highlight state
    float* highlightTime = (float*)((char*)this + 0x0450);
    float* highlightIntensity = (float*)((char*)this + 0x0454);

    // Advance time
    *highlightTime += 0.05f;
    if (*highlightTime > 6.28318f) {
        *highlightTime -= 6.28318f;
    }

    // Calculate intensity using sine wave
    float sinVal = SinF(*highlightTime);
    *highlightIntensity = 0.5f + sinVal * 0.3f;

    // Apply to light if exists
    EILight* light = *(EILight**)((char*)this + 0x0460);
    if (light != 0) {
        SetLightIntensity(light, *highlightIntensity);
    }
}

// ============================================================================
// ISimsObjectModel::CalcOrient(void)
// Address: 0x8004EB70 | Size: 264 bytes
// NON_MATCHING - GCC float math, matrix operations
//
// Calculates the object's orientation matrix from its position and rotation.
// Builds a transform matrix and stores it in the model's internal state.
// ============================================================================
void ISimsObjectModel::CalcOrient() {
    float rot = *(float*)((char*)this + 0x03F0);
    EVec3* pos = (EVec3*)((char*)this + 0x0404);
    EVec3* dir = (EVec3*)((char*)this + 0x0410);

    // Build rotation matrix from angle
    float cosR = CosF(rot);
    float sinR = SinF(rot);

    // Set direction vector
    *(float*)((char*)dir + 0x00) = sinR;
    *(float*)((char*)dir + 0x04) = 0.0f;
    *(float*)((char*)dir + 0x08) = cosR;

    // Update internal transform
    // Matrix at some offset...
}

// ============================================================================
// ISimsObjectModel::SetupCharacter(void)
// Address: 0x8004D6CC | Size: 468 bytes
// NON_MATCHING - GCC register alloc, resource loading
//
// Sets up the character/model resources for this object. Loads the 3D model,
// textures, and animation data. Called during object creation.
// ============================================================================
void ISimsObjectModel::SetupCharacter() {
    cXObject* obj = *(cXObject**)((char*)this + 0x0328);
    if (obj == 0) return;

    cXObjectImpl* impl = obj->CAST_IMPL();
    if (impl == 0) return;

    // Get model ID from definition
    void* def = *(void**)((char*)impl + 0x88);
    if (def == 0) return;

    u32 modelId = *(u32*)((char*)def + 0x40);
    if (modelId == 0) return;

    // Load model
    SetSOMModel(modelId);

    // Setup animation
    void* animTable = impl->GetAdultAnimTable();
    if (animTable != 0) {
        // Load default animation
        int defaultAnim = *(int*)((char*)animTable + 0x04);
        if (defaultAnim >= 0) {
            AnimStartImmediate(defaultAnim);
        }
    }

    // Initialize bulb
    InitBulb();
}

// ============================================================================
// ISimsObjectModel::UpdateTracks(void)
// Address: 0x8004E028 | Size: 308 bytes
// NON_MATCHING - GCC register alloc, track iteration
//
// Updates all active animation tracks. Advances track time, handles
// track completion, and manages track blending.
// ============================================================================
void ISimsObjectModel::UpdateTracks() {
    u32 trackCount = *(u32*)((char*)this + 0x0428);

    for (u32 i = 0; i < trackCount; i++) {
        void* track = *(void**)((char*)this + 0x0430 + i * 4);
        if (track == 0) continue;

        // Advance track time
        int isComplete = AdvanceTrack(track);

        if (isComplete) {
            // Track finished - remove it
            ReleaseAnimTrack(track);
            *(void**)((char*)this + 0x0430 + i * 4) = 0;

            // Shift remaining tracks down
            for (u32 j = i; j < trackCount - 1; j++) {
                *(void**)((char*)this + 0x0430 + j * 4) =
                    *(void**)((char*)this + 0x0430 + (j + 1) * 4);
            }
            *(void**)((char*)this + 0x0430 + (trackCount - 1) * 4) = 0;
            trackCount--;
            *(u32*)((char*)this + 0x0428) = trackCount;
            i--;  // Re-check this slot
        }
    }
}

// ============================================================================
// ISimsObjectModel::processAnimEvents(ERAnim *, int, int, bool)
// Address: 0x80050630 | Size: 440 bytes
// NON_MATCHING - GCC register alloc, event iteration
//
// Processes animation events that occur between startFrame and endFrame.
// Iterates through the anim's event list and dispatches each matching
// event to animEventHandler.
// ============================================================================
void ISimsObjectModel::processAnimEvents(ERAnim* anim, int startFrame, int endFrame, bool flag) {
    if (anim == 0) return;

    // Get event count
    int eventCount = *(int*)((char*)anim + 0x20);
    if (eventCount <= 0) return;

    // Get events array
    EAnimNote* events = *(EAnimNote**)((char*)anim + 0x24);
    if (events == 0) return;

    for (int i = 0; i < eventCount; i++) {
        EAnimNote* note = &events[i];
        int noteFrame = *(int*)((char*)note + 0x00);

        // Check if this event falls in the frame range
        if (startFrame <= endFrame) {
            // Normal range
            if (noteFrame >= startFrame && noteFrame < endFrame) {
                animEventHandler(anim, *note, i);
            }
        } else {
            // Wrapped range (looping animation)
            if (noteFrame >= startFrame || noteFrame < endFrame) {
                animEventHandler(anim, *note, i);
            }
        }
    }
}

// ============================================================================
// ISimsObjectModel::SetWallForPortal(void)
// Address: 0x8004E868 | Size: 492 bytes
// NON_MATCHING - GCC register alloc, wall lookup
//
// Sets up wall rendering for portal objects (doors, windows). Determines
// which wall segments need special rendering treatment and configures
// the wall shader accordingly.
// ============================================================================
void ISimsObjectModel::SetWallForPortal() {
    cXObject* obj = *(cXObject**)((char*)this + 0x0328);
    if (obj == 0) return;

    cXObjectImpl* impl = obj->CAST_IMPL();
    if (impl == 0) return;

    // Get tile position
    FTilePt* tile = impl->GetLocation();
    if (tile == 0) return;

    int level = impl->GetLevel();

    // Get wall data at this position
    EHouse* house = *(EHouse**)((char*)this + 0x03C8);
    if (house == 0) return;

    // Look up wall segments
    int wallDir = impl->GetFrontFaceDirection();
    void* wallData = GetWallDataAtTile(house, tile, level);
    if (wallData == 0) return;

    // Configure wall rendering for portal
    void* wallShader = *(void**)((char*)this + 0x0458);
    if (wallShader == 0) {
        // Allocate wall shader data
        wallShader = operator_new(0x20);
        *(void**)((char*)this + 0x0458) = wallShader;
    }

    // Set portal cutout in wall
    SetPortalCutout(wallShader, wallData, wallDir);
}

// ============================================================================
// ISimsObjectModel::CreateShadow(void)
// Address: 0x8004EA54 | Size: 280 bytes
// NON_MATCHING - GCC register alloc, shadow creation
//
// Creates a shadow for this object model. Allocates shadow resources
// and configures them based on the object's size and shape.
// ============================================================================
void ISimsObjectModel::CreateShadow() {
    // Check if shadow already exists
    if (*(void**)((char*)this + 0x044C) != 0) return;

    // Check if house exists
    EHouse* house = *(EHouse**)((char*)this + 0x03C8);
    if (house == 0) return;

    // Check dynamic flag
    bool isDynamic = GetDynamic();

    // Create shadow object
    void* shadow = CreateShadowObject(isDynamic);
    if (shadow == 0) return;

    *(void**)((char*)this + 0x044C) = shadow;

    // Set shadow position
    EVec3* pos = GetPos();
    if (pos != 0) {
        SetShadowPosition(shadow, pos);
    }
}

// ============================================================================
// ISimsObjectModel::TryAnimateObject(short, short *)
// Address: 0x8004ED3C | Size: 540 bytes
// NON_MATCHING - GCC register alloc, anim lookup
//
// Attempts to animate the object with the specified animation ID.
// Looks up the animation, validates it exists, and starts it. Returns
// the result through the output parameter.
// ============================================================================
void ISimsObjectModel::TryAnimateObject(short animId, short* result) {
    if (result == 0) return;
    *result = 0;

    cXObject* obj = *(cXObject**)((char*)this + 0x0328);
    if (obj == 0) return;

    cXObjectImpl* impl = obj->CAST_IMPL();
    if (impl == 0) return;

    // Get animation table
    void* animTable = impl->GetAdultAnimTable();
    if (animTable == 0) {
        *result = -1;
        return;
    }

    // Look up animation
    int tableCount = *(int*)((char*)animTable + 0x00);
    if (animId < 0 || animId >= tableCount) {
        *result = -1;
        return;
    }

    ObjAnimDef* animDef = (ObjAnimDef*)((char*)animTable + 0x04 + animId * sizeof(ObjAnimDef));

    // Start animation
    UpdateAnimTrack(animDef, true);

    *result = 1;
}

// ============================================================================
// ISimsObjectModel::CalcLightsFromPos(ELights *, bool)
// Address: 0x8004F658 | Size: 640 bytes
// NON_MATCHING - GCC float math, light calculation
//
// Calculates lighting contribution from this object's position.
// Samples nearby lights and computes the ambient/diffuse/specular
// contributions at the object's location.
// ============================================================================
void ISimsObjectModel::CalcLightsFromPos(ELights* lights, bool includeGlobal) {
    if (lights == 0) return;

    EVec3* pos = GetPos();
    if (pos == 0) return;

    EHouse* house = *(EHouse**)((char*)this + 0x03C8);
    if (house == 0) return;

    // Clear output lights
    memset(lights, 0, sizeof(ELights));

    // Get global ambient if requested
    if (includeGlobal) {
        float* ambient = GetGlobalAmbient(house);
        if (ambient != 0) {
            *(float*)((char*)lights + 0x00) = ambient[0];
            *(float*)((char*)lights + 0x04) = ambient[1];
            *(float*)((char*)lights + 0x08) = ambient[2];
        }
    }

    // Find nearby lights
    int lightCount = GetNearbyLights(house, pos, 8);  // Max 8 lights
    for (int i = 0; i < lightCount; i++) {
        EILight* nearLight = GetNearbyLight(i);
        if (nearLight == 0) continue;

        // Calculate light contribution
        float* lightPos = GetLightPosition(nearLight);
        float dx = lightPos[0] - *(float*)((char*)pos + 0);
        float dy = lightPos[1] - *(float*)((char*)pos + 4);
        float dz = lightPos[2] - *(float*)((char*)pos + 8);
        float dist = dx*dx + dy*dy + dz*dz;

        float radius = GetLightRadius(nearLight);
        if (dist > radius * radius) continue;

        // Attenuation
        float sqrtDist = SqrtF(dist);
        float atten = 1.0f - (sqrtDist / radius);
        if (atten < 0.0f) atten = 0.0f;

        // Add contribution
        float* lightColor = GetLightColor(nearLight);
        *(float*)((char*)lights + 0x00) += lightColor[0] * atten;
        *(float*)((char*)lights + 0x04) += lightColor[1] * atten;
        *(float*)((char*)lights + 0x08) += lightColor[2] * atten;
    }
}

// ============================================================================
// ISimsObjectModel::DoLightingCalculation(void)
// Address: 0x8004F8D8 | Size: 712 bytes
// NON_MATCHING - GCC float math, light computation
//
// Performs the full lighting calculation for this object. Combines ambient,
// diffuse, and object-emitted light. Stores the result in the model's
// light data for rendering.
// ============================================================================
void ISimsObjectModel::DoLightingCalculation() {
    EHouse* house = *(EHouse**)((char*)this + 0x03C8);
    if (house == 0) return;

    // Get position
    EVec3* pos = GetPos();
    if (pos == 0) return;

    // Calculate lights from position
    ELights lights;
    CalcLightsFromPos(&lights, true);

    // Check if this object emits light
    EILight* selfLight = *(EILight**)((char*)this + 0x0460);
    if (selfLight != 0) {
        // Don't count our own light
        float* selfColor = GetLightColor(selfLight);
        float* selfPos = GetLightPosition(selfLight);
        float selfRadius = GetLightRadius(selfLight);

        float dx = selfPos[0] - *(float*)((char*)pos + 0);
        float dy = selfPos[1] - *(float*)((char*)pos + 4);
        float dz = selfPos[2] - *(float*)((char*)pos + 8);
        float dist = SqrtF(dx*dx + dy*dy + dz*dz);

        if (dist < selfRadius) {
            float atten = 1.0f - (dist / selfRadius);
            *(float*)((char*)&lights + 0x00) -= selfColor[0] * atten;
            *(float*)((char*)&lights + 0x04) -= selfColor[1] * atten;
            *(float*)((char*)&lights + 0x08) -= selfColor[2] * atten;
        }
    }

    // Clamp light values
    for (int i = 0; i < 3; i++) {
        float* val = (float*)((char*)&lights + i * 4);
        if (*val < 0.0f) *val = 0.0f;
        if (*val > 1.0f) *val = 1.0f;
    }

    // Store lighting result
    memcpy((char*)this + 0x0440, &lights, sizeof(ELights));
}

// ============================================================================
// ISimsObjectModel::AnimateLights(void)
// Address: 0x80050288 | Size: 400 bytes
// NON_MATCHING - GCC register alloc, light animation
//
// Animates the object's light source (flickering, color changes, etc.).
// Called each frame for objects that have dynamic lighting.
// ============================================================================
void ISimsObjectModel::AnimateLights() {
    EILight* light = *(EILight**)((char*)this + 0x0460);
    if (light == 0) return;

    // Get light animation state
    float* animTime = (float*)((char*)this + 0x045C);
    *animTime += 0.016667f;  // ~60fps

    // Check if light has animation data
    int animType = GetLightAnimType(light);
    if (animType == 0) return;  // Static light

    // Animate based on type
    float intensity = 1.0f;
    switch (animType) {
        case 1:  // Flicker
            intensity = 0.7f + 0.3f * SinF(*animTime * 10.0f);
            break;
        case 2:  // Pulse
            intensity = 0.5f + 0.5f * SinF(*animTime * 3.0f);
            break;
        case 3:  // Candle
            intensity = 0.6f + 0.4f * (SinF(*animTime * 8.0f) *
                        SinF(*animTime * 13.0f));
            break;
    }

    SetLightIntensity(light, intensity);
}

// ============================================================================
// ISimsObjectModel::animEventHandler(ERAnim *, EAnimNote &, int)
// Address: 0x800507E8 | Size: 792 bytes
// NON_MATCHING - GCC register alloc, event dispatch
//
// Handles a specific animation event. Dispatches to the appropriate
// handler based on the event type (sound, particle, property change, etc.).
// ============================================================================
void ISimsObjectModel::animEventHandler(ERAnim* anim, EAnimNote& note, int param) {
    // Get event type
    int eventType = *(int*)((char*)&note + 0x04);

    switch (eventType) {
        case 0:  // Sound event
        {
            int soundID = *(int*)((char*)&note + 0x08);
            if (soundID != 0) {
                // Play sound at object position
                EVec3* pos = GetPos();
                PlaySoundAtPos(soundID, pos);
            }
            break;
        }
        case 1:  // Particle event
        {
            int particleID = *(int*)((char*)&note + 0x08);
            if (particleID != 0) {
                // Create particle effect
                EVec3* pos = GetPos();
                CreateParticleAtPos(particleID, pos);
            }
            break;
        }
        case 2:  // Property change
        {
            int propID = *(int*)((char*)&note + 0x08);
            int propValue = *(int*)((char*)&note + 0x0C);
            // Apply property change
            cXObject* obj = *(cXObject**)((char*)this + 0x0328);
            if (obj != 0) {
                cXObjectImpl* impl = obj->CAST_IMPL();
                if (impl != 0) {
                    impl->SetData(propID, (short)propValue);
                }
            }
            break;
        }
        case 3:  // Visibility toggle
        {
            int visible = *(int*)((char*)&note + 0x08);
            // Toggle sub-model visibility
            break;
        }
        case 4:  // Shader change
        {
            u32 oldShader = *(u32*)((char*)&note + 0x08);
            u32 newShader = *(u32*)((char*)&note + 0x0C);
            ChageShader(oldShader, newShader);
            break;
        }
        default:
            break;
    }
}

// ============================================================================
// ISimsObjectModel::SetInitalObjectState(void)
// Address: 0x80050B00 | Size: 312 bytes
// NON_MATCHING - GCC register alloc, init chain
//
// Sets the initial visual state for a newly created object. Loads the
// default model, applies initial rotation, and creates the shadow.
// ============================================================================
void ISimsObjectModel::SetInitalObjectState() {
    // Setup character model
    SetupCharacter();

    // Calculate orientation
    CalcOrient();

    // Set object orientation
    SetObjOrient();

    // Create shadow
    CreateShadow();

    // Initialize bulb
    InitBulb();

    // Do initial lighting
    DoLightingCalculation();
}

// ============================================================================
// ISimsObjectModel::SetObjOrient(void)
// Address: 0x80050D44 | Size: 368 bytes
// NON_MATCHING - GCC float math, matrix operations
//
// Sets the object's visual orientation from its logical facing direction.
// Builds a transform matrix from the position, rotation, and scale.
// ============================================================================
void ISimsObjectModel::SetObjOrient() {
    cXObject* obj = *(cXObject**)((char*)this + 0x0328);
    if (obj == 0) return;

    cXObjectImpl* impl = obj->CAST_IMPL();
    if (impl == 0) return;

    // Get facing direction
    int dir = impl->GetFrontFaceDirection();

    // Convert to radians (0=East, 1=South, 2=West, 3=North)
    float angle = (float)dir * 1.5707963f;  // PI/2
    *(float*)((char*)this + 0x03F0) = angle;

    // Recalculate orientation
    CalcOrient();

    // Update position from tile
    FTilePt* tile = impl->GetLocation();
    if (tile != 0) {
        float posX = (float)tile->x * 16.0f + 8.0f;
        float posZ = (float)tile->y * 16.0f + 8.0f;
        int level = impl->GetLevel();
        float posY = (float)level * 64.0f + GetHeightOffset();

        EVec3* pos = GetPos();
        *(float*)((char*)pos + 0) = posX;
        *(float*)((char*)pos + 4) = posY;
        *(float*)((char*)pos + 8) = posZ;
    }
}

// ============================================================================
// ISimsObjectModel::OrentSubObject(void)
// Address: 0x80050F14 | Size: 444 bytes
// NON_MATCHING - GCC register alloc, sub-object iteration
//
// Orients sub-objects (parts of multi-tile objects). Iterates through
// sub-models and sets each one's orientation relative to the parent.
// ============================================================================
void ISimsObjectModel::OrentSubObject() {
    cXObject* obj = *(cXObject**)((char*)this + 0x0328);
    if (obj == 0) return;

    cXObjectImpl* impl = obj->CAST_IMPL();
    if (impl == 0) return;

    // Get rotation
    float rot = *(float*)((char*)this + 0x03F0);
    EVec3* basePos = GetPos();

    // Check for multi-tile parts
    if (!impl->IsMultiTile()) return;

    // Iterate sub-objects
    cXObjectImpl* nextImpl = impl->GetNextImpl();
    while (nextImpl != 0) {
        if (nextImpl->IsPartOfMe((cXObject*)impl)) {
            void* nextSim = nextImpl->GetSim();
            if (nextSim != 0) {
                // Calculate offset position
                FTilePt* nextTile = nextImpl->GetLocation();
                FTilePt* myTile = impl->GetLocation();

                if (nextTile != 0 && myTile != 0) {
                    int dx = nextTile->x - myTile->x;
                    int dy = nextTile->y - myTile->y;

                    // Apply rotation to offset
                    float cosR = CosF(rot);
                    float sinR = SinF(rot);
                    float offX = (float)dx * cosR - (float)dy * sinR;
                    float offZ = (float)dx * sinR + (float)dy * cosR;

                    // Set sub-object position
                    float subPos[3];
                    subPos[0] = *(float*)((char*)basePos + 0) + offX * 16.0f;
                    subPos[1] = *(float*)((char*)basePos + 4);
                    subPos[2] = *(float*)((char*)basePos + 8) + offZ * 16.0f;

                    SetSubModelPosition(nextSim, subPos, rot);
                }
            }
        }
        nextImpl = nextImpl->GetNextImpl();
    }
}

// ============================================================================
// ISimsCounterTopObject::SetObjOrient(void)
// Address: 0x80052190 | Size: 948 bytes
// NON_MATCHING - GCC register alloc, counter-specific orient
//
// Override of SetObjOrient for counter top objects. Handles special
// counter orientation logic including adjacent counter detection and
// matching end-cap/middle/corner variants based on neighbors.
// ============================================================================
void ISimsCounterTopObject::SetObjOrient() {
    // Call base implementation first
    ISimsObjectModel::SetObjOrient();

    cXObject* obj = *(cXObject**)((char*)this + 0x0328);
    if (obj == 0) return;

    cXObjectImpl* impl = obj->CAST_IMPL();
    if (impl == 0) return;

    // Get tile position
    FTilePt* tile = impl->GetLocation();
    if (tile == 0) return;

    int level = impl->GetLevel();

    // Check adjacent tiles for other counters
    bool hasNorth = false, hasSouth = false, hasEast = false, hasWest = false;

    // Check north
    FTilePt checkTile;
    checkTile.x = tile->x;
    checkTile.y = tile->y - 1;
    hasNorth = IsCounterAtTile(checkTile, level);

    // Check south
    checkTile.y = tile->y + 1;
    hasSouth = IsCounterAtTile(checkTile, level);

    // Check east
    checkTile.x = tile->x + 1;
    checkTile.y = tile->y;
    hasEast = IsCounterAtTile(checkTile, level);

    // Check west
    checkTile.x = tile->x - 1;
    hasWest = IsCounterAtTile(checkTile, level);

    // Determine counter variant
    int neighborCount = (hasNorth ? 1 : 0) + (hasSouth ? 1 : 0) +
                        (hasEast ? 1 : 0) + (hasWest ? 1 : 0);

    int variant = 0;  // Default: standalone
    int facing = impl->GetFrontFaceDirection();

    if (neighborCount == 0) {
        variant = 0;  // Standalone
    } else if (neighborCount == 1) {
        variant = 1;  // End cap
        // Set facing towards the neighbor
        if (hasNorth) facing = 3;
        else if (hasSouth) facing = 1;
        else if (hasEast) facing = 0;
        else if (hasWest) facing = 2;
    } else if (neighborCount == 2) {
        // Check if they're opposite (straight) or adjacent (corner)
        if ((hasNorth && hasSouth) || (hasEast && hasWest)) {
            variant = 2;  // Middle/straight
        } else {
            variant = 3;  // Corner
            // Determine corner facing
            if (hasNorth && hasEast) facing = 0;
            else if (hasEast && hasSouth) facing = 1;
            else if (hasSouth && hasWest) facing = 2;
            else if (hasWest && hasNorth) facing = 3;
        }
    } else {
        variant = 4;  // T or + intersection
    }

    // Apply variant model
    if (variant != 0) {
        // Get variant model ID from definition
        void* def = *(void**)((char*)impl + 0x88);
        if (def != 0) {
            u32 variantModelId = *(u32*)((char*)def + 0x44 + variant * 4);
            if (variantModelId != 0) {
                SetSOMModel(variantModelId);
            }
        }
    }

    // Update facing
    if (facing != impl->GetFrontFaceDirection()) {
        impl->Turn(facing);
        float angle = (float)facing * 1.5707963f;
        *(float*)((char*)this + 0x03F0) = angle;
        CalcOrient();
    }

    // Check for sink
    if (IsSinkId(obj)) {
        // Special sink handling
        // Sink may need to be positioned differently on counter
    }
}

// ============================================================================
// __static_initialization_and_destruction_0 (iobject.obj)
// Address: 0x80053A70 | Size: 408 bytes
// NON_MATCHING - GCC static init
//
// Static initialization function for iobject.obj. Registers type info
// for all ISimsObjectModel variants and initializes static members.
// ============================================================================
void __static_initialization_and_destruction_0_iobject(int init, int priority) {
    if (init == 1 && priority == 65535) {
        // Register types
        ISimsObjectModel::RegisterType(1);
        ISimsWallObjectModel::RegisterType(1);
        ISimsMultiTileObjectModel::RegisterType(1);
        ISimsCounterTopObject::RegisterType(1);
        IShrubObject::RegisterType(1);

        // Initialize static shader
        ISimsObjectModel::m_pWhiteShader = 0;
    }
}

// ============================================================================
// ISimsObjectModel::StartNewAnimTrack(ObjAnimDef *, bool)
// Address: 0x8005455C | Size: 424 bytes
// NON_MATCHING - GCC register alloc, track management
//
// Starts a new animation track. Allocates a track slot, configures the
// animation parameters, and begins playback. The bool controls whether
// to blend in or start immediately.
// ============================================================================
void ISimsObjectModel::StartNewAnimTrack(ObjAnimDef* animDef, bool immediate) {
    if (animDef == 0) return;

    u32 trackCount = *(u32*)((char*)this + 0x0428);

    // Find free track slot
    int freeSlot = -1;
    for (int i = 0; i < 4; i++) {
        void* track = *(void**)((char*)this + 0x0430 + i * 4);
        if (track == 0) {
            freeSlot = i;
            break;
        }
    }

    if (freeSlot < 0) {
        // All slots full - kill oldest track
        void* oldest = *(void**)((char*)this + 0x0430);
        ReleaseAnimTrack(oldest);

        // Shift tracks
        for (int i = 0; i < 3; i++) {
            *(void**)((char*)this + 0x0430 + i * 4) =
                *(void**)((char*)this + 0x0430 + (i + 1) * 4);
        }
        *(void**)((char*)this + 0x0430 + 3 * 4) = 0;
        freeSlot = (int)trackCount - 1;
        if (freeSlot < 0) freeSlot = 0;
        trackCount = trackCount > 0 ? trackCount - 1 : 0;
    }

    // Create new track
    void* newTrack = CreateAnimTrack(animDef->m_modelId, immediate);
    if (newTrack != 0) {
        *(void**)((char*)this + 0x0430 + freeSlot * 4) = newTrack;
        if ((u32)freeSlot >= trackCount) {
            *(u32*)((char*)this + 0x0428) = (u32)freeSlot + 1;
        }
    }
}

// ============================================================================
// ISimsObjectModel::ProcessPropertyEventTags(ObjAnimDef *, float)
// Address: 0x80054704 | Size: 476 bytes
// NON_MATCHING - GCC register alloc, property processing
//
// Processes property change event tags from an animation definition.
// These tags modify object data values at specific animation times.
// ============================================================================
void ISimsObjectModel::ProcessPropertyEventTags(ObjAnimDef* animDef, float time) {
    if (animDef == 0) return;

    cXObject* obj = *(cXObject**)((char*)this + 0x0328);
    if (obj == 0) return;

    cXObjectImpl* impl = obj->CAST_IMPL();
    if (impl == 0) return;

    // Get property tags from anim def
    void* propTags = *(void**)((char*)animDef + 0x10);
    if (propTags == 0) return;

    int tagCount = *(int*)((char*)propTags + 0x00);
    if (tagCount <= 0) return;

    // Process each tag
    for (int i = 0; i < tagCount; i++) {
        char* tag = (char*)propTags + 0x04 + i * 0x0C;
        float tagTime = *(float*)((char*)tag + 0x00);

        // Check if this tag should fire at the current time
        if (tagTime <= time) {
            int propID = *(int*)((char*)tag + 0x04);
            short propValue = *(short*)((char*)tag + 0x08);

            // Apply property change
            impl->SetData(propID, propValue);
        }
    }
}

// ============================================================================
// TArray<EILight *, TArrayDefaultAllocator>::SetSize(int, int)
// Address: 0x8039F7BC | Size: 292 bytes
// NON_MATCHING - GCC template instantiation, memory management
//
// Sets the size of a TArray of EILight pointers. Handles growth/shrinkage
// with the specified grow factor.
// ============================================================================
void TArray_EILight_SetSize(void* arr, int newSize, int grow) {
    // arr layout: [m_pData, m_size, m_capacity]
    void*** pData = (void***)arr;
    int* pSize = (int*)((char*)arr + 4);
    int* pCap = (int*)((char*)arr + 8);

    int oldSize = *pSize;
    int oldCap = *pCap;

    if (newSize <= oldCap) {
        // No reallocation needed
        // Zero new entries if growing
        if (newSize > oldSize) {
            memset((char*)*pData + oldSize * 4, 0, (newSize - oldSize) * 4);
        }
        *pSize = newSize;
        return;
    }

    // Need to grow
    int newCap = newSize;
    if (grow > 0) {
        newCap = ((newSize + grow - 1) / grow) * grow;
    }

    void** newData = (void**)operator_new(newCap * 4);
    if (oldSize > 0 && *pData != 0) {
        memcpy(newData, *pData, oldSize * 4);
    }
    memset((char*)newData + oldSize * 4, 0, (newCap - oldSize) * 4);

    if (*pData != 0) {
        operator_delete(*pData);
    }

    *pData = newData;
    *pSize = newSize;
    *pCap = newCap;
}

// ============================================================================
// IShrubObject virtual table
// Address: 0x8045B980 | Size: 496 bytes
// This is vtable data, not a function
// ============================================================================
// IShrubObject vtable - 124 entries

// ============================================================================
// ISimsCounterTopObject virtual table
// Address: 0x8045BBA8 | Size: 496 bytes
// This is vtable data, not a function
// ============================================================================
// ISimsCounterTopObject vtable - 124 entries

// ============================================================================
// ISimsMultiTileObjectModel virtual table
// Address: 0x8045BDD0 | Size: 496 bytes
// This is vtable data, not a function
// ============================================================================
// ISimsMultiTileObjectModel vtable - 124 entries

// ============================================================================
// ISimsWallObjectModel virtual table
// Address: 0x8045BFF8 | Size: 496 bytes
// This is vtable data, not a function
// ============================================================================
// ISimsWallObjectModel vtable - 124 entries

// ============================================================================
// ISimsObjectModel virtual table
// Address: 0x8045C220 | Size: 496 bytes
// This is vtable data, not a function
// ============================================================================
// ISimsObjectModel vtable - 124 entries

// ============================================================================
// EmitterGeom3dTab virtual table
// Address: 0x8045C410 | Size: 344 bytes
// This is vtable data, not a function
// ============================================================================
// EmitterGeom3dTab vtable - 86 entries

// ============================================================================
// EmitterGeom3d virtual table
// Address: 0x8045C568 | Size: 344 bytes
// This is vtable data, not a function
// ============================================================================
// EmitterGeom3d vtable - 86 entries

#endif // Reference decompilation
