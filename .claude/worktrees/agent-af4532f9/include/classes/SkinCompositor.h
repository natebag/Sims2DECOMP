#ifndef SKINCOMPOSITOR_H
#define SKINCOMPOSITOR_H

#include "types.h"

// SkinCompositor - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 10 known fields (6 named), 28 methods

class SkinCompositor {
public:
    // Static members (from map file)
    // static ??? s_fullAlphaValue;

    // Constructors / Destructors
    SkinCompositor(void)  // 0x80169D64
    ~SkinCompositor(void);  // 0x80169DF4

    // Methods
    void CreateSkinQuadrantPrecomposited(ERTexture *, unsigned int, bool);  // 0x8016A07C (484B)
    void CreateSkinQuadrantHiRes(ERTexture *, unsigned char, CasSimDescriptionS2C *);  // 0x80169FBC (96B)
    void CreateSkinQuadrantLoRes(ERTexture *, unsigned char, CasSimDescriptionS2C *);  // 0x8016A01C (96B)
    void Reset(void);  // 0x80169E4C (368B)
    void CreateSkin(ERTexture *, unsigned char, CasSimDescriptionS2C *, bool);  // 0x8016A260 (564B)
    void InitScratchpadTextures(unsigned short);  // 0x8016A494 (908B)
    void InitSkinTexture(void);  // 0x8016A820 (700B)
    void LoadAllTextureLayers(void);  // 0x8016AC14 (2504B)
    void FinalizeSkinTexture(void);  // 0x8016AADC (312B)
    /* ? */ GetTextureIDs(unsigned int &, unsigned int *, unsigned int *, unsigned int *);  // 0x8016B5DC (504B)
    void BlendTexture(eBodyPartS2C, unsigned int, unsigned int);  // 0x8016B7D4 (3560B)
    /* ? */ GetFinalReflectionMask(void);  // 0x8016C5BC (336B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_finalReflectionMask;  // 0x000 [R/W] (BlendTexture, GetFinalReflectionMask, InitScratchpadTextures, ...)
    u8 _pad_002[2];  // 0x002
    u32 m_field_004;  // 0x004 [R/W] (FinalizeSkinTexture, InitSkinTexture, SkinCompositor)
    u32 m_field_008;  // 0x008 [R/W] (BlendTexture, FinalizeSkinTexture, InitScratchpadTextures, ...)
    u32 m_finalReflectionMask_00C;  // 0x00C [R/W] (BlendTexture, GetFinalReflectionMask, LoadAllTextureLayers, ...)
    u32 m_field_010;  // 0x010 [R/W] (BlendTexture, CreateSkin, InitSkinTexture, ...)
    u32 m_textureIDs;  // 0x014 [R/W] (CreateSkin, GetTextureIDs, LoadAllTextureLayers, ...)
    u32 m_field_018;  // 0x018 [R/W] (CreateSkin, FinalizeSkinTexture, InitSkinTexture, ...)
    u8 m_textureIDs_01C;  // 0x01C [R/W] (BlendTexture, CreateSkin, GetTextureIDs, ...)
    u8 _pad_01D[3];  // 0x01D
    u32 m_finalReflectionMask_020;  // 0x020 [R/W] (BlendTexture, GetFinalReflectionMask, InitScratchpadTextures, ...)
    u32 m_textureIDs_024;  // 0x024 [R/W] (BlendTexture, CreateSkin, GetTextureIDs, ...)
};

#endif // SKINCOMPOSITOR_H
