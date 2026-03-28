#ifndef EROOMWALL_H
#define EROOMWALL_H

#include "types.h"

// ERoomWall - struct layout extracted from assembly analysis
// Estimated minimum size: 0x114 (276 bytes)
// 22 known fields (15 named), 44 methods

class ERoomWall {
public:
    // Constructors / Destructors
    ERoomWall(void)  // 0x8007F794
    ERoomWall(TileWallsSegment, DiagonalSideSelector, CTilePt &, bool)  // 0x80072CDC
    ~ERoomWall(void);  // 0x80073328

    // Methods
    /* ? */ GetWallMeterValue(int &);  // 0x8006D81C (620B)
    bool IsWallsOpaque(int);  // 0x8006DAE0 (64B)
    void CalWallsOpaque(int);  // 0x8006DB20 (332B)
    void CalShortDistToCam(int);  // 0x8006DC6C (504B)
    /* ? */ GetWallDims(TileWallsSegment, DiagonalSideSelector, EVec3 &, EVec3 &);  // 0x8007344C (1960B)
    void SetWallUpDownMode(EWallUpDownStateType, bool);  // 0x80073BF4 (152B)
    void AddTile(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector, bool);  // 0x80073C8C (392B)
    void DrawWall(ERC *);  // 0x80073E14 (1888B)
    void getRoomIdFromPoint(CTilePt &);  // 0x80074574 (884B)
    void getWallNormalOnSideOfCursor(EVec3 &, EVec3 &, EVec2 &, EVec2 &);  // 0x800748E8 (148B)
    void DrawWallpaperPreview(ERC *, EVec2 &);  // 0x8007497C (1764B)
    /* ? */ GetWallPaperCost(int, unsigned short);  // 0x80075644 (456B)
    void CountWalls(void);  // 0x80078498 (164B)
    bool HasSegment(TileWallsSegment, CTilePt &, CTilePt &);  // 0x8007853C (704B)
    void DeleteWallAtTile(CTilePt &);  // 0x800787FC (792B)
    void RemoveWallsFromWorld(void);  // 0x80078B14 (396B)
    /* ? */ GetWallAtTile(CTilePt &);  // 0x80078D58 (260B)
    void SafeDelete(void);  // 0x8007F830 (108B)
    /* ? */ GetShortDistToCam(int);  // 0x8007F89C (60B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_wallPaperCost;  // 0x000 [R/W] (CalWallsOpaque, DrawWall, DrawWallpaperPreview, ...)
    f32 m_field_004;  // 0x004 [R/W] (DrawWall, DrawWallpaperPreview, getWallNormalOnSideOfCursor)
    f32 m_wallPaperCost_008;  // 0x008 [R/W] (DrawWall, DrawWallpaperPreview, GetWallPaperCost, ...)
    f32 m_wallpaperPreview;  // 0x00C [W] (DrawWall, DrawWallpaperPreview)
    u16 m_wallMeterValue;  // 0x010 [R/W] (DrawWall, DrawWallpaperPreview, GetWallMeterValue)
    u8 _pad_012[2];  // 0x012
    u32 m_wallPaperCost_014;  // 0x014 [R/W] (CalShortDistToCam, CalWallsOpaque, DrawWall, ...)
    u32 m_wallpaperPreview_018;  // 0x018 [W] (DrawWall, DrawWallpaperPreview)
    u32 m_wallpaperPreview_01C;  // 0x01C [W] (DrawWall, DrawWallpaperPreview)
    f32 m_bHasSegment;  // 0x020 [R/W] (DeleteWallAtTile, DrawWall, DrawWallpaperPreview, ...)
    u32 m_field_024;  // 0x024 [R/W] (DrawWall, DrawWallpaperPreview, ERoomWall)
    u16 m_field_028;  // 0x028 [W] (ERoomWall)
    u8 _pad_02A[2];  // 0x02A
    u32 m_field_02C;  // 0x02C [W] (ERoomWall)
    u32 m_field_030;  // 0x030 [W] (DrawWall, DrawWallpaperPreview, ERoomWall)
    f32 m_wallMeterValue_034;  // 0x034 [R/W] (DrawWall, DrawWallpaperPreview, ERoomWall, ...)
    f32 m_field_038;  // 0x038 [W] (DrawWall, DrawWallpaperPreview, ERoomWall)
    u32 m_field_03C;  // 0x03C [W] (DrawWall, DrawWallpaperPreview, ERoomWall, ...)
    u8 _pad_040[0x10];  // 0x040
    f32 m_wallpaperPreview_050;  // 0x050 [W] (DrawWall, DrawWallpaperPreview)
    u8 _pad_054[0x1C];  // 0x054
    f32 m_wallpaperPreview_070;  // 0x070 [W] (DrawWall, DrawWallpaperPreview)
    u8 _pad_074[0x2C];  // 0x074
    f32 m_wallpaperPreview_0A0;  // 0x0A0 [W] (DrawWall, DrawWallpaperPreview)
    u8 _pad_0A4[0x1C];  // 0x0A4
    f32 m_wallpaperPreview_0C0;  // 0x0C0 [W] (DrawWall, DrawWallpaperPreview)
    u8 _pad_0C4[0x2C];  // 0x0C4
    f32 m_wallpaperPreview_0F0;  // 0x0F0 [R/W] (DrawWall, DrawWallpaperPreview)
    u8 _pad_0F4[0x1C];  // 0x0F4
    f32 m_wallpaperPreview_110;  // 0x110 [W] (DrawWall, DrawWallpaperPreview)
};

#endif // EROOMWALL_H
