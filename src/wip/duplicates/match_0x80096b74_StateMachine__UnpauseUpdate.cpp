struct StateMachine {
    char pad[0x24];
    int m_pausedUpdate;

    void UnpauseUpdate(void);
};

void StateMachine::UnpauseUpdate(void) {
    m_pausedUpdate = 0;
}
