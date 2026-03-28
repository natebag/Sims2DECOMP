#ifndef SIMSCAMERAPARAMETERS_H
#define SIMSCAMERAPARAMETERS_H

#include "types.h"

// SimsCameraParameters - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C8 (456 bytes)
// 80 known fields (1 named), 10 methods

class SimsCameraParameters {
public:
    // Constructors / Destructors
    SimsCameraParameters(void)  // 0x8003A7D8
    ~SimsCameraParameters(void);  // 0x8003ADBC

    // Methods
    void Validate(void);  // 0x8003AE20 (72B)
    /* ? */ GetWindowName(void);  // 0x8003AE68 (68B)
    void SetupWindow(CUIWindow *);  // 0x8003AEAC (3056B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (SimsCameraParameters)
    f32 m_field_004;  // 0x004 [W] (SimsCameraParameters)
    f32 m_field_008;  // 0x008 [W] (SimsCameraParameters)
    f32 m_field_00C;  // 0x00C [W] (SimsCameraParameters)
    f32 m_field_010;  // 0x010 [W] (SimsCameraParameters)
    f32 m_field_014;  // 0x014 [W] (SimsCameraParameters)
    f32 m_field_018;  // 0x018 [W] (SimsCameraParameters)
    f32 m_field_01C;  // 0x01C [W] (SimsCameraParameters)
    f32 m_field_020;  // 0x020 [W] (SimsCameraParameters)
    f32 m_field_024;  // 0x024 [W] (SimsCameraParameters)
    f32 m_field_028;  // 0x028 [R/W] (SimsCameraParameters)
    f32 m_field_02C;  // 0x02C [W] (SimsCameraParameters)
    f32 m_field_030;  // 0x030 [W] (SimsCameraParameters)
    f32 m_field_034;  // 0x034 [W] (SimsCameraParameters)
    f32 m_field_038;  // 0x038 [R/W] (SimsCameraParameters)
    f32 m_field_03C;  // 0x03C [W] (SimsCameraParameters)
    f32 m_field_040;  // 0x040 [W] (SimsCameraParameters)
    u8 _pad_044[8];  // 0x044
    f32 m_field_04C;  // 0x04C [W] (SimsCameraParameters)
    f32 m_field_050;  // 0x050 [W] (SimsCameraParameters)
    f32 m_field_054;  // 0x054 [W] (SimsCameraParameters)
    f32 m_field_058;  // 0x058 [W] (SimsCameraParameters)
    f32 m_field_05C;  // 0x05C [W] (SimsCameraParameters)
    f32 m_field_060;  // 0x060 [W] (SimsCameraParameters)
    f32 m_field_064;  // 0x064 [W] (SimsCameraParameters)
    f32 m_field_068;  // 0x068 [W] (SimsCameraParameters)
    f32 m_field_06C;  // 0x06C [W] (SimsCameraParameters)
    f32 m_field_070;  // 0x070 [W] (SimsCameraParameters)
    f32 m_field_074;  // 0x074 [W] (SimsCameraParameters)
    f32 m_field_078;  // 0x078 [W] (SimsCameraParameters)
    f32 m_field_07C;  // 0x07C [W] (SimsCameraParameters)
    f32 m_field_080;  // 0x080 [W] (SimsCameraParameters)
    f32 m_field_084;  // 0x084 [W] (SimsCameraParameters)
    f32 m_field_088;  // 0x088 [W] (SimsCameraParameters)
    f32 m_field_08C;  // 0x08C [W] (SimsCameraParameters)
    f32 m_field_090;  // 0x090 [W] (SimsCameraParameters)
    f32 m_field_094;  // 0x094 [W] (SimsCameraParameters)
    f32 m_field_098;  // 0x098 [W] (SimsCameraParameters)
    f32 m_field_09C;  // 0x09C [W] (SimsCameraParameters)
    f32 m_field_0A0;  // 0x0A0 [W] (SimsCameraParameters)
    f32 m_field_0A4;  // 0x0A4 [W] (SimsCameraParameters)
    f32 m_field_0A8;  // 0x0A8 [W] (SimsCameraParameters)
    f32 m_field_0AC;  // 0x0AC [W] (SimsCameraParameters)
    f32 m_field_0B0;  // 0x0B0 [W] (SimsCameraParameters)
    f32 m_field_0B4;  // 0x0B4 [W] (SimsCameraParameters)
    f32 m_field_0B8;  // 0x0B8 [W] (SimsCameraParameters)
    f32 m_field_0BC;  // 0x0BC [W] (SimsCameraParameters)
    u8 _pad_0C0[8];  // 0x0C0
    f32 m_field_0C8;  // 0x0C8 [W] (SimsCameraParameters)
    u8 _pad_0CC[8];  // 0x0CC
    f32 m_field_0D4;  // 0x0D4 [W] (SimsCameraParameters)
    u8 _pad_0D8[8];  // 0x0D8
    u32 m_field_0E0;  // 0x0E0 [W] (SimsCameraParameters)
    u32 m_field_0E4;  // 0x0E4 [W] (SimsCameraParameters)
    u32 m_field_0E8;  // 0x0E8 [W] (SimsCameraParameters)
    u8 _pad_0EC[4];  // 0x0EC
    u32 m_field_0F0;  // 0x0F0 [W] (SimsCameraParameters)
    u32 m_field_0F4;  // 0x0F4 [W] (SimsCameraParameters)
    u32 m_field_0F8;  // 0x0F8 [W] (SimsCameraParameters)
    f32 m_field_0FC;  // 0x0FC [W] (SimsCameraParameters)
    u8 _pad_100[0xC];  // 0x100
    f32 m_field_10C;  // 0x10C [W] (SimsCameraParameters)
    u8 _pad_110[0xC];  // 0x110
    f32 m_field_11C;  // 0x11C [W] (SimsCameraParameters)
    u8 _pad_120[0x1C];  // 0x120
    f32 m_field_13C;  // 0x13C [W] (SimsCameraParameters)
    u8 _pad_140[0xC];  // 0x140
    f32 m_field_14C;  // 0x14C [W] (SimsCameraParameters)
    u8 _pad_150[0xC];  // 0x150
    f32 m_field_15C;  // 0x15C [W] (SimsCameraParameters)
    u8 _pad_160[0xC];  // 0x160
    f32 m_field_16C;  // 0x16C [W] (SimsCameraParameters)
    f32 m_field_170;  // 0x170 [W] (SimsCameraParameters)
    f32 m_field_174;  // 0x174 [W] (SimsCameraParameters)
    u8 _pad_178[4];  // 0x178
    f32 m_field_17C;  // 0x17C [W] (SimsCameraParameters)
    f32 m_field_180;  // 0x180 [W] (SimsCameraParameters)
    f32 m_field_184;  // 0x184 [W] (SimsCameraParameters)
    u32 m_field_188;  // 0x188 [W] (SimsCameraParameters)
    u32 m_field_18C;  // 0x18C [W] (SimsCameraParameters)
    u32 m_field_190;  // 0x190 [W] (SimsCameraParameters)
    u8 _pad_194[4];  // 0x194
    u32 m_field_198;  // 0x198 [W] (SimsCameraParameters)
    u32 m_field_19C;  // 0x19C [W] (SimsCameraParameters)
    u32 m_field_1A0;  // 0x1A0 [W] (SimsCameraParameters)
    u32 m_field_1A4;  // 0x1A4 [W] (SimsCameraParameters)
    u32 m_field_1A8;  // 0x1A8 [W] (SimsCameraParameters)
    u32 m_field_1AC;  // 0x1AC [W] (SimsCameraParameters)
    u8 _pad_1B0[4];  // 0x1B0
    u32 m_field_1B4;  // 0x1B4 [W] (SimsCameraParameters)
    u32 m_field_1B8;  // 0x1B8 [W] (SimsCameraParameters)
    u32 m_field_1BC;  // 0x1BC [W] (SimsCameraParameters)
    u32 m_field_1C0;  // 0x1C0 [W] (SimsCameraParameters)
    u32 m_field_1C4;  // 0x1C4 [W] (SimsCameraParameters)
};

#endif // SIMSCAMERAPARAMETERS_H
