// resources_decomp.cpp - Resource, Shader, Texture, Model, Font System Decompilation
// Part of the Sims 2 GC matching decompilation
// Original object files: e_resource.obj, e_resourcemanager.obj, e_ershader.obj,
//                        e_submodelshader.obj, e_ermodel.obj, e_ertexture.obj,
//                        e_erfont.obj, e_ngcshader.obj, e_ngctexture.obj
//
// This file documents the complete asset pipeline after loading — how the game
// manages resources (reference counting, lifecycle), configures shaders for
// different materials, binds textures through GX TEV stages, and renders fonts.
//
// ============================================================================
// ARCHITECTURE OVERVIEW
// ============================================================================
//
// The Sims 2 GC uses a hierarchical resource system built on EResource:
//
//   EResource (base)         -- Reference-counted asset with managed/unmanaged modes
//     |-- ERShader           -- Material definition wrapping EShader(s) + day/night blending
//     |-- ERTexture          -- Texture wrapper owning an ETexture (platform-specific image)
//     |-- ERModel            -- 3D model containing ESubModelShader strip arrays
//     |-- ERLevel            -- Scene graph (documented in erlevel_decomp.cpp)
//     |-- ERFont             -- Bitmap font with glyph pages and size scaling
//     |-- ERBinary           -- Raw binary data
//     |-- ERDataset          -- Data table resource
//     |-- ERCharacter        -- Animated character resource
//     |-- ERAnim             -- Animation clip resource
//     |-- ERMovie            -- Video stream resource
//
// EResourceManager is the central registry. It owns an EResourceMap (hash table)
// that maps resource IDs (u32 hashes of filenames) to EResource pointers.
// Resources can be loaded from .arc archive files or loose files on disc.
//
// The rendering pipeline flows:
//   ERModel -> iterates ESubModelShader strips -> each strip selects its ERShader
//   ERShader -> resolves to EShader -> calls ENgcShader::Select() for GX state
//   ENgcShader::Select() -> configures TEV stages, texture binds, material colors
//   ESubModelShader::Draw() -> submits GX display list primitives
//
// ============================================================================
// SECTION 1: RESOURCE BASE CLASS (EResource)
// ============================================================================
//
// Size: ~0x14 (20 bytes, not including vtable-pointed ETypeInfo area)
// The header lays out:
//   0x00: void** _vtable   -- Points to EResource vtable (or derived class vtable)
//   0x04: u32  m_pManager  -- Pointer to owning EResourceManager (NULL = unmanaged)
//   0x08: u32  m_resId     -- Resource ID (hash of filename)
//   0x0A: u16  m_readVersion -- Serialization version read from file
//   0x0C: s16  m_refCount  -- Reference count (starts at 1)
//   0x0E: u16  m_flags     -- Resource flags (managed, loaded, etc.)
//   0x10: u32  m_resSize   -- Size in bytes of the loaded resource data
//
// The vtable contains virtual dispatch entries for the type system:
//   vtable+0x00: ~EResource()        [destructor]
//   vtable+0x04: DelRefSubResources()
//   vtable+0x08: SafeDelete() offset / IsSafeToDelete() thunk
//   vtable+0x0C: SafeDelete() function pointer
//   vtable+0x10: Select() (base = no-op)
//   ...etc
//
// EResource uses SN Systems C++ ABI vtable layout where virtual calls are:
//   lwz   r9, 0(this)        // load vtable
//   lha   r3, offset(r9)     // load 'this' adjustment (thunk offset)
//   lwz   r0, offset+4(r9)   // load function pointer
//   add   r3, this, r3       // adjust 'this' pointer
//   mtlr  r0
//   blrl                     // indirect call
//
// This 8-byte vtable entry format (s16 this_adj + padding + u32 func_ptr) is
// consistent across all virtual calls in the codebase.
//

// ============================================================================
// EResource::EResource(void)
// Address: 0x80311DC8  Size: 48 bytes
// ============================================================================
//
// The default constructor initializes a new resource with refcount=1 and
// sets the vtable pointer. No memory allocation occurs here.
//
// Decompiled from PPC assembly:

#include "types.h"

// Forward declarations
class EShader;
class EShaderDef;
class ETexture;
class ETextureDef;
class EFile;
class ERC {
public:
    void* m_pVtableExt;  // offset 0x70 (112)
    void SetTEVStageTexture(int stage, int tex) {}
    void CommitShaderState(void* shader, unsigned int flags) {}
    void SetAlphaBlend(int mode) {}
    void SetCullMode(int mode) {}
    void SetTEVColorAlpha(int a, int b, int c, int d) {}
};
class EMat4;
class EVec2;
class EVec3;
class EVec4;
class EBound3;
class EBoundSphere;
class EWindow;
struct CUIWindow;
struct EACNodeState;
struct fontFXcommand;

// Enum stubs (minimal definitions)
enum EFontAlignX { kFontAlignX_Left = 0, kFontAlignX_Center, kFontAlignX_Right };
enum EFontAlignY { kFontAlignY_Top = 0, kFontAlignY_Center, kFontAlignY_Bottom };
enum EFontMatrixType { kFontMatrix_None = 0 };

// Minimal EStream stub (serialization stream)
class EStream {
public:
    void Init() {}
    void InitFromString(const char* s) {}
    void Destroy() {}
};

// Minimal EAHeap stub for resource usage
class EAHeap {
public:
    static EAHeap* GetPool() { return NULL; }
    static void   Free(void* ptr) {}
    static unsigned char* Alloc(unsigned int size, int flags) { return NULL; }
    static void   CollectGarbage() {}
    void* Malloc(unsigned int size, int flags = 0) { return NULL; }
};
extern EAHeap* MainHeap();

// vtable placeholders
extern void* EResource_vtable;
extern void* EStorable_vtable;

// Minimal EResourceMap stub
class EResourceMap {
public:
    bool Find(unsigned int id, void** out) { return false; }
};

// Minimal EResourceManager stub
class EResourceManager {
public:
    EResourceMap m_resourceMap;
    void  ResourceDestructing(void* res) {}
    void  AddRef(void* res) {}
    void  DelRef(void* res, int mode) {}
    void  Detach(void* res) {}
    void  Refresh(void* res) {}
    void  BeginAccess(int timeout) {}
    void  EndAccess() {}
    void* GetRef(unsigned int resId);
};

// EResource class declaration
class EResource {
public:
    void**          _vtable;        // 0x00
    EResourceManager* m_pManager;  // 0x04
    unsigned int    m_resId;        // 0x08
    unsigned short  m_readVersion;  // 0x0A
    short           m_refCount;     // 0x0C
    unsigned short  m_flags;        // 0x0E
    unsigned int    m_resSize;      // 0x10

    EResource(void);
    virtual ~EResource(void);
    void AddRef(void);
    void DelRef(void);
    void Detach(void);
    void Refresh(void);
    void SafeDelete(void);
    bool IsSafeToDelete(void);
    void Init(void);
    void Load(EFile& file);
    void Read(EStream& srcStream);
    void Write(EStream& stream);
    void StreamRead(EStream& src, EStream* dst) {}
    void StreamWrite(EStream& dst, EStream* src) {}
};

// Minimal EShader stub
class EShader {
public:
    void** _vtable;
    unsigned int m_flags;   // 0x04
    static bool ValidateDef(void* def) { return true; }
    void Select(ERC* rc, unsigned int flags) {}
};

// ERShader vtable placeholders
extern void* ERShader_vtable;
extern void* ERTexture_vtable;

// Minimal EFile stub
class EFile {
public:
    void Read(void* buf, unsigned int size) {}
    virtual ~EFile() {}
};

// Minimal EResourceFile stub (used in ERTexture::Load)
class EResourceFile {
public:
    void Init() {}
    bool Open(EFile* file, unsigned int sig, int minV, int maxV) { return false; }
    void Close(int mode) {}
    unsigned int GetDataSize() { return 0; }
};

// Minimal ETextureManager stub
class ETextureManager {
public:
    void** _vtable;
};

// Minimal ENgcTexture with m_pGXTexObj
class ENgcTexture {
public:
    void* m_pGXTexObj;  // 0x00
    void Select(int texMapId, int texCoordId);
    int  GetTEVStageCount(void);
    int  GetTEXCount(void);
};

// ERShader class declaration
class ERShader : public EResource {
public:
    EShader*  m_pCurrentEShader;    // 0x14
    ERShader* m_pCurrentERShader;   // 0x18
    EShader*  m_pIncomingShader;    // 0x1C
    unsigned int m_pendingShader;   // 0x5C
    void*     m_pBlendEShader;      // 0x30
    void*     m_pTextureResource;   // 0x34
    unsigned int m_textureResId;    // 0x38
    float     m_timeOfDay;          // 0x3C
    void*     m_pMultiShaderInfo;
    float     m_weatherFactor;
    unsigned char m_updateFlags;
    unsigned int m_shaderData;
    float     m_blendProgress;      // 0x60
    unsigned char m_currentStateIndex;  // 0x50
    unsigned int m_pUpdateListNext; // 0x54
    unsigned char m_currentShaderIdx;   // 0x64
    unsigned char m_targetShaderIdx;    // 0x65
    unsigned char m_weatherState;       // 0x67

    ERShader(void);
    bool     IsDayNightShader(void) const;
    bool     IsMultiShader(void) const;
    bool     IsMultiTextureShader(void) const;
    ERShader* GetCurrentShader(void);
    void     Select(ERC* rc, unsigned int flags);
};

// ERTexture class declaration
class ERTexture : public EResource {
public:
    ETexture* m_pTexture;   // 0x14
    void Attach(ETexture* tex);
    void Deallocate(void);
    void Load(EFile& file);
    void LoadFromMemory(void* data) {}
    bool IsSafeToDelete(void);
};

// ESubModelShader stub
class ESubModelShader {
public:
    void Draw(ERC* rc) {}
    void DrawGeometry(ERC* rc) {}
};

// ERModel class declaration
class ERModel : public EResource {
public:
    void* m_pStripArray;    // 0x3C
    void Draw(ERC* rc);
    void DrawGeometry(ERC* rc);
};

// EFontData stub (font metrics/page table)
class EFontData {
public:
    void* m_pageArrayPtr;   // 0x20
};

// ERFont class declaration
class ERFont : public EResource {
public:
    void*     m_pCharTable;     // 0x14
    EFontData* m_pFontData;    // 0x18
    void*     m_pPageArray;    // 0x54
    float     m_scaleX;        // 0x4C
    int       m_currentPage;   // 0x68

    void Deallocate(void) {}
    void Read(EFile& file, EStream* stream) {}
    void Load(EFile& file);
    void SelectPage(ERC* rc, int pageIndex);
};

// ENgcShader class declaration
class ENgcShader {
public:
    unsigned char m_numTEVStages;       // 0x00
    unsigned char m_tevStage0Color[4];  // 0x80
    unsigned char m_tevStage1Color[4];  // 0xC0
    unsigned int  m_gxFlags;
    unsigned int  m_gxFlags2;
    void* m_pVtableExt;

    bool  Create(EShaderDef& def);
    void  Select(ERC* rc, unsigned int flags);
    void  SelectForShadowMask(ERC* rc);
    void* GetStageParams(int stage) { return NULL; }
};

// ---- EResource vtable (located at 0x8046B240 in .data) ----
// extern void* EResource_vtable[];

EResource::EResource(void) {
    // 0x80311DC8
    this->m_refCount = 1;                         // sth r0=1, 12(r11)
    this->_vtable = &EResource_vtable;            // stw r9, 0(r11)  -- r9 = 0x8046B240
    this->m_flags = 0;                            // sth r10=0, 14(r11)
    this->m_resSize = 128;                        // stw r0=0x80, 16(r11) -- default 128 bytes
    this->m_pManager = NULL;                      // stw r10=0, 4(r11)
    // No prologue/epilogue needed -- leaf function (blr only)
}

// ============================================================================
// EResource::~EResource(void)
// Address: 0x80311DF8  Size: 108 bytes
// ============================================================================
//
// The destructor notifies the resource manager (if managed) that the resource
// is being destroyed, then optionally frees the memory (if bit 0 of the
// hidden parameter r4 is set -- SN Systems C++ ABI scalar deleting destructor).
//
// The hidden r4 parameter encodes:
//   bit 0 (0x01): if set, call operator delete after destruction
//   bit 1 (0x02): if set, this is an array delete (not used for EResource)

EResource::~EResource(void) {
    // 0x80311DF8
    // Restore EResource vtable (in case derived class changed it)
    this->_vtable = &EResource_vtable;            // stw r9, 0(r31)

    // If this resource is managed, notify the manager
    if (this->m_pManager != NULL) {               // lwz r3, 4(r31); cmpwi r3, 0
        // Call EResourceManager::ResourceDestructing(this)
        this->m_pManager->ResourceDestructing(this);  // bl 0x80327530
    }

    // Set vtable to base EStorable vtable (parent class)
    this->_vtable = &EStorable_vtable;            // stw r9, 0(r31)  -- r9 = 0x804690C8

    // If scalar-delete bit is set, free memory (SN Systems ABI hidden param)
    // hidden_param & 0x01 --> handled by compiler-generated scalar deleting destructor
    // EAHeap::GetPool()->Free(this) -- 0x802CFF00 / 0x802D0D78
}

// ============================================================================
// EResource::AddRef(void)
// Address: 0x80312000  Size: 64 bytes
// ============================================================================
//
// Increments the reference count. If the resource is managed (m_pManager != NULL),
// the operation is delegated to the resource manager (which tracks all references
// centrally). If unmanaged, the local m_refCount is incremented directly.
//
// This is the core of the resource lifetime system. Every system that holds a
// pointer to an EResource must AddRef() it, and DelRef() when done.

void EResource::AddRef(void) {
    // 0x80312000
    EResource* self = this;                       // mr r4, r3
    EResourceManager* mgr = self->m_pManager;    // lwz r3, 4(r4)

    if (mgr != NULL) {                            // cmpwi r3, 0; beq
        // Managed: delegate to EResourceManager::AddRef(EResource*)
        mgr->AddRef(self);                        // bl 0x80326F60
    } else {
        // Unmanaged: local increment
        self->m_refCount++;                       // lhz r9, 12(r4); addi r9,r9,1; sth r9, 12(r4)
    }
}

// ============================================================================
// EResource::DelRef(void)
// Address: 0x80311F70  Size: 104 bytes
// ============================================================================
//
// Decrements the reference count. If managed, delegates to the manager
// with DelRefMode=1 (NORMAL). If unmanaged, decrements locally and when
// the count reaches 0, calls the virtual SafeDelete() to destroy the resource.
//
// The SafeDelete dispatch uses the vtable pattern:
//   vtable[idx]    = s16 this_adjustment
//   vtable[idx+4]  = u32 function_pointer
//
// SafeDelete is at vtable offset 0x08/0x0C (the 2nd virtual after dtor).

void EResource::DelRef(void) {
    // 0x80311F70
    EResource* self = this;                       // mr r4, r3
    EResourceManager* mgr = self->m_pManager;    // lwz r3, 4(r4)

    if (mgr != NULL) {                            // cmpwi r3, 0; beq
        // Managed: delegate to EResourceManager::DelRef(EResource*, NORMAL)
        mgr->DelRef(self, 1);                     // li r5, 1; bl 0x80327234
    } else {
        // Unmanaged: local decrement
        self->m_refCount--;                       // lhz r9, 12(r4); addi r9,r9,-1; sth r9, 12(r4)

        if (self->m_refCount == 0) {              // lha r0, 12(r4); cmpwi r0, 0; bne
            // Refcount hit zero -- call virtual SafeDelete()
            // Uses vtable dispatch pattern:
            void** vtbl = self->_vtable;          // lwz r9, 0(r4)
            s16 adj = *(s16*)(vtbl + 0x08);       // lha r3, 8(r9)
            void* fn = *(void**)(vtbl + 0x0C);    // lwz r0, 12(r9)
            // this_adjusted = self + adj
            // fn(this_adjusted)
            ((void(*)(void*))(fn))((u8*)self + adj); // blrl
        }
    }
}

// ============================================================================
// EResource::Detach(void)
// Address: 0x80311FD8  Size: 40 bytes
// ============================================================================
//
// Removes this resource from its managing EResourceManager, transitioning it
// to "unmanaged" state. The resource's refcount is preserved — it just won't
// be tracked by the manager anymore.

void EResource::Detach(void) {
    // 0x80311FD8
    EResource* self = this;                       // mr r4, r3
    EResourceManager* mgr = self->m_pManager;    // lwz r3, 4(r4)
    // Call EResourceManager::Detach(self)
    mgr->Detach(self);                            // bl 0x8032737C
}

// ============================================================================
// EResource::Refresh(void)
// Address: 0x80312040  Size: 48 bytes
// ============================================================================
//
// Signals the resource manager to re-evaluate this resource (e.g., reload from
// disc if the source file changed). Only effective for managed resources.

void EResource::Refresh(void) {
    // 0x80312040
    EResource* self = this;                       // mr r4, r3
    EResourceManager* mgr = self->m_pManager;    // lwz r3, 4(r4)
    if (mgr != NULL) {                            // cmpwi r3, 0; beq
        mgr->Refresh(self);                       // bl 0x80326E20
    }
}

// ============================================================================
// EResource::SafeDelete(void)
// Address: 0x80312158  Size: 64 bytes
// ============================================================================
//
// Dispatches a virtual call to the derived class's SafeDelete implementation.
// The "mode" parameter (r4=3) tells the implementation how aggressively to
// clean up (mode 3 = full delete including sub-resources).
//
// SafeDelete is at vtable offset 0x30/0x34.

void EResource::SafeDelete(void) {
    // 0x80312158
    if (this == NULL) return;                     // mr. r11, r3; beq

    void** vtbl = this->_vtable;                  // lwz r9, 0(r11)
    int mode = 3;                                 // li r4, 3
    s16 adj = *(s16*)(vtbl + 0x30);               // lha r3, 48(r9)
    void* fn = *(void**)(vtbl + 0x34);            // lwz r0, 52(r9)
    // Virtual call: derived->SafeDelete(mode)
    ((void(*)(void*, int))(fn))((u8*)this + adj, mode); // blrl
}

// ============================================================================
// EResource::IsSafeToDelete(void)
// Address: 0x8031226C  Size: 8 bytes
// ============================================================================
//
// Base class always returns true. Derived classes (like ERTexture) override
// this to check if the resource is still in use by the GPU pipeline.

bool EResource::IsSafeToDelete(void) {
    // 0x8031226C
    return true;                                  // li r3, 1; blr
}

// ============================================================================
// EResource::Init(void)
// Address: 0x80312338  Size: 4 bytes
// ============================================================================
//
// Base class Init is a no-op. Derived classes override to perform
// post-construction initialization.

void EResource::Init(void) {
    // 0x80312338
    // blr -- intentionally empty
}

// ============================================================================
// EResource::Load(EFile &)
// Address: 0x80311F14  Size: 92 bytes
// ============================================================================
//
// Loads the resource from a file. Creates an EStream from the EFile, then
// checks a global flag (at 0x804FCD4E) to decide between stream-based
// reading or direct binary loading. The EStream abstraction handles
// endian conversion and versioned serialization.

void EResource::Load(EFile& file) {
    // 0x80311F14
    EStream stream;                               // addi r31, r1, 8
    stream.Init();                                // bl 0x802D293C (EStream::EStream)

    // Check global "use binary load" flag
    u16 useBinaryLoad = *(u16*)0x804FCD4E;        // lis r9, 0x8050; lhz r0, -12978(r9)
    if (useBinaryLoad == 0) {
        // Stream-based load path
        this->Read(stream);                       // bl 0x802C66C0 -- EResource::Read(EStream&)
    }

    stream.Destroy();                             // lwz r4, 8(r1); bl 0x802D2948
}

// ============================================================================
// EResource::Read(EStream &)
// Address: 0x80311EB8  Size: 92 bytes
// ============================================================================
//
// Similar to Load but uses a pre-existing stream. Creates an inner EStream
// and reads the resource data through the Storable serialization system.

void EResource::Read(EStream& srcStream) {
    // 0x80311EB8
    EStream stream;                               // addi r31, r1, 8
    stream.Init();                                // bl 0x802D293C

    u16 useBinaryLoad = *(u16*)0x804FCD4E;
    if (useBinaryLoad == 0) {
        this->StreamRead(srcStream, &stream);     // bl 0x802D3698 -- EStorable::Read
    }

    stream.Destroy();                             // bl 0x802D2948
}

// ============================================================================
// EResource::Write(EStream &)
// Address: 0x80311E64  Size: 84 bytes
// ============================================================================
//
// Writes the resource to a stream. Constructs a type tag string ("EResource")
// and writes it as a header before the resource data.

void EResource::Write(EStream& stream) {
    // 0x80311E64
    EStream localStream;                          // addi r30, r1, 8
    const char* typeName = "EResource";           // lis r4, 0x8042; addi r4, r4, 0x0498
    localStream.InitFromString(typeName);         // bl 0x802D2B60

    this->StreamWrite(stream, &localStream);      // bl 0x802D3650
    localStream.Destroy();                        // bl 0x802D2948
}


// ============================================================================
// SECTION 2: RESOURCE MANAGER (EResourceManager)
// ============================================================================
//
// Size: 0xD20 (3,360 bytes)
// Layout:
//   0x000: void** _vtable
//   0x004: u32 m_resourceArray      -- Pointer to resource pointer array
//   0x008: u32 m_resourceCount      -- Number of entries in array
//   0x00C: s16 m_globalRefCount     -- Master ref count for "add/del ref all"
//   0x040: u32 m_archivePath        -- Path string for archive file
//   0x044: u32 m_archiveFile        -- Pointer to open EFile for .arc
//   0x048: u32 m_flags              -- State flags (initialized, etc.)
//   0x04C: u32 m_totalResources     -- Total resource entries in archive
//   0x050: u32 m_archiveFilePtr     -- Secondary archive file reference
//   0x054: u32 m_archiveFileBackup  -- Backup archive file reference
//   0x058..0xD1B: EResourceMap      -- Hash table (0xCC4 bytes!) for ID->resource lookup
//   0xD1C: u32 m_heap              -- Pointer to EAHeap for resource allocation
//
// EResourceManager uses a hash map (EResourceMap) to look up resources by ID.
// Resource IDs are 32-bit hashes computed from the resource filename via CalcId().
//
// The manager supports:
//   - Synchronous loading:  GetRef(id) blocks until the resource is loaded
//   - Asynchronous loading: AddRefAsync(id) queues loading on a worker thread
//   - Cache management:     FreeUnreferencedResources() releases resources with refcount 0
//   - Override files:       GetOverriddenFile() checks for loose files overriding .arc entries
//
// LIFECYCLE:
//   1. Init(archivePath) -- opens the .arc file, reads the resource index
//   2. GetRef(id) or AddRef(id) -- loads + caches the resource
//   3. DelRef(id) -- decrements refcount, resource stays cached
//   4. FreeUnreferencedResources() -- evicts resources with refcount=0 from cache
//   5. Shutdown() -- closes archive, frees all resources
//
// REFERENCE COUNTING RULES:
//   - Every GetRef() increments refcount and returns the resource pointer
//   - Every DelRef() decrements refcount
//   - Resources with refcount=0 are "unreferenced" but still cached
//   - Resources are only freed when explicitly evicted (FreeUnreferencedResources)
//     or when the manager shuts down
//   - The global AddRefAll()/DelRefAll() pair increments/decrements a master counter;
//     this is used during level transitions to keep all resources alive temporarily

// ============================================================================
// EResourceManager::GetRef(unsigned int)
// Address: 0x8032671C  Size: 188 bytes
// ============================================================================
//
// Looks up a resource by ID. If found and has a positive refcount, returns it
// after calling a "begin access" virtual on the manager (likely a mutex lock).
// If not found, returns NULL.
//
// The EResourceMap::Find() call at 0x80327AE8 performs a hash lookup.
// The "begin/end access" virtual calls at vtable offsets 0x10/0x14 and
// 0x18/0x1C implement thread safety (ESingleLock on the internal mutex).

void* EResourceManager::GetRef(unsigned int resId) {
    // 0x8032671C
    if (resId == 0) return NULL;                  // mr. r30, r4; beq -> return NULL

    // Store 'this' for later use
    EResourceManager* self = this;

    // Begin critical section (virtual call at vtable+0x10)
    self->BeginAccess(-1);                        // li r4, -1; blrl (vtable dispatch)

    EResource* res = NULL;
    // Look up resource in the hash map at this+0xD08
    bool found = self->m_resourceMap.Find(resId, &res);  // addi r3, r31, 0xD08; bl 0x80327AE8

    if (found && res->m_refCount > 0) {
        // End critical section
        self->EndAccess();                        // blrl (vtable+0x18)
        return res;
    }

    // End critical section
    self->EndAccess();                            // blrl (vtable+0x18)
    return NULL;
}

// ============================================================================
// EResourceManager::DelRef(EResource*, DelRefMode)
// Address: 0x80327234 (dispatched from EResource::DelRef)  Size: 976 bytes
// ============================================================================
//
// This is the managed DelRef path. DelRefMode values:
//   0 = ASYNC    -- schedule for deferred deletion
//   1 = NORMAL   -- decrement refcount, SafeDelete if zero
//   2 = FORCE    -- force immediate deletion regardless of refcount
//
// The function:
//   1. Acquires the resource manager's lock
//   2. Decrements the resource's refcount
//   3. If refcount <= 0 and mode allows deletion:
//      a. Calls resource->DelRefSubResources() to release child resources
//      b. Calls resource->SafeDelete() to destroy the resource
//      c. Removes from the EResourceMap
//   4. Releases the lock
//
// For ASYNC mode, the resource is queued into a deferred deletion list
// (processed on the next frame by the loading thread).


// ============================================================================
// SECTION 3: SHADER SYSTEM (ERShader, EShader, ENgcShader)
// ============================================================================
//
// The shader pipeline has three layers:
//
//   ERShader   (6,076 bytes) -- Resource-level shader. Owns one or more EShaders.
//                                Manages day/night blending, multi-shader states,
//                                and texture swapping.
//
//   EShader    (2,268 bytes) -- Platform-agnostic material description. Holds
//                                material colors, texture references, scroll speeds,
//                                alpha test settings, and surface properties.
//                                Owns an ENgcShader for hardware dispatch.
//
//   ENgcShader (244 bytes)   -- GameCube-specific shader implementation.
//                                Configures GX TEV stages, texture coordinate
//                                generation, and blend modes. This is where
//                                the rubber meets the road for rendering.
//
// ERShader Field Layout (refined from assembly analysis):
//   0x000-0x00B: EResource base (vtable, manager ptr)
//   0x00C: s16  m_refCount (inherited)
//   0x014: u32  m_pCurrentEShader    -- Active EShader pointer (for single-shader)
//   0x018: u32  m_pCurrentERShader   -- For multi-shader: pointer to current child ERShader
//   0x01C: u32  m_pIncomingShader    -- Shader being transitioned TO (for day/night blend)
//   0x020: u32  m_pERTexture         -- Primary texture resource
//   0x028: u32  m_pERTexture2        -- Secondary texture (multi-texture shaders)
//   0x02C: f32  m_blendFactor        -- Day/night interpolation factor [0.0 .. 1.0]
//   0x030: u32  m_pBlendEShader      -- EShader used during blending
//   0x034: u32  m_pTextureResource   -- Managed texture resource pointer
//   0x038: u32  m_textureResId       -- Resource ID of the texture
//   0x03C: f32  m_timeOfDay          -- Current time-of-day value for shader selection
//   0x040: f32  m_weatherFactor      -- Weather blend factor
//   0x044: u8   m_numStates          -- Number of multi-shader states
//   0x048: u32  m_pStateArray        -- Array of state shader pointers
//   0x04C: u32  m_pMultiShaderInfo   -- MultiShaderInfo array for state management
//   0x050: u8   m_currentStateIndex  -- Active multi-shader state index
//   0x054: u32  m_pUpdateListNext    -- Next shader in global update linked list
//   0x058: s16  m_flags              -- Shader flags bitfield:
//                                         bit 0: is multi-shader
//                                         bit 1: is day/night shader
//                                         bit 2: has multi-texture
//                                         bit 3: supports decal
//                                         bit 4: state change pending
//   0x05C: u32  m_pendingShader      -- Shader queued for async state change
//   0x060: f32  m_blendProgress      -- Async blend progress timer
//   0x064: u8   m_currentShaderIdx   -- Index of active shader in state array
//   0x065: u8   m_targetShaderIdx    -- Index of target shader (during transition)
//   0x066: u8   m_updateFlags        -- Per-frame update control flags
//   0x067: u8   m_weatherState       -- Current weather state index
//   0x068: u32  m_shaderData         -- Raw shader data pointer (from file)
//   0x0F0: u32  m_pEShaderDef        -- Pointer to EShaderDef definition data
//   0xA74: f32  m_someParam          -- Unknown parameter (cloned)
//   0x17B8: u32 m_pUpdateListHead    -- Static: head of global shader update list

// ============================================================================
// ERShader::ERShader(void)
// Address: 0x8031C6DC  Size: 196 bytes
// ============================================================================
//
// Calls base EResource constructor, then initializes all shader-specific fields
// to default/null state. The update list pointers are zeroed, all blend factors
// are set to 0.0, state indices to 0, and the global update fields cleared.

ERShader::ERShader(void) {
    // 0x8031C6DC
    EResource::EResource();                       // bl 0x80311DC8

    // Set ERShader vtable
    this->_vtable = &ERShader_vtable;             // stw r9, 0(r31) -- 0x8046B678

    // Initialize all fields to zero/null
    this->m_pCurrentEShader = NULL;               // stw r0=0, 20(r31)
    this->m_pCurrentERShader = NULL;              // stw r0=0, 24(r31)
    this->m_pIncomingShader = NULL;               // stw r0=0, 28(r31)
    this->m_pBlendEShader = NULL;                 // stw r0=0, 48(r31)
    this->m_pTextureResource = NULL;              // stw r0=0, 52(r31)
    this->m_textureResId = 0;                     // stw r0=0, 56(r31)
    this->m_timeOfDay = -1.0f;                    // stw r11=-1, 60(r31) -- as float bits
    // Initialize multi-shader state struct at offset 0x3C
    this->m_pMultiShaderInfo = NULL;              // stw r0=0, offset+16
    this->m_weatherFactor = 0.0f;                 // stfs f0, offset+4
    this->m_updateFlags = 0;                      // stb r0, offset+8
    this->m_shaderData = 0;                       // stw r0, offset+12
    this->m_blendProgress = 0.0f;                 // stfs f0, 96(r31)
    this->m_shaderData = 0;                       // stw r0, 104(r31)
    this->m_currentStateIndex = 0;                // stb r0, 80(r31)
    this->m_pUpdateListNext = 0;                  // stw r0, 84(r31)
    this->m_flags = 0;                            // stw r0, 88(r31) (actually at 0x58, 16-bit)
    this->m_pendingShader = 0;                    // stw r0, 92(r31)
    this->m_currentShaderIdx = 0;                 // stb r0, 100(r31)
    this->m_targetShaderIdx = 0;                  // stb r0, 101(r31)
    this->m_updateFlags = 0;                      // stb r0, 102(r31)
    this->m_weatherState = 0;                     // stb r0, 103(r31)
    // Zero two pairs of shader pointers (day/night array at 0x20..0x2F)
    // Loop with bdnz zeroing 4 words
}

// ============================================================================
// ERShader::IsDayNightShader(void) const
// Address: 0x80320750  Size: 12 bytes
// ============================================================================
//
// Checks bit 4 of the flags word at offset 0x58 to determine if this shader
// participates in the day/night cycle blending system.
//
// The rlwinm instruction extracts bit 4: (flags >> 5) & 1

bool ERShader::IsDayNightShader(void) const {
    // 0x80320750
    u32 flags = this->m_flags;                    // lwz r3, 88(r3)
    return (flags >> 5) & 1;                      // rlwinm r3,r3,27,31,31
}

// ============================================================================
// ERShader::IsMultiShader(void) const
// Address: 0x80320860  Size: 12 bytes
// ============================================================================
//
// Checks bit 0 of the flags word. Multi-shaders contain multiple child ERShaders
// that can be switched between (e.g., different material states for objects).

bool ERShader::IsMultiShader(void) const {
    // 0x80320860
    u32 flags = this->m_flags;                    // lwz r3, 88(r3)
    return (flags >> 1) & 1;                      // rlwinm r3,r3,31,31,31
}

// ============================================================================
// ERShader::IsMultiTextureShader(void) const
// Address: 0x8032086C  Size: 72 bytes
// ============================================================================
//
// Returns true if the shader uses multiple texture layers. First checks
// if the shader is a multi-shader (bit 1 of flags), which is NOT multi-texture.
// Then resolves the current EShader and checks bit 5 of its property flags.

bool ERShader::IsMultiTextureShader(void) const {
    // 0x8032086C
    u32 flags = this->m_flags;                    // lwz r0, 88(r3)
    if (flags & 0x02) {                           // andi. r9, r0, 2
        return false;                             // li r3, 0; blr
    }

    // Resolve current EShader
    EShader* shader = this->m_pCurrentEShader;    // lwz r0, 20(r3)
    if (shader != NULL) {
        // Direct path
    } else {
        // Indirect: get from current child ERShader
        ERShader* child = this->m_pCurrentERShader; // lwz r3, 24(r3)
        shader = (child != NULL) ? child->m_pCurrentEShader : NULL;
    }

    // Check EShader multi-texture flag: bit 5 of flags at EShader+0x04
    u32 shaderFlags = shader->m_flags;            // lwz r3, 4(r9)
    return (shaderFlags >> 6) & 1;                // rlwinm r3,r3,6,31,31
}

// ============================================================================
// ERShader::GetCurrentShader(void)
// Address: 0x8032076C  Size: 60 bytes
// ============================================================================
//
// Returns the current child ERShader (for multi-shaders). If this is not
// a multi-shader, returns NULL.

ERShader* ERShader::GetCurrentShader(void) {
    // 0x8032076C
    if (this->IsMultiShader()) {                  // bl 0x80320860
        return this->m_pCurrentERShader;          // lwz r3, 24(r31)
    }
    return NULL;
}

// ============================================================================
// ERShader::Select(ERC *, unsigned int)
// Address: 0x80320904  Size: 96 bytes
// ============================================================================
//
// Binds this shader for rendering. Resolves the active EShader and calls
// its virtual Select() method through the EShader vtable.
//
// The resolution logic:
//   1. Check m_pCurrentEShader (direct single-shader path)
//   2. If NULL, check m_pCurrentERShader (multi-shader path)
//   3. From the child ERShader, get ITS m_pCurrentEShader
//   4. Call EShader::Select(rc, flags) via vtable offset 0x10

void ERShader::Select(ERC* rc, unsigned int flags) {
    // 0x80320904
    EShader* shader;

    // Resolve current EShader
    if (this->m_pCurrentEShader != NULL) {        // lwz r3, 20(r9); cmpwi r3, 0
        shader = this->m_pCurrentEShader;
    } else {
        ERShader* child = this->m_pCurrentERShader; // lwz r3, 24(r9)
        if (child != NULL) {
            shader = child->m_pCurrentEShader;    // lwz r11, 20(r3)
        } else {
            shader = NULL;
        }
    }

    // Virtual call: EShader::Select(rc, flags) at vtable+0xF0
    void** vtbl = shader->_vtable;                // lwz r9, 240(r11)
    s16 adj = *(s16*)(vtbl + 0x10);               // lha r3, 16(r9)
    void* fn = *(void**)(vtbl + 0x14);            // lwz r0, 20(r9)
    ((void(*)(void*, ERC*, u32))(fn))((u8*)shader + adj, rc, flags); // blrl
}

// ============================================================================
// ERShader::BlendCurrentShader(float)
// Address: 0x8031F644  Size: 1216 bytes (partial analysis)
// ============================================================================
//
// This is the core of the day/night transition system. It interpolates between
// two EShaders (the "current" and "incoming" shaders) by the given blend factor.
//
// For each material property (diffuse color, specular, ambient, emissive),
// the function computes:
//   result = current + (incoming - current) * blendFactor
//
// The shader's material colors are stored as sets of 4 floats (RGBA) at
// various offsets within the EShader struct (starting at EShader+0x20).
//
// The function iterates over multiple color components:
//   - Diffuse:    EShader+0x20..0x2F
//   - Ambient:    EShader+0x30..0x3F (16 bytes later)
//   - Specular:   EShader+0x40..0x4F
//   - Emissive:   EShader+0x50..0x5F (if present)
//
// After interpolation, the blended values are stored into a third EShader
// at this->m_pBlendEShader, which is the one actually used for rendering.
//
// This function is called from ERShader::Update() each frame when
// IsDayNightShader() is true and a time-of-day transition is in progress.

// (Full decompilation omitted due to size -- 304 instructions of FPU math)


// ============================================================================
// SECTION 4: GX HARDWARE SHADER (ENgcShader)
// ============================================================================
//
// ENgcShader is the bottom of the shader stack, directly configuring the
// GameCube's GX graphics API.
//
// Size: 0xF4 (244 bytes)
// Layout:
//   0x000: u8   m_numTEVStages      -- Number of active TEV stages (typically 1-4)
//   0x004: u32  m_texGenCount        -- Number of texture coordinate generators
//   0x008: u32  m_gxFlags            -- GX configuration flags
//   0x00C: u32  m_blendSrc           -- GX blend source factor
//   0x010: u32  m_blendDst           -- GX blend destination factor
//   0x014: u32  m_alphaCompare       -- Alpha comparison function
//   0x064..0x9F: TEV stage 0 params  -- 60 bytes per TEV stage config
//   0x0A4..0xDF: TEV stage 1 params  -- (for 2-stage shaders)
//   0x070: u32  m_gxFlags2           -- Secondary flags (checked bit 6 = 0x40)
//   0x080..0x083: u8x4 TEV color inputs for stage 0
//   0x0C0..0x0C3: u8x4 TEV color inputs for stage 1
//   0x0F0: u32  m_pPlatformData      -- Platform-specific allocated data (freed in dtor)
//
// TEV STAGE CONFIGURATION:
//
// Each TEV stage is configured by 4 color inputs and 4 alpha inputs:
//   Color: GX_CC_CPREV, GX_CC_TEXC, GX_CC_RASC, GX_CC_KONST, etc.
//   Alpha: GX_CA_APREV, GX_CA_TEXA, GX_CA_RASA, GX_CA_KONST, etc.
//
// The ENgcShader::Create() function reads these from the EShaderDef and packs
// them into a compact encoding:
//   colorInput = input0 | (input1 << 2) | (input2 << 4) | (input3 << 6)
//
// Common configurations seen in the game:
//
//   SIMPLE TEXTURED (1 TEV stage):
//     Color: TEX * RAS         // modulate texture color by vertex/lighting color
//     Alpha: TEX * RAS         // modulate texture alpha by vertex alpha
//
//   LIT + VERTEX COLOR (1 TEV stage):
//     Color: RAS               // just use rasterized (lit) vertex color
//     Alpha: RAS               // vertex alpha only
//
//   MULTI-TEXTURE (2 TEV stages):
//     Stage 0: TEX0 * RAS      // base texture modulated by lighting
//     Stage 1: blend(PREV, TEX1, TEX1_ALPHA)  // blend with detail texture
//
//   ENVIRONMENT MAP (2 TEV stages):
//     Stage 0: TEX0 * RAS      // base texture
//     Stage 1: PREV + TEX1 * KONST  // add environment map contribution

// ============================================================================
// ENgcShader::Create(EShaderDef &)
// Address: 0x8034DE0C  Size: 372 bytes
// ============================================================================
//
// Configures the NGC shader from a platform-agnostic EShaderDef.
// This is where the GX TEV stage setup is determined.
//
// The function:
//   1. Validates the shader def (bl 0x802F9DC8 -- EShader::Validate or similar)
//   2. Clears bit 5 of m_gxFlags (mask 0xFFFFFFDF)
//   3. If m_numTEVStages == 2 (a 2-stage shader):
//      a. Reads TEV color inputs from offsets 0x80-0x83 (stage 0) and 0xC0-0xC3 (stage 1)
//      b. Packs them: packed = in0 | (in1<<2) | (in2<<4) | (in3<<6)
//      c. Checks m_gxFlags2 bit 6 (0x40) to enable/disable the second TEV stage
//      d. Validates specific packed combinations (0x4A, 0x5A, 0x6A for color;
//         0x44, 0x48, 0x64, 0x68 for alpha) that represent known-good TEV configs
//      e. If valid, sets m_numTEVStages=1 and copies the TEV1 params (0xA4..0xDF)
//         into the TEV0 slot (0x64..0x9F) -- essentially promoting stage 1 to stage 0
//   4. Returns success (1) or failure (0)
//
// The packed TEV input values map to GX enums:
//   0x4A = CPREV|TEXC<<2|RASC<<4  (common modulate)
//   0x5A = CPREV|TEXC<<2|KONST<<4 (texture * constant)
//   0x6A = CPREV|TEXC<<2|RASC<<4|KONST<<6 (modulate + tint)

bool ENgcShader::Create(EShaderDef& def) {
    // 0x8034DE0C
    // Validate the shader definition
    if (!EShader::ValidateDef(&def)) {            // bl 0x802F9DC8
        return false;                             // li r3, 0
    }

    // Clear bit 5 of GX flags
    this->m_gxFlags &= ~0x20;                    // rlwinm r0,r0,0,27,22; stw

    if (this->m_numTEVStages != 2) {              // cmpwi r9, 2; bne -> return true
        return true;
    }

    // Pack TEV color inputs for stage 0
    u8 c0_0 = this->m_tevStage0Color[0];          // lbz r6, 128(r31)
    u8 c0_1 = this->m_tevStage0Color[1];          // lbz r0, 129(r31)
    u8 c0_2 = this->m_tevStage0Color[2];          // lbz r7, 130(r31)
    u8 c0_3 = this->m_tevStage0Color[3];          // lbz r11, 131(r31)
    u32 packedColor0 = c0_0 | (c0_1 << 2) | (c0_2 << 4) | (c0_3 << 6);

    // Pack TEV color inputs for stage 1
    u8 c1_0 = this->m_tevStage1Color[0];          // lbz r10, 192(r31)
    u8 c1_1 = this->m_tevStage1Color[1];          // lbz r8, 193(r31)
    u8 c1_2 = this->m_tevStage1Color[2];          // lbz r9, 194(r31)
    u8 c1_3 = this->m_tevStage1Color[3];          // lbz r0, 195(r31)
    u32 packedColor1 = c1_0 | (c1_1 << 2) | (c1_2 << 4) | (c1_3 << 6);

    // Check if secondary TEV stage is enabled
    if (!(this->m_gxFlags2 & 0x40)) {            // andi. r0, r8, 64
        packedColor0 = 0;                         // disable stage 0 contribution
    }

    // Validate known TEV configurations
    bool validColor = (packedColor0 == 0x4A || packedColor0 == 0x5A || packedColor0 == 0x6A);
    bool validAlpha = (packedColor1 == 0x44 || packedColor1 == 0x48 ||
                       packedColor1 == 0x64 || packedColor1 == 0x68);

    if (validColor && validAlpha) {
        // Promote: set to 1-stage and copy stage 1 params to stage 0
        this->m_numTEVStages = 1;                 // stb r0=1, 0(r31)
        // memcpy(this+0x64, this+0xA4, 60) -- copy TEV1 config to TEV0 slot
        // (Unrolled loop copying 4 bytes at a time, 60 bytes total)
        u32* dst = (u32*)(this + 0x64);
        u32* src = (u32*)(this + 0xA4);
        for (int i = 0; i < 15; i++) {
            dst[i] = src[i];
        }
    }

    return true;                                  // li r3, 1
}

// ============================================================================
// ENgcShader::Select(ERC *, unsigned int)
// Address: 0x8034DC98  Size: 164 bytes
// ============================================================================
//
// Activates this shader on the GX hardware through the render context (ERC).
//
// The function iterates over all TEV stages (0 to m_numTEVStages) and for
// each stage, calls an ERC virtual method to configure it. Then it calls
// a final virtual on ERC to commit the overall shader state.
//
// The ERC (Engine Render Context) is a wrapper around ENgcRenderer that
// provides a virtual interface for rendering operations. The vtable calls
// at offset 0x120 (per-stage setup) and 0x338 (shader commit) correspond to:
//   ERC::SetTEVStage(stageIndex, params)    -- vtable+0x120
//   ERC::CommitShaderState(shader, flags)   -- vtable+0x338

void ENgcShader::Select(ERC* rc, unsigned int flags) {
    // 0x8034DC98
    int numStages = (int)this->m_numTEVStages;    // lbz r0, 0(r28)

    for (int i = 0; i < numStages; i++) {         // cmpw r31, r0; blt loop
        // Get ERC vtable entry at offset 0x120 (TEV stage configuration)
        void** rcVtbl = rc->m_pVtableExt;         // lwz r29, 112(r27)
        s16 adj = *(s16*)(rcVtbl + 0x120);        // lha r30, 288(r29)
        void* fn = *(void**)(rcVtbl + 0x124);     // lwz at 292

        // Calculate TEV stage parameters for this stage index
        void* stageParams = this->GetStageParams(i);  // bl 0x802FA474

        // Call ERC::SetTEVStage(stageParams, stageIndex)
        ((void(*)(void*, void*, int))(fn))((u8*)rc + adj, stageParams, i);
    }

    // Commit overall shader state
    void** rcVtbl = rc->m_pVtableExt;             // lwz r9, 112(r27)
    s16 adj = *(s16*)(rcVtbl + 0x338);            // lha r3, 824(r9)
    void* fn = *(void**)(rcVtbl + 0x33C);         // lwz r0, 828(r9)
    ((void(*)(void*, ENgcShader*, u32))(fn))((u8*)rc + adj, this, flags);
}

// ============================================================================
// ENgcShader::SelectForShadowMask(ERC *)
// Address: 0x8034DD3C  Size: 208 bytes
// ============================================================================
//
// Configures GX state for shadow mask rendering. This special mode is used
// when drawing shadow volumes / shadow maps. It sets up a minimal shader:
//
// 1. Disables texturing (SetTEVStage with texIdx=0, texGenIdx=0 -- no texture)
// 2. Applies the current shader state
// 3. Sets alpha blending to additive (blend factor 0x4000 = GX_BL_ONE?)
// 4. Sets geometry/cull mode to special shadow value (64 = double-sided?)
// 5. Configures a single TEV stage for shadow: color=(0,0,0), alpha from vertex
//    with args (0, 2, 0, 0) mapping to GX_CC_ZERO for color, GX_CA_RASA for alpha

void ENgcShader::SelectForShadowMask(ERC* rc) {
    // 0x8034DD3C
    // 1. Disable texture on TEV stage 0
    rc->SetTEVStageTexture(0, 0);                 // vtable+0x120: li r4,0; li r5,0

    // 2. Apply shader state
    rc->CommitShaderState(this, 0);               // vtable+0x338

    // 3. Set alpha blend mode (additive)
    rc->SetAlphaBlend(0x4000);                    // vtable+0x128: li r4, 16384

    // 4. Set cull mode for shadows (double-sided)
    rc->SetCullMode(64);                          // vtable+0x140: li r4, 64; li r5, 0

    // 5. Configure shadow TEV: zero color, vertex alpha
    rc->SetTEVColorAlpha(0, 2, 0, 0);            // vtable+0x1C8: li r4,0; li r5,2; li r6,0; li r7,0
}


// ============================================================================
// SECTION 5: TEXTURE SYSTEM (ERTexture, ETexture, ENgcTexture)
// ============================================================================
//
// The texture pipeline has three layers mirroring shaders:
//
//   ERTexture    (40 bytes)  -- Resource wrapper. Owns an ETexture via m_pTexture (offset 0x14).
//                               Handles loading from .arc files and memory.
//
//   ETexture     (40 bytes)  -- Platform-agnostic texture description. Holds dimensions,
//                               format, palette info, and flags. Delegates to ENgcTexture.
//
//   ENgcTexture  (44 bytes)  -- GameCube-specific texture. Owns the GX texture object
//                               and manages TMEM (texture memory) allocation, swizzling,
//                               and mipmap chain setup. Calls GXInitTexObj/GXLoadTexObj.
//
// ERTexture Field Layout:
//   0x000: void** _vtable
//   0x004: u32  m_pManager           -- EResourceManager pointer (inherited)
//   0x008: u32  m_resId              -- Resource ID (inherited)
//   0x00C: s16  m_refCount           -- Reference count (inherited)
//   0x010: u32  m_flags              -- Resource flags (bits packed with image size in upper 24)
//   0x014: u32  m_pTexture           -- Pointer to ETexture object (the actual image data)
//   0x018-0x023: padding / reserved
//   0x024: u32  m_formatInfo         -- Image format auxiliary info
//
// TEXTURE LOADING FLOW:
//
//   ERTexture::Load(EFile&)
//     1. Opens an EResourceFile to find the texture entry
//     2. Reads the 4-byte signature 'TXFL' (0x5458464C)
//     3. Reads version (must be 9)
//     4. Reads the image data size
//     5. Packs image size into m_flags upper 24 bits: m_flags = (size << 8) | (m_flags & 0xFF)
//     6. Allocates memory from EAHeap for the image data
//     7. Reads the raw texture data into the allocation
//     8. Calls ERTexture::LoadFromMemory() to decode and create the GX texture
//
//   ERTexture::LoadFromMemory(unsigned char*)
//     1. Reads a 32-byte texture header from the memory buffer:
//        - Offset 0x00: u32 magic/flags
//        - Offset 0x18: u8  imageFormat (GX format enum)
//        - Offset 0x19: u8  paletteFormat
//        - Offset 0x1A: u16 width
//        - Offset 0x1B: u8  bitsPerPixel / heightLog2
//        - Offset 0x1C: u32 paletteDataOffset
//        - Offset 0x1E: u16 height (or packed with width)
//     2. Fills an ETextureDef with these parameters
//     3. Computes image data size: (width * height * bitsPerPixel) / 8
//     4. Packs size into m_flags (same upper-24-bit encoding)
//     5. Calls ENgcTexture::Create(textureDef) to allocate GX resources

// ============================================================================
// ERTexture::Attach(ETexture *)
// Address: 0x80320BCC  Size: 52 bytes
// ============================================================================
//
// Attaches an externally-created ETexture to this resource, replacing any
// existing texture. First calls Deallocate() to release the old texture.

void ERTexture::Attach(ETexture* tex) {
    // 0x80320BCC
    this->Deallocate();                           // bl 0x80320C00
    this->m_pTexture = tex;                       // stw r29, 20(r30)
}

// ============================================================================
// ERTexture::Deallocate(void)
// Address: 0x80320C00  Size: 80 bytes
// ============================================================================
//
// Releases the owned ETexture back to the ETextureManager. This uses the
// global texture manager singleton (accessed via r13-relative addressing at
// r13-0x6718 = address of the global ETextureManager*).
//
// The ETextureManager call uses vtable dispatch at offset 0xC0/0xC4 which
// corresponds to ETextureManager::Release(ETexture*).

void ERTexture::Deallocate(void) {
    // 0x80320C00
    // r13-0x6718 = global ETextureManager* (SDA-relative address)
    extern ETextureManager* g_pTextureManager;
    ETextureManager* texMgr = g_pTextureManager;

    ETexture* tex = this->m_pTexture;             // lwz r4, 20(r30)

    // Virtual call: texMgr->Release(tex)
    void** vtbl = texMgr->_vtable;                // lwz r9, 0(r11)
    s16 adj = *(s16*)(vtbl + 0xC0);               // lha r3, 192(r9)
    void* fn = *(void**)(vtbl + 0xC4);            // lwz r0, 196(r9)
    ((void(*)(void*, ETexture*))(fn))((u8*)texMgr + adj, tex);

    this->m_pTexture = NULL;                      // stw r0=0, 20(r30)
}

// ============================================================================
// ERTexture::Load(EFile &)
// Address: 0x80320D00  Size: 240 bytes
// ============================================================================
//
// Loads a texture from an archive file:
//   1. Creates an EResourceFile and opens it
//   2. Searches for the 'TXFL' chunk with version 9
//   3. Reads image data size, packs into flags
//   4. Allocates memory from heap, reads raw data
//   5. Calls LoadFromMemory() to decode
//   6. Frees the temporary buffer

void ERTexture::Load(EFile& file) {
    // 0x80320D00
    EResourceFile resFile;                        // addi r3, r1, 8
    resFile.Init();                               // bl 0x8035AE70

    // Open the resource file looking for 'TXFL' signature, version 9
    u32 signature = 0x5458464C;                   // 'TXFL' -- lis r5, 0x5458; ori r5, r5, 0x464C
    int minVersion = 9;                           // li r6, 9
    int maxVersion = 9;                           // li r7, 9
    bool found = resFile.Open(&file, signature, minVersion, maxVersion); // bl 0x8035B09C

    if (!found) {
        resFile.Close(2);                         // bl 0x8035AEA8
        return;
    }

    // Read image data
    u32 imageSize = resFile.GetDataSize();        // bl 0x8035B320
    // Pack image size into upper 24 bits of flags
    u32 flags = this->m_flags;                    // lwz r0, 16(r28)
    flags = (imageSize << 8) | (flags & 0xFF);    // rlwimi r0,r30,8,0,23
    this->m_flags = flags;                        // stw r0, 16(r28)

    // Allocate memory
    u8* buffer = EAHeap::Alloc(imageSize, 0);     // bl 0x802D0AA4
    if (buffer == NULL) {
        // Try again after garbage collection
        EAHeap::CollectGarbage();                 // bl 0x802D0040
        buffer = EAHeap::Alloc(imageSize, 0);     // bl 0x802D0AA4
    }

    // Read raw texture data into buffer
    file.Read(buffer, imageSize);                 // vtable dispatch at offset 0x18/0x1C

    // Decode texture from memory
    this->LoadFromMemory(buffer);                 // bl 0x80320E14

    // Free temporary buffer
    EAHeap::CollectGarbage();                     // bl 0x802D0040
    EAHeap::Free(buffer);                         // bl 0x802D0D78

    resFile.Close(2);                             // bl 0x8035AEA8
}

// ============================================================================
// ERTexture::IsSafeToDelete(void)
// Address: 0x803210F4  Size: 140 bytes
// ============================================================================
//
// Checks if this texture can be safely deleted. A texture is NOT safe to delete
// if its ETexture pointer matches any texture currently bound in the global
// shader system (checked via a global at r13-0x66C8).
//
// The function iterates over 2 possible texture slots (index 0 and 1),
// calling a method on the global shader system to get the currently bound
// texture for each slot. If any match, returns false (not safe).

bool ERTexture::IsSafeToDelete(void) {
    // 0x803210F4
    ETexture* myTex = this->m_pTexture;           // lwz r0, 20(r30)
    if (myTex == NULL) return true;               // cmpwi r0, 0; beq -> true

    // r13-0x66C8 = global shader system pointer (SDA-relative)
    // IsSafeToDelete: check if texture is currently bound
    return true; // simplified stub
}

// ============================================================================
// ENgcTexture::Create(ETextureDef &)
// Address: 0x8034F86C  Size: 460 bytes
// ============================================================================
//
// Creates a GX texture object from the platform-agnostic texture definition.
// This is where image data gets turned into hardware-ready textures.
//
// The function dispatches on the image format byte at ETextureDef+0x18:
//
//   Format 0x00 (GX_TF_I4):      4-bit intensity
//     -> If palette size == 2080: uses C8_32 handler (8-bit indexed, 32-bit palette)
//     -> If palette size == 1056: uses C4_32 handler (4-bit indexed, 32-bit palette)
//
//   Format 0x01 (GX_TF_I8):      8-bit intensity
//     -> Uses direct format handler
//
//   Format 0x81 (GX_TF_IA4):     4-bit intensity + 4-bit alpha
//     -> Uses 156-byte allocation, specific palette handler
//
//   Format 0x82 (GX_TF_IA8):     8-bit intensity + 8-bit alpha
//     -> Uses 156-byte allocation
//
//   Format 0x83 (GX_TF_RGB565):  16-bit direct color
//     -> Uses 156-byte allocation
//
//   Format 0x84 (GX_TF_RGB5A3):  16-bit with alpha
//     -> Uses 156-byte allocation (same as 0x83 path)
//
//   Format 0x85 (GX_TF_RGBA8):   32-bit direct color
//     -> Uses direct format handler (same path as 0x01)
//
//   Format 0x89 (GX_TF_CMPR):    S3TC/DXT1 compressed
//     -> Uses C4_32 handler (smaller allocation)
//
//   Format 0x8A (GX_TF_C14X2):   14-bit indexed
//     -> Uses C8_32 handler (larger allocation)
//
// Each handler:
//   1. Calls EAHeap::Alloc(size, 8) to allocate with 8-byte alignment
//   2. Calls a format-specific initializer (ENgcTextureC4_32, ENgcTextureC8_32, etc.)
//   3. Stores the result at this->m_pGXTexObj (offset 0x28)
//   4. If successful, calls the GX texture's virtual Create(textureDef) method
//      via vtable dispatch at offset 0x78/0x7C

// (Decompiled logic -- see disassembly above for exact instruction mapping)


// ============================================================================
// ENgcTexture::Select(int, int)
// Address: 0x8034FA38  Size: 56 bytes
// ============================================================================
//
// Binds this texture to a GX texture unit. Delegates to the internal GX
// texture object's Select() virtual via vtable offset 0xA0/0xA4.
//
// The internal object at this->m_pGXTexObj (offset 0x28) is an ENgcTextureBase
// subclass (ENgcTextureC4_32, ENgcTextureC8_32, or direct format).

void ENgcTexture::Select(int texMapId, int texCoordId) {
    // 0x8034FA38
    void* gxTex = this->m_pGXTexObj;              // lwz r3, 40(r3)  -- offset 0x28
    void** vtbl = *(void***)gxTex;                // lwz r9, 36(r3)  -- offset 0x24 (vtable)
    // Virtual call at vtable+0xA0: Select(texMapId, texCoordId)
    s16 adj = *(s16*)((u8*)vtbl + 0xA0);          // lha r0, 160(r9)
    void* fn = *(void**)((u8*)vtbl + 0xA4);       // lwz r9, 164(r9)
    ((void(*)(void*, int, int))(fn))((u8*)gxTex + adj, texMapId, texCoordId);
}

// ============================================================================
// ENgcTexture::GetTEVStageCount(void)
// Address: 0x8034FAA0  Size: 56 bytes
// ============================================================================
//
// Returns the number of TEV stages required by this texture's internal format.
// Delegates to the GX texture object's virtual at vtable+0x90/0x94.

int ENgcTexture::GetTEVStageCount(void) {
    // 0x8034FAA0
    void* gxTex = this->m_pGXTexObj;              // lwz r3, 40(r3)
    void** vtbl = *(void***)gxTex;
    // Virtual dispatch at vtable+0x90
    s16 adj = *(s16*)((u8*)vtbl + 0x90);          // lha r0, 144(r9)
    void* fn = *(void**)((u8*)vtbl + 0x94);       // lwz r9, 148(r9)
    return ((int(*)(void*))(fn))((u8*)gxTex + adj);
}

// ============================================================================
// ENgcTexture::GetTEXCount(void)
// Address: 0x8034FAD8  Size: 56 bytes
// ============================================================================
//
// Returns the number of GX texture map units required by this texture format.
// For indexed textures (C4, C8, C14), this may be 2 (one for the image,
// one for the palette TLUT). For direct textures, this is 1.

int ENgcTexture::GetTEXCount(void) {
    // 0x8034FAD8
    void* gxTex = this->m_pGXTexObj;              // lwz r3, 40(r3)
    void** vtbl = *(void***)gxTex;
    // Virtual dispatch at vtable+0x98
    s16 adj = *(s16*)((u8*)vtbl + 0x98);          // lha r0, 152(r9)
    void* fn = *(void**)((u8*)vtbl + 0x9C);       // lwz r9, 156(r9)
    return ((int(*)(void*))(fn))((u8*)gxTex + adj);
}


// ============================================================================
// SECTION 6: MODEL SYSTEM (ERModel, ESubModelShader)
// ============================================================================
//
// ERModel (660 bytes) wraps a 3D model composed of one or more ESubModelShaders.
// Each ESubModelShader represents a mesh strip (triangle strip) with its own
// shader assignment, vertex data, and optional morph targets.
//
// ERModel Field Layout:
//   0x000: f32  m_boundMin[3]       -- Bounding box minimum (x, y, z)
//   0x00C: s16  m_boneCount         -- Number of bones for hierarchical models
//   0x010: u32  m_lodLevel          -- Level-of-detail index
//   0x014: u32  m_lodDistance        -- LOD transition distance
//   0x018: u32  m_vertexDataPtr     -- Pointer to shared vertex buffer
//   0x01C: u32  m_boneArray         -- Pointer to bone hierarchy (NULL=static)
//   0x020: u32  m_numStrips         -- Number of strip entries
//   0x024-0x03B: strip config data
//   0x03C: u32  m_pStripArray       -- TArray<ESubModelShader> -- the mesh strips
//   0x040: u32  m_pAttachmentVerts  -- Attachment vertex data (for accessories)
//   0x048: f32  m_boundRadius       -- Bounding sphere radius
//   0x054: f32  m_boundMax          -- Bounding sphere extent
//   0x088: f32  m_scale             -- Global scale factor (default 1.0)
//   0x08C: u32  m_hierarchyData     -- Hierarchical rendering data
//   0x0F0: u32  m_pShadowModel     -- Shadow volume model
//   0x0FC: u32  m_pMorphTargets     -- Morph target array
//   0x100: u32  m_morphFlags        -- Morph system flags
//   0x104: u32  m_pLattices         -- BSpline lattice deformation array
//   0x134-0x135: u8 flags (wall, morphTarget, lattice, weldable)
//   0x138: u32  m_pAttachmentIds    -- Attachment ID array
//   0x13C: u32  m_pAttachmentData   -- Attachment transform data
//   0x174: u32  m_pScaleMatrix      -- Allocated scale matrix (if non-uniform)
//   0x178: u8   m_loadFlags         -- Flags set during loading
//   0x17C: u32  m_uvTransformFlags  -- UV transform capability flags
//   0x290: u32  m_boneMatrices      -- Runtime bone matrices for hierarchical draw
//
// ESubModelShader (116 bytes) Layout:
//   0x000: void** _vtable
//   0x003: u8   m_colorFormat       -- Vertex color format
//   0x004: f32  m_bounds             -- Local bounding info
//   0x006: u16  m_vertexCount       -- Number of vertices
//   0x008: f32  m_pShader           -- ERShader pointer (AddRef'd)
//   0x00C: u32  m_displayListSize   -- Size of prebuilt GX display list
//   0x010: u32  m_pMorphData        -- Morph target vertex deltas
//   0x014: u32  m_pStripData        -- Triangle strip index data
//   0x018: u32  m_pVertexPositions  -- Vertex position array
//   0x020: u32  m_pTexCoords        -- Texture coordinate array
//   0x024: f32  m_morphWeight       -- Current morph interpolation weight
//   0x028: u32  m_pNormals          -- Vertex normal array
//   0x02C: u32  m_pMorphStrips      -- Morph-space strip data
//   0x030: u32  m_pMorphTargetArray -- Array of registered morph targets
//   0x068: u32  m_pLatticeParams    -- BSpline parametrization data
//   0x06C: u32  m_pLatticeList      -- Lattice deformation control point list
//   0x070: u32  m_displayListFlags  -- Display list build flags

// ============================================================================
// ERModel::Draw(ERC *)
// Address: 0x80318B18  Size: 108 bytes
// ============================================================================
//
// Draws all sub-model strips. Iterates over the TArray at offset 0x3C,
// calling each ESubModelShader's draw function. Each strip is 0x18 (24) bytes
// apart in the array.
//
// The draw function at 0x802FAF20 is a non-virtual helper that:
//   1. Selects the strip's ERShader (which configures GX TEV/textures)
//   2. Submits the prebuilt GX display list
//   3. Restores render state

void ERModel::Draw(ERC* rc) {
    // 0x80318B18
    int count = *(int*)((u8*)this + 0x3C + 4);   // lwz r0, 4(r9) -- TArray count at offset 0x40
    u8* stripBase = (u8*)this->m_pStripArray;     // lwz r3, 60(r29)

    for (int i = 0; i < count; i++) {             // cmpw r31, r0; blt loop
        ESubModelShader* strip = (ESubModelShader*)(stripBase + i * 0x18);
        strip->Draw(rc);                          // bl 0x802FAF20
    }
}

// ============================================================================
// ERModel::DrawGeometry(ERC *)
// Address: 0x80318950  Size: 108 bytes
// ============================================================================
//
// Same loop structure as Draw() but calls DrawGeometry() on each strip
// (0x802FB004). DrawGeometry skips shader selection and just submits the
// raw geometry, useful for shadow passes and depth pre-passes where the
// shader is already configured.

void ERModel::DrawGeometry(ERC* rc) {
    // 0x80318950
    int count = *(int*)((u8*)this + 0x3C + 4);   // TArray count
    u8* stripBase = (u8*)this->m_pStripArray;

    for (int i = 0; i < count; i++) {
        ESubModelShader* strip = (ESubModelShader*)(stripBase + i * 0x18);
        strip->DrawGeometry(rc);                  // bl 0x802FB004
    }
}


// ============================================================================
// SECTION 7: FONT RENDERING (ERFont)
// ============================================================================
//
// ERFont (244 bytes) is a bitmap font resource. It loads glyph pages (textures)
// and character metrics, then renders text by submitting textured quads through
// the GX pipeline.
//
// ERFont Field Layout:
//   0x000: f32  m_stringWidth       -- Computed string width (for GetStringSize)
//   0x004: f32  m_stringHeight      -- Computed string height
//   0x008: u32  m_numPages          -- Number of font texture pages
//   0x010: u32  m_formatVersion     -- Font format version from file
//   0x014: u32  m_pCharTable        -- Character lookup table
//   0x018: u32  m_pFontData         -- EFontData pointer (metrics, kerning)
//   0x024: u32  m_lineHeight        -- Pixel line height
//   0x028: u32  m_ascent            -- Ascent from baseline
//   0x02C: u32  m_descent           -- Descent below baseline
//   0x030: u32  m_leading           -- Line leading (extra spacing)
//   0x034: u32  m_spaceWidth        -- Width of space character
//   0x038: u32  m_tabWidth          -- Width of tab character
//   0x04C: f32  m_scaleX            -- Horizontal scale factor
//   0x050: f32  m_scaleY            -- Vertical scale factor
//   0x054: u32  m_sizeFlags         -- Size computation flags
//   0x058: f32  m_dropShadowX       -- Drop shadow X offset
//   0x068: u32  m_currentPage       -- Currently selected glyph page index
//   0x0F0: u32  m_pPageArray        -- Array of glyph page texture pointers
//
// FONT RENDERING PIPELINE:
//
// 1. ERFont::SetSize(scaleX, scaleY, useAspect)
//    - Applies a global screen aspect ratio correction
//    - Searches the font's size table for the closest matching point size
//    - Selects the appropriate glyph page (each page has a different resolution)
//    - Stores the final scale factors at m_scaleX/m_scaleY
//
// 2. ERFont::SetColor(EVec4& color)
//    - Sets the font rendering color (RGBA)
//    - Stored in the active glyph page's material
//
// 3. ERFont::Draw(rc, text, pos, alignX, alignY, ...)
//    - Calls DoDrawAlign() which computes alignment offsets
//    - DoDrawAlign calls DoDraw() which is the core text renderer
//
// 4. ERFont::DoDraw(text, isWide, snapToPixel, wrapText, pos, rc, ...)
//    - This is the 3740-byte monster function (935 instructions!)
//    - Sets up a coordinate system transform if needed (screen-space or 3D-space)
//    - Iterates over each character in the string:
//      a. Looks up the character in m_pCharTable to get glyph metrics
//      b. Calls SelectPage(rc, pageIndex) if the character is on a different page
//      c. Computes the quad vertices: position + glyph width/height * scale
//      d. Computes UV coordinates from the glyph's position in the page texture
//      e. Submits a textured quad via GX immediate mode (GX_Begin/GX_End)
//    - Handles kerning pairs, line breaks, word wrap, and font FX (shake, wave, etc.)
//
// 5. ERFont::SelectPage(rc, pageIndex)
//    - Selects a different glyph texture page for rendering
//    - Each page is an ERTexture containing a grid of glyph images
//    - The function binds the page's ERShader (which contains the texture)
//    - Then calls ERC::SetTEVColor() to set the text color on the GX TEV unit

// ============================================================================
// ERFont::Load(EFile &)
// Address: 0x80314034  Size: 244 bytes
// ============================================================================
//
// Loads a font resource from the archive:
//   1. Calls Deallocate() to clear any existing font data
//   2. Opens an EResourceFile looking for 'FONT' (0x464F4E54), version 10
//   3. If found in new format:
//      a. Reads data size, packs into m_flags
//   4. If not found (legacy format):
//      a. Falls back to stream-based reading via EResource::Read()
//   5. Reads the font character table (at offset 0x14 from this)
//   6. If the font data (offset 0x18) is loaded:
//      a. Extracts the page array pointer from fontData[0]
//      b. Stores it at this+0x54
//      c. Reads the scale factor: converts integer to float via
//         the classic PPC int-to-float trick:
//           stw  int, stack     // store as int
//           stw  0x43300000, stack-4  // magic constant
//           lfd  f0, stack-4   // load as double
//           fsub f0, f0, magic // subtract to get float value
//           frsp f0, f0        // round to single precision
//      d. Stores the scale at this+0x4C (m_scaleX)

void ERFont::Load(EFile& file) {
    // 0x80314034
    this->Deallocate();                           // bl 0x80313FF0

    EResourceFile resFile;
    resFile.Init();                               // bl 0x8035AE70

    u32 signature = 0x464F4E54;                   // 'FONT'
    int version = 10;
    bool found = resFile.Open(&file, signature, version, version); // bl 0x8035B09C

    if (found) {
        // New format: read data size
        u32 dataSize = resFile.GetDataSize();     // bl 0x8035B320
        u32 flags = this->m_flags;
        flags = (dataSize << 8) | (flags & 0xFF); // rlwimi
        this->m_flags = flags;
    } else {
        // Legacy format: stream-based read
        EStream stream;
        stream.Init();
        this->Read(file, &stream);                // bl 0x802C66C0
        stream.Destroy();
    }

    // Read character table (bl 0x802C6760)
    // file.ReadCharTable(&this->m_pCharTable); -- platform-specific, stub

    // Set up font page data
    void* fontData = this->m_pFontData;           // lwz r10, 24(r31)
    if (fontData != NULL) {
        void* pageArray = *(void**)fontData;
        this->m_pPageArray = pageArray;           // stw r10, 84(r31)

        // Convert integer scale to float (PPC int-to-float pattern)
        int rawScale = *(int*)((u8*)pageArray + 4);  // lwz r0, 4(r10)
        // XOR with 0x80000000 to handle sign, use 0x43300000 magic
        float scale = (float)(rawScale);          // int->double->float conversion
        this->m_scaleX = scale;                   // stfs f0, 76(r31)
    }

    resFile.Close(2);                             // bl 0x8035AEA8
}

// ============================================================================
// ERFont::SelectPage(ERC *, int)
// Address: 0x80314298  Size: 240 bytes
// ============================================================================
//
// Switches the active glyph page texture for text rendering. Font glyph images
// are split across multiple texture pages to fit in TMEM; this function binds
// the correct page before drawing characters that reside on it.
//
// The function:
//   1. Checks if pageIndex == current page (early-out if same)
//   2. Updates m_currentPage to the new index
//   3. Reads the page's color data from a global font color table
//      (at 0x804D54B8 + 0x4644, a 3-byte RGB entry)
//   4. Looks up the font page entry: m_pFontData->m_pageTable[pageIndex]
//   5. Gets the ERShader from the page entry's texture field
//   6. Resolves the EShader from the ERShader (same pattern as ERShader::Select)
//   7. Calls EShader::Select(rc, 0) to bind the page texture
//   8. Gets the ERC's SetTEVColor virtual (vtable+0x1C8) and calls it
//      with the page's RGB color values to tint the text

void ERFont::SelectPage(ERC* rc, int pageIndex) {
    // 0x80314298
    if (this->m_currentPage == pageIndex) {       // lwz r0, 104(r3); cmpw r0, r5
        return;                                   // beq end
    }

    this->m_currentPage = pageIndex;              // stw r5, 104(r3)

    // Read font color from global table
    u8* colorTable = (u8*)0x804D9AFC;             // lis r9, 0x804D; addi r9, r9, 0x54B8 (+0x4644)
    u8 r = colorTable[0];                         // lbz r0, 0x4644(r9)
    u8 g = colorTable[1];                         // lbz r11, 0x4645(r9)
    u8 b = colorTable[2];                         // lbz r10, 0x4646(r9)

    // Get the page entry from the font data
    void** pageTable = (void**)this->m_pFontData->m_pageArrayPtr; // lwz r7, 84(r3); lwz r9, 32(r7)
    void* pageEntry = pageTable[pageIndex];       // lwzx r11, r9, r8 (r8 = index*4)

    // Get the page's ERShader (offset 0x08 in page entry)
    ERShader* pageShader = *(ERShader**)((u8*)pageEntry + 0x08);  // lwz r5, 8(r11)

    // Resolve to EShader (same pattern as ERShader::Select)
    EShader* shader;
    if (pageShader->m_pCurrentEShader != NULL) {
        shader = pageShader->m_pCurrentEShader;
    } else if (pageShader->m_pCurrentERShader != NULL) {
        shader = pageShader->m_pCurrentERShader->m_pCurrentEShader;
    } else {
        shader = NULL;
    }

    // Select the page shader
    shader->Select(rc, 0);                        // vtable+0x10: blrl

    // Set text color on TEV (vtable+0x1C8)
    int enableColor = (r != 0) ? 1 : 0;
    rc->SetTEVColorAlpha(enableColor, g, b, 0);  // SetTEVColor maps to SetTEVColorAlpha
}


// ============================================================================
// SECTION 8: RENDERING DATA FLOW SUMMARY
// ============================================================================
//
// A complete frame's rendering of a textured object goes through these steps:
//
// 1. RESOURCE LOOKUP
//    EResourceManager::GetRef(modelId)    -> returns ERModel*
//    EResourceManager::GetRef(shaderId)   -> returns ERShader*
//    EResourceManager::GetRef(textureId)  -> returns ERTexture*
//    All three AddRef the resources. The caller must DelRef when done.
//
// 2. SHADER SETUP (per-frame, if day/night or animated)
//    ERShader::Update(deltaTime, timeOfDay, weather, season)
//      -> If IsDayNightShader(): BlendCurrentShader(blendFactor)
//      -> If weather changed: UpdateWeatherShader(weatherState)
//      -> If state change pending: SetCurrentShaderForState(newState)
//
// 3. DRAW CALL
//    ERModel::Draw(rc)
//      for each ESubModelShader strip:
//        strip->Draw(rc):
//          a. ERShader::Select(rc, flags)        -- bind material
//             -> EShader::Select(rc, flags)
//                -> ENgcShader::Select(rc, flags)
//                   -> For each TEV stage:
//                      ERC::SetTEVStage(params, i)   -- configure combiner
//                   -> ERC::CommitShaderState()       -- flush to GX
//                -> ETexture::Select(texMapId)
//                   -> ENgcTexture::Select(id, coordId)
//                      -> GXLoadTexObj / GXInitTexObj
//
//          b. ESubModelShader::DrawGeometry(rc)  -- submit mesh
//             -> GXCallDisplayList(m_pDisplayList, m_displayListSize)
//             (Or for morphed/deformed meshes: immediate mode GX_Begin/GX_End)
//
// 4. FONT RENDERING (separate path)
//    ERFont::SetSize(scaleX, scaleY, useAspect)
//    ERFont::SetColor(rgba)
//    ERFont::Draw(rc, text, pos, alignX, alignY, ...)
//      -> DoDrawAlign() computes alignment
//      -> DoDraw() iterates characters:
//         for each character:
//           SelectPage(rc, glyphPage)   -- bind correct glyph texture
//           Submit textured quad via GX immediate mode
//
// 5. CLEANUP (level unload or end of use)
//    EResource::DelRef()  -- on each resource
//      -> When refcount hits 0, resource is eligible for eviction
//    EResourceManager::FreeUnreferencedResources()
//      -> Walks the EResourceMap, deletes resources with refcount <= 0
//      -> Calls EResource::SafeDelete() which calls virtual Deallocate()
//         on each resource type (ERTexture::Deallocate frees GX texture, etc.)
//
// ============================================================================
// GX TEV STAGE REFERENCE (for PC port shader generation)
// ============================================================================
//
// The GameCube's TEV (Texture Environment) is a programmable combiner with
// up to 16 stages. Each stage has:
//   - 4 color inputs (a, b, c, d) -> color_out = (d + ((1-c)*a + c*b) + bias) * scale
//   - 4 alpha inputs (a, b, c, d) -> alpha_out = same formula
//   - An operation (add, subtract, compare)
//   - An output register (PREV, REG0, REG1, REG2)
//
// Color input sources (GX_CC_*):
//   0 = CPREV   (previous stage output color)
//   1 = APREV   (previous stage output alpha, replicated to RGB)
//   2 = C0/C1/C2 (constant color registers)
//   3 = A0/A1/A2 (constant alpha, replicated)
//   4 = TEXC    (texture color)
//   5 = TEXA    (texture alpha, replicated)
//   6 = RASC    (rasterized/lit vertex color)
//   7 = RASA    (rasterized vertex alpha, replicated)
//   8 = ONE     (1.0)
//   9 = HALF    (0.5)
//  10 = KONST   (constant color from KONST register)
//  15 = ZERO    (0.0)
//
// The packed TEV values in ENgcShader encode 4 inputs in one byte:
//   packed = in_a | (in_b << 2) | (in_c << 4) | (in_d << 6)
//
// For a PC port, each unique packed value maps to a GLSL fragment shader snippet.
// The most common configurations (from ENgcShader::Create analysis):
//
//   0x4A = TEXC*RASC       -> fragColor = texColor * vertColor;
//   0x5A = TEXC*KONST      -> fragColor = texColor * konstColor;
//   0x6A = TEXC*RASC*KONST -> fragColor = texColor * vertColor * konstColor;
//   0x44 = TEXA*RASA       -> fragAlpha = texAlpha * vertAlpha;
//   0x48 = TEXA*KONSTA     -> fragAlpha = texAlpha * konstAlpha;
//   0x64 = TEXA*RASA*KONSTA -> fragAlpha = texAlpha * vertAlpha * konstAlpha;
//   0x68 = APREV*KONSTA    -> fragAlpha = prevAlpha * konstAlpha;
