/* include/types/WallTypes.h — canonical wall-geometry primitives
 *
 * S18 TypeArchaeologist deliverable. Surgical subset extraction from
 * legacy include/core/house.h. Covers the wall geometry types only
 * (TileWalls + WallStyle/Pattern enums + segment + diagonal-side
 * selectors + free-function Walls API).
 *
 * The full include/core/house.h (508 lines — HouseStats, House,
 * HouseImpl, IconGroup, Careers, Family, NeighborhoodInfo, etc.) is
 * deferred to a follow-up promotion. This subset unblocks Lane 7
 * SonnetWorker2's InteractorModule::WallManipulator routing (404 virgin
 * stubs) which needs the wall-segment API without the rest of house
 * state-machine surface.
 *
 * ============================================================================
 * Type ownership note: the enums TilePtDir + DiagonalSideSelector were
 * previously local-defined in include/types/InteractorModule.h (S18
 * deliverable #4) as a workaround before this canonical header existed.
 * InteractorModule.h is amended in the same commit to consume the
 * canonical definitions here.
 * ============================================================================
 */
#ifndef SIMS2_TYPES_WALLTYPES_H
#define SIMS2_TYPES_WALLTYPES_H

#include "../types.h"

/* Forward decls */
struct FTilePt;
struct FTileRect;
struct CTilePt;
struct TileWallStorage;

/* ============================================================================
 * Wall + floor enumeration types
 * ========================================================================== */

/* WallStyle — concrete values not yet fully recovered. Known walkable
 * values (from CanWalkThrough(WallStyle)): 3, 5, 6, 15, 23. Leave as
 * opaque enum until per-method evidence pins more. */
enum WallStyle { WallStyle_OPAQUE = 0 };

/* WallPattern / FloorPattern — opaque 16-bit pattern IDs */
typedef u16 WallPattern;
typedef u16 FloorPattern;

/* TileWallsSegment — bitmask identifying wall segments on a tile */
typedef u32 TileWallsSegment;

/* DiagonalSideSelector — used for diagonal wall sides.
 * Values 1 and 2 map to TileWalls offset 0x08, >=3 maps to offset 0x14
 * (per legacy GetFloorValue dispatch). Concrete enum values TBD. */
enum DiagonalSideSelector { DiagonalSideSelector_OPAQUE = 0 };

/* TilePtDir — direction enum used by TilePt math + adjacent-tile lookup.
 * Concrete values not yet recovered. */
enum TilePtDir { TilePtDir_OPAQUE = 0 };

/* TileWallStorage — opaque storage backing handed to TileWalls ctor
 * for stateful initialization */
struct TileWallStorage {
    /* opaque */
};

/* ============================================================================
 * TileWalls — manages walls on a single tile
 *
 * Size: 0x38 (56 bytes) — zeroed on default construction.
 *
 * Verified offsets (legacy + cross-reference to legacy interactor walls
 * methods):
 *   0x00 u32 m_wallBits         — wall-segment bitmask
 *   0x08 u16 m_floorValue1      — floor for diagonal side 1/2
 *   0x14 u16 m_floorValue2      — floor for diagonal side 3+
 *   0x24 u32 m_rotation         — current rotation state
 * (other 0x04/0x0A-0x13/0x16-0x23/0x28-0x37 ranges hold per-segment style/
 *  pattern + sheer-placement data; not yet enumerated per-byte)
 * ========================================================================== */
class TileWalls {
public:
    /* 0x00 */ u32  m_wallBits;
    /* 0x04 */ u8   _pad04[0x04];
    /* 0x08 */ u16  m_floorValue1;
    /* 0x0A */ u8   _pad0A[0x0A];
    /* 0x14 */ u16  m_floorValue2;
    /* 0x16 */ u8   _pad16[0x0E];
    /* 0x24 */ u32  m_rotation;
    /* 0x28 */ u8   _pad28[0x10];
    /* total 0x38 */

    /* Ctors / dtor */
    TileWalls(void);
    TileWalls(TileWallStorage& storage);
    TileWalls(TileWallStorage& storage, bool, bool, bool, bool);
    TileWalls(TileWalls& other);
    ~TileWalls(void);

    TileWalls& operator=(TileWalls& other);

    /* Wall queries */
    bool HasWall(TileWallsSegment seg) const;
    bool HasWall(void) const;
    bool HasDiagonal(void) const;
    bool HasWallNotFence(TileWallsSegment seg) const;
    bool HasFenceNotWall(TileWallsSegment seg) const;
    bool HasDiagonalNotFence(void) const;
    bool HasDiagonalFence(void) const;

    /* Wall modification */
    void AddWall(TileWallsSegment seg);
    void RemoveWall(TileWallsSegment seg);
    void RemoveAllWalls(void);
    bool CanAdd(TileWallsSegment seg) const;

    /* Wall style + pattern */
    WallStyle   GetStyle(TileWallsSegment seg) const;
    void        SetStyle(WallStyle style, TileWallsSegment seg);
    WallPattern GetPattern(TileWallsSegment seg, DiagonalSideSelector side) const;
    void        SetPattern(WallPattern pattern, TileWallsSegment seg, DiagonalSideSelector side);

    /* Floor values */
    FloorPattern GetFloorValue(DiagonalSideSelector side) const;
    FloorPattern SetFloorValue(FloorPattern pattern, DiagonalSideSelector side);

    /* Placement */
    s32 GetPlacement(TileWallsSegment seg) const;

    struct SheerPlacement {};
    void SetPlacement(SheerPlacement placement, TileWallsSegment seg);

    /* Iteration */
    TileWallsSegment First(void) const;
    TileWallsSegment Next(TileWallsSegment seg) const;
    bool             IsSingleWall(TileWallsSegment seg);

    /* Rotation + conversion */
    void                       Rotate(s32 amount);
    static TileWallsSegment    RotateSegment(TileWallsSegment seg, s32 rotation);
    static DiagonalSideSelector RotateDiagonal(DiagonalSideSelector side, s32 rotation);
    void                       ConvertToWorldCoords(void);
    void                       GenerateRotationLookups(void);

    /* Segment utilities */
    static s32              SegmentToIndex(TileWallsSegment seg, DiagonalSideSelector* side);
    static TileWallsSegment IndexToSegment(s32 index, DiagonalSideSelector* side);
    static void             GetAdjacentTile(TileWallsSegment seg, CTilePt* pt);
    static TileWallsSegment GetOppositeSegment(TileWallsSegment seg);
    static TileWallsSegment DirToWallSeg(TilePtDir dir);
    static TileWallsSegment GetWallBetween(TilePtDir dir);
};

/* ============================================================================
 * Rotation lookup tables (live in .data per legacy)
 *   sRotateSegmentLUT  @ 0x8050BC30
 *   sRotateDiagonalLUT @ 0x8050C030
 * ========================================================================== */
extern u32 sRotateSegmentLUT[];
extern u32 sRotateDiagonalLUT[];

/* ============================================================================
 * Free Walls API (from walls.obj)
 * ========================================================================== */
bool CanWalkThrough(u8 wallBits);
bool CanWalkThrough(WallStyle style);
s32  TestDoorCondition(TileWalls& walls, TileWallsSegment seg);
void SectWall(FTileRect* rect, s32 level);
s32  ValidDoorLocation(s32 x, s32 y, s32 level, s32 dir, s32 type);
u8   RotateWallBits(u8 bits, s32 rotation);
void CheckWallFlags(FTilePt pt, s32 level, s32 x, s32 y);

#endif /* SIMS2_TYPES_WALLTYPES_H */
