#ifndef EFONTSIZE_H
#define EFONTSIZE_H

#include "types.h"

// EFontSize - struct layout extracted from assembly analysis
// Estimated minimum size: 0x2C (44 bytes)
// 7 known fields (1 named), 40 methods

class EFontSize {
public:
    // Constructors / Destructors
    EFontSize(void)  // 0x807B96FC
    ~EFontSize(void);  // 0x807B977C

    // Methods
    void Deallocate(void);  // 0x807B97F0 (68B)
    void DeallocatePages(void);  // 0x807B98B8 (60B)
    void DeallocateShaders(void);  // 0x807B9834 (132B)
    void Write(EStream &);  // 0x807B98F4 (148B)
    void Read(EStream &);  // 0x807B9988 (292B)
    /* ? */ GetReadVersion(void);  // 0x807BCAF0 (52B)
    void Load(EFile &);  // 0x807B9AAC (280B)
    void SafeDelete(void);  // 0x807BC990 (108B)
    /* ? */ GetTypeInfo(void);  // 0x807BC9FC (44B)
    /* ? */ GetTypeName(void);  // 0x807BCA28 (52B)
    /* ? */ GetTypeKey(void);  // 0x807BCA5C (52B)
    /* ? */ GetTypeVersion(void);  // 0x807BCA90 (56B)
    void RegisterType(unsigned short);  // 0x807BCB24 (116B)
    void New(void);  // 0x807BC8B4 (80B)
    void Construct(EFontSize *);  // 0x807BC904 (80B)
    void Destruct(EFontSize *);  // 0x807BC954 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x807BCAC8 (40B)
    void CreateCopy(void);  // 0x807BCB98 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (EFontSize, ~EFontSize)
    u32 m_field_004;  // 0x004 [R/W] (EFontSize, Write)
    u32 m_field_008;  // 0x008 [R/W] (EFontSize, Write)
    u32 m_field_00C;  // 0x00C [R/W] (EFontSize, Write)
    u32 m_field_010;  // 0x010 [R] (Deallocate)
    u8 _pad_014[0xC];  // 0x014
    u32 m_field_020;  // 0x020 [R] (DeallocateShaders)
    u8 _pad_024[4];  // 0x024
    u32 m_field_028;  // 0x028 [R] (Load)
};

#endif // EFONTSIZE_H
