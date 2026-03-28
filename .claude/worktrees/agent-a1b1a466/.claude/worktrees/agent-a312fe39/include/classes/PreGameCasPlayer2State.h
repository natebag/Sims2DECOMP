#ifndef PREGAMECASPLAYER2STATE_H
#define PREGAMECASPLAYER2STATE_H

#include "types.h"

// PreGameCasPlayer2State - struct layout extracted from assembly analysis
// Estimated minimum size: 0x30 (48 bytes)
// 3 known fields (0 named), 12 methods

class PreGameCasPlayer2State {
public:
    // Constructors / Destructors
    PreGameCasPlayer2State(int)  // 0x801D4604
    ~PreGameCasPlayer2State(void);  // 0x801D3958

    // Methods
    void Startup(void);  // 0x801D063C (148B)
    void Shutdown(void);  // 0x801D06D0 (76B)
    void Reset(void);  // 0x801D071C (264B)
    void Update(float);  // 0x801D0824 (132B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x20];  // 0x000
    u32 m_field_020;  // 0x020 [R] (Update)
    u8 _pad_024[4];  // 0x024
    u32 m_field_028;  // 0x028 [R] (Update)
    u32 m_field_02C;  // 0x02C [R] (Update)
};

#endif // PREGAMECASPLAYER2STATE_H
