#ifndef DIALOGPANE_H
#define DIALOGPANE_H

#include "types.h"

// DialogPane - struct layout extracted from assembly analysis
// Estimated minimum size: 0x60 (96 bytes)
// 2 known fields (0 named), 3 methods

class DialogPane {
public:
    // Constructors / Destructors
    DialogPane(int, int)  // 0x80188C4C
    ~DialogPane(void);  // 0x80189EF4

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (~DialogPane)
    u8 _pad_00C[0x50];  // 0x00C
    u32 m_field_05C;  // 0x05C [W] (~DialogPane)
};

#endif // DIALOGPANE_H
