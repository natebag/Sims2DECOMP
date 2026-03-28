#ifndef BACKGROUNDPANE_H
#define BACKGROUNDPANE_H

#include "types.h"

// BackgroundPane - struct layout extracted from assembly analysis
// Estimated minimum size: 0x60 (96 bytes)
// 2 known fields (0 named), 3 methods

class BackgroundPane {
public:
    // Constructors / Destructors
    BackgroundPane(int, int, int, int)  // 0x801E98FC
    ~BackgroundPane(void);  // 0x801EA0BC

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (~BackgroundPane)
    u8 _pad_00C[0x50];  // 0x00C
    u32 m_field_05C;  // 0x05C [W] (~BackgroundPane)
};

#endif // BACKGROUNDPANE_H
