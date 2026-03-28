#ifndef BASIC_STRING_REF2_H
#define BASIC_STRING_REF2_H

#include "types.h"

// basic_string_ref2 - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (1 named), 24 methods

class basic_string_ref2 {
public:
    // Constructors / Destructors
    basic_string_ref2(void)  // 0x801F6BA8
    basic_string_ref2(unsigned int, BString2::capacity)  // 0x801F6BDC
    basic_string_ref2(BString2 &, unsigned int, unsigned int)  // 0x801F6D64
    basic_string_ref2(unsigned wchar_t *, unsigned int, unsigned int)  // 0x801F6E5C
    basic_string_ref2(unsigned wchar_t *, unsigned int)  // 0x801F6F48
    basic_string_ref2(unsigned wchar_t *)  // 0x801F7034
    basic_string_ref2(wchar_t, unsigned int)  // 0x801F7134
    ~basic_string_ref2(void);  // 0x801F7260

    // Methods
    void delete_ptr(void);  // 0x801F5E60 (88B)
    void throwlength(void);  // 0x801F5EB8 (132B)
    void throwrange(void);  // 0x801F5F3C (132B)
    void eos(void);  // 0x801F6B6C (60B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (basic_string_ref2, delete_ptr)
    u32 m_field_004;  // 0x004 [R/W] (basic_string_ref2)
    u32 m_field_008;  // 0x008 [R/W] (basic_string_ref2, delete_ptr)
    u32 m_field_00C;  // 0x00C [W] (basic_string_ref2)
};

#endif // BASIC_STRING_REF2_H
