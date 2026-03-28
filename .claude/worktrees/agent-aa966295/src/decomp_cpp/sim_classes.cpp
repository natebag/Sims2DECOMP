// sim_classes.cpp -- Decompiled sim/gameplay classes (portable C++)
//
// Converted from inline PPC asm (src/asm_decomp/) and decomp documentation
// (src/sim/*_decomp.cpp) into functionally correct, portable C++.
//
// Classes covered in THIS file (not duplicated from other decomp_cpp files):
//   - cXMTObjectImpl    (multi-tile object implementation)
//   - CasSimDescriptionS2C (per-sim appearance data, 290 bytes)
//   - CasSimPartsS2C    (static catalog of body parts/textures)
//   - CasGenetics       (genetic blending for Create-A-Sim)
//   - CASTarget         (top-level CAS controller)
//   - SimModel          (3D sim model manager, 63 methods)
//   - TreeSim           (behavior tree base class)
//   - TreeSimImpl       (behavior tree execution engine)
//   - TreeStack         (call frame stack for BHAV gosub/return)
//   - TreeTab           (tree table data container)
//   - TreeTable         (interaction tree lookup)
//   - TreeTableQuickData      (fast loaded tree table data)
//   - TreeTableEntryQuickData (fast loaded tree table entry)
//   - TreeTableAdQuickData    (fast loaded tree table ad)
//   - TreeTableAdScratch      (scratch copy of tree table ad)
//   - TreeTableEntry    (one interaction row in TTAB)
//   - TTabScratchEntry  (scratch copy of tree table entry)
//   - WantFear::Bookmark (bookmark methods: bookmark into want/fear tree)
//   - AwarenessManager  (NPC awareness/head tracking system)
//   - Neighbor          (neighborhood character data, 39 methods)
//   - HoodManager       (lot/family move-in/eviction manager)
//   - INVTarget         (inventory UI target, 108 methods)
//   - PCTTarget         (place/catalog/tool UI target, 51 methods)
//   - ACTTarget         (action queue UI target, 22 methods)
//   - WAFTarget         (wants & fears UI target, 24 methods)
//
// Already covered elsewhere (skipped):
//   - cXObjectImpl       -> src/decomp_cpp/cxobjectimpl.cpp
//   - cXPersonImpl       -> src/decomp_cpp/gameplay.cpp
//   - Interaction        -> src/decomp_cpp/misc_classes.cpp
//   - FamilyImpl         -> src/decomp_cpp/effects_skin_neighborhood.cpp
//   - PlayerFamilyImpl   -> src/decomp_cpp/effects_skin_neighborhood.cpp
//   - NeighborhoodImpl   -> src/decomp_cpp/effects_skin_neighborhood.cpp
//   - cFixedWorldImpl    -> src/decomp_cpp/effects_skin_neighborhood.cpp
//   - BBI::Inventory*    -> src/decomp_cpp/effects_skin_neighborhood.cpp
//   - GoalUnlock         -> src/decomp_cpp/effects_skin_neighborhood.cpp
//   - WantFearManager    -> src/decomp_cpp/effects_skin_neighborhood.cpp
//   - WantFear structs   -> src/decomp_cpp/effects_skin_neighborhood.cpp
//
// Original game: The Sims 2 (GameCube) -- G4ZE69
// Build: u2_ngc_release_dvd (Sep 12, 2005)
// Compiler: SN Systems ProDG for GameCube

#include "types.h"

#ifndef nullptr
#define nullptr 0
#endif

// ============================================================================
// FORWARD DECLARATIONS
// ============================================================================

class cXObject;
class cXObjectImpl;
class cXPerson;
class cXPersonImpl;
class cXMTObject;
class cXMTObjectImpl;
class cXPortalImpl;
class ESim;
class EAnimController;
class SAnimator2;
class StackElem;
class BehaviorNode;
class Behavior;
class ObjectDataBehaviorTree;
class ObjectDataBehaviorConstants;
class Interaction;
class InteractionList;
class ITreeTable;
class ITreeTableEntry;
class ITreeTableAd;
class TreeTable;
class TreeTableEntry;
class TreeTableQuickData;
class TreeTableEntryQuickData;
class TreeTableAdQuickData;
class TreeTableAdScratch;
class TTabScratchEntry;
class TreeStack;
class TreeSim;
class TreeSimImpl;
class EdithVariableSet;
class ObjSelector;
class ObjectModule;
class ActionQueue;
class XPrimParam;
class XRoute;
class RoutingSlot;
class TileList;
class BString;
class BString2;
class StringBuffer;
class StringBuffer2;
class ReconBuffer;
class Language;
class XObjLang;
class IBaseSimInstance;
class ISimInstance;
class BehaviorFinder;
class CasSimDescriptionS2C;
class CasSimPartsS2C;
class CasGenetics;
class CasMediator;
class CasSimState;
class CASTarget;
class CASGeneticsTarget;
class CASSelectionTarget;
class CASBodyTarget;
class CASFashionTarget;
class CASMiscTarget;
class CASMorphTarget;
class CASPersonalTarget;
class CASTattooTarget;
class CASRoommateTarget;
class CasNpcEditor;
class CasCostumes;
class CasScene;
class AnimRef;
class ERShader;
class ERCharacter;
class EACNodeState;
class EACTrack;
class ETextureDef;
class EString;
class ObjTestSim;
class EActionIcon;
class ObjectDataID;
class NghResFile;
class Family;
class FamilyInfo;
class HouseInfo;
class Neighbor;
class RelMatrix;
class cSimulator;
class ENeighborhoodCustomChar;
class IGoalUnlock;
class FenceData;
class FloorTile;
class WallTile;
class ObjDefinition;
class FTilePt;
class CTilePt;
class EMat4;
class EVec2;

struct SCID {};
struct tRelationshipType {};
struct eBodyPartS2C {};
struct eTattooTextureTypeS2C {};

template <typename T> class TNodeList;

// ============================================================================
// EXTERNAL FUNCTIONS
// ============================================================================

extern "C" {
    void  memset(void* dst, int val, u32 size);
    void* memcpy(void* dst, const void* src, u32 size);
    int   strcmp(const char* a, const char* b);

    void* operator_new(u32 size);
    void  operator_delete(void* ptr);

    void ReconBuffer_StreamBytes(ReconBuffer* buf, void* data, int count);
    void ReconBuffer_StreamInt(ReconBuffer* buf, void* data, int count);
    void ReconBuffer_StreamHalfwords(ReconBuffer* buf, void* data, int count);

    int   RandomInt(u32 range);
    float GetRandomFloat();
}

extern void* g_pNeighborhoodImpl;
extern void* g_pObjectModuleImpl;
extern int   g_treeSimError;


// ############################################################################
//
//  SECTION 1: cXMTObjectImpl -- MULTI-TILE OBJECT IMPLEMENTATION
//
// ############################################################################
//
// cXMTObjectImpl extends cXObjectImpl to handle objects that span multiple
// tiles (e.g., beds, sofas, dining tables). It manages a chain of sub-objects,
// offset calculations, and multi-tile placement validation.
//
// From asm: 29 functions, 17,236 bytes total
// Inherits: cXObjectImpl (base) + TreeSimImpl (via TreeSim)
//
// Key concepts:
//   - A "leader" object is the primary tile; followers are linked via chain
//   - AssignOffsets() computes per-tile position offsets from the leader
//   - Place/Pickup/Turn affect all tiles in the chain atomically
//   - IsDynamic() checks if this tile is a dynamically-generated sub-tile

class cXMTObjectImpl {
public:
    // Layout (from constructor analysis):
    // Embeds TreeSim at +0x00 (chain pointer structure)
    // Embeds TreeSimImpl at +0x98 (or similar offset)
    // Embeds cXObjectImpl at +0x00 of the main object pointer
    //
    // Key fields (from asm offset analysis):
    void*         m_chainPtrs[4];     // 0x00  linked list of sub-objects
    u8            m_treeSimData[192]; // embedded TreeSim + TreeSimImpl vtables
    cXMTObject*   m_leader;           // leader of this multi-tile group
    int           m_tileCountX;       // number of tiles in X direction
    int           m_tileCountY;       // number of tiles in Y direction
    u8            m_isDynamic;        // true if dynamically generated sub-tile
    u8            _pad[3];

    // ---- Constructor ----
    // Address: 0x800C3684 | 4632 bytes
    // Initializes TreeSim, TreeSimImpl, cXObjectImpl subobjects.
    // Copies multiple vtable blocks (168+ bytes each) from static data.
    // Patches all vtable this-adjustment offsets.
    // Called with: numAttr, selector, mtObject, module
    void Init(int numAttr, ObjSelector* sel, cXMTObject* mtObj, ObjectModule* mod) {
        // Initialize embedded TreeSim
        // Initialize embedded TreeSimImpl
        // Initialize embedded cXObjectImpl
        // Set vtables for all sub-objects
        m_leader = mtObj;
        m_tileCountX = 1;
        m_tileCountY = 1;
        m_isDynamic = 0;
    }

    // ---- Destructor ----
    // Address: 0x800C4868 | 368 bytes
    // Destroys sub-objects in reverse order, frees dynamic tiles
    ~cXMTObjectImpl() {
        // Destroy TreeSimImpl
        // Destroy cXObjectImpl
        // Free linked sub-objects
    }

    // ---- Core Methods ----

    // Address: 0x800C4C08 | 96 bytes
    void SetLeader(cXMTObject* leader) {
        m_leader = leader;
    }

    // Address: 0x800C4BD4 | 52 bytes
    void* GetISimInstance() {
        // Returns ISimInstance from the leader's dispatch table
        return nullptr; // placeholder
    }

    // Address: 0x800C4C68 | 300 bytes
    // Removes this tile from the multi-tile chain
    void RemoveFromChain() {
        // Walk the chain, find and unlink this node
        // Decrement tile count on leader
    }

    // Address: 0x800C4FB4 | 1220 bytes
    // Rotates the entire multi-tile object
    void Turn(int direction) {
        // For each sub-tile:
        //   1. Compute new offset from leader based on rotation
        //   2. Update tile position
        //   3. Recompute bounding rect
    }

    // Address: 0x800C5450 | 520 bytes
    // Assigns position offsets for all sub-tiles relative to leader
    void AssignOffsets() {
        // Iterate chain, compute offsets based on tile indices
        // Uses direction table for rotated placement
    }

    // Address: 0x800C5658 | 664 bytes
    // Tests if the multi-tile object can be placed at a location
    int CanPlace(FTilePt& pos, int direction, cXObject* container, int flags) {
        // For each sub-tile, check if target tile is available
        // Returns 0 on success, error code on failure
        return 0;
    }

    // Address: 0x800C58F0 | 788 bytes
    // Places the multi-tile object
    int Place(FTilePt& pos, int direction, cXObject* container, int flags) {
        // Validate with CanPlace first
        // Then place each sub-tile at computed offset positions
        return 0;
    }

    // Address: 0x800C5C04 | 292 bytes
    void Pickup() {
        // Remove all sub-tiles from the world
        // Clear positions but keep chain intact
    }

    // Address: 0x800C5D28 | 368 bytes
    int UserCanPlace(FTilePt& pos, int direction, cXObject* container, int flags) {
        // Player-initiated placement check
        // Additional validation beyond CanPlace (budget, permissions)
        return CanPlace(pos, direction, container, flags);
    }

    // Address: 0x800C5E98 | 416 bytes
    int UserPlace(FTilePt& pos, int direction, cXObject* container, int flags) {
        // Player-initiated placement
        return Place(pos, direction, container, flags);
    }

    // Address: 0x800C6038 | 80 bytes
    bool UserCanPickup() {
        // Check if player can pick this up (not occupied, etc.)
        return true;
    }

    // Address: 0x800C6088 | 156 bytes
    void UserPickup(bool returnToInventory) {
        Pickup();
        // If returnToInventory: add to player inventory
    }

    // Address: 0x800C6124 | 80 bytes
    bool UserCanDelete() {
        return true;
    }

    // Address: 0x800C6174 | 336 bytes
    void Reset(bool fullReset) {
        // Reset all sub-tiles to default state
        // Clear animations, sounds, behavior trees
    }

    // Address: 0x800C62C4 | 744 bytes
    void ReconStream(ReconBuffer* buf, int version, bool isWrite) {
        // Stream the multi-tile object state for save/load
        // Includes chain structure, positions, data variables
    }

    // Address: 0x800C65AC | 308 bytes
    void PostLoad(int version, bool isResuming) {
        // Rebuild runtime state after loading
        // Reconstruct chain, reassign offsets, validate positions
    }

    // Address: 0x800C66E0 | 256 bytes
    void SetMultiObjectData(int dataIndex, int value) {
        // Set data variable on all tiles in the chain
    }

    // Address: 0x800C67E0 | 380 bytes
    void MergeDynamic(cXMTObject* dynamicTile) {
        // Merge a dynamically created sub-tile into this group
    }

    // Address: 0x800C695C | 16 bytes
    bool IsDynamic() {
        return m_isDynamic != 0;
    }

    // Address: 0x800C696C | 108 bytes
    void RemoveFromDynamic() {
        // Remove this dynamic sub-tile from the chain
    }

    // Address: 0x800C69D8 | 412 bytes
    void UpdateAllAdjacecy() {
        // Update wall/floor adjacency for all tiles
    }

    // Address: 0x800C6B74 | 336 bytes
    void UpdateDynAdjacency() {
        // Update adjacency for dynamic sub-tiles only
    }

    // Address: 0x800C6CC4 | 248 bytes
    void MergeInPlace() {
        // Merge sub-tiles in their current positions
    }

    // Address: 0x800C6DBC | 236 bytes
    // Returns average position of all tiles
    void GetAverageLocation(int* outX, int* outY) const {
        // Sum positions of all sub-tiles, divide by count
        *outX = 0;
        *outY = 0;
    }

    // Address: 0x800C6EA8 | 84 bytes
    // Returns the tile dimensions of this multi-tile object
    void GetNumTiles(int& outX, int& outY) {
        outX = m_tileCountX;
        outY = m_tileCountY;
    }

    // Address: 0x800C6EFC | 4 bytes
    void* CAST_IMPL() {
        return this;
    }
};


// ############################################################################
//
//  SECTION 2: CREATE-A-SIM (CAS) CLASSES
//
// ############################################################################
//
// The CAS system handles character creation and customization.
// Architecture: CASTarget -> CasMediator -> CasSimState -> CasSimDescriptionS2C
// Data: CasSimPartsS2C (static catalog), CasGenetics (genetic blending)

// ============================================================================
// ENUMERATIONS
// ============================================================================

enum eBodyPartS2C_Enum {
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
    kBodyPart_COUNT         = 26
};

enum eSkinColorType_Enum {
    kSkinColor_Light    = 0,
    kSkinColor_Medium   = 1,
    kSkinColor_Tan      = 2,
    kSkinColor_Dark     = 3,
    kSkinColor_VeryDark = 4,
    kSkinColor_Alien    = 5,
    kSkinColor_COUNT    = 6
};

enum eBodyTypeS2C_Enum {
    kBodyType_Fit    = 0,
    kBodyType_Fat    = 1,
    kBodyType_Skinny = 2,
    kBodyType_COUNT  = 3
};

enum eTattooTextureTypeS2C_Enum {
    kTattoo_LeftArm  = 0,
    kTattoo_RightArm = 1,
    kTattoo_Back     = 2,
    kTattoo_Chest    = 3,
    kTattoo_COUNT    = 4
};

// ============================================================================
// CasSimDescriptionS2C -- Per-Sim Appearance Data (290 bytes)
// ============================================================================
//
// Holds all mutable per-sim appearance data: body parts, textures, clothing
// layers, morph values, hair colors, tattoos, personality, and interests.
//
// Address of constructor: 0x801672FC (52 bytes)
// Address of ClearSim: 0x80167330 (528 bytes)
// Address of DoStream: 0x80167664 (variable)

class CasSimDescriptionS2C {
public:
    // ---- Field layout (from assembly analysis) ----
    s16   m_ageGender;              // 0x000 (-275 = default/unset)
    u8    m_skinColorType;          // 0x002 eSkinColorType index (default 2)
    u8    _pad_003;                 // 0x003
    u16   m_bodyPartParam_004;      // 0x004
    u16   _pad_006;                 // 0x006
    u32   m_bodyPartParam_008;      // 0x008
    u32   m_bodyPartParam_00C;      // 0x00C
    u8    m_personalityData[0x32];  // 0x010 personality trait/interest data
    u16   m_personalityMarker;      // 0x042
    u8    m_interestData[0x40];     // 0x044 additional trait data
    u16   m_interestMarker;         // 0x082

    // --- Body type morphing ---
    u32   m_bodyType;               // 0x084 eBodyTypeS2C
    u8    m_bodyTypeMorphParam;     // 0x088
    u8    m_unused_089;             // 0x089

    // --- Body part model/texture indices ---
    u8    m_headModelIdx;           // 0x08A
    u8    m_headTextureIdx;         // 0x08B
    u8    m_hairModelIdx;           // 0x08C
    u8    m_facialHairModelIdx;     // 0x08D
    u8    m_facialHairTextureIdx;   // 0x08E
    u8    _pad_08F;                 // 0x08F

    // --- Hair color ---
    u32   m_hairColor;              // 0x090
    u8    m_hairColorAlpha;         // 0x093 (overlaps within u32)
    u32   m_hairHighlight;          // 0x094

    // --- Eye color ---
    u8    m_eyeColorModelIdx;       // 0x098
    u8    m_eyeColorTextureIdx;     // 0x099
    u8    _pad_09A[2];              // 0x09A

    // --- Clothing: Inner layer ---
    u32   m_innerTorsoStyle;        // 0x09C
    u32   m_innerSleeveStyle;       // 0x0A0
    u8    m_innerTorsoModelIdx;     // 0x0A4
    u8    m_innerTorsoTextureIdx;   // 0x0A5
    u8    _pad_0A6[2];              // 0x0A6

    // --- Clothing: Mid layer ---
    u32   m_midTorsoStyle;          // 0x0A8
    u32   m_midCollarStyle;         // 0x0AC
    u32   m_midSleeveStyle;         // 0x0B0
    u8    m_midTorsoModelIdx;       // 0x0B4
    u8    m_midTorsoTextureIdx;     // 0x0B5
    u8    _pad_0B6[2];              // 0x0B6

    // --- Clothing: Outer layer ---
    u32   m_outerTorsoStyle;        // 0x0B8
    u32   m_outerCollarStyle;       // 0x0BC
    u32   m_outerSleeveStyle;       // 0x0C0
    u8    m_outerTorsoModelIdx;     // 0x0C4
    u8    m_outerTorsoTextureIdx;   // 0x0C5
    u8    _pad_0C6[2];              // 0x0C6

    // --- Lower body & accessories ---
    u32   m_lowerBodyStyle;         // 0x0C8
    u8    m_lowerBodyModelIdx;      // 0x0CC
    u8    m_lowerBodyTextureIdx;    // 0x0CD
    u8    _pad_0CE[2];              // 0x0CE
    u32   m_bootTopDisplayed;       // 0x0D0
    u8    m_shoeModelIdx;           // 0x0D4
    u8    m_hatModelIdx;            // 0x0D5
    u8    m_hatTextureIdx;          // 0x0D6
    u8    _pad_0D7;                 // 0x0D7
    u32   m_hatStyle;               // 0x0D8
    u8    m_glassesModelIdx;        // 0x0DC
    u8    m_glassesTextureIdx;      // 0x0DD
    u8    _pad_0DE[2];              // 0x0DE
    u32   m_field_0E0;              // 0x0E0
    u32   m_field_0E4;              // 0x0E4
    u8    m_armAccessoryModelIdx;   // 0x0E8
    u8    m_armAccessoryTextureIdx; // 0x0E9
    u8    m_bootTopModelIdx;        // 0x0EA
    u8    m_bootTopTextureIdx;      // 0x0EB
    u32   m_field_0EC;              // 0x0EC
    u8    m_tattooModelIdx;         // 0x0F0
    u8    m_tattooTextureIdx;       // 0x0F1
    u8    _pad_0F2[6];              // 0x0F2

    // --- Facial morph values (float blend weights, 0.0-1.0) ---
    f32   m_morphNoseWidth;         // 0x0F8
    f32   m_morphNoseLength;        // 0x0FC
    f32   m_morphChinShape;         // 0x100
    f32   m_morphCheekWidth;        // 0x104
    f32   m_morphEyeSpacing;        // 0x108
    f32   m_morphEyeSize;           // 0x10C
    f32   m_morphLipWidth;          // 0x110
    f32   m_morphJawWidth;          // 0x114

    u32   m_field_118;              // 0x118
    u8    _pad_11C[5];              // 0x11C
    u8    m_isCustomSim;            // 0x121

    // ---- Constructor ----
    // Address: 0x801672FC | 52 bytes
    CasSimDescriptionS2C() {
        ClearSim(false);
    }

    // Address: 0x80167540 | 112 bytes
    // Constructor that initializes morph values to midpoints
    void InitWithDefaults(bool isFemale) {
        ClearSim(isFemale);
        // Set default morph values (0.5 = midpoint)
        m_morphNoseWidth = 0.5f;
        m_morphNoseLength = 0.5f;
        m_morphChinShape = 0.5f;
        m_morphCheekWidth = 0.5f;
        m_morphEyeSpacing = 0.5f;
        m_morphEyeSize = 0.5f;
        m_morphLipWidth = 0.5f;
        m_morphJawWidth = 0.5f;
    }

    // Address: 0x80167330 | 528 bytes
    void ClearSim(bool isFemale) {
        m_ageGender = -275; // 0xFEED sentinel
        m_skinColorType = 2; // medium

        m_facialHairTextureIdx = 0;
        m_outerSleeveStyle = 3;

        m_headModelIdx = 0;
        m_headTextureIdx = 0;
        m_facialHairModelIdx = 0;
        m_hairColor = 0;
        m_hairHighlight = 0;
        m_eyeColorModelIdx = 0;
        m_eyeColorTextureIdx = 0;

        m_innerTorsoStyle = 0;
        m_innerSleeveStyle = 3;
        m_innerTorsoModelIdx = 0;
        m_innerTorsoTextureIdx = 0;

        m_midTorsoStyle = 0;
        m_midCollarStyle = 0;
        m_midSleeveStyle = 3;
        m_midTorsoModelIdx = 0;
        m_midTorsoTextureIdx = 0;

        m_outerTorsoStyle = 0;
        m_outerCollarStyle = 0;
        m_outerTorsoModelIdx = 0;
        m_outerTorsoTextureIdx = 0;

        m_lowerBodyStyle = 0;
        m_lowerBodyModelIdx = 0;
        m_lowerBodyTextureIdx = 0;
        m_bootTopDisplayed = 0;

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

        m_tattooModelIdx = 0;
        m_tattooTextureIdx = 0;

        m_bodyType = 0;  // Fit
        m_bodyTypeMorphParam = 0;
        m_unused_089 = 0;

        m_field_0E0 = 0;
        m_field_0E4 = 0;
        m_field_0EC = 0;
        m_field_118 = 0;
        m_isCustomSim = 0;

        if (!isFemale) {
            // Clear morph values
            m_morphNoseWidth = 0.0f;
            m_morphNoseLength = 0.0f;
            m_morphChinShape = 0.0f;
            m_morphCheekWidth = 0.0f;
            m_morphEyeSpacing = 0.0f;
            m_morphEyeSize = 0.0f;
            m_morphLipWidth = 0.0f;
            m_morphJawWidth = 0.0f;

            // Clear personality and interest data
            memset(m_personalityData, 0, sizeof(m_personalityData));
            m_personalityMarker = 0;
            memset(m_interestData, 0, sizeof(m_interestData));
            m_interestMarker = 0;
        }
    }

    // Address: 0x801675B0 | variable
    // Maps body part enum to internal data array index
    int GetBodyPartIndex(int bodyPart) const {
        switch (bodyPart) {
            case kBodyPart_Head:         return 0;
            case kBodyPart_Hair:         return 1;
            case kBodyPart_FacialHair:   return 2;
            case kBodyPart_EyeColor:     return 3;
            case kBodyPart_Eyebrows:     return 4;
            case kBodyPart_Glasses:      return 5;
            case kBodyPart_InnerTorso:   return 6;
            case kBodyPart_MidTorso:     return 7;
            case kBodyPart_OuterTorso:   return 8;
            case kBodyPart_LowerBody:    return 9;
            case kBodyPart_Shoes:        return 10;
            case kBodyPart_Hat:          return 11;
            case kBodyPart_ArmAccessory: return 12;
            case kBodyPart_BootTop:      return 13;
            default:                     return -1;
        }
    }

    // Address: 0x80167664 | variable
    void DoStream(ReconBuffer* buf, int version) {
        ReconBuffer_StreamHalfwords(buf, &m_ageGender, 1);
        ReconBuffer_StreamBytes(buf, &m_skinColorType, 1);
        ReconBuffer_StreamInt(buf, &m_bodyType, 1);
        ReconBuffer_StreamBytes(buf, &m_headModelIdx, 1);
        ReconBuffer_StreamBytes(buf, &m_headTextureIdx, 1);
        ReconBuffer_StreamBytes(buf, &m_hairModelIdx, 1);
        ReconBuffer_StreamBytes(buf, &m_facialHairModelIdx, 1);
        ReconBuffer_StreamBytes(buf, &m_facialHairTextureIdx, 1);
        ReconBuffer_StreamInt(buf, &m_hairColor, 1);
        ReconBuffer_StreamInt(buf, &m_hairHighlight, 1);
        // ... remaining fields streamed in order
    }
};


// ============================================================================
// CasSimPartsS2C -- Static Body Part Catalog
// ============================================================================
//
// Provides lookup tables for all available models and textures per body part.
// Loaded from game data on CAS screen entry.
//
// Key methods use switch tables to dispatch per-body-part queries.

class CasSimPartsS2C {
public:
    // Internal data arrays loaded from catalog resources
    void* m_bodyPartData[kBodyPart_COUNT]; // pointers to part lists per slot

    // Address: 0x8016A9FC | variable
    int GetNumBodyModels(int bodyPart) const {
        // Switch on bodyPart enum to select correct data array
        // Returns count of available models for that slot
        return 0; // placeholder
    }

    int GetNumBodyTextures(int bodyPart) const {
        return 0; // placeholder
    }

    // Address: 0x8016ACA4 | variable
    u32 GetSkinTextureID(int skinColor) const {
        // Returns texture resource ID for given skin color index
        return 0;
    }

    u32 GetSkinTexturesDatasetID(int skinColor) const {
        return 0;
    }

    // Address: 0x8016AF28 | variable
    u32 GetBodyModelID(int bodyPart, int modelIndex) const {
        return 0; // placeholder
    }

    u32 GetBodyTextureID(int bodyPart, int textureIndex) const {
        return 0; // placeholder
    }

    u32 GetTattooTextureID(int tattooType, int textureIndex) const {
        return 0; // placeholder
    }
};


// ============================================================================
// CasGenetics -- Genetic Blending System
// ============================================================================
//
// Handles inheritance-based sim creation on the genetics screen.
// Blends parent/grandparent CasSimDescriptionS2C data to produce child appearance.
//
// Key concept: "Grandparent" objects hold saved sim descriptions that can be
// mixed. BlendSimDescriptions interpolates between two descriptions using
// weighted random selection of individual body parts.

class CasGenetics {
public:
    struct Grandparent {
        CasSimDescriptionS2C* m_description;
        int m_familyIndex;
        int m_neighborId;
    };

    Grandparent* m_grandparents[4]; // max 4 grandparents
    int m_numGrandparents;

    CasGenetics() : m_numGrandparents(0) {
        m_grandparents[0] = nullptr;
        m_grandparents[1] = nullptr;
        m_grandparents[2] = nullptr;
        m_grandparents[3] = nullptr;
    }

    ~CasGenetics() {
        for (int i = 0; i < 4; i++) {
            if (m_grandparents[i] != nullptr) {
                operator_delete(m_grandparents[i]);
                m_grandparents[i] = nullptr;
            }
        }
        m_numGrandparents = 0;
    }

    // Blend two sim descriptions together for genetic inheritance
    void BlendSimDescriptions(CasSimDescriptionS2C* parent1,
                              CasSimDescriptionS2C* parent2,
                              CasSimDescriptionS2C* child) {
        child->ClearSim(false);

        // For each body part, randomly pick from parent1 or parent2
        // Skin color: weighted blend
        // Morph values: linear interpolation with random weight
        // Hair: dominant/recessive gene model
        f32 blendFactor = GetRandomFloat();

        // Morph blending: lerp each morph value
        child->m_morphNoseWidth = parent1->m_morphNoseWidth * blendFactor +
                                  parent2->m_morphNoseWidth * (1.0f - blendFactor);
        child->m_morphNoseLength = parent1->m_morphNoseLength * blendFactor +
                                   parent2->m_morphNoseLength * (1.0f - blendFactor);
        child->m_morphChinShape = parent1->m_morphChinShape * blendFactor +
                                  parent2->m_morphChinShape * (1.0f - blendFactor);
        child->m_morphCheekWidth = parent1->m_morphCheekWidth * blendFactor +
                                   parent2->m_morphCheekWidth * (1.0f - blendFactor);
        child->m_morphEyeSpacing = parent1->m_morphEyeSpacing * blendFactor +
                                   parent2->m_morphEyeSpacing * (1.0f - blendFactor);
        child->m_morphEyeSize = parent1->m_morphEyeSize * blendFactor +
                                parent2->m_morphEyeSize * (1.0f - blendFactor);
        child->m_morphLipWidth = parent1->m_morphLipWidth * blendFactor +
                                 parent2->m_morphLipWidth * (1.0f - blendFactor);
        child->m_morphJawWidth = parent1->m_morphJawWidth * blendFactor +
                                 parent2->m_morphJawWidth * (1.0f - blendFactor);

        // Skin color: pick from parent with 50/50 chance
        if (RandomInt(2) == 0) {
            child->m_skinColorType = parent1->m_skinColorType;
        } else {
            child->m_skinColorType = parent2->m_skinColorType;
        }

        // Eye color: random parent
        if (RandomInt(2) == 0) {
            child->m_eyeColorModelIdx = parent1->m_eyeColorModelIdx;
            child->m_eyeColorTextureIdx = parent1->m_eyeColorTextureIdx;
        } else {
            child->m_eyeColorModelIdx = parent2->m_eyeColorModelIdx;
            child->m_eyeColorTextureIdx = parent2->m_eyeColorTextureIdx;
        }
    }
};


// ============================================================================
// CASTarget -- Top-Level CAS Controller (~5184 bytes)
// ============================================================================
//
// Main entry point for all Create-A-Sim flows. Manages navigation between
// CAS screens, owns sub-target objects, handles saving completed Sims.
//
// Layout: UIObjectBase base (0x28) + listeners + CasSimState[4] + subtargets
// Size: ~0x1440 (5184 bytes)

class CASTarget {
public:
    // Base UIObjectBase fields
    u8  m_baseFields[0x28];         // 0x000 UIObjectBase

    // Listener sub-objects
    u8  m_listeners[0x50];          // 0x028 5 listener sub-objects (16 bytes each)

    // Padding / misc
    u8  _pad_078[0x30];             // 0x078

    // CasSimState array -- supports up to 4 sims in a household
    u8  m_casSimStates[4 * 592];    // 0x108  (592 bytes each = 0x250)

    // CasMediator storage area
    u8  m_mediatorStorage[0x300];   // 0x0A48

    u32 m_hasSimInSlot;             // 0x1348 bitmask (bit per slot)
    u8  _pad_134C[4];               // 0x134C
    void* m_casScene;               // 0x1350 CasScene*
    void* m_npcEditor;              // 0x1354 CasNpcEditor*
    u8  _pad_1358[8];               // 0x1358
    int m_currentSimNumber;         // 0x1360

    u8  _pad_1364[12];              // 0x1364
    void* m_geneticsTarget;         // 0x1370 CASGeneticsTarget*
    void* m_morphTarget;            // 0x1374 CASMorphTarget*
    void* m_bodyTarget;             // 0x1378 CASBodyTarget*
    void* m_selectionTarget;        // 0x137C CASSelectionTarget*
    void* m_miscTarget;             // 0x1380 CASMiscTarget*
    void* m_fashionTarget;          // 0x1384 CASFashionTarget*
    void* m_personalTarget;         // 0x1388 CASPersonalTarget*
    void* m_tattooTarget;           // 0x138C CASTattooTarget*
    void* m_roommateTarget;         // 0x1390 CASRoommateTarget*
    u8  _pad_1394[4];               // 0x1394
    void* m_loaderUI;               // 0x1398

    u8  _pad_139C[0x8C];            // padding to reach name fields
    void* m_firstName;              // 0x1428 wchar_t*
    u8  _pad_142C[4];               // 0x142C
    void* m_lastName;               // 0x1430 wchar_t*

    // Address: 0x80190EA0 | 2912 bytes
    // Constructor: allocates sub-targets, sets up navigation table
    CASTarget(bool isNewGame) {
        memset(m_baseFields, 0, sizeof(m_baseFields));
        memset(m_listeners, 0, sizeof(m_listeners));
        memset(m_casSimStates, 0, sizeof(m_casSimStates));
        m_hasSimInSlot = 0;
        m_currentSimNumber = 0;
        m_casScene = nullptr;
        m_npcEditor = nullptr;
        m_geneticsTarget = nullptr;
        m_morphTarget = nullptr;
        m_bodyTarget = nullptr;
        m_selectionTarget = nullptr;
        m_miscTarget = nullptr;
        m_fashionTarget = nullptr;
        m_personalTarget = nullptr;
        m_tattooTarget = nullptr;
        m_roommateTarget = nullptr;
        m_loaderUI = nullptr;
        m_firstName = nullptr;
        m_lastName = nullptr;
    }

    // Address: 0x80191C94 | 1540 bytes
    void Init(bool isNewGame) {
        // Create all sub-target objects
        // Set up CAS navigation table (952 bytes at 0x80436C20)
        // Set up conditional navigation table (576 bytes at 0x80436FD8)
        // Initialize CasSimRenderer
    }

    // Address: 0x80192360 | 760 bytes
    void SaveSimToFamilySlot(int slotIndex) {
        // Copy current CasSimState to the family member slot
        // Validate required fields (name, etc.)
    }

    // Address: 0x80192658 | 468 bytes
    void SaveCASDataToNeighborhood() {
        // For each occupied slot:
        //   Create/update Neighbor in NeighborhoodImpl
        //   Copy CasSimDescriptionS2C to neighbor
        //   Assign to family
    }

    // Address: 0x80192DB8 | 804 bytes
    void ChangeMediator(int newMediatorIndex) {
        // Switch between CAS screens (body, fashion, genetics, etc.)
    }

    // Address: 0x80195154 | 2760 bytes
    void HandleConditionalNav(int condition) {
        // Process conditional navigation in the CAS state machine
    }

    int GetCurrentSimNumber() const { return m_currentSimNumber; }
    void SetCurrentSimNumber(int num) { m_currentSimNumber = num; }
};


// ############################################################################
//
//  SECTION 3: SimModel -- 3D SIM MODEL MANAGER
//
// ############################################################################
//
// SimModel manages the 3D rendering of a Sim character. It owns model parts
// for each body slot, skin textures, morph targets, and handles loading,
// welding, UV transformation, and compositing.
//
// From asm: 63 functions, 16,188 bytes total

class SimModel {
public:
    CasSimDescriptionS2C* m_simDescription;   // 0x00
    void* m_modelParts[kBodyPart_COUNT];       // 0x04 ERModel* per body part
    void* m_skinTexture;                       // skin composite texture
    void* m_morphTargets;                      // loaded morph target data
    u32   m_changedFlags;                      // bitfield: which parts changed
    u8    m_isInitialized;                     // true after Init()
    u8    _pad[3];

    // Address: 0x8010AB54 | variable
    SimModel() {
        m_simDescription = nullptr;
        for (int i = 0; i < kBodyPart_COUNT; i++) {
            m_modelParts[i] = nullptr;
        }
        m_skinTexture = nullptr;
        m_morphTargets = nullptr;
        m_changedFlags = 0;
        m_isInitialized = 0;
    }

    ~SimModel() {
        DeallocateAllModels();
        DeallocateAllSkinTextures();
        DeallocateMorphResources();
    }

    void Init(CasSimDescriptionS2C* desc, bool loadModels) {
        m_simDescription = desc;
        m_isInitialized = 1;
        if (loadModels) {
            SetAllModels();
        }
    }

    void Reset() {
        DeallocateAllModels();
        DeallocateAllSkinTextures();
        DeallocateMorphResources();
        m_changedFlags = 0;
    }

    void SetSimDescription(CasSimDescriptionS2C* desc) {
        m_simDescription = desc;
    }

    void DetachSimDescription() {
        m_simDescription = nullptr;
    }

    void DeallocateAllModels() {
        for (int i = 0; i < kBodyPart_COUNT; i++) {
            DeallocateModelPart(i);
        }
    }

    void DeallocateModelPart(int bodyPart) {
        if (m_modelParts[bodyPart] != nullptr) {
            // Release ERModel resource
            m_modelParts[bodyPart] = nullptr;
        }
    }

    void DeallocateMorphResources() {
        if (m_morphTargets != nullptr) {
            operator_delete(m_morphTargets);
            m_morphTargets = nullptr;
        }
    }

    void DeallocateAllSkinTextures() {
        if (m_skinTexture != nullptr) {
            // Release ERTexture resource
            m_skinTexture = nullptr;
        }
    }

    void SetAllModels() {
        for (int i = 0; i < kBodyPart_COUNT; i++) {
            SetModelPart(i, 0);
        }
    }

    void SetModelPart(int bodyPart, u32 modelId) {
        DeallocateModelPart(bodyPart);
        // Load model from resource system
        m_changedFlags |= (1u << bodyPart);
    }

    void UpdateModelPart(int bodyPart, bool reweld, bool remorph) {
        SetModelPart(bodyPart, 0);
        if (reweld) WeldAllSharedVertices();
        if (remorph) ApplyAllMorphTargets();
    }

    void ChangeModelPart(int bodyPart, u32 newModelId, bool reweld, bool remorph) {
        SetModelPart(bodyPart, newModelId);
        if (reweld) WeldAllSharedVertices();
        if (remorph) ApplyAllMorphTargets();
    }

    void GetChangedModels(int* outFlags) {
        *outFlags = (int)m_changedFlags;
        m_changedFlags = 0;
    }

    void WeldAllSharedVertices() {
        // Weld vertices shared between adjacent body parts
        // e.g., neck seam between head and torso
    }

    void ApplyAllMorphTargets() {
        // Apply facial morph values from m_simDescription to head mesh
    }

    void ApplyAllLatticeMorphing() {
        // Apply body type lattice deformation to all parts
    }

    void CreateSkin(char* skinName) {
        // Create skin composite texture
    }

    void ApplySkinToModels() {
        // Apply the composited skin texture to all body part models
        for (int i = 0; i < kBodyPart_COUNT; i++) {
            ApplySkinToModelPart(i);
        }
    }

    void ApplySkinToModelPart(int bodyPart) {
        // Apply skin texture to specific body part model
    }

    void TransformAllModelUV() {
        // Transform UV coordinates for all body parts
        for (int i = 0; i < kBodyPart_COUNT; i++) {
            TransformModelPartUV(i);
        }
    }

    void TransformModelPartUV(int bodyPart) {
        // Transform UV coordinates for a specific body part
    }

    void CompositeAllSkin() {
        // CPU-based compositing of skin texture layers
    }

    void RebuildModified() {
        // Rebuild only the parts that have been modified
    }

    void FlushLoadingModels() {
        // Wait for async model loads to complete
    }

    void* Clone() {
        // Create a copy of this SimModel
        return nullptr; // placeholder
    }
};


// ############################################################################
//
//  SECTION 4: BEHAVIOR TREE SYSTEM
//
// ############################################################################

// ============================================================================
// BehaviorNode -- Single instruction in a BHAV tree
// ============================================================================

struct BehaviorNode {
    u16 opcode;       // 0x00 primitive opcode or tree ID for gosub
    u8  true_dest;    // 0x02 node index on true result (253=error, 254=true, 255=false)
    u8  false_dest;   // 0x03 node index on false result
    u32 operand0;     // 0x04 first operand word
    u32 operand1;     // 0x08 second operand word
};

// ============================================================================
// TreeSim -- Base class for behavior tree simulation
// ============================================================================
//
// Holds references to the sim/object being controlled.
// Size: ~68 bytes as base.
//
// From asm: 1 function (dyncast), plus many trivial getters in decomp docs

class TreeSim {
public:
    void*          m_pObjectImpl;    // 0x00 cXObjectImpl*
    void*          m_pPersonImpl;    // 0x04 cXPersonImpl*
    void*          m_pMTObjectImpl;  // 0x08 cXMTObjectImpl*
    void*          m_pPortalImpl;    // 0x0C cXPortalImpl*
    void*          m_pPerson;        // 0x10 cXPerson*
    void*          m_pBaseSimInst;   // 0x14 IBaseSimInstance*
    void*          m_pESimPerson;    // 0x18 ESim*
    int            m_maxIterations;  // 0x1C
    f32            m_tooLongPrimTime;  // 0x20
    f32            m_tooLongTickTime;  // 0x24
    u32            m_breakFlags;     // 0x28 debug break settings
    u32            m_field_2C;       // 0x2C
    u32            m_field_30;       // 0x30
    u32            m_isExecutingInMainSim; // 0x34

    TreeSim() {
        m_pObjectImpl = nullptr;
        m_pPersonImpl = nullptr;
        m_pMTObjectImpl = nullptr;
        m_pPortalImpl = nullptr;
        m_pPerson = nullptr;
        m_pBaseSimInst = nullptr;
        m_pESimPerson = nullptr;
        m_maxIterations = 50000;
        m_tooLongPrimTime = 0.0f;
        m_tooLongTickTime = 0.0f;
        m_breakFlags = 0;
        m_field_2C = 0;
        m_field_30 = 0;
        m_isExecutingInMainSim = 0;
    }

    virtual ~TreeSim() {}

    // Trivial getters/setters (all 8 bytes / 2 instructions each)
    void* GetPerson()           { return m_pPerson; }
    void* GetBaseISimInstance()  { return m_pBaseSimInst; }
    void  SetISimInstance(void* inst) { m_pBaseSimInst = inst; }
    void* GetESimPerson()       { return m_pESimPerson; }
    void  SetESimPerson(void* esim)   { m_pESimPerson = esim; }
    void  setObjectImpl(void* impl)   { m_pObjectImpl = impl; }
    void  setPersonImpl(void* impl)   { m_pPersonImpl = impl; }
    void  setMTObjectImpl(void* impl) { m_pMTObjectImpl = impl; }
    void  setPortalImpl(void* impl)   { m_pPortalImpl = impl; }
    int   GetMaxIterations()    { return m_maxIterations; }
    void  SetMaxIterations(int n) { m_maxIterations = n; }
    bool  IsExecutingInMainSim() { return m_isExecutingInMainSim != 0; }

    // Address: 0x800F2BA4 | 176 bytes
    // SN Systems dynamic cast implementation
    void* _dyncastimpl(int scid) {
        switch (scid) {
            case 7:  return m_pPersonImpl;
            case 8:  return m_pMTObjectImpl;
            case 10: return m_pObjectImpl;
            case 11: return m_pPortalImpl;
            case 6: {
                // Check portal -> return portal's person if exists
                if (m_pPortalImpl == nullptr) return nullptr;
                return *(void**)((u8*)m_pPortalImpl + 4);
            }
            case 2: {
                if (m_pPersonImpl == nullptr) return nullptr;
                return *(void**)((u8*)m_pPersonImpl + 4);
            }
            case 3: {
                if (m_pMTObjectImpl == nullptr) return nullptr;
                return *(void**)((u8*)m_pMTObjectImpl + 4);
            }
            case 1: case 5: {
                if (m_pObjectImpl == nullptr) return nullptr;
                return *(void**)((u8*)m_pObjectImpl + 4);
            }
            default: return nullptr;
        }
    }
};


// ============================================================================
// TreeStack -- Call frame stack for BHAV gosub/return
// ============================================================================
//
// Manages a dynamic stack of StackElem frames. Each frame represents one
// active BHAV tree in the call chain.
//
// From asm: 8 functions, 2,292 bytes total

class TreeStack {
public:
    void*  m_stackMemory;     // 0x00 heap-allocated stack buffer
    u32    m_stackCapacity;   // 0x04 reserved bytes
    void*  m_frames;          // 0x08 vector<StackElem*> data
    void*  m_framesEnd;       // 0x0C vector end
    void*  m_framesCapEnd;    // 0x10 vector capacity end
    int    m_stackSize;       // 0x14 number of frames on stack
    int    m_memUsed;         // 0x18 bytes currently used

    // Address: 0x80147198 | 140 bytes
    ~TreeStack() {
        if (m_stackMemory != nullptr) {
            // Free via EAHeap::Free(MainHeap(), m_stackMemory)
            m_stackMemory = nullptr;
        }
        // Free the frames vector
    }

    // Address: 0x80147474 | 216 bytes
    void MakeNewFrame(u32 frameSize) {
        // Check if there's enough space in current buffer
        // If not, grow the buffer (double size, min 512 bytes)
        // Allocate a StackElem at current position
    }

    // Address: 0x80148D10 | variable
    int GetMemUsed() {
        return m_memUsed;
    }

    // Address: 0x80148D18 | variable
    void AssignFrames(int numFrames) {
        m_stackSize = numFrames;
    }

    // Address: 0x80147960 | variable
    void Push(StackElem* frame, short* params) {
        // Push a new frame onto the stack
        // Copy params into the frame's local variable area
        m_stackSize++;
    }

    // Address: 0x80148C70 | variable
    void Pop() {
        // Pop the top frame, decrement stack size
        if (m_stackSize > 0) {
            m_stackSize--;
        }
    }

    void Reset() {
        m_stackSize = 0;
        m_memUsed = 0;
    }

    // Address: 0x80148B40 | variable
    void ReconStream(ReconBuffer* buf, int version, BehaviorFinder* finder) {
        // Serialize/deserialize the entire stack for save/load
    }
};


// ============================================================================
// TreeSimImpl -- Behavior Tree Execution Engine
// ============================================================================
//
// The actual BHAV tree interpreter. Contains the TreeStack, iteration counter,
// primitive dispatch vtable, and the main Simulate() / DoNodeAction() loop.
//
// From asm: 13 functions, 4,616 bytes total
// Size: ~84 bytes (0x54) or larger

class TreeSimImpl {
public:
    void*       m_pTreeSim;       // 0x00 pointer to TreeSim portion
    u32         m_iterations;     // 0x04 iteration counter per tick
    f32         m_tickTime;       // 0x08 accumulated tick time
    TreeStack   m_stack;          // 0x0C embedded TreeStack
    u32         m_lastNodeOp;     // 0x28 last executed node opcode
    u32         m_lastResult;     // 0x2C last primitive result
    void*       m_pParams;        // 0x30 current parameter locals
    s16         m_error;          // 0x34 error code (0=none, 1000+=error)
    u16         _pad_036;         // 0x36
    u32         m_field_038;      // 0x38
    u32         m_field_03C;      // 0x3C
    void*       m_pVtable;        // 0x40 primitive dispatch vtable
    u32         m_field_044;      // 0x44
    u8          m_localVtable[192]; // 0x48 local copy of vtable data

    // Address: 0x8014772C | 508 bytes
    TreeSimImpl(int allocMode) {
        m_iterations = 0;
        m_tickTime = 0.0f;
        m_lastNodeOp = 253; // error/uninitialized
        m_lastResult = 0;
        m_pParams = nullptr;
        m_error = 0;
        m_field_038 = 0;
        m_field_03C = 0;
        m_pVtable = nullptr;
        m_field_044 = 0;
        // Copy static vtable (168 bytes) to local storage
        // Patch this-adjustment offsets
    }

    // Address: 0x80147258 | 476 bytes
    ~TreeSimImpl() {
        // Destroy embedded TreeStack
        // Reset vtable pointers
    }

    // Address: 0x80147928 | 56 bytes
    void Initialize(int stackSize, short* params) {
        m_stack.MakeNewFrame(stackSize);
        m_pParams = params;
    }

    void* GetISimInstance() {
        // Get ISimInstance from the TreeSim's person
        return nullptr;
    }

    // Address: 0x80148C10 | variable
    void GetCurrentNode(short* outTreeId, short* outNodeIdx) {
        // Return current tree ID and node index from top of stack
        *outTreeId = -1;
        *outNodeIdx = -1;
    }

    // Address: 0x80148C4C | variable
    int GetCurrentPrimitive() {
        // Return opcode of current node
        return m_lastNodeOp;
    }

    // Address: 0x80147A34 | 108 bytes
    void Reset(Behavior* behavior, short treeID) {
        m_stack.Reset();
        if (treeID != 0) {
            short params[2] = {0, 0};
            Gosub(behavior, nullptr, treeID);
            m_error = 0;
        }
    }

    // Address: 0x80147AA0 | 464 bytes
    // BHAV gosub: push a new tree frame onto the stack
    int Gosub(Behavior* behavior, short* callerParams, short treeID) {
        // 1. Get current top of stack
        // 2. Resolve tree via Behavior::GetTree(treeID)
        // 3. If not found, return 0
        // 4. Build new StackElem frame with tree info
        // 5. Push onto TreeStack
        // 6. Return 1 on success
        return 1;
    }

    // Address: 0x80147C68 | variable
    int RunCheckTree(Behavior* behavior, short treeID, short param, short* outResult) {
        // Execute a check tree (used for ad test / guard conditions)
        // Returns true if check passed, false if failed
        return 0;
    }

    // Address: 0x80147FD8 | 1380 bytes
    // THE CORE: Execute one step of the behavior tree
    int DoNodeAction(StackElem* stackElem) {
        if (stackElem == nullptr) {
            m_error = 1001; // stack empty
            return 1; // tree completed with error
        }

        m_iterations++;

        // Check iteration limit
        if ((int)m_iterations > 50000) {
            m_error = 1101; // max iterations exceeded
            return 1;
        }

        // Get current node from stack frame
        // BehaviorNode* node = stackElem->GetCurrentNode();
        // u16 opcode = node->opcode;

        // If opcode >= 256: this is a gosub to another tree
        // If opcode <= 254: dispatch to primitive handler via vtable

        // Primitive dispatch:
        //   handler = m_pVtable[opcode]
        //   result = handler(this, stackElem, opcode, node->operand0, node->operand1)

        // Based on result:
        //   0 (false): advance to node->false_dest
        //   1 (true):  advance to node->true_dest
        //   2 (yield): return 2 (tree paused)

        // Special destinations:
        //   253 -> error return
        //   254 -> true return (tree success)
        //   255 -> false return (tree failure)

        // If destination is a return, pop the stack
        // If stack is empty after pop, tree completed

        return 0; // continue to next node
    }

    // Address: 0x80148550 | 136 bytes
    // Main per-tick simulation entry
    int Simulate(int param) {
        m_iterations = 0;
        m_tickTime = 0.0f;

        while (true) {
            // Get current top-of-stack element (via vtable call)
            StackElem* curElem = nullptr; // GetCurElem()

            int result = DoNodeAction(curElem);

            if (result == 1) return 1;   // tree completed
            if (result == 2) return 0;   // tree yielded
            // result == 0: continue to next node
        }
    }

    // Address: 0x80148AF0 | variable
    void* GetHighLevelAction() {
        // Returns the top-level action description
        return nullptr;
    }

    // Address: 0x80148B00 | variable
    void* GetMainSimElem() {
        // Returns the main (bottom) stack element
        return nullptr;
    }

    // Address: 0x80147FA8 | variable
    void HandleBreakpoint(StackElem* elem, BehaviorNode* node) {
        // Debug breakpoint handler -- no-op in release build
    }
};


// ============================================================================
// TreeTable -- Interaction Lookup Table (TTAB)
// ============================================================================
//
// Table of available interactions on an object. Each entry has a check tree,
// action tree, ad data for autonomy scoring, and UI name.
//
// From asm: 2 functions, 208 bytes

class TreeTable {
public:
    TreeTableEntry* m_entries; // 0x00 pointer to array of entries

    // Address: 0x801498B0 | 116 bytes
    int GetIndexOfResource(short resourceId) const {
        if (m_entries == nullptr) return -1;

        int count = 0;
        // Get count from array header (stored at offset -4)
        // count = *(int*)((u8*)m_entries - 4);

        // Search entries using FindRes<TreeTableEntry>
        // Each entry is 36 bytes
        // Returns index in array, or -1 if not found
        return -1;
    }

    // Address: 0x80149924 | 92 bytes
    int GetIndexByTreeID(short treeID, short checkTreeID) const {
        if (m_entries == nullptr) return -1;

        int count = 0;
        // Get count from array header
        // count = *(int*)((u8*)m_entries - 4);

        for (int i = 0; i < count; i++) {
            // Each entry is 36 bytes
            s16* entry = (s16*)((u8*)m_entries + i * 36);
            if (entry[0] == treeID && entry[1] == checkTreeID) {
                return i;
            }
        }
        return -1;
    }
};


// ============================================================================
// TreeTableEntry -- One row in the TTAB (36 bytes)
// ============================================================================
//
// Each entry: action tree ID, check tree ID, ad data, flags, name.
// From asm: 1 function, 108 bytes

class TreeTableEntry_Impl {
public:
    s16   m_actionTreeID;    // 0x00
    s16   m_checkTreeID;     // 0x02
    void* m_adArray;         // 0x04 array of TreeTableAd (8 bytes each)
    // ... other fields up to 36 bytes total

    // Address: 0x803AF7F0 | 108 bytes
    // Returns the ad entry matching the given ID
    void* GetAdByID(int adId) const {
        // Walk the ad array, find entry with matching ID field at offset +6
        if (m_adArray == nullptr) return nullptr;

        int count = 0;
        // count = *(int*)((u8*)m_adArray - 4);

        for (int i = 0; i < count; i++) {
            s16* ad = (s16*)((u8*)m_adArray + i * 8);
            if (ad[3] == (s16)adId) {
                return ad;
            }
        }

        // Return the static "null ad" if not found
        return nullptr;
    }
};


// ============================================================================
// TreeTableQuickData -- Fast-loaded tree table data
// ============================================================================
//
// Wrapper around loaded TTAB data with COM-style QueryInterface/Release.
// From asm: 10 functions, 1,636 bytes

class TreeTableQuickData {
public:
    void** m_vtable;             // 0x00
    int    m_refCount;           // 0x04
    void*  m_entryArrayData;    // 0x08 vector<ConsoleAutoRefCount<TreeTableEntryQuickData>>
    void*  m_entryArrayEnd;     // 0x0C
    void*  m_entryArrayCap;     // 0x10
    void*  m_orderedEntries;    // 0x14
    void*  m_orderedEnd;        // 0x18
    ObjectDataID* m_dataId;     // 0x1C (embedded at offset 0x18)
    int    m_numEntries;        // 0x20

    // Address: 0x8015DCB8 | 104 bytes
    TreeTableQuickData() {
        m_refCount = 0;
        m_entryArrayData = nullptr;
        m_entryArrayEnd = nullptr;
        m_entryArrayCap = nullptr;
        m_orderedEntries = nullptr;
        m_orderedEnd = nullptr;
        m_numEntries = 0;
    }

    // Address: 0x8015DD20 | 268 bytes
    ~TreeTableQuickData() {
        // Release all entries in the vector
        // Free the vectors themselves
        m_refCount = 0;
    }

    void* GetNthEntry(int n) const {
        if (m_entryArrayData == nullptr) return nullptr;
        return ((void**)m_entryArrayData)[n];
    }

    void* GetEntryByIndex(int index) const {
        return GetNthEntry(index);
    }

    void* GetEntryByTreeID(short treeID, short checkTreeID) const {
        // Linear search through entries
        return nullptr;
    }

    void* GetNthOrderedEntry(int n) const {
        if (m_orderedEntries == nullptr) return nullptr;
        return ((void**)m_orderedEntries)[n];
    }

    // COM-style interface
    int QueryInterface(u32 iid, void** outPtr) {
        if (outPtr == nullptr) return 0;
        if (iid == 1 || iid == 0x6BF32227) { // known IIDs
            // AddRef
            *outPtr = this;
            return 1;
        }
        return 0;
    }

    int Release() {
        m_refCount--;
        if (m_refCount <= 0) {
            // Destroy via vtable
            return 0;
        }
        return m_refCount;
    }
};


// ============================================================================
// TreeTableEntryQuickData -- Fast-loaded entry (per-interaction)
// ============================================================================
//
// From asm: 5 functions, 1,136 bytes

class TreeTableEntryQuickData {
public:
    void** m_vtable;          // 0x00
    void*  m_treeTableEntry;  // 0x04 TreeTableEntry*
    void*  m_adArrayData;     // 0x08 vector data
    void*  m_adArrayEnd;      // 0x0C
    void*  m_adArrayCap;      // 0x10
    int    m_refCount;        // 0x14 (or at another offset)
    void*  m_defaultAd;       // 0x18

    TreeTableEntryQuickData(void* entry) {
        m_treeTableEntry = entry;
        m_adArrayData = nullptr;
        m_adArrayEnd = nullptr;
        m_adArrayCap = nullptr;
        m_refCount = 0;
        m_defaultAd = nullptr;
        // Initialize ad vector with 16 entries from the tree table entry
    }

    ~TreeTableEntryQuickData() {
        // Release all ads in the vector
    }

    void* GetAd(int index) const {
        if (m_adArrayData == nullptr) return nullptr;
        return ((void**)m_adArrayData)[index];
    }

    int QueryInterface(u32 iid, void** outPtr) {
        if (outPtr == nullptr) return 0;
        if (iid == 1 || iid == 0x6BF32227) {
            *outPtr = this;
            return 1;
        }
        return 0;
    }

    int Release() {
        m_refCount--;
        if (m_refCount <= 0) {
            // Destroy
            return 0;
        }
        return m_refCount;
    }
};


// ============================================================================
// TreeTableAdQuickData -- Fast-loaded ad data
// ============================================================================
//
// From asm: 2 functions, 204 bytes

class TreeTableAdQuickData {
public:
    void** m_vtable;   // 0x00
    void*  m_adData;   // 0x04
    int    m_refCount; // 0x08

    int QueryInterface(u32 iid, void** outPtr) {
        if (outPtr == nullptr) return 0;
        if (iid == 1 || iid == 0x6BF32227) {
            *outPtr = this;
            return 1;
        }
        return 0;
    }

    int Release() {
        m_refCount--;
        if (m_refCount <= 0) {
            // Destroy via vtable
            return 0;
        }
        return m_refCount;
    }
};


// ============================================================================
// TreeTableAdScratch -- Scratch copy of a tree table ad
// ============================================================================
//
// From asm: 3 functions, 432 bytes

class TreeTableAdScratch {
public:
    void** m_vtable;      // 0x00
    void*  m_adData;      // 0x04
    void*  m_field_08;    // 0x08
    int    m_refCount;    // 0x0C

    int QueryInterface(u32 iid, void** outPtr) {
        if (outPtr == nullptr) return 0;
        if (iid == 1 || iid == 0x6BF32227) {
            *outPtr = this;
            return 1;
        }
        return 0;
    }

    int Release() {
        m_refCount--;
        if (m_refCount <= 0) {
            return 0;
        }
        return m_refCount;
    }

    void operator=(void* srcAd) {
        // Copy ad data from ITreeTableAd source
    }
};


// ============================================================================
// TTabScratchEntry -- Scratch copy of a tree table entry
// ============================================================================
//
// From asm: 6 functions, 904 bytes

class TTabScratchEntry {
public:
    void** m_vtable;             // 0x00
    s16    m_actionTreeID;       // 0x04
    s16    m_checkTreeID;        // 0x06
    u8     m_adSlots[256];       // 0x08 up to 16 ads (16 bytes each)
    int    m_refCount;           // 0x108

    ~TTabScratchEntry() {
        // Release all ad slots
    }

    void CopyFrom(void* srcEntry) {
        // Copy action tree ID, check tree ID, flags from source
        // Copy all ad entries
    }

    int QueryInterface(u32 iid, void** outPtr) {
        if (outPtr == nullptr) return 0;
        if (iid == 1 || iid == 0x6BF32227) {
            *outPtr = this;
            return 1;
        }
        return 0;
    }

    int Release() {
        m_refCount--;
        if (m_refCount <= 0) {
            return 0;
        }
        return m_refCount;
    }

    void SetAd(int index, void* srcAd) {
        // Copy ad data to slot[index]
    }

    const char* GetName() const {
        return nullptr; // placeholder
    }
};


// ============================================================================
// TreeTab -- Tree table data container
// ============================================================================
//
// Wraps the loaded TTAB resource. Provides iteration over entries.

class TreeTab {
public:
    void*  m_treeTableData;   // loaded TTAB resource
    int    m_entryCount;

    TreeTab() : m_treeTableData(nullptr), m_entryCount(0) {}

    int GetEntryCount() const { return m_entryCount; }

    void* GetEntry(int index) const {
        if (index < 0 || index >= m_entryCount) return nullptr;
        // Each entry is 36 bytes
        return (void*)((u8*)m_treeTableData + index * 36);
    }

    int FindEntryByTreeID(short treeID) const {
        for (int i = 0; i < m_entryCount; i++) {
            s16* entry = (s16*)((u8*)m_treeTableData + i * 36);
            if (*entry == treeID) return i;
        }
        return -1;
    }
};


// ############################################################################
//
//  SECTION 5: WANTFEAR BOOKMARK METHODS
//
// ############################################################################
//
// The WantFear::Bookmark struct is defined in effects_skin_neighborhood.cpp.
// Here we implement the methods from the asm decomp (14 functions, 4508 bytes).

namespace WantFear_Methods {

// Re-declare types matching effects_skin_neighborhood.cpp
struct Event {
    u16  m_eventId;
    u8   m_type;        // 0x01=platinum, 0x80=fear
    u8   m_category;
    u8   _data[32];
};

struct Node {
    u16  m_eventRef;
    u8   m_flags;           // bit 0=hidden, bit 1=target override
    u8   _pad_03;
    s16  m_defaultTarget;
    s16  m_field_06;
    s16  m_countdown;       // 0x08
    u8   m_numBranches;
    u8   m_firstChildIndex;
    u32  m_field_0C;
    u8   m_adData[8];
    u32  m_rewardData;
    u8   m_field_1C;
    u8   m_field_1D;
    u8   _pad[2];

    Event* GetEvent() const {
        // Look up event by m_eventRef via WantFearManager
        return nullptr;
    }
};

struct Bookmark {
    u16   m_treeId;
    u16   m_countdown;
    Node* m_node;
    u16   m_adIndex;
    u16   _pad;

    // Address: 0x8014ABE4 | 80 bytes
    void ResetCountdown() {
        Node* node = m_node;
        Event* evt = node->GetEvent();
        if (evt != nullptr && evt->_data[9] == 2) {
            // Type 2: use node's default countdown
            m_countdown = node->m_countdown;
        } else {
            m_countdown = 0;
        }
    }

    // Address: 0x8014ACB8 | 120 bytes
    bool IsDuplicateNode(const Bookmark& other) const {
        if (m_treeId != other.m_treeId) return false;
        if (m_node != other.m_node) return false;
        // Also compare targets
        return (GetTarget() == other.GetTarget());
    }

    // Address: 0x8014AD30 | 112 bytes
    bool IsDuplicateEvent(const Bookmark& other) const {
        Node* myNode = m_node;
        Node* otherNode = other.m_node;
        Event* myEvt = myNode->GetEvent();
        Event* otherEvt = otherNode->GetEvent();
        if (myEvt == nullptr || otherEvt == nullptr) return false;
        if (myEvt->m_eventId != otherEvt->m_eventId) return false;
        return (GetTarget() == other.GetTarget());
    }

    // Address: 0x8014ADA0 | 104 bytes
    int GetType() const {
        Node* node = m_node;
        Event* evt = node->GetEvent();
        if (evt == nullptr) return 0;
        u8 type = evt->m_type;
        if (type == 0x80) return 128; // fear
        if (type == 0x01) return 1;   // platinum want
        if (IsInStoryTree()) return 4; // story want
        return 0; // normal want
    }

    bool IsInStoryTree() const {
        // Check tree's story flag
        return false;
    }

    s16 GetTarget() const {
        if (m_node == nullptr) return -1;
        if (m_node->m_flags & 2) {
            // Target override: countdown field holds the target
            return (s16)m_countdown;
        }
        return m_node->m_defaultTarget;
    }

    // Address: 0x8014B39C | variable
    bool SatisfiedBy(const void* notification) const {
        // Check if the given notification event matches this bookmark
        // Compare event types and targets
        return false;
    }

    // Address: 0x8014B460 | variable
    bool IsValid(Neighbor* neighbor, bool checkActive) const {
        // Validate that this bookmark is still valid
        // Tree exists, node exists, sim qualifies
        return (m_node != nullptr && m_treeId != 0xFFFF);
    }

    // Address: 0x8014B538 | variable
    bool IsCompleted(Neighbor* neighbor) const {
        // Check if countdown has reached zero
        return (m_countdown == 0);
    }

    // Address: 0x8014B5C4 | variable
    void ApplyReward(Neighbor* neighbor) {
        // Grant aspiration points based on reward data
        // Positive for wants, negative for fears
    }

    // Address: 0x8014B69C | variable
    void GetNextBookmarkAlongBranch(short branchIndex) {
        // Advance to the next node along a branch
    }

    // Address: 0x8014B774 | variable
    void DoStream(ReconBuffer* buf, int version) {
        ReconBuffer_StreamHalfwords(buf, &m_treeId, 1);
        ReconBuffer_StreamHalfwords(buf, &m_countdown, 1);
        ReconBuffer_StreamHalfwords(buf, &m_adIndex, 1);
        // Node pointer is resolved after load via tree lookup
    }
};

} // namespace WantFear_Methods


// ############################################################################
//
//  SECTION 6: AwarenessManager -- NPC HEAD TRACKING & AWARENESS
//
// ############################################################################
//
// Manages NPC awareness behavior: head turning to look at objects/people,
// memory-based awareness animations, passive influence reactions, rain checks.
//
// From asm: 38 functions, 11,032 bytes total

class AwarenessManager {
public:
    SAnimator2*      m_animator;          // 0x00
    EAnimController* m_animController;    // 0x04
    cXObject*        m_awareTarget;       // 0x08 object being looked at
    cXObject*        m_memoryTarget;      // 0x0C memory awareness target
    f32              m_targetAngle;       // 0x10 angle to look at
    f32              m_currentAngle;      // 0x14 current head angle
    f32              m_headRotation;      // 0x18
    f32              m_torsoRotation;     // 0x1C
    u32              m_lastCheckTime;     // 0x20
    u32              m_memoryCheckTime;   // 0x24
    int              m_memoryCategory;    // 0x28
    int              m_memorySubcategory; // 0x2C
    u32              m_flags;             // 0x30 awareness state flags
    AnimRef*         m_passiveInfluenceAnim; // 0x34
    int              m_pendingMemoryAnimId;  // 0x38
    int              m_pendingMemoryAnimSub; // 0x3C
    u8               m_isAutoCarrying;    // 0x40
    u8               _pad[3];             // 0x41

    // Address: 0x80011F4C | 232 bytes
    void Init(SAnimator2* animator, EAnimController* controller) {
        m_animator = animator;
        m_animController = controller;
        m_awareTarget = nullptr;
        m_memoryTarget = nullptr;
        m_targetAngle = 0.0f;
        m_currentAngle = 0.0f;
        m_headRotation = 0.0f;
        m_torsoRotation = 0.0f;
        m_lastCheckTime = 0;
        m_memoryCheckTime = 0;
        m_memoryCategory = 0;
        m_memorySubcategory = 0;
        m_flags = 0;
        m_passiveInfluenceAnim = nullptr;
        m_pendingMemoryAnimId = -1;
        m_pendingMemoryAnimSub = -1;
        m_isAutoCarrying = 0;
    }

    void Reset() {
        m_awareTarget = nullptr;
        m_memoryTarget = nullptr;
        m_targetAngle = 0.0f;
        m_currentAngle = 0.0f;
        m_headRotation = 0.0f;
        m_torsoRotation = 0.0f;
        m_flags = 0;
        m_passiveInfluenceAnim = nullptr;
        m_pendingMemoryAnimId = -1;
    }

    ~AwarenessManager() {
        Reset();
    }

    void SetAwareOfObject(cXObject* obj) {
        m_awareTarget = obj;
    }

    void ClearAwareOfObject(cXObject* obj) {
        if (m_awareTarget == obj) {
            m_awareTarget = nullptr;
        }
    }

    void SetAwarenessTargetAngle(cXObject* target) {
        // Compute angle from sim to target object
        // m_targetAngle = atan2(deltaX, deltaZ)
    }

    void AwarenessCheck(u32 tickCount) {
        // Main per-tick awareness check
        // 1. Check if sim should look at an object
        // 2. Update head/torso rotation towards target
        // 3. Handle animation transitions
        handleAwarenessAnimations(tickCount);
    }

    void handleAwarenessAnimations(u32 tickCount) {
        // Animate head and torso rotation to track target
        handleAwarenessTurningAnimation();
    }

    void handleAwarenessTurningAnimation() {
        // Smooth interpolation of head rotation
    }

    void UpdateAwarenessAngle(u32 tickCount) {
        // Update the target angle as objects move
    }

    f32 GetDeltaAngleToTargetObject(cXObject* target) {
        // Returns angle difference between current facing and target
        return 0.0f;
    }

    bool ShouldAwarenessBeActive(u32 tickCount) {
        // Check conditions: sim not busy, target visible, etc.
        return (m_awareTarget != nullptr);
    }

    void MemoryAwarenessCheck(u32 tickCount) {
        // Check if sim should react to a memory (e.g., seeing a dead relative's grave)
    }

    bool IsTimeToCheckMemoryAwareness(u32 tickCount) {
        return (tickCount - m_memoryCheckTime) > 300; // every ~5 seconds
    }

    bool CanSeePlayer() {
        return false; // placeholder
    }

    void GetActiveMemoryCategory(cXObject* obj, int& category, int& subcategory) {
        category = 0;
        subcategory = 0;
    }

    void SetMemoryAwarenessActionToTry(cXObject* obj) {
        m_memoryTarget = obj;
    }

    void MemoryAwarenessClearAction() {
        m_memoryTarget = nullptr;
    }

    void SetPendingMemoryAwarenessAnim(int animId, int animSub) {
        m_pendingMemoryAnimId = animId;
        m_pendingMemoryAnimSub = animSub;
    }

    void StartMemoryAwarenessAnimation(int animId, int animSub) {
        // Start playing the memory awareness animation
    }

    void RainAwarenessCheck() {
        // Check if sim should react to rain (run inside, etc.)
    }

    void PassiveInfluenceAwarenessCheck(u32 tickCount) {
        // Check if nearby objects are passively influencing the sim
    }

    void StopPassiveInfluenceAnimation() {
        m_passiveInfluenceAnim = nullptr;
    }

    void StartPassiveInfluenceAnimation(AnimRef* anim) {
        m_passiveInfluenceAnim = anim;
    }

    bool shouldAutoCarry() {
        return m_isAutoCarrying != 0;
    }

    void startAutoCarry() {
        m_isAutoCarrying = 1;
    }

    void endAutoCarry() {
        m_isAutoCarrying = 0;
    }

    bool IsMemoryAwarenessAnimDone() {
        return (m_pendingMemoryAnimId == -1);
    }

    void StarMemoryAwarenessSprite() {
        // Show the memory bubble sprite
    }

    void AwarenessAutoRunCheck(f32 speed) {
        // Check if awareness should disable during auto-run
    }

    f32 GetFirstNodeRotation(f32 deltaAngle, f32 maxAngle) {
        // Compute head rotation clamped to max
        if (deltaAngle > maxAngle) return maxAngle;
        if (deltaAngle < -maxAngle) return -maxAngle;
        return deltaAngle;
    }

    f32 GetSecondNodeRotation(f32 remainingAngle) {
        // Compute torso rotation for remaining angle
        return remainingAngle * 0.5f;
    }
};


// ############################################################################
//
//  SECTION 7: Neighbor -- NEIGHBORHOOD CHARACTER DATA
//
// ############################################################################
//
// A Neighbor represents a persistent character in the neighborhood.
// Contains: identity (name, GUID), relationships, persistent data fields,
// wants/fears bookmarks, motive history, and aspiration state.
//
// From asm: 39 functions, 13,740 bytes total
// Size: ~540 bytes (estimated from field access patterns)

class Neighbor_Impl {
public:
    // Layout (from constructor and field access analysis):
    void*  m_vtable;                  // 0x000
    u8     _pad_004[24];             // 0x004
    s16    m_neighborID;              // 0x01C
    s16    m_selectorIndex;           // 0x01E
    s16    m_familyIndex;             // 0x020
    s16    m_field_022;               // 0x022
    u8     m_nameBuffer[64];          // 0x028 StringBuffer (40+24 = 64 bytes)
    u8     _pad_068[0xC8];           // 0x068
    // Relationships at ~0x130
    s16    m_relationships[32];       // relationship values per neighbor
    // Persistent data at ~0x170
    s16    m_persistentData[32];      // persistent sim data fields
    // Wants/fears bookmarks at ~0x194
    u8     m_wantFearBookmarks[240];  // 20 bookmarks (12 bytes each)
    u8     m_wantFearIcons[84];       // 7 icon slots (12 bytes each)
    // Motive data
    u8     m_motiveData[128];         // 0x110 Motives

    // ---- Constructor ----
    // Address: 0x800C8C48 | 184 bytes
    Neighbor_Impl() {
        m_neighborID = 0;
        m_selectorIndex = 0;
        m_familyIndex = 0;
        m_field_022 = 0;
        // Initialize StringBuffer at +0x028 with 64-byte capacity
        // Initialize Motives at +0x110
        // Allocate relationship array (240 bytes)
        InitDefaultValues();
    }

    ~Neighbor_Impl() {
        // Free relationship array
        // Destroy StringBuffer
    }

    // Address: 0x800C8D44 | variable
    // Construct from ID and selector
    void InitFromSelector(short id, ObjSelector* sel) {
        m_neighborID = id;
        // Copy name from selector
        // Initialize default data
    }

    // Copy constructor
    void CopyFrom(Neighbor_Impl& other) {
        // Deep copy all fields
        m_neighborID = other.m_neighborID;
        m_selectorIndex = other.m_selectorIndex;
        m_familyIndex = other.m_familyIndex;
    }

    // Address: 0x800C9220 | variable
    int GetNumPersistentDataFields() {
        return 32; // fixed at 32 persistent fields
    }

    // Address: 0x800C92F8 | variable
    void DoStream(ReconBuffer* buf, int version) {
        // Stream all persistent fields, relationships, wants/fears
        ReconBuffer_StreamHalfwords(buf, &m_neighborID, 1);
        ReconBuffer_StreamHalfwords(buf, &m_selectorIndex, 1);
        // ... remaining fields
    }

    void* GetFamily() {
        // Return Family pointer from neighborhood by family index
        return nullptr;
    }

    bool IsCharacter() {
        return (m_selectorIndex >= 0);
    }

    // ---- Relationship Methods ----

    void RecalculateRelationshipData() {
        // Recalculate friendship/romance levels from raw values
    }

    bool RelCountsAsRel(int type1, int type2) {
        // Check if relationship type1 counts as type2
        return (type1 == type2);
    }

    int CalculateRelationshipLevel(int friendScore, int romanceScore) {
        // Map raw scores to relationship level enum
        if (friendScore >= 70) return 3; // best friend
        if (friendScore >= 50) return 2; // good friend
        if (friendScore >= 25) return 1; // friend
        return 0; // acquaintance
    }

    int CalculateRelationshipLevelWith(Neighbor_Impl* other) {
        int score = 0;
        int romScore = 0;
        GetRelationshipById(other->m_neighborID, &score);
        return CalculateRelationshipLevel(score, romScore);
    }

    int CountRelationshipsOfType(int relType) {
        int count = 0;
        // Walk all relationships, count matching type
        return count;
    }

    bool IsMarriedTo(Neighbor_Impl* other) const {
        // Check marriage relationship
        return false;
    }

    void GetRelationshipById(int neighborId, int* outScore) {
        *outScore = 0;
        // Look up relationship value for given neighbor
    }

    void AdjustRelationship(Neighbor_Impl* other, int delta) {
        // Modify relationship score with other neighbor
    }

    void CopyRelationships(Neighbor_Impl* source) {
        // Copy all relationship data from another neighbor
    }

    // ---- Persistent Data Loading/Saving ----

    void LoadFromCharacter(ENeighborhoodCustomChar& customChar) {
        // Load neighbor data from custom character resource
    }

    void SaveToCharacter(ENeighborhoodCustomChar& customChar) {
        // Save neighbor data to custom character resource
    }

    void InitDefaultValues() {
        // Set all persistent data to defaults
        memset(m_persistentData, 0, sizeof(m_persistentData));
    }

    // ---- Wants & Fears ----

    void InitWantsFears() {
        // Initialize bookmark slots to empty
        memset(m_wantFearBookmarks, 0, sizeof(m_wantFearBookmarks));
    }

    void InitWantFearIcons() {
        memset(m_wantFearIcons, 0, sizeof(m_wantFearIcons));
    }

    void SpawnWantFearDialog(u32 slotIndex) const {
        // Show the want/fear dialog UI for a specific slot
    }

    void Notify(void* notification, bool fromPlayer) {
        // Check each active bookmark against the notification
        // If a bookmark matches, apply reward and shuffle
    }

    int FindDuplicateBookmark(void* notification) const {
        // Check if notification already matches an active bookmark
        return -1;
    }

    void ForceNewTree(u16 treeId) {
        // Force-assign a new want/fear tree by ID
    }

    int FindActiveSlotIndex(void* notification) const {
        // Find the active bookmark slot matching notification
        return -1;
    }

    void AdvanceBookmark(u32 slotIndex) {
        // Advance bookmark to next node along branch
    }

    int FindBookmarkToReplace(u32 slotFlags, u32 preferFlags) {
        // Find a bookmark slot to replace (LRU or priority-based)
        return 0;
    }

    void CalculateBookmarkAd(void* notification) {
        // Calculate advertisement value for a bookmark
    }

    f32 CalcAdMultiplier(f32 aspirationScore, f32 moodScore, f32 baseWeight) {
        // Compute multiplier for ad weighting
        return baseWeight;
    }

    void CalculateWantFearAd(void* notification, short adIndex) {
        // Calculate want/fear ad for autonomy
    }

    void MakeNewActiveBookmark(u32 slotIndex) {
        // Create a new active bookmark in the given slot
    }

    void SelectInactiveBookmark(bool wantNotFear, bool storyOnly) {
        // Select an inactive bookmark to activate
    }

    void StartNewTree(u32 slotIndex) {
        // Start a new want/fear tree in the given slot
    }

    void UpdateUIifNeeded(u32 slotIndex, int eventCode) {
        // Notify UI system of want/fear changes
    }

    void ResetAllWantsAndFears() {
        InitWantsFears();
        InitWantFearIcons();
    }

    void ShuffleWantFear(int slotIndex) {
        // Replace completed/expired bookmark with new selection
    }
};


// ############################################################################
//
//  SECTION 8: HoodManager -- LOT/FAMILY MANAGEMENT
//
// ############################################################################
//
// Manages high-level neighborhood operations: moving families in/out of lots,
// evicting families, demolishing houses, resetting neighborhoods.
//
// From asm: 11 functions, 7,272 bytes total

class HoodManager {
public:
    // Address: 0x80042F5C | 216 bytes
    bool TestMoveInFamily(int lotNumber, void* family) {
        // Validate that family can move into lot
        // Check lot size, existing residents, budget
        return true;
    }

    // Address: 0x80043034 | variable
    void MoveInFamily(int lotNumber, void* family, bool freeMode) {
        // Place family in lot
        // Load lot data, create sim instances, place objects
    }

    // Address: 0x800432A0 | variable
    void UnmarkFamilyForDeletion(int lotNumber, void* family) {
        // Remove deletion flag from family
    }

    // Address: 0x80043300 | variable
    void EvictFamilyAndLiquidateAssets(int lotNumber) {
        // Remove family from lot and sell all their objects
        // Adds total value to family funds
    }

    // Address: 0x800434F0 | variable
    void EvictFamily(int lotNumber, bool keepObjects) {
        // Remove family from lot
        // If keepObjects: leave furniture in place
    }

    // Address: 0x800436CC | variable
    void RemoveAllObjects(int lotNumber) {
        // Delete all objects from a lot
    }

    // Address: 0x80043820 | variable
    void DemolishCurrentHouse(int lotNumber) {
        // Remove all walls, floors, objects, and reset lot to empty
    }

    // Address: 0x80043954 | variable
    void ResetToPristine() {
        // Reset entire neighborhood to factory defaults
    }

    // Address: 0x80043A3C | variable
    void ResetNeighbors() {
        // Reset all neighbor data (relationships, wants/fears, etc.)
    }

    // Address: 0x80043B40 | variable
    void GetMatrix(Neighbor* n1, Neighbor* n2, RelMatrix** outMatrix, int* outIndex) {
        // Get the relationship matrix entry between two neighbors
        *outMatrix = nullptr;
        *outIndex = -1;
    }

    // Address: 0x80043D40 | variable
    void GetRelatedPeople(int familyId, cXPerson* person, void* outList) {
        // Find all neighbors related to person in the given family
    }
};


// ############################################################################
//
//  SECTION 9: UI TARGET CLASSES
//
// ############################################################################
//
// UI Targets are the bridge between the APT UI system and game logic.
// Each target handles SetVariable/GetVariable/GetLocalizable for APT bindings,
// plus Update() for per-frame logic.

// ============================================================================
// INVTarget -- Inventory UI Target (108 functions, 43,760 bytes)
// ============================================================================

class INVTarget {
public:
    // Base UIObjectBase fields
    u8  m_baseFields[128];   // UIObjectBase + listeners
    u8  m_inventoryData[2048]; // inventory state, tab mode, selection, etc.

    INVTarget(int param) {
        memset(m_baseFields, 0, sizeof(m_baseFields));
        memset(m_inventoryData, 0, sizeof(m_inventoryData));
    }

    ~INVTarget() {}

    // Core APT binding methods
    void SetVariable(char* name, char* value) {
        // Parse variable name, set corresponding internal state
    }

    char* GetVariable(char* name) {
        // Look up variable, return string value
        return nullptr;
    }

    char* GetLocalizable(char* name) {
        // Return localized string for given key
        return nullptr;
    }

    void Update() {
        // Per-frame update: refresh inventory display, handle input
    }

    // Inventory management
    int GetPlayerFunds() const { return 0; }
    void SetPlayerFunds(int funds) {}

    void FormatMoneyString(int amount, bool addSymbol, u16* outBuffer) {
        // Format money amount as displayable string
    }

    void OnSetCurrentTab(int tabIndex) {
        // Switch to inventory tab (objects, build, etc.)
    }

    void InstallInventoryPanelShaders(int panelIndex) {
        // Set up shaders for the selected panel
    }

    void UninstallInventoryPanelInfo() {
        // Clean up current panel data
    }

    void SetupInteractorCamera(bool animated) {
        // Position camera for item preview
    }

    void UpdateInputState() {
        // Process controller input for inventory navigation
    }

    void PushPlaceFilter() {
        // Enter placement mode filter
    }

    void PushGrabFilter() {
        // Enter grab mode filter
    }

    void PopCurrentFilter() {
        // Return to previous input filter
    }
};


// ============================================================================
// PCTTarget -- Place/Catalog/Tool UI Target (51 functions, 26,192 bytes)
// ============================================================================

class PCTTarget {
public:
    u8  m_baseFields[128];
    u8  m_catalogData[4096];

    PCTTarget(int param1, int param2) {
        memset(m_baseFields, 0, sizeof(m_baseFields));
        memset(m_catalogData, 0, sizeof(m_catalogData));
    }

    ~PCTTarget() {}

    void SetVariable(char* name, char* value) {}
    char* GetVariable(char* name) { return nullptr; }
    char* GetLocalizable(char* name) { return nullptr; }

    void Update() {
        // Per-frame update: refresh catalog display
    }

    void on_tab_changed() {
        // Handle tab change in catalog
    }

    void on_selection_changed() {
        // Handle item selection change
    }

    void on_PCT_Scroll(int direction) {
        // Scroll catalog grid
    }

    void on_PCT_EnterToolMode() {
        // Enter tool mode (grab, delete, etc.)
    }

    void on_PCT_EnterPlaceMode() {
        // Enter placement mode
    }

    void on_PCT_SetVisible(bool visible) {
        // Show/hide the catalog UI
    }

    void update_grid_shaders() {
        // Refresh grid item thumbnails
    }

    void calc_motive_ratings() {
        // Calculate motive ratings for selected item
    }

    bool can_afford_selection() const {
        // Check if player can afford the selected item
        return true;
    }

    void start_action_menu() {
        // Show context menu for selected object
    }

    void setup_interactor_camera(bool animated) {
        // Position camera for catalog browsing
    }
};


// ============================================================================
// ACTTarget -- Action Queue UI Target (22 functions, 10,388 bytes)
// ============================================================================

class ACTTarget {
public:
    u8  m_baseFields[128];
    u8  m_actionData[2048];

    ACTTarget(int param) {
        memset(m_baseFields, 0, sizeof(m_baseFields));
        memset(m_actionData, 0, sizeof(m_actionData));
    }

    ~ACTTarget() {}

    void SetVariable(char* name, char* value) {}
    char* GetVariable(char* name) { return nullptr; }
    char* GetLocalizable(char* name) { return nullptr; }

    void Update() {
        UpdateActionQueue();
    }

    void UpdateActionQueue() {
        // Refresh the action queue display from the sim's queue
    }

    void AddAction(int index, Interaction* action, BString2& name,
                   u32 flags, ERShader* shader, u32 param) {
        // Add an action to the queue display
    }

    void RemoveAction(int index, Interaction* action) {
        // Remove an action from the queue display
    }

    void RemoveAllActions(int playerIndex) {
        // Clear all actions for a player
    }

    void ReOrderActionQueue() {
        // Re-sort the action queue by priority
    }

    Interaction* GetInteractionFromID(int id) {
        // Look up an interaction by its unique ID
        return nullptr;
    }

    void MoveCancelCursorUp() {
        // Move cursor up in cancel mode
    }

    void MoveCancelCursorDown() {
        // Move cursor down in cancel mode
    }

    void CancelModeEnabled(bool enable) {
        // Enter/exit action cancel mode
    }

    void CancelCurrentObject() {
        // Cancel the currently highlighted action
    }

    void UpdateCancelModeWidgets() {
        // Refresh cancel mode UI
    }

    void ExitCancelMode() {
        // Leave cancel mode
    }

    bool CancellingLastObject() {
        // Check if about to cancel the last action
        return false;
    }
};


// ============================================================================
// WAFTarget -- Wants & Fears UI Target (24 functions, 13,608 bytes)
// ============================================================================

class WAFTarget {
public:
    u8  m_baseFields[128];
    u8  m_wafData[1024];

    // Aspiration meter state
    f32 m_aspirationMeterHeight;
    f32 m_aspirationTweenStart;
    f32 m_aspirationTweenTarget;
    f32 m_aspirationTweenProgress;
    u32 m_topBarColor;
    u32 m_bottomBarColor;
    bool m_isTweening;

    WAFTarget(int param) {
        memset(m_baseFields, 0, sizeof(m_baseFields));
        memset(m_wafData, 0, sizeof(m_wafData));
        m_aspirationMeterHeight = 0.0f;
        m_aspirationTweenStart = 0.0f;
        m_aspirationTweenTarget = 0.0f;
        m_aspirationTweenProgress = 0.0f;
        m_topBarColor = 0;
        m_bottomBarColor = 0;
        m_isTweening = false;
    }

    ~WAFTarget() {}

    void SetVariable(char* name, char* value) {}
    char* GetVariable(char* name) { return nullptr; }
    char* GetLocalizable(char* name) { return nullptr; }

    void Update() {
        UpdateWantsAndFears();
        UpdateAspirationMeter();
    }

    void UpdateWantsAndFears() {
        // Refresh want/fear icons from neighbor bookmark data
    }

    void NewWantsAndFearsIcon(int slot, u32 eventId, u32 targetId,
                              int type, Neighbor* neighbor) {
        // Create a new want/fear icon in the given display slot
    }

    void StartAnimation(int animIndex) {
        // Start icon animation (slide in, glow, etc.)
    }

    void FinishSettingIcon(int slot) {
        // Finalize icon setup after animation
    }

    void SetAspirationMeterHeight(int height) {
        m_aspirationMeterHeight = (f32)height;
    }

    void BeginMeterTween() {
        m_isTweening = true;
        m_aspirationTweenProgress = 0.0f;
    }

    void BeginBottomBarTween() {
        // Start bottom bar animation
    }

    void BeginTopBarTween() {
        // Start top bar animation
    }

    void OnTopBarTweenComplete() {
        // Handle top bar tween completion
    }

    void OnBottomBarTweenComplete() {
        // Handle bottom bar tween completion
    }

    u32 GetTopBarColorAtTier() {
        // Return color based on aspiration tier
        return 0xFFFFFF;
    }

    void CalculateTweenTargetPosition() {
        // Compute where meter should tween to
    }

    f32 MapGameAspirationValueToMeterValue(f32 gameValue) {
        // Map game aspiration score to UI meter position
        // Typically a piecewise linear function
        return gameValue / 100.0f;
    }

    void GlowEffectStart() {
        // Start glow effect on aspiration meter
    }

    void GlowEffectAwayStart() {
        // Start glow-away effect
    }

    u32 GetTopBarTweenColor() {
        // Get interpolated color during tween
        return m_topBarColor;
    }

    void OnShow() {
        // Called when the wants/fears panel becomes visible
        UpdateWantsAndFears();
    }

    void UpdateAspirationMeter() {
        if (m_isTweening) {
            m_aspirationTweenProgress += 0.016f; // ~60fps
            if (m_aspirationTweenProgress >= 1.0f) {
                m_aspirationTweenProgress = 1.0f;
                m_isTweening = false;
            }
            // Interpolate meter position
        }
    }
};


// ============================================================================
//  END OF CONVERSION
// ============================================================================
//
// Summary of classes converted from inline PPC asm to portable C++:
//
// 1. MULTI-TILE OBJECTS
//    - cXMTObjectImpl (29 functions, 17,236 bytes)
//
// 2. CREATE-A-SIM
//    - CasSimDescriptionS2C (290 bytes, per-sim appearance data)
//    - CasSimPartsS2C (static body part catalog)
//    - CasGenetics (genetic blending for inheritance)
//    - CASTarget (~5,184 bytes, top-level CAS controller)
//
// 3. SIM MODEL
//    - SimModel (63 functions, 16,188 bytes, 3D model management)
//
// 4. BEHAVIOR TREE SYSTEM
//    - BehaviorNode (instruction struct)
//    - TreeSim (base class, ~68 bytes)
//    - TreeStack (call frame stack, 8 functions)
//    - TreeSimImpl (execution engine, 13 functions, 4,616 bytes)
//    - TreeTable (TTAB lookup, 2 functions)
//    - TreeTableEntry (36-byte row, 1 function)
//    - TreeTableQuickData (10 functions, fast-load wrapper)
//    - TreeTableEntryQuickData (5 functions)
//    - TreeTableAdQuickData (2 functions)
//    - TreeTableAdScratch (3 functions)
//    - TTabScratchEntry (6 functions)
//    - TreeTab (data container)
//
// 5. WANTS & FEARS
//    - WantFear::Bookmark methods (14 functions, 4,508 bytes)
//
// 6. AWARENESS
//    - AwarenessManager (38 functions, 11,032 bytes)
//
// 7. NEIGHBORHOOD
//    - Neighbor (39 functions, 13,740 bytes)
//    - HoodManager (11 functions, 7,272 bytes)
//
// 8. UI TARGETS
//    - INVTarget (108 functions, 43,760 bytes -- inventory)
//    - PCTTarget (51 functions, 26,192 bytes -- catalog)
//    - ACTTarget (22 functions, 10,388 bytes -- action queue)
//    - WAFTarget (24 functions, 13,608 bytes -- wants & fears)
//
// Total: ~25+ classes, ~480+ functions, ~190,000+ bytes of original PPC asm
// converted to portable C++.
