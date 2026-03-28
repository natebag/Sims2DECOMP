#ifndef EMITTERSPR3D_H
#define EMITTERSPR3D_H

#include "types.h"

// EmitterSpr3d - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8C (140 bytes)
// 3 known fields (0 named), 15 methods

class EmitterSpr3d {
public:
    // Constructors / Destructors
    EmitterSpr3d(void)  // 0x80022CCC
    ~EmitterSpr3d(void);  // 0x8002300C

    // Methods
    void Destroy(void);  // 0x8065B060 (56B)
    void Create(char *, float *, pemitterinfo *);  // 0x8065ACC8 (272B)
    void CreateCameraFollowXY(char *, float *, pemitterinfo *);  // 0x8065AF1C (324B)
    void CreateCameraFollowXYZ(char *, float *, pemitterinfo *);  // 0x8065ADD8 (324B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x50];  // 0x000
    u32 m_field_050;  // 0x050 [R/W] (CreateCameraFollowXY, CreateCameraFollowXYZ)
    u8 _pad_054[0x2C];  // 0x054
    u32 m_field_080;  // 0x080 [W] (Create)
    u8 _pad_084[4];  // 0x084
    u32 m_field_088;  // 0x088 [R] (Create, CreateCameraFollowXY, CreateCameraFollowXYZ)
};

#endif // EMITTERSPR3D_H
