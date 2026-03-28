#ifndef FRAMEEFFECT_H
#define FRAMEEFFECT_H

#include "types.h"

// FrameEffect - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 3 known fields (3 named), 19 methods

class FrameEffect {
public:
    // Constructors / Destructors
    FrameEffect(void)  // 0x808F5008
    ~FrameEffect(void);  // 0x808F4908

    // Methods
    void SetFadeInTime(float);  // 0x80004EFC (168B)
    void SetFadeOutTime(float);  // 0x80004FA4 (168B)
    /* ? */ GetEffectState(void);  // 0x8004D584 (44B)
    void Enable(bool);  // 0x808F2490 (136B)
    void Update(float, ERC *);  // 0x808F2518 (260B)
    void SetEffectState(FrameEffect::EffectState);  // 0x808F4288 (104B)
    bool IsEffectRamping(void);  // 0x808F261C (76B)
    bool IsEffectRunning(void);  // 0x808F2668 (60B)
    void UpdateEffectState(void);  // 0x808F26A4 (220B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    f32 m_effectState;  // 0x008 [R/W] (Enable, Update, UpdateEffectState)
    u32 m_effectState_00C;  // 0x00C [R/W] (Enable, UpdateEffectState)
    u32 m_effectState_010;  // 0x010 [R] (Enable, Update, UpdateEffectState)
};

#endif // FRAMEEFFECT_H
