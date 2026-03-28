#ifndef EHASHTABLE_H
#define EHASHTABLE_H

#include "types.h"

// EHashTable - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 5 known fields (4 named), 56 methods

class EHashTable {
public:
    // Constructors / Destructors
    EHashTable(int)  // 0x80751640
    EHashTable(EHashTable &)  // 0x80751690
    ~EHashTable(void);  // 0x807516F0

    // Methods
    void FindFirst(unsigned int, unsigned int *);  // 0x80652AAC (84B)
    void RemoveAll(void);  // 0x807524D0 (64B)
    void AutoSizeTable(void);  // 0x80752648 (148B)
    void SetTableSize(int);  // 0x807526DC (332B)
    void Insert(unsigned int, unsigned int, bool);  // 0x80751B94 (392B)
    void Remove(HTIteratorPtrType *);  // 0x80751F8C (208B)
    void FindNext(HTIteratorPtrType *, unsigned int *);  // 0x807522B4 (284B)
    void Find(unsigned int, unsigned int *);  // 0x807521E8 (204B)
    void InitTable(int);  // 0x8075175C (308B)
    void SetValues(EHashTable &);  // 0x80752828 (160B)
    void ClearTable(void);  // 0x80751890 (80B)
    void operator[](unsigned int);  // 0x807518E0 (196B)
    bool IsValid(HTIteratorPtrType *);  // 0x807529CC (56B)
    bool Hash(unsigned int);  // 0x80752C98 (64B)
    void Find(unsigned int, unsigned int);  // 0x807523D0 (256B)
    void InsertNew(unsigned int, unsigned int, unsigned int);  // 0x80751D1C (480B)
    void SetValue(unsigned int, unsigned int);  // 0x80751A94 (256B)
    void Remove(unsigned int);  // 0x80751EFC (144B)
    void Remove(unsigned int, HTIteratorPtrType *);  // 0x8075205C (396B)
    /* ? */ GetKey(HTIteratorPtrType *);  // 0x80752B50 (164B)
    void FreeAll(void);  // 0x80752510 (148B)
    void Head(void);  // 0x80752B0C (68B)
    /* ? */ GetValue(HTIteratorPtrType *);  // 0x80752BF4 (164B)
    void Next(HTIteratorPtrType *);  // 0x80752A30 (176B)
    /* ? */ GetSize(void);  // 0x807525A4 (68B)
    void operator=(EHashTable &);  // 0x807525E8 (96B)
    void operator==(EHashTable &);  // 0x807528C8 (260B)
    /* ? */ GetTableSize(void);  // 0x807BBF04 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (EHashTable, FreeAll, InsertNew, ...)
    u32 m_field_004;  // 0x004 [R/W] (EHashTable, InsertNew, Remove, ...)
    u32 m_tableSize_008;  // 0x008 [R/W] (Find, FindNext, InitTable, ...)
    u32 m_value;  // 0x00C [R/W] (Find, FindNext, InitTable, ...)
    u32 m_value_010;  // 0x010 [R/W] (Find, FindNext, SetValue, ...)
};

#endif // EHASHTABLE_H
