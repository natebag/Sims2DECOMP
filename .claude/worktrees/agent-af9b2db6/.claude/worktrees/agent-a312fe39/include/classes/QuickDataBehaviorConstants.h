#ifndef QUICKDATABEHAVIORCONSTANTS_H
#define QUICKDATABEHAVIORCONSTANTS_H

#include "types.h"

// QuickDataBehaviorConstants - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 5 known fields (1 named), 24 methods

class QuickDataBehaviorConstants {
public:
    // Constructors / Destructors
    QuickDataBehaviorConstants(void)  // 0x803F73BC
    ~QuickDataBehaviorConstants(void);  // 0x803F7410

    // Methods
    void LoadFromIndex(unsigned int, int);  // 0x803F5F38 (324B)
    void LoadFromDataID(ObjectDataID &);  // 0x803F607C (300B)
    void SetValueCount(int);  // 0x803F61A8 (156B)
    void QueryInterface(unsigned int, void **);  // 0x803F6244 (248B)
    void AddRef(void);  // 0x803F633C (64B)
    void Release(void);  // 0x803F637C (160B)
    void SaveDataByID(ObjectDataID &);  // 0x803F7540 (44B)
    /* ? */ GetDataSourceType(void);  // 0x803F756C (40B)
    void LoadOnlyNameAndIDFromIndex(unsigned int, int);  // 0x803F7594 (48B)
    /* ? */ GetValue(int);  // 0x803F7470 (208B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (QueryInterface, QuickDataBehaviorConstants, Release, ...)
    u16 m_field_004;  // 0x004 [R/W] (LoadFromDataID, LoadFromIndex, operator delete, ...)
    u8 _pad_006[2];  // 0x006
    u32 m_field_008;  // 0x008 [R] (LoadFromDataID, LoadFromIndex)
    u8 _pad_00C[0xC];  // 0x00C
    u32 m_field_018;  // 0x018 [R/W] (LoadFromDataID, LoadFromIndex)
    u32 m_field_01C;  // 0x01C [R/W] (QuickDataBehaviorConstants, Release)
};

#endif // QUICKDATABEHAVIORCONSTANTS_H
