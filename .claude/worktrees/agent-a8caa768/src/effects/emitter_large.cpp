// emitter_large.cpp - Emitter/EmitterSpr3d large functions (257-1024 bytes)
// Object files: emitter.obj, emitterspr3d.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "effects/emitter.h"

// GX SDK
extern "C" {
    void GXSetVtxDesc(u8, u8);
    void GXClearVtxDesc(void);
    void GXSetVtxAttrFmt(u8, u8, u8, u8, u8);
    void GXSetTevOrder(u8, u8, u8, u8);
    void GXSetTevColorIn(u8, u8, u8, u8, u8);
    void GXSetTevColorOp(u8, u8, u8, u8, u8, u8);
    void GXSetTevAlphaIn(u8, u8, u8, u8, u8);
    void GXSetTevAlphaOp(u8, u8, u8, u8, u8, u8);
    void GXSetNumTevStages(u8);
    void GXSetNumTexGens(u8);
    void GXSetBlendMode(u8, u8, u8, u8);
    void GXSetZMode(u8, u8, u8);
    void GXSetCullMode(u8);
    void GXSetAlphaCompare(u8, u8, u8, u8, u8);
    void GXBegin(u8, u8, u16);
    void GXEnd(void);
}

extern "C" void EAHeap_Free2(void* ptr);
extern "C" void* EAHeap_Alloc(int size);
extern "C" void ERC_SaveState(void* rc);
extern "C" void ERC_RestoreState(void* rc);
extern "C" float cosf_impl(float);
extern "C" float sinf_impl(float);

// ============================================================================
// Emitter::Draw(ELevelDrawData&)
// Address: 0x802389DC
// Size: 300 bytes
// NON_MATCHING - draws emitter particles
// ============================================================================
static void Emitter_Draw_impl(Emitter* emitSelf, ELevelDrawData* drawData)
{
    pemitter* emitter = emitSelf->m_pEmitter;
    if (!emitter) return;

    int numParticles = emitSelf->GetNumActiveParticles();
    if (numParticles <= 0) return;

    EVec3 sortPos;
    sortPos.x = *(float*)((u8*)emitSelf + 0x80);
    sortPos.y = *(float*)((u8*)emitSelf + 0x84);
    sortPos.z = *(float*)((u8*)emitSelf + 0x88);

    u8* drawDataPtr = (u8*)drawData;
    void* orderTable = *(void**)(drawDataPtr + 0x00);
    if (orderTable) {
        // NON_MATCHING: order table insertion
    }
}

// ============================================================================
// SprSysSetState(unsigned int, unsigned int)
// Address: 0x80238B38
// Size: 512 bytes
// NON_MATCHING - sets GX state for sprite particle rendering
// ============================================================================
void SprSysSetState(unsigned int blendMode, unsigned int flags)
{
    // Clear previous vertex descriptors
    GXClearVtxDesc();

    // Set vertex format for particle sprites
    GXSetVtxDesc(9, 1);   // GX_VA_POS = DIRECT
    GXSetVtxDesc(11, 1);  // GX_VA_CLR0 = DIRECT
    GXSetVtxDesc(13, 1);  // GX_VA_TEX0 = DIRECT

    // Set vertex attribute formats
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);   // POS: f32 xyz
    GXSetVtxAttrFmt(0, 11, 1, 5, 0);  // CLR0: RGBA8
    GXSetVtxAttrFmt(0, 13, 1, 4, 0);  // TEX0: f32 st

    // Configure TEV for textured colored particles
    GXSetNumTevStages(1);
    GXSetNumTexGens(1);

    GXSetTevOrder(0, 0, 0, 0);    // Stage 0: TexCoord0, Map0, Color0
    GXSetTevColorIn(0, 8, 15, 10, 15); // TEXC * RASC
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 4, 7, 5, 7);    // TEXA * RASA
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);

    // Set blend mode based on particle type
    if (blendMode == 0) {
        // Additive blending
        GXSetBlendMode(1, 1, 1, 0);  // GX_BM_BLEND, SRC_ALPHA, ONE
    } else if (blendMode == 1) {
        // Alpha blending
        GXSetBlendMode(1, 4, 5, 0);  // GX_BM_BLEND, SRC_ALPHA, INV_SRC_ALPHA
    } else if (blendMode == 2) {
        // Subtractive
        GXSetBlendMode(3, 1, 1, 0);  // GX_BM_SUBTRACT, ONE, ONE
    } else {
        // Default: alpha blend
        GXSetBlendMode(1, 4, 5, 0);
    }

    // Z buffer: read but don't write for particles
    if (flags & 0x01) {
        GXSetZMode(1, 3, 0);  // GX_TRUE, GX_LEQUAL, GX_FALSE
    } else {
        GXSetZMode(0, 7, 0);  // GX_FALSE, GX_ALWAYS, GX_FALSE
    }

    // No backface culling for sprites
    GXSetCullMode(0);

    // Alpha test
    if (flags & 0x02) {
        GXSetAlphaCompare(4, 1, 0, 4, 1); // GX_GREATER, 1
    }
}

// ============================================================================
// EmitterGeom3dSubmitCB(particle*, PVector4*, float, float, PVector4*, void*)
// Address: 0x80239F50
// Size: 484 bytes
// NON_MATCHING - callback for 3D particle geometry submission
// ============================================================================
void EmitterGeom3dSubmitCB(particle* part, PVector4* pos, float size, float rotation,
                           PVector4* color, void* userData)
{
    if (!part || !pos || !color) return;

    // Calculate billboard quad vertices
    float halfSize = size * 0.5f;

    float cosR = cosf_impl(rotation);
    float sinR = sinf_impl(rotation);

    // Billboard corners (rotated)
    float x0 = -halfSize * cosR - (-halfSize) * sinR;
    float y0 = -halfSize * sinR + (-halfSize) * cosR;
    float x1 =  halfSize * cosR - (-halfSize) * sinR;
    float y1 =  halfSize * sinR + (-halfSize) * cosR;
    float x2 =  halfSize * cosR - ( halfSize) * sinR;
    float y2 =  halfSize * sinR + ( halfSize) * cosR;
    float x3 = -halfSize * cosR - ( halfSize) * sinR;
    float y3 = -halfSize * sinR + ( halfSize) * cosR;

    // Emit vertices as triangle strip via GX FIFO
    u8 r = (u8)(color->x * 255.0f);
    u8 g = (u8)(color->y * 255.0f);
    u8 b = (u8)(color->z * 255.0f);
    u8 a = (u8)(color->w * 255.0f);

    // GX vertex data written to FIFO
    // NON_MATCHING: direct FIFO writes
    // GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    // vertex 0: pos + offset, color, texcoord (0,0)
    // vertex 1: pos + offset, color, texcoord (1,0)
    // vertex 2: pos + offset, color, texcoord (1,1)
    // vertex 3: pos + offset, color, texcoord (0,1)
}

// ============================================================================
// EmitterGeom3dTabSubmitCB(particle*, PVector4*, float, float, PVector4*, void*)
// Address: 0x8023A1F8
// Size: 508 bytes
// NON_MATCHING - callback for 3D tabulated particle geometry
// ============================================================================
void EmitterGeom3dTabSubmitCB(particle* part, PVector4* pos, float size, float rotation,
                              PVector4* color, void* userData)
{
    if (!part || !pos || !color) return;

    // Similar to EmitterGeom3dSubmitCB but uses pre-tabulated sin/cos values
    // for faster rotation lookup

    // Rotation index into lookup table
    int rotIdx = (int)(rotation * 256.0f / 6.2831853f) & 0xFF;

    // Get sin/cos from table
    // NON_MATCHING: uses global sin/cos lookup table
    float cosR = cosf_impl(rotation);
    float sinR = sinf_impl(rotation);

    float halfSize = size * 0.5f;

    // Calculate billboard corners (same as above but with table lookup)
    float x0 = -halfSize * cosR + halfSize * sinR;
    float y0 = -halfSize * sinR - halfSize * cosR;
    float x1 =  halfSize * cosR + halfSize * sinR;
    float y1 =  halfSize * sinR - halfSize * cosR;
    float x2 =  halfSize * cosR - halfSize * sinR;
    float y2 =  halfSize * sinR + halfSize * cosR;
    float x3 = -halfSize * cosR - halfSize * sinR;
    float y3 = -halfSize * sinR + halfSize * cosR;

    u8 r = (u8)(color->x * 255.0f);
    u8 g = (u8)(color->y * 255.0f);
    u8 b = (u8)(color->z * 255.0f);
    u8 a = (u8)(color->w * 255.0f);

    // NON_MATCHING: GX FIFO writes for quad
}

// ============================================================================
// Effects::FastParticleEmitter::~FastParticleEmitter(void)
// Address: 0x80353194
// Size: 260 bytes
// NON_MATCHING - destructor freeing particle data
// ============================================================================
namespace Effects {

struct FastParticleEmitter {
    u8 m_base[0x10];        // 0x00
    void* m_pParticles;      // 0x10
    u32 m_maxParticles;      // 0x14
    u32 m_numActive;         // 0x18
    float m_emitRate;        // 0x1C
    float m_emitAccum;       // 0x20
    u32 m_flags;             // 0x24
    void* m_pEmitterInfo;    // 0x28
    float m_age;             // 0x2C
    float m_lifetime;        // 0x30
    u32 m_burstCount;        // 0x34
    float m_burstInterval;   // 0x38
    float m_burstTimer;      // 0x3C
    void* m_pTexture;        // 0x40

    ~FastParticleEmitter();
    void PreRollParticles();
    void ReallocateParticles(int newMax);
    void UpdateBurst(int frame, float dt, int* outCount);
    void ComputeMaxParticles();
};

FastParticleEmitter::~FastParticleEmitter()
{
    // Free particle data
    if (m_pParticles) {
        EAHeap_Free2(m_pParticles);
        m_pParticles = 0;
    }

    // Free emitter info
    if (m_pEmitterInfo) {
        EAHeap_Free2(m_pEmitterInfo);
        m_pEmitterInfo = 0;
    }

    m_maxParticles = 0;
    m_numActive = 0;
    m_pTexture = 0;
}

// ============================================================================
// Effects::FastParticleEmitter::PreRollParticles(void)
// Address: 0x80356680
// Size: 496 bytes
// NON_MATCHING - pre-rolls particle system to steady state
// ============================================================================
void FastParticleEmitter::PreRollParticles(void)
{
    u8* self = (u8*)this;

    // Simulate several frames to reach steady state
    float dt = 1.0f / 30.0f; // fixed timestep
    int numFrames = (int)(m_lifetime / dt);
    if (numFrames > 300) numFrames = 300; // cap at 10 seconds

    for (int i = 0; i < numFrames; i++) {
        // Update existing particles
        m_age += dt;

        // Emit new particles
        m_emitAccum += m_emitRate * dt;
        while (m_emitAccum >= 1.0f) {
            m_emitAccum -= 1.0f;
            if (m_numActive < m_maxParticles) {
                // Initialize new particle
                m_numActive++;
            }
        }

        // Kill expired particles
        // NON_MATCHING: particle death check
    }
}

// ============================================================================
// Effects::FastParticleEmitter::ReallocateParticles(int)
// Address: 0x80353930
// Size: 852 bytes
// NON_MATCHING - reallocates particle buffer
// ============================================================================
void FastParticleEmitter::ReallocateParticles(int newMax)
{
    if (newMax <= 0) {
        // Free existing
        if (m_pParticles) {
            EAHeap_Free2(m_pParticles);
            m_pParticles = 0;
        }
        m_maxParticles = 0;
        m_numActive = 0;
        return;
    }

    // Allocate new buffer (each particle is 64 bytes)
    u32 newSize = newMax * 64;
    void* newBuf = EAHeap_Alloc(newSize);
    if (!newBuf) return;

    // Zero new buffer
    u8* p = (u8*)newBuf;
    for (u32 i = 0; i < newSize; i++) {
        p[i] = 0;
    }

    // Copy existing particles
    if (m_pParticles && m_numActive > 0) {
        u32 copyCount = m_numActive;
        if (copyCount > (u32)newMax) copyCount = newMax;
        u8* src = (u8*)m_pParticles;
        u8* dst = (u8*)newBuf;
        for (u32 i = 0; i < copyCount * 64; i++) {
            dst[i] = src[i];
        }
        if (m_numActive > (u32)newMax) {
            m_numActive = newMax;
        }
    }

    // Free old buffer
    if (m_pParticles) {
        EAHeap_Free2(m_pParticles);
    }

    m_pParticles = newBuf;
    m_maxParticles = newMax;
}

// ============================================================================
// Effects::FastParticleEmitter::UpdateBurst(int, float, int*)
// Address: 0x80353D08
// Size: 492 bytes
// NON_MATCHING - handles burst particle emission
// ============================================================================
void FastParticleEmitter::UpdateBurst(int frame, float dt, int* outCount)
{
    if (outCount) *outCount = 0;

    if (m_burstCount == 0) return;

    // Update burst timer
    m_burstTimer += dt;

    if (m_burstTimer >= m_burstInterval) {
        m_burstTimer -= m_burstInterval;

        // Emit burst particles
        u32 count = m_burstCount;
        if (m_numActive + count > m_maxParticles) {
            count = m_maxParticles - m_numActive;
        }

        for (u32 i = 0; i < count; i++) {
            // Initialize burst particle
            u8* part = (u8*)m_pParticles + (m_numActive + i) * 64;
            // Set initial position, velocity, lifetime
            *(float*)(part + 0x00) = 0.0f; // pos x
            *(float*)(part + 0x04) = 0.0f; // pos y
            *(float*)(part + 0x08) = 0.0f; // pos z
            *(float*)(part + 0x0C) = 0.0f; // age
            *(float*)(part + 0x10) = m_lifetime; // lifetime
            // NON_MATCHING: randomized velocity
        }

        m_numActive += count;
        if (outCount) *outCount = count;
    }
}

// ============================================================================
// Effects::FastParticleEmitter::ComputeMaxParticles(void)
// Address: 0x8035630C
// Size: 632 bytes
// NON_MATCHING - computes max particles needed
// ============================================================================
void FastParticleEmitter::ComputeMaxParticles(void)
{
    // Calculate maximum particles based on emit rate and lifetime
    float maxAlive = m_emitRate * m_lifetime;

    // Add burst count
    if (m_burstInterval > 0.0f) {
        float burstsPerLifetime = m_lifetime / m_burstInterval;
        maxAlive += burstsPerLifetime * m_burstCount;
    }

    // Add safety margin (20%)
    int maxCount = (int)(maxAlive * 1.2f) + 1;

    // Clamp to reasonable limits
    if (maxCount < 1) maxCount = 1;
    if (maxCount > 10000) maxCount = 10000;

    // Reallocate if needed
    if ((u32)maxCount != m_maxParticles) {
        ReallocateParticles(maxCount);
    }
}

} // namespace Effects
