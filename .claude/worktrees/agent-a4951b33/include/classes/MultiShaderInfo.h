#ifndef MULTISHADERINFO_H
#define MULTISHADERINFO_H

#include "types.h"

// MultiShaderInfo - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 2 known fields (0 named), 5 methods

class MultiShaderInfo {
public:
    // Constructors / Destructors
    MultiShaderInfo(void)  // 0x8086FA38
    ~MultiShaderInfo(void);  // 0x8086FA8C

    // Methods
    void AllocShaderIdLists(void);  // 0x8086FAE0 (156B)
    void DeAlloc(void);  // 0x80871568 (120B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0xC];  // 0x000
    u32 m_field_00C;  // 0x00C [R/W] (DeAlloc)
    u32 m_field_010;  // 0x010 [R/W] (DeAlloc)
};

#endif // MULTISHADERINFO_H
