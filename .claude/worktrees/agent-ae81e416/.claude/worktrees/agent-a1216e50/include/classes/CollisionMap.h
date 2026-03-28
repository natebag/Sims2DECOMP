#ifndef COLLISIONMAP_H
#define COLLISIONMAP_H

#include "types.h"

// CollisionMap - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (1 named), 6 methods

class CollisionMap {
public:
    // Methods
    void DoesCollideEnvironment(EVec2 &, EVec2 &, float, bool, bool, EVec2 &);  // 0x80057184 (2352B)
    bool IsMoveBlocked(int, int, bool, TileWallsSegment);  // 0x80057AB4 (540B)
    void DoesCollideObject(EVec2 &, EVec2 &, float, bool, EVec2 &);  // 0x80057CD0 (1984B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_bIsMoveBlocked;  // 0x000 [R] (DoesCollideEnvironment, DoesCollideObject, IsMoveBlocked)
    f32 m_field_004;  // 0x004 [R] (DoesCollideEnvironment, DoesCollideObject)
};

#endif // COLLISIONMAP_H
