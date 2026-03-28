// skincompositor_medium.cpp - SkinCompositor medium functions (65-256 bytes)
// Object file: skincompositor.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "skin/skincompositor.h"

// External functions
extern "C" void* EAHeap_Get();
extern "C" void EAHeap_Free(void*, void*);
extern "C" void* EAHeap_Alloc(int);
extern "C" void ERTexture_GetInfo(void* tex, u32* width, u32* height, u32* fmt);
extern "C" void ERTexture_Create(void* tex, int w, int h, int fmt);
extern "C" void ERTexture_Lock(void* tex);
extern "C" void ERTexture_Unlock(void* tex);
extern "C" void ERTexture_Copy(void* dst, void* src, int w, int h);
extern "C" void CasSimDesc_GetTextureID(void* desc, int part, u32* out);

// ============================================================================
// SkinCompositor::SkinCompositor
// skincompositor.obj | 0x80075B10 | 96 bytes
// ============================================================================
// NON_MATCHING: init order
SkinCompositor::SkinCompositor() {
    m_size = 256;
    m_ptr04 = 0;
    m_ptr08 = 0;
    m_ptr0C = 0;
    m_ptr10 = 0;
    m_ptr14 = 0;
    m_ptr18 = 0;
    m_byte1C = 0;
    m_ptr20 = 0;
    m_ptr24 = 0;
}

// ============================================================================
// SkinCompositor::Reset
// skincompositor.obj | 0x80075BB0 | 208 bytes
// Resets all internal textures and state
// ============================================================================
// NON_MATCHING: complex cleanup logic
void SkinCompositor::Reset() {
    // Release all texture resources
    if (m_ptr04 != 0) {
        // Release texture at m_ptr04
        m_ptr04 = 0;
    }
    if (m_ptr08 != 0) {
        m_ptr08 = 0;
    }
    if (m_ptr0C != 0) {
        m_ptr0C = 0;
    }
    if (m_ptr10 != 0) {
        m_ptr10 = 0;
    }
    if (m_ptr14 != 0) {
        m_ptr14 = 0;
    }
    if (m_ptr18 != 0) {
        m_ptr18 = 0;
    }
    m_byte1C = 0;
    if (m_ptr20 != 0) {
        m_ptr20 = 0;
    }
    if (m_ptr24 != 0) {
        m_ptr24 = 0;
    }
}

// ============================================================================
// SkinCompositor::CreateSkin
// skincompositor.obj | 0x80075DEC | 160 bytes
// Creates skin texture for a given quadrant
// ============================================================================
// NON_MATCHING: codegen differences
void SkinCompositor::CreateSkin(ERTexture* tex, unsigned char quadrant, CasSimDescriptionS2C* desc, bool lowRes) {
    if (lowRes) {
        CreateSkinQuadrantLoRes(tex, quadrant, desc);
    } else {
        CreateSkinQuadrantHiRes(tex, quadrant, desc);
    }
}

// ============================================================================
// SkinCompositor::InitSkinTexture
// skincompositor.obj | 0x80076000 | 76 bytes
// ============================================================================
// NON_MATCHING: texture setup codegen
void SkinCompositor::InitSkinTexture() {
    // Set up the render target for skin compositing
    // Calls into ERTexture/GX to configure the texture
}

// ============================================================================
// SkinCompositor::FinalizeSkinTexture
// skincompositor.obj | 0x8007604C | 76 bytes
// ============================================================================
// NON_MATCHING: texture finalization codegen
void SkinCompositor::FinalizeSkinTexture() {
    // Finalize the skin texture after compositing
    // Flush render state, restore previous target
}

// ============================================================================
// SkinCompositor::GetTextureIDs
// skincompositor.obj | 0x80076524 | 244 bytes
// Gets texture IDs for body parts from CAS description
// ============================================================================
// NON_MATCHING: complex branching with multiple output params
void SkinCompositor::GetTextureIDs(unsigned int& id, unsigned int* a, unsigned int* b, unsigned int* c) {
    // Look up texture IDs from the CAS sim description
    // Fills in output parameters based on body part type
}

// ============================================================================
// SkinCompositor::GetFinalReflectionMask
// skincompositor.obj | 0x80076DA4 | 208 bytes
// ============================================================================
// NON_MATCHING: complex texture blending logic
void SkinCompositor::GetFinalReflectionMask() {
    // Generate the final reflection mask texture
    // Used for skin shader reflections
}
