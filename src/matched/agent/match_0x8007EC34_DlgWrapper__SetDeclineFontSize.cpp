// 0x8007EC34 DlgWrapper::SetDeclineFontSize (84B)
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
    char pad[64];
    WrapperElement* m_accept;
    WrapperElement* m_decline;
    WrapperElement* m_alt1;
    void UpdateAptButtonWidth(int type);
};

struct DlgWrapper {
    char pad[172];
    WrapperPaneBase* m_base;
    void SetDeclineFontSize(float s);
};

void DlgWrapper::SetDeclineFontSize(float s) {
    WrapperPaneBase* base = m_base;
    WrapperElement* e = base->m_decline;
    TextBlock* tb = &e->m_tb;
    tb->m_size = s;
    tb->SetDirty();
    e->m_flag |= 2;
    base->UpdateAptButtonWidth(1);
}
