#ifndef TILELIST_H
#define TILELIST_H

#include "types.h"

// TileList - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (0 named), 4 methods

class TileList {
public:
    // Constructors / Destructors
    TileList(void)  // 0x803787EC
    ~TileList(void);  // 0x803787AC

    // Methods
    void FindNearestPoint(FTilePt *, int);  // 0x803ED7C4 (1108B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (FindNearestPoint)
    u32 m_field_004;  // 0x004 [R] (FindNearestPoint)
};

#endif // TILELIST_H
