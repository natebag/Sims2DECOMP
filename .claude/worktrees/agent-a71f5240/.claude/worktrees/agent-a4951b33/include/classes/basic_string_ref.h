#ifndef BASIC_STRING_REF_H
#define BASIC_STRING_REF_H

#include "types.h"

// basic_string_ref - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (1 named), 24 methods

class basic_string_ref {
public:
    // Constructors / Destructors
    basic_string_ref(void)  // 0x801F01D8
    basic_string_ref(unsigned int, BString::capacity)  // 0x801F020C
    basic_string_ref(BString &, unsigned int, unsigned int)  // 0x801F0384
    basic_string_ref(char *, unsigned int, unsigned int)  // 0x801F046C
    basic_string_ref(char *, unsigned int)  // 0x801F0550
    basic_string_ref(char *)  // 0x801F0634
    basic_string_ref(char, unsigned int)  // 0x801F072C
    ~basic_string_ref(void);  // 0x801F0848

    // Methods
    void delete_ptr(void);  // 0x801EF43C (88B)
    void throwlength(void);  // 0x801EF494 (132B)
    void throwrange(void);  // 0x801EF518 (132B)
    void eos(void);  // 0x801F0198 (64B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (basic_string_ref, delete_ptr)
    u32 m_field_004;  // 0x004 [R/W] (basic_string_ref)
    u32 m_field_008;  // 0x008 [R/W] (basic_string_ref, delete_ptr)
    u32 m_field_00C;  // 0x00C [W] (basic_string_ref)
};

#endif // BASIC_STRING_REF_H
