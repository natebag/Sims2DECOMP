// 0x8007E808 DlgWrapper::SetTitleFontSize(float) (68B)
// DlgWrapper font family — TextBlock pointer local forces correct scheduling
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
    char pad[96];
    WrapperElement* m_title;
};

struct DlgWrapper {
    char pad[172];
    WrapperPaneBase* m_base;
    void SetTitleFontSize(float s);
};

void DlgWrapper::SetTitleFontSize(float s) {
    WrapperElement* e = m_base->m_title;
    TextBlock* tb = &e->m_tb;
    tb->m_size = s;
    tb->SetDirty();
    e->m_flag |= 2;
}
