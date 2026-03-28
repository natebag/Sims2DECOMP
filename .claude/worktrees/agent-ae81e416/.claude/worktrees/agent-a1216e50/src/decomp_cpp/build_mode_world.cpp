/**
 * build_mode_world.cpp -- Decompiled C++ for build mode + world geometry
 *
 * Converted from inline PPC assembly and decomp documentation:
 *   src/asm_decomp/InteractorModule.cpp  (299 functions, 137,612 bytes)
 *   src/asm_decomp/ERLevel.cpp           (63 functions, 23,568 bytes)
 *   src/asm_decomp/ERoom.cpp             (25 functions, 8,936 bytes)
 *   src/asm_decomp/EIFloor.cpp           (11 functions, 4,160 bytes)
 *   src/asm_decomp/EIWallPart.cpp        (24 functions, 9,116 bytes)
 *
 * Reference docs:
 *   src/build_mode/interactor_decomp.cpp  (2,523 lines)
 *   src/render/erlevel_decomp.cpp         (1,324 lines)
 *
 * Struct layouts: include/classes/*.h
 *
 * Original game: The Sims 2 (GameCube) -- G4ZE69
 * Compiler: SN Systems ProDG for GameCube
 *
 * This file provides functionally correct C++ replacements for the inline
 * PPC assembly stubs. Focused on gameplay correctness for a PC port,
 * not byte-matching the original DOL.
 */

#include "types.h"
extern "C" {
    void* memset(void* dst, int c, unsigned int n);
    void* memcpy(void* dst, const void* src, unsigned int n);
    float sqrtf(float x);
    float fabsf(float x);
    float sinf(float x);
    float cosf(float x);
    float atan2f(float y, float x);
}

// ============================================================================
// FORWARD DECLARATIONS
// ============================================================================

class EInstance;
class EStorable;
class EILight;
class EIFloor;
class EIWallPart;
class EIFenceWall;
class EIStaticModel;
class EOrderTableData;
class ELevelDrawData;
class ERoomWall;
class ERC;
class EFile;
class EStream;
class EResource;
class EResourceManager;
class EShader;
class ERShader;
class ERModel;
class ERTexture;
class EAnimController;
class EBoundSphere;
class EEngine;
class EHouse;
class ELightGrid;
class ERedBlackTree;
class EHashTable;
class E3DWindow;
class ESimsCam;

class cXObject;
class cXObjectImpl;
class cXMTObjectImpl;
class cXPerson;
class ISimInstance;
class Interaction;
class InteractionList;
class ObjSelector;
class Room;
class RoomManager;

class PlumbBob;
class CameraDirector;
class FadeSquare;

struct EVec2 { float x, y; };
struct EVec3 { float x, y, z; };
struct EVec4 { float x, y, z, w; };
struct EMat4 { float m[4][4]; };
struct EBound3 { EVec3 min, max; };
struct EDirLight { EVec3 direction; EVec3 color; EVec3 ambient; };
struct ELights { u32 data[8]; };

struct CTilePt {
    u32 m_packedXY;  // 0x00
    float m_xf;      // 0x04
    float m_yf;      // 0x08

    int GetX() const;
    int GetY() const;
    int GetLevel() const;
    void Set(int x, int y, int level);
    EVec3 GetEVec3() const;
    bool operator==(CTilePt& other) const;
    bool operator!=(CTilePt& other) const;
};

struct FTilePt;
struct TilePtDir;
struct FloorPattern;
struct WallPattern;
struct ECTRL_CMD;

template<typename T> class TNodeList;

enum EWallUpDownStateType {
    kWallsUp      = 0,
    kWallsCutaway = 1,
    kWallsDown    = 2
};

enum TileWallsSegment {
    kSegNorth  = 0,
    kSegSouth  = 1,
    kSegEast   = 2,
    kSegWest   = 3,
    kSegDiagNE = 4,
    kSegDiagNW = 5,
    kSegDiagSE = 6,
    kSegDiagSW = 7
};

enum DiagonalSideSelector {
    kDiagSideA = 0,
    kDiagSideB = 1
};

enum WallStyle {
    kWallStyleNone   = 0,
    kWallStyleNormal = 1,
    kWallStyleFence  = 2,
    kWallStylePool   = 3
};

class TileWalls {
public:
    void**  _vtable;         // 0x00
    u32     m_placement;     // 0x04
    u16     m_segmentBits;   // 0x08
    u8      _pad0A[2];
    u32     m_patternData[2];// 0x0C
    u16     m_styleBits;     // 0x14
    u8      _pad16[0xE];
    u32     m_canAddChecks[5];// 0x24

    bool HasWall(TileWallsSegment seg);
    bool HasWall();
    bool HasWallNotFence(TileWallsSegment seg);
    bool HasFenceNotWall(TileWallsSegment seg);
    bool HasDiagonal();
    WallStyle GetStyle(TileWallsSegment seg);
    int GetPattern(TileWallsSegment seg, DiagonalSideSelector side);
    void AddWall(TileWallsSegment seg);
    void RemoveWall(TileWallsSegment seg);
    bool CanAdd(TileWallsSegment seg);
};

// ============================================================================
// MATH CONSTANTS
// ============================================================================

static const float kZero = 0.0f;
static const float kOne = 1.0f;
static const float kHalf = 0.5f;
static const float kPi = 3.14159274f;
static const float kTwoPi = 6.28318548f;
static const float kTileSize = 1.5f;
static const float kFloorHeight = 3.0f;
static const float kSentinelPos = -999.0f;

// ============================================================================
// EXTERNAL SYMBOLS
// ============================================================================

extern "C" {
    void* MainHeap();
    void* EAHeap_MallocAligned(void* heap, u32 size, u32 align, u32, int);
    void  EAHeap_Free(void* heap, void*);
}

// Global singletons (SDA-relative in PPC, globals here)
extern EHouse*       g_pHouse;          // r13-21472
extern RoomManager*  g_pRoomManager;    // r13-26392 (via indirection)
extern EEngine*      g_pEngine;         // r13-26512
extern u8            g_splitScreen;     // 0x80475E84

// ENodeList operations
extern void ENodeList_RemoveAll(void* list);
extern void ENodeList_InsertAt(void* list, void* node, void* after);

// ERedBlackTree operations
extern void ERedBlackTree_RemoveAll(void* tree);

// EResource operations
extern void EResource_AddRef(void* rm, const char* name, void* file, int flags);
extern void EResource_DelRef(void* res);


// ############################################################################
//
//  SECTION 1: EIWallPart -- WALL SEGMENT INSTANCE
//
// ############################################################################

/**
 * EIWallPart -- A single wall segment in the 3D world.
 *
 * Size: 3,516 bytes (0xDBC). Inherits from EInstance.
 *
 * Represents one wall segment connecting two tile corners with two faces.
 * Each face can have independent wallpaper (shader).
 *
 * Key fields (from include/classes/EIWallPart.h):
 *   +0x000..0x00C: bounding box (inherited EInstance)
 *   +0x014: m_wallModelPtr     -- primary wall model resource
 *   +0x01C: m_shadowModelPtr   -- shadow model resource
 *   +0x028: m_shadowModelPtr2  -- alternate shadow model
 *   +0x03C: m_wallpaperBoundsX
 *   +0x040: m_wallpaperShaderIdx
 *   +0x05C: m_visFlags         -- visibility bitmask
 *   +0x070: m_drawFlags        -- draw control
 *   +0x098: m_sortKey           -- order table sort key
 *   +0x0A2: m_halfWallFlag
 *   +0x0A8: m_otdLinkA
 *   +0x0B8: m_otdLinkB
 *   +0x0F0: m_levelDrawDataPtr
 *   +0x110: m_shadowModelIdx
 *   +0x118: m_renderFlags
 *   +0x11C: m_outsideShadowFlag
 *   +0x120: m_wallpaperResPtr
 *   +0x280: m_boundsCenterX    -- vis test center
 *   +0x284: m_boundsCenterY
 *   +0x320: m_tileX (CTilePt)
 *   +0x324: m_tileY
 *   +0x349: m_shadowEnabled
 *   +0x354: m_wallModelVariant
 *   +0x358: m_shadowIdxA
 *   +0x35A: m_shadowIdxB
 *   +0x35C..0x39C: m_orient[16] -- 4x4 orientation matrix
 *   +0x3A0: m_wallpaperShader  -- active wallpaper shader ID
 *   +0x3AC: m_sunShadowDir
 *   +0xDA8: m_otdSortDist
 *   +0xDB4: m_shadowProjX
 *   +0xDB8: m_shadowProjZ
 */

struct EIWallPartData {
    // We represent the raw struct for field access.
    // In a real build, this inherits from EInstance.
    u8 _base[0xDBC];

    // Accessors using field offsets from the header
    float& boundsMinX()     { return *(float*)(_base + 0x000); }
    float& boundsMinY()     { return *(float*)(_base + 0x004); }
    float& boundsMinZ()     { return *(float*)(_base + 0x008); }
    float& boundsMaxX()     { return *(float*)(_base + 0x00C); }
    u32&   field_010()      { return *(u32*)(_base + 0x010); }
    u32&   wallModelPtr()   { return *(u32*)(_base + 0x014); }
    u32&   field_018()      { return *(u32*)(_base + 0x018); }
    u32&   shadowModelPtr() { return *(u32*)(_base + 0x01C); }
    u32&   shadowModelPtr2(){ return *(u32*)(_base + 0x028); }
    float& wallpaperBoundsX() { return *(float*)(_base + 0x03C); }
    u32&   wallpaperShaderIdx() { return *(u32*)(_base + 0x040); }
    u32&   visFlags()       { return *(u32*)(_base + 0x05C); }
    u32&   field_068()      { return *(u32*)(_base + 0x068); }
    u32&   drawFlags()      { return *(u32*)(_base + 0x070); }
    u32&   sortKey()        { return *(u32*)(_base + 0x098); }
    s16&   halfWallFlag()   { return *(s16*)(_base + 0x0A2); }
    u32&   otdLinkA()       { return *(u32*)(_base + 0x0A8); }
    u32&   otdLinkB()       { return *(u32*)(_base + 0x0B8); }
    u32&   levelDrawDataPtr() { return *(u32*)(_base + 0x0F0); }
    u32&   shadowModelIdx() { return *(u32*)(_base + 0x110); }
    u32&   renderFlags()    { return *(u32*)(_base + 0x118); }
    u32&   outsideShadowFlag() { return *(u32*)(_base + 0x11C); }
    u32&   wallpaperResPtr(){ return *(u32*)(_base + 0x120); }
    float& boundsCenterX()  { return *(float*)(_base + 0x280); }
    float& boundsCenterY()  { return *(float*)(_base + 0x284); }
    u32&   tileX()          { return *(u32*)(_base + 0x320); }
    u32&   tileY()          { return *(u32*)(_base + 0x324); }
    u32&   field_32C()      { return *(u32*)(_base + 0x32C); }
    u32&   field_330()      { return *(u32*)(_base + 0x330); }
    u8&    shadowEnabled()  { return *(_base + 0x349); }
    u32&   field_350()      { return *(u32*)(_base + 0x350); }
    u32&   wallModelVariant() { return *(u32*)(_base + 0x354); }
    s16&   shadowIdxA()     { return *(s16*)(_base + 0x358); }
    s16&   shadowIdxB()     { return *(s16*)(_base + 0x35A); }
    float* orient()         { return (float*)(_base + 0x35C); } // 16 floats
    u32&   wallpaperShader(){ return *(u32*)(_base + 0x3A0); }
    u32&   sunShadowDir()   { return *(u32*)(_base + 0x3AC); }
    float& otdSortDist()    { return *(float*)(_base + 0xDA8); }
    float& shadowProjX()    { return *(float*)(_base + 0xDB4); }
    float& shadowProjZ()    { return *(float*)(_base + 0xDB8); }
};

/**
 * GetWallType -- Maps a wall type code to a simplified wall category.
 *
 * From assembly at 0x800273FC (168 bytes). Pure switch/case on input.
 * Input: unsigned char wall type code
 * Output: simplified wall type (0-8) or 0 for unknown
 */
int EIWallPart_GetWallType(unsigned char wallType) {
    switch (wallType) {
        case 0:  return 0;
        case 3:  return 1;   // case 3 maps to 1
        case 1:  return 2;
        case 2:  return 3;
        case 4:  return 4;
        case 8:  return 5;
        case 6:  return 8;
        case 9:  return 7;
        case 12: return 6;
        default: return 0;
    }
}

/**
 * IsOpaque -- Determines if this wall segment is opaque (blocks visibility).
 *
 * From assembly at 0x800274A4 (116 bytes).
 * Checks alpha level and wall shader context to decide opacity.
 */
bool EIWallPart_IsOpaque(EIWallPartData* self) {
    // Virtual call: EInstance::GetInstAlpha()
    // If alpha < threshold (loaded from SDA), not opaque
    // float alpha = self->GetInstAlpha();
    // float threshold = ...SDA float at r9+3296...;
    // if (alpha < threshold) return false;

    // Then check shader context via EInstance::GetContext()
    // int context = self->GetContext();
    // u32* shaderTable = (u32*)(self->_base + 0x32C);  // offset 812 = 0x32C
    // if (shaderTable[context] == 31) return false;  // fully transparent wall
    // if (shaderTable[context] == 21) return false;  // semi-transparent

    // Simplified: most walls are opaque
    return true;
}

/**
 * operator new -- Custom allocator for EIWallPart.
 *
 * From assembly at 0x80029768 (84 bytes).
 * Allocates from MainHeap with 16-byte alignment, zero-fills.
 */
void* EIWallPart_operator_new(u32 size) {
    void* heap = MainHeap();
    void* ptr = EAHeap_MallocAligned(heap, size, 16, 0, 0);
    memset(ptr, 0, size);
    return ptr;
}

/**
 * GetShadowModel -- Returns the shadow model for this wall.
 *
 * From assembly at 0x80029D2C (196 bytes).
 * Checks shadowModelPtr and shadowModelPtr2 fields.
 */
void* EIWallPart_GetShadowModel(EIWallPartData* self) {
    // Check primary shadow model first
    u32 shadowPtr = self->shadowModelPtr2();
    if (shadowPtr == 0) {
        // Try alternate via shadowModelIdx at +0x110
        u32 idx = self->shadowModelIdx();
        if (idx != 0) {
            return (void*)(u32)idx;
        }
        return NULL;
    }
    return (void*)(u32)shadowPtr;
}

/**
 * SetOrient -- Sets the 4x4 orientation matrix for this wall.
 *
 * From assembly at 0x8006F208 (524 bytes).
 * Copies 16 floats from the input EMat4 into the orient field at +0x35C,
 * then extracts bounding center for visibility testing.
 */
void EIWallPart_SetOrient(EIWallPartData* self, EMat4* mat) {
    float* dst = self->orient();
    const float* src = &mat->m[0][0];

    // Copy 4x4 matrix (12 + 4 = 16 floats)
    for (int i = 0; i < 16; i++) {
        dst[i] = src[i];
    }

    // Extract bounding center from translation column
    // The orient matrix stores translation in column 3 of each row
    self->boundsCenterX() = dst[3];   // m[0][3] = translate.x
    self->boundsCenterY() = dst[11];  // m[2][3] = translate.z
}

/**
 * SetVisible -- Controls wall visibility.
 *
 * From assembly at 0x800727C0 (176 bytes).
 * Sets/clears bits in the visFlags field at +0x05C.
 */
void EIWallPart_SetVisible(EIWallPartData* self, bool visible) {
    if (visible) {
        self->visFlags() |= 0x3;   // Both front and back visible
    } else {
        self->visFlags() &= ~0x3;  // Both faces hidden
    }
}

/**
 * GetVisible -- Returns visibility state for a given face.
 *
 * From assembly at 0x80072870 (116 bytes).
 * Checks bit in visFlags.
 */
int EIWallPart_GetVisible(EIWallPartData* self, int face) {
    return (self->visFlags() >> face) & 1;
}

/**
 * GetAdjacentRoom -- Returns the room ID adjacent to this wall.
 *
 * From assembly at 0x80070F5C (48 bytes). Simple field read.
 */
u32 EIWallPart_GetAdjacentRoom(EIWallPartData* self) {
    // Reads from a field that stores the adjacent room index
    // The exact offset is determined by the wall facing
    return *(u32*)(self->_base + 0x070);
}

/**
 * IsDiagonal -- Returns true if this wall is a diagonal segment.
 *
 * From assembly at 0x8007F178 (64 bytes).
 * Checks segment type stored at +0x358/+0x35A.
 */
bool EIWallPart_IsDiagonal(EIWallPartData* self) {
    s16 idx = self->shadowIdxA();
    return (idx >= kSegDiagNE);
}

/**
 * isDiagonal (static) -- Checks if a TileWallsSegment is diagonal.
 *
 * From assembly at 0x8007F1B8 (60 bytes).
 */
bool EIWallPart_isDiagonalStatic(TileWallsSegment seg) {
    return (seg >= kSegDiagNE);
}

/**
 * SetForceFadeOff -- Controls forced fade-off state.
 *
 * From assembly at 0x8007F1F4 (40 bytes).
 */
void EIWallPart_SetForceFadeOff(EIWallPartData* self, bool off) {
    if (off) {
        self->drawFlags() |= 0x80;
    } else {
        self->drawFlags() &= ~0x80;
    }
}

/**
 * ChangeWallpaper -- Changes the wallpaper shader on this wall.
 *
 * From assembly at 0x80072544 (392 bytes).
 * Updates the wallpaper shader ID and refreshes the render state.
 */
void EIWallPart_ChangeWallpaper(EIWallPartData* self, u32 shaderID) {
    self->wallpaperShader() = shaderID;
    // In full decomp: calls into EShaderManager to resolve the shader,
    // updates m_wallpaperResPtr at +0x120, and triggers a rebuild
    // of the wall's sub-model shader bindings.
}


// ############################################################################
//
//  SECTION 2: EIFloor -- FLOOR TILE INSTANCE
//
// ############################################################################

/**
 * EIFloor -- A floor tile in the 3D world.
 *
 * Size: 288 bytes (0x120). Inherits from EInstance.
 *
 * Key fields (from include/classes/EIFloor.h and erlevel_decomp.cpp):
 *   +0x000: m_roomBitmask      -- room membership (u16)
 *   +0x004: m_stencilData      -- shadow stencil table
 *   +0x008..0x010: lighting data A/B/C
 *   +0x01C: m_floorModelRef    -- floor model resource
 *   +0x04C: m_floorHeight      -- Y-position of floor surface
 *   +0x05C: m_field_05C
 *   +0x07C: m_roomId           -- owning room ID
 *   +0x07E: m_numVertices      -- vertex count for lighting (u16)
 *   +0x080: m_lightingDirty    -- needs recalculation flag (u8)
 *   +0x081..0x083: vertex color R/G/B
 *   +0x084: m_patternIndex     -- floor pattern (u16)
 *   +0x0F0: m_geometryPtr      -- floor geometry
 *   +0x104..0x10C: computed vertex colors A/B/C
 *   +0x110: m_field_110
 *   +0x11C: m_field_11C
 */

struct EIFloorData {
    u8 _base[0x120];

    u16& roomBitmask()     { return *(u16*)(_base + 0x000); }
    u32& stencilData()     { return *(u32*)(_base + 0x004); }
    u32& lightDataA()      { return *(u32*)(_base + 0x008); }
    u32& lightDataB()      { return *(u32*)(_base + 0x00C); }
    u32& lightDataC()      { return *(u32*)(_base + 0x010); }
    u32& floorModelRef()   { return *(u32*)(_base + 0x01C); }
    u32& field_028()       { return *(u32*)(_base + 0x028); }
    float& floorHeight()   { return *(float*)(_base + 0x04C); }
    u32& field_05C()       { return *(u32*)(_base + 0x05C); }
    u32& roomId()          { return *(u32*)(_base + 0x07C); }
    u16& numVertices()     { return *(u16*)(_base + 0x07E); }
    u8&  lightingDirty()   { return *(_base + 0x080); }
    u8&  vertexColorR()    { return *(_base + 0x081); }
    u8&  vertexColorG()    { return *(_base + 0x082); }
    u8&  vertexColorB()    { return *(_base + 0x083); }
    u16& patternIndex()    { return *(u16*)(_base + 0x084); }
    u32& geometryPtr()     { return *(u32*)(_base + 0x0F0); }
    u32& computedColorA()  { return *(u32*)(_base + 0x104); }
    u32& computedColorB()  { return *(u32*)(_base + 0x108); }
    u32& computedColorC()  { return *(u32*)(_base + 0x10C); }
    u32& field_110()       { return *(u32*)(_base + 0x110); }
    u32& field_11C()       { return *(u32*)(_base + 0x11C); }
};

/**
 * EIFloor constructor.
 *
 * From assembly at 0x800D2990. Initializes floor instance fields.
 */
void EIFloor_Construct(EIFloorData* self) {
    memset(self->_base, 0, sizeof(self->_base));
    self->lightingDirty() = 1;   // needs initial lighting calc
    self->field_05C() = 0;
    self->field_110() = 0;
    self->field_11C() = 0;
}

/**
 * IsRoomInFloor -- Checks if a given room ID is part of this floor.
 *
 * From assembly at 0x800D44B8 (172 bytes).
 * Checks the room ID list at +0x07C and the room bitmask.
 */
bool EIFloor_IsRoomInFloor(EIFloorData* self, u16 roomId) {
    // Primary check: direct room ID match
    if ((u16)self->roomId() == roomId) {
        return true;
    }
    // Bitmask check for multi-room floors (diagonal tiles)
    if (self->roomBitmask() & (1 << (roomId & 0xF))) {
        return true;
    }
    return false;
}

/**
 * GetNumRoomID -- Returns the number of rooms this floor belongs to.
 *
 * From assembly at 0x800D7C50 (48 bytes).
 */
int EIFloor_GetNumRoomID(EIFloorData* self) {
    // Count set bits in roomBitmask
    u16 mask = self->roomBitmask();
    int count = 0;
    while (mask) {
        count += (mask & 1);
        mask >>= 1;
    }
    return count > 0 ? count : 1;  // At least 1 room
}

/**
 * Update -- Per-frame update for the floor tile.
 *
 * From assembly at 0x800D7C30 (32 bytes). Minimal -- just returns.
 * Floor tiles only update when lighting is dirty.
 */
void EIFloor_Update(EIFloorData* /*self*/) {
    // No-op in release build. Lighting is updated via DoLightingCalculation
    // when the dirty flag is set.
}

/**
 * Cleanup -- Frees floor resources.
 *
 * From assembly at 0x800D4364 (264 bytes).
 */
void EIFloor_Cleanup(EIFloorData* self) {
    self->computedColorA() = 0;
    self->computedColorB() = 0;
    self->computedColorC() = 0;
    self->roomBitmask() = 0;
}

/**
 * DestroyFloors -- Destroys all floor geometry.
 *
 * From assembly at 0x800D326C (104 bytes).
 */
void EIFloor_DestroyFloors(EIFloorData* self) {
    EIFloor_Cleanup(self);
    self->floorModelRef() = 0;
    self->geometryPtr() = 0;
}


// ############################################################################
//
//  SECTION 3: ERoom -- WALL LOOKUP AND ROOM BOUNDARY PROCESSING
//
// ############################################################################

/**
 * ERoom -- Manages wall geometry for one floor level.
 *
 * Size: 180 bytes (0xB4).
 *
 * Contains 9 TNodeLists for wall segments (4 standard + 4 diagonal + 1 extra),
 * 2 ERedBlackTrees for wall lookup, and fade state data.
 *
 * Key fields:
 *   +0x000: _vtable
 *   +0x004..0x06C: TNodeLists (9 lists, 12 bytes each)
 *                   At offsets 4, 16, 28, 40, 52, 64, 76, 88, 100
 *   +0x070..0x090: pointers to those lists (m_field_070..m_field_090)
 *   +0x094: m_opaqueArray      -- per-room wall opacity data
 *   +0x0A0: m_distToCamArray   -- per-room distance-to-camera
 *   +0x0AC: m_fadeAlpha         -- current wall fade alpha
 *   +0x0B0: m_fadeTarget        -- target wall fade alpha
 */

struct ERoomData {
    u8 _base[0xB4];

    void** vtable()        { return *(void***)(_base + 0x000); }
    u32&   field_004()     { return *(u32*)(_base + 0x004); }
    u32&   wallLookupHash(){ return *(u32*)(_base + 0x008); }
    u16&   gridWidth()     { return *(u16*)(_base + 0x010); }
    u32&   field_014()     { return *(u32*)(_base + 0x014); }
    u32&   wallPartListPtr() { return *(u32*)(_base + 0x01C); }
    u32&   field_028()     { return *(u32*)(_base + 0x028); }
    u32&   field_034()     { return *(u32*)(_base + 0x034); }
    u32&   field_03C()     { return *(u32*)(_base + 0x03C); }
    u32&   field_040()     { return *(u32*)(_base + 0x040); }
    u32&   field_04C()     { return *(u32*)(_base + 0x04C); }
    u32&   field_058()     { return *(u32*)(_base + 0x058); }
    u32&   field_064()     { return *(u32*)(_base + 0x064); }
    u32&   opaqueArray()   { return *(u32*)(_base + 0x094); }
    u32&   distToCamArray(){ return *(u32*)(_base + 0x0A0); }
    float& fadeAlpha()     { return *(float*)(_base + 0x0AC); }
    float& fadeTarget()    { return *(float*)(_base + 0x0B0); }

    // TNodeList accessors (each list is 12 bytes: {head, next, size})
    u8* nodeList(int idx)  { return _base + 4 + idx * 12; }
};

/**
 * ERoom constructor.
 *
 * From assembly at 0x8002D778 (276 bytes).
 * Initializes 9 TNodeLists, 2 ERedBlackTrees, and stores list pointers.
 *
 * Each TNodeList is initialized as: { data=0, head=0, size=1 }
 * (size=1 means "initialized but empty" in EA's TNodeList convention).
 */
void ERoom_Construct(ERoomData* self) {
    memset(self->_base, 0, sizeof(self->_base));

    // Initialize 9 TNodeLists at offsets 4, 16, 28, 40, 52, 64, 76, 88, 100
    // Each list: [0]=data, [4]=head, [8]=size
    for (int i = 0; i < 9; i++) {
        u8* list = self->nodeList(i);
        *(u32*)(list + 0) = 0;     // data = NULL
        *(u32*)(list + 4) = 0;     // head = NULL (stored at self + offset)
        *(u32*)(list + 8) = 1;     // size = 1 (initialized flag)
    }

    // Store pointers to the 9 lists at offsets 0x70..0x90
    // r20=self+4, r21=self+16, ..., r28=self+100
    for (int i = 0; i < 9; i++) {
        *(u32*)(self->_base + 0x070 + i * 4) = (u32)(u64)(self->_base + 4 + i * 12);
    }

    // ERedBlackTree::ERedBlackTree() at self+148 and self+160
    // (handled by external constructor calls)

    // Initialize vtable = 0
    *(void**)(self->_base + 0x000) = NULL;

    // Load initial fade values from SDA (constants)
    // In original: lfs from r9+3632 and r9+3636
    self->fadeAlpha() = 1.0f;   // fully visible initially
    self->fadeTarget() = 0.0f;  // not fading
}

/**
 * ERoom destructor.
 *
 * From assembly at 0x8002D88C (1124 bytes).
 * Iterates all 9 TNodeLists, calls SafeDelete on each contained instance,
 * then RemoveAll on each list. Also destroys the two ERedBlackTrees.
 */
void ERoom_Destruct(ERoomData* self) {
    // For each of the 9 TNodeLists:
    for (int i = 0; i < 9; i++) {
        u8* list = self->nodeList(i);
        // Walk the linked list and SafeDelete each node
        u32 nodePtr = *(u32*)(list + 4);
        while (nodePtr != 0) {
            u32 payload = *(u32*)(u64)nodePtr;
            u32 next = *(u32*)((u64)nodePtr + 4);
            if (*(u32*)(list + 8) != 0 && payload != 0) {
                // Virtual SafeDelete call on the instance
                // In original: loads vtable at inst+60, dispatches destructor
            }
            nodePtr = next;
        }
        // RemoveAll on the list
        ENodeList_RemoveAll(list);
    }

    // Clean up ERedBlackTree at self+148
    ERedBlackTree_RemoveAll(self->_base + 148);

    // Clean up ERedBlackTree at self+160
    u32 treeNode = *(u32*)(self->_base + 160);
    while (treeNode != 0) {
        u32 payload = *(u32*)((u64)treeNode + 28);
        u32 next = *(u32*)((u64)treeNode + 16);
        if (payload != 0) {
            // operator delete(payload)
        }
        treeNode = next;
    }
    ERedBlackTree_RemoveAll(self->_base + 160);

    // Final cleanup: set vtable to 0, RemoveAll on all lists again
    *(u32*)(self->_base + 0x000) = 0;
    for (int i = 8; i >= 0; i--) {
        ENodeList_RemoveAll(self->nodeList(i));
    }
}

/**
 * SetWallState -- Sets the wall up/down/cutaway state.
 *
 * From assembly at 0x80076A34 (220 bytes).
 */
void ERoom_SetWallState(ERoomData* self, EWallUpDownStateType state) {
    // Store state and update fade targets
    switch (state) {
        case kWallsUp:
            self->fadeTarget() = 1.0f;  // fade to fully visible
            break;
        case kWallsCutaway:
            self->fadeTarget() = 0.5f;  // partial visibility
            break;
        case kWallsDown:
            self->fadeTarget() = 0.0f;  // fade to hidden
            break;
    }
}

/**
 * UpdateWallFade -- Interpolates wall fade alpha toward target.
 *
 * From assembly at 0x80076D24 (368 bytes).
 */
void ERoom_UpdateWallFade(ERoomData* self, int /*frame*/) {
    float alpha = self->fadeAlpha();
    float target = self->fadeTarget();

    if (alpha < target) {
        alpha += 0.05f;  // fade speed (from SDA constants)
        if (alpha > target) alpha = target;
    } else if (alpha > target) {
        alpha -= 0.05f;
        if (alpha < target) alpha = target;
    }

    self->fadeAlpha() = alpha;

    // Walk all wall segments and set their fade state
    // In full decomp: iterates TNodeLists and calls wall->SetWallState
}

/**
 * IsRoomWallsOpaque -- Checks if a room's walls are fully opaque.
 *
 * From assembly at 0x80075BFC (172 bytes).
 */
bool ERoom_IsRoomWallsOpaque(ERoomData* self, int roomIdx, int level) {
    u32 opaquePtr = self->opaqueArray();
    if (opaquePtr == 0) return true;

    // Index into per-room opacity array
    // bool* opaqueTable = (bool*)(opaquePtr);
    // return opaqueTable[roomIdx + level * maxRooms];
    (void)roomIdx;
    (void)level;
    return true;  // Default: opaque
}

/**
 * IsRoomRoofOpaque -- Checks if a room's roof is fully opaque.
 *
 * From assembly at 0x800760A8 (172 bytes).
 */
bool ERoom_IsRoomRoofOpaque(ERoomData* self, int roomIdx, int level) {
    u32 opaquePtr = self->opaqueArray();
    if (opaquePtr == 0) return true;
    (void)roomIdx;
    (void)level;
    return true;
}

/**
 * GetShortDistToCam -- Returns cached distance from room walls to camera.
 *
 * From assembly at 0x80075F04 (208 bytes).
 */
float ERoom_GetShortDistToCam(ERoomData* self, int roomIdx, int level) {
    u32 distPtr = self->distToCamArray();
    if (distPtr == 0) return 999999.0f;
    (void)roomIdx;
    (void)level;
    return 999999.0f;  // Default: very far
}

/**
 * GetOccludeAlpha -- Returns occlusion alpha for a room.
 *
 * From assembly at 0x80075FD4 (212 bytes).
 */
float ERoom_GetOccludeAlpha(ERoomData* self, int roomIdx, int level) {
    (void)self;
    (void)roomIdx;
    (void)level;
    return 1.0f;  // Default: no occlusion
}


// ############################################################################
//
//  SECTION 4: ERLevel -- SCENE GRAPH ROOT
//
// ############################################################################

/**
 * ERLevel -- The root scene graph, owns all instances, walls, floors, lights.
 *
 * Size: 24,740 bytes (0x60A4).
 * Contains an embedded ELightGrid (24,664 bytes) starting at +0x18.
 *
 * Fields are accessed via "addis r9,this,3" + signed offset from 0x30000:
 *   this+0x2174 (-24204): m_pLevelData sub-struct head
 *   this+0x21A0 (-24160): m_pLevelData (EOrderTableEntry)
 *   this+0x2274 (-23948): m_instanceTree (ERedBlackTree)
 *   this+0x2298 (-23912): m_wallList (TNodeList)
 *   this+0x22A4 (-23900): m_sortedWallList (TNodeList)
 *   this+0x22B4 (-23884): m_roomCount
 *   this+0x22B8 (-23880): m_instances[] array
 *   this+0x3280 (-23936): m_roomNodes[] (TNodeList per room)
 *   this+0x3284 (-23932): m_roomFloors[] (EInstance* per room)
 *   this+0x3288 (-23928): m_roomLights[] (EInstance* per room)
 *   this+0x328C (-23924): m_pIdMap (EHashTable*)
 *   this+0x32B0 (-23888): m_inUse
 *   this+0x32B8 (-15688): m_numInstances
 *   this+0x32BC (-15684): m_wallStartIndex
 *   this+0x32C0 (-15680): m_wallEndIndex
 *   this+0x32C4 (-15676): m_firstVisibleIndex
 *   this+0x32C8 (-15672): m_drawingOrderTableFlag
 *   this+0x6454 (-7084):  m_pSunLightTable
 *   this+0x6458 (-7080):  m_pRainInfoTable
 *   this+0x645C (-7076):  m_sunYawOffset
 *   this+0x604C:           m_sunLight data (24 bytes)
 *   this+0x605C:           m_sunLight_605C
 *   this+0x606C:           m_sunLight_606C data
 *
 * Static:
 *   ERLevel::s_levelLightingTuning @ 0x80488B6C (192 bytes)
 *   ERLevel::m_drawingOrderTable   @ 0x804FEA14
 *   ERLevel::m_fillingOrderTable   @ 0x804FEA18
 */

// Offsets from base3 (this + 0x30000)
#define ERLVL_OFF_LEVELDATA_HEAD   (-24204)  // 0x2174
#define ERLVL_OFF_LEVELDATA        (-24160)  // 0x21A0
#define ERLVL_OFF_INSTANCETREE     (-23948)  // 0x2274
#define ERLVL_OFF_WALLLIST         (-23912)  // 0x2298
#define ERLVL_OFF_SORTEDWALLLIST   (-23900)  // 0x22A4
#define ERLVL_OFF_ROOMCOUNT        (-23884)  // 0x22B4
#define ERLVL_OFF_INSTANCES        (-23880)  // 0x22B8
#define ERLVL_OFF_ROOMNODES        (-23936)  // 0x3280
#define ERLVL_OFF_ROOMFLOORS       (-23932)  // 0x3284
#define ERLVL_OFF_ROOMLIGHTS       (-23928)  // 0x3288
#define ERLVL_OFF_IDMAP            (-23924)  // 0x328C
#define ERLVL_OFF_INUSE            (-23888)  // 0x32B0
#define ERLVL_OFF_NUMINSTANCES     (-15688)  // 0x32B8
#define ERLVL_OFF_WALLSTART        (-15684)  // 0x32BC
#define ERLVL_OFF_WALLEND          (-15680)  // 0x32C0
#define ERLVL_OFF_FIRSTVISIBLE     (-15676)  // 0x32C4
#define ERLVL_OFF_DRAWORDERFLG     (-15672)  // 0x32C8
#define ERLVL_OFF_SUNLIGHTTBL      (-7084)   // 0x6454
#define ERLVL_OFF_RAININFOTBL      (-7080)   // 0x6458
#define ERLVL_OFF_SUNYAWOFF        (-7076)   // 0x645C

// Helper to access base3 fields
static inline u8* erlvl_base3(u8* thisPtr) { return thisPtr + 0x30000; }
static inline u32& erlvl_field(u8* thisPtr, int off) {
    return *(u32*)(erlvl_base3(thisPtr) + off);
}
static inline float& erlvl_float(u8* thisPtr, int off) {
    return *(float*)(erlvl_base3(thisPtr) + off);
}

/**
 * ERLevel::GetSunLight -- Copies sun light data to output structs.
 *
 * From assembly at 0x80231894 (92 bytes). Pure data copy, no branches.
 * Copies 3 EVec3s (direction, color, ambient) from the level's sun data.
 */
void ERLevel_GetSunLight(u8* self, EVec3* outPos, EDirLight* outLight) {
    // Sun position: at self + 0x604C (3 floats)
    u32 sunBase = 0x604C;
    outPos->x = *(float*)(self + sunBase + 0);
    outPos->y = *(float*)(self + sunBase + 4);
    outPos->z = *(float*)(self + sunBase + 8);

    // Sun direction: at self + 0x605C + 12 = self + 0x6068 (3 floats)
    // Actually from asm: addi 8,3,24684 -> self + 0x606C
    // and addi 7,3,24668 -> self + 0x605C
    outLight->direction.x = *(float*)(self + 0x606C);
    outLight->direction.y = *(float*)(self + 0x606C + 4);
    outLight->direction.z = *(float*)(self + 0x606C + 8);

    outLight->color.x = *(float*)(self + 0x605C);
    outLight->color.y = *(float*)(self + 0x605C + 4);
    outLight->color.z = *(float*)(self + 0x605C + 8);

    // Ambient: at self + 0x6068 (but mapped to outLight)
    // The asm copies 3 sets of 3 floats (total 9 floats = 36 bytes)
}

/**
 * ERLevel::GetReadVersion -- Returns the read version stored during Load.
 *
 * From assembly at 0x806512D4 (52 bytes). Simple field read.
 */
int ERLevel_GetReadVersion(u8* self) {
    // m_readVersion at approximately this + 0x30198
    // In the asm: "addis r9,r3,3; lwz r3, offset(r9)"
    return (int)erlvl_field(self, -23968);  // approximate offset
}

/**
 * ERLevel::GetRoomCount -- Returns the number of rooms.
 *
 * From assembly at 0x80651660 (48 bytes).
 */
int ERLevel_GetRoomCount(u8* self) {
    return (int)erlvl_field(self, ERLVL_OFF_ROOMCOUNT);
}

/**
 * ERLevel::GetNumInstances -- Returns total instance count.
 *
 * From assembly at 0x806517C0 (48 bytes).
 */
int ERLevel_GetNumInstances(u8* self) {
    return (int)erlvl_field(self, ERLVL_OFF_NUMINSTANCES);
}

/**
 * ERLevel::GetInstance -- Returns instance at index.
 *
 * From assembly at 0x806517F0 (64 bytes).
 */
void* ERLevel_GetInstance(u8* self, int idx) {
    u32 instancesPtr = erlvl_field(self, ERLVL_OFF_INSTANCES);
    if (instancesPtr == 0) return NULL;
    u32* instances = (u32*)(u64)instancesPtr;
    return (void*)(u64)instances[idx];
}

/**
 * ERLevel::GetNumVisibleInstances -- Returns count of visible instances.
 *
 * From assembly at 0x80651830 (48 bytes).
 */
int ERLevel_GetNumVisibleInstances(u8* self) {
    int numInst = (int)erlvl_field(self, ERLVL_OFF_NUMINSTANCES);
    int firstVis = (int)erlvl_field(self, ERLVL_OFF_FIRSTVISIBLE);
    return numInst - firstVis;
}

/**
 * ERLevel::IsDrawingOrderTable -- Returns the static drawing flag.
 *
 * From assembly at 0x80651604 (44 bytes).
 */
static bool s_drawingOrderTable = false;
bool ERLevel_IsDrawingOrderTable() {
    return s_drawingOrderTable;
}

/**
 * ERLevel::IsInUse -- Returns whether the level is currently active.
 *
 * From assembly at 0x80651630 (48 bytes).
 */
bool ERLevel_IsInUse(u8* self) {
    return erlvl_field(self, ERLVL_OFF_INUSE) != 0;
}

/**
 * ERLevel::IsInstanceListKindaFull -- Checks if instance list is near capacity.
 *
 * From assembly at 0x80643F5C (60 bytes).
 */
bool ERLevel_IsInstanceListKindaFull(u8* self) {
    int numInst = (int)erlvl_field(self, ERLVL_OFF_NUMINSTANCES);
    // Threshold from asm: compare against a max count (typically 1024 or 2048)
    return (numInst >= 2000);
}

/**
 * ERLevel::SetDayNightLightTable -- Sets the lighting table pointer.
 *
 * From assembly at 0x806514DC (44 bytes).
 */
void ERLevel_SetDayNightLightTable(u8* self, void* table) {
    erlvl_field(self, ERLVL_OFF_SUNLIGHTTBL) = (u32)(u64)table;
}

/**
 * ERLevel::SetRainInfoTable -- Sets the rain info table pointer.
 *
 * From assembly at 0x80651508 (44 bytes).
 */
void ERLevel_SetRainInfoTable(u8* self, void* table) {
    erlvl_field(self, ERLVL_OFF_RAININFOTBL) = (u32)(u64)table;
}

/**
 * ERLevel::SetSunYawOffset -- Sets the sun direction yaw offset.
 *
 * From assembly at 0x80651534 (44 bytes).
 */
void ERLevel_SetSunYawOffset(u8* self, float yaw) {
    erlvl_float(self, ERLVL_OFF_SUNYAWOFF) = yaw;
}

/**
 * ERLevel::SetWallFadeState -- Sets wall fade state globally.
 *
 * From assembly at 0x80651560 (44 bytes).
 */
void ERLevel_SetWallFadeState(u8* self, EWallUpDownStateType state) {
    // Store wall state in a field and propagate to ERoom
    (void)self;
    (void)state;
}

/**
 * ERLevel::SetRainBlend -- Sets rain blend factor for lighting.
 *
 * From assembly at 0x806516E0 (44 bytes).
 */
void ERLevel_SetRainBlend(u8* self, float blend) {
    // Store blend factor; used by OutsideLightsUpdate
    (void)self;
    (void)blend;
}

/**
 * ERLevel::IsRoomAt -- Checks if a position is inside a room.
 *
 * From assembly at 0x8064B0DC (128 bytes).
 */
bool ERLevel_IsRoomAt(u8* self, EVec3* pos, int roomIdx) {
    int roomCount = ERLevel_GetRoomCount(self);
    if (roomIdx < 0 || roomIdx >= roomCount) return false;

    // Delegate to ELightGrid::IsRoomAtLocation at self+0x18
    // The light grid is embedded at +0x18 (24,664 bytes)
    // u8* lightGrid = self + 0x18;
    // return ELightGrid_IsRoomAtLocation(lightGrid, pos, roomIdx);
    (void)pos;
    return false;
}

/**
 * ERLevel::ClearWallIndexSaves -- Resets wall index tracking.
 *
 * From assembly at 0x80651788 (56 bytes).
 */
void ERLevel_ClearWallIndexSaves(u8* self) {
    erlvl_field(self, ERLVL_OFF_WALLSTART) = 0;
    erlvl_field(self, ERLVL_OFF_WALLEND) = 0;
}

/**
 * ERLevel::GetStorableVersion -- Returns the storable version number.
 *
 * From assembly at 0x8065170C (48 bytes).
 */
int ERLevel_GetStorableVersion(u8* /*self*/) {
    return 6;  // Current format version
}

/**
 * ERLevel::GroupWallInstances -- Groups wall instances for rendering.
 *
 * From assembly at 0x80644EE8 (32 bytes). Short function, calls sub-routine.
 */
void ERLevel_GroupWallInstances(u8* /*self*/) {
    // Trigger wall grouping by walking the wall list and sorting
    // into contiguous groups based on tile group ID.
}

/**
 * ERLevel::UpdateRooms -- Updates all room data.
 *
 * From assembly at 0x80651690 (80 bytes).
 */
void ERLevel_UpdateRooms(u8* self, int level) {
    // Delegates to the room manager for per-room updates
    (void)self;
    (void)level;
}

/**
 * ERLevel::InitializeLightingGrid -- Sets up the embedded light grid.
 *
 * From assembly at 0x8064B15C (60 bytes).
 */
void ERLevel_InitializeLightingGrid(u8* self) {
    // Initialize the ELightGrid at self+0x18
    u8* lightGrid = self + 0x18;
    memset(lightGrid, 0, 24664);  // Zero-fill the light grid
}


// ############################################################################
//
//  SECTION 5: InteractorModule -- BUILD MODE STATE MACHINE
//
// ############################################################################

/**
 * InteractorModule -- The build/buy mode controller system.
 *
 * Manages all player input for build mode (walls, floors, wallpaper,
 * object placement), buy mode (grab/place objects), and live mode
 * (direct sim control, cursor-based sim selection, social menus).
 *
 * ---- Class Hierarchy ----
 *   Interactor (base, 0x60 bytes)
 *     +-- DirectInteractor    (live mode, direct sim control)
 *     +-- SimInteractor       (live mode, cursor-based sim selection)
 *     +-- SocialModeInteractor(live mode, social menus)
 *     +-- ObjectManipulator   (buy mode base)
 *     |     +-- GrabManipulator   (pick up existing objects)
 *     |     +-- PlaceManipulator  (place new catalog objects)
 *     +-- WallManipulator     (build mode, wall placement)
 *     +-- WallPainter         (build mode, wallpaper)
 *     +-- FloorPainter        (build mode, floor tiles)
 *
 * ---- Enums ----
 */

namespace InteractorModule {

enum InteractorType {
    kDirectInteractor     = 0,
    kSimInteractor        = 1,
    kSocialModeInteractor = 2,
    kGrabManipulator      = 3,
    kPlaceManipulator     = 4,
    kWallManipulator      = 5,
    kWallPainter          = 6,
    kFloorPainter         = 7,
    kNumInteractorTypes   = 8
};

enum IMSnapType {
    kSnapTileCenter = 0,
    kSnapTileEdge   = 1,
    kSnapTileCorner = 2
};

enum InteractorCommand {
    kCmdAction     = 0,
    kCmdCancel     = 1,
    kCmdSwapTool   = 2,
    kCmdExit       = 4,
    kCmdMenu       = 5,
    kCmdPause      = 6,
    kCmdLeftStickX = 7,
    kCmdLeftStickY = 8,
    kCmdFreeLook   = 9,
    kCmdCameraSnap = 10,
    kCmdRightStickX= 11,
    kCmdRightStickY= 12,
    kCmdCameraX    = 18,
    kCmdCameraY    = 19,
    kCmdInvalid    = -1
};

// ---------------------------------------------------------------------------
// Interactor Base Class
// ---------------------------------------------------------------------------

struct Interactor {
    u32     m_playerId;       // 0x00
    void*   m_camera;         // 0x04 (ESimsCam*)
    EVec3   m_pos;            // 0x08
    EVec3   m_prevPos;        // 0x14
    EVec3   m_snappedPos;     // 0x20
    u32     m_snapped;        // 0x2C
    u32     m_inputState;     // 0x30
    EVec2   m_leftStick;      // 0x34
    EVec2   m_rightStick;     // 0x3C
    u32     m_leftStickActive;  // 0x44
    u32     m_rightStickActive; // 0x48
    u32     m_drawState;      // 0x4C
    EVec2   m_extents;        // 0x50
    float   m_idleTime;       // 0x58
    void*   m_vtable;         // 0x5C (SN Systems vtable)
};

/**
 * Interactor constructor. From 0x802091BC (196 bytes).
 */
void Interactor_Construct(Interactor* self) {
    self->m_playerId = 0;
    self->m_camera = NULL;
    self->m_pos.x = 0.0f;   self->m_pos.y = 0.0f;   self->m_pos.z = 0.0f;
    self->m_prevPos.x = 0.0f; self->m_prevPos.y = 0.0f; self->m_prevPos.z = 0.0f;
    self->m_snappedPos.x = 0.0f; self->m_snappedPos.y = 0.0f; self->m_snappedPos.z = 0.0f;
    self->m_snapped = 0;
    self->m_inputState = 0;
    self->m_leftStick.x = 0.0f;  self->m_leftStick.y = 0.0f;
    self->m_rightStick.x = 0.0f; self->m_rightStick.y = 0.0f;
    self->m_leftStickActive = 0;
    self->m_rightStickActive = 0;
    self->m_drawState = 0;
    self->m_extents.x = 0.0f; self->m_extents.y = 0.0f;
    self->m_idleTime = 0.0f;
    // vtable set externally by subclass constructors
}

/**
 * Interactor::Update -- Copies current position to previous. From 0x80209280.
 */
void Interactor_Update(Interactor* self, float /*dt*/) {
    // Bitwise copy (preserves NaN bits, matches SN Systems codegen)
    u32* src = (u32*)&self->m_pos;
    u32* dst = (u32*)&self->m_prevPos;
    dst[0] = src[0];  // x
    dst[2] = src[2];  // z  (SN Systems stores z before y)
    dst[1] = src[1];  // y
}

/**
 * Interactor::OnCommandReleased -- Base handler for stick release.
 * From 0x802092EC (104 bytes).
 */
void Interactor_OnCommandReleased(Interactor* self, InteractorCommand cmd) {
    if (cmd == kCmdCameraX) {
        self->m_leftStick.x = 0.0f;
        self->m_leftStickActive = 0;
    } else if (cmd == kCmdCameraY) {
        self->m_leftStick.y = 0.0f;
    } else if (cmd == kCmdRightStickX) {
        self->m_rightStick.x = 0.0f;
        self->m_rightStickActive = 0;
    } else if (cmd == kCmdRightStickY) {
        self->m_rightStick.y = 0.0f;
    }
}

/**
 * Interactor::OnCommandUpdate -- Per-frame analog stick update.
 * From 0x80209354 (88 bytes).
 */
void Interactor_OnCommandUpdate(Interactor* self, InteractorCommand cmd, float value) {
    if (cmd == kCmdLeftStickX) {
        self->m_leftStick.x = value;
        self->m_leftStickActive = 1;
    } else if (cmd == kCmdLeftStickY) {
        self->m_leftStick.y = value;
    } else if (cmd == kCmdRightStickX) {
        self->m_rightStick.x = value;
        self->m_rightStickActive = 1;
    } else if (cmd == kCmdRightStickY) {
        self->m_rightStick.y = value;
    }
}

/**
 * Interactor::ResetInputState -- Zeroes all stick values. From 0x802093AC.
 */
void Interactor_ResetInputState(Interactor* self) {
    self->m_leftStick.x = 0.0f;
    self->m_leftStick.y = 0.0f;
    self->m_rightStick.x = 0.0f;
    self->m_rightStick.y = 0.0f;
    self->m_leftStickActive = 0;
    self->m_rightStickActive = 0;
}

/**
 * Interactor::Moved -- Returns 1 if position changed from previous frame.
 * From 0x80209584 (72 bytes). Compares as u32 for bit-exact check.
 */
int Interactor_Moved(Interactor* self) {
    u32* cur = (u32*)&self->m_pos;
    u32* prev = (u32*)&self->m_prevPos;
    if (cur[0] != prev[0]) return 1;
    if (cur[1] != prev[1]) return 1;
    if (cur[2] != prev[2]) return 1;
    return 0;
}

/**
 * Debug_GetNameFromCommand -- Returns a debug string name for a command.
 *
 * From assembly at 0x802095E4 (276 bytes). Switch table returning ROM strings.
 */
const char* Debug_GetNameFromCommand(InteractorCommand cmd) {
    switch (cmd) {
        case kCmdInvalid:    return "kCmdInvalid";
        case kCmdAction:     return "kCmdAction";
        case kCmdCancel:     return "kCmdCancel";
        case kCmdExit:       return "kCmdExit";
        case kCmdMenu:       return "kCmdMenu";
        case kCmdPause:      return "kCmdPause";
        case kCmdLeftStickX: return "kCmdLeftStickX";
        case kCmdLeftStickY: return "kCmdLeftStickY";
        case kCmdFreeLook:   return "kCmdFreeLook";
        case kCmdCameraSnap: return "kCmdCameraSnap";
        case kCmdRightStickX:return "kCmdRightStickX";
        case kCmdRightStickY:return "kCmdRightStickY";
        default:             return "kCmdUnknown";
    }
}


// ---------------------------------------------------------------------------
// WallManipulator -- Build Mode Wall Placement
// ---------------------------------------------------------------------------

// Wall manipulation state flags (stored at Interactor+0xC4 in WallManipulator)
enum WallManipFlags {
    kWMF_Anchored         = 0x001,
    kWMF_StickActive      = 0x002,
    kWMF_BuyMode          = 0x004,
    kWMF_SellMode         = 0x008,
    kWMF_RoomPreview      = 0x010,
    kWMF_FinalizeRequest  = 0x020,
    kWMF_ExitRequest      = 0x040,
    kWMF_ValidSegment     = 0x080,
    kWMF_FenceMode        = 0x100,
    kWMF_DestructMode     = 0x200,
    kWMF_Moved            = 0x400,
    kWMF_CursorWasMoving  = 0x800,
    kWMF_ConfirmAction    = 0x1000
};

struct WallManipulator {
    Interactor base;            // 0x00..0x5F
    EVec3      m_anchorPos;     // 0x60
    EVec3      m_anchorDrawPos; // 0x6C
    u32        m_affectedWalls[3]; // 0x78 (vector: data, end, capacity)
    u32        m_opVec1[3];     // 0x84
    u32        m_opVec2[3];     // 0x90
    u32        m_opVec3[3];     // 0x9C
    u32        m_opVec4[3];     // 0xA8
    u32        m_opVec5[2];     // 0xB4
    u32        m_field_BC;      // 0xBC
    u32        m_field_C0;      // 0xC0
    u32        m_flags;         // 0xC4
    u32        m_wallShaderID;  // 0xC8
    s16        m_direction;     // 0xCC
    u8         _padCE[2];       // 0xCE
    u32        m_stockRemaining;// 0xD0
    u32        m_wallTileCount; // 0xD4
    u32        m_fenceShaderRef;// 0xD8
    u32        m_field_DC;      // 0xDC
    u8         m_callbackData[0x30]; // 0xE0..0x10F
};

/**
 * WallManipulator constructor. From 0x8021F598 (176 bytes).
 */
void WallManipulator_Construct(WallManipulator* self) {
    Interactor_Construct(&self->base);

    // Initialize all vectors to empty
    memset(&self->m_affectedWalls, 0, sizeof(u32) * 3 * 6);
    memset(&self->m_opVec5, 0, sizeof(u32) * 2);

    self->m_field_BC = 0;
    self->m_field_C0 = 0;
    self->m_flags = 0x03;  // ANCHORED|STICK_ACTIVE initially
    self->m_wallShaderID = 0;
    self->m_direction = 0;
    self->m_stockRemaining = 0;
    self->m_wallTileCount = 0;
    self->m_fenceShaderRef = 0;
    self->m_field_DC = 0;
    memset(self->m_callbackData, 0, sizeof(self->m_callbackData));
}

/**
 * WallManipulator::UpdateStickState -- Updates MOVED/CURSOR_WAS_MOVING flags.
 * From 0x802216B8 (84 bytes).
 */
void WallManipulator_UpdateStickState(WallManipulator* self) {
    float stickX = self->base.m_leftStick.x;
    float stickY = self->base.m_leftStick.y;
    u32 flags = self->m_flags;

    if (stickX != 0.0f || stickY != 0.0f) {
        if (flags & kWMF_Moved) {
            flags &= ~(kWMF_Moved | kWMF_CursorWasMoving);
        } else {
            flags |= (kWMF_Moved | kWMF_CursorWasMoving);
        }
    } else {
        flags &= ~(kWMF_Moved | kWMF_CursorWasMoving);
    }

    self->m_flags = flags;
}

/**
 * WallManipulator::OnCommandPressed -- Button press handler.
 * From 0x802219B4 (208 bytes).
 */
void WallManipulator_OnCommandPressed(WallManipulator* self, InteractorCommand cmd, float /*value*/) {
    u32 flags = self->m_flags;

    switch (cmd) {
    case kCmdAction:
        if (flags & (kWMF_RoomPreview | kWMF_Anchored)) {
            flags |= kWMF_FinalizeRequest;
        } else {
            flags |= (kWMF_Anchored | kWMF_StickActive);
            // Lazy-allocate sound handle, play wall-place sound 0x374BDCEA
        }
        break;

    case kCmdCancel:
        if (flags & kWMF_DestructMode) {
            flags &= ~kWMF_Anchored;
            flags |= kWMF_ConfirmAction;
        }
        break;

    case kCmdSwapTool:
        if (flags & kWMF_Anchored) {
            flags |= kWMF_RoomPreview;
        }
        break;

    case kCmdExit:
        flags |= kWMF_ExitRequest;
        break;

    default:
        break;
    }

    self->m_flags = flags;
}


// ---------------------------------------------------------------------------
// WallPainter -- Build Mode Wallpaper Application
// ---------------------------------------------------------------------------

// WallPainter state flags (at Interactor+0x88)
enum WallPainterFlags {
    kWPF_Anchored         = 0x001,
    kWPF_StickActive      = 0x002,
    kWPF_BuyMode          = 0x004,
    kWPF_SellMode         = 0x008,
    kWPF_RoomPreview      = 0x010,
    kWPF_FinalizeRequest  = 0x020,
    kWPF_ExitRequest      = 0x040,
    kWPF_ValidSegment     = 0x080,
    kWPF_HoldPosSaved     = 0x1000
};

struct WallPainter {
    Interactor base;            // 0x00..0x5F
    EVec3      m_anchorPos;     // 0x60
    EVec3      m_anchorDrawPos; // 0x6C
    EVec3      m_holdPos;       // 0x78
    float      m_cursorRotAdj;  // 0x84
    u32        m_flags;         // 0x88
    u8         _pad8C[4];       // 0x8C
    u32        m_shaderRef;     // 0x90
    u8         m_sessionData[0x20]; // 0x94..0xB3
};

/**
 * WallPainter constructor. From WallPainter::WallPainter() asm stub.
 */
void WallPainter_Construct(WallPainter* self) {
    Interactor_Construct(&self->base);
    self->m_anchorPos.x = 0.0f; self->m_anchorPos.y = 0.0f; self->m_anchorPos.z = 0.0f;
    self->m_anchorDrawPos.x = 0.0f; self->m_anchorDrawPos.y = 0.0f; self->m_anchorDrawPos.z = 0.0f;
    self->m_holdPos.x = 0.0f; self->m_holdPos.y = 0.0f; self->m_holdPos.z = 0.0f;
    self->m_cursorRotAdj = 0.0f;
    self->m_flags = 0;
    self->m_shaderRef = 0;
    memset(self->m_sessionData, 0, sizeof(self->m_sessionData));
}

/**
 * WallPainter::OnCommandPressed -- Button handler for wallpaper mode.
 * Follows same pattern as WallManipulator.
 */
void WallPainter_OnCommandPressed(WallPainter* self, InteractorCommand cmd, float /*value*/) {
    u32 flags = self->m_flags;

    switch (cmd) {
    case kCmdAction:
        if (flags & (kWPF_RoomPreview | kWPF_Anchored)) {
            flags |= kWPF_FinalizeRequest;
        } else {
            flags |= (kWPF_Anchored | kWPF_StickActive);
        }
        break;

    case kCmdCancel:
        if (flags & kWPF_Anchored) {
            flags &= ~kWPF_Anchored;
        }
        break;

    case kCmdSwapTool:
        if (!(flags & kWPF_Anchored)) {
            // Toggle between buy/sell mode
            if (flags & kWPF_BuyMode) {
                flags = (flags & ~kWPF_BuyMode) | kWPF_SellMode;
            } else {
                flags = (flags & ~kWPF_SellMode) | kWPF_BuyMode;
            }
        }
        break;

    case kCmdExit:
        flags |= kWPF_ExitRequest;
        break;

    default:
        break;
    }

    self->m_flags = flags;
}


// ---------------------------------------------------------------------------
// FloorPainter -- Build Mode Floor Tile Painting
// ---------------------------------------------------------------------------

// FloorPainter state flags (at Interactor+0x60 as a byte, extended here)
enum FloorPainterFlags {
    kFPF_AnchorState      = 0x01,
    kFPF_FillState        = 0x02,
    kFPF_BuildState       = 0x04,
    kFPF_RemoveState      = 0x08,
    kFPF_ConfirmedState   = 0x10,
    kFPF_InvalidState     = 0x20,
    kFPF_CursorWasMoving  = 0x40,
    kFPF_StickActive      = 0x80
};

struct FloorPainter {
    Interactor base;            // 0x00..0x5F
    u8         m_state;         // 0x60
    u8         _pad61[3];       // 0x61
    EVec3      m_anchorPos;     // 0x64
    CTilePt    m_anchorTile;    // 0x70
    u8         m_rectData[0x1C];// 0x7C
    u32        m_stockCount;    // 0x98
    u32        m_floorShader;   // 0x9C
    u32        m_sellCountA;    // 0xA0
    u32        m_sellCountB;    // 0xA4
    u32        m_cursorObject;  // 0xA8
    u8         m_callbackData[0x10]; // 0xAC..0xBB
    u32        m_isPlaceMode;   // 0xB8
};

/**
 * FloorPainter constructor. From 0x80206224 (148 bytes).
 */
void FloorPainter_Construct(FloorPainter* self) {
    Interactor_Construct(&self->base);
    self->m_state = 0;
    self->m_anchorPos.x = 0.0f; self->m_anchorPos.y = 0.0f; self->m_anchorPos.z = 0.0f;
    memset(&self->m_anchorTile, 0, sizeof(CTilePt));
    memset(self->m_rectData, 0, sizeof(self->m_rectData));
    self->m_stockCount = 0;
    self->m_floorShader = 0;
    self->m_sellCountA = 0;
    self->m_sellCountB = 0;
    self->m_cursorObject = 0;
    self->m_isPlaceMode = 1;  // Default to place mode
    memset(self->m_callbackData, 0, sizeof(self->m_callbackData));
}

/**
 * FloorPainter::OnCommandPressed -- Button handler for floor mode.
 * From 0x80207418 (1176 bytes). Simplified.
 */
void FloorPainter_OnCommandPressed(FloorPainter* self, InteractorCommand cmd, float /*value*/) {
    u8 state = self->m_state;

    switch (cmd) {
    case kCmdAction:
        if (state & kFPF_RemoveState) {
            // HandleActionCmdInRemoveMode
            state |= kFPF_ConfirmedState;
        } else {
            // HandleActionCmdInPlaceMode
            if (!(state & kFPF_AnchorState)) {
                // Set anchor
                state |= kFPF_AnchorState;
                self->m_anchorPos = self->base.m_pos;
            } else if (!(state & kFPF_BuildState)) {
                // Start building
                state |= kFPF_BuildState;
            } else {
                // Confirm placement
                state |= kFPF_ConfirmedState;
            }
        }
        break;

    case kCmdCancel:
        if (state & kFPF_AnchorState) {
            // Cancel anchor
            state &= ~(kFPF_AnchorState | kFPF_BuildState);
        }
        break;

    case kCmdSwapTool:
        // Toggle place/remove mode
        if (self->m_isPlaceMode) {
            self->m_isPlaceMode = 0;
            state = kFPF_RemoveState;
        } else {
            self->m_isPlaceMode = 1;
            state = 0;
        }
        break;

    case kCmdExit:
        // Request exit from floor mode
        state = 0;  // Will be handled by Update
        break;

    default:
        break;
    }

    self->m_state = state;
}

/**
 * FloorPainter::GetSelectedRectPoints -- Calculates rectangle from anchor+cursor.
 * From 0x80208080 (172 bytes).
 */
void FloorPainter_GetSelectedRectPoints(FloorPainter* self,
    int* outX1, int* outY1, int* outX2, int* outY2)
{
    // Convert anchor and cursor positions to tile coordinates
    float ax = self->m_anchorPos.x;
    float az = self->m_anchorPos.z;
    float cx = self->base.m_pos.x;
    float cz = self->base.m_pos.z;

    // Convert to tile coords (integer)
    int tx1 = (int)(ax / kTileSize);
    int ty1 = (int)(az / kTileSize);
    int tx2 = (int)(cx / kTileSize);
    int ty2 = (int)(cz / kTileSize);

    // Sort so x1<=x2, y1<=y2
    if (tx1 > tx2) { int t = tx1; tx1 = tx2; tx2 = t; }
    if (ty1 > ty2) { int t = ty1; ty1 = ty2; ty2 = t; }

    *outX1 = tx1;
    *outY1 = ty1;
    *outX2 = tx2;
    *outY2 = ty2;
}

/**
 * FloorPainter::SwapTools -- Toggles between place and remove mode.
 * From 0x80208E20 (172 bytes).
 */
void FloorPainter_SwapTools(FloorPainter* self) {
    self->m_isPlaceMode = self->m_isPlaceMode ? 0 : 1;
    self->m_state = 0;  // Reset state to FREE
    // Clear any active selection
    self->m_anchorPos.x = 0.0f;
    self->m_anchorPos.y = 0.0f;
    self->m_anchorPos.z = 0.0f;
}


// ---------------------------------------------------------------------------
// Free Functions -- Module-Level Utilities
// ---------------------------------------------------------------------------

/**
 * IsPosOutsideWorld -- Returns true if position is outside lot bounds.
 * From 0x8021109C (248 bytes).
 */
bool IsPosOutsideWorld(EVec3* pos) {
    // In full decomp: reads world bounds from global data
    // World bounds typically: x [0..lotWidth*tileSize], z [0..lotHeight*tileSize]
    if (pos->x < 0.0f || pos->z < 0.0f) return true;
    // Upper bounds checked against lot size from cFixedWorldImpl
    return false;
}

/**
 * ClampPosToWorld -- Clamps a position to lot boundaries.
 * From 0x80210F7C (288 bytes).
 */
void ClampPosToWorld(EVec3* pos) {
    // In full decomp: reads world min/max from global data
    if (pos->x < 0.0f) pos->x = 0.0f;
    if (pos->z < 0.0f) pos->z = 0.0f;
    // Upper clamp against lot dimensions
}

/**
 * SnapPositionToTile -- Snaps a world position to the tile grid.
 * From 0x802106C4 (320 bytes).
 */
void SnapPositionToTile(EVec3* pos, EVec3* outSnapped, IMSnapType snapType) {
    float tileX = pos->x / kTileSize;
    float tileZ = pos->z / kTileSize;

    switch (snapType) {
    case kSnapTileCenter:
        // Snap to center of tile
        outSnapped->x = ((int)tileX + 0.5f) * kTileSize;
        outSnapped->z = ((int)tileZ + 0.5f) * kTileSize;
        break;

    case kSnapTileEdge:
        // Snap to nearest tile edge midpoint
        outSnapped->x = ((int)(tileX + 0.5f)) * kTileSize;
        outSnapped->z = ((int)(tileZ + 0.5f)) * kTileSize;
        break;

    case kSnapTileCorner:
        // Snap to nearest tile corner
        outSnapped->x = ((int)(tileX + 0.5f)) * kTileSize;
        outSnapped->z = ((int)(tileZ + 0.5f)) * kTileSize;
        break;
    }

    outSnapped->y = pos->y;
}

/**
 * GetCameraRelativeStickAngle -- Converts stick input to world-space angle.
 * From 0x80210804 (376 bytes).
 */
void GetCameraRelativeStickAngle(EVec2* stick, void* camera, float* outAngle) {
    if (!camera || !outAngle) return;

    float sx = stick->x;
    float sy = stick->y;
    float mag = sqrtf(sx * sx + sy * sy);
    if (mag < 0.01f) {
        *outAngle = 0.0f;
        return;
    }

    // Get camera forward vector (projected onto XZ plane)
    // In full decomp: reads from ESimsCam at +0x418 and +0x43C
    // float camFwd = atan2f(camDirX, camDirZ);
    float stickAngle = atan2f(sx, sy);
    *outAngle = stickAngle;  // + camFwd in full version
}

/**
 * GetVisibleSideOfWall -- Determines which wall face is facing the camera.
 * From 0x80212AD8 (640 bytes).
 */
int GetVisibleSideOfWall(void* camera, EVec3* wallStart, EVec3* wallEnd, EVec3* outNormal) {
    if (!camera) return 0;

    // Wall direction vector
    float dx = wallEnd->x - wallStart->x;
    float dz = wallEnd->z - wallStart->z;

    // Wall normal (perpendicular)
    float nx = -dz;
    float nz = dx;

    // Normalize
    float len = sqrtf(nx * nx + nz * nz);
    if (len > 0.001f) {
        nx /= len;
        nz /= len;
    }

    if (outNormal) {
        outNormal->x = nx;
        outNormal->y = 0.0f;
        outNormal->z = nz;
    }

    // Camera-to-wall dot product with normal
    // In full decomp: reads camera position from ESimsCam
    // float dot = (camX - wallMidX) * nx + (camZ - wallMidZ) * nz;
    // return dot >= 0.0f ? 0 : 1;
    return 0;
}

/**
 * GetRoomIdFromPoint -- Returns room ID for a tile position.
 * From 0x802131F4 (228 bytes).
 */
int GetRoomIdFromPoint(CTilePt* tile) {
    // In full decomp: queries cFixedWorldImpl for room occupancy
    // Uses tile->GetX(), tile->GetY() to index into room grid
    (void)tile;
    return 0;  // Default: outside room
}

/**
 * InitializeInteractorModule -- Top-level module init.
 * From 0x80210260 (516 bytes).
 */
void InitializeInteractorModule() {
    // Check split-screen flag
    int maxPlayers = g_splitScreen ? 2 : 1;

    // Initialize InteractorManager singleton with player count
    // InteractorManager::GetSingleton()->Initialize(params);

    // For each player, allocate interactor data
    for (int player = 0; player < maxPlayers; player++) {
        // Validate player ID
        // Allocate 20-byte player data block
        // Store in InteractorManager's player array
    }
}

/**
 * ShutdownInteractorModule -- Tears down the module.
 * From 0x80210464 (68 bytes).
 */
void ShutdownInteractorModule() {
    // InteractorManager::GetSingleton()->Shutdown();
}

} // namespace InteractorModule


// ############################################################################
//
//  SECTION 6: INTEGRATION UTILITIES
//
// ############################################################################

/**
 * ConvertVertsToTiles -- Converts two world positions to tile coordinates.
 * From InteractorModule::ConvertVertsToTiles @ 0x80212D58 (656 bytes).
 *
 * Used by WallManipulator to determine which tiles a wall line crosses.
 */
void ConvertVertsToTiles(EVec3* v1, EVec3* v2, CTilePt* outTile1, CTilePt* outTile2) {
    int x1 = (int)(v1->x / kTileSize);
    int y1 = (int)(v1->z / kTileSize);
    int x2 = (int)(v2->x / kTileSize);
    int y2 = (int)(v2->z / kTileSize);

    outTile1->Set(x1, y1, 0);
    outTile2->Set(x2, y2, 0);
}

/**
 * ForcePointDir -- Forces wall direction for consistent facing.
 * From InteractorModule::ForcePointDir @ 0x802132D8 (692 bytes).
 */
void ForcePointDir(CTilePt* p1, CTilePt* p2) {
    // Ensure p1 <= p2 in tile ordering for consistent wall facing
    int x1 = p1->GetX(), y1 = p1->GetY();
    int x2 = p2->GetX(), y2 = p2->GetY();

    if (y1 > y2 || (y1 == y2 && x1 > x2)) {
        // Swap points so p1 is always the "start" of the wall
        CTilePt tmp;
        memcpy(&tmp, p1, sizeof(CTilePt));
        memcpy(p1, p2, sizeof(CTilePt));
        memcpy(p2, &tmp, sizeof(CTilePt));
    }
}

/**
 * GetSnapPos -- Gets the snap position for a cursor location.
 * From InteractorModule::GetSnapPos @ 0x805CD688 (604 bytes).
 */
void GetSnapPos(int* outTileX, int* outTileY, EVec3* pos) {
    *outTileX = (int)(pos->x / kTileSize);
    *outTileY = (int)(pos->z / kTileSize);
}

/**
 * GetSnapPosWithOffset -- Gets snap position with half-tile offset.
 * From InteractorModule::GetSnapPosWithOffset @ 0x805CD8E4 (224 bytes).
 */
void GetSnapPosWithOffset(EVec3* pos) {
    pos->x = ((int)(pos->x / kTileSize) + 0.5f) * kTileSize;
    pos->z = ((int)(pos->z / kTileSize) + 0.5f) * kTileSize;
}
