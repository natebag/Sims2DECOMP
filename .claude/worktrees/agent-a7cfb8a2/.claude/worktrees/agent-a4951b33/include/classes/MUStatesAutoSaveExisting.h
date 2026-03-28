#ifndef MUSTATESAUTOSAVEEXISTING_H
#define MUSTATESAUTOSAVEEXISTING_H

#include "types.h"

// MUStatesAutoSaveExisting - struct layout extracted from assembly analysis
// Estimated minimum size: 0x24 (36 bytes)
// 3 known fields (0 named), 10 methods

class MUStatesAutoSaveExisting {
public:
    // Constructors / Destructors
    MUStatesAutoSaveExisting(int)  // 0x801CEC50
    ~MUStatesAutoSaveExisting(void);  // 0x801CECBC

    // Methods
    void Reset(void);  // 0x801C8FB4 (76B)
    void Update(float);  // 0x801C9000 (812B)
    /* ? */ GetWrapper(void);  // 0x801CED08 (80B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Update)
    u8 _pad_00C[0x10];  // 0x00C
    u32 m_field_01C;  // 0x01C [R/W] (Update)
    u32 m_field_020;  // 0x020 [R/W] (Update)
};

#endif // MUSTATESAUTOSAVEEXISTING_H
