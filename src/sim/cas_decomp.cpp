/**
 * Create-A-Sim (CAS) System -- Decompiled Implementation
 *
 * Source: src/sim/cas_decomp.cpp
 * Headers: include/classes/CasSimDescriptionS2C.h
 *          include/classes/CasSimPartsS2C.h
 *          include/classes/CasGenetics.h
 *          include/classes/CasMediator.h
 *          include/classes/CasSimState.h
 *          include/classes/CasCostumes.h
 * Original ELF: extracted/files/u2_ngc_release_dvd.elf
 * Compiler: SN Systems ProDG for GameCube
 *
 * This file documents the decompiled Create-A-Sim subsystem from The Sims 2
 * for GameCube. CAS is the character creation/editing pipeline that generates
 * and customizes Sim appearance, clothing, personality, and genetics.
 *
 * ============================================================================
 * ARCHITECTURE OVERVIEW
 * ============================================================================
 *
 * CAS is built around a Mediator pattern with an event-driven UI:
 *
 *   CASTarget (top-level controller)
 *     |
 *     +-- CasMediator (event bus, bridges UI <-> sim data)
 *     |     |
 *     |     +-- CasSimState (per-sim editing state)
 *     |     +-- CasSimRendererDynamic (3D preview renderer)
 *     |     +-- CasScene (3D scene/background)
 *     |
 *     +-- CASGeneticsTarget (genetics/inheritance screen)
 *     |     +-- CasGenetics (blend logic, grandparent system)
 *     |
 *     +-- CASSelectionTarget (body part selection grids)
 *     +-- CASBodyTarget (body type, skin color, hair)
 *     +-- CASFashionTarget (clothing layers)
 *     +-- CASMorphTarget (facial morph sliders)
 *     +-- CASMiscTarget (glasses, etc.)
 *     +-- CASPersonalTarget (personality, aspiration, zodiac)
 *     +-- CASTattooTarget (tattoo overlays)
 *     +-- CASRoommateTarget (roommate slot management)
 *     +-- CasNpcEditor (NPC-specific editing)
 *
 * Data flow:
 *   CasSimPartsS2C  -- static catalog of all available parts/textures
 *   CasSimDescriptionS2C -- mutable per-sim configuration (what the sim wears/looks like)
 *   CasSimState     -- wraps CasSimDescriptionS2C with undo/adjacency navigation
 *   CasCostumes     -- saved costume presets (persistent across sessions)
 *   CasGenetics     -- grandparent blending for genetics screen
 *
 * ============================================================================
 * CASTarget -- TOP-LEVEL CAS CONTROLLER
 * ============================================================================
 *
 * CASTarget is the main entry point for all Create-A-Sim flows. It manages
 * navigation between CAS screens, owns the sub-target objects, and handles
 * saving completed Sims to the neighborhood.
 *
 * Layout (from assembly -- total size ~0x1440 / 5184 bytes):
 *
 *   Offset  Size  Purpose
 *   ------  ----  -------
 *   0x000   0x28  Base UIObjectBase fields (vtable at 0x80467068)
 *   0x028   0x10  CasListener sub-object (vtable at 0x80467008)
 *   0x038   0x10  Additional listener sub-object
 *   0x048   0x10  Additional listener sub-object
 *   0x058   0x10  Additional listener sub-object
 *   0x068   0x10  Additional listener sub-object
 *   0x078   ---   Padding/misc
 *   0x080   0x04  CASTarget::CasListener vtable (set to 0x80467008)
 *   0x088   0x04  Secondary vtable pointer (0x80466F88)
 *   0x0A8   0x10  Unknown sub-objects x4
 *   0x0D8   ---   CasSimRenderer (at offset 0xD8)
 *   0x108   0x750 CasSimState array [4] (592 bytes each, at offsets 0x108)
 *                 -- supports up to 4 sims in the household
 *   0x0A48  ---   CasMediator storage area
 *   0x1348  0x04  m_hasSimInSlot bitmask
 *   0x1350  0x04  m_casScene (CasScene*)
 *   0x1354  0x04  m_npcEditor (CasNpcEditor*)
 *   0x1360  0x04  m_currentSimNumber
 *   0x1370  0x04  m_geneticsTarget (CASGeneticsTarget*)
 *   0x1374  0x04  m_morphTarget (CASMorphTarget*)
 *   0x1378  0x04  m_bodyTarget (CASBodyTarget*)
 *   0x137C  0x04  m_selectionTarget (CASSelectionTarget*)
 *   0x1380  0x04  m_miscTarget (CASMiscTarget*)
 *   0x1384  0x04  m_fashionTarget (CASFashionTarget*)
 *   0x1388  0x04  m_personalTarget (CASPersonalTarget*)
 *   0x138C  0x04  m_tattooTarget (CASTattooTarget*)
 *   0x1390  0x04  m_roommateTarget (CASRoommateTarget*)
 *   0x1398  0x04  m_loaderUI
 *   0x13FC  0x04  Unknown pointer
 *   0x140C  0x04  Unknown pointer
 *   0x1428  0x04  m_firstName wchar_t*
 *   0x1430  0x04  m_lastName wchar_t*
 *
 * Navigation table: CASTarget::m_casNavigationTable at 0x80436C20 (952 bytes)
 * Conditional table: CASTarget::m_casConditional at 0x80436FD8 (576 bytes)
 *
 * Key functions:
 *   CASTarget::CASTarget(bool)             -- 0x80190EA0 (2912B)
 *   CASTarget::Init(bool)                  -- 0x80191C94 (1540B)
 *   CASTarget::SaveSimToFamilySlot(int)    -- 0x80192360 (760B)
 *   CASTarget::SaveCASDataToNeighborhood() -- 0x80192658 (468B)
 *   CASTarget::ChangeMediator(int)         -- 0x80192DB8 (804B)
 *   CASTarget::HandleConditionalNav(int)   -- 0x80195154 (2760B)
 */

// ============================================================================
// Forward declarations and class stubs
// ============================================================================

// Basic type aliases
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

#ifndef NULL
#define NULL 0
#endif

// External C functions
extern "C" {
    int  rand(void);
    void memcpy(void* dst, const void* src, unsigned int n);
    void memset(void* dst, int val, unsigned int n);
}

// Skin color blending helper (stub -- actual implementation in CasGenetics asm)
static s8 BlendSkinColor(unsigned char c1, unsigned char c2) { return (s8)((c1 + c2) / 2); }

// Opaque stub classes (used only as pointers or with new)
class CasMediator      {};
class CasSimState      {};
class CasScene         {};
class CasCostumes      {};

// Sub-target classes - need complete type for "new" expressions
class CASSelectionTarget { public: virtual ~CASSelectionTarget() {} };
class CASBodyTarget      { public: virtual ~CASBodyTarget() {} };
class CASFashionTarget   { public: virtual ~CASFashionTarget() {} };
class CASMiscTarget      { public: virtual ~CASMiscTarget() {} };
class CASMorphTarget     { public: virtual ~CASMorphTarget() {} };
class CASPersonalTarget  { public: virtual ~CASPersonalTarget() {} };
class CASTattooTarget    { public: virtual ~CASTattooTarget() {} };
class CASRoommateTarget  { public: virtual ~CASRoommateTarget() {} };
class CasNpcEditor       { public: virtual ~CasNpcEditor() {} };
class UILoader           { public: virtual ~UILoader() {} };

// StringBuffer utility namespace
namespace StringBuffer {
    inline void Copy(void* dst, const void* src) {}
}

// GameData namespace
namespace GameData {
    bool SaveCreateAFamily();
}

// Namespace for CAS globals
namespace Globs {
    extern unsigned int* pCASData;
}

// Global NPC slot data (accessed via r13-relative addressing)
extern u32 npcSlot1;
extern u32 npcSlot2;
extern u32 npcSlot3;

// CasSimDescriptionS2C - per-sim appearance descriptor
class CasSimDescriptionS2C {
public:
    short m_ageGender;              // 0x000
    unsigned char m_skinColorType;  // 0x002
    unsigned char m_unused_003;     // 0x003
    unsigned short m_bodyPartParam_004; // 0x004
    unsigned short m_unused_006;    // 0x006
    unsigned int  m_bodyPartParam_008; // 0x008
    unsigned int  m_bodyPartParam_00C; // 0x00C
    // 0x010-0x041: personality/interest data
    unsigned char m_personalityData[0x32]; // 0x010
    unsigned short m_personalityMarker;    // 0x042
    unsigned char m_interestData[0x3E];    // 0x044
    unsigned short m_interestMarker;       // 0x082
    // body type
    unsigned int   m_bodyType;          // 0x084
    unsigned char  m_bodyTypeMorphParam; // 0x088
    unsigned char  m_unused_089;        // 0x089
    // body part model/texture indices
    unsigned char m_headModelIdx;       // 0x08A
    unsigned char m_headTextureIdx;     // 0x08B
    unsigned char m_hairModelIdx;       // 0x08C
    unsigned char m_facialHairModelIdx; // 0x08D
    unsigned char m_facialHairTextureIdx; // 0x08E
    unsigned char m_unused_08F;         // 0x08F
    unsigned int  m_hairColor;          // 0x090
    unsigned int  m_hairHighlight;      // 0x094
    unsigned char m_eyeColorModelIdx;   // 0x098
    unsigned char m_eyeColorTextureIdx; // 0x099
    unsigned char m_unused_09A[2];      // 0x09A
    // Inner layer
    unsigned int  m_innerTorsoStyle;    // 0x09C
    unsigned int  m_innerSleeveStyle;   // 0x0A0
    unsigned char m_innerTorsoModelIdx; // 0x0A4
    unsigned char m_innerTorsoTextureIdx; // 0x0A5
    unsigned char m_unused_0A6[2];      // 0x0A6
    // Mid layer
    unsigned int  m_midTorsoStyle;      // 0x0A8
    unsigned int  m_midCollarStyle;     // 0x0AC
    unsigned int  m_midSleeveStyle;     // 0x0B0
    unsigned char m_midTorsoModelIdx;   // 0x0B4
    unsigned char m_midTorsoTextureIdx; // 0x0B5
    unsigned char m_unused_0B6[2];      // 0x0B6
    // Outer layer
    unsigned int  m_outerTorsoStyle;    // 0x0B8
    unsigned int  m_outerCollarStyle;   // 0x0BC
    unsigned int  m_outerSleeveStyle;   // 0x0C0
    unsigned char m_outerTorsoModelIdx; // 0x0C4
    unsigned char m_outerTorsoTextureIdx; // 0x0C5
    unsigned char m_unused_0C6[2];      // 0x0C6
    // Lower body
    unsigned int  m_lowerBodyStyle;     // 0x0C8
    unsigned char m_lowerBodyModelIdx;  // 0x0CC
    unsigned char m_lowerBodyTextureIdx; // 0x0CD
    unsigned char m_unused_0CE[2];      // 0x0CE
    unsigned int  m_bootTopDisplayed;   // 0x0D0
    unsigned char m_shoeModelIdx;       // 0x0D4
    unsigned char m_hatModelIdx;        // 0x0D5
    unsigned char m_hatTextureIdx;      // 0x0D6
    unsigned char m_unused_0D7;         // 0x0D7
    unsigned int  m_hatStyle;           // 0x0D8
    unsigned char m_glassesModelIdx;    // 0x0DC
    unsigned char m_glassesTextureIdx;  // 0x0DD
    unsigned char m_unused_0DE[2];      // 0x0DE
    unsigned int  m_field_0E0;          // 0x0E0
    unsigned int  m_field_0E4;          // 0x0E4
    unsigned char m_armAccessoryModelIdx;   // 0x0E8
    unsigned char m_armAccessoryTextureIdx; // 0x0E9
    unsigned char m_bootTopModelIdx;    // 0x0EA
    unsigned char m_bootTopTextureIdx;  // 0x0EB
    unsigned int  m_field_0EC;          // 0x0EC
    unsigned char m_tattooModelIdx;     // 0x0F0
    unsigned char m_tattooTextureIdx;   // 0x0F1
    unsigned char m_unused_0F2[6];      // 0x0F2
    // Morph values
    float m_morphNoseWidth;             // 0x0F8
    float m_morphNoseLength;            // 0x0FC
    float m_morphChinShape;             // 0x100
    float m_morphCheekWidth;            // 0x104
    float m_morphEyeSpacing;            // 0x108
    float m_morphEyeSize;               // 0x10C
    float m_morphLipWidth;              // 0x110
    float m_morphJawWidth;              // 0x114
    unsigned int m_field_118;           // 0x118

    void ClearSim(bool isFemale);
    void InitializeToDefaultCostume(bool isMale);
};

// eBodyPartS2C must be defined before CasSimPartsS2C uses it
enum eBodyPartS2C {
    kBodyPart_Head          = 0,
    kBodyPart_Hair          = 1,
    kBodyPart_FacialHair    = 2,
    kBodyPart_EyeColor      = 6,
    kBodyPart_Eyebrows      = 7,
    kBodyPart_Glasses       = 8,
    kBodyPart_InnerTorso    = 12,
    kBodyPart_InnerCollar   = 13,
    kBodyPart_InnerSleeve   = 14,
    kBodyPart_MidTorso      = 15,
    kBodyPart_MidCollar     = 16,
    kBodyPart_MidSleeve     = 17,
    kBodyPart_OuterTorso    = 18,
    kBodyPart_OuterCollar   = 19,
    kBodyPart_OuterSleeve   = 20,
    kBodyPart_LowerBody     = 21,
    kBodyPart_Shoes         = 22,
    kBodyPart_Hat           = 23,
    kBodyPart_ArmAccessory  = 24,
    kBodyPart_BootTop       = 25,
    kBodyPart_COUNT
};

// CasSimPartsS2C - static catalog of body parts
class CasSimPartsS2C {
public:
    void** _vtable;     // 0x000
    void*  m_partsData; // 0x004

    int  GetNumBodyModels(eBodyPartS2C part) const;
    void SetGender(bool isMale);
};

// CasGenetics - genetic blending system
class CasGenetics {
public:
    void BlendSimDescriptions(
        CasSimDescriptionS2C& parent1,
        CasSimDescriptionS2C& parent2,
        CasSimDescriptionS2C& output,
        bool isMale);
};

// CASGeneticsTarget - genetics screen controller
class CASGeneticsTarget {
public:
    void* m_parent1Texture;  // 0x414
    void* m_parent2Texture;  // 0x418
    static int s_GenerateState;
    void BeginGenerate();
    void SetGrandparentIndex(int slot, int idx);
};
int CASGeneticsTarget::s_GenerateState = 0;

// CASTarget - top-level CAS controller
class CASTarget {
public:
    int    m_casMode;           // 0x104
    int    m_hasSimBitmask;     // 0x1348
    void*  m_casScene;          // 0x1350
    CasNpcEditor* m_npcEditor;  // 0x1354
    CASGeneticsTarget* m_geneticsTarget;
    CASMorphTarget*    m_morphTarget;
    CASBodyTarget*     m_bodyTarget;
    CASSelectionTarget* m_selectionTarget;
    CASMiscTarget*     m_miscTarget;
    CASFashionTarget*  m_fashionTarget;
    CASPersonalTarget* m_personalTarget;
    CASTattooTarget*   m_tattooTarget;
    CASRoommateTarget* m_roommateTarget;
    UILoader*          m_loaderUI;
    void*              m_renderer;
    void*              m_lastName;      // 0x1430 wchar_t* last name

    int   GetCasMode() { return m_casMode; }
    void* ChangeMediator(int mode) { return NULL; }
    void  SaveSimToFamilySlot(int slotIndex);
    void  SaveCASDataToNeighborhood();
    void  Init(bool isNewSim);
};

// ============================================================================
// ENUMERATIONS (reconstructed from switch tables and comparison values)
// ============================================================================

// eBodyPartS2C is defined above (before CasSimPartsS2C)

/**
 * eSkinColorType -- Skin tone selections.
 * Used by CasSimPartsS2C::GetSkinTextureID and GetSkinTexturesDatasetID.
 */
enum eSkinColorType {
    kSkinColor_Light   = 0,
    kSkinColor_Medium  = 1,
    kSkinColor_Tan     = 2,
    kSkinColor_Dark    = 3,
    kSkinColor_VeryDark = 4,
    kSkinColor_Alien   = 5,
    kSkinColor_COUNT
};

/**
 * eBodyTypeS2C -- Body shape presets.
 * Controls morph target blend weights at offset 0x084 in CasSimDescriptionS2C.
 */
enum eBodyTypeS2C {
    kBodyType_Fit    = 0,
    kBodyType_Fat    = 1,
    kBodyType_Skinny = 2,
    kBodyType_COUNT
};

/**
 * eTattooTextureTypeS2C -- Tattoo overlay locations.
 */
enum eTattooTextureTypeS2C {
    kTattoo_LeftArm   = 0,
    kTattoo_RightArm  = 1,
    kTattoo_Back      = 2,
    kTattoo_Chest     = 3,
    kTattoo_COUNT
};

/**
 * Sim::MidLayerTorsoStyleS2C -- Mid-layer torso style variants.
 * These affect how the shirt is tucked and whether it hides the belt.
 */
namespace Sim {
    enum MidLayerTorsoStyleS2C {
        kMidTorso_FullTucked    = 0,
        kMidTorso_FullUntucked  = 1,
        kMidTorso_HalfTucked    = 2,
        kMidTorso_HalfUntucked  = 3,
        kMidTorso_COUNT
    };

    enum OuterLayerTorsoStyleS2C {
        kOuterTorso_Open  = 0,
        kOuterTorso_Closed = 1,
        kOuterTorso_Hood   = 2,
        kOuterTorso_COUNT
    };

    enum OuterLayerCollarStyleS2C {
        kOuterCollar_Normal = 0,
        kOuterCollar_Hood   = 1,
        kOuterCollar_COUNT
    };

    enum SleeveStyleS2C {
        kSleeve_Long      = 0,
        kSleeve_Short     = 1,
        kSleeve_Sleeveless = 2,
        kSleeve_COUNT
    };
}

// ============================================================================
// CasSimDescriptionS2C -- PER-SIM APPEARANCE DATA
// ============================================================================
//
// Size: 0x122 (290 bytes)
// Address of CasSimDescriptionS2C(void): 0x801672FC (52B)
// Address of CasSimDescriptionS2C(bool): 0x80167540 (112B)
//
// This struct holds all mutable per-sim appearance data. It is the canonical
// "what does this sim look like" descriptor. Every body part selection,
// texture index, morph value, and clothing layer choice lives here.
//
// ---- FIELD MAP (from assembly analysis of ClearSim + DoStream + Verify) ----
//
// 0x000  s16   m_ageGender           -- Age/gender packed field (-275 = default)
//                                       sign bit = gender (negative = female?)
// 0x002  u8    m_skinColorType       -- eSkinColorType index (default 2)
// 0x004  u16   m_bodyPartParam_004   -- Body part parameter (set by GetBodyPartParam)
// 0x008  u32   m_bodyPartParam_008   -- Extended param data
// 0x00C  u32   m_bodyPartParam_00C   -- Extended param data
// 0x010-0x041  -- Personality trait/interest data block
// 0x042  u16   m_personalityMarker   -- Personality validation marker
// 0x044-0x081  -- Additional trait data
// 0x082  u16   m_interestMarker      -- Interest data validation marker
//
// --- Body type morphing ---
// 0x084  u32   m_bodyType            -- eBodyTypeS2C enum (0=Fit, 1=Fat, 2=Skinny)
// 0x088  u8    m_bodyTypeMorphParam  -- Morph blend parameter
// 0x089  u8    m_unused_089          -- Cleared to 0
//
// --- Body part index/texture index pairs ---
// Each customizable body part has a (modelIndex, textureIndex) byte pair.
// The model index selects which 3D mesh, the texture index selects which
// skin/pattern to apply on that mesh.
//
// 0x08A  u8    m_headModelIdx
// 0x08B  u8    m_headTextureIdx
// 0x08C  u8    m_hairModelIdx
// 0x08D  u8    m_facialHairModelIdx
// 0x08E  u8    m_facialHairTextureIdx
//
// 0x090  u32   m_hairColor           -- Hair color packed value
// 0x093  u8    m_hairColorAlpha      -- (from DoStream)
// 0x094  u32   m_hairHighlight       -- Hair highlight/streak color
// 0x098  u8    m_eyeColorModelIdx
// 0x099  u8    m_eyeColorTextureIdx
//
// --- Clothing layers ---
// The Sims 2 GC uses a 3-layer clothing system:
//   Inner layer (undershirt), Mid layer (shirt), Outer layer (jacket).
// Each layer has torso, collar, and sleeve sub-parts.
//
// 0x09C  u32   m_innerTorsoStyle     -- Sim::InnerLayerTorsoStyle
// 0x0A0  u32   m_innerSleeveStyle    -- Sim::SleeveStyleS2C
// 0x0A4  u8    m_innerTorsoModelIdx
// 0x0A5  u8    m_innerTorsoTextureIdx
//
// 0x0A8  u32   m_midTorsoStyle       -- Sim::MidLayerTorsoStyleS2C
// 0x0AC  u32   m_midCollarStyle
// 0x0B0  u32   m_midSleeveStyle      -- Sim::SleeveStyleS2C
// 0x0B4  u8    m_midTorsoModelIdx
// 0x0B5  u8    m_midTorsoTextureIdx
//
// 0x0B8  u32   m_outerTorsoStyle     -- Sim::OuterLayerTorsoStyleS2C
// 0x0BC  u32   m_outerCollarStyle
// 0x0C0  u32   m_outerSleeveStyle
// 0x0C4  u8    m_outerTorsoModelIdx
// 0x0C5  u8    m_outerTorsoTextureIdx
//
// 0x0C8  u32   m_lowerBodyStyle
// 0x0CC  u8    m_lowerBodyModelIdx
// 0x0CD  u8    m_lowerBodyTextureIdx
// 0x0D0  u32   m_bootTopDisplayed    -- whether boot-top covers pants
// 0x0D4  u8    m_shoeModelIdx
// 0x0D5  u8    m_hatModelIdx
// 0x0D6  u8    m_hatTextureIdx
// 0x0D8  u32   m_hatStyle
// 0x0DC  u8    m_glassesModelIdx
// 0x0DD  u8    m_glassesTextureIdx
// 0x0E0  u32   m_field_0E0
// 0x0E4  u32   m_field_0E4
// 0x0E8  u8    m_armAccessoryModelIdx
// 0x0E9  u8    m_armAccessoryTextureIdx
// 0x0EA  u8    m_bootTopModelIdx
// 0x0EB  u8    m_bootTopTextureIdx
// 0x0EC  u32   m_field_0EC
// 0x0F0  u8    m_tattooModelIdx
// 0x0F1  u8    m_tattooTextureIdx
//
// --- Facial morph values ---
// These are float blend weights for the 3D head morph system.
// Range is typically 0.0 to 1.0. Set by CasSimDescriptionS2C(bool) ctor.
//
// 0x0F8  f32   m_morphNoseWidth      -- Nose width morph
// 0x0FC  f32   m_morphNoseLength     -- Nose length morph
// 0x100  f32   m_morphChinShape      -- Chin shape morph
// 0x104  f32   m_morphCheekWidth     -- Cheek width
// 0x108  f32   m_morphEyeSpacing     -- Eye spacing
// 0x10C  f32   m_morphEyeSize        -- Eye size
// 0x110  f32   m_morphLipWidth       -- Lip width
// 0x114  f32   m_morphJawWidth       -- Jaw width
//
// 0x118  u32   m_field_118           -- Cleared in ClearSim
// 0x121  u8    m_isCustomSim         -- Whether this is a user-created sim
//
// Static data:
//   CasSimDescriptionS2C::s_SkinColorNames at 0x803DFE65 (176B, .rodata)

// ============================================================================
// CasSimDescriptionS2C::ClearSim -- Reset sim to blank state
// ============================================================================
// Address: 0x80167330  Size: 528 bytes
//
// NON_MATCHING -- Decompiled from PPC assembly for documentation.
//
// Resets all body part indices, texture indices, clothing layers, and morph
// values to defaults. Called before InitializeToDefaultCostume and by
// CasGenetics::BlendSimDescriptions.
//
// When isFemale==false (0), also clears the morph values, personality data,
// and interest data to zero. When isFemale==true, clears fewer fields
// (presumably preserving some inherited genetics data).

void CasSimDescriptionS2C::ClearSim(bool isFemale) {
    // Set age/gender to default (-275 = 0xFEED, likely "unset" sentinel)
    m_ageGender = -275;  // sth r9, 0(r31) where r9=-275
    m_skinColorType = 2; // default medium skin

    // Clear facial hair texture to 0
    m_facialHairTextureIdx = 0;

    // Set all clothing layer styles to default value 3 (Sim::kStyle_Default?)
    m_outerSleeveStyle = 3;  // stw r8, 0xC0(r31)

    // Clear all body part model/texture index pairs to 0
    m_headModelIdx = 0;
    m_headTextureIdx = 0;
    m_facialHairModelIdx = 0;

    // Clear hair data
    m_hairColor = 0;
    m_hairHighlight = 0;
    m_eyeColorModelIdx = 0;
    m_eyeColorTextureIdx = 0;

    // Inner layer
    m_innerTorsoStyle = 0;
    m_innerSleeveStyle = 3; // default sleeve style
    m_innerTorsoModelIdx = 0;
    m_innerTorsoTextureIdx = 0;

    // Mid layer
    m_midTorsoStyle = 0;
    m_midCollarStyle = 0;
    m_midSleeveStyle = 3;
    m_midTorsoModelIdx = 0;
    m_midTorsoTextureIdx = 0;

    // Outer layer
    m_outerTorsoStyle = 0;
    m_outerCollarStyle = 0;
    m_outerTorsoModelIdx = 0;
    m_outerTorsoTextureIdx = 0;

    // Lower body
    m_lowerBodyStyle = 0;
    m_lowerBodyModelIdx = 0;
    m_lowerBodyTextureIdx = 0;
    m_bootTopDisplayed = 0;

    // Accessories
    m_shoeModelIdx = 0;
    m_hatModelIdx = 0;
    m_hatTextureIdx = 0;
    m_hatStyle = 0;
    m_glassesModelIdx = 0;
    m_glassesTextureIdx = 0;
    m_armAccessoryModelIdx = 0;
    m_armAccessoryTextureIdx = 0;
    m_bootTopModelIdx = 0;
    m_bootTopTextureIdx = 0;

    m_field_118 = 0;
    m_field_0E0 = 0;
    m_field_0E4 = 0;
    m_field_0EC = 0;
    m_tattooModelIdx = 0;
    m_tattooTextureIdx = 0;

    if (!isFemale) {
        // Male: also clear personality, morph data, and interests
        m_bodyType = 0;             // kBodyType_Fit
        m_bodyTypeMorphParam = 0;
        m_unused_089 = 0;
        m_hairModelIdx = 0;

        // Clear interest bytes at 0x0F2..0x0F4 (3 bytes via CTR loop)
        // for (int i = 0; i < 3; i++) { m_interests[i] = 0; }

        // Load default morph values from .sdata2 constants
        // All morph floats at 0x0F8..0x114 set to 0.5 (default center)
        m_morphNoseWidth = 0.5f;
        m_morphNoseLength = 0.5f;
        m_morphChinShape = 0.5f;
        m_morphCheekWidth = 0.5f;
        m_morphEyeSpacing = 0.5f;
        m_morphEyeSize = 0.5f;
        m_morphLipWidth = 0.5f;
        m_morphJawWidth = 0.5f;

        // Clear personality trait block (0x004..0x041)
        // ...memset-like clearing loop...

        // Clear interest block (0x044..0x081)
        // ...memset-like clearing loop...

        // Set validation markers
        m_personalityMarker = 0;  // at 0x042
        m_interestMarker = 0;     // at 0x082
    }
}

// ============================================================================
// CasSimDescriptionS2C::InitializeToDefaultCostume -- Set up default outfit
// ============================================================================
// Address: 0x8016A5F8  Size: 120 bytes
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Calls ClearSim(false) first, then sets gender-specific default clothing.
// Male and female defaults differ in their initial body part selections.

void CasSimDescriptionS2C::InitializeToDefaultCostume(bool isMale) {
    ClearSim(false);

    if (isMale) {
        // Male defaults:
        m_bodyType = 1;             // stw r9(1), 0x84(r31)
        m_eyeColorModelIdx = 3;     // stb r11(3), 0x98(r31)
        m_outerTorsoModelIdx = 8;   // stb r10(8), 0xC4(r31)
        m_lowerBodyModelIdx = 9;    // stb r0(9), 0xCC(r31)
    } else {
        // Female defaults:
        m_bodyType = 0;             // stw r30(0), 0x84(r31)
        m_outerTorsoModelIdx = 7;   // stb r0(7), 0xC4(r31)
        m_lowerBodyModelIdx = 4;    // stb r9(4), 0xCC(r31)
        m_eyeColorModelIdx = 4;     // stb r9(4), 0x98(r31)
    }
}

// ============================================================================
// CasSimPartsS2C -- STATIC BODY PARTS CATALOG
// ============================================================================
//
// Size: 0x10 (16 bytes) -- but mostly pointers to large data arrays
// Constructor: 0x8016A894 (100B)
// Destructor:  0x8016A8F8 (88B)
//
// CasSimPartsS2C is a catalog/database of all available body part models,
// textures, and their metadata. It's initialized once and queried by the
// CAS system when populating selection grids.
//
// Layout:
//   0x000  void**  _vtable
//   0x004  u32     m_partsData       -- Pointer to loaded SimParts data arrays
//                                       Contains vectors of model IDs per body part
//   0x008  u32     m_skinTextureData -- Skin texture dataset info
//   0x00C  u32     m_field_00C       -- Unknown
//
// The m_partsData pointer at offset 0x004 points to a structure containing:
//   +0x00  VECTOR<u32>  m_outerTorsoModels    (eBodyPart 17: GetNumBodyModels case)
//   +0x08  VECTOR<u32>  m_midTorsoModels      (eBodyPart 6-8)
//   +0x0C  VECTOR<u32>  m_innerTorsoModels    (eBodyPart 9-11)
//   +0x10  VECTOR<u32>  m_lowerBodyModels     (eBodyPart 12-13)
//   +0x14  VECTOR<u32>  m_miscModels_014      (eBodyPart 15-16)
//   +0x18  VECTOR<u32>  m_headModels          (eBodyPart 16)
//   +0x1C  VECTOR<u32>  m_hairModels          (eBodyPart 1)
//   +0x20  VECTOR<u32>  m_facialHairModels    (eBodyPart 2-5)
//   +0x24  VECTOR<u32>  m_hatModels           (eBodyPart 19)
//   +0x30  VECTOR<u32>  m_headTopModels       (eBodyPart 0)
//   +0x38  VECTOR<u32>  m_accessoryModels     (eBodyPart 20-25)
//
// Each VECTOR<u32> stores model resource IDs. The count is obtained via
// lwz r3, -4(r9) -- the vector stores its size at offset -4 from the
// data pointer (standard EA STL vector layout).
//
// Global state:
//   gSimPartsMapSizeMultiplier_CAS at 0x804FDB54 (2 bytes, .sdata)
//   -- Scales the sim parts data for CAS vs. in-game rendering

// ============================================================================
// CasSimPartsS2C::GetNumBodyModels -- Query model count for a body part
// ============================================================================
// Address: 0x8016A9FC  Size: 332 bytes
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Returns the number of available 3D models for the given body part enum.
// Uses a large switch statement to index into the correct data vector.

int CasSimPartsS2C::GetNumBodyModels(eBodyPartS2C part) const {
    // m_partsData is at this+0x004
    void* data = m_partsData;
    if (data == nullptr) {
        return 0;
    }

    // Switch on body part enum to select the correct vector
    // Each vector stores count at data[-1] (offset -4 from data pointer)
    u32* vectorData = nullptr;
    switch (part) {
        case 0:  // Head
            vectorData = *(u32**)((u8*)data + 0x30);
            break;
        case 1:  // Hair
            vectorData = *(u32**)((u8*)data + 0x1C);
            break;
        case 2:  // Facial hair (2-5 share same vector)
        case 3:
        case 4:
        case 5:
            vectorData = *(u32**)((u8*)data + 0x20);
            break;
        case 6:  // Eye color / eyebrows / glasses (6-8)
        case 7:
        case 8:
            vectorData = *(u32**)((u8*)data + 0x08);
            break;
        case 9:  // Body morph data vectors
        case 10:
        case 11:
            // Special: returns from offset +0x0C or +0x14
            // (uses two-step indirection)
            break;
        case 12: // Inner torso (12-13)
        case 13:
            vectorData = *(u32**)((u8*)data + 0x10);
            break;
        // ... additional cases for remaining body parts
        case 16: // Mid torso
            vectorData = *(u32**)((u8*)data + 0x18);
            break;
        case 17: // Outer torso
            vectorData = *(u32**)((u8*)data + 0x00);
            break;
        case 19: // Hat
            vectorData = *(u32**)((u8*)data + 0x24);
            break;
        case 20: // Arm accessory
            vectorData = *(u32**)((u8*)data + 0x38);
            break;
        case 21: // Lower body
            // (separate case)
            break;
        case 25: // Boot top
            // (separate case)
            break;
        default:
            return 0;
    }

    if (vectorData == nullptr) {
        return 0;
    }
    // EA STL vector stores count at pointer[-1] (4 bytes before data start)
    return vectorData[-1];
}

// ============================================================================
// CasSimPartsS2C::SetGender -- Switch parts catalog to male/female
// ============================================================================
// Address: 0x8016A950  Size: 172 bytes
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Reloads the sim parts data arrays for the specified gender.
// Sets the vtable pointer, then loads gender-specific model/texture lists
// into m_partsData. Called when switching between male and female Sims in CAS.

void CasSimPartsS2C::SetGender(bool isMale) {
    // Updates _vtable at offset 0x000
    // Reloads m_partsData (0x004) from gender-specific resource
    // Reloads m_skinTextureData (0x008)
    // The actual data comes from dataset resources loaded into memory
}

// ============================================================================
// CasGenetics -- GENETIC INHERITANCE SYSTEM
// ============================================================================
//
// Size: 0x88 (136 bytes)
// Constructor: 0x801604A8 (via CasGenetics at 0x80160100)
//
// CasGenetics handles the "Genetics" CAS screen where players select
// grandparents to produce blended offspring. It implements Mendelian-ish
// inheritance for body parts and uses random selection with bias for
// facial features.
//
// Layout:
//   0x000  void** _vtable
//   0x004  u32    m_grandparentListMale   -- pointer to male grandparent list
//   0x008  u32    m_field_008
//   0x00C  u32    m_field_00C
//   0x010  u32    m_malePortraitData
//   0x014  u32    m_femalePortraitData
//   0x018-0x083   Grandparent description storage
//   0x084  u32    m_hasCustomGrandparents
//
// Key functions:
//   BlendSimDescriptions    -- 0x801604A8 (492B)
//   BlendSkinColor          -- 0x80160694 (428B)
//   BlendBodyType           -- 0x80160838 (468B)
//   BlendMorphValues        -- 0x80160A0C (112B)
//   ChooseRandomBodyPart    -- 0x80160974 (1028B)
//   ChoosePersonalityTraits -- 0x80160900 (116B)

// Helper function stubs (actual implementations elsewhere or non-matching)
static void ChooseRandomBodyPart(int part, CasSimDescriptionS2C& output, int mutation) {
    (void)part; (void)output; (void)mutation;
}
static void ChoosePersonalityTraits(CasSimDescriptionS2C& output) {
    (void)output;
}

// ============================================================================
// CasGenetics::BlendSimDescriptions -- Create child from two parents
// ============================================================================
// Address: 0x801604A8  Size: 492 bytes
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// This is the core genetics function. Given two parent CasSimDescriptionS2C
// references and a boolean for gender, it produces a blended child description.
//
// The blending algorithm:
//   1. Clear the output description
//   2. Set output gender (m_bodyType = isMale parameter)
//   3. Blend skin color from both parents (BlendSkinColor)
//   4. Choose random body parts for each slot:
//      - Some parts (head, face) are 50/50 from either parent
//      - Hair uses 25% mutation chance
//      - Clothing defaults inherited from dominant parent
//   5. Blend morph values (facial features) via linear interpolation
//   6. Randomize personality traits (ChoosePersonalityTraits)

void CasGenetics::BlendSimDescriptions(
    CasSimDescriptionS2C& parent1,
    CasSimDescriptionS2C& parent2,
    CasSimDescriptionS2C& output,
    bool isMale)
{
    // Step 1: Clear output
    output.ClearSim(false);   // bl 0x80167330

    // Step 2: Set gender
    output.m_bodyType = isMale;  // stw r30, 0x84(r31)

    // Step 3: Blend skin color
    // lbz r4, 0x89(parent1)  -- get parent1 skin color
    // lbz r5, 0x89(parent2)  -- get parent2 skin color
    // extsb r4/r5            -- sign-extend
    // bl BlendSkinColor
    s8 skinColor = BlendSkinColor(parent1.m_skinColorType, parent2.m_skinColorType);
    output.m_skinColorType = skinColor;

    // If skin color == 5 (alien), set special flag
    if (skinColor == 5) {
        output.m_hairModelIdx = 1;  // stb at 0x8C -- alien marker
    }

    // Step 4: Choose random body parts
    // Each call to ChooseRandomBodyPart picks from parent1 or parent2
    // with a random chance, optionally with mutation probability.
    // The last parameter is the mutation percentage (0 = no mutation).
    ChooseRandomBodyPart(kBodyPart_FacialHair, output, 0);   // part 2, 0% mutation
    ChooseRandomBodyPart(kBodyPart_Eyebrows, output, 0);     // part 7
    ChooseRandomBodyPart(kBodyPart_MidTorso, output, 0);     // part 15
    ChooseRandomBodyPart(kBodyPart_MidCollar, output, 0);    // part 16
    ChooseRandomBodyPart(kBodyPart_OuterCollar, output, 25); // part 19, 25% mutation
    ChooseRandomBodyPart(kBodyPart_Head, output, 25);        // part 0, 25% mutation
    ChooseRandomBodyPart(kBodyPart_OuterTorso, output, 50);  // part 18, 50% mutation
    ChooseRandomBodyPart(kBodyPart_OuterSleeve, output, 25); // part 20
    ChooseRandomBodyPart(kBodyPart_LowerBody, output, 10);   // part 21, 10% mutation

    // Step 5: Blend body type
    // Uses random number: rand() % 3 determines which parent contributes more
    int r = rand();  // bl 0x800a64f8
    int choice = r / 3;  // divwu
    // Calls BlendBodyType with parent body types

    // Step 6: Blend morph values
    // For each morph float (nose width, chin shape, etc.),
    // linearly interpolate between parent1 and parent2 values
    // with a random blend factor.
    for (int i = 0; i < 8; i++) {
        float p1 = *((float*)&parent1 + 0x0F8/4 + i);
        float p2 = *((float*)&parent2 + 0x0F8/4 + i);
        float t = (float)(rand() % 100) / 100.0f;
        *((float*)&output + 0x0F8/4 + i) = p1 + (p2 - p1) * t;
    }

    // Step 7: Choose personality traits
    ChoosePersonalityTraits(output);
}

// ============================================================================
// CASGeneticsTarget::BeginGenerate -- Start genetic offspring generation
// ============================================================================
// Address: 0x8019828C  Size: 432 bytes
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Called when the player presses "Generate" on the genetics screen.
// Sets up the background generation state machine, randomizes grandparent
// indices for each parent slot, and kicks off the blend process.

void CASGeneticsTarget::BeginGenerate() {
    // Check if generation is already in progress
    // r0 = lwz r13-0x7AD0 (s_GenerateState)
    bool isGenerating = (s_GenerateState != 0);
    if (isGenerating) {
        return;
    }

    // Load UI event string for "generating" notification
    // "CASGenerate" string at lis r9, 0x803F / addi r9, -15588
    // Posts event to APT UI system

    // Check if both parent portraits are loaded
    // lwz r0, 0x414(this)  -- parent1 texture
    // lwz r0, 0x418(this)  -- parent2 texture
    if (m_parent1Texture && m_parent2Texture) {
        // Mark parent textures as "in use" by setting flag bits
        // ori r9, r9, 8  -- set bit 3 of texture flags
        // stw r0, 16(r11) -- store "generating" flag = 1
    }

    // Randomly select grandparent index for each parent (out of 26 options)
    // Three randomization rounds using rand() % 26:
    int idx0 = rand() % 26;
    SetGrandparentIndex(0, idx0);

    int idx1 = rand() % 26;
    SetGrandparentIndex(1, idx1);

    int idx2 = rand() % 26;
    SetGrandparentIndex(2, idx2);

    // Additional randomization for secondary traits
    int idx3 = rand() % 26;
    SetGrandparentIndex(3, idx3);

    // Set state to "generating" and trigger background task
    // BGCall_CASCGEGenerateStage will be called on next update
}

// ============================================================================
// CASTarget::SaveSimToFamilySlot -- Save edited sim to a family slot
// ============================================================================
// Address: 0x80192360  Size: 760 bytes
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Saves the current CAS sim data into the specified family slot (0-3).
// Updates the neighborhood data structure with the sim's appearance
// description, name, and family association.
//
// The function accesses the global CAS data structure (at r13-relative
// address 0x80475B84) which contains:
//   +0x078  pointer to neighborhood family data array
//   +0x620  hasSimInSlot flags (4 u32 entries, one per slot)

void CASTarget::SaveSimToFamilySlot(int slotIndex) {
    // Mark the slot as occupied
    // slwi r10, slotIndex, 2  (multiply by 4 for array index)
    // stwx r11(1), r9+r10     (store 1 into hasSimInSlot[slotIndex])
    u8* familyData = (u8*)Globs::pCASData;
    // hasSimInSlot array at +0x620, 4 bytes each
    *((u32*)(familyData + 0x620 + slotIndex * 4)) = 1;

    // If not in NPC edit mode (m_casMode at 0x104)
    if (m_casMode == 0) {
        // Copy first name and last name strings
        // mulli r29, slotIndex, 0x188  (392 bytes per family slot)
        // StringBuffer::Copy into slot's name fields
        int slotOffset = slotIndex * 392;
        (void)slotOffset;

        // Copy first name (32 wchar_t) to slot+0x18
        // Copy last name (32 wchar_t) to slot+0x58
        // Clear the "unused" flag at slot+0x56
    }

    // Copy the CasSimDescriptionS2C (288 bytes) into the family slot
    // mulli r11, slotIndex, 0x250  (592 bytes per sim render state)
    // The CasSimState at offset 0x108 + slotIndex*592 contains
    // the full sim description at +0x110 within CasSimState
    int srcOffset = slotIndex * 592;
    u8* src = (u8*)this + 0x108 + srcOffset + 0x010;
    int dstOffset = slotIndex * 392;
    // m_slotData pointer at +0x078 in familyData
    void* slotDataBase = *(void**)(familyData + 0x078);
    u8* dst = (u8*)slotDataBase + dstOffset + 0x14;

    // Block copy 288 bytes (sim description) in 24-byte chunks
    // This is an unrolled memcpy loop using lwz/stw pairs
    for (int i = 0; i < 288; i += 24) {
        // 6 lwz/stw pairs per iteration (24 bytes)
        (void)src; (void)dst;
    }
    // Final 4-byte copy for remainder

    // Check the CAS mediator mode (at renderer+0x2C)
    // If mode == 0 or mode == 3, copy additional data
    u32 mode = *(u32*)((u8*)this->m_renderer + 0x2C);
    if (mode == 0 || mode == 3) {
        // Copy personality data from the sim description
        // into the neighborhood family slot's personality fields
    }
}

// ============================================================================
// CASTarget::SaveCASDataToNeighborhood -- Finalize all CAS data
// ============================================================================
// Address: 0x80192658  Size: 468 bytes
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Called when the player exits CAS to save all edited sims to the
// neighborhood. Iterates over all 4 possible sim slots, saves occupied
// ones, and triggers the family creation/save flow.
//
// Flow:
//   1. Check if CAS mode is "create a family" (mode 5 exits early)
//   2. If CAS mode == 3 (Create-A-Family):
//      a. Loop over slots 0-3
//      b. For each slot with a sim (check bitmask at 0x1348):
//         - Call SaveSimToFamilySlot(slotIndex)
//      c. Track the first occupied slot (for family head)
//      d. Copy family name to neighborhood data
//      e. Call GameData::SaveCreateAFamily()
//   3. If GameData::SaveCreateAFamily succeeds:
//      a. Update the neighborhood's family list
//      b. Notify the lot system of the new family

void CASTarget::SaveCASDataToNeighborhood() {
    // Check if we're in "view-only" mode (mode 5, called "CAR" mode)
    int mode = GetCasMode();  // bl 0x80179AC8 with "mode" string
    if (mode == 5) {
        return;  // beq 0x80192814
    }

    // Only process if CAS mode is 3 (Create-A-Family)
    if (m_casMode != 3) {
        return;
    }

    u8* familyData = (u8*)Globs::pCASData;

    int firstSlot = 4;  // Track first occupied slot
    for (int i = 0; i <= 3; i++) {
        // Check if this slot has a sim
        // Extract bit from bitmask: (m_hasSimBitmask >> (i % 4)) & 1
        bool hasSimInSlot = (m_hasSimBitmask >> i) & 1;

        if (hasSimInSlot) {
            if (i < firstSlot) {
                firstSlot = i;
            }
            SaveSimToFamilySlot(i);
        } else {
            // Clear the hasSimInSlot flag for empty slots
            *((u32*)(familyData + 0x620 + i * 4)) = 0;
        }
    }

    if (firstSlot > 3) {
        return;  // No sims were saved
    }

    // Copy family name
    // If the family name string has length > 0, copy it to the
    // neighborhood's family record at familyData+0x650
    // m_lastName is a wchar_t* -- check if non-null as length proxy
    if (m_lastName != NULL) {
        StringBuffer::Copy(familyData + 0x650, m_lastName);
    } else {
        // Use the first sim's last name instead
        void* slotDataBase = *(void**)(familyData + 0x078);
        int nameOffset = firstSlot * 392;
        StringBuffer::Copy(familyData + 0x650,
                          (u8*)slotDataBase + nameOffset + 0x58);
    }

    // Save the family data
    // bl GameData::SaveCreateAFamily at 0x8003C728
    bool success = GameData::SaveCreateAFamily();
    if (!success) {
        return;
    }

    // Update neighborhood family relationships
    // Access global neighborhood pointer via r13
    // Neighborhood* ngh = *(Neighborhood**)(r13 - 0x53E4);
    // ngh->UpdateFamilyNumbers();
}

// ============================================================================
// CASTarget::Init -- Initialize the CAS system
// ============================================================================
// Address: 0x80191C94  Size: 1540 bytes
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Allocates and initializes all CAS sub-target objects, loads the UI,
// and sets up the 3D sim preview scene. Called once when entering CAS.
//
// Allocation sizes reveal the class sizes:
//   CASGeneticsTarget:   0x41C = 1052 bytes  (at 0x80191CE0)
//   CASMorphTarget:      0x1C4 = 452 bytes   (at 0x80191D10)
//   CASBodyTarget:       0x08C = 140 bytes   (at 0x80191D28)
//   CASSelectionTarget:  0x5DC = 1500 bytes  (at 0x80191D2C)
//   CASMiscTarget:       0x08C = 140 bytes   (at 0x80191D3C)
//   CASFashionTarget:    0x090 = 144 bytes   (at 0x80191D4C)
//   CASPersonalTarget:   0x094 = 148 bytes   (at 0x80191D5C)
//   CASTattooTarget:     0x1B0 = 432 bytes   (at 0x80191D6C)
//   CASRoommateTarget:   0x190 = 400 bytes   (at 0x80191D7C)
//   CasNpcEditor:        0x068 = 104 bytes   (at 0x80191DBC)
//   UILoader:            0x08C = 140 bytes   (at 0x80191DCC)

void CASTarget::Init(bool isNewSim) {
    // Load game state info
    // bl 0x800312C8 (EGlobal::GetGameState or similar)

    // If not creating a new sim, change mediator to current mode
    if (!isNewSim) {
        m_casScene = ChangeMediator(m_casMode);
    }

    // Allocate all sub-target objects via operator new + placement constructors
    m_geneticsTarget = new CASGeneticsTarget();     // 1052 bytes
    m_morphTarget = new CASMorphTarget();            // 452 bytes
    m_bodyTarget = new CASBodyTarget();              // 140 bytes
    m_selectionTarget = new CASSelectionTarget();    // 1500 bytes
    m_miscTarget = new CASMiscTarget();              // 140 bytes
    m_fashionTarget = new CASFashionTarget();        // 144 bytes
    m_personalTarget = new CASPersonalTarget();      // 148 bytes
    m_tattooTarget = new CASTattooTarget();           // 432 bytes
    m_roommateTarget = new CASRoommateTarget();      // 400 bytes

    // Conditionally create NPC editor if NPC data exists
    if (!isNewSim) {
        // Check 3 NPC data slots at global offset 0x80475DCC + 0x41C/0x420/0x424
        bool hasNpcData = (npcSlot1 != 0 || npcSlot2 != 0 || npcSlot3 != 0);
        if (hasNpcData) {
            m_npcEditor = new CasNpcEditor();  // 104 bytes
        }
    }

    // Create UI loader
    m_loaderUI = new UILoader();  // 140 bytes

    // Load the CAS UI layout from APT resource
    // String "CAS_Main" at 0x803FC0A4
    // bl EResourceManager::LoadResource

    // Load the 3D lot for the CAS scene background
    // String "CAS_Lot" at 0x803FC0B0
    // GetLotNumberFromMode determines which 3D lot to show

    // ... (remainder: register mediator listeners, initialize cam, etc.)
}

// ============================================================================
// CLOTHING LAYER SYSTEM
// ============================================================================
//
// The Sims 2 GC uses a three-layer clothing system unique to the console
// version. Each layer can be independently customized:
//
//   Layer 1 -- INNER (undershirt, tank top)
//     - Torso mesh + texture
//     - Sleeve style (long/short/sleeveless)
//     - Half-torso vs full-torso variant
//
//   Layer 2 -- MID (shirt, sweater)
//     - Torso mesh + texture
//     - Collar style (normal, v-neck, crew)
//     - Sleeve style
//     - Tucked/untucked variants (4 styles: full tucked, full untucked,
//       half tucked, half untucked)
//     - Can hide belt if torso covers waist area
//
//   Layer 3 -- OUTER (jacket, coat, hoodie)
//     - Torso mesh + texture
//     - Collar style (normal, hood up, hood down)
//     - Sleeve style
//     - Can be open or closed
//     - "Hood" variants that replace the collar with a hood mesh
//     - Can require full-torso mesh in mid layer
//     - Can hide music player accessory
//
// When switching between clothing items, the game cascades changes:
//   - Switching outer layer may force mid layer torso to full mesh
//   - Switching mid layer may force inner layer to half torso
//   - Boot-top display depends on lower body style
//   - Long sleeves can hide arm accessories
//
// Key functions controlling this cascade:
//   SwitchInnerLayerTorso(bool)                    -- 0x80169A40
//   SwitchMidLayerTorso(bool)                      -- 0x80169A5C
//   InnerLayerHalfTorsoRequired(CasSimPartsS2C&)   -- 0x80169B38
//   MidLayerHalfTorsoRequired(CasSimPartsS2C&)     -- 0x80169CB4
//   ShouldBootTopBeDisplayed(CasSimPartsS2C&)      -- 0x8016A460
//   OuterLayerTorsoIsAHood(u32, style)              -- 0x8016CE80
//   OuterLayerCollarIsAHood(u32, style)             -- 0x8016CDD8
//   MidLayerTorsoHidesBelt(u32, style, u32)         -- 0x8016CF78
//   OuterLayerTorsoHidesBelt(u32, style, u32)       -- 0x8016CFF8
//   LongSleeveDoesNotHideArmAccessory(part, u32)    -- 0x8016CD80

// ============================================================================
// CASTarget::ChangeMediator -- Switch between CAS editing modes
// ============================================================================
// Address: 0x80192DB8  Size: 804 bytes
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Transitions the CAS system between different editing contexts:
//   Mode 0: Create-A-Sim (single sim, normal flow)
//   Mode 1: In-game mirror editing
//   Mode 2: Genetics screen
//   Mode 3: Create-A-Family (multiple sims)
//   Mode 4: Roommate selection
//   Mode 5: View-only (Create-A-Room review)
//
// Each mode configures different sub-targets as active, changes the
// 3D scene/camera, and loads the appropriate UI layout.

// ============================================================================
// CasSimState -- PER-SIM EDITING STATE
// ============================================================================
//
// Size: 0x120 (288 bytes)
// Constructor from desc: 0x80172C78 (188B)
//
// Wraps a CasSimDescriptionS2C with navigation state for the CAS UI.
// Tracks which body part options are available (locked/unlocked),
// which adjacent styles exist for each part, and provides undo support.
//
// Key features:
//   - GetAdjacentIndex: Navigate to next/previous option for a body part
//     (3400 bytes of switch logic!)
//   - GetMoreThanOneOption: Check if scrolling is available
//   - HandleEventChangeSim: Process a body part change event from UI
//   - HandleEventMorphSim: Process facial morph slider changes
//   - HandleEventStoreSim: Save current state for undo
//
// The state tracks model and texture indices for every body part plus
// the full morph parameter set (8 floats for facial features).

// ============================================================================
// CasCostumes -- SAVED COSTUME PRESETS
// ============================================================================
//
// Size: 0x0C (12 bytes)
// Constructor: 0x804223B8 (via constructor at 0x80422338)
//
// Manages saved costume presets that persist across CAS sessions.
// Costumes are stored in the neighborhood save file and loaded at CAS init.
//
// Methods:
//   LoadCostumesList    -- Load from NghResFile
//   SaveCostumesList    -- Save to NghResFile
//   CreateNewCostumesList -- Initialize empty costume list
//   GetSimDescription   -- Get description by name or index
//   UpdateSimDescription -- Update a saved costume with new description
//   CompareSimDescription -- Check if two descriptions match

// ============================================================================
// SetupCAS -- Global CAS initialization
// ============================================================================
// Address: 0x801C6FC4  Size: 300 bytes
//
// Called during game startup to register CAS-related UI targets with the
// APT (ActionScript for Flash UI) system. Registers GetVariable, SetVariable,
// GetLocalizable, Update, and Draw callbacks for CASTarget and all sub-targets.

// ============================================================================
// CASPersonalTarget -- PERSONALITY AND ASPIRATION
// ============================================================================
//
// Size: 0x094 (148 bytes)
// Constructor: 0x8019D518 (2736B -- huge due to inline string tables)
//
// Manages the personality screen where players assign:
//   - Zodiac sign (Aries through Pisces)
//   - 5 personality trait sliders (Neat/Sloppy, Outgoing/Shy, etc.)
//   - Aspiration type
//
// The constructor at 0x8019D518 is notably large (2736 bytes) because it
// inlines static lookup tables for zodiac sign names, personality trait
// names, and aspiration descriptions.
//
// Key methods:
//   ParseSignText(short, wchar_t*)        -- Get zodiac sign display text
//   ParseDescriptionText(short, wchar_t*) -- Get aspiration description text
//   ParsePersonalityText(char*, wchar_t*) -- Get personality slider label
//   CalcHighScoreAspShaderIds()           -- Compute UI shader IDs for
//                                            aspiration score display
//
// Static data:
//   CASPersonalTarget::m_highScoreAspShaderIds at 0x804FC080 (100B, .bss)

// ============================================================================
// SKIN COMPOSITING
// ============================================================================
//
// The sim's visible skin texture is composited from multiple layers:
//   1. Base skin color texture (from GetSkinTextureID)
//   2. Tattoo overlays (from GetTattooTextureID)
//   3. Clothing textures per body part (from GetTextureID)
//
// CasSimPartsS2C::GetTextureID is the largest single function in the parts
// system at 3868 bytes (0x8016B910). It handles all body part types with
// a massive switch statement that accounts for gender, style variants,
// and GC-specific texture overrides (IsGamecubeOnly).
//
// The skin compositor (SkinCompositor class) takes these texture IDs and
// composites them into a single render target per body quadrant. This is
// done at two quality levels:
//   CreateSkinQuadrantHiRes -- Full-res for close-up CAS view
//   CreateSkinQuadrantLoRes -- Reduced-res for gameplay

// ============================================================================
// WELD SYSTEM
// ============================================================================
//
// Since body parts are separate meshes, they must be "welded" at boundaries
// to prevent seams. CasSimPartsS2C::GetWeldableBodyPartConnections
// (0x8016D560, 464B) returns the list of adjacent body parts that need
// welding for a given part.
//
// SimModel::UpdateReweldCAS (0x80072D3C, 88B) triggers re-welding when
// body parts change during CAS editing.

// ============================================================================
// UNLOCK SYSTEM
// ============================================================================
//
// Not all body parts/textures are available from the start. Many are locked
// behind gameplay progression. CasSimPartsS2C::GetUnlockGroupNum
// (0x8016D078, 540B for body parts; 0x8016D294, 244B for tattoos)
// returns the unlock group that must be completed to use a given item.
//
// CASSelectionTarget::GetLockStateString queries unlock state to show
// lock/unlock icons on the selection grid.
//
// CASSelectionTarget::ClearRecentlyUnlockedBitFlag clears the "new!" flag
// after the player has seen a newly unlocked item.
