#ifndef WORLD_H
#define WORLD_H

#include "types.h"

// Forward declarations
struct CTilePt;
struct FTilePt;
struct FloorPattern;
struct TileWalls;
struct TileWallsSegment;
struct TileWallStorage;
class iResFile;

// ============================================================================
// WallStyle - Wall style enum
// ============================================================================
typedef int WallStyle;

// ============================================================================
// FloorLayer - Opaque floor layer type
// ============================================================================
class FloorLayer;

// ============================================================================
// WallLayer - Opaque wall layer type
// ============================================================================
class WallLayer;

// ============================================================================
// InfluenceMap - Influence map for AI
// ============================================================================
class InfluenceMap;

// ============================================================================
// cFixedWorld - Abstract base class for world/lot representation
// Size: 0x04 (vtable pointer only for base)
// vtable at 0x804654C8
// ============================================================================
class cFixedWorld {
public:
    virtual ~cFixedWorld(void);

    // Pure virtual interface - see cFixedWorldImpl for implementations
    virtual void SetSize(int x, int y, bool flag) = 0;
    virtual void DeleteArrays(void) = 0;
    virtual void Save(iResFile* file, int param) = 0;
    virtual void Load(iResFile* file, int param) = 0;
    virtual FloorLayer* GetFloorLayer(void) = 0;
    virtual WallLayer* GetWalls(void) = 0;
    virtual void GetWall(CTilePt& tile) = 0;
    virtual void SetWall(CTilePt& tile, TileWalls walls) = 0;
    virtual void ComputeRooms(int param) = 0;
    virtual void ComputeArchValue(bool* result) = 0;
    virtual void DoCommand(short cmd, int param) = 0;
    virtual void OffsetWorld(CTilePt& offset) = 0;
    virtual void OutOfRoutableExtent(CTilePt& tile) const = 0;
    virtual void OutOfRoutableExtent(FTilePt& tile) const = 0;
    virtual void OutOfBounds(CTilePt& tile) const = 0;
    virtual void OutOfBuildingBounds(CTilePt& tile, bool flag) const = 0;
    virtual void OutOfGrid(CTilePt& tile) const = 0;
    virtual void OutOfBounds(FTilePt& tile) const = 0;
    virtual void OutOfGrid(FTilePt& tile) const = 0;
    virtual int GetXSize(void) const = 0;
    virtual int GetYSize(void) const = 0;
    virtual int GetMaxSize(void) const = 0;
    virtual void GetFloor(CTilePt& tile) = 0;
    virtual void IsGrassAt(CTilePt& tile) = 0;
    virtual void SetFloor(CTilePt& tile, FloorPattern pattern) = 0;
    virtual void GetRoom(CTilePt& tile) = 0;
    virtual void SetRoom(CTilePt& tile, unsigned short room) = 0;
    virtual void GetFlags(CTilePt& tile) = 0;
    virtual void SetFlags(CTilePt& tile, unsigned char flags) = 0;
    virtual void IsOutside(CTilePt& tile) = 0;
    virtual void HasWalls(CTilePt& tile, TileWallsSegment seg) = 0;
    virtual void HasWalls(CTilePt& tile) = 0;
    virtual void GetWallStorage(CTilePt& tile) = 0;
    virtual void SetWallStorage(CTilePt& tile, TileWallStorage& storage) = 0;
    virtual void MayEditTile(CTilePt& tile) const = 0;
    virtual void GetRoomIdFromPoint(CTilePt& tile) = 0;
    virtual InfluenceMap* GetInfluenceMap(void) = 0;
    virtual InfluenceMap* GetPassiveInfluenceMap(void) = 0;
};

// ============================================================================
// cFixedWorldImpl - Concrete world implementation
// Size: 0x44 (68 bytes) based on CreateTheWorld allocating 0x44 bytes
//
// Member layout:
//   +0x00: vtable (cFixedWorldImpl virtual table at 0x80465388)
//   +0x04: vtable2 (Commander virtual table at 0x80465368)
//   +0x08-0x13: unknown
//   +0x14: int m_xSize
//   +0x18: int m_ySize
//   +0x1C-0x2B: unknown
//   +0x2C: FloorLayer* m_floorLayer
//   +0x30-0x37: unknown
//   +0x38: WallLayer* m_walls
//   +0x3C: InfluenceMap* m_influenceMap
//   +0x40: InfluenceMap* m_passiveInfluenceMap
// ============================================================================
class cFixedWorldImpl : public cFixedWorld {
public:
    cFixedWorldImpl(int xSize, int ySize);
    virtual ~cFixedWorldImpl(void);

    // Overrides
    virtual void SetSize(int x, int y, bool flag);
    virtual void DeleteArrays(void);
    virtual void Save(iResFile* file, int param);
    virtual void Load(iResFile* file, int param);
    virtual FloorLayer* GetFloorLayer(void);
    virtual WallLayer* GetWalls(void);
    virtual void GetWall(CTilePt& tile);
    virtual void SetWall(CTilePt& tile, TileWalls walls);
    virtual void ComputeRooms(int param);
    virtual void ComputeArchValue(bool* result);
    virtual void DoCommand(short cmd, int param);
    virtual void OffsetWorld(CTilePt& offset);
    virtual void OutOfRoutableExtent(CTilePt& tile) const;
    virtual void OutOfRoutableExtent(FTilePt& tile) const;
    virtual void OutOfBounds(CTilePt& tile) const;
    virtual void OutOfBuildingBounds(CTilePt& tile, bool flag) const;
    virtual void OutOfGrid(CTilePt& tile) const;
    virtual void OutOfBounds(FTilePt& tile) const;
    virtual void OutOfGrid(FTilePt& tile) const;
    virtual int GetXSize(void) const;
    virtual int GetYSize(void) const;
    virtual int GetMaxSize(void) const;
    virtual void GetFloor(CTilePt& tile);
    virtual void IsGrassAt(CTilePt& tile);
    virtual void SetFloor(CTilePt& tile, FloorPattern pattern);
    virtual void GetRoom(CTilePt& tile);
    virtual void SetRoom(CTilePt& tile, unsigned short room);
    virtual void GetFlags(CTilePt& tile);
    virtual void SetFlags(CTilePt& tile, unsigned char flags);
    virtual void IsOutside(CTilePt& tile);
    virtual void HasWalls(CTilePt& tile, TileWallsSegment seg);
    virtual void HasWalls(CTilePt& tile);
    virtual void GetWallStorage(CTilePt& tile);
    virtual void SetWallStorage(CTilePt& tile, TileWallStorage& storage);
    virtual void MayEditTile(CTilePt& tile) const;
    virtual void GetRoomIdFromPoint(CTilePt& tile);
    virtual InfluenceMap* GetInfluenceMap(void);
    virtual InfluenceMap* GetPassiveInfluenceMap(void);

    // Data members
    char _pad04[0x10];                 // +0x04
    int m_xSize;                       // +0x14
    int m_ySize;                       // +0x18
    char _pad1C[0x10];                 // +0x1C
    FloorLayer* m_floorLayer;          // +0x2C
    char _pad30[0x08];                 // +0x30
    WallLayer* m_walls;                // +0x38
    InfluenceMap* m_influenceMap;      // +0x3C
    InfluenceMap* m_passiveInfluenceMap; // +0x40
};

// ============================================================================
// Global world functions
// ============================================================================
void CreateTheWorld(void);
void DestroyTheWorld(void);
void ValidateTheWorld(void);
void SetLotBorders(int x1, int y1, int x2, int y2);
int GetWallPrice(WallStyle style);

// ============================================================================
// Globs - Global game state pointers
// ============================================================================
namespace Globs {
    extern cFixedWorld* pFixedWorld;
}

#endif // WORLD_H
