#ifndef CSAMPLEPATCH_H
#define CSAMPLEPATCH_H

#include "types.h"

// cSamplePatch - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 5 known fields (1 named), 19 methods

class cSamplePatch {
public:
    // Constructors / Destructors
    cSamplePatch(SndEvtHitPatch *, float)  // 0x803455A4
    ~cSamplePatch(void);  // 0x80345744

    // Methods
    void SetLooped(int);  // 0x803458F4 (44B)
    void CreateChannel(void);  // 0x80345B30 (92B)
    void FreeSnd(void);  // 0x80345AB0 (128B)
    void SetVolume(int);  // 0x8034579C (172B)
    void SetPan(int);  // 0x80345848 (172B)
    bool IsPlaying(void);  // 0x80345920 (136B)
    void CreateSnd(void);  // 0x803459A8 (264B)
    void TempGetSnd(void);  // 0x8034CBA8 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (CreateSnd)
    u32 m_field_00C;  // 0x00C [R] (CreateSnd)
    u32 m_field_010;  // 0x010 [R] (CreateSnd)
    f32 m_field_014;  // 0x014 [R] (CreateSnd)
    u32 m_bIsPlaying;  // 0x018 [R/W] (CreateSnd, FreeSnd, IsPlaying)
};

#endif // CSAMPLEPATCH_H
