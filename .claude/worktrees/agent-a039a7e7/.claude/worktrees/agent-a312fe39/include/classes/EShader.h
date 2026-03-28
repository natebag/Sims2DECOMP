#ifndef ESHADER_H
#define ESHADER_H

#include "types.h"

// EShader - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8DC (2268 bytes)
// 36 known fields (10 named), 100 methods

class EShader {
public:
    // Constructors / Destructors
    EShader(void)  // 0x807D3690
    ~EShader(void);  // 0x807D3754

    // Methods
    void UpdateAll(float);  // 0x807D3B84 (204B)
    bool IsValid(void);  // 0x807D6204 (64B)
    /* ? */ GetTexture(int);  // 0x807D40DC (176B)
    /* ? */ GetMaterial(void);  // 0x807D5D6C (44B)
    /* ? */ GetShaderDef(void);  // 0x807D6014 (44B)
    /* ? */ GetName(void);  // 0x807D6164 (72B)
    bool IsAlphaShader(void);  // 0x807D60F4 (72B)
    void SetShadowAlpha(float);  // 0x807D51A8 (32B)
    void RemoveFromUpdateList(void);  // 0x807D3B08 (124B)
    void Create(EShaderDef &);  // 0x807D3844 (220B)
    void AddToUpdateList(void);  // 0x807D3A7C (140B)
    void Clone(void);  // 0x807D3920 (348B)
    void Update(float);  // 0x807D3C50 (924B)
    void ChangeMaterial(EMaterial &);  // 0x807D3FEC (112B)
    void UseOverrideTexture(unsigned char);  // 0x807D405C (128B)
    void UsesMipMapping(void);  // 0x807D418C (388B)
    void Validate(void);  // 0x807D4310 (524B)
    void SetTransform(ERC *);  // 0x807D451C (1484B)
    void SetScrollSpeed(EVec2 &, int, bool);  // 0x807D4AE8 (604B)
    /* ? */ GetWindowName(void);  // 0x807D4D44 (156B)
    /* ? */ GetMixinSize(void);  // 0x807D4DE0 (48B)
    /* ? */ GetMixinInfo(char *);  // 0x807D4E10 (56B)
    void AddTuning(unsigned int, CUIWindow *, int);  // 0x807D4E48 (144B)
    void RemoveTuning(unsigned int, CUIWindow *, int);  // 0x807D4ED8 (184B)
    void LoadAllTuning(unsigned int, CUIWindow *, int);  // 0x807D4F90 (188B)
    void SaveAllTuning(unsigned int, CUIWindow *, int);  // 0x807D504C (76B)
    void SetupWindow(CUIWindow *);  // 0x807D5098 (168B)
    void SelectForShadowMask(ERC *);  // 0x807D5140 (104B)
    void SetName(char *);  // 0x807D51C8 (84B)
    void Select(ERC *, unsigned int);  // 0x807D5CE0 (140B)
    void SetSurfaceProperty(unsigned int);  // 0x807D5D98 (48B)
    void ClearSurfaceProperty(unsigned int);  // 0x807D5DC8 (52B)
    void SetTexture(ETexture *, int);  // 0x807D5F50 (56B)
    void SetMultiTexture(ETexture *, int);  // 0x807D5F88 (60B)
    void SetAlternateShader(EShader *);  // 0x807D5FF0 (36B)
    void PrintSelectInfo(void);  // 0x807D613C (40B)
    void SetAlphaTestThreshold(float, int);  // 0x807D61AC (56B)
    void UpdateMaterialCoefficients(void);  // 0x807D61E4 (32B)
    void RemoveGeometryModes(unsigned int);  // 0x807D6244 (36B)
    void AddGeometryModes(unsigned int);  // 0x807D6268 (36B)
    bool IsSurface(unsigned int);  // 0x807D5DFC (68B)
    /* ? */ GetSurfaceProperties(void);  // 0x807D5E40 (44B)
    bool CanColorBeModified(void);  // 0x807D5E6C (60B)
    /* ? */ GetModifiableColor(unsigned int);  // 0x807D5EA8 (168B)
    void UndoOverrideTexture(void);  // 0x807D5FC4 (44B)
    bool IsFacer(void);  // 0x807D6040 (84B)
    bool IsCylindricalFacer(void);  // 0x807D6094 (52B)
    /* ? */ GetShaderUpdate(void);  // 0x807D60C8 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_transform;  // 0x000 [R/W] (AddToUpdateList, EShader, SetScrollSpeed, ...)
    u8 m_field_001;  // 0x001 [W] (EShader)
    u16 m_field_002;  // 0x002 [W] (EShader)
    u32 m_texture;  // 0x004 [R/W] (AddToUpdateList, Create, EShader, ...)
    u32 m_field_008;  // 0x008 [W] (AddToUpdateList, EShader)
    u32 m_bIsAlphaShader;  // 0x00C [R/W] (AddToUpdateList, EShader, IsAlphaShader)
    f32 m_field_010;  // 0x010 [W] (AddToUpdateList, ChangeMaterial, EShader)
    f32 m_field_014;  // 0x014 [W] (AddToUpdateList, EShader)
    f32 m_field_018;  // 0x018 [W] (AddToUpdateList, EShader)
    u8 m_bIsAlphaShader_01C;  // 0x01C [R/W] (AddToUpdateList, EShader, IsAlphaShader)
    u8 m_bIsAlphaShader_01D;  // 0x01D [R/W] (EShader, IsAlphaShader)
    u8 m_field_01E;  // 0x01E [W] (EShader)
    u8 m_bIsAlphaShader_01F;  // 0x01F [R/W] (EShader, IsAlphaShader)
    u8 m_field_020;  // 0x020 [W] (AddToUpdateList, EShader)
    u8 m_field_021;  // 0x021 [W] (EShader)
    u8 m_field_022;  // 0x022 [W] (EShader)
    u8 m_field_023;  // 0x023 [W] (EShader)
    u8 m_field_024;  // 0x024 [R/W] (EShader, UsesMipMapping)
    u8 m_field_025;  // 0x025 [W] (EShader)
    u16 m_field_026;  // 0x026 [W] (EShader)
    u32 m_field_028;  // 0x028 [W] (EShader)
    u32 m_field_02C;  // 0x02C [W] (EShader)
    f32 m_field_030;  // 0x030 [R/W] (ChangeMaterial, EShader)
    u32 m_field_034;  // 0x034 [W] (EShader)
    u32 m_field_038;  // 0x038 [W] (EShader)
    u32 m_field_03C;  // 0x03C [W] (EShader)
    u8 _pad_040[0x28];  // 0x040
    u32 m_field_068;  // 0x068 [R] (Validate)
    u8 _pad_06C[0x1A];  // 0x06C
    u8 m_scrollSpeed;  // 0x086 [R/W] (SetScrollSpeed)
    u8 _pad_087[1];  // 0x087
    u8 m_field_088;  // 0x088 [R] (Validate)
    u8 _pad_089[0x5B];  // 0x089
    u32 m_field_0E4;  // 0x0E4 [R/W] (Clone, EShader, ~EShader)
    u32 m_transform_0E8;  // 0x0E8 [R/W] (AddToUpdateList, EShader, RemoveFromUpdateList, ...)
    u8 m_texture_0EC;  // 0x0EC [R/W] (Clone, EShader, GetTexture, ...)
    u8 m_field_0ED;  // 0x0ED [R/W] (Clone, EShader, Update)
    u16 m_field_0EE;  // 0x0EE [R/W] (Clone, EShader, Update)
    u32 m_field_0F0;  // 0x0F0 [R/W] (ChangeMaterial, EShader, UpdateAll, ...)
    u8 _pad_0F4[0x7E4];  // 0x0F4
    u32 m_all;  // 0x8D8 [R] (RemoveFromUpdateList, UpdateAll)
};

#endif // ESHADER_H
