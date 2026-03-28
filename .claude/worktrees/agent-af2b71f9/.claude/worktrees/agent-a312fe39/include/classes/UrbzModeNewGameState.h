#ifndef URBZMODENEWGAMESTATE_H
#define URBZMODENEWGAMESTATE_H

#include "types.h"

// UrbzModeNewGameState - struct layout extracted from assembly analysis
// Estimated minimum size: 0xF4 (244 bytes)
// 5 known fields (0 named), 8 methods

class UrbzModeNewGameState {
public:
    // Constructors / Destructors
    UrbzModeNewGameState(int)  // 0x801EE448
    ~UrbzModeNewGameState(void);  // 0x801ED898

    // Methods
    void Reset(void);  // 0x801EA860 (84B)
    void Update(float);  // 0x801EA8B4 (1956B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (Update)
    s16 m_field_004;  // 0x004 [R] (Update)
    u8 _pad_006[6];  // 0x006
    u32 m_field_00C;  // 0x00C [R/W] (Update)
    u8 _pad_010[0x2C];  // 0x010
    u32 m_field_03C;  // 0x03C [R] (Update)
    u8 _pad_040[0xB0];  // 0x040
    u32 m_field_0F0;  // 0x0F0 [R] (Update)
};

#endif // URBZMODENEWGAMESTATE_H
