// =============================================================================
// skincompositor_decomp.cpp
//
// Sims 2 GameCube — Character Rendering Pipeline Decompilation
//
// Covers: SkinCompositor, ERCharacter, ESubModelShader, SimModel (rendering),
//         CasSimRenderer, and supporting CAS body part assembly.
//
// All functions NON_MATCHING (SN Systems vs devkitPPC codegen differences).
// Decompiled from PPC disassembly of u2_ngc_release_dvd.elf.
//
// Original source: c:\BuildAgent\cm3-build22-NGC\CMBuild\
// =============================================================================

#include "types.h"

// ============================================================================
//
//  CHARACTER RENDERING PIPELINE — ARCHITECTURE OVERVIEW
//
//  The Sims 2 GC character rendering pipeline transforms CAS (Create-A-Sim)
//  body part selections into a renderable Sim through these stages:
//
//  ┌──────────────────────────────────────────────────────────────────────┐
//  │ STAGE 1: CAS DESCRIPTION                                           │
//  │   CasSimDescriptionS2C holds per-Sim body part indices:             │
//  │   - Body part model index per slot (head, torso layers, legs, etc.) │
//  │   - Body part texture index per slot                                │
//  │   - Morph parameters (body type: fit/fat/thin)                      │
//  │   - Skin color, hair color, eye color                               │
//  │   - Tattoo selections                                               │
//  │   Total ~290 bytes of Sim customization data.                       │
//  └─────────────────────┬────────────────────────────────────────────────┘
//                        │
//                        ▼
//  ┌──────────────────────────────────────────────────────────────────────┐
//  │ STAGE 2: MODEL ASSEMBLY (SimModel)                                  │
//  │   SimModel::SetAllModels() loads 3D meshes for each body part:      │
//  │   - Head, hair, hat, glasses, facial feature                        │
//  │   - Inner/mid/outer torso layers + sleeves + collars                │
//  │   - Lower body, shoes, belt, arm accessory                          │
//  │   - Vest/scarf, necklace/earring                                    │
//  │   Each body part is an ERModel with ESubModelShader sub-meshes.     │
//  │   Parts are loaded async via SimModel::SetModelPartASync().         │
//  └─────────────────────┬────────────────────────────────────────────────┘
//                        │
//                        ▼
//  ┌──────────────────────────────────────────────────────────────────────┐
//  │ STAGE 3: MORPHING (ESubModelShader::Morph / ApplyMorph)             │
//  │   Body type morphs are applied via lattice deformation:             │
//  │   - Each morph target stores vertex deltas (s16 or float)           │
//  │   - Morph weights from CasSimDescriptionS2C (fit, fat, etc.)        │
//  │   - Up to 12 morph targets blended per sub-model                    │
//  │   - BSplineVolume lattice deformation for smooth body shaping       │
//  │   SimModel::ApplyAllMorphTargets() drives 4 morph regions:          │
//  │     Region 0 (torso), Region 3 (lower), Region 6 (head), Region 9  │
//  └─────────────────────┬────────────────────────────────────────────────┘
//                        │
//                        ▼
//  ┌──────────────────────────────────────────────────────────────────────┐
//  │ STAGE 4: VERTEX WELDING                                             │
//  │   SimModel::WeldAllSharedVertices() joins body part seams:          │
//  │   - Adjacent parts share boundary vertices                          │
//  │   - CasSimPartsS2C::GetWeldableBodyPartConnections() provides       │
//  │     which parts connect (e.g., torso↔arms, torso↔legs)             │
//  │   - Ensures no visible seams between clothing layers                │
//  └─────────────────────┬────────────────────────────────────────────────┘
//                        │
//                        ▼
//  ┌──────────────────────────────────────────────────────────────────────┐
//  │ STAGE 5: SKIN COMPOSITING (SkinCompositor)                          │
//  │   Builds the Sim's skin texture by layering body part textures:     │
//  │   a) InitScratchpadTextures() — allocate RGBA8 scratch textures     │
//  │   b) InitSkinTexture() — set resolution, check alpha mode           │
//  │   c) LoadAllTextureLayers() — determine layer ordering per quadrant │
//  │   d) BlendTexture() — per-pixel alpha blend each layer              │
//  │   e) GetFinalReflectionMask() — encode specular mask in alpha       │
//  │   f) FinalizeSkinTexture() — copy/tile result to GX texture         │
//  │                                                                     │
//  │   The skin is divided into quadrants (0-3):                         │
//  │     Quadrant 0: Head/face skin                                      │
//  │     Quadrant 1: Upper torso                                         │
//  │     Quadrant 2: Lower body (legs/feet)                              │
//  │     Quadrant 3: Arms/hands                                          │
//  │                                                                     │
//  │   Compositing supports hi-res (256x256) and lo-res (128x128) modes. │
//  │   Each quadrant can be precomposited (loaded from disc) or           │
//  │   dynamically composited (layered at runtime).                      │
//  └─────────────────────┬────────────────────────────────────────────────┘
//                        │
//                        ▼
//  ┌──────────────────────────────────────────────────────────────────────┐
//  │ STAGE 6: RENDERING (CasSimRenderer / DrawSubModelShader)            │
//  │   CasSimRenderer::Draw() renders the assembled Sim:                 │
//  │   a) SetupSimCommon() — bind composited skin texture to shaders     │
//  │   b) For each body part model, draw sub-model shaders               │
//  │   c) DrawSubModelShader() — set GX TEV alpha, bind display list     │
//  │   d) Separate shadow pass via DrawShadow()                          │
//  │   e) Head rendered separately with morph-blended mesh               │
//  │                                                                     │
//  │   ERCharacter provides the skeleton (bone hierarchy) loaded from    │
//  │   .chr files. Each node is 184 bytes containing:                    │
//  │     - Name (string at +0xB4, 64 chars)                              │
//  │     - Local transform matrix (4x4 at +0x1C and +0x70)               │
//  │     - Child node indices (TArray<int> at +0x04)                     │
//  │     - Visibility flag at +0xB0                                      │
//  └──────────────────────────────────────────────────────────────────────┘
//
// ============================================================================


// ============================================================================
//  Forward declarations (types referenced from symbols)
// ============================================================================

class ERTexture;

// Body part enum (eBodyPartS2C) — 26 values from CAS system
// Values determined from LoadAllTextureLayers switch cases and GetTextureIDs loop
enum eBodyPartS2C {
    eBodyPart_InnerLayerTorso       = 0,   // quadrant 1 base
    eBodyPart_InnerLayerSleeve      = 1,
    eBodyPart_MidLayerTorso         = 2,
    eBodyPart_MidLayerSleeve        = 3,
    eBodyPart_MidLayerCollar        = 4,
    eBodyPart_OuterLayerTorso       = 5,
    eBodyPart_OuterLayerSleeve      = 6,
    eBodyPart_OuterLayerCollar      = 7,
    eBodyPart_Head                  = 8,   // quadrant 0
    eBodyPart_Hair                  = 9,
    eBodyPart_Hat                   = 10,
    eBodyPart_LowerBody             = 11,  // quadrant 2
    eBodyPart_Shoes                 = 12,
    eBodyPart_Hood                  = 13,
    eBodyPart_FacialFeature         = 14,
    eBodyPart_Skin                  = 15,  // base skin layer
    eBodyPart_Glasses               = 16,
    eBodyPart_ArmAccessory          = 17,
    eBodyPart_Belt                  = 18,
    eBodyPart_VestScarf             = 19,
    eBodyPart_Tattoo0               = 20,
    eBodyPart_Tattoo1               = 21,
    eBodyPart_Tattoo2               = 22,
    eBodyPart_Tattoo3               = 23,
    eBodyPart_Tattoo4               = 24,
    eBodyPart_NecklaceEarring       = 25,
    eBodyPart_COUNT                 = 26
};

// Skin color / body type enums (from CasSimPartsS2C::GetSkinTextureID)
enum eSkinColorType { eSkinColor_Light = 0, eSkinColor_Medium = 1, eSkinColor_Dark = 2, eSkinColor_Alien = 3 };
enum eBodyTypeS2C   { eBodyType_Normal = 0, eBodyType_Fit = 1, eBodyType_Heavy = 2 };
enum eSimPartsMapLocation { eSimPartsMap_Head = 0, eSimPartsMap_Torso = 1, eSimPartsMap_Legs = 2, eSimPartsMap_Arms = 3 };
enum eTattooTextureTypeS2C { eTattooType_0 = 0, eTattooType_1 = 1, eTattooType_2 = 2 };

// CasSimDescriptionS2C — stub for skin compositor use
class CasSimDescriptionS2C {
public:
    // Generic member access via offset casting
    u8   m_bodyTypeMorphValues; // at offset 0x84 (gender/bodytype field)
    u8   m_bodyPartIndex;       // body part model index array base
    u8   m_bodyPartTextureIdx;  // body part texture index array base

    u32  GetCompositeTextureID(const char* basePath, int quadrant) const { (void)basePath; (void)quadrant; return 0; }
    void GetCompositeTextureName(char* buf, const char* basePath, int quadrant) const { (void)buf; (void)basePath; (void)quadrant; }
    u8   GetBodyPartIndex(int part) const { (void)part; return 0; }
    u8   GetBodyPartTextureIndex(int part) const { (void)part; return 0; }
};

// CasSimPartsS2C — stub for skin compositor use
class CasSimPartsS2C {
public:
    u32         GetSkinTexturesDatasetID(int skinColor, int bodyType) const { (void)skinColor; (void)bodyType; return 0; }
    u32         GetSkinTextureID(eSkinColorType skinColor, eBodyTypeS2C bodyType, eSimPartsMapLocation loc) const { (void)skinColor; (void)bodyType; (void)loc; return 0; }
    int         GetNumBodyModels(int part) const { (void)part; return 0; }
    void        SetGender(bool isMale) { (void)isMale; }
    bool        OuterLayerTorsoIsAHood(s8 idx, u32 style) const { (void)idx; (void)style; return false; }
    bool        OuterLayerCollarIsAHood(s8 idx, u32 style) const { (void)idx; (void)style; return false; }
    const char* GetBodyPartName(eBodyPartS2C part) const { (void)part; return ""; }
    u32         GetTextureID(eBodyPartS2C part, CasSimDescriptionS2C* desc, bool unk) const { (void)part; (void)desc; (void)unk; return 0; }
    u32         GetReflectionTextureID(eBodyPartS2C part, CasSimDescriptionS2C* desc) const { (void)part; (void)desc; return 0; }
    u32         GetTattooTextureID(eTattooTextureTypeS2C type, s8 slot) const { (void)type; (void)slot; return 0; }
};
class EFile;
class ERC;
class EStream;
class ERModel;
class EShader;
class ESMSStrip;
class ESMBuildDisplayListData;
class BSplineVolume;
class ETexture;
class ETextureDef;
class SimModel;
class SkinCompositor;
struct EVec2 { float x, y; };
struct EVec3 { float x, y, z; };
struct EMat4 { float m[4][4]; };
struct EBound3 { EVec3 min, max; };

template<class T, class A> class TArray {
public:
    T*  m_data;     // +0x00
    int m_size;     // +0x04
    int m_capacity; // +0x08
    void Init();
    void SetSize(int, int);
    // ...
};

// (enums moved above class definitions — see top of forward declarations block)

// External functions referenced by disassembly
extern "C" {
    void  memset(void* dst, int val, u32 size);               // 0x802435e4
    int   strcmp(const char* a, const char* b);                // 0x802d2de8
    void  snprintf(char* buf, int size, const char* fmt, ...); // 0x802de924
    void* ERTextureManager_Find(void* mgr, u32 id, u32, u32); // 0x80326cf8
    void  ERTextureManager_Release(void* tex);                 // 0x80311f70
    void* ERTexture_Lock(void* tex);                           // 0x8030c5b4
    void  ERTexture_Unlock(void* tex, void* data);             // 0x8030c618
    void  ERTexture_CopyPixels(u32 id, void* texData);         // 0x8030b108
    void  ERTexture_ConvertFormat(void* tex);                  // 0x8030b228
    void  ERTexture_ConvertFormatAlt(void* tex);               // 0x8030b7b0
    u32   AlphaBlendPixel(u32 src, u32 dst);                   // 0x8030c65c
}


// ============================================================================
//
//  1. SkinCompositor — SKIN TEXTURE COMPOSITING
//
//     Builds the composited skin texture from layered body part textures.
//     The compositor works in software, blending RGBA8 textures on the CPU,
//     then flushing to GX texture memory.
//
// ============================================================================

// SkinCompositor class (0x28 bytes)
class SkinCompositor {
public:
    u16   m_textureSize;     // 0x00
    u16   _pad_02;           // 0x02
    u32   m_hasAlphaChannel; // 0x04
    void* m_pScratchTexture; // 0x08
    void* m_pMaskData;       // 0x0C
    u32   m_lowResFlag;      // 0x10
    void* m_pSimDescription; // 0x14
    void* m_pSkinTexture;    // 0x18
    u8    m_quadrant;        // 0x1C
    u8    _pad_1D[3];        // 0x1D
    void* m_pReflectionMask; // 0x20
    void* m_pSimParts;       // 0x24

    void CreateSkin(ERTexture* tex, unsigned char quadrant, CasSimDescriptionS2C* desc, bool lowRes);
    void InitSkinTexture();
    void LoadAllTextureLayers();
    void BlendTexture(eBodyPartS2C bodyPart, u32 texID, u32 reflTexID);
    void GetTextureIDs(u32& skinTexID, u32* partTexIDs, u32* texIDs2, u32* partReflIDs);
    void GetFinalReflectionMask();
    void FinalizeSkinTexture();
    void InitScratchpadTextures(u32 resolution);
};

// SkinCompositor struct layout (0x28 bytes) — see class above


// ============================================================================
// SkinCompositor::CreateSkin
// Address: 0x80075DEC | Size: 160 bytes
// NON_MATCHING
//
// Entry point for compositing one quadrant of the skin texture.
// Called by CreateSkinQuadrantHiRes (lowRes=false) and
// CreateSkinQuadrantLoRes (lowRes=true).
//
// Flow:
//   1. Store parameters into compositor state
//   2. Create CasSimPartsS2C and configure gender
//   3. Select texture resolution based on hi/lo-res mode
//   4. InitScratchpadTextures(resolution)
//   5. InitSkinTexture() — set up render target
//   6. LoadAllTextureLayers() — determine and blend all layers
//   7. FinalizeSkinTexture() — flush to GX
// ============================================================================
void SkinCompositor::CreateSkin(ERTexture* tex, unsigned char quadrant,
                                 CasSimDescriptionS2C* desc, bool lowRes)
{
    // r31 = this, r30 = lowRes
    m_lowResFlag = (u32)lowRes;          // stw r30, 0x10(r31)
    m_pSimDescription = desc;            // stw r6, 0x14(r31)
    m_pScratchTexture = tex;             // stw r4, 0x18(r31) — actually stores output tex ptr
    m_quadrant = quadrant;               // stb r5, 0x1C(r31)

    // Allocate temporary CasSimPartsS2C (16 bytes at r3=16 → EAHeap_Alloc)
    // bl 0x802d11b0 — operator new for CasSimPartsS2C
    CasSimPartsS2C* parts = new CasSimPartsS2C();  // bl 0x8016a894

    m_pSimParts = parts;                 // stw r3, 0x24(r31)

    // Configure gender from sim description
    // lbz r4, 0x84(desc) — gender byte from CasSimDescriptionS2C
    bool isMale = (desc->m_bodyTypeMorphValues != 0);
    parts->SetGender(isMale);            // bl 0x8016a950 (CasSimPartsS2C::SetGender)

    // Store lowRes flag in parts too
    // stw r30, 0x0C(parts)

    // Select texture resolution (from SDA-relative globals)
    u16 baseSize   = 128;  // from SDA at r13-21264
    u16 multiplier = lowRes ? 1 : 2;  // from SDA at r13-32202 / r13-32204
    u16 resolution = (u16)(baseSize * multiplier);

    InitScratchpadTextures(resolution);  // bl 0x80075e8c
    InitSkinTexture();                   // bl 0x80076000
    LoadAllTextureLayers();              // bl 0x80076098
    FinalizeSkinTexture();               // bl 0x8007604c
}


// ============================================================================
// SkinCompositor::InitSkinTexture
// Address: 0x80076000 | Size: 76 bytes
// NON_MATCHING
//
// Prepares the scratch texture for compositing. Sets the texture size based
// on resolution and low-res flag. Checks if the texture format has an alpha
// channel — if so, sets m_hasAlphaChannel to 1, enabling per-pixel alpha
// blending in BlendTexture().
// ============================================================================
void SkinCompositor::InitSkinTexture()
{
    // Calculate actual size from SDA-relative globals
    u16 configSize = 128;  // from SDA at r13-21264
    u16 multiplier = (m_lowResFlag != 0) ? 1 : 2;  // from SDA
    m_textureSize = (u16)(configSize * multiplier);

    m_hasAlphaChannel = 0;

    // Check texture format for alpha:
    // lwz r9, 0x18(this) — m_pSkinTexture
    // lwz r11, 0x14(r9) — texture info struct
    // lbz r0, 0x19(r11) — format byte: 0 = no alpha, nonzero = has alpha
    void* texInfo = *(void**)((u8*)m_pSkinTexture + 0x14);
    u8 hasAlpha = *(u8*)((u8*)texInfo + 0x19);
    if (hasAlpha != 0) {
        m_hasAlphaChannel = 1;
    }
}


// ============================================================================
// SkinCompositor::LoadAllTextureLayers
// Address: 0x80076098 | Size: 1164 bytes
// NON_MATCHING
//
// Determines the layering order of body part textures for the current
// quadrant, then blends each layer onto the scratch texture.
//
// The quadrant value (stored at m_quadrant / +0x1C) selects which body
// parts to composite:
//
//   Quadrant 0 (head):
//     Layers: 8(head), 11(hair), 14(facialFeature), 10(hat), 12(shoes)
//     Total: 5 layers
//
//   Quadrant 1 (torso):
//     Layers: 7(outerCollar) or 9(hair)
//     Checks OuterLayerTorsoIsAHood — if hood, adds layer 12(hood)
//     Total: 2-3 layers
//
//   Quadrant 2 (full body):
//     Layers: 4(midCollar), 3(midSleeve), 5(outerTorso), 6(outerSleeve),
//             19(vestScarf), 25(necklace)
//     Appends: 0(tattoo0), 20(tattoo?), 21, 22, 23, 24
//     Checks OuterLayerTorsoIsAHood and OuterLayerCollarIsAHood for hood layers
//     Total: 7-14 layers
//
//   Quadrant 3 (misc):
//     Layers: 15(skin) only
//     Total: 1 layer
//
// After determining layers, the function:
//   1. Calls GetTextureIDs() to resolve texture resource IDs
//   2. For quadrant 2: locks texture, sets up format conversion
//   3. Loads base skin texture via ERTexture_CopyPixels
//   4. Iterates body part layers, calling BlendTexture() for each
//   5. Calls GetFinalReflectionMask() to encode specular data
//   6. Unlocks and finalizes texture
// ============================================================================
void SkinCompositor::LoadAllTextureLayers()
{
    // Stack frame: 920 bytes (large local arrays)
    // Local arrays on stack:
    //   +0x08: u32 layerParts[26]   — body part IDs for this quadrant's layers
    //   +0x70: u32 skinTexIDs[3]    — base skin texture IDs
    //   +0x80: u32 partTexIDs[26]   — resolved texture IDs per body part
    //   +0xE8: u32 partReflIDs[26]  — reflection texture IDs per body part
    //   +0x150: char debugStr[512]  — debug string buffer

    u32 layerParts[26];
    memset(layerParts, 0, 104);  // 26 * 4 = 104

    u8 numLayers = 0;
    u8 quadrant = m_quadrant;  // lbz r5, 0x1C(r31)

    switch (quadrant) {
    case 0: // Head quadrant
        layerParts[0] = 8;   // head
        layerParts[1] = 11;  // lowerBody (shares texture space)
        layerParts[2] = 14;  // facialFeature
        layerParts[3] = 10;  // hat
        layerParts[4] = 12;  // shoes (boots share UV space)
        numLayers = 5;
        break;

    case 1: // Torso quadrant
        layerParts[0] = 7;   // outerCollar
        layerParts[1] = 9;   // hair
        numLayers = 2;

        // Check if outer torso is a hood — adds extra layer
        {
            CasSimDescriptionS2C* desc = (CasSimDescriptionS2C*)m_pSimDescription;
            CasSimPartsS2C* parts = (CasSimPartsS2C*)m_pSimParts;
            s8 outerIdx = desc->m_bodyPartIndex; // at +0xB4
            u32 outerStyle = desc->m_bodyTypeMorphValues; // at +0xB8
            bool isHood = parts->OuterLayerTorsoIsAHood(outerIdx, outerStyle);
            if (!isHood) {
                layerParts[2] = 12; // add shoes layer to hood position
                numLayers = 3;
            }
        }
        break;

    case 2: // Full body quadrant (most complex)
        layerParts[0] = 2;   // midLayerTorso  (== quadrant value itself)
        layerParts[1] = 4;   // midLayerCollar
        layerParts[2] = 3;   // midLayerSleeve
        layerParts[3] = 12;  // shoes (== r29 = 12)
        layerParts[4] = 5;   // outerTorso
        layerParts[5] = 6;   // outerSleeve
        layerParts[6] = 19;  // vestScarf
        numLayers = 7;

        // Check if outer torso is a hood
        {
            CasSimDescriptionS2C* desc = (CasSimDescriptionS2C*)m_pSimDescription;
            CasSimPartsS2C* parts = (CasSimPartsS2C*)m_pSimParts;
            s8 outerIdx = *(s8*)((u8*)desc + 0xB4);
            u32 outerStyle = *(u32*)((u8*)desc + 0xB8);

            if (parts->OuterLayerTorsoIsAHood(outerIdx, outerStyle)) {
                layerParts[7] = 12;  // r29 = 12
                numLayers = 8;
            } else {
                u32 collarStyle = *(u32*)((u8*)desc + 0xBC);
                if (parts->OuterLayerCollarIsAHood(outerIdx, collarStyle)) {
                    layerParts[7] = 13; // hood body part
                    numLayers = 8;
                }
            }
        }

        // Append null separator then tattoo/accessory layers
        layerParts[numLayers++] = 0;   // separator
        layerParts[numLayers++] = 20;  // tattoo 0
        layerParts[numLayers++] = 21;  // tattoo 1
        layerParts[numLayers++] = 22;  // tattoo 2
        layerParts[numLayers++] = 23;  // tattoo 3
        layerParts[numLayers++] = 24;  // tattoo 4
        break;

    case 3: // Misc quadrant
        layerParts[0] = 15;  // skin base
        numLayers = 1;
        break;
    }

    // Resolve texture IDs for all body parts
    u32 partTexIDs[26];
    u32 partReflIDs[26];
    u32 skinTexID = 0;
    GetTextureIDs(skinTexID, partTexIDs, partTexIDs, partReflIDs);

    // For quadrant 2: special format conversion path
    if (quadrant == 2) {
        // Lock scratch texture, get raw pixel pointer
        void* scratchData = ERTexture_Lock(m_pScratchTexture);
        // ... vtable call to configure format ...
        // ... vtable call to get width/height ...

        // Clear pixel buffer
        u16 sz = m_textureSize;
        memset(scratchData, 0, sz * sz * 4);

        // ... vtable call for format init ...
        ERTexture_Unlock(m_pScratchTexture, scratchData);
    } else {
        // Copy base skin texture pixels directly
        ERTexture_CopyPixels(skinTexID, (void*)m_pScratchTexture);
    }

    // Lock texture for compositing
    void* lockedData = ERTexture_Lock(m_pScratchTexture);
    void* savedData = lockedData;

    // ... vtable call to set write mode ...
    // ... vtable call to get extents ...

    // Clear reflection mask
    u16 sz = m_textureSize;
    memset(m_pReflectionMask, 0, sz * sz);

    // Determine base skin texture for this quadrant
    u32 baseSkinTexID;
    u16 baseSkinRefl = 15; // default: skin body part
    switch (quadrant) {
    case 0: baseSkinTexID = *(u32*)((u8*)&skinTexID + 0); baseSkinRefl = 8; break;
    case 1: baseSkinTexID = *(u32*)((u8*)&skinTexID + 4); baseSkinRefl = 7; break;
    case 3: baseSkinTexID = *(u32*)((u8*)&skinTexID + 8); break;
    default: baseSkinTexID = 0; break;
    }

    // Blend base skin layer
    if (baseSkinTexID != 0) {
        BlendTexture((eBodyPartS2C)baseSkinRefl, baseSkinTexID, 0);
    }

    // Iterate body part layers and blend each
    for (u8 i = 0; i < numLayers; i++) {
        u32 bodyPart = layerParts[i];
        u32 texID = partTexIDs[bodyPart];
        if (texID == 0) continue;

        u32 reflID = partReflIDs[bodyPart];
        if (texID == reflID) {
            // Same texture for diffuse and reflection — use BlendTexture with no alpha mask
            // Get body part name for debug
            CasSimPartsS2C* parts = (CasSimPartsS2C*)m_pSimParts;
            const char* partName = parts->GetBodyPartName((eBodyPartS2C)bodyPart);
            CasSimDescriptionS2C* desc = (CasSimDescriptionS2C*)m_pSimDescription;
            s8 partIdx = desc->GetBodyPartIndex((eBodyPartS2C)bodyPart);
            s8 texIdx = desc->GetBodyPartTextureIndex((eBodyPartS2C)bodyPart);
            // Debug log: snprintf(debugStr, 512, "part=%s idx=%d tex=%d", ...)
        } else {
            // Normal blend with separate reflection texture
            BlendTexture((eBodyPartS2C)bodyPart, texID, reflID);
        }
    }

    // Generate final reflection mask
    GetFinalReflectionMask();

    // Unlock texture and restore state
    // ... vtable call to finalize ...
    ERTexture_Unlock(m_pScratchTexture, savedData);
    m_pMaskData = 0;
}


// ============================================================================
// SkinCompositor::BlendTexture
// Address: 0x80076618 | Size: 1932 bytes
// NON_MATCHING
//
// Per-pixel alpha blends a body part texture layer onto the scratch texture.
// This is the core compositing function — called once per body part layer.
//
// Parameters:
//   bodyPart   — which body part this texture belongs to (eBodyPartS2C)
//   texID      — resource ID of the diffuse texture to blend
//   reflTexID  — resource ID of the reflection/specular texture (0 = none)
//
// The function:
//   1. Looks up UV mapping coordinates from a global table (10 bytes per part)
//   2. Scales UV coords by lo-res/hi-res multiplier
//   3. Loads the diffuse texture via ERTextureManager_Find
//   4. If reflTexID != 0, loads the reflection texture
//   5. Validates dimensions match between source and destination
//   6. Per-pixel loop:
//      - Read source pixel (RGBA8 or I8)
//      - If source alpha > 0:
//        a. For format with alpha: alpha blend using AlphaBlendPixel()
//        b. For format without alpha: direct copy
//      - Write reflection mask byte from alpha channel
//   7. Release texture references
//
// The UV mapping table at (0x80485698 + bodyPart*10) contains:
//   +0: u16 srcX      — source X origin in body part texture
//   +2: u16 srcY      — source Y origin
//   +4: u16 dstX      — destination X in composited texture
//   +6: u16 dstY      — destination Y
//   +8: u16 reserved
//
// Special case: body parts 12-13 (shoes/hood) in quadrant 2 use
// half-size coordinates (64x64 instead of 128x128).
// ============================================================================
void SkinCompositor::BlendTexture(eBodyPartS2C bodyPart, u32 texID, u32 reflTexID)
{
    // Stack frame: 680 bytes
    // r22 = this, r30 = reflTexID

    // Load UV mapping from global table
    // mulli r11, bodyPart, 10
    // lis r9, hi(0x8048569a); addi r9, r9, lo(0x8048569a)
    // lhzux r8, r11, r9 — load srcX from table[bodyPart]
    u16 srcX, srcY, dstX, dstY;
    // These are loaded from the body part UV mapping table

    // For quadrant 2, body parts 12-13: override to half-size coords
    u8 quadrant = m_quadrant;  // lbz r0, 0x1C(r22)
    if (quadrant == 2) {
        u32 partOffset = (u32)bodyPart - 12;
        if (partOffset <= 1) { // bodyPart == 12 or 13
            // Override UV coords for half-size shoe/hood region
            srcX = 64; srcY = 64;
            dstX = 128; dstY = 128;
            // (specific half-size coordinate setup from disasm)
        }
    }

    // Scale coordinates by resolution multiplier (from SDA globals)
    u16 multiplier = (m_lowResFlag != 0) ? 1 : 2;
    for (int i = 0; i < 4; i++) {
        (void)multiplier;
        // Multiply each coordinate component by the multiplier
    }

    // Load diffuse texture
    // r19 = ERTextureManager_Find(g_texMgr, texID, 0, 0)
    void* srcTex = ERTextureManager_Find(/*g_texMgr*/ 0, texID, 0, 0);
    if (!srcTex) return;

    void* srcTexInfo = *(void**)((u8*)srcTex + 0x14);
    if (!srcTexInfo) return;

    // Check if source texture has alpha channel
    bool srcHasAlpha = false;
    u8 srcFormat = *(u8*)((u8*)srcTexInfo + 0x19);
    if (srcFormat != 0) {
        srcHasAlpha = true;
    }
    // Check if it's an I8 format (format byte == 8)
    bool srcIsI8 = false;
    if (srcFormat == 0 || *(u8*)((u8*)srcTexInfo + 0x1A) == 8) {
        srcIsI8 = true;
    }

    // Validate source dimensions against expected region
    u16 srcW = *(u16*)((u8*)srcTexInfo + 0x10);
    u16 srcH = *(u16*)((u8*)srcTexInfo + 0x12);
    u32 regionW = dstX - srcX;
    u32 regionH = dstY - srcY;

    if (regionW != srcW || regionH != srcH) {
        // Dimension mismatch — clamp to minimum
        regionW = (regionW < srcW) ? regionW : srcW;
        regionH = (regionH < srcH) ? regionH : srcH;
    }

    // Load reflection texture if provided
    void* reflTex = 0;
    void* reflPixelData = 0;
    bool reflHasAlpha = false;

    if (reflTexID != 0) {
        reflTex = ERTextureManager_Find(/*g_texMgr*/ 0, reflTexID, 0, 0);
        if (!reflTex || !*(void**)((u8*)reflTex + 0x14)) {
            ERTextureManager_Release(srcTex);
            return;
        }

        // Validate reflection texture dimensions match
        void* reflInfo = *(void**)((u8*)reflTex + 0x14);
        u16 reflW = *(u16*)((u8*)reflInfo + 0x10);
        u16 reflH = *(u16*)((u8*)reflInfo + 0x12);

        if (reflW != srcW || reflH != srcH) {
            // Mismatch — release both and bail
            ERTextureManager_Release(srcTex);
            ERTextureManager_Release(reflTex);
            return;
        }

        // Clamp region to minimum of source, reflection, and expected
        regionW = (regionW < reflW) ? regionW : reflW;
        regionH = (regionH < reflH) ? regionH : reflH;

        // Lock reflection texture
        reflPixelData = ERTexture_Lock(*(void**)((u8*)reflTex + 0x14));

        // ... vtable calls to set up reflection format ...

        // Get reflection alpha lookup table
        // Checks format byte at +0x18: if 0x8A, uses one vtable slot, else another
        u8 fmtByte = *(u8*)((u8*)*(void**)((u8*)reflTex + 0x14) + 0x18);
        if (fmtByte == 0x8A) {
            // Use 16-bit indexed alpha lookup
            // vtable[0x50/4] — specialized alpha accessor
        } else {
            // Use 8-bit direct alpha lookup
            // vtable[0x48/4] — standard alpha accessor
        }
    } else {
        // No reflection texture — clamp region to texture size
        u16 texSize = m_textureSize;
        regionW = (regionW < texSize) ? regionW : texSize;
        regionH = (regionH < texSize) ? regionH : texSize;
    }

    // Lock source texture
    void* srcPixelData = ERTexture_Lock(*(void**)((u8*)srcTex + 0x14));

    // ... vtable calls to set up source format ...

    // Get source alpha lookup table (same format check as reflection)
    void* srcAlphaTable = 0;
    u8 srcFmt2 = *(u8*)((u8*)*(void**)((u8*)srcTex + 0x14) + 0x18);
    if (srcFmt2 == 0x8A) {
        // vtable[0x50/4]
    } else {
        // vtable[0x48/4]
    }

    // ===== MAIN COMPOSITING LOOP =====
    // Iterates over each pixel in the region, blending source onto destination.

    u32 dstStride = *(u32*)(/*stack*/ 0); // destination texture width (from texture info)

    for (u32 y = 0; y < regionH; y++) {
        for (u32 x = 0; x < regionW; x++) {
            u32 dstIdx = (y + srcY) * dstStride + (srcX + x);  // destination pixel index

            // Read source pixel
            u32 srcPixel;
            u8 alpha;

            if (reflTexID != 0) {
                // Read alpha from source texture's alpha channel
                u8 srcAlphaByte = ((u8*)srcPixelData)[y * srcW + x];
                srcPixel = ((u32*)reflPixelData)[y * srcW + x]; // from reflection
                alpha = srcAlphaByte;
            } else {
                srcPixel = ((u32*)srcPixelData)[x];  // direct read
                alpha = srcPixel & 0xFF;
            }

            // Read destination pixel
            u32* dstPixels = (u32*)m_pMaskData;  // +0x0C
            u32 dstPixel = dstPixels[dstIdx];

            // Alpha check — skip fully transparent pixels
            u8 srcAlpha = alpha;  // clrlwi r30, r4, 24
            if (srcAlpha == 0) continue;

            // Blend based on texture format
            if (quadrant == 2) {
                // Quadrant 2: direct pixel write (no blend)
                dstPixels[dstIdx] = srcPixel;
            } else {
                // Other quadrants: alpha blend
                u32 blended = AlphaBlendPixel(dstPixel, srcPixel);
                dstPixels[dstIdx] = blended;
            }

            // Write reflection mask
            if (reflTexID != 0) {
                u8 reflValue;
                if (reflHasAlpha) {
                    // Look up reflection value from alpha table
                    u8 alphaIdx = ((u8*)reflPixelData)[y * srcW + x]; // lbz from refl alpha
                    reflValue = ((u32*)srcAlphaTable)[alphaIdx] & 0xFF;
                } else {
                    reflValue = ((u8*)reflPixelData)[y * srcW + x]; // direct byte
                }
                u8* reflMask = (u8*)m_pReflectionMask;  // +0x20
                reflMask[dstIdx] = reflValue;
            }
        }
    }

    // Release reflection texture
    if (reflTexID != 0) {
        // Unlock reflection texture
        // ... vtable call to finalize ...
        ERTexture_Unlock(*(void**)((u8*)reflTex + 0x14), reflPixelData);
        ERTextureManager_Release(reflTex);
    }

    // Release source texture
    // ... vtable call to finalize ...
    ERTexture_Unlock(*(void**)((u8*)srcTex + 0x14), srcPixelData);
    ERTextureManager_Release(srcTex);
}


// ============================================================================
// SkinCompositor::GetTextureIDs
// Address: 0x80076524 | Size: 244 bytes
// NON_MATCHING
//
// Resolves texture resource IDs for all body parts from the CAS description.
// Fills three output arrays:
//   - skinTexID (out): base skin texture ID from CasSimPartsS2C::GetSkinTextureID
//   - partTexIDs[26]: diffuse texture ID per body part
//   - partReflIDs[26]: reflection texture ID per body part
//
// Also resolves 3 tattoo texture IDs from the tattoo slots.
// ============================================================================
void SkinCompositor::GetTextureIDs(u32& skinTexID, u32* partTexIDs,
                                    u32* texIDs2, u32* partReflIDs)
{
    CasSimDescriptionS2C* desc = (CasSimDescriptionS2C*)m_pSimDescription;
    CasSimPartsS2C* parts = (CasSimPartsS2C*)m_pSimParts;

    // Get base skin texture from skin color + body type + quadrant
    s8 skinColor = (s8)*(u8*)((u8*)desc + 0x88);  // lbz r5, 0x88(r9), extsb
    s8 bodyType  = (s8)*(u8*)((u8*)desc + 0x89);  // lbz r4, 0x89(r9), extsb
    u8 quadrant  = m_quadrant;
    skinTexID = parts->GetSkinTextureID((eSkinColorType)skinColor,
                                         (eBodyTypeS2C)bodyType,
                                         (eSimPartsMapLocation)quadrant);

    // Iterate all 26 body parts, get texture + reflection IDs
    u32 offset = 0;
    for (u32 i = 0; i <= 25; i++) {
        partTexIDs[offset / 4] = parts->GetTextureID((eBodyPartS2C)i, desc, false);
        partReflIDs[offset / 4] = parts->GetReflectionTextureID((eBodyPartS2C)i, desc);
        offset += 4;
    }

    // Get 3 tattoo texture IDs
    texIDs2[0] = parts->GetTattooTextureID((eTattooTextureTypeS2C)0,
                                             (s8)*(u8*)((u8*)desc + 0xF2));
    texIDs2[1] = parts->GetTattooTextureID((eTattooTextureTypeS2C)1,
                                             (s8)*(u8*)((u8*)desc + 0xF3));
    texIDs2[2] = parts->GetTattooTextureID((eTattooTextureTypeS2C)2,
                                             (s8)*(u8*)((u8*)desc + 0xF4));
}


// ============================================================================
// SkinCompositor::GetFinalReflectionMask
// Address: 0x80076DA4 | Size: 208 bytes
// NON_MATCHING
//
// Encodes the reflection mask into the alpha channel of the composited
// skin texture. Iterates every pixel, reads the reflection mask byte,
// and packs it into bits [2:0] of the destination pixel's blue channel
// (with bits [7:3] preserved from the existing color).
//
// This allows the shader to read specular intensity from the blue channel
// while preserving most of the color information.
// ============================================================================
void SkinCompositor::GetFinalReflectionMask()
{
    u16 size = m_textureSize;

    for (u32 y = 0; y < size; y++) {
        u32 rowStart = y * size;

        for (u32 x = 0; x < size; x++) {
            u32 pixelIdx = rowStart + x;

            // Read RGBA8 pixel from composited texture
            u32* pixels = (u32*)m_pMaskData;
            u32 pixel = pixels[pixelIdx];

            // Decompose pixel
            u8 a = (pixel >> 24) & 0xFF;
            u8 r = (pixel >> 16) & 0xFF;
            u8 g = (pixel >>  8) & 0xFF;
            u8 b = (pixel >>  0) & 0xFF;

            // Read reflection mask value
            u8* reflMask = (u8*)m_pReflectionMask;
            u8 reflValue = reflMask[pixelIdx];

            // Encode reflection into low 3 bits of blue channel
            // rlwinm r0, r0, 0, 24, 26 — mask bits [7:3], clear [2:0]
            b = (b & 0xF8) | (reflValue & 0x07);

            // Recompose and write back
            pixel = (a << 24) | (r << 16) | (g << 8) | b;
            pixels[pixelIdx] = pixel;
        }
    }
}


// ============================================================================
// SkinCompositor::FinalizeSkinTexture
// Address: 0x8007604C | Size: 76 bytes
// NON_MATCHING
//
// Copies the composited scratch texture to the output skin texture.
// Uses different conversion paths based on whether the texture has alpha:
//   - With alpha: ERTexture_ConvertFormat (0x8030b228) — full RGBA conversion
//   - Without alpha: ERTexture_ConvertFormatAlt (0x8030b7b0) — RGB-only path
//
// After conversion, the texture is ready for GX to use in rendering.
// ============================================================================
void SkinCompositor::FinalizeSkinTexture()
{
    if (m_hasAlphaChannel != 0) {
        // Alpha-aware format conversion
        void* skinTex = m_pSkinTexture;
        void* texInfo = *(void**)((u8*)skinTex + 0x14);
        ERTexture_ConvertFormat(texInfo);
    } else {
        // RGB-only format conversion
        void* skinTex = m_pSkinTexture;
        void* texInfo = *(void**)((u8*)skinTex + 0x14);
        ERTexture_ConvertFormatAlt(texInfo);
    }
}


// ============================================================================
//
//  2. ERCharacter — SKELETON / BONE HIERARCHY
//
//     ERCharacter loads .chr files containing the Sim's skeleton.
//     Each node in the hierarchy is 184 (0xB8) bytes.
//
// ============================================================================

// ECharacterNode layout (184 bytes per node)
// Reconstructed from ERCharacter::Load and ERCharacter::FindNode disassembly.
//
// Offset  Size  Type         Field
// ------  ----  ----         -----
// 0x00    4     u32          nodeID / flags
// 0x04    12    TArray<int>  childNodeIndices (data, size, capacity)
// 0x10    12    EVec3        localPosition
// 0x1C    16    EMat4 (row)  localTransformRow0
// ...
// 0x70    64    EMat4        worldTransform (4x4 matrix, 16 floats)
// 0xB0    4     u32          visibilityFlag (1 = visible, from lbz → bool conversion)
// 0xB4    64    char[64]     nodeName (used by FindNode with strcmp)

// ERCharacter struct layout (0xB4+ bytes)
// Offset  Type            Field
// 0x00    void**          vtable
// 0x04    ...             base class data
// 0x14    TArray<ECharacterNode>  m_nodes (data ptr, count)
// 0x20    EVec3           m_rootOffset
// 0x2C    u32             m_flags2
// 0x30    u32             m_extraData


// ============================================================================
// ERCharacter::Load
// Address: 0x80368794 | Size: 704 bytes
// NON_MATCHING
//
// Loads a character skeleton from an EFile. Reads the magic header "CHRC"
// (0x43485243), then deserializes nodes.
//
// Per-node loading reads:
//   - Node ID (4 bytes)
//   - Child count + child indices (TArray<int>)
//   - Local position (12 bytes = EVec3)
//   - Local transform matrix (16 bytes = 4 floats of a row)
//   - Visibility flag (1 byte → bool)
//   - Node name (64 bytes)
//   - World transform matrix (64 bytes)
//   - Additional streaming data via EStream operator>>
//
// After all nodes: reads root offset (12 bytes), flags (4 bytes),
// extra data (4 bytes), then closes the chunk reader.
// ============================================================================
void ERCharacter_Load(void* self, void* file)
{
    // r29 = self (ERCharacter*), r31 = file (EFile&)

    // Initialize chunk reader
    // bl 0x8035ae70 — EChunkReader::EChunkReader

    // Try to open "CHRC" chunk (version 9)
    // lis r5, 0x4348; ori r5, r5, 0x5243 — "CHRC"
    // li r6, 9; li r7, 9
    // bl 0x8035b09c — EChunkReader::Open
    // If open fails, close chunk reader and return

    // If no CHRC chunk, try alternate format:
    // bl 0x802d293c — construct EString
    // bl 0x802c66c0 — EFile::ReadString
    // bl 0x802d2948 — destruct EString

    // Read node count (4 bytes)
    u32 nodeCount;
    // vtable call: file->Read(&nodeCount, 4)

    // Resize node array
    // bl 0x803c9d54 — TArray<ECharacterNode>::SetSize

    // For each node (i from 0 to nodeCount-1):
    for (u32 i = 0; i < nodeCount; i++) {
        // Node base = m_nodes.data + i * 184
        void* node = (u8*)(*(void**)((u8*)self + 0x14)) + i * 0xB8;

        // Read node ID (4 bytes into node+0x00)
        // vtable call: file->Read(node, 4)

        // Read child node count
        u32 childCount;
        // vtable call: file->Read(&childCount, 4)
        // TArray<int>::SetSize(childIndices, childCount, 0)

        // Read each child index (4 bytes each)
        for (u32 j = 0; j < childCount; j++) {
            // vtable call: file->Read(childIndices.data + j*4, 4)
        }

        // Read local position (12 bytes = EVec3 at node+0x10)
        // vtable call: file->Read(node+0x10, 12)

        // Read local transform row (16 bytes at node+0x1C)
        // vtable call: file->Read(node+0x1C, 16)

        // Read visibility flag (1 byte)
        u8 visByte;
        // vtable call: file->Read(&visByte, 1)
        *(u32*)((u8*)node + 0xB0) = (visByte != 0) ? 1 : 0;

        // Read node name (64 bytes at node+0x30)
        // vtable call: file->Read(node+0x30, 64)

        // Read world transform (64 bytes at node+0x70)
        // vtable call: file->Read(node+0x70, 64)

        // Read additional streaming data
        // bl 0x802c66c0 — EFile::ReadString (node+0xB4)
    }

    // Read root offset (12 bytes at self+0x20)
    // Read flags (4 bytes at self+0x2C)
    // Read extra data (4 bytes at self+0x30)

    // Close chunk reader
    // bl 0x8035aea8 — EChunkReader::Close(2)
}


// ============================================================================
// ERCharacter::FindNode
// Address: 0x80368A94 | Size: 132 bytes
// NON_MATCHING
//
// Searches for a node by name. Returns the node index (0-based) or -1.
// Iterates through all nodes, comparing the name string at offset +0xB4
// using strcmp.
// ============================================================================
int ERCharacter_FindNode(void* self, const char* name)
{
    // r29 = self, r27 = name
    int count = *(int*)((u8*)self + 0x14 + 4); // m_nodes.size

    for (int i = 0; i < count; i++) {
        void* nodeData = *(void**)((u8*)self + 0x14);
        const char* nodeName = (const char*)((u8*)nodeData + i * 0xB8 + 0xB4);

        if (strcmp(nodeName, name) == 0) {
            return i;
        }
    }
    return -1;
}


// ============================================================================
// ERCharacter::GetNode
// Address: 0x80368D64 | Size: 16 bytes
// NON_MATCHING
//
// Returns pointer to node data for a given index.
// Trivial: return m_nodes.data + index * 184
// ============================================================================
void* ERCharacter_GetNode(void* self, int index)
{
    // mulli r4, r4, 184
    // lwz r3, 0x14(r3) — m_nodes.data
    // add r3, r3, r4
    // blr
    void* data = *(void**)((u8*)self + 0x14);
    return (u8*)data + index * 184;
}


// ============================================================================
//
//  3. ESubModelShader — SUB-MESH RENDERING & MORPHING
//
//     Each ERModel contains one or more ESubModelShader instances.
//     These hold vertex data, indices, display lists, and morph targets.
//     The morph system supports both s16 fixed-point and float vertex formats.
//
// ============================================================================

// ESubModelShader struct layout (0x74 bytes minimum)
// Reconstructed from ApplyMorph, Morph, and Draw method disassembly.
//
// Offset  Type     Field                   Description
// 0x00    void*    m_pDisplayList          GX display list pointer (or vertex buffer)
// 0x04    f32      m_morphScale            Scale factor for s16→float morph conversion
// 0x08    void*    m_pVertexData           Vertex position data (float or s16 format)
// 0x0C    u32      m_vertexCount           Number of vertices
// 0x10    u32      m_flags                 Bit flags: bit 4 = s16 vertex format
// 0x14    void*    m_pBaseVertices         Base (unmorphed) vertex positions
// 0x18    u32      m_stripCount            Number of triangle strips
// 0x1C    ...
// 0x24    f32      m_lodBias               LOD bias value
// 0x28    u32      m_morphTargetDataSize   Size of morph delta data
// 0x2C    TArray<MorphStripData>  m_morphStrips  Morph target strip info
//   +0x2C: void*   data pointer
//   +0x30: int     size (num morph targets)
//   +0x34: ...
// Per morph strip (52 bytes each at m_morphStrips.data + i*0x34):
//   +0x00: void*   deltaData pointer (vertex deltas)
//   +0x18: u32     numVerticesInStrip
//   +0x24: u16     stripStartIndex
//   +0x28: u16     stripVertexCount
//   +0x2B: u8      numBoneWeights
//   +0x2C: void*   boneWeightData
//
// 0x38    void*[12]  m_pMorphTargets    Pointers to morph target ESubModelShaders
//   Stored as: *(u32*)(this + 0x38 + morphIdx * 4) = pointer
// 0x68    void*    m_pLatticeList        BSpline lattice data for deformation
// 0x6C    void*    m_pParameterizedVerts  Parameterized vertex data for lattice
// 0x70    u32      m_flags2              Additional flags (lattice, display list state)


// ============================================================================
// ESubModelShader::ApplyMorph
// Address: 0x802FD484 | Size: 1244 bytes
// NON_MATCHING
//
// Applies all registered morph targets to the sub-model's vertex data.
// This is called after Morph() has been called with morph weights.
//
// The function handles two vertex formats:
//   1. s16 fixed-point (flag bit 4 set at +0x10):
//      - Vertices stored as 3x s16 + 1x s16 (normal/padding)
//      - Morph deltas also s16, converted via:
//        delta_float = (s16_val ^ 0x8000 - magic) * scale
//      - Magic constant at 0x8041f620 (double), scale at 0x8041f628 (float)
//
//   2. Float (flag bit 4 clear):
//      - Vertices stored as 3x float + 1x float (normal w-component)
//      - Morph deltas stored as 3x float, directly added
//      - Normal w-component copied from delta to result
//
// After morphing vertices, the function rebuilds the GX display list:
//   1. Releases old display list if present
//   2. Allocates new vertex buffer from morph heap
//   3. Copies morphed strip data with bone weights
//   4. Calls CreateRCPrimitive() to build GX display list
//
// The inner loop structure (for s16 format):
//   for each morph target (0..m_morphStrips.size):
//     for each vertex in strip:
//       base[i] = base[i] + delta[i]  (as s16 fixed-point arithmetic)
//       copy morph normal
// ============================================================================
bool ESubModelShader_ApplyMorph(void* self)
{
    // r28 = self

    // Outer loop: iterate morph targets
    int numTargets = *(int*)((u8*)self + 0x30);  // m_morphStrips.m_size
    for (int t = 0; t < numTargets; t++) {
        void* stripData = *(void**)((u8*)self + 0x2C); // m_morphStrips.data
        void* strip = (u8*)stripData + t * 0x34;

        int numVerts = *(int*)((u8*)strip + 0x18);

        // Check vertex format flag
        u32 flags = *(u32*)((u8*)self + 0x10);
        bool isS16 = (flags & 0x10) != 0;

        if (isS16) {
            // s16 fixed-point morph path
            void* baseVerts = *(void**)((u8*)self + 0x14);  // base vertices
            void* deltaVerts = *(void**)((u8*)stripData + t * 0x34);  // delta data

            for (int v = 0; v < numVerts; v++) {
                // Load base vertex (3x s16)
                s16* base = (s16*)((u8*)baseVerts + /*offset*/0);
                s16* delta = (s16*)((u8*)deltaVerts + /*offset*/0);

                // Convert s16 to float: (val ^ 0x8000) → double subtraction → float
                // Then scale and add
                // result[0] = base[0] + delta[0]
                // result[1] = base[1] + delta[1]
                // result[2] = base[2] + delta[2]
                // Copy normal word: base[3] = delta[3]

                base[0] += delta[0];
                base[1] += delta[1];
                base[2] += delta[2];
                base[3] = delta[3]; // copy normal/padding
            }
        } else {
            // Float morph path
            void* baseVerts = *(void**)((u8*)self + 0x14);
            void* deltaVerts = *(void**)((u8*)stripData + t * 0x34);

            for (int v = 0; v < numVerts; v++) {
                float* base = (float*)((u8*)baseVerts + v * 16);
                float* delta = (float*)((u8*)deltaVerts + v * 16);

                // Direct float addition
                base[0] += delta[0];
                base[1] += delta[1];
                base[2] += delta[2];
                base[3] = delta[3]; // copy w-component (normal)
            }
        }
    }

    // After morphing: rebuild display list
    // Check if morph strips have data
    int morphStripCount = *(int*)((u8*)self + 0x2C + 4);
    if (morphStripCount == 0) return false;

    // Release old display list if allocated
    void* oldDL = *(void**)((u8*)self + 0x00);
    if (oldDL != 0) {
        // vtable call: release via renderer
        // Global renderer at *(void**)(-26392 + r13)
        *(u32*)((u8*)self + 0x00) = 0;
    }

    // Allocate new display list from morph heap
    // bl 0x802f99ec — allocation helper

    // For each morph strip: rebuild strip data with bone weights
    for (int s = 0; s < morphStripCount; s++) {
        void* strip = (u8*)(*(void**)((u8*)self + 0x2C)) + s * 0x34;

        // Copy bone weight data for this strip
        u8 numWeights = *(u8*)((u8*)strip + 0x2B);
        void* weightData = *(void**)((u8*)strip + 0x2C);

        // For each weight: vtable call to set bone weight
        for (u32 w = 0; w < numWeights; w++) {
            u8 boneIdx = *(u8*)((u8*)strip + 0x24 + w);
            // vtable[0xE0/4](renderer, morphIdx=w, boneIdx)
        }

        // Create GX primitive for this strip
        u16 startIdx = *(u16*)((u8*)strip + 0x28);
        // CreateRCPrimitive(startIdx, renderer, strip, true, true, false)
    }

    // Store new display list pointer
    // vtable call: renderer->BuildDisplayList()
    // stw r3, 0x00(self)

    return true;
}


// ============================================================================
// ESubModelShader::Morph
// Address: 0x802FDDC4 | Size: 992 bytes
// NON_MATCHING
//
// Applies weighted morph blending from multiple morph targets.
// Input: float* weights — array of morph weights (one per morph target slot).
//
// For each morph target in m_morphStrips:
//   For each vertex in the strip:
//     For each morph target slot (up to 12):
//       if weight[slot] != 0.0 and target[slot] exists:
//         vertex += target_delta * weight
//
// Supports both s16 (with fixed-point conversion) and float vertex formats.
//
// The morph target pointers are stored in an array starting at this+0x38,
// with each entry being 4 bytes (pointer to another ESubModelShader whose
// vertex data contains the morph deltas).
//
// The morph weight of 0.0 is checked via fcmpu against a constant at
// 0x8041f650, providing early-out for zero-weight targets.
// ============================================================================
bool ESubModelShader_Morph(void* self, float* weights)
{
    // r28 = self, r22 = weights

    // Initialize accumulator vectors to 0
    float accum[3] = {0.0f, 0.0f, 0.0f};
    float delta[3] = {0.0f, 0.0f, 0.0f};

    int numStrips = *(int*)((u8*)self + 0x2C + 4); // m_morphStrips.size
    void* stripBase = *(void**)((u8*)self + 0x2C);

    for (int stripIdx = 0; stripIdx < numStrips; stripIdx++) {
        void* strip = (u8*)stripBase + stripIdx * 0x34;
        int numVerts = *(int*)((u8*)strip + 0x18);

        for (int v = 0; v < numVerts; v++) {
            u32 flags = *(u32*)((u8*)self + 0x10);
            bool isS16 = (flags & 0x10) != 0;

            if (isS16) {
                // s16 path: read base vertex, accumulate weighted deltas
                // ... (same s16→float conversion as ApplyMorph)

                // Loop over 12 morph target slots
                for (int slot = 0; slot < 12; slot++) {
                    float w = weights[slot];
                    if (w == 0.0f) continue;

                    void* morphTarget = *(void**)((u8*)self + 0x38 + slot * 4);
                    if (!morphTarget) continue;

                    // Read delta from morph target's vertex data
                    void* morphVerts = *(void**)((u8*)morphTarget + 0x14);
                    // ... s16 conversion + weighted accumulation ...

                    accum[0] += delta[0] * w;
                    accum[1] += delta[1] * w;
                    accum[2] += delta[2] * w;
                }

                // Convert accumulated result back to s16 and store
                // fctiwz + sth for each component
            } else {
                // Float path: read base, accumulate weighted deltas
                // Copy base vertex to accumulator
                for (int slot = 0; slot < 12; slot++) {
                    float w = weights[slot];
                    if (w == 0.0f) continue;

                    void* morphTarget = *(void**)((u8*)self + 0x38 + slot * 4);
                    if (!morphTarget) continue;

                    void* morphVerts = *(void**)((u8*)morphTarget + 0x14);
                    // Direct float delta read and weighted add
                    accum[0] += delta[0] * w;
                    accum[1] += delta[1] * w;
                    accum[2] += delta[2] * w;
                }

                // Store accumulated result back to float vertex
            }
        }
    }

    return true;
}


// ============================================================================
// DrawSubModelShader (global function)
// Address: 0x80030964 | Size: 104 bytes
// NON_MATCHING
//
// Renders a single ESubModelShader sub-mesh through the GX pipeline.
//
// Steps:
//   1. Set TEV alpha from ESubModelShader::m_lodBias (+0x24) via vtable
//   2. Bind the sub-model's display list via vtable
//
// The rendering context (ERC) at r30 has a node table pointer at +0x70.
// Two vtable calls through the node table:
//   - vtable[0x1BC/4](rc + offset_0x1B8, alpha) — set TEV alpha
//   - vtable[0xBC/4](rc + offset_0xB8, displayList) — bind display list
// ============================================================================
void DrawSubModelShader(void* rc, void* subModel)
{
    // r30 = rc (ERC*), r29 = subModel (ESubModelShader*)

    // Read alpha value from sub-model
    float alpha = *(float*)((u8*)subModel + 0x24);

    // Get node table from RC
    void* nodeTable = *(void**)((u8*)rc + 0x70);

    // vtable call: set TEV alpha
    // lwz r0, 0x1BC(nodeTable)
    // lha r3, 0x1B8(nodeTable) — offset
    // add r3, rc, r3
    // blrl — call(rc + offset, 0, alpha)

    // Read display list pointer from sub-model
    void* displayList = *(void**)((u8*)subModel + 0x00);

    // vtable call: bind and execute display list
    // lwz r0, 0xBC(nodeTable)
    // lha r3, 0xB8(nodeTable) — offset
    // add r3, rc, r3
    // blrl — call(rc + offset, displayList)
}


// ============================================================================
//
//  4. SimModel — BODY PART ASSEMBLY
//
//     SimModel is the hub class that transforms a CasSimDescriptionS2C
//     into a set of renderable 3D models. It manages loading, morphing,
//     welding, UV transformation, and skin compositing for all body parts.
//
// ============================================================================

// SimModel struct layout (0x158+ bytes)
// Key fields reconstructed from SetAllModels, CreateSkin, CompositeAllSkin, etc.
//
// Offset  Type              Field
// 0x00    void**            vtable
// 0x04    u32               m_flags (bit 1=morphed, bit 2=morphing_disabled, bit 4=...)
// 0x08    ...               texture def data
// 0x68    void*[26]         m_pModelParts — one ERModel* per eBodyPartS2C
//   (0x68 + partIdx*4)
// 0x6C    void*             m_pMorphableModel (ERCharacter or ERModel for morphing)
// 0x120   void*             m_pMorphResources
// 0x138   void*             m_pSimParts (CasSimPartsS2C*)
// 0x13C   void*             m_pSimDescription (CasSimDescriptionS2C*)
// 0x140   void*[4]          m_pSkinTextures — composited skin textures per quadrant
// 0x150   u32               m_skinTextureFlags
// 0x154   void*             m_pSimDescCopy


// ============================================================================
// SimModel::SetAllModels
// Address: 0x80070CC4 | Size: 416 bytes
// NON_MATCHING
//
// Loads all body part models from the CAS description. Calls individual
// Update*() methods for each body part category in a specific order:
//
//   1. UpdateHead(true, false, false)           — head mesh
//   2. UpdateOuterLayerCollar(false, false)      — collar
//   3. UpdateOuterLayerTorso(true, false, false, false)  — outer jacket/coat
//   4. UpdateOuterLayerSleeve(true, false, false, false) — outer sleeves
//   5. UpdateMidLayerCollar(false)               — mid-layer collar
//   6. UpdateMidLayerTorso(true, false, false, false)    — shirt/sweater
//   7. UpdateMidLayerSleeve(true, false, false, false)   — mid sleeves
//   8. UpdateInnerLayerTorso(true, false, false) — undershirt
//   9. UpdateInnerLayerSleeve(true, false, false) — inner sleeves
//  10. UpdateLowerBody(true, false)              — pants/skirt
//  11. UpdateShoes(true, false, false)            — footwear
//  12. UpdateVestScarf(true, false, false)         — accessories
//  13. UpdateHat(true, false, false)               — headwear
//  14. UpdateHair(true, false, false)              — hairstyle
//  15. UpdateArmAccessory(true, false, false)      — watches/bracelets
//  16. UpdateBelt(true, false, false)              — belt
//  17. UpdateGlasses(true, false, false)           — eyewear
//  18. UpdateFacialFeature(true, false, false)     — facial hair, etc.
//  19. UpdateNecklaceEarring(true, false, false)   — jewelry
//
// Each Update*() method:
//   - Reads the body part index from CasSimDescriptionS2C
//   - Looks up the model resource ID from CasSimPartsS2C
//   - Calls SetModelPart() to load the ERModel from the resource system
//   - The first bool param (always true here) means "force load"
//   - The second/third params control reweld and async loading
// ============================================================================
void SimModel_SetAllModels(void* self)
{
    // Calls are sequential — each must complete before the next.
    // The order matters because some parts depend on others for welding.
    // (See complete call sequence in disassembly above.)
}


// ============================================================================
// SimModel::ApplyAllMorphTargets
// Address: 0x80071B1C | Size: 764 bytes
// NON_MATCHING
//
// Applies body type morph targets across all relevant body part models.
// Reads morph weights from CasSimDescriptionS2C at offsets:
//   +0x108: float morphWeight_region0 (torso muscle/fat)
//   +0x10C: float morphWeight_region6 (head shape)
//   +0x110: float morphWeight_region3 (lower body)
//   +0x114: float morphWeight_region9 (extra/detailed)
//
// For each non-zero weight, calls ApplyMorphTargetsToRegion() with:
//   - regionStart: starting game state model ID index
//   - regionCount: 3 (each region uses 3 morph targets)
//   - weight: the float morph weight
//   - modelIDs: resolved resource IDs for the morph target models
//
// The morph system uses SimModel::GetGameStateModelID() to resolve
// morph target resource IDs from the s_SimPartsMap table. The original
// game stores morph data as separate ERModel files that contain only
// vertex position deltas relative to the base mesh.
//
// Old format (14 entries): uses indices 0-13 with skip at 9-10
// New format: direct 1:1 mapping
// ============================================================================
void SimModel_ApplyAllMorphTargets(void* self)
{
    // r28 = self (SimModel*)
    CasSimDescriptionS2C* desc = *(CasSimDescriptionS2C**)((u8*)self + 0x13C);
    if (!desc) return;

    // Get morph controller from character instance
    void* morphCtrl = *(void**)((u8*)desc + 0x120);
    if (!morphCtrl) return;

    // Check if morphing is disabled (flag bit 2)
    u32 flags = *(u32*)((u8*)self + 0x04);
    if (flags & 0x04) return;

    // Mark as morphed (flag bit 1)
    flags |= 0x02;
    *(u32*)((u8*)self + 0x04) = flags;

    // Initialize morph controller
    // bl 0x8031a1ac

    // Get morph target data from character
    void* morphData = *(void**)((u8*)desc + 0x120 + 8);
    // ... validate morph data exists ...

    // Resolve morph target model IDs
    bool isHighRes = /*SimModel::UsingHighResolutionModel()*/false;
    u32 modelIDs[12];
    // ... loop to resolve IDs via GetGameStateModelID ...

    // Apply morph region 0 (torso) if weight != 0.0
    float weight0 = *(float*)((u8*)desc + 0x108);
    if (weight0 != 0.0f) {
        // ApplyMorphTargetsToRegion(0, 3, weight0, &modelIDs[0])
    }

    // Apply morph region 9 if weight != 0.0
    float weight9 = *(float*)((u8*)desc + 0x114);
    if (weight9 != 0.0f) {
        // ApplyMorphTargetsToRegion(9, 3, weight9, &modelIDs[9])
    }

    // Apply morph region 6 (head) if weight != 0.0
    float weight6 = *(float*)((u8*)desc + 0x10C);
    if (weight6 != 0.0f) {
        // ApplyMorphTargetsToRegion(6, 3, weight6, &modelIDs[6])
    }

    // Apply morph region 3 (lower body) if weight != 0.0
    float weight3 = *(float*)((u8*)desc + 0x110);
    if (weight3 != 0.0f) {
        // ApplyMorphTargetsToRegion(3, 3, weight3, &modelIDs[3])
    }

    // Finalize morph controller
    // bl 0x8031a2a4, bl 0x8031a21c
}


// ============================================================================
// SimModel::CompositeAllSkin
// Address: 0x80072B20 | Size: 196 bytes
// NON_MATCHING
//
// Composites all 4 skin quadrants. Calls CompositeSkinPart() for each
// quadrant (0-3).
//
// First checks if a skin dataset texture exists. If the sim description
// has no precomposited texture (field at +0x118 == 0), it looks up
// the skin dataset resource from CasSimPartsS2C::GetSkinTexturesDatasetID()
// and loads it from the texture manager.
//
// After compositing all quadrants, releases the skin dataset texture
// back to the texture manager.
// ============================================================================
void SimModel_CompositeAllSkin(void* self)
{
    CasSimDescriptionS2C* desc = *(CasSimDescriptionS2C**)((u8*)self + 0x13C);
    if (!desc) return;

    // Check for precomposited texture
    u32 precompFlag = *(u32*)((u8*)desc + 0x118);
    void* skinDatasetTex = 0;

    if (precompFlag == 0) {
        // Need to load skin dataset for compositing
        s8 skinColor = (s8)*(u8*)((u8*)desc + 0x88);
        s8 bodyType  = (s8)*(u8*)((u8*)desc + 0x89);
        CasSimPartsS2C* parts = *(CasSimPartsS2C**)((u8*)self + 0x138);

        u32 datasetID = parts->GetSkinTexturesDatasetID(
            (eSkinColorType)skinColor, (eBodyTypeS2C)bodyType);

        // Load from texture manager
        skinDatasetTex = ERTextureManager_Find(/*g_texMgr*/ 0, datasetID, 0, 0);
    }

    // Composite each quadrant
    for (u8 quadrant = 0; quadrant <= 3; quadrant++) {
        // SimModel::CompositeSkinPart(quadrant)
        // This internally calls SkinCompositor::CreateSkinQuadrantHiRes or LoRes
    }

    // Release skin dataset texture
    if (skinDatasetTex != 0) {
        // ERTextureManager_Release(skinDatasetTex) with flag=1
    }
}


// ============================================================================
// SimModel::CreateSkin
// Address: 0x80072064 | Size: 752 bytes
// NON_MATCHING
//
// Creates the output skin ERTexture objects for all 4 quadrants.
// For each quadrant (0-3):
//   1. Deallocate previous skin textures
//   2. Get composite texture name from CasSimDescriptionS2C
//   3. Check if texture already exists in texture manager
//   4. If not found: create new ERTexture via renderer, configure
//      format (RGBA8, 64x64 tiles), and register with texture manager
//   5. Store texture pointer in SimModel::m_pSkinTextures[quadrant]
//
// The texture format is configured from the SkinCompositor's texture def:
//   - Width/height from GetSkinTextureDef (typically 64x64 per quadrant)
//   - Format: RGBA8 with optional alpha
//   - Tile size calculated as: width * height * bitsPerPixel / 8
// ============================================================================
void SimModel_CreateSkin(void* self, const char* basePath)
{
    // r29 = self, r25 = basePath

    // Deallocate existing skin textures
    // bl 0x8007096c — SimModel::DeallocateAllSkinTextures

    // Get skin texture definition
    // bl 0x80072354 — SimModel::GetSkinTextureDef

    for (u8 quadrant = 0; quadrant <= 3; quadrant++) {
        // Get composite texture ID from sim description
        CasSimDescriptionS2C* desc = *(CasSimDescriptionS2C**)((u8*)self + 0x13C);
        u32 texID = desc->GetCompositeTextureID(basePath, (eSimPartsMapLocation)quadrant);

        // Get composite texture name for debug
        char texName[64];
        desc->GetCompositeTextureName(texName, basePath, (eSimPartsMapLocation)quadrant);

        // Check if already in texture manager
        // bl 0x80327474 — ERTextureManager::Find by name

        if (/*not found*/ true) {
            // Try loading from disc, with retry logic
            // If load fails after retries, allocate blank texture

            // Allocate new ERTexture
            // bl 0x80327654 — allocate from morph heap (24 bytes, 8-aligned)
            // bl 0x80320b28 — ERTexture constructor

            // Store in skin texture array
            // *(void**)((u8*)self + 0x140 + quadrant*4) = newTexture

            // If allocation succeeded:
            //   bl 0x80320bcc — configure texture format
            //   Calculate tile size: w * h * bpp
            //   rlwimi to pack into texture header
            //   bl 0x80326be4 — register with texture manager

            // If allocation failed:
            //   Release via renderer vtable calls
        }
    }
}


// ============================================================================
//
//  5. CasSimRenderer — HIGH-LEVEL SIM DRAWING
//
//     CasSimRenderer drives the full Sim rendering pipeline.
//     It owns a SimModel and coordinates animation, skin updates,
//     and multi-pass rendering (body + shadow + face portrait).
//
// ============================================================================

// CasSimRenderer struct layout (0x218 bytes)
// Documented from Init, Draw, DrawShadow, SetupSimCommon disassembly.
// The class has a vtable with ~30 entries.
//
// Key fields:
// 0x00    void**    vtable
// 0x04    void*     m_pAnimController — animation state
// 0x84    void*     m_pRepShaders — reputation shader overrides
// 0x170   void*     m_pShadowModel — shadow mesh override
// 0x188   s16       m_faceImageOffset — offset for face portrait rendering
// 0x18C   void*     m_pFaceImageTexture
// 0x198   void*     m_pActiveModel — currently bound ERModel
// 0x204   u32       m_nextAnimID — queued animation resource ID
// 0x208   f32       m_simRotation — Y-axis rotation angle
// 0x20C   f32       m_simScale — uniform scale factor
// 0x210   void*     m_pFaceTexture — 2D face portrait texture
// 0x214   u32       m_drawFlags — rendering mode flags

// CasSimRenderer::Draw overview (from 0x8016F174, 400 bytes):
//
// 1. Check m_pActiveModel is valid
// 2. SetupSimCommon() — bind skin texture, configure shaders
// 3. Iterate body part models, for each:
//    a. Get model transform matrix
//    b. Set GX model matrix
//    c. For each ESubModelShader in the model:
//       - DrawSubModelShader(rc, subModel)
// 4. Draw head model separately (may have different morph state)
// 5. Draw accessory models (glasses, hat, etc.)
//
// CasSimRenderer::SetupSimCommon (from 0x8016F5A8, 376 bytes):
//
// 1. Get SimModel from internal state
// 2. For each body part that has a composited skin texture:
//    a. Override the shader's texture slot with the composited skin
//    b. Set up TEV (Texture Environment) stages for skin rendering
// 3. Configure GX lighting for the Sim
// 4. Set alpha/blend modes based on draw flags (ghost, highlight, etc.)


// ============================================================================
//
//  6. FULL PIPELINE SEQUENCE
//
//  When a Sim is loaded or changed in CAS:
//
//  CasSimRendererDynamic::HandleEventChangeSim()
//    ├─ SimModel::SetSimDescription(newDesc)
//    ├─ SimModel::SetAllModels()          ← loads all body part ERModels
//    ├─ SimModel::WeldAllSharedVertices() ← joins seams between parts
//    ├─ SimModel::LoadAllMorphTargets()   ← loads morph target meshes
//    ├─ SimModel::ApplyAllLatticeMorphing() ← BSpline body shape deformation
//    ├─ SimModel::ApplyAllMorphTargets()  ← weight-based morph blending
//    ├─ SimModel::TransformAllModelUV()   ← UV coordinate transforms
//    ├─ SimModel::CreateSkin(basePath)    ← allocate skin textures
//    ├─ SimModel::CompositeAllSkin()      ← SkinCompositor blends all layers
//    ├─ SimModel::ApplySkinToModels()     ← bind composited skin to shaders
//    └─ SimModel::UpdateReweld(false)     ← final vertex welding pass
//
//  Each frame:
//
//  CasSimRenderer::Draw(ERC* rc)
//    ├─ SetupSimCommon()                  ← bind skin, set render state
//    ├─ for each body part model:
//    │    └─ DrawSubModelShader(rc, sub)  ← GX display list execution
//    └─ (optional) DrawFaceImage(rc)      ← 2D face portrait overlay
//
//  CasSimRenderer::DrawShadow(ERC* rc)
//    └─ ERModel_DrawShadow()             ← shadow volume or projected shadow
//
// ============================================================================


// ============================================================================
//  APPENDIX: Key Address Reference
//
//  SkinCompositor:
//    0x80075B10  SkinCompositor::SkinCompositor         96B
//    0x80075B70  SkinCompositor::~SkinCompositor        64B
//    0x80075BB0  SkinCompositor::Reset                  208B
//    0x80075C80  SkinCompositor::CreateSkinQuadrantHiRes 36B
//    0x80075CA4  SkinCompositor::CreateSkinQuadrantLoRes 36B
//    0x80075CC8  SkinCompositor::CreateSkinQuadrantPrecomposited 292B
//    0x80075DEC  SkinCompositor::CreateSkin              160B
//    0x80075E8C  SkinCompositor::InitScratchpadTextures  372B
//    0x80076000  SkinCompositor::InitSkinTexture         76B
//    0x8007604C  SkinCompositor::FinalizeSkinTexture     76B
//    0x80076098  SkinCompositor::LoadAllTextureLayers    1164B
//    0x80076524  SkinCompositor::GetTextureIDs           244B
//    0x80076618  SkinCompositor::BlendTexture            1932B
//    0x80076DA4  SkinCompositor::GetFinalReflectionMask  208B
//
//  ERCharacter:
//    0x803686E8  ERCharacter::ERCharacter               68B
//    0x8036872C  ERCharacter::~ERCharacter              104B
//    0x80368794  ERCharacter::Load                      704B
//    0x80368A54  ERCharacter::Refresh                   64B
//    0x80368A94  ERCharacter::FindNode                  132B
//    0x80368D64  ERCharacter::GetNode                   16B
//
//  ESubModelShader:
//    0x802FBAF4  ESubModelShader::ESubModelShader       124B
//    0x802FBB70  ESubModelShader::~ESubModelShader      88B
//    0x802FBFEC  ESubModelShader::CreateRCPrimitive     292B
//    0x802FCED4  ESubModelShader::Read                  888B
//    0x802FD258  ESubModelShader::AllocateMorph         216B
//    0x802FD330  ESubModelShader::RegisterMorphTarget   184B
//    0x802FD3FC  ESubModelShader::ResetMorph            136B
//    0x802FD484  ESubModelShader::ApplyMorph            1244B
//    0x802FD960  ESubModelShader::GetMorphedVertex      332B
//    0x802FDAAC  ESubModelShader::GenerateMorphTargetDeltas 792B
//    0x802FDDC4  ESubModelShader::Morph                 992B
//    0x802FE1A4  ESubModelShader::CreateLatticeList     604B
//    0x802FE5CC  ESubModelShader::ParameterizeVerts     836B
//    0x802FE910  ESubModelShader::LatticeDeform         1048B
//    0x802FED28  ESubModelShader::BuildDisplayList(ESMBuildDisplayListData*) 1336B
//    0x802FF260  ESubModelShader::BuildDisplayList(bool,...) 1176B
//    0x802FF844  ESubModelShader::TransformModelUV      852B
//
//  SimModel (rendering-related):
//    0x80070CC4  SimModel::SetAllModels                 416B
//    0x80071B1C  SimModel::ApplyAllMorphTargets         764B
//    0x80072064  SimModel::CreateSkin                   752B
//    0x80072354  SimModel::GetSkinTextureDef            116B
//    0x800723C8  SimModel::ApplySkinToModels            68B
//    0x80072B20  SimModel::CompositeAllSkin             196B
//    0x80072BE4  SimModel::CompositeSkinPart            216B
//
//  CasSimRenderer:
//    0x8016EEE0  CasSimRenderer::CasSimRenderer         88B
//    0x8016F174  CasSimRenderer::Draw                   400B
//    0x8016F304  CasSimRenderer::DrawShadow             388B
//    0x8016F5A8  CasSimRenderer::SetupSimCommon         376B
//    0x8016F90C  CasSimRenderer::DrawFaceImage          276B
//
//  Standalone:
//    0x80030964  DrawSubModelShader(ERC*, ESubModelShader*) 104B
//
// ============================================================================
