// 0x80087B24 WrapperPaneBase::IsStateRunning (16b)
struct WrapperPaneBase {
    char pad[52];
    int m_state;
    int IsStateRunning();
};

int WrapperPaneBase::IsStateRunning() {
    return m_state == 0;
}
