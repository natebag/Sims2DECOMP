#ifndef EIPOINTLIGHT_H
#define EIPOINTLIGHT_H

#include "types.h"

// EIPointLight - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD0 (208 bytes)
// 17 known fields (11 named), 48 methods

class EIPointLight {
public:
    // Constructors / Destructors
    EIPointLight(void)  // 0x8062496C
    ~EIPointLight(void);  // 0x806277B4

    // Methods
    void SetPosition(EVec3 &);  // 0x80624F04 (272B)
    void Setup(void);  // 0x80625014 (224B)
    void Write(EStream &);  // 0x80624A38 (132B)
    void Read(EStream &);  // 0x80624ABC (264B)
    /* ? */ GetReadVersion(void);  // 0x80627A30 (52B)
    void CalcFullIntensityLightOnPoint(EVec3 &, float &);  // 0x80624BC4 (336B)
    void LightingParameters(EVec3 &, float &, EVec3 &, EVec3 &);  // 0x80624D14 (496B)
    void SafeDelete(void);  // 0x806278D0 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8062793C (44B)
    /* ? */ GetTypeName(void);  // 0x80627968 (52B)
    /* ? */ GetTypeKey(void);  // 0x8062799C (52B)
    /* ? */ GetTypeVersion(void);  // 0x806279D0 (56B)
    /* ? */ GetLightType(void);  // 0x80627B1C (40B)
    /* ? */ GetPosition(EVec3 &);  // 0x80627B44 (68B)
    /* ? */ GetFalloffEnd(void);  // 0x80627B88 (44B)
    void RegisterType(unsigned short);  // 0x80627A64 (116B)
    void New(void);  // 0x806277F4 (80B)
    void Construct(EIPointLight *);  // 0x80627844 (80B)
    void Destruct(EIPointLight *);  // 0x80627894 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x80627A08 (40B)
    void CreateCopy(void);  // 0x80627AD8 (68B)
    /* ? */ GetRoomId(void);  // 0x80627BB4 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (EIPointLight, LightingParameters)
    u32 m_up;  // 0x004 [W] (Setup)
    u32 m_up_008;  // 0x008 [W] (Setup)
    u8 _pad_00C[0xC];  // 0x00C
    u32 m_field_018;  // 0x018 [R] (Read, Write)
    u32 m_position;  // 0x01C [R] (SetPosition)
    u8 _pad_020[8];  // 0x020
    u32 m_position_028;  // 0x028 [R] (SetPosition)
    u8 _pad_02C[0x60];  // 0x02C
    f32 m_field_08C;  // 0x08C [R] (CalcFullIntensityLightOnPoint, LightingParameters)
    f32 m_field_090;  // 0x090 [R] (LightingParameters)
    u8 _pad_094[8];  // 0x094
    f32 m_field_09C;  // 0x09C [R] (LightingParameters)
    u8 _pad_0A0[0xC];  // 0x0A0
    f32 m_position_0AC;  // 0x0AC [R/W] (CalcFullIntensityLightOnPoint, EIPointLight, SetPosition)
    f32 m_field_0B0;  // 0x0B0 [R] (CalcFullIntensityLightOnPoint)
    u8 _pad_0B4[4];  // 0x0B4
    u32 m_position_0B8;  // 0x0B8 [R/W] (EIPointLight, SetPosition)
    u32 m_position_0BC;  // 0x0BC [R/W] (EIPointLight, SetPosition)
    u32 m_position_0C0;  // 0x0C0 [R/W] (EIPointLight, SetPosition)
    f32 m_field_0C4;  // 0x0C4 [R/W] (EIPointLight, Write)
    f32 m_up_0C8;  // 0x0C8 [R/W] (CalcFullIntensityLightOnPoint, EIPointLight, LightingParameters, ...)
    u32 m_up_0CC;  // 0x0CC [R/W] (CalcFullIntensityLightOnPoint, EIPointLight, Read, ...)
};

#endif // EIPOINTLIGHT_H
