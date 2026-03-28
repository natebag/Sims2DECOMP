#ifndef EIPORTALPOINTLIGHT_H
#define EIPORTALPOINTLIGHT_H

#include "types.h"

// EIPortalPointLight - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD8 (216 bytes)
// 15 known fields (8 named), 52 methods

class EIPortalPointLight {
public:
    // Constructors / Destructors
    EIPortalPointLight(void)  // 0x80627EF4
    ~EIPortalPointLight(void);  // 0x8062B1E8

    // Methods
    void SetPortal(EInstance *, bool);  // 0x80627FC4 (116B)
    /* ? */ GetLumina(void);  // 0x80627E8C (104B)
    void Setup(void);  // 0x80628498 (288B)
    void Write(EStream &);  // 0x80628038 (280B)
    void Read(EStream &);  // 0x80628150 (376B)
    /* ? */ GetReadVersion(void);  // 0x8062B464 (52B)
    void LightingParameters(EVec3 &, float &, EVec3 &, EVec3 &);  // 0x806282C8 (464B)
    void Update(void);  // 0x806285B8 (1240B)
    bool IsEnabled(void);  // 0x80628A90 (160B)
    void SafeDelete(void);  // 0x8062B304 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8062B370 (44B)
    /* ? */ GetTypeName(void);  // 0x8062B39C (52B)
    /* ? */ GetTypeKey(void);  // 0x8062B3D0 (52B)
    /* ? */ GetTypeVersion(void);  // 0x8062B404 (56B)
    /* ? */ GetLightType(void);  // 0x8062B550 (40B)
    bool IsPointLight(void);  // 0x8062B5A4 (40B)
    void RegisterType(unsigned short);  // 0x8062B498 (116B)
    void New(void);  // 0x8062B228 (80B)
    void Construct(EIPortalPointLight *);  // 0x8062B278 (80B)
    void Destruct(EIPortalPointLight *);  // 0x8062B2C8 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8062B43C (40B)
    void CreateCopy(void);  // 0x8062B50C (68B)
    /* ? */ GetPortal(void);  // 0x8062B578 (44B)
    /* ? */ GetRoomId(void);  // 0x8062B5CC (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (EIPortalPointLight, LightingParameters, Setup, ...)
    u8 _pad_004[0x14];  // 0x004
    u32 m_field_018;  // 0x018 [R] (Read, Write)
    u32 m_bIsEnabled;  // 0x01C [R/W] (IsEnabled, LightingParameters, Update)
    u32 m_bIsEnabled_020;  // 0x020 [R/W] (IsEnabled, LightingParameters, Update)
    u32 m_bIsEnabled_024;  // 0x024 [R/W] (IsEnabled, LightingParameters, Update)
    u32 m_bIsEnabled_028;  // 0x028 [R/W] (IsEnabled, LightingParameters, Update)
    u8 _pad_02C[0x30];  // 0x02C
    u32 m_field_05C;  // 0x05C [R/W] (EIPortalPointLight)
    u8 _pad_060[0x28];  // 0x060
    u32 m_bIsEnabled_088;  // 0x088 [R/W] (EIPortalPointLight, IsEnabled)
    f32 m_field_08C;  // 0x08C [R/W] (EIPortalPointLight, LightingParameters, Update)
    f32 m_field_090;  // 0x090 [R] (LightingParameters)
    u8 _pad_094[0x30];  // 0x094
    f32 m_field_0C4;  // 0x0C4 [R/W] (EIPortalPointLight, Write)
    f32 m_up_0C8;  // 0x0C8 [R/W] (EIPortalPointLight, LightingParameters, Setup, ...)
    u32 m_up_0CC;  // 0x0CC [R/W] (EIPortalPointLight, Read, Setup, ...)
    u32 m_field_0D0;  // 0x0D0 [R/W] (EIPortalPointLight, Update)
    u32 m_field_0D4;  // 0x0D4 [R/W] (EIPortalPointLight, Update)
};

#endif // EIPORTALPOINTLIGHT_H
