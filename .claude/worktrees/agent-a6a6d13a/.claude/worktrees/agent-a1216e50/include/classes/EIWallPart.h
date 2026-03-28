#ifndef EIWALLPART_H
#define EIWALLPART_H

#include "types.h"

// EIWallPart - struct layout extracted from assembly analysis
// Estimated minimum size: 0xDBC (3516 bytes)
// 59 known fields (40 named), 80 methods

class EIWallPart {
public:
    // Static members (from map file)
    // static ??? kMaxWallShaders;

    // Constructors / Destructors
    EIWallPart(void)  // 0x8006E9E0
    EIWallPart(TileWalls &, TileWallsSegment, DiagonalSideSelector, CTilePt &)  // 0x8006ED50
    ~EIWallPart(void);  // 0x80071678

    // Methods
    void DrawOutsideShadows(TNodeList<EInstance *> &, EVec3 &, ELevelDrawData &);  // 0x80070B90 (972B)
    /* ? */ GetWallType(unsigned char);  // 0x8006A238 (368B)
    bool IsOpaque(void);  // 0x8006A3A8 (168B)
    /* ? */ GetVisible(int);  // 0x80072870 (116B)
    void SetOrient(EMat4 &);  // 0x8006F208 (524B)
    /* ? */ GetPoints(CTilePt &, CTilePt &);  // 0x8007121C (1116B)
    /* ? */ GetShadowModel(void);  // 0x8006E8F4 (236B)
    void OptimizeOrderTable(void);  // 0x8006EB98 (440B)
    /* ? */ GetWallModelId(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector, float &);  // 0x80071748 (3580B)
    void ChangeWallpaper(unsigned int);  // 0x80072544 (392B)
    void VisibilityTest(E3DWindow &);  // 0x8006F414 (232B)
    void SetVisible(bool);  // 0x800727C0 (176B)
    void Draw(ELevelDrawData &);  // 0x8006F53C (1984B)
    void WallOrderTableCallback(ELevelDrawData &, EOrderTableData *);  // 0x800706C4 (896B)
    void DrawShadow(ELevelDrawData &);  // 0x80070A44 (332B)
    /* ? */ GetAdjacentRoom(void);  // 0x80070F5C (48B)
    /* ? */ GetPoint(CTilePt &);  // 0x80070F8C (656B)
    bool IsDiagonal(void);  // 0x8007F178 (64B)
    /* ? */ GetWallpaperShader(void);  // 0x800726CC (244B)
    void SetWallState(EWallUpDownStateType, bool);  // 0x800728E4 (452B)
    void DoFadeCollisonWallList(TrapezoidFade &, EVec3 &, TNodeList<EIWallPart *> &);  // 0x80076B10 (380B)
    void DoFadeCollisonForList(TrapezoidFade &, TNodeList<ERoomWall *> &);  // 0x80076C8C (152B)
    void RealizeShaderTuning(void);  // 0x8007F21C (32B)
    void SafeDelete(void);  // 0x8007EF00 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8007EF6C (44B)
    /* ? */ GetTypeName(void);  // 0x8007EF98 (52B)
    /* ? */ GetTypeKey(void);  // 0x8007EFCC (52B)
    /* ? */ GetTypeVersion(void);  // 0x8007F000 (56B)
    void RegisterType(unsigned short);  // 0x8007F094 (116B)
    void New(void);  // 0x8007EE2C (76B)
    void Construct(EIWallPart *);  // 0x8007EE78 (76B)
    void Destruct(EIWallPart *);  // 0x8007EEC4 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8007F038 (40B)
    /* ? */ GetReadVersion(void);  // 0x8007F060 (52B)
    void CreateCopy(void);  // 0x8007F108 (68B)
    void isDiagonal(TileWallsSegment);  // 0x8007F1B8 (60B)
    void SetForceFadeOff(bool);  // 0x8007F1F4 (40B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_wallModelId;  // 0x000 [R/W] (DrawOutsideShadows, DrawShadow, EIWallPart, ...)
    f32 m_wallModelId_004;  // 0x004 [R/W] (Draw, DrawOutsideShadows, GetWallModelId, ...)
    f32 m_wallpaperShader;  // 0x008 [R/W] (Draw, DrawOutsideShadows, GetWallpaperShader, ...)
    f32 m_field_00C;  // 0x00C [R/W] (Draw, WallOrderTableCallback)
    u32 m_field_010;  // 0x010 [W] (EIWallPart)
    u32 m_wallModelId_014;  // 0x014 [R/W] (Draw, GetWallModelId)
    u32 m_field_018;  // 0x018 [R] (Draw)
    u32 m_shadowModel;  // 0x01C [R/W] (Draw, EIWallPart, GetShadowModel)
    u8 _pad_020[8];  // 0x020
    u32 m_shadowModel_028;  // 0x028 [R/W] (Draw, EIWallPart, GetShadowModel)
    u8 _pad_02C[0x10];  // 0x02C
    f32 m_wallpaperShader_03C;  // 0x03C [R] (DrawOutsideShadows, GetWallpaperShader)
    u32 m_wallpaperShader_040;  // 0x040 [R] (GetWallpaperShader)
    u8 _pad_044[0x18];  // 0x044
    u32 m_visible;  // 0x05C [R/W] (SetVisible)
    u8 _pad_060[8];  // 0x060
    u32 m_field_068;  // 0x068 [W] (EIWallPart)
    u8 _pad_06C[4];  // 0x06C
    u32 m_field_070;  // 0x070 [R] (Draw, DrawOutsideShadows, DrawShadow, ...)
    u8 _pad_074[0x24];  // 0x074
    u32 m_field_098;  // 0x098 [R] (WallOrderTableCallback)
    u8 _pad_09C[6];  // 0x09C
    s16 m_wallModelId_0A2;  // 0x0A2 [R] (GetWallModelId)
    u8 _pad_0A4[4];  // 0x0A4
    u32 m_field_0A8;  // 0x0A8 [R/W] (WallOrderTableCallback)
    u8 _pad_0AC[0xC];  // 0x0AC
    u32 m_field_0B8;  // 0x0B8 [R/W] (WallOrderTableCallback)
    u8 _pad_0BC[0x34];  // 0x0BC
    u32 m_field_0F0;  // 0x0F0 [R] (DrawOutsideShadows, DrawShadow, WallOrderTableCallback)
    u8 _pad_0F4[0x1C];  // 0x0F4
    u32 m_shadowModel_110;  // 0x110 [R] (GetShadowModel)
    u8 _pad_114[4];  // 0x114
    u32 m_field_118;  // 0x118 [R] (Draw, DrawOutsideShadows, DrawShadow)
    u32 m_outsideShadows;  // 0x11C [R] (DrawOutsideShadows)
    u32 m_wallpaperShader_120;  // 0x120 [R] (Draw, DrawShadow, GetWallpaperShader, ...)
    u8 _pad_124[4];  // 0x124
    u32 m_field_128;  // 0x128 [W] (Draw)
    u8 _pad_12C[0xC];  // 0x12C
    u32 m_field_138;  // 0x138 [W] (Draw)
    u8 _pad_13C[0xDC];  // 0x13C
    u32 m_field_218;  // 0x218 [W] (Draw)
    u8 _pad_21C[0x64];  // 0x21C
    f32 m_field_280;  // 0x280 [R] (VisibilityTest)
    f32 m_field_284;  // 0x284 [R] (VisibilityTest)
    u8 _pad_288[0x98];  // 0x288
    u32 m_points;  // 0x320 [R/W] (EIWallPart, GetPoint, GetPoints)
    u32 m_points_324;  // 0x324 [R/W] (EIWallPart, GetPoint, GetPoints)
    u8 _pad_328[4];  // 0x328
    u32 m_field_32C;  // 0x32C [W] (EIWallPart)
    u32 m_field_330;  // 0x330 [W] (EIWallPart)
    u8 _pad_334[0x15];  // 0x334
    u8 m_shadow;  // 0x349 [R] (Draw, DrawShadow)
    u8 _pad_34A[6];  // 0x34A
    u32 m_field_350;  // 0x350 [W] (EIWallPart)
    u32 m_wallModelId_354;  // 0x354 [R/W] (EIWallPart, GetWallModelId)
    s16 m_shadowModel_358;  // 0x358 [R/W] (DrawOutsideShadows, DrawShadow, EIWallPart, ...)
    s16 m_shadowModel_35A;  // 0x35A [R/W] (DrawOutsideShadows, DrawShadow, EIWallPart, ...)
    f32 m_orient;  // 0x35C [R/W] (EIWallPart, SetOrient)
    f32 m_orient_360;  // 0x360 [R/W] (EIWallPart, SetOrient)
    f32 m_orient_364;  // 0x364 [R/W] (EIWallPart, SetOrient)
    f32 m_orient_368;  // 0x368 [R/W] (EIWallPart, SetOrient)
    f32 m_orient_36C;  // 0x36C [R/W] (EIWallPart, SetOrient)
    f32 m_orient_370;  // 0x370 [R/W] (EIWallPart, SetOrient)
    f32 m_orient_374;  // 0x374 [R/W] (EIWallPart, SetOrient)
    f32 m_orient_378;  // 0x378 [R/W] (EIWallPart, SetOrient)
    f32 m_orient_37C;  // 0x37C [R/W] (DrawOutsideShadows, DrawShadow, SetOrient, ...)
    f32 m_orient_380;  // 0x380 [R/W] (DrawOutsideShadows, DrawShadow, SetOrient, ...)
    f32 m_orient_384;  // 0x384 [R/W] (SetOrient, VisibilityTest)
    f32 m_orient_388;  // 0x388 [W] (SetOrient)
    f32 m_orient_38C;  // 0x38C [W] (SetOrient)
    f32 m_orient_390;  // 0x390 [W] (SetOrient)
    f32 m_orient_394;  // 0x394 [W] (SetOrient)
    f32 m_orient_398;  // 0x398 [W] (SetOrient)
    f32 m_orient_39C;  // 0x39C [W] (SetOrient)
    u32 m_wallpaperShader_3A0;  // 0x3A0 [R/W] (ChangeWallpaper, EIWallPart, GetWallpaperShader, ...)
    u8 _pad_3A4[8];  // 0x3A4
    u32 m_shadowModel_3AC;  // 0x3AC [R/W] (DrawOutsideShadows, DrawShadow, EIWallPart, ...)
    u8 _pad_3B0[0x9F8];  // 0x3B0
    f32 m_field_DA8;  // 0xDA8 [R] (WallOrderTableCallback)
    u8 _pad_DAC[8];  // 0xDAC
    f32 m_outsideShadows_DB4;  // 0xDB4 [R] (DrawOutsideShadows)
    f32 m_outsideShadows_DB8;  // 0xDB8 [R] (DrawOutsideShadows)
};

#endif // EIWALLPART_H
