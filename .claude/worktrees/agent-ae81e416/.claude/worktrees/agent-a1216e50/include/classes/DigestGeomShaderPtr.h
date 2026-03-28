#ifndef DIGESTGEOMSHADERPTR_H
#define DIGESTGEOMSHADERPTR_H

#include "types.h"

// DigestGeomShaderPtr - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 2 known fields (2 named), 2 methods

class DigestGeomShaderPtr {
public:
    // Methods
    void UpdateShaderFlags(bool &);  // 0x80618628 (264B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    u32 m_shaderFlags;  // 0x004 [R] (UpdateShaderFlags)
    u32 m_shaderFlags_008;  // 0x008 [R/W] (UpdateShaderFlags)
};

#endif // DIGESTGEOMSHADERPTR_H
