#ifndef AUTONOMYCONSTANTSCLIENT_H
#define AUTONOMYCONSTANTSCLIENT_H

#include "types.h"

// AutonomyConstantsClient - struct layout extracted from assembly analysis
// Estimated minimum size: 0x70 (112 bytes)
// 3 known fields (3 named), 4 methods

class AutonomyConstantsClient {
public:
    // Constructors / Destructors
    AutonomyConstantsClient(void)  // 0x8037AFFC

    // Methods
    void UpdateConstants(void);  // 0x80352118 (1476B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_constants;  // 0x000 [R] (UpdateConstants)
    u8 _pad_004[0x64];  // 0x004
    s16 m_constants_068;  // 0x068 [R] (UpdateConstants)
    u8 _pad_06A[2];  // 0x06A
    u32 m_constants_06C;  // 0x06C [R] (UpdateConstants)
};

#endif // AUTONOMYCONSTANTSCLIENT_H
