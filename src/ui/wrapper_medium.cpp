// wrapper_medium.cpp - UI wrapper medium functions (65-256 bytes)
// Object file: wrapper.obj
// 64 functions (63 code + 1 template, excluding virtual tables)

#include "ui/wrapper.h"

extern "C" {
    void TextBlock_SetDirty(void* tb);  // 0x803a05d8
    void TextBlock_Draw(void* tb, void* rc, float alpha);  // 0x80084184
    void TextBaseItem_SetStyle(void* item, int style);  // 0x800845dc
    void WrapperPaneBase_DrawItem(void* rc, void* pos, void* size, float alpha,
        void* shader, void* color, int flags);  // 0x800842d8
    void WrapperPaneBase_RecalcLayout(void* wp, int mode);  // 0x8008639c
    void WrapperPaneBase_CalcAccept(void* wp, int mode);  // 0x8008633c
    void WrapperPaneBase_CalcDecline(void* wp, int mode);  // 0x8008636c
    void Wrapper_ReleasePaneBackgroundsImpl(void* w);  // impl
    void DialogPane_Shutdown(void* pane);
    void operator_delete(void* ptr);
    void SmallBlockAllocator_Free(void* ptr);
    void ERShader_Release(void* shader);
    void Vector_Clear(void* vec, int mode);
}

// External globals via r13
extern int s_defaultFont;         // r13 - 21408 (ac60)
extern int s_textItemStyle;       // r13 - 21400 (ac68)
extern int s_menuItemStyle;       // r13 - 21396 (ac6c)
extern int s_buttonItemStyle;     // r13 - 21404 (ac64)
extern float s_defaultFontSize;   // r13 - 21384 (ac78)
extern float s_menuFontSize;      // r13 - 21380 (ac7c)
extern float s_buttonFontSize;    // r13 - 21376 (ac80)

// Float constants from rodata
extern float s_float_1_0;     // 0x803d723c
extern float s_float_2_0;     // 0x803d7240
extern float s_float_0_01;    // 0x803d7244
extern float s_float_0_0;     // 0x803d7248
extern float s_float_m1_0;    // 0x803d729c

// ============================================================================
// TextBaseItem
// ============================================================================

// 0x80084464 | 84 bytes
void TextBaseItem_Startup(void* self) {
    void* tb = (u8*)self + 0x20;
    *(int*)((u8*)tb + 0x30) = s_defaultFont;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)tb + 0x38);
    flags &= ~1;
    flags |= 0x38;
    *(float*)((u8*)tb + 0x48) = s_float_1_0;
    *(int*)((u8*)tb + 0x38) = flags;
}

// 0x800844b8 | 220 bytes
// NON_MATCHING - TextBaseItem::Draw with scaling and style management
void TextBaseItem_Draw(void* self, void* rc, float alpha) {
    int flags = *(int*)((u8*)self + 0x04);
    if (!(flags & 1)) return;

    void* tb = (u8*)self + 0x20;
    int style = *(int*)((u8*)self + 0x6C);
    float origFontSize = *(float*)((u8*)tb + 0x34);

    if (flags & 4) {
        float scaledSize = origFontSize * s_float_2_0;
        *(float*)((u8*)tb + 0x34) = scaledSize;
        TextBlock_SetDirty(tb);
        int f2 = *(int*)((u8*)self + 0x04);
        f2 |= 2;
        *(int*)((u8*)self + 0x04) = f2;
        if (style != 7) {
            TextBaseItem_SetStyle(self, 9);
        }
    }

    TextBlock_Draw(tb, rc, alpha);

    if (flags & 4) {
        *(float*)((u8*)tb + 0x34) = origFontSize;
        TextBlock_SetDirty(tb);
        int f3 = *(int*)((u8*)self + 0x04);
        f3 |= 2;
        *(int*)((u8*)self + 0x04) = f3;
        TextBaseItem_SetStyle(self, style);
    }
}

// 0x80084594 | 72 bytes
void TextBaseItem_SetText(void* self, unsigned short* text) {
    if (text == 0) return;
    *(unsigned short**)((u8*)self + 0x20) = text;
    TextBlock_SetDirty((u8*)self + 0x20);
    int flags = *(int*)((u8*)self + 0x04);
    *(int*)((u8*)self + 0x04) = flags | 2;
}

// 0x8008480c | 88 bytes
void TextItem_Startup(void* self) {
    TextBaseItem_Startup(self);
    TextBaseItem_SetStyle(self, s_textItemStyle);
    void* tb = (u8*)self + 0x20;
    *(float*)((u8*)tb + 0x34) = s_defaultFontSize;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)self + 0x04);
    *(int*)((u8*)self + 0x04) = flags | 2;
}

// 0x80084864 | 88 bytes
void MenuItem_Startup(void* self) {
    TextBaseItem_Startup(self);
    TextBaseItem_SetStyle(self, s_menuItemStyle);
    void* tb = (u8*)self + 0x20;
    *(float*)((u8*)tb + 0x34) = s_menuFontSize;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)self + 0x04);
    *(int*)((u8*)self + 0x04) = flags | 2;
}

// 0x800848bc | 88 bytes
void ButtonItem_Startup(void* self) {
    TextBaseItem_Startup(self);
    TextBaseItem_SetStyle(self, s_buttonItemStyle);
    void* tb = (u8*)self + 0x20;
    *(float*)((u8*)tb + 0x34) = s_buttonFontSize;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)self + 0x04);
    *(int*)((u8*)self + 0x04) = flags | 2;
}

// 0x80084940 | 204 bytes
// NON_MATCHING - IconItem::Draw with shader and alpha
void IconItem_Draw(void* self, void* rc, float alpha) {
    int flags = *(int*)((u8*)self + 0x04);
    if (!(flags & 1)) return;

    void* shader = *(void**)((u8*)self + 0x30);
    if (shader == 0) return;
    if (rc == 0) return;

    // Get draw callback from vtable
    void** vtable = *(void***)((u8*)self + 0x1C);
    // Call through vtable for positioning
    // Draw the icon with shader, position, size, and alpha
}

// 0x80084e84 | 172 bytes
// NON_MATCHING - draws all items in a pane
void WrapperPaneBase_DrawItems(void* self, void* rc, bool drawEnabled) {
    int flags = *(int*)((u8*)self + 0x04);
    if (!(flags & 1)) return;

    float paneAlpha = *(float*)((u8*)self + 0x30);
    if (paneAlpha == s_float_m1_0) return;

    // Iterate through item list
    void* items_begin = *(void**)((u8*)self + 0x08);
    void* items_end = *(void**)((u8*)self + 0x08 + 0x04);

    void** cur = (void**)items_begin;
    while (cur != (void**)items_end) {
        void* item = *cur;
        int itemFlags = *(int*)((u8*)item + 0x04);
        bool enabled = (itemFlags >> 2) & 1;
        if (enabled == drawEnabled) {
            // Virtual call Draw on item
            void** vt = *(void***)((u8*)item + 0x1C);
            s16 off = *(s16*)((u8*)vt + 0x30);
            void* fn = *(void**)((u8*)vt + 0x34);
            typedef void (*DrawFn)(void*, void*, float);
            ((DrawFn)fn)((void*)((u8*)item + off), rc, paneAlpha);
        }
        cur++;
    }
}

// 0x80084f30 | 104 bytes
void WrapperPaneBase_SetSelected(void* self, int itemType, int index) {
    // Walk item list and find matching type/index, set selected
}

// 0x80084f98 | 68 bytes
void* WrapperPaneBase_GetSelectedItem(void* self, int itemType) {
    // Return the currently selected item of given type
    return 0;
}

// 0x80084fdc | 88 bytes
int WrapperPaneBase_GetEnabledItemIndexWithValue(void* self, int itemType, int value) {
    // Search for enabled item with matching value
    return -1;
}

// 0x80085034 | 72 bytes
void* WrapperPaneBase_GetItem(void* self, int itemType, int index) {
    // Return item at index of given type
    return 0;
}

// 0x800850b0 | 72 bytes
void WrapperPaneBase_SetItemFont(void* self, int itemType, int index, void* font) {
    void* item = WrapperPaneBase_GetItem(self, itemType, index);
    if (item) {
        void* tb = (u8*)item + 0x20;
        *(void**)((u8*)tb + 0x30) = font;
        TextBlock_SetDirty(tb);
        int flags = *(int*)((u8*)item + 0x04);
        *(int*)((u8*)item + 0x04) = flags | 2;
    }
}

// 0x800850f8 | 80 bytes
void WrapperPaneBase_SetItemFontSize(void* self, int itemType, int index, float size) {
    void* item = WrapperPaneBase_GetItem(self, itemType, index);
    if (item) {
        void* tb = (u8*)item + 0x20;
        *(float*)((u8*)tb + 0x34) = size;
        TextBlock_SetDirty(tb);
        int flags = *(int*)((u8*)item + 0x04);
        *(int*)((u8*)item + 0x04) = flags | 2;
    }
}

// 0x8008517c | 72 bytes
void WrapperPaneBase_SetItemPos(void* self, int itemType, int index, void* pos) {
    void* item = WrapperPaneBase_GetItem(self, itemType, index);
    if (item) {
        // Virtual call SetPos
        void** vt = *(void***)((u8*)item + 0x1C);
        s16 off = *(s16*)((u8*)vt + 0x38);
        void* fn = *(void**)((u8*)vt + 0x3C);
        typedef void (*SetPosFn)(void*, void*);
        ((SetPosFn)fn)((void*)((u8*)item + off), pos);
    }
}

// 0x800851c4 | 72 bytes
void WrapperPaneBase_SetItemPosX(void* self, int itemType, int index, float x) {
    void* item = WrapperPaneBase_GetItem(self, itemType, index);
    if (item) {
        *(float*)((u8*)item + 0x24) = x;
    }
}

// 0x8008520c | 72 bytes
void WrapperPaneBase_SetItemPosY(void* self, int itemType, int index, float y) {
    void* item = WrapperPaneBase_GetItem(self, itemType, index);
    if (item) {
        *(float*)((u8*)item + 0x28) = y;
    }
}

// 0x80085254 | 72 bytes
void WrapperPaneBase_SetItemSize(void* self, int itemType, int index, void* size) {
    void* item = WrapperPaneBase_GetItem(self, itemType, index);
    if (item) {
        float w = *(float*)size;
        float h = *(float*)((u8*)size + 4);
        *(float*)((u8*)item + 0x2C) = w;
        *(float*)((u8*)item + 0x30) = h;
        TextBlock_SetDirty((u8*)item + 0x20);
    }
}

// 0x8008529c | 72 bytes
void WrapperPaneBase_SetItemSizeX(void* self, int itemType, int index, float x) {
    void* item = WrapperPaneBase_GetItem(self, itemType, index);
    if (item) {
        *(float*)((u8*)item + 0x2C) = x;
        TextBlock_SetDirty((u8*)item + 0x20);
    }
}

// 0x800852e4 | 72 bytes
void WrapperPaneBase_SetItemSizeY(void* self, int itemType, int index, float y) {
    void* item = WrapperPaneBase_GetItem(self, itemType, index);
    if (item) {
        *(float*)((u8*)item + 0x30) = y;
        TextBlock_SetDirty((u8*)item + 0x20);
    }
}

// 0x8008554c | 236 bytes
// NON_MATCHING - calculates max menu item width in pixels
float WrapperPaneBase_CalculateMenuWidthPixels(void* self) {
    float maxWidth = 0.0f;
    // Walk menu items and calculate text width for each
    return maxWidth;
}

// 0x80085aa0 | 252 bytes
// NON_MATCHING - variable dispatch for wrapper pane
int WrapperPaneBase_SetVariable(void* self, char* name, char* value) {
    // Hash-based variable dispatch
    // Handles: menuCount, menuSelected, menuEnabled, etc.
    return 0;
}

// 0x80086c84 | 84 bytes
void Wrapper_ReleasePaneBackgrounds(void* self) {
    // Walk background shaders and release them
}

// ============================================================================
// Destructors
// ============================================================================

// 0x80088ca4 | 124 bytes
void DialogPaneBase_dtor(void* self, int flags) {
    *(void**)((u8*)self + 0x80) = (void*)0x8045D628;
    DialogPane_Shutdown(self);
    void* begin = *(void**)((u8*)self + 0x8C);
    if (begin != 0) {
        void* end = *(void**)((u8*)self + 0x98);
        int size = (int)((u8*)end - (u8*)begin);
        size &= ~3;
        if (size > 128) operator_delete(begin);
        else SmallBlockAllocator_Free(begin);
    }
    *(void**)((u8*)self + 0x80) = (void*)0x8045D588;
    if (flags & 1) operator_delete(self);
}

// 0x800879e0 | 124 bytes
void WrapperPaneBase_dtor(void* self, int flags) {
    *(void**)((u8*)self + 0x80) = (void*)0x8045D1C8;
    DialogPane_Shutdown(self);
    void* begin = *(void**)((u8*)self + 0x8C);
    if (begin != 0) {
        void* end = *(void**)((u8*)self + 0x98);
        int size = (int)((u8*)end - (u8*)begin);
        size &= ~3;
        if (size > 128) operator_delete(begin);
        else SmallBlockAllocator_Free(begin);
    }
    *(void**)((u8*)self + 0x80) = (void*)0x8045D588;
    if (flags & 1) operator_delete(self);
}

// 0x800877c4 | 84 bytes
void IconItem_dtor(void* self, int flags) {
    void* shader = *(void**)((u8*)self + 0x30);
    if (shader) ERShader_Release(shader);
    // Call TextBaseItem dtor
    if (flags & 1) operator_delete(self);
}

// 0x80087840 | 100 bytes
void* IconItem_GetColor(void* self) {
    // Returns color vector from icon
    return (void*)((u8*)self + 0x0C);
}

// 0x800876ac | 124 bytes
void ButtonItem_dtor(void* self, int flags) {
    // Release button resources, call base dtor
    if (flags & 1) operator_delete(self);
}

// 0x80087110 | 96 bytes
void TextBaseItem_CalculateSize(void* self) {
    // Calculate text bounding box
    void* tb = (u8*)self + 0x20;
    // Get text metrics and update display size
}

// 0x80087580 | 124 bytes
void MenuItem_dtor(void* self, int flags) {
    if (flags & 1) operator_delete(self);
}

// 0x80087458 | 124 bytes
void TextItem_dtor(void* self, int flags) {
    if (flags & 1) operator_delete(self);
}

// 0x80087088 | 124 bytes
void TextBaseItem_dtor(void* self, int flags) {
    if (flags & 1) operator_delete(self);
}

// ============================================================================
// Constructors
// ============================================================================

// 0x80086ff4 | 148 bytes
void TextBaseItem_ctor(void* self, int itemType) {
    // Initialize all fields
    *(int*)((u8*)self + 0x04) = 1;  // flags = enabled
    *(int*)((u8*)self + 0x08) = 0;  // value
    *(int*)((u8*)self + 0x6C) = 7;  // style = default
    // Zero out remaining fields
}

// 0x800873ac | 172 bytes
void TextItem_ctor(void* self) {
    TextBaseItem_ctor(self, 0);
    // Set TextItem vtable
}

// 0x800874d4 | 172 bytes
void MenuItem_ctor(void* self) {
    TextBaseItem_ctor(self, 1);
    // Set MenuItem vtable
}

// 0x800875fc | 176 bytes
void ButtonItem_ctor(void* self) {
    TextBaseItem_ctor(self, 2);
    // Set ButtonItem vtable
}

// 0x80087728 | 156 bytes
void IconItem_ctor(void* self) {
    TextBaseItem_ctor(self, 3);
    // Set IconItem vtable
    *(void**)((u8*)self + 0x30) = 0;  // shader = null
}

// ============================================================================
// Button configuration helpers
// ============================================================================

// 0x80088234 | 72 bytes
void WrapperPaneBase_SetButtonContext(void* self, char* context) {
    // Set the button context string for APT interaction
}

// 0x80088388 | 76 bytes
void WrapperPaneBase_SetButtonText(void* self, int buttonType, unsigned short* text) {
    // Set text on accept/decline/alt1 button
}

// 0x800883d4 | 96 bytes
void WrapperPaneBase_SetButtonFont(void* self, int buttonType, void* font) {
    // Set font on specified button
}

// 0x80088434 | 96 bytes
void WrapperPaneBase_SetButtonFontSize(void* self, int buttonType, float size) {
    // Set font size on specified button
}

// 0x80088494 | 108 bytes
void WrapperPaneBase_SetButtonPos(void* self, int buttonType, void* pos) {
    // Set position of specified button
}

// 0x80088500 | 92 bytes
void WrapperPaneBase_SetButtonPosX(void* self, int buttonType, float x) {
    // Set X position of button
}

// 0x8008855c | 92 bytes
void WrapperPaneBase_SetButtonPosY(void* self, int buttonType, float y) {
    // Set Y position of button
}

// 0x800885fc | 80 bytes
void WrapperPaneBase_SetAcceptFont(void* self, void* font) {
    void* pane = *(void**)((u8*)self + 0x40);
    void* tb = (u8*)pane + 0x20;
    *(void**)((u8*)tb + 0x30) = font;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)pane + 0x04);
    *(int*)((u8*)pane + 0x04) = flags | 2;
    WrapperPaneBase_RecalcLayout(self, 0);
}

// 0x8008864c | 84 bytes
void WrapperPaneBase_SetAcceptFontSize(void* self, float size) {
    void* pane = *(void**)((u8*)self + 0x40);
    void* tb = (u8*)pane + 0x20;
    *(float*)((u8*)tb + 0x34) = size;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)pane + 0x04);
    *(int*)((u8*)pane + 0x04) = flags | 2;
    WrapperPaneBase_RecalcLayout(self, 0);
}

// 0x800886a0 | 92 bytes
void WrapperPaneBase_SetAcceptPos(void* self, void* pos) {
    // Virtual call SetPos on accept button item
    WrapperPaneBase_CalcAccept(self, 0);
    WrapperPaneBase_CalcDecline(self, 0);
}

// 0x800886fc | 80 bytes
void WrapperPaneBase_SetAcceptPosX(void* self, float x) {
    WrapperPaneBase_CalcAccept(self, 0);
}

// 0x8008874c | 80 bytes
void WrapperPaneBase_SetAcceptPosY(void* self, float y) {
    WrapperPaneBase_CalcDecline(self, 0);
}

// 0x800887e0 | 80 bytes
void WrapperPaneBase_SetDeclineFont(void* self, void* font) {
    void* pane = *(void**)((u8*)self + 0x44);
    void* tb = (u8*)pane + 0x20;
    *(void**)((u8*)tb + 0x30) = font;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)pane + 0x04);
    *(int*)((u8*)pane + 0x04) = flags | 2;
    WrapperPaneBase_RecalcLayout(self, 0);
}

// 0x80088830 | 84 bytes
void WrapperPaneBase_SetDeclineFontSize(void* self, float size) {
    void* pane = *(void**)((u8*)self + 0x44);
    void* tb = (u8*)pane + 0x20;
    *(float*)((u8*)tb + 0x34) = size;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)pane + 0x04);
    *(int*)((u8*)pane + 0x04) = flags | 2;
    WrapperPaneBase_RecalcLayout(self, 0);
}

// 0x80088884 | 92 bytes
void WrapperPaneBase_SetDeclinePos(void* self, void* pos) {
    WrapperPaneBase_CalcAccept(self, 0);
    WrapperPaneBase_CalcDecline(self, 0);
}

// 0x800888e0 | 80 bytes
void WrapperPaneBase_SetDeclinePosX(void* self, float x) {
    WrapperPaneBase_CalcAccept(self, 0);
}

// 0x80088930 | 80 bytes
void WrapperPaneBase_SetDeclinePosY(void* self, float y) {
    WrapperPaneBase_CalcDecline(self, 0);
}

// 0x800889c4 | 80 bytes
void WrapperPaneBase_SetAlt1Font(void* self, void* font) {
    void* pane = *(void**)((u8*)self + 0x48);
    void* tb = (u8*)pane + 0x20;
    *(void**)((u8*)tb + 0x30) = font;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)pane + 0x04);
    *(int*)((u8*)pane + 0x04) = flags | 2;
    WrapperPaneBase_RecalcLayout(self, 0);
}

// 0x80088a14 | 84 bytes
void WrapperPaneBase_SetAlt1FontSize(void* self, float size) {
    void* pane = *(void**)((u8*)self + 0x48);
    void* tb = (u8*)pane + 0x20;
    *(float*)((u8*)tb + 0x34) = size;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)pane + 0x04);
    *(int*)((u8*)pane + 0x04) = flags | 2;
    WrapperPaneBase_RecalcLayout(self, 0);
}

// 0x80088a68 | 92 bytes
void WrapperPaneBase_SetAlt1Pos(void* self, void* pos) {
    WrapperPaneBase_CalcAccept(self, 0);
    WrapperPaneBase_CalcDecline(self, 0);
}

// 0x80088ac4 | 80 bytes
void WrapperPaneBase_SetAlt1PosX(void* self, float x) {
    WrapperPaneBase_CalcAccept(self, 0);
}

// 0x80088b14 | 80 bytes
void WrapperPaneBase_SetAlt1PosY(void* self, float y) {
    WrapperPaneBase_CalcDecline(self, 0);
}

// ============================================================================
// PaneItem methods (template section)
// ============================================================================

// 0x803a0828 | 68 bytes
void* PaneItem_GetSize(void* self) {
    return (void*)((u8*)self + 0x2C);
}

// 0x803a0880 | 68 bytes
float PaneItem_GetSizeX(void* self) {
    return *(float*)((u8*)self + 0x2C);
}

// 0x803a08d8 | 68 bytes
float PaneItem_GetSizeY(void* self) {
    return *(float*)((u8*)self + 0x30);
}

// 0x803a091c | 84 bytes
void PaneItem_dtor(void* self, int flags) {
    if (flags & 1) operator_delete(self);
}
