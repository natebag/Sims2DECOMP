#ifndef EFFECTS_H
#define EFFECTS_H

#include "types.h"

// Effects - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1A8 (424 bytes)
// 65 known fields (0 named), 50 methods

class Effects {
public:
    // Methods
    void Rand2f(void);  // 0x80180030 (104B)
    void Rand2(void);  // 0x80180184 (108B)
    void Vec3CrossProduct(EVec3 &, EVec3 &, EVec3 &);  // 0x80449DF4 (380B)
    void PreComputeRand32Table(void);  // 0x808E5F98 (128B)
    void Compute32BitRand(void);  // 0x808E6264 (236B)
    void PMRand(void);  // 0x808E6018 (156B)
    void SetSeed2(int);  // 0x808E60B4 (144B)
    /* ? */ GetTextureFromID(unsigned int);  // 0x808E6144 (88B)
    /* ? */ GetDefaultRenderContext(void);  // 0x808E619C (36B)
    /* ? */ GetFaceCameraRotation(ERC *, EMat4 &, EVec4 &, bool);  // 0x808E61C0 (44B)
    void FreeFastAllocPool(FastAllocPool *);  // 0x808E61EC (120B)
    void ShutdownEffectsSystem(void);  // 0x808E6414 (104B)
    void InitializeEffectsSystem(void);  // 0x808E6350 (196B)
    void SinCosf(float, float &, float &);  // 0x808E7B38 (660B)
    void InitEffectsMath(void);  // 0x808E7B1C (28B)
    void Mat4SetEulerAngles34(float, float, float, EMat4 &);  // 0x808E7DCC (4000B)
    void Mat4Multiply34(EMat4 &, EMat4 &, EMat4 &);  // 0x808E8D6C (604B)
    void Mat4Copy34(EMat4 &, EMat4 &);  // 0x808E8FC8 (192B)
    void ValidateVec(EVec3 &);  // 0x808F0580 (32B)
    void Vec4DotProduct3(EVec4 &, EVec4 &);  // 0x808F0158 (100B)
    void Uint32Rand2f(unsigned int);  // 0x808F0664 (76B)
    void Vec3Scale(float, EVec3 &, EVec3 &);  // 0x808F01BC (196B)
    void Vec3DistanceSquared(EVec3 &, EVec3 &);  // 0x808F0280 (96B)
    void Vec3Copy(EVec3 &, EVec3 &);  // 0x808F02E0 (68B)
    void SetTerrainColor(EVec4 &, EVec4 &);  // 0x808F05A0 (92B)
    void MultiplyMatrix1Vector(EVec3 &, EVec3 &);  // 0x808F06B0 (72B)
    void MultiplyMatrix1Vector3(EVec3 &, EVec3 &);  // 0x808F06F8 (72B)
    void Vec3Substract(EVec3 &, EVec3 &, EVec4 &);  // 0x808F0324 (80B)
    void Vec3AddScale(EVec3 &, EVec3 &, float, EVec3 &);  // 0x808F0374 (268B)
    void Vec4AddScale(EVec4 &, EVec4 &, float, EVec4 &);  // 0x808EFE00 (104B)
    void Vec4Clamp4(EVec4 &, EVec4 &, EVec4 &);  // 0x808EFE68 (752B)
    void Float2Int(float);  // 0x808F04DC (56B)
    void Vec4AddTwoScale3(float, EVec3 &, float, EVec3 &, EVec4 &);  // 0x808F1E40 (292B)
    void Vec4Add3(EVec3 &, EVec3 &, EVec4 &);  // 0x808F1DF0 (80B)
    void Vec4AddTwoScale4(float, EVec4 &, float, EVec4 &, EVec4 &);  // 0x808F1F64 (360B)
    void Vec4AddScale3(EVec3 &, EVec3 &, float, EVec4 &);  // 0x808F1D84 (108B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (Effect::DefaultInit, Effect::Effect, EffectsManager::AddEffect, ...)
    f32 m_field_004;  // 0x004 [R/W] (Effect::DefaultInit, Effect::Effect, EffectsManager::AddEffect, ...)
    f32 m_field_008;  // 0x008 [R/W] (Effect::DefaultInit, Effect::Effect, EffectsManager::AddEffect, ...)
    f32 m_field_00C;  // 0x00C [R/W] (Effect::DefaultInit, Effect::Effect, FastParticleEmitter::AddBurst, ...)
    f32 m_field_010;  // 0x010 [R/W] (Effect::DefaultInit, Effect::Effect, EffectsManager::Update, ...)
    f32 m_field_014;  // 0x014 [R/W] (Effect::DefaultInit, Effect::Effect, FastParticleEmitter::RotateEmitter, ...)
    f32 m_field_018;  // 0x018 [R/W] (Effect::DefaultInit, Effect::Effect, FastParticleEmitter::RotateEmitter, ...)
    f32 m_field_01C;  // 0x01C [R/W] (Effect::DefaultInit, Effect::Effect, FastParticleEmitter::RotateEmitter, ...)
    f32 m_field_020;  // 0x020 [R/W] (Effect::DefaultInit, Effect::Effect, FastParticleEmitter::RotateEmitter, ...)
    f32 m_field_024;  // 0x024 [R/W] (Effect::DefaultInit, Effect::Effect, FastParticleEmitter::RotateEmitter, ...)
    f32 m_field_028;  // 0x028 [R/W] (Effect::DefaultInit, Effect::Effect, FastParticleEmitter::RotateEmitter, ...)
    f32 m_field_02C;  // 0x02C [R/W] (Effect::DefaultInit, Effect::Effect, FastParticleEmitter::RotateEmitter, ...)
    u32 m_field_030;  // 0x030 [R/W] (Effect::DefaultInit, Effect::Effect)
    u32 m_field_034;  // 0x034 [R/W] (Effect::DefaultInit, Effect::Effect)
    u32 m_field_038;  // 0x038 [R/W] (Effect::DefaultInit, Effect::Effect)
    u32 m_field_03C;  // 0x03C [R/W] (Effect::DefaultInit, Effect::Effect)
    u16 m_field_040;  // 0x040 [W] (Effect::Effect)
    u8 _pad_042[2];  // 0x042
    u32 m_field_044;  // 0x044 [W] (Effect::Effect)
    u32 m_field_048;  // 0x048 [W] (Effect::Effect)
    u32 m_field_04C;  // 0x04C [W] (Effect::Effect)
    f32 m_field_050;  // 0x050 [W] (FastParticleEmitter::RotateEmitter)
    u8 _pad_054[0x2C];  // 0x054
    f32 m_field_080;  // 0x080 [R/W] (FastParticleEmitter::SharedInitPart2)
    u8 _pad_084[0xC];  // 0x084
    f32 m_field_090;  // 0x090 [R] (FastParticleEmitter::RenderQuad)
    u8 _pad_094[0x2C];  // 0x094
    f32 m_field_0C0;  // 0x0C0 [R] (FastParticleEmitter::ComputeDispersionPositionAndVelocity, FastParticleEmitter::SharedInitPart2, FastParticleEmitter::Update)
    u8 _pad_0C4[0xC];  // 0x0C4
    f32 m_field_0D0;  // 0x0D0 [R/W] (FastParticleEmitter::AddBurst, FastParticleEmitter::SharedInitPart2, FastParticleEmitter::Update)
    u8 _pad_0D4[0xC];  // 0x0D4
    f32 m_field_0E0;  // 0x0E0 [R/W] (FastParticleEmitter::Update)
    u8 _pad_0E4[8];  // 0x0E4
    f32 m_field_0EC;  // 0x0EC [R/W] (FastParticleEmitter::SharedInitPart2, FastParticleEmitter::Update)
    f32 m_field_0F0;  // 0x0F0 [R/W] (FastParticleEmitter::ComputeDispersionPositionAndVelocity, FastParticleEmitter::SharedInitPart2, FastParticleEmitter::Update)
    u8 _pad_0F4[0xC];  // 0x0F4
    f32 m_field_100;  // 0x100 [W] (Effect::DefaultInit, Effect::SetParentTransform)
    f32 m_field_104;  // 0x104 [W] (Effect::DefaultInit, Effect::SetParentTransform)
    f32 m_field_108;  // 0x108 [W] (Effect::SetParentTransform)
    u8 _pad_10C[4];  // 0x10C
    f32 m_field_110;  // 0x110 [W] (Effect::SetParentTransform)
    f32 m_field_114;  // 0x114 [W] (Effect::SetParentTransform)
    f32 m_field_118;  // 0x118 [W] (Effect::SetParentTransform)
    u8 _pad_11C[4];  // 0x11C
    f32 m_field_120;  // 0x120 [W] (Effect::SetParentTransform)
    f32 m_field_124;  // 0x124 [W] (Effect::SetParentTransform)
    f32 m_field_128;  // 0x128 [W] (Effect::SetParentTransform)
    u8 _pad_12C[0x14];  // 0x12C
    u32 m_field_140;  // 0x140 [R/W] (Effect::DefaultInit, Effect::SetParentTransform, FastParticleEmitter::ComputeCombinedMatrix, ...)
    u32 m_field_144;  // 0x144 [R/W] (Effect::Effect, EffectsManager::CreateEffect, FastParticleEmitter::FastParticleEmitter, ...)
    u32 m_field_148;  // 0x148 [R/W] (FastParticleEmitter::AddBurst, FastParticleEmitter::SharedInitPart1, FastParticleEmitter::SharedInitPart2, ...)
    f32 m_field_14C;  // 0x14C [R/W] (FastParticleEmitter::DoSimulationAndRender, FastParticleEmitter::SharedInitPart1)
    f32 m_field_150;  // 0x150 [R/W] (FastParticleEmitter::ComputeDispersionPositionAndVelocity, FastParticleEmitter::ComputeMaxParticles, FastParticleEmitter::PreRollParticles, ...)
    f32 m_field_154;  // 0x154 [R/W] (FastParticleEmitter::ComputeMaxParticles, FastParticleEmitter::PreRollParticles, FastParticleEmitter::ReallocateParticles, ...)
    f32 m_field_158;  // 0x158 [R/W] (FastParticleEmitter::SharedInitPart2, FastParticleEmitter::Update)
    u32 m_field_15C;  // 0x15C [R/W] (FastParticleEmitter::AddBurst, FastParticleEmitter::SharedInitPart2, FastParticleEmitter::Stop, ...)
    u32 m_field_160;  // 0x160 [R/W] (FastParticleEmitter::SharedInitPart2, FastParticleEmitter::Update)
    s16 m_field_164;  // 0x164 [R/W] (FastParticleEmitter::AllocateParticlePackets, FastParticleEmitter::FastParticleEmitter, FastParticleEmitter::FreeParticlePackets, ...)
    u8 m_field_166;  // 0x166 [W] (FastParticleEmitter::Init)
    u8 _pad_167[1];  // 0x167
    s16 m_field_168;  // 0x168 [R/W] (FastParticleEmitter::AddBurst, FastParticleEmitter::AllocateParticlePackets, FastParticleEmitter::DoSimulationAndRender, ...)
    u8 _pad_16A[2];  // 0x16A
    f32 m_field_16C;  // 0x16C [W] (FastParticleEmitter::SharedInitPart2)
    f32 m_field_170;  // 0x170 [W] (FastParticleEmitter::SharedInitPart2)
    f32 m_field_174;  // 0x174 [R/W] (FastParticleEmitter::RotateEmitter, FastParticleEmitter::SharedInitPart2)
    f32 m_field_178;  // 0x178 [R/W] (FastParticleEmitter::RotateEmitter, FastParticleEmitter::SharedInitPart2)
    f32 m_field_17C;  // 0x17C [R/W] (FastParticleEmitter::ComputeMaxParticles, FastParticleEmitter::PreRollParticles, FastParticleEmitter::ReallocateParticles, ...)
    f32 m_field_180;  // 0x180 [R/W] (FastParticleEmitter::ComputeMaxParticles, FastParticleEmitter::PreRollParticles, FastParticleEmitter::ReallocateParticles, ...)
    f32 m_field_184;  // 0x184 [R/W] (FastParticleEmitter::ComputeDispersionPositionAndVelocity, FastParticleEmitter::SharedInitPart2, FastParticleEmitter::Update)
    f32 m_field_188;  // 0x188 [R/W] (FastParticleEmitter::SharedInitPart2, FastParticleEmitter::Update)
    u32 m_field_18C;  // 0x18C [R/W] (FastParticleEmitter::AddBurst, FastParticleEmitter::AllocateParticlePackets, FastParticleEmitter::ComputeDispersionPositionAndVelocity, ...)
    u32 m_field_190;  // 0x190 [R/W] (FastParticleEmitter::AddBurst, FastParticleEmitter::DoSimulationAndRender, FastParticleEmitter::FastParticleEmitter, ...)
    u32 m_field_194;  // 0x194 [R/W] (FastParticleEmitter::FastParticleEmitter, FastParticleEmitter::Init, FastParticleEmitter::InitResourceData, ...)
    u16 m_field_198;  // 0x198 [R/W] (FastParticleEmitter::AddBurst, FastParticleEmitter::ComputeMaxParticles, FastParticleEmitter::DoSimulationAndRender, ...)
    u16 m_field_19A;  // 0x19A [R/W] (FastParticleEmitter::AddBurst, FastParticleEmitter::ComputeMaxParticles, FastParticleEmitter::DoSimulationAndRender, ...)
    u32 m_field_19C;  // 0x19C [R/W] (FastParticleEmitter::AddBurst, FastParticleEmitter::AllocateParticlePackets, FastParticleEmitter::DoSimulationAndRender, ...)
    u32 m_field_1A0;  // 0x1A0 [R/W] (FastParticleEmitter::FastParticleEmitter, FastParticleEmitter::Init, FastParticleEmitter::~FastParticleEmitter)
    u32 m_field_1A4;  // 0x1A4 [R/W] (FastParticleEmitter::DoSimulationAndRender, FastParticleEmitter::FastParticleEmitter, FastParticleEmitter::SharedInitPart2, ...)
};

#endif // EFFECTS_H
