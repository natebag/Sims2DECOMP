#ifndef EPARTICLEEFFECT_H
#define EPARTICLEEFFECT_H

#include "types.h"

// EParticleEffect - struct layout extracted from assembly analysis
// Estimated minimum size: 0x150 (336 bytes)
// 29 known fields (13 named), 12 methods

class EParticleEffect {
public:
    // Constructors / Destructors
    EParticleEffect(AttachmentNode &, EMat4 &)  // 0x800E1F18
    ~EParticleEffect(void);  // 0x800E24EC

    // Methods
    void UpdateParticleEffectLoad(void);  // 0x800E2018 (1116B)
    void Refresh(void);  // 0x800E2474 (120B)
    void SetPos(EMat4 &, EVec3 *);  // 0x800E27B8 (544B)
    void SetAlphaFade(float);  // 0x800E29D8 (180B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (EParticleEffect, UpdateParticleEffectLoad)
    u32 m_field_004;  // 0x004 [W] (EParticleEffect)
    u32 m_field_008;  // 0x008 [W] (EParticleEffect)
    u32 m_field_00C;  // 0x00C [W] (EParticleEffect)
    u32 m_field_010;  // 0x010 [W] (EParticleEffect)
    u32 m_particleEffectLoad_014;  // 0x014 [R/W] (EParticleEffect, UpdateParticleEffectLoad)
    u32 m_field_018;  // 0x018 [W] (EParticleEffect)
    u32 m_field_01C;  // 0x01C [W] (EParticleEffect)
    u32 m_field_020;  // 0x020 [W] (EParticleEffect)
    u32 m_field_024;  // 0x024 [W] (EParticleEffect)
    u32 m_field_028;  // 0x028 [W] (EParticleEffect)
    u32 m_field_02C;  // 0x02C [W] (EParticleEffect)
    s16 m_particleEffectLoad_030;  // 0x030 [R/W] (EParticleEffect, UpdateParticleEffectLoad)
    u8 _pad_032[2];  // 0x032
    u32 m_particleEffectLoad_034;  // 0x034 [R/W] (EParticleEffect, UpdateParticleEffectLoad)
    u32 m_field_038;  // 0x038 [W] (EParticleEffect)
    u32 m_field_03C;  // 0x03C [W] (EParticleEffect)
    u16 m_field_040;  // 0x040 [W] (EParticleEffect)
    u8 _pad_042[2];  // 0x042
    u32 m_field_044;  // 0x044 [W] (EParticleEffect)
    u32 m_field_048;  // 0x048 [W] (EParticleEffect)
    u32 m_field_04C;  // 0x04C [W] (EParticleEffect)
    u8 _pad_050[8];  // 0x050
    u32 m_alphaFade;  // 0x058 [R/W] (EParticleEffect, SetAlphaFade, SetPos, ...)
    u32 m_alphaFade_05C;  // 0x05C [R/W] (EParticleEffect, SetAlphaFade, SetPos, ...)
    u32 m_particleEffectLoad_060;  // 0x060 [R/W] (EParticleEffect, UpdateParticleEffectLoad, ~EParticleEffect)
    u32 m_alphaFade_064;  // 0x064 [R/W] (EParticleEffect, SetAlphaFade, SetPos, ...)
    u32 m_particleEffectLoad_068;  // 0x068 [R/W] (EParticleEffect, UpdateParticleEffectLoad, ~EParticleEffect)
    u32 m_particleEffectLoad_06C;  // 0x06C [R/W] (EParticleEffect, UpdateParticleEffectLoad, ~EParticleEffect)
    u8 _pad_070[0x18];  // 0x070
    u32 m_pos;  // 0x088 [R] (SetPos)
    u8 _pad_08C[0xB4];  // 0x08C
    u32 m_particleEffectLoad_140;  // 0x140 [R/W] (UpdateParticleEffectLoad)
    u8 _pad_144[8];  // 0x144
    f32 m_alphaFade_14C;  // 0x14C [W] (SetAlphaFade)
};

#endif // EPARTICLEEFFECT_H
