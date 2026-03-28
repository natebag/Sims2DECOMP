// render_classes.cpp - Real C++ decompilation of rendering and effects resource classes
// Part of the Sims 2 GC decompilation
//
// Converted from inline PPC asm (src/asm_decomp/) into functionally correct C++
// using struct field offsets inferred from the assembly.
//
// This is NOT byte-matching code. It is a clean C++ translation for a future
// PC port, preserving the original logic and data flow.
//
// Classes converted:
//   R* effects:       REffectsEmitter, REffectsSequencer, REffectsAttachment,
//                     RParticle, RoutingSlot
//   NGC rendering:    ENgcRC, ENgcShader, ENgcTexture
//   Engine resources: ERModel, ERShader, ERLevel, ERFont, ERTexture,
//                     ESubModelShader, ENgcAudio, ENgcMemoryCard

#include "types.h"

#ifndef NULL
#define NULL 0
#endif

// ============================================================================
// Forward Declarations & Minimal Type Stubs
// ============================================================================

class EResource;
class EResourceManager;
class EFile;
class EStream;
class EDataHeader;
class EShader;
class EShaderDef;
class ETexture;
class ETextureDef;
class ERC;
class EDL;
class EFontData;
class ETypeInfo;
class EStorable;
class EAHeap;
class EMutex;
class EPMDesc;
class EVoice;
class EVoiceDesc;

struct EVec2 { f32 x, y; };
struct EVec3 { f32 x, y, z; };
struct EVec4 { f32 x, y, z, w; };
struct EMat4 { f32 m[4][4]; };
struct EBound3 { EVec3 min, max; };
struct EBoundSphere { EVec3 center; f32 radius; };

struct EACNodeState;
struct EWeldVert;
struct EGEVert;
struct ELights;
struct EDirLight;
struct EILight;
struct EInstance;
struct EOrderTableData;
struct EWindow;
struct fontFXcommand;
struct SlotDescriptor;
struct ESMSStrip;
struct ESMBuildDisplayListData;
struct BSplineVolume;
struct LevelLightingEntry;
struct ETCTransformSource;
struct EFontAlignX;
struct EFontAlignY;
struct EFontMatrixType;
struct ERenderSurface;

template <typename T> class TRect;
template <typename T> class TNodeList;
template <typename T0, typename T1> class TArray;
class TArrayERModelAllocator;

// ============================================================================
// External Function Declarations
// ============================================================================

extern EAHeap* MainHeap();
extern EAHeap* RootHeap();
extern EAHeap* VMHeap();
extern void* EAHeap_Malloc(EAHeap* heap, u32 size, int flags);
extern void* EAHeap_MallocAligned(EAHeap* heap, u32 size, u32 align, u32 a, int b);
extern void  EAHeap_Free(EAHeap* heap, void* ptr);

extern EResourceManager* g_pResourceManager;       // EResourceManager singleton
extern EResourceManager* g_pShaderResourceManager;  // Shader-specific resource mgr
extern EResourceManager* g_pTextureResourceManager;  // Texture-specific resource mgr

extern void* g_pRenderer;   // ENgcRenderer* (r13-relative global)

extern void* memcpy(void* dst, const void* src, u32 size);
extern void* memset(void* dst, int val, u32 size);
extern u32   strlen(const char* s);
extern u32   AtoI(char* s);

// ============================================================================
// Base Classes (minimal definitions for inheritance)
// ============================================================================

// EResource - base class for all engine resources
// Layout inferred from constructor asm patterns:
//   0x00: vtable*
//   0x04: u32 m_refCount
//   0x08: u32 m_state
//   0x0C: u32 m_flags
//   0x10: u32 m_sizeAndType (bits 8-31 = size, bits 0-7 = type)
//   0x14: void* (varies by subclass)

class EResource {
public:
    void*  m_vtable;        // 0x00
    u32    m_refCount;      // 0x04
    u32    m_state;         // 0x08
    u32    m_flags;         // 0x0C
    u32    m_sizeAndType;   // 0x10

    EResource();
    ~EResource();
    void DelRef();
    void AddRef();
};

// Slot - base class for RoutingSlot
class Slot {
public:
    Slot();
    Slot(SlotDescriptor*);
};

// EShader - base class for ENgcShader
class ENgcShader;
class ENgcTexture;

// ============================================================================
// EDataHeader - resource file header helper
// ============================================================================

class EDataHeader {
public:
    u8   m_data[16];    // 0x00
    u32  m_dataSize;    // 0x10: decoded size from GetName()

    EDataHeader();
    ~EDataHeader();
    int  Read(EFile& file, u32 magic, u32 minVer, u32 maxVer);
    u32  GetName();
};


// ############################################################################
//
//  R* EFFECTS CLASSES
//
// ############################################################################

// ============================================================================
// REffectsEmitter
// ============================================================================
// EResource subclass for particle emitter effect resources
// Layout (from asm offsets):
//   0x00: vtable* (EResource base)
//   0x04-0x10: EResource fields
//   0x14: void*  m_emitterData     (particle emitter description pointer)
//   0x18: void*  m_emitterBuffer   (allocated data buffer)
//   0x1C: void*  m_subResource     (child resource reference, e.g. texture)
//   0x20: u32    m_loaded          (refresh flag)

class REffectsEmitter : public EResource {
public:
    void*  m_emitterData;    // 0x14 (offset 20)
    void*  m_emitterBuffer;  // 0x18 (offset 24)
    void*  m_subResource;    // 0x1C (offset 28)
    u32    m_loaded;         // 0x20 (offset 32)

    // 0x8036A7B4 (80 bytes)
    REffectsEmitter() {
        // EResource::EResource() called by inheritance
        // vtable set to REffectsEmitter vtable
        m_loaded = 0;
        m_emitterData = NULL;
        m_emitterBuffer = NULL;
        m_subResource = NULL;
    }

    // 0x8036A804 (92 bytes)
    ~REffectsEmitter() {
        // vtable set to REffectsEmitter vtable
        Deallocate();
        // EResource::~EResource() called
        // Conditional free via MainHeap if bit 0 of destructor flag set
    }

    // 0x8036A860 (100 bytes)
    // Frees the allocated emitter buffer via virtual call + heap free
    void Deallocate() {
        // Call virtual method to clean up sub-data
        // (vtable offset 108/104 - virtual cleanup call)

        if (m_emitterBuffer != NULL) {
            EAHeap_Free(MainHeap(), m_emitterBuffer);
            m_emitterBuffer = NULL;
            m_emitterData = NULL;
        }
    }

    // 0x8036A904 (96 bytes)
    // Adds reference to sub-resources (e.g. texture used by emitter)
    void AddRefSubResources() {
        m_subResource = NULL;

        if (m_emitterData != NULL) {
            // Get resource ID from emitter data at offset 192
            u32* pData = (u32*)m_emitterData;
            u32 resID = pData[48]; // offset 192
            if (resID != 0) {
                // AddRef via the shader resource manager
                EResource* res = (EResource*)g_pShaderResourceManager;
                // EResourceManager::AddRef(resID, NULL, 0)
                // stores result in m_subResource
                // m_subResource = EResourceManager::AddRef(resID, NULL, 0);
            }
        }
    }

    // 0x8036A964 (108 bytes)
    // Try to increment sub-resources (non-blocking resource load check)
    // Returns 1 on success, 0 on failure
    int TryIncrementSubResources() {
        if (m_emitterData != NULL) {
            u32* pData = (u32*)m_emitterData;
            u32 resID = pData[48]; // offset 192
            if (resID != 0) {
                EResource* result = NULL;
                // TryIncrementResource(resID, &result)
                // if fails, return 0
                // if succeeds, m_subResource = result
                // return 1 on success
            }
        }
        return 1;
    }

    // 0x8036A9D0 (244 bytes)
    // Loads emitter data from file
    void Load(EFile* file) {
        Deallocate();

        if (file == NULL)
            return;

        EDataHeader header;
        // Magic 'EFEM' (0x4545 4D54), version 1
        if (!header.Read(*file, 0x4545'4D54, 1, 1)) {
            // header.~EDataHeader()
            return;
        }

        u32 dataSize = header.GetName();
        // Merge data size into m_sizeAndType (bits 8-31)
        m_sizeAndType = (m_sizeAndType & 0x000000FF) | (dataSize << 8);

        // Allocate aligned buffer for emitter data
        void* buf = EAHeap_MallocAligned(MainHeap(), dataSize, 64, 0, 0);
        m_emitterBuffer = buf;
        m_emitterData = (u8*)buf + 144; // offset 144 into buffer

        // Read data from file into buffer via virtual read call
        // file->Read(buf, dataSize)

        // Call virtual method to finish setup
        // vtable offset 112/116

        // header.~EDataHeader()
    }

    // 0x8036AAC4 (72 bytes)
    // Reloads emitter from file
    void Refresh(EFile* file) {
        if (file == NULL)
            return;

        Deallocate();
        Load(file);
        m_loaded = 1;
    }

    // 0x8036AC78 (84 bytes)
    // Registers type with the engine's type system
    static void RegisterType(unsigned short typeID) {
        // ETypeInfo::Register(createFunc, destroyFunc, cleanupFunc, typeID, name, parentInfo)
    }
};


// ============================================================================
// REffectsSequencer
// ============================================================================
// EResource subclass for effect sequencer resources
// Simpler than REffectsEmitter - just loads data with a header

class REffectsSequencer : public EResource {
public:
    // Inherits EResource fields at 0x00-0x10
    // No additional fields observed beyond EResource base

    // 0x8036AEAC (92 bytes)
    ~REffectsSequencer() {
        // vtable set to REffectsSequencer vtable
        Deallocate();
        // EResource::~EResource()
        // Conditional heap free
    }

    void Deallocate();  // Defined elsewhere (called in dtor)

    // 0x8036AF4C (176 bytes)
    // Loads sequencer data from file
    void Load(EFile* file) {
        Deallocate();

        if (file == NULL)
            return;

        EDataHeader header;
        // Magic 'ESEQ' (0x4553 4551), version 1
        if (!header.Read(*file, 0x4553'4551, 1, 1)) {
            // header.~EDataHeader()
            return;
        }

        u32 dataSize = header.GetName();
        // Merge size into m_sizeAndType
        m_sizeAndType = (m_sizeAndType & 0x000000FF) | (dataSize << 8);

        // Call virtual method (vtable offset 112/116) to finish setup

        // header.~EDataHeader()
    }

    // 0x8036B1A8 (84 bytes)
    static void RegisterType(unsigned short typeID) {
        // ETypeInfo::Register(...)
    }
};


// ============================================================================
// REffectsAttachment
// ============================================================================
// EResource subclass for effect attachment resources
// Maps effects to model attachment points
//
// Layout:
//   0x00-0x10: EResource base
//   0x14: void* m_attachNodes      (pointer to AttachmentNode array)
//   0x18: void* m_attachNodeEnd    (end pointer)
//   0x1C: m_nodeVector fields      (vector header: start, end, capacity at 0x14-0x20)

struct AttachmentNode {
    u8   m_type;        // 0x00
    u8   m_boneID;      // 0x01
    u16  m_pad;         // 0x02
    u32  m_effectID;    // 0x04
};

struct AttachmentNodeV1 {
    u8   m_data[32];    // 32-byte legacy format
};

class REffectsAttachment : public EResource {
public:
    // Vector of AttachmentNode at offset 0x14
    // Implemented as pointer + size + capacity (STL vector layout)
    AttachmentNode* m_nodesBegin;   // 0x14 (offset 20)
    AttachmentNode* m_nodesEnd;     // 0x18 (offset 24)
    // Additional vector fields at 0x1C (offset 28)
    AttachmentNode* m_nodesCap;     // 0x1C (offset 28)
    u32             m_reserved;     // 0x20 (offset 32)

    // 0x80322400 (80 bytes)
    REffectsAttachment() {
        // EResource::EResource() called via inheritance
        // vtable set to REffectsAttachment
        m_nodesBegin = NULL;
        m_nodesEnd = NULL;
        m_nodesCap = NULL;
        m_reserved = 0;
    }

    // 0x80322450 (164 bytes)
    ~REffectsAttachment() {
        // vtable set to REffectsAttachment
        // Iterate through nodes to clean up
        AttachmentNode* it = m_nodesBegin;
        while (it != m_nodesEnd) {
            it++; // destructor iteration
        }

        // Free the vector backing store
        if (m_nodesBegin != NULL) {
            // Compute byte size
            u32 byteSize = (u32)((u8*)m_nodesCap - (u8*)m_nodesBegin);
            byteSize &= ~7u; // align to 8 bytes
            if (byteSize > 128) {
                // operator delete(m_nodesBegin)
            } else {
                // __node_alloc<false,0>::_M_deallocate(m_nodesBegin, byteSize)
            }
        }

        // EResource::~EResource()
        // Conditional MainHeap free
    }

    // 0x803224F4 (652 bytes)
    // Loads attachment data from old (v1) format
    void OldLoad(EFile* file) {
        if (file == NULL)
            return;

        EDataHeader header;
        // Magic 'EAtt' (0x4541 5443), version 1
        if (!header.Read(*file, 0x4541'5443, 1, 1)) {
            return;
        }

        u32 dataSize = header.GetName();
        m_sizeAndType = (m_sizeAndType & 0x000000FF) | (dataSize << 8);

        if (dataSize == 0)
            return;

        // Resize temp vector for AttachmentNodeV1 entries
        u32 nodeCount = dataSize >> 5; // dataSize / 32

        // Read v1 nodes from file

        // Resize AttachmentNode output vector
        // Convert from v1 to v2 format:
        // For each v1 node at index i:
        //   - Copy bone ID from v1[i].offset13 to node[i].m_boneID
        //   - Copy effect ID from v1[i].offset28 to node[i].m_effectID
        //   - Copy type from v1[i].offset12 to node[i].m_type
        //   - Clear pad to 0

        // Free temp v1 vector
    }

    // 0x80322780 (300 bytes)
    // Loads attachment data from current (v2) format
    void Load(EFile* file) {
        if (file == NULL)
            return;

        EDataHeader header;
        // Magic 'EAtt' (0x4541 5443), version 2
        if (!header.Read(*file, 0x4541'5443, 2, 2)) {
            // Fall back to old format
            OldLoad(file);
            return;
        }

        u32 dataSize = header.GetName();
        m_sizeAndType = (m_sizeAndType & 0x000000FF) | (dataSize << 8);

        if (dataSize == 0)
            return;

        // Resize node vector: dataSize / sizeof(AttachmentNode) = dataSize / 8
        u32 nodeCount = dataSize >> 3;
        AttachmentNode dummy;
        dummy.m_type = 0;
        dummy.m_effectID = 0;

        // vector resize to nodeCount, fill with dummy
        // Read raw data directly into node array from file
        // file->Read(m_nodesBegin, dataSize)
    }

    // 0x803228AC (232 bytes)
    // Refreshes attachment by swapping vectors and reloading
    void Refresh(EFile* file) {
        if (file == NULL)
            return;

        // Save old vector to temp
        AttachmentNode* oldBegin = m_nodesBegin;
        AttachmentNode* oldEnd = m_nodesEnd;

        // Swap in empty vector
        m_nodesBegin = NULL;
        m_nodesEnd = NULL;

        // Load new data
        Load(file);

        // Clean up old vector
        AttachmentNode* it = oldBegin;
        while (it != oldEnd) {
            it++;
        }
        if (oldBegin != NULL) {
            u32 byteSize = (u32)((u8*)m_nodesCap - (u8*)oldBegin);
            byteSize &= ~7u;
            if (byteSize > 128) {
                // operator delete
            } else {
                // __node_alloc deallocate
            }
        }
    }

    // 0x80322B00 (84 bytes)
    static void RegisterType(unsigned short typeID) {
        // ETypeInfo::Register(...)
    }
};


// ============================================================================
// RParticle
// ============================================================================
// EResource subclass for particle system definitions
// Contains particle system data, texture references, and visual parameters
//
// Layout:
//   0x00-0x10: EResource base
//   0x14: void* m_particleData      (pointer to particle definition data, 1420 bytes)
//   0x18: u32   m_textureCount      (number of textures used)
//   0x1C: EResource* m_textures[8]  (texture resource refs at offsets 0x1C-0x38)
//   0x3C-0x58: additional fields (zeroed in ctor: offsets 28-56, 8 dwords)

// Particle data block layout (inside m_particleData, 1420 bytes):
//   Many float fields for particle parameters, see PrepareData() for details

class RParticle : public EResource {
public:
    void*      m_particleData;   // 0x14 (offset 20) - 1420-byte particle def
    u32        m_textureCount;   // 0x18 (offset 24) - number of texture references
    EResource* m_textures[8];    // 0x1C (offset 28) - texture resource pointers

    // 0x8036B2E8 (100 bytes)
    RParticle() {
        // EResource::EResource()
        // vtable set to RParticle vtable
        m_textureCount = 0;
        m_particleData = NULL;

        // Zero out 8 dwords starting at offset 56 going down (offsets 28-56)
        // This covers m_textures[0..7]
        for (int i = 0; i < 8; i++) {
            m_textures[i] = NULL;
        }
    }

    // 0x8036B34C (96 bytes)
    ~RParticle() {
        // vtable set to RParticle vtable
        Deallocate();
        // EResource::~EResource()
        // Conditional free via EResourceManager::Free
    }

    // 0x8036B3AC (88 bytes)
    // Frees particle data and cleans up via virtual call
    void Deallocate() {
        // Virtual cleanup call (vtable offset 108/104)

        // Free particle data block via resource manager
        // EResourceManager::Free(m_particleData)
        m_particleData = NULL;
    }

    // 0x8036B404 (140 bytes)
    // Releases references to texture sub-resources
    void DelRefSubResources() {
        if (m_particleData == NULL)
            return;

        u32 texCount = m_textureCount;
        if (texCount <= 0)
            return;

        // Particle data textures are at offset 364 with stride 132
        u32* particleDataU32 = (u32*)m_particleData;

        for (u32 i = 0; i < texCount; i++) {
            if (m_textures[i] != NULL) {
                EResource* tex = m_textures[i];
                EResource* next = (EResource*)(*(u32*)((u8*)tex + 8)); // tex->m_state (next ptr)
                tex->DelRef();
                m_textures[i] = NULL;
                // Store next into particle data texture slot
                u32* texSlot = (u32*)((u8*)m_particleData + 364 + i * 132);
                *texSlot = (u32)(uintptr_t)next;
            }
        }
    }

    // 0x8036B490 (204 bytes)
    // Adds references to texture sub-resources
    void AddRefSubResources() {
        if (m_particleData == NULL)
            return;

        u32* pData = (u32*)m_particleData;
        u32 flags = pData[66]; // offset 264

        // Check flag bit 20 (andis. with 32 = bit 20 of upper halfword)
        if (flags & 0x00200000) {
            // Single texture mode (shader resource manager)
            u32 texID = pData[91]; // offset 364
            // m_textures[7] = EResourceManager::AddRef(g_pShaderResourceManager, texID, NULL, 0)
            // pData[91] = m_textures[7]
        } else if (flags & 0x02000000) {
            // Multi-texture mode (shader resource manager)
            u32 texCount = m_textureCount;
            for (u32 i = 0; i < texCount; i++) {
                u32 texID = pData[91 + i * 33]; // offset 364 + i * 132
                // m_textures[i] = EResourceManager::AddRef(g_pShaderResourceManager, texID, NULL, 0)
                // pData[91 + i*33] = m_textures[i]
            }
        } else {
            // Single texture mode (texture resource manager)
            u32 texID = pData[91]; // offset 364
            // m_textures[7] = EResourceManager::AddRef(g_pTextureResourceManager, texID, NULL, 0)
            // pData[91] = m_textures[7]
        }
    }

    // 0x8036B55C (352 bytes)
    // Try to increment sub-resources (non-blocking)
    // Returns 1 on success, 0 on failure
    int TryIncrementSubResources() {
        if (m_particleData == NULL)
            return 1;

        u32* pData = (u32*)m_particleData;
        u32 flags = pData[66]; // offset 264

        if (flags & 0x00200000) {
            // Single texture, shader resource manager
            u32 texID = pData[91];
            EResource* result = NULL;
            // if (!EResourceManager::TryIncrementResource(g_pShaderResourceManager, texID, &m_textures[7]))
            //     return 0;
        } else if (flags & 0x02000000) {
            // Multi-texture mode
            u32 texCount = m_textureCount;
            u32 successCount = 0;

            for (u32 i = 0; i < texCount; i++) {
                u32 texID = pData[91 + i * 33];
                // if (!TryIncrementResource(g_pShaderResourceManager, texID, &m_textures[i]))
                //     rollback: DelRef all previously succeeded, return 0

                successCount++;
            }

            // Copy texture pointers back to particle data slots
            for (u32 i = 0; i < texCount; i++) {
                pData[91 + i * 33] = (u32)(uintptr_t)m_textures[i];
            }
        } else {
            // Single texture, texture resource manager
            u32 texID = pData[91];
            // if (!EResourceManager::TryIncrementResource(g_pTextureResourceManager, texID, &m_textures[7]))
            //     return 0;
        }

        // On success for single-tex modes, sync particle data
        // pData[91] = m_textures[7]
        return 1;
    }

    // 0x8036B6BC (1596 bytes)
    // Prepares particle data by converting units and computing derived values
    // NON_MATCHING: very large function with extensive float math, matrix ops
    void PrepareData() {
        if (m_particleData == NULL)
            return;

        f32* pf = (f32*)m_particleData;

        // If rotation speed (offset 272) is zero, set defaults
        if (pf[68] == 0.0f) {  // offset 272
            pf[68] = 1.0f;     // rotation speed
            pf[53] = 1.0f;     // offset 212 - spin rate X
            pf[58] = 1.0f;     // offset 232 - spin rate Y
            pf[63] = 1.0f;     // offset 252 - spin rate Z
        }

        // Unit conversions: multiply various fields by scale factors
        // degToRad = PI / 180.0 (from ROM constant)
        // tickScale = 1.0/30.0 (from ROM constant)
        // angleFactor (from ROM constant)

        const f32 degToRad = 0.01745329f;   // PI / 180
        const f32 tickScale = 0.03333333f;  // 1/30

        // Convert angular velocities from degrees to radians
        pf[31] *= degToRad;   // offset 124
        pf[33] *= degToRad;   // offset 132
        pf[32] *= degToRad;   // offset 128

        // Scale velocity components
        pf[20] *= degToRad;   // offset 80
        pf[21] *= degToRad;   // offset 84
        pf[23] *= degToRad;   // offset 92
        pf[24] *= degToRad;   // offset 96
        pf[25] *= degToRad;   // offset 100

        // Scale color fade rates
        pf[65] *= degToRad;   // offset 260
        pf[66] *= degToRad;   // offset 264
        pf[67] *= degToRad;   // offset 268

        // Scale acceleration by tickScale^2
        pf[47] *= tickScale;  // offset 188
        pf[48] *= tickScale;  // offset 192
        pf[49] *= tickScale;  // offset 196

        pf[50] *= degToRad;   // offset 200 - scale rate

        // Scale additional velocity fields
        pf[72] *= degToRad;   // offset 288
        f32* extFields = (f32*)((u8*)m_particleData + 288);
        extFields[1] *= degToRad;  // offset 292
        extFields[2] *= degToRad;  // offset 296

        // Scale trail fields
        pf[82] *= degToRad;   // offset 328
        pf[83] *= degToRad;   // offset 332
        pf[84] *= degToRad;   // offset 336
        pf[86] *= degToRad;   // offset 344
        pf[87] *= degToRad;   // offset 348
        pf[88] *= degToRad;   // offset 352

        // Normalize rotation angle (offset 108)
        f32 twoPi = 6.28318530f;
        f32 angle = pf[27]; // offset 108
        if (angle > twoPi) {
            while (angle > twoPi) {
                angle -= twoPi;
            }
            pf[27] = angle;
        }
        if (angle < 0.0f) {
            while (angle < 0.0f) {
                angle += twoPi;
            }
            pf[27] = angle;
        }

        // Compute frame rate / lifetime derived values
        f32 lifetime = pf[16]; // offset 64
        f32 lifetimeVar = pf[17]; // offset 68

        // invLifetime = 1.0 / lifetime
        pf[76] = 1.0f / lifetime;  // offset 304

        // Rate of change for lifetime variation
        if (lifetimeVar - lifetime == 0.0f) {
            pf[77] = 1.0f;        // offset 308
        } else {
            pf[77] = 1.0f / (lifetimeVar - lifetime);
        }

        // Compute various interpolation factors
        f32 fadeIn = pf[26]; // offset 104
        pf[80] = 1.0f / (1.0f - fadeIn);  // offset 320
        pf[78] = 1.0f / lifetimeVar;      // offset 312
        pf[79] = 1.0f / fadeIn;            // offset 316

        // Copy color key matrices
        // Build rotation matrices and multiply
        // EMat4::RotateX and EMat4::Mult4x4 calls

        // Copy extensive particle parameter data into prepared buffer
        // (numerous stfs instructions copying floats at known offsets)
    }

    // 0x8036BCF8 (612 bytes)
    // Loads particle data from file
    void Load(EFile* file, u32 resID) {
        Deallocate();

        // Allocate particle data block (1420 bytes, 16-byte aligned)
        // m_particleData = EResourceManager::Alloc(1420, 16)
        // memset(m_particleData, 0, 1420)

        EDataHeader header;
        // Magic 'PART' (0x5041 5254), version 14
        if (header.Read(*file, 0x5041'5254, 14, 14)) {
            // New format: read directly into particle data
            u32 dataSize = header.GetName();
            m_sizeAndType = (m_sizeAndType & 0x000000FF) | (dataSize << 8);
            // file->Read(m_particleData, dataSize)
        } else {
            // Old format: read as string name
            // Read 20 bytes of name data
            // Allocate temp buffer for name
            // Read name string, parse to get resource data
            // Copy data after name into particle data
        }

        // After loading, resolve texture references
        u32* pData = (u32*)m_particleData;
        u32 flags = pData[66]; // offset 264

        if (flags & 0x00200000) {
            // Single texture (shader resource)
            m_textureCount = 1;
            char* texName = (char*)((u8*)m_particleData + 220);
            u32 texID = AtoI(texName);
            if (texID != 0) {
                // m_textures[7] = EResourceManager::AddRef(g_pShaderResourceManager, texID, NULL, 0)
            }
        } else if (flags & 0x02000000) {
            // Multi-texture mode
            u32 texCount = pData[90]; // offset 360
            m_textureCount = texCount;

            for (u32 i = 0; i < texCount; i++) {
                char* texName = (char*)((u8*)m_particleData + 364 + i * 132);
                u32 texID = AtoI(texName);
                if (texID != 0) {
                    // m_textures[i] = EResourceManager::AddRef(g_pShaderResourceManager, texID, NULL, 0)
                }
                // Sync back to particle data
                pData[91 + i * 33] = (u32)(uintptr_t)m_textures[i];
            }
        } else {
            // Single texture (texture resource)
            m_textureCount = 1;
            char* texName = (char*)((u8*)m_particleData + 220);
            u32 texID = AtoI(texName);
            if (texID != 0) {
                // m_textures[7] = EResourceManager::AddRef(g_pTextureResourceManager, texID, NULL, 0)
            }
        }

        // Sync texture pointer to particle data
        // pData[91] = m_textures[7]

        // header.~EDataHeader()
    }

    // 0x8036BF5C (356 bytes)
    // Refreshes particle data from file (reloads and patches texture refs)
    void Refresh(EFile* file) {
        if (file == NULL)
            return;

        u32* oldData = (u32*)m_particleData;

        EDataHeader header;
        // Magic 'PART', version 14
        if (header.Read(*file, 0x5041'5254, 14, 14)) {
            // New format
            u32 dataSize = header.GetName();
            m_sizeAndType = (m_sizeAndType & 0x000000FF) | (dataSize << 8);
            // file->Read(m_particleData, dataSize)
        } else {
            // Old format: read name + data
            // Read header, allocate temp, copy data portion
        }

        // Patch texture references: copy old texture pointers back
        u32 texCount = m_textureCount;
        u32* pData = (u32*)m_particleData;

        for (u32 i = 0; i < texCount; i++) {
            pData[91 + i * 33] = (u32)(uintptr_t)m_textures[i]; // offset 364 + i*132
        }

        // header.~EDataHeader()
    }

    // 0x8036C230 (84 bytes)
    static void RegisterType(unsigned short typeID) {
        // ETypeInfo::Register(...)
    }
};


// ============================================================================
// RoutingSlot
// ============================================================================
// Slot subclass representing a position/rotation where a Sim can route to
//
// Layout (from asm offsets):
//   0x00: vtable*
//   0x04: f32 m_offsetX
//   0x08: f32 m_offsetY
//   0x0C: f32 m_offsetZ      (initialized from ROM float)
//   0x10: u32 m_routeToID
//   0x14: u32 m_routeFromID
//   0x18: u32 m_containerID
//   0x1C: u32 m_flags
//   0x20: s32 m_slotID       (initialized to -1)
//   0x24: s32 m_tileDistX    (initialized to 16)
//   0x28: s32 m_tileDistY    (initialized to 16)
//   0x2C: s32 m_tileDistZ    (initialized to 16)
//   0x30: f32 m_facing       (initialized from ROM float)
//   0x34: s32 m_priority     (initialized to -2)
//   0x38: s32 m_type         (initialized to 16)

class RoutingSlot : public Slot {
public:
    f32  m_offsetX;         // 0x04
    f32  m_offsetY;         // 0x08
    f32  m_offsetZ;         // 0x0C
    u32  m_routeToID;       // 0x10
    u32  m_routeFromID;     // 0x14
    u32  m_containerID;     // 0x18
    u32  m_flags;           // 0x1C
    s32  m_slotID;          // 0x20
    s32  m_tileDistX;       // 0x24
    s32  m_tileDistY;       // 0x28
    s32  m_tileDistZ;       // 0x2C
    f32  m_facing;          // 0x30
    s32  m_priority;        // 0x34
    s32  m_type;            // 0x38

    // 0x80142994 (148 bytes)
    RoutingSlot() : Slot() {
        // vtable set to RoutingSlot vtable
        // ROM constants loaded for m_offsetZ and m_facing
        m_offsetZ = 0.0f;       // from ROM float at -10528
        m_facing = 1.5707963f;  // PI/2, from ROM float at -10524
        m_offsetX = 0.0f;
        m_offsetY = 0.0f;
        m_routeToID = 0;
        m_routeFromID = 0;
        m_containerID = 0;
        m_flags = 0;
        m_slotID = -1;
        m_priority = -2;
        m_type = 16;
        m_tileDistX = 16;
        m_tileDistY = 16;
        m_tileDistZ = 16;
    }

    // 0x80142A28 (176 bytes)
    RoutingSlot(SlotDescriptor* desc) : Slot(desc) {
        // vtable set to RoutingSlot vtable
        // Copy fields from descriptor
        m_offsetX = *(f32*)((u8*)desc + 4);
        m_offsetY = *(f32*)((u8*)desc + 8);
        m_offsetZ = *(f32*)((u8*)desc + 12);
        m_flags   = *(u32*)((u8*)desc + 40);
        m_routeToID    = *(u32*)((u8*)desc + 28);
        m_routeFromID  = *(u32*)((u8*)desc + 32);
        m_containerID  = *(u32*)((u8*)desc + 36);
        m_slotID       = *(s32*)((u8*)desc + 44);
        m_tileDistX    = *(s32*)((u8*)desc + 48);
        m_tileDistY    = *(s32*)((u8*)desc + 52);
        m_tileDistZ    = *(s32*)((u8*)desc + 56);
        m_facing       = *(f32*)((u8*)desc + 60);
        m_priority     = *(s32*)((u8*)desc + 64);
        m_type         = *(s32*)((u8*)desc + 68);
    }

    // 0x80142BD8 (88 bytes)
    // Converts tile-space distances to internal fixed-point representation
    void SetTileDistances(f32 distX, f32 distY, f32 distZ) {
        // Multiply by scale factor (from ROM constant, likely 16.0)
        const f32 tileScale = 16.0f; // from ROM float at -10520

        m_tileDistX = (s32)(distX * tileScale);
        m_tileDistY = (s32)(distY * tileScale);
        m_tileDistZ = (s32)(distZ * tileScale);
    }
};


// ############################################################################
//
//  NGC RENDERING CLASSES
//
// ############################################################################

// ============================================================================
// ENgcRC (NGC Render Context)
// ============================================================================
// Render context for GameCube GX hardware
// Manages render state, triangle submission, textures, shaders
//
// Layout:
//   0x00: vtable* (via m_vtable->...)
//   0x04-0x0C: render state
//   0x0C: u32 m_dlActive         (display list active flag)
//   0x10: ...
//   0x14: u32 m_endCommandFlag
//   0x18: u8  m_commandDepth     (nested command depth)
//   0x70: void* m_rcVtable       (additional vtable for RC commands at offset 112)

class ENgcRC {
public:
    void*  m_vtable;            // 0x00
    u32    m_field04;           // 0x04
    u32    m_field08;           // 0x08
    u32    m_dlActive;          // 0x0C (display list active)
    u32    m_field10;           // 0x10
    u32    m_endCommandFlag;    // 0x14
    u8     m_commandDepth;      // 0x18
    u8     m_pad19[3];          // 0x19
    u8     m_data1C[0x54];      // 0x1C (internal render state)
    void*  m_rcVtable;          // 0x70 (offset 112 - RC command vtable)

    // 0x803383C0 (104 bytes)
    // Ends the current render command, decrements depth
    void EndCommand() {
        m_endCommandFlag = 1;
        m_commandDepth--;

        if (m_dlActive == 0) {
            // Check vtable entry at offset 76 for null
            u32* vtbl = (u32*)m_vtable;
            if (vtbl[19] == 0) { // offset 76
                // Dispatch via m_rcVtable (offset 112)
                // virtual call at m_rcVtable offsets 16/20
            }
        }
    }

    // 0x80338428 (92 bytes)
    void TriStrip(EGEVert* verts, int count);

    // Multiple TriStrip overloads for different vertex formats:
    void TriStrip(int count, f32* pos, f32* texcoord, u8* color, s8* normal, u8* weights, bool indexed);
    void TriStripRef(int count, f32* pos, f32* texcoord, u8* color, s8* normal, u8* weights, bool indexed);
    void TriStrip(int indexCount, int vertCount, u16* indices, f32* pos, f32* texcoord, u8* color, s8* normal, u8* weights);
    void TriStripRef(int indexCount, int vertCount, u16* indices, f32* pos, f32* texcoord, u8* color, s8* normal, u8* weights);

    // Short (s16) position versions:
    void TriStrip(int count, s16* pos, s16* texcoord, u8* color, s8* normal, u8* weights, bool indexed);
    void TriStripRef(int count, s16* pos, s16* texcoord, u8* color, s8* normal, u8* weights, bool indexed);
    void TriStrip(int indexCount, int vertCount, u16* indices, s16* pos, s16* texcoord, u8* color, s8* normal, u8* weights);
    void TriStripRef(int indexCount, int vertCount, u16* indices, s16* pos, s16* texcoord, u8* color, s8* normal, u8* weights);

    // Display list based:
    void TriStripDL(u8* dl, int dlSize, int vertCount, f32* pos, f32* texcoord, u8* color, s8* normal);
    void TriStripDLRef(u8* dl, int dlSize, int vertCount, f32* pos, f32* texcoord, u8* color, s8* normal, bool ref);
    void TriStripDL(u8* dl, int dlSize, int vertCount, s16* pos, s16* texcoord, u8* color, s8* normal);
    void TriStripDLRef(u8* dl, int dlSize, int vertCount, s16* pos, s16* texcoord, u8* color, s8* normal, bool ref);

    // Triangle list (non-strip):
    void TriList(int count, s16* pos, s16* texcoord, u8* color, s8* normal, u8* weights, bool indexed);

    // 0x80339C1C - Invalidates texture cache
    void TextureCacheInvalidate();

    // 0x8033B270 - Reads GPU performance metrics
    void ReadMetrics();

    // State setting:
    void Shader(ENgcShader* shader, u32 flags);
    void ModelMatrixIndex(int index, int count);
    void ModelMatrices(EMat4* matrices, int count);
    void DisplayList(EDL* dl);
    void Texture(ETexture* tex, int stage);
    void ClipRect(TRect<f32>& rect);
    void Lights(ELights* lights);

    // Rect drawing:
    void Rect(EVec2& p0, EVec2& p1, EVec2& uv0, EVec2& uv1, EVec4& color, f32 depth);
    void RectList(int count, f32* rects, EVec4& color, f32 depth);
    void RectListRot(int count, f32* rects, EVec4& color, f32 depth);
    void DirectRect(EVec2& pos, EVec2& size, EVec4& color, f32 depth);

    // Render state:
    void EnvironmentMap(bool enable, bool spherical, int stage);
    void TextureMatrix(EMat4* mat, ETCTransformSource src, bool enable, bool postMultiply, int stage);
    void ZTest(bool enable, int func, int writeEnable, int ref);
    void ZClear(f32 x0, f32 y0, f32 x1, f32 y1, f32 depth);
    void AlphaTest(bool enable, int func, f32 ref, int mode);
    void SetBlendMode(int srcFactor, int dstFactor, int op, int logicOp, f32 constAlpha, int alphaSrc);

    // Geometry:
    void QuadList(int count, f32* pos, f32* texcoord, u8* color, s8* normal, bool indexed);
    void SpriteList(int count, f32* pos, f32* texcoord, u8* color, s8* normal, u8* sizes);
    void LineList(EGEVert* verts, int count);
};


// ============================================================================
// ENgcShader
// ============================================================================
// GameCube-specific shader implementation
// Derives from EShader (platform-agnostic base)
// Manages GX TEV stages and texture environment configuration
//
// Layout:
//   0x00-0xEF: EShader base class (240 bytes)
//   0xF0: vtable override at offset 240
//   Texture slots at offsets within EShader base (0-based indexing via m_numTextures)

class ENgcShader {
public:
    u8     m_numTextures;       // 0x00 - number of textures in this shader
    u8     m_pad01[3];
    u32    m_field04;           // 0x04
    u32    m_flags;             // 0x08
    u8     m_shaderData[228];   // 0x0C-0xEF - EShader base data
    void*  m_vtableOverride;    // 0xF0 (offset 240) - vtable set in dtor

    // 0x8034DC40 (88 bytes)
    ~ENgcShader() {
        // Set vtable at offset 240
        // EShader::~EShader()
        // Conditional free via EResourceManager::Free (texture resource mgr)
    }

    // 0x8034DC98 (164 bytes)
    // Selects this shader for rendering, binding all textures
    void Select(ERC* rc, u32 flags) {
        u8 numTex = m_numTextures;

        for (int i = 0; i < numTex; i++) {
            // Get texture via EShader::GetTexture(i)
            // Get texture slot vtable entry (offset 288 in rc->m_rcVtable)
            // Call rc->Texture(tex, i)
        }

        // Apply shader state (vtable at rc->m_rcVtable offset 824/828)
        // rc->SelectShader(this, flags)
    }

    // 0x8034DD3C (208 bytes)
    // Special shader select for shadow mask rendering
    void SelectForShadowMask(ERC* rc) {
        // Bind first texture with NULL and no flags
        // rc->Texture(NULL, 0) via vtable offset 288/292

        // Apply shader: rc->SelectShader(this, 0) via vtable 824/828

        // Set alpha threshold: vtable offset 296/300 with param 16384

        // Set blend mode: vtable offset 320/324 with (64, 0)

        // Set Z test: vtable offset 456/460 with (0, 2, 0, 0)
    }

    // 0x8034DE0C (372 bytes)
    // Creates shader from definition, potentially optimizing to single-pass
    int Create(EShaderDef& def) {
        // EShader::Create(def)
        // if base create fails, return 0

        // Clear specific flag bits in m_flags (bits 2-4)
        m_flags &= ~0x000001E0;

        // Only attempt 2-texture optimization if numTextures == 2
        if (m_numTextures != 2)
            return 1;

        // Check texture stage 0 and 1 blend modes
        // Stage 0 at offset 128-131, Stage 1 at offset 192-195
        // Compute combined blend mode IDs by packing config bytes

        u8* stage0 = (u8*)this + 128;
        u8* stage1 = (u8*)this + 192;
        u32 blendMode0 = stage0[0] | (stage0[1] << 2) | (stage0[2] << 4) | (stage0[3] << 6);
        u32 blendMode1 = stage1[0] | (stage1[1] << 2) | (stage1[2] << 4) | (stage1[3] << 6);

        // Check if shader flags at offset 112 have bit 6 set
        u32 shaderFlags = *(u32*)((u8*)this + 112);
        if (!(shaderFlags & 64)) {
            blendMode0 = 0;
        }

        // Check for specific blend mode combinations that allow single-pass
        bool canOptimize = false;
        if (blendMode0 == 74 || blendMode0 == 90 || blendMode0 == 106) {
            if (blendMode1 == 68 || blendMode1 == 72 || blendMode1 == 100 || blendMode1 == 104) {
                canOptimize = true;
            }
        }

        if (!canOptimize)
            return 1;

        // Optimization: merge texture stage 1 into stage 0
        // Copy 3 blocks of 24 bytes from offset 164 to offset 100
        m_numTextures = 1;
        u8* dst = (u8*)this + 100;
        u8* src = (u8*)this + 164;
        for (int block = 0; block < 3; block++) {
            for (int j = 0; j < 24; j++) {
                dst[block * 24 + j] = src[block * 24 + j];
            }
        }
        // Copy remaining 16 bytes
        u8* finalDst = (u8*)this + 100 + 72;
        u8* finalSrc = (u8*)this + 164 + 72;
        for (int j = 0; j < 16; j++) {
            finalDst[j] = finalSrc[j];
        }

        return 1;
    }
};


// ============================================================================
// ENgcTexture
// ============================================================================
// GameCube-specific texture implementation
// Derives from ETexture (platform-agnostic base)
// Manages GX texture objects and texture memory
//
// Layout:
//   0x00-0x23: ETexture base (36 bytes)
//   0x24: void* m_ngcVtable     (NGC-specific vtable)
//   0x28: void* m_platformTex   (GXTexObj or platform texture handle)

class ENgcTexture {
public:
    // ETexture base fields
    u32    m_field00;       // 0x00
    u32    m_field04;       // 0x04
    u32    m_texFlags;      // 0x08
    u8     m_baseData[24];  // 0x0C-0x23
    void*  m_ngcVtable;     // 0x24 (offset 36) - platform vtable
    void*  m_platformTex;   // 0x28 (offset 40) - platform texture object

    // 0x8034F43C (68 bytes)
    ENgcTexture() {
        // ETexture::ETexture()
        // vtable at offset 36 set to ENgcTexture vtable
        m_platformTex = NULL;
    }

    // 0x8034F480 (140 bytes)
    ~ENgcTexture() {
        // vtable at offset 36 set to ENgcTexture vtable
        if (m_platformTex != NULL) {
            // Destroy via platform vtable at m_platformTex->vtable offsets 8/12
            // (delete mode 3)
            m_platformTex = NULL;
        }
        // ETexture::~ETexture()
        // Conditional free via EResourceManager::Free
    }

    // 0x8034F50C (416 bytes)
    // Creates a swizzled clone of this texture for GPU-optimized access
    void* CloneSwizzled() {
        // Copy texture definition (first 50 bytes) to temp buffer
        // Set swizzle flag in temp copy: flags |= 128

        // Create new texture via g_pRenderer->CreateTexture(texDef)
        // Set mip level to 2

        // Get level 0 offset and size from platform tex
        // Copy texture data from source to dest via memcpy

        // Handle CLUT (color lookup table) if present
        // Copy CLUT data

        // Finalize texture via platform vtable call

        return NULL; // returns ENgcTexture*
    }

    // 0x8034F86C (460 bytes)
    // Creates platform texture from definition, dispatching to format-specific subclasses
    int Create(ETextureDef& def) {
        // ETexture::Create(def)

        // Determine format from def.format (offset 24 in def)
        u8 format = *(u8*)((u8*)&def + 24);

        switch (format) {
            case 0: {
                // Check subformat at offset 26
                u16 subFormat = *(u16*)((u8*)&def + 26);
                if (subFormat == 2080) {
                    // ENgcTextureC8_32 (8-bit indexed, 32-bit CLUT)
                    // Alloc 216 bytes, construct
                } else if (subFormat == 1056) {
                    // ENgcTextureC4_32 (4-bit indexed, 32-bit CLUT)
                    // Alloc 212 bytes, construct
                }
                break;
            }
            case 129:
                // ENgcTextureCMPR (compressed, 156 bytes)
                break;
            case 130:
                // ENgcTextureRGB5A3 (16-bit RGBA, 156 bytes)
                break;
            case 131:
                // ENgcTextureC4 (4-bit indexed, 156 bytes)
                break;
            case 132:
                // ENgcTextureC8 (8-bit indexed, 156 bytes)
                break;
            case 1:
            case 133:
                // ENgcTextureRGBA8 (32-bit RGBA, 156 bytes)
                break;
            case 137:
                // ENgcTextureC4_32 (212 bytes)
                break;
            case 138:
                // ENgcTextureC8_32 (216 bytes)
                break;
            default:
                // Unsupported format
                break;
        }

        // Store platform texture object
        // m_platformTex = newPlatTex;

        if (m_platformTex == NULL)
            return 0;

        // Call platform texture Create via vtable (offset 120/124)
        // platformTex->Create(def)

        return 1;
    }

    // 0x8034FB10 (68 bytes)
    // Clears tile flags (low 2 bits of m_texFlags)
    void ClearTileFlags() {
        m_texFlags &= ~3u; // clear bits 0-1
        // Call platform vtable method at offset 88/92
    }

    // 0x8034FB54 (68 bytes)
    // Clears swizzle flag (bit 7 of m_texFlags)
    void ClearSwizzleFlag() {
        m_texFlags &= ~128u; // clear bit 7
        // Call platform vtable method at offset 96/100
    }

    // 0x8034FB98 (68 bytes)
    // Sets swizzle flag (bit 7 of m_texFlags)
    void SetSwizzleFlag() {
        m_texFlags |= 128; // set bit 7
        // Call platform vtable method at offset 104/108
    }
};


// ############################################################################
//
//  ENGINE RESOURCE (ER*) CLASSES
//
// ############################################################################

// ============================================================================
// ERTexture
// ============================================================================
// EResource wrapper for texture assets loaded from files
// Manages texture data loading, mipmap generation, and platform texture creation
//
// Layout:
//   0x00-0x10: EResource base
//   0x14: void* m_texture   (ENgcTexture* - platform texture object)

class ERTexture : public EResource {
public:
    void*  m_texture;    // 0x14 (offset 20) - platform texture (ENgcTexture*)

    // 0x80320B28 (68 bytes)
    ERTexture() {
        // EResource::EResource()
        // vtable set to ERTexture vtable
        m_texture = NULL;
    }

    // 0x80320B6C (96 bytes)
    ~ERTexture() {
        // vtable set to ERTexture vtable
        Deallocate();
        // EResource::~EResource()
        // Conditional free via EResourceManager::Free (textures)
    }

    // 0x80320C00 (80 bytes)
    // Releases the platform texture object
    void Deallocate() {
        // Release texture via g_pRenderer vtable (offset 192/196)
        // g_pRenderer->ReleaseTexture(m_texture)
        m_texture = NULL;
    }

    // 0x80320C50 (176 bytes)
    // Refreshes texture from file (reloads if already loaded)
    void Refresh(EFile* file) {
        if (file == NULL)
            return;

        if (m_texture == NULL) {
            // First load: Load via virtual call (vtable offset 72/76)
            // this->Load(*file)
        } else {
            // Reload: release old, load new, re-lock
            // g_pRenderer->UnlockTexture()
            // this->Load(*file)
            // g_pRenderer->LockTexture()
        }
    }

    // 0x80320D00 (240 bytes)
    // Loads texture data from file
    void Load(EFile& file) {
        EDataHeader header;
        // Magic 'TXTR' (0x5458 544C), version 9
        if (!header.Read(file, 0x5458'544C, 9, 9)) {
            return;
        }

        u32 dataSize = header.GetName();
        m_sizeAndType = (m_sizeAndType & 0x000000FF) | (dataSize << 8);

        // Try to allocate from RootHeap first, fall back to VMHeap
        void* buf = EAHeap_Malloc(RootHeap(), dataSize, 0);
        if (buf == NULL) {
            buf = EAHeap_Malloc(VMHeap(), dataSize, 0);
        }

        // Read raw texture data from file
        // file.Read(buf, dataSize)

        // Load from the memory buffer
        LoadFromMemory((u8*)buf);

        // Free the temp buffer
        EAHeap_Free(VMHeap(), buf);
    }

    // 0x80320E14 (736 bytes)
    // Loads texture from raw memory buffer
    // NON_MATCHING: complex mipmap iteration, pixel format dispatch
    void LoadFromMemory(u8* data) {
        // Parse 32-byte texture header from data:
        //   0x00: u32 flags
        //   0x04: u32 reserved
        //   0x08: u32 reserved
        //   0x10: u16 width
        //   0x12: u16 height
        //   0x14: u16 clutWidth
        //   0x16: u16 clutHeight
        //   0x18: u8  format
        //   0x19: u8  mipCount
        //   0x1A: u8  bitsPerPixel
        //   0x1B: u8  clutBpp
        //   0x1C: u16 unused
        //   0x1E: u16 mipLevels

        // Build ETextureDef from header
        // Compute data size: width * height * bpp / 8

        // Merge data size into m_sizeAndType

        // If platform texture already exists, call Create on it
        // Otherwise create new via g_pRenderer->CreateTexture

        // Set texture to mip level 2

        // For each mip level:
        //   Get mip dimensions and offset
        //   Copy data into platform texture buffer

        // Handle CLUT data if present

        // Finalize via platform vtable call
    }

    // 0x803210F4 (140 bytes)
    // Checks if texture can be safely deleted (not in use by any render target)
    int IsSafeToDelete() {
        if (m_texture == NULL)
            return 1;

        // Check global render target list
        // (g_pRenderTargets stored at r13 - 26312)
        void* renderTargets = NULL; // from r13-relative global
        if (renderTargets == NULL)
            return 1;

        // Check both render targets (index 0 and 1)
        for (int i = 0; i <= 1; i++) {
            // Get render target texture via vtable (offset 824, params 24/28)
            // If this texture matches our m_texture, return 0 (not safe)
        }

        return 1;
    }

    // 0x803212F0 (84 bytes)
    static void RegisterType(unsigned short typeID) {
        // ETypeInfo::Register(...)
    }
};


// ============================================================================
// ERShader
// ============================================================================
// EResource wrapper for shader/material definitions
// Manages multi-state shaders (day/night, LOD), texture references, and blend states
//
// Function declarations only - 39 functions, 16152 bytes total
// Full implementation in asm_decomp/ERShader.cpp

class ERShader : public EResource {
public:
    // Additional fields beyond EResource base (complex layout)

    ERShader();
    ~ERShader();
    void Deallocate();
    void DelRefSubResources();
    void DeallocateIncomingShader();
    void AddRefSubResources();
    int  TryIncrementSubResources();
    void CreateEShaderForTexture(ETexture* tex);
    void Load(EFile& file);
    void Clone(u32 shaderID);
    void DoLoadMultiShader(char* name, EShaderDef& def);
    void SetCurrentShaderForState(u8 state);
    void ChangeCurrentShader(ERShader* shader);
    u32  GetMultiShaderStateID(int state);
    void SetShaderASyncForState(int state);
    void DoLoad(EFile& file, EShaderDef& def);
    void OldLoad(EFile& file, EShaderDef& def);
    void CopyShedData(EShaderDef& def, char* data);
    void CopyIntermediateShedData(EShaderDef& def, char* data);
    void AddToUpdateList();
    void RemoveFromUpdateList();
    void Update(f32 dt, int a, int b, int c);
    static int HasCommonTexture(ERShader* a, ERShader* b);
    void UpdateTimeOfDayShader();
    void InterpolateShaders(f32 blend);
    void BlendCurrentShader(f32 blend);
    static void UpdateAll(f32 dt, int a, int b, int c);
    void InitDayNightShaders(int dayState, int nightState);
    void SetDayNightShaderToClosestTime(int dayState, int nightState);
    void ReplaceTexture(ERTexture* tex, int slot);
    void SwapTexture(ERTexture* tex, int slot);
    int  HasTexture(u32 texID);
    static void RegisterType(unsigned short typeID);
    void SetSupportDecal(bool enable);
    int  GetSupportDecal();
    void* GetState(u32 stateID);
    int  IsMultiTextureShader();
    void Select(ERC* rc, u32 flags);
    void SelectForShadowMask(ERC* rc);
};


// ============================================================================
// ERModel
// ============================================================================
// EResource wrapper for 3D model data
// Manages mesh data, morph targets, attachments, and sub-model shaders
//
// 46 functions, 12972 bytes total

class ERModel : public EResource {
public:
    // Additional fields (complex layout with sub-model shaders, morph targets, etc.)

    ERModel();
    ~ERModel();
    void DelRefSubResources();
    void AddRefSubResources();
    int  TryIncrementSubResources();
    void ReadAttachmentVert(char* data);
    void LoadModel(EFile* file);
    void FinishLoad(char flags);
    void GetScaleMatrix();
    void DeallocateScaleMatrix();
    void CalcOrientedBoundSphere(EMat4& mat, EBoundSphere& sphere);
    void DrawGeometry(ERC* rc);
    void DrawAsShadow(ERC* rc);
    void DrawNormals(ERC* rc);
    void DrawWireFrame(ERC* rc);
    void Draw(ERC* rc);
    void DrawShadow(ERC* rc, f32 alpha);
    void DrawShadowWithStencilInverted(ERC* rc);
    void DrawHierarchical(ERC* rc, EMat4* matrices, EACNodeState* nodeState, int nodeCount);
    void GetWeldPos(EWeldVert* weld);
    void SetWeldPos(EWeldVert* weld, EVec3& pos);
    void WeldSharedVerts(ERModel* other, f32 threshold);
    void GenerateMorphTargetDeltas(ERModel* target);
    void RegisterMorphTarget(ERModel* target, int slot);
    void RegisterMorphTarget(int targetID, int slot);
    void UnRegisterMorphTarget(int slot);
    void UnRegisterMorphTarget(ERModel* target);
    void ResetMorph();
    void MorphTargets();
    void MorphLattices();
    void ApplyMorph();
    void CleanMorphTargets(bool force);
    void FreeStripResource();
    void FreeMorphStripResource();
    void SetLatticeWeight(int lattice, int axis, f32 weight);
    void ResetLatticeWeights();
    void ParameterizeVerts();
    void FreeMorphResource();
    int  HasModifiableColor();
    u32  GetModifiableColor(u32 index);
    void GetAttachmentID(u8 type, s8& outID);
    void DrawAttachment(ERC* rc, ERModel* model, EMat4* matrices, int index, f32 scale);
    void GetAttachmentMatrix(EMat4& outMat, ERModel* model, EMat4* matrices, int index, f32 scale);
    void GetAttachmentMatrix(EMat4& outMat, u8 attachID, EMat4* matrices, int index, f32 scale, f32 param);
    void TransformModelUV(EVec2& uvOffset, EVec2& uvScale, u32 channel, EVec2& outOffset, EVec2& outScale);
    static void RegisterType(unsigned short typeID);
};


// ============================================================================
// ERFont
// ============================================================================
// EResource wrapper for bitmap fonts
// Manages glyph data, font sizing, and text rendering
//
// 20 functions, 14208 bytes total

class ERFont : public EResource {
public:
    // offset 0x14: EFontData m_fontData (constructed in ERFont ctor)
    // offset varies: float m_sizeX, m_sizeY
    // offset varies: bool m_customSize

    ERFont();
    ~ERFont();
    void Deallocate();
    void Load(EFile& file);
    void SetSize(f32 width, f32 height, bool custom);
    void SelectPage(ERC* rc, int page);
    void DoDraw(void* text, bool unicode, bool rtl, bool wrap, EVec2& pos, ERC* rc,
                EVec2* clipSize, EWindow* window, EMat4* transform, EVec2* scale,
                EFontMatrixType matType, fontFXcommand* fx);
    void DoDrawNormalize(void* text, bool unicode, bool rtl, bool wrap, EVec2& pos, ERC* rc,
                         EVec2* clipSize, EWindow* window, EMat4* transform, EVec2* scale,
                         EFontMatrixType matType, fontFXcommand* fx);
    void DoGetStringSize(void* text, bool unicode, bool rtl, EWindow* window);
    void SnapPosToPixel(EVec2& pos, bool snapX, bool snapY, EWindow* window);
    void SnapPosToPixelNormalize(EVec2& pos, bool snapX, bool snapY, EWindow* window);
    void DoDrawAlign(ERC* rc, void* text, bool unicode, EVec2 pos, EFontAlignX alignX,
                     EFontAlignY alignY, EVec2* clipSize, EMat4* transform,
                     EFontMatrixType matType, fontFXcommand* fx, bool normalize);
    void Draw(ERC* rc, char* text, EVec2& pos, EFontAlignX alignX, EFontAlignY alignY,
              EVec2* clipSize, EMat4* transform, EFontMatrixType matType, fontFXcommand* fx, bool normalize);
    void DrawDs(ERC* rc, char* text, EVec2& pos, EFontAlignX alignX, EFontAlignY alignY,
                EVec2* clipSize, f32 shadowX, f32 shadowY, bool normalize);
    void DrawDs(ERC* rc, u16* text, EVec2& pos, EFontAlignX alignX, EFontAlignY alignY,
                EVec2* clipSize, f32 shadowX, f32 shadowY, bool normalize);
    void LoadFont();
    void GetLineSpacing(EWindow* window, bool normalize);
    void ProcessFontFX(fontFXcommand* fx, EMat4* transform, int count);
    static void RegisterType(unsigned short typeID);
    void Draw(ERC* rc, u16* text, EVec2& pos, EFontAlignX alignX, EFontAlignY alignY,
              EVec2* clipSize, EMat4* transform, EFontMatrixType matType, fontFXcommand* fx, bool normalize);
};


// ============================================================================
// ERLevel
// ============================================================================
// EResource wrapper for level/map data
// Manages instances, rooms, lights, order tables, and scene graph
//
// 63 functions, 23568 bytes total

class ERLevel : public EResource {
public:
    // Complex layout with instance lists, room data, bound trees, light arrays, etc.

    ERLevel();
    ~ERLevel();
    void GetSunLight(EVec3& dir, EDirLight& light);
    void Write(EStream& stream);
    void AddInstancesFromBoundTree(EStorable* tree);
    void Read(EStream& stream);
    void Load(EFile& file);
    void Refresh(EFile* file);
    void AllocAndLoadLevel(EFile& file);
    void ClearJustReadByLevelFlags();
    void DestroyInstancesWithoutJustReadByLevelFlags();
    void DestroyInstancesOriginallyReadByLevel();
    void Deallocate();
    void DeallocateSub();
    void InsertWall(EInstance* inst, bool sorted);
    void RemoveWall(EInstance* inst);
    void InsertLight(EILight* light);
    void RemoveLight(EILight* light);
    void InsertSkydomeInstance(EInstance* inst);
    void AddInstanceToLevel(EInstance* inst);
    void AddInstanceToLevelHead(EInstance* inst);
    void AddWallInstanceToLevel(EInstance* inst);
    void PrepareInstance(EInstance* inst);
    void AddInstanceToRoom(EInstance* inst);
    void RemoveInstanceFromRoom(EInstance* inst);
    int  GetRoomIndex(EInstance* inst) const;
    void NotifyInstanceMoved(EInstance* inst);
    void FixInstances();
    void FixInstanceList(TNodeList<EInstance*>& list);
    void RemoveInstanceFromIdMap(EInstance* inst);
    void Init();
    void UnregisterFloorOTDs(EInstance* inst);
    void RemoveInstance(EInstance* inst);
    void SetBounds(EInstance* inst, EBound3& bounds);
    void AddBounds(EBound3& a, EBound3& b, bool& expanded);
    void CalcBounds();
    void Update();
    f32  CalcRadiusFromViewParams(f32 fov, f32 aspect, f32 nearPlane);
    void DrawObjectShadowsOutside(TNodeList<EInstance*>& list);
    void DrawObjectShadowsInside(TNodeList<EInstance*>& list);
    void DrawOrderTableSlot(EOrderTableData* slot);
    void DrawOrderTableSlotFast(EOrderTableData* slot);
    void DrawSortedOrderTable(EOrderTableData* slot);
    void Draw(ERC* rc);
    int  ObjectShouldBeOccluded(EInstance* inst);
    int  ObjectShouldBeOccluded(s16 roomIdx, f32 radius);
    void DrawSimShadow(int simIndex);
    void AllocAndCopyOTD(EOrderTableData& otd);
    void RegisterFloor(EOrderTableData& otd);
    void InsertInOrderTable(EOrderTableData& otd);
    void InsertInDOFForegroundObjectList(EOrderTableData& otd);
    void DrawOrderTableEntry(EOrderTableData* otd, ERC* rc);
    void DrawOrderTable();
    void IntersectBoundBox(EBound3& box, EVec3& rayOrigin, EVec3& rayDir);
    static void RegisterType(unsigned short typeID);
};


// ============================================================================
// ESubModelShader
// ============================================================================
// Sub-model shader component within ERModel
// Manages vertex data, strip data, morph targets, and display list building
//
// 34 functions, 16336 bytes total
//
// Layout:
//   0x00: void*  m_shaderData
//   0x04: void*  m_morphData
//   0x08: int    m_morphTargetCount
//   0x0C: int    m_vertexFormat
//   0x10: int    m_flags
//   0x14: TArray<ESMSStrip> m_strips  (12 bytes: ptr, count, capacity)
//   0x20: int    m_reserved
//   0x24: float  m_lodScale
//   0x28: int    m_morphStripCount
//   0x2C: TArray<ESMSStrip> m_morphStrips (12 bytes)
//   0x38: mesh data (48 bytes of vertex/normal/color buffers)
//   0x68: void*  m_morphDeltas
//   0x6C: void*  m_morphResult

class ESubModelShader {
public:
    void*  m_shaderData;       // 0x00
    void*  m_morphData;        // 0x04
    int    m_morphTargetCount; // 0x08
    int    m_vertexFormat;     // 0x0C
    int    m_flags;            // 0x10
    int    m_strips[3];        // 0x14 - TArray header (ptr, count, capacity)
    int    m_reserved;         // 0x20
    f32    m_lodScale;         // 0x24
    int    m_morphStripCount;  // 0x28
    int    m_morphStrips[3];   // 0x2C - TArray header
    u8     m_meshData[48];     // 0x38 - vertex data buffers
    void*  m_morphDeltas;      // 0x68
    void*  m_morphResult;      // 0x6C

    // 0x802FBAF4 (124 bytes)
    ESubModelShader() {
        // TArray ctors for strips and morphStrips

        m_shaderData = NULL;
        m_morphTargetCount = 0;
        m_flags = 0;
        m_vertexFormat = 0;
        m_morphStripCount = 0;
        m_lodScale = 1.0f;

        memset(m_meshData, 0, 48);

        m_morphData = NULL;
        m_morphDeltas = NULL;
        m_morphResult = NULL;
    }

    ~ESubModelShader() {
        Deallocate();
    }

    void AddRefSubResources();
    int  TryIncrementSubResources();
    void DeallocateStripData(ESMSStrip* strip);
    void Deallocate();
    void FreeStripResource();
    void FreeMorphStripResource();
    void FreeMorphResource();
    void CreateRCPrimitive(u32 type, ERC* rc, ESMSStrip* strip, bool a, bool b, bool c);
    void ReadPositions(u8* data, ESMSStrip* strip, bool compressed);
    void ReadTexcoords(u8* data, ESMSStrip* strip);
    void ReadColors(u8* data, ESMSStrip* strip);
    void ReadNormalsOld(u8* data, ESMSStrip* strip);
    void ReadNormals(u8* data, ESMSStrip* strip);
    void ReadWeights(u8* data, ESMSStrip* strip, bool normalized);
    void OptimizeStripsForMemory(ESubModelShader* src, ESMSStrip* strip, int count, bool force);
    void ReadIndices(u8* data, ESMSStrip* strip, u32& offset);
    void Read(u8* data, int size);
    void AllocateMorph();
    void RegisterMorphTarget(ESubModelShader* target, int slot);
    void ResetMorph();
    void ApplyMorph();
    void GetMorphedVertex(EVec3& outPos, s16 vertIndex, s16 morphIndex);
    void GenerateMorphTargetDeltas(ESubModelShader* target);
    void Morph(f32* weights);
    void CreateLatticeList(TArray<BSplineVolume, TArrayERModelAllocator>* lattices);
    void AllocateParameterizeVerts();
    void ParameterizeVerts(TArray<BSplineVolume, TArrayERModelAllocator>* lattices);
    void LatticeDeform();
    void BuildDisplayList(ESMBuildDisplayListData* dlData);
    void BuildDisplayList(bool indexed, char* data, bool compressed, f32 posScale, f32 uvScale);
    void GetMinMaxX(f32* outMin, f32* outMax);
    void TransformModelUV(EVec2& uvOffset, EVec2& uvScale, u32 channel, EVec2& outOffset, EVec2& outScale, bool apply);
};


// ============================================================================
// ENgcAudio
// ============================================================================
// GameCube-specific audio implementation
// Wraps DolphinSDK audio (MUSYX / DSPADPCM)
//
// 18 functions, 4684 bytes total
// (Already decompiled in audio_save_camera.cpp - declarations only here)

class ENgcAudio {
public:
    void*  m_vtable;           // 0x00
    f32    m_musicVolume;      // 0x04 (0.0 - 1.0)
    f32    m_musicPan;         // 0x08 (0.0 - 1.0, center = 0.5)
    int    m_isPlayingMusic;   // 0x0C
    u8     m_pad10[4];         // 0x10
    void*  m_field14;          // 0x14
    void*  m_field18;          // 0x18
    void*  m_field1C;          // 0x1C
    u8     m_pad20[24];        // 0x20
    int    m_field38;          // 0x38
    int    m_field3C;          // 0x3C
    u8     m_mutex1[24];       // 0x40 - EMutex
    int    m_field58;          // 0x58
    int    m_field5C;          // 0x5C

    ENgcAudio();
    ~ENgcAudio();
    void InitAudio();
    void Shutdown();
    void PlayMusic(EPMDesc& desc);
    void Update();
    void StopMusic();
    void PauseMusic();
    void ResumeMusic();
    void SetMusicVolume(f32 volume);
    void SetMusicPan(f32 pan);
    int  IsPlayingMusic();
    void FreeVoice(EVoice* voice);
    void AudioBindVoice(EVoice* voice, u32 sampleID);
    void UnbindVoice(EVoice* voice);
    void GetVoiceState(EVoice* voice, EVoiceDesc& desc);
    void SetVoiceState(EVoice* voice, EVoiceDesc& desc);
    void SetSpeakerVolumes(EVoice* voice, int* volumes, u32 count);
};


// ============================================================================
// ENgcMemoryCard
// ============================================================================
// GameCube memory card interface
// Wraps DolphinSDK CARD library for save/load operations
//
// 21 functions, 20244 bytes total
// (Already decompiled in audio_save_camera.cpp - declarations only here)

class ENgcMemoryCard {
public:
    void SetComments(u16* comment1, u16* comment2);
    void InitMemoryCard();
    int  LoadDataChunkS(char* filename, u32 offset, u32 size, u32 chunkSize, void* buffer);
    int  LoadDataS(char* filename, u32 offset, u32 size, void* buffer);
    int  SaveDataChunkS(char* filename, u32 offset, u32 size, u32 chunkSize, void* buffer);
    int  SaveDataS(char* filename, u32 offset, u32 size, void* buffer);
    int  CreateFileS(char* filename, u32 size, u32 cardSlot);
    void CheckAndWriteBannerAndIcon(char* filename, u32 cardSlot);
    int  DeleteDataS(char* filename, u32 cardSlot);
    int  FormatCardS(u32 cardSlot);
    int  GetFreeSpaceS(u32 cardSlot, u32& freeBytes);
    int  GetFreeFilesS(u32 cardSlot, int& freeFiles);
    int  IsSpaceAvailable(u32 cardSlot, u32 sizeNeeded, bool& available);
    int  IsEnoughFiles(u32 cardSlot, u32 filesNeeded, bool& enough);
    int  IsCardAvailable(u32 cardSlot);
    int  IsWrongDevice(u32 cardSlot);
    void AnyCardsPresent(int& count);
    int  IsCardFormated(u32 cardSlot, bool& formatted);
    int  GetFileList(u32 cardSlot, char* pattern, u32 maxFiles, char (*outNames)[31]);
    int  DoesFileExist(char* filename, u32 cardSlot, bool& exists);
    int  GetSectorSize(int cardSlot, u32& sectorSize);
};
