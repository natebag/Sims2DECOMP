#ifndef PAZTARGET_H
#define PAZTARGET_H

#include "types.h"

// PAZTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x90 (144 bytes)
// 19 known fields (1 named), 6 methods

class PAZTarget {
public:
    // Constructors / Destructors
    PAZTarget(int)  // 0x805274D8
    ~PAZTarget(void);  // 0x805277F0

    // Methods
    /* ? */ GetTLA(void);  // 0x80552F78 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (PAZTarget)
    u32 m_field_004;  // 0x004 [W] (PAZTarget)
    u32 m_field_008;  // 0x008 [W] (PAZTarget)
    u32 m_field_00C;  // 0x00C [W] (PAZTarget)
    u32 m_field_010;  // 0x010 [W] (PAZTarget)
    u32 m_field_014;  // 0x014 [W] (PAZTarget)
    u32 m_field_018;  // 0x018 [W] (PAZTarget)
    u32 m_field_01C;  // 0x01C [W] (PAZTarget)
    u32 m_field_020;  // 0x020 [W] (PAZTarget)
    u32 m_field_024;  // 0x024 [R/W] (PAZTarget)
    u32 m_field_028;  // 0x028 [W] (PAZTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (PAZTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (PAZTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [W] (PAZTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [W] (PAZTarget)
    u8 _pad_06C[0x10];  // 0x06C
    u32 m_field_07C;  // 0x07C [R/W] (PAZTarget)
    u32 m_field_080;  // 0x080 [W] (PAZTarget)
    u32 m_field_084;  // 0x084 [W] (PAZTarget)
    u8 _pad_088[4];  // 0x088
    u32 m_field_08C;  // 0x08C [W] (PAZTarget)
};

#endif // PAZTARGET_H
