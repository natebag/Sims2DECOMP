// 0x803A1928 (96B) InLevelStoryState::~InLevelStoryState(void)
// Variant L (MI sibling of InLevelBaseState): vtable-transition at +0x18 + UIDialog member dtor at +0x2c.

extern char vt_InLevelStoryState_a[];
extern char vt_InLevelStoryState_b[];

void UIDialog_dtor(void* obj, int flag);
void __builtin_delete(void* p);

struct UIDialog {
    char data[1];
};

struct InLevelStoryState {
    char pad_00_17[24];
    void* m_vt_at_18;
    char pad_1c_2b[16];
    UIDialog m_dialog;
    void dtor(int flag);
};

void InLevelStoryState::dtor(int flag) {
    m_vt_at_18 = vt_InLevelStoryState_a;
    UIDialog_dtor(&m_dialog, 2);
    m_vt_at_18 = vt_InLevelStoryState_b;
    if (flag & 1) {
        __builtin_delete(this);
    }
}
