#ifndef EMITTERGEOM3DTAB_H
#define EMITTERGEOM3DTAB_H

#include "types.h"

// EmitterGeom3dTab - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8C (140 bytes)
// 2 known fields (0 named), 5 methods

class EmitterGeom3dTab {
public:
    // Constructors / Destructors
    EmitterGeom3dTab(void)  // 0x800F5184
    ~EmitterGeom3dTab(void);  // 0x800F8608

    // Methods
    void Create(char *, float *, pemitterinfo *);  // 0x8065B934 (348B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x80];  // 0x000
    u32 m_field_080;  // 0x080 [W] (Create)
    u8 _pad_084[4];  // 0x084
    u32 m_field_088;  // 0x088 [R] (Create)
};

#endif // EMITTERGEOM3DTAB_H
