#ifndef APTBOOLEAN_H
#define APTBOOLEAN_H

#include "types.h"

// AptBoolean - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 2 known fields (0 named), 16 methods

class AptBoolean {
public:
    // Constructors / Destructors
    AptBoolean(bool)  // 0x80712C80
    ~AptBoolean(void);  // 0x80713058

    // Methods
    void ClearPool(void);  // 0x80712E74 (212B)
    void Create(bool);  // 0x80712CDC (320B)
    /* ? */ GetBool(void);  // 0x80712E48 (44B)
    void Destroy(void);  // 0x80712E1C (44B)
    void DeleteThis(void);  // 0x80712F48 (56B)
    void ForceDelete(void);  // 0x80712F80 (56B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R/W] (AptBoolean, ClearPool, Create, ...)
    u32 m_field_00C;  // 0x00C [R/W] (AptBoolean, ClearPool, Create)
};

#endif // APTBOOLEAN_H
