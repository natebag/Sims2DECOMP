#ifndef EISPOTLIGHT_H
#define EISPOTLIGHT_H

#include "types.h"

// EISpotLight - struct layout extracted from assembly analysis
// Estimated minimum size: 0xE0 (224 bytes)
// 11 known fields (7 named), 34 methods

class EISpotLight {
public:
    // Constructors / Destructors
    EISpotLight(void)  // 0x8062B87C
    ~EISpotLight(void);  // 0x8062C340

    // Methods
    void Setup(void);  // 0x8062BB84 (724B)
    void Write(EStream &);  // 0x8062B988 (184B)
    void Read(EStream &);  // 0x8062BA40 (324B)
    /* ? */ GetReadVersion(void);  // 0x8062C5BC (52B)
    void SafeDelete(void);  // 0x8062C45C (108B)
    /* ? */ GetTypeInfo(void);  // 0x8062C4C8 (44B)
    /* ? */ GetTypeName(void);  // 0x8062C4F4 (52B)
    /* ? */ GetTypeKey(void);  // 0x8062C528 (52B)
    /* ? */ GetTypeVersion(void);  // 0x8062C55C (56B)
    void RegisterType(unsigned short);  // 0x8062C5F0 (116B)
    void New(void);  // 0x8062C380 (80B)
    void Construct(EISpotLight *);  // 0x8062C3D0 (80B)
    void Destruct(EISpotLight *);  // 0x8062C420 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8062C594 (40B)
    void CreateCopy(void);  // 0x8062C664 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (EISpotLight)
    u8 _pad_004[0x14];  // 0x004
    u32 m_field_018;  // 0x018 [R] (Read, Write)
    u8 _pad_01C[0x90];  // 0x01C
    u32 m_field_0AC;  // 0x0AC [W] (EISpotLight)
    u8 _pad_0B0[8];  // 0x0B0
    f32 m_field_0B8;  // 0x0B8 [W] (EISpotLight)
    u8 _pad_0BC[8];  // 0x0BC
    f32 m_field_0C4;  // 0x0C4 [R/W] (EISpotLight, Write)
    f32 m_up;  // 0x0C8 [R/W] (EISpotLight, Setup, Write)
    f32 m_up_0CC;  // 0x0CC [R/W] (EISpotLight, Setup, Write)
    f32 m_up_0D0;  // 0x0D0 [R/W] (EISpotLight, Setup, Write)
    u32 m_up_0D4;  // 0x0D4 [R/W] (EISpotLight, Read, Setup, ...)
    f32 m_up_0D8;  // 0x0D8 [W] (Setup)
    f32 m_up_0DC;  // 0x0DC [W] (Setup)
};

#endif // EISPOTLIGHT_H
