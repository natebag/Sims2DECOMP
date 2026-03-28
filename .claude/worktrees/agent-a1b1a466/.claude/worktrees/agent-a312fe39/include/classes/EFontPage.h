#ifndef EFONTPAGE_H
#define EFONTPAGE_H

#include "types.h"

// EFontPage - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 3 known fields (0 named), 36 methods

class EFontPage {
public:
    // Constructors / Destructors
    EFontPage(void)  // 0x807B9290
    ~EFontPage(void);  // 0x807BC50C

    // Methods
    void Write(EStream &);  // 0x807B92EC (108B)
    void Read(EStream &);  // 0x807B9358 (252B)
    void DeallocateShader(void);  // 0x807B9544 (84B)
    /* ? */ GetReadVersion(void);  // 0x807BC788 (52B)
    void Load(EFile &);  // 0x807B9454 (240B)
    void SafeDelete(void);  // 0x807BC628 (108B)
    /* ? */ GetTypeInfo(void);  // 0x807BC694 (44B)
    /* ? */ GetTypeName(void);  // 0x807BC6C0 (52B)
    /* ? */ GetTypeKey(void);  // 0x807BC6F4 (52B)
    /* ? */ GetTypeVersion(void);  // 0x807BC728 (56B)
    void RegisterType(unsigned short);  // 0x807BC7BC (116B)
    void New(void);  // 0x807BC54C (80B)
    void Construct(EFontPage *);  // 0x807BC59C (80B)
    void Destruct(EFontPage *);  // 0x807BC5EC (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x807BC760 (40B)
    void CreateCopy(void);  // 0x807BC830 (68B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    u32 m_field_004;  // 0x004 [R] (Write)
    u8 _pad_008[4];  // 0x008
    u32 m_field_00C;  // 0x00C [R] (Write)
    u32 m_field_010;  // 0x010 [R] (Write)
};

#endif // EFONTPAGE_H
