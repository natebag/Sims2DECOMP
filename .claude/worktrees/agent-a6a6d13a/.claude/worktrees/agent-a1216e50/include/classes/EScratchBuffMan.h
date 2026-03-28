#ifndef ESCRATCHBUFFMAN_H
#define ESCRATCHBUFFMAN_H

#include "types.h"

// EScratchBuffMan - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 5 known fields (1 named), 12 methods

class EScratchBuffMan {
public:
    // Constructors / Destructors
    EScratchBuffMan(void)  // 0x808997C4
    ~EScratchBuffMan(void);  // 0x80899818

    // Methods
    /* ? */ GetBuffSize(void);  // 0x8084C1BC (44B)
    /* ? */ GetCurOwner(void);  // 0x8084C1E8 (44B)
    void Init(void);  // 0x80899904 (388B)
    void TryAcquireBuffer(EScratchBuffUser *, char *, int);  // 0x80899A88 (448B)
    void ReleaseBuffer(EScratchBuffUser *);  // 0x80899C48 (140B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ReleaseBuffer, TryAcquireBuffer)
    u32 m_field_004;  // 0x004 [W] (ReleaseBuffer, TryAcquireBuffer)
    u32 m_field_008;  // 0x008 [R/W] (ReleaseBuffer, TryAcquireBuffer)
    u32 m_field_00C;  // 0x00C [R/W] (Init, TryAcquireBuffer, ~EScratchBuffMan)
    u32 m_field_010;  // 0x010 [R/W] (Init)
};

#endif // ESCRATCHBUFFMAN_H
