#ifndef EFLOATTREE_H
#define EFLOATTREE_H

#include "types.h"

// EFloatTree - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 6 known fields (1 named), 51 methods

class EFloatTree {
public:
    // Constructors / Destructors
    EFloatTree(void)  // 0x8074F1A4
    EFloatTree(EFloatTree &)  // 0x8074F1EC
    ~EFloatTree(void);  // 0x80864468

    // Methods
    void Init(void);  // 0x80750914 (44B)
    void SetValues(EFloatTree &, bool);  // 0x8075045C (200B)
    void RotateLeft(EFloatTreeNode *);  // 0x8074F248 (272B)
    void RotateRight(EFloatTreeNode *);  // 0x8074F358 (272B)
    void InsertFixup(EFloatTreeNode *);  // 0x8074F468 (564B)
    void operator[](float);  // 0x8074F69C (196B)
    void Find(float, unsigned int *);  // 0x80750318 (192B)
    bool IsValid(FTIteratorPtrType *);  // 0x807506A0 (56B)
    void FindKeyOrParent(float);  // 0x8074F808 (176B)
    void InsertAt(EFloatTreeNode *, float, unsigned int);  // 0x8074FAD0 (400B)
    void FindParent(float);  // 0x8074F8B8 (144B)
    void SetValue(float, unsigned int);  // 0x8074F948 (168B)
    void Insert(float, unsigned int, bool);  // 0x8074F9F0 (224B)
    void RemoveFixup(EFloatTreeNode *);  // 0x8074FC60 (760B)
    void Remove(float);  // 0x8074FF58 (120B)
    void Remove(FTIteratorPtrType *);  // 0x8074FFD0 (840B)
    void RemoveAll(void);  // 0x807503D8 (64B)
    /* ? */ GetSize(void);  // 0x80750418 (68B)
    void Head(void);  // 0x80750788 (68B)
    /* ? */ GetKey(FTIteratorPtrType *);  // 0x807507CC (164B)
    /* ? */ GetValue(FTIteratorPtrType *);  // 0x80750870 (164B)
    void Next(FTIteratorPtrType *);  // 0x807506D8 (176B)
    void operator=(EFloatTree &);  // 0x80750524 (84B)
    void operator==(EFloatTree &);  // 0x80750578 (296B)
    void Tail(void);  // 0x80861BCC (68B)
    void Last(FTIteratorPtrType *);  // 0x80861A6C (176B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (EFloatTree, Find, FindKeyOrParent, ...)
    u32 m_field_004;  // 0x004 [R/W] (EFloatTree, Find, FindKeyOrParent, ...)
    u32 m_field_008;  // 0x008 [R/W] (EFloatTree, Find, FindKeyOrParent, ...)
    u8 _pad_00C[4];  // 0x00C
    u32 m_field_010;  // 0x010 [R] (operator==)
    u8 _pad_014[4];  // 0x014
    u32 m_field_018;  // 0x018 [R] (Find, operator==)
    f32 m_field_01C;  // 0x01C [R] (Find, FindKeyOrParent, Insert, ...)
};

#endif // EFLOATTREE_H
