struct StateMachineState {
    int m_stateId;
};

struct StateMachine {
    char pad[0x48];
    StateMachineState *m_callingState;

    int GetCallingStateId(void) const;
};

int StateMachine::GetCallingStateId(void) const {
    return m_callingState->m_stateId;
}
