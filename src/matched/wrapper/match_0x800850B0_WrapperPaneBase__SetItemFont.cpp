// 0x800850B0 WrapperPaneBase::SetItemFont(ItemType, int, ERFont*) (72B)
struct ERFont;
struct TextBlock {
    char pad[48];
    ERFont* m_font;
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
    void SetItemFont(int type, int idx, ERFont* font);
};

void WrapperPaneBase::SetItemFont(int type, int idx, ERFont* font) {
    WrapperElement* e = GetItem(type, idx);
    TextBlock* tb = &e->m_tb;
    tb->m_font = font;
    tb->SetDirty();
    e->m_flag |= 2;
}
