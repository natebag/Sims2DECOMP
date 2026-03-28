#ifndef UIROUTER_H
#define UIROUTER_H

#include "types.h"

// UIRouter - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8C (140 bytes)
// 16 known fields (3 named), 8 methods

class UIRouter {
public:
    // Constructors / Destructors
    UIRouter(void)  // 0x80491F94
    ~UIRouter(void);  // 0x8049200C

    // Methods
    /* ? */ GetVariable(char *);  // 0x8049206C (412B)
    void SetVariable(char *, char *);  // 0x80492208 (408B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (UIRouter)
    u32 m_field_004;  // 0x004 [W] (UIRouter)
    u32 m_field_008;  // 0x008 [W] (UIRouter)
    u32 m_field_00C;  // 0x00C [W] (UIRouter)
    u32 m_field_010;  // 0x010 [W] (UIRouter)
    u32 m_field_014;  // 0x014 [W] (UIRouter)
    u32 m_field_018;  // 0x018 [W] (UIRouter)
    u8 _pad_01C[0xC];  // 0x01C
    u32 m_field_028;  // 0x028 [W] (UIRouter)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (UIRouter)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (UIRouter)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [W] (UIRouter)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [W] (UIRouter)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (UIRouter)
    u8 _pad_07C[4];  // 0x07C
    u32 m_field_080;  // 0x080 [W] (UIRouter, ~UIRouter)
    u32 m_variable;  // 0x084 [R/W] (GetVariable, UIRouter)
    u32 m_variable_088;  // 0x088 [R/W] (SetVariable, UIRouter)
};

#endif // UIROUTER_H
