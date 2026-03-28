#ifndef MUSTATESLOADHOUSE_H
#define MUSTATESLOADHOUSE_H

#include "types.h"

// MUStatesLoadHouse - struct layout extracted from assembly analysis
// Estimated minimum size: 0x94 (148 bytes)
// 4 known fields (0 named), 12 methods

class MUStatesLoadHouse {
public:
    // Constructors / Destructors
    MUStatesLoadHouse(int)  // 0x801CE91C
    ~MUStatesLoadHouse(void);  // 0x801CE988

    // Methods
    void Reset(void);  // 0x801C75C0 (64B)
    void Draw(ERC *);  // 0x801C7600 (64B)
    void Update(float);  // 0x801C7640 (1064B)
    /* ? */ GetWrapper(void);  // 0x801CE9D4 (80B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Update)
    u8 _pad_00C[0x10];  // 0x00C
    u32 m_field_01C;  // 0x01C [R/W] (Update)
    f32 m_field_020;  // 0x020 [R/W] (Update)
    u8 _pad_024[0x6C];  // 0x024
    u32 m_field_090;  // 0x090 [R/W] (Update)
};

#endif // MUSTATESLOADHOUSE_H
