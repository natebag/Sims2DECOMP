#ifndef EFENCEWALL_H
#define EFENCEWALL_H

#include "types.h"

// EFenceWall - struct layout extracted from assembly analysis
// Estimated minimum size: 0x40 (64 bytes)
// 6 known fields (0 named), 10 methods

class EFenceWall {
public:
    // Constructors / Destructors
    EFenceWall(TileWallsSegment &, CTilePt &, WallStyle)  // 0x80072AA8
    ~EFenceWall(void);  // 0x8007F8D8

    // Methods
    void SafeDelete(void);  // 0x8007F92C (108B)
    bool IsWallsOpaque(int);  // 0x8007F998 (44B)
    void CalWallsOpaque(int);  // 0x8007F9C4 (60B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x14];  // 0x000
    u32 m_field_014;  // 0x014 [W] (EFenceWall)
    u8 _pad_018[0x14];  // 0x018
    u32 m_field_02C;  // 0x02C [W] (EFenceWall)
    u32 m_field_030;  // 0x030 [W] (EFenceWall)
    f32 m_field_034;  // 0x034 [W] (EFenceWall)
    f32 m_field_038;  // 0x038 [W] (EFenceWall)
    u32 m_field_03C;  // 0x03C [W] (EFenceWall)
};

#endif // EFENCEWALL_H
