#ifndef ERSHADER_H
#define ERSHADER_H

#include "types.h"

// ERShader - struct layout extracted from assembly analysis
// Estimated minimum size: 0x17BC (6076 bytes)
// 41 known fields (14 named), 132 methods

class ERShader {
public:
    // Constructors / Destructors
    ERShader(void)  // 0x80866BC0
    ~ERShader(void);  // 0x80866D04

    // Methods
    void UpdateAll(float, int, int, int);  // 0x8086D268 (680B)
    /* ? */ GetShader(void);  // 0x80870418 (100B)
    void Select(ERC *, unsigned int);  // 0x8087092C (240B)
    void SelectForShadowMask(ERC *);  // 0x80870A1C (116B)
    /* ? */ GetRTextureForRenderPass(int);  // 0x808705C8 (60B)
    void ReplaceTexture(ERTexture *, int);  // 0x8086D81C (824B)
    void SetDefaultShaderState(int);  // 0x80869838 (44B)
    void InitDayNightShaders(int, int);  // 0x8086D510 (504B)
    void CreateEShaderForTexture(ETexture *);  // 0x80868CB4 (576B)
    void SupportsMultiShaderStates(void);  // 0x80870660 (56B)
    void SetShaderASyncForState(int);  // 0x8086A178 (352B)
    bool IsStateChangePending(void);  // 0x808707A4 (52B)
    /* ? */ GetMultiShaderStateID(int);  // 0x8086A08C (236B)
    /* ? */ GetCurrentGraphicsState(void);  // 0x80870774 (48B)
    bool HasTexture(unsigned int);  // 0x8086DE5C (300B)
    /* ? */ GetSupportDecal(void);  // 0x80870520 (116B)
    bool IsMultiShader(void);  // 0x808707D8 (52B)
    bool IsMultiTextureShader(void);  // 0x8087080C (124B)
    void Clone(unsigned int);  // 0x808690B0 (1928B)
    /* ? */ GetCurrentShader(void);  // 0x80870604 (92B)
    bool CanColorBeModified(void);  // 0x80870A90 (80B)
    /* ? */ GetModifiableColor(unsigned int);  // 0x80870AE0 (88B)
    void Deallocate(void);  // 0x80866D90 (472B)
    void DelRefSubResources(void);  // 0x80866F68 (1576B)
    void RemoveFromUpdateList(void);  // 0x8086C848 (124B)
    void DeallocateIncomingShader(void);  // 0x80867590 (580B)
    void AddRefSubResources(void);  // 0x808677D4 (2412B)
    void SetCurrentShaderForState(unsigned char);  // 0x80869D8C (328B)
    void AddToUpdateList(void);  // 0x8086C7BC (140B)
    void TryIncrementSubResources(void);  // 0x80868140 (2932B)
    void Refresh(EFile *);  // 0x80868EF4 (112B)
    void Load(EFile &);  // 0x80868F64 (332B)
    void DoLoad(EFile &, EShaderDef &);  // 0x8086A2D8 (3980B)
    void CreateCopy(void);  // 0x80870318 (68B)
    void DoLoadMultiShader(char *, EShaderDef &);  // 0x80869864 (1320B)
    void ChangeCurrentShader(ERShader *);  // 0x80869ED4 (440B)
    void OldLoad(EFile &, EShaderDef &);  // 0x8086B264 (4432B)
    void CopyShedData(EShaderDef &, char *);  // 0x8086C3B4 (592B)
    void CopyIntermediateShedData(EShaderDef &, char *);  // 0x8086C604 (440B)
    void Update(float, int, int, int);  // 0x8086C8C4 (484B)
    bool HasCommonTexture(ERShader *, ERShader *);  // 0x8086CAA8 (352B)
    void InterpolateShaders(float);  // 0x8086CCA0 (308B)
    void UpdateTimeOfDayShader(void);  // 0x8086CC48 (88B)
    void UpdateWeatherShader(int);  // 0x8086CC08 (64B)
    /* ? */ GetTimeState(void);  // 0x808708D4 (88B)
    void BlendCurrentShader(float);  // 0x8086CDD4 (1172B)
    bool IsDayNightShader(void);  // 0x80870594 (52B)
    void SetDayNightShaderToClosestTime(int, int);  // 0x8086D708 (276B)
    void SwapTexture(ERTexture *, int);  // 0x8086DB54 (776B)
    void SafeDelete(void);  // 0x80870110 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8087017C (44B)
    /* ? */ GetTypeName(void);  // 0x808701A8 (52B)
    /* ? */ GetTypeKey(void);  // 0x808701DC (52B)
    /* ? */ GetTypeVersion(void);  // 0x80870210 (56B)
    void DetachClone(void);  // 0x80870888 (76B)
    void RegisterType(unsigned short);  // 0x808702A4 (116B)
    void New(void);  // 0x8087003C (76B)
    void Construct(ERShader *);  // 0x80870088 (76B)
    void Destruct(ERShader *);  // 0x808700D4 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x80870248 (40B)
    /* ? */ GetReadVersion(void);  // 0x80870270 (52B)
    void SetSupportDecal(bool);  // 0x8087047C (164B)
    /* ? */ GetStateCount(void);  // 0x80870698 (92B)
    /* ? */ GetState(unsigned int);  // 0x808706F4 (128B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_bHasTexture;  // 0x000 [R/W] (AddRefSubResources, AddToUpdateList, Clone, ...)
    f32 m_field_004;  // 0x004 [R/W] (AddToUpdateList, BlendCurrentShader, Clone, ...)
    f32 m_field_008;  // 0x008 [R/W] (AddRefSubResources, AddToUpdateList, BlendCurrentShader, ...)
    f32 m_field_00C;  // 0x00C [R/W] (BlendCurrentShader, Clone, Load, ...)
    f32 m_field_010;  // 0x010 [R/W] (BlendCurrentShader, Clone, DoLoad, ...)
    f32 m_bHasTexture_014;  // 0x014 [R/W] (AddRefSubResources, BlendCurrentShader, ChangeCurrentShader, ...)
    f32 m_supportDecal;  // 0x018 [R/W] (AddRefSubResources, BlendCurrentShader, ChangeCurrentShader, ...)
    u8 m_field_01C;  // 0x01C [R/W] (BlendCurrentShader, Clone, DeallocateIncomingShader, ...)
    u8 m_field_01D;  // 0x01D [W] (Load)
    u8 m_field_01E;  // 0x01E [W] (Load)
    u8 m_field_01F;  // 0x01F [W] (Load)
    f32 m_field_020;  // 0x020 [R/W] (BlendCurrentShader, CreateEShaderForTexture, Load, ...)
    u8 m_field_021;  // 0x021 [W] (Load)
    u8 m_field_022;  // 0x022 [W] (Load)
    u8 m_field_023;  // 0x023 [W] (Load)
    u8 m_field_024;  // 0x024 [W] (Load)
    u8 m_field_025;  // 0x025 [W] (Load)
    u16 m_field_026;  // 0x026 [W] (Load)
    u32 m_field_028;  // 0x028 [W] (CreateEShaderForTexture, Load)
    f32 m_field_02C;  // 0x02C [W] (Clone, Load)
    f32 m_bHasTexture_030;  // 0x030 [R/W] (AddRefSubResources, BlendCurrentShader, ChangeCurrentShader, ...)
    u32 m_field_034;  // 0x034 [R/W] (AddRefSubResources, ChangeCurrentShader, Clone, ...)
    u32 m_bHasTexture_038;  // 0x038 [R/W] (AddRefSubResources, ChangeCurrentShader, Clone, ...)
    f32 m_field_03C;  // 0x03C [R/W] (BlendCurrentShader, Clone, DoLoadMultiShader, ...)
    f32 m_field_040;  // 0x040 [R] (AddRefSubResources, InterpolateShaders, TryIncrementSubResources, ...)
    u8 m_state;  // 0x044 [R] (AddRefSubResources, Clone, DoLoadMultiShader, ...)
    u8 _pad_045[3];  // 0x045
    u32 m_state_048;  // 0x048 [R] (AddRefSubResources, Clone, DoLoadMultiShader, ...)
    u32 m_multiShaderStateID;  // 0x04C [R] (Clone, DoLoadMultiShader, GetMultiShaderStateID, ...)
    u8 m_currentShaderForState;  // 0x050 [R/W] (Clone, DelRefSubResources, ERShader, ...)
    u8 _pad_051[3];  // 0x051
    u32 m_field_054;  // 0x054 [R/W] (AddToUpdateList, ERShader, RemoveFromUpdateList)
    s16 m_multiShaderStateID_058;  // 0x058 [R/W] (AddRefSubResources, BlendCurrentShader, Clone, ...)
    u8 _pad_05A[2];  // 0x05A
    u32 m_shaderASyncForState;  // 0x05C [R/W] (BlendCurrentShader, Clone, DeallocateIncomingShader, ...)
    f32 m_field_060;  // 0x060 [R/W] (Deallocate, DeallocateIncomingShader, ERShader, ...)
    u8 m_currentShaderForState_064;  // 0x064 [R/W] (AddRefSubResources, Clone, DelRefSubResources, ...)
    u8 m_shaderASyncForState_065;  // 0x065 [R/W] (Clone, ERShader, SetShaderASyncForState)
    u8 m_field_066;  // 0x066 [R/W] (Clone, ERShader, Update, ...)
    u8 m_field_067;  // 0x067 [R/W] (Clone, ERShader, Update, ...)
    u32 m_field_068;  // 0x068 [R/W] (BlendCurrentShader, Clone, Deallocate, ...)
    u8 _pad_06C[0x84];  // 0x06C
    u32 m_field_0F0;  // 0x0F0 [R] (AddRefSubResources, BlendCurrentShader, Clone, ...)
    u8 _pad_0F4[0x980];  // 0x0F4
    f32 m_field_A74;  // 0xA74 [R] (Clone)
    u8 _pad_A78[0xD40];  // 0xA78
    u32 m_all;  // 0x17B8 [R] (InitDayNightShaders, RemoveFromUpdateList, UpdateAll)
};

#endif // ERSHADER_H
