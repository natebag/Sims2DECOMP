struct StateMachine {
    char pad[0x24];
    int m_pausedUpdate;

    int IsPausedUpdate(void);
};

int StateMachine::IsPausedUpdate(void) {
    return m_pausedUpdate;
}
