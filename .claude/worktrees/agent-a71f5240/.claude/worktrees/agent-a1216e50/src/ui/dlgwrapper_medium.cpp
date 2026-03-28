// dlgwrapper_medium.cpp - DlgWrapper medium functions (65-256 bytes)
// Object file: dlgwrapper.obj
// 29 functions

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class ERC;
class ERFont;
class EVec2;
class DialogPane;
class Wrapper;
class WrapperPaneBase;

// External functions
extern "C" {
    void TextBlock_SetDirty(void* tb);  // 0x803a05d8
    void WrapperPaneBase_SetVariable(void* wp, char* name, char* value);  // 0x80085aa0
    void DialogPane_Shutdown(void* pane);  // 0x80086848
    void Wrapper_ReleasePaneEvent(void* w);  // 0x8008698c
    void Wrapper_ShowPane(void* w, char* name);  // 0x80086ae8
    void Wrapper_ReadInput(void* w, void* rc);  // 0x80086994
    void Wrapper_UpdateItems(void* w);  // 0x80086988
    void Wrapper_Draw(void* w, int flag);  // 0x80086984
    void DialogPane_ShowPane(void* pane);  // 0x80085ebc
    void DialogPane_HidePane(void* pane);  // 0x80085ff0
    void DialogPane_ClearAllItems(void* pane);  // 0x80085678
    void WrapperPaneBase_RecalcLayout(void* wp, int mode);  // 0x8008639c
    void WrapperPaneBase_CalcAccept(void* wp, int mode);  // 0x8008633c
    void WrapperPaneBase_CalcDecline(void* wp, int mode);  // 0x8008636c
    void AptViewer_EnableInput(void* viewer, int enable);  // 0x80011e1c
    int strcmp_n(const char* a, const char* b, int n);  // 0x80243a8c
    int strcmp_impl(const char* a, const char* b);  // 0x80243838
    int atoi_impl(const char* str);  // 0x802dec2c
    void* operator_new(u32 size);  // 0x802d11b0
    void operator_delete(void* ptr);  // 0x802d1220
    void SmallBlockAllocator_Free(void* ptr);  // 0x8039be60
    void* UIEventRouter_Create();  // 0x801770c0
    void UIEventRouter_RegisterHash(void* router, u32 hash);  // 0x80177670
    void ERShader_Release(void* shader);  // 0x80311f70
}

extern void* g_aptViewerObj;  // lis r9,-32697; lwz r3,24192(r9)

// String constants
static const char s_paneSuffix[] = "Pane";        // approximate
static const char s_showStr[] = "show";            // 0x803d69c0
static const char s_hideStr[] = "hide";            // 0x803d69cc
static const char s_dialogPaneStr[] = "dialogPane"; // 0x803d69d8
static const char s_bgStr[] = "dialogBG";          // 0x803d69ec
static const char s_bgX[] = "dialogBGPosX";        // 0x803d69fc

// ============================================================================
// DlgWrapper class layout (expanded from small functions)
// ============================================================================
// 0x00-0x7F: base class data
// 0x80: vtable pointer
// 0x8C: vector (begin)
// 0x90: vector (end)
// 0x94: vector (capacity)
// 0xA0: field_A0 (saved pane state)
// 0xA4: field_A4
// 0xA8: shader pointer
// 0xAC: pane pointer (WrapperPaneBase*)
// 0xB0: field_B0
// 0xB4: field_B4 (dialog mode flag)
// 0xB8: ref count
// 0xC0: dialog pos X
// 0xC4: dialog pos Y
// 0xC8: dialog size X
// 0xCC: dialog size Y

// Helper: get this pointer adjusted for virtual call
#define VCALL_0(obj, vtable_off) do { \
    void** _vt = *(void***)((u8*)(obj) + 0x1C); \
    s16 _off = *(s16*)((u8*)_vt + (vtable_off)); \
    void* _fn = *(void**)((u8*)_vt + (vtable_off) + 4); \
    void* _this = (void*)((u8*)(obj) + _off); \
    typedef void (*_Fn)(void*); \
    ((_Fn)_fn)(_this); \
} while(0)

// ============================================================================
// Implementations
// ============================================================================

struct DlgWrapperObj {
    u8 _pad00[0x80];
    void* m_vtable;      // 0x80
    u8 _pad84[0x08];
    void* m_vec_begin;   // 0x8C
    void* m_vec_end;     // 0x90
    void* m_vec_cap;     // 0x94
    u8 _pad98[0x08];
    int m_field_A0;      // 0xA0
    u8 _padA4[0x04];
    void* m_shader;      // 0xA8
    void* m_pane;        // 0xAC
    int m_field_B0;      // 0xB0
    int m_field_B4;      // 0xB4
    int m_refCount;      // 0xB8
    u8 _padBC[0x04];
    float m_posX;        // 0xC0
    float m_posY;        // 0xC4
    float m_sizeX;       // 0xC8
    float m_sizeY;       // 0xCC
};

// 0x8007dd98 | 84 bytes
void DlgWrapper_Shutdown(DlgWrapperObj* self) {
    // DialogPaneHide
    void DlgWrapper_DialogPaneHide(DlgWrapperObj*);
    DlgWrapper_DialogPaneHide(self);
    // Shutdown pane
    DialogPane_Shutdown(self);
    // Release shader
    void* shader = self->m_shader;
    if (shader != 0) {
        ERShader_Release(shader);
        self->m_shader = 0;
    }
    self->m_field_B0 = 0;
}

// 0x8007ddec | 68 bytes
void DlgWrapper_Reset(DlgWrapperObj* self) {
    self->m_refCount = 0;
    void* pane = self->m_pane;
    *(int*)((u8*)pane + 0x34) = 0;
    Wrapper_ReleasePaneEvent(self);
    void DlgWrapper_DialogPaneShow(DlgWrapperObj*);
    DlgWrapper_DialogPaneShow(self);
}

// 0x8007e084 | 120 bytes
void DlgWrapper_DialogPaneShow(DlgWrapperObj* self) {
    int refCount = self->m_refCount;
    self->m_refCount = refCount + 1;
    Wrapper_Draw(self, 0);  // dummy arg
    Wrapper_ShowPane(self, (char*)s_showStr);
    self->m_field_B4 = 0;
    void* pane = self->m_pane;
    DialogPane_ShowPane(pane);
    // Set visible flag
    void* pane2 = self->m_pane;
    int flags = *(int*)((u8*)pane2 + 4);
    flags |= 1;
    *(int*)((u8*)pane2 + 4) = flags;
    DialogPane_ShowPane(pane2);
    // Clear selection
    void* pane3 = self->m_pane;
    *(int*)((u8*)pane3 + 0x34) = 0;
}

// 0x8007e0fc | 136 bytes
void DlgWrapper_DialogPaneHide(DlgWrapperObj* self) {
    int refCount = self->m_refCount;
    self->m_refCount = refCount - 1;
    Wrapper_ShowPane(self, (char*)s_hideStr);
    // Disable APT input
    AptViewer_EnableInput(g_aptViewerObj, 1);
    self->m_field_B4 = 0;
    void* pane = self->m_pane;
    DialogPane_HidePane(pane);
    // Clear visible flag
    void* pane2 = self->m_pane;
    int flags = *(int*)((u8*)pane2 + 4);
    flags &= ~1;
    *(int*)((u8*)pane2 + 4) = flags;
    DialogPane_HidePane(pane2);
    // Clear all items
    void* pane3 = self->m_pane;
    DialogPane_ClearAllItems(pane3);
    Wrapper_UpdateItems(self);
}

// 0x8007e184 | 240 bytes
// NON_MATCHING - string comparison and variable routing logic
void DlgWrapper_SetVariable(DlgWrapperObj* self, char* name, char* value) {
    void* pane = self->m_pane;
    WrapperPaneBase_SetVariable(pane, name, value);
    // Check return in r3 (simplified)
    int result = 0; // NON_MATCHING - need to capture return
    if (result != 0) {
        return;
    }
    void* innerPane = self->m_pane;
    // Check if name starts with "dialogBG"
    if (strcmp_n(name, (char*)s_dialogPaneStr, 16) == 0) {
        // Parse 'x' suffix
        u8 ch = *(u8*)(name + 17);
        int isX = (ch ^ 'x') ? 0 : 1;
        int val = atoi_impl(value);
        if (innerPane == 0) return;
        if (isX) {
            // SetPosX through vtable
            void* item = *(void**)((u8*)innerPane + 0x60);
            void** vt = *(void***)((u8*)item + 0x1C);
            s16 off = *(s16*)((u8*)vt + 0x48);
            void* fn = *(void**)((u8*)vt + 0x4C);
            typedef void (*Fn)(void*);
            ((Fn)fn)((void*)((u8*)item + off));
        } else {
            // SetPosY through vtable
            void* item = *(void**)((u8*)innerPane + 0x60);
            void** vt = *(void***)((u8*)item + 0x1C);
            s16 off = *(s16*)((u8*)vt + 0x58);
            void* fn = *(void**)((u8*)vt + 0x5C);
            typedef void (*Fn)(void*);
            ((Fn)fn)((void*)((u8*)item + off));
        }
    } else if (strcmp_impl(name, (char*)s_bgStr) == 0) {
        // Check value against "true"
        int boolVal = strcmp_impl(value, "true") == 0 ? 1 : 0;
        self->m_field_B4 = boolVal;
    }
}

// 0x8007dfe8 | 156 bytes
// NON_MATCHING - complex Update/Draw with branching
void DlgWrapper_Draw(DlgWrapperObj* self, ERC* rc) {
    int isShown = self->m_field_B4;
    if (isShown == 0) {
        // Not shown path
        int savedState = self->m_field_A0;
        self->m_field_A0 = 0;
        Wrapper_ShowPane(self, (char*)s_showStr);
        Wrapper_ReadInput(self, rc);
        Wrapper_ShowPane(self, (char*)s_hideStr);
        self->m_field_A0 = savedState;
    } else {
        Wrapper_ShowPane(self, (char*)s_showStr);
        Wrapper_ReadInput(self, rc);
        Wrapper_ShowPane(self, (char*)s_hideStr);
    }
}

// 0x8007e544 | 156 bytes
void DlgWrapper_dtor(DlgWrapperObj* self, int flags) {
    // Set derived vtable
    *(void**)((u8*)self + 0x80) = (void*)0x8045CF18;
    DlgWrapper_Shutdown(self);
    // Set intermediate vtable
    *(void**)((u8*)self + 0x80) = (void*)0x8045CF98;
    DialogPane_Shutdown(self);
    // Free vector buffer
    void* begin = *(void**)((u8*)self + 0x8C);
    if (begin != 0) {
        void* end = *(void**)((u8*)self + 0x8C + 0x0C);
        int size = (int)((u8*)end - (u8*)begin);
        size &= ~3;
        if (size > 128) {
            operator_delete(begin);
        } else {
            SmallBlockAllocator_Free(begin);
        }
    }
    // Set base vtable
    *(void**)((u8*)self + 0x80) = (void*)0x8045CFD8;
    if (flags & 1) {
        operator_delete(self);
    }
}

// 0x8007e68c | 76 bytes
void DlgWrapper_SetDialogSize(DlgWrapperObj* self, void* sizeVec) {
    float x = *(float*)sizeVec;
    float y = *(float*)((u8*)sizeVec + 4);
    self->m_sizeX = x;
    self->m_sizeY = y;
    // Update pane's body item
    void* pane = self->m_pane;
    void* bodyItem = *(void**)((u8*)pane + 0x64);
    *(float*)((u8*)bodyItem + 0x2C) = y;
    *(float*)((u8*)bodyItem + 0x28) = x;
    // SetDirty on text block
    TextBlock_SetDirty((u8*)bodyItem + 0x20);
}

// 0x8007e808 | 68 bytes
void DlgWrapper_SetTitleFontSize(DlgWrapperObj* self, float size) {
    void* pane = self->m_pane;
    void* titleItem = *(void**)((u8*)pane + 0x60);
    void* tb = (u8*)titleItem + 0x20;
    *(float*)((u8*)tb + 0x34) = size;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)titleItem + 4);
    *(int*)((u8*)titleItem + 4) = flags | 2;
}

// 0x8007e874 | 68 bytes
void DlgWrapper_SetBodyFont(DlgWrapperObj* self, ERFont* font) {
    void* pane = self->m_pane;
    void* bodyItem = *(void**)((u8*)pane + 0x64);
    void* tb = (u8*)bodyItem + 0x20;
    *(void**)((u8*)tb + 0x30) = font;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)bodyItem + 4);
    *(int*)((u8*)bodyItem + 4) = flags | 2;
}

// 0x8007e8b8 | 68 bytes
void DlgWrapper_SetBodyFontSize(DlgWrapperObj* self, float size) {
    void* pane = self->m_pane;
    void* bodyItem = *(void**)((u8*)pane + 0x64);
    void* tb = (u8*)bodyItem + 0x20;
    *(float*)((u8*)tb + 0x34) = size;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)bodyItem + 4);
    *(int*)((u8*)bodyItem + 4) = flags | 2;
}

// 0x8007e8fc | 88 bytes
void DlgWrapper_SetBodyPos(DlgWrapperObj* self, void* posVec) {
    float x = *(float*)posVec;
    float y = *(float*)((u8*)posVec + 4);
    // Copy to stack
    void* pane = self->m_pane;
    void* bodyItem = *(void**)((u8*)pane + 0x64);
    // Virtual call SetPos
    void** vt = *(void***)((u8*)bodyItem + 0x1C);
    s16 off = *(s16*)((u8*)vt + 0x38);
    void* fn = *(void**)((u8*)vt + 0x3C);
    typedef void (*SetPosFn)(void*, void*);
    ((SetPosFn)fn)((void*)((u8*)bodyItem + off), posVec);
}

// 0x8007ea08 | 80 bytes
void DlgWrapper_SetAcceptFont(DlgWrapperObj* self, ERFont* font) {
    void* pane = self->m_pane;
    void* acceptItem = *(void**)((u8*)pane + 0x40);
    void* tb = (u8*)acceptItem + 0x20;
    *(void**)((u8*)tb + 0x30) = font;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)acceptItem + 4);
    *(int*)((u8*)acceptItem + 4) = flags | 2;
    WrapperPaneBase_RecalcLayout(pane, 0);
}

// 0x8007ea58 | 84 bytes
void DlgWrapper_SetAcceptFontSize(DlgWrapperObj* self, float size) {
    void* pane = self->m_pane;
    void* acceptItem = *(void**)((u8*)pane + 0x40);
    void* tb = (u8*)acceptItem + 0x20;
    *(float*)((u8*)tb + 0x34) = size;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)acceptItem + 4);
    *(int*)((u8*)acceptItem + 4) = flags | 2;
    WrapperPaneBase_RecalcLayout(pane, 0);
}

// 0x8007eaac | 92 bytes
void DlgWrapper_SetAcceptPos(DlgWrapperObj* self, void* posVec) {
    void* pane = self->m_pane;
    void* acceptItem = *(void**)((u8*)pane + 0x40);
    // Virtual call SetPos
    void** vt = *(void***)((u8*)acceptItem + 0x1C);
    s16 off = *(s16*)((u8*)vt + 0x38);
    void* fn = *(void**)((u8*)vt + 0x3C);
    typedef void (*SetPosFn)(void*, void*);
    ((SetPosFn)fn)((void*)((u8*)acceptItem + off), posVec);
    WrapperPaneBase_CalcAccept(pane, 0);
    WrapperPaneBase_CalcDecline(pane, 0);
}

// 0x8007eb08 | 80 bytes
void DlgWrapper_SetAcceptPosX(DlgWrapperObj* self, float x) {
    void* pane = self->m_pane;
    void* acceptItem = *(void**)((u8*)pane + 0x40);
    // Virtual call SetPosX
    void** vt = *(void***)((u8*)acceptItem + 0x1C);
    s16 off = *(s16*)((u8*)vt + 0x48);
    void* fn = *(void**)((u8*)vt + 0x4C);
    typedef void (*SetPosXFn)(void*);
    ((SetPosXFn)fn)((void*)((u8*)acceptItem + off));
    WrapperPaneBase_CalcAccept(pane, 0);
}

// 0x8007eb58 | 80 bytes
void DlgWrapper_SetAcceptPosY(DlgWrapperObj* self, float y) {
    void* pane = self->m_pane;
    void* acceptItem = *(void**)((u8*)pane + 0x40);
    // Virtual call SetPosY
    void** vt = *(void***)((u8*)acceptItem + 0x1C);
    s16 off = *(s16*)((u8*)vt + 0x58);
    void* fn = *(void**)((u8*)vt + 0x5C);
    typedef void (*SetPosYFn)(void*);
    ((SetPosYFn)fn)((void*)((u8*)acceptItem + off));
    WrapperPaneBase_CalcDecline(pane, 0);
}

// 0x8007ebe4 | 80 bytes
void DlgWrapper_SetDeclineFont(DlgWrapperObj* self, ERFont* font) {
    void* pane = self->m_pane;
    void* declineItem = *(void**)((u8*)pane + 0x44);
    void* tb = (u8*)declineItem + 0x20;
    *(void**)((u8*)tb + 0x30) = font;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)declineItem + 4);
    *(int*)((u8*)declineItem + 4) = flags | 2;
    WrapperPaneBase_RecalcLayout(pane, 0);
}

// 0x8007ec34 | 84 bytes
void DlgWrapper_SetDeclineFontSize(DlgWrapperObj* self, float size) {
    void* pane = self->m_pane;
    void* declineItem = *(void**)((u8*)pane + 0x44);
    void* tb = (u8*)declineItem + 0x20;
    *(float*)((u8*)tb + 0x34) = size;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)declineItem + 4);
    *(int*)((u8*)declineItem + 4) = flags | 2;
    WrapperPaneBase_RecalcLayout(pane, 0);
}

// 0x8007ec88 | 92 bytes
void DlgWrapper_SetDeclinePos(DlgWrapperObj* self, void* posVec) {
    void* pane = self->m_pane;
    void* declineItem = *(void**)((u8*)pane + 0x44);
    void** vt = *(void***)((u8*)declineItem + 0x1C);
    s16 off = *(s16*)((u8*)vt + 0x38);
    void* fn = *(void**)((u8*)vt + 0x3C);
    typedef void (*SetPosFn)(void*, void*);
    ((SetPosFn)fn)((void*)((u8*)declineItem + off), posVec);
    WrapperPaneBase_CalcAccept(pane, 0);
    WrapperPaneBase_CalcDecline(pane, 0);
}

// 0x8007ece4 | 80 bytes
void DlgWrapper_SetDeclinePosX(DlgWrapperObj* self, float x) {
    void* pane = self->m_pane;
    void* declineItem = *(void**)((u8*)pane + 0x44);
    void** vt = *(void***)((u8*)declineItem + 0x1C);
    s16 off = *(s16*)((u8*)vt + 0x48);
    void* fn = *(void**)((u8*)vt + 0x4C);
    typedef void (*SetPosXFn)(void*);
    ((SetPosXFn)fn)((void*)((u8*)declineItem + off));
    WrapperPaneBase_CalcAccept(pane, 0);
}

// 0x8007ed34 | 80 bytes
void DlgWrapper_SetDeclinePosY(DlgWrapperObj* self, float y) {
    void* pane = self->m_pane;
    void* declineItem = *(void**)((u8*)pane + 0x44);
    void** vt = *(void***)((u8*)declineItem + 0x1C);
    s16 off = *(s16*)((u8*)vt + 0x58);
    void* fn = *(void**)((u8*)vt + 0x5C);
    typedef void (*SetPosYFn)(void*);
    ((SetPosYFn)fn)((void*)((u8*)declineItem + off));
    WrapperPaneBase_CalcDecline(pane, 0);
}

// 0x8007edc0 | 80 bytes
void DlgWrapper_SetAlt1Font(DlgWrapperObj* self, ERFont* font) {
    void* pane = self->m_pane;
    void* alt1Item = *(void**)((u8*)pane + 0x48);
    void* tb = (u8*)alt1Item + 0x20;
    *(void**)((u8*)tb + 0x30) = font;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)alt1Item + 4);
    *(int*)((u8*)alt1Item + 4) = flags | 2;
    WrapperPaneBase_RecalcLayout(pane, 0);
}

// 0x8007ee10 | 84 bytes
void DlgWrapper_SetAlt1FontSize(DlgWrapperObj* self, float size) {
    void* pane = self->m_pane;
    void* alt1Item = *(void**)((u8*)pane + 0x48);
    void* tb = (u8*)alt1Item + 0x20;
    *(float*)((u8*)tb + 0x34) = size;
    TextBlock_SetDirty(tb);
    int flags = *(int*)((u8*)alt1Item + 4);
    *(int*)((u8*)alt1Item + 4) = flags | 2;
    WrapperPaneBase_RecalcLayout(pane, 0);
}

// 0x8007ee64 | 92 bytes
void DlgWrapper_SetAlt1Pos(DlgWrapperObj* self, void* posVec) {
    void* pane = self->m_pane;
    void* alt1Item = *(void**)((u8*)pane + 0x48);
    void** vt = *(void***)((u8*)alt1Item + 0x1C);
    s16 off = *(s16*)((u8*)vt + 0x38);
    void* fn = *(void**)((u8*)vt + 0x3C);
    typedef void (*SetPosFn)(void*, void*);
    ((SetPosFn)fn)((void*)((u8*)alt1Item + off), posVec);
    WrapperPaneBase_CalcAccept(pane, 0);
    WrapperPaneBase_CalcDecline(pane, 0);
}

// 0x8007eec0 | 80 bytes
void DlgWrapper_SetAlt1PosX(DlgWrapperObj* self, float x) {
    void* pane = self->m_pane;
    void* alt1Item = *(void**)((u8*)pane + 0x48);
    void** vt = *(void***)((u8*)alt1Item + 0x1C);
    s16 off = *(s16*)((u8*)vt + 0x48);
    void* fn = *(void**)((u8*)vt + 0x4C);
    typedef void (*SetPosXFn)(void*);
    ((SetPosXFn)fn)((void*)((u8*)alt1Item + off));
    WrapperPaneBase_CalcAccept(pane, 0);
}

// 0x8007ef10 | 80 bytes
void DlgWrapper_SetAlt1PosY(DlgWrapperObj* self, float y) {
    void* pane = self->m_pane;
    void* alt1Item = *(void**)((u8*)pane + 0x48);
    void** vt = *(void***)((u8*)alt1Item + 0x1C);
    s16 off = *(s16*)((u8*)vt + 0x58);
    void* fn = *(void**)((u8*)vt + 0x5C);
    typedef void (*SetPosYFn)(void*);
    ((SetPosYFn)fn)((void*)((u8*)alt1Item + off));
    WrapperPaneBase_CalcDecline(pane, 0);
}

// 0x803a05f0 | 124 bytes
// NON_MATCHING - DialogPane destructor
void DialogPane_dtor(void* self, int flags) {
    // Set derived vtable
    *(void**)((u8*)self + 0x80) = (void*)0x8045D628;
    // Shutdown
    DialogPane_Shutdown(self);
    // Free vector
    void* begin = *(void**)((u8*)self + 0x8C);
    if (begin != 0) {
        void* end = *(void**)((u8*)self + 0x8C + 0x0C);
        int size = (int)((u8*)end - (u8*)begin);
        size &= ~3;
        if (size > 128) {
            operator_delete(begin);
        } else {
            SmallBlockAllocator_Free(begin);
        }
    }
    *(void**)((u8*)self + 0x80) = (void*)0x8045D588;
    if (flags & 1) {
        operator_delete(self);
    }
}

// 0x803a06b4 | 136 bytes
// NON_MATCHING - Wrapper destructor
void Wrapper_dtor(void* self, int flags) {
    *(void**)((u8*)self + 0x80) = (void*)0x8045D4D0;
    // Shutdown pane backgrounds
    void Wrapper_ReleasePaneBackgrounds(void*);
    Wrapper_ReleasePaneBackgrounds(self);
    DialogPane_Shutdown(self);
    void* begin = *(void**)((u8*)self + 0x8C);
    if (begin != 0) {
        void* end = *(void**)((u8*)self + 0x8C + 0x0C);
        int size = (int)((u8*)end - (u8*)begin);
        size &= ~3;
        if (size > 128) {
            operator_delete(begin);
        } else {
            SmallBlockAllocator_Free(begin);
        }
    }
    *(void**)((u8*)self + 0x80) = (void*)0x8045D588;
    if (flags & 1) {
        operator_delete(self);
    }
}
