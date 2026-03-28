#ifndef STRINGPOOL_H
#define STRINGPOOL_H

#include "types.h"

// StringPool - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 6 known fields (6 named), 17 methods

class StringPool {
public:
    // Methods
    void Initialize(int);  // 0x8071B460 (11008B)
    void Teardown(void);  // 0x8071DF60 (780B)
    void ClearTemporaryPool(void);  // 0x8071EA8C (212B)
    void RemoveFromPool(AptString *);  // 0x8071E6CC (960B)
    /* ? */ GetFromPool(char *);  // 0x8071E35C (880B)
    /* ? */ GetString(StringCode);  // 0x8071B3A8 (184B)
    void CheckContent(void);  // 0x8071EB60 (240B)
    /* ? */ GetDeltaDuplicated(AptString *);  // 0x8071ED10 (140B)
    /* ? */ GetDeltaCreated(AptString *);  // 0x8071EC50 (192B)
    /* ? */ GetString(char *);  // 0x8071E26C (240B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_fromPool;  // 0x000 [R/W] (GetFromPool, RemoveFromPool)
    u8 _pad_001[1];  // 0x001
    u16 m_string;  // 0x002 [R] (GetString)
    u8 _pad_004[2];  // 0x004
    u16 m_fromPool_006;  // 0x006 [R] (GetFromPool)
    u32 m_fromPool_008;  // 0x008 [R] (ClearTemporaryPool, GetFromPool, RemoveFromPool)
    u32 m_fromPool_00C;  // 0x00C [R/W] (GetFromPool, RemoveFromPool)
    u32 m_fromPool_010;  // 0x010 [R/W] (ClearTemporaryPool, GetFromPool, RemoveFromPool)
};

#endif // STRINGPOOL_H
