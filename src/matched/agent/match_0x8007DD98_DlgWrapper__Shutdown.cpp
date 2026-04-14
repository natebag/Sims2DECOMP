// 0x8007DD98 DlgWrapper::Shutdown(void) (84B)
struct EResource {
    void DelRef();
};

struct DlgWrapper {
    char pad[168];
    EResource* m_f168;
    char pad2[4];
    int m_f176;
    void Shutdown();
    void DialogPaneHide();
    void WrapperShutdown();
};

void DlgWrapper::Shutdown() {
    DialogPaneHide();
    WrapperShutdown();
    if (m_f168 != 0) {
        m_f168->DelRef();
        m_f168 = 0;
    }
    m_f176 = 0;
}
