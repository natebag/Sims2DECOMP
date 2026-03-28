#ifndef OBJECTDATAOBJDEFINITION_H
#define OBJECTDATAOBJDEFINITION_H

#include "types.h"

// ObjectDataObjDefinition - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 10 known fields (5 named), 52 methods

class ObjectDataObjDefinition {
public:
    // Constructors / Destructors
    ObjectDataObjDefinition(void)  // 0x803FADFC
    ObjectDataObjDefinition(ObjectDataObjDefinition &)  // 0x803FAFA4
    ~ObjectDataObjDefinition(void);  // 0x803FAE90

    // Methods
    /* ? */ GetData(void);  // 0x803FC6E4 (44B)
    void Reset(void);  // 0x803FAF2C (88B)
    void SetOwnDefinition(ObjDefinition *);  // 0x803FB25C (152B)
    void operator=(ObjDefinition &);  // 0x803FB14C (136B)
    void Detach(void);  // 0x803FAF04 (40B)
    void ResetResData(void);  // 0x803FAF84 (32B)
    void SetResourceName(StringBuffer *);  // 0x803FBAD4 (184B)
    /* ? */ GetResID(void);  // 0x803FBB8C (56B)
    void SetResID(short);  // 0x803FBBC4 (60B)
    void operator=(ObjectDataObjDefinition &);  // 0x803FB08C (192B)
    /* ? */ GetResDataName(unsigned int, short, StringBuffer &);  // 0x803FB1D4 (80B)
    void SetResDataName(unsigned int, short, char *);  // 0x803FB224 (56B)
    /* ? */ GetResourceName(StringBuffer *);  // 0x803FB2F4 (120B)
    /* ? */ GetResourceType(void);  // 0x803FB36C (44B)
    void LoadFromQDataByID(unsigned int, short);  // 0x803FB398 (236B)
    void LoadFromIFFByID(unsigned int, short);  // 0x803FB484 (484B)
    void SaveToIFFFile(unsigned int, short, StringBuffer &);  // 0x803FB668 (548B)
    void LoadFromDBByID(unsigned int, short);  // 0x803FB88C (56B)
    void SaveToDB(unsigned int, short, StringBuffer &);  // 0x803FB8C4 (56B)
    void QueryInterface(unsigned int, void **);  // 0x803FB8FC (248B)
    void AddRef(void);  // 0x803FB9F4 (64B)
    void Release(void);  // 0x803FBA34 (160B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_resourceName;  // 0x000 [R/W] (LoadFromIFFByID, LoadFromQDataByID, ObjectDataObjDefinition, ...)
    u8 _pad_001[3];  // 0x001
    u32 m_resourceName_004;  // 0x004 [R/W] (GetResourceName, LoadFromIFFByID, ObjectDataObjDefinition, ...)
    u32 m_resourceName_008;  // 0x008 [R/W] (GetResourceName, LoadFromQDataByID, SaveToIFFFile)
    u32 m_field_00C;  // 0x00C [R/W] (LoadFromIFFByID, SaveToIFFFile)
    u32 m_field_010;  // 0x010 [R/W] (SaveToIFFFile, ~ObjectDataObjDefinition)
    u32 m_field_014;  // 0x014 [R/W] (ObjectDataObjDefinition, Release, SaveToIFFFile)
    u16 m_field_018;  // 0x018 [W] (ObjectDataObjDefinition)
    u8 m_ownDefinition;  // 0x01A [R/W] (ObjectDataObjDefinition, Reset, SetOwnDefinition)
    u8 m_field_01B;  // 0x01B [W] (ObjectDataObjDefinition)
    u32 m_ownDefinition_01C;  // 0x01C [R/W] (ObjectDataObjDefinition, Reset, SaveToIFFFile, ...)
};

#endif // OBJECTDATAOBJDEFINITION_H
