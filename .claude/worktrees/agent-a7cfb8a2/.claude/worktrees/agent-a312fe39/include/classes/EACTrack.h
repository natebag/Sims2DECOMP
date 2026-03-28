#ifndef EACTRACK_H
#define EACTRACK_H

#include "types.h"

// EACTrack - struct layout extracted from assembly analysis
// Estimated minimum size: 0xB0 (176 bytes)
// 41 known fields (0 named), 5 methods

class EACTrack {
public:
    // Constructors / Destructors
    EACTrack(void)  // 0x807A4BB8
    ~EACTrack(void);  // 0x80148DCC

    // Methods
    void operator=(EACTrack &);  // 0x807B39D8 (468B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [W] (EACTrack)
    f32 m_field_004;  // 0x004 [W] (EACTrack)
    u32 m_field_008;  // 0x008 [W] (EACTrack)
    u8 m_field_00C;  // 0x00C [W] (EACTrack)
    u8 m_field_00D;  // 0x00D [W] (EACTrack)
    u8 m_field_00E;  // 0x00E [W] (EACTrack)
    u8 _pad_00F[1];  // 0x00F
    f32 m_field_010;  // 0x010 [W] (EACTrack)
    f32 m_field_014;  // 0x014 [W] (EACTrack)
    f32 m_field_018;  // 0x018 [W] (EACTrack)
    f32 m_field_01C;  // 0x01C [W] (EACTrack)
    f32 m_field_020;  // 0x020 [W] (EACTrack)
    u32 m_field_024;  // 0x024 [W] (EACTrack, operator=)
    u32 m_field_028;  // 0x028 [W] (EACTrack, operator=)
    u32 m_field_02C;  // 0x02C [W] (operator=)
    u32 m_field_030;  // 0x030 [W] (EACTrack, operator=)
    u32 m_field_034;  // 0x034 [W] (operator=)
    u32 m_field_038;  // 0x038 [W] (operator=)
    f32 m_field_03C;  // 0x03C [W] (EACTrack, operator=)
    f32 m_field_040;  // 0x040 [W] (EACTrack, operator=)
    f32 m_field_044;  // 0x044 [W] (operator=)
    f32 m_field_048;  // 0x048 [W] (operator=)
    f32 m_field_04C;  // 0x04C [W] (EACTrack, operator=)
    f32 m_field_050;  // 0x050 [W] (EACTrack, operator=)
    f32 m_field_054;  // 0x054 [W] (operator=)
    f32 m_field_058;  // 0x058 [W] (operator=)
    f32 m_field_05C;  // 0x05C [W] (EACTrack, operator=)
    f32 m_field_060;  // 0x060 [W] (operator=)
    f32 m_field_064;  // 0x064 [W] (operator=)
    f32 m_field_068;  // 0x068 [W] (operator=)
    f32 m_field_06C;  // 0x06C [W] (operator=)
    f32 m_field_070;  // 0x070 [W] (operator=)
    u32 m_field_074;  // 0x074 [W] (EACTrack, operator=)
    f32 m_field_078;  // 0x078 [W] (EACTrack, operator=)
    u32 m_field_07C;  // 0x07C [R/W] (EACTrack, operator=)
    u32 m_field_080;  // 0x080 [W] (operator=)
    u8 _pad_084[0x14];  // 0x084
    u32 m_field_098;  // 0x098 [W] (EACTrack, operator=)
    u32 m_field_09C;  // 0x09C [W] (EACTrack, operator=)
    u8 m_field_0A0;  // 0x0A0 [W] (EACTrack, operator=)
    u8 _pad_0A1[3];  // 0x0A1
    u32 m_field_0A4;  // 0x0A4 [W] (operator=)
    u32 m_field_0A8;  // 0x0A8 [W] (EACTrack, operator=)
    u32 m_field_0AC;  // 0x0AC [W] (EACTrack, operator=)
};

#endif // EACTRACK_H
