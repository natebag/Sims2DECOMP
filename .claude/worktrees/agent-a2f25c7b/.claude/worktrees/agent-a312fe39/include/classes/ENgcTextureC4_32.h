#ifndef ENGCTEXTUREC4_32_H
#define ENGCTEXTUREC4_32_H

#include "types.h"

// ENgcTextureC4_32 - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD4 (212 bytes)
// 17 known fields (3 named), 16 methods

class ENgcTextureC4_32 {
public:
    // Constructors / Destructors
    ENgcTextureC4_32(void)  // 0x808E2154
    ~ENgcTextureC4_32(void);  // 0x808E21BC

    // Methods
    void Create(ETextureDef &);  // 0x808E2250 (252B)
    void SwizzleImage(unsigned char *, int, int, unsigned char *);  // 0x808E234C (84B)
    void UpdateEnd(void);  // 0x808E23A0 (360B)
    void Select(int, int);  // 0x808E2508 (776B)
    /* ? */ GetTEVStageCount(void);  // 0x808E2810 (40B)
    /* ? */ GetTEXCount(void);  // 0x808E2838 (40B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Create, Select, UpdateEnd, ...)
    u8 _pad_00C[4];  // 0x00C
    u16 m_field_010;  // 0x010 [R] (Select)
    u16 m_field_012;  // 0x012 [R] (Select)
    u16 m_end;  // 0x014 [R] (Select, UpdateEnd)
    u16 m_field_016;  // 0x016 [R] (Select)
    u8 _pad_018[0xC];  // 0x018
    u32 m_field_024;  // 0x024 [W] (ENgcTextureC4_32, ~ENgcTextureC4_32)
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
    u32 m_field_0CC;  // 0x0CC [R/W] (Create, ENgcTextureC4_32, Select, ...)
    u32 m_field_0D0;  // 0x0D0 [R/W] (Create, ENgcTextureC4_32, Select, ...)
};

#endif // ENGCTEXTUREC4_32_H
