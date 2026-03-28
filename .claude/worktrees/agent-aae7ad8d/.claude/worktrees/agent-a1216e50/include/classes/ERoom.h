#ifndef EROOM_H
#define EROOM_H

#include "types.h"

// ERoom - struct layout extracted from assembly analysis
// Estimated minimum size: 0xB4 (180 bytes)
// 26 known fields (3 named), 50 methods

class ERoom {
public:
    // Constructors / Destructors
    ERoom(void)  // 0x80075060
    ~ERoom(void);  // 0x800751A8

    // Methods
    bool IsRoomWallsOpaque(int, int);  // 0x80075BFC (172B)
    bool IsRoomRoofOpaque(int, int);  // 0x800760A8 (172B)
    void Init(void);  // 0x80076E94 (812B)
    void SetWallState(EWallUpDownStateType);  // 0x80076A34 (220B)
    void UpdateWallFade(int);  // 0x80076D24 (368B)
    void InitRoomLookupTab(void);  // 0x80075334 (784B)
    /* ? */ GetNumWalls(unsigned short);  // 0x8007580C (256B)
    /* ? */ GetWallPaperCost(unsigned int, unsigned short);  // 0x8007590C (432B)
    void DrawWallpaperPreview(ERC *, unsigned short, EVec2 &);  // 0x80075ABC (320B)
    void CalAllRoomOpaque(int);  // 0x80075CA8 (604B)
    /* ? */ GetShortDistToCam(int, int);  // 0x80075F04 (208B)
    /* ? */ GetOccludeAlpha(int, int);  // 0x80075FD4 (212B)
    void CalRoofOpaque(int);  // 0x80076154 (1216B)
    void CalShortDistToCam(int);  // 0x80076614 (896B)
    void ProcStandardWalls(bool, int &, int &, bool);  // 0x800771C0 (1120B)
    void ProcDiagonalWalls(int &, int &, bool);  // 0x80077620 (1368B)
    void ProcessCell(TNodeList<ERoomWall *> &, ERoomWallPtr &, CTilePt &, TileWallsSegment, DiagonalSideSelector, TileWalls &, int, int &, int &, bool);  // 0x80077B78 (1096B)
    void PreviewWallBuild(bool);  // 0x80077FC0 (1240B)
    void KillArchitecturalObject(CTilePt &, TileWallsSegment, int &, bool);  // 0x80079420 (1028B)
    void FindWallContainingSegment(TNodeList<ERoomWall *> &, TileWallsSegment, CTilePt &, CTilePt &);  // 0x80078CA0 (184B)
    /* ? */ GetWallFromTileAndSegment(TileWallsSegment, CTilePt &);  // 0x80078E5C (420B)
    void DeleteERoomWallContainingSegment(TileWallsSegment, CTilePt &, CTilePt &);  // 0x80079000 (512B)
    void DeleteWallAtTile(CTilePt &, TileWalls &, TileWallsSegment);  // 0x80079200 (544B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (DrawWallpaperPreview, ERoom, GetNumWalls, ...)
    u32 m_field_004;  // 0x004 [W] (ERoom, InitRoomLookupTab)
    u32 m_wallFromTileAndSegment;  // 0x008 [R/W] (GetWallFromTileAndSegment, InitRoomLookupTab)
    u8 _pad_00C[4];  // 0x00C
    u16 m_field_010;  // 0x010 [R/W] (ERoom, InitRoomLookupTab, PreviewWallBuild)
    u8 _pad_012[2];  // 0x012
    u32 m_field_014;  // 0x014 [R] (PreviewWallBuild)
    u8 _pad_018[4];  // 0x018
    u32 m_wallPaperCost_01C;  // 0x01C [R/W] (DrawWallpaperPreview, ERoom, GetNumWalls, ...)
    u8 _pad_020[8];  // 0x020
    u32 m_field_028;  // 0x028 [W] (ERoom)
    u8 _pad_02C[8];  // 0x02C
    u32 m_field_034;  // 0x034 [R/W] (ERoom, PreviewWallBuild)
    u8 _pad_038[4];  // 0x038
    u32 m_field_03C;  // 0x03C [R] (CalAllRoomOpaque)
    u32 m_field_040;  // 0x040 [W] (ERoom)
    u8 _pad_044[8];  // 0x044
    u32 m_field_04C;  // 0x04C [W] (ERoom)
    u8 _pad_050[8];  // 0x050
    u32 m_field_058;  // 0x058 [W] (ERoom)
    u8 _pad_05C[8];  // 0x05C
    u32 m_field_064;  // 0x064 [W] (ERoom)
    u8 _pad_068[8];  // 0x068
    u32 m_field_070;  // 0x070 [W] (ERoom)
    u32 m_field_074;  // 0x074 [W] (ERoom)
    u32 m_field_078;  // 0x078 [W] (ERoom)
    u32 m_field_07C;  // 0x07C [W] (ERoom)
    u32 m_field_080;  // 0x080 [W] (ERoom)
    u32 m_field_084;  // 0x084 [W] (ERoom)
    u32 m_field_088;  // 0x088 [W] (ERoom)
    u32 m_field_08C;  // 0x08C [W] (ERoom)
    u32 m_field_090;  // 0x090 [W] (ERoom)
    u32 m_field_094;  // 0x094 [R] (CalAllRoomOpaque, CalRoofOpaque, CalShortDistToCam, ...)
    u8 _pad_098[8];  // 0x098
    u32 m_field_0A0;  // 0x0A0 [R] (CalAllRoomOpaque, CalRoofOpaque, CalShortDistToCam, ...)
    u8 _pad_0A4[8];  // 0x0A4
    f32 m_field_0AC;  // 0x0AC [R/W] (CalShortDistToCam, ERoom)
    f32 m_field_0B0;  // 0x0B0 [R/W] (CalShortDistToCam, ERoom)
};

#endif // EROOM_H
