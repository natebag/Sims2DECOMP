#ifndef EMITTER_H
#define EMITTER_H

#include "types.h"

// Emitter - struct layout extracted from assembly analysis
// Estimated minimum size: 0xBC (188 bytes)
// 18 known fields (3 named), 40 methods

class Emitter {
public:
    // Constructors / Destructors
    Emitter(void)  // 0x80656DB4
    ~Emitter(void);  // 0x80656E20

    // Methods
    void UnReg(psystem *, bool);  // 0x80656B90 (140B)
    /* ? */ Get(void);  // 0x80656D88 (44B)
    void SetState(int, int);  // 0x80656C6C (212B)
    void EmitterSetPostDestroyCallback(void (*);  // 0x80657000 (144B)
    void Reg(psystem *, bool);  // 0x80656B0C (132B)
    void SetMatrix(float *);  // 0x80656C1C (80B)
    void VisibilityTest(E3DWindow &);  // 0x80657268 (44B)
    void Draw(ELevelDrawData &);  // 0x80657294 (356B)
    /* ? */ GetInstName(EInstance::InstType &);  // 0x806573F8 (120B)
    void SetSortPos(EVec3 &);  // 0x80657170 (72B)
    void SetScale(float);  // 0x806571B8 (48B)
    void SetCallbacks(void (*);  // 0x80656E94 (364B)
    void Create(char *, float *, pemitterinfo *, void (*);  // 0x806569BC (260B)
    void Destroy(void);  // 0x80656AC0 (76B)
    /* ? */ GetNumActiveParticles(void);  // 0x80656D40 (72B)
    void EmitterSetIntervalCallback(void (*);  // 0x80657090 (152B)
    void Reset(void);  // 0x80657128 (72B)
    void PEmitterSubmitParticlesCB(ELevelDrawData &, EOrderTableData *);  // 0x806571E8 (128B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Draw, Emitter, ~Emitter)
    u32 m_state;  // 0x004 [R] (SetState, UnReg)
    u8 _pad_008[0x58];  // 0x008
    f32 m_field_060;  // 0x060 [W] (Create)
    f32 m_field_064;  // 0x064 [W] (Create)
    u32 m_field_068;  // 0x068 [W] (Create)
    u32 m_field_06C;  // 0x06C [W] (Create)
    u32 m_field_070;  // 0x070 [W] (Create)
    u8 _pad_074[8];  // 0x074
    u32 m_matrix;  // 0x07C [R/W] (Draw, Emitter, EmitterSetIntervalCallback, ...)
    u32 m_field_080;  // 0x080 [W] (Create)
    u8 _pad_084[8];  // 0x084
    u32 m_field_08C;  // 0x08C [W] (Draw, Emitter)
    u32 m_field_090;  // 0x090 [W] (Draw)
    u32 m_field_094;  // 0x094 [W] (Draw)
    u8 _pad_098[8];  // 0x098
    u32 m_field_0A0;  // 0x0A0 [W] (Draw)
    u8 _pad_0A4[4];  // 0x0A4
    u32 m_field_0A8;  // 0x0A8 [W] (PEmitterSubmitParticlesCB)
    u32 m_field_0AC;  // 0x0AC [W] (PEmitterSubmitParticlesCB)
    u32 m_field_0B0;  // 0x0B0 [W] (Draw)
    u32 m_field_0B4;  // 0x0B4 [W] (PEmitterSubmitParticlesCB)
    u32 m_field_0B8;  // 0x0B8 [W] (PEmitterSubmitParticlesCB)
};

#endif // EMITTER_H
