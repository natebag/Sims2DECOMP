#ifndef APTVALUEGC_POOLMANAGER_H
#define APTVALUEGC_POOLMANAGER_H

#include "types.h"

// AptValueGC_PoolManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (2 named), 14 methods

class AptValueGC_PoolManager {
public:
    // Constructors / Destructors
    AptValueGC_PoolManager(unsigned int, unsigned int)  // 0x806A6724
    ~AptValueGC_PoolManager(void);  // 0x806A6674

    // Methods
    void StaticInitialize(void);  // 0x80709B48 (300B)
    /* ? */ GetFirstAptValue(void);  // 0x80709988 (244B)
    /* ? */ GetNextAptValue(AptValue *);  // 0x80709768 (544B)
    void AllocateAptValueGC(unsigned int);  // 0x807094B4 (296B)
    void DeallocateAptValueGC(AptValueGC *, unsigned int);  // 0x807095DC (396B)
    void VerifyList(void);  // 0x80709A7C (204B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AllocateAptValueGC, GetFirstAptValue, GetNextAptValue)
    u32 m_nextAptValue_004;  // 0x004 [R/W] (AllocateAptValueGC, GetFirstAptValue, GetNextAptValue)
};

#endif // APTVALUEGC_POOLMANAGER_H
