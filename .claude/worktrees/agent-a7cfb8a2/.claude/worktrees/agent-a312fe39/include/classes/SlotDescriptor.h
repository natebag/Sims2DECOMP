#ifndef SLOTDESCRIPTOR_H
#define SLOTDESCRIPTOR_H

#include "types.h"

// SlotDescriptor - struct layout extracted from assembly analysis
// Estimated minimum size: 0x48 (72 bytes)
// 18 known fields (0 named), 4 methods

class SlotDescriptor {
public:
    // Constructors / Destructors
    SlotDescriptor(void)  // 0x803BF388

    // Methods
    void DoStream(ReconBuffer *, int);  // 0x803BF470 (896B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_field_000;  // 0x000 [W] (SlotDescriptor)
    u8 _pad_002[2];  // 0x002
    f32 m_field_004;  // 0x004 [W] (SlotDescriptor)
    f32 m_field_008;  // 0x008 [W] (SlotDescriptor)
    f32 m_field_00C;  // 0x00C [R/W] (DoStream, SlotDescriptor)
    u32 m_field_010;  // 0x010 [W] (SlotDescriptor)
    u32 m_field_014;  // 0x014 [W] (SlotDescriptor)
    u32 m_field_018;  // 0x018 [W] (SlotDescriptor)
    u32 m_field_01C;  // 0x01C [W] (DoStream, SlotDescriptor)
    u32 m_field_020;  // 0x020 [W] (DoStream, SlotDescriptor)
    u32 m_field_024;  // 0x024 [W] (DoStream, SlotDescriptor)
    u32 m_field_028;  // 0x028 [R/W] (DoStream, SlotDescriptor)
    u32 m_field_02C;  // 0x02C [W] (SlotDescriptor)
    u32 m_field_030;  // 0x030 [R/W] (DoStream, SlotDescriptor)
    u32 m_field_034;  // 0x034 [R/W] (DoStream, SlotDescriptor)
    u32 m_field_038;  // 0x038 [R/W] (DoStream, SlotDescriptor)
    f32 m_field_03C;  // 0x03C [R/W] (DoStream, SlotDescriptor)
    u32 m_field_040;  // 0x040 [W] (DoStream, SlotDescriptor)
    u32 m_field_044;  // 0x044 [W] (SlotDescriptor)
};

#endif // SLOTDESCRIPTOR_H
