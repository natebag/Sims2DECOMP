#ifndef EDITHDIALOGPRIMITIVE_H
#define EDITHDIALOGPRIMITIVE_H

#include "types.h"

// EdithDialogPrimitive - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8C (140 bytes)
// 22 known fields (11 named), 14 methods

class EdithDialogPrimitive {
public:
    // Constructors / Destructors
    EdithDialogPrimitive(void)  // 0x80230914
    ~EdithDialogPrimitive(void);  // 0x80230A84

    // Methods
    void SelectionCallback(int);  // 0x80230AD0 (100B)
    void AssignString(StringSet *, BString2 &, int, unsigned wchar_t *, bool);  // 0x80230B34 (352B)
    void ResetDialogParameters(void);  // 0x80230C94 (308B)
    void SetDialog(StackElem *, DialogParam *, cXObject *, bool);  // 0x80230DC8 (3972B)
    /* ? */ GetModalDialogResult(void);  // 0x80232A9C (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (EdithDialogPrimitive, SetDialog)
    u32 m_dialog_004;  // 0x004 [R/W] (EdithDialogPrimitive, SetDialog)
    u32 m_dialog_008;  // 0x008 [W] (EdithDialogPrimitive, SetDialog)
    u32 m_dialog_00C;  // 0x00C [R/W] (EdithDialogPrimitive, SetDialog)
    u32 m_dialog_010;  // 0x010 [W] (EdithDialogPrimitive, SetDialog)
    u32 m_dialog_014;  // 0x014 [W] (EdithDialogPrimitive, SetDialog)
    u32 m_dialog_018;  // 0x018 [W] (EdithDialogPrimitive, ResetDialogParameters, SetDialog)
    u32 m_field_01C;  // 0x01C [W] (EdithDialogPrimitive)
    u32 m_field_020;  // 0x020 [W] (EdithDialogPrimitive)
    u32 m_field_024;  // 0x024 [W] (EdithDialogPrimitive)
    u8 _pad_028[0x14];  // 0x028
    u32 m_dialog_03C;  // 0x03C [R/W] (EdithDialogPrimitive, ResetDialogParameters, SetDialog)
    u32 m_field_040;  // 0x040 [W] (EdithDialogPrimitive)
    u32 m_field_044;  // 0x044 [W] (EdithDialogPrimitive, ResetDialogParameters)
    u16 m_dialog_048;  // 0x048 [W] (EdithDialogPrimitive, ResetDialogParameters, SetDialog)
    u16 m_dialog_04A;  // 0x04A [W] (EdithDialogPrimitive, ResetDialogParameters, SetDialog)
    u32 m_dialog_04C;  // 0x04C [W] (EdithDialogPrimitive, SetDialog)
    u32 m_field_050;  // 0x050 [W] (EdithDialogPrimitive)
    u8 _pad_054[0xC];  // 0x054
    u32 m_field_060;  // 0x060 [W] (EdithDialogPrimitive)
    u8 _pad_064[0xC];  // 0x064
    u32 m_field_070;  // 0x070 [W] (EdithDialogPrimitive)
    u8 _pad_074[0xC];  // 0x074
    u32 m_field_080;  // 0x080 [W] (EdithDialogPrimitive)
    u32 m_field_084;  // 0x084 [W] (EdithDialogPrimitive)
    u32 m_field_088;  // 0x088 [W] (EdithDialogPrimitive)
};

#endif // EDITHDIALOGPRIMITIVE_H
