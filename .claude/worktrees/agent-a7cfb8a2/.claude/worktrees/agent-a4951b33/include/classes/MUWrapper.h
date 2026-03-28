#ifndef MUWRAPPER_H
#define MUWRAPPER_H

#include "types.h"

// MUWrapper - struct layout extracted from assembly analysis
// Estimated minimum size: 0x118 (280 bytes)
// 53 known fields (20 named), 48 methods

class MUWrapper {
public:
    // Constructors / Destructors
    MUWrapper(void)  // 0x80194034
    ~MUWrapper(void);  // 0x80194100

    // Methods
    void Startup(void);  // 0x8018A7E4 (908B)
    void Shutdown(void);  // 0x8018AB70 (388B)
    void Reset(void);  // 0x8018ACF4 (6900B)
    /* ? */ GetFont(void);  // 0x801941A4 (44B)
    void ResetSlotSelection(bool);  // 0x8018C838 (1152B)
    void SetupDisplayOkType(void);  // 0x8018F308 (2932B)
    void SetupQueryType(void);  // 0x8018FE7C (1880B)
    void SetupInfoType(void);  // 0x801905D4 (1552B)
    void HideDialog(void);  // 0x8018D9F8 (412B)
    void ShowDialog(void);  // 0x8018D6BC (828B)
    void ShowMenu(void);  // 0x8018D604 (92B)
    void HideMenu(void);  // 0x8018D660 (92B)
    void CleanUp(void);  // 0x8018C7E8 (80B)
    void Update(void);  // 0x8018CCB8 (1636B)
    void Draw(ERC *);  // 0x8018D31C (744B)
    void SetVariable(char *, char *);  // 0x8018DB94 (604B)
    /* ? */ GetVariable(char *);  // 0x8018DDF0 (5220B)
    void SetDisplayOkType(MUStateMachine::eMUDisplayOk);  // 0x8018F254 (60B)
    void SetQueryType(MUStateMachine::eMUQuery);  // 0x8018F290 (60B)
    void SetInfoType(MUStateMachine::eMUInfo);  // 0x8018F2CC (60B)
    void SetScreenConfiguration(MUWrapper::eMUScreenConfiguration);  // 0x80194154 (40B)
    void SetBackgroundDrawEnable(bool);  // 0x8019417C (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetVariable, Startup)
    u32 m_variable_004;  // 0x004 [R/W] (Draw, GetVariable, Reset, ...)
    u32 m_field_008;  // 0x008 [R/W] (ResetSlotSelection, Startup)
    f32 m_field_00C;  // 0x00C [W] (Startup)
    f32 m_field_010;  // 0x010 [W] (Startup)
    f32 m_field_014;  // 0x014 [W] (Startup)
    f32 m_field_018;  // 0x018 [W] (Startup)
    f32 m_variable_01C;  // 0x01C [R/W] (GetVariable, Reset, ResetSlotSelection, ...)
    f32 m_field_020;  // 0x020 [W] (Startup)
    f32 m_field_024;  // 0x024 [W] (Startup)
    f32 m_field_028;  // 0x028 [W] (Startup)
    f32 m_field_02C;  // 0x02C [W] (Startup)
    f32 m_field_030;  // 0x030 [W] (Startup)
    u32 m_field_034;  // 0x034 [W] (Startup)
    u32 m_field_038;  // 0x038 [W] (Startup)
    u32 m_field_03C;  // 0x03C [W] (Startup)
    u8 m_variable_03F;  // 0x03F [W] (GetVariable)
    u8 _pad_040[0x1C];  // 0x040
    u32 m_field_05C;  // 0x05C [W] (Startup)
    u32 m_field_060;  // 0x060 [W] (Startup)
    u32 m_field_064;  // 0x064 [W] (Startup)
    f32 m_field_068;  // 0x068 [W] (Startup)
    u32 m_field_06C;  // 0x06C [W] (Startup)
    u8 _pad_070[0x10];  // 0x070
    u32 m_field_080;  // 0x080 [W] (~MUWrapper)
    u8 _pad_084[8];  // 0x084
    u32 m_field_08C;  // 0x08C [R] (~MUWrapper)
    u8 _pad_090[0x14];  // 0x090
    u32 m_field_0A4;  // 0x0A4 [R/W] (Reset, ResetSlotSelection, Shutdown, ...)
    u32 m_variable_0A8;  // 0x0A8 [R/W] (Draw, GetVariable, HideDialog, ...)
    u32 m_variable_0AC;  // 0x0AC [R/W] (GetVariable, Reset, ResetSlotSelection, ...)
    u32 m_variable_0B0;  // 0x0B0 [R/W] (GetVariable, Reset, ResetSlotSelection, ...)
    u32 m_upDisplayOkType;  // 0x0B4 [R] (Draw, Reset, SetupDisplayOkType, ...)
    u32 m_upQueryType;  // 0x0B8 [R] (SetupQueryType)
    u32 m_upInfoType;  // 0x0BC [R] (SetupInfoType)
    u32 m_field_0C0;  // 0x0C0 [R/W] (HideDialog, ShowDialog)
    u32 m_field_0C4;  // 0x0C4 [R/W] (HideMenu, ShowMenu)
    u32 m_field_0C8;  // 0x0C8 [R/W] (Draw, Startup)
    u32 m_variable_0CC;  // 0x0CC [R/W] (ResetSlotSelection, SetVariable, Startup)
    u32 m_variable_0D0;  // 0x0D0 [R/W] (SetVariable, Startup)
    f32 m_variable_0D4;  // 0x0D4 [R/W] (ResetSlotSelection, SetVariable, Startup)
    f32 m_variable_0D8;  // 0x0D8 [W] (SetVariable)
    f32 m_variable_0DC;  // 0x0DC [R/W] (ResetSlotSelection, SetVariable, Startup)
    f32 m_variable_0E0;  // 0x0E0 [R/W] (ResetSlotSelection, SetVariable)
    f32 m_variable_0E4;  // 0x0E4 [R/W] (GetVariable, Reset, Startup)
    f32 m_variable_0E8;  // 0x0E8 [R] (GetVariable, Reset)
    f32 m_variable_0EC;  // 0x0EC [R/W] (GetVariable, Reset, Startup)
    f32 m_variable_0F0;  // 0x0F0 [R/W] (GetVariable, Reset)
    u32 m_field_0F4;  // 0x0F4 [R/W] (Reset)
    u32 m_field_0F8;  // 0x0F8 [R/W] (Reset)
    u32 m_field_0FC;  // 0x0FC [R/W] (Reset)
    u32 m_field_100;  // 0x100 [R/W] (Reset)
    u32 m_field_104;  // 0x104 [W] (Reset)
    u32 m_field_108;  // 0x108 [R/W] (Draw, HideDialog, Reset, ...)
    u32 m_field_10C;  // 0x10C [R/W] (Draw, HideDialog, Reset, ...)
    u32 m_field_110;  // 0x110 [R/W] (Draw, HideDialog, Reset, ...)
    u32 m_field_114;  // 0x114 [R/W] (Draw, HideDialog, Reset, ...)
};

#endif // MUWRAPPER_H
