#ifndef APTINTEGER_H
#define APTINTEGER_H

#include "types.h"

// AptInteger - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 2 known fields (0 named), 16 methods

class AptInteger {
public:
    // Constructors / Destructors
    AptInteger(int)  // 0x80713870
    ~AptInteger(void);  // 0x80713C48

    // Methods
    void ClearPool(void);  // 0x80713A64 (212B)
    void Create(int);  // 0x807138CC (320B)
    /* ? */ GetInt(void);  // 0x80713A38 (44B)
    void Destroy(void);  // 0x80713A0C (44B)
    void DeleteThis(void);  // 0x80713B38 (56B)
    void ForceDelete(void);  // 0x80713B70 (56B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R/W] (AptInteger, ClearPool, Create, ...)
    u32 m_field_00C;  // 0x00C [R/W] (AptInteger, ClearPool, Create)
};

#endif // APTINTEGER_H
