#ifndef STARTSCREENVARS_H
#define STARTSCREENVARS_H

#include "types.h"

// StartScreenVars - struct layout extracted from assembly analysis
// Estimated minimum size: 0x38 (56 bytes)
// 14 known fields (0 named), 11 methods

class StartScreenVars {
public:
    // Constructors / Destructors
    StartScreenVars(void)  // 0x801D85A4

    // Methods
    void Startup(void);  // 0x801D4DA0 (248B)
    void Shutdown(void);  // 0x801D4E98 (120B)
    void Reset(void);  // 0x801D4F10 (212B)
    void Update(float);  // 0x801D4FE4 (124B)
    void DrawPressStart(ERC *);  // 0x801D5060 (272B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (Reset, Update)
    f32 m_field_004;  // 0x004 [W] (Reset)
    f32 m_field_008;  // 0x008 [R/W] (Reset, Update)
    u32 m_field_00C;  // 0x00C [R/W] (DrawPressStart, Reset, Update)
    f32 m_field_010;  // 0x010 [R/W] (Reset, Startup)
    f32 m_field_014;  // 0x014 [R/W] (Reset, Startup)
    f32 m_field_018;  // 0x018 [R/W] (Reset, Startup)
    f32 m_field_01C;  // 0x01C [W] (Reset)
    u32 m_field_020;  // 0x020 [R/W] (Shutdown, Startup)
    u32 m_field_024;  // 0x024 [W] (Reset)
    u32 m_field_028;  // 0x028 [W] (Reset)
    u32 m_field_02C;  // 0x02C [W] (Reset)
    u32 m_field_030;  // 0x030 [W] (Reset)
    f32 m_field_034;  // 0x034 [W] (Reset)
};

#endif // STARTSCREENVARS_H
