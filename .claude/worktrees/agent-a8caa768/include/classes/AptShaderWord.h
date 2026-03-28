#ifndef APTSHADERWORD_H
#define APTSHADERWORD_H

#include "types.h"

// AptShaderWord - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1A8 (424 bytes)
// 16 known fields (4 named), 12 methods

class AptShaderWord {
public:
    // Constructors / Destructors
    AptShaderWord(void)  // 0x80022BE4
    ~AptShaderWord(void);  // 0x80022C3C

    // Methods
    void Draw(ERC *, EMat4 *, EVec4 *, EVec4 *);  // 0x8001DBA4 (1216B)
    void Resize(float);  // 0x8001E064 (284B)
    void SetShader(int);  // 0x8001E180 (184B)
    void InsertSpace(void);  // 0x8001E238 (272B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R] (Draw)
    f32 m_field_004;  // 0x004 [R/W] (Draw)
    f32 m_field_008;  // 0x008 [R/W] (Draw, ~AptShaderWord)
    f32 m_field_00C;  // 0x00C [R/W] (Draw, InsertSpace, Resize, ...)
    u32 m_field_010;  // 0x010 [R/W] (Draw, InsertSpace, ~AptShaderWord)
    u32 m_field_014;  // 0x014 [R] (Draw)
    u8 _pad_018[4];  // 0x018
    f32 m_field_01C;  // 0x01C [R] (Draw)
    f32 m_field_020;  // 0x020 [R] (Draw)
    f32 m_shader;  // 0x024 [R/W] (Draw, InsertSpace, Resize, ...)
    f32 m_shader_028;  // 0x028 [R/W] (Draw, Resize, SetShader)
    u32 m_field_02C;  // 0x02C [W] (~AptShaderWord)
    f32 m_shader_030;  // 0x030 [R/W] (Draw, InsertSpace, Resize, ...)
    f32 m_shader_034;  // 0x034 [R/W] (Draw, Resize, SetShader)
    u8 _pad_038[0xB8];  // 0x038
    u32 m_field_0F0;  // 0x0F0 [R] (Draw)
    u8 _pad_0F4[0xAC];  // 0x0F4
    s16 m_field_1A0;  // 0x1A0 [R] (Draw)
    u8 _pad_1A2[2];  // 0x1A2
    u32 m_field_1A4;  // 0x1A4 [R] (Draw)
};

#endif // APTSHADERWORD_H
