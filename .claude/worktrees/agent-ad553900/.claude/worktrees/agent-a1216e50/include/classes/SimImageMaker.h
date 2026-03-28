#ifndef SIMIMAGEMAKER_H
#define SIMIMAGEMAKER_H

#include "types.h"

// SimImageMaker - struct layout extracted from assembly analysis
// Estimated minimum size: 0x53E4 (21476 bytes)
// 32 known fields (15 named), 41 methods

class SimImageMaker {
public:
    // Constructors / Destructors
    SimImageMaker(void)  // 0x801518D8
    ~SimImageMaker(void);  // 0x801519BC

    // Methods
    void SetGender(bool);  // 0x80151D14 (44B)
    void SetPortraitModels(SimModel *);  // 0x80151E34 (368B)
    void CreateImage(void);  // 0x801521A8 (1676B)
    void SetModel(eBodyPartS2C, EIStaticModel *);  // 0x80151D6C (200B)
    void UpdateRepShaders(int);  // 0x80153C58 (1420B)
    void Init(void);  // 0x80151A24 (64B)
    void Shutdown(void);  // 0x80151A64 (104B)
    void SetToDefaultValues(void);  // 0x80151B14 (512B)
    void Reset(void);  // 0x80151ACC (72B)
    void SetSkinShader(EShader *);  // 0x80151D40 (44B)
    void OverrideImageSize(unsigned int, unsigned int, unsigned int);  // 0x80151FA4 (68B)
    void OverrideLights(ELights &);  // 0x80151FE8 (136B)
    void OverridePose(unsigned int, EVec3 &, EVec3 &, EVec3 &, float);  // 0x80152070 (176B)
    void OverrideBackground(unsigned int);  // 0x80152120 (136B)
    void CreateImage32x32(void);  // 0x801541E4 (1200B)
    void InitWindow(E3DWindow &, ERC *);  // 0x80152834 (648B)
    void PoseSim(ERC *);  // 0x80152ABC (476B)
    void CopyToFinalImage(ETexture *);  // 0x80152C98 (4032B)
    void SetSepia(bool);  // 0x80465A5C (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CopyToFinalImage, CreateImage, CreateImage32x32, ...)
    u8 m_field_001;  // 0x001 [R/W] (CopyToFinalImage)
    u16 m_field_002;  // 0x002 [R/W] (CopyToFinalImage, CreateImage)
    u8 m_field_003;  // 0x003 [W] (CopyToFinalImage)
    f32 m_toDefaultValues_004;  // 0x004 [R/W] (CopyToFinalImage, CreateImage, InitWindow, ...)
    u16 m_field_006;  // 0x006 [R] (CopyToFinalImage, CreateImage)
    f32 m_toDefaultValues_008;  // 0x008 [R/W] (CopyToFinalImage, CreateImage, CreateImage32x32, ...)
    u8 m_field_00B;  // 0x00B [R] (CopyToFinalImage)
    u32 m_toDefaultValues_00C;  // 0x00C [R/W] (CreateImage, OverrideLights, SetToDefaultValues, ...)
    u32 m_field_010;  // 0x010 [W] (OverrideLights)
    u32 m_field_014;  // 0x014 [R/W] (CopyToFinalImage, OverrideLights)
    u32 m_field_018;  // 0x018 [W] (InitWindow)
    u32 m_field_01C;  // 0x01C [W] (InitWindow)
    u32 m_field_020;  // 0x020 [R] (CreateImage, PoseSim)
    u32 m_field_024;  // 0x024 [R] (CopyToFinalImage)
    u8 _pad_028[0xC];  // 0x028
    u32 m_field_034;  // 0x034 [R] (CreateImage, PoseSim)
    u8 _pad_038[0x38];  // 0x038
    u32 m_field_070;  // 0x070 [R] (CreateImage)
    u8 _pad_074[0x14];  // 0x074
    u32 m_field_088;  // 0x088 [R/W] (PoseSim, SimImageMaker)
    u32 m_field_08C;  // 0x08C [R/W] (CreateImage, SimImageMaker)
    u8 _pad_090[0x60];  // 0x090
    u32 m_field_0F0;  // 0x0F0 [R] (CreateImage)
    u8 _pad_0F4[4];  // 0x0F4
    u32 m_toDefaultValues_0F8;  // 0x0F8 [W] (SetToDefaultValues)
    u8 _pad_0FC[0xEC];  // 0x0FC
    u32 m_toDefaultValues_1E8;  // 0x1E8 [W] (SetToDefaultValues)
    u32 m_toDefaultValues_1EC;  // 0x1EC [W] (SetToDefaultValues)
    f32 m_toDefaultValues_1F0;  // 0x1F0 [W] (SetToDefaultValues, SimImageMaker)
    u8 _pad_1F4[8];  // 0x1F4
    f32 m_toDefaultValues_1FC;  // 0x1FC [W] (SetToDefaultValues, SimImageMaker)
    u8 _pad_200[8];  // 0x200
    f32 m_toDefaultValues_208;  // 0x208 [W] (SetToDefaultValues, SimImageMaker)
    u8 _pad_20C[8];  // 0x20C
    f32 m_toDefaultValues_214;  // 0x214 [R/W] (InitWindow, SetToDefaultValues, SimImageMaker)
    u32 m_toDefaultValues_218;  // 0x218 [R/W] (PoseSim, SetToDefaultValues, SimImageMaker)
    u32 m_field_21C;  // 0x21C [R/W] (CopyToFinalImage, OverrideBackground, Shutdown, ...)
    u8 _pad_220[0x1AE8];  // 0x220
    u32 m_toDefaultValues_1D08;  // 0x1D08 [R] (SetToDefaultValues)
    u8 _pad_1D0C[0x368C];  // 0x1D0C
    f32 m_repShaders;  // 0x5398 [R] (UpdateRepShaders)
    u8 _pad_539C[0x44];  // 0x539C
    f32 m_repShaders_53E0;  // 0x53E0 [R] (UpdateRepShaders)
};

#endif // SIMIMAGEMAKER_H
