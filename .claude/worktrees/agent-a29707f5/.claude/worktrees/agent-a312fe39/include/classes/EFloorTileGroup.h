#ifndef EFLOORTILEGROUP_H
#define EFLOORTILEGROUP_H

#include "types.h"

// EFloorTileGroup - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 5 known fields (1 named), 4 methods

class EFloorTileGroup {
public:
    // Constructors / Destructors
    EFloorTileGroup(ERShader *, EDL *, EFloorTileStrip *, int, EFloorTileGroup *)  // 0x800D49A0
    ~EFloorTileGroup(void);  // 0x800D4A8C

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (EFloorTileGroup, ~EFloorTileGroup)
    u32 m_field_004;  // 0x004 [R/W] (EFloorTileGroup, ~EFloorTileGroup)
    u32 m_field_008;  // 0x008 [R/W] (EFloorTileGroup, ~EFloorTileGroup)
    u32 m_field_00C;  // 0x00C [R/W] (EFloorTileGroup, ~EFloorTileGroup)
    u32 m_field_010;  // 0x010 [R/W] (EFloorTileGroup, ~EFloorTileGroup)
};

#endif // EFLOORTILEGROUP_H
