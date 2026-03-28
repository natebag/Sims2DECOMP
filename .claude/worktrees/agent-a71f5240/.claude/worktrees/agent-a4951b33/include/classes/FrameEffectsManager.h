#ifndef FRAMEEFFECTSMANAGER_H
#define FRAMEEFFECTSMANAGER_H

#include "types.h"

// FrameEffectsManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0x2B60 (11104 bytes)
// 9 known fields (0 named), 10 methods

class FrameEffectsManager {
public:
    // Methods
    void BloomObject(void);  // 0x808F4D7C (44B)
    void MotionBlurObject(void);  // 0x808F4D50 (44B)
    void DepthOfFieldObject(void);  // 0x808F4DA8 (44B)
    void Init(void);  // 0x808F4960 (348B)
    void Shutdown(void);  // 0x808F4ABC (660B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (Init, Shutdown)
    f32 m_field_004;  // 0x004 [R/W] (Init, Shutdown)
    f32 m_field_008;  // 0x008 [R/W] (Init, Shutdown)
    u32 m_field_00C;  // 0x00C [W] (Init)
    u32 m_field_010;  // 0x010 [W] (Init)
    f32 m_field_014;  // 0x014 [W] (Init)
    u8 _pad_018[8];  // 0x018
    f32 m_field_020;  // 0x020 [W] (Init)
    u8 _pad_024[8];  // 0x024
    f32 m_field_02C;  // 0x02C [W] (Init)
    u8 _pad_030[0x2B2C];  // 0x030
    f32 m_field_2B5C;  // 0x2B5C [R] (Init)
};

#endif // FRAMEEFFECTSMANAGER_H
