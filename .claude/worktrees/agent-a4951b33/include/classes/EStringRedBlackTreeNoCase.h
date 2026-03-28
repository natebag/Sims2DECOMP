#ifndef ESTRINGREDBLACKTREENOCASE_H
#define ESTRINGREDBLACKTREENOCASE_H

#include "types.h"

// EStringRedBlackTreeNoCase - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 8 known fields (1 named), 58 methods

class EStringRedBlackTreeNoCase {
public:
    // Constructors / Destructors
    EStringRedBlackTreeNoCase(void)  // 0x80905788
    EStringRedBlackTreeNoCase(EStringRedBlackTreeNoCase &)  // 0x809057D0
    ~EStringRedBlackTreeNoCase(void);  // 0x808FC4C0

    // Methods
    void Head(void);  // 0x808FBC00 (68B)
    void Next(SRBNCIteratorPtrType *);  // 0x808FBB50 (176B)
    bool IsValid(SRBNCIteratorPtrType *);  // 0x808FC514 (56B)
    /* ? */ GetValue(SRBNCIteratorPtrType *);  // 0x808FC5A4 (164B)
    void operator[](char *);  // 0x80905D44 (180B)
    void RemoveAll(void);  // 0x80906E80 (64B)
    void Init(void);  // 0x80907640 (44B)
    void SetValues(EStringRedBlackTreeNoCase &, bool);  // 0x80906F98 (224B)
    void RotateLeft(EStringRedBlackTreeNoCaseNoCaseNode *);  // 0x8090582C (272B)
    void RotateRight(EStringRedBlackTreeNoCaseNoCaseNode *);  // 0x8090593C (272B)
    void InsertFixup(EStringRedBlackTreeNoCaseNoCaseNode *);  // 0x80905A4C (564B)
    void Find(char *, unsigned int *);  // 0x80906B8C (232B)
    void FindKeyOrParent(char *);  // 0x80905DF8 (216B)
    void InsertAt(EStringRedBlackTreeNoCaseNoCaseNode *, char *, unsigned int);  // 0x8090611C (768B)
    void FindParent(char *);  // 0x80905ED0 (172B)
    void SetValue(char *, unsigned int);  // 0x80905F7C (180B)
    void Insert(char *, unsigned int, bool);  // 0x80906030 (236B)
    void RemoveFixup(EStringRedBlackTreeNoCaseNoCaseNode *);  // 0x8090641C (760B)
    void Remove(char *);  // 0x80906714 (120B)
    void Remove(SRBNCIteratorPtrType *);  // 0x8090678C (872B)
    void Remove(EStringRedBlackTreeNoCase &);  // 0x80906AF4 (152B)
    /* ? */ GetKey(SRBNCIteratorPtrType *);  // 0x809074F8 (164B)
    void FindFirst(char *, unsigned int *);  // 0x80906C74 (228B)
    void Last(SRBNCIteratorPtrType *);  // 0x80907354 (176B)
    void FindNext(SRBNCIteratorPtrType *, unsigned int *);  // 0x80906D58 (296B)
    void FreeAll(void);  // 0x80906EC0 (148B)
    /* ? */ GetSize(void);  // 0x80906F54 (68B)
    void operator=(EStringRedBlackTreeNoCase &);  // 0x80907078 (84B)
    void operator==(EStringRedBlackTreeNoCase &);  // 0x809070CC (316B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (EStringRedBlackTreeNoCase, Find, FreeAll, ...)
    u32 m_field_004;  // 0x004 [R/W] (EStringRedBlackTreeNoCase, Find, InsertAt, ...)
    u32 m_field_008;  // 0x008 [R/W] (EStringRedBlackTreeNoCase, Find, FindKeyOrParent, ...)
    u32 m_field_00C;  // 0x00C [W] (InsertAt)
    u32 m_field_010;  // 0x010 [W] (InsertAt)
    u32 m_field_014;  // 0x014 [W] (InsertAt)
    u32 m_field_018;  // 0x018 [R/W] (Find, InsertAt)
    u32 m_field_01C;  // 0x01C [R] (InsertAt)
};

#endif // ESTRINGREDBLACKTREENOCASE_H
