#ifndef REFFECTSEMITTER_H
#define REFFECTSEMITTER_H

#include "types.h"

// REffectsEmitter - struct layout extracted from assembly analysis
// Estimated minimum size: 0x24 (36 bytes)
// 6 known fields (1 named), 56 methods

class REffectsEmitter {
public:
    // Constructors / Destructors
    REffectsEmitter(void)  // 0x8087E49C
    ~REffectsEmitter(void);  // 0x8087E508

    // Methods
    void Refreshed(void);  // 0x8087EFB4 (44B)
    void RefreshClear(void);  // 0x8087EFE0 (40B)
    void Deallocate(void);  // 0x8087E574 (140B)
    void DelRefSubResources(void);  // 0x8087E600 (76B)
    void AddRefSubResources(void);  // 0x8087E64C (120B)
    void TryIncrementSubResources(void);  // 0x8087E6C4 (136B)
    void Load(EFile *);  // 0x8087E74C (792B)
    void Refresh(EFile *);  // 0x8087EA64 (92B)
    void SafeDelete(void);  // 0x8087EC00 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8087EC6C (44B)
    /* ? */ GetTypeName(void);  // 0x8087EC98 (52B)
    /* ? */ GetTypeKey(void);  // 0x8087ECCC (52B)
    /* ? */ GetTypeVersion(void);  // 0x8087ED00 (56B)
    void RegisterType(unsigned short);  // 0x8087ED94 (116B)
    void New(void);  // 0x8087EB2C (76B)
    void Construct(REffectsEmitter *);  // 0x8087EB78 (76B)
    void Destruct(REffectsEmitter *);  // 0x8087EBC4 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8087ED38 (40B)
    /* ? */ GetReadVersion(void);  // 0x8087ED60 (52B)
    void CreateCopy(void);  // 0x8087EE08 (68B)
    void Alloc(unsigned long);  // 0x8087EE4C (80B)
    void AllocAligned(unsigned long, unsigned long);  // 0x8087EE9C (84B)
    void Free(void *);  // 0x8087EEF0 (64B)
    /* ? */ GetEmitterInitData(void);  // 0x8087EF30 (44B)
    /* ? */ GetParticleBirthData(void);  // 0x8087EF5C (44B)
    /* ? */ GetTexture(void);  // 0x8087EF88 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Deallocate, Load, REffectsEmitter, ...)
    u8 _pad_004[0xC];  // 0x004
    u32 m_field_010;  // 0x010 [R/W] (Load)
    u32 m_field_014;  // 0x014 [R/W] (AddRefSubResources, Deallocate, Load, ...)
    u32 m_field_018;  // 0x018 [R/W] (Deallocate, Load, REffectsEmitter)
    u32 m_field_01C;  // 0x01C [W] (AddRefSubResources, REffectsEmitter, TryIncrementSubResources)
    u32 m_field_020;  // 0x020 [W] (REffectsEmitter, Refresh)
};

#endif // REFFECTSEMITTER_H
