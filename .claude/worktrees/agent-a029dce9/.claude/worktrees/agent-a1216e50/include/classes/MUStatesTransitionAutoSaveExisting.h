#ifndef MUSTATESTRANSITIONAUTOSAVEEXISTING_H
#define MUSTATESTRANSITIONAUTOSAVEEXISTING_H

#include "types.h"

// MUStatesTransitionAutoSaveExisting - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 4 known fields (0 named), 10 methods

class MUStatesTransitionAutoSaveExisting {
public:
    // Constructors / Destructors
    MUStatesTransitionAutoSaveExisting(int)  // 0x801CEE60
    ~MUStatesTransitionAutoSaveExisting(void);  // 0x801CEECC

    // Methods
    void Reset(void);  // 0x801C997C (76B)
    void Update(float);  // 0x801C99C8 (848B)
    /* ? */ GetWrapper(void);  // 0x801CEF18 (80B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Update)
    u8 _pad_00C[0x10];  // 0x00C
    u32 m_field_01C;  // 0x01C [R/W] (Update)
    u32 m_field_020;  // 0x020 [R/W] (Update)
    u32 m_field_024;  // 0x024 [W] (Update)
};

#endif // MUSTATESTRANSITIONAUTOSAVEEXISTING_H
