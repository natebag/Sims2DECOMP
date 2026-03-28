#ifndef PYRAMIDFADE_H
#define PYRAMIDFADE_H

#include "types.h"

// PyramidFade - struct layout extracted from assembly analysis
// Estimated minimum size: 0xB0 (176 bytes)
// 16 known fields (14 named), 17 methods

class PyramidFade {
public:
    // Constructors / Destructors
    PyramidFade(void)  // 0x80823F64

    // Methods
    void SetInstantFade(bool);  // 0x8006981C (40B)
    void SetExcludeFromFadeHeight(float);  // 0x800697CC (40B)
    void SetAlphaMin(float);  // 0x800697F4 (40B)
    void SetPointTest(bool);  // 0x80069844 (40B)
    /* ? */ GetExcludeFromFadeHeight(void);  // 0x80651968 (44B)
    /* ? */ GetAlphaMin(void);  // 0x80651994 (44B)
    /* ? */ GetInstantFade(void);  // 0x806519C0 (44B)
    void SetEnabled(bool);  // 0x808248CC (84B)
    void Setup(EVec3 &, EVec3 *);  // 0x80824050 (976B)
    bool IsOutsideFadeVolume(void *, EBound3 &);  // 0x80824628 (676B)
    void DeriveDepthData(void);  // 0x80824420 (520B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_bIsOutsideFadeVolume;  // 0x000 [R] (IsOutsideFadeVolume)
    u32 m_bIsOutsideFadeVolume_004;  // 0x004 [R] (IsOutsideFadeVolume)
    f32 m_bIsOutsideFadeVolume_008;  // 0x008 [R] (IsOutsideFadeVolume)
    u8 _pad_00C[0x14];  // 0x00C
    f32 m_bIsOutsideFadeVolume_020;  // 0x020 [R] (IsOutsideFadeVolume)
    u8 _pad_024[0x14];  // 0x024
    f32 m_bIsOutsideFadeVolume_038;  // 0x038 [R] (DeriveDepthData, IsOutsideFadeVolume)
    u8 _pad_03C[0x14];  // 0x03C
    f32 m_bIsOutsideFadeVolume_050;  // 0x050 [R] (IsOutsideFadeVolume)
    u8 _pad_054[0x14];  // 0x054
    f32 m_bIsOutsideFadeVolume_068;  // 0x068 [R] (IsOutsideFadeVolume)
    u8 _pad_06C[0x14];  // 0x06C
    f32 m_bIsOutsideFadeVolume_080;  // 0x080 [R] (IsOutsideFadeVolume)
    f32 m_bIsOutsideFadeVolume_084;  // 0x084 [R] (IsOutsideFadeVolume)
    f32 m_bIsOutsideFadeVolume_088;  // 0x088 [R/W] (DeriveDepthData, IsOutsideFadeVolume)
    u8 _pad_08C[4];  // 0x08C
    f32 m_bIsOutsideFadeVolume_090;  // 0x090 [R/W] (DeriveDepthData, IsOutsideFadeVolume)
    u8 _pad_094[4];  // 0x094
    u8 m_bIsOutsideFadeVolume_098;  // 0x098 [R] (IsOutsideFadeVolume)
    u8 m_bIsOutsideFadeVolume_099;  // 0x099 [R] (IsOutsideFadeVolume)
    u8 _pad_09A[2];  // 0x09A
    u32 m_field_09C;  // 0x09C [R/W] (DeriveDepthData, PyramidFade)
    u32 m_bIsOutsideFadeVolume_0A0;  // 0x0A0 [R/W] (IsOutsideFadeVolume, PyramidFade)
    u8 _pad_0A4[8];  // 0x0A4
    u32 m_field_0AC;  // 0x0AC [W] (PyramidFade)
};

#endif // PYRAMIDFADE_H
