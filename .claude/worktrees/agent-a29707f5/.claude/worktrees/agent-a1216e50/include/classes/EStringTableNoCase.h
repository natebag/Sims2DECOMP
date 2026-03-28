#ifndef ESTRINGTABLENOCASE_H
#define ESTRINGTABLENOCASE_H

#include "types.h"

// EStringTableNoCase - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 6 known fields (2 named), 56 methods

class EStringTableNoCase {
public:
    // Constructors / Destructors
    EStringTableNoCase(void)  // 0x80907FB0
    EStringTableNoCase(EStringTableNoCase &)  // 0x80908010
    ~EStringTableNoCase(void);  // 0x80908080

    // Methods
    bool IsEmpty(void);  // 0x808FBAC0 (68B)
    void Head(void);  // 0x808FBA7C (68B)
    void Next(STNCIteratorPtrType *);  // 0x808FB9CC (176B)
    bool IsValid(STNCIteratorPtrType *);  // 0x808FC354 (56B)
    /* ? */ GetValue(STNCIteratorPtrType *);  // 0x808FC41C (164B)
    void RemoveAll(void);  // 0x80908E24 (72B)
    void SetValue(char *, unsigned int);  // 0x8090851C (256B)
    void Find(char *, unsigned int *);  // 0x80908C0C (240B)
    void Remove(STNCIteratorPtrType *);  // 0x80908978 (208B)
    void InitTable(int);  // 0x809081B8 (340B)
    void SetValues(EStringTableNoCase &);  // 0x80909190 (160B)
    bool Hash(char *);  // 0x809080EC (204B)
    void ClearTable(void);  // 0x8090830C (92B)
    void operator[](char *);  // 0x80908368 (196B)
    void Find(unsigned int, char *);  // 0x80908CFC (296B)
    void InsertNew(unsigned int, char *, unsigned int);  // 0x80908718 (464B)
    void Insert(char *, unsigned int);  // 0x8090861C (252B)
    void GrowTable(void);  // 0x809090B4 (220B)
    void Remove(char *);  // 0x809088E8 (144B)
    void Remove(unsigned int, STNCIteratorPtrType *);  // 0x80908A48 (452B)
    /* ? */ GetKey(STNCIteratorPtrType *);  // 0x809095DC (176B)
    void FreeAll(void);  // 0x80908E6C (148B)
    /* ? */ GetSize(void);  // 0x80908F00 (68B)
    void operator=(EStringTableNoCase &);  // 0x80908F44 (80B)
    void PreGrowTable(int);  // 0x80908F94 (184B)
    void FreeTable(void);  // 0x8090904C (104B)
    void operator==(EStringTableNoCase &);  // 0x80909230 (260B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (EStringTableNoCase, FreeAll, GrowTable, ...)
    u32 m_field_004;  // 0x004 [R/W] (EStringTableNoCase, InsertNew, Remove, ...)
    u32 m_field_008;  // 0x008 [R/W] (EStringTableNoCase, Find, FreeTable, ...)
    u32 m_field_00C;  // 0x00C [R/W] (Find, FreeTable, GrowTable, ...)
    u32 m_bHash;  // 0x010 [R/W] (Find, FreeTable, Hash, ...)
    u32 m_field_014;  // 0x014 [R/W] (EStringTableNoCase, FreeTable, InsertNew, ...)
};

#endif // ESTRINGTABLENOCASE_H
