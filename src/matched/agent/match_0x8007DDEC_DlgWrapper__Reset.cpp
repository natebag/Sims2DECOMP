// 0x8007DDEC DlgWrapper::Reset(void) (68B)
struct WrapperPaneBase {
    char pad[52];
    int m_f52;
};

struct DlgWrapper {
    char pad[172];
    WrapperPaneBase* m_base;
    char pad2[8];
    int m_f184;
    void DialogPaneShow();
    void Reset();
    void WrapperReset();
};

void DlgWrapper::Reset() {
    m_f184 = 0;
    m_base->m_f52 = 0;
    WrapperReset();
    DialogPaneShow();
}
