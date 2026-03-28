#ifndef WRAPPER_H
#define WRAPPER_H

#include "types.h"

// Forward declarations
class ERC;
class ERShader;
class ERFont;
class UIObjectBase;

// EVec2 - 2D vector (8 bytes)
struct EVec2 {
    f32 x;
    f32 y;
};

// EVec4 - 4D vector (16 bytes)
struct EVec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

// ItemType enum
enum ItemType {
    kItemType_Text   = 0,
    kItemType_Menu   = 1,
    kItemType_Button = 2,
    kItemType_Icon   = 3,
};

// ItemStyle enum - values based on disassembly
enum ItemStyle {
    kItemStyle_Default = 7,
};

// Forward declarations for external functions
extern "C" {
    ERShader* ERShader_AddRef(const char* name, u32 hashId, u32 flags1, u32 flags2);
    void ERShader_Release(ERShader* shader);
    void* EControllerMan_GetInstance();
    void EControllerMan_SetPlayer(void* mgr, int player);
    void EControllerMan_ReadController(void* mgr, int flags);
    u32 _strlen(const char* s);
}

// PaneItem base
struct PaneItem;

// TextBlock sub-object at offset 0x20 within TextBaseItem
// Has a SetDirty() method at 0x803a05d8
struct TextBlock {
    void SetDirty();
};

// TextBaseItem - base class for text-based UI items
// Has vtable at offset 0x00
// Layout:
//   0x00: vtable*
//   0x04: u32 m_flags
//   0x08: s32 m_value
//   0x0C-0x1F: padding
//   0x20: unsigned short* m_text
//   0x24: f32 m_posX
//   0x28: f32 m_posY
//   0x2C: f32 m_displaySizeX
//   0x30: f32 m_displaySizeY
//   0x34: f32 m_displayPadSizeX
//   0x38: f32 m_displayPadSizeY
//   0x3C-0x43: padding
//   0x44: EVec4* m_color
//   0x48: f32 m_shadowAlpha
//   0x4C: f32 m_shadowSize
//   0x50: ERFont* m_font
//   0x54: f32 m_fontSize
//   0x58: u32 m_textBlockFlags
//   0x5C-0x6B: padding
//   0x6C: ItemStyle m_style
class TextBaseItem {
public:
    /* vtable at 0x00 - implicit from virtual */
    u32 m_flags;                            // 0x04
    s32 m_value;                            // 0x08
    u8 _pad0C[0x14];                        // 0x0C - 0x1F
    unsigned short* m_text;                 // 0x20
    f32 m_posX;                             // 0x24
    f32 m_posY;                             // 0x28
    f32 m_displaySizeX;                     // 0x2C
    f32 m_displaySizeY;                     // 0x30
    f32 m_displayPadSizeX;                  // 0x34
    f32 m_displayPadSizeY;                  // 0x38
    u8 _pad3C[0x08];                        // 0x3C - 0x43
    EVec4* m_color;                         // 0x44
    f32 m_shadowAlpha;                      // 0x48
    f32 m_shadowSize;                       // 0x4C
    ERFont* m_font;                         // 0x50
    f32 m_fontSize;                         // 0x54
    u32 m_textBlockFlags;                   // 0x58
    u8 _pad5C[0x10];                        // 0x5C - 0x6B
    ItemStyle m_style;                      // 0x6C

    TextBaseItem(ItemType type);
    virtual ~TextBaseItem();

    void Startup();
    void Draw(ERC* rc, f32 alpha);
    void SetStyle(ItemStyle style);
    void SetText(unsigned short* text);
    void Reset();
    void CalculateSize();

    void SetPos(EVec2& pos);
    EVec2* GetPos();
    void SetPosX(f32 x);
    f32 GetPosX();
    void SetPosY(f32 y);
    f32 GetPosY();

    void SetColor(EVec4& color);
    EVec4* GetColor();
    void SetAlpha(f32 alpha);
    f32 GetAlpha();
    void SetShadowAlpha(f32 alpha);
    f32 GetShadowAlpha();
    void SetShadowSize(f32 size);
    f32 GetShadowSize();

    void SetDisplaySize(EVec2& size);
    EVec2* GetDisplaySize();
    f32 GetDisplaySizeX();
    f32 GetDisplaySizeY();
    void SetDisplayPadSize(EVec2& size);
    EVec2* GetDisplayPadSize();
    f32 GetDisplayPadSizeX();
    f32 GetDisplayPadSizeY();

    void SetVerticalCenter(bool center);
    void SetYPosCentered(bool centered);

    unsigned short* GetText() const;
    void SetFont(ERFont* font);
    ERFont* GetFont() const;
    void SetFontSize(f32 size);
    f32 GetFontSize() const;
    ItemStyle GetStyle() const;
};

// TextItem
class TextItem : public TextBaseItem {
public:
    TextItem();
    virtual ~TextItem();
};

// MenuItem
class MenuItem : public TextBaseItem {
public:
    MenuItem();
    virtual ~MenuItem();
};

// ButtonItem
class ButtonItem : public TextBaseItem {
public:
    ButtonItem();
    virtual ~ButtonItem();
};

// IconItem - icon/image display item (NOT virtual - no vtable)
// Layout:
//   0x00-0x1F: data/padding
//   0x20-0x2B: color (r,g,b)
//   0x2C: f32 alpha
//   0x30: ERShader* m_shader
class IconItem {
public:
    u8 _pad00[0x20];       // 0x00 - 0x1F
    f32 m_colorR;          // 0x20
    f32 m_colorG;          // 0x24
    f32 m_colorB;          // 0x28
    f32 m_alpha;           // 0x2C
    ERShader* m_shader;    // 0x30

    IconItem();
    ~IconItem();

    void Startup();
    void Shutdown();
    void Draw(ERC* rc, f32 alpha);
    void SetShader(u32 shaderHash);
    void SetShader(ERShader* shader);
    void ReleaseShader();
    void SetColor(EVec4& color);
    EVec4 GetColor();
    void SetAlpha(f32 alpha);
    f32 GetAlpha();
    ERShader* GetShader();
};

// WrapperPaneBase - NOT virtual (m_paneId at offset 0)
// Layout:
//   0x00: s32 m_paneId
//   0x04: u32 m_drawFlags
//   0x08: s32 m_numItemsInit
//   0x0C: s32 m_numItemsCurrent
//   0x10-0x17: item list
//   0x18: ERShader* m_bgShader
//   0x1C: f32 m_bgRectPosX
//   0x20: f32 m_bgRectPosY
//   0x24: f32 m_bgRectSizeX
//   0x28: f32 m_bgRectSizeY
//   0x2C: f32 m_bgAlpha
//   0x30: f32 m_alpha
//   0x34: PaneState m_state
//   0x38: char* m_buttonContext
//   0x3C: u32 m_buttonContextLen
//   0x40: TextBaseItem* m_buttons[3]
class WrapperPaneBase {
public:
    enum PaneState {
        kPaneState_Running  = 0,
        kPaneState_Accepted = 1,
        kPaneState_Declined = 2,
        kPaneState_Alt1     = 3,
    };

    enum ButtonType {
        kButton_Accept  = 0,
        kButton_Decline = 1,
        kButton_Alt1    = 2,
    };

    s32 m_paneId;                   // 0x00
    u32 m_drawFlags;                // 0x04
    s32 m_numItemsInit;             // 0x08
    s32 m_numItemsCurrent;          // 0x0C
    u8 _pad10[0x08];               // 0x10 - 0x17
    ERShader* m_bgShader;           // 0x18
    f32 m_bgRectPosX;              // 0x1C
    f32 m_bgRectPosY;              // 0x20
    f32 m_bgRectSizeX;             // 0x24
    f32 m_bgRectSizeY;             // 0x28
    f32 m_bgAlpha;                 // 0x2C
    f32 m_alpha;                   // 0x30
    PaneState m_state;             // 0x34
    char* m_buttonContext;         // 0x38
    u32 m_buttonContextLen;        // 0x3C
    TextBaseItem* m_buttons[3];    // 0x40, 0x44, 0x48
    // Total size: 0x4C

    WrapperPaneBase(int paneId, int numItems);
    ~WrapperPaneBase();

    void Startup();
    void Shutdown();
    void DeleteItemList();
    void DrawBackground(ERC* rc);
    void DrawItems(ERC* rc, bool drawSelected);
    void SetSelected(ItemType type, int index);
    TextBaseItem* GetSelectedItem(ItemType type);
    TextBaseItem* GetEnabledItemIndexWithValue(ItemType type, int value);
    TextBaseItem* GetItem(ItemType type, int index);
    void Reset();

    void SetItemText(ItemType type, int index, unsigned short* text);
    void SetItemFont(ItemType type, int index, ERFont* font);
    void SetItemFontSize(ItemType type, int index, f32 size);
    void SetItemStyle(ItemType type, int index, ItemStyle style);
    void SetItemPos(ItemType type, int index, EVec2& pos);
    void SetItemPosX(ItemType type, int index, f32 x);
    void SetItemPosY(ItemType type, int index, f32 y);
    void SetItemSize(ItemType type, int index, EVec2& size);
    void SetItemSizeX(ItemType type, int index, f32 x);
    void SetItemSizeY(ItemType type, int index, f32 y);
    void SetItemShader(ItemType type, int index, u32 shaderHash);

    unsigned short* GetItemText(ItemType type, int index);
    ERFont* GetItemFont(ItemType type, int index);
    f32 GetItemFontSize(ItemType type, int index);
    ItemStyle GetItemStyle(ItemType type, int index);
    EVec2* GetItemPos(ItemType type, int index);
    f32 GetItemPosX(ItemType type, int index);
    f32 GetItemPosY(ItemType type, int index);
    EVec2* GetItemSize(ItemType type, int index);
    f32 GetItemSizeX(ItemType type, int index);
    f32 GetItemSizeY(ItemType type, int index);

    void CalculateMenuWidthPixels();

    void SetBackgroundShader(u32 shaderHash);
    void ReleaseBackgroundShader();
    ERShader* GetBackgroundShader();
    void SetBackgroundRect(EVec2* pos, EVec2* size);
    void SetBackgroundAlpha(f32 alpha);

    void SetButtonContext(char* context);
    TextBaseItem* GetButton(ButtonType type);
    unsigned short* GetButtonText(ButtonType type) const;
    ERFont* GetButtonFont(ButtonType type) const;
    f32 GetButtonFontSize(ButtonType type) const;
    EVec2* GetButtonPos(ButtonType type) const;
    f32 GetButtonPosX(ButtonType type) const;
    f32 GetButtonPosY(ButtonType type) const;

    void SetButtonText(ButtonType type, unsigned short* text);
    void SetButtonFont(ButtonType type, ERFont* font);
    void SetButtonFontSize(ButtonType type, f32 size);
    void SetButtonPos(ButtonType type, EVec2& pos);
    void SetButtonPosX(ButtonType type, f32 x);
    void SetButtonPosY(ButtonType type, f32 y);

    void AddButton(ButtonType type, bool enabled, unsigned short* text);
    void ShowEnabledButtons();
    void HideEnabledButtons();
    void ShowButton(ButtonType type);
    void HideButton(ButtonType type);
    void UpdateAptButtonPosX(ButtonType type);
    void UpdateAptButtonPosY(ButtonType type);
    void UpdateAptButtonWidth(ButtonType type);

    void GetVariableButtonIndex(char* name, char* outValue);
    char* GetVariable(char* name);
    void SetVariable(char* name, char* value);

    TextBaseItem* GetAcceptButton();
    void SetAcceptText(unsigned short* text);
    void SetAcceptFont(ERFont* font);
    void SetAcceptFontSize(f32 size);
    void SetAcceptPos(EVec2& pos);
    void SetAcceptPosX(f32 x);
    void SetAcceptPosY(f32 y);

    TextBaseItem* GetDeclineButton();
    void SetDeclineText(unsigned short* text);
    void SetDeclineFont(ERFont* font);
    void SetDeclineFontSize(f32 size);
    void SetDeclinePos(EVec2& pos);
    void SetDeclinePosX(f32 x);
    void SetDeclinePosY(f32 y);

    TextBaseItem* GetAlt1Button();
    void SetAlt1Text(unsigned short* text);
    void SetAlt1Font(ERFont* font);
    void SetAlt1FontSize(f32 size);
    void SetAlt1Pos(EVec2& pos);
    void SetAlt1PosX(f32 x);
    void SetAlt1PosY(f32 y);

    void AddItem(PaneItem* item);
    void* GetItemList();

    s32 GetPaneId();
    void EnableDraw();
    void DisableDraw();
    bool IsDrawEnabled();
    void SetAlpha(f32 alpha);
    f32 GetAlpha();
    void SetState(PaneState state);
    void SetStateRunning();
    void SetStateAccepted();
    void SetStateDeclined();
    void SetStateAlt1();
    PaneState GetState() const;
    bool IsStateRunning() const;
    bool IsStateAccepted() const;
    bool IsStateDeclined() const;
    bool IsStateAlt1() const;

    TextBaseItem* GetTextItem(int index);
    TextBaseItem* GetButtonItem(int index);
    TextBaseItem* GetMenuItem(int index);
    IconItem* GetIconItem(int index);

    void SetTextItemText(int index, unsigned short* text);
    void SetTextItemFont(int index, ERFont* font);
    void SetTextItemFontSize(int index, f32 size);
    void SetTextItemStyle(int index, ItemStyle style);
    void SetTextItemPos(int index, EVec2& pos);
    void SetTextItemPosX(int index, f32 x);
    void SetTextItemPosY(int index, f32 y);

    void SetButtonItemText(int index, unsigned short* text);
    void SetButtonItemFont(int index, ERFont* font);
    void SetButtonItemFontSize(int index, f32 size);
    void SetButtonItemStyle(int index, ItemStyle style);
    void SetButtonItemPos(int index, EVec2& pos);
    void SetButtonItemPosX(int index, f32 x);
    void SetButtonItemPosY(int index, f32 y);

    void SetMenuItemText(int index, unsigned short* text);
    void SetMenuItemFont(int index, ERFont* font);
    void SetMenuItemFontSize(int index, f32 size);
    void SetMenutItemStyle(int index, ItemStyle style);
    void SetMenuItemPos(int index, EVec2& pos);
    void SetMenuItemPosX(int index, f32 x);
    void SetMenuItemPosY(int index, f32 y);

    void SetIconItemShader(int index, u32 shaderHash);
    void SetIconItemPos(int index, EVec2& pos);
    void SetIconItemPosX(int index, f32 x);
    void SetIconItemPosY(int index, f32 y);
    void SetIconItemSize(int index, EVec2& size);
    void SetIconItemSizeX(int index, f32 x);
    void SetIconItemSizeY(int index, f32 y);
};

// DialogPaneBase - extends WrapperPaneBase
// Additional layout (relative to start of DialogPaneBase):
//   inherits WrapperPaneBase (size depends on base)
//   0x60: TextBaseItem* m_titleTextItem
//   0x64: TextBaseItem* m_bodyTextItem
class DialogPaneBase : public WrapperPaneBase {
public:
    u8 _padDPB[0x14];              // padding to reach 0x60
    TextBaseItem* m_titleTextItem; // 0x60
    TextBaseItem* m_bodyTextItem;  // 0x64

    DialogPaneBase(int paneId, int numItems);
    ~DialogPaneBase();

    void Startup();
    void Shutdown();

    TextBaseItem* GetTitleTextItem();
    TextBaseItem* GetBodyTextItem();

    void SetTitleText(unsigned short* text);
    void SetTitleFont(ERFont* font);
    void SetTitleFontSize(f32 size);
    void SetTitlePos(EVec2 pos);
    void SetTitlePosX(f32 x);
    void SetTitlePosY(f32 y);

    void SetBodyText(unsigned short* text);
    void SetBodyFont(ERFont* font);
    void SetBodyFontSize(f32 size);
    void SetBodyPos(EVec2 pos);
    void SetBodyPosX(f32 x);
    void SetBodyPosY(f32 y);

    void SetBodyDisplaySize(EVec2& size);
    EVec2* GetBodyDisplaySize();
    f32 GetBodyDisplaySizeX();
    f32 GetBodyDisplaySizeY();

    void SetBodyDisplayPadSize(EVec2& size);
    EVec2* GetBodyDisplayPadSize();
    f32 GetBodyDisplayPadSizeX();
    f32 GetBodyDisplayPadSizeY();
};

// MenuPane
class MenuPane : public WrapperPaneBase {
public:
    int GetSelectedMenuItemValue();
};

// MenuDialogPane
class MenuDialogPane : public DialogPaneBase {
public:
    ItemStyle GetSelectedMenuItemStyle();
    int GetSelectedMenuItemValue();
};

// Wrapper
// Layout:
//   0x88: UIObjectBase* m_uiObject
//   0x8C: WrapperPaneBase** m_panesBegin
//   0x90: WrapperPaneBase** m_panesEnd
class Wrapper {
public:
    u8 _pad00[0x88];
    UIObjectBase* m_uiObject;               // 0x88
    WrapperPaneBase** m_panesBegin;         // 0x8C
    WrapperPaneBase** m_panesEnd;           // 0x90

    void WrapperStartup(UIObjectBase* uiObj);
    void WrapperShutdown();
    void WrapperRestoreMessageHandler();
    void WrapperRemoveMessageHandler();
    void WrapperReset();
    void WrapperUpdate();
    void WrapperDraw(ERC* rc);
    void WrapperCallFunction(char* funcName);
    void WrapperReadController(bool param1, int playerIndex);
    void AddPane(WrapperPaneBase* pane);
    WrapperPaneBase* FindPane(WrapperPaneBase* pane);
    void ReleasePaneBackgrounds();
    WrapperPaneBase* FindPaneById(int paneId);
};

#endif // WRAPPER_H
