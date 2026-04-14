// 0x800850F8 WrapperPaneBase::SetItemFontSize(ItemType, int, float) (80B)
struct TextBlock {
    char pad[48];
    void* m_font;
    float m_size;
    void SetDirty();
};
struct WrapperElement {
    char pad[4];
    int m_flag;
    char pad2[24];
    TextBlock m_tb;
};
struct WrapperPaneBase {
    WrapperElement* GetItem(int type, int idx);
    void SetItemFontSize(int type, int idx, float s);
};

void WrapperPaneBase::SetItemFontSize(int type, int idx, float s) {
    WrapperElement* e = GetItem(type, idx);
    TextBlock* tb = &e->m_tb;
    tb->m_size = s;
    tb->SetDirty();
    e->m_flag |= 2;
}
