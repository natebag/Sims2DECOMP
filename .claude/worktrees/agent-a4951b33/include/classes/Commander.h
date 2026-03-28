#ifndef COMMANDER_H
#define COMMANDER_H

#include "types.h"

// Commander - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 2 known fields (1 named), 10 methods

class Commander {
public:
    // Constructors / Destructors
    Commander(void)  // 0x8022E67C
    ~Commander(void);  // 0x8022E6E4

    // Methods
    void DoCommand(short, int);  // 0x8022E804 (52B)
    /* ? */ GetType(void);  // 0x8022EA28 (44B)
    /* ? */ GetNext(void);  // 0x8022EA54 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R] - vtable pointer (~Commander)
    u8 _pad_004[8];  // 0x004
    u32 m_field_00C;  // 0x00C [W] (~Commander)
};

#endif // COMMANDER_H
