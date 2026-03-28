#ifndef MUSTATESFORMAT_H
#define MUSTATESFORMAT_H

#include "types.h"

// MUStatesFormat - struct layout extracted from assembly analysis
// Estimated minimum size: 0x9C (156 bytes)
// 5 known fields (0 named), 12 methods

class MUStatesFormat {
public:
    // Constructors / Destructors
    MUStatesFormat(int)  // 0x801CE4FC
    ~MUStatesFormat(void);  // 0x801CE568

    // Methods
    void Reset(void);  // 0x801C6420 (148B)
    /* ? */ GetWrapper(void);  // 0x801CE5B4 (80B)
    void Draw(ERC *);  // 0x801C64B4 (144B)
    void Update(float);  // 0x801C6544 (1384B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Draw, Reset, Update)
    u8 _pad_00C[0x10];  // 0x00C
    u32 m_field_01C;  // 0x01C [R/W] (Reset, Update)
    u32 m_field_020;  // 0x020 [R/W] (Draw, Reset, Update)
    u8 _pad_024[0x6C];  // 0x024
    u32 m_field_090;  // 0x090 [R/W] (Update)
    u8 _pad_094[4];  // 0x094
    u32 m_field_098;  // 0x098 [R] (Update)
};

#endif // MUSTATESFORMAT_H
