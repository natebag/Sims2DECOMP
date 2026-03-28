#ifndef ISIMSOBJECTMODEL_H
#define ISIMSOBJECTMODEL_H

#include "types.h"

// ISimsObjectModel - struct layout extracted from assembly analysis
// Estimated minimum size: 0x323C (12860 bytes)
// 88 known fields (28 named), 162 methods

class ISimsObjectModel {
public:
    // Constructors / Destructors
    ISimsObjectModel(void)  // 0x800E3290
    ~ISimsObjectModel(void);  // 0x800E34FC

    // Methods
    void CleanupStuff(ERLevel *);  // 0x800E39C4 (700B)
    /* ? */ GetHeightOffset(void);  // 0x800E3630 (496B)
    void InsertSubModelsInHouse(ERLevel *);  // 0x800E3820 (236B)
    void PropigateFlagsToSubModels(void);  // 0x800E390C (184B)
    void Update(void);  // 0x800E3C80 (4072B)
    /* ? */ GetAnimDef(int, bool);  // 0x800E9168 (1956B)
    void UpdateModel(ObjAnimDef *);  // 0x800F766C (272B)
    void UpdateParticle(ObjAnimDef *);  // 0x800E4C68 (380B)
    void UpdateAnimTrack(ObjAnimDef *, bool);  // 0x800E6068 (316B)
    void UpdateShader(ObjAnimDef *);  // 0x800F777C (316B)
    void UpdateBulb(ObjAnimDef *);  // 0x800E588C (176B)
    void UpdateHighlightAnim(void);  // 0x800E5AE0 (592B)
    /* ? */ GetRot(void);  // 0x800F5B70 (44B)
    void CalcDynamicOrient(void);  // 0x800E6F34 (224B)
    void CalcOrient(void);  // 0x800E6DD0 (356B)
    void SetupCharacter(void);  // 0x800E4DE4 (1116B)
    void InitBulb(void);  // 0x800E5240 (1612B)
    void SetSOMModel(unsigned int);  // 0x800E593C (420B)
    void AnimStartImmediate(unsigned int);  // 0x800E5D30 (104B)
    void AnimStartBlendIn(unsigned int);  // 0x800E5D98 (104B)
    void KillAllAnimTracks(void);  // 0x800E5E00 (112B)
    void UpdateTracks(void);  // 0x800E5E70 (504B)
    void UpdateAnimController(void);  // 0x800E8560 (228B)
    void StartNewAnimTrack(ObjAnimDef *, bool);  // 0x800F7968 (812B)
    void ProcessPropertyEventTags(ObjAnimDef *, float);  // 0x800F7CD0 (696B)
    void UpdateAnim(ObjAnimDef *);  // 0x800E61A4 (76B)
    void RemoveSubModelsFromHouse(ERLevel *);  // 0x800E61F0 (436B)
    void ChageShader(unsigned int, unsigned int);  // 0x800E63A4 (188B)
    /* ? */ GetAdjacentRoom(bool);  // 0x800E66D0 (304B)
    void SetWallForPortal(void);  // 0x800E6800 (864B)
    void CreateShadow(void);  // 0x800E6B60 (576B)
    void SetPosStatic(EVec3 &, float);  // 0x800E6DA0 (48B)
    void SetOutOfWorld(void);  // 0x800E7014 (40B)
    void StartBurp(int);  // 0x800E703C (72B)
    void TryAnimateObject(short, short *);  // 0x800E7084 (852B)
    void PreloadAnimation(short);  // 0x800E73D8 (360B)
    void BlendHighlights(ELights *, bool *);  // 0x800E7540 (2120B)
    void CalcLightsFromPos(ELights *, bool);  // 0x800E7D88 (668B)
    void DoLightingCalculation(void);  // 0x800E8024 (1012B)
    void VisibilityTest(E3DWindow &);  // 0x800E8418 (164B)
    bool IsVisible(void);  // 0x800E84BC (164B)
    void DoAnimation(void);  // 0x800E8644 (412B)
    void AnimateLights(void);  // 0x800E8D24 (864B)
    void Draw(ELevelDrawData &);  // 0x800E87E0 (1348B)
    void DrawBounds(ERC *);  // 0x800E9084 (228B)
    void processAnimEvents(ERAnim *, int, int, bool);  // 0x800E990C (956B)
    void animEventHandler(ERAnim *, EAnimNote &, int);  // 0x800E9CC8 (1000B)
    void SetInitalObjectState(void);  // 0x800EA0B0 (460B)
    void Create(cXObject *, EHouse *);  // 0x800EA34C (264B)
    void SetObjOrient(void);  // 0x800EA454 (724B)
    void ApplyMatrix(float, EVec3 &, EVec3 &);  // 0x800EE288 (4880B)
    void OrientSubObjects(void);  // 0x800EA728 (184B)
    void OrentSubObject(void);  // 0x800EA7E0 (804B)
    bool IsMultiTilePart(void);  // 0x800EE1F4 (148B)
    void SetAutonomyScore(float);  // 0x800EF598 (212B)
    /* ? */ GetShadow(void);  // 0x800F59E8 (44B)
    void SafeDelete(void);  // 0x800F579C (108B)
    /* ? */ GetTypeInfo(void);  // 0x800F5808 (44B)
    /* ? */ GetTypeName(void);  // 0x800F5834 (52B)
    /* ? */ GetTypeKey(void);  // 0x800F5868 (52B)
    /* ? */ GetTypeVersion(void);  // 0x800F589C (56B)
    void RegisterType(unsigned short);  // 0x800F5930 (116B)
    void New(void);  // 0x800F56C8 (76B)
    void Construct(ISimsObjectModel *);  // 0x800F5714 (76B)
    void Destruct(ISimsObjectModel *);  // 0x800F5760 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x800F58D4 (40B)
    /* ? */ GetReadVersion(void);  // 0x800F58FC (52B)
    void CreateCopy(void);  // 0x800F59A4 (68B)
    /* ? */ GetDynamic(void);  // 0x800F5A14 (52B)
    void SetDynamic(bool);  // 0x800F5A48 (72B)
    /* ? */ GetPos(void);  // 0x800F5A90 (44B)
    void SetPos(EVec3 &);  // 0x800F5ABC (68B)
    /* ? */ GetDir(void);  // 0x800F5B00 (44B)
    void SetDir(EVec3 &);  // 0x800F5B2C (68B)
    void SetRot(float);  // 0x800F5B9C (40B)
    /* ? */ GetILight(void);  // 0x800F5BC4 (44B)
    void ShouldAnimStartBlendIn(unsigned int);  // 0x800F5BF0 (100B)
    void ShouldAnimStartImmediate(unsigned int);  // 0x800F5C54 (60B)
    void ShouldKillAllAnimTracks(unsigned int);  // 0x800F5C90 (56B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_heightOffset;  // 0x000 [R/W] (ApplyMatrix, BlendHighlights, CalcDynamicOrient, ...)
    f32 m_adjacentRoom;  // 0x004 [R/W] (ApplyMatrix, BlendHighlights, CreateShadow, ...)
    f32 m_field_008;  // 0x008 [R/W] (ApplyMatrix, BlendHighlights, DoLightingCalculation, ...)
    u32 m_initalObjectState;  // 0x00C [R/W] (BlendHighlights, DoLightingCalculation, SetInitalObjectState, ...)
    u8 m_tracks;  // 0x00E [R] (UpdateTracks)
    u8 _pad_00F[1];  // 0x00F
    u32 m_initalObjectState_010;  // 0x010 [R/W] (BlendHighlights, DoLightingCalculation, Draw, ...)
    s16 m_animController;  // 0x012 [R] (CreateShadow, UpdateAnimController)
    f32 m_field_014;  // 0x014 [R/W] (ApplyMatrix, BlendHighlights, DoLightingCalculation, ...)
    f32 m_field_018;  // 0x018 [R] (ApplyMatrix, Update)
    f32 m_field_01C;  // 0x01C [R/W] (ApplyMatrix, Update)
    u32 m_field_020;  // 0x020 [R/W] (ApplyMatrix, Update)
    u32 m_field_024;  // 0x024 [R/W] (ApplyMatrix, Update)
    u32 m_field_028;  // 0x028 [R/W] (ApplyMatrix, Update)
    u32 m_field_02C;  // 0x02C [R] (Update, VisibilityTest)
    u32 m_field_030;  // 0x030 [R] (Update, VisibilityTest)
    u32 m_field_034;  // 0x034 [R] (Update)
    u32 m_field_038;  // 0x038 [R] (Update)
    u32 m_field_03C;  // 0x03C [R] (Update)
    u8 _pad_040[0x10];  // 0x040
    f32 m_field_050;  // 0x050 [R] (Update)
    u8 _pad_054[8];  // 0x054
    u32 m_field_05C;  // 0x05C [R/W] (CreateShadow, ISimsObjectModel)
    u8 _pad_060[0x10];  // 0x060
    u32 m_field_070;  // 0x070 [R] (Draw)
    u8 _pad_074[8];  // 0x074
    u32 m_field_07C;  // 0x07C [W] (CreateShadow, InitBulb)
    u8 _pad_080[0x2C];  // 0x080
    f32 m_upCharacter;  // 0x0AC [R/W] (ApplyMatrix, InitBulb, SetupCharacter)
    u8 _pad_0B0[8];  // 0x0B0
    f32 m_field_0B8;  // 0x0B8 [R/W] (ApplyMatrix, InitBulb)
    u8 _pad_0BC[4];  // 0x0BC
    f32 m_animDef;  // 0x0C0 [R] (ApplyMatrix, CalcLightsFromPos, CreateShadow, ...)
    f32 m_upCharacter_0C4;  // 0x0C4 [W] (InitBulb, SetupCharacter)
    f32 m_upCharacter_0C8;  // 0x0C8 [W] (InitBulb, SetupCharacter)
    f32 m_upCharacter_0CC;  // 0x0CC [W] (InitBulb, SetupCharacter)
    f32 m_field_0D0;  // 0x0D0 [W] (InitBulb)
    u32 m_field_0D4;  // 0x0D4 [W] (InitBulb)
    u8 _pad_0D8[0x18];  // 0x0D8
    u32 m_field_0F0;  // 0x0F0 [R] (Draw)
    u8 _pad_0F4[0x1C];  // 0x0F4
    u32 m_sOMModel;  // 0x110 [R] (SetSOMModel)
    u8 _pad_114[4];  // 0x114
    u32 m_field_118;  // 0x118 [R] (CreateShadow, DoAnimation, DoLightingCalculation, ...)
    u32 m_field_11C;  // 0x11C [R] (CreateShadow, DoAnimation, Draw)
    u32 m_bIsVisible;  // 0x120 [R] (AnimateLights, ApplyMatrix, CalcLightsFromPos, ...)
    u32 m_field_124;  // 0x124 [R] (Draw)
    u8 _pad_128[0x1F0];  // 0x128
    u32 m_field_318;  // 0x318 [R] (Draw)
    u8 _pad_31C[4];  // 0x31C
    u32 m_field_320;  // 0x320 [R/W] (ApplyMatrix, Create, ISimsObjectModel, ...)
    u8 _pad_324[4];  // 0x324
    u32 m_adjacentRoom_328;  // 0x328 [R/W] (ApplyMatrix, Create, CreateShadow, ...)
    u32 m_field_32C;  // 0x32C [R/W] (DoLightingCalculation, ISimsObjectModel, PropigateFlagsToSubModels, ...)
    u8 _pad_330[0x10];  // 0x330
    u32 m_field_340;  // 0x340 [R] (AnimateLights)
    u8 _pad_344[0x14];  // 0x344
    u32 m_field_358;  // 0x358 [R] (DoAnimation, Draw)
    u8 _pad_35C[0x1C];  // 0x35C
    u32 m_animTrack;  // 0x378 [R] (StartNewAnimTrack, UpdateAnimTrack)
    u8 _pad_37C[0x40];  // 0x37C
    u32 m_field_3BC;  // 0x3BC [R/W] (CleanupStuff)
    u32 m_field_3C0;  // 0x3C0 [R/W] (CleanupStuff)
    u8 _pad_3C4[4];  // 0x3C4
    u32 m_objOrient;  // 0x3C8 [R/W] (Create, ISimsObjectModel, InitBulb, ...)
    u32 m_heightOffset_3CC;  // 0x3CC [R/W] (ApplyMatrix, GetHeightOffset, ISimsObjectModel, ...)
    u32 m_heightOffset_3D0;  // 0x3D0 [R/W] (GetHeightOffset, ISimsObjectModel)
    u32 m_field_3D4;  // 0x3D4 [W] (ISimsObjectModel)
    u32 m_field_3D8;  // 0x3D8 [W] (ISimsObjectModel)
    u32 m_field_3DC;  // 0x3DC [W] (ISimsObjectModel)
    u32 m_field_3E0;  // 0x3E0 [W] (ISimsObjectModel)
    u32 m_initalObjectState_3E4;  // 0x3E4 [R/W] (ISimsObjectModel, SetInitalObjectState, Update)
    u32 m_sOMModel_3E8;  // 0x3E8 [R/W] (AnimStartBlendIn, AnimStartImmediate, Draw, ...)
    f32 m_field_3EC;  // 0x3EC [R/W] (ISimsObjectModel, StartNewAnimTrack, UpdateAnimTrack, ...)
    f32 m_objOrient_3F0;  // 0x3F0 [R/W] (CalcOrient, SetObjOrient, Update)
    f32 m_field_3F4;  // 0x3F4 [W] (ISimsObjectModel)
    f32 m_highlightAnim;  // 0x3F8 [R/W] (ISimsObjectModel, UpdateHighlightAnim)
    f32 m_highlightAnim_3FC;  // 0x3FC [R/W] (ISimsObjectModel, UpdateHighlightAnim)
    u32 m_field_400;  // 0x400 [W] (ISimsObjectModel, Update)
    f32 m_field_404;  // 0x404 [W] (ApplyMatrix, Update)
    u8 _pad_408[0x14];  // 0x408
    u32 m_field_41C;  // 0x41C [R/W] (ChageShader, ISimsObjectModel, ~ISimsObjectModel)
    u32 m_initalObjectState_420;  // 0x420 [R/W] (ISimsObjectModel, SetInitalObjectState)
    u8 _pad_424[4];  // 0x424
    u32 m_field_428;  // 0x428 [R] (StartNewAnimTrack)
    u8 _pad_42C[0x14];  // 0x42C
    u32 m_field_440;  // 0x440 [R/W] (Draw, ISimsObjectModel, Update, ...)
    u8 _pad_444[8];  // 0x444
    u32 m_field_44C;  // 0x44C [R/W] (ApplyMatrix, CalcDynamicOrient, CalcOrient, ...)
    u32 m_field_450;  // 0x450 [R/W] (ISimsObjectModel, InsertSubModelsInHouse, OrientSubObjects, ...)
    u8 _pad_454[8];  // 0x454
    u32 m_adjacentRoom_45C;  // 0x45C [R/W] (GetAdjacentRoom, ISimsObjectModel, SetWallForPortal)
    u32 m_initalObjectState_460;  // 0x460 [R/W] (ApplyMatrix, CleanupStuff, ISimsObjectModel, ...)
    u32 m_field_464;  // 0x464 [R] (AnimateLights, CleanupStuff)
    u32 m_field_468;  // 0x468 [R] (AnimateLights)
    u8 _pad_46C[4];  // 0x46C
    f32 m_field_470;  // 0x470 [W] (ApplyMatrix)
    f32 m_field_474;  // 0x474 [W] (ISimsObjectModel)
    f32 m_field_478;  // 0x478 [W] (ISimsObjectModel)
    f32 m_field_47C;  // 0x47C [W] (ISimsObjectModel)
    u32 m_field_480;  // 0x480 [W] (ApplyMatrix)
    u8 _pad_484[8];  // 0x484
    f32 m_field_48C;  // 0x48C [R/W] (ISimsObjectModel, ProcessPropertyEventTags, StartNewAnimTrack, ...)
    u32 m_field_490;  // 0x490 [R/W] (ISimsObjectModel, ProcessPropertyEventTags, StartNewAnimTrack, ...)
    u32 m_field_494;  // 0x494 [R/W] (ISimsObjectModel, TryAnimateObject)
    u32 m_field_498;  // 0x498 [R/W] (ISimsObjectModel, ProcessPropertyEventTags, StartNewAnimTrack, ...)
    u32 m_field_49C;  // 0x49C [R/W] (ISimsObjectModel, ProcessPropertyEventTags, StartNewAnimTrack, ...)
    u32 m_initalObjectState_4A0;  // 0x4A0 [R/W] (SetInitalObjectState, TryAnimateObject, Update, ...)
    u32 m_field_4A4;  // 0x4A4 [R/W] (ISimsObjectModel, ProcessPropertyEventTags, StartNewAnimTrack, ...)
    u32 m_animTrack_4A8;  // 0x4A8 [W] (StartNewAnimTrack, UpdateAnimTrack)
    u8 _pad_4AC[8];  // 0x4AC
    u32 m_field_4B4;  // 0x4B4 [R/W] (CleanupStuff, ISimsObjectModel, KillAllAnimTracks, ...)
    u32 m_field_4B8;  // 0x4B8 [W] (ISimsObjectModel)
    u8 _pad_4BC[0x2D78];  // 0x4BC
    f32 m_field_3234;  // 0x3234 [R] (Draw)
    f32 m_field_3238;  // 0x3238 [R] (Draw)
};

#endif // ISIMSOBJECTMODEL_H
