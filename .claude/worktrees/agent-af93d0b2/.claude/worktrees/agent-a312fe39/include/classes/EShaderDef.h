#ifndef ESHADERDEF_H
#define ESHADERDEF_H

#include "types.h"

// EShaderDef - struct layout extracted from assembly analysis
// Estimated minimum size: 0x34 (52 bytes)
// 8 known fields (0 named), 7 methods

class EShaderDef {
public:
    // Constructors / Destructors
    EShaderDef(void)  // 0x8001914C
    EShaderDef(EShaderDef &)  // 0x807D9FB0

    // Methods
    void operator=(EShaderDef &);  // 0x807D5844 (396B)
    bool IsAlphaShader(void);  // 0x807D6948 (72B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [W] (operator=)
    u8 m_field_001;  // 0x001 [W] (operator=)
    u16 m_field_002;  // 0x002 [W] (operator=)
    u32 m_field_004;  // 0x004 [W] (operator=)
    u32 m_field_008;  // 0x008 [W] (operator=)
    u32 m_field_00C;  // 0x00C [W] (operator=)
    f32 m_field_010;  // 0x010 [W] (operator=)
    u8 _pad_014[0x1C];  // 0x014
    u32 m_field_030;  // 0x030 [W] (operator=)
};

#endif // ESHADERDEF_H
