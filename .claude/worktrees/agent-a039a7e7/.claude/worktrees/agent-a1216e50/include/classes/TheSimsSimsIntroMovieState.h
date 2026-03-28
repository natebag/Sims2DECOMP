#ifndef THESIMSSIMSINTROMOVIESTATE_H
#define THESIMSSIMSINTROMOVIESTATE_H

#include "types.h"

// TheSimsSimsIntroMovieState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 3 known fields (0 named), 10 methods

class TheSimsSimsIntroMovieState {
public:
    // Constructors / Destructors
    TheSimsSimsIntroMovieState(int)  // 0x801E8F60
    ~TheSimsSimsIntroMovieState(void);  // 0x801E8FD4

    // Methods
    void Startup(void);  // 0x801E0660 (604B)
    void Shutdown(void);  // 0x801E08BC (136B)
    void Update(float);  // 0x801E0944 (264B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Update)
    u8 _pad_00C[0x14];  // 0x00C
    u32 m_field_020;  // 0x020 [R/W] (Startup, Update)
    u32 m_field_024;  // 0x024 [R/W] (Shutdown, Startup)
};

#endif // THESIMSSIMSINTROMOVIESTATE_H
