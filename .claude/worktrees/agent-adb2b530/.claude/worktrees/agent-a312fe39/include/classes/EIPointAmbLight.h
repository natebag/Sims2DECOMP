#ifndef EIPOINTAMBLIGHT_H
#define EIPOINTAMBLIGHT_H

#include "types.h"

// EIPointAmbLight - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC4 (196 bytes)
// 8 known fields (5 named), 34 methods

class EIPointAmbLight {
public:
    // Constructors / Destructors
    EIPointAmbLight(void)  // 0x80621B6C
    ~EIPointAmbLight(void);  // 0x80624398

    // Methods
    void Setup(void);  // 0x80621DAC (224B)
    void Write(EStream &);  // 0x80621C20 (132B)
    void Read(EStream &);  // 0x80621CA4 (264B)
    /* ? */ GetReadVersion(void);  // 0x80624614 (52B)
    void SafeDelete(void);  // 0x806244B4 (108B)
    /* ? */ GetTypeInfo(void);  // 0x80624520 (44B)
    /* ? */ GetTypeName(void);  // 0x8062454C (52B)
    /* ? */ GetTypeKey(void);  // 0x80624580 (52B)
    /* ? */ GetTypeVersion(void);  // 0x806245B4 (56B)
    void RegisterType(unsigned short);  // 0x80624648 (116B)
    void New(void);  // 0x806243D8 (80B)
    void Construct(EIPointAmbLight *);  // 0x80624428 (80B)
    void Destruct(EIPointAmbLight *);  // 0x80624478 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x806245EC (40B)
    void CreateCopy(void);  // 0x806246BC (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (EIPointAmbLight)
    u32 m_up;  // 0x004 [W] (Setup)
    u32 m_up_008;  // 0x008 [W] (Setup)
    u8 _pad_00C[0xC];  // 0x00C
    u32 m_field_018;  // 0x018 [R] (Read, Write)
    u8 _pad_01C[0x90];  // 0x01C
    u32 m_field_0AC;  // 0x0AC [W] (EIPointAmbLight)
    u8 _pad_0B0[8];  // 0x0B0
    f32 m_field_0B8;  // 0x0B8 [R/W] (EIPointAmbLight, Write)
    f32 m_up_0BC;  // 0x0BC [R/W] (EIPointAmbLight, Setup, Write)
    u32 m_up_0C0;  // 0x0C0 [R/W] (EIPointAmbLight, Read, Setup, ...)
};

#endif // EIPOINTAMBLIGHT_H
