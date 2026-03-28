#ifndef LEVELLIGHTINGTUNING_H
#define LEVELLIGHTINGTUNING_H

#include "types.h"

// LevelLightingTuning - struct layout extracted from assembly analysis
// Estimated minimum size: 0xB8 (184 bytes)
// 29 known fields (0 named), 12 methods

class LevelLightingTuning {
public:
    // Constructors / Destructors
    LevelLightingTuning(void)  // 0x8064C4E0
    ~LevelLightingTuning(void);  // 0x8064EB64

    // Methods
    void ProcessOverrides(LevelLightingEntry &);  // 0x8064C818 (476B)
    void ProcessSunYawOffsetOverride(float &);  // 0x806508F8 (72B)
    /* ? */ GetWindowName(void);  // 0x8064C12C (44B)
    void SetupWindow(CUIWindow *);  // 0x8064C158 (904B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [W] (LevelLightingTuning)
    f32 m_field_004;  // 0x004 [W] (LevelLightingTuning)
    f32 m_field_008;  // 0x008 [W] (LevelLightingTuning)
    f32 m_field_00C;  // 0x00C [W] (LevelLightingTuning)
    f32 m_field_010;  // 0x010 [W] (LevelLightingTuning)
    f32 m_field_014;  // 0x014 [W] (LevelLightingTuning)
    f32 m_field_018;  // 0x018 [W] (LevelLightingTuning)
    u32 m_field_01C;  // 0x01C [W] (LevelLightingTuning)
    u8 _pad_020[8];  // 0x020
    u32 m_field_028;  // 0x028 [W] (LevelLightingTuning)
    u8 _pad_02C[8];  // 0x02C
    f32 m_field_034;  // 0x034 [W] (LevelLightingTuning)
    u32 m_field_038;  // 0x038 [W] (LevelLightingTuning)
    f32 m_field_03C;  // 0x03C [W] (LevelLightingTuning)
    f32 m_field_040;  // 0x040 [W] (LevelLightingTuning)
    u32 m_field_044;  // 0x044 [R/W] (LevelLightingTuning, ProcessOverrides)
    f32 m_field_048;  // 0x048 [R/W] (LevelLightingTuning, ProcessOverrides)
    u8 _pad_04C[8];  // 0x04C
    f32 m_field_054;  // 0x054 [R/W] (ProcessOverrides)
    f32 m_field_058;  // 0x058 [R/W] (LevelLightingTuning, ProcessOverrides)
    u8 _pad_05C[8];  // 0x05C
    f32 m_field_064;  // 0x064 [R/W] (ProcessOverrides)
    f32 m_field_068;  // 0x068 [R/W] (LevelLightingTuning, ProcessOverrides)
    f32 m_field_06C;  // 0x06C [R/W] (ProcessOverrides)
    u8 _pad_070[4];  // 0x070
    f32 m_field_074;  // 0x074 [R/W] (LevelLightingTuning, ProcessOverrides)
    u8 _pad_078[8];  // 0x078
    f32 m_field_080;  // 0x080 [R/W] (ProcessOverrides)
    f32 m_field_084;  // 0x084 [R/W] (LevelLightingTuning, ProcessOverrides)
    u8 _pad_088[8];  // 0x088
    f32 m_field_090;  // 0x090 [R/W] (ProcessOverrides)
    f32 m_field_094;  // 0x094 [R/W] (LevelLightingTuning, ProcessOverrides)
    u8 _pad_098[8];  // 0x098
    f32 m_field_0A0;  // 0x0A0 [R/W] (ProcessOverrides)
    f32 m_field_0A4;  // 0x0A4 [R/W] (LevelLightingTuning, ProcessOverrides)
    u32 m_field_0A8;  // 0x0A8 [W] (LevelLightingTuning)
    u8 _pad_0AC[8];  // 0x0AC
    u32 m_field_0B4;  // 0x0B4 [W] (LevelLightingTuning)
};

#endif // LEVELLIGHTINGTUNING_H
