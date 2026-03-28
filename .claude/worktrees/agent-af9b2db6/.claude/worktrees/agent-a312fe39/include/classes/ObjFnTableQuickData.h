#ifndef OBJFNTABLEQUICKDATA_H
#define OBJFNTABLEQUICKDATA_H

#include "types.h"

// ObjFnTableQuickData - struct layout extracted from assembly analysis
// Estimated minimum size: 0x30 (48 bytes)
// 5 known fields (3 named), 42 methods

class ObjFnTableQuickData {
public:
    // Constructors / Destructors
    ObjFnTableQuickData(void)  // 0x8032D508
    ~ObjFnTableQuickData(void);  // 0x8032D580

    // Methods
    void CreateInstance(void);  // 0x8032D398 (80B)
    /* ? */ GetDataSourceType(void);  // 0x8032D5D4 (40B)
    /* ? */ GetTreeID(ObjEntryPoint);  // 0x8032D5FC (176B)
    /* ? */ GetCheckTreeID(ObjEntryPoint);  // 0x8032D6AC (176B)
    void SetTreeID(ObjEntryPoint, short);  // 0x8032D75C (168B)
    void SetCheckTreeID(ObjEntryPoint, short);  // 0x8032D804 (168B)
    void Load(unsigned int, short);  // 0x8032D8AC (228B)
    void Load(iResFile *, short);  // 0x8032D990 (204B)
    void BuildFromOldEntries(ObjDefinition *);  // 0x8032DA5C (128B)
    /* ? */ GetDataID(void);  // 0x8032DADC (80B)
    void LoadFromDataID(ObjectDataID &);  // 0x8032DB2C (156B)
    void SaveDataByID(ObjectDataID &);  // 0x8032DBC8 (164B)
    /* ? */ GetResourceName(StringBuffer &);  // 0x8032DC6C (164B)
    void SetResourceName(StringBuffer &);  // 0x8032DD10 (164B)
    void QueryInterface(unsigned int, void **);  // 0x8032DDB4 (248B)
    void AddRef(void);  // 0x8032DEAC (64B)
    void Release(void);  // 0x8032DEEC (160B)
    void LoadFromIndex(unsigned int, int);  // 0x8032E20C (48B)
    void LoadOnlyNameAndIDFromIndex(unsigned int, int);  // 0x8032E23C (48B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (LoadFromDataID, ObjFnTableQuickData, QueryInterface, ...)
    u8 _pad_004[8];  // 0x004
    u32 m_checkTreeID;  // 0x00C [R/W] (GetCheckTreeID, GetTreeID, Load, ...)
    u32 m_treeID;  // 0x010 [R/W] (BuildFromOldEntries, GetCheckTreeID, GetTreeID, ...)
    u32 m_field_014;  // 0x014 [R/W] (ObjFnTableQuickData, Release)
    u8 _pad_018[0x14];  // 0x018
    u32 m_field_02C;  // 0x02C [R] (Load)
};

#endif // OBJFNTABLEQUICKDATA_H
