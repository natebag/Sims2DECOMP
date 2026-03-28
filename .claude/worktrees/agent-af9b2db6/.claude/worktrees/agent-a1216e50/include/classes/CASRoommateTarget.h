#ifndef CASROOMMATETARGET_H
#define CASROOMMATETARGET_H

#include "types.h"

// CASRoommateTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x134C (4940 bytes)
// 29 known fields (5 named), 22 methods

class CASRoommateTarget {
public:
    // Constructors / Destructors
    CASRoommateTarget(void)  // 0x804D9048
    ~CASRoommateTarget(void);  // 0x804D9380

    // Methods
    /* ? */ GetLocalizableSubnav(int, unsigned wchar_t *);  // 0x804D98EC (416B)
    void SetVariableSubnav(int, int);  // 0x804D9730 (444B)
    /* ? */ GetSelectedSlot(void);  // 0x804DF95C (44B)
    void SetButtonState(void);  // 0x804D9C78 (100B)
    void SetVariable(char *, char *);  // 0x804D9414 (796B)
    void SelectFirstNonEmptySlot(void);  // 0x804D9B8C (236B)
    /* ? */ GetVariable(char *);  // 0x804D9A8C (256B)
    /* ? */ GetButtonStateString(char *);  // 0x804D9CDC (432B)
    void Draw(ERC *);  // 0x804D9E8C (500B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_variable;  // 0x000 [R/W] (CASRoommateTarget, GetVariable, ~CASRoommateTarget)
    u8 _pad_001[3];  // 0x001
    u32 m_field_004;  // 0x004 [R/W] (CASRoommateTarget, Draw, ~CASRoommateTarget)
    u32 m_field_008;  // 0x008 [R/W] (CASRoommateTarget, Draw, ~CASRoommateTarget)
    u32 m_field_00C;  // 0x00C [R/W] (CASRoommateTarget, ~CASRoommateTarget)
    u32 m_field_010;  // 0x010 [R/W] (CASRoommateTarget, ~CASRoommateTarget)
    u32 m_field_014;  // 0x014 [R/W] (CASRoommateTarget, ~CASRoommateTarget)
    u32 m_field_018;  // 0x018 [R/W] (CASRoommateTarget, ~CASRoommateTarget)
    u32 m_field_01C;  // 0x01C [R/W] (CASRoommateTarget, ~CASRoommateTarget)
    u32 m_field_020;  // 0x020 [R/W] (CASRoommateTarget, ~CASRoommateTarget)
    u32 m_field_024;  // 0x024 [R/W] (CASRoommateTarget, ~CASRoommateTarget)
    u32 m_field_028;  // 0x028 [W] (CASRoommateTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (CASRoommateTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (CASRoommateTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (CASRoommateTarget, ~CASRoommateTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (CASRoommateTarget, ~CASRoommateTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (CASRoommateTarget)
    u32 m_field_07C;  // 0x07C [R/W] (CASRoommateTarget, ~CASRoommateTarget)
    u32 m_field_080;  // 0x080 [W] (CASRoommateTarget, ~CASRoommateTarget)
    u32 m_buttonStateString;  // 0x084 [R/W] (CASRoommateTarget, Draw, GetButtonStateString, ...)
    u32 m_field_088;  // 0x088 [W] (CASRoommateTarget, ~CASRoommateTarget)
    u32 m_variable_08C;  // 0x08C [R/W] (CASRoommateTarget, Draw, SetVariable, ...)
    u32 m_variableSubnav;  // 0x090 [R/W] (CASRoommateTarget, Draw, SelectFirstNonEmptySlot, ...)
    u32 m_field_094;  // 0x094 [R/W] (CASRoommateTarget, Draw, ~CASRoommateTarget)
    u32 m_field_098;  // 0x098 [W] (Draw)
    u8 _pad_09C[0xC];  // 0x09C
    f32 m_field_0A8;  // 0x0A8 [R/W] (Draw)
    u8 _pad_0AC[8];  // 0x0AC
    u32 m_field_0B4;  // 0x0B4 [W] (Draw)
    u8 _pad_0B8[0xD0];  // 0x0B8
    u32 m_field_188;  // 0x188 [R/W] (Draw)
    u32 m_field_18C;  // 0x18C [W] (Draw)
    u8 _pad_190[0x11B8];  // 0x190
    u32 m_buttonStateString_1348;  // 0x1348 [R] (GetButtonStateString)
};

#endif // CASROOMMATETARGET_H
