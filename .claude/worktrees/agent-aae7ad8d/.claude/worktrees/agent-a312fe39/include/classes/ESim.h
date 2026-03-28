#ifndef ESIM_H
#define ESIM_H

#include "types.h"

// ESim - struct layout extracted from assembly analysis
// Estimated minimum size: 0x648 (1608 bytes)
// 97 known fields (21 named), 152 methods

class ESim {
public:
    // Static members (from map file)
    // static ??? m_pMemoryForHeap;

    // Constructors / Destructors
    ESim(cXPerson *)  // 0x8008181C
    ESim(void)  // 0x8008CEC8
    ~ESim(void);  // 0x80081DE4

    // Methods
    void RefreshSkin(void);  // 0x80087CEC (320B)
    /* ? */ GetIsModelLoaded(void);  // 0x8008D1A8 (44B)
    bool IsAdult(void);  // 0x80082B90 (112B)
    void tProcessCommand(unsigned int);  // 0x80087E2C (228B)
    /* ? */ GetPerson(void);  // 0x8008D01C (44B)
    void ServiceNpcOrderTableCallback(ELevelDrawData &, EOrderTableData *);  // 0x800852B4 (492B)
    void SimOrderTableCallback(ELevelDrawData &, EOrderTableData *);  // 0x80084D48 (580B)
    void CensorOrderTableCallback(ELevelDrawData &, EOrderTableData *);  // 0x80084F8C (364B)
    void PropOrderTableCallback(ELevelDrawData &, EOrderTableData *);  // 0x80084B04 (580B)
    void SkillMeterOrderTableCallback(ELevelDrawData &, EOrderTableData *);  // 0x80085674 (208B)
    bool IsDog(void);  // 0x80082C70 (112B)
    bool IsCat(void);  // 0x80082CE0 (112B)
    bool IsMonkey(void);  // 0x80082D50 (112B)
    bool HasQueuedOperation(void);  // 0x80087F10 (184B)
    void flushQueuedCostumeModels(void);  // 0x80082AA0 (56B)
    void TransferModelToCache(void);  // 0x80082548 (1368B)
    void DeletePlayerCachedModel(void);  // 0x80082168 (200B)
    void ReadModelFromCache(void);  // 0x80082230 (792B)
    /* ? */ GetSimModel(void);  // 0x8008D0C0 (44B)
    bool IsMale(void);  // 0x80082AD8 (112B)
    bool IsFemale(void);  // 0x80082B48 (72B)
    bool IsChild(void);  // 0x80082C00 (112B)
    bool IsPet(void);  // 0x80082DC0 (112B)
    void initModel(void);  // 0x80082E30 (3364B)
    void CompositeSkin(void);  // 0x80087A14 (192B)
    void DrawSim(bool);  // 0x800881C8 (140B)
    void DrawPlumbBob(ERC *);  // 0x80083B54 (820B)
    /* ? */ GetPlayerIndex(void);  // 0x800883D0 (152B)
    void UpdateSkillMeter(EVec3 &, EVec3 &);  // 0x80083E88 (864B)
    void DrawSkillMeter(ERC *);  // 0x800841E8 (1424B)
    void SetPlumbBobState(unsigned int);  // 0x80084778 (908B)
    void DrawSimAndNpcCommonItems(ERC *);  // 0x800854A0 (468B)
    void DrawSimModel(ERC *, EMat4 *, unsigned int);  // 0x80085248 (108B)
    void DrawCursorHighLight(ERC *);  // 0x80085744 (1024B)
    void DoAnimation(void);  // 0x80085B44 (112B)
    void DoLightingCalculation(void);  // 0x80085BB4 (40B)
    void Draw(ELevelDrawData &);  // 0x80085BDC (3692B)
    void Update(void);  // 0x80086A48 (1148B)
    void UpdateQueuedOperation(void);  // 0x80087FC8 (224B)
    void UpdateSkinChange(void);  // 0x800872B0 (1552B)
    void UpdateShowerCurtain(void);  // 0x800870B0 (512B)
    void UpdateGhostParticleEffect(void);  // 0x800886C8 (716B)
    void UpdatePlumbBob(void);  // 0x80088468 (140B)
    void UpdateShadow(void);  // 0x800884F4 (468B)
    void VisibilityTest(E3DWindow &);  // 0x80086EC4 (280B)
    void SetAnim(char *);  // 0x80086FDC (212B)
    void CreateSkinAsync(void);  // 0x800878C0 (340B)
    void CreateThumbnail(void);  // 0x80087AD4 (284B)
    void UpdateRepShaders(int);  // 0x80087BF0 (252B)
    void ChangeCostume(void);  // 0x80088994 (112B)
    /* ? */ GetScaler(void);  // 0x800880A8 (288B)
    /* ? */ GetObCenter(void);  // 0x80088254 (380B)
    void SafeDelete(void);  // 0x8008CC7C (108B)
    /* ? */ GetTypeInfo(void);  // 0x8008CCE8 (44B)
    /* ? */ GetTypeName(void);  // 0x8008CD14 (52B)
    /* ? */ GetTypeKey(void);  // 0x8008CD48 (52B)
    /* ? */ GetTypeVersion(void);  // 0x8008CD7C (56B)
    /* ? */ GetShadow(void);  // 0x8008CFF0 (44B)
    void SetXOb(cXObject *);  // 0x8008CF68 (136B)
    void RegisterType(unsigned short);  // 0x8008CE10 (116B)
    void New(void);  // 0x8008CBA8 (76B)
    void Construct(ESim *);  // 0x8008CBF4 (76B)
    void Destruct(ESim *);  // 0x8008CC40 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8008CDB4 (40B)
    /* ? */ GetReadVersion(void);  // 0x8008CDDC (52B)
    void CreateCopy(void);  // 0x8008CE84 (68B)
    /* ? */ GetModelPart(int);  // 0x8008D048 (76B)
    /* ? */ GetSimHead(void);  // 0x8008D094 (44B)
    void SetVanityDraw(bool, unsigned int);  // 0x8008D0EC (48B)
    void UseVanityDraw(unsigned int *);  // 0x8008D11C (56B)
    /* ? */ GetPlumbBobState(void);  // 0x8008D154 (44B)
    void SetSkillmeterValue(float);  // 0x8008D180 (40B)
    /* ? */ GetIsChangingOutfit(void);  // 0x8008D1D4 (44B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_obCenter;  // 0x000 [R/W] (CensorOrderTableCallback, DeletePlayerCachedModel, Draw, ...)
    f32 m_obCenter_004;  // 0x004 [R/W] (Draw, DrawSim, ESim, ...)
    f32 m_obCenter_008;  // 0x008 [R/W] (ESim, GetObCenter, initModel)
    u32 m_field_00C;  // 0x00C [W] (ESim)
    u32 m_field_010;  // 0x010 [W] (ESim)
    u32 m_ghostParticleEffect;  // 0x014 [R/W] (ESim, UpdateGhostParticleEffect)
    u32 m_ghostParticleEffect_018;  // 0x018 [R/W] (ESim, UpdateGhostParticleEffect)
    u32 m_field_01C;  // 0x01C [W] (ESim)
    u32 m_field_020;  // 0x020 [W] (ESim)
    u32 m_field_024;  // 0x024 [W] (ESim)
    u8 _pad_028[0xC];  // 0x028
    u32 m_field_034;  // 0x034 [W] (ESim)
    u8 _pad_038[0x1C];  // 0x038
    f32 m_field_054;  // 0x054 [W] (initModel)
    u8 _pad_058[4];  // 0x058
    u32 m_field_05C;  // 0x05C [R/W] (ESim, Update)
    f32 m_field_060;  // 0x060 [W] (Update)
    f32 m_field_064;  // 0x064 [W] (Update)
    u32 m_field_068;  // 0x068 [R/W] (Draw, ESim)
    u32 m_field_06C;  // 0x06C [W] (ESim)
    u32 m_field_070;  // 0x070 [R] (Draw)
    u8 _pad_074[0x15];  // 0x074
    u8 m_field_089;  // 0x089 [R] (CompositeSkin)
    u8 _pad_08A[0xE];  // 0x08A
    u32 m_field_098;  // 0x098 [R] (CensorOrderTableCallback, PropOrderTableCallback, ServiceNpcOrderTableCallback, ...)
    u8 _pad_09C[0xC];  // 0x09C
    u32 m_field_0A8;  // 0x0A8 [W] (CensorOrderTableCallback, PropOrderTableCallback, ServiceNpcOrderTableCallback, ...)
    u32 m_field_0AC;  // 0x0AC [W] (CensorOrderTableCallback, PropOrderTableCallback, ServiceNpcOrderTableCallback, ...)
    u32 m_field_0B0;  // 0x0B0 [W] (SkillMeterOrderTableCallback)
    u32 m_field_0B4;  // 0x0B4 [W] (CensorOrderTableCallback, PropOrderTableCallback, ServiceNpcOrderTableCallback, ...)
    u32 m_field_0B8;  // 0x0B8 [W] (PropOrderTableCallback, SimOrderTableCallback, SkillMeterOrderTableCallback)
    u8 _pad_0BC[0x5C];  // 0x0BC
    u32 m_field_118;  // 0x118 [R] (initModel)
    u8 _pad_11C[4];  // 0x11C
    u32 m_shadow;  // 0x120 [R/W] (UpdateShadow, initModel)
    u8 _pad_124[0x1FC];  // 0x124
    u32 m_field_320;  // 0x320 [W] (ESim, ~ESim)
    u8 _pad_324[4];  // 0x324
    u32 m_field_328;  // 0x328 [W] (ESim)
    u32 m_simAndNpcCommonItems;  // 0x32C [R] (DrawSimAndNpcCommonItems)
    u8 _pad_330[0xA0];  // 0x330
    u32 m_field_3D0;  // 0x3D0 [R/W] (CompositeSkin, CreateThumbnail, Draw, ...)
    u32 m_field_3D4;  // 0x3D4 [W] (initModel)
    u32 m_field_3D8;  // 0x3D8 [R/W] (CreateSkinAsync, ESim, RefreshSkin, ...)
    u8 _pad_3DC[4];  // 0x3DC
    u32 m_field_3E0;  // 0x3E0 [R/W] (ESim, Update, UpdateShadow, ...)
    u32 m_field_3E4;  // 0x3E4 [W] (ESim)
    u32 m_plumbBobState;  // 0x3E8 [R/W] (DrawPlumbBob, DrawSkillMeter, ESim, ...)
    u32 m_plumbBobState_3EC;  // 0x3EC [R/W] (DrawPlumbBob, DrawSkillMeter, SetPlumbBobState, ...)
    f32 m_skillMeter;  // 0x3F0 [R/W] (DrawSkillMeter, initModel)
    f32 m_plumbBobState_3F4;  // 0x3F4 [R/W] (DrawPlumbBob, SetPlumbBobState, UpdateSkillMeter)
    u8 _pad_3F8[0xC];  // 0x3F8
    u32 m_ghostParticleEffect_404;  // 0x404 [R/W] (ESim, UpdateGhostParticleEffect)
    u32 m_field_408;  // 0x408 [R/W] (DrawCursorHighLight, ESim, initModel, ...)
    u32 m_field_40C;  // 0x40C [R/W] (DrawCursorHighLight, ESim, initModel, ...)
    u32 m_field_410;  // 0x410 [R/W] (ESim, initModel, ~ESim)
    u32 m_field_414;  // 0x414 [W] (ESim)
    f32 m_field_418;  // 0x418 [R/W] (DrawCursorHighLight, DrawSkillMeter, ESim)
    u32 m_cursorHighLight;  // 0x41C [R/W] (DrawCursorHighLight, ESim)
    u32 m_cursorHighLight_420;  // 0x420 [R/W] (DrawCursorHighLight, ESim)
    u32 m_skinChange;  // 0x424 [R/W] (ESim, UpdateSkinChange)
    u32 m_shadow_428;  // 0x428 [R/W] (Draw, DrawSim, UpdateShadow)
    u32 m_field_42C;  // 0x42C [R/W] (DrawSimAndNpcCommonItems, ESim, initModel, ...)
    u32 m_field_430;  // 0x430 [R/W] (DrawSimAndNpcCommonItems, ESim, UpdateShowerCurtain, ...)
    u32 m_showerCurtain;  // 0x434 [R/W] (ESim, UpdateShowerCurtain, UpdateSkinChange)
    f32 m_field_438;  // 0x438 [R/W] (DrawSimAndNpcCommonItems, ESim, UpdateShowerCurtain, ...)
    f32 m_queuedOperation;  // 0x43C [R/W] (DrawSkillMeter, ESim, UpdateQueuedOperation)
    u32 m_field_440;  // 0x440 [W] (ESim, initModel)
    u32 m_field_444;  // 0x444 [W] (ESim, initModel)
    u32 m_field_448;  // 0x448 [W] (ESim, initModel)
    u32 m_field_44C;  // 0x44C [W] (ESim, initModel)
    u32 m_field_450;  // 0x450 [R/W] (Draw)
    u32 m_field_454;  // 0x454 [R/W] (Draw, ESim, Update, ...)
    u32 m_field_458;  // 0x458 [W] (ESim, initModel)
    u8 _pad_45C[8];  // 0x45C
    u32 m_field_464;  // 0x464 [W] (ESim, initModel)
    u8 _pad_468[0x10];  // 0x468
    u32 m_field_478;  // 0x478 [W] (ESim, initModel)
    u32 m_field_47C;  // 0x47C [W] (ESim, initModel)
    u32 m_field_480;  // 0x480 [W] (ESim, initModel)
    u32 m_field_484;  // 0x484 [W] (ESim, initModel)
    u32 m_field_488;  // 0x488 [W] (Draw)
    u32 m_field_48C;  // 0x48C [W] (ESim, initModel)
    u32 m_field_490;  // 0x490 [W] (ESim, initModel)
    u8 _pad_494[8];  // 0x494
    u32 m_field_49C;  // 0x49C [W] (ESim, initModel)
    u8 _pad_4A0[0x10];  // 0x4A0
    u32 m_field_4B0;  // 0x4B0 [W] (ESim)
    u32 m_field_4B4;  // 0x4B4 [W] (ESim)
    u32 m_field_4B8;  // 0x4B8 [W] (ESim)
    u32 m_field_4BC;  // 0x4BC [W] (ESim)
    u32 m_field_4C0;  // 0x4C0 [W] (ESim)
    u32 m_field_4C4;  // 0x4C4 [W] (ESim)
    u8 _pad_4C8[0xC];  // 0x4C8
    u32 m_field_4D4;  // 0x4D4 [W] (ESim)
    u8 _pad_4D8[0x10];  // 0x4D8
    u32 m_field_4E8;  // 0x4E8 [W] (ESim)
    u32 m_field_4EC;  // 0x4EC [W] (ESim)
    u32 m_field_4F0;  // 0x4F0 [W] (ESim)
    u32 m_field_4F4;  // 0x4F4 [W] (ESim)
    u32 m_field_4F8;  // 0x4F8 [R/W] (Draw)
    u32 m_field_4FC;  // 0x4FC [R/W] (Draw, ESim)
    u32 m_field_500;  // 0x500 [W] (ESim)
    u8 _pad_504[8];  // 0x504
    u32 m_field_50C;  // 0x50C [W] (ESim)
    u8 _pad_510[0x10];  // 0x510
    u32 m_skinChange_520;  // 0x520 [R/W] (ESim, UpdateQueuedOperation, UpdateSkinChange)
    u32 m_field_524;  // 0x524 [W] (ESim, initModel)
    u32 m_field_528;  // 0x528 [W] (Draw)
    u32 m_field_52C;  // 0x52C [W] (ESim, initModel)
    u8 _pad_530[0xF8];  // 0x530
    u32 m_field_628;  // 0x628 [R/W] (ESim, ~ESim)
    u32 m_field_62C;  // 0x62C [W] (initModel)
    u32 m_field_630;  // 0x630 [R/W] (CreateSkinAsync, ESim, RefreshSkin, ...)
    u32 m_shadow_634;  // 0x634 [R/W] (Draw, UpdateShadow, initModel)
    u32 m_field_638;  // 0x638 [R/W] (Draw, ESim, Update, ...)
    u32 m_scaler;  // 0x63C [R/W] (ChangeCostume, CompositeSkin, CreateThumbnail, ...)
    u32 m_field_640;  // 0x640 [R/W] (ESim, Update)
    u32 m_field_644;  // 0x644 [R/W] (ESim, ReadModelFromCache, TransferModelToCache)
};

#endif // ESIM_H
