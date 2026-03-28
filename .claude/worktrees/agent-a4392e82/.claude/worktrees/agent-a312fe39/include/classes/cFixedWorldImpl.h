#ifndef CFIXEDWORLDIMPL_H
#define CFIXEDWORLDIMPL_H

#include "types.h"

// cFixedWorldImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x62 (98 bytes)
// 21 known fields (12 named), 80 methods

class cFixedWorldImpl {
public:
    // Constructors / Destructors
    cFixedWorldImpl(int, int)  // 0x803DC9B4
    ~cFixedWorldImpl(void);  // 0x803DCAF4

    // Methods
    void SetSize(int, int, bool);  // 0x803DCB64 (1656B)
    void DeleteArrays(void);  // 0x803DD1DC (264B)
    void Save(iResFile *, int);  // 0x803DD2E4 (512B)
    void Load(iResFile *, int);  // 0x803DD4E4 (1008B)
    /* ? */ GetFloorLayer(void);  // 0x803DD8D4 (156B)
    /* ? */ GetWalls(void);  // 0x803DD970 (156B)
    /* ? */ GetWall(CTilePt &);  // 0x803DDA0C (1752B)
    void SetWall(CTilePt &, TileWalls);  // 0x803DE0E4 (4044B)
    void ComputeRooms(int);  // 0x803DF0B0 (10128B)
    void ComputeArchValue(bool *);  // 0x803E1840 (2060B)
    void DoCommand(short, int);  // 0x803E204C (252B)
    void OffsetWorld(CTilePt &);  // 0x803E2148 (1064B)
    void OutOfRoutableExtent(CTilePt &);  // 0x803E2884 (152B)
    void OutOfRoutableExtent(FTilePt &);  // 0x803E291C (156B)
    void OutOfBounds(CTilePt &);  // 0x803E29B8 (156B)
    void OutOfBuildingBounds(CTilePt &, bool);  // 0x803E2A54 (256B)
    void OutOfGrid(CTilePt &);  // 0x803E2B54 (148B)
    void OutOfBounds(FTilePt &);  // 0x803E2BE8 (156B)
    void OutOfGrid(FTilePt &);  // 0x803E2C84 (156B)
    /* ? */ GetXSize(void);  // 0x803E2D20 (44B)
    /* ? */ GetYSize(void);  // 0x803E2D4C (44B)
    /* ? */ GetMaxSize(void);  // 0x803E2D78 (40B)
    /* ? */ GetFloor(CTilePt &);  // 0x803E2DA0 (84B)
    bool IsGrassAt(CTilePt &);  // 0x803E2DF4 (252B)
    void SetFloor(CTilePt &, FloorPattern);  // 0x803E2EF0 (152B)
    /* ? */ GetRoom(CTilePt &);  // 0x803E2F88 (220B)
    void SetRoom(CTilePt &, unsigned short);  // 0x803E3064 (92B)
    /* ? */ GetFlags(CTilePt &);  // 0x803E30C0 (84B)
    void SetFlags(CTilePt &, unsigned char);  // 0x803E3114 (92B)
    bool IsOutside(CTilePt &);  // 0x803E3170 (96B)
    bool HasWalls(CTilePt &, TileWallsSegment);  // 0x803E31D0 (112B)
    bool HasWalls(CTilePt &);  // 0x803E3240 (100B)
    /* ? */ GetWallStorage(CTilePt &);  // 0x803E32A4 (76B)
    void SetWallStorage(CTilePt &, TileWallStorage &);  // 0x803E32F0 (96B)
    void MayEditTile(CTilePt &);  // 0x803E3350 (132B)
    /* ? */ GetRoomIdFromPoint(CTilePt &);  // 0x803E33D4 (868B)
    /* ? */ GetInfluenceMap(void);  // 0x803E4B34 (44B)
    /* ? */ GetPassiveInfluenceMap(void);  // 0x803E4B60 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ComputeArchValue, ComputeRooms, DoCommand, ...)
    u16 m_field_002;  // 0x002 [R/W] (ComputeRooms)
    u32 m_wall;  // 0x004 [R/W] (ComputeRooms, GetWall, OutOfBounds, ...)
    u32 m_wall_008;  // 0x008 [R] (ComputeRooms, GetWall)
    u32 m_wall_00C;  // 0x00C [R/W] (ComputeRooms, GetWall, OffsetWorld, ...)
    u32 m_field_010;  // 0x010 [W] (cFixedWorldImpl, ~cFixedWorldImpl)
    u32 m_size;  // 0x014 [R/W] (ComputeArchValue, ComputeRooms, Load, ...)
    u32 m_size_018;  // 0x018 [R/W] (ComputeArchValue, ComputeRooms, Load, ...)
    u32 m_field_01C;  // 0x01C [R/W] (ComputeRooms, OutOfRoutableExtent)
    u32 m_field_020;  // 0x020 [R/W] (ComputeRooms, OutOfRoutableExtent)
    u32 m_field_024;  // 0x024 [R/W] (ComputeRooms, OutOfRoutableExtent)
    u32 m_field_028;  // 0x028 [R/W] (ComputeRooms, OutOfRoutableExtent)
    u32 m_floor;  // 0x02C [R/W] (DeleteArrays, GetFloor, Load, ...)
    u32 m_room;  // 0x030 [R/W] (ComputeRooms, DeleteArrays, GetRoom, ...)
    u32 m_flags;  // 0x034 [R/W] (ComputeRooms, DeleteArrays, GetFlags, ...)
    u32 m_wallStorage;  // 0x038 [R/W] (ComputeRooms, DeleteArrays, GetWallStorage, ...)
    u32 m_size_03C;  // 0x03C [R/W] (DeleteArrays, Load, SetSize, ...)
    u32 m_size_040;  // 0x040 [R/W] (DeleteArrays, Load, SetSize, ...)
    u8 _pad_044[4];  // 0x044
    s16 m_field_048;  // 0x048 [R] (OutOfRoutableExtent)
    u8 _pad_04A[0xE];  // 0x04A
    s16 m_field_058;  // 0x058 [R] (OutOfBounds)
    u8 _pad_05A[6];  // 0x05A
    s16 m_field_060;  // 0x060 [R] (OutOfGrid)
};

#endif // CFIXEDWORLDIMPL_H
