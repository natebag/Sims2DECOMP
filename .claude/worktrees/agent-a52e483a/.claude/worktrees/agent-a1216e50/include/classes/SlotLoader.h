#ifndef SLOTLOADER_H
#define SLOTLOADER_H

#include "types.h"

// SlotLoader - struct layout extracted from assembly analysis
// Estimated minimum size: 0x6C (108 bytes)
// 25 known fields (0 named), 10 methods

class SlotLoader {
public:
    // Constructors / Destructors
    SlotLoader(unsigned int)  // 0x803BF7F0
    ~SlotLoader(void);  // 0x803BFD6C

    // Methods
    void Load(short, vector<ObjectSlot, allocator<ObjectSlot> > *, vector<RoutingSlot, allocator<RoutingSlot> > *, vector<SpriteSlot, allocator<SpriteSlot> > *, cXObject *);  // 0x803BF82C (1136B)
    void Save(short, vector<ObjectSlot, allocator<ObjectSlot> > *, vector<RoutingSlot, allocator<RoutingSlot> > *, vector<SpriteSlot, allocator<SpriteSlot> > *, cXObject *);  // 0x803BFC9C (64B)
    /* ? */ GetSlotName(Slot *, BString &, int);  // 0x803BFCDC (144B)

    // ---- Field Layout (from assembly analysis) ----
    s16 m_field_000;  // 0x000 [R/W] (Load)
    u8 _pad_002[2];  // 0x002
    f32 m_field_004;  // 0x004 [R/W] (Load)
    f32 m_field_008;  // 0x008 [W] (Load)
    f32 m_field_00C;  // 0x00C [W] (Load)
    u32 m_field_010;  // 0x010 [W] (Load)
    f32 m_field_014;  // 0x014 [W] (Load)
    f32 m_field_018;  // 0x018 [W] (Load)
    f32 m_field_01C;  // 0x01C [W] (Load)
    u32 m_field_020;  // 0x020 [W] (Load)
    u32 m_field_024;  // 0x024 [W] (Load)
    u32 m_field_028;  // 0x028 [W] (Load)
    u32 m_field_02C;  // 0x02C [W] (Load)
    f32 m_field_030;  // 0x030 [W] (Load)
    u32 m_field_034;  // 0x034 [W] (Load)
    u32 m_field_038;  // 0x038 [W] (Load)
    u32 m_field_03C;  // 0x03C [W] (Load)
    u32 m_field_040;  // 0x040 [W] (Load)
    u32 m_field_044;  // 0x044 [W] (Load)
    u32 m_field_048;  // 0x048 [W] (Load)
    f32 m_field_04C;  // 0x04C [W] (Load)
    u8 _pad_050[8];  // 0x050
    f32 m_field_058;  // 0x058 [W] (Load)
    f32 m_field_05C;  // 0x05C [W] (Load)
    u32 m_field_060;  // 0x060 [W] (Load)
    u32 m_field_064;  // 0x064 [W] (Load)
    u32 m_field_068;  // 0x068 [W] (Load)
};

#endif // SLOTLOADER_H
