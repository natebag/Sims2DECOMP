#ifndef MUSTATESTRANSITIONSAVEEXISTINGGAME_H
#define MUSTATESTRANSITIONSAVEEXISTINGGAME_H

#include "types.h"

// MUStatesTransitionSaveExistingGame - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 4 known fields (0 named), 12 methods

class MUStatesTransitionSaveExistingGame {
public:
    // Constructors / Destructors
    MUStatesTransitionSaveExistingGame(int)  // 0x801CEF68
    ~MUStatesTransitionSaveExistingGame(void);  // 0x801CEFD4

    // Methods
    void Reset(void);  // 0x801C9D18 (64B)
    void Draw(ERC *);  // 0x801C9D58 (208B)
    /* ? */ GetWrapper(void);  // 0x801CF020 (80B)
    void Update(float);  // 0x801C9E28 (1216B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Draw, Update)
    u8 _pad_00C[0x10];  // 0x00C
    u32 m_field_01C;  // 0x01C [R/W] (Draw, Update)
    f32 m_field_020;  // 0x020 [R/W] (Update)
    u32 m_field_024;  // 0x024 [W] (Update)
};

#endif // MUSTATESTRANSITIONSAVEEXISTINGGAME_H
