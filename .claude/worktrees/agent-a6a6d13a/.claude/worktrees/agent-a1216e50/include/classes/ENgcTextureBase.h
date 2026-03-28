#ifndef ENGCTEXTUREBASE_H
#define ENGCTEXTUREBASE_H

#include "types.h"

// ENgcTextureBase - struct layout extracted from assembly analysis
// Estimated minimum size: 0x9C (156 bytes)
// 21 known fields (6 named), 42 methods

class ENgcTextureBase {
public:
    // Constructors / Destructors
    ENgcTextureBase(unsigned int, int, int)  // 0x808E0D38
    ~ENgcTextureBase(void);  // 0x808E0DEC

    // Methods
    void ComputeMipLevelOffset(int, int &, int &);  // 0x808E1A0C (476B)
    void FlushImageMemoryRange(bool);  // 0x808E0F8C (160B)
    void Lock(void);  // 0x808E102C (52B)
    void Unlock(void);  // 0x808E1060 (44B)
    void Invalidate(void);  // 0x808E108C (32B)
    void Create(ETextureDef &);  // 0x808E10AC (708B)
    /* ? */ GetPaletteLocation(void);  // 0x808E1370 (112B)
    void Select(int, int);  // 0x808E13E0 (556B)
    void UpdateBegin(ETextureUpdateType);  // 0x808E160C (84B)
    void UpdateMipLevel(int, int &, int &);  // 0x808E1660 (352B)
    void UpdatePalette(void);  // 0x808E17C0 (44B)
    void UpdateEnd(void);  // 0x808E17EC (544B)
    /* ? */ GetTEVStageCount(void);  // 0x808E1BE8 (40B)
    /* ? */ GetTEXCount(void);  // 0x808E1C10 (40B)
    void ClearSwizzleFlag(void);  // 0x808E1C38 (492B)
    void ClearTileFlags(void);  // 0x808E1E24 (60B)
    void UpdatePaletteDeswizzled(void);  // 0x808E1E60 (104B)
    void SetSwizzleFlag(void);  // 0x808E1EC8 (44B)
    void UnswizzleImage(unsigned char *, int, int, unsigned char *);  // 0x808E1EF4 (148B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R/W] (ClearSwizzleFlag, Create, Select, ...)
    u8 m_field_00B;  // 0x00B [R] (Select)
    u8 _pad_00C[4];  // 0x00C
    u16 m_field_010;  // 0x010 [R] (ComputeMipLevelOffset, Select)
    u16 m_field_012;  // 0x012 [R] (ComputeMipLevelOffset, Select)
    u16 m_end;  // 0x014 [R] (Create, Select, UpdateEnd)
    u16 m_field_016;  // 0x016 [R] (ClearSwizzleFlag, Create, FlushImageMemoryRange, ...)
    u8 _pad_018[2];  // 0x018
    u8 m_mipLevel;  // 0x01A [R] (ComputeMipLevelOffset, UpdateMipLevel)
    u8 m_end_01B;  // 0x01B [R] (Create, UpdateEnd)
    u8 _pad_01C[8];  // 0x01C
    u32 m_field_024;  // 0x024 [R/W] (ClearSwizzleFlag, ENgcTextureBase, UpdateEnd, ...)
    u8 _pad_028[0x1C];  // 0x028
    u32 m_field_044;  // 0x044 [W] (ENgcTextureBase)
    u8 _pad_048[0x20];  // 0x048
    u32 m_end_068;  // 0x068 [R/W] (ENgcTextureBase, Select, UpdateEnd)
    u32 m_end_06C;  // 0x06C [R/W] (ENgcTextureBase, Select, UpdateEnd)
    u32 m_field_070;  // 0x070 [R/W] (Create, ENgcTextureBase, Select)
    u32 m_field_074;  // 0x074 [R/W] (ClearSwizzleFlag, Create, ENgcTextureBase, ...)
    u32 m_field_078;  // 0x078 [R/W] (ClearSwizzleFlag, Create, ENgcTextureBase, ...)
    u8 m_field_07C;  // 0x07C [R/W] (ComputeMipLevelOffset, ENgcTextureBase)
    u8 m_field_07D;  // 0x07D [R/W] (ComputeMipLevelOffset, ENgcTextureBase)
    u8 _pad_07E[2];  // 0x07E
    u32 m_field_080;  // 0x080 [R/W] (Create, ENgcTextureBase, Select)
    u8 _pad_084[0xC];  // 0x084
    u32 m_field_090;  // 0x090 [R/W] (Create, ENgcTextureBase, Select, ...)
    u32 m_field_094;  // 0x094 [R/W] (Select)
    u32 m_mipLevel_098;  // 0x098 [R] (UpdateEnd, UpdateMipLevel)
};

#endif // ENGCTEXTUREBASE_H
