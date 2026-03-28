// erlevel_decomp.cpp - ERLevel, ERoom, EIWallPart, EIFloor, EIFenceWall Decompilation
// Part of the Sims 2 GC matching decompilation
// Original object files: e_rlevel.obj, eroom.obj, e_wallpart.obj, e_floor.obj
//
// This file documents the world geometry and room system — how the 3D game world
// is constructed from tiles, walls, floors, rooms, and lighting zones.
//
// ============================================================================
// ARCHITECTURE OVERVIEW
// ============================================================================
//
// The Sims 2 GC world is built on a tile-based system:
//
//   ERLevel  (24,740 bytes)  — The root scene graph. Owns all instances, walls,
//                               floors, lights, rooms, and the render order table.
//                               One ERLevel exists per loaded lot.
//
//   ERoom    (180 bytes)     — Wall lookup table + room boundary processing.
//                               Processes TileWalls into ERoomWall segments.
//                               Manages wall visibility, wallpaper, and fade states.
//
//   Room     (164 bytes)     — Logical room: tile membership, environment score,
//                               lighting group, ambient light, overhead light state.
//                               Computed by RoomManager::ComputeRooms().
//
//   RoomManager (56 bytes)   — Owns a red-black tree of Room objects keyed by
//                               room ID. Drives room detection and environment scoring.
//
//   EIWallPart (3,516 bytes) — A single wall segment instance (EInstance subclass).
//                               Contains geometry (model ID), orientation matrix,
//                               wallpaper shader, shadow model, and tile coordinates.
//
//   EIFenceWall (944 bytes)  — A fence wall instance (EInstance subclass). Lightweight
//                               transparent wall that does not block room boundaries.
//
//   EIFloor  (288 bytes)     — A floor tile instance (EInstance subclass). Holds
//                               geometry, room ID membership, lighting data, and
//                               per-vertex colors for shadow reception.
//
//   EFenceWall (64 bytes)    — Fence wall rendering helper within ERoomWall.
//
//   ERoomWall (276 bytes)    — A contiguous wall run: multiple EIWallPart segments
//                               sharing a wall line. Owns wallpaper cost, draw logic,
//                               and room-boundary queries.
//
//   TileWalls (56 bytes)     — Per-tile wall configuration. Encodes which of the
//                               8 wall segments (N, S, E, W, NE diag, NW diag,
//                               SE diag, SW diag) are present, their style, pattern,
//                               placement, and floor values.
//
//   CTilePt  (12 bytes)      — Integer tile coordinate (x, y, level). Converts
//                               to/from world-space EVec3 via GetEVec3().
//
// ============================================================================
// DATA FLOW: LEVEL LOADING
// ============================================================================
//
// 1. ERLevel::AllocAndLoadLevel(EFile&)
//      -> Allocates the ERLevel, then calls ERLevel::Load(EFile&)
//
// 2. ERLevel::Load(EFile&)  [2172 bytes @ 0x80232334]
//      -> Reads serialization version from the file header
//      -> Stores version at ERLevel+0x30198 (m_readVersion)
//      -> Switches on version (0..6) for backwards compatibility:
//           Version 0-1: Legacy — read instance list as flat TNodeList
//           Version 2:   Read instance list + separate sorted list
//           Version 3:   Read instance list + sorted list + light list
//           Version 4:   Version 3 + additional wall instance list
//           Version 5:   Version 4 + floor registration data
//           Version 6:   Current — full format with all sub-lists
//
//      For each sub-list, the file contains:
//        - 4-byte count
//        - N x 4-byte instance pointers (serialized via EStorable streaming)
//
//      After reading, calls AddInstancesFromList() and AddInstancesFromBoundTree()
//      to wire all instances into the level's internal data structures.
//
// 3. ERLevel::Read(EStream&)  [1720 bytes @ 0x80231C7C]
//      -> Stream-based variant of Load. Reads 4 floats (bounds min/max)
//         from the stream header, then dispatches on version:
//           Version 0-1: Read bound tree + two TNodeLists
//           Version 2-3: Read bound tree + sorted list + count + per-instance read
//           Version 4:   Adds separate wall instance reading
//           Version 5-6: Adds floor + light instance reading
//      -> For each instance, reads from stream via operator>>(EStream&, EInstance*&)
//      -> Calls AddInstancesFromList/AddInstancesFromBoundTree to populate
//
// 4. ERLevel::Init()  [192 bytes @ 0x80233D1C]
//      -> Calls SetRoomCount(0) to allocate initial room arrays
//      -> Iterates all instances (m_instances array at this+0x30000+0x2B8):
//           For each, calls PrepareInstance() to set flags, then
//           calls the instance's virtual Init() method
//      -> Initializes the ENodeList at this+0x30000+0x264
//      -> Sets default view parameters (near/far plane distances)
//
// ============================================================================
// MEMORY LAYOUT OF ERLevel (24,740 bytes)
// ============================================================================
//
// The ERLevel is a massive struct. Key field groups (offsets relative to `this`):
//
//   +0x0000          : EStorable base (vtable, type info)
//   +0x0018          : ELightGrid (24,664 bytes) — embedded lighting grid
//   +0x0018+0x6058   : End of light grid
//
// Many fields are accessed as this+0x30000+offset (addis r9,this,3 pattern).
// This is because the struct is so large that field offsets exceed 16-bit range.
// The compiler uses a two-instruction sequence:
//     addis  r9, rThis, 3          ; r9 = this + 0x30000
//     lwz    r0, -23948(r9)        ; load from this + 0x30000 - 23948 = this + 0x5D94
//
// Key "this+0x30000+X" fields (X = signed offset from 0x30000):
//
//   this+0x21A0 (-24160 from base3):  m_pLevelData — ELevelDrawData sub-struct
//   this+0x2174 (-24204 from base3):  m_roomLightData — per-room light arrays
//   this+0x2274 (-23948 from base3):  m_instanceTree — ERedBlackTree<EInstance*>
//   this+0x2298 (-23912 from base3):  m_wallList — TNodeList of wall instances
//   this+0x22A4 (-23900 from base3):  m_sortedWallList — sorted wall TNodeList
//   this+0x22B4 (-23884 from base3):  m_roomCount — number of rooms
//   this+0x22B8 (-23880 from base3):  m_instances[] — array of instance pointers
//   this+0x3280 (-23936 from base3):  m_roomNodes[] — per-room TNodeList<EInstance*>
//   this+0x3284 (-23932 from base3):  m_roomFloors[] — per-room floor instance ptr
//   this+0x3288 (-23928 from base3):  m_roomLights[] — per-room light instance ptr
//   this+0x328C (-23924 from base3):  m_pIdMap — instance ID hash table
//   this+0x32B0 (-23888 from base3):  m_inUse flag
//   this+0x32B8 (-15688 from base3):  m_numInstances — total instance count
//   this+0x32BC (-15684 from base3):  m_wallStartIndex
//   this+0x32C0 (-15680 from base3):  m_wallEndIndex
//   this+0x32C4 (-15676 from base3):  m_firstVisibleIndex
//   this+0x32C8 (-15672 from base3):  m_drawingOrderTable flag
//   this+0x6454 (-7084 from base3):   m_pSunLightTable
//   this+0x6458 (-7080 from base3):   m_pRainInfoTable
//   this+0x645C (-7076 from base3):   m_sunYawOffset
//
// Static members:
//   ERLevel::s_levelLightingTuning  @ 0x80488B6C  (192 bytes, LevelLightingTuning)
//   ERLevel::m_typeInfo             @ 0x804FCCE8  (40 bytes)
//   ERLevel::m_drawingOrderTable    @ 0x804FEA14  (4 bytes, static bool)
//   ERLevel::m_fillingOrderTable    @ 0x804FEA18  (4 bytes, static bool)

#if 0 // SKIP — documentation-only decompilation, not compiled

#include "types.h"

// ============================================================================
// FORWARD DECLARATIONS
// ============================================================================

struct EVec2 { float x, y; };
struct EVec3 { float x, y, z; };
struct EVec4 { float x, y, z, w; };
struct EMat4 { float m[4][4]; };
struct EBound3 { EVec3 min; EVec3 max; };
struct EDirLight { EVec3 direction; EVec3 color; };
class EStream;
class EFile;
class ERC;
class EInstance;
class EStorable;
class EILight;
class EShader;
class ETypeInfo;
class E3DWindow;
class EHouse;
class ELightGrid;
class ERedBlackTree;
template<typename T> class TNodeList;

struct EOrderTableData;
struct ELevelDrawData;
struct LevelLighting;
struct LevelLightingEntry;
struct levelraininfo;
struct HTIteratorPtrType;

enum EWallUpDownStateType {
    kWallsUp     = 0,
    kWallsCutaway = 1,
    kWallsDown   = 2
};

enum TileWallsSegment {
    kSegNorth     = 0,  // +Y wall
    kSegSouth     = 1,  // -Y wall
    kSegEast      = 2,  // +X wall
    kSegWest      = 3,  // -X wall
    kSegDiagNE    = 4,  // NE diagonal
    kSegDiagNW    = 5,  // NW diagonal
    kSegDiagSE    = 6,  // SE diagonal
    kSegDiagSW    = 7   // SW diagonal
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

// ============================================================================
// CTilePt — Integer tile coordinate
// ============================================================================
//
// Size: 12 bytes (0x0C)
// Each tile is a diamond in isometric view. Coordinates are stored as
// packed integer X and Y with a level (floor) index.
//
// The conversion to world-space EVec3 uses:
//   world.x = (tileX + 0.5) * kTileSize
//   world.z = (tileY + 0.5) * kTileSize
//   world.y = level * kFloorHeight
//
// where kTileSize is typically 1.5 world units and kFloorHeight is ~3.0.

struct CTilePt {
    // 0x00: Packed tile data
    //   Byte 0: lower bits of X coordinate
    //   Byte 1: upper bits of X + flags (used by GetDirection/operator<)
    //   Byte 2: flags (set in CTilePt(void) constructor)
    //   Byte 3: padding
    u32 m_packedXY;      // 0x00

    // 0x04-0x08: Float-precision tile position (set by SetX/SetY/Set)
    //   Used by GetEVec3/GetEVec3M for world-space conversion
    float m_xf;          // 0x04
    float m_yf;          // 0x08

    int GetX() const;
    int GetY() const;
    int GetLevel() const;
    void Set(int x, int y, int level);
    EVec3 GetEVec3() const;
    bool operator==(CTilePt& other) const;
    bool operator!=(CTilePt& other) const;
};


// ============================================================================
// TileWalls — Per-tile wall configuration
// ============================================================================
//
// Size: 56 bytes (0x38)
// Each tile has up to 8 wall segments: N, S, E, W, and 4 diagonals.
// The wall data is stored in a TileWallStorage bitfield structure.
// Segments can be walls (opaque), fences (transparent), or absent.
//
// Key methods:
//   HasWall(segment) — check if a segment exists
//   HasWallNotFence(segment) — check if segment is a real wall (not fence)
//   HasFenceNotWall(segment) — check if segment is a fence
//   GetStyle(segment) — returns WallStyle enum
//   GetPattern(segment, diagSide) — wallpaper pattern index
//   GetPlacement(segment) — wall model placement variant
//   AddWall(segment) / RemoveWall(segment)
//   CanAdd(segment) — checks if adding wouldn't violate adjacency rules
//
// The wall segment indices map to the SegmentToIndex() lookup:
//   Standard: N=0, E=1, S=2, W=3  (offset 4 bytes each)
//   Diagonal: NE=4, NW=5, SE=6, SW=7  (using DiagonalSideSelector)

class TileWalls {
public:
    void** _vtable;         // 0x00
    u32  m_placement;       // 0x04 — bitfield of SheerPlacement per segment
    u16  m_segmentBits;     // 0x08 — bitmask: which segments have walls
    u8   _pad0A[2];
    u32  m_patternData[2];  // 0x0C — wallpaper pattern storage
    u16  m_styleBits;       // 0x14 — style bits per segment
    u8   _pad16[0xE];
    u32  m_canAddChecks[5]; // 0x24 — precomputed CanAdd constraint data

    bool HasWall(TileWallsSegment seg);
    bool HasWall();  // any wall at all
    bool HasWallNotFence(TileWallsSegment seg);
    bool HasFenceNotWall(TileWallsSegment seg);
    bool HasDiagonal();
    WallStyle GetStyle(TileWallsSegment seg);
    int GetPattern(TileWallsSegment seg, DiagonalSideSelector diagSide);
    void AddWall(TileWallsSegment seg);
    void RemoveWall(TileWallsSegment seg);
};


// ============================================================================
// EIWallPart — Wall segment instance
// ============================================================================
//
// Size: 3,516 bytes (0xDBC)
// Inherits from EInstance. Represents one wall segment in the 3D world.
//
// A wall segment connects two tile corners and has two faces (inside/outside).
// Each face can have an independent wallpaper pattern (shader).
//
// CONSTRUCTION:
//   EIWallPart(TileWalls& tw, TileWallsSegment seg,
//              DiagonalSideSelector diagSide, CTilePt& pos)
//   @ 0x8006ED50
//
//   1. Calls GetWallModelId() to determine which 3D model to use
//   2. Loads the model resource via ERModel
//   3. Stores tile coordinates at +0x320 and +0x324
//   4. Computes orientation matrix via SetOrient()
//   5. Sets shadow model indices at +0x358/+0x35A
//   6. Stores wallpaper shader at +0x3A0
//
// WALL MODEL SELECTION:
//   GetWallModelId(CTilePt&, TileWalls&, TileWallsSegment, DiagonalSideSelector, float&)
//   @ 0x8002BD58, 1172 bytes
//
//   Selects among ~20 wall model variants based on:
//   - Standard vs diagonal wall
//   - Adjacent wall connectivity (T-junction, L-corner, straight run)
//   - Whether neighbor tiles have walls on connecting segments
//   - Half-wall vs full-wall (checked via m_wallModelId_0A2 at +0x0A2)
//   - Pool wall vs normal wall
//
//   Returns a model ID index that maps to an ERModel resource.
//   The float& parameter receives the Y-rotation angle for placement.
//
// ORIENTATION:
//   SetOrient(EMat4&) @ 0x8006F208, 524 bytes
//
//   Stores a 4x4 transformation matrix at offsets 0x35C..0x398:
//     +0x35C: m[0][0..3]  (right vector + translate.x)
//     +0x36C: m[1][0..3]  (up vector + translate.y)
//     +0x37C: m[2][0..3]  (forward vector + translate.z)
//     +0x38C: m[3][0..3]  (perspective row)
//
//   Also extracts bounding box center for visibility testing:
//     +0x280: m_boundsCenter.x
//     +0x284: m_boundsCenter.y
//
// DRAWING:
//   Draw(ELevelDrawData&) @ 0x8002A4C0, 1620 bytes
//
//   1. Checks visibility flags at +0x05C
//   2. If not visible, early-out
//   3. Loads wall model from +0x014 and shadow flag from +0x349
//   4. Sets up render state (shader at +0x120, model at +0x01C/+0x028)
//   5. For each sub-model in the wall mesh:
//        - Sets wallpaper shader if wall face is textured
//        - Submits to order table via WallOrderTableCallback
//   6. Draw calls go through ELevelDrawData which manages the order table
//
//   WallOrderTableCallback(ELevelDrawData&, EOrderTableData*)
//   @ 0x800706C4, 896 bytes
//   - Sorts wall draw order by distance to camera
//   - Handles inside/outside face rendering order
//   - Reads adjacency info from +0x098 and +0x0A8/+0x0B8
//
// SHADOW RENDERING:
//   DrawShadow(ELevelDrawData&)     @ 0x80070A44, 332 bytes
//   DrawOutsideShadows(...)         @ 0x80070B90, 972 bytes
//
//   - Uses shadow model at +0x110 (GetShadowModel returns from +0x01C/+0x028)
//   - Shadow model indices at +0x358/+0x35A select which shadow variant
//   - Shadow projection uses sun direction at +0x3AC
//   - Outside shadows use orientation matrix at +0x37C/+0x380 for projection

class EIWallPart /* : public EInstance */ {
public:
    // Inherited EInstance fields at +0x000..~0x05C

    // Wall-specific fields:
    float  m_wallBoundsMin[3];   // 0x000 — bounding box min (inherited)
    float  m_wallBoundsMax[3];   // 0x00C — bounding box max
    u32    m_field_010;          // 0x010
    u32    m_wallModelPtr;       // 0x014 — primary wall model resource
    u32    m_field_018;          // 0x018
    u32    m_shadowModelPtr;     // 0x01C — shadow model resource
    u8     _pad020[8];           // 0x020
    u32    m_shadowModelPtr2;    // 0x028 — alternate shadow model
    u8     _pad02C[0x10];
    float  m_wallpaperBoundsX;   // 0x03C — wallpaper UV bounds
    u32    m_wallpaperShaderIdx; // 0x040 — wallpaper shader index
    u8     _pad044[0x18];
    u32    m_visFlags;           // 0x05C — visibility bitmask (bit 0=front, bit 1=back)
    u8     _pad060[8];
    u32    m_field_068;          // 0x068
    u8     _pad06C[4];
    u32    m_drawFlags;          // 0x070 — draw control flags
    u8     _pad074[0x24];
    u32    m_sortKey;            // 0x098 — order table sort key
    u8     _pad09C[6];
    s16    m_halfWallFlag;       // 0x0A2 — half-wall detection
    u8     _pad0A4[4];
    u32    m_otdLinkA;           // 0x0A8 — order table data link
    u8     _pad0AC[0xC];
    u32    m_otdLinkB;           // 0x0B8 — order table data link 2
    u8     _pad0BC[0x34];
    u32    m_levelDrawDataPtr;   // 0x0F0 — back-pointer to ELevelDrawData
    u8     _pad0F4[0x1C];
    u32    m_shadowModelIdx;     // 0x110 — shadow sub-model index
    u8     _pad114[4];
    u32    m_renderFlags;        // 0x118 — rendering control flags
    u32    m_outsideShadowFlag;  // 0x11C — has outside shadow
    u32    m_wallpaperResPtr;    // 0x120 — wallpaper EShader resource
    u8     _pad124[4];
    u32    m_field_128;          // 0x128
    u8     _pad12C[0xC];
    u32    m_field_138;          // 0x138
    u8     _pad13C[0xDC];
    u32    m_field_218;          // 0x218
    u8     _pad21C[0x64];
    float  m_boundsCenterX;     // 0x280 — bounding center X (for vis test)
    float  m_boundsCenterY;     // 0x284 — bounding center Y (for vis test)
    u8     _pad288[0x98];
    u32    m_tileX;             // 0x320 — tile X coordinate (CTilePt data)
    u32    m_tileY;             // 0x324 — tile Y coordinate
    u8     _pad328[4];
    u32    m_field_32C;         // 0x32C
    u32    m_field_330;         // 0x330
    u8     _pad334[0x15];
    u8     m_shadowEnabled;     // 0x349 — shadow draw flag
    u8     _pad34A[6];
    u32    m_field_350;         // 0x350
    u32    m_wallModelVariant;  // 0x354 — selected wall model variant
    s16    m_shadowIdxA;        // 0x358 — shadow variant index A
    s16    m_shadowIdxB;        // 0x35A — shadow variant index B
    // Orientation matrix (3x4):
    float  m_orient[12];       // 0x35C..0x38C — 4x3 transform matrix
    float  m_orientRow3[4];    // 0x38C..0x39C — 4th row (perspective)
    u32    m_wallpaperShader;   // 0x3A0 — active wallpaper shader ID
    u8     _pad3A4[8];
    u32    m_sunShadowDir;      // 0x3AC — sun shadow direction data
    u8     _pad3B0[0x9F8];
    float  m_otdSortDist;       // 0xDA8 — order table sort distance
    u8     _padDAC[8];
    float  m_shadowProjX;       // 0xDB4 — shadow projection X
    float  m_shadowProjZ;       // 0xDB8 — shadow projection Z
};


// ============================================================================
// EIFenceWall — Fence wall instance
// ============================================================================
//
// Size: 944 bytes (0x3B0)
// Inherits from EInstance. A lightweight wall that does NOT form room boundaries.
// Fences are transparent to room detection but still render and collide.
//
// CONSTRUCTION:
//   EIFenceWall(TileWallsSegment& seg, CTilePt& pos, WallStyle style)
//   @ 0x8006E0D8
//
//   - Stores segment and position at +0x358/+0x35A (same offsets as EIWallPart)
//   - Sets up the fence model based on WallStyle (picket, wrought iron, etc.)
//   - Allocates a sub-array at +0x3AC if the fence has decorative posts
//
// RENDERING:
//   Draw(ELevelDrawData&) @ 0x8006F4FC, 64 bytes
//   - Delegates to EIWallPart::Draw (fence shares wall rendering logic)
//   - The 64-byte function is just a thunk that adjusts parameters
//
//   VisibilityTest(E3DWindow&) @ 0x8006DA88, 88 bytes
//   - Tests bounding box against view frustum
//   - Simpler than EIWallPart because fences are always single-sided
//
//   IsOpaque() @ 0x8007F68C, 40 bytes
//   - Always returns false — fences never occlude
//
// ROOM BOUNDARY BEHAVIOR:
//   Fences do NOT participate in room boundary computation.
//   RoomManager::ComputeRooms() uses TileWalls::HasWallNotFence() to skip them.
//   This means a room can extend through a fence into adjacent space.
//   EFenceWall::IsWallsOpaque() always returns false (address 0x8039E4B0, 8 bytes).

class EIFenceWall /* : public EInstance */ {
public:
    void** _vtable;          // 0x000
    u32    m_instanceType;   // 0x004 — EInstance type marker
    u8     _pad008[0x350];   // 0x008 — inherited EInstance data
    u16    m_segmentType;    // 0x358 — TileWallsSegment
    u16    m_diagSide;       // 0x35A — DiagonalSideSelector
    u8     _pad35C[0x50];
    u32    m_postArray;      // 0x3AC — decorative post sub-objects

    bool IsOpaque() { return false; }  // fences never occlude
};


// ============================================================================
// EIFloor — Floor tile instance
// ============================================================================
//
// Size: 288 bytes (0x120)
// Inherits from EInstance. Represents one floor tile in the world.
//
// FLOOR CREATION:
//   CreateFloors(EHouse*) @ 0x800477D0, 1460 bytes
//
//   This is the core floor tile generation function. It:
//
//   1. Calls EFloorShdTblNode::BuildTable() to generate the floor shadow table
//   2. Allocates a 7312-byte scratch buffer (0x1C90) for floor geometry processing
//   3. Initializes a ChainResFile for floor model resources
//   4. Iterates over all rooms in the lot:
//        - For each Room, checks if it has tiles (via Room::IsOutside and tile list)
//        - Skips outside rooms unless they have a floor pattern
//        - For each room, uses ChainResFile lookup to find the floor model
//   5. For each valid floor tile:
//        - Allocates a 304-byte (0x130) EIFloor instance
//        - Stores room ID at +0x07C (m_roomId)
//        - Stores the floor model reference at +0x01C
//        - Stores the floor pattern resource at +0x108
//        - Computes floor height from room level
//   6. For diagonal tiles, creates two triangular floor halves
//      (one for each side of the diagonal wall)
//   7. Registers each floor with its room's lighting group
//
//   The floor creation uses a lookup table at the ChainResFile (+0x50 offset)
//   to map room ID -> floor model. Floor models are indexed by pattern type:
//     - Carpet patterns: model indices 0..N
//     - Tile patterns: model indices N+1..M
//     - Wood patterns: model indices M+1..P
//
// LIGHTING CALCULATION:
//   DoLightingCalculation() @ 0x80046614, 1160 bytes
//
//   Computes per-vertex lighting colors for the floor tile:
//   1. Reads the room's ambient light level from the lighting grid
//   2. Iterates over all active lights in the room (point lights, ambient lights)
//   3. For each light:
//        - Computes distance from light to each floor vertex
//        - Applies attenuation curve (quadratic falloff)
//        - Accumulates light color contribution
//   4. Clamps final vertex colors to [0, 1]
//   5. Stores computed colors at +0x104/+0x108/+0x10C
//      (these feed into the floor shadow stencil rendering)
//
//   The lighting uses data from:
//     +0x000: m_roomBitmask — which room IDs this floor belongs to
//     +0x004: m_stencilData — shadow stencil table pointer
//     +0x07E: m_numVertices — vertex count for lighting
//     +0x080: m_lightingDirty — flag set when lighting needs recalc
//
// DRAWING:
//   Draw(ELevelDrawData&) @ 0x800D2A58, 820 bytes
//     - Checks m_lightingDirty at +0x080; if set, recalculates lighting
//     - Loads floor model geometry from +0x0F0
//     - Applies per-vertex colors from lighting calculation
//     - Sets shader state for floor material
//     - Submits floor geometry to the render pipeline
//
//   DrawStencil(ELevelDrawData&) @ 0x800D2D8C, 544 bytes
//     - Renders floor into stencil buffer for shadow reception
//     - Uses stencil data at +0x004
//     - Only draws if room is visible (checked via m_roomBitmask)
//
//   DrawShadow(ELevelDrawData&) @ 0x800D2FAC, 164 bytes
//     - Renders shadow overlay on the floor tile
//     - Uses pre-computed shadow projection from sun direction

class EIFloor /* : public EInstance */ {
public:
    u16    m_roomBitmask;      // 0x000 — room membership bitmask
    u8     _pad002[2];
    u32    m_stencilData;      // 0x004 — shadow stencil table
    u32    m_lightDataA;       // 0x008 — lighting calculation data
    u32    m_lightDataB;       // 0x00C
    u32    m_lightDataC;       // 0x010
    u8     _pad014[8];
    u32    m_floorModelRef;    // 0x01C — floor model resource ref
    u8     _pad020[8];
    u32    m_field_028;        // 0x028
    u8     _pad02C[0x20];
    float  m_floorHeight;      // 0x04C — Y-position of floor surface
    u8     _pad050[0xC];
    u32    m_field_05C;        // 0x05C
    u8     _pad060[0x1C];
    u32    m_roomId;           // 0x07C — owning room ID
    u16    m_numVertices;      // 0x07E — vertex count for lighting
    u8     m_lightingDirty;    // 0x080 — lighting needs recalculation
    u8     m_vertexColorR;     // 0x081 — base vertex color R
    u8     m_vertexColorG;     // 0x082 — base vertex color G
    u8     m_vertexColorB;     // 0x083 — base vertex color B
    u16    m_patternIndex;     // 0x084 — floor pattern/material index
    u8     _pad086[0x6A];
    u32    m_geometryPtr;      // 0x0F0 — floor geometry data
    u8     _pad0F4[0x10];
    u32    m_computedColorA;   // 0x104 — computed vertex color A (RGBA packed)
    u32    m_computedColorB;   // 0x108 — computed vertex color B
    u32    m_computedColorC;   // 0x10C — computed vertex color C
    u32    m_field_110;        // 0x110
    u8     _pad114[8];
    u32    m_field_11C;        // 0x11C
};


// ============================================================================
// ERoomWall — Contiguous wall run
// ============================================================================
//
// Size: 276 bytes (0x114)
// Represents a group of connected wall segments sharing a common wall line.
// Multiple EIWallPart instances are grouped under one ERoomWall.
//
// CONSTRUCTION:
//   ERoomWall(TileWallsSegment seg, DiagonalSideSelector diagSide,
//             CTilePt& startPos, bool isDiagonal)
//   @ 0x80072CDC
//
//   Creates an ERoomWall and begins building the wall run from the start tile.
//
// TILE ADDING:
//   AddTile(CTilePt& pos, TileWalls& tw, TileWallsSegment seg,
//           DiagonalSideSelector diagSide, bool flag)
//   @ 0x80073C8C, 392 bytes
//
//   Extends the wall run to include a new tile. Updates:
//   - Wall length count at +0x010
//   - Running bounding box at +0x000..+0x00C
//   - Wall normal direction at +0x020
//   - Wallpaper cost accumulation
//
// KEY FIELDS:
//   +0x000: m_boundsMinX      — wall run bounding box
//   +0x004: m_boundsMinZ
//   +0x008: m_boundsMaxX
//   +0x00C: m_boundsMaxZ
//   +0x010: m_numTiles         — number of tiles in this wall run
//   +0x014: m_wallPartListPtr  — linked list of EIWallPart instances
//   +0x020: m_wallLength       — total wall length in world units
//   +0x024: m_parentRoom       — back-pointer to owning ERoom
//   +0x034: m_wallDirection    — primary direction of wall run
//   +0x094: m_opaqueState      — per-room opacity flags array
//   +0x0A0: m_distToCam        — per-room distance-to-camera array
//
// DRAWING:
//   DrawWall(ERC*) @ 0x80073E14, 1888 bytes
//   DrawWallpaperPreview(ERC*, EVec2&) @ 0x8007497C, 1764 bytes
//
// ROOM QUERIES:
//   getRoomIdFromPoint(CTilePt&) @ 0x80074574, 884 bytes
//   getWallNormalOnSideOfCursor(EVec3&, EVec3&, EVec2&, EVec2&) @ 0x800748E8
//
//   Determines which room is on each side of the wall by checking
//   tile occupancy in the RoomManager's collision map.

class ERoomWall {
public:
    float  m_boundsMinX;       // 0x000
    float  m_boundsMinZ;       // 0x004
    float  m_boundsMaxX;       // 0x008
    float  m_boundsMaxZ;       // 0x00C
    u16    m_numTiles;         // 0x010
    u8     _pad012[2];
    u32    m_wallPartList;     // 0x014
    u8     _pad018[4];
    u32    m_wallPaperCostPtr; // 0x01C
    float  m_wallLength;       // 0x020
    u32    m_parentRoom;       // 0x024
    u16    m_field_028;        // 0x028
    u8     _pad02A[2];
    u32    m_field_02C;        // 0x02C
    u32    m_field_030;        // 0x030
    float  m_wallDirection;    // 0x034
    float  m_field_038;        // 0x038
    u32    m_field_03C;        // 0x03C
    u8     _pad040[0x10];
    // wallpaper preview draw data at 0x050..0x110
    u32    m_opaqueState;      // 0x094
    u8     _pad098[8];
    u32    m_distToCam;        // 0x0A0
};


// ============================================================================
// ERoom — Wall lookup table and room boundary processor
// ============================================================================
//
// Size: 180 bytes (0xB4)
// ERoom manages the wall geometry for one floor level. It processes the
// per-tile TileWalls data into connected ERoomWall segments and handles
// wall visibility, wallpaper editing, and fade state transitions.
//
// INITIALIZATION:
//   InitRoomLookupTab() @ 0x8002DCF0, 384 bytes
//
//   Builds the wall lookup tables used by GetWallFromTileAndSegment():
//   1. Iterates the entire tile grid (from the FixedWorldImpl)
//   2. For each tile with walls, stores a reference in the lookup hash
//   3. The hash maps (tileX, tileY, segment) -> ERoomWall*
//   4. Lookup table stored at +0x008 (m_wallFromTileAndSegment)
//
// WALL PROCESSING — THE CORE ALGORITHM:
//   ProcStandardWalls(bool reverse, int& wallCount, int& fenceCount, bool preview)
//   @ 0x8002EC60, 676 bytes
//
//   This processes all 4 standard wall segments (N, S, E, W) for every tile:
//
//   1. Sets up 4 iteration descriptors on the stack, one per segment:
//        - Stack+0x18: Segment N, pointer to this+0x28 (North wall TNodeList)
//        - Stack+0x20: Segment E, pointer to this+0x10 (East wall TNodeList)
//        - Stack+0x28: Segment S, pointer to this+0x1C (South wall TNodeList)
//        - Stack+0x30: Segment W, pointer to this+0x04 (West wall TNodeList)
//
//   2. Gets the tile grid dimensions from cFixedWorldImpl:
//        - Reads grid width  via vtable call (offset 0x30/0x34 in vtable)
//        - Reads grid height via vtable call (offset 0x38/0x3C in vtable)
//        - If `reverse` flag is set, swaps width/height for iteration order
//
//   3. Double-nested loop over all tiles:
//        For y in [0..height):
//          For x in [0..width):
//            - Gets TileWalls for tile (x, y) from cFixedWorldImpl
//            - Calls ProcessCell() for each standard segment that has a wall
//
//   4. For each segment, ProcessCell() either:
//        - Extends an existing ERoomWall if the current tile continues the run
//        - Creates a new ERoomWall if starting a new wall section
//
//   ProcDiagonalWalls(int& wallCount, int& fenceCount, bool preview)
//   @ 0x80077620, 1368 bytes
//
//   Same concept but for diagonal walls (NE, NW, SE, SW segments).
//   Diagonal walls cannot form multi-tile runs; each is a single segment.
//
// CELL PROCESSING:
//   ProcessCell(TNodeList<ERoomWall*>& wallList, ERoomWallPtr& currentWall,
//               CTilePt& pos, TileWallsSegment seg, DiagonalSideSelector diagSide,
//               TileWalls& tw, int wallIndex, int& wallCount, int& fenceCount, bool)
//   @ 0x8002F264, 632 bytes
//
//   For one tile and one segment:
//   1. Checks if the segment has a wall (tw.HasWall(seg))
//   2. If fence: creates EFenceWall, increments fenceCount
//   3. If wall: checks if currentWall can be extended
//        - Same direction? Same wall type? Adjacent tile?
//        - If yes: AddTile() to extend currentWall
//        - If no: finalize currentWall, create new ERoomWall
//   4. Creates EIWallPart for the wall model geometry
//   5. Sets wall visibility based on room adjacency
//
// WALL VISIBILITY:
//   CalAllRoomOpaque(int level) @ 0x80075CA8, 604 bytes
//   CalRoofOpaque(int level)    @ 0x80076154, 1216 bytes
//   CalShortDistToCam(int level) @ 0x80076614, 896 bytes
//
//   These compute per-room wall transparency:
//   - Walls facing the camera get alpha-faded based on distance
//   - Interior walls can be made transparent to see inside rooms
//   - "Cutaway" mode slices walls at a height plane
//
// WALL STATE TRANSITIONS:
//   SetWallState(EWallUpDownStateType state) @ 0x80076A34, 220 bytes
//   UpdateWallFade(int frame) @ 0x80076D24, 368 bytes
//
//   Manages the wall up/down/cutaway animation:
//   - kWallsUp: all walls fully visible
//   - kWallsCutaway: walls cut at camera height
//   - kWallsDown: walls hidden (for overhead view)
//   - Fade interpolation stored at +0x0AC/+0x0B0

class ERoom {
public:
    void** _vtable;              // 0x000
    u32    m_field_004;          // 0x004 — West wall TNodeList
    u32    m_wallLookupHash;     // 0x008 — wall lookup hash table
    u8     _pad00C[4];
    u16    m_gridWidth;          // 0x010 — tile grid width
    u8     _pad012[2];
    u32    m_field_014;          // 0x014
    u8     _pad018[4];
    u32    m_wallPartListPtr;    // 0x01C — master wall part list
    u8     _pad020[8];
    u32    m_field_028;          // 0x028 — South wall TNodeList
    u8     _pad02C[8];
    u32    m_field_034;          // 0x034 — preview mode flag
    u8     _pad038[4];
    u32    m_field_03C;          // 0x03C — opacity calc temp
    u32    m_field_040;          // 0x040
    u8     _pad044[8];
    u32    m_field_04C;          // 0x04C
    u8     _pad050[8];
    u32    m_field_058;          // 0x058
    u8     _pad05C[8];
    u32    m_field_064;          // 0x064
    u8     _pad068[8];
    u32    m_field_070;          // 0x070
    u32    m_field_074;          // 0x074
    u32    m_field_078;          // 0x078
    u32    m_field_07C;          // 0x07C
    u32    m_field_080;          // 0x080
    u32    m_field_084;          // 0x084
    u32    m_field_088;          // 0x088
    u32    m_field_08C;          // 0x08C
    u32    m_field_090;          // 0x090
    u32    m_opaqueArray;        // 0x094 — per-room opacity data
    u8     _pad098[8];
    u32    m_distToCamArray;     // 0x0A0 — per-room dist-to-cam data
    u8     _pad0A4[8];
    float  m_fadeAlpha;          // 0x0AC — current wall fade alpha
    float  m_fadeTarget;         // 0x0B0 — target wall fade alpha
};


// ============================================================================
// Room — Logical room with environment scoring
// ============================================================================
//
// Size: 164 bytes (0xA4)
// Represents a logical room: a set of tiles enclosed by walls.
// Created and managed by RoomManager.
//
// ROOM DETECTION ALGORITHM:
//   Room::IsOutside() @ 0x80138420, 276 bytes
//
//   Determines if a room is "outside" (not enclosed by walls):
//
//   1. Check if room has tiles (m_tileListSize at +0x034):
//        If 0, return false immediately
//   2. If m_isOutsideCached at +0x088 is set, return cached value at +0x08C
//   3. Otherwise, iterate the room's tile list (starting at +0x004):
//        For each tile (stored as 3-byte entries: x, y, level):
//          - Query cFixedWorldImpl for the tile at this position
//          - Get the room ID for this tile
//          - If room ID matches our room ID:
//              Check if the tile is on the world boundary
//              (via vtable call at offset 0xF8/0xFC)
//              If boundary tile: set boundary flag, cache isOutside=true
//   4. If no boundary tiles found:
//        Count total tiles. If only 1 tile:
//          m_isOutside = 1 (single tile = outside by convention)
//        Else:
//          m_isOutside = 0 (enclosed room)
//   5. Set m_isOutsideCached = 1 to cache the result
//   6. Return m_isOutside
//
//   The key insight: a room is "outside" if ANY of its tiles touch
//   the world boundary. The world boundary is the edge of the lot grid.
//
// ROOM SCORING:
//   Room::ComputeRoom() @ 0x801377D8, 896 bytes
//
//   Computes the room's environment score (0.0 = terrible, 1.0 = perfect):
//
//   1. Call IsOutside():
//        If OUTSIDE:
//          - Get ambient light multiplier from the lighting system
//          - Score = ambientLight * kOutsideBaseScore
//          - Store at +0x080 (m_ambientLight)
//
//        If INSIDE:
//          a. Get room area (tile count) and normalize:
//               areaFactor = area / maxRoomArea
//               areaFactor = clamp(areaFactor, 0, 1)
//
//          b. Get room's total object score:
//               objectScore = sum of all object environment scores in room
//               objectFactor = objectScore / area
//               objectFactor = clamp(objectFactor, 0, maxObjectScore)
//               objectFactor = objectFactor * kObjectWeight
//
//          c. Compute light contribution:
//               Get tile count, compute tile density
//               lightFactor = brightness / tileCount
//               lightFactor = clamp(lightFactor, minLight, maxLight)
//
//          d. Compute furniture density:
//               densityFactor = objectCount / area
//               Map through piecewise function (too empty=bad, too crowded=bad)
//
//          e. Final score:
//               score = areaScore + objectScore + lightScore + densityScore
//               score = clamp(score, 0.0, 1.0)
//               Store at +0x07C
//
//   The score uses constants loaded from r13-relative storage
//   (the small data area), including:
//     r13-0x5DF4: kOutsideBaseScore
//     r13-0x5DF0: kAreaWeight
//     r13-0x5DEC: kObjectWeight
//     r13-0x5DE8: kLightWeight
//     r13-0x5DE4: kMinLightLevel
//     r13-0x5DE0: kMaxLightLevel
//     r13-0x5DDC: kDensityWeight
//     r13-0x5DD8: kMaxDensity
//
// ROOM DATA:
//   +0x000: m_tileList (with 2-byte inline room ID at top)
//   +0x004: m_tileListData — vector<CTilePt> of tiles
//   +0x034: m_tileListSize — number of tiles
//   +0x04C: m_objectScore — cumulative environment score from objects
//   +0x050: m_objectCount — number of objects in room
//   +0x054: m_decorScore — decoration sub-score
//   +0x058..0x070: additional object type sub-scores
//   +0x074: m_wallTileCount — tiles with walls
//   +0x078: m_windowTileCount — tiles with windows
//   +0x07C: m_finalScore — computed room score
//   +0x080: m_ambientLight — room ambient light level
//   +0x084: m_flags
//   +0x088: m_isOutsideCached — cache validity flag
//   +0x08C: m_isOutside — cached outside status
//   +0x090: m_overheadLightEnabled
//   +0x094: m_overheadLightBrightness
//   +0x098: m_lightingGroupId
//   +0x09C: m_ambientLightAccum
//   +0x0A0: m_ambientLightCount

class Room {
public:
    u16    m_roomId;               // 0x000 (first 2 bytes of m_partition field)
    u16    m_field_002;            // 0x002
    u32    m_tileListData;         // 0x004 — vector of CTilePt
    float  m_field_008;            // 0x008
    u8     _pad00C[8];
    u32    m_field_014;            // 0x014
    u8     _pad018[0xC];
    u32    m_partitionData;        // 0x024 — SpacePartition data
    u8     _pad028[0xC];
    u32    m_tileListSize;         // 0x034 — tile count
    u32    m_field_038;            // 0x038
    u8     _pad03C[8];
    u32    m_field_044;            // 0x044
    float  m_field_048;            // 0x048
    u32    m_objectScore;          // 0x04C
    u32    m_objectCount;          // 0x050
    u32    m_decorScore;           // 0x054
    u32    m_field_058;            // 0x058
    u32    m_field_05C;            // 0x05C
    u32    m_field_060;            // 0x060
    u32    m_field_064;            // 0x064
    u32    m_field_068;            // 0x068
    u32    m_field_06C;            // 0x06C
    u32    m_field_070;            // 0x070
    u32    m_wallTileCount;        // 0x074
    u32    m_windowTileCount;      // 0x078
    float  m_finalScore;           // 0x07C — environment score [0..1]
    float  m_ambientLight;         // 0x080 — room ambient light
    u32    m_flags;                // 0x084
    u32    m_isOutsideCached;      // 0x088
    u32    m_isOutside;            // 0x08C
    u32    m_overheadLightEnabled; // 0x090
    u32    m_overheadLightLevel;   // 0x094
    u32    m_lightingGroupId;      // 0x098
    u32    m_ambientLightAccum;    // 0x09C
    u32    m_ambientLightCount;    // 0x0A0
};


// ============================================================================
// RoomManager — Room detection system
// ============================================================================
//
// Size: 56 bytes (0x38)
// Singleton manager that owns all Room objects and drives room computation.
//
// ROOM DETECTION ALGORITHM (ComputeRooms):
//   RoomManager::ComputeRooms() @ 0x80136274, 784 bytes
//
//   This is the main room detection entry point, called when walls change:
//
//   1. INITIALIZATION:
//      - If the tile occupation map hasn't been built (field +0x024 == 0):
//          Call internal BuildOccupationMap() to mark which tiles are walkable
//          Set flag +0x024 = 1
//      - Get the room collection (red-black tree at +0x004)
//      - Initialize indoor tile counter to 0
//
//   2. PER-ROOM ITERATION (first pass — compute room properties):
//      For each Room in the red-black tree:
//        - Get room pointer from tree node (+0x014)
//        - If room is null, skip
//        - If room has no tiles (m_tileListSize == 0), skip
//        - If room has no valid flags (m_flags == 0), skip
//        - Save current ambient light multiplier (GetAmbientLightMultiplier())
//        - Call Room::CollectObjectStats() — enumerate objects in room
//        - Reset room's dirty flag and recalc flags
//        - Iterate the room's tile list:
//            For each tile (as CTilePt, 3 bytes per entry: x<<1|y_hi, y_lo, level):
//              Call Room::CollectTileStats(tilePt)
//              — This counts walls, windows, doors, updates sub-scores
//        - Call Room::ComputeRoom() to calculate the final environment score
//        - Compare new ambient light multiplier with saved value
//          If changed: signal lighting update (RoomLightingChanged)
//        - If room is NOT outside and has valid tiles:
//            Call Room::GetArea() to get tile count
//            Add to indoor tile counter
//
//   3. COMPUTE AVERAGE ENVIRONMENT SCORE (second pass):
//      For each Room:
//        - If outside, skip
//        - If valid: accumulate roomScore into running total at +0x02C
//      - finalAverage = total / kScoreDivisor (from r13-relative constants)
//      - Store at +0x028
//
//   4. APPLY DIFFICULTY MODIFIER:
//      Query the game difficulty level (via vtable on a global object):
//        difficulty 0 (easy):   average += easyBonus
//        difficulty 1 (medium): average += mediumBonus
//        difficulty 2 (normal): average += normalBonus
//        difficulty 3 (hard):   average += hardBonus
//      Clamp final average to [kMinScore, kMaxScore]
//      (kMinScore/kMaxScore loaded from r9-relative constants)
//
//   5. REPORT RESULTS:
//      Signal the mood system with the indoor tile count
//      (via vtable call: SetVar with ID 27 = indoor_tile_count)
//      Clear the rooms-dirty flag at +0x020
//
// ROOM CREATION:
//   RoomManager::GetNewRoom(unsigned short roomId) @ 0x8039CF38, 576 bytes
//
//   Creates a new Room object and inserts it into the red-black tree.
//   Room IDs are assigned sequentially. Room ID 0 is reserved for "outside."
//
// WORLD OFFSET:
//   RoomManager::OffsetWorld(CTilePt& offset) @ 0x8039D1FC, 432 bytes
//
//   Shifts all room tile coordinates by the given offset. Used when
//   the lot position changes within the neighborhood.
//
// DIAGONAL RESOLUTION:
//   RoomManager::ResolveDiagonal(CTilePt& pos, Room** roomA, Room** roomB,
//                                Room::Sides* sideA, Room::Sides* sideB)
//   @ 0x8039D66C, 524 bytes
//
//   For a diagonal wall tile, determines which room is on each side.
//   The diagonal splits the tile into two triangular halves, each
//   potentially belonging to a different room.

class RoomManager {
public:
    void** _vtable;               // 0x000
    u16    m_field_002;           // 0x002
    u32    m_roomTree;            // 0x004 — _Rb_tree of Room* keyed by room ID
    u32    m_field_008;           // 0x008
    u8     m_occupationMapBuilt; // 0x00C
    u8     _pad00D[3];
    u32    m_field_010;           // 0x010
    u32    m_roomIntensityScale;  // 0x014
    u32    m_field_018;           // 0x018
    u8     m_field_01C;           // 0x01C
    u8     _pad01D[3];
    u32    m_roomsDirty;          // 0x020 — set when rooms need recomputation
    u32    m_occupationMapReady;  // 0x024
    float  m_averageScore;        // 0x028 — average environment score
    float  m_totalScore;          // 0x02C — total environment score
    u8     _pad030[4];
    u32    m_field_034;           // 0x034
};


// ============================================================================
// ERLevel — SCENE GRAPH AND RENDERING
// ============================================================================
//
// ERLevel is the root of the rendering scene graph. All instances, walls,
// floors, and lights are registered with it.
//
// INSTANCE MANAGEMENT:
//
//   ERLevel::InsertInstance(EInstance* inst, EInstance* after)
//   @ 0x802331BC, 60 bytes
//   - Inserts into the main instance linked list (TNodeList at +0x30000+0x2274)
//   - Sets the instance's level pointer
//
//   ERLevel::AddInstanceToLevel(EInstance* inst)
//   @ 0x80233454, 232 bytes
//   - Full registration: calls InsertInstance, then AddInstanceToRoom
//   - Adds to ID map if instance has an ID
//   - Calls PrepareInstance to set render flags
//
//   ERLevel::AddWallInstanceToLevel(EInstance* wallInst)
//   @ 0x8023362C, 420 bytes
//   - Specialized wall insertion that maintains sort order
//   - Walls are grouped by their tile group (GetWallType returns group index)
//   - Binary search on existing wall array to find insertion point
//   - Maintains m_wallStartIndex and m_wallEndIndex range
//   - If first wall, sets both start/end to current count
//   - Subsequent walls: finds correct slot by comparing GetWallType
//     group and sub-model index (+0x110 field on wall instance)
//
//   ERLevel::InsertWall(EInstance* wallInst, bool addToSortedList)
//   @ 0x80233210, 92 bytes
//   - Calls InsertInstance first
//   - If addToSortedList: adds to m_sortedWallList (+0x30000+0x2298)
//     via TNodeList::InsertAt() and stores list iterator at inst+0x078
//   - Otherwise: sets inst+0x078 = 0 (not in sorted list)
//
// ROOM ASSIGNMENT:
//
//   ERLevel::GetRoomIndex(EInstance* inst) const
//   @ 0x80233964, 120 bytes
//
//   Determines which room an instance belongs to:
//   1. Check if instance has a tile callback (inst+0x01C != 0)
//      - If yes: call the callback to get tile position (x, y)
//      - Read tile Y coordinate from stack result
//   2. If no callback: set tile to (0, 0) — defaults to room 0
//   3. Validate room index against m_roomCount
//      - If index < 0 or >= m_roomCount: return m_roomCount (default room)
//   4. Return the room index
//
//   ERLevel::AddInstanceToRoom(EInstance* inst)
//   @ 0x80233824, 164 bytes
//
//   Assigns an instance to a room's data structures:
//   1. Call GetRoomIndex() to find the room
//   2. Store room index at inst+0x054
//   3. Check instance flags at inst+0x05C:
//      - If flag 0x00010000 (wall): store in m_roomFloors[roomIdx]
//        Set inst+0x078 = 0
//      - If flag 0x00020000 (floor/furniture):
//        Insert into m_roomNodes[roomIdx] TNodeList
//        Store iterator at inst+0x078
//      - If flag 0x00008000 (auto-register): call instance's virtual
//        RegisterWithRoom method (vtable offset 0xB8/0xBC)
//
// FLOOR REGISTRATION:
//
//   ERLevel::RegisterFloor(EOrderTableData& otd)
//   @ 0x8023637C, 100 bytes
//
//   Registers a floor tile's order table data for rendering:
//   1. Check if m_roomLights array exists (at +0x30000+0x3288)
//   2. Call AllocAndCopyOTD() to clone the order table entry
//   3. Get room index via GetRoomIndex on the OTD's instance
//   4. Link the new OTD into the per-room floor chain:
//      newOTD->next = m_roomLights[roomIdx]
//      m_roomLights[roomIdx] = newOTD
//
// ROOM COUNT MANAGEMENT:
//
//   ERLevel::SetRoomCount(int count)
//   @ 0x80236CA8, 480 bytes
//
//   Allocates/reallocates the per-room data arrays:
//   1. If m_roomNodes array exists (at +0x30000+0x3280):
//      - Destroy all TNodeList entries (iterate backwards, calling destructor)
//      - Free the array memory
//   2. Free m_roomFloors array (at +0x30000+0x3284)
//   3. If m_roomLights array exists (at +0x30000+0x3288):
//      - For each room, call SafeDelete on each light instance
//      - Free the array memory
//   4. Allocate new arrays for (count + 1) rooms:
//      - m_roomNodes: array of TNodeList<EInstance*>, each 12 bytes
//        Initialize each: {data=0, next=0, size=1}
//      - m_roomFloors: array of EInstance* (one per room + 1)
//      - m_roomLights: array of EInstance* (one per room + 1)
//   5. Zero-fill m_roomFloors and m_roomLights
//   6. Store new count at +0x30000+0x22B4 (m_roomCount)
//   7. Re-add all existing instances to their rooms:
//      For idx in [m_firstVisibleIndex..m_numInstances):
//        AddInstanceToRoom(m_instances[idx])
//
// ============================================================================
// RENDERING PIPELINE
// ============================================================================
//
// ERLevel::Draw(ERC*) @ 0x80234C98, 4364 bytes
//
// This is the main rendering entry point. The massive function orchestrates
// the entire frame rendering:
//
// 1. SETUP:
//    - Set static flag m_drawingOrderTable = true
//    - Compute view frustum planes from camera
//    - Calculate draw radius based on view parameters
//      (CalcRadiusFromViewParams at 0x80234438)
//
// 2. VISIBILITY DETERMINATION:
//    - Iterate all instances in the instance array
//    - For each: test bounding box against view frustum
//    - Build visible instance list
//
// 3. WALL RENDERING:
//    - Iterate wall instances (m_wallStartIndex to m_wallEndIndex)
//    - For each visible wall:
//        - Call wall's Draw method
//        - Apply wall fade state (cutaway/down/up)
//        - Draw wall shadows if sun is active
//
// 4. ORDER TABLE FILLING:
//    - Set m_fillingOrderTable = true
//    - For each visible non-wall instance:
//        - Call InsertInOrderTable() to depth-sort
//    - For each floor instance:
//        - Call RegisterFloor() to add to per-room floor chains
//    - Set m_fillingOrderTable = false
//
// 5. SHADOW RENDERING:
//    - DrawObjectShadowsOutside() for outdoor shadows
//    - DrawObjectShadowsInside() for indoor shadows
//    - Uses sun direction from m_sunLight data (+0x604C..+0x606C)
//
// 6. ORDER TABLE DRAW:
//    - DrawOrderTable() processes depth-sorted entries front-to-back
//    - For each entry: calls DrawOrderTableEntry(otd, rc)
//    - Handles transparency blending
//
// 7. DOF FOREGROUND:
//    - DrawDOFForegroundObjects() renders depth-of-field foreground
//
// 8. CLEANUP:
//    - Set m_drawingOrderTable = false
//
// ERLevel::Update() @ 0x802343A0, 152 bytes
//
// Per-frame update:
// 1. Call UpdateLightGrid() to refresh light probe data
// 2. Call UpdatePerRoomData() which calls UpdateFloorLighting()
// 3. Walk the instance tree and call Update() on each dirty instance
//    (checks flags at inst+0x05C for dirty bit 0x10)
//
// ERLevel::UpdateFloorLighting() @ 0x80237918, 136 bytes
//
// Iterates all per-room floor instances:
// For each room (0..m_roomCount):
//   - Get floor instance from m_roomFloors[room]
//   - If non-null: call the floor's DoLightingCalculation()
//     (vtable call at offset 0x68/0x6C)
// This updates per-vertex floor colors based on current light state.
//
// ============================================================================
// LIGHTING ZONES
// ============================================================================
//
// The lighting system divides the world into zones:
//
// 1. PER-ROOM ZONES:
//    Each room has its own ambient light level, overhead light state,
//    and point light dimmer. The Room class tracks:
//      - m_ambientLight (+0x080): base ambient brightness
//      - m_overheadLightEnabled (+0x090): ceiling light on/off
//      - m_overheadLightLevel (+0x094): ceiling light brightness
//      - m_lightingGroupId (+0x098): shared lighting group ID
//      - PointLightDimmer: scales all point lights in this room
//
// 2. LIGHTING GROUPS:
//    Multiple rooms can share a lighting group (via m_lightingGroupId).
//    When one room's lighting changes, all rooms in the same group update.
//    This is used for connected rooms (rooms sharing doorways).
//    RoomManager::ChangeLightingGroup() @ 0x8039E068 handles group merging.
//
// 3. LIGHT GRID (ELightGrid):
//    The ELightGrid (24,664 bytes, embedded at ERLevel+0x18) subdivides
//    the world into a volumetric grid. Each grid cell stores:
//      - Ambient light color and intensity
//      - List of affecting point lights
//      - Portal light connections (lights bleeding through doorways)
//
//    Key ELightGrid methods:
//      AddRoomToVertex(int, int, int) — marks which rooms affect a grid vertex
//      EvaluatePointLights() — computes point light contributions per cell
//      EvaluatePortalLights() — propagates light through room boundaries
//      GetLightsAtLocation(EVec3&, int) — queries lights at a world position
//      IsRoomAtLocation(EVec3&, int) — checks if a position is inside a room
//
// 4. OUTSIDE LIGHTING:
//    ERLevel::OutsideLightsInit(float, LevelLightingEntry&) @ 0x80237784
//    ERLevel::OutsideLightsUpdate(float, LevelLightingEntry&) @ 0x802377AC
//
//    Outside lighting is driven by the day/night cycle:
//    - m_pSunLightTable (+0x6454): LevelLighting table for sun interpolation
//    - m_pRainInfoTable (+0x6458): weather-based lighting overrides
//    - m_sunYawOffset (+0x645C): sun direction offset
//    - s_levelLightingTuning (static): tuning parameters for light levels
//
//    The sun position is computed as:
//      sunAngle = timeOfDay * 2PI + sunYawOffset
//      sunDir = (sin(sunAngle), sunHeight, cos(sunAngle))
//    Then applied to directional light data at +0x604C..+0x606C.
//
//    OutsideLightsUpdate() interpolates between sun/moon based on time:
//    1. Update sun light table (via LevelLighting interpolation)
//    2. Apply rain blend factor from m_pRainInfoTable
//    3. Process lighting overrides from s_levelLightingTuning
//    4. Compute sun direction vector from yaw angle
//    5. Set directional light color = sun_color * rain_blend
//    6. Store results in the ERLevel's sun light data block
//    7. Copy sky color data to the level's ambient light entries
//
// 5. ROOM INTENSITY SCALING:
//    ERLevel::UpdateLightsIntensityScale(int roomIdx, EVec3 scale)
//    @ 0x80236E88, 132 bytes
//
//    Applies per-room intensity scaling to all lights:
//    - Reads the room's light array from m_roomLights
//    - Scales each light's color by the given EVec3 multiplier
//    - Used for time-of-day transitions and mood lighting effects
//
//    ERLevel::IsRoomAt(EVec3& pos, int roomIdx)
//    @ 0x80236F0C, 68 bytes
//
//    Quick spatial query: is position `pos` inside room `roomIdx`?
//    1. Validate roomIdx (>= 0 and < m_roomCount)
//    2. Delegate to ELightGrid::IsRoomAtLocation()
//    3. Returns bool
//
// ============================================================================
// WORLD CONSTRUCTION SUMMARY
// ============================================================================
//
// The 3D world is constructed in this order:
//
// 1. ERLevel::AllocAndLoadLevel() — allocate and deserialize the level
// 2. ERLevel::Init() — initialize room arrays, prepare all instances
// 3. EHouse::BuildHouse() — triggers:
//      a. RoomManager::ComputeRooms() — detect rooms from tile grid + walls
//      b. ERoom::InitRoomLookupTab() — build wall lookup hash
//      c. ERoom::ProcStandardWalls() — create ERoomWall segments for N/S/E/W
//      d. ERoom::ProcDiagonalWalls() — create ERoomWall segments for diagonals
//      e. EIFloor::CreateFloors() — generate floor tile instances per room
//      f. ERLevel::SetRoomCount() — allocate per-room rendering arrays
//      g. EHouse::InitRoomLighting() — initialize per-room light groups
// 4. ERLevel::Update() per frame — update light grid, floor lighting
// 5. ERLevel::Draw() per frame — visibility test, sort, render everything
//
// The tile grid is the fundamental data structure. Each tile:
//   - Knows its walls (via TileWalls in cFixedWorldImpl)
//   - Belongs to exactly one room (assigned by RoomManager)
//   - May have a floor instance (created by EIFloor::CreateFloors)
//   - May have wall instances (created by ERoom::ProcStandardWalls)
//   - Is lit by the nearest light grid cell (queried via ELightGrid)

#endif // SKIP
