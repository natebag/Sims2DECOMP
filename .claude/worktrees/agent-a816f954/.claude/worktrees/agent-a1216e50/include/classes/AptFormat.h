#ifndef APTFORMAT_H
#define APTFORMAT_H

#include "types.h"

// AptFormat - struct layout extracted from assembly analysis
// Estimated minimum size: 0x90 (144 bytes)
// 33 known fields (0 named), 14 methods

class AptFormat {
public:
    // Static members (from map file)
    // static ??? s_nPSystemUID;

    // Constructors / Destructors
    AptFormat(AptWord *)  // 0x8001A70C
    ~AptFormat(void);  // 0x8001A9CC

    // Methods
    void Draw(EMat4 *, EVec4 *, EVec4 *);  // 0x8001AC04 (3056B)
    void InitForParticles(AptFormat::aptFormat_PartFX);  // 0x8001B7F4 (2932B)
    void ProcessParticles(ERC *, EMat4 *, EVec2 &, EVec2 &, float, float);  // 0x8001C368 (1596B)
    void CheckAsyncLoads(void);  // 0x8001C9A4 (716B)
    void CopyForward(AptFormat *);  // 0x8001CC70 (560B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (AptFormat, CheckAsyncLoads, CopyForward, ...)
    u8 m_field_003;  // 0x003 [W] (Draw)
    f32 m_field_004;  // 0x004 [R/W] (AptFormat, CopyForward, Draw, ...)
    f32 m_field_008;  // 0x008 [R/W] (AptFormat, CopyForward, Draw, ...)
    f32 m_field_00C;  // 0x00C [R/W] (AptFormat, CopyForward, Draw, ...)
    f32 m_field_010;  // 0x010 [R/W] (AptFormat, CopyForward, Draw, ...)
    u32 m_field_014;  // 0x014 [R/W] (AptFormat, CopyForward, Draw, ...)
    u32 m_field_018;  // 0x018 [R/W] (AptFormat, CopyForward, Draw)
    f32 m_field_01C;  // 0x01C [R/W] (AptFormat, CopyForward, Draw, ...)
    u32 m_field_020;  // 0x020 [R/W] (AptFormat, Draw, ProcessParticles)
    f32 m_field_024;  // 0x024 [R/W] (AptFormat, CopyForward, Draw)
    f32 m_field_028;  // 0x028 [R/W] (AptFormat, CopyForward, Draw, ...)
    u32 m_field_02C;  // 0x02C [R/W] (AptFormat, CopyForward, Draw, ...)
    u32 m_field_030;  // 0x030 [R/W] (AptFormat, CopyForward, Draw, ...)
    f32 m_field_034;  // 0x034 [R/W] (AptFormat, CopyForward, Draw, ...)
    f32 m_field_038;  // 0x038 [R/W] (AptFormat, CopyForward, Draw)
    f32 m_field_03C;  // 0x03C [R/W] (AptFormat, CopyForward, Draw)
    u32 m_field_040;  // 0x040 [R/W] (AptFormat, CopyForward, Draw, ...)
    u32 m_field_044;  // 0x044 [R/W] (AptFormat, CopyForward, InitForParticles)
    u32 m_field_048;  // 0x048 [R/W] (AptFormat, CopyForward, InitForParticles, ...)
    u32 m_field_04C;  // 0x04C [R/W] (AptFormat, CopyForward, InitForParticles, ...)
    f32 m_field_050;  // 0x050 [R/W] (AptFormat, CheckAsyncLoads, CopyForward, ...)
    f32 m_field_054;  // 0x054 [R/W] (AptFormat, CopyForward, InitForParticles, ...)
    f32 m_field_058;  // 0x058 [R/W] (AptFormat, CopyForward, InitForParticles, ...)
    f32 m_field_05C;  // 0x05C [R/W] (AptFormat, CopyForward, InitForParticles, ...)
    u32 m_field_060;  // 0x060 [R/W] (AptFormat, CheckAsyncLoads, CopyForward, ...)
    u32 m_field_064;  // 0x064 [R/W] (AptFormat, CopyForward, Draw, ...)
    f32 m_field_068;  // 0x068 [R/W] (AptFormat, CopyForward, Draw)
    u32 m_field_06C;  // 0x06C [W] (AptFormat, CopyForward)
    u8 _pad_070[8];  // 0x070
    f32 m_field_078;  // 0x078 [W] (AptFormat, CopyForward)
    u32 m_field_07C;  // 0x07C [W] (AptFormat, CopyForward)
    u8 _pad_080[8];  // 0x080
    u32 m_field_088;  // 0x088 [R/W] (AptFormat, CheckAsyncLoads, Draw, ...)
    u32 m_field_08C;  // 0x08C [W] (AptFormat, ~AptFormat)
};

#endif // APTFORMAT_H
