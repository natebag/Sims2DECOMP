#ifndef PZ1TARGET_H
#define PZ1TARGET_H

#include "types.h"

// PZ1Target - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC0 (192 bytes)
// 20 known fields (1 named), 6 methods

class PZ1Target {
public:
    // Constructors / Destructors
    PZ1Target(int)  // 0x80527848
    ~PZ1Target(void);  // 0x80527BA8

    // Methods
    /* ? */ GetTLA(void);  // 0x80552FA4 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (PZ1Target)
    u32 m_field_004;  // 0x004 [W] (PZ1Target)
    u32 m_field_008;  // 0x008 [W] (PZ1Target)
    u32 m_field_00C;  // 0x00C [W] (PZ1Target)
    u32 m_field_010;  // 0x010 [W] (PZ1Target)
    u32 m_field_014;  // 0x014 [W] (PZ1Target)
    u32 m_field_018;  // 0x018 [W] (PZ1Target)
    u32 m_field_01C;  // 0x01C [W] (PZ1Target)
    u32 m_field_020;  // 0x020 [W] (PZ1Target)
    u32 m_field_024;  // 0x024 [W] (PZ1Target)
    u32 m_field_028;  // 0x028 [W] (PZ1Target)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (PZ1Target)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (PZ1Target)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [W] (PZ1Target)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [W] (PZ1Target)
    u8 _pad_06C[0x10];  // 0x06C
    u32 m_field_07C;  // 0x07C [W] (PZ1Target)
    u32 m_field_080;  // 0x080 [W] (PZ1Target, ~PZ1Target)
    u8 _pad_084[8];  // 0x084
    u32 m_field_08C;  // 0x08C [R/W] (PZ1Target, ~PZ1Target)
    u8 _pad_090[4];  // 0x090
    u32 m_field_094;  // 0x094 [W] (PZ1Target)
    u8 _pad_098[0x24];  // 0x098
    u32 m_field_0BC;  // 0x0BC [R/W] (PZ1Target, ~PZ1Target)
};

#endif // PZ1TARGET_H
