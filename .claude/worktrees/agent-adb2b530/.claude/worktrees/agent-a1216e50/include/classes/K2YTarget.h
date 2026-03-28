#ifndef K2YTARGET_H
#define K2YTARGET_H

#include "types.h"

// K2YTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x108 (264 bytes)
// 24 known fields (7 named), 26 methods

class K2YTarget {
public:
    // Constructors / Destructors
    K2YTarget(void)  // 0x8050DCB0
    ~K2YTarget(void);  // 0x8050E184

    // Methods
    /* ? */ GetMode(void);  // 0x80551EBC (44B)
    void SetStartMode(K2YTarget::eK2yboardMode);  // 0x8050F6E8 (184B)
    /* ? */ GetSavedFirstName(void);  // 0x80551EE8 (40B)
    /* ? */ GetSavedLastName(void);  // 0x80551F10 (40B)
    void SaveName(void);  // 0x8050F7A0 (380B)
    /* ? */ GetName(void);  // 0x8050E1F4 (600B)
    bool IsModeValid(void);  // 0x8050E44C (164B)
    void SetVariable(char *, char *);  // 0x8050E4F0 (1288B)
    /* ? */ GetVariable(char *);  // 0x8050E9F8 (1408B)
    /* ? */ GetKeybits(int, int);  // 0x8050F458 (656B)
    /* ? */ GetLocalizable(char *);  // 0x8050EF78 (1248B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_variable;  // 0x000 [R/W] (GetLocalizable, GetVariable, K2YTarget, ...)
    u8 m_variable_001;  // 0x001 [W] (GetVariable)
    u8 _pad_002[2];  // 0x002
    u16 m_variable_004;  // 0x004 [R/W] (GetVariable, K2YTarget, ~K2YTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (K2YTarget, ~K2YTarget)
    u8 m_variable_00C;  // 0x00C [R/W] (GetVariable, K2YTarget, ~K2YTarget)
    u8 _pad_00D[3];  // 0x00D
    u32 m_field_010;  // 0x010 [R/W] (K2YTarget, ~K2YTarget)
    u32 m_field_014;  // 0x014 [R/W] (K2YTarget, ~K2YTarget)
    u32 m_field_018;  // 0x018 [R/W] (K2YTarget, ~K2YTarget)
    u32 m_field_01C;  // 0x01C [R/W] (K2YTarget, ~K2YTarget)
    u8 m_variable_01F;  // 0x01F [W] (GetVariable)
    u32 m_field_020;  // 0x020 [R/W] (K2YTarget, ~K2YTarget)
    u32 m_field_024;  // 0x024 [R/W] (K2YTarget, ~K2YTarget)
    u32 m_field_028;  // 0x028 [W] (K2YTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (K2YTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (K2YTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (K2YTarget, ~K2YTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (K2YTarget, ~K2YTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (K2YTarget)
    u32 m_field_07C;  // 0x07C [R/W] (K2YTarget, ~K2YTarget)
    u32 m_field_080;  // 0x080 [W] (K2YTarget, ~K2YTarget)
    u32 m_field_084;  // 0x084 [W] (K2YTarget)
    u32 m_field_088;  // 0x088 [W] (K2YTarget, ~K2YTarget)
    u8 _pad_08C[0x78];  // 0x08C
    u32 m_variable_104;  // 0x104 [R] (GetVariable)
};

#endif // K2YTARGET_H
