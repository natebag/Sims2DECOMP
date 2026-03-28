#ifndef APTNATIVEHASH_H
#define APTNATIVEHASH_H

#include "types.h"

// AptNativeHash - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 7 known fields (3 named), 46 methods

class AptNativeHash {
public:
    // Static members (from map file)
    // static ??? NUM_PROBES;

    // Constructors / Destructors
    AptNativeHash(int)  // 0x806F8714
    ~AptNativeHash(void);  // 0x806F89C8

    // Methods
    /* ? */ GetPrototype(void);  // 0x806BC1EC (44B)
    void SetPrototype(AptValue *);  // 0x806BC218 (212B)
    bool HasEventHandler(int);  // 0x806D7DB8 (52B)
    void SetEventHandler(int);  // 0x806D7D54 (48B)
    void RemoveEventHandler(int);  // 0x806D7D84 (52B)
    void RegisterReferences(AptValue *, char *);  // 0x806FA44C (452B)
    void Set(EAStringC *, AptValue *);  // 0x806F8CA0 (300B)
    void UpdateObjectMethods(AptValue *, EAStringC *, int);  // 0x806FA2E8 (356B)
    void Lookup(EAStringC *);  // 0x806F8EE4 (268B)
    /* ? */ GetFirstItem(void);  // 0x806F9458 (236B)
    /* ? */ GetNextItem(AptHashItem *);  // 0x806F9544 (308B)
    void DestroyGCPointers(void);  // 0x806F8B08 (312B)
    void Unset(EAStringC *);  // 0x806F8DCC (280B)
    void RegisterReferences(AptValue *);  // 0x806FA610 (376B)
    void UnsetPrototype(void);  // 0x806FA9BC (140B)
    bool IsEmpty(void);  // 0x806FAA48 (56B)
    void SetIfNotExists(EAStringC *, AptValue *);  // 0x806F8C40 (96B)
    void FirstAllocation(void);  // 0x806F9678 (280B)
    bool HashSet(EAStringC *, AptValue *);  // 0x806F98C4 (1428B)
    bool HashFindKey(EAStringC *);  // 0x806F9E58 (1168B)
    void UnsetAt(AptHashItem *);  // 0x806FACF0 (268B)
    void ClearData(void);  // 0x806F8FF0 (592B)
    void ClearDataNoDelete(void);  // 0x806F9240 (536B)
    void Expand(void);  // 0x806F9790 (308B)
    void OverwriteAt(int, AptValue *);  // 0x806FAC20 (208B)
    void SetAt(int, AptValue *);  // 0x806FAAE4 (316B)
    /* ? */ GetHashSize(void);  // 0x8070F3D0 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ClearData, ClearDataNoDelete, DestroyGCPointers, ...)
    u16 m_field_002;  // 0x002 [R] (Lookup, Set, Unset, ...)
    u32 m_nextItem_004;  // 0x004 [R/W] (ClearData, ClearDataNoDelete, DestroyGCPointers, ...)
    u16 m_bHashSet;  // 0x006 [R] (HashFindKey, HashSet, Set)
    u32 m_field_008;  // 0x008 [R/W] (ClearData, ClearDataNoDelete, DestroyGCPointers, ...)
    u32 m_field_00C;  // 0x00C [R/W] (ClearData, ClearDataNoDelete, DestroyGCPointers, ...)
    u32 m_field_010;  // 0x010 [R/W] (ClearData, ClearDataNoDelete, DestroyGCPointers, ...)
};

#endif // APTNATIVEHASH_H
