#ifndef FLOWGOTOTARGET_H
#define FLOWGOTOTARGET_H

#include "types.h"

// FlowGotoTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8C (140 bytes)
// 21 known fields (5 named), 14 methods

class FlowGotoTarget {
public:
    // Constructors / Destructors
    FlowGotoTarget(void)  // 0x804875D0
    ~FlowGotoTarget(void);  // 0x80487838

    // Methods
    bool IsStateRequestPending(void);  // 0x80488828 (64B)
    /* ? */ GetStateRequest(void);  // 0x80488868 (44B)
    void SetPendingStateCurrent(void);  // 0x80488894 (40B)
    void SetVariable(char *, char *);  // 0x8048789C (2432B)
    /* ? */ GetVariable(char *);  // 0x8048821C (264B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_variable;  // 0x000 [R/W] (FlowGotoTarget, GetVariable, ~FlowGotoTarget)
    u8 _pad_001[3];  // 0x001
    u16 m_variable_004;  // 0x004 [R/W] (FlowGotoTarget, GetVariable, ~FlowGotoTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (FlowGotoTarget, ~FlowGotoTarget)
    u32 m_field_00C;  // 0x00C [R/W] (FlowGotoTarget, ~FlowGotoTarget)
    u32 m_field_010;  // 0x010 [R/W] (FlowGotoTarget, ~FlowGotoTarget)
    u32 m_field_014;  // 0x014 [R/W] (FlowGotoTarget, ~FlowGotoTarget)
    u32 m_field_018;  // 0x018 [R/W] (FlowGotoTarget, ~FlowGotoTarget)
    u32 m_field_01C;  // 0x01C [R/W] (FlowGotoTarget, ~FlowGotoTarget)
    u32 m_field_020;  // 0x020 [R/W] (FlowGotoTarget, ~FlowGotoTarget)
    u32 m_field_024;  // 0x024 [R/W] (FlowGotoTarget, ~FlowGotoTarget)
    u32 m_field_028;  // 0x028 [W] (FlowGotoTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (FlowGotoTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (FlowGotoTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (FlowGotoTarget, ~FlowGotoTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (FlowGotoTarget, ~FlowGotoTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (FlowGotoTarget)
    u32 m_field_07C;  // 0x07C [R/W] (FlowGotoTarget, ~FlowGotoTarget)
    u32 m_field_080;  // 0x080 [W] (FlowGotoTarget, ~FlowGotoTarget)
    u32 m_variable_084;  // 0x084 [R/W] (FlowGotoTarget, GetVariable, SetVariable)
    u32 m_variable_088;  // 0x088 [R/W] (FlowGotoTarget, GetVariable)
};

#endif // FLOWGOTOTARGET_H
