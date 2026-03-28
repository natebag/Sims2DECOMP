#ifndef SETVAR_EYE_STATE_H
#define SETVAR_EYE_STATE_H

#include "types.h"

// SetVar_EYE_state - struct layout extracted from assembly analysis
// Estimated minimum size: 0xB0 (176 bytes)
// 7 known fields (3 named), 6 methods

class SetVar_EYE_state {
public:
    // Constructors / Destructors
    SetVar_EYE_state(char *)  // 0x80593A4C
    ~SetVar_EYE_state(void);  // 0x80591AB4

    // Methods
    void Handler(char *);  // 0x80569958 (532B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (SetVar_EYE_state)
    u32 m_var_EYE_state_004;  // 0x004 [W] (SetVar_EYE_state)
    u32 m_var_EYE_state_008;  // 0x008 [W] (SetVar_EYE_state)
    u8 _pad_00C[4];  // 0x00C
    u16 m_field_010;  // 0x010 [R] (Handler)
    u16 m_field_012;  // 0x012 [R] (Handler)
    u8 _pad_014[0x10];  // 0x014
    u32 m_field_024;  // 0x024 [R] (Handler)
    u8 _pad_028[0x84];  // 0x028
    u32 m_field_0AC;  // 0x0AC [W] (Handler)
};

#endif // SETVAR_EYE_STATE_H
