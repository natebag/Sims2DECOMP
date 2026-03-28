#ifndef SIMRENDERER_H
#define SIMRENDERER_H

#include "types.h"

// SimRenderer - struct layout extracted from assembly analysis
// Estimated minimum size: 0x124 (292 bytes)
// 2 known fields (0 named), 8 methods

class SimRenderer {
public:
    // Methods
    void Render(ERC *, EIStaticModel **, EShader *, EMat4 *, unsigned int, bool);  // 0x80161E18 (348B)
    void RenderGhosted(ERC *, EIStaticModel **, EMat4 *, unsigned int, bool);  // 0x8016222C (280B)
    void MorphParts(EIStaticModel **, bool);  // 0x801620CC (352B)
    void Render(ERC *, EIStaticModel **, EAnimController *, EShader *, EMat4 &, bool);  // 0x80161F74 (344B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x70];  // 0x000
    u32 m_field_070;  // 0x070 [R] (Render, RenderGhosted)
    u8 _pad_074[0xAC];  // 0x074
    u32 m_field_120;  // 0x120 [R] (MorphParts)
};

#endif // SIMRENDERER_H
