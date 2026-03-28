#ifndef EIAMBLIGHT_H
#define EIAMBLIGHT_H

#include "types.h"

// EIAmbLight - struct layout extracted from assembly analysis
// Estimated minimum size: 0x94 (148 bytes)
// 3 known fields (1 named), 35 methods

class EIAmbLight {
public:
    // Constructors / Destructors
    EIAmbLight(void)  // 0x80068E8C
    ~EIAmbLight(void);  // 0x806175F8

    // Methods
    void CalcLightOnPoint(EVec3 &, EVec3 &);  // 0x8061716C (252B)
    void LightingParameters(EVec3 &, float &, EVec3 &, EVec3 &);  // 0x80617268 (280B)
    void Setup(void);  // 0x80617380 (180B)
    void SafeDelete(void);  // 0x80617714 (108B)
    /* ? */ GetTypeInfo(void);  // 0x80617780 (44B)
    /* ? */ GetTypeName(void);  // 0x806177AC (52B)
    /* ? */ GetTypeKey(void);  // 0x806177E0 (52B)
    /* ? */ GetTypeVersion(void);  // 0x80617814 (56B)
    /* ? */ GetLightType(void);  // 0x80617960 (40B)
    void RegisterType(unsigned short);  // 0x806178A8 (116B)
    void New(void);  // 0x80617638 (80B)
    void Construct(EIAmbLight *);  // 0x80617688 (80B)
    void Destruct(EIAmbLight *);  // 0x806176D8 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8061784C (40B)
    /* ? */ GetReadVersion(void);  // 0x80617874 (52B)
    void CreateCopy(void);  // 0x8061791C (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CalcLightOnPoint, New)
    u8 _pad_004[0x88];  // 0x004
    f32 m_field_08C;  // 0x08C [R] (CalcLightOnPoint, LightingParameters)
    f32 m_field_090;  // 0x090 [R] (CalcLightOnPoint, LightingParameters)
};

#endif // EIAMBLIGHT_H
