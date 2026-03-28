#ifndef OBJECTDATABEHAVIORTREE_H
#define OBJECTDATABEHAVIORTREE_H

#include "types.h"

// ObjectDataBehaviorTree - struct layout extracted from assembly analysis
// Estimated minimum size: 0x58 (88 bytes)
// 4 known fields (2 named), 38 methods

class ObjectDataBehaviorTree {
public:
    // Constructors / Destructors
    ObjectDataBehaviorTree(void)  // 0x803F79F0
    ObjectDataBehaviorTree(ObjectDataBehaviorTree &)  // 0x803F7AD8
    ~ObjectDataBehaviorTree(void);  // 0x803F7A7C

    // Methods
    /* ? */ GetNumNodes(void);  // 0x803F7CB8 (52B)
    /* ? */ GetNode(unsigned int);  // 0x803F7F98 (64B)
    /* ? */ GetTreeVersion(void);  // 0x803F7F28 (52B)
    /* ? */ GetNumLocals(void);  // 0x803F7E40 (176B)
    /* ? */ GetNumParams(void);  // 0x803F7D58 (176B)
    /* ? */ GetType(void);  // 0x803F7CEC (52B)
    void SetResourceName(StringBuffer &);  // 0x803F7C38 (76B)
    /* ? */ GetResID(void);  // 0x803F7FD8 (48B)
    void SetResID(short);  // 0x803F8008 (52B)
    /* ? */ GetResourceName(StringBuffer &);  // 0x803F7BCC (108B)
    /* ? */ GetStructVersion(void);  // 0x803F7C84 (52B)
    void SetType(unsigned char);  // 0x803F7D20 (56B)
    void SetNumParams(unsigned char);  // 0x803F7E08 (56B)
    void SetNumLocals(unsigned char);  // 0x803F7EF0 (56B)
    void SetTreeVersion(unsigned char);  // 0x803F7F5C (60B)
    /* ? */ GetDataID(void);  // 0x803FA0BC (80B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ObjectDataBehaviorTree)
    u16 m_field_004;  // 0x004 [W] (ObjectDataBehaviorTree)
    u8 _pad_006[2];  // 0x006
    u32 m_field_008;  // 0x008 [W] (ObjectDataBehaviorTree)
    u8 _pad_00C[0x48];  // 0x00C
    u32 m_numLocals;  // 0x054 [R/W] (GetNumLocals, GetNumParams, ObjectDataBehaviorTree)
};

#endif // OBJECTDATABEHAVIORTREE_H
