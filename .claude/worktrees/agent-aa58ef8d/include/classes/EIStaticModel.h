#ifndef EISTATICMODEL_H
#define EISTATICMODEL_H

#include "types.h"

// EIStaticModel - struct layout extracted from assembly analysis
// Estimated minimum size: 0x31C (796 bytes)
// 44 known fields (28 named), 112 methods

class EIStaticModel {
public:
    // Constructors / Destructors
    EIStaticModel(void)  // 0x8062C864
    ~EIStaticModel(void);  // 0x8062C93C

    // Methods
    /* ? */ GetOrient(void);  // 0x80632CC8 (44B)
    void SetModel(unsigned int, bool, EInstance *, EAnimController *);  // 0x8062CD38 (116B)
    void SetOrient(EMat4 &);  // 0x8062CE10 (180B)
    void Draw(ELevelDrawData &);  // 0x8062D9C0 (824B)
    void ChangeShader(unsigned int, unsigned int);  // 0x8062E218 (328B)
    /* ? */ GetModel(void);  // 0x80632C70 (44B)
    void Read(EStream &);  // 0x8062CA08 (240B)
    void Write(EStream &);  // 0x8062C9A8 (96B)
    void RebuildShaders(void);  // 0x8062E59C (188B)
    /* ? */ GetInstName(EInstance::InstType &);  // 0x8062F994 (124B)
    void RegisterFloor(void);  // 0x8062CF70 (768B)
    /* ? */ GetBoundSphere(EBoundSphere &);  // 0x8062CAF8 (76B)
    /* ? */ GetPos(EVec3 &);  // 0x80632B38 (116B)
    /* ? */ GetOrient(EMat4 &);  // 0x8062CF24 (76B)
    bool HasModifiableColor(void);  // 0x8062F12C (88B)
    void ModifyColor(unsigned int);  // 0x8062F184 (156B)
    /* ? */ GetModifiableColor(void);  // 0x8062F220 (44B)
    /* ? */ GetAnchorPos(EMat4 &, int);  // 0x80632BFC (72B)
    /* ? */ GetDrawMatrix(void);  // 0x80632C9C (44B)
    void DrawShadow(ELevelDrawData &);  // 0x8062DEA4 (560B)
    void RealizeShaderTuning(void);  // 0x8062E658 (124B)
    void SafeDelete(void);  // 0x80632820 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8063288C (44B)
    /* ? */ GetTypeName(void);  // 0x806328B8 (52B)
    /* ? */ GetTypeKey(void);  // 0x806328EC (52B)
    /* ? */ GetTypeVersion(void);  // 0x80632920 (56B)
    void VisibilityTest(E3DWindow &);  // 0x8062D960 (96B)
    void SlamOrient(EMat4 &, EMat4 &);  // 0x8062CEC4 (96B)
    void AnimOrderTableCallback(ELevelDrawData &, EOrderTableData *);  // 0x8062E0D4 (324B)
    bool IsSkydome(void);  // 0x80632BAC (80B)
    /* ? */ GetModelId(void);  // 0x80632C44 (44B)
    void Clone(void);  // 0x8062EFB4 (376B)
    void ReplaceBaseTexture(ERTexture *, unsigned int, ERTexture *);  // 0x8062E914 (1696B)
    void DrawImmediate(ERC *, EAnimController *);  // 0x8062F24C (512B)
    void DrawImmediateGhosted(ERC *, EAnimController *);  // 0x8062F44C (860B)
    void DeallocateModel(void);  // 0x8062CC70 (200B)
    /* ? */ GetReadVersion(void);  // 0x80632980 (52B)
    void Setup(EInstance *, EAnimController *);  // 0x8062CB44 (300B)
    void SetupModel(EInstance *, EAnimController *);  // 0x8062D270 (512B)
    void SetupBounds(void);  // 0x8062D788 (472B)
    void SetModel(char *);  // 0x8062CDAC (100B)
    void BuildDigests(void);  // 0x8062D470 (792B)
    void DrawAsShadow(ELevelDrawData &);  // 0x8062DCF8 (428B)
    void ChangeShaderState(unsigned int);  // 0x8062E360 (260B)
    void UpdateShaders(void);  // 0x8062E464 (312B)
    void FindShaderContainingTexture(unsigned int);  // 0x8062E6D4 (292B)
    void FindShaderSupportingDecal(void);  // 0x8062E7F8 (284B)
    void TagAsGrabbed(void);  // 0x8062F7A8 (492B)
    void RegisterType(unsigned short);  // 0x806329B4 (116B)
    void New(void);  // 0x8063274C (76B)
    void Construct(EIStaticModel *);  // 0x80632798 (76B)
    void Destruct(EIStaticModel *);  // 0x806327E4 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x80632958 (40B)
    void CreateCopy(void);  // 0x80632A28 (68B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_field_000;  // 0x000 [R/W] (AnimOrderTableCallback, BuildDigests, Clone, ...)
    u16 m_asShadow;  // 0x002 [R/W] (BuildDigests, DrawAsShadow)
    u32 m_field_004;  // 0x004 [R/W] (BuildDigests, Clone, Draw, ...)
    u32 m_orient;  // 0x008 [R] (BuildDigests, Clone, DrawAsShadow, ...)
    f32 m_orient_00C;  // 0x00C [R/W] (BuildDigests, Clone, DrawAsShadow, ...)
    u32 m_orient_010;  // 0x010 [R] (Clone, DrawAsShadow, DrawShadow, ...)
    u32 m_orient_014;  // 0x014 [R/W] (Clone, Draw, DrawAsShadow, ...)
    u32 m_orient_018;  // 0x018 [R/W] (Clone, Draw, DrawAsShadow, ...)
    u32 m_anchorPos;  // 0x01C [R] (DrawShadow, GetAnchorPos, GetOrient)
    u32 m_anchorPos_020;  // 0x020 [R] (GetAnchorPos, GetOrient)
    u32 m_anchorPos_024;  // 0x024 [R] (DrawAsShadow, DrawShadow, GetAnchorPos, ...)
    u32 m_anchorPos_028;  // 0x028 [R] (DrawShadow, GetAnchorPos, GetOrient)
    u32 m_orient_02C;  // 0x02C [R] (DrawAsShadow, DrawImmediate, DrawImmediateGhosted, ...)
    u32 m_orient_030;  // 0x030 [R] (DrawAsShadow, DrawImmediate, DrawImmediateGhosted, ...)
    u32 m_anchorPos_034;  // 0x034 [R] (GetAnchorPos, GetOrient)
    u32 m_anchorPos_038;  // 0x038 [R] (GetAnchorPos, GetOrient)
    u32 m_anchorPos_03C;  // 0x03C [R] (GetAnchorPos, GetOrient)
    u8 _pad_040[0x1C];  // 0x040
    u32 m_field_05C;  // 0x05C [R/W] (BuildDigests, EIStaticModel)
    u8 _pad_060[8];  // 0x060
    u32 m_field_068;  // 0x068 [W] (BuildDigests)
    u32 m_field_06C;  // 0x06C [W] (BuildDigests)
    u32 m_field_070;  // 0x070 [R/W] (AnimOrderTableCallback, BuildDigests, Draw, ...)
    u32 m_immediateGhosted;  // 0x074 [R] (DrawImmediateGhosted)
    u8 _pad_078[4];  // 0x078
    u32 m_upModel;  // 0x07C [R/W] (Clone, Draw, DrawAsShadow, ...)
    u32 m_anchorPos_080;  // 0x080 [R/W] (Clone, GetAnchorPos, SetOrient, ...)
    u32 m_anchorPos_084;  // 0x084 [R/W] (Clone, GetAnchorPos, SetOrient, ...)
    u8 _pad_088[0x10];  // 0x088
    u32 m_field_098;  // 0x098 [R] (AnimOrderTableCallback)
    u8 _pad_09C[0xC];  // 0x09C
    u32 m_field_0A8;  // 0x0A8 [R/W] (AnimOrderTableCallback)
    u8 _pad_0AC[8];  // 0x0AC
    u32 m_immediateGhosted_0B4;  // 0x0B4 [R] (DrawImmediateGhosted)
    u8 _pad_0B8[8];  // 0x0B8
    f32 m_orient_0C0;  // 0x0C0 [R/W] (GetOrient, SetOrient, Setup, ...)
    u32 m_orient_0C4;  // 0x0C4 [R/W] (GetOrient, SetOrient, Setup, ...)
    u8 _pad_0C8[4];  // 0x0C8
    f32 m_up;  // 0x0CC [W] (Setup)
    f32 m_up_0D0;  // 0x0D0 [R] (Setup)
    u8 _pad_0D4[0xC];  // 0x0D4
    f32 m_up_0E0;  // 0x0E0 [R] (Setup)
    u8 _pad_0E4[0xC];  // 0x0E4
    u32 m_field_0F0;  // 0x0F0 [R] (AnimOrderTableCallback, Draw, DrawAsShadow, ...)
    u8 _pad_0F4[0xC];  // 0x0F4
    u32 m_field_100;  // 0x100 [R/W] (Clone, EIStaticModel)
    u8 _pad_104[0xC];  // 0x104
    u32 m_upModel_110;  // 0x110 [R/W] (Clone, EIStaticModel, SetupModel, ...)
    u32 m_upModel_114;  // 0x114 [R/W] (Clone, DeallocateModel, EIStaticModel, ...)
    u32 m_field_118;  // 0x118 [R/W] (BuildDigests, ChangeShader, ChangeShaderState, ...)
    u32 m_field_11C;  // 0x11C [R/W] (BuildDigests, Clone, DeallocateModel, ...)
    u32 m_upBounds;  // 0x120 [R/W] (BuildDigests, ChangeShader, ChangeShaderState, ...)
    u32 m_field_124;  // 0x124 [R/W] (Clone, Draw, EIStaticModel)
    u8 _pad_128[0x38];  // 0x128
    s16 m_field_160;  // 0x160 [R] (Draw)
    u8 _pad_162[2];  // 0x162
    u32 m_field_164;  // 0x164 [R] (Draw)
    u8 _pad_168[0x1B0];  // 0x168
    u32 m_field_318;  // 0x318 [R/W] (BuildDigests, Clone, Draw, ...)
};

#endif // EISTATICMODEL_H
