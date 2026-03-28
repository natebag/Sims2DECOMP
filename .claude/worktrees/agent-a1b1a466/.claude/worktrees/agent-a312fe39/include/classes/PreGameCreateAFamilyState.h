#ifndef PREGAMECREATEAFAMILYSTATE_H
#define PREGAMECREATEAFAMILYSTATE_H

#include "types.h"

// PreGameCreateAFamilyState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x30 (48 bytes)
// 3 known fields (0 named), 8 methods

class PreGameCreateAFamilyState {
public:
    // Constructors / Destructors
    PreGameCreateAFamilyState(int)  // 0x801D466C
    ~PreGameCreateAFamilyState(void);  // 0x801D3998

    // Methods
    void Reset(void);  // 0x801D08A8 (80B)
    void Update(float);  // 0x801D08F8 (220B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x20];  // 0x000
    u32 m_field_020;  // 0x020 [R] (Update)
    u8 _pad_024[4];  // 0x024
    u32 m_field_028;  // 0x028 [R] (Update)
    u32 m_field_02C;  // 0x02C [R] (Update)
};

#endif // PREGAMECREATEAFAMILYSTATE_H
