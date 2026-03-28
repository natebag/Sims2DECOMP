#ifndef EVEC3DECOMP_H
#define EVEC3DECOMP_H

#include "types.h"

// EVec3Decomp - struct layout extracted from assembly analysis
// Estimated minimum size: 0x54 (84 bytes)
// 16 known fields (10 named), 23 methods

class EVec3Decomp {
public:
    // Constructors / Destructors
    EVec3Decomp(void)  // 0x807B318C

    // Methods
    /* ? */ GetFrame(float);  // 0x807796F8 (1804B)
    void Init(EBitArray *, int);  // 0x80779164 (1112B)
    void Reset(void);  // 0x8077A1BC (140B)
    /* ? */ GetBitCount(void);  // 0x807796BC (60B)
    void NextSegment(float);  // 0x80779E04 (480B)
    void ResetEnd(void);  // 0x8077A248 (168B)
    void LastSegment(float);  // 0x80779FE4 (472B)
    /* ? */ GetV(int, int, EVec3 &);  // 0x8077A6D4 (1308B)
    void ReadAllVs(void);  // 0x8077A2F0 (156B)
    /* ? */ GetKeyframe(int, EVec3Keyframe &);  // 0x8077A38C (584B)
    /* ? */ GetVecVal(int, EVec3 &);  // 0x8077A5D4 (256B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_keyframe;  // 0x000 [R/W] (GetFrame, GetKeyframe, GetVecVal, ...)
    f32 m_v;  // 0x004 [R/W] (GetFrame, GetKeyframe, GetV, ...)
    f32 m_keyframe_008;  // 0x008 [R/W] (GetFrame, GetKeyframe, LastSegment, ...)
    u32 m_keyframe_00C;  // 0x00C [R/W] (GetKeyframe, LastSegment, NextSegment, ...)
    u32 m_field_010;  // 0x010 [R/W] (LastSegment, NextSegment, Reset, ...)
    u32 m_field_014;  // 0x014 [R/W] (Init, ResetEnd)
    u32 m_v_018;  // 0x018 [R/W] (GetV, Init, ResetEnd, ...)
    s16 m_v_01C;  // 0x01C [R/W] (GetKeyframe, GetV, Init, ...)
    u8 m_v_01E;  // 0x01E [R/W] (GetKeyframe, GetV, Init, ...)
    u8 m_vecVal;  // 0x01F [R/W] (GetVecVal, Init)
    u8 m_keyframe_020;  // 0x020 [R/W] (GetKeyframe, GetV, Init)
    u8 m_field_021;  // 0x021 [W] (Init, LastSegment, NextSegment)
    u8 _pad_022[2];  // 0x022
    f32 m_keyframe_024;  // 0x024 [R/W] (GetKeyframe, Init)
    f32 m_field_028;  // 0x028 [R/W] (LastSegment, NextSegment, Reset, ...)
    u32 m_field_02C;  // 0x02C [R/W] (LastSegment, NextSegment)
    u8 _pad_030[0x20];  // 0x030
    u32 m_field_050;  // 0x050 [R/W] (LastSegment, NextSegment)
};

#endif // EVEC3DECOMP_H
