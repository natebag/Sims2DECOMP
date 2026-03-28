#ifndef EIDIRLIGHT_H
#define EIDIRLIGHT_H

#include "types.h"

// EIDirLight - struct layout extracted from assembly analysis
// Estimated minimum size: 0xB0 (176 bytes)
// 4 known fields (1 named), 42 methods

class EIDirLight {
public:
    // Constructors / Destructors
    EIDirLight(void)  // 0x80617BF0
    ~EIDirLight(void);  // 0x80618178

    // Methods
    /* ? */ GetDir(void);  // 0x8061854C (44B)
    void SetDir(EVec3 &);  // 0x80618508 (68B)
    void Write(EStream &);  // 0x80617C6C (80B)
    void Read(EStream &);  // 0x80617CBC (204B)
    /* ? */ GetReadVersion(void);  // 0x806183F4 (52B)
    void LightingParameters(EVec3 &, float &, EVec3 &, EVec3 &);  // 0x80617D88 (264B)
    void Setup(void);  // 0x80617E90 (188B)
    void SafeDelete(void);  // 0x80618294 (108B)
    /* ? */ GetTypeInfo(void);  // 0x80618300 (44B)
    /* ? */ GetTypeName(void);  // 0x8061832C (52B)
    /* ? */ GetTypeKey(void);  // 0x80618360 (52B)
    /* ? */ GetTypeVersion(void);  // 0x80618394 (56B)
    /* ? */ GetLightType(void);  // 0x806184E0 (40B)
    void RegisterType(unsigned short);  // 0x80618428 (116B)
    void New(void);  // 0x806181B8 (80B)
    void Construct(EIDirLight *);  // 0x80618208 (80B)
    void Destruct(EIDirLight *);  // 0x80618258 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x806183CC (40B)
    void CreateCopy(void);  // 0x8061849C (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (EIDirLight)
    u8 _pad_004[0x88];  // 0x004
    f32 m_field_08C;  // 0x08C [R] (LightingParameters)
    f32 m_field_090;  // 0x090 [R] (LightingParameters)
    u8 _pad_094[0x18];  // 0x094
    f32 m_field_0AC;  // 0x0AC [R/W] (EIDirLight, LightingParameters)
};

#endif // EIDIRLIGHT_H
