#ifndef TREETABLEQUICKDATA_H
#define TREETABLEQUICKDATA_H

#include "types.h"

// TreeTableQuickData - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 6 known fields (4 named), 74 methods

class TreeTableQuickData {
public:
    // Constructors / Destructors
    TreeTableQuickData(void)  // 0x80401DF8
    ~TreeTableQuickData(void);  // 0x80401E90

    // Methods
    /* ? */ GetDataID(void);  // 0x80401F10 (80B)
    void LoadFromDataID(ObjectDataID &);  // 0x80401F60 (576B)
    void SaveDataByID(ObjectDataID &);  // 0x804021A0 (164B)
    /* ? */ GetDataSourceType(void);  // 0x80402244 (40B)
    void Load(unsigned int, short);  // 0x8040226C (176B)
    /* ? */ GetNthEntry(int);  // 0x8040231C (420B)
    /* ? */ GetImplementation(void);  // 0x804071FC (44B)
    /* ? */ GetEntryByIndex(int);  // 0x804024C0 (284B)
    /* ? */ GetEntryByTreeID(short, short);  // 0x804025DC (308B)
    /* ? */ GetNthOrderedEntry(int);  // 0x80402710 (276B)
    void CreateInstance(void);  // 0x80402824 (80B)
    void QueryInterface(unsigned int, void **);  // 0x80402C24 (248B)
    void AddRef(void);  // 0x80402D1C (64B)
    void Release(void);  // 0x80402D5C (160B)
    void LoadFromIndex(unsigned int, int);  // 0x80406730 (48B)
    /* ? */ GetResourceName(StringBuffer &);  // 0x80406760 (44B)
    void SetResourceName(StringBuffer &);  // 0x8040678C (164B)
    void LoadOnlyNameAndIDFromIndex(unsigned int, int);  // 0x80406830 (48B)
    /* ? */ GetID(void);  // 0x80406860 (92B)
    void CountMotiveAds(void);  // 0x804068BC (88B)
    void CountEntries(void);  // 0x80406914 (88B)
    void AddEntry(short, short);  // 0x80407014 (168B)
    void RemoveEntry(ITreeTableEntry *);  // 0x804070BC (164B)
    /* ? */ GetPrefixCheckTreeID(void);  // 0x8040696C (92B)
    void SetPrefixCheckTreeID(short);  // 0x80407160 (156B)
    void SwapEntries(int, int);  // 0x804069C8 (160B)
    void AreOrderIndicesValid(void);  // 0x80406CF0 (160B)
    void SetName(StringBuffer &);  // 0x80406C54 (156B)
    void Save(unsigned int, short);  // 0x80406D90 (168B)
    void Save(void);  // 0x80406E38 (160B)
    /* ? */ GetIsTuned(void);  // 0x80406ED8 (160B)
    void SetIsTuned(bool);  // 0x80406F78 (156B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetEntryByIndex, GetEntryByTreeID, GetNthEntry, ...)
    u32 m_entryByTreeID;  // 0x004 [R/W] (GetEntryByIndex, GetEntryByTreeID, GetNthEntry, ...)
    u32 m_nthEntry;  // 0x008 [R/W] (GetNthEntry, LoadFromDataID, TreeTableQuickData, ...)
    u32 m_nthEntry_00C;  // 0x00C [R] (GetNthEntry)
    u8 _pad_010[0x10];  // 0x010
    u32 m_field_020;  // 0x020 [R/W] (Release, TreeTableQuickData)
    u32 m_field_024;  // 0x024 [R] (LoadFromDataID)
};

#endif // TREETABLEQUICKDATA_H
