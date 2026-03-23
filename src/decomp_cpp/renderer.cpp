// renderer.cpp - Real C++ decompilation of ENgcRenderer, ERShader, ETexture, ERModel
// Part of the Sims 2 GC decompilation — PC port variant
//
// Converted from inline asm (src/render/) and decomp docs
// (engcrenderer_decomp.cpp, resources_decomp.cpp) into functionally
// correct C++ using struct field names from include/classes/ headers.
//
// This is NOT byte-matching code. It is a clean C++ translation for a
// future PC port, preserving the original logic and data flow.

#include "types.h"

// Use 0 for null pointers (C++03 compatibility with project codebase)
#ifndef nullptr
#define nullptr 0
#endif

// ============================================================================
// Forward Declarations & Minimal Type Stubs
// ============================================================================

class EResource;
class EResourceManager;
class EShader;
class EShaderDef;
class ETexture;
class ETextureDef;
class ENgcTexture;
class ENgcTextureBase;
class ENgcShader;
class ERShader;
class ERTexture;
class ERModel;
class ERFont;
class ESubModelShader;
class ERC;
class EDL;
class EDLEntry;
class EFile;
class EStream;
class EFontData;
class ENgcRenderStateCache;
class ENgcRendCommand;
class EResourceFile;
class EMaterial;

struct EVec2 { f32 x, y; };
struct EVec3 { f32 x, y, z; };
struct EVec4 { f32 x, y, z, w; };
struct EMat4 { f32 m[4][4]; };
struct EBound3 { EVec3 min, max; };
struct EBoundSphere { EVec3 center; f32 radius; };
struct EACNodeState;

struct _GXRenderModeObj {
    u32 viTVMode;
    u16 fbWidth;
    u16 efbHeight;
    u16 xfbHeight;
    u16 viXOrigin;
    u16 viYOrigin;
    u16 viWidth;
    u16 viHeight;
    u32 xfbMode;
    u8  field_rendering;
    u8  aa;
    u8  sample_pattern[12][2];
    u8  vfilter[7];
};

struct ENgcRendCommandData {
    u32 type;
    u32 param1;
    u32 param2;
};

// Jump table entry for command dispatch
struct JumpTableEntry {
    s16 offsetFlag;
    s16 paramOffset;
    void (*handler)(void*, EDLEntry*);
};

// ============================================================================
// External Function Declarations
// ============================================================================

extern void* EAHeap_GetCurrentHeap();
extern void* EAHeap_Alloc(void* heap, u32 size, int flags);
extern void* EAHeap_AllocAlign(void* heap, u32 size, u32 align, int a, int b);
extern void  EAHeap_Free(void* heap, void* ptr);
extern void  EAHeap_CollectGarbage();

extern void ENgcRenderStateCache_Init(ENgcRenderStateCache* rsc);
extern void ENgcRenderStateCache_Save(ENgcRenderStateCache* rsc);
extern void ENgcRenderStateCache_Restore(ENgcRenderStateCache* rsc);

extern void* memcpy(void* dst, const void* src, u32 size);
extern void* memset(void* dst, int val, u32 size);

// Global pointers
extern void* _pRend;                   // Global renderer pointer (r13-relative)
extern u32   g_videoMode;              // 1 = progressive/480p
extern u32   g_targetFrameRate;
extern u32   g_renderActive;
extern u32   g_frameCounter;
extern u32   g_polyCount;
extern u32   g_drawCallCount;
extern u32   g_batchCount;
extern u32   g_prevPolyCount;
extern f32   g_frameTimeAccum;
extern f32   g_frameTimePrev;
extern f32   g_prevFrameTime;
extern f32   g_prevFrameTimePrev;
extern u32   g_prevDrawCallCount;
extern u32   g_viewportChanged;
extern u32   g_windowMatrixChanged;

// Vtable pointers (link-time resolved)
extern void* EResource_vtable;
extern void* EStorable_vtable;
extern void* ERShader_vtable;
extern void* ERTexture_vtable;
extern void* ENgcRenderer_vtable;

// GX compare function lookup table (8 entries: NEVER..ALWAYS)
extern u32 g_compareTable[8];

// Global projection matrix buffer
extern f32 g_projectionMatrix[16];


// ============================================================================
//  SECTION 1: EResource — Base Resource Class
// ============================================================================
//
// EResource is the reference-counted base for all game assets.
// Size: ~0x14 (20 bytes)
//   0x00: vtable
//   0x04: m_pManager (EResourceManager*)
//   0x08: m_resId (u32)
//   0x0C: m_refCount (s16)
//   0x0E: m_flags (u16)
//   0x10: m_resSize (u32)

struct EResourceFields {
    void**             _vtable;     // 0x00
    EResourceManager*  m_pManager;  // 0x04
    u32                m_resId;     // 0x08
    s16                m_refCount;  // 0x0C
    u16                m_flags;     // 0x0E
    u32                m_resSize;   // 0x10
};

// ---------- EResource::EResource ----------
// Address: 0x80311DC8, Size: 48 bytes
void EResource_Ctor(EResourceFields* self) {
    self->_vtable    = (void**)&EResource_vtable;
    self->m_pManager = nullptr;
    self->m_refCount = 1;
    self->m_flags    = 0;
    self->m_resSize  = 128;  // default size
}

// ---------- EResource::~EResource ----------
// Address: 0x80311DF8, Size: 108 bytes
void EResource_Dtor(EResourceFields* self, int hiddenParam) {
    // Restore base vtable
    self->_vtable = (void**)&EResource_vtable;

    // If managed, notify manager
    if (self->m_pManager != nullptr) {
        // self->m_pManager->ResourceDestructing(self);
        // (virtual call omitted — delegated to manager)
    }

    // Set vtable to parent EStorable
    self->_vtable = (void**)&EStorable_vtable;

    // If scalar-delete bit set, free memory
    if (hiddenParam & 0x01) {
        void* heap = EAHeap_GetCurrentHeap();
        EAHeap_Free(heap, self);
    }
}

// ---------- EResource::AddRef ----------
// Address: 0x80312000, Size: 64 bytes
void EResource_AddRef(EResourceFields* self) {
    if (self->m_pManager != nullptr) {
        // Managed: delegate to manager
        // self->m_pManager->AddRef(self);
    } else {
        // Unmanaged: local increment
        self->m_refCount++;
    }
}

// ---------- EResource::DelRef ----------
// Address: 0x80311F70, Size: 104 bytes
void EResource_DelRef(EResourceFields* self) {
    if (self->m_pManager != nullptr) {
        // Managed: delegate to manager (mode=NORMAL=1)
        // self->m_pManager->DelRef(self, 1);
    } else {
        // Unmanaged: local decrement
        self->m_refCount--;
        if (self->m_refCount == 0) {
            // Virtual SafeDelete dispatch through vtable
            // vtable offset 0x08: this-adjust, 0x0C: function pointer
            void** vtbl = self->_vtable;
            s16 adj = *(s16*)((u8*)vtbl + 0x08);
            void (*fn)(void*) = (void(*)(void*))*(u32*)((u8*)vtbl + 0x0C);
            fn((u8*)self + adj);
        }
    }
}

// ---------- EResource::Detach ----------
// Address: 0x80311FD8, Size: 40 bytes
void EResource_Detach(EResourceFields* self) {
    // Delegate to manager
    // self->m_pManager->Detach(self);
}

// ---------- EResource::Refresh ----------
// Address: 0x80312040, Size: 48 bytes
void EResource_Refresh(EResourceFields* self) {
    if (self->m_pManager != nullptr) {
        // self->m_pManager->Refresh(self);
    }
}

// ---------- EResource::IsSafeToDelete ----------
// Address: 0x8031226C, Size: 8 bytes
bool EResource_IsSafeToDelete(EResourceFields* /*self*/) {
    return true;
}

// ---------- EResource::Init ----------
// Address: 0x80312338, Size: 4 bytes
void EResource_Init(EResourceFields* /*self*/) {
    // Intentionally empty
}


// ============================================================================
//  SECTION 2: ERShader — Shader Resource
// ============================================================================
//
// ERShader wraps EShader(s) and manages day/night blending,
// multi-shader states, and texture swapping.
// Size: 0x17BC (6,076 bytes)

// Key fields from the header and decomp docs:
//   0x00: inherited EResource fields (but note: the auto-extracted header
//         has floating point at 0x00 due to union/overlap; the decomp doc
//         clarifies the true resource-base lives at the EResource layer.)
//   0x014: m_pCurrentEShader (EShader*)
//   0x018: m_pCurrentERShader (ERShader* — child for multi-shader)
//   0x01C: m_pIncomingShader (EShader*)
//   0x02C: m_blendFactor (f32)
//   0x030: m_pBlendEShader (EShader*)
//   0x034: m_pTextureResource (ERTexture*)
//   0x038: m_textureResId (u32)
//   0x03C: m_timeOfDay (f32)
//   0x040: m_weatherFactor (f32)
//   0x044: m_numStates (u8)
//   0x048: m_pStateArray (ERShader**)
//   0x04C: m_pMultiShaderInfo (MultiShaderInfo*)
//   0x050: m_currentStateIndex (u8)
//   0x054: m_pUpdateListNext (ERShader*)
//   0x058: m_flags (s16/u32 — see bit definitions)
//   0x05C: m_pendingShader (u32)
//   0x060: m_blendProgress (f32)
//   0x064: m_currentShaderIdx (u8)
//   0x065: m_targetShaderIdx (u8)
//   0x066: m_updateFlags (u8)
//   0x067: m_weatherState (u8)
//   0x068: m_shaderData (u32)
//   0x0F0: m_pEShaderDef (EShaderDef*)

// Helper: access ERShader fields by offset (mirrors assembly access patterns)
static inline u32& ERShader_u32(void* self, u32 off) { return *(u32*)((u8*)self + off); }
static inline f32& ERShader_f32(void* self, u32 off) { return *(f32*)((u8*)self + off); }
static inline u8&  ERShader_u8(void* self, u32 off)  { return *(u8*)((u8*)self + off); }

// ---------- ERShader::ERShader ----------
// Address: 0x8031C6DC, Size: 196 bytes
void ERShader_Ctor(void* self) {
    // Call base EResource constructor
    EResource_Ctor((EResourceFields*)self);

    // Set ERShader vtable
    *(void**)self = (void*)&ERShader_vtable;

    // Zero all shader-specific fields
    ERShader_u32(self, 0x014) = 0;  // m_pCurrentEShader
    ERShader_u32(self, 0x018) = 0;  // m_pCurrentERShader
    ERShader_u32(self, 0x01C) = 0;  // m_pIncomingShader
    ERShader_u32(self, 0x030) = 0;  // m_pBlendEShader
    ERShader_u32(self, 0x034) = 0;  // m_pTextureResource
    ERShader_u32(self, 0x038) = 0;  // m_textureResId

    // Set timeOfDay to -1.0f (no time selected yet)
    ERShader_f32(self, 0x03C) = -1.0f;

    // Zero multi-shader info
    ERShader_u32(self, 0x04C) = 0;  // m_pMultiShaderInfo
    ERShader_f32(self, 0x040) = 0.0f;  // m_weatherFactor
    ERShader_u8(self, 0x050)  = 0;  // m_currentStateIndex
    ERShader_u32(self, 0x054) = 0;  // m_pUpdateListNext
    ERShader_u32(self, 0x058) = 0;  // m_flags
    ERShader_u32(self, 0x05C) = 0;  // m_pendingShader
    ERShader_f32(self, 0x060) = 0.0f;  // m_blendProgress
    ERShader_u8(self, 0x064)  = 0;  // m_currentShaderIdx
    ERShader_u8(self, 0x065)  = 0;  // m_targetShaderIdx
    ERShader_u8(self, 0x066)  = 0;  // m_updateFlags
    ERShader_u8(self, 0x067)  = 0;  // m_weatherState
    ERShader_u32(self, 0x068) = 0;  // m_shaderData
}

// ---------- ERShader::IsDayNightShader ----------
// Address: 0x80320750, Size: 12 bytes
bool ERShader_IsDayNightShader(void* self) {
    u32 flags = ERShader_u32(self, 0x058);
    return (flags >> 5) & 1;
}

// ---------- ERShader::IsMultiShader ----------
// Address: 0x80320860, Size: 12 bytes
bool ERShader_IsMultiShader(void* self) {
    u32 flags = ERShader_u32(self, 0x058);
    return (flags >> 1) & 1;
}

// ---------- ERShader::IsMultiTextureShader ----------
// Address: 0x8032086C, Size: 72 bytes
bool ERShader_IsMultiTextureShader(void* self) {
    u32 flags = ERShader_u32(self, 0x058);

    // Multi-shader (bit 1) is NOT multi-texture
    if (flags & 0x02) {
        return false;
    }

    // Resolve current EShader
    void* shader = (void*)(u32)ERShader_u32(self, 0x014);
    if (shader == nullptr) {
        void* child = (void*)(u32)ERShader_u32(self, 0x018);
        if (child != nullptr) {
            shader = (void*)(u32)ERShader_u32(child, 0x014);
        } else {
            return false;
        }
    }

    // Check EShader multi-texture flag: bit 6 of flags at EShader+0x04
    u32 shaderFlags = *(u32*)((u8*)shader + 0x04);
    return (shaderFlags >> 6) & 1;
}

// ---------- ERShader::GetCurrentShader ----------
// Address: 0x8032076C, Size: 60 bytes
void* ERShader_GetCurrentShader(void* self) {
    if (ERShader_IsMultiShader(self)) {
        return (void*)(u32)ERShader_u32(self, 0x018);
    }
    return nullptr;
}

// ---------- ERShader::Select ----------
// Address: 0x80320904, Size: 96 bytes
void ERShader_Select(void* self, ERC* rc, u32 flags) {
    // Resolve current EShader
    void* shader = nullptr;

    u32 currentEShader = ERShader_u32(self, 0x014);
    if (currentEShader != 0) {
        shader = (void*)currentEShader;
    } else {
        u32 currentERShader = ERShader_u32(self, 0x018);
        if (currentERShader != 0) {
            shader = (void*)ERShader_u32((void*)currentERShader, 0x014);
        }
    }

    if (shader == nullptr) return;

    // Virtual call: EShader::Select(rc, flags)
    // EShader has its platform shader at offset 0xF0 which has a vtable
    void* platformShader = (void*)*(u32*)((u8*)shader + 0xF0);
    if (platformShader != nullptr) {
        void** vtbl = *(void***)platformShader;
        // vtable+0x10: this-adjust, vtable+0x14: function pointer
        s16 adj = *(s16*)((u8*)vtbl + 0x10);
        void (*fn)(void*, ERC*, u32) = (void(*)(void*, ERC*, u32))*(u32*)((u8*)vtbl + 0x14);
        fn((u8*)platformShader + adj, rc, flags);
    }
}


// ============================================================================
//  SECTION 3: ENgcShader — GX Hardware Shader
// ============================================================================
//
// ENgcShader directly configures the GX TEV pipeline.
// Size: 0xF4 (244 bytes)
//   0x00: m_numTEVStages (u8)
//   0x04: m_texGenCount (u32)
//   0x08: m_gxFlags (u32)
//   0x0C: m_blendSrc (u32)
//   0x10: m_blendDst (u32)
//   0x14: m_alphaCompare (u32)
//   0x64..0x9F: TEV stage 0 params (60 bytes)
//   0x70: m_gxFlags2 (u32)
//   0x80..0x83: TEV stage 0 color inputs (4 x u8)
//   0xA4..0xDF: TEV stage 1 params (60 bytes)
//   0xC0..0xC3: TEV stage 1 color inputs (4 x u8)
//   0xF0: m_pPlatformData (u32)

// ---------- ENgcShader::Create ----------
// Address: 0x8034DE0C, Size: 372 bytes
bool ENgcShader_Create(void* self, void* shaderDef) {
    // Validate the shader definition
    // (delegated — assume valid for PC port)

    // Clear bit 5 of GX flags
    u32 gxFlags = *(u32*)((u8*)self + 0x08);
    gxFlags &= ~0x20u;
    *(u32*)((u8*)self + 0x08) = gxFlags;

    u8 numStages = *(u8*)self;
    if (numStages != 2) {
        return true;
    }

    // Pack TEV color inputs for stage 0
    u8 c0_0 = *((u8*)self + 0x80);
    u8 c0_1 = *((u8*)self + 0x81);
    u8 c0_2 = *((u8*)self + 0x82);
    u8 c0_3 = *((u8*)self + 0x83);
    u32 packedColor0 = c0_0 | (c0_1 << 2) | (c0_2 << 4) | (c0_3 << 6);

    // Pack TEV color inputs for stage 1
    u8 c1_0 = *((u8*)self + 0xC0);
    u8 c1_1 = *((u8*)self + 0xC1);
    u8 c1_2 = *((u8*)self + 0xC2);
    u8 c1_3 = *((u8*)self + 0xC3);
    u32 packedColor1 = c1_0 | (c1_1 << 2) | (c1_2 << 4) | (c1_3 << 6);

    // Check if secondary TEV stage is enabled (bit 6 of m_gxFlags2)
    u32 gxFlags2 = *(u32*)((u8*)self + 0x70);
    if (!(gxFlags2 & 0x40)) {
        packedColor0 = 0;
    }

    // Validate known TEV configurations
    bool validColor = (packedColor0 == 0x4A || packedColor0 == 0x5A || packedColor0 == 0x6A);
    bool validAlpha = (packedColor1 == 0x44 || packedColor1 == 0x48 ||
                       packedColor1 == 0x64 || packedColor1 == 0x68);

    if (validColor && validAlpha) {
        // Promote to 1-stage: copy TEV1 config to TEV0 slot
        *(u8*)self = 1;  // m_numTEVStages = 1
        u32* dst = (u32*)((u8*)self + 0x64);
        u32* src = (u32*)((u8*)self + 0xA4);
        for (int i = 0; i < 15; i++) {
            dst[i] = src[i];
        }
    }

    return true;
}

// ---------- ENgcShader::Select ----------
// Address: 0x8034DC98, Size: 164 bytes
void ENgcShader_Select(void* self, ERC* rc, u32 flags) {
    u8 numStages = *(u8*)self;  // m_numTEVStages

    for (int i = 0; i < (int)numStages; i++) {
        // Get ERC's extended vtable
        void** rcVtbl = *(void***)((u8*)rc + 0x70);  // m_pVtableExt at offset 112
        s16 adj = *(s16*)((u8*)rcVtbl + 0x120);
        void (*fn)(void*, void*, int) =
            (void(*)(void*, void*, int))*(u32*)((u8*)rcVtbl + 0x124);

        // Calculate TEV stage parameters base for this stage
        // Each stage config is at self + 0x64 + i * 0x40 (estimated)
        void* stageParams = (void*)((u8*)self + 0x64 + i * 0x40);

        fn((u8*)rc + adj, stageParams, i);
    }

    // Commit overall shader state
    void** rcVtbl = *(void***)((u8*)rc + 0x70);
    s16 adj = *(s16*)((u8*)rcVtbl + 0x338);
    void (*commitFn)(void*, void*, u32) =
        (void(*)(void*, void*, u32))*(u32*)((u8*)rcVtbl + 0x33C);
    commitFn((u8*)rc + adj, self, flags);
}

// ---------- ENgcShader::SelectForShadowMask ----------
// Address: 0x8034DD3C, Size: 208 bytes
void ENgcShader_SelectForShadowMask(void* self, ERC* rc) {
    void** rcVtbl = *(void***)((u8*)rc + 0x70);

    // 1. Disable texture on TEV stage 0
    {
        s16 adj = *(s16*)((u8*)rcVtbl + 0x120);
        void (*fn)(void*, int, int) =
            (void(*)(void*, int, int))*(u32*)((u8*)rcVtbl + 0x124);
        fn((u8*)rc + adj, 0, 0);
    }

    // 2. Commit shader state
    {
        s16 adj = *(s16*)((u8*)rcVtbl + 0x338);
        void (*fn)(void*, void*, u32) =
            (void(*)(void*, void*, u32))*(u32*)((u8*)rcVtbl + 0x33C);
        fn((u8*)rc + adj, self, 0);
    }

    // 3. Set alpha blend mode (additive: 0x4000)
    {
        s16 adj = *(s16*)((u8*)rcVtbl + 0x128);
        void (*fn)(void*, int) =
            (void(*)(void*, int))*(u32*)((u8*)rcVtbl + 0x12C);
        fn((u8*)rc + adj, 0x4000);
    }

    // 4. Set cull mode for shadows (double-sided: 64)
    {
        s16 adj = *(s16*)((u8*)rcVtbl + 0x140);
        void (*fn)(void*, int, int) =
            (void(*)(void*, int, int))*(u32*)((u8*)rcVtbl + 0x144);
        fn((u8*)rc + adj, 64, 0);
    }

    // 5. Configure shadow TEV: zero color, vertex alpha
    {
        s16 adj = *(s16*)((u8*)rcVtbl + 0x1C8);
        void (*fn)(void*, int, int, int, int) =
            (void(*)(void*, int, int, int, int))*(u32*)((u8*)rcVtbl + 0x1CC);
        fn((u8*)rc + adj, 0, 2, 0, 0);
    }
}


// ============================================================================
//  SECTION 4: EShader — Platform-Agnostic Material
// ============================================================================
//
// EShader (2,268 bytes) holds material colors, textures, surface properties.
// Key fields from e_shader.cpp and header:
//   0x04: m_flags (u32 — surface property bitfield)
//   0x10..0x18: material coefficients
//   0x40..0x63: modifiable colors (indexed by u32)
//   0x64: texture slot 0 (ETexture*)
//   0x68: multi-texture array pointer
//   0x74: geometry flags
//   0x88: texture count (u8)
//   0xB4: shader data flags
//   0xEC: override texture index (u8)
//   0xF0: platform shader (ENgcShader*)

// ---------- EShader::UseOverrideTexture ----------
// Address: 0x802FA438, Size: 60 bytes
bool EShader_UseOverrideTexture(void* self, u8 index) {
    u32 flags = *(u32*)((u8*)self + 0x04);
    if (!(flags & 0x04000000)) {
        return false;
    }
    u8 texCount = *((u8*)self + 0x88);
    if (index >= texCount) {
        return false;
    }
    flags |= 0x02000000;
    *((u8*)self + 0xEC) = index;
    *(u32*)((u8*)self + 0x04) = flags;
    return true;
}

// ---------- EShader::UndoOverrideTexture ----------
// Address: 0x802FAB38, Size: 16 bytes
void EShader_UndoOverrideTexture(void* self) {
    u32 flags = *(u32*)((u8*)self + 0x04);
    flags &= ~0x02000000u;
    *(u32*)((u8*)self + 0x04) = flags;
}

// ---------- EShader::SetSurfaceProperty ----------
// Address: 0x802FAAB4, Size: 16 bytes
void EShader_SetSurfaceProperty(void* self, u32 prop) {
    u32 flags = *(u32*)((u8*)self + 0x04);
    flags |= prop;
    *(u32*)((u8*)self + 0x04) = flags;
}

// ---------- EShader::ClearSurfaceProperty ----------
// Address: 0x802FAAC4, Size: 16 bytes
void EShader_ClearSurfaceProperty(void* self, u32 prop) {
    u32 flags = *(u32*)((u8*)self + 0x04);
    flags &= ~prop;
    *(u32*)((u8*)self + 0x04) = flags;
}

// ---------- EShader::IsSurface ----------
// Address: 0x802FAAD4, Size: 24 bytes
bool EShader_IsSurface(void* self, u32 prop) {
    u32 flags = *(u32*)((u8*)self + 0x04);
    return (flags & prop) != 0;
}

// ---------- EShader::GetSurfaceProperties ----------
// Address: 0x802FAAEC, Size: 8 bytes
u32 EShader_GetSurfaceProperties(void* self) {
    return *(u32*)((u8*)self + 0x04);
}

// ---------- EShader::CanColorBeModified ----------
// Address: 0x802FAAF4, Size: 20 bytes
bool EShader_CanColorBeModified(void* self) {
    u32 shaderData = *(u32*)((u8*)self + 0xB4);
    u32 geomFlags = *(u32*)((u8*)self + 0x74);
    return ((geomFlags | shaderData) >> 27) & 1;
}

// ---------- EShader::GetMaterial ----------
// Address: 0x802FAAAC, Size: 8 bytes
void* EShader_GetMaterial(void* self) {
    return (void*)((u8*)self + 0x10);
}

// ---------- EShader::GetModifiableColor ----------
// Address: 0x802FAB08, Size: 16 bytes
void* EShader_GetModifiableColor(void* self, u32 index) {
    return (void*)*(u32*)((u8*)self + 0x40 + index * 4);
}

// ---------- EShader::SetTexture ----------
// Address: 0x802FAB18, Size: 16 bytes
void EShader_SetTexture(void* self, void* tex, int slot) {
    u32 offset = (u32)slot * 64;
    *(void**)((u8*)self + 0x64 + offset) = tex;
}

// ---------- EShader::SetMultiTexture ----------
// Address: 0x802FAB28, Size: 16 bytes
void EShader_SetMultiTexture(void* self, void* tex, int slot) {
    u32* texArray = *(u32**)((u8*)self + 0x68);
    texArray[slot] = (u32)tex;
}

// ---------- EShader::Select (base) ----------
// Address: 0x802FAAA8, Size: 4 bytes
void EShader_Select(void* /*self*/, ERC* /*rc*/, u32 /*flags*/) {
    // Empty stub — derived classes override
}

// ---------- EShader::SetShadowAlpha ----------
// Address: 0x802FA9E4, Size: 4 bytes
void EShader_SetShadowAlpha(void* /*self*/, f32 /*alpha*/) {
    // Empty stub
}

// ---------- EShader::SelectForShadowMask ----------
// Address: 0x802FA9AC, Size: 56 bytes
void EShader_SelectForShadowMask(void* self, ERC* rc) {
    // Dispatch through platform shader at offset 0xF0
    void* platformShader = (void*)*(u32*)((u8*)self + 0xF0);
    if (platformShader == nullptr) return;

    void** vtbl = *(void***)platformShader;
    s16 adj = *(s16*)((u8*)vtbl + 0x10);
    void (*fn)(void*, ERC*, int) = (void(*)(void*, ERC*, int))*(u32*)((u8*)vtbl + 0x14);
    fn((u8*)platformShader + adj, rc, 0);
}


// ============================================================================
//  SECTION 5: ERTexture — Texture Resource
// ============================================================================
//
// ERTexture (40 bytes) wraps an ETexture with resource management.
//   0x00: vtable
//   0x04..0x0F: EResource base fields
//   0x10: m_flags (u32 — upper 24 bits = image size)
//   0x14: m_pTexture (ETexture*)
//   0x24: m_formatInfo (u32)

// Forward declarations within ERTexture section
static void ERTexture_Deallocate(void* self);

// ---------- ERTexture::Attach ----------
// Address: 0x80320BCC, Size: 52 bytes
void ERTexture_Attach(void* self, void* tex) {
    // Deallocate old texture first
    ERTexture_Deallocate(self);
    *(u32*)((u8*)self + 0x14) = (u32)tex;
}

// ---------- ERTexture::Deallocate ----------
// Address: 0x80320C00, Size: 80 bytes
static void ERTexture_Deallocate(void* self) {
    // Get global texture manager (r13-relative, simplified here)
    // void* texMgr = g_pTextureManager;
    void* tex = (void*)*(u32*)((u8*)self + 0x14);
    if (tex != nullptr) {
        // texMgr->Release(tex) — virtual call
        // For PC port: just delete the texture object
    }
    *(u32*)((u8*)self + 0x14) = 0;
}

// ---------- ERTexture::Load ----------
// Address: 0x80320D00, Size: 240 bytes
void ERTexture_Load(void* self, void* file) {
    // 1. Open resource file looking for 'TXFL' signature, version 9
    u32 signature = 0x5458464C;  // 'TXFL'
    // EResourceFile resFile;
    // resFile.Open(file, signature, 9, 9);

    // 2. Read image data size, pack into flags upper 24 bits
    // u32 imageSize = resFile.GetDataSize();
    // u32 flags = *(u32*)((u8*)self + 0x10);
    // flags = (imageSize << 8) | (flags & 0xFF);
    // *(u32*)((u8*)self + 0x10) = flags;

    // 3. Allocate memory for image data
    // u8* buffer = EAHeap_Alloc(heap, imageSize, 0);

    // 4. Read raw texture data
    // file->Read(buffer, imageSize);

    // 5. Decode texture from memory
    // ERTexture_LoadFromMemory(self, buffer);

    // 6. Free temporary buffer
    // EAHeap_Free(heap, buffer);

    (void)signature;  // suppress unused warning in stub
}

// ---------- ERTexture::IsSafeToDelete ----------
// Address: 0x803210F4, Size: 140 bytes
bool ERTexture_IsSafeToDelete(void* self) {
    void* myTex = (void*)*(u32*)((u8*)self + 0x14);
    if (myTex == nullptr) return true;

    // Check if any texture slot in the global renderer has this texture bound
    if (_pRend == nullptr) return true;

    // Iterate over 2 texture slots
    for (int slot = 0; slot <= 1; slot++) {
        // Get texture bound in this slot from the renderer
        void* boundTex = (void*)*(u32*)((u8*)_pRend + 0x4638 + slot * 4);
        if (boundTex == myTex) {
            return false;  // Still in use by the GPU
        }
    }

    return true;
}


// ============================================================================
//  SECTION 6: ETexture — Platform-Agnostic Texture
// ============================================================================
//
// ETexture (40 bytes) holds dimensions, format, palette info.
//   0x00: vtable
//   0x04..0x14: format data set by Create()
//   0x20: data ptr 1 (freed in dtor)
//   0x24: data ptr 2 (freed in dtor)

// ---------- ETexture::Select ----------
// Address: 0x807EAA10, Size: 36 bytes
void ETexture_Select(void* self, int texMapId) {
    // Delegate to platform texture (ENgcTexture)
    void* gxTex = (void*)*(u32*)((u8*)self + 0x20);
    if (gxTex == nullptr) return;

    // Virtual call to platform Select
    void** vtbl = *(void***)gxTex;
    // ...platform dispatch
    (void)texMapId;
}


// ============================================================================
//  SECTION 7: ENgcTexture — GX Hardware Texture
// ============================================================================
//
// ENgcTexture (44 bytes) manages GX texture objects.
//   0x08: m_swizzleFlag
//   0x14: m_width (u16)
//   0x1B: m_bpp
//   0x24: internal alloc ptr
//   0x28: GX texture object ptr

// ---------- ENgcTexture::Select ----------
// Address: 0x8034FA38, Size: 56 bytes
void ENgcTexture_Select(void* self, int texMapId, int texCoordId) {
    void* gxTex = (void*)*(u32*)((u8*)self + 0x28);
    if (gxTex == nullptr) return;

    void** vtbl = *(void***)((u8*)gxTex + 0x24);
    s16 adj = *(s16*)((u8*)vtbl + 0xA0);
    void (*fn)(void*, int, int) =
        (void(*)(void*, int, int))*(u32*)((u8*)vtbl + 0xA4);
    fn((u8*)gxTex + adj, texMapId, texCoordId);
}

// ---------- ENgcTexture::GetTEVStageCount ----------
// Address: 0x8034FAA0, Size: 56 bytes
int ENgcTexture_GetTEVStageCount(void* self) {
    void* gxTex = (void*)*(u32*)((u8*)self + 0x28);
    if (gxTex == nullptr) return 0;

    void** vtbl = *(void***)((u8*)gxTex + 0x24);
    s16 adj = *(s16*)((u8*)vtbl + 0x90);
    int (*fn)(void*) = (int(*)(void*))*(u32*)((u8*)vtbl + 0x94);
    return fn((u8*)gxTex + adj);
}

// ---------- ENgcTexture::GetTEXCount ----------
// Address: 0x8034FAD8, Size: 56 bytes
int ENgcTexture_GetTEXCount(void* self) {
    void* gxTex = (void*)*(u32*)((u8*)self + 0x28);
    if (gxTex == nullptr) return 0;

    void** vtbl = *(void***)((u8*)gxTex + 0x24);
    s16 adj = *(s16*)((u8*)vtbl + 0x98);
    int (*fn)(void*) = (int(*)(void*))*(u32*)((u8*)vtbl + 0x9C);
    return fn((u8*)gxTex + adj);
}


// ============================================================================
//  SECTION 8: ERModel — 3D Model Resource
// ============================================================================
//
// ERModel (660 bytes) wraps a 3D model composed of ESubModelShader strips.
// Key fields (from resources_decomp.cpp and ERModel.h):
//   0x00..0x0B: bounding box min (3 floats)
//   0x0C: m_boneCount (s16)
//   0x01C: m_boneArray (u32 ptr)
//   0x020: m_numStrips (u32)
//   0x03C: m_pStripArray (TArray — ptr at 0x3C, count at 0x40)
//   0x048: m_boundRadius (f32)
//   0x088: m_scale (f32, default 1.0)
//   0x0F0: m_pShadowModel (u32)
//   0x134: flags (wall, morphTarget, lattice, weldable)
//   0x174: m_pScaleMatrix (u32)
//   0x178: m_loadFlags (u8)

// Forward declarations for strip draw helpers
static void ESubModelShader_Draw(void* strip, ERC* rc);
static void ESubModelShader_DrawGeometry(void* strip, ERC* rc);

// ---------- ERModel::Draw ----------
// Address: 0x80318B18, Size: 108 bytes
void ERModel_Draw(void* self, ERC* rc) {
    u32 stripArrayPtr = *(u32*)((u8*)self + 0x3C);
    int count = *(int*)((u8*)self + 0x40);  // TArray count

    for (int i = 0; i < count; i++) {
        // Each ESubModelShader is 0x18 (24) bytes in the array
        void* strip = (void*)(stripArrayPtr + i * 0x18);
        // strip->Draw(rc)  — non-virtual helper at 0x802FAF20
        // Selects the strip's ERShader, submits GX display list, restores state
        ESubModelShader_Draw(strip, rc);
    }
}

// ---------- ERModel::DrawGeometry ----------
// Address: 0x80318950, Size: 108 bytes
void ERModel_DrawGeometry(void* self, ERC* rc) {
    u32 stripArrayPtr = *(u32*)((u8*)self + 0x3C);
    int count = *(int*)((u8*)self + 0x40);

    for (int i = 0; i < count; i++) {
        void* strip = (void*)(stripArrayPtr + i * 0x18);
        // strip->DrawGeometry(rc) — skips shader selection
        ESubModelShader_DrawGeometry(strip, rc);
    }
}

// ---------- ESubModelShader::Draw ----------
// Address: 0x802FAF20 (helper, not in ERModel object)
static void ESubModelShader_Draw(void* strip, ERC* rc) {
    // 1. Get strip's ERShader from offset 0x08
    void* shader = (void*)*(u32*)((u8*)strip + 0x08);
    if (shader != nullptr) {
        // Select the shader (configures GX TEV/textures)
        ERShader_Select(shader, rc, 0);
    }

    // 2. Submit geometry
    ESubModelShader_DrawGeometry(strip, rc);
}

// ---------- ESubModelShader::DrawGeometry ----------
// Address: 0x802FB004 (helper)
static void ESubModelShader_DrawGeometry(void* strip, ERC* rc) {
    // Submit the prebuilt display list
    // u32 dlSize = *(u32*)((u8*)strip + 0x0C);
    // void* dl = *(void**)((u8*)strip + 0x14);
    // GXCallDisplayList(dl, dlSize);
    // For PC port: submit VBO/EBO draw call instead
    (void)strip;
    (void)rc;
}


// ============================================================================
//  SECTION 9: ENgcRenderer — Hardware Renderer Core
// ============================================================================
//
// ENgcRenderer (18,024 bytes) wraps the GX API and manages all render state.
// Key offsets from ENgcRenderer.h and engcrenderer_decomp.cpp:
//   0x0338: vtable ptr
//   0x0340: framebuffer index
//   0x0344: framebuffer[0]
//   0x0348: framebuffer[1]
//   0x034C: nextExternalFrameBuffer
//   0x0354: framebuffer stride
//   0x0358: GX FIFO buffer
//   0x035C: frame timer
//   0x0360: clear color dirty
//   0x0364: render mode struct
//   0x0368: width (u16)
//   0x036A: height (u16)
//   0x036C: efb height (u16)
//   0x03A0: shader (-1 = none)
//   0x03A4: alpha (f32)
//   0x04D8: renderStateCache ptr
//   0x04DC: current DL pointer
//   0x04E0: overflow flag
//   0x04E4: DL stack base
//   0x050C: DL stack pointer
//   0x0510: dirty flag
//   0x0518: ambient color (4 floats)
//   0x0528: diffuse color (4 floats)
//   0x0538: specular color (4 floats)
//   0x0548: render state entries (2 x 64 bytes)
//   0x0564..0x0568: blend mode fields
//   0x4634: texture count
//   0x4638: texture array (ENgcTexture*[])
//   0x4640: display list ptr
//   0x4644: z-test compare (u8)
//   0x4645: z-test reference (u8)
//   0x4646: z-test enable (u8)
//   0x4648: frame command counter
//   0x464C: frame effects scratch memory
//   0x4650: previous framebuffer ptr
//
// RSC (ENgcRenderStateCache) offsets within the cache block:
//   RSC+0x03AC: z-test enable (u8)
//   RSC+0x03B0: z-test compare func (u32)
//   RSC+0x03B4: z-test write enable (u8)
//   RSC+0x03B8: alpha compare0 func (u32)
//   RSC+0x03BC: alpha ref0 (u8)
//   RSC+0x03C0: alpha op (u32)
//   RSC+0x03C4: alpha compare1 func (u32)
//   RSC+0x03C8: alpha test flag (u8)
//   RSC+0x03C9: alpha passthrough (u8)
//   RSC+0x06CC: dirty flags (u32 bitmask)
//   RSC+0x06E8: geometry mode flags (u32)
//   RSC+0x079C: cull mode (u32)
//   RSC+0x09B0..0x09C4: viewport (6 floats)
//   RSC+0x09C8..0x09D4: scissor (4 u32)
//   RSC+0x09D8: projection mode (u32)

// Helper: access renderer fields by offset
static inline u32&  Rend_u32(void* r, u32 off)  { return *(u32*)((u8*)r + off); }
static inline u16&  Rend_u16(void* r, u32 off)  { return *(u16*)((u8*)r + off); }
static inline u8&   Rend_u8(void* r, u32 off)   { return *(u8*)((u8*)r + off); }
static inline f32&  Rend_f32(void* r, u32 off)  { return *(f32*)((u8*)r + off); }
static inline void* Rend_ptr(void* r, u32 off)  { return (void*)*(u32*)((u8*)r + off); }

// RSC field access (RSC base is at renderer + 0x04D8, stored as pointer)
static inline u8* RSC(void* rend) {
    return (u8*)*(u32*)((u8*)rend + 0x04D8);
}

static inline u32& RSC_u32(void* rend, u32 off) { return *(u32*)(RSC(rend) + off); }
static inline u8&  RSC_u8(void* rend, u32 off)  { return *(u8*)(RSC(rend) + off); }
static inline f32& RSC_f32(void* rend, u32 off) { return *(f32*)(RSC(rend) + off); }


// Forward declarations for ENgcRenderer functions used before definition
static void ENgcRenderer_InitVideo(void* self, int& outWidth, int& outHeight);
static void ENgcRenderer_BeginFrame(void* self, ENgcRendCommand* cmd);
static void ENgcRenderer_CycleToNextFrameBuffer(void* self);
static void ENgcRenderer_FlushCmd(void* self, ENgcRendCommand* cmd);

// ---------- ENgcRenderer::ENgcRenderer ----------
// Address: 0x8033B50C, Size: 480 bytes
void ENgcRenderer_Ctor(void* self) {
    // Base class constructor (ERenderer::ERenderer)
    // ... base init ...

    // Set vtable
    Rend_u32(self, 0x0338) = (u32)&ENgcRenderer_vtable;

    // Initialize render state entries (2 entries, 64 bytes each at 0x0548)
    for (int i = 0; i < 2; i++) {
        u8* entry = (u8*)self + 0x0548 + i * 0x40;
        *(u32*)(entry + 0x00) = 0;
        *(u32*)(entry + 0x04) = 0;
        *(u32*)(entry + 0x08) = 0;
        *(u32*)(entry + 0x0C) = 8;      // vertex format
        *(u32*)(entry + 0x10) = 24;     // stride
        *(f32*)(entry + 0x14) = 1.0f;   // alpha
        *(f32*)(entry + 0x18) = 0.0f;
        *(u8*)(entry + 0x1C) = 0;       // blend src = ZERO
        *(u8*)(entry + 0x1D) = 1;       // blend enable
        *(u8*)(entry + 0x1E) = 0;       // blend op
        *(u8*)(entry + 0x1F) = 1;       // z write
        *(u8*)(entry + 0x20) = 255;     // alpha ref
        *(u8*)(entry + 0x21) = 0;
        *(u8*)(entry + 0x22) = 0;
        *(u8*)(entry + 0x23) = 0;
        *(u8*)(entry + 0x24) = 0;
        *(u8*)(entry + 0x25) = 0;
        *(u16*)(entry + 0x26) = 0;
    }

    // Store global renderer pointer
    _pRend = self;

    // Set frame rate based on video mode
    if (g_videoMode == 1) {
        g_targetFrameRate = 50;  // progressive
    } else {
        g_targetFrameRate = 60;  // interlaced
    }

    // Initialize state
    Rend_u32(self, 0x034C) = 0;     // framebuffer index
    Rend_u32(self, 0x03A0) = (u32)-1;  // no shader active
    Rend_u32(self, 0x0510) = 1;     // dirty
    Rend_u32(self, 0x0360) = 1;     // needs clear
}

// ---------- ENgcRenderer::~ENgcRenderer ----------
// Address: 0x8033B6EC, Size: 52 bytes
void ENgcRenderer_Dtor(void* self) {
    Rend_u32(self, 0x0338) = (u32)&ENgcRenderer_vtable;
    _pRend = nullptr;
    // ERenderer::~ERenderer()
}

// ---------- ENgcRenderer::Init ----------
// Address: 0x8033B734, Size: 48 bytes
bool ENgcRenderer_Init(void* self, int& width, int& height) {
    // Thin wrapper around InitVideo
    ENgcRenderer_InitVideo(self, width, height);
    return true;
}

// ---------- ENgcRenderer::InitVideo ----------
// Address: 0x8033D5B4, Size: 692 bytes
// PC PORT: Replace with window creation + GL context init
static void ENgcRenderer_InitVideo(void* self, int& outWidth, int& outHeight) {
    // For PC port: create window with SDL/GLFW
    // Set default resolution
    u16 width = 640;
    u16 height = 480;

    Rend_u16(self, 0x0368) = width;
    Rend_u16(self, 0x036A) = height;

    outWidth = width;
    outHeight = height;

    // Calculate framebuffer stride: ((width + 15) & ~15) * 2
    u32 stride = ((width + 15) & ~15) * 2;
    u32 fbSize = stride * height;
    Rend_u32(self, 0x0354) = stride;
    Rend_u32(self, 0x0350) = fbSize;

    // Allocate two framebuffers (double buffering)
    void* heap = EAHeap_GetCurrentHeap();
    for (int i = 0; i < 2; i++) {
        void* fb = EAHeap_AllocAlign(heap, fbSize, 32, 0, 0);
        Rend_u32(self, 0x0344 + i * 4) = (u32)fb;
        memset(fb, 0, fbSize);
    }

    // Set initial framebuffer index
    Rend_u32(self, 0x0340) = 0;
    Rend_u32(self, 0x034C) = Rend_u32(self, 0x0344);

    // PC PORT: create FBOs, initialize OpenGL state here
}

// ---------- ENgcRenderer::QueueBeginFrame ----------
// Address: 0x8033E7F4, Size: 48 bytes
void ENgcRenderer_QueueBeginFrame(void* self, int frameNumber) {
    ENgcRendCommandData cmd;
    cmd.type = 1;  // REND_CMD_BEGIN_FRAME
    cmd.param1 = (u32)frameNumber;
    ENgcRenderer_BeginFrame(self, (ENgcRendCommand*)&cmd);
}

// ---------- ENgcRenderer::BeginFrame ----------
// Address: 0x8033E8E8, Size: 100 bytes
static void ENgcRenderer_BeginFrame(void* self, ENgcRendCommand* /*cmd*/) {
    g_renderActive = 1;
    g_frameTimeAccum = 0.0f;
    g_frameTimePrev = 0.0f;
    g_polyCount = 0;
    g_drawCallCount = 0;
    g_batchCount = 0;
    Rend_u32(self, 0x4648) = 0;  // frame command counter
}

// ---------- ENgcRenderer::Swap ----------
// Address: 0x8033EC3C, Size: 124 bytes
void ENgcRenderer_Swap(void* self, ENgcRendCommand* /*cmd*/) {
    // Cycle framebuffer
    ENgcRenderer_CycleToNextFrameBuffer(self);

    // Copy per-frame stats
    g_prevPolyCount = g_polyCount;
    g_prevFrameTime = g_frameTimeAccum;
    g_prevFrameTimePrev = g_frameTimePrev;
    g_prevDrawCallCount = g_drawCallCount;
    g_frameCounter++;
}

// ---------- ENgcRenderer::CycleToNextFrameBuffer ----------
// Address: 0x8033CAB8, Size: 100 bytes
static void ENgcRenderer_CycleToNextFrameBuffer(void* self) {
    // Advance framebuffer index (toggle 0/1)
    u32 idx = Rend_u32(self, 0x0340);
    idx = (idx + 1) % 2;
    Rend_u32(self, 0x0340) = idx;
    Rend_u32(self, 0x034C) = Rend_u32(self, 0x0344 + idx * 4);

    // PC PORT: SwapBuffers() here
}

// ---------- ENgcRenderer::Flush (no args) ----------
// Address: 0x8033E8BC, Size: 44 bytes
void ENgcRenderer_Flush(void* self) {
    ENgcRendCommandData cmd;
    cmd.type = 5;  // REND_CMD_FLUSH
    ENgcRenderer_FlushCmd(self, (ENgcRendCommand*)&cmd);
}

// ---------- ENgcRenderer::Flush (with command) ----------
// Address: 0x8033ECB8, Size: 32 bytes
static void ENgcRenderer_FlushCmd(void* /*self*/, ENgcRendCommand* /*cmd*/) {
    // PC PORT: glFinish() or glFlush()
}


// ---------- ENgcRenderer::Execute ----------
// Address: 0x80341E28, Size: 192 bytes
void ENgcRenderer_Execute(void* self, EDLEntry* dlStart) {
    Rend_u32(self, 0x04DC) = (u32)dlStart;  // current DL pointer
    Rend_u32(self, 0x04E0) = 0;             // overflow flag

    while (true) {
        u8* current = (u8*)Rend_u32(self, 0x04DC);
        u8 opcode = current[0];

        // Advance DL pointer past this 8-byte entry
        Rend_u32(self, 0x04DC) = (u32)(current + 8);

        // Look up handler in jump table (75 entries, 8 bytes each)
        // JumpTableEntry* jte = &m_jumpTable[opcode];
        // handler = jte->handler;
        // handler(self, (EDLEntry*)current);

        // Dispatch would go here in full implementation
        // For now, just check for End command (opcode 8)
        if (opcode == 8) {
            // End command
            u32 stackPtr = Rend_u32(self, 0x050C);
            if (stackPtr != 0) {
                stackPtr--;
                Rend_u32(self, 0x050C) = stackPtr;
                u32* stack = (u32*)((u8*)self + 0x04E4);
                Rend_u32(self, 0x04DC) = stack[stackPtr];
            } else {
                Rend_u32(self, 0x04E0) = 1;  // stop
            }
        }

        if (Rend_u32(self, 0x04E0) != 0) {
            break;
        }
    }
}


// ---------- ENgcRenderer::Viewport ----------
// Address: 0x80343DDC, Size: 160 bytes
void ENgcRenderer_Viewport(void* self, EDLEntry* entry) {
    if (g_viewportChanged != 0) {
        g_viewportChanged = 0;
    }

    f32* vp = (f32*)*(u32*)((u8*)entry + 4);  // param pointer to 6 floats

    f32 left   = vp[0];
    f32 top    = vp[1];
    f32 width  = vp[4];
    f32 height = vp[5];

    RSC_f32(self, 0x09B0) = -left + width;
    RSC_f32(self, 0x09B4) = top + height;
    RSC_f32(self, 0x09B8) = (left + width) - RSC_f32(self, 0x09B0);
    RSC_f32(self, 0x09BC) = -(-top + height) - RSC_f32(self, 0x09B4);
    RSC_f32(self, 0x09C0) = 0.0f;
    RSC_f32(self, 0x09C4) = 1.0f;

    RSC_u32(self, 0x06CC) |= 0x80000200;  // viewport dirty
}

// ---------- ENgcRenderer::Scissor ----------
// Address: 0x80343EA0, Size: 404 bytes
void ENgcRenderer_Scissor(void* self, EDLEntry* entry) {
    f32* rect = (f32*)*(u32*)((u8*)entry + 4);

    f32 left   = rect[0];
    f32 top    = rect[1];
    f32 right  = rect[2];
    f32 bottom = rect[3];

    f32 width  = (right - left) + 0.5f;
    f32 height = (bottom - top) + 0.5f;

    RSC_u32(self, 0x09C8) = (u32)(s32)left;
    RSC_u32(self, 0x09CC) = (u32)(s32)top;
    RSC_u32(self, 0x09D0) = (u32)(s32)width;
    RSC_u32(self, 0x09D4) = (u32)(s32)height;

    if (width <= 0.0f || height <= 0.0f) {
        RSC_u32(self, 0x09D0) = 0;
        RSC_u32(self, 0x09D4) = 0;
    }

    RSC_u32(self, 0x06CC) |= 0x80000400;  // scissor dirty
}

// ---------- ENgcRenderer::SetClearColor ----------
// Address: 0x8033CA48, Size: 80 bytes
void ENgcRenderer_SetClearColor(void* self, EVec3* color, bool flag) {
    Rend_u32(self, 0x0360) = flag ? 1 : 0;

    // Convert float RGB to u8 clear color
    u8* clearColor = (u8*)self + 0x03AC;
    clearColor[0] = (u8)(color->x * 255.0f);
    clearColor[1] = (u8)(color->y * 255.0f);
    clearColor[2] = (u8)(color->z * 255.0f);
    clearColor[3] = 127;  // alpha = 0.5

    Rend_u32(self, 0x03B0) = 0x00FFFFFF;  // clear Z to max
}

// ---------- ENgcRenderer::ViewMatrix ----------
// Address: 0x8034420C, Size: 204 bytes
void ENgcRenderer_ViewMatrix(void* self, EDLEntry* entry) {
    f32* src = (f32*)*(u32*)((u8*)entry + 4);  // 4x4 row-major matrix
    f32* dst = (f32*)(RSC(self) + 0x0860);     // view matrix slot in RSC

    // Transpose while copying (row-major -> column-major)
    // Row 0
    dst[0]  = src[0];  dst[1]  = src[4];  dst[2]  = src[8];  dst[3]  = src[12];
    // Row 1
    dst[4]  = src[1];  dst[5]  = src[5];  dst[6]  = src[9];  dst[7]  = src[13];
    // Row 2
    dst[8]  = src[2];  dst[9]  = src[6];  dst[10] = src[10]; dst[11] = src[14];

    RSC_u32(self, 0x06CC) |= 0x80000004;  // view matrix dirty
    Rend_u32(self, 0x0510) = 1;            // global dirty
}

// ---------- ENgcRenderer::ProjectionMatrix ----------
// Address: 0x803442D8, Size: 196 bytes
void ENgcRenderer_ProjectionMatrix(void* self, EDLEntry* entry) {
    f32* src = (f32*)*(u32*)((u8*)entry + 4);

    // Transpose 4x4 matrix into global projection buffer
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 4; row++) {
            g_projectionMatrix[col * 4 + row] = src[row * 4 + col];
        }
    }

    // Set projection mode to custom (2)
    RSC_u32(self, 0x09D8) = 2;

    RSC_u32(self, 0x06CC) |= 0x80000020;  // projection dirty
    Rend_u32(self, 0x0510) = 1;
}

// ---------- ENgcRenderer::WindowMatrix ----------
// Address: 0x8034439C, Size: 160 bytes
void ENgcRenderer_WindowMatrix(void* self, EDLEntry* entry) {
    if (g_windowMatrixChanged != 0) {
        g_windowMatrixChanged = 0;
    }

    f32* src = (f32*)*(u32*)((u8*)entry + 4);
    f32* dst = (f32*)((u8*)self + 0x0498);
    memcpy(dst, src, 64);  // copy 4x4 matrix (16 floats = 64 bytes)
}


// ---------- ENgcRenderer::ZTest ----------
// Address: 0x80345220, Size: 100 bytes
void ENgcRenderer_ZTest(void* self, EDLEntry* entry) {
    u8 enable = ((u8*)entry)[1];
    u8 ref    = ((u8*)entry)[2];
    u8 func   = ((u8*)entry)[3];

    Rend_u8(self, 0x4644) = enable;
    Rend_u8(self, 0x4645) = ref;
    Rend_u8(self, 0x4646) = func;

    u8 zEnable = (enable != 0) ? 1 : 0;
    u8 zWrite  = (func != 0) ? 1 : 0;
    u32 gxCompare = g_compareTable[ref & 7];  // clamp to valid range

    RSC_u8(self, 0x03AC)  = zEnable;
    RSC_u32(self, 0x03B0) = gxCompare;
    RSC_u8(self, 0x03B4)  = zWrite;
    RSC_u32(self, 0x06CC) |= 0x80000040;  // z/alpha test dirty
}

// ---------- ENgcRenderer::AlphaTest ----------
// Address: 0x80345284, Size: 144 bytes
void ENgcRenderer_AlphaTest(void* self, EDLEntry* entry) {
    u8 enable = ((u8*)entry)[1];
    u8 func   = ((u8*)entry)[2];
    u8 ref    = ((u8*)entry)[3];

    if (enable != 0) {
        u32 gxFunc = g_compareTable[func & 7];
        RSC_u32(self, 0x03B8) = gxFunc;     // alphaCompare0
        RSC_u8(self, 0x03BC)  = ref;        // alphaRef0
        RSC_u32(self, 0x03C4) = 7;          // alphaCompare1 = GX_ALWAYS
        RSC_u32(self, 0x03C0) = 0;          // alphaOp = GX_AOP_AND
        RSC_u8(self, 0x03C9)  = 0;          // alphaPassthrough = false
        RSC_u8(self, 0x03C8)  = 0;          // alphaTestFlag = false
    } else {
        RSC_u32(self, 0x03C4) = 7;          // GX_ALWAYS
        RSC_u8(self, 0x03C9)  = 1;          // passthrough = true
        RSC_u8(self, 0x03C8)  = 0;
        RSC_u32(self, 0x03B8) = 7;          // GX_ALWAYS
        RSC_u8(self, 0x03BC)  = 0;
        RSC_u32(self, 0x03C0) = 1;          // GX_AOP_OR
    }

    RSC_u32(self, 0x06CC) |= 0x80000040;    // z/alpha test dirty
}

// ---------- ENgcRenderer::SetBlendMode ----------
// Address: 0x80346124, Size: 56 bytes
void ENgcRenderer_SetBlendMode(void* self, EDLEntry* entry) {
    u32 packed = *(u32*)((u8*)entry + 4);
    Rend_u32(self, 0x0510) = 1;  // dirty

    Rend_u8(self, 0x0564) = packed & 0x3;          // src factor
    Rend_u8(self, 0x0565) = (packed >> 2) & 0x3;   // dst factor
    Rend_u8(self, 0x0566) = (packed >> 4) & 0x3;   // blend op
    Rend_u8(self, 0x0567) = (packed >> 6) & 0x3;   // logic op
    Rend_u8(self, 0x0568) = (packed >> 24) & 0xFF;  // alpha value
}

// ---------- ENgcRenderer::SetAlpha ----------
// Address: 0x80344714, Size: 16 bytes
void ENgcRenderer_SetAlpha(void* self, f32 alpha) {
    Rend_f32(self, 0x03A4) = alpha;
    Rend_u32(self, 0x0510) = 1;  // dirty
}

// ---------- ENgcRenderer::Material ----------
// Address: 0x80345120, Size: 132 bytes
void ENgcRenderer_Material(void* self, EDLEntry* entry) {
    f32* src = (f32*)*(u32*)((u8*)entry + 4);

    // Copy ambient (4 floats at offset 0x0518)
    f32* ambient = (f32*)((u8*)self + 0x0518);
    ambient[0] = src[0]; ambient[1] = src[1];
    ambient[2] = src[2]; ambient[3] = src[3];

    // Copy diffuse (4 floats at offset 0x0528)
    f32* diffuse = (f32*)((u8*)self + 0x0528);
    diffuse[0] = src[4]; diffuse[1] = src[5];
    diffuse[2] = src[6]; diffuse[3] = src[7];

    // Copy specular + shininess (at offset 0x0538)
    u32* spec = (u32*)((u8*)self + 0x0538);
    spec[0] = ((u32*)src)[8];
    spec[1] = ((u32*)src)[9];
    spec[2] = ((u32*)src)[10];
    *(f32*)&spec[3] = src[11];

    Rend_u32(self, 0x0510) = 1;  // dirty
}

// ---------- ENgcRenderer::EnableGeometryModes ----------
// Address: 0x80344598, Size: 88 bytes
void ENgcRenderer_EnableGeometryModes(void* self, EDLEntry* entry) {
    u32 flags = *(u32*)((u8*)entry + 4);

    RSC_u32(self, 0x06CC) |= 0x80000000;
    RSC_u32(self, 0x06E8) |= flags;

    u32 geoFlags = RSC_u32(self, 0x06E8);
    u32 cullMode = 0;
    if (geoFlags & 0x04) {
        cullMode = 1;  // GX_CULL_FRONT
    } else if (geoFlags & 0x02) {
        cullMode = 2;  // GX_CULL_BACK
    }
    RSC_u32(self, 0x079C) = cullMode;

    Rend_u32(self, 0x0510) = 1;
}

// ---------- ENgcRenderer::DisableGeometryModes ----------
// (mirror of Enable but with AND-NOT)
void ENgcRenderer_DisableGeometryModes(void* self, EDLEntry* entry) {
    u32 flags = *(u32*)((u8*)entry + 4);

    RSC_u32(self, 0x06CC) |= 0x80000000;
    RSC_u32(self, 0x06E8) &= ~flags;

    u32 geoFlags = RSC_u32(self, 0x06E8);
    u32 cullMode = 0;
    if (geoFlags & 0x04) {
        cullMode = 1;
    } else if (geoFlags & 0x02) {
        cullMode = 2;
    }
    RSC_u32(self, 0x079C) = cullMode;

    Rend_u32(self, 0x0510) = 1;
}

// ---------- ENgcRenderer::SetGeometryModes ----------
void ENgcRenderer_SetGeometryModes(void* self, EDLEntry* entry) {
    u32 flags = *(u32*)((u8*)entry + 4);

    RSC_u32(self, 0x06CC) |= 0x80000000;
    RSC_u32(self, 0x06E8) = flags;

    u32 cullMode = 0;
    if (flags & 0x04) {
        cullMode = 1;
    } else if (flags & 0x02) {
        cullMode = 2;
    }
    RSC_u32(self, 0x079C) = cullMode;

    Rend_u32(self, 0x0510) = 1;
}


// ---------- ENgcRenderer::SaveState / RestoreState ----------
// Address: 0x80343D94 / 0x80343DB8, Size: 36 each
void ENgcRenderer_SaveState(void* self, EDLEntry* /*entry*/) {
    ENgcRenderStateCache_Save((ENgcRenderStateCache*)RSC(self));
}

void ENgcRenderer_RestoreState(void* self, EDLEntry* /*entry*/) {
    ENgcRenderStateCache_Restore((ENgcRenderStateCache*)RSC(self));
}


// ---------- ENgcRenderer::SetTexture ----------
// Address: 0x8034447C, Size: 284 bytes
void ENgcRenderer_SetTexture(void* self, void* tex, int slot) {
    void* oldTex = (void*)Rend_u32(self, 0x4638 + slot * 4);

    // Update texture reference counting
    if (tex != nullptr && oldTex == nullptr) {
        Rend_u32(self, 0x4634)++;  // m_textureCount++
    } else if (tex == nullptr && oldTex != nullptr) {
        u32 count = Rend_u32(self, 0x4634);
        if (count > 0) {
            Rend_u32(self, 0x4634) = count - 1;
        }
    }

    // Store new texture
    Rend_u32(self, 0x4638 + slot * 4) = (u32)tex;

    // PC PORT: glActiveTexture(GL_TEXTURE0 + slot)
    //          glBindTexture(GL_TEXTURE_2D, texId)
}

// ---------- ENgcRenderer::GetCurrentTexture ----------
// Address: 0x8033B724, Size: 16 bytes
void* ENgcRenderer_GetCurrentTexture(void* self, int slot) {
    return (void*)Rend_u32(self, 0x4638 + slot * 4);
}


// ---------- ENgcRenderer::Goto ----------
// Address: 0x80343D54, Size: 12 bytes
void ENgcRenderer_Goto(void* self, EDLEntry* entry) {
    Rend_u32(self, 0x04DC) = *(u32*)((u8*)entry + 4);
}

// ---------- ENgcRenderer::End ----------
// Address: 0x80343D60, Size: 52 bytes
void ENgcRenderer_End(void* self, EDLEntry* /*entry*/) {
    u32 stackPtr = Rend_u32(self, 0x050C);
    if (stackPtr != 0) {
        stackPtr--;
        Rend_u32(self, 0x050C) = stackPtr;
        u32* stack = (u32*)((u8*)self + 0x04E4);
        Rend_u32(self, 0x04DC) = stack[stackPtr];
    } else {
        Rend_u32(self, 0x04E0) = 1;  // overflow = stop Execute loop
    }
}

// ---------- ENgcRenderer::DisplayList (command) ----------
// Address: 0x80343D24, Size: 48 bytes
void ENgcRenderer_DisplayListCmd(void* self, EDLEntry* entry) {
    u32 stackPtr = Rend_u32(self, 0x050C);
    u32* stack = (u32*)((u8*)self + 0x04E4);
    stack[stackPtr] = Rend_u32(self, 0x04DC);  // save current DL position
    Rend_u32(self, 0x050C) = stackPtr + 1;

    void* dl = *(void**)((u8*)entry + 4);
    Rend_u32(self, 0x4640) = (u32)dl;                         // m_currentDL
    Rend_u32(self, 0x04DC) = *(u32*)((u8*)dl + 0x48);        // DL command start
}


// ---------- ENgcRenderer::PushAndClearViewport ----------
// Address: 0x8033ECD8, Size: 240 bytes
void ENgcRenderer_PushAndClearViewport(void* self) {
    ENgcRenderStateCache_Save((ENgcRenderStateCache*)RSC(self));

    // Set full-screen viewport
    RSC_f32(self, 0x09B0) = 0.0f;
    RSC_f32(self, 0x09B4) = 0.0f;
    RSC_f32(self, 0x09B8) = (f32)Rend_u16(self, 0x0368);  // render width
    RSC_f32(self, 0x09BC) = (f32)Rend_u16(self, 0x036A);  // render height
    RSC_f32(self, 0x09C0) = 0.0f;
    RSC_f32(self, 0x09C4) = 1.0f;

    // Set full-screen scissor
    RSC_u32(self, 0x09C8) = 0;
    RSC_u32(self, 0x09CC) = 0;
    RSC_u32(self, 0x09D0) = Rend_u16(self, 0x0368);
    RSC_u32(self, 0x09D4) = Rend_u16(self, 0x036A);

    RSC_u32(self, 0x06CC) |= 0x80000600;  // viewport + scissor dirty
}

// ---------- ENgcRenderer::RestoreViewport ----------
// Address: 0x8033EDC8, Size: 36 bytes
void ENgcRenderer_RestoreViewport(void* self) {
    ENgcRenderStateCache_Restore((ENgcRenderStateCache*)RSC(self));
}


// ---------- Accessor Functions ----------

// GetRenderStateCache - Address: 0x80349F3C, Size: 8
void* ENgcRenderer_GetRenderStateCache(void* self) {
    return Rend_ptr(self, 0x04D8);
}

// GetNextExternalFrameBuffer - Address: 0x80349F44, Size: 8
void* ENgcRenderer_GetNextExternalFrameBuffer(void* self) {
    return Rend_ptr(self, 0x034C);
}

// GetFrameEffectsScratchMemory - Address: 0x80349FD4, Size: 8
void* ENgcRenderer_GetFrameEffectsScratchMemory(void* self) {
    return Rend_ptr(self, 0x464C);
}

// GetExternalFrameBuffer - Address: 0x8033CA98, Size: 32
void* ENgcRenderer_GetExternalFrameBuffer(void* self) {
    void* fb0 = Rend_ptr(self, 0x0344);
    void* nextXFB = Rend_ptr(self, 0x034C);
    if (nextXFB != fb0) {
        return fb0;
    }
    return Rend_ptr(self, 0x0348);
}

// GetRenderMode - Address: 0x8034A51C, Size: 28
void* ENgcRenderer_GetRenderMode(void* self) {
    if (Rend_ptr(self, 0x034C) == nullptr) {
        return nullptr;
    }
    return (void*)((u8*)self + 0x0364);
}

// GetZTestSettings - Address: 0x8034A538, Size: 28
void ENgcRenderer_GetZTestSettings(void* self, u8& compare, u8& ref, u8& enable) {
    compare = Rend_u8(self, 0x4644);
    ref     = Rend_u8(self, 0x4645);
    enable  = Rend_u8(self, 0x4646);
}

// GetPreviousFrameBuffer - Address: 0x80349F4C, Size: 32
void* ENgcRenderer_GetPreviousFrameBuffer(void* self, int* outWidth, int* outHeight) {
    *outWidth  = Rend_u16(self, 0x0368) >> 1;
    *outHeight = Rend_u16(self, 0x036A) >> 1;
    return Rend_ptr(self, 0x4650);
}


// ---------- DrawSyncCallback ----------
// Address: 0x8033CE20, Size: 8 bytes
static u16 s_lastTokenFromGX = 0;
static u16 s_lastTokenToGX = 0;

void ENgcRenderer_DrawSyncCallback(u16 token) {
    s_lastTokenFromGX = token;
}

// ---------- AddDrawSync ----------
// Address: 0x8033CE28, Size: 52 bytes
void ENgcRenderer_AddDrawSync(void* /*self*/) {
    s_lastTokenToGX++;
    // GXSetDrawSync(s_lastTokenToGX);
    // PC PORT: glFenceSync / memory barrier
}


// ---------- Stub Functions ----------
// These exist in the jump table but do nothing on GameCube.
// They represent PS2/Xbox features not used on this platform.

void ENgcRenderer_ShowPerfGraphs(void* /*self*/, bool /*show*/) { }
void ENgcRenderer_TextureMatrix(void* /*self*/, EDLEntry* /*entry*/) { }
void ENgcRenderer_NoOp(void* /*self*/, EDLEntry* /*entry*/) { }
void ENgcRenderer_VIPostRetraceCallback(void* /*self*/, u32 /*retraceCount*/) { }
void ENgcRenderer_ProcessFrameEffects(void* /*self*/,
    f32 /*a*/, f32 /*b*/, f32 /*c*/, f32 /*d*/,
    EVec3* /*e*/, EVec3* /*f*/) { }


// ============================================================================
//  SECTION 10: ClearXFB and Allocation Helpers
// ============================================================================

// ---------- ClearXFB ----------
// Address: 0x8033B4E4, Size: 40 bytes
void ClearXFB(u8* buf, int size) {
    u8* end = buf + size;
    while (buf < end) {
        *(u32*)buf = 0x10801080;  // YCbCr black
        buf += 4;
    }
}

// ---------- PerfAlloc ----------
// Address: 0x8033B404, Size: 56 bytes
void* PerfAlloc(u32 size) {
    void* heap = EAHeap_GetCurrentHeap();
    return EAHeap_Alloc(heap, size, 0);
}

// ---------- PerfFree ----------
// Address: 0x8033B43C, Size: 52 bytes
void PerfFree(void* ptr) {
    void* heap = EAHeap_GetCurrentHeap();
    EAHeap_Free(heap, ptr);
}

// ---------- ScreenShotAlloc ----------
// Address: 0x8033B470, Size: 64 bytes
void* ScreenShotAlloc(u32 size) {
    void* heap = EAHeap_GetCurrentHeap();
    return EAHeap_AllocAlign(heap, size, 32, 0, 0);
}

// ---------- ScreenShotFree ----------
// Address: 0x8033B4B0, Size: 52 bytes
void ScreenShotFree(void* ptr) {
    void* heap = EAHeap_GetCurrentHeap();
    EAHeap_Free(heap, ptr);
}
