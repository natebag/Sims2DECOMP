#ifndef TRAPEZOIDFADE_H
#define TRAPEZOIDFADE_H

#include "types.h"

// TrapezoidFade - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC8 (200 bytes)
// 35 known fields (30 named), 11 methods

class TrapezoidFade {
public:
    // Constructors / Destructors
    TrapezoidFade(void)  // 0x80825AE8
    ~TrapezoidFade(void);  // 0x80825C24

    // Methods
    void Enable(bool);  // 0x800696C0 (40B)
    void SetParms(float, float, float, float, float, float, float, float, bool, int);  // 0x8006959C (292B)
    void SetEye(EVec3 &);  // 0x800696E8 (76B)
    void SetUp(EVec3 &);  // 0x80069734 (76B)
    void SetInterest(EVec3 &);  // 0x80069780 (76B)
    void CalcAlpha(EBound3 &);  // 0x80823D58 (524B)
    void Setup(void);  // 0x80823064 (3316B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_up;  // 0x000 [R] (Setup)
    f32 m_up_004;  // 0x004 [R] (Setup)
    f32 m_up_008;  // 0x008 [R] (Setup)
    f32 m_up_00C;  // 0x00C [R] (Setup)
    u8 _pad_010[8];  // 0x010
    f32 m_up_018;  // 0x018 [R] (Setup)
    u8 _pad_01C[8];  // 0x01C
    f32 m_up_024;  // 0x024 [R/W] (CalcAlpha, Setup)
    u8 _pad_028[4];  // 0x028
    f32 m_up_02C;  // 0x02C [W] (Setup)
    f32 m_up_030;  // 0x030 [W] (Setup)
    f32 m_up_034;  // 0x034 [W] (Setup)
    f32 m_up_038;  // 0x038 [W] (Setup)
    f32 m_up_03C;  // 0x03C [W] (Setup)
    f32 m_up_040;  // 0x040 [W] (Setup)
    f32 m_up_044;  // 0x044 [W] (Setup)
    f32 m_up_048;  // 0x048 [R] (Setup)
    f32 m_up_04C;  // 0x04C [R] (Setup)
    f32 m_up_050;  // 0x050 [R] (Setup)
    f32 m_up_054;  // 0x054 [R] (CalcAlpha, Setup)
    f32 m_field_058;  // 0x058 [R] (CalcAlpha)
    f32 m_field_05C;  // 0x05C [R] (CalcAlpha)
    f32 m_field_060;  // 0x060 [R] (CalcAlpha)
    f32 m_field_064;  // 0x064 [R] (CalcAlpha)
    u32 m_up_068;  // 0x068 [R] (CalcAlpha, Setup)
    u32 m_up_06C;  // 0x06C [R] (CalcAlpha, Setup)
    u32 m_field_070;  // 0x070 [R] (CalcAlpha)
    u32 m_up_074;  // 0x074 [R/W] (CalcAlpha, Setup)
    f32 m_up_078;  // 0x078 [R/W] (Setup)
    u8 _pad_07C[8];  // 0x07C
    f32 m_up_084;  // 0x084 [W] (Setup)
    f32 m_up_088;  // 0x088 [R/W] (Setup)
    u8 _pad_08C[8];  // 0x08C
    f32 m_up_094;  // 0x094 [W] (Setup)
    f32 m_up_098;  // 0x098 [R/W] (Setup)
    u8 _pad_09C[8];  // 0x09C
    f32 m_up_0A4;  // 0x0A4 [W] (Setup)
    f32 m_up_0A8;  // 0x0A8 [R/W] (Setup)
    u8 _pad_0AC[8];  // 0x0AC
    f32 m_up_0B4;  // 0x0B4 [W] (Setup)
    f32 m_up_0B8;  // 0x0B8 [R/W] (Setup)
    u8 _pad_0BC[8];  // 0x0BC
    f32 m_up_0C4;  // 0x0C4 [W] (Setup)
};

#endif // TRAPEZOIDFADE_H
