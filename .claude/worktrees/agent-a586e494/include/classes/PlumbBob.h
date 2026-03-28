#ifndef PLUMBBOB_H
#define PLUMBBOB_H

#include "types.h"

// PlumbBob - struct layout extracted from assembly analysis
// Estimated minimum size: 0x440 (1088 bytes)
// 45 known fields (16 named), 70 methods

class PlumbBob {
public:
    // Constructors / Destructors
    PlumbBob(void)  // 0x8011CB74
    ~PlumbBob(void);  // 0x8011D0C8

    // Methods
    void SetTargetPos(EVec3 *);  // 0x8008D654 (68B)
    void SetZScale(float);  // 0x8008D698 (44B)
    void SetModel(unsigned int);  // 0x8011DAC0 (104B)
    void SetShadow(unsigned int);  // 0x8011DB28 (104B)
    void SetState(PlumbBob::PlumbBob_MotionState);  // 0x8011D978 (328B)
    /* ? */ GetOwner(void);  // 0x80122DDC (44B)
    /* ? */ GetTargetPos(void);  // 0x80122CD8 (44B)
    void PlumbBobOrderTableCallback(ELevelDrawData &, EOrderTableData *);  // 0x8011CB10 (100B)
    void DrawShadow(ERC *);  // 0x8011E87C (184B)
    void StartupAll(void);  // 0x8011CD50 (152B)
    void CreateInstance(int);  // 0x80122E08 (360B)
    void Startup(void);  // 0x8011CEEC (192B)
    void ShutdownAll(void);  // 0x8011CDE8 (260B)
    void Shutdown(void);  // 0x8011D058 (112B)
    void AddParticleSystem(int);  // 0x8011D130 (500B)
    void EnableDraw(bool);  // 0x8011CFAC (172B)
    void SetParticleDrawState(bool);  // 0x8011D848 (156B)
    void DestroyParticleSystems(void);  // 0x8011D6F8 (336B)
    void UpdateParticleSystem(int);  // 0x8011D324 (980B)
    void SetParticleVisibility(bool);  // 0x8011D8E4 (148B)
    void SetColor(EVec3 *);  // 0x8011DB90 (156B)
    void SetPlayerColor(int);  // 0x8011DC2C (92B)
    void SetScaleFromTween(int, float);  // 0x8011DC88 (180B)
    void BecomeTransitionIndicator(void);  // 0x8011DD3C (48B)
    void ForceMorphToPlumbbob(void);  // 0x8011DD6C (60B)
    void StartPositiveRepMomentEffect(void);  // 0x8011DDA8 (76B)
    void StartNegativeRepMomentEffect(void);  // 0x8011DDF4 (76B)
    void Update(int);  // 0x8011DE40 (2620B)
    /* ? */ GetScale(void);  // 0x80122D48 (48B)
    void SetScale(float);  // 0x80122D78 (44B)
    void Draw(ERC *);  // 0x8011E934 (684B)
    void ResetMomentum(bool);  // 0x8011EBE0 (184B)
    void Instance(int, PlumbBobOwner *);  // 0x80127BD0 (184B)
    /* ? */ GetOwner(int);  // 0x80127C88 (148B)
    void SetOwner(int, PlumbBobOwner *);  // 0x80127D1C (136B)
    /* ? */ GetPlumbob(int);  // 0x805A9C84 (120B)
    void SetBobbing(bool);  // 0x805A9B78 (44B)
    void SetRotating(bool);  // 0x805A9BA4 (44B)
    /* ? */ GetExtents(EVec2 &);  // 0x805A9C44 (64B)
    /* ? */ GetParticleVisibility(void);  // 0x805A9BD0 (76B)
    void ClearFrameUpdateCount(void);  // 0x805A9C1C (40B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_state;  // 0x000 [R/W] (AddParticleSystem, Draw, DrawShadow, ...)
    f32 m_state_004;  // 0x004 [R/W] (Draw, DrawShadow, SetState, ...)
    f32 m_state_008;  // 0x008 [R/W] (Draw, DrawShadow, SetState, ...)
    f32 m_state_00C;  // 0x00C [R/W] (ResetMomentum, SetState, Update)
    u8 _pad_010[4];  // 0x010
    f32 m_field_014;  // 0x014 [R] (AddParticleSystem, ResetMomentum)
    u32 m_state_018;  // 0x018 [W] (ResetMomentum, SetState, Update)
    u8 _pad_01C[8];  // 0x01C
    f32 m_state_024;  // 0x024 [W] (SetState, Update)
    f32 m_state_028;  // 0x028 [W] (SetState, Update)
    f32 m_field_02C;  // 0x02C [R/W] (Update)
    u32 m_color;  // 0x030 [W] (SetColor)
    u8 _pad_034[0xC];  // 0x034
    u32 m_color_040;  // 0x040 [W] (SetColor)
    u8 _pad_044[8];  // 0x044
    f32 m_field_04C;  // 0x04C [R/W] (Draw)
    f32 m_field_050;  // 0x050 [R/W] (Draw)
    f32 m_field_054;  // 0x054 [W] (Draw)
    u8 _pad_058[0x30];  // 0x058
    u32 m_particleSystem;  // 0x088 [R] (UpdateParticleSystem)
    u8 _pad_08C[0xC];  // 0x08C
    u32 m_field_098;  // 0x098 [R] (PlumbBobOrderTableCallback)
    u8 _pad_09C[0xC];  // 0x09C
    u32 m_field_0A8;  // 0x0A8 [W] (PlumbBobOrderTableCallback)
    u32 m_field_0AC;  // 0x0AC [W] (PlumbBobOrderTableCallback)
    u32 m_field_0B0;  // 0x0B0 [W] (PlumbBobOrderTableCallback)
    u32 m_field_0B4;  // 0x0B4 [W] (PlumbBobOrderTableCallback)
    u32 m_field_0B8;  // 0x0B8 [W] (PlumbBobOrderTableCallback)
    u8 _pad_0BC[0x64];  // 0x0BC
    u32 m_field_120;  // 0x120 [W] (PlumbBob)
    u32 m_field_124;  // 0x124 [W] (PlumbBob)
    f32 m_state_128;  // 0x128 [R/W] (PlumbBob, SetState, Update)
    u8 _pad_12C[4];  // 0x12C
    f32 m_field_130;  // 0x130 [R] (Update)
    f32 m_field_134;  // 0x134 [W] (PlumbBob, Update)
    u8 _pad_138[8];  // 0x138
    f32 m_field_140;  // 0x140 [R/W] (PlumbBob, Update)
    f32 m_field_144;  // 0x144 [R/W] (PlumbBob, Update)
    u32 m_field_148;  // 0x148 [R/W] (PlumbBob, Update)
    u32 m_field_14C;  // 0x14C [R/W] (PlumbBob, Update)
    f32 m_field_150;  // 0x150 [R/W] (PlumbBob, Update)
    u32 m_particleVisibility;  // 0x154 [R/W] (Draw, EnableDraw, PlumbBob, ...)
    u32 m_state_158;  // 0x158 [R/W] (PlumbBob, SetState, Update)
    u32 m_field_15C;  // 0x15C [R/W] (PlumbBob, Update)
    u32 m_field_160;  // 0x160 [R/W] (PlumbBob, Update)
    u32 m_scaleFromTween;  // 0x164 [R/W] (Draw, DrawShadow, PlumbBob, ...)
    u32 m_state_168;  // 0x168 [R/W] (PlumbBob, SetState, Update)
    u32 m_field_16C;  // 0x16C [W] (PlumbBob, Shutdown)
    u32 m_field_170;  // 0x170 [W] (PlumbBob)
    u8 _pad_174[0x40];  // 0x174
    u32 m_field_1B4;  // 0x1B4 [W] (PlumbBob)
    u8 _pad_1B8[0x10];  // 0x1B8
    u32 m_field_1C8;  // 0x1C8 [W] (PlumbBob)
    u8 _pad_1CC[0x28];  // 0x1CC
    u32 m_particleVisibility_1F4;  // 0x1F4 [R/W] (AddParticleSystem, DestroyParticleSystems, PlumbBob, ...)
    u32 m_field_1F8;  // 0x1F8 [R/W] (Update)
    u8 _pad_1FC[0x21C];  // 0x1FC
    f32 m_field_418;  // 0x418 [R] (Draw)
    u8 _pad_41C[0x20];  // 0x41C
    f32 m_field_43C;  // 0x43C [R] (Draw)
};

#endif // PLUMBBOB_H
