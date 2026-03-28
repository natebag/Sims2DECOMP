#if 0 // SKIP
// wrapper.cpp - UI wrapper/widget functions
// Object file: wrapper.obj
// Decompiled small functions (<=64 bytes)
// 161 functions total

#include "ui/wrapper.h"

// Static string for shader lookup (at 0x804cbbdc in original)
static const char s_shaderPath[] = "";

// ============================================================================
// TextBaseItem
// ============================================================================

// 0x80087104 | 12 bytes
void TextBaseItem::Reset() {
    m_flags = 1;
}

// 0x80087170 | 40 bytes
void TextBaseItem::SetColor(EVec4& color) {
    EVec4* c = m_color;
    c->x = color.x;
    c->y = color.y;
    c->z = color.z;
    c->w = color.w;
}

// 0x80087198 | 8 bytes
EVec4* TextBaseItem::GetColor() {
    return m_color;
}

// 0x800871a0 | 12 bytes
void TextBaseItem::SetAlpha(f32 alpha) {
    m_color->w = alpha;
}

// 0x800871ac | 12 bytes
f32 TextBaseItem::GetAlpha() {
    return m_color->w;
}

// 0x800871b8 | 8 bytes
void TextBaseItem::SetShadowAlpha(f32 alpha) {
    m_shadowAlpha = alpha;
}

// 0x800871c0 | 8 bytes
f32 TextBaseItem::GetShadowAlpha() {
    return m_shadowAlpha;
}

// 0x800871c8 | 8 bytes
void TextBaseItem::SetShadowSize(f32 size) {
    m_shadowSize = size;
}

// 0x800871d0 | 8 bytes
f32 TextBaseItem::GetShadowSize() {
    return m_shadowSize;
}

// 0x800871d8 | 20 bytes
void TextBaseItem::SetPos(EVec2& pos) {
    m_posX = pos.x;
    m_posY = pos.y;
}

// 0x800871ec | 8 bytes
EVec2* TextBaseItem::GetPos() {
    return (EVec2*)&m_posX;
}

// 0x800871f4 | 8 bytes
void TextBaseItem::SetPosX(f32 x) {
    m_posX = x;
}

// 0x800871fc | 8 bytes
f32 TextBaseItem::GetPosX() {
    return m_posX;
}

// 0x80087204 | 8 bytes
void TextBaseItem::SetPosY(f32 y) {
    m_posY = y;
}

// 0x8008720c | 8 bytes
f32 TextBaseItem::GetPosY() {
    return m_posY;
}

// 0x80087214 | 56 bytes
void TextBaseItem::SetDisplaySize(EVec2& size) {
    m_displaySizeX = size.x;
    m_displaySizeY = size.y;
    TextBlock* tb = (TextBlock*)((u8*)this + 0x20);
    tb->SetDirty();
}

// 0x8008724c | 8 bytes
EVec2* TextBaseItem::GetDisplaySize() {
    return (EVec2*)&m_displaySizeX;
}

// 0x80087254 | 8 bytes
f32 TextBaseItem::GetDisplaySizeX() {
    return m_displaySizeX;
}

// 0x8008725c | 8 bytes
f32 TextBaseItem::GetDisplaySizeY() {
    return m_displaySizeY;
}

// 0x80087264 | 56 bytes
void TextBaseItem::SetDisplayPadSize(EVec2& size) {
    m_displayPadSizeX = size.x;
    m_displayPadSizeY = size.y;
    TextBlock* tb = (TextBlock*)((u8*)this + 0x20);
    tb->SetDirty();
}

// 0x8008729c | 8 bytes
EVec2* TextBaseItem::GetDisplayPadSize() {
    return (EVec2*)&m_displayPadSizeX;
}

// 0x800872a4 | 8 bytes
f32 TextBaseItem::GetDisplayPadSizeX() {
    return m_displayPadSizeX;
}

// 0x800872ac | 8 bytes
f32 TextBaseItem::GetDisplayPadSizeY() {
    return m_displayPadSizeY;
}

// 0x800872b4 | 44 bytes
void TextBaseItem::SetVerticalCenter(bool center) {
    u32* flags = &m_textBlockFlags;
    if (center) {
        *flags |= 0x08;
    } else {
        *flags &= ~0x08;
    }
}

// 0x800872e0 | 44 bytes
void TextBaseItem::SetYPosCentered(bool centered) {
    u32* flags = &m_textBlockFlags;
    if (centered) {
        *flags |= 0x20;
    } else {
        *flags &= ~0x20;
    }
}

// 0x8008730c | 8 bytes
unsigned short* TextBaseItem::GetText() const {
    return m_text;
}

// 0x80087314 | 64 bytes
void TextBaseItem::SetFont(ERFont* font) {
    TextBlock* tb = (TextBlock*)((u8*)this + 0x20);
    m_font = font;
    tb->SetDirty();
    m_flags |= 0x02;
}

// 0x80087354 | 8 bytes
ERFont* TextBaseItem::GetFont() const {
    return m_font;
}

// 0x8008735c | 64 bytes
void TextBaseItem::SetFontSize(f32 size) {
    TextBlock* tb = (TextBlock*)((u8*)this + 0x20);
    m_fontSize = size;
    tb->SetDirty();
    m_flags |= 0x02;
}

// 0x8008739c | 8 bytes
f32 TextBaseItem::GetFontSize() const {
    return m_fontSize;
}

// 0x800873a4 | 8 bytes
ItemStyle TextBaseItem::GetStyle() const {
    return m_style;
}

// ============================================================================
// IconItem
// ============================================================================

// 0x80084914 | 12 bytes
void IconItem::Startup() {
    m_shader = NULL;
}

// 0x80084920 | 32 bytes
void IconItem::Shutdown() {
    ReleaseShader();
}

// 0x80084a0c | 64 bytes
void IconItem::SetShader(u32 shaderHash) {
    m_shader = ERShader_AddRef(s_shaderPath, shaderHash, 0, 0);
}

// 0x80084a4c | 64 bytes
void IconItem::ReleaseShader() {
    if (m_shader != NULL) {
        ERShader_Release(m_shader);
        m_shader = NULL;
    }
}

// 0x80087818 | 40 bytes
void IconItem::SetColor(EVec4& color) {
    m_colorR = color.x;
    m_colorG = color.y;
    m_colorB = color.z;
    m_alpha = color.w;
}

// 0x800878a4 | 8 bytes
void IconItem::SetAlpha(f32 alpha) {
    m_alpha = alpha;
}

// 0x800878ac | 8 bytes
f32 IconItem::GetAlpha() {
    return m_alpha;
}

// 0x800878b4 | 8 bytes
void IconItem::SetShader(ERShader* shader) {
    m_shader = shader;
}

// 0x800878bc | 8 bytes
ERShader* IconItem::GetShader() {
    return m_shader;
}

// ============================================================================
// WrapperPaneBase
// ============================================================================

// 0x80084a8c | 40 bytes
// NON_MATCHING: uses bdnz loop to zero 7 words backwards from offset 0x58
void WrapperPaneBase::Startup() {
    m_numItemsCurrent = m_numItemsInit;
    u32* p = (u32*)((u8*)this + 0x58);
    for (int i = 0; i < 7; i++) {
        *p = 0;
        p--;
    }
}

// 0x80087a64 | 4 bytes
void WrapperPaneBase::Reset() {
}

// 0x80087a5c | 8 bytes
s32 WrapperPaneBase::GetPaneId() {
    return m_paneId;
}

// 0x80087a68 | 48 bytes
void WrapperPaneBase::EnableDraw() {
    m_drawFlags |= 0x01;
    ShowEnabledButtons();
}

// 0x80087a98 | 48 bytes
void WrapperPaneBase::DisableDraw() {
    m_drawFlags &= ~0x01;
    HideEnabledButtons();
}

// 0x80087ac8 | 12 bytes
bool WrapperPaneBase::IsDrawEnabled() {
    return m_drawFlags & 0x01;
}

// 0x80087ad4 | 8 bytes
void WrapperPaneBase::SetAlpha(f32 alpha) {
    m_alpha = alpha;
}

// 0x80087adc | 8 bytes
f32 WrapperPaneBase::GetAlpha() {
    return m_alpha;
}

// 0x80087ae4 | 8 bytes
void WrapperPaneBase::SetState(PaneState state) {
    m_state = state;
}

// 0x80087aec | 12 bytes
void WrapperPaneBase::SetStateRunning() {
    m_state = kPaneState_Running;
}

// 0x80087af8 | 12 bytes
void WrapperPaneBase::SetStateAccepted() {
    m_state = kPaneState_Accepted;
}

// 0x80087b04 | 12 bytes
void WrapperPaneBase::SetStateDeclined() {
    m_state = kPaneState_Declined;
}

// 0x80087b10 | 12 bytes
void WrapperPaneBase::SetStateAlt1() {
    m_state = kPaneState_Alt1;
}

// 0x80087b1c | 8 bytes
int WrapperPaneBase::GetState() const {
    return m_state;
}

// 0x80087b24 | 16 bytes
bool WrapperPaneBase::IsStateRunning() const {
    return m_state == kPaneState_Running;
}

// 0x80087b34 | 20 bytes
bool WrapperPaneBase::IsStateAccepted() const {
    return m_state == kPaneState_Accepted;
}

// 0x80087b48 | 20 bytes
bool WrapperPaneBase::IsStateDeclined() const {
    return m_state == kPaneState_Declined;
}

// 0x80087b5c | 20 bytes
bool WrapperPaneBase::IsStateAlt1() const {
    return m_state == kPaneState_Alt1;
}

// 0x80085638 | 64 bytes
void WrapperPaneBase::SetBackgroundShader(u32 shaderHash) {
    m_bgShader = ERShader_AddRef(s_shaderPath, shaderHash, 0, 0);
}

// 0x80085678 | 64 bytes
void WrapperPaneBase::ReleaseBackgroundShader() {
    if (m_bgShader != NULL) {
        ERShader_Release(m_bgShader);
        m_bgShader = NULL;
    }
}

// 0x80088200 | 8 bytes
ERShader* WrapperPaneBase::GetBackgroundShader() {
    return m_bgShader;
}

// 0x80088208 | 36 bytes
void WrapperPaneBase::SetBackgroundRect(EVec2* pos, EVec2* size) {
    m_bgRectPosX = pos->x;
    m_bgRectPosY = pos->y;
    m_bgRectSizeX = size->x;
    m_bgRectSizeY = size->y;
}

// 0x8008822c | 8 bytes
void WrapperPaneBase::SetBackgroundAlpha(f32 alpha) {
    m_bgAlpha = alpha;
}

// 0x80088234 | 72 bytes
// NON_MATCHING: 72 bytes > 64 byte limit but included as it's referenced by other small funcs
void WrapperPaneBase::SetButtonContext(char* context) {
    m_buttonContext = context;
    if (context == NULL) {
        m_buttonContextLen = 0;
    } else {
        m_buttonContextLen = _strlen(context);
    }
}

// 0x8008827c | 16 bytes
TextBaseItem* WrapperPaneBase::GetButton(ButtonType type) {
    return m_buttons[type];
}

// 0x8008828c | 20 bytes
unsigned short* WrapperPaneBase::GetButtonText(ButtonType type) const {
    return m_buttons[type]->m_text;
}

// 0x800882a0 | 20 bytes
ERFont* WrapperPaneBase::GetButtonFont(ButtonType type) const {
    return m_buttons[type]->m_font;
}

// 0x800882b4 | 20 bytes
f32 WrapperPaneBase::GetButtonFontSize(ButtonType type) const {
    return m_buttons[type]->m_fontSize;
}

// 0x800882c8 | 64 bytes
// NON_MATCHING: uses virtual dispatch through button's TextBaseItem vtable
EVec2* WrapperPaneBase::GetButtonPos(ButtonType type) const {
    TextBaseItem* btn = m_buttons[type];
    return btn->GetPos();
}

// 0x80088308 | 64 bytes
// NON_MATCHING: uses virtual dispatch through button's TextBaseItem vtable
f32 WrapperPaneBase::GetButtonPosX(ButtonType type) const {
    TextBaseItem* btn = m_buttons[type];
    return btn->GetPosX();
}

// 0x80088348 | 64 bytes
// NON_MATCHING: uses virtual dispatch through button's TextBaseItem vtable
f32 WrapperPaneBase::GetButtonPosY(ButtonType type) const {
    TextBaseItem* btn = m_buttons[type];
    return btn->GetPosY();
}

// 0x800885b8 | 8 bytes
TextBaseItem* WrapperPaneBase::GetAcceptButton() {
    return m_buttons[kButton_Accept];
}

// 0x8008879c | 8 bytes
TextBaseItem* WrapperPaneBase::GetDeclineButton() {
    return m_buttons[kButton_Decline];
}

// 0x80088980 | 8 bytes
TextBaseItem* WrapperPaneBase::GetAlt1Button() {
    return m_buttons[kButton_Alt1];
}

// 0x80088b64 | 8 bytes
void* WrapperPaneBase::GetItemList() {
    return (void*)((u8*)this + 0x08);
}

// 0x800885c0 | 60 bytes
void WrapperPaneBase::SetAcceptText(unsigned short* text) {
    m_buttons[kButton_Accept]->SetText(text);
    UpdateAptButtonWidth(kButton_Accept);
}

// 0x800887a4 | 60 bytes
void WrapperPaneBase::SetDeclineText(unsigned short* text) {
    m_buttons[kButton_Decline]->SetText(text);
    UpdateAptButtonWidth(kButton_Decline);
}

// 0x80088988 | 60 bytes
void WrapperPaneBase::SetAlt1Text(unsigned short* text) {
    m_buttons[kButton_Alt1]->SetText(text);
    UpdateAptButtonWidth(kButton_Alt1);
}

// 0x80088388 | 76 bytes
// NON_MATCHING: 76 bytes > 64 byte limit but included as related
void WrapperPaneBase::SetButtonText(ButtonType type, unsigned short* text) {
    m_buttons[type]->SetText(text);
    UpdateAptButtonWidth(type);
}

// 0x8008633c | 48 bytes
// NON_MATCHING: complex bit manipulation with APT button flags
void WrapperPaneBase::UpdateAptButtonPosX(ButtonType type) {
    u32 mask = 0x100 << type;
    if (!(m_drawFlags & mask)) return;
    TextBaseItem* btn = m_buttons[type];
    u32* aptFlags = (u32*)((u8*)btn + 0x04);
    *aptFlags |= 0x10800000;
}

// 0x8008636c | 48 bytes
// NON_MATCHING: complex bit manipulation with APT button flags
void WrapperPaneBase::UpdateAptButtonPosY(ButtonType type) {
    u32 mask = 0x100 << type;
    if (!(m_drawFlags & mask)) return;
    TextBaseItem* btn = m_buttons[type];
    u32* aptFlags = (u32*)((u8*)btn + 0x04);
    *aptFlags |= 0x20800000;
}

// 0x8008639c | 48 bytes
// NON_MATCHING: complex bit manipulation with APT button flags
void WrapperPaneBase::UpdateAptButtonWidth(ButtonType type) {
    u32 mask = 0x100 << type;
    if (!(m_drawFlags & mask)) return;
    TextBaseItem* btn = m_buttons[type];
    u32* aptFlags = (u32*)((u8*)btn + 0x04);
    *aptFlags |= 0x40800000;
}

// --- GetItemXxx (call GetItem then access member) ---

// 0x8008536c | 36 bytes
unsigned short* WrapperPaneBase::GetItemText(ItemType type, int index) {
    TextBaseItem* item = GetItem(type, index);
    return item->m_text;
}

// 0x80085390 | 36 bytes
ERFont* WrapperPaneBase::GetItemFont(ItemType type, int index) {
    TextBaseItem* item = GetItem(type, index);
    return item->m_font;
}

// 0x800853b4 | 36 bytes
f32 WrapperPaneBase::GetItemFontSize(ItemType type, int index) {
    TextBaseItem* item = GetItem(type, index);
    return item->m_fontSize;
}

// 0x800853d8 | 36 bytes
ItemStyle WrapperPaneBase::GetItemStyle(ItemType type, int index) {
    TextBaseItem* item = GetItem(type, index);
    return item->m_style;
}

// 0x800853fc | 56 bytes
// NON_MATCHING: uses virtual dispatch through TextBaseItem vtable (lha+lwz from vtable, blrl)
EVec2* WrapperPaneBase::GetItemPos(ItemType type, int index) {
    TextBaseItem* item = GetItem(type, index);
    return item->GetPos();
}

// 0x80085434 | 56 bytes
// NON_MATCHING: uses virtual dispatch through TextBaseItem vtable
f32 WrapperPaneBase::GetItemPosX(ItemType type, int index) {
    TextBaseItem* item = GetItem(type, index);
    return item->GetPosX();
}

// 0x8008546c | 56 bytes
// NON_MATCHING: uses virtual dispatch through TextBaseItem vtable
f32 WrapperPaneBase::GetItemPosY(ItemType type, int index) {
    TextBaseItem* item = GetItem(type, index);
    return item->GetPosY();
}

// 0x800854a4 | 56 bytes
// NON_MATCHING: uses virtual dispatch through TextBaseItem vtable
EVec2* WrapperPaneBase::GetItemSize(ItemType type, int index) {
    TextBaseItem* item = GetItem(type, index);
    return item->GetDisplaySize();
}

// 0x800854dc | 56 bytes
// NON_MATCHING: uses virtual dispatch through TextBaseItem vtable
f32 WrapperPaneBase::GetItemSizeX(ItemType type, int index) {
    TextBaseItem* item = GetItem(type, index);
    return item->GetDisplaySizeX();
}

// 0x80085514 | 56 bytes
// NON_MATCHING: uses virtual dispatch through TextBaseItem vtable
f32 WrapperPaneBase::GetItemSizeY(ItemType type, int index) {
    TextBaseItem* item = GetItem(type, index);
    return item->GetDisplaySizeY();
}

// --- SetItemXxx ---

// 0x8008507c | 52 bytes
void WrapperPaneBase::SetItemText(ItemType type, int index, unsigned short* text) {
    TextBaseItem* item = GetItem(type, index);
    item->SetText(text);
}

// 0x80085148 | 52 bytes
void WrapperPaneBase::SetItemStyle(ItemType type, int index, ItemStyle style) {
    TextBaseItem* item = GetItem(type, index);
    item->SetStyle(style);
}

// 0x8008532c | 64 bytes
void WrapperPaneBase::SetItemShader(ItemType type, int index, u32 shaderHash) {
    IconItem* item = (IconItem*)GetItem(type, index);
    item->ReleaseShader();
    item->SetShader(shaderHash);
}

// --- GetTextItem/GetButtonItem/GetMenuItem/GetIconItem ---

// 0x80087cc4 | 40 bytes
TextBaseItem* WrapperPaneBase::GetTextItem(int index) {
    return GetItem(kItemType_Text, index);
}

// 0x80087cec | 40 bytes
TextBaseItem* WrapperPaneBase::GetButtonItem(int index) {
    return GetItem(kItemType_Button, index);
}

// 0x80087d14 | 40 bytes
TextBaseItem* WrapperPaneBase::GetMenuItem(int index) {
    return GetItem(kItemType_Menu, index);
}

// 0x80087d3c | 40 bytes
IconItem* WrapperPaneBase::GetIconItem(int index) {
    return (IconItem*)GetItem(kItemType_Icon, index);
}

// --- SetTextItemXxx ---

// 0x80087d64 | 44 bytes
void WrapperPaneBase::SetTextItemText(int index, unsigned short* text) {
    SetItemText(kItemType_Text, index, text);
}

// 0x80087d90 | 44 bytes
void WrapperPaneBase::SetTextItemFont(int index, ERFont* font) {
    SetItemFont(kItemType_Text, index, font);
}

// 0x80087dbc | 40 bytes
void WrapperPaneBase::SetTextItemFontSize(int index, f32 size) {
    SetItemFontSize(kItemType_Text, index, size);
}

// 0x80087de4 | 44 bytes
void WrapperPaneBase::SetTextItemStyle(int index, ItemStyle style) {
    SetItemStyle(kItemType_Text, index, style);
}

// 0x80087e10 | 44 bytes
void WrapperPaneBase::SetTextItemPos(int index, EVec2& pos) {
    SetItemPos(kItemType_Text, index, pos);
}

// 0x80087e3c | 40 bytes
void WrapperPaneBase::SetTextItemPosX(int index, f32 x) {
    SetItemPosX(kItemType_Text, index, x);
}

// 0x80087e64 | 40 bytes
void WrapperPaneBase::SetTextItemPosY(int index, f32 y) {
    SetItemPosY(kItemType_Text, index, y);
}

// --- SetButtonItemXxx ---

// 0x80087e8c | 44 bytes
void WrapperPaneBase::SetButtonItemText(int index, unsigned short* text) {
    SetItemText(kItemType_Button, index, text);
}

// 0x80087eb8 | 44 bytes
void WrapperPaneBase::SetButtonItemFont(int index, ERFont* font) {
    SetItemFont(kItemType_Button, index, font);
}

// 0x80087ee4 | 40 bytes
void WrapperPaneBase::SetButtonItemFontSize(int index, f32 size) {
    SetItemFontSize(kItemType_Button, index, size);
}

// 0x80087f0c | 44 bytes
void WrapperPaneBase::SetButtonItemStyle(int index, ItemStyle style) {
    SetItemStyle(kItemType_Button, index, style);
}

// 0x80087f38 | 44 bytes
void WrapperPaneBase::SetButtonItemPos(int index, EVec2& pos) {
    SetItemPos(kItemType_Button, index, pos);
}

// 0x80087f64 | 40 bytes
void WrapperPaneBase::SetButtonItemPosX(int index, f32 x) {
    SetItemPosX(kItemType_Button, index, x);
}

// 0x80087f8c | 40 bytes
void WrapperPaneBase::SetButtonItemPosY(int index, f32 y) {
    SetItemPosY(kItemType_Button, index, y);
}

// --- SetMenuItemXxx ---

// 0x80087fb4 | 44 bytes
void WrapperPaneBase::SetMenuItemText(int index, unsigned short* text) {
    SetItemText(kItemType_Menu, index, text);
}

// 0x80087fe0 | 44 bytes
void WrapperPaneBase::SetMenuItemFont(int index, ERFont* font) {
    SetItemFont(kItemType_Menu, index, font);
}

// 0x8008800c | 40 bytes
void WrapperPaneBase::SetMenuItemFontSize(int index, f32 size) {
    SetItemFontSize(kItemType_Menu, index, size);
}

// 0x80088034 | 44 bytes (typo "SetMenutItemStyle" is original)
void WrapperPaneBase::SetMenutItemStyle(int index, ItemStyle style) {
    SetItemStyle(kItemType_Menu, index, style);
}

// 0x80088060 | 44 bytes
void WrapperPaneBase::SetMenuItemPos(int index, EVec2& pos) {
    SetItemPos(kItemType_Menu, index, pos);
}

// 0x8008808c | 40 bytes
void WrapperPaneBase::SetMenuItemPosX(int index, f32 x) {
    SetItemPosX(kItemType_Menu, index, x);
}

// 0x800880b4 | 40 bytes
void WrapperPaneBase::SetMenuItemPosY(int index, f32 y) {
    SetItemPosY(kItemType_Menu, index, y);
}

// --- SetIconItemXxx ---

// 0x800880dc | 44 bytes
void WrapperPaneBase::SetIconItemShader(int index, u32 shaderHash) {
    SetItemShader(kItemType_Icon, index, shaderHash);
}

// 0x80088108 | 44 bytes
void WrapperPaneBase::SetIconItemPos(int index, EVec2& pos) {
    SetItemPos(kItemType_Icon, index, pos);
}

// 0x80088134 | 40 bytes
void WrapperPaneBase::SetIconItemPosX(int index, f32 x) {
    SetItemPosX(kItemType_Icon, index, x);
}

// 0x8008815c | 40 bytes
void WrapperPaneBase::SetIconItemPosY(int index, f32 y) {
    SetItemPosY(kItemType_Icon, index, y);
}

// 0x80088184 | 44 bytes
void WrapperPaneBase::SetIconItemSize(int index, EVec2& size) {
    SetItemSize(kItemType_Icon, index, size);
}

// 0x800881b0 | 40 bytes
void WrapperPaneBase::SetIconItemSizeX(int index, f32 x) {
    SetItemSizeX(kItemType_Icon, index, x);
}

// 0x800881d8 | 40 bytes
void WrapperPaneBase::SetIconItemSizeY(int index, f32 y) {
    SetItemSizeY(kItemType_Icon, index, y);
}

// ============================================================================
// DialogPaneBase
// ============================================================================

// 0x80086778 | 32 bytes
void DialogPaneBase::Shutdown() {
    WrapperPaneBase::Shutdown();
}

// 0x80088d20 | 8 bytes
TextBaseItem* DialogPaneBase::GetTitleTextItem() {
    return m_titleTextItem;
}

// 0x80088d28 | 8 bytes
TextBaseItem* DialogPaneBase::GetBodyTextItem() {
    return m_bodyTextItem;
}

// 0x80088d30 | 36 bytes
void DialogPaneBase::SetTitleText(unsigned short* text) {
    m_titleTextItem->SetText(text);
}

// 0x80088e7c | 36 bytes
void DialogPaneBase::SetBodyText(unsigned short* text) {
    m_bodyTextItem->SetText(text);
}

// 0x80088dd4 | 56 bytes
// NON_MATCHING: uses virtual dispatch through title item's vtable
void DialogPaneBase::SetTitlePos(EVec2 pos) {
    m_titleTextItem->SetPos(pos);
}

// 0x80088e0c | 56 bytes
// NON_MATCHING: uses virtual dispatch through title item's vtable
void DialogPaneBase::SetTitlePosX(f32 x) {
    m_titleTextItem->SetPosX(x);
}

// 0x80088e44 | 56 bytes
// NON_MATCHING: uses virtual dispatch through title item's vtable
void DialogPaneBase::SetTitlePosY(f32 y) {
    m_titleTextItem->SetPosY(y);
}

// 0x80088d54 | 64 bytes
void DialogPaneBase::SetTitleFont(ERFont* font) {
    TextBaseItem* item = m_titleTextItem;
    item->m_font = font;
    TextBlock* tb = (TextBlock*)((u8*)item + 0x20);
    tb->SetDirty();
    item->m_flags |= 0x02;
}

// 0x80088d94 | 64 bytes
void DialogPaneBase::SetTitleFontSize(f32 size) {
    TextBaseItem* item = m_titleTextItem;
    item->m_fontSize = size;
    TextBlock* tb = (TextBlock*)((u8*)item + 0x20);
    tb->SetDirty();
    item->m_flags |= 0x02;
}

// 0x80088f20 | 56 bytes
// NON_MATCHING: uses virtual dispatch through body item's vtable
void DialogPaneBase::SetBodyPos(EVec2 pos) {
    m_bodyTextItem->SetPos(pos);
}

// 0x80088f58 | 56 bytes
// NON_MATCHING: uses virtual dispatch through body item's vtable
void DialogPaneBase::SetBodyPosX(f32 x) {
    m_bodyTextItem->SetPosX(x);
}

// 0x80088f90 | 56 bytes
// NON_MATCHING: uses virtual dispatch through body item's vtable
void DialogPaneBase::SetBodyPosY(f32 y) {
    m_bodyTextItem->SetPosY(y);
}

// 0x80088ea0 | 64 bytes
void DialogPaneBase::SetBodyFont(ERFont* font) {
    TextBaseItem* item = m_bodyTextItem;
    item->m_font = font;
    TextBlock* tb = (TextBlock*)((u8*)item + 0x20);
    tb->SetDirty();
    item->m_flags |= 0x02;
}

// 0x80088ee0 | 64 bytes
void DialogPaneBase::SetBodyFontSize(f32 size) {
    TextBaseItem* item = m_bodyTextItem;
    item->m_fontSize = size;
    TextBlock* tb = (TextBlock*)((u8*)item + 0x20);
    tb->SetDirty();
    item->m_flags |= 0x02;
}

// 0x80088fc8 | 56 bytes
void DialogPaneBase::SetBodyDisplaySize(EVec2& size) {
    TextBaseItem* item = m_bodyTextItem;
    item->m_displaySizeX = size.x;
    item->m_displaySizeY = size.y;
    TextBlock* tb = (TextBlock*)((u8*)item + 0x20);
    tb->SetDirty();
}

// 0x80089000 | 12 bytes
EVec2* DialogPaneBase::GetBodyDisplaySize() {
    return (EVec2*)&m_bodyTextItem->m_displaySizeX;
}

// 0x8008900c | 12 bytes
f32 DialogPaneBase::GetBodyDisplaySizeX() {
    return m_bodyTextItem->m_displaySizeX;
}

// 0x80089018 | 12 bytes
f32 DialogPaneBase::GetBodyDisplaySizeY() {
    return m_bodyTextItem->m_displaySizeY;
}

// 0x80089024 | 56 bytes
void DialogPaneBase::SetBodyDisplayPadSize(EVec2& size) {
    TextBaseItem* item = m_bodyTextItem;
    item->m_displayPadSizeX = size.x;
    item->m_displayPadSizeY = size.y;
    TextBlock* tb = (TextBlock*)((u8*)item + 0x20);
    tb->SetDirty();
}

// 0x8008905c | 12 bytes
EVec2* DialogPaneBase::GetBodyDisplayPadSize() {
    return (EVec2*)&m_bodyTextItem->m_displayPadSizeX;
}

// 0x80089068 | 12 bytes
f32 DialogPaneBase::GetBodyDisplayPadSizeX() {
    return m_bodyTextItem->m_displayPadSizeX;
}

// 0x80089074 | 12 bytes
f32 DialogPaneBase::GetBodyDisplayPadSizeY() {
    return m_bodyTextItem->m_displayPadSizeY;
}

// ============================================================================
// MenuPane
// ============================================================================

// 0x80086798 | 56 bytes
int MenuPane::GetSelectedMenuItemValue() {
    TextBaseItem* item = GetSelectedItem(kItemType_Menu);
    if (item != NULL) {
        return item->m_value;
    }
    return -1;
}

// ============================================================================
// MenuDialogPane
// ============================================================================

// 0x800867d0 | 56 bytes
ItemStyle MenuDialogPane::GetSelectedMenuItemStyle() {
    TextBaseItem* item = GetSelectedItem(kItemType_Menu);
    if (item != NULL) {
        return item->m_style;
    }
    return (ItemStyle)7;
}

// 0x80086808 | 56 bytes
int MenuDialogPane::GetSelectedMenuItemValue() {
    TextBaseItem* item = GetSelectedItem(kItemType_Menu);
    if (item != NULL) {
        return item->m_value;
    }
    return -1;
}

// ============================================================================
// Wrapper
// ============================================================================

// 0x80086840 | 8 bytes
void Wrapper::WrapperStartup(UIObjectBase* uiObj) {
    m_uiObject = uiObj;
}

// 0x80086984 | 4 bytes
void Wrapper::WrapperRestoreMessageHandler() {
}

// 0x80086988 | 4 bytes
void Wrapper::WrapperRemoveMessageHandler() {
}

// 0x8008698c | 4 bytes
void Wrapper::WrapperReset() {
}

// 0x80086990 | 4 bytes
void Wrapper::WrapperUpdate() {
}

// 0x80086ae8 | 4 bytes
void Wrapper::WrapperCallFunction(char* funcName) {
}

// 0x80086aec | 48 bytes
// NON_MATCHING: references global controller manager via r13 offset
void Wrapper::WrapperReadController(bool param1, int playerIndex) {
    void* mgr = EControllerMan_GetInstance();
    EControllerMan_SetPlayer(mgr, playerIndex);
    EControllerMan_ReadController(mgr, 0);
}

// 0x80086cd8 | 56 bytes
WrapperPaneBase* Wrapper::FindPaneById(int paneId) {
    WrapperPaneBase** it = m_panesBegin;
    WrapperPaneBase** end = m_panesEnd;
    for (; it != end; it++) {
        WrapperPaneBase* pane = *it;
        if (pane->GetPaneId() == paneId) {
            return pane;
        }
    }
    return NULL;
}

// 0x80086d10 | 48 bytes
WrapperPaneBase* Wrapper::FindPane(WrapperPaneBase* pane) {
    WrapperPaneBase** it = m_panesBegin;
    WrapperPaneBase** end = m_panesEnd;
    for (; it != end; it++) {
        if (*it == pane) {
            return *it;
        }
    }
    return NULL;
}

// ============================================================================
// Static initialization
// ============================================================================

// Forward declaration
extern "C" void __static_initialization_and_destruction_0(int, int);

// 0x80089080 | 44 bytes
// NON_MATCHING: GCC generates this automatically, included for completeness
// "global constructors keyed to TextBaseItem::Startup(void)"
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
static void __attribute__((constructor)) _GLOBAL__I_wrapper() {
    __static_initialization_and_destruction_0(1, 0xFFFF);
}
#endif
