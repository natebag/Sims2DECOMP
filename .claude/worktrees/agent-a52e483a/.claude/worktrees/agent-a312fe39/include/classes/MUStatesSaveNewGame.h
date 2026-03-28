#ifndef MUSTATESSAVENEWGAME_H
#define MUSTATESSAVENEWGAME_H

#include "types.h"

// MUStatesSaveNewGame - struct layout extracted from assembly analysis
// Estimated minimum size: 0x58DC (22748 bytes)
// 11 known fields (0 named), 12 methods

class MUStatesSaveNewGame {
public:
    // Constructors / Destructors
    MUStatesSaveNewGame(int)  // 0x801CEB2C
    ~MUStatesSaveNewGame(void);  // 0x801CEBA4

    // Methods
    void Reset(void);  // 0x801C7E04 (88B)
    void Draw(ERC *);  // 0x801C7E5C (172B)
    /* ? */ GetWrapper(void);  // 0x801CEC00 (80B)
    void Update(float);  // 0x801C7F08 (4268B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Draw, Update)
    u8 _pad_00C[0xC];  // 0x00C
    u32 m_field_018;  // 0x018 [R] (Update)
    u32 m_field_01C;  // 0x01C [R/W] (Draw, Update)
    s16 m_field_020;  // 0x020 [R/W] (Update)
    u8 _pad_022[2];  // 0x022
    f32 m_field_024;  // 0x024 [R/W] (Update)
    s16 m_field_028;  // 0x028 [R] (Update)
    u8 _pad_02A[2];  // 0x02A
    u32 m_field_02C;  // 0x02C [R] (Update)
    u8 _pad_030[0x60];  // 0x030
    u32 m_field_090;  // 0x090 [R/W] (Update)
    u8 _pad_094[4];  // 0x094
    u32 m_field_098;  // 0x098 [R] (Update)
    u8 _pad_09C[0x10];  // 0x09C
    u32 m_field_0AC;  // 0x0AC [W] (Update)
    u8 _pad_0B0[0x5828];  // 0x0B0
    u32 m_field_58D8;  // 0x58D8 [R] (Update)
};

#endif // MUSTATESSAVENEWGAME_H
