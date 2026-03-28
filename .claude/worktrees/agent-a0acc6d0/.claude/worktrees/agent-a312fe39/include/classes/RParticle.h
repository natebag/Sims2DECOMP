#ifndef RPARTICLE_H
#define RPARTICLE_H

#include "types.h"

// RParticle - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 5 known fields (1 named), 44 methods

class RParticle {
public:
    // Constructors / Destructors
    RParticle(void)  // 0x8087F190
    ~RParticle(void);  // 0x8087F22C

    // Methods
    /* ? */ GetData(void);  // 0x80882B10 (44B)
    void Deallocate(void);  // 0x8087F298 (116B)
    void DelRefSubResources(void);  // 0x8087F30C (252B)
    void AddRefSubResources(void);  // 0x8087F408 (384B)
    void TryIncrementSubResources(void);  // 0x8087F588 (596B)
    void PrepareData(void);  // 0x8087F7DC (2192B)
    void Load(EFile *, unsigned int);  // 0x8088006C (1864B)
    void Refresh(EFile *);  // 0x808807B4 (1256B)
    void SafeDelete(void);  // 0x80882808 (108B)
    /* ? */ GetTypeInfo(void);  // 0x80882874 (44B)
    /* ? */ GetTypeName(void);  // 0x808828A0 (52B)
    /* ? */ GetTypeKey(void);  // 0x808828D4 (52B)
    /* ? */ GetTypeVersion(void);  // 0x80882908 (56B)
    void RegisterType(unsigned short);  // 0x8088299C (116B)
    void New(void);  // 0x80882734 (76B)
    void Construct(RParticle *);  // 0x80882780 (76B)
    void Destruct(RParticle *);  // 0x808827CC (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x80882940 (40B)
    /* ? */ GetReadVersion(void);  // 0x80882968 (52B)
    void CreateCopy(void);  // 0x80882A10 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Deallocate, Load, RParticle, ...)
    u8 _pad_004[0xC];  // 0x004
    u32 m_field_010;  // 0x010 [R/W] (Load, Refresh)
    u32 m_field_014;  // 0x014 [R/W] (AddRefSubResources, Deallocate, DelRefSubResources, ...)
    u32 m_field_018;  // 0x018 [R/W] (AddRefSubResources, DelRefSubResources, Load, ...)
    u32 m_field_01C;  // 0x01C [R/W] (AddRefSubResources, Load, TryIncrementSubResources)
};

#endif // RPARTICLE_H
