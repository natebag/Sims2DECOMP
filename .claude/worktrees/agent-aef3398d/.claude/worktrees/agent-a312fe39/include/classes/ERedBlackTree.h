#ifndef EREDBLACKTREE_H
#define EREDBLACKTREE_H

#include "types.h"

// ERedBlackTree - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 7 known fields (1 named), 57 methods

class ERedBlackTree {
public:
    // Constructors / Destructors
    ERedBlackTree(void)  // 0x8075E37C
    ERedBlackTree(ERedBlackTree &)  // 0x8075E3C4
    ~ERedBlackTree(void);  // 0x80080D24

    // Methods
    void Head(void);  // 0x8007D4F8 (68B)
    void Next(RBIteratorPtrType *);  // 0x8007D448 (176B)
    bool IsValid(RBIteratorPtrType *);  // 0x80080D78 (56B)
    /* ? */ GetValue(RBIteratorPtrType *);  // 0x80080E08 (164B)
    bool IsEmpty(void);  // 0x800D7194 (68B)
    /* ? */ GetKey(RBIteratorPtrType *);  // 0x80101368 (164B)
    void RemoveAll(void);  // 0x8075F898 (64B)
    void Find(unsigned int, unsigned int *);  // 0x8075F5F4 (192B)
    void Insert(unsigned int, unsigned int, bool);  // 0x8075EBC8 (224B)
    void Remove(unsigned int);  // 0x8075F234 (120B)
    void Remove(RBIteratorPtrType *);  // 0x8075F2AC (840B)
    /* ? */ GetSize(void);  // 0x8075F96C (68B)
    void operator[](unsigned int);  // 0x8075E938 (168B)
    void Init(void);  // 0x8075FF10 (44B)
    void SetValues(ERedBlackTree &, bool);  // 0x8075FA04 (200B)
    void RotateLeft(ERedBlackTreeNode *);  // 0x8075E420 (272B)
    void RotateRight(ERedBlackTreeNode *);  // 0x8075E530 (272B)
    void InsertFixup(ERedBlackTreeNode *);  // 0x8075E640 (564B)
    void FindKeyOrParent(unsigned int);  // 0x8075E9E0 (176B)
    void InsertAt(ERedBlackTreeNode *, unsigned int, unsigned int);  // 0x8075ECA8 (660B)
    void FindParent(unsigned int);  // 0x8075EA90 (144B)
    void SetValue(unsigned int, unsigned int);  // 0x8075EB20 (168B)
    void RemoveFixup(ERedBlackTreeNode *);  // 0x8075EF3C (760B)
    void FindFirst(unsigned int, unsigned int *);  // 0x8075F6B4 (216B)
    void Last(RBIteratorPtrType *);  // 0x8075FC24 (176B)
    void FindNext(RBIteratorPtrType *, unsigned int *);  // 0x8075F78C (268B)
    void FreeAll(void);  // 0x8075F8D8 (148B)
    void operator=(ERedBlackTree &);  // 0x8075F9B0 (84B)
    void operator==(ERedBlackTree &);  // 0x8075FACC (288B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ERedBlackTree, Find, FindKeyOrParent, ...)
    u32 m_field_004;  // 0x004 [R/W] (ERedBlackTree, Find, FindKeyOrParent, ...)
    u32 m_field_008;  // 0x008 [R/W] (ERedBlackTree, Find, FindKeyOrParent, ...)
    u32 m_field_00C;  // 0x00C [R] (FindFirst)
    u32 m_field_010;  // 0x010 [R] (operator==)
    u8 _pad_014[4];  // 0x014
    u32 m_field_018;  // 0x018 [R] (Find, FindKeyOrParent, Insert, ...)
    u32 m_field_01C;  // 0x01C [R] (Find, FindFirst, operator==)
};

#endif // EREDBLACKTREE_H
