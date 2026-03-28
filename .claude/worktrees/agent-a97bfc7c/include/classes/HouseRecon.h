#ifndef HOUSERECON_H
#define HOUSERECON_H

#include "types.h"

// HouseRecon - struct layout extracted from assembly analysis
// Estimated minimum size: 0x6008 (24584 bytes)
// 5 known fields (1 named), 10 methods

class HouseRecon {
public:
    // Constructors / Destructors
    HouseRecon(void)  // 0x800CEB64
    ~HouseRecon(void);  // 0x800CEC00

    // Methods
    void LoadHouseData(iResFile *);  // 0x800CED44 (512B)
    void SaveHouseData(iResFile *, int);  // 0x800CEF44 (448B)
    void findHRSelector(int);  // 0x800CECB4 (144B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (LoadHouseData, SaveHouseData, findHRSelector)
    u32 m_field_004;  // 0x004 [R/W] (LoadHouseData, SaveHouseData)
    u32 m_field_008;  // 0x008 [W] (SaveHouseData)
    u8 _pad_00C[0xC];  // 0x00C
    u32 m_field_018;  // 0x018 [R] (SaveHouseData)
    u8 _pad_01C[0x5FE8];  // 0x01C
    u32 m_field_6004;  // 0x6004 [R] (findHRSelector)
};

#endif // HOUSERECON_H
