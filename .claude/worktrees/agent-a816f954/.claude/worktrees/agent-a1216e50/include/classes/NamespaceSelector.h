#ifndef NAMESPACESELECTOR_H
#define NAMESPACESELECTOR_H

#include "types.h"

// NamespaceSelector - struct layout extracted from assembly analysis
// Estimated minimum size: 0x34 (52 bytes)
// 8 known fields (5 named), 29 methods

class NamespaceSelector {
public:
    // Constructors / Destructors
    NamespaceSelector(unsigned int)  // 0x802D04C8
    NamespaceSelector(NamespaceSelector &)  // 0x802D013C
    NamespaceSelector(void)  // 0x802D3C78
    ~NamespaceSelector(void);  // 0x80269B0C

    // Methods
    /* ? */ GetBehaviorConstants(short);  // 0x80269BA4 (112B)
    void FlushAllCaches(void);  // 0x80269EFC (148B)
    /* ? */ GetCacheItem(short, list<NamespaceSelector::DataCache, allocator<NamespaceSelector::DataCache> > &, unsigned int, unsigned int);  // 0x8026A094 (1844B)
    /* ? */ GetSoundInfo(short);  // 0x80269C14 (112B)
    /* ? */ GetStringSet(short);  // 0x80269C84 (112B)
    void FlushBehaviorConstant(short);  // 0x80269CF4 (88B)
    void FlushCacheItem(short, list<NamespaceSelector::DataCache, allocator<NamespaceSelector::DataCache> > &);  // 0x80269DA4 (256B)
    void FlushSoundInfo(short);  // 0x80269D4C (88B)
    void FlushStringSet(short);  // 0x80269EA4 (88B)
    /* ? */ GetTreeSetResource(void);  // 0x8026A7C8 (44B)
    void SetTreeSetResource(EREdithTreeSet *);  // 0x8026A7F4 (116B)
    void operator=(NamespaceSelector &);  // 0x802D01E0 (180B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (FlushAllCaches, GetCacheItem, NamespaceSelector)
    u32 m_cacheItem_004;  // 0x004 [R/W] (FlushAllCaches, GetCacheItem, NamespaceSelector)
    u16 m_cacheItem_008;  // 0x008 [W] (FlushAllCaches, GetCacheItem, NamespaceSelector)
    u8 _pad_00A[2];  // 0x00A
    u32 m_cacheItem_00C;  // 0x00C [W] (FlushAllCaches, GetCacheItem, NamespaceSelector)
    u8 _pad_010[0x10];  // 0x010
    u32 m_field_020;  // 0x020 [R/W] (FlushAllCaches)
    u8 _pad_024[4];  // 0x024
    u32 m_field_028;  // 0x028 [R/W] (FlushAllCaches)
    u8 m_field_02C;  // 0x02C [R/W] (FlushAllCaches)
    u8 _pad_02D[3];  // 0x02D
    u32 m_treeSetResource;  // 0x030 [R/W] (FlushAllCaches, NamespaceSelector, SetTreeSetResource)
};

#endif // NAMESPACESELECTOR_H
