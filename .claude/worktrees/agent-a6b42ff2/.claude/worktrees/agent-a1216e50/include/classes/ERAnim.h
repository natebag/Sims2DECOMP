#ifndef ERANIM_H
#define ERANIM_H

#include "types.h"

// ERAnim - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8C (140 bytes)
// 9 known fields (1 named), 34 methods

class ERAnim {
public:
    // Constructors / Destructors
    ERAnim(void)  // 0x80836BA4
    ~ERAnim(void);  // 0x80836CC8

    // Methods
    void Load(EFile *);  // 0x8083744C (1156B)
    void OldLoad(EFile *);  // 0x808378D0 (1208B)
    void Refresh(EFile *);  // 0x80837D88 (76B)
    void SafeDelete(void);  // 0x8083A324 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8083A390 (44B)
    /* ? */ GetTypeName(void);  // 0x8083A3BC (52B)
    /* ? */ GetTypeKey(void);  // 0x8083A3F0 (52B)
    /* ? */ GetTypeVersion(void);  // 0x8083A424 (56B)
    void RegisterType(unsigned short);  // 0x8083A4B8 (116B)
    void New(void);  // 0x8083A250 (76B)
    void Construct(ERAnim *);  // 0x8083A29C (76B)
    void Destruct(ERAnim *);  // 0x8083A2E8 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8083A45C (40B)
    /* ? */ GetReadVersion(void);  // 0x8083A484 (52B)
    void CreateCopy(void);  // 0x8083A52C (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ERAnim, ~ERAnim)
    u8 _pad_004[0xC];  // 0x004
    u32 m_field_010;  // 0x010 [R/W] (Load, OldLoad)
    u32 m_field_014;  // 0x014 [W] (Load, OldLoad)
    u32 m_field_018;  // 0x018 [R/W] (ERAnim, Load, OldLoad)
    u32 m_field_01C;  // 0x01C [W] (ERAnim)
    u8 _pad_020[8];  // 0x020
    u32 m_field_028;  // 0x028 [R/W] (ERAnim)
    u8 _pad_02C[0x24];  // 0x02C
    u32 m_field_050;  // 0x050 [R] (Load, OldLoad)
    u8 _pad_054[0x10];  // 0x054
    f32 m_field_064;  // 0x064 [R/W] (ERAnim, Load, OldLoad)
    u8 _pad_068[0x20];  // 0x068
    u32 m_field_088;  // 0x088 [R] (Load)
};

#endif // ERANIM_H
