#ifndef ECULLPLANE_H
#define ECULLPLANE_H

#include "types.h"

// ECullPlane - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (4 named), 5 methods

class ECullPlane {
public:
    // Constructors / Destructors
    ECullPlane(void)  // 0x80825C70

    // Methods
    /* ? */ GetPlane(EVec4 &);  // 0x80825CD0 (64B)
    bool IsBoxOutside(EBound3 &);  // 0x80825D10 (200B)
    void SetPlane(EVec4 &);  // 0x8090B798 (380B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_plane;  // 0x000 [W] (SetPlane)
    f32 m_plane_004;  // 0x004 [W] (SetPlane)
    f32 m_plane_008;  // 0x008 [W] (SetPlane)
    f32 m_plane_00C;  // 0x00C [W] (SetPlane)
};

#endif // ECULLPLANE_H
