#ifndef ENGCTEXTURE_H
#define ENGCTEXTURE_H

#include "types.h"

// ENgcTexture - struct layout extracted from assembly analysis
// Estimated minimum size: 0x2C (44 bytes)
// 5 known fields (2 named), 40 methods

class ENgcTexture {
public:
    // Constructors / Destructors
    ENgcTexture(void)  // 0x808DFF70
    ~ENgcTexture(void);  // 0x808DFFC4

    // Methods
    /* ? */ GetTEVStageCount(void);  // 0x808E0A30 (120B)
    /* ? */ GetTEXCount(void);  // 0x808E0AA8 (120B)
    void FlushImageMemoryRange(bool);  // 0x808E09E8 (72B)
    /* ? */ GetGXTexFmt(void);  // 0x808E09B0 (56B)
    void CloneSwizzled(void);  // 0x808E0084 (612B)
    void Lock(void);  // 0x808E02E8 (112B)
    void Unlock(void);  // 0x808E0358 (100B)
    void Invalidate(void);  // 0x808E03BC (100B)
    void UpdateBegin(ETextureUpdateType);  // 0x808E0420 (120B)
    void UpdateMipLevel(int, int &, int &);  // 0x808E0498 (136B)
    void UpdatePalette(void);  // 0x808E0520 (112B)
    void UpdatePaletteDeswizzled(void);  // 0x808E0590 (112B)
    void UpdateEnd(void);  // 0x808E0600 (100B)
    void Create(ETextureDef &);  // 0x808E0664 (720B)
    void Select(int, int);  // 0x808E0934 (124B)
    void ClearTileFlags(void);  // 0x808E0B20 (116B)
    void ClearSwizzleFlag(void);  // 0x808E0B94 (116B)
    void SetSwizzleFlag(void);  // 0x808E0C08 (116B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_swizzleFlag;  // 0x008 [R/W] (ClearSwizzleFlag, ClearTileFlags, SetSwizzleFlag)
    u8 _pad_00C[8];  // 0x00C
    u16 m_field_014;  // 0x014 [R] (CloneSwizzled)
    u8 _pad_016[5];  // 0x016
    u8 m_field_01B;  // 0x01B [R] (CloneSwizzled)
    u8 _pad_01C[8];  // 0x01C
    u32 m_field_024;  // 0x024 [R/W] (CloneSwizzled, ENgcTexture, ~ENgcTexture)
    u32 m_swizzleFlag_028;  // 0x028 [R/W] (ClearSwizzleFlag, ClearTileFlags, CloneSwizzled, ...)
};

#endif // ENGCTEXTURE_H
