struct EResource {
    void DelRef();
};

struct WrapperPaneBase {
    char pad[0x18];
    EResource *m_backgroundShader;

    void ReleaseBackgroundShader();
};

void WrapperPaneBase::ReleaseBackgroundShader() {
    if (m_backgroundShader != 0) {
        m_backgroundShader->DelRef();
    }
    m_backgroundShader = 0;
}
