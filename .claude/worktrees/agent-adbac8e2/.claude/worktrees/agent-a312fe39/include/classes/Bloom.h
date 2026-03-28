#ifndef BLOOM_H
#define BLOOM_H

#include "types.h"

// Bloom - struct layout extracted from assembly analysis
// Estimated minimum size: 0x74 (116 bytes)
// 12 known fields (12 named), 16 methods

class Bloom {
public:
    // Constructors / Destructors
    Bloom(void)  // 0x808F4F28
    ~Bloom(void);  // 0x808F45D4

    // Methods
    void SetTargetSettings(BloomSettings &);  // 0x808F4620 (156B)
    void UpdateTargetParameters(float);  // 0x808F29C0 (372B)
    void EffectStateChanged(FrameEffect::EffectState);  // 0x808F2B34 (184B)
    void EffectIsFinishedFadingIn(float);  // 0x808F2BEC (68B)
    void EffectIsFinishedFadingOut(float);  // 0x808F2C30 (68B)
    void UpdateTuningUI(void);  // 0x808F2C74 (80B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_targetSettings;  // 0x000 [R/W] (Bloom, EffectStateChanged, SetTargetSettings, ...)
    f32 m_targetSettings_004;  // 0x004 [R/W] (Bloom, EffectStateChanged, SetTargetSettings, ...)
    f32 m_targetSettings_008;  // 0x008 [W] (Bloom, EffectStateChanged, SetTargetSettings)
    u32 m_targetSettings_00C;  // 0x00C [R/W] (Bloom, EffectStateChanged, SetTargetSettings, ...)
    u32 m_targetSettings_010;  // 0x010 [W] (Bloom, EffectStateChanged, SetTargetSettings)
    f32 m_targetSettings_014;  // 0x014 [R/W] (EffectStateChanged, SetTargetSettings, UpdateTargetParameters)
    f32 m_targetParameters;  // 0x018 [R] (UpdateTargetParameters)
    f32 m_targetParameters_01C;  // 0x01C [R] (UpdateTargetParameters)
    u8 _pad_020[0x20];  // 0x020
    f32 m_targetParameters_040;  // 0x040 [W] (UpdateTargetParameters)
    f32 m_targetParameters_044;  // 0x044 [W] (UpdateTargetParameters)
    f32 m_targetParameters_048;  // 0x048 [W] (UpdateTargetParameters)
    u8 _pad_04C[0x24];  // 0x04C
    f32 m_targetParameters_070;  // 0x070 [R] (UpdateTargetParameters)
};

#endif // BLOOM_H
