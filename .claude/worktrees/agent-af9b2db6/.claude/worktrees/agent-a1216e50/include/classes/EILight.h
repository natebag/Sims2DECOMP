#ifndef EILIGHT_H
#define EILIGHT_H

#include "types.h"

// EILight - struct layout extracted from assembly analysis
// Estimated minimum size: 0xAC (172 bytes)
// 16 known fields (5 named), 74 methods

class EILight {
public:
    // Constructors / Destructors
    EILight(void)  // 0x80618E5C
    ~EILight(void);  // 0x8061BD74

    // Methods
    void SetIntensity(float);  // 0x8061C430 (40B)
    void SetColor(EVec3 &);  // 0x8061C484 (68B)
    void SetIntensityScale(EVec3 &);  // 0x8061C30C (68B)
    void Enable(bool);  // 0x8061C4F4 (40B)
    void UseScaleIntensity(bool);  // 0x8061C350 (40B)
    /* ? */ GetColor(void);  // 0x8061C4C8 (44B)
    /* ? */ GetIntensity(void);  // 0x8061C458 (44B)
    void Read(EStream &);  // 0x8061904C (304B)
    void Write(EStream &);  // 0x80618FA0 (172B)
    void Init(void);  // 0x8061917C (108B)
    void CalcFullIntensityLightOnPoint(EVec3 &, float &);  // 0x8061C170 (140B)
    /* ? */ GetPosition(EVec3 &);  // 0x8061C378 (104B)
    bool IsEnabled(void);  // 0x8061C51C (44B)
    /* ? */ GetFalloffEnd(void);  // 0x8061C548 (44B)
    /* ? */ GetReadVersion(void);  // 0x8061BFF0 (52B)
    /* ? */ GetScaledIntColor(float, unsigned int *);  // 0x806191E8 (408B)
    /* ? */ GetScaledIntensity(void);  // 0x80619380 (244B)
    void TestOverlap(EInstance *);  // 0x80619474 (252B)
    void SafeDelete(void);  // 0x8061BE90 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8061BEFC (44B)
    /* ? */ GetTypeName(void);  // 0x8061BF28 (52B)
    /* ? */ GetTypeKey(void);  // 0x8061BF5C (52B)
    /* ? */ GetTypeVersion(void);  // 0x8061BF90 (56B)
    void LightingParameters(EVec3 &, float &, EVec3 &, EVec3 &);  // 0x8061C0DC (148B)
    void Setup(void);  // 0x8061C1FC (132B)
    /* ? */ GetLightType(void);  // 0x8061C280 (140B)
    void RegisterType(unsigned short);  // 0x8061C024 (116B)
    void New(void);  // 0x8061BDB4 (80B)
    void Construct(EILight *);  // 0x8061BE04 (80B)
    void Destruct(EILight *);  // 0x8061BE54 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8061BFC8 (40B)
    void CreateCopy(void);  // 0x8061C098 (68B)
    /* ? */ GetIntensityScale(void);  // 0x8061C3E0 (80B)
    void SetHaveLightsChanged(bool);  // 0x8061C574 (40B)
    void HaveLightsChanged(void);  // 0x8061C59C (44B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_scaledIntensity;  // 0x000 [W] (EILight, GetScaledIntensity)
    f32 m_scaledIntensity_004;  // 0x004 [W] (GetScaledIntensity)
    f32 m_scaledIntensity_008;  // 0x008 [W] (GetScaledIntensity)
    u8 _pad_00C[0x30];  // 0x00C
    u32 m_field_03C;  // 0x03C [R] (TestOverlap)
    u8 _pad_040[8];  // 0x040
    u32 m_field_048;  // 0x048 [R] (TestOverlap)
    u8 _pad_04C[0x10];  // 0x04C
    u32 m_field_05C;  // 0x05C [R/W] (EILight)
    u8 _pad_060[0x1C];  // 0x060
    u32 m_field_07C;  // 0x07C [R/W] (EILight, Read, Write)
    u32 m_field_080;  // 0x080 [R/W] (EILight, Read, Write)
    u32 m_field_084;  // 0x084 [R/W] (EILight, Write)
    u32 m_field_088;  // 0x088 [R/W] (EILight, Read, Write)
    f32 m_scaledIntColor;  // 0x08C [R/W] (EILight, GetScaledIntColor, Write)
    f32 m_scaledIntColor_090;  // 0x090 [R/W] (EILight, GetScaledIntColor)
    u8 _pad_094[8];  // 0x094
    f32 m_field_09C;  // 0x09C [W] (EILight)
    f32 m_field_0A0;  // 0x0A0 [W] (EILight)
    f32 m_field_0A4;  // 0x0A4 [W] (EILight)
    u32 m_field_0A8;  // 0x0A8 [W] (EILight)
};

#endif // EILIGHT_H
