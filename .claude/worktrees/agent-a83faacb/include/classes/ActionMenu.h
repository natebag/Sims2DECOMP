#ifndef ACTIONMENU_H
#define ACTIONMENU_H

#include "types.h"

// ActionMenu - struct layout extracted from assembly analysis
// Estimated minimum size: 0x398 (920 bytes)
// 27 known fields (6 named), 43 methods

class ActionMenu {
public:
    // Constructors / Destructors
    ActionMenu(void)  // 0x8049C93C
    ~ActionMenu(void);  // 0x8049CA40

    // Methods
    bool IsObjectInMenu(cXObject *);  // 0x8049CAF4 (80B)
    void Start(HUDTarget *, int);  // 0x8049CB44 (64B)
    void Draw(ERC *);  // 0x8049CB84 (1712B)
    /* ? */ GetCurrentMenu(void);  // 0x804A19B0 (88B)
    void TerminateMenu(void);  // 0x8049E4F8 (432B)
    void Start(INVTarget *, int);  // 0x8049D234 (64B)
    void Stop(void);  // 0x8049D274 (284B)
    void Animate(void);  // 0x8049D390 (164B)
    void FillInMenu(void);  // 0x8049D610 (708B)
    void UpdateIcon(void);  // 0x8049D434 (476B)
    /* ? */ GetSelectedItem(void);  // 0x804A1A08 (48B)
    void Run(void);  // 0x8049D8D4 (608B)
    void AcceptMenu(void);  // 0x8049E130 (828B)
    void BackOutMenu(void);  // 0x8049E00C (292B)
    void AddMenu(cXObject *, BString2 &, unsigned int, ERShader *);  // 0x8049DB34 (420B)
    void AddMenuItem(cXObject *, Interaction *, BString2 &, unsigned int, ERShader *, bool);  // 0x8049DCD8 (172B)
    void CompleteMenu(void);  // 0x8049DD84 (172B)
    void ShowMenu(void);  // 0x8049DE30 (476B)
    void CloseMenu(void);  // 0x8049E46C (140B)
    /* ? */ GetPlayerSim(void);  // 0x8049E6A8 (132B)
    bool IsMenuAvailable(void);  // 0x804B0618 (60B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AcceptMenu, ActionMenu, AddMenu, ...)
    u16 m_field_004;  // 0x004 [R/W] (ActionMenu, Draw, Run, ...)
    s16 m_field_006;  // 0x006 [R/W] (AcceptMenu, ActionMenu, Animate, ...)
    u8 m_icon;  // 0x007 [R] (AcceptMenu, FillInMenu, UpdateIcon)
    u8 m_field_008;  // 0x008 [W] (ActionMenu, Stop)
    u8 m_field_009;  // 0x009 [R/W] (AcceptMenu, ActionMenu, Animate, ...)
    u8 m_field_00A;  // 0x00A [W] (AcceptMenu, BackOutMenu)
    u8 _pad_00B[0x11];  // 0x00B
    u32 m_icon_01C;  // 0x01C [R] (UpdateIcon)
    u8 _pad_020[0x2C];  // 0x020
    u32 m_field_04C;  // 0x04C [R/W] (MenuItem::ClearMenu, MenuItem::MenuItem, MenuItem::Setup)
    u32 m_icon_050;  // 0x050 [R/W] (MenuItem::MenuItem, MenuItem::Setup, UpdateIcon)
    u32 m_field_054;  // 0x054 [R/W] (MenuItem::ClearMenu, MenuItem::MenuItem, MenuItem::Setup, ...)
    u32 m_field_058;  // 0x058 [R/W] (AcceptMenu, MenuItem::MenuItem, MenuItem::Setup)
    u32 m_field_05C;  // 0x05C [R/W] (AcceptMenu, MenuItem::AddSubItem, MenuItem::ClearMenu, ...)
    u32 m_field_060;  // 0x060 [R/W] (MenuItem::ClearMenu, MenuItem::IsObjectInMenu, MenuItem::MenuItem)
    u8 _pad_064[0xC];  // 0x064
    u32 m_field_070;  // 0x070 [W] (ActionMenu, Stop, TerminateMenu)
    u8 _pad_074[0x1C];  // 0x074
    u16 m_field_090;  // 0x090 [W] (ActionMenu, Stop)
    u8 _pad_092[0xE];  // 0x092
    u8 m_field_0A0;  // 0x0A0 [R/W] (AcceptMenu, ActionMenu, AddMenu, ...)
    u8 m_field_0A1;  // 0x0A1 [W] (ActionMenu, Draw, FillInMenu)
    u8 m_field_0A2;  // 0x0A2 [R/W] (AcceptMenu, ActionMenu, Animate, ...)
    u8 _pad_0A3[1];  // 0x0A3
    u32 m_icon_0A4;  // 0x0A4 [R/W] (ActionMenu, Stop, UpdateIcon)
    u32 m_playerSim;  // 0x0A8 [R] (AcceptMenu, BackOutMenu, Draw, ...)
    u32 m_field_0AC;  // 0x0AC [R/W] (ActionMenu, Run, ShowMenu, ...)
    u32 m_field_0B0;  // 0x0B0 [R/W] (ActionMenu, ~ActionMenu)
    u8 _pad_0B4[0x2B4];  // 0x0B4
    s16 m_field_368;  // 0x368 [R] (Draw)
    u8 _pad_36A[2];  // 0x36A
    u32 m_field_36C;  // 0x36C [R] (Draw)
    u8 _pad_370[0x20];  // 0x370
    s16 m_field_390;  // 0x390 [R] (Draw)
    u8 _pad_392[2];  // 0x392
    u32 m_field_394;  // 0x394 [R] (Draw)
};

#endif // ACTIONMENU_H
