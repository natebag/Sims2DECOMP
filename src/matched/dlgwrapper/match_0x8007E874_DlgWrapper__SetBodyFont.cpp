// 0x8007E874 DlgWrapper::SetBodyFont(ERFont*) (68B)
struct ERFont;
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
    char pad[100];
    WrapperElement* m_body;
};

struct DlgWrapper {
    char pad[172];
    WrapperPaneBase* m_base;
    void SetBodyFont(ERFont* f);
};

void DlgWrapper::SetBodyFont(ERFont* f) {
    WrapperElement* e = m_base->m_body;
    TextBlock* tb = &e->m_tb;
    tb->m_font = f;
    tb->SetDirty();
    e->m_flag |= 2;
}
