#ifndef RESOURCEBEHAVIOR_H
#define RESOURCEBEHAVIOR_H

#include "types.h"

// ResourceBehavior - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 6 known fields (4 named), 18 methods

class ResourceBehavior {
public:
    // Constructors / Destructors
    ResourceBehavior(void)  // 0x802146C0
    ~ResourceBehavior(void);  // 0x8021472C

    // Methods
    void Init(Language *, ObjSelector *);  // 0x802147EC (356B)
    void CountTrees(short);  // 0x80214950 (308B)
    /* ? */ GetTreeIDByName(char *);  // 0x80214A84 (172B)
    /* ? */ GetTreeByIndex(int, short, ObjectDataBehaviorTree **);  // 0x80214B30 (376B)
    void QueryInterface(unsigned int, void **);  // 0x80214CA8 (248B)
    void AddRef(void);  // 0x80214DA0 (64B)
    void Release(void);  // 0x80214DE0 (160B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (QueryInterface, Release, ResourceBehavior, ...)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [R] (Init)
    u8 _pad_00C[4];  // 0x00C
    u32 m_treeIDByName;  // 0x010 [R/W] (CountTrees, GetTreeByIndex, GetTreeIDByName, ...)
    u32 m_treeIDByName_014;  // 0x014 [R/W] (CountTrees, GetTreeByIndex, GetTreeIDByName, ...)
    u32 m_treeIDByName_018;  // 0x018 [R/W] (CountTrees, GetTreeByIndex, GetTreeIDByName, ...)
    u32 m_field_01C;  // 0x01C [R/W] (Release, ResourceBehavior)
};

#endif // RESOURCEBEHAVIOR_H
