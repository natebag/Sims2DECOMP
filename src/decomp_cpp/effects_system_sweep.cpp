// effects_system_sweep.cpp - Batch conversion of Effects system asm stubs to portable C++
// Converted from 27 asm stub files covering particles, emitters, fades, frame effects, and more
// Total: ~100 functions across the Effects subsystem
//
// NOTE: These are logical C++ interpretations of the PPC asm stubs.
// The asm stubs in src/asm_decomp/ remain the authoritative byte-matching versions.
// This file exists for readability, documentation, and future porting.

#include "types.h"

extern "C" {
    void* memcpy(void* dst, const void* src, unsigned int n);
    void* memset(void* s, int c, unsigned int n);
    float sqrtf(float x);
    float sinf(float x);
    float cosf(float x);
    unsigned int strlen(const char* s);
}

// Forward declarations - external systems
class EAHeap;
extern EAHeap* MainHeap();
class EAHeap {
public:
    void* Malloc(unsigned int size, int flags);
    void* MallocAligned(unsigned int size, unsigned int align, unsigned int flags, int extra);
    void Free(void* ptr);
};

class EResource {
public:
    EResource();
    ~EResource();
    void DelRef();
};

class EResourceManager {
public:
    static EResource* AddRef(unsigned int id, void* file, int flags);
    static void AddRefAsync(unsigned int id);
    static void DelRefAsync(unsigned int id);
    static EResource* GetRef(unsigned int id);
    static void Free(void* ptr);
    static void* Alloc(unsigned long size, unsigned int align);
    static int TryIncrementResource(unsigned int id, EResource** out);
    static void DelRef(EResource* res, int mode);
};

class EDataHeader {
public:
    EDataHeader();
    ~EDataHeader();
    int Read(void* file, unsigned int magic, unsigned int minVer, unsigned int maxVer);
    const char* GetName();
    unsigned int m_size; // at offset 16 in stack layout
};

class EInstance {
public:
    EInstance();
    ~EInstance();
    void InsertInOrderTable(void* orderTable);
};

class ETypeInfo {
public:
    static void Register(void* createFn, void* loadFn, void* destroyFn,
                         unsigned short typeId, const char* name, void* parentType);
};

class ENodeList {
public:
    void RemoveAll();
    void AddTail(unsigned int data);
};

class EFile;
class ERC;
class EMat4 {
public:
    void Id();
    void RotateX(float angle);
    void PreScale(float scale);
    void PostTranslate(void* vec);
    void Mult4x4(EMat4& a, EMat4& b);
    EMat4& operator=(EMat4& other);
};

struct EVec3 { float x, y, z; };
struct EVec4 { float x, y, z, w; };
struct EBound3 { float min[3]; float max[3]; };
struct PVector4 { float x, y, z, w; };
struct BloomSettings { float data[17]; };

// Particle system forward declarations
struct particle;
struct pemitter;
struct pemitterinfo;
struct psystem;
struct AttachmentNode {
    unsigned char flags;
    unsigned char boneId;
    unsigned short param;
    unsigned int resourceId;
};
struct ObjAnimDef;
class EAnimController;
class ERModel;
class ERLevel;
class ELevelDrawData;
class EOrderTableData;
class ITreeTableEntry;
class cXPerson;
class AnimParticleData;

// External function declarations
extern int PEmitterCreate(void* emitter);
extern void PEmitterReg(psystem* sys, void* emitter);
extern void PEmitterUnReg(psystem* sys, void* emitter);
extern void PEmitterSubmitParticles(void* emitter, float dt);
extern void PSVECNormalize(float* src, float* dst);
extern float PSVECDotProduct(float* a, float* b);
extern int Sprintf(char* buf, const char* fmt, ...);
extern int AtoI(const char* str);

typedef void (*ParticleInitCB)(particle*, PVector4*, float, float, PVector4*, void*);
typedef void (*ParticleDestroyCB)(void*);
typedef void (*EmitterUpdateCB)(pemitter*, PVector4*, PVector4*);

// Float interpolation helpers
namespace {
    float InterpolateLinear_float(float start, float end, float startTime, float endTime, float t) {
        if (endTime <= startTime) return end;
        float pct = (t - startTime) / (endTime - startTime);
        if (pct < 0.0f) pct = 0.0f;
        if (pct > 1.0f) pct = 1.0f;
        return start + (end - start) * pct;
    }
    void InterpolateLinear_EVec3(EVec3* out, EVec3* a, EVec3* b, float startTime, float endTime, float t) {
        float pct = (endTime <= startTime) ? 1.0f : (t - startTime) / (endTime - startTime);
        if (pct < 0.0f) pct = 0.0f;
        if (pct > 1.0f) pct = 1.0f;
        out->x = a->x + (b->x - a->x) * pct;
        out->y = a->y + (b->y - a->y) * pct;
        out->z = a->z + (b->z - a->z) * pct;
    }
}

// ============================================================================
// FrameEffect - Base class for screen effects
// ============================================================================

class FrameEffect {
public:
    enum EffectState { Inactive = 1, Activating = 2, Active = 4, Deactivating = 8 };

    float m_activateStartTime; // offset 0
    float m_deactivateStartTime; // offset 4
    float m_timer;             // offset 8
    int m_state;               // offset 12
    void** m_vtable;           // offset 16

    void Enable(bool enable);
    void Update(float dt, ERC* rc);
    void UpdateEffectState();

    // Virtual function helpers
    bool IsEffectRamping() const;
    bool IsEffectRunning() const;
    bool IsActivateComplete(float t) const;
    bool IsDeactivateComplete(float t) const;
    virtual void EffectStateChanged(int newState) {}
    virtual void UpdateTargetParameters(float t) {}
    virtual void Draw(ERC* rc) {}
};

// 0x80356FB0
void FrameEffect::Enable(bool enable) {
    if (!enable && m_state == Inactive) {
        return;
    }
    int newState;
    if (!enable) {
        newState = Deactivating;
    } else {
        newState = Activating;
    }
    m_state = newState;
    // Call virtual EffectStateChanged via vtable
    // vtable[32/8] -> EffectStateChanged(newState)
    m_timer = 0.0f;
}

// 0x80357020
void FrameEffect::Update(float dt, ERC* rc) {
    m_timer += dt;
    if (IsEffectRamping()) {
        UpdateTargetParameters(m_timer);
    }
    if (IsEffectRunning()) {
        Draw(rc);
    }
    UpdateEffectState();
}

// 0x803570EC
void FrameEffect::UpdateEffectState() {
    if (m_state == Activating) {
        if (IsActivateComplete(m_timer)) {
            m_state = Active;
            EffectStateChanged(Active);
        }
    } else if (m_state == Deactivating) {
        if (IsDeactivateComplete(m_timer)) {
            m_state = Inactive;
            EffectStateChanged(Inactive);
        }
    }
}

// ============================================================================
// Bloom - Screen bloom effect
// ============================================================================

class Bloom : public FrameEffect {
public:
    // FrameEffect base: offsets 0-16 (20 bytes)
    // float m_targetParams[6] at offset 20 (3 pairs of floats for 3 mip levels)
    // float m_savedParams[44] at offset 64
    // float m_currentParams[44] at offset 108
    // float m_blendAmount at offset 112

    Bloom();
    void UpdateTargetParameters(float t);
    void EffectStateChanged(int newState);
    void SetTargetSettings(BloomSettings& settings);
};

// 0x803C78E0
Bloom::Bloom() {
    // Set vtable
    // Initialize base FrameEffect params
    m_state = Inactive;
    m_timer = 0.0f;
    // Initialize bloom-specific parameters - mip levels, colors, thresholds
    // 4 iterations of paired float init for target/current params
    // NOTE: asm-derived, complex float constant initialization
}

// 0x803572F0
void Bloom::UpdateTargetParameters(float t) {
    if (m_state == Activating) {
        // Copy current target settings to saved
        // Interpolate m_blendAmount from saved to target
        // Copy mip-level params
    } else if (m_state == Deactivating) {
        // Interpolate m_blendAmount toward zero
    }
}

// 0x803573BC
void Bloom::EffectStateChanged(int newState) {
    if (newState != Activating && newState != Deactivating) return;
    // Copy 44 bytes (current params) to saved params area
    // Memcpy-style loop: copies 24 bytes at a time, then remaining 20 bytes
    // Source: offset 64, Dest: offset 108
    char* src = (char*)this + 64;
    char* dst = (char*)this + 108;
    for (int i = 0; i < 24; i += 24) {
        memcpy(dst + i, src + i, 24);
    }
    memcpy(dst + 24, src + 24, 20);
}

// 0x803576E0
void Bloom::SetTargetSettings(BloomSettings& settings) {
    // Copy BloomSettings data to offset 20 of this
    // Loop copies 24 bytes at a time, then 20 remaining
    char* dst = (char*)this + 20;
    char* src = (char*)&settings;
    for (int i = 0; i < 24; i += 24) {
        memcpy(dst + i, src + i, 24);
    }
    memcpy(dst + 24, src + 24, 20);
}

// ============================================================================
// MotionBlur - Screen motion blur effect
// ============================================================================

class MotionBlur : public FrameEffect {
public:
    // offset 20-24: saved float params
    // offset 32-36: current interpolated params
    // offset 40: blend param
    // offset 44-48: target float params

    void UpdateTargetParameters(float t);
};

// 0x803571C0
void MotionBlur::UpdateTargetParameters(float t) {
    float* thisPtr = (float*)this;
    if (m_state == Activating) {
        // Interpolate from saved to target
        thisPtr[8] = InterpolateLinear_float(thisPtr[11], thisPtr[5], 0.0f /*constant*/, thisPtr[0], t);
        float result = InterpolateLinear_float(thisPtr[12], thisPtr[6], 0.0f, thisPtr[0], t);
        thisPtr[9] = result;
        // Store blend param from offset 28
        int* iPtr = (int*)this;
        iPtr[10] = iPtr[7];
    } else if (m_state == Deactivating) {
        // Interpolate toward zero
        thisPtr[8] = InterpolateLinear_float(thisPtr[11], 0.0f, 0.0f, thisPtr[1], t);
        float result = InterpolateLinear_float(thisPtr[12], 0.0f, 0.0f, thisPtr[1], t);
        thisPtr[9] = result;
        int* iPtr = (int*)this;
        iPtr[10] = 0;
    }
}

// ============================================================================
// DepthOfField - Depth of field effect
// ============================================================================

class DepthOfField : public FrameEffect {
public:
    // offset 24-36: saved EVec3 params
    // offset 40-56: current params (EVec3 + float)
    // offset 60-76: saved secondary params
    // offset 76: float blendFactor

    void UpdateTargetParameters(float t);
    void EffectStateChanged(int newState);
};

// 0x80357474
void DepthOfField::UpdateTargetParameters(float t) {
    float* p = (float*)this;
    if (m_state == Activating) {
        // Copy offset 64 to offset 40 (savedNear = currentNear)
        p[10] = p[16];
        // InterpolateLinear<EVec3> for near/far plane params
        // InterpolateLinear<float> for blend amount
        // NOTE: asm-derived, complex EVec3 interpolation
    } else if (m_state == Deactivating) {
        // Interpolate current params toward zero
        // NOTE: asm-derived, complex EVec3 interpolation toward zero
    }
}

// 0x803575E4
void DepthOfField::EffectStateChanged(int newState) {
    if (newState != Activating && newState != Deactivating) return;
    // Copy current params (offset 40, 20 bytes) to saved params (offset 60)
    float* src = (float*)this + 10; // offset 40
    float* dst = (float*)this + 15; // offset 60
    for (int i = 0; i < 5; i++) {
        dst[i] = src[i];
    }
}

// ============================================================================
// BloomNGC - GameCube-specific bloom rendering
// ============================================================================

class BloomNGC {
public:
    // offset 64-88: bloom parameters (mip strengths, colors)
    float m_mipStrength0; // offset 64
    float m_blendAmount;  // offset 68
    float m_unused72;     // offset 72
    float m_mipParams[4]; // offset 76+

    void Draw(ERC* rc);
};

// 0x803595E4
void BloomNGC::Draw(ERC* rc) {
    // NOTE: asm-derived, heavy GX hardware interaction
    // 1. Save current render state (viewport + general)
    // 2. Set default render states for post-processing
    // 3. Get next external frame buffer
    // 4. GXDrawDone() - wait for GPU
    // 5. Copy EFB to buffer for reading
    // 6. Create texture objects from the copied buffer
    // 7. Construct bloom mip surface with strength parameters
    // 8. Create scaled texture for the mip chain
    // 9. Blend jittered scratch buffer with frame buffer
    // 10. Restore viewport and render states
    // 11. Set dirty flags on render state cache
}

// ============================================================================
// MotionBlurNGC - GameCube-specific motion blur rendering
// ============================================================================

class MotionBlurNGC {
public:
    float m_blurAmount;  // offset 32
    float m_blurStrength; // offset 36
    int m_quality;        // offset 40

    void Draw(ERC* rc);
};

// 0x8035917C
void MotionBlurNGC::Draw(ERC* rc) {
    // NOTE: asm-derived, heavy GX hardware interaction
    // Similar structure to BloomNGC::Draw but for motion blur:
    // 1. Save render state
    // 2. Set default render states
    // 3. Get frame buffers (current + previous)
    // 4. GXDrawDone()
    // 5. Copy EFB to buffer
    // 6. Create texture objects
    // 7. Get previous frame buffer for temporal blending
    // 8. If quality > 0: use scaled intermediate buffer
    // 9. Blend with frame buffer using color/alpha parameters
    // 10. Restore render state
}

// ============================================================================
// DepthOfFieldNGC - GameCube-specific DOF rendering
// ============================================================================

class DepthOfFieldNGC {
public:
    // offset 40: shift amount
    // offset 44-56: DOF parameters (near focus, far focus, blend)

    void Draw(ERC* rc);
};

// 0x80359950
void DepthOfFieldNGC::Draw(ERC* rc) {
    // NOTE: asm-derived, heavy GX hardware interaction
    // Similar structure to BloomNGC/MotionBlurNGC but for DOF:
    // 1. Save render state
    // 2. Copy EFB to buffer
    // 3. Create source texture
    // 4. Compute blur size from shift parameter (256 >> shift)
    // 5. Copy buffer to scaled buffer
    // 6. Create blur texture from scaled buffer
    // 7. Compute DOF blend colors from focus parameters
    // 8. Blend jittered scratch buffer with frame buffer
    // 9. Restore render state
}

// ============================================================================
// FrameEffectsManager - Manages Bloom, MotionBlur, DepthOfField
// ============================================================================

class FrameEffectsManager {
public:
    FrameEffect* m_motionBlur; // offset 0
    FrameEffect* m_bloom;      // offset 4
    FrameEffect* m_depthOfField; // offset 8

    void Init();
    void Shutdown();
};

// 0x803577B8
void FrameEffectsManager::Init() {
    // Allocate and initialize MotionBlur (56 bytes)
    // - Set vtable, initial float params, state = Inactive
    m_motionBlur = (FrameEffect*)operator new(56);
    // Initialize MotionBlur params...

    // Allocate and initialize Bloom (152 bytes)
    m_bloom = (FrameEffect*)operator new(152);
    // Bloom::Bloom() constructor called
    // Set Bloom-specific vtable

    // Allocate and initialize DepthOfField (80 bytes)
    m_depthOfField = (FrameEffect*)operator new(80);
    // DepthOfField::DepthOfField() constructor called
    // Set DOF-specific vtable
}

// 0x803578B0
void FrameEffectsManager::Shutdown() {
    // Delete each effect via virtual destructor, set pointer to null
    if (m_motionBlur) {
        // Call virtual destructor with delete flag = 3
        delete m_motionBlur;
        m_motionBlur = 0;
    }
    if (m_bloom) {
        delete m_bloom;
        m_bloom = 0;
    }
    if (m_depthOfField) {
        delete m_depthOfField;
        m_depthOfField = 0;
    }
}

// ============================================================================
// GameEffectsManager - Manages pre-rendering of particle effects
// ============================================================================

class GameEffectsManager {
public:
    // offset 152: some pointer
    // offset 168: some int flag

    void PreRender();
    void RenderCB(ELevelDrawData& drawData, EOrderTableData* orderTable);
};

// 0x8003E048
void GameEffectsManager::PreRender() {
    // Create EffectsPreRenderVisitor on stack
    // Set its vtable to the pre-render visitor vtable
    // Call Effects::EffectsManager::GetSingleton()
    // Call ForEachActiveEffect with the visitor
    // Reset the visitor vtable to destructor vtable
}

// 0x8003E094
void GameEffectsManager::RenderCB(ELevelDrawData& drawData, EOrderTableData* orderTable) {
    int* thisI = (int*)this;
    void* effectData = *(void**)((char*)orderTable + 24);
    if (effectData != 0) {
        // Get vtable from effectData offset 324
        // Call virtual render function via vtable offset 28
        // with this->m_data (offset 152) as parameter
        thisI[42] = 0; // offset 168 = 0
    }
}

// ============================================================================
// EffectsPreRenderVisitor
// ============================================================================

class EffectsPreRenderVisitor {
public:
    void Visit(int& fastParticleEmitter);
};

// 0x8003DED4
void EffectsPreRenderVisitor::Visit(int& emitter) {
    int* ep = &emitter;
    // Check if emitter has flag 0x800 set in its flags field (offset 320)
    bool isActive = (ep[80] & 0x800) != 0; // offset 320 / 4 = 80
    if (!isActive) return;

    // Initialize EOrderTableData on stack (zero out ~52 bytes)
    // Set up order table entry with emitter's render data
    // Check if emitter uses DOF foreground (offset 72 flag)
    // If DOF foreground: insert into DOF foreground object list with priority 16384
    // Otherwise: insert into normal order table via ERLevel
}

// ============================================================================
// Emitter - Particle emitter wrapper
// ============================================================================

class Emitter : public EInstance {
public:
    // EInstance base: ~124 bytes
    // offset 124: pemitter* m_pEmitter
    // offset 128-136: transform data
    // offset 140-192: render/callback data

    Emitter();
    ~Emitter();
    int Create(char* name, float* matrix, pemitterinfo* info,
               ParticleInitCB initCB, ParticleDestroyCB destroyCB,
               EmitterUpdateCB updateCB, void* userData);
    void Reg(psystem* sys, bool addToLevel);
    void UnReg(psystem* sys, bool removeFromLevel);
    void SetMatrix(float* matrix);
    void SetState(int stateBits, int enable);
    void* Get();
    void SetCallbacks(ParticleInitCB cb1, ParticleDestroyCB cb2,
                      ParticleDestroyCB cb3, EmitterUpdateCB cb4, void* ud1,
                      ParticleDestroyCB cb5, void* ud2,
                      ParticleDestroyCB cb6, void* ud3);
    void EmitterSetPostDestroyCallback(ParticleDestroyCB cb, void* userData);
    void EmitterSetIntervalCallback(ParticleDestroyCB cb, void* userData);
    void SetSortPos(EVec3& pos);
    void Destroy();
    void PEmitterSubmitParticlesCB(ELevelDrawData& drawData, EOrderTableData* orderTable);
    void Draw(ELevelDrawData& drawData);
};

// 0x802386A4
Emitter::Emitter() {
    // Call EInstance::EInstance()
    // Set vtable
    // Zero out all callback/data fields (offsets 140-192)
    // Zero pemitter pointer at offset 124
}

// 0x8023872C
Emitter::~Emitter() {
    // Set vtable
    void* pEmitter = *(void**)((char*)this + 124);
    if (pEmitter) {
        int flags = *(int*)((char*)pEmitter + 80);
        if (!(flags & 0x4000)) {
            Destroy();
        }
    }
    // Call EInstance::~EInstance()
}

// 0x802383EC
int Emitter::Create(char* name, float* matrix, pemitterinfo* info,
                    ParticleInitCB initCB, ParticleDestroyCB destroyCB,
                    EmitterUpdateCB updateCB, void* userData) {
    // Call PEmitterCreate on internal pemitter at offset 124
    int result = PEmitterCreate((char*)this + 124);
    // Initialize transform data, zero out various fields
    float* fThis = (float*)this;
    fThis[25] = 0.0f; // offset 100
    fThis[24] = 0.0f; // offset 96
    *(int*)((char*)this + 112) = 0;
    *(int*)((char*)this + 104) = 0;
    *(int*)((char*)this + 108) = 0;
    // Return 0 on success, -1 on failure
    return (result >= 0) ? 0 : -1;
}

// 0x802384B0
void Emitter::Reg(psystem* sys, bool addToLevel) {
    void* pEmitter = *(void**)((char*)this + 124);
    if (pEmitter) {
        PEmitterReg(sys, pEmitter);
        if (addToLevel) {
            // ERLevel::InsertInstance(this, 0)
        }
    }
}

// 0x8023850C
void Emitter::UnReg(psystem* sys, bool removeFromLevel) {
    void* pEmitter = *(void**)((char*)this + 124);
    if (pEmitter) {
        PEmitterUnReg(sys, pEmitter);
        if (removeFromLevel) {
            void* owner = *(void**)((char*)this + 4);
            if (owner) {
                // ERLevel::RemoveInstance(this)
            }
        }
    }
}

// 0x80238570
void Emitter::SetMatrix(float* matrix) {
    void* pEmitter = *(void**)((char*)this + 124);
    if (!pEmitter) return;
    // Copy 16 floats from matrix to pEmitter
    float* dst = (float*)pEmitter;
    for (int i = 0; i < 16; i++) {
        dst[i] = matrix[i];
    }
}

// 0x80238608
void Emitter::SetState(int stateBits, int enable) {
    void* pEmitter = *(void**)((char*)this + 124);
    if (!pEmitter) return;

    int* flagsPtr = (int*)((char*)pEmitter + 80);
    if (enable) {
        *flagsPtr |= stateBits;
    } else {
        *flagsPtr &= ~stateBits;
    }

    if (stateBits & 0x4000) {
        // Remove from level if kill flag set
        void* owner = *(void**)((char*)this + 4);
        if (owner) {
            // ERLevel::RemoveInstance(this)
        }
    }
}

// 0x8023878C
void Emitter::SetCallbacks(ParticleInitCB cb1, ParticleDestroyCB cb2,
                           ParticleDestroyCB cb3, EmitterUpdateCB cb4, void* ud1,
                           ParticleDestroyCB cb5, void* ud2,
                           ParticleDestroyCB cb6, void* ud3) {
    void* pEmitter = *(void**)((char*)this + 124);
    if (!pEmitter) return;

    unsigned int sentinel = 0x0000FFFF;
    int** pe = (int**)pEmitter;

    if ((unsigned int)(unsigned long)cb1 != sentinel) *(void**)((char*)pEmitter + 144) = (void*)cb1;
    if ((unsigned int)(unsigned long)cb3 != sentinel) *(void**)((char*)pEmitter + 152) = (void*)cb3;
    if ((unsigned int)(unsigned long)cb6 != sentinel) *(void**)((char*)pEmitter + 160) = (void*)cb6;
    if ((unsigned int)(unsigned long)cb4 != sentinel) *(void**)((char*)pEmitter + 156) = (void*)cb4;
    if ((unsigned int)(unsigned long)ud1 != sentinel) *(void**)((char*)pEmitter + 164) = (void*)ud1;
    if ((unsigned int)(unsigned long)cb5 != sentinel) *(void**)((char*)pEmitter + 168) = (void*)cb5;
    if ((unsigned int)(unsigned long)cb2 != sentinel) *(void**)((char*)pEmitter + 148) = (void*)cb2;
    if ((unsigned int)(unsigned long)ud3 != sentinel) *(void**)((char*)pEmitter + 176) = (void*)ud3;
    if ((unsigned int)(unsigned long)ud2 != sentinel) *(void**)((char*)pEmitter + 172) = (void*)ud2;
}

// 0x8023884C
void Emitter::EmitterSetPostDestroyCallback(ParticleDestroyCB cb, void* userData) {
    if (!*(void**)((char*)this + 124)) return;
    // Call SetCallbacks with all sentinel values except the post-destroy slot
    unsigned int s = 0x0000FFFF;
    SetCallbacks((ParticleInitCB)(unsigned long)s, (ParticleDestroyCB)(unsigned long)s,
                 (ParticleDestroyCB)(unsigned long)s, (EmitterUpdateCB)(unsigned long)s,
                 (void*)(unsigned long)s, (ParticleDestroyCB)(unsigned long)s,
                 0, (ParticleDestroyCB)(unsigned long)s, 0);
}

// 0x802388B4
void Emitter::EmitterSetIntervalCallback(ParticleDestroyCB cb, void* userData) {
    if (!*(void**)((char*)this + 124)) return;
    // Call SetCallbacks with all sentinel values except interval callback slot
    unsigned int s = 0x0000FFFF;
    SetCallbacks((ParticleInitCB)(unsigned long)s, (ParticleDestroyCB)(unsigned long)s,
                 (ParticleDestroyCB)(unsigned long)s, (EmitterUpdateCB)(unsigned long)s,
                 (void*)(unsigned long)s, (ParticleDestroyCB)(unsigned long)s,
                 (void*)(unsigned long)s, cb, userData);
}

// 0x80238980
void Emitter::PEmitterSubmitParticlesCB(ELevelDrawData& drawData, EOrderTableData* orderTable) {
    void* emitterData = *(void**)((char*)orderTable + 36 + 124);
    if (emitterData) {
        // PEmitterSubmitParticles with global dt
        // Zero out offsets 184, 172, 180, 168
    }
}

// 0x802389DC
void Emitter::Draw(ELevelDrawData& drawData) {
    void* pEmitter = *(void**)((char*)this + 124);
    if (!pEmitter) return;

    int* thisI = (int*)this;
    thisI[44] = (int)(uintptr_t)this; // offset 176 = this

    int flags = *(int*)((char*)pEmitter + 80);
    if (flags & 0x02200000) {
        // Direct emitter position from pemitter offset 48
        *(void**)((char*)this + 148) = (char*)pEmitter + 48;
    } else {
        // Get position from texture/model data chain
        // Compute position from the emitter info structure
        // NOTE: asm-derived, complex data chain traversal
    }

    // Check DOF foreground flag
    if (flags & 0x08000000) {
        // Insert into DOF foreground list
    } else {
        // Insert into normal order table
        InsertInOrderTable((char*)this + 140);
    }
}

// ============================================================================
// EmitterGeom3d - 3D geometry particle emitter
// ============================================================================

class EmitterGeom3d {
public:
    void Create(char* name, float* matrix, pemitterinfo* info);
};

// 0x8023A134
void EmitterGeom3d::Create(char* name, float* matrix, pemitterinfo* info) {
    Emitter* self = (Emitter*)this;
    int result = self->Create(name, matrix, info, 0, 0, 0, 0);
    if (result == -1) return;

    // Get pemitter data, set geometry-specific callbacks
    void* pData = self->Get();
    // Set Geom3d-specific callbacks
    // Copy info->offset364 to pData->offset128
    // Set matrix
    self->SetMatrix(matrix);
    // Set flags: oris 0,0,32 => set flag bit 0x00200000
    void* pInfo = *(void**)((char*)pData + 136);
    int* flagsPtr = (int*)((char*)pInfo + 264);
    *flagsPtr |= 0x00200000;
}

// ============================================================================
// EmitterGeom3dTab - Tabulated 3D geometry emitter
// ============================================================================

class EmitterGeom3dTab {
public:
    void Create(char* name, float* matrix, pemitterinfo* info);
};

// 0x8023A3F4
void EmitterGeom3dTab::Create(char* name, float* matrix, pemitterinfo* info) {
    Emitter* self = (Emitter*)this;
    int result = self->Create(name, matrix, info, 0, 0, 0, 0);
    if (result == -1) return;

    // Similar to EmitterGeom3d but with additional flags
    void* pData = self->Get();
    // addi 0,info,364 => store address of info+364
    void* pInfo2 = *(void**)((char*)pData + 136);
    *(void**)((char*)pData + 128) = (char*)info + 364;
    self->SetMatrix(matrix);
    // Set additional flags: 0x02000000 and 0x0800
    int* flagsPtr = (int*)((char*)pInfo2 + 264);
    *flagsPtr |= 0x02000000;
    *flagsPtr |= 0x0800;
    // Store info->offset360 at pInfo2->offset260
    *(int*)((char*)pInfo2 + 260) = *(int*)((char*)info + 360);
}

// ============================================================================
// EmitterSpr3d - Sprite-based 3D particle emitter
// ============================================================================

class EmitterSpr3d {
public:
    void Create(char* name, float* matrix, pemitterinfo* info);
    void CreateCameraFollowXYZ(char* name, float* matrix, pemitterinfo* info);
    void CreateCameraFollowXY(char* name, float* matrix, pemitterinfo* info);
};

// 0x80239BC4
void EmitterSpr3d::Create(char* name, float* matrix, pemitterinfo* info) {
    Emitter* self = (Emitter*)this;
    int result = self->Create(name, matrix, info, 0, 0, 0, 0);
    if (result == -1) return;

    // Set sprite-specific callbacks
    void* pData = self->Get();
    // Copy info->offset364 to pData->offset128
    void* inner = *(void**)((char*)pData + 136);
    *(int*)((char*)pData + 128) = *(int*)((char*)info + 364);
    self->SetMatrix(matrix);
}

// 0x80239C78
void EmitterSpr3d::CreateCameraFollowXYZ(char* name, float* matrix, pemitterinfo* info) {
    Create(name, matrix, info);
    // NOTE: Create returns via r3, check for -1
    Emitter* self = (Emitter*)this;
    // if result == -1, return

    void* pData = self->Get();
    void* inner = *(void**)((char*)pData + 136);
    // Set camera follow XYZ flags:
    // flag |= 0x01000000 (camera follow)
    // flag |= 0x00100000 (XYZ mode)
    // Clear bits 3-6: rlwinm 0,0,0,28,25
    int* flagsPtr = (int*)((char*)inner + 264);
    *flagsPtr |= 0x01000000;
    *flagsPtr |= 0x00100000;
    *flagsPtr &= ~0x3C; // clear bits 2-5
    // Clear bit in pData->offset80: rlwinm 9,9,0,19,17
    int* sortFlags = (int*)((char*)pData + 80);
    *sortFlags &= ~0x00001800;
}

// 0x80239D40
void EmitterSpr3d::CreateCameraFollowXY(char* name, float* matrix, pemitterinfo* info) {
    Create(name, matrix, info);
    Emitter* self = (Emitter*)this;
    // Same structure as CreateCameraFollowXYZ but with XY-only callbacks
    void* pData = self->Get();
    void* inner = *(void**)((char*)pData + 136);
    int* flagsPtr = (int*)((char*)inner + 264);
    *flagsPtr |= 0x01000000;
    *flagsPtr |= 0x00100000;
    *flagsPtr &= ~0x3C;
    int* sortFlags = (int*)((char*)pData + 80);
    *sortFlags &= ~0x00001800;
}

// ============================================================================
// EParticleEffect - Per-object particle effect instance
// ============================================================================

class EParticleEffect {
public:
    // offset 0-63: EMat4 transform
    // offset 64: short param
    // offset 68: ptr effectData1
    // offset 72: int useNewSystem
    // offset 76: int isAnimated
    // offset 88: Emitter* m_emitter
    // offset 92: void* m_effectsEffect
    // offset 96: unsigned int m_resourceId
    // offset 100: int m_effectType (0=old particle, 1=new effects)
    // offset 104: void* m_oldResource
    // offset 108: void* m_newResource

    EParticleEffect(AttachmentNode& node, EMat4& mat);
    ~EParticleEffect();
    int UpdateParticleEffectLoad();
    void SetPos(EMat4& mat, EVec3* sortPos);
    void SetAlphaFade(float alpha);
};

// 0x8004B8E0
EParticleEffect::EParticleEffect(AttachmentNode& node, EMat4& mat) {
    int* iThis = (int*)this;
    iThis[17] = 0; // offset 68
    iThis[18] = 0; // offset 72
    iThis[19] = 0; // offset 76
    *(short*)((char*)this + 64) = 0;

    // EMat4::Id() on this (the transform at offset 0)
    iThis[23] = 0; // offset 92
    iThis[26] = 0; // offset 104
    iThis[27] = 0; // offset 108
    iThis[22] = 0; // offset 88

    // Extract attachment node data
    iThis[24] = node.resourceId; // offset 96
    int effectType = node.flags & ~(*(unsigned char*)0); // mask with global flag
    iThis[25] = effectType; // offset 100
    *(short*)((char*)this + 64) = node.param;

    int isAnimated = (node.flags & 0x80) ? 1 : 0; // check animation flag
    iThis[19] = isAnimated; // offset 76

    // Copy EMat4 (64 bytes)
    memcpy(this, &mat, 64);

    // AddRefAsync based on effect type
    if (effectType == 0) {
        EResourceManager::AddRefAsync(node.resourceId);
    } else if (effectType == 1) {
        EResourceManager::AddRefAsync(node.resourceId);
    }

    UpdateParticleEffectLoad();
}

// 0x8004BA38
int EParticleEffect::UpdateParticleEffectLoad() {
    int* iThis = (int*)this;
    int effectType = iThis[25]; // offset 100

    if (effectType == 0) {
        // Old-style particle effect
        if (iThis[26]) return 1; // already loaded

        EResource* res = EResourceManager::GetRef(iThis[24]);
        iThis[26] = (int)(uintptr_t)res; // offset 104
        if (!res) return 0;

        // Get pemitterinfo from resource
        void* pInfo = *(void**)((char*)res + 20);

        // Check emitter type flags and create appropriate emitter
        int flags = *(int*)((char*)pInfo + 264);

        Emitter* emitter;
        if (flags & 0x02000000) {
            // EmitterGeom3dTab
            emitter = new Emitter();
            // Create as EmitterGeom3dTab
        } else if (flags & 0x00200000) {
            // EmitterGeom3d
            emitter = new Emitter();
            // Create as EmitterGeom3d
        } else {
            // EmitterSpr3d
            emitter = new Emitter();
            // Create as EmitterSpr3d
        }
        iThis[22] = (int)(uintptr_t)emitter; // offset 88

        // Register and set callbacks
        return 1;
    } else if (effectType == 1) {
        // New Effects system
        if (iThis[27]) return 1; // offset 108, already loaded

        EResource* res = EResourceManager::GetRef(iThis[24]);
        iThis[27] = (int)(uintptr_t)res;
        if (!res) return 0;

        // Effects::EffectsManager::CreateEffect
        // Store effect handle at offset 92
        return 1;
    }

    return 0;
}

// 0x8004BC6C
EParticleEffect::~EParticleEffect() {
    int* iThis = (int*)this;
    Emitter* emitter = (Emitter*)(unsigned long)iThis[22]; // offset 88

    if (emitter) {
        emitter->SetState(0x4000, 1); // kill
        emitter->SetState(8, 1);      // stop
        // Delete emitter
        iThis[24] = 0; // offset 96
        iThis[22] = 0; // offset 88
        iThis[26] = 0; // offset 104
    } else {
        void* effect = (void*)(unsigned long)iThis[23]; // offset 92
        if (effect) {
            // Set destroy flags and call Release
            iThis[23] = 0;
        } else {
            // DelRefAsync for resource
            if (iThis[24] && iThis[25] == 0) {
                EResourceManager::DelRefAsync(iThis[24]);
            }
        }
    }

    // Clean up secondary resource
    if (iThis[24] && iThis[25] == 1) {
        EResourceManager::DelRefAsync(iThis[24]);
    }

    // Free memory if needed (via delete flag)
}

// 0x8004BDAC
void EParticleEffect::SetPos(EMat4& mat, EVec3* sortPos) {
    int* iThis = (int*)this;
    int effectType = iThis[25]; // offset 100

    if (effectType == 0) {
        // Old particle system
        Emitter* emitter = (Emitter*)(unsigned long)iThis[22];
        if (!emitter) return;

        emitter->SetState(2, 1); // enable
        emitter->SetSortPos(*sortPos);

        void* pData = emitter->Get();
        void* pInfo = *(void**)((char*)pData + 136);

        // Build composite transform: copy mat, check rotation flags
        // If no rotation flag: zero out rotation part
        // If no translation flag: zero out translation
        // Mult4x4 with emitter's info matrix
        // SetMatrix with result
    } else if (effectType == 1) {
        // New Effects system
        void* effect = (void*)(unsigned long)iThis[23];
        if (!effect) return;

        // Set flags for transform update
        int* eFlags = (int*)((char*)effect + 320);
        *eFlags |= 0x0800; // transform dirty
        *eFlags |= 0x0400; // position dirty
        // Effects::Effect::SetParentTransform(mat)
        // Set sort position
    }
}

// 0x8004BFE4
void EParticleEffect::SetAlphaFade(float alpha) {
    int* iThis = (int*)this;
    int effectType = iThis[25]; // offset 100

    if (effectType == 0) {
        Emitter* emitter = (Emitter*)(unsigned long)iThis[22];
        if (!emitter) return;

        if (alpha < 0.5f) { // NOTE: threshold from float constant
            emitter->SetState(4, 0); // disable alpha
        } else {
            emitter->SetState(4, 1); // enable alpha
        }
    } else if (effectType == 1) {
        void* effect = (void*)(unsigned long)iThis[23];
        if (!effect) return;
        *(float*)((char*)effect + 332) = alpha;
    }
}

// ============================================================================
// EParticleObj - Container for particle effects on an object
// ============================================================================

class EParticleObj : public ENodeList {
public:
    // offset 0: ENodeList base (node list for effects)
    // offset 12: EResource* m_attachmentResource

    ~EParticleObj();
    int CreateEffects(EMat4& mat, float scale, ObjAnimDef* animDef);
    void UpdateEffectPosAndAlphaFade(EAnimController& animCtrl, float dt, EMat4& mat, EVec3* sortPos, float alpha);
};

// 0x8004C150
EParticleObj::~EParticleObj() {
    // Iterate linked list, destroy each EParticleEffect
    // RemoveAll from node list
    // DelRef attachment resource if present
    // RemoveAll again
}

// 0x8004C1F8
int EParticleObj::CreateEffects(EMat4& mat, float scale, ObjAnimDef* animDef) {
    // Destroy existing effects (iterate and delete)
    // RemoveAll
    // DelRef existing attachment resource

    // Load attachment resource from animDef
    int* iThis = (int*)this;
    unsigned int resId = *(unsigned int*)((char*)animDef + 4);
    if (!resId) return 0;

    EResource* res = EResourceManager::AddRef(resId, 0, 0);
    iThis[3] = (int)(uintptr_t)res; // offset 12

    if (!res) return 0;

    // Get attachment count from resource
    int* resData = (int*)((char*)res + 20);
    int* endData = (int*)((char*)res + 24);
    int count = (*endData - *resData) / 8;

    if (count == 0) {
        res->DelRef();
        iThis[3] = 0;
        return 0;
    }

    // Create EParticleEffect for each attachment node
    for (int i = 0; i < count; i++) {
        void* nodeData = (char*)*resData + i * 8;
        unsigned int nodeResId = *(unsigned int*)((char*)nodeData + 4);
        if (nodeResId == 0) continue;

        void* mem = MainHeap()->MallocAligned(112, 16, 0, 0);
        // EParticleEffect constructor with node and mat
        // AddTail to this node list
    }

    return 1;
}

// 0x8004C350
void EParticleObj::UpdateEffectPosAndAlphaFade(EAnimController& animCtrl, float dt, EMat4& mat, EVec3* sortPos, float alpha) {
    int* iThis = (int*)this;
    void* node = (void*)(unsigned long)iThis[0]; // first node
    if (!node) return;

    int offset = 0;
    while (node) {
        void* effect = *(void**)node;
        if (effect) {
            EParticleEffect* pEffect = (EParticleEffect*)effect;
            if (pEffect->UpdateParticleEffectLoad()) {
                // Get attachment info
                EResource* res = (EResource*)(unsigned long)iThis[3];
                void* attachData = *(void**)((char*)res + 20);
                void* nodeInfo = (char*)attachData + offset;

                // Check if bone-attached (flag & 0x80)
                unsigned char flags = *(unsigned char*)((char*)nodeInfo + 1);
                if (!(flags & 0x80)) {
                    // Bone-attached: calc node orient, then SetPos
                    EMat4 boneMat;
                    boneMat = mat;
                    // CalcNodeOrient on animCtrl
                    pEffect->SetPos(boneMat, sortPos);
                    pEffect->SetAlphaFade(alpha);
                } else {
                    // Direct attachment
                    pEffect->SetPos(mat, sortPos);
                    pEffect->SetAlphaFade(alpha);
                }
            }
        }
        node = *(void**)((char*)node + 8);
        offset += 8;
    }
}

// ============================================================================
// EBoneParticle - Bone-attached particle effect
// ============================================================================

class EBoneParticle {
public:
    // offset 0-63: EMat4 transform
    // offset 64: short param
    // offset 68-76: flags
    // offset 80: cXPerson* m_person
    // offset 84: unsigned int m_animId
    // offset 88-128: various state
    // offset 96: unsigned int m_resourceId
    // offset 100: int m_effectType
    // offset 104: Emitter* m_emitter
    // offset 108: void* m_effectsEffect
    // offset 112: void* m_oldResource
    // offset 116: void* m_newResource
    // offset 120: int m_killOnDestroy
    // offset 124: bool m_isLooping

    EBoneParticle(cXPerson* person, AnimParticleData* data, bool looping);
    ~EBoneParticle();
    int UpdateParticleLoad();
    void Update();
};

// 0x80015074
EBoneParticle::EBoneParticle(cXPerson* person, AnimParticleData* data, bool looping) {
    int* iThis = (int*)this;
    iThis[17] = 0; // offset 68
    iThis[18] = 0; // offset 72
    iThis[19] = 0; // offset 76
    *(short*)((char*)this + 64) = 0;

    // EMat4::Id()
    iThis[20] = (int)(uintptr_t)person;  // offset 80
    iThis[21] = *(int*)data;  // offset 84 = animId
    iThis[26] = 0; // offset 104
    iThis[27] = 0; // offset 108
    iThis[28] = 0; // offset 112
    iThis[29] = 0; // offset 116

    // Extract data from AnimParticleData
    iThis[24] = *(int*)((char*)data + 4);  // offset 96 = resourceId
    // Compute effect type from flags
    iThis[25] = 0; // offset 100 = effectType
    iThis[31] = (int)looping; // offset 124
    iThis[30] = 0; // offset 120

    // AddRefAsync for the resource
    UpdateParticleLoad();
}

// 0x800151C4
int EBoneParticle::UpdateParticleLoad() {
    int* iThis = (int*)this;
    int effectType = iThis[25]; // offset 100

    if (effectType == 0) {
        if (iThis[28]) return 1; // offset 112 already loaded

        EResource* res = EResourceManager::GetRef(iThis[24]); // offset 96
        iThis[28] = (int)(uintptr_t)res;
        if (!res) return 0;

        void* pInfo = *(void**)((char*)res + 20);

        // Create EmitterSpr3d
        Emitter* emitter = new Emitter();
        iThis[26] = (int)(uintptr_t)emitter; // offset 104

        // EmitterSpr3d::Create
        // If creation failed, destroy emitter, return 1
        // If succeeded: set state, set callbacks, register
        return 1;
    } else if (effectType == 1) {
        if (iThis[29]) return 1; // offset 116

        EResource* res = EResourceManager::GetRef(iThis[24]);
        iThis[29] = (int)(uintptr_t)res;
        if (!res) return 0;

        // Effects::EffectsManager::CreateEffect
        iThis[27] = 0; // store effect at offset 108
        return (iThis[27] != 0) ? 1 : 0;
    }

    return 0;
}

// 0x80015358
EBoneParticle::~EBoneParticle() {
    int* iThis = (int*)this;
    iThis[20] = 0; // offset 80 = null person

    Emitter* emitter = (Emitter*)(unsigned long)iThis[26]; // offset 104
    if (emitter) {
        emitter->SetState(8, 1); // stop
        if (iThis[30] == 0) { // offset 120 killOnDestroy
            emitter->SetState(0x4000, 1); // kill
        } else {
            emitter->SetState(0x4000, 0);
            // UnReg and DelRef
        }
        // Destroy emitter
        iThis[24] = 0;
        iThis[26] = 0;
        iThis[28] = 0;
    } else {
        void* effect = (void*)(unsigned long)iThis[27]; // offset 108
        if (effect) {
            if (iThis[30] == 0) {
                // Set destroy flag
            } else {
                // DeleteEffect via EffectsManager
            }
            iThis[29] = 0;
            iThis[27] = 0;
        } else {
            // DelRefAsync
            if (iThis[24] && iThis[25] == 0) {
                EResourceManager::DelRefAsync(iThis[24]);
            }
        }
    }

    // Clean up secondary resources
    if (iThis[24] && iThis[25] == 1) {
        EResourceManager::DelRefAsync(iThis[24]);
    }
}

// 0x80015504
void EBoneParticle::Update() {
    if (!UpdateParticleLoad()) return;

    int* iThis = (int*)this;
    cXPerson* person = (cXPerson*)(unsigned long)iThis[20]; // offset 80

    // Get bone transform from person's animation system
    EMat4 boneMat;
    if (person) {
        // Get skeleton, calc bone orient
    } else {
        boneMat.Id();
    }

    int effectType = iThis[25]; // offset 100
    if (effectType == 0) {
        Emitter* emitter = (Emitter*)(unsigned long)iThis[26]; // offset 104
        if (!emitter) return;

        // Check visibility state on person
        // SetState(2, visible ? 1 : 0)

        // Get pemitter info, build composite matrix
        // Handle rotation/translation flags
        // SetMatrix on emitter
    } else if (effectType == 1) {
        void* effect = (void*)(unsigned long)iThis[27]; // offset 108
        if (!effect) return;

        // Check visibility, set flags
        // Effects::Effect::SetParentTransform
    }
}

// ============================================================================
// REffectsEmitter - Resource wrapper for Effects emitter data
// ============================================================================

class REffectsEmitter : public EResource {
public:
    // offset 20: void* m_data (pemitterinfo)
    // offset 24: void* m_rawData
    // offset 28: void* m_subResource
    // offset 32: int m_dirty

    REffectsEmitter();
    ~REffectsEmitter();
    void Deallocate();
    void AddRefSubResources();
    int TryIncrementSubResources();
    void Load(EFile* file);
    void Refresh(EFile* file);
    static void RegisterType(unsigned short typeId);
};

// 0x8036A7B4
REffectsEmitter::REffectsEmitter() {
    // EResource::EResource()
    // Set vtable
    int* iThis = (int*)this;
    iThis[8] = 0;  // offset 32
    iThis[5] = 0;  // offset 20
    iThis[6] = 0;  // offset 24
    iThis[7] = 0;  // offset 28
}

// 0x8036A804
REffectsEmitter::~REffectsEmitter() {
    // Set vtable
    Deallocate();
    // EResource::~EResource()
    // Optional: MainHeap()->Free(this)
}

// 0x8036A860
void REffectsEmitter::Deallocate() {
    int* iThis = (int*)this;
    // Call virtual DelRefSubResources via vtable
    if (iThis[6]) { // offset 24
        MainHeap()->Free((void*)(unsigned long)iThis[6]);
        iThis[6] = 0;
        iThis[5] = 0;
    }
}

// 0x8036A904
void REffectsEmitter::AddRefSubResources() {
    int* iThis = (int*)this;
    iThis[7] = 0; // offset 28

    void* data = (void*)(unsigned long)iThis[5]; // offset 20
    if (!data) return;

    unsigned int subResId = *(unsigned int*)((char*)data + 192);
    if (!subResId) return;

    EResource* subRes = EResourceManager::AddRef(subResId, 0, 0);
    iThis[7] = (int)(uintptr_t)subRes;
}

// 0x8036A964
int REffectsEmitter::TryIncrementSubResources() {
    int* iThis = (int*)this;
    void* data = (void*)(unsigned long)iThis[5]; // offset 20
    if (!data) return 1;

    unsigned int subResId = *(unsigned int*)((char*)data + 192);
    if (!subResId) return 1;

    EResource* result = 0;
    if (!EResourceManager::TryIncrementResource(subResId, &result)) {
        return 0;
    }
    iThis[7] = (int)(uintptr_t)result;
    return 1;
}

// 0x8036A9D0
void REffectsEmitter::Load(EFile* file) {
    Deallocate();
    if (!file) return;

    EDataHeader header;
    // Read with magic 'EuTt' (0x45755474)
    if (!header.Read(file, 0x45755474, 1, 1)) return;

    // Extract name/size, update resource flags
    // Allocate aligned memory for data
    void* data = MainHeap()->MallocAligned(header.m_size, 64, 0, 0);
    int* iThis = (int*)this;
    iThis[6] = (int)(uintptr_t)data; // offset 24
    iThis[5] = (int)((uintptr_t)data + 144); // offset 20 = data + 144

    // Read data from file
    // Call virtual post-load via vtable
}

// 0x8036AAC4
void REffectsEmitter::Refresh(EFile* file) {
    if (!file) return;
    Deallocate();
    Load(file);
    int* iThis = (int*)this;
    iThis[8] = 1; // offset 32 = dirty
}

// 0x8036AC78
void REffectsEmitter::RegisterType(unsigned short typeId) {
    // ETypeInfo::Register with create/load/destroy function pointers
    // and type name string
}

// ============================================================================
// REffectsAttachment - Resource wrapper for attachment data
// ============================================================================

class REffectsAttachment : public EResource {
public:
    // offset 20: AttachmentNode* m_nodes (vector start)
    // offset 24: int m_nodeCount (vector end)
    // offset 28-32: vector capacity data

    REffectsAttachment();
    ~REffectsAttachment();
    void OldLoad(EFile* file);
    void Load(EFile* file);
    void Refresh(EFile* file);
    static void RegisterType(unsigned short typeId);
};

// 0x80322400
REffectsAttachment::REffectsAttachment() {
    // EResource::EResource()
    // Set vtable
    int* iThis = (int*)this;
    iThis[5] = 0; // offset 20
    iThis[6] = 0; // offset 24
    // Zero vector metadata at offset 28+
    *(int*)((char*)this + 32) = 0;
}

// 0x80322450
REffectsAttachment::~REffectsAttachment() {
    // Set vtable
    // Iterate vector, clean up nodes
    // Free vector memory
    // EResource::~EResource()
}

// 0x803224F4
void REffectsAttachment::OldLoad(EFile* file) {
    if (!file) return;

    EDataHeader header;
    // Read with magic 'EaAc' (0x45614163)
    if (!header.Read(file, 0x45614163, 1, 1)) return;

    // Parse old format: read AttachmentNodeV1 array
    // Convert V1 nodes to current AttachmentNode format
    // Populate the attachment node vector
}

// 0x80322780
void REffectsAttachment::Load(EFile* file) {
    if (!file) return;

    EDataHeader header;
    // Read with magic 'EaAc', version 2
    if (!header.Read(file, 0x45614163, 2, 2)) {
        // Fall back to old format
        OldLoad(file);
        return;
    }

    // Parse V2 format directly
    // Resize vector to hold header.m_size / 8 nodes
    // Read node data from file
}

// 0x803228AC
void REffectsAttachment::Refresh(EFile* file) {
    if (!file) return;

    // Swap current nodes to temp, clear current
    // Load new data
    // Free old temp data
    Load(file);
}

// 0x80322B00
void REffectsAttachment::RegisterType(unsigned short typeId) {
    // ETypeInfo::Register with type-specific function pointers
}

// ============================================================================
// REffectsSequencer - Resource wrapper for sequencer data
// ============================================================================

class REffectsSequencer : public EResource {
public:
    ~REffectsSequencer();
    void Deallocate();
    void Load(EFile* file);
    static void RegisterType(unsigned short typeId);
};

// 0x8036AEAC
REffectsSequencer::~REffectsSequencer() {
    // Set vtable
    Deallocate();
    // EResource::~EResource()
}

// 0x8036AF4C
void REffectsSequencer::Load(EFile* file) {
    Deallocate();
    if (!file) return;

    EDataHeader header;
    // Read with magic 'EQEq' (0x45514571)
    if (!header.Read(file, 0x45514571, 1, 1)) return;

    // Extract data, update resource flags
    // Call virtual post-load via vtable
}

// 0x8036B1A8
void REffectsSequencer::RegisterType(unsigned short typeId) {
    // ETypeInfo::Register
}

// ============================================================================
// RParticle - Resource wrapper for particle system data
// ============================================================================

class RParticle : public EResource {
public:
    // offset 20: void* m_data (pemitterinfo, 1420 bytes)
    // offset 24: int m_subCount
    // offset 28+: sub-resource pointers (up to 8)

    RParticle();
    ~RParticle();
    void Deallocate();
    void DelRefSubResources();
    void AddRefSubResources();
    int TryIncrementSubResources();
    void PrepareData();
    void Load(EFile* file, unsigned int magic);
    void Refresh(EFile* file);
    static void RegisterType(unsigned short typeId);
};

// 0x8036B2E8
RParticle::RParticle() {
    // EResource::EResource()
    // Set vtable
    int* iThis = (int*)this;
    iThis[6] = 0; // offset 24
    iThis[5] = 0; // offset 20
    // Zero out 8 sub-resource pointers (offsets 28-56)
    for (int i = 0; i < 8; i++) {
        iThis[7 + i] = 0;
    }
}

// 0x8036B34C
RParticle::~RParticle() {
    // Set vtable
    Deallocate();
    // EResource::~EResource()
    // Free via EResourceManager
}

// 0x8036B3AC
void RParticle::Deallocate() {
    int* iThis = (int*)this;
    // Call virtual DelRefSubResources via vtable
    // Free m_data via EResourceManager::Free
    EResourceManager::Free((void*)(unsigned long)iThis[5]);
    iThis[5] = 0; // offset 20
}

// 0x8036B404
void RParticle::DelRefSubResources() {
    int* iThis = (int*)this;
    void* data = (void*)(unsigned long)iThis[5]; // offset 20
    if (!data) return;

    int count = iThis[6]; // offset 24
    for (int i = 0; i < count; i++) {
        void* subRes = (void*)(unsigned long)iThis[7 + i]; // offsets 28+
        if (!subRes) continue;

        // Get texture resource at data + 364 + i*132
        void* texRes = *(void**)((char*)data + 364 + i * 132);
        int nextRef = *(int*)((char*)texRes + 8);
        ((EResource*)texRes)->DelRef();
        iThis[7 + i] = 0;
        *(void**)((char*)data + 364 + i * 132) = (void*)(unsigned long)nextRef;
    }
}

// 0x8036B490
void RParticle::AddRefSubResources() {
    int* iThis = (int*)this;
    void* data = (void*)(unsigned long)iThis[5]; // offset 20
    if (!data) return;

    int flags = *(int*)((char*)data + 264);

    if (flags & 0x00200000) {
        // Single texture: AddRef for model resource
        unsigned int resId = *(unsigned int*)((char*)data + 364);
        EResource* res = EResourceManager::AddRef(resId, 0, 0);
        iThis[7] = (int)(uintptr_t)res; // offset 28
        *(unsigned int*)((char*)data + 364) = (unsigned int)(unsigned long)res;
    } else if (flags & 0x02000000) {
        // Multiple textures: AddRef for each
        int count = iThis[6]; // offset 24
        for (int i = 0; i < count; i++) {
            unsigned int resId = *(unsigned int*)((char*)data + 364 + i * 132);
            EResource* res = EResourceManager::AddRef(resId, 0, 0);
            iThis[7 + i] = (int)(uintptr_t)res;
            *(unsigned int*)((char*)data + 364 + i * 132) = (unsigned int)(unsigned long)res;
        }
    } else {
        // Sprite texture
        unsigned int resId = *(unsigned int*)((char*)data + 364);
        EResource* res = EResourceManager::AddRef(resId, 0, 0);
        iThis[7] = (int)(uintptr_t)res;
        *(unsigned int*)((char*)data + 364) = (unsigned int)(unsigned long)res;
    }
}

// 0x8036B55C
int RParticle::TryIncrementSubResources() {
    int* iThis = (int*)this;
    void* data = (void*)(unsigned long)iThis[5]; // offset 20
    if (!data) return 1;

    int flags = *(int*)((char*)data + 264);

    if (flags & 0x00200000) {
        unsigned int resId = *(unsigned int*)((char*)data + 364);
        EResource* res = 0;
        if (!EResourceManager::TryIncrementResource(resId, &res)) return 0;
        iThis[7] = (int)(uintptr_t)res;
        *(unsigned int*)((char*)data + 364) = (unsigned int)(unsigned long)res;
    } else if (flags & 0x02000000) {
        int count = iThis[6]; // offset 24
        for (int i = 0; i < count; i++) {
            unsigned int resId = *(unsigned int*)((char*)data + 364 + i * 132);
            EResource* res = 0;
            if (!EResourceManager::TryIncrementResource(resId, &res)) {
                // Rollback: DelRef everything already incremented
                for (int j = i - 1; j >= 0; j--) {
                    ((EResource*)(unsigned long)iThis[7 + j])->DelRef();
                    iThis[7 + j] = 0;
                }
                return 0;
            }
            iThis[7 + i] = (int)(uintptr_t)res;
        }
        // Copy back to data
        for (int i = 0; i < count; i++) {
            *(unsigned int*)((char*)data + 364 + i * 132) = (unsigned int)(unsigned long)iThis[7 + i];
        }
    } else {
        unsigned int resId = *(unsigned int*)((char*)data + 364);
        EResource* res = 0;
        if (!EResourceManager::TryIncrementResource(resId, &res)) return 0;
        iThis[7] = (int)(uintptr_t)res;
        *(unsigned int*)((char*)data + 364) = (unsigned int)(unsigned long)res;
    }

    return 1;
}

// 0x8036B6BC
void RParticle::PrepareData() {
    // NOTE: asm-derived, very large function (1596 bytes)
    // Converts particle data from file format to runtime format:
    // 1. Scale various parameters by conversion constants
    // 2. Normalize rotation angles to [0, 2*PI)
    // 3. Compute reciprocals for lifetime/fade parameters
    // 4. Build rotated coordinate frames
    // 5. Copy and transform vertex/color data to runtime layout
    // 6. Pack data into the final pemitterinfo structure (~1420 bytes)
}

// 0x8036BCF8
void RParticle::Load(EFile* file, unsigned int magic) {
    Deallocate();

    // Allocate 1420 bytes aligned to 16
    void* data = EResourceManager::Alloc(1420, 16);
    int* iThis = (int*)this;
    iThis[5] = (int)(uintptr_t)data; // offset 20
    memset(data, 0, 1420);

    EDataHeader header;
    // Read with magic 'PARt' (0x50415274), version 14
    if (header.Read(file, 0x50415274, 14, 14)) {
        // Direct load: read data into allocated buffer
    } else {
        // Legacy load: read old header, convert
        // Read name string, compute data offset
        // memcpy remaining data
    }

    // Parse sub-resources (textures)
    void* loadedData = (void*)(unsigned long)iThis[5];
    int flags = *(int*)((char*)loadedData + 264);

    if (flags & 0x00200000) {
        iThis[6] = 1; // single texture
        // AtoI texture name, AddRef
    } else if (flags & 0x02000000) {
        int texCount = *(int*)((char*)loadedData + 360);
        iThis[6] = texCount;
        // For each texture: AtoI name, AddRef
    } else {
        iThis[6] = 1; // sprite texture
        // AtoI texture name, AddRef
    }
}

// 0x8036BF5C
void RParticle::Refresh(EFile* file) {
    if (!file) return;

    int* iThis = (int*)this;
    void* oldData = (void*)(unsigned long)iThis[5];

    EDataHeader header;
    if (header.Read(file, 0x50415274, 14, 14)) {
        // Direct read into existing buffer
    } else {
        // Legacy format conversion
    }

    // Copy sub-resource references back
    int count = iThis[6];
    for (int i = 0; i < count; i++) {
        *(unsigned int*)((char*)oldData + 364 + i * 132) = (unsigned int)(unsigned long)iThis[7 + i];
    }
}

// 0x8036C230
void RParticle::RegisterType(unsigned short typeId) {
    // ETypeInfo::Register
}

// ============================================================================
// MotiveEffects - Motive score calculation for Sim AI
// ============================================================================

class PiecewiseFn {
public:
    PiecewiseFn();
    void SetMaxPoints(int max);
    void AddPoint(void* point);
};

class MotiveEffects {
public:
    // offset 0: PiecewiseFn* m_curves (array pointer)
    // offset 4: int m_motiveCount (9 motives)
    // offset 8-188: PiecewiseFn array (9 entries, 20 bytes each)
    // offset 188: cXPerson* m_person
    // offset 192: int m_personality

    MotiveEffects(cXPerson* person);
    float GetCurrentScore();
    float GetInteractionScore(ITreeTableEntry* entry);
};

// 0x800C2F34
MotiveEffects::MotiveEffects(cXPerson* person) {
    int* iThis = (int*)this;
    iThis[1] = 9; // 9 motives
    iThis[0] = (int)(uintptr_t)((char*)this + 8); // curves array

    // Initialize 9 PiecewiseFn objects
    char* curves = (char*)this + 8;
    for (int i = 8; i >= 0; i--) {
        PiecewiseFn* fn = (PiecewiseFn*)(curves + i * 20);
        // PiecewiseFn::PiecewiseFn()
        *(int*)((char*)fn + 16) = -1; // motive index = -1
    }

    iThis[47] = (int)(uintptr_t)person; // offset 188

    // Get personality data from person
    // Set motive indices and initial curve points
    // For each motive: SetMaxPoints(4), AddPoint with two initial points
}

// 0x800C3058
float MotiveEffects::GetCurrentScore() {
    int* iThis = (int*)this;
    int motiveCount = iThis[1];
    int* curves = (int*)(unsigned long)iThis[0];

    float totalScore = 0.0f;
    // For each active motive curve:
    //   Look up current motive value from person
    //   Evaluate piecewise function at that value
    //   Accumulate score
    // Return totalScore / motiveCount
    return totalScore / (float)motiveCount;
}

// 0x800C31AC
float MotiveEffects::GetInteractionScore(ITreeTableEntry* entry) {
    if (!entry) return 0.0f;

    int* iThis = (int*)this;
    float totalScore = 0.0f;

    // For each motive:
    //   Get the interaction's effect on this motive from the tree table entry
    //   Compute: deltaScore = currentValue + motiveChange
    //   Evaluate curve at deltaScore
    //   Weight by interaction priority and motive weight
    //   Accumulate
    // Return totalScore / motiveCount
    int motiveCount = iThis[1];
    return totalScore / (float)motiveCount;
}

// ============================================================================
// FadeSquare - Square screen fade effect for transitions
// ============================================================================

class FadeSquare {
public:
    // offset 0-3: fade state pointers
    // offset 12: ERModel* m_model
    // offset 16: float m_fadeTimer
    // offset 20: int m_isDrawing
    // offset 24: int m_fadeCallback

    FadeSquare();
    ~FadeSquare();
    void Update(float dt);
    void Draw(ERC* rc, EVec3& position);
    void StopDraw();
};

// 0x8021CE00
FadeSquare::FadeSquare() {
    // AddRefAsync for the fade model resource
    int* iThis = (int*)this;
    EResourceManager::AddRefAsync(0x969A60EA); // model hash (async, no return value)
    StopDraw();
}

// 0x8021CE4C
FadeSquare::~FadeSquare() {
    int* iThis = (int*)this;
    if (iThis[3]) { // offset 12
        // EResource::DelRef
    } else {
        // EResourceManager::DelRefAsync
    }
}

// 0x8021CF08
void FadeSquare::Update(float dt) {
    int* iThis = (int*)this;
    float* fThis = (float*)this;

    if (!iThis[3]) { // offset 12 - model not loaded
        iThis[3] = (int)(uintptr_t)EResourceManager::GetRef(0x969A60EA);
    }

    if (iThis[5]) { // offset 20 - isDrawing
        fThis[4] -= dt; // offset 16 - fadeTimer
        if (iThis[6] && fThis[4] <= 0.0f) { // offset 24 - fadeCallback
            iThis[6] = 0;
            fThis[4] += 1.0f; // add small offset
        }
    }
}

// 0x8021CFCC
void FadeSquare::Draw(ERC* rc, EVec3& position) {
    int* iThis = (int*)this;
    if (!iThis[3]) return; // no model

    // Get camera position and compute view direction
    // Normalize view direction
    // Scale position by global scale factor
    // Build transform matrix: Id -> PostTranslate(position)
    // Apply fade scale based on timer and fade type
    // Set fog parameters on RC
    // Set world transform on RC
    // ERModel::Draw(rc)
}

// ============================================================================
// LineFade - Line-based fade volume for wall/object fading
// ============================================================================

class LineFade {
public:
    // offset 0-11: EVec3 start point
    // offset 12-23: EVec3 end point
    // offset 24-35: EVec3 direction
    // offset 36-47: EVec3 reciprocal direction
    // offset 48-59: EVec3 far point

    void Setup(EVec3& start, EVec3& end);
    int IsLineIntersected(EBound3& bounds) const;
};

// 0x80309E08
void LineFade::Setup(EVec3& start, EVec3& end) {
    float* fThis = (float*)this;

    // Store start and end points
    fThis[0] = start.x; fThis[1] = start.y; fThis[2] = start.z;
    fThis[3] = end.x;   fThis[4] = end.y;   fThis[5] = end.z;
    fThis[12] = end.x;  fThis[13] = end.y;  fThis[14] = end.z;

    // Compute direction = end - start
    float dx = end.x - start.x;
    float dy = end.y - start.y;
    float dz = end.z - start.z;
    fThis[6] = dx; fThis[7] = dy; fThis[8] = dz;

    // Compute reciprocal direction (1/dir for each axis)
    float epsilon = 0.0001f; // small threshold
    for (int i = 0; i < 3; i++) {
        float d = fThis[6 + i];
        if (d > epsilon || d < -epsilon) {
            fThis[9 + i] = 1.0f / d;
        } else {
            fThis[9 + i] = 100000.0f; // large number for near-zero
        }
    }

    // If far point hasn't been set (all zeros), initialize defaults
    if (fThis[15] == 0) {
        fThis[9] = 100000.0f;
        fThis[10] = 100000.0f;
        fThis[11] = 100000.0f;
        fThis[13] = 1.0f; // default near
        fThis[12] = 1.0f;
    }
}

// 0x80309F3C
int LineFade::IsLineIntersected(EBound3& bounds) const {
    // Slab-based ray-AABB intersection test
    // Tests all 3 axes using the reciprocal direction
    // For each axis: compute entry/exit t-values
    //   Check against perpendicular axes for valid intersection
    // Returns 1 if ray intersects the AABB, 0 otherwise
    // NOTE: asm-derived, complex slab intersection with modular arithmetic for axis cycling
    return 0;
}

// ============================================================================
// PyramidFade - Pyramid-shaped fade volume
// ============================================================================

class ECullPlane {
public:
    void SetPlane(EVec4& plane);
};

class PyramidFade {
public:
    // offset 0-3: int lastPrimitive[2]
    // offset 8-128: ECullPlane planes[5] (24 bytes each)
    // offset 128-136: EVec3 center
    // offset 136-152: depth data
    // offset 152-156: depth indices
    // offset 156: int hasDepth
    // offset 160: int hasAdditionalPlanes
    // offset 172: int dirtyFlag

    PyramidFade();
    void Setup(EVec3& apex, EVec3* corners);
    void DeriveDepthData();
    int IsOutsideFadeVolume(void* primitive, EBound3& bounds) const;
};

// 0x80309388
PyramidFade::PyramidFade() {
    // Initialize 5 cull planes with zero vectors
    EVec4 zeroPlane = {0.0f, 0.0f, 0.0f, 0.0f};
    ECullPlane* planes = (ECullPlane*)((char*)this + 8);
    for (int i = 0; i < 5; i++) {
        planes[i].SetPlane(zeroPlane);
    }

    int* iThis = (int*)this;
    iThis[40] = 1;  // offset 160 = hasAdditionalPlanes
    iThis[43] = 0;  // offset 172 = dirtyFlag
    iThis[39] = 1;  // offset 156 = hasDepth
    iThis[0] = 0;   // offset 0
    iThis[1] = 0;   // offset 4
}

// 0x80309480
void PyramidFade::Setup(EVec3& apex, EVec3* corners) {
    // NOTE: asm-derived, 1260 bytes - very complex geometry setup
    // For each of the 4 pyramid faces:
    //   1. Compute edge vectors from apex to corners
    //   2. Cross product to get face normal
    //   3. Normalize the normal
    //   4. Compute plane distance from apex
    //   5. Set the ECullPlane with (normal, distance)
    // Then for the base:
    //   1. Compute base plane from corners
    //   2. Set the 5th cull plane
    // Compute center point as midpoint of corners
    // DeriveDepthData()
}

// 0x8030996C
void PyramidFade::DeriveDepthData() {
    // Compute depth attenuation data for each cull plane pair
    // For each plane: determine which side the center is on
    // Store depth indices and scaled distance values
    // Used for smooth fade-out near pyramid boundaries
}

// 0x80309AA0
int PyramidFade::IsOutsideFadeVolume(void* primitive, EBound3& bounds) const {
    // NOTE: asm-derived, 824 bytes - complex culling test
    // Tests bounding box against all pyramid planes
    // First checks the two primary planes (top/bottom)
    // If hasAdditionalPlanes: also checks depth planes and center bounds
    // If not: checks remaining side planes
    // Returns 1 if outside (should be faded), 0 if inside
    return 0;
}

// ============================================================================
// TrapezoidFade - Trapezoidal fade volume for wall/object fading
// ============================================================================

class TrapezoidFade {
public:
    // offset 0-11: EVec3 near point
    // offset 12-23: EVec3 far point (direction to camera)
    // offset 24-35: EVec3 second reference point
    // offset 36-47: EVec3 stored near point
    // offset 48-68: float fade parameters
    // offset 72-88: float trapezoid geometry
    // offset 88-100: float alpha parameters
    // offset 104: int mode
    // offset 108: int planeCount
    // offset 112: int isActive
    // offset 116: int isDirty
    // offset 120-200: ECullPlane-like data (plane normals and distances)

    void Setup();
    float CalcAlpha(EBound3& bounds);
};

// 0x80308344
void TrapezoidFade::Setup() {
    int* iThis = (int*)this;
    if (iThis[29] == 0) return; // offset 116 = isDirty, skip if clean

    // NOTE: asm-derived, 3752 bytes - extremely complex geometry setup
    // Copy near point to stored near point
    // Handle mode 0 (simple) vs mode != 0 (complex with extra planes)
    //
    // For simple mode:
    //   1. Compute direction from stored point to second reference
    //   2. Normalize length, store reciprocal
    //   3. Compute fade extents from inner/outer distances
    //   4. Build 2 side planes from cross products
    //   5. PSVECDotProduct for plane distances
    //
    // For complex mode:
    //   1. Normalize the base direction vector
    //   2. Build 4+ fade planes using cross products
    //   3. Each plane gets PSVECNormalize and PSVECDotProduct
    //   4. Store plane normals and distances in the plane array
    //   5. Supports up to 6 planes for the full trapezoidal volume

    iThis[29] = 0; // clear dirty flag
}

// 0x803091EC
float TrapezoidFade::CalcAlpha(EBound3& bounds) {
    int* iThis = (int*)this;

    if (!iThis[28]) return 1.0f; // offset 112 = isActive

    if (iThis[29]) { // offset 116 = isDirty
        Setup();
    }

    // Compute center of bounds
    float cx = (bounds.min[0] + bounds.max[0]) * 0.5f;
    float cy = (bounds.min[1] + bounds.max[1]) * 0.5f;
    float cz = (bounds.min[2] + bounds.max[2]) * 0.5f;

    float* fThis = (float*)this;

    // Handle simple vs complex mode
    if (iThis[26] == 0) { // offset 104 = mode
        // Adjust center by subtracting stored near point
    }

    // For each fade plane:
    //   Compute dot product of center with plane normal
    //   Add plane distance
    //   Subtract base offset
    //   Track maximum penetration depth
    float maxDepth = 0.0f;
    int planeCount = iThis[27]; // offset 108
    for (int i = 0; i < planeCount; i++) {
        // PSVECDotProduct with plane normal
        // Accumulate maximum
    }

    // Apply fade curve: alpha = maxDepth * scale
    float alpha = maxDepth * fThis[22]; // offset 88 = scale
    if (alpha >= fThis[23]) { // offset 92 = max threshold
        return 1.0f; // fully visible
    }
    if (alpha < fThis[24]) { // offset 96 = min threshold
        return fThis[25]; // offset 100 = min alpha
    }
    return alpha;
}

// ============================================================================
// RainEffect - Rain particle system
// ============================================================================

class SAnimator2 {
public:
    static void SetIsRaining(bool raining);
};

class CTilePt {
public:
    CTilePt(int x, int y, int level);
    ~CTilePt();
};

class RainEffect {
public:
    // offset 0: EResource* m_rainResource
    // offset 4: Emitter* m_rainEmitter
    // offset 8: int m_isIndoors
    // offset 12: EResource* m_splashResource
    // offset 16: Emitter* m_splashEmitter
    // offset 20: float m_fadeInTime
    // offset 24: float m_activeTime
    // offset 28: float m_fadeOutTime
    // offset 32: float m_rainSpeed
    // offset 36: float m_rainScale
    // offset 40: float m_splashSpeed
    // offset 44: float m_splashScale
    // offset 48: float m_timer
    // offset 52: int m_rainType

    RainEffect(float fadeIn, float active, float fadeOut, int rainType);
    ~RainEffect();
    int UpdateParticleRainSplashLoad();
    int UpdateParticleRainLoad();
    void RainModeUpdate(float dt);
};

// 0x8007A2D8
RainEffect::RainEffect(float fadeIn, float active, float fadeOut, int rainType) {
    float* fThis = (float*)this;
    int* iThis = (int*)this;

    fThis[5] = fadeIn;   // offset 20
    fThis[7] = fadeOut;  // offset 28
    fThis[6] = active;   // offset 24
    fThis[12] = 0.0f;   // offset 48 = timer
    iThis[2] = 0;        // offset 8
    iThis[13] = rainType; // offset 52
    iThis[4] = 0;        // offset 16
    iThis[3] = 0;        // offset 12
    iThis[1] = 0;        // offset 4
    iThis[0] = 0;        // offset 0

    // AddRefAsync for rain particle resource (lookup by type)
    // AddRefAsync for splash particle resource
    UpdateParticleRainLoad();
    SAnimator2::SetIsRaining(true);
}

// 0x8007A380
int RainEffect::UpdateParticleRainSplashLoad() {
    int* iThis = (int*)this;
    if (iThis[3]) return 1; // offset 12, already loaded

    // GetRef for splash resource
    EResource* res = EResourceManager::GetRef(0); // lookup by rain type
    iThis[3] = (int)(uintptr_t)res;
    if (!res) return 0;

    // Create EMat4::Id for splash position
    // Create EmitterSpr3d with camera follow XY
    // If failed, destroy and return
    // Register emitter, set state, set matrix
    // Store splash emitter speed/scale from pemitter data
    return 1;
}

// 0x8007A510
int RainEffect::UpdateParticleRainLoad() {
    int* iThis = (int*)this;
    if (iThis[0]) return 1; // offset 0, already loaded

    // GetRef for rain resource
    EResource* res = EResourceManager::GetRef(0); // lookup by rain type
    iThis[0] = (int)(uintptr_t)res;
    if (!res) return 0;

    // Create EmitterSpr3d with camera follow XYZ
    // RotateX for rain angle
    // Register, set state, set matrix
    // Store rain speed/scale from constants
    return 1;
}

// 0x8007A64C
RainEffect::~RainEffect() {
    SAnimator2::SetIsRaining(false);

    int* iThis = (int*)this;
    Emitter* rainEmitter = (Emitter*)(unsigned long)iThis[1]; // offset 4

    if (rainEmitter) {
        // UnReg from appropriate particle system
        // Destroy rain emitter
    }

    // DelRefAsync for rain resources
    Emitter* splashEmitter = (Emitter*)(unsigned long)iThis[4]; // offset 16
    if (splashEmitter) {
        // UnReg splash emitter
        // Destroy splash emitter
    }

    // DelRefAsync for splash resources
}

// 0x8007A76C
void RainEffect::RainModeUpdate(float dt) {
    // NOTE: asm-derived, 928 bytes - complex rain behavior update
    // Check if outdoor area exists
    // Update rain particle loads
    // Advance timer

    float* fThis = (float*)this;
    int* iThis = (int*)this;

    fThis[12] += dt; // timer

    // Get rain emitter data
    // Get splash emitter data

    float totalDuration = fThis[5] + fThis[6] + fThis[7]; // fadeIn + active + fadeOut
    float timer = fThis[12];

    if (timer > totalDuration) {
        // Rain ended - disable
        SAnimator2::SetIsRaining(false);
        // SetState(8, 1) on both emitters
        return;
    }

    if (timer < fThis[5]) {
        // Fade in phase
        float ratio = timer / fThis[5];
        // Scale emitter parameters by ratio
    } else if (timer > fThis[5] + fThis[7]) {
        // Fade out phase
        float fadeProgress = (timer - fThis[5] - fThis[7]) / fThis[6];
        float ratio = 1.0f - fadeProgress;
        // Scale emitter parameters by ratio
    } else {
        // Full intensity phase
        // Set emitter parameters to maximum
    }

    // Check tile-based indoor/outdoor status
    // Switch emitter between indoor and outdoor particle systems
}
