#ifndef MUSTATESLOADCONFIG_H
#define MUSTATESLOADCONFIG_H

#include "types.h"

// MUStatesLoadConfig - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 2 known fields (0 named), 12 methods

class MUStatesLoadConfig {
public:
    // Constructors / Destructors
    MUStatesLoadConfig(int)  // 0x801CF070
    ~MUStatesLoadConfig(void);  // 0x801CF0DC

    // Methods
    void Reset(void);  // 0x801CA2E8 (64B)
    void Draw(ERC *);  // 0x801CA328 (160B)
    /* ? */ GetWrapper(void);  // 0x801CF128 (80B)
    void Update(float);  // 0x801CA3C8 (228B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Draw)
    u8 _pad_00C[0x10];  // 0x00C
    u32 m_field_01C;  // 0x01C [R] (Draw)
};

#endif // MUSTATESLOADCONFIG_H
