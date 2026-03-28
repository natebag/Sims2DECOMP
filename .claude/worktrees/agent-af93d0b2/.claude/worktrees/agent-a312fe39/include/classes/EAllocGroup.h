#ifndef EALLOCGROUP_H
#define EALLOCGROUP_H

#include "types.h"

// EAllocGroup - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 6 known fields (1 named), 17 methods

class EAllocGroup {
public:
    // Constructors / Destructors
    EAllocGroup(int)  // 0x808F8CCC
    ~EAllocGroup(void);  // 0x807D301C

    // Methods
    void MoveContents(EAllocGroup &);  // 0x808F92BC (116B)
    void RemoveAllocExternal(void *);  // 0x808F9330 (192B)
    void DeallocateAll(void);  // 0x808F921C (160B)
    void Alloc(unsigned int, int);  // 0x808F8DDC (784B)
    void SetAllocHeap(EAHeap *);  // 0x808F8D38 (164B)
    bool IsEmpty(void);  // 0x808F9500 (68B)
    void Validate(void);  // 0x808F90EC (304B)
    void AllocExternal(void *);  // 0x8090C724 (64B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (EAllocGroup)
    u32 m_field_004;  // 0x004 [R/W] (Alloc, DeallocateAll, EAllocGroup)
    u32 m_field_008;  // 0x008 [W] (EAllocGroup)
    u32 m_field_00C;  // 0x00C [R/W] (Alloc, DeallocateAll, EAllocGroup)
    u32 m_field_010;  // 0x010 [R/W] (Alloc, DeallocateAll, EAllocGroup, ...)
    u32 m_field_014;  // 0x014 [R/W] (Alloc, DeallocateAll, EAllocGroup, ...)
};

#endif // EALLOCGROUP_H
