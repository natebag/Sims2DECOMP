#ifndef ERESOURCEMAP_H
#define ERESOURCEMAP_H

#include "types.h"

// EResourceMap - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 5 known fields (2 named), 42 methods

class EResourceMap {
public:
    // Constructors / Destructors
    EResourceMap(void)  // 0x808916A4
    ~EResourceMap(void);  // 0x808916F4

    // Methods
    /* ? */ GetNumEntries(void);  // 0x80892DBC (44B)
    void Find(unsigned int, EResource **);  // 0x80891830 (188B)
    bool IsEmpty(void);  // 0x80892148 (56B)
    void RemoveAll(void);  // 0x80892180 (120B)
    void SetCapacity(int, char *);  // 0x808918EC (192B)
    void PrintLoadedResources(char *);  // 0x808921F8 (804B)
    void PrintResourceSizes(char *);  // 0x8089251C (564B)
    void Insert(EResourceManager *, unsigned int, EResource *, char *);  // 0x808919AC (956B)
    void RefreshResources(void);  // 0x80892750 (380B)
    void Remove(unsigned int);  // 0x80891D68 (948B)
    void Search(unsigned int);  // 0x8089174C (228B)
    /* ? */ GetSize(void);  // 0x8089211C (44B)
    void BuildResourceList(vector<int, allocator<int> > &);  // 0x808928CC (468B)
    /* ? */ GetPrevResourceID(int);  // 0x80892AA0 (360B)
    /* ? */ GetNextResourceID(int);  // 0x80892C08 (368B)
    /* ? */ GetResourceID(int);  // 0x80892D78 (68B)
    /* ? */ GetMaxEntries(void);  // 0x80892DE8 (44B)
    /* ? */ GetMaxLoaded(void);  // 0x80892E14 (44B)
    /* ? */ GetMaxUsed(void);  // 0x80892E40 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Find, Insert, Remove, ...)
    u32 m_field_004;  // 0x004 [R/W] (Find, Insert, Remove, ...)
    u32 m_capacity_008;  // 0x008 [R/W] (Insert, RemoveAll, SetCapacity)
    u32 m_field_00C;  // 0x00C [R/W] (Insert, RemoveAll)
    u32 m_field_010;  // 0x010 [R/W] (Insert, RemoveAll)
};

#endif // ERESOURCEMAP_H
