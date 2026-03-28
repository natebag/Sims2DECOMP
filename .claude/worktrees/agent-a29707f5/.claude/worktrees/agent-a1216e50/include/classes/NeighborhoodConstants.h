#ifndef NEIGHBORHOODCONSTANTS_H
#define NEIGHBORHOODCONSTANTS_H

#include "types.h"

// NeighborhoodConstants - struct layout extracted from assembly analysis
// Estimated minimum size: 0x70 (112 bytes)
// 3 known fields (3 named), 4 methods

class NeighborhoodConstants {
public:
    // Constructors / Destructors
    NeighborhoodConstants(void)  // 0x8028A270

    // Methods
    void UpdateConstants(void);  // 0x80279834 (1220B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_constants;  // 0x000 [R] (UpdateConstants)
    u8 _pad_004[0x64];  // 0x004
    s16 m_constants_068;  // 0x068 [R] (UpdateConstants)
    u8 _pad_06A[2];  // 0x06A
    u32 m_constants_06C;  // 0x06C [R] (UpdateConstants)
};

#endif // NEIGHBORHOODCONSTANTS_H
