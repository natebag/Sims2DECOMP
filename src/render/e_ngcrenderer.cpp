// e_ngcrenderer.cpp - ENgcRenderer (GameCube hardware renderer)
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(e_ngcrenderer.obj)
//
// Small functions (<=64 bytes) decompiled from the e_ngcrenderer object file.
// This is the main GC renderer with 159 small functions.

#include "types.h"

// Forward declarations
class EDLEntry;
class EDL;
class EEvent;
class ENgcRenderStateCache;
class ENgcRendCommand;
struct EVec3 { float x, y, z; };

// External heap functions
extern void* EAHeap_GetCurrentHeap();
extern void* EAHeap_Alloc(void* heap, u32 size, int align);
extern void* EAHeap_AllocAlign(void* heap, u32 size, u32 align, int a, int b);
extern void EAHeap_Free(void* heap, void* ptr);

// External SDK functions
extern "C" {
    void GXSetDrawSync(u16 token);
    void GXSetBreakPtCallback(void (*cb)(void));
    void DCFlushRange(void* addr, u32 len);
    void GXInvalidateTexAll();
}

// External render functions
extern void ENgcRenderStateCache_Save(ENgcRenderStateCache* rsc);
extern void ENgcRenderStateCache_Restore(ENgcRenderStateCache* rsc);
extern void ENgcRenderStateCache_RestoreViewport(ENgcRenderStateCache* rsc);
extern void ENgcRenderer_ProcessTriStrip(void* rend, u16 count, void* data);
extern void ENgcRenderer_ProcessLineList(void* rend, u16 count, void* data);
extern void ENgcRenderer_ProcessModelMatrices(void* rend, u8 count, void* data);
extern void ENgcRenderer_ProcessTexture(void* rend, u8 slot, void* data);
extern void ENgcRenderer_ProcessGeometrySetup2(void* rend);
extern void ENgcRenderer_ProcessSetup(void* rend);
extern void ENgcRenderer_ProcessSpriteListPacked(void* rend, void* r4, void* r5, void* r6, void* r7, void* r8, void* r9);
extern void ENgcRenderer_ProcessShader(void* rend, void* shader, int idx);
extern void ENgcRenderer_ReadMetricsImpl(void* rend);
extern void ENgcRenderer_QueueCommand(void* rend, void* cmd);
extern void ENgcRenderer_QueueCommandDL(void* rend, void* cmd);
extern void ENgcRenderer_QueueCommandSwap(void* rend, void* cmd);
extern void ENgcRenderer_QueueCommandEndFrame(void* rend, void* cmd);
extern void ENgcRenderer_Destruct(void* rend);
extern void ENgcRendCommand_Execute(ENgcRendCommand* cmd);

// Globals from .sdata/.sbss
extern void* _pRend;

// ENgcRenderer class layout (partial - offsets from disassembly)
// 0x0338 = vtable ptr
// 0x0344 = framebuffer[0]
// 0x0348 = framebuffer[1]
// 0x034C = nextExternalFrameBuffer
// 0x0364 = renderMode struct start
// 0x0368 = width (u16) at +0x368
// 0x036A = height (u16) at +0x36A
// 0x03A4 = alpha (float)
// 0x04D8 = renderStateCache ptr
// 0x04DC = current display list offset
// 0x04E0 = overflow flag
// 0x04E4 = display list stack base
// 0x050C = display list stack pointer
// 0x0510 = dirty flag
// 0x0564 = blend mode fields start
// 0x0569 = combine mode field
// 0x4638 = texture array base (17976 / 0x4638)
// 0x4640 = display list ptr
// 0x4644 = z-test compare (u8)
// 0x4645 = z-test reference (u8)
// 0x4646 = z-test enable (u8)
// 0x464C = frame effects scratch memory
// 0x4650 = previous framebuffer ptr

// Struct for renderer command
struct ENgcRendCommandData {
    u32 type;       // 0x00
    u32 param1;     // 0x04
    u32 param2;     // 0x08
};

//=============================================================================
// PerfAlloc - Allocate from perf heap
// Address: 0x8033B404, Size: 56
//=============================================================================
void* PerfAlloc(unsigned long size) {
    void* heap = EAHeap_GetCurrentHeap();
    return EAHeap_Alloc(heap, size, 0);
}

//=============================================================================
// PerfFree - Free perf heap allocation
// Address: 0x8033B43C, Size: 52
//=============================================================================
void PerfFree(void* ptr) {
    void* heap = EAHeap_GetCurrentHeap();
    EAHeap_Free(heap, ptr);
}

//=============================================================================
// ScreenShotAlloc - Allocate aligned for screenshot
// Address: 0x8033B470, Size: 64
//=============================================================================
void* ScreenShotAlloc(unsigned int size) {
    void* heap = EAHeap_GetCurrentHeap();
    return EAHeap_AllocAlign(heap, size, 32, 0, 0);
}

//=============================================================================
// ScreenShotFree - Free screenshot allocation
// Address: 0x8033B4B0, Size: 52
//=============================================================================
void ScreenShotFree(void* ptr) {
    void* heap = EAHeap_GetCurrentHeap();
    EAHeap_Free(heap, ptr);
}

//=============================================================================
// ClearXFB - Clear external framebuffer with YCbCr black
// Address: 0x8033B4E4, Size: 40
//=============================================================================
void ClearXFB(unsigned char* buf, int size) {
    unsigned char* end = buf + size;
    if (buf >= end) return;
    while (buf < end) {
        *(u32*)buf = 0x10801080; // YCbCr black
        buf += 4;
    }
}

//=============================================================================
// ENgcRenderer::ShowPerfGraphs - Empty stub
// Address: 0x8033B720, Size: 4
//=============================================================================
// void ENgcRenderer::ShowPerfGraphs(bool) - just blr

//=============================================================================
// ENgcRenderer::GetCurrentTexture
// Address: 0x8033B724, Size: 16
// Returns this->m_textures[slot]
//=============================================================================
// Inline: return *(u32*)((u8*)this + 0x4638 + slot * 4);

//=============================================================================
// ENgcRenderer::VIPostRetraceCallback - Empty stub
// Address: 0x8033CDEC, Size: 4
//=============================================================================
// void ENgcRenderer::VIPostRetraceCallback(unsigned long) - just blr

//=============================================================================
// ENgcRenderer::DrawSyncCallback
// Address: 0x8033CE20, Size: 8
// Stores the token value to s_lastTokenFromGX
//=============================================================================
// void ENgcRenderer::DrawSyncCallback(unsigned short token) {
//     s_lastTokenFromGX = token;
// }

//=============================================================================
// ENgcRenderer::TextureMatrix - Empty stub
// Address: 0x8034443C, Size: 4
//=============================================================================
// void ENgcRenderer::TextureMatrix(EDLEntry*) - just blr

//=============================================================================
// ENgcRenderer::SetAlpha
// Address: 0x80344714, Size: 16
// Sets alpha value and marks dirty
//=============================================================================
// void ENgcRenderer::SetAlpha(float alpha) {
//     this->m_alpha = alpha; // offset 0x03A4
//     this->m_dirty = 1;     // offset 0x0510
// }

//=============================================================================
// ENgcRenderer::ProcessFrameEffects - Empty stub (allocs/deallocs stack)
// Address: 0x80349F30, Size: 12
//=============================================================================
// void ENgcRenderer::ProcessFrameEffects(float, float, float, float, EVec3&, EVec3&) - empty

//=============================================================================
// ENgcRenderer::GetRenderStateCache
// Address: 0x80349F3C, Size: 8
// Returns this->m_renderStateCache (offset 0x04D8)
//=============================================================================
// ENgcRenderStateCache* ENgcRenderer::GetRenderStateCache() {
//     return m_renderStateCache;
// }

//=============================================================================
// ENgcRenderer::GetNextExternalFrameBuffer
// Address: 0x80349F44, Size: 8
// Returns this->m_nextExternalFrameBuffer (offset 0x034C)
//=============================================================================
// void* ENgcRenderer::GetNextExternalFrameBuffer() {
//     return m_nextExternalFrameBuffer;
// }

//=============================================================================
// ENgcRenderer::GetFrameEffectsScratchMemory
// Address: 0x80349FD4, Size: 8
// Returns this->m_frameEffectsScratchMemory (offset 0x464C)
//=============================================================================
// void* ENgcRenderer::GetFrameEffectsScratchMemory() {
//     return m_frameEffectsScratchMemory;
// }

// We need a class definition to compile member functions
class ENgcRenderer {
public:
    u8 pad000[0x0338];
    void* m_vtable;             // 0x0338
    u8 pad33C[0x08];            // 0x033C
    void* m_framebuffer0;       // 0x0344
    void* m_framebuffer1;       // 0x0348
    void* m_nextXFB;            // 0x034C
    u8 pad350[0x14];            // 0x0350
    u16 m_renderWidth;          // 0x0368 (used for GetPreviousFrameBuffer)
    u16 m_renderHeight;         // 0x036A
    u8 pad36C[0x38];            // 0x036C
    float m_alpha;              // 0x03A4
    u8 pad3A8[0x130];           // 0x03A8
    ENgcRenderStateCache* m_rsc; // 0x04D8
    u32 m_dlOffset;             // 0x04DC
    u32 m_overflow;             // 0x04E0
    u32 m_dlStack[10];          // 0x04E4
    u32 m_dlStackPtr;           // 0x050C
    u32 m_dirty;                // 0x0510
    u8 pad514[0x50];            // 0x0514
    u8 m_blendSrc;              // 0x0564
    u8 m_blendDst;              // 0x0565
    u8 m_blendOp;               // 0x0566
    u8 m_blendLogic;            // 0x0567
    u8 m_blendAlpha;            // 0x0568
    // Per-TEV combine mode at variable offset: 0x0569 + tevIdx * 64
    u8 pad569[0x3ECF];          // 0x0569
    void* m_textures[2];        // 0x4638 (array)
    void* m_currentDL;          // 0x4640
    u8 m_zTestCompare;          // 0x4644
    u8 m_zTestRef;              // 0x4645
    u8 m_zTestEnable;           // 0x4646
    u8 pad4647[0x05];           // 0x4647
    void* m_fesScratch;         // 0x464C
    void* m_prevFB;             // 0x4650

    // Methods
    void ShowPerfGraphs(bool) {}
    static void VIPostRetraceCallback(unsigned long) {}
    static void TextureMatrix(EDLEntry*) {}

    void* GetCurrentTexture(int slot) {
        return m_textures[slot];
    }

    void SetAlpha(float alpha) {
        m_alpha = alpha;
        m_dirty = 1;
    }

    void ProcessFrameEffects(float, float, float, float, EVec3&, EVec3&) {
        // Empty - stack frame alloc/dealloc only
    }

    ENgcRenderStateCache* GetRenderStateCache() {
        return m_rsc;
    }

    void* GetNextExternalFrameBuffer() {
        return m_nextXFB;
    }

    void* GetFrameEffectsScratchMemory() {
        return m_fesScratch;
    }

    // GetExternalFrameBuffer - returns the framebuffer not being rendered to
    // Address: 0x8033CA98, Size: 32
    void* GetExternalFrameBuffer() {
        void* fb0 = m_framebuffer0;
        if (m_nextXFB != fb0) {
            return fb0;
        }
        return m_framebuffer1;
    }

    // GetRenderMode - returns pointer to render mode or NULL
    // Address: 0x8034A51C, Size: 28
    void* GetRenderMode() {
        if (m_nextXFB == NULL) {
            return NULL;
        }
        return (void*)((u8*)this + 0x0364);
    }

    // GetZTestSettings
    // Address: 0x8034A538, Size: 28
    void GetZTestSettings(unsigned char& compare, unsigned char& ref, unsigned char& enable) {
        compare = m_zTestCompare;
        ref = m_zTestRef;
        enable = m_zTestEnable;
    }

    // GetPreviousFrameBuffer
    // Address: 0x80349F4C, Size: 32
    void* GetPreviousFrameBuffer(int* outWidth, int* outHeight) {
        *outWidth = m_renderWidth >> 1;
        *outHeight = m_renderHeight >> 1;
        return m_prevFB;
    }

    // Goto - set DL offset from EDLEntry
    // Address: 0x80343D54, Size: 12
    void Goto(EDLEntry* entry) {
        m_dlOffset = *(u32*)((u8*)entry + 4);
    }

    // End - pop display list stack
    // Address: 0x80343D60, Size: 52
    void End(EDLEntry*) {
        if (m_dlStackPtr != 0) {
            m_dlStackPtr--;
            m_dlOffset = m_dlStack[m_dlStackPtr];
        } else {
            m_overflow = 1;
        }
    }

    // DisplayList - push current offset onto stack, switch to new DL
    // Address: 0x80343D24, Size: 48
    void DisplayList(EDLEntry* entry) {
        m_dlStack[m_dlStackPtr] = m_dlOffset;
        m_dlStackPtr++;
        void* dl = *(void**)((u8*)entry + 4);
        m_currentDL = dl;
        m_dlOffset = *(u32*)((u8*)dl + 0x48);
    }

    // SaveState - delegates to render state cache
    // Address: 0x80343D94, Size: 36
    void SaveState(EDLEntry*) {
        ENgcRenderStateCache_Save(m_rsc);
    }

    // RestoreState - delegates to render state cache
    // Address: 0x80343DB8, Size: 36
    void RestoreState(EDLEntry*) {
        ENgcRenderStateCache_Restore(m_rsc);
    }

    // RestoreViewport - delegates to render state cache
    // Address: 0x8033EDC8, Size: 36
    void RestoreViewport() {
        ENgcRenderStateCache_RestoreViewport(m_rsc);
    }

    // TriStrip - dispatch tri strip rendering from DL entry
    // Address: 0x80342120, Size: 40
    void TriStrip(EDLEntry* entry) {
        u16 count = *(u16*)((u8*)entry + 2);
        void* data = *(void**)((u8*)entry + 4);
        ENgcRenderer_ProcessTriStrip(this, count, data);
    }

    // LineList - dispatch line list rendering from DL entry
    // Address: 0x80343BD4, Size: 40
    void LineList(EDLEntry* entry) {
        u16 count = *(u16*)((u8*)entry + 2);
        void* data = *(void**)((u8*)entry + 4);
        ENgcRenderer_ProcessLineList(this, count, data);
    }

    // ModelMatrices - dispatch model matrices from DL entry
    // Address: 0x80344034, Size: 40
    void ModelMatrices(EDLEntry* entry) {
        u8 count = *(u8*)((u8*)entry + 1);
        void* data = *(void**)((u8*)entry + 4);
        ENgcRenderer_ProcessModelMatrices(this, count, data);
    }

    // Texture - load texture from DL entry and mark dirty
    // Address: 0x80344440, Size: 60
    void Texture(EDLEntry* entry) {
        u8 slot = *(u8*)((u8*)entry + 1);
        void* data = *(void**)((u8*)entry + 4);
        ENgcRenderer_ProcessTexture(this, slot, data);
        m_dirty = 1;
    }

    // EnableRasterModes - OR flags into raster mode
    // Address: 0x80344698, Size: 44
    void EnableRasterModes(EDLEntry* entry) {
        u32 flags = *(u32*)((u8*)entry + 4);
        ENgcRenderStateCache* rsc = m_rsc;
        *(u32*)((u8*)rsc + 0x06EC) |= flags;
        rsc = m_rsc;
        *(u32*)((u8*)rsc + 0x06CC) |= 0x80000040;
    }

    // DisableRasterModes - AND flags out of raster mode
    // Address: 0x803446C4, Size: 44
    void DisableRasterModes(EDLEntry* entry) {
        u32 flags = *(u32*)((u8*)entry + 4);
        ENgcRenderStateCache* rsc = m_rsc;
        *(u32*)((u8*)rsc + 0x06EC) &= flags;
        rsc = m_rsc;
        *(u32*)((u8*)rsc + 0x06CC) |= 0x80000040;
    }

    // SetRasterModes - set raster mode directly
    // Address: 0x803446F0, Size: 36
    void SetRasterModes(EDLEntry* entry) {
        u32 flags = *(u32*)((u8*)entry + 4);
        ENgcRenderStateCache* rsc = m_rsc;
        *(u32*)((u8*)rsc + 0x06EC) = flags;
        rsc = m_rsc;
        *(u32*)((u8*)rsc + 0x06CC) |= 0x80000040;
    }

    // SetCombineMode - set TEV combine mode for a stage
    // Address: 0x80346104, Size: 32
    void SetCombineMode(EDLEntry* entry) {
        u16 stage = *(u16*)((u8*)entry + 2);
        u32 mode = *(u32*)((u8*)entry + 4);
        *((u8*)this + 0x0569 + stage * 64) = (u8)mode;
        m_dirty = 1;
    }

    // SetBlendMode - unpack blend mode from entry
    // Address: 0x80346124, Size: 56
    void SetBlendMode(EDLEntry* entry) {
        u32 packed = *(u32*)((u8*)entry + 4);
        m_dirty = 1;
        m_blendDst = (packed >> 2) & 0x3;
        m_blendSrc = packed & 0x3;
        m_blendOp = (packed >> 4) & 0x3;
        m_blendLogic = (packed >> 6) & 0x3;
        m_blendAlpha = (packed >> 24) & 0xFF;
    }

    // ClipRect - advance DL offset, check flag
    // Address: 0x80343E7C, Size: 36
    // NON_MATCHING - uses sdata globals
    void ClipRect(EDLEntry* entry);

    // NgcTexInvalidateAll - invalidate all textures
    // Address: 0x803477AC, Size: 32
    void NgcTexInvalidateAll(EDLEntry*) {
        GXInvalidateTexAll();
    }

    // ReadMetrics - read perf metrics and set flag
    // Address: 0x803489A8, Size: 40
    // NON_MATCHING - needs sdata globals
    void ReadMetrics(EDLEntry*);

    // Shader - dispatch shader from DL entry
    // Address: 0x803489D0, Size: 40
    void Shader(EDLEntry* entry) {
        void* shader = *(void**)((u8*)entry + 4);
        ENgcRenderer_ProcessShader(this, shader, -1);
    }

    // MipMapSetup - check and clear sdata flag
    // Address: 0x803451A4, Size: 24
    // NON_MATCHING - uses sdata globals
    void MipMapSetup(EDLEntry*);

    // TriIndexed - check and clear sdata flag
    // Address: 0x8034548C, Size: 24
    // NON_MATCHING - uses sdata globals
    void TriIndexed(EDLEntry*);

    // SaveImageData - check and clear sdata flag
    // Address: 0x803454A4, Size: 24
    // NON_MATCHING - uses sdata globals
    void SaveImageData(EDLEntry*);

    // Debug - debug marker from DL entry
    // Address: 0x803451BC, Size: 40
    // NON_MATCHING - uses sdata globals
    void Debug(EDLEntry*);

    // GeometrySetup - restore viewport, process setup, clear dirty
    // Address: 0x803451E4, Size: 60
    void GeometrySetup(EDLEntry*) {
        RestoreViewport();
        ENgcRenderer_ProcessSetup(this);
        m_dirty = 0;
    }

    // SpriteListPacked - unpack entry and dispatch
    // Address: 0x803454BC, Size: 60
    void SpriteListPacked(EDLEntry* entry) {
        void* p1 = *(void**)((u8*)entry + 4);
        void* p2 = *(void**)((u8*)entry + 8);
        void* p3 = *(void**)((u8*)entry + 12);
        void* p4 = *(void**)((u8*)entry + 16);
        void* p5 = *(void**)((u8*)entry + 20);
        void* p6 = *(void**)((u8*)entry + 24);
        ENgcRenderer_ProcessSpriteListPacked(this, p1, p2, p3, p4, p5, p6);
    }

    // QueueBeginFrame - queue a begin frame command
    // Address: 0x8033E7F4, Size: 48
    void QueueBeginFrame(int param) {
        ENgcRendCommandData cmd;
        cmd.type = 1;
        cmd.param1 = param;
        ENgcRenderer_QueueCommand(this, &cmd);
    }

    // QueueDisplayList - queue a display list command
    // Address: 0x8033E824, Size: 52
    void QueueDisplayList(EDL* dl, bool flag) {
        ENgcRendCommandData cmd;
        cmd.type = 2;
        cmd.param1 = (u32)dl;
        cmd.param2 = (u32)flag;
        ENgcRenderer_QueueCommandDL(this, &cmd);
    }

    // QueueEndFrame - queue an end frame command
    // Address: 0x8033E858, Size: 48
    void QueueEndFrame(EEvent& event) {
        ENgcRendCommandData cmd;
        cmd.type = 3;
        cmd.param1 = (u32)&event;
        ENgcRenderer_QueueCommandEndFrame(this, &cmd);
    }

    // QueueSwap - queue a swap command
    // Address: 0x8033E888, Size: 52
    void QueueSwap(int a, int b) {
        ENgcRendCommandData cmd;
        cmd.type = 4;
        cmd.param1 = a;
        cmd.param2 = b;
        ENgcRenderer_QueueCommandSwap(this, &cmd);
    }

    // Flush (no args) - queue a flush command
    // Address: 0x8033E8BC, Size: 44
    void Flush() {
        ENgcRendCommandData cmd;
        cmd.type = 5;
        Flush((ENgcRendCommand*)&cmd);
    }

    // Flush (command) - execute command
    // Address: 0x8033ECB8, Size: 32
    void Flush(ENgcRendCommand* cmd) {
        ENgcRendCommand_Execute(cmd);
    }

    // ~ENgcRenderer
    // Address: 0x8033B6EC, Size: 52
    // NON_MATCHING - vtable and destructor chain
    ~ENgcRenderer();

    // Init
    // Address: 0x8033B734, Size: 48
    // NON_MATCHING - calls initialization chain
    bool Init(int& width, int& height);

    // BreakPtCallback
    // Address: 0x8033CDF0, Size: 48
    // NON_MATCHING - uses sdata globals
    static void BreakPtCallback();

    // DrawSyncCallback
    // Address: 0x8033CE20, Size: 8
    // NON_MATCHING - uses sdata globals
    static void DrawSyncCallback(unsigned short token);

    // AddDrawSync
    // Address: 0x8033CE28, Size: 52
    // NON_MATCHING - uses sdata globals
    void AddDrawSync();

    // AcquireCopyMutex
    // Address: 0x8034A554, Size: 64
    // NON_MATCHING - virtual dispatch through mutex vtable
    void AcquireCopyMutex();

    // ReleaseCopyMutex
    // Address: 0x8034A594, Size: 60
    // NON_MATCHING - virtual dispatch through mutex vtable
    void ReleaseCopyMutex();
};
