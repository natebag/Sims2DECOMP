struct WrapperPaneBase {
    char pad[0x34];
    int m_state;

    void SetStateRunning(void);
};

void WrapperPaneBase::SetStateRunning(void) {
    m_state = 0;
}
