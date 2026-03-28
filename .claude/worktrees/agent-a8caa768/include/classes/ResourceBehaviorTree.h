#ifndef RESOURCEBEHAVIORTREE_H
#define RESOURCEBEHAVIORTREE_H

#include "types.h"

// ResourceBehaviorTree - struct layout extracted from assembly analysis
// Estimated minimum size: 0x68 (104 bytes)
// 7 known fields (4 named), 22 methods

class ResourceBehaviorTree {
public:
    // Constructors / Destructors
    ResourceBehaviorTree(void)  // 0x803F803C
    ~ResourceBehaviorTree(void);  // 0x803F86E8

    // Methods
    void LoadFromIndex(unsigned int, int);  // 0x803F8098 (488B)
    void LoadOnlyNameAndIDFromIndex(unsigned int, int);  // 0x803F8280 (120B)
    void LoadFromDataID(ObjectDataID &);  // 0x803F82F8 (484B)
    /* ? */ GetFromDataID(ObjectDataID &);  // 0x803F84DC (480B)
    void SaveDataByID(ObjectDataID &);  // 0x803F86BC (44B)
    void QueryInterface(unsigned int, void **);  // 0x803F888C (248B)
    void AddRef(void);  // 0x803F8984 (64B)
    void Release(void);  // 0x803F89C4 (160B)
    /* ? */ GetDataSourceType(void);  // 0x803FA10C (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (QueryInterface, Release, ResourceBehaviorTree, ...)
    u32 m_field_004;  // 0x004 [R/W] (operator delete, operator new)
    u32 m_fromDataID;  // 0x008 [R/W] (GetFromDataID, LoadFromDataID, LoadFromIndex, ...)
    u8 _pad_00C[0x48];  // 0x00C
    u32 m_fromDataID_054;  // 0x054 [R/W] (GetFromDataID, LoadFromDataID, LoadFromIndex)
    u32 m_field_058;  // 0x058 [R] (LoadFromDataID, LoadFromIndex)
    u8 _pad_05C[4];  // 0x05C
    u32 m_fromDataID_060;  // 0x060 [R/W] (GetFromDataID, LoadFromDataID, LoadFromIndex, ...)
    u32 m_field_064;  // 0x064 [R/W] (Release, ResourceBehaviorTree)
};

#endif // RESOURCEBEHAVIORTREE_H
