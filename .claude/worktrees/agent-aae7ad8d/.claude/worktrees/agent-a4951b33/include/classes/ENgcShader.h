#ifndef ENGCSHADER_H
#define ENGCSHADER_H

#include "types.h"

// ENgcShader - struct layout extracted from assembly analysis
// Estimated minimum size: 0xF4 (244 bytes)
// 16 known fields (0 named), 12 methods

class ENgcShader {
public:
    // Constructors / Destructors
    ENgcShader(void)  // 0x808DD0CC
    ~ENgcShader(void);  // 0x808DD118

    // Methods
    void Select(ERC *, unsigned int);  // 0x808DD17C (240B)
    void SelectForShadowMask(ERC *);  // 0x808DD26C (356B)
    void Create(EShaderDef &);  // 0x808DD3D0 (492B)
    void ChangeMaterial(EMaterial &);  // 0x808DD5BC (72B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R/W] (Create, Select)
    u8 _pad_001[3];  // 0x001
    u32 m_field_004;  // 0x004 [W] (Create)
    u32 m_field_008;  // 0x008 [R/W] (Create)
    u32 m_field_00C;  // 0x00C [W] (Create)
    u32 m_field_010;  // 0x010 [W] (Create)
    u32 m_field_014;  // 0x014 [W] (Create)
    u8 _pad_018[0x58];  // 0x018
    u32 m_field_070;  // 0x070 [R] (Create)
    u8 _pad_074[0xC];  // 0x074
    u8 m_field_080;  // 0x080 [R] (Create)
    u8 m_field_081;  // 0x081 [R] (Create)
    u8 m_field_082;  // 0x082 [R] (Create)
    u8 m_field_083;  // 0x083 [R] (Create)
    u8 _pad_084[0x3C];  // 0x084
    u8 m_field_0C0;  // 0x0C0 [R] (Create)
    u8 m_field_0C1;  // 0x0C1 [R] (Create)
    u8 m_field_0C2;  // 0x0C2 [R] (Create)
    u8 m_field_0C3;  // 0x0C3 [R] (Create)
    u8 _pad_0C4[0x2C];  // 0x0C4
    u32 m_field_0F0;  // 0x0F0 [W] (~ENgcShader)
};

#endif // ENGCSHADER_H
