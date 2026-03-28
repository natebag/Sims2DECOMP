#ifndef R2LTARGET_H
#define R2LTARGET_H

#include "types.h"

// R2LTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1EC (492 bytes)
// 46 known fields (20 named), 38 methods

class R2LTarget {
public:
    // Constructors / Destructors
    R2LTarget(int)  // 0x80534714
    ~R2LTarget(void);  // 0x80534C1C

    // Methods
    void SetupRelationships(void);  // 0x80536494 (1280B)
    void SetupPageShaders(void);  // 0x80536994 (2536B)
    void SetVariable(char *, char *);  // 0x80534E24 (1580B)
    void ChangeSelection(int);  // 0x8053737C (1684B)
    void SpawnSummaryDialog(void);  // 0x805361E4 (688B)
    void ScrollRightEnabled(void);  // 0x80537BA8 (80B)
    void ScrollLeftEnabled(void);  // 0x80537B68 (64B)
    void RecordIndexToGridIndex(int);  // 0x80537A10 (108B)
    /* ? */ GetVariable(char *);  // 0x80535450 (708B)
    /* ? */ GetLocalizable(char *);  // 0x80535714 (2736B)
    void GridIndexToRecordIndex(int);  // 0x80537A7C (112B)
    void OldGridIndexToRecordIndex(int);  // 0x80537AEC (124B)
    void Update(void);  // 0x805361C4 (32B)
    void onSummaryDialogSelection(int);  // 0x80537C1C (112B)
    void onSummaryDialogZeroInputCallback(void);  // 0x80537C8C (40B)
    void onSummaryDialogDialogClosedCallback(void);  // 0x80537CB4 (40B)
    void onHelpDialogSelection(int);  // 0x80537BF8 (36B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (ChangeSelection, GetLocalizable, GetVariable, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (ChangeSelection, GetVariable, R2LTarget, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_upPageShaders;  // 0x008 [R/W] (R2LTarget, SetupPageShaders, ~R2LTarget)
    u16 m_upPageShaders_00C;  // 0x00C [R/W] (R2LTarget, SetupPageShaders, ~R2LTarget)
    u8 _pad_00E[2];  // 0x00E
    u32 m_field_010;  // 0x010 [R/W] (R2LTarget, ~R2LTarget)
    u32 m_field_014;  // 0x014 [R/W] (ChangeSelection, R2LTarget, ~R2LTarget)
    u32 m_upPageShaders_018;  // 0x018 [R/W] (ChangeSelection, R2LTarget, SetupPageShaders, ...)
    u32 m_upPageShaders_01C;  // 0x01C [R/W] (ChangeSelection, R2LTarget, SetupPageShaders, ...)
    u32 m_field_020;  // 0x020 [R/W] (R2LTarget, ~R2LTarget)
    u32 m_field_024;  // 0x024 [R/W] (R2LTarget, ~R2LTarget)
    u32 m_field_028;  // 0x028 [W] (R2LTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (R2LTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (R2LTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (R2LTarget, ~R2LTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (R2LTarget, ~R2LTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (R2LTarget)
    u32 m_upPageShaders_07C;  // 0x07C [R/W] (ChangeSelection, R2LTarget, SetupPageShaders, ...)
    u32 m_variable_080;  // 0x080 [R/W] (R2LTarget, SetVariable, ~R2LTarget)
    u32 m_field_084;  // 0x084 [W] (R2LTarget, ~R2LTarget)
    u32 m_variable_088;  // 0x088 [W] (GetVariable, R2LTarget)
    u32 m_field_08C;  // 0x08C [R/W] (R2LTarget, ~R2LTarget)
    u32 m_field_090;  // 0x090 [R/W] (R2LTarget, ~R2LTarget)
    u32 m_upPageShaders_094;  // 0x094 [R/W] (ChangeSelection, R2LTarget, SetupPageShaders, ...)
    u32 m_localizable_098;  // 0x098 [R/W] (ChangeSelection, GetLocalizable, SetupPageShaders, ...)
    u32 m_localizable_09C;  // 0x09C [R/W] (ChangeSelection, GetLocalizable, GetVariable, ...)
    u32 m_localizable_0A0;  // 0x0A0 [R/W] (ChangeSelection, GetLocalizable, GetVariable, ...)
    u32 m_variable_0A4;  // 0x0A4 [R/W] (R2LTarget, SetVariable)
    u32 m_variable_0A8;  // 0x0A8 [W] (R2LTarget, SetVariable)
    u8 _pad_0AC[4];  // 0x0AC
    u32 m_localizable_0B0;  // 0x0B0 [R/W] (ChangeSelection, GetLocalizable, R2LTarget)
    u32 m_localizable_0B4;  // 0x0B4 [R/W] (ChangeSelection, GetLocalizable, R2LTarget)
    u32 m_variable_0B8;  // 0x0B8 [R/W] (GetVariable, R2LTarget, SetVariable, ...)
    u32 m_field_0BC;  // 0x0BC [W] (R2LTarget, SpawnSummaryDialog)
    u32 m_field_0C0;  // 0x0C0 [W] (SpawnSummaryDialog)
    u32 m_field_0C4;  // 0x0C4 [W] (SpawnSummaryDialog)
    u32 m_field_0C8;  // 0x0C8 [W] (SpawnSummaryDialog)
    u32 m_field_0CC;  // 0x0CC [W] (SpawnSummaryDialog)
    u32 m_field_0D0;  // 0x0D0 [W] (SpawnSummaryDialog)
    u8 _pad_0D4[4];  // 0x0D4
    u32 m_field_0D8;  // 0x0D8 [W] (SpawnSummaryDialog)
    u8 _pad_0DC[4];  // 0x0DC
    u32 m_field_0E0;  // 0x0E0 [W] (SpawnSummaryDialog)
    u8 _pad_0E4[0x24];  // 0x0E4
    u32 m_field_108;  // 0x108 [W] (SpawnSummaryDialog)
    u32 m_field_10C;  // 0x10C [W] (R2LTarget, SpawnSummaryDialog)
    u8 _pad_110[0xC];  // 0x110
    u32 m_field_11C;  // 0x11C [W] (R2LTarget, SpawnSummaryDialog)
    u8 _pad_120[0xC];  // 0x120
    u32 m_field_12C;  // 0x12C [W] (R2LTarget, SpawnSummaryDialog)
    u8 _pad_130[0x9C];  // 0x130
    u32 m_variable_1CC;  // 0x1CC [R] (GetVariable, SetVariable)
    u8 _pad_1D0[0x18];  // 0x1D0
    u32 m_field_1E8;  // 0x1E8 [R/W] (ChangeSelection, R2LTarget, ~R2LTarget)
};

#endif // R2LTARGET_H
