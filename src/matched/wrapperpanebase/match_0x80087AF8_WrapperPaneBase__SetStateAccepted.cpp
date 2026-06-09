struct WrapperPaneBase {
    char pad[0x34];
    int m_state;

    void SetStateAccepted(void);
};

void WrapperPaneBase::SetStateAccepted(void) {
    m_state = 1;
}
