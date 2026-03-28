#ifndef APTARRAY_H
#define APTARRAY_H

#include "types.h"

// AptArray - struct layout extracted from assembly analysis
// Estimated minimum size: 0x30 (48 bytes)
// 10 known fields (2 named), 62 methods

class AptArray {
public:
    // Constructors / Destructors
    AptArray(void)  // 0x806C6698
    AptArray(int, AptValue **)  // 0x806C65C8
    ~AptArray(void);  // 0x806C6704

    // Methods
    void CleanNativeFunctions(void);  // 0x806C6844 (1056B)
    void set(int, AptValue *);  // 0x806C70B0 (212B)
    void get(int);  // 0x806C7184 (148B)
    void length(void);  // 0x806C96BC (44B)
    /* ? */ GetAt(int);  // 0x806C96E8 (224B)
    void _reserve(int);  // 0x806C6F08 (424B)
    void SetAt(int, AptValue *);  // 0x806C97C8 (388B)
    void DestroyGCPointers(void);  // 0x806C6C64 (488B)
    void RegisterReferences(void);  // 0x806C6E4C (188B)
    void toString(char *, char *);  // 0x806C7218 (204B)
    void toString(EAStringC &, char *);  // 0x806C72E4 (352B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x806C7444 (2660B)
    void sMethod_concat(AptValue *, int);  // 0x806C8038 (440B)
    void sMethod_join(AptValue *, int);  // 0x806C81F0 (324B)
    void sMethod_pop(AptValue *, int);  // 0x806C8334 (216B)
    void sMethod_push(AptValue *, int);  // 0x806C840C (208B)
    void sMethod_shift(AptValue *, int);  // 0x806C84DC (268B)
    void sMethod_unshift(AptValue *, int);  // 0x806C85E8 (360B)
    void sMethod_reverse(AptValue *, int);  // 0x806C8D98 (328B)
    void sMethod_sort(AptValue *, int);  // 0x806C89D0 (224B)
    void sMethod_splice(AptValue *, int);  // 0x806C8EE0 (1048B)
    void sMethod_slice(AptValue *, int);  // 0x806C92F8 (496B)
    void sMethod_sortOn(AptValue *, int);  // 0x806C8CE0 (184B)
    void objectMemberSet(AptValue *, EAStringC *, AptValue *);  // 0x806C7F28 (272B)
    void defaultSortCompareFunc(void *, void *);  // 0x806C8750 (328B)
    void ConvertAptValue(AptValue *);  // 0x806C994C (40B)
    void scriptFunctionSortFunc(void *, void *);  // 0x806C8898 (312B)
    void defaultSortOnCompareFunc(void *, void *);  // 0x806C8AB0 (560B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (defaultSortCompareFunc, defaultSortOnCompareFunc, objectMemberLookup, ...)
    u16 m_field_002;  // 0x002 [R] (objectMemberLookup)
    u32 m_field_004;  // 0x004 [R] (objectMemberLookup)
    u32 m_field_008;  // 0x008 [R/W] (AptArray, objectMemberLookup, sMethod_push, ...)
    u32 m_field_00C;  // 0x00C [R/W] (objectMemberLookup, sMethod_join, sMethod_push, ...)
    u32 m_field_010;  // 0x010 [R] (sMethod_join)
    u8 _pad_014[0xC];  // 0x014
    u8 m_field_020;  // 0x020 [R/W] (AptArray, objectMemberLookup)
    u8 _pad_021[3];  // 0x021
    u32 m_at;  // 0x024 [R/W] (AptArray, DestroyGCPointers, RegisterReferences, ...)
    u32 m_field_028;  // 0x028 [R/W] (AptArray, DestroyGCPointers, _reserve)
    u32 m_field_02C;  // 0x02C [R/W] (AptArray, DestroyGCPointers, RegisterReferences, ...)
};

#endif // APTARRAY_H
