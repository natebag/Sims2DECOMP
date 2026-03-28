#if 0 // SKIP
// e_ngcrenderer_large.cpp - ENgcRenderer large functions (257-1024 bytes)
// Part of the Sims 2 GC decompilation
// Original: engine_ngc_release_dvd.lib(e_ngcrenderer.obj)

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class ENgcRenderer;
class ENgcShader;
class ENgcTexture;
class ENgcRenderStateCache;
struct EDLEntry;
struct EVec3 { float x, y, z; };
struct EVec4 { float x, y, z, w; };
struct EMat4 { float m[4][4]; };
struct EGEVert;
struct ENgcRendCommand;
struct _GXRenderModeObj;
struct _GXTexObj;

// GX SDK functions
extern "C" {
    void GXSetViewport(float, float, float, float, float, float);
    void GXSetScissor(u32, u32, u32, u32);
    void GXSetZMode(u8, u8, u8);
    void GXSetBlendMode(u8, u8, u8, u8);
    void GXSetAlphaCompare(u8, u8, u8, u8, u8);
    void GXSetTevOrder(u8, u8, u8, u8);
    void GXSetTevColorIn(u8, u8, u8, u8, u8);
    void GXSetTevColorOp(u8, u8, u8, u8, u8, u8);
    void GXSetTevAlphaIn(u8, u8, u8, u8, u8);
    void GXSetTevAlphaOp(u8, u8, u8, u8, u8, u8);
    void GXSetNumTevStages(u8);
    void GXSetNumTexGens(u8);
    void GXSetCullMode(u8);
    void GXLoadPosMtxImm(float (*)[4], u32);
    void GXSetCurrentMtx(u32);
    void GXBegin(u8, u8, u16);
    void GXEnd(void);
    void GXInitTexObj(_GXTexObj*, void*, u16, u16, u32, u8, u8, u8);
    void GXLoadTexObj(_GXTexObj*, u8);
    void GXInvalidateVtxCache(void);
    void GXSetVtxDesc(u8, u8);
    void GXClearVtxDesc(void);
    void GXSetVtxAttrFmt(u8, u8, u8, u8, u8);
    void VISetNextFrameBuffer(void*);
    void VIFlush(void);
    void VIWaitForRetrace(void);
}

// ============================================================================
// ENgcRenderer::ENgcRenderer(void)
// Address: 0x8033B50C
// Size: 480 bytes
// NON_MATCHING - complex constructor with state initialization
// ============================================================================
void ENgcRenderer_Ctor(void* self)
{
    u8* p = (u8*)self;

    // Zero out large state block
    for (int i = 0; i < 0x4650 / 4; i++) {
        ((u32*)p)[i] = 0;
    }

    // Set default render states
    *(u8*)(p + 0x4644) = 3;   // z compare func = LEQUAL
    *(u8*)(p + 0x4645) = 0;   // z reference
    *(u8*)(p + 0x4646) = 1;   // z test enable

    // Initialize blend defaults
    *(u8*)(p + 0x0564) = 1;   // src blend = ONE
    *(u8*)(p + 0x0565) = 0;   // dst blend = ZERO

    // Set up vtable / jump table
    // NON_MATCHING: vtable pointer, jump table initialization
}

// ============================================================================
// ENgcRenderer::InitGX(_GXRenderModeObj*)
// Address: 0x8033CEB8
// Size: 824 bytes
// NON_MATCHING - full GX hardware initialization
// ============================================================================
void ENgcRenderer_InitGX(void* self, _GXRenderModeObj* rmode)
{
    // Initialize GX with render mode
    // Set default viewport, scissor
    // Configure default vertex formats
    // Set up TEV stages for basic rendering
    // Configure Z buffer, blend modes
    // NON_MATCHING: many GX SDK calls with specific constant parameters

    GXSetViewport(0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
    GXSetScissor(0, 0, 640, 480);
    GXSetCullMode(2); // GX_CULL_BACK
    GXSetZMode(1, 3, 1); // GX_TRUE, GX_LEQUAL, GX_TRUE

    // Set default blend mode
    GXSetBlendMode(0, 1, 0, 0); // GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_CLEAR

    // Set default TEV stage
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 0xFF);
    GXSetTevColorIn(0, 0x0F, 0x08, 0x0A, 0x0F);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 4, 5, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);

    GXSetNumTexGens(1);
    GXSetAlphaCompare(7, 0, 0, 7, 0);

    GXInvalidateVtxCache();
}

// ============================================================================
// ENgcRenderer::InitGXVertexFormats(void)
// Address: 0x8033D1F0
// Size: 964 bytes
// NON_MATCHING - sets up all vertex attribute formats for different draw modes
// ============================================================================
void ENgcRenderer_InitGXVertexFormats(void* self)
{
    // Set up vertex format 0: Position + Normal + Color + TexCoord
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);   // GX_VA_POS = DIRECT
    GXSetVtxDesc(10, 1);  // GX_VA_NRM = DIRECT
    GXSetVtxDesc(11, 1);  // GX_VA_CLR0 = DIRECT
    GXSetVtxDesc(13, 1);  // GX_VA_TEX0 = DIRECT

    GXSetVtxAttrFmt(0, 9, 1, 4, 0);   // POS: XYZ, F32
    GXSetVtxAttrFmt(0, 10, 0, 4, 0);  // NRM: XYZ, F32
    GXSetVtxAttrFmt(0, 11, 1, 5, 0);  // CLR0: RGBA8
    GXSetVtxAttrFmt(0, 13, 1, 4, 0);  // TEX0: ST, F32

    // Set up additional vertex formats for weighted skinning, etc.
    // NON_MATCHING: many more GXSetVtxAttrFmt calls for formats 1-7
}

// ============================================================================
// ENgcRenderer::InitVideo(int&, int&)
// Address: 0x8033D5B4
// Size: 692 bytes
// NON_MATCHING - initializes video hardware, framebuffers
// ============================================================================
void ENgcRenderer_InitVideo(void* self, int* width, int* height)
{
    u8* p = (u8*)self;

    // Get render mode from system
    // Allocate framebuffers
    // Initialize VI

    *width = 640;
    *height = 480;

    // Store dimensions
    *(u16*)(p + 0x0368) = (u16)*width;
    *(u16*)(p + 0x036A) = (u16)*height;

    // Set up double buffering
    // NON_MATCHING: EAHeap allocation calls, VIInit, VISetNextFrameBuffer
}

// ============================================================================
// ENgcRenderer::EndFrame(ENgcRendCommand*)
// Address: 0x8033E9AC
// Size: 656 bytes
// NON_MATCHING - end of frame processing, buffer swap
// ============================================================================
void ENgcRenderer_EndFrame(void* self, ENgcRendCommand* cmd)
{
    u8* p = (u8*)self;

    // Flush display list
    // Wait for GPU idle
    // Copy EFB to XFB
    // Swap framebuffers

    // NON_MATCHING: GXSetDrawDone, GXWaitDrawDone, VISetNextFrameBuffer, VIFlush
}

// ============================================================================
// ENgcRenderer::SetupTEVStagePassColor(_GXTevStageID)
// Address: 0x8033F80C
// Size: 464 bytes
// NON_MATCHING - configures a TEV stage for color pass
// ============================================================================
void ENgcRenderer_SetupTEVStagePassColor(void* self, u8 stage)
{
    // Configure TEV combiner for color-only pass
    GXSetTevOrder(stage, 0xFF, 0xFF, 0xFF);
    GXSetTevColorIn(stage, 0x0F, 0x00, 0x0A, 0x0F);
    GXSetTevColorOp(stage, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(stage, 7, 0, 5, 7);
    GXSetTevAlphaOp(stage, 0, 0, 0, 1, 0);
}

// ============================================================================
// ENgcRenderer::Setup1TEVStageTexture(int, int&, int, int&)
// Address: 0x8033F9DC
// Size: 952 bytes
// NON_MATCHING - configures TEV stage for textured rendering
// ============================================================================
void ENgcRenderer_Setup1TEVStageTexture(void* self, int texIdx, int* stageOut, int coordIdx, int* coordOut)
{
    u8* p = (u8*)self;
    int stage = *stageOut;

    // Set up TEV for textured rendering
    GXSetTevOrder(stage, coordIdx, texIdx, 0xFF);
    GXSetTevColorIn(stage, 0x0F, 0x08, 0x0A, 0x0F);
    GXSetTevColorOp(stage, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(stage, 7, 4, 5, 7);
    GXSetTevAlphaOp(stage, 0, 0, 0, 1, 0);

    *stageOut = stage + 1;
    *coordOut = coordIdx + 1;
}

// ============================================================================
// ENgcRenderer::Scissor(EDLEntry*)
// Address: 0x80343EA0
// Size: 404 bytes
// NON_MATCHING - processes scissor DL entry
// ============================================================================
void ENgcRenderer_Scissor(void* self, EDLEntry* entry)
{
    u8* e = (u8*)entry;
    float x = *(float*)(e + 0x04);
    float y = *(float*)(e + 0x08);
    float w = *(float*)(e + 0x0C);
    float h = *(float*)(e + 0x10);

    u32 ix = (u32)x;
    u32 iy = (u32)y;
    u32 iw = (u32)w;
    u32 ih = (u32)h;

    GXSetScissor(ix, iy, iw, ih);
}

// ============================================================================
// ENgcRenderer::Lights(EDLEntry*)
// Address: 0x80344724
// Size: 400 bytes
// NON_MATCHING - processes lighting setup DL entry
// ============================================================================
void ENgcRenderer_Lights(void* self, EDLEntry* entry)
{
    u8* e = (u8*)entry;

    // Read light count and data
    u32 lightCount = *(u32*)(e + 0x04);
    void* lightData = *(void**)(e + 0x08);

    // Configure GX channel controls and light objects
    // NON_MATCHING: GXSetChanCtrl, GXInitLightPos, GXLoadLightObjImm calls
}

// ============================================================================
// ENgcRenderer::Rect(EDLEntry*)
// Address: 0x803448B4
// Size: 1004 bytes
// NON_MATCHING - renders a textured/colored rectangle
// ============================================================================
void ENgcRenderer_Rect(void* self, EDLEntry* entry)
{
    u8* e = (u8*)entry;

    float x = *(float*)(e + 0x04);
    float y = *(float*)(e + 0x08);
    float w = *(float*)(e + 0x0C);
    float h = *(float*)(e + 0x10);

    // Set up ortho projection for 2D rendering
    // Configure TEV for flat color or textured rect
    // Draw quad using GXBegin/GXEnd

    GXBegin(0x80, 0, 4); // GX_QUADS, vtxfmt 0, 4 verts

    // Emit 4 vertices for the rectangle
    // NON_MATCHING: GX FIFO writes for position, texcoord, color
    // Position: (x,y), (x+w,y), (x+w,y+h), (x,y+h)

    GXEnd();
}

// ============================================================================
// ENgcRenderer::RenderSurface(EDLEntry*)
// Address: 0x80345314
// Size: 376 bytes
// NON_MATCHING
// ============================================================================
void ENgcRenderer_RenderSurface(void* self, EDLEntry* entry)
{
    u8* e = (u8*)entry;
    void* surface = *(void**)(e + 0x04);
    u32 flags = *(u32*)(e + 0x08);

    // Set render target to specified surface
    // NON_MATCHING: EFB copy setup, GXSetTexCopySrc, GXSetTexCopyDst
}

// ============================================================================
// ENgcRenderer::RectList(EDLEntry*)
// Address: 0x803472C0
// Size: 880 bytes
// NON_MATCHING - renders a list of rectangles
// ============================================================================
void ENgcRenderer_RectList(void* self, EDLEntry* entry)
{
    u8* e = (u8*)entry;
    u32 count = *(u32*)(e + 0x04);
    void* rectData = *(void**)(e + 0x08);

    // Process each rect in the list
    for (u32 i = 0; i < count; i++) {
        float* rect = (float*)((u8*)rectData + i * 32);
        // Draw rect similar to single Rect()
        // NON_MATCHING: GX calls
    }
}

// ============================================================================
// ENgcRenderer::Stencil(EDLEntry*)
// Address: 0x80347630
// Size: 380 bytes
// NON_MATCHING
// ============================================================================
void ENgcRenderer_Stencil(void* self, EDLEntry* entry)
{
    u8* e = (u8*)entry;
    u32 stencilFunc = *(u32*)(e + 0x04);
    u32 stencilRef = *(u32*)(e + 0x08);

    // GC doesn't have HW stencil - emulated via alpha test
    GXSetAlphaCompare(stencilFunc, stencilRef, 0, 7, 0);
}

// ============================================================================
// ENgcRenderer::NgcGXDisplayList(EDLEntry*)
// Address: 0x80347BE4
// Size: 1012 bytes
// NON_MATCHING - executes a pre-built GX display list
// ============================================================================
void ENgcRenderer_NgcGXDisplayList(void* self, EDLEntry* entry)
{
    u8* e = (u8*)entry;
    void* dlData = *(void**)(e + 0x04);
    u32 dlSize = *(u32*)(e + 0x08);
    u32 vertCount = *(u32*)(e + 0x0C);

    // Set up vertex descriptors
    // Load position/normal/texcoord matrices
    // Call GXCallDisplayList
    // NON_MATCHING: complex vertex format setup based on flags
}

// ============================================================================
// ENgcRenderer::NgcTriListInt(EDLEntry*)
// Address: 0x80347FD8
// Size: 896 bytes
// NON_MATCHING - renders indexed triangle list with int positions
// ============================================================================
void ENgcRenderer_NgcTriListInt(void* self, EDLEntry* entry)
{
    u8* e = (u8*)entry;
    u32 vertCount = *(u32*)(e + 0x04);
    short* positions = *(short**)(e + 0x08);
    short* texCoords = *(short**)(e + 0x0C);
    unsigned char* colors = *(unsigned char**)(e + 0x10);
    signed char* normals = *(signed char**)(e + 0x14);

    // Set up vertex format for short positions
    // Emit vertices
    GXBegin(0x90, 0, vertCount); // GX_TRIANGLES

    for (u32 i = 0; i < vertCount; i++) {
        // Write position (s16 x3)
        // Write normal (s8 x3)
        // Write color (u8 x4)
        // Write texcoord (s16 x2)
        // NON_MATCHING: direct FIFO writes
    }

    GXEnd();
}

// ============================================================================
// ENgcRenderer::NgcTriList(EDLEntry*)
// Address: 0x80348358
// Size: 812 bytes
// NON_MATCHING - renders triangle list with float positions
// ============================================================================
void ENgcRenderer_NgcTriList(void* self, EDLEntry* entry)
{
    u8* e = (u8*)entry;
    u32 vertCount = *(u32*)(e + 0x04);
    float* positions = *(float**)(e + 0x08);
    float* texCoords = *(float**)(e + 0x0C);
    unsigned char* colors = *(unsigned char**)(e + 0x10);
    signed char* normals = *(signed char**)(e + 0x14);

    GXBegin(0x90, 0, vertCount);

    for (u32 i = 0; i < vertCount; i++) {
        // NON_MATCHING: FIFO writes
    }

    GXEnd();
}

// ============================================================================
// ENgcRenderer::NgcScreenTriList(EDLEntry*)
// Address: 0x80348684
// Size: 804 bytes
// NON_MATCHING - renders screen-space triangle list
// ============================================================================
void ENgcRenderer_NgcScreenTriList(void* self, EDLEntry* entry)
{
    u8* e = (u8*)entry;
    u32 vertCount = *(u32*)(e + 0x04);
    float* positions = *(float**)(e + 0x08);
    float* texCoords = *(float**)(e + 0x0C);
    unsigned char* colors = *(unsigned char**)(e + 0x10);
    signed char* normals = *(signed char**)(e + 0x14);

    // Uses screen-space projection (no world transform)
    // NON_MATCHING: sets identity world matrix before drawing

    GXBegin(0x90, 0, vertCount);
    for (u32 i = 0; i < vertCount; i++) {
        // NON_MATCHING: FIFO writes
    }
    GXEnd();
}

// ============================================================================
// ENgcRenderer::TriStrip(EGEVert*, int)
// Address: 0x80342148
// Size: 920 bytes
// NON_MATCHING - renders tri strip from generic vertex array
// ============================================================================
void ENgcRenderer_TriStrip(void* self, EGEVert* verts, int count)
{
    if (count < 3) return;

    // Set up vertex format based on vertex flags
    // Submit vertices to GX
    GXBegin(0x98, 0, count); // GX_TRIANGLESTRIP

    for (int i = 0; i < count; i++) {
        // Write vertex data from EGEVert structure
        // NON_MATCHING: per-vertex FIFO writes
    }

    GXEnd();
}

// ============================================================================
// ENgcRenderer::WeightedBlend(_GXPrimitive, int, float*, signed char*, float*, unsigned char*, unsigned char*, bool)
// Address: 0x803424E0
// Size: 920 bytes
// NON_MATCHING - weighted vertex blending for skinned meshes
// ============================================================================
void ENgcRenderer_WeightedBlend(void* self, u8 prim, int count,
    float* positions, signed char* normals, float* weights,
    unsigned char* colors, unsigned char* matIndices, bool flag)
{
    // Set up weighted blending matrices
    // For each vertex, compute blended position from bone weights
    // NON_MATCHING: matrix palette skinning computation

    GXBegin(prim, 0, count);
    for (int i = 0; i < count; i++) {
        // Blend position: pos = sum(weight[j] * matrix[j] * srcPos)
        // Blend normal: nrm = sum(weight[j] * matrix[j] * srcNrm)
        // NON_MATCHING: FIFO writes
    }
    GXEnd();
}

// ============================================================================
// ENgcRenderer::WeightedBlendInt(_GXPrimitive, int, short*, signed char*, short*, unsigned char*, unsigned char*, bool)
// Address: 0x8034932C
// Size: 788 bytes
// NON_MATCHING - integer position weighted blend
// ============================================================================
void ENgcRenderer_WeightedBlendInt(void* self, u8 prim, int count,
    short* positions, signed char* normals, short* texCoords,
    unsigned char* colors, unsigned char* matIndices, bool flag)
{
    GXBegin(prim, 0, count);
    for (int i = 0; i < count; i++) {
        // NON_MATCHING: integer position skinning
    }
    GXEnd();
}

// ============================================================================
// ENgcRenderer::LineList(EGEVert*, int)
// Address: 0x80343BFC
// Size: 296 bytes
// NON_MATCHING
// ============================================================================
void ENgcRenderer_LineList(void* self, EGEVert* verts, int count)
{
    if (count < 2) return;

    GXBegin(0xA8, 0, count); // GX_LINES
    for (int i = 0; i < count; i++) {
        // NON_MATCHING: FIFO writes
    }
    GXEnd();
}

// ============================================================================
// ENgcRenderer::ModelMatrixIndex(int, int)
// Address: 0x803440AC
// Size: 276 bytes
// NON_MATCHING
// ============================================================================
void ENgcRenderer_ModelMatrixIndex(void* self, int posIdx, int nrmIdx)
{
    u8* p = (u8*)self;

    // Load matrix at index into GX matrix slots
    float (*mtx)[4] = (float (*)[4])((u8*)p + posIdx * 48);
    GXLoadPosMtxImm(mtx, posIdx * 3);
    GXSetCurrentMtx(posIdx * 3);
}

// ============================================================================
// ENgcRenderer::SetTexture(ENgcTexture*, int)
// Address: 0x8034447C
// Size: 284 bytes
// NON_MATCHING
// ============================================================================
void ENgcRenderer_SetTexture(void* self, ENgcTexture* tex, int slot)
{
    u8* p = (u8*)self;

    if (!tex) return;

    // Get GXTexObj from ENgcTexture
    _GXTexObj* texObj = (_GXTexObj*)((u8*)tex + 0x10);
    GXLoadTexObj(texObj, slot);

    // Store in renderer state
    *(u32*)(p + 0x4638 + slot * 4) = (u32)tex;
}

// ============================================================================
// ENgcRenderer::SpriteListPacked(int, float*, float*, unsigned char*, signed char*, unsigned char*)
// Address: 0x803454F8
// Size: 696 bytes
// NON_MATCHING - renders billboard sprites
// ============================================================================
void ENgcRenderer_SpriteListPacked(void* self, int count,
    float* positions, float* texCoords, unsigned char* colors,
    signed char* normals, unsigned char* sizes)
{
    // For each sprite:
    //   - Calculate billboard orientation from camera
    //   - Expand point to quad
    //   - Draw quad
    // NON_MATCHING: camera-facing billboard computation

    for (int i = 0; i < count; i++) {
        // Each sprite becomes 4 vertices
        GXBegin(0x80, 0, 4); // GX_QUADS
        // NON_MATCHING: FIFO writes for billboard quad
        GXEnd();
    }
}

// ============================================================================
// ENgcRenderer::SetShader(ENgcShader*, unsigned int)
// Address: 0x803489F8
// Size: 996 bytes
// NON_MATCHING - applies full shader state to GX hardware
// ============================================================================
void ENgcRenderer_SetShader(void* self, ENgcShader* shader, unsigned int flags)
{
    u8* p = (u8*)self;

    if (!shader) return;

    // Apply shader state:
    // 1. Set textures
    // 2. Configure TEV stages based on shader definition
    // 3. Set blend mode
    // 4. Set alpha test
    // 5. Set color/alpha channels
    // 6. Apply material colors

    // NON_MATCHING: reads shader fields and configures GX accordingly
    // Multiple GXSetTev* calls based on shader layer count and blend modes
}

// ============================================================================
// ENgcRenderer::SimpleSkinning(_GXPrimitive, int, short*, signed char*, short*, unsigned char*, unsigned char*, bool)
// Address: 0x80349640
// Size: 732 bytes
// NON_MATCHING - single-weight skinning
// ============================================================================
void ENgcRenderer_SimpleSkinning(void* self, u8 prim, int count,
    short* positions, signed char* normals, short* texCoords,
    unsigned char* colors, unsigned char* boneIndices, bool flag)
{
    // Simple 1-bone-per-vertex skinning
    GXBegin(prim, 0, count);
    for (int i = 0; i < count; i++) {
        // Transform vertex by single bone matrix
        // NON_MATCHING: FIFO writes with matrix index
    }
    GXEnd();
}

// ============================================================================
// ENgcRenderer::ScaleTexture(_GXTexObj*, void*, int, float)
// Address: 0x80349A70 (listed as 0x8034991C but that's 340 bytes)
// Size: 340 bytes
// NON_MATCHING
// ============================================================================
void ENgcRenderer_ScaleTexture(void* self, _GXTexObj* texObj, void* data, int size, float scale)
{
    // Scale texture data by given factor
    // Used for LOD/mipmap generation
    // NON_MATCHING: pixel manipulation loop
}

// ============================================================================
// ENgcRenderer::DrawTextureToFullViewportWithJitter(float, float)
// Address: 0x80349A70
// Size: 292 bytes
// NON_MATCHING
// ============================================================================
void ENgcRenderer_DrawTextureToFullViewportWithJitter(void* self, float jitterX, float jitterY)
{
    // Draw full-screen textured quad with sub-pixel jitter offset
    // Used for anti-aliasing accumulation

    GXBegin(0x80, 0, 4); // GX_QUADS
    // Vertices at corners of viewport with jitter applied to texcoords
    // NON_MATCHING: FIFO writes
    GXEnd();
}

// ============================================================================
// ENgcRenderer::DrawFrameWithBloomAndMotionBlur(float, float)
// Address: 0x80349B94
// Size: 356 bytes
// NON_MATCHING
// ============================================================================
void ENgcRenderer_DrawFrameWithBloomAndMotionBlur(void* self, float bloomStr, float blurStr)
{
    // Composites bloom and motion blur over the frame
    // 1. Copy EFB to texture
    // 2. Draw bloom overlay
    // 3. Draw motion blur overlay
    // NON_MATCHING: GX copy and blend calls
}

// ============================================================================
// ENgcRenderer::ProcessThumbnail(void*, int, float, float)
// Address: 0x80349CF8
// Size: 568 bytes
// NON_MATCHING - captures a thumbnail image
// ============================================================================
void ENgcRenderer_ProcessThumbnail(void* self, void* dest, int size, float w, float h)
{
    // Copy portion of framebuffer to thumbnail buffer
    // Scales down to requested size
    // NON_MATCHING: GXSetTexCopySrc, GXSetTexCopyDst, GXCopyTex
}

// ============================================================================
// ENgcRenderer::VIPreRetraceCallback(unsigned long)
// Address: 0x8033CCEC (adjusted) -> 0x8033CCD4
// Size: 280 bytes
// NON_MATCHING - vertical blank interrupt handler
// ============================================================================
void ENgcRenderer_VIPreRetraceCallback(unsigned long retraceCount)
{
    // Swap framebuffers on vertical blank
    // Update frame counter
    // Signal frame complete event
    // NON_MATCHING: VI register writes
}

// ============================================================================
// ReflectionCoord(Vec&, Vec&, float(*)[3], float(*)[3], Vec&)
// Address: 0x80341EE8
// Size: 568 bytes
// NON_MATCHING - computes reflection texture coordinate
// ============================================================================
void ReflectionCoord(EVec3& normal, EVec3& viewDir, float (*texMtx)[3], float (*nrmMtx)[3], EVec3& outCoord)
{
    // Calculate reflection vector: R = 2(N.V)N - V
    float dot = normal.x * viewDir.x + normal.y * viewDir.y + normal.z * viewDir.z;
    float rx = 2.0f * dot * normal.x - viewDir.x;
    float ry = 2.0f * dot * normal.y - viewDir.y;
    float rz = 2.0f * dot * normal.z - viewDir.z;

    // Transform through texture matrix
    outCoord.x = texMtx[0][0] * rx + texMtx[0][1] * ry + texMtx[0][2] * rz;
    outCoord.y = texMtx[1][0] * rx + texMtx[1][1] * ry + texMtx[1][2] * rz;
    outCoord.z = texMtx[2][0] * rx + texMtx[2][1] * ry + texMtx[2][2] * rz;
}

// ============================================================================
// ENgcRenderStateCache::operator=(ENgcRenderStateCache&)
// Address: 0x8034A818
// Size: 864 bytes
// NON_MATCHING - copies all render state
// ============================================================================
void ENgcRenderStateCache_CopyAssign(void* dst, void* src)
{
    // Copy all GX render state fields
    // TEV stages, blend modes, alpha test, z mode, etc.
    for (int i = 0; i < 216; i++) {
        ((u32*)dst)[i] = ((u32*)src)[i];
    }
}

// ============================================================================
// __DEMODiagnoseHang(void)
// Address: 0x8033CB1C
// Size: 440 bytes
// NON_MATCHING
// ============================================================================
void __DEMODiagnoseHang(void)
{
    // Debug function to detect GPU hangs
    // Reads GX state, checks for stall conditions
    // NON_MATCHING: register reads, debug output
}
#endif
