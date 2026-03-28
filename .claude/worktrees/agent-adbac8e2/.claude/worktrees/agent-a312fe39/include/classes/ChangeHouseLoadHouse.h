#ifndef CHANGEHOUSELOADHOUSE_H
#define CHANGEHOUSELOADHOUSE_H

#include "types.h"

// ChangeHouseLoadHouse - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 5 known fields (0 named), 14 methods

class ChangeHouseLoadHouse {
public:
    // Constructors / Destructors
    ChangeHouseLoadHouse(int)  // 0x801C0844
    ~ChangeHouseLoadHouse(void);  // 0x801BE624

    // Methods
    void DatasetGetRef(void);  // 0x801B5894 (216B)
    void DatasetFinishAddRefAsync(void);  // 0x801B596C (72B)
    void Reset(void);  // 0x801B59B4 (184B)
    void Update(float);  // 0x801B5A6C (4580B)
    void DatasetPendingAddRefAsync(void);  // 0x801C08B8 (60B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (Update)
    s16 m_field_004;  // 0x004 [R] (Update)
    u8 _pad_006[2];  // 0x006
    u32 m_field_008;  // 0x008 [R] (Update)
    u32 m_field_00C;  // 0x00C [R/W] (Reset, Update)
    u8 _pad_010[0xC];  // 0x010
    u32 m_field_01C;  // 0x01C [R/W] (DatasetGetRef, Reset, Update)
};

#endif // CHANGEHOUSELOADHOUSE_H
