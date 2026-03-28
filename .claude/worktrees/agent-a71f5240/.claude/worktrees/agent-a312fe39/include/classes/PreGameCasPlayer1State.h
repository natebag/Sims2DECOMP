#ifndef PREGAMECASPLAYER1STATE_H
#define PREGAMECASPLAYER1STATE_H

#include "types.h"

// PreGameCasPlayer1State - struct layout extracted from assembly analysis
// Estimated minimum size: 0x30 (48 bytes)
// 3 known fields (0 named), 12 methods

class PreGameCasPlayer1State {
public:
    // Constructors / Destructors
    PreGameCasPlayer1State(int)  // 0x801D459C
    ~PreGameCasPlayer1State(void);  // 0x801D3918

    // Methods
    void Startup(void);  // 0x801D0440 (56B)
    void Shutdown(void);  // 0x801D0478 (56B)
    void Reset(void);  // 0x801D04B0 (264B)
    void Update(float);  // 0x801D05B8 (132B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x20];  // 0x000
    u32 m_field_020;  // 0x020 [R] (Update)
    u8 _pad_024[4];  // 0x024
    u32 m_field_028;  // 0x028 [R] (Update)
    u32 m_field_02C;  // 0x02C [R] (Update)
};

#endif // PREGAMECASPLAYER1STATE_H
