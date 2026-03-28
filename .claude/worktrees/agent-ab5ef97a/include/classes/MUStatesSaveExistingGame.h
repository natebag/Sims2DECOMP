#ifndef MUSTATESSAVEEXISTINGGAME_H
#define MUSTATESSAVEEXISTINGGAME_H

#include "types.h"

// MUStatesSaveExistingGame - struct layout extracted from assembly analysis
// Estimated minimum size: 0x94 (148 bytes)
// 4 known fields (0 named), 12 methods

class MUStatesSaveExistingGame {
public:
    // Constructors / Destructors
    MUStatesSaveExistingGame(int)  // 0x801CED58
    ~MUStatesSaveExistingGame(void);  // 0x801CEDC4

    // Methods
    void Reset(void);  // 0x801C932C (64B)
    void Draw(ERC *);  // 0x801C936C (64B)
    void Update(float);  // 0x801C93AC (1488B)
    /* ? */ GetWrapper(void);  // 0x801CEE10 (80B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Update)
    u8 _pad_00C[0x10];  // 0x00C
    u32 m_field_01C;  // 0x01C [R/W] (Update)
    f32 m_field_020;  // 0x020 [R/W] (Update)
    u8 _pad_024[0x6C];  // 0x024
    u32 m_field_090;  // 0x090 [R/W] (Update)
};

#endif // MUSTATESSAVEEXISTINGGAME_H
