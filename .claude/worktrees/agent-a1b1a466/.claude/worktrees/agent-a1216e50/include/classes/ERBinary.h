#ifndef ERBINARY_H
#define ERBINARY_H

#include "types.h"

// ERBinary - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 4 known fields (1 named), 36 methods

class ERBinary {
public:
    // Constructors / Destructors
    ERBinary(void)  // 0x8083B2BC
    ~ERBinary(void);  // 0x8083B318

    // Methods
    /* ? */ GetData(void);  // 0x8083B94C (44B)
    /* ? */ GetDataSize(void);  // 0x8083B978 (44B)
    void Deallocate(void);  // 0x8083B384 (80B)
    void Load(EFile *, unsigned int);  // 0x8083B3D4 (492B)
    void SafeDelete(void);  // 0x8083B700 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8083B76C (44B)
    /* ? */ GetTypeName(void);  // 0x8083B798 (52B)
    /* ? */ GetTypeKey(void);  // 0x8083B7CC (52B)
    /* ? */ GetTypeVersion(void);  // 0x8083B800 (56B)
    void RegisterType(unsigned short);  // 0x8083B894 (116B)
    void New(void);  // 0x8083B62C (76B)
    void Construct(ERBinary *);  // 0x8083B678 (76B)
    void Destruct(ERBinary *);  // 0x8083B6C4 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8083B838 (40B)
    /* ? */ GetReadVersion(void);  // 0x8083B860 (52B)
    void CreateCopy(void);  // 0x8083B908 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ERBinary, ~ERBinary)
    u8 _pad_004[0xC];  // 0x004
    u32 m_field_010;  // 0x010 [R/W] (Load)
    u32 m_field_014;  // 0x014 [R/W] (Deallocate, ERBinary, Load)
    u32 m_field_018;  // 0x018 [W] (Deallocate, ERBinary, Load)
};

#endif // ERBINARY_H
