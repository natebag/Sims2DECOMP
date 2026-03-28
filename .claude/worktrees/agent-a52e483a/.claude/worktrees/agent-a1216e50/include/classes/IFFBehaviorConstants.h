#ifndef IFFBEHAVIORCONSTANTS_H
#define IFFBEHAVIORCONSTANTS_H

#include "types.h"

// IFFBehaviorConstants - struct layout extracted from assembly analysis
// Estimated minimum size: 0x64 (100 bytes)
// 6 known fields (1 named), 26 methods

class IFFBehaviorConstants {
public:
    // Constructors / Destructors
    IFFBehaviorConstants(void)  // 0x803F75C4
    ~IFFBehaviorConstants(void);  // 0x803F762C

    // Methods
    void LoadData(iResFile *, Memory::HandleNode *);  // 0x803F641C (392B)
    void LoadFromIndex(unsigned int, int);  // 0x803F65A4 (276B)
    void LoadOnlyNameAndIDFromIndex(unsigned int, int);  // 0x803F66B8 (128B)
    void LoadFromDataID(ObjectDataID &);  // 0x803F6738 (292B)
    void SaveDataByID(ObjectDataID &);  // 0x803F685C (648B)
    /* ? */ GetResourceName(StringBuffer &);  // 0x803F6AE4 (116B)
    void SetResourceName(StringBuffer &);  // 0x803F6B58 (84B)
    void QueryInterface(unsigned int, void **);  // 0x803F6BAC (248B)
    void AddRef(void);  // 0x803F6CA4 (64B)
    void Release(void);  // 0x803F6CE4 (160B)
    /* ? */ GetDataSourceType(void);  // 0x803F7678 (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (IFFBehaviorConstants, LoadData, QueryInterface, ...)
    u32 m_field_004;  // 0x004 [R/W] (SaveDataByID)
    u32 m_field_008;  // 0x008 [W] (SaveDataByID)
    u32 m_field_00C;  // 0x00C [R] (LoadFromDataID, LoadFromIndex, SaveDataByID)
    u8 _pad_010[4];  // 0x010
    u32 m_field_014;  // 0x014 [R] (LoadData, SaveDataByID)
    u8 _pad_018[0x48];  // 0x018
    u32 m_field_060;  // 0x060 [R/W] (IFFBehaviorConstants, Release)
};

#endif // IFFBEHAVIORCONSTANTS_H
