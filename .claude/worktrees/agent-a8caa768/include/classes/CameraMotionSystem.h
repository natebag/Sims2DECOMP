#ifndef CAMERAMOTIONSYSTEM_H
#define CAMERAMOTIONSYSTEM_H

#include "types.h"

// CameraMotionSystem - struct layout extracted from assembly analysis
// Estimated minimum size: 0x58 (88 bytes)
// 10 known fields (0 named), 21 methods

class CameraMotionSystem {
public:
    // Constructors / Destructors
    CameraMotionSystem(SimsCameraParameters *)  // 0x8003BA9C
    ~CameraMotionSystem(void);  // 0x8003BB3C

    // Methods
    void SetMotionType(CameraMotionType);  // 0x8003BB8C (44B)
    /* ? */ GetMotionType(void);  // 0x8003BBB8 (44B)
    void SetRig(EVec3 &, EVec3 &, EVec3 &);  // 0x8003BBE4 (152B)
    void SnapCamera(void);  // 0x8003BC7C (212B)
    void MoveCamera(float);  // 0x8003BD50 (112B)
    void RubberBandMove(float);  // 0x8003BF08 (272B)
    void RubberBandInterpolate(EVec3 *, EVec3, float);  // 0x8003BDC0 (328B)
    /* ? */ GetPosition(void);  // 0x8004DB80 (44B)
    /* ? */ GetLookAtVector(void);  // 0x8004DBAC (44B)
    /* ? */ GetUpVector(void);  // 0x8004DBD8 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    u32 m_field_004;  // 0x004 [R] (RubberBandInterpolate)
    f32 m_field_008;  // 0x008 [R] (RubberBandMove, SnapCamera)
    u8 _pad_00C[8];  // 0x00C
    f32 m_field_014;  // 0x014 [R] (RubberBandMove, SnapCamera)
    u8 _pad_018[8];  // 0x018
    u32 m_field_020;  // 0x020 [R] (RubberBandMove, SnapCamera)
    u8 _pad_024[8];  // 0x024
    f32 m_field_02C;  // 0x02C [R/W] (RubberBandMove, SnapCamera)
    u8 _pad_030[8];  // 0x030
    f32 m_field_038;  // 0x038 [R/W] (RubberBandMove, SnapCamera)
    u8 _pad_03C[8];  // 0x03C
    u32 m_field_044;  // 0x044 [W] (RubberBandMove, SnapCamera)
    u8 _pad_048[4];  // 0x048
    f32 m_field_04C;  // 0x04C [R] (RubberBandInterpolate)
    f32 m_field_050;  // 0x050 [R/W] (RubberBandInterpolate, RubberBandMove, SnapCamera)
    f32 m_field_054;  // 0x054 [R] (RubberBandInterpolate)
};

#endif // CAMERAMOTIONSYSTEM_H
