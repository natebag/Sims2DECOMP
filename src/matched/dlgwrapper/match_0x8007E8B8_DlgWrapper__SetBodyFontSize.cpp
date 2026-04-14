// 0x8007E8B8 DlgWrapper::SetBodyFontSize(float) (68B)
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
    void SetBodyFontSize(float s);
};

void DlgWrapper::SetBodyFontSize(float s) {
    WrapperElement* e = m_base->m_body;
    TextBlock* tb = &e->m_tb;
    tb->m_size = s;
    tb->SetDirty();
    e->m_flag |= 2;
}
