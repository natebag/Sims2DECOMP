struct StateMachineState {
    int m_stateId;
};

struct StateMachine {
    char pad[0x3C];
    StateMachineState *m_curState;

    int GetCurStateId(void) const;
};

int StateMachine::GetCurStateId(void) const {
    if (m_curState != 0) {
        return m_curState->m_stateId;
    }
    return -1;
}
