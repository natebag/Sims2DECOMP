#ifndef ETYPEINFO_H
#define ETYPEINFO_H

#include "types.h"

// ETypeInfo - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 11 known fields (1 named), 15 methods

class ETypeInfo {
public:
    // Methods
    void SetReadVersion(unsigned short);  // 0x80749C2C (44B)
    void New(void);  // 0x80749BE4 (72B)
    /* ? */ GetBaseClass(void);  // 0x80749C58 (44B)
    /* ? */ GetName(void);  // 0x807696C8 (44B)
    /* ? */ GetVersion(void);  // 0x8076CA64 (48B)
    /* ? */ GetKey(void);  // 0x8076CAC0 (44B)
    void Register(EStorable *(*);  // 0x8077886C (208B)
    void Find(unsigned int);  // 0x80778AA0 (152B)
    bool IsDerivedFrom(ETypeInfo *);  // 0x80778B38 (220B)
    void CalcKey(char *);  // 0x80778C40 (68B)
    void Insert(void);  // 0x8077893C (356B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (Register)
    u32 m_field_004;  // 0x004 [W] (Register)
    u32 m_field_008;  // 0x008 [W] (Register)
    u32 m_field_00C;  // 0x00C [W] (Register)
    u32 m_field_010;  // 0x010 [R/W] (Insert, Register)
    u16 m_field_014;  // 0x014 [W] (Register)
    u16 m_field_016;  // 0x016 [W] (Register)
    u32 m_field_018;  // 0x018 [W] (Register)
    u32 m_field_01C;  // 0x01C [W] (Insert)
    u32 m_field_020;  // 0x020 [W] (Insert)
    u32 m_field_024;  // 0x024 [W] (Insert)
};

#endif // ETYPEINFO_H
