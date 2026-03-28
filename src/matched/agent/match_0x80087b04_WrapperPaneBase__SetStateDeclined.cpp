struct WrapperPaneBase {
    char pad[0x34];
    int m_state;

    void SetStateDeclined(void);
};

void WrapperPaneBase::SetStateDeclined(void) {
    m_state = 2;
}
