#ifndef SETVAR_EYE_SAVETOSLOTSTATUS_H
#define SETVAR_EYE_SAVETOSLOTSTATUS_H

#include "types.h"

// SetVar_EYE_saveToSlotStatus - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 6 known fields (3 named), 6 methods

class SetVar_EYE_saveToSlotStatus {
public:
    // Constructors / Destructors
    SetVar_EYE_saveToSlotStatus(char *)  // 0x80593BF0
    ~SetVar_EYE_saveToSlotStatus(void);  // 0x80591BF4

    // Methods
    void Handler(char *);  // 0x80569E38 (260B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (SetVar_EYE_saveToSlotStatus)
    u32 m_var_EYE_saveToSlotStatus_004;  // 0x004 [W] (SetVar_EYE_saveToSlotStatus)
    u32 m_var_EYE_saveToSlotStatus_008;  // 0x008 [W] (SetVar_EYE_saveToSlotStatus)
    u8 _pad_00C[4];  // 0x00C
    u16 m_field_010;  // 0x010 [R] (Handler)
    u16 m_field_012;  // 0x012 [R] (Handler)
    u8 _pad_014[0x10];  // 0x014
    u32 m_field_024;  // 0x024 [R] (Handler)
};

#endif // SETVAR_EYE_SAVETOSLOTSTATUS_H
