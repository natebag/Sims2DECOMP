#ifndef SCROLLINGTEXTBOX_H
#define SCROLLINGTEXTBOX_H

#include "types.h"

// ScrollingTextBox - struct layout extracted from assembly analysis
// Estimated minimum size: 0x4F78 (20344 bytes)
// 20 known fields (7 named), 24 methods

class ScrollingTextBox {
public:
    // Constructors / Destructors
    ScrollingTextBox(void)  // 0x8014A9A8
    ~ScrollingTextBox(void);  // 0x8014AAF8

    // Methods
    void SetPosition(float, float, float, float);  // 0x8014ABB4 (80B)
    void SetPosition(EVec2 &, EVec2 &);  // 0x8014AC04 (96B)
    void SetScrollVelocity(float, float);  // 0x8014AC64 (56B)
    void SetScrollVelocity(EVec2 &);  // 0x8014AC9C (64B)
    void SetString(unsigned wchar_t *, float);  // 0x8014ACDC (324B)
    void SetTextColor(float, float, float, float);  // 0x8014AE20 (112B)
    void SetTextColor(EVec4 &);  // 0x8014AE90 (80B)
    void SetSubOffset(EVec2 &);  // 0x8014AEE0 (64B)
    void SetSubOffset(float, float);  // 0x8014AF20 (56B)
    void Draw(ERC *);  // 0x8014AF58 (2420B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_string;  // 0x000 [R/W] (Draw, ScrollingTextBox, SetString, ...)
    f32 m_string_004;  // 0x004 [R/W] (Draw, ScrollingTextBox, SetString)
    f32 m_field_008;  // 0x008 [R/W] (Draw, ScrollingTextBox)
    f32 m_string_00C;  // 0x00C [R/W] (Draw, ScrollingTextBox, SetString)
    f32 m_field_010;  // 0x010 [R/W] (Draw, ScrollingTextBox)
    f32 m_field_014;  // 0x014 [R/W] (Draw, ScrollingTextBox)
    f32 m_field_018;  // 0x018 [R/W] (Draw, ScrollingTextBox)
    f32 m_string_01C;  // 0x01C [R/W] (Draw, ScrollingTextBox, SetString)
    f32 m_field_020;  // 0x020 [R/W] (Draw, ScrollingTextBox)
    u32 m_field_024;  // 0x024 [R/W] (Draw, ScrollingTextBox, ~ScrollingTextBox)
    f32 m_string_028;  // 0x028 [R/W] (Draw, ScrollingTextBox, SetString)
    f32 m_string_02C;  // 0x02C [R/W] (Draw, ScrollingTextBox, SetString)
    f32 m_string_030;  // 0x030 [R/W] (Draw, ScrollingTextBox, SetString)
    f32 m_field_034;  // 0x034 [R/W] (Draw, ScrollingTextBox)
    f32 m_field_038;  // 0x038 [R/W] (Draw, ScrollingTextBox)
    u32 m_field_03C;  // 0x03C [R/W] (Draw, ScrollingTextBox, ~ScrollingTextBox)
    u32 m_field_040;  // 0x040 [W] (ScrollingTextBox, ~ScrollingTextBox)
    u8 _pad_044[0xAC];  // 0x044
    u32 m_field_0F0;  // 0x0F0 [R] (Draw)
    u8 _pad_0F4[0x4E74];  // 0x0F4
    f32 m_field_4F68;  // 0x4F68 [R] (Draw)
    u8 _pad_4F6C[8];  // 0x4F6C
    f32 m_field_4F74;  // 0x4F74 [R] (Draw)
};

#endif // SCROLLINGTEXTBOX_H
