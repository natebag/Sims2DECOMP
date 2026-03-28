#ifndef BSPLINEVOLUME_H
#define BSPLINEVOLUME_H

#include "types.h"

// BSplineVolume - struct layout extracted from assembly analysis
// Estimated minimum size: 0xE0 (224 bytes)
// 26 known fields (3 named), 30 methods

class BSplineVolume {
public:
    // Constructors / Destructors
    BSplineVolume(void)  // 0x8082D208
    ~BSplineVolume(void);  // 0x8082D2EC

    // Methods
    /* ? */ GetID(void);  // 0x80832A2C (44B)
    void ParameterizeVert(EVec3, int &);  // 0x8082EFD8 (988B)
    /* ? */ GetPosition(EVec3 *, int);  // 0x80830204 (1288B)
    void Free(void);  // 0x8082D350 (936B)
    void Read(EStream &);  // 0x8082D6F8 (1312B)
    void AllocateControlPoints(int, int, int, int);  // 0x8082E308 (780B)
    void ParameterizeControlPoints(void);  // 0x8082E614 (2500B)
    void GenerateControlPointDeltas(void);  // 0x8082F3B4 (928B)
    void Read(unsigned char *);  // 0x8082DC18 (1468B)
    void Write(EStream &);  // 0x8082E1D4 (44B)
    /* ? */ GetNumVolumes(void);  // 0x8082F754 (84B)
    void SetVolumeWeights(int, float);  // 0x8082F7A8 (304B)
    void BlendVolumes(void);  // 0x8082F8D8 (1676B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_position;  // 0x000 [W] (GetPosition, ParameterizeVert)
    f32 m_position_004;  // 0x004 [W] (GetPosition, ParameterizeVert)
    f32 m_position_008;  // 0x008 [W] (GetPosition, ParameterizeVert)
    u8 _pad_00C[0x78];  // 0x00C
    u32 m_field_084;  // 0x084 [R] (BlendVolumes, Free, GenerateControlPointDeltas, ...)
    u32 m_field_088;  // 0x088 [R] (BlendVolumes, Free, GenerateControlPointDeltas, ...)
    u32 m_field_08C;  // 0x08C [R] (BlendVolumes, GenerateControlPointDeltas, ParameterizeControlPoints, ...)
    u32 m_field_090;  // 0x090 [R] (BlendVolumes, Free, GenerateControlPointDeltas, ...)
    u32 m_field_094;  // 0x094 [R/W] (BSplineVolume, BlendVolumes, Free, ...)
    u32 m_field_098;  // 0x098 [R/W] (BSplineVolume, BlendVolumes, Free, ...)
    u32 m_field_09C;  // 0x09C [R/W] (BSplineVolume, GenerateControlPointDeltas)
    u32 m_field_0A0;  // 0x0A0 [R/W] (BSplineVolume, BlendVolumes)
    u32 m_field_0A4;  // 0x0A4 [R/W] (BSplineVolume, BlendVolumes, Free, ...)
    f32 m_field_0A8;  // 0x0A8 [R/W] (ParameterizeControlPoints)
    f32 m_field_0AC;  // 0x0AC [R/W] (ParameterizeControlPoints)
    f32 m_field_0B0;  // 0x0B0 [R/W] (ParameterizeControlPoints)
    f32 m_field_0B4;  // 0x0B4 [R/W] (ParameterizeControlPoints)
    f32 m_field_0B8;  // 0x0B8 [R/W] (ParameterizeControlPoints)
    f32 m_field_0BC;  // 0x0BC [R/W] (ParameterizeControlPoints)
    f32 m_field_0C0;  // 0x0C0 [W] (ParameterizeControlPoints)
    f32 m_field_0C4;  // 0x0C4 [W] (ParameterizeControlPoints)
    f32 m_field_0C8;  // 0x0C8 [W] (ParameterizeControlPoints)
    f32 m_field_0CC;  // 0x0CC [R] (BSplineVolume)
    f32 m_field_0D0;  // 0x0D0 [R] (BSplineVolume)
    f32 m_field_0D4;  // 0x0D4 [W] (BSplineVolume)
    f32 m_field_0D8;  // 0x0D8 [W] (BSplineVolume)
    u32 m_field_0DC;  // 0x0DC [W] (BSplineVolume, ~BSplineVolume)
};

#endif // BSPLINEVOLUME_H
