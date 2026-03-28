#ifndef ENGCTEXTUREC8_32_H
#define ENGCTEXTUREC8_32_H

#include "types.h"

// ENgcTextureC8_32 - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD8 (216 bytes)
// 18 known fields (3 named), 20 methods

class ENgcTextureC8_32 {
public:
    // Constructors / Destructors
    ENgcTextureC8_32(void)  // 0x808E2B3C
    ~ENgcTextureC8_32(void);  // 0x808E2BAC

    // Methods
    void Create(ETextureDef &);  // 0x808E2C64 (252B)
    void SwizzleImage(unsigned char *, int, int, unsigned char *);  // 0x808E2D60 (84B)
    void UnswizzleImage(unsigned char *, int, int, unsigned char *);  // 0x808E2DB4 (84B)
    void UpdatePaletteDeswizzled(void);  // 0x808E2E08 (536B)
    void UpdateEnd(void);  // 0x808E3020 (488B)
    void Select(int, int);  // 0x808E3208 (776B)
    /* ? */ GetTEVStageCount(void);  // 0x808E3510 (40B)
    /* ? */ GetTEXCount(void);  // 0x808E3538 (40B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Create, Select, UpdateEnd, ...)
    u8 _pad_00C[4];  // 0x00C
    u16 m_field_010;  // 0x010 [R] (Select)
    u16 m_field_012;  // 0x012 [R] (Select)
    u16 m_end;  // 0x014 [R] (Select, UpdateEnd, UpdatePaletteDeswizzled)
    u16 m_field_016;  // 0x016 [R] (Select)
    u8 _pad_018[0xC];  // 0x018
    u32 m_field_024;  // 0x024 [W] (ENgcTextureC8_32, ~ENgcTextureC8_32)
    u8 _pad_028[0x40];  // 0x028
    u32 m_field_068;  // 0x068 [R] (Select)
    u32 m_field_06C;  // 0x06C [R] (Select)
    u32 m_field_070;  // 0x070 [R] (Select)
    u32 m_field_074;  // 0x074 [R] (Select)
    u8 _pad_078[8];  // 0x078
    u32 m_field_080;  // 0x080 [R/W] (Select)
    u8 _pad_084[0xC];  // 0x084
    u32 m_end_090;  // 0x090 [R] (Create, UpdateEnd)
    u32 m_field_094;  // 0x094 [R/W] (Select)
    u32 m_end_098;  // 0x098 [R] (UpdateEnd)
    u8 _pad_09C[0x2C];  // 0x09C
    u32 m_field_0C8;  // 0x0C8 [R/W] (Select)
    u32 m_field_0CC;  // 0x0CC [R/W] (Create, ENgcTextureC8_32, Select, ...)
    u32 m_field_0D0;  // 0x0D0 [R/W] (Create, ENgcTextureC8_32, Select, ...)
    u32 m_field_0D4;  // 0x0D4 [R/W] (ENgcTextureC8_32, UpdateEnd, UpdatePaletteDeswizzled, ...)
};

#endif // ENGCTEXTUREC8_32_H
