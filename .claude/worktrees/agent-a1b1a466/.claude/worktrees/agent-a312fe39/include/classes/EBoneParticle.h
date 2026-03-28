#ifndef EBONEPARTICLE_H
#define EBONEPARTICLE_H

#include "types.h"

// EBoneParticle - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8C (140 bytes)
// 18 known fields (6 named), 13 methods

class EBoneParticle {
public:
    // Constructors / Destructors
    EBoneParticle(cXPerson *, AnimParticleData *, bool)  // 0x800363DC
    ~EBoneParticle(void);  // 0x80036908

    // Methods
    void UpdateParticleLoad(void);  // 0x8003665C (564B)
    void Refresh(void);  // 0x80036890 (120B)
    void Update(void);  // 0x80036B2C (960B)
    void SetStopImmediate(bool);  // 0x80143F5C (40B)
    void SetShouldContinueOnSkillStart(bool);  // 0x80143FB0 (40B)
    /* ? */ GetShouldContinueOnSkillStart(void);  // 0x80143F84 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (EBoneParticle, Update, UpdateParticleLoad)
    u32 m_field_004;  // 0x004 [R] (Update)
    u8 _pad_008[0xC];  // 0x008
    u32 m_particleLoad_014;  // 0x014 [R] (UpdateParticleLoad)
    u8 _pad_018[0x28];  // 0x018
    u16 m_field_040;  // 0x040 [W] (EBoneParticle)
    u8 _pad_042[2];  // 0x042
    u32 m_field_044;  // 0x044 [W] (EBoneParticle)
    u32 m_particleLoad_048;  // 0x048 [R/W] (EBoneParticle, UpdateParticleLoad)
    u32 m_field_04C;  // 0x04C [W] (EBoneParticle)
    u32 m_field_050;  // 0x050 [R/W] (EBoneParticle, Update, ~EBoneParticle)
    u32 m_field_054;  // 0x054 [R/W] (EBoneParticle, Update)
    u8 _pad_058[8];  // 0x058
    u32 m_particleLoad_060;  // 0x060 [R/W] (EBoneParticle, UpdateParticleLoad, ~EBoneParticle)
    u32 m_field_064;  // 0x064 [R/W] (EBoneParticle, Update, UpdateParticleLoad, ...)
    u32 m_field_068;  // 0x068 [R/W] (EBoneParticle, Update, UpdateParticleLoad, ...)
    u32 m_field_06C;  // 0x06C [R/W] (EBoneParticle, Update, UpdateParticleLoad, ...)
    u32 m_particleLoad_070;  // 0x070 [R/W] (EBoneParticle, UpdateParticleLoad, ~EBoneParticle)
    u32 m_particleLoad_074;  // 0x074 [R/W] (EBoneParticle, UpdateParticleLoad, ~EBoneParticle)
    u32 m_field_078;  // 0x078 [R/W] (EBoneParticle, ~EBoneParticle)
    u32 m_field_07C;  // 0x07C [W] (EBoneParticle)
    u8 _pad_080[8];  // 0x080
    u32 m_field_088;  // 0x088 [R] (Update)
};

#endif // EBONEPARTICLE_H
