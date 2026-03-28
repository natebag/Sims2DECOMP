#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

// Player - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (2 named), 12 methods

class Player {
public:
    // Constructors / Destructors
    Player(void)  // 0x80119410

    // Methods
    /* ? */ GetCamera(void);  // 0x800A8700 (44B)
    /* ? */ GetPrimaryNeighbor(void);  // 0x80119520 (332B)
    void Reset(int);  // 0x80119450 (164B)
    /* ? */ GetInteractorColor(void);  // 0x801194F4 (44B)
    /* ? */ GetSelectedNeighbor(void);  // 0x8011966C (220B)
    /* ? */ GetPiMenu(void);  // 0x804A1F0C (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetPrimaryNeighbor, GetSelectedNeighbor, Reset)
    u32 m_primaryNeighbor;  // 0x004 [W] (GetPrimaryNeighbor)
    u32 m_field_008;  // 0x008 [R/W] (Reset)
    u32 m_field_00C;  // 0x00C [R/W] (Reset)
};

#endif // PLAYER_H
