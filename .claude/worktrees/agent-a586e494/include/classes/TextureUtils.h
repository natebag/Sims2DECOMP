#ifndef TEXTUREUTILS_H
#define TEXTUREUTILS_H

#include "types.h"

// TextureUtils - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1B (27 bytes)
// 5 known fields (0 named), 36 methods

class TextureUtils {
public:
    // Methods
    void ColorToArray32(unsigned int, unsigned char *);  // 0x80157110 (96B)
    void ArrayToColor32(unsigned char *, unsigned int *);  // 0x80157170 (96B)
    void ArrayToColor16(unsigned char *, unsigned short *);  // 0x801571D0 (112B)
    /* ? */ GetAlpha(unsigned int);  // 0x8016EAF4 (44B)
    void PrepareTextureForUpdateBegin(ETexture *);  // 0x8082AC04 (168B)
    void PostUpdateEnd(ETexture *, bool);  // 0x8082ACAC (128B)
    void VerticalFlip(ETexture *);  // 0x80829F1C (544B)
    void MakeTextureSepiaTone(ETexture *);  // 0x8082A13C (820B)
    void CopyTexture32To32Half(ETexture *, ETexture *, unsigned char, unsigned int);  // 0x80829954 (1480B)
    void LoadTexture(unsigned int, ETexture *);  // 0x8082808C (836B)
    void CopyTexture32To8(ETexture *, ETexture *);  // 0x808283D0 (1732B)
    void CopyTexture32To32(ETexture *, ETexture *);  // 0x80828F98 (1092B)
    void BlendPixels32(unsigned int, unsigned int);  // 0x8082AD2C (496B)
    void CopyTexture8To32(ETexture *, ETexture *);  // 0x80828A94 (1284B)
    void CopyTexture8To8(ETexture *, ETexture *);  // 0x808293DC (1400B)
    void AveragePixels32(unsigned int, unsigned int, unsigned int, unsigned int);  // 0x8082B180 (284B)
    void ColorToArray8(unsigned char, unsigned char *);  // 0x8082B0B8 (104B)
    void ConvertColorArrayToSepia(unsigned char *, unsigned char *);  // 0x8082A470 (428B)
    void ArrayToColor8(unsigned char *, unsigned char *);  // 0x8082B120 (96B)
    void ColorToArray16A(unsigned short, unsigned char *);  // 0x8082AFDC (112B)
    void ArrayToColor16A(unsigned char *, unsigned short *);  // 0x8082B04C (108B)
    void SwapRB(ETexture *);  // 0x8082A61C (1512B)
    void ArrayToWin32Color(unsigned char *, unsigned int *);  // 0x8082D10C (96B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R/W] (ConvertColorArrayToSepia, CopyTexture32To8, SwapRB)
    u8 m_field_001;  // 0x001 [R] (ConvertColorArrayToSepia, CopyTexture32To8)
    u8 m_field_002;  // 0x002 [R] (ConvertColorArrayToSepia, CopyTexture32To8)
    u8 m_field_003;  // 0x003 [R] (ConvertColorArrayToSepia, CopyTexture32To8)
    u8 _pad_004[0x16];  // 0x004
    u8 m_field_01A;  // 0x01A [R] (LoadTexture)
};

#endif // TEXTUREUTILS_H
