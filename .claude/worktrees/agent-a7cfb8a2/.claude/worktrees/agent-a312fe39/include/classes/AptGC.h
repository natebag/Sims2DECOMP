#ifndef APTGC_H
#define APTGC_H

#include "types.h"

// AptGC - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 2 known fields (1 named), 8 methods

class AptGC {
public:
    // Methods
    void CleanAll(void);  // 0x806E5160 (440B)
    void Initialize(void);  // 0x806E4DA0 (28B)
    void CleanUnreachable(void);  // 0x806E4E48 (792B)
    void sReferenceRegistrationCb(AptValue *, AptValue *, char *);  // 0x806E4DBC (140B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CleanUnreachable)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [R] (CleanUnreachable)
};

#endif // APTGC_H
