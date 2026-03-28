#ifndef ENGCRENDERSURFACE_H
#define ENGCRENDERSURFACE_H

#include "types.h"

// ENgcRenderSurface - struct layout extracted from assembly analysis
// Estimated minimum size: 0x2C (44 bytes)
// 5 known fields (0 named), 22 methods

class ENgcRenderSurface {
public:
    // Constructors / Destructors
    ENgcRenderSurface(void)  // 0x808D996C
    ~ENgcRenderSurface(void);  // 0x808D99C8

    // Methods
    void DestroySubtextures(void);  // 0x808D9A14 (112B)
    /* ? */ GetTexture(void);  // 0x808D9A84 (44B)
    void Create(ERenderSurfaceDef &);  // 0x808D9AB0 (216B)
    /* ? */ GetOutputRect(TRect<float> &);  // 0x808D9B88 (68B)
    void SetBackgroundColor(EVec3 &);  // 0x808D9BCC (76B)
    /* ? */ GetImageData(void *);  // 0x808D9C18 (84B)
    void CopyToTexture(ETexture *);  // 0x808D9C6C (2032B)
    void Select(void);  // 0x808DA45C (40B)
    void Deselect(void);  // 0x808DA484 (208B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[2];  // 0x000
    u16 m_field_002;  // 0x002 [R] (Deselect)
    u8 _pad_004[2];  // 0x004
    u16 m_field_006;  // 0x006 [R] (Deselect)
    u8 _pad_008[0x18];  // 0x008
    u32 m_field_020;  // 0x020 [W] (ENgcRenderSurface)
    u32 m_field_024;  // 0x024 [W] (Deselect, ENgcRenderSurface)
    u32 m_field_028;  // 0x028 [R/W] (CopyToTexture, Create, Deselect, ...)
};

#endif // ENGCRENDERSURFACE_H
