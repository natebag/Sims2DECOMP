#ifndef FLOATCONSTANTSQUICKDATA_H
#define FLOATCONSTANTSQUICKDATA_H

#include "types.h"

// FloatConstantsQuickData - struct layout extracted from assembly analysis
// Estimated minimum size: 0x34 (52 bytes)
// 5 known fields (1 named), 38 methods

class FloatConstantsQuickData {
public:
    // Constructors / Destructors
    FloatConstantsQuickData(void)  // 0x80236D70
    ~FloatConstantsQuickData(void);  // 0x80236DE0

    // Methods
    void CreateInstance(void);  // 0x80236C00 (80B)
    /* ? */ Get(char *, float, bool);  // 0x80236E34 (188B)
    bool Has(char *);  // 0x80236EF0 (152B)
    void findItem(FloatConstantItem *, FloatConstantItem *, char *);  // 0x8023712C (340B)
    void Load(unsigned int, short);  // 0x80236F88 (228B)
    void Load(iResFile *, short);  // 0x8023706C (192B)
    /* ? */ GetDataID(void);  // 0x80237280 (80B)
    void LoadFromDataID(ObjectDataID &);  // 0x802372D0 (156B)
    void SaveDataByID(ObjectDataID &);  // 0x8023736C (164B)
    void QueryInterface(unsigned int, void **);  // 0x80237410 (248B)
    /* ? */ GetDataSourceType(void);  // 0x80237508 (48B)
    void AddRef(void);  // 0x80237538 (64B)
    void Release(void);  // 0x80237578 (160B)
    void LoadFromIndex(unsigned int, int);  // 0x80237894 (48B)
    /* ? */ GetResourceName(StringBuffer &);  // 0x802378C4 (44B)
    void SetResourceName(StringBuffer &);  // 0x802378F0 (44B)
    void LoadOnlyNameAndIDFromIndex(unsigned int, int);  // 0x8023791C (48B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (FloatConstantsQuickData, Has, LoadFromDataID, ...)
    u32 m_field_004;  // 0x004 [R] (findItem)
    u8 _pad_008[4];  // 0x008
    u32 m_field_00C;  // 0x00C [R/W] (FloatConstantsQuickData, Get, Has, ...)
    u32 m_field_010;  // 0x010 [R/W] (FloatConstantsQuickData, Release)
    u8 _pad_014[0x1C];  // 0x014
    u32 m_field_030;  // 0x030 [R] (Load)
};

#endif // FLOATCONSTANTSQUICKDATA_H
