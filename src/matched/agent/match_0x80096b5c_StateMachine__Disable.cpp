struct StateMachine {
    char pad[0x94];
    int m_enabled;

    void Disable(void);
};

void StateMachine::Disable(void) {
    m_enabled = 0;
}
