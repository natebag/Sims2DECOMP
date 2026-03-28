#ifndef GAMEEFFECTSMANAGER_H
#define GAMEEFFECTSMANAGER_H

#include "types.h"

// GameEffectsManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0xAC (172 bytes)
// 2 known fields (0 named), 8 methods

class GameEffectsManager {
public:
    // Constructors / Destructors
    GameEffectsManager(void)  // 0x800B2424

    // Methods
    void RenderCB(ELevelDrawData &, EOrderTableData *);  // 0x800B2524 (272B)
    /* ? */ GetSingleton(void);  // 0x800B244C (108B)
    void PreRender(void);  // 0x800B24B8 (108B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x98];  // 0x000
    u32 m_field_098;  // 0x098 [R] (RenderCB)
    u8 _pad_09C[0xC];  // 0x09C
    u32 m_field_0A8;  // 0x0A8 [W] (RenderCB)
};

#endif // GAMEEFFECTSMANAGER_H
