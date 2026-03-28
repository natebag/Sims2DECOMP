struct WrapperPaneBase {
    char pad[0x34];
    int m_state;

    void SetState(int state);
};

void WrapperPaneBase::SetState(int state) {
    m_state = state;
}
