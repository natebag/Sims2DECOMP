#ifndef WALLFADEPARMS_H
#define WALLFADEPARMS_H

#include "types.h"

// WallFadeParms - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 6 known fields (0 named), 10 methods

class WallFadeParms {
public:
    // Constructors / Destructors
    WallFadeParms(char *, float, float, bool)  // 0x80079824
    ~WallFadeParms(void);  // 0x8007EDCC

    // Methods
    void Validate(void);  // 0x80079908 (116B)
    /* ? */ GetWindowName(void);  // 0x8007997C (44B)
    void SetupWindow(CUIWindow *);  // 0x800799A8 (440B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    f32 m_field_004;  // 0x004 [R/W] (Validate)
    f32 m_field_008;  // 0x008 [R] (Validate)
    u8 _pad_00C[0xC];  // 0x00C
    f32 m_field_018;  // 0x018 [R] (Validate)
    f32 m_field_01C;  // 0x01C [W] (Validate)
    f32 m_field_020;  // 0x020 [W] (Validate)
    f32 m_field_024;  // 0x024 [W] (Validate)
};

#endif // WALLFADEPARMS_H
