#ifndef M2MTARGET_H
#define M2MTARGET_H

#include "types.h"

// M2MTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x23E8 (9192 bytes)
// 69 known fields (26 named), 96 methods

class M2MTarget {
public:
    // Constructors / Destructors
    M2MTarget(void)  // 0x8050F91C
    ~M2MTarget(void);  // 0x80510250

    // Methods
    void SetDevice(int);  // 0x8051290C (76B)
    void HideWidget(void);  // 0x805141C4 (208B)
    /* ? */ GetDevice(void);  // 0x805128E0 (44B)
    /* ? */ GetPlayerNum(void);  // 0x80550844 (44B)
    /* ? */ GetSaveGameID(void);  // 0x80512958 (44B)
    void PushButtonFilters(void);  // 0x805154C8 (152B)
    void StartNGCMemoryCardBootChecks(void);  // 0x80513D2C (200B)
    void SpawnSaveBeforeQuitCASDialog(void);  // 0x80512F38 (452B)
    void SpawnSaveBeforeQuitGameDialog(void);  // 0x805130FC (452B)
    void SpawnNoSaveBeforeQuitDialog(void);  // 0x805132C0 (408B)
    void UnloadDialog(void);  // 0x80515254 (364B)
    /* ? */ GetVariable(char *);  // 0x805103C4 (756B)
    /* ? */ GetLocalizable(char *);  // 0x805106B8 (1420B)
    /* ? */ GetItemTextMemCardSelect(int, unsigned wchar_t *);  // 0x805135F0 (440B)
    /* ? */ GetItemTextSaveGameSelect(int, unsigned wchar_t *);  // 0x805137A8 (144B)
    void SetVariable(char *, char *);  // 0x80510C44 (756B)
    bool IsItemEnabled(int);  // 0x80514AF4 (276B)
    void OnSlotSelectItemSelected(int, M2MTarget::ResultStruct &);  // 0x805125A8 (584B)
    void UpdateSelection(int);  // 0x80514A34 (192B)
    void OnCancel(void);  // 0x80511F4C (360B)
    void ReflowButtonSelection(void);  // 0x80510F38 (676B)
    void Update(void);  // 0x805111DC (1484B)
    void UpdateWidgetState(void);  // 0x80513DF4 (692B)
    void SpawnContinueNoMemCardDialog(void);  // 0x80512D84 (436B)
    void PrepareNewGame(void);  // 0x805153C0 (96B)
    void PrepareLoadGame(void);  // 0x80515420 (168B)
    void SpawnNoSpaceDialog(void);  // 0x80512A48 (420B)
    void SpawnConfirmStartNewGameDialog(void);  // 0x80512BEC (408B)
    void StartLoadedGame(void);  // 0x80513B10 (140B)
    void DoesMemoryDeviceExist(void);  // 0x8051398C (388B)
    void OnSaveLoadSucceed(void);  // 0x805120B4 (596B)
    void OnSaveLoadFailed(void);  // 0x80512308 (672B)
    void ReturnFailureDestination(void);  // 0x80513B9C (400B)
    void SelectionCallback(int);  // 0x805117A8 (1784B)
    void ZeroInputCallback(void);  // 0x80511EA0 (40B)
    void DialogClosedCallback(void);  // 0x80511EC8 (132B)
    /* ? */ GetMemCardPort(void);  // 0x80512984 (196B)
    void SpawnStartNGCNoMemCardDialog(void);  // 0x80513458 (408B)
    void OnGetNumItems(M2MTarget::ResultStruct &);  // 0x805127F0 (240B)
    bool IsItemEnabledMemCardSelect(int);  // 0x80513838 (284B)
    bool IsItemEnabledSaveGameSelect(int);  // 0x80513954 (56B)
    void FillWidget(void);  // 0x805140A8 (284B)
    void SetCurrState(M2MTarget::WidgetState);  // 0x80514C68 (1516B)
    void CalcNumItems(void);  // 0x80514C08 (96B)
    void SetupWidgetLayout(void);  // 0x80514294 (1952B)
    void PopButtonFilters(void);  // 0x80515560 (120B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (GetLocalizable, GetVariable, M2MTarget, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (GetVariable, M2MTarget, ~M2MTarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (M2MTarget, ~M2MTarget)
    u32 m_upWidgetLayout;  // 0x00C [R/W] (M2MTarget, SetupWidgetLayout, ~M2MTarget)
    u32 m_field_010;  // 0x010 [R/W] (M2MTarget, ~M2MTarget)
    u32 m_field_014;  // 0x014 [R/W] (M2MTarget, ~M2MTarget)
    u32 m_field_018;  // 0x018 [R/W] (M2MTarget, ~M2MTarget)
    u32 m_field_01C;  // 0x01C [R/W] (M2MTarget, ~M2MTarget)
    u32 m_field_020;  // 0x020 [R/W] (M2MTarget, ~M2MTarget)
    u32 m_field_024;  // 0x024 [R/W] (M2MTarget, ~M2MTarget)
    u32 m_field_028;  // 0x028 [W] (M2MTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (M2MTarget)
    u32 m_field_03C;  // 0x03C [W] (M2MTarget)
    u32 m_field_040;  // 0x040 [W] (M2MTarget)
    u32 m_field_044;  // 0x044 [W] (M2MTarget)
    u16 m_field_048;  // 0x048 [W] (M2MTarget)
    u16 m_field_04A;  // 0x04A [W] (M2MTarget)
    u32 m_field_04C;  // 0x04C [W] (M2MTarget)
    u8 _pad_050[8];  // 0x050
    u32 m_field_058;  // 0x058 [R/W] (M2MTarget, ~M2MTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (M2MTarget, ~M2MTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (M2MTarget)
    u32 m_field_07C;  // 0x07C [R/W] (M2MTarget, PushButtonFilters, ~M2MTarget)
    u32 m_upWidgetLayout_080;  // 0x080 [R/W] (M2MTarget, SetupWidgetLayout, ~M2MTarget)
    u32 m_field_084;  // 0x084 [W] (M2MTarget, SpawnConfirmStartNewGameDialog, SpawnContinueNoMemCardDialog, ...)
    u32 m_field_088;  // 0x088 [W] (SpawnConfirmStartNewGameDialog, SpawnContinueNoMemCardDialog, SpawnNoSaveBeforeQuitDialog, ...)
    u32 m_field_08C;  // 0x08C [W] (SpawnConfirmStartNewGameDialog, SpawnContinueNoMemCardDialog, SpawnNoSaveBeforeQuitDialog, ...)
    u32 m_field_090;  // 0x090 [W] (SpawnConfirmStartNewGameDialog, SpawnContinueNoMemCardDialog, SpawnNoSaveBeforeQuitDialog, ...)
    u32 m_field_094;  // 0x094 [W] (SpawnConfirmStartNewGameDialog, SpawnContinueNoMemCardDialog, SpawnNoSaveBeforeQuitDialog, ...)
    u32 m_field_098;  // 0x098 [W] (SpawnConfirmStartNewGameDialog, SpawnContinueNoMemCardDialog, SpawnNoSaveBeforeQuitDialog, ...)
    u8 _pad_09C[4];  // 0x09C
    u32 m_field_0A0;  // 0x0A0 [W] (SpawnConfirmStartNewGameDialog, SpawnContinueNoMemCardDialog, SpawnNoSaveBeforeQuitDialog, ...)
    u32 m_field_0A4;  // 0x0A4 [W] (SpawnConfirmStartNewGameDialog, SpawnContinueNoMemCardDialog, SpawnNoSaveBeforeQuitDialog, ...)
    u8 _pad_0A8[0x18];  // 0x0A8
    u32 m_field_0C0;  // 0x0C0 [W] (SpawnConfirmStartNewGameDialog, SpawnContinueNoMemCardDialog, SpawnNoSaveBeforeQuitDialog, ...)
    u8 _pad_0C4[8];  // 0x0C4
    u16 m_field_0CC;  // 0x0CC [W] (SpawnConfirmStartNewGameDialog, SpawnContinueNoMemCardDialog, SpawnNoSaveBeforeQuitDialog, ...)
    u16 m_field_0CE;  // 0x0CE [W] (SpawnConfirmStartNewGameDialog, SpawnContinueNoMemCardDialog, SpawnNoSaveBeforeQuitDialog, ...)
    u32 m_field_0D0;  // 0x0D0 [W] (SpawnConfirmStartNewGameDialog, SpawnContinueNoMemCardDialog, SpawnNoSaveBeforeQuitDialog, ...)
    u32 m_field_0D4;  // 0x0D4 [W] (M2MTarget)
    u8 _pad_0D8[0xC];  // 0x0D8
    u32 m_field_0E4;  // 0x0E4 [W] (M2MTarget)
    u8 _pad_0E8[0xC];  // 0x0E8
    u32 m_field_0F4;  // 0x0F4 [W] (M2MTarget)
    u8 _pad_0F8[0xC];  // 0x0F8
    u32 m_field_104;  // 0x104 [W] (M2MTarget)
    u32 m_field_108;  // 0x108 [W] (M2MTarget, ~M2MTarget)
    u32 m_localizable_10C;  // 0x10C [R/W] (GetLocalizable, IsItemEnabled, M2MTarget, ...)
    u32 m_localizable_110;  // 0x110 [R/W] (GetLocalizable, IsItemEnabled, OnCancel, ...)
    u32 m_field_114;  // 0x114 [R] (StartLoadedGame)
    u32 m_currState;  // 0x118 [R/W] (M2MTarget, OnSaveLoadFailed, OnSaveLoadSucceed, ...)
    u32 m_localizable_11C;  // 0x11C [R/W] (DialogClosedCallback, GetLocalizable, M2MTarget, ...)
    u8 _pad_120[0x38];  // 0x120
    u32 m_field_158;  // 0x158 [R/W] (OnSaveLoadFailed, StartNGCMemoryCardBootChecks)
    u32 m_field_15C;  // 0x15C [R/W] (OnSaveLoadFailed, StartNGCMemoryCardBootChecks)
    u32 m_variable_160;  // 0x160 [R/W] (GetVariable, M2MTarget, SetupWidgetLayout)
    u32 m_variable_164;  // 0x164 [R/W] (GetVariable, M2MTarget, SetupWidgetLayout)
    u32 m_localizable_168;  // 0x168 [R/W] (CalcNumItems, DialogClosedCallback, GetLocalizable, ...)
    u32 m_widgetState;  // 0x16C [R/W] (M2MTarget, Update, UpdateWidgetState)
    u32 m_field_170;  // 0x170 [R/W] (PopButtonFilters, PushButtonFilters)
    u32 m_field_174;  // 0x174 [R/W] (PopButtonFilters, PushButtonFilters)
    u32 m_bIsItemEnabledMemCardSelect;  // 0x178 [R/W] (IsItemEnabledMemCardSelect, M2MTarget, Update)
    u32 m_bIsItemEnabledMemCardSelect_17C;  // 0x17C [R/W] (IsItemEnabledMemCardSelect, M2MTarget, Update)
    u32 m_field_180;  // 0x180 [R/W] (M2MTarget, OnCancel, OnSaveLoadFailed, ...)
    u32 m_variable_184;  // 0x184 [R/W] (M2MTarget, SetCurrState, SetVariable, ...)
    u32 m_upWidgetLayout_188;  // 0x188 [R/W] (CalcNumItems, FillWidget, M2MTarget, ...)
    u32 m_variable_18C;  // 0x18C [R/W] (FillWidget, M2MTarget, ReflowButtonSelection, ...)
    u32 m_field_190;  // 0x190 [R/W] (M2MTarget, PushButtonFilters, SpawnConfirmStartNewGameDialog, ...)
    u32 m_currState_194;  // 0x194 [R/W] (M2MTarget, SetCurrState)
    u8 _pad_198[0x220C];  // 0x198
    f32 m_upWidgetLayout_23A4;  // 0x23A4 [R] (SetupWidgetLayout)
    f32 m_upWidgetLayout_23A8;  // 0x23A8 [R] (SetupWidgetLayout)
    f32 m_upWidgetLayout_23AC;  // 0x23AC [R] (SetupWidgetLayout)
    u8 _pad_23B0[0x18];  // 0x23B0
    f64 m_upWidgetLayout_23C8;  // 0x23C8 [R] (SetupWidgetLayout)
    f64 m_upWidgetLayout_23D0;  // 0x23D0 [R] (SetupWidgetLayout)
    u8 _pad_23D8[4];  // 0x23D8
    f32 m_upWidgetLayout_23DC;  // 0x23DC [R] (SetupWidgetLayout)
    u8 _pad_23E0[4];  // 0x23E0
    f32 m_upWidgetLayout_23E4;  // 0x23E4 [R] (SetupWidgetLayout)
};

#endif // M2MTARGET_H
