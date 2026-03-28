struct StateMachineState {
    int m_stateId;
};

struct StateMachine {
    char pad[0x44];
    StateMachineState *m_lastState;

    int GetLastStateId(void) const;
};

int StateMachine::GetLastStateId(void) const {
    return m_lastState->m_stateId;
}
