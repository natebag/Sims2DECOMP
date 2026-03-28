#ifndef EMITTERGEOM3D_H
#define EMITTERGEOM3D_H

#include "types.h"

// EmitterGeom3d - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8C (140 bytes)
// 2 known fields (0 named), 5 methods

class EmitterGeom3d {
public:
    // Constructors / Destructors
    EmitterGeom3d(void)  // 0x800F5138
    ~EmitterGeom3d(void);  // 0x800F85C8

    // Methods
    void Create(char *, float *, pemitterinfo *);  // 0x8065B518 (304B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x80];  // 0x000
    u32 m_field_080;  // 0x080 [W] (Create)
    u8 _pad_084[4];  // 0x084
    u32 m_field_088;  // 0x088 [R] (Create)
};

#endif // EMITTERGEOM3D_H
