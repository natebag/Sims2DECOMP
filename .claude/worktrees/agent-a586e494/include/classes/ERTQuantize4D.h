#ifndef ERTQUANTIZE4D_H
#define ERTQUANTIZE4D_H

#include "types.h"

// ERTQuantize4D - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20FC (8444 bytes)
// 40 known fields (10 named), 62 methods

class ERTQuantize4D {
public:
    // Constructors / Destructors
    ERTQuantize4D(void)  // 0x80901C4C
    ~ERTQuantize4D(void);  // 0x80901D18

    // Methods
    void Init(unsigned int, unsigned int, void *(*);  // 0x80901DDC (1756B)
    void AddPixel(unsigned char *);  // 0x8090291C (412B)
    void Compute(void);  // 0x80903990 (308B)
    /* ? */ GetPaletteSize(void);  // 0x80903E28 (156B)
    /* ? */ GetPaletteEntry(int, unsigned char *);  // 0x80903EC4 (308B)
    /* ? */ GetClosestColor(unsigned char *);  // 0x80903FF8 (924B)
    void Deallocate(void);  // 0x80901D78 (100B)
    void DefaultAlloc(unsigned int);  // 0x809024B8 (84B)
    void DefaultFree(void *);  // 0x8090250C (68B)
    void InitializeCube(void);  // 0x809025E8 (340B)
    void TextureAlloc(unsigned int);  // 0x80902550 (84B)
    void TextureFree(void *);  // 0x809025A4 (68B)
    void InitializeNode(unsigned char, unsigned int, ERTQ4Node *, EVec4 &);  // 0x8090273C (480B)
    void NodeToIndex(ERTQ4Node *);  // 0x80904EE4 (236B)
    void AllocNode(void);  // 0x80904D68 (116B)
    void IndexToNode(unsigned short);  // 0x80904E2C (184B)
    void EVecToFVec(EVec4 &, unsigned short *);  // 0x80904FD0 (888B)
    void FlushAdd(ERTQ4CacheNode &);  // 0x80902AB8 (184B)
    void TransformToYuva(unsigned char *, EVec4 &);  // 0x80902B70 (672B)
    void Classify(EVec4 &, int);  // 0x809031B8 (1324B)
    void TransformFromYUVA(EVec4 &, unsigned char *);  // 0x80902E10 (936B)
    void PruneLevel(ERTQ4Node *);  // 0x809036E4 (236B)
    void FVecToEVec(unsigned short *, EVec4 &);  // 0x80905348 (1016B)
    void PruneChild(ERTQ4Node *);  // 0x809037D0 (448B)
    void FreeNode(unsigned short);  // 0x80904DDC (80B)
    void Reduction(void);  // 0x80903AC4 (156B)
    void MColormap(ERTQ4Node *);  // 0x80903C98 (400B)
    void Reduce(ERTQ4Node *);  // 0x80903B60 (312B)
    void ClosestColor(ERTQ4Node *);  // 0x80904394 (332B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Init, ~ERTQuantize4D)
    u16 m_field_002;  // 0x002 [W] (InitializeNode)
    u16 m_closestColor;  // 0x004 [R/W] (GetClosestColor, InitializeNode)
    u16 m_closestColor_006;  // 0x006 [R/W] (GetClosestColor, InitializeNode)
    u8 _pad_008[8];  // 0x008
    u32 m_field_010;  // 0x010 [R/W] (Classify, InitializeCube)
    u32 m_field_014;  // 0x014 [R/W] (Classify)
    u16 m_field_018;  // 0x018 [W] (InitializeCube)
    u8 _pad_01A[0x20];  // 0x01A
    u16 m_field_03A;  // 0x03A [R/W] (Classify)
    u16 m_field_03C;  // 0x03C [R] (Classify)
    u16 m_field_03E;  // 0x03E [R] (Classify)
    u16 m_field_040;  // 0x040 [R] (Classify)
    u16 m_field_042;  // 0x042 [R] (Classify)
    u8 _pad_044[0xFB8];  // 0x044
    u32 m_field_FFC;  // 0xFFC [R/W] (Init)
    u32 m_field_1000;  // 0x1000 [R/W] (Deallocate, Init)
    u16 m_closestColor_1004;  // 0x1004 [R/W] (Classify, Compute, GetClosestColor, ...)
    u16 m_field_1006;  // 0x1006 [R/W] (Deallocate, Init, InitializeNode, ...)
    u32 m_closestColor_1008;  // 0x1008 [R/W] (Classify, ClosestColor, Compute, ...)
    u32 m_field_100C;  // 0x100C [W] (Compute, Init)
    u32 m_field_1010;  // 0x1010 [R/W] (Classify, Init, InitializeNode, ...)
    u32 m_field_1014;  // 0x1014 [R/W] (Init, Reduction)
    u32 m_field_1018;  // 0x1018 [R/W] (Classify, Init)
    u32 m_field_101C;  // 0x101C [R/W] (Classify, InitializeCube, PruneLevel)
    u8 _pad_1020[4];  // 0x1020
    u32 m_closestColor_1024;  // 0x1024 [R/W] (Classify, Compute, GetClosestColor, ...)
    u32 m_field_1028;  // 0x1028 [R/W] (Reduce, Reduction)
    u32 m_field_102C;  // 0x102C [R/W] (Reduce, Reduction)
    u8 _pad_1030[0x2C];  // 0x1030
    u32 m_closestColor_105C;  // 0x105C [R/W] (ClosestColor, GetClosestColor)
    f32 m_closestColor_1060;  // 0x1060 [R] (GetClosestColor)
    u8 _pad_1064[0xFFC];  // 0x1064
    f32 m_closestColor_2060;  // 0x2060 [R/W] (ClosestColor, GetClosestColor)
    u8 _pad_2064[0xC];  // 0x2064
    f32 m_closestColor_2070;  // 0x2070 [R/W] (ClosestColor, GetClosestColor)
    u8 _pad_2074[4];  // 0x2074
    f32 m_field_2078;  // 0x2078 [R/W] (Init, TransformToYuva)
    f32 m_field_207C;  // 0x207C [W] (Init)
    f32 m_field_2080;  // 0x2080 [W] (Init)
    u8 _pad_2084[4];  // 0x2084
    f32 m_field_2088;  // 0x2088 [W] (Init)
    f32 m_field_208C;  // 0x208C [W] (Init)
    f32 m_field_2090;  // 0x2090 [W] (Init)
    u8 _pad_2094[4];  // 0x2094
    f32 m_field_2098;  // 0x2098 [W] (Init)
    f32 m_field_209C;  // 0x209C [W] (Init)
    f32 m_field_20A0;  // 0x20A0 [W] (Init)
    u8 _pad_20A4[0x14];  // 0x20A4
    f32 m_field_20B8;  // 0x20B8 [R] (TransformFromYUVA)
    u8 _pad_20BC[0x3C];  // 0x20BC
    u32 m_field_20F8;  // 0x20F8 [R/W] (Init, TransformFromYUVA, TransformToYuva)
};

#endif // ERTQUANTIZE4D_H
