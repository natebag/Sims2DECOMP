#ifndef MDITARGET_H
#define MDITARGET_H

#include "types.h"

// MDITarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x2654 (9812 bytes)
// 32 known fields (17 named), 32 methods

class MDITarget {
public:
    // Constructors / Destructors
    MDITarget(void)  // 0x805155D8
    ~MDITarget(void);  // 0x80515924

    // Methods
    void SpawnModelessDialog(UIDialog *);  // 0x805162F8 (672B)
    void CleanupModelessDialogs(void);  // 0x805167A8 (56B)
    void CountModelessDialogs(void);  // 0x80516638 (244B)
    bool IsModelessDialogActive(void);  // 0x805162CC (44B)
    void DeleteAllModelessDialogs(void);  // 0x8051672C (124B)
    void SetVariable(char *, char *);  // 0x8051599C (408B)
    /* ? */ GetVariable(char *);  // 0x80515B34 (504B)
    /* ? */ GetLocalizable(char *);  // 0x80515D2C (744B)
    void Update(void);  // 0x80516014 (584B)
    void SetupModelessDialog(void);  // 0x805167E0 (3336B)
    void HideModelessDialog(void);  // 0x80516284 (40B)
    void ShowModelessDialog(void);  // 0x8051625C (40B)
    void UpdateModelessDialogs(void);  // 0x805162AC (32B)
    void AddToList(MDITarget::ModelessDialog *);  // 0x80516598 (160B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (GetLocalizable, GetVariable, MDITarget, ...)
    u8 _pad_002[2];  // 0x002
    f32 m_variable;  // 0x004 [R/W] (GetVariable, MDITarget, SetupModelessDialog, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (MDITarget, SpawnModelessDialog, ~MDITarget)
    u32 m_upModelessDialog;  // 0x00C [R/W] (MDITarget, SetupModelessDialog, SpawnModelessDialog, ...)
    u32 m_field_010;  // 0x010 [R/W] (MDITarget, SpawnModelessDialog, ~MDITarget)
    u32 m_field_014;  // 0x014 [R/W] (MDITarget, SpawnModelessDialog, ~MDITarget)
    u32 m_field_018;  // 0x018 [R/W] (MDITarget, SpawnModelessDialog, ~MDITarget)
    u32 m_upModelessDialog_01C;  // 0x01C [R/W] (MDITarget, SetupModelessDialog, SpawnModelessDialog, ...)
    u32 m_field_020;  // 0x020 [R/W] (MDITarget, SpawnModelessDialog, ~MDITarget)
    u32 m_field_024;  // 0x024 [R/W] (MDITarget, ~MDITarget)
    u32 m_field_028;  // 0x028 [W] (MDITarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (MDITarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (MDITarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (MDITarget, ~MDITarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (MDITarget, ~MDITarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (MDITarget)
    u32 m_upModelessDialog_07C;  // 0x07C [R/W] (MDITarget, SetupModelessDialog, ~MDITarget)
    u32 m_field_080;  // 0x080 [W] (MDITarget, ~MDITarget)
    u32 m_localizable_084;  // 0x084 [R/W] (AddToList, DeleteAllModelessDialogs, GetLocalizable, ...)
    u32 m_field_088;  // 0x088 [R/W] (AddToList, DeleteAllModelessDialogs, MDITarget, ...)
    u32 m_variable_08C;  // 0x08C [R/W] (GetVariable, MDITarget, SetupModelessDialog)
    u32 m_variable_090;  // 0x090 [R/W] (GetVariable, MDITarget, Update)
    u32 m_variable_094;  // 0x094 [R/W] (MDITarget, SetVariable, Update)
    u32 m_variable_098;  // 0x098 [R/W] (MDITarget, SetVariable, Update)
    u32 m_field_09C;  // 0x09C [R/W] (MDITarget, Update)
    u8 _pad_0A0[0x256C];  // 0x0A0
    f32 m_upModelessDialog_260C;  // 0x260C [R] (SetupModelessDialog)
    u8 _pad_2610[0xC];  // 0x2610
    f32 m_upModelessDialog_261C;  // 0x261C [R] (SetupModelessDialog)
    f32 m_upModelessDialog_2620;  // 0x2620 [R] (SetupModelessDialog)
    u8 _pad_2624[4];  // 0x2624
    f32 m_upModelessDialog_2628;  // 0x2628 [R] (SetupModelessDialog)
    u8 _pad_262C[0xC];  // 0x262C
    f32 m_upModelessDialog_2638;  // 0x2638 [R] (SetupModelessDialog)
    u8 _pad_263C[0x14];  // 0x263C
    f32 m_upModelessDialog_2650;  // 0x2650 [R] (SetupModelessDialog)
};

#endif // MDITARGET_H
