#ifndef STACKELEM_H
#define STACKELEM_H

#include "types.h"

// StackElem - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 7 known fields (7 named), 26 methods

class StackElem {
public:
    // Methods
    /* ? */ GetParams(void);  // 0x803CDCEC (44B)
    /* ? */ GetLocals(void);  // 0x803CDD18 (64B)
    /* ? */ GetTreeID(void);  // 0x803CE420 (84B)
    /* ? */ GetTreeName(StringBuffer &);  // 0x803CAC08 (112B)
    void ReconStream(ReconBuffer *, int, BehaviorFinder *);  // 0x803CAC78 (372B)
    void SetTreeID(short);  // 0x803CE474 (100B)
    void SetBreak(bool);  // 0x803CE530 (108B)
    void NextFrame(void);  // 0x803CDDB8 (72B)
    /* ? */ GetSize(void);  // 0x803CDD58 (96B)
    void Setup(StackElem *, short *);  // 0x803CDE00 (272B)
    /* ? */ GetBreak(void);  // 0x803CE4D8 (88B)
    /* ? */ GetIgnoreDataBreakPoint(void);  // 0x803CE59C (44B)
    void SetIgnoreDataBreakPoint(bool);  // 0x803CE5C8 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_up;  // 0x000 [W] (Setup)
    u16 m_up_002;  // 0x002 [W] (Setup)
    u16 m_up_004;  // 0x004 [W] (Setup)
    u8 m_up_006;  // 0x006 [R/W] (ReconStream, Setup)
    u8 m_up_007;  // 0x007 [R/W] (ReconStream, Setup)
    u32 m_up_008;  // 0x008 [W] (Setup)
    u8 _pad_00C[4];  // 0x00C
    u32 m_treeName;  // 0x010 [R/W] (GetTreeName, Setup)
};

#endif // STACKELEM_H
