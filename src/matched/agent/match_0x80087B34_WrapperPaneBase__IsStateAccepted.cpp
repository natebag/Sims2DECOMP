// 0x80087B34 WrapperPaneBase::IsStateAccepted (20b)
struct WrapperPaneBase {
    char pad[52];
    int m_state;
    int IsStateAccepted();
};

int WrapperPaneBase::IsStateAccepted() {
    return m_state == 1;
}
