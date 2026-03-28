#ifndef RAINEFFECT_H
#define RAINEFFECT_H

#include "types.h"

// RainEffect - struct layout extracted from assembly analysis
// Estimated minimum size: 0xEA (234 bytes)
// 17 known fields (7 named), 10 methods

class RainEffect {
public:
    // Constructors / Destructors
    RainEffect(float, float, float, RainEffect::RainType)  // 0x8017CBA8
    ~RainEffect(void);  // 0x8017D0B4

    // Methods
    void RainModeUpdate(float);  // 0x8017D248 (1440B)
    void UpdateParticleRainLoad(void);  // 0x8017CED8 (476B)
    void UpdateParticleRainSplashLoad(void);  // 0x8017CC9C (572B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (RainEffect, UpdateParticleRainLoad, UpdateParticleRainSplashLoad)
    u32 m_field_004;  // 0x004 [R/W] (RainEffect, RainModeUpdate, UpdateParticleRainLoad, ...)
    u32 m_field_008;  // 0x008 [R/W] (RainEffect, RainModeUpdate, ~RainEffect)
    u32 m_particleRainSplashLoad;  // 0x00C [R/W] (RainEffect, UpdateParticleRainSplashLoad)
    u32 m_field_010;  // 0x010 [R/W] (RainEffect, RainModeUpdate, UpdateParticleRainSplashLoad, ...)
    f32 m_field_014;  // 0x014 [R/W] (RainEffect, RainModeUpdate)
    f32 m_field_018;  // 0x018 [R/W] (RainEffect, RainModeUpdate)
    f32 m_field_01C;  // 0x01C [R/W] (RainEffect, RainModeUpdate)
    f32 m_particleRainLoad_020;  // 0x020 [R/W] (RainModeUpdate, UpdateParticleRainLoad)
    f32 m_particleRainLoad_024;  // 0x024 [R/W] (RainModeUpdate, UpdateParticleRainLoad)
    f32 m_particleRainSplashLoad_028;  // 0x028 [W] (UpdateParticleRainSplashLoad)
    f32 m_particleRainSplashLoad_02C;  // 0x02C [W] (UpdateParticleRainSplashLoad)
    f32 m_field_030;  // 0x030 [R/W] (RainEffect, RainModeUpdate)
    u32 m_field_034;  // 0x034 [R/W] (RainEffect, UpdateParticleRainLoad, UpdateParticleRainSplashLoad, ...)
    u8 _pad_038[0x20];  // 0x038
    s16 m_field_058;  // 0x058 [R] (RainModeUpdate)
    u8 _pad_05A[0x2E];  // 0x05A
    u32 m_particleRainSplashLoad_088;  // 0x088 [R] (RainModeUpdate, UpdateParticleRainSplashLoad)
    u8 _pad_08C[0x5C];  // 0x08C
    s16 m_field_0E8;  // 0x0E8 [R] (RainModeUpdate)
};

#endif // RAINEFFECT_H
