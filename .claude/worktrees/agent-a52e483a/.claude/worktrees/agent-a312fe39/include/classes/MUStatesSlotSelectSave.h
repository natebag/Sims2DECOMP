#ifndef MUSTATESSLOTSELECTSAVE_H
#define MUSTATESSLOTSELECTSAVE_H

#include "types.h"

// MUStatesSlotSelectSave - struct layout extracted from assembly analysis
// Estimated minimum size: 0x94 (148 bytes)
// 2 known fields (0 named), 8 methods

class MUStatesSlotSelectSave {
public:
    // Constructors / Destructors
    MUStatesSlotSelectSave(int)  // 0x801CE604
    ~MUStatesSlotSelectSave(void);  // 0x801CE670

    // Methods
    void Update(float);  // 0x801C6AAC (248B)
    /* ? */ GetWrapper(void);  // 0x801CE6BC (80B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Update)
    u8 _pad_00C[0x84];  // 0x00C
    u32 m_field_090;  // 0x090 [R] (Update)
};

#endif // MUSTATESSLOTSELECTSAVE_H
