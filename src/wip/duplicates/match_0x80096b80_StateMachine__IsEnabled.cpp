struct StateMachine {
    char pad[0x94];
    int m_enabled;

    int IsEnabled(void);
};

int StateMachine::IsEnabled(void) {
    return m_enabled;
}
