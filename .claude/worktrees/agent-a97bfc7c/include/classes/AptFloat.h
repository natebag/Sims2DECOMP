#ifndef APTFLOAT_H
#define APTFLOAT_H

#include "types.h"

// AptFloat - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 3 known fields (1 named), 16 methods

class AptFloat {
public:
    // Constructors / Destructors
    AptFloat(float)  // 0x80713278
    ~AptFloat(void);  // 0x80713650

    // Methods
    void ClearPool(void);  // 0x8071346C (212B)
    void Create(float);  // 0x807132D4 (320B)
    /* ? */ GetFloat(void);  // 0x80713440 (44B)
    void Destroy(void);  // 0x80713414 (44B)
    void DeleteThis(void);  // 0x80713540 (56B)
    void ForceDelete(void);  // 0x80713578 (56B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Create)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [R/W] (AptFloat, ClearPool, Create, ...)
    f32 m_field_00C;  // 0x00C [R/W] (AptFloat, ClearPool, Create)
};

#endif // APTFLOAT_H
