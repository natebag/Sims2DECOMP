#ifndef DIALOGPANEBASE_H
#define DIALOGPANEBASE_H

#include "types.h"

// DialogPaneBase - struct layout extracted from assembly analysis
// Estimated minimum size: 0x7330 (29488 bytes)
// 19 known fields (1 named), 52 methods

class DialogPaneBase {
public:
    // Constructors / Destructors
    DialogPaneBase(int, int)  // 0x8019FDC0
    ~DialogPaneBase(void);  // 0x8019FE38

    // Methods
    void SetTitleFontSize(float);  // 0x801A001C (168B)
    void SetBodyFontSize(float);  // 0x801A0478 (168B)
    /* ? */ GetBodyTextItem(void);  // 0x8019FEB0 (44B)
    void SetBodyPosX(float);  // 0x801A05EC (212B)
    void SetBodyPosY(float);  // 0x801A06C0 (212B)
    void SetTitlePosX(float);  // 0x801A0190 (212B)
    void SetTitlePosY(float);  // 0x801A0264 (212B)
    void Startup(void);  // 0x8019A36C (160B)
    void SetBodyDisplaySize(EVec2 &);  // 0x801A0794 (160B)
    /* ? */ GetBodyDisplayPadSizeX(void);  // 0x801A0B64 (164B)
    /* ? */ GetBodyDisplayPadSizeY(void);  // 0x801A0C08 (164B)
    /* ? */ GetTitleTextItem(void);  // 0x8019FE84 (44B)
    void SetTitleText(unsigned wchar_t *);  // 0x8019FEDC (160B)
    void SetBodyText(unsigned wchar_t *);  // 0x801A0338 (160B)
    void SetBodyFont(ERFont *);  // 0x801A03D8 (160B)
    void SetBodyPos(EVec2);  // 0x801A0520 (204B)
    void SetBodyDisplayPadSize(EVec2 &);  // 0x801A0A20 (160B)
    void Shutdown(void);  // 0x8019A40C (56B)
    void SetTitleFont(ERFont *);  // 0x8019FF7C (160B)
    void SetTitlePos(EVec2);  // 0x801A00C4 (204B)
    /* ? */ GetBodyDisplaySize(void);  // 0x801A0834 (164B)
    /* ? */ GetBodyDisplaySizeX(void);  // 0x801A08D8 (164B)
    /* ? */ GetBodyDisplaySizeY(void);  // 0x801A097C (164B)
    /* ? */ GetBodyDisplayPadSize(void);  // 0x801A0AC0 (164B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (DialogPaneBase, Startup)
    u32 m_field_004;  // 0x004 [W] (DialogPaneBase, Startup)
    u32 m_field_008;  // 0x008 [R/W] (DialogPaneBase, Startup, ~DialogPaneBase)
    f32 m_field_00C;  // 0x00C [W] (Startup)
    f32 m_field_010;  // 0x010 [W] (Startup)
    f32 m_field_014;  // 0x014 [W] (Startup)
    f32 m_field_018;  // 0x018 [W] (DialogPaneBase, Startup)
    f32 m_field_01C;  // 0x01C [W] (DialogPaneBase, Startup)
    u8 _pad_020[4];  // 0x020
    f32 m_field_024;  // 0x024 [W] (DialogPaneBase)
    u8 _pad_028[4];  // 0x028
    f32 m_field_02C;  // 0x02C [W] (DialogPaneBase)
    f32 m_field_030;  // 0x030 [W] (DialogPaneBase)
    u32 m_field_034;  // 0x034 [W] (DialogPaneBase)
    u32 m_field_038;  // 0x038 [W] (DialogPaneBase)
    u32 m_field_03C;  // 0x03C [W] (DialogPaneBase)
    u8 _pad_040[0x1C];  // 0x040
    u32 m_field_05C;  // 0x05C [W] (DialogPaneBase, ~DialogPaneBase)
    u32 m_field_060;  // 0x060 [R/W] (DialogPaneBase, Startup)
    u32 m_field_064;  // 0x064 [R/W] (DialogPaneBase, Startup)
    u8 _pad_068[4];  // 0x068
    u32 m_field_06C;  // 0x06C [W] (Startup)
    u8 _pad_070[0x72BC];  // 0x070
    f32 m_field_732C;  // 0x732C [R] (DialogPaneBase)
};

#endif // DIALOGPANEBASE_H
