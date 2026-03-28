#ifndef ERMODEL_H
#define ERMODEL_H

#include "types.h"

// ERModel - struct layout extracted from assembly analysis
// Estimated minimum size: 0x294 (660 bytes)
// 39 known fields (16 named), 170 methods

class ERModel {
public:
    // Constructors / Destructors
    ERModel(void)  // 0x8085796C
    ~ERModel(void);  // 0x80857B64

    // Methods
    void DrawGeometry(ERC *);  // 0x80858A58 (140B)
    void Draw(ERC *);  // 0x80858D60 (140B)
    /* ? */ GetLightPos(void);  // 0x80863854 (44B)
    /* ? */ GetNumLightPos(void);  // 0x80863828 (44B)
    void CalcOrientedBoundBox(EMat4 &, EBound3 &);  // 0x80863374 (76B)
    /* ? */ GetNumMorphBases(void);  // 0x8085BA50 (72B)
    /* ? */ GetNumMorphLattice(int);  // 0x8085B964 (236B)
    void SetLatticeWeight(int, int, float);  // 0x8085B7A8 (244B)
    void DrawAsShadow(ERC *);  // 0x80858AE4 (140B)
    void CleanMorphTargets(bool);  // 0x8085B5D0 (124B)
    void FreeAllMorphAndLatticeResource(bool);  // 0x8085B64C (84B)
    void WeldSharedVerts(ERModel *, float);  // 0x80859A3C (4528B)
    void RebuildAfterWelding(void);  // 0x8085ABEC (32B)
    void ResetMorph(void);  // 0x8085B2F8 (144B)
    void MorphLattices(void);  // 0x8085B454 (228B)
    void MorphTargets(void);  // 0x8085B388 (204B)
    void ApplyMorph(void);  // 0x8085B538 (152B)
    void RegisterMorphTarget(int, int);  // 0x8085AF28 (172B)
    void GenerateMorphTargetDeltas(ERModel *);  // 0x8085AC0C (228B)
    void SetMorphTargetWeight(int, float);  // 0x8085B264 (148B)
    void UnRegisterMorphTarget(ERModel *);  // 0x8085B1AC (184B)
    void TransformModelUV(EVec2 &, EVec2 &, unsigned int, EVec2 &, EVec2 &);  // 0x8085C8D8 (212B)
    bool HasModifiableColor(void);  // 0x8085BBA8 (160B)
    void AreMatsInDLs(void);  // 0x808636C8 (44B)
    /* ? */ GetScaleMatrix(void);  // 0x8085887C (240B)
    /* ? */ GetDummy(int);  // 0x808634C4 (80B)
    void DrawShadowWithStencilInverted(ERC *);  // 0x808590A4 (684B)
    /* ? */ GetModifiableColor(unsigned int);  // 0x8085BC48 (380B)
    bool IsHierarchical(void);  // 0x80863618 (44B)
    /* ? */ GetShaderCount(void);  // 0x808587D4 (168B)
    void DontFrontPlaneFade(void);  // 0x808636F4 (44B)
    void DontInterestFade(void);  // 0x80863720 (44B)
    void DontCull(void);  // 0x8086374C (44B)
    void CalcOrientedBoundSphere(EMat4 &, EBoundSphere &);  // 0x808589C0 (152B)
    void DrawHierarchical(ERC *, EMat4 *, EACNodeState *, int);  // 0x80859350 (1184B)
    void DeallocateScaleMatrix(void);  // 0x8085896C (84B)
    void Refresh(EFile *);  // 0x80857C6C (76B)
    void LoadModel(EFile *);  // 0x80857FB4 (1544B)
    void DelRefSubResources(void);  // 0x80857CB8 (132B)
    void AddRefSubResources(void);  // 0x80857D3C (132B)
    void TryIncrementSubResources(void);  // 0x80857DC0 (232B)
    void ReadAttachmentVert(char *);  // 0x80857EA8 (268B)
    void FinishLoad(char);  // 0x808585BC (536B)
    void ParameterizeVerts(void);  // 0x8085BA98 (140B)
    void DrawNormals(ERC *);  // 0x80858B70 (140B)
    void DrawWireFrame(ERC *);  // 0x80858BFC (140B)
    /* ? */ GetLatticeCount(void);  // 0x80858C88 (72B)
    /* ? */ GetDummyCount(void);  // 0x80858CD0 (72B)
    /* ? */ GetCameraCount(void);  // 0x80858D18 (72B)
    void DrawShadow(ERC *, float);  // 0x80858DEC (696B)
    /* ? */ GetWeldPos(EWeldVert *);  // 0x808597F0 (292B)
    void SetWeldPos(EWeldVert *, EVec3 &);  // 0x80859914 (296B)
    bool IsWeldable(void);  // 0x80863644 (44B)
    void RegisterMorphTarget(ERModel *, int);  // 0x8085ACF0 (568B)
    void UnRegisterMorphTarget(int);  // 0x8085AFD4 (472B)
    void FreeMorphResource(void);  // 0x8085BB24 (132B)
    void FreeStripResource(void);  // 0x8085B6A0 (132B)
    void FreeMorphStripResource(void);  // 0x8085B724 (132B)
    void ResetLatticeWeights(void);  // 0x8085B89C (200B)
    /* ? */ GetAttachmentID(unsigned char, signed char &);  // 0x8085BDC4 (160B)
    void DrawAttachment(ERC *, ERModel *, EMat4 *, int, float);  // 0x8085BE64 (176B)
    /* ? */ GetAttachmentMatrix(EMat4 &, ERModel *, EMat4 *, int, float);  // 0x8085BF14 (284B)
    /* ? */ GetAttachmentMatrix(EMat4 &, unsigned char, EMat4 *, int, float, float);  // 0x8085C030 (2216B)
    void SafeDelete(void);  // 0x8086306C (108B)
    /* ? */ GetTypeInfo(void);  // 0x808630D8 (44B)
    /* ? */ GetTypeName(void);  // 0x80863104 (52B)
    /* ? */ GetTypeKey(void);  // 0x80863138 (52B)
    /* ? */ GetTypeVersion(void);  // 0x8086316C (56B)
    void RegisterType(unsigned short);  // 0x80863200 (116B)
    void New(void);  // 0x80862F98 (76B)
    void Construct(ERModel *);  // 0x80862FE4 (76B)
    void Destruct(ERModel *);  // 0x80863030 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x808631A4 (40B)
    /* ? */ GetReadVersion(void);  // 0x808631CC (52B)
    void CreateCopy(void);  // 0x80863274 (68B)
    /* ? */ GetLattice(int);  // 0x808633C0 (80B)
    /* ? */ GetCamera(int);  // 0x808635C8 (80B)
    bool IsMorphTarget(void);  // 0x80863670 (44B)
    bool IsLattice(void);  // 0x8086369C (44B)
    bool IsWall(void);  // 0x80863778 (44B)
    /* ? */ GetAttachmentColor(void);  // 0x808637A4 (48B)
    void ClearAttachmentID(void);  // 0x808637D4 (40B)
    /* ? */ GetNumAttachmentVerts(void);  // 0x808637FC (44B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_weldPos;  // 0x000 [W] (ERModel, GetWeldPos, WeldSharedVerts, ...)
    f32 m_weldPos_004;  // 0x004 [R/W] (DrawShadow, DrawShadowWithStencilInverted, GetWeldPos, ...)
    f32 m_weldPos_008;  // 0x008 [W] (GetWeldPos, WeldSharedVerts)
    s16 m_field_00C;  // 0x00C [R] (DrawHierarchical, UnRegisterMorphTarget, WeldSharedVerts)
    u8 _pad_00E[2];  // 0x00E
    u32 m_field_010;  // 0x010 [R/W] (LoadModel)
    u32 m_field_014;  // 0x014 [W] (FinishLoad)
    u32 m_weldPos_018;  // 0x018 [R/W] (LoadModel, SetWeldPos)
    u32 m_hierarchical;  // 0x01C [R/W] (DrawHierarchical, LoadModel)
    u32 m_field_020;  // 0x020 [R/W] (FinishLoad, TransformModelUV, WeldSharedVerts)
    u32 m_field_024;  // 0x024 [W] (FinishLoad)
    u32 m_field_028;  // 0x028 [W] (FinishLoad)
    u32 m_field_02C;  // 0x02C [W] (FinishLoad)
    u32 m_field_030;  // 0x030 [W] (FinishLoad)
    u32 m_field_034;  // 0x034 [R/W] (FinishLoad)
    u32 m_field_038;  // 0x038 [R/W] (FinishLoad)
    u32 m_modifiableColor;  // 0x03C [R] (AddRefSubResources, ApplyMorph, DelRefSubResources, ...)
    u32 m_attachmentMatrix;  // 0x040 [R] (GetAttachmentMatrix)
    u8 _pad_044[4];  // 0x044
    f32 m_field_048;  // 0x048 [R/W] (CalcOrientedBoundSphere, ERModel)
    u8 _pad_04C[8];  // 0x04C
    f32 m_field_054;  // 0x054 [R] (CalcOrientedBoundSphere)
    u32 m_field_058;  // 0x058 [W] (ERModel)
    u8 _pad_05C[8];  // 0x05C
    u32 m_field_064;  // 0x064 [R/W] (ERModel)
    u8 _pad_068[8];  // 0x068
    u32 m_field_070;  // 0x070 [W] (ERModel)
    u8 _pad_074[8];  // 0x074
    u32 m_field_07C;  // 0x07C [R/W] (ERModel)
    u8 _pad_080[8];  // 0x080
    f32 m_scaleMatrix;  // 0x088 [R/W] (ERModel, GetAttachmentMatrix, GetScaleMatrix)
    u32 m_field_08C;  // 0x08C [R/W] (DrawHierarchical, ERModel, LoadModel)
    u8 _pad_090[0x60];  // 0x090
    u32 m_shadow;  // 0x0F0 [R] (DrawShadow, DrawShadowWithStencilInverted)
    u8 _pad_0F4[8];  // 0x0F4
    u32 m_latticeWeight;  // 0x0FC [R/W] (ApplyMorph, CleanMorphTargets, ERModel, ...)
    u32 m_field_100;  // 0x100 [W] (ERModel, FinishLoad)
    u32 m_latticeWeight_104;  // 0x104 [R] (MorphLattices, ResetLatticeWeights, SetLatticeWeight)
    u8 _pad_108[0x2C];  // 0x108
    u8 m_field_134;  // 0x134 [W] (ERModel, ~ERModel)
    u8 m_field_135;  // 0x135 [W] (ERModel, ~ERModel)
    u8 _pad_136[2];  // 0x136
    u32 m_attachmentMatrix_138;  // 0x138 [R/W] (ERModel, GetAttachmentID, GetAttachmentMatrix, ...)
    u8 m_attachmentMatrix_13B;  // 0x13B [R] (GetAttachmentMatrix)
    u32 m_attachmentMatrix_13C;  // 0x13C [R/W] (ERModel, GetAttachmentID, GetAttachmentMatrix, ...)
    u32 m_field_140;  // 0x140 [W] (ERModel)
    u8 _pad_144[0x30];  // 0x144
    u32 m_scaleMatrix_174;  // 0x174 [R/W] (DeallocateScaleMatrix, ERModel, GetScaleMatrix)
    u8 m_field_178;  // 0x178 [R/W] (ERModel, LoadModel)
    u8 _pad_179[3];  // 0x179
    u32 m_field_17C;  // 0x17C [R/W] (ERModel, TransformModelUV)
    u8 _pad_180[0x110];  // 0x180
    u32 m_hierarchical_290;  // 0x290 [R] (DrawHierarchical)
};

#endif // ERMODEL_H
