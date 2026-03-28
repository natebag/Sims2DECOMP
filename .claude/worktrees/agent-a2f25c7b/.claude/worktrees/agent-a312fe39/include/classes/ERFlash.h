#ifndef ERFLASH_H
#define ERFLASH_H

#include "types.h"

// ERFlash - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 3 known fields (1 named), 34 methods

class ERFlash {
public:
    // Constructors / Destructors
    ERFlash(void)  // 0x8084D9C8
    ~ERFlash(void);  // 0x8084DA1C

    // Methods
    /* ? */ GetFlashBigData(void);  // 0x8084DC3C (84B)
    void Deallocate(void);  // 0x8084DA88 (96B)
    void Load(EFile *, unsigned int);  // 0x8084DAE8 (340B)
    void SafeDelete(void);  // 0x8084E868 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8084E8D4 (44B)
    /* ? */ GetTypeName(void);  // 0x8084E900 (52B)
    /* ? */ GetTypeKey(void);  // 0x8084E934 (52B)
    /* ? */ GetTypeVersion(void);  // 0x8084E968 (56B)
    void RegisterType(unsigned short);  // 0x8084E9FC (116B)
    void New(void);  // 0x8084E794 (76B)
    void Construct(ERFlash *);  // 0x8084E7E0 (76B)
    void Destruct(ERFlash *);  // 0x8084E82C (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8084E9A0 (40B)
    /* ? */ GetReadVersion(void);  // 0x8084E9C8 (52B)
    void CreateCopy(void);  // 0x8084EA70 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ERFlash, ~ERFlash)
    u8 _pad_004[0xC];  // 0x004
    u32 m_field_010;  // 0x010 [R/W] (Load)
    u32 m_field_014;  // 0x014 [R/W] (Deallocate, ERFlash, Load)
};

#endif // ERFLASH_H
