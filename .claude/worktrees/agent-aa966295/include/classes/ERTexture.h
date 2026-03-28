#ifndef ERTEXTURE_H
#define ERTEXTURE_H

#include "types.h"

// ERTexture - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 4 known fields (2 named), 44 methods

class ERTexture {
public:
    // Constructors / Destructors
    ERTexture(void)  // 0x80875FCC
    ~ERTexture(void);  // 0x80876020

    // Methods
    void Attach(ETexture *);  // 0x8087608C (68B)
    void Load(unsigned char *);  // 0x808763F8 (192B)
    void Deallocate(void);  // 0x808760D0 (120B)
    void Refresh(EFile *);  // 0x80876148 (296B)
    void Load(EFile &);  // 0x80876270 (392B)
    void LoadFromMemory(unsigned char *);  // 0x808764B8 (1452B)
    bool IsSafeToDelete(void);  // 0x80876A64 (224B)
    void SafeDelete(void);  // 0x8087758C (108B)
    /* ? */ GetTypeInfo(void);  // 0x808775F8 (44B)
    /* ? */ GetTypeName(void);  // 0x80877624 (52B)
    /* ? */ GetTypeKey(void);  // 0x80877658 (52B)
    /* ? */ GetTypeVersion(void);  // 0x8087768C (56B)
    void RegisterType(unsigned short);  // 0x80877720 (116B)
    void New(void);  // 0x808774B8 (76B)
    void Construct(ERTexture *);  // 0x80877504 (76B)
    void Destruct(ERTexture *);  // 0x80877550 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x808776C4 (40B)
    /* ? */ GetReadVersion(void);  // 0x808776EC (52B)
    void CreateCopy(void);  // 0x80877794 (68B)
    void Select(ERC *, int);  // 0x80877894 (108B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ERTexture, LoadFromMemory, Refresh, ...)
    u8 _pad_004[0xC];  // 0x004
    u32 m_field_010;  // 0x010 [R/W] (Load, LoadFromMemory)
    u32 m_bIsSafeToDelete;  // 0x014 [R/W] (Deallocate, ERTexture, IsSafeToDelete, ...)
    u8 _pad_018[0xC];  // 0x018
    u32 m_field_024;  // 0x024 [R] (LoadFromMemory)
};

#endif // ERTEXTURE_H
