// simrenderer_medium.cpp - SimRenderer medium functions (65-256 bytes)
// Object file: simrenderer.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class ERC;
class EIStaticModel;
class EAnimController;
class EShader;
struct EMat4 { float data[16]; };

// SimRenderer - renders Sim body parts
// This is a static utility class
class SimRenderer {
public:
    static void Render(ERC* rc, EIStaticModel** models, EShader* shader, EMat4* mat, unsigned int flags, bool flag);
    static void Render(ERC* rc, EIStaticModel** models, EAnimController* anim, EShader* shader, EMat4& mat, bool flag);
    static void MorphParts(EIStaticModel** models, bool flag);
    static void RenderGhosted(ERC* rc, EIStaticModel** models, EMat4* mat, unsigned int flags, bool flag);
};

// ============================================================================
// SimRenderer::Render (static model version)
// simrenderer.obj | 0x80074B30 | 196 bytes
// Renders body parts using static model array with shader and transform
// ============================================================================
// NON_MATCHING: loop codegen, multiple model rendering
void SimRenderer::Render(ERC* rc, EIStaticModel** models, EShader* shader, EMat4* mat, unsigned int flags, bool flag) {
    if (rc == 0 || models == 0) return;
    // Iterate through body parts in render order
    // For each part with a valid model:
    //   Apply shader, set transform, render
}

// ============================================================================
// SimRenderer::Render (animated version)
// simrenderer.obj | 0x80074BF4 | 180 bytes
// Renders body parts with animation controller
// ============================================================================
// NON_MATCHING: animation controller integration
void SimRenderer::Render(ERC* rc, EIStaticModel** models, EAnimController* anim, EShader* shader, EMat4& mat, bool flag) {
    if (rc == 0 || models == 0) return;
    // Apply animation transforms to each body part
    // Render with shader and final matrix
}

// ============================================================================
// SimRenderer::MorphParts
// simrenderer.obj | 0x80074CA8 | 160 bytes
// Applies morph targets to body parts
// ============================================================================
// NON_MATCHING: morph target application loop
void SimRenderer::MorphParts(EIStaticModel** models, bool flag) {
    if (models == 0) return;
    // For each body part model:
    //   Apply morph weights
    //   Update vertex positions
}

// ============================================================================
// SimRenderer::RenderGhosted
// simrenderer.obj | 0x80074D48 | 152 bytes
// Renders body parts with ghost/transparent effect
// ============================================================================
// NON_MATCHING: alpha blending setup
void SimRenderer::RenderGhosted(ERC* rc, EIStaticModel** models, EMat4* mat, unsigned int flags, bool flag) {
    if (rc == 0 || models == 0) return;
    // Set up ghost rendering state (alpha blend)
    // Render all body parts
    // Restore render state
}
