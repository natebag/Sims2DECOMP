#ifndef WRAPPER_H
#define WRAPPER_H

#include "types.h"

// Wrapper - struct layout extracted from assembly analysis
// Estimated minimum size: 0xA4 (164 bytes)
// 6 known fields (0 named), 45 methods

class Wrapper {
public:
    // Constructors / Destructors
    Wrapper(char *)  // 0x80189F40
    ~Wrapper(void);  // 0x80189FD4

    // Methods
    void SetDefaultFont(ERFont *);  // 0x80188D04 (40B)
    void SetDefaultTextStyle(ItemStyle);  // 0x80188D2C (40B)
    void SetDefaultButtonStyle(ItemStyle);  // 0x80188D54 (40B)
    bool IsDrawOverApt(void);  // 0x80188CD8 (44B)
    void SetDrawOverApt(bool);  // 0x80188CB0 (40B)
    void SetDefaultMenuStyle(ItemStyle);  // 0x80193F38 (40B)
    void WrapperStartup(UIObjectBase *);  // 0x8019A6D4 (44B)
    void AddPane(WrapperPaneBase *);  // 0x8019AD98 (104B)
    void WrapperShutdown(void);  // 0x8019A700 (380B)
    void WrapperReset(void);  // 0x8019A950 (124B)
    void WrapperUpdate(void);  // 0x8019A9CC (80B)
    void WrapperReadController(bool, int);  // 0x8019ACA8 (240B)
    void WrapperCallFunction(char *);  // 0x8019AC4C (92B)
    void WrapperDraw(ERC *);  // 0x8019AA1C (560B)
    void WrapperRestoreMessageHandler(void);  // 0x8019A87C (128B)
    void WrapperRemoveMessageHandler(void);  // 0x8019A8FC (84B)
    /* ? */ GetDefaultFont(void);  // 0x801A0DE0 (44B)
    /* ? */ GetDefaultTextStyle(void);  // 0x801A0E90 (44B)
    /* ? */ GetDefaultTextFontSize(void);  // 0x801A0E0C (44B)
    /* ? */ GetDefaultMenuStyle(void);  // 0x801A0EBC (44B)
    /* ? */ GetDefaultMenuFontSize(void);  // 0x801A0E38 (44B)
    /* ? */ GetDefaultButtonStyle(void);  // 0x801A0EE8 (44B)
    /* ? */ GetDefaultButtonFontSize(void);  // 0x801A0E64 (44B)
    void FindPane(WrapperPaneBase *);  // 0x8019AF38 (168B)
    void ReleasePaneBackgrounds(void);  // 0x8019AE00 (136B)
    void FindPaneById(int);  // 0x8019AE88 (176B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x80];  // 0x000
    u32 m_field_080;  // 0x080 [W] (~Wrapper)
    u8 _pad_084[4];  // 0x084
    u32 m_field_088;  // 0x088 [R] (WrapperShutdown)
    u32 m_field_08C;  // 0x08C [R/W] (AddPane, ReleasePaneBackgrounds, WrapperDraw, ...)
    u32 m_field_090;  // 0x090 [R/W] (WrapperShutdown)
    u32 m_field_094;  // 0x094 [R/W] (WrapperShutdown)
    u8 _pad_098[8];  // 0x098
    u32 m_field_0A0;  // 0x0A0 [R] (WrapperDraw)
};

#endif // WRAPPER_H
