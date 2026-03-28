// engcrenderer_decomp.cpp - ENgcRenderer Full Decompilation Analysis
// Part of the Sims 2 GC matching decompilation
// Original: u2_ngc_release_dvd(e_ngcrenderer.obj)
//
// ENgcRenderer is the GameCube-specific hardware renderer.
// Size: 0x4668 (18,024 bytes), 119 fields, 153 methods.
// It wraps the Nintendo GX graphics API and manages:
//   - Framebuffer management (double-buffered XFBs)
//   - Display list execution (command-based rendering)
//   - TEV stage configuration (GameCube's programmable pixel pipeline)
//   - Vertex format setup (8 vertex format groups)
//   - Viewport/scissor/projection matrix management
//   - Blend mode, Z-test, alpha test state
//   - Material and lighting configuration
//   - Render state cache (push/pop for nested rendering)
//
// ARCHITECTURE OVERVIEW FOR PC PORT:
//
// The renderer uses a command-based architecture. Game code builds EDL
// (Engine Display List) buffers containing 8-byte command entries.
// ENgcRenderer::Execute() reads each entry's opcode byte and dispatches
// through m_jumpTable (75 entries at 0x80442B50 in .data).
//
// The ENgcRenderStateCache (at offset 0x04D8) is a ~1960-byte struct
// that holds ALL current GX hardware state. Functions set "dirty flags"
// in the cache (at offset 0x06CC within the RSC), and the state is
// flushed to GX hardware lazily before draw calls.
//
// KEY OFFSETS into ENgcRenderStateCache (RSC, pointed to by this+0x4D8):
//   RSC+0x0000  = cull mode / geometry mode
//   RSC+0x03AC  = z-test enable (u8)
//   RSC+0x03B0  = z-test compare func (u32 -> GXCompare enum)
//   RSC+0x03B4  = z-test write enable (u8)
//   RSC+0x03B8  = alpha compare func (u32)
//   RSC+0x03BC  = alpha ref (u8)
//   RSC+0x03C0  = alpha op (u32)
//   RSC+0x03C4  = alpha compare2 func (u32)
//   RSC+0x03C8  = alpha test flag (u8)
//   RSC+0x03C9  = alpha pass-through (u8)
//   RSC+0x03D4  = TEV stage config start
//   RSC+0x06CC  = dirty flags (u32, bitmask)
//   RSC+0x06D0  = dirty flags 2 (u32, bitmask)
//   RSC+0x06D4  = material dirty (u32)
//   RSC+0x06E8  = geometry mode flags (u32)
//   RSC+0x06F0  = lighting enabled (u8)
//   RSC+0x079C  = cull mode (u32)
//   RSC+0x07A0  = padding / viewport state
//   RSC+0x09B0  = viewport params (6 floats: x, y, w, h, nearZ, farZ)
//   RSC+0x09C8  = scissor params (4 u32: x, y, w, h)
//   RSC+0x09D8  = projection mode (u32: 0=perspective, 1=ortho, 2=custom)
//
// DIRTY FLAG BITS (RSC+0x06CC):
//   0x80000000  = always set (indicates pending changes)
//   0x00000001  = blend/TEV state dirty
//   0x00000002  = viewport dirty (unused separately?)
//   0x00000004  = view matrix dirty
//   0x00000020  = projection matrix dirty
//   0x00000040  = z-test/alpha-test dirty
//   0x00000080  = material color dirty
//   0x00000100  = TEV stage config dirty
//   0x00000200  = viewport dirty
//   0x00000400  = scissor dirty
//   0x00000600  = viewport + scissor
//
// GX→OPENGL TRANSLATION NOTES (for PC port):
//
// 1. TEV STAGES → Fragment Shaders
//    GX TEV is a fixed-function combiner with up to 16 stages.
//    Each stage combines color/alpha inputs via add/sub/compare.
//    Map to: GLSL fragment shader with equivalent combiners.
//    The game uses max ~4 TEV stages for most geometry.
//
// 2. VERTEX FORMATS → VAOs/VBOs
//    GX uses GXSetVtxAttrFmt to define per-format vertex layouts.
//    8 vertex format groups (GX_VTXFMT0..GX_VTXFMT7).
//    Map to: OpenGL Vertex Array Objects with matching layouts.
//
// 3. GX DISPLAY LISTS → Draw Call Batches
//    GX display lists (GXBeginDisplayList/GXEndDisplayList) are
//    precompiled command buffers stored in main RAM.
//    Map to: OpenGL display lists or VBO+EBO draw calls.
//
// 4. Z-TEST → glDepthFunc
//    GX compare functions map directly to GL compare functions.
//    GX_NEVER=0, GX_LESS=1, GX_EQUAL=2, GX_LEQUAL=3, etc.
//
// 5. BLEND MODES → glBlendFunc
//    GX blend src/dst factors map to GL blend factors.
//    GX_BL_ZERO=0, GX_BL_ONE=1, GX_BL_SRCALPHA=4, etc.
//
// 6. FRAMEBUFFERS → FBOs
//    GX uses external framebuffers (XFBs) in main RAM.
//    The game double-buffers with m_framebuffer[0] and m_framebuffer[1].
//    Map to: OpenGL FBOs or just swap buffers.
//
// 7. SCISSOR → glScissor
//    Direct mapping. GXSetScissor(x,y,w,h) → glScissor(x,y,w,h).
//
// 8. VIEWPORT → glViewport
//    GXSetViewport(x,y,w,h,near,far) → glViewport + glDepthRange.
//
// 9. MATRICES → Uniform Matrices
//    GXLoadPosMtxImm loads position matrices into GX matrix slots.
//    Map to: glUniformMatrix4fv for model/view/projection.
//
// ============================================================================

#if 0 // DECOMP ANALYSIS - not compiled

#include "types.h"
#include "include/classes/ENgcRenderer.h"

// ============================================================================
// STATIC MEMBERS (from .sdata/.sbss/.bss)
// ============================================================================
//
// s_lastTokenToGX   (0x804FF2F4, u16) - last draw sync token sent to GX
// s_lastTokenFromGX (0x804FF2F6, u16) - last draw sync token returned by GX
// s_breakPointSet   (0x804FF2F8, u32) - breakpoint callback registered flag
// s_frameAvailable  (0x804FF2FC, u32) - frame available for display
// s_frameXfb        (0x804FF300, u32) - pointer to frame XFB
// s_frameEvent      (0x804FF304, u32) - frame event signal
// s_copyMutex       (0x804D9B20, 28B) - OSSemaphore for copy protection
//
// Global renderer pointer: _pRend at r13-26312 (0x9938 offset from r13)
// Video mode flag:         at r13-18460 (0xB7E4 offset from r13)
//   Value 1 = progressive/480p mode
//   Other   = interlaced mode


// ============================================================================
// JUMP TABLE (m_jumpTable) at 0x80442B50 in .data
// ============================================================================
//
// 75 entries, each 8 bytes: { s16 offset_or_flags, s16 pad, void* handler }
// The Execute() function reads the opcode byte from EDLEntry[0], uses it as
// an index into this table to find the handler function pointer.
//
// Opcode → Handler mapping (reconstructed from jump table addresses):
//
//  0 = TriStrip(EDLEntry*)           0x80342120
//  1 = TriFan(EDLEntry*)             0x8034A628  [stub - warn once]
//  2 = TriList(EDLEntry*)            0x8034A640  [stub - warn once]
//  3 = QuadList(EDLEntry*)           0x803457B0
//  4 = PointList(EDLEntry*)          0x8034A670  [stub - warn once]
//  5 = SpriteList(EDLEntry*)         0x8034A688  [stub - warn once]
//  6 = DisplayList(EDLEntry*)        0x80343D24
//  7 = Goto(EDLEntry*)               0x80343D54
//  8 = End(EDLEntry*)                0x80343D60
//  9 = Viewport(EDLEntry*)           0x80343DDC
// 10 = ClipRect(EDLEntry*)           0x80343E7C
// 11 = Scissor(EDLEntry*)            0x80343EA0
// 12 = ModelMatrices(EDLEntry*)      0x80344034
// 13 = ViewMatrix(EDLEntry*)         0x8034420C
// 14 = ProjectionMatrix(EDLEntry*)   0x803442D8
// 15 = WindowMatrix(EDLEntry*)       0x8034439C
// 16 = TextureMatrix(EDLEntry*)      0x8034443C  [stub - blr]
// 17 = Texture(EDLEntry*)            0x80344440
// 18 = EnableGeometryModes(EDLEntry*)  0x80344598
// 19 = DisableGeometryModes(EDLEntry*) 0x803445F0
// 20 = SetGeometryModes(EDLEntry*)     0x80344648
// 21 = EnableRasterModes(EDLEntry*)    0x80344698
// 22 = DisableRasterModes(EDLEntry*)   0x803446C4
// 23 = SetRasterModes(EDLEntry*)       0x803446F0
// 24 = Lights(EDLEntry*)             0x80344724
// 25 = SetAlpha(EDLEntry*)           0x8034A7E8  [stub variant]
// 26 = LineList(EDLEntry*)           0x80343BD4
// 27 = LineStrip(EDLEntry*)          0x8034A658  [stub - warn once]
// 28 = SaveState(EDLEntry*)          0x80343D94
// 29 = RestoreState(EDLEntry*)       0x80343DB8
// 30 = SendGSDisplayList(EDLEntry*)  0x8034A6A0  [stub - warn once]
// 31 = CallbackParam(EDLEntry*)      0x8034A6B8  [stub - warn once]
// 32 = GEList(EDLEntry*)             0x8034A6E8  [stub - warn once]
// 33 = Rect(EDLEntry*)               0x803448B4
// 34 = ModelMatrixIndices(EDLEntry*)  0x803441C0
// 35 = Material(EDLEntry*)           0x80345120
// 36 = MipMapSetup(EDLEntry*)        0x803451A4
// 37 = RecalcMatrices(EDLEntry*)     0x8034A700  [stub - warn once]
// 38 = Debug(EDLEntry*)              0x803451BC
// 39 = GeometrySetup(EDLEntry*)      0x803451E4
// 40 = ZTest(EDLEntry*)              0x80345220
// 41 = AlphaTest(EDLEntry*)          0x80345284
// 42 = RenderSurface(EDLEntry*)      0x80345314
// 43 = TriIndexed(EDLEntry*)         0x8034548C
// 44 = SaveImageData(EDLEntry*)      0x803454A4
// 45 = SpriteListPacked(EDLEntry*)   0x803454BC
// 46 = SetCombineMode(EDLEntry*)     0x80346104
// 47 = SetBlendMode(EDLEntry*)       0x80346124
// 48 = MovieFrame(EDLEntry*)         0x8034615C
// 49 = SetMipMap(EDLEntry*)          0x8034A718  [stub - warn once]
// 50 = TriStripPacked(EDLEntry*)     0x80342878
// 51 = Callback(EDLEntry*)           0x8034A6D0  [stub - warn once]
// 52 = DirectRect(EDLEntry*)         0x80344CA0
// 53 = Vertex(EDLEntry*)             0x8034A730  [stub - warn once]
// 54 = PointListPacked(EDLEntry*)    0x8034A754  [stub - warn once]
// 55 = NoOp(EDLEntry*)               0x8034A778  [nop - blr]
// 56 = VerifyMpg(EDLEntry*)          0x8034A77C  [stub - warn once]
// 57 = ParticleList(EDLEntry*)       0x8034A794  [stub - warn once]
// 58 = ParticleListRot(EDLEntry*)    0x8034A7AC  [stub - warn once]
// 59 = LineStreakList(EDLEntry*)      0x8034A7C4  [stub - warn once]
// 60 = CopyScreenToTexture(EDLEntry*)  0x8034A800  [stub - warn once]
// 61 = RectListRot(EDLEntry*)        0x80346E1C
// 62 = RectList(EDLEntry*)           0x803472C0
// 63 = Stencil(EDLEntry*)            0x80347630
// 64 = NgcTexInvalidateAll(EDLEntry*)  0x803477AC
// 65 = NgcGXDisplayListInt(EDLEntry*)  0x803477CC
// 66 = NgcGXDisplayList(EDLEntry*)     0x80347BE4
// 67 = NgcTriListInt(EDLEntry*)        0x80347FD8
// 68 = NgcTriList(EDLEntry*)           0x80348358
// 69 = NgcScreenTriList(EDLEntry*)     0x80348684
// 70 = ReadMetrics(EDLEntry*)          0x803489A8
// 71 = Shader(EDLEntry*)               0x803489D0
// 72 = ScrambleRect(EDLEntry*)         0x80348DDC
// 73 = TriStripPackedInt(EDLEntry*)    0x80343264
// 74 = Shader(EDLEntry*)               0x803489D0  [duplicate?]


// ============================================================================
// SECTION 1: LIFECYCLE (Constructor / Destructor / Init / Shutdown)
// ============================================================================

// ----------------------------------------------------------------------------
// ENgcRenderer::ENgcRenderer(void)
// Address: 0x8033B50C, Size: 480 bytes
// ----------------------------------------------------------------------------
// The constructor initializes the base class (via bl 0x80364d38, likely
// ERenderer::ERenderer()), sets the vtable pointer at offset 0x0338 to
// the ENgcRenderer vtable (0x8046CD60), then initializes the per-render
// state block at offsets 0x0548..0x05A0 (the render mode/state array).
//
// Key initialization:
//   - Calls base class constructor
//   - Sets vtable at this+0x338 = 0x8046CD60
//   - Initializes render state entries (loop at 0x8033B5D8):
//     Each entry is 64 bytes with fields:
//       +0x00..0x08: three 32-bit values (zeroed)
//       +0x0C: u32 = 8 (vertex format index?)
//       +0x10: u32 = 24 (stride?)
//       +0x1C: u8 = 0 (blend src)
//       +0x1D: u8 = 1 (blend enable)
//       +0x1E: u8 = 0 (blend op)
//       +0x1F: u8 = 1 (z write)
//       +0x20: u8 = 255 (alpha ref)
//       +0x21..0x26: zeroed
//       +0x14: float = 1.0f (alpha)
//       +0x18: float = 0.0f
//       +0x28..0x3C: copied from floats loaded earlier
//   - Sets framebuffer index (this+0x034C) = 0
//   - Sets shader (this+0x03A0) = -1 (no shader)
//   - Sets dirty flag (this+0x0510) = 1
//   - Sets clear color (this+0x0360) = 1
//   - Stores global renderer pointer: _pRend = this
//   - Sets frame rate target based on video mode:
//     progressive (1) → 50 FPS target, else → 60 FPS target
//
// SPIN LOOPS at 0x8033B668..0x8033B698:
//   Three tight loops (bdnz to self) for cycle-wasting delays.
//   Loop counts: 1 iter, 4 iters, 4 iters, 248 iters.
//   These are likely cache/pipeline synchronization barriers
//   required before initializing GX hardware state.
//
void ENgcRenderer::ENgcRenderer(void)
{
    // Call base class ERenderer constructor
    ERenderer::ERenderer();

    // Set vtable
    this->_vtable = &ENgcRenderer_vtable; // 0x8046CD60

    // Initialize render state entries at offset 0x0548 (2 entries, 64 bytes each)
    // The entries at 0x0518, 0x0528, 0x0538 are material colors (ambient/diffuse/specular)
    // copied from const data

    for (int i = 0; i < 2; i++) {
        u8* entry = (u8*)this + 0x0548 + i * 0x40;
        *(u32*)(entry + 0x00) = 0;
        *(u32*)(entry + 0x04) = 0;
        *(u32*)(entry + 0x08) = 0;
        *(u32*)(entry + 0x0C) = 8;     // vertex format
        *(u32*)(entry + 0x10) = 24;    // stride
        *(u8*)(entry + 0x1C) = 0;      // blend src = ZERO
        *(u8*)(entry + 0x1D) = 1;      // blend enable
        *(u8*)(entry + 0x1E) = 0;      // blend op
        *(u8*)(entry + 0x1F) = 1;      // z write
        *(u8*)(entry + 0x20) = 255;    // alpha ref
        *(u8*)(entry + 0x21) = 0;
        *(u8*)(entry + 0x22) = 0;
        *(u8*)(entry + 0x23) = 0;
        *(u8*)(entry + 0x24) = 0;
        *(u8*)(entry + 0x25) = 0;
        *(u16*)(entry + 0x26) = 0;
        *(f32*)(entry + 0x14) = 1.0f;  // alpha
        *(f32*)(entry + 0x18) = 0.0f;
        // Copy material data from const pool
    }

    // Spin-wait barriers for hardware sync
    // (3 tight loops with bdnz)

    // Store global renderer pointer
    _pRend = this;

    // Set frame rate based on video mode
    if (g_videoMode == 1) {  // progressive
        g_targetFrameRate = 50;
    } else {
        g_targetFrameRate = 60;
    }

    // Initialize state
    this->m_field_34C = 0;      // framebuffer index
    this->m_shader = -1;        // no shader active
    this->m_geometryModes_510 = 1;  // dirty
    this->m_clearColor = 1;     // needs clear
}


// ----------------------------------------------------------------------------
// ENgcRenderer::~ENgcRenderer(void)
// Address: 0x8033B6EC, Size: 52 bytes
// ----------------------------------------------------------------------------
// Resets vtable to ENgcRenderer vtable (in case of virtual dispatch during
// destruction), clears global renderer pointer, calls base class destructor.
//
void ENgcRenderer::~ENgcRenderer(void)
{
    this->_vtable = &ENgcRenderer_vtable; // 0x8046CD60
    _pRend = NULL;
    ERenderer::~ERenderer();  // bl 0x80364d74
}


// ----------------------------------------------------------------------------
// ENgcRenderer::Init(int &, int &)
// Address: 0x8033B734, Size: 48 bytes
// ----------------------------------------------------------------------------
// Thin wrapper around InitVideo. Returns success as bool.
//
bool ENgcRenderer::Init(int& width, int& height)
{
    int result = InitVideo(width, height);
    return (result != 0) ? true : false;
}


// ============================================================================
// SECTION 2: VIDEO & GX INITIALIZATION
// ============================================================================

// ----------------------------------------------------------------------------
// ENgcRenderer::InitVideo(int &, int &)
// Address: 0x8033D5B4, Size: 692 bytes
// ----------------------------------------------------------------------------
// Full video system initialization:
//   1. Selects render mode based on g_videoMode:
//      - progressive (1): uses 480p render mode from 0x8046A05C
//      - interlaced:      uses 480i render mode from 0x80469C60
//   2. Copies render mode to this+0x0396 (anti-alias table)
//   3. Stores output dimensions: width at this+0x0368, height at this+0x036A
//   4. Calculates framebuffer stride: ((width + 15) & ~15) * 2
//   5. Allocates two XFB framebuffers (32-byte aligned) at this+0x0344/0x0348
//   6. Clears each framebuffer with ClearXFB (YCbCr black: 0x10801080)
//   7. Allocates frame effects scratch memory (half-resolution, 4-byte aligned)
//      at this+0x464C and this+0x4650
//   8. Calls InitData() to set up render state
//   9. Initializes VI (Video Interface):
//      - VIConfigure, VISetNextFrameBuffer, VISetBlack(0)
//   10. Calls InitGX() to set up GX hardware
//   11. Sets up draw sync and breakpoint callbacks
//   12. Registers VIPreRetraceCallback and VIPostRetraceCallback
//   13. Configures Peripheral Interface (PI) via MMIO at 0xCC01xxxx:
//       Sets up command processor interrupt configuration
//
// PC PORT NOTE: Replace entire function with window creation + GL context init.
// The framebuffer allocation becomes FBO setup.
// The VI callbacks become swap interval / vsync configuration.
//
void ENgcRenderer::InitVideo(int& outWidth, int& outHeight)
{
    // Select render mode
    _GXRenderModeObj* rmode;
    if (g_videoMode == 1) {
        rmode = &GXNtsc480Prog; // progressive 480p
    } else {
        rmode = &GXNtsc480IntDf; // interlaced 480i
    }

    // Copy render mode struct to this+0x0364
    memcpy((u8*)this + 0x0364, rmode, sizeof(_GXRenderModeObj));

    // Copy anti-alias table
    memcpy((u8*)this + 0x0396, &rmode->aa_table, 7);

    // Store dimensions
    outWidth = this->m_field_368; // render width
    outHeight = this->m_field_36A; // render height

    // Calculate framebuffer size
    u32 stride = ((this->m_field_368 + 15) & ~15) * 2;
    u32 fbSize = stride * this->m_field_36C;
    this->m_field_354 = stride;
    this->m_field_350 = fbSize;

    // Allocate two XFB framebuffers (double buffering)
    for (int i = 0; i < 2; i++) {
        void* heap = EAHeap_GetCurrentHeap();
        void* fb = EAHeap_AllocAlign(heap, fbSize, 32, 0, 0);
        this->framebuffer[i] = fb;
        ClearXFB(fb, fbSize);
        memset(fb, 0x10801080, fbSize); // YCbCr black
    }

    // Allocate frame effects memory (half resolution)
    void* feScratch = AllocTexMem(outWidth, outHeight, 4, 0, 0);
    this->m_field_464C = feScratch;
    void* fePrev = AllocTexMem(outWidth / 2, outHeight / 2, 4, 0, 0);
    this->m_field_4650 = fePrev;

    // Set initial framebuffer index
    this->m_field_340 = 0;
    this->m_field_34C = this->framebuffer[0];

    // Initialize render data
    InitData();

    // Initialize video interface
    VIConfigure(rmode);
    VISetNextFrameBuffer(this->m_field_34C);
    VISetBlack(0);
    VIFlush();

    // Initialize GX hardware
    InitGX(rmode);

    // Set up callbacks
    GXSetDrawSyncCallback(DrawSyncCallback);
    GXSetBreakPtCallback(BreakPtCallback);
    GXSetMisc(GX_MT_XF_FLUSH, 1); // 0x80390168
    GXSetMisc(GX_MT_DL_SAVE_CTX, 1); // 0x80390194

    // Register VI callbacks
    VISetPreRetraceCallback(VIPreRetraceCallback);
    VISetPostRetraceCallback(VIPostRetraceCallback);

    // Configure PI interrupts (MMIO writes to 0xCC01xxxx)
    // ... hardware-specific register pokes ...

    // Call CycleToNextFrameBuffer
    CycleToNextFrameBuffer();
}


// ----------------------------------------------------------------------------
// ENgcRenderer::InitGX(_GXRenderModeObj *)
// Address: 0x8033CEB8, Size: 824 bytes
// ----------------------------------------------------------------------------
// Complete GX hardware initialization:
//
// 1. Zeros out 4000 bytes of BSS data (render state cache buffer at 0x804E9B58)
//    using a tight loop with CTR=1000
//
// 2. Allocates GX FIFO buffer:
//    - Size: 0x10000 (64KB), 32-byte aligned
//    - Stored at this+0x0358
//    - Initializes with GXInit()
//    - Stores GX state handle at this+0x03A8
//
// 3. Configures viewport and scissor from render mode:
//    viewport = (0, 0, rmode->fbWidth, rmode->efbHeight, 0.0, 1.0)
//    scissor  = (0, 0, rmode->fbWidth, rmode->efbHeight)
//    copy filter from render mode y-scale
//
// 4. Configures copy display:
//    GXSetDispCopyGamma(GX_GM_1_0)  // gamma = 2
//    GXSetDispCopySrc(0, 0, rmode->fbWidth, rmode->efbHeight)
//    GXSetDispCopyDst(rmode->fbWidth, rmode->xfbHeight)
//
// 5. Sets up rendering defaults:
//    - GXSetCullMode(GX_CULL_BACK = 2)
//    - GXSetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR)
//    - GXSetCopyClear({0,0,0,127}, 0x00FFFFFF) // alpha=127, max Z
//    - GXSetNumChans(1)        // 1 color channel
//    - GXSetNumTexGens(1)      // 1 texture coordinate generator
//    - GXSetDispCopyFrame2Field(GX_COPY_PROGRESSIVE)
//    - GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET)
//
// 6. Calls InitGXVertexFormats()
//
// 7. Initializes multiple ENgcRenderStateCache instances:
//    - Main RSC at this+0x04D8 (base pointer)
//    - 7 additional RSC sub-blocks at offsets +0x07A0, +0x0860, +0x08F0,
//      +0x0920, +0x0950, +0x0980
//
// 8. Sets hardware state defaults in the RSC:
//    - Dirty flag = 0x8000001E (viewport + scissor + view + proj dirty)
//
// PC PORT: Replace with OpenGL/Vulkan context creation.
// Map GX state to: glEnable(GL_DEPTH_TEST), glEnable(GL_BLEND),
// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA),
// glCullFace(GL_BACK), glClearColor(0,0,0,0.5), glClearDepth(1.0).
//
void ENgcRenderer::InitGX(_GXRenderModeObj* rmode)
{
    // Zero 4000 bytes of BSS state cache
    u32* bssBase = (u32*)(0x804E9B58 + 3996);
    for (int i = 0; i < 1000; i++) {
        *bssBase = 0;
        bssBase--;
    }

    // Allocate GX FIFO (64KB, 32-byte aligned)
    void* heap = EAHeap_GetCurrentHeap();
    void* fifo = EAHeap_AllocAlign(heap, 0x10000, 32, 0, 0);
    this->m_field_358 = fifo;
    GXInit(fifo, 0x10000);
    this->m_field_3A8 = GXGetGPStatus(); // or similar

    // Get display dimensions from render mode
    u16 fbWidth  = rmode->fbWidth;   // offset 4
    u16 efbHeight = rmode->efbHeight; // offset 6

    // Set viewport (with float conversion from u16)
    float fWidth  = (float)fbWidth;
    float fHeight = (float)efbHeight;
    GXSetViewport(0.0f, 0.0f, fWidth, fHeight, 0.0f, 1.0f);

    // Set scissor
    GXSetScissor(0, 0, fbWidth, efbHeight);

    // Set copy filter
    GXSetCopyFilter(rmode->aa, rmode->vfilter); // approximate

    // Configure frame display
    GXSetDispCopyGamma(2);  // GX_GM_1_0
    GXSetDispCopySrc(0, 0, fbWidth, efbHeight);
    GXSetDispCopyDst(fbWidth, rmode->xfbHeight);

    // Set rendering defaults
    GXSetCullMode(2); // GX_CULL_BACK

    // Configure pixel format
    GXSetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);

    // Set copy clear color (RGBA = 0,0,0,127) and Z = 0x00FFFFFF
    GXSetCopyClear({0, 0, 0, 127}, 0x00FFFFFF);

    // TEV/lighting setup
    GXSetNumChans(1);
    GXSetNumTexGens(1);

    // Blend mode
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);

    // Vertex formats
    InitGXVertexFormats();

    // Hardware state flush
    GXSetMisc(GX_MT_XF_FLUSH, 1);

    // TEV stage setup - configure for basic 1-texture rendering
    GXSetDispCopyFrame2Field(GX_COPY_PROGRESSIVE);

    // Initialize render state caches
    ENgcRenderStateCache* rsc = this->m_geometryModes; // at 0x04D8
    ENgcRenderStateCache_Init(rsc);
    ENgcRenderStateCache_Init(rsc + 0x07A0);
    ENgcRenderStateCache_Init(rsc + 0x0860);
    ENgcRenderStateCache_Init(rsc + 0x08F0);
    ENgcRenderStateCache_Init(rsc + 0x0920);
    ENgcRenderStateCache_Init(rsc + 0x0950);
    ENgcRenderStateCache_Init(rsc + 0x0980);

    // Mark all state dirty
    rsc->dirtyFlags |= 0x8000001E;
}


// ----------------------------------------------------------------------------
// ENgcRenderer::InitGXVertexFormats(void)
// Address: 0x8033D1F0, Size: 964 bytes
// ----------------------------------------------------------------------------
// Configures 8 GX vertex format groups (GX_VTXFMT0..GX_VTXFMT7) via
// GXSetVtxAttrFmt(format, attr, compCount, compType, fracBits).
//
// FORMAT 0 - Position only (untextured)
//   POS:    (0, GX_POS_XYZ=9,  GX_DIRECT=1, GX_F32=3,  frac=0)
//   TEX0:   (0, GX_TEX0=13,    GX_DIRECT=1, GX_U16=2,  frac=0)
//
// FORMAT 1 - Standard textured (float positions, float UVs)
//   POS:    (1, GX_POS_XYZ=9,  GX_DIRECT=1, GX_F32=4,  frac=0)
//   TEX0-4: (1, GX_TEX0..4,    GX_DIRECT=1, GX_F32=4,  frac=0)
//
// FORMAT 2 - Standard with normals (float pos, s8 normals, float UVs)
//   POS:    (2, GX_POS_XYZ=9,  GX_DIRECT=1, GX_F32=4,  frac=0)
//   NRM:    (2, GX_NRM=10,     GX_NONE=0,   GX_U8=1,   frac=0)
//   CLR0:   (2, GX_CLR0=11,    GX_DIRECT=1, GX_RGBA8=5, frac=0)
//   TEX0-5: (2, GX_TEX0..5,    GX_DIRECT=1, GX_F32=4,  frac=0)
//
// FORMAT 3 - Short positions with normals (s16 pos, s8 normals, s16 UVs)
//   POS:    (3, GX_POS_XYZ=9,  GX_DIRECT=1, GX_F32=4,  frac=0)
//   NRM:    (3, GX_NRM=10,     GX_NONE=0,   GX_U8=1,   frac=0)
//   CLR0:   (3, GX_CLR0=11,    GX_DIRECT=1, GX_RGBA8=5, frac=0)
//   TEX0:   (3, GX_TEX0=13,    GX_DIRECT=1, GX_S16=3,  frac=12) // 12-bit fraction
//   TEX1:   (3, GX_TEX1=14,    GX_DIRECT=1, GX_S16=3,  frac=12)
//
// FORMAT 4 - Skinned/indexed (s16 pos, normals, s16 UVs, 12-bit frac)
//   POS:    (4, GX_POS_XYZ=9,  GX_DIRECT=1, GX_S16=3,  frac=0)
//   NRM:    (4, GX_NRM=10,     GX_NONE=0,   GX_U8=1,   frac=0)
//   CLR0:   (4, GX_CLR0=11,    GX_DIRECT=1, GX_RGBA8=5, frac=0)
//   TEX0:   (4, GX_TEX0=13,    GX_DIRECT=1, GX_F32=4,  frac=12)
//   TEX1:   (4, GX_TEX1=14,    GX_DIRECT=1, GX_F32=4,  frac=0)
//
// FORMAT 5 - Simple (float pos, float UVs)
//   POS:    (5, GX_POS_XYZ=9,  GX_DIRECT=1, GX_F32=4,  frac=0)
//   TEX0:   (5, GX_TEX0=13,    GX_DIRECT=1, GX_F32=4,  frac=0)
//
// FORMAT 6 - Full with s16 UVs, 12-bit fraction
//   POS:    (6, GX_POS_XYZ=9,  GX_DIRECT=1, GX_S16=3,  frac=0)
//   NRM:    (6, GX_NRM=10,     GX_NONE=0,   GX_U8=1,   frac=0)
//   CLR0:   (6, GX_CLR0=11,    GX_DIRECT=1, GX_RGBA8=5, frac=0)
//   TEX0:   (6, GX_TEX0=13,    GX_DIRECT=1, GX_S16=3,  frac=12)
//   TEX1:   (6, GX_TEX1=14,    GX_DIRECT=1, GX_S16=3,  frac=12)
//
// FORMAT 7 - Full with float UVs, second UV float
//   POS:    (7, GX_POS_XYZ=9,  GX_DIRECT=1, GX_F32=4,  frac=0)
//   NRM:    (7, GX_NRM=10,     GX_NONE=0,   GX_U8=1,   frac=0)
//   CLR0:   (7, GX_CLR0=11,    GX_DIRECT=1, GX_RGBA8=5, frac=0)
//   TEX0:   (7, GX_TEX0=13,    GX_DIRECT=1, GX_F32=4,  frac=12)
//   TEX1:   (7, GX_TEX1=14,    GX_DIRECT=1, GX_F32=4,  frac=0)
//
// PC PORT: Each GX vertex format maps to an OpenGL VAO.
// Create 8 VAOs with matching attribute layouts:
//   - Position: always vec3 float (GL_FLOAT)
//   - Normal: vec3 s8 normalized (GL_BYTE, GL_TRUE)
//   - Color: vec4 u8 (GL_UNSIGNED_BYTE, GL_TRUE)
//   - TexCoord: vec2 float or vec2 s16 with fixed-point conversion
//
// The 12-bit fraction formats (frac=12) mean s16 values are divided by 4096
// to get the actual float value. In GLSL: texcoord = float(raw) / 4096.0;


// ============================================================================
// SECTION 3: FRAME LIFECYCLE
// ============================================================================

// ----------------------------------------------------------------------------
// ENgcRenderer::QueueBeginFrame(int)
// Address: 0x8033E7F4, Size: 48 bytes
// ----------------------------------------------------------------------------
// Pushes a "begin frame" command onto the render command queue.
// The command struct is {type=1, param=frameNumber}.
// Calls BeginFrame directly (single-threaded on GC).
//
void ENgcRenderer::QueueBeginFrame(int frameNumber)
{
    ENgcRendCommandData cmd;
    cmd.type = 1;          // REND_CMD_BEGIN_FRAME
    cmd.param1 = frameNumber;
    BeginFrame((ENgcRendCommand*)&cmd);
}

// ----------------------------------------------------------------------------
// ENgcRenderer::BeginFrame(ENgcRendCommand *)
// Address: 0x8033E8E8, Size: 100 bytes
// ----------------------------------------------------------------------------
// Starts a new frame:
//   - Sets g_renderActive = 1
//   - Resets per-frame timing counters (polycount, drawcalls) to 0
//   - Clears this->m_field_4648 (frame command counter) to 0
//   - Copies timing data from global state
//   - Calls ResetGXPerf() (0x803380AC) to reset GX performance counters
//
void ENgcRenderer::BeginFrame(ENgcRendCommand* cmd)
{
    g_renderActive = 1;
    g_frameTimeAccum = 0.0f;
    g_frameTimePrev = 0.0f;
    g_polyCount = 0;
    g_drawCallCount = 0;
    g_batchCount = 0;
    this->m_field_4648 = 0;

    // Copy GPU time from previous frame
    void* perfState = g_perfState;
    perfState->prevTime = perfState->currentTime;

    // Reset GX performance counters
    ResetGXPerf();

    g_perfFrameCount = 0;
}


// ----------------------------------------------------------------------------
// ENgcRenderer::EndFrame(ENgcRendCommand *)
// Address: 0x8033E9AC, Size: 656 bytes
// ----------------------------------------------------------------------------
// Finishes a frame:
//   1. Configures EFB-to-XFB copy: GXSetDispCopySrc, GXSetDispCopyDst
//      Source: full EFB (0,0, fbWidth, fbHeight)
//      Dest: half resolution for XFB
//   2. Sets XFB render target: GXSetTexCopySrc(this->m_field_4650, 0)
//   3. Configures copy filter: VIPreRetraceCallback, VIPostRetraceCallback
//   4. Resets render state cache dirty flags
//   5. Applies clear color with fade:
//      - Reads fade factor from global (clamped 0..1)
//      - Multiplies each channel of the clear color (at this+0x0396..0x039C)
//        by the fade factor
//      - Calls GXSetCopyClear with the faded color
//   6. Sets up frame copy parameters
//   7. If multi-threaded mode (g_renderThread != 0):
//      - Signals render thread with semaphore
//      - Stores current XFB pointer
//      - Calls VISetNextFrameBuffer, GXCopyDisp, GXSetDrawSync
//      - Waits for copy completion
//   8. Otherwise (single-threaded):
//      - GXDrawDone()
//      - VISetNextFrameBuffer
//   9. Cycles to next framebuffer (double-buffer swap)
//   10. Resets render state cache
//   11. Sets dirty flag = 1
//
// PC PORT: Replace with glFinish() / SwapBuffers().
// The fade factor application becomes glClearColor modification.
// The EFB→XFB copy is implicit in OpenGL (back buffer is the "XFB").
//


// ----------------------------------------------------------------------------
// ENgcRenderer::Swap(ENgcRendCommand *)
// Address: 0x8033EC3C, Size: 124 bytes
// ----------------------------------------------------------------------------
// Handles frame swap timing:
//   - If NOT multi-threaded: cycles framebuffer, calls VSync timing
//   - Reads tick counter, calculates frame time
//   - Computes FPS = targetFrameRate / frameTime
//   - Stores frame timing data for performance tracking
//   - Increments frame counter
//
void ENgcRenderer::Swap(ENgcRendCommand* cmd)
{
    if (g_renderThread == 0) {
        CycleToNextFrameBuffer();
        u32 currentTick = OSGetTick();
        u32 elapsed = currentTick - this->m_field_35C;
        u32 fps = g_targetFrameRate / elapsed;
        g_frameTime = elapsed;
        g_currentFPS = fps;
        this->m_field_35C = currentTick;
    }

    // Copy per-frame stats to "previous frame" slots
    g_prevPolyCount = g_polyCount;
    g_prevFrameTime = g_frameTimeAccum;
    g_prevFrameTimePrev = g_frameTimePrev;
    g_prevDrawCallCount = g_drawCallCount;
    g_frameCounter++;
}


// ----------------------------------------------------------------------------
// ENgcRenderer::CycleToNextFrameBuffer(void)
// Address: 0x8033CAB8, Size: 100 bytes
// ----------------------------------------------------------------------------
// Advances to the next framebuffer for double-buffering:
//   1. Calls VISetNextFrameBuffer(this->m_field_34C)
//   2. Increments framebuffer index: idx = (idx + 1) % 2
//   3. Sets m_field_34C = framebuffer[idx]
//   4. Calls VIFlush() and VIWaitForRetrace()
//
void ENgcRenderer::CycleToNextFrameBuffer(void)
{
    VISetNextFrameBuffer(this->m_field_34C);

    u32 idx = this->m_field_340;
    idx = (idx + 1) % 2; // toggle 0/1
    this->m_field_340 = idx;
    this->m_field_34C = this->framebuffer[idx]; // at this+0x344 + idx*4

    VIFlush();
    VIWaitForRetrace();
}


// ============================================================================
// SECTION 4: COMMAND EXECUTION (Display List Interpreter)
// ============================================================================

// ----------------------------------------------------------------------------
// ENgcRenderer::Execute(EDLEntry *)
// Address: 0x80341E28, Size: 192 bytes
// ----------------------------------------------------------------------------
// The main rendering command dispatcher. Processes EDLEntry commands
// from the engine's display list in a loop until an End command sets
// m_overflow = 1.
//
// EDLEntry format (8 bytes):
//   byte 0:  opcode (index into m_jumpTable)
//   byte 1:  param byte (used differently per command)
//   bytes 2-3: param short (count, stage index, etc.)
//   bytes 4-7: param word (pointer, flags, packed data)
//
// The jump table at 0x80442B50 has 75 entries, each 8 bytes:
//   bytes 0-1: s16 - offset type flag (-1 = no param offset, >=0 = offset field index)
//   bytes 2-3: s16 - parameter offset within renderer struct
//   bytes 4-7: void* - handler function pointer
//
// Dispatch logic:
//   1. Read opcode from entry[0]
//   2. Load next entry pointer (entry += 8)
//   3. Look up jump table: jumpEntry = m_jumpTable[opcode]
//   4. If jumpEntry.offsetFlag >= 0:
//      - Load secondary handler from struct offset
//   5. Call handler with (this + calcOffset, entry)
//   6. Check m_overflow; if 0, continue loop
//
// PC PORT: This is the core rendering loop to translate.
// Each opcode handler needs an OpenGL equivalent.
// The command stream format can be kept as-is; only the handlers change.
//
void ENgcRenderer::Execute(EDLEntry* dlStart)
{
    this->m_field_4DC = (u32)dlStart; // current DL pointer
    this->m_field_4E0 = 0;           // overflow flag

    while (true) {
        u8* current = (u8*)this->m_field_4DC;
        u8 opcode = current[0];
        EDLEntry* entry = (EDLEntry*)current;

        // Advance DL pointer past this entry
        this->m_field_4DC = (u32)(current + 8);

        // Look up handler in jump table
        JumpTableEntry* jte = &m_jumpTable[opcode];
        s16 offsetFlag = jte->offsetFlag;
        void (*handler)(void*, EDLEntry*);

        if (offsetFlag >= 0) {
            // Load handler from struct field at jte->paramOffset
            u32 fieldOffset = jte->paramOffset;
            void* base = *(void**)((u8*)this + fieldOffset);
            // Read pre-entry data for chained dispatch
            handler = (void*)*(u32*)((u8*)base + offsetFlag - 8 + 4);
        } else {
            handler = jte->handler;
        }

        // Calculate 'this' offset for the call
        s16 thisOffset = *(s16*)(&m_jumpTable[opcode]);
        void* thisPtr = (u8*)this + thisOffset;

        // Call the handler
        handler(thisPtr, entry);

        // Check if we should stop
        if (this->m_field_4E0 != 0) {
            break; // End command was processed
        }
    }
}


// ============================================================================
// SECTION 5: VIEWPORT, SCISSOR, AND CLEAR
// ============================================================================

// ----------------------------------------------------------------------------
// ENgcRenderer::Viewport(EDLEntry *)
// Address: 0x80343DDC, Size: 160 bytes
// ----------------------------------------------------------------------------
// Sets viewport from display list entry data. The entry's param pointer
// points to a viewport struct with 6 floats: {left, top, right, bottom, near, far}.
//
// Converts to GX viewport format stored in the render state cache (RSC):
//   RSC+0x09B0 = x_origin = -left + width    (shifted)
//   RSC+0x09B4 = y_origin = top + height
//   RSC+0x09B8 = width = (left + width) - x_origin
//   RSC+0x09BC = height = -(-top + height) - y_origin
//   RSC+0x09C0 = near = 0.0
//   RSC+0x09C4 = far = 1.0
//
// Also checks/clears a global "viewport changed" flag.
// Sets dirty bit: RSC.dirtyFlags |= 0x80000200 (viewport dirty)
//
// PC PORT: glViewport(x, y, width, height) + glDepthRange(near, far)
//
void ENgcRenderer::Viewport(EDLEntry* entry)
{
    // Check and clear viewport changed flag
    if (g_viewportChanged != 0) {
        g_viewportChanged = 0;
    }

    float* vp = (float*)entry->param; // 6 floats: l, r, t, b, near, far
    ENgcRenderStateCache* rsc = this->m_geometryModes; // 0x04D8

    float left   = vp[0];
    float top    = vp[1];
    float width  = vp[4]; // actually right extent?
    float height = vp[5];

    rsc->viewport_x = -left + width;
    rsc->viewport_y = top + height;
    rsc->viewport_w = (left + width) - rsc->viewport_x;
    rsc->viewport_h = -(-top + height) - rsc->viewport_y;
    rsc->viewport_near = 0.0f;
    rsc->viewport_far  = 1.0f;

    // Mark viewport dirty
    rsc->dirtyFlags |= 0x80000200;
}


// ----------------------------------------------------------------------------
// ENgcRenderer::Scissor(EDLEntry *)
// Address: 0x80343EA0, Size: 404 bytes
// ----------------------------------------------------------------------------
// Sets scissor rectangle from display list entry.
// The entry param pointer has 4 floats: {left, top, right, bottom}.
//
// Converts float coordinates to integer scissor rect with careful
// handling of values >= 2^31 (uses xoris 0x8000 trick for u32→s32).
//
// Stores in RSC:
//   RSC+0x09C8 = scissor_left
//   RSC+0x09CC = scissor_top
//   RSC+0x09D0 = scissor_width
//   RSC+0x09D4 = scissor_height
//
// Clamps width/height to 0 if either is negative (degenerate scissor).
// Sets dirty bit: RSC.dirtyFlags |= 0x80000400 (scissor dirty)
//
// PC PORT: glScissor(x, y, width, height) with GL_SCISSOR_TEST enabled.
//
void ENgcRenderer::Scissor(EDLEntry* entry)
{
    float* rect = (float*)entry->param;
    ENgcRenderStateCache* rsc = this->m_geometryModes;

    float left   = rect[0];
    float top    = rect[1];
    float right  = rect[2];
    float bottom = rect[3];

    // Calculate width and height, add 0.5 for rounding
    float width  = (right - left) + 0.5f;
    float height = (bottom - top) + 0.5f;

    // Convert to integers (with large float handling)
    rsc->scissor_x = (s32)left;
    rsc->scissor_y = (s32)top;
    rsc->scissor_w = (s32)width;
    rsc->scissor_h = (s32)height;

    // Clamp degenerate scissor to zero
    if (width <= 0.0f || height <= 0.0f) {
        rsc->scissor_w = 0;
        rsc->scissor_h = 0;
    }

    // Mark scissor dirty
    rsc->dirtyFlags |= 0x80000400;
}


// ----------------------------------------------------------------------------
// ENgcRenderer::SetClearColor(EVec3 &, bool)
// Address: 0x8033CA48, Size: 80 bytes
// ----------------------------------------------------------------------------
// Sets the clear color for framebuffer clears.
//   - Copies EVec3 color to this+0x03AC (clear color storage)
//   - Sets alpha component to 127 (0x7F) at this+0x03AC+3
//   - Sets clear color dirty flag at this+0x03B0 = 0x00FFFFFF (max Z clear)
//   - Stores bool param at this+0x0360
//
void ENgcRenderer::SetClearColor(EVec3& color, bool flag)
{
    this->m_clearColor = flag;
    // Copy RGB from EVec3 (converts float→u8 via some helper)
    EVec3_ToColor(&color, (u8*)this + 0x03AC);
    *((u8*)this + 0x03AC + 3) = 127; // alpha = 0.5
    this->m_clearColor_3B0 = 0x00FFFFFF; // clear Z to max
}


// ----------------------------------------------------------------------------
// ENgcRenderer::ClearRect(EVec4 &, EVec4 &)
// Address: 0x8033E1D4, Size: 1568 bytes
// ----------------------------------------------------------------------------
// Clears a rectangular region of the framebuffer.
// This is a complex function that:
//   1. Normalizes the rect coordinates by dividing by screen dimensions
//      (using the integer-to-float conversion trick with 0x43300000)
//   2. Saves current render state (ENgcRenderStateCache_Save)
//   3. Resets render state cache to defaults
//   4. Sets up a full-screen viewport
//   5. Configures TEV for flat-color rendering:
//      - 2 TEV stages, passthrough color
//      - Z-test disabled, alpha test disabled
//   6. Configures material colors from the clear color (EVec4 parameter)
//   7. Sends a quad to GX covering the clear rect:
//      - 4 vertices written directly to GX FIFO at 0xCC008000
//      - Each vertex: position (f32 x, f32 y, f32 z) + color (4 x u8)
//   8. Restores render state
//   9. Sets projection mode = 2 (custom)
//   10. Marks all state dirty
//
// PC PORT: glClearColor + glClear, or draw a full-screen quad with
// glDisable(GL_DEPTH_TEST) and flat color fragment shader.
//
// The FIFO writes at 0xCC008000 are direct GX hardware register writes.
// In the GC memory map, 0xCC008000 is the GX command processor FIFO.
// Writing floats/bytes there is equivalent to GX_Position3f32() etc.
// For PC port, replace with glVertex3f/glColor4ub or VBO submission.


// ============================================================================
// SECTION 6: MATRIX MANAGEMENT
// ============================================================================

// ----------------------------------------------------------------------------
// ENgcRenderer::ViewMatrix(EDLEntry *)
// Address: 0x8034420C, Size: 204 bytes
// ----------------------------------------------------------------------------
// Loads the view matrix from the display list entry into GX.
//
// The entry param points to a 4x4 matrix in row-major order (16 floats).
// The function transposes it to column-major and stores it in the RSC
// at offset 0x0860 (view matrix slot in the RSC).
//
// Then calls ENgcRenderStateCache_SetViewMatrix which loads it via
// GXLoadPosMtxImm into GX matrix slot 0.
//
// Sets dirty: RSC.dirtyFlags |= 0x80000004 (view matrix dirty)
// Sets m_dirty = 1 (this+0x0510)
//
// PC PORT: glUniformMatrix4fv for the view matrix uniform.
// Note the transpose — GX uses row-major, OpenGL column-major.
//
void ENgcRenderer::ViewMatrix(EDLEntry* entry)
{
    float* src = (float*)entry->param; // 4x4 row-major matrix
    ENgcRenderStateCache* rsc = this->m_geometryModes;
    float* dst = (float*)((u8*)rsc + 0x0860); // view matrix in RSC

    // Transpose while copying (row-major → column-major for GX internal format)
    // Row 0: src[0], src[4], src[8], src[12]
    dst[0]  = src[0];  dst[1]  = src[4];  dst[2]  = src[8];  dst[3]  = src[12];
    // Row 1: src[1], src[5], src[9], src[13]
    dst[4]  = src[1];  dst[5]  = src[5];  dst[6]  = src[9];  dst[7]  = src[13];
    // Row 2: src[2], src[6], src[10], src[14]
    dst[8]  = src[2];  dst[9]  = src[6];  dst[10] = src[10]; dst[11] = src[14];

    // Compute inverse for normal matrix (3x3 only)
    ENgcRenderStateCache_ComputeNormalMatrix(rsc + 0x0860);

    // Mark view matrix dirty
    rsc->dirtyFlags |= 0x80000004;
    this->m_geometryModes_510 = 1; // global dirty
}


// ----------------------------------------------------------------------------
// ENgcRenderer::ProjectionMatrix(EDLEntry *)
// Address: 0x803442D8, Size: 196 bytes
// ----------------------------------------------------------------------------
// Loads the projection matrix from display list entry.
// Transposes 4x4 matrix to a global projection matrix buffer at 0x804FD04C.
// Also sets projection mode in RSC: RSC+0x09D8 = 2 (custom projection).
// Sets dirty: RSC.dirtyFlags |= 0x80000020 (projection dirty)
//
// Unlike ViewMatrix, the full 4x4 is stored (including row 3 with w-divide).
//
// PC PORT: glUniformMatrix4fv for the projection matrix.
// Check if perspective or orthographic by inspecting matrix[3][3]:
//   perspective: m[3][3] = 0, m[3][2] = -1
//   orthographic: m[3][3] = 1
//
void ENgcRenderer::ProjectionMatrix(EDLEntry* entry)
{
    float* src = (float*)entry->param;
    float* dst = g_projectionMatrix; // global at 0x804FD04C

    // Transpose 4x4 matrix
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 4; row++) {
            dst[col * 4 + row] = src[row * 4 + col]; // transpose
        }
    }

    // Set projection mode to custom (2)
    ENgcRenderStateCache* rsc = this->m_geometryModes;
    rsc->projectionMode = 2;

    // Mark projection dirty
    rsc->dirtyFlags |= 0x80000020;
    this->m_geometryModes_510 = 1;
}


// ----------------------------------------------------------------------------
// ENgcRenderer::WindowMatrix(EDLEntry *)
// Address: 0x8034439C, Size: 160 bytes
// ----------------------------------------------------------------------------
// Copies a 4x4 matrix (64 bytes) from the entry param to this+0x0498.
// This is the window/screen-space transform matrix.
// Also checks and clears a "window matrix changed" global flag.
//
// No GX calls — just stores the matrix for later use by draw commands.
//
void ENgcRenderer::WindowMatrix(EDLEntry* entry)
{
    // Check and clear global flag
    if (g_windowMatrixChanged != 0) {
        g_windowMatrixChanged = 0;
    }

    // Copy 64 bytes (4x4 matrix) from entry param to this+0x0498
    float* src = (float*)entry->param;
    float* dst = (float*)((u8*)this + 0x0498);
    memcpy(dst, src, 64);
}


// ============================================================================
// SECTION 7: RENDER STATE MANAGEMENT
// ============================================================================

// ----------------------------------------------------------------------------
// ENgcRenderer::ZTest(EDLEntry *)
// Address: 0x80345220, Size: 100 bytes
// ----------------------------------------------------------------------------
// Configures Z-buffer test from display list entry:
//   entry[1] = enable (u8): 0=disable, nonzero=enable
//   entry[2] = ref value (u8): not used as threshold, maps to compare func
//   entry[3] = compare func index (u8): indexes into GX compare function table
//
// Stores in renderer:
//   this+0x4644 = enable
//   this+0x4645 = ref
//   this+0x4646 = compare func index
//
// Updates RSC:
//   RSC+0x03AC = enable (0 or 1)
//   RSC+0x03B0 = GX compare function (looked up from table at 0x80421E08)
//   RSC+0x03B4 = write enable (1 if compare!=0, else 0)
//
// Sets dirty: RSC.dirtyFlags |= 0x80000040 (z/alpha test dirty)
//
// GX Compare function table (at 0x80421E08):
//   Index 0 → GX_NEVER  (0)
//   Index 1 → GX_LESS   (1)
//   Index 2 → GX_EQUAL  (2)
//   Index 3 → GX_LEQUAL (3)
//   Index 4 → GX_GREATER(4)
//   Index 5 → GX_NEQUAL (5)
//   Index 6 → GX_GEQUAL (6)
//   Index 7 → GX_ALWAYS (7)
//
// PC PORT:
//   if (enable) glEnable(GL_DEPTH_TEST); else glDisable(GL_DEPTH_TEST);
//   glDepthFunc(gl_compare_map[compareIndex]);
//   glDepthMask(writeEnable ? GL_TRUE : GL_FALSE);
//
void ENgcRenderer::ZTest(EDLEntry* entry)
{
    u8 enable = ((u8*)entry)[1];
    u8 ref    = ((u8*)entry)[2];
    u8 func   = ((u8*)entry)[3];

    this->m_field_4644 = enable;
    this->m_field_4645 = ref;
    this->m_field_4646 = func;

    u8 zEnable = (enable != 0) ? 1 : 0;
    u8 zWrite  = (func != 0) ? 1 : 0;

    ENgcRenderStateCache* rsc = this->m_geometryModes;
    u32 gxCompare = g_compareTable[ref]; // lookup from 0x80421E08

    rsc->zTestEnable = zEnable;
    rsc->zCompareFunc = gxCompare;
    rsc->zWriteEnable = zWrite;
    rsc->dirtyFlags |= 0x80000040;
}


// ----------------------------------------------------------------------------
// ENgcRenderer::AlphaTest(EDLEntry *)
// Address: 0x80345284, Size: 144 bytes
// ----------------------------------------------------------------------------
// Configures alpha test from display list entry:
//   entry[1] = enable (u8): 0=disable, nonzero=enable
//   entry[2] = compare func index (u8): indexes into GX compare table
//   entry[3] = reference value (u8): alpha threshold (0-255)
//
// When ENABLED:
//   RSC+0x03B8 = GX compare func (from table)
//   RSC+0x03BC = ref value
//   RSC+0x03C4 = GX_ALWAYS (7)
//   RSC+0x03C0 = 0 (GX_AOP_AND)
//   RSC+0x03C8 = 0 (not passthrough)
//   RSC+0x03C9 = 0
//
// When DISABLED:
//   RSC+0x03C4 = GX_ALWAYS (7)
//   RSC+0x03C9 = 1 (passthrough)
//   RSC+0x03C8 = 0
//   RSC+0x03B8 = GX_ALWAYS (7)
//   RSC+0x03BC = 0
//   RSC+0x03C0 = 1 (GX_AOP_OR)
//
// Sets dirty: RSC.dirtyFlags |= 0x80000040
//
// PC PORT:
//   if (enable) { glEnable(GL_ALPHA_TEST); glAlphaFunc(func, ref/255.0f); }
//   else { glDisable(GL_ALPHA_TEST); }
//   Note: GL_ALPHA_TEST is deprecated in GL 3.1+. Use discard in fragment shader.
//
void ENgcRenderer::AlphaTest(EDLEntry* entry)
{
    u8 enable = ((u8*)entry)[1];
    u8 func   = ((u8*)entry)[2];
    u8 ref    = ((u8*)entry)[3];

    ENgcRenderStateCache* rsc = this->m_geometryModes;

    if (enable != 0) {
        // Enable alpha test
        u32 gxFunc = g_compareTable[func];
        rsc->alphaCompare0 = gxFunc;
        rsc->alphaRef0     = ref;
        rsc->alphaCompare1 = GX_ALWAYS; // 7
        rsc->alphaOp       = GX_AOP_AND; // 0
        rsc->alphaPassthrough = 0;
        rsc->alphaTestFlag = 0;
    } else {
        // Disable alpha test (always pass)
        rsc->alphaCompare1 = GX_ALWAYS;
        rsc->alphaPassthrough = 1;
        rsc->alphaTestFlag = 0;
        rsc->alphaCompare0 = GX_ALWAYS;
        rsc->alphaRef0     = 0;
        rsc->alphaOp       = GX_AOP_OR; // 1
    }

    rsc->dirtyFlags |= 0x80000040;
}


// ----------------------------------------------------------------------------
// ENgcRenderer::SetBlendMode(EDLEntry *)
// Address: 0x80346124, Size: 56 bytes
// ----------------------------------------------------------------------------
// Unpacks blend mode from a 32-bit packed value in entry[4..7]:
//   bits 0-1:   blend src factor
//   bits 2-3:   blend dst factor
//   bits 4-5:   blend op
//   bits 6-7:   logic op
//   bits 24-31: alpha value (u8)
//
// Stores at:
//   this+0x0564 = src factor
//   this+0x0565 = dst factor
//   this+0x0566 = blend op
//   this+0x0567 = logic op
//   this+0x0568 = alpha
//   this+0x0510 = 1 (dirty)
//
// PC PORT:
//   glBlendFunc(src_map[srcFactor], dst_map[dstFactor]);
//   glBlendEquation(op_map[blendOp]);
//   // Logic op only used if blendOp selects it
//
void ENgcRenderer::SetBlendMode(EDLEntry* entry)
{
    u32 packed = *(u32*)((u8*)entry + 4);
    this->m_geometryModes_510 = 1; // dirty

    this->m_tEVStages_565 = (packed >> 2) & 0x3;  // dst
    this->m_tEVStages_564 = packed & 0x3;          // src
    this->m_tEVStages_566 = (packed >> 4) & 0x3;   // op
    this->m_tEVStages_567 = (packed >> 6) & 0x3;   // logic
    this->m_tEVStages_568 = (packed >> 24) & 0xFF;  // alpha
}


// ----------------------------------------------------------------------------
// ENgcRenderer::SetAlpha(float)
// Address: 0x80344714, Size: 16 bytes
// ----------------------------------------------------------------------------
// Simply stores the global alpha value and marks renderer dirty.
//
void ENgcRenderer::SetAlpha(float alpha)
{
    *(f32*)((u8*)this + 0x03A4) = alpha; // m_alpha
    this->m_geometryModes_510 = 1;       // dirty flag
}


// ----------------------------------------------------------------------------
// ENgcRenderer::Material(EDLEntry *)
// Address: 0x80345120, Size: 132 bytes
// ----------------------------------------------------------------------------
// Copies material data from the entry into three material color slots:
//   this+0x0518 = ambient color (4 floats from src+0x00)
//   this+0x0528 = diffuse color (4 floats from src+0x10)
//   this+0x0538 = specular + shininess (3 u32 from src+0x20, 1 float from src+0x2C)
//
// Sets this+0x0510 = 1 (dirty)
//
// PC PORT:
//   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
//   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
//   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
//   Or use uniform buffer for material parameters in modern GL.
//


// ============================================================================
// SECTION 8: GEOMETRY MODE AND STATE FLAGS
// ============================================================================

// ----------------------------------------------------------------------------
// ENgcRenderer::EnableGeometryModes(EDLEntry *)
// Address: 0x80344598, Size: 88 bytes
// ----------------------------------------------------------------------------
// ORs geometry mode flags from the entry into the RSC geometry mode field.
// Then checks specific bits to determine cull mode:
//   bit 2 (0x04) set → cull mode = GX_CULL_FRONT (1)
//   bit 1 (0x02) set → cull mode = GX_CULL_BACK (2)
// Stores cull mode at RSC+0x079C.
// Sets dirty: RSC.dirtyFlags |= 0x80000000 and this+0x0510 = 1
//
// PC PORT:
//   if (flags & 0x04) glCullFace(GL_FRONT);
//   else if (flags & 0x02) glCullFace(GL_BACK);
//   if (flags & (0x02|0x04)) glEnable(GL_CULL_FACE);
//
void ENgcRenderer::EnableGeometryModes(EDLEntry* entry)
{
    u32 flags = *(u32*)((u8*)entry + 4);
    ENgcRenderStateCache* rsc = this->m_geometryModes;

    rsc->dirtyFlags |= 0x80000000;
    rsc->geometryModeFlags |= flags; // RSC+0x06E8

    u32 geoFlags = rsc->geometryModeFlags;
    u32 cullMode = 0;
    if (geoFlags & 0x04) {
        cullMode = 1; // GX_CULL_FRONT
    } else if (geoFlags & 0x02) {
        cullMode = 2; // GX_CULL_BACK
    }
    rsc->cullMode = cullMode;

    this->m_geometryModes_510 = 1;
}


// ----------------------------------------------------------------------------
// ENgcRenderer::SaveState(EDLEntry *)  /  RestoreState(EDLEntry *)
// Address: 0x80343D94 / 0x80343DB8, Size: 36 each
// ----------------------------------------------------------------------------
// Delegate to ENgcRenderStateCache_Save / ENgcRenderStateCache_Restore.
// The RSC maintains a stack of render states for nested rendering
// (e.g., rendering into a texture, then restoring main state).
//
// PC PORT: Push/pop OpenGL state, or maintain a state stack manually.
//
void ENgcRenderer::SaveState(EDLEntry*) {
    ENgcRenderStateCache_Save(this->m_geometryModes);
}

void ENgcRenderer::RestoreState(EDLEntry*) {
    ENgcRenderStateCache_Restore(this->m_geometryModes);
}


// ============================================================================
// SECTION 9: TEXTURE MANAGEMENT
// ============================================================================

// ----------------------------------------------------------------------------
// ENgcRenderer::SetTexture(ENgcTexture *, int)
// Address: 0x8034447C, Size: 284 bytes
// ----------------------------------------------------------------------------
// Binds a texture to a slot (0-based index):
//   1. If a texture was already bound to this slot, calls its Unbind method
//      via vtable dispatch (entry+0x24 → vtable → offset 0x20)
//   2. Updates texture reference count:
//      - If setting non-NULL where NULL was: m_textureCount++ (at this+0x4634)
//      - If setting NULL where non-NULL was: m_textureCount--
//   3. Stores texture pointer in this->m_textures[slot] (at this+0x4638 + slot*4)
//   4. If texture is non-NULL:
//      - Iterates through slots 0..slot-1 to count active texture coordinate gens
//      - Calls texture's Bind method via vtable (entry+0x24 → vtable → offset 0x18)
//      - Calls texture's SetupTexGen method (offset 0x90 in vtable)
//
// PC PORT:
//   glActiveTexture(GL_TEXTURE0 + slot);
//   glBindTexture(GL_TEXTURE_2D, textureId);
//
void ENgcRenderer::SetTexture(ENgcTexture* tex, int slot)
{
    ENgcTexture* oldTex = this->m_textures[slot];

    // Unbind old texture
    if (oldTex != NULL) {
        oldTex->Unbind(); // vtable call
    }

    // Update reference count
    if (tex != NULL && oldTex == NULL) {
        this->m_textureCount++;
    } else if (tex == NULL && oldTex != NULL) {
        if (this->m_textureCount > 0) {
            this->m_textureCount--;
        }
    }

    // Store new texture
    this->m_textures[slot] = tex;

    if (tex != NULL) {
        // Count active texcoord gens before this slot
        int texGenCount = 0;
        for (int i = 0; i < slot; i++) {
            if (this->m_textures[i] != NULL) {
                texGenCount += tex->GetTexGenCount(); // vtable call
            }
        }

        // Bind and configure
        tex->Bind();           // vtable call
        tex->SetupTexGen(slot, texGenCount); // vtable call
    }
}

// ----------------------------------------------------------------------------
// ENgcRenderer::GetCurrentTexture(int)
// Address: 0x8033B724, Size: 16 bytes
// ----------------------------------------------------------------------------
// Returns the texture pointer for the given slot.
//   return this->m_textures[slot]; // at this+0x4638 + slot*4
//
void* ENgcRenderer::GetCurrentTexture(int slot)
{
    return *((void**)((u8*)this + 0x4638) + slot);
}


// ============================================================================
// SECTION 10: ACCESSORS AND SIMPLE GETTERS
// ============================================================================

// ENgcRenderer::GetRenderStateCache(void)
// Address: 0x80349F3C, Size: 8
ENgcRenderStateCache* ENgcRenderer::GetRenderStateCache(void)
{
    return (ENgcRenderStateCache*)*(u32*)((u8*)this + 0x04D8);
}

// ENgcRenderer::GetNextExternalFrameBuffer(void)
// Address: 0x80349F44, Size: 8
void* ENgcRenderer::GetNextExternalFrameBuffer(void)
{
    return *(void**)((u8*)this + 0x034C);
}

// ENgcRenderer::GetFrameEffectsScratchMemory(void)
// Address: 0x80349FD4, Size: 8
void* ENgcRenderer::GetFrameEffectsScratchMemory(void)
{
    return *(void**)((u8*)this + 0x464C);
}

// ENgcRenderer::GetExternalFrameBuffer(void)
// Address: 0x8033CA98, Size: 32
// Returns the framebuffer not currently being rendered to
void* ENgcRenderer::GetExternalFrameBuffer(void)
{
    void* fb0 = *(void**)((u8*)this + 0x0344);
    void* nextXFB = *(void**)((u8*)this + 0x034C);
    if (nextXFB != fb0) {
        return fb0;
    }
    return *(void**)((u8*)this + 0x0348);
}

// ENgcRenderer::GetRenderMode(void)
// Address: 0x8034A51C, Size: 28
// Returns pointer to render mode struct, or NULL if no framebuffer
void* ENgcRenderer::GetRenderMode(void)
{
    if (*(void**)((u8*)this + 0x034C) == NULL) {
        return NULL;
    }
    return (void*)((u8*)this + 0x0364);
}

// ENgcRenderer::GetCurrentRenderMode(void)
// Address: 0x80349F6C, Size: 104
// Copies 60 bytes of render mode data from this+0x0364 to output struct
// Uses unrolled memcpy (24 bytes at a time, then 12 bytes tail)
void ENgcRenderer::GetCurrentRenderMode(void* output)
{
    // memcpy(output, (u8*)this + 0x0364, 60);
    // Unrolled: copy 24 bytes x2, then 12 bytes
}

// ENgcRenderer::GetZTestSettings(u8&, u8&, u8&)
// Address: 0x8034A538, Size: 28
void ENgcRenderer::GetZTestSettings(u8& compare, u8& ref, u8& enable)
{
    compare = *(u8*)((u8*)this + 0x4644);
    ref     = *(u8*)((u8*)this + 0x4645);
    enable  = *(u8*)((u8*)this + 0x4646);
}

// ENgcRenderer::GetPreviousFrameBuffer(int*, int*)
// Address: 0x80349F4C, Size: 32
// Returns half-resolution dimensions and previous framebuffer pointer
void* ENgcRenderer::GetPreviousFrameBuffer(int* outWidth, int* outHeight)
{
    *outWidth  = *(u16*)((u8*)this + 0x0368) >> 1;
    *outHeight = *(u16*)((u8*)this + 0x036A) >> 1;
    return *(void**)((u8*)this + 0x4650);
}


// ============================================================================
// SECTION 11: STUB / UNIMPLEMENTED HANDLERS
// ============================================================================

// These handlers exist in the jump table but do nothing or just
// clear a "warned once" flag. They represent PS2/Xbox features
// not used on GameCube. Each follows the same pattern:
//
//   void Handler(EDLEntry*) {
//       if (g_warnedOnce_Handler != 0) {
//           return;
//       }
//       g_warnedOnce_Handler = 0; // clear to suppress future warnings
//   }
//
// Stub handlers (all at 0x8034A6xx range, 24 bytes each):
//   TriFan, TriList, LineStrip, PointList, SpriteList,
//   SendGSDisplayList, CallbackParam, Callback, GEList,
//   RecalcMatrices, SetMipMap, VerifyMpg, ParticleList,
//   ParticleListRot, LineStreakList, SetAlpha(EDLEntry*),
//   CopyScreenToTexture

// Empty stubs (4 bytes = blr):
void ENgcRenderer::ShowPerfGraphs(bool) { /* empty */ }
void ENgcRenderer::TextureMatrix(EDLEntry*) { /* empty */ }
void ENgcRenderer::NoOp(EDLEntry*) { /* empty */ }
void ENgcRenderer::VIPostRetraceCallback(unsigned long) { /* empty */ }


// ============================================================================
// SECTION 12: DISPLAY LIST COMMANDS (Goto/End/DisplayList)
// ============================================================================

// ENgcRenderer::Goto(EDLEntry*)
// Address: 0x80343D54, Size: 12
// Sets the current DL pointer to the entry's param
void ENgcRenderer::Goto(EDLEntry* entry)
{
    this->m_field_4DC = *(u32*)((u8*)entry + 4);
}

// ENgcRenderer::End(EDLEntry*)
// Address: 0x80343D60, Size: 52
// Pops the display list stack. If stack is empty, sets overflow flag
// to stop Execute() loop.
void ENgcRenderer::End(EDLEntry*)
{
    u32 stackPtr = *(u32*)((u8*)this + 0x050C); // m_dlStackPtr
    if (stackPtr != 0) {
        stackPtr--;
        *(u32*)((u8*)this + 0x050C) = stackPtr;
        u32* stack = (u32*)((u8*)this + 0x04E4); // m_dlStack
        *(u32*)((u8*)this + 0x04DC) = stack[stackPtr]; // restore DL pointer
    } else {
        *(u32*)((u8*)this + 0x04E0) = 1; // m_overflow = 1 → stop Execute
    }
}

// ENgcRenderer::DisplayList(EDLEntry*)
// Address: 0x80343D24, Size: 48
// Pushes current DL pointer onto stack, switches to new display list.
void ENgcRenderer::DisplayList(EDLEntry* entry)
{
    u32 stackPtr = *(u32*)((u8*)this + 0x050C);
    u32* stack = (u32*)((u8*)this + 0x04E4);
    stack[stackPtr] = *(u32*)((u8*)this + 0x04DC); // save current
    *(u32*)((u8*)this + 0x050C) = stackPtr + 1;

    void* dl = *(void**)((u8*)entry + 4);
    *(void**)((u8*)this + 0x4640) = dl; // m_currentDL
    *(u32*)((u8*)this + 0x04DC) = *(u32*)((u8*)dl + 0x48); // DL command start
}


// ============================================================================
// SECTION 13: MUTEX / SYNCHRONIZATION
// ============================================================================

// ENgcRenderer::AcquireCopyMutex(void)
// Address: 0x8034A554, Size: 64
// Acquires the copy protection mutex (s_copyMutex at 0x804D9B20).
// Uses virtual dispatch through the mutex's vtable.
void ENgcRenderer::AcquireCopyMutex(void)
{
    // s_copyMutex is at a fixed BSS address
    // Virtual call: s_copyMutex.Lock(-1) // wait forever
    OSMutex* mutex = &s_copyMutex;
    mutex->vtable->Lock(mutex, -1);
}

// ENgcRenderer::ReleaseCopyMutex(void)
// Address: 0x8034A594, Size: 60
// Releases the copy protection mutex.
void ENgcRenderer::ReleaseCopyMutex(void)
{
    OSMutex* mutex = &s_copyMutex;
    mutex->vtable->Unlock(mutex);
}


// ============================================================================
// SECTION 14: CALLBACKS
// ============================================================================

// ENgcRenderer::DrawSyncCallback(unsigned short token)
// Address: 0x8033CE20, Size: 8
// Called by GX when a draw sync token is reached.
// Simply stores the token for the main thread to poll.
void ENgcRenderer::DrawSyncCallback(unsigned short token)
{
    s_lastTokenFromGX = token; // at 0x804FF2F6
}

// ENgcRenderer::AddDrawSync(void)
// Address: 0x8033CE28, Size: 52
// Sends a draw sync token to GX and increments the token counter.
void ENgcRenderer::AddDrawSync(void)
{
    s_lastTokenToGX++;
    GXSetDrawSync(s_lastTokenToGX);
}


// ============================================================================
// SECTION 15: FLUSH AND QUEUE COMMANDS
// ============================================================================

// ENgcRenderer::Flush(void)
// Address: 0x8033E8BC, Size: 44
// Queues a flush command (type=5) and processes it immediately.
void ENgcRenderer::Flush(void)
{
    ENgcRendCommandData cmd;
    cmd.type = 5; // REND_CMD_FLUSH
    Flush((ENgcRendCommand*)&cmd);
}

// ENgcRenderer::Flush(ENgcRendCommand*)
// Address: 0x8033ECB8, Size: 32
// Calls GXDrawDone() to synchronize GPU and CPU.
void ENgcRenderer::Flush(ENgcRendCommand* cmd)
{
    GXDrawDone(); // bl 0x8038B0A8
}


// ============================================================================
// SECTION 16: PushAndClearViewport / RestoreViewport
// ============================================================================

// ENgcRenderer::PushAndClearViewport(void)
// Address: 0x8033ECD8, Size: 240
// Saves current viewport state and sets up a full-screen viewport.
// Used before rendering effects, UI overlays, or post-processing.
//
// Sets RSC viewport to cover the full render target:
//   x = 0, y = 0
//   w = renderWidth (from this+0x0372)
//   h = renderHeight (from this+0x0374)
//   near = 0.0, far = 1.0
//   scissor = full screen
//
// Sets dirty: RSC.dirtyFlags |= 0x80000600 (viewport + scissor)
//
void ENgcRenderer::PushAndClearViewport(void)
{
    ENgcRenderStateCache* rsc = this->m_geometryModes;
    ENgcRenderStateCache_Save(rsc); // push current state

    // Set full-screen viewport
    rsc->viewport_x = 0.0f;
    rsc->viewport_y = 0.0f;
    rsc->viewport_w = (float)this->m_field_372;
    rsc->viewport_h = (float)this->m_field_374;
    rsc->viewport_near = 0.0f;
    rsc->viewport_far  = 1.0f;

    // Set full-screen scissor
    rsc->scissor_x = 0;
    rsc->scissor_y = 0;
    rsc->scissor_w = this->m_field_372;
    rsc->scissor_h = this->m_field_374;

    rsc->dirtyFlags |= 0x80000600;
}

// ENgcRenderer::RestoreViewport(void)
// Address: 0x8033EDC8, Size: 36
// Restores the viewport state saved by PushAndClearViewport.
void ENgcRenderer::RestoreViewport(void)
{
    ENgcRenderStateCache* rsc = this->m_geometryModes;
    ENgcRenderStateCache_Restore(rsc);
}


// ============================================================================
// SECTION 17: GX INTEGRATION PATTERNS SUMMARY
// ============================================================================
//
// PATTERN 1: Deferred State Application
// ------------------------------------
// The renderer never calls GX functions directly from state-setting commands.
// Instead, it sets fields in the ENgcRenderStateCache and marks dirty bits.
// Before each draw call, UpdateTEVStages() and UpdateLightingEquation()
// flush all dirty state to GX hardware. This batches state changes.
//
//   setState:  rsc->field = value;  rsc->dirtyFlags |= bit;
//   drawCall:  if (rsc->dirtyFlags) FlushState(rsc);  GXBegin(...);
//
// PC PORT: Same pattern maps well to modern GL/Vulkan.
// Accumulate state changes, then bind pipeline/descriptors before draw.
//
//
// PATTERN 2: FIFO Direct Writes (0xCC008000)
// -------------------------------------------
// Some functions (ClearRect, particle rendering) write vertex data
// directly to the GX command processor FIFO via memory-mapped I/O.
// Address 0xCC008000 is the GX Write Gather Pipe.
//
//   *(float*)0xCC008000 = position_x;  // GX_Position3f32 equivalent
//   *(float*)0xCC008000 = position_y;
//   *(float*)0xCC008000 = position_z;
//   *(u8*)0xCC008000 = color_r;        // GX_Color4u8 equivalent
//   ...
//
// PC PORT: Replace with glVertex3f/glColor4ub (legacy) or
// fill a VBO and call glDrawArrays (modern).
//
//
// PATTERN 3: Dirty Flag Bitmask
// ----------------------------
// RSC+0x06CC holds a 32-bit dirty flag bitmask.
// Bit 31 (0x80000000) is always set when ANY state changes.
// Lower bits indicate which specific subsystems need flushing.
// The flush function tests each bit and calls the appropriate
// GX function (GXSetViewport, GXSetScissor, GXSetZMode, etc.).
//
//
// PATTERN 4: Integer-to-Float Conversion Trick
// --------------------------------------------
// The game frequently converts u16 integers to floats using:
//   *(u32*)(stack+4) = intValue ^ 0x80000000;
//   *(u32*)(stack+0) = 0x43300000;
//   double temp = *(double*)(stack+0);
//   float result = (float)(temp - 4503599627370496.0); // 0x4330000080000000
//
// This is a well-known PowerPC trick for integer→float conversion
// that avoids the expensive fctiw instruction.
// PC PORT: Just use (float)intValue — x86 has efficient cvtsi2ss.
//
//
// PATTERN 5: Render Command Queue
// --------------------------------
// High-level rendering commands (BeginFrame, EndFrame, Swap, Flush,
// DisplayList) go through a command queue:
//   QueueBeginFrame → builds command struct → calls BeginFrame
//   QueueEndFrame   → builds command struct → calls EndFrame
//   etc.
//
// On GameCube this is single-threaded (commands execute immediately).
// The queue infrastructure exists for potential multi-threaded rendering
// (which is partially implemented but controlled by a global flag).
//
// PC PORT: This maps naturally to a command buffer / render graph.
//

#endif // DECOMP ANALYSIS
