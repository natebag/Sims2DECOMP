#ifndef APTFRAMESTACK_H
#define APTFRAMESTACK_H

#include "types.h"

// AptFrameStack - struct layout extracted from assembly analysis
// Estimated minimum size: 0x24 (36 bytes)
// 2 known fields (0 named), 12 methods

class AptFrameStack {
public:
    // Constructors / Destructors
    AptFrameStack(AptFrameStack *, int)  // 0x80710044
    AptFrameStack(AptFrameStack *)  // 0x8070FF94
    ~AptFrameStack(void);  // 0x807103D8

    // Methods
    void ExistsInLocalScope(EAStringC *);  // 0x807100F8 (96B)
    void SetInLocalScope(EAStringC *, AptValue *);  // 0x80710158 (76B)
    void SetWhereExistsInScopeChain(EAStringC *, AptValue *);  // 0x807101A4 (164B)
    /* ? */ GetInScopeChain(EAStringC *);  // 0x80710248 (148B)
    void DestroyGCPointers(void);  // 0x807102DC (140B)
    void RegisterReferences(void);  // 0x80710368 (112B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [W] (~AptFrameStack)
    u8 _pad_00C[0x14];  // 0x00C
    u32 m_field_020;  // 0x020 [R] (DestroyGCPointers, RegisterReferences)
};

#endif // APTFRAMESTACK_H
