#ifndef EGROWPOOL_H
#define EGROWPOOL_H

#include "types.h"

// EGrowPool - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (1 named), 17 methods

class EGrowPool {
public:
    // Constructors / Destructors
    EGrowPool(void)  // 0x808FD0E4
    EGrowPool(int)  // 0x808FD124
    ~EGrowPool(void);  // 0x808FD174

    // Methods
    void SetBlockSize(int);  // 0x808DCECC (164B)
    void Alloc(void);  // 0x808DCF70 (140B)
    void Free(void *);  // 0x808DCFFC (88B)
    void AllocNewSeg(void);  // 0x808FD204 (360B)
    void Init(void);  // 0x808FD1CC (56B)
    void Reset(void);  // 0x808FD36C (164B)
    void FreeUnusedSegments(void);  // 0x808FD410 (1252B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AllocNewSeg, FreeUnusedSegments, Reset)
    u32 m_field_004;  // 0x004 [R/W] (AllocNewSeg, FreeUnusedSegments, Reset)
    u32 m_field_008;  // 0x008 [R/W] (AllocNewSeg, EGrowPool, FreeUnusedSegments, ...)
};

#endif // EGROWPOOL_H
