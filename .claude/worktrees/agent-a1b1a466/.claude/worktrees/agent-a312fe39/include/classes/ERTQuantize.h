#ifndef ERTQUANTIZE_H
#define ERTQUANTIZE_H

#include "types.h"

// ERTQuantize - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1CF8 (7416 bytes)
// 28 known fields (8 named), 60 methods

class ERTQuantize {
public:
    // Constructors / Destructors
    ERTQuantize(void)  // 0x807607D4
    ~ERTQuantize(void);  // 0x807608A0

    // Methods
    void Init(unsigned int, unsigned int, void *(*);  // 0x80760964 (1644B)
    void AddPixel(unsigned char *);  // 0x80761440 (388B)
    void Compute(void);  // 0x8076229C (308B)
    /* ? */ GetFullPaletteSize(void);  // 0x807627AC (156B)
    /* ? */ GetPaletteEntry(int, unsigned char *);  // 0x80762848 (368B)
    /* ? */ GetClosestColor(unsigned char *);  // 0x807629B8 (928B)
    void Deallocate(void);  // 0x80760900 (100B)
    void DefaultAlloc(unsigned int);  // 0x80760FD0 (84B)
    void DefaultFree(void *);  // 0x80761024 (68B)
    void InitializeCube(void);  // 0x80761100 (340B)
    void TextureAlloc(unsigned int);  // 0x80761068 (84B)
    void TextureFree(void *);  // 0x807610BC (68B)
    void InitializeNode(unsigned char, unsigned int, ERTQNode *, EVec3 &);  // 0x80761254 (492B)
    void NodeToIndex(ERTQNode *);  // 0x80763810 (236B)
    void AllocNode(void);  // 0x80763694 (116B)
    void IndexToNode(unsigned short);  // 0x80763758 (184B)
    void FlushAdd(ERTQCacheNode &);  // 0x807615C4 (164B)
    void TransformToYuv(unsigned char *, EVec3 &);  // 0x80761668 (608B)
    void Classify(EVec3 &, int);  // 0x80761B70 (1228B)
    void TransformFromYUV(EVec3 &, unsigned char *);  // 0x807618C8 (680B)
    void PruneLevel(ERTQNode *);  // 0x8076203C (236B)
    void PruneChild(ERTQNode *);  // 0x80762128 (372B)
    void FreeNode(unsigned short);  // 0x80763708 (80B)
    void Reduction(void);  // 0x807623D0 (156B)
    void MColormap(ERTQNode *);  // 0x807625A4 (364B)
    void Reduce(ERTQNode *);  // 0x8076246C (312B)
    /* ? */ GetPaletteSize(void);  // 0x80762710 (156B)
    void ClosestColor(ERTQNode *);  // 0x80762D58 (328B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Init, ~ERTQuantize)
    u8 _pad_004[4];  // 0x004
    f32 m_field_008;  // 0x008 [R/W] (Init, TransformToYuv)
    f32 m_field_00C;  // 0x00C [W] (Init)
    u8 _pad_010[8];  // 0x010
    f32 m_field_018;  // 0x018 [W] (Init, InitializeCube)
    f32 m_field_01C;  // 0x01C [W] (Init)
    f32 m_field_020;  // 0x020 [W] (Init, InitializeCube)
    u8 _pad_024[4];  // 0x024
    f32 m_field_028;  // 0x028 [W] (Init)
    f32 m_field_02C;  // 0x02C [W] (Init)
    f32 m_field_030;  // 0x030 [W] (Init)
    u8 _pad_034[0x14];  // 0x034
    f32 m_field_048;  // 0x048 [R] (TransformFromYUV)
    u8 _pad_04C[0x1034];  // 0x04C
    u32 m_field_1080;  // 0x1080 [R/W] (Init)
    u32 m_field_1084;  // 0x1084 [R/W] (Deallocate, Init)
    u16 m_closestColor;  // 0x1088 [R/W] (Classify, Compute, GetClosestColor, ...)
    u16 m_field_108A;  // 0x108A [R/W] (Deallocate, Init, InitializeNode, ...)
    u32 m_closestColor_108C;  // 0x108C [R/W] (Classify, ClosestColor, Compute, ...)
    u32 m_field_1090;  // 0x1090 [W] (Compute, Init)
    u32 m_field_1094;  // 0x1094 [R/W] (Classify, Init, InitializeNode, ...)
    u32 m_field_1098;  // 0x1098 [R/W] (Init, Reduction)
    u32 m_field_109C;  // 0x109C [R/W] (Classify, Init)
    u32 m_field_10A0;  // 0x10A0 [R/W] (Classify, InitializeCube, PruneLevel)
    u8 _pad_10A4[4];  // 0x10A4
    u32 m_paletteEntry;  // 0x10A8 [R/W] (Classify, Compute, GetClosestColor, ...)
    u32 m_field_10AC;  // 0x10AC [R/W] (Reduce, Reduction)
    u32 m_field_10B0;  // 0x10B0 [R/W] (Reduce, Reduction)
    u8 _pad_10B4[0x2C];  // 0x10B4
    u32 m_closestColor_10E0;  // 0x10E0 [R/W] (ClosestColor, GetClosestColor)
    f32 m_closestColor_10E4;  // 0x10E4 [R] (GetClosestColor)
    u8 _pad_10E8[0xBFC];  // 0x10E8
    f32 m_closestColor_1CE4;  // 0x1CE4 [R/W] (ClosestColor, GetClosestColor)
    u8 _pad_1CE8[8];  // 0x1CE8
    f32 m_closestColor_1CF0;  // 0x1CF0 [R/W] (ClosestColor, GetClosestColor)
    u32 m_field_1CF4;  // 0x1CF4 [R/W] (Init, TransformFromYUV, TransformToYuv)
};

#endif // ERTQUANTIZE_H
