#ifndef IFFBEHAVIOR_H
#define IFFBEHAVIOR_H

#include "types.h"

// IFFBehavior - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 3 known fields (1 named), 16 methods

class IFFBehavior {
public:
    // Constructors / Destructors
    IFFBehavior(void)  // 0x80214E80
    ~IFFBehavior(void);  // 0x80214ED4

    // Methods
    void CountTrees(short);  // 0x80214F20 (460B)
    /* ? */ GetTreeByIndex(int, short, ObjectDataBehaviorTree **);  // 0x802150EC (632B)
    /* ? */ GetTreeIDByName(char *);  // 0x80215364 (540B)
    void QueryInterface(unsigned int, void **);  // 0x80215580 (248B)
    void AddRef(void);  // 0x80215678 (64B)
    void Release(void);  // 0x802156B8 (160B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetTreeByIndex, GetTreeIDByName, IFFBehavior, ...)
    u8 _pad_004[8];  // 0x004
    u32 m_field_00C;  // 0x00C [R] (CountTrees)
    u32 m_field_010;  // 0x010 [R/W] (IFFBehavior, Release)
};

#endif // IFFBEHAVIOR_H
