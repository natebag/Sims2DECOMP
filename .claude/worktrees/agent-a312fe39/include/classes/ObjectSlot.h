#ifndef OBJECTSLOT_H
#define OBJECTSLOT_H

#include "types.h"

// ObjectSlot - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 8 known fields (3 named), 19 methods

class ObjectSlot {
public:
    // Constructors / Destructors
    ObjectSlot(ObjectSlot &)  // 0x802BE2B8
    ObjectSlot(void)  // 0x803BE4C8
    ObjectSlot(SlotDescriptor *)  // 0x803BE558
    ~ObjectSlot(void);  // 0x803C2810

    // Methods
    /* ? */ GetHeightMask(StdHeight);  // 0x803C2900 (52B)
    /* ? */ GetHeight(void);  // 0x803C285C (44B)
    bool IsFreePos(void);  // 0x803C28CC (52B)
    void SetHeight(StdHeight);  // 0x803BE678 (232B)
    void WriteSlot(SlotDescriptor *);  // 0x803BE600 (120B)
    bool IsSurface(void);  // 0x803C2888 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ObjectSlot)
    u16 m_field_004;  // 0x004 [W] (ObjectSlot)
    u8 _pad_006[2];  // 0x006
    u32 m_height;  // 0x008 [W] (ObjectSlot, SetHeight)
    u32 m_field_00C;  // 0x00C [W] (ObjectSlot)
    u32 m_field_010;  // 0x010 [W] (ObjectSlot)
    f32 m_field_014;  // 0x014 [W] (ObjectSlot)
    f32 m_field_018;  // 0x018 [W] (ObjectSlot)
    f32 m_height_01C;  // 0x01C [R/W] (ObjectSlot, SetHeight)
};

#endif // OBJECTSLOT_H
