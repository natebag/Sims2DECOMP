#ifndef EFONTCHARACTER_H
#define EFONTCHARACTER_H

#include "types.h"

// EFontCharacter - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (0 named), 33 methods

class EFontCharacter {
public:
    // Constructors / Destructors
    EFontCharacter(void)  // 0x807BDC68
    ~EFontCharacter(void);  // 0x807BC1A4

    // Methods
    void Write(EStream &);  // 0x807B8E9C (140B)
    void Read(EStream &);  // 0x807B8F28 (264B)
    /* ? */ GetReadVersion(void);  // 0x807BC420 (52B)
    void Load(EFile &);  // 0x807B9030 (252B)
    void SafeDelete(void);  // 0x807BC2C0 (108B)
    /* ? */ GetTypeInfo(void);  // 0x807BC32C (44B)
    /* ? */ GetTypeName(void);  // 0x807BC358 (52B)
    /* ? */ GetTypeKey(void);  // 0x807BC38C (52B)
    /* ? */ GetTypeVersion(void);  // 0x807BC3C0 (56B)
    void RegisterType(unsigned short);  // 0x807BC454 (116B)
    void New(void);  // 0x807BC1E4 (80B)
    void Construct(EFontCharacter *);  // 0x807BC234 (80B)
    void Destruct(EFontCharacter *);  // 0x807BC284 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x807BC3F8 (40B)
    void CreateCopy(void);  // 0x807BC4C8 (68B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    u32 m_field_004;  // 0x004 [R] (Write)
    u32 m_field_008;  // 0x008 [R] (Write)
    u16 m_field_00C;  // 0x00C [R] (Write)
    u16 m_field_00E;  // 0x00E [R] (Write)
};

#endif // EFONTCHARACTER_H
