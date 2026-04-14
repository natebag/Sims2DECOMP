// 0x80085678 WrapperPaneBase::ReleaseBackgroundShader(void) (64B)
struct EResource {
    void DelRef();
};

struct WrapperPaneBase {
    char pad[24];
    EResource* m_bgShader;
    void ReleaseBackgroundShader();
};

void WrapperPaneBase::ReleaseBackgroundShader() {
    if (m_bgShader != 0) {
        m_bgShader->DelRef();
        m_bgShader = 0;
    }
}
