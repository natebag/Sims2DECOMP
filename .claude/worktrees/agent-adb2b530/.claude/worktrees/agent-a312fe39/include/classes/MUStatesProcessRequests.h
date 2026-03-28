#ifndef MUSTATESPROCESSREQUESTS_H
#define MUSTATESPROCESSREQUESTS_H

#include "types.h"

// MUStatesProcessRequests - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 3 known fields (0 named), 8 methods

class MUStatesProcessRequests {
public:
    // Constructors / Destructors
    MUStatesProcessRequests(int)  // 0x801CE3F4
    ~MUStatesProcessRequests(void);  // 0x801CE460

    // Methods
    void Update(float);  // 0x801C5E64 (1084B)
    /* ? */ GetWrapper(void);  // 0x801CE4AC (80B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Update)
    u8 _pad_00C[0x10];  // 0x00C
    u32 m_field_01C;  // 0x01C [R/W] (Update)
    u8 _pad_020[4];  // 0x020
    u32 m_field_024;  // 0x024 [W] (Update)
};

#endif // MUSTATESPROCESSREQUESTS_H
