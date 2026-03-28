#ifndef APTSTRING_H
#define APTSTRING_H

#include "types.h"

// AptString - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 10 known fields (0 named), 60 methods

class AptString {
public:
    // Constructors / Destructors
    AptString(void)  // 0x806FD010
    AptString(char *)  // 0x806FD0EC
    ~AptString(void);  // 0x806FD074

    // Methods
    void CleanNativeFunctions(void);  // 0x806FD1C8 (1148B)
    void Create(void);  // 0x806FCE50 (348B)
    void cpy(char *);  // 0x806FF594 (96B)
    /* ? */ GetInternalString(void);  // 0x806FF67C (44B)
    void cpy(EAStringC *);  // 0x806FF550 (68B)
    void Destroy(void);  // 0x806FCFAC (100B)
    void DeleteThis(void);  // 0x806FD158 (56B)
    void ForceDelete(void);  // 0x806FD190 (56B)
    void sMethod_charAt(AptValue *, int);  // 0x806FD644 (280B)
    void sMethod_charCodeAt(AptValue *, int);  // 0x806FD75C (312B)
    void sMethod_concat(AptValue *, int);  // 0x806FD894 (276B)
    void sMethod_fromCharCode(AptValue *, int);  // 0x806FD9A8 (284B)
    void sMethod_indexOf(AptValue *, int);  // 0x806FDAC4 (460B)
    void sMethod_lastIndexOf(AptValue *, int);  // 0x806FDC90 (48B)
    void sMethod_slice(AptValue *, int);  // 0x806FDCC0 (576B)
    void sMethod_split(AptValue *, int);  // 0x806FDF00 (984B)
    void sMethod_substr(AptValue *, int);  // 0x806FE2D8 (400B)
    void sMethod_substring(AptValue *, int);  // 0x806FE468 (484B)
    void sMethod_toLowerCase(AptValue *, int);  // 0x806FE64C (156B)
    void sMethod_toUpperCase(AptValue *, int);  // 0x806FE6E8 (156B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x806FE784 (2564B)
    void printf(char *,...);  // 0x806FF188 (264B)
    void Create(char *);  // 0x806FF290 (376B)
    void cat(EAStringC *);  // 0x806FF5F4 (68B)
    void cat(char *);  // 0x806FF638 (68B)
    void SetNext(AptString *);  // 0x806FF6A8 (40B)
    /* ? */ GetNext(void);  // 0x806FF6D0 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_field_000;  // 0x000 [R/W] (objectMemberLookup, sMethod_charAt, sMethod_charCodeAt, ...)
    u8 m_field_001;  // 0x001 [R] (sMethod_charCodeAt, sMethod_split)
    u16 m_field_002;  // 0x002 [R] (objectMemberLookup, sMethod_charCodeAt, sMethod_split)
    u8 m_field_003;  // 0x003 [R] (sMethod_charCodeAt, sMethod_split)
    u16 m_field_004;  // 0x004 [R] (objectMemberLookup, sMethod_charAt, sMethod_charCodeAt, ...)
    u8 _pad_006[2];  // 0x006
    u32 m_field_008;  // 0x008 [R/W] (AptString, objectMemberLookup, sMethod_indexOf, ...)
    u32 m_field_00C;  // 0x00C [R/W] (AptString, objectMemberLookup, printf, ...)
    u32 m_field_010;  // 0x010 [R/W] (AptString, DeleteThis, Destroy, ...)
    u8 _pad_014[0xC];  // 0x014
    u8 m_field_020;  // 0x020 [R/W] (objectMemberLookup)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [R/W] (objectMemberLookup, sMethod_charAt, sMethod_charCodeAt, ...)
};

#endif // APTSTRING_H
