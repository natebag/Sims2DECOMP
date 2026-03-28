#ifndef MENUDIALOGPANE_H
#define MENUDIALOGPANE_H

#include "types.h"

// MenuDialogPane - struct layout extracted from assembly analysis
// Estimated minimum size: 0x60 (96 bytes)
// 2 known fields (0 named), 13 methods

class MenuDialogPane {
public:
    // Constructors / Destructors
    MenuDialogPane(int, int, int, int)  // 0x80193C28
    ~MenuDialogPane(void);  // 0x801944D4

    // Methods
    void SetMenuWidth(float);  // 0x80193D40 (40B)
    void SetMenuItemFont(int, ERFont *);  // 0x80193E48 (76B)
    void SetMenuItemFontSize(int, float);  // 0x80193E94 (84B)
    /* ? */ GetMenuItem(int);  // 0x80193DAC (80B)
    void SetMenuItemText(int, unsigned wchar_t *);  // 0x80193DFC (76B)
    void SetSelectedMenuItem(int);  // 0x80193D68 (68B)
    /* ? */ GetSelectedMenuItemValue(void);  // 0x8019A5F8 (220B)
    /* ? */ GetSelectedMenuItemStyle(void);  // 0x8019A520 (216B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (~MenuDialogPane)
    u8 _pad_00C[0x50];  // 0x00C
    u32 m_field_05C;  // 0x05C [W] (~MenuDialogPane)
};

#endif // MENUDIALOGPANE_H
