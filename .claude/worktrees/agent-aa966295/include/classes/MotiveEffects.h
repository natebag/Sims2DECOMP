#ifndef MOTIVEEFFECTS_H
#define MOTIVEEFFECTS_H

#include "types.h"

// MotiveEffects - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC4 (196 bytes)
// 5 known fields (5 named), 7 methods

class MotiveEffects {
public:
    // Constructors / Destructors
    MotiveEffects(cXPerson *)  // 0x8025F880
    ~MotiveEffects(void);  // 0x8037A5A0

    // Methods
    /* ? */ GetCurrentScore(void);  // 0x8025F9F4 (236B)
    /* ? */ GetInteractionScore(ITreeTableEntry *);  // 0x8025FAE0 (1156B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetCurrentScore, GetInteractionScore, MotiveEffects)
    u32 m_currentScore_004;  // 0x004 [R/W] (GetCurrentScore, GetInteractionScore, MotiveEffects)
    u32 m_interactionScore;  // 0x008 [R] (GetInteractionScore)
    u8 _pad_00C[0xB0];  // 0x00C
    u32 m_interactionScore_0BC;  // 0x0BC [R/W] (GetInteractionScore, MotiveEffects)
    u32 m_currentScore_0C0;  // 0x0C0 [R/W] (GetCurrentScore, GetInteractionScore, MotiveEffects)
};

#endif // MOTIVEEFFECTS_H
