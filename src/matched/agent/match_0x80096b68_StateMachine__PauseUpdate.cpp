struct StateMachine {
    char pad[0x24];
    int m_pausedUpdate;

    void PauseUpdate(void);
};

void StateMachine::PauseUpdate(void) {
    m_pausedUpdate = 1;
}
