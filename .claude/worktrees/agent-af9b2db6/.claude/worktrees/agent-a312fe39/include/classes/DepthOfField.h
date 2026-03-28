#ifndef DEPTHOFFIELD_H
#define DEPTHOFFIELD_H

#include "types.h"

// DepthOfField - struct layout extracted from assembly analysis
// Estimated minimum size: 0x50 (80 bytes)
// 12 known fields (11 named), 16 methods

class DepthOfField {
public:
    // Constructors / Destructors
    DepthOfField(void)  // 0x808F4F98
    ~DepthOfField(void);  // 0x808F47B0

    // Methods
    void SetTargetSettings(DepthOfFieldSettings &);  // 0x808F47FC (84B)
    void UpdateTargetParameters(float);  // 0x808F2CC4 (476B)
    void EffectStateChanged(FrameEffect::EffectState);  // 0x808F2EA0 (112B)
    void EffectIsFinishedFadingIn(float);  // 0x808F2F10 (68B)
    void EffectIsFinishedFadingOut(float);  // 0x808F2F54 (68B)
    void UpdateTuningUI(void);  // 0x808F2F98 (80B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_targetParameters;  // 0x000 [R] (UpdateTargetParameters)
    f32 m_targetParameters_004;  // 0x004 [R] (UpdateTargetParameters)
    u8 _pad_008[4];  // 0x008
    u32 m_targetParameters_00C;  // 0x00C [R] (UpdateTargetParameters)
    u8 _pad_010[4];  // 0x010
    u32 m_targetParameters_014;  // 0x014 [R] (UpdateTargetParameters)
    f32 m_targetParameters_018;  // 0x018 [R] (UpdateTargetParameters)
    u8 _pad_01C[8];  // 0x01C
    f32 m_targetParameters_024;  // 0x024 [R] (UpdateTargetParameters)
    u32 m_targetParameters_028;  // 0x028 [R/W] (EffectStateChanged, UpdateTargetParameters)
    u32 m_targetParameters_02C;  // 0x02C [W] (UpdateTargetParameters)
    u8 _pad_030[8];  // 0x030
    f32 m_targetParameters_038;  // 0x038 [W] (UpdateTargetParameters)
    u32 m_field_03C;  // 0x03C [W] (EffectStateChanged)
    f32 m_targetParameters_040;  // 0x040 [R] (UpdateTargetParameters)
    u8 _pad_044[8];  // 0x044
    f32 m_targetParameters_04C;  // 0x04C [R] (UpdateTargetParameters)
};

#endif // DEPTHOFFIELD_H
