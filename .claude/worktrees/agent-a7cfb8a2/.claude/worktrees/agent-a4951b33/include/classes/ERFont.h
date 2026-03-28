#ifndef ERFONT_H
#define ERFONT_H

#include "types.h"

// ERFont - struct layout extracted from assembly analysis
// Estimated minimum size: 0xF4 (244 bytes)
// 18 known fields (8 named), 80 methods

class ERFont {
public:
    // Constructors / Destructors
    ERFont(void)  // 0x8084EDA8
    ~ERFont(void);  // 0x8084EE48

    // Methods
    void Select(ERC *);  // 0x80854208 (76B)
    void SetSize(float, float, bool);  // 0x8084F0AC (660B)
    void SetColor(EVec4 &);  // 0x80856A9C (68B)
    void Draw(ERC *, char *, EVec2 &, EFontAlignX, EFontAlignY, EVec2 *, EMat4 *, EFontMatrixType, fontFXcommand *, bool);  // 0x808537B8 (976B)
    void DrawDs(ERC *, char *, EVec2 &, EFontAlignX, EFontAlignY, EVec2 *, float, float, bool);  // 0x80853B88 (632B)
    /* ? */ GetStringSize(unsigned wchar_t *, EWindow *, bool);  // 0x80856A38 (100B)
    void Draw(ERC *, unsigned wchar_t *, EVec2 &, EFontAlignX, EFontAlignY, EVec2 *, EMat4 *, EFontMatrixType, fontFXcommand *, bool);  // 0x80856B58 (156B)
    /* ? */ GetColor(void);  // 0x80856B2C (44B)
    /* ? */ GetLineSpacing(EWindow *, bool);  // 0x80854254 (520B)
    void DrawDs(ERC *, unsigned wchar_t *, EVec2 &, EFontAlignX, EFontAlignY, EVec2 *, float, float, bool);  // 0x80853E00 (632B)
    void LoadFont(void);  // 0x80854078 (400B)
    /* ? */ GetStringSize(char *, EWindow *, bool);  // 0x808569D4 (100B)
    void SetColor(float);  // 0x80856AE0 (76B)
    void Deallocate(void);  // 0x8084EEC4 (128B)
    void Load(EFile &);  // 0x8084EF44 (360B)
    void SelectPage(ERC *, int);  // 0x8084F340 (268B)
    void DoDraw(void *, bool, bool, bool, EVec2 &, ERC *, EVec2 *, EWindow *, EMat4 *, EVec2 *, EFontMatrixType, fontFXcommand *);  // 0x8084F5CC (6760B)
    /* ? */ GetChar(void *, bool, int);  // 0x80856BF4 (92B)
    void ProcessFontFX(fontFXcommand *, EMat4 *, int);  // 0x8085445C (2344B)
    void DoDrawNormalize(void *, bool, bool, bool, EVec2 &, ERC *, EVec2 *, EWindow *, EMat4 *, EVec2 *, EFontMatrixType, fontFXcommand *);  // 0x80851034 (7256B)
    void DoGetStringSize(void *, bool, bool, EWindow *);  // 0x80852C8C (340B)
    void SnapPosToPixel(EVec2 &, bool, bool, EWindow *);  // 0x80852DE0 (460B)
    void SnapPosToPixelNormalize(EVec2 &, bool, bool, EWindow *);  // 0x80852FAC (868B)
    void DoDrawAlign(ERC *, void *, bool, EVec2, EFontAlignX, EFontAlignY, EVec2 *, EMat4 *, EFontMatrixType, fontFXcommand *, bool);  // 0x80853310 (1192B)
    void SafeDelete(void);  // 0x80856664 (108B)
    /* ? */ GetTypeInfo(void);  // 0x808566D0 (44B)
    /* ? */ GetTypeName(void);  // 0x808566FC (52B)
    /* ? */ GetTypeKey(void);  // 0x80856730 (52B)
    /* ? */ GetTypeVersion(void);  // 0x80856764 (56B)
    void RegisterType(unsigned short);  // 0x808567F8 (116B)
    void New(void);  // 0x80856590 (76B)
    void Construct(ERFont *);  // 0x808565DC (76B)
    void Destruct(ERFont *);  // 0x80856628 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8085679C (40B)
    /* ? */ GetReadVersion(void);  // 0x808567C4 (52B)
    void CreateCopy(void);  // 0x8085686C (68B)
    /* ? */ GetYSize(void);  // 0x8085697C (44B)
    /* ? */ GetAspect(void);  // 0x808569A8 (44B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [W] (DoGetStringSize, ERFont, ~ERFont)
    f32 m_field_004;  // 0x004 [W] (DoGetStringSize)
    u32 m_field_008;  // 0x008 [R] (SelectPage)
    u8 _pad_00C[4];  // 0x00C
    u32 m_field_010;  // 0x010 [R/W] (Load)
    u32 m_field_014;  // 0x014 [R] (SelectPage)
    u32 m_size;  // 0x018 [R] (Deallocate, Load, SetSize)
    u8 _pad_01C[8];  // 0x01C
    u32 m_lineSpacing;  // 0x024 [R] (DoDraw, DoDrawNormalize, GetLineSpacing)
    u32 m_lineSpacing_028;  // 0x028 [R] (DoDraw, DoDrawNormalize, GetLineSpacing)
    u32 m_field_02C;  // 0x02C [R] (DoDraw, DoDrawNormalize)
    u32 m_lineSpacing_030;  // 0x030 [R] (GetLineSpacing)
    u32 m_field_034;  // 0x034 [R] (DoDraw, DoDrawNormalize)
    u32 m_field_038;  // 0x038 [R] (DoDraw, DoDrawNormalize)
    u8 _pad_03C[0x10];  // 0x03C
    f32 m_size_04C;  // 0x04C [R/W] (DoDraw, DoDrawNormalize, ERFont, ...)
    f32 m_size_050;  // 0x050 [R/W] (DoDraw, DoDrawNormalize, ERFont, ...)
    u32 m_size_054;  // 0x054 [R/W] (DoDraw, DoDrawAlign, DoDrawNormalize, ...)
    f32 m_ds;  // 0x058 [R/W] (DrawDs, ERFont)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (DoDraw, DoDrawNormalize, ERFont, ...)
    u8 _pad_06C[0x84];  // 0x06C
    u32 m_field_0F0;  // 0x0F0 [R] (SelectPage)
};

#endif // ERFONT_H
