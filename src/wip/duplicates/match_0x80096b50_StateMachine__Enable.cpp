struct StateMachine {
    char pad[0x94];
    int m_enabled;

    void Enable(void);
};

void StateMachine::Enable(void) {
    m_enabled = 1;
}
