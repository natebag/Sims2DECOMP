struct WrapperPaneBase {
    char pad[0x34];
    int m_state;

    void SetStateAlt1(void);
};

void WrapperPaneBase::SetStateAlt1(void) {
    m_state = 3;
}
