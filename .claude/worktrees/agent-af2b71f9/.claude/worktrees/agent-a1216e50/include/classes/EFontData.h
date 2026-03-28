#ifndef EFONTDATA_H
#define EFONTDATA_H

#include "types.h"

// EFontData - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 8 known fields (1 named), 36 methods

class EFontData {
public:
    // Constructors / Destructors
    EFontData(void)  // 0x807B9D28
    ~EFontData(void);  // 0x807B9DC4

    // Methods
    void Deallocate(void);  // 0x807B9E38 (72B)
    void Write(EStream &);  // 0x807B9E80 (196B)
    void Read(EStream &);  // 0x807B9F44 (352B)
    /* ? */ GetReadVersion(void);  // 0x807BCE98 (52B)
    void Load(EFile &);  // 0x807BA0A4 (340B)
    void SafeDelete(void);  // 0x807BCD38 (108B)
    /* ? */ GetTypeInfo(void);  // 0x807BCDA4 (44B)
    /* ? */ GetTypeName(void);  // 0x807BCDD0 (52B)
    /* ? */ GetTypeKey(void);  // 0x807BCE04 (52B)
    /* ? */ GetTypeVersion(void);  // 0x807BCE38 (56B)
    void RegisterType(unsigned short);  // 0x807BCECC (116B)
    void New(void);  // 0x807BCC5C (80B)
    void Construct(EFontData *);  // 0x807BCCAC (80B)
    void Destruct(EFontData *);  // 0x807BCCFC (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x807BCE70 (40B)
    void CreateCopy(void);  // 0x807BCF40 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (EFontData, ~EFontData)
    u32 m_field_004;  // 0x004 [W] (EFontData)
    u8 _pad_008[8];  // 0x008
    u32 m_field_010;  // 0x010 [R/W] (EFontData, Write)
    u32 m_field_014;  // 0x014 [R/W] (EFontData, Write)
    u32 m_field_018;  // 0x018 [R/W] (EFontData, Read, Write)
    u32 m_field_01C;  // 0x01C [R/W] (EFontData, Write)
    u32 m_field_020;  // 0x020 [R/W] (EFontData, Write)
    u32 m_field_024;  // 0x024 [R/W] (EFontData, Write)
};

#endif // EFONTDATA_H
