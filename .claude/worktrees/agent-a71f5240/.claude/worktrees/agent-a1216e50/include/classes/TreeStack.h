#ifndef TREESTACK_H
#define TREESTACK_H

#include "types.h"

// TreeStack - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 5 known fields (3 named), 28 methods

class TreeStack {
public:
    // Constructors / Destructors
    TreeStack(TreeSimImpl &)  // 0x803CA4A4
    ~TreeStack(void);  // 0x803CA52C

    // Methods
    void ReconStream(ReconBuffer *, int, BehaviorFinder *);  // 0x803CD7BC (1328B)
    /* ? */ GetStackSize(void);  // 0x803CE3D8 (72B)
    /* ? */ GetNthFrame(int);  // 0x803CE34C (140B)
    void Pop(void);  // 0x803CE224 (196B)
    void Initialize(int);  // 0x803CA9CC (68B)
    void MakeNewFrame(unsigned int);  // 0x803CAA10 (504B)
    /* ? */ GetMemReserved(void);  // 0x803CE03C (52B)
    /* ? */ GetMemUsed(void);  // 0x803CDFA4 (152B)
    /* ? */ GetNewFrame(void);  // 0x803CDF10 (148B)
    void AssignFrames(int);  // 0x803CE070 (312B)
    void Reset(void);  // 0x803CE2E8 (100B)
    void Push(StackElem *, short *);  // 0x803CE1A8 (124B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AssignFrames, GetMemUsed, GetNewFrame, ...)
    u32 m_field_004;  // 0x004 [W] (MakeNewFrame, ReconStream)
    u32 m_newFrame_008;  // 0x008 [R] (AssignFrames, GetMemUsed, GetNewFrame, ...)
    u32 m_newFrame_00C;  // 0x00C [R/W] (AssignFrames, GetMemUsed, GetNewFrame, ...)
    u8 _pad_010[8];  // 0x010
    u32 m_field_018;  // 0x018 [R] (Pop)
};

#endif // TREESTACK_H
