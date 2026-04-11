struct EResource {
    void DelRef();
};

struct EFontPage {
    char pad[0x08];
    EResource *m_shader;

    void DeallocateShader();
};

void EFontPage::DeallocateShader() {
    if (m_shader != 0) {
        m_shader->DelRef();
    }
    m_shader = 0;
}
