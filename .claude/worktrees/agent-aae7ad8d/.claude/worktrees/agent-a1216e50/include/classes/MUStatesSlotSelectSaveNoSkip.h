#ifndef MUSTATESSLOTSELECTSAVENOSKIP_H
#define MUSTATESSLOTSELECTSAVENOSKIP_H

#include "types.h"

// MUStatesSlotSelectSaveNoSkip - struct layout extracted from assembly analysis
// Estimated minimum size: 0x9C (156 bytes)
// 3 known fields (0 named), 8 methods

class MUStatesSlotSelectSaveNoSkip {
public:
    // Constructors / Destructors
    MUStatesSlotSelectSaveNoSkip(int)  // 0x801CE70C
    ~MUStatesSlotSelectSaveNoSkip(void);  // 0x801CE778

    // Methods
    void Update(float);  // 0x801C6BA4 (256B)
    /* ? */ GetWrapper(void);  // 0x801CE7C4 (80B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Update)
    u8 _pad_00C[0x84];  // 0x00C
    u32 m_field_090;  // 0x090 [R] (Update)
    u8 _pad_094[4];  // 0x094
    u32 m_field_098;  // 0x098 [R] (Update)
};

#endif // MUSTATESSLOTSELECTSAVENOSKIP_H
