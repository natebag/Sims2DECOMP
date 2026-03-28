#ifndef EINSTANCE_H
#define EINSTANCE_H

#include "types.h"

// EInstance - struct layout extracted from assembly analysis
// Estimated minimum size: 0x60 (96 bytes)
// 13 known fields (7 named), 162 methods

class EInstance {
public:
    // Constructors / Destructors
    EInstance(void)  // 0x8061C968
    ~EInstance(void);  // 0x8061CA88

    // Methods
    void SafeDelete(void);  // 0x80620578 (108B)
    /* ? */ GetTypeInfo(void);  // 0x806205E4 (44B)
    /* ? */ GetTypeName(void);  // 0x80620610 (52B)
    /* ? */ GetTypeKey(void);  // 0x80620644 (52B)
    /* ? */ GetTypeVersion(void);  // 0x80620678 (56B)
    void Read(EStream &);  // 0x8061CBDC (432B)
    void Write(EStream &);  // 0x8061CB4C (144B)
    void Load(EFile &);  // 0x8061CD8C (420B)
    void Init(void);  // 0x806207C4 (32B)
    void Update(void);  // 0x806207E4 (32B)
    void DoAnimation(void);  // 0x80620804 (32B)
    void DoLightingCalculation(void);  // 0x80620824 (32B)
    void DrawStencil(ELevelDrawData &);  // 0x806208F8 (136B)
    void DrawShadow(ELevelDrawData &);  // 0x80620980 (136B)
    void DrawWireFrame(ERC *);  // 0x80620A08 (36B)
    void SetOrient(EMat4 &);  // 0x80620A2C (36B)
    void RebuildShaders(void);  // 0x80620A50 (32B)
    /* ? */ GetUpdatePriority(void);  // 0x80620AA8 (40B)
    void RegisterFloor(void);  // 0x80620AD0 (32B)
    /* ? */ GetShadowCenter(EVec3 &);  // 0x80620EB8 (36B)
    /* ? */ GetBoundSphere(EBoundSphere &);  // 0x8061CF9C (76B)
    void ReadInstanceData(EStream &, bool);  // 0x80620F08 (40B)
    bool CanReloadInstanceData(void);  // 0x80620F30 (40B)
    /* ? */ GetLevel(void);  // 0x80620F58 (44B)
    /* ? */ GetOwner(void);  // 0x80620F84 (40B)
    /* ? */ GetNumRoomID(void);  // 0x80620FAC (40B)
    /* ? */ GetRoomID(unsigned int);  // 0x80620FD4 (44B)
    /* ? */ GetVelocity(EVec3 &);  // 0x80621000 (68B)
    /* ? */ GetPos(EVec3 &);  // 0x80621044 (68B)
    /* ? */ GetOrient(EMat4 &);  // 0x80621088 (60B)
    bool HasModifiableColor(void);  // 0x806210C4 (40B)
    void ModifyColor(unsigned int);  // 0x806210EC (136B)
    /* ? */ GetModifiableColor(unsigned int);  // 0x80621174 (144B)
    void AddedToLevel(ERLevel *);  // 0x80621204 (36B)
    void AboutToBeRemovedFromLevel(ERLevel *);  // 0x80621228 (36B)
    void RemovedFromLevel(ERLevel *);  // 0x8062124C (36B)
    void RealizeShaderTuning(void);  // 0x80621338 (32B)
    /* ? */ GetBounds(void);  // 0x80620EDC (44B)
    void SetContext(int);  // 0x8061DCF4 (52B)
    /* ? */ GetLocationId(short &, short &);  // 0x80620B9C (124B)
    void RegisterThisSideFn(unsigned int, void (*);  // 0x80620DC8 (48B)
    /* ? */ GetInstAlpha(void);  // 0x8061DDDC (64B)
    /* ? */ GetContext(void);  // 0x8061DD28 (44B)
    void CalcLights4(EVec3 &, ELights &, bool);  // 0x8061DA58 (500B)
    void InsertInOrderTable(EOrderTableData &);  // 0x8061DC4C (168B)
    void SetPortalType(EPortalType);  // 0x80620C94 (40B)
    void SetShadowInterpolated(bool);  // 0x80620E90 (40B)
    void CalcLights(EVec3 &, ELights &, bool);  // 0x8061D864 (500B)
    void SetInstAlpha(float);  // 0x8061DD54 (136B)
    void RegisterHiddenFn(unsigned int, bool (*);  // 0x80620DF8 (48B)
    void SetBounds(EBound3 &);  // 0x8061CF30 (108B)
    bool IsHidden(void);  // 0x80620E28 (104B)
    void RegisterOtherSideFn(unsigned int, void (*);  // 0x80620CE8 (48B)
    /* ? */ GetPortalType(void);  // 0x80620CBC (44B)
    void ShouldInterestFade(bool);  // 0x80621304 (52B)
    void VisibilityTest(E3DWindow &);  // 0x80620844 (44B)
    void Draw(ELevelDrawData &);  // 0x80620870 (136B)
    /* ? */ GetInstName(EInstance::InstType &);  // 0x80620A70 (56B)
    void RemoveFromLevel(void);  // 0x8061CFE8 (80B)
    /* ? */ GetReadVersion(void);  // 0x806206D8 (52B)
    void ShadowDirAtPoint(EVec3 &, EVec3 &, int);  // 0x8061D0BC (480B)
    void CalcShadowLight(EVec3 &, short);  // 0x8061D29C (352B)
    void ShadowDirAtPointWeighted(EVec3 &, EVec3 &, int);  // 0x8061D52C (580B)
    void CalcShadowLightWeighted(EVec3 &, short);  // 0x8061D3FC (304B)
    /* ? */ GetOtherSide(short &, short &);  // 0x80620C18 (124B)
    void RegisterType(unsigned short);  // 0x8062070C (116B)
    void New(void);  // 0x8062049C (80B)
    void Construct(EInstance *);  // 0x806204EC (80B)
    void Destruct(EInstance *);  // 0x8062053C (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x806206B0 (40B)
    void CreateCopy(void);  // 0x80620780 (68B)
    void ResetLocation(void);  // 0x80620AF0 (172B)
    /* ? */ GetThisSideData(void);  // 0x80620D18 (44B)
    /* ? */ GetThisSideFn(void);  // 0x80620D44 (44B)
    /* ? */ GetOtherSideData(void);  // 0x80620D70 (44B)
    /* ? */ GetOtherSideFn(void);  // 0x80620D9C (44B)
    bool IsShadow(void);  // 0x80621270 (60B)
    /* ? */ GetShadowOwner(void);  // 0x806212AC (44B)
    bool IsWall(void);  // 0x806212D8 (44B)

    // ---- Field Layout (from assembly analysis) ----
    s16 m_field_000;  // 0x000 [R/W] (ShadowDirAtPoint, ~EInstance)
    u8 _pad_002[2];  // 0x002
    u32 m_bounds;  // 0x004 [R] (CalcLights, CalcLights4, CalcShadowLight, ...)
    u8 _pad_008[4];  // 0x008
    u32 m_field_00C;  // 0x00C [R] (CalcShadowLight)
    u8 _pad_010[8];  // 0x010
    u32 m_field_018;  // 0x018 [R] (Read, Write)
    u32 m_locationId;  // 0x01C [R] (CalcLights, CalcLights4, GetLocationId, ...)
    u32 m_otherSide;  // 0x020 [R] (CalcLights, CalcLights4, GetOtherSide, ...)
    u32 m_otherSide_024;  // 0x024 [R] (CalcLights, CalcLights4, GetOtherSide, ...)
    u32 m_locationId_028;  // 0x028 [R] (CalcLights, CalcLights4, GetLocationId, ...)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [R] (Write)
    f32 m_bounds_03C;  // 0x03C [R/W] (CalcShadowLight, CalcShadowLightWeighted, SetBounds)
    u8 _pad_040[8];  // 0x040
    f32 m_bounds_048;  // 0x048 [R/W] (CalcShadowLight, CalcShadowLightWeighted, SetBounds)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R] (Write)
    u32 m_field_05C;  // 0x05C [R] (Write)
};

#endif // EINSTANCE_H
