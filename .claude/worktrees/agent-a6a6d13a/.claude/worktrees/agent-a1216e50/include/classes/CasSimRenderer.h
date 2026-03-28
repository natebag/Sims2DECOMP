#ifndef CASSIMRENDERER_H
#define CASSIMRENDERER_H

#include "types.h"

// CasSimRenderer - struct layout extracted from assembly analysis
// Estimated minimum size: 0x218 (536 bytes)
// 16 known fields (8 named), 48 methods

class CasSimRenderer {
public:
    // Constructors / Destructors
    CasSimRenderer(void)  // 0x80461150
    ~CasSimRenderer(void);  // 0x804611D4

    // Methods
    /* ? */ GetNumActiveBodyModels(void);  // 0x80461478 (148B)
    /* ? */ GetNumBodyModels(eBodyPartS2C);  // 0x80461F14 (92B)
    /* ? */ GetNumTattooTextures(eTattooTextureTypeS2C);  // 0x80461F70 (92B)
    /* ? */ GetIconTextureId(eBodyPartS2C, unsigned int);  // 0x80461FCC (100B)
    /* ? */ GetIconTattooTextureId(eTattooTextureTypeS2C, unsigned int);  // 0x80462030 (100B)
    void CreateFaceImage(unsigned int, unsigned int, unsigned int, bool, unsigned int);  // 0x80461E1C (248B)
    void SetFaceImage(ETexture *);  // 0x80462094 (312B)
    /* ? */ GetSimModel(void);  // 0x80465A30 (44B)
    void Init(void);  // 0x80461370 (180B)
    void SetPosition(EVec3 &, float);  // 0x80461424 (84B)
    void UpdateSkin(void);  // 0x8046150C (72B)
    void Draw(ERC *);  // 0x80461554 (636B)
    void DrawShadow(ERC *);  // 0x804617D0 (492B)
    void SetNextAnimation(unsigned int);  // 0x804619BC (256B)
    void CheckPending(void);  // 0x80461ABC (184B)
    void SetupSimCommon(void);  // 0x80461B74 (680B)
    void DrawFaceImage(ERC *);  // 0x804621CC (504B)
    void UpdateRepShaders(int);  // 0x804623C4 (232B)
    /* ? */ GetBonePos(unsigned int, EVec3 &);  // 0x804624AC (160B)
    /* ? */ GetPositionNum(void);  // 0x804659B4 (44B)
    void SetPositionNum(unsigned int);  // 0x804659E0 (40B)
    void SetSimRotation(float);  // 0x80465A08 (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CasSimRenderer, CreateFaceImage, Draw, ...)
    u32 m_upSimCommon_004;  // 0x004 [R/W] (CasSimRenderer, Init, SetupSimCommon, ...)
    u32 m_field_008;  // 0x008 [R] (Init)
    u32 m_field_00C;  // 0x00C [W] (CreateFaceImage)
    u8 _pad_010[0x74];  // 0x010
    u32 m_repShaders;  // 0x084 [R] (CreateFaceImage, UpdateRepShaders)
    u8 _pad_088[0xE8];  // 0x088
    u32 m_upSimCommon_170;  // 0x170 [R/W] (DrawShadow, Init, SetupSimCommon, ...)
    u8 _pad_174[0x14];  // 0x174
    s16 m_faceImage;  // 0x188 [R] (DrawFaceImage)
    u8 _pad_18A[2];  // 0x18A
    u32 m_faceImage_18C;  // 0x18C [R] (DrawFaceImage)
    u8 _pad_190[8];  // 0x190
    u32 m_field_198;  // 0x198 [R] (Draw)
    u8 _pad_19C[0x50];  // 0x19C
    u32 m_field_1EC;  // 0x1EC [W] (Init)
    u8 _pad_1F0[8];  // 0x1F0
    u32 m_field_1F8;  // 0x1F8 [W] (Init)
    u8 _pad_1FC[8];  // 0x1FC
    u32 m_nextAnimation;  // 0x204 [R/W] (CheckPending, Init, SetNextAnimation, ...)
    f32 m_field_208;  // 0x208 [R/W] (Draw, Init)
    f32 m_field_20C;  // 0x20C [R/W] (Draw, Init)
    u32 m_faceImage_210;  // 0x210 [R/W] (DrawFaceImage, Init, SetFaceImage, ...)
    u32 m_field_214;  // 0x214 [R] (Draw)
};

#endif // CASSIMRENDERER_H
