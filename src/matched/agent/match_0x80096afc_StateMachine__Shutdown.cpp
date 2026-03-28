struct StateMachineStatusStack {
    void clear(void);
};

struct StateMachine {
    char pad[0x3C];
    StateMachineStatusStack m_statusStack;

    void Shutdown(void);
};

void StateMachine::Shutdown(void) {
    m_statusStack.clear();
}
