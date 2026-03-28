#ifndef EROTDECOMP_H
#define EROTDECOMP_H

#include "types.h"

// ERotDecomp - struct layout extracted from assembly analysis
// Estimated minimum size: 0x64 (100 bytes)
// 17 known fields (12 named), 23 methods

class ERotDecomp {
public:
    // Constructors / Destructors
    ERotDecomp(void)  // 0x807B311C

    // Methods
    /* ? */ GetFrame(float);  // 0x80900178 (1588B)
    void Init(EBitArray *, int);  // 0x808FFC7C (960B)
    void Reset(void);  // 0x80900B74 (140B)
    /* ? */ GetBitCount(void);  // 0x8090013C (60B)
    void NextSegment(float);  // 0x809007AC (488B)
    void ResetEnd(void);  // 0x80900C00 (168B)
    void LastSegment(float);  // 0x80900994 (480B)
    /* ? */ GetQ(int, int, EQuat &);  // 0x809011AC (936B)
    void ReadAllQs(void);  // 0x80900CA8 (156B)
    /* ? */ GetKeyframe(int, ERotKeyframe &);  // 0x80900D44 (584B)
    /* ? */ GetQuatVal(int, EQuat &);  // 0x80900F8C (544B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_keyframe;  // 0x000 [R/W] (GetFrame, GetKeyframe, GetQuatVal, ...)
    f32 m_q;  // 0x004 [R/W] (GetFrame, GetKeyframe, GetQ, ...)
    f32 m_keyframe_008;  // 0x008 [R/W] (GetFrame, GetKeyframe, LastSegment, ...)
    f32 m_frame;  // 0x00C [R/W] (GetFrame, LastSegment, NextSegment, ...)
    u32 m_field_010;  // 0x010 [R/W] (Init, ResetEnd)
    u32 m_keyframe_014;  // 0x014 [R/W] (GetKeyframe, LastSegment, NextSegment, ...)
    u32 m_q_018;  // 0x018 [R/W] (GetQ, Init, ResetEnd, ...)
    s16 m_q_01C;  // 0x01C [R/W] (GetKeyframe, GetQ, Init, ...)
    u8 m_q_01E;  // 0x01E [R/W] (GetKeyframe, GetQ, Init, ...)
    u8 m_quatVal;  // 0x01F [R/W] (GetQuatVal, Init)
    u8 m_keyframe_020;  // 0x020 [R/W] (GetKeyframe, GetQ, Init)
    u8 m_field_021;  // 0x021 [W] (Init, LastSegment, NextSegment)
    u8 _pad_022[2];  // 0x022
    f32 m_quatVal_024;  // 0x024 [R/W] (GetQuatVal, Init)
    f32 m_keyframe_028;  // 0x028 [R/W] (GetKeyframe, Init)
    f32 m_field_02C;  // 0x02C [R/W] (LastSegment, NextSegment, Reset, ...)
    u32 m_field_030;  // 0x030 [R/W] (LastSegment, NextSegment)
    u8 _pad_034[0x2C];  // 0x034
    u32 m_field_060;  // 0x060 [R/W] (LastSegment, NextSegment)
};

#endif // EROTDECOMP_H
