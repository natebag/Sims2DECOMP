struct StateMachineState {
    char pad[0x0C];
    int m_stage;
};

struct StateMachine {
    char pad[0x3C];
    StateMachineState *m_curState;

    int GetCurStateStage(void) const;
};

int StateMachine::GetCurStateStage(void) const {
    return m_curState->m_stage;
}
