#ifndef PREGAMESTATE_H
#define PREGAMESTATE_H

#include "types.h"

// PreGameState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x88 (136 bytes)
// 11 known fields (0 named), 12 methods

class PreGameState {
public:
    // Constructors / Destructors
    PreGameState(int)  // 0x801D44C8
    ~PreGameState(void);  // 0x801D38D8

    // Methods
    void Reset(void);  // 0x801CF618 (160B)
    void Update(float);  // 0x801CF6B8 (2812B)
    void InsertPlayer2Roommate(void);  // 0x801D01B4 (652B)
    void SetFlowStateCurrent(void);  // 0x801D4554 (72B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (InsertPlayer2Roommate, Update)
    s16 m_field_004;  // 0x004 [R] (InsertPlayer2Roommate)
    u8 _pad_006[2];  // 0x006
    u32 m_field_008;  // 0x008 [R] (Update)
    u32 m_field_00C;  // 0x00C [R/W] (Reset, Update)
    u8 _pad_010[0xC];  // 0x010
    u32 m_field_01C;  // 0x01C [R/W] (Reset, Update)
    u32 m_field_020;  // 0x020 [R/W] (Reset, Update)
    u32 m_field_024;  // 0x024 [R/W] (Reset, Update)
    u32 m_field_028;  // 0x028 [R/W] (Reset, Update)
    u32 m_field_02C;  // 0x02C [R/W] (Reset, Update)
    u8 _pad_030[4];  // 0x030
    u32 m_field_034;  // 0x034 [R/W] (Update)
    u8 _pad_038[0x4C];  // 0x038
    u32 m_field_084;  // 0x084 [R] (Update)
};

#endif // PREGAMESTATE_H
