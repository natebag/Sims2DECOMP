#ifndef ETEXTURE_H
#define ETEXTURE_H

#include "types.h"

// ETexture - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 8 known fields (1 named), 62 methods

class ETexture {
public:
    // Constructors / Destructors
    ETexture(void)  // 0x807E9188
    ~ETexture(void);  // 0x807E9204

    // Methods
    /* ? */ GetXSize(void);  // 0x807EAB50 (48B)
    /* ? */ GetYSize(void);  // 0x807EAB80 (48B)
    /* ? */ GetBitsPerImagePixel(void);  // 0x807EAB20 (48B)
    /* ? */ GetPaletteFormat(void);  // 0x807EABB0 (48B)
    /* ? */ GetPaletteSize(void);  // 0x807EAC10 (48B)
    /* ? */ GetFlags(void);  // 0x807EAC40 (44B)
    void Create(ETextureDef &);  // 0x807E92DC (144B)
    void Validate(void);  // 0x807E936C (152B)
    /* ? */ GetWindowName(void);  // 0x807E9404 (108B)
    /* ? */ GetMixinSize(void);  // 0x807E9470 (40B)
    /* ? */ GetMixinInfo(char *);  // 0x807E9498 (144B)
    void DrawWindow(CUIWindow *, ERC *);  // 0x807E9528 (1676B)
    void SetupWindow(CUIWindow *);  // 0x807E9BB4 (2840B)
    void WindowNotify(CUIWindow *, int);  // 0x807EA6CC (168B)
    void Select(int);  // 0x807EAA10 (36B)
    void Lock(void);  // 0x807EAC6C (40B)
    void Unlock(void);  // 0x807EAC94 (32B)
    void Invalidate(void);  // 0x807EACB4 (32B)
    void DisableMipmapping(void);  // 0x807EACD4 (32B)
    void UpdateMipLevel(int, int &, int &);  // 0x807EACF4 (52B)
    void UpdatePalette(void);  // 0x807EAD28 (40B)
    void UpdatePaletteDeswizzled(void);  // 0x807EAD50 (104B)
    void ClearTileFlags(void);  // 0x807EADB8 (44B)
    void ClearSwizzleFlag(void);  // 0x807EADE4 (44B)
    void SetSwizzleFlag(void);  // 0x807EAE10 (44B)
    void Test1(int, int, int, int);  // 0x807EAE3C (80B)
    /* ? */ GetImageFormat(void);  // 0x807EAAF0 (48B)
    /* ? */ GetBitsPerPaletteEntry(void);  // 0x807EABE0 (48B)
    bool IsValid(void);  // 0x807EAE8C (64B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (Create)
    u32 m_field_004;  // 0x004 [W] (Create)
    u32 m_field_008;  // 0x008 [W] (Create)
    u32 m_field_00C;  // 0x00C [W] (Create)
    u32 m_field_010;  // 0x010 [W] (Create)
    u32 m_field_014;  // 0x014 [W] (Create)
    u8 _pad_018[8];  // 0x018
    u32 m_field_020;  // 0x020 [W] (~ETexture)
    u32 m_field_024;  // 0x024 [W] (~ETexture)
};

#endif // ETEXTURE_H
