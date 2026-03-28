#ifndef LINEFADE_H
#define LINEFADE_H

#include "types.h"

// LineFade - struct layout extracted from assembly analysis
// Estimated minimum size: 0x40 (64 bytes)
// 9 known fields (9 named), 8 methods

class LineFade {
public:
    // Constructors / Destructors
    LineFade(void)  // 0x80825DD8

    // Methods
    bool IsInterestPointInside2D(EBound3 &);  // 0x806519EC (116B)
    void SetEnabled(bool);  // 0x80824EA8 (96B)
    void Setup(EVec3 &, EVec3 &);  // 0x80824920 (452B)
    bool IsLineIntersected(EBound3 &);  // 0x80824AE4 (964B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (Setup)
    u32 m_up_004;  // 0x004 [R/W] (Setup)
    u32 m_up_008;  // 0x008 [R/W] (Setup)
    u32 m_up_00C;  // 0x00C [W] (Setup)
    u8 _pad_010[8];  // 0x010
    u32 m_up_018;  // 0x018 [W] (Setup)
    u8 _pad_01C[8];  // 0x01C
    f32 m_up_024;  // 0x024 [W] (Setup)
    u8 _pad_028[8];  // 0x028
    f32 m_up_030;  // 0x030 [W] (Setup)
    f32 m_up_034;  // 0x034 [W] (Setup)
    u8 _pad_038[4];  // 0x038
    u32 m_up_03C;  // 0x03C [R] (Setup)
};

#endif // LINEFADE_H
