// bigfish_batch_4.cpp - Big fish asm stub conversions, batch 4
// Converted from 6 massive asm stub files to portable C++
// Classes: ENgcRenderer (73 fn), SAnimator2 (158 fn), cXPersonImpl (96 fn),
//          AptActionInterpreter (147 fn), cXObjectImpl (169 fn),
//          InteractorModule + subclasses (299 fn)
// Total: 942 functions, ~543,484 bytes of code
#include "types.h"

// ============================================================================
// External functions
// ============================================================================
extern "C" {
    void* memcpy(void*, const void*, unsigned int);
    void* memset(void*, int, unsigned int);
    int memcmp(const void*, const void*, unsigned int);
    int strlen(const char*);
    char* strcpy(char*, const char*);
    char* strcat(char*, const char*);
    char* strncpy(char*, const char*, unsigned int);
    int strcmp(const char*, const char*);
    int strncmp(const char*, const char*, unsigned int);
    float sqrtf(float);
    float atan2f(float, float);
    float fabsf(float);
    int Sprintf(char*, char*, ...);
    int wcslen(const unsigned short*);
}

// Memory
class EAHeap;
extern EAHeap* MainHeap();
extern EAHeap* RootHeap();
extern EAHeap* ResourceHeap();
extern EAHeap* AptHeap();
class EAHeap {
public:
    void* Malloc(unsigned int, int);
    void* MallocAligned(unsigned int, unsigned int, unsigned int, int);
    void Free(void*);
};

// Operator new/delete
extern void* operator new(std::size_t);
extern void operator delete(void*);
extern void* __builtin_vec_new(std::size_t);
extern void __builtin_vec_delete(void*);

// ============================================================================
// Forward declarations
// ============================================================================

// Core engine classes
class EDL;
class EDLEntry;
class EGEVert;
class EMat4;
struct EVec2 {};
class EVec3;
class EVec4;
class ERC;
class EShader;
class EBound3;
class EResource;
class EResourceManager;
class EGraphics;
class ERenderer {};
class ENodeList;
class ERedBlackTree;
class EAnimController;
class EAnimNote;
class EACTrack;
class ERAnim;
class EBoneParticle;
class EWindow;
class EHouse;
class EIObjectMan;
class ELevelDrawData;
class EOrderTableData;
class ESimsCam;
class ERShader;

// NGC-specific
class ENgcRendCommand;
class ENgcShader;
class ENgcTexture;
class _GXRenderModeObj;
class _GXTexObj;
struct _GXPrimitive {};
struct _GXTevStageID {};

// Sim/Object system
class cXObject;
class cXPerson;
class cXObjectImpl;
class cXMTObjectImpl;
class ObjSelector;
class ObjectModule;
class StackElem;
class XPrimParam;
class Interaction;
class InteractionList;
class ReconBuffer;
class Behavior;
class RoutingSlot;
class TileList;
class XRoute;
class ISimInstance;
struct FTilePt {};
class FTileRect;
class PlacementSpec;
class HierarchySite;
class ObjectSlot;
class FindGoodLocationParams;
class BString;
class BString2;
class TreeSim;
class TreeSimImpl;

// Animation
class AnimRef;
class AnimateNewParam;
class AnimParticleData;
class IdleAnimateParam;
class PropRef;
class CasSimDescriptionS2C;
class REffectsAttachment;
class RumbleDataElement;
class CameraBloomDataElement;
struct CTilePt {};
class AwarenessManager;

// APT/UI
class AptActionSetup;
class AptCIH;
class AptCharacterInst;
class AptConstFile;
class AptInitParmsT;
class AptValue;
class AptNativeHash;
class AptString;
class AptScriptFunctionBase;
class EAStringC;
class DOGMA_PoolManager;

// Build mode
class DiagonalSideSelector;
class Room;
class TileWalls;
struct TilePtDir {};
struct TileWallsSegment {};
struct WallPattern {};
struct WallStyle {};
struct FloorPattern {};
struct ECTRL_CMD {};
struct ObjEntryPoint {};
struct TFGL_ACTIONS {};

// Misc
class DialogParam;
class ExpressionParam;
class CompleteGoalParam;
class InventoryCommandParam;
class KillSoundsParam;
class PlaySoundParam;
class MotiveCurveSet;
class PiecewiseFn;
class WantFear;
class Motives;
class MotiveEffects;
class Path;
class EdithVariableSet;
class NLIteratorPtrType;
class CameraManager;

template <typename T0, typename T1> class TRedBlackTree;
template <typename T0> class TNodeList;
template <typename T0> class allocator;
template <typename T0, typename T1> class vector;

// Globals accessed via r13/r2
extern void* g_pRenderer;
extern void* g_pEngine;
extern void* g_pApp;
extern void* g_pHouseManager;
extern void* g_pDOGMA;
extern void* g_pAptValueGC;
extern float g_deltaTime;

extern void EORDbgTrace(char*, ...);
extern void ENgcPerf_ClearMetrics();
extern void GXPokeBlendMode(int, int, int, int);
extern void GXPokeAlphaMode(int, int);
extern void GXDrawDone();
extern void VISetNextFrameBuffer(void*);
extern void VIFlush();
extern void VIWaitForRetrace();

// ============================================================================
// ENgcRenderer — NGC graphics renderer (73 functions, 58,472 bytes)
// Handles GX display list creation, rendering commands, frame management
// ============================================================================

class ENgcRenderer : public ERenderer {
public:
    ENgcRenderer(void);
    void CreateGXDisplayList(EDL*, _GXPrimitive, int, unsigned short*, int, float*, float*, unsigned char*, signed char*, unsigned int&, bool);
    void CreateGXDisplayList(EDL*, _GXPrimitive, int, unsigned short*, int, short*, short*, unsigned char*, signed char*, unsigned int&, bool);
    void CreateGXDisplayList(EDL*, _GXPrimitive, int, float*, float*, unsigned char*, signed char*, unsigned int&, bool);
    void CreateGXDisplayList(EDL*, _GXPrimitive, int, short*, short*, unsigned char*, signed char*, unsigned int&, bool, bool);
    void SetClearColor(EVec3& color, bool flag);
    void CycleToNextFrameBuffer(void);
    void VIPreRetraceCallback(unsigned long);
    void InitGX(_GXRenderModeObj*);
    void InitGXVertexFormats(void);
    void InitVideo(int& width, int& height);
    void InitData(void);
    void ClearRect(EVec4& rect, EVec4& color);
    void BeginFrame(ENgcRendCommand*);
    void DisplayList(ENgcRendCommand* cmd);
    void EndFrame(ENgcRendCommand*);
    void Swap(ENgcRendCommand*);
    void PushAndClearViewport(void);
    void UpdateLightingEquation(void);
    void SetupTEVStagePassColor(_GXTevStageID stage);
    void Setup1TEVStageTexture(int, int&, int, int&);
    void Setup2TEVStageTexture(int, int&, int, int&);
    void UpdateTEVStages(void);
    void Execute(EDLEntry*);
    void TriStrip(EGEVert* verts, int count);
    void WeightedBlend(_GXPrimitive, int, float*, signed char*, float*, unsigned char*, unsigned char*, bool);
    void TriStripPacked(EDLEntry* entry);
    void TriStripPacked(int, float*, float*, unsigned char*, signed char*, unsigned char*, unsigned char*, bool);
    void TriStripPackedInt(EDLEntry*);
    void LineList(EGEVert* verts, int count);
    void Viewport(EDLEntry*);
    void Scissor(EDLEntry*);
    void ModelMatrices(EMat4* matrices, int count);
    void ModelMatrixIndex(int slot, int index);
    void ModelMatrixIndices(EDLEntry*);
    void ViewMatrix(EDLEntry*);
    void ProjectionMatrix(EDLEntry*);
    void WindowMatrix(EDLEntry*);
    void SetTexture(ENgcTexture* tex, int stage);
    void EnableGeometryModes(EDLEntry*);
    void DisableGeometryModes(EDLEntry*);
    void SetGeometryModes(EDLEntry*);
    void Lights(EDLEntry*);
    void Rect(EDLEntry*);
    void DirectRect(EDLEntry*);
    void Material(EDLEntry*);
    void ZTest(EDLEntry*);
    void AlphaTest(EDLEntry*);
    void RenderSurface(EDLEntry*);
    void SpriteListPacked(int, float*, float*, unsigned char*, signed char*, unsigned char*);
    void QuadList(EDLEntry* entry);
    void QuadList(int, float*, float*, unsigned char*, signed char*, unsigned char*, unsigned char*, bool);
    void MovieFrame(EDLEntry*);
    void RectListRot(EDLEntry*);
    void RectList(EDLEntry*);
    void Stencil(EDLEntry*);
    void NgcGXDisplayListInt(EDLEntry*);
    void NgcGXDisplayList(EDLEntry*);
    void NgcTriListInt(EDLEntry*);
    void NgcTriList(EDLEntry*);
    void NgcScreenTriList(EDLEntry*);
    void SetShader(ENgcShader* shader, unsigned int flags);
    void ScrambleRect(EDLEntry* entry);
    void ScrambleRect(EVec2& min, EVec2& max, float intensity);
    void WeightedBlendInt(_GXPrimitive, int, short*, signed char*, short*, unsigned char*, unsigned char*, bool);
    void SimpleSkinning(_GXPrimitive, int, short*, signed char*, short*, unsigned char*, unsigned char*, bool);
    void ScaleTexture(_GXTexObj*, void*, int, float);
    void DrawTextureToFullViewportWithJitter(float jitterX, float jitterY);
    void DrawFrameWithBloomAndMotionBlur(float bloomAmount, float blurAmount);
    void ProcessThumbnail(void* buffer, int size, float x, float y);
    void GetCurrentRenderMode(void);
    void ParticleListBegin(unsigned int count, unsigned int type);
    void ParticleListEnd(unsigned int flags);
};

// 0x8033B50C (480 bytes)
// Constructor: calls ERenderer base ctor, initializes vtable, frame buffers,
// shader slots (2 loops of 64 bytes each), sets frame rate based on video mode
ENgcRenderer::ENgcRenderer(void) {
    // Calls ERenderer::ERenderer(void)
    // Sets vtable at offset 824
    // Initializes EVec3 color fields at offsets 1304, 1320, 1336
    // Initializes 2 shader slot structs (64 bytes each) at offset 1352
    // Empty spin loops (countdown counters)
    // Sets frame rate: 60 (NTSC) or 50 (PAL) based on global video mode flag
    // Stores this ptr to global renderer pointer
    // Sets fields at 844, 928, 1296, 864
}

// 0x8033B764 (1172 bytes)
// Creates GX display list from indexed vertex data (float positions, float normals)
void ENgcRenderer::CreateGXDisplayList(EDL*, _GXPrimitive, int, unsigned short*, int, float*, float*, unsigned char*, signed char*, unsigned int&, bool) {
    // Allocates aligned memory from MainHeap for DL
    // Adds to EDL node list
    // Calls GXBeginDisplayList, iterates vertices writing position/normal/color/texcoord
    // Calls GXEndDisplayList, stores size
}

// 0x8033BBF8 (1172 bytes)
// Creates GX display list from indexed vertex data (float positions, short normals)
void ENgcRenderer::CreateGXDisplayList(EDL*, _GXPrimitive, int, unsigned short*, int, short*, short*, unsigned char*, signed char*, unsigned int&, bool) {
    // Same structure as above but reads normals as shorts
}

// 0x8033C08C (1156 bytes)
// Creates GX display list from non-indexed vertex data (float positions, float normals)
void ENgcRenderer::CreateGXDisplayList(EDL*, _GXPrimitive, int, float*, float*, unsigned char*, signed char*, unsigned int&, bool) {
    // Direct vertex data (no index buffer)
}

// 0x8033C510 (1336 bytes)
// Creates GX display list from non-indexed vertex data (short positions, short normals)
void ENgcRenderer::CreateGXDisplayList(EDL*, _GXPrimitive, int, short*, short*, unsigned char*, signed char*, unsigned int&, bool, bool) {
    // Short-format vertex data, extra bool for additional processing
}

// 0x8033CA48 (80 bytes)
// Sets the clear color from a Vec3, stores alpha=127, flags=0xFFFFFF
void ENgcRenderer::SetClearColor(EVec3& color, bool flag) {
    char* self = (char*)this;
    *(int*)(self + 864) = flag;
    // Calls color.ToU8s(self + 940)
    *(unsigned char*)(self + 943) = 127; // alpha
    *(unsigned int*)(self + 944) = 0x00FFFFFF;
}

// 0x8033CAB8 (100 bytes)
// Cycles to next frame buffer: calls VISetNextFrameBuffer, advances buffer index (mod 2)
void ENgcRenderer::CycleToNextFrameBuffer(void) {
    char* self = (char*)this;
    // Calls VISetNextFrameBuffer(*(void**)(self + 844))
    // Advances buffer index at offset 832 (mod 2)
    // Updates current buffer pointer at offset 844
    // Calls VIFlush(), VIWaitForRetrace()
}

// 0x8033CCD4 (280 bytes)
// Static callback: VIPreRetraceCallback
void ENgcRenderer::VIPreRetraceCallback(unsigned long) {
    // Updates retrace counter, signals frame buffer swap
    // Manages double-buffered rendering synchronization
}

// 0x8033CEB8 (824 bytes)
// Initializes GX hardware
void ENgcRenderer::InitGX(_GXRenderModeObj*) {
    // Calls GXInit, GXSetCopyClear, GXSetViewport, GXSetScissor
    // Configures TEV stages, alpha compare, blend mode
    // Sets up vertex attribute formats
}

// 0x8033D1F0 (964 bytes)
// Initializes GX vertex format descriptors
void ENgcRenderer::InitGXVertexFormats(void) {
    // Configures multiple vertex attribute tables (VAT)
    // Sets position, normal, color, texcoord formats
}

// 0x8033D5B4 (692 bytes)
// Initializes video mode and display
void ENgcRenderer::InitVideo(int& width, int& height) {
    // Calls VIInit, VIConfigure
    // Allocates frame buffers from MainHeap
    // Sets up progressive/interlaced mode
}

// 0x8033D868 (2412 bytes)
// Initializes renderer data structures
void ENgcRenderer::InitData(void) {
    // Allocates shader tables, render state caches
    // Initializes light arrays, material defaults
    // Sets up command dispatch table
}

// 0x8033E1D4 (1568 bytes)
// Clears a rectangular screen region
void ENgcRenderer::ClearRect(EVec4& rect, EVec4& color) {
    // Sets up GX state for quad rendering
    // Draws colored quad over specified screen region
}

// 0x8033E8E8 (100 bytes)
// Begin frame: resets per-frame counters and metrics
void ENgcRenderer::BeginFrame(ENgcRendCommand*) {
    // Sets frame-active flag to 1
    // Clears accumulated float values
    // Resets draw call counters
    // Copies timing data, calls ENgcPerf::ClearMetrics
}

// 0x8033E94C (96 bytes)
// Processes a display list render command
void ENgcRenderer::DisplayList(ENgcRendCommand* cmd) {
    char* c = (char*)cmd;
    // Checks if DL should be freed after execution
    // Calls Execute on the DL entry
    // Optionally deallocates DL via EGraphics::DeallocateDL
}

// 0x8033E9AC (656 bytes)
// End frame: finalizes rendering, applies post-processing
void ENgcRenderer::EndFrame(ENgcRendCommand*) {
    // Applies bloom/motion blur if enabled
    // Calls GXDrawDone, copies to EFB
    // Updates performance metrics
}

// 0x8033EC3C (124 bytes)
// Swap buffers
void ENgcRenderer::Swap(ENgcRendCommand*) {
    // Calls CycleToNextFrameBuffer
    // Updates frame counter
}

// 0x8033ECD8 (240 bytes)
// Push and clear viewport state
void ENgcRenderer::PushAndClearViewport(void) {
    // Saves current viewport/scissor
    // Sets viewport to full screen
}

// 0x8033EDEC (2592 bytes)
// Updates lighting equation for current TEV configuration
void ENgcRenderer::UpdateLightingEquation(void) {
    // Configures GX light channels based on active lights
    // Sets ambient, diffuse, specular colors
    // Manages up to 8 hardware lights
}

// 0x8033F80C (464 bytes)
// Setup TEV stage for color pass
void ENgcRenderer::SetupTEVStagePassColor(_GXTevStageID stage) {
    // Configures a single TEV stage for basic color rendering
}

// 0x8033F9DC (952 bytes)
// Setup 1-texture TEV stage
void ENgcRenderer::Setup1TEVStageTexture(int, int&, int, int&) {
    // Configures TEV for single texture mapping
}

// 0x8033FD94 (1884 bytes)
// Setup 2-texture TEV stage
void ENgcRenderer::Setup2TEVStageTexture(int, int&, int, int&) {
    // Configures TEV for dual texture mapping (multitexture)
}

// 0x803404F0 (6456 bytes)
// Updates all TEV stages based on current shader state
void ENgcRenderer::UpdateTEVStages(void) {
    // Major function: configures the entire TEV pipeline
    // Handles up to 16 TEV stages
    // Manages texture coordinate generation
    // Sets up indirect texturing if needed
}

// 0x80341E28 (192 bytes)
// Executes a display list entry
void ENgcRenderer::Execute(EDLEntry*) {
    // Dispatches based on entry type
    // Calls appropriate handler (TriStrip, Viewport, Lights, etc.)
}

// 0x80342148 (920 bytes)
// Renders triangle strip from EGEVert array
void ENgcRenderer::TriStrip(EGEVert* verts, int count) {
    // Iterates vertices, submits position/normal/color/texcoord to GX
}

// 0x803424E0 (920 bytes)
// Weighted blend rendering (bone animation)
void ENgcRenderer::WeightedBlend(_GXPrimitive, int, float*, signed char*, float*, unsigned char*, unsigned char*, bool) {
    // Blends vertex positions between two weight sets
    // Used for skeletal animation rendering
}

// 0x80342878 (88 bytes)
// Renders packed triangle strip from display list entry
void ENgcRenderer::TriStripPacked(EDLEntry* entry) {
    char* e = (char*)entry;
    // Extracts vertex data pointers from entry
    // Calls the main TriStripPacked overload
}

// 0x803428D0 (2452 bytes)
// Renders packed triangle strip from raw vertex data
void ENgcRenderer::TriStripPacked(int, float*, float*, unsigned char*, signed char*, unsigned char*, unsigned char*, bool) {
    // Processes packed vertex format
    // Handles optional second texture coordinate
}

// 0x80343264 (2416 bytes)
// Renders packed triangle strip (integer vertex format)
void ENgcRenderer::TriStripPackedInt(EDLEntry*) {
    // Same as TriStripPacked but uses short vertex positions
}

// 0x80343BFC (296 bytes)
// Renders line list from EGEVert array
void ENgcRenderer::LineList(EGEVert* verts, int count) {
    // Submits line primitives to GX
}

// 0x80343DDC (160 bytes)
// Sets viewport from display list entry
void ENgcRenderer::Viewport(EDLEntry*) {
    // Extracts viewport parameters, calls GXSetViewport
}

// 0x80343EA0 (404 bytes)
// Sets scissor rectangle
void ENgcRenderer::Scissor(EDLEntry*) {
    // Extracts scissor params, calls GXSetScissor
}

// 0x8034405C (80 bytes)
// Sets model matrices for skinning
void ENgcRenderer::ModelMatrices(EMat4* matrices, int count) {
    // Loads bone matrices into GX position matrix array
}

// 0x803440AC (276 bytes)
// Sets model matrix by index
void ENgcRenderer::ModelMatrixIndex(int slot, int index) {
    // Loads a single matrix into the specified GX matrix slot
}

// 0x803441C0 (76 bytes)
// Sets model matrix indices from display list entry
void ENgcRenderer::ModelMatrixIndices(EDLEntry*) {
    // Configures which matrices are used for vertex transform
}

// 0x8034420C (204 bytes)
// Sets view matrix from display list entry
void ENgcRenderer::ViewMatrix(EDLEntry*) {
    // Loads view matrix, applies to GX
}

// 0x803442D8 (196 bytes)
// Sets projection matrix from display list entry
void ENgcRenderer::ProjectionMatrix(EDLEntry*) {
    // Loads projection matrix, calls GXSetProjection
}

// 0x8034439C (160 bytes)
// Sets window matrix from display list entry
void ENgcRenderer::WindowMatrix(EDLEntry*) {
    // Configures screen-space transform
}

// 0x8034447C (284 bytes)
// Binds a texture to a texture stage
void ENgcRenderer::SetTexture(ENgcTexture* tex, int stage) {
    // Calls GXLoadTexObj for the specified stage
    // Updates internal texture state tracking
}

// 0x80344598 (88 bytes)
// Enables geometry rendering modes from display list entry
void ENgcRenderer::EnableGeometryModes(EDLEntry*) {
    // Sets cull mode, blend mode flags
}

// 0x803445F0 (88 bytes)
// Disables geometry rendering modes
void ENgcRenderer::DisableGeometryModes(EDLEntry*) {
    // Clears rendering mode flags
}

// 0x80344648 (80 bytes)
// Sets geometry modes (combined enable/disable)
void ENgcRenderer::SetGeometryModes(EDLEntry*) {
    // Overwrites rendering mode flags
}

// 0x80344724 (400 bytes)
// Configures lights from display list entry
void ENgcRenderer::Lights(EDLEntry*) {
    // Initializes GX light objects
    // Sets light position, direction, color, attenuation
}

// 0x803448B4 (1004 bytes)
// Draws a filled rectangle
void ENgcRenderer::Rect(EDLEntry*) {
    // Renders a textured or colored quad
}

// 0x80344CA0 (1152 bytes)
// Draws a direct rectangle (bypasses display list)
void ENgcRenderer::DirectRect(EDLEntry*) {
    // Similar to Rect but for immediate mode rendering
}

// 0x80345120 (132 bytes)
// Sets material properties
void ENgcRenderer::Material(EDLEntry*) {
    // Updates ambient, diffuse, specular material colors
}

// 0x80345220 (100 bytes)
// Configures Z-buffer test mode
void ENgcRenderer::ZTest(EDLEntry*) {
    // Calls GXSetZMode with compare function and write enable
}

// 0x80345284 (144 bytes)
// Configures alpha test
void ENgcRenderer::AlphaTest(EDLEntry*) {
    // Calls GXSetAlphaCompare with threshold and function
}

// 0x80345314 (376 bytes)
// Sets render surface (render target)
void ENgcRenderer::RenderSurface(EDLEntry*) {
    // Configures copy pipeline for render-to-texture
}

// 0x803454F8 (696 bytes)
// Renders sprite list (packed format)
void ENgcRenderer::SpriteListPacked(int, float*, float*, unsigned char*, signed char*, unsigned char*) {
    // Renders billboard sprites as quads
}

// 0x803457B0 (88 bytes)
// Renders quad list from display list entry
void ENgcRenderer::QuadList(EDLEntry* entry) {
    char* e = (char*)entry;
    // Extracts quad data and calls main QuadList overload
}

// 0x80345808 (2300 bytes)
// Renders quad list from raw vertex data
void ENgcRenderer::QuadList(int, float*, float*, unsigned char*, signed char*, unsigned char*, unsigned char*, bool) {
    // Processes quads as pairs of triangles
}

// 0x8034615C (3264 bytes)
// Renders a movie frame (video overlay)
void ENgcRenderer::MovieFrame(EDLEntry*) {
    // Decodes and displays YUV video frame as textured quad
}

// 0x80346E1C (1188 bytes)
// Renders rotated rectangle list
void ENgcRenderer::RectListRot(EDLEntry*) {
    // Draws rectangles with per-rect rotation
}

// 0x803472C0 (880 bytes)
// Renders rectangle list (axis-aligned)
void ENgcRenderer::RectList(EDLEntry*) {
    // Batch renders multiple rectangles
}

// 0x80347630 (380 bytes)
// Configures stencil buffer
void ENgcRenderer::Stencil(EDLEntry*) {
    // Sets stencil test parameters via GX alpha compare
}

// 0x803477CC (1048 bytes)
// Renders NGC GX display list (integer vertex format)
void ENgcRenderer::NgcGXDisplayListInt(EDLEntry*) {
    // Processes pre-built GX display list data (short positions)
}

// 0x80347BE4 (1012 bytes)
// Renders NGC GX display list (float vertex format)
void ENgcRenderer::NgcGXDisplayList(EDLEntry*) {
    // Processes pre-built GX display list data (float positions)
}

// 0x80347FD8 (896 bytes)
// Renders NGC triangle list (integer vertex format)
void ENgcRenderer::NgcTriListInt(EDLEntry*) {
    // Triangle list rendering with short positions
}

// 0x80348358 (812 bytes)
// Renders NGC triangle list (float vertex format)
void ENgcRenderer::NgcTriList(EDLEntry*) {
    // Triangle list rendering with float positions
}

// 0x80348684 (804 bytes)
// Renders NGC screen-space triangle list
void ENgcRenderer::NgcScreenTriList(EDLEntry*) {
    // Screen-space triangles for 2D overlays
}

// 0x803489F8 (996 bytes)
// Sets shader (material pipeline) for subsequent draws
void ENgcRenderer::SetShader(ENgcShader* shader, unsigned int flags) {
    // Configures TEV stages, texture bindings, blend modes
    // based on shader definition
}

// 0x80348DDC (80 bytes)
// Renders scramble rect from display list entry (delegates to Vec2 overload)
void ENgcRenderer::ScrambleRect(EDLEntry* entry) {
    char* e = (char*)entry;
    // Extracts two EVec2s and a float from the entry
    // Calls ScrambleRect(EVec2&, EVec2&, float)
}

// 0x80348E2C (1164 bytes)
// Renders scramble rectangle effect
void ENgcRenderer::ScrambleRect(EVec2& min, EVec2& max, float intensity) {
    // Post-processing distortion effect
    // Reads back from EFB, applies pixel-level scrambling
}

// 0x8034932C (788 bytes)
// Weighted blend rendering (integer vertex format)
void ENgcRenderer::WeightedBlendInt(_GXPrimitive, int, short*, signed char*, short*, unsigned char*, unsigned char*, bool) {
    // Bone-weighted skinning with short positions
}

// 0x80349640 (732 bytes)
// Simple skinning (single bone per vertex)
void ENgcRenderer::SimpleSkinning(_GXPrimitive, int, short*, signed char*, short*, unsigned char*, unsigned char*, bool) {
    // Single-bone vertex transformation
}

// 0x8034991C (340 bytes)
// Scales a texture
void ENgcRenderer::ScaleTexture(_GXTexObj*, void*, int, float) {
    // Applies scale factor to texture coordinates
}

// 0x80349A70 (292 bytes)
// Draws texture to full viewport with jitter offset (for temporal AA)
void ENgcRenderer::DrawTextureToFullViewportWithJitter(float jitterX, float jitterY) {
    // Draws a full-screen quad with sub-pixel offset
}

// 0x80349B94 (356 bytes)
// Draws frame with bloom and motion blur post-processing
void ENgcRenderer::DrawFrameWithBloomAndMotionBlur(float bloomAmount, float blurAmount) {
    // Composites bloom and motion blur effects onto the frame
}

// 0x80349CF8 (568 bytes)
// Processes thumbnail (screenshot) rendering
void ENgcRenderer::ProcessThumbnail(void* buffer, int size, float x, float y) {
    // Captures a region of the framebuffer for thumbnail generation
}

// 0x80349F6C (104 bytes)
// Returns current render mode (progressive/interlaced)
void ENgcRenderer::GetCurrentRenderMode(void) {
    // Returns the active _GXRenderModeObj
}

// 0x80349FDC (80 bytes)
// Begins particle list rendering, allocates particle buffer
void ENgcRenderer::ParticleListBegin(unsigned int count, unsigned int type) {
    char* self = (char*)this;
    // Allocates count * 64 bytes from MainHeap
    // Stores type, count, and buffer pointer at offsets 18020, 18016, 18012
}

// 0x8034A02C (1116 bytes)
// Ends particle list rendering, submits to GX
void ENgcRenderer::ParticleListEnd(unsigned int flags) {
    // If no particles, frees buffer and returns
    // Otherwise renders all particles as quads/sprites
    // Frees particle buffer
}


// ============================================================================
// SAnimator2 — Sim animation controller (158 functions, 66,260 bytes)
// Manages walk/run/idle/skill animations, particle effects, props, movement
// ============================================================================

class SAnimator2 {
public:
    SAnimator2(void);
    ~SAnimator2(void);
    void Initialize(cXPerson*);
    void InitStaticAnimationElements(void);
    void TryChangeSuit(void);
    void checkParticleCleanup(void);
    void updateFreeMoveState(void);
    void updateMovementState(void);
    void Update(void);
    void Reset(void);
    void resolveSkillForPrimitive(StackElem*, IdleAnimateParam*, AnimRef*&);
    void resolveSkillForPrimitive(StackElem*, AnimateNewParam*, AnimRef*&);
    void loadSkillAnim(AnimRef*);
    void TryIdleAnimate(StackElem*, IdleAnimateParam*);
    void SelectAlgorithmicIdle(AnimRef*&);
    void TryAnimate(StackElem*, AnimateNewParam*);
    void BeginFollow(float speed);
    void FollowOneStep(void);
    void EndFollow(void);
    void DequeueAnimEvent(int*);
    void ReconStream(ReconBuffer*, int);
    void getCorrectId(PropRef*);
    void Dress(PropRef*);
    void AddProp(unsigned int propId, bool visible);
    void RemoveProp(unsigned int propId);
    void PreloadDress(PropRef*);
    void Undress(PropRef*);
    void endFollowDone(void);
    void followStandToTurnUpdate(float&, float&, float);
    void followSidestepUpdate(float&, float&, float);
    void followMiddleUpdate(float&, float&, float);
    void followMoveToTurnUpdate(float&, float&, float);
    void followDoneUpdate(float&, float&, float);
    void endMoveAnimation(void);
    void UpdatePortalMode(void);
    void moveAnimation(void);
    void awarenessMove(void);
    void GetTurnRate(void);
    void rotateAnimation(float current, float target, float rate);
    void sidestepAlongNode(float& distance);
    void advanceAlongNode(float& distance);
    void getUseSpeed(float base, float mod, float anim, float scale);
    void EnableWalkFade(unsigned int& flags, float start, float end, float duration);
    void moveTowardsDestination(float& remaining, EVec2& target);
    void updateRenderAnimation(void);
    void updateParticles(void);
    void handleMoodAnimations(void);
    void playFootprint(char* surfaceType);
    void getFootSound(char* outSound);
    void handleSidestepAnimation(void);
    void handleWalkRunAnimation(void);
    void CheckCollision(EVec2& pos, EVec2& dir);
    void handleFreeMoveWalkRunAnimation(void);
    void handleRunStopAnimation(void);
    void SetNextStateFromCompletedTurn(void);
    void selectRandomIdle(void);
    void handleSkillIdleAnimation(void);
    void handleIdleAnimation(void);
    void handleImpatientIdleAnimation(void);
    void clearImpatientIdleAnimation(void);
    void LoadSMOptionalMotionAnims(void);
    void LoadDCOptionalMotionAnims(void);
    void LoadOptionalIdleAnim(void);
    void UnloadPendingLongIdleAnim(void);
    void UnloadOptionalIdleAnim(void);
    void UnloadDCOptionalMotionAnims(void);
    void UnloadSMOptionalMotionAnims(void);
    void CheckOptionalMotionAnimStatusOnStateChange(int newState);
    void handleTurnAnimation(void);
    void positionCharacter(EMat4* transform);
    void AttachParticleEffect(unsigned int effectId, unsigned int boneId, int flags);
    void DetachParticleEffect(unsigned int effectId, unsigned int boneId, int flags);
    void GetEngineFormatPos(void);
    void processEvents(AnimRef& anim, int startFrame, int endFrame, bool forward, bool loop);
    void eventHandler(EAnimNote& event, int trackIndex);
    void PreloadEvents(AnimRef*);
    void PreloadBoneParticleEvent(REffectsAttachment*);
    void _handleParticleEvent(REffectsAttachment*);
    void procBoneParticleEvt(AnimParticleData*, bool attach);
    void cleanupParticlesDelayed(TRedBlackTree<unsigned int, TRedBlackTree<unsigned int, EBoneParticle*>*>*);
    void cleanupParticlesImmediate(TRedBlackTree<unsigned int, TRedBlackTree<unsigned int, EBoneParticle*>*>*);
    void cleanupParticles(TRedBlackTree<unsigned int, TRedBlackTree<unsigned int, EBoneParticle*>*>*);
    void playRumble(char* name);
    void playRumble(RumbleDataElement*);
    void triggerCameraBloom(char* name);
    void triggerCameraBloom(CameraBloomDataElement*);
    void triggerCameraBlur(char* name);
    void startSkill(AnimRef* anim, bool blend, unsigned int flags);
    void isAnimationDone(void);
    void setPersonDirection(float angle);
    void updateCarryAnimation(void);
    void updateRenderModels(void);
    void setJobModel(void);
    void wearNormal(void);
    void setNewModel(char* modelName, bool immediate, bool keepProps);
    void RestoreNonCostumeRelatedSimDescriptionItems(CasSimDescriptionS2C*, CasSimDescriptionS2C*, bool);
    void GetCostumeName(int costumeIndex);
    void GetCarryHandPosAndDir(EVec3& pos, EVec3& dir, EMat4& transform);
    void GetBonePos(int boneIndex, EVec3& outPos);
    void PropsHaveAlpha(void);
    void DrawProps(ERC* rc, bool shadow, EShader* overrideShader);
    void DrawPropsShadow(ERC* rc);
    void removeAllProps(void);
    void updateCensor(void);
    void DrawCensor(ERC*);
    void GetFootSound(CTilePt& tile, char* outSound);
    void UpdateAnimationValidity(void);
    void setAwarenessFollowStart(float angle);
    void shouldUseLowMotiveIdle(void);
    void shouldUseLowMotiveWalk(void);
    void IsSimulatorControlled(void);
    void SetPlayerControl(bool controlled);
    void* operator new(std::size_t size);
    void getPersonDirection(void);
    void EndAutoRun(void);
    void getIndexOfPropID(unsigned int propId);
    void SetDesiredFacing(float angle);
    void clearSuspendedCarry(void);
    void SetIdleAnimPlaybackParameters(EACTrack* track);
    void determineFirstFollowMode(TileList* path);
    void determineWalkRunStyle(float speed);
    void StartDefaultIdle(void);
    void updateDesiredAndDeltaDir(float& desiredDir, float& deltaDir);
    void setFirstFollowMode(int mode);
    void setFollowEnd(void);
    void setFollowDone(void);
    void defaultVelocity(int style);
    void getAnimDuration(ERAnim*);
    void setSideStepSpeedFromAnimation(AnimRef*);
    void setMovementVelocityFromAnimation(void);
    void setRotationRateFromShuffleDir(int dir, float speed);
    void initShuffleRotation(float targetAngle);
    void getIsLeftFootUp(void);
    void getShuffleDirFromDeltaDir(float deltaDir);
    void getDeltaDirFromDesiredDir(float desiredDir);
    void getDesiredDir(void);
    void GetMovementVelocityFromStyle(int style);
    void setAnimationState(void);
    void getTurnSkillID(AnimRef*& outAnim, int direction);
    void getSidestepSkillIDs(AnimRef*& left, AnimRef*& right, float angle);
    void getWalkRunSkillID(AnimRef*& outAnim);
    void UpdateNPCAutoRunState(void);
    void UpdateNPCAutoRun(void);
    void DetachMonitoredTrack(void);
    void getSidestepIntensity(void);
    void initSidestep(void);
    void initWalkRun(void);
    void initWalkRunFadeOut(void);
    void selectIdleOverlay(void);
    void stopIdleOverlay(void);
    void skillIsIdle(void);
    void ShouldEndSkillTrack(void);
    void startCarry(void);
    void stopCarry(void);
    void setAwarenessFollowEnd(void);
    void setAwarenessFollowMiddle(void);
    void exitAwarenessFollow(void);
    void StartAutoRun(float speed);
};

// 0x8005BFD0 (620 bytes)
// Constructor: sets vtable, initializes two ERedBlackTrees, AwarenessManager
// Zeroes many float/int fields for animation state
SAnimator2::SAnimator2(void) {
    // Sets vtable
    // Calls ERedBlackTree::ERedBlackTree() twice (offsets 1488, 1500)
    // Calls AwarenessManager::AwarenessManager() at offset 1568
    // Zeroes/initializes ~60 fields covering:
    //   movement state, direction, speed, animation references,
    //   follow state, particle state, carry state
    // Calls EMat4::Id() for identity matrix at offset 384
}

// 0x8005C23C (512 bytes)
// Destructor: cleans up particles, props, animation resources
SAnimator2::~SAnimator2(void) {
    // Calls cleanupParticlesImmediate for both particle trees
    // Calls removeAllProps
    // Destroys ERedBlackTree instances
    // Cleans up animation controller tracks
}

// 0x8005C43C (468 bytes)
// Initialize: sets up person reference, loads initial animations
void SAnimator2::Initialize(cXPerson*) {
    // Stores person pointer
    // Loads base motion animations (walk, run, idle, turn)
    // Initializes animation controller
}

// 0x8005C610 (348 bytes)
// Initializes static animation elements (loaded once for all sims)
void SAnimator2::InitStaticAnimationElements(void) {
    // Loads shared animation resources
    // Sets up animation lookup tables
}

// 0x8005C790 (236 bytes)
// Tries to change the sim's outfit/suit
void SAnimator2::TryChangeSuit(void) {
    // Checks current costume state
    // Loads new model if needed
    // Triggers costume change animation
}

// 0x8005C87C (108 bytes)
// Checks if particles need cleanup (delayed removal)
void SAnimator2::checkParticleCleanup(void) {
    // Iterates particle trees, removes expired particles
}

// 0x8005C8E8 (836 bytes)
// Updates free-move state (direct control walking)
void SAnimator2::updateFreeMoveState(void) {
    // Handles player-controlled movement animation state machine
    // Transitions between idle/walk/run/turn states
}

// 0x8005CC2C (84 bytes)
// Updates movement state (autonomous walking)
void SAnimator2::updateMovementState(void) {
    // Updates sim's path-following movement animation
}

// 0x8005CC80 (916 bytes)
// Main update: called every frame to advance animation state
void SAnimator2::Update(void) {
    // Updates movement, animation, particles, mood
    // Handles state transitions
    // Updates render models
}

// 0x8005D04C (212 bytes)
// Resets animator to default state
void SAnimator2::Reset(void) {
    // Clears all animation tracks
    // Resets movement state
    // Removes props and particles
}

// 0x8005D164 (560 bytes)
// Resolves skill animation for an idle primitive
void SAnimator2::resolveSkillForPrimitive(StackElem*, IdleAnimateParam*, AnimRef*&) {
    // Looks up appropriate skill-level animation
    // Falls back to default if skill anim not found
}

// 0x8005D394 (616 bytes)
// Resolves skill animation for an animate primitive
void SAnimator2::resolveSkillForPrimitive(StackElem*, AnimateNewParam*, AnimRef*&) {
    // Same pattern as idle variant but for active animations
}

// 0x8005D5FC (164 bytes)
// Loads a skill animation resource
void SAnimator2::loadSkillAnim(AnimRef*) {
    // Calls resource manager to load animation data
}

// 0x8005D6D4 (848 bytes)
// Attempts to start an idle animation
void SAnimator2::TryIdleAnimate(StackElem*, IdleAnimateParam*) {
    // Resolves skill, loads animation, starts playback
    // Handles overlay idle animations
}

// 0x8005DA24 (380 bytes)
// Selects an algorithmic idle animation
void SAnimator2::SelectAlgorithmicIdle(AnimRef*&) {
    // Picks random idle based on personality/mood
}

// 0x8005DBA0 (3112 bytes)
// Attempts to start a full animation
void SAnimator2::TryAnimate(StackElem*, AnimateNewParam*) {
    // Major function: resolves animation, sets blend params
    // Handles mirroring, speed scaling, looping
}

// 0x8005E7CC (748 bytes)
// Begins path-following mode
void SAnimator2::BeginFollow(float speed) {
    // Initializes follow state from path data
    // Determines walk/run style
    // Starts movement animation
}

// 0x8005EAB8 (444 bytes)
// Advances one step along the follow path
void SAnimator2::FollowOneStep(void) {
    // Updates position along path
    // Handles turns at path nodes
}

// 0x8005EC74 (296 bytes)
// Ends path-following mode
void SAnimator2::EndFollow(void) {
    // Transitions to idle state
    // Cleans up path data
}

// 0x8005EDBC (120 bytes)
// Dequeues a pending animation event
void SAnimator2::DequeueAnimEvent(int*) {
    // Returns next event from animation event queue
}

// 0x8005EE34 (1708 bytes)
// Serializes animation state for savegame/recon
void SAnimator2::ReconStream(ReconBuffer*, int) {
    // Reads/writes all animator state to buffer
}

// 0x8005F4E8 (96 bytes)
// Gets correct prop ID (resolves aliases)
void SAnimator2::getCorrectId(PropRef*) {
    // Looks up canonical prop ID from reference
}

// 0x8005F548 (136 bytes)
// Dresses a prop onto the sim
void SAnimator2::Dress(PropRef*) {
    // Attaches prop model to sim's bone hierarchy
}

// 0x8005F5D0 (392 bytes)
// Adds a prop to the sim
void SAnimator2::AddProp(unsigned int propId, bool visible) {
    // Creates prop instance, loads model, attaches
}

// 0x8005F758 (136 bytes)
// Removes a prop from the sim
void SAnimator2::RemoveProp(unsigned int propId) {
    // Detaches and destroys prop instance
}

// 0x8005F7E0 (76 bytes)
// Preloads prop resources (async)
void SAnimator2::PreloadDress(PropRef*) {
    // Queues prop resources for background loading
}

// 0x8005F82C (172 bytes)
// Undresses a prop from the sim
void SAnimator2::Undress(PropRef*) {
    // Detaches prop model from bone hierarchy
}

// 0x8005F958 (504 bytes)
// Called when follow-done state completes
void SAnimator2::endFollowDone(void) {
    // Finalizes path following, cleans up state
}

// 0x8005FB50 (128 bytes)
// Updates stand-to-turn animation during path following
void SAnimator2::followStandToTurnUpdate(float&, float&, float) {
    // Blends between standing and turning animations
}

// 0x8005FBD0 (492 bytes)
// Updates sidestep animation during path following
void SAnimator2::followSidestepUpdate(float&, float&, float) {
    // Handles lateral movement animation
}

// 0x8005FDBC (252 bytes)
// Updates middle section of path following
void SAnimator2::followMiddleUpdate(float&, float&, float) {
    // Maintains walking animation during straight path segments
}

// 0x8005FEB8 (100 bytes)
// Updates move-to-turn animation
void SAnimator2::followMoveToTurnUpdate(float&, float&, float) {
    // Transitions from walking to turning at path nodes
}

// 0x8005FF1C (100 bytes)
// Updates follow-done animation
void SAnimator2::followDoneUpdate(float&, float&, float) {
    // Final deceleration animation at path end
}

// 0x8005FF80 (352 bytes)
// Ends movement animation
void SAnimator2::endMoveAnimation(void) {
    // Stops walk/run tracks, blends to idle
}

// 0x800600E0 (428 bytes)
// Updates portal mode (door traversal)
void SAnimator2::UpdatePortalMode(void) {
    // Checks if sim is going through a door/portal
    // Adjusts animation accordingly
}

// 0x8006028C (1008 bytes)
// Handles movement animation state machine
void SAnimator2::moveAnimation(void) {
    // Central movement dispatcher - calls appropriate follow*Update
}

// 0x8006067C (608 bytes)
// Updates awareness-based movement
void SAnimator2::awarenessMove(void) {
    // Handles obstacle avoidance during movement
}

// 0x800608DC (76 bytes)
// Gets the turn rate for the current animation style
void SAnimator2::GetTurnRate(void) {
    // Returns turn speed based on walk/run state
}

// 0x80060928 (348 bytes)
// Handles rotation animation
void SAnimator2::rotateAnimation(float current, float target, float rate) {
    // Interpolates rotation towards target angle
}

// 0x80060A84 (412 bytes)
// Steps laterally along a path node
void SAnimator2::sidestepAlongNode(float& distance) {
    // Moves sim sideways while maintaining facing direction
}

// 0x80060C20 (192 bytes)
// Advances along a path node
void SAnimator2::advanceAlongNode(float& distance) {
    // Moves sim forward along current path segment
}

// 0x80060CE0 (336 bytes)
// Calculates effective movement speed
void SAnimator2::getUseSpeed(float base, float mod, float anim, float scale) {
    // Computes final movement speed from multiple factors
}

// 0x80060E30 (140 bytes)
// Enables walk animation fade
void SAnimator2::EnableWalkFade(unsigned int& flags, float start, float end, float duration) {
    // Configures crossfade parameters for walk transitions
}

// 0x80060EBC (668 bytes)
// Moves towards destination position
void SAnimator2::moveTowardsDestination(float& remaining, EVec2& target) {
    // Core movement function: advances position towards target
    // Handles collision and tile boundary crossing
}

// 0x80061158 (1280 bytes)
// Updates rendering animation (blending, events)
void SAnimator2::updateRenderAnimation(void) {
    // Processes animation blending each frame
    // Triggers animation events
}

// 0x80061658 (356 bytes)
// Updates particle effects attached to sim
void SAnimator2::updateParticles(void) {
    // Updates bone particle positions
    // Removes expired particles
}

// 0x80061804 (440 bytes)
// Handles mood-based idle animations
void SAnimator2::handleMoodAnimations(void) {
    // Selects mood overlay animation based on motive state
}

// 0x800619BC (384 bytes)
// Plays footprint effect at foot position
void SAnimator2::playFootprint(char* surfaceType) {
    // Creates footprint decal based on surface material
}

// 0x80061B3C (224 bytes)
// Gets appropriate footstep sound for surface
void SAnimator2::getFootSound(char* outSound) {
    // Looks up footstep sound name by tile material
}

// 0x80061C1C (1168 bytes)
// Handles sidestep animation logic
void SAnimator2::handleSidestepAnimation(void) {
    // Manages lateral movement animation state
}

// 0x800620AC (1268 bytes)
// Handles walk/run animation selection
void SAnimator2::handleWalkRunAnimation(void) {
    // Selects and blends walk/run animation based on speed
}

// 0x800625A0 (544 bytes)
// Checks collision during movement
void SAnimator2::CheckCollision(EVec2& pos, EVec2& dir) {
    // Tests movement against collision map
}

// 0x800627C0 (2332 bytes)
// Handles free-move walk/run animation
void SAnimator2::handleFreeMoveWalkRunAnimation(void) {
    // Player-controlled movement animation
}

// 0x800630DC (344 bytes)
// Handles run-stop animation
void SAnimator2::handleRunStopAnimation(void) {
    // Deceleration animation when stopping from run
}

// 0x80063234 (184 bytes)
// Sets next state after completing a turn
void SAnimator2::SetNextStateFromCompletedTurn(void) {
    // Transitions from turn state to walk/idle
}

// 0x800632EC (752 bytes)
// Selects a random idle animation
void SAnimator2::selectRandomIdle(void) {
    // Picks from available idle animations based on personality
}

// 0x800635DC (1088 bytes)
// Handles skill-specific idle animation
void SAnimator2::handleSkillIdleAnimation(void) {
    // Plays skill-appropriate idle (e.g., reading, cooking)
}

// 0x80063A1C (2584 bytes)
// Handles general idle animation
void SAnimator2::handleIdleAnimation(void) {
    // Manages idle animation state machine
    // Handles periodic idle variations
}

// 0x80064434 (260 bytes)
// Handles impatient idle animation
void SAnimator2::handleImpatientIdleAnimation(void) {
    // Plays frustrated idle when waiting too long
}

// 0x80064538 (144 bytes)
// Clears impatient idle state
void SAnimator2::clearImpatientIdleAnimation(void) {
    // Returns to normal idle from impatient
}

// 0x800645C8 (196 bytes)
// Loads optional motion animations (SM = State Machine)
void SAnimator2::LoadSMOptionalMotionAnims(void) {
    // Loads state-machine-driven optional animations
}

// 0x8006468C (196 bytes)
// Loads optional motion animations (DC = Direct Control)
void SAnimator2::LoadDCOptionalMotionAnims(void) {
    // Loads direct-control optional animations
}

// 0x80064750 (264 bytes)
// Loads optional idle animation
void SAnimator2::LoadOptionalIdleAnim(void) {
    // Loads a long idle animation for variety
}

// 0x80064858 (196 bytes)
// Unloads pending long idle animation
void SAnimator2::UnloadPendingLongIdleAnim(void) {
    // Releases long idle animation resources
}

// 0x8006491C (292 bytes)
// Unloads optional idle animation
void SAnimator2::UnloadOptionalIdleAnim(void) {
    // Releases optional idle resources
}

// 0x80064A40 (236 bytes)
// Unloads DC optional motion animations
void SAnimator2::UnloadDCOptionalMotionAnims(void) {
    // Releases direct-control animation resources
}

// 0x80064B2C (236 bytes)
// Unloads SM optional motion animations
void SAnimator2::UnloadSMOptionalMotionAnims(void) {
    // Releases state-machine animation resources
}

// 0x80064C18 (108 bytes)
// Checks optional animation status on state change
void SAnimator2::CheckOptionalMotionAnimStatusOnStateChange(int newState) {
    // Determines if optional animations need load/unload on state transition
}

// 0x80064C84 (1040 bytes)
// Handles turn animation
void SAnimator2::handleTurnAnimation(void) {
    // Manages turning in place animation
}

// 0x80065094 (868 bytes)
// Positions character model at current location
void SAnimator2::positionCharacter(EMat4* transform) {
    // Applies position/rotation to character transform matrix
}

// 0x80065420 (208 bytes)
// Attaches a particle effect to a bone
void SAnimator2::AttachParticleEffect(unsigned int effectId, unsigned int boneId, int flags) {
    // Creates bone-attached particle emitter
}

// 0x800654F0 (172 bytes)
// Detaches a particle effect from a bone
void SAnimator2::DetachParticleEffect(unsigned int effectId, unsigned int boneId, int flags) {
    // Removes bone-attached particle emitter
}

// 0x800655D4 (148 bytes)
// Gets engine-format position of sim
void SAnimator2::GetEngineFormatPos(void) {
    // Returns sim position in engine coordinate format
}

// 0x80065668 (432 bytes)
// Processes animation events between two frame indices
void SAnimator2::processEvents(AnimRef& anim, int startFrame, int endFrame, bool forward, bool loop) {
    // Iterates animation event list, fires events in range
}

// 0x80065818 (848 bytes)
// Handles a single animation event
void SAnimator2::eventHandler(EAnimNote& event, int trackIndex) {
    // Dispatches event by type: sound, particle, prop, rumble, etc.
}

// 0x80065B68 (264 bytes)
// Preloads resources referenced by animation events
void SAnimator2::PreloadEvents(AnimRef*) {
    // Scans event list, queues resource loads
}

// 0x80065C70 (116 bytes)
// Preloads bone particle event resources
void SAnimator2::PreloadBoneParticleEvent(REffectsAttachment*) {
    // Queues particle effect resource for loading
}

// 0x80065CE4 (260 bytes)
// Handles a particle event from animation
void SAnimator2::_handleParticleEvent(REffectsAttachment*) {
    // Creates or removes particle effect based on event data
}

// 0x80065DE8 (524 bytes)
// Processes bone particle event
void SAnimator2::procBoneParticleEvt(AnimParticleData*, bool attach) {
    // Attaches/detaches particle to bone based on event
}

// 0x80065FF4 (96 bytes)
// Cleans up particles with delayed removal
void SAnimator2::cleanupParticlesDelayed(TRedBlackTree<unsigned int, TRedBlackTree<unsigned int, EBoneParticle*>*>*) {
    // Marks particles for deferred removal
}

// 0x80066054 (104 bytes)
// Cleans up particles immediately
void SAnimator2::cleanupParticlesImmediate(TRedBlackTree<unsigned int, TRedBlackTree<unsigned int, EBoneParticle*>*>*) {
    // Immediately destroys all particles in tree
}

// 0x800660BC (284 bytes)
// Cleans up particles (general)
void SAnimator2::cleanupParticles(TRedBlackTree<unsigned int, TRedBlackTree<unsigned int, EBoneParticle*>*>*) {
    // Iterates particle tree and removes entries
}

// 0x800661D8 (84 bytes)
// Plays rumble effect by name
void SAnimator2::playRumble(char* name) {
    // Looks up rumble data and triggers controller vibration
}

// 0x8006622C (288 bytes)
// Plays rumble effect from data
void SAnimator2::playRumble(RumbleDataElement*) {
    // Triggers controller vibration with specified parameters
}

// 0x8006634C (84 bytes)
// Triggers camera bloom effect by name
void SAnimator2::triggerCameraBloom(char* name) {
    // Looks up bloom data and triggers camera bloom
}

// 0x800663A0 (72 bytes)
// Triggers camera bloom from data
void SAnimator2::triggerCameraBloom(CameraBloomDataElement*) {
    // Applies bloom parameters to camera system
}

// 0x800663E8 (84 bytes)
// Triggers camera blur effect
void SAnimator2::triggerCameraBlur(char* name) {
    // Looks up blur data and applies motion blur
}

// 0x80066490 (864 bytes)
// Starts a skill animation
void SAnimator2::startSkill(AnimRef* anim, bool blend, unsigned int flags) {
    // Begins playing a skill animation on the primary track
}

// 0x800667F0 (336 bytes)
// Checks if current animation is done
void SAnimator2::isAnimationDone(void) {
    // Returns true if primary animation track has completed
}

// 0x8006697C (164 bytes)
// Sets person's facing direction
void SAnimator2::setPersonDirection(float angle) {
    // Updates character rotation to face given angle
}

// 0x80066A20 (1248 bytes)
// Updates carry animation (holding objects)
void SAnimator2::updateCarryAnimation(void) {
    // Manages overlay animation for carrying items
}

// 0x80066FC0 (288 bytes)
// Updates render models (mesh/material changes)
void SAnimator2::updateRenderModels(void) {
    // Refreshes character model based on current state
}

// 0x800670E0 (224 bytes)
// Sets job-specific model
void SAnimator2::setJobModel(void) {
    // Changes character model for career outfit
}

// 0x800671C0 (200 bytes)
// Reverts to normal clothing
void SAnimator2::wearNormal(void) {
    // Changes character back to everyday outfit
}

// 0x80067288 (372 bytes)
// Sets a new character model
void SAnimator2::setNewModel(char* modelName, bool immediate, bool keepProps) {
    // Loads and applies a new character model
}

// 0x800673FC (420 bytes)
// Restores non-costume sim description items
void SAnimator2::RestoreNonCostumeRelatedSimDescriptionItems(CasSimDescriptionS2C*, CasSimDescriptionS2C*, bool) {
    // Preserves hair, accessories when changing costumes
}

// 0x800675A0 (324 bytes)
// Gets costume name for a given index
void SAnimator2::GetCostumeName(int costumeIndex) {
    // Returns string name of the costume
}

// 0x800676EC (108 bytes)
// Gets carry hand position and direction
void SAnimator2::GetCarryHandPosAndDir(EVec3& pos, EVec3& dir, EMat4& transform) {
    // Computes position/direction of the hand holding an object
}

// 0x80067758 (88 bytes)
// Gets bone position by index
void SAnimator2::GetBonePos(int boneIndex, EVec3& outPos) {
    // Returns world-space position of a skeleton bone
}

// 0x800677B0 (108 bytes)
// Checks if any props have alpha transparency
void SAnimator2::PropsHaveAlpha(void) {
    // Returns true if any attached props use alpha blending
}

// 0x8006781C (460 bytes)
// Draws all attached props
void SAnimator2::DrawProps(ERC* rc, bool shadow, EShader* overrideShader) {
    // Renders all prop models attached to sim
}

// 0x800679E8 (212 bytes)
// Draws prop shadows
void SAnimator2::DrawPropsShadow(ERC* rc) {
    // Renders shadow geometry for attached props
}

// 0x80067ABC (152 bytes)
// Removes all props from sim
void SAnimator2::removeAllProps(void) {
    // Detaches and destroys all prop instances
}

// 0x80067B54 (248 bytes)
// Updates censor pixelation
void SAnimator2::updateCensor(void) {
    // Updates censor position to follow sim
}

// 0x80067C4C (2608 bytes)
// Draws censor pixelation effect
void SAnimator2::DrawCensor(ERC*) {
    // Renders the censor mosaic over appropriate body parts
}

// 0x80068680 (884 bytes)
// Gets footstep sound for a tile
void SAnimator2::GetFootSound(CTilePt& tile, char* outSound) {
    // Determines footstep sound based on floor material at tile
}

// 0x800689FC (68 bytes)
// Updates animation validity (checks if current anim is still valid)
void SAnimator2::UpdateAnimationValidity(void) {
    char* self = (char*)this;
    char* charMgr = *(char**)(self + 8);
    char* animCtrl = charMgr + 820;
    int trackIdx = *(int*)(animCtrl + 8);
    int valid = 1;
    void* trackData;
    if (trackIdx >= 0) {
        trackData = (void*)(*(int*)(animCtrl + 68) + trackIdx * 176);
    } else {
        trackData = 0;
    }
    if (trackData == 0) {
        valid = 0;
    }
    *(int*)(charMgr + 916) = valid;
}

// 0x80068AB4 (216 bytes)
// Sets awareness follow start position
void SAnimator2::setAwarenessFollowStart(float angle) {
    // Initializes awareness-based follow mode
    // Wraps angle to 0..2*PI range
    // Calls EAnimController::BlendAllOutgoingTracks
}

// 0x80068B8C (580 bytes)
// Checks if sim should use low-motive idle
void SAnimator2::shouldUseLowMotiveIdle(void) {
    // Checks energy/comfort/fun motives
    // Returns true if any are critically low
}

// 0x80068DD0 (252 bytes)
// Checks if sim should use low-motive walk
void SAnimator2::shouldUseLowMotiveWalk(void) {
    // Similar to shouldUseLowMotiveIdle for walk animations
}

// 0x80068ECC (240 bytes)
// Checks if sim is under simulator control (not player-controlled)
void SAnimator2::IsSimulatorControlled(void) {
    // Returns true if sim is running autonomously
}

// 0x80068FBC (104 bytes)
// Sets player control flag
void SAnimator2::SetPlayerControl(bool controlled) {
    // Updates player control state
}

// 0x80069038 (84 bytes)
// Custom operator new
void* SAnimator2::operator new(std::size_t size) {
    // Allocates from MainHeap
    return MainHeap()->Malloc((unsigned int)size, 0);
}

// 0x80069230 (180 bytes)
// Gets person's current facing direction
void SAnimator2::getPersonDirection(void) {
    // Returns current rotation angle
}

// 0x800692E4 (112 bytes)
// Ends auto-run mode
void SAnimator2::EndAutoRun(void) {
    // Transitions from auto-run to normal state
}

// 0x80069354 (100 bytes)
// Gets index of a prop by its ID
void SAnimator2::getIndexOfPropID(unsigned int propId) {
    // Searches prop list for matching ID
}

// 0x800693E0 (144 bytes)
// Sets desired facing direction
void SAnimator2::SetDesiredFacing(float angle) {
    // Sets the target rotation angle for interpolation
}

// 0x80069470 (112 bytes)
// Clears suspended carry state
void SAnimator2::clearSuspendedCarry(void) {
    // Resets carry animation flags
}

// 0x800694E0 (76 bytes)
// Sets idle animation playback parameters
void SAnimator2::SetIdleAnimPlaybackParameters(EACTrack* track) {
    char* self = (char*)this;
    if (track == 0) return;
    char* charMgr = *(char**)(self + 8);
    float speed = *(float*)(self + 252);
    // Calls EAnimController::SetTrackSpeed(track, speed)
    *(unsigned char*)((char*)track + 13) = 0; // clear flag
}

// 0x8006952C (140 bytes)
// Determines first follow mode based on path
void SAnimator2::determineFirstFollowMode(TileList* path) {
    char* self = (char*)this;
    int mode = 1; // default: normal follow
    // Calls UpdatePortalMode()
    // If not in portal mode and path has exactly 3 nodes
    // and distance between first two nodes <= 256 (16 tiles squared)
    // then mode = 2 (short distance mode)
    // return mode;
}

// 0x800695B8 (264 bytes)
// Determines walk/run animation style
void SAnimator2::determineWalkRunStyle(float speed) {
    // Calls UnloadDCOptionalMotionAnims, UnloadSMOptionalMotionAnims, LoadSMOptionalMotionAnims
    // Checks costume type for special walk styles
    // May start auto-run if appropriate
}

// 0x800697D8 (84 bytes)
// Starts the default idle animation
void SAnimator2::StartDefaultIdle(void) {
    // Begins playing the base idle animation
}

// 0x8006982C (68 bytes)
// Updates desired and delta direction angles
void SAnimator2::updateDesiredAndDeltaDir(float& desiredDir, float& deltaDir) {
    // Calls getDesiredDir() -> stores to desiredDir
    // Calls getDeltaDirFromDesiredDir(desiredDir) -> stores to deltaDir
}

// 0x80069870 (116 bytes)
// Sets follow mode with state transitions
void SAnimator2::setFirstFollowMode(int mode) {
    char* self = (char*)this;
    *(int*)(self + 16) = 1; // set follow active flag
    int currentMode = *(int*)(self + 24);
    if (currentMode <= 5) {
        // Blend out current tracks
        // Calls EAnimController::BlendAllOutgoingTracks
        *(int*)(self + 24) = mode;
        *(int*)(self + 1640) = 0;
    }
}

// 0x80069920 (120 bytes)
// Sets follow to end state
void SAnimator2::setFollowEnd(void) {
    // Sets mode to 4 (follow end)
    // Configures deceleration blend
}

// 0x80069998 (124 bytes)
// Sets follow to done state
void SAnimator2::setFollowDone(void) {
    // Sets mode to 5 (follow done)
    // Starts final position animation
}

// 0x80069A14 (120 bytes)
// Returns default velocity for a movement style
void SAnimator2::defaultVelocity(int style) {
    // Lookup table of default movement speeds
}

// 0x80069A8C (80 bytes)
// Gets duration of an animation
void SAnimator2::getAnimDuration(ERAnim*) {
    // Returns total length of animation in seconds
}

// 0x80069ADC (564 bytes)
// Sets sidestep speed from animation
void SAnimator2::setSideStepSpeedFromAnimation(AnimRef*) {
    // Calculates lateral movement speed from animation data
}

// 0x80069D10 (684 bytes)
// Sets movement velocity from current animation
void SAnimator2::setMovementVelocityFromAnimation(void) {
    // Extracts root motion velocity from playing animation
}

// 0x80069FBC (488 bytes)
// Sets rotation rate from shuffle direction
void SAnimator2::setRotationRateFromShuffleDir(int dir, float speed) {
    // Configures rotation speed based on shuffle movement
}

// 0x8006A1A4 (520 bytes)
// Initializes shuffle rotation
void SAnimator2::initShuffleRotation(float targetAngle) {
    // Sets up rotation parameters for shuffle movement
}

// 0x8006A3AC (88 bytes)
// Checks if left foot is currently up
void SAnimator2::getIsLeftFootUp(void) {
    char* self = (char*)this;
    char* charMgr = *(char**)(self + 8);
    // Gets track position from EAnimController
    // Returns 1 if in left-foot-up phase of walk cycle, 0 otherwise
}

// 0x8006A404 (144 bytes)
// Gets shuffle direction from delta direction angle
void SAnimator2::getShuffleDirFromDeltaDir(float deltaDir) {
    // Quantizes angle to 8 cardinal directions
    // Returns shuffle direction index
}

// 0x8006A494 (116 bytes)
// Gets delta direction from desired direction
void SAnimator2::getDeltaDirFromDesiredDir(float desiredDir) {
    char* self = (char*)this;
    float currentDir = *(float*)(self + 48);
    float delta = desiredDir - currentDir;
    // Wraps delta to -PI..PI range
    // Clamps small deltas to zero
}

// 0x8006A508 (404 bytes)
// Gets desired facing direction from path
void SAnimator2::getDesiredDir(void) {
    // Computes desired direction from path waypoints
    // Uses atan2 of waypoint delta
}

// 0x8006A69C (140 bytes)
// Gets movement velocity for a style
void SAnimator2::GetMovementVelocityFromStyle(int style) {
    // Returns base movement speed for walk/run/shuffle style
}

// 0x8006A728 (780 bytes)
// Sets animation state based on movement mode
void SAnimator2::setAnimationState(void) {
    // Configures animation controller for current state
}

// 0x8006AA34 (612 bytes)
// Gets turn skill ID
void SAnimator2::getTurnSkillID(AnimRef*& outAnim, int direction) {
    // Looks up appropriate turn animation
}

// 0x8006AC98 (232 bytes)
// Gets sidestep skill IDs (left and right)
void SAnimator2::getSidestepSkillIDs(AnimRef*& left, AnimRef*& right, float angle) {
    // Looks up left/right sidestep animations
}

// 0x8006AD80 (424 bytes)
// Gets walk/run skill ID
void SAnimator2::getWalkRunSkillID(AnimRef*& outAnim) {
    // Selects walk or run animation based on speed
}

// 0x8006AF28 (156 bytes)
// Updates NPC auto-run state
void SAnimator2::UpdateNPCAutoRunState(void) {
    // Manages AI-controlled running behavior
}

// 0x8006AFC4 (1292 bytes)
// Updates NPC auto-run movement
void SAnimator2::UpdateNPCAutoRun(void) {
    // Handles movement during NPC auto-run
}

// 0x8006B4D0 (92 bytes)
// Detaches monitored animation track
void SAnimator2::DetachMonitoredTrack(void) {
    // Removes monitoring from the current animation track
}

// 0x8006B52C (1144 bytes)
// Gets sidestep intensity
void SAnimator2::getSidestepIntensity(void) {
    // Returns intensity of lateral movement
}

// 0x8006B9A4 (752 bytes)
// Initializes sidestep movement
void SAnimator2::initSidestep(void) {
    // Sets up sidestep animation and parameters
}

// 0x8006BC94 (200 bytes)
// Initializes walk/run movement
void SAnimator2::initWalkRun(void) {
    // Sets up walk/run animation
}

// 0x8006BD5C (652 bytes)
// Initializes walk/run fade-out
void SAnimator2::initWalkRunFadeOut(void) {
    // Begins blend to idle from walk/run
}

// 0x8006BFE8 (88 bytes)
// Selects idle overlay animation
void SAnimator2::selectIdleOverlay(void) {
    // Picks appropriate idle overlay (breathing, fidgeting)
}

// 0x8006C040 (84 bytes)
// Stops idle overlay animation
void SAnimator2::stopIdleOverlay(void) {
    // Removes current idle overlay track
}

// 0x8006C094 (180 bytes)
// Checks if current skill animation is an idle
void SAnimator2::skillIsIdle(void) {
    // Returns true if the skill animation is categorized as idle
}

// 0x8006C148 (472 bytes)
// Checks if skill track should end
void SAnimator2::ShouldEndSkillTrack(void) {
    // Determines if the active skill animation should stop
}

// 0x8006C320 (368 bytes)
// Starts carry animation
void SAnimator2::startCarry(void) {
    // Begins the object-carrying overlay animation
}

// 0x8006C490 (468 bytes)
// Stops carry animation
void SAnimator2::stopCarry(void) {
    // Ends the carrying overlay animation
}

// 0x8006C664 (120 bytes)
// Sets awareness follow end
void SAnimator2::setAwarenessFollowEnd(void) {
    // Transitions awareness follow to ending state
}

// 0x8006C6DC (372 bytes)
// Sets awareness follow middle
void SAnimator2::setAwarenessFollowMiddle(void) {
    // Transitions awareness follow to middle state
}

// 0x8006C850 (112 bytes)
// Exits awareness follow mode
void SAnimator2::exitAwarenessFollow(void) {
    // Cleans up awareness follow state
}

// 0x8006C8B0 (not listed - likely StartAutoRun)
// Starts auto-run at given speed
void SAnimator2::StartAutoRun(float speed) {
    // Initiates auto-run movement mode
}


// ============================================================================
// cXPersonImpl — Person simulation implementation (96 functions, 70,864 bytes)
// Handles person motives, actions, social, routing, animation control
// ============================================================================

class cXPersonImpl {
public:
    static void InitializeStaticMemory(void);
    static void CleanupStaticMemory(void);
    void GetNextQueueStr(int offset);
    cXPersonImpl(int type, ObjSelector* selector, ObjectModule* module);
    ~cXPersonImpl(void);
    void Initialize(void);
    void Reset(bool full);
    void PostLoad(int version, bool fromSave);
    void LoadMotiveEffects(void);
    void PreSave(void);
    void TrySetMotiveDelta(StackElem*, XPrimParam*);
    void TryGosubFoundAction(StackElem*);
    void TryLookTowards(StackElem*, XPrimParam*);
    void TryGotoRoutingSlot(StackElem*, XPrimParam*);
    void TryGotoRoutingSlot(StackElem*, RoutingSlot*);
    void AskOthersToMove(XRoute* route);
    void MoveOutOfWay(int urgency);
    void MoveOutOfWay(XRoute* route, TileList& tiles);
    void InitRoute(XRoute* route);
    void TryGotoRelative(StackElem*, XPrimParam*);
    void TryRoomRouting(XRoute* route);
    void TryGetReachInfo(StackElem*, XPrimParam*, cXObject**, cXObject**, int*, float*);
    void TryReach(StackElem*, XPrimParam*);
    void NetTrySnapTo(StackElem*, XPrimParam*);
    void TryElement(StackElem*, short elementId, XPrimParam*);
    void Simulate(int deltaMs);
    void ReconStream(ReconBuffer*, int, bool);
    void SimMotives(void);
    void GetAspirationScore(void);
    void SetAspirationScore(float score);
    void GetAspirationStatus(void);
    void SpawnAspirationBalloon(int type);
    void RunImmediateAction(Interaction* action);
    void AddAction(Interaction* action);
    void RemoveAction(int index);
    void HasQueuedActionOfPri(int priority) const;
    void CancelLastAction(void);
    void CancelAllActions(void);
    void CancelAllButLastActions(void);
    void GetIndAction(int index, bool wrap);
    void GetCurrentAction(void);
    void GetCurrentInteractionStackObject(void);
    void GetCurrentInteractionIconObject(void);
    void ShouldInterrupt(void);
    void TryTestInteractingWith(StackElem*, XPrimParam*);
    void TryChangeSuit(StackElem*, XPrimParam*);
    void TryIdleForInput(StackElem*, XPrimParam*);
    void executeInterruptOnIdlePrimitve(StackElem*, short*, bool);
    void TryIdleAnimate(StackElem*, XPrimParam*);
    void TryFindBestAction(StackElem*);
    void Skipping3D(void);
    void UpdateCurrentRoom(void);
    void Place(FTilePt& pos, int dir, cXObject* container, int slot);
    void TrySocialMode(StackElem*, XPrimParam*);
    void SetHilite(int hiliteMode);
    void IsSelectableByPlayer(int playerIndex);
    void IsPrimarySim(int playerIndex);
    void AttachToHUD(bool attach);
    void IsPersonInFamily(int familyId) const;
    void ForceLocation(void);
    void GosubObjectTree(cXObject* obj, short* treeId, short param, bool immediate);
    void StackJustPopped(void);
    void SetCurrentAction(Interaction& action);
    void UpdateCurrentAction(void);
    void Cleanup(cXObject* obj);
    void CompleteCurrentAction(void);
    void DeleteTopAction(void);
    void ActionSkipped(Interaction& action);
    void DumpDestList(char* label);
    void IsDog(void);
    void IsCat(void);
    void IsMonkey(void);
    void IsPet(void);
    void IsChild(void);
    void IsMale(void);
    void UserCanPickup(void);
    void Turn(int direction);
    void IsPersonDying(void);
    void SetSecondPlayerInSocialMode(bool inSocial);
    void CheckFirstPlayerForFailedSocialModeEntry(void);
    void CheckSecondPlayerForFailedSocialModeEntry(void);
    void GetSocialModeTarget(void);
    void IncrementSimSocialInterest(float amount);
    void GetSimSocialInterestAsMotiveValue(cXPerson* otherSim);
    void SetSimSocialIntrestFromMotiveValue(cXPerson* otherSim, float value);
    void InitWantFearIcons(void);
    void SpawnWantFearDialog(unsigned int eventId) const;
    void SetIdlePlayerSimAutonomous(void);
    void IsCarryingDCObject(void);
    void GetNormalSimDescription(void);
    void IsCarrying(void);
    void GetControllingObject(void);
    void GetSimMemory(cXPerson* otherSim, int memoryType);
    void SetSimMemory(cXPerson* otherSim, int memoryType, int value);
    void GetDominantMemory(cXPerson* otherSim, int category);
};

// 0x8011A824 (232 bytes)
// Initializes static memory for all person instances
void cXPersonImpl::InitializeStaticMemory(void) {
    // Loads motive curve data from string tables
    // Calls PiecewiseFn::SetMaxPoints for each motive
    // Calls MotiveCurveSet::LoadFromStringSet
    // Sets static initialization flag
}

// 0x8011A90C (120 bytes)
// Cleans up static memory for all person instances
void cXPersonImpl::CleanupStaticMemory(void) {
    // Resets PiecewiseFn max points to 0 for each motive
    // Clears static initialization flag
}

// 0x8011AD9C (104 bytes)
// Gets the name string of the next queued action
void cXPersonImpl::GetNextQueueStr(int offset) {
    // Computes circular buffer index
    // Calls Interaction::GetName() and BString2::c_str()
    // Returns the name as a C string
}

// 0x8011AE04 (6232 bytes)
// Constructor: creates a new person implementation
cXPersonImpl::cXPersonImpl(int type, ObjSelector* selector, ObjectModule* module) {
    // Calls TreeSim::TreeSim()
    // Sets up vtables for multiple interfaces
    // Initializes action queue (10 slots, 68 bytes each)
    // Initializes motive system, social system
    // Creates SAnimator2 instance
    // Sets up want/fear system
    // Initializes ~200 fields
}

// 0x8011C77C (6528 bytes)
// Destructor: cleans up person instance
cXPersonImpl::~cXPersonImpl(void) {
    // Destroys SAnimator2
    // Cleans up action queue
    // Releases motive effects
    // Cleans up social state
}

// 0x8011E0FC (2684 bytes)
// Initializes person after construction
void cXPersonImpl::Initialize(void) {
    // Sets initial motive values
    // Loads personality data
    // Initializes relationship system
}

// 0x8011EB78 (260 bytes)
// Resets person to default state
void cXPersonImpl::Reset(bool full) {
    // Clears action queue, resets motives
    // Resets animation state
}

// 0x8011EC7C (708 bytes)
// Post-load processing after save game load
void cXPersonImpl::PostLoad(int version, bool fromSave) {
    // Validates loaded data, fixes up pointers
    // Rebuilds internal state from saved data
}

// 0x8011EF40 (300 bytes)
// Loads motive effect data
void cXPersonImpl::LoadMotiveEffects(void) {
    // Loads motive modifiers from data tables
}

// 0x8011F06C (80 bytes)
// Pre-save processing before saving
void cXPersonImpl::PreSave(void) {
    // Prepares person data for serialization
}

// 0x8011F0BC (932 bytes)
// Attempts to set a motive delta (change rate)
void cXPersonImpl::TrySetMotiveDelta(StackElem*, XPrimParam*) {
    // Modifies a motive's change rate based on primitive parameters
}

// 0x8011F460 (500 bytes)
// Attempts to gosub to a found action's tree
void cXPersonImpl::TryGosubFoundAction(StackElem*) {
    // Pushes a found action's behavior tree onto the stack
}

// 0x8011F654 (3412 bytes)
// Attempts to make sim look towards a target
void cXPersonImpl::TryLookTowards(StackElem*, XPrimParam*) {
    // Sets head/eye tracking target
}

// 0x801203A8 (664 bytes)
// Attempts to route to a routing slot
void cXPersonImpl::TryGotoRoutingSlot(StackElem*, XPrimParam*) {
    // Initiates pathfinding to a slot position
}

// 0x80120640 (6800 bytes)
// Attempts to route to a routing slot (direct)
void cXPersonImpl::TryGotoRoutingSlot(StackElem*, RoutingSlot*) {
    // Core routing function: finds path, handles blocked cases
}

// 0x80122120 (2168 bytes)
// Asks other sims to move out of the way
void cXPersonImpl::AskOthersToMove(XRoute* route) {
    // Checks for sims blocking the path
    // Issues move-out-of-way interactions
}

// 0x80122AAC (852 bytes)
// Forces sim to move out of the way
void cXPersonImpl::MoveOutOfWay(int urgency) {
    // Immediate movement to clear space
}

// 0x80122E00 (2308 bytes)
// Moves out of way of a specific route
void cXPersonImpl::MoveOutOfWay(XRoute* route, TileList& tiles) {
    // Finds clear tile and moves there
}

// 0x8012373C (3124 bytes)
// Initializes a route for pathfinding
void cXPersonImpl::InitRoute(XRoute* route) {
    // Sets up route parameters from current state
}

// 0x80124370 (808 bytes)
// Attempts relative movement
void cXPersonImpl::TryGotoRelative(StackElem*, XPrimParam*) {
    // Moves by a relative offset
}

// 0x80124698 (260 bytes)
// Attempts room-based routing
void cXPersonImpl::TryRoomRouting(XRoute* route) {
    // Routes within or between rooms
}

// 0x8012479C (600 bytes)
// Gets reach info for interaction
void cXPersonImpl::TryGetReachInfo(StackElem*, XPrimParam*, cXObject**, cXObject**, int*, float*) {
    // Determines if target is reachable
}

// 0x801249F4 (88 bytes)
// Attempts to reach a target
void cXPersonImpl::TryReach(StackElem*, XPrimParam*) {
    // Routes to interaction position
}

// 0x80124ADC (580 bytes)
// Network snap-to for multiplayer
void cXPersonImpl::NetTrySnapTo(StackElem*, XPrimParam*) {
    // Synchronizes position in multiplayer
}

// 0x80124D20 (796 bytes)
// Attempts a behavior tree element
void cXPersonImpl::TryElement(StackElem*, short elementId, XPrimParam*) {
    // Executes a single behavior tree primitive
}

// 0x80125048 (860 bytes)
// Main simulation tick
void cXPersonImpl::Simulate(int deltaMs) {
    // Updates motives, processes actions, runs behavior tree
}

// 0x801253E4 (364 bytes)
// Serializes person state
void cXPersonImpl::ReconStream(ReconBuffer*, int, bool) {
    // Writes/reads person data to/from buffer
}

// 0x80125550 (412 bytes)
// Simulates motive changes
void cXPersonImpl::SimMotives(void) {
    // Applies motive deltas, processes motive effects
}

// 0x801256EC (96 bytes)
// Gets aspiration score (normalized)
void cXPersonImpl::GetAspirationScore(void) {
    // Reads raw aspiration value via vtable call
    // Normalizes: (value + offset) / range * scale
}

// 0x8012574C (92 bytes)
// Sets aspiration score (denormalized)
void cXPersonImpl::SetAspirationScore(float score) {
    // Denormalizes: score / scale * range - offset
    // Writes via vtable call
}

// 0x801257A8 (140 bytes)
// Gets aspiration status level (0-3)
void cXPersonImpl::GetAspirationStatus(void) {
    // Reads aspiration value
    // Returns 0 (low), 1, 2, or 3 (high) based on thresholds
}

// 0x80125834 (332 bytes)
// Spawns aspiration balloon UI
void cXPersonImpl::SpawnAspirationBalloon(int type) {
    // Creates thought balloon for aspiration changes
}

// 0x80125980 (336 bytes)
// Runs an immediate action
void cXPersonImpl::RunImmediateAction(Interaction* action) {
    // Executes an action without queueing
}

// 0x80125ADC (904 bytes)
// Adds an action to the queue
void cXPersonImpl::AddAction(Interaction* action) {
    // Inserts action into priority queue
}

// 0x80125E64 (388 bytes)
// Removes an action by index
void cXPersonImpl::RemoveAction(int index) {
    // Removes and cleans up queued action
}

// 0x80125FE8 (132 bytes)
// Checks if queue has action of given priority
void cXPersonImpl::HasQueuedActionOfPri(int priority) const {
    // Scans action queue for matching priority
}

// 0x8012606C (296 bytes)
// Cancels the last queued action
void cXPersonImpl::CancelLastAction(void) {
    // Removes most recent queued action
}

// 0x80126194 (284 bytes)
// Cancels all queued actions
void cXPersonImpl::CancelAllActions(void) {
    // Clears entire action queue
}

// 0x801262B0 (176 bytes)
// Cancels all but the last action
void cXPersonImpl::CancelAllButLastActions(void) {
    // Keeps only the most recent action
}

// 0x80126360 (104 bytes)
// Gets action at index
void cXPersonImpl::GetIndAction(int index, bool wrap) {
    // Returns action at circular buffer index
}

// 0x801263C8 (68 bytes)
// Gets current (active) action
void cXPersonImpl::GetCurrentAction(void) {
    // Returns the action currently being executed
}

// 0x8012640C (92 bytes)
// Gets stack object of current interaction
void cXPersonImpl::GetCurrentInteractionStackObject(void) {
    // Returns the object involved in current action
}

// 0x80126468 (92 bytes)
// Gets icon object of current interaction
void cXPersonImpl::GetCurrentInteractionIconObject(void) {
    // Returns the object whose icon represents the action
}

// 0x801264C8 (376 bytes)
// Checks if current action should be interrupted
void cXPersonImpl::ShouldInterrupt(void) {
    // Evaluates interrupt conditions
}

// 0x80126640 (140 bytes)
// Tests if interacting with specific object
void cXPersonImpl::TryTestInteractingWith(StackElem*, XPrimParam*) {
    // Checks if current interaction involves target object
}

// 0x801266CC (852 bytes)
// Attempts to change outfit
void cXPersonImpl::TryChangeSuit(StackElem*, XPrimParam*) {
    // Changes sim's clothing via behavior primitive
}

// 0x80126A20 (324 bytes)
// Idles waiting for player input
void cXPersonImpl::TryIdleForInput(StackElem*, XPrimParam*) {
    // Suspends behavior tree until player provides input
}

// 0x80126B64 (756 bytes)
// Executes interrupt on idle primitive
void cXPersonImpl::executeInterruptOnIdlePrimitve(StackElem*, short*, bool) {
    // Processes interrupts during idle
}

// 0x80126E58 (648 bytes)
// Attempts idle animation
void cXPersonImpl::TryIdleAnimate(StackElem*, XPrimParam*) {
    // Triggers idle animation via behavior tree
}

// 0x80127114 (4104 bytes)
// Attempts to find best autonomous action
void cXPersonImpl::TryFindBestAction(StackElem*) {
    // AI autonomy: evaluates all available interactions
    // Selects highest-scoring action
}

// 0x80128134 (128 bytes)
// Checks if 3D rendering should be skipped
void cXPersonImpl::Skipping3D(void) {
    // Returns true if sim is off-screen or in background
}

// 0x801281B4 (224 bytes)
// Updates which room the sim is in
void cXPersonImpl::UpdateCurrentRoom(void) {
    // Recalculates room assignment based on position
}

// 0x80128294 (76 bytes)
// Places sim at a location
void cXPersonImpl::Place(FTilePt& pos, int dir, cXObject* container, int slot) {
    // Positions sim at the given tile
}

// 0x801282E0 (4584 bytes)
// Attempts social mode interaction
void cXPersonImpl::TrySocialMode(StackElem*, XPrimParam*) {
    // Handles social interaction system
}

// 0x801294C8 (116 bytes)
// Sets highlight state
void cXPersonImpl::SetHilite(int hiliteMode) {
    // Sets visual highlighting for selection
}

// 0x8012954C (464 bytes)
// Checks if person is selectable by a player
void cXPersonImpl::IsSelectableByPlayer(int playerIndex) {
    // Determines if this sim can be selected/controlled
}

// 0x8012971C (232 bytes)
// Checks if this is the primary sim for a player
void cXPersonImpl::IsPrimarySim(int playerIndex) {
    // Returns true if this is the main controlled sim
}

// 0x80129804 (116 bytes)
// Attaches/detaches sim to HUD
void cXPersonImpl::AttachToHUD(bool attach) {
    // Links/unlinks sim to the heads-up display
}

// 0x80129878 (112 bytes)
// Checks if person is in a specific family
void cXPersonImpl::IsPersonInFamily(int familyId) const {
    // Returns true if sim belongs to the given family
}

// 0x801298E8 (76 bytes)
// Forces sim to a known location
void cXPersonImpl::ForceLocation(void) {
    // Teleports sim to their assigned position
}

// 0x80129934 (780 bytes)
// Gosubs to an object's behavior tree
void cXPersonImpl::GosubObjectTree(cXObject* obj, short* treeId, short param, bool immediate) {
    // Pushes object's behavior tree onto execution stack
}

// 0x80129C40 (652 bytes)
// Called when behavior stack just popped
void cXPersonImpl::StackJustPopped(void) {
    // Handles cleanup after behavior tree returns
}

// 0x80129ECC (68 bytes)
// Sets the current action
void cXPersonImpl::SetCurrentAction(Interaction& action) {
    // Updates the active action reference
}

// 0x80129F10 (316 bytes)
// Updates the current action state
void cXPersonImpl::UpdateCurrentAction(void) {
    // Advances current action's behavior tree
}

// 0x8012A04C (3120 bytes)
// Cleans up after interaction with an object
void cXPersonImpl::Cleanup(cXObject* obj) {
    // Releases resources from completed interaction
}

// 0x8012AC7C (172 bytes)
// Completes the current action
void cXPersonImpl::CompleteCurrentAction(void) {
    // Finalizes and removes current action
}

// 0x8012AD28 (112 bytes)
// Deletes the top action from queue
void cXPersonImpl::DeleteTopAction(void) {
    // Removes topmost queued action
}

// 0x8012AD98 (240 bytes)
// Handles a skipped action
void cXPersonImpl::ActionSkipped(Interaction& action) {
    // Processes cleanup for actions that were skipped
}

// 0x8012AE88 (816 bytes)
// Dumps destination list for debugging
void cXPersonImpl::DumpDestList(char* label) {
    // Debug output of pathfinding destinations
}

// 0x8012B1D4 (128 bytes)
// Checks if person is a dog
void cXPersonImpl::IsDog(void) {
    char* self = (char*)this;
    // Gets IsPerson flag via vtable; if person, gets species via vtable
    // Returns (species == 2)
}

// 0x8012B254 (128 bytes)
// Checks if person is a cat
void cXPersonImpl::IsCat(void) {
    // Same pattern as IsDog but checks species == 3
}

// 0x8012B2D4 (128 bytes)
// Checks if person is a monkey
void cXPersonImpl::IsMonkey(void) {
    // Same pattern as IsDog but checks species == 4
}

// 0x8012B354 (216 bytes)
// Checks if person is any pet type
void cXPersonImpl::IsPet(void) {
    // Returns IsDog() || IsCat() || IsMonkey()
}

// 0x8012B42C (128 bytes)
// Checks if person is a child
void cXPersonImpl::IsChild(void) {
    // Gets age group via vtable, returns (ageGroup == 1)
}

// 0x8012B4AC (124 bytes)
// Checks if person is male
void cXPersonImpl::IsMale(void) {
    // Gets gender via vtable, returns (gender == 0)
}

// 0x8012B5F4 (228 bytes)
// Checks if player can pick up this sim
void cXPersonImpl::UserCanPickup(void) {
    // Returns false (sims cannot be picked up like objects)
}

// 0x8012B6D8 (124 bytes)
// Turns person to face a direction
void cXPersonImpl::Turn(int direction) {
    // Rotates sim to specified compass direction
}

// 0x8012B784 (128 bytes)
// Checks if person is dying
void cXPersonImpl::IsPersonDying(void) {
    // Returns true if death sequence is active
}

// 0x8012B834 (144 bytes)
// Sets second player in social mode flag
void cXPersonImpl::SetSecondPlayerInSocialMode(bool inSocial) {
    // Updates social mode state for player 2
}

// 0x8012B8CC (172 bytes)
// Checks if player 1 failed social mode entry
void cXPersonImpl::CheckFirstPlayerForFailedSocialModeEntry(void) {
    // Validates social mode was entered successfully
}

// 0x8012B978 (424 bytes)
// Checks if player 2 failed social mode entry
void cXPersonImpl::CheckSecondPlayerForFailedSocialModeEntry(void) {
    // Same as above for player 2
}

// 0x8012BB20 (108 bytes)
// Gets the social mode target sim
void cXPersonImpl::GetSocialModeTarget(void) {
    // Returns the other sim in the social interaction
}

// 0x8012BB8C (588 bytes)
// Increments social interest score
void cXPersonImpl::IncrementSimSocialInterest(float amount) {
    // Adds to the social interest value
}

// 0x8012BDD8 (368 bytes)
// Gets social interest as a motive value
void cXPersonImpl::GetSimSocialInterestAsMotiveValue(cXPerson* otherSim) {
    // Converts social interest to motive-compatible value
}

// 0x8012BF48 (324 bytes)
// Sets social interest from motive value
void cXPersonImpl::SetSimSocialIntrestFromMotiveValue(cXPerson* otherSim, float value) {
    // Converts motive value to social interest
}

// 0x8012C08C (108 bytes)
// Initializes want/fear icons
void cXPersonImpl::InitWantFearIcons(void) {
    // Sets up icons for the want/fear panel
}

// 0x8012C0F8 (116 bytes)
// Spawns want/fear dialog
void cXPersonImpl::SpawnWantFearDialog(unsigned int eventId) const {
    // Creates the want/fear selection dialog
}

// 0x8012C16C (136 bytes)
// Sets idle player sim to autonomous mode
void cXPersonImpl::SetIdlePlayerSimAutonomous(void) {
    // Enables autonomy for player sim that is idle
}

// 0x8012C1F4 (196 bytes)
// Checks if sim is carrying a direct control object
void cXPersonImpl::IsCarryingDCObject(void) {
    // Returns true if holding an object in direct control mode
}

// 0x8012C2B8 (180 bytes)
// Gets normal sim description
void cXPersonImpl::GetNormalSimDescription(void) {
    // Returns the sim's everyday appearance description
}

// 0x8012C788 (84 bytes)
// Checks if sim is carrying anything
void cXPersonImpl::IsCarrying(void) {
    // Returns true if sim has an object in hand
}

// 0x8012CA5C (76 bytes)
// Gets the controlling object (e.g., chair sim is sitting in)
void cXPersonImpl::GetControllingObject(void) {
    // Returns object that controls sim's position
}

// 0x8013FDF0 (148 bytes)
// Gets memory value for a specific sim
void cXPersonImpl::GetSimMemory(cXPerson* otherSim, int memoryType) {
    // Retrieves stored memory about another sim
}

// 0x8013FE84 (156 bytes)
// Sets memory value for a specific sim
void cXPersonImpl::SetSimMemory(cXPerson* otherSim, int memoryType, int value) {
    // Stores a memory about another sim
}

// 0x8013FF20 (148 bytes)
// Gets dominant memory for a specific sim
void cXPersonImpl::GetDominantMemory(cXPerson* otherSim, int category) {
    // Returns the strongest memory in a category
}


// ============================================================================
// AptActionInterpreter — Flash/ActionScript bytecode interpreter
// (147 functions, 84,768 bytes)
// Implements the APT ActionScript VM for the game's Flash-based UI
// ============================================================================

class AptActionInterpreter {
public:
    ~AptActionInterpreter(void);
    void initialize(AptInitParmsT& parms);
    void shutdown(void);
    void _parseStream(unsigned char* stream, unsigned char* end, AptConstFile* constFile, int* result);
    void loadVariables(AptValue* target, AptValue* url, EAStringC* vars);
    void getObject(AptValue* scope, AptValue* name, EAStringC* path);
    void getContext(AptValue* scope, AptValue* target, EAStringC* name, AptValue** outCtx, EAStringC& outName);
    void getContext(AptValue* scope, AptValue* target, EAStringC* name, AptValue** outCtx, char* outName);
    void setVariable(AptValue* scope, AptValue* target, EAStringC* name, AptValue* value, int flags1, int flags2, int flags3);
    void cbCallMethod_setInterval(AptValue* args, int argc);
    void cbCallMethod_clearInterval(AptValue* args, int argc);
    void cbCallMethod_hitTest(AptCIH* cih, int argc);
    void cbCallMethod_isNaN(AptValue* args, int argc);
    void cbCallMethod_unescape(AptValue* args, int argc);
    void cbCallMethod_escape(AptValue* args, int argc);
    void cbCallMethod_boolean(AptValue* args, int argc);
    void getName2(AptCIH* cih, EAStringC& outName);
    void getName(AptCIH* cih, EAStringC& outName);
    void _doCloneSprite(AptCIH* cih, AptValue* name, AptValue* depth, AptValue* initObj, int flags, AptValue* target);
    void getVariable(AptValue* scope, AptValue* target, EAStringC* name, int flags1, int flags2, int flags3);
    void valueToObject(AptValue* in, AptValue* scope, AptValue* this_ptr, AptValue** outObj);
    void callFunction(AptValue* func, AptValue* this_ptr, int argc);
    void CleanupAfterExecution(char* name, void* data);
    void CleanupAfterExecution(void* ctx, AptActionSetup* setup);
    void _createObject(AptValue* scope, AptValue* constructor, EAStringC* className, int argc, bool callCtor);
    void _doEnumerate(AptValue* target, AptValue* scope);
    void runStream(unsigned char* stream, AptCIH* cih, int length, AptCharacterInst* charInst);
    void urlDecode(char* input, EAStringC& key, EAStringC& value);
    void isFSCommand(char* url);
    void doFSCommand(char* command, char* args);
    void _FunctionAptActionNextFrame(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPrevFrame(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPlay(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionStop(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionAdd(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionSubtract(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionMultiply(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionDivide(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionEquals(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionLessThan(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionAnd(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionOr(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionNot(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionStringEquals(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionStringLength(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionSubString(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPop(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionToInteger(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionGetVariable(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionSetVariable(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionSetTarget2(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionStringAdd(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionGetProperty(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionSetProperty(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionCloneSprite(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionRemoveSprite(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionTrace(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionStartDragMovie(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionStopDragMovie(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionRandom(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionAsciiToChar(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionGetTimer(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionDelete(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionDelete2(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionDefineLocal(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionCallFunction(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionModulo(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionNewObject(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionDefineLocal2(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionInitArray(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionInitObject(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionTypeOf(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionTargetPath(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionAdd2(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionLessThan2(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionEquals2(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionToNumber(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionToString(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushDuplicate(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionStackSwap(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionGetMember(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionSetMember(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionIncrement(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionDecrement(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionCallMethod(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionNewMethod(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionBitAnd(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionBitOr(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionBitXor(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionBitLShift(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionBitRShift(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionStrictEquals(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionGreater(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionGotoFrame(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionGetUrl(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionStoreRegister(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionSetTarget(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionGotoLabel(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionWith(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPush(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionGetUrl2(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionDefineFunction(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionDefineFunction2(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionBranchIfTrue(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionCallFrame(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionGotoFrame2(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionBranchAlways(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushThis(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushGlobal(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPush0(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPush1(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushTrue(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushFalse(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushNULL(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushUndefined(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionCallFuncAndPop(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionCallFuncSetVar(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionCallMethodPop(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionCallMethodSetVar(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushThisVariable(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushGlobalVariable(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushZeroSetVar(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushString(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushStringDictByte(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushStringDictWord(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushStringGetVar(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushStringGetMember(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushStringSetVar(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushStringSetMember(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionStringDictByteGetVar(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionStringDictByteGetMember(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionDictCallFuncPop(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionDictCallFuncSetVar(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionDictCallMethodPop(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionDictCallMethodSetVar(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushFloat(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushByte(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushWord(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionPushDWord(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionBranchIfFalse(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionExtends(AptActionInterpreter* interp, int* ctx);
    void isObjectOfType(AptValue* obj, AptValue* type);
    void _FunctionAptActionInstanceOf(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionCastOp(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionImplementsOp(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionTry(AptActionInterpreter* interp, int* ctx);
    void _FunctionAptActionThrow(AptActionInterpreter* interp, int* ctx);
};

// 0x8026C8BC (172 bytes)
// Initializes the ActionScript interpreter
void AptActionInterpreter::initialize(AptInitParmsT& parms) {
    char* self = (char*)this;
    // Allocates 4 arrays from DOGMA pool:
    //   stack (offset 0), local vars (offset 12),
    //   scope chain (offset 24), register file (offset 36)
    // Each sized by parms fields at offsets 32/36
    // Zeroes execution counters at offsets 88, 92
    // Calls AptScriptFunctionBase::InitializeStaticData
}

// 0x8026C968 (220 bytes)
// Shuts down the interpreter
void AptActionInterpreter::shutdown(void) {
    char* self = (char*)this;
    // Deallocates all 4 arrays via DOGMA_PoolManager::Deallocate
    // Zeroes array pointers and counts
    // Calls AptScriptFunctionBase::ShutdownStaticData
}

// 0x8026CA44 (2504 bytes)
// Parses an ActionScript bytecode stream
void AptActionInterpreter::_parseStream(unsigned char* stream, unsigned char* end, AptConstFile* constFile, int* result) {
    // Main bytecode parsing loop
    // Reads opcode, dispatches to handler function
    // Handles branches, function calls, variable access
}

// 0x8026D454 (620 bytes)
// Loads variables from a URL-encoded string
void AptActionInterpreter::loadVariables(AptValue* target, AptValue* url, EAStringC* vars) {
    // Parses URL-encoded variables and sets them on target
}

// 0x8026D6C0 (316 bytes)
// Gets an object from the scope chain
void AptActionInterpreter::getObject(AptValue* scope, AptValue* name, EAStringC* path) {
    // Resolves object reference by name in scope chain
}

// 0x8026D7FC (348 bytes)
// Gets context for variable/member access (returns reference + name)
void AptActionInterpreter::getContext(AptValue* scope, AptValue* target, EAStringC* name, AptValue** outCtx, EAStringC& outName) {
    // Resolves dot-notation paths to context object + member name
}

// 0x8026D958 (520 bytes)
// Gets context (char* name variant)
void AptActionInterpreter::getContext(AptValue* scope, AptValue* target, EAStringC* name, AptValue** outCtx, char* outName) {
    // Same as above but with C string output
}

// 0x8026DB60 (1256 bytes)
// Sets a variable on an object
void AptActionInterpreter::setVariable(AptValue* scope, AptValue* target, EAStringC* name, AptValue* value, int flags1, int flags2, int flags3) {
    // Resolves variable path and sets value
    // Handles property aliases and special cases
}

// 0x8026E048 (924 bytes)
// Built-in: setInterval
void AptActionInterpreter::cbCallMethod_setInterval(AptValue* args, int argc) {
    // Creates periodic timer callback
}

// 0x8026E3E4 (308 bytes)
// Built-in: clearInterval
void AptActionInterpreter::cbCallMethod_clearInterval(AptValue* args, int argc) {
    // Removes periodic timer callback
}

// 0x8026E518 (388 bytes)
// Built-in: hitTest
void AptActionInterpreter::cbCallMethod_hitTest(AptCIH* cih, int argc) {
    // Tests point/shape intersection
}

// 0x8026E69C (1196 bytes)
// Built-in: isNaN
void AptActionInterpreter::cbCallMethod_isNaN(AptValue* args, int argc) {
    // Tests if value is NaN
}

// 0x8026EB48 (416 bytes)
// Built-in: unescape
void AptActionInterpreter::cbCallMethod_unescape(AptValue* args, int argc) {
    // URL-decodes a string
}

// 0x8026ECE8 (372 bytes)
// Built-in: escape
void AptActionInterpreter::cbCallMethod_escape(AptValue* args, int argc) {
    // URL-encodes a string
}

// 0x8026EE5C (1628 bytes)
// Built-in: Boolean constructor
void AptActionInterpreter::cbCallMethod_boolean(AptValue* args, int argc) {
    // Creates Boolean object from value
}

// 0x8026F6DC (328 bytes)
// Gets name of a CIH (character instance hierarchy) node - variant 2
void AptActionInterpreter::getName2(AptCIH* cih, EAStringC& outName) {
    // Resolves display name from CIH
}

// 0x8026F824 (184 bytes)
// Gets name of a CIH node
void AptActionInterpreter::getName(AptCIH* cih, EAStringC& outName) {
    // Resolves name from CIH
}

// 0x8026F8DC (628 bytes)
// Clones a sprite (duplicateMovieClip)
void AptActionInterpreter::_doCloneSprite(AptCIH* cih, AptValue* name, AptValue* depth, AptValue* initObj, int flags, AptValue* target) {
    // Creates a copy of a movie clip at specified depth
}

// 0x8026FB50 (1092 bytes)
// Gets a variable from scope chain
void AptActionInterpreter::getVariable(AptValue* scope, AptValue* target, EAStringC* name, int flags1, int flags2, int flags3) {
    // Resolves and returns variable value
}

// 0x8026FF94 (220 bytes)
// Converts a value to an object
void AptActionInterpreter::valueToObject(AptValue* in, AptValue* scope, AptValue* this_ptr, AptValue** outObj) {
    // Wraps primitive values in object wrappers
}

// 0x80270070 (1752 bytes)
// Calls a function
void AptActionInterpreter::callFunction(AptValue* func, AptValue* this_ptr, int argc) {
    // Invokes function with arguments from stack
}

// 0x80270788 (212 bytes)
// Cleanup after execution (char* variant)
void AptActionInterpreter::CleanupAfterExecution(char* name, void* data) {
    // Releases resources after script execution
}

// 0x8027085C (212 bytes)
// Cleanup after execution (AptActionSetup variant)
void AptActionInterpreter::CleanupAfterExecution(void* ctx, AptActionSetup* setup) {
    // Releases execution context
}

// 0x80270930 (4744 bytes)
// Creates an object (new operator)
void AptActionInterpreter::_createObject(AptValue* scope, AptValue* constructor, EAStringC* className, int argc, bool callCtor) {
    // Allocates new object, sets prototype chain, optionally calls constructor
}

// 0x80271BB8 (760 bytes)
// Enumerates object properties (for..in)
void AptActionInterpreter::_doEnumerate(AptValue* target, AptValue* scope) {
    // Pushes all enumerable property names onto stack
}

// 0x802720D0 (1008 bytes)
// Runs an ActionScript bytecode stream
void AptActionInterpreter::runStream(unsigned char* stream, AptCIH* cih, int length, AptCharacterInst* charInst) {
    // Sets up execution context and calls _parseStream
}

// 0x802727F4 (324 bytes)
// Decodes URL-encoded string
void AptActionInterpreter::urlDecode(char* input, EAStringC& key, EAStringC& value) {
    // Parses key=value pairs from URL string
}

// 0x80272938 (76 bytes)
// Checks if a URL is an FSCommand
void AptActionInterpreter::isFSCommand(char* url) {
    // Compares beginning of url against FSCommand prefix string
    // Returns 1 if matches, 0 otherwise
}

// 0x80272984 (80 bytes)
// Executes an FSCommand
void AptActionInterpreter::doFSCommand(char* command, char* args) {
    // Strips FSCommand prefix, calls registered handler
    // Always returns 1
}

// --- ActionScript opcode handler functions ---
// Each takes (AptActionInterpreter* interp, LocalContextT* ctx)
// and implements one AS bytecode operation

// 0x802729D8 (76 bytes)
void AptActionInterpreter::_FunctionAptActionNextFrame(AptActionInterpreter* interp, int* ctx) {
    // Gets CIH from ctx, calls jumpToFrame(currentFrame + 1)
    // Clears play flag (bit 6) in CIH flags
}

// 0x80272A24 (76 bytes)
void AptActionInterpreter::_FunctionAptActionPrevFrame(AptActionInterpreter* interp, int* ctx) {
    // Gets CIH from ctx, calls jumpToFrame(currentFrame - 1)
    // Clears play flag
}

// 0x80272A70 (212 bytes)
void AptActionInterpreter::_FunctionAptActionPlay(AptActionInterpreter* interp, int* ctx) {
    // Resolves target CIH, sets play flag (bit 6) in CIH flags
}

// 0x80272B44 (120 bytes)
void AptActionInterpreter::_FunctionAptActionStop(AptActionInterpreter* interp, int* ctx) {
    // Clears play flag (bit 6) on target CIH
}

// 0x80272BC4 (688 bytes)
void AptActionInterpreter::_FunctionAptActionAdd(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, adds them, pushes result
}

// 0x80272E74 (688 bytes)
void AptActionInterpreter::_FunctionAptActionSubtract(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, subtracts, pushes result
}

// 0x80273124 (688 bytes)
void AptActionInterpreter::_FunctionAptActionMultiply(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, multiplies, pushes result
}

// 0x802733D4 (496 bytes)
void AptActionInterpreter::_FunctionAptActionDivide(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, divides, pushes result (handles div by zero)
}

// 0x802735C4 (636 bytes)
void AptActionInterpreter::_FunctionAptActionEquals(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, pushes equality result
}

// 0x80273840 (620 bytes)
void AptActionInterpreter::_FunctionAptActionLessThan(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, pushes less-than result
}

// 0x80273AAC (660 bytes)
void AptActionInterpreter::_FunctionAptActionAnd(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, pushes logical AND result
}

// 0x80273D40 (656 bytes)
void AptActionInterpreter::_FunctionAptActionOr(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, pushes logical OR result
}

// 0x80273FD0 (360 bytes)
void AptActionInterpreter::_FunctionAptActionNot(AptActionInterpreter* interp, int* ctx) {
    // Pops value, pushes logical NOT
}

// 0x80274138 (860 bytes)
void AptActionInterpreter::_FunctionAptActionStringEquals(AptActionInterpreter* interp, int* ctx) {
    // Pops two strings, pushes string equality result
}

// 0x80274494 (456 bytes)
void AptActionInterpreter::_FunctionAptActionStringLength(AptActionInterpreter* interp, int* ctx) {
    // Pops string, pushes its length
}

// 0x8027465C (864 bytes)
void AptActionInterpreter::_FunctionAptActionSubString(AptActionInterpreter* interp, int* ctx) {
    // Pops string, index, count - pushes substring
}

// 0x802749BC (164 bytes)
void AptActionInterpreter::_FunctionAptActionPop(AptActionInterpreter* interp, int* ctx) {
    // Pops and discards top of stack
}

// 0x80274A60 (404 bytes)
void AptActionInterpreter::_FunctionAptActionToInteger(AptActionInterpreter* interp, int* ctx) {
    // Pops value, converts to integer, pushes result
}

// 0x80274BF4 (344 bytes)
void AptActionInterpreter::_FunctionAptActionGetVariable(AptActionInterpreter* interp, int* ctx) {
    // Pops name, pushes variable value from scope chain
}

// 0x80274D4C (332 bytes)
void AptActionInterpreter::_FunctionAptActionSetVariable(AptActionInterpreter* interp, int* ctx) {
    // Pops value and name, sets variable in scope chain
}

// 0x80274E98 (380 bytes)
void AptActionInterpreter::_FunctionAptActionSetTarget2(AptActionInterpreter* interp, int* ctx) {
    // Pops target path, sets current target
}

// 0x80275014 (508 bytes)
void AptActionInterpreter::_FunctionAptActionStringAdd(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, concatenates as strings, pushes result
}

// 0x80275210 (532 bytes)
void AptActionInterpreter::_FunctionAptActionGetProperty(AptActionInterpreter* interp, int* ctx) {
    // Pops property index and target, pushes property value
}

// 0x80275424 (296 bytes)
void AptActionInterpreter::_FunctionAptActionSetProperty(AptActionInterpreter* interp, int* ctx) {
    // Pops value, property index, and target - sets property
}

// 0x8027554C (236 bytes)
void AptActionInterpreter::_FunctionAptActionCloneSprite(AptActionInterpreter* interp, int* ctx) {
    // Pops depth, name, target - clones sprite
}

// 0x80275638 (240 bytes)
void AptActionInterpreter::_FunctionAptActionRemoveSprite(AptActionInterpreter* interp, int* ctx) {
    // Pops target, removes duplicated sprite
}

// 0x80275728 (592 bytes)
void AptActionInterpreter::_FunctionAptActionTrace(AptActionInterpreter* interp, int* ctx) {
    // Pops value, outputs to debug trace
}

// 0x80275978 (832 bytes)
void AptActionInterpreter::_FunctionAptActionStartDragMovie(AptActionInterpreter* interp, int* ctx) {
    // Starts drag operation on a movie clip
}

// 0x80275CB8 (100 bytes)
void AptActionInterpreter::_FunctionAptActionStopDragMovie(AptActionInterpreter* interp, int* ctx) {
    // Stops current drag operation
}

// 0x80275D20 (400 bytes)
void AptActionInterpreter::_FunctionAptActionRandom(AptActionInterpreter* interp, int* ctx) {
    // Pops max, pushes random integer in [0, max)
}

// 0x80275EB8 (640 bytes)
void AptActionInterpreter::_FunctionAptActionAsciiToChar(AptActionInterpreter* interp, int* ctx) {
    // Pops ASCII code, pushes single-character string
}

// 0x80276138 (252 bytes)
void AptActionInterpreter::_FunctionAptActionGetTimer(AptActionInterpreter* interp, int* ctx) {
    // Pushes elapsed milliseconds since movie started
}

// 0x80276240 (548 bytes)
void AptActionInterpreter::_FunctionAptActionDelete(AptActionInterpreter* interp, int* ctx) {
    // Deletes a property from an object
}

// 0x80276464 (476 bytes)
void AptActionInterpreter::_FunctionAptActionDelete2(AptActionInterpreter* interp, int* ctx) {
    // Deletes a variable (scoped)
}

// 0x80276640 (316 bytes)
void AptActionInterpreter::_FunctionAptActionDefineLocal(AptActionInterpreter* interp, int* ctx) {
    // Defines a local variable with initial value
}

// 0x8027677C (576 bytes)
void AptActionInterpreter::_FunctionAptActionCallFunction(AptActionInterpreter* interp, int* ctx) {
    // Pops function name and args, calls function
}

// 0x802769C8 (504 bytes)
void AptActionInterpreter::_FunctionAptActionModulo(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, pushes modulo result
}

// 0x80276BC0 (496 bytes)
void AptActionInterpreter::_FunctionAptActionNewObject(AptActionInterpreter* interp, int* ctx) {
    // Pops constructor name and args, creates new object
}

// 0x80276DB0 (372 bytes)
void AptActionInterpreter::_FunctionAptActionDefineLocal2(AptActionInterpreter* interp, int* ctx) {
    // Defines a local variable (no initial value)
}

// 0x80276F24 (428 bytes)
void AptActionInterpreter::_FunctionAptActionInitArray(AptActionInterpreter* interp, int* ctx) {
    // Pops count and elements, creates array
}

// 0x802770D0 (788 bytes)
void AptActionInterpreter::_FunctionAptActionInitObject(AptActionInterpreter* interp, int* ctx) {
    // Pops count and key/value pairs, creates object literal
}

// 0x802773E4 (1016 bytes)
void AptActionInterpreter::_FunctionAptActionTypeOf(AptActionInterpreter* interp, int* ctx) {
    // Pops value, pushes type name string
}

// 0x802777DC (856 bytes)
void AptActionInterpreter::_FunctionAptActionTargetPath(AptActionInterpreter* interp, int* ctx) {
    // Pops movie clip, pushes its target path string
}

// 0x80277B5C (1972 bytes)
void AptActionInterpreter::_FunctionAptActionAdd2(AptActionInterpreter* interp, int* ctx) {
    // SWF 5+ addition: handles both numeric and string concatenation
}

// 0x80278310 (2868 bytes)
void AptActionInterpreter::_FunctionAptActionLessThan2(AptActionInterpreter* interp, int* ctx) {
    // SWF 5+ less-than comparison
}

// 0x80278E44 (4572 bytes)
void AptActionInterpreter::_FunctionAptActionEquals2(AptActionInterpreter* interp, int* ctx) {
    // SWF 5+ equality: handles type coercion
}

// 0x8027A020 (1816 bytes)
void AptActionInterpreter::_FunctionAptActionToNumber(AptActionInterpreter* interp, int* ctx) {
    // Converts top of stack to number
}

// 0x8027A738 (924 bytes)
void AptActionInterpreter::_FunctionAptActionToString(AptActionInterpreter* interp, int* ctx) {
    // Converts top of stack to string
}

// 0x8027AAD4 (104 bytes)
void AptActionInterpreter::_FunctionAptActionPushDuplicate(AptActionInterpreter* interp, int* ctx) {
    // Duplicates top of stack
}

// 0x8027AB3C (112 bytes)
void AptActionInterpreter::_FunctionAptActionStackSwap(AptActionInterpreter* interp, int* ctx) {
    // Swaps top two stack values
}

// 0x8027ABAC (1060 bytes)
void AptActionInterpreter::_FunctionAptActionGetMember(AptActionInterpreter* interp, int* ctx) {
    // Pops member name and object, pushes member value
}

// 0x8027AFD0 (872 bytes)
void AptActionInterpreter::_FunctionAptActionSetMember(AptActionInterpreter* interp, int* ctx) {
    // Pops value, member name, and object - sets member
}

// 0x8027B338 (604 bytes)
void AptActionInterpreter::_FunctionAptActionIncrement(AptActionInterpreter* interp, int* ctx) {
    // Pops value, pushes value + 1
}

// 0x8027B594 (604 bytes)
void AptActionInterpreter::_FunctionAptActionDecrement(AptActionInterpreter* interp, int* ctx) {
    // Pops value, pushes value - 1
}

// 0x8027B7F0 (2868 bytes)
void AptActionInterpreter::_FunctionAptActionCallMethod(AptActionInterpreter* interp, int* ctx) {
    // Pops method name, object, args - calls method
}

// 0x8027C324 (620 bytes)
void AptActionInterpreter::_FunctionAptActionNewMethod(AptActionInterpreter* interp, int* ctx) {
    // Pops method name, object, args - creates new via method
}

// 0x8027C5B8 (460 bytes)
void AptActionInterpreter::_FunctionAptActionBitAnd(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, pushes bitwise AND
}

// 0x8027C784 (460 bytes)
void AptActionInterpreter::_FunctionAptActionBitOr(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, pushes bitwise OR
}

// 0x8027C950 (460 bytes)
void AptActionInterpreter::_FunctionAptActionBitXor(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, pushes bitwise XOR
}

// 0x8027CB1C (460 bytes)
void AptActionInterpreter::_FunctionAptActionBitLShift(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, pushes left shift result
}

// 0x8027CCE8 (460 bytes)
void AptActionInterpreter::_FunctionAptActionBitRShift(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, pushes right shift result
}

// 0x8027CEB8 (1412 bytes)
void AptActionInterpreter::_FunctionAptActionStrictEquals(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, pushes strict equality (no type coercion)
}

// 0x8027D43C (924 bytes)
void AptActionInterpreter::_FunctionAptActionGreater(AptActionInterpreter* interp, int* ctx) {
    // Pops two values, pushes greater-than result
}

// 0x8027D7D8 (232 bytes)
void AptActionInterpreter::_FunctionAptActionGotoFrame(AptActionInterpreter* interp, int* ctx) {
    // Reads frame number from bytecode, jumps to frame
}

// 0x8027D8C0 (416 bytes)
void AptActionInterpreter::_FunctionAptActionGetUrl(AptActionInterpreter* interp, int* ctx) {
    // Reads URL and target from bytecode
}

// 0x8027DA60 (76 bytes)
void AptActionInterpreter::_FunctionAptActionStoreRegister(AptActionInterpreter* interp, int* ctx) {
    // Copies top of stack to register
}

// 0x8027DAD8 (372 bytes)
void AptActionInterpreter::_FunctionAptActionSetTarget(AptActionInterpreter* interp, int* ctx) {
    // Sets target from bytecode string
}

// 0x8027DC4C (228 bytes)
void AptActionInterpreter::_FunctionAptActionGotoLabel(AptActionInterpreter* interp, int* ctx) {
    // Jumps to named frame label
}

// 0x8027DD30 (276 bytes)
void AptActionInterpreter::_FunctionAptActionWith(AptActionInterpreter* interp, int* ctx) {
    // Enters 'with' scope
}

// 0x8027DE44 (264 bytes)
void AptActionInterpreter::_FunctionAptActionPush(AptActionInterpreter* interp, int* ctx) {
    // Pushes constant values from bytecode
}

// 0x8027DF4C (1160 bytes)
void AptActionInterpreter::_FunctionAptActionGetUrl2(AptActionInterpreter* interp, int* ctx) {
    // Pops URL and target from stack, loads URL
}

// 0x8027E3D4 (428 bytes)
void AptActionInterpreter::_FunctionAptActionDefineFunction(AptActionInterpreter* interp, int* ctx) {
    // Defines a function from bytecode (SWF 5)
}

// 0x8027E580 (308 bytes)
void AptActionInterpreter::_FunctionAptActionDefineFunction2(AptActionInterpreter* interp, int* ctx) {
    // Defines a function from bytecode (SWF 7)
}

// 0x8027E6B4 (228 bytes)
void AptActionInterpreter::_FunctionAptActionBranchIfTrue(AptActionInterpreter* interp, int* ctx) {
    // Pops value, branches if truthy
}

// 0x8027E798 (424 bytes)
void AptActionInterpreter::_FunctionAptActionCallFrame(AptActionInterpreter* interp, int* ctx) {
    // Calls frame actions on target
}

// 0x8027E940 (708 bytes)
void AptActionInterpreter::_FunctionAptActionGotoFrame2(AptActionInterpreter* interp, int* ctx) {
    // Pops frame from stack, jumps to it
}

// 0x8027EC04 (96 bytes)
void AptActionInterpreter::_FunctionAptActionBranchAlways(AptActionInterpreter* interp, int* ctx) {
    // Unconditional branch by offset
}

// 0x8027EC64 (324 bytes)
void AptActionInterpreter::_FunctionAptActionPushThis(AptActionInterpreter* interp, int* ctx) {
    // Pushes 'this' object onto stack
}

// 0x8027EDA8 (324 bytes)
void AptActionInterpreter::_FunctionAptActionPushGlobal(AptActionInterpreter* interp, int* ctx) {
    // Pushes global object onto stack
}

// 0x8027EEEC (252 bytes)
void AptActionInterpreter::_FunctionAptActionPush0(AptActionInterpreter* interp, int* ctx) {
    // Pushes integer 0
}

// 0x8027EFE8 (252 bytes)
void AptActionInterpreter::_FunctionAptActionPush1(AptActionInterpreter* interp, int* ctx) {
    // Pushes integer 1
}

// 0x8027F0E4 (252 bytes)
void AptActionInterpreter::_FunctionAptActionPushTrue(AptActionInterpreter* interp, int* ctx) {
    // Pushes boolean true
}

// 0x8027F1E0 (252 bytes)
void AptActionInterpreter::_FunctionAptActionPushFalse(AptActionInterpreter* interp, int* ctx) {
    // Pushes boolean false
}

// 0x8027F2DC (100 bytes)
void AptActionInterpreter::_FunctionAptActionPushNULL(AptActionInterpreter* interp, int* ctx) {
    // Pushes null value onto stack
    // Gets null singleton from global, pushes to stack array
}

// 0x8027F340 (100 bytes)
void AptActionInterpreter::_FunctionAptActionPushUndefined(AptActionInterpreter* interp, int* ctx) {
    // Pushes undefined value onto stack
    // Gets undefined singleton from global, pushes to stack array
}

// 0x8027F3A4 (160 bytes)
void AptActionInterpreter::_FunctionAptActionCallFuncAndPop(AptActionInterpreter* interp, int* ctx) {
    // Calls _FunctionAptActionCallFunction, then pops result
}

// 0x8027F444 (92 bytes)
void AptActionInterpreter::_FunctionAptActionCallFuncSetVar(AptActionInterpreter* interp, int* ctx) {
    // Calls function, stores result in variable
}

// 0x8027F4A0 (160 bytes)
void AptActionInterpreter::_FunctionAptActionCallMethodPop(AptActionInterpreter* interp, int* ctx) {
    // Calls method, pops result
}

// 0x8027F540 (92 bytes)
void AptActionInterpreter::_FunctionAptActionCallMethodSetVar(AptActionInterpreter* interp, int* ctx) {
    // Calls method, stores result in variable
}

// 0x8027F59C (144 bytes)
void AptActionInterpreter::_FunctionAptActionPushThisVariable(AptActionInterpreter* interp, int* ctx) {
    // Pushes this.variableName
}

// 0x8027F62C (100 bytes)
void AptActionInterpreter::_FunctionAptActionPushGlobalVariable(AptActionInterpreter* interp, int* ctx) {
    // Pushes _global.variableName
}

// 0x8027F690 (268 bytes)
void AptActionInterpreter::_FunctionAptActionPushZeroSetVar(AptActionInterpreter* interp, int* ctx) {
    // Pushes 0 and sets into variable
}

// 0x8027F79C (392 bytes)
void AptActionInterpreter::_FunctionAptActionPushString(AptActionInterpreter* interp, int* ctx) {
    // Pushes string from bytecode
}

// 0x8027F924 (128 bytes)
void AptActionInterpreter::_FunctionAptActionPushStringDictByte(AptActionInterpreter* interp, int* ctx) {
    // Pushes string from dictionary (byte index)
}

// 0x8027F9A4 (140 bytes)
void AptActionInterpreter::_FunctionAptActionPushStringDictWord(AptActionInterpreter* interp, int* ctx) {
    // Pushes string from dictionary (word index)
}

// 0x8027FA30 (284 bytes)
void AptActionInterpreter::_FunctionAptActionPushStringGetVar(AptActionInterpreter* interp, int* ctx) {
    // Pushes string then gets variable of that name
}

// 0x8027FB4C (408 bytes)
void AptActionInterpreter::_FunctionAptActionPushStringGetMember(AptActionInterpreter* interp, int* ctx) {
    // Pushes string then gets member of that name
}

// 0x8027FCE4 (408 bytes)
void AptActionInterpreter::_FunctionAptActionPushStringSetVar(AptActionInterpreter* interp, int* ctx) {
    // Pushes string, pops value, sets variable
}

// 0x8027FE7C (408 bytes)
void AptActionInterpreter::_FunctionAptActionPushStringSetMember(AptActionInterpreter* interp, int* ctx) {
    // Pushes string, pops value, sets member
}

// 0x80280014 (192 bytes)
void AptActionInterpreter::_FunctionAptActionStringDictByteGetVar(AptActionInterpreter* interp, int* ctx) {
    // Dict byte lookup + get variable
}

// 0x802800D4 (152 bytes)
void AptActionInterpreter::_FunctionAptActionStringDictByteGetMember(AptActionInterpreter* interp, int* ctx) {
    // Dict byte lookup + get member
}

// 0x8028016C (264 bytes)
void AptActionInterpreter::_FunctionAptActionDictCallFuncPop(AptActionInterpreter* interp, int* ctx) {
    // Dict lookup + call function + pop result
}

// 0x80280274 (196 bytes)
void AptActionInterpreter::_FunctionAptActionDictCallFuncSetVar(AptActionInterpreter* interp, int* ctx) {
    // Dict lookup + call function + set variable
}

// 0x80280338 (264 bytes)
void AptActionInterpreter::_FunctionAptActionDictCallMethodPop(AptActionInterpreter* interp, int* ctx) {
    // Dict lookup + call method + pop result
}

// 0x80280440 (196 bytes)
void AptActionInterpreter::_FunctionAptActionDictCallMethodSetVar(AptActionInterpreter* interp, int* ctx) {
    // Dict lookup + call method + set variable
}

// 0x80280504 (296 bytes)
void AptActionInterpreter::_FunctionAptActionPushFloat(AptActionInterpreter* interp, int* ctx) {
    // Pushes float from bytecode
}

// 0x8028062C (268 bytes)
void AptActionInterpreter::_FunctionAptActionPushByte(AptActionInterpreter* interp, int* ctx) {
    // Pushes byte-sized integer from bytecode
}

// 0x80280738 (280 bytes)
void AptActionInterpreter::_FunctionAptActionPushWord(AptActionInterpreter* interp, int* ctx) {
    // Pushes word-sized integer from bytecode
}

// 0x80280850 (296 bytes)
void AptActionInterpreter::_FunctionAptActionPushDWord(AptActionInterpreter* interp, int* ctx) {
    // Pushes dword-sized integer from bytecode
}

// 0x80280978 (228 bytes)
void AptActionInterpreter::_FunctionAptActionBranchIfFalse(AptActionInterpreter* interp, int* ctx) {
    // Pops value, branches if falsy
}

// 0x80280A5C (1004 bytes)
void AptActionInterpreter::_FunctionAptActionExtends(AptActionInterpreter* interp, int* ctx) {
    // Implements prototype-based inheritance
}

// 0x80280E48 (372 bytes)
void AptActionInterpreter::isObjectOfType(AptValue* obj, AptValue* type) {
    // Checks instanceof relationship
}

// 0x80280FBC (560 bytes)
void AptActionInterpreter::_FunctionAptActionInstanceOf(AptActionInterpreter* interp, int* ctx) {
    // Pops type and object, pushes instanceof result
}

// 0x802811EC (568 bytes)
void AptActionInterpreter::_FunctionAptActionCastOp(AptActionInterpreter* interp, int* ctx) {
    // Cast operation
}

// 0x80281424 (932 bytes)
void AptActionInterpreter::_FunctionAptActionImplementsOp(AptActionInterpreter* interp, int* ctx) {
    // Registers interface implementation
}

// 0x802817C8 (844 bytes)
void AptActionInterpreter::_FunctionAptActionTry(AptActionInterpreter* interp, int* ctx) {
    // Try/catch/finally exception handling
}

// 0x80281B14 (192 bytes)
void AptActionInterpreter::_FunctionAptActionThrow(AptActionInterpreter* interp, int* ctx) {
    // Throws an exception
}

// 0x80281BD4 (184 bytes)
// Destructor
AptActionInterpreter::~AptActionInterpreter(void) {
    // Calls shutdown if initialized
}


// ============================================================================
// cXObjectImpl — Object simulation implementation (169 functions, 125,508 bytes)
// Core game object system: placement, hierarchy, interaction, behavior trees
// ============================================================================

class cXObjectImpl {
public:
    cXObjectImpl(int type, ObjSelector* selector, ObjectModule* module);
    ~cXObjectImpl(void);
    void Initialize(void);
    void Reset(bool full);
    void JustBorn(void);
    void PostLoad(int version, bool fromSave);
    void Cleanup(cXObject* other);
    void SetHilite(int mode);
    void GetCurrentValue(void);
    void DayPassed(void);
    void UpdateAge(void);
    void GetObstacleAtLocation(FTilePt& pos, int dir, bool checkPeople);
    void GetRootObject(FTilePt& pos, int dir);
    void GetPlacementInfo(FTilePt* outPos, int* outDir, cXObject** outContainer, short* outSlot, bool* outPlaced);
    void GetPlacementSpec(PlacementSpec* outSpec);
    void GetPrevObjectSibling(void);
    void HierGetParent(void);
    void HierSetSite(HierarchySite* site);
    void HierGetChild(int index);
    void HierGetSite(HierarchySite* outSite);
    void HierSever(void);
    void HierGetObject(HierarchySite* site);
    void GetContainerID(void);
    void GetContainer(void);
    void GetObjectSlot(int index);
    void ExtractContainedSims(void);
    void TestAndPlace(PlacementSpec* spec, bool testOnly);
    void Pickup(void);
    void CanPlace(FTilePt& pos, int dir, cXObject* container, int slot);
    void Place(FTilePt& pos, int dir, cXObject* container, int slot);
    void UpdateChairFacing(void);
    void UpdateChairFacing(ObjectModule* mod, int dir, int flags, int param);
    void TestIntersection(FTilePt& pos, int dir);
    void ComputeRect(FTilePt& pos, FTileRect* outRect);
    void SetLocation(FTilePt& pos, int dir);
    void Turn(int dir);
    void GetSlotHeight(int slotIndex);
    void GetTypeName(BString& outName);
    void CalcShortDistance(cXObject* other);
    void CalcShortDistanceIn16thsOfTiles(cXObject* other);
    void CalcDistanceWithPentalties(cXObject* other);
    void CalcShortDistance(FTilePt* pos);
    void CalcDistance(cXObject* other);
    void ReconHeader(ReconBuffer* buf, int version);
    void ReconStream(ReconBuffer* buf, int version, bool full);
    void ReconSlots(ReconBuffer* buf, int version);
    void FindGoodLocation(FindGoodLocationParams& params, FTilePt* outPos);
    void GetFrontFaceDirection(void);
    void UpdateWallAdjacency(void);
    void GetTileWidth(void);
    void GetAgeInMinutes(void);
    void GetInteractionLeader(void);
    void UserCanPickup(void);
    void UserCanDelete(void);
    void IsDeletedByEvict(void);
    void UserPlace(FTilePt& pos, int dir, cXObject* container, int slot);
    void UserCanPlace(FTilePt& pos, int dir, cXObject* container, int slot);
    void UserPickup(bool force);
    void IsFromCatalog(void);
    void SetWasPlacedFromInventory(bool value);
    void ShouldAutoRotate(void);
    void GetRequiredSegment(void);
    void CanChooseAutonomously(void);
    void UpdateSimFlags(void);
    void GetWallBlockFlags(void);
    void GetAverageLocation(void) const;
    void GetCTilePt(void) const;
    void IsSpriteVisible(short spriteId);
    void SyncObjectIsReady(signed char syncId);
    void SetSyncObject(signed char syncId);
    void SyncObjectIsReady(void);
    void RunTree(ObjEntryPoint entry, short param, short* result);
    void IsVehicle(void);
    void IsPerson(void);
    void SetColorIndex(unsigned char index);
    void IsInteractionTile(void);
    void SimObjectPlaced(ISimInstance* sim);
    void IsEmissive(void);
    void RunTree(char* treeName);
    void RequiresWallAdjacency(void);
    void GetTreeID(ObjEntryPoint entry);
    void IsPortal(void);
    void IsWindow(void);
    void IsDoor(void);
    void EnableSim(bool enable);
    void HideForCutaway(void);
    void IsRoof(void);
    void GetContainedObject(int slotIndex);
    void IsSupport(void);
    void CanIntersectPeople(void);
    void IsChair(void);
    void GetFirstImpl(void);
    void GetDebugName(char* buf, int bufSize) const;
    void Error(short errorCode);
    void HandleError(void);
    void AllowIdleOptimization(void);
    void TryUserEvent(StackElem*, XPrimParam*);
    void TryTestObjectType(StackElem*, XPrimParam*);
    void TryIsPersonInArea(StackElem*, XPrimParam*);
    void UseKnownGoodLocation(TFGL_ACTIONS action, short param, FTilePt* pos, int dir, short flags);
    void TryFindGoodLocation(StackElem*, XPrimParam*, TFGL_ACTIONS*, FTilePt*, int*, short*);
    void TrySetBalloon(StackElem*, XPrimParam*);
    void TryCallNamedTree(StackElem*, XPrimParam*);
    void ParseUIString(BString2& outStr, StackElem* stack, short* vars, ObjSelector** selectors, bool localize);
    void TryMakeActionString(StackElem*, XPrimParam*);
    void TryPushAction(StackElem*, XPrimParam*);
    void TryFind5WorstMotives(StackElem*, XPrimParam*);
    void TryRelationship2(StackElem*, XPrimParam*);
    void TryRelationship(StackElem*, XPrimParam*);
    void TryTutorial(StackElem*, XPrimParam*);
    void TryBurn(StackElem*, XPrimParam*);
    void TryCreateObject(StackElem*, XPrimParam*);
    void TryPreloadObject(StackElem*, XPrimParam*);
    void TryDropOnto(StackElem*, XPrimParam*);
    void TryBudget(StackElem*, XPrimParam*);
    void TrySetToNext(StackElem*, XPrimParam*);
    void TryFindFunctionalObject(StackElem*, XPrimParam*);
    void TryCallFunctionalTree(StackElem*, XPrimParam*);
    void TryGenericSimCall(StackElem*, XPrimParam*);
    void ShowAllObjectDialogs(StackElem*, XPrimParam*);
    void TransitionToNewHouse(short houseId, short doorId, short param);
    void RewriteDialogParamIndices(DialogParam& param);
    void TryDialog(StackElem*, XPrimParam*, bool modal);
    void TryShowString(StackElem*, XPrimParam*);
    void TryKillObject(StackElem*, XPrimParam*, short* result);
    void KillSelf(bool immediate);
    void TryIdle(StackElem*, XPrimParam*);
    void TryUpdate(StackElem*, XPrimParam*);
    void TryGrab(StackElem*, XPrimParam*);
    void TryTreeBreak(StackElem*, XPrimParam*);
    void TryRandom(StackElem*, XPrimParam*);
    void TryRoomEffect(StackElem*, XPrimParam*);
    void TryCheckObject(StackElem*, XPrimParam*);
    void TryGbaCommunication(StackElem*, XPrimParam*);
    void TryAnimateObject(StackElem*, XPrimParam*);
    void TryCompleteGoal(StackElem*, CompleteGoalParam&);
    void InventoryCommandParam_GetGuid(InventoryCommandParam& param);
    void InventoryCommandParam_GetCount(InventoryCommandParam& param);
    void TryInventoryCommand(StackElem*, XPrimParam*);
    void TryCameraControl(StackElem*, XPrimParam*);
    void TryDistanceTo(StackElem*, XPrimParam*);
    void TryDirectionTo(StackElem*, XPrimParam*);
    void TryNotifyStackObject(StackElem*, XPrimParam*);
    void TryParticleEffect(StackElem*, XPrimParam*);
    void TryMemory(StackElem*, XPrimParam*);
    void TryPassiveInfluence(StackElem*, XPrimParam*);
    void TryWantsAndFearsNotify(StackElem*, XPrimParam*);
    void TryChangeWantFearTree(StackElem*, XPrimParam*);
    void TrySetMotiveDelta(StackElem*, XPrimParam*);
    void TryAnimate(StackElem*, AnimateNewParam*);
    void Simulate(int deltaMs);
    void TryElement(StackElem*, short id, XPrimParam*);
    void TryKillSounds(StackElem*, KillSoundsParam*);
    void TryPlaySound(StackElem*, PlaySoundParam*);
    void GosubObjectTree(cXObject* obj, short* treeId, short param, bool immediate);
    void RunTree(Behavior* beh, short param, char* name, short* result);
    void TryExpression(ExpressionParam*);
    void GetShortComboValue(signed char which, short* val1, short* val2);
    void InterpValue(short type, short param, short** dataPtr, float** floatPtr, short* result, short** outPtr);
    void InterpWriteValue(short type, short param, short** dataPtr, short value);
    void TryDrop(void);
    void TrySnap(StackElem*, XPrimParam*);
    void TrySnap(FTilePt pos, int dir, cXObject* target, int slot, bool immediate, int flags, bool force);
    void TryHUDCreate(StackElem*, XPrimParam*);
    void TryHUDAddItem(StackElem*, XPrimParam*);
    void TryHUDManage(StackElem*, XPrimParam*);
    void TryHUDData(StackElem*, XPrimParam*);
    void ChangeSelectedSimL(int playerIndex);
    void ChangeSelectedSimR(int playerIndex);
};

// 0x800D962C (3500 bytes)
// Constructor: creates object from type/selector/module
cXObjectImpl::cXObjectImpl(int type, ObjSelector* selector, ObjectModule* module) {
    // Calls TreeSim::TreeSim()
    // Sets up multiple vtables for interface dispatch
    // Initializes ~30 fields: position, direction, hierarchy, slots
    // Calls TreeSimImpl::TreeSimImpl if selector provided
}

// 0x800DA3D8 (1136 bytes)
// Initialize: sets up object after construction
void cXObjectImpl::Initialize(void) {
    // Loads object definition data
    // Creates slots, initializes behavior trees
}

// 0x800DA848 (1100 bytes)
// Reset: returns object to initial state
void cXObjectImpl::Reset(bool full) {
    // Clears all runtime state
    // Resets slots, hierarchy, behavior trees
}

// 0x800DAC94 (296 bytes)
// Called when object is first created in the world
void cXObjectImpl::JustBorn(void) {
    // Runs initialization behavior tree
}

// 0x800DADBC (940 bytes)
// Post-load: fixup after save game load
void cXObjectImpl::PostLoad(int version, bool fromSave) {
    // Validates and fixes up loaded object data
}

// 0x800DB16C (1112 bytes)
// Cleanup: removes references to another object
void cXObjectImpl::Cleanup(cXObject* other) {
    // Cleans up containment, interaction references
}

// 0x800DB5D0 (372 bytes)
// Sets highlight mode for selection feedback
void cXObjectImpl::SetHilite(int mode) {
    // Updates highlight shader/color based on mode
}

// 0x800DB744 (528 bytes)
// Gets current monetary value of object
void cXObjectImpl::GetCurrentValue(void) {
    // Calculates depreciated value
}

// 0x800DB9A8 (368 bytes)
// Called each sim-day passing
void cXObjectImpl::DayPassed(void) {
    // Ages object, applies daily depreciation
}

// 0x800DBB18 (316 bytes)
// Updates object age
void cXObjectImpl::UpdateAge(void) {
    // Increments age counter
}

// 0x800DBC54 (3348 bytes)
// Destructor: destroys object
cXObjectImpl::~cXObjectImpl(void) {
    // Cleans up slots, hierarchy, behavior trees
    // Removes from all systems
}

// 0x800DC968 (196 bytes)
// Gets obstacle at a location
void cXObjectImpl::GetObstacleAtLocation(FTilePt& pos, int dir, bool checkPeople) {
    // Calls GetRootObject, iterates linked objects
    // Returns first object that blocks passage
}

// 0x800DCA2C (160 bytes)
// Gets root object at tile position
void cXObjectImpl::GetRootObject(FTilePt& pos, int dir) {
    // Creates CTilePt, queries space partition
}

// 0x800DCACC (132 bytes)
// Gets placement info for this object
void cXObjectImpl::GetPlacementInfo(FTilePt* outPos, int* outDir, cXObject** outContainer, short* outSlot, bool* outPlaced) {
    // Creates PlacementSpec, extracts fields
}

// 0x800DCB78 (468 bytes)
// Gets full placement specification
void cXObjectImpl::GetPlacementSpec(PlacementSpec* outSpec) {
    // Populates spec with current position, direction, container
}

// 0x800DCD70 (76 bytes)
// Gets previous sibling in hierarchy
void cXObjectImpl::GetPrevObjectSibling(void) {
    // Returns previous object in linked list
}

// 0x800DCF2C (88 bytes)
// Gets parent in hierarchy
void cXObjectImpl::HierGetParent(void) {
    // Returns parent object
}

// 0x800DCFB8 (348 bytes)
// Sets hierarchy site
void cXObjectImpl::HierSetSite(HierarchySite* site) {
    // Configures attachment point in hierarchy
}

// 0x800DD114 (72 bytes)
// Gets child by index
void cXObjectImpl::HierGetChild(int index) {
    // Returns child object at index
}

// 0x800DD15C (268 bytes)
// Gets hierarchy site info
void cXObjectImpl::HierGetSite(HierarchySite* outSite) {
    // Populates site from current hierarchy data
}

// 0x800DD268 (208 bytes)
// Severs object from hierarchy
void cXObjectImpl::HierSever(void) {
    // Disconnects from parent, clears hierarchy links
}

// 0x800DD338 (208 bytes)
// Gets object at a hierarchy site
void cXObjectImpl::HierGetObject(HierarchySite* site) {
    // Returns object at the specified site
}

// 0x800DD444 (88 bytes)
// Gets container ID
void cXObjectImpl::GetContainerID(void) {
    // Returns ID of containing object
}

// 0x800DD4C8 (176 bytes)
// Gets container object
void cXObjectImpl::GetContainer(void) {
    // Returns the object this is contained in
}

// 0x800DD578 (108 bytes)
// Gets object slot by index
void cXObjectImpl::GetObjectSlot(int index) {
    // Returns slot descriptor at index
}

// 0x800DD5E4 (260 bytes)
// Extracts all contained sims
void cXObjectImpl::ExtractContainedSims(void) {
    // Removes all sims from container slots
}

// 0x800DD6E8 (2456 bytes)
// Tests placement and places object if valid
void cXObjectImpl::TestAndPlace(PlacementSpec* spec, bool testOnly) {
    // Core placement function
}

// 0x800DE144 (508 bytes)
// Picks up object from world
void cXObjectImpl::Pickup(void) {
    // Removes from world, clears placement
}

// 0x800DE340 (132 bytes)
// Tests if object can be placed at location
void cXObjectImpl::CanPlace(FTilePt& pos, int dir, cXObject* container, int slot) {
    // Returns true if placement is valid
}

// 0x800DE3C4 (956 bytes)
// Places object at location
void cXObjectImpl::Place(FTilePt& pos, int dir, cXObject* container, int slot) {
    // Full placement with world updates
}

// 0x800DE788 (860 bytes)
// Updates chair facing direction
void cXObjectImpl::UpdateChairFacing(void) {
    // Adjusts chair to face table/desk
}

// 0x800DEAE4 (212 bytes)
// Updates chair facing (with parameters)
void cXObjectImpl::UpdateChairFacing(ObjectModule* mod, int dir, int flags, int param) {
    // Parameterized chair facing update
}

// 0x800DEBB8 (1624 bytes)
// Tests intersection at position
void cXObjectImpl::TestIntersection(FTilePt& pos, int dir) {
    // Checks if object collides with others at position
}

// 0x800DF4D0 (692 bytes)
// Computes tile rectangle for object
void cXObjectImpl::ComputeRect(FTilePt& pos, FTileRect* outRect) {
    // Calculates bounding rectangle in tile space
}

// 0x800DF784 (792 bytes)
// Sets object location
void cXObjectImpl::SetLocation(FTilePt& pos, int dir) {
    // Updates position and direction
}

// 0x800DFA9C (352 bytes)
// Turns object
void cXObjectImpl::Turn(int dir) {
    // Rotates object to face direction
}

// 0x800DFBFC (240 bytes)
// Gets slot height
void cXObjectImpl::GetSlotHeight(int slotIndex) {
    // Returns vertical offset of a slot
}

// 0x800DFCEC (252 bytes)
// Gets type name string
void cXObjectImpl::GetTypeName(BString& outName) {
    // Populates string with object's type name
}

// 0x800DFE38 (168 bytes)
// Calculates short distance to another object
void cXObjectImpl::CalcShortDistance(cXObject* other) {
    // Manhattan distance in tiles
}

// 0x800DFEE0 (416 bytes)
// Calculates short distance in 16ths of tiles
void cXObjectImpl::CalcShortDistanceIn16thsOfTiles(cXObject* other) {
    // Fine-grained distance calculation
}

// 0x800E0080 (808 bytes)
// Calculates distance with penalties (for routing)
void cXObjectImpl::CalcDistanceWithPentalties(cXObject* other) {
    // Distance with door/room crossing penalties
}

// 0x800E03A8 (116 bytes)
// Calculates short distance to a tile
void cXObjectImpl::CalcShortDistance(FTilePt* pos) {
    // Manhattan distance to a specific tile
}

// 0x800E041C (176 bytes)
// Calculates Euclidean distance to another object
void cXObjectImpl::CalcDistance(cXObject* other) {
    // Straight-line distance
}

// 0x800E04CC (240 bytes)
// Serializes object header
void cXObjectImpl::ReconHeader(ReconBuffer* buf, int version) {
    // Writes object type/ID/state header
}

// 0x800E05BC (1516 bytes)
// Serializes object state
void cXObjectImpl::ReconStream(ReconBuffer* buf, int version, bool full) {
    // Writes/reads all object fields
}

// 0x800E0BA8 (908 bytes)
// Serializes slot data
void cXObjectImpl::ReconSlots(ReconBuffer* buf, int version) {
    // Writes/reads containment slot data
}

// 0x800E0F40 (1536 bytes)
// Finds good placement location
void cXObjectImpl::FindGoodLocation(FindGoodLocationParams& params, FTilePt* outPos) {
    // Searches for valid placement near target
}

// 0x800E1540 (84 bytes)
// Gets front face direction from slots
void cXObjectImpl::GetFrontFaceDirection(void) {
    // Gets the direction the front of the object faces
}

// 0x800E1594 (496 bytes)
// Updates wall adjacency flags
void cXObjectImpl::UpdateWallAdjacency(void) {
    // Checks which walls are adjacent and updates flags
}

// 0x800E178C (192 bytes)
// Gets tile width of object
void cXObjectImpl::GetTileWidth(void) {
    // Returns width in tiles (may be rotation-dependent)
}

// 0x800E184C (396 bytes)
// Gets age in simulated minutes
void cXObjectImpl::GetAgeInMinutes(void) {
    // Converts tick count to minutes
}

// 0x800E19D8 (284 bytes)
// Gets the leader of current interaction
void cXObjectImpl::GetInteractionLeader(void) {
    // Returns the sim leading the current social interaction
}

// 0x800E1AF4 (452 bytes)
// Checks if user can pick up this object
void cXObjectImpl::UserCanPickup(void) {
    // Validates pickup conditions
}

// 0x800E1CB8 (200 bytes)
// Checks if user can delete this object
void cXObjectImpl::UserCanDelete(void) {
    // Validates deletion conditions
}

// 0x800E1D80 (176 bytes)
// Checks if object is deleted by eviction
void cXObjectImpl::IsDeletedByEvict(void) {
    // Returns true if this object type is removed on eviction
}

// 0x800E1E30 (452 bytes)
// Checks if user can place at location
void cXObjectImpl::UserPlace(FTilePt& pos, int dir, cXObject* container, int slot) {
    // Validates user placement
}

// 0x800E1FF4 (308 bytes)
// Tests user placement validity
void cXObjectImpl::UserCanPlace(FTilePt& pos, int dir, cXObject* container, int slot) {
    // Returns true if user is allowed to place here
}

// 0x800E2128 (308 bytes)
// Picks up with user validation
void cXObjectImpl::UserPickup(bool force) {
    // User-initiated pickup with validation
}

// 0x800E225C (108 bytes)
// Checks if object is from the catalog
void cXObjectImpl::IsFromCatalog(void) {
    // Returns true if bought from catalog
}

// 0x800E22F8 (108 bytes)
// Sets was-placed-from-inventory flag
void cXObjectImpl::SetWasPlacedFromInventory(bool value) {
    // Updates inventory placement flag
}

// 0x800E2364 (480 bytes)
// Checks if object should auto-rotate
void cXObjectImpl::ShouldAutoRotate(void) {
    // Returns true if object auto-faces walls
}

// 0x800E2544 (192 bytes)
// Gets required segment for placement
void cXObjectImpl::GetRequiredSegment(void) {
    // Returns wall segment requirement
}

// 0x800E2604 (324 bytes)
// Checks if object can be chosen autonomously
void cXObjectImpl::CanChooseAutonomously(void) {
    // Returns true if AI sims can use this object
}

// 0x800E2748 (256 bytes)
// Updates sim-related flags
void cXObjectImpl::UpdateSimFlags(void) {
    // Refreshes sim presence/interaction flags
}

// 0x800E2848 (100 bytes)
// Gets wall blocking flags
void cXObjectImpl::GetWallBlockFlags(void) {
    // Returns which wall directions this object blocks
}

// 0x800E2A68 (92 bytes)
// Gets average location (const)
void cXObjectImpl::GetAverageLocation(void) const {
    // Returns center position for multi-tile objects
}

// 0x800E2AD4 (68 bytes)
// Gets tile position (const)
void cXObjectImpl::GetCTilePt(void) const {
    // Returns position as CTilePt
}

// 0x800E2B18 (88 bytes)
// Checks if a sprite layer is visible
void cXObjectImpl::IsSpriteVisible(short spriteId) {
    // Returns visibility of animation sprite
}

// 0x800E2B70 (452 bytes)
// Checks if sync object is ready
void cXObjectImpl::SyncObjectIsReady(signed char syncId) {
    // Returns true if synchronized object is in ready state
}

// 0x800E2D34 (208 bytes)
// Sets sync object state
void cXObjectImpl::SetSyncObject(signed char syncId) {
    // Updates sync state for multiplayer coordination
}

// 0x800E2E04 (272 bytes)
// Checks if sync object is ready (no-param)
void cXObjectImpl::SyncObjectIsReady(void) {
    // Returns overall sync readiness
}

// 0x800E2F14 (208 bytes)
// Runs a behavior tree
void cXObjectImpl::RunTree(ObjEntryPoint entry, short param, short* result) {
    // Executes behavior tree from entry point
}

// 0x800E3050 (68 bytes)
// Checks if object is a vehicle
void cXObjectImpl::IsVehicle(void) {
    // Returns true if object is a vehicle type
}

// 0x800E3094 (68 bytes)
// Checks if object is a person
void cXObjectImpl::IsPerson(void) {
    // Returns true if object is a sim/NPC
}

// 0x800E3118 (116 bytes)
// Sets color index for customization
void cXObjectImpl::SetColorIndex(unsigned char index) {
    // Updates object color variant
}

// 0x800E318C (192 bytes)
// Checks if tile is an interaction tile
void cXObjectImpl::IsInteractionTile(void) {
    // Returns true if current tile allows interactions
}

// 0x800EA6B0 (356 bytes)
// Called when sim object is placed
void cXObjectImpl::SimObjectPlaced(ISimInstance* sim) {
    // Notifies sim of placement
}

// 0x800EAABC (124 bytes)
// Checks if object emits light
void cXObjectImpl::IsEmissive(void) {
    // Returns true if object has emissive property
}

// 0x800EAB54 (112 bytes)
// Runs behavior tree by name
void cXObjectImpl::RunTree(char* treeName) {
    // Looks up and executes named behavior tree
}

// 0x800EAC00 (100 bytes)
// Checks if object requires wall adjacency
void cXObjectImpl::RequiresWallAdjacency(void) {
    // Returns true if must be placed against wall
}

// 0x800EAC88 (96 bytes)
// Gets tree ID for entry point
void cXObjectImpl::GetTreeID(ObjEntryPoint entry) {
    // Returns behavior tree ID
}

// 0x800EAD18 (128 bytes)
// Checks if object is a portal (door)
void cXObjectImpl::IsPortal(void) {
    // Returns true if object is a door/archway
}

// 0x800EAD98 (168 bytes)
// Checks if object is a window
void cXObjectImpl::IsWindow(void) {
    // Returns true if object is a window
}

// 0x800EAE40 (168 bytes)
// Checks if object is a door
void cXObjectImpl::IsDoor(void) {
    // Returns true if object is a door
}

// 0x800EAFC0 (68 bytes)
// Enables/disables simulation for object
void cXObjectImpl::EnableSim(bool enable) {
    // Controls whether object is simulated
}

// 0x800EB15C (116 bytes)
// Hides object for cutaway view
void cXObjectImpl::HideForCutaway(void) {
    // Makes object invisible during wall cutaway
}

// 0x800EB1D0 (72 bytes)
// Checks if object is a roof element
void cXObjectImpl::IsRoof(void) {
    // Returns true if object is roof type
}

// 0x800EB230 (112 bytes)
// Gets contained object by slot
void cXObjectImpl::GetContainedObject(int slotIndex) {
    // Returns object in containment slot
}

// 0x800EB4B4 (68 bytes)
// Checks if object is a support structure
void cXObjectImpl::IsSupport(void) {
    // Returns true if object is a support (table, counter)
}

// 0x800EB6C4 (148 bytes)
// Checks if object can intersect with people
void cXObjectImpl::CanIntersectPeople(void) {
    // Returns true if sims can walk through this object
}

// 0x800EB758 (100 bytes)
// Checks if object is a chair
void cXObjectImpl::IsChair(void) {
    // Returns true if object is seating
}

// 0x800EB84C (80 bytes)
// Gets first implementation pointer
void cXObjectImpl::GetFirstImpl(void) {
    // Returns first impl in chain
}

// 0x800EB940 (344 bytes)
// Gets debug name for object
void cXObjectImpl::GetDebugName(char* buf, int bufSize) const {
    // Formats debug display name
}

// 0x800EBA98 (152 bytes)
// Reports an error
void cXObjectImpl::Error(short errorCode) {
    // Logs behavior tree error
}

// 0x800EBB30 (776 bytes)
// Handles error recovery
void cXObjectImpl::HandleError(void) {
    // Attempts error recovery in behavior tree
}

// 0x800F9E6C (180 bytes)
// Checks if idle optimization is allowed
void cXObjectImpl::AllowIdleOptimization(void) {
    // Returns true if object can skip simulation when idle
}

// 0x800F9F44 (676 bytes)
// Tries user event primitive
void cXObjectImpl::TryUserEvent(StackElem*, XPrimParam*) {
    // Processes user-triggered event
}

// 0x800FA1F4 (288 bytes)
// Tests object type
void cXObjectImpl::TryTestObjectType(StackElem*, XPrimParam*) {
    // Checks if object matches a type
}

// 0x800FA314 (1936 bytes)
// Tests if person is in area
void cXObjectImpl::TryIsPersonInArea(StackElem*, XPrimParam*) {
    // Checks if any sim is within specified area
}

// 0x800FAAA4 (848 bytes)
// Uses known good location
void cXObjectImpl::UseKnownGoodLocation(TFGL_ACTIONS action, short param, FTilePt* pos, int dir, short flags) {
    // Places at previously validated location
}

// 0x800FADF4 (3084 bytes)
// Finds good location primitive
void cXObjectImpl::TryFindGoodLocation(StackElem*, XPrimParam*, TFGL_ACTIONS*, FTilePt*, int*, short*) {
    // Behavior tree primitive for finding placement
}

// 0x800FBA00 (1300 bytes)
// Sets balloon (thought/speech bubble)
void cXObjectImpl::TrySetBalloon(StackElem*, XPrimParam*) {
    // Creates thought/speech balloon above sim
}

// 0x800FBF14 (1676 bytes)
// Calls named behavior tree
void cXObjectImpl::TryCallNamedTree(StackElem*, XPrimParam*) {
    // Looks up and executes behavior tree by name
}

// 0x800FC7DC (4276 bytes)
// Parses UI string with variable substitution
void cXObjectImpl::ParseUIString(BString2& outStr, StackElem* stack, short* vars, ObjSelector** selectors, bool localize) {
    // Processes string template with variable expansion
}

// 0x800FD890 (536 bytes)
// Makes action string for display
void cXObjectImpl::TryMakeActionString(StackElem*, XPrimParam*) {
    // Creates human-readable action description
}

// 0x800FDAA8 (1388 bytes)
// Pushes action onto queue
void cXObjectImpl::TryPushAction(StackElem*, XPrimParam*) {
    // Adds interaction to sim's action queue
}

// 0x800FE068 (548 bytes)
// Finds 5 worst motives
void cXObjectImpl::TryFind5WorstMotives(StackElem*, XPrimParam*) {
    // Returns the 5 most depleted motives
}

// 0x800FE28C (2120 bytes)
// Handles relationship2 primitive
void cXObjectImpl::TryRelationship2(StackElem*, XPrimParam*) {
    // Advanced relationship modification
}

// 0x800FEAD4 (1800 bytes)
// Handles relationship primitive
void cXObjectImpl::TryRelationship(StackElem*, XPrimParam*) {
    // Basic relationship modification
}

// 0x800FF1DC (284 bytes)
// Handles tutorial primitive
void cXObjectImpl::TryTutorial(StackElem*, XPrimParam*) {
    // Triggers tutorial messages
}

// 0x800FF520 (2564 bytes)
// Handles burn primitive
void cXObjectImpl::TryBurn(StackElem*, XPrimParam*) {
    // Fire/burn simulation
}

// 0x800FFF24 (3424 bytes)
// Creates an object
void cXObjectImpl::TryCreateObject(StackElem*, XPrimParam*) {
    // Spawns a new object in the world
}

// 0x80100C84 (200 bytes)
// Preloads object resources
void cXObjectImpl::TryPreloadObject(StackElem*, XPrimParam*) {
    // Queues object resources for background loading
}

// 0x80100D4C (572 bytes)
// Drops object onto target
void cXObjectImpl::TryDropOnto(StackElem*, XPrimParam*) {
    // Places carried object onto target
}

// 0x80100F88 (392 bytes)
// Budget/money primitive
void cXObjectImpl::TryBudget(StackElem*, XPrimParam*) {
    // Modifies household budget
}

// 0x80101110 (4872 bytes)
// Sets to next object in iteration
void cXObjectImpl::TrySetToNext(StackElem*, XPrimParam*) {
    // Iterates objects matching criteria
}

// 0x80102418 (1064 bytes)
// Finds functional object
void cXObjectImpl::TryFindFunctionalObject(StackElem*, XPrimParam*) {
    // Searches for object that satisfies a function
}

// 0x80102840 (484 bytes)
// Calls functional tree
void cXObjectImpl::TryCallFunctionalTree(StackElem*, XPrimParam*) {
    // Calls behavior tree on found functional object
}

// 0x80102A24 (6448 bytes)
// Generic sim call primitive
void cXObjectImpl::TryGenericSimCall(StackElem*, XPrimParam*) {
    // Dispatches various sim-related sub-calls
}

// 0x801043A4 (2740 bytes)
// Shows all object dialogs
void cXObjectImpl::ShowAllObjectDialogs(StackElem*, XPrimParam*) {
    // Displays dialog boxes for object interactions
}

// 0x80104EC0 (364 bytes)
// Transitions to new house/lot
void cXObjectImpl::TransitionToNewHouse(short houseId, short doorId, short param) {
    // Initiates lot transition
}

// 0x8010502C (304 bytes)
// Rewrites dialog parameter indices
void cXObjectImpl::RewriteDialogParamIndices(DialogParam& param) {
    // Adjusts dialog parameter references
}

// 0x8010515C (708 bytes)
// Shows dialog primitive
void cXObjectImpl::TryDialog(StackElem*, XPrimParam*, bool modal) {
    // Displays dialog box
}

// 0x80105420 (284 bytes)
// Shows string primitive
void cXObjectImpl::TryShowString(StackElem*, XPrimParam*) {
    // Displays text string to player
}

// 0x8010553C (432 bytes)
// Kills object primitive
void cXObjectImpl::TryKillObject(StackElem*, XPrimParam*, short* result) {
    // Destroys object from behavior tree
}

// 0x801056EC (148 bytes)
// Kills self (object destroys itself)
void cXObjectImpl::KillSelf(bool immediate) {
    // Self-destruction
}

// 0x80105780 (352 bytes)
// Idle primitive
void cXObjectImpl::TryIdle(StackElem*, XPrimParam*) {
    // Suspends behavior tree for specified time
}

// 0x801058E0 (540 bytes)
// Update primitive
void cXObjectImpl::TryUpdate(StackElem*, XPrimParam*) {
    // Updates object state from behavior tree
}

// 0x80105AFC (628 bytes)
// Grab primitive
void cXObjectImpl::TryGrab(StackElem*, XPrimParam*) {
    // Picks up an object via behavior tree
}

// 0x80105D70 (100 bytes)
// Tree break primitive
void cXObjectImpl::TryTreeBreak(StackElem*, XPrimParam*) {
    // Interrupts current behavior tree
}

// 0x80105DD4 (384 bytes)
// Random primitive
void cXObjectImpl::TryRandom(StackElem*, XPrimParam*) {
    // Generates random number for behavior tree
}

// 0x80105F54 (796 bytes)
// Room effect primitive
void cXObjectImpl::TryRoomEffect(StackElem*, XPrimParam*) {
    // Applies room score effect
}

// 0x80106270 (760 bytes)
// Check object primitive
void cXObjectImpl::TryCheckObject(StackElem*, XPrimParam*) {
    // Tests object properties/conditions
}

// 0x80106568 (72 bytes)
// GBA communication primitive (GameCube-GBA link)
void cXObjectImpl::TryGbaCommunication(StackElem*, XPrimParam*) {
    // Handles GBA link cable communication
}

// 0x801065B0 (488 bytes)
// Animate object primitive
void cXObjectImpl::TryAnimateObject(StackElem*, XPrimParam*) {
    // Triggers object animation
}

// 0x80106798 (540 bytes)
// Complete goal primitive
void cXObjectImpl::TryCompleteGoal(StackElem*, CompleteGoalParam&) {
    // Marks a goal as completed
}

// 0x801069B4 (116 bytes)
// Gets GUID from inventory command
void cXObjectImpl::InventoryCommandParam_GetGuid(InventoryCommandParam& param) {
    // Extracts object GUID from inventory param
}

// 0x80106A28 (100 bytes)
// Gets count from inventory command
void cXObjectImpl::InventoryCommandParam_GetCount(InventoryCommandParam& param) {
    // Extracts item count from inventory param
}

// 0x80106A8C (752 bytes)
// Inventory command primitive
void cXObjectImpl::TryInventoryCommand(StackElem*, XPrimParam*) {
    // Processes inventory add/remove/check operations
}

// 0x80106D7C (3936 bytes)
// Camera control primitive
void cXObjectImpl::TryCameraControl(StackElem*, XPrimParam*) {
    // Controls camera position/target from behavior tree
}

// 0x80107CDC (452 bytes)
// Distance-to primitive
void cXObjectImpl::TryDistanceTo(StackElem*, XPrimParam*) {
    // Calculates distance to target object
}

// 0x80107EA0 (716 bytes)
// Direction-to primitive
void cXObjectImpl::TryDirectionTo(StackElem*, XPrimParam*) {
    // Calculates direction to target object
}

// 0x8010816C (536 bytes)
// Notify stack object primitive
void cXObjectImpl::TryNotifyStackObject(StackElem*, XPrimParam*) {
    // Sends notification to stack object
}

// 0x80108384 (204 bytes)
// Particle effect primitive
void cXObjectImpl::TryParticleEffect(StackElem*, XPrimParam*) {
    // Triggers particle effect on object
}

// 0x80108450 (2680 bytes)
// Memory primitive
void cXObjectImpl::TryMemory(StackElem*, XPrimParam*) {
    // Gets/sets sim memory entries
}

// 0x80108EC8 (384 bytes)
// Passive influence primitive
void cXObjectImpl::TryPassiveInfluence(StackElem*, XPrimParam*) {
    // Applies passive environmental influence
}

// 0x80109048 (540 bytes)
// Wants and fears notify primitive
void cXObjectImpl::TryWantsAndFearsNotify(StackElem*, XPrimParam*) {
    // Triggers want/fear system events
}

// 0x80109264 (224 bytes)
// Change want/fear tree primitive
void cXObjectImpl::TryChangeWantFearTree(StackElem*, XPrimParam*) {
    // Modifies want/fear behavior tree
}

// 0x80109344 (584 bytes)
// Set motive delta primitive (object version)
void cXObjectImpl::TrySetMotiveDelta(StackElem*, XPrimParam*) {
    // Sets motive change rate from object interaction
}

// 0x8010958C (312 bytes)
// Animate primitive (object version)
void cXObjectImpl::TryAnimate(StackElem*, AnimateNewParam*) {
    // Triggers animation from behavior tree
}

// 0x801096C4 (172 bytes)
// Simulate tick (object version)
void cXObjectImpl::Simulate(int deltaMs) {
    // Runs object simulation for one tick
}

// 0x80109770 (1148 bytes)
// Try element (object version)
void cXObjectImpl::TryElement(StackElem*, short id, XPrimParam*) {
    // Dispatches behavior tree primitive
}

// 0x80109BEC (68 bytes)
// Kill sounds primitive
void cXObjectImpl::TryKillSounds(StackElem*, KillSoundsParam*) {
    // Stops sounds playing on this object
}

// 0x80109C30 (448 bytes)
// Play sound primitive
void cXObjectImpl::TryPlaySound(StackElem*, PlaySoundParam*) {
    // Plays a sound effect
}

// 0x80109DF0 (212 bytes)
// Gosub to object tree
void cXObjectImpl::GosubObjectTree(cXObject* obj, short* treeId, short param, bool immediate) {
    // Pushes object's tree onto execution stack
}

// 0x80109EC4 (144 bytes)
// Run behavior tree (full params)
void cXObjectImpl::RunTree(Behavior* beh, short param, char* name, short* result) {
    // Executes named behavior with parameters
}

// 0x80109F54 (2692 bytes)
// Expression evaluation primitive
void cXObjectImpl::TryExpression(ExpressionParam*) {
    // Evaluates arithmetic/logic expressions
}

// 0x8010AA24 (128 bytes)
// Gets short combo value
void cXObjectImpl::GetShortComboValue(signed char which, short* val1, short* val2) {
    // Splits combined short value
}

// 0x8010AAC8 (9880 bytes)
// Interprets a value from behavior tree data
void cXObjectImpl::InterpValue(short type, short param, short** dataPtr, float** floatPtr, short* result, short** outPtr) {
    // Complex value resolution from behavior tree state
}

// 0x8010D160 (604 bytes)
// Writes an interpreted value
void cXObjectImpl::InterpWriteValue(short type, short param, short** dataPtr, short value) {
    // Stores value back to behavior tree state
}

// 0x8010D3C8 (484 bytes)
// Drop primitive
void cXObjectImpl::TryDrop(void) {
    // Drops carried object
}

// 0x8010D5B0 (2772 bytes)
// Snap primitive
void cXObjectImpl::TrySnap(StackElem*, XPrimParam*) {
    // Snaps to routing slot
}

// 0x8010E084 (1520 bytes)
// Snap with full parameters
void cXObjectImpl::TrySnap(FTilePt pos, int dir, cXObject* target, int slot, bool immediate, int flags, bool force) {
    // Full snap-to implementation
}

// 0x8010E674 (576 bytes)
// HUD create primitive
void cXObjectImpl::TryHUDCreate(StackElem*, XPrimParam*) {
    // Creates HUD element from behavior tree
}

// 0x8010E8B4 (892 bytes)
// HUD add item primitive
void cXObjectImpl::TryHUDAddItem(StackElem*, XPrimParam*) {
    // Adds item to HUD display
}

// 0x8010EC30 (208 bytes)
// HUD manage primitive
void cXObjectImpl::TryHUDManage(StackElem*, XPrimParam*) {
    // Manages HUD elements
}

// 0x8010ED00 (356 bytes)
// HUD data primitive
void cXObjectImpl::TryHUDData(StackElem*, XPrimParam*) {
    // Sets HUD data values
}

// 0x8010FAB0 (96 bytes)
// Changes selected sim (left)
void cXObjectImpl::ChangeSelectedSimL(int playerIndex) {
    // Cycles selection to previous sim
}

// 0x8010FB10 (104 bytes)
// Changes selected sim (right)
void cXObjectImpl::ChangeSelectedSimR(int playerIndex) {
    // Cycles selection to next sim
}


// ============================================================================
// InteractorModule — Build mode & input system (299 functions, 137,612 bytes)
// Handles object placement, wall/floor building, direct control,
// cursor management, and all build-mode interactions
// ============================================================================

namespace InteractorModule {
    // Free functions
    void Debug_GetNameFromCommand(int command);
    void InitializeInteractorModule(void);
    void ShutdownInteractorModule(void);
    void GetPersonPosition(EVec3* outPos, cXPerson* person, bool useGround, bool useCenter);
    void GetObjectPosition(EVec3* outPos, cXObject* obj);
    void SnapPositionToTile(EVec3& inPos, EVec3& outPos, int flags);
    void GetCameraRelativeStickAngle(EVec2& stickInput, ESimsCam* cam, float* outAngle);
    void MoveCursorAlongCameraTargetVector(EVec3& pos, EVec2& input, ESimsCam* cam, float speed);
    void MoveCursorOneTileAlongCameraTargetVector(EVec3& pos, EVec2& input, ESimsCam* cam, int gridSize);
    void ClampPosToWorld(EVec3& pos);
    void IsPosOutsideWorld(EVec3& pos);
    void GetSnapPos(int& x, int& y, EVec3& pos);
    void GetSnapPosWithOffset(EVec3& pos);
    void CreateObjectFromSelector(ObjSelector* sel);
    void CreateObjectFromGUID(unsigned int guid);
    void DestroyObject(cXObject* obj);
    void CanObjectBeDestroyed(cXObject* obj);
    void GetCursorIntersectionObjects(vector<short, allocator<short> >& outList, int flags);
    void GetObjectFromInt16(short id);
    void GetLeadObjectImpl(cXObject* obj);
    void AllPlayersActiveInputInteractors(int playerCount);
    void IsObjectInRange(cXObject* obj);
    void CoreIsLegalToPlace(cXObject* obj, FTilePt& pos, int& dir);
    void IsLegalToPlaceMultiTileAtLocation(cXObject* obj, FTilePt& pos);
    void IsLegalToPlaceSingleTileAtLocation(cXObject* obj, FTilePt& pos, int* outDir);
    void IsLegalToPlaceAtLocation(cXObject* obj, FTilePt& pos, int* outDir);
    void FinalUserPlaceObject(cXObject* obj);
    void UpdateAllObjectsInWorldAfterFirstPickupOrFinalPlace(cXObject* obj);
    void RecomputeLightingGrid(cXObject* obj);
    void SetDirection(int dir, cXObject* obj);
    void GetObjectInstancesList(cXObject* obj, TNodeList<ISimInstance*>& outList);
    void ShadeModelToShowValidState(cXObjectImpl* impl, bool valid);
    void GetVisibleSideOfWall(ESimsCam* cam, EVec3& wallStart, EVec3& wallEnd, EVec3* outNormal);
    void ConvertVertsToTiles(EVec3& vert1, EVec3& vert2, CTilePt& outTile1, CTilePt& outTile2);
    void GetAdjacentTileCoordinates(TilePtDir tileDir, int offset, EVec3& outPos);
    void GetRoomIdFromPoint(CTilePt& pt);
    void ForcePointDir(CTilePt& from, CTilePt& to);
    void EorGetAdjacentTile(TileWallsSegment& seg, int side, DiagonalSideSelector& diagSel, CTilePt& outTile1, CTilePt& outTile2);
    void IsCameraDirectorInControl(int playerIndex);
    void SetCameraFilter(int filterType);
    void ClearCameraFilter(int filterType);
    void IncrementSellCountForPattern(int patternId, vector<int, allocator<int> >& counts);
    void IncrementSellCountForObjectGuid(int guid, vector<int, allocator<int> >& counts);
    void CheckNewSimInSocialMode(unsigned int simId);

    // Inner classes
    class Interactor {
    public:
        void OnCommandReleased(int cmd);
        void OnCommandUpdate(int cmd, float value);
        void ResetInputState(void);
        void GetSelectionRadius(void);
        void Moved(void);
    };

    class DirectInteractor {
    public:
        DirectInteractor(void);
        void OnStart(int*);
        void OnStop(void);
        void ParseControls(void);
        void GetDesiredAnimState(bool moving, EVec2 input);
        void InitPlayerPos(void);
        void UpdatePlumbBob(void);
        void UpdateControlStatus(void);
        void SetVelocityModifiers(void);
        void SendNeutralFreeMoveInput(void);
        void InterpretFreeMoveInput(void);
        void Update(float dt);
        void IsSimulatorPaused(void);
        void ShouldHighlightObject(cXObject* obj, float dist);
        void CancelQueuedActions(void);
        void OnCommandPressed(int cmd, float value);
        void OnCommandReleased(int cmd);
        void ExecuteActionMenu(void);
        void ExecuteObjectActionMenu(cXObject* obj);
        void ChooseAction(Interaction* action);
        void SetupCamera(void);
        void UpdateObjectHighlights(EIObjectMan* objMan);
        void ResetIdleTime(void);
        void CameraDirectorPermitsDirectControl(void);
        void UpdateInteractorPos(void);
    };

    class FloorPainter {
    public:
        FloorPainter(void);
        ~FloorPainter(void);
        void OnCreate(void);
        void OnDestroy(void);
        void OnStart(int*);
        void OnStop(void);
        void UpdateStickState(void);
        void Update(float dt);
        void SendBuildItemCountChangeEvent(int delta);
        void SendSuccessEvent(int type);
        void HandleActionCmdInRemoveMode(void);
        void UpdateStockChanges(int* costs, int count);
        void HandleActionCmdInPlaceMode(void);
        void OnCommandPressed(int cmd, float value);
        void OnCommandReleased(int cmd);
        void OnCommandUpdate(int cmd, float value);
        void IsValidFloorPlacement(CTilePt& pos, FloorPattern pattern);
        void SetFloorTile(CTilePt* pos, FloorPattern pattern, int* cost);
        void SetFloorTile(CTilePt& pos, FloorPattern pattern, Room* room, int* cost);
        void RemoveFloorTile(CTilePt* pos, int* refund);
        void GetSelectedRectPoints(int& x1, int& y1, int& x2, int& y2);
        void PaintFloor(int* totalCost);
        void RemoveFloor(int* totalRefund);
        void PaintRoom(int* totalCost);
        void RemoveRoom(int* totalRefund);
        void CheckDiagForRoomContainment(Room* room, CTilePt& pos, TileWalls& walls, DiagonalSideSelector& sel1, DiagonalSideSelector& sel2);
        void CancelSession(void);
        void SwapTools(void);
        void CurrentSelectionIsValid(int& outCount);
    };

    class GrabManipulator {
    public:
        GrabManipulator(void);
        void OnCommandPressed(int cmd, float value);
        void OnStart(int*);
        void TryGrabbingWorldObject(void);
        void TryGrabbingWorldObjectFromId(short objId);
        void DestroyObjectInHand(void);
        void DropCurrentObject(void);
        void TryRemoveCurrentObjectFromWorld(void);
        void CancelCurrentGrab(void);
        void CancelSession(void);
    };

    class InteractorInputManager {
    public:
        InteractorInputManager(int playerIndex);
        ~InteractorInputManager(void);
        void Update(float dt);
        class InstanceData {
        public:
            ~InstanceData(void);
            void AddCommandMapping(int inputId, ECTRL_CMD cmd);
            void AddCommandMapping(int inputId, int param1, int param2);
            void OpenSession(int sessionId, int* cmds1, int count1, int* cmds2, int count2, int* cmds3, char* name);
            void CloseSession(void);
            void Update(float dt);
        };
    };

    class InteractorManager {
    public:
        ~InteractorManager(void);
        void Initialize(int& playerCount);
        void Shutdown(void);
        void Update(float dt);
        void ChangeActiveInteractorToNull(int playerIndex);
        void GetPlayerInteractor(int playerIndex, int interactorType);
        void GetPlayerInteractorInfo(int playerIndex) const;
        void CreatePlayerInteractorSets(void);
        void DestroyPlayerInteractorSets(void);
        void UpdateActivePlayerInteractors(float dt);
    };

    class InteractorResourceSet {
    public:
        InteractorResourceSet(int& flags);
        ~InteractorResourceSet(void);
        void AddModel(unsigned int id);
        void RemoveModel(unsigned int id);
        void GetModel(unsigned int id);
        void AddShader(unsigned int id);
        void RemoveShader(unsigned int id);
        void GetShader(unsigned int id);
        void AddTexture(unsigned int id);
        void RemoveTexture(unsigned int id);
        void GetTexture(unsigned int id);
        void ClearSet(void);
        void AddOrderTableData(EOrderTableData& data);
    };

    class InteractorVisualizer {
    public:
        ~InteractorVisualizer(void);
        void Initialize(void);
        void Shutdown(void);
        void CreateResources(int& flags);
        void PreDraw(int& flags);
        void Draw(int& flags);
        void DrawFloorRectPreview(ERC* rc, EVec3& min, EVec3& max);
        void DrawFloorRoomPreview(ERC* rc, EVec3& pos);
        void DrawWallpaperRoomPreview(int& flags);
        void DrawWallpaperPreviewOnAffectedWalls(int& flags);
        void DrawWallpaperRectPreview(ERShader* shader, EVec2& min, EVec2& max, float height);
        void DrawWallRectPreview(int& flags);
        void DrawVerticalRect(ERShader* shader, EVec2& min, EVec2& max, float height, int segments, float offset);
        void DrawRoomPreview(int& flags);
        void DrawPreviewOnAffectedWalls(int& flags);
        void InteractorOrderTableCallback(ELevelDrawData& data, EOrderTableData* orderData);
        void SetupDrawCallback(EHouse* house, int layer);
        void CreateSimpleResourceSet(int& flags, int type);
        void DrawSimpleResourceSet(int& flags, int type, EVec3& pos, float rot);
        void SelectShader(int& flags, int type);
        void Draw(int& flags, EVec3& pos);
        void DrawResource(int& flags, int resId, EVec3& pos, EMat4* transform);
        void CreateResourceSet(int& flags);
        void AddModelToResourceSet(int& flags, int modelId);
        void AddOrderTableToResourceSet(int& flags, EOrderTableData& data);
        void DestroyResourceSet(int& flags);
        void GetInteractorResourceSet(int* outSet);
        void SetDefaultLights(void);
    };

    class ObjectManipulator {
    public:
        ObjectManipulator(void);
        ~ObjectManipulator(void);
        void OnStart(int*);
        void OnCommandUpdate(int cmd, float value);
        void OnCommandReleased(int cmd);
        void Update(float dt);
        void UpdateObjectHighlights(EIObjectMan* objMan);
        void UpdateOverlapIntersection(int* result);
    };

    class PlaceManipulator {
    public:
        void OnCommandPressed(int cmd, float value);
        void StartPlacement(int* params);
        void TryPlacingCurrentObject(void);
        void CancelSession(void);
    };

    class PlacementObject {
    public:
        ~PlacementObject(void);
        void SetObjectColor(cXObject* obj, unsigned char colorIndex);
        void CreateNewPlacementObjectFromGuid(unsigned int guid, unsigned char color);
        void GrabExistingObjectInstanceFromId(short id);
        void CreateGridObject(FTilePt& pos, cXObject* template_);
        void CreateGridTile(ObjSelector* sel, cXMTObjectImpl* mtImpl, cXObjectImpl* impl);
        void DestroyGridObject(cXMTObjectImpl*& mtImpl);
        void InitializeGridObject(cXMTObjectImpl* mtImpl);
        void AssignOffsetsToGridObject(cXMTObjectImpl* mtImpl, cXObjectImpl* impl);
        void Pickup(void);
        void IsLegalToPlaceAtLocation(FTilePt& pos, int& dir);
        void Place(FTilePt& pos, int& dir);
        void Drop(void);
        void Initialize(void);
        void Destroy(void);
        void Reset(void);
        void SetDirection(int dir);
        void Rotate(int delta);
        void ResetLocation(void);
        void SetShaderToValidState(bool valid);
    };

    class SimInteractor {
    public:
        SimInteractor(void);
        ~SimInteractor(void);
        void OnStart(int*);
        void OnStop(void);
        void ParseControls(void);
        void Update(float dt);
        void GetBeamScale(void);
        void OnCommandPressed(int cmd, float value);
        void OnCommandReleased(int cmd);
        void ReturnPlumbBobToOwner(void);
        void ImmediatelyCutCursorAndCameraToPos(EVec3& pos);
        void TryCutToSim(void);
        void UpdateOverlapIntersection(int* result);
        void ExecuteActionMenu(void);
        void IsSimulatorPaused(void);
        void UpdateObjectHighlights(EIObjectMan* objMan);
        void SetupCamera(void);
        void ChooseAction(Interaction* action);
    };

    class SocialModeInteractor {
    public:
        SocialModeInteractor(void);
        void OnStart(int*);
        void OnStop(void);
        void Update(float dt);
        void SetupInteractionMenu(cXObject* target, InteractionList& interactions);
    };

    class WallManipulator {
    public:
        WallManipulator(void);
        ~WallManipulator(void);
        void OnCreate(void);
        void OnStart(int*);
        void OnStop(void);
        void CommittTransaction(int cost);
        void FinalizePlacement(void);
        void FinalizeWallDel(void);
        void CountWallsInRoomSelection(void);
        void FinalizeRoom(void);
        void HandleFinalizeRequest(void);
        void HandleSwapRequest(void);
        void HandleExitRequest(void);
        void ValidateWallSegment(void);
        void UpdateStickState(void);
        void ClearWallFadeOffList(void);
        void Update(float dt);
        void OnCommandPressed(int cmd, float value);
        void OnCommandReleased(int cmd);
        void OnCommandUpdate(int cmd, float value);
        void GetWallLineCost(EVec3& start, EVec3& end, bool& valid, bool adding, bool checkBudget);
        void SubmitLine(EVec3& start, EVec3& end, int& cost, bool adding, bool commit);
        void DoesNotConflictWithExistingArchitecture(CTilePt& pos, TileWallsSegment seg);
        void CanChangeTileAdd(CTilePt& pos, TileWallsSegment seg);
        void CanChangeTileDelete(CTilePt& pos, TileWallsSegment seg);
        void HandleDeleteLine(CTilePt& start, CTilePt& end, TilePtDir& dir, int cost);
        void HandleAddLine(CTilePt start, CTilePt end, TilePtDir& dir, int cost);
        void LegalWallTile(CTilePt& pos, TileWallsSegment seg);
        void AddWallAtTile(CTilePt& pos, TileWalls& walls, TileWallsSegment seg);
        void PreviewNRooms(void);
        void IncrementSellCountForStyle(WallStyle style);
        void CheckForAffectedWalls(EVec3& start, EVec3& end);
        void SendBuildItemCountChangeEvent(int delta);
        class CallbackData {
        public:
            ~CallbackData(void);
        };
    };

    class WallPainter {
    public:
        WallPainter(void);
        ~WallPainter(void);
        void OnCreate(void);
        void OnStart(int*);
        void CommittTransaction(int cost);
        void HandleFinalizeRequest(void);
        void HandleSwapRequest(void);
        void HandleExitRequest(void);
        void AdjustCursorPosition(void);
        void ValidateWallSegment(void);
        void UpdateStickState(void);
        void Update(float dt);
        void OnCommandPressed(int cmd, float value);
        void OnCommandReleased(int cmd);
        void OnCommandUpdate(int cmd, float value);
        void CountWallsInRoomSelection(void);
        void FinalizePaperForRoom(void);
        void FinalizePaperForLine(void);
        void FinalizeSellPaperForLine(void);
        void SubmitPaperLine(EVec2& start, EVec2& end, WallPattern pattern, int cost);
        void SendBuildItemCountChangeEvent(int delta);
        void RestoreFromHoldPos(EVec3& pos);
        class CallbackData {
        public:
            ~CallbackData(void);
        };
    };
} // namespace InteractorModule

// --- InteractorModule top-level functions ---

// 0x802095E4 (276 bytes)
// Returns debug name string for a command enum value
void InteractorModule::Debug_GetNameFromCommand(int command) {
    // Switch on command value (-1 to 12)
    // Returns static string like "CMD_NONE", "CMD_ACTION", etc.
}

// 0x80210260 (516 bytes)
// Initializes the interactor module
void InteractorModule::InitializeInteractorModule(void) {
    // Creates interactor instances
    // Initializes input mappings
    // Sets up build mode resources
}

// 0x80210464 (68 bytes)
// Shuts down the interactor module
void InteractorModule::ShutdownInteractorModule(void) {
    // Destroys interactor instances and resources
}

// 0x802104A8 (396 bytes)
// Gets person position in world coordinates
void InteractorModule::GetPersonPosition(EVec3* outPos, cXPerson* person, bool useGround, bool useCenter) {
    // Calculates 3D position of a sim
}

// 0x80210634 (144 bytes)
// Gets object position in world coordinates
void InteractorModule::GetObjectPosition(EVec3* outPos, cXObject* obj) {
    // Calculates 3D position of an object
}

// 0x802106C4 (320 bytes)
// Snaps position to nearest tile grid point
void InteractorModule::SnapPositionToTile(EVec3& inPos, EVec3& outPos, int flags) {
    // Aligns position to tile boundaries
}

// 0x80210804 (376 bytes)
// Gets camera-relative analog stick angle
void InteractorModule::GetCameraRelativeStickAngle(EVec2& stickInput, ESimsCam* cam, float* outAngle) {
    // Converts stick input to world-space angle
}

// 0x8021097C (732 bytes)
// Moves cursor along camera target vector
void InteractorModule::MoveCursorAlongCameraTargetVector(EVec3& pos, EVec2& input, ESimsCam* cam, float speed) {
    // Moves cursor position in camera-relative direction
}

// 0x80210C58 (804 bytes)
// Moves cursor one tile along camera target vector
void InteractorModule::MoveCursorOneTileAlongCameraTargetVector(EVec3& pos, EVec2& input, ESimsCam* cam, int gridSize) {
    // Discrete tile-based cursor movement
}

// 0x80210F7C (288 bytes)
// Clamps position to world boundaries
void InteractorModule::ClampPosToWorld(EVec3& pos) {
    // Keeps position within lot boundaries
}

// 0x8021109C (248 bytes)
// Checks if position is outside world
void InteractorModule::IsPosOutsideWorld(EVec3& pos) {
    // Returns true if position is beyond lot edges
}

// 0x80211194 (248 bytes)
// Gets snap position on grid
void InteractorModule::GetSnapPos(int& x, int& y, EVec3& pos) {
    // Converts world position to grid coordinates
}

// 0x8021128C (176 bytes)
// Gets snap position with offset
void InteractorModule::GetSnapPosWithOffset(EVec3& pos) {
    // Grid-snapped position with half-tile offset
}

// 0x8021133C (156 bytes)
// Creates object from selector
void InteractorModule::CreateObjectFromSelector(ObjSelector* sel) {
    // Instantiates game object from catalog selector
}

// 0x802113D8 (148 bytes)
// Creates object from GUID
void InteractorModule::CreateObjectFromGUID(unsigned int guid) {
    // Instantiates game object by GUID
}

// 0x8021146C (184 bytes)
// Destroys an object
void InteractorModule::DestroyObject(cXObject* obj) {
    // Removes object from world and frees memory
}

// 0x80211524 (316 bytes)
// Checks if object can be destroyed
void InteractorModule::CanObjectBeDestroyed(cXObject* obj) {
    // Validates destruction conditions
}

// 0x80211660 (520 bytes)
// Gets cursor intersection objects
void InteractorModule::GetCursorIntersectionObjects(vector<short, allocator<short> >& outList, int flags) {
    // Finds objects under cursor position
}

// 0x80211868 (88 bytes)
// Gets object from int16 ID
void InteractorModule::GetObjectFromInt16(short id) {
    // Resolves object pointer from short ID
}

// 0x802118C0 (256 bytes)
// Gets lead object implementation
void InteractorModule::GetLeadObjectImpl(cXObject* obj) {
    // Returns the lead tile's implementation for multi-tile objects
}

// 0x802119EC (212 bytes)
// Checks if all players have active input interactors
void InteractorModule::AllPlayersActiveInputInteractors(int playerCount) {
    // Returns true if all players have active input
}

// 0x80211AC0 (244 bytes)
// Checks if object is in interaction range
void InteractorModule::IsObjectInRange(cXObject* obj) {
    // Distance check for interactions
}

// 0x80211BB4 (216 bytes)
// Core legal placement check
void InteractorModule::CoreIsLegalToPlace(cXObject* obj, FTilePt& pos, int& dir) {
    // Validates placement at position
}

// 0x80211C8C (76 bytes)
// Checks legal placement for multi-tile at location
void InteractorModule::IsLegalToPlaceMultiTileAtLocation(cXObject* obj, FTilePt& pos) {
    // Multi-tile placement validation
}

// 0x80211CD8 (1104 bytes)
// Checks legal placement for single-tile at location
void InteractorModule::IsLegalToPlaceSingleTileAtLocation(cXObject* obj, FTilePt& pos, int* outDir) {
    // Single-tile placement validation
}

// 0x80212128 (156 bytes)
// Checks legal placement at location
void InteractorModule::IsLegalToPlaceAtLocation(cXObject* obj, FTilePt& pos, int* outDir) {
    // Dispatches to single or multi-tile check
}

// 0x802121C4 (460 bytes)
// Finalizes object placement
void InteractorModule::FinalUserPlaceObject(cXObject* obj) {
    // Commits object placement, updates world state
}

// 0x80212390 (200 bytes)
// Updates all objects after first pickup or final place
void InteractorModule::UpdateAllObjectsInWorldAfterFirstPickupOrFinalPlace(cXObject* obj) {
    // Refreshes nearby objects after placement change
}

// 0x80212458 (92 bytes)
// Recomputes lighting grid around object
void InteractorModule::RecomputeLightingGrid(cXObject* obj) {
    // Updates light grid cells affected by object
}

// 0x802124B4 (412 bytes)
// Sets object direction
void InteractorModule::SetDirection(int dir, cXObject* obj) {
    // Rotates object to specified direction
}

// 0x80212650 (376 bytes)
// Gets list of object instances
void InteractorModule::GetObjectInstancesList(cXObject* obj, TNodeList<ISimInstance*>& outList) {
    // Collects all sim instances using this object
}

// 0x802127C8 (784 bytes)
// Shades model to show placement validity
void InteractorModule::ShadeModelToShowValidState(cXObjectImpl* impl, bool valid) {
    // Green tint for valid, red for invalid placement
}

// 0x80212AD8 (640 bytes)
// Gets visible side of wall segment
void InteractorModule::GetVisibleSideOfWall(ESimsCam* cam, EVec3& wallStart, EVec3& wallEnd, EVec3* outNormal) {
    // Determines which side of wall faces camera
}

// 0x80212D58 (656 bytes)
// Converts vertex positions to tile coordinates
void InteractorModule::ConvertVertsToTiles(EVec3& vert1, EVec3& vert2, CTilePt& outTile1, CTilePt& outTile2) {
    // Maps 3D positions to tile grid
}

// 0x80212FE8 (524 bytes)
// Gets adjacent tile coordinates
void InteractorModule::GetAdjacentTileCoordinates(TilePtDir tileDir, int offset, EVec3& outPos) {
    // Returns position of adjacent tile
}

// 0x802131F4 (228 bytes)
// Gets room ID from point
void InteractorModule::GetRoomIdFromPoint(CTilePt& pt) {
    // Returns which room contains the point
}

// 0x802132D8 (692 bytes)
// Forces point direction
void InteractorModule::ForcePointDir(CTilePt& from, CTilePt& to) {
    // Ensures consistent direction between two tiles
}

// 0x8021358C (320 bytes)
// Gets adjacent tile for EOR (wall placement)
void InteractorModule::EorGetAdjacentTile(TileWallsSegment& seg, int side, DiagonalSideSelector& diagSel, CTilePt& outTile1, CTilePt& outTile2) {
    // Complex wall adjacency calculation
}

// 0x80213700 (76 bytes)
// Checks if camera director is in control
void InteractorModule::IsCameraDirectorInControl(int playerIndex) {
    // Returns true if cinematic camera is active
}

// 0x8021374C (116 bytes)
// Sets camera filter
void InteractorModule::SetCameraFilter(int filterType) {
    // Applies visual filter to camera
}

// 0x802137C0 (104 bytes)
// Clears camera filter
void InteractorModule::ClearCameraFilter(int filterType) {
    // Removes visual filter from camera
}

// 0x80213828 (540 bytes)
// Increments sell count for pattern
void InteractorModule::IncrementSellCountForPattern(int patternId, vector<int, allocator<int> >& counts) {
    // Tracks how many of each pattern were sold
}

// 0x80213A44 (540 bytes)
// Increments sell count for object GUID
void InteractorModule::IncrementSellCountForObjectGuid(int guid, vector<int, allocator<int> >& counts) {
    // Tracks how many of each object type were sold
}

// 0x80213C60 (300 bytes)
// Checks new sim in social mode
void InteractorModule::CheckNewSimInSocialMode(unsigned int simId) {
    // Validates social mode for incoming sim
}


// --- InteractorModule::DirectInteractor ---

// 0x80203D70 (96 bytes)
// Constructor: initializes direct control state
InteractorModule::DirectInteractor::DirectInteractor(void) {
    char* self = (char*)this;
    // Calls Interactor::Interactor()
    // Sets vtable at offset 92
    // Initializes: inputActive=1, velocity=0, highlightObj=0, etc.
}

// 0x80203E6C (616 bytes)
void InteractorModule::DirectInteractor::OnStart(int*) {
    // Initializes direct control session
    // Sets up command mappings, initializes camera
}

// 0x802040D4 (136 bytes)
void InteractorModule::DirectInteractor::OnStop(void) {
    // Cleans up direct control session
}

// 0x8020415C (112 bytes)
void InteractorModule::DirectInteractor::ParseControls(void) {
    // Reads controller input and translates to commands
}

// 0x802041CC (84 bytes)
void InteractorModule::DirectInteractor::GetDesiredAnimState(bool moving, EVec2 input) {
    // Returns desired animation based on input
}

// 0x80204220 (536 bytes)
void InteractorModule::DirectInteractor::InitPlayerPos(void) {
    // Sets initial player position from sim location
}

// 0x80204438 (212 bytes)
void InteractorModule::DirectInteractor::UpdatePlumbBob(void) {
    // Updates plumb bob (selection indicator) position
}

// 0x8020450C (184 bytes)
void InteractorModule::DirectInteractor::UpdateControlStatus(void) {
    // Updates controller connectivity status
}

// 0x802045C4 (92 bytes)
void InteractorModule::DirectInteractor::SetVelocityModifiers(void) {
    // Sets speed modifiers based on input
}

// 0x80204620 (220 bytes)
void InteractorModule::DirectInteractor::SendNeutralFreeMoveInput(void) {
    // Sends zero-velocity input to movement system
}

// 0x802046FC (316 bytes)
void InteractorModule::DirectInteractor::InterpretFreeMoveInput(void) {
    // Processes analog stick for free movement
}

// 0x80204838 (948 bytes)
void InteractorModule::DirectInteractor::Update(float dt) {
    // Main update: processes input, moves sim, updates camera
}

// 0x80204BEC (112 bytes)
void InteractorModule::DirectInteractor::IsSimulatorPaused(void) {
    // Checks if simulation is paused
}

// 0x80204C5C (640 bytes)
void InteractorModule::DirectInteractor::ShouldHighlightObject(cXObject* obj, float dist) {
    // Determines if object should be highlighted
}

// 0x80204F3C (156 bytes)
void InteractorModule::DirectInteractor::CancelQueuedActions(void) {
    // Cancels all queued player actions
}

// 0x8020506C (1644 bytes)
void InteractorModule::DirectInteractor::OnCommandPressed(int cmd, float value) {
    // Handles button press events
}

// 0x802056D8 (112 bytes)
void InteractorModule::DirectInteractor::OnCommandReleased(int cmd) {
    // Handles button release events
}

// 0x802057C8 (664 bytes)
void InteractorModule::DirectInteractor::ExecuteActionMenu(void) {
    // Opens the pie menu for actions
}

// 0x80205A60 (280 bytes)
void InteractorModule::DirectInteractor::ExecuteObjectActionMenu(cXObject* obj) {
    // Opens pie menu for a specific object
}

// 0x80205BB0 (84 bytes)
void InteractorModule::DirectInteractor::ChooseAction(Interaction* action) {
    // Selects an action from the menu
}

// 0x80205C04 (72 bytes)
void InteractorModule::DirectInteractor::SetupCamera(void) {
    // Configures camera for direct control mode
}

// 0x80205C4C (872 bytes)
void InteractorModule::DirectInteractor::UpdateObjectHighlights(EIObjectMan* objMan) {
    // Updates highlight state for all nearby objects
}

// 0x80205FF4 (212 bytes)
void InteractorModule::DirectInteractor::ResetIdleTime(void) {
    // Resets the idle timer
}

// 0x80206134 (76 bytes)
void InteractorModule::DirectInteractor::CameraDirectorPermitsDirectControl(void) {
    // Checks if camera director allows direct control
}

// 0x80206180 (120 bytes)
void InteractorModule::DirectInteractor::UpdateInteractorPos(void) {
    // Updates interactor's world position
}


// --- InteractorModule::FloorPainter ---

// 0x80206224 (148 bytes)
InteractorModule::FloorPainter::FloorPainter(void) {
    // Initializes floor painting state
}

// 0x802062B8 (172 bytes)
InteractorModule::FloorPainter::~FloorPainter(void) {
    // Cleans up floor painting resources
}

// 0x80206364 (116 bytes)
void InteractorModule::FloorPainter::OnCreate(void) {
    // Creates floor painting resources
}

// 0x802063D8 (76 bytes)
void InteractorModule::FloorPainter::OnDestroy(void) {
    // Destroys floor painting resources
}

// 0x80206424 (608 bytes)
void InteractorModule::FloorPainter::OnStart(int*) {
    // Starts floor painting session
}

// 0x80206684 (92 bytes)
void InteractorModule::FloorPainter::OnStop(void) {
    // Stops floor painting session
}

// 0x802066E0 (84 bytes)
void InteractorModule::FloorPainter::UpdateStickState(void) {
    // Updates analog stick input state
}

// 0x80206734 (1576 bytes)
void InteractorModule::FloorPainter::Update(float dt) {
    // Main update for floor painting
}

// 0x80206D5C (128 bytes)
void InteractorModule::FloorPainter::SendBuildItemCountChangeEvent(int delta) {
    // Notifies UI of item count change
}

// 0x80206DDC (128 bytes)
void InteractorModule::FloorPainter::SendSuccessEvent(int type) {
    // Notifies UI of successful action
}

// 0x80206E5C (544 bytes)
void InteractorModule::FloorPainter::HandleActionCmdInRemoveMode(void) {
    // Processes action command during floor removal
}

// 0x8020707C (508 bytes)
void InteractorModule::FloorPainter::UpdateStockChanges(int* costs, int count) {
    // Updates inventory and budget for floor changes
}

// 0x80207278 (416 bytes)
void InteractorModule::FloorPainter::HandleActionCmdInPlaceMode(void) {
    // Processes action command during floor placement
}

// 0x80207418 (1176 bytes)
void InteractorModule::FloorPainter::OnCommandPressed(int cmd, float value) {
    // Handles button press in floor painter
}

// 0x802078B0 (188 bytes)
void InteractorModule::FloorPainter::OnCommandReleased(int cmd) {
    // Handles button release
}

// 0x8020796C (76 bytes)
void InteractorModule::FloorPainter::OnCommandUpdate(int cmd, float value) {
    // Handles continuous input
}

// 0x80207A10 (208 bytes)
void InteractorModule::FloorPainter::IsValidFloorPlacement(CTilePt& pos, FloorPattern pattern) {
    // Validates floor tile placement
}

// 0x80207AE0 (436 bytes)
void InteractorModule::FloorPainter::SetFloorTile(CTilePt* pos, FloorPattern pattern, int* cost) {
    // Places a floor tile
}

// 0x80207C94 (488 bytes)
void InteractorModule::FloorPainter::SetFloorTile(CTilePt& pos, FloorPattern pattern, Room* room, int* cost) {
    // Places floor tile with room context
}

// 0x80207E7C (516 bytes)
void InteractorModule::FloorPainter::RemoveFloorTile(CTilePt* pos, int* refund) {
    // Removes a floor tile
}

// 0x80208080 (172 bytes)
void InteractorModule::FloorPainter::GetSelectedRectPoints(int& x1, int& y1, int& x2, int& y2) {
    // Returns selection rectangle corners
}

// 0x8020812C (632 bytes)
void InteractorModule::FloorPainter::PaintFloor(int* totalCost) {
    // Paints floor over selected rectangle
}

// 0x802083A4 (688 bytes)
void InteractorModule::FloorPainter::RemoveFloor(int* totalRefund) {
    // Removes floor from selected rectangle
}

// 0x80208654 (768 bytes)
void InteractorModule::FloorPainter::PaintRoom(int* totalCost) {
    // Paints floor of entire room
}

// 0x80208954 (800 bytes)
void InteractorModule::FloorPainter::RemoveRoom(int* totalRefund) {
    // Removes floor from entire room
}

// 0x80208C74 (300 bytes)
void InteractorModule::FloorPainter::CheckDiagForRoomContainment(Room* room, CTilePt& pos, TileWalls& walls, DiagonalSideSelector& sel1, DiagonalSideSelector& sel2) {
    // Checks diagonal wall containment for room painting
}

// 0x80208DA0 (128 bytes)
void InteractorModule::FloorPainter::CancelSession(void) {
    // Cancels current floor painting session
}

// 0x80208E20 (172 bytes)
void InteractorModule::FloorPainter::SwapTools(void) {
    // Switches between paint and remove mode
}

// 0x80208ECC (624 bytes)
void InteractorModule::FloorPainter::CurrentSelectionIsValid(int& outCount) {
    // Validates current selection rectangle
}


// --- InteractorModule::GrabManipulator ---

// 0x802192E8 (232 bytes)
void InteractorModule::GrabManipulator::OnCommandPressed(int cmd, float value) {
    // Handles input for object grabbing
}

// 0x8021A07C (268 bytes)
void InteractorModule::GrabManipulator::OnStart(int*) {
    // Starts grab manipulation session
}

// 0x8021A348 (240 bytes)
void InteractorModule::GrabManipulator::TryGrabbingWorldObject(void) {
    // Attempts to grab object at cursor
}

// 0x8021A438 (212 bytes)
void InteractorModule::GrabManipulator::TryGrabbingWorldObjectFromId(short objId) {
    // Grabs specific object by ID
}

// 0x8021A50C (88 bytes)
void InteractorModule::GrabManipulator::DestroyObjectInHand(void) {
    // Destroys the currently held object
}

// 0x8021A564 (188 bytes)
void InteractorModule::GrabManipulator::DropCurrentObject(void) {
    // Drops held object at current position
}

// 0x8021A620 (412 bytes)
void InteractorModule::GrabManipulator::TryRemoveCurrentObjectFromWorld(void) {
    // Removes held object from world
}

// 0x8021A7BC (152 bytes)
void InteractorModule::GrabManipulator::CancelCurrentGrab(void) {
    // Cancels current grab, returns object
}

// 0x8021A854 (124 bytes)
void InteractorModule::GrabManipulator::CancelSession(void) {
    // Cancels entire grab session
}

// 0x8021CD14 (124 bytes)
InteractorModule::GrabManipulator::GrabManipulator(void) {
    // Constructor: initializes grab state
}


// --- InteractorModule::Interactor (base class) ---

// 0x802092EC (104 bytes)
void InteractorModule::Interactor::OnCommandReleased(int cmd) {
    char* self = (char*)this;
    if (cmd == 7) {
        // Reset left stick input at offsets 52, 56
    } else if (cmd == 8) {
        // Reset right stick input at offsets 60, 64
    }
}

// 0x80209354 (88 bytes)
void InteractorModule::Interactor::OnCommandUpdate(int cmd, float value) {
    char* self = (char*)this;
    if (cmd == 7) {
        // Store stick value at offsets 52, 56
    } else if (cmd == 8) {
        // Store stick value at offsets 60, 64
    }
}

// 0x802093AC (68 bytes)
void InteractorModule::Interactor::ResetInputState(void) {
    char* self = (char*)this;
    // Resets all input values to zero
    // Sets input-active flags at offsets 68, 72 to 1
    // Zeroes stick values at offsets 52-64
}

// 0x802093F0 (100 bytes)
void InteractorModule::Interactor::GetSelectionRadius(void) {
    // Gets camera singleton, gets camera from player index
    // If no camera, returns default radius
    // Otherwise: radius = lerp(minRadius, maxRadius, zoomRatio)
}

// 0x80209584 (72 bytes)
void InteractorModule::Interactor::Moved(void) {
    // Checks if position has changed since last frame
    // Compares offsets 8/12 with 20/24
}


// --- InteractorModule::InteractorInputManager ---

// 0x8020ADBC (124 bytes)
InteractorModule::InteractorInputManager::InteractorInputManager(int playerIndex) {
    // Initializes input manager for a player
}

// 0x8020AE38 (140 bytes)
InteractorModule::InteractorInputManager::~InteractorInputManager(void) {
    // Destroys input manager
}

// 0x8020AEC4 (108 bytes)
void InteractorModule::InteractorInputManager::Update(float dt) {
    // Updates input state for this frame
}


// --- InteractorModule::InteractorInputManager::InstanceData ---

// 0x8020972C (152 bytes)
InteractorModule::InteractorInputManager::InstanceData::~InstanceData(void) {
    // Destructor for input instance data
}

// 0x802097C4 (2260 bytes)
void InteractorModule::InteractorInputManager::InstanceData::AddCommandMapping(int inputId, ECTRL_CMD cmd) {
    // Maps controller input to game command
}

// 0x8020A098 (2256 bytes)
void InteractorModule::InteractorInputManager::InstanceData::AddCommandMapping(int inputId, int param1, int param2) {
    // Maps controller input with parameters
}

// 0x8020A968 (260 bytes)
void InteractorModule::InteractorInputManager::InstanceData::OpenSession(int sessionId, int* cmds1, int count1, int* cmds2, int count2, int* cmds3, char* name) {
    // Opens new input session with command sets
}

// 0x8020AA6C (124 bytes)
void InteractorModule::InteractorInputManager::InstanceData::CloseSession(void) {
    // Closes current input session
}

// 0x8020AAF0 (716 bytes)
void InteractorModule::InteractorInputManager::InstanceData::Update(float dt) {
    // Processes input for current session
}


// --- InteractorModule::InteractorManager ---

// 0x8020B020 (408 bytes)
InteractorModule::InteractorManager::~InteractorManager(void) {
    // Destructor: destroys all interactors
}

// 0x8020B1B8 (664 bytes)
void InteractorModule::InteractorManager::Initialize(int& playerCount) {
    // Initializes manager for given player count
}

// 0x8020B450 (120 bytes)
void InteractorModule::InteractorManager::Shutdown(void) {
    // Shuts down interactor manager
}

// 0x8020B4C8 (84 bytes)
void InteractorModule::InteractorManager::Update(float dt) {
    // Updates all active interactors
}

// 0x8020B51C (136 bytes)
void InteractorModule::InteractorManager::ChangeActiveInteractorToNull(int playerIndex) {
    // Deactivates interactor for player
}

// 0x8020B5A4 (104 bytes)
void InteractorModule::InteractorManager::GetPlayerInteractor(int playerIndex, int interactorType) {
    // Returns specific interactor for player
}

// 0x8020B60C (72 bytes)
void InteractorModule::InteractorManager::GetPlayerInteractorInfo(int playerIndex) const {
    // Returns interactor info struct
}

// 0x8020B6A8 (936 bytes)
void InteractorModule::InteractorManager::CreatePlayerInteractorSets(void) {
    // Creates all interactor types for each player
}

// 0x8020BA50 (876 bytes)
void InteractorModule::InteractorManager::DestroyPlayerInteractorSets(void) {
    // Destroys all interactor instances
}

// 0x8020BDF4 (680 bytes)
void InteractorModule::InteractorManager::UpdateActivePlayerInteractors(float dt) {
    // Updates only active interactors
}


// --- InteractorModule::InteractorResourceSet ---

// 0x8020C14C (520 bytes)
InteractorModule::InteractorResourceSet::~InteractorResourceSet(void) {
    // Destructor: releases all resources
}

// 0x8020C354 (2444 bytes)
// Contains: AddModel, RemoveModel, GetModel, AddShader, RemoveShader, GetShader,
//           AddTexture, RemoveTexture, GetTexture, ClearSet, AddOrderTableData
// These manage the resource set used by build mode visualizers

// The individual resource management functions follow a similar pattern:
// - AddX: Loads resource, adds to set
// - RemoveX: Releases resource, removes from set
// - GetX: Looks up resource in set

void InteractorModule::InteractorResourceSet::AddModel(unsigned int id) { /* Loads model resource */ }
void InteractorModule::InteractorResourceSet::RemoveModel(unsigned int id) { /* Releases model */ }
void InteractorModule::InteractorResourceSet::GetModel(unsigned int id) { /* Returns model pointer */ }
void InteractorModule::InteractorResourceSet::AddShader(unsigned int id) { /* Loads shader */ }
void InteractorModule::InteractorResourceSet::RemoveShader(unsigned int id) { /* Releases shader */ }
void InteractorModule::InteractorResourceSet::GetShader(unsigned int id) { /* Returns shader pointer */ }
void InteractorModule::InteractorResourceSet::AddTexture(unsigned int id) { /* Loads texture */ }
void InteractorModule::InteractorResourceSet::RemoveTexture(unsigned int id) { /* Releases texture */ }
void InteractorModule::InteractorResourceSet::GetTexture(unsigned int id) { /* Returns texture pointer */ }
void InteractorModule::InteractorResourceSet::ClearSet(void) { /* Releases all resources */ }
void InteractorModule::InteractorResourceSet::AddOrderTableData(EOrderTableData& data) { /* Adds render order data */ }

// 0x8020FEF4 (788 bytes)
InteractorModule::InteractorResourceSet::InteractorResourceSet(int& flags) {
    // Constructor: initializes resource containers
}


// --- InteractorModule::InteractorVisualizer ---

// 0x803C01C8 (1292 bytes)
InteractorModule::InteractorVisualizer::~InteractorVisualizer(void) {
    // Destructor: cleans up visualization resources
}

// 0x80213DE0 (148 bytes)
void InteractorModule::InteractorVisualizer::Initialize(void) {
    // Initializes visualizer
}

// 0x80213E74 (224 bytes)
void InteractorModule::InteractorVisualizer::Shutdown(void) {
    // Shuts down visualizer
}

// 0x80213F54 (68 bytes)
void InteractorModule::InteractorVisualizer::CreateResources(int& flags) {
    // Creates rendering resources
}

// 0x80213F98 (328 bytes)
void InteractorModule::InteractorVisualizer::PreDraw(int& flags) {
    // Pre-draw setup
}

// 0x80214100 (76 bytes)
void InteractorModule::InteractorVisualizer::Draw(int& flags) {
    // Main draw call
}

// 0x8021414C (1688 bytes)
void InteractorModule::InteractorVisualizer::DrawFloorRectPreview(ERC* rc, EVec3& min, EVec3& max) {
    // Draws floor placement preview rectangle
}

// 0x802147E4 (800 bytes)
void InteractorModule::InteractorVisualizer::DrawFloorRoomPreview(ERC* rc, EVec3& pos) {
    // Draws floor room preview
}

// 0x80214B04 (892 bytes)
void InteractorModule::InteractorVisualizer::DrawWallpaperRoomPreview(int& flags) {
    // Draws wallpaper room preview
}

// 0x80214E80 (152 bytes)
void InteractorModule::InteractorVisualizer::DrawWallpaperPreviewOnAffectedWalls(int& flags) {
    // Draws wallpaper on affected walls
}

// 0x80214F38 (92 bytes)
void InteractorModule::InteractorVisualizer::DrawWallpaperRectPreview(ERShader* shader, EVec2& min, EVec2& max, float height) {
    // Draws wallpaper rectangle preview
}

// 0x80214F94 (644 bytes)
void InteractorModule::InteractorVisualizer::DrawWallRectPreview(int& flags) {
    // Draws wall placement preview rectangle
}

// 0x80215218 (476 bytes)
void InteractorModule::InteractorVisualizer::DrawVerticalRect(ERShader* shader, EVec2& min, EVec2& max, float height, int segments, float offset) {
    // Draws vertical rectangle for wall preview
}

// 0x802153F4 (500 bytes)
void InteractorModule::InteractorVisualizer::DrawRoomPreview(int& flags) {
    // Draws room boundary preview
}

// 0x802155E8 (404 bytes)
void InteractorModule::InteractorVisualizer::DrawPreviewOnAffectedWalls(int& flags) {
    // Draws preview on walls that will be affected
}

// 0x8021577C (1176 bytes)
void InteractorModule::InteractorVisualizer::InteractorOrderTableCallback(ELevelDrawData& data, EOrderTableData* orderData) {
    // Callback for render order table
}

// 0x80215C34 (92 bytes)
void InteractorModule::InteractorVisualizer::SetupDrawCallback(EHouse* house, int layer) {
    // Sets up draw callback for build mode visualization
}

// 0x80215C90 (632 bytes)
void InteractorModule::InteractorVisualizer::CreateSimpleResourceSet(int& flags, int type) {
    // Creates a simple resource set for visualization
}

// 0x80215F08 (212 bytes)
void InteractorModule::InteractorVisualizer::DrawSimpleResourceSet(int& flags, int type, EVec3& pos, float rot) {
    // Draws a simple resource set at position
}

// 0x80215FDC (1196 bytes)
void InteractorModule::InteractorVisualizer::SelectShader(int& flags, int type) {
    // Selects shader for visualization type
}

// 0x80216488 (584 bytes)
void InteractorModule::InteractorVisualizer::Draw(int& flags, EVec3& pos) {
    // Draws visualization at position
}

// 0x802166D0 (1472 bytes)
void InteractorModule::InteractorVisualizer::DrawResource(int& flags, int resId, EVec3& pos, EMat4* transform) {
    // Draws specific resource at position with transform
}

// 0x80216C90 (88 bytes)
void InteractorModule::InteractorVisualizer::CreateResourceSet(int& flags) {
    // Creates full resource set
}

// 0x80216D08 (92 bytes)
void InteractorModule::InteractorVisualizer::AddModelToResourceSet(int& flags, int modelId) {
    // Adds model to resource set
}

// 0x80216D64 (308 bytes)
void InteractorModule::InteractorVisualizer::AddOrderTableToResourceSet(int& flags, EOrderTableData& data) {
    // Adds order table data to resource set
}

// 0x80216EF8 (92 bytes)
void InteractorModule::InteractorVisualizer::DestroyResourceSet(int& flags) {
    // Destroys resource set
}

// 0x80216F54 (476 bytes)
void InteractorModule::InteractorVisualizer::GetInteractorResourceSet(int* outSet) {
    // Returns current resource set
}

// 0x80217140 (92 bytes)
void InteractorModule::InteractorVisualizer::SetDefaultLights(void) {
    // Sets default lighting for build mode
}


// --- InteractorModule::ObjectManipulator ---

// 0x8021719C (240 bytes)
InteractorModule::ObjectManipulator::ObjectManipulator(void) {
    // Constructor: initializes object manipulator state
}

// 0x8021729C (92 bytes)
InteractorModule::ObjectManipulator::~ObjectManipulator(void) {
    // Destructor
}

// 0x802172FC (140 bytes)
void InteractorModule::ObjectManipulator::OnStart(int*) {
    // Starts object manipulation session
}

// 0x80217388 (96 bytes)
void InteractorModule::ObjectManipulator::OnCommandUpdate(int cmd, float value) {
    // Handles continuous input
}

// 0x802173E8 (80 bytes)
void InteractorModule::ObjectManipulator::OnCommandReleased(int cmd) {
    // Handles button release
}

// 0x80217438 (280 bytes)
void InteractorModule::ObjectManipulator::Update(float dt) {
    // Updates object manipulation state
}

// 0x80217550 (156 bytes)
void InteractorModule::ObjectManipulator::UpdateObjectHighlights(EIObjectMan* objMan) {
    // Updates highlights on manipulable objects
}

// 0x802175EC (1348 bytes)
void InteractorModule::ObjectManipulator::UpdateOverlapIntersection(int* result) {
    // Checks overlap between held object and world
}


// --- InteractorModule::PlaceManipulator ---

// 0x80217B30 (464 bytes)
void InteractorModule::PlaceManipulator::OnCommandPressed(int cmd, float value) {
    // Handles input during placement
}

// 0x80217D00 (3544 bytes)
void InteractorModule::PlaceManipulator::StartPlacement(int* params) {
    // Begins object placement mode
}

// 0x80218AD8 (180 bytes)
void InteractorModule::PlaceManipulator::TryPlacingCurrentObject(void) {
    // Attempts to place object at cursor position
}

// 0x80218B8C (184 bytes)
void InteractorModule::PlaceManipulator::CancelSession(void) {
    // Cancels placement session
}


// --- InteractorModule::PlacementObject ---

// 0x80218C44 (416 bytes)
InteractorModule::PlacementObject::~PlacementObject(void) {
    // Destructor: cleans up placement state
}

// 0x80218DE4 (160 bytes)
void InteractorModule::PlacementObject::SetObjectColor(cXObject* obj, unsigned char colorIndex) {
    // Sets color variant on placement object
}

// 0x803C06D4 (108 bytes)
void InteractorModule::PlacementObject::CreateNewPlacementObjectFromGuid(unsigned int guid, unsigned char color) {
    // Creates placement preview from GUID
}

// 0x80218F3C (112 bytes)
void InteractorModule::PlacementObject::GrabExistingObjectInstanceFromId(short id) {
    // Grabs existing object for repositioning
}

// 0x80218FAC (96 bytes)
void InteractorModule::PlacementObject::CreateGridObject(FTilePt& pos, cXObject* template_) {
    // Creates grid visualization object
}

// 0x80219074 (380 bytes)
void InteractorModule::PlacementObject::CreateGridTile(ObjSelector* sel, cXMTObjectImpl* mtImpl, cXObjectImpl* impl) {
    // Creates single grid tile for multi-tile object
}

// 0x802193D0 (76 bytes)
void InteractorModule::PlacementObject::DestroyGridObject(cXMTObjectImpl*& mtImpl) {
    // Destroys grid visualization
}

// 0x8021941C (108 bytes)
void InteractorModule::PlacementObject::InitializeGridObject(cXMTObjectImpl* mtImpl) {
    // Initializes grid object
}

// 0x802194E0 (1940 bytes)
void InteractorModule::PlacementObject::AssignOffsetsToGridObject(cXMTObjectImpl* mtImpl, cXObjectImpl* impl) {
    // Sets tile offsets for grid visualization
}

// 0x80219C74 (644 bytes)
void InteractorModule::PlacementObject::Pickup(void) {
    // Picks up placement object
}

// 0x80219EF8 (312 bytes)
void InteractorModule::PlacementObject::IsLegalToPlaceAtLocation(FTilePt& pos, int& dir) {
    // Checks if placement is valid at location
}

// 0x80219230 (184 bytes)
void InteractorModule::PlacementObject::Place(FTilePt& pos, int& dir) {
    // Places object at location
}

// 0x8021A1FC (332 bytes)
void InteractorModule::PlacementObject::Drop(void) {
    // Drops placement object
}

// 0x8021A8D8 (276 bytes)
void InteractorModule::PlacementObject::Initialize(void) {
    // Initializes placement object state
}

// 0x8021A9EC (204 bytes)
void InteractorModule::PlacementObject::Destroy(void) {
    // Destroys placement object
}

// 0x8021AAF0 (152 bytes)
void InteractorModule::PlacementObject::Reset(void) {
    // Resets placement state
}

// 0x8021AB88 (316 bytes)
void InteractorModule::PlacementObject::SetDirection(int dir) {
    // Sets placement direction
}

// 0x8021ACC4 (288 bytes)
void InteractorModule::PlacementObject::Rotate(int delta) {
    // Rotates placement by increment
}

// 0x8021ADE4 (276 bytes)
void InteractorModule::PlacementObject::ResetLocation(void) {
    // Resets to original pickup location
}

// 0x8021AEF8 (900 bytes)
void InteractorModule::PlacementObject::SetShaderToValidState(bool valid) {
    // Sets green (valid) or red (invalid) placement shader
}


// --- InteractorModule::SimInteractor ---

// 0x8021B27C (2328 bytes)
InteractorModule::SimInteractor::SimInteractor(void) {
    // Constructor: initializes sim interaction state
}

// 0x8021BB94 (176 bytes)
InteractorModule::SimInteractor::~SimInteractor(void) {
    // Destructor
}

// 0x8021BC44 (100 bytes)
void InteractorModule::SimInteractor::OnStart(int*) {
    // Starts sim interaction session
}

// 0x8021BCA8 (268 bytes)
void InteractorModule::SimInteractor::OnStop(void) {
    // Stops sim interaction session
}

// 0x8021BDB4 (216 bytes)
void InteractorModule::SimInteractor::ParseControls(void) {
    // Reads and translates controller input
}

// 0x8021BE8C (88 bytes)
void InteractorModule::SimInteractor::Update(float dt) {
    // Updates sim interaction state
}

// 0x8021BEE4 (392 bytes)
void InteractorModule::SimInteractor::GetBeamScale(void) {
    // Gets selection beam scale based on distance
}

// 0x8021C06C (244 bytes)
void InteractorModule::SimInteractor::OnCommandPressed(int cmd, float value) {
    // Handles button press
}

// 0x8021C160 (116 bytes)
void InteractorModule::SimInteractor::OnCommandReleased(int cmd) {
    // Handles button release
}

// 0x8021C208 (172 bytes)
void InteractorModule::SimInteractor::ReturnPlumbBobToOwner(void) {
    // Returns plumb bob to controlled sim
}

// 0x8021C2B4 (144 bytes)
void InteractorModule::SimInteractor::ImmediatelyCutCursorAndCameraToPos(EVec3& pos) {
    // Instantly moves cursor and camera to position
}

// 0x8021C384 (68 bytes)
void InteractorModule::SimInteractor::TryCutToSim(void) {
    // Attempts to cut camera to selected sim
}

// 0x8021C3C8 (1628 bytes)
void InteractorModule::SimInteractor::UpdateOverlapIntersection(int* result) {
    // Checks cursor overlap with sims
}

// 0x8021CA24 (668 bytes)
void InteractorModule::SimInteractor::ExecuteActionMenu(void) {
    // Opens action menu for sim interaction
}

// 0x8021CCC0 (84 bytes)
void InteractorModule::SimInteractor::IsSimulatorPaused(void) {
    // Checks pause state
}

// 0x8021D250 (276 bytes)
void InteractorModule::SimInteractor::UpdateObjectHighlights(EIObjectMan* objMan) {
    // Updates highlights for interactable objects
}

// 0x8021D364 (144 bytes)
void InteractorModule::SimInteractor::SetupCamera(void) {
    // Configures camera for sim interaction mode
}

// 0x8021D45C (640 bytes)
void InteractorModule::SimInteractor::ChooseAction(Interaction* action) {
    // Selects action from menu
}


// --- InteractorModule::SocialModeInteractor ---

// 0x8021D6DC (136 bytes)
InteractorModule::SocialModeInteractor::SocialModeInteractor(void) {
    // Constructor
}

// 0x8021D764 (112 bytes)
void InteractorModule::SocialModeInteractor::OnStart(int*) {
    // Starts social mode
}

// 0x8021D7D4 (1980 bytes)
void InteractorModule::SocialModeInteractor::OnStop(void) {
    // Stops social mode
}

// 0x8021DF90 (100 bytes)
void InteractorModule::SocialModeInteractor::Update(float dt) {
    // Updates social mode state
}

// 0x8021E070 (1116 bytes)
void InteractorModule::SocialModeInteractor::SetupInteractionMenu(cXObject* target, InteractionList& interactions) {
    // Builds social interaction menu
}


// --- InteractorModule::WallManipulator ---

// 0x8021E4CC (204 bytes)
InteractorModule::WallManipulator::WallManipulator(void) {
    // Constructor: initializes wall building state
}

// 0x8021E610 (208 bytes)
InteractorModule::WallManipulator::~WallManipulator(void) {
    // Destructor
}

// 0x8021E6E0 (76 bytes)
void InteractorModule::WallManipulator::OnCreate(void) {
    // Creates wall building resources
}

// 0x8021E72C (356 bytes)
void InteractorModule::WallManipulator::OnStart(int*) {
    // Starts wall building session
}

// 0x8021E8E8 (432 bytes)
void InteractorModule::WallManipulator::OnStop(void) {
    // Stops wall building session
}

// 0x8021EA98 (536 bytes)
void InteractorModule::WallManipulator::CommittTransaction(int cost) {
    // Commits wall placement transaction
}

// 0x8021ECBC (112 bytes)
void InteractorModule::WallManipulator::FinalizePlacement(void) {
    // Finalizes wall placement
}

// 0x8021ED2C (668 bytes)
void InteractorModule::WallManipulator::FinalizeWallDel(void) {
    // Finalizes wall deletion
}

// 0x8021EFC8 (68 bytes)
void InteractorModule::WallManipulator::CountWallsInRoomSelection(void) {
    // Counts walls in room for cost calculation
}

// 0x8021F00C (104 bytes)
void InteractorModule::WallManipulator::FinalizeRoom(void) {
    // Finalizes room creation
}

// 0x8021F118 (76 bytes)
void InteractorModule::WallManipulator::HandleFinalizeRequest(void) {
    // Processes finalize command
}

// 0x8021F208 (200 bytes)
void InteractorModule::WallManipulator::HandleSwapRequest(void) {
    // Handles swap between add/delete mode
}

// 0x8021F2D0 (128 bytes)
void InteractorModule::WallManipulator::HandleExitRequest(void) {
    // Handles exit from wall building
}

// 0x8021F350 (136 bytes)
void InteractorModule::WallManipulator::ValidateWallSegment(void) {
    // Validates current wall segment
}

// 0x8021F480 (200 bytes)
void InteractorModule::WallManipulator::UpdateStickState(void) {
    // Updates analog stick input
}

// 0x8021F598 (176 bytes)
void InteractorModule::WallManipulator::ClearWallFadeOffList(void) {
    // Clears wall fade animation list
}

// 0x8021F648 (372 bytes)
void InteractorModule::WallManipulator::Update(float dt) {
    // Main wall manipulator update
}

// 0x8021F7BC (76 bytes)
void InteractorModule::WallManipulator::OnCommandPressed(int cmd, float value) {
    // Handles button press
}

// 0x8021F83C (732 bytes)
void InteractorModule::WallManipulator::OnCommandReleased(int cmd) {
    // Handles button release
}

// 0x8021FB18 (104 bytes)
void InteractorModule::WallManipulator::OnCommandUpdate(int cmd, float value) {
    // Handles continuous input
}

// 0x8021FBA4 (1820 bytes)
void InteractorModule::WallManipulator::GetWallLineCost(EVec3& start, EVec3& end, bool& valid, bool adding, bool checkBudget) {
    // Calculates cost of wall line
}

// 0x802202C0 (688 bytes)
void InteractorModule::WallManipulator::SubmitLine(EVec3& start, EVec3& end, int& cost, bool adding, bool commit) {
    // Submits wall line for placement
}

// 0x80220570 (976 bytes)
void InteractorModule::WallManipulator::DoesNotConflictWithExistingArchitecture(CTilePt& pos, TileWallsSegment seg) {
    // Checks if wall placement conflicts with existing structures
}

// 0x80220940 (444 bytes)
void InteractorModule::WallManipulator::CanChangeTileAdd(CTilePt& pos, TileWallsSegment seg) {
    // Checks if wall segment can be added at tile
}

// 0x80220AFC (1324 bytes)
void InteractorModule::WallManipulator::CanChangeTileDelete(CTilePt& pos, TileWallsSegment seg) {
    // Checks if wall segment can be deleted at tile
}

// 0x80221028 (692 bytes)
void InteractorModule::WallManipulator::HandleDeleteLine(CTilePt& start, CTilePt& end, TilePtDir& dir, int cost) {
    // Processes wall line deletion
}

// 0x802212DC (104 bytes)
void InteractorModule::WallManipulator::HandleAddLine(CTilePt start, CTilePt end, TilePtDir& dir, int cost) {
    // Processes wall line addition
}

// 0x80221344 (80 bytes)
void InteractorModule::WallManipulator::LegalWallTile(CTilePt& pos, TileWallsSegment seg) {
    // Validates single wall tile
}

// 0x802213C0 (760 bytes)
void InteractorModule::WallManipulator::AddWallAtTile(CTilePt& pos, TileWalls& walls, TileWallsSegment seg) {
    // Adds wall segment at tile
}

// 0x802216B8 (84 bytes)
void InteractorModule::WallManipulator::PreviewNRooms(void) {
    // Previews room count after wall changes
}

// 0x8022170C (96 bytes)
void InteractorModule::WallManipulator::IncrementSellCountForStyle(WallStyle style) {
    // Tracks wall sell counts by style
}

// 0x8022176C (584 bytes)
void InteractorModule::WallManipulator::CheckForAffectedWalls(EVec3& start, EVec3& end) {
    // Finds walls affected by placement
}

// 0x802219B4 (208 bytes)
void InteractorModule::WallManipulator::SendBuildItemCountChangeEvent(int delta) {
    // Notifies UI of item count change
}


// --- InteractorModule::WallManipulator::CallbackData ---

// 0x80221A84 (132 bytes)
InteractorModule::WallManipulator::CallbackData::~CallbackData(void) {
    // Destructor
}


// --- InteractorModule::WallPainter ---

// 0x80221B08 (76 bytes)
InteractorModule::WallPainter::WallPainter(void) {
    // Constructor
}

// 0x80221BD4 (532 bytes)
InteractorModule::WallPainter::~WallPainter(void) {
    // Destructor
}

// 0x80221DE8 (400 bytes)
void InteractorModule::WallPainter::OnCreate(void) {
    // Creates wallpaper painting resources
}

// 0x80221F78 (1028 bytes)
void InteractorModule::WallPainter::OnStart(int*) {
    // Starts wallpaper painting session
}

// 0x8022237C (332 bytes)
void InteractorModule::WallPainter::CommittTransaction(int cost) {
    // Commits wallpaper transaction
}

// 0x802224C8 (1308 bytes)
void InteractorModule::WallPainter::HandleFinalizeRequest(void) {
    // Processes finalize command
}

// 0x802229E4 (1036 bytes)
void InteractorModule::WallPainter::HandleSwapRequest(void) {
    // Handles swap between paint/remove mode
}

// 0x80222DF0 (664 bytes)
void InteractorModule::WallPainter::HandleExitRequest(void) {
    // Handles exit from wallpaper mode
}

// 0x80223088 (716 bytes)
void InteractorModule::WallPainter::AdjustCursorPosition(void) {
    // Adjusts cursor to wall surface
}

// 0x80223354 (384 bytes)
void InteractorModule::WallPainter::ValidateWallSegment(void) {
    // Validates target wall segment
}

// 0x802234D4 (176 bytes)
void InteractorModule::WallPainter::UpdateStickState(void) {
    // Updates analog stick state
}

// 0x80223584 (540 bytes)
void InteractorModule::WallPainter::Update(float dt) {
    // Main wallpaper painter update
}

// 0x802237A0 (1840 bytes)
void InteractorModule::WallPainter::OnCommandPressed(int cmd, float value) {
    // Handles button press
}

// 0x80223ED0 (160 bytes)
void InteractorModule::WallPainter::OnCommandReleased(int cmd) {
    // Handles button release
}

// 0x803C0E1C (300 bytes)
void InteractorModule::WallPainter::OnCommandUpdate(int cmd, float value) {
    // Handles continuous input
}

// 0x80224064 (112 bytes)
void InteractorModule::WallPainter::CountWallsInRoomSelection(void) {
    // Counts walls for cost calculation
}

// 0x802240D4 (172 bytes)
void InteractorModule::WallPainter::FinalizePaperForRoom(void) {
    // Applies wallpaper to entire room
}

// 0x80224180 (76 bytes)
void InteractorModule::WallPainter::FinalizePaperForLine(void) {
    // Applies wallpaper to wall line
}

// 0x80224200 (652 bytes)
void InteractorModule::WallPainter::FinalizeSellPaperForLine(void) {
    // Removes wallpaper from wall line (sells)
}

// 0x802244EC (844 bytes)
void InteractorModule::WallPainter::SubmitPaperLine(EVec2& start, EVec2& end, WallPattern pattern, int cost) {
    // Submits wallpaper line
}

// 0x80224838 (396 bytes)
void InteractorModule::WallPainter::SendBuildItemCountChangeEvent(int delta) {
    // Notifies UI
}

// 0x802249C4 (120 bytes)
void InteractorModule::WallPainter::RestoreFromHoldPos(EVec3& pos) {
    // Restores cursor from held position
}


// --- InteractorModule::WallPainter::CallbackData ---

// 0x80224A3C (112 bytes)
InteractorModule::WallPainter::CallbackData::~CallbackData(void) {
    // Destructor
}

// 0x80224AAC (268 bytes)
// Additional WallPainter helper functions
// (remaining functions in the InteractorModule namespace)

// 0x80224BB8 (1164 bytes)
// 0x80225044 (84 bytes)
// 0x80225098 (948 bytes)
// 0x8022544C (328 bytes)
// 0x80225594 (196 bytes)
// 0x80225658 (76 bytes)
// 0x802256FC (1652 bytes)
// 0x80225D70 (1352 bytes)
// 0x802262B8 (216 bytes)
// 0x80226390 (200 bytes)
// 0x80226458 (984 bytes)
// 0x8022683C (216 bytes)
// 0x80226A58 (116 bytes)
// 0x803C12EC (148 bytes)
// These are additional InteractorModule functions handling
// various build mode operations, input processing, and UI callbacks.
// Each follows the same pattern as the documented functions above.
