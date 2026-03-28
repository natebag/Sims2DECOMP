#ifndef ESUBMODELSHADER_H
#define ESUBMODELSHADER_H

#include "types.h"

// ESubModelShader - struct layout extracted from assembly analysis
// Estimated minimum size: 0x74 (116 bytes)
// 17 known fields (5 named), 96 methods

class ESubModelShader {
public:
    // Constructors / Destructors
    ESubModelShader(void)  // 0x807DE394
    ~ESubModelShader(void);  // 0x807DE444

    // Methods
    void DrawGeometry(ERC *);  // 0x8007E1B0 (248B)
    /* ? */ GetDisplayList(void);  // 0x806324CC (44B)
    void SetVertFromMainHeap(void);  // 0x807DDC04 (40B)
    void Draw(ERC *);  // 0x807DDE28 (264B)
    void DrawAsShadow(ERC *);  // 0x807DDD24 (260B)
    void operator=(ESubModelShader &);  // 0x807DD3E0 (268B)
    void DelRefSubResources(void);  // 0x807DE4BC (76B)
    void AddRefSubResources(void);  // 0x807DE508 (92B)
    void TryIncrementSubResources(void);  // 0x807DE564 (112B)
    void Read(unsigned char *, int);  // 0x807E06D0 (2092B)
    void DrawNormals(ERC *);  // 0x807E0EFC (44B)
    void DrawWireFrame(ERC *);  // 0x807E0F28 (44B)
    void BuildDisplayList(bool, char *, bool, float, float);  // 0x807E4734 (1932B)
    void BuildDisplayList(ESMBuildDisplayListData *);  // 0x807E3F20 (2068B)
    /* ? */ GetMinMaxX(float *, float *);  // 0x807E4EC0 (556B)
    void ApplyMorph(void);  // 0x807E14B4 (2264B)
    void ResetMorph(void);  // 0x807E1394 (288B)
    void Morph(float *);  // 0x807E2608 (1632B)
    void LatticeDeform(void);  // 0x807E38A4 (1660B)
    void RegisterMorphTarget(ESubModelShader *, int);  // 0x807E1150 (512B)
    void UnRegisterMorphTarget(int);  // 0x807E1350 (68B)
    void GenerateMorphTargetDeltas(ESubModelShader *);  // 0x807E2030 (1496B)
    void ParameterizeVerts(TArray<BSplineVolume, TArrayERModelAllocator> *);  // 0x807E3310 (1428B)
    void FreeMorphResource(void);  // 0x807DE9C4 (212B)
    void FreeStripResource(void);  // 0x807DE844 (152B)
    void FreeMorphStripResource(void);  // 0x807DE8DC (232B)
    bool CanColorBeModified(void);  // 0x807E50EC (172B)
    /* ? */ GetModifiableColor(unsigned int);  // 0x807E5198 (280B)
    void TransformModelUV(EVec2 &, EVec2 &, unsigned int, EVec2 &, EVec2 &, bool);  // 0x807E52B0 (1936B)
    void VertexDataAllocation(int, char *, int, char *);  // 0x807DE1E8 (140B)
    void VertexDataDeallocation(void *, bool);  // 0x807DE274 (132B)
    void MorphDataAllocation(int, int);  // 0x807DE2F8 (88B)
    void MorphDataDeallocation(void *);  // 0x807DE350 (68B)
    void Deallocate(void);  // 0x807DE704 (320B)
    void DeallocateStripData(ESMSStrip *);  // 0x807DE5D4 (304B)
    void CreateRCPrimitive(unsigned int, ERC *, ESMSStrip *, bool, bool, bool);  // 0x807DEA98 (836B)
    void ReadPositions(unsigned char *, ESMSStrip *, bool);  // 0x807DEDDC (660B)
    void ReadTexcoords(unsigned char *, ESMSStrip *);  // 0x807DF070 (288B)
    void ReadColors(unsigned char *, ESMSStrip *);  // 0x807DF190 (332B)
    void ReadNormalsOld(unsigned char *, ESMSStrip *);  // 0x807DF2DC (424B)
    void ReadNormals(unsigned char *, ESMSStrip *);  // 0x807DF484 (296B)
    void ReadWeights(unsigned char *, ESMSStrip *, bool);  // 0x807DF5AC (752B)
    void OptimizeStripsForMemory(ESubModelShader *, ESMSStrip *, int, bool);  // 0x807DF89C (3132B)
    void ReadIndices(unsigned char *, ESMSStrip *, unsigned int &);  // 0x807E04D8 (504B)
    void MorphBreakUpStrip(TArray<ESMSStrip, TArrayERModelAllocator> &, TArray<ESMSStrip, TArrayERModelAllocator> &);  // 0x807E0F54 (48B)
    void AllocateMorph(void);  // 0x807E0F84 (460B)
    /* ? */ GetMorphedVertex(EVec3 &, short, short);  // 0x807E1D8C (676B)
    void CreateLatticeList(TArray<BSplineVolume, TArrayERModelAllocator> *);  // 0x807E2C68 (932B)
    void AllocateParameterizeVerts(void);  // 0x807E300C (772B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ApplyMorph, BuildDisplayList, Deallocate, ...)
    u8 m_field_003;  // 0x003 [W] (ReadColors)
    f32 m_field_004;  // 0x004 [R/W] (ApplyMorph, ESubModelShader)
    u16 m_field_006;  // 0x006 [R/W] (ReadPositions)
    f32 m_field_008;  // 0x008 [R/W] (AddRefSubResources, ApplyMorph, BuildDisplayList, ...)
    u32 m_field_00C;  // 0x00C [R/W] (AddRefSubResources, AllocateParameterizeVerts, ESubModelShader, ...)
    u32 m_morphedVertex;  // 0x010 [R/W] (AllocateMorph, ApplyMorph, CreateRCPrimitive, ...)
    u32 m_minMaxX;  // 0x014 [R] (AllocateMorph, AllocateParameterizeVerts, ApplyMorph, ...)
    u32 m_field_018;  // 0x018 [R] (AllocateMorph, AllocateParameterizeVerts, BuildDisplayList, ...)
    u8 _pad_01C[4];  // 0x01C
    u32 m_field_020;  // 0x020 [R] (TransformModelUV)
    f32 m_field_024;  // 0x024 [W] (ESubModelShader)
    u32 m_field_028;  // 0x028 [R/W] (ESubModelShader, GenerateMorphTargetDeltas)
    u32 m_morphedVertex_02C;  // 0x02C [R] (AllocateMorph, ApplyMorph, FreeMorphStripResource, ...)
    u32 m_morphedVertex_030;  // 0x030 [R] (ApplyMorph, GetMorphedVertex, RegisterMorphTarget, ...)
    u8 _pad_034[0x34];  // 0x034
    u32 m_field_068;  // 0x068 [R/W] (AllocateParameterizeVerts, CreateLatticeList, ESubModelShader, ...)
    u32 m_field_06C;  // 0x06C [R/W] (AllocateParameterizeVerts, CreateLatticeList, ESubModelShader, ...)
    u32 m_field_070;  // 0x070 [R] (ApplyMorph, BuildDisplayList)
};

#endif // ESUBMODELSHADER_H
