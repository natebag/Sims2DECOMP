#ifndef G2DTARGET_H
#define G2DTARGET_H

#include "types.h"

// G2DTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0xDE0 (3552 bytes)
// 72 known fields (40 named), 58 methods

class G2DTarget {
public:
    // Constructors / Destructors
    G2DTarget(void)  // 0x8050030C
    ~G2DTarget(void);  // 0x80500810

    // Methods
    bool IsG2DActive(void);  // 0x80501CF8 (44B)
    void ServiceG2DShutdown(void);  // 0x80503E74 (184B)
    bool HasPendingTransition(void);  // 0x8054FF30 (72B)
    void PopAptButtonFilters(void);  // 0x80501E18 (184B)
    /* ? */ GetVariable(char *);  // 0x80500900 (1016B)
    void PushAptButtonFilters(void);  // 0x80501D50 (72B)
    void SetupWidgets(void);  // 0x80502788 (2112B)
    /* ? */ GetLocalizable(char *);  // 0x80500CF8 (1072B)
    void SetVariable(char *, char *);  // 0x80501128 (1140B)
    void CheckPlayerInput(char *);  // 0x80503DC4 (176B)
    void HideDialogRunCallbacks(void);  // 0x80501CA0 (88B)
    void ReflowButtonSelection(void);  // 0x8050159C (972B)
    void ExecuteZeroInputCallback(void);  // 0x80503288 (192B)
    void UnloadUI(void);  // 0x80503CF8 (204B)
    void Update(void);  // 0x80501968 (700B)
    void UnloadDialog(void);  // 0x80502FC8 (428B)
    void ExecuteSelectionCallback(int);  // 0x8050322C (92B)
    void SpawnDialog(UIDialog *);  // 0x80501ED0 (1116B)
    void ExecuteDialogClosedCallback(void);  // 0x80503348 (164B)
    void SetupDialogData(UIDialog *);  // 0x805034F8 (2048B)
    void CalculateBackgroundSize(void);  // 0x8050232C (1116B)
    void HideDialog(void);  // 0x80501C24 (124B)
    bool IsG2DSpawned(void);  // 0x80501D24 (44B)
    void PushAptButtonFiltersForPlayer(int);  // 0x80501D98 (128B)
    void SetIcon(ERShader *, short, short);  // 0x80503174 (184B)
    void ChangeContinueType(int);  // 0x805033EC (268B)
    bool IsInitComplete(void);  // 0x8054FF04 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (CalculateBackgroundSize, G2DTarget, GetLocalizable, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (G2DTarget, GetVariable, ~G2DTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (G2DTarget, ~G2DTarget)
    u32 m_field_00C;  // 0x00C [R/W] (CalculateBackgroundSize, G2DTarget, ~G2DTarget)
    u32 m_field_010;  // 0x010 [R/W] (G2DTarget, SpawnDialog, UnloadDialog, ...)
    u32 m_field_014;  // 0x014 [R/W] (G2DTarget, ~G2DTarget)
    u32 m_field_018;  // 0x018 [R/W] (G2DTarget, ~G2DTarget)
    u32 m_icon;  // 0x01C [R/W] (G2DTarget, SetIcon, SetupDialogData, ...)
    u32 m_field_020;  // 0x020 [R/W] (G2DTarget, ~G2DTarget)
    u32 m_field_024;  // 0x024 [R/W] (G2DTarget, ~G2DTarget)
    u32 m_field_028;  // 0x028 [W] (G2DTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (G2DTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (G2DTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (G2DTarget, SpawnDialog, UnloadDialog, ...)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (G2DTarget, ~G2DTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (G2DTarget)
    u32 m_icon_07C;  // 0x07C [R/W] (G2DTarget, PushAptButtonFiltersForPlayer, SetIcon, ...)
    u32 m_field_080;  // 0x080 [W] (G2DTarget, ~G2DTarget)
    u32 m_field_084;  // 0x084 [W] (G2DTarget, SpawnDialog, UnloadDialog)
    u32 m_variable_088;  // 0x088 [R/W] (G2DTarget, GetVariable, UnloadDialog, ...)
    u32 m_variable_08C;  // 0x08C [W] (G2DTarget, GetVariable, SetVariable, ...)
    u32 m_field_090;  // 0x090 [R/W] (G2DTarget, Update)
    u32 m_field_094;  // 0x094 [R/W] (G2DTarget, Update)
    u32 m_field_098;  // 0x098 [R/W] (G2DTarget, ServiceG2DShutdown, SpawnDialog, ...)
    u32 m_upDialogData;  // 0x09C [R/W] (CheckPlayerInput, SetupDialogData)
    u32 m_upDialogData_0A0;  // 0x0A0 [W] (G2DTarget, SetupDialogData)
    u32 m_variable_0A4;  // 0x0A4 [R/W] (CalculateBackgroundSize, ChangeContinueType, CheckPlayerInput, ...)
    u32 m_upDialogData_0A8;  // 0x0A8 [R/W] (SetupDialogData, SpawnDialog)
    u32 m_upDialogData_0AC;  // 0x0AC [R/W] (ChangeContinueType, G2DTarget, SetupDialogData)
    u32 m_upWidgets;  // 0x0B0 [R/W] (G2DTarget, ReflowButtonSelection, SetVariable, ...)
    u32 m_upDialogData_0B4;  // 0x0B4 [W] (G2DTarget, SetupDialogData)
    u32 m_upDialogData_0B8;  // 0x0B8 [R/W] (G2DTarget, SetupDialogData, Update)
    u32 m_upDialogData_0BC;  // 0x0BC [R/W] (G2DTarget, SetupDialogData, Update)
    u32 m_variable_0C0;  // 0x0C0 [R/W] (G2DTarget, SetVariable, SetupDialogData)
    u32 m_upDialogData_0C4;  // 0x0C4 [R/W] (ExecuteDialogClosedCallback, G2DTarget, HideDialog, ...)
    u32 m_upDialogData_0C8;  // 0x0C8 [R/W] (G2DTarget, ReflowButtonSelection, SetVariable, ...)
    u32 m_upDialogData_0CC;  // 0x0CC [R/W] (CalculateBackgroundSize, G2DTarget, SetupDialogData, ...)
    s16 m_upDialogData_0D0;  // 0x0D0 [R/W] (CalculateBackgroundSize, G2DTarget, SetIcon, ...)
    s16 m_upDialogData_0D2;  // 0x0D2 [R/W] (CalculateBackgroundSize, G2DTarget, SetIcon, ...)
    u32 m_variable_0D4;  // 0x0D4 [R/W] (CalculateBackgroundSize, G2DTarget, GetVariable, ...)
    u32 m_variable_0D8;  // 0x0D8 [R/W] (CalculateBackgroundSize, G2DTarget, GetVariable)
    f32 m_upWidgets_0DC;  // 0x0DC [R/W] (CalculateBackgroundSize, SetupWidgets)
    f32 m_field_0E0;  // 0x0E0 [R/W] (CalculateBackgroundSize)
    f32 m_upWidgets_0E4;  // 0x0E4 [R/W] (CalculateBackgroundSize, SetupWidgets)
    f32 m_upWidgets_0E8;  // 0x0E8 [R/W] (CalculateBackgroundSize, SetupWidgets)
    f32 m_upWidgets_0EC;  // 0x0EC [R/W] (CalculateBackgroundSize, SetupWidgets)
    f32 m_upWidgets_0F0;  // 0x0F0 [R/W] (CalculateBackgroundSize, SetupWidgets)
    f32 m_upWidgets_0F4;  // 0x0F4 [R/W] (CalculateBackgroundSize, SetupWidgets)
    f32 m_upWidgets_0F8;  // 0x0F8 [R/W] (CalculateBackgroundSize, SetupWidgets)
    u8 _pad_0FC[0x14];  // 0x0FC
    u32 m_upDialogData_110;  // 0x110 [R/W] (ExecuteSelectionCallback, HideDialog, SetupDialogData, ...)
    u32 m_upDialogData_114;  // 0x114 [R/W] (ExecuteZeroInputCallback, HideDialog, SetupDialogData, ...)
    u32 m_upDialogData_118;  // 0x118 [R/W] (ExecuteDialogClosedCallback, HideDialog, SetupDialogData, ...)
    u32 m_upDialogData_11C;  // 0x11C [R/W] (G2DTarget, SetupDialogData)
    u32 m_field_120;  // 0x120 [W] (G2DTarget)
    u32 m_field_124;  // 0x124 [W] (G2DTarget)
    f32 m_variable_128;  // 0x128 [R/W] (SetVariable, SpawnDialog)
    f32 m_variable_12C;  // 0x12C [R/W] (G2DTarget, SetVariable, SpawnDialog, ...)
    u32 m_upDialogData_130;  // 0x130 [R/W] (G2DTarget, SetupDialogData, Update)
    u32 m_variable_134;  // 0x134 [R/W] (G2DTarget, GetVariable, HideDialog, ...)
    u8 _pad_138[0x14];  // 0x138
    u32 m_variable_14C;  // 0x14C [R/W] (GetVariable, UnloadDialog)
    u32 m_field_150;  // 0x150 [R/W] (ReflowButtonSelection)
    u32 m_field_154;  // 0x154 [R/W] (ReflowButtonSelection)
    u32 m_field_158;  // 0x158 [R/W] (ReflowButtonSelection)
    u32 m_field_15C;  // 0x15C [R/W] (ReflowButtonSelection)
    u32 m_field_160;  // 0x160 [R/W] (ReflowButtonSelection)
    u32 m_field_164;  // 0x164 [R/W] (ReflowButtonSelection)
    u32 m_field_168;  // 0x168 [R/W] (ReflowButtonSelection)
    u32 m_field_16C;  // 0x16C [R/W] (ReflowButtonSelection)
    u32 m_field_170;  // 0x170 [R/W] (ReflowButtonSelection)
    u8 _pad_174[0xC58];  // 0x174
    f32 m_field_DCC;  // 0xDCC [R] (CalculateBackgroundSize)
    u8 _pad_DD0[8];  // 0xDD0
    f64 m_field_DD8;  // 0xDD8 [R] (CalculateBackgroundSize)
};

#endif // G2DTARGET_H
