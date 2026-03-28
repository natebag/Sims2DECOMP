#ifndef EPARTICLEOBJ_H
#define EPARTICLEOBJ_H

#include "types.h"

// EParticleObj - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 6 known fields (2 named), 8 methods

class EParticleObj {
public:
    // Constructors / Destructors
    EParticleObj(void)  // 0x800E2BF0
    ~EParticleObj(void);  // 0x800E2C3C

    // Methods
    void CreateEffects(EMat4 &, float, ObjAnimDef *);  // 0x800E2CBC (592B)
    void UpdateEffectPosAndAlphaFade(EAnimController &, float, EMat4 &, EVec3 *, float);  // 0x800E2F0C (568B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_effectPosAndAlphaFade;  // 0x000 [R] (UpdateEffectPosAndAlphaFade)
    u32 m_field_004;  // 0x004 [R] (CreateEffects, ~EParticleObj)
    u32 m_field_008;  // 0x008 [R] (CreateEffects, ~EParticleObj)
    u32 m_effectPosAndAlphaFade_00C;  // 0x00C [R/W] (CreateEffects, UpdateEffectPosAndAlphaFade, ~EParticleObj)
    u8 _pad_010[4];  // 0x010
    u32 m_field_014;  // 0x014 [R] (CreateEffects)
    u32 m_field_018;  // 0x018 [R] (CreateEffects)
};

#endif // EPARTICLEOBJ_H
