#ifndef ENODELIST_H
#define ENODELIST_H

#include "types.h"

// ENodeList - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (2 named), 38 methods

class ENodeList {
public:
    // Constructors / Destructors
    ENodeList(void)  // 0x80080A98
    ~ENodeList(void);  // 0x80080AD8

    // Methods
    void Head(void);  // 0x8007D3C0 (68B)
    void Next(NLIteratorPtrType *);  // 0x8007D378 (72B)
    bool IsEmpty(void);  // 0x8007D404 (68B)
    /* ? */ GetData(NLIteratorPtrType *);  // 0x80080BD8 (164B)
    void Tail(void);  // 0x80080CA8 (68B)
    bool IsValid(NLIteratorPtrType *);  // 0x80080BA0 (56B)
    void Last(NLIteratorPtrType *);  // 0x80080B2C (72B)
    /* ? */ GetCount(void);  // 0x805D5F7C (68B)
    void RemoveAll(void);  // 0x8075B408 (132B)
    void AddTail(unsigned int);  // 0x8075AF94 (212B)
    void Remove(NLIteratorPtrType *);  // 0x8075AE10 (176B)
    void AddHead(unsigned int);  // 0x8075AEC0 (212B)
    /* ? */ GetSize(void);  // 0x8075B520 (140B)
    void Search(unsigned int);  // 0x8075B9D0 (156B)
    void AddHead(ENodeList &);  // 0x8075B068 (244B)
    void AddTail(ENodeList &);  // 0x8075B15C (244B)
    void InsertBefore(NLIteratorPtrType *, unsigned int);  // 0x8075B250 (220B)
    void InsertAfter(NLIteratorPtrType *, unsigned int);  // 0x8075B32C (220B)
    void FreeAll(void);  // 0x8075B48C (148B)
    /* ? */ GetSizeRev(void);  // 0x8075B5AC (140B)
    bool IsValidList(void);  // 0x8075B638 (920B)
    void MoveContents(ENodeList &);  // 0x8075BA6C (116B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddHead, AddTail, InsertAfter, ...)
    u32 m_bIsValidList_004;  // 0x004 [R/W] (AddHead, AddTail, FreeAll, ...)
    u32 m_field_008;  // 0x008 [R/W] (AddHead, AddTail, InsertAfter, ...)
};

#endif // ENODELIST_H
