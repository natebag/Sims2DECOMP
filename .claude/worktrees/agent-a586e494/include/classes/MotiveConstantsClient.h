#ifndef MOTIVECONSTANTSCLIENT_H
#define MOTIVECONSTANTSCLIENT_H

#include "types.h"

// MotiveConstantsClient - struct layout extracted from assembly analysis
// Estimated minimum size: 0x70 (112 bytes)
// 3 known fields (3 named), 4 methods

class MotiveConstantsClient {
public:
    // Constructors / Destructors
    MotiveConstantsClient(void)  // 0x8025F018

    // Methods
    void UpdateConstants(void);  // 0x8025D720 (4196B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_constants;  // 0x000 [R] (UpdateConstants)
    u8 _pad_004[0x64];  // 0x004
    s16 m_constants_068;  // 0x068 [R] (UpdateConstants)
    u8 _pad_06A[2];  // 0x06A
    u32 m_constants_06C;  // 0x06C [R] (UpdateConstants)
};

#endif // MOTIVECONSTANTSCLIENT_H
