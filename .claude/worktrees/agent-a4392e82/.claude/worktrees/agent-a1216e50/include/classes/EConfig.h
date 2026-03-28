#ifndef ECONFIG_H
#define ECONFIG_H

#include "types.h"

// EConfig - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 5 known fields (2 named), 41 methods

class EConfig {
public:
    // Constructors / Destructors
    EConfig(void)  // 0x80821724
    ~EConfig(void);  // 0x8082178C

    // Methods
    bool IsOpened(void);  // 0x8082181C (76B)
    void Open(char *);  // 0x808FA09C (568B)
    /* ? */ GetInt(char *, int);  // 0x808FAB84 (136B)
    /* ? */ GetFloat(char *, float);  // 0x808FADB4 (136B)
    /* ? */ GetString(char *, char *);  // 0x808FA9FC (288B)
    void Close(bool, bool, char *);  // 0x808FA2D4 (216B)
    /* ? */ GetS(char *, int, EFile *);  // 0x808FB4E4 (432B)
    void Write(char *);  // 0x808FA3AC (576B)
    void SetString(char *, char *);  // 0x808FA5EC (840B)
    void Delete(char *);  // 0x808FA934 (200B)
    void SetInt(char *, int);  // 0x808FAB1C (104B)
    void SetBool(char *, bool);  // 0x808FAC0C (128B)
    /* ? */ GetBool(char *, bool);  // 0x808FAC8C (184B)
    void SetFloat(char *, float);  // 0x808FAD44 (112B)
    void AddComment(char *);  // 0x808FAE3C (228B)
    void Sort(void);  // 0x808FAF20 (744B)
    void Empty(void);  // 0x808FB208 (80B)
    /* ? */ GetNextLabelAndValue(EString &, EString &, NLIteratorPtrType *);  // 0x808FB258 (368B)
    /* ? */ GetFirst(EString &, EString &);  // 0x808FB3C8 (88B)
    /* ? */ GetNext(NLIteratorPtrType *, EString &, EString &);  // 0x808FB420 (196B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddComment, Close, Delete, ...)
    u32 m_field_004;  // 0x004 [R] (Close, Open, Sort, ...)
    u32 m_nextLabelAndValue;  // 0x008 [R] (GetNextLabelAndValue, Sort, Write)
    u8 _pad_00C[4];  // 0x00C
    u32 m_field_010;  // 0x010 [R] (Sort)
    u32 m_field_014;  // 0x014 [R] (Sort)
};

#endif // ECONFIG_H
