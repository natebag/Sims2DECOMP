#ifndef IFFBEHAVIORTREE_H
#define IFFBEHAVIORTREE_H

#include "types.h"

// IFFBehaviorTree - struct layout extracted from assembly analysis
// Estimated minimum size: 0x64 (100 bytes)
// 6 known fields (1 named), 24 methods

class IFFBehaviorTree {
public:
    // Constructors / Destructors
    IFFBehaviorTree(void)  // 0x803F8A64
    IFFBehaviorTree(int)  // 0x803F8AB8
    ~IFFBehaviorTree(void);  // 0x803F8B3C

    // Methods
    void LoadFromIndex(unsigned int, int);  // 0x803F8BB4 (588B)
    void LoadOnlyNameAndIDFromIndex(unsigned int, int);  // 0x803F8E00 (120B)
    void LoadFromDataID(ObjectDataID &);  // 0x803F8E78 (580B)
    /* ? */ GetFromDataID(ObjectDataID &);  // 0x803F90BC (112B)
    void SaveDataByID(ObjectDataID &);  // 0x803F912C (744B)
    void QueryInterface(unsigned int, void **);  // 0x803F9414 (248B)
    void AddRef(void);  // 0x803F950C (64B)
    void Release(void);  // 0x803F954C (160B)
    /* ? */ GetDataSourceType(void);  // 0x803FA134 (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (IFFBehaviorTree, LoadFromDataID, QueryInterface, ...)
    u32 m_field_004;  // 0x004 [R/W] (SaveDataByID)
    u32 m_field_008;  // 0x008 [R/W] (IFFBehaviorTree, LoadFromDataID, LoadFromIndex, ...)
    u32 m_field_00C;  // 0x00C [R] (SaveDataByID)
    u8 _pad_010[0x44];  // 0x010
    u32 m_field_054;  // 0x054 [R/W] (IFFBehaviorTree, LoadFromDataID, LoadFromIndex, ...)
    u8 _pad_058[8];  // 0x058
    u32 m_field_060;  // 0x060 [R/W] (IFFBehaviorTree, Release)
};

#endif // IFFBEHAVIORTREE_H
