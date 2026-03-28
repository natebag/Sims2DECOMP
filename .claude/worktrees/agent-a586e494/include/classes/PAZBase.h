#ifndef PAZBASE_H
#define PAZBASE_H

#include "types.h"

// PAZBase - struct layout extracted from assembly analysis
// Estimated minimum size: 0xBC (188 bytes)
// 27 known fields (14 named), 20 methods

class PAZBase {
public:
    // Constructors / Destructors
    PAZBase(void)  // 0x80525E40
    ~PAZBase(void);  // 0x80525ED4

    // Methods
    /* ? */ GetPausePlayer(void);  // 0x80527024 (44B)
    void SetVariable(char *, char *);  // 0x80525F84 (2700B)
    void on_user_set_selection_index(int);  // 0x8052731C (444B)
    void UpdateButtonVisibility(void);  // 0x80527050 (32B)
    /* ? */ GetVariable(char *);  // 0x80526A10 (852B)
    /* ? */ GetLocalizable(char *);  // 0x80526D64 (672B)
    void Update(void);  // 0x80527004 (32B)
    void ConfigureAndLoad(int, char **, PAZItemInfo *, unsigned int);  // 0x80527070 (684B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_variable;  // 0x000 [R/W] (ConfigureAndLoad, GetVariable, SetVariable, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable_004;  // 0x004 [R/W] (ConfigureAndLoad, GetVariable, ~PAZBase)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R] (ConfigureAndLoad, ~PAZBase)
    u32 m_field_00C;  // 0x00C [R] (ConfigureAndLoad, ~PAZBase)
    u32 m_field_010;  // 0x010 [R] (ConfigureAndLoad, ~PAZBase)
    u32 m_field_014;  // 0x014 [R] (~PAZBase)
    u32 m_field_018;  // 0x018 [R] (~PAZBase)
    u32 m_variable_01C;  // 0x01C [R] (SetVariable, ~PAZBase)
    u32 m_field_020;  // 0x020 [R] (~PAZBase)
    u32 m_field_024;  // 0x024 [R] (~PAZBase)
    u8 _pad_028[0x30];  // 0x028
    u32 m_field_058;  // 0x058 [R] (ConfigureAndLoad, ~PAZBase)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R] (~PAZBase)
    u8 _pad_06C[0x10];  // 0x06C
    u32 m_variable_07C;  // 0x07C [R] (ConfigureAndLoad, SetVariable, ~PAZBase)
    u32 m_variable_080;  // 0x080 [R/W] (ConfigureAndLoad, SetVariable, on_user_set_selection_index, ...)
    u32 m_variable_084;  // 0x084 [R] (ConfigureAndLoad, SetVariable)
    u32 m_variable_088;  // 0x088 [W] (SetVariable)
    u32 m_variable_08C;  // 0x08C [R/W] (GetLocalizable, GetVariable, SetVariable)
    u32 m_field_090;  // 0x090 [R/W] (on_user_set_selection_index)
    u8 _pad_094[4];  // 0x094
    u32 m_variable_098;  // 0x098 [R/W] (SetVariable, on_user_set_selection_index)
    u8 _pad_09C[4];  // 0x09C
    u32 m_variable_0A0;  // 0x0A0 [R/W] (SetVariable)
    u32 m_field_0A4;  // 0x0A4 [R/W] (ConfigureAndLoad, ~PAZBase)
    u32 m_localizable;  // 0x0A8 [R/W] (ConfigureAndLoad, GetLocalizable, SetVariable)
    u32 m_variable_0AC;  // 0x0AC [R/W] (ConfigureAndLoad, GetVariable, SetVariable, ...)
    u32 m_localizable_0B0;  // 0x0B0 [R/W] (ConfigureAndLoad, GetLocalizable, GetVariable, ...)
    u32 m_field_0B4;  // 0x0B4 [R/W] (ConfigureAndLoad, ~PAZBase)
    u32 m_field_0B8;  // 0x0B8 [R/W] (ConfigureAndLoad, ~PAZBase)
};

#endif // PAZBASE_H
