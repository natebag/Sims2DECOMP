#ifndef TILEWALLS_H
#define TILEWALLS_H

#include "types.h"

// TileWalls - struct layout extracted from assembly analysis
// Estimated minimum size: 0x38 (56 bytes)
// 11 known fields (7 named), 78 methods

class TileWalls {
public:
    // Constructors / Destructors
    TileWalls(void)  // 0x803C8AF0
    TileWalls(TileWalls &)  // 0x803C8B38
    TileWalls(TileWallStorage &)  // 0x803C6E74
    TileWalls(TileWallStorage &, bool, bool, bool, bool)  // 0x803C6FA8
    ~TileWalls(void);  // 0x803C8B84

    // Methods
    bool HasWall(TileWallsSegment);  // 0x803C8C98 (72B)
    /* ? */ GetStyle(TileWallsSegment);  // 0x803C9374 (352B)
    bool HasWall(void);  // 0x803C8CE0 (60B)
    void First(void);  // 0x803C9968 (264B)
    void Next(TileWallsSegment);  // 0x803C9A70 (404B)
    bool HasWallNotFence(TileWallsSegment);  // 0x803C8D1C (128B)
    void operator=(TileWalls &);  // 0x803C8BD4 (196B)
    /* ? */ GetPattern(TileWallsSegment, DiagonalSideSelector);  // 0x803C8FC0 (424B)
    bool HasDiagonal(void);  // 0x803C8E18 (64B)
    void SetStyle(WallStyle, TileWallsSegment);  // 0x803C94D4 (424B)
    /* ? */ GetAdjacentTile(TileWallsSegment, CTilePt *);  // 0x803C7ECC (608B)
    /* ? */ GetFloorValue(DiagonalSideSelector);  // 0x803C9C04 (316B)
    void RemoveWall(TileWallsSegment);  // 0x803C97F8 (328B)
    void RotateSegment(TileWallsSegment, int);  // 0x803C9F5C (232B)
    void Rotate(int);  // 0x803C796C (828B)
    void GenerateRotationLookups(void);  // 0x803C7134 (1276B)
    /* ? */ GetPlacement(TileWallsSegment);  // 0x803C7630 (404B)
    bool IsSingleWall(TileWallsSegment);  // 0x803C8A5C (148B)
    void SegmentToIndex(TileWallsSegment, DiagonalSideSelector);  // 0x803C8480 (1112B)
    void SetPlacement(TileWalls::SheerPlacement, TileWallsSegment);  // 0x803C77C4 (424B)
    void RemoveAllWalls(void);  // 0x803C9940 (40B)
    void AddWall(TileWallsSegment);  // 0x803C967C (380B)
    void RotateDiagonal(DiagonalSideSelector, int);  // 0x803CA044 (364B)
    void SetPattern(WallPattern, TileWallsSegment, DiagonalSideSelector);  // 0x803C9168 (524B)
    void SetFloorValue(FloorPattern, DiagonalSideSelector);  // 0x803C9D40 (340B)
    bool CanAdd(TileWallsSegment);  // 0x803C7CA8 (548B)
    /* ? */ GetOppositeSegment(TileWallsSegment);  // 0x803C812C (296B)
    void DirToWallSeg(TilePtDir);  // 0x803C8254 (260B)
    /* ? */ GetWallBetween(TilePtDir);  // 0x803C8358 (296B)
    void IndexToSegment(int, DiagonalSideSelector *);  // 0x803C88D8 (388B)
    bool HasFenceNotWall(TileWallsSegment);  // 0x803C8D9C (124B)
    bool HasDiagonalNotFence(void);  // 0x803C8E58 (180B)
    bool HasDiagonalFence(void);  // 0x803C8F0C (180B)
    void ConvertToWorldCoords(void);  // 0x803C9E94 (200B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddWall, CanAdd, First, ...)
    u32 m_placement;  // 0x004 [R/W] (GetPlacement, SetPlacement, operator=)
    u16 m_field_008;  // 0x008 [W] (AddWall, operator=)
    u8 _pad_00A[2];  // 0x00A
    u32 m_field_00C;  // 0x00C [W] (operator=)
    u32 m_field_010;  // 0x010 [W] (operator=)
    u16 m_field_014;  // 0x014 [W] (AddWall, operator=)
    u8 _pad_016[0xE];  // 0x016
    u32 m_bCanAdd_024;  // 0x024 [R] (CanAdd)
    u32 m_bCanAdd_028;  // 0x028 [R] (CanAdd)
    u32 m_bCanAdd_02C;  // 0x02C [R] (CanAdd)
    u32 m_bCanAdd_030;  // 0x030 [R] (CanAdd)
    u32 m_bCanAdd_034;  // 0x034 [R] (CanAdd)
};

#endif // TILEWALLS_H
