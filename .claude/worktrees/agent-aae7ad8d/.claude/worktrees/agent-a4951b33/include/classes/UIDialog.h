#ifndef UIDIALOG_H
#define UIDIALOG_H

#include "types.h"

// UIDialog - struct layout extracted from assembly analysis
// Estimated minimum size: 0x88 (136 bytes)
// 20 known fields (1 named), 16 methods

class UIDialog {
public:
    // Constructors / Destructors
    UIDialog(void)  // 0x8054FCC0
    ~UIDialog(void);  // 0x80503F2C

    // Methods
    void SpawnDialog(void);  // 0x80504024 (68B)
    void ZeroInputCallback(void);  // 0x8054FE84 (64B)
    void DialogClosedCallback(void);  // 0x8054FEC4 (64B)
    void HideDialog(void);  // 0x805040B0 (144B)
    void ChangeContinueType(int);  // 0x80504068 (72B)
    void SelectionCallback(int);  // 0x8054FE40 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (UIDialog)
    u32 m_field_004;  // 0x004 [W] (UIDialog)
    u32 m_field_008;  // 0x008 [W] (UIDialog)
    u32 m_field_00C;  // 0x00C [W] (UIDialog)
    u32 m_field_010;  // 0x010 [W] (UIDialog)
    u32 m_field_014;  // 0x014 [W] (UIDialog)
    u32 m_field_018;  // 0x018 [W] (UIDialog)
    u32 m_field_01C;  // 0x01C [W] (UIDialog)
    u32 m_field_020;  // 0x020 [W] (UIDialog)
    u32 m_field_024;  // 0x024 [W] (UIDialog)
    u8 _pad_028[0x14];  // 0x028
    u32 m_field_03C;  // 0x03C [R/W] (UIDialog, ~UIDialog)
    u32 m_field_040;  // 0x040 [W] (UIDialog)
    u32 m_field_044;  // 0x044 [R/W] (UIDialog, ~UIDialog)
    u16 m_field_048;  // 0x048 [W] (UIDialog)
    u16 m_field_04A;  // 0x04A [W] (UIDialog)
    u32 m_field_04C;  // 0x04C [W] (UIDialog)
    u32 m_field_050;  // 0x050 [W] (UIDialog)
    u8 _pad_054[0xC];  // 0x054
    u32 m_field_060;  // 0x060 [W] (UIDialog)
    u8 _pad_064[0xC];  // 0x064
    u32 m_field_070;  // 0x070 [W] (UIDialog)
    u8 _pad_074[0x10];  // 0x074
    u32 m_field_084;  // 0x084 [W] (UIDialog, ~UIDialog)
};

#endif // UIDIALOG_H
