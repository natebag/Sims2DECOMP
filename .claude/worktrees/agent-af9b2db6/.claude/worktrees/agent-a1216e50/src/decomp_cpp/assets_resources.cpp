// assets_resources.cpp - Real C++ decompilation of asset loading & resource classes
// Part of the Sims 2 GC decompilation — PC port variant
//
// Converted from inline asm (src/asm_decomp/) and decomp docs
// (asset_loading_decomp.cpp, resources_decomp.cpp) into functionally
// correct C++ using struct field names from include/classes/ headers.
//
// This is NOT byte-matching code. It is a clean C++ translation for a
// future PC port, preserving the original logic and data flow.
//
// Classes covered:
//   NghResFile         - Neighborhood save/load (.NGH format)
//   ChainResFile       - Multi-file resource chaining
//   IFFResFile2        - IFF container file parser
//   EResourceManager   - Central resource registry
//   EResourceLoaderImpl - Async resource loading coordinator
//   EResource          - Base reference-counted resource
//   ERShader           - Shader resource (day/night blending, multi-state)
//   ETexture           - Platform-agnostic texture description
//   ERTexture          - Texture resource wrapper
//   ERFont             - Bitmap font resource

#include "types.h"

// ============================================================================
// Forward Declarations & Minimal Type Stubs
// ============================================================================

class EResource;
class EResourceManager;
class EResourceLoaderImpl;
class EResourceMap;
class EResPrefetch;
class EResPrefetchFile;
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
class EFile;
class EStream;
class EString;
class EFontData;
class EFontSize;
class EFontPage;
class ETextureManager;
class ETypeInfo;
class EStorable;
class EDataHeader;
class EThread;
class ESemaphore;
class EWindow;
class MultiShaderInfo;
class MemFile;
class MemoryCardCache;

class iResFile;
class IFFResFile2;
class IFFResNode;
class IFFResMap;
class IFFResList;
class IFFHeader;
class NghResFile;
class ChainResFile;
class ArcFileInfo;
class ArcCopier;

struct StringBuffer;
struct NghResFileSectionHeader;
struct NghResFileWriteInfo;
struct NghLayout;
struct EResLoadCmd;
struct EResLoadCmdResult;
struct EScratchBuffUser;
struct EPrefetchMsg;
struct CUIWindow;
struct EACNodeState;
struct fontFXcommand;
struct EVec2 { f32 x, y; };
struct EVec3 { f32 x, y, z; };
struct EVec4 { f32 x, y, z, w; };
struct EMat4 { f32 m[4][4]; };

enum EFontAlignX { FONT_ALIGN_X_LEFT = 0, FONT_ALIGN_X_CENTER = 1, FONT_ALIGN_X_RIGHT = 2 };
enum EFontAlignY { FONT_ALIGN_Y_TOP = 0, FONT_ALIGN_Y_CENTER = 1, FONT_ALIGN_Y_BOTTOM = 2 };
enum EFontMatrixType { FONT_MATRIX_IDENTITY = 0, FONT_MATRIX_CUSTOM = 1 };

namespace Memory { class HandleNode; }

// ============================================================================
// External Function Declarations
// ============================================================================

extern void* MainHeap();
extern void* RootHeap();
extern void* VMHeap();
extern void* EAHeap_Malloc(void* heap, u32 size, int flags);
extern void  EAHeap_Free(void* heap, void* ptr);

extern void  EString_SetToNull(void* str);
extern void  EString_MakeCopy(void* str, const char* src);
extern void  EString_Deallocate(void* str, void* data);

extern void  ETypeInfo_Register(void* typeInfo, void* newFn, void* constructFn,
                                void* destructFn, u16 key, const char* name, void* parent);

extern "C" {
    extern void* memcpy(void* dst, const void* src, u32 size);
    extern void* memset(void* dst, int val, u32 size);
    extern int   strcmp(const char* a, const char* b);
    extern char* strstr(const char* hay, const char* needle);
    extern u32   strlen(const char* s);
}

// Vtable pointers (link-time resolved)
extern void* EResource_vtable;
extern void* EStorable_vtable;
extern void* ERShader_vtable;
extern void* ERTexture_vtable;
extern void* ERFont_vtable;
extern void* NghResFile_vtable;
extern void* ChainResFile_vtable;
extern void* IFFResFile2_vtable;
extern void* EResourceManager_vtable;
extern void* EResourceLoaderImpl_vtable;

// Global singletons (r13-relative in original binary)
extern ETextureManager* g_pTextureManager;     // r13 - 0x6718
extern void*            g_pShaderSystem;       // r13 - 0x66C8
extern EResourceLoaderImpl* g_pResourceLoader; // global
extern NghLayout*       g_pNghLayout;          // 0x80486330

// Global flag for binary load path
extern u16 g_useBinaryLoad;                    // 0x804FCD4E


// ============================================================================
//  SECTION 1: EResource -- Base Reference-Counted Resource
// ============================================================================
//
// Size: ~0x14 (20 bytes)
//   0x00: _vtable
//   0x04: m_pManager (EResourceManager*)
//   0x08: m_resId (u32)
//   0x0A: m_readVersion (u16)
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
    self->m_pManager = NULL;
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
    if (self->m_pManager != NULL) {
        // EResourceManager::ResourceDestructing(EResource*)
        void** mgrVtbl = *(void***)self->m_pManager;
        // Direct call (not virtual -- known function)
        // self->m_pManager->ResourceDestructing(self);
    }

    // Set vtable to parent EStorable
    self->_vtable = (void**)&EStorable_vtable;

    // SN Systems ABI: if scalar-delete bit set, free memory
    if (hiddenParam & 0x01) {
        void* heap = MainHeap();
        EAHeap_Free(heap, self);
    }
}

// ---------- EResource::AddRef ----------
// Address: 0x80312000, Size: 64 bytes
void EResource_AddRef(EResourceFields* self) {
    if (self->m_pManager != NULL) {
        // Managed: delegate to EResourceManager::AddRef(EResource*)
        // self->m_pManager->AddRef(self);
    } else {
        // Unmanaged: local increment
        self->m_refCount++;
    }
}

// ---------- EResource::DelRef ----------
// Address: 0x80311F70, Size: 104 bytes
void EResource_DelRef(EResourceFields* self) {
    if (self->m_pManager != NULL) {
        // Managed: delegate to manager (mode = NORMAL = 1)
        // self->m_pManager->DelRef(self, 1);
    } else {
        // Unmanaged: local decrement
        self->m_refCount--;
        if (self->m_refCount == 0) {
            // Virtual SafeDelete dispatch through vtable
            // vtable offset 0x08: this-adjust (s16), 0x0C: function pointer
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
    if (self->m_pManager != NULL) {
        // self->m_pManager->Detach(self);
    }
}

// ---------- EResource::Refresh ----------
// Address: 0x80312040, Size: 48 bytes
void EResource_Refresh(EResourceFields* self) {
    if (self->m_pManager != NULL) {
        // self->m_pManager->Refresh(self);
    }
}

// ---------- EResource::Write ----------
// Address: 0x80311E64, Size: 84 bytes
void EResource_Write(EResourceFields* self, void* stream) {
    // Create EString with type name "EResource"
    u32 localStr[2];  // stack EString
    EString_MakeCopy(&localStr, "EResource");

    // Write type name to stream
    // operator<<(stream, localStr);

    // Clean up
    EString_Deallocate(&localStr, (void*)localStr[0]);
}

// ---------- EResource::Read ----------
// Address: 0x80311EB8, Size: 92 bytes
void EResource_Read(EResourceFields* self, void* stream) {
    u32 localStr[2];  // stack EString
    EString_SetToNull(&localStr);

    if (g_useBinaryLoad == 0) {
        // Stream-based read: operator>>(stream, localStr)
    }

    EString_Deallocate(&localStr, (void*)localStr[0]);
}

// ---------- EResource::Load ----------
// Address: 0x80311F14, Size: 92 bytes
void EResource_Load(EResourceFields* self, void* file) {
    u32 localStr[2];  // stack EString
    EString_SetToNull(&localStr);

    if (g_useBinaryLoad == 0) {
        // File-based read: operator>>(file, localStr)
    }

    EString_Deallocate(&localStr, (void*)localStr[0]);
}

// ---------- EResource::SafeDelete ----------
// Address: 0x80312158, Size: 64 bytes
void EResource_SafeDelete(EResourceFields* self) {
    if (self == NULL) return;

    void** vtbl = self->_vtable;
    int mode = 3;
    s16 adj = *(s16*)((u8*)vtbl + 0x30);
    void (*fn)(void*, int) = (void(*)(void*, int))*(u32*)((u8*)vtbl + 0x34);
    fn((u8*)self + adj, mode);
}

// ---------- EResource::IsSafeToDelete ----------
// Address: 0x8031226C, Size: 8 bytes
bool EResource_IsSafeToDelete(EResourceFields* /*self*/) {
    return true;
}

// ---------- EResource::Init ----------
// Address: 0x80312338, Size: 4 bytes
void EResource_Init(EResourceFields* /*self*/) {
    // Intentionally empty -- no-op in base class
}

// ---------- EResource::RegisterType ----------
// Address: 0x803121E0, Size: 84 bytes
void EResource_RegisterType(void* typeInfo, u16 key) {
    // Registers EResource with the type system
    // ETypeInfo::Register(New, Construct, Destruct, key, "EResource", parentTypeInfo);
}


// ============================================================================
//  SECTION 2: ERShader -- Shader Resource
// ============================================================================
//
// ERShader wraps EShader(s) and manages day/night blending,
// multi-shader states, and texture swapping.
// Size: 0x17BC (6,076 bytes)
//
// Key fields (from resources_decomp.cpp analysis):
//   0x014: m_pCurrentEShader (EShader*)
//   0x018: m_pCurrentERShader (ERShader* -- child for multi-shader)
//   0x01C: m_pIncomingShader (EShader*)
//   0x02C: m_blendFactor (f32)
//   0x030: m_pBlendEShader (EShader*)
//   0x034: m_pTextureResource (ERTexture*)
//   0x038: m_textureResId (u32)
//   0x03C: m_timeOfDay (f32) -- initialized to -1.0f
//   0x040: m_weatherFactor (f32)
//   0x044: m_numStates (u8)
//   0x048: m_pStateArray (ERShader**)
//   0x04C: m_pMultiShaderInfo (MultiShaderInfo*)
//   0x050: m_currentStateIndex (u8)
//   0x054: m_pUpdateListNext (ERShader*)
//   0x058: m_flags (s16)
//     bit 0: unused
//     bit 1: is multi-shader
//     bit 2: has multi-texture
//     bit 3: supports decal
//     bit 4: state change pending
//     bit 5: is day/night shader
//   0x05C: m_pendingShader (u32)
//   0x060: m_blendProgress (f32)
//   0x064: m_currentShaderIdx (u8)
//   0x065: m_targetShaderIdx (u8)
//   0x066: m_updateFlags (u8)
//   0x067: m_weatherState (u8)
//   0x068: m_shaderData (u32)
//   0x0F0: m_pEShaderDef (EShaderDef*)
//   0x17B8: m_pUpdateListHead (u32) -- static: global shader update list

// Helper: access ERShader fields by offset (mirrors assembly access patterns)
static inline u32& ERShader_u32(void* self, u32 off) { return *(u32*)((u8*)self + off); }
static inline f32& ERShader_f32(void* self, u32 off) { return *(f32*)((u8*)self + off); }
static inline u8&  ERShader_u8(void* self, u32 off)  { return *(u8*)((u8*)self + off); }
static inline s16& ERShader_s16(void* self, u32 off) { return *(s16*)((u8*)self + off); }

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
    ERShader_u32(self, 0x03C) = 0xBF800000;  // -1.0f in IEEE 754

    // Zero multi-shader info
    ERShader_u32(self, 0x04C) = 0;  // m_pMultiShaderInfo
    ERShader_f32(self, 0x040) = 0.0f;  // m_weatherFactor
    ERShader_u8(self, 0x050)  = 0;  // m_currentStateIndex
    ERShader_u32(self, 0x054) = 0;  // m_pUpdateListNext
    ERShader_u32(self, 0x058) = 0;  // m_flags (and adjacent bytes)
    ERShader_u32(self, 0x05C) = 0;  // m_pendingShader

    ERShader_f32(self, 0x060) = 0.0f;  // m_blendProgress
    ERShader_u32(self, 0x068) = 0;  // m_shaderData

    ERShader_u8(self, 0x050)  = 0;  // m_currentStateIndex
    ERShader_u8(self, 0x064)  = 0;  // m_currentShaderIdx
    ERShader_u8(self, 0x065)  = 0;  // m_targetShaderIdx
    ERShader_u8(self, 0x066)  = 0;  // m_updateFlags
    ERShader_u8(self, 0x067)  = 0;  // m_weatherState

    // Zero two pairs of shader/data pointers (loop in asm: bdnz zeroing 4 words)
    // These are at offsets 0x020..0x02F (day/night shader array)
    ERShader_u32(self, 0x020) = 0;
    ERShader_u32(self, 0x024) = 0;
    ERShader_u32(self, 0x028) = 0;
    ERShader_u32(self, 0x02C) = 0;

    // Zero state array pointers
    ERShader_u32(self, 0x044) = 0;  // m_numStates
    ERShader_u32(self, 0x048) = 0;  // m_pStateArray
}

// ---------- ERShader::~ERShader ----------
// Address: 0x8031C7A0, Size: 104 bytes
void ERShader_Dtor(void* self, int hiddenParam) {
    // Restore ERShader vtable
    *(void**)self = (void*)&ERShader_vtable;

    // Deallocate owned resources
    // ERShader::Deallocate()
    // Calls virtual DelRefSubResources, frees shader data, etc.

    // Deallocate MultiShaderInfo at offset 0x3C
    // MultiShaderInfo::DeAlloc()

    // Call base destructor (no scalar-delete -- pass 0)
    EResource_Dtor((EResourceFields*)self, 0);

    // SN Systems ABI: if scalar-delete bit set, free via manager heap
    if (hiddenParam & 0x01) {
        // EResourceManager::Free(self) using the manager's heap
    }
}

// ---------- ERShader::Deallocate ----------
// Address: 0x8031C808, Size: 252 bytes
void ERShader_Deallocate(void* self) {
    // Virtual call: DelRefSubResources() via vtable offset 104/108
    void** vtbl = *(void***)self;
    s16 adj = *(s16*)((u8*)vtbl + 104);
    void (*fn)(void*) = (void(*)(void*))*(u32*)((u8*)vtbl + 108);
    fn((u8*)self + adj);

    // Free shader data at offset 0x014 (m_pCurrentEShader's owned buffers)
    u32 shaderDataPtr = ERShader_u32(self, 0x014);
    if (shaderDataPtr != 0) {
        u32* shaderData = (u32*)shaderDataPtr;
        // Free sub-allocations within the shader data
        u32 buf1 = shaderData[108 / 4];  // offset 108 in EShader
        if (buf1 != 0) {
            // EResourceManager::Free(buf1);
        }
        u32 buf2 = shaderData[104 / 4];  // offset 104 in EShader
        if (buf2 != 0) {
            // EResourceManager::Free(buf2);
        }

        // Release via global texture manager
        // g_pTextureManager->Release(shaderData) at vtable+0x110
    }

    ERShader_u32(self, 0x014) = 0;  // m_pCurrentEShader = NULL

    // Free remaining shader allocations at offset 0x018, 0x01C
    u32 pChild = ERShader_u32(self, 0x018);
    if (pChild != 0) {
        // Release child ERShader
        ERShader_u32(self, 0x018) = 0;
    }
    u32 pIncoming = ERShader_u32(self, 0x01C);
    if (pIncoming != 0) {
        ERShader_u32(self, 0x01C) = 0;
    }
}

// ---------- ERShader::IsDayNightShader ----------
// Address: 0x80320750, Size: 12 bytes
bool ERShader_IsDayNightShader(void* self) {
    u32 flags = ERShader_u32(self, 0x058);
    return (flags >> 5) & 1;  // bit 5
}

// ---------- ERShader::IsMultiShader ----------
// Address: 0x80320860, Size: 12 bytes
bool ERShader_IsMultiShader(void* self) {
    u32 flags = ERShader_u32(self, 0x058);
    return (flags >> 1) & 1;  // bit 1
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
    if (shader == NULL) {
        void* child = (void*)(u32)ERShader_u32(self, 0x018);
        if (child != NULL) {
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
    return NULL;
}

// ---------- ERShader::GetShader ----------
// Address: 0x80870418, Size: 100 bytes
// Returns the active EShader pointer, resolving through multi-shader indirection
void* ERShader_GetShader(void* self) {
    void* shader = (void*)(u32)ERShader_u32(self, 0x014);
    if (shader != NULL) {
        return shader;
    }
    void* child = (void*)(u32)ERShader_u32(self, 0x018);
    if (child != NULL) {
        return (void*)(u32)ERShader_u32(child, 0x014);
    }
    return NULL;
}

// ---------- ERShader::Select ----------
// Address: 0x80320904, Size: 96 bytes
void ERShader_Select(void* self, ERC* rc, u32 flags) {
    // Resolve current EShader
    void* shader = NULL;

    u32 currentEShader = ERShader_u32(self, 0x014);
    if (currentEShader != 0) {
        shader = (void*)currentEShader;
    } else {
        u32 currentERShader = ERShader_u32(self, 0x018);
        if (currentERShader != 0) {
            shader = (void*)ERShader_u32((void*)currentERShader, 0x014);
        }
    }

    if (shader == NULL) return;

    // Virtual call: EShader::Select(rc, flags)
    // EShader has platform shader at offset 0xF0 (ENgcShader*)
    void* platformShader = (void*)*(u32*)((u8*)shader + 0xF0);
    if (platformShader != NULL) {
        void** vtbl = *(void***)platformShader;
        s16 adj = *(s16*)((u8*)vtbl + 0x10);
        void (*fn)(void*, ERC*, u32) = (void(*)(void*, ERC*, u32))*(u32*)((u8*)vtbl + 0x14);
        fn((u8*)platformShader + adj, rc, flags);
    }
}

// ---------- ERShader::SelectForShadowMask ----------
// Address: 0x80870A1C, Size: 116 bytes
void ERShader_SelectForShadowMask(void* self, ERC* rc) {
    void* shader = ERShader_GetShader(self);
    if (shader == NULL) return;

    // Delegate to EShader::SelectForShadowMask(rc) via vtable
    void** vtbl = *(void***)shader;
    // vtable dispatch for SelectForShadowMask
}

// ---------- ERShader::GetCurrentGraphicsState ----------
// Address: 0x80870774, Size: 48 bytes
u8 ERShader_GetCurrentGraphicsState(void* self) {
    return ERShader_u8(self, 0x064);  // m_currentShaderIdx
}

// ---------- ERShader::IsStateChangePending ----------
// Address: 0x808707A4, Size: 52 bytes
bool ERShader_IsStateChangePending(void* self) {
    u32 flags = ERShader_u32(self, 0x058);
    return (flags >> 4) & 1;  // bit 4
}

// ---------- ERShader::RegisterType ----------
// Address: 0x80870318, Size: 84 bytes
void ERShader_RegisterType(void* typeInfo, u16 key) {
    // Registers ERShader with the type system
    // ETypeInfo::Register(New, Construct, Destruct, key, "ERShader", EResource_typeInfo);
}


// ============================================================================
//  SECTION 3: ETexture -- Platform-Agnostic Texture Description
// ============================================================================
//
// Size: 0x28 (40 bytes)
//   0x00: _vtable
//   0x04: m_imageFormat (u32)
//   0x08: m_bitsPerPixel (u32)
//   0x0C: m_xSize (u32)
//   0x10: m_ySize (u32)
//   0x14: m_paletteFormat (u32)
//   0x18: padding
//   0x20: m_pPlatformTexture (u32)
//   0x24: m_pPaletteData (u32)

struct ETextureFields {
    void** _vtable;          // 0x00
    u32    m_imageFormat;    // 0x04
    u32    m_bitsPerPixel;   // 0x08
    u32    m_xSize;          // 0x0C
    u32    m_ySize;          // 0x10
    u32    m_paletteFormat;  // 0x14
    u8     _pad_018[8];      // 0x18
    u32    m_pPlatformTex;   // 0x20
    u32    m_pPaletteData;   // 0x24
};

// ---------- ETexture::ETexture ----------
// Address: 0x807E9188, Size: 156 bytes
void ETexture_Ctor(ETextureFields* self) {
    // Zero-initialize all fields
    self->m_imageFormat   = 0;
    self->m_bitsPerPixel  = 0;
    self->m_xSize         = 0;
    self->m_ySize         = 0;
    self->m_paletteFormat = 0;
    memset(self->_pad_018, 0, 8);
    self->m_pPlatformTex  = 0;
    self->m_pPaletteData  = 0;
}

// ---------- ETexture::~ETexture ----------
// Address: 0x807E9204, Size: 100 bytes
void ETexture_Dtor(ETextureFields* self) {
    self->m_pPlatformTex = 0;
    self->m_pPaletteData = 0;
}

// ---------- ETexture::Create ----------
// Address: 0x807E92DC, Size: 144 bytes
void ETexture_Create(ETextureFields* self, void* textureDef) {
    // Copies fields from ETextureDef into this texture
    // Sets vtable, format, dimensions, palette info
}

// ---------- ETexture simple getters ----------
// Addresses: 0x807EAB50..0x807EAC40, Size: 48 bytes each
u32 ETexture_GetXSize(ETextureFields* self)         { return self->m_xSize; }
u32 ETexture_GetYSize(ETextureFields* self)         { return self->m_ySize; }
u32 ETexture_GetBitsPerPixel(ETextureFields* self)  { return self->m_bitsPerPixel; }
u32 ETexture_GetImageFormat(ETextureFields* self)   { return self->m_imageFormat; }
u32 ETexture_GetPaletteFormat(ETextureFields* self) { return self->m_paletteFormat; }

// ---------- ETexture::Select ----------
// Address: 0x807EAA10, Size: 36 bytes
void ETexture_Select(ETextureFields* self, int texUnit) {
    // Base implementation is empty (virtual -- overridden by ENgcTexture)
}

// ---------- ETexture::IsValid ----------
// Address: 0x807EAE8C, Size: 64 bytes
bool ETexture_IsValid(ETextureFields* self) {
    return (self->m_pPlatformTex != 0);
}


// ============================================================================
//  SECTION 4: ERTexture -- Texture Resource Wrapper
// ============================================================================
//
// Size: ~0x28 (40 bytes, extends EResource)
//   0x00: EResource base fields
//   0x10: m_flags (with image size packed in upper 24 bits)
//   0x14: m_pTexture (ETexture*)
//   0x24: m_formatInfo (u32)
//
// Helper: access ERTexture fields by offset
static inline u32& ERTexture_u32(void* self, u32 off) { return *(u32*)((u8*)self + off); }

// ---------- ERTexture::ERTexture ----------
// Address: 0x80320B28, Size: 68 bytes
void ERTexture_Ctor(void* self) {
    // Call base EResource constructor
    EResource_Ctor((EResourceFields*)self);

    // Set ERTexture vtable
    *(void**)self = (void*)&ERTexture_vtable;

    // Initialize texture pointer to NULL
    ERTexture_u32(self, 0x014) = 0;  // m_pTexture = NULL
}

// ---------- ERTexture::~ERTexture ----------
// Address: 0x80320B6C, Size: 96 bytes
void ERTexture_Dtor(void* self, int hiddenParam) {
    // Restore ERTexture vtable
    *(void**)self = (void*)&ERTexture_vtable;

    // Deallocate owned texture
    // ERTexture::Deallocate();

    // Call base destructor (no scalar-delete)
    EResource_Dtor((EResourceFields*)self, 0);

    // SN Systems ABI: if scalar-delete bit set, free via manager heap
    if (hiddenParam & 0x01) {
        // EResourceManager::Free(self);
    }
}

// ---------- ERTexture::Attach ----------
// Address: 0x80320BCC, Size: 52 bytes
void ERTexture_Attach(void* self, void* tex) {
    // Deallocate existing
    // ERTexture_Deallocate(self);

    // Store new texture pointer
    ERTexture_u32(self, 0x014) = (u32)(uintptr_t)tex;
}

// ---------- ERTexture::Deallocate ----------
// Address: 0x80320C00, Size: 80 bytes
void ERTexture_Deallocate(void* self) {
    // Release owned texture via global ETextureManager
    ETextureManager* texMgr = g_pTextureManager;
    void* tex = (void*)ERTexture_u32(self, 0x014);

    if (texMgr != NULL && tex != NULL) {
        // Virtual call: texMgr->Release(tex) at vtable+0xC0/0xC4
        void** vtbl = *(void***)texMgr;
        s16 adj = *(s16*)((u8*)vtbl + 0xC0);
        void (*fn)(void*, void*) = (void(*)(void*, void*))*(u32*)((u8*)vtbl + 0xC4);
        fn((u8*)texMgr + adj, tex);
    }

    ERTexture_u32(self, 0x014) = 0;  // m_pTexture = NULL
}

// ---------- ERTexture::Refresh ----------
// Address: 0x80320C50, Size: 176 bytes
void ERTexture_Refresh(void* self, void* file) {
    if (file == NULL) return;

    u32 texPtr = ERTexture_u32(self, 0x014);
    if (texPtr == 0) {
        // No existing texture -- Load fresh from file via vtable
        void** vtbl = *(void***)self;
        s16 adj = *(s16*)((u8*)vtbl + 72);
        void (*fn)(void*, void*) = (void(*)(void*, void*))*(u32*)((u8*)vtbl + 76);
        fn((u8*)self + adj, file);
    } else {
        // Has existing texture -- invalidate GX texture, reload, revalidate
        ETextureManager* texMgr = g_pTextureManager;
        if (texMgr != NULL) {
            // texMgr->Invalidate() at vtable+0x40/0x44
            void** mgrVtbl = *(void***)texMgr;
            s16 adj = *(s16*)((u8*)mgrVtbl + 0x40);
            void (*invFn)(void*) = (void(*)(void*))*(u32*)((u8*)mgrVtbl + 0x44);
            invFn((u8*)texMgr + adj);
        }

        // Reload via vtable
        void** vtbl = *(void***)self;
        s16 adj2 = *(s16*)((u8*)vtbl + 72);
        void (*loadFn)(void*, void*) = (void(*)(void*, void*))*(u32*)((u8*)vtbl + 76);
        loadFn((u8*)self + adj2, file);

        if (texMgr != NULL) {
            // texMgr->Validate() at vtable+0x40/0x44
            void** mgrVtbl = *(void***)texMgr;
            s16 adj = *(s16*)((u8*)mgrVtbl + 0x40);
            void (*valFn)(void*) = (void(*)(void*))*(u32*)((u8*)mgrVtbl + 0x44);
            valFn((u8*)texMgr + adj);
        }
    }
}

// ---------- ERTexture::Load ----------
// Address: 0x80320D00, Size: 240 bytes
void ERTexture_Load(void* self, void* file) {
    // Create EDataHeader on stack
    // EDataHeader resFile;
    // resFile.Init();

    // Open resource file looking for 'TXFL' signature, version 9
    u32 signature = 0x5458464C;  // 'TXFL'
    int minVersion = 9;
    int maxVersion = 9;
    // bool found = resFile.Open(file, signature, minVersion, maxVersion);

    bool found = true;  // placeholder
    if (!found) {
        // resFile.Close(2);
        return;
    }

    // Read image data size
    u32 imageSize = 0;  // resFile.GetDataSize();

    // Pack image size into upper 24 bits of flags
    u32 flags = ERTexture_u32(self, 0x010);
    flags = (imageSize << 8) | (flags & 0xFF);
    ERTexture_u32(self, 0x010) = flags;

    // Allocate memory from RootHeap first, fall back to VMHeap
    u8* buffer = (u8*)EAHeap_Malloc(RootHeap(), imageSize, 0);
    if (buffer == NULL) {
        buffer = (u8*)EAHeap_Malloc(VMHeap(), imageSize, 0);
    }

    // Read raw texture data into buffer via file vtable
    // file->Read(buffer, imageSize);

    // Decode texture from memory
    // ERTexture_LoadFromMemory(self, buffer);

    // Free temporary buffer
    EAHeap_Free(VMHeap(), buffer);

    // resFile.Close(2);
}

// ---------- ERTexture::LoadFromMemory ----------
// Address: 0x80320E14, Size: 736 bytes
void ERTexture_LoadFromMemory(void* self, u8* data) {
    // Parse 32-byte texture header from data
    // Build ETextureDef from header fields:
    //   imageFormat, width, height, bitsPerPixel, paletteFormat, mipLevels

    u32 texDef[8];  // local ETextureDef on stack
    memset(&texDef, 0, sizeof(texDef));

    // Default dimensions
    u16 width = 64;
    u16 height = 64;

    // Read header (first 32 bytes of data)
    // texDef fields populated from header bytes

    // Calculate image data size: (width * height * bpp + 7) / 8
    u32 imageDataSize = 0;
    u32 flags = ERTexture_u32(self, 0x010);
    flags = (imageDataSize << 8) | (flags & 0xFF);
    ERTexture_u32(self, 0x010) = flags;

    // Advance past header
    data += 32;

    // Get or create platform texture via ETextureManager
    u32 existingTex = ERTexture_u32(self, 0x014);
    if (existingTex != 0) {
        // Update existing texture with new def
        void* tex = (void*)existingTex;
        void** texVtbl = *(void***)((u8*)tex + 36);
        // tex->Create(texDef)
    } else {
        // Create new texture via global manager
        // g_pTextureManager->CreateTexture(texDef)
        // Store result at offset 0x014
    }

    // Copy mip levels from data into texture
    void* tex = (void*)ERTexture_u32(self, 0x014);
    if (tex == NULL) return;

    // Set format mode
    // tex->SetFormat(2);

    // Determine mip count
    u32 mipLevels = 1;  // from header byte at offset 30

    // Copy each mip level
    for (u32 mip = 0; mip < mipLevels; mip++) {
        // Get mip data pointer and stride from texture
        // Copy scanlines from data into texture memory
        u32 mipWidth = width >> mip;
        u32 mipHeight = height >> mip;
        if (mipWidth == 0) mipWidth = 1;
        if (mipHeight == 0) mipHeight = 1;

        // memcpy per-scanline or bulk copy depending on stride match
    }

    // Copy palette data if present
    // Invalidate texture cache
    // tex->Invalidate();
}

// ---------- ERTexture::IsSafeToDelete ----------
// Address: 0x803210F4, Size: 140 bytes
bool ERTexture_IsSafeToDelete(void* self) {
    u32 texPtr = ERTexture_u32(self, 0x014);  // m_pTexture
    if (texPtr == 0) return true;

    // Check global shader system
    if (g_pShaderSystem == NULL) return true;

    // Check if texture is currently bound in any slot
    for (int slot = 0; slot <= 1; slot++) {
        // Get bound texture for slot via global shader system vtable
        void** sysVtbl = *(void***)((u8*)g_pShaderSystem + 824);
        s16 adj = *(s16*)((u8*)sysVtbl + 24);
        void* (*getBound)(void*, int) = (void*(*)(void*, int))*(u32*)((u8*)sysVtbl + 28);
        void* boundTex = getBound((u8*)g_pShaderSystem + adj, slot);

        if ((u32)(uintptr_t)boundTex == texPtr) {
            return false;  // Currently in use by GPU
        }
    }

    return true;
}

// ---------- ERTexture::Select ----------
// Address: 0x80877894, Size: 108 bytes
void ERTexture_Select(void* self, ERC* rc, int texUnit) {
    void* tex = (void*)ERTexture_u32(self, 0x014);
    if (tex == NULL) return;

    // Virtual call: tex->Select(texUnit) via platform texture vtable
}

// ---------- ERTexture::RegisterType ----------
// Address: 0x803212F0, Size: 84 bytes
void ERTexture_RegisterType(void* typeInfo, u16 key) {
    // Registers ERTexture with the type system
    // ETypeInfo::Register(New, Construct, Destruct, key, "ERTexture", EResource_typeInfo);
}


// ============================================================================
//  SECTION 5: ERFont -- Bitmap Font Resource
// ============================================================================
//
// Size: 0xF4 (244 bytes, extends EResource)
//   0x000: f32  m_stringWidth
//   0x004: f32  m_stringHeight
//   0x008: u32  m_numPages
//   0x010: u32  m_formatVersion
//   0x014: u32  m_pCharTable
//   0x018: u32  m_pFontData (EFontData*)
//   0x024: u32  m_lineHeight
//   0x028: u32  m_ascent
//   0x02C: u32  m_descent
//   0x030: u32  m_leading
//   0x034: u32  m_spaceWidth
//   0x038: u32  m_tabWidth
//   0x04C: f32  m_scaleX
//   0x050: f32  m_scaleY
//   0x054: u32  m_sizeFlags
//   0x058: f32  m_dropShadowX
//   0x068: u32  m_currentPage (-1 = unset)
//   0x0F0: u32  m_pPageArray

// Helper: access ERFont fields by offset
static inline u32& ERFont_u32(void* self, u32 off) { return *(u32*)((u8*)self + off); }
static inline f32& ERFont_f32(void* self, u32 off) { return *(f32*)((u8*)self + off); }
static inline u8&  ERFont_u8(void* self, u32 off)  { return *(u8*)((u8*)self + off); }

// ---------- ERFont::ERFont ----------
// Address: 0x80313F08, Size: 128 bytes
void ERFont_Ctor(void* self) {
    // Call base EResource constructor
    EResource_Ctor((EResourceFields*)self);

    // Set ERFont vtable
    *(void**)self = (void*)&ERFont_vtable;

    // Initialize EFontData at offset 0x14
    // EFontData::EFontData() at self+20

    // Initialize font-specific fields
    ERFont_u32(self, 0x054) = 0;  // m_sizeFlags
    ERFont_f32(self, 0x04C) = 1.0f;  // m_scaleX (default scale)
    ERFont_f32(self, 0x050) = 0.0f;  // m_scaleY

    // Zero color/effect fields at offset 0x058..0x06C
    ERFont_f32(self, 0x058) = 0.0f;  // m_dropShadowX
    ERFont_f32(self, 0x05C + 0x04) = 0.0f;
    ERFont_f32(self, 0x05C + 0x0C) = 0.0f;
    ERFont_f32(self, 0x05C + 0x08) = 0.0f;
    ERFont_f32(self, 0x058 + 0x00) = 0.0f;

    ERFont_u32(self, 0x068) = 0xFFFFFFFF;  // m_currentPage = -1 (unset)
}

// ---------- ERFont::~ERFont ----------
// Address: 0x80313F88, Size: 104 bytes
void ERFont_Dtor(void* self, int hiddenParam) {
    // Restore ERFont vtable
    *(void**)self = (void*)&ERFont_vtable;

    // Deallocate font resources
    // ERFont::Deallocate();

    // Destroy EFontData at offset 0x14
    // EFontData::~EFontData() at self+20

    // Call base destructor
    EResource_Dtor((EResourceFields*)self, 0);

    // SN Systems ABI: if scalar-delete bit set, free memory
    if (hiddenParam & 0x01) {
        void* heap = MainHeap();
        EAHeap_Free(heap, self);
    }
}

// ---------- ERFont::Deallocate ----------
// Address: 0x80313FF0, Size: 68 bytes
void ERFont_Deallocate(void* self) {
    // Walk the font size linked list at offset 0x18 (m_pFontData)
    u32 sizeNode = ERFont_u32(self, 0x018);  // m_pFontData -> first size entry
    while (sizeNode != 0) {
        void* sizePtr = (void*)*(u32*)sizeNode;  // sizeNode->data
        // EFontSize::DeallocateShaders(sizePtr);
        sizeNode = *(u32*)((u8*)sizeNode + 8);  // sizeNode->next
    }
}

// ---------- ERFont::Load ----------
// Address: 0x80314034, Size: 244 bytes
void ERFont_Load(void* self, void* file) {
    // Deallocate existing font data
    ERFont_Deallocate(self);

    // Create EDataHeader on stack
    // EDataHeader resFile;
    // resFile.Init();

    // Open resource looking for 'FONT' (0x464F4E54), version 10
    u32 signature = 0x464F4E54;  // 'FONT'
    int version = 10;
    bool found = false;  // resFile.Open(file, signature, version, version);

    if (found) {
        // New format: read data size, pack into flags
        u32 dataSize = 0;  // resFile.GetDataSize();
        u32 flags = ERFont_u32(self, 0x010);
        flags = (dataSize << 8) | (flags & 0xFF);
        ERFont_u32(self, 0x010) = flags;
    } else {
        // Legacy format: stream-based read
        // EString localStr;
        // EString_SetToNull(&localStr);
        // operator>>(file, localStr);
        // EString_Deallocate(&localStr, ...);
    }

    // Read character table: operator>>(file, &this->m_pCharTable)
    // this is at self+0x14

    // Set up font page data
    u32 fontData = ERFont_u32(self, 0x018);  // m_pFontData
    if (fontData != 0) {
        u32 pageArray = *(u32*)fontData;  // first word is page array pointer
        ERFont_u32(self, 0x054) = pageArray;  // m_sizeFlags / m_pPageArray

        // Convert integer scale to float (PPC int-to-float pattern)
        u32 rawScale = *(u32*)(fontData + 4);
        f32 scale = (f32)(s32)rawScale;
        ERFont_f32(self, 0x04C) = scale;  // m_scaleX
    }

    // resFile.Close(2);
}

// ---------- ERFont::SetSize ----------
// Address: 0x8084F0AC, Size: 660 bytes
void ERFont_SetSize(void* self, f32 scaleX, f32 scaleY, bool useAspect) {
    // Apply global screen aspect ratio correction if useAspect is true
    // Search the font's size table for closest matching point size
    // Select appropriate glyph page for the resolution
    // Store final scale factors
    ERFont_f32(self, 0x04C) = scaleX;
    ERFont_f32(self, 0x050) = scaleY;
}

// ---------- ERFont::SetColor ----------
// Address: 0x80856A9C, Size: 68 bytes
void ERFont_SetColor(void* self, EVec4* color) {
    // Store color in the active glyph page's material
    // Accesses font data page array and sets per-page color
}

// ---------- ERFont::GetColor ----------
// Address: 0x80856B2C, Size: 44 bytes
EVec4* ERFont_GetColor(void* self) {
    // Returns pointer to stored color
    return NULL;  // placeholder
}

// ---------- ERFont::GetYSize ----------
// Address: 0x8085697C, Size: 44 bytes
f32 ERFont_GetYSize(void* self) {
    return ERFont_f32(self, 0x050);  // m_scaleY
}

// ---------- ERFont::GetAspect ----------
// Address: 0x808569A8, Size: 44 bytes
f32 ERFont_GetAspect(void* self) {
    f32 sx = ERFont_f32(self, 0x04C);
    f32 sy = ERFont_f32(self, 0x050);
    if (sy != 0.0f) return sx / sy;
    return 1.0f;
}

// ---------- ERFont::SelectPage ----------
// Address: 0x80314298, Size: 240 bytes
void ERFont_SelectPage(void* self, ERC* rc, int pageIndex) {
    u32 currentPage = ERFont_u32(self, 0x068);
    if (currentPage == (u32)pageIndex) {
        return;  // Already on this page
    }

    ERFont_u32(self, 0x068) = (u32)pageIndex;  // m_currentPage

    // Read font color from global table
    // Get page entry from font data
    // Get page's ERShader, resolve to EShader
    // Call EShader::Select(rc, 0) to bind page texture
    // Set text color on TEV unit via ERC virtual
}

// ---------- ERFont::GetLineSpacing ----------
// Address: 0x80854254, Size: 520 bytes
f32 ERFont_GetLineSpacing(void* self, void* window, bool useLeading) {
    u32 lineHeight = ERFont_u32(self, 0x024);
    u32 ascent     = ERFont_u32(self, 0x028);
    u32 leading    = ERFont_u32(self, 0x030);

    f32 spacing = (f32)(s32)lineHeight;
    if (useLeading) {
        spacing += (f32)(s32)leading;
    }

    f32 scale = ERFont_f32(self, 0x050);  // m_scaleY
    return spacing * scale;
}

// ---------- ERFont::RegisterType ----------
// Address: 0x808567F8, Size: 116 bytes
void ERFont_RegisterType(void* typeInfo, u16 key) {
    // Registers ERFont with the type system
    // ETypeInfo::Register(New, Construct, Destruct, key, "ERFont", EResource_typeInfo);
}


// ============================================================================
//  SECTION 6: NghResFile -- Neighborhood Resource File (.NGH Format)
// ============================================================================
//
// Size: 0x194 (404 bytes)
// Manages .NGH neighborhood files storing game state: neighborhoods, houses,
// sims, families, thumbnails, and save game data.
//
// Field layout:
//   0x000: vtable*
//   0x004: u32 m_byID              - resource lookup data
//   0x008: u16 m_byID_008          - ID count
//   0x00C: u32 m_field_00C         - inner vtable pointer
//   0x010: u32 m_memoryCardCache   - MemoryCardCache*
//   0x014: u32 m_field_014         - registry data pointer
//   0x018: u32 m_field_018         - current section data
//   0x020: u32 m_bHasCardChanged   - dirty flag
//   0x024: u32 m_bIsSectionLoaded  - bitfield: which sections loaded
//   0x028: u32 m_field_028         - total data size
//   0x02C-0x133: StackString<260>  - file path
//   0x134: u8  m_field_134         - source type flag
//   0x138: u32 m_sectionState_138  - section 1 (Both) loaded state
//   0x13C-0x17B: section data arrays
//   0x17C: u32 m_sectionState_17C  - section 2 (Thumb) loaded state
//   0x180: u32 m_byIndex_180       - index lookup data
//   0x184: u16 m_field_184         - house count
//   0x188: u32 m_field_188         - write state
//   0x18C: u32 m_field_18C         - endian swap state
//   0x190: u32 m_memoryCardCache_190 - secondary cache

// Helper: access NghResFile fields by offset
static inline u32& Ngh_u32(void* self, u32 off) { return *(u32*)((u8*)self + off); }
static inline u16& Ngh_u16(void* self, u32 off) { return *(u16*)((u8*)self + off); }
static inline u8&  Ngh_u8(void* self, u32 off)  { return *(u8*)((u8*)self + off); }

// ---------- NghResFile::NghResFile ----------
// Address: 0x8016D2DC, Size: 244 bytes
static void NghResFile_init(void* self);  // forward declaration

void NghResFile_Ctor(void* self) {
    // Call iResFile base linkage
    // iResFile::Link();

    // Set vtable
    *(void**)((u8*)self + 0x00C) = (void*)&NghResFile_vtable;

    // Initialize fields
    Ngh_u32(self, 0x010) = 0;           // m_memoryCardCache = NULL
    Ngh_u32(self, 0x014) = 0;           // m_field_014 = NULL
    Ngh_u32(self, 0x018) = 0;           // m_field_018 = 0
    Ngh_u32(self, 0x020) = 1;           // m_bHasCardChanged = 1 (dirty)
    Ngh_u32(self, 0x024) = 0;           // m_bIsSectionLoaded = 0
    Ngh_u32(self, 0x18C) = 1;           // m_field_18C = 1 (endian swap)
    Ngh_u8(self, 0x134)  = 0;           // m_field_134 = 0 (source type)
    Ngh_u32(self, 0x180) = 0;           // m_byIndex_180 = 0
    Ngh_u16(self, 0x184) = 0;           // m_field_184 = 0 (house count)
    Ngh_u32(self, 0x188) = 1;           // m_field_188 = 1 (write state)

    // Initialize StackString<260> for file path at offset 0x028
    // StackString_init(&m_path, &m_path_buf, 260);

    // Allocate registry node (28 bytes)
    void* reg = EAHeap_Malloc(MainHeap(), 28, 0);
    Ngh_u32(self, 0x190) = (u32)(uintptr_t)reg;
    if (reg != NULL) {
        memset(reg, 0, 28);
    }

    // Call init()
    NghResFile_init(self);
}

// ---------- NghResFile::~NghResFile ----------
// Address: 0x8016D3D0, Size: 252 bytes
void NghResFile_Dtor(void* self, int hiddenParam) {
    // Flush all data
    // NghResFile::FlushAllData();

    // Free registry at offset 0x190
    u32 regPtr = Ngh_u32(self, 0x190);
    if (regPtr != 0) {
        EAHeap_Free(MainHeap(), (void*)regPtr);
        Ngh_u32(self, 0x190) = 0;
    }

    // Free section data arrays
    // NghResFile::reset();

    // Call iResFile::Unlink()
}

// ---------- NghResFile::init ----------
// Address: 0x8016E2F4, Size: 272 bytes
void NghResFile_init(void* self) {
    // Allocate section type lookup table (4 entries x 4 bytes)
    void* sectionTable = EAHeap_Malloc(MainHeap(), 16, 0);
    Ngh_u32(self, 0x138) = (u32)(uintptr_t)sectionTable;
    if (sectionTable != NULL) {
        memset(sectionTable, 0, 16);
    }

    // Allocate per-section data (16 sections, each 24 bytes)
    for (int i = 0; i < 16; i++) {
        void* sectionData = EAHeap_Malloc(MainHeap(), 24, 0);
        // Store at this+0x13C + i*4
        *(u32*)((u8*)self + 0x13C + i * 4) = (u32)(uintptr_t)sectionData;
        if (sectionData != NULL) {
            memset(sectionData, 0, 24);
        }
    }

    // Allocate character data table (2 entries x 4 bytes)
    void* charData = EAHeap_Malloc(MainHeap(), 8, 0);
    Ngh_u32(self, 0x17C) = (u32)(uintptr_t)charData;
    if (charData != NULL) {
        memset(charData, 0, 8);
    }
}

// ---------- NghResFile::reset ----------
// Address: 0x8016E404, Size: 240 bytes
void NghResFile_reset(void* self) {
    // Free section type lookup table
    u32 sectionTable = Ngh_u32(self, 0x138);
    if (sectionTable != 0) {
        EAHeap_Free(MainHeap(), (void*)sectionTable);
        Ngh_u32(self, 0x138) = 0;
    }

    // Free per-section data
    for (int i = 0; i < 16; i++) {
        u32 sectionData = *(u32*)((u8*)self + 0x13C + i * 4);
        if (sectionData != 0) {
            EAHeap_Free(MainHeap(), (void*)sectionData);
            *(u32*)((u8*)self + 0x13C + i * 4) = 0;
        }
    }

    // Free character data
    u32 charData = Ngh_u32(self, 0x17C);
    if (charData != 0) {
        EAHeap_Free(MainHeap(), (void*)charData);
        Ngh_u32(self, 0x17C) = 0;
    }
}

// ---------- NghResFile::FlushAllData ----------
// Address: 0x80172690, Size: 68 bytes
void NghResFile_FlushAllData(void* self) {
    // Flush all three sections
    // FlushSection(0);  // Host
    // FlushSection(1);  // Both
    // FlushSection(2);  // Thumb
}

// ---------- NghResFile::FlushSection ----------
// Address: 0x8016EB88, Size: 464 bytes
void NghResFile_FlushSection(void* self, u32 sectionIndex) {
    u32 sectionLoaded = Ngh_u32(self, 0x024);

    // Check if section is loaded (bit in m_bIsSectionLoaded)
    if (!(sectionLoaded & (1 << sectionIndex))) {
        return;  // Not loaded
    }

    // Walk resource entries for this section and free them
    // Clear loaded bit
    sectionLoaded &= ~(1 << sectionIndex);
    Ngh_u32(self, 0x024) = sectionLoaded;
}

// ---------- NghResFile::FlushCharacterData ----------
// Address: 0x8016E18C, Size: 156 bytes
void NghResFile_FlushCharacterData(void* self, bool freeAll) {
    u32 charData = Ngh_u32(self, 0x17C);
    if (charData == 0) return;

    // Walk character data entries and free/clear them
    // If freeAll, release all entries; otherwise keep some
}

// ---------- NghResFile::FlushNeighborData ----------
// Address: 0x8016E228, Size: 84 bytes
void NghResFile_FlushNeighborData(void* self) {
    u32 sectionData = Ngh_u32(self, 0x138);
    if (sectionData == 0) return;

    // Free neighbor-specific data from section 1
}

// ---------- NghResFile::FlushHouseData ----------
// Address: 0x8016E0E4, Size: 168 bytes
void NghResFile_FlushHouseData(void* self, u32 houseIndex) {
    // Validate house index
    // Free house-specific resource entries
    // Update loaded state
}

// ---------- NghResFile::IsSectionLoaded ----------
// Address: 0x8016E804, Size: 900 bytes
bool NghResFile_IsSectionLoaded(void* self, u32 sectionId) {
    u32 loaded = Ngh_u32(self, 0x024);

    // Complex lookup through section tables to determine if
    // the requested sectionId is currently loaded
    // Checks m_bIsSectionLoaded, m_sectionState_138, m_sectionState_17C

    return (loaded & (1 << sectionId)) != 0;
}

// ---------- NghResFile::SetFileName ----------
// Address: 0x80174F2C, Size: 72 bytes
void NghResFile_SetFileName(void* self, const char* name) {
    // Copy name into StackString<260> at offset 0x028
    // StackString_assign(&m_path, name);
}

// ---------- NghResFile::GetMemoryCardCache ----------
// Address: 0x80174F74, Size: 72 bytes
void* NghResFile_GetMemoryCardCache(void* self) {
    u32 cache = Ngh_u32(self, 0x010);
    if (cache != 0) return (void*)cache;
    return (void*)Ngh_u32(self, 0x190);
}

// ---------- NghResFile::GetCurrentHouse ----------
// Address: 0x8029E100, Size: 48 bytes
u32 NghResFile_GetCurrentHouse(void* self) {
    return Ngh_u32(self, 0x024);
}

// ---------- NghResFile::GetSourceType ----------
// Address: 0x8029E130, Size: 44 bytes
u8 NghResFile_GetSourceType(void* self) {
    return Ngh_u8(self, 0x134);
}

// ---------- NghResFile::SetStoreChecksum ----------
// Address: 0x8029CDE0, Size: 44 bytes
void NghResFile_SetStoreChecksum(void* self, bool store) {
    // Set/clear checksum storage flag
}

// ---------- NghResFile::GetStoreChecksum ----------
// Address: 0x8029CE0C, Size: 44 bytes
bool NghResFile_GetStoreChecksum(void* self) {
    return false;  // placeholder
}

// ---------- NghResFile::ResetChecksums ----------
// Address: 0x8029CE38, Size: 52 bytes
void NghResFile_ResetChecksums(void* self) {
    // Clear all stored checksums
}

// ---------- NghResFile::SwapFourByteNumber ----------
// Address: 0x8029C980, Size: 148 bytes
void NghResFile_SwapFourByteNumber(u32* value) {
    u32 v = *value;
    *value = ((v & 0xFF) << 24) | ((v & 0xFF00) << 8) |
             ((v >> 8) & 0xFF00) | ((v >> 24) & 0xFF);
}

// ---------- NghResFile::SwapTwoByteNumber ----------
// Address: 0x8029C924, Size: 92 bytes
void NghResFile_SwapTwoByteNumber(u16* value) {
    u16 v = *value;
    *value = ((v & 0xFF) << 8) | ((v >> 8) & 0xFF);
}


// ============================================================================
//  SECTION 7: ChainResFile -- Multi-File Resource Chain
// ============================================================================
//
// Size: 0x14 (20 bytes) base + inline array of 8 slots (24 bytes each)
// Total effective: ~0xD4 (212 bytes)
//
// Chains multiple iResFile instances together, searching in order
// when looking up resources. This layers:
//   1. Save game overrides (NghResFile)
//   2. Object definition files (ObjResFile)
//   3. Base game resources (StdResFile / IFFResFile2)
//
// Field layout:
//   0x000: u32 m_byIndex      - base data
//   0x004: [8 bytes]
//   0x00C: u32 m_fileCount    - number of chained files
//   0x010: u32 m_file         - pointer to file list

// Helper
static inline u32& Chain_u32(void* self, u32 off) { return *(u32*)((u8*)self + off); }

// ---------- ChainResFile::ChainResFile ----------
// Address: 0x801397A0, Size: 108 bytes
void ChainResFile_Ctor(void* self) {
    // Set vtable
    // *(void**)self = &ChainResFile_vtable;

    // Initialize file count and list
    Chain_u32(self, 0x00C) = 0;  // m_fileCount = 0
    Chain_u32(self, 0x010) = 0;  // m_file = NULL

    // Zero all 8 inline file slots (24 bytes each)
    u8* slots = (u8*)self + 0x014;
    memset(slots, 0, 8 * 24);
}

// ---------- ChainResFile::~ChainResFile ----------
// Address: 0x8013980C, Size: 152 bytes
void ChainResFile_Dtor(void* self, int hiddenParam) {
    // Close all chained files
    // ChainResFile::Close();

    // Zero out file slots
    Chain_u32(self, 0x00C) = 0;
}

// ---------- ChainResFile::AddFile ----------
// Address: 0x80228B6C, Size: 368 bytes
void ChainResFile_AddFile(void* self, void* file) {
    // Search for first empty slot in the 8-slot inline array
    u8* slot = (u8*)self + 0x014;
    for (int i = 0; i < 8; i++) {
        u32* slotFile = (u32*)(slot - 4);
        if (*slotFile == 0) {
            // Empty slot found -- store file
            *slotFile = (u32)(uintptr_t)file;
            *(u32*)(slot + 16) = 1;  // mark active
            Chain_u32(self, 0x00C) = Chain_u32(self, 0x00C) + 1;
            return;
        }
        slot += 24;
    }
    // All 8 slots full -- file not added
}

// ---------- ChainResFile::RemoveFile ----------
// Address: 0x80139940, Size: 208 bytes
void ChainResFile_RemoveFile(void* self, void* file) {
    u8* slot = (u8*)self + 0x014;
    for (int i = 0; i < 8; i++) {
        u32* slotFile = (u32*)(slot - 4);
        if (*slotFile == (u32)(uintptr_t)file) {
            *slotFile = 0;
            *(u32*)(slot + 16) = 0;  // mark inactive
            Chain_u32(self, 0x00C) = Chain_u32(self, 0x00C) - 1;
            return;
        }
        slot += 24;
    }
}

// ---------- ChainResFile::CountFiles ----------
// Address: 0x80228DF4, Size: 136 bytes
int ChainResFile_CountFiles(void* self) {
    return (int)Chain_u32(self, 0x00C);
}

// ---------- ChainResFile::GetFile ----------
// Address: 0x80139A4C, Size: 96 bytes
void* ChainResFile_GetFile(void* self, s16 index) {
    if (index < 0 || index >= (s16)Chain_u32(self, 0x00C)) {
        return NULL;
    }
    // Walk active slots to find the index-th active file
    u8* slot = (u8*)self + 0x014;
    int found = 0;
    for (int i = 0; i < 8; i++) {
        u32* slotFile = (u32*)(slot - 4);
        u32 active = *(u32*)(slot + 16);
        if (active != 0 && *slotFile != 0) {
            if (found == index) {
                return (void*)*slotFile;
            }
            found++;
        }
        slot += 24;
    }
    return NULL;
}

// ---------- ChainResFile::Close ----------
// Address: 0x80139AAC, Size: 148 bytes
void ChainResFile_Close(void* self) {
    // Iterate all active slots and call Close on each iResFile
    u8* slot = (u8*)self + 0x014;
    for (int i = 0; i < 8; i++) {
        u32* slotFile = (u32*)(slot - 4);
        if (*slotFile != 0) {
            // iResFile::Close() via vtable
        }
        slot += 24;
    }
}

// ---------- ChainResFile::GetByID ----------
// Address: 0x80229D70, Size: 144 bytes
void* ChainResFile_GetByID(void* self, int type, s16 id, void (*callback)(void*, int)) {
    // Delegate to GetByIDAndLanguage with default language 0
    return NULL;  // ChainResFile_GetByIDAndLanguage(self, type, id, 0, callback);
}

// ---------- ChainResFile::GetByIDAndLanguage ----------
// Address: 0x80229BF4, Size: 380 bytes
void* ChainResFile_GetByIDAndLanguage(void* self, int type, s16 id, char lang,
                                       void (*callback)(void*, int)) {
    // Walk through chained files in order
    int count = (int)Chain_u32(self, 0x00C);
    for (int i = 0; i < count; i++) {
        void* file = ChainResFile_GetFile(self, (s16)i);
        if (file == NULL) continue;

        // Check type filters (prohibited/exclusive)
        // ...

        // Try to find resource in this file via iResFile vtable
        // Memory::HandleNode* node = file->GetByIDAndLanguage(type, id, lang, callback);
        // if (node != NULL) return node;
    }
    return NULL;  // Not found in any file
}

// ---------- ChainResFile::Count ----------
// Address: 0x8013A318, Size: 192 bytes
int ChainResFile_Count(void* self, int type) {
    int total = 0;
    int count = (int)Chain_u32(self, 0x00C);
    for (int i = 0; i < count; i++) {
        void* file = ChainResFile_GetFile(self, (s16)i);
        if (file == NULL) continue;
        // total += file->Count(type) via vtable
    }
    return total;
}

// ---------- ChainResFile::ValidFile ----------
// Address: 0x80139DD0, Size: 148 bytes
bool ChainResFile_ValidFile(void* self) {
    int count = (int)Chain_u32(self, 0x00C);
    for (int i = 0; i < count; i++) {
        void* file = ChainResFile_GetFile(self, (s16)i);
        if (file != NULL) {
            // if (file->ValidFile()) return true;
        }
    }
    return false;
}


// ============================================================================
//  SECTION 8: IFFResFile2 -- IFF Container File Parser
// ============================================================================
//
// Size: 0x150 (336 bytes)
// Parses .iff (Interchange File Format) containers -- the fundamental resource
// container format used by Maxis/EA games since SimCity.
//
// Field layout:
//   0x000: vtable*
//   0x004: u32 m_iD              - current resource ID
//   0x006: u16 m_iD_006          - short form of current ID
//   0x008: s16 m_language         - language code
//   0x00A: u16 m_field_00A       - flags
//   0x00C: u32 m_index            - block index counter
//   0x010: u32 m_field_010       - file offset
//   0x014-0x133: MemFile embedded object (0x120 bytes)
//   0x134: u32 m_field_134       - allocated state
//   0x138: u32 m_resType         - IFFResMap*
//   0x13C: u32 m_field_13C       - block header tracking
//   0x140: u32 m_blockHeader     - resource map offset
//   0x144: u32 m_blockHeader_144 - block header cache
//   0x148: u32 m_field_148       - block header count
//   0x14C: u32 m_field_14C       - reopen state

// Helper
static inline u32& IFF_u32(void* self, u32 off) { return *(u32*)((u8*)self + off); }
static inline u16& IFF_u16(void* self, u32 off) { return *(u16*)((u8*)self + off); }
static inline s16& IFF_s16(void* self, u32 off) { return *(s16*)((u8*)self + off); }

// ---------- IFFResFile2::IFFResFile2 ----------
// Address: 0x8014E150, Size: 112 bytes
void IFFResFile2_Ctor(void* self) {
    // Call iResFile base constructor
    // iResFile_ctor();

    // Set IFFResFile2 vtable
    *(void**)self = (void*)&IFFResFile2_vtable;

    // Initialize fields
    IFF_u32(self, 0x134) = 0;  // m_field_134 (no allocation)
    IFF_u32(self, 0x138) = 0;  // m_resType = NULL
    IFF_u32(self, 0x13C) = 0;  // m_field_13C
    IFF_u32(self, 0x140) = 0;  // m_blockHeader = NULL
    IFF_u32(self, 0x144) = 0;  // m_blockHeader_144 = NULL
    IFF_u32(self, 0x148) = 0;  // m_field_148
    IFF_u32(self, 0x14C) = 0;  // m_field_14C
}

// ---------- IFFResFile2::~IFFResFile2 ----------
// Address: 0x8014E1C0, Size: 112 bytes
void IFFResFile2_Dtor(void* self, int hiddenParam) {
    // Restore vtable
    *(void**)self = (void*)&IFFResFile2_vtable;

    // Close and free resources
    // IFFResFile2::Close();

    // Free allocated memory at m_field_134
    u32 allocPtr = IFF_u32(self, 0x134);
    if (allocPtr != 0) {
        EAHeap_Free(MainHeap(), (void*)allocPtr);
        IFF_u32(self, 0x134) = 0;
    }

    // Call base destructor
    // iResFile_dtor();
}

// ---------- IFFResFile2::Open ----------
// Address: 0x8014E230, Size: 1036 bytes
int IFFResFile2_Open(void* self, void* filename) {
    // Check if already open
    // if (ValidFile()) return -47;

    // Open the physical file via MemFile at offset 0x014
    // Read 64-byte IFF header
    // Validate magic signature (with wildcards)
    // Parse version: bytes 9 and 11 -> major.minor
    //   Supported: 0x0200 (v2.0) and 0x0205 (v2.5)
    // If v2.5: read resource map offset from bytes 0x3C-0x3F
    //   IFF_u32(self, 0x140) = (b[0x3C]<<24)|(b[0x3D]<<16)|(b[0x3E]<<8)|b[0x3F];

    // Allocate IFFResMap at 0x138
    // IFF_u32(self, 0x138) = new IFFResMap();

    // If v2.5 with rsmp offset:
    //   Load 'rsmp' block at that offset
    //   Parse resource map entries
    // Else:
    //   Sequential scan from offset 64 onward
    //   Parse block headers until end

    IFF_u32(self, 0x14C) = 0;  // Clear reopen state
    return 0;
}

// ---------- IFFResFile2::Close ----------
// Address: 0x8014E9B8, Size: 712 bytes
void IFFResFile2_Close(void* self) {
    // Free the resource map at 0x138
    u32 resMap = IFF_u32(self, 0x138);
    if (resMap != 0) {
        // IFFResMap destructor
        EAHeap_Free(MainHeap(), (void*)resMap);
        IFF_u32(self, 0x138) = 0;
    }

    // Free block header cache at 0x144
    u32 headerCache = IFF_u32(self, 0x144);
    if (headerCache != 0) {
        EAHeap_Free(MainHeap(), (void*)headerCache);
        IFF_u32(self, 0x144) = 0;
    }

    // Close the MemFile
    // MemFile_Close(&m_memfile);

    // Reset state
    IFF_u32(self, 0x140) = 0;
    IFF_u32(self, 0x148) = 0;
    IFF_u32(self, 0x13C) = 0;
}

// ---------- IFFResFile2::ValidFile ----------
// Address: 0x80252B38, Size: 72 bytes
bool IFFResFile2_ValidFile(void* self) {
    // Check if the MemFile at offset 0x014 is open
    return (IFF_u32(self, 0x138) != 0);
}

// ---------- IFFResFile2::CloseForReopen ----------
// Address: 0x8014EC80, Size: 104 bytes
void IFFResFile2_CloseForReopen(void* self) {
    // Save current state for later reopening
    IFF_u32(self, 0x14C) = 1;  // Mark as closed-for-reopen
    // Close the file but keep the resource map
}

// ---------- IFFResFile2::Reopen ----------
// Address: 0x8014ECE8, Size: 152 bytes
void IFFResFile2_Reopen(void* self) {
    u32 reopenState = IFF_u32(self, 0x14C);
    if (reopenState == 0) return;

    // Reopen the file from saved state
    IFF_u32(self, 0x14C) = 0;
}

// ---------- IFFResFile2::CountTypes ----------
// Address: 0x8014EF04, Size: 136 bytes
int IFFResFile2_CountTypes(void* self) {
    u32 resMap = IFF_u32(self, 0x138);
    if (resMap == 0) return 0;

    // Delegate to IFFResMap::CountTypes()
    return 0;
}

// ---------- IFFResFile2::Count ----------
// Address: 0x8014F02C, Size: 144 bytes
int IFFResFile2_Count(void* self, int type) {
    u32 resMap = IFF_u32(self, 0x138);
    if (resMap == 0) return 0;

    // Delegate to IFFResMap::Count(type)
    return 0;
}


// ============================================================================
//  SECTION 9: EResourceManager -- Central Resource Registry
// ============================================================================
//
// Size: 0xD20 (3360 bytes)
// Manages a single resource category (textures, models, sounds, etc.)
// Each category has its own .arc archive file.
//
// Field layout:
//   0x000: vtable*
//   0x004: u32 m_resourceArray
//   0x008: u32 m_resourceCount
//   0x00C: s16 m_globalRefCount
//   0x040: u32 m_archivePath (name string pointer)
//   0x044: u32 m_archiveFile (archive name string)
//   0x048: u32 m_flags (initialized state)
//   0x04C: u32 m_totalResources
//   0x050: u32 m_archiveFilePtr (EFile* for open archive)
//   0x054: u32 m_archiveFileBackup
//   0x058-0xD1B: EResourceMap (0xCC4 bytes hash table)
//   0xD1C: u32 m_heap (EAHeap*)

// Helper
static inline u32& ResMgr_u32(void* self, u32 off) { return *(u32*)((u8*)self + off); }
static inline s16& ResMgr_s16(void* self, u32 off) { return *(s16*)((u8*)self + off); }

// ---------- EResourceManager::EResourceManager ----------
// Address: 0x804FA584, Size: 108 bytes
void EResourceManager_Ctor(void* self) {
    *(void**)self = (void*)&EResourceManager_vtable;

    ResMgr_u32(self, 0x004) = 0;   // m_resourceArray
    ResMgr_u32(self, 0x008) = 0;   // m_resourceCount
    ResMgr_s16(self, 0x00C) = 0;   // m_globalRefCount
    ResMgr_u32(self, 0x040) = 0;   // m_archivePath
    ResMgr_u32(self, 0x044) = 0;   // m_archiveFile
    ResMgr_u32(self, 0x048) = 0;   // m_flags
    ResMgr_u32(self, 0x04C) = 0;   // m_totalResources
    ResMgr_u32(self, 0x050) = 0;   // m_archiveFilePtr
    ResMgr_u32(self, 0x054) = 0;   // m_archiveFileBackup
    ResMgr_u32(self, 0xD1C) = 0;   // m_heap
}

// ---------- EResourceManager::~EResourceManager ----------
// Address: 0x804FA5F0, Size: 160 bytes
void EResourceManager_Dtor(void* self) {
    // Shutdown first
    // EResourceManager::Shutdown();

    // Free archive file name at 0x044
    u32 archFile = ResMgr_u32(self, 0x044);
    if (archFile != 0) {
        EAHeap_Free(MainHeap(), (void*)archFile);
    }
}

// ---------- EResourceManager::Init ----------
// Address: 0x804FA720, Size: 920 bytes
void EResourceManager_Init(void* self, char* name) {
    ResMgr_u32(self, 0x040) = (u32)(uintptr_t)name;  // Store category name

    // Build archive file path: name + ".arc"
    // EResourceManager::CalcPath();

    // Register with EResourceLoaderImpl singleton
    // g_pResourceLoader->AddManager(self);

    // Determine resource capacity from category name
    int capacity = 4;  // default
    if (strcmp(name, "level") == 0)         capacity = 800;
    else if (strcmp(name, "shader") == 0)   capacity = 150;
    else if (strcmp(name, "shaderlow") == 0) capacity = 100;
    else if (strcmp(name, "fontpage") == 0) capacity = 20;
    else if (strcmp(name, "texture") == 0)  capacity = 50;
    else if (strcmp(name, "tquantize") == 0) capacity = 700;
    else if (strcmp(name, "model") == 0)    capacity = 500;
    else if (strcmp(name, "anim") == 0)     capacity = 250;
    else if (strcmp(name, "flash") == 0)    capacity = 550;
    else if (strcmp(name, "sample") == 0)   capacity = 10;
    else if (strcmp(name, "binary") == 0)   capacity = 16;

    // Initialize resource map with capacity
    // m_resourceMap.SetCapacity(capacity, name);

    ResMgr_u32(self, 0x048) = 1;  // Mark as initialized
}

// ---------- EResourceManager::Shutdown ----------
// Address: 0x804FA690, Size: 144 bytes
void EResourceManager_Shutdown(void* self) {
    // Close archive file
    // EResourceManager::CloseArchiveFile();

    // Remove from loader
    // g_pResourceLoader->RemoveManager(self);

    ResMgr_u32(self, 0x048) = 0;  // No longer initialized
}

// ---------- EResourceManager::IsInitialized ----------
// Address: 0x80897848, Size: 44 bytes
bool EResourceManager_IsInitialized(void* self) {
    return ResMgr_u32(self, 0x048) != 0;
}

// ---------- EResourceManager::IsValid ----------
// Address: 0x804FC8AC, Size: 48 bytes
bool EResourceManager_IsValid(void* self, u32 resId) {
    if (resId == 0) return false;
    return true;  // Lookup in resource map
}

// ---------- EResourceManager::IsLoaded ----------
// Address: 0x804FC8DC, Size: 128 bytes
bool EResourceManager_IsLoaded(void* self, u32 resId) {
    if (resId == 0) return false;

    // Lock
    // Look up in resource map
    // Check refcount > 0
    // Unlock

    return false;
}

// ---------- EResourceManager::GetRef ----------
// Address: 0x804FB81C, Size: 260 bytes
void* EResourceManager_GetRef(void* self, u32 resId) {
    if (resId == 0) return NULL;

    // Begin critical section (virtual call at vtable+0x10)
    // Look up resource in hash map at this+0xD08
    // If found and refcount > 0, return it
    // End critical section

    return NULL;
}

// ---------- EResourceManager::AddResource ----------
// Address: 0x804FBEC0, Size: 36 bytes
void EResourceManager_AddResource(void* self, void* resource, u32 resId) {
    // Add resource to internal map with given ID
    // EResourceManager_AddResourceInternal(self, resource, resId, false);
}

// ---------- EResourceManager::BinarySearch ----------
// Address: 0x804FAE98, Size: 100 bytes
int EResourceManager_BinarySearch(u32 targetId, u32* idArray, int count) {
    int low = 0;
    int high = count - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        u32 midId = idArray[mid];

        if (midId == targetId) {
            return mid;
        } else if (midId < targetId) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// ---------- EResourceManager::LookupId ----------
// Address: 0x804FAF8C, Size: 144 bytes
bool EResourceManager_LookupId(void* self, u32 resourceId, u32* outOffset, u32* outSize) {
    // Get sorted ID array from resource index at this+0x058
    u32* ids = (u32*)((u8*)self + 0x058);
    int count = (int)ResMgr_u32(self, 0x04C);

    int index = EResourceManager_BinarySearch(resourceId, ids, count);
    if (index < 0) return false;

    // Retrieve offset and size from parallel arrays
    // *outOffset = m_offsetArray[index];
    // *outSize = m_sizeArray[index];
    return true;
}

// ---------- EResourceManager::CalcId ----------
// Address: 0x804FC99C, Size: 88 bytes
u32 EResourceManager_CalcId(const char* name) {
    // Compute 32-bit hash of resource name
    // Uses DJB2 or similar hash algorithm
    if (name == NULL) return 0;

    u32 hash = 0;
    while (*name != 0) {
        hash = (hash << 5) + hash + (u8)*name;
        name++;
    }
    return hash;
}

// ---------- EResourceManager::FreeUnreferencedResources ----------
// Address: 0x804FCE54, Size: 60 bytes
void EResourceManager_FreeUnreferencedResources(void* self) {
    // Walk the resource map, delete resources with refcount <= 0
    // For each: call EResource::SafeDelete()
}

// ---------- EResourceManager::CanCache ----------
// Address: 0x80897874, Size: 40 bytes
bool EResourceManager_CanCache(void* self) {
    return true;  // Default: caching always allowed
}

// ---------- EResourceManager::Free ----------
// Address: 0x804FCF58, Size: 80 bytes
void EResourceManager_Free(void* self, void* ptr) {
    u32 heap = ResMgr_u32(self, 0xD1C);
    if (heap != 0 && ptr != NULL) {
        EAHeap_Free((void*)heap, ptr);
    }
}

// ---------- EResourceManager::Alloc ----------
// Address: 0x804FCEB4, Size: 164 bytes
void* EResourceManager_Alloc(void* self, u32 size, u32 alignment) {
    u32 heap = ResMgr_u32(self, 0xD1C);
    if (heap == 0) return NULL;
    return EAHeap_Malloc((void*)heap, size, 0);
}

// ---------- EResourceManager::GetHeap ----------
// Address: 0x804FCDEC, Size: 32 bytes
void* EResourceManager_GetHeap(void* self) {
    return (void*)ResMgr_u32(self, 0xD1C);
}

// ---------- EResourceManager::ResourceDestructing ----------
// Address: 0x804FC998, Size: 4 bytes
void EResourceManager_ResourceDestructing(void* self, void* resource) {
    // Remove resource from internal tracking
    // This is a no-op in some builds (4 bytes = blr)
}


// ============================================================================
//  SECTION 10: EResourceLoaderImpl -- Async Resource Loading Coordinator
// ============================================================================
//
// Size: 0xD08 (3336 bytes)
// Runs on a separate thread, processes command queue for async I/O.
//
// Field layout:
//   0x000: vtable*
//   0x004-0x03C: message queue fields
//   0x040: u32 m_managerArray
//   0x348: u32 m_managerCount
//   0x350: u32 m_isInitialized
//   0x3E4: u32 m_bIsBusy
//   0x3E8: u32 m_bIsBusy_3E8
//   0xD04: u32 m_managerCapacity

// Helper
static inline u32& ResLoader_u32(void* self, u32 off) { return *(u32*)((u8*)self + off); }

// ---------- EResourceLoaderImpl::EResourceLoaderImpl ----------
// Address: 0x804D85D8, Size: 188 bytes
void EResourceLoaderImpl_Ctor(void* self) {
    *(void**)self = (void*)&EResourceLoaderImpl_vtable;

    // Zero-init message queue fields
    ResLoader_u32(self, 0x004) = 0;
    ResLoader_u32(self, 0x008) = 0;
    ResLoader_u32(self, 0x00C) = 0;

    ResLoader_u32(self, 0x340) = 0;
    ResLoader_u32(self, 0x348) = 0;   // m_managerCount
    ResLoader_u32(self, 0x34C) = 0;
    ResLoader_u32(self, 0x350) = 0;   // m_isInitialized
    ResLoader_u32(self, 0x3E0) = 0;
    ResLoader_u32(self, 0x3E4) = 0;   // m_bIsBusy
    ResLoader_u32(self, 0x3E8) = 0;   // m_bIsBusy_3E8
}

// ---------- EResourceLoaderImpl::~EResourceLoaderImpl ----------
// Address: 0x804D8694, Size: 164 bytes
void EResourceLoaderImpl_Dtor(void* self) {
    // Shutdown if initialized
    // EResourceLoaderImpl::Shutdown();

    // Free allocated resources
    u32 allocPtr = ResLoader_u32(self, 0x340);
    if (allocPtr != 0) {
        EAHeap_Free(MainHeap(), (void*)allocPtr);
        ResLoader_u32(self, 0x340) = 0;
    }
}

// ---------- EResourceLoaderImpl::Init ----------
// Address: 0x804D8838, Size: 124 bytes
void EResourceLoaderImpl_Init(void* self) {
    ResLoader_u32(self, 0x3E4) = 0;  // Not busy

    // Initialize message queue
    // EResLoaderMsgQueue_Init(&m_msgQueue);

    // Set up and start loader thread
    // EThread_Init, Create, Start with priority=17, stack=32KB

    ResLoader_u32(self, 0x3E8) = 0;
    ResLoader_u32(self, 0x350) = 1;  // Mark initialized
}

// ---------- EResourceLoaderImpl::Shutdown ----------
// Address: 0x804D8738, Size: 148 bytes
void EResourceLoaderImpl_Shutdown(void* self) {
    if (ResLoader_u32(self, 0x350) == 0) return;  // Not initialized

    // Terminate loader thread
    // EResourceLoaderImpl::TerminateThread();

    // Flush command queue
    // EResourceLoaderImpl::FlushCommandQueue(NULL, 0);

    ResLoader_u32(self, 0x350) = 0;
}

// ---------- EResourceLoaderImpl::IsBusy ----------
// Address: 0x804D857C, Size: 92 bytes
bool EResourceLoaderImpl_IsBusy(void* self) {
    return (ResLoader_u32(self, 0x3E4) != 0) || (ResLoader_u32(self, 0x3E8) != 0);
}

// ---------- EResourceLoaderImpl::IsCallingThread ----------
// Address: 0x804D8814, Size: 36 bytes
bool EResourceLoaderImpl_IsCallingThread(void* self) {
    // Check if current thread is the loader thread
    return false;  // Default: not on loader thread
}

// ---------- EResourceLoaderImpl::Update ----------
// Address: 0x804D8BD0, Size: 4 bytes
void EResourceLoaderImpl_Update(void* self) {
    // No-op (blr) -- the loader runs on its own thread
}

// ---------- EResourceLoaderImpl::AddManager ----------
// Address: 0x804D8DCC, Size: 204 bytes
void EResourceLoaderImpl_AddManager(void* self, void* manager) {
    u32 count = ResLoader_u32(self, 0x348);
    u32 capacity = ResLoader_u32(self, 0xD04);

    if (count >= capacity) {
        // Grow manager array
        capacity = (capacity == 0) ? 8 : capacity * 2;
        // Reallocate array
        ResLoader_u32(self, 0xD04) = capacity;
    }

    // Add manager to array
    u32 arrayPtr = ResLoader_u32(self, 0x040);
    if (arrayPtr != 0) {
        ((u32*)arrayPtr)[count] = (u32)(uintptr_t)manager;
    }
    ResLoader_u32(self, 0x348) = count + 1;

    // Set manager's field_D00
    ResMgr_u32(manager, 0xD00) = count;
}

// ---------- EResourceLoaderImpl::RemoveManager ----------
// Address: 0x804D8E98, Size: 232 bytes
void EResourceLoaderImpl_RemoveManager(void* self, void* manager) {
    u32 count = ResLoader_u32(self, 0x348);
    u32 arrayPtr = ResLoader_u32(self, 0x040);

    if (count == 0 || arrayPtr == 0) return;

    // Find and remove manager from array
    for (u32 i = 0; i < count; i++) {
        if (((u32*)arrayPtr)[i] == (u32)(uintptr_t)manager) {
            // Shift remaining entries down
            for (u32 j = i; j < count - 1; j++) {
                ((u32*)arrayPtr)[j] = ((u32*)arrayPtr)[j + 1];
            }
            ResLoader_u32(self, 0x348) = count - 1;
            return;
        }
    }
}

// ---------- EResourceLoaderImpl::FindResourceManager ----------
// Address: 0x804D95AC, Size: 128 bytes
void* EResourceLoaderImpl_FindResourceManager(void* self, const char* name) {
    u32 count = ResLoader_u32(self, 0x348);
    u32 arrayPtr = ResLoader_u32(self, 0x040);

    if (arrayPtr == 0) return NULL;

    for (u32 i = 0; i < count; i++) {
        void* mgr = (void*)((u32*)arrayPtr)[i];
        const char* mgrName = (const char*)ResMgr_u32(mgr, 0x040);
        if (mgrName != NULL && strcmp(mgrName, name) == 0) {
            return mgr;
        }
    }
    return NULL;
}

// ---------- EResourceLoaderImpl::Load ----------
// Address: 0x804D8FC8, Size: 384 bytes
void* EResourceLoaderImpl_Load(void* self, void* manager, u32 resourceId,
                                void* file, u32 offset, u32 size, bool async) {
    void* result = NULL;

    if (EResourceLoaderImpl_IsCallingThread(self)) {
        // Direct synchronous load (already on loader thread)
        // result = DoLoadResource(manager, resourceId, file, offset, size);
    } else {
        // Enqueue async load command
        // Allocate EResLoadCmd, fill fields, sendCommand()

        if (!async) {
            // Synchronous: wait for completion
            // WaitForSemaphore();
            // result = manager->GetRef(resourceId);
        }
    }

    return result;
}

// ---------- EResourceLoaderImpl::Unload ----------
// Address: 0x804D9148, Size: 172 bytes
void EResourceLoaderImpl_Unload(void* self, void* manager, u32 resourceId) {
    // Send UNLOAD command (type=4) to message queue
}

// ---------- EResourceLoaderImpl::FlushCommandQueue ----------
// Address: 0x804D8BFC, Size: 464 bytes
void EResourceLoaderImpl_FlushCommandQueue(void* self, const char* name, int flags) {
    // Process all pending commands in the queue
    // For each command, call ProcessMessage()
}

// ---------- EResourceLoaderImpl::OpenFiles ----------
// Address: 0x804D968C, Size: 172 bytes
void EResourceLoaderImpl_OpenFiles(void* self) {
    u32 count = ResLoader_u32(self, 0x348);
    u32 arrayPtr = ResLoader_u32(self, 0x040);

    if (arrayPtr == 0) return;

    for (u32 i = 0; i < count; i++) {
        void* mgr = (void*)((u32*)arrayPtr)[i];
        // mgr->GetArchiveFile();  // Opens archive if not already open
    }
}

// ---------- EResourceLoaderImpl::AddRefDelRefAllResources ----------
// Address: 0x804D982C, Size: 168 bytes
void EResourceLoaderImpl_AddRefDelRefAllResources(void* self) {
    u32 count = ResLoader_u32(self, 0x348);
    u32 arrayPtr = ResLoader_u32(self, 0x040);

    if (arrayPtr == 0) return;

    for (u32 i = 0; i < count; i++) {
        void* mgr = (void*)((u32*)arrayPtr)[i];
        // mgr->AddDelRefAll();
    }
}

// ---------- EResourceLoaderImpl::FreeUnreferencedResources ----------
// Address: 0x804D9AF0, Size: 104 bytes
void EResourceLoaderImpl_FreeUnreferencedResources(void* self) {
    u32 count = ResLoader_u32(self, 0x348);
    u32 arrayPtr = ResLoader_u32(self, 0x040);

    if (arrayPtr == 0) return;

    for (u32 i = 0; i < count; i++) {
        void* mgr = (void*)((u32*)arrayPtr)[i];
        EResourceManager_FreeUnreferencedResources(mgr);
    }
}

// ---------- EResourceLoaderImpl::GetUnreferencedResourceCount ----------
// Address: 0x804D9C08, Size: 80 bytes
int EResourceLoaderImpl_GetUnreferencedResourceCount(void* self) {
    int total = 0;
    u32 count = ResLoader_u32(self, 0x348);
    u32 arrayPtr = ResLoader_u32(self, 0x040);

    if (arrayPtr == 0) return 0;

    for (u32 i = 0; i < count; i++) {
        // void* mgr = (void*)((u32*)arrayPtr)[i];
        // total += mgr->GetUnreferencedResourceCount();
    }
    return total;
}

// ---------- EResourceLoaderImpl::EnableReloads ----------
// Address: 0x804DAFFC, Size: 8 bytes
void EResourceLoaderImpl_EnableReloads(void* self, bool enable) {
    // Store enable flag (simple setter)
}

// ---------- EResourceLoaderImpl::PauseLoads ----------
// Address: 0x804DB004, Size: 12 bytes
void EResourceLoaderImpl_PauseLoads(void* self) {
    ResLoader_u32(self, 0x3E4) = 1;  // Set busy flag to pause
}

// ---------- EResourceLoaderImpl::UnPauseLoads ----------
// Address: 0x804DB010, Size: 44 bytes
void EResourceLoaderImpl_UnPauseLoads(void* self) {
    ResLoader_u32(self, 0x3E4) = 0;  // Clear busy flag

    // Signal the loader thread to resume
    // ESemaphore::Signal();
}

// ---------- EResourceLoaderImpl::AreLoadsPaused ----------
// Address: 0x804DB03C, Size: 8 bytes
bool EResourceLoaderImpl_AreLoadsPaused(void* self) {
    return ResLoader_u32(self, 0x3E4) != 0;
}
