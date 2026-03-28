#ifndef ESUBMODEL_H
#define ESUBMODEL_H

#include "types.h"

// ESubModel - struct layout extracted from assembly analysis
// Estimated minimum size: 0xF4 (244 bytes)
// 4 known fields (3 named), 60 methods

class ESubModel {
public:
    // Constructors / Destructors
    ESubModel(void)  // 0x807DA460
    ~ESubModel(void);  // 0x807DA4A8

    // Methods
    void Draw(ERC *);  // 0x807DA910 (132B)
    void DrawWireFrame(ERC *);  // 0x807DAB20 (132B)
    void DelRefSubResources(void);  // 0x807DA50C (124B)
    void AddRefSubResources(void);  // 0x807DA588 (124B)
    void TryIncrementSubResources(void);  // 0x807DA604 (220B)
    /* ? */ GetCompositeShaderFlags(void);  // 0x807DA6E0 (52B)
    void Read(unsigned char *, int);  // 0x807DA7A8 (360B)
    void DrawGeometry(ERC *);  // 0x807DA994 (132B)
    void DrawAsShadow(ERC *);  // 0x807DAA18 (132B)
    void DrawNormals(ERC *);  // 0x807DAA9C (132B)
    void BuildDisplayList(bool, char *, bool, float, float);  // 0x807DABA4 (164B)
    void BuildDisplayList(ESMBuildDisplayListData *);  // 0x807DAC48 (132B)
    /* ? */ GetMinMaxX(float *, float *);  // 0x807DACCC (140B)
    void ApplyMorph(void);  // 0x807DAD58 (132B)
    void ResetMorph(void);  // 0x807DADDC (124B)
    void Morph(float *);  // 0x807DAE58 (160B)
    void LatticeDeform(void);  // 0x807DAEF8 (124B)
    void RegisterMorphTarget(ESubModel *, int);  // 0x807DAF74 (300B)
    void UnRegisterMorphTarget(int);  // 0x807DB0A0 (132B)
    void GenerateMorphTargetDeltas(ESubModel *);  // 0x807DB124 (200B)
    void ParameterizeVerts(TArray<BSplineVolume, TArrayERModelAllocator> *);  // 0x807DB1EC (132B)
    void FreeMorphResource(void);  // 0x807DB270 (124B)
    void FreeStripResource(void);  // 0x807DB2EC (124B)
    void FreeMorphStripResource(void);  // 0x807DB368 (124B)
    bool HasModifiableColor(void);  // 0x807DB3E4 (152B)
    /* ? */ GetModifiableColor(unsigned int);  // 0x807DB47C (368B)
    void TransformModelUV(EVec2 &, EVec2 &, unsigned int, EVec2 &, EVec2 &, bool);  // 0x807DB5EC (172B)
    void SetParent(ERModel *);  // 0x80862F70 (40B)
    void operator=(ESubModel &);  // 0x80861304 (100B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_minMaxX;  // 0x000 [R] (AddRefSubResources, ApplyMorph, BuildDisplayList, ...)
    u32 m_minMaxX_004;  // 0x004 [R] (AddRefSubResources, ApplyMorph, BuildDisplayList, ...)
    u8 _pad_008[0xC];  // 0x008
    u32 m_field_014;  // 0x014 [R/W] (Read, ~ESubModel)
    u8 _pad_018[0xD8];  // 0x018
    u32 m_asShadow;  // 0x0F0 [R] (Draw, DrawAsShadow)
};

#endif // ESUBMODEL_H
