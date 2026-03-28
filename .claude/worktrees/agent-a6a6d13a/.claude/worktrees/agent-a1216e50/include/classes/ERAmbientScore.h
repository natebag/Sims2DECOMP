#ifndef ERAMBIENTSCORE_H
#define ERAMBIENTSCORE_H

#include "types.h"

// ERAmbientScore - struct layout extracted from assembly analysis
// Estimated minimum size: 0x34 (52 bytes)
// 11 known fields (1 named), 32 methods

class ERAmbientScore {
public:
    // Constructors / Destructors
    ERAmbientScore(void)  // 0x808333B0
    ~ERAmbientScore(void);  // 0x80833464

    // Methods
    void Load(EFile *, unsigned int);  // 0x808334EC (924B)
    void Refresh(EFile *);  // 0x80833888 (80B)
    void SafeDelete(void);  // 0x80835884 (108B)
    /* ? */ GetTypeInfo(void);  // 0x808358F0 (44B)
    /* ? */ GetTypeName(void);  // 0x8083591C (52B)
    /* ? */ GetTypeKey(void);  // 0x80835950 (52B)
    /* ? */ GetTypeVersion(void);  // 0x80835984 (56B)
    void RegisterType(unsigned short);  // 0x80835A18 (116B)
    void New(void);  // 0x808357B0 (76B)
    void Construct(ERAmbientScore *);  // 0x808357FC (76B)
    void Destruct(ERAmbientScore *);  // 0x80835848 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x808359BC (40B)
    /* ? */ GetReadVersion(void);  // 0x808359E4 (52B)
    void CreateCopy(void);  // 0x80835A8C (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ERAmbientScore, ~ERAmbientScore)
    u8 _pad_004[0x10];  // 0x004
    u32 m_field_014;  // 0x014 [W] (ERAmbientScore)
    u32 m_field_018;  // 0x018 [W] (ERAmbientScore)
    u32 m_field_01C;  // 0x01C [W] (ERAmbientScore)
    u32 m_field_020;  // 0x020 [R/W] (ERAmbientScore, Load, ~ERAmbientScore)
    u32 m_field_024;  // 0x024 [W] (ERAmbientScore)
    u8 m_field_028;  // 0x028 [W] (ERAmbientScore)
    u8 m_field_029;  // 0x029 [W] (ERAmbientScore)
    u8 m_field_02A;  // 0x02A [W] (ERAmbientScore)
    u8 _pad_02B[1];  // 0x02B
    u32 m_field_02C;  // 0x02C [R/W] (ERAmbientScore, Load, ~ERAmbientScore)
    u32 m_field_030;  // 0x030 [W] (ERAmbientScore)
};

#endif // ERAMBIENTSCORE_H
