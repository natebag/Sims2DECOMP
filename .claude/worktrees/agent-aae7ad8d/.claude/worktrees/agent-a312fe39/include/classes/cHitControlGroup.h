#ifndef CHITCONTROLGROUP_H
#define CHITCONTROLGROUP_H

#include "types.h"

// cHitControlGroup - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 5 methods

class cHitControlGroup {
public:
    // Constructors / Destructors
    cHitControlGroup(int)  // 0x80340B28

    // Methods
    void Volume(void);  // 0x80224DE8 (44B)
    void SetVolume(int);  // 0x80340BD4 (300B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_volume;  // 0x000 [R] (SetVolume)
    u32 m_volume_004;  // 0x004 [W] (SetVolume)
    u32 m_volume_008;  // 0x008 [R] (SetVolume)
};

#endif // CHITCONTROLGROUP_H
