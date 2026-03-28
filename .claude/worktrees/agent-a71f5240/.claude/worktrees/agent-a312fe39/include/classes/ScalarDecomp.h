#ifndef SCALARDECOMP_H
#define SCALARDECOMP_H

#include "types.h"

// ScalarDecomp - struct layout extracted from assembly analysis
// Estimated minimum size: 0x44 (68 bytes)
// 20 known fields (20 named), 23 methods

class ScalarDecomp {
public:
    // Constructors / Destructors
    ScalarDecomp(void)  // 0x807B32C0

    // Methods
    /* ? */ GetFrame(float);  // 0x8090A57C (1620B)
    void Init(EBitArray *, int);  // 0x8090A150 (1008B)
    void Reset(void);  // 0x8090AF58 (140B)
    /* ? */ GetBitCount(void);  // 0x8090A540 (60B)
    void NextSegment(float);  // 0x8090ABD0 (456B)
    void ResetEnd(void);  // 0x8090AFE4 (168B)
    void LastSegment(float);  // 0x8090AD98 (448B)
    /* ? */ GetV(int, int, float &);  // 0x8090B3FC (924B)
    void ReadAllVs(void);  // 0x8090B08C (156B)
    /* ? */ GetKeyframe(int, ScalarKeyframe &);  // 0x8090B128 (584B)
    /* ? */ GetVal(int, float &);  // 0x8090B370 (140B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetKeyframe, GetVal, Init, ...)
    u32 m_v;  // 0x004 [R/W] (GetKeyframe, GetV, Init, ...)
    u32 m_keyframe;  // 0x008 [R/W] (GetKeyframe, LastSegment, NextSegment, ...)
    u32 m_keyframe_00C;  // 0x00C [R/W] (GetFrame, GetKeyframe, LastSegment, ...)
    u32 m_frame;  // 0x010 [R/W] (GetFrame, LastSegment, NextSegment, ...)
    u32 m_frame_014;  // 0x014 [R/W] (GetFrame, Init, ResetEnd)
    u32 m_v_018;  // 0x018 [R/W] (GetV, Init, ResetEnd)
    s16 m_v_01C;  // 0x01C [R/W] (GetKeyframe, GetV, Init, ...)
    u8 m_v_01E;  // 0x01E [R/W] (GetKeyframe, GetV, Init, ...)
    u8 m_val_01F;  // 0x01F [R/W] (GetVal, Init)
    u8 m_keyframe_020;  // 0x020 [R/W] (GetKeyframe, GetV, Init)
    u8 m_frame_021;  // 0x021 [R/W] (GetFrame, Init, LastSegment, ...)
    u8 _pad_022[2];  // 0x022
    f32 m_keyframe_024;  // 0x024 [R/W] (GetKeyframe, Init)
    f32 m_frame_028;  // 0x028 [R/W] (GetFrame, LastSegment, NextSegment, ...)
    f32 m_frame_02C;  // 0x02C [R/W] (GetFrame, LastSegment, NextSegment)
    f32 m_frame_030;  // 0x030 [R] (GetFrame)
    f32 m_frame_034;  // 0x034 [R] (GetFrame)
    f32 m_frame_038;  // 0x038 [R/W] (GetFrame, LastSegment, NextSegment)
    f32 m_val_03C;  // 0x03C [R/W] (GetVal, Init)
    f32 m_val_040;  // 0x040 [R/W] (GetVal, Init)
};

#endif // SCALARDECOMP_H
