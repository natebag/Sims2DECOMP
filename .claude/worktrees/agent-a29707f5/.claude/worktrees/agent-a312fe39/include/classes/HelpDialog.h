#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include "types.h"

// HelpDialog - struct layout extracted from assembly analysis
// Estimated minimum size: 0x90 (144 bytes)
// 23 known fields (1 named), 10 methods

class HelpDialog {
public:
    // Constructors / Destructors
    HelpDialog(void)  // 0x80477C24
    ~HelpDialog(void);  // 0x80477C80

    // Methods
    void SpawnHelpDialog(int, char *, char *, HelpDialogCallback *, bool, char *);  // 0x80477CCC (992B)
    void SpawnHelpDialog(int, char *, HelpDialogCallback *, bool, char *);  // 0x804780AC (176B)
    void SelectionCallback(int);  // 0x8047815C (128B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (HelpDialog, SpawnHelpDialog)
    u32 m_field_004;  // 0x004 [W] (HelpDialog, SpawnHelpDialog)
    u32 m_field_008;  // 0x008 [W] (HelpDialog, SpawnHelpDialog)
    u32 m_field_00C;  // 0x00C [W] (HelpDialog, SpawnHelpDialog)
    u32 m_field_010;  // 0x010 [W] (HelpDialog, SpawnHelpDialog)
    u32 m_field_014;  // 0x014 [W] (HelpDialog, SpawnHelpDialog)
    u32 m_field_018;  // 0x018 [W] (HelpDialog)
    u32 m_field_01C;  // 0x01C [W] (HelpDialog)
    u32 m_field_020;  // 0x020 [W] (HelpDialog)
    u32 m_field_024;  // 0x024 [W] (HelpDialog, SpawnHelpDialog)
    u8 _pad_028[0x14];  // 0x028
    u32 m_field_03C;  // 0x03C [W] (HelpDialog)
    u32 m_field_040;  // 0x040 [W] (HelpDialog)
    u32 m_field_044;  // 0x044 [W] (HelpDialog)
    u16 m_field_048;  // 0x048 [W] (HelpDialog, SpawnHelpDialog)
    u16 m_field_04A;  // 0x04A [W] (HelpDialog, SpawnHelpDialog)
    u32 m_field_04C;  // 0x04C [W] (HelpDialog, SpawnHelpDialog)
    u32 m_field_050;  // 0x050 [W] (HelpDialog, SpawnHelpDialog)
    u8 _pad_054[0xC];  // 0x054
    u32 m_field_060;  // 0x060 [W] (HelpDialog, SpawnHelpDialog)
    u8 _pad_064[0xC];  // 0x064
    u32 m_field_070;  // 0x070 [W] (HelpDialog, SpawnHelpDialog)
    u8 _pad_074[0xC];  // 0x074
    u32 m_field_080;  // 0x080 [W] (SpawnHelpDialog)
    u32 m_field_084;  // 0x084 [W] (HelpDialog)
    u32 m_field_088;  // 0x088 [R/W] (HelpDialog, SelectionCallback, SpawnHelpDialog)
    u32 m_field_08C;  // 0x08C [R/W] (HelpDialog, SelectionCallback, SpawnHelpDialog)
};

#endif // HELPDIALOG_H
