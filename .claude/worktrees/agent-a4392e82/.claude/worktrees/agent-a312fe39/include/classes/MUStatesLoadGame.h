#ifndef MUSTATESLOADGAME_H
#define MUSTATESLOADGAME_H

#include "types.h"

// MUStatesLoadGame - struct layout extracted from assembly analysis
// Estimated minimum size: 0x58DC (22748 bytes)
// 6 known fields (0 named), 12 methods

class MUStatesLoadGame {
public:
    // Constructors / Destructors
    MUStatesLoadGame(int)  // 0x801CE814
    ~MUStatesLoadGame(void);  // 0x801CE880

    // Methods
    void Reset(void);  // 0x801C6CA4 (64B)
    void Draw(ERC *);  // 0x801C6CE4 (64B)
    void Update(float);  // 0x801C6D24 (2204B)
    /* ? */ GetWrapper(void);  // 0x801CE8CC (80B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Update)
    u8 _pad_00C[0x10];  // 0x00C
    u32 m_field_01C;  // 0x01C [R/W] (Update)
    f32 m_field_020;  // 0x020 [R/W] (Update)
    u8 _pad_024[0x6C];  // 0x024
    u32 m_field_090;  // 0x090 [R/W] (Update)
    u8 _pad_094[0x18];  // 0x094
    u32 m_field_0AC;  // 0x0AC [W] (Update)
    u8 _pad_0B0[0x5828];  // 0x0B0
    u32 m_field_58D8;  // 0x58D8 [R] (Update)
};

#endif // MUSTATESLOADGAME_H
