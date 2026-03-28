#ifndef MOTIONBLUR_H
#define MOTIONBLUR_H

#include "types.h"

// MotionBlur - struct layout extracted from assembly analysis
// Estimated minimum size: 0x34 (52 bytes)
// 11 known fields (11 named), 15 methods

class MotionBlur {
public:
    // Constructors / Destructors
    MotionBlur(void)  // 0x808F4EB8
    ~MotionBlur(void);  // 0x808F439C

    // Methods
    void SetTargetSettings(MotionBlurSettings &);  // 0x808F43E8 (68B)
    void UpdateTargetParameters(float);  // 0x808F2780 (264B)
    void EffectStateChanged(FrameEffect::EffectState);  // 0x808F2888 (96B)
    void EffectIsFinishedFadingIn(float);  // 0x808F28E8 (68B)
    void EffectIsFinishedFadingOut(float);  // 0x808F292C (68B)
    void UpdateTuningUI(void);  // 0x808F2970 (80B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_targetParameters;  // 0x000 [R] (UpdateTargetParameters)
    f32 m_targetParameters_004;  // 0x004 [R] (UpdateTargetParameters)
    u8 _pad_008[4];  // 0x008
    u32 m_targetParameters_00C;  // 0x00C [R] (UpdateTargetParameters)
    u8 _pad_010[4];  // 0x010
    f32 m_targetParameters_014;  // 0x014 [R] (UpdateTargetParameters)
    f32 m_targetParameters_018;  // 0x018 [R] (UpdateTargetParameters)
    u32 m_targetParameters_01C;  // 0x01C [R] (UpdateTargetParameters)
    f32 m_targetParameters_020;  // 0x020 [W] (UpdateTargetParameters)
    f32 m_targetParameters_024;  // 0x024 [W] (UpdateTargetParameters)
    u32 m_targetParameters_028;  // 0x028 [W] (UpdateTargetParameters)
    f32 m_targetParameters_02C;  // 0x02C [R] (UpdateTargetParameters)
    f32 m_targetParameters_030;  // 0x030 [R] (UpdateTargetParameters)
};

#endif // MOTIONBLUR_H
