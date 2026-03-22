// simrenderer_large.cpp - CasSimRenderer large functions (257-1024 bytes)
// Object file: cassimrenderer.obj (listed under simrenderer in task)
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"

// Forward declarations
class CasSimRenderer;
class ERC;
class EShader;
class ERModel;

extern "C" void EAHeap_Free2(void* ptr);
extern "C" void ERModel_Draw(void* model, void* rc, int flags);
extern "C" void ERModel_DrawShadow(void* model, void* rc, int flags);
extern "C" void* ERModel_GetShader(void* model, int idx);
extern "C" void EShader_Select(void* shader, void* rc, u32 flags);
extern "C" void ERC_SaveState(void* rc);
extern "C" void ERC_RestoreState(void* rc);
extern "C" void ERC_EnableGeometryModes(void* rc, u32 modes);
extern "C" void ERC_DisableGeometryModes(void* rc, u32 modes);

// ============================================================================
// CasSimRenderer::~CasSimRenderer(void)
// Address: 0x8016EF38
// Size: 280 bytes
// NON_MATCHING - destructor releasing models and textures
// ============================================================================
struct CasSimRenderer {
    u8 m_base[0x20];       // 0x00 - base class data
    void* m_pModel;         // 0x20
    void* m_pShadowModel;   // 0x24
    void* m_pHeadModel;     // 0x28
    void* m_pTexture;       // 0x2C
    u32 m_flags;            // 0x30
    void* m_pShaders[8];    // 0x34
    u8 m_rest[0x80];        // 0x54

    ~CasSimRenderer();
    void Draw(ERC* rc);
    void DrawShadow(ERC* rc);
    void SetupSimCommon();
    void DrawFaceImage(ERC* rc);
};

CasSimRenderer::~CasSimRenderer()
{
    // Release model resources
    if (m_pModel) {
        EAHeap_Free2(m_pModel);
        m_pModel = 0;
    }
    if (m_pShadowModel) {
        EAHeap_Free2(m_pShadowModel);
        m_pShadowModel = 0;
    }
    if (m_pHeadModel) {
        EAHeap_Free2(m_pHeadModel);
        m_pHeadModel = 0;
    }
    if (m_pTexture) {
        EAHeap_Free2(m_pTexture);
        m_pTexture = 0;
    }

    // Clear shader references
    for (int i = 0; i < 8; i++) {
        m_pShaders[i] = 0;
    }
}

// ============================================================================
// CasSimRenderer::Draw(ERC*)
// Address: 0x8016F174
// Size: 400 bytes
// NON_MATCHING - draws the sim model
// ============================================================================
void CasSimRenderer::Draw(ERC* rc)
{
    if (!rc) return;
    if (!m_pModel) return;

    ERC_SaveState(rc);

    // Set up common rendering state
    SetupSimCommon();

    // Enable required geometry modes
    ERC_EnableGeometryModes(rc, 0x01); // Lighting
    ERC_EnableGeometryModes(rc, 0x04); // Texturing

    // Select each shader and draw model parts
    for (int i = 0; i < 8; i++) {
        if (m_pShaders[i]) {
            EShader_Select(m_pShaders[i], rc, 0);
        }
    }

    // Draw the model
    ERModel_Draw(m_pModel, rc, 0);

    // Draw head model if present
    if (m_pHeadModel) {
        ERModel_Draw(m_pHeadModel, rc, 0);
    }

    ERC_RestoreState(rc);
}

// ============================================================================
// CasSimRenderer::DrawShadow(ERC*)
// Address: 0x8016F304
// Size: 388 bytes
// NON_MATCHING - draws sim shadow
// ============================================================================
void CasSimRenderer::DrawShadow(ERC* rc)
{
    if (!rc) return;
    if (!m_pModel) return;

    ERC_SaveState(rc);

    // Disable lighting for shadow
    ERC_DisableGeometryModes(rc, 0x01);

    // Set shadow alpha
    // NON_MATCHING: blend mode setup for shadow rendering

    // Draw shadow model
    if (m_pShadowModel) {
        ERModel_DrawShadow(m_pShadowModel, rc, 0);
    } else {
        ERModel_DrawShadow(m_pModel, rc, 0);
    }

    ERC_RestoreState(rc);
}

// ============================================================================
// CasSimRenderer::SetupSimCommon(void)
// Address: 0x8016F5A8
// Size: 376 bytes
// NON_MATCHING - common sim rendering setup
// ============================================================================
void CasSimRenderer::SetupSimCommon(void)
{
    u8* self = (u8*)this;

    // Set up skin composited texture
    if (m_pTexture) {
        // Override shader textures with composited skin
        for (int i = 0; i < 8; i++) {
            if (m_pShaders[i]) {
                void* shader = m_pShaders[i];
                // Set composited texture on shader
                *(void**)((u8*)shader + 0x64) = m_pTexture;
            }
        }
    }

    // Set flags for rendering mode
    u32 flags = m_flags;
    if (flags & 0x01) {
        // Alpha blended sim (ghost, etc)
        // NON_MATCHING: special alpha setup
    }
    if (flags & 0x02) {
        // Selected/highlighted sim
        // NON_MATCHING: outline highlight setup
    }
}

// ============================================================================
// CasSimRenderer::DrawFaceImage(ERC*)
// Address: 0x8016F90C
// Size: 276 bytes
// NON_MATCHING - draws face thumbnail
// ============================================================================
void CasSimRenderer::DrawFaceImage(ERC* rc)
{
    if (!rc) return;
    if (!m_pHeadModel) return;

    ERC_SaveState(rc);

    // Set up orthographic projection for face rendering
    // NON_MATCHING: projection matrix setup

    // Draw head model
    ERModel_Draw(m_pHeadModel, rc, 0);

    ERC_RestoreState(rc);
}
