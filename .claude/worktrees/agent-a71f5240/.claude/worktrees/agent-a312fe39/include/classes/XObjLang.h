#ifndef XOBJLANG_H
#define XOBJLANG_H

#include "types.h"

// XObjLang - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 3 known fields (3 named), 28 methods

class XObjLang {
public:
    // Constructors / Destructors
    XObjLang(ObjSelector *)  // 0x803E7784
    ~XObjLang(void);  // 0x803E85D8

    // Methods
    /* ? */ GetSelector(void);  // 0x803E8624 (44B)
    /* ? */ GetConstantsID(short, short *, int *);  // 0x803E7800 (248B)
    /* ? */ GetTreeTypeName(int, StringBuffer &);  // 0x803E748C (140B)
    /* ? */ GetNodeText(Behavior *, short, BehaviorNode *, StringBuffer &);  // 0x803E7518 (152B)
    /* ? */ GetPrimName(short, StringBuffer &);  // 0x803E75B0 (144B)
    bool IsSingleExit(BehaviorNode *);  // 0x803E7640 (144B)
    void CountPrimitives(void);  // 0x803E76D0 (140B)
    /* ? */ GetSwizzler(void);  // 0x803E775C (40B)
    /* ? */ GetMaxConstants(void);  // 0x803E77DC (36B)
    /* ? */ GetConstantsDataField(short, int, short *);  // 0x803E78F8 (360B)
    void StripPathInformation(char *, StringBuffer &);  // 0x803E7A60 (232B)
    /* ? */ GetGlobalIconName(vector<StackString<64>, allocator<StackString<64> > > &);  // 0x803E7B48 (244B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetGlobalIconName)
    u32 m_globalIconName_004;  // 0x004 [R/W] (GetGlobalIconName)
    u8 _pad_008[4];  // 0x008
    u32 m_globalIconName_00C;  // 0x00C [R/W] (GetGlobalIconName)
};

#endif // XOBJLANG_H
