#ifndef FASTALLOCPOOL_H
#define FASTALLOCPOOL_H

#include "types.h"

// FastAllocPool - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 6 known fields (1 named), 36 methods

class FastAllocPool {
public:
    // Static members (from map file)
    // static ??? ALIGNMENT;

    // Constructors / Destructors
    FastAllocPool(char *, void *, int, int)  // 0x8077B44C
    ~FastAllocPool(void);  // 0x8077B560

    // Methods
    void Alloc(void);  // 0x8077BF7C (648B)
    void BlockIsInPool(void *);  // 0x8077BF10 (108B)
    void Free(void *);  // 0x8077C204 (460B)
    void Init(void *, int, int);  // 0x8077B620 (356B)
    /* ? */ GetPoolSize(void);  // 0x8077BC3C (52B)
    /* ? */ GetAlignment(void);  // 0x8077BBE4 (44B)
    /* ? */ GetPoolStart(void);  // 0x8077BC10 (44B)
    void Valid(void);  // 0x8077B784 (676B)
    /* ? */ GetBlockSize(void);  // 0x8077BC70 (44B)
    /* ? */ GetPoolBlocks(void);  // 0x8077BC9C (44B)
    /* ? */ GetMemFree(void);  // 0x8077BCC8 (84B)
    /* ? */ GetMemUsed(void);  // 0x8077BD1C (52B)
    /* ? */ GetCurrentAllocs(void);  // 0x8077BD50 (44B)
    /* ? */ GetTotalAllocs(void);  // 0x8077BD7C (44B)
    /* ? */ GetMaxAllocs(void);  // 0x8077BDA8 (44B)
    /* ? */ GetOverFlowAllocs(void);  // 0x8077BDD4 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (FastAllocPool, Init, Valid)
    u32 m_field_004;  // 0x004 [R/W] (FastAllocPool, Init, Valid)
    u32 m_field_008;  // 0x008 [R/W] (FastAllocPool, Init, Valid)
    u32 m_field_00C;  // 0x00C [R/W] (FastAllocPool, Init, Valid)
    u32 m_field_010;  // 0x010 [W] (FastAllocPool, Init)
    u32 m_field_014;  // 0x014 [W] (FastAllocPool)
};

#endif // FASTALLOCPOOL_H
