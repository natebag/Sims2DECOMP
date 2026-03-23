#ifndef EFRAMEALLOCGROUP_H
#define EFRAMEALLOCGROUP_H

#include "types.h"

// EFrameAllocGroup - struct layout extracted from assembly analysis
// Estimated minimum size: 0x38 (56 bytes)
// 2 known fields (1 named), 10 methods

class EFrameAllocGroup {
public:
    // Constructors / Destructors
    EFrameAllocGroup(void)  // 0x8081022C
    ~EFrameAllocGroup(void);  // 0x8080FF3C

    // Methods
    void Update(void);  // 0x80810030 (92B)
    void Alloc(unsigned int, int);  // 0x808102CC (100B)
    void ManagedShutdown(void);  // 0x8080FFE8 (72B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (EFrameAllocGroup, ~EFrameAllocGroup)
    u8 _pad_004[0x30];  // 0x004
    u32 m_field_034;  // 0x034 [W] (EFrameAllocGroup)
};

#endif // EFRAMEALLOCGROUP_H
