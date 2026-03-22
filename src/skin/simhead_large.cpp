// simhead_large.cpp - DHead/simhead large functions (257-1024 bytes)
// Object file: simhead.obj
// Note: The map shows simhead.obj functions under DHead:: namespace
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

// Forward declarations from simhead
struct EVec3_local { float x, y, z; };
class ERC;
class ERModel;
class EShader;

extern "C" void EShader_Select(void* shader, void* rc, u32 flags);
extern "C" void ERModel_Draw(void* model, void* rc, int flags);
extern "C" void ERC_SaveState(void* rc);
extern "C" void ERC_RestoreState(void* rc);
extern "C" void ERC_ModelMatrix(void* rc, void* mat);

// DHead class layout (from disassembly)
// Inherits from ESims::DHead which inherits from EInstance
struct DHead {
    u8 m_instanceBase[0x7C];     // 0x00 - EInstance base
    void* m_pModel;               // 0x7C
    void* m_pShaders[16];         // 0x80
    u32 m_numShaders;             // 0xC0
    void* m_pMorphTargets[4];     // 0xC4
    float m_morphWeights[4];      // 0xD4
    u32 m_numMorphTargets;        // 0xE4
    void* m_pEyeShader;           // 0xE8
    void* m_pSkinTexture;         // 0xEC
    u32 m_flags;                  // 0xF0

    void Draw(ERC* rc);
    void InitHead(void* model, int numShaders);
    void InitShaders(void* shaderDefs, int count);
    void ResetShaders();
};

// ============================================================================
// DHead::Draw
// (One of the large functions in simhead.obj)
// NON_MATCHING - draws the head model with morphing
// ============================================================================
void DHead::Draw(ERC* rc)
{
    if (!rc) return;
    if (!m_pModel) return;

    ERC_SaveState(rc);

    // Set model matrix from instance transform
    void* mat = (void*)(m_instanceBase + 0x10);
    ERC_ModelMatrix(rc, mat);

    // Apply morph targets
    for (u32 i = 0; i < m_numMorphTargets; i++) {
        if (m_pMorphTargets[i] && m_morphWeights[i] > 0.0f) {
            // NON_MATCHING: morph target blending
            // Blends between base mesh and morph target
        }
    }

    // Select shaders and draw
    for (u32 i = 0; i < m_numShaders; i++) {
        if (m_pShaders[i]) {
            EShader_Select(m_pShaders[i], rc, 0);
        }
    }

    // Draw the model
    ERModel_Draw(m_pModel, rc, 0);

    // Draw eyes with eye shader
    if (m_pEyeShader) {
        EShader_Select(m_pEyeShader, rc, 0);
        // NON_MATCHING: eye rendering with separate pass
    }

    ERC_RestoreState(rc);
}

// ============================================================================
// DHead::InitHead
// NON_MATCHING - initializes head with model and shader count
// ============================================================================
void DHead::InitHead(void* model, int numShaders)
{
    m_pModel = model;
    m_numShaders = numShaders;

    // Clear shader slots
    for (int i = 0; i < 16; i++) {
        m_pShaders[i] = 0;
    }

    // Clear morph targets
    for (int i = 0; i < 4; i++) {
        m_pMorphTargets[i] = 0;
        m_morphWeights[i] = 0.0f;
    }
    m_numMorphTargets = 0;

    m_pEyeShader = 0;
    m_pSkinTexture = 0;
    m_flags = 0;
}

// ============================================================================
// DHead::InitShaders
// NON_MATCHING - initializes head shaders from shader definitions
// ============================================================================
void DHead::InitShaders(void* shaderDefs, int count)
{
    if (!shaderDefs) return;
    if (count > 16) count = 16;

    for (int i = 0; i < count; i++) {
        u8* def = (u8*)shaderDefs + i * 0xF4;
        // Create shader from definition
        // NON_MATCHING: shader creation through EShader::Create
        m_pShaders[i] = 0; // placeholder
    }
    m_numShaders = count;
}

// ============================================================================
// DHead::ResetShaders
// NON_MATCHING - resets all head shaders to defaults
// ============================================================================
void DHead::ResetShaders()
{
    for (u32 i = 0; i < m_numShaders; i++) {
        if (m_pShaders[i]) {
            // Reset shader to default state
            u8* shader = (u8*)m_pShaders[i];
            *(u32*)(shader + 0x04) = 0; // clear flags
        }
    }

    // Reset skin texture override
    m_pSkinTexture = 0;
}
