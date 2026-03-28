#ifndef ESIMSHADOW_H
#define ESIMSHADOW_H

#include "types.h"

// ESimShadow - struct layout extracted from assembly analysis
// Estimated minimum size: 0x324 (804 bytes)
// 2 known fields (2 named), 8 methods

class ESimShadow {
public:
    // Constructors / Destructors
    ESimShadow(cXPerson *)  // 0x8008CAEC
    ~ESimShadow(void);  // 0x8008CB40

    // Methods
    void DrawShadow(ELevelDrawData &);  // 0x800850F8 (144B)
    /* ? */ GetShadowCenter(EVec3 &);  // 0x80085188 (192B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ESimShadow, GetShadowCenter, ~ESimShadow)
    u8 _pad_004[0x31C];  // 0x004
    u32 m_shadowCenter_320;  // 0x320 [R/W] (DrawShadow, ESimShadow, GetShadowCenter, ...)
};

#endif // ESIMSHADOW_H
