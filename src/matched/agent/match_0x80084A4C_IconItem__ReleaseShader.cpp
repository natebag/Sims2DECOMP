struct EResource {
    void DelRef();
};

struct IconItem {
    char pad[0x30];
    EResource *m_shader;

    void ReleaseShader();
};

void IconItem::ReleaseShader() {
    if (m_shader != 0) {
        m_shader->DelRef();
    }
    m_shader = 0;
}
