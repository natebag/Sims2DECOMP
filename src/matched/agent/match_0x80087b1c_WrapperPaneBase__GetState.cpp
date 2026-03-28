struct WrapperPaneBase {
    char pad[0x34];
    int m_state;

    int GetState(void) const;
};

int WrapperPaneBase::GetState(void) const {
    return m_state;
}
